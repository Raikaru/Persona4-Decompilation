#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
extern void (*jtbl_008873EC[])(void *);

extern void (*D_008873ec[])(s32);

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void memset(void *dst, s32 value, u32 size);
extern s32 func_0010b6f0(void);
extern s32 func_0010b5b0(void);
extern s32 func_0010ac10(u16 arg0);
extern u8 *func_00109220(u16 arg0);
extern void func_002bad10(s32 arg0);
extern void func_002bbd20(s32 arg0, void *arg1);
extern u8 *func_0010b010(u16 personaId);
extern s32 func_00376590(u8 *arg0, u8 *arg1);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void func_00389cb0(u8 *arg0);
extern void func_0038d020(u8 *arg0);
extern void func_003889b0(s32 arg0, u8 *arg1);
extern void func_0044ea90(const void *arg0, s32 arg1);

extern void func_00388d10(u8 *arg0);
extern void func_003874c0(s32 arg0, u8 *arg1);
extern s32 func_00388b40(u8 *arg0);
extern void func_00388ba0(u8 *arg0);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern void func_0034f1e0(void);
extern void func_0038acd0(u8 *arg0);
extern void func_0038bab0(u8 *arg0);
extern void func_0038c100(u8 *arg0);
extern void func_0038c770(u8 *arg0);
extern void func_0038cab0(u8 *arg0);

extern f32 D_00761470;
extern f32 D_008872F8[];
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
extern s32 func_00457120(void);
extern f32 cosf(f32 fparg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 func_003df590(s32 arg0, ...);
extern u8 *func_003df4d0(s32 *arg0);
extern void func_00389370();
extern void func_00389640();
extern void func_00389e10();
extern void func_0038a940();
extern void func_0038b1c0();
extern void func_0034f460(s32 resource, s32 slot, f32 x, f32 y,
                          u8 r, u8 g, u8 b, u8 alpha);
extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0,
                          s16 arg_sp8);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

