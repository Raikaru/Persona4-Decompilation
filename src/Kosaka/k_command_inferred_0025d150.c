#include "btl_action_internal.h"
#include "datPersona_internal.h"
#include "Kosaka/k_command_internal.h"
#include "list_item_internal.h"
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
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 func_00120e20(s32 arg0, s32 arg1);
extern s32 taskRecordIsDone(s32 arg0);
extern void func_00120f00(s32 arg0);
extern void taskRecordSetPosition(s32 arg0, s64 arg1);
extern s32 iGpffffb480;



s32 scrGetCmdTimer(void);
void fadeBegin(void);
s32 fadeIsIdle(void);

s16 datGetPartyId(s32 arg0);
void datSetPartyId(s32 arg0, s32 arg1);
s16 func_00106cd0(s16 arg0, s16 arg1);
void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
s32 kwlnTaskIsLinked(s32 arg0);
void func_00120f20(s32 arg0);
s32 mcIconTaskCreate(u8 *parent, s32 mode);
s32 mcIconTaskPoll(void);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 cosf(f32 arg0);
extern f32 sinf(f32 arg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void PrimDrawPoints(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Source unit: src/promoted/code1_0025.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 0025d150-0025d850 */

// FUN_0025D150
s32 scrCommonSetItemCount(void) {
    s16 temp_16;

    temp_16 = scrGetParamInt(0);
    func_00106620(temp_16, scrGetParamInt(1) & 0xFF);
    return 1;
}

/* measured probe: opt_propagation off tests d1b0 saved-register colouring. */
// Intent: Common script command PARTY_IN (p4flow Common 0x0038): adds a character to a party slot if absent [inferred]
// FUN_0025D1B0
s32 scrCommonPartyIn(void) {
    s32 var_17;
    s64 temp_16;
    s32 var_18;
    s32 var_16;

    var_16 = 0;
    var_18 = 0;
    goto loop_4_test;
loop_4:
    temp_16 = datGetPartyId(var_18);
    if ((s32)temp_16 == scrGetParamInt(0)) {
        var_16 = 1;
    }
    var_18 += 1;
loop_4_test:
    if (var_18 < 3) {
        goto loop_4;
    }
    if (var_16 != 0) {
        goto block_4;
    }
    var_17 = 0;
    goto loop_10_test;
loop_10:
    if ((s64)datGetPartyId(var_17) == 0) {
        datSetPartyId(var_17, (s32)(s64)(s16)scrGetParamInt(0));
        var_16 = 1;
        goto block_4;
    }
    var_17 += 1;
loop_10_test:
    if (var_17 < 3) {
        goto loop_10;
    }
block_4:
    if (var_16 == 0) {
        datSetPartyId(2, (s32)(s64)(s16)scrGetParamInt(0));
    }
    return 1;
}

/* measured probe: restore opt_propagation after d1b0. */
// Intent: Common script command PARTY_OUT (p4flow Common 0x0039): clears the party slot holding a character [inferred]
// FUN_0025D2D0
s32 scrCommonPartyOut(void) {
    s16 temp_16;
    s32 var_17;

    var_17 = 0;
    while (var_17 < 3) {
        temp_16 = datGetPartyId(var_17);
        if (temp_16 == scrGetParamInt(0)) {
            datSetPartyId(var_17, 0);
        }
        var_17++;
    }
    return 1;
}

// FUN_0025D350
s32 scrCommonGetCharStat(void) {
    s16 temp_16;
    s16 temp_5;

    temp_16 = scrGetParamInt(0);
    temp_5 = scrGetParamInt(1);
    scrSetReturnInt((s32)func_00106cd0(temp_16, temp_5));
    return 1;
}

// FUN_0025D3C0
s32 scrCommonSetCharStat(void) {
    s16 a;
    s16 b;

    a = scrGetParamInt(0);
    b = scrGetParamInt(1);
    func_00106d40(a, b, (s16)scrGetParamInt(2));
    return 1;
}

// FUN_0025D440
s32 K_Cmd_ICON_START_FLAGGED_WAIT(void) {
    s32 temp_2;

    if (scrGetCmdTimer() == 0) {
        mcIconTaskCreate(0, 1);
        goto block_4;
    }
    temp_2 = mcIconTaskPoll();
    if (temp_2 != 0) {
        scrSetReturnInt(temp_2);
        return 1;
    }
block_4:
    return 0;
}

// FUN_0025D4B0
s32 K_Cmd_ICON_START_WAIT(void) {
    s32 temp_2;

    if (scrGetCmdTimer() == 0) {
        mcIconTaskCreate(0, 0);
    } else {
        temp_2 = mcIconTaskPoll();
        if (temp_2 != 0) {
            scrSetReturnInt(temp_2);
            return 1;
        }
    }
    return 0;
}

// FUN_0025D520
s32 scrCommonNop(void)
{
    return 1;
}

// FUN_0025D530
s32 scrCommonGetPartyMember(void)
{
    scrSetReturnInt((s16)datGetPartyId(scrGetParamInt(0)));
    return 1;
}

// FUN_0025D580
s32 scrCommonLoadPersonaRecord(void) {
    u8 sp30[0x30];
    s16 sp60[18];
    s16 *var_6;
    s16 *var_5;
    u16 temp_18;
    s16 temp_2;
    s16 temp_3;
    s32 temp_2_2;
    u16 temp_16;
    s32 var_4;
    temp_16 = scrGetParamInt(0) & 0xFFFF;
    var_6 = D_00636A40;
    var_5 = (s16 *)sp30;
    var_4 = 9;
    do {
        temp_3 = *var_6;
        temp_2 = *(var_6 + 1);
        var_6 += 2;
        var_4 -= 1;
        *var_5 = temp_3;
        *(var_5 + 1) = temp_2;
        var_5 += 2;
    } while (var_4 > 0);
    temp_18 = (u16)temp_16;
    if (temp_18 == 1) {
        return 1;
    }
    temp_2_2 = (s32)datPersonaGetRecord(temp_16);
    datPersonaLoadRecord(
        (u8 *)sp60,
        *(u16 *)((u8 *)sp30 + ((temp_16 & 0xFFFF) * 4) + 2),
        (u8 *)temp_2_2);
    memcpy((void *)temp_2_2, sp60, 0x30);
    return 1;
}

// FUN_0025D650
s32 func_0025d650(void) {
    struct {
        f32 f0;
        f32 f1;
        s32 pad;
        s16 h0;
        s16 h1;
    } local;
    s32 temp_16;
    s32 temp_17;

    local.f0 = (f32)scrGetParamInt(0);
    local.f1 = (f32)scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    temp_16 = scrGetParamInt(3);
    if (scrGetCmdTimer() == 0) {
        local.h0 = (s16)temp_17;
        local.h1 = (s16)temp_16;
        iGpffffb480 = func_00120e20(0, *(s32 *)&local.h0);
        goto block_4;
    }
    if (taskRecordIsDone(iGpffffb480) != 0) {
        func_00120f00(iGpffffb480);
        taskRecordSetPosition(iGpffffb480, *(s64 *)&local.f0);
        scrSetReturnInt(iGpffffb480);
        iGpffffb480 = 0;
        return 1;
    }
block_4:
    return 0;
}

// FUN_0025D760
s32 K_Cmd_TASK_DESTROY(void) {
    s32 temp_16;

    temp_16 = scrGetParamInt(0);
    if (scrGetCmdTimer() == 0) {
        if (kwlnTaskIsLinked(temp_16) != 0) {
            func_00120f20(temp_16);
        }
    } else {
        return 1;
    }
    return 0;
}

/* `x > 0xA` here, not the equivalent `x >= 0xB`: b210 compiles `>= K` by
   materialising the comparison into $v0, and `> K-1` by branching through the
   assembler temp as retail does (slti $at,$v0,0xB / bnez $at). Identical
   semantics, different branch form - this was the whole nd-2 residual. Found by
   permute_ast (MATCH at 113 compiles) and reduced with permute_min; the winner
   had rewritten the constant as `> (0xB & 0xFFFF) - 1`, which is the same thing.
   Un-chaining the && and negating the inner test do NOT help - both stay nd 2. */
// FUN_0025D7E0
s32 func_0025d7e0(void) {
    if (scrGetCmdTimer() == 0xA) {
        fadeBegin();
        goto block_5;
    }
    if ((scrGetCmdTimer() > 0xA) && (fadeIsIdle() != 0)) {
        return 1;
    }
block_5:
    return 0;
}

// FUN_0025D850
void func_0025d850(f32 farg0, f32 farg1, f32 farg2, s32 arg0) {
    struct {
        u8 spB0[0x100];
        f32 sp1B0[0x7C];
    } local;
    s32 var_19;
    f32 *var_18;
    u8 *var_17;
    u8 temp_16;
    u8 temp_21;
    u8 temp_22;
    u8 temp_23;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f25;
    f32 temp_f2;
    f32 temp_f2_2;

    var_18 = local.sp1B0;
    var_17 = local.spB0;
    var_19 = 0;
    temp_16 = (u8)((u32)arg0 >> 0x18);
    temp_21 = (u8)((u32)arg0 >> 0x10);
    temp_22 = (u8)((u32)arg0 >> 8);
    temp_23 = (u8)arg0;
    goto loop_test;
loop_body:
    temp_f20 = 12.0f * (f32)var_19;
    temp_f25 = fGpffff8200 * temp_f20;
    temp_f24 = sinf(temp_f25);
    temp_f2 = 8.5f * cosf(temp_f25);
    var_18[0] = p4_0025_mul_add(8.5f, temp_f24, farg0 + temp_f2);
    var_18[1] = p4_0025_add(
        p4_0025_mul_add(8.5f, -temp_f24, farg1), temp_f2);
    temp_f24_2 = fGpffff8200 * (6.0f + temp_f20);
    temp_f20_2 = sinf(temp_f24_2);
    temp_f2_2 = 7.0f * cosf(temp_f24_2);
    var_18[2] = p4_0025_mul_add(7.0f, temp_f20_2, farg0 + temp_f2_2);
    var_18[3] = p4_0025_add(
        p4_0025_mul_add(7.0f, -temp_f20_2, farg1), temp_f2_2);
    var_18 += 4;
    var_17[0] = temp_16;
    var_17[1] = temp_21;
    var_17[2] = temp_22;
    var_17[3] = temp_23;
    var_17[4] = temp_16;
    var_17[5] = temp_21;
    var_17[6] = temp_22;
    var_17[7] = temp_23;
    var_17 += 8;
    var_19 += 1;
loop_test:
    if (var_19 < 0x1E) {
        goto loop_body;
    }
    var_18[0] = local.sp1B0[0];
    var_18[1] = local.sp1B0[1];
    var_18[2] = local.sp1B0[2];
    var_18[3] = local.sp1B0[3];
    var_17[0] = (u8)((u32)arg0 >> 0x18);
    var_17[1] = (u8)((u32)arg0 >> 0x10);
    var_17[2] = (u8)((u32)arg0 >> 8);
    var_17[3] = (u8)arg0;
    var_17[4] = (u8)((u32)arg0 >> 0x18);
    var_17[5] = (u8)((u32)arg0 >> 0x10);
    var_17[6] = (u8)((u32)arg0 >> 8);
    var_17[7] = (u8)arg0;
    func_00364c50();
    PrimDrawPoints(local.spB0, local.sp1B0, farg2, 0x3E, 4, 1);
    local.spB0[0] = 0xDC;
    local.spB0[1] = 0xDC;
    local.spB0[2] = 0xDC;
    local.spB0[3] = 0xFF;
    temp_f0 = 180.0f;
    func_0045ee00((s32)farg0, (s32)farg1, local.spB0, 8, temp_f0, farg2, 1);
    func_00364c70();
}

