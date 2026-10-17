/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0013ad40-0013f620 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
extern s32 radarSkillEffectMissing(s16 arg0, s16 arg1, s32 arg2);
extern s32 func_0013f720(s16 arg0, s16 arg1, s32 arg2, u8 *arg3);
extern s32 nLineIsIdle(void);
struct GDataEntry;

extern struct GDataEntry *datEntryAt(s16 arg0);
extern u32 datEntryGetFlags(s16 arg0);
extern s32 datCalcSkillEffectFlagsById(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}

extern u16 func_0010f8c0(s32 arg0);
extern s32 titleSetMenuLayout(u8 *arg0, u32 arg1);
extern s32 nLineSelectSet(s32 arg0);
extern s32 radarEntryTypeIsActive(s16 arg0);
extern s32 func_0010f540(s32 arg0);
extern void shdPersonaSetFlags(u8 *arg0, s32 arg1);
extern void shdPersonaClearFlags(u8 *arg0, s32 arg1);
extern void shdPersonaRefreshDispCtlPosition(u8 *arg0, void *arg1);
extern void shdPersonaSetChildDispCtlHandleAndColor(u8 *arg0, s32 arg1, s32 arg2);
extern void sdkListStateConfigure(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetActive(void *arg0, s32 arg1);
extern void sdkListStateSetSecondaryMasks(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 sdkListStateHandleInput(u8 *arg0);
extern void cmpPersonaSetSelection(u8 *arg0, s32 arg1, s32 arg2);
extern void shdPersonaBeginDisplay(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern void datPersonaSetLeadSlot(s16 arg0);
extern s32 datCalcThresholdTriggerById(s16 arg0, u32 arg1);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern s32 radarEntryIsAllowed(s16 arg0, s32 arg1, u8 *arg2);
extern s32 cmpSkillSetSelection(s16 *arg0, s32 arg1, s32 arg2);
extern s32 cmpSkillSetMode(u8 *arg0, s32 arg1);
extern void cmpSkillSetScrollCursorMotion(u8 *arg0);
extern void cmpEquipSetSelection(u8 *arg0, s32 arg1, s32 arg2);
extern void cmpEquipBuildItemList(u8 *arg0);
extern void cmpEquipSetMode(u8 *arg0, s32 arg1);
extern void radarBeginSlideOut(u8 *arg0);
extern void radarBeginSlideIn(u8 *arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern s32 datItemCount(s16 arg0);
extern void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
extern void radarResetAndSetIndices(u8 *arg0, s16 arg1, s16 arg2);
extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void datPanelResetCursor(u8 *arg0);
extern void datPanelDrawByKind(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern s32 datCalcGetLevelById(s32 arg0);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void datEntryDrawByKind(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4);
extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void titleStateInit(u8 *arg0);
extern s32 titleAdvanceWait(u8 *arg0);
extern s32 radarPushHistoryValue(s32 arg0, s32 arg1, s32 arg2);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datCommunityCursorFeedback(s32 arg0);
extern s32 nLineSelectSetImmediate(s32 arg0);
extern s32 radarAdvanceGroupSelection(u8 *arg0);
extern s32 radarApplyItemStep(s16 arg0, s16 arg1, u8 *arg2);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern void radarHandleEntrySelect(s32 *arg0, u8 *arg1);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2F4[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
extern u8 D_0064B30C[];
extern void datSetFlag(s32 arg0, s32 arg1);
extern void datCalcApplySkillEffectById(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
extern s32 FldStepNotAtBoundaryQuery(void);
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_005ED9E0[];
typedef struct {
    s32 first;
    s32 second;
} code13Pair;

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Draw one radar entry row from the first group (slots 5 and 1) or the second group (slots 0x1C and 0x18) [inferred]
// FUN_0013AD40
void radarDrawEntryRowGroup(u8 *arg0, s32 arg1, s32 arg2)
{
    typedef struct
    {
        s16 id;
        s16 pad2;
        s16 unk4;
        s16 highlight;
        s32 mode;
    } LabelParam;
    typedef struct
    {
        f32 x;
        f32 y;
        u8 pad8[2];
        u8 alpha;
        u8 padB[0x25];
    } LabelSlot;
    s32 id;
    s32 highlight;
    u8 *color0;
    u8 *color1;
    u8 *color2;
    s16 n;
    u8 alpha;
    f32 dim;
    f32 fade;
    f32 x;
    f32 y;
    f32 yoff;
    f32 ty;
    s32 slot;
    s32 slot2;
    LabelParam param;
    Vec2f pos;
    void *spr;
    s32 selected;

    highlight = 0;
    dim = 1.0f;
    id = ((s16 *)(arg0 + 0xF4))[arg1];
    x = *(f32 *)(arg0 + 4);
    y = *(f32 *)(arg0 + 8);
    fade = (f32)*(u8 *)arg0 / 255.0f;
    datPanelResetCursor((u8 *)&param);
    param.mode = 1;
    param.id = id;
    selected = ((s16 *)(arg0 + 0x5C))[arg2];
    if (selected == arg1 || (*(s32 *)(arg0 + 0x1C) & 0x100) != 0) {
        if (arg2 == 0 && (*(s32 *)(arg0 + 0x1C) & 0x10) != 0) {
            param.highlight = 2;
            color0 = D_0064B2F4;
            color1 = D_0064B2F0;
            color2 = D_0064B30C;
        } else {
            highlight = 1;
            param.highlight = highlight;
            color0 = D_0064B2E8;
            color1 = D_0064B2EC;
            color2 = D_0064B2FC;
        }
    } else {
        param.highlight = 0;
        color0 = D_0064B2E0;
        color1 = D_0064B2F0;
        color2 = D_0064B308;
        dim = fGpffff82cc;
    }
    if (arg2 == 0) {
        slot = 5;
        slot2 = 1;
    } else {
        slot = 0x1C;
        slot2 = 0x18;
    }
    pos.x = 67.0f + (x + ((LabelSlot *)(arg0 + 0x594))[slot + arg1].x);
    yoff = 75.0f * (f32)arg1;
    ty = 24.0f + (y + ((LabelSlot *)(arg0 + 0x594))[slot + arg1].y);
    pos.y = ty + yoff;
    ty = ((LabelSlot *)(arg0 + 0x594))[slot + arg1].alpha;
    datPanelDrawByKind(pos, 0.0f, (u8)(ty * fade), (u8 *)&param, 0);
    alpha = (f32)(arg0 + 0x59E)[(slot2 + arg1) * 0x30] * fade;
    pos.x = 60.0f + (x + ((f32 *)(arg0 + 0x594))[(slot2 + arg1) * 12]);
    ty = y + ((f32 *)(arg0 + 0x598))[(slot2 + arg1) * 12];
    pos.y = 21.0f + (ty + yoff);
    sdkSpriteDrawAt(*(void **)(arg0 + 0x12BC), pos.x, pos.y, color0[0], color0[1], color0[2], alpha);
    if (highlight != 0) {
        pos.x = 2.0f + (x + ((f32 *)(arg0 + 0x594))[(slot2 + arg1) * 12]);
        ty = y + ((f32 *)(arg0 + 0x598))[(slot2 + arg1) * 12];
        pos.y = 27.0f + (ty + yoff);
        sdkSpriteDrawAt(*(void **)(arg0 + 0x12C0), pos.x, pos.y, 0x4C, 0x4C, 0x4C, alpha);
    }
    n = (u8)datCalcGetLevelById(id);
    pos.x = 43.0f + (x + ((f32 *)(arg0 + 0x594))[(slot2 + arg1) * 12]);
    ty = y + ((f32 *)(arg0 + 0x598))[(slot2 + arg1) * 12];
    pos.y = 25.0f + (ty + yoff);
    if (n < 10) {
        pos.x -= 11.0f;
    }
    while (n > 0) {
        sdkSpriteDrawAt(*(void **)(arg0 + (n % 10) * 4 + 0x12C4), pos.x, pos.y, color1[0], color1[1], color1[2], alpha);
        pos.x -= 22.0f;
        n /= 10;
    }
    pos.x = 37.0f + (x + ((f32 *)(arg0 + 0x594))[(slot2 + arg1) * 12]);
    ty = y + ((f32 *)(arg0 + 0x598))[(slot2 + arg1) * 12];
    pos.y = 53.0f + (ty + yoff);
    spr = *(void **)(arg0 + 0x1330);
    sdkSpriteDrawAt(spr, pos.x, pos.y, color2[0], color2[1], color2[2], (u8)((f32)alpha * dim));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw a sprite pair from the second sprite table at the given position, 340 units apart, with the given colour [inferred]
// FUN_0013B370
/* The call consumes a complete position and RGBA packet. Keep explicit
   views of their argument storage: b210 otherwise hoists the Y load before
   the RGB snapshots. All 176 instruction bytes and 42 sibling images match. */
#pragma opt_propagation off
void radarDrawSecondSpritePair(u8 *arg0, Vec2f arg1, PackedColor4 arg2)
{
    f32 c0;
    s32 p;
    u8 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1288);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    sdkSpriteDrawAt((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    sdkSpriteDrawAt(*(void **)(arg0 + 0x128c),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
/* 1480/1488 bytes; fourteen resolved relocations and eight zero tail bytes.
 * The skill renderer uses complete position/color objects and retains the
 * original Y component and sprite cursor through the draw pairs. */
// Intent: Draw one skill card: the background sprites, the bars and the value text, at the given position and alpha [inferred]
// FUN_0013B420
void radarDrawSkillCard(void *context, Vec2f inputPosition, s32 inputAlpha, void *entry)
{
    typedef union {
        f32 f;
        u8 b[4];
    } Color;
    struct {
        Color copy;
        Color current;
    } colors;
    PackedVec2f position;
    PackedVec2f palettePosition;
    f32 opacityValue;
    f32 opacityScale;
    f32 height;
    f32 originalY;
    f32 scaledAlpha;
    f32 alphaValue;
    f32 scaledInputAlpha;
    s32 alphaByte;
    s32 labelAlpha;
    u8 *sprite;
    u8 *work;

    work = context;
    originalY = inputPosition.y;
    opacityValue = (f32)(u32)*(u8 *)(work + 0);
    opacityScale = opacityValue / 255.0f;
    colors.current.b[0] = 0x14;
    colors.current.b[1] = 0x14;
    colors.current.b[2] = 0x14;
    scaledAlpha = 204.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    height = (f32)(u32)*(u16 *)(work + 0xBAA);
    position.xy.x = inputPosition.x - 1.0f;
    inputPosition.y = 24.0f;
    inputPosition.y += originalY;
    position.xy.y = inputPosition.y;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = *(u8 **)(work + 0x1324);
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawSized(sprite, position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
        sprite = *(u8 **)(work + 0x1328);
        sdkSpriteDrawSized(sprite, (f32)0x159 + position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
    }
    {
        f32 x;
        x = 5.0f + inputPosition.x;
        x += *(f32 *)(work + 0xC84);
        position.xy.x = x;
    }
    {
        f32 y;
        y = 34.0f + originalY;
        y += *(f32 *)(work + 0xC88);
        position.xy.y = y;
    }
    colors.current.b[0] = 0x68;
    colors.current.b[1] = 0x68;
    colors.current.b[2] = 0x68;
    alphaValue = (f32)(u32)inputAlpha;
    scaledInputAlpha = alphaValue * opacityScale;
    colors.current.b[3] = scaledInputAlpha;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = *(u8 **)(work + 0x131C);
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawAt(sprite, position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
        sdkSpriteDrawAt(*(void **)(work + 0x1320), 330.0f + position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
    }
    position.xy.x = inputPosition.x;
    position.xy.y = originalY;
    colors.current.b[0] = D_0064B2E8[0];
    colors.current.b[1] = D_0064B2E8[1];
    colors.current.b[2] = D_0064B2E8[2];
    scaledAlpha = 255.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    colors.copy.f = colors.current.f;
    palettePosition.packed = position.packed;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = *(u8 **)(work + 0x1288);
        alpha = colors.copy.b[3];
        blue = colors.copy.b[2];
        green = colors.copy.b[1];
        y = palettePosition.xy.y;
        sdkSpriteDrawAt(sprite, palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
        sprite = *(u8 **)(work + 0x128C);
        sdkSpriteDrawAt(sprite, 340.0f + palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
    }
    position.xy.x = position.xy.x - 2.0f;
    datEntryDrawByKind(position.xy, colors.current.b[3], entry, 1, 0.0f);
    position.xy.x = 22.0f + inputPosition.x;
    position.xy.y = 54.0f + originalY;
    labelAlpha = (u8)scaledInputAlpha;
    itfMesWindowDrawDefaultEntry((f32)(s32)position.xy.x, (f32)(s32)position.xy.y, 0.0f,
                  (labelAlpha & 0xFF) | ~0xFF, 1, 8, *(u16 *)((u8 *)entry + 0xA));
}
#pragma pop

static inline s32 code13GroupBefore(u8 *arg0, s32 index)
{
    u32 selected;
    selected = datEntryGetFlags(*(s16 *)(code13AddOff((index - 1) * 4, arg0) + 0x3E));
    index = index - 1;
    while (index > 0) {
        if (datEntryGetFlags(*(s16 *)(arg0 + index * 4 + 0x3A)) != selected) break;
        index--;
    }
    return index;
}

static inline s32 code13GroupBeforeOrSame(u8 *arg0, s32 total)
{
    if (total == 0) {
        return total;
    } else {
        return code13GroupBefore(arg0, total);
    }
}

static inline s32 code13GroupAfter(u8 *arg0, s32 total, s32 count, s32 wrap)
{
    s32 index;
    u32 selected;
    selected = datEntryGetFlags(*(s16 *)(code13AddOff(total * 4, arg0) + 0x3E));
    index = total + 1;
    while (index < count) {
        if (datEntryGetFlags(*(s16 *)(arg0 + index * 4 + 0x3E)) != selected) break;
        index++;
    }
    if (index >= count) index = wrap;
    return index;
}

static inline s32 code13SelectionSum(s32 row, s32 column)
{
    return row + column;
}

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Advance the group selection to the neighbour chosen by the button bits, and update the two group windows [inferred]
// FUN_0013B9F0
s32 radarAdvanceGroupSelection(u8 *arg0)
{
    s32 count;
    s32 index;
    s32 total;
    s32 low;
    s32 high;

    count = *(s16 *)(arg0 + 0xC3E);
    if (count < 2) return 0;
    {
        s32 column = *(s16 *)(arg0 + 0x24);
        s32 row = *(s16 *)(arg0 + 0x22);
        total = code13SelectionSum(row, column);
    }
    if (D_008C024E[0] & 4) {
        index = total;
        if (total == 0) index = count;
        index = code13GroupBefore(arg0, index);
        goto process;
    }
    if (D_008C024E[0] & 8) {
        index = code13GroupAfter(arg0, total, count, 0);
        goto process;
    }
    if (D_008C0252[0] & 4) {
        index = code13GroupBeforeOrSame(arg0, total);
        goto process;
    }
    if (D_008C0252[0] & 8) {
        index = code13GroupAfter(arg0, total, count, total);
        goto process;
    }
    return 0;
process:
    if (total == index) return 0;
    if (count < 7) {
        low = 0;
        high = (s16)index;
    } else {
        s32 threshold = count - 6;
        if (index >= threshold) {
            low = (s16)threshold;
            high = (s16)(index - low);
        } else {
            low = (s16)index;
            high = 0;
        }
    }
    radarPushHistoryValue((s32)arg0, 0, (s16)high);
    radarPushHistoryValue((s32)arg0, 1, (s16)low);
    return 1;
}
#pragma pop

s32 radarEntriesCoverValue(u8 *arg0);
void radarFreeSpriteNodes(u8 *arg0);
void radarPushSlotState(u8 *arg0);
void radarResetIndicator(u8 *arg0);

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Item-use menu state machine: step the item selection, apply the chosen item to its recipients, and return the menu's result [inferred]
// FUN_0013BCF0
s32 radarItemMenuUpdate(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern s32 radarPushHistoryValue(s32 arg0, s32 arg1, s32 arg2);
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_16;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_2;
    s32 var_3;
    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        *arg1 = 0;
        titleStateInit(arg2);
        *arg0 = 1;
        break;
    case 1:
        temp_16 = titleAdvanceWait(arg2);
        if (temp_16 & nLineIsIdle()) {
            *arg0 = 3;
            nLineSelectSet(0xB);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (radarEntriesCoverValue(arg2) != 0) {
            radarFreeSpriteNodes(arg2);
            return 1;
        }
        break;
    case 3:
        if (radarEntriesCoverValue(arg2) != 0) {
            titleSetMenuLayout(arg2, 3);
            *arg0 = 4;
            resrcMngSuppressRender();
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(arg2, 1);
            *arg0 = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0xD);
            sdkSndStartStream(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            radarHandleEntrySelect((s32 *)arg0, arg2);
            *(s32 *)(arg2 + 0xC44) = 0;
        } else if ((D_008C024E[0] & 0x80) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            titleSetMenuLayout(arg2, 8);
            *arg0 = 5;
            *(s32 *)(arg2 + 0xC44) = 1;
            sdkSndStartStream(0, 2, 0, 3);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xB;
        } else if (radarAdvanceGroupSelection(arg2) != 0) {
            sdkSndStartStream(0, 1, 0, 5);
        } else {
            sdkListStateConfigure(buf, 6, *(s16 *)(arg2 + 0xC3E), *(s16 *)(arg2 + 0x22), *(s16 *)(arg2 + 0x24));
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_2 = sdkListStateHandleInput(buf)) > 0) {
                radarPushHistoryValue((s32)arg2, 0, *(s32 *)(buf + 0x24));
                radarPushHistoryValue((s32)arg2, 1, *(s32 *)(buf + 0x28));
                if (*(s16 *)(arg2 + 0x24) != *(s16 *)(arg2 + 0x2A)) {
                    radarResetIndicator(arg2);
                }
                datCommunityCursorFeedback(temp_2_2);
            }
        }
        break;
    case 7:
        if (radarEntriesCoverValue(arg2) != 0) {
            titleSetMenuLayout(arg2, 6);
            radarPushSlotState(arg2);
            *arg0 = 8;
        }
        break;
    case 8:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(arg2, 2);
            *arg0 = 3;
            nLineSelectSetImmediate(0xB);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            if (radarApplyItemStep(1, *(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x26) * 2) + (u32)arg2) + 0x34), arg2) == 2) {
                titleSetMenuLayout(arg2, 2);
                *arg0 = 3;
                nLineSelectSetImmediate(0xB);
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xB;
        } else {
            sdkListStateConfigure(buf, 4, *(s16 *)(arg2 + 0x3C), *(s16 *)(arg2 + 0x26), 0);
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(buf) != 0) {
                radarPushHistoryValue((s32)arg2, 2, *(s32 *)(buf + 0x24));
                radarPushSlotState(arg2);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 9:
        if (radarEntriesCoverValue(arg2) != 0) {
            titleSetMenuLayout(arg2, 7);
            *arg0 = 0xA;
        }
        break;
    case 10:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(arg2, 2);
            *arg0 = 3;
            nLineSelectSetImmediate(0xB);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            {
                s32 inner = radarApplyItemStep(1, -1, arg2);
                switch (inner) {
                case 2:
                    titleSetMenuLayout(arg2, 2);
                    *arg0 = 3;
                    nLineSelectSetImmediate(0xB);
                    break;
                case 3:
                    return 2;
                default:
                    break;
                }
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xB;
        }
        break;
    case 5:
        if (radarEntriesCoverValue(arg2) != 0) {
            titleSetMenuLayout(arg2, 9);
            *arg0 = 6;
        }
        break;
    case 6:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            titleSetMenuLayout(arg2, 2);
            *arg0 = 3;
            sdkSndStartStream(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            radarHandleEntrySelect((s32 *)arg0, arg2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xB;
        } else if (radarAdvanceGroupSelection(arg2) != 0) {
            sdkSndStartStream(0, 1, 0, 5);
        } else {
            sdkListStateConfigure(buf, 6, *(s16 *)(arg2 + 0xC3E), *(s16 *)(arg2 + 0x22), *(s16 *)(arg2 + 0x24));
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_3 = sdkListStateHandleInput(buf)) > 0) {
                radarPushHistoryValue((s32)arg2, 0, *(s32 *)(buf + 0x24));
                radarPushHistoryValue((s32)arg2, 1, *(s32 *)(buf + 0x28));
                if (*(s16 *)(arg2 + 0x24) != *(s16 *)(arg2 + 0x2A)) {
                    radarResetIndicator(arg2);
                }
                datCommunityCursorFeedback(temp_2_3);
            }
        }
        break;
    case 11:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            var_2 = 1;
        } else {
            temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            var_3 = (u8)temp_f1;
            *(u8 *)arg2 = var_3;
            var_2 = 0;
        }
        if (var_2 != 0) {
            return 2;
        }
        break;
    default:
        break;
    }
    return 0;
}
#pragma pop

void radarPushSlotState(u8 *arg0);

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Handle a selected entry: when its type is active, set the state by type (0 becomes 7, 1 or 2 become 9) and play the cue; otherwise play cue 8 [inferred]
// FUN_0013C5A0
void radarHandleEntrySelect(s32 *arg0, u8 *arg1) {
    u8 *entry;
    s16 type;

    entry = code13AddOff((*(s16 *)(arg1 + 0x24) + *(s16 *)(arg1 + 0x22)) * 4,
                         arg1) + 0x3E;
    if (radarEntryTypeIsActive(*(s16 *)entry) == 0) {
        sdkSndStartStream(0, 0, 0, 8);
        return;
    }
    type = (s16)func_0010f8c0(*(u16 *)((u8 *)datEntryAt(*(s16 *)entry) + 0x24));
    if (type == 0) {
        titleSetMenuLayout(arg1, 4);
        radarPushSlotState(arg1);
        *arg0 = 7;
    } else {
        if ((type == 2) || (type == 1)) {
            titleSetMenuLayout(arg1, 5);
            *arg0 = 9;
        }
    }
    nLineSelectSet(0xC);
    sdkSndStartStream(0, 0, 0, 1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Return whether the type of the entry's item is active [inferred]
// FUN_0013C6D0
s32 radarEntryTypeIsActive(s16 arg0) {
    return func_0010f540(*(u16 *)((u8 *)datEntryAt(arg0) + 0x24)) != 0;
}
#pragma pop

s32 radarCollectPartyChanges(u8 *arg0);
void radarReleaseSpritesAndEntries(u8 *arg0);
void radarResetLayout(u8 *arg0);
s32 radarWideEntriesCoverValue(u8 *arg0);

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Transfer menu state machine: step the party-change and unit-transfer states, and return the menu's result [inferred]
// FUN_0013CAA0
s32 radarTransferMenuUpdate(u32 *arg0, s32 *arg1, u8 *arg2) {
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_16;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_2;
    s32 var_3;

    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        *arg1 = 0;
        cmpEquipMenuInit(arg2);
        *arg0 = 1;
        break;
    default:
        break;
    case 1:
        temp_16 = (s32)(cmpEquipStateStep(arg2));
        if (temp_16 & nLineIsIdle()) {
            *arg0 = 4;
            nLineSelectSet(3);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        temp_4 = (s32)(*(s32 *)(arg2 + 0x1594));
        if ((temp_4 == 0) || (kwlnTaskIsLinked(temp_4) == 0)) {
            *arg0 = 3;
            cmpEquipSetMode(arg2, 1);
            resrcMngUnsuppressRender();
            nLineSelectSet(7);
        case 3:
            if (radarWideEntriesCoverValue(arg2) != 0) {
                radarReleaseSpritesAndEntries(arg2);
                return 1;
            }
            break;
        }
        break;
    case 4:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            resrcMngSuppressRender();
            cmpEquipSetMode(arg2, 2);
            *arg0 = 5;
        }
        break;
    case 5:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                *arg0 = 2;
                radarCollectPartyChanges(arg2);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                cmpEquipSetMode(arg2, 3);
                *arg0 = 7;
                nLineSelectSet(4);
                sdkSndStartStream(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x10) {
                radarCollectPartyChanges(arg2);
                *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
                *arg0 = 0xD;
            } else {
                sdkListStateConfigure(buf, 8, *(s16 *)(arg2 + 0x48), *(s16 *)(arg2 + 0x28), 0);
                sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(buf) != 0) {
                    cmpEquipSetSelection(arg2, 0, *(s32 *)(buf + 0x24));
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
        }
        break;
    case 6:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            cmpEquipSetMode(arg2, 4);
            *arg0 = 7;
        }
        break;
    case 7:
        if (D_008C024E[0] & 0x20) {
            cmpEquipSetSelection(arg2, 1, 0);
            cmpEquipSetMode(arg2, 2);
            *arg0 = 5;
            nLineSelectSetImmediate(3);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            cmpEquipSetMode(arg2, 5);
            *arg0 = 8;
            nLineSelectSet(5);
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            radarCollectPartyChanges(arg2);
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xD;
        } else {
            sdkListStateConfigure(buf, 3, 3, *(s16 *)(arg2 + 0x2A), 0);
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(buf) != 0) {
                cmpEquipSetSelection(arg2, 1, *(s32 *)(buf + 0x24));
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 8:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            cmpEquipSetMode(arg2, 6);
            *arg0 = 9;
            nLineSelectSet(6);
        }
        break;
    case 9:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            cmpEquipSetMode(arg2, 7);
            *arg0 = 0xA;
        }
        break;
    case 10:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            if (D_008C024E[0] & 0x40) {
                if (*(s16 *)(arg2 + 0xC46) != 0) {
                    radarTransferSelectedUnit(arg2);
                }
            } else if (D_008C024E[0] & 0x20) {
                cmpEquipSetSelection(arg2, 2, 0);
                cmpEquipSetSelection(arg2, 3, 0);
                cmpEquipSetMode(arg2, 4);
                *arg0 = 6;
                nLineSelectSetImmediate(4);
                sdkSndStartStream(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                radarCollectPartyChanges(arg2);
                *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
                *arg0 = 0xD;
            } else if (D_008C024E[0] & 0x80) {
                if (*(s16 *)(arg2 + 0xC46) != 0) {
                    cmpEquipSetMode(arg2, 8);
                    *arg0 = 0xB;
                    sdkSndStartStream(0, 2, 0, 3);
                }
            } else if (radarBeginPickList(arg2, arg0) == 0) {
                sdkListStateConfigure(buf, 5, *(s16 *)(arg2 + 0xC46), *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
                sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
                if ((temp_2_2 = sdkListStateHandleInput(buf)) > 0) {
                    cmpEquipSetSelection(arg2, 2, *(s32 *)(buf + 0x28));
                    cmpEquipSetSelection(arg2, 3, *(s32 *)(buf + 0x24));
                    if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                        radarResetLayout(arg2);
                    }
                    datCommunityCursorFeedback(temp_2_2);
                }
            }
        }
        break;
    case 11:
        if (radarWideEntriesCoverValue(arg2) != 0) {
            cmpEquipSetMode(arg2, 9);
            *arg0 = 0xC;
        }
        break;
    case 12:
        if (D_008C024E[0] & 0x40) {
            if (radarTransferSelectedUnit(arg2) != 0) {
                *arg0 = 9;
            }
        } else if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            cmpEquipSetMode(arg2, 7);
            *arg0 = 9;
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            radarCollectPartyChanges(arg2);
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 0xD;
        } else if (radarBeginPickList(arg2, arg0) == 0) {
            sdkListStateConfigure(buf, 5, *(s16 *)(arg2 + 0xC46), *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_3 = sdkListStateHandleInput(buf)) > 0) {
                cmpEquipSetSelection(arg2, 2, *(s32 *)(buf + 0x28));
                cmpEquipSetSelection(arg2, 3, *(s32 *)(buf + 0x24));
                if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                    radarResetLayout(arg2);
                }
                datCommunityCursorFeedback(temp_2_3);
            }
        }
        break;
    case 13:
        temp_4_2 = (s32)(*(s32 *)(arg2 + 0x1594));
        if ((temp_4_2 == 0) || (kwlnTaskIsLinked(temp_4_2) == 0)) {
            if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
                var_2 = 1;
            } else {
                temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
                var_3 = (u8)temp_f1;
                *(u8 *)arg2 = var_3;
                var_2 = 0;
            }
            if (var_2 != 0) {
                return 2;
            }
            break;
        }
        break;
    }
    return 0;
}
#pragma pop

void radarRandomizeEntries(u8 *arg0);

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Apply the selected item to the chosen recipients, consume one use, and update the row; return the resulting state [inferred]
// FUN_0013C700
s32 radarApplyItemStep(s16 arg0, s16 arg1, u8 *arg2)
{
    extern void titleCollectFlaggedIds(u8 *arg0);
    extern u8 D_005ED9D0[];
    s32 state;
    s16 item;
    s32 item_type;
    s16 remaining;
    s32 total;
    s32 updated;
    u8 *entry;

    state = 1;
    total = *(s16 *)(arg2 + 0x24) + *(s16 *)(arg2 + 0x22);
    item = ((s16 *)(arg2 + 0x3E))[total * 2];
    item_type = *(u16 *)((u8 *)datEntryAt(item) + 0x24);
    if (item_type == 246) {
        if (FldStepNotAtBoundaryQuery() != 0) state = 3;
        else state = 0;
    } else if (arg1 == -1) {
        s32 index_count;
        s32 index;
        u8 *recipient;
        index_count = 0;
        index = 0;
        while (index < *(s16 *)(arg2 + 0x3C)) {
            recipient = arg2 + index * 2 + 0x34;
            if (radarSkillEffectMissing(arg0, *(s16 *)recipient, item_type) != 0) {
                datCalcApplySkillEffectById(arg0, *(s16 *)recipient, item_type, 1);
                index_count++;
            }
            index++;
        }
        if (index_count == 0) state = 0;
    } else if (radarSkillEffectMissing(arg0, arg1, item_type) != 0) {
        datCalcApplySkillEffectById(arg0, arg1, item_type, 1);
    } else state = 0;
    if (state > 0) {
        updated = (s16)(datItemCount(item) & 0xff) - 1;
        if (updated < 0) kAssertFail(D_005ED9D0, 0x29c);
        datItemSetCount(item, updated & 0xff);
        if (state == 3) {
            datSetFlag(5121, 1);
        } else {
            radarRandomizeEntries(arg2);
            entry = code13AddOff((u32)total * 4U, arg2);
            remaining = --*(s16 *)(entry + 0x40);
            if (remaining == 0) {
                s32 selection;
                titleCollectFlaggedIds(arg2);
                selection = *(s16 *)(arg2 + 0xc3e);
                if (selection < 6) {
                    radarPushHistoryValue((s32)arg2, 1, 0);
                    selection = *(s16 *)(arg2 + 0xc3e) - 1;
                    if (selection < *(s16 *)(arg2 + 0x22)) radarPushHistoryValue((s32)arg2, 0, selection);
                } else {
                    selection -= 6;
                    if (selection < *(s16 *)(arg2 + 0x24)) radarPushHistoryValue((s32)arg2, 1, selection);
                }
                state = 2;
            }
        }
    }
    switch (state) {
    case 0:
        sdkSndStartStream(0, 0, 0, 8);
        break;
    case 1:
    case 2:
        sdkSndStartStream(1, 3, 2, 22);
        break;
    case 3:
        break;
    default:
        kAssertFail(D_005ED9D0, 0x2ca);
        break;
    }
    return state;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Return 1 when the skill effect for the recipient is not yet applied [inferred]
// FUN_0013CA60
s32 radarSkillEffectMissing(s16 arg0, s16 arg1, s32 arg2) {
    s32 v = 0;

    if (datCalcSkillEffectFlagsById(arg0, arg1, arg2, 1) == 0) {
        v = 1;
    }
    return v;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Open the pick list when it has entries: set state 10 and initialise its groups; return 1 when opened [inferred]
// FUN_0013D470
s32 radarBeginPickList(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    sdkListStateConfigure(sp40, 8, *(s16 *)(arg0 + 0x48), *(s16 *)(arg0 + 0x28), 0);
    sdkListStateSetActive(sp40, 0);
    sdkListStateSetSecondaryMasks(sp40, 8, 4, 0, 0);
    temp_2 = sdkListStateHandleInput(sp40);
    if (temp_2 > 0) {
        cmpEquipSetSelection(arg0, 0, *(s32 *)(sp40 + 0x24));
        cmpEquipSetSelection(arg0, 3, 0);
        cmpEquipSetSelection(arg0, 2, 0);
        cmpEquipBuildItemList(arg0);
        cmpEquipSetMode(arg0, 7);
        *arg1 = 0xA;
        if (temp_2 == 1) {
            radarBeginSlideOut(arg0);
        } else if (temp_2 == 2) {
            radarBeginSlideIn(arg0);
        }
        sdkSndStartStream(0, 1, 0, 5);
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Transfer one unit of the selected entry to the target entry, refresh the rows, and step the cursor; return 1 when a transfer happened [inferred]
// FUN_0013D5D0
s32 radarTransferSelectedUnit(u8 *arg0) {
    struct {
        s16 value;
    } temp_16;
    s16 temp_19;
    s16 temp_18;
    s16 temp_2;
    s32 temp_6;
    s32 temp_6_2;
    s16 temp_17;

    temp_18 = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x28) * 2, arg0) + 0x38);
    temp_19 = *(s16 *)(code13AddOff((*(s16 *)(arg0 + 0x2C) +
                                     *(s16 *)(arg0 + 0x2E)) * 4, arg0) + 0x4A);
    temp_16.value = *(s16 *)(arg0 + 0x2A);
    temp_17 = (s16)func_00106cd0(temp_18, temp_16.value);
    if (temp_19 == temp_17) {
        sdkSndStartStream(0, 0, 0, 8);
        return 0;
    }
    cmpEquipSetMode(arg0, 7);
    radarResetAndSetIndices(arg0, temp_17, temp_19);
    if ((datItemCount(temp_17) & 0xFF) != 0x63) {
        datItemSetCount(temp_17, ((datItemCount(temp_17) & 0xFF) + 1) & 0xFF);
    }
    func_00106d40(temp_18, temp_16.value, temp_19);
    datItemSetCount(temp_19, ((datItemCount(temp_19) & 0xFF) - 1) & 0xFF);
    cmpEquipBuildItemList(arg0);
    temp_2 = *(s16 *)(arg0 + 0xC46);
    if (temp_2 < 5) {
        cmpEquipSetSelection(arg0, 2, 0);
        temp_6 = *(s16 *)(arg0 + 0xC46) - 1;
        if (temp_6 < *(s16 *)(arg0 + 0x2E)) {
            cmpEquipSetSelection(arg0, 3, temp_6);
        }
    } else {
        temp_6_2 = temp_2 - 5;
        if (temp_6_2 < *(s16 *)(arg0 + 0x2C)) {
            cmpEquipSetSelection(arg0, 2, temp_6_2);
        }
    }
    sdkSndStartStream(0, 3, 0, 7);
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Set or clear the persona highlight flags and position for arg1 0 (set) or 1 (clear) [inferred]
// FUN_0013D7D0
void radarSetPersonaHighlight(u8 *arg0, s32 arg1) {
    code13Pair sp0;
    code13Pair sp1;

    switch (arg1) {
    case 0:
        sp0.first = 0x43030000;
        sp0.second = 0xC26C0000;
        shdPersonaSetFlags(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        shdPersonaRefreshDispCtlPosition(*(u8 **)(arg0 + 0x1CB4), &sp0);
        shdPersonaSetChildDispCtlHandleAndColor(*(u8 **)(arg0 + 0x1CB4), -1, -0x7F00);
        return;
    case 1:
        sp1.first = 0x43030000;
        sp1.second = 0xC2600000;
        shdPersonaClearFlags(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        shdPersonaRefreshDispCtlPosition(*(u8 **)(arg0 + 0x1CB4), &sp1);
        shdPersonaSetChildDispCtlHandleAndColor(*(u8 **)(arg0 + 0x1CB4), -1, 0xFFE92C00);
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Persona menu state machine: step the persona highlight and display states, and return the menu's result [inferred]
// FUN_0013D8B0
s32 radarPersonaMenuUpdate(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern void radarBeginRecipientPick(u8 *arg0, s32 *arg1);
    extern void cmpPersonaMenuInit(u8 *arg0);
    extern s32 cmpPersonaStateStep(u8 *arg0);
    extern s32 cmpPersonaRowsSettled(u8 *arg0);
    extern void cmpPersonaMenuRelease(u8 *arg0);
    extern void cmpPersonaSetMode(u8 *arg0, s32 arg1);
    extern void datScreenWipeSetTextureId(u8 *arg0, s32 arg1);
    extern void cmpPersonaStartScreenWipe(u8 *arg0, s32 a, s32 b, s32 c);
    extern void shdPersonaSetDisplayState(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
    extern void cmpPersonaSetPartyCursor(u8 *arg0);
    extern void cmpPersonaResetRosterCursor(u8 *arg0);
    extern void cmpPersonaScatterGridCells(u8 *arg0);
    extern void shdPersonaStartSlideIn(u8 *arg0);
    extern void radarSetPersonaHighlight(u8 *arg0, s32 arg1);
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s16 temp_17;
    s16 temp_3_2;
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_2;
    s32 var_3;

    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        cmpPersonaMenuInit(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        temp_16 = (s32)(cmpPersonaStateStep(arg2));
        if (temp_16 & nLineIsIdle()) {
            *arg0 = 3;
            nLineSelectSet(0xE);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            cmpPersonaMenuRelease(arg2);
            return 1;
        }
        break;
    case 3:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            cmpPersonaSetMode(arg2, 2);
            *arg0 = 4;
            resrcMngSuppressRender();
            datScreenWipeSetTextureId(*(u8 **)(arg2 + 0x1CB8), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24));
            cmpPersonaStartScreenWipe(*(u8 **)(arg2 + 0x1CB8), 0, 1, 0);
            shdPersonaSetDisplayState(*(u8 **)(arg2 + 0x1CB4), 0U, 0, 0);
        }
        break;
    case 4:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                cmpPersonaSetMode(arg2, 1);
                *arg0 = 2;
                resrcMngUnsuppressRender();
                nLineSelectSet(0x14);
                cmpPersonaStartScreenWipe(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (*(s16 *)(arg2 + 0x50) == 0) {
                    cmpPersonaSetMode(arg2, 3);
                    *arg0 = 5;
                    cmpPersonaSetSelection(arg2, 1, 0);
                    cmpPersonaSetPartyCursor(arg2);
                    cmpPersonaResetRosterCursor(arg2);
                    cmpPersonaScatterGridCells(arg2);
                    nLineSelectSet(0xF);
                    cmpPersonaStartScreenWipe(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                    shdPersonaSetDisplayState(*(u8 **)(arg2 + 0x1CB4), 1U, (u32)datPersonaRosterSlot(*(s16 *)(arg2 + 0x52)), 0);
                    radarSetPersonaHighlight(arg2, 1);
                    shdPersonaRefreshDispCtlPosition(*(u8 **)(arg2 + 0x1CB4), NULL);
                    shdPersonaSetFlags(*(u8 **)(arg2 + 0x1CB4), 0x40000);
                    sdkSndStartStream(0, 0, 0, 1);
                } else {
                    cmpPersonaSetMode(arg2, 8);
                    *arg0 = 0xA;
                    cmpPersonaSetPartyCursor(arg2);
                    nLineSelectSet(0x11);
                    cmpPersonaStartScreenWipe(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                    radarSetPersonaHighlight(arg2, 0);
                    shdPersonaSetDisplayState(*(u8 **)(arg2 + 0x1CB4), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24), (u32)datPersonaGetRecord(*(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24)), 0);
                    shdPersonaStartSlideIn(*(u8 **)(arg2 + 0x1CB4));
                    shdPersonaClearFlags(*(u8 **)(arg2 + 0x1CB4), 0x40000);
                }
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
                *arg0 = 0x10;
            } else {
                sdkListStateConfigure(buf, 8, *(s16 *)(arg2 + 0x34), *(s16 *)(arg2 + 0x50), 0);
                sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(buf) != 0) {
                    cmpPersonaSetSelection(arg2, 0, *(s32 *)(buf + 0x24));
                    datScreenWipeSetTextureId(*(u8 **)(arg2 + 0x1CB8), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24));
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
        }
        break;
    case 5:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            cmpPersonaSetMode(arg2, 4);
            *arg0 = 6;
            cmpPersonaResetRosterCursor(arg2);
            datScreenWipeSetTextureId(*(u8 **)(arg2 + 0x1CB8), 0U);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            cmpPersonaSetMode(arg2, 2);
            *arg0 = 3;
            nLineSelectSetImmediate(0xE);
            datPersonaRemoveSelectedRosterMember();
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            datPersonaSetLeadSlot(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
            sdkSndStartStream(1, 3, 2, 6);
            cmpPersonaRandomizeBackgroundCells(arg2);
        } else if (D_008C024E[0] & 0x80) {
            radarSetPersonaHighlight(arg2, 0);
            shdPersonaStartSlideIn(*(u8 **)(arg2 + 0x1CB4));
            cmpPersonaSetMode(arg2, 6);
            cmpPersonaSetRosterCursorMotion(arg2);
            *arg0 = 7;
            nLineSelectSet(0x10);
        } else if (D_008C024E[0] & 0x10) {
            temp_17 = (s16)(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
            if (temp_17 == func_00105330(1)) {
                nmMesWindowShowCurrentRecord(2);
                cmpPersonaSetMode(arg2, 0xC);
                *arg0 = 0xF;
                sdkSndStartStream(0, 0, 0, 8);
            } else {
                nmMesWindowShowCurrentRecord(1);
                nmMesWindowSetCurrentParam(0);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                cmpPersonaSetMode(arg2, 0xB);
                *arg0 = 0xE;
                sdkSndStartStream(0, 0, 0, 1);
            }
            cmpPersonaResetRosterCursor(arg2);
        } else {
            sdkListStateConfigure(buf, 0xC, *(s16 *)(arg2 + 0x4E), *(s16 *)(arg2 + 0x52), 0);
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if (sdkListStateHandleInput(buf) != 0) {
                cmpPersonaSetSelection(arg2, 1, *(s32 *)(buf + 0x24));
                cmpPersonaResetRosterCursor(arg2);
                shdPersonaSetDisplayState(*(u8 **)(arg2 + 0x1CB4), 1U, (u32)datPersonaRosterSlot(*(s16 *)(arg2 + 0x52)), 0);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 7:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            *arg0 = 8;
            cmpPersonaSetMode(arg2, 7);
        }
        break;
    case 8:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                cmpPersonaSetMode(arg2, 5);
                *arg0 = 5;
                cmpPersonaResetRosterCursor(arg2);
                nLineSelectSetImmediate(0xF);
                shdPersonaBeginClose(*(u8 **)(arg2 + 0x1CB4));
                radarSetPersonaHighlight(arg2, 1);
            } else if (D_008C024E[0] & 0x40) {
                cmpPersonaSetMode(arg2, 0xA);
                nmMesWindowShowCurrentRecord(3);
                nmMesWindowSetCurrentParam(0);
                nmMesWindowSetCurrentFlag(0);
                nmMesWindowRequestRefresh();
                *arg0 = 0xD;
                sdkSndStartStream(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                shdPersonaBeginSelection(*(u8 **)(arg2 + 0x1CB4));
                *arg0 = 9;
            } else if (D_008C024E[0] & 0x10) {
                datPersonaRemoveSelectedRosterMember();
                *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
                shdPersonaFinishPhase(*(u8 **)(arg2 + 0x1CB4));
                shdPersonaSetPersonaId(*(u8 **)(arg2 + 0x1CB4), 0xB1);
                *arg0 = 0x10;
            } else {
                radarBeginRecipientPick(arg2, (s32 *)arg0);
            }
        }
        break;
    case 9:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            shdPersonaEndSelection(*(u8 **)(arg2 + 0x1CB4), 1);
            *arg0 = 8;
        } else if (D_008C024E[0] & 0x40) {
            cmpPersonaSetMode(arg2, 0xA);
            shdPersonaEndSelection(*(u8 **)(arg2 + 0x1CB4), 0);
            nmMesWindowShowCurrentRecord(3);
            nmMesWindowSetCurrentParam(0);
            nmMesWindowSetCurrentFlag(0);
            nmMesWindowRequestRefresh();
            *arg0 = 0xD;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            datPersonaRemoveSelectedRosterMember();
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            shdPersonaFinishPhase(*(u8 **)(arg2 + 0x1CB4));
            shdPersonaSetPersonaId(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else {
            shdPersonaStepSelectionCursor(*(u8 **)(arg2 + 0x1CB4));
            radarBeginRecipientPick(arg2, (s32 *)arg0);
        }
        break;
    case 10:
        if (cmpPersonaRowsSettled(arg2) != 0) {
            *arg0 = 0xB;
            cmpPersonaSetMode(arg2, 7);
            datScreenWipeSetTextureId(*(u8 **)(arg2 + 0x1CB8), 0U);
        }
        break;
    case 11:
        if (D_008C024E[0] & 0x20) {
            cmpPersonaSetMode(arg2, 2);
            *arg0 = 3;
            nLineSelectSetImmediate(0xE);
            shdPersonaBeginClose(*(u8 **)(arg2 + 0x1CB4));
        } else if (D_008C024E[0] & 0x80) {
            shdPersonaBeginSelection(*(u8 **)(arg2 + 0x1CB4));
            *arg0 = 0xC;
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            shdPersonaFinishPhase(*(u8 **)(arg2 + 0x1CB4));
            shdPersonaSetPersonaId(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else {
            radarBeginCharacterPick(arg2, arg0);
        }
        break;
    case 12:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            shdPersonaEndSelection(*(u8 **)(arg2 + 0x1CB4), 1);
            *arg0 = 0xB;
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            shdPersonaFinishPhase(*(u8 **)(arg2 + 0x1CB4));
            shdPersonaSetPersonaId(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else if (radarBeginCharacterPick(arg2, arg0) == 0) {
            shdPersonaStepSelectionCursor(*(u8 **)(arg2 + 0x1CB4));
        }
        break;
    case 13:
        if ((cmpPersonaRowsSettled(arg2) != 0) && (datMemberNoticeTryBegin(1) == 0)) {
            temp_2 = nmMesWindowCurrentAnimFlag();
            switch (temp_2) {
            case 0:
                datPersonaSetLeadSlot(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
                sdkSndStartStream(1, 3, 2, 6);
                break;
            case 1:
                break;
            default:
                kAssertFail(D_005ED9E0, 0x220);
                break;
            }
            *arg0 = 7;
        }
        break;
    case 14:
        if ((cmpPersonaRowsSettled(arg2) != 0) && (datMemberNoticeTryBegin(1) == 0)) {
            temp_2_2 = nmMesWindowCurrentAnimFlag();
            switch (temp_2_2) {
            case 0:
                datPersonaRemoveRosterSlot(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
                cmpPersonaBuildRosterList(arg2);
                temp_3_2 = (s16)(*(s16 *)(arg2 + 0x4E));
                if (*(s16 *)(arg2 + 0x52) >= temp_3_2) {
                    cmpPersonaSetSelection(arg2, 1, temp_3_2 - 1);
                }
                shdPersonaSetDisplayState(*(u8 **)(arg2 + 0x1CB4), 1U, (u32)datPersonaRosterSlot(*(s16 *)(arg2 + 0x52)), 0);
                break;
            case 1:
                break;
            default:
                kAssertFail(D_005ED9E0, 0x244);
                break;
            }
            cmpPersonaResetRosterCursor(arg2);
            *arg0 = 5;
        }
        break;
    case 15:
        if (datMemberNoticeTryBegin(1) == 0) {
            cmpPersonaResetRosterCursor(arg2);
            *arg0 = 5;
        }
        break;
    case 16:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            var_2 = 1;
        } else {
            temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            var_3 = (u8)temp_f1;
            *(u8 *)arg2 = var_3;
            var_2 = 0;
        }
        if (var_2 != 0) {
            return 2;
        }
        break;
    default:
        kAssertFail(D_005ED9E0, 0x25C);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Open the recipient pick display for the chosen entry: set state 8 and begin the display for one or two picks [inferred]
// FUN_0013E7C0
void radarBeginRecipientPick(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    sdkListStateConfigure(sp40, 0xC, *(s16 *)(arg0 + 0x4E), *(s16 *)(arg0 + 0x52), 0);
    sdkListStateSetActive(sp40, 0);
    sdkListStateSetSecondaryMasks(sp40, 8, 4, 0, 0);
    temp_2 = sdkListStateHandleInput(sp40);
    if (temp_2 > 0) {
        cmpPersonaSetSelection(arg0, 1, *(s32 *)(sp40 + 0x24));
        *arg1 = 8;
        if (temp_2 == 1) {
            shdPersonaBeginDisplay(*(u8 **)(arg0 + 0x1CB4), 1, (s32)datPersonaRosterSlot(*(s16 *)(arg0 + 0x52)), 0);
            return;
        }
        if (temp_2 == 2) {
            shdPersonaBeginDisplayAndEndSelection(*(u8 **)(arg0 + 0x1CB4), 1, (s32)datPersonaRosterSlot(*(s16 *)(arg0 + 0x52)), 0);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Open the character pick display for the chosen entry, and return 1 when a pick list was opened [inferred]
// FUN_0013E8E0
s32 radarBeginCharacterPick(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;
    s32 temp_18;
    u16 character;

    sdkListStateConfigure(sp40, 8, *(s16 *)(arg0 + 0x34), *(s16 *)(arg0 + 0x50), 0);
    sdkListStateSetActive(sp40, 0);
    sdkListStateSetSecondaryMasks(sp40, 8, 4, 0, 0);
    temp_2 = sdkListStateHandleInput(sp40);
    if (temp_2 > 0) {
        cmpPersonaSetSelection(arg0, 0, *(s32 *)(sp40 + 0x24));
        *arg1 = 0xB;
        temp_18 = character = *(u16 *)(code13AddOff(*(s32 *)(sp40 + 0x24) * 2, arg0) + 0x24);
        if (temp_2 == 1) {
            shdPersonaBeginDisplay(*(u8 **)(arg0 + 0x1CB4), temp_18, (s32)datPersonaGetRecord(character), 0);
        } else if (temp_2 == 2) {
            shdPersonaBeginDisplayAndEndSelection(*(u8 **)(arg0 + 0x1CB4), temp_18, (s32)datPersonaGetRecord(character), 0);
        }
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Recipient menu state machine: step the recipient selection and entry action states, and return the menu's result [inferred]
// FUN_0013EA20
s32 radarRecipientMenuUpdate(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern void cmpSkillMenuInit(u8 *arg0);
    extern u32 datCalcIsDeadById(s16 character);
    extern s32 cmpSkillStateStep(u8 *arg0);
    extern s32 cmpSkillRowsSettled(u8 *arg0);
    extern void cmpSkillFreeSprites(u8 *arg0);
    extern void cmpSkillSetPartyCursorMotion(u8 *arg0);
    extern void cmpSkillLayoutScrollRows(void *arg0);
    extern void cmpSkillBuildAbilityList(void *arg0);
    extern void radarHandleEntryAction(s32 *arg0, s16 arg1, s32 arg2, u8 *arg3);
    u8 query[0x30];
    f32 alpha;
    s16 character;
    s32 skillRow;
    s16 recipientId;
    s32 recipientValue;
    s32 characterRow;
    s32 skillPage;
    s32 recipientRow;
    s32 skillIndex;
    s32 ready;
    s32 queryResult;
    s32 alternateQueryResult;
    s32 finished;
    s64 applicationResult;
    s64 allApplicationResult;
    s32 alphaByte;
    s32 confirm;
    s32 alternateConfirm;

    *arg1 = (finished = 1);
    characterRow = (*(s16 *)(arg2 + 0x5C));
    character = *(s16 *)(code13AddOff(characterRow * 2, arg2) + 0xF4);
    recipientRow = (*(s16 *)(arg2 + 0x62));
    recipientValue = recipientId = *(s16 *)(code13AddOff(recipientRow * 2, arg2) + 0xF4);
    skillRow = (*(s16 *)(arg2 + 0x5E));
    skillPage = (*(s16 *)(arg2 + 0x60));
    skillIndex = skillPage + skillRow;
    switch (*arg0) {
        case 0:
            *arg1 = 0;
            cmpSkillMenuInit(arg2);
            *arg0 = 1;
            break;
        case 1:
            ready = (cmpSkillStateStep(arg2));
            if (ready & nLineIsIdle()) {
                *arg0 = 3;
                nLineSelectSet(8);
                cmpSkillSetPartyCursorMotion(arg2);
            } else {
                *arg1 = 0;
            }
            break;
        case 2:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                cmpSkillFreeSprites(arg2);
                return 1;
            }
            break;
        case 3:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                resrcMngSuppressRender();
                *arg0 = 4;
                cmpSkillSetMode(arg2, 2U);
                cmpSkillSetPartyCursorMotion(arg2);
            }
            break;
        case 4:
            if (D_008C024E[0] & 0x20) {
                cmpSkillSetMode(arg2, 1U);
                *arg0 = 2;
                resrcMngUnsuppressRender();
                nLineSelectSet(0xA);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if ((s32)(datCalcIsDeadById(character)) != (s32)(0)) {
                    sdkSndStartStream(0, 0, 0, 8);
                } else {
                    cmpSkillSetMode(arg2, 3U);
                    *arg0 = 5;
                    sdkSndStartStream(0, 0, 0, 1);
                }
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = (s32)(datCommunityRequestExit());
                *arg0 = 0xD;
            } else {
                sdkListStateConfigure(query, 4, *(s16 *)(arg2 + 0xFC), characterRow, 0);
                sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
                if ((s32)(sdkListStateHandleInput(query)) != (s32)(0)) {
                    cmpSkillSetSelection((s16 *)arg2, 0, *(s32 *)(query + 0x24));
                    cmpSkillBuildAbilityList(arg2);
                    cmpSkillSetPartyCursorMotion(arg2);
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
            break;
        case 5:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                *arg0 = 6;
                cmpSkillSetMode(arg2, 4U);
            }
            break;
        case 6:
            if (D_008C024E[0] & 0x20) {
                *arg0 = 3;
                cmpSkillSetMode(arg2, 2);
                cmpSkillSetPartyCursorMotion(arg2);
                sdkSndStartStream(0, 0, 0, 2);
            } else {
                confirm = D_008C024E[0] & 0x40;
                if (confirm != 0) {
                    radarHandleEntryAction((s32 *)arg0, character, recipientValue, arg2);
                } else if (D_008C024E[0] & 0x80) {
                    cmpSkillSetMode(arg2, 9);
                    *arg0 = 0xB;
                    sdkSndStartStream(0, 2, 0, 3);
                } else if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(datCommunityRequestExit());
                    *arg0 = 0xD;
                } else {
                    sdkListStateConfigure(query, 6, *(s16 *)(arg2 + 0x580), skillRow, skillPage);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
                    if ((queryResult = sdkListStateHandleInput(query)) > 0) {
                        cmpSkillSetSelection((s16 *)arg2, 1, *(s32 *)(query + 0x24));
                        cmpSkillSetSelection((s16 *)arg2, 2, *(s32 *)(query + 0x28));
                        if (*(s16 *)(arg2 + 0x60) != *(s16 *)(arg2 + 0xAC)) {
                            cmpSkillLayoutScrollRows(arg2);
                        }
                        datCommunityCursorFeedback(queryResult);
                    }
                }
            }
            break;
        case 7:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                cmpSkillSetMode(arg2, 6U);
                cmpSkillSetScrollCursorMotion(arg2);
                *arg0 = 8;
            }
            break;
        case 8:
            if (D_008C024E[0] & 0x20) {
                cmpSkillSetMode(arg2, 3U);
                *arg0 = 5;
                nLineSelectSetImmediate(8);
                sdkSndStartStream(0, 0, 0, 2);
                break;
            }
            if (D_008C024E[0] & 0x40) {
                applicationResult = (s8)func_0013f720((s16)character, (s16)recipientId, skillIndex, arg2);
                switch (applicationResult) {
                case 0:
                case 1:
                    break;
                case 2:
                    cmpSkillSetMode(arg2, 3U);
                    *arg0 = 5;
                    nLineSelectSetImmediate(8);
                    break;
                case 3:
                    return 2;
                }
            } else {
                if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(datCommunityRequestExit());
                    *arg0 = 0xD;
                } else {
                    sdkListStateConfigure(query, 4, *(s16 *)(arg2 + 0xFC), recipientRow, 0);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
                    if ((s32)(sdkListStateHandleInput(query)) != (s32)(0)) {
                        cmpSkillSetSelection((s16 *)arg2, 3, *(s32 *)(query + 0x24));
                        cmpSkillSetScrollCursorMotion(arg2);
                        sdkSndStartStream(0, 1, 0, 0);
                    }
                }
                break;
            }
            break;
        case 9:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                cmpSkillSetMode(arg2, 8U);
                *arg0 = 0xA;
            }
            break;
        case 10:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                if (D_008C024E[0] & 0x20) {
                    cmpSkillSetMode(arg2, 3U);
                    *arg0 = 5;
                    nLineSelectSetImmediate(8);
                    sdkSndStartStream(0, 0, 0, 2);
                    break;
                }
                if (D_008C024E[0] & 0x40) {
                    allApplicationResult = (s8)func_0013f720((s16)character, -1, skillIndex, arg2);
                    switch (allApplicationResult) {
                    case 0:
                    case 1:
                        break;
                    case 2:
                        cmpSkillSetMode(arg2, 3U);
                        *arg0 = 5;
                        nLineSelectSetImmediate(8);
                        break;
                    case 3:
                        return 2;
                    }
                } else {
                    if (D_008C024E[0] & 0x10) {
                        *(s32 *)(arg2 + 0x10) = (s32)(datCommunityRequestExit());
                        *arg0 = 0xD;
                    }
                    break;
                }
            } else {
                break;
            }
            break;
        case 11:
            if ((s32)(cmpSkillRowsSettled(arg2)) != (s32)(0)) {
                cmpSkillSetMode(arg2, 0xAU);
                *arg0 = 0xC;
            }
            break;
        case 12:
            if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
                cmpSkillSetMode(arg2, 3);
                *arg0 = 5;
                sdkSndStartStream(0, 2, 0, 4);
            } else {
                alternateConfirm = D_008C024E[0] & 0x40;
                if (alternateConfirm != 0) {
                    radarHandleEntryAction((s32 *)arg0, character, recipientValue, arg2);
                } else if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(datCommunityRequestExit());
                    *arg0 = 0xD;
                } else {
                    sdkListStateConfigure(query, 6, *(s16 *)(arg2 + 0x580), skillRow, skillPage);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
                    if ((alternateQueryResult = sdkListStateHandleInput(query)) > 0) {
                        cmpSkillSetSelection((s16 *)arg2, 1, *(s32 *)(query + 0x24));
                        cmpSkillSetSelection((s16 *)arg2, 2, *(s32 *)(query + 0x28));
                        if (*(s16 *)(arg2 + 0x60) != *(s16 *)(arg2 + 0xAC)) {
                            cmpSkillLayoutScrollRows(arg2);
                        }
                        datCommunityCursorFeedback(alternateQueryResult);
                    }
                }
            }
            break;
        case 13:
            if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
                finished = 1;
            } else {
                alpha = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
                alphaByte = (u8)alpha;
                *(u8 *)arg2 = alphaByte;
                finished = 0;
            }
            if (finished != 0) {
                return 2;
            }
            break;
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Handle the entry action after its check: the type zero path sets state 7, and the type 1 or 2 path sets state 9 [inferred]
// FUN_0013F4D0
void radarHandleEntryAction(s32 *arg0, s16 arg1, s32 arg2, u8 *arg3) {
    s32 temp_18;
    u16 temp_3;

    temp_18 = *(s16 *)(arg3 + 0x60) + *(s16 *)(arg3 + 0x5E);
    if (radarEntryIsAllowed(arg1, temp_18, arg3) == 0) {
        sdkSndStartStream(0, 0, 0, 8);
        return;
    }
    temp_3 = func_0010f8c0(*(u16 *)(code13AddOff(temp_18 * 0xC, arg3) + 0x102)) & 0xFFFF;
    if (temp_3 == 0) {
        cmpSkillSetSelection((s16 *)arg3, 3, 0);
        cmpSkillSetMode(arg3, 5);
        cmpSkillSetScrollCursorMotion(arg3);
        if (arg0 != 0) {
            *arg0 = 7;
        }
    } else {
        if ((temp_3 == 2) || (temp_3 == 1)) {
            cmpSkillSetMode(arg3, 7);
            if (arg0 != 0) {
                *arg0 = 9;
            }
        }
    }
    nLineSelectSet(9);
    sdkSndStartStream(0, 0, 0, 1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Return 1 when the entry's type is valid and the threshold check does not block it [inferred]
// FUN_0013F620
s32 radarEntryIsAllowed(s16 arg0, s32 arg1, u8 *arg2) {
    s32 var_19;
    s16 var_18;
    s16 temp_17;
    s32 temp_16;
    u8 *temp_2;

    var_19 = 1;
    var_18 = -1;
    temp_2 = code13AddOff(arg1 * 0xC, arg2);
    temp_16 = *(u16 *)(temp_2 + 0x102);
    temp_17 = *(s16 *)(temp_2 + 0x100);
    if (func_0010f540(temp_16) == 0) {
        return 0;
    }
    if (temp_17 != -1) {
        var_18 = (s16)datPersonaGetLeadSlot();
        datPersonaSetLeadSlot(temp_17);
    }
    if (datCalcThresholdTriggerById(arg0, temp_16) != 0) {
        var_19 = 0;
    }
    if (var_18 != -1) {
        datPersonaSetLeadSlot(var_18);
    }
    return var_19;
}
#pragma pop
