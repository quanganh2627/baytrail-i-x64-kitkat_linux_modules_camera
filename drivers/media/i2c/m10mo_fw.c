/*
 *
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include <linux/atomisp_platform.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/spi/spi.h>
#include <media/v4l2-device.h>
#include <linux/sizes.h>
#include "m10mo.h"


/*
 * Currently the FW image and dump paths are hardcoded here.
 * TBD: flexible interface for defining proper path as needed
 */
#define M10MO_FW_DUMP_PATH "/data/M10MO_dump.bin"
#define M10MO_FW_PATH "/data/M10MO_fw.bin"

#define SRAM_BUFFER_ADDRESS 0x01100000
#define SDRAM_BUFFER_ADDRESS 0x20000000

#define M10MO_FLASH_READ_BASE_ADDR	0x18000000
#define PLL_SETTINGS_24MHZ 0x00170141
#define PLL_SETTINGS_19_2MHZ 0x001d0152

#define PORT_SETTINGS0_ADDR  0x90001200
#define PORT_SETTINGS1_ADDR  0x90001000
#define PORT_SETTINGS2_ADDR  0x90001100

#define PORT_SETTING_DELAY   (10*1000)
#define I2C_DELAY	     (10*1000)

#define I2C_DUMP_SIZE	     0x20 /* keep as power of 2 values */
#define FW_SIZE		     0x00200000
#define FLASH_BLOCK_SIZE     0x10000
#define SIO_BLOCK_SIZE	     8192
#define DUMP_BLOCK_SIZE      0x1000

#define FW_VERSION_INFO_ADDR 0x181EF080
#define FW_VERSION_SIZE	     11

#define ONE_WRITE_SIZE	     64
/*
 * TBD: proper matching between I2C and SPI devices instead of this global
 * variable.
 */
static struct m10mo_spi *fw_spi_device;

/* Tables for m10mo pin configurations */
u8 buf_port_settings0_m10mo[] = {
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
		  0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x05,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
		 };

u8 buf_port_settings1_m10mo[] = {
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 };

u8 buf_port_settings2_m10mo[] = {
		  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x14,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 };

static int m10mo_set_flash_address(struct v4l2_subdev *sd, u32 addr)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;
	ret = m10mo_writel(sd, CATEGORY_FLASHROM, REG_FLASH_ADD, addr);
	if (ret)
		dev_err(&client->dev, "Set flash address failed\n");
	return ret;
}

static u32 m10mo_get_pll_cfg(u32 freq)
{
	u32 ret;
	switch(freq) {
	case 24000000:
		ret = PLL_SETTINGS_24MHZ;
		break;
	case 19200000:
		ret = PLL_SETTINGS_19_2MHZ;
		break;
	default:
		/* Defaults to development board xtal freq */
		ret = PLL_SETTINGS_24MHZ;
		break;
	}
	return ret;
}

static int m10mo_wait_operation_complete(struct v4l2_subdev *sd, u8 reg,
					 u32 timeout)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int res;
	do {
		msleep(10);
		m10mo_readb(sd, CATEGORY_FLASHROM, reg, &res);
		timeout--;
	} while ((res != 0) && timeout);

	if (!timeout) {
		dev_err(&client->dev,
			"timeout while waiting for chip op to finish");
		return -ETIME;
	}
	return 0;
}

static int m10mo_to_fw_access_mode(struct m10mo_device *m10mo_dev)
{
	struct v4l2_subdev *sd = &m10mo_dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int err;

	err = m10mo_memory_write(sd, M10MO_MEMORY_WRITE_8BIT, SZ_64,
				PORT_SETTINGS0_ADDR , buf_port_settings0_m10mo);
	if (err)
		goto fail;

	usleep_range(PORT_SETTING_DELAY, PORT_SETTING_DELAY);

	err = m10mo_memory_write(sd, M10MO_MEMORY_WRITE_8BIT, SZ_64,
				PORT_SETTINGS1_ADDR, buf_port_settings1_m10mo);
	if (err)
		goto fail;

	usleep_range(PORT_SETTING_DELAY, PORT_SETTING_DELAY);

	err = m10mo_memory_write(sd, M10MO_MEMORY_WRITE_8BIT, SZ_64,
				PORT_SETTINGS2_ADDR, buf_port_settings2_m10mo);
	if (err)
		goto fail;
	usleep_range(PORT_SETTING_DELAY, PORT_SETTING_DELAY);

	err = m10mo_writel(sd, CATEGORY_FLASHROM,
			   REG_PLL_VALUES,
			   m10mo_get_pll_cfg(24000000));
	if (err)
		goto fail;
	return 0;
fail:
	dev_err(&client->dev, "transition to fw mode failed\n");
	return err;
}


