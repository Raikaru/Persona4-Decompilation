/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00210c70-00218730 */

#include "datCalc_unit_internal.h"
#include "member_access.h"
#include "rw_camera_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "datPersona_internal.h"
#include "btl_effect_internal.h"
#include "btl_hud_internal.h"
/* Enemy message flags occupy the first halfword of each 0x3C-byte table row. */
typedef struct DatEnemyRecord {
    u16 flags;
    u8 pad02[0x3A];
} DatEnemyRecord;

extern s32 iGpffffa598;
extern u8 *iGpffffb3ac; /* active battle state */
extern f32 D_008872F8[];
extern BtlShuffleRenderStateSet D_00887300[];
extern void sprintf(u8 *dst, const char *fmt, s32 arg);
extern void itfMesWindowSetString(u8 *, s32, u8 *);
extern void frFontListKeepOrRelease(s32);
extern void itfMesWindowClear(s32, s32);
extern void btlUiSetRenderStates(void);
extern void btlDamageDrawGaugeBar(u8 *, u8 *);
extern void memset(void *destination, s32 value, u32 size);
extern u32 kwlnTaskGetWork(void *task);
extern f32 cosf(f32);
extern f32 sinf(f32);
extern f32 fGpffff8378;
extern s32 btlDamageIsIdle(s32);
extern void btlPanelSetCountdown(s32, s32);
extern void btlSoundFadeChannel(s16 channel, s32 fadeFrames);
extern u32 datGetFlag(s32);
extern s32 datCalcEnemyHasTableFlag(u8 *);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag(const void *, s32);
extern void PrimAppendNode(void *, void *);
extern u8 D_00796340[];
extern s32 hMaestroDecodeIsReady(s32);
extern u8 *iGpffffb3c4; /* enemy table: 0x3C-byte records */
extern s32 sdkSpriteRequestLoad(void *);
extern u8 D_00626C30[];
extern u8 D_00626CA0[];
extern void btlEncounterDrawTransition(u8 *drawPayload, s32 workAddress, void *callback);
extern void sdkSpriteRelease(void *);
extern void (*jtbl_008873EC[])(void *);
extern s32 btlEncounterIsActive(void);
extern s32 kwlnTaskGetTaskByName(void *);
extern u8 D_00626C80[];
extern void btlUiSetScale(void *, f32, f32);
extern void btlUiSetRect(s32 *, f32, f32, f32, f32);
extern void btlUiSetTileOffset(u8 *, s16, s32, f32);
extern void btlUiSetFactorXY(u8 *, f32, f32);
extern s32 datCalcUnitClass(u8 *);
extern s32 btlActionGetQueueFront(void);
extern void btlPortraitDraw(s32 *, u8 *, f32, f32, s32);
extern void btlPortraitDrawPulse(s32 *, u8 *, f32, f32, s32);
extern void btlPortraitDrawFlash(s32 *, u8 *, f32, f32, s32);
extern f32 fGpffff84a0;
extern s32 datCalcMaxHp(s32);
extern void btlDamageDrawPanel(u8 *, u8 *);
extern void btlTransitionDrawFrame(u8 *, u8 *);
static inline f32 ws14_mul(f32 left, f32 right)
{
    return left * right;
}

static inline f32 ws14_add(f32 left, f32 right)
{
    return left + right;
}

static inline f32 ws14_sub(f32 left, f32 right)
{
    return left - right;
}

typedef struct BtlUnit BtlUnit;

typedef struct RwV3d RwV3d;

typedef struct {
    f32 offset;
    u8 alpha;
    s32 drawGauge;
    f32 gaugeX;
    f32 gaugeY;
} DamageDrawInfo;

/* Retail-exact: 1604 bytes, resolved calls/globals and twelve zero alignment
 * bytes. HP/SP amount and color locals have independent row lifetimes. The
 * flag compound-clear preserves the expiration reload; the gauge provider
 * takes X/Y before color in the independent EE integer/float argument banks.
 * See docs/probe_archive/Battle_damage_panel_00210c70_20260922.md. */
// Intent: draw the damage popup's HP and SP numbers, gauge and status icon for one target. [inferred]
/* b210: remaining flag, age and task-handle accesses individually change instructions when typed. */
// FUN_00210C70
void btlDamageDrawPanel(u8 *drawState, u8 *entry)
{
    extern s32 btlTargetFindInRange(s32 position, u8 *output);
    extern f32 btlSelectionEaseCurve(s32 drawState, s32 entry, s32, s32);
    extern void btlUnitGetHudAnchor(BtlUnit *unit, RwV3d *outPosition);
    extern void btlTransitionStepStretch(u8 *drawState, u8 *entry, u8 *, u8 *);
    extern void btlTransitionStepExpand(u8 *drawState, u8 *entry, u8 *, u8 *);
    extern void btlTransitionStepPulse(u8 *task, u8 *transition, f32 x, f32 y);
    extern void btlTransitionStepSlide(u8 *drawState, u8 *entry, u8 *, f32 x, f32 y, s32 a, u8 *out);
    extern void btlSelectionDrawValue(u8 *drawWork, f32 x, f32 y, s32 value, s32 rightAligned, u32 packedColor);
    extern f32 fGpffff8110;
    extern f32 fGpffff827c;
    s32 *panel;
    u8 *task;
    u8 *transition;
    u8 *work;
    s32 numeralMode;
    s32 stage;
    s32 first;
    s32 *icon;
    DamageDrawInfo info;
    f32 pos[2];
    u8 *unit;
    s32 drew;
    s32 alive;
    f32 shift;
    f32 rowX;
    f32 alpha;
    f32 base;
    f32 height;
    f32 rate;
    f32 fade;
    f32 scale;

    task = drawState;
    transition = entry;
    panel = (s32 *)kwlnTaskGetWork(((BtlDamageState *)task)->task);
    if (((((BtlDamageEntry *)transition)->flags & 2) && (((BtlDamageEntry *)transition)->age >= 6)) || (((BtlDamageEntry *)transition)->age >= 0x19)) {
        MEMBER(u16, transition, BtlDamageEntry, flags) &= ~1U;
        alive = 0;
    } else {
        alive = 1;
    }
    if (alive != 0) {
        if (MEMBER(u16, transition, BtlDamageEntry, flags) & 8) {
            btlUnitGetHudAnchor((BtlUnit *)((BtlDamageEntry *)transition)->unit, (RwV3d *)(transition + 4));
        }
        if (btlTargetFindInRange((s32)(transition + 4), (u8 *)pos) != 0) {
            work = ((BtlDamageEntry *)transition)->unit + 0xA3C;
            info.drawGauge = 0;
            btlUiSetRect(panel, pos[0] - 86.0f, pos[1] - 86.0f, 172.0f, 172.0f);
            drew = 0;
            if (((BtlDamageEntry *)transition)->drawFlags & 1) {
                btlTransitionStepStretch(task, transition, work, (u8 *)&info);
                drew = 1;
            }
            if (MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 2) {
                btlTransitionStepExpand(task, transition, work, (u8 *)&info);
                drew = 1;
            }
            if (MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 4) {
                btlTransitionStepPulse(task, transition, pos[0] - 86.0f, pos[1] - 86.0f);
                drew = 1;
            }
            if (MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 8) {
                icon = (s32 *)kwlnTaskGetWork(MEMBER(void *, task, BtlDamageState, task));
                stage = MEMBER(s32, transition, BtlDamageEntry, age);
                rate = btlSelectionEaseCurve(stage, 0, 4, 0);
                scale = 0.0f;
                if (!(rate <= scale)) {
                    scale = fGpffff827c - fGpffff8110 * rate;
                    btlUiSetFactorXY((u8 *)icon, scale, scale);
                    btlUiDrawSpriteFaded((u8 *)icon, 0xA, 0xF, 57.0f, 63.0f, 0x15U, 0x15U, 0x15U, 0xFFU);
                    btlUiDrawSpriteFaded((u8 *)icon, 0xA, 0x10, 86.0f, 63.0f, 0x15U, 0x15U, 0x15U, 0xFFU);
                    btlUiSetFactorXY((u8 *)icon, 1.0f, 1.0f);
                }
                rate = btlSelectionEaseCurve(stage, 5, 7, 0);
                if (!(rate <= 0.0f)) {
                    alpha = 255.0f * rate;
                    fade = ws14_mul(20.0f, ws14_sub(1.0f, rate));
                    height = ws14_add(75.0f, fade);
                    btlUiDrawSpriteFaded((u8 *)icon, 0xA, 0xA, 47.0f, height, 0x15U, 0x15U, 0x15U, (u8)alpha);
                    btlUiDrawSpriteFaded((u8 *)icon, 0xA, 9, 47.0f, height, 0xFFU, 0xFU, 2U, (u8)alpha);
                }
                drew = 1;
            }
            if (drew != 0) {
                rowX = 86.0f;
                base = 83.0f;
                numeralMode = 1;
                first = 0;
                shift = 0.0f;
            } else {
                rowX = 86.0f;
                base = 83.0f;
                numeralMode = 1;
                first = numeralMode;
                if ((MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 0x30) == 0x30) {
                    shift = -10.0f;
                } else {
                    shift = 0.0f;
                }
            }
            if (MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 0x10) {
                s32 hpAmount;
                s32 hpColor;
                s32 hpBackground;
                hpAmount = ((BtlDamageEntry *)transition)->hpAmount;
                if (hpAmount < 0) {
                    hpAmount = -hpAmount;
                    hpBackground = 0xFF;
                    hpColor = -0x100;
                } else {
                    hpBackground = 0xFF;
                    hpColor = 0xFFD92F00;
                }
                if (first != 0) {
                    btlTransitionStepSlide(task, transition, work, pos[0] - 86.0f, pos[1] - 86.0f, hpBackground, (u8 *)&info);
                    first = 0;
                }
                if (info.alpha > 0) {
                    hpColor |= info.alpha;
                    btlSelectionDrawValue((u8 *)panel, rowX, shift + (base + info.offset),
                                  hpAmount, numeralMode, hpColor);
                }
                if (info.drawGauge != 0) {
                    unit = ((BtlDamageEntry *)transition)->unit;
                    /* The current HP ratio scales the unit gauge. */
                    btlGaugeDrawUnit(MEMBER(s32, task, BtlDamageState, task), unit, info.gaugeX,
                                  info.gaugeY + shift, 0xFF, ((BtlUnit *)(unit))->hpRatio);
                }
                base += 27.0f;
            }
            if (MEMBER(u16, transition, BtlDamageEntry, drawFlags) & 0x20) {
                s32 spAmount;
                s32 spColor;
                s32 spBackground;
                spAmount = ((BtlDamageEntry *)transition)->spAmount;
                if (spAmount < 0) {
                    spAmount = -spAmount;
                    spBackground = 0xFF;
                    spColor = 0x67F1FF00;
                } else {
                    spBackground = 0xFF;
                    spColor = 0xB7FF3600;
                }
                if (first != 0) {
                    btlTransitionStepSlide(task, transition, work, pos[0] - 86.0f, pos[1] - 86.0f, spBackground, (u8 *)&info);
                }
                if (info.alpha > 0) {
                    spColor |= info.alpha;
                    btlSelectionDrawValue((u8 *)panel, rowX, shift + (base + info.offset),
                                  spAmount, numeralMode, spColor);
                }
            }
        }
    }
}

#pragma push
#pragma opt_loop_invariants on
// Intent: fill the decaying trail alpha table for a damage popup. [inferred]
/* b210: remaining trail flags, wrap-counter and alpha accesses individually differ when typed. */
// FUN_002112C0
static void btlDamageBuildTrail(u8 *state, u8 *output)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ((BtlDamageTrail *)output)->alpha[i] = 0;
    }
    if (((BtlDamageState *)state)->trailFlags & 1) {
        s32 frame;
        s32 cursor;
        f32 weight;
        u16 phase;

        frame = ((BtlDamageState *)state)->trailFrame;
        cursor = frame;
        weight = 1.0f;
        while (cursor >= 0) {
            if (cursor < 9) {
                ((BtlDamageTrail *)output)->alpha[cursor] = (u16)(255.0f * weight);
            }
            cursor--;
            weight *= 0.75f;
        }
        if (!(MEMBER(u16, state, BtlDamageState, trailFlags) & 2) && frame > 4) {
            phase = frame;
            if (frame >= 8) {
                phase = 0;
            }
            if (phase % 2 == 0 && phase / 2 == 0) {
                MEMBER(u16, state, BtlDamageState, trailFlags) |= 2;
            }
        }
        if (frame >= 18) {
            ((BtlDamageState *)state)->trailFlags &= 0xFFFE;
            ((BtlDamageState *)state)->trailFlags |= 2;
        }
        ((BtlDamageTrail *)output)->count = 9;
    } else {
        ((BtlDamageTrail *)output)->count = 4;
    }
    if (MEMBER(u16, state, BtlDamageState, trailFlags) & 4) {
        s32 frame;
        f32 alpha;

        frame = ((BtlDamageState *)state)->trailFrame;
        if (frame < 0) {
            alpha = 0.0f;
        } else if (frame < 3) {
            alpha = (f32)frame / 3.0f;
        } else {
            alpha = 1.0f;
        }
        ((BtlDamageTrail *)output)->scale = alpha;
        if (frame > 3) {
            MEMBER(u16, state, BtlDamageState, trailFlags) &= 0xFFFB;
        }
    } else {
        ((BtlDamageTrail *)output)->scale = 1.0f;
    }
    if (MEMBER(u16, state, BtlDamageState, trailFlags) & 2) {
        s32 frame;
        s32 trail;
        u16 phase;

        frame = ((BtlDamageState *)state)->trailFrame;
        phase = frame % 8;
        if (phase % 2 == 0) {
            state[0x18 + phase / 2] = 255;
        }
        for (trail = 0; trail < 4; trail++) {
            u16 sum;
            f32 decay;

            decay = (f32)state[0x18 + trail];
            decay *= 0.75f;
            state[0x18 + trail] = (u8)decay;
            sum = ((BtlDamageTrail *)output)->alpha[trail] + state[0x18 + trail];
            if (sum > 255) {
                sum = 255;
            }
            ((BtlDamageTrail *)output)->alpha[trail] = sum;
        }
    }
    if (++((BtlDamageState *)state)->trailFrame >= 144) {
        MEMBER(u16, state, BtlDamageState, trailFrame) = 0;
    }
}
#pragma pop

union ColorWord {
    s32 word;
    f32 value;
    u8 bytes[4];
};

// Intent: draw the damage popup's gauge bar segments from the trail table. [inferred]
// FUN_00211650
void btlDamageDrawGaugeBar(u8 *drawContext, u8 *trail)
{
    extern BtlShuffleRenderStateSet D_00887300[];
    extern void btlUiSetRenderMode(s32 mode);
    extern s32 btlAdvantageGetRaster(void);
    extern void btlPanelDrawQuad(f32, f32, f32, f32,
                              f32, f32, f32, f32,
                              f32, union ColorWord drawContext);
    extern f32 fGpffff84a0;
    union ColorWord frame;
    f32 scale;
    f32 barHeight;
    f32 barY;
    s32 segmentCount;
    s32 segmentIndex;

    D_00887300[0](rwRENDERSTATETEXTURERASTER, (void *)btlAdvantageGetRaster());
    btlUiSetRenderMode(2);
    frame.bytes[0] = 0x52;
    frame.bytes[1] = 0xF3;
    frame.bytes[2] = 0;
    segmentCount = ((BtlDamageTrail *)trail)->count;
    for (segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++) {
        frame.bytes[3] = (s8)((BtlDamageTrail *)trail)->alpha[segmentIndex];
        btlPanelDrawQuad(21.0f + (f32)(segmentIndex * 0x14),
                      386.0f, 0.0f, 22.0f, 22.0f,
                      114.0f, 197.0f, 136.0f, 219.0f, frame);
    }
    scale = ((BtlDamageTrail *)trail)->scale;
    if (!(scale <= 0.0f)) {
        frame.bytes[0] = 0x52;
        frame.bytes[1] = 0xF3;
        frame.bytes[2] = 0;
        frame.bytes[3] = 0xFF;
        barHeight = 21.0f * scale;
        barY = ws14_mul(scale, -10.5f);
        barY = ws14_add(fGpffff84a0, barY);
        btlPanelDrawQuad(14.0f, barY, 0.0f, 12.0f, barHeight,
                      37.0f, 218.0f, 49.0f, 239.0f, frame);
        btlPanelDrawQuad(26.0f, barY, 0.0f, 112.0f, barHeight,
                      49.0f, 218.0f, 49.0f, 239.0f, frame);
        btlPanelDrawQuad(138.0f, barY, 0.0f, 12.0f, barHeight,
                      49.0f, 218.0f, 37.0f, 239.0f, frame);
        btlUiSetRenderMode(0);
        frame.bytes[0] = 0xD;
        frame.bytes[1] = 0x1B;
        frame.bytes[2] = 0;
        frame.bytes[3] = 0xFF;
        btlPanelDrawQuad(24.0f, fGpffff84a0 + ws14_mul(scale, -9.5f),
                      0.0f, 116.0f, 19.0f * scale, 136.0f,
                      235.0f, 252.0f, 254.0f, frame);
        return;
    }
    btlUiSetRenderMode(0);
}

