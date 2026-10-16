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
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();

extern u8 *func_0029d050();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
extern u8 *btlEffectFindUnitByIdAndStatus();
extern u8 *btlAICommandPickUnitByHpWeight();


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


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
extern s32 datCalcGetHp(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001e6d20-001e6ea0 */

/* AI script command 0x207b (p4flow AI.json AI_FUNCTION_007B). */
// FUN_001E6D20
s32 btlEffectScriptPickUnitByKind(void) {
    s32 first;
    s32 second;
    s32 kind;
    u8 *result;

    first = scrGetParamIntS32(0) & 0xFFFF;
    second = scrGetParamIntS32(1) & 0xFFFF;
    result = 0;
    kind = first & 0xFFFF;
    switch (kind) {
    case 0:
        result = btlEffectFindUnitByIdAndStatus(second, 1, 0);
        break;
    case 1:
        result = btlEffectFindUnitByIdAndStatus(second, 2, 0x80000);
        break;
    }
    scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x207c (p4flow AI.json AI_FUNCTION_007C). */
// FUN_001E6DC0
s32 btlEffectScriptPickLowestHpLivingSide1Unit(void) {
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 1 &&
                datCalcIsDead(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = datCalcGetHp(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    scrSetReturnInt(*(s32 *)(best + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x207d (p4flow AI.json AI_FUNCTION_007D). */
// FUN_001E6EA0
s32 btlEffectScriptPickWeakCandidateUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38);
            }
            scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

