#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"

typedef struct RwMatrix RwMatrix;

extern s32 iGpffff9ef8;
extern s32 iGpffff9f08;

extern void (*DAT_008873EC[])(void *);
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007E4320[];
extern u8 D_007F16F2[];
extern u8 D_007F16F4[];
extern u8 D_007E8C00[];
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern s32 iGpffffb2e8;
extern s32 iGpffffb2e4;
extern s32 iGpffffb2e0;
extern u8 D_007E8BE0[];
extern u8 D_007E8BE8[];
extern u8 D_007E8BF8[];
extern u8 D_007E80A0[];
extern u8 D_007E8060[];
extern u8 D_007E8020[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern s32 D_007643A4;
extern s32 D_007643AC;
extern f32 D_007643B0;
extern f32 D_007643B4;
extern u8 D_007943C0[];
extern u8 D_00794960[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern void (*D_00887300[])(u32, u32);
extern void chkmemAllocSiteTag(const void *msg, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 D_007F1730[];

extern u8 D_005F16C8[];
extern u8 D_005F16D0[];

extern u8 D_007EF9F8[];
extern u8 D_007EFA00[];
extern u8 D_005F1698[];
extern u8 D_005F16E0[];
extern char D_005F16B0[];
extern u8 D_007948D0[];
extern f32 fabsf(f32 x);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern u8 *mdlGetMatrix();
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern u8 D_005F12E0[];
extern u8 D_005F15F8[];
extern u8 D_005F1630[];
extern u8 D_005F1610[];
extern u8 D_007F00D8[];
extern u8 D_007E9328[];
extern s32 FldFrameTask_Update(u8 *arg0);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlAdvanceModelFromFlags(s32 arg0);
extern s32 iGpffff9f00;
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 func_001623f0();
extern s32 D_005F1350[];
extern void mdlAttachSlotModelFromResource(void *arg0, u16 arg1, u32 arg2, u16 arg3,
                           void *arg4, u32 arg5);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];


typedef struct F8060Frame
{
    RwV3d sp50;
    RwV3d sp5c;
    u8 pad68[8];
    RwV3d sp70;
    u8 pad7c[4];
    RwV3d sp80;
    u8 pad8c[4];
    RwV3d sp90;
} F8060Frame;

extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldFrame_RaycastFieldWorlds(RwV3d *arg0, RwV3d *arg1, f32 fparg0,
                         u16 arg2);
extern void func_001823d0(s32 arg0, u16 arg1, u16 arg2);


typedef struct E8E0Frame
{
    s64 sp30;
    f32 sp38;
    u8 pad3c[4];
    u8 sp40[12];
    u8 pad4c[4];
    RwV3d sp50;
} E8E0Frame;
typedef struct EEE0Frame
{
    s64 sp40;
    f32 sp48;
    u8 pad4c[4];
    u8 sp50[12];
    u8 pad5c[4];
    RwV3d sp60;
    u8 pad6c[4];
    s64 sp70;
    f32 sp78;
    u8 pad7c[4];
    u8 sp80[12];
    u8 pad8c[4];
    RwV3d sp90;
} EEE0Frame;
extern f32 iGpffff8094;

extern s32 RwEngineGetMatrixTolerances(RwV3d *arg0);
extern void RwMatrixOptimize(u8 *arg0, RwV3d *arg1);
extern void RwMatrixUpdate(u8 *arg0);


typedef signed __int128 s128;

typedef struct F630Frame
{
    u8 work[0x40];
    f32 sp80;
    s16 sp84;
    u8 pad86[2];
    f32 sp88;
    f32 sp8c;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 sp9c;
    f32 spa0;
    f32 spa4;
    f32 spa8;
    u32 reserved6c; /* Cleared and copied with the seven-quadword snapshot. */
} __attribute__((aligned(16))) F630Frame;
static inline f32 code1_0016_cvt(s32 value) {
    return (f32)value;
}

/* Source unit: src/promoted/code1_0016.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0016.c; members 00167f00-00168ec0 */

/* Build a 7-by-8 grid of 80-by-64 quads, snapshotting depth before any stores.
   measured: natural vertex assignment order, invariant hoisting and disabled
   propagation preserve retail's coordinate preparation and float registers.
   Object 252B/window 256B; exact instructions and a four-byte zero tail. */
/* measured: restore propagation and invariant baselines after the exact grid. */
/* measured: closing the single-function address-hoist bracket. */
/* measured: opt_propagation off preserves the render-state table base across calls. */
/* measured: closes the function-scoped opt_propagation probe. */
/* Matched full 759-instruction retail body.  The state accessor preserves the
 * read before the row-offset calculations across the branch join. */
#pragma push
#pragma pop
/* measured: opt_propagation off probe for retail field-load order in func_001615a0 */
/* measured: opt_propagation on closes the func_001615a0 load-order probe */
/* measured: opt_propagation off preserves the retail recomputed index and live register set in func_00162200. */
/* measured: closes the opt_propagation bracket for func_00162200. */
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
/* measured: closes the loop-invariant scope at the file baseline. */
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
/* measured: closes the loop-invariant scope at the file baseline. */
/* measured: optimization_level 1 reproduces func_001623f0's register coloring. */
/* measured: restore baseline optimization level after func_001623f0. */
// FUN_00167F00
s32 FldFrameTask_UpdateFollower(u8 *arg0)
{
    s32 temp_3;
    s32 temp_4_2;
    u16 temp_4;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0xC) == 0) {
        temp_4 = *(u16 *)(temp_16 + 4);
        temp_3 = (temp_4 & 0xFFC00) >> 0xA;
        switch (temp_3) {
        case 1:
            temp_2 = MT_Scene_GetRes(temp_4);
            *(s32 *)(temp_16 + 8) = *(s32 *)(temp_2 + 0x164);
            *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_2 + 0x228);
            break;
        case 3:
            temp_2_2 = MT_Scene_GetRes(temp_4);
            if ((*(s32 *)(temp_2_2 + 0x28) & 0x10000000) != 0) {
                *(s32 *)(temp_16 + 8) = *(s32 *)(temp_2_2 + 0x164);
                *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_2_2 + 0x22C);
            }
            break;
        }
    }
    temp_4_2 = *(s32 *)(temp_16 + 8);
    if ((temp_4_2 != 0) &&
        (*(s32 *)(temp_16 + 0xC) != 0) &&
        (((*(u16 *)(temp_16 + 4) & 0xFFC00) >> 0xA) == 3)) {
        temp_17 = (u8 *)mdlGetMatrix(temp_4_2);
        temp_2_3 = (u8 *)mdlGetMatrix(*(s32 *)(temp_16 + 0xC));
        *(RwV3d *)(temp_2_3 + 0x30) =
            *(RwV3d *)(temp_17 + 0x30);
        mdlAdvanceModelFromFlags(*(s32 *)(temp_16 + 0xC));
    }
    return 0;
}

