#
# Makefile for sensor drivers
#

obj-$(CONFIG_VIDEO_IMX)        += imx/
obj-$(CONFIG_VIDEO_IMXVB)      += imx135VB/
obj-$(CONFIG_VIDEO_OV5693)     += ov5693.o
obj-$(CONFIG_VIDEO_GC2155)     += gc/

obj-$(CONFIG_VIDEO_MT9M114)    += mt9m114.o
obj-$(CONFIG_VIDEO_MT9E013)    += mt9e013/

obj-$(CONFIG_VIDEO_MT9D113)    += mt9d113.o
CFFLAGS_mt9d113.o = -Werror

obj-$(CONFIG_VIDEO_MT9V113)    += mt9v113.o
CFFLAGS_mt9v113.o = -Werror

obj-$(CONFIG_VIDEO_OV5640)     += ov5640.o
CFFLAGS_ov5640.o = -Werror

obj-$(CONFIG_VIDEO_BF3A20)     += bf3a20.o
obj-$(CONFIG_VIDEO_GC2235)     += gc2235.o
obj-$(CONFIG_VIDEO_OV2685)     += ov2685.o
obj-$(CONFIG_VIDEO_OV9724)     += ov9724.o
obj-$(CONFIG_VIDEO_OV2722)     += ov2722.o
obj-$(CONFIG_VIDEO_OV8830)     += ov8830.o
obj-$(CONFIG_VIDEO_OV5648)     += ov5648.o
obj-$(CONFIG_VIDEO_OV2680)     += ov2680.o
obj-$(CONFIG_VIDEO_OV8858)     += ov8858.o
obj-$(CONFIG_VIDEO_GC2235)     += gc2235.o
obj-$(CONFIG_VIDEO_GC5004)     += gc5004.o
obj-$(CONFIG_VIDEO_GC0339)     += gc0339.o
obj-$(CONFIG_VIDEO_GC0310)     += gc0310.o
obj-$(CONFIG_VIDEO_VM149)      += vm149.o
obj-$(CONFIG_VIDEO_WV511)      += wv511.o
obj-$(CONFIG_VIDEO_DW9714)     += dw9714.o
obj-$(CONFIG_VIDEO_BF3905)     += bf3905.o
obj-$(CONFIG_VIDEO_S5K8AAY)    += s5k8aay.o
CFLAGS_s5k8aay.o += -Werror

obj-$(CONFIG_VIDEO_MSRLIST_HELPER) += libmsrlisthelper.o 
CFLAGS_libmsrlisthelper.o += -Werror

obj-$(CONFIG_VIDEO_AP1302)     += ap1302.o

obj-$(CONFIG_VIDEO_CSI_XACTOR) += xactor_x.o

#
# Makefile for flash drivers
#

obj-$(CONFIG_VIDEO_LM3554) += lm3554.o
obj-$(CONFIG_VIDEO_LM3559) += lm3559.o
obj-$(CONFIG_VIDEO_LM3642) += lm3642.o

