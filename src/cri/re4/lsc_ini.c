/* CRI LSC init / finish (lsc_ini.c, LSC/GC Ver.2.18): the scheduler table lsc_obj (32) and the
 * build string. */
#include "cri_xpt.h"
#include "lsc.h"
#include <string.h>

/* volatile: the build string must stay referenced (dead `lwz` in LSC_Init) */
const Char8 *const volatile lsc_build = "\nLSC/GC Ver.2.18 Build:Oct  8 2004 13:31:48\n";
static const Sint32 lsc_reserved = 0;

static Sint32 lsc_init_cnt = 0;
LSC_OBJ lsc_obj[32];
Sint32 lsc_work;

// Destroys the live schedulers and clears the table and error callback on the last release.
void LSC_Finish(void)
{
	Sint32 msk;
	LSC_OBJ *lsc;
	Sint32 i;

	LSC_LockCrs(&msk);
	if (--lsc_init_cnt == 0) {
		for (i = 0; i < 32; i++) {
			lsc = &lsc_obj[i];
			if (lsc->used == 1) {
				LSC_Destroy(lsc);
			}
		}
		memset(lsc_obj, 0, sizeof(lsc_obj));
		LSC_EntryErrFunc(NULL, NULL);
	}
	LSC_UnlockCrs(&msk);
}

// Clears the table and error callback on the first init.
void LSC_Init(void)
{
	Sint32 msk;

	lsc_build;
	LSC_LockCrs(&msk);
	if (lsc_init_cnt == 0) {
		memset(lsc_obj, 0, sizeof(lsc_obj));
		LSC_EntryErrFunc(NULL, NULL);
	}
	lsc_init_cnt++;
	LSC_UnlockCrs(&msk);
}
