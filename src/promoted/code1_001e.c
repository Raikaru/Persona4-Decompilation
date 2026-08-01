/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001E6820)
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 func_001de000();
extern s64 func_0029cc00();
extern void func_0029cf50();
extern u8 *func_0029d050();

// FUN_001E6820
s32 func_001e6820(void) {
    s64 temp_16;
    s64 temp_17;
    u8 *temp_18;

    temp_18 = (u8 *)(func_0029d050());
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_0029cf50(~func_001de000(temp_18, func_001b0cc0((u64) temp_17 & 0xFFFFFFF), (s16) temp_16, 0) != 0);
    return 1;
}
#endif /* P4_UNIT_001E6820 */

#if defined(P4_UNIT_001E68C0)
#include "type.h"

extern u8 *func_001b0cc0();
extern s64 func_0029cc00();
extern void func_0029cf50();
extern u8 *func_0029d050();

// FUN_001E68C0
s32 func_001e68c0(void) {
    s64 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_001b0cc0((u64) temp_16 & 0xFFFFFFF);
    func_0029cf50(0U);
    return 1;
}
#endif /* P4_UNIT_001E68C0 */

#if defined(P4_UNIT_001E6A00)
#include "type.h"

extern u8 *func_001b0cc0();
extern s64 func_0029cc00();
extern void func_0029cf50();

// FUN_001E6A00
s32 func_001e6a00(void) {
    func_0029cf50(*(u8 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA2) == 0);
    return 1;
}
#endif /* P4_UNIT_001E6A00 */

#if defined(P4_UNIT_001E7D70)
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 func_00231f80();
extern s64 func_0029cc00();
extern void func_0029cf50();

// FUN_001E7D70
s32 func_001e7d70(void) {
    func_0029cf50(func_00231f80(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_001E7D70 */

#if defined(P4_UNIT_001E7DD0)
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 datCalcGetHp();
extern s64 func_0029cc00();
extern void func_0029cf50();

// FUN_001E7DD0
s32 func_001e7dd0(void) {
    func_0029cf50(datCalcGetHp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_001E7DD0 */

#if defined(P4_UNIT_001E7EF0)
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 func_00232290();
extern s64 func_0029cc00();
extern void func_0029cf50();

// FUN_001E7EF0
s32 func_001e7ef0(void) {
    func_0029cf50(func_00232290(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_001E7EF0 */

#if defined(P4_UNIT_001E7F50)
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 datCalcGetSp();
extern s64 func_0029cc00();
extern void func_0029cf50();

// FUN_001E7F50
s32 func_001e7f50(void) {
    func_0029cf50(datCalcGetSp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_001E7F50 */

#if defined(P4_UNIT_001E8D80)
#include "type.h"

extern s64 func_0023d8e0();
extern void func_0029cf50();
extern u8 *func_0029d050();

// FUN_001E8D80
s32 func_001e8d80(void) {
    func_0029cf50((s16) func_0023d8e0(*(u8 **)(*(u8 **)(func_0029d050() + 0x30) + 0xA64), 0U));
    return 1;
}
#endif /* P4_UNIT_001E8D80 */

#if defined(P4_UNIT_001EB380)
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}
#endif /* P4_UNIT_001EB380 */