// Intent: initialise a list entry node with its owner and a reference count of one. [inferred]
// FUN_00211950
void btlEntryInit(u8 *entry, s32 owner) {
    memset(entry, 0, 0x20);
    ((BtlEntryRecord *)entry)->owner = owner;
    ((BtlEntryRecord *)entry)->references = 1;
}

// Intent: release every entry in a list and clear its head. [inferred]
// FUN_002119A0
void btlEntryListFlush(u8 **head) {
    u8 *entry = *head;
    u8 *next;

    while (entry != NULL) {
        next = ((BtlDamageEntry *)entry)->next;
        ((BtlUnit *)((BtlDamageEntry *)entry)->unit)->pendingPacketCount -= 1;
        jtbl_008873EC[0](entry);
        entry = next;
    }
    *head = NULL;
}

// Intent: remove finished entries from a list and advance the age of the rest. [inferred]
// FUN_00211A10
void btlEntryListPrune(u8 **head)
{
    u8 *entry;
    u8 *previous;
    u8 *next;
    u8 *unit;

    entry = *head;
    previous = entry;
    while (entry != NULL) {
        ((BtlDamageEntry *)entry)->age = ((BtlDamageEntry *)entry)->age + 1;
        if ((((BtlDamageEntry *)entry)->flags & 1) == 0) {
            next = ((BtlDamageEntry *)entry)->next;
            if (*head == entry) {
                *head = next;
            } else {
                ((BtlDamageEntry *)previous)->next = next;
            }
            unit = ((BtlDamageEntry *)entry)->unit;
            ((BtlUnit *)unit)->pendingPacketCount = ((BtlUnit *)unit)->pendingPacketCount - 1;
            jtbl_008873EC[0](entry);
            entry = next;
        } else {
            previous = entry;
            entry = ((BtlDamageEntry *)entry)->next;
        }
    }
}

// Intent: draw each active damage popup and its timed follow-up. [inferred]
/* b210: typing the final flash-flag clear changes instructions; other state fields remain typed. */
// FUN_00211AD0
void btlDamageDrawList(u8 *drawContext, u8 *state)
{
    s32 *hud;
    u16 flags;
    u8 *entry;

    hud = (s32 *)kwlnTaskGetWork(((BtlDamageState *)state)->task);
    if ((*hud & 1) != 0) {
        btlUiSetRenderStates();
        entry = ((BtlDamageState *)state)->head;
        while (entry != NULL) {
            btlDamageDrawPanel(state, entry);
            entry = ((BtlDamageEntry *)entry)->next;
        }
        flags = ((BtlDamageState *)state)->flags;
        if ((flags & 8) != 0) {
            if (((BtlDamageState *)state)->flashFrame < 0x3C) {
                btlTransitionDrawFrame((u8 *)hud, state);
                return;
            }
            MEMBER(u16, state, BtlDamageState, flags) = flags & 0xFFF7;
        }
    }
}

/* Measured: 1000/1008 bytes, eighteen resolved relocations and eight zero
 * alignment bytes. Projection writes three world and two screen floats;
 * the fade consumer reads the initialized twelve-byte typed packet. */
// Intent: draw the pulsing bad-status ring over party units while the popup is active. [inferred]
/* b210: remaining task, fade-counter and flag accesses individually change instructions when typed. */
// FUN_00211BA0
void btlDamageDrawBadStatus(u8 *drawContext, u8 *state)
{
    extern void btlUnitGetStatusMarkerPoint(u8 *unit, f32 *outPosition);
    extern s32 btlTargetFindInRange(f32 *position, f32 *output);
    extern void btlUiSetOrigin(u8 *drawContext, f32, f32);
    extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
    extern f32 btlSelectionEaseCurve(s32 drawContext, s32 state, s32, s32);
    extern void btlPanelDrawGauge(u8 *work, u8 *state);
    extern f32 fGpffff81e0;
    f32 world[3];
    f32 screen[2];
    struct {
        u8 alpha;
        s16 step;
        u16 flags;
        f32 scale;
    } fade;
    u8 *context;
    s16 frame;
    u16 flags;
    u8 *unit;
    s32 group;
    f32 pulse;
    u8 *draw;

    context = (u8 *)kwlnTaskGetWork(((BtlDamageState *)state)->task);
    if (*(u32 *)context & 1) {
        if (((BtlDamageState *)state)->flags & 1) {
            btlUiSetRenderStates();
            for (group = 0; group < 2; group++) {
                for (unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[group * 2];
                     unit != NULL; unit = (u8 *)((BtlUnit *)unit)->nextUnit) {
                    if (!(((BtlUnit *)unit)->flags3 & 8)) {
                        continue;
                    }
                    if (!datCalcChkBadStatus((s32)((BtlUnit *)unit)->datUnit, 0x100000)) {
                        continue;
                    }
                    btlUnitGetStatusMarkerPoint(unit, world);
                    if (!btlTargetFindInRange(world, screen)) {
                        continue;
                    }
                    btlUiSetOrigin(context, screen[0] - 86.0f, screen[1] - 86.0f);
                    draw = (u8 *)kwlnTaskGetWork(MEMBER(void *, state, BtlDamageState, task));
                    /* Status pulse counter (+0xA44) is outside the shared BtlUnit's named tail. */
                    if (++((BtlUnit *)(unit))->statusPulseFrame >= 25) {
                        MEMBER(u16, unit, BtlUnit, statusPulseFrame) = 0;
                    }
                    pulse = sinf((fGpffff81e0 * (f32)(s32)MEMBER(u16, unit, BtlUnit, statusPulseFrame)) / 25.0f);
                    btlUiDrawSpriteFaded(draw, 10, 17, 64.0f, (0.0f + 45.0f) + 10.0f * pulse,
                                   12, 79, 85, 255);
                    btlUiDrawSpriteFaded(draw, 10, 17, 64.0f, (0.0f + 37.0f) + 5.0f * pulse,
                                   63, 255, 245, 255);
                    btlUiDrawSpriteFaded(draw, 10, 8, 55.0f, 44.0f, 63, 255, 245, 255);
                    btlUiDrawSpriteFaded(draw, 10, 7, 55.0f, 44.0f, 12, 79, 85, 255);
                }
            }
        }
        flags = MEMBER(u16, state, BtlDamageState, flags);
        if (flags & 2) {
            if (((BtlDamageState *)state)->fadeFrame < 30) {
                frame = ((BtlDamageState *)state)->fadeFrame;
                fade.flags = flags;
                {
                    f32 opacity = btlSelectionEaseCurve(frame, 0, 5, 0);
                    fade.alpha = (u8)(255.0f * (1.0f - opacity));
                }
                fade.step = (s16)(s32)(12.0f * btlSelectionEaseCurve(frame, 1, 12, 0));
                fade.scale = 1.0f - btlSelectionEaseCurve(frame, 20, 30, 0);
                MEMBER(u16, state, BtlDamageState, fadeFrame) += 1;
                btlPanelDrawGauge(context, (u8 *)&fade);
            } else {
                MEMBER(u16, state, BtlDamageState, flags) = flags & 0xFFFD;
            }
        }
    }
}

// Intent: draw the damage popup bars when its flag and value are set. [inferred]
// FUN_00211F90
void btlDamageDrawBars(s32 drawContext, u8 *state) {
    u8 trail[0x20];
    u8 *hud = (u8 *)kwlnTaskGetWork(((BtlDamageState *)state)->task);

    btlUiSetRenderStates();
    if ((((BtlDamageState *)state)->flags & 0x10) == 0) {
        return;
    }
    if (((BtlDamageState *)state)->source == 0) {
        return;
    }
    btlDamageBuildTrail(state, trail);
    btlDamageDrawGaugeBar(hud, trail);
}

// Intent: set the active bit of the damage popup. [inferred]
// FUN_00212010
void btlDamageSetActive(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->damage.flags = ((BtlHudWork *)hud)->damage.flags | 1;
}

// Intent: clear the active bit of the damage popup. [inferred]
// FUN_00212040
void btlDamageClearActive(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->damage.flags = ((BtlHudWork *)hud)->damage.flags & 0xFFFE;
}

// Intent: start a damage popup, playing its cue and setting its flags from the target. [inferred]
/* b210: typing the final damage-start flag store changes instructions; the other fields are typed. */
// FUN_00212070
void btlDamageStart(u8 *task, u8 *action)
{
    u8 *hud;
    u8 *state;

    hud = (u8 *)kwlnTaskGetWork(task);
    state = hud + 0x75C;
    ((BtlHudWork *)hud)->damage.fadeFrame = 0;
    if (((BtlAction *)action)->unit->genus == 0) {
        ((BtlDamageState *)state)->flags |= 4;
    } else {
        ((BtlDamageState *)state)->flags &= 0xFFFB;
    }
    sdkSndStartStream(1, 0xF, 2, 0xD);
    MEMBER(u16, state, BtlDamageState, flags) |= 2;
}

// Intent: start the damage flash when the popup is idle. [inferred]
// FUN_00212100
void btlDamageStartFlash(s32 task) {
    u8 *state;

    state = (u8 *)kwlnTaskGetWork((void *)task) + 0x75C;
    if (btlDamageIsIdle(task) != 0) {
        sdkSndStartStream(1, 0xE, 2, 2);
        ((BtlDamageState *)state)->flashFrame = 0;
        ((BtlDamageState *)state)->flags |= 8;
    }
}

// Intent: report whether the damage popup is not flashing. [inferred]
// FUN_00212180
s32 btlDamageIsIdle(s32 task)
{
    s32 flag;

    flag = (((BtlHudWork *)kwlnTaskGetWork((void *)task))->damage.flags & 8) != 0;
    return flag ^ 1;
}

// Intent: reset the damage popup phase counters and start its display phase. [inferred]
// FUN_002121B0
void btlDamageBeginPhase(s32 task)
{
    u8 *hud;
    u8 *state;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    state = hud + 0x75C;
    ((BtlHudWork *)hud)->damage.trailFrame = 0;
    ((BtlHudWork *)hud)->damage.trailFlags = 5;
    memset(state + 0x18, 0, 4);
    ((BtlDamageState *)state)->flags = ((BtlDamageState *)state)->flags | 0x10;
}

// Intent: end the damage popup display phase and clear its active bit. [inferred]
// FUN_00212210
void btlDamageEndPhase(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->damage.trailFlags = 0;
    ((BtlHudWork *)hud)->damage.flags = ((BtlHudWork *)hud)->damage.flags & 0xFFEF;
}

// Intent: store the damage popup's source value. [inferred]
// FUN_00212240
void btlDamageSetSource(u8 *task, s32 source) {
    ((BtlHudWork *)kwlnTaskGetWork(task))->damage.source = source;
}

/* Encounter-transition geometry uses the actual sky-vertex, UV and matrix
 * layouts. Each direction owns its frame ratio; vertex opacity is narrowed
 * independently. See docs/probe_archive/Battle_transition_00212270_20260922.md. */
static inline f32 btlTransitionExitCurve(f32 coefficient, f32 fraction)
{
    f32 eased = coefficient * fraction - fraction * fraction;
    return 1.0f + eased;
}