static int m10mo_memory_dump(struct m10mo_device *m10mo_dev, u16 len,
			     u32 addr, u8 *val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&m10mo_dev->sd);
	struct i2c_msg msg;
	unsigned char data[8];
	u16 len_received;
	int i, err = 0;

	if (!client->adapter)
		return -ENODEV;

	if (len >= (sizeof(m10mo_dev->message_buffer) - 3))
		return -EINVAL;

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = sizeof(data);
	msg.buf = data;

	/* high byte goes out first */
	data[0] = 0x00;
	data[1] = M10MO_MEMORY_READ_8BIT;
	data[2] = (addr >> 24) & 0xFF;
	data[3] = (addr >> 16) & 0xFF;
	data[4] = (addr >> 8) & 0xFF;
	data[5] = addr & 0xFF;
	data[6] = (len >> 8) & 0xFF;
	data[7] = len & 0xFF;

	for (i = M10MO_I2C_RETRY; i; i--) {
		err = i2c_transfer(client->adapter, &msg, 1);
		if (err == 1)
			break;
		usleep_range(I2C_DELAY, I2C_DELAY);
	}

	if (err != 1)
		return err;

	msg.flags = I2C_M_RD;
	msg.len = len + 3;
	msg.buf = m10mo_dev->message_buffer;
	for (i = M10MO_I2C_RETRY; i; i--) {
		err = i2c_transfer(client->adapter, &msg, 1);
		if (err == 1)
			break;
		usleep_range(I2C_DELAY, I2C_DELAY);
	}

	if (err != 1)
		return err;

	len_received = m10mo_dev->message_buffer[1] << 8 |
		m10mo_dev->message_buffer[2];
	if (len != len_received)
		dev_err(&client->dev,
			"expected length %d, but return length %d\n",
			len, len_received);

	memcpy(val, m10mo_dev->message_buffer + 3, len);
	return err;
}

int m10mo_dump_fw(struct m10mo_device *m10mo_dev)
{
	struct v4l2_subdev *sd = &m10mo_dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct file *fp;
	mm_segment_t old_fs;
	u8 *buf;
	u32 addr, unit, count;
	int i;
	int err;

	dev_dbg(&client->dev, "Begin FW dump to file %s\n", M10MO_FW_DUMP_PATH);

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	fp = filp_open(M10MO_FW_DUMP_PATH,
		O_WRONLY|O_CREAT|O_TRUNC, S_IRUGO|S_IWUGO|S_IXUSR);
	if (IS_ERR(fp)) {
		dev_err(&client->dev,
			"failed to open %s, err %ld\n",
			M10MO_FW_DUMP_PATH, PTR_ERR(fp));
		err = -ENOENT;
		goto out_file;
	}

	err = m10mo_to_fw_access_mode(m10mo_dev);
	if (err)
		goto out_close;

	buf = kmalloc(DUMP_BLOCK_SIZE, GFP_KERNEL);
	if (!buf) {
		dev_err(&client->dev, "Failed to allocate memory\n");
		err = -ENOMEM;
		goto out_close;
	}

	err = m10mo_writeb(sd, CATEGORY_FLASHROM,
			   REG_FW_READ, REG_FW_READ_CMD_READ);

	if (err) {
		dev_err(&client->dev, "FW read cmd fails %d\n", err);
		goto out_mem_free;
	}

	addr = M10MO_FLASH_READ_BASE_ADDR;
	unit = I2C_DUMP_SIZE;
	count = FW_SIZE / I2C_DUMP_SIZE;
	for (i = 0; i < count; i++) {
		err = m10mo_memory_dump(m10mo_dev,
					unit,
					addr + (i * unit),
					buf);
		if (err < 0) {
			dev_err(&client->dev, "Memory dump failed %d\n", err);
			goto out_mem_free;
		}
		vfs_write(fp, buf, unit, &fp->f_pos);
	}
	dev_dbg(&client->dev, "End of FW dump to file\n");

out_mem_free:
	if (buf)
		kfree(buf);
out_close:
	if (!IS_ERR(fp))
		filp_close(fp, current->files);
out_file:
	set_fs(old_fs);

	return err;
}

