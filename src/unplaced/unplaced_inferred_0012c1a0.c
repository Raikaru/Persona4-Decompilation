/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0012c1a0-0012c460 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void (*jtbl_008873EC[])(void *);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern s32 shdWindowTaskCreate(u8 *arg0, s32 arg1, s32 arg2);
extern void shdWindowMarkDone(s32 arg0);
extern s32 shdWindowQueryState(s32 arg0);
extern s32 kwlnTaskIsLinked();
extern void *kwlnTaskGetWork();
extern void kwlnTaskDestroyWithHierarchy();
typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;

extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005E57B8[];
extern u8 D_005E57D0[];
extern s32 titleSoundStartStep(u8 *arg0);
#include "btl_shuffle_draw_internal.h"
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (kwlnTaskIsLinked() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(kwlnTaskGetWork(arg0));
    if (temp_2->field_4 != 0) {
        kwlnTaskDestroyWithHierarchy(arg0);
    }
    return temp_2->field_4;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012C220
s32 titleSoundStartStep(u8 *arg0) {
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        if ((hsndSlotIsStarting(0) != 0) && (hsndSlotIsStarting(1) != 0)) {
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    default:
        goto block_20;
    case 1:
        *(s32 *)(temp_16 + 0xC) = shdWindowTaskCreate(arg0, 1, 0xF);
        *(s32 *)(temp_16 + 8) = 0x3C;
        *(u32 *)(temp_16 + 0) = 2U;
        goto block_20;
    case 2:
        temp_2_2 = *(s32 *)(temp_16 + 8) - 1;
        *(s32 *)(temp_16 + 8) = temp_2_2;
        if (temp_2_2 == 0) {
            H_Memcard_Reset();
            *(u32 *)(temp_16 + 0) = 3U;
        }
        goto block_20;
    case 3:
        temp_2_3 = H_Memcard_CreateSlotsStep();
        *(s32 *)(temp_16 + 4) = temp_2_3;
        if (temp_2_3 != 0) {
            if (temp_2_3 == 0x64) {
                shdWindowMarkDone(*(s32 *)(temp_16 + 0xC));
                return -1;
            }
            *(u32 *)(temp_16 + 0) = 4U;
            goto block_20;
        }
        goto block_20;
    case 4:
        shdWindowMarkDone(*(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 4) == -6) {
            *(s32 *)(temp_16 + 0xC) = shdWindowTaskCreate(arg0, 1, 0x15);
        } else {
            *(s32 *)(temp_16 + 0xC) = shdWindowTaskCreate(arg0, 1, 0x10);
        }
        *(u32 *)(temp_16 + 0) = 5U;
        goto block_20;
    case 5:
        temp_2_4 = shdWindowQueryState(*(s32 *)(temp_16 + 0xC));
        if (temp_2_4 == 1) {
            shdWindowMarkDone(*(s32 *)(temp_16 + 0xC));
            return -1;
        }
        if (temp_2_4 == 2) {
            shdWindowMarkDone(*(s32 *)(temp_16 + 0xC));
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    }
block_20:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012C410
void titleSoundStartDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    func_001029a0(1, 0, 0, 5);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012C460
s32 titleStartSoundTask(s32 arg0) {
    s32 var_2;
    u8 *temp_2;

    chkmemAllocSiteTag(D_005E57B8, 0x74);
    temp_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    var_2 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005E57D0), 0xF, 0, 0, titleSoundStartStep, titleSoundStartDestroy, (u8 *)(temp_2));
    if (var_2 == 0) {
        return 0;
    }
    return var_2;
}
#pragma pop
