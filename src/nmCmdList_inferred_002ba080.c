#include "sdktask.h"
#include "fcl_object_internal.h"
#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
/* Digit slots retain the shared FclObject prefix at +0x100. The digit
 * variant interprets its resource tail as a floating glyph rectangle instead
 * of the generic resource/index/mode words. Every slot advances 0x220 bytes. */
typedef struct NmMesDigitGlyph { f32 x, y, width, height; } NmMesDigitGlyph;
typedef union NmMesDigitDraw {
    FclObject object;
    s16 layer;
    struct {
        u8 pad00[0xF4];
        NmMesDigitGlyph glyph;
    } region;
} NmMesDigitDraw;
typedef struct NmMesDigitSlot {
    u8 pad00[0x100];
    NmMesDigitDraw draw;
    FclBoundsPacket bounds;
    u8 pad214[0xC];
} NmMesDigitSlot;
typedef char NmMesDigitSlotSize[sizeof(NmMesDigitSlot) == 0x220 ? 1 : -1];

extern void nmMesWindowClearSlotTable(void);
extern void nmMesWindowInitRecord(s32 *arg0);



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];



extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002ba080-002baa50 */

extern void fclFadeRectSetRenderStates(s32 arg0, u8 *arg1);
static inline s32 fclDigitIsZero(const s16 *value)
{
    return *value == 0;
}
/* measured: opt_rebuildconditionals off probe for min/max */
/* measured: close opt_rebuildconditionals after min/max */
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: close opt_loop_invariants after 3170. */
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
/* measured: closes the loop-invariant bracket; the unit default is off. */
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
/* Row and value are signed halfwords; retail discards incoming row high bits.
   Rewritten on the matched nmMesWindowSetNumber pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in nmMesWindowSetNumber:
   retail copies $f12 before $t3 in the prologue, and both callers still
   match. opt_dead_assignments off reproduces retail's late argument loads. */
#pragma push
/* measured: func_002ba080 MATCH -> MISMATCH without this pragma. */
#pragma opt_dead_assignments off
// Intent: shows the two-digit number on row `row`: the entrance animation when mode is 0, otherwise a retrace of the existing sprite.
/* measured: later task+0x38 loads stay raw; typing them retains the work-field
 * address across the entrance callback and spills secondIndex (1372B vs 1360B). */
