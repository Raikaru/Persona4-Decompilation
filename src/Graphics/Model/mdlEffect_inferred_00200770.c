#include "btl_skill_target_internal.h"
#include "list_item_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
typedef struct BtlPacket BtlPacket;
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "fr_font_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
typedef struct BtlUnit BtlUnit;
typedef struct BtlAction BtlAction;

extern void func_00113500(void);



typedef struct {
    u8 pad0[2];
    s16 field2;
    s16 field4;
    s16 field6;
    s16 field8;
} P4_00202D20;
static inline f32 func_0020_mul(f32 left, f32 right)
{
    return left * right;
}
static inline u8 *p4_002091f0_add(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];





extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];

extern u8 D_00625240[];
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
typedef void (*BattleSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *state, f32 x, f32 y,
                         BattleSelectionDraw drawSelection);

extern void btlSelectionDrawList(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          BattleSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 show_detail);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;
typedef struct {
    s32 value3;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 pad[0xC];
    Color4 colors;
} Work4;
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlCameraSetState(s32 state, BtlAction *action, u32 param_3);
extern void func_001bcd40(u8 *arg1, u8 *arg2, f32 *arg3, f32 arg0, u16 arg4);
extern u8 *btlActionFindByUnit(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void btlUnitSetPos(void *arg0, void *arg1);
extern void btlUnitSetRot(void *arg0, void *arg1);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern u8 D_006253B0[];

/* Source unit: src/promoted/code1_0020.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0020.c; members 00200770-00200c50 */

// Intent: advance the battle model curve and update the model matrix from the curve state. [inferred]
// FUN_00200770
void btlUiUpdateModelCurve(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 sp40;
        Vec3 sp4C;
        u8 pad18[8];
        u8 sp60[0x10];
        u8 sp70[0x20];
        u8 sp90[0x40];
        u8 spD0[0x10];
        u8 spE0[0x40];
        Vec3 sp120;
    } Frame;
    extern void func_001bcd40(u8 *arg1, u8 *arg2, f32 *arg3, f32 arg0, u16 arg4);
    extern u16 btlCameraGetState(void);
    extern void func_0048a150(void *arg0, void *arg1);
    extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
    extern void mdlScale(void *arg0, f32 *arg1, s32 arg2);
    extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
    extern void mdlAdvanceModelFromFlags(void *arg0);
    extern s32 mdlCopyIndexedMatrix(void *arg0, s32 arg1, void *arg2);
    extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
    extern void btlMainCurveReset(u16 *arg0, f32 *arg1);
    extern u8 *iGpffffb474;
    Frame frame;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_4;
    u32 temp_3;
    f32 temp_f0;

    temp_17 = *(u8 **)(arg0 + 0x30);
    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u32 *)(arg0 + 0x28);
    temp_3 = *(u32 *)(temp_16 + 0x2C);
    if ((temp_3 >= temp_4) || (temp_3 == 0)) {
        if (temp_4 == 0) {
            if (*(u16 *)(temp_16 + 0x38) == 0) {
                btlCameraSetState(1, NULL, 1);
                func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
            } else {
                btlCameraSetState(1, NULL, 0);
            }
        }
        if (((btlCameraGetState() & 0xFFFF) == 1) && (*(s32 *)temp_17 != 0)) {
            func_0048a150(frame.spE0, arg0 + 0x10);
            mdlApplyModelMatrix(*(u8 **)temp_17, frame.spE0, 0);
            temp_f0 = *(f32 *)(arg0 + 0x20) * *(f32 *)(temp_16 + 0x34);
            frame.sp120.z = temp_f0;
            frame.sp120.y = temp_f0;
            frame.sp120.x = temp_f0;
            mdlScale(*(u8 **)temp_17, &frame.sp120.x, 2);
            frame.sp120.x = *(f32 *)(arg0 + 0);
            frame.sp120.y = *(f32 *)(arg0 + 4);
            frame.sp120.z = *(f32 *)(arg0 + 8);
            mdlTranslateMatrix((RwMatrix *)*(u8 **)temp_17, (const RwV3d *)&frame.sp120, 2);
            mdlSetLayerWeight(*(u8 **)temp_17, 0, *(f32 *)(temp_16 + 0x30));
            mdlAdvanceModelFromFlags(*(u8 **)temp_17);
            mdlCopyIndexedMatrix(*(u8 **)temp_17, *(u16 *)(temp_17 + 4), frame.sp60);
            mdlCopyIndexedMatrix(*(u8 **)temp_17, *(u16 *)(temp_17 + 4) + 1, frame.sp90 + 0x10);
            frame.sp40 = *(Vec3 *)frame.sp90;
            btlCameraLookAtQuat(&frame.sp4C, frame.sp90, frame.spD0, frame.sp70);
            btlMainCurveReset((u16 *)(iGpffffb474 + 0x24), (f32 *)(&frame.sp40));
        }
    }
}