// FUN_00380980
s32 func_00380980(u8 *arg0)
{
    typedef struct {
        s32 active;
        u16 value0;
        u16 value1;
        u16 value2;
    } Result;
    extern s32 func_0036f640(s32 arg0, s32 *arg1);
    extern u8 *func_00109220(u16 arg0);
    extern u8 *func_00243840(s32 arg0);
    extern s32 func_002bad10(s32 arg0);
    extern void func_002bbd20(s32 arg0, void *arg1);
    extern void func_0038daf0(u8 *arg0, s32 arg1);
    extern void sprintf(void *arg0, const void *arg1, s32 arg2);
    extern s32 D_0064EB80[];
    extern s32 D_0064EB84[];
    extern u8 D_0064EC30[];
    extern u8 iGpffffa9E8;
    u8 *base;
    u8 *state;
    u32 id;
    s32 index;
    s32 channel;
    s32 packed;
    s32 result;
    s32 high;
    s32 original;
    s16 *flags;
    s32 *entry;
    u8 *resource;
    u8 text[64];
    Result output;

    base = *(u8 **)arg0;
    state = arg0 + 0x18;
    id = *(u8 *)(arg0 + 0x12);
    if (id == 1) {
        id = *(u8 *)(state + 0xC);
    }
    id &= 0xFF;
    index = id - 1;
    channel = index * 4 + 0x15;
    packed = (id << 16) | ((*(s32 *)(state + 0x10) != 0) ? 1 : 0);
    result = func_0036f640(packed, (s32 *)&output);
    high = ((u32)(result & 0xFFFF0000) >> 16) & 0xFFFF;
    if (high != 0) {
        original = ((u32)(packed & 0xFFFF0000) >> 16) & 0xFFFF;
        if (high != original) {
            *(s32 *)(state + 0x18) = result;
        }
    }
    if (output.active != 0) {
        flags = (s16 *)(D_0064EC30 + index * 2);
        if ((*flags & 1) != 0) {
            func_002bbd20(0, func_00109220(output.value0));
        }
        if ((*flags & 2) != 0) {
            func_002bbd20(1, func_00243840(output.value1));
            func_002bbd20(4, func_00243840(output.value2));
        }
        if ((*flags & 4) != 0) {
            sprintf(text, &iGpffffa9E8, (s16)output.value2);
            func_002bbd20(2, text);
        }
        if ((*flags & 8) != 0) {
            func_002bbd20(3, func_00109220(output.value2));
        }
    } else {
        func_002bad10(channel + 3);
        return 1;
    }
    if (*(s32 *)(state + 0x10) != 0) {
        entry = D_0064EB80 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 1);
    } else {
        entry = D_0064EB84 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 2);
    }
    return 1;
}
// FUN_00380BD0
s32 func_00380bd0(u8 **arg0)
{
    extern u8 func_00109bf0(u16 arg0, s32 arg1);
    extern s32 func_00104c70(s32 arg0);
    extern s32 datGetFlag(s32 arg0);
    extern u32 RpRandom(void);
    extern u8 D_0064E760[];
    f32 temp_f1;
    f32 var_f1;
    u16 temp_16;
    u16 temp_2;
    s32 var_3;
    u8 var_16;
    if (*(s32 *)(*arg0 + 0x1F30C) != 0) {
        return 0;
    }
    temp_16 = func_00109bf0(1, 4) & 0xFF;
    func_00104c70(1);
    if (datGetFlag(0x1426) != 0) {
        var_16 = 0x3C;
    } else if (datGetFlag(0x1427) != 0) {
        var_16 = 0xA;
    } else {
        temp_2 = temp_16 & 0xFF;
        if (temp_2 == 0) {
            temp_2 = 1;
        } else if (temp_2 > 0x63) {
            temp_2 = 0x63;
        }
        var_16 = D_0064E760[((temp_2 & 0xFF) - 1) / 10];
    }
    var_f1 = (f32)(u32)(RpRandom() & 0xFFF);
    temp_f1 = 100.0f * (var_f1 / 4096.0f);
    var_3 = (u8)temp_f1;
    return (var_3 & 0xFF) < (var_16 & 0xFF);
}
// FUN_00380D80
s32 func_00380d80(u8 *arg0, s32 arg1)
{
    u16 count2;
    u16 count1;

    count1 = func_0010b6f0();
    count2 = func_0010b5b0();
    if (func_0010ac10(arg1) != 0) {
        func_002bad10(2);
        return 6;
    }
    if (count1 == count2) {
        memset(arg0 + 0x18, 0, 0x7C);
        func_002bbd20(0, func_00109220(arg1));
        func_002bad10(3);
        return 7;
    }
    func_0010b010((u16)arg1);
    func_002bbd20(0, func_00109220(arg1));
    func_002bad10(1);
    return 5;
}
// FUN_00383C00
s32 func_00383c00(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) != 0;
}
// FUN_00383C20
u32 func_00383c20(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 4;
    return *(u32 *)(p + 0x14);
}
// FUN_00383C40
void func_00383c40(u8 *arg0)
{
    u8 *base;
    s32 value;
    u8 colors[4];

    base = *(u8 **)arg0;
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    switch (*(s32 *)(base + 0x1F2FC)) {
    case 0:
    case 1:
    case 2:
        value = func_00376590(base, 0);
        break;
    case 3:
        value = *(u16 *)(base + 0x1F1D4);
        break;
    default:
        func_0046d730(D_0064EEB0, 0x103);
        break;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    func_00377930(base, value, 0, colors, 1);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
// FUN_00383D70
void func_00383d70(u8 *arg0)
{
    extern f32 sinf(f32 fparg0);
    extern f32 iGpffff81e0;
    extern f32 fGpffff8198;
    extern f32 fGpffff809c;
    u8 *state;
    u8 *base;
    u8 *flags;
    s32 value;
    s32 i;
    u8 colors[4];
    f32 alpha;

    state = arg0 + 0x28;
    base = *(u8 **)arg0;
    flags = base + 0x1F1D0;
    if ((*(u16 *)flags & 2) != 0 ||
        (*(u16 *)flags & 4) != 0) {
        return;
    }
    if (*(s32 *)(state + 0x14) <= 0) {
        return;
    }
    value = (*(u16 *)state + 1) % 30;
    *(u16 *)state = value;
    colors[0] = 0;
    colors[1] = 70;
    colors[2] = 120;
    alpha = 255.0f *
        (fGpffff8198 * sinf((iGpffff81e0 *
                                     (f32)*(u16 *)state) / 30.0f) +
         fGpffff809c + 0.0f);
    colors[3] = (u8)alpha;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (i = 0; i < *(s32 *)(state + 0x14); i++) {
        func_00377930(base, *(s32 *)(state + i * 4 + 4), 0,
                      colors, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* Window frame fade.  The 192 alpha is converted at each vertex (u8)(192.0f *
   scale) - the product is shared, the float->u8 conversion is not - and the
   primitive table is read through an integer view so its address stays in
   $s0 across the first draw, as in func_0034ae70's twin 0014dd80 recipe. */
// FUN_00383F80
void func_00383f80(u8 *arg0)
{
    extern f32 func_00373cb0(f32 t, f32 a, f32 b, s32 mode);
    extern s32 func_00378530(s32 a, s32 b);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex;
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 colors[4];
    Vertex work[4];
    f32 f22;
    f32 f21;
    f32 scale;
    u8 alpha;
    s32 var17;
    s32 count;
    s32 tmp;
    s32 i;
    s32 lo;
    u32 draw;
    s32 j;
    s32 hi;
    u16 flags;
    s32 v18;

    state = arg0 + 0x20;
    ctx = *(u8 **)arg0;
    info = ctx + 0x1F1D0;
    flags = *(u16 *)state;
    if (!(flags & 1)) {
        scale = func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = 255.0f * scale;
        if (++*(u16 *)(state + 2) >= 0xA) {
            *(u16 *)state = *(u16 *)state | 1;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f - func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = 255.0f * scale;
        if (++*(u16 *)(state + 2) >= 0xA) {
            *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFDF;
        }
    } else {
        scale = 1.0f;
        alpha = 0xFF;
    }
    v18 = *(u16 *)(info + 4);
    v18 = (v18 < 3) ? v18 : 2;
    tmp = *(s32 *)(ctx + 0x1F304);
    var17 = (tmp < 6) ? tmp * 2 : tmp;
    count = func_00378530(tmp, *(s32 *)(ctx + 0x1F2FC));
    f22 = D_008872F8[0];
    f21 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    colors[0] = 0x5F;
    colors[1] = 0x31;
    colors[2] = 0;
    colors[3] = (u8)(((alpha & 0xFF) * 0xC0) / 255);
    lo = var17 * (v18 + 1);
    hi = count;
    for (i = lo; i < hi; i++) {
        func_00377930(ctx, i, 0, colors, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    colors[0] = 0x50;
    colors[1] = 0x4B;
    colors[2] = 0x3C;
    colors[3] = (u8)(((alpha & 0xFF) << 7) / 255);
    lo = var17 * v18;
    hi = var17 * (v18 + 1);
    for (j = lo; j < hi; j++) {
        func_00377930(ctx, j, 0, colors, 0);
    }
    colors[0] = 0xFF;
    colors[1] = 0xC5;
    colors[2] = 0x50;
    work[0].x = 156.0f;
    work[0].y = 0.0f;
    work[0].z = f22;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = (u8)(192.0f * scale);
    work[0].scale = f21;
    work[1].x = (f32)0x1D9;
    work[1].y = 0.0f;
    work[1].z = f22;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = (u8)(192.0f * scale);
    work[1].scale = f21;
    work[2].x = 156.0f;
    work[2].y = 84.0f;
    work[2].z = f22;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = 0.0f;
    work[2].scale = f21;
    work[3].x = (f32)0x1D9;
    work[3].y = 84.0f;
    work[3].z = f22;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = 0.0f;
    work[3].scale = f21;
    draw = (u32)D_00887310;
    (*(s32 (**)(s32, void *, s32))draw)(4, work, 4);
    work[0].x = 156.0f;
    work[0].y = 364.0f;
    work[0].z = f22;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = 0.0f;
    work[0].scale = f21;
    work[1].x = (f32)0x1D9;
    work[1].y = 364.0f;
    work[1].z = f22;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = 0.0f;
    work[1].scale = f21;
    work[2].x = 156.0f;
    work[2].y = 448.0f;
    work[2].z = f22;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = (u8)(192.0f * scale);
    work[2].scale = f21;
    work[3].x = (f32)0x1D9;
    work[3].y = 448.0f;
    work[3].z = f22;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = (u8)(192.0f * scale);
    work[3].scale = f21;
    (*(s32 (**)(s32, void *, s32))draw)(4, work, 4);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* Line and icon fade for the selected shuffle pattern.
 * The halfword frame increment wraps before the phase test; byte
 * opacities and the shared point preserve the native call boundaries. */
// FUN_00384CC0
void func_00384cc0(u8 *work)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 work);
    extern f32 fGpffff83c0;
    extern f32 fGpffff83c4;
    extern const Vec2f D_0064ECC0[13];
    struct LineAnimation { u16 flags; u16 frame; } *state;
    u8 *base;
    u16 *patternFlags;
    s32 texture;
    Vec2f point;
    u16 flags;
    u16 nextFrame;
    f32 progress;
    u8 lineAlpha;
    u8 iconAlpha;
    u8 overlayAlpha;
    s32 packed;
    u16 mask;
    u32 selectedMask;
    u32 drawOverlay;
    s32 i;
    const Vec2f *entry;
    state = (struct LineAnimation *)(work + 0x24);
    base = *(u8 **)work;
    patternFlags = (u16 *)(base + 0x1F1D0);
    texture = *(s32 *)(base + 0x1F2AC);
    mask = 0;
    if (*(s32 *)(base + 0x1F2FC) != 4) {
        func_0046d730(D_0064EEB0, 459);
    }
    flags = state->flags;
    if ((flags & 1) == 0) {
        lineAlpha = 0;
        progress = (f32)state->frame;
        iconAlpha = (u8)(255.0f * func_00373cb0(progress, 0.0f, 5.0f, 1));
        overlayAlpha = 0;
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 5) {
            state->flags = state->flags | 1;
            state->flags = state->flags | 2;
            state->frame = 0;
        }
    } else if (flags & 2) {
        progress = (f32)state->frame;
        lineAlpha = (u8)(255.0f * func_00373cb0(progress, 0.0f, 3.0f, 1));
        iconAlpha = 0xFF;
        progress = (f32)state->frame;
        overlayAlpha = (u8)(255.0f * (1.0f - func_00373cb0(progress, 5.0f, 10.0f, 1)));
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 10) {
            state->flags = state->flags & 0xFFFD;
            state->frame = 0;
        }
    } else if (flags & 4) {
        progress = (f32)state->frame;
        lineAlpha = (u8)(255.0f * (1.0f - func_00373cb0(progress, 0.0f, 5.0f, 1)));
        overlayAlpha = lineAlpha;
        iconAlpha = lineAlpha;
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 10) {
            *(u16 *)(work + 0x4C) = *(u16 *)(work + 0x4C) & 0xFFBF;
            state->frame = 0;
        }
    } else {
        lineAlpha = 0xFF;
        iconAlpha = lineAlpha;
        overlayAlpha = 0;
    }
    point.x = 314.0f;
    point.y = 237.0f;
    packed = (lineAlpha & 0xFF) | 0x3767FF00;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    if (*patternFlags & 0x20) {
        if (lineAlpha != 0) {
            func_00364c90(point, 0.0f, packed, 403.0f, 2.0f, 0.0f, 1);
        }
        mask |= 0x1F;
    }
    point.x = 314.0f;
    point.y = 236.0f;
    if (*patternFlags & 0x10) {
        if (lineAlpha != 0) {
            func_00364c90(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c0, 1);
        }
        mask |= 0x1E1;
    }
    point.x = 316.0f;
    point.y = 236.0f;
    if (*patternFlags & 0x40) {
        if (lineAlpha != 0) {
            func_00364c90(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c4, 1);
        }
        mask |= 0x1E01;
    }
    i = 0;
    selectedMask = (u16)mask;
    drawOverlay = (u8)overlayAlpha;
    for (; i < 13; i++) {
        if (selectedMask & (1 << i)) {
            entry = D_0064ECC0 + i;
            point.x = entry->x;
            point.y = entry->y;
            func_0034f460(texture, 55, point.x, point.y, 0xFF, 0xFF, 0xFF, iconAlpha);
            if (drawOverlay != 0) {
                func_0034f460(texture, 55, point.x, point.y, 0xFF, 0xFF, 0xFF, overlayAlpha);
            }
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* measured: probe_variants func_00385380 base 336wd honest (exclusive <0x12, Vec2f{318,231}, plain accumulators, (u8)/(u16) clamps), inclusive (>0x12/slti 0x13) 336wd tie (no $at site, lever N/A beyond exclusivity), pragma_schedule 335wd (-1 churn, fnalign 411 vs 193 edits worse, not adopted); fnalign base retail 377/object 320 (193 edits +1 reloc-only; frame 0x90->0x80, s3->s2, accumulator madd chains); providers verified (373cb0, 3f6440, 64c90, 34f4a0, 44b7b0/610, DAT_007613F8/fGp82cc/80bc/83c8 per Draft5380); Ghidra/IDA agree; archive docs/probe_archive/P038_00385380_body.c (COP1 floor note, consistent); lever 4 tie; banked guarded floor for opclass measurability (object 320/377, 15% short noted plainly, stays out per 3% rule for MATCH but in as floor for triage). */
/* measured this batch: hoisting N/A (no D_00887310/global-pointer call, no loop; DAT_007613F8/fGp globals read straight-line only); direct (u8)/(u16) casts (was (u8)(s32)/(u16)(s32)) recover retail clamping chains: fnalign retail 377/object 366 (-2.9% inside gate, was 320/-15.1%), edits 194+1 reloc-only (was 193+1), max hole 49@0x385818 -> 4@0x3854F0, max lump 30 retained, guarded 342wd (was 336wd outside gate, not comparable per handoff 7y), opclass 29 -> 8 (lui -4, mtc1 -4 remain); remaining deletes 0x3854F0(4, Vec 318/231 lui/sw), 0x3858EC(2, x/y reload), 0x385900(1, move t1,s2 idx). */
// FUN_00385380 NONMATCHING
#ifdef NON_MATCHING
void func_00385380(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    typedef struct { f32 x; f32 y; } Vec2f_5380;
    extern void func_00364c90(Vec2f_5380 pos, f32 depth, s32 color, f32 width, f32 height, f32 angle, s32 mode);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    extern f32 sinf(f32 fparg0);
    extern f32 cosf(f32 fparg0);
    extern f32 DAT_007613F8;
    extern f32 fGpffff82cc;
    extern f32 fGpffff80bc;
    extern f32 fGpffff83c8;
    u16 *cnt = (u16 *)(arg0 + 0x1E);
    s32 res = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    f32 eased1;
    f32 w1;
    f32 t1;
    f32 blend1;
    f32 w2;
    f32 t2;
    f32 blend2;
    f32 b;
    u8 idx;
    f32 delta;
    f32 inv;
    f32 v21;
    f32 v23;
    f32 s1;
    f32 c1;
    f32 s2;
    f32 c2;
    f32 x;
    f32 y;
    u16 cdelta;
    u16 cblend;
    u16 next;
    eased1 = func_00373cb0((f32)*cnt, 14.0f, 18.0f, 2);
    w1 = func_00373cb0((f32)*cnt, 5.0f, 6.0f, 1);
    t1 = func_00373cb0((f32)*cnt, 0.0f, 5.0f, 1);
    blend1 = DAT_007613F8 * w1 + (fGpffff80bc - fGpffff82cc * t1);
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    func_00364c90((Vec2f_5380){318.0f, 231.0f}, 0.0f, 0x71BA00FF, (blend1 - eased1) * 270.0f, blend1 * 45.0f, fGpffff83c8, 0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    w2 = func_00373cb0((f32)*cnt, 5.0f, 6.0f, 1);
    t2 = func_00373cb0((f32)*cnt, 2.0f, 5.0f, 1);
    blend2 = DAT_007613F8 * w2 + (fGpffff80bc - fGpffff82cc * t2);
    delta = blend2 - eased1;
    b = func_00373cb0((f32)*cnt, 2.0f, 5.0f, 1);
    idx = (u8)(255.0f * b);
    inv = 1.0f - delta;
    v21 = (inv * 190.0f) / 2.0f;
    s1 = sinf(fGpffff83c8);
    c1 = cosf(fGpffff83c8);
    v23 = (inv * 39.0f) / 2.0f;
    s2 = sinf(fGpffff83c8);
    c2 = cosf(fGpffff83c8);
    x = 221.0f + v21 * c1 - v23 * s1;
    y = 235.0f + 2.0f + v21 * s2 + ((1.0f - blend2) * 39.0f) / 2.0f * c2;
    cdelta = (u16)(4096.0f * delta);
    cblend = (u16)(4096.0f * blend2);
    func_0034f4a0(res, 0x12, x, y, 0.0f, 0, 0, 0, idx, cdelta, cblend, -15.0f, 0, 0);
    next = *cnt + 1;
    *cnt = next;
    if ((u16)(next & 0xFFFF) >= 0x12) {
        *(u16 *)(arg0 + 0x4C) &= (u16)~8;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385380);
#endif
/* measured: honest first reconstruction per func_0038bab0/86c00 idiom (u8* state at +0x04 plus base, (f32)(u16) counters bltz double, plain (u8) clamps, sequential <0x20/<0xA/<5 guards empty else, block-scoped next/i, plain arithmetic no COP1 exemption, s64 pos via spA8/spAC shift/or packing per bab0; m2c+romwright into /var/tmp/cold385970 (m2c_385970.c 422 lines + rom_385970.c 259 lines + rom_raw 245 lines + types int(void*) 1082 instr arity trusted); probe_variants v1 938 base honest, R1 branch 934 win (-4, inner &8 !=0 with C-first matches retail beqz), swap 940 regress (+2), inclusive 940 regress (+2), frev/s64/nextfunc/staterev/loop 938 ties; R2 flip2 938 regress (+4), bswap/binc 936 regress (+2), bfrev/bs64/bnext/bloop/bstate 934 ties unproductive, stop after two rounds per batch; pragma prag1/prag2 934 ties not adopted; fnalign branch retail 1187/object 1175 (12 short 1.0% within 3%, 289 edits +3 reloc-only, vs v1 360 edits -71 from branch fix, frame 0xB0, sh/andi order + $v0/$v1 + GP offsets + COP1 mula/madd/adda/msub floor remain); providers verified (373cb0 f32,f32,f32,s32 per btlShuffleCalc.c:43, 64fb0 s64,u32,s32,s32,f32,f32 per generated/code1_0036.c:1920, 34f4a0 per this file:75, 3f6440 s32,s32 per this file:25, 3b7060 s32(void) per this file:176 as (u32)&0xFFF idiom, 44b7b0 f32 per btlShuffleCalc.c:27, fGp8374/83cc/81e0 per GP -0x7C8C/-0x7C34/-0x7E20, D_0064ED30 12B table per asm lui); Ghidra/IDA agree on CFG/32-call order, differ on 64fb0/34f4a0 prototypes and GP naming (used file idiom); lever 4 exclusive <0x20/<0xA/<5/<0x1E/<15 correct (inclusive regresses); lhu/lbu correct; double-def offset remains + COP1 chains (26 mula/madd/adda/msub); re-derived, no fabrications; archive P038_00385970_body.c is seven-line stub, not a body. Banked guarded floor. */
// FUN_00385970 NONMATCHING
#ifdef NON_MATCHING
void func_00385970(u8 *arg0)
{
    typedef struct { f32 x; f32 y; } Vec2f_5970;
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    extern u32 RpRandom(void);
    extern f32 sinf(f32 fparg0);
    extern f32 fGpffff8374;
    extern f32 fGpffff83cc;
    extern f32 fGpffff81e0;
    extern u8 D_0064ED30[];
    u8 *base;
    u8 *state;
    s32 resource;
    f32 var_f25;
    f32 var_f24;
    f32 var_f23;
    f32 var_f29;
    f32 var_f22;
    f32 blend;
    Vec2f position;
    base = *(u8 **)arg0;
    state = arg0 + 4;
    resource = *(s32 *)(base + 0x1F2AC);
    if ((*(u16 *)state & 1) == 0) {
        var_f25 = 1.0f - func_00373cb0((f32)*(u16 *)(state + 2), 10.0f, 21.0f, 2);
        var_f24 = 1.0f - func_00373cb0((f32)*(u16 *)(state + 2), 19.0f, 21.0f, 2);
        var_f23 = 0.0f;
        var_f29 = 0.0f;
        var_f22 = func_00373cb0((f32)*(u16 *)(state + 2), 21.0f, 25.0f, 1);
        {
            u16 next;
            next = *(u16 *)(state + 2) + 1;
            *(u16 *)(state + 2) = next;
            if ((next & 0xFFFF) < 0x20) {
            } else {
                *(u16 *)state = *(u16 *)state | 1;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if ((*(u16 *)state & 4) == 0) {
        if ((*(u16 *)state & 8) != 0) {
            var_f25 = 0.0f;
            var_f24 = 0.0f;
            var_f23 = 1.0f;
            var_f29 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 5.0f, 0);
            var_f22 = 1.0f;
            {
                u16 next;
                next = *(u16 *)(state + 2) + 1;
                *(u16 *)(state + 2) = next;
                if ((next & 0xFFFF) < 5) {
                } else {
                    *(u16 *)(state + 2) = 0;
                }
            }
        } else {
            if ((*(u16 *)state & 2) == 0) {
                var_f25 = 0.0f;
                var_f24 = 0.0f;
                var_f23 = 0.0f;
                var_f29 = 0.0f;
                var_f22 = 1.0f;
            } else {
                var_f25 = func_00373cb0((f32)*(u16 *)(state + 2), 4.0f, 10.0f, 2);
                var_f24 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 6.0f, 2);
                var_f23 = 0.0f;
                var_f29 = 0.0f;
                var_f22 = 1.0f - func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 0.0f, 1);
                {
                    u16 next;
                    next = *(u16 *)(state + 2) + 1;
                    *(u16 *)(state + 2) = next;
                    if ((next & 0xFFFF) < 0xA) {
                    } else {
                        *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFFE;
                        *(u16 *)(state + 2) = 0;
                    }
                }
            }
        }
    } else {
        var_f25 = 0.0f;
        var_f24 = 0.0f;
        var_f23 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 2);
        var_f29 = 0.0f;
        var_f22 = 1.0f;
        {
            u16 next;
            next = *(u16 *)(state + 2) + 1;
            *(u16 *)(state + 2) = next;
            if ((next & 0xFFFF) < 0xA) {
            } else {
                *(u16 *)state = *(u16 *)state & 0xFFFB;
                *(u16 *)state = *(u16 *)state | 8;
                *(u16 *)(state + 2) = 0;
            }
        }
    }
    if ((*(u16 *)state & 0x10) != 0) {
        if (*(u16 *)(state + 6) < 0x1E) {
            *(u16 *)(state + 6) = *(u16 *)(state + 6) + 1;
        }
    }
    blend = func_00373cb0((f32)*(u16 *)(state + 6), 0.0f, 30.0f, 0);
    if (((*(u16 *)state & 4) != 0) || ((*(u16 *)state & 8) != 0)) {
        f32 t108;
        f32 inv;
        u8 r0;
        u8 g0;
        u8 b0;
        s32 col0;
        f32 x0;
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        t108 = blend * 108.0f;
        inv = 1.0f - blend;
        r0 = (u8)(inv * 255.0f + t108);
        g0 = (u8)(inv * 32.0f + t108);
        b0 = (u8)(inv * 26.0f + t108);
        col0 = (r0 << 24) | (g0 << 16) | (b0 << 8);
        x0 = 603.0f - 20.0f * var_f29;
        position.x = x0;
        position.y = 224.0f;
        {
            func_00364fb0(position, 0.0f, col0 | 0xFF, fGpffff8374, 0, 0);
        }
        position.x = 56.0f + 20.0f * var_f29;
        position.y = 224.0f;
        {
            func_00364fb0(position, 0.0f, col0 | 0xFF, fGpffff83cc, 0, 0);
        }
        {
            u8 a1;
            s32 col1;
            f32 xa;
            f32 xb;
            a1 = (u8)(255.0f - 102.0f * var_f29);
            col1 = col0 | a1;
            xa = 603.0f - 20.0f * var_f23 - 30.0f * var_f29;
            xb = 56.0f + 20.0f * var_f23 + 30.0f * var_f29;
            position.x = xa;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col1, fGpffff8374, 0, 0);
            }
            position.x = xb;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col1, fGpffff83cc, 0, 0);
            }
        }
        {
            u8 a2;
            s32 col2;
            f32 xa;
            f32 xb;
            a2 = (u8)(153.0f - 51.0f * var_f29);
            col2 = col0 | a2;
            xa = 603.0f - 50.0f * var_f23 - 40.0f * var_f29;
            xb = 56.0f + 50.0f * var_f23 + 40.0f * var_f29;
            position.x = xa;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col2, fGpffff8374, 0, 0);
            }
            position.x = xb;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col2, fGpffff83cc, 0, 0);
            }
        }
        {
            u8 a3;
            s32 col3;
            f32 xa;
            f32 xb;
            a3 = (u8)(102.0f - 102.0f * var_f29);
            col3 = col0 | a3;
            xa = 603.0f - 90.0f * var_f23 - 50.0f * var_f29;
            xb = 56.0f + 90.0f * var_f23 + 50.0f * var_f29;
            position.x = xa;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col3, fGpffff8374, 0, 0);
            }
            position.x = xb;
            position.y = 224.0f;
            {
                func_00364fb0(position, 0.0f, col3, fGpffff83cc, 0, 0);
            }
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    {
        f32 inv2;
        u8 r1;
        u8 g1;
        u8 b1;
        s32 col4;
        f32 d1;
        inv2 = 1.0f - blend;
        r1 = (u8)(inv2 * 74.0f);
        g1 = (u8)(inv2 * 36.0f);
        b1 = (u8)(inv2 * 0.0f);
        col4 = (r1 << 24) | (g1 << 16) | (b1 << 8) | 0xFF;
        d1 = var_f25 * 300.0f;
        position.x = 603.0f - d1;
        position.y = 224.0f - d1;
        {
            func_00364fb0(position, 0.0f, col4, fGpffff8374, 0, 1);
        }
        position.x = 56.0f + d1;
        position.y = 224.0f + d1;
        {
            func_00364fb0(position, 0.0f, col4, fGpffff83cc, 0, 1);
        }
    }
    {
        f32 inv3;
        u8 cr;
        u8 cg;
        u8 cb;
        f32 d2;
        inv3 = 1.0f - blend;
        cr = (u8)(inv3 * 255.0f + blend * 255.0f);
        cg = (u8)(inv3 * 218.0f + blend * 70.0f);
        cb = (u8)(inv3 * 136.0f + blend * 80.0f);
        d2 = var_f24 * 300.0f;
        func_0034f4a0(resource, 0x38, 407.0f - d2, 40.0f - d2, 0.0f, cr, cg, cb, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
        func_0034f4a0(resource, 0x39, d2 + 103.0f, d2 + 186.0f, 0.0f, cr, cg, cb, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    *(u16 *)(state + 4) = (*(u16 *)(state + 4) + 1) % 10;
    {
        s32 i;
        u8 alpha0;
        alpha0 = (u8)(255.0f - blend * 30.0f);
        for (i = 0; i < 15; i++) {
            u8 *entry;
            f32 fx;
            f32 fy;
            f32 ff;
            f32 s;
            f32 t;
            f32 af;
            s32 alpha;
            entry = D_0064ED30 + i * 12;
            fx = *(f32 *)entry;
            fy = *(f32 *)(entry + 4);
            ff = *(f32 *)(entry + 8);
            s = sinf((fGpffff81e0 * (ff * 10.0f + (f32)*(u16 *)(state + 4))) / 10.0f);
            t = (s + 1.0f) / 2.0f;
            if (*(u16 *)(state + 4) == 0) {
                f32 rnd;
                f32 v;
                rnd = (f32)(u32)(RpRandom() & 0xFFF);
                v = rnd / 4096.0f * 224.0f + 32.0f;
                *(u8 *)(state + 8 + i) = (u8)v;
            }
            af = var_f22 * (f32)*(u8 *)(state + 8 + i) * t;
            alpha = (u8)af;
            func_0034f4a0(resource, 0x3B, fx, fy, 0.0f, 0xFF, alpha0, 0xFF, alpha, 0x1000, 0x1000, 0.0f, 0, 0);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385970);
#endif
/* This helper retains the radius-scale operation with the same operand
 * order as the other circular drawing primitives. */
static inline f32 code38ScaleRadius(f32 value, f32 scale)
{
    return scale * value;
}

/* Native b210 O2: 2228/2240 bytes, 27 resolved relocations, 12 zero tail
 * bytes. Entry/exit radius values and sprite opacity keep distinct
 * lifetimes; the final alpha is converted once at the byte provider.
 * See docs/probe_archive/Menu_shuffle_batch_20260923.md. */
// FUN_00386C00
void func_00386c00(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    extern f32 sinf(f32 fparg0);
    extern f32 fGpffff812c;
    extern f32 fGpffff83d0;
    extern f32 fGpffff837c;
    extern f32 fGpffff81e0;
    extern u8 D_0064EDF0[];
    u8 *base;
    u8 *state;
    s32 resource;
    Vec2f pos;
    f32 innerAngleScale;
    f32 cornerScale;
    f32 outerRadius;
    f32 innerRadius;
    f32 particleOpacity;
    f32 outerAngle;
    f32 innerAngle;
    f32 cornerDisplacement;
    state = arg0 + 4;
    base = *(u8 **)arg0;
    resource = *(s32 *)(base + 0x1F2AC);
    if ((*(u16 *)state & 1) == 0) {
        f32 overshootWeight;
        outerRadius = func_00373cb0((f32)*(u16 *)(state + 2), 10.0f, 20.0f, 2);
        innerRadius = func_00373cb0((f32)*(u16 *)(state + 2), 10.0f, 20.0f, 2);
        cornerScale = func_00373cb0((f32)*(u16 *)(state + 2), 19.0f, 21.0f, 2);
        overshootWeight = fGpffff83d0;
        cornerScale = fGpffff812c * func_00373cb0((f32)*(u16 *)(state + 2), 14.0f, 19.0f, 1)
                  - overshootWeight * cornerScale;
        particleOpacity = func_00373cb0((f32)*(u16 *)(state + 2), 13.0f, 20.0f, 1);
        innerAngleScale = innerRadius;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0x1C) {
            } else {
                *(u16 *)state = *(u16 *)state | 1;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if (*(u16 *)state & 2) {
        f32 t0;
        f32 t1;
        f32 t2;
        t0 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 13.0f, 2);
        outerRadius = (0.0f + 1.0f) + 3.0f * t0;
        t1 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 13.0f, 2);
        innerRadius = (0.0f + 1.0f) + 3.0f * t1;
        t2 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 2);
        cornerScale = (0.0f + 1.0f) + 2.0f * t2;
        particleOpacity = 1.0f - func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        innerAngleScale = innerRadius;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0x14) {
            } else {
                *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFFD;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else {
        outerRadius = 1.0f;
        innerRadius = outerRadius;
        innerAngleScale = outerRadius;
        cornerScale = outerRadius;
        particleOpacity = outerRadius;
    }
    pos.x = 316.0f;
    pos.y = 211.0f;
    if (outerRadius > 0.0f) {
        outerAngle = fGpffff837c * (1.0f + outerRadius);
        outerRadius = code38ScaleRadius(outerRadius, 111.5f);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        func_00365ac0(pos, 0.0f, 0xAE545AFF, outerAngle, outerRadius, 92.0f, 0);
    }
    if (innerRadius > 0.0f) {
        innerAngle = fGpffff837c * (1.0f + innerAngleScale);
        innerRadius = code38ScaleRadius(innerRadius, 98.0f);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        func_00365ac0(pos, 0.0f, 0x4A2400FF, innerAngle, innerRadius, 18.0f, 1);
    }
    cornerDisplacement = (cornerScale - 1.0f) * 300.0f;
    pos.x = (f32)359 + cornerDisplacement;
    pos.y = 14.0f + cornerDisplacement;
    func_0034f4a0(resource, 0x3A, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    pos.x = 119.0f - cornerDisplacement;
    pos.y = 184.0f - cornerDisplacement;
    func_0034f4a0(resource, 0x39, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    *(u16 *)(state + 4) = (*(u16 *)(state + 4) + 1) % 60;
    {
        s32 i;
        for (i = 0; i < 16; i++) {
            u8 *entry;
            f32 ff;
            f32 s;
            f32 t;
            f32 af;
            f32 one;
            f32 two;
            entry = D_0064EDF0 + i * 12;
            ff = *(f32 *)(entry + 8);
            s = sinf((fGpffff81e0 * ((0.0f + (f32)*(u16 *)(state + 4)) + 60.0f * ff)) / 60.0f);
            one = 1.0f;
            t = one + s;
            two = 2.0f;
            t = t / two;
            pos.x = *(f32 *)entry;
            pos.y = *(f32 *)(entry + 4);
            af = (255.0f * (one + t)) / two;
            af *= particleOpacity;
            func_0034f4a0(resource, 0x3C, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF, (u8)af, 0x1000, 0x1000, 0.0f, 0, 0);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
// FUN_003874C0
void func_003874c0(s32 arg0, u8 *arg1)
{
    extern void func_00383c40(u8 *arg0);
    extern void func_00383f80(u8 *arg0);
    extern void func_00383d70(u8 *arg0);
    extern void func_00384cc0(u8 *arg0);
    extern void func_00385380(u8 *arg0);
    extern void func_00385970(u8 *arg0);
    extern void func_00386c00(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    u8 *base;
    u8 *entry;
    s32 value;
    f32 var_f12;
    f32 temp_f1;
    u8 temp_3;
    s32 i;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x200) != 0) {
        base = *(u8 **)arg1;
        entry = arg1 + 0x46;
        value = *(u16 *)entry;
        if (value < 0x23) {
            value = ++*(u16 *)entry;
            var_f12 = (f32)(u16)value;
            temp_f1 = 255.0f *
                func_00373cb0(var_f12, 0.0f, 30.0f, 0);
            temp_3 = (u8)temp_f1;
            *(u8 *)(entry + 5) = temp_3;
        }
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (i = 0; i < *(s32 *)(base + 0x1F234); i++) {
            func_00377930(base,
                          *(s32 *)(base + (i * 4) + 0x1F214),
                          0, entry + 2, 1);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x10) != 0) {
        func_00383c40(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x20) != 0) {
        func_00383f80(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x80) != 0) {
        func_00383d70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x40) != 0) {
        func_00384cc0(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 8) != 0) {
        func_00385380(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 1) != 0) {
        func_00385970(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 2) != 0) {
        func_00386c00(arg1);
    }
}
static inline f32 code38QuarterTurnOffset(s32 index)
{
    extern f32 fGpffff83d8;
    return fGpffff83d8 * (f32)index;
}

// FUN_00387750
void func_00387750(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern f32 sinf(f32 fparg0);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void func_0045c870(void *arg0, s32 arg1);
    extern f32 fGpffff82cc;
    extern f32 fGpffff82fc;
    extern f32 fGpffff83d8;
    u8 *base;
    u8 *state;
    struct { f32 depth; f32 recipZ; f32 phase; } view;
    f32 blend0;
    f32 blend1;
    u8 colors[4];
    BtlShuffleSkyVertex work[4];
    typedef struct {
        s32 (*draw)(s32 primitive, void *vertices, s32 count);
    } Code38PrimitiveDispatch;
    Code38PrimitiveDispatch *dispatch;
    s32 alpha;
    base = *(u8 **)arg0;
    state = arg0 + 0x46;
    view.depth = D_008872F8[0];
    view.recipZ = 1.0f / *(f32 *)(func_00457120() + 0x80);
    *(u16 *)(state + 2) = (*(u16 *)(state + 2) + 1) % 10;
    view.phase = (fGpffff82fc * (f32)*(u16 *)(state + 2)) / 10.0f;
    if ((*(u16 *)(state + 4) & 1) == 0) {
        blend0 = func_00373cb0((f32)*(u16 *)state, 0.0f, 15.0f, 0);
        blend1 = 0.0f;
        {
            if (++*(u16 *)state >= 0xF) {
                *(u16 *)state = 0;
                *(u16 *)(state + 4) = *(u16 *)(state + 4) | 1;
            }
        }
    } else if (*(u16 *)(state + 4) & 2) {
        blend0 = 1.0f - func_00373cb0((f32)*(u16 *)state, 0.0f, 28.0f, 0);
        blend1 = func_00373cb0((f32)*(u16 *)state, 0.0f, 30.0f, 0);
        {
            if (++*(u16 *)state >= 0x23) {
                *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFBFF;
                func_00389180(*(u8 **)(base + 0x1F294));
            }
        }
    } else {
        blend0 = 1.0f;
        blend1 = 0.0f;
    }
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = (u8)(255.0f * (fGpffff82cc * blend0 + blend1));
    func_00377930(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0;
    func_00489f80();
    RpSkyRenderStateSet(3, (void *)0x31801);
    func_0045c870(colors, 0);
    colors[3] = 0xFF;
    func_00377930(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    func_0048a000();
    RpSkyRenderStateSet(3, (void *)0x3F801);
    RpSkyRenderStateSet(2, (void *)0x48);
    {
        s32 i;
        for (i = 0; i < 4; i++) {
            f32 ang;
            f32 y;
            f32 x;
            BtlShuffleSkyVertex *vertex;
            alpha = (u8)(255.0f * ((f32)(i & 1) * blend0));
            {
                f32 offset;
                offset = code38QuarterTurnOffset(i);
                ang = view.phase + offset;
            }
            y = (0.0f + 211.0f) + 192.0f * sinf(ang);
            x = (0.0f + 316.0f) + 192.0f * cosf(ang);
            vertex = &work[i];
            vertex->u.els.scrVertex.x = x;
            vertex->u.els.scrVertex.y = y;
            vertex->u.els.scrVertex.z = view.depth;
            vertex->u.els.color.r = 255.0f;
            vertex->u.els.color.g = 0.0f;
            vertex->u.els.color.b = 0.0f;
            vertex->u.els.color.a = (f32)(u32)alpha;
            vertex->u.els.recipZ = view.recipZ;
        }
    }
    dispatch = (Code38PrimitiveDispatch *)D_00887310;
    dispatch->draw(5, work, 4);
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            f32 ang;
            f32 y;
            f32 x;
            BtlShuffleSkyVertex *vertex;
            f32 edgeAlpha;
            edgeAlpha = fGpffff82cc * (f32)(j & 1);
            edgeAlpha *= blend0;
            alpha = (u8)(255.0f * edgeAlpha);
            {
                f32 offset;
                offset = code38QuarterTurnOffset(j);
                ang = view.phase + offset;
            }
            y = (0.0f + 211.0f) + 192.0f * sinf(ang);
            x = (0.0f + 316.0f) + 192.0f * cosf(ang);
            vertex = &work[j];
            vertex->u.els.scrVertex.x = x;
            vertex->u.els.scrVertex.y = y;
            vertex->u.els.scrVertex.z = view.depth;
            vertex->u.els.color.r = 255.0f;
            vertex->u.els.color.g = 0.0f;
            vertex->u.els.color.b = 0.0f;
            vertex->u.els.color.a = (f32)(u32)alpha;
            vertex->u.els.recipZ = view.recipZ;
        }
    }
    dispatch->draw(5, work, 4);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* measured: honest first reconstruction per func_0038bab0/89640/84cc0/87750 idiom (u8* base/outer/state at +0x18, s32 resource/han0/han1, (f32)(s32) counters, plain (u8) clamps, sequential guards empty else, block-scoped idx/yoff, plain arithmetic no COP1 exemption, s64 pos via sp68/sp6C packing per bab0; m2c+romwright into /var/tmp/cold387e70 (m2c 248 lines + rom 210 lines + raw 192 lines, arity 1 pointer trusted); probe_variants v1 667 base, v2 649 (-18 &han0==0 per micro_addr), v3 644 (-5 secX stacking), pragmas tie, v_sub 653 regress, v_swap tie, v4 s32 colors 643 but 693 outside gate not adopted, v5 switch 660 regress, v6 branch flip 656 regress, v7 for tie; stop after two non-improving rounds per batch; fnalign v3c retail 719/object 698 (21 short 2.9% within 3%, 626 edits +6 reloc-only, frame 0x100, $s/$f color + GP offsets + COP1 mula/msub/adda/madd + sq/lq floor remain); providers verified (46a770 s32(void*) per cmpSystem, 10b5b0 s32(void) per cmpPersona, 109220 u8*(u16) per this file:19, 109280 u8(s32) per code1_0010, 109390 s32(s32) per datCalc, 275020 per frFontEx, 364c90 s64 per bab0, 34f460/34f4a0/46d730/D_0064EEB0 file-scope, D_005E5810/5850 u8[] per cmpMain, fGp83dc/83b0 f32 per image, jal 22==22); Ghidra/IDA agree on CFG/switch/call order, differ on 364c90/275020 prototypes and GP naming (used file idiom); lever 4 N/A (float, no slti); lhu correct; double-def offset remains + COP1 chains; re-derived, no fabrications; archive P038_00387e70_body.c stale placeholder. Banked guarded floor. */
/* 2026-09-20 deficit probe: baseline 654w/626e retail 719/object 698 (2.9% 21 short, frame 0x100 vs 0x110); 7o grep: no `Type x =` inits, already bare decls + statement assigns so exchange-8 skipped per 7o (perm 18/other 62, 7o N/A); float-cascade 12 vars: v1 eased1 explicit-else 650 (-4), v2 eased1 t1>1 648 (-6), v3 eased1 !(<=) 654 tie, v4 slot goto-shared 658 (+4), v5 conv direct (u8)m 654 tie, v6 conv recompute (u8)(fGp*eased1)x2 638 (-16 best, 717ins 2 short but 645e), v7 eased0 !(<=) 654 tie, v8 v1+v4+v5 648 (-6), v9 sec array 654 tie, v10 addr-taken 654 tie, v11 ternary 648 (-6), v12 recompute+array 638 tie-best; retail 95:330 (0x387fec-0x388398, 235) vs obj 95:96 = eased1 hoisted (obj bc1f to slot, 1.0 kept in f22) vs explicit-else (retail bc1t to <0-check + mov f21,f2 + b to slot) + slot beq-shared single 0x19 at 880b4 vs bne-duplicate two 0x19 + 1mul+2conv via t1 (m in f22 survives) vs 1mul+1conv via s1 CSE (m in f1 dies) + sec/yoff stack spill (sw/swc1/lwc1+f12) vs regs (f21/f20+mov); delta sw+8/nop+8/b+7/bc1t+5/beq+4/swc1+3/lwc1+3/mfc1+2 matches; pairing not unlocked, floor stays. */
// FUN_00387E70 NONMATCHING
#ifdef NON_MATCHING
void func_00387e70(u8 *arg0)
{
    extern s32 func_0046a770(void *arg0);
    extern s32 func_0010b5b0(void);
    extern u8 func_00109280(u16 arg0);
    extern s32 datPersonaGetLevel(s32 arg0);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern void func_00364c90(s64 pos, s32 color, s32 mode, f32 rotation, f32 width, f32 height, f32 alpha);
    extern u8 D_005E5810[];
    extern u8 D_005E5850[];
    extern f32 fGpffff83dc;
    extern f32 fGpffff83b0;
    u8 *base;
    u8 *outer;
    u8 *state;
    s32 resource;
    s32 han0;
    s32 han1;
    s32 selSum;
    f32 t0;
    f32 eased0;
    f32 t1;
    f32 eased1;
    s32 slot;
    f32 secX;
    f32 secY;
    s32 idx;
    f32 yoff;
    u8 colA;
    u8 colB;
    u8 r;
    u8 g;
    u8 b;
    u8 alpha;
    u8 icon;
    base = *(u8 **)arg0;
    outer = *(u8 **)(base + 0x1F290);
    state = *(u8 **)(outer + 0x38) + 0x18;
    resource = *(s32 *)(base + 0x1F2AC);
    if (&han0 == 0) {
        func_0046d730(D_0064EEB0, 0x50B);
    }
    han0 = func_0046a770(D_005E5810);
    han1 = func_0046a770(D_005E5850);
    selSum = *(s32 *)(state + 4) + *(s32 *)(state + 8);
    t0 = (f32)(*(s32 *)(state + 16) - 12) / 12.0f;
    eased0 = 1.0f;
    if (t0 <= 1.0f) {
        eased0 = 0.0f;
        if (t0 >= 0.0f) {
            eased0 = t0 * 2.0f - t0 * t0;
        }
    }
    if (eased0 != 1.0f) {
        eased1 = 0.0f;
    } else {
        t1 = (f32)(*(s32 *)(state + 16) - 28) / 12.0f;
        eased1 = 1.0f;
        if (t1 <= 1.0f) {
            eased1 = t1;
            if (t1 < 0.0f) {
                eased1 = 0.0f;
            }
        }
        {
            s32 v;
            v = func_0010b5b0() & 0xFFFF;
            if (v == 12) {
                slot = 0x19;
                secX = 154.0f;
                secY = 386.0f;
            } else if (v == 10) {
                slot = 0x3F;
                secX = 154.0f;
                secY = 330.0f;
            } else if (v == 8) {
                slot = 0x3E;
                secX = 154.0f;
                secY = 274.0f;
            } else if (v == 6) {
                slot = 0x3D;
                secX = 154.0f;
                secY = 218.0f;
            } else {
                slot = 0x19;
                secX = 154.0f;
                secY = 386.0f;
            }
        }
        {
            f32 m;
            u8 a0;
            u8 a1;
            m = fGpffff83dc * eased1;
            a0 = (u8)m;
            func_0034f460(resource, slot, secX, 43.0f, 0xEA, 0x7C, 0, a0);
            a1 = (u8)m;
            func_0034f460(resource, 0x1A, secX, secY, 0xEA, 0x7C, 0, a1);
        }
    }
    idx = *(s32 *)(state + 12) - 1;
    yoff = (f32)(idx * 28);
    while (idx >= 0) {
        f32 cur;
        cur = yoff * eased0;
        if ((idx != selSum) || (*(s32 *)(state + 20) != 0)) {
            colA = 0xFF;
            colB = 0x81;
            r = 0xE7;
            g = 0x8C;
            b = 0x20;
        } else {
            colA = 0x2D;
            colB = 0x2D;
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        }
        if (idx == 0) {
            f32 y;
            y = cur + 49.0f;
            func_0034f460(resource, 0x17, 154.0f, y, 0xFF, 0, 0, 0xFF);
            func_0034f460(resource, 0x18, 526.0f, y, 0xFF, 0, 0, 0xFF);
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        }
        if ((idx != 0) || ((selSum == 0) && (*(s32 *)(state + 20) == 0))) {
            f32 y;
            y = cur + 49.0f;
            func_0034f460(resource, 0x15, 154.0f, y, colA, colA, colB, 0xFF);
            func_0034f460(resource, 0x16, 526.0f, y, colA, colA, colB, 0xFF);
        }
        if (idx == 0) {
            alpha = 0xFF;
        } else {
            f32 tt;
            f32 ee;
            tt = (f32)((*(s32 *)(state + 16) - 18) - idx) / 6.0f;
            ee = 1.0f;
            if (tt <= 1.0f) {
                ee = tt;
                if (tt < 0.0f) {
                    ee = 0.0f;
                }
            }
            alpha = (u8)(ee * 255.0f);
            if ((idx == *(s32 *)(state + 12) - 1) && (alpha == 0xFF)) {
                *(s32 *)(state + 20) = 0;
            }
        }
        if (alpha != 0) {
            u8 *entry;
            u16 pid;
            entry = state + idx * 4;
            pid = *(u16 *)(*(u8 **)(entry + 0x4C) + 2);
            icon = func_00109280(pid) & 0xFF;
            if ((icon == 0) || (icon >= 0x20)) {
                func_0046d730(D_0064EEB0, 0x588);
            }
            {
                f32 y;
                s32 islot;
                u8 *str;
                s32 lvl;
                s32 lv;
                y = cur + 55.0f;
                islot = ((icon - 1) & 0xFFFF) + 0x21;
                func_0034f460(han0, islot, 168.0f, y, r, g, b, alpha);
                str = func_00109220(pid);
                {
                    s32 packed;
                    packed = (alpha & 0xFF) | ((b & 0xFF) << 8) | ((r & 0xFF) << 24) | ((g & 0xFF) << 16);
                    func_00275020(269.0f, y - 3.0f, 0.0f, packed, 0, 1, (const char *)str, 0, -1);
                }
                lvl = datPersonaGetLevel(*(s32 *)(entry + 0x4C)) & 0xFF;
                if (lvl >= 100) {
                    lvl = 99;
                }
                lv = lvl & 0xFFFF;
                if (lv >= 10) {
                    func_0034f460(han1, lv / 10 + 0x1D, 471.0f, cur + 58.0f, r, g, b, alpha);
                }
                func_0034f460(han1, lv % 10 + 0x1D, 493.0f, cur + 58.0f, r, g, b, alpha);
            }
        }
        yoff -= 28.0f;
        idx -= 1;
    }
    {
        f32 tt;
        f32 ee;
        f32 temp;
        f32 px;
        f32 py;
        f32 sp68;
        f32 sp6C;
        tt = (f32)*(s32 *)(state + 16) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
        }
        temp = (1.0f - (ee * 2.0f - ee * ee)) * 160.0f;
        px = -116.0f;
        py = 30.0f - temp;
        sp68 = px;
        sp6C = py;
        {
            s64 pos;
            pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
            func_00364c90(pos, 0xFF0000FF, 1, 0.0f, 684.0f, 313.0f, fGpffff83b0);
        }
        px = -132.0f;
        py = 14.0f - temp;
        sp68 = px;
        sp6C = py;
        {
            s64 pos;
            pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
            func_00364c90(pos, 0xFF, 1, 0.0f, 684.0f, 313.0f, fGpffff83b0);
        }
        tt = (f32)(*(s32 *)(state + 16) - 14) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
            if (tt < 0.0f) {
                ee = 0.0f;
            }
        }
        ee = 1.0f - (ee * 2.0f - ee * ee);
        {
            f32 x;
            f32 y;
            x = ee * 200.0f + 6.0f;
            y = 90.0f - ee * 120.0f;
            sp68 = x;
            sp6C = y;
            func_0034f4a0(resource, 0x1C, x, y, 0.0f, 0xFF, 0, 0, 0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        }
        tt = (f32)(*(s32 *)(state + 16) - 6) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
            if (tt < 0.0f) {
                ee = 0.0f;
            }
        }
        ee = 1.0f - (ee * 2.0f - ee * ee);
        func_0034f460(resource, 0x1B, ee * 170.0f + 109.0f, 19.0f - ee * 90.0f, 0xFF, 0xFF, 0xFF, 0xFF);
        if ((*(s32 *)(state + 20) != 0) || (eased1 < 1.0f)) {
            *(s32 *)(state + 16) = *(s32 *)(state + 16) + 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387e70);
#endif
// FUN_003889B0
void func_003889b0(s32 arg0, u8 *arg1)
{
    extern void func_00387750(u8 *arg0);
    extern void func_00387e70(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_0045c870(void *arg0, s32 arg1);
    u8 colors[4];
    f32 temp_f1;
    f32 var_f12;
    u16 *counter;
    u16 temp_3;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x400) != 0) {
        func_00387750(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 4) != 0) {
        func_00387e70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x100) != 0) {
        counter = (u16 *)(arg1 + 0x40);
        colors[0] = *(u8 *)(arg1 + 0x42);
        colors[1] = *(u8 *)(arg1 + 0x43);
        colors[2] = *(u8 *)(arg1 + 0x44);
        var_f12 = (f32)(u16)*counter;
        temp_f1 = 128.0f *
            (1.0f - func_00373cb0(var_f12, 0.0f, 30.0f, 2));
        colors[3] = (u8)temp_f1;
        func_0045c870(colors, 1);
        temp_3 = ++*counter;
        if (temp_3 >= 0x1E) {
            *(u16 *)(arg1 + 0x4C) =
                *(u16 *)(arg1 + 0x4C) & 0xFEFF;
        }
    }
}
// FUN_00388B40
s32 func_00388b40(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    func_00460ac0(D_00795E30, p + 0x50);
    *(s32 *)(p + 0x80) = 0;
    *(s32 *)(p + 0x84) = 0;
    func_00460ac0(D_00795EF0, p + 0x80);
    return 0;
}
// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}

// FUN_00388BD0
u8 *func_00388bd0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064EEB0, 0x63F);
    work = D_008873F4[0](1, 0xB0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064EEB0, 0x640);
    }
    temp = func_00451fc0((void *)(arg0), (const void *)(D_0064ECA0), 0x13, 0, 0, func_00388b40, func_00388ba0, (u8 *)(work));
    if (temp == NULL) {
        func_0046d730(D_0064EEB0, 0x64A);
    }
    *(s32 *)work = func_0036e910(arg0);
    memset(work + 0x50, 0, 0x30);
    memset(work + 0x80, 0, 0x30);
    *(void **)(work + 0x58) = (void *)func_003874c0;
    *(void **)(work + 0x60) = (void *)work;
    *(void **)(work + 0x88) = (void *)func_003889b0;
    *(void **)(work + 0x90) = (void *)work;
    func_00388d10(temp);
    return temp;
}
// FUN_00388D10
void func_00388d10(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = 0;
}
// FUN_00388D20
void func_00388d20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x4;
}

// FUN_00388D40
void func_00388d40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFFB;
}

// FUN_00388D60
void func_00388d60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    memset(p + 4, 0, 6);
    *(u16 *)(p + 0x4C) |= 2;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388DE0
s32 func_00388de0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388E00
void func_00388e00(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x2;
}

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}

// FUN_00388E40
void func_00388e40(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    memset(p + 4, 0, 0x18);
    *(u16 *)(p + 0x4C) |= 1;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388EC0
s32 func_00388ec0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388EE0
void func_00388ee0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x4;
}

// FUN_00388F00
void func_00388f00(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0xA) = 0;
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 0x10;
}
// FUN_00388F20
void func_00388f20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x10;
}

