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
extern void frFontUpdateTextWork(u8 *context);
extern void frFontLayoutText(u8 *text, u8 *context);

extern s32 D_008815B0[];

extern void MT_Scene_SetResMotionSlot(u32 resourceId, s16 firstAnimation, s16 firstFrame, s16 nextAnimation, s16 nextFrame);
extern s32 cmmCommunityFindActiveSlotInGroup(s64 group);
extern u8 *cmmSlotNameRecord(s32 slotId);
extern s32 cmmCommunityGetCurrentId(void);
extern u8 *cmmNameRecord(s32 nameId);

extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 icon);
extern s32 calGetDayWindowFlags(s32 day);
extern s64 fclBankTryQueueRequest(s64 value, s32 index, s64 count);
extern void fclBankSetReadyFlag(void);

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern s16 datGetDateIndex(void);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
extern s32 sprintf(void *value, const void *index, s32 count);
extern u8 iGpffffa738;
extern s32 calGetWeekOfYear(s32 dateIndex);
extern void frFontExCopyString(void *src, void *dst, s32 maxlen);
extern s8 D_0063BAB0[];
extern s32 cmmCommunityGetCurrentId(void);

/* Decode and queue a bank request, deriving its state from calendar flags when unspecified. The
 * context's stream and position fields stay as raw pointer-typed reads because typed fields merge
 * reloads. */
