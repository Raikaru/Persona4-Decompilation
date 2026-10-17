/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00134890-00135520 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
extern s32 nLineIsIdle(void);
extern u32 datEntryGetFlags(s16 arg0);
extern void (*D_00887300[])(u32 state, u32 value);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}

static inline f32 code13Add(f32 left, f32 right) {
    return left + right;
}

extern void sdkSpriteFreeNode(void *node);
extern void datClampUnitHpSp(s16 arg0);
extern void radarBeginSlideOut(u8 *arg0);
extern void radarBeginSlideIn(u8 *arg0);
extern void radarResetAndSetIndices(u8 *arg0, s16 arg1, s16 arg2);
extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void radarDrawHeaderFrame(u8 *arg0, PackedVec2f arg1, u8 arg2, u16 arg3);
extern void datEntryDrawRow(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Reset the layout state, choosing the target and start positions by comparing the counters at +0x2C and +0x34 [inferred]
// FUN_00134890
void radarResetLayout(u8 *arg0)
{
    f32 temp_f1;
    f32 temp_f0;

    temp_f1 = 0.0f;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xFF;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    temp_f0 = 122.0f;
    *(s32 *)(arg0 + 0x1430) = 0x42F40000;
    *(s32 *)(arg0 + 0x1438) = 0x42F40000;
    *(s32 *)(arg0 + 0x1440) = 0x42F40000;
    *(u8 *)(arg0 + 0x1448) = 0xFF;
    *(u8 *)(arg0 + 0x144A) = 0xFF;
    *(s8 *)(arg0 + 0x1449) = 0;
    *(s32 *)(arg0 + 0x1490) = 0;
    *(s32 *)(arg0 + 0x1498) = 0;
    *(s32 *)(arg0 + 0x14A0) = 0;
    *(u8 *)(arg0 + 0x14A8) = 0xFF;
    *(u8 *)(arg0 + 0x14AA) = 0xFF;
    *(s8 *)(arg0 + 0x14A9) = 0;
    *(s32 *)(arg0 + 0x146C) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x34)) {
        *(s32 *)(arg0 + 0x1444) = 0x43090000;
        *(s32 *)(arg0 + 0x1434) = 0x43090000;
        *(f32 *)(arg0 + 0x143C) = temp_f0;
        *(f32 *)(arg0 + 0x14A4) = temp_f1;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0xC1A80000;
        *(s32 *)(arg0 + 0x1464) = 0xC1200000;
    } else {
        temp_f0 = (f32)0x111;
        *(f32 *)(arg0 + 0x1444) = temp_f0;
        *(f32 *)(arg0 + 0x1434) = temp_f0;
        *(s32 *)(arg0 + 0x143C) = 0x43950000;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0x41A80000;
        *(f32 *)(arg0 + 0x143C) = 10.0f + *(f32 *)(arg0 + 0x1444);
        *(s32 *)(arg0 + 0x1464) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x24) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state, clear the cursor, and store two indices at +0xC7A and +0xC7C [inferred]
// FUN_00134990
void radarResetAndSetIndices(u8 *arg0, s16 arg1, s16 arg2) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x1374) = 0;
    *(s32 *)(arg0 + 0x137c) = 0xc1200000;
    *(u8 *)(arg0 + 0x1388) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0x41200000;
    *(s32 *)(arg0 + 0x101c) = 0;
    *(s8 *)(arg0 + 0x1028) = 0;
    *(s16 *)(arg0 + 0xc7a) = arg1;
    *(s16 *)(arg0 + 0xc7c) = arg2;
    *(s16 *)(arg0 + 0x20) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state and begin a slide in from the +50 offset, copying the entry at +0x30 [inferred]