// FUN_00388F40
void func_00388f40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFEF;
}

// FUN_00388F60
void func_00388f60(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    memset(temp_16 + 0x20, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x20);
}

// FUN_00388FB0
void func_00388fb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) | 0x2;
}

// FUN_00388FD0
void func_00388fd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    memset(temp_16 + 0x24, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x40);
}

// FUN_00389020
void func_00389020(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) | 0x4;
}

// FUN_00389040
void func_00389040(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    memset(temp_16 + 0x28, 0, 0x18);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x80);
}

// FUN_00389090
void func_00389090(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = *(s32 *)(p + 0x3C);

    *(s32 *)(p + 0x3C) = n + 1;
    slot = (s32 *)((u32)(n << 2) + (u32)slot);
    slot[1] = arg1;
    if (*(s32 *)(p + 0x3C) > 4) {
        func_0046d730(D_0064EEB0, 0x745);
    }
  }

// FUN_003890F0
void func_003890f0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFF7F;
}

// FUN_00389110
void func_00389110(u8 *arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_3 + 0x1E) = 0;
    *(u16 *)(temp_3 + 0x4C) = (u16) (*(u16 *)(temp_3 + 0x4C) | 8);
    func_0045af60(1, 5, 5, 0);
}

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}

// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}

// FUN_003891B0
void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0x40) = 0;
    *(u8 *)(p + 0x42) = arg1;
    *(u8 *)(p + 0x43) = arg2;
    *(u8 *)(p + 0x44) = arg3;
    *(u16 *)(p + 0x4C) = *(u16 *)(p + 0x4C) | 0x100;
}
// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}

