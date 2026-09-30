#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - cmpConfig.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

typedef struct { f32 x, y; } Vec2f;

void func_0046d730(void* arg0, s32 arg1);
void func_0046d280(void *node);
void func_00460ac0(void* param, void* work);
void func_00106390(s32 a, s32 b);
s32 func_0035f0c0(u32* arg0, s32* arg1, u8* arg2);
s32 func_0034c210(void);
void func_0044ea90(void* file, s32 line);
void memset(void* dest, s32 value, s32 size);

void func_0034c260(s32 arg0);
void* func_0046a770(char* arg0);
s32 func_0046d200();
s32 datGetFlag(s32 arg0);
void func_00113480(s32 a, s32 b, s32 c, s32 d);
void func_001437b0(void* arg0, s32 arg1, s32 arg2);
void func_0034f8f0(void* arg0);
void func_0034f1e0(void);
void func_0034c270(Vec2f position, s32 alpha, s32 mode, f32 depth);
void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u8 arg4,
                   u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
f32 sinf(f32 arg0);

void func_0034f9d0(Vec2f unused, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
void func_00489f80(void);
void func_0045c870(void* arg0, s32 arg1);
void func_0048a000(void);
void RpSkyRenderStateSet(s32 a, s32 b);
void func_0035e820(u8* arg0);
s32 func_0035e720(u8* arg0);
s32 func_0035ce10(u8* arg0, s32 mode);
s32 func_0035cc80(u8* arg0, s32 arg1, s32 arg2);
void func_0035d000(u8* arg0, u8* arg1);
void func_0035ddf0(u8* arg0);
void func_0035d0a0(u8 *arg0);
void func_0035dfb0(u8* arg0, s32 arg1, s32 arg2);
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

// FUN_0035C690
s32 func_0035c690(void* arg0, s32 arg1) {
    s32 r;
    u8* work;

    func_0044ea90(D_0064D3C8, 0xC5);
    work = D_008873F4[0](1, 0x4B0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064D3C8, 0xC6);
    }
    r = (s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0064D3D8), 0xC7, 0, 0, func_0035e720, func_0035e820, (u8 *)(work));
    memset(work + 0x47C, 0, 0x30);
    *(s32 *)(work + 0x484) = (s32)func_0035d000;
    *(u8 **)(work + 0x48C) = work;
    *(u16 *)(work + 0x4AC) = 0xB1;
    *(s32 *)(work + 0x1C) = arg1;
    switch (arg1) {
    case 0:
        break;
    case 1:
        func_0034c260(1);
        break;
    default:
        func_0046d730(D_0064D3C8, 0xE6);
        break;
    }
    return r;
}

// FUN_0035C7D0
s32 func_0035c7d0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 1) != 0;
}

// FUN_0035C7F0
s32 func_0035c7f0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 4) != 0;
}

// FUN_0035C810
s32 func_0035c810(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 2) != 0;
}

// FUN_0035C830
void func_0035c830(u8* arg0) {
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

    *(s32 *)(arg0 + 0x20) = -1;
    func_0035ce10(arg0, 0);
    *(s32 *)(arg0 + 0x08) = 0;
    *(s32 *)(arg0 + 0x0C) = 0;
    *(u8 *)(arg0 + 0x00) = 0xFF;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x20) = -1;
    for (i = 0; i <= 0; i++) {
        *(s32 *)(arg0 + i * 4 + 0x30) = 0;
    }
    j = 0;
    table = D_0064D070;
    for (; j < 18; j++) {
        src = table + j * 20;
        dst = arg0 + j * 48;
        *(f32 *)(dst + 0x88) = *(f32 *)(src + 0x00);
        *(f32 *)(dst + 0x8C) = *(f32 *)(src + 0x04);
        *(u8 *)(dst + 0x92) = *(u8 *)(src + 0x08);
    }
    resource = (s32)(u32)func_0046a770((char *)D_005E5850);
    if (resource == 0) {
        func_0046d730(D_0064D3C8, 0x12F);
    }
    result = (s32)(u32)func_0046a770((char *)D_005E57F0);
    *(s32 *)(arg0 + 0x474) = result;
    for (k = 0; k < 11; k++) {
        dst = arg0 + k * 4 + 0x448;
        code = D_0064D3B8[k];
        *(s32 *)dst = func_0046d200(resource, code);
        if (*(s32 *)dst == 0) {
            func_0046d730(D_0064D3C8, 0x136);
        }
    }
    for (m = 0; m < 6; m++) {
        *(u16 *)(arg0 + m * 2 + 0x3A) = 5;
        result = datGetFlag(D_0064D3A0[m]);
        if (result != 0) {
            *(s32 *)(arg0 + m * 4 + 0x60) = 0;
            *(s32 *)(arg0 + m * 4 + 0x48) = 1;
        } else {
            *(s32 *)(arg0 + m * 4 + 0x60) = 1;
            *(s32 *)(arg0 + m * 4 + 0x48) = 0;
        }
    }
}


