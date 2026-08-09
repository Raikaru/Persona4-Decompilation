#include "include_asm.h"
#include "type.h"

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void func_00264d90();
extern s32 D_00796670[];

extern void func_00267570();

extern u8 *D_007242CC;
extern s32 iGpffffb1e0;
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void func_00103a60(void);
extern void func_00451de0(void *list, s32 count, s32 a, s32 b,
                           void *init, void *close, void *buf);
extern s32 func_00121af0(void);
extern u8 *func_00460990(void);
extern void func_00460ac0(char *name, u8 *task);
extern void func_001221a0(void);
extern void func_00122a40(void);
extern char D_00796340[];
extern char D_00795F50[];
extern s32 func_001060b0(void);
extern s32 func_001060c0(void);
extern s32 func_00110850(s16 arg0, s16 arg1);
extern s32 func_0015a160(void);
extern s32 func_0028b650(void);

extern s32 func_004522d0(s32 arg0);
extern void func_00103b00(void);
extern void func_0046a340(s32 arg0);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0012dea0(u8 *arg0, s32 arg1);
extern void func_0046d280(s32 arg0);
extern s32 func_0034c210(void);


typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;
typedef struct {
    f32 x;
    f32 y;
} SVec2_0012;



extern void func_003ef3a0(void *arg0);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_0034f5d0(u8 *arg0);
extern s32 func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(s32 window, const void *data, s32 prio, s32 a3,
                         s32 a4, void *init, void *close, u8 *work);
extern void func_001228c0(void);
extern u8 *iGpffffb1dc;
extern u8 D_005E5170[];
extern u8 D_005E5180[];
extern u8 D_005E5190[];
extern u8 D_005E51A0[];
extern u8 D_005E51B0[];
extern void func_00123b70(u8 *arg0);
extern void func_00123d50(u8 *arg0);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void func_0046d730(const void *file, s32 line);
extern u8 D_005E5548[];
extern u8 D_005E5720[];
extern void func_0012aa70(void);
extern void func_0012b660(void);

// FUN_001203A0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001203a0);
// FUN_00120AE0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120ae0);
// FUN_00120EE0
s32 func_00120ee0(void *arg0)
{
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38)) == 2;
}
// FUN_00120F00
void func_00120f00(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x14) = 1;
}
// FUN_00120F20
void func_00120f20(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x10) = 1;
}
// FUN_00120F40
void func_00120f40(u8 *arg0, s64 arg1)
{
    SVec2_0012 sp8;
    u8 *temp_3;
    *(s64 *)&sp8 = arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    *(SVec2_0012 *)(temp_3 + 0x1C) = sp8;
}
// FUN_00120F70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120f70);
// FUN_00121170
void func_00121170(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}



// FUN_001211A0
s32 func_001211a0(void)
{
    return 0;
}

// FUN_00121AF0
s32 func_00121af0(void)
{
    func_00103b00();
    return 0;
}
// FUN_00121B20
void func_00121b20(void) {
    func_00103a60();
    func_00451de0(&iGpffff9c58, 0xF, 0, 0, (void *)func_00121af0, 0, 0);
}

// FUN_00121B70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121b70);
// FUN_00121DB0
void func_00121db0(void)
{
    jtbl_008873EC[0]((void *)iGpffffb1cc);
    iGpffffb1cc = 0;
}
// FUN_00121DE0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121de0);
// FUN_00121F20
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121f20);
// FUN_001221A0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001221a0);
// FUN_001223D0
s32 func_001223d0(void) {
    u8 *p;
    s32 x;

    p = func_00460990();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    *(void **)(p + 8) = (void *)func_001221a0;
    *(s32 *)(p + 0x10) = x;
    func_00460ac0(D_00796340, p);
    return 0;
}

// FUN_00122720
/* The case values come from decoding the jump table at 0x007466C0 with
   tools/jtbl.py: entry 0 returns 1, entries 1/2/4/5 share one body returning
   0, entry 3 returns 2, and anything >= 6 falls through to the default 1.
   The labels are declared in that object order because b210 lays case bodies
   out in declaration order. */
