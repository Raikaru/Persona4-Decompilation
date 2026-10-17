/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00189600-0018bf50 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
#include "rw_types_internal.h"
typedef RwV3d RainVector;

#include "scene_event_internal.h"
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*jtbl_008873EC[])(void *);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *handle);
extern void func_003e0f40(s32 arg0);
extern s32 *MT_Scene_GetFrameState(void);
extern void FldRc_SetPositionSlotLock(s32 a, s32 b, s32 c);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8218;
extern s16 mdlGetLayerAnimation(s32 arg0, s32 arg1);
extern u8 *mdlGetMatrix(u32 arg0);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern u8 *K_ClumpLookAtBasis(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern s32 FldNpcControlUpdate(u8 *task);
extern f32 sinf(f32 arg0);
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern s32 frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern s32 FldPanel2dUpdate(u8 *arg0);
extern void FldPanel2dSelectEntry(s32 arg0);
extern s32 func_003bfae0();
extern s32 kwlnGetCamera(void);
extern s32 RwCameraFrustumTestSphere(u8 *arg0, s32 arg1);
extern s32 FldStepIndex(void);
extern u8 *iGpffff9db0;
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189600
void FldLmapCameraMoveTo(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 v32[4];
    f32 v31[4];
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_18;
    u8 *temp_16_2;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    kwlnGetCamera();
    temp_4 = *(s32 *)temp_17;
    if ((temp_4 != 1) || (*(s32 *)(temp_17 + 0x30) != arg2)) {
        if (fparg0 != 0.0f) {
            *(s32 *)(temp_17 + 0x2C) = arg1;
            *(s32 *)(temp_17 + 0x30) = arg2;
            temp_16 = arg2 * 0x18;
            v32[0] = *(f32 *)((u8 *)D_005F2190 + temp_16) -
                     *(f32 *)(temp_17 + 4);
            v32[1] = *(f32 *)((u8 *)D_005F2194 + temp_16) -
                     *(f32 *)(temp_17 + 8);
            v32[2] = *(f32 *)((u8 *)D_005F2198 + temp_16) -
                     *(f32 *)(temp_17 + 0xC);
            temp_f20 = RwV3dNormalize((RainVector *)&v32[0], (const RainVector *)&v32[0]);
            v31[0] = *(f32 *)((u8 *)D_005F219C + temp_16) -
                     *(f32 *)(temp_17 + 0x10);
            v31[1] = *(f32 *)((u8 *)D_005F21A0 + temp_16) -
                     *(f32 *)(temp_17 + 0x14);
            v31[2] = *(f32 *)((u8 *)D_005F21A4 + temp_16) -
                     *(f32 *)(temp_17 + 0x18);
            temp_f0 = RwV3dNormalize((RainVector *)&v31[0], (const RainVector *)&v31[0]);
            if (!(temp_f20 <= temp_f0)) {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f20 / fparg0) + 1;
            } else {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f0 / fparg0) + 1;
            }
            *(f32 *)(temp_17 + 0x1C) =
                temp_f20 / (f32)*(s32 *)(temp_17 + 0x28);
            *(f32 *)(temp_17 + 0x20) =
                temp_f0 / (f32)*(s32 *)(temp_17 + 0x28);
            *(s32 *)(temp_17 + 0x24) = 0;
            *(s32 *)temp_17 = 2;
            return;
        }
        *(s32 *)(temp_17 + 0x30) = arg2;
        temp_3 = arg2 * 0x18;
        temp_18 = (u8 *)D_005F2190 + temp_3;
        *(struct Vec3 *)(temp_17 + 4) = *(struct Vec3 *)temp_18;
        temp_16_2 = (u8 *)D_005F219C + temp_3;
        *(struct Vec3 *)(temp_17 + 0x10) = *(struct Vec3 *)temp_16_2;
        K_ClumpLookAtBasis(((u8 *)(uintptr_t)kwlnGetCamera()), temp_18, temp_16_2, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189870
#pragma opt_propagation off
void FldSkyApplyDefaultPreset(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 1);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189940
/* Measured: 1348 executable bytes, 26 resolved relocations, 12 zero tail bytes.
 * Preserve integer-to-float conversions and reloads across rendering callbacks.
 * Indexed addresses stay integer-valued until their final pointer conversion. */
#pragma opt_loop_invariants on
s32 FldPanel2dUpdate(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f1;
    f32 temp_f0;
    s32 i;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }

    switch (*(s32 *)temp_16) {
    case 0:
        temp_f2 = D_008872F8[0] - (f32)58980;
        temp_f3 = 1.0f / temp_f2;
        *(s32 *)(temp_16 + 8) = 0;
        *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f;
        *(f32 *)(temp_16 + 0x20) = 0.0f;
        temp_f1 = (f32)401;
        *(f32 *)(temp_16 + 0x24) = temp_f1;
        *(f32 *)(temp_16 + 0x28) = temp_f2;
        *(f32 *)(temp_16 + 0x60) = 25.0f;
        *(f32 *)(temp_16 + 0x64) = temp_f1;
        *(f32 *)(temp_16 + 0x68) = temp_f2;
        *(f32 *)(temp_16 + 0xA0) = 0.0f;
        temp_f0 = (f32)427;
        *(f32 *)(temp_16 + 0xA4) = temp_f0;
        *(f32 *)(temp_16 + 0xA8) = temp_f2;
        *(f32 *)(temp_16 + 0xE0) = 25.0f;
        *(f32 *)(temp_16 + 0xE4) = temp_f0;
        *(f32 *)(temp_16 + 0xE8) = temp_f2;
        *(f32 *)(temp_16 + 0x120) = 326.0f;
        *(f32 *)(temp_16 + 0x124) = temp_f1;
        *(f32 *)(temp_16 + 0x128) = temp_f2;
        *(f32 *)(temp_16 + 0x160) = 660.0f;
        *(f32 *)(temp_16 + 0x164) = temp_f1;
        *(f32 *)(temp_16 + 0x168) = temp_f2;
        *(f32 *)(temp_16 + 0x1A0) = 326.0f;
        *(f32 *)(temp_16 + 0x1A4) = temp_f0;
        *(f32 *)(temp_16 + 0x1A8) = temp_f2;
        *(f32 *)(temp_16 + 0x1E0) = 660.0f;
        *(f32 *)(temp_16 + 0x1E4) = temp_f0;
        *(f32 *)(temp_16 + 0x1E8) = temp_f2;
        for (i = 0; i < 4; i++) {
            temp_2 = temp_16 + (i << 6);
            *(f32 *)(temp_2 + 0x38) = temp_f3;
            *(f32 *)(temp_2 + 0x138) = temp_f3;
            *(f32 *)(temp_2 + 0x40) = 255.0f;
            *(f32 *)(temp_2 + 0x44) = 0.0f;
            *(f32 *)(temp_2 + 0x48) = 0.0f;
            *(f32 *)(temp_2 + 0x4C) = 0.0f;
            *(f32 *)(temp_2 + 0x140) = 255.0f;
            *(f32 *)(temp_2 + 0x144) = 0.0f;
            *(f32 *)(temp_2 + 0x148) = 0.0f;
            *(f32 *)(temp_2 + 0x14C) = 0.0f;
        }
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        *(f32 *)(temp_16 + 0x22C) = sinf((D_00761184 * (f32)*(s32 *)(temp_16 + 0x220)) / 10.0f);
        if (*(s32 *)(temp_16 + 0x220) < 10) {
            *(s32 *)(temp_16 + 0x220) += 1;
        } else {
            *(s32 *)temp_16 += 1;
        }
        *(f32 *)(temp_16 + 0x224) = (-300.0f + 0.0f) + 316.0f * *(f32 *)(temp_16 + 0x22C);
        *(f32 *)(temp_16 + 0x228) = ((f32)371 + 0.0f) + 30.0f * *(f32 *)(temp_16 + 0x22C);
        /* fallthrough */
    case 2:
        func_00366380((s32)*(f32 *)(temp_16 + 0x224), (s32)*(f32 *)(temp_16 + 0x228), (f32)59000, 301, 26, 0xFAFF20, 255, 1, 150, 13, D_00794C60, -5.0f, 1.0f, 1.0f);
        func_00366380(25, 401, (f32)59000, 301, 26, 0x191919, 255, 1, 150, 13, D_00794C60, 0.0f, 1.0f, *(f32 *)(temp_16 + 0x22C));
        if (!(*(f32 *)(temp_16 + 0x22C) < 1.0f)) {
            if (*(s32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x10)) != 0) {
                temp_f0 = sinf((D_00761184 * (f32)*(s32 *)(temp_16 + 0xC)) / 10.0f);
                *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f + 336.0f * temp_f0;
                *(f32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x18)) = -161.0f + 336.0f * temp_f0;
                if (*(s32 *)(temp_16 + 0xC) < 10) {
                    *(s32 *)(temp_16 + 0xC) += 1;
                } else {
                    *(s32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x10)) = 0;
                    *(s32 *)(temp_16 + 8) = !(u32)*(s32 *)(temp_16 + 8);
                }
            }
            temp_2 = PrimQueueDrawPrimitive(D_00794C60, 4, temp_16 + 0x20, 4);
            *(void (**)(void))(temp_2 + 8) = FldSkyApplyDefaultPreset;
            *(s32 *)(temp_2 + 0x10) = 0;
            PrimQueueDrawPrimitive(D_00794C60, 4, temp_16 + 0x120, 4);
            if (*(const char **)(temp_16 + 0x10) != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)*(f32 *)(temp_16 + 0x18), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x10), 8, 0, D_00794C60, -1);
            }
            if (*(const char **)(temp_16 + 0x14) != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)*(f32 *)(temp_16 + 0x1C), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x14), 8, 0, D_00794C60, -1);
            }
        }
        break;
    case 3:
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189E90
void FldPanel2dDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189EC0
void FldPanel2dTaskCreate(void)
{
    u8 *temp_16;
    u8 *temp_2;
    s32 var_16;
    if (((FldFrame *)MT_Scene_GetFrameState())->panelTask == 0) {
        temp_16 = *(u8 **)MT_Scene_GetFrameState();
        chkmemAllocSiteTag(&D_005F5320, 0x17C);
        temp_2 = D_008873F4[0](1, 0x230, 0x40000);
        if (temp_2 == NULL) {
            var_16 = 0;
        } else {
            var_16 = (s32)kwlnTaskCreateChild((void *)(temp_16), (const void *)(&D_005F5330), 0xF, 0, 0, FldPanel2dUpdate, FldPanel2dDestroy, (u8 *)(temp_2));
        }
        ((FldFrame *)MT_Scene_GetFrameState())->panelTask = (u8 *)var_16;
        FldPanel2dSelectEntry(-1);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189FA0
s32 FldPanel2dRelease(void) {
    if (((FldFrame *)MT_Scene_GetFrameState())->panelTask == 0) {
        return 0;
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)((FldFrame *)MT_Scene_GetFrameState())->panelTask);
    ((FldFrame *)MT_Scene_GetFrameState())->panelTask = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A000
void FldPanel2dSetState(u8 *arg0, s32 arg1)
{
    ((FldPanel2dWork *)*(u8 **)(arg0 + 0x38))->hidden = arg1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A010
void FldPanel2dSelectEntry(s32 arg0)
{
    extern u8 D_005F2210[];
    extern u8 D_005F4090[];
    extern u8 D_005F51E0[];
    s32 mode;
    s32 *save;
    s32 *entry;
    s32 index;
    u8 *base;
    u8 *work;
    s32 slot;
    u8 *p;

    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) == 0) {
        return;
    }
    if (arg0 == -1) {
        mode = FldStepIndex();
        if (mode == 0) {
            index = 0;
            save = (s32 *)iGpffff9db0;
            if (*save >= 0x28) {
                p = NULL;
            } else {
                entry = (s32 *)(D_005F51E0 + *save * 4);
                if (*entry != 0) {
                    index = *(u16 *)((u8 *)*entry + *(save + 1) * 2);
                }
                p = D_005F2210 + index * 0x1A;
            }
        } else {
            p = D_005F4090 + mode * 0x1B;
        }
        base = p;
    } else {
        base = D_005F2210 + arg0 * 0x1A;
    }
    work = *(u8 **)(*(u8 **)((u8 *)MT_Scene_GetFrameState() + 0x30) + 0x38);
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(u8 **)(slot + (s32)work + 0x10) = base;
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(s32 *)(slot + (s32)work + 0x18) = (s32)0xC3210000;
    *(s32 *)(work + 0xC) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A170
s32 FldRcAtomicFrustumTest(s32 arg0, s32 *arg1)
{
    u8 *temp_16;

    func_003bfae0();
    temp_16 = ((u8 *)(uintptr_t)kwlnGetCamera());
    if (RwCameraFrustumTestSphere(temp_16, func_003bfae0(arg0)) != 0) {
        *arg1 = 1;
        return 0;
    }
    return arg0;
}
#pragma pop

extern unsigned int D_007EFA00[];
extern void FldNpcSetPositionLock(unsigned char *, s32);
extern s32 func_0018bf50(unsigned char *);
extern s32 kwlnGetCamera(void);
extern s16 mdlGetLayerAnimation(s32, s32);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BAD0
void FldNpcControlDestroy(u8 *arg0) {
    s32 h = ((FldNpcControlWork *)*(u8 **)(arg0 + 0x38))->handle;

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BB20
s32 FldNpcControlTaskCreate(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_2;

    chkmemAllocSiteTag(&D_005F5340, 0x2E6);
    temp_2 = D_008873F4[0](1, 0x58, 0x40000);
    if (temp_2 == NULL)
        return 0;
    temp_17 = (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(&D_005F5350), 0xF, 0, 0, FldNpcControlUpdate, FldNpcControlDestroy, (u8 *)(temp_2));
    ((FldNpcControlWork *)temp_2)->actor = arg1;
    ((FldNpcControlWork *)temp_2)->cameraHeight = *(f32 *)(((u8 *)(uintptr_t)kwlnGetCamera()) + 0x80);
    return temp_17;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BBF0
s32 FldNpcControlReady(u8 *arg0)
{
    u32 value;

    if (arg0 == NULL) {
        return 1;
    }
    value = ((FldNpcControlWork *)*(u8 **)(arg0 + 0x38))->state;
    return value >= 4;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Shared animation contracts: CSE retains the common transition constant.
 * The O1 profile still preserves the retail FPU accumulator order. */
// FUN_0018BC20
/* measured: optimization_level 1 preserves retail's FPU scheduling for this
   vector normalize; -O2 reorders it into a mismatching form. */
#pragma optimization_level 1
#pragma push
#pragma opt_common_subs on
void FldNpcControlFacePlayer(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *temp_4;
    f32 *temp_4_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    u8 *temp_16;
    u8 *temp_2;
    void *target;
    s32 zero;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = mdlGetMatrix(*(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164));
    temp_4 = (f32 *)(temp_16 + 0x30);
    *(struct Vec3 *)temp_4 = *(struct Vec3 *)(temp_2 + 0x20);
    RwV3dNormalize((RainVector *)temp_4, (const RainVector *)temp_4);
    temp_f20 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x30);
    *(f32 *)(temp_16 + 0x3C) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x30) - temp_f20;
    temp_f20_2 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x34);
    *(f32 *)(temp_16 + 0x40) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x34) - temp_f20_2;
    temp_f20_3 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x38);
    *(f32 *)(temp_16 + 0x44) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x38) - temp_f20_3;
    temp_4_2 = (f32 *)(temp_16 + 0x3C);
    RwV3dNormalize((RainVector *)temp_4_2, (const RainVector *)temp_4_2);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) +
        guard38 * guard44 <
        fGpffff8218) {
        *(s32 *)(temp_16 + 0x2C) =
            (s16)mdlGetLayerAnimation(*(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164), 0);
        target = *(void **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        *(s32 *)temp_16 = 5;
        return;
    }
    mdlDispatchAnimIfPresent(*(void **)(*(u8 **)(temp_16 + 0xC) + 0x164), 0, 3, 8, 0);
    *(s32 *)temp_16 = 7;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Copy the complete direction vector when starting the transition. The
 * aggregate retains all three source loads with shared constants enabled. */
// FUN_0018BDD0
#pragma push
#pragma opt_common_subs on
void FldNpcControlTurnBack(u8 *arg0)
{
    struct Direction {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_16;
    u8 *target;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    s32 zero;

    temp_16 = *(u8 **)(arg0 + 0x38);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) + guard38 * guard44 <
        fGpffff8218) {
        *(struct Direction *)(temp_16 + 0x3C) = *(struct Direction *)(temp_16 + 0x30);
        target = *(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        *(s32 *)temp_16 = 6;
        return;
    }
    mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164),
                  0, 0, 8, 1);
    *(s32 *)temp_16 = 4;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BED0
void FldNpcSetPositionLock(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + *(s32 *)(p + 0x50) * 4 + 0x34) == 0) {
        return;
    }
    FldRc_SetPositionSlotLock(*(s32 *)((u8 *)MT_Scene_GetFrameState() + *(s32 *)(p + 0x50) * 4 + 0x34),
                  *(s32 *)(p + 0x54), arg1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BF50
s32 func_0018bf50(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 r = 0;
    s32 v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    if (*(u16 *)(*(u8 **)(p + 0xC) + 0x220) == 3) {
        if (*(s32 *)(p + 0x24) > 0) {
            r = 1;
        }
    }
    return r;
}
#pragma pop
