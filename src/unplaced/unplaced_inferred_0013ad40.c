
/* Unit optimizer settings; measured function exceptions remain scoped below. */
#pragma opt_loop_invariants off
#pragma opt_propagation on

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "member_access.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
/* measured: menu callers need the shared offset-first address addition; a plain base + offset
 * changes their code. */
#include "byte_address_internal.h"
extern s32 radarSkillEffectMissing(s16, s16, s32);
extern s32 cmpSkillApplySelected(s16, s16, s32, u8 *);
extern s32 nLineIsIdle(void);
#include "g_data_entry_internal.h"

extern struct GDataEntry *datEntryAt(s16);
extern u32 datEntryGetFlags(s16);
extern s32 datCalcSkillEffectFlagsById(s16, s16, u32, u32);

extern u16 datGetSkillPropertyByte(s32);
extern s32 titleSetMenuLayout(u8 *, u32);
extern s32 nLineSelectSet(s32);
extern s32 radarEntryTypeIsActive(s16);
extern s32 datIsSkillAvailable(s32);
extern void shdPersonaSetFlags(u8 *, s32);
extern void shdPersonaClearFlags(u8 *, s32);
extern void shdPersonaRefreshDispCtlPosition(u8 *, void *);
extern void shdPersonaSetChildDispCtlHandleAndColor(u8 *, s32, s32);
extern void sdkListStateConfigure(u8 *, s32, s32, s32, s32);
extern void sdkListStateSetActive(void *, s32);
extern void sdkListStateSetSecondaryMasks(u8 *, s32, s32, s32, s32);
extern s32 sdkListStateHandleInput(u8 *);
extern void cmpPersonaSetSelection(u8 *, s32, s32);
extern void shdPersonaBeginDisplay(u8 *, s32, s32, s8);
extern void datPersonaSetLeadSlot(s16);
extern s32 datCalcThresholdTriggerById(s16, u32);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *, s32, s32, s8);
extern s32 radarEntryIsAllowed(s16, s32, u8 *);
extern s32 cmpSkillSetSelection(s16 *, s32, s32);
extern s32 cmpSkillSetMode(u8 *, s32);
extern void cmpSkillSetScrollCursorMotion(u8 *);
extern void cmpEquipSetSelection(u8 *, s32, s32);
extern void cmpEquipBuildItemList(u8 *);
extern void cmpEquipSetMode(u8 *, s32);
extern void radarBeginSlideOut(u8 *);
extern void radarBeginSlideIn(u8 *);
extern s16 datGetEquippedItemByUnit(s16, s16);
extern s32 datItemCount(s16);
extern void datAssignEquippedItem(s16, s16, s16);
extern void radarResetAndSetIndices(u8 *, s16, s16);
extern void sdkSpriteDrawAt(void *, f32, f32,
                          u8, u8, u8, u8);
extern void sdkSpriteDrawSized(u8 *, f32, f32, f32,
                          u8, u8, u8, u8, u16,
                          u16, s16, f32, s16);
