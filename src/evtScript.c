#include "model_callbacks_internal.h"
/* Original translation unit evtScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "scene_event_internal.h"
extern void func_00106390();
extern void (*jtbl_008873EC[])(void *ptr);

typedef int (*code)();
extern code DAT_008873ec_abs[];



extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void kAssertFail(const void *file, u32 line);
extern u8 D_0063CF80[];
extern u8 D_0063CF90[];
extern u8 D_0063CFA0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_008C024E[];
extern u8 D_00795E60[];

extern void *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern s32 kwlnTaskDestroyWithHierarchy(void *task);
extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern s32 kwlnTaskIsLinked(void *target);
extern void MT_Scene_DestroyRes(u32);
extern void MT_Scene_SetResActiveById(s32, s32);
// lint: allow H011 -- measured: u16 prototype regresses func_00298370 and func_00298550 (andi on wide id args)
extern u16 *MT_Scene_GetRes(s32);
extern s32 mdlPrepareModel(u32 arg0);
extern u8 *mdlGetColor(s32);
extern void evtNodeSetRes(u8 *, s32, u16 *);
extern s32 func_00285af0();
extern u8 *func_00285480();
extern u8 *func_00285b80();
extern s32 scrGetParamInt();
extern s32 scrGetCmdTimer(void);
extern void *mdlFindOrCreateModelObject(u32, u16, u32);
extern s32 evtFindTask();
extern void itfMesWindowApplySlots(s32 arg0);
extern u8 *itfMesWindowBuildEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0,
                         s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *frFontSplitRun(u8 **arg0, s32 arg1);
extern s32 frFontNodeWidth(u8 *arg0);
extern void frFontMoveListToFloat(u8 *arg0, f32 fparg0, f32 fparg1);
extern void frFontSetGlyphColor(u8 *arg0, s32 arg1);

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v0,$v0,$s0`; every callsite spelling (p+scaled,
   scaled+p, a named s32 local) is canonicalized back to base-first. Expand it at
   the use rather than through a local, so nothing stays live across a call. */
static inline u32 evtSlot(u32 offset, u32 base)
{
    return offset + base;
}