// FUN_0035CAB0
s32 func_0035cab0(u8 *arg0, s32 idx, s32 val) {
    s32 scaled = idx * 4;
    u8 *p = (u8 *)(scaled + (int)arg0);

    *(s32 *)(p + 0x34) = *(s32 *)(p + 0x30);
    *(s32 *)(p + 0x30) = val;
    if (idx == 0) {
        if (val == 6) {
            *(u16 *)(arg0 + 0x38) = 0;
        } else {
            *(u16 *)(arg0 + 0x38) = 0x12;
        }
    }
    return 1;
}

// FUN_0035CB00
s32 func_0035cb00(u8* arg0, s32 idx) {
    s32 scaled;
    s32 scaled2;
    s32* state_ptr;
    s32 state;
    s32 state_zero;
    s32 allowed;
    s32 temp;

    scaled = idx * 4;
    state_ptr = (s32 *)(scaled + (u32)arg0 + 0x48);
    state = *state_ptr;
    state_zero = ((u32)*state_ptr != 0) ^ 1;
    if (idx == 1) {
        if ((state_zero == 0) && (*(s32 *)(arg0 + 0x50) != 0)) {
            func_0035cc80(arg0, 2, 0);
        }
    } else if ((idx == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
        func_0045af60(0, 0, 0, 8);
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
    *(s32 *)(scaled + (int)arg0 + 0x60) = state;
    *state_ptr = ((u32)state > 0) ^ 1;
    scaled2 = idx * 2;
    *(u16 *)(scaled2 + (int)arg0 + 0x3A) = 0;
    if ((idx == 0) && (*state_ptr == 1)) {
        temp = datGetFlag(D_0064D3A0[0]);
        func_00106390(D_0064D3A0[0], 1);
        func_00113480(0xA, 0x96, 0xA, 0);
        func_00106390(D_0064D3A0[0], temp);
    }
    return 1;
}



// FUN_0035CC80
s32 func_0035cc80(u8 *arg0, s32 arg1, s32 arg2)
{
    typedef struct {
        u8 pad[0x48];
        s32 state;
    } ConfigEntry;
    s32 temp_16;
    s32 var_2;
    u8 *temp_2;

    temp_2 = (u8 *)&((ConfigEntry *)((u8 *)(arg1 * 4) + (u32)arg0))->state;
    if (*(s32 *)temp_2 == arg2) {
        return 0;
    }
    if (arg1 == 1) {
        if ((arg2 == 0) && (*(s32 *)(arg0 + 0x50) != 0)) {
            func_0035cc80(arg0, 2, 0);
        }
        goto block_9;
    }
    if ((arg1 == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
        func_0045af60(0, 0, 0, 8);
        var_2 = 0;
    } else {
block_9:
        var_2 = 1;
    }
    if (var_2 == 0) {
        return 0;
    }
    *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x60) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x48);
    *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x48) = arg2;
    *(s16 *)((u8 *)(arg1 * 2) + (u32)arg0 + 0x3A) = 0;
    if ((arg1 == 0) && (*(s32 *)temp_2 == 1)) {
        temp_16 = datGetFlag(D_0064D3A0[0]);
        func_00106390(D_0064D3A0[0], 1);
        func_00113480(0xA, 0x96, 0xA, 0);
        func_00106390(D_0064D3A0[0], temp_16);
    }
    return 1;
}


