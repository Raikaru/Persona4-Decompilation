#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"

extern void kAssertFail(const void *file, u32 line);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0064F0F0[];
extern f32 D_0064F110[];
extern u8 D_0064F210[];
extern s32 func_0036e910(void *arg0);
extern s32 btlShuffleEffStep(u8 *arg0);
extern void btlShuffleEffRelease(u8 *arg0);
extern void btlShuffleEffInitTrail(u8 *arg0, s32 arg1);

extern u8 *mdlEffectCreateFromResource();
extern void mdlEffectDestroy(u8 *a);
extern void mdlEffectStart(s32 a);
extern void mdlEffectSetChildPositionVec(void *a, void *b);
extern void mdlEffectSetEulerRotation(u8 *a, f32 b, f32 c, f32 d);
extern void mdlEffectSetUniformScale(u8 *a, f32 b);
/* The callee's real signature is (f32 *, f32 *, f32); this caller-side prototype keeps the
   float in the second position because mwcc b210 materialises call args in declaration
   order, and retail's bytes (addiu a0 / lwc1 f12 / addiu a1 before the jal) require that. */
extern void btlShuffleCalcStepPose(f32 *arg0, f32 fparg0, f32 *arg1);
extern void btlShuffleCalcLookAt(f32 *arg0, f32 *arg1);

/* measured: the operands must travel through this helper's parameters to get
   retail's index-first `addu $v1,$v1,$s0`; rewriting the callsite expression as
   `offset + (u32)base` is canonicalized straight back to the base-first form. */
static inline u32 bseSlot(u32 offset, u32 base)
{
    return offset + base;
}

// FUN_0038D6C0
void btlShuffleEffFree(u8 *arg0) {
    u8 *tbl;
    s32 i;
    u8 *e;
    u8 **eff;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (i < 0 || i >= 9) {
            kAssertFail(&D_0064F210[0], 0x55);
        }
        e = tbl + i * 8;
        eff = (u8 **)(e + 0xC);
        if (*eff != 0) {
            mdlEffectDestroy(*eff);
            *eff = 0;
        }
        *(u16 *)(tbl + 4) &= ~(1 << i);
    }
    (*jtbl_008873EC)(tbl);
}
// FUN_0038D790
u8 *btlShuffleEffSpawn(u8 *arg0) {
    u8 *tbl;
    u8 *ctx;

    chkmemAllocSiteTag(&D_0064F210[0], 0x103);
    tbl = D_008873F4[0](1, 0x50, 0x40000);
    if (tbl == NULL) {
        kAssertFail(&D_0064F210[0], 0x104);
    }
    ctx = (u8 *)(s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_0064F0F0[0]), 0x13, 0, 0, btlShuffleEffStep, btlShuffleEffFree, (u8 *)(tbl));
    if (ctx == NULL) {
        kAssertFail(&D_0064F210[0], 0x10E);
    }
    *(s32 *)tbl = (s32)func_0036e910(arg0);
    btlShuffleEffRelease(ctx);
    return ctx;
}

// FUN_0038D890
void btlShuffleEffRelease(u8 *arg0) {
    s32 i;
    u8 *tbl;
    u8 *e;
    u8 **eff;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (i != 8) {
            if (i < 0 || i >= 9) {
                kAssertFail(&D_0064F210[0], 0x55);
            }
            e = tbl + i * 8;
            eff = (u8 **)(e + 0xC);
            if (*eff != 0) {
                mdlEffectDestroy(*eff);
                *eff = 0;
            }
            *(u16 *)(tbl + 4) &= ~(1 << i);
        }
    }
    btlShuffleEffInitTrail(arg0, 8);
}

// FUN_0038D970
void btlShuffleEffEnd(u8 *arg0) {
    s32 i;
    u8 *tbl;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (*(u16 *)(tbl + 4) & (u16)(1 << i)) {
            mdlEffectStart(*(s32 *)(tbl + i * 8 + 0xC));
        }
    }
}

