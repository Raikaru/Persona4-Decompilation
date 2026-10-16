#include "btl_target_state_packet_internal.h"
#include "datPersona_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"

extern u32 datCalcGetHpById(s16 arg0);
extern u32 datCalcGetSpById(s16 arg0);
extern s32 func_0013f720(s16 arg0, s16 arg1, s32 arg2, u8 *arg3);
struct GDataEntry;
extern s32 datCalcSkillEffectFlagsById(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
static inline f32 code13Add(f32 left, f32 right) {
    return left + right;
}
extern void radarDrawFrame(u8 *arg0);
extern void radarResetEntries(u8 *arg0);
extern void radarAnimateValue(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0010f540(s32 arg0);
extern void func_0010b3b0(s16 arg0);
extern s32 datCalcThresholdTriggerById(s16 arg0, u32 arg1);
extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2F4[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
extern u8 D_0064B30C[];
typedef signed __int128 code13S128;
extern void datSetUnitHp(s16 arg0, s16 arg1);
extern void datSetUnitSp(s16 arg0, s16 arg1);
extern void datSetFlag(s32 arg0, s32 arg1);
extern void datCalcApplySkillEffectById(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
extern s32 FldStepNotAtBoundaryQuery(void);
extern void func_0013aa90(u8 *arg0);
extern void *memset(void *arg0, s32 arg1, u32 arg2);
extern s16 datBuildMemberIdList(s16 *arg0);
extern u8 *datScreenWipeTaskCreate(s32 arg0, u16 arg1);
extern u8 *resourceFindByName(char *arg0);
extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern s32 radarSetMode(u8 *arg0, s32 arg1);
extern u8 D_005E57F0[];
extern u8 D_005E5810[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005EDEA0[];
extern u8 D_005EDA00[];
extern u8 D_005EF6C8[];
extern u8 D_005ED9E0[];
extern u8 D_005ED9F0[];
typedef struct {
    s32 first;
    s32 second;
} code13Pair;

 

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Source unit: src/promoted/code1_0013.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0013.c; members 0013f720-0013ffd0 */

/* measured: donor loop shape requires invariant hoisting for the retail preheader and loop register coloring. */
/* measured: close the donor loop's invariant-hoisting bracket. */
/* measured: probing O1 for retail's extra saved pointer. */
/* measured: closing O1 probe. */
/* measured: 1448B in the 1456B window.  The slot x/y reads are f32-array views
   (retail adds the row before arg0), and the last sprite pointer is a local
   loaded ahead of the alpha conversion, which needs opt_propagation off. */
#pragma push
#pragma pop
/* measured: opt_propagation off probe for radarDrawSpritePair ordering. */
/* measured: close opt_propagation for radarDrawSpritePair probe. */
/* measured: second 00134890 probe preserves the retail floating zero and constant materialization. */
/* measured: close opt_propagation for radarResetLayout. */
/* measured: loop-invariant hoisting gives 444B / 448B with only zero tail padding. */
#pragma push
#pragma pop
/* measured: reconstructing the mixed-ABI palette draw pair from the matching 00130C30 shape. */
/* measured: close mixed-ABI palette draw pair pragma. */
/* measured: transfer the neighboring mixed-ABI palette branch shape. */
/* measured: close neighboring mixed-ABI palette branch pragma. */
/* measured: 1580B in the 1584B window.  Built from the matched twin
   radarDrawEntryRow (same slot views, same sprite-pointer local under
   opt_propagation off); the selected entry is a local so the compare keeps
   retail's operand order. */
#pragma push
#pragma pop
/* The call consumes a complete position and RGBA packet. Keep explicit
   views of their argument storage: b210 otherwise hoists the Y load before
   the RGB snapshots. All 176 instruction bytes and 42 sibling images match. */
/* measured: close family opt_propagation bracket. */
/* The sum's inline boundary preserves the retail column-before-row loads. */
// FUN_0013F720
s32 func_0013f720(s16 arg0, s16 arg1, s32 arg2, u8 *arg3) {
    u8 *spC0;
    u8 *spB0;
    u8 *spA0;
    s32 var_19;
    s16 var_18;
    s32 temp_17;
    s16 temp_22;
    s32 temp_23;
    s32 temp_30;
    s32 var_22;
    s32 var_16;
    s32 var_17;
    s32 temp_16;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_3_3;
    s16 var_16_2;
    s16 temp_22_2;
    s32 temp_23_2;
    u8 *temp_3;
    u8 *temp_3_2;

    var_19 = 1;
    var_18 = -1;
    temp_3 = code13AddOff(arg2 * 0xC, arg3);
    spC0 = temp_3 + 0x102;
    temp_17 = *(u16 *)(temp_3 + 0x102);
    spB0 = temp_3 + 0x100;
    temp_22 = *(s16 *)(temp_3 + 0x100);
    temp_23 = *(s32 *)(temp_3 + 0x104);
    temp_30 = *(s32 *)(temp_3 + 0x108);
    if (temp_22 != -1) {
        var_18 = (s16)func_0010b510();
        func_0010b3b0(temp_22);
    }
    if ((temp_17 & 0xFFFF) == 0xF6) {
        if (FldStepNotAtBoundaryQuery() != 0) {
            var_19 = 3;
        } else {
            var_19 = 0;
        }
    } else if ((s16)arg1 == -1) {
        var_22 = 0;
        var_16 = 0;
        while (var_16 < *(s16 *)(arg3 + 0xFC)) {
            temp_3_2 = arg3 + var_16 * 2;
            spA0 = temp_3_2 + 0xF4;
            if (datCalcSkillEffectFlagsById(arg0, *(s16 *)(temp_3_2 + 0xF4), temp_17, 0) == 0) {
                datCalcApplySkillEffectById(arg0, *(s16 *)spA0, temp_17, 0);
                var_22 += 1;
            }
            var_16 += 1;
        }
        if (var_22 == 0) {
            var_19 = 0;
        }
    } else if (datCalcSkillEffectFlagsById(arg0, arg1, temp_17, 0) == 0) {
        datCalcApplySkillEffectById(arg0, arg1, temp_17, 0);
    } else {
        var_19 = 0;
    }
    temp_16 = (s8)var_19;
    if (temp_16 > 0) {
        if (temp_23 > 0) {
            temp_17_2 = (datCalcGetHpById(arg0) & 0xFFFF) - temp_23;
            if (temp_17_2 <= 0) {
                kAssertFail(D_005ED9F0, 0x25B);
            }
            datSetUnitHp(arg0, (s16)temp_17_2);
        }
        if (temp_30 > 0) {
            temp_17_3 = (datCalcGetSpById(arg0) & 0xFFFF) - temp_30;
            if (temp_17_3 < 0) {
                kAssertFail(D_005ED9F0, 0x261);
            }
            datSetUnitSp(arg0, (s16)temp_17_3);
        }
        if (temp_16 == 3) {
            datSetFlag(0x1401, 1);
        } else {
            var_17 = 1;
            var_16_2 = -1;
            temp_23_2 = *(u16 *)spC0;
            temp_22_2 = *(s16 *)spB0;
            if (func_0010f540(temp_23_2) == 0) {
                var_17 = 0;
            } else {
                if (temp_22_2 != -1) {
                    var_16_2 = (s16)func_0010b510();
                    func_0010b3b0(temp_22_2);
                }
                if (datCalcThresholdTriggerById(arg0, temp_23_2) != 0) {
                    var_17 = 0;
                }
                if (var_16_2 != -1) {
                    func_0010b3b0(var_16_2);
                }
            }
            if (var_17 == 0) {
                var_19 = 2;
            } else {
                func_0013aa90(arg3);
            }
        }
    }
    if (var_18 != -1) {
        func_0010b3b0(var_18);
    }
    temp_3_3 = (s8)var_19;
    switch (temp_3_3) {
    case 0:
        sdkSndStartStream(0, 0, 0, 8);
        break;
    case 1:
    case 2:
        sdkSndStartStream(1, 3, 2, 0x16);
        break;
    case 3:
        break;
    default:
        kAssertFail(D_005ED9F0, 0x28C);
        break;
    }
    return var_19;
}

/* measured: b210 -O2 with loop-invariant optimization hoists the table and
   conversion constants. Resource pointer contracts, the chained third-resource
   store, and a counter scoped to sprite construction close the saved floor. */
// FUN_0013FB50
#pragma push
/* measured: func_0013fb50 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void func_0013fb50(u8 *arg0) {
    s16 i;
    s16 j;
    s16 n;
    s32 value;
    f32 f;
    u8 *resource0;
    u8 *resource1;
    u8 *resource2;
    s32 *slot;
    u8 *src;
    u8 *dst;

    memset(arg0, 0, 0x18B0);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)(arg0 + 0) = 0xFF;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = -1;

    i = 0;
    while (i <= 0) {
        *(s16 *)(arg0 + i * 2 + 0x34) = 0;
        i++;
    }

    j = 0;
    while (j < 0x29) {
        src = D_005EDEA0 + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x50) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x54) = *(f32 *)(src + 4);
        f = *(f32 *)(src + 8);
        value = (u16)f;
        *(s16 *)(dst + 0x60) = value;
        f = *(f32 *)(src + 0xC);
        value = (u16)f;
        *(s16 *)(dst + 0x66) = value;
        *(u8 *)(dst + 0x5A) = *(u8 *)(src + 0x10);
        j++;
    }

    n = 0;
    while (n < 0x6C) {
        slot = (s32 *)(arg0 + n * 0x14 + 0xFA4);
        *slot = n % 9;
        *(s32 *)((u8 *)slot + 8) = 9;
        *(s32 *)((u8 *)slot + 4) = n / 9;
        *(s32 *)((u8 *)slot + 0xC) = 0xC;
        n++;
    }

    *(s16 *)(arg0 + 0x32) = datBuildMemberIdList((s16 *)(arg0 + 0x22));
    resource0 = resourceFindByName((char *)D_005E5830);
    if (resource0 == 0) {
        kAssertFail(D_005EF6C8, 0x1EB);
    }
    resource1 = resourceFindByName((char *)D_005E5850);
    if (resource1 == 0) {
        kAssertFail(D_005EF6C8, 0x1ED);
    }
    *(u8 **)(arg0 + 0x1874) = resource2 = resourceFindByName((char *)D_005E57F0);
    if (resource2 == 0) {
        kAssertFail(D_005EF6C8, 0x1EF);
    }
    if (resourceFindByName((char *)D_005E5810) == 0) {
        kAssertFail(D_005EF6C8, 0x1F1);
    }

    {
        s16 k;
        k = 0;
        while (k < 0x19) {
            if (k < 3) {
                slot = (s32 *)(arg0 + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource0, *(u8 *)(D_005EDA00 + k));
            } else if (k < 0x18) {
                slot = (s32 *)(arg0 + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource1, *(u8 *)(D_005EDA00 + k));
            } else {
                slot = (s32 *)(arg0 + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource2, *(u8 *)(D_005EDA00 + k));
            }
            if (*slot == 0) {
                kAssertFail(D_005EF6C8, 0x1FD);
            }
            k++;
        }
    }
    *(u8 **)(arg0 + 0x3C) = datScreenWipeTaskCreate(0, 1);
    radarSetMode(arg0, 0);
}

#pragma pop
// FUN_0013FF80
s32 func_0013ff80(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_0013FFD0
s32 func_0013ffd0(u8 *arg0) {
    s16 temp;
    s32 i;
    s32 result;
    u8 *p;

    result = 1;
    temp = *(s16 *)(arg0 + 0x20);
    if (temp < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp + 1;
    }
    i = 0;
    goto loop_test;
loop_body:
    if ((i >= 0x1C) || ((i >= 9) && (i < 0x10))) {
        p = arg0 + i * 0x30;
        radarAnimateValue(p + 0x40, *(s16 *)(arg0 + 0x20), 1);
    } else {
        p = arg0 + i * 0x30;
        radarAnimateValue(p + 0x40, *(s16 *)(arg0 + 0x20), 0);
    }
    if (*(u8 *)(p + 0x5A) != 0) {
        result = 0;
    }
    i++;
loop_test:
    if (i < 0x29) {
        goto loop_body;
    }
    radarResetEntries(arg0);
    radarDrawFrame(arg0);
    return result;
}

