/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00275A40)
/* Source unit: src/frFontEx_00275a40.c */
#include "type.h"

/* Ported from P3FES frFontGetHeight (verified MATCH there). The font-height
 * table lives at the address-normalized P4 global D_00763808; the scalar
 * extern + address-of-index form is required to reproduce retail's
 * gp-relative load sequence. */
extern s8 D_00763808;

// FUN_00275A40
s8 func_00275a40(char param_1)
{
    return (&D_00763808)[param_1];
}
#endif /* P4_UNIT_00275A40 */

#if defined(P4_UNIT_002BB1C0)
/* Source unit: src/frFontEx_002bb1c0.c */
#include "type.h"

/* Ported from P3FES frFontGetHeight (verified MATCH there). The font-height
 * table lives at the address-normalized P4 global D_00764670. */
extern s8 D_00764670;

// FUN_002BB1C0
s8 func_002bb1c0(char param_1)
{
    return (&D_00764670)[param_1];
}
#endif /* P4_UNIT_002BB1C0 */
