#include "include_asm.h"
#include "type.h"
#include "fr_font_objects.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];


extern s32 frFontGetMode(void);
extern void fclBankMarkSettled(void);
extern void frFontUpdateTextWork(u8 *value);
extern void frFontLayoutText(u8 *value, u8 *index);

extern s32 D_008815B0[];

extern void MT_Scene_SetResMotionSlot(u32 value, s16 index, s16 count, s16 flags, s16 mode);
extern s32 cmmCommunityFindActiveSlotInGroup(s64 value);
extern u8 *cmmSlotNameRecord(s32 value);
extern s32 cmmCommunityGetCurrentId(void);
extern u8 *cmmNameRecord(s32 value);
static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}
extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 value);
extern s32 calGetDayWindowFlags(s32 value);
extern s64 fclBankTryQueueRequest(s64 value, s32 index, s64 count);
extern void fclBankSetReadyFlag(void);

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern s16 datGetDateIndex(void);
extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
extern s32 sprintf(void *value, const void *index, s32 count);
extern u8 iGpffffa738;
extern s32 calGetWeekOfYear(s32 value);
extern void frFontExCopyString(void *value, void *index, s32 count);
extern s8 D_0063BAB0[];
extern s32 cmmCommunityGetCurrentId(void);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 00270100-00270f50 */

/* Decode and queue a bank request, deriving its state from calendar flags when unspecified. */
/* Context +0x10/+0x18 are stream/position; keep pointer-typed raw reads:
 * the canonical s32 fields merge operand reloads and lose the measured retail match. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 123, 139, 172, 181, 183, 188, 190, 200, 202, 213, 241, 267, 269, 274, 277, 340, 341, 469, 470, 471; retain their original address/alias expressions. */
