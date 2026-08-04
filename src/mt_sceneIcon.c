#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mt_sceneIcon.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

/* gp - 0x5908 = 0x007637E8. */
extern u8 iGpffffa6f8;
/* gp - 0x5900 = 0x007637F0. */
extern u8 iGpffffa700;
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 *func_00145270(void);
extern void func_004b1170(s32 a);
extern void func_0026d890(u8 *arg0);
extern u8 D_0063B558[];
extern u8 D_0063B568[];
extern void func_00440b68(u8 *fmt, u8 *file, s32 line);
extern u8 *func_00454a60(u8 *path, s32 mode);
extern void func_00456150(u8 *handle);


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0026D840
void func_0026d840(void)
{
    func_00440b68(&iGpffffa6f8, D_0063B558, 0x38);
    func_00456150(func_00454a60(D_0063B568, 1));
}

// FUN_0026D890
INCLUDE_ASM("asm/nonmatchings/mt_sceneIcon", func_0026d890);
// FUN_0026D9F0
void func_0026d9f0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0026DA30
s32 func_0026da30(s32 arg0, s32 arg1)
{
    u8 *icon;
    u8 *mem;
    s32 kind;

    if (arg1 == 0xA) {
        icon = func_00145270();
        /* measured: the NULL return is an `else` clause, not an early return, so
           its zero lands after the two kind blocks exactly as retail places it. */
        if (icon != NULL) {
            kind = (*(u16 *)icon & 0xFFC00) >> 10;
            if (kind == 1) {
                if (*(s32 *)(icon + 0x144) != 0) {
                    func_004b1170(*(s32 *)(icon + 0x144));
                    return 0;
                }
            } else if (kind == 3) {
                if (*(s32 *)(icon + 0x144) != 0) {
                    func_004b1170(*(s32 *)(icon + 0x144));
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
    func_0044ea90(D_0063B558, 0xC1);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    *(s16 *)(mem + 4) = arg0;
    *(s32 *)(mem + 8) = arg1;
    return func_00451de0(&iGpffffa700, 0xF, 0, 0, func_0026d890,
                         (void (*)(u8 *))func_0026d9f0, mem);
}

