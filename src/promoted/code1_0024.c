/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00243920)
#include "type.h"

extern u8 *func_00106820(s16 arg0);

// FUN_00243920
u16 func_00243920(s64 arg0)
{
    return *(u16 *)((u8 *)func_00106820((s16)arg0) + 0x24);
}
#endif /* P4_UNIT_00243920 */

#if defined(P4_UNIT_0024ACF0)
#include "type.h"

extern s32 func_0029cc00(s32 arg0);
extern void func_0029cf50(s32 arg0);
extern s32 func_00107930(s32 arg0);

// FUN_0024ACF0
s32 func_0024acf0(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_0029cf50(0);
    if ((temp_16 != 0) && (temp_16 != 1)) {
        return 1;
    }
    func_0029cf50(func_00107930(temp_16));
    return 1;
}
#endif /* P4_UNIT_0024ACF0 */

#if defined(P4_UNIT_0024AD70)
#include "type.h"

extern s32 func_0029cc00(s32 arg0);
extern s32 func_00109100(s32 arg0);
extern void func_001090c0(s32 arg0);

// FUN_0024AD70
s32 func_0024ad70(void)
{
    func_001090c0(func_00109100(func_0029cc00(0) & 0xFFFF));
    return 1;
}
#endif /* P4_UNIT_0024AD70 */

#if defined(P4_UNIT_0024ADB0)
#include "type.h"

extern s32 func_001090e0(void);
extern void func_0029cf50(s32 arg0);
extern void datResetTotalBtl(void);
extern void func_00106020(s32 arg0);

// FUN_0024ADB0
s32 func_0024adb0(void)
{
    s32 temp_2;

    temp_2 = func_001090e0();
    func_0029cf50(temp_2);
    datResetTotalBtl();
    func_00106020(temp_2);
    return 1;
}
#endif /* P4_UNIT_0024ADB0 */

#if defined(P4_UNIT_0024AE00)
#include "type.h"

extern s32 func_0029cc00(s32 arg0);
extern s32 func_00109100(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AE00
s32 func_0024ae00(void)
{
    func_0029cf50(func_00109100(func_0029cc00(0) & 0xFFFF));
    return 1;
}
#endif /* P4_UNIT_0024AE00 */

#if defined(P4_UNIT_0024AE40)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_00249010(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AE40
s32 func_0024ae40(void)
{
    func_0029cf50(func_00249010(func_001060b0()));
    return 1;
}
#endif /* P4_UNIT_0024AE40 */

#if defined(P4_UNIT_0024AE80)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_00249230(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AE80
s32 func_0024ae80(void)
{
    func_0029cf50(func_00249230(func_001060b0()) != 0);
    return 1;
}
#endif /* P4_UNIT_0024AE80 */

#if defined(P4_UNIT_0024AEC0)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_002492b0(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AEC0
s32 func_0024aec0(void)
{
    func_0029cf50(func_002492b0(func_001060b0()) != 0);
    return 1;
}
#endif /* P4_UNIT_0024AEC0 */

#if defined(P4_UNIT_0024AF00)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_00249370(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0029cc00(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AF00
s32 func_0024af00(void)
{
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0029cf50(0);
    if ((temp_17 != 0) && (temp_17 != 1)) {
        return 1;
    }
    if (temp_16 == 0) {
        func_0029cf50(func_00249370(0, func_001060b0(), temp_17));
    } else {
        func_0029cf50(func_00249370(1, func_001060b0(), temp_17));
    }
    return 1;
}
#endif /* P4_UNIT_0024AF00 */

#if defined(P4_UNIT_0024AFE0)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_002494c0(s32 arg0, s32 arg1);
extern s32 func_0029cc00(s32 arg0);
extern void func_0029cf50(s32 arg0);

// FUN_0024AFE0
s32 func_0024afe0(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_0029cf50(0);
    if ((temp_16 != 0) && (temp_16 != 1)) {
        return 1;
    }
    func_0029cf50(func_002494c0(func_001060b0(), temp_16));
    return 1;
}
#endif /* P4_UNIT_0024AFE0 */
