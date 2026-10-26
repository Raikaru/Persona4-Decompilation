#include "include_asm.h"
/* Original translation unit btlPanelCursor.c (from __FILE__ assert strings). */
#include "type.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"

extern u32 kwlnTaskGetWork(void *task);
extern void btlUiSetTileOffset(u8 *work, s16 x, s32 y, f32 factor);
extern void btlUiSetRenderMode(s32 mode);
extern void btlUnitGaugeClear(s32 unitAddress, s32 active);
extern f32 btlGaugeHpRatio(u8 *unit);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern void kAssertFail(void *file, s32 line);
extern f32 iGpffff83d4[2];

typedef struct { u8 r, g, b, a; } CursorColor;

/* All four cursor styles share the 0x14-byte state prefix. Ring styles
 * store a segment count and two angles; cross styles store distance/scale. */
typedef struct BtlPanelCursor
{
    u16 unk00;
    u16 state;
    u16 frame;
    u8 pad06[2];
    Vec2f position;
    u16 flags; /* 1: marker, 2: HP gauge, 4: segments, 8: cross, 0x10: opening */
    u8 pad12[2];
    union { s32 segmentCount; f32 distance; u32 distanceBits; } shape;
    union {
        struct { s16 segmentAngle; s16 spriteAngle; } ring;
        f32 scale;
    } animation;
} BtlPanelCursor;
extern u8 D_00626C00[];

/* Draw one asserted cursor segment and restore the sprite tile offset. */
static inline void btlPanelDrawCursorSegment(u8 *work, CursorColor color, f32 x, f32 y,
                                      s32 index, f32 rotation, f32 distance)
{
    if (index >= 8) {
        kAssertFail(D_00626C00, 401);
    }
    btlUiSetTileOffset(work, 13, (s32)(38.0f + distance), 360.0f * (f32)index / 8.0f + rotation);
    btlUiDrawSpriteFaded(work, 10, 2, x - 13.0f, (y - 38.0f) - distance,
                  color.r, color.g, color.b, color.a);
    btlUiSetTileOffset(work, 0, 0, 0.0f);
}

extern f32 fGpffff837c;
extern f32 D_00761590;

#pragma opt_loop_invariants on
/* Update the eight-segment target cursor and its HP gauge. `alpha` is deliberately uninitialised
 * because retail reads it on the reset path without writing it. */
