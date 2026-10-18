#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "message_handle.h"
#include "shd_misc_internal.h"

/* Marker update reads these bytes from its task work; the prefix is owned
   by the marker drawing routines, not interpreted here. */
typedef struct YSymbolMarker {
    u8 pad00[0x20];
    s8 mode;
    s8 hidden;
} YSymbolMarker;
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(void *);



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u32 datItemPrice(s16 );
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
extern void (*D_00887300[])(s32 , s32 );
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern f32 cosf(f32 );
extern f32 sinf(f32 );
extern u8 D_0063F3B0[];


extern s32 smapWorldToColumn(u8 *);
extern s32 smapWorldToRow(u8 *);

extern f32 smapPlayerOffsetX(s32 , f32 );
extern f32 smapPlayerOffsetZ(s32 , f32 );
extern void mapSymbolMarkerDraw(u8 *, s64 , f32 , s32 );
extern u8 *mdlGetMatrix(u32 );
extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern void strcpy(void *, ...);
extern void strcat(void *, void *);
extern void strncpy(void *, void *, s32 );
extern void frFontExCopyString(void *, void *, s32 );
extern s32 func_00443010(u8 *, u8 *);
extern s32 fclTagTextLength(u8 *, s64 );
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002b2940-002b3960 */

// Intent: Return the work block pointer stored at offset 0x38 of an object [inferred]
// FUN_002B2940
u8 *fclGetWorkPointer(u8 *task)
{
    return ((KwlnTask *)task)->work;
}

// Intent: sets the symbol system's enabled flag (global iGpffffb55c). The field code sets it to 1 right after smapCreateSymbols, when the map is in band A or B.
// FUN_002B2950
void ySymbolSetEnabled(s32 enabled)
{
    iGpffffb55c = enabled;
}

// Intent: returns the symbol system's enabled flag (global iGpffffb55c); the symbol update paths return early while it is 0.
// FUN_002B2960
s32 ySymbolIsEnabled(void)
{
    return iGpffffb55c;
}

// Intent: Build a two-component float vector [inferred]
// FUN_002B2970
FclVec2 fclMakeVec2(f32 x, f32 y)
{
    FclVec2 val;

    val.x = x;
    val.y = y;
    return val;
}

// Intent: Build a three-component float vector [inferred]
// FUN_002B29A0
FclVec3 fclMakeVec3(f32 x, f32 y, f32 z)
{
    FclVec3 val;

    val.x = x;
    val.y = y;
    val.z = z;
    return val;
}

// Intent: Build a bounds packet from width and height, truncated to integers [inferred]
// FUN_002B29E0
FclBoundsPacket fclMakeBoundsPacket(f32 width, f32 height)
{
    FclBoundsPacket val;

    val.dimensions.width = (s32)width;
    val.dimensions.height = (s32)height;
    return val;
}

// Intent: Pack four colour bytes into one word, red in the top byte [inferred]
// FUN_002B2A30
s32 fclPackRgba(u8 red, u8 green, u8 blue, u8 alpha)
{
    s32 result;

    result = alpha & 0xFF;
    result = p4_pack_or(result, (blue & 0xFF) << 8);
    result = p4_pack_or((green & 0xFF) << 16, result);
    /* The high byte must be shifted in unsigned 32-bit arithmetic. */
    result = p4_pack_or((red & 0xFFU) << 24, result);
    return result;
}

// Intent: Build a draw colour from four byte channels [inferred]
// FUN_002B2A60
FclDrawColor fclMakeDrawColor(u8 red, u8 green, u8 blue, u8 alpha)
{
    FclDrawColor val;

    val.c0 = (u8)red;
    val.c1 = (u8)green;
    val.c2 = (u8)blue;
    val.c3 = (u8)alpha;
    return val;
}

