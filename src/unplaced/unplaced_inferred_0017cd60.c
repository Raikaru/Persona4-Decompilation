/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0017cd60-0017d240 */

#include "mt_scene_internal.h"
#include "field_frame_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;

extern void *memset(void *dst, s32 value, s32 size);
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern s32 FldPlayerIconUpdate(u8 *arg0);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sinf(f32 arg0);
extern u8 *resourceFindByName(char *arg0);
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];
extern u8 *kwlnGetCamera(void);
extern void *mdlGetMatrix(void *arg0);
extern void func_003e42a0(void *dst, void *src, u8 *arg2);
extern u8 D_007EFA00[];
extern void sprintf(void *dst, const void *src);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 arg0, void *arg1);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern s32 D_005F1930[];
extern s32 D_005F1934[];
/* measured: best plain-C body is 108B in the 112B retail window (112B),
   normalized_diff 4; the sole residual bytes at offset 56 are retail
   `andi $a3,$s1,0xffff` versus candidate `move $a3,$s1`. The file-scope
   Encount_PickEncounter declaration remains (u16, u16, u16, s32) for matching
   FldUnit_SpawnEncounter. Probed a block-scope fourth-parameter u16 prototype at
   the function top, after locals, in an inner block, unnamed, and with
   explicit narrowed locals/casts: each moved the mask before the two lhu
   loads (nd 10); mixed third s32/fourth u16 gave nd 6. O1, schedule off,
   and function-pointer casts did not improve it. Best body remains archived
   at build/D178_00178870_body.c; committed form is bare INCLUDE_ASM. */

/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). That span and its helpers
   0x0017ACC0 and 0x0017B350 now live in src/Kosaka/k_shadow.c. The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0 and is not merged with it. */

#include "rw_types_internal.h"
#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
/* 764/768 bytes; fourteen resolved relocations; four zero alignment bytes.
 * Preserve unsigned frame updates and the three ordered sprite draws. */
// FUN_0017CD60
s32 FldPlayerIconUpdate(u8 *arg0)
{
    u8 *work;
    f32 easing;
    f32 inverse;
    f32 frame;
    s32 opacity;
    u16 counter;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 8) = (s32)resourceFindByName(D_005E5850);
        *(u16 *)(work + 0xC) = 320;
        *(u16 *)(work + 0xE) = 240;
        *(s32 *)work = *(s32 *)work + 1;
        goto done;
    case 1:
        counter = *(u16 *)(work + 0x10);
        frame = (f32)(u16)counter;
        easing = sinf((iGpffff82fc * frame) / 15.0f);
        inverse = 1.0f - easing;
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 10),
                      (f32)(*(u16 *)(work + 0xE) + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        opacity = (s32)(128.0f * easing) + 0x80;
        x = (f32)(*(u16 *)(work + 0xC) + 0x6E);
        y = (f32)(*(u16 *)(work + 0xE) + 0x22);
        opacity = (0xFF < opacity) ? 0xFF : opacity;
        sdkSpriteDrawQueued(x, y, 1000.0f,
                      0xFFFFFF, opacity & 0xFF, 0xC6, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 0x6E),
                      (f32)(*(u16 *)(work + 0xE) + 0xF +
                            (s32)(3.0f * inverse)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        counter = *(u16 *)(work + 0x10) + 1;
        *(u16 *)(work + 0x10) = counter;
        if (0xF < *(u16 *)(work + 0x10)) {
            *(u16 *)(work + 0x10) = 0;
        }
        goto done;
    case 2:
        return -1;
    default:
        goto done;
    }
done:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D060
void FldPlayerIconDestroy(u8 *arg0)
{
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D070
s32 FldPlayerIconTaskCreate(u8 *arg0)
{
    memset(D_007F1740, 0, 0x20);
    return (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1950), 0x12, 0, 0, FldPlayerIconUpdate, FldPlayerIconDestroy, (u8 *)(D_007F1740));
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D0F0
void FldPlayerIconSetActive(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D100
void FldPlayerIconUpdatePos(u8 *arg0)
{
    F2_0017 sp30;
    f32 temp_f1;
    s32 temp_17;
    s32 temp_4;
    s32 var_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = (s32)(kwlnGetCamera() + 0x20);
    func_003e42a0(&sp30, (u8 *)mdlGetMatrix(*(u8 **)D_007EFA00) + 0x30, (u8 *)temp_17);
    temp_f1 = 640.0f * (sp30.first / sp30.second);
    if (temp_f1 <= 100.0f) {
        var_3 = 0;
    } else if (temp_f1 < 540.0f) {
        var_3 = 1;
    } else {
        var_3 = 2;
    }
    temp_4 = var_3 * 8;
    *(s16 *)(temp_16 + 0xC) = *(s32 *)((u8 *)D_005F1930 + temp_4);
    *(s16 *)(temp_16 + 0xE) = *(s32 *)((u8 *)D_005F1934 + temp_4);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D1F0
void FldSmapTileQueueByType(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                   f32 arg5, f32 arg6, f32 arg7, s32 arg4)
{
    s32 temp_3;

    temp_3 = arg2 * 8;
    FldSmapTileQueueQuad(arg0, arg1, arg2, arg3,
                  *(s32 *)(D_005F1A60 + temp_3) + 1,
                  *(s32 *)(D_005F1A64 + temp_3) + 1, arg4,
                  arg5, arg6, arg7);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma optimization_level 1
// FUN_0017D240
void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9)
{
    struct {
        u8 data[0x10];
        u8 tail[0x10];
    } spA0;
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_6;
    s32 local_5;
    s32 local_4;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21 = (f32)arg4;
    f32 temp_f20 = (f32)arg5;
    f32 *temp_9;
    s32 temp_2;
    s32 temp_1;
    s32 temp_18;
    local_0 = arg0;
    local_1 = arg1;
    local_2 = arg2;
    temp_f24 = arg7;
    temp_f23 = arg8;
    temp_f22 = arg9;
    local_6 = arg4;
    local_5 = arg5;
    local_4 = arg6;
    if (arg3 == 0) {
        sprintf(spA0.data, D_005F1AE0);
    } else {
        sprintf(spA0.data, D_005F1B00);
    }
    temp_18 = local_2 * 0x10;
    temp_f21 = (f32)local_6;
    temp_f20 = (f32)local_5;
    temp_1 = func_003ef6d0();
    temp_2 = func_003ef650(temp_1, spA0.data);
    FldRc_QueueScreenQuad(local_0, local_1,
                  temp_f24, temp_f23, temp_f22, temp_f21, temp_f20,
                  (void *)&iGpffff9f54, temp_2,
                  *(f32 *)(temp_9 = (f32 *)(D_005F1970 + temp_18)),
                  *(f32 *)(D_005F1974 + temp_18),
                  *(f32 *)(D_005F1978 + temp_18),
                  local_4, temp_9,
                  *(f32 *)(D_005F197C + temp_18));
}
#pragma pop