// Intent: draw the encounter transition sky, bars and panel for its current frame. [inferred]
/* b210: remaining rotation-counter and sprite-handle reloads individually differ when typed. */
// FUN_00212270
void btlEncounterDrawTransition(u8 *drawPayload, s32 workAddress, void *callback)
{
    extern BtlShuffleRenderPrimitive D_00887310[];
    extern BtlShuffleVec3 D_0060A0E0[];
    extern BtlShuffleVec3 D_0060A0F0[];
    extern f32 fGpffff8370;
    extern f32 fGpffff8374;
    extern void btlUiSetRenderMode(s32 mode);
    extern s32 kwlnGetCamera(void);
    extern BtlShuffleMatrix *RwMatrixRotate(BtlShuffleMatrix *matrix,
        const BtlShuffleVec3 *axis, f32 angle, BtlShuffleCombine combine);
    extern void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
        u8 red, u8 green, u8 blue, u8 alpha);
    extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth,
        u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY,
        f32 angle, s16 pivotX, s16 pivotY);
    extern s32 sflDataDrawTexturedQuad(s32 x, s32 y, f32 z, s32 width, s32 height,
        s32 rgb, s32 alpha, s32 mode, s16 centerX, s16 centerY,
        BtlShuffleMatrix *matrix, s32 texture, f32 (*uv)[2]);
    extern s32 sdkSpriteSlotHandle(u8 *pack, s32 recordIndex);
    /* Four render objects and the position reproduce the retail 0x3A0 frame. */
    Vec2f drawPosition;
    BtlShuffleSkyVertex bars[4];
    BtlShuffleMatrix matrix;
    f32 uv[4][2];
    BtlShuffleSkyVertex fan[6];
    u8 *work;
    u8 *camera;
    s32 animationFrame;
    s32 entering;
    u8 alpha;
    u32 packedColor;
    f32 barReciprocalZ;
    f32 angle;
    f32 easeCoefficient;
    f32 fanDepth;
    f32 slideOffset;
    f32 eased;
    f32 barOpacity;
    f32 fanReciprocalZ;
    u8 *renderTable;
    u32 red;
    u32 green;
    u32 blue;
    u32 opacity;

    (void)drawPayload;
    (void)callback;
    work = (u8 *)(u32)workAddress;
    camera = (u8 *)(u32)kwlnGetCamera();
    /* Camera projection uses the canonical RenderWare near-plane field. */
    barReciprocalZ = 1.0f / ((RwCamera *)(camera))->nearPlane;
    animationFrame = ((BtlEncounterWork *)work)->animationFrame;
    if (animationFrame == 0) {
        return;
    }
    if (animationFrame < 0x25) {
        entering = 1;
    } else {
        entering = 0;
        animationFrame -= 0x24;
    }
    btlUiSetRenderStates();
    btlUiSetRenderMode(2);
    {
        if (entering) {
            f32 ratio;
            if (animationFrame < 6) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)(animationFrame - 5);
                if (21.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 21.0f;
                }
            }
            easeCoefficient = 2.0f;
            eased = easeCoefficient * ratio - ratio * ratio;
        } else {
            f32 ratio;
            if (animationFrame <= 0) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)animationFrame;
                if (14.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 14.0f;
                }
            }
            ratio = 1.0f - ratio;
            easeCoefficient = 2.0f;
            eased = easeCoefficient * ratio - ratio * ratio;
        }
    }
    alpha = (u8)(204.0f * eased);
    packedColor = 0xFF7B0000 | alpha;
    red = ((u32)packedColor >> 24) & 0xFF;
    green = ((u32)packedColor >> 16) & 0xFF;
    blue = ((u32)packedColor >> 8) & 0xFF;
    opacity = (u32)packedColor & 0xFF;
    fanDepth = D_008872F8[0];
    camera = (u8 *)(u32)kwlnGetCamera();
    fanReciprocalZ = 1.0f / ((RwCamera *)(camera))->nearPlane;
    fan[0].u.els.scrVertex.x = 640.0f;
    fan[0].u.els.scrVertex.y = 0.0f;
    fan[0].u.els.scrVertex.z = fanDepth;
    fan[0].u.els.recipZ = fanReciprocalZ;
    fan[0].u.els.color.r = (f32)red;
    fan[0].u.els.color.g = (f32)green;
    fan[0].u.els.color.b = (f32)blue;
    fan[0].u.els.color.a = (f32)opacity;
    fan[1].u.els.scrVertex.x = 221.0f;
    fan[1].u.els.scrVertex.y = 0.0f;
    fan[1].u.els.scrVertex.z = fanDepth;
    fan[1].u.els.recipZ = fanReciprocalZ;
    fan[1].u.els.color.r = (f32)red;
    fan[1].u.els.color.g = (f32)green;
    fan[1].u.els.color.b = (f32)blue;
    fan[1].u.els.color.a = 0.0f;
    fan[2].u.els.scrVertex.x = 640.0f;
    fan[2].u.els.scrVertex.y = 418.0f;
    fan[2].u.els.scrVertex.z = fanDepth;
    fan[2].u.els.recipZ = fanReciprocalZ;
    fan[2].u.els.color.r = (f32)red;
    fan[2].u.els.color.g = (f32)green;
    fan[2].u.els.color.b = (f32)blue;
    fan[2].u.els.color.a = 0.0f;
    fan[3].u.els.scrVertex.x = 0.0f;
    fan[3].u.els.scrVertex.y = 448.0f;
    fan[3].u.els.scrVertex.z = fanDepth;
    fan[3].u.els.recipZ = fanReciprocalZ;
    fan[3].u.els.color.r = (f32)red;
    fan[3].u.els.color.g = (f32)green;
    fan[3].u.els.color.b = (f32)blue;
    fan[3].u.els.color.a = (f32)opacity;
    fan[4].u.els.scrVertex.x = 418.0f;
    fan[4].u.els.scrVertex.y = 448.0f;
    fan[4].u.els.scrVertex.z = fanDepth;
    fan[4].u.els.recipZ = fanReciprocalZ;
    fan[4].u.els.color.r = (f32)red;
    fan[4].u.els.color.g = (f32)green;
    fan[4].u.els.color.b = (f32)blue;
    fan[4].u.els.color.a = 0.0f;
    fan[5].u.els.scrVertex.x = 0.0f;
    fan[5].u.els.scrVertex.y = 29.0f;
    fan[5].u.els.scrVertex.z = fanDepth;
    fan[5].u.els.recipZ = fanReciprocalZ;
    fan[5].u.els.color.r = (f32)red;
    fan[5].u.els.color.g = (f32)green;
    fan[5].u.els.color.b = (f32)blue;
    fan[5].u.els.color.a = 0.0f;
    renderTable = (u8 *)D_00887310;
    (*(BtlShuffleRenderPrimitive *)renderTable)(rwPRIMTYPETRILIST, fan, 6);
    if (entering) {
        alpha = 0xFF;
        ((BtlEncounterWork *)work)->rotationFrame += 1;
        if (((BtlEncounterWork *)work)->rotationFrame == 0x15) {
            MEMBER(s32, work, BtlEncounterWork, rotationFrame) = 0;
        }
        angle = 90.0f - (360.0f * (f32)MEMBER(s32, work, BtlEncounterWork, rotationFrame)) / 21.0f;
    } else if (((BtlEncounterWork *)work)->rotationFrame < 0xC) {
        f32 ratio;
        MEMBER(s32, work, BtlEncounterWork, rotationFrame) += 1;
        ratio = (f32)MEMBER(s32, work, BtlEncounterWork, rotationFrame) / 12.0f;
        eased = easeCoefficient * ratio - ratio * ratio;
        angle = 90.0f - 180.0f * eased;
        alpha = 0xFF;
    } else {
        alpha = 0;
    }
    if (alpha > 0) {
        RwMatrixRotate(&matrix, D_0060A0F0, fGpffff8370, rwCOMBINEREPLACE);
        RwMatrixRotate(&matrix, D_0060A0E0, angle, rwCOMBINEPOSTCONCAT);
        uv[0][0] = 0.6171875f;
        uv[0][1] = 0.4375f;
        uv[1][0] = 0.6171875f;
        uv[1][1] = 0.921875f;
        uv[2][0] = 0.00390625f;
        uv[2][1] = 0.4375f;
        uv[3][0] = 0.00390625f;
        uv[3][1] = 0.921875f;
        sflDataDrawTexturedQuad(0x13F, 0xE0, 0.0f, 0x78, 0x98, 0xFFFF761E, alpha,
            0, 0x3C, 0x4C, &matrix,
            sdkSpriteSlotHandle((u8 *)((BtlEncounterWork *)work)->sprite, 2),
            uv);
    }
    btlUiSetRenderMode(0);
    {
        if (entering) {
            f32 ratio;
            if (animationFrame < 0xB) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)(animationFrame - 0xA);
                if (13.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 13.0f;
                }
            }
            ratio = 1.0f - ratio;
            eased = easeCoefficient * ratio - ratio * ratio;
            slideOffset = 300.0f * eased;
        } else {
            f32 ratio;
            if (animationFrame <= 0) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)animationFrame;
                if (14.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 14.0f;
                }
            }
            eased = easeCoefficient * ratio - ratio * ratio;
            slideOffset = -600.0f * eased;
        }
    }
    drawPosition.x = (f32)563 - slideOffset;
    drawPosition.y = 224.0f - slideOffset;
    shdDrawWedge(drawPosition, 0.0f, 0xFF,
        fGpffff8374, 0, 1);
    drawPosition.x = 76.0f + slideOffset;
    drawPosition.y = 224.0f + slideOffset;
    shdDrawWedge(drawPosition, 0.0f, 0xFF,
        fGpffff8378, 0, 1);
    btlUiSetRenderMode(2);
    {
        if (entering) {
            f32 ratio;
            if (animationFrame < 0xD) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)(animationFrame - 0xC);
                if (14.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 14.0f;
                }
            }
            eased = easeCoefficient * ratio - ratio * ratio;
            eased = 1.0f - eased;
            slideOffset = 300.0f * eased;
        } else {
            f32 ratio;
            if (animationFrame <= 0) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)animationFrame;
                if (14.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 14.0f;
                }
            }
            eased = btlTransitionExitCurve(easeCoefficient, ratio);
            slideOffset = -300.0f * eased;
        }
    }
    drawPosition.x = 182.0f - slideOffset;
    drawPosition.y = (f32)331 - slideOffset;
    shdDrawWedge(drawPosition, 0.0f, 0xFF6400FF,
        fGpffff8374, 0, 0);
    drawPosition.x = (f32)457 + slideOffset;
    drawPosition.y = 117.0f + slideOffset;
    shdDrawWedge(drawPosition, 0.0f, 0xFF6400FF,
        fGpffff8378, 0, 0);
    {
        if (entering) {
            f32 ratio;
            if (animationFrame < 0xB) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)(animationFrame - 0xA);
                if (15.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 15.0f;
                }
            }
            eased = easeCoefficient * ratio - ratio * ratio;
        } else {
            f32 ratio;
            if (animationFrame <= 0) {
                ratio = 0.0f;
            } else {
                f32 frame = (f32)animationFrame;
                if (8.0f <= frame) {
                    ratio = 1.0f;
                } else {
                    ratio = frame / 8.0f;
                }
            }
            eased = easeCoefficient * (1.0f - ratio) - (1.0f - ratio) * (1.0f - ratio);
        }
    }
    bars[0].u.els.scrVertex.x = 0.0f;
    bars[0].u.els.scrVertex.y = 92.0f;
    bars[0].u.els.scrVertex.z = 0.0f;
    bars[0].u.els.recipZ = barReciprocalZ;
    bars[0].u.els.color.r = 255.0f;
    bars[0].u.els.color.g = 100.0f;
    bars[0].u.els.color.b = 0.0f;
    bars[0].u.els.color.a = 0.0f;
    bars[1].u.els.scrVertex.x = 640.0f;
    bars[1].u.els.scrVertex.y = 92.0f;
    bars[1].u.els.scrVertex.z = 0.0f;
    bars[1].u.els.recipZ = barReciprocalZ;
    bars[1].u.els.color.r = 255.0f;
    bars[1].u.els.color.g = 100.0f;
    bars[1].u.els.color.b = 0.0f;
    bars[1].u.els.color.a = 0.0f;
    bars[2].u.els.scrVertex.x = 0.0f;
    bars[2].u.els.scrVertex.y = 224.0f;
    bars[2].u.els.scrVertex.z = 0.0f;
    bars[2].u.els.recipZ = barReciprocalZ;
    bars[2].u.els.color.r = 255.0f;
    bars[2].u.els.color.g = 100.0f;
    bars[2].u.els.color.b = 0.0f;
    /* Keep the floating opacity; each vertex applies the unsigned byte conversion. */
    barOpacity = 204.0f * eased;
    bars[2].u.els.color.a = (f32)(u8)barOpacity;
    bars[3].u.els.scrVertex.x = 640.0f;
    bars[3].u.els.scrVertex.y = 224.0f;
    bars[3].u.els.scrVertex.z = 0.0f;
    bars[3].u.els.recipZ = barReciprocalZ;
    bars[3].u.els.color.r = 255.0f;
    bars[3].u.els.color.g = 100.0f;
    bars[3].u.els.color.b = 0.0f;
    bars[3].u.els.color.a = (f32)(u8)barOpacity;
    renderTable = (u8 *)D_00887310;
    (*(BtlShuffleRenderPrimitive *)renderTable)(rwPRIMTYPETRISTRIP, bars, 4);
    bars[0].u.els.scrVertex.x = 0.0f;
    bars[0].u.els.scrVertex.y = 224.0f;
    bars[0].u.els.scrVertex.z = 0.0f;
    bars[0].u.els.recipZ = barReciprocalZ;
    bars[0].u.els.color.r = 255.0f;
    bars[0].u.els.color.g = 100.0f;
    bars[0].u.els.color.b = 0.0f;
    bars[0].u.els.color.a = (f32)(u8)barOpacity;
    bars[1].u.els.scrVertex.x = 640.0f;
    bars[1].u.els.scrVertex.y = 224.0f;
    bars[1].u.els.scrVertex.z = 0.0f;
    bars[1].u.els.recipZ = barReciprocalZ;
    bars[1].u.els.color.r = 255.0f;
    bars[1].u.els.color.g = 100.0f;
    bars[1].u.els.color.b = 0.0f;
    bars[1].u.els.color.a = (f32)(u8)barOpacity;
    bars[2].u.els.scrVertex.x = 0.0f;
    bars[2].u.els.scrVertex.y = 356.0f;
    bars[2].u.els.scrVertex.z = 0.0f;
    bars[2].u.els.recipZ = barReciprocalZ;
    bars[2].u.els.color.r = 255.0f;
    bars[2].u.els.color.g = 100.0f;
    bars[2].u.els.color.b = 0.0f;
    bars[2].u.els.color.a = 0.0f;
    bars[3].u.els.scrVertex.x = 640.0f;
    bars[3].u.els.scrVertex.y = 356.0f;
    bars[3].u.els.scrVertex.z = 0.0f;
    bars[3].u.els.recipZ = barReciprocalZ;
    bars[3].u.els.color.r = 255.0f;
    bars[3].u.els.color.g = 100.0f;
    bars[3].u.els.color.b = 0.0f;
    bars[3].u.els.color.a = 0.0f;
    (*(BtlShuffleRenderPrimitive *)renderTable)(rwPRIMTYPETRISTRIP, bars, 4);
    btlUiSetRenderMode(0);
    if (entering) {
        f32 ratio;
        u8 labelAlpha;
        if (animationFrame < 0xF) {
            ratio = 0.0f;
        } else {
            f32 frame = (f32)(animationFrame - 0xE);
            if (8.0f <= frame) {
                ratio = 1.0f;
            } else {
                ratio = frame / 8.0f;
            }
        }
        ratio = 1.0f - ratio;
        eased = easeCoefficient * ratio - ratio * ratio;
        labelAlpha = (u8)(255.0f * (1.0f - eased));
        slideOffset = 400.0f * (1.0f - (1.0f - eased));
        sdkSpriteDrawOnceAt(((BtlEncounterWork *)work)->sprite, 0, 165.0f + slideOffset, 170.0f,
            0, 0, 0, labelAlpha);
        sdkSpriteDrawOnceAt(MEMBER(s32, work, BtlEncounterWork, sprite), 1, (f32)313 - slideOffset, 224.0f,
            0, 0, 0, labelAlpha);
        return;
    }
    {
        f32 labelScale;
        f32 labelProgress;
        f32 ratio;
        if (animationFrame <= 0) {
            ratio = 0.0f;
        } else {
            f32 frame = (f32)animationFrame;
            if (8.0f <= frame) {
                ratio = 1.0f;
            } else {
                ratio = frame / 8.0f;
            }
        }
        ratio = 1.0f - ratio;
        labelScale = 4096.0f * ratio;
        labelProgress = 1.0f - ratio;
        sdkSpriteDrawOnceScaled(((BtlEncounterWork *)work)->sprite, 0, 165.0f,
            170.0f + 28.0f * labelProgress, 0.0f, 0, 0, 0,
            0xFF, 0x1000, (u16)labelScale, 0.0f, 0, 0);
        sdkSpriteDrawOnceScaled(MEMBER(s32, work, BtlEncounterWork, sprite), 1, (f32)313,
            224.0f + 26.5f * labelProgress, 0.0f, 0, 0, 0,
            0xFF, 0x1000, (u16)labelScale, 0.0f, 0, 0);
    }
}

// Intent: advance the encounter task state machine and return -1 when it finishes. [inferred]
/* b210: typing the intro-frame store changes instructions; other encounter fields remain typed. */
// FUN_002136F0
s32 btlEncounterUpdateTask(u8 *sdkTaskBytes)
{
    s32 task = (s32)sdkTaskBytes;
    s16 state;
    u8 *work;
    s32 introFrame;
    s32 exitFrame;

    work = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlRenderNode *)(work + 8))->unk00 = 0;
    ((BtlRenderNode *)(work + 8))->unk04 = 0;
    PrimAppendNode(&D_00796340, work + 8);
    state = ((BtlEncounterWork *)work)->state;
    switch (state) {
    case 0:
        break;
    case 1:
        if (hMaestroDecodeIsReady(((BtlEncounterWork *)work)->sprite) != 0) {
            ((BtlEncounterWork *)work)->state = 2;
        }
        break;
    case 2:
        if (((BtlEncounterWork *)work)->ready != 0) {
            sdkSndStartStream(1, 0, 5, 0);
            ((BtlEncounterWork *)work)->state = 3;
        case 3:
            introFrame = ((BtlEncounterWork *)work)->animationFrame;
            if (introFrame < 0x24) {
                MEMBER(s32, work, BtlEncounterWork, animationFrame) = introFrame + 1;
            } else if ((((BtlEncounterWork *)work)->finish == 1) &&
                       (((BtlEncounterWork *)work)->rotationFrame == 0)) {
                ((BtlEncounterWork *)work)->state = 4;
            }
        }
        break;
    case 4:
        exitFrame = ((BtlEncounterWork *)work)->animationFrame;
        ((BtlEncounterWork *)work)->animationFrame = exitFrame + 1;
        if (exitFrame >= 0x34) {
            ((BtlEncounterWork *)work)->state = 5;
        }
        break;
    case 5:
        return -1;
    default:
        break;
    }
    return 0;
}

// Intent: release an encounter task and its sprite. [inferred]
// FUN_00213840
void btlEncounterDestroyTask(u8 *task) {
    u8 *work;
    s32 sprite;

    work = (u8 *)kwlnTaskGetWork(task);
    sprite = ((BtlEncounterWork *)work)->sprite;
    if (sprite != 0) {
        sdkSpriteRelease((void *)sprite);
    }
    jtbl_008873EC[0](work);
}