extern void frFontListKeepOrRelease(u8 *arg0);
extern f32 sinf(f32 fparg0);
extern f32 iGpffff8094;
/* INCLUDE_ASM fallback below; address taken by func_00298550. */
extern s32 func_00298370(u8 *task);
/* INCLUDE_ASM fallback below; address stored by func_00298b80. */
extern void func_00298990(s32 arg0, s32 arg1);

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_00298370
s32 func_00298370(u8 *unusedTask) {
    typedef struct { u8 b0; u8 b1; u8 b2; u8 b3; } EvtColor;
    s32 temp_2_2;
    u8 *temp_18;
    s32 temp_17;
    u8 *temp_2_4;
    u8 *temp_2;

    temp_2 = (u8 *)kwlnTaskGetWork();
    temp_17 = *(s32 *)(temp_2 + 0);
    if (mdlPrepareModel(temp_17) == 1) {
        MT_Scene_DestroyRes((u16)((( *(s32 *)(temp_2 + 4) + 0x384) & 0x3FF) | 0xC00));
        temp_17 = (s32)(MT_Scene_CreateModelNpcShadowRes((*(s32 *)(temp_2 + 4) + 0x384) & 0xFFFF, 3, temp_17) & 0xFFFF);
        if (temp_17 == 0) {
            kAssertFail(D_0063CF80, 0x34);
        }
        MT_Scene_SetResActiveById(temp_17, 1);
        temp_18 = (u8 *)MT_Scene_GetRes(temp_17);
        temp_2_2 = func_00285af0();
        if (temp_2_2 == 0) {
            kAssertFail(D_0063CF80, 0x39);
        }
        temp_2_4 = (u8 *)func_00285480(kwlnTaskGetWork(temp_2_2));
        temp_2_2 = *(s32 *)(temp_2 + 4);
        temp_2 = (u8 *)func_00285b80(temp_2_4, temp_2_2);
        if (temp_2 == NULL) {
            kAssertFail(D_0063CF80, 0x3D);
        }
        evtNodeSetRes(temp_2, temp_17, (u16 *)temp_18);
        temp_2_4 = mdlGetColor(*(s32 *)(temp_18 + 0x164));
        *(EvtColor *)(temp_2 + 0x50) = *(EvtColor *)temp_2_4;
        return -1;
    }
    return 0;
}
// FUN_00298510
void func_00298510(u8 *unusedTask)
{
    int iVar1;

    iVar1 = kwlnTaskGetWork();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_00298550
s32 func_00298550(void)
{
    s32 v0;
    s32 v1;
    u16 id;
    u8 *p;
    u8 *work;

    v0 = scrGetParamInt(0);
    v1 = scrGetParamInt(1);
    if (scrGetCmdTimer() == 0) {
        id = (u16)(((v0 + 0x384) & 0x3FF) | 0xC00);
        if (MT_Scene_GetRes(id) != 0) {
            p = (u8 *)MT_Scene_GetRes(id);
            if (*(u16 *)(*(s32 *)(p + 0x164) + 0xD4) == 5 &&
                *(u16 *)(*(s32 *)(p + 0x164) + 0xD6) == v1) {
                MT_Scene_SetResActiveById(id, 1);
                return 1;
            }
        }
        chkmemAllocSiteTag(D_0063CF80, 0x4F);
        work = D_008873F4[0](1, 8, 0x40000);
        *(s32 *)(work + 0) = (s32)mdlFindOrCreateModelObject(5, v1 & 0xFFFF, 0);
        *(s32 *)(work + 4) = v0;
        if (*(s32 *)(work + 0) == 0) {
            kAssertFail(D_0063CF80, 0x52);
        }
        (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_0063CF90), 0xF, 0, 0, func_00298370, func_00298510, (u8 *)(work));
    } else {
        if (kwlnTaskIsLinked(kwlnTaskGetTaskByName((s8 *)D_0063CF90)) != 0) {
            goto done;
        }
        return 1;
    }
done:
    return 0;
}
/* The addu operand order this note called an allocator floor is fixed by the
   `evtSlot` helper above, expanded at the use. The note was right that a named
   s32 local and every p+scaled / scaled+p callsite spelling get canonicalized
   back to base-first; only carrying the operands through a helper's parameters
   holds the order, and expanding it per use keeps nothing live across a call. */
// FUN_00298700
s32 func_00298700(void) {
    s32 slot;
    s32 value;
    s32 kind;
    u8 *p;

    slot = scrGetParamInt(0);
    value = scrGetParamInt(1);
    if (slot >= 5) {
        return 1;
    }
    kind = evtFindTask();
    if (kind == 0) {
        return 1;
    }
    p = (u8 *)kwlnTaskGetWork(kind);
    if (func_002909a0((u32 *)(p + 0x678)) == 0) {
        return 1;
    }
    *(s32 *)((u8 *)evtSlot(slot * 4, (u32)p) + 0x698) = value;
    return 1;
}