// FUN_0035CE10
s32 func_0035ce10(u8* arg0, s32 mode) {
    u8* tab = 0;
    s32 i;
    s32 j;

    if (*(s32*)(arg0 + 0x20) == mode) {
        return 0;
    }
    for (i = 0; i < 18; i++) {
        *(f32*)(arg0 + i * 48 + 0x78) = *(f32*)(arg0 + i * 48 + 0x88);
        *(f32*)(arg0 + i * 48 + 0x7C) = *(f32*)(arg0 + i * 48 + 0x8C);
        *(u8*)(arg0 + i * 48 + 0x90) = *(u8*)(arg0 + i * 48 + 0x92);
    }
    switch (mode) {
    case 0:
        tab = D_0064CD90;
        *(s32*)(arg0 + 0x24) = 3;
        *(u16*)(arg0 + 0x38) = 0x12;
        break;
    case 1:
        tab = D_0064D070;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    case 2:
        tab = D_0064CF00;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x207);
        break;
    }
    if (tab != 0) {
        for (j = 0; j < 18; j++) {
            *(f32*)(arg0 + j * 48 + 0x80) = *(f32*)(tab + j * 20 + 0);
            *(f32*)(arg0 + j * 48 + 0x84) = *(f32*)(tab + j * 20 + 4);
            *(u8*)(arg0 + j * 48 + 0x91) = *(u8*)(tab + j * 20 + 8);
            *(s32*)(arg0 + j * 48 + 0xA0) = *(s32*)(tab + j * 20 + 0xC);
            *(s32*)(arg0 + j * 48 + 0xA4) = *(s32*)(tab + j * 20 + 0x10);
        }
        *(s32*)(arg0 + 0x20) = mode;
        *(u16*)(arg0 + 0x28) = 0;
    }
    return 1;
}

// FUN_0035CFB0
s32 func_0035cfb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x18);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x18) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_0035D000
void func_0035d000(u8* arg0, u8* arg1) {
    s32 i;

    if (*(s16 *)(arg1 + 0x28) < 0x64) {
        *(s16 *)(arg1 + 0x28) = *(s16 *)(arg1 + 0x28) + 1;
    }
    for (i = 0; i < 18; i++) {
        s16 v = *(s16 *)(arg1 + 0x28);

        func_001437b0(arg1 + i * 48 + 0x78, v, 0);
    }
    func_0035ddf0(arg1);
    func_0035d0a0(arg1);
}

/* The menu owns 18 consecutive 48-byte animation records. */
typedef struct {
    Vec2f start;
    Vec2f target;
    Vec2f position;
    u8 startOpacity;
    u8 targetOpacity;
    u8 opacity;
    u8 unknown1B;
    u16 startWidth;
    u16 targetWidth;
    u16 width;
    u16 startHeight;
    u16 targetHeight;
    u16 height;
    s32 startFrame;
    s32 endFrame;
} ConfigMotion;

typedef struct {
    s16 unknown00;
    s16 height;
    s16 unknown04;
    s16 filled;
    s16 unknown08;
} ConfigGraphEntry;

typedef struct {
    u8 opacity;
    u8 unknown01[7];
    Vec2f origin;
    u8 unknown10[4];
    s32 backdropMode;
    u8 unknown18[0xC];
    u32 visible;
    u8 unknown28[8];
    s32 selectedOption;
    u8 unknown34[4];
    u16 helpStyle;
    u16 timers[7];
    s32 options[6];
    s32 previousOptions[6];
    ConfigMotion motion[18];
    ConfigGraphEntry graph[11];
    u8 unknown446[2];
    u8 *sprites[11];
    s32 helpTexture;
    u8 unknown478[0x38];
} ConfigMenuView;

typedef struct { u8 red, green, blue, alpha; } ConfigMenuColor;
typedef union { ConfigMenuColor rgba; f32 transport; } ConfigColorSnapshot;

static inline u32 config_gray_text(u8 alpha, u8 shade)
{
    return ((u32)shade << 24) | ((u32)shade << 16) | ((u32)shade << 8) | alpha;
}

/* Draw the live configuration graph, option rows, reset button and help text.
   The complete position/color records are shared across all draw phases.
   measured: 3092 matching code bytes plus 12 retail zero bytes. The scoped
   settings retain the source snapshots, constant lifetimes and loop roles;
   see docs/probe_archive/cmpConfig_0035d0a0_20260930.md. */
// FUN_0035D0A0
#pragma push
#pragma opt_pulloutconstants off
#pragma opt_propagation off
#pragma opt_lifetimes on

