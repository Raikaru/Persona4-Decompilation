#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];


extern s32 frFontGetMode(void);
extern void func_002e0f20(void);
extern void frFontUpdateTextWork(u8 *arg0);
extern void frFontLayoutText(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void MT_Scene_SetResMotionSlot(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 cmmCommunityFindActiveSlotInGroup(s64 arg0);
extern u8 *cmmSlotNameRecord(s32 arg0);
extern s32 cmmCommunityGetCurrentId(void);
extern u8 *cmmNameRecord(s32 arg0);
static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}
extern s32 MT_Scene_CheckResSlot(u32 resourceId, u32 value);
extern s32 func_00110d60(s32 arg0);
extern s64 func_002e0da0(s64 arg0, s32 arg1, s64 arg2);
extern void func_002e0f90(void);

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern s16 datGetDateIndex(void);
extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
extern s32 sprintf(void *arg0, const void *arg1, s32 arg2);
extern u8 iGpffffa738;
extern s32 calGetWeekOfYear(s32 arg0);
extern void frFontExCopyString(void *arg0, void *arg1, s32 arg2);
extern s8 D_0063BAB0[];
extern s32 cmmCommunityGetCurrentId(void);

/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 00270100-00270f50 */

// FUN_00270100
s32 func_00270100(s32 arg0, u8 *arg1)
{
    u32 flags;
    s64 key_0;
    s16 key_state;
    s64 key_a;

    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        high = ((u8 *)base)[7];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_0 = (s64)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
    }
    flags = 0;
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (key_0 == 0) {
        flags |= 0x100U;
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        high = ((u8 *)base)[5];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_state = (s16)(((var & 0xFF) << 8) |
                          (low & 0xFF));
    }
    if (key_state == -1) {
        if ((func_00110d60((s16)datGetDateIndex()) & 1) != 0) {
            if ((func_00110d60((s16)datGetDateIndex()) & 2) != 0) {
                key_state = 4;
            } else {
                key_state = 3;
            }
        } else if ((func_00110d60((s16)datGetDateIndex()) & 2) != 0) {
            key_state = 2;
        } else {
            key_state = 1;
        }
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        high = ((u8 *)base)[1];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_a = (s64)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        s32 key_b;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        high = ((u8 *)base)[3];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_b = (s32)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
        func_002e0da0(
            key_state |
            (((s64)((((s32)(s16)key_a) & 0xFF) << 0x10)) |
             ((key_b & 0xFF) << 8)),
            flags | 0x200,
            key_a);
    }
    func_002e0f90();
    return 0;
}

// FUN_00270390
s32 func_00270390(void)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    func_002e0f20();
    return 0;
}

/* measured: opt_propagation off probe for 002703d0 register setup. */
// FUN_002703D0
s32 func_002703d0(s32 arg0, u8 *arg1)
{
    u16 temp_16;
    s32 temp_4;

    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3_2;
        s32 low;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        temp_3_2 = ((u8 *)base)[1];
        if (temp_3_2 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3_2 - 1) & 0xFF;
        }
        temp_16 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                             (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2_2;
        u8 temp_3_4;
        s32 low;
        s32 key_2;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        temp_3_4 = ((u8 *)base)[3];
        if (temp_3_4 == 0xFF) {
            var_2_2 = 0;
        } else {
            var_2_2 = (temp_3_4 - 1) & 0xFF;
        }
        key_2 = (s32)(s16)(((var_2_2 & 0xFF) << 8) |
                           (low & 0xFF));
        temp_4 = key_2 & 0xFF;
    }
    if (frFontGetMode() != 0) {
        return 0;
    }
    MT_Scene_CheckResSlot(
        (((temp_16 & 0xFFFF) & 0x3FF) | 0xC00) & 0xFFFF,
        temp_4);
    return 0;
}