// Intent: reset the overlay scale field to its default value. [inferred]
// FUN_00200960
void btlUiResetOverlayScale(void) {
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
}

/* measured: clean-C body is byte-exact in the current TU (object/window 208B, normalized_diff 0). */
// Intent: set the overlay scale from the progress ratio of the current and total counters. [inferred]
// FUN_00200980
void btlUiUpdateOverlayScale(u8 *arg0)
{
    s32 temp_3;
    s32 temp_5;
    u8 *temp_6;
    f32 var_f1;
    f32 var_f0;
    f32 temp_f2;

    temp_6 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(arg0 + 0x28);
    temp_5 = *(s32 *)(temp_6 + 0);
    if ((temp_5 == 0) || ((u32)temp_5 < (u32)temp_3)) return;
    temp_f2 = *(f32 *)(temp_6 + 4);
    var_f1 = (f32)(u32)temp_3;
    var_f0 = (f32)(u32)temp_5;
    var_f1 /= var_f0;
    var_f0 = *(f32 *)(temp_6 + 8) - temp_f2;
    var_f0 = func_0020_mul(var_f1, var_f0);
    var_f1 = var_f0 + temp_f2;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff81a8 * var_f1;
}

// FUN_00200A50
void func_00200a50(void)
{
}

// Intent: re-apply position and rotation to the living units of both sides. [inferred]
// FUN_00200A60
void btlUiRefreshUnitPositions(u8 *arg0)
{
    u8 sp40[0x10];
    u8 sp30[0x10];
    s32 temp_4;
    s32 temp_4_2;
    u32 var_16;
    u8 *temp_16;
    u8 *var_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(arg0 + 0x28) != 0) {
        goto done;
    }
    btlCameraSetState(1, NULL, 1);
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
    temp_4 = *(s32 *)(temp_16 + 0);
    switch (temp_4) {
    case 0:
        btlCameraSetState(0x2C, NULL, 1);
        break;
    case 1:
        btlCameraSetState(0x2D, NULL, 1);
        break;
    case 2:
        btlCameraSetState(0x2E, (BtlAction *)btlActionFindByUnit(D_00881444_abs[0]), 1);
        break;
    case 3:
        btlCameraSetState(6, (BtlAction *)btlActionFindByUnit(D_00881444_abs[0]), 1);
        break;
    }
    if (*(u8 *)(temp_16 + 4) == 0) {
        goto done;
    }
    var_16 = 0;
    goto loop_19_test;
loop_19_body:
    var_17 = *(u8 **)(iGpffffb3ac + var_16 * 8 + 0x178);
    goto loop_17_test;
loop_17_body:
    temp_4_2 = *(s32 *)(var_17 + 0xA64);
    if ((temp_4_2 != 0) && (datCalcIsDead(temp_4_2, 0) == 0)) {
        func_00194ff0(var_17, sp40, sp30, NULL);
        btlUnitSetPos(var_17, sp40);
        btlUnitSetRot(var_17, sp30);
        btlUnitUpdateStatusMotion(var_17, 0);
        func_00198920(var_17, *(s16 *)(var_17 + 0x9EC), 0, *(f32 *)(var_17 + 0x9F0), *(s8 *)(var_17 + 0x9F4));
    }
    var_17 = *(u8 **)(var_17 + 0xA6C);
loop_17_test:
    if (var_17 != NULL) {
        goto loop_17_body;
    }
    var_16 += 1;
loop_19_test:
    if (var_16 < 2U) {
        goto loop_19_body;
    }
done:
    ;
}

// FUN_00200C50
void func_00200c50(void)
{
    func_00113500();
}

