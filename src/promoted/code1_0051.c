/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00510E30)
#include "type.h"

extern u8 *D_00745888[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and retail fills it with the final addiu (nd 6 -> 0). */
// FUN_00510E30
#pragma schedule on
u8 **func_00510e30(void) {
    return (u8 **)D_00745888;
}
#pragma schedule off
#endif /* P4_UNIT_00510E30 */

#if defined(P4_UNIT_00510E40)
#include "type.h"

extern u8 *D_00745888[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final load (nd 6 -> 2; residual
   is v1/v0 coloring below). */
// FUN_00510E40 NONMATCHING
#pragma schedule on
u8 *func_00510e40(void) {
    return D_00745888[0];
}
#pragma schedule off
#endif /* P4_UNIT_00510E40 */

#if defined(P4_UNIT_00513790)
#include "type.h"

extern u8 *D_00745AC0[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final load (nd 6 -> 2; residual
   is v1/v0 coloring below). */
// FUN_00513790 NONMATCHING
#pragma schedule on
u8 *func_00513790(void) {
    return D_00745AC0[0];
}
#pragma schedule off
#endif /* P4_UNIT_00513790 */

#if defined(P4_UNIT_00513A40)
#include "type.h"

extern u8 *D_00745AC0[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store and emits the return
   move before it (nd 6 -> 7; residual is v1/v0 coloring plus move/sw
   delay-slot choice). */
// FUN_00513A40 NONMATCHING
#pragma schedule on
s32 func_00513a40(u8 *arg0) {
    D_00745AC0[0] = arg0;
    return 0;
}
#pragma schedule off
#endif /* P4_UNIT_00513A40 */

#if defined(P4_UNIT_005179E8)
#include "type.h"

// FUN_005179E8 NONMATCHING
void func_005179e8(u8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0x1FC);
    p[1] = 0;
    p[0] = 0;
}
#endif /* P4_UNIT_005179E8 */

#if defined(P4_UNIT_00517C18)
#include "type.h"

typedef struct {
    s32 unk_0; /* 0 */
    s32 unk_4; /* 4 */
} Unit17C18;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 6 -> 0). */
// FUN_00517C18
#pragma schedule on
void func_00517c18(Unit17C18 *arg0, s32 arg1, s32 arg2) {
    arg0->unk_4 = arg2;
    arg0->unk_0 = arg1;
}
#pragma schedule off
#endif /* P4_UNIT_00517C18 */

#if defined(P4_UNIT_00519EE0)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final load (nd 7 -> 2). */
// FUN_00519EE0 NONMATCHING
#pragma schedule on
s32 func_00519ee0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1F7C);
    return *(s32 *)(p + 0x20);
}
#pragma schedule off
#endif /* P4_UNIT_00519EE0 */

#if defined(P4_UNIT_0051F5E8)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final load (nd 7 -> 2). */
// FUN_0051F5E8 NONMATCHING
#pragma schedule on
s32 func_0051f5e8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    return *(s32 *)(p + 0x7C);
}
#pragma schedule off
#endif /* P4_UNIT_0051F5E8 */

#if defined(P4_UNIT_0051F5F8)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 7 -> 2). */
// FUN_0051F5F8 NONMATCHING
#pragma schedule on
void func_0051f5f8(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    *(s32 *)(p + 0x80) = arg1;
}
#pragma schedule off
#endif /* P4_UNIT_0051F5F8 */
