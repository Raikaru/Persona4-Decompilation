/* Consolidated Persona 4 source units. */
/* Original translation unit effLineNova.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

void func_004833f0(void *arg);
void func_0044ea90(u8 *file, s32 line);
void func_0046d730(u8 *file, s32 line);
void *func_00481460(u16 arg0);
void *func_00481540(u16 arg0);
void func_00460ac0(void *arg0, void *arg1);
u16 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
u8 *func_00484490(u8 *obj);
void func_0043f810(void *dst, const void *src, u32 size);
s32 func_004b4430(u8 *arg1);
f32 func_004bd0b0(u32 param);

extern u8 D_00713310[];
extern u8 D_00714628[];
extern u8 D_00714650[];
extern u8 D_00714654[];
extern u8 D_00714664[];
extern u8 D_00724C54[];

/* 4-byte color state at 0x00724C54..57, accessed gp-relative in retail */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern LineNovaColor iGpffffbb64;  // 0x00724C54
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);


/* measured: retail colors the 7 loop-carried temps count2=$a3 v8=$t0 v6=$a2
   v5=$a1 v4=$a0 v3=$v1 i=$t1; mwcc b210 colors count2=$a1 v8=$a3 v6=$a0
   v5=$t1 v4=$v1 v3=$t0 i=$a2 (nd 20, all rows pure register renaming; object
   is otherwise byte-identical incl. hoisted count2 reload before the chain,
   the `(u32)x << 8 >> 8` dsll32/dsrl32 byte extraction, and the i++,v8+=0x18
   increment order). Tried declaration orders, s32/u32 counter+count2,
   raw-memory loop bound (mwcc rematerializes at loop bottom instead of
   hoisting to the preheader), loads-before-calls (adds a 4th saved reg),
   u64 shift spellings (all add sext+canonicalize pairs). Saved-register
   rotation floor family. */
// FUN_004B32F0
u8 *func_004b32f0(u8 *arg0)
{
    s32 n;
    u8 *r;
    u16 *p;
    u32 i;
    u8 *dst;
    u32 c0;
    u32 c1;
    u32 a0;
    u32 a1;
    u32 cnt;
    n = *(s32 *)(arg0 + 0x38);
    func_0044ea90(D_00714628, 0x43);
    r = (u8 *)(*jtbl_008873E8)(n * 8 + 0x10, 0x40000);
    if (r == NULL) {
        func_0046d730(D_00714628, 0x44);
    }
    *(u8 **)(r + 0) = r + 0x10;
    *(u8 **)(r + 8) = r;
    p = func_00482f70(n & 0xFFFF, 4, 6, D_00713310, 0x48);
    *(u16 **)(r + 4) = p;
    *p = *p & 0xFFFE;
    cnt = *(s32 *)(arg0 + 0x38);
    dst = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(r + 4) + 0x10) + 0x18) + 0x30);
    c1 = *(u32 *)(arg0 + 0x54);
    c0 = c1 & 0xFFFFFF;
    a1 = *(u32 *)(arg0 + 0x58);
    a0 = a1 & 0xFFFFFF;
    i = 0;
    while (i < cnt) {
        *(u32 *)(dst + 0x00) = c0;
        *(u32 *)(dst + 0x04) = c1;
        *(u32 *)(dst + 0x08) = c0;
        *(u32 *)(dst + 0x0C) = a0;
        *(u32 *)(dst + 0x10) = a1;
        *(u32 *)(dst + 0x14) = a0;
        i++;
        dst += 0x18;
    }
    return r;
}

// FUN_004B3420
void func_004b3420(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


/* measured: ordinary float/loop candidate reached nd 220 with a 576-byte
   object, but remained non-byte-exact; partial candidate restored to ASM. */
// FUN_004B3470
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b3470);


/* measured: retail contains COP2/VU0 vector work; H009 permits the required
   inline asm. No byte-exact candidate was retained in this wave. */
// FUN_004B36B0
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b36b0);


