/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00470C10)
#include "type.h"

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

// FUN_00470C10
void func_00470c10(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 2;
        *(s32 *)(temp_2 + 0x208) = arg2;
        *(s32 *)(temp_2 + 0x210) = 0;
        *(s32 *)(temp_2 + 0x214) = 1;
        func_004704d0(arg0);
    }
}
#endif /* P4_UNIT_00470C10 */

#if defined(P4_UNIT_00470C80)
#include "type.h"

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

// FUN_00470C80
void func_00470c80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 4;
        *(f32 *)(temp_2 + 0x20C) = (f32)arg2;
        *(s32 *)(temp_2 + 0x210) = arg3;
        *(s32 *)(temp_2 + 0x214) = arg4;
        func_004704d0(arg0);
    }
}
#endif /* P4_UNIT_00470C80 */

#if defined(P4_UNIT_00478E70)
#include "type.h"

extern void func_00478a30(u8 *arg0, s32 arg1);

// FUN_00478E70
void func_00478e70(u8 *arg0)
{
    func_00478a30(arg0, (*(s32 *)(arg0 + 0xD8) & 1) == 0);
}
#endif /* P4_UNIT_00478E70 */

#if defined(P4_UNIT_00479030)
#include "type.h"

extern void func_00478ec0(u8 *arg0);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

// FUN_00479030
void func_00479030(u8 *arg0, u8 *arg1)
{
    func_00478ec0(arg0);
    RpSkyRenderStateSet(2, *(s32 *)(arg1 + 0xE4));
    RpSkyRenderStateSet(3, *(s32 *)(arg1 + 0xE8));
}
#endif /* P4_UNIT_00479030 */

#if defined(P4_UNIT_00479C30)
#include "type.h"

extern s32 func_00479ca0(u8 *arg0, s32 arg1);

/* measured: single residual at off 64 -- addu $v0,$s0,$v0 vs retail
 * addu $v0,$v0,$s0 (commutative operand swap on the final index*0xA4+base
 * add). Both C operand orders compile identically; nd 2 -> 2. Allocator
 * floor (same residual in 0047ADF0/0047AE90). */
// FUN_00479C30 NONMATCHING
s16 func_00479c30(s32 arg0, s32 arg1)
{
    if (func_00479ca0((u8 *)arg0, arg1) != 0) {
        return *(s16 *)(arg0 + ((arg1 & 0xFFFF) * 0xA4) + 0xF0);
    }
    return -1;
}
#endif /* P4_UNIT_00479C30 */

#if defined(P4_UNIT_0047ADF0)
#include "type.h"

/* measured: single residual at off 16 -- addu $v1,$a0,$v1 vs retail
 * addu $v1,$v1,$a0 (commutative operand swap on the final index*0xC+base
 * add). Both C operand orders compile identically; nd 1 -> 1. Allocator
 * floor (same residual in 0047AE90/00479C30). */
// FUN_0047ADF0 NONMATCHING
void func_0047adf0(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(((arg1 & 0xFFFF) * 0xC) + arg0 + 0x294) = arg2;
}
#endif /* P4_UNIT_0047ADF0 */

#if defined(P4_UNIT_0047AE90)
#include "type.h"

extern s32 func_004782b0(u8 *arg0);

/* measured: single residual at off 24 -- addu $v0,$a0,$v0 vs retail
 * addu $v0,$v0,$a0 (commutative operand swap on the final index*0xC+base
 * add). Both C operand orders compile identically; nd 1 -> 1. Allocator
 * floor (same residual in 0047ADF0/00479C30). */
// FUN_0047AE90 NONMATCHING
s32 func_0047ae90(s32 arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + ((arg1 & 0xFFFF) * 0xC) + 0x290);
    if (temp_4 == NULL) {
        return 1;
    }
    return func_004782b0(temp_4);
}
#endif /* P4_UNIT_0047AE90 */

#if defined(P4_UNIT_0047D7E0)
#include "type.h"

extern void func_004b11d0(s32 arg0, s32 arg1);

// FUN_0047D7E0
void func_0047d7e0(s32 arg0, u8 **arg1)
{
    s32 temp_5;
    u8 *var_16;

    var_16 = *arg1;
    while (var_16 != NULL) {
        temp_5 = *(s32 *)(var_16 + 8);
        if (temp_5 != 0) {
            func_004b11d0(arg0, temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}
#endif /* P4_UNIT_0047D7E0 */

#if defined(P4_UNIT_0047D8A0)
#include "type.h"

extern void func_004b13f0(s32 arg0, s32 arg1);

// FUN_0047D8A0
void func_0047d8a0(u8 **arg0, s32 arg1)
{
    s32 temp_4;
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        temp_4 = *(s32 *)(var_16 + 8);
        if (temp_4 != 0) {
            func_004b13f0(temp_4, arg1);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}
#endif /* P4_UNIT_0047D8A0 */

#if defined(P4_UNIT_0047DD70)
#include "type.h"

extern void func_004b5c20(s32 arg0);

// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg1 + 4);
    if (temp_4 != 0) {
        func_004b5c20(temp_4);
    }
}
#endif /* P4_UNIT_0047DD70 */
