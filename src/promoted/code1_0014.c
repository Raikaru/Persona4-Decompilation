#include "include_asm.h"
#include "type.h"

extern s32 func_0014a230(s32 arg0, s32 arg1);
extern s32 func_0014a2a0(s32 arg0, s32 arg1);
extern u8 * iGpffff9db0;
extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 D_00762EA0;

extern s32 func_00145540(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_007642E4;
extern u8 D_005EFB10[];
extern void func_00148280(void);
extern void func_0017ccc0(u8 *arg0);
extern u8 *func_00451fc0(u8 *a, void *b, s32 c, s32 d, s32 e, void *f, void *g, void *h);

typedef struct { f32 x, y, z; } SVec3;

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;



extern u8 *func_00460990(void);
extern void func_00460ac0(void *arg0, u8 *arg1);
extern void func_0014d290(u8 *arg0, u8 *arg1);

extern s32 func_0034c210(void);

extern u8 *func_001452b0(s32 arg0);
extern u8 *resrcMngGetListHead(u8 *resManager, u8 resType);
extern void func_00153b20(s32 arg0, s32 arg1);

extern void func_00153b60(s32 arg0, s32 arg1);

extern void func_00153b90(s32 arg0, s32 arg1);

extern void func_00153bd0(s32 arg0, s32 arg1);

// FUN_00142130
void func_00142130(u8 *arg0) {
    *(f32 *)(arg0 + 0x250) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0x42C80000;
    *(s32 *)(arg0 + 0x220) = 0x42C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(s32 *)(arg0 + 0x708) = 0xC3160000;
    *(s32 *)(arg0 + 0x6D8) = 0xC2C80000;
    *(s32 *)(arg0 + 0x738) = 0xC2C80000;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_001421B0
void func_001421b0(u8 *arg0) {
    *(s32 *)(arg0 + 0x250) = 0xC3160000;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0xC2C80000;
    *(s32 *)(arg0 + 0x220) = 0xC2C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(f32 *)(arg0 + 0x708) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x6D8) = 0x42C80000;
    *(s32 *)(arg0 + 0x738) = 0x42C80000;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_00142230
/* measured: optimization level 1 plus base-before-value declaration order
   keeps the retail t0/t1/a3 live ranges and loop arithmetic. */
#pragma optimization_level 1
void func_00142230(u8 *arg0) {
    extern s32 iGpffff9cd8;
    extern u8 D_005EF5A0[];
    s32 i;
    u8 *base;
    s32 value;
    u8 *table;
    u8 *temp_3;
    u8 *temp_5;
    i = 0;
    base = (u8 *)&iGpffff9cd8;
    table = D_005EF5A0;
    while (i < 5) {
        value = *(s16 *)(arg0 + (*(u8 *)(base + i) * 2) + 0x187E) - 1;
        temp_5 = table + i * 0x28 + value * 8;
        temp_3 = arg0 + i * 0x30;
        *(f32 *)(temp_3 + 0x588) = *(f32 *)(temp_5 + 0);
        *(f32 *)(temp_3 + 0x58C) = *(f32 *)(temp_5 + 4);
        i++;
    }
}
/* measured: closes the scoped optimization-level-1 probe. */
#pragma optimization_level 2

// FUN_00142340
s32 func_00142340(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x6C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00143B70
void func_00143b70(void)
{
}

// FUN_00143B80
void func_00143b80(void)
{
}

// FUN_00143B90
void func_00143b90(void)
{
}

// FUN_00144AC0
void func_00144ac0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00145250
s32 func_00145250(void) {
    return D_00762EA0;
}



// FUN_001452B0
u8 *func_001452b0(s32 arg0)
{
    u8 *resManager;

    resManager = *(u8 **)(iGpffff9db0 + 8);
    if (resManager == NULL) {
        return NULL;
    }
    return resrcMngGetListHead(resManager, (u8)(arg0 & 0xFF));
}

// FUN_00145510
void func_00145510(s32 arg0, s32 arg1) {
    func_00145540(arg0, 0, arg1);
}



// FUN_001475C0
/* Ported from P3FES resrcMngGetTotalResInList: P4 uses a 0x16-entry list
   table and the list link remains at offset 0x138. */
u32 func_001475c0(u8 *resLists, u8 resType)
{
    u32 total;
    u8 *currRes;

    total = 0;
    if (resType >= 0x16) {
        return total;
    }
    currRes = *(u8 **)(resLists + resType * 4);
    while (currRes != NULL) {
        total++;
        currRes = *(u8 **)(currRes + 0x138);
    }
    return total;
}

// FUN_00149620
u8 *func_00149620(void) {
    u8 *ctx;
    u8 *o;

    o = func_00451fc0(ctx, D_005EFB10, 0xC7, 0, 0, (void *)func_00148280, NULL, NULL);
    func_0017ccc0(o);
    return o;
}

// FUN_00149680
void func_00149680(s32 arg0) {
    D_007642E4 = arg0;
}



// FUN_00149D60
void func_00149d60(s32 arg0)
{
    func_001452b0(12);
    func_00153b20(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149DB0
void func_00149db0(s32 arg0)
{
    func_001452b0(12);
    func_00153b60(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E00
void func_00149e00(s32 arg0)
{
    func_001452b0(12);
    func_00153b90(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E50
void func_00149e50(s32 arg0)
{
    func_001452b0(12);
    func_00153bd0(*(s32 *)(D_00762EA0 + 32), arg0);
}

/* measured: opt_rebuildconditionals off reproduces retail's xori/sltiu
   boolean tail and branch layout; scoped to this function. */
#pragma opt_rebuildconditionals off
// FUN_0014A190
s32 func_0014a190(s32 arg0, s32 arg1) {
    if (func_0014a230(arg0, arg1) == 1) {
        return 1;
    }
    return func_0014a2a0(arg0, arg1) == 1;
}
/* measured: closes the scoped opt_rebuildconditionals probe. */
#pragma opt_rebuildconditionals on

// FUN_0014A2F0
void func_0014a2f0(s32 arg0)
{
    *(s32 *)(iGpffff9db0 + 0x18) = arg0;
}

// FUN_0014B510
s32 func_0014b510(s32 arg0)
{
    s32 var_17;
    s32 temp_16;
    u8 *var_2;

    var_17 = 0;
    temp_16 = arg0 & 0xFFFF;
    var_2 = func_001452b0(temp_16);
    while (var_2 != NULL) {
        if ((*(u16 *)var_2 & 0x3FF) == var_17) {
            var_17 += 1;
            var_2 = func_001452b0(temp_16);
        } else {
            var_2 = *(u8 **)(var_2 + 0x138);
        }
    }
    return var_17 & 0xFFFF;
}

// FUN_0014B840
void func_0014b840(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014D470
s32 func_0014d470(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014d290;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x110), obj);
    return 0;
}

// FUN_0014D4E0
void func_0014d4e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014D7D0
void func_0014d7d0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014D9E0
void func_0014d9e0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014DCD0
void func_0014dcd0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44) = arg1;
}

// FUN_0014DD10
void func_0014dd10(u8 *arg0, u8 *arg1) {
    f32 sp20[4];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(SVec3 *)(temp_16 + 0x30) = *(SVec3 *)arg1;
    RwEngineGetMatrixTolerances(&sp20[0]);
    RwMatrixOptimize(temp_16, &sp20[0]);
    RwMatrixUpdate(temp_16);
}



// FUN_0014EC20
void func_0014ec20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EEC0
s32 func_0014eec0(void) {
    return D_007642F0;
}
