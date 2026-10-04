#ifndef FCL_COMBINE_ROW_INTERNAL_H
#define FCL_COMBINE_ROW_INTERNAL_H

#include "fcl_color.h"
#include "fcl_draw_types.h"

/* Partial views used by the combination-row renderer. Unknown byte ranges
   belong to the existing objects; they are not compiler-allocation padding.
   Retail 0031ac10 reads selected rows at 128/129, resets the two cursor bytes
   at 294/295, writes the position at 298, and reloads the digit task at 2bc. */
typedef struct {
    u8 unknown000[0x128];
    s8 firstSelectedRow;
    s8 secondSelectedRow;
    u8 unknown12A[0x16A];
    s8 firstCursorState;
    s8 secondCursorState;
    u8 unknown296[2];
    FclVec2 cursorPosition;
    u8 unknown2A0[0x1C];
    u8 *digitTask;
} FclCombineRowWork;

typedef struct {
    u8 unknown00[0x38];
    FclCombineRowWork *work;
} FclCombineRowTask;

/* func_002b6150 returns four bytes into a 0x100-byte draw-table entry.
   The image halfword, current alpha, flag and byte-aligned color below are
   precisely the fields used here, not a replacement provider signature. */
typedef struct {
    u8 unknown00[4];
    s16 image;
    u8 unknown06[0x68];
    u8 alpha;
    u8 unknown6F[4];
    u8 flag73;
    u8 unknown74[0x11];
    FclDrawColor color;
} FclCombineRowSprite;

/* Bounded availability view used by the list fixture. The renderer keeps
   signed byte-offset addressing, so this view imposes no caller-domain
   restriction on a provider returning an interior pointer into larger storage.
   y_list.c writes 0, 1 and 2; the renderer rejects every nonpositive value. */
typedef struct {
    u8 unknown00[0x14];
    s8 availability[12][12];
} FclCombineRowList;

#endif
