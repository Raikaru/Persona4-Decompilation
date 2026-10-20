#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"

extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern u32 datGetMoney(void);
extern void datSetMoney(s32 amount);
extern s32 iGpffffb480;




extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);







/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 0025d000-0025d090 */

// Intent: Common script command ADD_PC_MONEY (p4flow Common 0x0050): adds money, clamped to 9,999,999 and at least zero [inferred]
// FUN_0025D000
s32 scrCommonAddPcMoney(void) {
    s32 currentMoney;
    s32 newMoney;
    currentMoney = datGetMoney();

    newMoney = currentMoney + scrGetParamInt(0);
    if (newMoney <= 0x0098967F) {
        goto block_1;
    }
    newMoney = 0x0098967FU;
block_1:
    if (newMoney < 0) {
        newMoney = 0;
    }
    datSetMoney(newMoney);
    scrSetReturnInt(datGetMoney());
    return 1;
}

// Intent: Common script command CALL_NAME_ENTRY (p4flow Common 0x0051): opens the name entry screen (mode 0x1C) [inferred]
// FUN_0025D090
s32 scrCommonCallNameEntry(void) {
    if (scrGetCmdTimer() == 0) {
        sequenceRequest(0x1C, 0, 0, 0);
        goto block_4;
    }
    if (timeLimitTaskExists() == 0) {
        return 1;
    }
block_4:
    return 0;
}