/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: func_002704f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_002704F0
s32 func_002704f0(s32 arg0, u8 *arg1)
{
    s32 key_0;
    struct code1_record_view {
        u8 pad0[0x10];
        s32 offset;
        u8 pad14[4];
        u8 *base;
    };
    s16 key_1;
    s16 key_2;
    s16 key_3;
    s16 key_4;
    if (frFontGetMode() != 0) {
        return 0;
    }

    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[1];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_0 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[3];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_1 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = ((struct code1_record_view *)arg1)->base;
        offset = ((struct code1_record_view *)arg1)->offset;
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[5];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_2 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((const u8 *)arg1 + 0x18);
        offset = *(s32 *)((const u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[7];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_3 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((u8 *)(u32)arg1 + 0x18);
        offset = *(s32 *)((u8 *)(u32)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[8] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[9];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_4 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }

    MT_Scene_SetResMotionSlot(key_0 & 0xFFFF, key_1, key_2, key_3, key_4);
    return 0;
}

/* measured: closes opt_rebuildconditionals off for 002704f0. */
// Intent: re-lays out the text work with no string while the frFont mode is 0.
// FUN_002706F0
s32 itfMesRefreshText(u8 *arg0, u8 *arg1)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    frFontUpdateTextWork(arg1);
    frFontLayoutText(NULL, arg1);
    return 0;
}

// FUN_00270750
s32 func_00270750(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off probe for 00270780 family add */
/* measured: itfMesSetSlotNameText MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: lays out the name of the active slot in the current group.
// FUN_00270780
s32 itfMesSetSlotNameText(s32 arg0, u8 *arg1) {
    u8 sp30[0x20];
    s32 temp_17;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u32 low;
    s32 key;
    u32 base;
    u32 offset;

    base = *(u32 *)(arg1 + 0x18);
    offset = *(u32 *)(arg1 + 0x10);
    temp_3 = (u8 *)add_retail_ptr(offset, base);
    low = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    key = ((var_2 & 0xFF) << 8) | (low & 0xFF);
    temp_17 = cmmCommunityFindActiveSlotInGroup((s16)key);
    if (frFontGetMode() != 0) {
        return 0;
    }
    frFontUpdateTextWork(arg1);
    frFontExCopyString(cmmSlotNameRecord(temp_17 & 0xFFFF), sp30, 0x20);
    frFontLayoutText(sp30, arg1);
    return 0;
}

/* measured: close opt_propagation off probe for 00270780 family add */
// Intent: lays out the first calendar field (month) as text in the text work.
// FUN_00270870
s32 itfMesSetMonthText(s32 arg0, u8 *arg1)
{
    s32 sp2C = 0;
    s32 sp28 = 0;
    u8 sp20[8];

    if (frFontGetMode() != 0)
        return 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &sp2C, &sp28);
    sprintf(sp20, &iGpffffa738, sp2C);
    frFontUpdateTextWork(arg1);
    frFontLayoutText(sp20, arg1);
    return 0;
}

// Intent: lays out the second calendar field (day) as text in the text work.
// FUN_00270910
s32 itfMesSetDayText(s32 arg0, u8 *arg1)
{
    s32 sp2C = 0;
    s32 sp28 = 0;
    u8 sp20[8];

    if (frFontGetMode() != 0)
        return 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &sp2C, &sp28);
    sprintf(sp20, &iGpffffa738, sp28);
    frFontUpdateTextWork(arg1);
    frFontLayoutText(sp20, arg1);
    return 0;
}

// Intent: copies the weekday name from the table at D_0063BAB0 into the text work.
// FUN_002709B0
s32 itfMesSetWeekdayText(s32 arg0, u8 *arg1)
{
    struct {
        u8 sp20[0x20];
        s8 sp40[0x20];
        u8 pad[0x20];
    } work;
    s8 *src;
    s8 *dst;
    s32 count;
    s8 temp0;
    s8 temp1;

    src = D_0063BAB0;
    dst = work.sp40;
    count = 0x1C;
    do
    {
        temp0 = src[0];
        temp1 = src[1];
        src += 2;
        count -= 1;
        dst[0] = temp0;
        dst[1] = temp1;
        dst += 2;
    } while (count > 0);
    if (frFontGetMode() != 0)
        return 0;
    frFontExCopyString(work.sp40 + calGetWeekOfYear((s16)datGetDateIndex()) * 8,
                  work.sp20, 0x20);
    frFontUpdateTextWork(arg1);
    frFontLayoutText(work.sp20, arg1);
    return 0;
}

