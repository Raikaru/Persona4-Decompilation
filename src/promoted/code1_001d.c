/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001D4E90)
#include "type.h"

// FUN_001D4E90
void func_001d4e90(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    *(s32 *)((u8 *)arg3 + 0) = 0;
    *(s32 *)((u8 *)arg3 + 4) = 0;
    *(s32 *)((u8 *)arg3 + 8) = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}
#endif /* P4_UNIT_001D4E90 */

#if defined(P4_UNIT_001DA230)
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x02000000) != 0);
}
#endif /* P4_UNIT_001DA230 */

#if defined(P4_UNIT_001DA270)
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x04000000) != 0);
}
#endif /* P4_UNIT_001DA270 */

#if defined(P4_UNIT_001DA2B0)
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x01000000) != 0);
}
#endif /* P4_UNIT_001DA2B0 */

#if defined(P4_UNIT_001DA2F0)
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x08000000) != 0);
}
#endif /* P4_UNIT_001DA2F0 */

#if defined(P4_UNIT_001DA3E0)
#include "type.h"

typedef int (*code)(...);

extern int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6);
extern s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}
#endif /* P4_UNIT_001DA3E0 */

#if defined(P4_UNIT_001DB790)
#include "type.h"

// FUN_001DB790
s32 btlCond_DOWN(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 8) ? 0 : 1;
}
#endif /* P4_UNIT_001DB790 */

#if defined(P4_UNIT_001DB7B0)
#include "type.h"

// FUN_001DB7B0
s32 btlCond_SLIP(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 0x10) ? 0 : 1;
}
#endif /* P4_UNIT_001DB7B0 */

#if defined(P4_UNIT_001DB900)
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x10000000) != 0);
}
#endif /* P4_UNIT_001DB900 */