// FUN_0020BFF0
void btlPanelCursorDrawA(s32 task, u8 *cursor, u8 *panel, f32 *position)
{
    CursorColor color;
    Vec2f point;
    f32 delta[2];
    u8 *work;
    u8 *control;
    f32 alpha;
    f32 t;
    f32 length;
    s32 count;
    s32 i;

    BtlPanelCursor *typedCursor = (BtlPanelCursor *)cursor;
    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (((BtlPanelCursor *)cursor)->state) {
    case 1:
        btlUnitGaugeClear((s32)(panel), (s32)( 0));
        ((BtlPanelCursor *)cursor)->frame = 0;
        ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
        typedCursor->state = 4;
        ((BtlPanelCursor *)cursor)->flags |= 1;
        ((BtlPanelCursor *)cursor)->flags |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear((s32)(panel), (s32)( 0));
            ((BtlPanelCursor *)cursor)->frame = 0;
            ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
            typedCursor->state = 4;
            ((BtlPanelCursor *)cursor)->flags |= 1;
            ((BtlPanelCursor *)cursor)->flags |= 0x10;
        } else {
            t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - ((BtlPanelCursor *)cursor)->position.x;
            delta[1] = position[1] - ((BtlPanelCursor *)cursor)->position.y;
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = typedCursor->position.x + delta[0];
            position[1] = typedCursor->position.y + delta[1];
            if (++typedCursor->frame == 4) {
                btlUnitGaugeClear((s32)(panel), (s32)( 0));
                typedCursor->frame = 0;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
                typedCursor->state = 4;
                ((BtlPanelCursor *)cursor)->flags |= 1;
                ((BtlPanelCursor *)cursor)->flags |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 8.0f;
        alpha = 1.0f - t;
        if (++typedCursor->frame == 8) {
            typedCursor->state = 0;
            ((BtlPanelCursor *)cursor)->flags = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (((BtlPanelCursor *)cursor)->flags & 0x10) {
            ++((BtlPanelCursor *)cursor)->frame;
            if (((BtlPanelCursor *)cursor)->frame < 2) {
            } else if (((BtlPanelCursor *)cursor)->frame == 2) {
                typedCursor->flags |= 4;
                typedCursor->flags |= 2;
            } else if (((BtlPanelCursor *)cursor)->frame < 11) {
                t = (f32)(((BtlPanelCursor *)cursor)->frame - 2) / 9.0f;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = (s32)(8.0f * t);
            } else if (((BtlPanelCursor *)cursor)->frame >= 11) {
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 8;
                typedCursor->flags &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (((BtlPanelCursor *)cursor)->flags & 4) {
        count = ((BtlPanelCursor *)cursor)->shape.segmentCount;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = (((BtlPanelCursor *)cursor)->animation.ring.segmentAngle + 2) % 360;
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            btlPanelDrawCursorSegment(work, color, position[0], position[1], i,
                              (f32)typedCursor->animation.ring.segmentAngle, 0.0f);
        }
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (typedCursor->flags & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* Update the seven-segment target cursor with its rotating sprite and HP gauge. `alpha` is
 * deliberately uninitialised because retail reads it on the reset path without writing it. */
// FUN_0020C680
void btlPanelCursorDrawB(s32 task, u8 *cursor, u8 *panel, f32 *position)
{
    CursorColor color;
    Vec2f point;
    f32 delta[2];
    u8 *work;
    u8 *control;
    f32 alpha;
    f32 t;
    f32 length;
    s32 count;
    s32 i;

    BtlPanelCursor *typedCursor = (BtlPanelCursor *)cursor;
    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (((BtlPanelCursor *)cursor)->state) {
    case 1:
        btlUnitGaugeClear((s32)(panel), (s32)( 0));
        ((BtlPanelCursor *)cursor)->frame = 0;
        ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
        typedCursor->state = 4;
        ((BtlPanelCursor *)cursor)->flags |= 1;
        ((BtlPanelCursor *)cursor)->flags |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear((s32)(panel), (s32)( 0));
            ((BtlPanelCursor *)cursor)->frame = 0;
            ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
            typedCursor->state = 4;
            ((BtlPanelCursor *)cursor)->flags |= 1;
            ((BtlPanelCursor *)cursor)->flags |= 0x10;
        } else {
            t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - ((BtlPanelCursor *)cursor)->position.x;
            delta[1] = position[1] - ((BtlPanelCursor *)cursor)->position.y;
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = typedCursor->position.x + delta[0];
            position[1] = typedCursor->position.y + delta[1];
            if (++typedCursor->frame == 4) {
                btlUnitGaugeClear((s32)(panel), (s32)( 0));
                typedCursor->frame = 0;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
                typedCursor->state = 4;
                ((BtlPanelCursor *)cursor)->flags |= 1;
                ((BtlPanelCursor *)cursor)->flags |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 8.0f;
        alpha = 1.0f - t;
        if (++typedCursor->frame == 8) {
            typedCursor->state = 0;
            ((BtlPanelCursor *)cursor)->flags = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (((BtlPanelCursor *)cursor)->flags & 0x10) {
            ++((BtlPanelCursor *)cursor)->frame;
            if (((BtlPanelCursor *)cursor)->frame < 2) {
            } else if (((BtlPanelCursor *)cursor)->frame == 2) {
                typedCursor->flags |= 4;
                typedCursor->flags |= 2;
            } else if (((BtlPanelCursor *)cursor)->frame < 11) {
                t = (f32)(((BtlPanelCursor *)cursor)->frame - 2) / 9.0f;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = (s32)(7.0f * t);
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = (s16)(360.0f * ((0.0f + alpha) - 2.0f * t + t * t));
            } else if (((BtlPanelCursor *)cursor)->frame >= 11) {
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 7;
                typedCursor->flags &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (((BtlPanelCursor *)cursor)->flags & 4) {
        count = ((BtlPanelCursor *)cursor)->shape.segmentCount;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = (((BtlPanelCursor *)cursor)->animation.ring.segmentAngle + 2) % 360;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = (((BtlPanelCursor *)cursor)->animation.ring.spriteAngle + 356) % 360;
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 148;
        color.b = 50;
        color.a = (u8)(204.0f * alpha);
        btlUiSetTileOffset(work, 56, 53, (f32)typedCursor->animation.ring.spriteAngle);
        btlUiDrawSpriteFaded(work, 10, 4, position[0] - 56.0f, position[1] - 53.0f,
                      color.r, color.g, color.b, color.a);
        btlUiSetTileOffset(work, 0, 0, 0.0f);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            btlPanelDrawCursorSegment(work, color, position[0], position[1], i,
                              (f32)typedCursor->animation.ring.segmentAngle, 0.0f);
        }
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (typedCursor->flags & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* Update the expanding cross target cursor and its HP gauge. Like the other cursors, alpha is left
 * uninitialised; func_002016e0's tile parameter is s32 because retail passes the converted float
 * straight through. */
// FUN_0020CE60
void btlPanelCursorDrawC(s32 task, u8 *cursor, u8 *panel, f32 *position)
{
    CursorColor color;
    Vec2f point;
    f32 delta[2];
    u8 *work;
    u8 *control;
    f32 alpha;
    f32 t;
    f32 length;
    s32 i;
    u32 packed;

    BtlPanelCursor *typedCursor = (BtlPanelCursor *)cursor;
    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (((BtlPanelCursor *)cursor)->state) {
    case 1:
        btlUnitGaugeClear((s32)(panel), (s32)( 0));
        ((BtlPanelCursor *)cursor)->frame = 0;
        ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
        ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
        typedCursor->state = 4;
        ((BtlPanelCursor *)cursor)->flags |= 1;
        ((BtlPanelCursor *)cursor)->flags |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear((s32)(panel), (s32)( 0));
            ((BtlPanelCursor *)cursor)->frame = 0;
            ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
            ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
            typedCursor->state = 4;
            ((BtlPanelCursor *)cursor)->flags |= 1;
            ((BtlPanelCursor *)cursor)->flags |= 0x10;
        } else {
            t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - ((BtlPanelCursor *)cursor)->position.x;
            delta[1] = position[1] - ((BtlPanelCursor *)cursor)->position.y;
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = typedCursor->position.x + delta[0];
            position[1] = typedCursor->position.y + delta[1];
            if (++typedCursor->frame == 4) {
                btlUnitGaugeClear((s32)(panel), (s32)( 0));
                typedCursor->frame = 0;
                ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
                typedCursor->state = 4;
                ((BtlPanelCursor *)cursor)->flags |= 1;
                ((BtlPanelCursor *)cursor)->flags |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 8.0f;
        alpha = 1.0f - t;
        if (++typedCursor->frame == 8) {
            typedCursor->state = 0;
            ((BtlPanelCursor *)cursor)->flags = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (((BtlPanelCursor *)cursor)->flags & 0x10) {
            ++((BtlPanelCursor *)cursor)->frame;
            if (((BtlPanelCursor *)cursor)->frame < 2) {
            } else if (((BtlPanelCursor *)cursor)->frame == 2) {
                typedCursor->flags |= 4;
                typedCursor->flags |= 2;
            } else if (((BtlPanelCursor *)cursor)->frame < 6) {
                t = (f32)(((BtlPanelCursor *)cursor)->frame - 2) / 4.0f;
                t = alpha - t;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f * t;
            } else if (((BtlPanelCursor *)cursor)->frame >= 6) {
                ((BtlPanelCursor *)cursor)->shape.distance = 0.0f;
            }
            if (typedCursor->frame < 2) {
            } else if (typedCursor->frame == 2) {
                typedCursor->flags |= 8;
            } else if (typedCursor->frame < 4) {
                t = (f32)(typedCursor->frame - 2) / 4.0f;
                length = 1.5f;
                ((BtlPanelCursor *)cursor)->animation.scale = (0.0f + length) - 0.5f * t;
            } else if (typedCursor->frame >= 4) {
                ((BtlPanelCursor *)cursor)->animation.scale = 1.0f;
            }
            if (typedCursor->frame >= 6) {
                typedCursor->flags &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (((BtlPanelCursor *)cursor)->flags & 4) {
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < 4; i++) {
            btlPanelDrawCursorSegment(work, color, position[0], position[1], i * 2,
                              0.0f, ((BtlPanelCursor *)cursor)->shape.distance);
        }
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 1) {
        point.x = position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (typedCursor->flags & 8) {
        point.x = position[0];
        point.y = position[1];
        btlUiSetRenderMode(2);
        packed = 0xFF620000 | (u8)(255.0f * alpha);
        t = ((BtlPanelCursor *)cursor)->animation.scale;
        shdDrawRotatedRect(point, 0.0f, packed, 5.0f * t, 77.0f * t, fGpffff837c, 1);
        t = typedCursor->animation.scale;
        shdDrawRotatedRect(point, 0.0f, packed, 5.0f * t, 77.0f * t, D_00761590, 1);
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* The lifetime pass keeps task on the stack while the loop holds its repeated color components in
 * registers. */
#pragma push
/* measured: retail keeps task on the stack and the color components in registers, which needs
 * opt_lifetimes on. */
#pragma opt_lifetimes on
// FUN_0020D6A0
/* Update the green four-segment/ring target cursor and its HP gauge. */
void btlPanelCursorDrawD(s32 task, u8 *cursor, u8 *panel, f32 *position)
{
    extern void btlUiSetScale(u8 *work, f32 x, f32 y);
    extern f32 D_00626C20[];
    extern f32 fGpffff84a4;
    typedef struct { f32 values[4]; } CursorDirections;
    CursorColor color;
    Vec2f point;
    f32 delta[2];
    CursorDirections dir;
    u8 *work;
    u8 *control;
    /* Reset paths leave alpha unwritten in retail, as in the three sibling cursors. */
    f32 alpha;
    f32 t;
    f32 length;
    s32 i;
    u16 cnt;

    BtlPanelCursor *typedCursor = (BtlPanelCursor *)cursor;
    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (((BtlPanelCursor *)cursor)->state) {
    case 1:
        btlUnitGaugeClear((s32)(panel), (s32)( 0));
        ((BtlPanelCursor *)cursor)->frame = 0;
        ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
        ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
        typedCursor->state = 4;
        ((BtlPanelCursor *)cursor)->flags |= 1;
        ((BtlPanelCursor *)cursor)->flags |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear((s32)(panel), (s32)( 0));
            ((BtlPanelCursor *)cursor)->frame = 0;
            ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
            ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
            typedCursor->state = 4;
            ((BtlPanelCursor *)cursor)->flags |= 1;
            ((BtlPanelCursor *)cursor)->flags |= 0x10;
        } else {
            t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - ((BtlPanelCursor *)cursor)->position.x;
            delta[1] = position[1] - ((BtlPanelCursor *)cursor)->position.y;
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = typedCursor->position.x + delta[0];
            position[1] = typedCursor->position.y + delta[1];
            if (++typedCursor->frame == 4) {
                btlUnitGaugeClear((s32)(panel), (s32)( 0));
                typedCursor->frame = 0;
                ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
                typedCursor->state = 4;
                ((BtlPanelCursor *)cursor)->flags |= 1;
                ((BtlPanelCursor *)cursor)->flags |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)((BtlPanelCursor *)cursor)->frame / 8.0f;
        alpha = 1.0f - t;
        if (++typedCursor->frame == 8) {
            typedCursor->state = 0;
            ((BtlPanelCursor *)cursor)->flags = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (((BtlPanelCursor *)cursor)->flags & 0x10) {
            ++((BtlPanelCursor *)cursor)->frame;
            cnt = ((BtlPanelCursor *)cursor)->frame;
            if (cnt < 3) {
            } else if (cnt == 3) {
                typedCursor->flags |= 4;
                typedCursor->flags |= 2;
            } else if (cnt < 5) {
                t = (f32)(cnt - 3) / 2.0f;
                t = alpha - t;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f * t;
            } else if (cnt >= 5) {
                ((BtlPanelCursor *)cursor)->shape.distanceBits = 0;
            }
            cnt = typedCursor->frame;
            if (cnt < 2) {
            } else if (cnt == 2) {
                typedCursor->flags |= 8;
            } else if (cnt < 4) {
                t = (f32)(cnt - 2) / 3.0f;
                length = 1.5f;
                ((BtlPanelCursor *)cursor)->animation.scale = (0.0f + length) - 0.5f * t;
            } else if (cnt >= 4) {
                ((BtlPanelCursor *)cursor)->animation.scale = 1.0f;
            }
            if (typedCursor->frame >= 5) {
                typedCursor->flags &= ~0x10;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (((BtlPanelCursor *)cursor)->flags & 4) {
        btlUiSetRenderMode(2);
        color.r = 14;
        color.g = 255;
        color.b = 2;
        color.a = (u8)(200.0f * alpha);
        /* Four segments use the even indices of the eight-slot ring. */
        for (i = 0; i < 4; i++) {
            btlPanelDrawCursorSegment(work, color, position[0], position[1], i * 2,
                              45.0f, ((BtlPanelCursor *)cursor)->shape.distance);
        }
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 1) {
        point.x = position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, fGpffff84a4 * alpha, 1);
    }
    if (typedCursor->flags & 8) {
        /* Snapshot all four direction components before publishing
         * them to the bounded ring-coordinate workspace. */
        dir = *(const CursorDirections *)D_00626C20;
        btlUiSetRenderMode(2);
        for (i = 0; i < 4; i++) {
            /* Separate these from the earlier interpolation values. */
            f32 ringScale;
            f32 ringRadius;
            ringScale = ((BtlPanelCursor *)cursor)->animation.scale;
            ringRadius = 21.0f * ringScale;
            point.x = position[0] + ringRadius * dir.values[(i + 1) % 4];
            point.y = position[1] + ringRadius * dir.values[i % 4];
            shdDrawRotatedRect(point, 0.0f, 0x0EFF02FF, 3.0f * ringScale,
                          26.0f * ringScale, fGpffff84a4 * (f32)i, 1);
        }
        t = ((BtlPanelCursor *)cursor)->animation.scale;
        point.x = position[0] - 11.0f * t;
        point.y = position[1] - 11.0f * t;
        color.r = 0x5E;
        color.g = 255;
        color.b = 2;
        color.a = (u8)(255.0f * alpha);
        btlUiSetScale(work, t, t);
        btlUiDrawSpriteFaded(work, 10, 3, point.x, point.y, color.r, color.g, color.b, color.a);
        btlUiSetScale(work, 1.0f, 1.0f);
        btlUiSetRenderMode(0);
    }
    if (typedCursor->flags & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] + 5.0f, 255, t);
    }
}
#pragma pop
