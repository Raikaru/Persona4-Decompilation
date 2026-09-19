#include "include_asm.h"
/* Persona 4 USA decompilation - btlPanelCursor.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"

extern u8 *func_00452560(s32 task);
extern void func_002016e0(u8 *work, s16 mode, s32 tile, f32 angle);
extern void func_00201820(s32 mode);
extern void func_0021ae80(u8 *work, s32 unused);
extern void func_0021aeb0(s32 arg0, u8 *work, s32 color, f32 x, f32 y, f32 alpha);
extern f32 func_0021b0a0(u8 *work);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern void func_0046d730(void *file, s32 line);
extern f32 iGpffff83d4[2];

typedef struct { u8 r, g, b, a; } CursorColor;
extern u8 D_00626C00[];

static inline void drawCursorSegment(u8 *work, CursorColor color, f32 x, f32 y,
                                      s32 index, f32 rotation, f32 distance)
{
    if (index >= 8) {
        func_0046d730(D_00626C00, 401);
    }
    func_002016e0(work, 13, (s32)(38.0f + distance), 360.0f * (f32)index / 8.0f + rotation);
    func_00201650(work, 10, 2, x - 13.0f, (y - 38.0f) - distance,
                  color.r, color.g, color.b, color.a);
    func_002016e0(work, 0, 0, 0.0f);
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
void func_0020bff0(s32 task, u8 *cursor, u8 *panel, f32 *position)
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

    work = func_00452560(task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        func_0021ae80(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        *(s32 *)(cursor + 0x14) = 0;
        *(s16 *)(cursor + 0x18) = 0;
        *(s16 *)(cursor + 0x1A) = 0;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            func_0021ae80(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            *(s32 *)(cursor + 0x14) = 0;
            *(s16 *)(cursor + 0x18) = 0;
            *(s16 *)(cursor + 0x1A) = 0;
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
                func_0021ae80(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                *(s32 *)(cursor + 0x14) = 0;
                *(s16 *)(cursor + 0x18) = 0;
                *(s16 *)(cursor + 0x1A) = 0;
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
                *(s32 *)(cursor + 0x14) = (s32)(8.0f * t);
            } else if (*(u16 *)(cursor + 4) >= 11) {
                *(s32 *)(cursor + 0x14) = 8;
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        *(Vec2f *)(cursor + 8) = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        count = *(s32 *)(cursor + 0x14);
        *(s16 *)(cursor + 0x18) = (*(s16 *)(cursor + 0x18) + 2) % 360;
        func_00201820(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            drawCursorSegment(work, color, position[0], position[1], i,
                              (f32)*(s16 *)(cursor + 0x18), 0.0f);
        }
        func_00201820(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        func_003657d0(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = func_0021b0a0(panel);
        func_0021aeb0(task, panel, 255, position[0] - 9.0f, position[1] - 5.0f, t);
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
void func_0020c680(s32 task, u8 *cursor, u8 *panel, f32 *position)
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

    work = func_00452560(task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        func_0021ae80(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        *(s32 *)(cursor + 0x14) = 0;
        *(s16 *)(cursor + 0x18) = 0;
        *(s16 *)(cursor + 0x1A) = 0;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            func_0021ae80(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            *(s32 *)(cursor + 0x14) = 0;
            *(s16 *)(cursor + 0x18) = 0;
            *(s16 *)(cursor + 0x1A) = 0;
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
                func_0021ae80(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                *(s32 *)(cursor + 0x14) = 0;
                *(s16 *)(cursor + 0x18) = 0;
                *(s16 *)(cursor + 0x1A) = 0;
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
                *(s32 *)(cursor + 0x14) = (s32)(7.0f * t);
                *(s16 *)(cursor + 0x1A) = (s16)(360.0f * ((0.0f + alpha) - 2.0f * t + t * t));
            } else if (*(u16 *)(cursor + 4) >= 11) {
                *(s32 *)(cursor + 0x14) = 7;
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        *(Vec2f *)(cursor + 8) = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        count = *(s32 *)(cursor + 0x14);
        *(s16 *)(cursor + 0x18) = (*(s16 *)(cursor + 0x18) + 2) % 360;
        *(s16 *)(cursor + 0x1A) = (*(s16 *)(cursor + 0x1A) + 356) % 360;
        func_00201820(2);
        color.r = 255;
        color.g = 148;
        color.b = 50;
        color.a = (u8)(204.0f * alpha);
        func_002016e0(work, 56, 53, (f32)*(s16 *)(cursor + 0x1A));
        func_00201650(work, 10, 4, position[0] - 56.0f, position[1] - 53.0f,
                      color.r, color.g, color.b, color.a);
        func_002016e0(work, 0, 0, 0.0f);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < count; i++) {
            drawCursorSegment(work, color, position[0], position[1], i,
                              (f32)*(s16 *)(cursor + 0x18), 0.0f);
        }
        func_00201820(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = 22.0f + position[0];
        point.y = position[1];
        func_003657d0(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = func_0021b0a0(panel);
        func_0021aeb0(task, panel, 255, position[0] - 9.0f, position[1] - 5.0f, t);
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
void func_0020ce60(s32 task, u8 *cursor, u8 *panel, f32 *position)
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

    work = func_00452560(task);
    control = work + 0x710;
    switch (*(u16 *)(cursor + 2)) {
    case 1:
        func_0021ae80(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        *(f32 *)(cursor + 0x18) = 1.5f;
        *(f32 *)(cursor + 0x14) = 10.0f;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 0x10) |= 1;
        *(u16 *)(cursor + 0x10) |= 0x10;
        break;
    case 2:
        if (*(u16 *)control & 2) {
            func_0021ae80(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            *(f32 *)(cursor + 0x18) = 1.5f;
            *(f32 *)(cursor + 0x14) = 10.0f;
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
                func_0021ae80(panel, 0);
                *(u16 *)(cursor + 4) = 0;
                *(f32 *)(cursor + 0x18) = 1.5f;
                *(f32 *)(cursor + 0x14) = 10.0f;
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
                *(f32 *)(cursor + 0x14) = 10.0f * t;
            } else if (*(u16 *)(cursor + 4) >= 6) {
                *(f32 *)(cursor + 0x14) = 0.0f;
            }
            if (*(u16 *)(cursor + 4) < 2) {
            } else if (*(u16 *)(cursor + 4) == 2) {
                *(u16 *)(cursor + 0x10) |= 8;
            } else if (*(u16 *)(cursor + 4) < 4) {
                t = (f32)(*(u16 *)(cursor + 4) - 2) / 4.0f;
                length = 1.5f;
                *(f32 *)(cursor + 0x18) = (0.0f + length) - 0.5f * t;
            } else if (*(u16 *)(cursor + 4) >= 4) {
                *(f32 *)(cursor + 0x18) = 1.0f;
            }
            if (*(u16 *)(cursor + 4) >= 6) {
                *(u16 *)(cursor + 0x10) &= 0xFFEF;
            }
        }
        *(Vec2f *)(cursor + 8) = *(Vec2f *)position;
        break;
    }
    if (*(u16 *)(cursor + 0x10) & 4) {
        func_00201820(2);
        color.r = 255;
        color.g = 174;
        color.b = 0;
        color.a = (u8)(150.0f * alpha);
        for (i = 0; i < 4; i++) {
            drawCursorSegment(work, color, position[0], position[1], i * 2,
                              0.0f, *(f32 *)(cursor + 0x14));
        }
        func_00201820(0);
    }
    if (*(u16 *)(cursor + 0x10) & 1) {
        point.x = position[0];
        point.y = position[1];
        func_003657d0(point, 0.0f, 255, 22.0f, iGpffff83d4[1] * alpha, 1);
    }
    if (*(u16 *)(cursor + 0x10) & 8) {
        point.x = position[0];
        point.y = position[1];
        func_00201820(2);
        packed = 0xFF620000 | (u8)(255.0f * alpha);
        t = *(f32 *)(cursor + 0x18);
        func_00364c90(point, 0.0f, packed, 5.0f * t, 77.0f * t, fGpffff837c, 1);
        t = *(f32 *)(cursor + 0x18);
        func_00364c90(point, 0.0f, packed, 5.0f * t, 77.0f * t, D_00761590, 1);
        func_00201820(0);
    }
    if (*(u16 *)(cursor + 0x10) & 2) {
        t = func_0021b0a0(panel);
        func_0021aeb0(task, panel, 255, position[0] - 9.0f, position[1] - 5.0f, t);
    }
}
/* measured triage: no real C body was produced for the 2416B retail window;
   prior ring/MAC probes were discarded rather than parked because object-size
   closeness was not established. */