// FUN_00168030
void FldFrameTask_DestroyFollower(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

// FUN_00168060
s32 FldFrameTask_Update(u8 *arg0)
{
    F8060Frame stack;
    s32 state;
    s32 i;
    s32 offset;
    s32 *counter_ptr;
    u32 counter;
    u8 *object;
    u8 *source;
    u8 *target;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if ((*(u32 *)(work + 4) & 0x08000000) != 0) {
        return 0;
    }

    state = *(s32 *)work;
    switch (state) {
    case 0:
        object = mdlGetMatrix(*(s32 *)(work + 0x10));
        stack.sp70 = *(RwV3d *)(object + 0x30);

        if (((*(u32 *)(work + 4) & 0x40000000) != 0) &&
            ((*(u32 *)(work + 4) & 0x10000000) == 0)) {
            stack.sp5c = stack.sp70;
            stack.sp50 = stack.sp5c;
            if (FldMap_IsCurrentInBandA() != 0) {
                stack.sp50.y += 600.0f;
            } else {
                stack.sp50.y += 200.0f;
            }
            stack.sp5c.y -= 1000.0f;
            if (FldFrame_RaycastSelectedWorld(&stack.sp50, &stack.sp90) == 1) {
                *(f32 *)(work + 0x1C) = -(stack.sp70.y - stack.sp90.y);
            }
        }

        for (i = 0; i < 3; i++) {
            stack.sp80.x = *(f32 *)(work + 0x18) / 3.0f;
            stack.sp80.y = *(f32 *)(work + 0x1C) / 3.0f;
            stack.sp80.z = *(f32 *)(work + 0x20) / 3.0f;
            source = mdlGetMatrix(*(s32 *)(work + 0x10));
            stack.sp70 = *(RwV3d *)(source + 0x30);
            stack.sp70.y += *(f32 *)(work + 0x24);
            if ((*(u32 *)(work + 4) & 0x10000000) == 0) {
                FldFrame_RaycastFieldWorlds(&stack.sp70, &stack.sp80,
                              *(f32 *)(work + 0x24), *(u16 *)(work + 8));
            }
            mdlTranslateMatrix((RwMatrix *)*(s32 *)(work + 0x10), &stack.sp80, 2);
            if (*(s32 *)(work + 0x14) != 0) {
                source = mdlGetMatrix(*(s32 *)(work + 0x10));
                target = mdlGetMatrix(*(s32 *)(work + 0x14));
                *(RwV3d *)(target + 0x30) =
                    *(RwV3d *)(source + 0x30);
                mdlAdvanceModelFromFlags(*(s32 *)(work + 0x14));
            }
        }

        if (*(s32 *)(work + 0xC) != 0) {
            if ((*(u32 *)(work + 4) & 1) == 0) {
                counter = *(u32 *)(work + 0x3C);
                if (counter >= 5) {
                    target = *(u8 **)(work + 0xC);
                    *(u8 *)(*(s32 *)(target + 0x710) + (s32)target +
                            0x1D0) = 1;
                    target = *(u8 **)(work + 0xC);
                    *(f32 *)((*(u32 *)(target + 0x710) << 3) +
                             (u32)target + 0x210) =
                        *(f32 *)(object + 0x30);
                    target = *(u8 **)(work + 0xC);
                    *(f32 *)((*(u32 *)(target + 0x710) << 3) +
                             (u32)target + 0x214) =
                        *(f32 *)(object + 0x38);
                    target = *(u8 **)(work + 0xC);
                    offset = *(s32 *)(target + 0x710) * 12;
                    offset += (s32)target;
                    *(RwV3d *)(offset + 0x410) =
                        *(RwV3d *)(object + 0x20);
                    target = *(u8 **)(work + 0xC);
                    *(s32 *)(target + 0x710) += 1;
                    target = *(u8 **)(work + 0xC);
                    counter_ptr = (s32 *)(target + 0x710);
                    if (*(s32 *)(target + 0x710) >= 0x40) {
                        *counter_ptr = 0;
                    }
                    *(s32 *)(work + 0x3C) = 0;
                } else {
                    *(u32 *)(work + 0x3C) = counter + 1;
                }
            } else {
                *(s32 *)(work + 0x3C) = 0;
            }
        }

        *(s32 *)(work + 0x40) =
            (s32)((*(f32 *)(object + 0x30) + 600.0f) / 1200.0f);
        *(s32 *)(work + 0x44) =
            (s32)((*(f32 *)(object + 0x38) + 600.0f) / 1200.0f);
        if ((*(u16 *)(work + 8) & 0x3FF) < 100) {
            func_001823d0(*(s32 *)(work + 0x10), *(u16 *)(work + 0xA),
                          *(u16 *)(work + 8));
        }
        *(s32 *)work += 1;
        break;
    case 1:
    case 2:
    default:
        break;
    }
    return 0;
}

// FUN_00168470
void FldFrameTask_Destroy(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

// FUN_001684A0
/* measured: opt_loop_invariants hoists the two resource-table strides and
   their absolute bases for FldFrameTask_Spawn. */
/* measured: FldFrameTask_Spawn MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 FldFrameTask_Spawn(s32 arg0, s32 arg1, f32 fparg0)
{
    s32 temp_18;
    s32 temp_7;
    s32 temp_7_2;
    s32 var_9;
    s32 var_9_2;
    s32 stride;
    u16 temp_4;
    u32 temp_3;
    u8 *base;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_5;
    u8 *temp_5_2;

    stride = 0x750;
    chkmemAllocSiteTag(D_005F15F8, 0x182);
    base = (u8 *)D_008873F4;
    temp_2 = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x48, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_18 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1630), 0xF, 0, 0, FldFrameTask_Update, FldFrameTask_Destroy, (u8 *)(temp_2));
    *(s32 *)temp_2 = 1;
    temp_4 = arg1 & 0xFFFF;
    *(s16 *)(temp_2 + 8) = arg1;
    *(f32 *)(temp_2 + 0x24) = fparg0;
    *(s32 *)(temp_2 + 0x28) = 0;
    temp_3 = (u32)(arg1 & 0xFFC00) >> 0xA;
    if (temp_3 == 1) {
        temp_2_2 = MT_Scene_GetRes(temp_4);
        if (temp_2_2 != NULL) {
            *(s32 *)(temp_2 + 0x10) = *(s32 *)(temp_2_2 + 0x164);
        }
        var_9 = 0;
        while (var_9 < 4) {
            temp_7 = var_9 * stride;
            temp_5 = D_007EF9B0 + temp_7;
            if ((*(s32 *)(temp_5 + 0x48) != 0) &&
                (*(s32 *)(temp_5 + 0x50) == *(s32 *)(temp_2_2 + 0x164))) {
                *(u16 *)(temp_2 + 0xA) = *(u16 *)(D_007F00D8 + temp_7);
                *(u8 **)(temp_2 + 0xC) = temp_5;
                break;
            }
            var_9 += 1;
        }
        var_9_2 = 0;
        while (var_9_2 < 0xF) {
            temp_7_2 = var_9_2 * stride;
            temp_5_2 = D_007E8C00 + temp_7_2;
            if ((*(s32 *)(temp_5_2 + 0x48) != 0) &&
                (*(s32 *)(temp_5_2 + 0x50) == *(s32 *)(temp_2_2 + 0x164))) {
                *(u16 *)(temp_2 + 0xA) = *(u16 *)(D_007E9328 + temp_7_2);
                *(u8 **)(temp_2 + 0xC) = temp_5_2;
                break;
            }
            var_9_2 += 1;
        }
    } else if (temp_3 == 3) {
        temp_2_3 = MT_Scene_GetRes(temp_4);
        if (temp_2_3 != NULL) {
            *(s32 *)(temp_2 + 0x10) = *(s32 *)(temp_2_3 + 0x164);
        }
    }
    chkmemAllocSiteTag(D_005F15F8, 0x83);
    base = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x10, 0x40000);
    if (base != NULL) {
        (s32)kwlnTaskCreateChild((void *)(temp_18), (const void *)(D_005F1610), 0x10, 0, 0, FldFrameTask_UpdateFollower, FldFrameTask_DestroyFollower, (u8 *)(base));
        *(s16 *)(base + 4) = arg1;
    }
    return temp_18;
}

/* measured: closes the opt_loop_invariants scope for FldFrameTask_Spawn. */
/* measured: FldFrameTask_GetPosition, FldFrameTask_SetOrientation, FldFrameTask_StartMove MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
// FUN_00168730
void FldFrameTask_SetFlags(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) | arg1;
}

// FUN_00168750
void FldFrameTask_ClearFlags(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) & ~arg1;
}

// FUN_00168770
f32 FldFrameTask_GetHeight(u8 *arg0)
{
    return *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x24);
}

// FUN_00168780
void FldFrameTask_SetHeight(u8 *arg0, f32 fparg0) {
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(f32 *)(temp_5 + 0x24) = fparg0;
    if (fparg0 == 0.0f) {
        *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) | 0x10000000);
        return;
    }
    *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) & 0xEFFFFFFF);
}

// FUN_001687D0
s32 FldFrameTask_GetTileX(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40);
}

// FUN_001687E0
s32 FldFrameTask_GetTileZ(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44);
}

// FUN_001687F0
void FldFrameTask_GetPosition(u8 *arg0, u8 *arg1)
{
    RwV3d sp20;
    u8 *var_4;
    s32 var_3;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg1 + 0x38);
    var_4 = (u8 *)&sp20;
    var_3 = 0xC;
    if (var_4 != NULL) {
        do {
            *var_4 = 0;
            var_4 += 1;
            var_3 -= 1;
        } while (var_3 != 0);
    }
    temp_4 = *(s32 *)(temp_5 + 0x10);
    if (temp_4 != 0) {
        temp_2 = mdlGetMatrix(temp_4, temp_5);
        sp20 = *(RwV3d *)(temp_2 + 0x30);
    }
    *(RwV3d *)arg0 = sp20;
}

// FUN_00168890
void FldFrameTask_SetOrientation(u8 *arg0, u8 *arg1)
{
    RwV3d sp70;
    RwV3d sp60;
    RwV3d sp50;
    RwV3d sp40;
    RwV3d sp30;
    u8 *var_4;
    s32 var_3;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_5;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_4 = (u8 *)&sp60;
    var_3 = 0xC;
    if (var_4 != NULL) {
        do {
            *var_4 = 0;
            var_4 += 1;
            var_3 -= 1;
        } while (var_3 != 0);
    }
    temp_4 = *(s32 *)(temp_16 + 0x10);
    if (temp_4 != 0) {
        temp_2 = mdlGetMatrix(temp_4);
        sp70 = *(RwV3d *)(temp_2 + 0x30);
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        *(RwV3d *)(temp_2 + 0x30) = sp60;
        RwEngineGetMatrixTolerances(&sp50);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(temp_16 + 0x10)),
            &sp50);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)));
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        *(RwV3d *)temp_2 = *(RwV3d *)arg1;
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        *(RwV3d *)(temp_2 + 0x10) = *(RwV3d *)(arg1 + 0x10);
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        *(RwV3d *)(temp_2 + 0x20) = *(RwV3d *)(arg1 + 0x20);
        RwEngineGetMatrixTolerances(&sp40);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(temp_16 + 0x10)),
            &sp40);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)));
        temp_5 = *(u8 **)(temp_16 + 0xC);
        if (temp_5 != NULL) {
            mdlScale(
                *(void **)(temp_16 + 0x10),
                D_005F12E0 + *(u8 *)(temp_5 + 0x1CA) * 0x30 +
                    *(u8 *)(temp_5 + 0x1CB) * 0xC,
                2);
        }
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        *(RwV3d *)(temp_2 + 0x30) = sp70;
        RwEngineGetMatrixTolerances(&sp30);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(temp_16 + 0x10)),
            &sp30);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)));
    }
}

// FUN_00168AE0
void FldFrameTask_SetPosition(u8 *arg0, u8 *arg1)
{
    RwV3d sp30;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(temp_16 + 0x10);
    if (temp_4 != 0) {
        temp_2 = (u8 *)mdlGetMatrix(temp_4);
        *(RwV3d *)(temp_2 + 0x30) =
            *(RwV3d *)(arg1 + 0x00);
        RwEngineGetMatrixTolerances(&sp30);
        RwMatrixOptimize(
            (u8 *)mdlGetMatrix(*(s32 *)(temp_16 + 0x10)),
            &sp30);
        RwMatrixUpdate(
            (u8 *)mdlGetMatrix(*(s32 *)(temp_16 + 0x10)));
        *(s32 *)(temp_16 + 0x40) =
            (s32)((600.0f +
                   *(f32 *)(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)) +
                            0x30)) /
                  1200.0f);
        *(s32 *)(temp_16 + 0x44) =
            (s32)((600.0f +
                   *(f32 *)(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)) +
                            0x38)) /
                  1200.0f);
    }
}

// FUN_00168C00
void FldFrameTask_UpdateTile(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_16 + 0x40) =
        (s32)((600.0f + *(f32 *)(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)) + 0x30)) /
              1200.0f);
    *(s32 *)(temp_16 + 0x44) =
        (s32)((600.0f + *(f32 *)(mdlGetMatrix(*(s32 *)(temp_16 + 0x10)) + 0x38)) /
              1200.0f);
}

// FUN_00168CB0
void FldFrameTask_StartMove(u8 *arg0, f32 fparg0)
{
    RwV3d sp30;
    u8 *var_4;
    s32 var_3;
    s32 var_4_2;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_4 = (u8 *)&sp30;
    var_3 = 0xC;
    if (var_4 != NULL) {
        do {
            *var_4 = 0;
            var_4 += 1;
            var_3 -= 1;
        } while (var_3 != 0);
    }
    if (*(s32 *)temp_16 == 1) {
        temp_2 = mdlGetMatrix(*(s32 *)(temp_16 + 0x10));
        sp30 = *(RwV3d *)(temp_2 + 0x20);
        RwV3dNormalize(&sp30, &sp30);
        sp30.x *= fparg0;
        sp30.y *= fparg0;
        sp30.z *= fparg0;
        if (!(2147483648.0f <= fparg0)) {
            var_4_2 = (s32)fparg0;
        } else {
            var_4_2 = (s32)(fparg0 - 2147483648.0f);
            var_4_2 |= (s32)0x80000000;
        }
        *(s32 *)(temp_16 + 0x38) += var_4_2;
        *(RwV3d *)(temp_16 + 0x18) = sp30;
        *(s32 *)temp_16 = 0;
    }
}

// FUN_00168DE0
void FldFrameTask_Rotate(u8 *arg0, const void *arg1, f32 fparg0) {
    RwV3d sp50;
    RwV3d sp40;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(temp_16 + 0x10);
    if (temp_4 != 0) {
        temp_2 = mdlGetMatrix(temp_4);
        sp50 = *(RwV3d *)(temp_2 + 0x30);
        sp40.x = -1.0f * sp50.x;
        sp40.y = -1.0f * sp50.y;
        sp40.z = -1.0f * sp50.z;
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(temp_16 + 0x10), &sp40, 2);
        mdlRotateMatrix((void *)(u32)*(s32 *)(temp_16 + 0x10), arg1, fparg0, 2);
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(temp_16 + 0x10), &sp50, 2);
    }
}

// FUN_00168EC0
s32 K_FldFrame_IsPointInTriangle(f32 *arg0, f32 **arg1, f32 *arg2)
{
    f32 abs_x;
    f32 abs_y;
    f32 abs_z;
    s32 axis;
    s32 prev;
    s32 result;



    result = 0;
    abs_x = fabsf(arg2[0]);
    abs_y = fabsf(arg2[1]);
    abs_z = fabsf(arg2[2]);
    axis = 0x7FFFFFFF;
    if (abs_z > abs_y) {
        axis = (abs_z > abs_x) ? 2 : 0;
    } else {
        if (abs_y > abs_x) {
            axis = 1;
        } else {
            axis = 0;
        }
    }
    if (axis != 0x7FFFFFFF) {
        prev = 2;
        switch (axis) {
        case 0: {
            f32 coord;
            s32 i;
            i = 0;
            coord = arg0[1];
            while (i < 3) {
                if ((arg1[i][1] <= coord && coord < arg1[prev][1]) ||
                    (arg1[prev][1] <= coord && coord < arg1[i][1])) {
                    if (arg0[2] <
                        arg1[i][2] +
                            ((coord - arg1[i][1]) *
                             (arg1[prev][2] - arg1[i][2])) /
                                (arg1[prev][1] - arg1[i][1])) {
                        result = !result;
                    }
                }
                prev = i;
                i += 1;
            }
            break;
        }
        case 1: {
            f32 coord;
            s32 i;
            i = 0;
            coord = arg0[2];
            while (i < 3) {
                if ((arg1[i][2] <= coord && coord < arg1[prev][2]) ||
                    (arg1[prev][2] <= coord && coord < arg1[i][2])) {
                    if (arg0[0] <
                        arg1[i][0] +
                            ((coord - arg1[i][2]) *
                             (arg1[prev][0] - arg1[i][0])) /
                                (arg1[prev][2] - arg1[i][2])) {
                        result = !result;
                    }
                }
                prev = i;
                i += 1;
            }
            break;
        }
        case 2: {
            f32 coord;
            s32 i;
            i = 0;
            coord = arg0[1];
            while (i < 3) {
                if ((arg1[i][1] <= coord && coord < arg1[prev][1]) ||
                    (arg1[prev][1] <= coord && coord < arg1[i][1])) {
                    if (arg0[0] <
                        arg1[i][0] +
                            ((coord - arg1[i][1]) *
                             (arg1[prev][0] - arg1[i][0])) /
                                (arg1[prev][1] - arg1[i][1])) {
                        result = !result;
                    }
                }
                prev = i;
                i += 1;
            }
            break;
        }
    }
    }
    return result;
}