// Intent: Interpolate between two values by an easing mode: linear, sine or cosine [inferred]
// FUN_002B2AA0
f32 fclEaseInterpolate(s64 easing, f32 first, f32 second, f32 elapsed, f32 duration)
{
    f32 start;
    f32 end;
    f32 weight;
    f32 difference;
    s64 mode;

    start = first;
    end = second;
    if (elapsed == duration) {
        return end;
    }
    mode = (s8)easing;
    switch (mode) {
    case 0:
        return start + ((elapsed * (end - start)) / duration);
    case 1:
        weight = sinf(p4_mul_left(elapsed, iGpffff82fc / (2.0f * duration)));
        difference = end - start;
        return start + difference * weight;
    case 2:
        weight = cosf(p4_mul_left(elapsed, iGpffff82fc / (2.0f * duration)));
        difference = end - start;
        return end - difference * weight;
    default:
        return -1.0f;
    }
}

// Intent: Compute a 2D anchor offset for a box of size w by h, from anchor mode 0 (centre), 1 or 2 [inferred]
// FUN_002B2BD0
void fclAnchorOffset(f32 *destination, s64 mode, f32 width, f32 height, f32 referenceWidth, f32 referenceHeight)
{
    FclVec2 offset;

    if ((s8)mode == 0) {
        offset.x = width / 2.0f;
        offset.y = height / 2.0f;
    } else if ((s8)mode == 1) {
        offset.x = (referenceWidth / 2.0f) + ((width - referenceWidth) / 2.0f);
        offset.y = (referenceHeight / 2.0f) + ((height - referenceHeight) / 2.0f);
    } else if ((s8)mode == 2) {
        offset.x = (width / 2.0f) - (referenceWidth / 2.0f);
        offset.y = (height / 2.0f) - (referenceHeight / 2.0f);
    }
    *(FclVec2 *)destination = offset;
}

// Intent: Add two values, clamping to a bound chosen by the mode (0 none, 1 maximum, else the second bound) [inferred]
// FUN_002B2CB0
s32 fclAddClamped(s32 value, s32 increment, s32 limit, s32 wrappedValue, s8 mode) {
    if (mode == 0) {
        return value + increment;
    }
    {
        s32 result = value + increment;
        s32 bound;
        if (limit < result) {
            bound = (mode == 1) ? limit : wrappedValue;
            result = bound;
        }
        return result;
    }
}

// Intent: Subtract two values, clamping to a bound chosen by the mode (0 none, 1 minimum, else the second bound) [inferred]
// FUN_002B2D00
s32 fclSubClamped(s32 value, s32 decrement, s32 limit, s32 wrappedValue, s8 mode) {
    if (mode == 0) {
        return value - decrement;
    }
    {
        s32 result = value - decrement;
        s32 bound;
        if (result < limit) {
            bound = (mode == 1) ? limit : wrappedValue;
            result = bound;
        }
        return result;
    }
}

// Intent: Step a list index by a signed delta within a count, wrapping through the window bounds [inferred]
// FUN_002B2D50
s16 yListStepIndex(s16 index, s16 cursor, s16 count, s16 windowSize, s16 delta) {
    s32 nextIndex;
    s32 oldCursor;
    s32 step;
    s32 entryCount;
    s32 previousCursor;

    entryCount = count;
    if (entryCount == 0) {
        return 0;
    }
    step = delta;
    nextIndex = index + step;
    if (nextIndex < 0) {
        return 0;
    }
    if (entryCount < nextIndex) {
        return windowSize - 1;
    }
    if (step > 0) {
        return (s16)fclMinS32(cursor + step, windowSize - 2, entryCount);
    }
    if (step < 0) {
        oldCursor = cursor;
        if (oldCursor == 0) {
            previousCursor = oldCursor - 1;
            if (previousCursor < 0) {
                previousCursor = 0;
            }
            return (s16)previousCursor;
        }
        return (s16)fclMaxS32(oldCursor + step, 1, entryCount);
    }
    return cursor;
}