// Intent: create an encounter task and its transition state. [inferred]
// FUN_002138A0
void btlEncounterStart(s32 parent)
{
    BtlEncounterWork *work;
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)parent);
    chkmemAllocSiteTag(&D_00626C30, 0x3A);
    work = (BtlEncounterWork *)jtbl_008873E8[0](0x48, 0x40000);
    memset(work, 0, 0x48);
    ((BtlEncounterWork *)work)->sprite = sdkSpriteRequestLoad(&D_00626CA0);
    ((BtlEncounterWork *)work)->state = 1;
    ((BtlRenderNode *)((u8 *)work + 8))->callback = (void *)btlEncounterDrawTransition;
    ((BtlRenderNode *)((u8 *)work + 8))->work = work;
    ((BtlHudWork *)hud)->encounterTask =
        (void *)kwlnTaskCreateChild((void *)(parent), (const void *)(&D_00626C80), 0xF, 0, 0, btlEncounterUpdateTask, btlEncounterDestroyTask, (u8 *)(work));
}

// Intent: mark the encounter task as ready to proceed. [inferred]
// FUN_00213990
void btlEncounterSetReady(s32 task)
{
    u8 *work;
    s32 value;

    work = (u8 *)kwlnTaskGetWork(((BtlHudWork *)kwlnTaskGetWork((void *)task))->encounterTask);
    value = 1;
    ((BtlEncounterWork *)work)->ready = value;
}

// Intent: report whether the encounter intro has finished. [inferred]
// FUN_002139D0
s32 btlEncounterIsIntroDone(s32 task)
{
    return ((BtlEncounterWork *)kwlnTaskGetWork(((BtlHudWork *)kwlnTaskGetWork((void *)task))->encounterTask))->animationFrame >= 0x24;
}

// Intent: mark the encounter task as finishing. [inferred]
// FUN_00213A10
void btlEncounterSetFinish(s32 task)
{
    u8 *work;
    s32 value;

    work = (u8 *)kwlnTaskGetWork(((BtlHudWork *)kwlnTaskGetWork((void *)task))->encounterTask);
    value = 1;
    ((BtlEncounterWork *)work)->finish = value;
}

// Intent: report whether no encounter task is active. [inferred]
// FUN_00213A50
s32 btlEncounterIsInactive(void)
{
    s32 flag;

    flag = btlEncounterIsActive() != 0;
    return flag ^ 1;
}

// Intent: report whether an encounter task exists. [inferred]
// FUN_00213A80
s32 btlEncounterIsActive(void)
{
    return kwlnTaskGetTaskByName(&D_00626C80) != 0;
}

// Intent: initialise encounter parameters with their default values. [inferred]
// FUN_00213AB0
void btlEncounterInitParams(s32 context, u8 *state) {
    memset(state, 0, 0x18);
    ((BtlPortraitState *)state)->pulsePhase = 0.5f;
    ((BtlPortraitState *)state)->angle = 170.0f;
    ((BtlPortraitState *)state)->flashFrame = 10;
    ((BtlPortraitState *)state)->slideFrame = -2;
    ((BtlPortraitState *)state)->emphasisFrame = -2;
}

// Intent: Start a unit panel's 0x18-frame ring effect: set bit 0x1 of its +0xA10 word and reset the frame counter at +0xA18 [inferred]
// FUN_00213B10
void btlPanelStartRingEffect(u8 *unit)
{
    ((BtlPortraitState *)(unit + 0xA10))->flags |= 1;
    ((BtlPortraitState *)(unit + 0xA10))->ringFrame = 0;
}

// Intent: Start a unit panel's 0x18-frame pulse effect: set bit 0x2 of its +0xA10 word and reset the frame counter at +0xA1A [inferred]
// FUN_00213B30
void btlPanelStartPulseEffect(u8 *unit)
{
    ((BtlPortraitState *)(unit + 0xA10))->flags |= 2;
    ((BtlPortraitState *)(unit + 0xA10))->pulseFrame = 0;
}

// Intent: Clear the retract bit (0x1) of an encounter entry, so its slide offset ramps back out [inferred]
// FUN_00213B50
void btlEncounterEntryClearRetracted(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags & ~1;
}

// Intent: Set the retract bit (0x1) of an encounter entry while a target is being selected; its slide offset ramps toward retracted [inferred]
// FUN_00213B80
void btlEncounterEntrySetRetracted(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags | 0x1;
}

// Intent: Clear the message bit (0x4) of an encounter entry, so its message counter stops ramping up [inferred]
// FUN_00213BB0
void btlEncounterEntryClearMessageFade(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags & ~4;
}

// Intent: Set the message bit (0x4) of an encounter entry before its message is set up; its counter ramps up while set [inferred]
// FUN_00213BE0
void btlEncounterEntrySetMessageFade(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags | 0x4;
}

// Intent: Set the emphasis bit (0x2) of an encounter entry; its emphasis ramp rises toward 8 [inferred]
// FUN_00213C10
void btlEncounterEntrySetEmphasis(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags | 0x2;
}

// Intent: Clear the emphasis bit (0x2) of an encounter entry; its emphasis ramp falls back to 0 [inferred]
// FUN_00213C40
void btlEncounterEntryClearEmphasis(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags & ~2;
}

// Intent: Set the active bit (0x100) of an encounter entry's status word (the bit btlEncounterInitEntry also sets) [inferred]
// FUN_00213C70
void btlEncounterEntrySetActive(u8 *view)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork(view);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags | 0x100;
}

// Intent: Clear the active bit (0x100) of an encounter entry's status word [inferred]
// FUN_00213CA0
void btlEncounterEntryClearActive(u8 *view)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork(view);
    ((BtlHudWork *)hud)->encounter.flags = ((BtlHudWork *)hud)->encounter.flags & ~0x100;
}

// Intent: initialise an encounter entry and its status word. [inferred]
// FUN_00213CD0
void btlEncounterInitEntry(u8 *entry, s32 task) {
    memset(entry, 0, 0x10);
    ((BtlEncounterEntry *)entry)->task = task;
    ((BtlEncounterEntry *)entry)->flags |= 0x100;
}

// Intent: advance every encounter entry's timers toward the flag state. [inferred]
/* b210: these counter stores must stay byte-addressed; their reads use the proven typed layout. */
// FUN_00213D20
void btlEncounterUpdateEntries(u8 *state)
{
    u8 *entry;

    entry = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
    while (entry != NULL) {
        if ((((BtlEncounterEntry *)state)->flags & 1) != 0) {
            if (((BtlPortraitState *)(entry + 0xA10))->slideFrame > -2) {
                MEMBER(s16, entry, BtlUnit, portrait.slideFrame) = ((BtlPortraitState *)(entry + 0xA10))->slideFrame - 1;
            }
        } else {
            if (((BtlPortraitState *)(entry + 0xA10))->slideFrame < 0x19) {
                MEMBER(s16, entry, BtlUnit, portrait.slideFrame) = ((BtlPortraitState *)(entry + 0xA10))->slideFrame + 1;
            }
        }
        if ((((BtlEncounterEntry *)state)->flags & 2) == 0) {
            ((BtlPortraitState *)(entry + 0xA10))->emphasisFrame = ((BtlPortraitState *)(entry + 0xA10))->emphasisFrame - 2;
            if (((BtlPortraitState *)(entry + 0xA10))->emphasisFrame < 0) {
                MEMBER(s16, entry, BtlUnit, portrait.emphasisFrame) = 0;
            }
        } else {
            if (((BtlPortraitState *)(entry + 0xA10))->emphasisFrame < 8) {
                MEMBER(s16, entry, BtlUnit, portrait.emphasisFrame) = ((BtlPortraitState *)(entry + 0xA10))->emphasisFrame + 1;
            }
        }
        entry = (u8 *)((BtlUnit *)entry)->prevUnit;
    }
    if ((((BtlEncounterEntry *)state)->flags & 4) != 0) {
        if (((BtlEncounterEntry *)state)->messageFrame < 10) {
            MEMBER(s16, state, BtlEncounterEntry, messageFrame) = ((BtlEncounterEntry *)state)->messageFrame + 1;
        }
    } else {
        if (((BtlEncounterEntry *)state)->messageFrame > 0) {
            MEMBER(s16, state, BtlEncounterEntry, messageFrame) = ((BtlEncounterEntry *)state)->messageFrame - 1;
        }
    }
}