// FUN_004B3D90
void func_004b3d90(u8 *arg0) {
    u8 *p6;
    u8 *p16;
    u32 v5;
    void *r;

    p6 = *(u8 **)(arg0 + 0x24);
    p16 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    v5 = *(u32 *)(p6 + 0x34);
    if (v5 >= *(u32 *)(arg0 + 0x14) || v5 == 0) {
        switch (*(u8 *)(p6 + 0x68)) {
        case 0:
            r = func_00481540(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        default:
            r = func_00481460(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        }
    }
}


// FUN_004B3E40
void func_004b3e40(u8 *arg0) {
    u8 *p10;
    u8 *dst;

    p10 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p10 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p10 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    *(s32 *)(p10 + 0x20) = (s32)func_004b4430;
    *(s32 *)(p10 + 0x28) = (s32)arg0;
}


// FUN_004B3ED0
u8 *func_004b3ed0(u8 *arg0)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_5;
    s32 var_5_2;
    u16 *temp_2_2;
    u32 temp_16;
    u32 cnt;
    u32 temp_4_2;
    u32 temp_4_3;
    u32 temp_6;
    u32 temp_6_2;
    u32 var_6;
    u8 temp_4;
    u8 *temp_2;
    u8 *var_3;

    temp_16 = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00714628, 0x16D);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_16 * 6 + 0x10, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00714628, 0x16E);
    }
    *(u8 **)(temp_2 + 0) = temp_2 + 0x10;
    *(u8 **)(temp_2 + 8) = temp_2;
    temp_2_2 = func_00482f70(temp_16 & 0xFFFF, 4, 6, D_00713310, 0x48);
    *(u16 **)(temp_2 + 4) = temp_2_2;
    *temp_2_2 &= 0xFFFE;
    cnt = *(u32 *)(arg0 + 0x38);
    var_3 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 4) + 0x10) + 0x18) + 0x30);
    temp_4 = *(u8 *)(arg0 + 0x92);
    var_f1 = (f32)(u32)temp_4;
    temp_f2 = var_f1 / 255.0f;
    temp_6 = *(u32 *)(arg0 + 0x54);
    temp_4_2 = temp_6 >> 0x18;
    var_f0 = (f32)(u32)temp_4_2;
    temp_f1 = var_f0 * temp_f2;
    var_5 = (u32)temp_f1;
    temp_5 = (temp_6 & 0xFFFFFF) | (var_5 << 24);
    temp_6_2 = *(u32 *)(arg0 + 0x58);
    temp_4_3 = temp_6_2 >> 0x18;
    var_f0_2 = (f32)(u32)temp_4_3;
    temp_f1_2 = var_f0_2 * temp_f2;
    var_5_2 = (u32)temp_f1_2;
    temp_5_2 = (temp_6_2 & 0xFFFFFF) | (var_5_2 << 24);
    var_6 = 0;
    while (var_6 < cnt) {
        *(s32 *)(var_3 + 0) = temp_5_2;
        *(s32 *)(var_3 + 4) = temp_5;
        *(s32 *)(var_3 + 8) = temp_5_2;
        *(u32 *)(var_3 + 0xC) = *(u32 *)(arg0 + 0x58);
        *(u32 *)(var_3 + 0x10) = *(u32 *)(arg0 + 0x54);
        *(u32 *)(var_3 + 0x14) = *(u32 *)(arg0 + 0x58);
        var_6++;
        var_3 += 0x18;
    }
    return temp_2;
}

// FUN_004B4170
void func_004b4170(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


/* measured: plain-C FPU-MAC reconstruction reached nd 266 with a 568-byte
   object against a 624-byte window; non-byte-exact candidate restored to ASM. */
// FUN_004B41C0
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b41c0);


/* measured: retail contains COP2/VU0 vector work; H009 permits the required
   inline asm, while the FPU MAC portions must remain plain C. No byte-exact
   candidate was retained in this wave. */
// FUN_004B4430
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b4430);


// FUN_004B4C00
void func_004b4c00(u8 *arg0) {
    u8 *p6;
    u8 *p16;
    u32 v5;
    void *r;

    p6 = *(u8 **)(arg0 + 0x24);
    p16 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    v5 = *(u32 *)(p6 + 0x34);
    if (v5 >= *(u32 *)(arg0 + 0x14) || v5 == 0) {
        switch (*(u8 *)(p6 + 0x68)) {
        case 0:
            r = func_00481540(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        default:
            r = func_00481460(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        }
    }
}


// FUN_004B4CB0
u8 *func_004b4cb0(s32 arg0, u8 *arg1) {
    u8 *w;
    s32 size;
    u32 idx;
    u32 idx2;

    if ((u16)arg0 >= 3) {
        func_0046d730(D_00714628, 0x28C);
    }
    idx = (u16)arg0;
    size = *(s32 *)(&D_00714664[0] + idx * 0x18);
    func_0044ea90(D_00714628, 0x290);
    w = (u8 *)(*jtbl_008873E8)(size + 0x30, 0x40000);
    if (w == NULL) {
        func_0046d730(D_00714628, 0x291);
    }
    *(u8 **)(w + 0x24) = w + 0x30;
    *(s32 *)(w + 0x14) = 0;
    *(s32 *)(w + 0x18) = idx;
    *(s32 *)(w + 0x10) = -1;
    *(s32 *)(w + 0x1C) = 0;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(w) : "memory");
    func_0043f810(*(void **)(w + 0x24), arg1, size);
    idx2 = (u16)arg0 * 0x18;
    *(s32 *)(w + 0x20) = (*(s32 (**)(u8 *))(&D_00714654[0] + idx2))(arg1);
    (*(void (**)(u8 *))(&D_00714650[0] + idx2))(w);
    return w;
}
// FUN_004B4E10
u8 *func_004b4e10(u8 *arg0) {
    u8 *p;

    p = func_00484490(arg0);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B3);
    }
    p = func_004b4cb0(*(u16 *)(arg0 + 0xC), p);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B5);
    }
    return p;
}