// FUN_00270100
s32 frFontQueueBankRequestCommand(s32 unusedCommand, u8 *context)
{
    u32 flags;
    s64 requestKey;
    s16 requestState;
    s64 primaryKey;

    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 decodedHigh;
        base = (u8 *)((FrFontContext *)context)->position;
        offset = ((FrFontContext *)context)->stream;
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        high = ((u8 *)base)[7];
        if (high == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (high - 1) & 0xFF;
        }
        requestKey = (s64)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    flags = 0;
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (requestKey == 0) {
        flags |= 0x100U;
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 decodedHigh;
        base = *(u8 **)(context + 0x18);
        offset = *(s32 *)(context + 0x10);
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        high = ((u8 *)base)[5];
        if (high == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (high - 1) & 0xFF;
        }
        requestState = (s16)(((decodedHigh & 0xFF) << 8) |
                          (low & 0xFF));
    }
    if (requestState == -1) {
        if ((calGetDayWindowFlags((s16)datGetDateIndex()) & 1) != 0) {
            if ((calGetDayWindowFlags((s16)datGetDateIndex()) & 2) != 0) {
                requestState = 4;
            } else {
                requestState = 3;
            }
        } else if ((calGetDayWindowFlags((s16)datGetDateIndex()) & 2) != 0) {
            requestState = 2;
        } else {
            requestState = 1;
        }
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 decodedHigh;
        base = *(u8 **)(context + 0x18);
        offset = *(s32 *)(context + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        high = ((u8 *)base)[1];
        if (high == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (high - 1) & 0xFF;
        }
        primaryKey = (s64)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 decodedHigh;
        s32 secondaryKey;
        base = *(u8 **)((u8 *)context + 0x18);
        offset = *(s32 *)((u8 *)context + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        high = ((u8 *)base)[3];
        if (high == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (high - 1) & 0xFF;
        }
        secondaryKey = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
        fclBankTryQueueRequest(
            requestState |
            (((s64)((((s32)(s16)primaryKey) & 0xFF) << 0x10)) |
             ((secondaryKey & 0xFF) << 8)),
            flags | 0x200,
            primaryKey);
    }
    fclBankSetReadyFlag();
    return 0;
}

/* Mark the bank request settled when the font command mode permits execution. */
// FUN_00270390
s32 frFontSettleBankRequestCommand(void)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    fclBankMarkSettled();
    return 0;
}

/* measured: opt_propagation off probe for 002703d0 register setup. */
/* Decode the resource and value operands and spawn the corresponding scene icon task. */
/* Context +0x10/+0x18 are stream/position; keep pointer-typed raw reads:
 * the canonical s32 fields merge operand reloads and lose the measured retail match. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 123, 139, 181, 183, 188, 190, 200, 202, 213, 274, 277, 470, 471; retain their original address/alias expressions. */
// FUN_002703D0
s32 frFontSpawnResourceIconCommand(s32 unusedCommand, u8 *context)
{
    u16 resourceId;
    s32 value;

    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 encodedHigh;
        s32 low;
        base = (u8 *)((FrFontContext *)context)->position;
        offset = ((FrFontContext *)context)->stream;
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        encodedHigh = ((u8 *)base)[1];
        if (encodedHigh == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (encodedHigh - 1) & 0xFF;
        }
        resourceId = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                             (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 secondDecodedHigh;
        u8 secondEncodedHigh;
        s32 low;
        s32 secondKey;
        base = *(u8 **)((u8 *)context + 0x18);
        offset = *(s32 *)((u8 *)context + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        secondEncodedHigh = ((u8 *)base)[3];
        if (secondEncodedHigh == 0xFF) {
            secondDecodedHigh = 0;
        } else {
            secondDecodedHigh = (secondEncodedHigh - 1) & 0xFF;
        }
        secondKey = (s32)(s16)(((secondDecodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
        value = secondKey & 0xFF;
    }
    if (frFontGetMode() != 0) {
        return 0;
    }
    MT_Scene_SpawnResIconTask(
        (((resourceId & 0xFFFF) & 0x3FF) | 0xC00) & 0xFFFF,
        value);
    return 0;
}

/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: func_002704f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* Context +0x10/+0x18 are stream/position; keep pointer-typed raw reads:
 * the canonical s32 fields merge operand reloads and lose the measured retail match. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 123, 139, 143, 150, 172, 181, 183, 188, 190, 200, 202, 211, 213, 214, 236, 238, 241, 267, 269, 274, 277, 340, 341, 469, 470, 471; retain their original address/alias expressions. */
// FUN_002704F0
s32 frFontSetResourceMotionCommand(s32 unusedCommand, u8 *context)
{
    s32 requestKey;
    struct FrFontCommandOperands {
        u8 pad0[0x10];
        s32 offset;
        u8 pad14[4];
        u8 *base;
    };
    s16 motion;
    s16 secondKey;
    s16 startFrame;
    s16 endFrame;
    if (frFontGetMode() != 0) {
        return 0;
    }

    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 operand;
        s32 low;
        base = *(u8 **)(context + 0x18);
        offset = *(s32 *)(context + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        operand = ((u8 *)base)[1];
        if (operand == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (operand - 1) & 0xFF;
        }
        requestKey = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 operand;
        s32 low;
        base = *(u8 **)((u8 *)context + 0x18);
        offset = *(s32 *)((u8 *)context + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        operand = ((u8 *)base)[3];
        if (operand == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (operand - 1) & 0xFF;
        }
        motion = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 operand;
        s32 low;
        base = ((struct FrFontCommandOperands *)context)->base;
        offset = ((struct FrFontCommandOperands *)context)->offset;
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        operand = ((u8 *)base)[5];
        if (operand == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (operand - 1) & 0xFF;
        }
        secondKey = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 operand;
        s32 low;
        base = *(u8 **)((const u8 *)context + 0x18);
        offset = *(s32 *)((const u8 *)context + 0x10);
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        operand = ((u8 *)base)[7];
        if (operand == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (operand - 1) & 0xFF;
        }
        startFrame = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 operand;
        s32 low;
        base = *(u8 **)((u8 *)(u32)context + 0x18);
        offset = *(s32 *)((u8 *)(u32)context + 0x10);
        base += offset;
        low = (((u8 *)base)[8] - 1) & 0xFF;
        operand = ((u8 *)base)[9];
        if (operand == 0xFF) {
            decodedHigh = 0;
        } else {
            decodedHigh = (operand - 1) & 0xFF;
        }
        endFrame = (s32)(s16)(((decodedHigh & 0xFF) << 8) |
                           (low & 0xFF));
    }

    MT_Scene_SetResMotionSlot(requestKey & 0xFFFF, motion, secondKey, startFrame, endFrame);
    return 0;
}

/* measured: closes opt_rebuildconditionals off for 002704f0. */
// Intent: re-lays out the text work with no string while the frFont mode is 0.
// FUN_002706F0
s32 itfMesRefreshText(u8 *unusedCommand, u8 *context)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    frFontUpdateTextWork(context);
    frFontLayoutText(NULL, context);
    return 0;
}

/* Sample the font mode without executing a text command. */
// FUN_00270750
s32 frFontCheckModeCommand(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off probe for 00270780 family add */
/* measured: itfMesSetSlotNameText MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: lays out the name of the active slot in the current group.
// FUN_00270780
s32 itfMesSetSlotNameText(s32 unusedCommand, u8 *context) {
    u8 nameBuffer[0x20];
    s32 communityId;
    s32 decodedHigh;
    u8 encodedHigh;
    u8 *operand;
    u32 low;
    s32 key;
    u32 base;
    u32 offset;

    base = (u32)((FrFontContext *)context)->position;
    offset = (u32)((FrFontContext *)context)->stream;
    operand = (u8 *)add_retail_ptr(offset, base);
    low = (operand[0] - 1) & 0xFF;
    encodedHigh = operand[1];
    if (encodedHigh == 0xFF) {
        decodedHigh = 0;
    } else {
        decodedHigh = (encodedHigh - 1) & 0xFF;
    }
    key = ((decodedHigh & 0xFF) << 8) | (low & 0xFF);
    communityId = cmmCommunityFindActiveSlotInGroup((s16)key);
    if (frFontGetMode() != 0) {
        return 0;
    }
    frFontUpdateTextWork(context);
    frFontExCopyString(cmmSlotNameRecord(communityId & 0xFFFF), nameBuffer, 0x20);
    frFontLayoutText(nameBuffer, context);
    return 0;
}

/* measured: close opt_propagation off probe for 00270780 family add */
// Intent: lays out the first calendar field (month) as text in the text work.
// FUN_00270870
s32 itfMesSetMonthText(s32 unusedCommand, u8 *context)
{
    s32 month = 0;
    s32 day = 0;
    u8 textBuffer[8];

    if (frFontGetMode() != 0)
        return 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &day);
    sprintf(textBuffer, &iGpffffa738, month);
    frFontUpdateTextWork(context);
    frFontLayoutText(textBuffer, context);
    return 0;
}

// Intent: lays out the second calendar field (day) as text in the text work.
// FUN_00270910
s32 itfMesSetDayText(s32 unusedCommand, u8 *context)
{
    s32 month = 0;
    s32 day = 0;
    u8 textBuffer[8];

    if (frFontGetMode() != 0)
        return 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &day);
    sprintf(textBuffer, &iGpffffa738, day);
    frFontUpdateTextWork(context);
    frFontLayoutText(textBuffer, context);
    return 0;
}

// Intent: copies the weekday name from the table at D_0063BAB0 into the text work.
// FUN_002709B0
s32 itfMesSetWeekdayText(s32 unusedCommand, u8 *context)
{
    struct {
        u8 textBuffer[0x20];
        s8 weekdayTable[0x20];
        u8 pad[0x20];
    } work;
    s8 *src;
    s8 *dst;
    s32 count;
    s8 temp0;
    s8 temp1;

    src = D_0063BAB0;
    dst = work.weekdayTable;
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
    frFontExCopyString(work.weekdayTable + calGetWeekOfYear((s16)datGetDateIndex()) * 8,
                  work.textBuffer, 0x20);
    frFontUpdateTextWork(context);
    frFontLayoutText(work.textBuffer, context);
    return 0;
}

/* measured: opt_propagation off probe for 00270a80 addu order */
// Intent: lays out a community name; the current community is used when the key is 0.
// FUN_00270A80
s32 itfMesSetCommunityNameText(s32 unusedCommand, u8 *context) {
    u8 nameBuffer[0x40];
    s32 value;
    s32 decodedHigh;
    s64 communityId;
    u8 encodedHigh;
    u8 *operand;
    u8 *secondDecodedHigh;
    u32 base;
    u32 offset;

    base = (u32)((FrFontContext *)context)->position;
    offset = (u32)((FrFontContext *)context)->stream;
    operand = (u8 *)add_retail_ptr(offset, base);
    value = (operand[0] - 1) & 0xFF;
    encodedHigh = operand[1];
    if (encodedHigh == 0xFF) {
        decodedHigh = 0;
    } else {
        decodedHigh = (encodedHigh - 1) & 0xFF;
    }
    communityId = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (value & 0xFF));
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (communityId == 0) {
        secondDecodedHigh = cmmNameRecord(cmmCommunityGetCurrentId() & 0xFFFF);
    } else {
        secondDecodedHigh = cmmNameRecord((u16)communityId);
    }
    frFontExCopyString(secondDecodedHigh, nameBuffer, 0x40);
    frFontUpdateTextWork(context);
    frFontLayoutText(nameBuffer, context);
    return 0;
}

/* measured: close opt_propagation off probe for 00270a80 */
/* measured: cmmCommunityClearBrokenCurrent, cmmCommunityClearReverseCurrent, cmmCommunitySetBrokenCurrent, cmmCommunitySetReverseCurrent, cmmCommunityScriptAddPoints MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: script command that adds points to a community; the current community is used when the id is 0.
/* Context +0x10/+0x18 are stream/position; keep pointer-typed raw reads:
 * the canonical s32 fields merge operand reloads and lose the measured retail match. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 123, 139, 181, 183, 188, 190, 200, 202, 213, 274, 277, 470, 471; retain their original address/alias expressions. */
// FUN_00270B80
s32 cmmCommunityScriptAddPoints(s32 unusedCommand, u8 *context)
{
    s64 first;
    s64 second;

    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = (u8 *)((FrFontContext *)context)->position;
        offset = ((FrFontContext *)context)->stream;
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            decodedHigh = 0;
        else
            decodedHigh = (high - 1) & 0xFF;
        first = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)context + 0x18);
        offset = *(s32 *)((u8 *)context + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            decodedHigh = 0;
        else
            decodedHigh = (high - 1) & 0xFF;
        second = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (low & 0xFF));
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
/* Context +0x10/+0x18 are stream/position; keep pointer-typed raw reads:
 * the canonical s32 fields merge operand reloads and lose the measured retail match. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 123, 139, 172, 181, 183, 188, 190, 200, 202, 213, 241, 267, 269, 274, 277, 340, 341, 469, 470, 471; retain their original address/alias expressions. */
// FUN_00270CA0
s32 cmmCommunityScriptAddPointsChecked(s32 unusedCommand, u8 *context)
{
    extern s32 cmmCommunityHasRecord(u16 unusedCommand); /* lint: allow H011 -- measured: the u16 prototype reproduces retail's narrowing at this call; s32 gives nd 44 on cmmCommunityScriptAddPointsChecked */
    extern s32 cmmCommunityAddPoints(s32 unusedCommand, s32 context, s32 count);
    s32 second;
    s32 first;
    s32 third;

    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = *(u8 **)(context + 0x18);
        offset = *(s32 *)(context + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            decodedHigh = 0;
        else
            decodedHigh = (high - 1) & 0xFF;
        first = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (low & 0xFF));
    }
    {
        s32 offset;
        u8 *base;
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)context + 0x18);
        offset = *(s32 *)((u8 *)context + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            decodedHigh = 0;
        else
            decodedHigh = (high - 1) & 0xFF;
        second = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (low & 0xFF));
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
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = ((struct KeyData *)context)->base;
        offset = ((struct KeyData *)context)->offset;
        base += offset;
        low = (base[4] - 1) & 0xFF;
        high = base[5];
        if (high == 0xFF)
            decodedHigh = 0;
        else
            decodedHigh = (high - 1) & 0xFF;
        third = (s64)(s16)(((decodedHigh & 0xFF) << 8) | (low & 0xFF));
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
    s32 communityId;

    if (frFontGetMode() != 0) {
        return 0;
    }
    communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    if (communityId != 0) {
        cmmCommunitySetReversed(communityId & 0xFFFF);
    }
    return 0;
}

// Intent: Clears the reverse flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270E90
s32 cmmCommunityClearReverseCurrent(void) {
    s32 communityId;

    if (frFontGetMode() != 0) {
        return 0;
    }
    communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    if (communityId != 0) {
        cmmCommunityClearReversed(communityId & 0xFFFF);
    }
    return 0;
}

// Intent: Sets the broken flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270EF0
s32 cmmCommunitySetBrokenCurrent(void) {
    s32 communityId;

    if (frFontGetMode() != 0) {
        return 0;
    }
    communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    if (communityId != 0) {
        cmmCommunitySetBroken(communityId & 0xFFFF);
    }
    return 0;
}

// Intent: Clears the broken flag on the current community entry unless the font is in a blocking mode [inferred]
// FUN_00270F50
s32 cmmCommunityClearBrokenCurrent(void) {
    s32 communityId;

    if (frFontGetMode() != 0) {
        return 0;
    }
    communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    if (communityId != 0) {
        cmmCommunityClearBroken(communityId & 0xFFFF);
    }
    return 0;
}

