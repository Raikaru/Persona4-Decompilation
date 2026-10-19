/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00134890-00135520 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
extern s32 nLineIsIdle(void);
extern u32 datEntryGetFlags(s16);
extern void (*D_00887300[])(u32 state, u32 value);
/* Keep the unsigned integer address addition order used by the matching indexed loads. */
static inline u8 *radarOffsetAddress(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}

static inline f32 radarAddCoordinates(f32 left, f32 right) {
    return left + right;
}

extern void sdkSpriteFreeNode(void *node);
extern void datClampUnitHpSp(s16);
extern void radarBeginSlideOut(u8 *);
extern void radarBeginSlideIn(u8 *);
extern void radarResetAndSetIndices(u8 *, s16, s16);
extern void sdkSpriteDrawAt(void *, f32, f32,
                          u8, u8, u8, u8);
extern void radarDrawHeaderFrame(u8 *, PackedVec2f, u8, u16);
extern void datEntryDrawRow(Vec2f, f32, u8, u8 *);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
/* Transition thresholds: 41 records at +0xC80, stride 0x30, threshold +0x2C. */
typedef struct { s32 nodes[52]; } RadarSpriteTable;
typedef struct { s16 item; u8 pad2[0x14]; s16 kind; } RadarItemCardEntry;

/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct {
    u8 pad0[0x1C];
    s32 unk1C; /* +0x1C */
    s16 unk20; /* +0x20 */
    u8 pad22[0x2];
    s16 unk24; /* +0x24 */
    u8 pad26[0x6];
    s16 unk2C; /* +0x2C */
    u8 pad2E[0x2];
    s16 unk30; /* +0x30 */
    u8 pad32[0x2];
    s16 unk34; /* +0x34 */
    u8 pad36[2];
    s16 unitIds[8];
    s16 entryCount; /* +0x48 */
    u8 pad4A[0xC30];
    s16 previousItem; /* +0xC7A */
    s16 selectedItem; /* +0xC7C */
    s16 slideUnitId; /* +0xC7E */
    u8 padC80[0x394];
    s32 unk1014; /* +0x1014 */
    u8 pad1018[0x4];
    s32 unk101C; /* +0x101C */
    u8 pad1020[0x8];
    union { s8 signedByte; u8 byte; } unk1028; /* +0x1028 */
    u8 pad1029[0x34B];
    s32 unk1374; /* +0x1374 */
    u8 pad1378[0x4];
    s32 unk137C; /* +0x137C */
    u8 pad1380[0x8];
    union { s8 signedByte; u8 byte; } unk1388; /* +0x1388 */
    u8 pad1389[0x47];
    s32 unk13D0; /* +0x13D0 */
    u8 pad13D4[0x14];
    union { s8 signedByte; u8 byte; } unk13E8; /* +0x13E8 */
    u8 pad13E9[0x17];
    s32 unk1400; /* +0x1400 */
    u8 pad1404[0x14];
    union { s8 signedByte; u8 byte; } unk1418; /* +0x1418 */
    u8 pad1419[0x17];
    s32 unk1430; /* +0x1430 */
    union { f32 scalar; s32 integer; } unk1434; /* +0x1434 */
    s32 unk1438; /* +0x1438 */
    union { f32 scalar; s32 integer; } unk143C; /* +0x143C */
    s32 unk1440; /* +0x1440 */
    union { f32 scalar; s32 integer; } unk1444; /* +0x1444 */
    u8 unk1448; /* +0x1448 */
    s8 unk1449; /* +0x1449 */
    u8 unk144A; /* +0x144A */
    u8 pad144B[0x19];
    s32 unk1464; /* +0x1464 */
    u8 pad1468[0x4];
    s32 unk146C; /* +0x146C */
    u8 pad1470[0x20];
    s32 unk1490; /* +0x1490 */
    f32 unk1494; /* +0x1494 */
    s32 unk1498; /* +0x1498 */
    s32 unk149C; /* +0x149C */
    s32 unk14A0; /* +0x14A0 */
    f32 unk14A4; /* +0x14A4 */
    u8 unk14A8; /* +0x14A8 */
    s8 unk14A9; /* +0x14A9 */
    u8 unk14AA; /* +0x14AA */
    u8 pad14AB[0x1D];
    s32 unk14C8; /* +0x14C8 */
    u8 pad14CC[0x34];
    s32 unk1500; /* +0x1500 */
    s32 unk1504; /* +0x1504 */
    s32 unk1508; /* +0x1508 */
    u8 pad150C[0x2C];
    void * headerTopLeftSprite; /* +0x1538 */
    void * headerTopRightSprite; /* +0x153C */
    void * headerBottomLeftSprite; /* +0x1540 */
    void * headerBottomRightSprite; /* +0x1544 */
    void * cardLabelSprite; /* +0x1548 */
    void * cardTopLeftSprite; /* +0x154C */
    void * cardTopRightSprite; /* +0x1550 */
    void * cardBottomLeftSprite; /* +0x1554 */
    void * cardBottomRightSprite; /* +0x1558 */
    s32 unk155C; /* +0x155C */
    s32 unk1560; /* +0x1560 */
    u8 pad1564[0x1C];
    s32 paletteLeftSprite; /* +0x1580 */
    s32 paletteRightSprite; /* +0x1584 */
    void * unk1588; /* +0x1588 */
} RadarTransferWork;

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Reset the layout state, choosing the target and start positions by comparing the counters at +0x2C and +0x34 [inferred]
// FUN_00134890
/* Measured: typed float/integer aliases in this reset changed 32 bytes; retain the raw stores to the proven RadarTransferWork offsets. */
void radarResetLayout(u8 *work)
{
    f32 zeroOffset;
    f32 startPosition;

    zeroOffset = 0.0f;
    *(s32 *)(work + 0x13D0) = 0;
    *(u8 *)(work + 0x13E8) = 0xFF;
    *(s8 *)(work + 0x1418) = 0;
    *(s8 *)(work + 0x1388) = 0;
    *(u8 *)(work + 0x1028) = 0xFF;
    *(s32 *)(work + 0x1014) = 0;
    *(s32 *)(work + 0x13D0) = 0;
    *(u8 *)(work + 0x13E8) = 0xFF;
    *(s8 *)(work + 0x1418) = 0;
    startPosition = 122.0f;
    *(s32 *)(work + 0x1430) = 0x42F40000;
    *(s32 *)(work + 0x1438) = 0x42F40000;
    *(s32 *)(work + 0x1440) = 0x42F40000;
    *(u8 *)(work + 0x1448) = 0xFF;
    *(u8 *)(work + 0x144A) = 0xFF;
    *(s8 *)(work + 0x1449) = 0;
    *(s32 *)(work + 0x1490) = 0;
    *(s32 *)(work + 0x1498) = 0;
    *(s32 *)(work + 0x14A0) = 0;
    *(u8 *)(work + 0x14A8) = 0xFF;
    *(u8 *)(work + 0x14AA) = 0xFF;
    *(s8 *)(work + 0x14A9) = 0;
    *(s32 *)(work + 0x146C) = 0;
    if (*(s16 *)(work + 0x2C) > *(s16 *)(work + 0x34)) {
        *(s32 *)(work + 0x1444) = 0x43090000;
        *(s32 *)(work + 0x1434) = 0x43090000;
        *(f32 *)(work + 0x143C) = startPosition;
        *(f32 *)(work + 0x14A4) = zeroOffset;
        *(f32 *)(work + 0x1494) = zeroOffset;
        *(s32 *)(work + 0x149C) = 0xC1A80000;
        *(s32 *)(work + 0x1464) = 0xC1200000;
    } else {
        startPosition = (f32)0x111;
        *(f32 *)(work + 0x1444) = startPosition;
        *(f32 *)(work + 0x1434) = startPosition;
        *(s32 *)(work + 0x143C) = 0x43950000;
        *(f32 *)(work + 0x1494) = zeroOffset;
        *(s32 *)(work + 0x149C) = 0x41A80000;
        *(f32 *)(work + 0x143C) = 10.0f + *(f32 *)(work + 0x1444);
        *(s32 *)(work + 0x1464) = 0x41200000;
    }
    *(s16 *)(work + 0x24) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state, clear the cursor, and store two indices at +0xC7A and +0xC7C [inferred]
// FUN_00134990
void radarResetAndSetIndices(u8 *work, s16 sourceIndex, s16 targetIndex) {
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk1388.signedByte = 0;
    ((RadarTransferWork *)work)->unk1028.byte = 0xff;
    ((RadarTransferWork *)work)->unk1014 = 0;
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk1374 = 0;
    ((RadarTransferWork *)work)->unk137C = 0xc1200000;
    ((RadarTransferWork *)work)->unk1388.byte = 0xff;
    ((RadarTransferWork *)work)->unk1014 = 0x41200000;
    ((RadarTransferWork *)work)->unk101C = 0;
    ((RadarTransferWork *)work)->unk1028.signedByte = 0;
    ((RadarTransferWork *)work)->previousItem = sourceIndex;
    ((RadarTransferWork *)work)->selectedItem = targetIndex;
    ((RadarTransferWork *)work)->unk20 = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state and begin a slide in from the +50 offset, copying the entry at +0x30 [inferred]
// FUN_001349F0
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
void radarBeginSlideIn(u8 *work) {
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk1388.signedByte = 0;
    ((RadarTransferWork *)work)->unk1028.byte = 0xff;
    ((RadarTransferWork *)work)->unk1014 = 0;
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk13D0 = 0x42480000;
    ((RadarTransferWork *)work)->unk13E8.signedByte = 0;
    ((RadarTransferWork *)work)->unk1400 = 0xc2480000;
    ((RadarTransferWork *)work)->unk1418.byte = 0xff;
    ((RadarTransferWork *)work)->slideUnitId = *(s16 *)(radarOffsetAddress(((RadarTransferWork *)work)->unk30 * 2, work) + 0x38);
    ((RadarTransferWork *)work)->unk20 = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state and begin a slide out to the -50 offset, copying the entry at +0x30 [inferred]
// FUN_00134A50
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
void radarBeginSlideOut(u8 *work) {
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk1388.signedByte = 0;
    ((RadarTransferWork *)work)->unk1028.byte = 0xff;
    ((RadarTransferWork *)work)->unk1014 = 0;
    ((RadarTransferWork *)work)->unk13D0 = 0;
    ((RadarTransferWork *)work)->unk13E8.byte = 0xff;
    ((RadarTransferWork *)work)->unk1418.signedByte = 0;
    ((RadarTransferWork *)work)->unk13D0 = 0xc2480000;
    ((RadarTransferWork *)work)->unk13E8.signedByte = 0;
    ((RadarTransferWork *)work)->unk1400 = 0x42480000;
    ((RadarTransferWork *)work)->unk1418.byte = 0xff;
    ((RadarTransferWork *)work)->slideUnitId = *(s16 *)(radarOffsetAddress(((RadarTransferWork *)work)->unk30 * 2, work) + 0x38);
    ((RadarTransferWork *)work)->unk20 = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Free the 52 sprite nodes in the second radar sprite table, then release the entries listed at +0x38 [inferred]
// FUN_00134AB0
void radarReleaseSpritesAndEntries(u8 *work) {
    s32 sprite;
    s32 entryIndex;
    s32 spriteIndex;
    u8 *spriteSlot;
    u8 *spriteBase;

    spriteIndex = 0;
    while (spriteIndex < 0x34) {
        spriteBase = work + spriteIndex * 4;
        spriteSlot = spriteBase + 0x14c0;
        sprite = ((RadarSpriteTable *)(spriteBase + 0x14C0))->nodes[0];
        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *(s32 *)spriteSlot = 0;
        }
        spriteIndex++;
    }
    entryIndex = 0;
    while (entryIndex < ((RadarTransferWork *)work)->entryCount) {
        datClampUnitHpSp(((RadarTransferWork *)work)->unitIds[entryIndex]);
        entryIndex++;
    }
    ((RadarTransferWork *)work)->unk1C = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Return 1 when the value at +0x20 is at least the threshold of every one of the 41 entries and the external check passes [inferred]
// FUN_00134B60
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
s32 radarWideEntriesCoverValue(u8 *work) {
    s32 covered = 1;
    s32 entryIndex = 0;
    s32 value = ((RadarTransferWork *)work)->unk20;

    while (entryIndex < 41) {
        if (value < *(s32 *)(work + entryIndex * 48 + 0xcac)) {
            covered = 0;
        }
        entryIndex++;
    }
    return covered & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Map the first set flag bit to an icon mode from 7 to 13 [inferred]
// FUN_00134DA0
s32 radarFlagToIconMode(s32 flags) {
    s32 result;

    if (flags & 0x81) {
        result = 7;
        goto done;
    }
    if (flags & 0x102) {
        result = 8;
        goto done;
    }
    if (flags & 0x204) {
        result = 9;
        goto done;
    }
    if (flags & 0x408) {
        result = 10;
        goto done;
    }
    if (flags & 0x810) {
        result = 11;
        goto done;
    }
    if (flags & 0x1020) {
        result = 12;
        goto done;
    }
    if (flags & 0x2040) {
        result = 13;
    }
done:
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw a palette sprite pair at the given position, with the colour set chosen by the mode value [inferred]
// FUN_00134E50
/* measured: reconstructing the mixed-ABI palette draw pair from the matching 00130C30 shape. */
#pragma opt_propagation off
void radarDrawPalettePair(u8 *work, s64 position, s64 mode, u8 alpha)
{
    f32 drawY;
    s32 leftSprite;
    s32 rightSprite;
    u8 *color;

    leftSprite = ((RadarTransferWork *)work)->paletteLeftSprite;
    rightSprite = ((RadarTransferWork *)work)->paletteRightSprite;
    switch ((s16)mode) {
    case 0:
        color = D_0064B2E0;
        break;
    case 1:
        color = D_0064B2E8;
        break;
    }
    drawY = ((f32 *)&position)[1] - 3.0f;
    sdkSpriteDrawAt((void *)leftSprite, ((f32 *)&position)[0], drawY,
                  color[0], color[1], color[2], alpha);
    sdkSpriteDrawAt((void *)rightSprite, 241.0f + ((f32 *)&position)[0], drawY,
                  color[0], color[1], color[2], alpha);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw a palette sprite set for mode 0 (four sprites) or mode 1 (two sprites) [inferred]
// FUN_00134F40
/* measured: transfer the neighboring mixed-ABI palette branch shape. */
#pragma opt_propagation off
void radarDrawPaletteSet(u8 *work, s64 position, s64 mode, u8 alpha)
{
    f32 drawY;
    s32 sprite;
    u8 *color;

    switch ((s16)mode) {
    case 0:
        sprite = ((RadarTransferWork *)work)->unk14C8;
        drawY = ((f32 *)&position)[1];
        sdkSpriteDrawAt((void *)sprite,
                      ((f32 *)&position)[0], drawY,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], alpha);
        sprite = ((RadarTransferWork *)work)->unk1508;
        sdkSpriteDrawAt((void *)sprite,
                      36.0f + ((f32 *)&position)[0], 24.0f + drawY,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], alpha);
        sprite = ((RadarTransferWork *)work)->unk1500;
        drawY = radarAddCoordinates(9.0f, drawY);
        sdkSpriteDrawAt((void *)sprite,
                      419.0f + ((f32 *)&position)[0], drawY,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], alpha);
        sprite = ((RadarTransferWork *)work)->unk1504;
        sdkSpriteDrawAt((void *)sprite,
                      473.0f + ((f32 *)&position)[0], drawY,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], alpha);
        break;
    case 1:
        color = D_0064B2E8;
        sprite = ((RadarTransferWork *)work)->unk155C;
        drawY = ((f32 *)&position)[1];
        sdkSpriteDrawAt((void *)sprite,
                      2.0f + ((f32 *)&position)[0], drawY,
                      color[0], color[1], color[2], alpha);
        sprite = ((RadarTransferWork *)work)->unk1560;
        sdkSpriteDrawAt((void *)sprite,
                      474.0f + ((f32 *)&position)[0], drawY,
                      color[0], color[1], color[2], alpha);
        break;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw one item card: the bordered panel, its corner sprites, the entry row, and the value and count text [inferred]
// FUN_00135130
void radarDrawItemCard(u8 *work, s64 inputPosition, u8 inputAlpha, u8 *entry)
{
    extern u16 datItemValue(s16 item);
    extern void PrimDrawFlatRectangle(u8 *color, f32 *rect, f32 depth, s32 flags);
    extern void fclMesWindowDrawTableItem(s32 item, f32 x, f32 y, f32 depth,
                            s32 color, s32 font, s32 mode, s32 table);
    typedef struct { u8 r; u8 g; u8 b; } Rgb;
    struct { Rgb rgb; u8 alpha; } color;
    PackedVec2f position;
    union {
        s32 integer[4];
        f32 words[4];
    } rectangle;
    f32 originalY;
    f32 initialY;
    f32 borderY;
    f32 bottomY;
    f32 rightX;
    s32 itemValue;
    s32 labelColor;
    void *sprite;

    originalY = ((f32 *)&inputPosition)[1];
    position.xy.x = 5.0f + ((f32 *)&inputPosition)[0];
    position.xy.y = 27.0f + originalY;
    switch (((RadarItemCardEntry *)entry)->kind) {
    case 3:
        ((u8 *)&color)[0] = D_0064B2E0[0];
        ((u8 *)&color)[1] = D_0064B2E0[1];
        ((u8 *)&color)[2] = D_0064B2E0[2];
        break;
    default:
        color.rgb.r = D_0064B2E0[0];
        color.rgb.g = D_0064B2E0[1];
        color.rgb.b = D_0064B2E0[2];
        break;
    }
    color.alpha = inputAlpha;
    rectangle.integer[0] = (s32)position.xy.x;
    initialY = position.xy.y;
    rectangle.integer[1] = (s32)initialY;
    rectangle.integer[2] = 470;
    rectangle.integer[3] = 39;
    D_00887300[0](1, 0);
    PrimDrawFlatRectangle((u8 *)&color, rectangle.words, 0.0f, 0);
    sprite = ((RadarTransferWork *)work)->cardLabelSprite;
    sdkSpriteDrawAt(sprite, 4.0f + position.xy.x,
                  10.0f + initialY, 0xFF, 0xFF, 0xFF, inputAlpha);
    position.xy.y = position.xy.y + 36.0f;
    borderY = position.xy.y;
    sdkSpriteDrawAt(((RadarTransferWork *)work)->cardTopLeftSprite, position.xy.x, borderY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = ((RadarTransferWork *)work)->cardTopRightSprite;
    rightX = (f32)0x1C9 + position.xy.x;
    sdkSpriteDrawAt(sprite, rightX, borderY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = ((RadarTransferWork *)work)->cardBottomLeftSprite;
    bottomY = 91.0f + borderY;
    sdkSpriteDrawAt(sprite, position.xy.x, bottomY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = ((RadarTransferWork *)work)->cardBottomRightSprite;
    sdkSpriteDrawAt(sprite, rightX, bottomY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sdkSpriteDrawAt(((RadarTransferWork *)work)->unk1588, 6.0f + position.xy.x,
                  2.0f + borderY, color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    position.xy.x = ((f32 *)&inputPosition)[0];
    position.xy.y = originalY;
    radarDrawHeaderFrame(work, position, inputAlpha, 3);
    position.xy.x = ((f32 *)&inputPosition)[0] - 2.0f;
    position.xy.y = originalY;
    datEntryDrawRow(position.xy, 0.0f, inputAlpha, entry);
    position.xy.x = 128.0f + ((f32 *)&inputPosition)[0];
    position.xy.y = 32.0f + originalY;
    if ((datEntryGetFlags(*(s16 *)entry) & 0x8000) != 0) {
        itemValue = 0;
    } else {
        itemValue = datItemValue(*(s16 *)entry) & 0xFFFF;
    }
    labelColor = (inputAlpha & 0xFF) | ~0xFF;
    fclMesWindowDrawTableItem(itemValue, (f32)(s32)position.xy.x,
                  (f32)(s32)position.xy.y, 0.0f, labelColor, 1, 6, 3);
    position.xy.x = 131.0f + ((f32 *)&inputPosition)[0];
    position.xy.y = 81.0f + originalY;
    fclMesWindowDrawItemCategory(0.0f, *(s16 *)entry, (s32)position.xy.x,
                  (s32)position.xy.y, labelColor, 1, 6);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw the header frame sprites when bit 2 of the flags is set, and the palette set when bit 1 is set [inferred]
// FUN_00135520
void radarDrawHeaderFrame(u8 *work, PackedVec2f position, u8 alpha, u16 flags)
{
    f32 topY;
    f32 drawCoordinate;
    u16 drawFlags;
    u8 red;
    u8 green;
    u8 blue;
    void *sprite;
    red = D_0064B2E8[0];
    green = D_0064B2E8[1];
    blue = D_0064B2E8[2];
    topY = radarAddCoordinates(position.xy.y, 26.0f);
    position.xy.y = topY;
    drawFlags = (u16)flags;
    if (drawFlags & 2) {
        sdkSpriteDrawAt(((RadarTransferWork *)work)->headerTopLeftSprite,
                      (drawCoordinate = position.xy.x), topY,
                      red, green, blue, alpha);
        sprite = ((RadarTransferWork *)work)->headerTopRightSprite;
        drawCoordinate = 467.0f + position.xy.x;
        sdkSpriteDrawAt(sprite,
                      drawCoordinate, topY,
                      red, green, blue, alpha);
        sprite = ((RadarTransferWork *)work)->headerBottomLeftSprite;
        sprite = sprite;
        drawCoordinate = topY + 130.0f;
        sdkSpriteDrawAt(sprite,
                      position.xy.x, drawCoordinate,
                      red, green, blue, alpha);
        sdkSpriteDrawAt(((RadarTransferWork *)work)->headerBottomRightSprite,
                      467.0f + position.xy.x, drawCoordinate,
                      red, green, blue, alpha);
    }
    if (drawFlags & 1) {
        position.xy.x -= 2.0f;
        position.xy.y -= 26.0f;
        radarDrawPaletteSet(work, position.packed, 1, alpha);
    }
}
#pragma pop
