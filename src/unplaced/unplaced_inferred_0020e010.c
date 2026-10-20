/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0020e010-0020ff00 */

#include "btl_skill_target_internal.h"
#include "btl_unit_internal.h"
#include "list_item_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
extern void btlSelectionFlushEntries();
extern u32 kwlnTaskGetWork();
extern f32 fGpffff815c;
extern f32 fGpffff83b0;
extern void btlEntryListFlush(u8 *head);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, const void *src, u32 size);
extern f32 fGpffff84a4;
extern f32 cosf(f32 angle);
extern f32 sinf(f32 angle);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;

extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 D_008872F8[];
extern s32 kwlnGetCamera(void);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);
extern void btlUiSetRenderMode(s32 mode);
extern void btlGaugeSetActive(u8 *gauge, s32 active);
extern void btlUiSetOrigin(u8 *work, f32 x, f32 y);
extern void btlUiSetRect(s32 *work, f32 x, f32 y, f32 width, f32 height);
extern void btlUiSetRenderStates(void);
extern void btlUiSetTileOffset(u8 *work, s16 x, s32 y, f32 factor);
extern void btlUiSetScale(u8 *work, f32 x, f32 y);
extern void btlUiSetFactorXY(u8 *work, f32 x, f32 y);
typedef struct BattleRenderDispatch {
    void (*setState)(u32 state, u32 value);
} BattleRenderDispatch;

extern void btlSelectionSwapRowState(u8 *from, u8 *to);
/* Row offsets are shared by swap and target-mode dispatch. */
typedef struct BtlSelectionRow {
    u16 drawMode;
    s16 state;
    s16 frame;
    u8 pad06[2];
    Vec2f position;
    u16 flags;
} BtlSelectionRow;

/* The entry allocator requests 0x28 bytes and links through the last word. */
typedef struct BtlSelectionEntry {
    s32 unit;
    f32 x, y, z;
    s32 frame;
    u16 flags;
    u8 pad16[2];
    u8 data[8];
    u16 kind;
    u8 pad22[2];
    struct BtlSelectionEntry *next;
} BtlSelectionEntry;

typedef struct BtlTransitionOutput {
    f32 offset;
    u8 alpha;
    u8 pad05[3];
    s32 ready;
    f32 x, y;
} BtlTransitionOutput;

