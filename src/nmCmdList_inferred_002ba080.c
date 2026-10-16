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
extern void func_002baa50(void);
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

/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002ba080-002baa50 */

extern void func_002b5120(s32 arg0, u8 *arg1);
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
   Rewritten on the matched func_002ba5d0 pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in func_002ba5d0:
   retail copies $f12 before $t3 in the prologue, and both callers still
   match. opt_dead_assignments off reproduces retail's late argument loads. */
#pragma push
/* measured: func_002ba080 MATCH -> MISMATCH without this pragma. */
#pragma opt_dead_assignments off
// FUN_002BA080
void func_002ba080(u8 *task, s16 row, s16 number, FclVec2 position,
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

    bounds = func_002b29e0(22.0f, 17.0f);
    origin = func_002b2970(position.x + 284.0f, position.y + 6.0f);
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
        glyphHeight = *(f32 *)(digit + 12);
        glyphWidth = *(f32 *)(digit + 8);
        glyphY = *(f32 *)(digit + 4);
        slot = *(u8 **)(task + 0x38);
        offset = (s32)firstIndex * 0x220;
        glyphX = *(f32 *)digit;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
        firstBounds = bounds.representation;
        slot = *(u8 **)(task + 0x38);
        firstColor = color;
        slot += offset;
        *(FclVec2 *)(slot + 0x12C) = origin;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        *(u8 *)(slot + 0x162) = ((u8 *)&firstColor)[3];
        *(FclDrawColor *)(slot + 0x179) = color;
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = depth;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        ((FclBoundsPacket *)(slot + 0x204))->representation = firstBounds;
        *(s16 *)(slot + 0x100) = layer;
        slot = *(u8 **)(task + 0x38) + offset + 0x104;
        fclSpriteStartEntrance(slot, origin, *(u32 *)&color, *(u32 *)((u32)&color), 0,
                      ((u8 *)&color)[3], (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
    } else {
        u8 *draw = *(u8 **)(task + 0x38) + (s32)firstIndex * 0x220 + 0x104;

        if ((*(s16 *)draw & 1) == 1) {
            fclSpriteStartEntrance(draw, *(FclVec2 *)(draw + 0x28),
                          ((const DigitStoredWord *)(draw + 0x75))->word,
                          ((const DigitStoredWord *)((u32)draw + 0x75))->word,
                          *(u8 *)(draw + 0x5E), 0, (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
        }
    }
    if (flag == 0) {
        if ((value >= 10) || (value == 0)) {
            u8 *digit; u8 *slot; s32 offset;
            f32 glyphHeight, glyphWidth, glyphY, glyphX;

            digit = D_0063F1F0 + ((s32)tens * 0x10);
            glyphHeight = *(f32 *)(digit + 12);
            glyphWidth = *(f32 *)(digit + 8);
            glyphY = *(f32 *)(digit + 4);
            slot = *(u8 **)(task + 0x38);
            offset = (s32)secondIndex * 0x220;
            glyphX = *(f32 *)digit;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
            {
                f32 shiftX = origin.x - 18.0f;

                shifted = func_002b2970(shiftX, origin.y);
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
            *(FclVec2 *)(slot + 0x12C) = secondPosition;
            *(f32 *)(slot + 0x1A0) = 1.0f;
            *(f32 *)(slot + 0x194) = 1.0f;
            *(u8 *)(slot + 0x162) = ((u8 *)&secondColor)[3];
            *(FclDrawColor *)(slot + 0x179) = color;
            *(s32 *)(slot + 0x1C4) = 0;
            *(f32 *)(slot + 0x108) = depth;
            *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
            ((FclBoundsPacket *)(slot + 0x204))->representation = secondBounds;
            *(s16 *)(slot + 0x100) = layer;
            {
                u8 *draw = *(u8 **)(task + 0x38) + offset + 0x104;

                redrawn = func_002b2970(origin.x - 18.0f, origin.y);
                fclSpriteStartEntrance(draw, redrawn, *(u32 *)&color, *(u32 *)((u32)&color), 0,
                              ((u8 *)&color)[3], (f32)bounds.dimensions.height, depth, duration, delay, mode, 0);
            }
        }
    } else {
        u8 *draw = *(u8 **)(task + 0x38) + (s32)secondIndex * 0x220 + 0x104;

        if ((*(s16 *)draw & 1) == 1) {
            retrace = func_002b2970(origin.x - 18.0f, *(f32 *)(draw + 0x2C));
            fclSpriteStartEntrance(draw, retrace,
                          ((const DigitStoredWord *)(draw + 0x75))->word,
                          ((const DigitStoredWord *)((u32)draw + 0x75))->word, *(u8 *)(draw + 0x5E), 0,
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
// FUN_002BA5D0
void func_002ba5d0(u8 *task, s16 row, s32 number, FclVec2 position,
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

    bounds = func_002b29e0(22.0f, 17.0f);
    origin = func_002b2970(position.x + 284.0f, position.y + 6.0f);
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
        glyphHeight = *(f32 *)(digit + 12);
        glyphWidth = *(f32 *)(digit + 8);
        glyphY = *(f32 *)(digit + 4);
        slot = *(u8 **)(task + 0x38);
        offset = (s32)firstIndex * 0x220;
        glyphX = *(f32 *)digit;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
        firstBounds = bounds.representation;
        slot = *(u8 **)(task + 0x38);
        firstColor = color;
        slot += offset;
        *(FclVec2 *)(slot + 0x12C) = origin;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        *(u8 *)(slot + 0x162) = ((u8 *)&firstColor)[3];
        *(FclDrawColor *)(slot + 0x179) = color;
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = depth;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        ((FclBoundsPacket *)(slot + 0x204))->representation = firstBounds;
        *(s16 *)(slot + 0x100) = layer;
        *(s16 *)(*(u8 **)(task + 0x38) + offset + 0x104) = 0;
        slot = *(u8 **)(task + 0x38) + offset;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    }
    if ((value >= 10) || (value == 0)) {
        u8 *digit; u8 *slot; s32 offset;
        f32 glyphHeight, glyphWidth, glyphY, glyphX;

        digit = D_0063F1F0 + ((s32)tens * 0x10);
        glyphHeight = *(f32 *)(digit + 12);
        glyphWidth = *(f32 *)(digit + 8);
        glyphY = *(f32 *)(digit + 4);
        slot = *(u8 **)(task + 0x38);
        offset = (s32)secondIndex * 0x220;
        glyphX = *(f32 *)digit;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
        shifted = func_002b2970(origin.x - 18.0f, origin.y);
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
        *(FclVec2 *)(slot + 0x12C) = secondPosition;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        *(u8 *)(slot + 0x162) = ((u8 *)&secondColor)[3];
        *(FclDrawColor *)(slot + 0x179) = color;
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = depth;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        ((FclBoundsPacket *)(slot + 0x204))->representation = secondBounds;
        *(s16 *)(slot + 0x100) = layer;
        *(s16 *)(*(u8 **)(task + 0x38) + offset + 0x104) = 0;
        slot = *(u8 **)(task + 0x38) + offset;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    } else {
        u8 *slot; s32 offset;
        offset = (s32)secondIndex * 0x220;
        slot = *(u8 **)(task + 0x38) + offset;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) & ~1;
    }
}

#pragma pop
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
/* measured: func_002ba970 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_002BA970
void func_002ba970(u8 *arg0, s16 arg1, FclDrawColor color)
{
    s32 first;
    s32 second;
    u8 *p;
    u8 r, g, b, a;
    s32 index;
    u8 alpha;

    index = arg1 * 2;
    first = (s16)index * 0x220;
    p = *(u8 **)(arg0 + 0x38) + first;
    r = ((u8 *)&color)[0];
    g = ((u8 *)&color)[1];
    b = ((u8 *)&color)[2];
    a = ((u8 *)&color)[3];
    p[0x179] = r;
    p[0x17A] = g;
    p[0x17B] = b;
    p[0x17C] = a;
    second = (s16)(index + 1) * 0x220;
    p = *(u8 **)(arg0 + 0x38) + second;
    p[0x179] = r;
    p[0x17A] = g;
    p[0x17B] = b;
    p[0x17C] = a;
    p = *(u8 **)(arg0 + 0x38) + first;
    alpha = ((u8 *)&color)[3];
    p[0x162] = alpha;
    p = *(u8 **)(arg0 + 0x38) + second;
    p[0x162] = alpha;
}

// FUN_002BAA20
void func_002baa20(void)
{
    nmMesWindowInitRecord(D_00882F60);
    func_002baa50();
}

// FUN_002BAA50
void func_002baa50(void)
{
    s32 i;
    u8 **t;

    i = 0;
    t = D_00882F40;
    while (i < 5) {
        t[i] = NULL;
        i++;
    }
}