s32 func_00122720(void) {
    s32 *state;

    state = (s32 *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state[0]) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 4:
    case 5:
        return 0;
    case 3:
        return 2;
    }
    return 1;
}

// FUN_001227A0
s32 func_001227a0(void)
{
    if (iGpffffb1cc == 0) {
        return 1;
    }
    return *(s32 *)(iGpffffb1cc + 4);
}
// FUN_001227D0
void func_001227d0(void)
{
    if (iGpffffb1cc != 0) {
        *(s32 *)(iGpffffb1cc + 0x14) = 1;
    }
}
// FUN_001227F0
s32 func_001227f0(void)
{
    s32 result;
    u8 *temp_3;
    result = 1;
    temp_3 = D_007242CC;
    if (temp_3 == NULL)
        return 1;
    if (*(s32 *)(temp_3 + 0x14) != 0)
        result = 0;
    return result;
}
// FUN_00122820
void func_00122820(s32 arg0, s32 arg1)
{
    func_00264d90(0, arg0, arg1, D_00796670);
}



// FUN_00122860
void func_00122860(s32 arg0, s32 arg1)
{
    func_00267570(0, arg0, arg1, D_00796670);
}



// FUN_001228C0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001228c0);
// FUN_00122A10
void func_00122a10(void *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    D_007242CC = 0;
}



// FUN_00122A40
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00122a40);
// FUN_001236E0
s32 func_001236e0(void) {
    u8 *p;
    u8 *q;

    p = func_00460990();
    q = D_007242CC;
    *(void **)(p + 8) = (void *)func_00122a40;
    *(u8 **)(p + 0x10) = q;
    func_00460ac0(D_00795F50, p);
    return 0;
}

// FUN_00123730
s32 func_00123730(s32 arg0)
{
    s32 temp_2;
    s32 temp_2_2;
    func_0044ea90(D_005E5170, 0x179);
    temp_2_2 = (s32)D_008873F4[0](1, 0x114, 0x40000);
    if (temp_2_2 == 0)
        return 0;
    iGpffffb1dc = (u8 *)temp_2_2;
    temp_2 = func_00451fc0(arg0, D_005E5180, 0x96, 0, 0,
                           (void *)func_001228c0,
                           (void *)func_00122a10, (u8 *)temp_2_2);
    func_00451fc0(temp_2, D_005E5190, 0x97, 0, 0,
                  (void *)func_001236e0, (void *)0, (u8 *)0);
    return temp_2;
}
// FUN_00123810
s16 func_00123810(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 6);
    }
    return var_2;
}



// FUN_00123830
s16 func_00123830(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 4);
    }
    return var_2;
}



/* measured: the named first-field load plus -O1 reproduce retail's argument setup order; exact match nd 0 (obj 104B/window 112B). */
// FUN_00123850
/* measured: opens optimization_level 1 to keep the +6 store and +4 load before the call conversion (nd 0). */
#pragma optimization_level 1
void func_00123850(void) {
    u8 *p;
    s32 t;
    s16 first;

    p = D_007242CC;
    if (p != NULL) {
        *(s16 *)(p + 4) = (s16)func_001060b0();
        t = func_001060c0() & 0xFF;
        *(s16 *)(p + 6) = (s16)t;
        first = *(s16 *)(p + 4);
        *(s16 *)(p + 8) = (s8)func_00110850(first, (s16)t);
    }
}
/* measured: closes the optimization_level bracket at the file's -O2 baseline (nd 0). */
#pragma optimization_level 2

// FUN_001238C0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001238c0);
// FUN_00123A10
void func_00123a10(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        *(s32 *)(p + 0x18) = 1;
        if (func_0015a160() != 0) {
            goto set1;
        }
        if (func_0028b650() != 0) {
            goto set1;
        }
        *(s32 *)(p + 0x1C) = 0;
        return;
set1:
        *(s32 *)(p + 0x1C) = 1;
    }
}

