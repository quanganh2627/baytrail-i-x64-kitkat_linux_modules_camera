#include "system_types.h"  /* for hrt_vaddress */
#include "type_support.h"
#include "ia_css_psys_event.h"
#include "ia_css_fwctrl.h"
#include "ia_css_psys_cmd_comm.h"
#include "ia_css_process_group_internal.h"
#include "memory_access.h"

int ia_css_psys_handle_event(ia_css_psys_event_descriptor_t *event)
{
	int ret;
	hrt_vaddress xmem_psys_response;
	ia_css_psysapi_cmd_t cmd_resp;

	if(event == NULL) {
		return -1;
	}

	ret = ia_css_fwctrl_psys_receive_msg(&xmem_psys_response);
	if(ret == 0) {
		mmgr_load(xmem_psys_response, &cmd_resp, sizeof(struct ia_css_psysapi_cmd));
		if(cmd_resp.psys_event == IA_CSS_PSYSPOC_CMD_FINISHED){
			event->type = IA_CSS_PSYS_EVENT_TYPE_CMD_COMPLETE;
			/* Get the process group address */
			event->cookie = (void *) (cmd_resp.cookie);
			ia_css_process_group_stop(cmd_resp.cookie);
		} else {
			/* TODO: Handle other events when fw supports them. */
			event->cookie = 0;
		}


		/* TODO: Change state of output buffers in output termina here? It may
		 * be better to do it under explicit control of the application since it
		 * knows more about explicit fragmentation */
	}
	return ret;
}
