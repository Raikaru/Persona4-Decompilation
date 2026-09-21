/* CRI SUD (Sofdec picture user data) analyser (sud_lib.c, "CRI SUD/GC Ver.0.05"): finds the
 * "<SUDPS_>" record the Sofdec encoder writes into each picture's user data and reads its type
 * letters (scan P/I, field division A/D, colour space N/C). */
#include "cri_xpt.h"
#include <string.h>
#include <stdio.h>

static const Char8 sud_ver_str[] = "\nCRI SUD/GC Ver.0.05 Build:Sep 22 2004 10:35:24\n";

Sint32 sud_init_cnt;
static const Char8 *sud_dummy;

/* The three type-name tables and the debug print below belong to functions the linker dead-stripped;
 * only their .rodata templates and strings survive. */
const Char8 *SUD_GetTypeDivFieldName(Sint32 type)
{
	const Char8 *tbl[2] = {"A", "D"};
	return tbl[type & 1];
}

// Dead: "N"/"C" name of the colour-space type.
const Char8 *SUD_GetTypeCcsName(Sint32 type)
{
	const Char8 *tbl[2] = {"N", "C"};
	return tbl[type & 1];
}

// Dead: "P"/"I" name of the scan type.
const Char8 *SUD_GetTypeScanName(Sint32 type)
{
	const Char8 *tbl[2] = {"P", "I"};
	return tbl[type & 1];
}

// Finds the last "<SUDPS_>" record in the picture user data; *sud points at it, *sudsize = 0x23.
void SUD_SearchSudDat(Uint8 *dat, Sint32 size, void **sud, Sint32 *sudsize)
{
	Sint32 i;
	Uint8 *p = dat;

	*sud = NULL;
	*sudsize = 0;
	if (dat == NULL || size <= 0) {
		return;
	}
	for (i = 0; i < size; p++, i++) {
		if (memcmp(p, "<", 1) == 0) {
			if (memcmp(p, "<SUDPS_>", 8) == 0) {
				*sud = p;
				*sudsize = (*sud == NULL) ? 0 : 0x23;
			}
		}
	}
}

// Dead: formats a "<%06X>02\n" record.
void SUD_PrintDat(Char8 *buf, Sint32 code)
{
	sprintf(buf, "<%06X>", code);
	strcat(buf, "02");
	strcat(buf, "\n");
}

// Colour-space type letter (byte 0x13) is 'C'.
// FUN_0052D010
Bool SUD_AnalyTypeCcs(Uint8 *dat, Sint32 size)
{
	if (dat == NULL || size < 0) {
		return FALSE;
	}
	return strncmp((Char8 *)dat + 0x13, "C", 1) == 0;
}

// Field-division type letter (byte 0x12) is 'D'.
// FUN_0052CFD0
Bool SUD_AnalyTypeDivField(Uint8 *dat, Sint32 size)
{
	if (dat == NULL || size < 0) {
		return FALSE;
	}
	return strncmp((Char8 *)dat + 0x12, "D", 1) == 0;
}

// Module init (once): keeps the version string referenced.
void SUD_Init(void)
{
	if (sud_init_cnt < 1) {
		sud_dummy = sud_ver_str;
		sud_init_cnt++;
	}
}
