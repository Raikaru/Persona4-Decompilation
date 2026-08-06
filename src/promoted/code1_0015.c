#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb210;
extern void func_00454bd0();

extern void (*DAT_008873EC[])(...);

extern s32 func_00102980(void);
extern void func_00145080();
extern void func_00160440(void);

extern u8 *D_00764334;
extern s32 D_00764384;
extern u32 D_0076438C;


extern u8 *func_001452b0(s32 arg0);

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);



extern void (*jtbl_008873EC[])(s32 arg0);

// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}



// FUN_00155290
s32 func_00155290(void)
{
    return iGpffffb210;
}

// FUN_001560A0
void func_001560a0(u8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_16 + 0xD8) = arg1;
    *(s16 *)(temp_16 + 0xDA) = arg2;
    *(s16 *)(temp_16 + 0xDC) = arg3;
    *(s16 *)(temp_16 + 0xDE) = 0;
    *(s16 *)(temp_16 + 0xE0) = 0;
    func_00122520(1, 0);
    *(s32 *)(temp_16 + 0) = 0x11;
}

// FUN_001560F0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001560f0);

// FUN_00156170
u16 func_00156170(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x18);
}

// FUN_00156180
u16 func_00156180(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A);
}

// FUN_00156190
u16 func_00156190(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20);
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


// FUN_0015A630
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a630);

// FUN_0015A740
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a740);

// FUN_0015C210
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c210);

// FUN_0015C440
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c440);

// FUN_0015C590
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c590);

// FUN_0015C630
s32 func_0015c630(void)
{
    return 1;
}

// FUN_0015C730
void func_0015c730(void)
{
    func_00454bd0();
}

// FUN_0015D270
void func_0015d270(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0x14);
    if (h != 0) {
        (*jtbl_008873EC)(h);
        *(s32 *)(arg0 + 0x14) = 0;
    }
}

// FUN_0015D2C0
u16 *func_0015d2c0(u32 arg0)
{
    u16 *record;
    u32 i;
    s32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16 *)D_00764384;
    emptyCount = 0;
    i = 0;
    recordCount = D_0076438C;
    emptyId = 0xFFFF;
    while (i < recordCount) {
        if (emptyCount != arg0) {
            if (*record == emptyId) {
                emptyCount++;
            }
            i++;
            record = (u16 *)((u8 *)record + 0x84);
        } else {
            break;
        }
    }
    return record;
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
