#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern u32 datGetMoney(void);
extern void datSetMoney(s32 arg0);
extern s32 iGpffffb480;



s32 scrGetCmdTimer(void);

extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void func_0045dfd0(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Source unit: src/promoted/code1_0025.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 0025d000-0025d090 */

// Intent: Common script command ADD_PC_MONEY (p4flow Common 0x0050): adds money, clamped to 9,999,999 and at least zero [inferred]
// FUN_0025D000
s32 scrCommonAddPcMoney(void) {
    s32 temp_16;
    s32 var_4;
    temp_16 = datGetMoney();

    var_4 = temp_16 + scrGetParamInt(0);
    if (var_4 <= 0x0098967F) {
        goto block_1;
    }
    var_4 = 0x0098967FU;
block_1:
    if (var_4 < 0) {
        var_4 = 0;
    }
    datSetMoney(var_4);
    scrSetReturnInt(datGetMoney());
    return 1;
}

// Intent: Common script command CALL_NAME_ENTRY (p4flow Common 0x0051): opens the name entry screen (mode 0x1C) [inferred]
// FUN_0025D090
s32 scrCommonCallNameEntry(void) {
    if (scrGetCmdTimer() == 0) {
        func_001029a0(0x1C, 0, 0, 0);
        goto block_4;
    }
    if (func_002a2710() == 0) {
        return 1;
    }
block_4:
    return 0;
}

