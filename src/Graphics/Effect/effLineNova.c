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
u16 *func_00482f70(u32 arg0, u32 arg1, u32 arg2, void *arg3, u32 arg4);
u8 *func_00484490(u8 *obj);
void func_0043f810(void *dst, const void *src, u32 size);
s32 func_004b4430(u8 *arg1);

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


// FUN_004B32F0
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b32f0);
// FUN_004B3420
void func_004b3420(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


// FUN_004B3470
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b3470);


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
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b3ed0);

// FUN_004B4170
void func_004b4170(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


// FUN_004B41C0
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b41c0);


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