void func_0035d0a0(u8 *work) {
    extern int func_00274ed0(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags,
                             int charWidth);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags,
                             int charWidth);
    ConfigMenuView *menu;
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
    ConfigColorSnapshot color;
    u8 alpha;
    Vec2f pos;
    f32 fade;
    f32 baseX;
    f32 baseY;
    f32 graphX;
    f32 graphY;
    f32 topAlpha;
    f32 filledAlpha;

    menu = (ConfigMenuView *)work;
    func_0034f1e0();
    baseX = menu->origin.x;
    baseY = menu->origin.y;
    fade = (f32)menu->opacity / 255.0f;
    selectedOption = menu->selectedOption;
    backdropMode = menu->backdropMode;
    if (backdropMode != 0) {
        pos.x = baseX;
        pos.y = baseY;
        alpha = (u8)(255.0f * fade);
        func_0034c270(pos, alpha, backdropMode, 0.0f);
    }
    if ((menu->visible & 1) != 0) {
        pos.x = 26.0f + (baseX + menu->motion[0].position.x);
        pos.y = 388.0f + (baseY + menu->motion[0].position.y);
        alpha = (u8)((f32)menu->motion[0].opacity * fade);
        sprite = menu->sprites[0];
        func_0034f2e0(sprite, pos.x, pos.y, 0x5E, 0x37, 0xFF, alpha);
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
                for (; cellIndex < *(s16 *)(graphEntry + 0x3DA); cellIndex++) {
                    if (cellIndex == *(s16 *)(graphEntry + 0x3DA) - 1) {
                        color.rgba.red = 0xFF;
                        color.rgba.green = 0xFF;
                        color.rgba.blue = 0xA4;
                        color.rgba.alpha = (u8)topAlpha;
                    } else if (cellIndex < *(s16 *)(graphEntry + 0x3DE)) {
                        color.rgba.red = 0xFE;
                        color.rgba.green = 0xFF;
                        color.rgba.blue = 0x56;
                        color.rgba.alpha = (u8)filledAlpha;
                    } else {
                        continue;
                    }
                    pos.y = graphY + (f32)(cellIndex * 17);
                    func_0034f2e0(graphSprite, pos.x, pos.y, color.rgba.red, color.rgba.green, color.rgba.blue,
                                  color.rgba.alpha);
                }
            }
        }
        index = 0;
        pendingOption = -1;
        for (; index < 7; index++) {
            {
                f32 optionX, optionY;
                ConfigMotion *optionRow;
                u8 green;
                f32 pairY;
                /* Signed row offsets retain the work-relative option view. */
                optionRow = (ConfigMotion *)(work + index * 48 + 0xA8);
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
                func_0034f2e0(sprite, pos.x, pairY, color.rgba.red, green, rowBlue, alpha);
                sprite = menu->sprites[2];
                func_0034f2e0(sprite, 380.0f + pos.x, pairY, color.rgba.red, green, rowBlue, alpha);
                if (index == selectedOption) {
                    u8 *selectedPalette;
                    selected = 1;
                    selectedPalette = D_0064B2E8;
                    sprite = menu->sprites[6];
                    func_0034f2e0(sprite, pos.x, pairY, selectedPalette[0], selectedPalette[1], selectedPalette[2],
                                  alpha);
                    sprite = menu->sprites[8];
                    func_0034f2e0(sprite, 247.0f + pos.x, pairY, selectedPalette[0], selectedPalette[1],
                                  selectedPalette[2], alpha);
                    if ((index == 2) && (menu->options[1] == 0)) {
                        textColor = (alpha & 0xFF) | 0xB4B4B400;
                    } else {
                        textColor = (alpha & 0xFF) | 0xFFFFFF00;
                    }
                } else {
                    selected = 0;
                    if (index == 2) {
                        textColor = config_gray_text(alpha, 0x80);
                    } else {
                        textColor = (alpha & 0xFF) | 0x80808000;
                    }
                }
                pos.x = (f32)0x1C7 + optionX;
                pos.y = 122.0f + optionY;
                func_00275020(pos.x, pos.y, 0.0f, textColor, 8, 1, (const char *)D_0064D230[index], 2, -1);
            }
            if (index != 6) {
                u16 *timer = &menu->timers[index];
                if (*timer >= 5) {
                    func_0035dfb0(work, index, 0);
                } else {
                    if (pendingOption != -1) {
                        func_0035dfb0(work, pendingOption, 1);
                        func_0035dfb0(work, pendingOption, 2);
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
                button = work + index * sizeof(ConfigMotion);
                buttonX = (f32 *)(button + 0x208);
                pos.x = (f32)0x1CF + (baseX + *buttonX);
                buttonY = (f32 *)(button + 0x20C);
                pos.y = (f32)0x137 + (baseY + *buttonY);
                buttonPalette = D_0064B2E8;
                sprite = menu->sprites[7];
                func_0034f2e0(sprite, pos.x, pos.y, buttonPalette[0], buttonPalette[1], buttonPalette[2], alpha);
                sprite = menu->sprites[8];
                func_0034f2e0(sprite, 150.0f + pos.x, pos.y, buttonPalette[0], buttonPalette[1], buttonPalette[2],
                              alpha);
                pos.x = (f32)0x205 + (baseX + *buttonX);
                pos.y = (f32)0x13F + (baseY + *buttonY);
                sprite = menu->sprites[9];
                if (selected != 0) {
                    buttonColor = D_0064B2EC;
                } else {
                    buttonColor = D_0064B304;
                }
                func_0034f2e0(sprite, pos.x, pos.y, buttonColor[0], buttonColor[1], buttonColor[2], alpha);
            }
        }
        if (pendingOption != -1) {
            func_0035dfb0(work, pendingOption, 1);
            func_0035dfb0(work, pendingOption, 2);
        }
        pos.x = (f32)0x26B + (baseX + menu->motion[15].position.x);
        pos.y = (f32)0x15B + (baseY + menu->motion[15].position.y);
        alpha = (u8)((f32)menu->motion[15].opacity * fade);
        textColor = alpha | ~0xFF;
        func_00274ed0(pos.x, pos.y, 0.0f, textColor, 6, 1, (const char *)D_0064D380[selectedOption], 2, 0);
    }
    pos.x = 640.0f + (baseX + menu->motion[16].position.x);
    pos.y = 400.0f + (baseY + menu->motion[16].position.y);
    alpha = (u8)((f32)menu->motion[16].opacity * fade);
    func_0034f9d0(pos, 0.0f, alpha, menu->helpStyle, menu->helpTexture);
}

