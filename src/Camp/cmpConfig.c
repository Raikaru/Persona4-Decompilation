#include "include_asm.h"
#include "sdktask.h"
/* Original translation unit cmpConfig.c (from __FILE__ assert strings). */
#include "type.h"
#include "sdk_snd_internal.h"

typedef struct { f32 x, y; } Vec2f;

void kAssertFail(void*, s32);
void sdkSpriteFreeNode(void *node);
void PrimAppendNode(void* list, void* node);
void datSetFlag(s32 flagId, s32 enabled);
s32 cmpConfigStepInput(u32*, s32*, u8*);
s32 nLineIsIdle(void);
void chkmemAllocSiteTag(void* file, s32 line);
void memset(void* dest, s32 value, s32 size);

void nLineSetActive(s32);
void* resourceFindByName(char*);
s32 sdkSpriteNewNode();
s32 datGetFlag(s32);
void datEntryDrawGatedByFlag39(s32 port, s32 sequence, s32 duration, s32 flags);
void radarAnimateValue(void*, s32, s32);
void datSmoothTargetStep(void*);
void sdkRenderStateSetDefault(void);
void nLineDrawSet(Vec2f position, s32 alpha, s32 setIndex, f32 depthOffset);
void sdkSpriteDrawAt(void *, f32, f32, u8, u8, u8, u8);
void sdkSpriteDrawSized(u8 *, f32, f32, f32,
                   u8, u8, u8, u8,
                   u16, u16, s16, f32, s16);
f32 sinf(f32);

