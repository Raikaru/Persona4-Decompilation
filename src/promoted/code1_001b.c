/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001B1570)
#include "type.h"

extern u8 *D_0076449C;

// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}
#endif /* P4_UNIT_001B1570 */

#if defined(P4_UNIT_001B1830)
#include "type.h"

extern u8 *D_0076449C;

// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
}
#endif /* P4_UNIT_001B1830 */

#if defined(P4_UNIT_001B3F00)
#include "type.h"

extern u8 *D_0076449C;
extern u8 D_005F7000[];

void func_00194590(u8 *arg0, u32 arg1);
u8 *func_001bc920(u8 *arg0, u32 arg1);
u8 *func_001d3700(u32 arg0, u32 arg1);
void func_002baac0(void *arg0);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);

// FUN_001B3F00
void func_001b3f00(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0(&D_005F7000);
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = func_001d3700(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    func_00194590(t, 0);
    func_00194590(func_001bc920(NULL, 0x2B), 0);
}
#endif /* P4_UNIT_001B3F00 */

#if defined(P4_UNIT_001B7060)
#include "type.h"

// FUN_001B7060
void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}
#endif /* P4_UNIT_001B7060 */

#if defined(P4_UNIT_001B70A0)
#include "type.h"

// FUN_001B70A0
void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}
#endif /* P4_UNIT_001B70A0 */

#if defined(P4_UNIT_001BC330)
#include "type.h"

s32 func_001f2f90(u8 *arg0);

// FUN_001BC330
s32 func_001bc330(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xE0);
    if (ptr == NULL) {
        return 0;
    }
    if (func_001f2f90(ptr) == 0) {
        return 1;
    }
    return *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6C) == 3;
}
#endif /* P4_UNIT_001BC330 */

#if defined(P4_UNIT_001BCC80)
#include "type.h"

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);

// FUN_001BCC80
s32 func_001bcc80(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}
#endif /* P4_UNIT_001BCC80 */

#if defined(P4_UNIT_001BD4F0)
#include "type.h"

void func_00194fa0(u8 *arg0, u32 arg1);
void func_00194fc0(u8 *arg0, u32 arg1);

// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    func_00194fa0(arg0, 0xA);
    func_00194fc0(arg0, 4);
}
#endif /* P4_UNIT_001BD4F0 */

#if defined(P4_UNIT_001BD530)
#include "type.h"

void func_00194fc0(u8 *arg0, u32 arg1);

// FUN_001BD530
void func_001bd530(u32 arg0) {
    func_00194fc0((u8 *)arg0, 0xA);
}
#endif /* P4_UNIT_001BD530 */

#if defined(P4_UNIT_001BDD60)
#include "type.h"

extern u8 *D_0076449C;

// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}
#endif /* P4_UNIT_001BDD60 */