// FUN_00389200
void func_00389200(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_16 = (u8 *)(temp_17 + 0x46);
    memset(temp_16, 0, 6);
    *(s8 *)(temp_16 + 2) = arg1;
    *(s8 *)(temp_16 + 3) = arg2;
    *(s8 *)(temp_16 + 4) = arg3;
    *(u16 *)(temp_17 + 0x4C) = (u16) (*(u16 *)(temp_17 + 0x4C) | 0x200);
}

/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
#pragma opt_rebuildconditionals off
// FUN_00389280
s32 func_00389280(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 flags;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x46);
    flags = *(u16 *)(p + 0x4C);
    if (!(flags & 0x200)) {
        return 1;
    }
    return *field >= 0x23;
}
/* measured: restore conditional rebuilding after this function. */
#pragma opt_rebuildconditionals on
// FUN_003892C0
void func_003892c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFDFF;
}

// FUN_003892E0
void func_003892e0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    memset(temp_16 + 0x46, 0, 6);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x400);
}

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}

// FUN_00389350
void func_00389350(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) | 0x2;
}

// FUN_00389370
void func_00389370(u8 **arg0)
{
    u16 *tick;
    s32 palette;
    u16 phase;
    f32 t;
    f32 value0;
    f32 q0;
    f32 q1;
    f32 size0_f;
    f32 size1_f;
    s32 size0;
    s32 size1;

    tick = (u16 *)((u8 *)arg0 + 0x68);
    palette = *(s32 *)(*arg0 + 0x1F2B0);

    *tick += 1;
    if (*tick >= 0x320) {
        *tick = 0;
    }

    phase = (u16)(*tick % 100);
    if (phase < 50) {
        t = (f32)phase;
        value0 = 1.0f - cosf((D_00761470 * t) / 50.0f);
    } else {
        t = (f32)(phase - 50);
        value0 = cosf((D_00761470 * t) / 50.0f);
    }

    if (value0 < 0.0f) {
        value0 = 0.0f;
    }

    q0 = (0.0f + 644.0f + 584.0f * value0) / 254.0f;
    q1 = (0.0f + 454.0f + 404.0f * value0) / 254.0f;

    size0_f = 127.0f * q0;
    size1_f = 127.0f * q1;

    size0 = (s32)size0_f;
    size1 = (s32)size1_f;

    {
        func_0034f4a0(palette, 0, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                      0xFF, 0xFF, 0xFF, (u8)0xFF,
                      (u16)(4096.0f * q0), (u16)(4096.0f * q1),
                      0.0f, (s16)size0, (s16)size1);
    }
}
/* Animate four sprites with interpolated colors and rotated pixel offsets.
   The timer and random samples are snapshots; angle division precedes
   multiplication, and the second sine result is converted to a signed
   pixel offset after scaling. Opacity crosses the sprite API as a byte. */
