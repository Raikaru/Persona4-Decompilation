/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00230710)
#include "type.h"

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;
extern void func_0045a9a0(s32 arg0, s32 arg1);

// FUN_00230710
s32 func_00230710(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB94) != 0) {
        func_0045a9a0(2, 0);
    }
    return 1;
}
#endif /* P4_UNIT_00230710 */

#if defined(P4_UNIT_00231550)
#include "type.h"

extern void func_00231380(s32 *arg0, s32 arg1);

// FUN_00231550
void func_00231550(s32 arg0, s32 arg1)
{
    func_00231380((s32 *)arg0, arg1 & 0xFFFF);
}
#endif /* P4_UNIT_00231550 */

#if defined(P4_UNIT_002319C0)
#include "type.h"

extern void (*jtbl_008873EC[])(void);

// FUN_002319C0
void func_002319c0(void)
{
    jtbl_008873EC[0]();
}
#endif /* P4_UNIT_002319C0 */

#if defined(P4_UNIT_00231D70)
#include "type.h"

extern u32 func_003b7060(void);
extern void func_0046d730(u8 *arg0, s32 arg1);
extern u8 D_00635938[];

// FUN_00231D70
u32 func_00231d70(u32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_00635938, 0x17);
    }
    return func_003b7060() % arg0;
}
#endif /* P4_UNIT_00231D70 */

#if defined(P4_UNIT_00231DC0)
#include "type.h"

extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);

// FUN_00231DC0
void func_00231dc0(u8 *arg0, s16 arg1)
{
    func_0043f9c8(arg0, 0, 0x30);
    *(s16 *)(arg0 + 2) = arg1;
    *(s8 *)(arg0 + 6) = 1;
    *(s16 *)(arg0 + 8) = 1;
    *(s16 *)(arg0 + 0xA) = 1;
    *(s16 *)(arg0 + 4) = arg1;
    *(s8 *)(arg0 + 0x10) = 0;
}
#endif /* P4_UNIT_00231DC0 */

#if defined(P4_UNIT_00232830)
#include "type.h"

extern s32 func_00106600(s16 arg);

// FUN_00232830
s32 func_00232830(u16 *arg0, s64 arg1)
{
    if (*arg0 & 4) {
        return 0;
    }
    return (func_00106600((s16)arg1) & 0xFF) > 0;
}
#endif /* P4_UNIT_00232830 */

#if defined(P4_UNIT_0023A620)
#include "type.h"

// FUN_0023A620
s32 func_0023a620(s32 arg0, s32 arg1)
{
    s32 temp_3 = arg1 & 0xFFFF;
    s32 var_2 = ((temp_3 & 0xFF00) << 0x10) | ((temp_3 & 0xFFFF00FF) * 5);
    if (!(var_2 & 0xFFFF)) {
        if (var_2 & 0x08000000) {
            var_2 |= 0x7D;
        } else if (var_2 & 0x27000000) {
            var_2 |= 0x64;
        } else if (var_2 & 0x10000000) {
            var_2 |= 0x32;
        }
    }
    return var_2;
}
#endif /* P4_UNIT_0023A620 */

#if defined(P4_UNIT_0023D6E0)
#include "type.h"

extern void func_0046d730(u8 *arg0, s32 arg1);
extern u8 D_00635938[];

// FUN_0023D6E0
s32 func_0023d6e0(s16 arg0)
{
    if (arg0 >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    return 1 << (arg0 + 1);
}
#endif /* P4_UNIT_0023D6E0 */

#if defined(P4_UNIT_0023DD90)
#include "type.h"

/* gp - 0x4C48 = 0x007690f0 - 0x4c48 = 0x007644a8 */
extern u8 *iGpffffb3b8;

// FUN_0023DD90
u8 func_0023dd90(u8 *arg0, s32 arg1)
{
    u8 *base = iGpffffb3b8 + 3;
    return *(u8 *)(base + (arg1 & 0xFFFF) * 0x28);
}
#endif /* P4_UNIT_0023DD90 */

#if defined(P4_UNIT_0023E1F0)
#include "type.h"

extern void func_0046d730(u8 *arg0, s32 arg1);
extern u8 D_00635938[];
/* gp - 0x4C40 = 0x007690f0 - 0x4c40 = 0x007644b0 */
extern u8 *iGpffffb3c0;

// FUN_0023E1F0
u8 func_0023e1f0(u8 *arg0)
{
    u8 *base;
    if (*(u16 *)(arg0 + 0) & 4) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFBB);
    }
    base = iGpffffb3c0 + 0x14A;
    return *(u8 *)(base + *(u16 *)(arg0 + 2) * 0x14C);
}
#endif /* P4_UNIT_0023E1F0 */
