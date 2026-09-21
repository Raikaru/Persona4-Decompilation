/* CRI DCT library version (dct_ver.c, "CRI DCT/GC Ver.1.945", Sep 22 2004). */
#include "cri_xpt.h"

const Char8 DCT_version_str[] =
	"\nCRI DCT/GC Ver.1.945 Build:Sep 22 2004 10:34:51\n\0Append: MW2407 GC20Apr2004Patch1\n";

const Sint32 DCT_version_num = 0;

static const Char8 *cri_verstr_ptr;
static Sint32 dct_ver_work;

// The DCT build string (kept referenced through cri_verstr_ptr).
const Char8 *DCT_GetVerStr(void)
{
	cri_verstr_ptr = DCT_version_str;
	return DCT_version_str;
}
