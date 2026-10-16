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
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 func_001eb860(void);
extern void btlDamageEndPhase(s32 task);
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
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


extern u32 datCalcRandomBelow(u32 arg0);



extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
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

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001eb4a0-001eb8d0 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern s32 btlCurrentUnitId(void);
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
/* measured: optimization_level 1 probe for retail GP-load scheduling. */
/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: closes opt_propagation probe for btlAiSetGlobal. */
// FUN_001EB4A0
/* measured: u16 state selects the narrow daddiu constants at 0x001eb598 and
   0x001eb5c0; the table-entry scan preserves the retail register-width masks. */
/* The action caller forwards the 32-bit unit-status word. This selector
 * consumes its low20 bits; higher bits have no role in table selection. */
void func_001eb4a0(u8 *arg0, u8 *arg1, u32 status) {
    extern s32 datGetMoney();
    extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
    extern s32 datCalcRandomBelow(u32 arg0);
    extern void memset(void *arg0, s32 arg1, s32 arg2);
    extern void *D_006098BC[];
    extern void *D_00609934[];
    extern u8 D_00609E50[];
    extern u8 D_00609EF0[];
    extern u8 D_00609F90[];
    extern u8 D_0060A030[];
    extern u8 *iGpffffb3c4;
    extern u8 iGpffffa4d8;
    u8 *table;
    u32 actionWord;
    s32 threshold;
    u16 state;
    s32 index;
    s32 sum;
    s32 cumulative;
    s32 scanIndex;
    u64 mode;
    u8 *current;
    u8 *entry;
    u8 weight;
    u8 *row;
    u8 *unitData;
    u8 *unit;
    s32 (*callback)(u8 *, s64);

    *(u16 *)(arg1 + 0x32) = 0;
    *(u16 *)(arg1 + 0x36) = 0;
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x34) = 0;
    *(u32 *)(arg1 + 0x50) = 0;
    *(u32 *)(arg1 + 0x54) = 0;
    *(u32 *)(arg1 + 0x58) = 0;
    memset(arg1 + 0x3E, 0, 6);
    table = NULL;
    entry = NULL;
    mode = ((u64)status << 44) >> 44;
    switch (mode) {
    case 0x10:
        unit = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unit + 0xA2) == 1) {
            if ((*(u16 *)(iGpffffb3c4 + *(u16 *)(unit + 0xA4) * 0x3C) & 0x2000) == 0 &&
                (*(u16 *)(arg0 + 0x1A) & 0x4000) == 0) {
                state = 0;
            } else {
                state = 2;
            }
        } else if (datGetMoney() != 0) {
            state = 0;
        } else {
            state = 2;
        }
        if (((s32 (*)(u8 *, s32))D_006098BC[0])(arg0, 1) != 0)
            state++;
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0)
            table = D_00609E50;
        else
            table = D_00609EF0;
        break;
    case 4:
        unitData = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unitData + 0xA2) == 0 && *(u16 *)(unitData + 0xA4) == 1) {
            state = 1;
        } else {
            state = (u16)(((s32 (*)(u8 *, s32))D_00609934[0])(arg0, 0) != 1);
        }
        table = D_00609F90;
        break;
    case 2:
        entry = (u8 *)&iGpffffa4d8 - 8;
        break;
    case 0x100:
        state = 0;
        table = D_0060A030;
        break;
    }
    if (table != NULL) {
        sum = 0;
        index = 0;
        row = table + (state & 0xFFFF) * 0x28;
        goto eb4a0_sum_test;
eb4a0_sum_body:
        sum = (sum + *(u8 *)(row + ((u16)index * 8))) & 0xFFFF;
        index = (index + 1) & 0xFFFF;
eb4a0_sum_test:
        if ((index & 0xFFFF) < 5)
            goto eb4a0_sum_body;
        entry = NULL;
        threshold = (s32)(datCalcRandomBelow(sum & 0xFFFF) & 0xFFFF);
        cumulative = 0;
        for (scanIndex = 0; (scanIndex & 0xFFFF) < 5;
             scanIndex = (scanIndex + 1) & 0xFFFF) {
            current = row + ((u16)scanIndex * 8);
            weight = *(u8 *)current;
            cumulative = (cumulative + weight) & 0xFFFF;
            if (threshold <= cumulative && weight > 0) {
                entry = current;
                break;
            }
        }
    }
    btlAICommandSetActionCode(arg0, arg1, *(u16 *)(entry + 2));
    actionWord = *(u32 *)(entry + 4);
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 +
                                      (((actionWord & 0xFF000000) >> 24) * 8));
    if (callback(arg0, (s64)((u64)actionWord << 40 >> 40)) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(arg0, 0);
}

// FUN_001EB7F0
void func_001eb7f0(void) {
    s32 temp_4;
    u8 *temp_3;
    u8 *temp_5;

    temp_3 = iGpffffb3ac;
    temp_5 = temp_3 + 0xC;
    temp_4 = *(s32 *)(temp_3 + 0xC);
    if (temp_4 & 0x1000) {
        *(s32 *)temp_5 = temp_4 & ~0x1000;
        btlDamageEndPhase(*(s32 *)(iGpffffb3ac + 0xDD4));
        sdkSndStartStream(1, 0xF, 2, 0x13);
    }
}

// FUN_001EB860
s32 func_001eb860(void) {
    u8 *temp_3;
    s32 result;

    temp_3 = iGpffffb3ac;
    if (*(s32 *)(temp_3 + 0xC) & 0x80) {
        result = 0;
        goto done;
    }
    if (*(s32 *)(temp_3 + 0xC68) != 0) {
        if (btlCurrentUnitId() == 0x215) {
            result = 0;
            goto done;
        }
    }
    result = 1;
done:
    return result;
}

// FUN_001EB8D0
void func_001eb8d0(void) {
    extern void btlDamageBeginPhase(s32 task);
    extern void btlDamageEndPhase(s32 task);
    extern u16 D_008C024E[];
    s32 flags;
    s32 temp_5;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x80) {
        var_3 = 0;
    } else if ((*(s32 *)(temp_4 + 0xC68) != 0) &&
               (btlCurrentUnitId() == 0x215)) {
        var_3 = 0;
    } else {
        var_3 = 1;
    }
    if ((var_3 != 0) &&
        (temp_3 = iGpffffb3ac,
         temp_6 = temp_3 + 0xC,
         flags = *(s32 *)(temp_3 + 0xC),
         ((flags & 0x2000) != 0))) {
        temp_5 = flags & 0x1000;
        if (temp_5 != 0) {
            if (((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20)) &&
                (temp_5 != 0)) {
                *(s32 *)temp_6 = *(s32 *)temp_6 & ~0x1000;
                btlDamageEndPhase(*(s32 *)(iGpffffb3ac + 0xDD4));
                sdkSndStartStream(1, 0xF, 2, 0x13);
            }
        } else if ((D_008C024E[0] & 0x10) && (temp_5 == 0)) {
            *(s32 *)temp_6 = flags | 0x1000;
            btlDamageBeginPhase(*(s32 *)(iGpffffb3ac + 0xDD4));
            sdkSndStartStream(1, 0xF, 2, 0x12);
        }
    }
}