#pragma pop

// FUN_0035DCC0
s32 func_0035dcc0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x28);

    while (i < 18) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xA4)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_0035DD40
void func_0035dd40(u8* arg0) {
    s32 i;

    *(u8*)(arg0 + 4) |= 2;
    for (i = 0; i < 6; i++) {
        if (*(s32*)(arg0 + i * 4 + 0x48) != 0) {
            func_00106390(D_0064D3A0[i], 1);
        } else {
            func_00106390(D_0064D3A0[i], 0);
        }
    }
}

// FUN_0035DDF0
void func_0035ddf0(u8 *arg0)
{
    s32 top; s32 bottom; s32 i; s32 d1; s32 d2; s64 score; s16 tmp1; s16 tmp2; u8 *p;
    *(s16 *)(arg0 + 0x2A) = *(s16 *)(arg0 + 0x2A) + 1;
    if (*(s16 *)(arg0 + 0x2A) >= 0x19) *(s16 *)(arg0 + 0x2A) = 0;
    *(s16 *)(arg0 + 0x2C) = *(s16 *)(arg0 + 0x2C) + 1;
    if (*(s16 *)(arg0 + 0x2C) >= 0x1E) *(s16 *)(arg0 + 0x2C) = 0;
    top = (s32)((11.0f * (f32)*(s16 *)(arg0 + 0x2A)) / 25.0f);
    bottom = (s32)(11.0f * (1.0f - ((f32)*(s16 *)(arg0 + 0x2C) / 30.0f)));
    i = 0;
    while (i < 0xB) {
        if (i < top) d1 = top - i; else d1 = i - top;
        if (i < bottom) d2 = bottom - i; else d2 = i - bottom;
        score = 1;
        tmp1 = (s16)(10 - d1 * 2);
        if (tmp1 > 1) score = tmp1;
        tmp2 = (s16)(8 - d2 * 2);
        if (score < tmp2) score = tmp2;
        p = arg0 + i * 0xA;
        *(s16 *)(p + 0x3D8) = (s16)score;
        func_0034f8f0(p + 0x3D8);
        i++;
    }
}







/* 1764/1776 bytes; seventeen resolved relocations and twelve zero tail bytes.
 * Member-first array bases preserve the four retail ADDU operand orders.
 * The second arrow reloads its counter/selection, but keeps the first
 * sprite/coordinate snapshot; both text draws reload their field data. */