int m10mo_get_isp_fw_version(struct m10mo_device *dev)
{
	int err;
	struct v4l2_subdev *sd = &dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u8 isp_ver[FW_VERSION_SIZE + 1] = {0, };

	err = m10mo_to_fw_access_mode(dev);
	if (err)
		return err;

	err = m10mo_writeb(sd, CATEGORY_FLASHROM,
				REG_FW_READ, REG_FW_READ_CMD_READ);
	if (err) {
		dev_err(&client->dev, "Read mode transition fail: %d\n", err);
		return err;
	}
	msleep(10);

	err = m10mo_memory_read(sd, FW_VERSION_SIZE, FW_VERSION_INFO_ADDR,
				isp_ver);
	if (err) {
		dev_err(&client->dev, "version read failed\n");
		goto out;
	}
	dev_err(&client->dev, "version string %s\n", isp_ver);

out:
	err = m10mo_writeb(sd, CATEGORY_FLASHROM,
			   REG_FW_READ, REG_FW_READ_CMD_NONE);
	return err;
}

int m10mo_fw_checksum(struct m10mo_device *dev, u16 *result)
{
	int err;
	struct v4l2_subdev *sd = &dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	int res = 0;

	err = m10mo_to_fw_access_mode(dev);
	if (err)
		goto leave;

	/* Set start address to 0*/
	err = m10mo_set_flash_address(sd, 0x0);
	if (err)
		goto leave;

	/* request checksum */
	err = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_FLASH_CHECK, 4);
	if (err) {
		dev_err(&client->dev, "Request checksum failed\n");
		goto leave;
	}

	err = m10mo_wait_operation_complete(sd, REG_FLASH_CHECK, 1000);
	if (err)
		goto leave;

	m10mo_readw(sd, CATEGORY_FLASHROM, REG_FLASH_SUM , &res);
	if (err) {
		dev_err(&client->dev, "Checksum read failed\n");
		goto leave;
	}
	*result = (u16)res;
leave:
	return err;
}

int m10mo_sector_erase_flash(struct m10mo_device *dev, u32 sector_addr)
{
	int ret;
	struct v4l2_subdev *sd = &dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	/*
	 * Preconditions - system is already in flash access mode,
	 * plls configured
	 */

	/* Set start address */
	ret = m10mo_set_flash_address(sd, sector_addr);
	if (ret)
		return ret;

	ret = m10mo_writeb(sd, CATEGORY_FLASHROM,
			   REG_FLASH_ERASE,
			   REG_FLASH_ERASE_SECTOR_ERASE);
	if (ret) {
		dev_err(&client->dev, "Checksum cmd fails\n");
		return ret;
	}

	m10mo_wait_operation_complete(sd, REG_FLASH_ERASE, 1000);
	return ret;
}


/* Full chip erase */
int m10mo_chip_erase_flash(struct m10mo_device *dev)
{
	struct v4l2_subdev *sd = &dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;
	/*
	 * Preconditions - system is already in flash access mode,
	 * plls configured
	 */

	/* Setup internal RAM */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_RAM_START,
			   REG_RAM_START_SRAM);
	if (ret) {
		dev_err(&client->dev, "Ram setup failed\n");
		return ret;
	}

	/* Set start address to 0*/
	ret = m10mo_set_flash_address(sd, 0x0);
	if (ret)
		return ret;

	/* chip erase command */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_FLASH_ERASE,
			   REG_FLASH_ERASE_CHIP_ERASE);
	if (ret) {
		dev_err(&client->dev, "Chip erase cmd failed\n");
		return ret;
	}
	ret = m10mo_wait_operation_complete(sd, REG_FLASH_ERASE, 1000);
	return ret;
}

