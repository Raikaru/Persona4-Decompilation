#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00452490();
extern s32 func_00452380();
extern u8 D_00636A30[];

typedef int (*code)(...);
extern code DAT_008873ec_abs[];
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_00636838[];
extern void func_0025c790(u8 *arg0);
extern s32 func_0029d020(void);
extern s32 func_0029cc00(s32 which);
extern void func_0029cf50(s32 arg0);



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0025C790
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025c790);

// FUN_0025CB80
void func_0025cb80(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0025CBC0
s32 func_0025cbc0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *mem;

    func_0044ea90(D_00636838, 0x113);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    *(s32 *)(mem + 4) = arg1;
    *(s32 *)(mem + 8) = arg2;
    *(s32 *)(mem + 0xC) = -1;
    return func_00451fc0(arg0, D_00636A30, 0xF, 0, 0, func_0025c790,
                         (void (*)(u8 *))func_0025cb80, mem);
}

// FUN_0025CC70
s32 func_0025cc70(void) {
    return func_00452490(func_00452380(D_00636A30)) != 0;
}

/* measured: the assert+allocator+register body is recovered (it is the
   func_0025cbc0 shape wrapped in a func_0029d020 state test, with a second
   path that probes func_00452380/func_00452490 and calls func_0029cf50 before
   returning 1). Best nd 16 with an inline `return 0` in the first branch;
   restructuring to an `else if` chain so all zero exits share one trailing
   `return 0` -- retail branches to a shared L0025CDAC -- measured WORSE at
   nd 18, so the shared-return lever does not apply in this shape. The
   residual sits in the second path (offsets 180-220: retail reaches the
   shared zero return by branch where b210 materializes it inline). Body not
   kept because it MISMATCHES; the recipe above reproduces it in one pass. */
/* measured: nd 42 against retail's 288-byte window; every instruction lines up
   except one. Retail booleanises the second guard's call result with an extra
   `sltu $v0,$zero,$v0` before branching, which shifts everything after it by a
   word. Probed `!= 0` compared against zero, a double negation, an explicit
   assignment into a named local, and that local typed u8/s8/u16/u32/s32 (all
   nd 63, which is worse) - b210 branches on the raw result in every spelling.
   Getting the outer guard's polarity right was worth nd 129 -> nd 42: retail
   sends the ALREADY-OPEN case out of line and falls through into the create
   path. Committed at nd 42. */
// FUN_0025CCB0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0025ccb0(void) {
    u8 *buf;
    s32 a;
    s32 b;

    if (func_0029d020() == 0) {
    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0044ea90(D_00636838, 0x113);
    buf = D_008873F4[0](1, 0x10, 0x40000);
    *(s32 *)(buf + 4) = a;
    *(s32 *)(buf + 8) = b;
    *(s32 *)(buf + 0xC) = -1;
    func_00451fc0(NULL, D_00636A30, 0xF, 0, 0, func_0025c790,
                  (void (*)(u8 *))func_0025cb80, buf);
    } else if (func_00452490(func_00452380(D_00636A30)) == 0) {
        func_0029cf50(0);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025ccb0);
#endif

