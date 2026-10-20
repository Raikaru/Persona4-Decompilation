/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00361970-00362f00 */

#include "include_asm.h"
#include "member_access.h"
#include "type.h"
#include "operand_order_internal.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
#include "rw_types_internal.h"
#include "radar_menu_internal.h"

/* Start/end positions, interpolated output, and a halfword frame pair. */
typedef struct CmpPartyRowMotion {
    f32 startX, startY, endX, endY, x, y;
    s16 frame, duration;
} CmpPartyRowMotion;

/* sdkListState.c clears 0x2C bytes; these outputs are read as low halfwords. */
typedef struct SdkListState {
    u8 pad0[0x24];
    s16 cursor;
    u8 pad26[2];
    s16 scroll;
    u8 pad2A[2];
} SdkListState;
extern void radarAnimateValue(u8 *work, s16 frame, s32 mode);
extern s32 nLineIsIdle(void);
extern u32 datGetFlag(s32 bit);
extern s32 cmpSystemSetSelection(u8 *work, s32 mode, s16 selection);
extern void datSmoothTargetStep(void *transition);
extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern void nmMesWindowDestroySlot(s8 slotIndex);
extern f32 iGpffff84a4;
extern void kAssertFail(const void *file, s32 line);
extern char D_0064E280[];
extern f32 cosf(f32 object);
extern void cmpSystemFocusFlaggedRow(u8 *work);
extern void cmpSystemMenuInit(u8 *work);
extern s32 datCommunityPanelOpenStepAlt(u8 *work);
extern s32 cmpSystemSetMode(u8 *work, u32 mode);
extern void nLineSelectSet(s32 setIndex);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datCommunityCursorFeedback(s32 direction);
extern s32 cmpConfigCreate(void *parentTask, s32 mode);
extern s32 cmpConfigIsStepDone(u8 *task);
extern s32 cmpConfigIsStepCancelled(u8 *task);
extern s32 nmMesWindowShowSlotRecord(s8 slotIndex, s32 recordIndex);
extern void nmMesWindowSetSlotParam(s8 slotIndex, s32 recordIndex);
extern void nmMesWindowSetSlotFlag(s8 slotIndex, s32 cursor);
extern void nmMesWindowRequestRefresh(void);
extern s32 nmMesWindowSlotResult(s8 slotIndex);
extern void nmMesWindowCloseSlot(s8 slotIndex, s32 release);
extern s32 nmMesWindowSlotStatus(s8 slotIndex);
extern void nmMesWindowStepSlot(s32 slotIndex, s32 release);
extern void sdkListStateConfigure(void *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern void sdkListStateSetSecondaryMasks(void *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern s32 sdkListStateHandleInput(void *state);
extern void sdkSndStopChannel(s32 fadeFrames);
extern void sdkSndFadeOutChannelFrames(s32 channelIndex, s32 requestValue, s32 fadeFrames);
extern void sequenceRequest(s32 sequenceId, s32 parameters, s32 parameterSize, s32 delay);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern s32 fadeStatus(void);
extern u16 D_008C024E[];
/* Reset the slide timer and choose its horizontal direction from old/new scroll rows. */
// FUN_00361970
void radarResetSlideDirection(u8 *work)
{
    ((RadarMenuWork *)work)->slide.targetY.s = 0;
    if (((RadarMenuWork *)work)->topRow > ((RadarMenuWork *)work)->previousTopRow) {
        ((RadarMenuWork *)work)->slide.startY.f = -10.0f;
    } else {
        ((RadarMenuWork *)work)->slide.startY.f = 10.0f;
    }
    ((RadarMenuWork *)work)->slideElapsed = 0;
}

/* Return true once every panel's end frame has elapsed and nLine is idle. */
// FUN_003619B0
s32 radarRowsSettled(u8 *work) {
    s32 allSettled = 1;
    s32 rowIndex = 0;
    s32 frame = ((RadarMenuWork *)work)->elapsed;

    while (rowIndex < 29) {
        if (frame < ((RadarMenuWork *)work)->panels[rowIndex].endFrame.s) {
            allSettled = 0;
        }
        rowIndex++;
    }
    return allSettled & nLineIsIdle();
}

/* Release the 42 menu sprites, optional config task, and owned message slot. */
// FUN_00361A30
void cmpSystemMenuRelease(u8 *work)
{
    s32 spriteAddress;
    s32 configTask;
    s32 spriteIndex;
    s8 messageSlot;
    u8 *spriteSlot;

    /* measured: typed child/message reset stores retain addresses across destroy calls (184 versus 176 bytes). */
    spriteIndex = 0;
    while (spriteIndex < 0x2A) {
        spriteSlot = (u8 *)&((RadarMenuWork *)work)->sprites[spriteIndex];
        spriteAddress = ((RadarSprite *)spriteSlot)->handle;
        if (spriteAddress != 0) {
            sdkSpriteFreeNode((void *)spriteAddress);
            ((RadarSprite *)spriteSlot)->handle = 0;
        }
        spriteIndex += 1;
    }
    configTask = ((RadarMenuWork *)work)->configTask.handle;
    if (configTask != 0) {
        kwlnTaskDestroyWithHierarchy(configTask);
        MEMBER(s32, work, RadarMenuWork, configTask.handle) = 0;
    }
    messageSlot = ((RadarMenuWork *)work)->messageSlot;
    if (messageSlot != -1) {
        nmMesWindowDestroySlot(messageSlot);
        MEMBER(s8, work, RadarMenuWork, messageSlot) = -1;
    }
    ((RadarMenuWork *)work)->drawFlags = 0;
}

/* Drive two traveling peaks over eleven bars, smoothing each requested height. */
// FUN_00361AE0
void radarStepBarWave(u8 *work)
{
    s32 topWave;
    s32 bottomWave;
    s32 column;
    s32 topDistance;
    s32 bottomDistance;
    s64 height;
    s16 topHeight;
    s16 bottomHeight;
    u8 *barBase;

    /* measured: typing the repeated counter reads/stores changes 336 normalized bytes;
     * retain the retail halfword reloads, with only their initial loads typed. */
    ((RadarMenuWork *)(work))->topWaveFrame = ((RadarMenuWork *)work)->topWaveFrame + 1;
    if (((RadarMenuWork *)(work))->topWaveFrame >= 0x19) MEMBER(s16, work, RadarMenuWork, topWaveFrame) = 0;
    ((RadarMenuWork *)(work))->bottomWaveFrame = ((RadarMenuWork *)work)->bottomWaveFrame + 1;
    if (((RadarMenuWork *)(work))->bottomWaveFrame >= 0x1E) MEMBER(s16, work, RadarMenuWork, bottomWaveFrame) = 0;
    topWave = (s32)((11.0f * (f32)MEMBER(s16, work, RadarMenuWork, topWaveFrame)) / 25.0f);
    bottomWave = (s32)(11.0f * (1.0f - ((f32)MEMBER(s16, work, RadarMenuWork, bottomWaveFrame) / 30.0f)));
    column = 0;
    while (column < 0xB) {
        if (column < topWave) topDistance = topWave - column; else topDistance = column - topWave;
        if (column < bottomWave) bottomDistance = bottomWave - column; else bottomDistance = column - bottomWave;
        height = 1;
        topHeight = (s16)(10 - topDistance * 2);
        if (topHeight > 1) height = topHeight;
        bottomHeight = (s16)(8 - bottomDistance * 2);
        if (height < bottomHeight) height = bottomHeight;
        barBase = work + column * 0xA;
        ((RadarBarTarget *)(barBase + 0x5E8))->target = (s16)height;
        datSmoothTargetStep(barBase + 0x5E8);
        column++;
    }
}

/* Advance the single slide animation, saturating its elapsed counter at 100. */
// FUN_00361CA0
void radarStepValueAnimation(u8 *work) {
    s16 elapsed = ((RadarMenuWork *)work)->slideElapsed;
    s32 count;
    s32 animationIndex;
    u8 *record;

    /* measured: typing the repeated slideElapsed accesses grows 128 to 140 bytes. */
    if (elapsed < 100) {
        MEMBER(s16, work, RadarMenuWork, slideElapsed) = elapsed + 1;
    }
    for (animationIndex = 0; animationIndex <= 0; animationIndex++) {
        record = work + animationIndex * 0x30;
        count = MEMBER(s16, work, RadarMenuWork, slideElapsed);
        radarAnimateValue(record + 0x5B8, count, 0);
    }
  }

/* Draw a scrolling row's marker, two-digit index and name using its flag-dependent palette. */
// FUN_00361D20
void radarDrawColumn(s32 rowIndex, u8 *work)
{
    typedef struct MenuPaletteColor { u8 r, g, b, a; } MenuPaletteColor;
    typedef struct MenuRowStride { u8 bytes[0x30]; } MenuRowStride;
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern int sprintf(char *dst, const char *fmt, ...);
    extern u32 datMemberNameLabel(s32 memberId);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 iGpffffa980;
    f32 *rowX;
    f32 *rowY;
    u8 *rowAlpha;
    f32 scale;
    f32 baseX;
    f32 baseY;
    f32 rowOffsetY;
    s32 itemIndex;
    s32 entryFlag;
    s32 markerFlag;
    s32 dimFlag;
    s32 rowSpriteAddress;
    void *drawNode;
    s8 fontMode;
    s32 textColorBase;
    u8 primaryRed;
    u8 primaryGreen;
    u8 primaryBlue;
    u8 labelRed;
    u8 labelGreen;
    u8 labelBlue;
    f32 x;
    f32 y;
    s32 alpha;
    s8 digits[256];
    f32 digitX;
    f32 digitY;
    u8 alphaLoop;
    f32 nameX;
    f32 nameY;
    u8 finalAlpha;

    /* Earlier panel-index and subarray probes changed cursor-address scheduling.
     * Keep the three interior field cursors in their original shape; the marker
     * alpha now uses the matching full-work panels[20 + rowIndex] access. */
    baseX = ((RadarMenuWork *)work)->x.f;
    baseY = ((RadarMenuWork *)work)->y.f;
    scale = (f32)((RadarMenuWork *)work)->alpha / 255.0f;
    itemIndex = rowIndex + ((RadarMenuWork *)work)->topRow;
    entryFlag = datGetFlag(itemIndex + 0x100);
    markerFlag = datGetFlag(itemIndex + 0x180);
    dimFlag = datGetFlag(itemIndex + 0x140);
    if (rowIndex == ((RadarMenuWork *)work)->selectedRow) {
        rowSpriteAddress = ((RadarMenuWork *)work)->sprites[36].handle;
        fontMode = 8;
        if (entryFlag != 0) {
            if (dimFlag != 0) {
                textColorBase = 0xAAAAAA00;
                labelRed = 0xAA;
                labelGreen = 0xAA;
                labelBlue = 0xAA;
                primaryRed = D_0064B2E8[0];
                primaryGreen = D_0064B2E8[1];
                primaryBlue = D_0064B2E8[2];
            } else {
                textColorBase = 0xFFFFFF00;
                labelRed = D_0064B2EC[0];
                labelGreen = D_0064B2EC[1];
                labelBlue = D_0064B2EC[2];
                primaryRed = D_0064B2E8[0];
                primaryGreen = D_0064B2E8[1];
                primaryBlue = D_0064B2E8[2];
            }
        } else {
            textColorBase = 0xAAAAAA00;
            labelRed = 0xAA;
            labelGreen = 0xAA;
            labelBlue = 0xAA;
            primaryRed = D_0064B2E8[0];
            primaryGreen = D_0064B2E8[1];
            primaryBlue = D_0064B2E8[2];
        }
    } else {
        rowSpriteAddress = ((RadarMenuWork *)work)->sprites[31].handle;
        textColorBase = 0xFFFFFF00;
        if (entryFlag != 0) {
            if (dimFlag != 0) {
                fontMode = 8;
                labelRed = D_0064B2EC[0];
                labelGreen = D_0064B2EC[1];
                labelBlue = D_0064B2EC[2];
                primaryRed = 0xAD;
                primaryGreen = 0xAD;
                primaryBlue = 0xAD;
            } else {
                fontMode = 6;
                labelRed = D_0064B2E4[0];
                labelGreen = D_0064B2E4[1];
                labelBlue = D_0064B2E4[2];
                primaryRed = D_0064B2E0[0];
                primaryGreen = D_0064B2E0[1];
                primaryBlue = D_0064B2E0[2];
            }
        } else {
            fontMode = 6;
            labelRed = D_0064B2E0[0];
            labelGreen = D_0064B2E0[1];
            labelBlue = D_0064B2E0[2];
            primaryRed = 0xFF;
            primaryGreen = 0xC8;
            primaryBlue = 0x2B;
        }
    }
    rowX = (f32 *)((MenuRowStride *)(work + 0x1D8) + rowIndex);
    x = 560.0f + (baseX + *rowX);
    rowY = (f32 *)((MenuRowStride *)(work + 0x1DC) + rowIndex);
    rowOffsetY = (f32)rowIndex * 30.0f;
    y = -13.0f + (rowOffsetY + (113.0f + (baseY + *rowY)));
    rowAlpha = (u8 *)((MenuRowStride *)(work + 0x1E2) + rowIndex);
    alpha = (u8)((f32)*rowAlpha * scale);
    sdkSpriteDrawAt((void *)rowSpriteAddress, x, y, primaryRed, primaryGreen, primaryBlue, alpha);
    if (markerFlag != 0) {
        MenuPaletteColor *pal;
        f32 markerX = 15.0f + (baseX + ((MenuSlotAnimation *)(work + 0x408))[rowIndex].currentX.f);
        f32 markerY = -13.0f + (rowOffsetY + (117.0f + (baseY + ((MenuSlotAnimation *)(work + 0x408))[rowIndex].currentY.f)));
        u8 markerAlpha = (u8)((f32)((RadarMenuWork *)work)->panels[20 + rowIndex].currentAlpha * scale);
        pal = (MenuPaletteColor *)D_0064B2EC;
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[19].object, markerX, markerY, 0x8C, 0x85, 0xFF, markerAlpha);
        drawNode = ((RadarMenuWork *)work)->sprites[20].object;
        sdkSpriteDrawAt(drawNode, markerX + 60.0f, markerY, 0x8C, 0x85, 0xFF, markerAlpha);
        drawNode = ((RadarMenuWork *)work)->sprites[18].object;
        sdkSpriteDrawAt(drawNode, markerX + 10.0f, markerY + 3.0f, pal->r, pal->g, pal->b, markerAlpha);
    } else if (dimFlag != 0) {
        x = 62.0f + (baseX + ((MenuSlotAnimation *)(work + 0x408))[rowIndex].currentX.f);
        y = -13.0f + (rowOffsetY + (117.0f + (baseY + ((MenuSlotAnimation *)(work + 0x408))[rowIndex].currentY.f)));
        alpha = (u8)((f32)((RadarMenuWork *)work)->panels[20 + rowIndex].currentAlpha * scale);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[40].object, x, y, 0xFF, 0xFF, 0xFF, alpha);
    }
    sprintf((char *)digits, (const char *)&iGpffffa980, itemIndex + 1);
    digitX = 89.0f + (baseX + *rowX);
    digitY = -13.0f + (rowOffsetY + (118.0f + (baseY + *rowY)));
    alphaLoop = (u8)((f32)*rowAlpha * scale);
    {
        s32 digitIndex;
        for (digitIndex = 0; digitIndex < 2; digitIndex++) {
            s32 digitSprite = ((RadarMenuWork *)work)->sprites[(s32)digits[digitIndex] - 27].handle;
            sdkSpriteDrawAt((void *)digitSprite, digitX, digitY, labelRed, labelGreen, labelBlue, alphaLoop);
            digitX += 22.0f;
        }
    }
    nameX = 153.0f + (baseX + *rowX);
    nameY = -13.0f + (rowOffsetY + (117.0f + (baseY + *rowY)));
    finalAlpha = (u8)((f32)*rowAlpha * scale);
    if (entryFlag != 0) {
        s32 color;
        u32 name;
        color = textColorBase;
        color |= finalAlpha & 0xFF;
        name = datMemberNameLabel(itemIndex);
        frFontExDrawTextOutA(nameX, nameY - 3.0f, 0.0f, color, fontMode, 1, (const char *)name, 0, 0x77, -1);
    } else {
        drawNode = ((RadarMenuWork *)work)->sprites[17].object;
        sdkSpriteDrawAt(drawNode, nameX + 2.0f, nameY + 1.0f, labelRed, labelGreen, labelBlue, finalAlpha);
    }
}

