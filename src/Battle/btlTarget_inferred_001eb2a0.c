#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern u32 datCalcRandomBelow(u32 arg0);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern void btlTargetResetRecordCounter(u8 *arg0);
extern u32 datCalcRandomBelow(u32 arg0);



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
    s32 temp;

    temp = scrGetParamIntS32(0);
    temp = datCalcRandomBelow(temp);
    scrSetReturnInt(temp);
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
    slot = p4_slot_001eb320((u32)index * 4, iGpffffb3ac);
    scrSetReturnInt(*(s32 *)(slot + 0xDD8));
    return 1;
}

/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: func_001eb3b0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: btlAiSetGlobal MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* AI command 0x20AE (p4flow AI.json AI_SET_GLOBAL). */
// FUN_001EB320
s32 btlAiSetGlobal(void)
{
    s32 idx;
    s32 value;

    idx = scrGetParamIntS32(0);
    value = scrGetParamIntS32(1);
    *(s32 *)(p4_slot_001eb320((u32)idx * 4, iGpffffb3ac) + 0xDD8) = value;
    return 1;
}

/* measured: closes opt_propagation probe for btlAiSetGlobal. */
/* AI script command 0x20b8 (p4flow AI.json AI_FUNCTION_00B8). */
// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void btlTargetClearRecord(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}

// FUN_001EB3B0
void func_001eb3b0(u8 *arg0) {
    u8 *temp;

    temp = arg0;
    btlTargetResetRecordCounter(temp);
    *(s16 *)(temp + 0x36) = 0;
    *(s16 *)(temp + 0x38) = 0;
    *(s16 *)(temp + 0x34) = 0;
    *(s32 *)(temp + 0x50) = 0;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    memset(temp + 0x3E, 0, 6);
}

// FUN_001EB410
void btlTargetResetRecordCounter(u8 *arg0) {
    *(s16 *)(arg0 + 0x32) = 0;
}

