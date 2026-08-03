#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effCrossfade.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern char D_007145F0[];
extern char D_00714608[];
extern char D_00714618[];
extern u8 *iGpffffbb9c;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *func_00452380(void *path);
extern void func_0044ea90(const void *msg, s32 id);
extern void func_0046d730(const char *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern void func_004b2a00(u8 *arg0);
extern s32 func_004b2780(u8 *arg0);
extern void func_004b2e00(u8 *arg0);
extern s32 func_004b2ed0(u8 *arg0);
extern void func_004b30a0(u8 *arg0, u8 *arg1);
extern u8 *func_003e84a0(void);
extern s32 func_003e9320(void);
extern void func_003efd20(void *a, void *b);
extern s32 func_003ec590(s32 a, s32 b, s32 c, s32 d);
extern void func_0040fcd0(s32 a, s32 b);
extern void func_003e8310(void *a, s32 b);
extern void func_00460ac0(void *a, void *b);

// FUN_004B2ED0
s32 func_004b2ed0(u8 *arg0) {
    u8 *st;
    s32 t;

    st = *(u8 **)(arg0 + 0x38);
    switch (*(u8 *)(st + 0)) {
    case 0:
        return 0;
    case 1:
        if (*(s32 *)(st + 8) != 0) {
            func_0046d730(D_00714608, 0xF2);
        }
        if (*(u8 **)(st + 0xC) != NULL) {
            func_0046d730(D_00714608, 0xF3);
        }
        *(u8 **)(st + 0xC) = (u8 *)func_003e84a0();
        if (*(u8 **)(st + 0xC) == NULL) {
            return 0;
        }
        func_003efd20(*(u8 **)(st + 0xC), (void *)func_003e9320());
        if (*(s32 *)(*(u8 **)(st + 0xC) + 4) == 0) {
            return 0;
        }
        t = func_003ec590(0x200, 0x100, 0x10, 0x185);
        *(s32 *)(st + 8) = t;
        if (t == 0) {
            return 0;
        }
        func_0040fcd0(t, 1);
        func_003e8310(*(u8 **)(st + 0xC), 2);
        *(s32 *)(*(u8 **)(st + 0xC) + 0x60) = *(s32 *)(st + 8);
        *(s16 *)(st + 4) = 0;
        /* fallthrough */
    case 2:
        if (func_004b2780(st) == 0) {
            return 0;
        }
        *(u8 *)(st + 0) = 3;
        /* fallthrough */
    case 3:
        if (iGpffffbb9c != 0) {
            *(s32 *)(st + 0x10) = 0;
            *(s32 *)(st + 0x14) = 0;
            func_00460ac0(iGpffffbb9c, st + 0x10);
        }
        break;
    default:
        break;
    case 4:
        func_004b2e00(st);
        *(u8 *)(st + 0) = 0;
        break;
    }
    return 0;
}

/* measured: store/mask scheduling floor. Retail: addiu $v1,$v1,1; sh $v1,4($s0);
   andi $a0,$v1,0xffff; slt (store BEFORE mask). mwcc b210 always emits the
   andi mask before the sh regardless of the temp type (u16/s32/u32) or the
   switch/single-case-if outer shape. Tried 5 spellings, all nd 2-3. The branch
   orientation (positive beq to out-of-line body) needed the single-case switch. */
// FUN_004B30A0
INCLUDE_ASM("asm/nonmatchings/effCrossfade", func_004b30a0);

// FUN_004B3110
s32 func_004b3110(s16 arg0) {
    u8 *p2;
    u8 *p3;

    p2 = (u8 *)func_00452380(D_007145F0);
    if (p2 == NULL) {
        return 0;
    }
    p3 = *(u8 **)(p2 + 0x38);
    if (*(u8 *)(p3 + 0) != 0) {
        return 0;
    }
    *(u8 *)(p3 + 0) = 1;
    *(s16 *)(p3 + 2) = arg0;
    return 1;
}

// FUN_004B3180
void func_004b3180(s32 arg0) {
    u8 *p;

    func_0044ea90(D_00714618, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x40, 0x40000);
    func_0043f9c8(p, 0, 0x40);
    if (p == NULL) {
        func_0046d730(D_00714608, 0x15B);
    }
    *(void **)(p + 0x18) = (void *)func_004b30a0;
    *(u8 **)(p + 0x20) = p;
    *(u8 *)(p + 0) = 0;
    func_00451de0(D_007145F0, arg0, 0, 0, (void *)func_004b2ed0, 0, p);
}