// FUN_0038D9F0
void btlShuffleEffUpdate(u8 *arg0) {
    s32 i;
    u8 *tbl;
    u8 *e;
    f32 *src;
    f32 sp68[2];
    f32 sp58[3];

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (*(u16 *)(tbl + 4) & (u16)(1 << i)) {
            e = tbl + i * 8 + 8;
            src = &D_0064F110[i * 7];
            sp68[0] = src[0];
            sp68[1] = src[1];
            btlShuffleCalcStepPose(&sp68[0], src[2], &sp58[0]);
            btlShuffleCalcLookAt(sp58, sp58);
            mdlEffectSetChildPositionVec(*(u8 **)(e + 4), sp58);
            mdlEffectSetEulerRotation(*(u8 **)(e + 4), src[3], src[4], src[5]);
            mdlEffectSetUniformScale(*(u8 **)(e + 4), src[6]);
        }
    }
}

// FUN_0038DAF0
void btlShuffleEffInitTrail(u8 *arg0, s32 arg1) {
    u8 *tbl;
    u8 *e;
    u8 **eff;
    s32 base;
    s32 off;
    s32 mask;
    s32 eoff;

    tbl = *(u8 **)(arg0 + 0x38);
    base = *(s32 *)tbl;
    if (arg1 < 0 || arg1 >= 9) {
        kAssertFail(&D_0064F210[0], 0x165);
    }
    off = arg1 * 4;
    if (((s32 *)(off + base))[0x7CAE] != 0) {
        if (arg1 < 0 || arg1 >= 9) {
            kAssertFail(&D_0064F210[0], 0x3E);
        }
        mask = 1 << arg1;
        if (!(*(u16 *)(tbl + 4) & (u16)mask)) {
            eoff = arg1 * 8;
            e = (u8 *)(eoff + (s32)tbl);
            eff = (u8 **)(e + 0xC);
            if (*eff != 0) {
                kAssertFail(&D_0064F210[0], 0x42);
            }
            *eff = mdlEffectCreateFromResource(((s32 *)(off + *(s32 *)tbl))[0x7CAE]);
            *(u16 *)(tbl + 4) |= (u16)mask;
        }
        eoff = arg1 * 8;
        e = (u8 *)(eoff + (s32)tbl);
        *(s16 *)(e + 8) = 0;
        mdlEffectStart(*(s32 *)(e + 0xC));
        switch (arg1) {
        case 0:
        case 1:
        case 2:
            sdkSndStartStream(1, 5, 5, 9);
            break;
        case 3:
        case 4:
        case 5:
            sdkSndStartStream(1, 5, 5, 0xB);
            break;
        case 6:
        case 7:
        case 8:
            break;
        default:
            kAssertFail(&D_0064F210[0], 0x180);
            break;
        }
    }
}
/* The window artifact this note used to describe is fixed: 0x0038DD60 is now a
   canonical nullsub boundary (see DATA_REACHABLE_ENTRIES in
   tools/reconcile_function_boundaries.py, justified by the callback-table word
   at 0x005DD2A4), so the window is 160B and the body fills it exactly. */
// FUN_0038DCC0
void btlShuffleEffSetup(u8 *arg0, s32 arg1)
{
    u8 *eff;
    u8 **slot;
    u8 *held;

    eff = *(u8 **)(arg0 + 0x38);
    if (arg1 < 0 || arg1 >= 9) {
        kAssertFail(&D_0064F210[0], 0x55);
    }
    slot = (u8 **)(bseSlot(arg1 * 8, (u32)eff) + 0xC);
    held = *(u8 **)(bseSlot(arg1 * 8, (u32)eff) + 0xC);
    if (held != 0) {
        mdlEffectDestroy(held);
        *slot = 0;
    }
    /* measured: the compound assignment evaluates the mask before loading the
       halfword, which is retail's order; a mask local plus an explicit load lets
       b210 hoist the lhu above the shift chain. */
    *(u16 *)(eff + 4) &= ~(1 << arg1);
}