// FUN_00389640
void func_00389640(u8 **arg0)
{
    extern u32 RpRandom(void);
    extern f32 sinf(f32 fparg0);
    extern f32 D_007613EC;
    extern f32 fGpffff82cc;
    extern f32 fGpffff8170;
    extern f32 fGpffff8218;
    u8 *base;
    s32 palette;
    s32 slot;
    s32 i;
    u16 *tickp;
    base = (u8 *)arg0 + 0x6C;
    palette = *(s32 *)(*arg0 + 0x1F2B0);
    tickp = (u16 *)base;
    if ((*tickp % 80) == 0) {
        slot = *tickp / 80;
        if (slot >= 4) {
            func_0046d730(D_0064F0E0, 0xEB);
        }
        {
            u8 *entry;
            u32 rnd;
            f32 ratio;
            entry = base + slot * 12 + 4;
            *(u16 *)entry = 0;
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(u16 *)(entry + 2) = (u16)(200.0f * ((0.0f + fGpffff8170) + fGpffff82cc * ratio));
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(u8 *)(entry + 4) = (u8)(255.0f * ((0.0f + fGpffff8218) + fGpffff8218 * ratio));
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(f32 *)(entry + 8) = 40.0f * ratio - 20.0f;
        }
    }
    *tickp += 1;
    if (*tickp >= 0x140) {
        *tickp = 0;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (i = 0; i < 4; i++) {
        u8 *entry;
        u16 counter;
        u16 limit;
        entry = base + i * 12 + 4;
        limit = *(u16 *)(entry + 2);
        counter = *(u16 *)entry;
        if (counter <= limit) {
            f32 fnext;
            f32 flimit;
            f32 s;
            f32 inv;
            f32 q0;
            f32 q1;
            f32 size0_f;
            f32 size1_f;
            f32 eased;
            fnext = (f32)(u32)(++*(u16 *)entry);
            flimit = (f32)limit;
            s = sinf(D_00761470 * (fnext / flimit));
            inv = 1.0f - s;
            q0 = ((0.0f + 992.0f) + (f32)1218 * inv) / 254.0f;
            q1 = ((0.0f + 696.0f) + (f32)854 * inv) / 254.0f;
            size0_f = 127.0f * q0;
            size1_f = 127.0f * q1;
            eased = sinf(D_007613EC * inv);
            if (eased < 0.0f) {
                eased = 0.0f;
            }
            func_0034f4a0(palette, 1, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                          0xFF, 0xAE, 0x49, (u8)((f32)(u32)*(u8 *)(entry + 4) * eased),
                          (u16)(4096.0f * q0), (u16)(4096.0f * q1),
                          *(f32 *)(entry + 8), (s16)(s32)size0_f, (s16)(s32)size1_f);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
#pragma opt_loop_invariants on
// FUN_00389CB0
void func_00389cb0(u8 *arg0)
{
    u8 *dst;
    s32 i;
    f32 scale300;
    f32 scale20;
    f32 temp;

    dst = arg0 + 0xA0;
    i = 0;
    scale300 = 300.0f;
    scale20 = 20.0f;
    for (; i < 4; i++) {
        u8 *s;
        u8 *d;
        d = dst + i * 0x30 + 4;
        s = D_0064EEF0 + i * 0x30;
        *(f32 *)(d + 0) = *(f32 *)(s + 0);
        *(f32 *)(d + 4) = *(f32 *)(s + 4);
        *(f32 *)(d + 0x10) = *(f32 *)(s + 8);
        *(f32 *)(d + 0x14) = *(f32 *)(s + 0xC);
        *(f32 *)(d + 8) = *(f32 *)(s + 0x10);
        *(f32 *)(d + 0xC) = *(f32 *)(s + 0x14);
        *(f32 *)(d + 0x18) = *(f32 *)(s + 0x18);
        *(f32 *)(d + 0x1C) = *(f32 *)(s + 0x1C);
        temp = scale300 * *(f32 *)(s + 0x20);
        *(u16 *)(d + 0x24) = (u16)temp;
        temp = scale300 * *(f32 *)(s + 0x24);
        *(u16 *)(d + 0x26) = (u16)temp;
        *(f32 *)(d + 0x28) = scale20 * *(f32 *)(s + 0x28);
        *(u8 *)(d + 0x2C) = *(u8 *)(s + 0x2C);
        *(u8 *)(d + 0x2D) = *(u8 *)(s + 0x2D);
        *(u8 *)(d + 0x2E) = *(u8 *)(s + 0x2E);
        *(u8 *)(d + 0x2F) = *(u8 *)(s + 0x2F);
    }
}
/* measured: restore loop-invariant optimization after func_00389cb0. */
#pragma opt_loop_invariants off
typedef union Code38WavePhase {
    Vec2f direction[2];
    Vec2f pair[2];
} Code38WavePhase;

typedef struct Code38WaveWorkspace {
    Vec2f normal[2];
    Code38WavePhase phase;
    BtlShuffleSkyVertex vertices[62];
    /* Retail leaves sp+0x1030..0x1037 unused; this layout places delta at sp+0x1038. */
    u32 pad[2];
    Vec2f delta;
} Code38WaveWorkspace;

/* Native b210 O2: 1488/1488 bytes, 26 resolved relocations. The
 * 62-vertex workspace preserves the original allocation and vector
 * lifetimes. Its explicit gap has no read or written value.
 * See docs/probe_archive/Shuffle_wave_00389e10_20260923.md. */
// FUN_00389E10
void func_00389e10(u8 **arg0)
{
    extern f32 D_007612D0;
    extern f32 D_007613EC;
    extern f32 sinf(f32);
    extern f32 func_003e41e0(Vec2f *out, const Vec2f *in);
    extern f32 RwV2dLength(const Vec2f *value);
    s32 outer;
    s32 j;
    s32 m;
    s32 idx;
    s32 half;
    s32 found;
    u8 *raw;
    u8 *entry;
    f32 scale;
    f32 z;
    Code38WaveWorkspace work;

    raw = (u8 *)arg0 + 0xA0;
    z = D_008872F8[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    D_00887300[0]((RwRenderState)1, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (outer = 0; outer < 4; outer++) {
        entry = raw + outer * 0x30 + 4;
        if (outer == 2) {
            RpSkyRenderStateSet(3, (void *)0x717FB);
            RpSkyRenderStateSet(2, (void *)0x44);
        }
        for (j = 0; j < 2; j++) {
            u16 *cnt;
            u16 *max;
            f32 *fp;
            Vec2f *direction;
            Vec2f *normal;
            cnt = (u16 *)(entry + j * 2 + 0x20);
            max = (u16 *)(entry + j * 2 + 0x24);
            *cnt = *cnt + 1;
            if (*cnt >= *max) {
                *cnt = 0;
            }
            fp = (f32 *)(entry + j * 8);
            direction = &work.phase.direction[j];
            direction->x = fp[4] - fp[0];
            direction->y = fp[5] - fp[1];
            normal = &((Vec2f *)&work.normal)[j];
            normal->x = -direction->y;
            normal->y = direction->x;
            func_003e41e0(normal, normal);
        }
        {
            s32 k;
            for (k = 0; k < 62; k++) {
                f32 cntf;
                f32 maxf;
                f32 ratio;
                f32 ang;
                f32 w;
                f32 *inp;
                Vec2f *direction;
                Vec2f *normal;
                BtlShuffleSkyVertex *vertex;
                f32 fraction;
                f32 offsetX;
                f32 offsetY;
                f32 productX;
                f32 productY;
                f32 rx;
                f32 ry;
                f32 baseX;
                f32 baseY;
                u8 alpha;
                u8 blue;
                u8 green;
                u8 red;
                idx = k % 2;
                half = k / 2;
                cntf = (f32)*(u16 *)(entry + idx * 2 + 0x20);
                maxf = (f32)*(u16 *)(entry + idx * 2 + 0x24);
                ratio = cntf / maxf;
                ang = D_007612D0 * ratio + D_007613EC * (f32)half / 30.0f;
                w = *(f32 *)(entry + 0x28) * sinf(ang);
                direction = &work.phase.direction[idx];
                fraction = (f32)half / 30.0f;
                offsetX = fraction * direction->x;
                offsetY = fraction * direction->y;
                productX = offsetX;
                productY = offsetY;
                inp = (f32 *)(entry + idx * 8);
                ry = productY + inp[1];
                rx = productX + inp[0];
                baseX = rx;
                baseY = ry;
                normal = &((Vec2f *)&work.normal)[idx];
                baseX = (0.0f + baseX) + w * normal->x;
                baseY = (0.0f + baseY) + w * normal->y;
                alpha = *(u8 *)(entry + 0x2F);
                blue = *(u8 *)(entry + 0x2E);
                green = *(u8 *)(entry + 0x2D);
                red = *(u8 *)(entry + 0x2C);
                vertex = &work.vertices[k];
                vertex->u.els.scrVertex.x = baseX;
                vertex->u.els.scrVertex.y = baseY;
                vertex->u.els.scrVertex.z = z;
                vertex->u.els.color.r = (f32)red;
                vertex->u.els.color.g = (f32)green;
                vertex->u.els.color.b = (f32)blue;
                vertex->u.els.color.a = (f32)alpha;
                vertex->u.els.recipZ = scale;
            }
        }
        if (outer < 2) {
            found = 0;
            for (m = 0; m <= 30; m++) {
                BtlShuffleSkyVertex *pair;
                pair = &((BtlShuffleSkyVertex *)&work.vertices)[m * 2];
                work.phase.pair[0].x = pair[0].u.els.scrVertex.x;
                work.phase.pair[0].y = pair[0].u.els.scrVertex.y;
                work.phase.pair[1].x = pair[1].u.els.scrVertex.x;
                work.phase.pair[1].y = pair[1].u.els.scrVertex.y;
                work.delta.x = work.phase.pair[0].x - work.phase.pair[1].x;
                work.delta.y = work.phase.pair[0].y - work.phase.pair[1].y;
                if (RwV2dLength(&work.delta) > 1.0f) {
                    found = 1;
                    break;
                }
            }
        }
        func_00364c50();
        if (outer < 2) {
            if (found != 0) {
                RpSkyRenderStateSet(3, (void *)0x71801);
                RpSkyRenderStateSet(2, (void *)0x42);
            }
            D_00887310[0](2, work.vertices, 62);
            if (found != 0) {
                RpSkyRenderStateSet(3, (void *)0x71801);
                RpSkyRenderStateSet(2, (void *)0x48);
            }
        }
        D_00887310[0](4, work.vertices, 62);
        func_00364c70();
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
// FUN_0038A3E0
void func_0038a3e0(u8 *arg0)
{
    u8 *temp_16;

    arg0 += 0x168;
    temp_16 = (u8 *)add_offset_first_0038(4, (u32)arg0);
    memset(arg0, 0, 0x28);
    *(s16 *)temp_16 = 0;
    *(f32 *)(temp_16 + 0x10) = (f32)0x13D;
    *(s32 *)(temp_16 + 0x14) = 0x43880000;
    *(s32 *)(temp_16 + 0x18) = 0x3F800000;
    *(s32 *)(temp_16 + 0x1C) = 0x3E800000;
    *(s32 *)(temp_16 + 4) = 0x43330000;
    *(s32 *)(temp_16 + 8) = 0x43610000;
    *(u8 *)(temp_16 + 0x20) = 0xD7;
    *(u8 *)(temp_16 + 0x21) = 0x84;
    *(u8 *)(temp_16 + 0x22) = 0x15;
    *(u8 *)(temp_16 + 0x23) = 0xFF;
}
/* Ring samples use complete three-component vectors and two vertices per
 * sample. The 65 samples occupy the entire 130-vertex buffer. */
typedef struct Code38RingVertex {
    f32 x, y, z;
    u32 pad0, pad1, pad2;
    f32 reciprocalZ;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Code38RingVertex;

static inline void code38RingVertex(Code38RingVertex *vertex,
    f32 x, f32 y, f32 depth, f32 reciprocalZ, u32 r, u32 g, u32 b, u32 a)
{
    vertex->x = x;
    vertex->y = y;
    vertex->z = depth;
    vertex->color[0] = (f32)r;
    vertex->color[1] = (f32)g;
    vertex->color[2] = (f32)b;
    vertex->color[3] = (f32)a;
    vertex->reciprocalZ = reciprocalZ;
}

/* Native b210 O2: 1204/1216 bytes, 19 resolved relocations, 12 zero tail bytes. */
// FUN_0038A480
void func_0038a480(u8 *arg0)
{
    extern BtlShuffleMatrix *func_003e0f80(void);
    extern BtlShuffleMatrix *RwMatrixRotate(BtlShuffleMatrix *, const BtlShuffleVec3 *, f32, BtlShuffleCombine);
    extern BtlShuffleVec3 *func_003e42a0(BtlShuffleVec3 *, const BtlShuffleVec3 *, const BtlShuffleMatrix *);
    extern s32 func_003e0f40(BtlShuffleMatrix *);
    extern f32 sinf(f32);
    extern f32 cosf(f32);
    extern f32 iGpffff81e0;
    Code38RingVertex vertices[130];
    BtlShuffleVec3 position;
    BtlShuffleVec3 axis;
    f32 angle;
    f32 depth;
    f32 reciprocalZ;
    f32 displacement;
    f32 blend;
    f32 nearRadius;
    f32 farRadius;
    BtlShuffleMatrix *matrix;
    s32 i;
    s32 count;

    depth = D_008872F8[0];
    reciprocalZ = 1.0f / *(f32 *)(func_00457120() + 0x80);
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    blend = *(f32 *)(arg0 + 0x1C);
    nearRadius = *(f32 *)(arg0 + 4);
    farRadius = *(f32 *)(arg0 + 8);
    displacement = (1.0f - blend * blend) * (farRadius * blend - nearRadius * blend);
    matrix = func_003e0f80();
    RwMatrixRotate(matrix, &axis, *(f32 *)(arg0 + 0xC), rwCOMBINEREPLACE);
    i = 0;
    count = 0;
    for (; i <= 64; i++) {
        f32 negativeSine;
        angle = (iGpffff81e0 * (f32)i) / 64.0f;
        negativeSine = sinf(angle);
        angle = cosf(angle);
        negativeSine = -negativeSine;
        position.x = negativeSine * *(f32 *)(arg0 + 0x18);
        position.y = angle * *(f32 *)(arg0 + 0x1C);
        position.z = 0.0f;
        func_003e42a0(&position, &position, matrix);
        code38RingVertex(&vertices[count++],
            (0.0f + *(f32 *)(arg0 + 0x10)) + position.x * *(f32 *)(arg0 + 8),
            (0.0f + *(f32 *)(arg0 + 0x14)) + position.y * *(f32 *)(arg0 + 8),
            depth, reciprocalZ, *(u8 *)(arg0 + 0x20), *(u8 *)(arg0 + 0x21),
            *(u8 *)(arg0 + 0x22), *(u8 *)(arg0 + 0x23));
        position.x = negativeSine * *(f32 *)(arg0 + 0x18);
        position.y = angle * *(f32 *)(arg0 + 0x1C);
        position.z = 0.0f;
        func_003e42a0(&position, &position, matrix);
        code38RingVertex(&vertices[count++],
            (0.0f + *(f32 *)(arg0 + 0x10)) + position.x * *(f32 *)(arg0 + 4),
            ((0.0f + *(f32 *)(arg0 + 0x14)) + position.y * *(f32 *)(arg0 + 4)) - displacement,
            depth, reciprocalZ, *(u8 *)(arg0 + 0x20), *(u8 *)(arg0 + 0x21),
            *(u8 *)(arg0 + 0x22), *(u8 *)(arg0 + 0x23));
    }
    if (count <= 130) {
    } else {
        func_0046d730(D_0064F0E0, 0x21E);
    }
    func_003e0f40(matrix);
    D_00887300[0]((RwRenderState)1, (void *)0);
    func_00364c50();
    D_00887310[0](4, vertices, count);
    func_00364c70();
}
/* Measured: 904/912 bytes, eleven resolved relocations and eight zero
 * alignment bytes. D_00761490 is the retail scalar 0xBD872B00, not the
 * rounded -0.066f literal; keep the five-frame and 300-frame reloads. */
#pragma opt_propagation off
// FUN_0038A940
void func_0038a940(u8 **arg0)
{
    extern f32 D_00761288;
    extern f32 D_00761300;
    extern f32 D_00761490;
    extern f32 D_007612D0;
    extern f32 DAT_007613f8;
    extern f32 func_00373cb0(f32, f32, f32, s32);
    extern f32 sinf(f32);
    extern void func_0038a480(u8 *);
    u8 *state = (u8 *)arg0 + 0x168;
    u8 *work = state + 4;
    u16 flags = *(u16 *)state;
    f32 t;
    if (flags & 1) {
        f32 c10 = 317.0f;
        f32 old10 = *(f32 *)(work + 0x10);
        f32 diff10 = c10 - old10;
        f32 k = D_00761288;
        *(f32 *)(work + 0x10) = k * diff10 + old10;
        {
            f32 old14 = *(f32 *)(work + 0x14);
            f32 diff14 = 212.0f - old14;
            *(f32 *)(work + 0x14) = k * diff14 + old14;
        }
        {
            f32 old18 = *(f32 *)(work + 0x18);
            f32 diff18 = D_00761300 - old18;
            *(f32 *)(work + 0x18) = k * diff18 + old18;
        }
        {
            f32 old1C = *(f32 *)(work + 0x1C);
            f32 diff1C = 1.0f - old1C;
            *(f32 *)(work + 0x1C) = k * diff1C + old1C;
        }
        *(f32 *)(work + 4) += 144.0f - *(f32 *)(work + 4);
        *(f32 *)(work + 8) += 165.0f - *(f32 *)(work + 8);
        {
            f32 old0C = *(f32 *)(work + 0x0C);
            f32 neg0C = -old0C;
            *(f32 *)(work + 0x0C) = k * neg0C + old0C;
        }
    } else if (flags & 2) {
        t = func_00373cb0((f32)*(u16 *)work, 0.0f, 5.0f, 2);
        *(f32 *)(work + 0x10) = (f32)0x13D;
        *(f32 *)(work + 0x14) = 212.0f + 60.0f * t;
        *(f32 *)(work + 0x18) = D_00761300 + D_00761490 * t;
        *(f32 *)(work + 0x1C) = 1.0f + (-0.75f) * t;
        *(f32 *)(work + 4) = 144.0f + 35.0f * t;
        *(f32 *)(work + 8) = 165.0f + 60.0f * t;
        if (++*(u16 *)work >= 5) {
            *(u16 *)state &= (u16)0xFFFD;
            *(u16 *)work = 0;
        }
    } else {
        ++*(u16 *)work;
        if (*(u16 *)work >= 300) {
            *(u16 *)work = 0;
        }
        *(f32 *)(work + 0x1C) = 0.25f + DAT_007613f8 * sinf(D_007612D0 * (f32)*(u16 *)work / 150.0f);
        *(f32 *)(work + 0x0C) = 15.0f * sinf(D_007612D0 * (f32)*(u16 *)work / 300.0f);
    }
    func_0038a480(work);
}
#pragma opt_propagation on
typedef struct Code38RevealWeight {
    f32 value;
} Code38RevealWeight;

#pragma push
#pragma opt_loop_invariants on
// FUN_0038ACD0
void func_0038acd0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern f32 fGpffff83a4;
    extern u8 D_0064F090[];
    Code38RevealWeight factors[5];
    Vec2f point;
    u8 *state;
    u8 *entry;
    s32 span;
    s32 i;
    s32 j;
    s32 k;
    s32 type;
    u16 flags;
    u16 counter;
    f32 tail;
    f32 lower;
    f32 upper;
    f32 elapsed;
    f32 width;
    f32 off;
    f32 half;
    f32 fac;
    f32 distance;

    state = arg0 + 0x1B4;
    type = *(s32 *)(*(u8 **)arg0 + 0x1F2FC);
    switch (type) {
    case 3:
        span = 20;
        lower = 196.0f;
        upper = 320.0f;
        break;
    case 4:
        span = 20;
        lower = 185.0f;
        upper = fGpffff83a4;
        break;
    }
    flags = *(u16 *)(state + 2);
    if ((flags & 1) == 0) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            elapsed = (f32)(u32)*(u16 *)state;
            factors[i].value = func_00373cb0(elapsed, (f32)span * *(f32 *)(entry + 8), (f32)span * *(f32 *)(entry + 0xC), 1);
        }
        elapsed = (f32)(u32)*(u16 *)state;
        tail = func_00373cb0(elapsed, 0.25f * (f32)span, (f32)span, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)(state + 2) |= 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            elapsed = (f32)(u32)*(u16 *)state;
            factors[i].value = 1.0f - func_00373cb0(elapsed, (f32)span * *(f32 *)(entry + 8), (f32)span * *(f32 *)(entry + 0xC), 1);
        }
        elapsed = (f32)(u32)*(u16 *)state;
        tail = 1.0f - func_00373cb0(elapsed, 0.25f * (f32)span, (f32)span, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)(arg0 + 4) &= (u16)0xFFDF;
        }
    } else {
        j = 0;
        for (; j < 5; j++) {
            factors[j].value = 1.0f;
        }
        tail = 1.0f;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    point.y = 224.0f;
    k = 0;
    half = lower / 2.0f;
    for (; k < 5; k++) {
        entry = (u8 *)&factors[k];
        fac = ((Code38RevealWeight *)entry)->value;
        entry = D_0064F090 + k * 0x10;
        width = *(f32 *)(entry + 4) * fac;
        distance = half + *(f32 *)entry;
        off = distance * fac;
        point.x = upper + off;
        func_00364c90(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
        point.x = upper - off;
        func_00364c90(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
    }
    width = lower * tail;
    point.x = upper;
    func_00364c90(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

#pragma pop

// FUN_0038B1C0
void func_0038b1c0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2,
                             s32 arg0);
    extern s32 D_0064EFB0[];
    u8 *base;
    s32 palette;
    s32 i;
    u16 *counter;
    f32 alpha;
    f32 scaled;
    u8 alpha_byte;
    u8 red;
    u8 green;
    u8 blue;
    counter = (u16 *)(arg0 + 0x164);
    base = *(u8 **)arg0;
    palette = *(s32 *)(base + 0x1F2AC);
    if (*counter < 30) {
        ++*counter;
    }
    for (i = 0; i < 11; i++) {
        u8 *entry;
        entry = (u8 *)D_0064EFB0 + i * 0x14;
        if (*counter < *(s32 *)(entry + 8)) {
            alpha = 0.0f;
        } else if (*counter < *(s32 *)(entry + 0xC)) {
            alpha = func_00373cb0(
                (f32)*counter,
                (f32)*(s32 *)(entry + 8),
                (f32)*(s32 *)(entry + 0xC),
                1);
        } else {
            alpha = 1.0f;
        }
        if (i == 5) {
            RpSkyRenderStateSet(3, (void *)0x71801);
            RpSkyRenderStateSet(2, (void *)0x48);
        }
        if (i < 5) {
            red = 0xFF;
            green = 0xBE;
            blue = 0x5A;
            scaled = 206.0f * alpha;
            alpha_byte = (u8)scaled;
        } else {
            red = 0x2B;
            green = 0x26;
            blue = 0x1E;
            scaled = 255.0f * alpha;
            alpha_byte = (u8)scaled;
        }
        func_0034f460(
            palette,
            *(s32 *)((u8 *)D_0064EFB0 + i * 0x14 + 0x10),
            30.0f * (1.0f - alpha) +
                *(f32 *)((u8 *)D_0064EFB0 + i * 0x14) + 0.0f,
            *(f32 *)((u8 *)D_0064EFB0 + i * 0x14 + 4),
            red, green, blue, alpha_byte);
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
// measured: preserve retail argument materialization order
#pragma opt_propagation off
// FUN_0038B490
void func_0038b490(s32 arg0, u8 **arg1)
{
    s32 temp_16;
    func_0034f1e0();
    func_00389370(arg1);
    func_00389640(arg1);
    temp_16 = *(s32 *)(*arg1 + 0x1F2B4);
    func_0034f460(temp_16, 0, 0.0f, 0.0f, 0xDA, 0x8C, 0x17, 0xC0);
    func_00389e10(arg1);
    func_0038a940(arg1);
    func_0038b1c0((u8 *)arg1);
}
// measured: restore propagation default
#pragma opt_propagation on
// FUN_0038B530
void func_0038b530(u8 *arg0, s32 arg1, const Vec2f *arg2)
{
    s32 handle;
    f32 x;
    f32 y;

    handle = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    switch (arg1) {
    case 1:
        func_0034f460(handle, 0x40, 492.0f + arg2->x,
                      407.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 507.0f + arg2->x;
        y = 403.0f + arg2->y;
        func_0034f4a0(handle, 0x41, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 528.0f + arg2->x,
                      416.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + arg2->x;
        y = 414.0f + arg2->y;
        func_0034f4a0(handle, 1, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 2:
        func_0034f460(handle, 6, 528.0f + arg2->x,
                      417.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + arg2->x;
        y = 414.0f + arg2->y;
        func_0034f4a0(handle, 3, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 3:
        func_0034f460(handle, 7, 493.0f + arg2->x,
                      361.0f + arg2->y, 0xB4, 0xB4, 0xB4, 0xFF);
        x = 504.0f + arg2->x;
        y = 358.0f + arg2->y;
        func_0034f4a0(handle, 4, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 479.0f + arg2->x,
                      397.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 492.0f + arg2->x;
        y = 394.0f + arg2->y;
        func_0034f4a0(handle, 5, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 4:
        func_0034f460(handle, 0x14, 483.0f + arg2->x,
                      413.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 498.0f + arg2->x;
        y = 410.0f + arg2->y;
        func_0034f4a0(handle, 0x1D, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 528.0f + arg2->x,
                      414.0f + arg2->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 542.0f + arg2->x;
        y = 414.0f + arg2->y;
        func_0034f4a0(handle, 0x13, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    default:
        func_0046d730(D_0064F0E0, 0x3B2);
        break;
    }
}
/* Native b210 O2: 1608/1616 bytes with eight zero alignment bytes.
 * The complete point owns the centered X coordinate before it is retained
 * for the second strip. The detail renderer consumes the same two-float point.
 * See docs/probe_archive/First_party_field_menu_shuffle_20260923.md. */
// FUN_0038BAB0
void func_0038bab0(u8 *arg0)
{
    extern f32 func_00373cb0(f32, f32, f32, s32);
    extern f32 fGpffff83a8;
    extern f32 fGpffff83ac;
    extern f32 fGpffff83b0;
    extern f32 fGpffff83b4;
    extern f32 fGpffff83b8;
    u8 *state;
    u16 flags;
    f32 mainFactor;
    f32 detailEnter;
    f32 detailExit;
    f32 verticalTravel;
    f32 detailX;
    f32 detailY;
    f32 verticalOffset;
    f32 trailingFactor;
    f32 horizontalOffset;
    f32 centerX;
    f32 shiftedY;
    f32 displacement;
    Vec2f point;

    state = arg0 + 0x190;
    flags = *(u16 *)(arg0 + 0x194);
    if (!(flags & 1)) {
        mainFactor = func_00373cb0((f32)(u32)*(u16 *)state, 0.0f, 8.0f, 2);
        trailingFactor = func_00373cb0((f32)(u32)*(u16 *)state, 2.0f, 10.0f, 2);
        if (++*(u16 *)state >= 10) {
            *(u16 *)(state + 4) |= 1;
            *(u16 *)state = 0;
        } else if (*(u16 *)state == 8) {
            *(u16 *)(state + 4) |= 0x10;
        }
    } else if (!(flags & 0x20) && (flags & 4)) {
        mainFactor = 1.0f - func_00373cb0((f32)(u32)*(u16 *)state, 0.0f, 5.0f, 2);
        trailingFactor = 1.0f - func_00373cb0((f32)(u32)*(u16 *)state, 2.0f, 7.0f, 2);
        if (++*(u16 *)state >= 7) {
            *(u16 *)(arg0 + 4) &= 0xFFFE;
        }
    } else {
        mainFactor = 1.0f;
        trailingFactor = mainFactor;
    }

    flags = *(u16 *)(state + 4);
    if (flags & 0x10) {
        if (!(flags & 8)) {
            detailEnter = func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 5.0f, 1);
            if (++*(u16 *)(state + 2) >= 5) {
                *(u16 *)(state + 4) |= 8;
                *(u16 *)(state + 2) = 0;
            }
        } else {
            detailEnter = 1.0f;
        }
        if (*(u16 *)(state + 4) & 0x20) {
            detailExit = func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 5.0f, 1);
            if (++*(u16 *)(state + 2) >= 5) {
                *(u16 *)(state + 4) &= 0xFFDF;
                *(u16 *)(state + 4) &= 0xFFEF;
                *(u16 *)(state + 2) = 0;
            }
        } else {
            detailExit = 0.0f;
        }
    } else {
        detailEnter = 0.0f;
        detailExit = detailEnter;
    }
    if (*(s32 *)(state + 8) == 3) {
        horizontalOffset = 0.0f;
        verticalOffset = -48.0f;
    } else {
        horizontalOffset = 0.0f;
        verticalOffset = horizontalOffset;
    }
    if (*(u16 *)(state + 4) & 2) {
        verticalTravel = 130.0f;
        detailX = 170.0f;
        detailY = -100.0f;
    } else {
        verticalTravel = 100.0f;
        detailX = 120.0f;
        detailY = -70.0f;
    }
    point.x = fGpffff83a8 + (410.0f + horizontalOffset);
    {
        f32 remainder = 1.0f - trailingFactor;
        f32 base = fGpffff83ac + ((f32)517 + verticalOffset);
        point.y = (0.0f + base) + verticalTravel * remainder;
    }
    func_00364c90(point, 0.0f, 0xFF0000FF, 430.0f, 5.0f, fGpffff83b0, 1);
    centerX = 300.0f + horizontalOffset;
    point.x = fGpffff83b4 + centerX;
    centerX = point.x;
    displacement = verticalTravel * (1.0f - mainFactor);
    shiftedY = fGpffff83b8 + ((f32)553 + verticalOffset);
    point.y = shiftedY + displacement;
    func_00364c90(point, 0.0f, 0xFF, 430.0f, 21.0f, fGpffff83b0, 1);
    if (*(u16 *)(state + 4) & 2) {
        point.x = centerX;
        shiftedY = fGpffff83b8 + (524.0f + verticalOffset);
        point.y = shiftedY + displacement;
        func_00364c90(point, 0.0f, 0xFF, 430.0f, 21.0f, fGpffff83b0, 1);
    }
    {
        s32 mode = *(s32 *)(state + 8);
        if (mode) {
            f32 t = (1.0f - detailEnter) - detailExit;
            point.x = detailX * t;
            point.y = detailY * t;
            func_0038b530(arg0, mode, &point);
        }
    }
}
/* Eight-frame count transition; five-frame fade-out. Extent and remainder
 * values preserve the two independently scaled sprite coordinates. */
/* Native b210 O2: 1640/1648 bytes, 12 resolved relocations, eight zero tail bytes. */
// FUN_0038C100
void func_0038c100(u8 *arg0)
{
    extern f32 func_00373cb0(f32, f32, f32, s32);
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 alpha;
    s32 handle;
    f32 scale;
    f32 first;
    f32 scaleY;
    f32 remainderX;
    f32 remainderY;
    f32 extentX;
    f32 extentY;
    f32 drawX;
    f32 drawY;
    u16 flags;
    u16 step;

    state = arg0 + 0x1A4;
    ctx = *(u8 **)arg0;
    handle = *(s32 *)(ctx + 0x1F2AC);
    if (*(s32 *)(ctx + 0x1F2FC) != 3) {
        func_0046d730(D_0064F0E0, 0x44D);
    }
    info = ctx + 0x1F1D0;
    flags = *(u16 *)(state + 2);
    if (!(flags & 1)) {
        scale = func_00373cb0((f32)(u32)*(u16 *)state, 4.0f, 8.0f, 0);
        scaleY = 1.0f;
        alpha = (u8)(255.0f * func_00373cb0((f32)(u32)*(u16 *)state, 0.0f, 8.0f, 1));
        step = ++*(u16 *)state;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) | 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f;
        scaleY = scale;
        alpha = (u8)(255.0f * (1.0f - func_00373cb0((f32)(u32)*(u16 *)state, 0.0f, 5.0f, 1)));
        step = ++*(u16 *)state;
        if (step >= 5) {
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFD;
        }
    } else if (flags & 4) {
        first = func_00373cb0((f32)(u32)*(u16 *)state, 4.0f, 8.0f, 0);
        first = first - func_00373cb0((f32)(u32)*(u16 *)state, 0.0f, 4.0f, 0);
        scaleY = 1.0f;
        scale = scaleY + first;
        alpha = (u8)255.0f;
        step = ++*(u16 *)state;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) & 0xFFFB;
            *(u16 *)state = 0;
        } else if (*(u16 *)state == 4) {
            *(u16 *)(state + 4) = *(u16 *)(info + 8);
        }
    } else {
        scale = 1.0f;
        scaleY = scale;
        alpha = (u8)255.0f;
        if (*(u16 *)(info + 8) != *(u16 *)(state + 4)) {
            *(u16 *)(state + 2) = flags | 4;
        }
    }
    func_0034f460(handle, 0x2B, (f32)578, (f32)417, 0x8E, 0x31, 0, alpha);
    func_0034f460(handle, 0x2A, (f32)543, 408.0f, 0x8E, 0x31, 0, alpha);
    func_0034f460(handle, *(u16 *)(info + 0xA) + 0x1F, (f32)559, 414.0f, 0x8E, 0x31, 0, alpha);
    remainderX = 1.0f - scale;
    extentX = 29.0f;
    drawX = (f32)515 + (remainderX * extentX) / 2.0f;
    remainderY = 1.0f - scaleY;
    extentY = 26.0f;
    drawY = (f32)407 + (remainderY * extentY) / 2.0f;
    func_0034f4a0(handle, (*(u16 *)(info + 0xA) + 0x2D) - *(u16 *)(state + 4), drawX, drawY, 0, 0, 0, 0, alpha, (u16)(4096.0f * scale), (u16)(4096.0f * scaleY), 0.0f, 0, 0);
}
// FUN_0038C770
void func_0038c770(u8 *arg0)
{
    extern void func_00371500(u8 *screen, f32 depth, u8 *point);
    extern s32 func_003717e0(u8 *point, u8 *screen);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 func_00378530(s32 arg0, s32 arg1);
    struct Work {
        BtlShuffleVec3 input;
        f32 pad0;
        f32 out0;
        f32 out1;
        f32 pad1;
        u8 colors[4];
    };
    struct Work work;
    f32 var_f12;
    f32 var_f12_2;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *base;
    s32 count;
    s32 i;

    {
        u8 *state;
        u16 flags;
        u16 value;
        u16 next;

        state = arg0 + 0x1A0;
        base = *(u8 **)arg0;
        count = func_00378530(*(s32 *)(base + 0x1F304),
                              *(s32 *)(base + 0x1F2FC));
        flags = *(u16 *)(state + 2);
        if ((flags & 1) == 0) {
            value = *(u16 *)state;
            var_f12 = (f32)(u16)value;
            temp_f1 = 102.0f *
                func_00373cb0(var_f12, 0.0f, 20.0f, 1);
            work.colors[3] = (u8)temp_f1;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(state + 2) |= 1;
                *(u16 *)state = 0;
            }
        } else if ((flags & 2) != 0) {
            value = *(u16 *)state;
            var_f12_2 = (f32)(u16)value;
            temp_f1_2 = 102.0f *
                (1.0f - func_00373cb0(var_f12_2, 0.0f, 20.0f, 1));
            work.colors[3] = (u8)temp_f1_2;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(arg0 + 4) &= 0xFFFB;
            }
        } else {
            work.colors[3] = 0x66;
        }
    }
    work.colors[0] = 0xDC;
    work.colors[1] = 0x8D;
    work.colors[2] = 0;
    for (i = 0; i < count; i++) {
        {
            u8 *entry;
            entry = base + (i * 0xE8) + 0x1D6B8;
            work.input = *(BtlShuffleVec3 *)entry;
        }
        func_003717e0((u8 *)&work.input, (u8 *)&work.out0);
        work.out0 += 6.0f;
        work.out1 += 5.0f;
        func_00371500((u8 *)&work.out0, work.input.z, (u8 *)&work.input);
        {
            u8 *draw_base;
            s32 draw_index;
            const BtlShuffleVec3 *draw_input;
            u8 *draw_colors;
            s32 draw_mode;
            draw_base = base;
            draw_index = i;
            draw_input = &work.input;
            draw_colors = work.colors;
            draw_mode = 1;
            func_00377930(draw_base, draw_index, draw_input, draw_colors, draw_mode);
        }
    }
}
typedef struct {
    u16 counter;
    u16 pad;
    f32 x;
    f32 z;
    f32 y;
    f32 w;
} State_0038CAB0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    f32 scale;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Vertex_0038CAB0;
// FUN_0038CAB0
void func_0038cab0(u8 *arg0)
{
    u8 *base;
    s32 mode;
    f32 zval;
    f32 inv_scale;
    f32 blend;
    f32 fade;
    f32 xcoord;
    f32 half;
    f32 left;
    f32 right;
    f32 y2;
    Vertex_0038CAB0 work[4];
    State_0038CAB0 *state;

    state = (State_0038CAB0 *)(arg0 + 0x1A0);
    base = *(u8 **)arg0 + 0x1F1D0;
    zval = D_008872F8[0];
    inv_scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    mode = *(u16 *)(base + 4);
    mode = (mode < 3) ? mode : 2;
    if (state->counter < 10) {
        state->counter += 1;
        blend = 1.0f - cosf((D_00761470 * (f32)state->counter) / 10.0f);
    } else {
        blend = 1.0f;
        if (state->w == 0.0f) {
            *(u16 *)(arg0 + 4) &= 0xFFF7;
        }
    }
    state->x = state->x + 0.25f * (207.0f + 107.0f * (f32)mode - state->x);
    state->y += blend * (state->w - state->y);
    fade = state->z;
    xcoord = state->x;
    half = state->y / 2.0f;
    left = xcoord - half;
    work[0].x = left;
    work[0].y = fade;
    work[0].z = zval;
    work[0].color[0] = 224.0f;
    work[0].color[1] = 127.0f;
    work[0].color[2] = 0.0f;
    work[0].color[3] = 255.0f;
    work[0].scale = inv_scale;
    right = xcoord + half;
    work[1].x = right;
    work[1].y = fade;
    work[1].z = zval;
    work[1].color[0] = 224.0f;
    work[1].color[1] = 127.0f;
    work[1].color[2] = 0.0f;
    work[1].color[3] = 255.0f;
    work[1].scale = inv_scale;
    y2 = fade + 448.0f;
    work[2].x = left;
    work[2].y = y2;
    work[2].z = zval;
    work[2].color[0] = 224.0f;
    work[2].color[1] = 127.0f;
    work[2].color[2] = 0.0f;
    work[2].color[3] = 255.0f;
    work[2].scale = inv_scale;
    work[3].x = right;
    work[3].y = y2;
    work[3].z = zval;
    work[3].color[0] = 224.0f;
    work[3].color[1] = 127.0f;
    work[3].color[2] = 0.0f;
    work[3].color[3] = 255.0f;
    work[3].scale = inv_scale;
    D_00887300[0]((RwRenderState)1, (void *)0);
    func_00364c50();
    D_00887310[0](4, &work[0], 4);
    func_00364c70();
}
// FUN_0038CD70
void func_0038cd70(u8 *arg0, u8 *arg1)
{
    u8 *p;

    p = arg1;
    func_0034f1e0();
    if (*(u16 *)(p + 4) & 0x20) {
        func_0038acd0(p);
    }
    if (*(u16 *)(p + 4) & 1) {
        func_0038bab0(p);
    }
    if (*(u16 *)(p + 4) & 2) {
        func_0038c100(p);
    }
    if (*(u16 *)(p + 4) & 4) {
        func_0038c770(p);
    }
    if (*(u16 *)(p + 4) & 8) {
        func_0038cab0(p);
    }
}
// FUN_0038CE30
s32 func_0038ce30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    func_00460ac0(D_00794990, p + 8);
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    func_00460ac0(D_00794E40, p + 0x38);
    return 0;
}

// FUN_0038CE90
void func_0038ce90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0038CEC0
u8 *func_0038cec0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064F0E0, 0x59D);
    work = D_008873F4[0](1, 0x1B8, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064F0E0, 0x59E);
    }
    temp = func_00451fc0((void *)(arg0), (const void *)(D_0064EED0), 0x13, 0, 0, func_0038ce30, func_0038ce90, (u8 *)(work));
    if (temp == NULL) {
        func_0046d730(D_0064F0E0, 0x5A8);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0038a3e0(work);
    func_00389cb0(work);
    memset(work + 8, 0, 0x30);
    *(void **)(work + 0x10) = (void *)func_0038b490;
    *(u8 **)(work + 0x18) = work;
    memset(work + 0x38, 0, 0x30);
    *(void **)(work + 0x40) = (void *)func_0038cd70;
    *(u8 **)(work + 0x48) = work;
    func_0038d020(temp);
    return temp;
}
// FUN_0038D020
void func_0038d020(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x168);
    *(u16 *)(p + 4) = 0;
    value = *field;
    if (value & 1) {
        *field = value & 0xFFFE;
        *field = *field | 2;
        field[2] = 0;
    }
}
// FUN_0038D060
void func_0038d060(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 1;
    memset(p + 0x190, 0, 0x10);
}
// FUN_0038D0A0
void func_0038d0a0(u8 *arg0)
{
    u8 *p;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 0x20;
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 4;
}
// FUN_0038D0D0
void func_0038d0d0(u8 *arg0, s32 arg1)
{
    s32 temp_3_2;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;

    temp_3 = *(u8 **)(arg0 + 0x38);
    temp_4 = temp_3 + 0x190;
    temp_3_2 = *(s32 *)(temp_3 + 0x198);
    if (temp_3_2 != arg1) {
        *(s32 *)(temp_4 + 0xC) = temp_3_2;
        *(s32 *)(temp_4 + 8) = arg1;
        *(s16 *)temp_4 = 0;
        *(s16 *)(temp_4 + 2) = 0;
        *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) & 0xFFF7;
        switch (arg1) {
        case 1:
        case 3:
        case 4:
            var_3 = 1;
            break;
        default:
            var_3 = 0;
            break;
        }
        if (var_3 != 0) {
            *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) | 2;
        }
    }
}
// FUN_0038D160
void func_0038d160(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_17 = (u8 *)(temp_16 + 0x1A4);
    memset(temp_17, 0, 6);
    *(u16 *)(temp_17 + 4) = (u16) *(u16 *)((u8 *)(*(u8 **)(temp_16 + 0)) + 0x1F1D8);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 2);
}

// FUN_0038D1D0
void func_0038d1d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) | 0x2;
}

// FUN_0038D1F0
void func_0038d1f0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    temp_16 = temp_17 + 0x1A0;
    if (*(s32 *)(*(u8 **)temp_17 + 0x1F2FC) != 4) {
        func_0046d730(D_0064F0E0, 0x641);
    }
    *(u16 *)(temp_17 + 4) = *(u16 *)(temp_17 + 4) | 8;
    *(s32 *)(temp_16 + 4) = 0x434F0000;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0x10) = 0x42C40000;
    *(s16 *)temp_16 = 0;
}
// FUN_0038D280
void func_0038d280(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x1B0) = 0;
    *(u16 *)(p + 0x1A0) = 0;
}
// FUN_0038D2A0
void func_0038d2a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) | 0x1;
}