// FUN_00123A80
void func_00123a80(void)
{
    u8 *temp_3;

    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        *(s32 *)(temp_3 + 0x14) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
    }
}



// FUN_00123AA0
void func_00123aa0(s16 arg0) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        *(s16 *)(p + 0xA) = *(s16 *)(p + 8);
        *(s16 *)(p + 8) = arg0;
    }
}
// FUN_00123AC0
void func_00123ac0(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        *(s16 *)(p + 8) = *(s16 *)(p + 0xA);
    }
}
// FUN_00123AE0
s8 func_00123ae0(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        return *(s8 *)(p + 8);
    }
    return -1;
}
// FUN_00123B10
s16 func_00123b10(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        return *(s16 *)(p + 4);
    }
    return -1;
}
// FUN_00123B40
s16 func_00123b40(void) {
    u8 *p;

    p = D_007242CC;
    if (p != NULL) {
        return *(s16 *)(p + 6);
    }
    return -1;
}
// FUN_00123B70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123b70);
// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00123D80
s32 func_00123d80(void)
{
    s32 temp_2;
    func_0044ea90(D_005E51A0, 0x84);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        temp_2 = 0;
    } else {
        temp_2 = func_00451fc0(0, D_005E51B0, 0xF, 0, 0,
                               (void *)func_00123b70,
                               (void *)func_00123d50, (u8 *)temp_2);
        if (temp_2 == 0)
            temp_2 = 0;
    }
    iGpffffb1e0 = temp_2;
    return 1;
}
// FUN_00123E30
s32 func_00123e30(void)
{
    if (func_004522d0(iGpffffb1e0) == 3) {
        iGpffffb1e0 = 0;
        return 1;
    }
    return 0;
}

// FUN_00123E80
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123e80);
// FUN_00124210
void func_00124210(u8 *arg0)
{
    func_0046a340(*(s32 *)(arg0 + 0x38));
}
// FUN_00124350
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124350);
// FUN_001246D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001246d0);
// FUN_00124830
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124830);
// FUN_00124970
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124970);
// FUN_00124BB0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124bb0);
// FUN_00124F70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124f70);
// FUN_00125E80
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00125e80);
// FUN_00126090
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00126090);
// FUN_001265A0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);
// FUN_0012AA70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012aa70);
// FUN_0012B660
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012b660);
// FUN_0012B760
void func_0012b760(void)
{
    u8 *temp_2;
    func_0044ea90(D_005E5548, 0x728);
    temp_2 = D_008873F4[0](1, 0x90, 0x40000);
    if (temp_2 == NULL)
        func_0046d730(D_005E5548, 0x729);
    *(s32 *)(temp_2 + 0x18) = 0;
    func_00451de0(D_005E5720, 0xF, 0, 0,
                  (void *)func_0012aa70, (void *)func_0012b660, temp_2);
}
// FUN_0012B810
s32 func_0012b810(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(func_00452560(arg0));
    if (temp_2->field_18 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_18;
}



// FUN_0012B890
s32 func_0012b890(void)
{
    s32 sp2C;
    u8 *temp_2;
    s32 temp_3;
    temp_2 = (u8 *)func_00452560();
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_2 + 0) = 1;
    case 1:
        *(s32 *)(temp_2 + 0) = 2;
    case 2:
        *(s32 *)(temp_2 + 8) = func_004669d0(*(s32 *)(temp_2 + 4), &sp2C, 0);
        if (sp2C != 0) {
            *(s32 *)(temp_2 + 0) = 3;
            *(s32 *)(temp_2 + 4) = 0;
        }
        break;
    case 3:
        break;
    }
    return 0;
}
// FUN_0012B940
void func_0012b940(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_003ef3a0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_0012B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012b9a0);
// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(func_00452560(arg0));
    if (temp_2->field_4 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_4;
}

