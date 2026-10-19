#ifndef FCL_COMBINE_ROW_INTERNAL_H
#define FCL_COMBINE_ROW_INTERNAL_H

#include "fcl_color.h"
#include "fcl_draw_types.h"

/* Partial views used by the combination-row and pair-grid renderers. Unknown
   byte ranges belong to the existing objects, not compiler-allocation padding.
   Retail 00320b80 resets the cursor row (11e), first selection (128), and
   per-cell transition bytes (18c). 003212e0 sets a cell's byte after queuing
   its availability-color transition; these are not the list's availability
   flags at offset 14. The existing 0031ac10 cursor/digit fields stay in place. */
typedef struct {
    u8 unknown000[0x11E];
    s16 cursorRow;                       /* 0x11e: currently highlighted row */
    u8 unknown120[8];
    s8 firstSelectedRow;                 /* 0x128: -1 until a row is selected */
    s8 secondSelectedRow;
    u8 unknown12A[0x2A];
    u8 *gridRowTasks[12];                /* 0x154: one cell-list task per row */
    u8 *gridColumnHeaderTask;            /* 0x184: indexed by column */
    u8 unknown188[4];
    s8 cellTransitionStarted[12][12];    /* 0x18c: row-major transition state */
    u8 unknown21C[0x78];
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

/* Row-relative views, not separately allocated objects. The grid renderer
   keeps work + row * 4 and work + row * 12 as distinct live pointers, then
   applies the field displacement at each access. This is the same view
   convention as FclCombineRowView in y_fclCombine.c. */
typedef struct {
    u8 unknown000[0x154];
    u8 *cellListTask;
} FclCombineGridRowTaskView;

typedef struct {
    u8 unknown000[0x18C];
    s8 cellTransitionStarted[12];
} FclCombineGridRowStateView;

/* yListSlotEntry(0, row) returns a Persona record: ID at 2, level at 4.
   The list count really is a word; 00320b80 deliberately reads only its
   signed low byte when passing the count to the row renderer. */
typedef struct {
    u8 unknown00[2];
    u16 personaId;
    u8 level;
} FclCombinePersonaHeader;

typedef struct {
    u8 unknown00[8];
    s32 count;
} FclCombinePersonaListHeader;

/* fclSpriteEntry returns four bytes into a 0x100-byte draw-table entry.
   The image halfword, current alpha, flag and byte-aligned color below are
   precisely the fields used here, not a replacement provider signature. */
typedef struct {
    u8 unknown00[4];
    s16 image;
    u8 unknown06[2];
    s32 order;                       /* 0x08: fclSpriteCreate draw order */
    u8 unknown0C[4];
    s16 flags;                       /* 0x10: fclSpriteSetFlag bit set */
    u8 unknown12[2];
    f32 depth;                       /* 0x14: selected-entry depth */
    u8 unknown18[0x10];
    FclVec2 positionStart;            /* 0x28: y_draw.c transition endpoints */
    FclVec2 positionEnd;
    FclVec2 position;
    s16 positionDuration;             /* 0x40 */
    s16 positionElapsed;
    s16 positionDelay;
    u8 positionMode;
    u8 positionReverse;
    u8 unknown48[0x26];
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