// FUN_002987D0
void func_002987d0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    u8 *node;
    s32 sum;
    u8 *p;
    u8 *spAC;

    itfMesWindowApplySlots(arg5);
    spAC = (u8 *)itfMesWindowBuildEntry(fparg0, fparg1, fparg2, (arg0 << 8) | arg1,
                               arg2, arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        p = (u8 *)frFontSplitRun(&spAC, arg7);
        if (p == NULL) {
            p = spAC;
            spAC = NULL;
        }
        node = p;
        sum = 0;
        while (node != NULL) {
            sum += frFontNodeWidth(node);
            node = *(u8 **)(node + 0x24);
        }
        frFontMoveListToFloat(p, fparg0 - (f32)sum / 2.0f, fparg1);
        frFontSetGlyphColor(p, arg1 | ~0xFF);
        if (spAC != NULL) {
            frFontDrawList(p, 1, 0);
        }
        frFontListKeepOrRelease(p);
        if (spAC != NULL) {
            frFontListKeepOrRelease(spAC);
        }
    }
}
/* Measured: object 488B / retail window 496B / normalized_diff 0. Named
   multiply-operand locals, assigned in retail order (converted delta first,
   then the GP scale), reproduce the retail conversion/load sequence. The
   prior archived nd8 claim was a differing-word count, not a body result.
   Also ruled out: first-argument hoist/local forms, declaration reversal,
   direct global load, comma assignment, schedule-off, inline evtMulScale and
   evtRamp helpers, reversed multiply operands, alternate float casts, and
   interleaved-parameter order (inapplicable: both target inputs are s32). */
// FUN_00298990
void func_00298990(s32 unused, s32 arg1) {
    f32 temp_f2;
    f32 temp_f0;
    f32 mul_left;
    f32 mul_right;
    s32 var_5;
    s32 temp_16;
    s32 temp_19;
    s32 temp_4;
    s32 temp_5;
    s32 var_18;
    u8 *temp_17;

    temp_17 = (u8 *)kwlnTaskGetWork(arg1);
    temp_19 = *(s32 *)((u8 *)func_00285480(kwlnTaskGetWork(func_00285af0())) + 0x680);
    var_18 = 0;
    while (var_18 < 0xF) {
        temp_5 = var_18 * 0x28;
        temp_4 = *(s32 *)(temp_17 + 4);
        if ((temp_5 < temp_4) && (temp_4 < (temp_5 + 0x12C))) {
            temp_16 = temp_4 - temp_5;
            if (temp_16 < 0xB4) {
                var_5 = (s32)(255.0f * sinf((iGpffff8094 * (f32)temp_16) / 180.0f));
            } else if (temp_16 > 0x10E) {
                temp_f0 = (f32)(temp_16 - 0x10E);
                mul_left = temp_f0;
                mul_right = iGpffff8094;
                temp_f2 = mul_right;
                var_5 = (s32)(255.0f * sinf(temp_f2 + ((mul_right * mul_left) / 30.0f)));
            } else {
                var_5 = 255;
            }
            func_002987d0(320.0f, 300.0f - ((230.0f * (f32)temp_16) / 300.0f), 0.0f,
                          0xFFFFFF, var_5, 0, 0, 0, temp_19, 0, var_18);
        }
        var_18 += 1;
    }
}
// FUN_00298B80
s32 func_00298b80(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *base;
    u8 *p;

    base = (u8 *)kwlnTaskGetWork();
    *(s32 *)(base + 4) += 1;
    if (D_008C024E[0] & 0x9FF) {
        func_00106390(0x1211, 1);
    }
    p = (u8 *)func_00460990();
    *(void **)(p + 8) = (void *)func_00298990;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_00795E60, p);
    return 0;
}
// FUN_00298C10
void func_00298c10(u8 *unusedTask) {
    u8 *p = (u8 *)kwlnTaskGetWork();

    func_00106390(0x1211, 0);
    jtbl_008873EC[0](p);
}

// FUN_00298C60
s32 func_00298c60(void)
{
    s32 task;
    s32 v0;
    u8 *work;

    func_00106390(0x1211, 0);
    task = (s32)kwlnTaskGetTaskByName((s8 *)D_0063CFA0);
    if (task != 0) {
        kwlnTaskDestroyWithHierarchy((void *)task);
    }
    v0 = func_00285af0();
    chkmemAllocSiteTag(D_0063CF80, 0xF6);
    (s32)kwlnTaskCreateChild((void *)(v0), (const void *)(D_0063CFA0), 0xF, 0, 0, func_00298b80, func_00298c10, (u8 *)(D_008873F4[0](1, 8, 0x40000)));
    return 1;
}