// FUN_0038D2C0
void func_0038d2c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    memset(temp_16 + 0x1B4, 0, 4);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 0x20);
}

// FUN_0038D310
void func_0038d310(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) | 0x2;
}

// FUN_0038D330
void func_0038d330(s32 *raw_arg0)
{
    extern void func_004b1150(s32 arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, s32 arg1);
    extern u8 D_005DC824[];
    extern u8 D_005DC974[];
    extern u8 D_005DC9C8[];
    u8 *arg0;
    u8 *temp_5;
    s32 temp_4;

    arg0 = (u8 *)raw_arg0;
    if (*(u16 *)(arg0 + 4) & 1) {
        temp_5 = (u8 *)(arg0 + 8);
        if (++*(u16 *)(arg0 + 8) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0xC);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0xC) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFE;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 2) {
        temp_5 = (u8 *)(arg0 + 0x10);
        if (++*(u16 *)(arg0 + 0x10) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x14);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x14) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFD;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 4) {
        temp_5 = (u8 *)(arg0 + 0x18);
        if (++*(u16 *)(arg0 + 0x18) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x1C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x1C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFB;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 8) {
        temp_5 = (u8 *)(arg0 + 0x20);
        if (++*(u16 *)(arg0 + 0x20) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x24);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x24) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFF7;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x10) {
        temp_5 = (u8 *)(arg0 + 0x28);
        if (++*(u16 *)(arg0 + 0x28) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x2C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x2C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFEF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x20) {
        temp_5 = (u8 *)(arg0 + 0x30);
        if (++*(u16 *)(arg0 + 0x30) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x34);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x34) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFDF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x40) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x3C));
    }
    if (*(u16 *)(arg0 + 4) & 0x80) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x44));
    }
    if (*(u16 *)(arg0 + 4) & 0x100) {
        func_004b1210(D_005DC824, *(s32 *)(arg0 + 0x4C));
    }
}
// FUN_0038D660
s32 func_0038d660(u8 *arg0) {
    s32 *temp_16;

    temp_16 = (s32 *)(*(s32 **)(arg0 + 0x38));
    func_00374910(*temp_16);
    func_0038d9f0(arg0);
    func_0038d330(temp_16);
    return 0;
}