/* Center the first flagged row in the six-row window; fall back to row zero. */
// FUN_00362630
void cmpSystemFocusFlaggedRow(u8 *work)
{
    s32 count;
    s32 itemIndex;
    s16 difference;
    s16 offset;

    count = ((RadarMenuWork *)work)->rowCount;
    itemIndex = 0;
    while (itemIndex < count) {
        if (datGetFlag(itemIndex + 0x180) != 0) {
            if ((s16)itemIndex >= count) {
                kAssertFail(D_0064E280, 0x37);
            }
            if ((s16)itemIndex < 3) {
                offset = 0;
            } else if ((s16)itemIndex >= count - 3) {
                offset = count - 6;
            } else {
                offset = (s16)itemIndex - 3;
            }
            difference = itemIndex - offset;
            if (difference + offset >= count) {
                kAssertFail(D_0064E280, 0x54);
            }
            cmpSystemSetSelection(work, 1, difference);
            cmpSystemSetSelection(work, 2, offset);
            break;
        }
        itemIndex++;
    }
    if (itemIndex == count) {
        cmpSystemSetSelection(work, 1, 0);
        cmpSystemSetSelection(work, 2, 0);
    }
}

/* Drive menu transitions, nested config and message actions; return 1 on close or 2 on exit. */
// FUN_003627B0
s32 cmpSystemMenuUpdate(u32 *phase, s32 *active, u8 *work)
{
    u8 query[0x30];
    s32 resultFlag = 1;
    s32 inputResult;
    s16 selection;
    f32 alpha;

    /* measured: typed messageSlot/configTask/topRow retain addresses across calls;
     * together with the fade reload they change the body from 1872 to 1884 bytes.
     * MEMBER keeps the measured repeated accesses byte-addressed; other work/query fields remain typed. */
    /* measured: replacing the shared finish jumps with early returns grows 1872 to 1940 bytes. */
    *active = 1;
    switch (*phase) {
    case 0:
        ((RadarMenuWork *)work)->x.s = 0;
        ((RadarMenuWork *)work)->y.s = 0;
        ((RadarMenuWork *)work)->alpha = 0xFF;
        cmpSystemMenuInit(work);
        *phase = 1;
        *active = 0;
        goto finish;
    case 1:
        if ((datCommunityPanelOpenStepAlt(work) != 0) && (nLineIsIdle() != 0)) {
            *phase = 3;
            nLineSelectSet(0x1D);
        } else {
            *active = 0;
        }
        goto finish;
    case 2:
        if (radarRowsSettled(work) != 0) {
            cmpSystemMenuRelease(work);
            return 1;
        }
        goto finish;
    case 3:
        if (radarRowsSettled(work) != 0) {
            cmpSystemSetMode(work, 2);
            *phase = 4;
        }
        goto finish;
    case 4:
        if (D_008C024E[0] & 0x20) {
            cmpSystemSetMode(work, resultFlag);
            *phase = 2;
            nLineSelectSet(0x1E);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            selection = ((RadarMenuWork *)work)->selectedHeader;
            switch (selection) {
            case 0:
                cmpSystemSetMode(work, resultFlag);
                *phase = 5;
                nLineSelectSet(0x1E);
                break;
            case 1:
                cmpSystemSetMode(work, resultFlag);
                *phase = 8;
                nLineSelectSet(0x1E);
                break;
            case 2:
                nmMesWindowShowSlotRecord(((RadarMenuWork *)(work))->messageSlot, 4);
                nmMesWindowSetSlotParam(MEMBER(s8, work, RadarMenuWork, messageSlot), 0);
                nmMesWindowRequestRefresh();
                nmMesWindowSetSlotFlag(MEMBER(s8, work, RadarMenuWork, messageSlot), 1);
                *phase = 0xA;
                break;
            }
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            ((RadarMenuWork *)work)->background = datCommunityRequestExit();
            *phase = 0xC;
        } else {
            sdkListStateConfigure(query, 3, 3, ((RadarMenuWork *)work)->selectedHeader, 0);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(query) != 0) {
                selection = ((SdkListState *)query)->cursor;
                cmpSystemSetSelection(work, 0, selection);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        goto finish;
    case 5:
        if (radarRowsSettled(work) != 0) {
            cmpSystemFocusFlaggedRow(work);
            cmpSystemSetMode(work, 3);
            *phase = 6;
            nLineSelectSet(0x1F);
        }
        goto finish;
    case 6:
        if (radarRowsSettled(work) != 0) {
            cmpSystemSetMode(work, 4);
            *phase = 7;
            resrcMngSuppressRender();
        }
        goto finish;
    case 7:
        if (D_008C024E[0] & 0x20) {
            cmpSystemSetMode(work, 5);
            *phase = 1;
            nLineSelectSet(0x20);
            resrcMngUnsuppressRender();
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            ((RadarMenuWork *)work)->background = datCommunityRequestExit();
            *phase = 0xC;
        } else {
            sdkListStateConfigure(query, 6, ((RadarMenuWork *)work)->rowCount,
                          ((RadarMenuWork *)work)->selectedRow, ((RadarMenuWork *)(work))->topRow);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((inputResult = sdkListStateHandleInput(query)) > 0) {
                selection = ((SdkListState *)query)->cursor;
                cmpSystemSetSelection(work, 1, selection);
                selection = ((SdkListState *)query)->scroll;
                cmpSystemSetSelection(work, 2, selection);
                if (MEMBER(s16, work, RadarMenuWork, topRow) != ((RadarMenuWork *)work)->previousTopRow) {
                    radarResetSlideDirection(work);
                }
                datCommunityCursorFeedback(inputResult);
            }
        }
        goto finish;
    case 8:
        if (nLineIsIdle() != 0) {
            ((RadarMenuWork *)(work))->configTask.handle = cmpConfigCreate(0, 0);
            *phase = 9;
        }
        goto finish;
    case 9:
        if (cmpConfigIsStepDone(((RadarMenuWork *)(work))->configTask.node) != 0) {
            if (cmpConfigIsStepCancelled(MEMBER(u8 *, work, RadarMenuWork, configTask.node)) != 0) {
                return 2;
            }
            kwlnTaskDestroyWithHierarchy(MEMBER(s32, work, RadarMenuWork, configTask.handle));
            MEMBER(s32, work, RadarMenuWork, configTask.handle) = 0;
            *phase = 1;
        }
        goto finish;
    case 10:
        nmMesWindowStepSlot(((RadarMenuWork *)(work))->messageSlot, resultFlag);
        if (nmMesWindowSlotStatus(MEMBER(s8, work, RadarMenuWork, messageSlot)) == 0) {
            switch (nmMesWindowSlotResult(MEMBER(s8, work, RadarMenuWork, messageSlot))) {
            case 0:
                fadeBeginTransition(1, 0x1E);
                sdkSndStopChannel(0x1E);
                sdkSndFadeOutChannelFrames(3, 0, 0x1E);
                *phase = 0xB;
                break;
            case 1:
                *phase = 4;
                break;
            }
            nmMesWindowCloseSlot((s8)MEMBER(s8, work, RadarMenuWork, messageSlot), 1);
        }
        goto finish;
    case 11:
        if (fadeStatus() != 0) {
            sequenceRequest(0x1B, 0, 0, 0xA);
        }
        goto finish;
    case 12:
        if ((++((RadarMenuWork *)work)->fadeFrame & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)MEMBER(u16, work, RadarMenuWork, fadeFrame) / 3.0f)) * 255.0f;
            inputResult = (u8)alpha;
            ((RadarMenuWork *)work)->alpha = inputResult;
            resultFlag = 0;
        }
        break;
    default:
        goto finish;
    }
    if (resultFlag != 0) {
        return 2;
    }
