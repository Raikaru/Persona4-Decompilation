/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004E1C20)
#include "type.h"

extern s8 D_00923640[];

#pragma schedule on
// FUN_004E1C20
s8 *func_004e1c20(void) {
    return D_00923640;
}
/* measured: without scheduling the addiu leaves the jr $ra delay slot; nd 0 -> 6 */
#pragma schedule off
#endif /* P4_UNIT_004E1C20 */

#if defined(P4_UNIT_004E3D88)
#include "type.h"

extern u8 D_00731C7C[];

#pragma schedule on
// FUN_004E3D88 NONMATCHING
void func_004e3d88(u8 arg0) {
    D_00731C7C[0] = arg0;
}
/* measured: retail puts the sb in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E3D88 */

#if defined(P4_UNIT_004E3D98)
#include "type.h"

extern s32 D_00731C78[];

#pragma schedule on
// FUN_004E3D98 NONMATCHING
void func_004e3d98(s32 arg0) {
    D_00731C78[0] = arg0;
}
/* measured: retail puts the sw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E3D98 */

#if defined(P4_UNIT_004E3DA8)
#include "type.h"

extern u8 D_00731C7C[];

#pragma schedule on
// FUN_004E3DA8 NONMATCHING
u8 func_004e3da8(void) {
    return D_00731C7C[0];
}
/* measured: retail puts the lbu in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E3DA8 */

#if defined(P4_UNIT_004E3DB8)
#include "type.h"

extern s32 D_00731C78[];

#pragma schedule on
// FUN_004E3DB8 NONMATCHING
s32 func_004e3db8(void) {
    return D_00731C78[0];
}
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E3DB8 */

#if defined(P4_UNIT_004E4180)
#include "type.h"

extern s32 D_00731C3C[];

#pragma schedule on
// FUN_004E4180 NONMATCHING
s32 func_004e4180(void) {
    return D_00731C3C[0];
}
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E4180 */

#if defined(P4_UNIT_004E4280)
#include "type.h"

extern s8 D_00731C01[];

#pragma schedule on
// FUN_004E4280 NONMATCHING
s8 func_004e4280(void) {
    return D_00731C01[0];
}
/* measured: retail puts the lb in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E4280 */

#if defined(P4_UNIT_004E4290)
#include "type.h"

extern s32 D_00731C34[];

#pragma schedule on
// FUN_004E4290 NONMATCHING
s32 func_004e4290(void) {
    return D_00731C34[0];
}
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E4290 */

#if defined(P4_UNIT_004E4688)
#include "type.h"

extern s32 D_00731C70[];

#pragma schedule on
// FUN_004E4688 NONMATCHING
s32 func_004e4688(void) {
    return D_00731C70[0];
}
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
#endif /* P4_UNIT_004E4688 */