extern void datPanelResetCursor(u8 *);
extern void datPanelDrawByKind(Vec2f, f32, s32, u8 *, s32);
extern s32 datCalcGetLevelById(s32);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void datEntryDrawByKind(Vec2f, u8, void *, s32, f32);
extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                          s32, s32, s32, s32);
extern void titleStateInit(u8 *);
extern s32 titleAdvanceWait(u8 *);
extern s32 radarPushHistoryValue(s32, s32, s32);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datCommunityCursorFeedback(s32);
extern s32 nLineSelectSetImmediate(s32);
extern s32 radarAdvanceGroupSelection(u8 *);
extern s32 radarApplyItemStep(s16, s16, u8 *);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern void radarHandleEntrySelect(s32 *, u8 *);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2F4[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
extern u8 D_0064B30C[];
extern void datSetFlag(s32, s32);
extern void datCalcApplySkillEffectById(s16, s16, u32, u32);
extern s32 FldStepNotAtBoundaryQuery(void);
extern void kAssertFail(void *, s32);
extern u8 D_005ED9E0[];
typedef struct {
    s32 first;
    s32 second;
} RadarPositionWords;

/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct { u8 pad0[0x24]; s32 row, page; } SdkListState;
typedef struct { s16 item, count; } RadarItemEntry;
typedef struct { s16 leadSlot; u16 skill; u8 pad4[6]; u16 label; } RadarSkillEntry;

typedef struct {
    u8 alpha;
    u8 pad1[0xB];
    u16 fadeFrame; /* +0xC */
    u8 padE[0x2];
    s32 exitRequest; /* +0x10 */
    u8 pad14[0xE];
    s16 unk22; /* +0x22 */
    s16 unk24; /* +0x24 */
    s16 unk26; /* +0x26 */
    u8 pad28[0x2];
    s16 unk2A; /* +0x2A */
    u8 pad2C[8];
    s16 recipients[4];
    s16 unk3C; /* +0x3C */
    RadarItemEntry entries[768];
    s16 itemCount; /* +0xC3E */
    u8 padC40[0x4];
    s32 unkC44; /* +0xC44 */
} RadarItemMenuWork;

/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct {
    u8 alpha;
    u8 pad1[0xB];
    u16 fadeFrame; /* +0xC */
    u8 padE[0x2];
    s32 exitRequest; /* +0x10 */
    u8 pad14[0x14];
    s16 unk28; /* +0x28 */
    s16 unk2A; /* +0x2A */
    s16 unk2C; /* +0x2C */
    s16 unk2E; /* +0x2E */
    u8 pad30[0x4];
    s16 unk34; /* +0x34 */
    u8 pad36[2];
    s16 recipients[8];
    s16 unk48; /* +0x48 */
    RadarItemEntry entries[767];
    s16 equipmentItemCount; /* +0xC46 */
    u8 padC48[0x94C];
    s32 unk1594; /* +0x1594 */
} RadarEquipmentMenuWork;

/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct {
    u8 alpha;
    u8 pad1[0xB];
    u16 fadeFrame; /* +0xC */
    u8 padE[0x2];
    s32 exitRequest; /* +0x10 */
    u8 pad14[0x10];
    u16 characters[8];
    s16 unk34; /* +0x34 */
    s16 roster[12];
    s16 unk4E; /* +0x4E */
    s16 unk50; /* +0x50 */
    s16 unk52; /* +0x52 */
    u8 pad54[0x1C60];
    u8 * personaDisplay; /* +0x1CB4 */
    u8 * screenWipe; /* +0x1CB8 */
} RadarPersonaMenuWork;

/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct {
    u8 alpha; /* +0x0 */
    u8 pad1[0x3];
    f32 x; /* +0x4 */
    f32 y; /* +0x8 */
    u16 fadeFrame; /* +0xC */
    u8 padE[0x2];
    s32 exitRequest; /* +0x10 */
    u8 pad14[0x8];
    s32 flags; /* +0x1C */
    u8 pad20[0x3C];
    s16 unk5C; /* +0x5C */
    s16 unk5E; /* +0x5E */
    s16 unk60; /* +0x60 */
    s16 unk62; /* +0x62 */
    u8 pad64[0x48];
    s16 unkAC; /* +0xAC */
    u8 padAE[0x46];
    s16 recipients[4];
    s16 unkFC; /* +0xFC */
    u8 padFE[2];
    RadarSkillEntry skills[96];
    s16 unk580; /* +0x580 */
    u8 pad582[0x628];
    u16 cardHeight; /* +0xBAA */
    u8 padBAC[0xD8];
    f32 cardOffsetX; /* +0xC84 */
    f32 cardOffsetY; /* +0xC88 */
    u8 padC8C[0x5FC];
    union { s32 integer; u8 * bytes; } unk1288; /* +0x1288 */
    union { u8 * bytes; void * pointer; } unk128C; /* +0x128C */
    u8 pad1290[0x2C];
    void * unk12BC; /* +0x12BC */
    void * unk12C0; /* +0x12C0 */
    void *digitSprites[10];
    u8 pad12EC[0x30];
    u8 * unk131C; /* +0x131C */
    void * unk1320; /* +0x1320 */
    u8 * unk1324; /* +0x1324 */
    u8 * unk1328; /* +0x1328 */
    u8 pad132C[0x4];
    void * unk1330; /* +0x1330 */
} RadarSkillMenuWork;

#pragma push
#pragma optimization_level 2
/* measured: without these settings the last sprite load sinks below where retail loads it. */
#pragma opt_propagation off
// Draws one radar entry row from the first group (slots 5 and 1) or the second group (slots 0x1C
// and 0x18).
// FUN_0013AD40
void radarDrawEntryRowGroup(u8 *work, s32 rowIndex, s32 groupIndex)
{
    typedef struct
    {
        s16 id;
        s16 pad2;
        s16 x;
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
    id = ((s16 *)(work + 0xF4))[rowIndex];
    x = ((RadarSkillMenuWork *)work)->x;
    y = ((RadarSkillMenuWork *)work)->y;
    fade = (f32)*(u8 *)work / 255.0f;
    datPanelResetCursor((u8 *)&param);
    param.mode = 1;
    param.id = id;
    selected = ((s16 *)(work + 0x5C))[groupIndex];
    if (selected == rowIndex || (((RadarSkillMenuWork *)work)->flags & 0x100) != 0) {
        if (groupIndex == 0 && (((RadarSkillMenuWork *)work)->flags & 0x10) != 0) {
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
    if (groupIndex == 0) {
        slot = 5;
        slot2 = 1;
    } else {
        slot = 0x1C;
        slot2 = 0x18;
    }
    pos.x = 67.0f + (x + ((LabelSlot *)(work + 0x594))[slot + rowIndex].x);
    yoff = 75.0f * (f32)rowIndex;
    ty = 24.0f + (y + ((LabelSlot *)(work + 0x594))[slot + rowIndex].y);
    pos.y = ty + yoff;
    ty = ((LabelSlot *)(work + 0x594))[slot + rowIndex].alpha;
    datPanelDrawByKind(pos, 0.0f, (u8)(ty * fade), (u8 *)&param, 0);
    alpha = (f32)(work + 0x59E)[(slot2 + rowIndex) * 0x30] * fade;
    pos.x = 60.0f + (x + ((f32 *)(work + 0x594))[(slot2 + rowIndex) * 12]);
    ty = y + ((f32 *)(work + 0x598))[(slot2 + rowIndex) * 12];
    pos.y = 21.0f + (ty + yoff);
    sdkSpriteDrawAt(((RadarSkillMenuWork *)work)->unk12BC, pos.x, pos.y, color0[0], color0[1], color0[2], alpha);
    if (highlight != 0) {
        pos.x = 2.0f + (x + ((f32 *)(work + 0x594))[(slot2 + rowIndex) * 12]);
        ty = y + ((f32 *)(work + 0x598))[(slot2 + rowIndex) * 12];
        pos.y = 27.0f + (ty + yoff);
        sdkSpriteDrawAt(((RadarSkillMenuWork *)work)->unk12C0, pos.x, pos.y, 0x4C, 0x4C, 0x4C, alpha);
    }
    n = (u8)datCalcGetLevelById(id);
    pos.x = 43.0f + (x + ((f32 *)(work + 0x594))[(slot2 + rowIndex) * 12]);
    ty = y + ((f32 *)(work + 0x598))[(slot2 + rowIndex) * 12];
    pos.y = 25.0f + (ty + yoff);
    if (n < 10) {
        pos.x -= 11.0f;
    }
    while (n > 0) {
        sdkSpriteDrawAt(((RadarSkillMenuWork *)work)->digitSprites[n % 10], pos.x, pos.y, color1[0], color1[1], color1[2], alpha);
        pos.x -= 22.0f;
        n /= 10;
    }
    pos.x = 37.0f + (x + ((f32 *)(work + 0x594))[(slot2 + rowIndex) * 12]);
    ty = y + ((f32 *)(work + 0x598))[(slot2 + rowIndex) * 12];
    pos.y = 53.0f + (ty + yoff);
    spr = ((RadarSkillMenuWork *)work)->unk1330;
    sdkSpriteDrawAt(spr, pos.x, pos.y, color2[0], color2[1], color2[2], (u8)((f32)alpha * dim));
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Draws a sprite pair from the second sprite table at the given position, 340 units apart, in the
// given colour.
// FUN_0013B370
/* measured: without copy propagation off, the compiler hoists the Y position load ahead of the RGB
 * colour reads, unlike retail. */
#pragma opt_propagation off
void radarDrawSecondSpritePair(u8 *work, Vec2f position, PackedColor4 color)
{
    f32 drawY;
    s32 sprite;
    u8 alpha;
    u8 blue;
    u8 green;

    sprite = ((RadarSkillMenuWork *)work)->unk1288.integer;
    alpha = ((u8 *)&color)[3];
    blue = ((u8 *)&color)[2];
    green = ((u8 *)&color)[1];
    drawY = ((f32 *)&position)[1];
    sdkSpriteDrawAt((void *)sprite,
                  ((f32 *)&position)[0], drawY,
                  ((u8 *)&color)[0], green, blue, alpha);
    sdkSpriteDrawAt(((RadarSkillMenuWork *)work)->unk128C.pointer,
                  340.0f + ((f32 *)&position)[0], drawY,
                  ((u8 *)&color)[0], green, blue, alpha);
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Draws one skill card (background sprites, bars and value text) at the given position and alpha,
 * keeping the original Y and sprite cursor across draw pairs. */
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
    opacityValue = (f32)(u32)((RadarSkillMenuWork *)work)->alpha;
    opacityScale = opacityValue / 255.0f;
    colors.current.b[0] = 0x14;
    colors.current.b[1] = 0x14;
    colors.current.b[2] = 0x14;
    scaledAlpha = 204.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    height = (f32)(u32)((RadarSkillMenuWork *)work)->cardHeight;
    position.xy.x = inputPosition.x - 1.0f;
    inputPosition.y = 24.0f;
    inputPosition.y += originalY;
    position.xy.y = inputPosition.y;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = ((RadarSkillMenuWork *)work)->unk1324;
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawSized(sprite, position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
        sprite = ((RadarSkillMenuWork *)work)->unk1328;
        sdkSpriteDrawSized(sprite, (f32)0x159 + position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
    }
    {
        f32 x;
        x = 5.0f + inputPosition.x;
        x += ((RadarSkillMenuWork *)work)->cardOffsetX;
        position.xy.x = x;
    }
    {
        f32 y;
        y = 34.0f + originalY;
        y += ((RadarSkillMenuWork *)work)->cardOffsetY;
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
        sprite = ((RadarSkillMenuWork *)work)->unk131C;
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawAt(sprite, position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
        sdkSpriteDrawAt(((RadarSkillMenuWork *)work)->unk1320, 330.0f + position.xy.x, y,
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
        sprite = ((RadarSkillMenuWork *)work)->unk1288.bytes;
        alpha = colors.copy.b[3];
        blue = colors.copy.b[2];
        green = colors.copy.b[1];
        y = palettePosition.xy.y;
        sdkSpriteDrawAt(sprite, palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
        sprite = ((RadarSkillMenuWork *)work)->unk128C.bytes;
        sdkSpriteDrawAt(sprite, 340.0f + palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
    }
    position.xy.x = position.xy.x - 2.0f;
    datEntryDrawByKind(position.xy, colors.current.b[3], entry, 1, 0.0f);
    position.xy.x = 22.0f + inputPosition.x;
    position.xy.y = 54.0f + originalY;
    labelAlpha = (u8)scaledInputAlpha;
    itfMesWindowDrawDefaultEntry((f32)(s32)position.xy.x, (f32)(s32)position.xy.y, 0.0f,
                  (labelAlpha & 0xFF) | ~0xFF, 1, 8, ((RadarSkillEntry *)entry)->label);
}
#pragma pop

/* Find the beginning of the preceding run of equal item flags. */
static inline s32 radarPreviousGroupStart(u8 *work, s32 index)
{
    u32 selected;
    selected = datEntryGetFlags(((RadarItemMenuWork *)byteAddressAdd((index - 1) * sizeof(RadarItemEntry), work))->entries[0].item);
    index = index - 1;
    while (index > 0) {
        if (datEntryGetFlags(((RadarItemMenuWork *)(work + index * 4))->entries[-1].item) != selected) break;
        index--;
    }
    return index;
}

/* Keep the initial group selected when no preceding group exists. */
static inline s32 radarPreviousGroupStartOrSame(u8 *work, s32 total)
{
    if (total == 0) {
        return total;
    } else {
        return radarPreviousGroupStart(work, total);
    }
}

/* Find the next flag group, wrapping when the item list ends. */
static inline s32 radarNextGroupStart(u8 *work, s32 total, s32 count, s32 wrap)
{
    s32 index;
    u32 selected;
    selected = datEntryGetFlags(((RadarItemMenuWork *)byteAddressAdd(total * sizeof(RadarItemEntry), work))->entries[0].item);
    index = total + 1;
    while (index < count) {
        if (datEntryGetFlags(((RadarItemMenuWork *)(work + index * 4))->entries[0].item) != selected) break;
        index++;
    }
    if (index >= count) index = wrap;
    return index;
}

#pragma push
#pragma optimization_level 2
/* measured: without these settings the load and add order differs from retail. */
#pragma opt_propagation off
// Advance the group selection to the neighbour chosen by the button bits, and update the two group
// windows.
// FUN_0013B9F0
s32 radarAdvanceGroupSelection(u8 *work)
{
    s32 count;
    s32 index;
    s32 total;
    s32 low;
    s32 high;

    count = ((RadarItemMenuWork *)work)->itemCount;
    if (count < 2) return 0;
    {
        s32 column = ((RadarItemMenuWork *)work)->unk24;
        s32 row = ((RadarItemMenuWork *)work)->unk22;
        total = ((row) + (column));
    }
    if (D_008C024E[0] & 4) {
        index = total;
        if (total == 0) index = count;
        index = radarPreviousGroupStart(work, index);
        goto process;
    }
    if (D_008C024E[0] & 8) {
        index = radarNextGroupStart(work, total, count, 0);
        goto process;
    }
    if (D_008C0252[0] & 4) {
        index = radarPreviousGroupStartOrSame(work, total);
        goto process;
    }
    if (D_008C0252[0] & 8) {
        index = radarNextGroupStart(work, total, count, total);
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
    radarPushHistoryValue((s32)work, 0, (s16)high);
    radarPushHistoryValue((s32)work, 1, (s16)low);
    return 1;
}
#pragma pop

s32 radarEntriesCoverValue(u8 *);
void radarFreeSpriteNodes(u8 *);
void radarPushSlotState(u8 *);
void radarResetIndicator(u8 *);

#pragma push
#pragma optimization_level 2
// Item-use menu state machine: step the item selection, apply the chosen item to its recipients,
// and return the menu's result.
// FUN_0013BCF0
s32 radarItemMenuUpdate(u32 *state, s32 *active, u8 *work) {
    RadarItemMenuWork *itemMenu = (RadarItemMenuWork *)work;
    extern s32 radarPushHistoryValue(s32 menuAddress, s32 selectionIndex, s32 selection);
    u8 listState[0x30];
    f32 fadeAlpha;
    f32 fadeValue;
    s32 ready;
    s32 listResult;
    s32 alternateListResult;
    s32 finished;
    s32 alphaByte;
    *active = (finished = 1);
    switch (*state) {
    case 0:
        *active = 0;
        titleStateInit(work);
        *state = 1;
        break;
    case 1:
        ready = titleAdvanceWait(work);
        if (ready & nLineIsIdle()) {
            *state = 3;
            nLineSelectSet(0xB);
        } else {
            *active = 0;
        }
        break;
    case 2:
        if (radarEntriesCoverValue(work) != 0) {
            radarFreeSpriteNodes(work);
            return 1;
        }
        break;
    case 3:
        if (radarEntriesCoverValue(work) != 0) {
            titleSetMenuLayout(work, 3);
            *state = 4;
            resrcMngSuppressRender();
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(work, 1);
            *state = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0xD);
            sdkSndStartStream(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (((RadarItemMenuWork *)(work))->itemCount > 0)) {
            radarHandleEntrySelect((s32 *)state, work);
            ((RadarItemMenuWork *)(work))->unkC44 = 0;
        } else if ((D_008C024E[0] & 0x80) && (((RadarItemMenuWork *)(work))->itemCount > 0)) {
            titleSetMenuLayout(work, 8);
            *state = 5;
            ((RadarItemMenuWork *)(work))->unkC44 = 1;
            sdkSndStartStream(0, 2, 0, 3);
        } else if (D_008C024E[0] & 0x10) {
            ((RadarItemMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xB;
        } else if (radarAdvanceGroupSelection(work) != 0) {
            sdkSndStartStream(0, 1, 0, 5);
        } else {
            sdkListStateConfigure(listState, 6, ((RadarItemMenuWork *)(work))->itemCount, ((RadarItemMenuWork *)(work))->unk22, ((RadarItemMenuWork *)(work))->unk24);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((listResult = sdkListStateHandleInput(listState)) > 0) {
                radarPushHistoryValue((s32)work, 0, ((SdkListState *)listState)->row);
                radarPushHistoryValue((s32)work, 1, ((SdkListState *)listState)->page);
                if (itemMenu->unk24 != ((RadarItemMenuWork *)(work))->unk2A) {
                    radarResetIndicator(work);
                }
                datCommunityCursorFeedback(listResult);
            }
        }
        break;
    case 7:
        if (radarEntriesCoverValue(work) != 0) {
            titleSetMenuLayout(work, 6);
            radarPushSlotState(work);
            *state = 8;
        }
        break;
    case 8:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(work, 2);
            *state = 3;
            nLineSelectSetImmediate(0xB);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            if (radarApplyItemStep(1, ((RadarItemMenuWork *)((u8 *)((u8 *)(((RadarItemMenuWork *)(work))->unk26 * 2) + (u32)work)))->recipients[0], work) == 2) {
                titleSetMenuLayout(work, 2);
                *state = 3;
                nLineSelectSetImmediate(0xB);
            }
        } else if (D_008C024E[0] & 0x10) {
            ((RadarItemMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xB;
        } else {
            sdkListStateConfigure(listState, 4, ((RadarItemMenuWork *)(work))->unk3C, ((RadarItemMenuWork *)(work))->unk26, 0);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(listState) != 0) {
                radarPushHistoryValue((s32)work, 2, ((SdkListState *)listState)->row);
                radarPushSlotState(work);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 9:
        if (radarEntriesCoverValue(work) != 0) {
            titleSetMenuLayout(work, 7);
            *state = 0xA;
        }
        break;
    case 10:
        if (D_008C024E[0] & 0x20) {
            titleSetMenuLayout(work, 2);
            *state = 3;
            nLineSelectSetImmediate(0xB);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            {
                s32 inner = radarApplyItemStep(1, -1, work);
                switch (inner) {
                case 2:
                    titleSetMenuLayout(work, 2);
                    *state = 3;
                    nLineSelectSetImmediate(0xB);
                    break;
                case 3:
                    return 2;
                default:
                    break;
                }
            }
        } else if (D_008C024E[0] & 0x10) {
            ((RadarItemMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xB;
        }
        break;
    case 5:
        if (radarEntriesCoverValue(work) != 0) {
            titleSetMenuLayout(work, 9);
            *state = 6;
        }
        break;
    case 6:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            titleSetMenuLayout(work, 2);
            *state = 3;
            sdkSndStartStream(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (((RadarItemMenuWork *)(work))->itemCount > 0)) {
            radarHandleEntrySelect((s32 *)state, work);
        } else if (D_008C024E[0] & 0x10) {
            ((RadarItemMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xB;
        } else if (radarAdvanceGroupSelection(work) != 0) {
            sdkSndStartStream(0, 1, 0, 5);
        } else {
            sdkListStateConfigure(listState, 6, ((RadarItemMenuWork *)(work))->itemCount, ((RadarItemMenuWork *)(work))->unk22, ((RadarItemMenuWork *)(work))->unk24);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((alternateListResult = sdkListStateHandleInput(listState)) > 0) {
                radarPushHistoryValue((s32)work, 0, ((SdkListState *)listState)->row);
                radarPushHistoryValue((s32)work, 1, ((SdkListState *)listState)->page);
                if (itemMenu->unk24 != ((RadarItemMenuWork *)(work))->unk2A) {
                    radarResetIndicator(work);
                }
                datCommunityCursorFeedback(alternateListResult);
            }
        }
        break;
    case 11:
        if ((++((RadarItemMenuWork *)(work))->fadeFrame & 0xFFFF) >= 3) {
            finished = 1;
        } else {
            fadeAlpha = (1.0f - ((f32)itemMenu->fadeFrame / 3.0f)) * 255.0f;
            alphaByte = (u8)fadeAlpha;
            ((RadarItemMenuWork *)work)->alpha = alphaByte;
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

void radarPushSlotState(u8 *);

#pragma push
#pragma optimization_level 2
// Handle a selected entry: when its type is active, set the state by type (0 becomes 7, 1 or 2
// become 9) and play the cue; otherwise play cue 8.
// FUN_0013C5A0
void radarHandleEntrySelect(s32 *state, u8 *work) {
    u8 *entry;
    s16 type;

    entry = byteAddressAdd((((RadarItemMenuWork *)work)->unk24 + ((RadarItemMenuWork *)work)->unk22) * sizeof(RadarItemEntry),
                         work) + MEMBER_OFFSET(RadarItemMenuWork, entries);
    if (radarEntryTypeIsActive(*(s16 *)entry) == 0) {
        sdkSndStartStream(0, 0, 0, 8);
        return;
    }
    type = (s16)datGetSkillPropertyByte(datEntryAt(*(s16 *)entry)->effect);
    if (type == 0) {
        titleSetMenuLayout(work, 4);
        radarPushSlotState(work);
        *state = 7;
    } else {
        if ((type == 2) || (type == 1)) {
            titleSetMenuLayout(work, 5);
            *state = 9;
        }
    }
    nLineSelectSet(0xC);
    sdkSndStartStream(0, 0, 0, 1);
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Return whether the type of the entry's item is active.
// FUN_0013C6D0
s32 radarEntryTypeIsActive(s16 item) {
    return datIsSkillAvailable(datEntryAt(item)->effect) != 0;
}
#pragma pop

s32 radarCollectPartyChanges(u8 *);
void radarReleaseSpritesAndEntries(u8 *);
void radarResetLayout(u8 *);
s32 radarWideEntriesCoverValue(u8 *);

#pragma push
#pragma optimization_level 2
// Transfer menu state machine: step the party-change and unit-transfer states, and return the
// menu's result.
// FUN_0013CAA0
s32 radarTransferMenuUpdate(u32 *state, s32 *active, u8 *work) {
    RadarEquipmentMenuWork *equipmentMenu = (RadarEquipmentMenuWork *)work;
    u8 listState[0x30];
    f32 fadeAlpha;
    f32 fadeValue;
    s32 ready;
    s32 listResult;
    s32 alternateListResult;
    s32 childTask;
    s32 exitTask;
    s32 finished;
    s32 alphaByte;

    *active = (finished = 1);
    switch (*state) {
    case 0:
        *active = 0;
        cmpEquipMenuInit(work);
        *state = 1;
        break;
    default:
        break;
    case 1:
        ready = (s32)(cmpEquipStateStep(work));
        if (ready & nLineIsIdle()) {
            *state = 4;
            nLineSelectSet(3);
        } else {
            *active = 0;
        }
        break;
    case 2:
        childTask = (s32)(((RadarEquipmentMenuWork *)(work))->unk1594);
        if ((childTask == 0) || (kwlnTaskIsLinked(childTask) == 0)) {
            *state = 3;
            cmpEquipSetMode(work, 1);
            resrcMngUnsuppressRender();
            nLineSelectSet(7);
        case 3:
            if (radarWideEntriesCoverValue(work) != 0) {
                radarReleaseSpritesAndEntries(work);
                return 1;
            }
            break;
        }
        break;
    case 4:
        if (radarWideEntriesCoverValue(work) != 0) {
            resrcMngSuppressRender();
            cmpEquipSetMode(work, 2);
            *state = 5;
        }
        break;
    case 5:
        if (radarWideEntriesCoverValue(work) != 0) {
            if (D_008C024E[0] & 0x20) {
                *state = 2;
                radarCollectPartyChanges(work);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                cmpEquipSetMode(work, 3);
                *state = 7;
                nLineSelectSet(4);
                sdkSndStartStream(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x10) {
                radarCollectPartyChanges(work);
                ((RadarEquipmentMenuWork *)(work))->exitRequest = datCommunityRequestExit();
                *state = 0xD;
            } else {
                sdkListStateConfigure(listState, 8, ((RadarEquipmentMenuWork *)(work))->unk48, ((RadarEquipmentMenuWork *)(work))->unk28, 0);
                sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(listState) != 0) {
                    cmpEquipSetSelection(work, 0, ((SdkListState *)listState)->row);
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
        }
        break;
    case 6:
        if (radarWideEntriesCoverValue(work) != 0) {
            cmpEquipSetMode(work, 4);
            *state = 7;
        }
        break;
    case 7:
        if (D_008C024E[0] & 0x20) {
            cmpEquipSetSelection(work, 1, 0);
            cmpEquipSetMode(work, 2);
            *state = 5;
            nLineSelectSetImmediate(3);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            cmpEquipSetMode(work, 5);
            *state = 8;
            nLineSelectSet(5);
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            radarCollectPartyChanges(work);
            ((RadarEquipmentMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xD;
        } else {
            sdkListStateConfigure(listState, 3, 3, ((RadarEquipmentMenuWork *)(work))->unk2A, 0);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(listState) != 0) {
                cmpEquipSetSelection(work, 1, ((SdkListState *)listState)->row);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 8:
        if (radarWideEntriesCoverValue(work) != 0) {
            cmpEquipSetMode(work, 6);
            *state = 9;
            nLineSelectSet(6);
        }
        break;
    case 9:
        if (radarWideEntriesCoverValue(work) != 0) {
            cmpEquipSetMode(work, 7);
            *state = 0xA;
        }
        break;
    case 10:
        if (radarWideEntriesCoverValue(work) != 0) {
            if (D_008C024E[0] & 0x40) {
                if (((RadarEquipmentMenuWork *)(work))->equipmentItemCount != 0) {
                    radarTransferSelectedUnit(work);
                }
            } else if (D_008C024E[0] & 0x20) {
                cmpEquipSetSelection(work, 2, 0);
                cmpEquipSetSelection(work, 3, 0);
                cmpEquipSetMode(work, 4);
                *state = 6;
                nLineSelectSetImmediate(4);
                sdkSndStartStream(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                radarCollectPartyChanges(work);
                ((RadarEquipmentMenuWork *)(work))->exitRequest = datCommunityRequestExit();
                *state = 0xD;
            } else if (D_008C024E[0] & 0x80) {
                if (((RadarEquipmentMenuWork *)(work))->equipmentItemCount != 0) {
                    cmpEquipSetMode(work, 8);
                    *state = 0xB;
                    sdkSndStartStream(0, 2, 0, 3);
                }
            } else if (radarBeginPickList(work, state) == 0) {
                sdkListStateConfigure(listState, 5, ((RadarEquipmentMenuWork *)(work))->equipmentItemCount, ((RadarEquipmentMenuWork *)(work))->unk2E, ((RadarEquipmentMenuWork *)(work))->unk2C);
                sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0x2000, 0x8000);
                if ((listResult = sdkListStateHandleInput(listState)) > 0) {
                    cmpEquipSetSelection(work, 2, ((SdkListState *)listState)->page);
                    cmpEquipSetSelection(work, 3, ((SdkListState *)listState)->row);
                    if (equipmentMenu->unk2C != ((RadarEquipmentMenuWork *)(work))->unk34) {
                        radarResetLayout(work);
                    }
                    datCommunityCursorFeedback(listResult);
                }
            }
        }
        break;
    case 11:
        if (radarWideEntriesCoverValue(work) != 0) {
            cmpEquipSetMode(work, 9);
            *state = 0xC;
        }
        break;
    case 12:
        if (D_008C024E[0] & 0x40) {
            if (radarTransferSelectedUnit(work) != 0) {
                *state = 9;
            }
        } else if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            cmpEquipSetMode(work, 7);
            *state = 9;
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            radarCollectPartyChanges(work);
            ((RadarEquipmentMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            *state = 0xD;
        } else if (radarBeginPickList(work, state) == 0) {
            sdkListStateConfigure(listState, 5, ((RadarEquipmentMenuWork *)(work))->equipmentItemCount, ((RadarEquipmentMenuWork *)(work))->unk2E, ((RadarEquipmentMenuWork *)(work))->unk2C);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((alternateListResult = sdkListStateHandleInput(listState)) > 0) {
                cmpEquipSetSelection(work, 2, ((SdkListState *)listState)->page);
                cmpEquipSetSelection(work, 3, ((SdkListState *)listState)->row);
                if (equipmentMenu->unk2C != ((RadarEquipmentMenuWork *)(work))->unk34) {
                    radarResetLayout(work);
                }
                datCommunityCursorFeedback(alternateListResult);
            }
        }
        break;
    case 13:
        exitTask = (s32)(((RadarEquipmentMenuWork *)(work))->unk1594);
        if ((exitTask == 0) || (kwlnTaskIsLinked(exitTask) == 0)) {
            if ((++((RadarEquipmentMenuWork *)(work))->fadeFrame & 0xFFFF) >= 3) {
                finished = 1;
            } else {
                fadeAlpha = (1.0f - ((f32)equipmentMenu->fadeFrame / 3.0f)) * 255.0f;
                alphaByte = (u8)fadeAlpha;
                ((RadarEquipmentMenuWork *)work)->alpha = alphaByte;
                finished = 0;
            }
            if (finished != 0) {
                return 2;
            }
            break;
        }
        break;
    }
    return 0;
}
#pragma pop

void radarRandomizeEntries(u8 *);

#pragma push
#pragma optimization_level 2
// Apply the selected item to the chosen recipients, consume one use, and update the row; return the
// resulting state.
// FUN_0013C700
s32 radarApplyItemStep(s16 source, s16 recipientId, u8 *work)
{
    RadarItemMenuWork *itemMenu = (RadarItemMenuWork *)work;
    extern void titleCollectFlaggedIds(u8 *menu);
    extern u8 D_005ED9D0[];
    s32 state;
    s16 item;
    s32 itemType;
    s16 remaining;
    s32 total;
    s32 updated;
    u8 *entry;

    state = 1;
    total = ((RadarItemMenuWork *)(work))->unk24 + ((RadarItemMenuWork *)(work))->unk22;
    item = ((s16 *)(work + 0x3E))[total * 2];
    itemType = datEntryAt(item)->effect;
    if (itemType == 246) {
        if (FldStepNotAtBoundaryQuery() != 0) state = 3;
        else state = 0;
    } else if (recipientId == -1) {
        s32 affectedCount;
        s32 index;
        u8 *recipient;
        affectedCount = 0;
        index = 0;
        while (index < ((RadarItemMenuWork *)(work))->unk3C) {
            recipient = work + index * 2 + 0x34;
            if (radarSkillEffectMissing(source, *(s16 *)recipient, itemType) != 0) {
                datCalcApplySkillEffectById(source, *(s16 *)recipient, itemType, 1);
                affectedCount++;
            }
            index++;
        }
        if (affectedCount == 0) state = 0;
    } else if (radarSkillEffectMissing(source, recipientId, itemType) != 0) {
        datCalcApplySkillEffectById(source, recipientId, itemType, 1);
    } else state = 0;
    if (state > 0) {
        updated = (s16)(datItemCount(item) & 0xff) - 1;
        if (updated < 0) kAssertFail(D_005ED9D0, 0x29c);
        datItemSetCount(item, updated & 0xff);
        if (state == 3) {
            datSetFlag(5121, 1);
        } else {
            radarRandomizeEntries(work);
            entry = byteAddressAdd((u32)total * sizeof(RadarItemEntry), work);
            remaining = --((RadarItemMenuWork *)(entry))->entries[0].count;
            if (remaining == 0) {
                s32 selection;
                titleCollectFlaggedIds(work);
                selection = ((RadarItemMenuWork *)(work))->itemCount;
                if (selection < 6) {
                    radarPushHistoryValue((s32)work, 1, 0);
                    selection = itemMenu->itemCount - 1;
                    if (selection < itemMenu->unk22) radarPushHistoryValue((s32)work, 0, selection);
                } else {
                    selection -= 6;
                    if (selection < itemMenu->unk24) radarPushHistoryValue((s32)work, 1, selection);
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
#pragma optimization_level 2
// Return 1 when the skill effect for the recipient is not yet applied.
// FUN_0013CA60
s32 radarSkillEffectMissing(s16 source, s16 recipient, s32 effect) {
    s32 missing = 0;

    if (datCalcSkillEffectFlagsById(source, recipient, effect, 1) == 0) {
        missing = 1;
    }
    return missing;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Open the pick list when it has entries: set state 10 and initialise its groups; return 1 when
// opened.
// FUN_0013D470
s32 radarBeginPickList(u8 *work, s32 *state) {
    u8 listState[0x28];
    s32 listResult;

    sdkListStateConfigure(listState, 8, ((RadarEquipmentMenuWork *)work)->unk48, ((RadarEquipmentMenuWork *)work)->unk28, 0);
    sdkListStateSetActive(listState, 0);
    sdkListStateSetSecondaryMasks(listState, 8, 4, 0, 0);
    listResult = sdkListStateHandleInput(listState);
    if (listResult > 0) {
        cmpEquipSetSelection(work, 0, ((SdkListState *)listState)->row);
        cmpEquipSetSelection(work, 3, 0);
        cmpEquipSetSelection(work, 2, 0);
        cmpEquipBuildItemList(work);
        cmpEquipSetMode(work, 7);
        *state = 0xA;
        if (listResult == 1) {
            radarBeginSlideOut(work);
        } else if (listResult == 2) {
            radarBeginSlideIn(work);
        }
        sdkSndStartStream(0, 1, 0, 5);
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Transfer one unit of the selected entry to the target entry, refresh the rows, and step the
// cursor; return 1 when a transfer happened.
// FUN_0013D5D0
s32 radarTransferSelectedUnit(u8 *work) {
    RadarEquipmentMenuWork *equipmentMenu = (RadarEquipmentMenuWork *)work;
    struct {
        s16 value;
    } equipmentSlot;
    s16 selectedItem;
    s16 unitId;
    s16 itemCount;
    s32 lastRow;
    s32 lastPage;
    s16 previousItem;

    unitId = ((RadarEquipmentMenuWork *)(byteAddressAdd(((RadarEquipmentMenuWork *)(work))->unk28 * sizeof(s16), work)))->recipients[0];
    selectedItem = ((RadarEquipmentMenuWork *)(byteAddressAdd((((RadarEquipmentMenuWork *)(work))->unk2C +
                                     ((RadarEquipmentMenuWork *)(work))->unk2E) * sizeof(RadarItemEntry), work)))->entries[0].item;
    equipmentSlot.value = ((RadarEquipmentMenuWork *)(work))->unk2A;
    previousItem = (s16)datGetEquippedItemByUnit(unitId, equipmentSlot.value);
    if (selectedItem == previousItem) {
        sdkSndStartStream(0, 0, 0, 8);
        return 0;
    }
    cmpEquipSetMode(work, 7);
    radarResetAndSetIndices(work, previousItem, selectedItem);
    if ((datItemCount(previousItem) & 0xFF) != 0x63) {
        datItemSetCount(previousItem, ((datItemCount(previousItem) & 0xFF) + 1) & 0xFF);
    }
    datAssignEquippedItem(unitId, equipmentSlot.value, selectedItem);
    datItemSetCount(selectedItem, ((datItemCount(selectedItem) & 0xFF) - 1) & 0xFF);
    cmpEquipBuildItemList(work);
    itemCount = ((RadarEquipmentMenuWork *)(work))->equipmentItemCount;
    if (itemCount < 5) {
        cmpEquipSetSelection(work, 2, 0);
        lastRow = equipmentMenu->equipmentItemCount - 1;
        if (lastRow < equipmentMenu->unk2E) {
            cmpEquipSetSelection(work, 3, lastRow);
        }
    } else {
        lastPage = itemCount - 5;
        if (lastPage < equipmentMenu->unk2C) {
            cmpEquipSetSelection(work, 2, lastPage);
        }
    }
    sdkSndStartStream(0, 3, 0, 7);
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Set or clear the persona highlight flags and position for mode 0 (set) or 1 (clear).
// FUN_0013D7D0
void radarSetPersonaHighlight(u8 *work, s32 mode) {
    RadarPersonaMenuWork *personaMenu = (RadarPersonaMenuWork *)work;
    RadarPositionWords highlightPosition;
    RadarPositionWords normalPosition;

    switch (mode) {
    case 0:
        highlightPosition.first = 0x43030000;
        highlightPosition.second = 0xC26C0000;
        shdPersonaSetFlags(((RadarPersonaMenuWork *)(work))->personaDisplay, 0x400E0);
        shdPersonaRefreshDispCtlPosition(personaMenu->personaDisplay, &highlightPosition);
        shdPersonaSetChildDispCtlHandleAndColor(personaMenu->personaDisplay, -1, -0x7F00);
        return;
    case 1:
        normalPosition.first = 0x43030000;
        normalPosition.second = 0xC2600000;
        shdPersonaClearFlags(((RadarPersonaMenuWork *)(work))->personaDisplay, 0x400E0);
        shdPersonaRefreshDispCtlPosition(personaMenu->personaDisplay, &normalPosition);
        shdPersonaSetChildDispCtlHandleAndColor(personaMenu->personaDisplay, -1, 0xFFE92C00);
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Persona menu state machine: step the persona highlight and display states, and return the menu's
// result.
// FUN_0013D8B0
s32 radarPersonaMenuUpdate(u32 *state, s32 *active, u8 *work) {
    RadarPersonaMenuWork *personaMenu = (RadarPersonaMenuWork *)work;
    extern void radarBeginRecipientPick(u8 *work, s32 *state);
    extern void cmpPersonaMenuInit(u8 *work);
    extern s32 cmpPersonaStateStep(u8 *work);
    extern s32 cmpPersonaRowsSettled(u8 *work);
    extern void cmpPersonaMenuRelease(u8 *work);
    extern void cmpPersonaSetMode(u8 *work, s32 mode);
    extern void datScreenWipeSetTextureId(u8 *task, s32 textureId);
    extern void cmpPersonaStartScreenWipe(u8 *task, s32 presetOrColor, s32 initialize, s32 reverse);
    extern void shdPersonaSetDisplayState(u8 *state, s32 active, u32 work, s8);
    extern void cmpPersonaSetPartyCursor(u8 *work);
    extern void cmpPersonaResetRosterCursor(u8 *work);
    extern void cmpPersonaScatterGridCells(u8 *work);
    extern void shdPersonaStartSlideIn(u8 *task);
    extern void radarSetPersonaHighlight(u8 *work, s32 mode);
    u8 listState[0x30];
    f32 fadeAlpha;
    f32 fadeValue;
    s16 selectedPersona;
    s16 rosterCount;
    s32 ready;
    s32 noticeResult;
    s32 removeResult;
    s32 finished;
    s32 alphaByte;

    *active = (finished = 1);
    switch (*state) {
    case 0:
        cmpPersonaMenuInit(work);
        *state = 1;
        *active = 0;
        break;
    case 1:
        ready = (s32)(cmpPersonaStateStep(work));
        if (ready & nLineIsIdle()) {
            *state = 3;
            nLineSelectSet(0xE);
        } else {
            *active = 0;
        }
        break;
    case 2:
        if (cmpPersonaRowsSettled(work) != 0) {
            cmpPersonaMenuRelease(work);
            return 1;
        }
        break;
    case 3:
        if (cmpPersonaRowsSettled(work) != 0) {
            cmpPersonaSetMode(work, 2);
            *state = 4;
            resrcMngSuppressRender();
            datScreenWipeSetTextureId(((RadarPersonaMenuWork *)(work))->screenWipe, ((RadarPersonaMenuWork *)((u8 *)((u8 *)(((RadarPersonaMenuWork *)(work))->unk50 * 2) + (u32)work)))->characters[0]);
            cmpPersonaStartScreenWipe(personaMenu->screenWipe, 0, 1, 0);
            shdPersonaSetDisplayState(((RadarPersonaMenuWork *)(work))->personaDisplay, 0U, 0, 0);
        }
        break;
    case 4:
        if (cmpPersonaRowsSettled(work) != 0) {
            if (D_008C024E[0] & 0x20) {
                cmpPersonaSetMode(work, 1);
                *state = 2;
                resrcMngUnsuppressRender();
                nLineSelectSet(0x14);
                cmpPersonaStartScreenWipe(((RadarPersonaMenuWork *)(work))->screenWipe, 0, 0, 1);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (((RadarPersonaMenuWork *)(work))->unk50 == 0) {
                    cmpPersonaSetMode(work, 3);
                    *state = 5;
                    cmpPersonaSetSelection(work, 1, 0);
                    cmpPersonaSetPartyCursor(work);
                    cmpPersonaResetRosterCursor(work);
                    cmpPersonaScatterGridCells(work);
                    nLineSelectSet(0xF);
                    cmpPersonaStartScreenWipe(((RadarPersonaMenuWork *)(work))->screenWipe, 0, 0, 1);
                    shdPersonaSetDisplayState(((RadarPersonaMenuWork *)(work))->personaDisplay, 1U, (u32)datPersonaRosterSlot(((RadarPersonaMenuWork *)(work))->unk52), 0);
                    radarSetPersonaHighlight(work, 1);
                    shdPersonaRefreshDispCtlPosition(personaMenu->personaDisplay, NULL);
                    shdPersonaSetFlags(personaMenu->personaDisplay, 0x40000);
                    sdkSndStartStream(0, 0, 0, 1);
                } else {
                    cmpPersonaSetMode(work, 8);
                    *state = 0xA;
                    cmpPersonaSetPartyCursor(work);
                    nLineSelectSet(0x11);
                    cmpPersonaStartScreenWipe(((RadarPersonaMenuWork *)(work))->screenWipe, 0, 0, 1);
                    radarSetPersonaHighlight(work, 0);
                    shdPersonaSetDisplayState(((RadarPersonaMenuWork *)(work))->personaDisplay, ((RadarPersonaMenuWork *)((u8 *)((u8 *)(personaMenu->unk50 * 2) + (u32)work)))->characters[0], (u32)datPersonaGetRecord(((RadarPersonaMenuWork *)((u8 *)((u8 *)(personaMenu->unk50 * 2) + (u32)work)))->characters[0]), 0);
                    shdPersonaStartSlideIn(personaMenu->personaDisplay);
                    shdPersonaClearFlags(personaMenu->personaDisplay, 0x40000);
                }
            } else if (D_008C024E[0] & 0x10) {
                ((RadarPersonaMenuWork *)(work))->exitRequest = datCommunityRequestExit();
                *state = 0x10;
            } else {
                sdkListStateConfigure(listState, 8, ((RadarPersonaMenuWork *)(work))->unk34, ((RadarPersonaMenuWork *)(work))->unk50, 0);
                sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(listState) != 0) {
                    cmpPersonaSetSelection(work, 0, ((SdkListState *)listState)->row);
                    datScreenWipeSetTextureId(((RadarPersonaMenuWork *)(work))->screenWipe, ((RadarPersonaMenuWork *)((u8 *)((u8 *)(personaMenu->unk50 * 2) + (u32)work)))->characters[0]);
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
        }
        break;
    case 5:
        if (cmpPersonaRowsSettled(work) != 0) {
            cmpPersonaSetMode(work, 4);
            *state = 6;
            cmpPersonaResetRosterCursor(work);
            datScreenWipeSetTextureId(((RadarPersonaMenuWork *)(work))->screenWipe, 0U);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            cmpPersonaSetMode(work, 2);
            *state = 3;
            nLineSelectSetImmediate(0xE);
            datPersonaRemoveSelectedRosterMember();
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            datPersonaSetLeadSlot(((RadarPersonaMenuWork *)((u8 *)((u8 *)(((RadarPersonaMenuWork *)(work))->unk52 * 2) + (u32)work)))->roster[0]);
            sdkSndStartStream(1, 3, 2, 6);
            cmpPersonaRandomizeBackgroundCells(work);
        } else if (D_008C024E[0] & 0x80) {
            radarSetPersonaHighlight(work, 0);
            shdPersonaStartSlideIn(((RadarPersonaMenuWork *)(work))->personaDisplay);
            cmpPersonaSetMode(work, 6);
            cmpPersonaSetRosterCursorMotion(work);
            *state = 7;
            nLineSelectSet(0x10);
        } else if (D_008C024E[0] & 0x10) {
            selectedPersona = (s16)(((RadarPersonaMenuWork *)((u8 *)((u8 *)(((RadarPersonaMenuWork *)(work))->unk52 * 2) + (u32)work)))->roster[0]);
            if (selectedPersona == datGetActiveRosterIndex(1)) {
                nmMesWindowShowCurrentRecord(2);
                cmpPersonaSetMode(work, 0xC);
                *state = 0xF;
                sdkSndStartStream(0, 0, 0, 8);
            } else {
                nmMesWindowShowCurrentRecord(1);
                nmMesWindowSetCurrentParam(0);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                cmpPersonaSetMode(work, 0xB);
                *state = 0xE;
                sdkSndStartStream(0, 0, 0, 1);
            }
            cmpPersonaResetRosterCursor(work);
        } else {
            sdkListStateConfigure(listState, 0xC, ((RadarPersonaMenuWork *)(work))->unk4E, ((RadarPersonaMenuWork *)(work))->unk52, 0);
            sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0x2000, 0x8000);
            if (sdkListStateHandleInput(listState) != 0) {
                cmpPersonaSetSelection(work, 1, ((SdkListState *)listState)->row);
                cmpPersonaResetRosterCursor(work);
                shdPersonaSetDisplayState(((RadarPersonaMenuWork *)(work))->personaDisplay, 1U, (u32)datPersonaRosterSlot(personaMenu->unk52), 0);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 7:
        if (cmpPersonaRowsSettled(work) != 0) {
            *state = 8;
            cmpPersonaSetMode(work, 7);
        }
        break;
    case 8:
        if (cmpPersonaRowsSettled(work) != 0) {
            if (D_008C024E[0] & 0x20) {
                cmpPersonaSetMode(work, 5);
                *state = 5;
                cmpPersonaResetRosterCursor(work);
                nLineSelectSetImmediate(0xF);
                shdPersonaBeginClose(((RadarPersonaMenuWork *)(work))->personaDisplay);
                radarSetPersonaHighlight(work, 1);
            } else if (D_008C024E[0] & 0x40) {
                cmpPersonaSetMode(work, 0xA);
                nmMesWindowShowCurrentRecord(3);
                nmMesWindowSetCurrentParam(0);
                nmMesWindowSetCurrentFlag(0);
                nmMesWindowRequestRefresh();
                *state = 0xD;
                sdkSndStartStream(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                shdPersonaBeginSelection(((RadarPersonaMenuWork *)(work))->personaDisplay);
                *state = 9;
            } else if (D_008C024E[0] & 0x10) {
                datPersonaRemoveSelectedRosterMember();
                ((RadarPersonaMenuWork *)(work))->exitRequest = datCommunityRequestExit();
                shdPersonaFinishPhase(((RadarPersonaMenuWork *)(work))->personaDisplay);
                shdPersonaSetPersonaId(personaMenu->personaDisplay, 0xB1);
                *state = 0x10;
            } else {
                radarBeginRecipientPick(work, (s32 *)state);
            }
        }
        break;
    case 9:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            shdPersonaEndSelection(((RadarPersonaMenuWork *)(work))->personaDisplay, 1);
            *state = 8;
        } else if (D_008C024E[0] & 0x40) {
            cmpPersonaSetMode(work, 0xA);
            shdPersonaEndSelection(((RadarPersonaMenuWork *)(work))->personaDisplay, 0);
            nmMesWindowShowCurrentRecord(3);
            nmMesWindowSetCurrentParam(0);
            nmMesWindowSetCurrentFlag(0);
            nmMesWindowRequestRefresh();
            *state = 0xD;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            datPersonaRemoveSelectedRosterMember();
            ((RadarPersonaMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            shdPersonaFinishPhase(((RadarPersonaMenuWork *)(work))->personaDisplay);
            shdPersonaSetPersonaId(personaMenu->personaDisplay, 0xB1);
            *state = 0x10;
        } else {
            shdPersonaStepSelectionCursor(((RadarPersonaMenuWork *)(work))->personaDisplay);
            radarBeginRecipientPick(work, (s32 *)state);
        }
        break;
    case 10:
        if (cmpPersonaRowsSettled(work) != 0) {
            *state = 0xB;
            cmpPersonaSetMode(work, 7);
            datScreenWipeSetTextureId(((RadarPersonaMenuWork *)(work))->screenWipe, 0U);
        }
        break;
    case 11:
        if (D_008C024E[0] & 0x20) {
            cmpPersonaSetMode(work, 2);
            *state = 3;
            nLineSelectSetImmediate(0xE);
            shdPersonaBeginClose(((RadarPersonaMenuWork *)(work))->personaDisplay);
        } else if (D_008C024E[0] & 0x80) {
            shdPersonaBeginSelection(((RadarPersonaMenuWork *)(work))->personaDisplay);
            *state = 0xC;
        } else if (D_008C024E[0] & 0x10) {
            ((RadarPersonaMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            shdPersonaFinishPhase(((RadarPersonaMenuWork *)(work))->personaDisplay);
            shdPersonaSetPersonaId(personaMenu->personaDisplay, 0xB1);
            *state = 0x10;
        } else {
            radarBeginCharacterPick(work, state);
        }
        break;
    case 12:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            shdPersonaEndSelection(((RadarPersonaMenuWork *)(work))->personaDisplay, 1);
            *state = 0xB;
        } else if (D_008C024E[0] & 0x10) {
            ((RadarPersonaMenuWork *)(work))->exitRequest = datCommunityRequestExit();
            shdPersonaFinishPhase(((RadarPersonaMenuWork *)(work))->personaDisplay);
            shdPersonaSetPersonaId(personaMenu->personaDisplay, 0xB1);
            *state = 0x10;
        } else if (radarBeginCharacterPick(work, state) == 0) {
            shdPersonaStepSelectionCursor(((RadarPersonaMenuWork *)(work))->personaDisplay);
        }
        break;
    case 13:
        if ((cmpPersonaRowsSettled(work) != 0) && (datMemberNoticeTryBegin(1) == 0)) {
            noticeResult = nmMesWindowCurrentAnimFlag();
            switch (noticeResult) {
            case 0:
                datPersonaSetLeadSlot(((RadarPersonaMenuWork *)((u8 *)((u8 *)(((RadarPersonaMenuWork *)(work))->unk52 * 2) + (u32)work)))->roster[0]);
                sdkSndStartStream(1, 3, 2, 6);
                break;
            case 1:
                break;
            default:
                kAssertFail(D_005ED9E0, 0x220);
                break;
            }
            *state = 7;
        }
        break;
    case 14:
        if ((cmpPersonaRowsSettled(work) != 0) && (datMemberNoticeTryBegin(1) == 0)) {
            removeResult = nmMesWindowCurrentAnimFlag();
            switch (removeResult) {
            case 0:
                datPersonaRemoveRosterSlot(((RadarPersonaMenuWork *)((u8 *)((u8 *)(((RadarPersonaMenuWork *)(work))->unk52 * 2) + (u32)work)))->roster[0]);
                cmpPersonaBuildRosterList(work);
                rosterCount = (s16)(((RadarPersonaMenuWork *)(work))->unk4E);
                if (personaMenu->unk52 >= rosterCount) {
                    cmpPersonaSetSelection(work, 1, rosterCount - 1);
                }
                shdPersonaSetDisplayState(((RadarPersonaMenuWork *)(work))->personaDisplay, 1U, (u32)datPersonaRosterSlot(personaMenu->unk52), 0);
                break;
            case 1:
                break;
            default:
                kAssertFail(D_005ED9E0, 0x244);
                break;
            }
            cmpPersonaResetRosterCursor(work);
            *state = 5;
        }
        break;
    case 15:
        if (datMemberNoticeTryBegin(1) == 0) {
            cmpPersonaResetRosterCursor(work);
            *state = 5;
        }
        break;
    case 16:
        if ((++((RadarPersonaMenuWork *)(work))->fadeFrame & 0xFFFF) >= 3) {
            finished = 1;
        } else {
            fadeAlpha = (1.0f - ((f32)personaMenu->fadeFrame / 3.0f)) * 255.0f;
            alphaByte = (u8)fadeAlpha;
            ((RadarPersonaMenuWork *)work)->alpha = alphaByte;
            finished = 0;
        }
        if (finished != 0) {
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
#pragma optimization_level 2
// Open the recipient pick display for the chosen entry: set state 8 and begin the display for one
// or two picks.
// FUN_0013E7C0
void radarBeginRecipientPick(u8 *work, s32 *state) {
    RadarPersonaMenuWork *personaMenu = (RadarPersonaMenuWork *)work;
    u8 listState[0x28];
    s32 listResult;

    sdkListStateConfigure(listState, 0xC, ((RadarPersonaMenuWork *)(work))->unk4E, ((RadarPersonaMenuWork *)(work))->unk52, 0);
    sdkListStateSetActive(listState, 0);
    sdkListStateSetSecondaryMasks(listState, 8, 4, 0, 0);
    listResult = sdkListStateHandleInput(listState);
    if (listResult > 0) {
        cmpPersonaSetSelection(work, 1, ((SdkListState *)listState)->row);
        *state = 8;
        if (listResult == 1) {
            shdPersonaBeginDisplay(((RadarPersonaMenuWork *)(work))->personaDisplay, 1, (s32)datPersonaRosterSlot(personaMenu->unk52), 0);
            return;
        }
        if (listResult == 2) {
            shdPersonaBeginDisplayAndEndSelection(((RadarPersonaMenuWork *)(work))->personaDisplay, 1, (s32)datPersonaRosterSlot(personaMenu->unk52), 0);
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Open the character pick display for the chosen entry, and return 1 when a pick list was opened.
// FUN_0013E8E0
s32 radarBeginCharacterPick(u8 *work, s32 *state) {
    u8 listState[0x28];
    s32 listResult;
    s32 characterId;
    u16 character;

    sdkListStateConfigure(listState, 8, ((RadarPersonaMenuWork *)work)->unk34, ((RadarPersonaMenuWork *)work)->unk50, 0);
    sdkListStateSetActive(listState, 0);
    sdkListStateSetSecondaryMasks(listState, 8, 4, 0, 0);
    listResult = sdkListStateHandleInput(listState);
    if (listResult > 0) {
        cmpPersonaSetSelection(work, 0, ((SdkListState *)(listState))->row);
        *state = 0xB;
        characterId = character = ((RadarPersonaMenuWork *)(byteAddressAdd(MEMBER(s32, listState, SdkListState, row) * sizeof(u16), work)))->characters[0];
        if (listResult == 1) {
            shdPersonaBeginDisplay(((RadarPersonaMenuWork *)work)->personaDisplay, characterId, (s32)datPersonaGetRecord(character), 0);
        } else if (listResult == 2) {
            shdPersonaBeginDisplayAndEndSelection(((RadarPersonaMenuWork *)work)->personaDisplay, characterId, (s32)datPersonaGetRecord(character), 0);
        }
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Recipient menu state machine: step the recipient selection and entry action states, and return
// the menu's result.
// FUN_0013EA20
s32 radarRecipientMenuUpdate(u32 *state, s32 *active, u8 *work) {
    RadarSkillMenuWork *skillMenu = (RadarSkillMenuWork *)work;
    extern void cmpSkillMenuInit(u8 *work);
    extern u32 datCalcIsDeadById(s16 unitId);
    extern s32 cmpSkillStateStep(u8 *work);
    extern s32 cmpSkillRowsSettled(u8 *work);
    extern void cmpSkillFreeSprites(u8 *work);
    extern void cmpSkillSetPartyCursorMotion(u8 *work);
    extern void cmpSkillLayoutScrollRows(void *work);
    extern void cmpSkillBuildAbilityList(void *work);
    extern void radarHandleEntryAction(s32 *state, s16 active, s32 work, u8 *);
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

    *active = (finished = 1);
    characterRow = (((RadarSkillMenuWork *)(work))->unk5C);
    character = ((RadarSkillMenuWork *)(byteAddressAdd(characterRow * sizeof(s16), work)))->recipients[0];
    recipientRow = (((RadarSkillMenuWork *)(work))->unk62);
    recipientValue = recipientId = ((RadarSkillMenuWork *)(byteAddressAdd(recipientRow * sizeof(s16), work)))->recipients[0];
    skillRow = (((RadarSkillMenuWork *)(work))->unk5E);
    skillPage = (((RadarSkillMenuWork *)(work))->unk60);
    skillIndex = skillPage + skillRow;
    switch (*state) {
        case 0:
            *active = 0;
            cmpSkillMenuInit(work);
            *state = 1;
            break;
        case 1:
            ready = (cmpSkillStateStep(work));
            if (ready & nLineIsIdle()) {
                *state = 3;
                nLineSelectSet(8);
                cmpSkillSetPartyCursorMotion(work);
            } else {
                *active = 0;
            }
            break;
        case 2:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                cmpSkillFreeSprites(work);
                return 1;
            }
            break;
        case 3:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                resrcMngSuppressRender();
                *state = 4;
                cmpSkillSetMode(work, 2U);
                cmpSkillSetPartyCursorMotion(work);
            }
            break;
        case 4:
            if (D_008C024E[0] & 0x20) {
                cmpSkillSetMode(work, 1U);
                *state = 2;
                resrcMngUnsuppressRender();
                nLineSelectSet(0xA);
                sdkSndStartStream(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if ((s32)(datCalcIsDeadById(character)) != (s32)(0)) {
                    sdkSndStartStream(0, 0, 0, 8);
                } else {
                    cmpSkillSetMode(work, 3U);
                    *state = 5;
                    sdkSndStartStream(0, 0, 0, 1);
                }
            } else if (D_008C024E[0] & 0x10) {
                ((RadarSkillMenuWork *)(work))->exitRequest = (s32)(datCommunityRequestExit());
                *state = 0xD;
            } else {
                sdkListStateConfigure(query, 4, ((RadarSkillMenuWork *)(work))->unkFC, characterRow, 0);
                sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
                if ((s32)(sdkListStateHandleInput(query)) != (s32)(0)) {
                    cmpSkillSetSelection((s16 *)work, 0, ((SdkListState *)query)->row);
                    cmpSkillBuildAbilityList(work);
                    cmpSkillSetPartyCursorMotion(work);
                    sdkSndStartStream(0, 1, 0, 0);
                }
            }
            break;
        case 5:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                *state = 6;
                cmpSkillSetMode(work, 4U);
            }
            break;
        case 6:
            if (D_008C024E[0] & 0x20) {
                *state = 3;
                cmpSkillSetMode(work, 2);
                cmpSkillSetPartyCursorMotion(work);
                sdkSndStartStream(0, 0, 0, 2);
            } else {
                confirm = D_008C024E[0] & 0x40;
                if (confirm != 0) {
                    radarHandleEntryAction((s32 *)state, character, recipientValue, work);
                } else if (D_008C024E[0] & 0x80) {
                    cmpSkillSetMode(work, 9);
                    *state = 0xB;
                    sdkSndStartStream(0, 2, 0, 3);
                } else if (D_008C024E[0] & 0x10) {
                    ((RadarSkillMenuWork *)(work))->exitRequest = (s32)(datCommunityRequestExit());
                    *state = 0xD;
                } else {
                    sdkListStateConfigure(query, 6, ((RadarSkillMenuWork *)(work))->unk580, skillRow, skillPage);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
                    if ((queryResult = sdkListStateHandleInput(query)) > 0) {
                        cmpSkillSetSelection((s16 *)work, 1, ((SdkListState *)query)->row);
                        cmpSkillSetSelection((s16 *)work, 2, ((SdkListState *)query)->page);
                        if (skillMenu->unk60 != ((RadarSkillMenuWork *)(work))->unkAC) {
                            cmpSkillLayoutScrollRows(work);
                        }
                        datCommunityCursorFeedback(queryResult);
                    }
                }
            }
            break;
        case 7:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                cmpSkillSetMode(work, 6U);
                cmpSkillSetScrollCursorMotion(work);
                *state = 8;
            }
            break;
        case 8:
            if (D_008C024E[0] & 0x20) {
                cmpSkillSetMode(work, 3U);
                *state = 5;
                nLineSelectSetImmediate(8);
                sdkSndStartStream(0, 0, 0, 2);
                break;
            }
            if (D_008C024E[0] & 0x40) {
                applicationResult = (s8)cmpSkillApplySelected((s16)character, (s16)recipientId, skillIndex, work);
                switch (applicationResult) {
                case 0:
                case 1:
                    break;
                case 2:
                    cmpSkillSetMode(work, 3U);
                    *state = 5;
                    nLineSelectSetImmediate(8);
                    break;
                case 3:
                    return 2;
                }
            } else {
                if (D_008C024E[0] & 0x10) {
                    ((RadarSkillMenuWork *)(work))->exitRequest = (s32)(datCommunityRequestExit());
                    *state = 0xD;
                } else {
                    sdkListStateConfigure(query, 4, ((RadarSkillMenuWork *)(work))->unkFC, recipientRow, 0);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
                    if ((s32)(sdkListStateHandleInput(query)) != (s32)(0)) {
                        cmpSkillSetSelection((s16 *)work, 3, ((SdkListState *)query)->row);
                        cmpSkillSetScrollCursorMotion(work);
                        sdkSndStartStream(0, 1, 0, 0);
                    }
                }
                break;
            }
            break;
        case 9:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                cmpSkillSetMode(work, 8U);
                *state = 0xA;
            }
            break;
        case 10:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                if (D_008C024E[0] & 0x20) {
                    cmpSkillSetMode(work, 3U);
                    *state = 5;
                    nLineSelectSetImmediate(8);
                    sdkSndStartStream(0, 0, 0, 2);
                    break;
                }
                if (D_008C024E[0] & 0x40) {
                    allApplicationResult = (s8)cmpSkillApplySelected((s16)character, -1, skillIndex, work);
                    switch (allApplicationResult) {
                    case 0:
                    case 1:
                        break;
                    case 2:
                        cmpSkillSetMode(work, 3U);
                        *state = 5;
                        nLineSelectSetImmediate(8);
                        break;
                    case 3:
                        return 2;
                    }
                } else {
                    if (D_008C024E[0] & 0x10) {
                        ((RadarSkillMenuWork *)(work))->exitRequest = (s32)(datCommunityRequestExit());
                        *state = 0xD;
                    }
                    break;
                }
            } else {
                break;
            }
            break;
        case 11:
            if ((s32)(cmpSkillRowsSettled(work)) != (s32)(0)) {
                cmpSkillSetMode(work, 0xAU);
                *state = 0xC;
            }
            break;
        case 12:
            if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
                cmpSkillSetMode(work, 3);
                *state = 5;
                sdkSndStartStream(0, 2, 0, 4);
            } else {
                alternateConfirm = D_008C024E[0] & 0x40;
                if (alternateConfirm != 0) {
                    radarHandleEntryAction((s32 *)state, character, recipientValue, work);
                } else if (D_008C024E[0] & 0x10) {
                    ((RadarSkillMenuWork *)(work))->exitRequest = (s32)(datCommunityRequestExit());
                    *state = 0xD;
                } else {
                    sdkListStateConfigure(query, 6, ((RadarSkillMenuWork *)(work))->unk580, skillRow, skillPage);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
                    if ((alternateQueryResult = sdkListStateHandleInput(query)) > 0) {
                        cmpSkillSetSelection((s16 *)work, 1, ((SdkListState *)query)->row);
                        cmpSkillSetSelection((s16 *)work, 2, ((SdkListState *)query)->page);
                        if (skillMenu->unk60 != ((RadarSkillMenuWork *)(work))->unkAC) {
                            cmpSkillLayoutScrollRows(work);
                        }
                        datCommunityCursorFeedback(alternateQueryResult);
                    }
                }
            }
            break;
        case 13:
            if ((++((RadarSkillMenuWork *)(work))->fadeFrame & 0xFFFF) >= 3) {
                finished = 1;
            } else {
                alpha = (1.0f - ((f32)skillMenu->fadeFrame / 3.0f)) * 255.0f;
                alphaByte = (u8)alpha;
                ((RadarSkillMenuWork *)work)->alpha = alphaByte;
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
#pragma optimization_level 2
// Handle the entry action after its check: the type zero path sets state 7, and the type 1 or 2
// path sets state 9.
// FUN_0013F4D0
void radarHandleEntryAction(s32 *state, s16 character, s32 recipient, u8 *work) {
    s32 skillIndex;
    u16 targetType;

    skillIndex = ((RadarSkillMenuWork *)work)->unk60 + ((RadarSkillMenuWork *)work)->unk5E;
    if (radarEntryIsAllowed(character, skillIndex, work) == 0) {
        sdkSndStartStream(0, 0, 0, 8);
        return;
    }
    targetType = datGetSkillPropertyByte(((RadarSkillMenuWork *)(byteAddressAdd(skillIndex * sizeof(RadarSkillEntry), work)))->skills[0].skill) & 0xFFFF;
    if (targetType == 0) {
        cmpSkillSetSelection((s16 *)work, 3, 0);
        cmpSkillSetMode(work, 5);
        cmpSkillSetScrollCursorMotion(work);
        if (state != 0) {
            *state = 7;
        }
    } else {
        if ((targetType == 2) || (targetType == 1)) {
            cmpSkillSetMode(work, 7);
            if (state != 0) {
                *state = 9;
            }
        }
    }
    nLineSelectSet(9);
    sdkSndStartStream(0, 0, 0, 1);
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Return 1 when the entry's type is valid and the threshold check does not block it.
// FUN_0013F620
s32 radarEntryIsAllowed(s16 character, s32 skillIndex, u8 *work) {
    s32 allowed;
    s16 savedLeadSlot;
    s16 leadSlot;
    s32 skill;
    u8 *entry;

    allowed = 1;
    savedLeadSlot = -1;
    entry = byteAddressAdd(skillIndex * sizeof(RadarSkillEntry), work);
    skill = ((RadarSkillMenuWork *)entry)->skills[0].skill;
    leadSlot = ((RadarSkillMenuWork *)entry)->skills[0].leadSlot;
    if (datIsSkillAvailable(skill) == 0) {
        return 0;
    }
    if (leadSlot != -1) {
        savedLeadSlot = (s16)datPersonaGetLeadSlot();
        datPersonaSetLeadSlot(leadSlot);
    }
    if (datCalcThresholdTriggerById(character, skill) != 0) {
        allowed = 0;
    }
    if (savedLeadSlot != -1) {
        datPersonaSetLeadSlot(savedLeadSlot);
    }
    return allowed;
}
#pragma pop