// FUN_0012C220
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012c220);
// FUN_0012C410
void func_0012c410(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    func_001029a0(1, 0, 0, 5);
}
// FUN_0012C460
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012c460);
// FUN_0012D410
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012d410);
// FUN_0012D630
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012d630);
// FUN_0012DB80
s32 func_0012db80(u8 *arg0, s32 arg1)
{
    if (arg1 != *(s32 *)(arg0 + 0x10)) {
        func_0045af60(0, 1, 0, 0);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x10);
        *(s32 *)(arg0 + 0x10) = arg1;
        *(s32 *)(arg0 + 0x18) = -1;
        func_0012dea0(arg0, 2);
    }
    return 1;
}
// FUN_0012DC00
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012dc00);
// FUN_0012DEA0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012dea0);
// FUN_0012E150
void func_0012e150(s32 arg0)
{
    s32 temp_4;
    s32 var_17;
    u8 *temp_3;
    u8 *temp_16;

    var_17 = 0;
    while (var_17 < 0x15) {
        temp_3 = (u8 *)(arg0 + (var_17 * 4));
        temp_16 = temp_3 + 0x3C;
        temp_4 = *(s32 *)temp_16;
        if (temp_4 != 0) {
            func_0046d280(temp_4);
            *(s32 *)temp_16 = 0;
        }
        var_17 += 1;
    }
}
// FUN_0012E1D0
s32 func_0012e1d0(u8 *arg0)
{
    s32 var_16 = 1;
    s32 var_5 = 0;
    s32 temp_3 = *(s16 *)(arg0 + 0xC);

    while (var_5 < 0xB) {
        if (temp_3 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
// FUN_0012E250
s32 func_0012e250(u8 *arg0)
{
    s32 temp_3 = *(s32 *)(arg0 + 0x18);
    s32 var_16 = 1;
    s32 var_5;
    s32 temp_4;

    if (temp_3 == var_16) {
        goto block_early;
    }
    if (temp_3 != 2) {
        goto block_loop;
    }
block_early:
    return 1;
block_loop:
    var_5 = 0;
    temp_4 = *(s16 *)(arg0 + 0xC);
    while (var_5 < 0xB) {
        if (temp_4 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
// FUN_0012E2F0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e2f0);
// FUN_0012E7C0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e7c0);
// FUN_0012E8B0
s32 func_0012e8b0(u8 *arg0)
{
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0x18);
    switch (temp_3) {
    case 0:
        *(s32 *)(arg0 + 0x18) = temp_3 + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0012E900
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e900);
// FUN_0012E9D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e9d0);
// FUN_0012FDF0
void func_0012fdf0(u8 *arg0)
{
    s16 temp_3;
    s32 var_16;
    s32 var_16_2;
    u8 *temp_2;

    temp_3 = *(s16 *)(arg0 + 0x1E);
    if (temp_3 < 0x64) {
        temp_3 += 1;
        *(s16 *)(arg0 + 0x1E) = temp_3;
    }
    for (var_16 = 0; var_16 < 0xC; var_16++) {
        temp_2 = arg0 + (var_16 * 0x30);
        func_001437b0(temp_2 + 0x1878, *(s16 *)(arg0 + 0x1E), 0);
    }
    for (var_16_2 = 0; var_16_2 < 0x54; var_16_2++) {
        temp_2 = arg0 + (var_16_2 * 0x14);
        func_0034f5d0(temp_2 + 0xC48);
    }
}
/* measured: opt_common_subs off preserves the retail base+offset accesses in
   the two-record callback loop. */
#pragma opt_common_subs off
// FUN_0012FEB0
void func_0012feb0(u8 *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = arg0 + i * 0x30 + 0x1AB8;
        func_001437b0(p, *(s16 *)(arg0 + 0x20), 0);
    }
}
/* measured: opt_common_subs on closes the callback-loop probe. */
#pragma opt_common_subs on
// FUN_0012FF40
s32 func_0012ff40(s32 arg0, s32 arg1, s16 arg2)
{
    u8 *p;

    p = (u8 *)(arg1 * 2) + (u32)arg0;
    *(s16 *)(p + 0x28) = *(s16 *)(p + 0x22);
    *(s16 *)(p + 0x22) = arg2;
    return 1;
}
// FUN_0012FF60
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012ff60);