#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mt_sceneIcon.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern s32 func_00455f70(s32 arg0, void *arg1);
extern s32 func_004b1130(s32 arg0);
extern void func_00268b20(s32 arg0);
extern s32 D_0063B4F0[];

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
extern u8 *func_00145270(); /* old-style: func_0026d890 passes the icon id in $a0, func_0026da30 calls it bare */
extern void func_004b1170(s32 a);
/* measured: returns 0 / -1 in $v0; the task dispatcher discards it, so the callback site casts. */
extern s32 func_0026d890(u8 *arg0);
extern u8 D_0063B558[];
extern u8 D_0063B568[];
extern void func_00440b68(u8 *fmt, u8 *file, s32 line);
extern u8 *func_00454a60(u8 *path, s32 mode);
extern void func_00456150(u8 *handle);



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

/* measured: nd 20 (obj 340B vs window 352B) from 55. Reconstructed from the m2c
   draft in src/generated/code1_0026.c.

   The 55 -> 20 was the exit shape: the shared `return 0` belongs at the very END
   of the function with case 0 reaching it via `break`, NOT as a `default:
   return 0;` sitting between case 0 and case 1 the way m2c prints it. With the
   m2c layout b210 materializes the zero inline at the end of case 0 and branches
   to the epilogue; retail branches both case 0 and the default to one trailing
   block.

   Residual: retail colours `w` into $s1 and the func_004b1130 handle into $s0,
   b210 the reverse -- and retail REUSES w's register for the func_00145270
   result once w is dead, which is why the mirror covers the whole body. Also
   `sltiu $at` vs `sltiu $v0` on the 0x1B bound, and retail tests the raw $v0
   return for NULL where b210 tests the saved copy.

   Measured and rejected: both declaration orders of {handle, w}, explicitly
   reusing `w` for the icon pointer (20), and collapsing the two zero cases into
   an `|| ` chain to chase the $at destination (61, far worse -- the nested
   else-if IS correct). Six spellings. Saved-register colouring floor.

   Two declaration facts recovered here: func_00145270 takes an id in $a0 from
   this function but is called bare from func_0026da30, so it must stay
   old-style; and func_0026d890 really does return 0 / -1 in $v0 even though the
   task dispatcher discards it, so its prototype is s32 and the callback site
   casts.
   Committed at nd 18. */
// FUN_0026D890 NONMATCHING
#ifdef NON_MATCHING
s32 func_0026d890(u8 *arg0)
{
    u8 sp3C[0x4];
    s32 handle;
    u8 *w;
    u8 *icon;
    s32 kind;
    s32 prev;
    u32 idx;
    s32 res;

    w = (u8 *)func_00452560();
    switch (*(u32 *)w) {
    case 0:
        idx = *(u32 *)(w + 8);
        if (idx >= 0x1BU) {
            res = 0;
        } else if (D_0063B4F0[idx] == 0) {
            res = 0;
        } else {
            res = func_00455f70(D_0063B4F0[idx], &sp3C[0]);
        }
        *(s32 *)(w + 0xC) = res;
        *(u32 *)w = 1;
        break;
    case 1:
        handle = func_004b1130(*(s32 *)(w + 0xC));
        icon = func_00145270(*(u16 *)(w + 4));
        if (icon != NULL) {
            kind = (*(u16 *)icon & 0xFFC00) >> 0xA;
            if (kind == 1) {
                prev = *(s32 *)(icon + 0x140);
                if (prev != 0) {
                    func_00268b20(prev);
                }
                *(s32 *)(icon + 0x140) = handle;
            } else if (kind == 3) {
                prev = *(s32 *)(icon + 0x140);
                if (prev != 0) {
                    func_00268b20(prev);
                }
                *(s32 *)(icon + 0x140) = handle;
            }
        }
        return -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mt_sceneIcon", func_0026d890);
#endif
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
    return func_00451de0(&iGpffffa700, 0xF, 0, 0, (void (*)(u8 *))func_0026d890,
                         (void (*)(u8 *))func_0026d9f0, mem);
}

