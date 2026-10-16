/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0020e010-0020ff00 */

#include "btl_skill_target_internal.h"
#include "list_item_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
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
extern void btlEntryListFlush(u8 *arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, const void *src, u32 size);
extern f32 fGpffff84a4;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
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
extern void btlUiSetRenderMode(s32 arg0);
extern void btlGaugeSetActive(u8 *arg0, s32 arg1);
extern void btlUiSetOrigin(u8 *arg0, f32 fparg0, f32 fparg1);
extern void btlUiSetRect(s32 *arg0, f32 fp0, f32 fp1, f32 fp2, f32 fp3);
extern void btlUiSetRenderStates(void);
extern void btlUiSetTileOffset(u8 *arg0, s16 arg1, s32 arg2, f32 fparg0);
extern void btlUiSetScale(u8 *arg0, f32 fparg0, f32 fparg1);
extern void btlUiSetFactorXY(u8 *arg0, f32 fparg0, f32 fparg1);
typedef struct BattleRenderDispatch {
    void (*setState)(u32 state, u32 value);
} BattleRenderDispatch;

extern void btlSelectionSwapRowState(u8 *arg0, u8 *arg1);
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: update a unit's target flag and dispatch the target draw for its mode. [inferred]
// FUN_0020E010
void btlSelectionDispatchTargetMode(s32 arg0, u8 *arg1, u8 *arg2)
{
    extern void btlUnitGetAttachedSphereCenter(u8 *arg0, f32 *arg1);
    extern s32 btlTargetFindInRange(f32 *arg0, f32 *arg1);
    extern void btlUiSetOrigin(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void btlPanelCursorDrawA(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void btlPanelCursorDrawB(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void btlPanelCursorDrawC(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void btlPanelCursorDrawD(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    struct E010Frame {
        u8 pad[8];
        u8 value[4];
        u8 gap[4];
        u8 vector[12];
    } work;
    u8 *temp_16;
    u16 temp_3;
    u16 temp_4;

    temp_16 = (u8 *)kwlnTaskGetWork();
    temp_3 = *(u16 *)(arg1 + 2);
    if (temp_3 == 0) {
        if (*(u8 *)(arg2 + 0xA2) == 0) {
            *(s32 *)(arg2 + 0xA10) &= ~0x200;
        }
        return;
    }
    if (*(u8 *)(arg2 + 0xA2) != 0) {
        goto flags_done;
    }
    switch (temp_3) {
    case 1:
    case 4:
        goto flag_set;
    default:
        goto flag_clear;
    }
flag_set:
    *(s32 *)(arg2 + 0xA10) |= 0x200;
    goto flags_done;
flag_clear:
    *(s32 *)(arg2 + 0xA10) &= ~0x200;
flags_done:
    btlUnitGetAttachedSphereCenter(arg2, (f32 *)work.vector);
    if (btlTargetFindInRange((f32 *)work.vector, (f32 *)work.value) != 0) {
        btlUiSetOrigin(temp_16, 0.0f, 0.0f);
        temp_4 = *(u16 *)(arg1 + 0);
        switch (temp_4) {
        case 0:
            btlPanelCursorDrawA(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 1:
            btlPanelCursorDrawB(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 2:
            btlPanelCursorDrawC(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 3:
            btlPanelCursorDrawD(arg0, arg1, arg2, (f32 *)work.value);
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
void btlSelectionSwapRowState(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 3;
    *(u16 *)(arg0 + 0x10) &= 0xFFFE;
    *(u16 *)(arg0 + 0x10) &= 0xFFFD;
    *(s16 *)(arg1 + 4) = 0;
    *(s16 *)(arg1 + 2) = 2;
    *(u16 *)(arg1 + 0x10) &= 0xFFF7;
    *(u16 *)(arg1 + 0x10) &= 0xFFFB;
    *(u16 *)(arg1 + 0x10) &= 0xFFFD;
    *(u16 *)(arg1 + 0x10) |= 1;
    *(Vec2f *)(arg1 + 8) = *(Vec2f *)(arg0 + 8);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: queue a new entry at the head of the selection entry list. [inferred]
// FUN_0020E250
void btlSelectionPushEntry(u8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, u16 arg4)
{
    u8 *state;
    u8 **list;
    u8 *node;
    u8 *new_node;
    u8 *allocated;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;

    state = (u8 *)kwlnTaskGetWork(arg0);
    list = (u8 **)(state + 0x75C);
    if (*(s32 *)arg2 != 0 || *(s32 *)(arg2 + 1) != 0 ||
        *(u16 *)((u8 *)arg2 + 8) != 0) {
        chkmemAllocSiteTag(&D_00626C30, 0x3A);
        allocated = (u8 *)jtbl_008873E8[0](0x28, 0x40000);
        new_node = allocated;
        temp_f2 = arg3[0];
        temp_f1 = arg3[1];
        temp_f0 = arg3[2];
        *(f32 *)(new_node + 4) = temp_f2;
        *(f32 *)(new_node + 8) = temp_f1;
        *(f32 *)(new_node + 0xC) = temp_f0;
        memcpy(new_node + 0x18, arg2, 0xC);
        *(s32 *)(new_node + 0x10) = 0;
        *(u16 *)(new_node + 0x14) = arg4;
        *(s32 *)new_node = arg1;
        *(u16 *)(new_node + 0x14) |= 1;
        *(u16 *)(*(u8 **)new_node + 0xA0) += 1;
        for (node = *(u8 **)list; node != NULL; node = *(u8 **)(node + 0x24)) {
            if ((*(u16 *)(node + 0x20) & 0xF) == 0 &&
                *(s32 *)node == arg1) {
                if ((*(u16 *)(node + 0x14) & 2) == 0) {
                    *(s32 *)(node + 0x10) = 0;
                    *(u16 *)(node + 0x14) |= 2;
                }
                if ((*(u16 *)(new_node + 0x14) & 4) == 0) {
                    temp_f2 = *(f32 *)(node + 4);
                    temp_f1 = *(f32 *)(node + 8);
                    temp_f0 = *(f32 *)(node + 0xC);
                    *(f32 *)(new_node + 4) = temp_f2;
                    *(f32 *)(new_node + 8) = temp_f1;
                    *(f32 *)(new_node + 0xC) = temp_f0;
                    *(u16 *)(new_node + 0x14) |= 4;
                }
            }
        }
        *(u8 **)(new_node + 0x24) = *(u8 **)list;
        *(u8 **)list = new_node;
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
void btlSelectionDrawValue(u8 *arg0, f32 fparg0, f32 fparg1, s32 arg1, s32 arg2, u32 arg3)
{
    extern s32 iGpffffa580;
    extern void sprintf(void *arg0, const char *arg1, ...);
    extern s32 strlen(const void *arg0);
    u8 sp90[0x40];
    u64 c0;
    u8 channel0;
    u64 c1;
    u8 channel1;
    u64 c2;
    u8 channel2;
    u64 c3;
    u8 channel3;
    s32 count;
    s32 i;

    c3 = (s8)(u8)((arg3 & 0xFF000000) >> 24);
    c2 = (s8)(u8)((arg3 & 0x00FF0000) >> 16);
    c1 = (s8)(u8)((arg3 & 0x0000FF00) >> 8);
    c0 = (s8)(u8)(arg3 & 0x000000FF);
    if (c0 != 0) {
        sprintf(sp90, (const char *)&iGpffffa580, arg1);
        count = strlen(sp90);
        if (arg2 != 0) {
            fparg0 = fparg0 - (f32)count * 9.5f;
            fparg1 -= 11.0f;
        }
        i = 0;
        channel0 = (u8)c0;
        channel1 = (u8)c1;
        channel2 = (u8)c2;
        channel3 = (u8)c3;
        for (; i < count; i++) {
            btlUiDrawSpriteFaded(arg0, 10, (s8)sp90[i] - 0x19, fparg0, fparg1,
                          channel3, channel2, channel1, channel0);
            fparg0 += 19.0f;
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
f32 btlSelectionEaseCurve(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    f32 temp_f0;

    if (arg0 < arg1) {
        temp_f0 = 0.0f;
        goto done;
    }
    if (arg0 < arg2) {
        temp_f0 = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 1:
            temp_f0 = sinf(fGpffff84a4 * temp_f0);
            goto done;
        case 2:
            temp_f0 = 1.0f - cosf(fGpffff84a4 * temp_f0);
            goto done;
        default:
            goto done;
        }
    }
    temp_f0 = 1.0f;
done:
    return temp_f0;
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
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 stretch;
    f32 fade;
    f32 y;
    work = (u8 *)kwlnTaskGetWork(*(void **)(task + 4));
    frame = *(s32 *)(transition + 0x10);
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
    output[4] = (u8)(255.0f * fade);
    *(f32 *)output = 20.0f * (1.0f - fade);
    if (*(u16 *)(transition + 0x14) & 4) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    } else if (frame == 6) {
        btlGaugeSetActive(panel, 1);
    } else if (frame > 6) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
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
    frame = *(s32 *)(transition + 0x10);
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
    output[4] = (u8)(255.0f * fade);
    *(f32 *)output = 20.0f * (1.0f - fade);
    if (*(u16 *)(transition + 0x14) & 4) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    } else if (frame == 6) {
        btlGaugeSetActive(panel, 1);
    } else if (frame > 6) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: step the pulse transition frame and draw its ring. [inferred]
// FUN_0020F4D0
void btlTransitionStepPulse(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1)
{
    extern u32 kwlnTaskGetWork(void *arg0);
    Vec2f sp48;
    f32 temp_f1;
    f32 var_f1;
    f32 var_f20;
    u8 *temp_17;
    s32 temp_16;

    temp_17 = (u8 *)kwlnTaskGetWork(*(void **)(arg0 + 4));
    temp_16 = *(s32 *)(arg1 + 0x10);
    if (temp_16 < 0) {
        var_f20 = 0.0f;
    } else if (temp_16 < 6) {
        var_f20 = (f32)temp_16 / 6.0f;
    } else {
        var_f20 = 1.0f;
    }
    if (!(var_f20 <= 0.0f)) {
        sp48.x = 86.0f + fparg0;
        sp48.y = 86.0f + fparg1;
        if (var_f20 == 1.0f) {
            shdDrawRotatedRect(sp48, 0.0f, 0x151515FF, 87.0f,
                          16.0f, fGpffff815c, 1);
        }
        temp_f1 = 2.0f - var_f20;
        shdDrawRotatedRect(sp48, 0.0f, 0xFF0F02FF,
                      87.0f * temp_f1, 16.0f * temp_f1,
                      fGpffff83b0, 1);
    }
    if (temp_16 < 7) {
        var_f1 = 0.0f;
    } else if (temp_16 < 7) {
        var_f1 = (f32)(temp_16 - 7) / 0.0f;
    } else {
        var_f1 = 1.0f;
    }
    if (!(var_f1 <= 0.0f)) {
        btlUiSetTileOffset(temp_17, 0x1C, 8, -30.0f);
        btlUiDrawSpriteFaded(temp_17, 0xA, 6, 58.0f, 78.0f,
                      0x15, 0x15, 0x15, 0xFF);
        btlUiSetTileOffset(temp_17, 0, 0, 0.0f);
    }
}
#pragma pop

extern f32 fGpffff8210;
f32 btlUiSpriteWidth(u8 *arg0, s32 arg1, s32 arg2);
f32 btlUiSpriteHeight(u8 *arg0, s32 arg1, s32 arg2);
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

    if (index != 0) {
        scaleY = fGpffff8210 * *(f32 *)(state + 8);
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
        if (index < *(s16 *)(state + 2)) {
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
    extern void btlPanelDrawIndexed(u8 *work, u8 *state, s32 color, s32 index);
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
    extent = *(f32 *)(state + 8);
    if (extent == 0.0f) return;
    btlUiSetRenderStates();
    if (*(s16 *)(state + 4) & 4) {
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
    extern f32 cosf(f32 fparg0);
    extern f32 sinf(f32 fparg0);
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
