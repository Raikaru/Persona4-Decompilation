/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00221910)
#include "type.h"

s32 func_00452380(u8 *arg0);

extern u8 D_006290F0[];

// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380(D_006290F0) != 0;
}
#endif /* P4_UNIT_00221910 */

#if defined(P4_UNIT_00221940)
#include "type.h"

u16 *func_00452560(void);

// FUN_00221940
s32 func_00221940(void)
{
    return ((*func_00452560() & 0x10) != 0) ^ 1;
}
#endif /* P4_UNIT_00221940 */

#if defined(P4_UNIT_00223270)
#include "type.h"

s32 func_00452380(u8 *arg0);

extern u8 D_00629640[];

// FUN_00223270
s32 func_00223270(void)
{
    return func_00452380(D_00629640) != 0;
}
#endif /* P4_UNIT_00223270 */

#if defined(P4_UNIT_002238C0)
#include "type.h"

s32 func_00452380(u8 *arg0);

extern u8 D_006296B0[];

// FUN_002238C0
s32 func_002238c0(void)
{
    return func_00452380(D_006296B0) != 0;
}
#endif /* P4_UNIT_002238C0 */

#if defined(P4_UNIT_002238F0)
#include "type.h"

void func_0046d730(u8 *arg0, s32 arg1);

extern u8 D_00629720[];

// FUN_002238F0
s32 func_002238f0(s64 arg0)
{
    s64 temp_2;

    temp_2 = (s64)(arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        return 0xE2;
    case 3:
        return 0x16C;
    case 4:
        return 0x1F3;
    case 6:
        return 0x27A;
    case 7:
        return 0x301;
    case 8:
        return 0x387;
    default:
        func_0046d730(D_00629720, 0x2C);
        return 0;
    }
}
#endif /* P4_UNIT_002238F0 */

#if defined(P4_UNIT_002240B0)
#include "type.h"

s32 func_00452380(u8 *arg0);

extern u8 D_00629700[];

// FUN_002240B0
s32 func_002240b0(void)
{
    return func_00452380(D_00629700) != 0;
}
#endif /* P4_UNIT_002240B0 */

#if defined(P4_UNIT_00224970)
#include "type.h"

void func_001c8d50(void);

extern u8 *DAT_0076449c;

// FUN_00224970
void func_00224970(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        func_001c8d50();
    }
}
#endif /* P4_UNIT_00224970 */

#if defined(P4_UNIT_00225BD0)
#include "type.h"

void func_002258b0(float arg0, float arg1);

// FUN_00225BD0
void func_00225bd0(void)
{
    func_002258b0(0.0f, 2.0f);
}
#endif /* P4_UNIT_00225BD0 */

#if defined(P4_UNIT_0022BD00)
#include "type.h"

extern u8 *DAT_0076449c;

// FUN_0022BD00
s32 func_0022bd00(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}
#endif /* P4_UNIT_0022BD00 */

#if defined(P4_UNIT_0022CED0)
#include "type.h"

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);

extern u8 *DAT_0076449c;

// FUN_0022CED0
void func_0022ced0(s32 arg0)
{
    func_00455ea0(*(s32 *)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}
#endif /* P4_UNIT_0022CED0 */