typedef struct BtlPanelGaugeState {
    u8 alpha;
    u8 pad01;
    s16 filledCount;
    s16 flags;
    u8 pad06[2];
    f32 extent;
} BtlPanelGaugeState;

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: update a unit's target flag and dispatch the target draw for its mode. [inferred]
// FUN_0020E010
void btlSelectionDispatchTargetMode(s32 mode, u8 *row, u8 *unit)
{
    extern void btlUnitGetAttachedSphereCenter(u8 *context, f32 *value);
    extern s32 btlTargetFindInRange(f32 *position, f32 *output);
    extern void btlUiSetOrigin(u8 *work, f32 x, f32 y);
    extern void btlPanelCursorDrawA(s32 task, u8 *cursor, u8 *panel, f32 *position);
    extern void btlPanelCursorDrawB(s32 task, u8 *cursor, u8 *panel, f32 *position);
    extern void btlPanelCursorDrawC(s32 task, u8 *cursor, u8 *panel, f32 *position);
    extern void btlPanelCursorDrawD(s32 task, u8 *cursor, u8 *panel, f32 *position);
    struct BtlTargetProjection {
        u8 pad[8];
        u8 value[4];
        u8 gap[4];
        u8 vector[12];
    } work;
    /* Unit flag word +A10 and parent-task prefix have no complete layout here. */
    u8 *drawWork;
    u16 targetState;
    u16 drawMode;

    drawWork = (u8 *)kwlnTaskGetWork();
    targetState = ((BtlSelectionRow *)row)->state;
    if (targetState == 0) {
        if (((BtlUnit *)unit)->genus == 0) {
            *(s32 *)(unit + 0xA10) &= ~0x200;
        }
        return;
    }
    if (((BtlUnit *)unit)->genus != 0) {
        goto flags_done;
    }
    switch (targetState) {
    case 1:
    case 4:
        goto flag_set;
    default:
        goto flag_clear;
    }
flag_set:
    *(s32 *)(unit + 0xA10) |= 0x200;
    goto flags_done;
flag_clear:
    *(s32 *)(unit + 0xA10) &= ~0x200;
flags_done:
    btlUnitGetAttachedSphereCenter(unit, (f32 *)work.vector);
    if (btlTargetFindInRange((f32 *)work.vector, (f32 *)work.value) != 0) {
        btlUiSetOrigin(drawWork, 0.0f, 0.0f);
        drawMode = ((BtlSelectionRow *)row)->drawMode;
        switch (drawMode) {
        case 0:
            btlPanelCursorDrawA(mode, row, unit, (f32 *)work.value);
            return;
        case 1:
            btlPanelCursorDrawB(mode, row, unit, (f32 *)work.value);
            return;
        case 2:
            btlPanelCursorDrawC(mode, row, unit, (f32 *)work.value);
            return;
        case 3:
            btlPanelCursorDrawD(mode, row, unit, (f32 *)work.value);
            break;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: swap the row state between two selection rows and copy the position. [inferred]
// FUN_0020E1D0
void btlSelectionSwapRowState(u8 *from, u8 *to) {
    ((BtlSelectionRow *)from)->frame = 0;
    ((BtlSelectionRow *)from)->state = 3;
    ((BtlSelectionRow *)from)->flags &= 0xFFFE;
    ((BtlSelectionRow *)from)->flags &= 0xFFFD;
    ((BtlSelectionRow *)to)->frame = 0;
    ((BtlSelectionRow *)to)->state = 2;
    ((BtlSelectionRow *)to)->flags &= 0xFFF7;
    ((BtlSelectionRow *)to)->flags &= 0xFFFB;
    ((BtlSelectionRow *)to)->flags &= 0xFFFD;
    ((BtlSelectionRow *)to)->flags |= 1;
    ((BtlSelectionRow *)to)->position = ((BtlSelectionRow *)from)->position;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: queue a new entry at the head of the selection entry list. [inferred]
// FUN_0020E250
void btlSelectionPushEntry(u8 *task, s32 unitHandle, s32 *entryData, f32 *position, u16 flags)
{
    /* Entry/output layouts are proven; typed fields change MWCC aliasing and lose MATCH. */
    u8 *state;
    u8 **list;
    u8 *entry;
    u8 *newEntry;
    u8 *allocated;
    f32 x;
    f32 y;
    f32 z;

    state = (u8 *)kwlnTaskGetWork(task);
    list = (u8 **)(state + 0x75C);
    if (*(s32 *)entryData != 0 || *(s32 *)(entryData + 1) != 0 ||
        *(u16 *)((u8 *)entryData + 8) != 0) {
        chkmemAllocSiteTag(&D_00626C30, 0x3A);
        allocated = (u8 *)jtbl_008873E8[0](0x28, 0x40000);
        newEntry = allocated;
        x = position[0];
        y = position[1];
        z = position[2];
        *(f32 *)(newEntry + 4) = x;
        *(f32 *)(newEntry + 8) = y;
        *(f32 *)(newEntry + 0xC) = z;
        memcpy(newEntry + 0x18, entryData, 0xC);
        *(s32 *)(newEntry + 0x10) = 0;
        *(u16 *)(newEntry + 0x14) = flags;
        *(s32 *)newEntry = unitHandle;
        *(u16 *)(newEntry + 0x14) |= 1;
        *(u16 *)(*(u8 **)newEntry + 0xA0) += 1;
        for (entry = *(u8 **)list; entry != NULL; entry = *(u8 **)(entry + 0x24)) {
            if ((*(u16 *)(entry + 0x20) & 0xF) == 0 &&
                *(s32 *)entry == unitHandle) {
                if ((*(u16 *)(entry + 0x14) & 2) == 0) {
                    *(s32 *)(entry + 0x10) = 0;
                    *(u16 *)(entry + 0x14) |= 2;
                }
                if ((*(u16 *)(newEntry + 0x14) & 4) == 0) {
                    x = *(f32 *)(entry + 4);
                    y = *(f32 *)(entry + 8);
                    z = *(f32 *)(entry + 0xC);
                    *(f32 *)(newEntry + 4) = x;
                    *(f32 *)(newEntry + 8) = y;
                    *(f32 *)(newEntry + 0xC) = z;
                    *(u16 *)(newEntry + 0x14) |= 4;
                }
            }
        }
        *(u8 **)(newEntry + 0x24) = *(u8 **)list;
        *(u8 **)list = newEntry;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: flush the selection entry list. [inferred]
// FUN_0020E3F0
void btlSelectionFlushEntries() {
    btlEntryListFlush((u8 *)kwlnTaskGetWork() + 0x75C);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: draw an integer value as sprite glyphs, optionally right-aligned. [inferred]
// FUN_0020E420
void btlSelectionDrawValue(u8 *drawWork, f32 x, f32 y, s32 value, s32 rightAligned, u32 packedColor)
{
    extern s32 iGpffffa580;
    extern void sprintf(void *drawWork, const char *value, ...);
    extern s32 strlen(const void *drawWork);
    u8 digits[0x40];
    s32 alphaWide;
    u8 alpha;
    s32 blueWide;
    u8 blue;
    s32 greenWide;
    u8 green;
    s32 redWide;
    u8 red;
    s32 count;
    s32 i;

    redWide = (s8)(u8)((packedColor & 0xFF000000) >> 24);
    greenWide = (s8)(u8)((packedColor & 0x00FF0000) >> 16);
    blueWide = (s8)(u8)((packedColor & 0x0000FF00) >> 8);
    alphaWide = (s8)(u8)(packedColor & 0x000000FF);
    if (alphaWide != 0) {
        sprintf(digits, (const char *)&iGpffffa580, value);
        count = strlen(digits);
        if (rightAligned != 0) {
            x = x - (f32)count * 9.5f;
            y -= 11.0f;
        }
        i = 0;
        alpha = (u8)alphaWide;
        blue = (u8)blueWide;
        green = (u8)greenWide;
        red = (u8)redWide;
        for (; i < count; i++) {
            btlUiDrawSpriteFaded(drawWork, 10, (s8)digits[i] - 0x19, x, y,
                          red, green, blue, alpha);
            x += 19.0f;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: map a linear progress value through an optional sine or cosine ease. [inferred]
// FUN_0020E5C0
f32 btlSelectionEaseCurve(s32 frame, s32 start, s32 end, s32 curve)
{
    f32 progress;

    if (frame < start) {
        progress = 0.0f;
        goto done;
    }
    if (frame < end) {
        progress = (f32)(frame - start) / (f32)(end - start);
        switch (curve) {
        case 1:
            progress = sinf(fGpffff84a4 * progress);
            goto done;
        case 2:
            progress = 1.0f - cosf(fGpffff84a4 * progress);
            goto done;
        default:
            goto done;
        }
    }
    progress = 1.0f;
done:
    return progress;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/*
 * measured: 964/976 bytes, three resolved calls, twelve zero alignment bytes.
 * The zero-duration ramp follows 0020E5C0 and the adjacent 0020F4D0 spelling;
 * its division is unreachable. Preserve the frame snapshot and flag reload.
 */
// Intent: step the slide transition frame and draw its panel elements. [inferred]
// FUN_0020E690
void btlTransitionStepSlide(u8 *task, u8 *transition, u8 *panel,
                   f32 x, f32 y, s32 color, u8 *output)
{
    /* Entry/output layouts are proven; typed fields change MWCC aliasing and lose MATCH. */
    Vec2f position;
    s32 frame;
    f32 fade;
    f32 slide;
    kwlnTaskGetWork(*(void **)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (*(u16 *)(transition + 0x14) & 2) {
        if (frame < 3) fade = 0.0f;
        else if (frame < 9) fade = (f32)(frame - 3) / 6.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * (1.0f - fade));
        if (frame < 0) slide = 0.0f;
        else if (frame < 6) slide = (f32)frame / 6.0f;
        else slide = 1.0f;
        *(f32 *)output = -30.0f * slide;
    } else {
        if (frame < 0) slide = 0.0f;
        else if (frame < 0) slide = (f32)frame / 0.0f;
        else slide = 1.0f;
        if (!(slide <= 0.0f)) {
            position.x = 89.0f + x;
            position.y = 86.0f + y;
            shdDrawRotatingQuad(position, 0.0f, color, 22.0f * slide, 0.0f, 1);
        }
        if (frame < 0) fade = 0.0f;
        else if (frame < 3) fade = (f32)frame / 3.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * fade);
        *(f32 *)output = 10.0f * (1.0f - fade);
        if (*(u16 *)(transition + 0x14) & 4) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        } else if (frame == 3) {
            btlGaugeSetActive(panel, 1);
        } else if (frame > 3) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/*
 * measured: 1192/1200 bytes, eight resolved calls, eight zero alignment bytes.
 * Keep the alternating fade/y stages: expression propagation otherwise fuses
 * the slide arithmetic or reverses its floating-point operand order.
 */
// Intent: step the stretch transition frame and draw its panel elements. [inferred]
// FUN_0020EA60
void btlTransitionStepStretch(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    /* Task +4 is the owner context; its full prefix is not established here. */
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 stretch;
    f32 fade;
    f32 y;
    work = (u8 *)kwlnTaskGetWork(*(void **)(task + 4));
    frame = ((BtlSelectionEntry *)transition)->frame;
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    stretch = 2.0f * first - second;
    if (!(stretch <= 0.0f)) {
        btlUiSetFactorXY(work, 1.0f, stretch);
        btlUiDrawSpriteFaded(work, 10, 21, 54.0f, 25.0f, 150, 255, 2, 255);
        btlUiDrawSpriteFaded(work, 10, 22, 54.0f, 70.0f, 150, 255, 2, 255);
        btlUiSetFactorXY(work, 1.0f, 1.0f);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 71.0f + y;
        y = fade - 16.0f;
        btlUiDrawSpriteFaded(work, 10, 14, 28.0f, y, 150, 255, 2, (u8)alpha);
        btlUiDrawSpriteFaded(work, 10, 13, 28.0f, y, 35, 55, 0, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    ((BtlTransitionOutput *)output)->alpha = (u8)(255.0f * fade);
    ((BtlTransitionOutput *)output)->offset = 20.0f * (1.0f - fade);
    if (((BtlSelectionEntry *)transition)->flags & 4) {
        ((BtlTransitionOutput *)output)->x = 54.0f;
        ((BtlTransitionOutput *)output)->y = 89.0f;
        ((BtlTransitionOutput *)output)->ready = 1;
    } else if (frame == 6) {
        btlGaugeSetActive(panel, 1);
    } else if (frame > 6) {
        ((BtlTransitionOutput *)output)->x = 54.0f;
        ((BtlTransitionOutput *)output)->y = 89.0f;
        ((BtlTransitionOutput *)output)->ready = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: step the expansion transition frame and draw its panel elements. [inferred]
// FUN_0020EF10
/* Retail-exact: 1460 bytes, 7 call relocations, 12 zero alignment bytes. */
void btlTransitionStepExpand(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    /* Task +4 is the owner context; its full prefix is not established here. */
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 expansion;
    f32 remaining;
    f32 fade;
    f32 offset;
    f32 y;
    work = (u8 *)kwlnTaskGetWork(*(void **)(task + 4));
    frame = ((BtlSelectionEntry *)transition)->frame;
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    expansion = 3.0f * first - 2.0f * second;
    if (!(expansion <= 0.0f)) {
        alpha = (expansion > 1.0f) ? 255 : (u8)(255.0f * expansion);
        remaining = 1.0f - expansion;
        btlUiDrawSpriteFaded(work, 10, 18, 61.0f,
                      (0.0f + 46.0f - 20.0f * remaining) - 16.0f,
                      244, 255, 14, (u8)alpha);
        offset = 10.0f * remaining;
        remaining = 87.0f + offset;
        y = remaining - 16.0f;
        btlUiDrawSpriteFaded(work, 10, 19, 37.0f - offset, y, 244, 255, 14, (u8)alpha);
        btlUiDrawSpriteFaded(work, 10, 20, 84.0f + offset, y, 244, 255, 14, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 73.0f + y;
        y = fade - 16.0f;
        btlUiDrawSpriteFaded(work, 10, 12, 47.0f, y, 244, 255, 14, (u8)alpha);
        btlUiDrawSpriteFaded(work, 10, 11, 47.0f, y, 54, 46, 0, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    ((BtlTransitionOutput *)output)->alpha = (u8)(255.0f * fade);
    ((BtlTransitionOutput *)output)->offset = 20.0f * (1.0f - fade);
    if (((BtlSelectionEntry *)transition)->flags & 4) {
        ((BtlTransitionOutput *)output)->x = 54.0f;
        ((BtlTransitionOutput *)output)->y = 89.0f;
        ((BtlTransitionOutput *)output)->ready = 1;
    } else if (frame == 6) {
        btlGaugeSetActive(panel, 1);
    } else if (frame > 6) {
        ((BtlTransitionOutput *)output)->x = 54.0f;
        ((BtlTransitionOutput *)output)->y = 89.0f;
        ((BtlTransitionOutput *)output)->ready = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: step the pulse transition frame and draw its ring. [inferred]
// FUN_0020F4D0
void btlTransitionStepPulse(u8 *task, u8 *transition, f32 x, f32 y)
{
    extern u32 kwlnTaskGetWork(void *task);
    Vec2f center;
    f32 scale;
    f32 labelProgress;
    f32 ringProgress;
    /* Task +4 is the owner context; its complete prefix is not established here. */
    u8 *drawWork;
    s32 frame;

    drawWork = (u8 *)kwlnTaskGetWork(*(void **)(task + 4));
    frame = ((BtlSelectionEntry *)transition)->frame;
    if (frame < 0) {
        ringProgress = 0.0f;
    } else if (frame < 6) {
        ringProgress = (f32)frame / 6.0f;
    } else {
        ringProgress = 1.0f;
    }
    if (!(ringProgress <= 0.0f)) {
        center.x = 86.0f + x;
        center.y = 86.0f + y;
        if (ringProgress == 1.0f) {
            shdDrawRotatedRect(center, 0.0f, 0x151515FF, 87.0f,
                          16.0f, fGpffff815c, 1);
        }
        scale = 2.0f - ringProgress;
        shdDrawRotatedRect(center, 0.0f, 0xFF0F02FF,
                      87.0f * scale, 16.0f * scale,
                      fGpffff83b0, 1);
    }
    if (frame < 7) {
        labelProgress = 0.0f;
    } else if (frame < 7) {
        labelProgress = (f32)(frame - 7) / 0.0f;
    } else {
        labelProgress = 1.0f;
    }
    if (!(labelProgress <= 0.0f)) {
        btlUiSetTileOffset(drawWork, 0x1C, 8, -30.0f);
        btlUiDrawSpriteFaded(drawWork, 0xA, 6, 58.0f, 78.0f,
                      0x15, 0x15, 0x15, 0xFF);
        btlUiSetTileOffset(drawWork, 0, 0, 0.0f);
    }
}
#pragma pop

extern f32 fGpffff8210;
f32 btlUiSpriteWidth(u8 *work, s32 slot, s32 segment);
f32 btlUiSpriteHeight(u8 *work, s32 slot, s32 segment);
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: draw one indexed panel sprite at its corner with its colour and visible state. [inferred]
// FUN_0020F730
void btlPanelDrawIndexed(u8 *work, u8 *state, s32 packedColor, s32 index)
{
    f32 corners[2][2] = {
        {-98.0f, -92.0f},
        {98.0f, 92.0f}
    };
    /* One interleaved coordinate block, with complete X-origin and
       Y-origin array views. Each row advances eight bytes inside its
       actual array; the leading firstX overlays the first coordinate. */
    union {
        f32 fromX[6];
        struct { f32 firstX; f32 fromY[5]; } y;
    } offsets[1] = {{{15.0f, 54.0f, 27.0f, 25.0f, 57.0f, 14.0f}}};
    s32 sprites[4] = {49, 54, 57, 60};
    f32 drawX;
    f32 drawY;
    f32 scaleY;
    f32 width;
    f32 height;
    f32 offsetX;
    f32 offsetY;
    f32 adjustmentX;
    f32 adjustmentY;
    f32 scaleX;
    s32 flipY;
    s32 flipX;
    s32 sprite;
    s32 part;
    s32 rowOffset;
    s32 half;
    s32 sign;
    u8 blue;
    u8 green;

    /* Interleaved coordinate rows retain byte indexing to preserve MWCC address trees. */
    if (index != 0) {
        scaleY = fGpffff8210 * ((BtlPanelGaugeState *)state)->extent;
        half = index / 6;
        flipX = 1 - (((index / 3) + half) & 1);
        flipY = 1 - half;
        if (flipX == 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        drawX = (f32)sign;
        if (flipY == 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        drawY = (f32)sign;
        if (index % 6 < 3) {
            part = index % 3;
        } else {
            part = ~(index % 3) + 3;
        }
        sprite = sprites[flipX | (flipY << 1)] - part;
        rowOffset = part * (2 * sizeof(f32));
        width = btlUiSpriteWidth(work, 10, sprite);
        adjustmentX = (f32)flipX * width;
        scaleX = fGpffff8210;
        adjustmentX = adjustmentX / scaleX;
        offsetX = *(f32 *)((u8 *)&offsets[0].fromX + rowOffset);
        drawX = scaleX * (drawX * (offsetX + adjustmentX));
        height = btlUiSpriteHeight(work, 10, sprite);
        adjustmentY = (f32)flipY * height;
        adjustmentY = adjustmentY / scaleY;
        offsetY = *(f32 *)((u8 *)&offsets[0].y.fromY + rowOffset);
        drawY = scaleY * (drawY * (offsetY + adjustmentY));
        btlUiSetOrigin(work,
                     (0.0f + (f32)0x117) + fGpffff8210 * corners[flipX][0],
                     (0.0f + 229.0f) + scaleY * corners[flipY][1]);
        blue = ((u8 *)&packedColor)[2];
        green = ((u8 *)&packedColor)[1];
        btlUiDrawSpriteFaded(work, 10, sprite, drawX, drawY,
                      ((u8 *)&packedColor)[0], green, blue, ((u8 *)&packedColor)[3]);
        if (index < ((BtlPanelGaugeState *)state)->filledCount) {
            btlUiDrawSpriteFaded(work, 10, sprite, drawX, drawY,
                          ((u8 *)&packedColor)[0], green, blue, 255);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: draw the panel gauge ring and fill for the given extent. [inferred]
// FUN_0020FA70
/* Retail-exact: 1156 bytes, 24 relocations, 12 zero alignment bytes. */
void btlPanelDrawGauge(u8 *work, u8 *state)
{
    extern void btlPanelDrawIndexed(u8 *work, u8 *state, s32 packedColor, s32 index);
    extern f32 D_00761300;
    extern f32 fGpffff8110;
    extern f32 fGpffff84ac;
    union { Color4 rgba; s32 bits; } ring, fill, saved, black, transparent;
    Vec2f position;
    u8 red;
    u8 green;
    u8 blue;
    s32 index;
    f32 extent;
    extent = ((BtlPanelGaugeState *)state)->extent;
    if (extent == 0.0f) return;
    btlUiSetRenderStates();
    if (((BtlPanelGaugeState *)state)->flags & 4) {
        red = 140; green = 170; blue = 255;
        ring.rgba.c0 = 102; ring.rgba.c1 = 130; ring.rgba.c2 = 255;
        fill.rgba.c0 = 0; fill.rgba.c1 = 25; fill.rgba.c2 = 255;
    } else {
        red = 255; green = 140; blue = 170;
        ring.rgba.c0 = 255; ring.rgba.c1 = 102; ring.rgba.c2 = 110;
        fill.rgba.c0 = 255; fill.rgba.c1 = 0; fill.rgba.c2 = 21;
    }
    ring.rgba.c3 = 51;
    fill.rgba.c3 = (u8)(255.0f * extent);
    btlUiSetOrigin(work, (f32)279, 229.0f);
    btlUiSetFactorXY(work, 1.0f, 1.0f);
    saved.rgba = fill.rgba;
    position.x = (f32)279;
    position.y = 229.0f;
    transparent.rgba.c0 = black.rgba.c0 = 0;
    transparent.rgba.c1 = black.rgba.c1 = 0;
    transparent.rgba.c2 = black.rgba.c2 = 0;
    black.rgba.c3 = (u8)(76.0f * extent);
    transparent.rgba.c3 = 0;
    shdDrawRadialFan(position, 0.0f, black.bits, transparent.bits, 100.0f, 0.0f, 12, D_00761300, 1.0f, 0);
    transparent.rgba.c0 = saved.rgba.c0;
    transparent.rgba.c1 = saved.rgba.c1;
    transparent.rgba.c2 = saved.rgba.c2;
    transparent.rgba.c3 = 0;
    btlUiSetRenderMode(2);
    shdDrawRadialFan(position, 0.0f, fill.bits, transparent.bits, 125.0f, 0.0f, 12, D_00761300, 1.0f, 0);
    btlUiSetScale(work, extent, 1.0f);
    btlUiSetTileOffset(work, 0, 0, 90.0f);
    btlUiDrawSpriteFaded(work, 10, 45, 20.0f, -57.0f * extent, red, green, blue, 255);
    if (state[0]) {
        btlUiSetScale(work, fGpffff8110, 1.5f);
        btlUiDrawSpriteFaded(work, 10, 45, 30.0f, fGpffff84ac, red, green, blue, state[0]);
    }
    btlUiSetScale(work, 1.0f, extent);
    btlUiSetTileOffset(work, 0, 0, 0.0f);
    btlUiDrawSpriteFaded(work, 10, 46, 12.0f, -5.0f * extent, red, green, blue, 255);
    btlUiSetScale(work, D_00761300, extent);
    for (index = 1; index < 12; index++) btlPanelDrawIndexed(work, state, ring.bits, index);
    btlUiSetTileOffset(work, 0, 0, 0.0f);
    btlUiSetScale(work, 1.0f, 1.0f);
    btlUiSetFactorXY(work, 1.0f, 1.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Advance the transition frame before its timed drawing phases. The corner
 * opacity is narrowed to one byte before packing the vertex color. */
// Intent: step the multi-phase transition frame and draw its bands and glyphs. [inferred]
// FUN_0020FF00
void btlTransitionDrawFrame(u8 *glyphs, u8 *transition)
{
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    extern s32 kwlnGetCamera(void);
    extern f32 fGpffff837c;
    extern f32 fGpffff84a8;
    Vec2f center;
    Vec2f firstPosition;
    Vec2f secondPosition;
    f32 vertices[6][16];
    s32 frame;
    BattleRenderDispatch *renderer;
    f32 lateBand;
    f32 earlyBand;
    f32 narrowIntro;
    f32 narrowExpansion;
    f32 narrowScale;
    f32 diagonalIntro;
    f32 diagonalExpansion;
    f32 diagonalScale;
    f32 glyphFadeIn;
    f32 glyphFadeOut;
    f32 glyphScale;
    f32 cornerFadeIn;
    f32 cornerFadeOut;
    f32 cornerOpacity;
    f32 horizontalExtent;
    f32 verticalExtent;
    u32 packedColor;
    s32 channel0;
    s32 channel1;
    s32 channel2;
    s32 channel3;
    f32 depth;
    f32 reciprocal;
    /* Intro frame at +E and camera near plane at +80 use separate, partial layouts. */
    frame = ++*(u16 *)(transition + 0xE);
    center.x = 302.0f;
    center.y = 224.0f;
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(1, 0);
    if (frame < 0x23) {
        lateBand = 0.0f;
    } else if (frame < 0x2D) {
        lateBand = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 0x23) / 10.0f));
    } else {
        lateBand = 1.0f;
    }
    if (!(lateBand <= 0.0f)) {
        btlUiSetRenderMode(2);
        shdDrawRectOutline(center, 0.0f, 0xFF1432FF, 0.0f, 400.0f * lateBand, 90.0f, 1);
        btlUiSetRenderMode(0);
    }
    if (frame < 0x19) {
        earlyBand = 0.0f;
    } else if (frame < 0x23) {
        earlyBand = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 0x19) / 10.0f));
    } else {
        earlyBand = 1.0f;
    }
    if (!(earlyBand <= 0.0f)) {
        btlUiSetRenderMode(2);
        shdDrawRectOutline(center, 0.0f, 0xFF1432FF, 0.0f, 400.0f * earlyBand, 90.0f, 1);
        btlUiSetRenderMode(0);
    }
    if (frame < 0xA) {
        narrowIntro = 0.0f;
    } else if (frame < 0x14) {
        narrowIntro = sinf(fGpffff84a4 * ((f32)(frame - 0xA) / 10.0f));
    } else {
        narrowIntro = 1.0f;
    }
    if (frame < 0x28) {
        narrowExpansion = 0.0f;
    } else if (frame < 0x32) {
        narrowExpansion = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 0x28) / 10.0f));
    } else {
        narrowExpansion = 1.0f;
    }
    narrowScale = 4.0f * narrowExpansion + narrowIntro;
    if (!(narrowScale <= 0.0f)) {
        shdDrawRectOutline(center, 0.0f, 0xFF, 0.0f, 86.0f * narrowScale, 11.0f, 1);
    }
    if (frame < 0) {
        diagonalIntro = 0.0f;
    } else if (frame < 0xA) {
        diagonalIntro = sinf(fGpffff84a4 * ((f32)frame / 10.0f));
    } else {
        diagonalIntro = 1.0f;
    }
    if (frame < 0x34) {
        diagonalExpansion = 0.0f;
    } else if (frame < 0x3E) {
        diagonalExpansion = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 0x34) / 10.0f));
    } else {
        diagonalExpansion = 1.0f;
    }
    diagonalScale = 2.0f * diagonalExpansion + diagonalIntro;
    if (!(diagonalScale <= 0.0f)) {
        horizontalExtent = 273.0f * diagonalScale;
        firstPosition.x = 79.0f + horizontalExtent;
        verticalExtent = 275.0f * diagonalScale;
        firstPosition.y = 448.0f - verticalExtent;
        shdDrawWedge(firstPosition, 0.0f, 0xFF, fGpffff837c, 1, 0);
        secondPosition.x = 525.0f - horizontalExtent;
        secondPosition.y = verticalExtent;
        shdDrawWedge(secondPosition, 0.0f, 0xFF, fGpffff84a8, 1, 0);
    }
    if (frame < 8) {
        glyphFadeIn = 0.0f;
    } else if (frame < 0xF) {
        glyphFadeIn = (f32)(frame - 8) / 7.0f;
    } else {
        glyphFadeIn = 1.0f;
    }
    if (frame < 0x30) {
        glyphFadeOut = 0.0f;
    } else if (frame < 0x37) {
        glyphFadeOut = (f32)(frame - 0x30) / 7.0f;
    } else {
        glyphFadeOut = 1.0f;
    }
    glyphScale = glyphFadeIn - glyphFadeOut;
    if (!(glyphScale <= 0.0f)) {
        btlUiSetRect((s32 *)glyphs, 239.0f, 161.0f, 128.0f, 127.0f);
        btlUiSetFactorXY(glyphs, glyphScale, 1.0f);
        btlUiDrawSpriteFaded(glyphs, 0xA, 0x33, 0.0f, 0.0f, 0xCC, 0, 0, 0xFF);
        btlUiSetFactorXY(glyphs, glyphScale, 1.0f);
    }
    renderer->setState(1, 0);
    btlUiSetRenderMode(2);
    if (frame < 0) {
        cornerFadeIn = 0.0f;
    } else if (frame < 0xA) {
        cornerFadeIn = (f32)frame / 10.0f;
    } else {
        cornerFadeIn = 1.0f;
    }
    if (frame < 0x32) {
        cornerFadeOut = 0.0f;
    } else if (frame < 0x3C) {
        cornerFadeOut = (f32)(frame - 0x32) / 10.0f;
    } else {
        cornerFadeOut = 1.0f;
    }
    cornerOpacity = cornerFadeIn - cornerFadeOut;
    if (!(cornerOpacity <= 0.0f)) {
        packedColor = (u8)(255.0f * cornerOpacity) | 0xFF000000;
        channel0 = (s32)((packedColor >> 24) & 0xFF);
        channel1 = (s32)((packedColor >> 16) & 0xFF);
        channel2 = (s32)((packedColor >> 8) & 0xFF);
        channel3 = (s32)(packedColor & 0xFF);
        depth = D_008872F8[0];
        reciprocal = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
        vertices[0][0] = 640.0f;
        vertices[0][1] = 0.0f;
        vertices[0][2] = depth;
        vertices[0][6] = reciprocal;
        vertices[0][8] = (f32)(u32)channel0;
        vertices[0][9] = (f32)(u32)channel1;
        vertices[0][10] = (f32)(u32)channel2;
        vertices[0][11] = (f32)(u32)channel3;
        vertices[1][0] = 221.0f;
        vertices[1][1] = 0.0f;
        vertices[1][2] = depth;
        vertices[1][6] = reciprocal;
        vertices[1][8] = (f32)(u32)channel0;
        vertices[1][9] = (f32)(u32)channel1;
        vertices[1][10] = (f32)(u32)channel2;
        vertices[1][11] = 0.0f;
        vertices[2][0] = 640.0f;
        vertices[2][1] = 418.0f;
        vertices[2][2] = depth;
        vertices[2][6] = reciprocal;
        vertices[2][8] = (f32)(u32)channel0;
        vertices[2][9] = (f32)(u32)channel1;
        vertices[2][10] = (f32)(u32)channel2;
        vertices[2][11] = 0.0f;
        vertices[3][0] = 0.0f;
        vertices[3][1] = 448.0f;
        vertices[3][2] = depth;
        vertices[3][6] = reciprocal;
        vertices[3][8] = (f32)(u32)channel0;
        vertices[3][9] = (f32)(u32)channel1;
        vertices[3][10] = (f32)(u32)channel2;
        vertices[3][11] = (f32)(u32)channel3;
        vertices[4][0] = 418.0f;
        vertices[4][1] = 448.0f;
        vertices[4][2] = depth;
        vertices[4][6] = reciprocal;
        vertices[4][8] = (f32)(u32)channel0;
        vertices[4][9] = (f32)(u32)channel1;
        vertices[4][10] = (f32)(u32)channel2;
        vertices[4][11] = 0.0f;
        vertices[5][0] = 0.0f;
        vertices[5][1] = 29.0f;
        vertices[5][2] = depth;
        vertices[5][6] = reciprocal;
        vertices[5][8] = (f32)(u32)channel0;
        vertices[5][9] = (f32)(u32)channel1;
        vertices[5][10] = (f32)(u32)channel2;
        vertices[5][11] = 0.0f;
        D_00887310[0](3, vertices, 6);
    }
}
#pragma pop
