#ifndef ED_SCROLL_INTERNAL_H
#define ED_SCROLL_INTERNAL_H

#include "type.h"

/* LayoutText writes pairs at +4/+8; FreeRecord and MoveRecord consume them. */
typedef struct EdScrollGlyph
{
    f32 x;
    u32 handle;
} EdScrollGlyph;

typedef struct EdScrollRecord
{
    u32 flags;
    EdScrollGlyph glyphs[16];
    u32 count;              /* 0x84 */
    u32 unk88;
    f32 y;                 /* 0x8C; record stride 0x90 */
} EdScrollRecord;

/* WorkInit clears 32 record flags and sets RGBA at 0x122C. */
typedef struct EdScrollWork
{
    u32 flags;
    EdScrollRecord records[32];
    u32 phaseFrame;         /* 0x1204 */
    u32 textIndex;
    u32 streamOffset;
    u32 unk1210;
    u32 unk1214;
    f32 unk1218;
    f32 nextY;
    u32 lastRecordAddress;
    u32 phase;
    f32 phaseStartY;
    u8 color[4];
} EdScrollWork;

/* CALL_STAFF_ROLL allocates exactly 0x1258 bytes and embeds scroll at +0x1C. */
typedef struct EdSrWork
{
    s32 flags;
    s32 task;
    s32 overlayTask;
    u8 parameters[0x10];
    EdScrollWork scroll;
    s32 state;
    s32 playerTask;
    s32 frame;
} EdSrWork;

#endif