int m10mo_flash_write_block(struct m10mo_device *dev, u32 target_addr,
			    u8 *block, u32 block_size)
{
	struct v4l2_subdev *sd = &dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	int ret;
	u32 ram_buffer = SRAM_BUFFER_ADDRESS;
	int i;

	ret = m10mo_set_flash_address(sd, target_addr);
	if (ret)
		return ret;

	/* Set block size of 64k == 0 as reg value */
	ret = m10mo_writew(sd, CATEGORY_FLASHROM, REG_FLASH_BYTE, 0);
	if (ret) {
		dev_err(&client->dev, "Set flash block size fails\n");
		return ret;
	}

	for (i = 0; i < block_size / ONE_WRITE_SIZE; i++) {
		ret = m10mo_memory_write(sd, M10MO_MEMORY_WRITE_8BIT,
					 ONE_WRITE_SIZE,
					 ram_buffer, block);
		if (ret) {
			/* Retry once */
			dev_err(&client->dev,
				"FW write block fails - retry %d\n", i);
			ret = m10mo_memory_write(sd, M10MO_MEMORY_WRITE_8BIT,
						 ONE_WRITE_SIZE,
						 ram_buffer, block);
		}
		if (ret)
			break;

		ram_buffer += ONE_WRITE_SIZE;
		block += ONE_WRITE_SIZE;
	}
	if (ret) {
		dev_err(&client->dev, "FW write block fails %d\n", i);
		return ret;
	}

	/* Program block */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_FLASH_WRITE,
			   REG_FLASH_WRITE_START_PRG);
	if (ret) {
		dev_err(&client->dev, "FW program block fails %d\n", i);
		return ret;
	}

	m10mo_wait_operation_complete(sd, REG_FLASH_WRITE, 1000);

	return 0;
}


static int m10mo_sio_write(struct m10mo_device *m10mo_dev, u8 *buf)
{
	int ret;
	struct v4l2_subdev *sd = &m10mo_dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	if (!fw_spi_device) {
		dev_err(&client->dev, "No spi device available");
		return -ENODEV;
	}

	/* Set SIO destination address */
	ret = m10mo_writel(sd, CATEGORY_FLASHROM, REG_DATA_RAM_ADDR,
			   SDRAM_BUFFER_ADDRESS);
	if (ret) {
		dev_err(&client->dev, "sio address setting fails\n");
		return ret;
	}

	/* Set programming size - multiples of 16 bytes */
	ret = m10mo_writel(sd, CATEGORY_FLASHROM, REG_DATA_TRANS_SIZE,
			   FW_SIZE / 16);
	if (ret) {
		dev_err(&client->dev, "set program size failed\n");
		return ret;
	}

	/* Set SDRAM - mystical value from flow picture */
	ret = m10mo_writew(sd, CATEGORY_FLASHROM, REG_SDRAM_CFG, 0x0608);
	if (ret) {
		dev_err(&client->dev, "set sdram failed\n");
		return ret;
	}

	/* Set sio mode: */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_SIO_MODE,
			   REG_SIO_MODE_RISING_LATCH);
	if (ret) {
		dev_err(&client->dev, "set sio mode failed\n");
		return ret;
	}

	/* Start sio mode */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_RAM_START,
			   REG_RAM_START_SDRAM);
	if (ret) {
		dev_err(&client->dev, "start sio mode failed \n");
		return ret;
	}

	m10mo_wait_operation_complete(sd, REG_RAM_START, 1000);
	usleep_range(30000, 30000);  /* TDB: is that required */

	fw_spi_device->write(fw_spi_device->spi_device,
			     buf, FW_SIZE, SIO_BLOCK_SIZE);

	msleep(5); /* TDB: is that required */

	/* Flash address to 0*/
	ret = m10mo_set_flash_address(sd, 0);
	if (ret)
		return ret;

	/* Programming size */
	ret = m10mo_writel(sd, CATEGORY_FLASHROM, REG_DATA_TRANS_SIZE, FW_SIZE);
	if (ret) {
		dev_err(&client->dev, "set sio programming size failed \n");
		return ret;
	}

	/* Start programming */
	ret = m10mo_writeb(sd, CATEGORY_FLASHROM, REG_FLASH_WRITE,
			   REG_FLASH_WRITE_START_PRG);
	if (ret) {
		dev_err(&client->dev, "SIO start programming failed\n");
		return ret;
	}
	ret = m10mo_wait_operation_complete(sd, REG_FLASH_WRITE, 1000);
	return ret;
}