// Intent: build the status icon and colour for a bad-status value. [inferred]
/* b210: typing the default-case status clear changes instructions; all palette colors remain typed. */
// FUN_00213E20
void btlEncounterBuildStatusIcon(u8 *unit, u8 *icon)
{
    extern s32 datCalcGetBadStatusNoDown(s32 unit);
    s32 value;

    value = datCalcGetBadStatusNoDown((s32)((BtlUnit *)unit)->datUnit);
    ((BtlStatusIcon *)icon)->status = value;
    if (value == 0) {
        ((BtlStatusIcon *)icon)->colors[0][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0xAF;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0x20;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xFE;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0x22;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0xAF;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0x20;
        return;
    }
    switch (value) {
    case 2:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x8E;
        ((BtlStatusIcon *)icon)->colors[0][1] = 6;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0x40;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0x7B;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0xB;
        ((BtlStatusIcon *)icon)->colors[2][2] = 1;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0x40;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0x40;
        return;
    case 4:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x4E;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0xF2;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0xE;
        ((BtlStatusIcon *)icon)->colors[2][1] = 1;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x7B;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0xFF;
        return;
    case 8:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x42;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0x6D;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0xA3;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0;
        ((BtlStatusIcon *)icon)->colors[2][0] = 5;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0x49;
        ((BtlStatusIcon *)icon)->colors[2][2] = 7;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0xA3;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0xA3;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0;
        return;
    case 0x10:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0xAF;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0xB8;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xCE;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x21;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0x5F;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x5C;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0xCE;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x21;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xCE;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x21;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0xFF;
        return;
    case 1:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x8E;
        ((BtlStatusIcon *)icon)->colors[0][1] = 6;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0x40;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0x7B;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0xB;
        ((BtlStatusIcon *)icon)->colors[2][2] = 1;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0x40;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x41;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0x40;
        return;
    case 0x20:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x4E;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0xF2;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0xE;
        ((BtlStatusIcon *)icon)->colors[2][1] = 1;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x7B;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0x76;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x40;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0xFF;
        return;
    case 0x40:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x3B;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0x38;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0x59;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0x57;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0xE8;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0xD;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0x30;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x6E;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0x59;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0x57;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0xE8;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0x59;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x57;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0xE8;
        return;
    case 0x80:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0x96;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0x96;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0x96;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0x2B;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0x2B;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x2B;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0xFF;
        return;
    case 0x80000:
        ((BtlStatusIcon *)icon)->colors[0][0] = 0;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0x53;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0x53;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0x53;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0x89;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0x89;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0x89;
        return;
    default:
        MEMBER(s32, icon, BtlStatusIcon, status) = 0;
        ((BtlStatusIcon *)icon)->colors[0][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[0][1] = 0xAF;
        ((BtlStatusIcon *)icon)->colors[0][2] = 0x20;
        ((BtlStatusIcon *)icon)->colors[1][0] = 0xFE;
        ((BtlStatusIcon *)icon)->colors[1][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[1][2] = 0x22;
        ((BtlStatusIcon *)icon)->colors[2][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][1] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[2][2] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[3][0] = 0;
        ((BtlStatusIcon *)icon)->colors[3][1] = 0;
        ((BtlStatusIcon *)icon)->colors[3][2] = 0;
        ((BtlStatusIcon *)icon)->colors[4][0] = 0xFF;
        ((BtlStatusIcon *)icon)->colors[4][1] = 0xAF;
        ((BtlStatusIcon *)icon)->colors[4][2] = 0x20;
        return;
    }
}

/* The portrait owns four three-layer position arrays and the color/status
 * output. The slide's duration, coefficient, curve and mutable frame have
 * one phase lifetime; the per-direction ratio temporaries stay local.
 * See docs/probe_archive/Battle_portrait_002142b0_20260922.md. */
// Intent: draw a unit portrait with its HP and SP bars, status colour and slide. [inferred]
/* b210: remaining DatUnit reloads and pulse-counter accesses individually differ when typed. */
// FUN_002142B0
#pragma push
#pragma opt_loop_invariants on
void btlPortraitDraw(s32 *hud, u8 *unit, f32 originX, f32 originY, s32 rowIndex)
{
    typedef struct DatUnit DatUnit;
    extern void btlUiSetOrigin(u8 *work, f32 x, f32 y);
    extern void btlUiSetRect(s32 *hud, f32 originX, f32 originY,
        f32, f32);
    extern void btlUiDrawSpriteEntry(u8 *work, s32 slot, s32 segment, f32 x,
        f32 y);
    extern void btlUiDrawSpriteFaded(u8 *hud, s32 unit, s32 rowIndex, f32 originX,
        f32 originY, u8, u8, u8,
        u8);
    extern void btlUiAdjustTileOffset(s32 hud, s32 unit, s32 rowIndex, s32);
    extern void btlUiSetRenderMode(s32 mode);
    extern void btlUiSetFactorXY(u8 *work, f32 x, f32 y);
    extern u16 datCalcGetHp(s32 unit);
    extern u16 datCalcGetSp(s32 unit);
    extern u16 datCalcMaxHp(DatUnit *unit);
    extern u16 datCalcMaxSp(DatUnit *unit);
    extern void *memset(void *dst, s32 value, u32 size);
    extern f32 fGpffff815c;
    extern f32 fGpffff8218;
    extern f32 fGpffff84b4;
    extern f32 fGpffff84b8;
    extern f32 D_00626CC0[][24];
    extern f32 D_00626DE0[][24];
    extern f32 D_00626F00[];
    extern f32 D_00626F60[];
    extern f32 D_00626FC0[];
    extern f32 D_00626FD0[];
    Vec2f effect[3];
    Vec2f offset[3];
    Vec2f hpDigits[3];
    Vec2f spDigits[3];
    struct {
        u8 rgba[20];
        s32 status;
    } colors;
    s32 maxHp;
    s32 maxSp;
    u8 *context;
    s32 hp;
    s32 sp;
    u32 row;
    s32 state;
    s16 frame;
    u8 alpha;
    u8 alpha2;
    s32 tile;
    f32 baseX;
    f32 baseY;
    f32 pulseWeight;

    row = rowIndex;
    context = (u8 *)hud + 0x80C;
    btlEncounterBuildStatusIcon(unit, (u8 *)&colors);
    hp = datCalcGetHp((s32)((BtlUnit *)unit)->datUnit) & 0xFFFF;
    sp = datCalcGetSp(MEMBER(s32, unit, BtlUnit, datUnit)) & 0xFFFF;
    maxHp = datCalcMaxHp(MEMBER(DatUnit *, unit, BtlUnit, datUnit)) & 0xFFFF;
    maxSp = datCalcMaxSp(MEMBER(DatUnit *, unit, BtlUnit, datUnit)) & 0xFFFF;
    tile = ((BtlUnit *)unit)->charId;
    if (tile < 9) {
        tile -= 1;
    } else {
        tile = 0;
    }
    frame = ((BtlPortraitState *)(unit + 0xA10))->slideFrame;
    if (frame <= -2) {
        return;
    }
    if (frame < 0x19) {
        frame = (s16)(frame - (s16)((row & 0xFFFF) * 2));
        {
            f32 transitionScale;
            state = ((BtlPortraitState *)(unit + 0xA10))->emphasisFrame;
            if (state > 0 && state < 9) {
                f32 scaleFrame;
                f32 scaleRatio;
                f32 scaleCurve;
                f32 scaleRowY;
                scaleFrame = (f32)state;
                if (scaleFrame > 6.0f) {
                    scaleRatio = 1.0f;
                } else if (scaleFrame < 0.0f) {
                    scaleRatio = 0.0f;
                } else {
                    scaleRatio = scaleFrame / 6.0f;
                }
                scaleCurve = 2.0f * scaleRatio - scaleRatio * scaleRatio;
                originX = originX + scaleCurve * (fGpffff84b4 - originX);
                scaleRowY = fGpffff84b8 + 85.0f * (f32)row;
                scaleRowY = scaleRowY - originY;
                originY = originY + scaleCurve * scaleRowY;
                transitionScale = 1.0f - fGpffff8218 * scaleCurve;
            } else {
                transitionScale = 1.0f;
            }
            btlUiSetFactorXY((u8 *)hud, transitionScale, transitionScale);
        }
        {
            u16 layerIndex;
            f32 layerFrame;
            layerFrame = (f32)frame;
            for (layerIndex = 0; layerIndex < 3U; layerIndex++) {
                f32 layerRatio;
                f32 layerCurve;
                if (layerFrame > 8.0f) {
                    layerRatio = 1.0f;
                } else if (layerFrame < 0.0f) {
                    layerRatio = 0.0f;
                } else {
                    layerRatio = layerFrame / 8.0f;
                }
                layerCurve = 1.0f - (2.0f * layerRatio - layerRatio * layerRatio);
                offset[layerIndex].x = 180.0f * layerCurve;
                offset[layerIndex].y = 80.0f * layerCurve;
                if (((BtlEncounterEntry *)context)->flags & 1) {
                    layerFrame += 0.75f;
                } else {
                    layerFrame -= 0.75f;
                }
            }
        }
        {
            u16 digitIndex;
            f32 digitFrame;
            f32 digitRatio;
            f32 digitCurve;
            f32 digitPhaseRatio;
            digitFrame = (f32)(frame - 3);
            if (digitFrame > 8.0f) {
                digitRatio = 1.0f;
            } else if (digitFrame < 0.0f) {
                digitRatio = 0.0f;
            } else {
                digitRatio = digitFrame / 8.0f;
            }
            digitCurve = 1.0f - (2.0f * digitRatio - digitRatio * digitRatio);
            baseX = 180.0f * digitCurve;
            baseY = -(80.0f * digitCurve);
            digitFrame = (f32)frame;
            for (digitIndex = 0; digitIndex < 3U; digitIndex++) {
                digitRatio = digitFrame - 5.0f;
                if (digitRatio > 8.0f) {
                    digitPhaseRatio = 1.0f;
                } else if (digitRatio < 0.0f) {
                    digitPhaseRatio = 0.0f;
                } else {
                    digitPhaseRatio = digitRatio / 8.0f;
                }
                digitCurve = 1.0f - (2.0f * digitPhaseRatio - digitPhaseRatio * digitPhaseRatio);
                hpDigits[digitIndex].x = 180.0f * digitCurve;
                hpDigits[digitIndex].y = -(80.0f * digitCurve);
                digitRatio = digitFrame - 7.0f;
                if (digitRatio > 8.0f) {
                    digitPhaseRatio = 1.0f;
                } else if (digitRatio < 0.0f) {
                    digitPhaseRatio = 0.0f;
                } else {
                    digitPhaseRatio = digitRatio / 8.0f;
                }
                digitCurve = 1.0f - (2.0f * digitPhaseRatio - digitPhaseRatio * digitPhaseRatio);
                spDigits[digitIndex].x = 180.0f * digitCurve;
                spDigits[digitIndex].y = -(80.0f * digitCurve);
                digitFrame += 1.0f;
            }
        }
    } else {
        state = ((BtlPortraitState *)(unit + 0xA10))->emphasisFrame;
        if (state > 0 && state < 9) {
            f32 selectionFrame;
            f32 selectionRatio;
            f32 selectionCurve;
            f32 selectionY;
            f32 selectionScale;
            if (((BtlEncounterEntry *)context)->selectedUnit != unit && (((BtlEncounterEntry *)context)->flags & 2)) {
                state = (s16)(state - 2);
            }
            selectionFrame = (f32)state;
            if (selectionFrame > 6.0f) {
                selectionRatio = 1.0f;
            } else if (selectionFrame < 0.0f) {
                selectionRatio = 0.0f;
            } else {
                selectionRatio = selectionFrame / 6.0f;
            }
            selectionCurve = 2.0f * selectionRatio - selectionRatio * selectionRatio;
            originX = originX + selectionCurve * (fGpffff84b4 - originX);
            selectionY = fGpffff84b8 + 85.0f * (f32)row;
            selectionY = selectionY - originY;
            originY = originY + selectionCurve * selectionY;
            selectionScale = 1.0f - fGpffff8218 * selectionCurve;
            btlUiSetFactorXY((u8 *)hud, selectionScale, selectionScale);
            memset(offset, 0, 0x18);
            memset(hpDigits, 0, 0x18);
            memset(spDigits, 0, 0x18);
            baseX = 0.0f;
            baseY = 0.0f;
        } else {
            btlUiSetOrigin((u8 *)hud, originX, originY);
            memset(offset, 0, 0x18);
            memset(hpDigits, 0, 0x18);
            memset(spDigits, 0, 0x18);
            baseX = 0.0f;
            baseY = 0.0f;
        }
    }
    state = ((BtlEncounterEntry *)context)->messageFrame;
    if (state > 0) {
        f32 slideDuration;
        f32 slideCoefficient;
        f32 slideCurve;
        f32 slideFrame;
        f32 slideOffset;
        if (((BtlEncounterEntry *)context)->flags & 4) {
            slideFrame = (f32)state;
        } else {
            slideFrame = (f32)state - 2.5f;
        }
        {
            f32 groupRatio;
            f32 groupCurve;
            if (((BtlEncounterEntry *)context)->flags & 4) {
                slideDuration = 10.0f;
                if (slideFrame > slideDuration) {
                    groupRatio = 1.0f;
                } else if (slideFrame < 0.0f) {
                    groupRatio = 0.0f;
                } else {
                    groupRatio = slideFrame / slideDuration;
                }
                slideCoefficient = 2.0f;
                groupCurve = slideCoefficient * groupRatio - groupRatio * groupRatio;
            } else {
                slideDuration = 10.0f;
                if (slideFrame > slideDuration) {
                    groupRatio = 1.0f;
                } else if (slideFrame < 0.0f) {
                    groupRatio = 0.0f;
                } else {
                    groupRatio = slideFrame / slideDuration;
                }
                groupRatio = 1.0f - groupRatio;
                slideCoefficient = 2.0f;
                groupCurve = 1.0f - (slideCoefficient * groupRatio - groupRatio * groupRatio);
            }
            slideOffset = 180.0f * groupCurve;
            baseX += slideOffset;
        }
        {
            u16 digitShiftIndex;
            for (digitShiftIndex = 0; digitShiftIndex < 3U; digitShiftIndex++) {
                hpDigits[digitShiftIndex].x += slideOffset;
                spDigits[digitShiftIndex].x += slideOffset;
            }
        }
        {
            u16 layerShiftIndex;
            for (layerShiftIndex = 0; layerShiftIndex < 3U; layerShiftIndex++) {
                f32 slideRatio;
                if (((BtlEncounterEntry *)context)->flags & 4) {
                    if (slideFrame > slideDuration) {
                        slideRatio = 1.0f;
                    } else if (slideFrame < 0.0f) {
                        slideRatio = 0.0f;
                    } else {
                        slideRatio = slideFrame / slideDuration;
                    }
                    slideCurve = slideCoefficient * slideRatio - slideRatio * slideRatio;
                    slideFrame -= 1.25f;
                } else {
                    if (slideFrame > slideDuration) {
                        slideRatio = 1.0f;
                    } else if (slideFrame < 0.0f) {
                        slideRatio = 0.0f;
                    } else {
                        slideRatio = slideFrame / slideDuration;
                    }
                    slideRatio = 1.0f - slideRatio;
                    slideCurve = 1.0f - (slideCoefficient * slideRatio - slideRatio * slideRatio);
                    slideFrame += 1.25f;
                }
                offset[layerShiftIndex].x += 180.0f * slideCurve;
            }
        }
    }
    if (((BtlPortraitState *)(unit + 0xA10))->flags & 1) {
        f32 effectCos;
        f32 effectSin;
        f32 amplitude;
        u16 effectIndex;
        u16 effectFrame;
        effectFrame = (u16)((BtlPortraitState *)(unit + 0xA10))->ringFrame;
        effectCos = cosf(fGpffff815c);
        effectSin = sinf(fGpffff815c);
        for (effectIndex = 0; effectIndex < 3U; effectIndex++) {
            amplitude = D_00626FC0[effectIndex] * D_00626CC0[effectIndex][effectFrame];
            effect[effectIndex].x = amplitude * effectCos;
            effect[effectIndex].y = -amplitude * effectSin;
            effect[effectIndex].y -= D_00626FD0[effectIndex] * D_00626DE0[effectIndex][effectFrame];
        }
        alpha = (u8)(64.0f * D_00626F00[effectFrame]);
        ((BtlPortraitState *)(unit + 0xA10))->ringFrame += 1;
        if (((BtlPortraitState *)(unit + 0xA10))->ringFrame >= 0x18) {
            ((BtlPortraitState *)(unit + 0xA10))->flags &= ~1;
        }
    } else {
        memset(effect, 0, 0x18);
    }
    btlUiSetRect(hud, originX, originY, 136.0f, 136.0f);
    if (((BtlPortraitState *)(unit + 0xA10))->flags & 0x200) {
        btlUiDrawSpriteFaded((u8 *)hud, 8, 0xE, 29.0f, 27.0f, 0x9D, 0xFF,
            0x22, 0xFF);
    }
    if (((BtlPortraitState *)(unit + 0xA10))->flags & 2) {
        pulseWeight = D_00626F60[((BtlPortraitState *)(unit + 0xA10))->pulseFrame];
        alpha = (u8)(160.0f * pulseWeight);
        alpha2 = (u8)(255.0f * pulseWeight);
        btlUiDrawSpriteFaded((u8 *)hud, 8, 0xE, 29.0f, 27.0f, 0x9D, 0xFF,
            0x22, alpha2);
        MEMBER(s16, unit, BtlUnit, portrait.pulseFrame) += 1;
        if (MEMBER(s16, unit, BtlUnit, portrait.pulseFrame) >= 0x18) {
            ((BtlPortraitState *)(unit + 0xA10))->flags &= ~2;
        }
    }
    if (colors.status != 0) {
        btlUiDrawSpriteFaded((u8 *)hud, 0xB, 0,
            29.0f + effect[0].x + offset[0].x,
            27.0f + effect[0].y + offset[0].y,
            colors.rgba[0xC], colors.rgba[0xD],
            colors.rgba[0xE], 0xFF);
    }
    btlUiDrawSpriteFaded((u8 *)hud, tile, 1,
        27.0f + effect[2].x + offset[2].x,
        16.0f + effect[2].y + offset[2].y, colors.rgba[4],
        colors.rgba[5], colors.rgba[6], 0xFF);
    btlUiDrawSpriteFaded((u8 *)hud, tile, 1,
        20.0f + effect[1].x + offset[1].x,
        20.0f + effect[1].y + offset[1].y, colors.rgba[0],
        colors.rgba[1], colors.rgba[2], 0xFF);
    btlUiDrawSpriteEntry((u8 *)hud, tile, 0,
        20.0f + effect[0].x + offset[0].x,
        20.0f + effect[0].y + offset[0].y);
    if (colors.status != 0) {
        btlUiSetRenderMode(2);
        btlUiDrawSpriteFaded((u8 *)hud, tile, 0,
            20.0f + effect[0].x + offset[0].x,
            20.0f + effect[0].y + offset[0].y,
            colors.rgba[8], colors.rgba[9], colors.rgba[0xA],
            0xFF);
        btlUiSetRenderMode(0);
    }
    if (((BtlPortraitState *)(unit + 0xA10))->flags & 3) {
        btlUiSetRenderMode(2);
        btlUiDrawSpriteFaded((u8 *)hud, tile, 0, 20.0f + effect[0].x,
            20.0f + effect[0].y, 0xFF, 0xFF, 0xFF,
            alpha);
        btlUiSetRenderMode(0);
    }
    if (colors.status != 0) {
        f32 statusX;
        f32 statusY;
        statusX = effect[0].x + offset[0].x;
        statusY = effect[0].y + offset[0].y;
        switch (colors.status) {
        case 2:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xA, 89.0f + statusX, 25.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xC, 66.0f + statusX, 53.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xB, 48.0f + statusX, 22.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 9, 27.0f + statusX, 86.0f + statusY);
            break;
        case 4:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xE, 59.0f + statusX, 18.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xF, 46.0f + statusX, 77.0f + statusY);
            break;
        case 8:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0xD, 73.0f + statusX, 25.0f + statusY);
            break;
        case 0x10:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 5, 36.0f + statusX, 27.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 6, 87.0f + statusX, 27.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 8, 32.0f + statusX, 88.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 7, 65.0f + statusX, 67.0f + statusY);
            break;
        case 1:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x10, 59.0f + statusX, 21.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x12, 109.0f + statusX, 38.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x14, 46.0f + statusX, 27.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x11, 23.0f + statusX, 76.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x13, 38.0f + statusX, 99.0f + statusY);
            break;
        case 0x20:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 1, 82.0f + statusX, 22.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 2, 47.0f + statusX, 23.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 3, 31.0f + statusX, 91.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 4, 31.0f + statusX, 44.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 4, 65.0f + statusX, 84.0f + statusY);
            break;
        case 0x40:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x15, 73.0f + statusX, 22.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x16, 60.0f + statusX, 51.0f + statusY);
            break;
        case 0x80:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x17, 83.0f + statusX, 30.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x18, 62.0f + statusX, 50.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x19, 78.0f + statusX, 26.0f + statusY);
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x1A, 32.0f + statusX, 88.0f + statusY);
            break;
        case 0x80000:
            btlUiDrawSpriteEntry((u8 *)hud, 0xB, 0x1B, 29.0f + statusX, 27.0f + statusY);
            break;
        }
    }
    btlUiDrawSpriteFaded((u8 *)hud, 8, 0xA, 63.0f + baseX, 82.0f + baseY,
        colors.rgba[0x10], colors.rgba[0x11],
        colors.rgba[0x12], 0xFF);
    btlUiDrawSpriteFaded((u8 *)hud, 8, 0xB, 66.0f + baseX, 85.0f + baseY,
        0x26, 0x26, 0x26, 0xFF);
    {
        f32 hpWidth;
        hpWidth = 54.0f * (f32)hp / (f32)maxHp;
        if (hpWidth < 5.0f && hpWidth > 0.0f) {
            hpWidth = 5.0f;
        }
        btlUiAdjustTileOffset((s32)hud, 8, 0xC, (s32)hpWidth);
    }
    btlUiDrawSpriteFaded((u8 *)hud, 8, 0xC, 70.0f + baseX, 88.0f + baseY,
        0xFF, 0xE0, 0x51, 0xFF);
    {
        f32 spWidth;
        spWidth = 54.0f * (f32)sp / (f32)maxSp;
        if (spWidth < 5.0f && spWidth > 0.0f) {
            spWidth = 5.0f;
        }
        btlUiAdjustTileOffset((s32)hud, 8, 0xC, (s32)spWidth);
    }
    btlUiDrawSpriteFaded((u8 *)hud, 8, 0xC, 70.0f + baseX, 94.0f + baseY,
        0xB7, 0xFF, 0x54, 0xFF);
    btlUiDrawSpriteEntry((u8 *)hud, 8, sp % 10,
        121.0f + spDigits[0].x, 64.0f + spDigits[0].y);
    if (sp / 10 != 0) {
        btlUiDrawSpriteEntry((u8 *)hud, 8, (sp / 10) % 10,
            108.0f + spDigits[1].x, 69.0f + spDigits[1].y);
    }
    if (sp / 100 != 0) {
        btlUiDrawSpriteEntry((u8 *)hud, 8, (sp / 100) % 10,
            95.0f + spDigits[2].x, 74.0f + spDigits[2].y);
    }
    btlUiDrawSpriteEntry((u8 *)hud, 8, hp % 10,
        122.0f + hpDigits[0].x, 47.0f + hpDigits[0].y);
    if (hp / 10 != 0) {
        btlUiDrawSpriteEntry((u8 *)hud, 8, (hp / 10) % 10,
            109.0f + hpDigits[1].x, 52.0f + hpDigits[1].y);
    }
    if (hp / 100 != 0) {
        btlUiDrawSpriteEntry((u8 *)hud, 8, (hp / 100) % 10,
            96.0f + hpDigits[2].x, 57.0f + hpDigits[2].y);
    }
}

