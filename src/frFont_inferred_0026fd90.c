#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_objects.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

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
extern void qsort(u32 *value, s32 index, s32 count,
                           s32 (*flags)(u8 **value, u8 **index));
extern u8 *(*jtbl_008873E8[])(s32 value, s32 index);
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
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);


extern u8 D_00637420[];


extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity,
                           s32 weather, s32 highlight, f32 scaleX, f32 scaleY,
                           s32 clipLeft, s32 clipWidth, s32 font,
                           s32 forcedHighlight);
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern u32 datGetItemNameId(s16 itemId);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern void frFontUpdateTextWork(u8 *context);
extern u8 iGpffffa734;

extern s32 frFontDataEntryClass(s64 entryId);

extern s32 MT_SceneManager_TaskUpdate(u8 *unusedTask);
extern s32 mtSceneUnitDepthCompare(u8 **left, u8 **right);
extern f32 D_007612C4;
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: loop-invariant hoisting is on so (u8)opacity is hoisted out of the fade block into the
 * stack spill retail has. */
#pragma push
#pragma pop
/* Switch arms follow retail's jump-table order; locals with disjoint live ranges share one
 * variable, matching retail's register reuse across cases. */
#pragma push
#pragma pop
/* measured: copy whole table objects because renderer callbacks may change the item index; the s8
 * count and block-scoped counters reproduce retail register order. */
#pragma push
/* measured: without loop-invariant hoisting the point base is recomputed every iteration. */
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Decode the palette, prefix flag and item ID, then append the item name. */
// FUN_0026FD90
/* measured: retail aligns the three-byte glyph buffer to eight bytes. */
#pragma push
/* measured: retail reloads operands instead of reusing common subexpressions. */
#pragma opt_common_subs off
/* measured: retail's decode scheduling needs copy propagation off. */
#pragma opt_propagation off
s32 frFontAppendItemNameCommand(s32 unusedCommand, u8 *context)
{
    u8 previousPalette;
    s32 first;
    s64 second;
    s32 third;
    s8 glyph[3] __attribute__((aligned(8)));
    s32 streamOffset;
    s32 streamBase;
    u8 *stream;
    s32 low;
    s32 highByte;
    s32 firstHigh;
    s32 secondHigh;
    s32 thirdHigh;
    s32 forcePalette;
    streamOffset = ((FrFontContext *)context)->position;
    streamBase = ((FrFontContext *)context)->stream;
    stream = (((u8 *)streamBase) + (u32)streamOffset);
    low = (stream[0] - 1) & 0xFF;
    highByte = stream[1];
    if (highByte == 0xFF) {
        firstHigh = 0;
    } else {
        firstHigh = (highByte - 1) & 0xFF;
    }
    first = (u16)(s16)(((firstHigh & 0xFF) << 8) | (low & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamBase = ((FrFontContext *)context)->stream;
    stream = (u8 *)((u32)streamOffset + (u32)streamBase);
    low = (stream[2] - 1) & 0xFF;
    highByte = stream[3];
    if (highByte == 0xFF) {
        secondHigh = 0;
    } else {
        secondHigh = (highByte - 1) & 0xFF;
    }
    second = (u16)(s16)(((secondHigh & 0xFF) << 8) | (low & 0xFF));

    streamOffset = ((FrFontContext *)context)->position;
    streamBase = ((FrFontContext *)context)->stream;
    stream = (u8 *)((u32)streamOffset + (u32)streamBase);
    low = (stream[4] - 1) & 0xFF;
    highByte = stream[5];
    if (highByte == 0xFF) {
        thirdHigh = 0;
    } else {
        thirdHigh = (highByte - 1) & 0xFF;
    }
    third = (u16)(s16)(((thirdHigh & 0xFF) << 8) | (low & 0xFF));

    if (frFontGetMode() != 0) {
        return 0;
    }
    if ((first & 0xFFFF) != -1) {
        previousPalette = ((FrFontContext *)context)->palette;
        ((FrFontContext *)context)->palette = first;
    }
    if ((u16)second != 0) {
        second = (u16)third;
        switch (frFontDataEntryClass(second)) {
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
            ((FrFontContext *)context)->palette = 4;
        }
        glyph[0] = -0x7D;
        glyph[1] = frFontDataEntryClass(second) + 0xC7;
        glyph[2] = 0;
        frFontUpdateTextWork(context);
        frFontLayoutText((u8 *)glyph, context);
    }
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)datGetItemNameId((s16)third), context);
    ((FrFontContext *)context)->palette = previousPalette;
    return 0;
}

#pragma pop
/* measured: with common-subexpression elimination off, retail reloads the context fields on each
 * access in func_0026fff0. */
#pragma opt_common_subs off
/* measured: retail keeps decoded values in place instead of propagating copies, which preserves the
 * decode instruction order. */
#pragma opt_propagation off
/* Decode an item ID and byte count and update the inventory in normal mode. */
// FUN_0026FFF0
s32 frFontSetItemCountCommand(s32 unusedCommand, u8 *context)
{
    s32 itemId;
    s32 itemCount;
    s32 lowByte;
    s32 firstHigh;
    s32 secondHigh;
    s32 firstOffset;
    s32 firstBase;
    s32 secondOffset;
    s32 secondBase;
    s32 firstEncodedHigh;
    s32 secondEncodedHigh;
    u8 *firstOperand;
    u8 *secondOperand;

    firstOffset = ((FrFontContext *)context)->position;
    firstBase = ((FrFontContext *)context)->stream;
    firstOperand = (u8 *)(firstBase + firstOffset);
    lowByte = (firstOperand[0] - 1) & 0xFF;
    firstEncodedHigh = firstOperand[1];
    if ((u8)firstEncodedHigh == 0xFF) {
        firstHigh = 0;
    } else {
        firstHigh = (firstEncodedHigh - 1) & 0xFF;
    }
    firstHigh &= 0xFF;
    itemId = (s32)(s16)((firstHigh << 8) | (u8)lowByte);
    secondOffset = ((FrFontContext *)context)->position;
    secondBase = ((FrFontContext *)context)->stream;
    secondOperand = (u8 *)(secondOffset + secondBase);
    lowByte = (secondOperand[2] - 1) & 0xFF;
    secondEncodedHigh = secondOperand[3];
    if ((u8)secondEncodedHigh == 0xFF) {
        secondHigh = 0;
    } else {
        secondHigh = (secondEncodedHigh - 1) & 0xFF;
    }
    secondHigh &= 0xFF;
    itemCount = (s32)(s16)((secondHigh << 8) | (u8)lowByte);
    if (frFontGetMode() != 0) {
        return 0;
    }
    datItemSetCount((s16)itemId, itemCount & 0xFF);
    return 0;
}

