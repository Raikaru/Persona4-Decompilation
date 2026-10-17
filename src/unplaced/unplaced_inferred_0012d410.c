/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0012db80-0012ff60 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}

static inline s32 code1_0012_stride_loop(s32 base, s32 index)
{
    return base + index;
}

extern u8 *resourceFindByName(char *filename);
extern s32 titleSlotSetMode(u8 *arg0, s32 arg1);
extern void sdkSpriteFreeNode(void *node);
extern s32 nLineIsIdle(void);
extern void radarAnimateValue(u8 *arg0, s32 arg1, s32 arg2);
extern void datCommunityEntryStep(u8 *arg0);
extern void radarDrawPanel(u8 *arg0);
extern void radarStepSlotAnimB(u8 *arg0);
extern void radarStepPairAnim(u8 *arg0);
extern void kAssertFail(const void *file, s32 line);
extern s32 datItemCount(s16 id);
extern u8 D_005E76C8[];
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s16 datBuildPartyIdList(void *arg0);
extern u8 *sdkSpriteNewNode(u32 sprites, u32 index);
extern u8 D_005E5F40[];
extern u8 D_005E7670[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_005E76C8[];
extern void titleCollectFlaggedIds(u8 *arg0);
extern s32 titleSetMenuLayout(u8 *arg0, u32 arg1);
#include "btl_shuffle_draw_internal.h"
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;

typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012DB80
s32 func_0012db80(u8 *arg0, s32 arg1)
{
    if (arg1 != *(s32 *)(arg0 + 0x10)) {
        sdkSndStartStream(0, 1, 0, 0);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x10);
        *(s32 *)(arg0 + 0x10) = arg1;
        *(s32 *)(arg0 + 0x18) = -1;
        titleSlotSetMode(arg0, 2);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
// FUN_0012DC00
void titleLayoutSlots(u8 *arg0)
{
    s32 temp_10;
    s32 temp_3;
    s32 temp_5;
    s32 temp_7;
    s32 temp_9;
    s32 temp_8;
    s32 var_11;
    s32 var_11_2;
    s32 var_12;
    s32 var_c_ff;
    f32 var_c_1;
    f32 var_c_2;
    s32 var_c_7f;
    s32 var_c_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_5_2;
    u8 *temp_5_3;
    u8 *temp_6;
    u8 *temp_6_2;
    u8 *temp_6_3;
    u8 *temp_6_4;
    u8 *temp_6_5;

    temp_5 = *(s32 *)(arg0 + 0x10);
    temp_10 = *(s32 *)(arg0 + 0x14);
    temp_3 = *(s32 *)(arg0 + 0x38);
    temp_9 = temp_3 - 1;
    temp_8 = -temp_9;
    temp_7 = temp_5 - temp_10;
    var_11 = 0;
    goto loop_0012dc00_2_check;
loop_0012dc00_2_body:
    temp_6 = (var_11 * 0x30) + arg0;
    *(s32 *)(temp_6 + 0xBC) = 0;
    *(s32 *)(temp_6 + 0xC0) = 0;
    var_11 += 1;
loop_0012dc00_2_check:
    if (var_11 < 0xB) {
        goto loop_0012dc00_2_body;
    }
    if (temp_7 == 1) {
        temp_3_2 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_2 + 0x9C) = 0;
        *(s32 *)(temp_3_2 + 0x98) = 0;
        *(s32 *)(temp_3_2 + 0xA0) = 0;
        *(u8 *)(temp_3_2 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_2 + 0xC0) = 0;
        temp_5_2 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_2 + 0x9C) = 0;
        *(s32 *)(temp_5_2 + 0x98) = (s32)0xC1700000;
        *(s32 *)(temp_5_2 + 0xA0) = (s32)0x40B00000;
        *(s8 *)(temp_5_2 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_2 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == -1) {
        temp_3_3 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_3 + 0x9C) = 0;
        *(s32 *)(temp_3_3 + 0x98) = 0;
        *(s32 *)(temp_3_3 + 0xA0) = 0;
        *(u8 *)(temp_3_3 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_3 + 0xC0) = 0;
        temp_5_3 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_3 + 0x9C) = 0;
        *(s32 *)(temp_5_3 + 0x98) = (s32)0x41700000;
        *(s32 *)(temp_5_3 + 0xA0) = (s32)0xC0B00000;
        *(s8 *)(temp_5_3 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_3 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    } else if (temp_7 == temp_9) {
        var_12 = 0;
        var_c_ff = 0xFF;
        var_c_1 = -15.0f;
        var_c_2 = 5.5f;
        var_c_7f = 0x7F;
        var_c_3 = 3;
        goto loop_0012dc00_13_check;
loop_0012dc00_13_body:
        if (var_12 == temp_5) {
            temp_6_2 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(f32 *)(temp_6_2 + 0x98) = var_c_1;
            *(f32 *)(temp_6_2 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_2 + 0xAC) = var_c_7f;
            *(u8 *)(temp_6_2 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_2 + 0xC0) = var_c_3;
        } else {
            temp_6_3 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(s32 *)(temp_6_3 + 0x9C) = 0;
            *(s32 *)(temp_6_3 + 0x98) = 0;
            *(s32 *)(temp_6_3 + 0xA0) = 0;
            *(u8 *)(temp_6_3 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_3 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_3 + 0xC0) = 0;
        }
        var_12 += 1;
loop_0012dc00_13_check:
        if (var_12 < temp_3) {
            goto loop_0012dc00_13_body;
        }
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == temp_8) {
        var_11_2 = 0;
        var_c_ff = 0xFF;
        var_c_1 = 15.0f;
        var_c_2 = -5.5f;
        var_c_3 = 3;
        goto loop_0012dc00_21_check;
loop_0012dc00_21_body:
        if (var_11_2 == temp_5) {
            temp_6_4 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(f32 *)(temp_6_4 + 0x98) = var_c_1;
            *(f32 *)(temp_6_4 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_4 + 0xAC) = 0;
            *(u8 *)(temp_6_4 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_4 + 0xC0) = var_c_3;
        } else {
            temp_6_5 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(s32 *)(temp_6_5 + 0x9C) = 0;
            *(s32 *)(temp_6_5 + 0x98) = 0;
            *(s32 *)(temp_6_5 + 0xA0) = 0;
            *(u8 *)(temp_6_5 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_5 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_5 + 0xC0) = 0;
        }
        var_11_2 += 1;
loop_0012dc00_21_check:
        if (var_11_2 < temp_3) {
            goto loop_0012dc00_21_body;
        }
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    }
    *(s16 *)(arg0 + 0xC) = 0;
}
#pragma pop