// Intent: draw the flashing portrait effect for a unit. [inferred]
/* b210: typing either flash-counter clamp store changes instructions; other accesses remain typed. */
// FUN_00215C10
void btlPortraitDrawFlash(s32 *hudContext, u8 *panelUnit, f32 originX, f32 originY, s32 rowIndex)
{
    extern f32 D_007615A4;
    extern f32 D_007615A8;
    extern f32 fGpffff8218;
    extern f32 btlUiSpriteWidth(u8 *work, s32 slot, s32 segment);
    extern f32 btlUiSpriteHeight(u8 *work, s32 slot, s32 segment);
    extern void btlUiDrawSpriteFaded(u8 *hudContext, s32 panelUnit, s32 rowIndex, f32 originX, f32 originY, u8, u8, u8, u8);
    s32 *hud;
    u8 *unit;
    u32 row;
    u8 *entry;
    f32 flashScale;
    f32 spriteOffset;
    f32 selectionScale;
    f32 selectionCurve;
    f32 ratio;
    f32 phaseRatio;
    f32 frame;
    f32 value;
    s32 flags;

    hud = hudContext;
    unit = panelUnit;
    row = rowIndex;
    entry = (u8 *)hud + 0x80C;
    flags = ((BtlPortraitState *)(unit + 0xA10))->flags;
    if ((flags & 0x14) != 0) {
        if ((flags & 0x4) != 0) {
            ((BtlPortraitState *)(unit + 0xA10))->flashFrame += 1;
            if (((BtlPortraitState *)(unit + 0xA10))->flashFrame >= 0x18) {
                ((BtlPortraitState *)(unit + 0xA10))->flags &= ~4;
                MEMBER(s16, unit, BtlUnit, portrait.flashFrame) = 0x18;
            }
        } else if ((flags & 0x10) != 0) {
            ((BtlPortraitState *)(unit + 0xA10))->flashFrame -= 1;
            if (((BtlPortraitState *)(unit + 0xA10))->flashFrame < 0xB) {
                ((BtlPortraitState *)(unit + 0xA10))->flags &= ~0x10;
                MEMBER(s16, unit, BtlUnit, portrait.flashFrame) = 0xA;
            }
        }
        frame = (f32)((BtlPortraitState *)(unit + 0xA10))->flashFrame;
        value = frame / 24.0f;
        flashScale = value * value;
    } else {
        flashScale = 1.0f;
    }
    if (((BtlPortraitState *)(unit + 0xA10))->emphasisFrame < 9) {
        frame = (f32)((BtlPortraitState *)(unit + 0xA10))->emphasisFrame;
        if (frame > 6.0f) {
            ratio = 1.0f;
        } else if (frame < 0.0f) {
            ratio = 0.0f;
        } else {
            ratio = frame / 6.0f;
        }
        selectionCurve = 2.0f * ratio - ratio * ratio;
        originX = originX + selectionCurve * (D_007615A4 - originX);
        value = D_007615A8 + 85.0f * (f32)row;
        value = value - originY;
        originY = originY + selectionCurve * value;
        selectionScale = 1.0f - fGpffff8218 * selectionCurve;
    } else {
        selectionScale = 1.0f;
    }

    btlUiSetFactorXY((u8 *)hud, selectionScale, selectionScale);
    if (((BtlPortraitState *)(unit + 0xA10))->slideFrame < 0x19) {
        frame = (f32)(s16)(((BtlPortraitState *)(unit + 0xA10))->slideFrame - (row & 0xFFFF) * 2);
        if (frame > 8.0f) {
            phaseRatio = 1.0f;
        } else if (frame < 0.0f) {
            phaseRatio = 0.0f;
        } else {
            phaseRatio = frame / 8.0f;
        }
        value = 2.0f * phaseRatio - phaseRatio * phaseRatio;
        frame = 1.0f - value;
        originX = originX + 180.0f * frame;
        originY = originY + 80.0f * frame;
    }
    if (((BtlEncounterEntry *)entry)->messageFrame > 0) {
        if ((((BtlEncounterEntry *)entry)->flags & 4) != 0) {
            frame = (f32)((BtlEncounterEntry *)entry)->messageFrame;
            if (frame > 10.0f) {
                ratio = 1.0f;
            } else if (frame < 0.0f) {
                ratio = 0.0f;
            } else {
                ratio = frame / 10.0f;
            }
            ratio = 2.0f * ratio - ratio * ratio;
        } else {
            frame = (f32)((BtlEncounterEntry *)entry)->messageFrame - 2.5f;
            if (frame > 10.0f) {
                phaseRatio = 1.0f;
            } else if (frame < 0.0f) {
                phaseRatio = 0.0f;
            } else {
                phaseRatio = frame / 10.0f;
            }
            frame = 1.0f - phaseRatio;
            value = 2.0f * frame - frame * frame;
            ratio = 1.0f - value;
        }
        originX = originX + 180.0f * ratio;
    }

    spriteOffset = 1.0f;
    btlUiSetRect(hud, originX, originY, 136.0f, 136.0f);
    if (spriteOffset == flashScale) {
        btlUiDrawSpriteFaded((u8 *)hud, 8, 0xE, 29.0f, 27.0f, 0xFE, 0xFF, 0x22, 0xFF);
    } else {
        f32 width;
        f32 height;
        f32 halfSize;
        spriteOffset = 1.0f - flashScale;
        width = btlUiSpriteWidth((u8 *)hud, 8, 0xE);
        halfSize = 0.5f * width;
        originY = 29.0f + spriteOffset * halfSize;
        height = btlUiSpriteHeight((u8 *)hud, 8, 0xE);
        halfSize = 0.5f * height;
        spriteOffset = 27.0f + spriteOffset * halfSize;
        btlUiSetScale(hud, flashScale, flashScale);
        btlUiDrawSpriteFaded((u8 *)hud, 8, 0xE, originY, spriteOffset, 0xFE, 0xFF, 0x22, 0xFF);
        btlUiSetScale(hud, 1.0f, 1.0f);
    }
}

// Intent: draw the pulsing portrait effect for a unit. [inferred]
/* b210: remaining pulse-phase and angle accesses individually differ when typed. */
// FUN_002161D0
void btlPortraitDrawPulse(s32 *hudContext, u8 *panelUnit, f32 originX, f32 originY, s32 rowIndex)
{
    extern f32 D_007615A4;
    extern f32 D_007615A8;
    extern f32 D_007615AC;
    extern f32 D_007615B0;
    extern f32 fGpffff8218;
    s32 *hud;
    u8 *unit;
    u32 row;
    u8 *entry;
    f32 slideRatio;
    u8 alpha;
    f32 phase;
    f32 curve;
    f32 rate;
    f32 frame;
    f32 value;
    f32 selectionScale;
    s32 flags;

    hud = hudContext;
    unit = panelUnit;
    row = rowIndex;
    entry = (u8 *)hud + 0x80C;
    slideRatio = 1.0f;
    flags = ((BtlPortraitState *)(panelUnit + 0xA10))->flags;
    if ((flags & 0xA0) != 0) {
        phase = ((BtlPortraitState *)(unit + 0xA10))->pulsePhase;
        curve = -1.0f + -2.0f * phase * phase + 4.0f * phase;
        curve = 2.0f * (curve - 0.5f);
        if ((flags & 0x20) != 0) {
            rate = 1.0f + 15.0f * curve;
            frame = 255.0f * (1.0f - curve);
            alpha = (u8)frame;
            MEMBER(f32, unit, BtlUnit, portrait.pulsePhase) = MEMBER(f32, unit, BtlUnit, portrait.pulsePhase) - D_007615AC;
        } else {
            rate = 1.0f + 10.0f * (1.0f - curve);
            frame = 255.0f * curve;
            alpha = (u8)frame;
            MEMBER(f32, unit, BtlUnit, portrait.pulsePhase) = MEMBER(f32, unit, BtlUnit, portrait.pulsePhase) - D_007615B0;
        }
        frame = MEMBER(f32, unit, BtlUnit, portrait.pulsePhase);
        if (frame <= 0.5f) {
            if ((((BtlPortraitState *)(unit + 0xA10))->flags & 0x80) != 0) {
                ((BtlPortraitState *)(unit + 0xA10))->angle = 170.0f;
            }
            ((BtlPortraitState *)(unit + 0xA10))->flags &= ~0xA0;
            MEMBER(f32, unit, BtlUnit, portrait.pulsePhase) = 0.5f;
        }
    } else {
        rate = 1.0f;
        alpha = 0xFF;
    }
    frame = ((BtlPortraitState *)(unit + 0xA10))->angle - rate;
    ((BtlPortraitState *)(unit + 0xA10))->angle = frame;
    if (frame < -180.0f) {
        frame = frame + 360.0f;
        MEMBER(f32, unit, BtlUnit, portrait.angle) = frame;
    }
    if (((BtlPortraitState *)(unit + 0xA10))->emphasisFrame < 9) {
        frame = (f32)((BtlPortraitState *)(unit + 0xA10))->emphasisFrame;
        if (frame > 6.0f) {
            curve = 1.0f;
        } else if (frame < 0.0f) {
            curve = 0.0f;
        } else {
            curve = frame / 6.0f;
        }
        phase = 2.0f * curve - curve * curve;
        originX = originX + phase * (D_007615A4 - originX);
        value = D_007615A8 + 85.0f * (f32)row;
        value = value - originY;
        originY = originY + phase * value;
        selectionScale = 1.0f - fGpffff8218 * phase;
    } else {
        selectionScale = 1.0f;
    }
    btlUiSetFactorXY((u8 *)hud, selectionScale, selectionScale);
    if (((BtlPortraitState *)(unit + 0xA10))->slideFrame < 0x19) {
        frame = (f32)(s16)(((BtlPortraitState *)(unit + 0xA10))->slideFrame - (row & 0xFFFF) * 2);
        if (frame > 8.0f) {
            rate = 1.0f;
        } else if (frame < 0.0f) {
            rate = 0.0f;
        } else {
            rate = frame / 8.0f;
        }
        value = 2.0f * rate - rate * rate;
        frame = 1.0f - value;
        originX = originX + 180.0f * frame;
        originY = originY + 80.0f * frame;
    }
    if (((BtlEncounterEntry *)entry)->messageFrame > 0) {
        if ((((BtlEncounterEntry *)entry)->flags & 4) != 0) {
            frame = (f32)((BtlEncounterEntry *)entry)->messageFrame;
            if (frame > 10.0f) {
                slideRatio = 1.0f;
            } else if (frame < 0.0f) {
                slideRatio = 0.0f;
            } else {
                slideRatio = frame / 10.0f;
            }
            curve = 2.0f * slideRatio - slideRatio * slideRatio;
        } else {
            frame = (f32)((BtlEncounterEntry *)entry)->messageFrame - 2.5f;
            if (frame > 10.0f) {
                slideRatio = 1.0f;
            } else if (frame < 0.0f) {
                slideRatio = 0.0f;
            } else {
                slideRatio = frame / 10.0f;
            }
            frame = 1.0f - slideRatio;
            value = 2.0f * frame - frame * frame;
            curve = 1.0f - value;
        }
        originX = originX + 180.0f * curve;
    }
    btlUiSetRect(hud, originX, originY, 136.0f, 136.0f);
    btlUiSetTileOffset((u8 *)hud, 0x42, 0x41, MEMBER(f32, unit, BtlUnit, portrait.angle));
    btlUiDrawSpriteFaded((u8 *)hud, 8, 0xD, 13.0f, 12.0f, 0xFE, 0xFF, 0x22, alpha);
    btlUiSetTileOffset((u8 *)hud, 0, 0, 0.0f);
}

/* 844/848 bytes; nine resolved relocations; four zero alignment bytes.
 * Snapshot the four party slots before callbacks can update the actor list. */
// Intent: draw the portrait roster, updating the selected unit and its portrait effects. [inferred]
/* b210: typing either selected-unit store changes instructions; roster snapshots use a typed aggregate. */
// FUN_002167F0
#pragma push
#pragma opt_loop_invariants on
void btlPortraitDrawRoster(u8 *drawContext, u8 *entry)
{
    s32 *work;
    u8 *selected;
    s32 i;
    s32 count;
    u8 *old;
    s32 j;
    u8 *iter;
    s32 selectedIndex;
    struct { Vec2f positions[4]; u8 *units[4]; } roster;
    f32 x;
    f32 y;

    work = (s32 *)kwlnTaskGetWork((void *)(((BtlEncounterEntry *)entry)->task));
    if ((*(s32 *)work & 1) != 0 && (((BtlEncounterEntry *)entry)->flags & 0x100) != 0) {
        btlUiSetRenderStates();
        selected = (u8 *)btlActionGetQueueFront();
        if (selected != NULL) selected = (u8 *)((BtlAction *)selected)->unit;
        else selected = ((BtlEncounterEntry *)entry)->selectedUnit;
        selectedIndex = -1;
        count = 0;
        iter = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
        while (iter != NULL) {
            if ((((BtlUnit *)iter)->flags3 & 8) != 0) {
                roster.positions[count].x = (f32)485;
                roster.positions[count].y = (f32)count * 105.0f + -15.0f;
                roster.units[count] = iter;
                if (selected == iter) selectedIndex = count;
                count += 1;
            }
            iter = (u8 *)((BtlUnit *)iter)->prevUnit;
        }
        if (selectedIndex >= 0) {
            old = ((BtlEncounterEntry *)entry)->selectedUnit;
            if (old != selected) {
                if (old != NULL) {
                    s32 flags = ((BtlPortraitState *)(old + 0xA10))->flags;
                    flags &= ~0xC; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    flags |= 0x10; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    if ((flags & 0x40) != 0) {
                        flags &= ~0x60; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                        flags |= 0x80; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                        ((BtlPortraitState *)(old + 0xA10))->pulsePhase = 1.0f;
                    }
                }
                old = selected;
                {
                    s32 flags = ((BtlPortraitState *)(old + 0xA10))->flags;
                    flags |= 0xC; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    flags &= ~0x10; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    if ((s16)datCalcUnitClass((u8 *)((BtlUnit *)old)->datUnit) == 4) {
                        flags = ((BtlPortraitState *)(old + 0xA10))->flags;
                        flags |= 0x60; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                        flags &= ~0x80; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                        ((BtlPortraitState *)(old + 0xA10))->pulsePhase = 1.0f;
                    }
                }
                MEMBER(u8 *, entry, BtlEncounterEntry, selectedUnit) = old;
            }
        } else {
            old = ((BtlEncounterEntry *)entry)->selectedUnit;
            if (old != NULL) {
                s32 flags = ((BtlPortraitState *)(old + 0xA10))->flags;
                flags &= ~0xC; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                flags |= 0x10; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                if ((flags & 0x40) != 0) {
                    flags &= ~0x60; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    flags |= 0x80; ((BtlPortraitState *)(old + 0xA10))->flags = flags;
                    ((BtlPortraitState *)(old + 0xA10))->pulsePhase = 1.0f;
                }
                MEMBER(u8 *, entry, BtlEncounterEntry, selectedUnit) = NULL;
            }
        }
        i = 0;
        while (i < count) {
            old = roster.units[i];
            x = roster.positions[i].x;
            y = roster.positions[i].y;
            if ((((BtlPortraitState *)(old + 0xA10))->flags & 0x1C) != 0) btlPortraitDrawFlash(work, old, x, y, i & 0xFFFF);
            if ((((BtlPortraitState *)(old + 0xA10))->flags & 0xE0) != 0) btlPortraitDrawPulse(work, old, x, y, i & 0xFFFF);
            i += 1;
        }
        j = 0;
        while (j < count) {
            old = roster.units[j];
            x = roster.positions[j].x;
            y = roster.positions[j].y;
            btlPortraitDraw(work, old, x, y, j & 0xFFFF);
            j += 1;
        }
        btlUiSetFactorXY((u8 *)work, 1.0f, 1.0f);
    }
}

// Intent: start a panel entry with a single value and its countdown. [inferred]
// FUN_00216B40
void btlPanelStartEntry(s32 task, s32 text) {
    u8 *panel;
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlMessagePanel *)panel)->mode = 0;
    ((BtlMessagePanel *)panel)->state = 1;
    ((BtlMessagePanel *)panel)->text = text;
    btlPanelSetCountdown(task, 0x20);
    ((BtlMessagePanel *)panel)->flags &= 0xFFF3;
}

