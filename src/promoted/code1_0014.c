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

// FUN_001400F0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001400f0);
// FUN_00141CF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00141cf0);
// FUN_00141D10
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00141d10);
// FUN_00141D80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00141d80);
// FUN_00142090
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142090);
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

// FUN_001422B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001422b0);
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

// FUN_001423C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001423c0);
// FUN_001424B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001424b0);
// FUN_001427C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001427c0);
// FUN_00142BF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142bf0);
// FUN_00142D80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142d80);
// FUN_00142F20
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142f20);
// FUN_001437B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001437b0);
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

// FUN_001441E0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001441e0);
// FUN_00144AC0
void func_00144ac0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00144AF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144af0);
// FUN_00144B80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144b80);
// FUN_00144C90
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144c90);
// FUN_00144E10
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144e10);
// FUN_00144ED0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144ed0);
// FUN_00144F60
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00144f60);
// FUN_00145080
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145080);
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

// FUN_001453A0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001453a0);
// FUN_00145480
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145480);
// FUN_00145510
void func_00145510(s32 arg0, s32 arg1) {
    func_00145540(arg0, 0, arg1);
}



// FUN_00145540
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145540);
// FUN_00145690
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145690);
// FUN_00145780
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145780);
// FUN_001459B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001459b0);
// FUN_00145AC0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145ac0);
// FUN_00145BA0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145ba0);
// FUN_00145C80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145c80);
// FUN_00145D60
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145d60);
// FUN_00145E90
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145e90);
// FUN_00145FC0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00145fc0);
// FUN_00146080
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146080);
// FUN_00146140
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146140);
// FUN_00146200
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146200);
// FUN_001462C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001462c0);
// FUN_00146380
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146380);
// FUN_00146440
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146440);
// FUN_00146630
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146630);
// FUN_00146A10
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146a10);
// FUN_00147530
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147530);
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

// FUN_00147620
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147620);
// FUN_00147640
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147640);
// FUN_00147830
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147830);
// FUN_00147910
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147910);
// FUN_00147AE0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147ae0);
// FUN_00147BB0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147bb0);
// FUN_00147D80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147d80);
// FUN_00147E60
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147e60);
// FUN_00147F30
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00147f30);
// FUN_00148000
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00148000);
// FUN_00148140
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00148140);
// FUN_00148280
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00148280);
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



// FUN_00149690
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149690);
// FUN_001496C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001496c0);
// FUN_00149CA0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149ca0);
// FUN_00149CE0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149ce0);
// FUN_00149D20
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149d20);
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

// FUN_00149EA0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149ea0);

// FUN_0014A000
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a000);

// FUN_0014A160
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a160);
// FUN_0014A190
s32 func_0014a190(s32 arg0, s32 arg1) {
    if (func_0014a230(arg0, arg1) == 1) {
        return 1;
    }
    return func_0014a2a0(arg0, arg1) == 1;
}
/* measured: closes the scoped opt_rebuildconditionals probe. */
#pragma opt_rebuildconditionals on

// FUN_0014A200
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a200);
// FUN_0014A230
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a230);
// FUN_0014A270
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a270);
// FUN_0014A2A0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a2a0);
// FUN_0014A2F0
void func_0014a2f0(s32 arg0)
{
    *(s32 *)(iGpffff9db0 + 0x18) = arg0;
}

// FUN_0014B1E0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b1e0);
// FUN_0014B450
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b450);
// FUN_0014B490
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b490);
// FUN_0014B4D0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b4d0);
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

// FUN_0014B590
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b590);
// FUN_0014B780
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b780);
// FUN_0014B840
void func_0014b840(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014BD90
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014bd90);
// FUN_0014BE50
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014be50);
// FUN_0014C540
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c540);
// FUN_0014C780
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c780);
// FUN_0014C850
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c850);
// FUN_0014C920
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c920);
// FUN_0014C960
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c960);
// FUN_0014CEF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014cef0);
// FUN_0014CFD0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014cfd0);
// FUN_0014D290
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014d290);
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

// FUN_0014DCE0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014dce0);
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



// FUN_0014DD80
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014dd80);
// FUN_0014DEF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014def0);
// FUN_0014E2A0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e2a0);
// FUN_0014E540
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e540);
// FUN_0014E5E0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e5e0);
// FUN_0014E710
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e710);
// FUN_0014E740
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e740);
// FUN_0014E880
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e880);
// FUN_0014E8C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e8c0);
// FUN_0014E8F0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e8f0);
// FUN_0014E920
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e920);
// FUN_0014E950
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e950);
// FUN_0014EC20
void func_0014ec20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EC50
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014ec50);
// FUN_0014EEC0
s32 func_0014eec0(void) {
    return D_007642F0;
}
