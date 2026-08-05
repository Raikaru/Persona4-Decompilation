#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit tnEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef void (*TNFunc)(s32, s32);

typedef struct {
    u8 pad0[0x30];
    u8 flag30;
    u8 pad1;
    u8 flag32;
} TnFlags;
s32 func_00464100(u8 *arg0, s32 arg1);
u8 *func_003ef2e0(u8 *arg0);
void func_0046d730(const char *file, s32 line);
s32 func_004ab2c0(void *arg0);
s32 func_004ab800(void *arg0);
void func_00488d70(void);
s32 func_004b0f70(void *arg0);
s32 func_004b0fa0(void *arg0);
s32 func_004aed70(void *arg0);
void func_003f6440(s32 arg0, s32 arg1);
void func_004b1600(void);
void func_004a7830(void);
void *func_004571a0(void);
void *func_004571c0(void);
void func_003c38b0(void *arg0, void *arg1);
void func_003e9cb0(void *arg0, void *arg1, s32 arg2);

extern char D_00713270[];
extern u8 D_00887300_abs[];
extern s32 D_00922CC0[];
extern f32 D_00922CA0[];
extern f32 D_00922CB0[];
extern f32 D_00922C60[];
extern s32 D_00922D10[];

static char sStr_7641E8[8];
static u8 sTbl_7641F0[8];
static void *sPtr_764C48;
static void *sCb_764C4C;

// FUN_00481300
s32 func_00481300(u16 arg0) {
    if (!((u16)arg0 < 0x16)) {
        func_0046d730(D_00713270, 0x27);
    }
    return D_00922D10[(u16)arg0];
}



// FUN_00481360
void func_00481360(u8 *arg0)
{
    func_00464100(arg0, 1);
}



// FUN_00481390
void func_00481390(u8 *arg0)
{
    u8 *temp_2 = func_003ef2e0((u8 *)func_00464100(arg0, 1));
    s32 temp_4 = (*(s32 *)(temp_2 + 0x50) & ~0xFF) | 2;

    *(s32 *)(temp_2 + 0x50) = temp_4;
    *(s32 *)(temp_2 + 0x50) = (temp_4 & 0xFFFF00FF) | 0x1100;
}

// FUN_004813F0
void func_004813f0(void) {
    if (sCb_764C4C != NULL) {
        ((void (*)(s32, s32))sCb_764C4C)(0, 0);
    }
}

// FUN_00481430
void func_00481430(void *arg0) {
    sCb_764C4C = arg0;
}

// FUN_00481440
void func_00481440(void *arg0) {
    sPtr_764C48 = arg0;
}

// FUN_00481450
s32 func_00481450(void) {
    return (s32)sPtr_764C48;
}

// FUN_00481460
s32 func_00481460(u16 arg0) {
    s32 idx;
    if (!((u16)arg0 < 0x7)) {
        func_0046d730(D_00713270, 0xCD);
    }
    idx = (u32)sTbl_7641F0[(u16)arg0] * 4;
    return *(s32 *)(idx + (u32)sPtr_764C48 + 0x1C);
}

// FUN_004814D0
s32 func_004814d0(u16 arg0) {
    s32 idx;
    if (!((u16)arg0 < 0x7)) {
        func_0046d730(D_00713270, 0xD2);
    }
    idx = (u32)sTbl_7641F0[(u16)arg0] * 4;
    return *(s32 *)(idx + (u32)sPtr_764C48 + 0x38);
}

// FUN_00481540
s32 func_00481540(u16 arg0) {
    if (!((u16)arg0 < 0x7)) {
        func_0046d730(D_00713270, 0xD7);
    }
    return ((u32 *)sPtr_764C48)[sTbl_7641F0[(u16)arg0]];
}

// FUN_004815B0
void func_004815b0(void *arg0) {
    u8 *obj;
    TNFunc *tbl;
    if (*(u16 *)arg0 & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    obj = *(u8 **)((u8 *)arg0 + 0x10);
    (*(void (**)(u8 *))(obj + 0x48))(obj);
    if (!(*(u16 *)arg0 & 1)) {
        (*tbl)(6, 1);
    }
}
// FUN_00481660
void func_00481660(void *arg0) {
    TNFunc *tbl = (TNFunc *)D_00887300_abs;
    (*tbl)(6, 0);
    func_004ab2c0(arg0);
    (*tbl)(6, 1);
}

// FUN_004816D0
void func_004816d0(void *arg0) {
    TNFunc *tbl = (TNFunc *)D_00887300_abs;
    (*tbl)(6, 0);
    func_004ab800(arg0);
    (*tbl)(6, 1);
}

// FUN_00481740
void func_00481740(void *arg0) {
    u8 *obj = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x58) + 0x20);
    TNFunc *tbl;
    TNFunc *tbl2;
    if (((TnFlags *)arg0)->flag32 & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    if (*(s32 *)(obj + 0x54) == 0) {
        (*tbl)(8, 1);
        func_003f6440(3, 0x70003);
    }
    tbl2 = (TNFunc *)D_00887300_abs;
    (*tbl2)(0x14, 2);
    func_004aed70(arg0);
    (*tbl2)(0x14, 1);
    if (*(s32 *)(obj + 0x54) == 0) {
        (*tbl)(8, 0);
        func_003f6440(3, 0x717FB);
    }
    if (!(*(u8 *)((u8 *)arg0 + 0x32) & 1)) {
        (*tbl)(6, 1);
    }
}

// FUN_004818A0
void func_004818a0(void) {
    func_00488d70();
}

// FUN_004818C0
void func_004818c0(void *arg0) {
    TNFunc *tbl;
    if (((TnFlags *)arg0)->flag30 & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    func_004b0f70(arg0);
    func_004b0fa0(arg0);
    if (!(*(u8 *)((u8 *)arg0 + 0x30) & 1)) {
        (*tbl)(6, 1);
    }
}

// FUN_00481980
s32 func_00481980(void) {
    func_004b1600();
    func_004a7830();
    if (D_00922CC0[0] != 0) {
        func_003c38b0(func_004571a0(), (void *)D_00922CA0);
        func_003c38b0(func_004571c0(), (void *)D_00922CB0);
        func_003e9cb0(*(void **)((u8 *)func_004571c0() + 4), (void *)D_00922C60, 0);
        D_00922CC0[0] = 0;
    }
    return 0;
}

// FUN_00481A20
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481a20);