// Intent: start a panel entry with three values and its countdown. [inferred]
// FUN_00216BB0
void btlPanelStartValues(s32 task, s32 unit, s32 window, s32 record) {
    u8 *panel;
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlMessagePanel *)panel)->mode = 1;
    ((BtlMessagePanel *)panel)->state = 1;
    ((BtlMessagePanel *)panel)->unit = unit;
    ((BtlMessagePanel *)panel)->window = window;
    ((BtlMessagePanel *)panel)->record = record;
    btlPanelSetCountdown(task, 0x20);
    ((BtlMessagePanel *)panel)->flags &= 0xFFF3;
}

// Intent: set the panel countdown and its pause bit. [inferred]
// FUN_00216C40
void btlPanelSetCountdown(s32 task, s32 duration) {
    u8 *hud = (u8 *)kwlnTaskGetWork((void *)task);
    u8 *panel = hud + 0x84C;

    ((BtlHudWork *)hud)->message.duration = duration;
    if (duration < 0) {
        ((BtlMessagePanel *)panel)->flags |= 1;
    } else {
        ((BtlMessagePanel *)panel)->flags &= 0xFFFE;
    }
}

// Intent: release a panel's font list and clear its message window. [inferred]
// FUN_00216CA0
void btlPanelReleaseText(s32 task) {
    u8 *panel = (u8 *)kwlnTaskGetWork((void *)task) + 0x84C;

    if (((BtlMessagePanel *)panel)->fontList != 0) {
        frFontListKeepOrRelease(((BtlMessagePanel *)panel)->fontList);
        ((BtlMessagePanel *)panel)->fontList = 0;
    }
    itfMesWindowClear(((BtlMessagePanel *)panel)->window, 0);
    ((BtlMessagePanel *)panel)->flags &= 0xFFFD;
    ((BtlMessagePanel *)panel)->fadeFrame = 0;
    ((BtlMessagePanel *)panel)->elapsed = ((BtlMessagePanel *)panel)->duration;
}

// Intent: Set bit 0x8 of a panel entry's +0x85C word once its entry has started [inferred]
// FUN_00216D10
void btlPanelMarkEntryStarted(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->message.flags = ((BtlHudWork *)hud)->message.flags | 8;
}

// Intent: Set bit 0x4 of a panel entry's +0x85C word after its countdown starts and before its target is set [inferred]
// FUN_00216D40
void btlPanelMarkEntryTimed(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->message.flags = ((BtlHudWork *)hud)->message.flags | 4;
}

// Intent: store the target unit for a panel. [inferred]
// FUN_00216D70
void btlPanelSetTarget(u8 *task, s32 unit) {
    ((BtlHudWork *)kwlnTaskGetWork(task))->message.unit = unit;
}

// Intent: format a number into a panel's message window. [inferred]
// FUN_00216DA0
void btlPanelSetValueText(u8 *window, s32 value) {
    u8 text[0x80];

    sprintf(text, (const char *)&iGpffffa598, value);
    itfMesWindowSetString(window, 1, text);
}

// Intent: initialise a panel record with its unit slots cleared. [inferred]
// FUN_00216DF0
void btlPanelInitRecord(u8 *panel, s32 task) {
    memset(panel, 0, 0x40);
    ((BtlMessagePanel *)panel)->window = -1;
    ((BtlMessagePanel *)panel)->task = (void *)task;
    ((BtlMessagePanel *)panel)->result = -1;
    ((BtlMessagePanel *)panel)->choiceWindow = -1;
}

/* Empty panel hook; the retail body has no side effects. */
// FUN_00216E50
void btlPanelNoOp(void)
{
}

/* Retail-exact: 4856 bytes, complete resolved relocations and eight zero
 * alignment bytes. Status icon/color locals have separate typed lifetimes;
 * timed messages share the render path, and rectangles use rounded integer
 * coordinates. Render-state scopes retain the table address while reloading
 * its callback. See Battle_message_panel_00216e60_20260922.md. */
