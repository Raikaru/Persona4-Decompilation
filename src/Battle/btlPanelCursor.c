#include "include_asm.h"
/* Persona 4 USA decompilation - btlPanelCursor.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"

extern u32 kwlnTaskGetWork(void *task);
extern void btlUiSetTileOffset(u8 *work, s16 mode, s32 tile, f32 angle);
extern void btlUiSetRenderMode(s32 mode);
extern void btlUnitGaugeClear(u8 *work, s32 unused);
extern f32 btlGaugeHpRatio(u8 *work);
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

static inline void drawCursorSegment(u8 *work, CursorColor color, f32 x, f32 y,
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
/* Recovered.  `alpha` is deliberately left uninitialised: retail reads the
   FPR on the reset path (case 1 sets the flag bits that make the later
   `iGpffff83d4[1] * alpha` live) without ever writing it there, so the
   defensive `= 1.0f` initialiser this recovery used to carry produced two
   extra instructions (`lui`/`mtc1` of 1.0f into $f20) at the top and cost
   the whole match. */
// FUN_0020BFF0
/* Update the eight-segment target cursor and its HP gauge. Measured: typing state, frame, flags or
 * position loads changes MATCH; keep those byte-shaped accesses while typing the independent animation
 * fields. */
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

    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        btlUnitGaugeClear(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
            *(u16 *)(cursor + 2) = 4;
            *(u16 *)(cursor + 0x10) |= 1;
            *(u16 *)(cursor + 0x10) |= 0x10;
        } else {
            t = (f32)(u32)*(u16 *)(cursor + 4) / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - *(f32 *)(cursor + 8);
            delta[1] = position[1] - *(f32 *)(cursor + 0xC);
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = *(f32 *)(cursor + 8) + delta[0];
            position[1] = *(f32 *)(cursor + 0xC) + delta[1];
            if (++*(u16 *)(cursor + 4) == 4) {
                btlUnitGaugeClear(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
                *(u16 *)(cursor + 2) = 4;
                *(u16 *)(cursor + 0x10) |= 1;
                *(u16 *)(cursor + 0x10) |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)*(u16 *)(cursor + 4) / 8.0f;
        alpha = 1.0f - t;
        if (++*(u16 *)(cursor + 4) == 8) {
            *(u16 *)(cursor + 2) = 0;
            *(u16 *)(cursor + 0x10) = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (*(u16 *)(cursor + 0x10) & 0x10) {
            ++*(u16 *)(cursor + 4);
            if (*(u16 *)(cursor + 4) < 2) {
            } else if (*(u16 *)(cursor + 4) == 2) {
                *(u16 *)(cursor + 0x10) |= 4;
                *(u16 *)(cursor + 0x10) |= 2;
            } else if (*(u16 *)(cursor + 4) < 11) {
                t = (f32)(*(u16 *)(cursor + 4) - 2) / 9.0f;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = (s32)(8.0f * t);
            } else if (*(u16 *)(cursor + 4) >= 11) {
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 8;
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        count = ((BtlPanelCursor *)cursor)->shape.segmentCount;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = (((BtlPanelCursor *)cursor)->animation.ring.segmentAngle + 2) % 360;
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            drawCursorSegment(work, color, position[0], position[1], i,
                              (f32)*(s16 *)(cursor + 0x18), 0.0f);
        }
        btlUiSetRenderMode(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* measured triage: no real C body was produced for the 2016B retail window;
   prior switch/MAC probes were discarded rather than parked because object-size
   closeness was not established. */
/* Recovered.  `alpha` is deliberately left uninitialised: retail reads the
   FPR on the reset path (case 1 sets the flag bits that make the later
   `iGpffff83d4[1] * alpha` live) without ever writing it there, so the
   defensive `= 1.0f` initialiser this recovery used to carry produced two
   extra instructions (`lui`/`mtc1` of 1.0f into $f20) at the top and cost
   the whole match. */
// FUN_0020C680
/* Update the seven-segment target cursor with its rotating sprite and HP gauge. Measured: typing
 * state, frame, flags or position loads changes MATCH; keep those byte-shaped accesses while typing
 * the independent animation fields. */
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

    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        btlUnitGaugeClear(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
            ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
            *(u16 *)(cursor + 2) = 4;
            *(u16 *)(cursor + 0x10) |= 1;
            *(u16 *)(cursor + 0x10) |= 0x10;
        } else {
            t = (f32)(u32)*(u16 *)(cursor + 4) / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - *(f32 *)(cursor + 8);
            delta[1] = position[1] - *(f32 *)(cursor + 0xC);
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = *(f32 *)(cursor + 8) + delta[0];
            position[1] = *(f32 *)(cursor + 0xC) + delta[1];
            if (++*(u16 *)(cursor + 4) == 4) {
                btlUnitGaugeClear(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = 0;
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = 0;
                *(u16 *)(cursor + 2) = 4;
                *(u16 *)(cursor + 0x10) |= 1;
                *(u16 *)(cursor + 0x10) |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)*(u16 *)(cursor + 4) / 8.0f;
        alpha = 1.0f - t;
        if (++*(u16 *)(cursor + 4) == 8) {
            *(u16 *)(cursor + 2) = 0;
            *(u16 *)(cursor + 0x10) = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (*(u16 *)(cursor + 0x10) & 0x10) {
            ++*(u16 *)(cursor + 4);
            if (*(u16 *)(cursor + 4) < 2) {
            } else if (*(u16 *)(cursor + 4) == 2) {
                *(u16 *)(cursor + 0x10) |= 4;
                *(u16 *)(cursor + 0x10) |= 2;
            } else if (*(u16 *)(cursor + 4) < 11) {
                t = (f32)(*(u16 *)(cursor + 4) - 2) / 9.0f;
                ((BtlPanelCursor *)cursor)->shape.segmentCount = (s32)(7.0f * t);
                ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = (s16)(360.0f * ((0.0f + alpha) - 2.0f * t + t * t));
            } else if (*(u16 *)(cursor + 4) >= 11) {
                ((BtlPanelCursor *)cursor)->shape.segmentCount = 7;
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        count = ((BtlPanelCursor *)cursor)->shape.segmentCount;
        ((BtlPanelCursor *)cursor)->animation.ring.segmentAngle = (((BtlPanelCursor *)cursor)->animation.ring.segmentAngle + 2) % 360;
        ((BtlPanelCursor *)cursor)->animation.ring.spriteAngle = (((BtlPanelCursor *)cursor)->animation.ring.spriteAngle + 356) % 360;
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 148;
        color.b = 50;
        color.a = (u8)(204.0f * alpha);
        btlUiSetTileOffset(work, 56, 53, (f32)*(s16 *)(cursor + 0x1A));
        btlUiDrawSpriteFaded(work, 10, 4, position[0] - 56.0f, position[1] - 53.0f,
                      color.r, color.g, color.b, color.a);
        btlUiSetTileOffset(work, 0, 0, 0.0f);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            drawCursorSegment(work, color, position[0], position[1], i,
                              (f32)*(s16 *)(cursor + 0x18), 0.0f);
        }
        btlUiSetRenderMode(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* measured triage: no real C body was produced for the 2112B retail window;
   prior switch/MAC probes were discarded rather than parked because object-size
   closeness was not established. */
/* Recovered.  Same uninitialised `alpha` as the two cursors above, plus the
   `tile` parameter of func_002016e0: retail passes the converted float
   straight through (`mfc1 $a2,$f0`), so the parameter is s32, not s16 -
   the narrow declaration added a dsll32/dsra32 pair here.  The other call
   sites pass a constant distance, where the conversion folds away, which
   is why they matched with the wrong width. */
// FUN_0020CE60
/* Update the expanding cross target cursor and its HP gauge. Measured: typed prefix and scale reloads
 * change MATCH; raw accesses preserve the reset-path alpha omission and callback aliasing. */
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

    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        btlUnitGaugeClear(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
        ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
            ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
            *(u16 *)(cursor + 2) = 4;
            *(u16 *)(cursor + 0x10) |= 1;
            *(u16 *)(cursor + 0x10) |= 0x10;
        } else {
            t = (f32)(u32)*(u16 *)(cursor + 4) / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - *(f32 *)(cursor + 8);
            delta[1] = position[1] - *(f32 *)(cursor + 0xC);
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = *(f32 *)(cursor + 8) + delta[0];
            position[1] = *(f32 *)(cursor + 0xC) + delta[1];
            if (++*(u16 *)(cursor + 4) == 4) {
                btlUnitGaugeClear(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
                *(u16 *)(cursor + 2) = 4;
                *(u16 *)(cursor + 0x10) |= 1;
                *(u16 *)(cursor + 0x10) |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)*(u16 *)(cursor + 4) / 8.0f;
        alpha = 1.0f - t;
        if (++*(u16 *)(cursor + 4) == 8) {
            *(u16 *)(cursor + 2) = 0;
            *(u16 *)(cursor + 0x10) = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (*(u16 *)(cursor + 0x10) & 0x10) {
            ++*(u16 *)(cursor + 4);
            if (*(u16 *)(cursor + 4) < 2) {
            } else if (*(u16 *)(cursor + 4) == 2) {
                *(u16 *)(cursor + 0x10) |= 4;
                *(u16 *)(cursor + 0x10) |= 2;
            } else if (*(u16 *)(cursor + 4) < 6) {
                t = (f32)(*(u16 *)(cursor + 4) - 2) / 4.0f;
                t = alpha - t;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f * t;
            } else if (*(u16 *)(cursor + 4) >= 6) {
                ((BtlPanelCursor *)cursor)->shape.distance = 0.0f;
            }
            if (*(u16 *)(cursor + 4) < 2) {
            } else if (*(u16 *)(cursor + 4) == 2) {
                *(u16 *)(cursor + 0x10) |= 8;
            } else if (*(u16 *)(cursor + 4) < 4) {
                t = (f32)(*(u16 *)(cursor + 4) - 2) / 4.0f;
                length = 1.5f;
                ((BtlPanelCursor *)cursor)->animation.scale = (0.0f + length) - 0.5f * t;
            } else if (*(u16 *)(cursor + 4) >= 4) {
                ((BtlPanelCursor *)cursor)->animation.scale = 1.0f;
            }
            if (*(u16 *)(cursor + 4) >= 6) {
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        btlUiSetRenderMode(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < 4; i++) {
            drawCursorSegment(work, color, position[0], position[1], i * 2,
                              0.0f, ((BtlPanelCursor *)cursor)->shape.distance);
        }
        btlUiSetRenderMode(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 8) {
        point.x = position[0];
        point.y = position[1];
        btlUiSetRenderMode(2);
        packed = 0xFF620000 | (u8)(255.0f * alpha);
        t = *(f32 *)(cursor + 0x18);
        shdDrawRotatedRect(point, 0.0f, packed, 5.0f * t, 77.0f * t, fGpffff837c, 1);
        t = *(f32 *)(cursor + 0x18);
        shdDrawRotatedRect(point, 0.0f, packed, 5.0f * t, 77.0f * t, D_00761590, 1);
        btlUiSetRenderMode(0);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] - 5.0f, 255, t);
    }
}
/* Native b210 O2: 2404/2416 bytes, 32 resolved relocations and twelve
 * zero alignment bytes. The lifetime pass retains task on the stack
 * while the loop keeps its repeated color components in registers.
 * See docs/probe_archive/Battle_cursor_0020d6a0_20260923.md. */
#pragma push
#pragma opt_lifetimes on
// FUN_0020D6A0
/* Update the green four-segment/ring target cursor and its HP gauge. Measured: typing state, frame,
 * flags or position loads changes MATCH; keep those byte-shaped accesses while typing the independent
 * animation fields. */
void btlPanelCursorDrawD(s32 task, u8 *cursor, u8 *panel, f32 *position)
{
    extern void btlUiSetScale(u8 *work, f32 scaleX, f32 scaleY);
    extern f32 D_00626C20[];
    extern f32 fGpffff84a4;
    typedef struct { f32 values[4]; } CursorDirections;
    CursorColor color;
    Vec2f point;
    f32 delta[2];
    CursorDirections dir;
    u8 *work;
    u8 *control;
    /* Reset paths leave alpha unwritten in retail, just as in the three
     * sibling cursors. Keep that original initialization omission. */
    f32 alpha;
    f32 t;
    f32 length;
    s32 i;
    u16 cnt;

    work = (u8 *)kwlnTaskGetWork((void *)task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        btlUnitGaugeClear(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
        ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            btlUnitGaugeClear(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
            ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
            *(u16 *)(cursor + 2) = 4;
            *(u16 *)(cursor + 0x10) |= 1;
            *(u16 *)(cursor + 0x10) |= 0x10;
        } else {
            t = (f32)(u32)*(u16 *)(cursor + 4) / 4.0f;
            alpha = 2.0f * t - t * t;
            length = position[0];
            delta[0] = length - *(f32 *)(cursor + 8);
            delta[1] = position[1] - *(f32 *)(cursor + 0xC);
            length = func_003e41e0(delta, delta);
            length *= alpha;
            delta[0] *= length;
            delta[1] *= length;
            position[0] = *(f32 *)(cursor + 8) + delta[0];
            position[1] = *(f32 *)(cursor + 0xC) + delta[1];
            if (++*(u16 *)(cursor + 4) == 4) {
                btlUnitGaugeClear(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                ((BtlPanelCursor *)cursor)->animation.scale = 1.5f;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f;
                *(u16 *)(cursor + 2) = 4;
                *(u16 *)(cursor + 0x10) |= 1;
                *(u16 *)(cursor + 0x10) |= 0x10;
            }
        }
        break;
    case 3:
        t = (f32)(u32)*(u16 *)(cursor + 4) / 8.0f;
        alpha = 1.0f - t;
        if (++*(u16 *)(cursor + 4) == 8) {
            *(u16 *)(cursor + 2) = 0;
            *(u16 *)(cursor + 0x10) = 0;
        }
        break;
    case 4:
        alpha = 1.0f;
        if (*(u16 *)(cursor + 0x10) & 0x10) {
            ++*(u16 *)(cursor + 4);
            cnt = *(u16 *)(cursor + 4);
            if (cnt < 3) {
            } else if (cnt == 3) {
                *(u16 *)(cursor + 0x10) |= 4;
                *(u16 *)(cursor + 0x10) |= 2;
            } else if (cnt < 5) {
                t = (f32)(cnt - 3) / 2.0f;
                t = alpha - t;
                ((BtlPanelCursor *)cursor)->shape.distance = 10.0f * t;
            } else if (cnt >= 5) {
                ((BtlPanelCursor *)cursor)->shape.distanceBits = 0;
            }
            cnt = *(u16 *)(cursor + 4);
            if (cnt < 2) {
            } else if (cnt == 2) {
                *(u16 *)(cursor + 0x10) |= 8;
            } else if (cnt < 4) {
                t = (f32)(cnt - 2) / 3.0f;
                length = 1.5f;
                ((BtlPanelCursor *)cursor)->animation.scale = (0.0f + length) - 0.5f * t;
            } else if (cnt >= 4) {
                ((BtlPanelCursor *)cursor)->animation.scale = 1.0f;
            }
            if (*(u16 *)(cursor + 4) >= 5) {
                *(u16 *)(cursor + 0x10) &= ~0x10;
            }
        }
        ((BtlPanelCursor *)cursor)->position = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        btlUiSetRenderMode(2);
        color.r = 14;
        color.g = 255;
        color.b = 2;
        color.a = (u8)(200.0f * alpha);
        /* Four segments use the even indices of the eight-slot ring. */
        for (i = 0; i < 4; i++) {
            drawCursorSegment(work, color, position[0], position[1], i * 2,
                              45.0f, ((BtlPanelCursor *)cursor)->shape.distance);
        }
        btlUiSetRenderMode(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = position[0];
        point.y = position[1];
        shdDrawRotatingQuad(point, 0.0f, 255, 22.0f, fGpffff84a4 * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 8) {
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
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = btlGaugeHpRatio(panel);
        btlGaugeDrawUnit(task, panel, position[0] - 9.0f, position[1] + 5.0f, 255, t);
    }
}
#pragma pop
