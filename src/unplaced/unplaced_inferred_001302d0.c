/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001302d0-00130ce0 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
extern u32 RpRandom(void);
extern s32 nLineIsIdle(void);
extern void sdkSpriteFreeNode(void *node);
extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void datEntryDrawRow(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2);
extern void datPanelResetCursor(u8 *arg0);
extern void datPanelDrawByKind(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern s32 datCalcGetLevelById(s32 arg0);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
#pragma push
#pragma opt_loop_invariants on
// Intent: Shift each of the four slots' positions and alphas into their previous values, highlight the selected slot, and reset the counter at +0x1C [inferred]
// FUN_001302D0
void radarPushSlotState(u8 *arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0x1608) = *(f32 *)(q + 0x1618);
        *(f32 *)(q + 0x160c) = *(f32 *)(q + 0x161c);
        *(u8 *)(q + 0x1620) = *(u8 *)(q + 0x1622);
        *(f32 *)(q + 0x16c8) = *(f32 *)(q + 0x16d8);
        *(f32 *)(q + 0x16cc) = *(f32 *)(q + 0x16dc);
        *(u8 *)(q + 0x16e0) = *(u8 *)(q + 0x16e2);
        if (*(s16 *)(arg0 + 0x26) == i) {
            *(s32 *)(q + 0x1610) = 0x41c80000;
            *(s32 *)(q + 0x16d0) = 0x41c80000;
        } else {
            *(s32 *)(q + 0x1610) = 0;
            *(s32 *)(q + 0x16d0) = 0;
        }
    }
    *(s16 *)(arg0 + 0x1c) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: Reset the indicator's colours and positions, choosing the x offset by comparing the counters at +0x24 and +0x2A [inferred]
// FUN_00130360
void radarResetIndicator(u8 *arg0) {
    f32 f0;
    f32 f1;

    *(u32 *)(arg0 + 0x1ab8) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac0) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac8) = 0x435d0000;
    *(u8 *)(arg0 + 0x1ad0) = 0xff;
    *(u8 *)(arg0 + 0x1ad2) = 0xff;
    *(u8 *)(arg0 + 0x1ad1) = 0;
    *(u32 *)(arg0 + 0x1af4) = 0;
    if (*(s16 *)(arg0 + 0x24) > *(s16 *)(arg0 + 0x2a)) {
        f0 = 21.0f + *(f32 *)(arg0 + 0x149c);
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = *(f32 *)(arg0 + 0x1acc) - 10.0f;
        *(u32 *)(arg0 + 0x1aec) = 0xc1200000;
    } else {
        f1 = 21.0f + *(f32 *)(arg0 + 0x158c);
        f0 = 170.0f + f1;
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = 10.0f + *(f32 *)(arg0 + 0x1acc);
        *(u32 *)(arg0 + 0x1aec) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 1
// Intent: Randomize the scatter of each of the twelve entries with probability three in four; the others keep their current alpha [inferred]
// FUN_00130430
void radarRandomizeEntries(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0xC; i++) {
        if (RpRandom() & 3) {
            p = arg0 + i * 0x30;
            val = (RpRandom() % 6U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x1880) = f;
            *(f32 *)(p + 0x1878) = f;
            *(u32 *)(p + 0x187C) = 0x43FA0000;
            *(f32 *)(p + 0x188C) = *(f32 *)(p + 0x187C);
            *(s32 *)(p + 0x1884) = 0xC2C80000;
            q = (u32 *)(p + 0x18A0);
            random = RpRandom() % 10U;
            *q = random;
            *(s32 *)(p + 0x18A4) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x187C) = *(f32 *)(p + 0x1884);
        }
    }
    *(s16 *)(arg0 + 0x1E) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
