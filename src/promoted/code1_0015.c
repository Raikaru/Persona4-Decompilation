/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00153A30)
#include "type.h"

extern void (*DAT_008873EC[])(...);

// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00153A30 */

#if defined(P4_UNIT_00153B60)
#include "type.h"

extern void func_00161460(s32 arg0, s32 arg1, s32 arg2);

// FUN_00153B60
void func_00153b60(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 8) = arg1;
    func_00161460(*(s32 *)(work + 4), arg1, *(s32 *)(work + 0x10));
}
#endif /* P4_UNIT_00153B60 */

#if defined(P4_UNIT_001546A0)
#include "type.h"

extern s16 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s64 arg0, s32 arg1);
extern void func_00154720(u16 arg0, u16 arg1, s64 arg2);

// FUN_001546A0
void func_001546a0(u16 arg0, u16 arg1)
{
    func_00154720(arg0, arg1, func_00110960(func_001060b0(), func_001060c0() & 0xFF));
}
#endif /* P4_UNIT_001546A0 */

#if defined(P4_UNIT_00156750)
#include "type.h"

extern s32 func_00102980(void);
extern void func_00145080();
extern void func_00160440(void);

// FUN_00156750
void func_00156750(u8 *arg0)
{
    u8 *work;
    u16 value;

    work = *(u8 **)(arg0 + 0x38);
    func_00160440();
    if ((func_00102980() != 9) && (func_00102980() != 0xB) && (func_00102980() != 0xA)) {
        func_00145080();
    }
    value = *(u16 *)(work + 0x18);
    if ((((s32)value >= 0x15) && ((s32)value <= 0x1E)) ||
        ((value == 6) && (value = *(u16 *)(work + 0x1A), value == 1))) {
        func_00145080(value);
    }
}
#endif /* P4_UNIT_00156750 */

#if defined(P4_UNIT_0015A100)
#include "type.h"

extern u8 *D_00764334;

// FUN_0015A100
s32 func_0015a100(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x2C);
}
#endif /* P4_UNIT_0015A100 */

#if defined(P4_UNIT_0015A130)
#include "type.h"

extern u8 *D_00764334;

// FUN_0015A130
s32 func_0015a130(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x30);
}
#endif /* P4_UNIT_0015A130 */

#if defined(P4_UNIT_0015CBE0)
#include "type.h"

extern u8 *func_00155280(void);

/* measured: opt_loop_invariants hoists the 0xFFFF compare constant (nd 8 -> 3).
 * Residual nd 3: scan pointer loaded from the call result coloured $a2 where
 * retail reuses $v0 -- allocator floor (decl order/typing/spelling/temps). */
#pragma opt_loop_invariants on
// FUN_0015CBE0 NONMATCHING
void func_0015cbe0(s32 arg0)
{
    u16 *work = *(u16 **)(func_00155280() + 0x18F4);
    s32 count = 0;

    for (;;) {
        if (count == arg0) {
            break;
        }
        if (*work == 0xFFFF) {
            count += 1;
        }
        work += 0x10;
    }
}
#pragma opt_loop_invariants off
#endif /* P4_UNIT_0015CBE0 */

#if defined(P4_UNIT_0015E7A0)
#include "type.h"

extern void (*DAT_008873EC[])(...);

// FUN_0015E7A0
void func_0015e7a0(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0015E7A0 */

#if defined(P4_UNIT_0015F600)
#include "type.h"

extern u8 *func_001452b0(s32 arg0);

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
// FUN_0015F600
s32 func_0015f600(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            result = 0;
            break;
        }
        work = *(u8 **)(work + 0x138);
    }
    return result;
}
#pragma opt_loop_invariants off
#endif /* P4_UNIT_0015F600 */

#if defined(P4_UNIT_0015F660)
#include "type.h"

extern u8 *func_001452b0(s32 arg0);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);

// FUN_0015F660
s32 func_0015f660(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            if (func_004782b0(*(s32 *)(work + 0x164)) != 0) {
                *(s32 *)(work + 0x28) |= 0x10000000;
            }
            result = 0;
        }
        work = *(u8 **)(work + 0x138);
    }
    if (func_003e8120(func_00457120()) != 0) {
        func_003e8110(func_00457120());
    }
    return result;
}
#endif /* P4_UNIT_0015F660 */