void sdkSpriteDrawFooter(Vec2f unused, f32, u8, s32, s32);
void mdlEffectEmitMaskedTagPair(void);
void effMiscDrawScreenColor(void*, s32);
void mdlEffectEmitTagPair(void);
void RpSkyRenderStateSet(s32 a, s32 b);
void cmpConfigDestroy(u8*);
s32 cmpConfigUpdate(u8*);
s32 cmpConfigSetMode(u8*, s32 mode);
s32 cmpConfigSetOption(u8*, s32, s32);
void cmpConfigUpdateFrame(u8*, u8*);
void cmpConfigAnimateGraph(u8*);
void cmpConfigDraw(u8 *);
void cmpConfigDrawOnOff(u8*, s32, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(u32, u32);
extern u8 D_0064D3C8[];
extern u8 D_0064D3D8[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_0064D3B8[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B304[];
extern s32 D_0064D230[];
extern s32 D_0064D380[];
extern f32 iGpffff8170;
extern f32 iGpffff8094;
extern u8 D_00793E80[];
extern s32 D_0064D3A0[];
extern u8 D_0064CD90[];
extern u8 D_0064CF00[];
extern u8 D_0064D070[];

/* The menu owns 18 consecutive 48-byte animation records. */
typedef struct {
    Vec2f start;
    Vec2f target;
    Vec2f position;
    u8 startOpacity;
    u8 targetOpacity;
    u8 opacity;
    u8 unk1B;
    u16 startWidth;
    u16 targetWidth;
    u16 width;
    u16 startHeight;
    u16 targetHeight;
    u16 height;
    s32 startFrame;
    s32 endFrame;
} CmpConfigMotion;

/* Twenty-byte row definitions consumed by the configuration transition code. */
typedef struct {
    Vec2f target;
    u8 opacity;
    u8 pad09[3];
    s32 startFrame;
    s32 endFrame;
} CmpConfigLayout;

typedef struct {
    s16 targetHeight;
    s16 height;
    s16 unk04;
    s16 filled;
    s16 unk08;
} CmpConfigGraphEntry;

typedef struct {
    u8 opacity;
    u8 pad01[3];
    u8 flags;
    u8 pad05[3];
    Vec2f origin;
    u8 pad10[4];
    s32 backdropMode;
    s32 phase;
    s32 creationMode;
    s32 tableMode;
    u32 visible;
    s16 frame, graphFrame, graphFrame2;
    u8 pad2E[2];
    s32 selectedOption;
    s32 previousOption;
    u16 helpStyle;
    u16 timers[7];
    s32 options[6];
    s32 previousOptions[6];
    CmpConfigMotion motion[18];
    CmpConfigGraphEntry graph[11];
    u8 pad446[2];
    u8 *sprites[11];
    s32 helpTexture;
    u32 detailState;
    s32 nodeNext, nodeTail, drawCallback;
    u8 pad488[4];
    u8 *nodeContext;
    u8 pad490[0x1C];
    u16 tableIndex;
    u8 pad4AE[2];
} CmpConfigWork;
typedef char CmpConfigWorkSize[sizeof(CmpConfigWork) == 0x4B0 ? 1 : -1];

typedef struct { u8 red, green, blue, alpha; } CmpConfigColor;
typedef union { CmpConfigColor rgba; f32 transport; } CmpConfigColorSnapshot;


// Creates the config overlay task under the parent: allocates its 0x4B0-byte work block, installs
// the detail step and destroy callbacks, and for mode 1 also runs nLineSetActive(1).
// FUN_0035C690
s32 cmpConfigCreate(void* parentTask, s32 mode) {
    s32 task;
    u8* work;

    chkmemAllocSiteTag(D_0064D3C8, 0xC5);
    work = D_008873F4[0](1, 0x4B0, 0x40000);
    if (work == NULL) {
        kAssertFail(D_0064D3C8, 0xC6);
    }
    task = (s32)kwlnTaskCreateChild((void *)((s32)parentTask), (const void *)(D_0064D3D8), 0xC7, 0, 0, cmpConfigUpdate, cmpConfigDestroy, (u8 *)(work));
    memset(work + 0x47C, 0, 0x30);
    ((CmpConfigWork *)work)->drawCallback = (s32)cmpConfigUpdateFrame;
    ((CmpConfigWork *)work)->nodeContext = work;
    ((CmpConfigWork *)work)->tableIndex = 0xB1;
    ((CmpConfigWork *)work)->creationMode = mode;
    switch (mode) {
    case 0:
        break;
    case 1:
        nLineSetActive(1);
        break;
    default:
        kAssertFail(D_0064D3C8, 0xE6);
        break;
    }
    return task;
}

// Returns whether the config detail step has finished (menu state bit 0x1).
// FUN_0035C7D0
s32 cmpConfigIsStepDone(u8 *task) {
    return (s32)((((SdkTask *)((s8 *)task))->work)[4] & 1) != 0;
}

// Returns whether the detail step ended with its second result (menu state bit 0x4) [inferred: cancelled].
// FUN_0035C7F0
s32 cmpConfigIsStepCancelled(u8 *task) {
    return (s32)((((SdkTask *)((s8 *)task))->work)[4] & 4) != 0;
}

// Returns whether the config flags have been synced (menu state bit 0x2, set by cmpConfigSyncFlags).
// FUN_0035C810
s32 cmpConfigIsFlagsSynced(u8 *task) {
    return (s32)((((SdkTask *)((s8 *)task))->work)[4] & 2) != 0;
}

// Resets the config menu state: clears the option values and cursor, then selects table mode 0 through cmpConfigSetMode.
// FUN_0035C830
void cmpConfigInitState(u8* work) {
    CmpConfigWork *menu = (CmpConfigWork *)work;
    s32 resource;
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    u8* table;
    u8* src;
    u8* dst;
    u8 code;
    s32 result;

    menu->tableMode = -1;
    cmpConfigSetMode(work, 0);
    *(s32 *)&menu->origin.x = 0;
    *(s32 *)&menu->origin.y = 0;
    menu->opacity = 0xFF;
    menu->phase = 0;
    menu->tableMode = -1;
    for (i = 0; i <= 0; i++) {
        ((CmpConfigWork *)(work + i * 4))->selectedOption = 0;
    }
    j = 0;
    table = D_0064D070;
    for (; j < 18; j++) {
        src = table + j * 20;
        dst = work + j * 48;
        ((CmpConfigWork *)dst)->motion[0].position.x = ((CmpConfigLayout *)src)->target.x;
        ((CmpConfigWork *)dst)->motion[0].position.y = ((CmpConfigLayout *)src)->target.y;
        ((CmpConfigWork *)dst)->motion[0].opacity = ((CmpConfigLayout *)src)->opacity;
    }
    resource = (s32)(u32)resourceFindByName((char *)D_005E5850);
    if (resource == 0) {
        kAssertFail(D_0064D3C8, 0x12F);
    }
    result = (s32)(u32)resourceFindByName((char *)D_005E57F0);
    menu->helpTexture = result;
    for (k = 0; k < 11; k++) {
        dst = work + k * 4 + 0x448;
        code = D_0064D3B8[k];
        *(s32 *)dst = sdkSpriteNewNode(resource, code);
        if (*(s32 *)dst == 0) {
            kAssertFail(D_0064D3C8, 0x136);
        }
    }
    for (m = 0; m < 6; m++) {
        ((CmpConfigWork *)(work + m * 2))->timers[0] = 5;
        result = datGetFlag(D_0064D3A0[m]);
        if (result != 0) {
            ((CmpConfigWork *)(work + m * 4))->previousOptions[0] = 0;
            ((CmpConfigWork *)(work + m * 4))->options[0] = 1;
        } else {
            ((CmpConfigWork *)(work + m * 4))->previousOptions[0] = 1;
            ((CmpConfigWork *)(work + m * 4))->options[0] = 0;
        }
    }
}


// Records a new value for slot idx and keeps the previous one; slot 0 sets the display offset from whether val is 6.
// FUN_0035CAB0
s32 cmpConfigSetValue(u8 *work, s32 slotIndex, s32 value) {
    s32 scaled = slotIndex * 4;
    u8 *slotBase = (u8 *)(scaled + (int)work);

    ((CmpConfigWork *)slotBase)->previousOption = ((CmpConfigWork *)slotBase)->selectedOption;
    ((CmpConfigWork *)slotBase)->selectedOption = value;
    if (slotIndex == 0) {
        if (value == 6) {
            ((CmpConfigWork *)work)->helpStyle = 0;
        } else {
            ((CmpConfigWork *)work)->helpStyle = 0x12;
        }
    }
    return 1;
}

// Toggles an option between its on and off states and applies side effects through
// cmpConfigSetOption; returns 0 when refused.
// FUN_0035CB00
s32 cmpConfigToggleOption(u8* work, s32 optionIndex) {
    s32 scaled;
    s32 timerOffset;
    s32* statePtr;
    s32 state;
    s32 newState;
    s32 allowed;
    s32 savedFlag;

    scaled = optionIndex * 4;
    statePtr = &((CmpConfigWork *)(scaled + (u32)work))->options[0];
    state = *statePtr;
    newState = ((u32)*statePtr != 0) ^ 1;
    if (optionIndex == 1) {
        if ((newState == 0) && (((CmpConfigWork *)work)->options[2] != 0)) {
            cmpConfigSetOption(work, 2, 0);
        }
    } else if ((optionIndex == 2) && (((CmpConfigWork *)work)->options[1] == 0)) {
        sdkSndStartStream(0, 0, 0, 8);
        allowed = 0;
        goto done;
    }
    allowed = 1;
done:
    if (allowed != 0) {
        goto apply;
    }
    return 0;
apply:
    ((CmpConfigWork *)(scaled + (int)work))->previousOptions[0] = state;
    *statePtr = ((u32)state > 0) ^ 1;
    timerOffset = optionIndex * 2;
    ((CmpConfigWork *)(timerOffset + (int)work))->timers[0] = 0;
    if ((optionIndex == 0) && (*statePtr == 1)) {
        savedFlag = datGetFlag(D_0064D3A0[0]);
        datSetFlag(D_0064D3A0[0], 1);
        datEntryDrawGatedByFlag39(0xA, 0x96, 0xA, 0);
        datSetFlag(D_0064D3A0[0], savedFlag);
    }
    return 1;
}


// Sets an option to value and keeps the old value; slot 1 turning off also clears slot 2, and slot
// 0 replays the flag draw.
// FUN_0035CC80
s32 cmpConfigSetOption(u8 *work, s32 optionIndex, s32 value)
{
    s32 savedFlag;
    s32 allowed;
    u8 *optionSlot;

    optionSlot = (u8 *)&((CmpConfigWork *)((u8 *)(optionIndex * 4) + (u32)work))->options[0];
    if (*(s32 *)optionSlot == value) {
        return 0;
    }
    if (optionIndex == 1) {
        if ((value == 0) && (((CmpConfigWork *)work)->options[2] != 0)) {
            cmpConfigSetOption(work, 2, 0);
        }
        goto block_9;
    }
    if ((optionIndex == 2) && (((CmpConfigWork *)work)->options[1] == 0)) {
        sdkSndStartStream(0, 0, 0, 8);
        allowed = 0;
    } else {
block_9:
        allowed = 1;
    }
    if (allowed == 0) {
        return 0;
    }
    ((CmpConfigWork *)((u8 *)(optionIndex * 4) + (u32)work))->previousOptions[0] =
        ((CmpConfigWork *)((u8 *)(optionIndex * 4) + (u32)work))->options[0];
    ((CmpConfigWork *)((u8 *)(optionIndex * 4) + (u32)work))->options[0] = value;
    *(s16 *)&((CmpConfigWork *)((u8 *)(optionIndex * 2) + (u32)work))->timers[0] = 0;
    if ((optionIndex == 0) && (*(s32 *)optionSlot == 1)) {
        savedFlag = datGetFlag(D_0064D3A0[0]);
        datSetFlag(D_0064D3A0[0], 1);
        datEntryDrawGatedByFlag39(0xA, 0x96, 0xA, 0);
        datSetFlag(D_0064D3A0[0], savedFlag);
    }
    return 1;
}


// Switches the config table to mode 0, 1 or 2 and loads its 18-row layout; unknown modes assert.
// FUN_0035CE10
s32 cmpConfigSetMode(u8* work, s32 mode) {
    CmpConfigWork *menu = (CmpConfigWork *)work;
    u8* layoutTable = 0;
    s32 i;
    s32 j;

    if (menu->tableMode == mode) {
        return 0;
    }
    for (i = 0; i < 18; i++) {
        ((CmpConfigWork *)(work + i * 48))->motion[0].start.x = ((CmpConfigWork *)(work + i * 48))->motion[0].position.x;
        ((CmpConfigWork *)(work + i * 48))->motion[0].start.y = ((CmpConfigWork *)(work + i * 48))->motion[0].position.y;
        ((CmpConfigWork *)(work + i * 48))->motion[0].startOpacity = ((CmpConfigWork *)(work + i * 48))->motion[0].opacity;
    }
    switch (mode) {
    case 0:
        layoutTable = D_0064CD90;
        menu->visible = 3;
        menu->helpStyle = 0x12;
        break;
    case 1:
        layoutTable = D_0064D070;
        menu->visible = 3;
        break;
    case 2:
        layoutTable = D_0064CF00;
        menu->visible = 3;
        break;
    default:
        kAssertFail(D_0064D3C8, 0x207);
        break;
    }
    if (layoutTable != 0) {
        for (j = 0; j < 18; j++) {
            ((CmpConfigWork *)(work + j * 48))->motion[0].target.x = ((CmpConfigLayout *)(layoutTable + j * 20))->target.x;
            ((CmpConfigWork *)(work + j * 48))->motion[0].target.y = ((CmpConfigLayout *)(layoutTable + j * 20))->target.y;
            ((CmpConfigWork *)(work + j * 48))->motion[0].targetOpacity = ((CmpConfigLayout *)(layoutTable + j * 20))->opacity;
            ((CmpConfigWork *)(work + j * 48))->motion[0].startFrame = ((CmpConfigLayout *)(layoutTable + j * 20))->startFrame;
            ((CmpConfigWork *)(work + j * 48))->motion[0].endFrame = ((CmpConfigLayout *)(layoutTable + j * 20))->endFrame;
        }
        menu->tableMode = mode;
        *(u16 *)&menu->frame = 0;
    }
    return 1;
}

// Advances the config phase from 0 to 1; returns 1 in phases 0 and 1, else 0.
// FUN_0035CFB0
s32 cmpConfigAdvancePhase(u8 *work) {
    CmpConfigWork *menu = (CmpConfigWork *)work;
    s32 phase = menu->phase;

    switch (phase) {
    case 0:
        phase += 1;
        menu->phase = phase;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// Per-frame update: advances the frame counter (capped at 100), animates the 18 rows, runs the graph animation and draws the screen.
// FUN_0035D000
void cmpConfigUpdateFrame(u8* unusedNode, u8* work) {
    CmpConfigWork *menu = (CmpConfigWork *)work;
    s32 i;

    if (menu->frame < 0x64) {
        menu->frame = menu->frame + 1;
    }
    for (i = 0; i < 18; i++) {
        s16 frame = menu->frame;

        radarAnimateValue(work + i * 48 + 0x78, frame, 0);
    }
    cmpConfigAnimateGraph(work);
    cmpConfigDraw(work);
}


/* Draws the config screen: live graph, option rows, reset button and help text. The position/color
 * records are shared by all draw phases. */
// FUN_0035D0A0
#pragma push
/* measured: retail needs constants left in place, no propagation, and original lifetimes together;
 * no single setting suffices. */
#pragma opt_pulloutconstants off
#pragma opt_propagation off
#pragma opt_lifetimes on

void cmpConfigDraw(u8 *work) {
    extern int frFontExDrawText(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags,
                             int unused);
    extern int frFontExDrawTextWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags,
                             int charWidth);
    CmpConfigWork *menu;
    s32 selectedOption;
    s32 backdropMode;
    s32 textColor;
    s32 index;
    s32 cellIndex;
    s32 pendingOption;
    s32 selected;
    u8 *sprite;
    u8 *buttonColor;
    u8 rowBlue;
    CmpConfigColorSnapshot color;
    u8 alpha;
    Vec2f pos;
    f32 fade;
    f32 baseX;
    f32 baseY;
    f32 graphX;
    f32 graphY;
    f32 topAlpha;
    f32 filledAlpha;

    menu = (CmpConfigWork *)work;
    sdkRenderStateSetDefault();
    baseX = menu->origin.x;
    baseY = menu->origin.y;
    fade = (f32)menu->opacity / 255.0f;
    selectedOption = menu->selectedOption;
    backdropMode = menu->backdropMode;
    if (backdropMode != 0) {
        pos.x = baseX;
        pos.y = baseY;
        alpha = (u8)(255.0f * fade);
        nLineDrawSet(pos, alpha, backdropMode, 0.0f);
    }
    if ((menu->visible & 1) != 0) {
        pos.x = 26.0f + (baseX + menu->motion[0].position.x);
        pos.y = 388.0f + (baseY + menu->motion[0].position.y);
        alpha = (u8)((f32)menu->motion[0].opacity * fade);
        sprite = menu->sprites[0];
        sdkSpriteDrawAt(sprite, pos.x, pos.y, 0x5E, 0x37, 0xFF, alpha);
    }
    if ((menu->visible & 2) != 0) {
        {
            u8 *graphEntry, *graphSprite;
            graphX = (baseX + menu->motion[17].position.x) - 23.0f;
            graphY = baseY + menu->motion[17].position.y;
            alpha = (u8)((f32)menu->motion[17].opacity * fade);
            graphSprite = menu->sprites[10];
            index = 0;
            topAlpha = 0.6f * (f32)alpha;
            filledAlpha = 0.5f * (f32)alpha;
            for (; index < 11; index++) {
                pos.x = graphX + (f32)(index * 45);
                cellIndex = 0;
                /* Live graph counters may change during sprite callbacks. */
                graphEntry = work + index * 10;
                for (; cellIndex < ((CmpConfigWork *)graphEntry)->graph[0].height; cellIndex++) {
                    if (cellIndex == ((CmpConfigWork *)graphEntry)->graph[0].height - 1) {
                        color.rgba.red = 0xFF;
                        color.rgba.green = 0xFF;
                        color.rgba.blue = 0xA4;
                        color.rgba.alpha = (u8)topAlpha;
                    } else if (cellIndex < ((CmpConfigWork *)graphEntry)->graph[0].filled) {
                        color.rgba.red = 0xFE;
                        color.rgba.green = 0xFF;
                        color.rgba.blue = 0x56;
                        color.rgba.alpha = (u8)filledAlpha;
                    } else {
                        continue;
                    }
                    pos.y = graphY + (f32)(cellIndex * 17);
                    sdkSpriteDrawAt(graphSprite, pos.x, pos.y, color.rgba.red, color.rgba.green, color.rgba.blue,
                                  color.rgba.alpha);
                }
            }
        }
        index = 0;
        pendingOption = -1;
        for (; index < 7; index++) {
            {
                f32 optionX, optionY;
                CmpConfigMotion *optionRow;
                u8 green;
                f32 pairY;
                /* Signed row offsets retain the work-relative option view. */
                optionRow = (CmpConfigMotion *)(work + index * 48 + 0xA8);
                optionX = baseX + optionRow->position.x;
                optionY = (f32)index * 32.0f + (baseY + optionRow->position.y);
                pos.x = 219.0f + optionX;
                pos.y = 119.0f + optionY;
                alpha = (u8)((f32)optionRow->opacity * fade);
                if ((index == 2) && (menu->options[1] == 0)) {
                    color.rgba.red = 0xA0;
                    color.rgba.green = 0xA0;
                    color.rgba.blue = 0xA0;
                } else {
                    color.transport = *(f32 *)D_0064B2E0;
                }
                sprite = menu->sprites[1];
                rowBlue = color.rgba.blue;
                green = color.rgba.green;
                pairY = pos.y;
                sdkSpriteDrawAt(sprite, pos.x, pairY, color.rgba.red, green, rowBlue, alpha);
                sprite = menu->sprites[2];
                sdkSpriteDrawAt(sprite, 380.0f + pos.x, pairY, color.rgba.red, green, rowBlue, alpha);
                if (index == selectedOption) {
                    u8 *selectedPalette;
                    selected = 1;
                    selectedPalette = D_0064B2E8;
                    sprite = menu->sprites[6];
                    sdkSpriteDrawAt(sprite, pos.x, pairY, selectedPalette[0], selectedPalette[1], selectedPalette[2],
                                  alpha);
                    sprite = menu->sprites[8];
                    sdkSpriteDrawAt(sprite, 247.0f + pos.x, pairY, selectedPalette[0], selectedPalette[1],
                                  selectedPalette[2], alpha);
                    if ((index == 2) && (menu->options[1] == 0)) {
                        textColor = (alpha & 0xFF) | 0xB4B4B400;
                    } else {
                        textColor = (alpha & 0xFF) | 0xFFFFFF00;
                    }
                } else {
                    selected = 0;
                    if (index == 2) {
                        textColor = (((u32)(0x80) << 24) | ((u32)(0x80) << 16) | ((u32)(0x80) << 8) | (alpha));
                    } else {
                        textColor = (alpha & 0xFF) | 0x80808000;
                    }
                }
                pos.x = (f32)0x1C7 + optionX;
                pos.y = 122.0f + optionY;
                frFontExDrawTextWithCharWidth(pos.x, pos.y, 0.0f, textColor, 8, 1, (const char *)D_0064D230[index], 2, -1);
            }
            if (index != 6) {
                u16 *timer = &menu->timers[index];
                if (*timer >= 5) {
                    cmpConfigDrawOnOff(work, index, 0);
                } else {
                    if (pendingOption != -1) {
                        cmpConfigDrawOnOff(work, pendingOption, 1);
                        cmpConfigDrawOnOff(work, pendingOption, 2);
                    }
                    pendingOption = index;
                    *timer = *timer + 1;
                }
            } else {
                u8 *button;
                f32 *buttonX;
                f32 *buttonY;
                u8 *buttonPalette;
                /* Keep the field addresses, not their values, across callbacks.
                   This is a size-based lookup in the second animation group. */
                button = work + index * sizeof(CmpConfigMotion);
                buttonX = &((CmpConfigWork *)button)->motion[8].position.x;
                pos.x = (f32)0x1CF + (baseX + *buttonX);
                buttonY = &((CmpConfigWork *)button)->motion[8].position.y;
                pos.y = (f32)0x137 + (baseY + *buttonY);
                buttonPalette = D_0064B2E8;
                sprite = menu->sprites[7];
                sdkSpriteDrawAt(sprite, pos.x, pos.y, buttonPalette[0], buttonPalette[1], buttonPalette[2], alpha);
                sprite = menu->sprites[8];
                sdkSpriteDrawAt(sprite, 150.0f + pos.x, pos.y, buttonPalette[0], buttonPalette[1], buttonPalette[2],
                              alpha);
                pos.x = (f32)0x205 + (baseX + *buttonX);
                pos.y = (f32)0x13F + (baseY + *buttonY);
                sprite = menu->sprites[9];
                if (selected != 0) {
                    buttonColor = D_0064B2EC;
                } else {
                    buttonColor = D_0064B304;
                }
                sdkSpriteDrawAt(sprite, pos.x, pos.y, buttonColor[0], buttonColor[1], buttonColor[2], alpha);
            }
        }
        if (pendingOption != -1) {
            cmpConfigDrawOnOff(work, pendingOption, 1);
            cmpConfigDrawOnOff(work, pendingOption, 2);
        }
        pos.x = (f32)0x26B + (baseX + menu->motion[15].position.x);
        pos.y = (f32)0x15B + (baseY + menu->motion[15].position.y);
        alpha = (u8)((f32)menu->motion[15].opacity * fade);
        textColor = alpha | ~0xFF;
        frFontExDrawText(pos.x, pos.y, 0.0f, textColor, 6, 1, (const char *)D_0064D380[selectedOption], 2, 0);
    }
    pos.x = 640.0f + (baseX + menu->motion[16].position.x);
    pos.y = 400.0f + (baseY + menu->motion[16].position.y);
    alpha = (u8)((f32)menu->motion[16].opacity * fade);
    sdkSpriteDrawFooter(pos, 0.0f, alpha, menu->helpStyle, menu->helpTexture);
}

#pragma pop

// Returns whether every row value has reached its threshold and the shared check passes.
// FUN_0035DCC0
s32 cmpConfigAllRowsMet(u8 *work) {
    s32 settled = 1;
    s32 i = 0;
    s32 frame = ((CmpConfigWork *)work)->frame;

    while (i < 18) {
        if (frame < ((CmpConfigWork *)(work + i * 48))->motion[0].endFrame) {
            settled = 0;
        }
        i++;
    }
    return settled & nLineIsIdle();
}

// Marks the flags synced (menu state bit 0x2) and writes each of the six config data flags from its option value.
// FUN_0035DD40
void cmpConfigSyncFlags(u8* work) {
    s32 i;

    ((CmpConfigWork *)work)->flags |= 2;
    for (i = 0; i < 6; i++) {
        if (((CmpConfigWork *)(work + i * 4))->options[0] != 0) {
            datSetFlag(D_0064D3A0[i], 1);
        } else {
            datSetFlag(D_0064D3A0[i], 0);
        }
    }
}

// Advances the graph phase counters and sets each of the 11 graph bars from its distance to the top
// and bottom targets.
// FUN_0035DDF0
void cmpConfigAnimateGraph(u8 *work)
{
    CmpConfigWork *menu = (CmpConfigWork *)work;
    s32 top; s32 bottom; s32 i; s32 topDistance; s32 bottomDistance; s64 score; s16 topHeight; s16 bottomHeight; u8 *barBase;
    menu->graphFrame = menu->graphFrame + 1;
    if (menu->graphFrame >= 0x19) menu->graphFrame = 0;
    menu->graphFrame2 = menu->graphFrame2 + 1;
    if (menu->graphFrame2 >= 0x1E) menu->graphFrame2 = 0;
    top = (s32)((11.0f * (f32)menu->graphFrame) / 25.0f);
    bottom = (s32)(11.0f * (1.0f - ((f32)menu->graphFrame2 / 30.0f)));
    i = 0;
    while (i < 0xB) {
        if (i < top) topDistance = top - i; else topDistance = i - top;
        if (i < bottom) bottomDistance = bottom - i; else bottomDistance = i - bottom;
        score = 1;
        topHeight = (s16)(10 - topDistance * 2);
        if (topHeight > 1) score = topHeight;
        bottomHeight = (s16)(8 - bottomDistance * 2);
        if (score < bottomHeight) score = bottomHeight;
        barBase = work + i * 0xA;
        ((CmpConfigWork *)barBase)->graph[0].targetHeight = (s16)score;
        datSmoothTargetStep(barBase + 0x3D8);
        i++;
    }
}


/* Draws the option arrows and their text for the selected row, with the selection's fade and
 * offset. The second arrow reloads its counter and selection but reuses the first arrow's sprite
 * and coordinates. */
// FUN_0035DFB0
/* Raw row-field addresses keep retail's address addition order; typed row pointers change it. */
void cmpConfigDrawOnOff(u8 *work, s32 optionIndex, s32 drawMode)
{
    u8 color[4];
    f32 opacity;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 phase;
    f32 angle;
    f32 rowY;
    f32 rowOpacity;
    u8 arrowAlpha;
    u8 otherColor;
    u8 *sprite;
    u8 alpha;
    u8 *row;
    u16 counter;
    u32 counterAddress;
    u32 rowAddress;
    f32 *rowXField;
    f32 *rowYField;

    baseX = ((CmpConfigWork *)work)->origin.x;
    baseY = ((CmpConfigWork *)work)->origin.y;
    opacity = (f32)*work / 255.0f;
    if (drawMode != 1) {
        rowAddress = optionIndex * 0x30;
        rowAddress += (u32)work;
        row = (u8 *)rowAddress;
        x = 60.0f + (464.0f + (baseX + ((CmpConfigWork *)row)->motion[8].position.x));
        y = (119.0f + (baseY + ((CmpConfigWork *)row)->motion[8].position.y)) + 32.0f * (f32)optionIndex;
        arrowAlpha = (u8)((f32)((CmpConfigWork *)row)->motion[8].opacity * opacity);
        sprite = ((CmpConfigWork *)work)->sprites[5];
        counterAddress = optionIndex * 2;
        counterAddress += (u32)work;
        counter = ((CmpConfigWork *)counterAddress)->timers[0];
        if ((s32)counter < 5)
            phase = sinf((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(work + 0x48))[optionIndex] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        sdkSpriteDrawSized(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, arrowAlpha,
                      0x1000, 0x1000, 0x11, angle, 0x11);
    }
    if (drawMode == 2) {
        mdlEffectEmitMaskedTagPair();
        D_00887300[0](1, 0);
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0;
        effMiscDrawScreenColor(color, 0);
        counterAddress = optionIndex * 2;
        counterAddress += (u32)work;
        counter = ((CmpConfigWork *)counterAddress)->timers[0];
        if ((s32)counter < 5)
            phase = sinf((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(work + 0x48))[optionIndex] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        sdkSpriteDrawSized(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, 0xFF,
                      0x1000, 0x1000, 0x11, angle, 0x11);
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(3, 0x2D801);
        RpSkyRenderStateSet(2, 0x44);
    }
    rowOpacity = (f32)work[optionIndex * 0x30 + 0xC2];
    rowOpacity *= opacity;
    alpha = (u8)rowOpacity;
    if (drawMode == 1) {
        color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0x80;
    } else if (drawMode == 2) {
        color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0xFF;
    } else {
        counterAddress = optionIndex * 4;
        counterAddress += (u32)work;
        if (((CmpConfigWork *)counterAddress)->options[0] != 0) {
            color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0x80;
        } else {
            color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0xFF;
        }
    }
    rowXField = &((f32 *)(work + 0x208))[optionIndex * 12];
    x = (f32)0x1DD;
    x = x + (baseX + *rowXField);
    rowYField = (f32 *)(optionIndex * 0x30 + work + 0x20C);
    rowY = 32.0f * (f32)optionIndex;
    sdkSpriteDrawAt(((CmpConfigWork *)work)->sprites[3], x,
                  rowY + (121.0f + (baseY + *rowYField)),
                  color[0], color[1], color[2], alpha);
    sdkSpriteDrawAt(((CmpConfigWork *)work)->sprites[4],
                  556.0f + (baseX + *rowXField),
                  rowY + (131.0f + (baseY + *rowYField)),
                  otherColor, otherColor, otherColor, alpha);
    if (drawMode == 2) {
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
}

// Frees the 11 sprite nodes of the config menu and clears the sprite count.
// FUN_0035E6A0
void cmpConfigFreeSprites(u8* work) {
    s32 i;

    for (i = 0; i < 0xB; i++) {
        u8* slotBase = work + i * 4;
        s32 sprite = *(s32 *)&((CmpConfigWork *)slotBase)->sprites[0];

        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *(s32 *)&((CmpConfigWork *)(work + i * 4))->sprites[0] = 0;
        }
    }
    *(s32 *)&((CmpConfigWork *)work)->visible = 0;
}

// Overlay task update: runs the detail step, sets the done bit (0x1) when it returns 1, and the
// cancel bit (0x4) on its second result.
// FUN_0035E720
s32 cmpConfigUpdate(u8* task) {
    u8* work = ((SdkTask *)task)->work;
    s32 changed;

    if (work[4] & 1) {
        return 0;
    }
    switch (cmpConfigStepInput(&((CmpConfigWork *)work)->detailState, &changed, work)) {
    case 0:
        if (changed != 0) {
            ((CmpConfigWork *)work)->nodeNext = 0;
            ((CmpConfigWork *)work)->nodeTail = 0;
            PrimAppendNode(D_00793E80 + ((CmpConfigWork *)work)->tableIndex * 48, work + 0x47C);
        }
        break;
    case 2:
        work[4] |= 4;
        /* fallthrough */
    case 1:
        work[4] |= 1;
        break;
    default:
        kAssertFail(D_0064D3C8, 0x49E);
        break;
    }
    return 0;
}
