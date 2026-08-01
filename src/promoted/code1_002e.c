/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002E0570)
#include "type.h"

// FUN_002E0570
s64 func_002e0570(u8 *arg0, s32 arg1)
{
    s16 flags;

    flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 4);
    return (s8)((flags & ((1 << (arg1 & 0xFFFF)) & 0xFFFF)) >> (arg1 & 0xFFFF));
}
#endif /* P4_UNIT_002E0570 */

#if defined(P4_UNIT_002E0660)
#include "type.h"

void func_002b82d0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5);

// FUN_002E0660
void func_002e0660(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s64 arg5)
{
    func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}
#endif /* P4_UNIT_002E0660 */

#if defined(P4_UNIT_002E06D0)
#include "type.h"

void func_002b8300(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);

// FUN_002E06D0
void func_002e06d0(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    func_002b8300(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}
#endif /* P4_UNIT_002E06D0 */

#if defined(P4_UNIT_002E0940)
#include "type.h"

void func_002b8340(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);

// FUN_002E0940
void func_002e0940(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    func_002b8340(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}
#endif /* P4_UNIT_002E0940 */

#if defined(P4_UNIT_002E0F90)
#include "type.h"

// P4 retail reaches this object at gp-0x4A78, i.e. absolute 0x007690f0 - 0x4a78
// = 0x00724678, GP-relative.
extern int iGpffffb588;

// FUN_002E0F90
void func_002e0f90(void)
{
    *(s32 *)(*(int *)(iGpffffb588 + 0x24) + 0x2C) |= 1;
}
#endif /* P4_UNIT_002E0F90 */

#if defined(P4_UNIT_002E23B0)
#include "type.h"

void func_002e2a10(s32 arg0, s32 arg1, s8 arg2, s32 arg3);

// FUN_002E23B0
s32 func_002e23b0(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e2a10(*(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}
#endif /* P4_UNIT_002E23B0 */

#if defined(P4_UNIT_002E2410)
#include "type.h"

void func_002e3560(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4);

// FUN_002E2410
s32 func_002e2410(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e3560(arg0, *(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}
#endif /* P4_UNIT_002E2410 */

#if defined(P4_UNIT_002E78A0)
#include "type.h"

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);

// FUN_002E78A0
u8 func_002e78a0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp18;
}
#endif /* P4_UNIT_002E78A0 */

#if defined(P4_UNIT_002E78E0)
#include "type.h"

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);

// FUN_002E78E0
u8 func_002e78e0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp1C;
}
#endif /* P4_UNIT_002E78E0 */

#if defined(P4_UNIT_002E7A80)
#include "type.h"

s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00105fa0(s32 arg0);

// FUN_002E7A80
void func_002e7a80(s32 arg0)
{
    func_00105fa0(func_002b2cb0(arg0, 0, 0x98967F, 0, 1));
}
#endif /* P4_UNIT_002E7A80 */
