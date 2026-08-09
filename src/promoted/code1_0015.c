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
extern void func_00440b68();
extern s32 iGpffff9e28;
extern s32 iGpffffb218;
extern u8 D_007D3E10[];
extern u8 D_007E36E4[];
extern u8 D_007E36F8[];
extern u8 D_005F0740[];
extern u8 D_005F05E8[];
extern u8 D_005F06C0[];
extern u8 D_005F0720[];
extern s16 D_005F05D0[];
extern u8 D_005F05CE[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_00442088(u8 *dst, const char *fmt, s32 arg);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern u8 D_005EFF60[];


extern u8 *func_001452b0(s32 arg0);

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);



extern void (*jtbl_008873EC[])(s32 arg0);

// FUN_001537C0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001537c0);
// FUN_001538A0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001538a0);
// FUN_00153A00
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00153a00);
// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}



// FUN_00155070
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00155070);
// FUN_00155250
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00155250);
// FUN_00155280
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00155280);
// FUN_00155290
s32 func_00155290(void)
{
    return iGpffffb210;
}

// FUN_001552A0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001552a0);
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
void func_001560f0(u8 *arg0, s32 arg1) {
    u8 *p;

    if (arg0 != NULL) {
        p = *(u8 **)(arg0 + 0x38);
        func_00440b68(D_005EFF60);
        *(s32 *)(p + 8) = arg1;
    }
}

// FUN_00156140
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156140);
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

// FUN_001561A0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001561a0);
// FUN_00156640
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156640);
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



// FUN_00156800
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156800);
// FUN_00156CF0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156cf0);
// FUN_00157310
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00157310);
// FUN_00157700
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00157700);
// FUN_001579B0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001579b0);
// FUN_001582F0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001582f0);
// FUN_001587D0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001587d0);
// FUN_001599D0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001599d0);
// FUN_00159A60
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00159a60);
// FUN_00159D50
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00159d50);
// FUN_00159E90
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00159e90);
// FUN_00159F70
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00159f70);
// FUN_0015A0C0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a0c0);
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


// FUN_0015A160
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a160);
// FUN_0015A190
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a190);
// FUN_0015A320
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a320);
// FUN_0015A350
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a350);
// FUN_0015A520
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a520);
// FUN_0015A560
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a560);
// FUN_0015A630
void func_0015a630(void) {
    func_0043f9c8(D_007D3E10, 0, 0xF8FC);
    func_0043f9c8(D_007E36E4, 0xFF, 0x14);
    func_0043f9c8(D_007E36F8, 0xFF, 0x14);
}

// FUN_0015A690
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a690);
// FUN_0015A6A0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a6a0);
// FUN_0015A6B0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a6b0);
// FUN_0015A740
u8 func_0015a740(s32 arg0) {
    s32 i = 0;

    while (D_005F05D0[i] >= 0) {
        if (arg0 < D_005F05D0[i]) {
            break;
        }
        i++;
    }
    if (i == 0) {
        return 0xFF;
    }
    return D_007E36E4[arg0 - *(s16 *)(D_005F05CE + i * 2)];
}

// FUN_0015A7C0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015a7c0);
// FUN_0015AB20
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015ab20);
// FUN_0015AC60
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015ac60);
// FUN_0015B240
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015b240);
// FUN_0015B3E0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015b3e0);
// FUN_0015BAE0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015bae0);
// FUN_0015C1E0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c1e0);
// FUN_0015C210
void func_0015c210(void) {
    if (D_00764334 == NULL) {
        return;
    }
    if (*(s32 *)(*(u8 **)(D_00764334 + 0x38) + 0x40) != 0) {
        return;
    }
    if (iGpffffb218 != 0) {
        return;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xB48);
    iGpffffb218 = func_00454a60(D_005F06C0, 1);
}

// FUN_0015C280
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c280);
// FUN_0015C360
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c360);
// FUN_0015C440
s32 func_0015c440(void)
{
    s32 r = 0;
    u8 *p = D_00764334;
    if (p == NULL) {
        return r;
    }
    if (*(u32 *)(*(u8 **)(p + 0x38) + 0x2C) == 0) {
        func_00440b68(&iGpffff9e28, D_005F05E8, 0xC19);
        r = func_00454a60(D_005F0720, 0);
    }
    return r;
}


// FUN_0015C4B0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c4b0);
// FUN_0015C590
void func_0015c590(s32 arg0) {
    u8 sp10[0x80];

    func_00442088(sp10, (const char *)D_005F0740, arg0);
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC49);
    func_00454a60(sp10, 0);
}

// FUN_0015C5F0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c5f0);
// FUN_0015C630
s32 func_0015c630(void)
{
    return 1;
}

// FUN_0015C640
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c640);
// FUN_0015C6F0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015c6f0);
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

// FUN_0015D310
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015d310);
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