/* measured: opt_propagation off probe for 00270a80 addu order */
// Intent: lays out a community name; the current community is used when the key is 0.
// FUN_00270A80
s32 itfMesSetCommunityNameText(s32 arg0, u8 *arg1) {
    u8 sp30[0x40];
    s32 temp_4;
    s32 var_2;
    s64 temp_17;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *var_2_2;
    u32 base;
    u32 offset;

    base = *(u32 *)(arg1 + 0x18);
    offset = *(u32 *)(arg1 + 0x10);
    temp_3 = (u8 *)add_retail_ptr(offset, base);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_17 = (s64)(s16)(((var_2 & 0xFF) << 8) | (temp_4 & 0xFF));
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (temp_17 == 0) {
        var_2_2 = cmmNameRecord(cmmCommunityGetCurrentId() & 0xFFFF);
    } else {
        var_2_2 = cmmNameRecord((u16)temp_17);
    }
    frFontExCopyString(var_2_2, sp30, 0x40);
    frFontUpdateTextWork(arg1);
    frFontLayoutText(sp30, arg1);
    return 0;
}

/* measured: close opt_propagation off probe for 00270a80 */
/* measured: cmmCommunityClearBrokenCurrent, cmmCommunityClearReverseCurrent, cmmCommunitySetBrokenCurrent, cmmCommunitySetReverseCurrent, cmmCommunityScriptAddPoints MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: script command that adds points to a community; the current community is used when the id is 0.
// FUN_00270B80
s32 cmmCommunityScriptAddPoints(s32 arg0, u8 *arg1)
{
    s64 first;
    s64 second;

    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        first = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        second = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }

    if (frFontGetMode() != 0)
        return 0;
    if (first == 0) {
        first = (u16)cmmCommunityGetCurrentId();
    }
    cmmCommunityAddPoints(first & 0xFFFF, second & 0xFFFF, -1);
    return 0;
}

// Intent: script command that adds points only when the community record exists.
// FUN_00270CA0
s32 cmmCommunityScriptAddPointsChecked(s32 arg0, u8 *arg1)
{
    extern s32 cmmCommunityHasRecord(u16 arg0); /* lint: allow H011 -- measured: the u16 prototype reproduces retail's narrowing at this call; s32 gives nd 44 on cmmCommunityScriptAddPointsChecked */
    extern s32 cmmCommunityAddPoints(s32 arg0, s32 arg1, s32 arg2);
    s32 second;
    s32 first;
    s32 third;

    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        first = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        s32 offset;
        u8 *base;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        second = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        struct KeyData {
            u8 pad0[0x10];
            s32 offset;
            u8 pad1[4];
            u8 *base;
        };
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = ((struct KeyData *)arg1)->base;
        offset = ((struct KeyData *)arg1)->offset;
        base += offset;
        low = (base[4] - 1) & 0xFF;
        high = base[5];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        third = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    if (frFontGetMode() != 0)
        return 0;
    if (first == 0) {
        first = (u16)cmmCommunityGetCurrentId();
    }
    if (cmmCommunityHasRecord((u16)first) != 0)
        cmmCommunityAddPoints((u16)first, (u16)second, third);
    return 0;
}

// Intent: Sets the reverse flag on the current community entry unless the font is in a mode that blocks it [inferred]
// FUN_00270E30
s32 cmmCommunitySetReverseCurrent(void) {
    s32 temp_2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    if (temp_2 != 0) {
        cmmCommunitySetReversed(temp_2 & 0xFFFF);
    }
    return 0;
}

// Intent: Clears the reverse flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270E90
s32 cmmCommunityClearReverseCurrent(void) {
    s32 temp_2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    if (temp_2 != 0) {
        cmmCommunityClearReversed(temp_2 & 0xFFFF);
    }
    return 0;
}

// Intent: Sets the broken flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270EF0
s32 cmmCommunitySetBrokenCurrent(void) {
    s32 temp_2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    if (temp_2 != 0) {
        cmmCommunitySetBroken(temp_2 & 0xFFFF);
    }
    return 0;
}

// Intent: Clears the broken flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270F50
s32 cmmCommunityClearBrokenCurrent(void) {
    s32 temp_2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    if (temp_2 != 0) {
        cmmCommunityClearBroken(temp_2 & 0xFFFF);
    }
    return 0;
}

