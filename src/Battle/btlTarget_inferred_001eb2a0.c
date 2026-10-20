#include "byte_address_internal.h"
#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);



extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern u32 datCalcRandomBelow(u32);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern void btlTargetResetRecordCounter(u8 *);
extern u32 datCalcRandomBelow(u32);



extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 D_00609E40[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001eb2a0-001eb410 */

#pragma push
#pragma pop
/* measured probe: preserve the retail filter branch chain */
#pragma push
/* measured probe: close the filter branch chain */
#pragma pop
/* measured probe: preserve retail conditional branch shape */
#pragma push
/* measured probe: close conditional branch shape */
#pragma pop
/* AI command 0x2097 (p4flow AI.json AI_RND). */
// FUN_001EB2A0
s32 btlAiRandom(void) {
    s32 value;

    value = scrGetParamIntS32(0);
    value = datCalcRandomBelow(value);
    scrSetReturnInt(value);
    return 1;
}

/* measured: optimization_level 1 probe for retail GP-load scheduling. */
/* measured: btlAiGetGlobal MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* AI command 0x20AD (p4flow AI.json AI_GET_GLOBAL). */
// FUN_001EB2E0
s32 btlAiGetGlobal(void) {
    s32 index;
    u8 *slot;

    index = scrGetParamIntS32(0);
    slot = byteAddressAdd((u32)index * 4, (u8 *)(iGpffffb3ac));
    scrSetReturnInt(((BtlTargetScriptGlobals *)(slot + 0xDD8))->values[0]);
    return 1;
}

/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: func_001eb3b0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: btlAiSetGlobal MATCH -> MISMATCH without this pragma. */
/* Unit-region setting: propagation remains off for the five neighboring setters and record helpers. */
#pragma opt_propagation off
/* AI command 0x20AE (p4flow AI.json AI_SET_GLOBAL). */
// FUN_001EB320
s32 btlAiSetGlobal(void)
{
    s32 idx;
    s32 value;

    idx = scrGetParamIntS32(0);
    value = scrGetParamIntS32(1);
    ((BtlTargetScriptGlobals *)(byteAddressAdd((u32)idx * 4, (u8 *)(iGpffffb3ac)) + 0xDD8))->values[0] = value;
    return 1;
}

/* measured: closes opt_propagation probe for btlAiSetGlobal. */
/* AI script command 0x20b8 (p4flow AI.json AI_FUNCTION_00B8). */
// FUN_001EB370
s32 btlAiScriptCommandNoop(void)
{
    return 1;
}

// FUN_001EB380
void btlTargetClearRecord(u8 *record) {
    memset(record, 0, 0x5C);
}

/* Reset command selection and three plan values while retaining the target slots. */
// FUN_001EB3B0
void btlTargetResetCommandRecord(u8 *record) {
    u8 *work;

    work = record;
    btlTargetResetRecordCounter(work);
    ((BtlAiCommandWork *)work)->command = 0;
    ((BtlAiCommandWork *)work)->skill = 0;
    ((BtlAiCommandWork *)work)->kind = 0;
    ((BtlAiCommandWork *)work)->unk50 = 0;
    ((BtlAiCommandWork *)work)->unk54 = 0;
    ((BtlAiCommandWork *)work)->unk58 = 0;
    memset(work + 0x3E, 0, 6);
}

// FUN_001EB410
void btlTargetResetRecordCounter(u8 *record) {
    ((BtlAiCommandWork *)record)->targetCount = 0;
}

