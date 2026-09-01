#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00452490();
extern s32 func_00452380();
extern u8 D_00636A30[];

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 *D_00636820[];
extern u8 D_00636838[];
extern u8 D_00636850[];
extern s32 func_00145270(s32 arg0);
extern void func_0026bc10(s32 arg0, s32 arg1);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s8 func_002bab80(u8 *arg0);
extern void func_00442830(u8 *arg0, u8 *arg1);
extern void func_002bbd80(s8 arg0, s32 arg1, u8 *arg2);
extern s32 func_00248f20(s16 arg0, s32 arg1);
extern void func_0046d730(u8 *arg0, s32 arg1);
extern void func_002badc0(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb420(s8 arg0);
extern s16 func_00104f10(s16 arg0);
extern s16 func_00104ea0(s32 arg0, s16 arg1);
extern void func_001051a0(s32 arg0, s16 arg1, s16 arg2);
extern u8 *func_00246980(s16 arg0, s16 arg1);
extern void func_00275980(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_002bb550(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern s32 func_0025c790(void);
extern s32 func_0029d020(void);
extern s32 func_0029cc00(s32 which);
extern void func_0029cf50(s32 arg0);

typedef struct {
    s32 state;
    s32 index;
    s32 value;
    s32 slot;
} ShdScriptWork;



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).

// FUN_0025C790
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025c790);
// FUN_0025CB80
void func_0025cb80(void)
{
    s32 iVar1;

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
    return func_00451fc0(arg0, D_00636A30, 0xF, 0, 0,
                         (void (*)(u8 *))func_0025c790,
                         (void (*)(u8 *))func_0025cb80, mem);
}

// FUN_0025CC70
s32 func_0025cc70(void) {
    return func_00452490(func_00452380(D_00636A30)) != 0;
}

/* measured: explicit hit local and shared done label preserve retail's
   booleanisation and branch targets; object 280B/window 288B, nd 0. */
// FUN_0025CCB0
s32 func_0025ccb0(void) {
    u8 *buf;
    s32 a;
    s32 b;
    s32 hit;

    if (func_0029d020() == 0) {
        a = func_0029cc00(0);
        b = func_0029cc00(1);
        func_0044ea90(D_00636838, 0x113);
        buf = D_008873F4[0](1, 0x10, 0x40000);
        *(s32 *)(buf + 4) = a;
        *(s32 *)(buf + 8) = b;
        *(s32 *)(buf + 0xC) = -1;
        func_00451fc0(NULL, D_00636A30, 0xF, 0, 0,
                      (void (*)(u8 *))func_0025c790,
                      (void (*)(u8 *))func_0025cb80, buf);
        goto done;
    }
    hit = func_00452490(func_00452380(D_00636A30)) != 0;
    if (hit != 0) {
        goto done;
    }
    func_0029cf50(0);
    return 1;
done:
    return 0;
}