/* measured: archived body in build/WW15_002b2e70.c (object 276B/window 288B, normalized_diff 5); restored ASM fallback. */
// Intent: Advance a list cursor and its scroll offset by one step, bounded by the visible window [inferred]
// FUN_002B2E70
void yListAdvanceCursorScroll(s32 index, s32 scroll, s32 count, s32 delta, s16 *outIndex, s16 *outScroll)
{
    s32 nextIndex;
    s32 relativeIndex;
    s32 advanced;
    s32 remaining;
    s32 stepIndex;
    s32 lastIndex;
    s32 step;
    s32 advanceIndex;
    nextIndex = index;
    advanced = 0;
    if (count == 0) { *outIndex = 0; *outScroll = 0; return; }
    lastIndex = count - 1;
    if (nextIndex != lastIndex) {
        relativeIndex = nextIndex - scroll;
        step = (s8)delta;
        remaining = count - (relativeIndex + step);
        if (remaining <= 0) {
            count = nextIndex;
            stepIndex = 0;
            goto loop_10_test;
loop_10_body:
            count += 1;
            if (lastIndex < count) count = lastIndex;
            advanced += 1;
            if (count >= lastIndex) { scroll += advanced; goto loop_10_done; }
            stepIndex += 1;
loop_10_test:
            if (stepIndex < step) goto loop_10_body;
loop_10_done:
            nextIndex += advanced;
        } else {
            if (remaining > step) goto loop_18_branch;
            goto loop_17_branch;
loop_17_branch:
            advanceIndex = 0;
            goto loop_17_test;
            do {
loop_17_body:
                nextIndex += 1;
                if (lastIndex < nextIndex) nextIndex = lastIndex;
                advanceIndex += 1;
loop_17_test: ;
            } while (advanceIndex < remaining);
            goto loop_17_done;
loop_18_branch:
            relativeIndex = nextIndex + step;
            lastIndex = (lastIndex < relativeIndex) ? lastIndex : relativeIndex;
            nextIndex = lastIndex;
loop_17_done: ;
        }
    }
    *outIndex = nextIndex;
    *outScroll = scroll;
}

// Intent: Retreat a list cursor and its scroll offset by one step, bounded by the visible window [inferred]
// FUN_002B2F90
void yListRetreatCursorScroll(s32 index, s32 scroll, s32 count, s32 delta, s16 *outIndex, s16 *outScroll)
{
    int conditionValue;
    s32 relativeIndex;
    s32 stepIndex;
    s32 step;
    if (count == 0) {
        *outIndex = 0;
        *outScroll = 0;
        goto exit;
    }
    relativeIndex = index - scroll;
    if (relativeIndex == 0) {
        index = 0;
        scroll = 0;
        goto done;
    }
    stepIndex = 0;
    step = (s8)delta;
    goto loop_test;
loop_body:
    relativeIndex = (s16)(index - scroll) - 1;
    if (relativeIndex < 0) {
        relativeIndex = 0;
    }
    if (relativeIndex == 0) {
        index -= 1;
        if (index < 0) {
            index = 0;
        }
        if ((!conditionValue) && (!conditionValue)) {
        }
        goto done;
    }
    index -= 1;
    if (index < 0) {
        index = 0;
    }
    stepIndex += 1;
loop_test:
    if (stepIndex < step) {
        goto loop_body;
    }
done:
    *outIndex = index;
    *outScroll = scroll;
exit:
    ;
}

// FUN_002B3050
/* Retreat the cursor, using the supplied low-byte index for an empty list. */
void yListRetreatCursorScrollDefaultIndex(s32 index, s32 scroll, s32 count, s64 delta, s32 emptyIndex, s16 *outIndex, s16 *outScroll)
{
  int conditionValue;
  s32 value;
  s32 iterations;
  if (count != 0)
  {
    goto nonzero;
  }
  value = emptyIndex & 0xFF;
  *outScroll = (*outIndex = value);
  goto done;
  nonzero:
  if ((index - scroll) != 0U)
  {
    goto setup;
  }
  index = emptyIndex & 0xFF; scroll = index;
  goto store;
  setup:
  iterations = 0;

  count = (s8) delta;
  goto loop_test;
  loop_body:
  value = ((s16) (index - scroll)) - 1;

  if (value < 0)
  {
    value = 0;
  }
  if (value != 0)
  {
    goto decrement;
  }
  index -= 1;
  if (index < 0)
  {
    index = 0;
  }
  if ((!conditionValue) && (!conditionValue))
  {
  }
  goto store;
  decrement:
  index -= 1;

  if (index < 0)
  {
    index = 0;
  }
  iterations += 1;
  loop_test:
  if (iterations < count)
  {
    goto loop_body;
  }

  store:
  *outIndex = index;

  *outScroll = scroll;
  done:
  return;
}