finish:
    return 0;
}

/* Interpolate the output position with 1-cos easing; return 1 after duration elapses. */
// FUN_00362F00
s32 cmpPartyPanelStepRowMotion(u8 *motion)
{
    f32 startY;
    f32 y;
    f32 x;
    f32 startX;
    f32 ease;
    s16 step;
    s16 frame;

    /* measured: repeated typed frame/duration/startY accesses cache addresses/values
     * across the increment and output store (216 versus 208 bytes); preserve those reloads. */
    frame = ((CmpPartyRowMotion *)motion)->frame;
    if (frame < ((CmpPartyRowMotion *)motion)->duration) {
        MEMBER(s16, motion, CmpPartyRowMotion, frame) = frame + 1;
        step = MEMBER(s16, motion, CmpPartyRowMotion, frame);
        ease = 1.0f - cosf(iGpffff84a4 * ((f32)step / (f32)MEMBER(s16, motion, CmpPartyRowMotion, duration)));
        startX = ((CmpPartyRowMotion *)motion)->startX;
        x = ((CmpPartyRowMotion *)motion)->endX;
        x = x - startX;
        y = ((CmpPartyRowMotion *)motion)->endY;
        startY = ((CmpPartyRowMotion *)motion)->startY;
        y = y - startY;
        x = x * ease;
        y = y * ease;
        x = x + startX;
        ((CmpPartyRowMotion *)motion)->x = x;
        startY = ((CmpPartyRowMotion *)(motion))->startY;
        startY = operandOrderAddFloat(y, startY);
        ((CmpPartyRowMotion *)motion)->y = startY;
        return 0;
    }
    return 1;
}