// FUN_002BA080
void nmMesWindowShowNumber(u8 *task, s16 row, s16 number, FclVec2 position,
                   FclDrawColor color, s32 duration, s32 delay, f32 depth,
                   s32 layer, s8 mode)
{
    typedef struct {
        u32 word;
    } DigitStoredWord __attribute__((packed));
    extern void fclSpriteStartEntrance(u8 *draw, FclVec2 position, u32 color0, u32 color1, u8 alpha0,
                              u8 alpha1, f32 height, f32 depth, s32 duration, s32 delay, s8 mode,
                              s8 reverse);
    FclBoundsPacket bounds;
    FclBoundsBytes firstBounds, secondBounds;
    FclVec2 origin, shifted, redrawn, retrace, secondPosition;
    FclDrawColor firstColor;
    FclDrawColor secondColor;
    s16 value;
    s16 firstIndex;
    s16 secondIndex;
    s8 ones;
    s8 tens;
    s8 flag;

    bounds = fclMakeBoundsPacket(22.0f, 17.0f);
    origin = fclMakeVec2(position.x + 284.0f, position.y + 6.0f);
    value = number;
    if ((value == -1) || fclDigitIsZero(&value)) {
        ones = 10;
        tens = 10;
    } else {
        ones = (s8)(value % 10);
        tens = (s8)(value / 10);
    }
    firstIndex = (s16)((s16)row * 2);
    secondIndex = (s16)((s16)row * 2 + 1);
    flag = mode;
    if (flag == 0) {
        u8 *digit; u8 *slot; s32 offset;
        f32 glyphHeight, glyphWidth, glyphY, glyphX;

        digit = D_0063F1F0 + ((s32)ones * 0x10);
        glyphHeight = ((NmMesDigitGlyph *)digit)->height;
        glyphWidth = ((NmMesDigitGlyph *)digit)->width;
        glyphY = ((NmMesDigitGlyph *)digit)->y;
        slot = ((SdkTask *)task)->work;
        offset = (s32)firstIndex * 0x220;
        glyphX = ((NmMesDigitGlyph *)digit)->x;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.x = glyphX;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.y = glyphY;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.width = glyphWidth;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.height = glyphHeight;
        firstBounds = bounds.representation;
        slot = ((SdkTask *)task)->work;
        firstColor = color;
        slot += offset;
        ((NmMesDigitSlot *)slot)->draw.object.anchorPosition = origin;
        ((NmMesDigitSlot *)slot)->draw.object.scale = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.scaleX = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.alpha = ((u8 *)&firstColor)[3];
        ((NmMesDigitSlot *)slot)->draw.object.color = color;
        ((NmMesDigitSlot *)slot)->draw.object.tweenValue = 0.0f;
        ((NmMesDigitSlot *)slot)->draw.object.anchorValue = depth;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
        ((NmMesDigitSlot *)slot)->bounds.representation = firstBounds;
        ((NmMesDigitSlot *)slot)->draw.layer = layer;
        slot = ((SdkTask *)task)->work + offset + 0x104;
        fclSpriteStartEntrance(slot, origin, *(u32 *)&color, *(u32 *)((u32)&color), 0,
                      ((u8 *)&color)[3], (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
    } else {
        u8 *draw = ((SdkTask *)task)->work + (s32)firstIndex * 0x220 + 0x104;

        if ((((FclObject *)(draw - 4))->spriteFlags & 1) == 1) {
            fclSpriteStartEntrance(draw, ((FclObject *)(draw - 4))->anchorPosition,
                          ((const DigitStoredWord *)(&((FclObject *)(draw - 4))->color))->word,
                          ((const DigitStoredWord *)(&((FclObject *)((u32)draw - 4))->color))->word,
                          ((FclObject *)(draw - 4))->alpha, 0, (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
        }
    }
    if (flag == 0) {
        if ((value >= 10) || (value == 0)) {
            u8 *digit; u8 *slot; s32 offset;
            f32 glyphHeight, glyphWidth, glyphY, glyphX;

            digit = D_0063F1F0 + ((s32)tens * 0x10);
            glyphHeight = ((NmMesDigitGlyph *)digit)->height;
            glyphWidth = ((NmMesDigitGlyph *)digit)->width;
            glyphY = ((NmMesDigitGlyph *)digit)->y;
            slot = *(u8 **)(task + 0x38);
            offset = (s32)secondIndex * 0x220;
            glyphX = ((NmMesDigitGlyph *)digit)->x;
            ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.x = glyphX;
            ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.y = glyphY;
            ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.width = glyphWidth;
            ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.height = glyphHeight;
            {
                f32 shiftX = origin.x - 18.0f;

                shifted = fclMakeVec2(shiftX, origin.y);
            }
            {
                f32 pointX, pointY;
                pointX = shifted.x;
                pointY = shifted.y;
                secondPosition.x = pointX;
                secondPosition.y = pointY;
            }
            secondBounds = bounds.representation;
            slot = *(u8 **)(task + 0x38);
            secondColor = color;
            slot += offset;
            ((NmMesDigitSlot *)slot)->draw.object.anchorPosition = secondPosition;
            ((NmMesDigitSlot *)slot)->draw.object.scale = 1.0f;
            ((NmMesDigitSlot *)slot)->draw.object.scaleX = 1.0f;
            ((NmMesDigitSlot *)slot)->draw.object.alpha = ((u8 *)&secondColor)[3];
            ((NmMesDigitSlot *)slot)->draw.object.color = color;
            ((NmMesDigitSlot *)slot)->draw.object.tweenValue = 0.0f;
            ((NmMesDigitSlot *)slot)->draw.object.anchorValue = depth;
            ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
            ((NmMesDigitSlot *)slot)->bounds.representation = secondBounds;
            ((NmMesDigitSlot *)slot)->draw.layer = layer;
            {
                u8 *draw = *(u8 **)(task + 0x38) + offset + 0x104;

                redrawn = fclMakeVec2(origin.x - 18.0f, origin.y);
                fclSpriteStartEntrance(draw, redrawn, *(u32 *)&color, *(u32 *)((u32)&color), 0,
                              ((u8 *)&color)[3], (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
            }
        }
    } else {
        u8 *draw = *(u8 **)(task + 0x38) + (s32)secondIndex * 0x220 + 0x104;

        if ((((FclObject *)(draw - 4))->spriteFlags & 1) == 1) {
            retrace = fclMakeVec2(origin.x - 18.0f, ((FclObject *)(draw - 4))->anchorPosition.y);
            fclSpriteStartEntrance(draw, retrace,
                          ((const DigitStoredWord *)(&((FclObject *)(draw - 4))->color))->word,
                          ((const DigitStoredWord *)(&((FclObject *)((u32)draw - 4))->color))->word, ((FclObject *)(draw - 4))->alpha, 0,
                          (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
        }
    }
}

#pragma pop
/* Keep the two positions, colors, and character-representation bounds
   snapshots separate across writes to the draw slots. The depth precedes
   the layer in the recovered signature. See the worker3 digit-pair archive. */
#pragma push
/* measured: func_002ba5d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: sets the two-digit number on row `row` without an entrance animation; the tens digit is hidden for values below 10 except 0.
/* measured: later task+0x38 loads stay raw; the typed form extends the
 * work-field address lifetime across the position constructor and loses MATCH. */
// FUN_002BA5D0
void nmMesWindowSetNumber(u8 *task, s16 row, s32 number, FclVec2 position,
                    FclDrawColor color, f32 depth, s64 layer)
{
    FclBoundsPacket bounds;
    FclBoundsBytes firstBounds, secondBounds;
    FclVec2 origin, shifted, secondPosition;
    FclDrawColor firstColor;
    FclDrawColor secondColor;
    s16 value;
    s16 firstIndex;
    s16 secondIndex;
    s8 ones;
    s8 tens;

    bounds = fclMakeBoundsPacket(22.0f, 17.0f);
    origin = fclMakeVec2(position.x + 284.0f, position.y + 6.0f);
    value = (s16)number;
    if ((value == -1) || fclDigitIsZero(&value)) {
        ones = 10;
        tens = 10;
    } else {
        ones = (s8)(value % 10);
        tens = (s8)(value / 10);
    }
    firstIndex = (s16)((s16)row * 2);
    secondIndex = (s16)((s16)row * 2 + 1);
    {
        u8 *digit; u8 *slot; s32 offset;
        f32 glyphHeight, glyphWidth, glyphY, glyphX;

        digit = D_0063F1F0 + ((s32)ones * 0x10);
        glyphHeight = ((NmMesDigitGlyph *)digit)->height;
        glyphWidth = ((NmMesDigitGlyph *)digit)->width;
        glyphY = ((NmMesDigitGlyph *)digit)->y;
        slot = ((SdkTask *)task)->work;
        offset = (s32)firstIndex * 0x220;
        glyphX = ((NmMesDigitGlyph *)digit)->x;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.x = glyphX;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.y = glyphY;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.width = glyphWidth;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.height = glyphHeight;
        firstBounds = bounds.representation;
        slot = ((SdkTask *)task)->work;
        firstColor = color;
        slot += offset;
        ((NmMesDigitSlot *)slot)->draw.object.anchorPosition = origin;
        ((NmMesDigitSlot *)slot)->draw.object.scale = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.scaleX = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.alpha = ((u8 *)&firstColor)[3];
        ((NmMesDigitSlot *)slot)->draw.object.color = color;
        ((NmMesDigitSlot *)slot)->draw.object.tweenValue = 0.0f;
        ((NmMesDigitSlot *)slot)->draw.object.anchorValue = depth;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
        ((NmMesDigitSlot *)slot)->bounds.representation = firstBounds;
        ((NmMesDigitSlot *)slot)->draw.layer = layer;
        ((NmMesDigitSlot *)(((SdkTask *)task)->work + offset))->draw.object.spriteFlags = 0;
        slot = ((SdkTask *)task)->work + offset;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
    }
    if ((value >= 10) || (value == 0)) {
        u8 *digit; u8 *slot; s32 offset;
        f32 glyphHeight, glyphWidth, glyphY, glyphX;

        digit = D_0063F1F0 + ((s32)tens * 0x10);
        glyphHeight = ((NmMesDigitGlyph *)digit)->height;
        glyphWidth = ((NmMesDigitGlyph *)digit)->width;
        glyphY = ((NmMesDigitGlyph *)digit)->y;
        slot = *(u8 **)(task + 0x38);
        offset = (s32)secondIndex * 0x220;
        glyphX = ((NmMesDigitGlyph *)digit)->x;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.x = glyphX;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.y = glyphY;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.width = glyphWidth;
        ((NmMesDigitSlot *)(u8 *)((u32)offset + (u32)slot))->draw.region.glyph.height = glyphHeight;
        shifted = fclMakeVec2(origin.x - 18.0f, origin.y);
        {
            f32 pointX, pointY;
            pointX = shifted.x;
            pointY = shifted.y;
            secondPosition.x = pointX;
            secondPosition.y = pointY;
        }
        secondBounds = bounds.representation;
        slot = *(u8 **)(task + 0x38);
        secondColor = color;
        slot += offset;
        ((NmMesDigitSlot *)slot)->draw.object.anchorPosition = secondPosition;
        ((NmMesDigitSlot *)slot)->draw.object.scale = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.scaleX = 1.0f;
        ((NmMesDigitSlot *)slot)->draw.object.alpha = ((u8 *)&secondColor)[3];
        ((NmMesDigitSlot *)slot)->draw.object.color = color;
        ((NmMesDigitSlot *)slot)->draw.object.tweenValue = 0.0f;
        ((NmMesDigitSlot *)slot)->draw.object.anchorValue = depth;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
        ((NmMesDigitSlot *)slot)->bounds.representation = secondBounds;
        ((NmMesDigitSlot *)slot)->draw.layer = layer;
        ((NmMesDigitSlot *)(*(u8 **)(task + 0x38) + offset))->draw.object.spriteFlags = 0;
        slot = *(u8 **)(task + 0x38) + offset;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags | 1;
    } else {
        u8 *slot; s32 offset;
        offset = (s32)secondIndex * 0x220;
        slot = *(u8 **)(task + 0x38) + offset;
        ((NmMesDigitSlot *)slot)->draw.object.spriteFlags = ((NmMesDigitSlot *)slot)->draw.object.spriteFlags & ~1;
    }
}

#pragma pop
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
/* measured: func_002ba970 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// Intent: sets the colour and alpha of both digit sprites on row `row`.
// FUN_002BA970
void nmMesWindowSetNumberColor(u8 *task, s16 row, FclDrawColor color)
{
    s32 firstOffset;
    s32 secondOffset;
    u8 *slot;
    u8 r, g, b, a;
    s32 index;
    u8 alpha;

    index = row * 2;
    firstOffset = (s16)index * 0x220;
    slot = ((SdkTask *)task)->work + firstOffset;
    r = ((u8 *)&color)[0];
    g = ((u8 *)&color)[1];
    b = ((u8 *)&color)[2];
    a = ((u8 *)&color)[3];
    ((NmMesDigitSlot *)slot)->draw.object.color.c0 = r;
    ((NmMesDigitSlot *)slot)->draw.object.color.c1 = g;
    ((NmMesDigitSlot *)slot)->draw.object.color.c2 = b;
    ((NmMesDigitSlot *)slot)->draw.object.color.c3 = a;
    secondOffset = (s16)(index + 1) * 0x220;
    slot = ((SdkTask *)task)->work + secondOffset;
    ((NmMesDigitSlot *)slot)->draw.object.color.c0 = r;
    ((NmMesDigitSlot *)slot)->draw.object.color.c1 = g;
    ((NmMesDigitSlot *)slot)->draw.object.color.c2 = b;
    ((NmMesDigitSlot *)slot)->draw.object.color.c3 = a;
    slot = ((SdkTask *)task)->work + firstOffset;
    alpha = ((u8 *)&color)[3];
    ((NmMesDigitSlot *)slot)->draw.object.alpha = alpha;
    slot = ((SdkTask *)task)->work + secondOffset;
    ((NmMesDigitSlot *)slot)->draw.object.alpha = alpha;
}

// Intent: resets the current message record and clears the slot table.
// FUN_002BAA20
void nmMesWindowResetRecords(void)
{
    nmMesWindowInitRecord(D_00882F60);
    nmMesWindowClearSlotTable();
}

// Intent: clears all five message slots.
// FUN_002BAA50
void nmMesWindowClearSlotTable(void)
{
    s32 slotIndex;
    u8 **slots;

    slotIndex = 0;
    slots = D_00882F40;
    while (slotIndex < 5) {
        slots[slotIndex] = NULL;
        slotIndex++;
    }
}