/* measured: opt_rebuildconditionals off probe for min/max */
/* measured: fclMinS32, fclMaxS32 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// Intent: Return the smaller of two signed 32-bit values [inferred]
// FUN_002B3110
s32 fclMinS32(s32 left, s32 right)
{
    s32 result;

    if (left < right)
        goto choose;
    result = right;
    goto done;
choose:
    result = left;
done:
    return result;
}

// Intent: Return the larger of two signed 32-bit values [inferred]
// FUN_002B3140
s32 fclMaxS32(s32 left, s32 right)
{
    s32 result;

    if (left > right)
        goto choose;
    result = right;
    goto done;
choose:
    result = left;
done:
    return result;
}

/* measured: close opt_rebuildconditionals after min/max */
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: fclDecimalDigitCount MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: Count the decimal digits of an integer [inferred]
// FUN_002B3170
s32 fclDecimalDigitCount(s32 value)
{
    s32 result;

    result = 0;
    do {
        value /= 10;
        result++;
    } while (value != 0);
    return result;
}

/* measured: close opt_loop_invariants after 3170. */
/* measured: fclExpandNameTags MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
// Intent: Subtract two 3-component float vectors and store the result [inferred]
// FUN_002B31A0
void fclVec3Subtract(u8 *destination, u8 *left, u8 *right)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 second;
    struct Vec3 result;

    first = *(struct Vec3 *)left;
    second = *(struct Vec3 *)right;
    result.x = first.x - second.x;
    result.y = first.y - second.y;
    result.z = first.z - second.z;
    *(struct Vec3 *)destination = result;
}

// Intent: Compare two list items by price for qsort: ascending, ties equal [inferred]
// FUN_002B3230
s32 datItemPriceCompare(const void *left, const void *right) {
    s16 rightId;
    u32 leftPrice;
    u32 rightPrice;

    rightId = *(const s16 *)right;
    leftPrice = datItemPrice(*(const s16 *)left);
    rightPrice = datItemPrice(rightId);
    if (leftPrice < rightPrice) {
        return 1;
    }
    return -(s32)(rightPrice < leftPrice);
}

// FUN_002B32A0
/* Return the limit once reached, otherwise the enabled fallback or zero. */
s32 fclSelectBoundedFallback(s32 value, s32 limit, s32 enabled, s32 fallback)
{
    s32 result;

    result = fallback;
    if (value >= limit) {
        return limit;
    }
    if (enabled == 0) {
        result = 0;
    }
    return result;
}

// Intent: Expand the name tags <P1>, <P2>, <R1>, <R2> in a text buffer by mode [inferred]
// FUN_002B32D0
u8 *fclExpandNameTags(u8 *text, s32 mode, u8 *secondName, u8 *thirdName, u8 *fourthName)
{
    u8 fourthReplacement[0x80];
    u8 thirdReplacement[0x80];
    u8 secondReplacement[0x80];
    u8 firstReplacement[0x80];
    u8 prefix[0x40];
    u8 copiedText[0x40];
    u8 expandedText[0x40];
    u8 **entry;
    s32 outer;
    u8 *dest;
    s32 size;
    s32 offset;
    s32 initial;
    s32 inner;

    strcpy(firstReplacement);
    strcpy(secondReplacement, secondName);
    strcpy(thirdReplacement, thirdName);
    strcpy(fourthReplacement, fourthName);
    initial = 0;
    while ((s16)initial < 0x40) {
        expandedText[(s16)initial] = 0;
        initial = (s16)(initial + 1);
    }
    outer = 0;
    while ((s16)outer < 4) {
        entry = &D_0063F110[(s16)outer];
        if (func_00443010(text, *entry) == 0) {
            outer = (s16)(outer + 1);
        } else {
            dest = firstReplacement + ((s16)outer * 0x80);
            offset = D_007488C0[(s16)outer];
            do {
                inner = 0;
                while ((s16)inner < 0x40) {
                    copiedText[(s16)inner] = 0;
                    prefix[(s16)inner] = 0;
                    inner = (s16)(inner + 1);
                }
                size = fclTagTextLength(text, (s8)outer);
                strncpy(prefix, text, size);
                frFontExCopyString(prefix, copiedText, 0x40);
                strcat(expandedText, copiedText);
                strcat(expandedText, dest);
                strcpy(text, text + size + offset);
            } while (func_00443010(text, *entry) != 0);
        }
    }
    frFontExCopyString(text, copiedText, 0x40);
    strcat(expandedText, copiedText);
    strcpy(text, expandedText);
    return text;
}