// FUN_00270100
s32 frFontQueueBankRequestCommand(s32 unusedCommand, u8 *context)
{
    FrFontContext *positionFields;
    FrFontContext *streamFields;
    FrFontContext *positionFieldsReload;
    FrFontContext *streamFieldsReload;
    FrFontContext *positionFieldsNextReload;
    FrFontContext *streamFieldsNextReload;

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
        base = *(u8 * *)&(positionFields = (FrFontContext *)(context), positionFields)->position;
        offset = (streamFields = (FrFontContext *)(context), streamFields)->stream;
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
        base = *(u8 * *)&(positionFieldsReload = (FrFontContext *)(context), positionFieldsReload)->position;
        offset = (streamFieldsReload = (FrFontContext *)(context), streamFieldsReload)->stream;
        base = (u8 *)((u32)offset + (u32)base);
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
        base = *(u8 * *)&(positionFieldsNextReload = (FrFontContext *)((u8 *)context), positionFieldsNextReload)->position;
        offset = (streamFieldsNextReload = (FrFontContext *)((u8 *)context), streamFieldsNextReload)->stream;
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

/* Decode the resource and value operands and spawn the corresponding scene icon task. Context
 * stream and position fields stay raw pointer reads because retail reloads each operand. */
// FUN_002703D0
s32 frFontSpawnResourceIconCommand(s32 unusedCommand, u8 *context)
{
    FrFontContext *positionFields;
    FrFontContext *streamFields;

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
        base = (u8 *)((u32)offset + (u32)base);
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
        base = *(u8 * *)&(positionFields = (FrFontContext *)((u8 *)context), positionFields)->position;
        offset = (streamFields = (FrFontContext *)((u8 *)context), streamFields)->stream;
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

/* measured: retail keeps the unrebuilt conditional-branch schedule in
 * frFontSetResourceMotionCommand, which needs opt_rebuildconditionals off. */
#pragma opt_rebuildconditionals off
/* measured: context stream (+0x10) and position (+0x18) stay raw pointer reads because typed s32
 * fields merge the operand reloads retail repeats. */
/* Decode the request key, motion, second key and frame operands from the font command stream and
 * apply them as a resource motion. Does nothing when the font mode is nonzero. */
// FUN_002704F0
s32 frFontSetResourceMotionCommand(s32 unusedCommand, u8 *context)
{
    FrFontContext *positionFields;
    FrFontContext *streamFields;
    FrFontContext *positionFieldsReload;
    FrFontContext *streamFieldsReload;
    FrFontContext *positionFieldsNextReload;
    FrFontContext *streamFieldsNextReload;

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
        base = *(u8 * *)&(positionFields = (FrFontContext *)(context), positionFields)->position;
        offset = (streamFields = (FrFontContext *)(context), streamFields)->stream;
        base = (u8 *)((u32)offset + (u32)base);
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
        base = *(u8 * *)&(positionFieldsReload = (FrFontContext *)((u8 *)context), positionFieldsReload)->position;
        offset = (streamFieldsReload = (FrFontContext *)((u8 *)context), streamFieldsReload)->stream;
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
        base = *(u8 * *)&(positionFieldsNextReload = (FrFontContext *)((const u8 *)context), positionFieldsNextReload)->position;
        offset = (streamFieldsNextReload = (FrFontContext *)((const u8 *)context), streamFieldsNextReload)->stream;
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
        base = *(u8 * *)&((FrFontContext *)((u8 *)(u32)context))->position;
        offset = ((FrFontContext *)((u8 *)(u32)context))->stream;
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

/* Re-lays out the text work with no string while the frFont mode is 0. */
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

/* measured: retail code for itfMesSetSlotNameText is built without copy propagation. */
#pragma opt_propagation off
// Lays out the name of the active slot in the current group.
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
    operand = (u8 *)(offset + base);
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

/* Lays out the first calendar field (month) as text in the text work. */
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

// Lays out the day as text in the text work.
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

// Copies the weekday name from the table at D_0063BAB0 into the text work.
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

/* Lays out a community name; the current community is used when the key is 0. */
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
    operand = (u8 *)(offset + base);
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

/* measured: the community broken/reverse setters and cmmCommunityScriptAddPoints need propagation
 * re-enabled to reproduce retail's operand reloads. */
#pragma opt_propagation on
// Script command that adds points to a community; uses the current community when the id is 0.
// Stream and position are read through raw pointers because typed fields change the output.
// FUN_00270B80
s32 cmmCommunityScriptAddPoints(s32 unusedCommand, u8 *context)
{
    FrFontContext *positionFields;
    FrFontContext *streamFields;

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
        base = (u8 *)((u32)offset + (u32)base);
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

        base = *(u8 * *)&(positionFields = (FrFontContext *)((u8 *)context), positionFields)->position;
        offset = (streamFields = (FrFontContext *)((u8 *)context), streamFields)->stream;
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

// Script command that adds points only when the community record exists. Context stream/position
// fields are read through pointer-typed raw accesses, since the s32 fields merge operand reloads.
// The remaining raw address expressions are intentional.
// FUN_00270CA0
s32 cmmCommunityScriptAddPointsChecked(s32 unusedCommand, u8 *context)
{
    FrFontContext *positionFields;
    FrFontContext *streamFields;
    FrFontContext *positionFieldsReload;
    FrFontContext *streamFieldsReload;

    extern s32 cmmCommunityHasRecord(u16 communityId); /* lint: allow H011 -- the u16 prototype reproduces retail's narrowing of the id at this call. */
    extern s32 cmmCommunityAddPoints(s32 communityId, s32 points, s32 resourceId);
    s32 second;
    s32 first;
    s32 third;

    {
        u8 *base;
        s32 offset;
        s32 decodedHigh;
        u8 high;
        s32 low;

        base = *(u8 * *)&(positionFields = (FrFontContext *)(context), positionFields)->position;
        offset = (streamFields = (FrFontContext *)(context), streamFields)->stream;
        base = (u8 *)((u32)offset + (u32)base);
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

        base = *(u8 * *)&(positionFieldsReload = (FrFontContext *)((u8 *)context), positionFieldsReload)->position;
        offset = (streamFieldsReload = (FrFontContext *)((u8 *)context), streamFieldsReload)->stream;
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

// Sets the reverse flag on the current community entry unless the font is in a mode that blocks it.
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

// Clears the reverse flag on the current community entry unless the font is in a blocking mode.
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

// Sets the broken flag on the current community entry unless the font is in a blocking mode.
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

// Clears the broken flag on the current community entry unless the font is in a blocking mode.
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

