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
extern s32 iGpffff9ca8;
extern void func_00103a60(void);
extern void func_00451de0(void *list, s32 count, s32 a, s32 b, void *fn, s32 c, s32 d);
extern void func_00121af0(void);
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



extern void func_003ef3a0(void *arg0);

// FUN_001203A0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001203a0);
// FUN_00120AE0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120ae0);
// FUN_00120EE0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120ee0);
// FUN_00120F00
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120f00);
// FUN_00120F20
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120f20);
// FUN_00120F40
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00120f40);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121af0);
// FUN_00121B20
void func_00121b20(void) {
    func_00103a60();
    func_00451de0(&iGpffff9ca8, 0xF, 0, 0, (void *)func_00121af0, 0, 0);
}

// FUN_00121B70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121b70);
// FUN_00121DB0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121db0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001227a0);
// FUN_001227D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001227d0);
// FUN_001227F0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001227f0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123730);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123aa0);
// FUN_00123AC0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123ac0);
// FUN_00123AE0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123ae0);
// FUN_00123B10
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123b10);
// FUN_00123B40
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123b40);
// FUN_00123B70
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123b70);
// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00123D80
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123d80);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124210);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012b760);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012b890);
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
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012c410);
// FUN_0012C460
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012c460);
// FUN_0012D410
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012d410);
// FUN_0012D630
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012d630);
// FUN_0012DB80
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012db80);
// FUN_0012DC00
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012dc00);
// FUN_0012DEA0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012dea0);
// FUN_0012E150
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e150);
// FUN_0012E1D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e1d0);
// FUN_0012E250
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e250);
// FUN_0012E2F0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e2f0);
// FUN_0012E7C0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e7c0);
// FUN_0012E8B0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e8b0);
// FUN_0012E900
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e900);
// FUN_0012E9D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e9d0);
// FUN_0012FDF0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012fdf0);
// FUN_0012FEB0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012feb0);
// FUN_0012FF40
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012ff40);
// FUN_0012FF60
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012ff60);