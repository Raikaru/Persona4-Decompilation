#include "type.h"

extern void (*DAT_008873EC[])(...);

extern s32 func_00102980(void);
extern void func_00145080();
extern void func_00160440(void);

extern u8 *D_00764334;

extern u8 *func_001452b0(s32 arg0);

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);



// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}



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
/* measured: see the annotation above the matching `on` pragma (func_0015f600). */
#pragma opt_loop_invariants off



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
