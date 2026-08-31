#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit tnEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef void (*TNFunc)(s32, s32);
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} TnV3d;

typedef struct {
    TnV3d right;
    u32 flags;
    TnV3d up;
    u32 pad1;
    TnV3d at;
    u32 pad2;
    TnV3d pos;
    u32 pad3;
} TnMatrix;

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
void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
u8 *func_00454a60(const void *arg0, s32 arg1);
void func_00454bd0(void *arg0);
void func_00456150(void *arg0);
void func_00442088(void *arg0, const void *arg1, s32 arg2);
u8 *func_003ef740(void *arg0, s32 arg1);
void func_004bd130(s32 arg0, s32 arg1);
void func_004abb60(void);
void func_004a77b0(void);
void func_004b3180(void *arg0);
s32 func_00451de0(void *arg0, void *arg1, s32 arg2, s32 arg3,
                  void *arg4, void *arg5, void *arg6);

extern char D_00713270[];
extern char D_00713280[];
extern char D_007132A0[];
extern char D_007132B8[];
extern u_long128 D_007132D0;
extern u_long128 D_007132E0;
extern u_long128 D_00922C60[4];
extern f32 D_00922CA0[];
extern f32 D_00922CB0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CD0[];
extern s32 D_00922CD4[];
extern s32 D_00922CD8[];
extern s32 D_00922CDC[];
extern s32 D_00922CE0[];
extern s32 D_00922CE4[];
extern s32 D_00922CE8[];
extern s32 D_00922CF0[];
extern s32 D_00922CF4[];
extern s32 D_00922CF8[];
extern s32 D_00922D00[];
extern s32 D_00922D04[];
extern s32 D_00922D08[];
extern u8 D_00887300_abs[];
extern s32 D_00922CC0[];
extern u8 *D_00922D10[];

static char sStr_7641E8[8];
static u8 sTbl_7641F0[8];
static void *sPtr_764C48;
static void *sCb_764C4C;
static s32 sState_764C50;


// FUN_00481300
s32 func_00481300(u16 arg0) {
    if (!((u16)arg0 < 0x16)) {
        func_0046d730(D_00713270, 0x27);
    }
    return (s32)D_00922D10[(u16)arg0];
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
void func_00481a20(void *arg0)
{
    TnMatrix matrix;
    u_long128 color0;
    u_long128 color1;
    u8 buffer[0x100];
    u32 index;
    u8 *handle;
    u8 **slot;
    u8 *obj;
    u8 *slotObj;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    u_long128 *matrixSrc;
    u_long128 *matrixDst;
    s32 copyCount;

    color0 = D_007132D0;
    color1 = D_007132E0;
    func_00440b68(sStr_7641E8, D_00713270, 0x35);
    handle = func_00454a60(D_00713280, 1);
    func_00456150(handle);
    index = 0;
    while (index < 0x16)
    {
        func_00442088(buffer, D_007132A0, index + 1);
        slot = &D_00922D10[index];
        obj = func_003ef740(buffer, 0);
        *slot = obj;
        *(s32 *)(obj + 0x50) = (*(s32 *)(obj + 0x50) & ~0xFF) | 2;
        slotObj = *slot;
        *(s32 *)(slotObj + 0x50) = (*(s32 *)(slotObj + 0x50) & 0xFFFF00FF) | 0x1100;
        index++;
    }
    func_00454bd0(handle);
    func_004bd130(0, 0x12345678);
    D_00922CC0[0] = 1;
    temp_f3 = ((f32 *)&color0)[0];
    temp_f2 = ((f32 *)&color0)[1];
    temp_f1 = ((f32 *)&color0)[2];
    temp_f0 = ((f32 *)&color0)[3];
    D_00922CA0[0] = temp_f3;
    D_00922CA4[0] = temp_f2;
    D_00922CA8[0] = temp_f1;
    D_00922CAC[0] = temp_f0;
    D_00922CB0[0] = temp_f3;
    D_00922CB4[0] = temp_f2;
    D_00922CB8[0] = temp_f1;
    D_00922CBC[0] = temp_f0;

    temp_f4 = ((f32 *)&color1)[1];
    temp_f12 = ((f32 *)&color1)[2];
    temp_f3 = ((f32 *)&color1)[3];
    temp_f11 = ((f32 *)&color1)[0];
    temp_f0 = 2.0f /
        ((temp_f11 * temp_f11) +
         (temp_f4 * temp_f4) +
         (temp_f12 * temp_f12) +
         (temp_f3 * temp_f3));
    temp_f2 = temp_f11 * temp_f0;
    temp_f1 = temp_f4 * temp_f0;
    temp_f0_2 = temp_f12 * temp_f0;
    temp_f10 = temp_f2 * temp_f3;
    temp_f9 = temp_f1 * temp_f3;
    temp_f8 = temp_f0_2 * temp_f3;
    temp_f7 = temp_f11 * temp_f2;
    temp_f6 = temp_f4 * temp_f1;
    temp_f5 = temp_f12 * temp_f0_2;
    temp_f4 = temp_f4 * temp_f0_2;
    temp_f3 = temp_f12 * temp_f2;
    temp_f2_2 = temp_f11 * temp_f1;
    matrix.right.x = 1.0f - (temp_f6 + temp_f5);
    matrix.right.y = temp_f2_2 + temp_f8;
    matrix.right.z = temp_f3 - temp_f9;
    matrix.up.x = temp_f2_2 - temp_f8;
    matrix.up.y = 1.0f - (temp_f5 + temp_f7);
    matrix.up.z = temp_f4 + temp_f10;
    matrix.at.x = temp_f3 + temp_f9;
    matrix.at.y = temp_f4 - temp_f10;
    matrix.at.z = 1.0f - (temp_f7 + temp_f6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;

    matrixSrc = (u_long128 *)&matrix;
    matrixDst = D_00922C60;
    copyCount = 4;
    do
    {
        u_long128 matrixRow = *matrixSrc;
        matrixSrc++;
        copyCount--;
        *matrixDst = matrixRow;
        matrixDst++;
    }
    while (copyCount > 0);
    sState_764C50 = 0;
    D_00922CF8[0] = 0x3F800000;
    D_00922CE4[0] = 0x3F800000;
    D_00922CD0[0] = 0x3F800000;
    D_00922CE0[0] = 0;
    D_00922CD8[0] = 0;
    D_00922CD4[0] = 0;
    D_00922CF4[0] = 0;
    D_00922CF0[0] = 0;
    D_00922CE8[0] = 0;
    D_00922D08[0] = 0;
    D_00922D04[0] = 0;
    D_00922D00[0] = 0;
    D_00922CDC[0] |= 0x20003;
    func_004abb60();
    func_004a77b0();
    func_004b3180(arg0);
    func_00451de0(D_007132B8, arg0, 0, 0, (void *)func_00481980, 0, 0);
}
