#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCmbBall.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_0044ea90(const void *, s32);
extern s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern char D_0064A740[];
extern char D_0064A750[];
extern char D_0064A770[];
extern void func_0034ac00(u8 *);
extern void func_0034ad40(u8 *);
extern s32 func_0034b380(u8 *);
extern u8 *func_00461390(void *, s32, void *, s32);
extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
extern s16 func_002b2cb0(s32, s32, s32, s32, s32);
extern s16 func_002b2d00(s32, s32, s32, s32, s32);
extern u8 D_00793E80[];



// FUN_0034AD70
void func_0034ad70(s32 arg0, s8 arg1, s16 arg2) {
    u8 *buf;
    s32 i;

    func_0044ea90(&D_0064A740, 0x98);
    buf = (u8 *)D_008873F4[0](1, 0x1810, 0x40000);
    func_00451fc0(arg0, D_0064A750, 0xF, 0, 0, (void (*)(u8 *))func_0034ac00,
                  func_0034ad40, buf);
    for (i = 0; i < 0xC; i++) {
        *(s16 *)(buf + (i << 9) + 0x104) = 0;
        *(s16 *)(buf + (i << 9) + 0x100) = arg2;
    }
    *(s8 *)(buf + 0x1800) = arg1;
}

// FUN_0034AE50
u8 *func_0034ae50(u8 *arg0, s8 arg1) {
    s32 off = arg1 * 0x200;

    return *(u8 **)(arg0 + 0x38) + off + 0x104;
}

/* measured: functional structure fully recovered (the 8 D_00887300[0] calls
   with the base hoisted into $s0, the func_003f6440/002b2a60 calls, the 8
   base stores, the 4-iteration loop with s16 index, and the final float
   stores). Unresolved residuals: (1) retail hoists base = arg1+(idx<<8)
   into $s0 ONCE (stores via $s0) and reuses it across all 8 stores AND the
   loop; mwcc rematerializes lh idx/sll/addu base on every store and every
   loop iteration even with #pragma opt_propagation off, obj 1028B vs
   window 1296B (67 words short); (2) the u8-to-float negative branch
   shifts with srl but retail ELF uses sra (same .s-vs-ELF conflict as
   func_0034b380). Grounded: no spelling tried (s16/s32 idx, typed base,
   opt_propagation off) reproduces the single hoist. */
// FUN_0034AE70
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034ae70);

/* measured: functional structure fully recovered (E10/E70/E73 dispatch, the
   two u8-to-float conversion branches with the s8 shift, the func_002b2aa0
   call with 5 args, the 0x4F000000 float-to-u8 guard, the E6A/E68 update,
   the E70 func_002b2d00 branch, and the 0xE s16-indexed func_00461390 loop).
   Unresolved residuals: (1) the float-to-u8 overflow guard compares with
   c.ole.s $f1,$f0 (2.1474836e9<=r) + bc1t, retail emits c.olt.s $f0,$f1
   (r<2.1474836e9) + bc1f -- both (r<f) and !(r>=f) spellings canonicalize to
   c.ole.s, unchanged nd 165; (2) the u8-to-float negative branch shifts with
   srl (v is s32/s8 from lbu, mwcc proves non-negative) but retail ELF uses
   sra; .s file says srl, ELF says sra -- unreconciled; (3) obj 892B vs window
   912B, 5 words short. Compiler floors, not yet source-drivable. */
// FUN_0034B380
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034b380);
// FUN_0034B710
void func_0034b710(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0034B740
void func_0034b740(s32 arg0) {
    u8 *buf;
    s16 i;

    func_0044ea90(&D_0064A740, 0x14D);
    buf = (u8 *)D_008873F4[0](1, 0xF10, 0x40000);
    func_00451fc0(arg0, D_0064A770, 0xF, 0, 0, (void (*)(u8 *))func_0034b380,
                  func_0034b710, buf);
    i = 0;
    *(s16 *)(buf + 0xE10) = 0;
    while (i < 0xE) {
        i++;
    }
    *(s16 *)(buf + 0) = 0x41;
}