// Intent: Free the 51 sprite nodes in the radar sprite table and clear the count at +0x14 [inferred]
// FUN_00130580
void radarFreeSpriteNodes(u8 *arg0) {
    s32 i;
    u8 *p;
    u8 *q;
    s32 temp;

    i = 0;
    while (i < 0x33) {
        q = arg0 + i * 4;
        p = q + 0x1b18;
        temp = *(s32 *)(q + 0x1b18);
        if (temp != 0) {
            sdkSpriteFreeNode((void *)temp);
            *(s32 *)p = 0;
        }
        i++;
    }
    *(s32 *)(arg0 + 0x14) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
// Intent: Return 1 when the value at +0x1C is at least the threshold of every one of the 30 entries and the external check passes [inferred]
// FUN_00130600
s32 radarEntriesCoverValue(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x1c);

    while (i < 0x1e) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x1304)) {
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
#pragma opt_propagation off
// Intent: Draw one radar entry row: the panel row with its highlight, the level digits and the icon, at the slot position and fade [inferred]
// FUN_00130680
void radarDrawEntryRow(u8 *arg0, s32 arg1)
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
    u8 n;
    u8 alpha;
    f32 dim;
    f32 fade;
    f32 x;
    f32 y;
    f32 yoff;
    f32 ty;
    LabelParam param;
    Vec2f pos;
    void *spr;

    id = ((s16 *)(arg0 + 0x34))[arg1];
    dim = 1.0f;
    highlight = 0;
    datPanelResetCursor((u8 *)&param);
    param.mode = 1;
    param.id = id;
    x = *(f32 *)(arg0 + 4);
    y = *(f32 *)(arg0 + 8);
    fade = (f32)*(u8 *)arg0 / 255.0f;
    if (((*(s32 *)(arg0 + 0x14) & 0x10) != 0 && *(s16 *)(arg0 + 0x26) == arg1) || (*(s32 *)(arg0 + 0x14) & 0x20) != 0) {
        highlight = 1;
        param.highlight = highlight;
        color0 = D_0064B2E8;
        color1 = D_0064B2EC;
        color2 = D_0064B2FC;
    } else {
        param.highlight = 0;
        color0 = D_0064B2E0;
        color1 = D_0064B2F0;
        color2 = D_0064B308;
        dim = fGpffff82cc;
    }
    pos.x = 67.0f + (x + ((LabelSlot *)(arg0 + 0x16D8))[arg1].x);
    yoff = 75.0f * (f32)arg1;
    ty = 24.0f + (y + ((LabelSlot *)(arg0 + 0x16D8))[arg1].y);
    pos.y = ty + yoff;
    ty = ((LabelSlot *)(arg0 + 0x16D8))[arg1].alpha;
    datPanelDrawByKind(pos, 0.0f, (u8)(ty * fade), (u8 *)&param, 0);
    alpha = (f32)(arg0 + 0x1622)[arg1 * 0x30] * fade;
    pos.x = 60.0f + (x + ((f32 *)(arg0 + 0x1618))[arg1 * 12]);
    ty = y + ((f32 *)(arg0 + 0x161C))[arg1 * 12];
    pos.y = 21.0f + (ty + yoff);
    sdkSpriteDrawAt(*(void **)(arg0 + 0x1B90), pos.x, pos.y, color0[0], color0[1], color0[2], alpha);
    if (highlight != 0) {
        pos.x = 2.0f + (x + ((f32 *)(arg0 + 0x1618))[arg1 * 12]);
        ty = y + ((f32 *)(arg0 + 0x161C))[arg1 * 12];
        pos.y = 27.0f + (ty + yoff);
        sdkSpriteDrawAt(*(void **)(arg0 + 0x1B94), pos.x, pos.y, 0x4C, 0x4C, 0x4C, alpha);
    }
    n = datCalcGetLevelById(id);
    pos.x = 43.0f + (x + ((f32 *)(arg0 + 0x1618))[arg1 * 12]);
    ty = y + ((f32 *)(arg0 + 0x161C))[arg1 * 12];
    pos.y = 25.0f + (ty + yoff);
    if (n < 10) {
        pos.x -= 11.0f;
    }
    while (n > 0) {
        sdkSpriteDrawAt(*(void **)(arg0 + (n % 10) * 4 + 0x1BA4), pos.x, pos.y, color1[0], color1[1], color1[2], alpha);
        pos.x -= 22.0f;
        n /= 10;
    }
    pos.x = 37.0f + (x + ((f32 *)(arg0 + 0x1618))[arg1 * 12]);
    ty = y + ((f32 *)(arg0 + 0x161C))[arg1 * 12];
    pos.y = 53.0f + (ty + yoff);
    spr = *(void **)(arg0 + 0x1BE0);
    sdkSpriteDrawAt(spr, pos.x, pos.y, color2[0], color2[1], color2[2], (u8)((f32)alpha * dim));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
// Intent: Draw a sprite at the given position and another 340 units to its right, with the given colour [inferred]
// FUN_00130C30
/* measured: opt_propagation off probe for radarDrawSpritePair ordering. */
#pragma opt_propagation off
void radarDrawSpritePair(u8 *arg0, s64 arg1, s32 arg2)
{
    f32 c0;
    s32 p;
    u8 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1b60);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    sdkSpriteDrawAt((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    sdkSpriteDrawAt(*(void **)(arg0 + 0x1b64),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 2
#pragma opt_propagation on
/* 1476/1488 bytes; fourteen resolved relocations and twelve zero tail bytes.
 * The position and color copies have their full object extents. Keep the
 * original Y component and the shared sprite cursor across the draw pairs. */
// Intent: Draw one radar entry card: the background bars, the value text and the entry row, at the given position and alpha [inferred]
// FUN_00130CE0
void radarDrawEntryCard(u8 *work, PackedVec2f inputPosition, s32 inputAlpha, s16 *entry)
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

    originalY = inputPosition.xy.y;
    opacityValue = (f32)(u32)*(u8 *)(work + 0);
    opacityScale = opacityValue / 255.0f;
    colors.current.b[0] = 0x14;
    colors.current.b[1] = 0x14;
    colors.current.b[2] = 0x14;
    scaledAlpha = 204.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    height = (f32)(u32)*(u16 *)(work + 0x15FE);
    position.xy.x = inputPosition.xy.x - 1.0f;
    inputPosition.xy.y = 24.0f;
    inputPosition.xy.y += originalY;
    position.xy.y = inputPosition.xy.y;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = *(u8 **)(work + 0x1BD4);
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawSized(sprite, position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
        sprite = *(u8 **)(work + 0x1BD8);
        sdkSpriteDrawSized(sprite, (f32)0x159 + position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
    }
    {
        f32 x;
        x = 5.0f + inputPosition.xy.x;
        x += *(f32 *)(work + 0x1858);
        position.xy.x = x;
    }
    {
        f32 y;
        y = 34.0f + originalY;
        y += *(f32 *)(work + 0x185C);
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
        sprite = *(u8 **)(work + 0x1BCC);
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawAt(sprite, position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
        sdkSpriteDrawAt(*(void **)(work + 0x1BD0), 330.0f + position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
    }
    position.xy.x = inputPosition.xy.x;
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
        sprite = *(u8 **)(work + 0x1B60);
        alpha = colors.copy.b[3];
        blue = colors.copy.b[2];
        green = colors.copy.b[1];
        y = palettePosition.xy.y;
        sdkSpriteDrawAt(sprite, palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
        sprite = *(u8 **)(work + 0x1B64);
        sdkSpriteDrawAt(sprite, 340.0f + palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
    }
    position.xy.x = position.xy.x - 2.0f;
    datEntryDrawRow(position.xy, 0.0f, colors.current.b[3], (u8 *)entry);
    position.xy.x = 22.0f + inputPosition.xy.x;
    position.xy.y = 54.0f + originalY;
    labelAlpha = (u8)scaledInputAlpha;
    func_002bc4b0(0.0f, *entry, (s32)position.xy.x, (s32)position.xy.y,
                  (labelAlpha & 0xFF) | ~0xFF, 1, 8);
}
#pragma pop