// FUN_0035DFB0
void func_0035dfb0(u8 *arg0, s32 arg1, s32 arg2)
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

    baseX = *(f32 *)(arg0 + 8);
    baseY = *(f32 *)(arg0 + 0xC);
    opacity = (f32)*arg0 / 255.0f;
    if (arg2 != 1) {
        rowAddress = arg1 * 0x30;
        rowAddress += (u32)arg0;
        row = (u8 *)rowAddress;
        x = 60.0f + (464.0f + (baseX + *(f32 *)(row + 0x208)));
        y = (119.0f + (baseY + *(f32 *)(row + 0x20C))) + 32.0f * (f32)arg1;
        arrowAlpha = (u8)((f32)*(u8 *)(row + 0x212) * opacity);
        sprite = *(u8 **)(arg0 + 0x45C);
        counterAddress = arg1 * 2;
        counterAddress += (u32)arg0;
        counter = *(u16 *)(counterAddress + 0x3A);
        if ((s32)counter < 5)
            phase = sinf((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(arg0 + 0x48))[arg1] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        func_0034f320(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, arrowAlpha,
                      0x1000, 0x1000, 0x11, angle, 0x11);
    }
    if (arg2 == 2) {
        func_00489f80();
        D_00887300[0](1, 0);
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0;
        func_0045c870(color, 0);
        counterAddress = arg1 * 2;
        counterAddress += (u32)arg0;
        counter = *(u16 *)(counterAddress + 0x3A);
        if ((s32)counter < 5)
            phase = sinf((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(arg0 + 0x48))[arg1] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        func_0034f320(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, 0xFF,
                      0x1000, 0x1000, 0x11, angle, 0x11);
        func_0048a000();
        RpSkyRenderStateSet(3, 0x2D801);
        RpSkyRenderStateSet(2, 0x44);
    }
    rowOpacity = (f32)arg0[arg1 * 0x30 + 0xC2];
    rowOpacity *= opacity;
    alpha = (u8)rowOpacity;
    if (arg2 == 1) {
        color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0x80;
    } else if (arg2 == 2) {
        color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0xFF;
    } else {
        counterAddress = arg1 * 4;
        counterAddress += (u32)arg0;
        if (*(s32 *)(counterAddress + 0x48) != 0) {
            color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0x80;
        } else {
            color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0xFF;
        }
    }
    rowXField = &((f32 *)(arg0 + 0x208))[arg1 * 12];
    x = (f32)0x1DD;
    x = x + (baseX + *rowXField);
    rowYField = (f32 *)(arg1 * 0x30 + arg0 + 0x20C);
    rowY = 32.0f * (f32)arg1;
    func_0034f2e0(*(u8 **)(arg0 + 0x454), x,
                  rowY + (121.0f + (baseY + *rowYField)),
                  color[0], color[1], color[2], alpha);
    func_0034f2e0(*(u8 **)(arg0 + 0x458),
                  556.0f + (baseX + *rowXField),
                  rowY + (131.0f + (baseY + *rowYField)),
                  otherColor, otherColor, otherColor, alpha);
    if (arg2 == 2) {
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
}

// FUN_0035E6A0
void func_0035e6a0(u8* arg0) {
    s32 i;

    for (i = 0; i < 0xB; i++) {
        u8* q = arg0 + i * 4;
        s32 v = *(s32*)(q + 0x448);

        if (v != 0) {
            func_0046d280((void *)v);
            *(s32*)(arg0 + i * 4 + 0x448) = 0;
        }
    }
    *(s32*)(arg0 + 0x24) = 0;
}

// FUN_0035E720
s32 func_0035e720(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x38);
    s32 local;

    if (p[4] & 1) {
        return 0;
    }
    switch (func_0035f0c0((u32*)(p + 0x478), &local, p)) {
    case 0:
        if (local != 0) {
            *(s32*)(p + 0x47C) = 0;
            *(s32*)(p + 0x480) = 0;
            func_00460ac0(D_00793E80 + *(u16*)(p + 0x4AC) * 48, p + 0x47C);
        }
        break;
    case 2:
        p[4] |= 4;
        /* fallthrough */
    case 1:
        p[4] |= 1;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x49E);
        break;
    }
    return 0;
}
