/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001704A0)
#include "type.h"

extern s32 func_00159e90(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00764334;

// FUN_001704A0
void func_001704a0(u8 *arg0)
{
    D_00764334 = func_00159e90(0, *(s32 *)(arg0 + 0), *(s32 *)(arg0 + 4));
}
#endif /* P4_UNIT_001704A0 */

#if defined(P4_UNIT_00174AA0)
#include "type.h"

extern void (*jtbl_008873EC[])(s32);

// FUN_00174AA0
void func_00174aa0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}
#endif /* P4_UNIT_00174AA0 */

#if defined(P4_UNIT_00175E70)
#include "type.h"

extern void (*jtbl_008873EC[])(s32);

// FUN_00175E70
void func_00175e70(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}
#endif /* P4_UNIT_00175E70 */

#if defined(P4_UNIT_00176220)
#include "type.h"

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern void func_0029cf50(s32 arg0);

// FUN_00176220 NONMATCHING
s32 func_00176220(void)
{
    if (func_0029d020() >= 4) {
        func_0029cf50(func_00110f00());
        return 1;
    }
    func_0029cf50(0);
    return 0;
}
#endif /* P4_UNIT_00176220 */

#if defined(P4_UNIT_001783B0)
#include "type.h"

extern s32 func_0029cc00(s32 arg0);
extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// FUN_001783B0
s32 func_001783b0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0) & 0xFF;
    temp_16 = func_0029cc00(1) & 0xFF;
    func_00457140(temp_17, temp_16, func_0029cc00(2) & 0xFF, 0);
    return 1;
}
#endif /* P4_UNIT_001783B0 */

#if defined(P4_UNIT_00178470)
#include "type.h"

extern f32 func_0029cd50(s32 arg0);
extern f32 D_00764B5C;

// FUN_00178470
s32 func_00178470(void)
{
    D_00764B5C = func_0029cd50(0);
    return 1;
}
#endif /* P4_UNIT_00178470 */

#if defined(P4_UNIT_001788E0)
#include "type.h"

extern s32 func_0029cc00(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// FUN_001788E0
s32 func_001788e0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_002bd240(1);
    func_002bd270(*(s32 *)(func_0029d040() + 0x124));
    func_002bd280(temp_17, temp_16, 0, 0);
    return 1;
}
#endif /* P4_UNIT_001788E0 */

#if defined(P4_UNIT_00178C00)
#include "type.h"

extern u8 *D_007643D0;

// FUN_00178C00 NONMATCHING
void func_00178c00(void)
{
    *(s32 *)(D_007643D0 + 8) = 1;
    D_007643D0 = 0;
}
#endif /* P4_UNIT_00178C00 */

#if defined(P4_UNIT_0017BB50)
#include "type.h"

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);

// FUN_0017BB50
void func_0017bb50(u8 *arg0, u8 *arg1)
{
    *(s32 *)(arg1 + 0x3C) = func_004571b0()[2];
    func_004571b0()[2] = 0;
    func_004571b0();
    *(s32 *)(arg1 + 0x38) = func_004571c0()[2];
    func_004571c0()[2] = 0;
    func_004571c0();
    *(s32 *)(arg1 + 0x34) = func_004571a0()[2];
    func_004571a0()[2] = 0;
    func_004571a0();
}
#endif /* P4_UNIT_0017BB50 */

#if defined(P4_UNIT_0017BBE0)
#include "type.h"

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);

// FUN_0017BBE0
void func_0017bbe0(u8 *arg0, u8 *arg1)
{
    u8 temp_16;

    temp_16 = arg1[0x3C];
    func_004571b0()[2] = temp_16;
    func_004571b0();
    temp_16 = arg1[0x38];
    func_004571c0()[2] = temp_16;
    func_004571c0();
    temp_16 = arg1[0x34];
    func_004571a0()[2] = temp_16;
    func_004571a0();
}
#endif /* P4_UNIT_0017BBE0 */