int m10mo_program_device(struct m10mo_device *m10mo_dev)
{
	struct v4l2_subdev *sd = &m10mo_dev->sd;
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	struct file *fp;
	mm_segment_t old_fs;
	long fsize, nread;
	u8 *buf = NULL;
	int ret = -ENODEV;
	u32 i;

	dev_dbg(&client->dev, "Start FW update\n");

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	fp = filp_open(M10MO_FW_PATH, O_RDONLY, 0);
	if (IS_ERR(fp)) {
		dev_err(&client->dev, "failed to open %s, err %ld\n",
		       M10MO_FW_PATH, PTR_ERR(fp));
		ret = -ENOENT;
		goto out;
	}

	fsize = fp->f_path.dentry->d_inode->i_size;
	if (fsize > FW_SIZE) {
		dev_err(&client->dev, "FW file size too big\n");
		goto out;
	}

	/* Looks that we have the fw image: 2Mbytes of flash memory */
	buf = kzalloc(FW_SIZE, GFP_KERNEL);
	if (!buf) {
		dev_err(&client->dev, "No memory for fw update\n");
		ret = -ENOMEM;
		goto out;
	}

	nread = vfs_read(fp, (char __user *)buf, fsize, &fp->f_pos);
	if (nread != fsize) {
		dev_err(&client->dev,
			"failed to read firmware file, %ld Bytes\n", nread);
		ret = -EIO;
		goto out_free_mem;
	}

	ret = m10mo_to_fw_access_mode(m10mo_dev);
	if (ret)
		goto out_free_mem;

	ret = m10mo_chip_erase_flash(m10mo_dev);
	if (ret) {
		dev_err(&client->dev, "Erase failed\n");
		goto out_free_mem;
	}

	if (fw_spi_device && fw_spi_device->spi_enabled) {
		m10mo_sio_write(m10mo_dev, buf);
	} else {
		for (i = 0 ; i < FW_SIZE; i = i + FLASH_BLOCK_SIZE) {
			dev_dbg(&client->dev, "Writing block %d\n", i);
			ret = m10mo_flash_write_block(m10mo_dev,
						      i, &buf[i],
						      FLASH_BLOCK_SIZE);
			if (ret) {
				dev_err(&client->dev, "Flash write failed\n");
				return ret;
			}

		}
	}
	dev_dbg(&client->dev, "Flashing done");
	msleep(50);

	ret = 0;
out_free_mem:
	kfree(buf);

out:
	if (!IS_ERR(fp))
		filp_close(fp, current->files);

	set_fs(old_fs);
	return ret;
}

int m10mo_get_spi_state(struct m10mo_device *m10mo_dev)
{
	if (fw_spi_device && fw_spi_device->spi_enabled)
		return 1;
	return 0;
}

int m10mo_set_spi_state(struct m10mo_device *m10mo_dev, bool enabled)
{
	if (fw_spi_device) {
		fw_spi_device->spi_enabled = !!enabled;
		return 0;
	}
	return -ENODEV;
}


void m10mo_register_spi_fw_flash_interface(struct m10mo_spi *m10mo_spi_dev)
{
	pr_debug("m10mo: Spi interface registered\n");
	fw_spi_device = m10mo_spi_dev;
}
EXPORT_SYMBOL_GPL(m10mo_register_spi_fw_flash_interface);