/* measured: object 504B/window 512B, nd 0. Retail hoists the nine tag-byte and
   case constants into $v1/$a1-$a3/$t0-$t2/$t5/$t6 ahead of the scan loop,
   which needs opt_loop_invariants on (the unit default here is off); the SJIS
   lead-byte test spelled `uc > 0x80` gives the `slti $at` form, and the four
   match exits are `goto found` to a label in front of the single return so
   the last byte compare branches straight to `jr ra`. The s64 second
   parameter (file prototype) is narrowed once into an s32 `mode`. */
// Intent: Return the length of text before the next name tag of the given mode [inferred]
// FUN_002B3520
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
/* measured: fclTagTextLength MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 fclTagTextLength(u8 *p, s64 tagMode)
{
    s32 count;
    s32 mode;
    s8 c;
    u8 uc;

    count = 0;
    mode = (s8)tagMode;
    for (;;) {
        c = *(s8 *)p;
        uc = c;
        switch (mode) {
        case 0:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && ((s8 *)p)[1] == 'P' && ((s8 *)p)[2] == '1' && ((s8 *)p)[3] == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 1:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && ((s8 *)p)[1] == 'P' && ((s8 *)p)[2] == '2' && ((s8 *)p)[3] == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 2:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && ((s8 *)p)[1] == 'R' && ((s8 *)p)[2] == '1' && ((s8 *)p)[3] == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 3:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && ((s8 *)p)[1] == 'R' && ((s8 *)p)[2] == '2' && ((s8 *)p)[3] == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        }
    }
found:
    return count;
}

/* measured: closes the loop-invariant bracket; the unit default is off. */
// Intent: Map symbol task update: place the marker at the player's position and draw it [inferred]
// FUN_002B3720
s32 mapSymbolTaskUpdate(u8 *task)
{
    FclVec2 out;
    FclVec2 work;
    f32 mapPosition;
    u8 *p;
    s32 color;

    p = ((KwlnTask *)task)->work;
    fclAnchorOffset(&work.x, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    out = *(FclVec2 *)&work;
    if (ySymbolIsEnabled() == 0) {
        return 0;
    }
    /* Player actor +0x220 remains byte-addressed: its owner layout is not established here. */
    if (((YSymbolMarker *)p)->hidden == 1) {
        return 0;
    }
    if (((YSymbolMarker *)p)->mode == 0) {
        out.x = out.x + 17.0f;
        out.y = out.y + 264.0f;
        out.x = out.x - 10.0f;
        out.y = out.y - 10.0f;
        out.y = out.y - 2.0f;
    } else if (((YSymbolMarker *)p)->mode == 1) {
        mapPosition = ((f32)smapWorldToColumn(
                        mdlGetMatrix(D_007EFA00[0]) + 0x30) *
                    18.0f) + 172.0f;
        out.x = mapPosition -
                smapPlayerOffsetX(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f);
        mapPosition = ((f32)smapWorldToRow(
                        mdlGetMatrix(D_007EFA00[0]) + 0x30) *
                    18.0f) + 9.0f;
        out.y = mapPosition -
                smapPlayerOffsetZ(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f) - 2.0f;
    }
    color = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
    mapSymbolMarkerDraw(task, *(s64 *)&out, 60002.0f, color);
    return 0;
}

// Intent: destructor for the marker task made by mapSymbolMarkerCreate. Frees the task's data block through the free table.
// FUN_002B3960
void mapSymbolMarkerDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