// FUN_0038DD60
void func_0038dd60(void)
{
}

// FUN_0038DD70
void func_0038dd70(void)
{
}

// FUN_0038DD80
void func_0038dd80(void)
{
}

// FUN_0038DD90
void func_0038dd90(u8 *arg0) {
    s32 i;

    *(s32 *)arg0 = 0;
    arg0[0x122C] = 0xFF;
    arg0[0x122D] = 0xFF;
    arg0[0x122E] = 0xFF;
    arg0[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)(arg0 + i * 0x90 + 4) = 0;
    }
    iGpffffb5b0 = arg0;
}

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !datGetFlag(0x1472);
}

// FUN_0038F400
extern u8 D_0064F240[];
extern void *memcpy(void *dst, const void *src, u32 size);
EffectStateHeader *func_0038f400(const u32 *arg0)
{
    u32 size;
    u32 remainder;
    EffectStateHeader *result;
    u32 cursor;
    u32 string;
    u32 index;
    const u8 *lengths;

    size = sizeof(*result);
    size += arg0[3] * 4;
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[6];
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[2];
    func_0044ea90(D_0064F240, 0x36);
    cursor = (u32)jtbl_008873E8[0](size, 0x40000);
    result = (EffectStateHeader *)cursor;
    cursor += sizeof(*result);
    result->entries = cursor;
    cursor += arg0[3] * 4;
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->strings = cursor;
    cursor += arg0[6];
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->data = cursor;
    result->count = (u16)arg0[3];
    result->id = (u16)arg0[0];
    memcpy((void *)result->strings,
                  (const u8 *)arg0 + arg0[5], arg0[6]);
    memcpy((void *)result->data,
                  (const u8 *)arg0 + arg0[1], arg0[2]);
    lengths = (const u8 *)arg0 + arg0[4];
    string = result->strings;
    index = 0;
    while (index < arg0[3]) {
        size = index * 4;
        *(u32 *)(result->entries + size) = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}
// FUN_0038F590
void func_0038f590(u8 *allocation)
{
    jtbl_008873EC[0](allocation);
}
// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}

#pragma schedule on
#pragma no_branch_likely on
// FUN_0038F990
u8 *func_0038f990(u16 arg0, u16 arg1, f32 *arg2, s32 arg3)
{
    u8 *temp_6;
    s32 temp_16;
    s32 temp_22;
    s32 temp_4;
    s32 var_17;
    u8 *temp_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    s32 fail_words[2];
    temp_16 = arg1 & 0xFFFF;
    var_17 = 0x28;

    if (temp_16 > 0) {
        var_17 += (temp_16 * 0x10) + 0xF;
    }
    goto dispatch_0;

add_0:
    var_17 += ((arg0 & 0xFFFF) * 2) + 1;

alloc_0:
    temp_2 = jtbl_008873E8[0](var_17, 0x3002C);
    if (temp_2 == NULL) {
        goto failure_0;
    }
    *(s32 *)(temp_2 + 0) = arg3;
    temp_6 = temp_2;
    *(u16 *)(temp_2 + 0x1C) = arg0;
    *(u16 *)(temp_2 + 0x1E) = arg1;
    temp_f0 = arg2[0];
    temp_f1 = arg2[1];
    temp_f2 = arg2[2];
    temp_f3 = arg2[3];
    *(f32 *)(temp_2 + 4) = temp_f0;
    *(f32 *)(temp_2 + 8) = temp_f1;
    *(f32 *)(temp_2 + 0xC) = temp_f2;
    *(f32 *)(temp_2 + 0x10) = temp_f3;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x10);
    temp_f0 = temp_f1;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x14);
    *(f32 *)(temp_2 + 0x14) = temp_f0;
    *(f32 *)(temp_2 + 0x18) = temp_f1;
    temp_2 += 0x28;
    if (temp_16 <= 0) {
        goto zero_extra;
    }
    temp_4 = ((s32)(temp_2 + 0xF)) & ~0xF;
    temp_2 = (u8 *)(temp_4 + (temp_16 * 0x10));
    *(s32 *)(temp_6 + 0x20) = temp_4;

