#include "member_access.h"
#include "g_data_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_objects.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc; /* deferred layout pending */
extern s32 iGpffffa730; /* decoded audio/deferred-layout duration */
extern s32 frFontCountRuns(u8 *node);

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 MT_SceneManager_TaskUpdate(u8 *unusedTask);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *value, s32 otherValue, s32 thirdValue,
                           s32 (*fourthValue)(u8 **value, u8 **otherValue));
extern u8 *(*jtbl_008873E8[])(s32 value, s32 otherValue);
extern void *memcpy(void *value, const void *otherValue, u32 thirdValue);
extern void memset(void *value, void *otherValue, s32 thirdValue);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;
extern void PrimDrawContour(f32 x, f32 y, f32 depth,
                          s32 rgb, s32 alpha, s32 unusedMode, s32 shape,
                          s32 originX, s32 originY,
                          f32 rotation, f32 scaleX, f32 scaleY);
extern char iGpffffa6c4;
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u8 *mtSceneBytePairAt(u8 *base, u32 index)
{
    return base + index;
}


extern u8 D_00637420[];

extern s32 datEntryGetFlags(s16 itemId);




extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void frFontSetStateBits(u32 bits, int enable);
extern void datSetFlag(s32 flagId, s32 enabled);
extern s32 cmmCommunityGetCurrentId(void);
extern void cmmCommunitySetReversed(s32 communityId);
extern void cmmCommunityClearReversed(s32 communityId);
extern s32 cmmCommunityAddScaledPoints(s32 communityId, u32 points);
extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity,
                           s32 weather, s32 highlight, f32 scaleX, f32 scaleY,
                           s32 clipLeft, s32 clipWidth, s32 font,
                           s32 forcedHighlight);
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern u32 datGetItemNameId(s16 itemId);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 sdkSndStartIndexedSource(s32 sourceAux, s32 channelIndex, s32 cueId);
extern s32 sdkSndStartChannel(s16 channelIndex, const char *path);
extern s32 D_008815B0[];
extern void frFontUpdateTextWork(u8 *context);
extern void frFontLayoutSlotText(s32 index, u8 *context);
extern u8 iGpffffa734;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0026; members 0026e350-0026f860 */

extern s32 MT_SceneManager_TaskUpdate(u8 *unusedTask);
extern s32 mtSceneUnitDepthCompare(u8 **left, u8 **right);
extern f32 D_007612C4;
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. shdSpriteDrawNowEx's
 * colour parameter is declared u32 here (H011): retail converts arg2 for each
 * call and keeps the per-case colour copies in $fp/$s7. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: optimization-level probe for 00263220 register colouring */
/* measured: closes optimization-level probe for 00263220 */
/* measured: opt_loop_invariants on hoists (u8)opacity into the sq/lq spill retail has (269 -> 253 words on the shape before the statement-ordered font word; off it stays inside the fade block). */
#pragma push
#pragma pop
/* The switch arms are in retail's jump-table order. Locals whose live ranges
 * are disjoint share one variable (temp_18_2/temp_3, temp_17_10/temp_16_2,
 * temp_19_2/temp_17_3, fadeAlpha/temp_17_9, temp_22/temp_17), as retail's
 * register reuse across the cases shows. In case 7's day loop the date is
 * `temp_20` and the `* 0x5E` column is `var_2`, both dead outside that loop:
 * retail's register numbering follows which variable each value lives in, and
 * these give the $s3/$s4/$s5 order of the product, date and font word. The
 * render-state table goes through a u32 local, both fade rectangles are
 * {x,y,w,h} structs copied into the 16-byte argument, the case-5 and case-7
 * fallback tails are separate copies, and `temp_3_2 > 1` gives the slti $at
 * form. opt_lifetimes on is measured (102 -> 85 edits without the other levers). */
#pragma push
#pragma pop
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
/* measured: closes the optimization_level bracket (nd 0). */
/* Copy complete table objects; renderer callbacks may change the item index. */
/* measured: 1296B/1296B.  Scalar out-parameters and CefV3 locals give the
   retail frame; the s8 count local and the named segment index give the
   hoisted point base under opt_loop_invariants; the control-point counters
   are block-scoped so the sampling counter k is coloured first. */
