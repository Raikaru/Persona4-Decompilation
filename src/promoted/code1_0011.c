/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001104A0)
#include "type.h"

extern s32 D_005E45E0[];

// FUN_001104A0
s32 func_001104a0(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}
#endif /* P4_UNIT_001104A0 */

#if defined(P4_UNIT_00110810)
#include "type.h"

extern u8 D_0079B6D8[];

// FUN_00110810
void func_00110810(s32 arg0, s8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}
#endif /* P4_UNIT_00110810 */

#if defined(P4_UNIT_00110D30)
#include "type.h"

extern s8 D_005E3A00[];

// FUN_00110D30
s32 func_00110d30(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}
#endif /* P4_UNIT_00110D30 */

#if defined(P4_UNIT_00111010)
#include "type.h"

s32 func_0029e970(void);
void func_0029e980(s32);

// FUN_00111010
void func_00111010(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}
#endif /* P4_UNIT_00111010 */

#if defined(P4_UNIT_00111050)
#include "type.h"

void func_00106390(s32, s32);

extern s32 uGpffffb1bc;

// FUN_00111050
void func_00111050(s32 arg0)
{
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
    if (arg0 != 0) {
        uGpffffb1bc = 0;
    }
}
#endif /* P4_UNIT_00111050 */

#if defined(P4_UNIT_0011D100)
#include "type.h"

// FUN_0011D100
void func_0011d100(u8 *arg0, f32 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(f32 *)(temp_3 + 0x4FC) = 0.0f;
        *(f32 *)(temp_3 + 0x500) = 0.0f;
        return;
    }
    *(f32 *)(temp_3 + 0x4FC) = arg1[0];
    *(f32 *)(temp_3 + 0x500) = arg1[1];
}
#endif /* P4_UNIT_0011D100 */

#if defined(P4_UNIT_0011D170)
#include "type.h"

void func_0011e230(s32);
void func_0011e3c0(s32, s32);

// FUN_0011D170
void func_0011d170(u8 *arg0, s32 arg1, s32 arg2)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
    func_0011e3c0(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8), arg2);
}
#endif /* P4_UNIT_0011D170 */

#if defined(P4_UNIT_0011DE80)
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

// FUN_0011DE80
f32 func_0011de80(u8 *arg0, Vec2f *arg1)
{
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x38);
    *arg1 = *(Vec2f *)(temp_2 + 0x28);
    return (f32)(*(s32 *)(temp_2 + 0x10)) / 10.0f;
}
#endif /* P4_UNIT_0011DE80 */

#if defined(P4_UNIT_0011DF90)
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0011DF90 */

#if defined(P4_UNIT_0011FB90)
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

// FUN_0011FB90
void func_0011fb90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0011FB90 */
