/* CRI ADX file system init / finish (adx_fini.c, ADXF/GC Ver.7.18): owns the ADXF globals (handle
 * table adxf_obj, AFS partition table adxf_ptinfo, command history) as raw byte arrays and resets them
 * in ADXF_Init / ADXF_Finish. The handle API is in adx_fs.c. */
#include "cri_xpt.h"
#include <string.h>

#define ADXF_MAX_OBJ 16
#define ADXF_OBJ_SIZE 0x44
#define ADXF_MAX_PTINFO 0x100
#define ADXF_CMD_HSTRY_NUM 0x100
#define ADXF_CMD_NUM 8

extern void ADXF_CloseAll(void);

/* volatile: the build string must stay referenced (dead `lwz` in ADXF_Init) */
const Char8 *const volatile adxf_build = "\nADXF/GC Ver.7.18 Build:Oct  8 2004 13:32:02\n";

Sint32 adxf_init_cnt;
static Sint32 adxf_ldptnw_last_stat;
static Sint32 adxf_ldptnw_ptid;
void *adxf_ldptnw_hn;
Sint32 adxf_flno;
Sint32 adxf_hstry_no;
Sint32 adxf_cmd_ncall[ADXF_CMD_NUM];
Uint8 adxf_cmd_hstry[ADXF_CMD_HSTRY_NUM];
Sint32 adxf_ocbi_fg;
void *adxf_ptinfo[ADXF_MAX_PTINFO];
Uint8 adxf_obj[ADXF_MAX_OBJ * ADXF_OBJ_SIZE];

/* dead-stripped by the linker; its references fix the .bss order (ocbi_fg after cmd_hstry) */
Sint32 ADXF_GetNumCmd(Sint32 *ncall)
{
	Sint32 i;
	Sint32 n;

	if (adxf_init_cnt == 0) {
		return 0;
	}
	adxf_ldptnw_last_stat = 0;
	adxf_ldptnw_ptid = -1;
	adxf_ldptnw_hn = NULL;
	adxf_flno = 0;
	adxf_hstry_no = 0;
	n = 0;
	for (i = 0; i < ADXF_CMD_NUM; i++) {
		ncall[i] = adxf_cmd_ncall[i];
		n += adxf_cmd_hstry[i];
	}
	adxf_ocbi_fg = 0;
	adxf_ptinfo[0] = adxf_obj;
	return n;
}

// ADX file system shutdown (reference counted): closes every handle and clears the partition table,
// the command history and the no-wait partition-load state.
void ADXF_Finish(void)
{
	if (--adxf_init_cnt == 0) {
		ADXF_CloseAll();
		adxf_ldptnw_last_stat = 1;
		adxf_ldptnw_ptid = -1;
		adxf_ldptnw_hn = NULL;
		adxf_flno = 0;
		adxf_ocbi_fg = 0;
		adxf_hstry_no = 0;
		memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
		memset(adxf_cmd_hstry, 0xFF, sizeof(adxf_cmd_hstry));
		memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo));
		memset(adxf_obj, 0, sizeof(adxf_obj));
	}
}

// ADX file system init (reference counted): clears the handles, the AFS partition table
// (adxf_ptinfo) and the command history; reads the build string to keep it linked.
void ADXF_Init(void)
{
	adxf_build;
	if (adxf_init_cnt == 0) {
		memset(adxf_obj, 0, sizeof(adxf_obj));
		memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo));
		memset(adxf_cmd_hstry, 0xFF, sizeof(adxf_cmd_hstry));
		memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
		adxf_hstry_no = 0;
		adxf_ocbi_fg = 0;
		adxf_flno = 0;
		adxf_ldptnw_hn = NULL;
		adxf_ldptnw_ptid = -1;
		adxf_ldptnw_last_stat = 1;
	}
	adxf_init_cnt++;
}