#pragma push
/* measured: without it the point base is recomputed per iteration (271). */
#pragma pop
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
/* measured: closes opt_propagation off probe for func_0026db60. */
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: opt_propagation off probe for mtSceneUnitDepthCompare float load scheduling. */
/* measured: closes opt_propagation off probe for mtSceneUnitDepthCompare. */
// Intent: Return the pending-layout flag; frFontBeginDeferredLayout sets it and frFontResetPendingState clears it [inferred]
// FUN_0026E350
s32 frFontGetPendingFlag(void)
{
    return iGpffffb4bc;
}

// Intent: Map a data entry's flag bits to a glyph class index from 0 to 14 (default 13) [inferred]
// FUN_0026E360
s32 frFontDataEntryClass(s64 entryId) {
    s32 flags = datEntryGetFlags((s16) entryId);

    if (flags & 1) {
        return 0;
    }
    if (flags & 2) {
        return 1;
    }
    if (flags & 4) {
        return 2;
    }
    if (flags & 8) {
        return 3;
    }
    if (flags & 0x10) {
        return 4;
    }
    if (flags & 0x20) {
        return 5;
    }
    if (flags & 0x40) {
        return 6;
    }
    if (flags & 0x4000) {
        return 9;
    }
    if (flags & 0x8000) {
        return 0xB;
    }
    if (flags & 0x10000) {
        return 0xD;
    }
    if (flags & 0x20000) {
        return 0xE;
    }
    if (flags & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

/* measured: opt_propagation off probe for func_0026e4c0 field-load order. */
/* measured: func_0026e4c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0026E4C0
/* Decode the palette operand in layout mode; return zero to continue parsing. */
s32 frFontCommandSetPalette(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    ((FrFontContext *)context)->palette = (s8)(s16)((highPart << 8) | (u8)lowByte);
    return 0;
}

/* measured: closing opt_propagation off probe for func_0026e4c0. */
/* Accept the no-op dispatch entry after palette assignment; sample mode and continue command parsing. */
// FUN_0026E560
/* Probe the current mode without stopping script parsing. */
s32 frFontCommandPostPaletteNoop(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off forces func_0026e590 field-load order. */
// FUN_0026E590
/* Decode the font style operand in layout mode. */
s32 frFontCommandSetStyle(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    ((FrFontContext *)context)->style = (s8)(s16)((highPart << 8) | (u8)lowByte);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e590. */
/* measured: opt_propagation off forces func_0026e630 field-load order. */
// FUN_0026E630
/* Decode the intensity operand in layout mode. */
s32 frFontCommandSetIntensity(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    ((FrFontContext *)context)->intensity = (s8)(s16)((highPart << 8) | (u8)lowByte);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e630. */
/* Accept the no-op dispatch entry after intensity assignment; sample mode and continue command parsing. */
// FUN_0026E6D0
/* Probe the current mode without stopping script parsing. */
s32 frFontCommandPostIntensityNoop(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off preserves field-load order for func_0026e700. */
// FUN_0026E700
/* Decode the intensity and height operands in layout mode. */
s32 frFontCommandSetIntensityAndHeight(s32 command, u8 *context)
{
    /* FrFontContext/FrFontTextRun offsets are proven in fr_font_objects.h;
     * typed access changes MWCC alias scheduling here (measured MISMATCH). */
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    streamOffset = ((FrFontContext *)(context))->position;
    streamAddress = ((FrFontContext *)(context))->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    ((FrFontContext *)(context))->intensity = (s8)(s16)((highPart << 8) | (u8)lowByte);
    streamOffset = MEMBER(s32, context, FrFontContext, position);
    streamAddress = MEMBER(s32, context, FrFontContext, stream);
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (operandBytes[2] - 1) & 0xFF;
    highByte = operandBytes[3];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    ((FrFontContext *)(context))->height = (s16)((highPart << 8) | (u8)lowByte);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e700. */
/* measured: opt_common_subs off forces func_0026e7f0 field reloads. */
/* measured: func_0026e7f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves field-load order for func_0026e7f0. */
// FUN_0026E7F0
/* Decode and store position in horizontal sixteenths and vertical eighths. */
s32 frFontCommandSetPosition(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    s32 highByte;
    u8 *operandBytes;
    s32 firstOperand;
    s32 secondOperand;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if ((u8)highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    firstOperand = (s32)(s16)((highPart << 8) | (u8)lowByte);
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (operandBytes[2] - 1) & 0xFF;
    highByte = operandBytes[3];
    if ((u8)highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    secondOperand = (s32)(s16)((highPart << 8) | (u8)lowByte);
    if (frFontGetMode() == 0) {
        goto success;
    }
    if (frFontGetMode() != 1) {
        return 0;
    }
success:
    ((FrFontContext *)context)->x = firstOperand << 4;
    ((FrFontContext *)context)->y = secondOperand << 3;
    return 0;
}

/* measured: closing opt_common_subs off for func_0026e7f0. */
/* measured: func_0026e910, func_0026e940, frFontBeginDeferredLayout, func_0026eba0, func_0026ebe0, func_0026ed00, func_0026ee00 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026e7f0. */
// FUN_0026E910
/* Mark script termination and stop parsing. */
s32 frFontCommandEnd(void)
{
    frFontSetStateBits(1, 1);
    return 1;
}

/* measured: opt_propagation off preserves decode and field-store order for func_0026e940. */
// FUN_0026E940
/* Store a nonnegative wait duration and set state bit 0x20. */
s32 frFontCommandSetWait(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;
    s32 firstOperand;
    s32 duration;
    u8 *durationAddress;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    firstOperand = (s32)(s16)((highPart << 8) | (u8)lowByte);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (((FrFontTextRun *)((FrFontContext *)context)->list)->unk34 != 0) {
        ((FrFontTextRun *)((FrFontContext *)context)->list)->unk38 = 1;
    }
    ((FrFontTextRun *)((FrFontContext *)context)->list)->command = command;
    ((FrFontTextRun *)((FrFontContext *)context)->list)->duration = (s32)(s16)firstOperand;
    durationAddress = (u8 *)&((FrFontTextRun *)((FrFontContext *)context)->list)->duration;
    duration = ((FrFontTextRun *)((FrFontContext *)context)->list)->duration;
    if (duration < 0) {
        *(s32 *)durationAddress = 0;
    }
    frFontSetStateBits(0x20, 1);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e940. */
/* measured: opt_propagation off preserves decode and state-store order for frFontBeginDeferredLayout. */
// Intent: Start a deferred layout when data flag 0x3B is set: store the operand, set the pending flag and state bit 0x10 [inferred]
// FUN_0026EA50
s32 frFontBeginDeferredLayout(s32 command, u8 *context)
{
    /* FrFontContext/FrFontTextRun offsets are proven in fr_font_objects.h;
     * typed access changes MWCC alias scheduling here (measured MISMATCH). */
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;
    s32 firstOperand;
    s32 runCount;
    s32 scaledRunCount;

    streamOffset = ((FrFontContext *)(context))->position;
    streamAddress = ((FrFontContext *)(context))->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    firstOperand = (s32)(s16)((highPart << 8) | (u8)lowByte);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (datGetFlag(0x3B) == 0) {
        return 0;
    }
    if (((FrFontTextRun *)(*(u8 * *)&((FrFontContext *)(context))->list))->unk34 != 0) {
        ((FrFontTextRun *)(*(u8 * *)&((FrFontContext *)(context))->list))->unk38 = 1;
    }
    ((FrFontTextRun *)(MEMBER(u8 *, context, FrFontContext, list)))->command = command;
    if (iGpffffa730 != 0) {
        goto direct_store;
    }
    runCount = frFontCountRuns(MEMBER(u8 *, context, FrFontContext, list));
    scaledRunCount = runCount << 4;
    runCount = scaledRunCount - runCount;
    scaledRunCount = runCount << 2;
    ((FrFontTextRun *)(MEMBER(u8 *, context, FrFontContext, list)))->duration = scaledRunCount;
    goto after_store;
direct_store:
    ((FrFontTextRun *)(MEMBER(u8 *, context, FrFontContext, list)))->duration = (s32)(s16)firstOperand;
after_store:
    iGpffffa730 = -1;
    iGpffffb4bc = 1;
    frFontSetStateBits(0x10, 1);
    return 0;
}

/* measured: closing opt_propagation off for frFontBeginDeferredLayout. */
// FUN_0026EBA0
/* Set both termination state bits and stop parsing. */
s32 frFontCommandEndAndSignal(void)
{
    frFontSetStateBits(1, 1);
    frFontSetStateBits(2, 1);
    return 1;
}

/* measured: opt_propagation off preserves target scan preheader ordering. */
/* measured: opt_loop_invariants on hoists the decode mask assignment to the target preheader. */
/* measured: func_0026ebe0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0026EBE0
/* Copy encoded text through the next newline and advance the stream. */
s32 frFontCommandCopyLine(s32 command, u8 *context)
{
    /* FrFontContext/FrFontTextRun offsets are proven in fr_font_objects.h;
     * typed access changes MWCC alias scheduling here (measured MISMATCH). */
    s32 byteIndex;
    s32 byteCount;
    s32 terminator;
    s32 byte;
    s32 streamOffset;
    s32 commandMask;
    u8 *streamBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    byteCount = 0;
    streamOffset = ((FrFontContext *)(context))->position;
    terminator = ((FrFontContext *)(context))->stream;
    streamBytes = (u8 *)(terminator + streamOffset);
    goto scan_loop;
decode:
    if ((byte & 0xF0) == (commandMask = 0xF0)) {
        byteCount += (((byte & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)byte < 0x80U) {
        goto scan_loop;
    }
    byteCount += 1;
    goto scan_loop;
scan_loop:
    byteIndex = byteCount;
    byteCount += 1;
    byte = ((s8 *)streamBytes)[byteIndex];
    terminator = 0xA;
    if (byte != terminator) {
        goto decode;
    }
    memset(&D_00881530, 0, 0x80);
    memcpy(&D_00881530,
                  (void *)(MEMBER(s32, context, FrFontContext, stream) + MEMBER(s32, context, FrFontContext, position)),
                  byteCount);
    /* The terminator uses the linker symbol one byte before the text buffer. */
    *((u8 *)((s32)&D_0088152F + byteCount)) = 0;
    frFontSetStateBits(4, 1);
    MEMBER(s32, context, FrFontContext, position) = MEMBER(s32, context, FrFontContext, position) + byteCount;
    return 0;
}

/* measured: closes the opt_loop_invariants and opt_propagation probes at the file baseline. */
/* measured: opt_propagation off preserves decode and state-store order for func_0026ed00. */
// FUN_0026ED00
/* Store a wait duration, using 35 unless data flag 0x3A permits the operand. */
s32 frFontCommandSetConditionalWait(s32 command, u8 *context)
{
    /* FrFontContext/FrFontTextRun offsets are proven in fr_font_objects.h;
     * typed access changes MWCC alias scheduling here (measured MISMATCH). */
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;

    if (frFontGetMode() != 0) {
        return 0;
    }
    if (((FrFontTextRun *)(MEMBER(u8 *, context, FrFontContext, list)))->unk34 != 0) {
        ((FrFontTextRun *)(*(u8 * *)&((FrFontContext *)(context))->list))->unk38 = 1;
    }
    ((FrFontTextRun *)(MEMBER(u8 *, context, FrFontContext, list)))->command = command;
    if (datGetFlag(0x3A) == 0) {
        ((FrFontTextRun *)(*(u8 * *)&((FrFontContext *)(context))->list))->duration = 0x23;
    } else {
        streamOffset = ((FrFontContext *)(context))->position;
        streamAddress = ((FrFontContext *)(context))->stream;
        operandBytes = (u8 *)(streamAddress + streamOffset);
        lowByte = (operandBytes[0] - 1) & 0xFF;
        highByte = operandBytes[1];
        if (highByte == 0xFF) {
            highPart = 0;
        } else {
            highPart = (highByte - 1) & 0xFF;
        }
        highPart &= 0xFF;
        ((FrFontTextRun *)(*(u8 * *)&((FrFontContext *)(context))->list))->duration =
            (s32)(s16)((highPart << 8) | (u8)lowByte);
    }
    return 0;
}

/* measured: closing opt_propagation off for func_0026ed00. */
/* measured: opt_propagation off preserves decode and state-store order for func_0026ee00. */
// FUN_0026EE00
/* Store a nonnegative decoded duration in layout mode. */
s32 frFontCommandSetDuration(s32 command, u8 *context)
{
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;
    s32 firstOperand;
    s32 duration;
    u8 *durationAddress;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    firstOperand = (s32)(s16)((highPart << 8) | (u8)lowByte);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (((FrFontTextRun *)((FrFontContext *)context)->list)->unk34 != 0) {
        ((FrFontTextRun *)((FrFontContext *)context)->list)->unk38 = 1;
    }
    ((FrFontTextRun *)((FrFontContext *)context)->list)->command = command;
    ((FrFontTextRun *)((FrFontContext *)context)->list)->duration = (s32)(s16)firstOperand;
    durationAddress = (u8 *)&((FrFontTextRun *)((FrFontContext *)context)->list)->duration;
    duration = ((FrFontTextRun *)((FrFontContext *)context)->list)->duration;
    if (duration < 0) {
        *(s32 *)durationAddress = 0;
    }
    return 0;
}

/* measured: closing opt_propagation off for func_0026ee00. */
// Intent: Reset the pending-layout flag and set the default values at +0xF and +0x1E [inferred]
// FUN_0026EF00
s32 frFontResetPendingState(s32 command, u8 *context)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    ((FrFontContext *)context)->intensity = 0x14;
    ((FrFontContext *)context)->height = 0x20;
    iGpffffb4bc = 0;
    return 0;
}

/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026ef60. */
/* measured: func_0026ef60 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026ef60. */
// FUN_0026EF60
/* Set a data flag using the decoded table selector and relative index. */
s32 frFontSetDataFlagTable(s32 command, u8 *context)
{
    s32 tableIndex;
    s32 signedIndex;
    s32 signedOffset;
    s32 flagOffset;
    s32 flagBases[5];
    u8 *sourceBytes;
    u8 *destinationBytes;
    s32 copiedWord;
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 firstOperand;
    s32 highPart;
    s32 secondHighPart;
    s32 wordsRemaining;

    s32 packedIndex;
    s32 highByte;
    s32 secondHighByte;
    u8 *operandBytes;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (s32)((operandBytes[0] - 1) & 0xFF);
    highByte = operandBytes[1];
    if ((u8)highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    packedIndex = (((highPart & 0xFF) << 8) |
                  (lowByte & 0xFF));
    signedIndex = (s64)(s16)packedIndex;
    tableIndex = signedIndex;
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    firstOperand = (s32)((operandBytes[2] - 1) & 0xFF);
    secondHighByte = operandBytes[3];
    if ((u8)secondHighByte == 0xFF) {
        secondHighPart = 0;
    } else {
        secondHighPart = (secondHighByte - 1) & 0xFF;
    }
    signedOffset = (s64)(s16)((((secondHighPart & 0xFF) << 8) |
                          (firstOperand & 0xFF)));
    flagOffset = signedOffset;

    if (frFontGetMode() != 0) {
        return 0;
    }
    sourceBytes = (u8 *)&D_0063BA30[0];
    destinationBytes = (u8 *)&flagBases[0];
    wordsRemaining = 5;
    do {
        copiedWord = *(s32 *)sourceBytes;
        sourceBytes += 4;
        wordsRemaining -= 1;
        *(s32 *)destinationBytes = copiedWord;
        destinationBytes += 4;
    } while (wordsRemaining > 0);
    datSetFlag(flagOffset + flagBases[tableIndex], 1);
    return 0;
}

/* measured: closing opt_propagation off for func_0026ef60. */
/* measured: closing opt_common_subs off for func_0026ef60. */
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for frFontClearDataFlagTable. */
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for frFontClearDataFlagTable. */
// Intent: Clear a data flag at the base plus the table entry picked by the first operand [inferred]
// FUN_0026F0A0
s32 frFontClearDataFlagTable(s32 command, u8 *context)
{
    s32 tableIndex;
    s32 signedIndex;
    s32 signedOffset;
    s32 flagOffset;
    s32 flagBases[5];
    u8 *sourceBytes;
    u8 *destinationBytes;
    s32 copiedWord;
    s32 lowByte;
    s32 streamAddress;
    s32 streamOffset;
    s32 firstOperand;
    s32 highPart;
    s32 secondHighPart;
    s32 wordsRemaining;

    s32 packedIndex;
    s32 highByte;
    s32 secondHighByte;
    u8 *operandBytes;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (s32)((operandBytes[0] - 1) & 0xFF);
    highByte = operandBytes[1];
    if ((u8)highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    packedIndex = (((highPart & 0xFF) << 8) |
                  (lowByte & 0xFF));
    signedIndex = (s64)(s16)packedIndex;
    tableIndex = signedIndex;
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    firstOperand = (s32)((operandBytes[2] - 1) & 0xFF);
    secondHighByte = operandBytes[3];
    if ((u8)secondHighByte == 0xFF) {
        secondHighPart = 0;
    } else {
        secondHighPart = (secondHighByte - 1) & 0xFF;
    }
    signedOffset = (s64)(s16)((((secondHighPart & 0xFF) << 8) |
                          (firstOperand & 0xFF)));
    flagOffset = signedOffset;

    if (frFontGetMode() != 0) {
        return 0;
    }
    sourceBytes = (u8 *)&D_0063BA30[0];
    destinationBytes = (u8 *)&flagBases[0];
    wordsRemaining = 5;
    do {
        copiedWord = *(s32 *)sourceBytes;
        sourceBytes += 4;
        wordsRemaining -= 1;
        *(s32 *)destinationBytes = copiedWord;
        destinationBytes += 4;
    } while (wordsRemaining > 0);
    datSetFlag(flagOffset + flagBases[tableIndex], 0);
    return 0;
}

/* measured: closing opt_propagation off for frFontClearDataFlagTable. */
/* measured: frFontLayoutSlotIfBound MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for frFontClearDataFlagTable. */
/* measured: frFontLayoutSlotIfBound MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// Intent: When the slot for the decoded index is bound, update the text work and lay out that slot [inferred]
// FUN_0026F1E0
s32 frFontLayoutSlotIfBound(s32 command, u32 contextAddress, s32 unused)
{
    s32 slotIndex;
    s32 lowByte;
    s32 streamOffset;
    s32 streamAddress;
    s32 highPart;
    u8 highByte;
    u8 *operandBytes;
    u8 *context;

    context = (u8 *)contextAddress;
    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = mtSceneBytePairAt((u8 *)streamAddress, (u32)streamOffset);
    lowByte = (operandBytes[0] - 1) & 0xFF;
    highByte = operandBytes[1];
    if (highByte == 0xFF) {
        highPart = 0;
    } else {
        highPart = (highByte - 1) & 0xFF;
    }
    highPart &= 0xFF;
    slotIndex = (u16)(s16)((highPart << 8) | (u8)lowByte);
    slotIndex &= 0xFFFF;
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (D_008815B0[slotIndex & 0xFFFF] != 0) {
        frFontUpdateTextWork(context);
        frFontLayoutSlotText(slotIndex & 0xFF, context);
    }
    return 0;
}

// Intent: Decode three operands; for a bound slot, lay out a glyph from the second operand, or the item name for the third [inferred]
// FUN_0026F2C0
/* measured: MWCCPS2 b210 -O2, 724B/window 736B, 16 relocations,
 * 12 zero alignment bytes. Ghidra/IDA and retail agree on the three-byte
 * glyph at sp+0x68: align the real buffer to eight, without enlarging it.
 * The scoped options preserve operand reloads and decode scheduling. */
#pragma push
/* measured: frFontLayoutSlotCommand MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: frFontLayoutSlotCommand MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 frFontLayoutSlotCommand(s32 command, u8 *context)
{
    s32 first;
    s32 second;
    s64 third;
    s32 *slot;
    u8 previousPalette;
    s32 streamOffset;
    s32 streamAddress;
    u8 *stream;
    s32 low;
    s32 highByte;
    s32 firstHighPart;
    s32 secondHighPart;
    s32 thirdHighPart;
    s32 forcePalette;
    s32 characterCode;
    s8 glyph[3] __attribute__((aligned(8)));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    stream = mtSceneBytePairAt((u8 *)streamAddress, (u32)streamOffset);
    low = (stream[0] - 1) & 0xFF;
    highByte = stream[1];
    if (highByte == 0xFF) {
        firstHighPart = 0;
    } else {
        firstHighPart = (highByte - 1) & 0xFF;
    }
    first = (u16)(s16)(((firstHighPart & 0xFF) << 8) | (low & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    stream = (u8 *)((u32)streamOffset + (u32)streamAddress);
    low = (stream[2] - 1) & 0xFF;
    highByte = stream[3];
    if (highByte == 0xFF) {
        secondHighPart = 0;
    } else {
        secondHighPart = (highByte - 1) & 0xFF;
    }
    second = (u16)(s16)(((secondHighPart & 0xFF) << 8) | (low & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    stream = (u8 *)((u32)streamOffset + (u32)streamAddress);
    low = (stream[4] - 1) & 0xFF;
    highByte = stream[5];
    if (highByte == 0xFF) {
        thirdHighPart = 0;
    } else {
        thirdHighPart = (highByte - 1) & 0xFF;
    }
    third = (u16)(s16)(((thirdHighPart & 0xFF) << 8) | (low & 0xFF));

    if (frFontGetMode() != 0) {
        return 0;
    }
    slot = &D_008815B0[(u16)third];
    if (*slot != 0) {
        previousPalette = context[0xD];
        /* Retail compares a zero-extended halfword with signed -1. */
        if ((first & 0xFFFF) != -1) {
            context[0xD] = first;
        }
        characterCode = second & 0xFFFF;
        if (characterCode != 0xFFFF) {
            glyph[0] = -0x7D;
            glyph[1] = characterCode + 0xC7;
            glyph[2] = 0;
            frFontUpdateTextWork(context);
            frFontLayoutText((u8 *)glyph, context);
            frFontUpdateTextWork(context);
            frFontLayoutSlotText((u8)third, context);
            context[0xD] = previousPalette;
        } else {
            third = *(s32 *)*slot;
            switch (frFontDataEntryClass(third)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 9:
            case 11:
                forcePalette = 1;
                break;
            default:
                forcePalette = 0;
                break;
            }
            if (forcePalette != 0) {
                context[0xD] = 4;
            }
            glyph[0] = -0x7D;
            glyph[1] = frFontDataEntryClass(third) + 0xC7;
            glyph[2] = 0;
            frFontUpdateTextWork(context);
            frFontLayoutText((u8 *)glyph, context);
            frFontUpdateTextWork(context);
            frFontLayoutText((u8 *)datGetItemNameId((s16)third), context);
            context[0xD] = previousPalette;
        }
    }
    return 0;
}

#pragma pop
/* measured: optimization_level 0 probe for the retail redundant return branch. */
/* measured: func_0026f5a0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 0
// FUN_0026F5A0
/* Probe whether script execution is in mode two; always continue. */
s32 frFontCommandCheckControlMode(void)
{
    if (frFontGetMode() != 2) {
        return 0;
    }
    return 0;
}

/* measured: closes optimization_level 0 around func_0026f5a0. */
/* measured: frFontRunCommunityCommand, frFontRunAudioCommand MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: opt_common_subs off preserves the per-decode pointer recompute for frFontRunCommunityCommand. */
/* measured: opt_propagation off preserves the byte-decode temporary liveness for frFontRunCommunityCommand. */
#pragma push
/* measured: frFontRunCommunityCommand MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// Intent: Run a community command in mode 3: set or clear the reversed flag, or add scaled points, for the current community [inferred]
// FUN_0026F5E0
s32 frFontRunCommunityCommand(s32 command, u8 *context)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 flagBases[5];
    s32 streamOffset;
    s32 streamAddress;
    s32 lowByte;
    s32 highByte;
    s32 firstHighPart;
    s32 secondHighPart;
    s32 thirdHighPart;
    s32 fourthHighPart;
    s32 copiedWord;
    s32 *src;
    s32 *dst;
    s32 i;
    u8 *operandBytes;

    if (frFontGetMode() != 3) {
        return 0;
    }

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (s32)((operandBytes[0] - 1) & 0xFF);
    highByte = operandBytes[1];
    if ((u8)highByte == 0xFF) {
        firstHighPart = 0;
    } else {
        firstHighPart = (highByte - 1) & 0xFF;
    }
    first = (s64)(s16)(((firstHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[2] - 1) & 0xFF);
    highByte = operandBytes[3];
    if ((u8)highByte == 0xFF) {
        secondHighPart = 0;
    } else {
        secondHighPart = (highByte - 1) & 0xFF;
    }
    second = (s64)(s16)(((secondHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[4] - 1) & 0xFF);
    highByte = operandBytes[5];
    if ((u8)highByte == 0xFF) {
        thirdHighPart = 0;
    } else {
        thirdHighPart = (highByte - 1) & 0xFF;
    }
    third = (s64)(s16)(((thirdHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[6] - 1) & 0xFF);
    highByte = operandBytes[7];
    if ((u8)highByte == 0xFF) {
        fourthHighPart = 0;
    } else {
        fourthHighPart = (highByte - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((fourthHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    switch (first) {
    case 0:
        src = (s32 *)&D_0063BA30[0];
        dst = &flagBases[0];
        i = 5;
        do {
            copiedWord = *src;
            src += 1;
            i -= 1;
            *dst = copiedWord;
            dst += 1;
        } while (i > 0);
        datSetFlag(third + flagBases[second], fourth);
        break;
    case 1:
        if (fourth != 0) {
            cmmCommunitySetReversed(cmmCommunityGetCurrentId());
        } else {
            cmmCommunityClearReversed(cmmCommunityGetCurrentId());
        }
        break;
    case 2:
    case 3:
        cmmCommunityAddScaledPoints(cmmCommunityGetCurrentId(), fourth & 0xFFFF);
        break;
    case 6:
    default:
        break;
    }
    return 0;
}

/* measured: closing opt_common_subs off for frFontRunCommunityCommand. */
/* measured: closing opt_propagation off for frFontRunCommunityCommand. */
#pragma pop
/* measured: MWCCPS2 b210 -O2, 832B/window 832B, 16 relocations.
 * Ghidra gives the descending dispatch; IDA gives the 64-byte path buffer.
 * Named action/channel values survive their comparisons into case one.
 * The final switch preserves retail's explicit zero/default branches.
 * The sound provider narrows the fourth operand at its halfword store. */
// Intent: Run an audio command in mode 1 when flag 0x3A is set: start a sound channel with formatted text or send the operands to the audio handler [inferred]
// FUN_0026F860
#pragma push
/* measured: frFontRunAudioCommand MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: frFontRunAudioCommand MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 frFontRunAudioCommand(s32 command, u8 *context)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s8 soundPath[0x40];
    s32 streamOffset;
    s32 streamAddress;
    s32 lowByte;
    s32 highByte;
    s32 firstHighPart;
    s32 secondHighPart;
    s32 thirdHighPart;
    s32 fourthHighPart;
    s32 action;
    s32 channel;
    u8 *operandBytes;

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamAddress + streamOffset);
    lowByte = (s32)((operandBytes[0] - 1) & 0xFF);
    highByte = operandBytes[1];
    if ((u8)highByte == 0xFF) {
        firstHighPart = 0;
    } else {
        firstHighPart = (highByte - 1) & 0xFF;
    }
    first = (s64)(s16)(((firstHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[2] - 1) & 0xFF);
    highByte = operandBytes[3];
    if ((u8)highByte == 0xFF) {
        secondHighPart = 0;
    } else {
        secondHighPart = (highByte - 1) & 0xFF;
    }
    second = (s64)(s16)(((secondHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[4] - 1) & 0xFF);
    highByte = operandBytes[5];
    if ((u8)highByte == 0xFF) {
        thirdHighPart = 0;
    } else {
        thirdHighPart = (highByte - 1) & 0xFF;
    }
    third = (s64)(s16)(((thirdHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamAddress = ((FrFontContext *)context)->stream;
    operandBytes = (u8 *)(streamOffset + streamAddress);
    lowByte = (s32)((operandBytes[6] - 1) & 0xFF);
    highByte = operandBytes[7];
    if ((u8)highByte == 0xFF) {
        fourthHighPart = 0;
    } else {
        fourthHighPart = (highByte - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((fourthHighPart & 0xFF) << 8) | (lowByte & 0xFF));

    iGpffffa730 = -1;
    if (frFontGetMode() == 0) {
        if (first == 1) {
            iGpffffa730 = fourth;
        }
    }
    if (frFontGetMode() != 1) {
        return 0;
    }
    if (datGetFlag(0x3A) == 0) {
        return 0;
    }

    if (first == 4) goto L4;
    if (first == 3) goto L3;
    action = 2;
    if (first == action) goto L2;
    channel = 1;
    if (first == channel) goto L1;
    switch (first) {
    case 0:
        goto L0;
    default:
        goto Lend;
    }

L0:
    if ((second >= 0) && (second < 0x191)) {
        sprintf((char *)soundPath, D_0063BA50, second, third, second, third, fourth);
    } else if ((second >= 0x191) && (second < 0x1F5)) {
        sprintf((char *)soundPath, D_0063BA80, second, third / 0x14, second, third, fourth);
    }
    sdkSndStartChannel(1, (const char *)soundPath);
    goto Lend;

L1:
    if (fourth != 0) {
        sdkSndStartIndexedSource(action, channel, fourth);
    }
    goto Lend;

L2:
    sdkSndStartIndexedSource(third, 1, fourth);
    goto Lend;

L3:
    sdkSndStartIndexedSource(third, 1, fourth);
    goto Lend;

L4:
    sdkSndStartIndexedSource(third, 1, fourth);
    goto Lend;

Lend:
    return 0;
}
#pragma pop