// FUN_001349F0
void radarBeginSlideIn(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0x42480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0xc2480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Reset the state and begin a slide out to the -50 offset, copying the entry at +0x30 [inferred]
// FUN_00134A50
void radarBeginSlideOut(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0xc2480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0x42480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Free the 52 sprite nodes in the second radar sprite table, then release the entries listed at +0x38 [inferred]
// FUN_00134AB0
void radarReleaseSpritesAndEntries(u8 *arg0) {
    s32 temp;
    s32 var17;
    s32 var18;
    u8 *p;
    u8 *q;

    var18 = 0;
    while (var18 < 0x34) {
        q = arg0 + var18 * 4;
        p = q + 0x14c0;
        temp = *(s32 *)(q + 0x14c0);
        if (temp != 0) {
            sdkSpriteFreeNode((void *)temp);
            *(s32 *)p = 0;
        }
        var18++;
    }
    var17 = 0;
    while (var17 < *(s16 *)(arg0 + 0x48)) {
        datClampUnitHpSp(*(s16 *)(arg0 + var17 * 2 + 0x38));
        var17++;
    }
    *(s32 *)(arg0 + 0x1c) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Return 1 when the value at +0x20 is at least the threshold of every one of the 41 entries and the external check passes [inferred]
// FUN_00134B60
s32 radarWideEntriesCoverValue(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xcac)) {
            flag = 0;
        }
        i++;
    }
    return flag & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Map the first set flag bit to an icon mode from 7 to 13 [inferred]
// FUN_00134DA0
s32 radarFlagToIconMode(s32 arg0) {
    s32 result;

    if (arg0 & 0x81) {
        result = 7;
        goto done;
    }
    if (arg0 & 0x102) {
        result = 8;
        goto done;
    }
    if (arg0 & 0x204) {
        result = 9;
        goto done;
    }
    if (arg0 & 0x408) {
        result = 10;
        goto done;
    }
    if (arg0 & 0x810) {
        result = 11;
        goto done;
    }
    if (arg0 & 0x1020) {
        result = 12;
        goto done;
    }
    if (arg0 & 0x2040) {
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
void radarDrawPalettePair(u8 *arg0, s64 arg1, s64 arg2, u8 arg3)
{
    f32 temp_f20;
    s32 p;
    s32 p2;
    u8 *color;

    p = *(s32 *)(arg0 + 0x1580);
    p2 = *(s32 *)(arg0 + 0x1584);
    switch ((s16)arg2) {
    case 0:
        color = D_0064B2E0;
        break;
    case 1:
        color = D_0064B2E8;
        break;
    }
    temp_f20 = ((f32 *)&arg1)[1] - 3.0f;
    sdkSpriteDrawAt((void *)p, ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
    sdkSpriteDrawAt((void *)p2, 241.0f + ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
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
void radarDrawPaletteSet(u8 *arg0, s64 arg1, s64 arg2, u8 arg3)
{
    f32 temp_f20;
    s32 p;
    u8 *color;

    switch ((s16)arg2) {
    case 0:
        p = *(s32 *)(arg0 + 0x14C8);
        temp_f20 = ((f32 *)&arg1)[1];
        sdkSpriteDrawAt((void *)p,
                      ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1508);
        sdkSpriteDrawAt((void *)p,
                      36.0f + ((f32 *)&arg1)[0], 24.0f + temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1500);
        temp_f20 = code13Add(9.0f, temp_f20);
        sdkSpriteDrawAt((void *)p,
                      419.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1504);
        sdkSpriteDrawAt((void *)p,
                      473.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        break;
    case 1:
        color = D_0064B2E8;
        p = *(s32 *)(arg0 + 0x155C);
        temp_f20 = ((f32 *)&arg1)[1];
        sdkSpriteDrawAt((void *)p,
                      2.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
        p = *(s32 *)(arg0 + 0x1560);
        sdkSpriteDrawAt((void *)p,
                      474.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
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
    switch (*(s16 *)(entry + 0x16)) {
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
    sprite = *(void **)(work + 0x1548);
    sdkSpriteDrawAt(sprite, 4.0f + position.xy.x,
                  10.0f + initialY, 0xFF, 0xFF, 0xFF, inputAlpha);
    position.xy.y = position.xy.y + 36.0f;
    borderY = position.xy.y;
    sdkSpriteDrawAt(*(void **)(work + 0x154C), position.xy.x, borderY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = *(void **)(work + 0x1550);
    rightX = (f32)0x1C9 + position.xy.x;
    sdkSpriteDrawAt(sprite, rightX, borderY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = *(void **)(work + 0x1554);
    bottomY = 91.0f + borderY;
    sdkSpriteDrawAt(sprite, position.xy.x, bottomY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sprite = *(void **)(work + 0x1558);
    sdkSpriteDrawAt(sprite, rightX, bottomY,
                  color.rgb.r, color.rgb.g, color.rgb.b, inputAlpha);
    sdkSpriteDrawAt(*(void **)(work + 0x1588), 6.0f + position.xy.x,
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
    func_002bc4b0(0.0f, *(s16 *)entry, (s32)position.xy.x,
                  (s32)position.xy.y, labelColor, 1, 6);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
// Intent: Draw the header frame sprites when bit 2 of the flags is set, and the palette set when bit 1 is set [inferred]
// FUN_00135520
void radarDrawHeaderFrame(u8 *arg0, PackedVec2f arg1, u8 arg2, u16 arg3)
{
    f32 temp_f21;
    f32 temp_f20;
    u16 temp_16;
    u8 temp_17;
    u8 temp_18;
    u8 temp_19;
    void *temp_p;
    temp_17 = D_0064B2E8[0];
    temp_18 = D_0064B2E8[1];
    temp_19 = D_0064B2E8[2];
    temp_f21 = code13Add(arg1.xy.y, 26.0f);
    arg1.xy.y = temp_f21;
    temp_16 = (u16)arg3;
    if (temp_16 & 2) {
        sdkSpriteDrawAt(*(void **)(arg0 + 0x1538),
                      (temp_f20 = arg1.xy.x), temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x153C);
        temp_f20 = 467.0f + arg1.xy.x;
        sdkSpriteDrawAt(temp_p,
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x1540);
        temp_p = temp_p;
        temp_f20 = temp_f21 + 130.0f;
        sdkSpriteDrawAt(temp_p,
                      arg1.xy.x, temp_f20,
                      temp_17, temp_18, temp_19, arg2);
        sdkSpriteDrawAt(*(void **)(arg0 + 0x1544),
                      467.0f + arg1.xy.x, temp_f20,
                      temp_17, temp_18, temp_19, arg2);
    }
    if (temp_16 & 1) {
        arg1.xy.x -= 2.0f;
        arg1.xy.y -= 26.0f;
        radarDrawPaletteSet(arg0, arg1.packed, 1, arg2);
    }
}
#pragma pop