extern u8 D_005E58C0[];
extern u8 D_005E59A0[];
extern u8 D_005E5A80[];
extern void titleLayoutSlots(u8 *arg0);
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
// FUN_0012DEA0
s32 titleSlotSetMode(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 i0;
    s32 i1;
    s32 i3;
    u8 *p;
    u8 *src0;
    u8 *dst0;
    u8 *src1;
    u8 *dst1;
    u8 *src3;
    u8 *dst3;

    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0xC) = 0;
    i = 0;
    while (i < 0xB) {
        p = arg0 + i * 0x30;
        *(f32 *)(p + 0x94) = *(f32 *)(p + 0xA4);
        *(f32 *)(p + 0x98) = *(f32 *)(p + 0xA8);
        *(u8 *)(p + 0xAC) = *(u8 *)(p + 0xAE);
        *(u16 *)(p + 0xB0) = *(u16 *)(p + 0xB4);
        *(u16 *)(p + 0xB6) = *(u16 *)(p + 0xBA);
        i++;
    }
    switch (arg1) {
    case 0:
        i0 = 0;
        while (i0 < 0xB) {
            if (i0 != *(s32 *)(arg0 + 0x10)) {
                src0 = D_005E58C0 + i0 * 0x14;
                dst0 = arg0 + i0 * 0x30;
                *(f32 *)(dst0 + 0x9C) = *(f32 *)(src0 + 0);
                *(f32 *)(dst0 + 0xA0) = *(f32 *)(src0 + 4);
                *(u8 *)(dst0 + 0xAD) = *(u8 *)(src0 + 8);
                *(u16 *)(dst0 + 0xB8) = *(u16 *)(src0 + 0xA);
                *(s32 *)(dst0 + 0xBC) = *(s32 *)(src0 + 0xC);
                *(s32 *)(dst0 + 0xC0) = *(s32 *)(src0 + 0x10);
            } else {
                dst0 = arg0 + i0 * 0x30;
                *(s32 *)(dst0 + 0x94) = 0;
                *(s32 *)(dst0 + 0x9C) = 0;
                *(s32 *)(dst0 + 0x98) = 0x41B80000;
                *(s32 *)(dst0 + 0xA0) = 0;
                *(u8 *)(dst0 + 0xAC) = 0;
                *(u8 *)(dst0 + 0xAD) = 0xFF;
                *(u16 *)(dst0 + 0xB6) = 1;
                *(u16 *)(dst0 + 0xB8) = 0x1000;
                *(s32 *)(dst0 + 0xBC) = 0xB;
                *(s32 *)(dst0 + 0xC0) = 0xD;
            }
            i0++;
        }
        break;
    case 1:
        i1 = 0;
        while (i1 < 0xB) {
            src1 = D_005E59A0 + i1 * 0x14;
            dst1 = arg0 + i1 * 0x30;
            *(f32 *)(dst1 + 0x9C) = *(f32 *)(src1 + 0);
            *(f32 *)(dst1 + 0xA0) = *(f32 *)(src1 + 4);
            *(u8 *)(dst1 + 0xAD) = *(u8 *)(src1 + 8);
            *(u16 *)(dst1 + 0xB8) = *(u16 *)(src1 + 0xA);
            *(s32 *)(dst1 + 0xBC) = *(s32 *)(src1 + 0xC);
            *(s32 *)(dst1 + 0xC0) = *(s32 *)(src1 + 0x10);
            i1++;
        }
        break;
    case 2:
        titleLayoutSlots(arg0);
        break;
    case 3:
        i3 = 0;
        while (i3 < 0xB) {
            dst3 = arg0 + i3 * 0x30;
            *(s32 *)(dst3 + 0x94) = 0;
            *(s32 *)(dst3 + 0x98) = 0;
            src3 = D_005E5A80 + i3 * 0x14;
            *(f32 *)(dst3 + 0x9C) = *(f32 *)(src3 + 0);
            *(f32 *)(dst3 + 0xA0) = *(f32 *)(src3 + 4);
            *(u8 *)(dst3 + 0xAD) = *(u8 *)(src3 + 8);
            *(u16 *)(dst3 + 0xB8) = *(u16 *)(src3 + 0xA);
            *(s32 *)(dst3 + 0xBC) = *(s32 *)(src3 + 0xC);
            *(s32 *)(dst3 + 0xC0) = *(s32 *)(src3 + 0x10);
            i3++;
        }
        break;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
// FUN_0012E150
void titleFreeSpriteNodes(s32 arg0)
{
    s32 temp_4;
    s32 var_17;
    u8 *temp_3;
    u8 *temp_16;

    var_17 = 0;
    while (var_17 < 0x15) {
        temp_3 = (u8 *)(arg0 + (var_17 * 4));
        temp_16 = temp_3 + 0x3C;
        temp_4 = *(s32 *)temp_16;
        if (temp_4 != 0) {
            sdkSpriteFreeNode((void *)temp_4);
            *(s32 *)temp_16 = 0;
        }
        var_17 += 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
// FUN_0012E1D0
s32 func_0012e1d0(u8 *arg0)
{
    s32 var_16 = 1;
    s32 var_5 = 0;
    s32 temp_3 = *(s16 *)(arg0 + 0xC);

    while (var_5 < 0xB) {
        if (temp_3 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
// FUN_0012E250
s32 titleSlotsSettled(u8 *arg0)
{
    s32 temp_3 = *(s32 *)(arg0 + 0x18);
    s32 var_16 = 1;
    s32 var_5;
    s32 temp_4;

    if (temp_3 == var_16) {
        goto block_early;
    }
    if (temp_3 != 2) {
        goto block_loop;
    }
block_early:
    return 1;
block_loop:
    var_5 = 0;
    temp_4 = *(s16 *)(arg0 + 0xC);
    while (var_5 < 0xB) {
        if (temp_4 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
// FUN_0012E2F0
s32 titleStateInit(u8 *arg0)
{
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    u8 *base_5f40;
    u8 *res_1;
    u8 *res_2;
    u8 *res_3;
    u8 *res_slot;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    u16 temp_u16;
    s32 temp_byte;
    s16 ii;

    memset(arg0, 0, 0x1BE8);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)arg0 = 0xFF;
    *(s32 *)(arg0 + 0x30) = -1;
    *(s16 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(arg0 + (i * 2) + 0x22) = 0;
    }
    j = 0;
    base_5f40 = D_005E5F40;
    for (; j < 30; j++) {
        temp_2 = base_5f40 + (j * 0x1C);
        temp_3 = arg0 + (j * 0x30);
        *(f32 *)(temp_3 + 0x12E8) = *(f32 *)temp_2;
        *(f32 *)(temp_3 + 0x12EC) = *(f32 *)(temp_2 + 4);
        *(u8 *)(temp_3 + 0x12F2) = *(u8 *)(temp_2 + 0x10);
        temp_u16 = (u16)*(f32 *)(temp_2 + 8);
        *(u16 *)(temp_3 + 0x12F8) = temp_u16;
        temp_u16 = (u16)*(f32 *)(temp_2 + 0xC);
        *(u16 *)(temp_3 + 0x12FE) = temp_u16;
    }
    for (k = 0; k < 12; k++) {
        *(s32 *)(arg0 + (k * 0x30) + 0x1888) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1878) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1884) = -1027080192;
        *(s32 *)(arg0 + (k * 0x30) + 0x187C) = -1027080192;
        *(u8 *)(arg0 + (k * 0x30) + 0x1891) = 127;
        *(u8 *)(arg0 + (k * 0x30) + 0x1890) = 127;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A0) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A4) = 10;
    }
    for (m = 0; m < 84; m++) {
        *(s32 *)(arg0 + (m * 0x14) + 0xC4C) = m % 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC54) = 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC50) = m / 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC58) = 12;
    }
    for (n = 0; n < 2; n++) {
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AB8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC4) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1ABC) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD1) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE4) = 3;
    }
    *(s16 *)(arg0 + 0x3C) = datBuildPartyIdList(arg0 + 0x34);
    res_1 = (u8 *)resourceFindByName((char *)D_005E5830);
    if (res_1 == NULL) {
        kAssertFail(D_005E76C8, 0x1FA);
    }
    res_2 = (u8 *)resourceFindByName((char *)D_005E5850);
    if (res_2 == NULL) {
        kAssertFail(D_005E76C8, 0x1FC);
    }
    temp_16 = (s32)resourceFindByName((char *)D_005E57F0);
    res_3 = (u8 *)temp_16;
    *(u8 **)(arg0 + 0x1BE4) = (u8 *)temp_16;
    if (res_3 == NULL) {
        kAssertFail(D_005E76C8, 0x1FE);
    }
    ii = 0;
    while (ii < 51) {
        if (ii < 28) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)sdkSpriteNewNode((u32)res_1, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else if (ii < 49) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)sdkSpriteNewNode((u32)res_2, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)sdkSpriteNewNode((u32)res_3, temp_byte);
            *(s32 *)res_slot = temp_16;
        }
        if (*(s32 *)res_slot == 0) {
            kAssertFail(D_005E76C8, 0x20B);
        }
        ii++;
    }
    titleCollectFlaggedIds(arg0);
    return titleSetMenuLayout(arg0, 0);
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
// FUN_0012E7C0
void titleCollectFlaggedIds(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    s64 temp_4_2;
    s16 var_18;
    s16 var_17;
    u8 *temp_3;

    var_17 = 0;
    var_18 = 0;
    goto loop_test;
loop_body:
    temp_16 = (s32)temp_4 + 0x300;
    temp_4_2 = (s64)(s16)(datItemCount(temp_16) & 0xFF);
    if (temp_4_2 != 0) {
        temp_3 = arg0 + ((s16)var_17 * 4);
        *(s16 *)(temp_3 + 0x3E) = (s16)temp_16;
        *(s16 *)(temp_3 + 0x40) = (s16)temp_4_2;
        var_17 += 1;
    }
    var_18 += 1;
loop_test:
    temp_4 = var_18;
    if (temp_4 < 0x300) {
        goto loop_body;
    }
    *(s16 *)(arg0 + 0xC3E) = var_17;
    if (var_17 <= 0x300) {
        goto guard_done;
    }
    kAssertFail(D_005E76C8, 0x225);
guard_done:
    ;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
// FUN_0012E8B0
s32 titleAdvanceWait(u8 *arg0)
{
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0x18);
    switch (temp_3) {
    case 0:
        *(s32 *)(arg0 + 0x18) = temp_3 + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
// FUN_0012E900
s32 radarStepSlotAnimA(u8 *arg0) {
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_19;

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x1C);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x1C) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test_0012e900;
loop_body_0012e900:
    temp_19 = arg0 + (var_17 * 0x30);
    radarAnimateValue(temp_19 + 0x12D8, *(s16 *)(arg0 + 0x1C), 0);
    if (*(u8 *)(temp_19 + 0x12F2) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test_0012e900:
    if (var_17 < 0x1E) {
        goto loop_body_0012e900;
    }
    radarStepSlotAnimB(arg0);
    radarStepPairAnim(arg0);
    radarDrawPanel(arg0);
    return var_16;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
// FUN_0012FDF0
void radarStepSlotAnimB(u8 *arg0)
{
    s16 temp_3;
    s32 var_16;
    s32 var_16_2;
    u8 *temp_2;

    temp_3 = *(s16 *)(arg0 + 0x1E);
    if (temp_3 < 0x64) {
        temp_3 += 1;
        *(s16 *)(arg0 + 0x1E) = temp_3;
    }
    for (var_16 = 0; var_16 < 0xC; var_16++) {
        temp_2 = arg0 + (var_16 * 0x30);
        radarAnimateValue(temp_2 + 0x1878, *(s16 *)(arg0 + 0x1E), 0);
    }
    for (var_16_2 = 0; var_16_2 < 0x54; var_16_2++) {
        temp_2 = arg0 + (var_16_2 * 0x14);
        datCommunityEntryStep(temp_2 + 0xC48);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs off
// FUN_0012FEB0
void radarStepPairAnim(u8 *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = arg0 + i * 0x30 + 0x1AB8;
        radarAnimateValue(p, *(s16 *)(arg0 + 0x20), 0);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs on
/* The selection is passed as a word; the field stores its low halfword. */
// FUN_0012FF40
s32 radarPushHistoryValue(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *p;

    p = (u8 *)code1_0012_stride(arg1 * 2, arg0);
    *(s16 *)(p + 0x28) = *(s16 *)(p + 0x22);
    *(s16 *)(p + 0x22) = arg2;
    return 1;
}
#pragma pop

extern u8 D_005E5BF0[];
extern u8 D_005E6290[];
extern u8 D_005E65E0[];
extern u8 D_005E6930[];
extern u8 D_005E6C80[];
extern u8 D_005E6FD0[];
extern u8 D_005E7320[];
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs off
// FUN_0012FF60
s32 titleSetMenuLayout(u8 *arg0, u32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    table = 0;
    if (arg1 == *(u32 *)(arg0 + 0x30)) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        dst = arg0 + (i * 0x30);
        *(f32 *)(dst + 0x12d8) = *(f32 *)(dst + 0x12e8);
        *(f32 *)(dst + 0x12dc) = *(f32 *)(dst + 0x12ec);
        *(u16 *)(dst + 0x12f4) = *(u16 *)(dst + 0x12f8);
        *(u16 *)(dst + 0x12fa) = *(u16 *)(dst + 0x12fe);
        *(u8 *)(dst + 0x12f0) = *(u8 *)(dst + 0x12f2);
    }
    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E5BF0;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 1:
        table = D_005E5F40;
        break;
    case 2:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 3:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 4:
        *(s32 *)(arg0 + 0x14) = 0x2dd;
        table = D_005E65E0;
        *(s16 *)(arg0 + 0x2c) = *(s16 *)(arg0 + 0x26);
        *(s16 *)(arg0 + 0x26) = 0;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 5:
        *(s32 *)(arg0 + 0x14) = 0x2ed;
        table = D_005E6C80;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 6:
        *(s32 *)(arg0 + 0x14) = 0x29d;
        table = D_005E6930;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 7:
        *(s32 *)(arg0 + 0x14) = 0x2ad;
        table = D_005E6FD0;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 8:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    case 9:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    default:
        kAssertFail(D_005E76C8, 0x4ab);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table-loop constants and
   stride calculations into retail's preheader (without it, nd is nonzero). */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 30; j++) {
            src = table + (j * 0x1c);
            dst = arg0 + (j * 0x30);
            *(f32 *)(dst + 0x12e0) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x12e4) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0x12f1) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0x12f6) = (u16)value;
            value = *(f32 *)(src + 0xc);
            *(u16 *)(dst + 0x12fc) = (u16)value;
            *(s32 *)(dst + 0x1300) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x1304) = *(s32 *)(src + 0x18);
        }
        *(u32 *)(arg0 + 0x30) = arg1;
        *(s16 *)(arg0 + 0x1c) = 0;
    }
    return 1;
}
#pragma pop