pointer_0:
    if (temp_22 != 0) {
        *(s32 *)(temp_6 + 0x24) = ((s32)(temp_2 + 1)) & ~1;
    } else {
        *(s32 *)(temp_6 + 0x24) = 0;
    }
    return temp_6;
dispatch_0:
    temp_22 = arg3 & 1;
    switch (temp_22) {
    case 0:
        goto alloc_0;
    default:
        goto add_0;
    }

failure_0:
    fail_words[0] = 0x11D;
    fail_words[1] = func_003df590(0x80000013, var_17);
    func_003df4d0(fail_words);
    return NULL;
zero_extra:
    *(s32 *)(temp_6 + 0x20) = 0;
    goto pointer_0;
}
/* measured: closes the bracket opened above func_0038f990, which matches at
   object 372 against the 384-byte window at nd 0 with the float copy-chain
   locals; the explicit off restores the file baseline for what follows. */
#pragma schedule off
#pragma no_branch_likely off
// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on
// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off

/* measured: probe_variants func_0038fb50 bare 86wd, truthful (5-arg deff0, 3-arg e2ab0/df270) 86wd tie (keeps faithful, fixes old-style () per semantic gate), sched 94wd regress, loop_invariants 86wd tie, guard levers s64-zero-lt 100wd regress (does not transfer per handoff 7i), u32-zero-lt/zero-lt/ge1/outer-ge1 tie 86wd; fnalign truthful 98 edits (sltu $at+beqz vs beqz inner !=0 guard, var16 materialisation order, six-float store rotation); lever 4 (slti inclusive) N/A - no slti, sltu sites need (s64)0 lever which regresses; lb/lbu N/A; double-def offset (addu base+off after lw) remains + float rotation; re-derived (Ghidra/IDA 5,3,3 confirmed, no fabrications); archive docs/probe_archive/IoE_0038fb50_body.c (stale nd262, fresh 86wd). Banked guarded floor (no pragmas, sched regresses). */
// FUN_0038FB50 NONMATCHING
#ifdef NON_MATCHING
u8 *func_0038fb50(u8 *arg0, s32 arg1)
{
    extern s32 func_003deff0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e2ab0(s32 arg0, void *arg1, s32 arg2);
    extern s32 func_003df270(s32 arg0, void *arg1, s32 arg2);
    struct {
        s32 f0;
        f32 f10;
        f32 f14;
        f32 f18;
        f32 f4;
        f32 f8;
        f32 fC;
        s32 f1C;
        s32 f1E;
    } header;
    struct {
        s32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    } entry;
    u32 count;
    s32 offset;
    u16 temp_2;
    u8 *temp_2_2;

    offset = 0x30;
    offset += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        offset += *(u16 *)(arg0 + 0x1C) * 2;
    }
#pragma push
/* measured: schedule on fills the first two call delay slots only. */
#pragma schedule on
    if (func_003deff0(arg1, 0x2C, offset, 0x37002, 0x37) == 0) {
        goto block_17;
    }
    if (func_003deff0(arg1, 1, offset - 0xC, 0x37002, 0x37) == 0) {
        goto block_17;
    }
#pragma pop
    header.f10 = *(f32 *)(arg0 + 0x10);
    header.f0 = *(s32 *)arg0;
    header.f14 = *(f32 *)(arg0 + 0x14);
    header.f1C = *(u16 *)(arg0 + 0x1C);
    header.f18 = *(f32 *)(arg0 + 0x18);
    header.f1E = *(u16 *)(arg0 + 0x1E);
    header.f4 = *(f32 *)(arg0 + 4);
    header.f8 = *(f32 *)(arg0 + 8);
    header.fC = *(f32 *)(arg0 + 0xC);
    if (func_003e2ab0(arg1, (u8 *)&header, 0x24) == 0) {
        goto block_17;
    }
    temp_2 = *(u16 *)(arg0 + 0x1E);
    if ((s32)temp_2 > 0) {
        count = 0;
        if (temp_2 != 0) {
            offset = 0;
            do {
                temp_2_2 = (u8 *)(*(s32 *)(arg0 + 0x20) + offset);
                entry.f0 = *(s32 *)temp_2_2;
                entry.f4 = *(f32 *)(temp_2_2 + 4);
                entry.f8 = *(f32 *)(temp_2_2 + 8);
                entry.fC = *(f32 *)(temp_2_2 + 0xC);
                if (func_003e2ab0(arg1, (u8 *)&entry, 0x10) == 0) {
                    goto block_17;
                }
                count += 1;
                offset += 0x10;
                if (count >= *(u16 *)(arg0 + 0x1E)) {
                    goto block_13;
                }
            } while (1);
        }
    }
block_13:
    if (*(s32 *)arg0 & 1) {
        if (func_003df270(arg1, *(u8 **)(arg0 + 0x24),
                          *(u16 *)(arg0 + 0x1C) * 2) == 0) {
            goto block_17;
        }
        return arg0;
    }
block_17:
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fb50);
#endif
/* measured: probe_variants src/promoted/code1_0038.c func_0038fd30 bare 88wd, sched (schedule on + no_branch_likely on) 9wd, sched+common_subs off 74wd regress, sched inclusive (>0 -> >=1) 9wd tie, sched direct-copy 9wd tie, sched+loop_invariants 9wd tie, loop_invariants alone 88wd tie; fnalign sched 11 edits (float-load rotation lwc1 f5/f4/f3 vs f2/f1/f0 + store order, plus 4 reloc-only); lever 4 (slti inclusive) N/A - no slti in window, >0 vs >=1 tie confirms bgtz correct; parent mdlSE lesson: all four pragmas measured on exact body (schedule on required 88->9, common_subs off regresses 9->74 per handoff 7h duplication, loop_invariants tie); lb/lbu N/A (no single-byte loads); double-def N/A (no col*12 chain); re-derived (4-arg df050, 3-arg e2910/df2a0 truthful, no fabrications per Ghidra/IDA two-copy rotation); archive docs/probe_archive/DcG_0038fd30_body.c (stale 12wd, fresh 9wd). Banked guarded floor with sched bracket. */
// FUN_0038FD30 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fd30(u8 *arg0)
{
    extern s32 func_003df050(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
    extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df2a0(u8 *arg0, void *arg1, s32 arg2);
    struct Input {
        s32 size;
        f32 values[6];
        u16 count1;
        u8 pad7E[2];
        u16 count2;
        u8 padding[8];
    } input;
    struct Output {
        f32 v0;
        f32 v1;
        f32 v2;
        f32 v3;
        f32 v4;
        f32 v5;
        f32 v6;
        f32 v7;
    } output;
    f32 temp_f5;
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 status[4];
    s32 temp_18;
    u16 temp_2_2;
    u8 *temp_2;

    if (func_003df050(arg0, 1, 0, status) != 0) {
        goto read_header;
    }
    return NULL;

read_header:
    if (func_003e2910(arg0, &input, 0x24) == 0x24) {
        goto make_output;
    }
    return NULL;

make_output:
    temp_f5 = input.values[0];
    temp_f4 = input.values[1];
    temp_f3 = input.values[2];
    temp_f2 = input.values[3];
    temp_f1 = input.values[4];
    temp_f0 = input.values[5];
    output.v3 = temp_f5;
    output.v4 = temp_f4;
    output.v5 = temp_f3;
    output.v0 = temp_f2;
    output.v1 = temp_f1;
    output.v2 = temp_f0;
    temp_2 = func_0038f990(input.count1, input.count2,
                            (f32 *)&output.v0, input.size);
    if (temp_2 == NULL) {
        goto result_null;
    }
    temp_2_2 = *(u16 *)(temp_2 + 0x1E);
    if ((s32)temp_2_2 > 0) {
        goto read_data;
    }

check_flags:
    if ((*(s32 *)temp_2 & 1) != 0) {
        goto read_flags;
    }

return_result:
    return temp_2;

result_null:
    return NULL;

read_data:
    temp_18 = temp_2_2 * 0x10;
    if (temp_18 == func_003e2910(arg0, *(void **)(temp_2 + 0x20), temp_18)) {
        goto check_flags;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;

read_flags:
    if (func_003df2a0(arg0, *(void **)(temp_2 + 0x24),
                      *(u16 *)(temp_2 + 0x1C) * 2) != 0) {
        goto return_result;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;
}
#pragma schedule off
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fd30);
#endif
/* measured: probe_variants func_0038fe90 fixed (externs corrected, jtbl redeclare removed) 216wd (vs stale archive 732wd oversized), sched 191wd win (-25), loop_invariants 215wd tie, sched inclusive (value<0xF0 -> <=0xEF) 191wd tie (fndiff both slti $at, exclusive already $at so lever neutral here); fnalign sched 246 edits (frame 0x140 vs retail 0x110 + scheduling + address chains, plus 4 reloc-only); lever 4 tie per above; parent lesson: schedule measured, common_subs off COMPILE ERROR (pragma+body interaction, banked without it), loop_invariants tie; lb (lbu correct for u8 record bytes) checked; double-def offset (addu base+off after lw at 28FF24/28FF30) remains; re-derived (5-arg f990, 3-arg df360/df300, 1-arg e2ce0, jtbl void* per file-scope, Ghidra/IDA 5-arg confirmed); archive docs/probe_archive/P038_0038fe90_body.c (stale oversized). Banked guarded floor with sched bracket; revisit (2.4% short 204v209): sched+common_subs push 192wd tie+1 (not adopted), dead-arm N/A (no trailing empty else-if, ends with flag-gated j-loop + return), compare-chain N/A (two ==2 tests on different bytes, not adjacent K/K+1). */
// FUN_0038FE90 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fe90(u8 *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4)
{
    extern s32 func_003df300(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df360(u8 *arg0, void *arg1, s32 arg2);
    extern u8 *func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s32 arg0, ...);
    extern s32 func_003e2ce0(u8 *arg0, s32 arg1);
    u8 *stream;
    u8 *obj;
    u8 *data;
    u8 *record;
    u8 **records;
    u8 scratch[176];
    u32 input0;
    u32 input1;
    u32 input2;
    u32 input3;
    u32 failure0;
    u32 failure1;
    s32 depth;
    s32 i;
    s32 j;
    s32 value;
    u16 count;

    stream = arg0;
    *arg4 = 0;
    obj = func_0038f990(arg1 & 0xFFFF, arg2 & 0xFFFF, arg3, 1);
    if (obj == NULL) {
        return NULL;
    }
    count = *(u16 *)(obj + 0x1E);
    if (count > 0) {
        data = *(u8 **)(obj + 0x20);
        i = 0;
        while (1) {
            if (func_003df360(stream, &input0, 4) == 0 ||
                func_003df360(stream, &input1, 4) == 0 ||
                func_003df300(stream, data + 4, 4) == 0 ||
                func_003df300(stream, data + 0xC, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            data[8] = input0 >> 16;
            data[0] = data[8] | 1;
            *(s16 *)(data + 0xA) = input1;
            *(s16 *)(data + 2) = input1 >> 16;
            data[1] = (((input0 >> 8) & 0xFF) == 2) ? 0xFF : 0;
            data[9] = ((u8)input0 == 2) ? 0xFF : 0;
            i++;
            data += 0x10;
            if (i >= count) {
                break;
            }
        }
    } else if (func_003e2ce0(stream, 4) == 0) {
        jtbl_008873EC[0](obj);
        return NULL;
    }
    records = (u8 **)scratch;
    record = scratch + 0x98;
    record[0] = 0;
    record[1] = 0xFF;
    depth = 1;
    while (1) {
        if (record[1] == 0xFF) {
            record = *(u8 **)(*(u8 **)(obj + 0x20) +
                              (*(u16 *)(record + 2) * 0x10));
            records[depth++] = record + 8;
            continue;
        }
        if (func_003df360(stream, &input2, 4) == 0) {
            jtbl_008873EC[0](obj);
            return NULL;
        }
        value = (input2 >> 16) & 0xFFFF;
        if (value < 0xF0) {
            record[1] = value;
            depth--;
            *(u16 *)(record + 2) = input2;
            record = records[depth];
            if (depth == 0) {
                break;
            }
            continue;
        }
        *arg4 = 1;
        jtbl_008873EC[0](obj);
        failure0 = 0x11D;
        failure1 = func_003df590(1);
        func_003df4d0((s32 *)&failure0);
        return NULL;
    }
    if ((*(s32 *)obj & 1) != 0) {
        j = 0;
        count = *(u16 *)(obj + 0x1C);
        i = 0;
        while (i < count) {
            if (func_003df360(stream, &input3, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            *(u8 *)(*(u32 *)(obj + 0x24) + j) = (s16)input3;
            i++;
            j += 2;
        }
    }
    return obj;
}
#pragma schedule off
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fe90);
#endif