/* measured 0020d6a0 (WColdC): `>=5`->`>4` + `>=4`->`>3` on the two else-if re-reads gives retail `slti $at` dests (was `$v1`; one src now `$a0` exact, one `$v1` colour), words 526 via `tools/measure_guarded.py` unchanged, 522/600 (-78) 547 edits (+2 reloc-only) via `tools/fnalign.py --candidate` unchanged; pragmas via `tools/probe_variants.py` (at-flip base 526): `schedule on` 550, `opt_common_subs off` 563, `opt_loop_invariants on` 526 neutral, `opt_propagation off` 555; `tools/wscan_pairs.py` 0 vs 0 (retail `daddu` 28 is `move` alias, not width). */
/* gate: object 522 against retail 600, -13.0% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
// FUN_0020D6A0 NONMATCHING
#ifdef NON_MATCHING
void func_0020d6a0(s32 task, u8 *cursor, u8 *panel, f32 *position) {
    extern void func_00201720(u8 *work, f32 arg1, f32 arg2);
    extern f32 D_00626C20[];
    extern f32 fGpffff84a4;
    u8 *work;
    u16 cnt;
    u16 mode;
    u16 flags;
    u16 cntA;
    u16 cntB;
    f32 dx;
    f32 dy;
    f32 r;
    f32 t;
    f32 c24;
    f32 dir[4];
    f32 angle;
    s32 i;
    f32 f20;
    f32 f21;
    f32 f22;
    union {
        f32 f;
        u8 b[4];
    } col;
    Vec2f pt;

    work = func_00452560(task);
    mode = *(u16 *)(cursor + 2);
    flags = *(u16 *)(cursor + 16);
    if (mode == 4) {
        if ((flags & 0x10) != 0) {
            cntA = *(u16 *)(cursor + 4) + 1;
            *(u16 *)(cursor + 4) = cntA;
            cnt = cntA;
            if (cntA >= 3) {
                if (cntA == 3) {
                    *(u16 *)(cursor + 16) |= 4;
                    *(u16 *)(cursor + 16) |= 2;
                } else if (*(u16 *)(cursor + 4) > 4) {
                    *(u32 *)(cursor + 20) = 0;
                } else {
                    t = 1.0f - (f32)((s32)cnt - 3) / 2.0f;
                    *(f32 *)(cursor + 20) = 10.0f * t;
                }
            }
            cntA = *(u16 *)(cursor + 4);
            cnt = cntA;
            if (cntA >= 2) {
                if (cntA == 2) {
                    *(u16 *)(cursor + 16) |= 8;
                } else if (*(u16 *)(cursor + 4) > 3) {
                    *(f32 *)(cursor + 24) = 1.0f;
                } else {
                    *(f32 *)(cursor + 24) = 1.5f - 0.5f * (f32)((s32)cnt - 2) / 3.0f;
                }
            }
            if (*(u16 *)(cursor + 4) >= 5) {
                *(u16 *)(cursor + 16) &= ~0x10;
            }
        }
        dy = position[1];
        *(u32 *)(cursor + 8) = *(u32 *)position;
        *(f32 *)(cursor + 12) = dy;
    } else if (mode == 3) {
        cnt = *(u16 *)(cursor + 4) + 1;
        *(u16 *)(cursor + 4) = cnt;
        if (cnt == 8) {
            *(u16 *)(cursor + 2) = 0;
            *(u16 *)(cursor + 16) = 0;
        }
    } else if (mode == 2) {
        if ((*(u16 *)(work + 0x710) & 2) != 0) {
            goto TAIL;
        }
        dx = position[0] - *(f32 *)(cursor + 8);
        dy = position[1] - *(f32 *)(cursor + 12);
        r = func_003e41e0(&dx, &dx);
        {
            f32 fc;
            f32 x;
            cntB = *(u16 *)(cursor + 4);
            fc = (f32)cntB;
            x = (2.0f * fc) / 4.0f;
            t = 2.0f * x - x * x;
        }
        r = r * t;
        dx = dx * r;
        dy = dy * r;
        position[0] = *(f32 *)(cursor + 8) + dx;
        position[1] = *(f32 *)(cursor + 12) + dy;
        cntB = *(u16 *)(cursor + 4) + 1;
        *(u16 *)(cursor + 4) = cntB;
        cnt = cntB;
        if (cntB == 4) {
            func_0021ae80(panel, 0);
            *(u16 *)(cursor + 4) = 0;
            *(f32 *)(cursor + 24) = 1.5f;
            *(f32 *)(cursor + 20) = 10.0f;
            *(u16 *)(cursor + 2) = 4;
            *(u16 *)(cursor + 16) |= 1;
            *(u16 *)(cursor + 16) |= 0x10;
        }
    } else if (mode == 1) {
TAIL:
        func_0021ae80(panel, 0);
        *(u16 *)(cursor + 4) = 0;
        *(f32 *)(cursor + 24) = 1.5f;
        *(f32 *)(cursor + 20) = 10.0f;
        *(u16 *)(cursor + 2) = 4;
        *(u16 *)(cursor + 16) |= 1;
        *(u16 *)(cursor + 16) |= 0x10;
    }
    if ((flags & 4) != 0) {
        func_00201820(2);
        col.b[0] = 0x0E;
        col.b[1] = 0xFF;
        col.b[2] = 2;
        col.b[3] = (u8)(200.0f * *(f32 *)(cursor + 20));
        f20 = *(f32 *)(cursor + 0x14);
        f21 = position[1];
        f22 = position[0];
        i = 0;
        while (i < 4) {
            if (2 * i >= 8) {
                func_0046d730(D_00626C00, 401);
            }
            func_002016e0(work, 13, (s32)(f20 + 38.0f), 360.0f * (f32)i / 8.0f + 45.0f);
            func_00201650(work, 10, 2, f22 - 13.0f, (f21 - 38.0f) - f20, col.b[0], col.b[1], col.b[2], col.b[3]);
            func_002016e0(work, 0, 0, 0.0f);
            i++;
        }
        func_00201820(0);
    }
    if ((flags & 1) != 0) {
        pt.x = position[0];
        pt.y = position[1];
        func_003657d0(pt, 0.0f, 255, 22.0f, fGpffff84a4 * t, 1);
    }
    if ((flags & 8) != 0) {
        dir[0] = D_00626C20[0];
        dir[1] = D_00626C20[1];
        dir[2] = D_00626C20[2];
        dir[3] = D_00626C20[3];
        func_00201820(2);
        c24 = *(f32 *)(cursor + 24);
        for (i = 0; i < 4; i++) {
            t = 21.0f * *(f32 *)(cursor + 0x18);
            pt.x = position[0] + t * dir[(i + 1) & 3];
            pt.y = position[1] + t * dir[i & 3];
            angle = fGpffff84a4 * (f32)i;
            func_00364c90(pt, 0.0f, 0x0EFF02FF, 3.0f * c24, 26.0f * c24, angle, 1);
        }
        pt.x = position[0] - 11.0f * c24;
        pt.y = position[1] - 11.0f * c24;
        col.b[0] = 0x5E;
        col.b[1] = 0xFF;
        col.b[2] = 2;
        col.b[3] = (u8)(255.0f * *(f32 *)(cursor + 0x18));
        func_00201720(work, angle, angle);
        func_00201650(work, 10, 3, pt.x, pt.y, col.b[0], col.b[1], col.b[2], col.b[3]);
        func_00201720(work, 1.0f, 1.0f);
        func_00201820(0);
    }
    if ((flags & 2) != 0) {
        func_0021b0a0(panel);
        func_0021aeb0(task, panel, 255, position[0] - 9.0f, position[1] + 5.0f, 0.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlPanelCursor", func_0020d6a0);
#endif
