#include "include_asm.h"
#include "type.h"

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void func_00264d90();
extern s32 D_00796670[];

extern void func_00267570();

extern u8 *D_007242CC;
extern s32 iGpffffb1e0;

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

// FUN_00121B20
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00121b20);

// FUN_001223D0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001223d0);

// FUN_00122720
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00122720);

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



// FUN_00122A10
void func_00122a10(void *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    D_007242CC = 0;
}



// FUN_001236E0
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001236e0);

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



// FUN_00123850
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123850);

// FUN_00123A10
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00123a10);

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



// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
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