// Intent: draw a timed message with its status icon and text list. [inferred]
/* b210: remaining window-handle, flag and timer accesses individually differ when typed. */
// FUN_00216E60
void btlMessageDrawTimed(u8 *drawContext, u8 *panel)
{
    extern s32 btlUnitGetDataRow(u8 *unit);
    extern void btlUiSetOrigin(u8 *work, f32 x, f32 y);
    extern void btlUiDrawSpriteEntry(u8 *work, s32 slot, s32 segment, f32 x, f32 y);
    extern void btlUiSetRenderMode(s32 mode);
    extern u8 *frFontCreateTextList(u8 *text, s32 style, s8 mode, s32, u8 *);
    extern void frFontSetCharWidth(s32 list, s32 spacing);
    extern void frFontMoveListTo(s32 drawContext, s32 panel, s32);
    extern void frFontSetGlyphColor(s32 list, s32 color);
    extern void frFontSetFlagBits(s32 bits);
    extern void frFontClearFlagBits(s32 bits);
    extern s32 frFontDrawList(void *drawContext, u32 panel, u32);
    extern s32 frFontNodeWidth(s32 node);
    extern void frFontExSetScale(s32 font, f32 scale);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr,
                               s32 id, const char *str, s32 flags, s32 unused);
    extern void itfMesWindowBindRecord(s32 drawContext, s32 panel, s32);
    extern void itfMesWindowMove(s32 drawContext, s32 panel, s32);
    extern void itfMesWindowSetFlagBits(s32 handle, s32 flags);
    extern void itfMesWindowSetGlyphStyle(s32 drawContext, s32 panel, s32, s32, s32);
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32,
                             s32, s32, s32, s32);
    extern s32 itfMesWindowRunEntry(s32 drawContext, s32 panel, s32, s32);
    extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
    extern void btlUiSetRenderStates(void);
    extern s32 itfMesWindowMeasureText(s32 drawContext, s32 panel, s32, s32);
    extern void btlUiDrawSpriteFaded(u8 *work, s32 slot, s32 segment, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 opacity);
    extern void btlUiSetScale(void *drawContext, f32 panel, f32);
    extern u16 D_008C024E[];
    extern BtlShuffleRenderStateSet D_00887300[];
    extern s32 iGpffffb4b0;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;
    extern f32 fGpffff8218;
    extern f32 fGpffffb47c;
    struct { s32 x, y, width, height; } box;
    u8 colorBytes[4];
    s32 animated;
    f32 boxOffset;
    f32 firstBoxY;
    f32 secondBoxY;
    extern const char *iGpffffa590;
    extern const char *iGpffffa594;
    u8 *hudBytes;
    u8 *activePanel;
    s32 *hud;
    s16 key;
    u16 count;
    f32 progress;
    f32 fade;
    f32 pulse;
    f32 statusX;

    (void)drawContext;
    hudBytes = (u8 *)kwlnTaskGetWork(((BtlMessagePanel *)panel)->task);
    hud = (s32 *)hudBytes;
    if ((*hud & 1) == 0) {
        return;
    }
    btlUiSetRenderStates();
    btlUiSetOrigin((u8 *)hud, 0.0f, 0.0f);
    switch (((BtlMessagePanel *)panel)->state) {
    case 0:
        break;
    case 1: {
        s32 measuredWidth;
        s32 textWidth;
        s32 halfWidth;
        if (((BtlMessagePanel *)panel)->fontList != 0) {
            frFontListKeepOrRelease(((BtlMessagePanel *)panel)->fontList);
            ((BtlMessagePanel *)panel)->fontList = 0;
        }
        itfMesWindowClear(((BtlMessagePanel *)panel)->window, 0);
        ((BtlMessagePanel *)panel)->flags &= (u16)~2;
        ((BtlMessagePanel *)panel)->elapsed = ((BtlMessagePanel *)panel)->duration;
        if (((BtlMessagePanel *)panel)->mode == 1) {
            if (((BtlMessagePanel *)panel)->unit != 0) {
                itfMesWindowSetString((u8 *)(MEMBER(s32, panel, BtlMessagePanel, window)), 0,
                              (u8 *)btlUnitGetDataRow((u8 *)((BtlMessagePanel *)panel)->unit));
            }
            itfMesWindowSetGlyphStyle(MEMBER(s32, panel, BtlMessagePanel, window), 2, 0, 0xFF, 0xFF);
            itfMesWindowBindRecord(MEMBER(s32, panel, BtlMessagePanel, window), ((BtlMessagePanel *)panel)->record, 0);
            itfMesWindowSetGlyphStyle(MEMBER(s32, panel, BtlMessagePanel, window), 2, 0, 0xFF, 0xFF);
            itfMesWindowSetFlagBits(MEMBER(s32, panel, BtlMessagePanel, window), 0x800000);
            measuredWidth = itfMesWindowMeasureText(MEMBER(s32, panel, BtlMessagePanel, window), MEMBER(s32, panel, BtlMessagePanel, record), 0, 2);
            textWidth = measuredWidth / 16;
            if (MEMBER(u16, panel, BtlMessagePanel, flags) & 4) {
                halfWidth = textWidth / 2;
                itfMesWindowMove(MEMBER(s32, panel, BtlMessagePanel, window), (0xD0 - halfWidth) << 4, 0x2A0);
            } else {
                halfWidth = textWidth / 2;
                itfMesWindowMove(MEMBER(s32, panel, BtlMessagePanel, window), (0x12F - halfWidth) << 4, 0x2B0);
            }
        } else {
            frFontSetFlagBits(1);
            frFontClearFlagBits(2);
            iGpffffb4b0 = 120;
            ((BtlMessagePanel *)panel)->fontList = (s32)frFontCreateTextList((u8 *)((BtlMessagePanel *)panel)->text, 1, 0, 0, 0);
            iGpffffb4b0 = 0;
            frFontSetCharWidth(((BtlMessagePanel *)panel)->fontList, -1);
            frFontClearFlagBits(1);
            frFontSetFlagBits(2);
            textWidth = frFontNodeWidth(((BtlMessagePanel *)panel)->fontList);
            if (MEMBER(u16, panel, BtlMessagePanel, flags) & 4) {
                frFontMoveListTo(((BtlMessagePanel *)panel)->fontList, (0xD1 - textWidth / 2) << 4, 0x2A0);
            } else {
                frFontMoveListTo(((BtlMessagePanel *)panel)->fontList, (0x130 - textWidth / 2) << 4, 0x2A0);
            }
            frFontExSetScale(((BtlMessagePanel *)panel)->fontList, 50.0f);
            frFontSetGlyphColor(((BtlMessagePanel *)panel)->fontList, -1);
        }
        ((BtlMessagePanel *)panel)->textWidth = textWidth;
        MEMBER(s32, panel, BtlMessagePanel, elapsed) = 0;
        MEMBER(u16, panel, BtlMessagePanel, state) = 2;
        MEMBER(u16, panel, BtlMessagePanel, flags) |= 2;
    }
    /* Fall through: initialize and draw the message in the same update. */
    case 2: {
        if ((((BtlMessagePanel *)panel)->flags & 1) == 0 &&
            (((BtlMessagePanel *)panel)->elapsed)++ >= ((BtlMessagePanel *)panel)->duration) {
            activePanel = (u8 *)kwlnTaskGetWork(MEMBER(void *, panel, BtlMessagePanel, task)) + 0x84C;
            if (((BtlMessagePanel *)activePanel)->fontList != 0) {
                frFontListKeepOrRelease(((BtlMessagePanel *)activePanel)->fontList);
                ((BtlMessagePanel *)activePanel)->fontList = 0;
            }
            itfMesWindowClear(((BtlMessagePanel *)activePanel)->window, 0);
            ((BtlMessagePanel *)activePanel)->flags &= (u16)~2;
            ((BtlMessagePanel *)activePanel)->fadeFrame = 0;
            ((BtlMessagePanel *)activePanel)->elapsed = ((BtlMessagePanel *)activePanel)->duration;
            MEMBER(u16, panel, BtlMessagePanel, state) = 0;
        } else if (MEMBER(u16, panel, BtlMessagePanel, flags) & 2) {
            count = ((BtlMessagePanel *)panel)->fadeFrame;
            if (count < 4) {
                progress = (f32)(u32)++MEMBER(u16, panel, BtlMessagePanel, fadeFrame) / 4.0f;
                fade = 2.0f * progress - progress * progress;
                if (((BtlMessagePanel *)panel)->mode != 1) {
                    void *renderStates = (void *)D_00887300;
                    (*(BtlShuffleRenderStateSet *)renderStates)(rwRENDERSTATETEXTURERASTER, 0);
                    (*(BtlShuffleRenderStateSet *)renderStates)(rwRENDERSTATEZWRITEENABLE, (void *)1);
                    colorBytes[0] = 0;
                    colorBytes[1] = 0;
                    colorBytes[2] = 0xFF;
                    colorBytes[3] = 0;
                    box.x = 104;
                    box.width = 400;
                    box.height = 20;
                    boxOffset = ws14_mul(16.0f, fade);
                    box.y = (s32)(103.0f - (f32)box.height - boxOffset);
                    firstBoxY = (f32)box.y;
                    PrimDrawFlatRectangle(colorBytes, (f32 *)&box, 0.0f, 0);
                    box.y = (s32)(99.0f + boxOffset);
                    secondBoxY = (f32)box.y;
                    PrimDrawFlatRectangle(colorBytes, (f32 *)&box, 0.0f, 0);
                    box.y = (s32)(firstBoxY + (f32)box.height);
                    box.height = (s32)(secondBoxY - (f32)box.y);
                    PrimDrawFlatRectangle(colorBytes, (f32 *)&box, 51.0f, 0);
                    (*(BtlShuffleRenderStateSet *)renderStates)(rwRENDERSTATEZWRITEENABLE, 0);
                }
                btlUiSetScale((u8 *)hud, 1.0f, fade);
                fade = 18.5f * (1.0f - fade);
                statusX = 0.0f;
                colorBytes[3] = 0;
                animated = 1;
            } else {
                fade = 0.0f;
                statusX = 0.0f;
                colorBytes[3] = 0xFF;
                animated = 0;
            }
            if (MEMBER(u16, panel, BtlMessagePanel, flags) & 8) {
                btlUiSetOrigin((u8 *)hud, 0.0f, 81.0f);
                btlUiDrawSpriteEntry((u8 *)hud, 10, 44, 186.0f, fade);
                btlUiDrawSpriteEntry((u8 *)hud, 10, 41, 402.0f, fade);
                btlUiSetScale((u8 *)hud, 1.0f, 1.0f);
            } else {
                btlUiSetOrigin((u8 *)hud, 94.0f, 81.0f);
                btlUiDrawSpriteEntry((u8 *)hud, 10, 40, 0.0f, fade);
                btlUiDrawSpriteEntry((u8 *)hud, 10, 41, 400.0f, fade);
                btlUiSetScale((u8 *)hud, 1.0f, 1.0f);
                if ((MEMBER(u16, panel, BtlMessagePanel, flags) & 4) && colorBytes[3] > 0) {
                    DatUnit *bits;
                    s32 allAttacks;
                    s8 attackSprite;
                    s8 defenseSprite;
                    s8 speedSprite;
                    u8 attackRed;
                    u8 attackGreen;
                    u8 attackBlue;
                    u8 defenseRed;
                    u8 defenseGreen;
                    u8 defenseBlue;
                    u8 speedRed;
                    u8 speedGreen;
                    u8 speedBlue;
                    btlUiSetOrigin((u8 *)hud, 94.0f + statusX, 81.0f);
                    bits = ((BtlUnit *)((BtlMessagePanel *)panel)->unit)->datUnit;
                    if (datCalcHasBuffMask(bits, 0x400) || datCalcHasBuffMask(bits, 0x800)) {
                        allAttacks = 1;
                    } else {
                        allAttacks = 0;
                    }
                    if (datCalcHasBuffMask(bits, 1) != 0 ||
                        datCalcHasBuffMask(bits, 4) != 0) {
                        attackSprite = 0x25;
                        attackRed = 0xFF;
                        attackGreen = 0x65;
                        attackBlue = 0x74;
                    } else if (datCalcHasBuffMask(bits, 2) != 0 ||
                               datCalcHasBuffMask(bits, 8) != 0) {
                        attackSprite = 0x26;
                        attackRed = 0x79;
                        attackGreen = 0xA1;
                        attackBlue = 0xFF;
                    } else {
                        attackSprite = 0x27;
                        attackRed = 0x66;
                        attackGreen = 0x66;
                        attackBlue = 0x66;
                    }
                    if (datCalcHasBuffMask(bits, 0x40) != 0) {
                        defenseSprite = 0x25;
                        defenseRed = 0xFF;
                        defenseGreen = 0x65;
                        defenseBlue = 0x74;
                    } else if (datCalcHasBuffMask(bits, 0x80) != 0) {
                        defenseSprite = 0x26;
                        defenseRed = 0x79;
                        defenseGreen = 0xA1;
                        defenseBlue = 0xFF;
                    } else {
                        defenseSprite = 0x27;
                        defenseRed = 0x66;
                        defenseGreen = 0x66;
                        defenseBlue = 0x66;
                    }
                    if (datCalcHasBuffMask(bits, 0x100) != 0 ||
                        datCalcHasBuffMask(bits, 0x10) != 0) {
                        speedSprite = 0x25;
                        speedRed = 0xFF;
                        speedGreen = 0x65;
                        speedBlue = 0x74;
                    } else if (datCalcHasBuffMask(bits, 0x200) != 0 ||
                               datCalcHasBuffMask(bits, 0x20) != 0) {
                        speedSprite = 0x26;
                        speedRed = 0x79;
                        speedGreen = 0xA1;
                        speedBlue = 0xFF;
                    } else {
                        speedSprite = 0x27;
                        speedRed = 0x66;
                        speedGreen = 0x66;
                        speedBlue = 0x66;
                    }
                    if (attackSprite == 0x27 && defenseSprite == 0x27 && speedSprite == 0x27 && !allAttacks) {
                        colorBytes[0] = 0x66;
                        colorBytes[1] = 0x66;
                        colorBytes[2] = 0x66;
                    } else {
                        colorBytes[0] = 0xFF;
                        colorBytes[1] = 0xFF;
                        colorBytes[2] = 0xFF;
                    }
                    btlUiDrawSpriteFaded((u8 *)hud, 10, 42, 222.0f, 6.0f,
                                  colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, 43, 384.0f, 6.0f,
                                  colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, 34, 233.0f, 8.0f,
                                  colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, 35, 285.0f, 8.0f,
                                  colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, 36, 337.0f, 8.0f,
                                  colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, defenseSprite, 313.0f, 10.0f,
                                  defenseRed, defenseGreen, defenseBlue, colorBytes[3]);
                    btlUiDrawSpriteFaded((u8 *)hud, 10, speedSprite, 365.0f, 10.0f,
                                  speedRed, speedGreen, speedBlue, colorBytes[3]);
                    if (!allAttacks) {
                        btlUiDrawSpriteFaded((u8 *)hud, 10, attackSprite, 261.0f, 10.0f,
                                      attackRed, attackGreen, attackBlue, colorBytes[3]);
                    } else {
                        btlUiDrawSpriteFaded((u8 *)hud, 10, 0x56, 262.0f, -8.0f,
                                      colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                        btlUiDrawSpriteFaded((u8 *)hud, 10, 0x57, 252.0f, 26.0f,
                                      colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
                        btlUiDrawSpriteFaded((u8 *)hud, 10, 0x25, 261.0f, 4.0f,
                                      0xFF, 0x65, 0x74, colorBytes[3]);
                        btlUiDrawSpriteFaded((u8 *)hud, 10, 0x25, 261.0f, 15.0f,
                                      0xFF, 0x65, 0x74, colorBytes[3]);
                        if (attackSprite == 0x25) {
                            u8 pulseAlpha;
                            pulse = sinf(fGpffff8478 * fGpffffb47c);
                            pulseAlpha = (u8)(255.0f * ((fGpffff8218 + 0.0f) + fGpffff847c * pulse));
                            fGpffffb47c += 12.0f;
                            if (fGpffffb47c >= 180.0f) {
                                fGpffffb47c -= 180.0f;
                            }
                            btlUiSetRenderMode(2);
                            btlUiDrawSpriteFaded((u8 *)hud, 10, 0x58, 256.0f, -1.0f,
                                          0xFC, 0x30, 0x30, pulseAlpha);
                            btlUiSetRenderMode(0);
                        }
                    }
                }
            }
            if (((BtlMessagePanel *)panel)->fontList != 0) {
                frFontSetFlagBits(0x40);
                if (animated != 0) {
                    void *renderStates = (void *)D_00887300;
                    (*(BtlShuffleRenderStateSet *)renderStates)(rwRENDERSTATEZTESTENABLE, (void *)1);
                    frFontDrawList(*(void **)panel, 1, 0);
                    (*(BtlShuffleRenderStateSet *)renderStates)(rwRENDERSTATEZTESTENABLE, 0);
                } else {
                    frFontDrawList(*(void **)panel, 1, 0);
                }
                frFontClearFlagBits(0x40);
            }
        }
        break;
    }
    }
    if (((BtlMessagePanel *)panel)->flags & 0x10) {
        progress = (f32)((BtlMessagePanel *)panel)->choiceFrame / 8.0f;
        if (progress > 1.0f) {
            fade = 1.0f;
        } else if (progress < 0.0f) {
            fade = 0.0f;
        } else {
            fade = 2.0f * progress - progress * progress;
        }
        btlUiSetOrigin((u8 *)hud, 0.0f, -8.0f);
        btlUiSetScale((u8 *)hud, 1.0f, 1.0f);
        btlUiDrawSpriteFaded((u8 *)hud, 9, 0x52, ws14_add(379.0f, ws14_mul(-400.0f, 1.0f - fade)),
                      303.0f, 0x21, 0x21, 0x21, 0xFF);
        progress = (f32)(MEMBER(s32, panel, BtlMessagePanel, choiceFrame) - 4) / 6.0f;
        if (progress > 1.0f) {
            fade = 1.0f;
        } else if (progress < 0.0f) {
            fade = 0.0f;
        } else {
            fade = 2.0f * progress - progress * progress;
        }
        if (fade > 0.0f) {
            btlUiSetScale((u8 *)hud, 1.0f, fade);
            btlUiDrawSpriteFaded((u8 *)hud, 9, 0x50, 170.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            btlUiDrawSpriteFaded((u8 *)hud, 9, 0x51, 473.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            btlUiSetScale((u8 *)hud, 1.0f, 1.0f);
        }
        if (fade == 1.0f) {
            btlUiDrawSpriteFaded((u8 *)hud, 9, 0x53, 211.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            btlUiDrawSpriteFaded((u8 *)hud, 9, 0x54, 328.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            frFontExDrawText(244.0f, 359.0f, 0.0f, 0x212121FF, 5, 0, iGpffffa590, 0, 0);
            frFontExDrawText(361.0f, 359.0f, 0.0f, 0x212121FF, 5, 0, iGpffffa594, 0, 0);
        }
        if (fade == 1.0f) {
            if (((BtlMessagePanel *)panel)->choiceStarted == 0) {
                itfMesWindowRunEntry(((BtlMessagePanel *)panel)->choiceWindow, ((BtlMessagePanel *)panel)->choiceRecord, 1, 0xF561);
                MEMBER(s32, panel, BtlMessagePanel, choiceStarted) = 1;
            }
            itfMesWindowDrawEntry(31.0f, 300.0f, 0.0f, -1, 0, 0, 0,
                          ((BtlMessagePanel *)panel)->choiceWindow, ((BtlMessagePanel *)panel)->choiceRecord);
            key = ((BtlMessagePanel *)panel)->inputDelay;
            if (key == 0) {
                if (((BtlMessagePanel *)panel)->result == -1) {
                    if (D_008C024E[0] & 0x40) {
                        MEMBER(s16, panel, BtlMessagePanel, result) = 0;
                    } else if (D_008C024E[0] & 0x20) {
                        MEMBER(s16, panel, BtlMessagePanel, result) = 1;
                    }
                }
            } else {
                MEMBER(s16, panel, BtlMessagePanel, inputDelay) = key - 1;
            }
        }
        (MEMBER(s32, panel, BtlMessagePanel, choiceFrame))++;
    }
}

// Intent: start a short timed message with a randomised offset. [inferred]
// FUN_00218160
void btlMessageStartShort(u8 *task, u8 *action)
{
    u8 *hud;
    u8 *panel;
    s32 value;

    hud = (u8 *)kwlnTaskGetWork(task);
    panel = hud + 0x84C;
    ((BtlHudWork *)hud)->message.result = -1;
    ((BtlHudWork *)hud)->message.choiceFrame = 0;
    ((BtlHudWork *)hud)->message.choiceWindow = ((BtlHudWork *)hud)->messageWindow;
    value = ((((BtlAction *)action)->unit->charId - 2) * 3) + 5;
    ((BtlMessagePanel *)panel)->choiceRecord = value + datCalcRandomBelow(3);
    ((BtlMessagePanel *)panel)->choiceStarted = 0;
    ((BtlMessagePanel *)panel)->inputDelay = 8;
    btlSoundCancelPlayback();
    ((BtlMessagePanel *)panel)->flags |= 0x10;
}

// Intent: report whether a message is still running. [inferred]
// FUN_00218200
s32 btlMessageIsActive(s32 task)
{
    return ~(((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result) != 0;
}

// Intent: return the message's result code. [inferred]
// FUN_00218230
s32 btlMessageGetResult(s32 task)
{
    return ((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result;
}

// Intent: reset a message's result and release its window. [inferred]
// FUN_00218260
void btlMessageReset(s32 task) {
    u8 *panel;
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlMessagePanel *)panel)->result = -1;
    ((BtlMessagePanel *)panel)->choiceWindow = -1;
    btlSoundFadeChannel(1, 0);
    ((BtlMessagePanel *)panel)->flags &= 0xFFEF;
}

// Intent: start a long timed message with a randomised offset. [inferred]
// FUN_002182C0
void btlMessageStartLong(u8 *task, u8 *action)
{
    u8 *hud;
    u8 *panel;
    s32 value;

    hud = (u8 *)kwlnTaskGetWork(task);
    panel = hud + 0x84C;
    ((BtlHudWork *)hud)->message.result = -1;
    ((BtlHudWork *)hud)->message.choiceFrame = 0;
    ((BtlHudWork *)hud)->message.choiceWindow = ((BtlHudWork *)hud)->messageWindow;
    value = ((((BtlAction *)action)->unit->charId - 2) * 3) + 0x1A;
    ((BtlMessagePanel *)panel)->choiceRecord = value + datCalcRandomBelow(3);
    ((BtlMessagePanel *)panel)->choiceStarted = 0;
    ((BtlMessagePanel *)panel)->inputDelay = 8;
    btlSoundCancelPlayback();
    ((BtlMessagePanel *)panel)->flags |= 0x10;
}

// Intent: report whether a message is still running (duplicate of btlMessageIsActive). [inferred]
// FUN_00218360
s32 btlMessageIsActiveAlt(s32 task)
{
    return ~(((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result) != 0;
}

// Intent: return the message's result code (duplicate of btlMessageGetResult). [inferred]
// FUN_00218390
s32 btlMessageGetResultAlt(s32 task)
{
    return ((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result;
}

// Intent: reset a message's result and release its window (duplicate of btlMessageReset). [inferred]
// FUN_002183C0
void btlMessageResetAlt(s32 task) {
    u8 *panel;
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlMessagePanel *)panel)->result = -1;
    ((BtlMessagePanel *)panel)->choiceWindow = -1;
    btlSoundFadeChannel(1, 0);
    ((BtlMessagePanel *)panel)->flags &= 0xFFEF;
}

// Intent: install a message window and reset the message state. [inferred]
// FUN_00218420
void btlMessageInstallWindow(s32 task, u8 *window)
{
    u8 *hud;
    u8 *panel;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlHudWork *)hud)->message.result = -1;
    ((BtlHudWork *)hud)->message.choiceFrame = 0;
    ((BtlMessagePanel *)panel)->choiceWindow = itfMesWindowInstall(btlTargetGetMessageRecord(0xCB));
    ((BtlMessagePanel *)panel)->choiceRecord = 0;
    ((BtlMessagePanel *)panel)->choiceStarted = 0;
    ((BtlMessagePanel *)panel)->inputDelay = 8;
    btlSoundCancelPlayback();
    ((BtlMessagePanel *)panel)->flags = ((BtlMessagePanel *)panel)->flags | 0x10;
}

// Intent: report whether a message is still running (duplicate of btlMessageIsActive). [inferred]
// FUN_002184A0
s32 btlMessageIsActiveAlt2(s32 task)
{
    return ~(((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result) != 0;
}

// Intent: return the message's result code (duplicate of btlMessageGetResult). [inferred]
// FUN_002184D0
s32 btlMessageGetResultAlt2(s32 task)
{
    return ((BtlHudWork *)kwlnTaskGetWork((void *)task))->message.result;
}

// Intent: release a message window and clear its result. [inferred]
// FUN_00218500
void btlMessageRelease(s32 task)
{
    u8 *hud;
    u8 *panel;
    s32 handle;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    panel = hud + 0x84C;
    ((BtlHudWork *)hud)->message.result = -1;
    handle = ((BtlHudWork *)hud)->message.choiceWindow;
    if (handle != -1) {
        itfMesWindowReleaseIfActive(handle);
        ((BtlMessagePanel *)panel)->choiceWindow = -1;
    }
    ((BtlMessagePanel *)panel)->flags = ((BtlMessagePanel *)panel)->flags & 0xFFEF;
}

// Intent: set up a message from a unit's flags and start its state. [inferred]
/* b210: MEMBER preserves nested action-pointer reloads; unit and enemy records remain typed. */
// FUN_00218560
void btlMessageSetup(u8 *task, u8 *action)
{
    u8 *message;

    message = (u8 *)kwlnTaskGetWork(task) + 0x8C0;
    if (datGetFlag(0x38) != 0) {
        *(u16 *)message |= 4;
    } else {
        *(u16 *)message &= 0xFFFB;
    }
    if (datCalcEnemyHasTableFlag((u8 *)((BtlAction *)action)->unit->datUnit) != 0) {
        *(u16 *)message |= 8;
    } else {
        *(u16 *)message &= 0xFFF7;
    }
    if (((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->genus == 1 &&
        (((DatEnemyRecord *)iGpffffb3c4)[
                  ((DatUnit *)(u8 *)((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit)->id].flags &
         0x4000) != 0) {
        *(u16 *)message |= 8;
    }
    sdkSndStartStream(1, 0xE, 2, 0xE);
    *(u16 *)message &= 0xFFEF;
    ((BtlMessageState *)message)->value = (s32)action;
    ((BtlMessageState *)message)->state = 1;
    ((BtlMessageState *)message)->frame = 0;
}

// Intent: report whether a message is not pending. [inferred]
// FUN_00218690
s32 btlMessageIsIdle(s32 task)
{
    s32 flag;

    flag = (((BtlHudWork *)kwlnTaskGetWork((void *)task))->messageState.flags & 2) != 0;
    return flag ^ 1;
}

// Intent: store a pending value and set the message state to pending. [inferred]
// FUN_002186C0
void btlMessageSetPendingValue(u8 *task, s32 value) {
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork(task);
    ((BtlHudWork *)hud)->messageState.value = value;
    ((BtlHudWork *)hud)->messageState.state = 2;
}

// Intent: set the message state to done. [inferred]
// FUN_00218700
void btlMessageSetDone(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->messageState.state = 4;
}

// Intent: set the message's hidden bit. [inferred]
// FUN_00218730
void btlMessageSetHidden(s32 task)
{
    u8 *hud;

    hud = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlHudWork *)hud)->messageState.flags = ((BtlHudWork *)hud)->messageState.flags | 0x10;
}

extern f32 D_008872F8[];
extern BtlShuffleRenderPrimitive D_00887310[];
extern s32 kwlnGetCamera(void);
#pragma pop
#pragma pop
