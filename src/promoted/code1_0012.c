#include "model_motion_internal.h"
typedef signed __int128 s128;
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern f32 fGpffff9cA0;
extern f32 fGpffff9cA4;
extern s128 D_005E5740;
extern s128 D_005E5750;
struct RwMatrixTag;
extern s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb, s32 alpha, s32 mode, s16 centerX, s16 centerY, struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);
extern f32 fGpffff84a4;
extern u8 iGpffffb1d8;
extern u8 iGpffffb1d4;
extern u8 iGpffffb1d0;
extern f32 sinf();
extern void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_0045dfd0(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4);
extern f32 fGpffff8478;
extern f32 cosf(f32 fparg0);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_002ab550(void *arg0, void *arg1);
extern void func_00478e70(void *arg0);
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}
static inline s32 code1_0012_stride_loop(s32 base, s32 index)
{
    return base + index;
}

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void func_00264d90();
extern s32 D_00796670[];
extern u8 D_005E50D0[];
extern u8 D_005E5870[];
extern u8 *func_0046a770(char *filename);
extern void func_001238c0(s32 arg0);

extern void func_00267570();

extern s32 iGpffffb1e0;
extern s32 iGpffffb1e8;
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void func_00103a60(void);

extern s32 func_00121af0(u8 *task);
extern u8 *func_00460990(void);
extern void func_00460ac0(char *name, u8 *task);
extern void func_001221a0(void *arg0, u8 *arg1);
extern void func_00122a40(void *unusedNode, void *work);
extern char D_00796340[];
extern char D_00795F50[];
extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern s32 func_00110850(s16 arg0, s16 arg1);
extern s32 func_0015a160(void);
extern s32 func_0028b650(void);
extern s32 iGpffffb1c8;
extern s32 func_001060d0(void);
extern s32 func_001060e0(void);
extern s32 func_001060f0(void);
extern void func_00106300();
extern void func_00106310();
extern void func_00106320();
extern s32 func_00110d30();
extern void func_00260450(void);
extern s16 func_00123810(void);
extern s16 func_00123830(void);
extern void func_00123850(void);
extern s32 func_00268990(s32 arg0);
extern void func_00103b00(void);
extern void func_0046a340(s32 arg0);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern s32 func_00453dc0(void *arg0);
extern u16 D_008C024E[];
extern void sprintf(void *arg0, const char *arg1, ...);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern void *func_00477f10(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern s32 func_004782b0(void *arg0);
extern u8 D_005E5560[];
extern u8 D_005E5570[];
extern void func_00111bc0(void);
extern s32 func_0025e800(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0025e8b0(s32 arg0);
extern s32 func_0025e8f0(s32 arg0);
extern s32 func_002aa300(u8 *arg0, s32 arg1);
extern s32 func_002aa3f0(void);
extern s32 func_0012dea0(u8 *arg0, s32 arg1);
extern void func_0046d280(void *node);
extern void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6);
extern s32 func_0034c210(void);


typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;
typedef struct {
    f32 x;
    f32 y;
} SVec2_0012;



extern void func_003ef3a0(void *arg0);
extern void func_001437b0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0034f5d0(u8 *arg0);
extern s32 func_0044ea90(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005E57B8[];
extern u8 D_005E57D0[];
extern s32 func_0012c220(u8 *arg0);
extern void func_0012e9d0(u8 *arg0);
extern void func_0012fdf0(u8 *arg0);
extern void func_0012feb0(u8 *arg0);
extern s32 func_001228c0(u8 *task);
extern u8 *iGpffffb1dc;
extern s32 func_00123b70(u8 *arg0);
extern u8 D_005E5170[];
extern u8 D_005E5180[];
extern u8 D_005E5190[];
extern u8 D_005E51A0[];
extern u8 D_005E51B0[];
extern void func_00123d50(u8 *arg0);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void func_0046d730(const void *file, s32 line);
extern u8 D_005E5548[];
extern s32 func_00106600(s16 id);
extern u8 D_005E76C8[];
extern u8 D_005E5720[];
extern s32 func_0012aa70(u8 *arg0);
extern void func_0012b660(u8 *task);
extern void func_0025f230(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
extern void func_004598e0(s32 arg0);
extern void func_004787e0(s32 arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s16 func_00353b50(void *arg0);
extern u8 *func_0046d200(u32 sprites, u32 index);
extern u8 D_005E5F40[];
extern u8 D_005E7670[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s32 datGetFlag(s32 arg0);
extern u8 D_005E5810[];
extern s32 D_005E5B60[];
extern u8 D_005E5BB8[];
extern u8 D_005E76C8[];
extern void func_0012e7c0(u8 *arg0);
extern s32 func_0012ff60(u8 *arg0, u32 arg1);
typedef struct {
    u8 b[4];
} PanelRgba;

void func_00120ae0(Vec2f position, f32 depth, PanelRgba color, u32 number, s32 sprites);

// FUN_001203A0
/* measured: b210 -O2 emits all 1856 retail bytes. Lifetime splitting
   separates the depth and HP row values. Coordinate accumulation and
   explicit byte conversions retain retail's separate evaluations.
   Full owner proof: build/cos20335-continuation/field-ui/review-001203a0-final. */
#pragma push
#pragma opt_lifetimes on
void func_001203a0(Vec2f origin, f32 depth, s32 opacity, u8 *entry, s32 showMaximum, s32 fullName)
{
    extern u8 *func_0046a770(char *filename);
    extern void func_0046d730(const void *file, s32 line);
    extern u32 func_0010d620(s16 unit);
    extern u32 func_0010d6d0(s16 unit);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern u32 func_00104ce0(s16 unit);
    extern u16 func_00104dc0(s16 unit);
    extern u32 func_00104d50(s16 unit);
    extern u16 func_00104e30(s16 unit);
    extern void func_0046d4c0(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 alpha, u8 red, u8 green, u8 blue, f32 depth, s32 flags);
    extern void func_0046d2b0(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 alpha, f32 depth, s32 flags);
    extern void func_0045d6e0(void *color, void *rectangle, f32 depth, s32 mode);
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 D_005E4F88[];
    PanelRgba numberColor;
    u8 emptyColor[4];
    PanelRgba hpMaxColor;
    PanelRgba spMaxColor;
    Vec2f point;
    s32 hpRect[4];
    s32 spRect[4];
    s32 panelSprites;
    s32 helpSprites;
    s8 fontStyle;
    s16 unit;
    s32 textColor;
    f32 hpMarkerX;
    f32 spMarkerX;
    f32 spY;
    f32 hpY;
    s16 entryStyle;
    s32 alpha;
    s32 currentHp;
    u8 *name;
    s32 missingHpWidth;
    s32 maximumHp;
    u32 hpNumber;
    u32 maxHpNumber;
    u32 spNumber;
    u32 maxSpNumber;

    panelSprites = (s32)func_0046a770((char *)D_005E5830);
    helpSprites = (s32)func_0046a770((char *)D_005E5850);
    if (panelSprites == 0) {
        func_0046d730(D_005E4F88, 0xB1);
    }
    if (helpSprites == 0) {
        func_0046d730(D_005E4F88, 0xB2);
    }
    unit = *(s16 *)entry;
    entryStyle = *(s16 *)(entry + 6);
    switch (entryStyle) {
    case 0:
        fontStyle = 6;
        numberColor.b[0] = 0xEC;
        numberColor.b[1] = 0x7C;
        numberColor.b[2] = 0;
        break;
    case 1:
        fontStyle = 7;
        numberColor.b[2] = numberColor.b[1] = numberColor.b[0] = 0x2D;
        break;
    case 2:
        fontStyle = 6;
        numberColor.b[0] = 0xEC;
        numberColor.b[1] = 0x7C;
        numberColor.b[2] = 0;
        break;
    default:
        fontStyle = 6;
        numberColor.b[1] = numberColor.b[0] = 0xFF;
        numberColor.b[2] = 0x81;
        break;
    }
    numberColor.b[3] = (u8)opacity;
    point.x = origin.x;
    point.y = origin.y;
    if (*(s32 *)(entry + 8) == 3) {
        point.y = origin.y - 5.0f;
    }
    alpha = opacity & 0xFF;
    textColor = alpha | -0x100;
    if (fullName != 0) {
        name = (u8 *)func_0010d620(unit);
    } else {
        name = (u8 *)func_0010d6d0(unit);
    }
    func_00275020(point.x, point.y, 0.0f, textColor, fontStyle, 1, (const char *)name, 0, -1);
    hpNumber = func_00104ce0(unit) & 0xFFFF;
    point.x = 30.0f + origin.x;
    point.y = 27.0f + origin.y;
    func_00120ae0(point, depth, numberColor, hpNumber, panelSprites);
    if (showMaximum != 0) {
        hpMarkerX = 52.0f + origin.x;
        point.x = hpMarkerX;
        hpY = 27.0f;
        hpY += origin.y;
        point.y = hpY;
        func_0046d4c0(0, helpSprites, 0x3D, hpMarkerX, hpY, (0xFF - alpha) & 0xFF, 0xFF, 0xA2, 0, depth, 0);
        point.x = 103.0f + origin.x;
        point.y = hpY;
        maxHpNumber = func_00104dc0(unit) & 0xFFFF;
        hpMaxColor.b[0] = 0xFB;
        hpMaxColor.b[1] = 0xA2;
        hpMaxColor.b[2] = 0;
        hpMaxColor.b[3] = (u8)opacity;
        func_00120ae0(point, depth, hpMaxColor, maxHpNumber, panelSprites);
        point.x = 123.0f + origin.x;
        point.y = 31.0f + origin.y;
    } else {
        point.x = 49.0f + origin.x;
        point.y = 30.0f + origin.y;
    }
    alpha = (u8)opacity;
    alpha = 0xFF - alpha;
    hpY = point.y;
    func_0046d2b0(0, panelSprites, 0x4B, point.x, hpY, (u8)alpha, depth, 0);
    func_0046d2b0(0, panelSprites, 0x4C, point.x, hpY, alpha & 0xFF, depth, 0);
    currentHp = func_00104ce0(unit) & 0xFFFF;
    maximumHp = func_00104dc0(unit) & 0xFFFF;
    missingHpWidth = (s32)((maximumHp - (currentHp & 0xFFFF)) * 0x58) / maximumHp;
    hpRect[2] = missingHpWidth;
    hpRect[3] = 6;
    hpRect[0] = (s32)((95.0f + point.x) - (f32)missingHpWidth);
    hpRect[1] = (s32)(4.0f + hpY);
    emptyColor[2] = emptyColor[1] = emptyColor[0] = 0x2D;
    emptyColor[3] = (u8)opacity;
    func_0045d6e0(emptyColor, hpRect, 0.0f, 1);
    spNumber = func_00104d50(unit) & 0xFFFF;
    point.x = 30.0f + origin.x;
    point.y = 43.0f + origin.y;
    func_00120ae0(point, depth, numberColor, spNumber, panelSprites);
    if (showMaximum != 0) {
        spMarkerX = 52.0f + origin.x;
        point.x = spMarkerX;
        spY = 43.0f;
        spY += origin.y;
        point.y = spY;
        func_0046d4c0(0, helpSprites, 0x3D, spMarkerX, spY, (u32)alpha & 0xFFU, 0xFF, 0xA2, 0, depth, 0);
        point.x = 103.0f + origin.x;
        point.y = spY;
        maxSpNumber = func_00104e30(unit) & 0xFFFF;
        spMaxColor.b[0] = 0xFB;
        spMaxColor.b[1] = 0xA2;
        spMaxColor.b[2] = 0;
        spMaxColor.b[3] = (u8)opacity;
        func_00120ae0(point, depth, spMaxColor, maxSpNumber, panelSprites);
        point.x = 123.0f + origin.x;
        point.y = 42.0f + origin.y;
    } else {
        point.x = 49.0f + origin.x;
        point.y = 41.0f + origin.y;
    }
    alpha = (u32)opacity & 0xFFU;
    alpha = 0xFFU - (u32)alpha;
    spY = point.y;
    func_0046d2b0(0, panelSprites, 0x4B, point.x, spY, (u8)alpha, depth, 0);
    func_0046d2b0(0, panelSprites, 0x4D, point.x, spY, alpha & 0xFF, depth, 0);
    {
        s32 currentSp = func_00104d50(unit) & 0xFFFF;
        s32 maximumSp = func_00104e30(unit) & 0xFFFF;
        s32 missingSpWidth = (s32)((maximumSp - (currentSp & 0xFFFF)) * 0x58) / maximumSp;
        spRect[2] = missingSpWidth;
        spRect[3] = 6;
        spRect[0] = (s32)((95.0f + point.x) - (f32)missingSpWidth);
        spRect[1] = (s32)(4.0f + spY);
    }
    emptyColor[2] = emptyColor[1] = emptyColor[0] = 0x2D;
    emptyColor[3] = (u8)opacity;
    func_0045d6e0(emptyColor, &spRect[0], 0.0f, 1);
}

#pragma pop
// FUN_00120AE0
void func_00120ae0(Vec2f position, f32 depth, PanelRgba color, u32 number, s32 sprites)
{
    s32 alpha;
    u32 remaining;
    s32 panelSprites;
    u8 blue;
    u8 green;

    remaining = number;
    panelSprites = sprites;
    blue = color.b[2];
    green = color.b[1];
    alpha = 0xFF;
    alpha -= color.b[3];
    do {
        func_0046d4c0(0, panelSprites, (remaining % 10U) + 9,
                      position.x, position.y,
                      alpha & 0xFF, color.b[0], green,
                      blue, depth, 0);
        position.x = position.x - 16.0f;
        remaining = remaining / 10U;
    } while (remaining != 0);
}
// FUN_00120EE0
s32 func_00120ee0(void *arg0)
{
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38)) == 2;
}
// FUN_00120F00
void func_00120f00(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x14) = 1;
}
// FUN_00120F20
void func_00120f20(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x10) = 1;
}
// FUN_00120F40
void func_00120f40(u8 *arg0, s64 arg1)
{
    SVec2_0012 sp8;
    u8 *temp_3;
    *(s64 *)&sp8 = arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    *(SVec2_0012 *)(temp_3 + 0x1C) = sp8;
}
// FUN_00120F70
s32 func_00120f70(u8 *arg0) {
    s32 *temp_16;
    s32 temp_3;

    temp_16 = *(s32 **)(arg0 + 0x38);
    temp_3 = *temp_16;
    switch (temp_3) {
    case 0:
        *temp_16 = 2;
    case 2:
        if ((iGpffffb1c8 == 0) && (func_001060f0() != 0)) {
            func_00106100(func_001060d0());
            func_001062f0(func_001060e0());
            func_00106320(0);
        }
        if ((func_001060c0() & 0xFF) == 5) {
            func_00106300((s64)(s16)((s16)func_001060b0() + 1));
            func_00106310(0);
        } else if (func_00110d30(
                       (s64)(s16)func_001060b0()) == 0) {
            func_00106300(func_001060b0());
            func_00106310(((func_001060c0() & 0xFF) + 1) & 0xFF);
        } else {
            func_00106300(func_001060b0());
            if ((func_001060c0() & 0xFF) == 0) {
                func_00106310(3);
            } else if ((func_001060c0() & 0xFF) == 3) {
                func_00106310(5);
            } else {
                func_00106310(((func_001060c0() & 0xFF) + 1) & 0xFF);
            }
        }
        func_00106320(1);
        *temp_16 = 3;
    case 3:
        func_00260450();
        return -1;
    default:
        return 0;
    }
}
// FUN_00121170
void func_00121170(u8 *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}



// FUN_001211A0
s32 func_001211a0(u8 *unusedTask)
{
    return 0;
}

// FUN_00121AF0
s32 func_00121af0(u8 *unusedTask)
{
    func_00103b00();
    return 0;
}
// FUN_00121B20
void func_00121b20(void) {
    func_00103a60();
    func_00451de0((const void *)(&iGpffff9c58), 0xF, 0, 0, func_00121af0, 0, (u8 *)(0));
}

// FUN_00121B70
s32 func_00121b70(u8 *unusedTask) {
    extern s32 func_00122820(s32 arg0, s32 arg1);
    extern s32 func_00122860(s32 arg0, s32 arg1);
    extern s32 func_00123810(void);
    extern s32 func_00123830(void);
    extern void func_00123850(void);
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = (u8 *)iGpffffb1cc;
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        *(s32 *)(temp_16 + 0x14) = 0;
        break;
    case 1:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 2;
        break;
    case 2:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_2 = *(s32 *)(temp_16 + 0xC) + 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_2;
        temp_3 = *(s32 *)(temp_16 + 8);
        if (temp_2_2 >= temp_3) {
            *(s32 *)(temp_16 + 0xC) = temp_3;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 3:
        *(s32 *)(temp_16 + 0x10) = 1;
        if (*(s32 *)(temp_16 + 0x14) != 0) {
            *(u32 *)(temp_16 + 0) = 6;
        } else if ((*(s32 *)(temp_16 + 4) == 4) &&
                   (*(s32 *)(temp_16 + 0x18) != 0)) {
            *(s32 *)(temp_16 + 0x1C) = func_00268990(0);
            *(u32 *)(temp_16 + 0) = 7;
            *(s32 *)(temp_16 + 0x18) = 0;
        }
        break;
    case 4:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 5;
        break;
    case 5:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_3 = *(s32 *)(temp_16 + 0xC) - 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_3;
        if (temp_2_3 <= 0) {
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 0xC) = 0;
            *(u32 *)(temp_16 + 0) = 0;
        }
        break;
    case 6:
        temp_17 = func_00123830();
        temp_18 = func_00123810();
        func_00123850();
        temp_19 = func_00123830();
        temp_2_4 = func_00123810();
        if (temp_17 != temp_19) {
            *(s32 *)(temp_16 + 0x1C) = func_00122820(temp_17, temp_19);
            *(u32 *)(temp_16 + 0) = 7;
        } else if (temp_18 != temp_2_4) {
            *(s32 *)(temp_16 + 0x1C) = func_00122860(temp_18, temp_2_4);
            *(u32 *)(temp_16 + 0) = 7;
        } else {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 7:
        if (func_004522d0(*(s32 *)(temp_16 + 0x1C)) == 3) {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    }
    return 0;
}
// FUN_00121DB0
void func_00121db0(u8 *unusedTask)
{
    jtbl_008873EC[0]((void *)iGpffffb1cc);
    iGpffffb1cc = 0;
}
typedef struct {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    u8 pad10[0xC];
    u8 c1c;
    u8 c1d;
    u8 c1e;
    u8 c1f;
} Frame00121DE0;
// FUN_00121DE0
void func_00121de0(void)
{
    extern f32 sinf(void *arg0, f32 arg1);
    Frame00121DE0 sp;
    u8 *temp_4;
    s32 temp_3;
    s32 var_16;
    s32 var_2;
    f32 result;
    f32 high_temp;
    f32 ratio;

    temp_4 = (u8 *)iGpffffb1cc;
    if (temp_4 != NULL) {
        temp_3 = *(s32 *)(temp_4 + 8);
        if (*(s32 *)temp_4 >= 4) {
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = sinf(temp_4, ratio);
            high_temp = 640.0f - (640.0f * result);
            var_16 = (s32)high_temp;
            var_2 = 0x280;
        } else {
            var_16 = 0;
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = sinf(temp_4, ratio);
            var_2 = (s32)(640.0f * result);
        }
        sp.s0 = var_16;
        sp.s1 = 0;
        sp.s2 = var_2 - var_16;
        sp.s3 = 0x1E0;
        sp.c1f = 0xFF;
        sp.c1c = iGpffffb1d8;
        sp.c1d = iGpffffb1d4;
        sp.c1e = iGpffffb1d0;
        func_0045d6e0(&sp.c1c, &sp.s0, 0.0f, 1);
    }
}
// FUN_00121F20
void func_00121f20(void)
{
    typedef struct {
        f32 p0;
        f32 p1;
        f32 p2;
        f32 p3;
    } Code1Point4;
    typedef struct {
        f32 p0;
        f32 p1;
    } Code1Point2;
    typedef struct {
        u8 c0;
        u8 c1;
        u8 c2;
        u8 c3;
    } Code1Color4;
    extern f32 sinf(f32 fparg0);
    Code1Point4 points[0x25];
    Code1Point2 quad[4];
    Code1Color4 color[4];
    u8 *temp_6;
    Code1Point4 *point;
    f32 result;
    f32 angle;
    f32 scale;
    f32 x;
    f32 sine;
    f32 cosine;
    s32 i;

    temp_6 = (u8 *)iGpffffb1cc;
    if (temp_6 != NULL) {
        color[0].c3 = 0xFF;
        color[0].c0 = iGpffffb1d8;
        color[0].c1 = iGpffffb1d4;
        color[0].c2 = iGpffffb1d0;
        color[3] = color[0];
        color[2] = color[3];
        color[1] = color[2];
        result = sinf(
            (fGpffff84a4 * (f32)*(s32 *)(temp_6 + 0xC)) /
            (f32)*(s32 *)(temp_6 + 8));
        scale = 600.0f - (600.0f * result);
        angle = 0.0f;
        i = 0;
        while (i < 0x25) {
            x = fGpffff8478 * angle;
            sine = cosf(x);
            cosine = sinf(x);
            point = &points[i];
            point->p0 = ((scale * sine * 1066.0f) / 1000.0f) + 320.0f;
            point->p1 = (scale * cosine) + 224.0f;
            point->p2 = ((sine * 600.0f * 1066.0f) / 1000.0f) + 320.0f;
            point->p3 = (cosine * 600.0f) + 224.0f;
            angle += 10.0f;
            i++;
        }
        i = 0;
        while (i < 0x24) {
            point = &points[i];
            quad[0] = *(Code1Point2 *)point;
            quad[1] = *(Code1Point2 *)((u8 *)point + 8);
            quad[2] = *(Code1Point2 *)(point + 1);
            quad[3] = *(Code1Point2 *)((u8 *)(point + 1) + 8);
            func_0045dfd0(color, quad, 0.0f, 4, 4, 1);
            i++;
        }
    }
}
// FUN_001221A0
/* measured: opt_propagation off preserves the single hoisted D_00887300 base
   used by retail across this callback's state setup sequence. */
#pragma opt_propagation off
void func_001221a0(void *arg0, u8 *arg1)
{
    typedef struct {
        s32 s0;
        s32 s1;
        s32 s2;
        s32 s3;
        u8 pad10[8];
        u8 c1c;
        u8 c1d;
        u8 c1e;
        u8 c1f;
    } Frame001221A0;
    extern s32 (*D_00887304[])(s32 arg0, void *arg1);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    Frame001221A0 sp;
    void (**base)(s32 arg0, s32 arg1);
    s32 result;
    s32 state;
    s32 alpha;

    if ((*(u32 *)(arg1 + 0x10) & 1) != 0) {
        D_00887304[0](0xE, &result);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](7, 2);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](0xB, 6);
        base[0](0xA, 5);
        base[0](2, 4);
        base[0](0xE, 0);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        state = *(s32 *)(arg1 + 4);
        if (state == 3)
            goto state3;
        if (state == 2)
            goto state2;
        if (state == 4)
            goto draw;
        if (state == 1)
            goto draw;
        if (state == 0 || state != 0)
            goto done;
        goto done;
    draw:
        if (iGpffffb1cc != 0) {
            alpha = ((*(s32 *)(iGpffffb1cc + 0xC) * 0xFF) /
                     *(s32 *)(iGpffffb1cc + 8));
            sp.s0 = 0;
            sp.s1 = 0;
            sp.s2 = 0x280;
            sp.s3 = 0x1E0;
            sp.c1f = (u8)alpha;
            sp.c1c = iGpffffb1d8;
            sp.c1d = iGpffffb1d4;
            sp.c1e = iGpffffb1d0;
            func_0045d6e0(&sp.c1c, &sp.s0, 0.0f, 1);
        }
        goto done;
    state2:
        func_00121de0();
        goto done;
    state3:
        func_00121f20();
    done:
        base[0](0xE, result);
    }
}
/* measured: closes the opt_propagation bracket for func_001221a0. */
#pragma opt_propagation on
// FUN_001223D0
s32 func_001223d0(u8 *unusedTask) {
    u8 *p;
    s32 x;

    p = func_00460990();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    *(void **)(p + 8) = (void *)func_001221a0;
    *(s32 *)(p + 0x10) = x;
    func_00460ac0(D_00796340, p);
    return 0;
}

// FUN_00122720
/* The case values come from decoding the jump table at 0x007466C0 with
   tools/jtbl.py: entry 0 returns 1, entries 1/2/4/5 share one body returning
   0, entry 3 returns 2, and anything >= 6 falls through to the default 1.
   The labels are declared in that object order because b210 lays case bodies
   out in declaration order. */
s32 func_00122720(void) {
    s32 *state;

    state = (s32 *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state[0]) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 4:
    case 5:
        return 0;
    case 3:
        return 2;
    }
    return 1;
}

// FUN_001227A0
s32 func_001227a0(void)
{
    if (iGpffffb1cc == 0) {
        return 1;
    }
    return *(s32 *)(iGpffffb1cc + 4);
}
// FUN_001227D0
void func_001227d0(void)
{
    if (iGpffffb1cc != 0) {
        *(s32 *)(iGpffffb1cc + 0x14) = 1;
    }
}
// FUN_001227F0
s32 func_001227f0(void)
{
    s32 result;
    u8 *temp_3;
    result = 1;
    temp_3 = (u8 *)iGpffffb1cc;
    if (temp_3 == NULL)
        return 1;
    if (*(s32 *)(temp_3 + 0x14) != 0)
        result = 0;
    return result;
}
// FUN_00122820
void func_00122820(s32 arg0, s32 arg1)
{
    func_00264d90(0, arg0, arg1, D_00796670);
}



// FUN_00122860
void func_00122860(s32 arg0, s32 arg1)
{
    func_00267570(0, arg0, arg1, D_00796670);
}



// FUN_001228C0
s32 func_001228c0(u8 *unusedTask)
{
    s32 temp_3;
    s32 i;
    u8 *temp_16;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *temp_6;
    u8 *table;

    temp_16 = iGpffffb1dc;
    temp_3 = *(s32 *)(temp_16 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_16 + 0x110) = (s32)func_0046a770((char *)D_005E5870);
        temp_6 = iGpffffb1dc;
        i = 0;
        table = D_005E50D0;
        while (i < 5) {
            temp_4 = table + (i << 5);
            temp_3_2 = temp_6 + i * 0x30;
            *(f32 *)(temp_3_2 + 0x20) = *(f32 *)(temp_4 + 0);
            *(f32 *)(temp_3_2 + 0x24) = *(f32 *)(temp_4 + 4);
            *(f32 *)(temp_3_2 + 0x28) = *(f32 *)(temp_4 + 8);
            *(f32 *)(temp_3_2 + 0x2C) = *(f32 *)(temp_4 + 0xC);
            *(s32 *)(temp_3_2 + 0x48) = *(s32 *)(temp_4 + 0x14);
            *(s32 *)(temp_3_2 + 0x4C) = *(s32 *)(temp_4 + 0x18);
            *(s8 *)(temp_3_2 + 0x39) = *(s32 *)(temp_4 + 0x10);
            *(s8 *)(temp_3_2 + 0x38) = 0;
            i++;
        }
        *(s32 *)(temp_6 + 0x10) = 0;
        *(s32 *)(temp_16 + 0) = 1;
        break;
    case 1:
        *(s16 *)(temp_16 + 4) = (s16)func_001060b0();
        *(s16 *)(temp_16 + 6) = func_001060c0() & 0xFF;
        *(s16 *)(temp_16 + 8) =
            (s8)func_00110850(*(s16 *)(temp_16 + 4), *(s16 *)(temp_16 + 6));
        func_001238c0(0);
        *(s32 *)(temp_16 + 0) = 2;
        break;
    case 2:
        break;
    }
    return 0;
}
// FUN_00122A10
void func_00122a10(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    iGpffffb1dc = 0;
}



// FUN_00122A40
/* measured: b210 -O2 emits all 3220 executable retail bytes; the
   remaining 12 bytes are zero alignment. Fresh float constants and
   shared integer literals require propagation and constant extraction
   off, with common-subexpression optimization enabled.
   Proof: build/cos20335-continuation/field-ui/review-00122a40-closed. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
void func_00122a40(void *unusedNode, void *work)
{
    extern s32 (*D_00887304[])(RwRenderState state, void *value);
    extern s32 (*D_00887300[])(RwRenderState state, void *value);
    extern void func_0046d3b0(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 shadowAlpha, u8 alpha, f32 depth, s32 flags);
    extern f32 func_0046b2f0(u8 *sprite);
    extern void func_0046b380(u8 *sprite, s32 flags);
    extern void func_001104d0(s32 date, s32 *month, s32 *day);
    extern s32 func_00110580(s32 date);
    extern s32 func_00110d30(s32 date);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    s32 (**states)(RwRenderState state, void *value);
    u8 *sprite;
    s32 parent;
    u8 *calendar;
    s32 value;
    s32 progress;
    s32 savedFog;
    s32 startFrame;
    s32 elapsed;
    s32 duration;
    s32 i;
    s32 month;
    s32 day;
    s32 height;
    s32 spriteIndex;
    f32 xOffset;
    f32 backgroundX;
    f32 yOffset;
    calendar = (u8 *)work;
    parent = 0;
    D_00887304[0](rwRENDERSTATEFOGENABLE, &savedFog);
    states = D_00887300;
    states[0](rwRENDERSTATEFOGENABLE, (void *)0);
    states[0](6, (void *)0);
    states[0](7, (void *)2);
    states[0](8, (void *)0);
    states[0](9, (void *)2);
    states[0](0xC, (void *)1);
    states[0](0xB, (void *)6);
    states[0](0xA, (void *)5);
    states[0](2, (void *)4);
    states[0](rwRENDERSTATEFOGENABLE, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    if ((*(s32 *)(calendar + 0xC) & 1) != 0) {
        if (*(s32 *)(calendar + 0x14) != 0) {
            value = *(s32 *)(calendar + 0x10);
            if (value < 0x64) {
                *(s32 *)(calendar + 0x10) = value + 1;
            }
        } else {
            value = *(s32 *)(calendar + 0x10);
            if (value != 0) {
                *(s32 *)(calendar + 0x10) = value - 1;
            }
            if (*(s32 *)(calendar + 0x10) == 0) {
                *(s32 *)(calendar + 0xC) = 0;
            }
        }
        for (i = 0; i < 5; i++) {
            func_001437b0(calendar + i * 0x30 + 0x20, *(s32 *)(calendar + 0x10), 0);
        }
        startFrame = *(s32 *)(calendar + 0x78);
        value = *(s32 *)(calendar + 0x10);
        if (value < startFrame) {
            elapsed = 0;
        } else {
            elapsed = value - startFrame;
        }
        duration = *(s32 *)(calendar + 0x7C) - startFrame;
        if (duration < elapsed) {
            elapsed = duration;
        }
        progress = (elapsed * 0x90) / duration;
        xOffset = (f32)0x23E;
        func_0046d3b0(0, *(s32 *)(calendar + 0x110), 0x25, xOffset + *(f32 *)(calendar + 0x30), *(f32 *)(calendar + 0x34), 0, (0xFF - *(u8 *)(calendar + 0x3A)) & 0xFF, 0.0f, 1);
        if (*(s32 *)(calendar + 0x18) != 0) {
            if (*(s32 *)(calendar + 0x1C) == 0) {
                sprite = (u8 *)func_0046d200((u32)*(s32 *)(calendar + 0x110), 0x1D);
            } else {
                sprite = (u8 *)func_0046d200((u32)*(s32 *)(calendar + 0x110), 0x1E);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            sprite = (u8 *)func_0046d200((u32)*(s32 *)(calendar + 0x110), 0x1D);
        } else {
            sprite = (u8 *)func_0046d200((u32)*(s32 *)(calendar + 0x110), 0x1E);
        }
        *(s32 *)(sprite + 0x24) = 0;
        backgroundX = (f32)0x223;
        *(f32 *)(sprite + 8) = backgroundX + *(f32 *)(calendar + 0x60);
        *(f32 *)(sprite + 0xC) = -33.0f + *(f32 *)(calendar + 0x64);
        *(s8 *)(sprite + 0x10) = (s8)(0xFF - *(u8 *)(calendar + 0x6A));
        *(s16 *)(sprite + 0x1C) = 0x50;
        *(s16 *)(sprite + 0x1E) = 0x2D;
        *(f32 *)(sprite + 0x18) = (f32)(0x90 - progress);
        func_0046b380(sprite, 1);
        /* Preserve the forwarded word before releasing the temporary sprite. */
        parent = (s32)sprite;
        func_0046d280(sprite);
    }
    if ((*(s32 *)(calendar + 0xC) & 2) != 0) {
        func_001104d0(*(s16 *)(calendar + 4), &month, &day);
        value = (s32)*(f32 *)(calendar + 0x90);
        func_0046d4c0(parent, *(s32 *)(calendar + 0x110), 7, (f32)(value + 0x1C2), 17.0f + *(f32 *)(calendar + 0x94), (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        func_0046d4c0(parent, *(s32 *)(calendar + 0x110), 8, (f32)(value + 0x246), 17.0f + *(f32 *)(calendar + 0x94), (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        value = month / 10 + 9;
        xOffset = (f32)0x1CF;
        xOffset += *(f32 *)(calendar + 0x90);
        func_0046d3b0(parent, *(s32 *)(calendar + 0x110), value, 14.0f + xOffset, 17.0f + *(f32 *)(calendar + 0x94), 0, (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0(parent, *(s32 *)(calendar + 0x110), month % 10 + 9, 14.0f + (476.0f + *(f32 *)(calendar + 0x90)), 17.0f + *(f32 *)(calendar + 0x94), 0, (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0(parent, *(s32 *)(calendar + 0x110), 0x13, 14.0f + (490.0f + *(f32 *)(calendar + 0x90)), 17.0f + *(f32 *)(calendar + 0x94), 0, (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0(parent, *(s32 *)(calendar + 0x110), day / 10 + 9, 14.0f + (500.0f + *(f32 *)(calendar + 0x90)), 17.0f + *(f32 *)(calendar + 0x94), 0, (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0.0f, 1);
        value = day % 10 + 9;
        xOffset = (f32)0x201;
        xOffset += *(f32 *)(calendar + 0x90);
        func_0046d3b0(parent, *(s32 *)(calendar + 0x110), value, 14.0f + xOffset, 17.0f + *(f32 *)(calendar + 0x94), 0, (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0.0f, 1);
        if (func_00110d30(*(s16 *)(calendar + 4)) != 0) {
            value = func_00110580(*(s16 *)(calendar + 4));
            xOffset = (f32)0x219;
            func_0046d4c0(parent, *(s32 *)(calendar + 0x110), value, xOffset + *(f32 *)(calendar + 0x90), 17.0f + *(f32 *)(calendar + 0x94), (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0xFF, 0xAC, 0x99, 0.0f, 1);
        } else if (func_00110580(*(s16 *)(calendar + 4)) == 6) {
            value = func_00110580(*(s16 *)(calendar + 4));
            xOffset = (f32)0x219;
            func_0046d4c0(parent, *(s32 *)(calendar + 0x110), value, xOffset + *(f32 *)(calendar + 0x90), 17.0f + *(f32 *)(calendar + 0x94), (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0x99, 0xA4, 0xFF, 0.0f, 1);
        } else {
            value = func_00110580(*(s16 *)(calendar + 4));
            xOffset = (f32)0x219;
            func_0046d4c0(parent, *(s32 *)(calendar + 0x110), value, xOffset + *(f32 *)(calendar + 0x90), 17.0f + *(f32 *)(calendar + 0x94), (0xFF - *(u8 *)(calendar + 0x9A)) & 0xFF, 0xFF, 0xFF, 0xFF, 0.0f, 1);
        }
        startFrame = *(s32 *)(calendar + 0xD8);
        value = *(s32 *)(calendar + 0x10);
        if (value < startFrame) {
            elapsed = 0;
        } else {
            elapsed = value - startFrame;
        }
        duration = *(s32 *)(calendar + 0xDC) - startFrame;
        if (duration < elapsed) {
            elapsed = duration;
        }
        progress = (elapsed << 0xC) / duration;
        if (func_00110d30(*(s16 *)(calendar + 4)) != 0) {
            value = *(s16 *)(calendar + 6);
            if (value == 3) {
                spriteIndex = 0x1A;
            } else {
                spriteIndex = value + 0x14;
            }
        } else {
            spriteIndex = *(s16 *)(calendar + 6) + 0x14;
        }
        if (*(s32 *)(calendar + 0x18) != 0) {
            if (*(s32 *)(calendar + 0x1C) == 1) {
                switch (spriteIndex) {
                case 0x18:
                    spriteIndex = 0x1B;
                    break;
                case 0x1A:
                    spriteIndex = 0x1C;
                    break;
                }
            }
        } else if ((func_0015a160() != 0) || (func_0028b650() != 0)) {
            switch (spriteIndex) {
                case 0x18:
                    spriteIndex = 0x1B;
                    break;
                case 0x1A:
                    spriteIndex = 0x1C;
                    break;
                }
        }
        sprite = (u8 *)func_0046d200((u32)*(s32 *)(calendar + 0x110), spriteIndex);
        *(s32 *)(sprite + 0x24) = 0;
        *(f32 *)(sprite + 8) = 552.0f + *(f32 *)(calendar + 0xC0);
        *(f32 *)(sprite + 0xC) = 31.0f + *(f32 *)(calendar + 0xC4);
        *(s8 *)(sprite + 0x10) = (s8)(0xFF - *(u8 *)(calendar + 0xCA));
        height = (s32)func_0046b2f0(sprite);
        *(s16 *)(sprite + 0x20) = 0xFF6;
        *(s16 *)(sprite + 0x22) = (s16)progress;
        value = (s32)(func_0046b2f0(sprite) / 2.0f + (f32)(height / 2));
        yOffset = 31.0f + *(f32 *)(calendar + 0xC4);
        yOffset -= (f32)value;
        *(f32 *)(sprite + 0xC) = (f32)height + yOffset;
        func_0046b380(sprite, 1);
        /* Preserve the forwarded word before releasing the temporary sprite. */
        parent = (s32)sprite;
        func_0046d280(sprite);
    }
    if ((*(s32 *)(calendar + 0xC) & 4) != 0) {
        if (*(s32 *)(calendar + 0x18) != 0) {
            if (*(s32 *)(calendar + 0x1C) == 0) {
                xOffset = (f32)0x247;
                func_0046d3b0(parent, *(s32 *)(calendar + 0x110), 0x1F, xOffset + *(f32 *)(calendar + 0xF0), 51.0f + *(f32 *)(calendar + 0xF4), 0, (0xFF - *(u8 *)(calendar + 0xFA)) & 0xFF, 0.0f, 1);
                value = *(s16 *)(calendar + 8) + 0x20;
                xOffset = (f32)0x247;
                func_0046d3b0(parent, *(s32 *)(calendar + 0x110), value, xOffset + *(f32 *)(calendar + 0xF0), 51.0f + *(f32 *)(calendar + 0xF4), 0, (0xFF - *(u8 *)(calendar + 0xFA)) & 0xFF, 0.0f, 1);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            xOffset = (f32)0x247;
            func_0046d3b0(parent, *(s32 *)(calendar + 0x110), 0x1F, xOffset + *(f32 *)(calendar + 0xF0), 51.0f + *(f32 *)(calendar + 0xF4), 0, (0xFF - *(u8 *)(calendar + 0xFA)) & 0xFF, 0.0f, 1);
            value = *(s16 *)(calendar + 8) + 0x20;
            xOffset = (f32)0x247;
            func_0046d3b0(parent, *(s32 *)(calendar + 0x110), value, xOffset + *(f32 *)(calendar + 0xF0), 51.0f + *(f32 *)(calendar + 0xF4), 0, (0xFF - *(u8 *)(calendar + 0xFA)) & 0xFF, 0.0f, 1);
        }
    }
    states[0](rwRENDERSTATEFOGENABLE, (void *)savedFog);
}
#pragma pop
// FUN_001236E0
s32 func_001236e0(u8 *unusedTask) {
    u8 *p;
    u8 *q;

    p = func_00460990();
    q = iGpffffb1dc;
    *(void **)(p + 8) = (void *)func_00122a40;
    *(u8 **)(p + 0x10) = q;
    func_00460ac0(D_00795F50, p);
    return 0;
}

// FUN_00123730
s32 func_00123730(s32 arg0)
{
    s32 temp_2;
    s32 temp_2_2;
    func_0044ea90(D_005E5170, 0x179);
    temp_2_2 = (s32)D_008873F4[0](1, 0x114, 0x40000);
    if (temp_2_2 == 0)
        return 0;
    iGpffffb1dc = (u8 *)temp_2_2;
    temp_2 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005E5180), 0x96, 0, 0, func_001228c0, func_00122a10, (u8 *)((u8 *)temp_2_2));
    (s32)func_00451fc0((void *)(temp_2), (const void *)(D_005E5190), 0x97, 0, 0, func_001236e0, 0, (u8 *)((u8 *)0));
    return temp_2;
}
// FUN_00123810
s16 func_00123810(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 6);
    }
    return var_2;
}



// FUN_00123830
s16 func_00123830(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 4);
    }
    return var_2;
}



/* measured: the named first-field load plus -O1 reproduce retail's argument setup order; exact match nd 0 (obj 104B/window 112B). */
// FUN_00123850
/* measured: opens optimization_level 1 to keep the +6 store and +4 load before the call conversion (nd 0). */
#pragma optimization_level 1
void func_00123850(void) {
    u8 *p;
    s32 t;
    s16 first;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 4) = (s16)func_001060b0();
        t = func_001060c0() & 0xFF;
        *(s16 *)(p + 6) = (s16)t;
        first = *(s16 *)(p + 4);
        *(s16 *)(p + 8) = (s8)func_00110850(first, (s16)t);
    }
}
/* measured: closes the optimization_level bracket at the file's -O2 baseline (nd 0). */
#pragma optimization_level 2

// FUN_001238C0
void func_001238c0(s32 arg0)
{
    s32 var_8;
    s32 var_9;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_8;
    u8 *table;

    temp_8 = (u8 *)iGpffffb1dc;
    if (temp_8 != NULL) {
        if (arg0 != 0) {
            *(s32 *)(temp_8 + 0x18) = 0;
        }
        if (*(s32 *)(temp_8 + 0x14) != arg0) {
            *(s32 *)(temp_8 + 0x14) = arg0;
            if (arg0 == 1) {
                temp_7 = (u8 *)iGpffffb1dc;
                var_9 = 0;
                table = D_005E50D0;
                while (var_9 < 5) {
                    temp_5 = table + (var_9 << 5);
                    temp_4 = temp_7 + (var_9 * 0x30);
                    *(f32 *)(temp_4 + 0x20) = *(f32 *)(temp_5 + 0);
                    *(f32 *)(temp_4 + 0x24) = *(f32 *)(temp_5 + 4);
                    *(f32 *)(temp_4 + 0x28) = *(f32 *)(temp_5 + 8);
                    *(f32 *)(temp_4 + 0x2C) = *(f32 *)(temp_5 + 0xC);
                    *(s32 *)(temp_4 + 0x48) = *(s32 *)(temp_5 + 0x14);
                    *(s32 *)(temp_4 + 0x4C) = *(s32 *)(temp_5 + 0x18);
                    *(s8 *)(temp_4 + 0x39) = *(s32 *)(temp_5 + 0x10);
                    *(s8 *)(temp_4 + 0x38) = 0;
                    var_9 += 1;
                }
                *(s32 *)(temp_7 + 0x10) = 0;
                *(s32 *)(temp_8 + 0xC) = 7;
                return;
            }
            temp_7_2 = (u8 *)iGpffffb1dc;
            var_8 = 0;
            table = D_005E50D0;
            while (var_8 < 5) {
                temp_5_2 = table + (var_8 << 5);
                temp_4_2 = temp_7_2 + (var_8 * 0x30);
                *(f32 *)(temp_4_2 + 0x20) = *(f32 *)(temp_5_2 + 0);
                *(f32 *)(temp_4_2 + 0x24) = *(f32 *)(temp_5_2 + 4);
                *(f32 *)(temp_4_2 + 0x28) = *(f32 *)(temp_5_2 + 8);
                *(f32 *)(temp_4_2 + 0x2C) = *(f32 *)(temp_5_2 + 0xC);
                *(s32 *)(temp_4_2 + 0x48) = *(s32 *)(temp_5_2 + 0x14);
                *(s32 *)(temp_4_2 + 0x4C) = *(s32 *)(temp_5_2 + 0x18);
                *(s8 *)(temp_4_2 + 0x39) = *(s32 *)(temp_5_2 + 0x10);
                *(s8 *)(temp_4_2 + 0x38) = 0;
                var_8 += 1;
            }
            *(s32 *)(temp_7_2 + 0x10) = 0x46;
        }
    }
}
// FUN_00123A10
void func_00123a10(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s32 *)(p + 0x18) = 1;
        if (func_0015a160() != 0) {
            goto set1;
        }
        if (func_0028b650() != 0) {
            goto set1;
        }
        *(s32 *)(p + 0x1C) = 0;
        return;
set1:
        *(s32 *)(p + 0x1C) = 1;
    }
}

// FUN_00123A80
void func_00123a80(void)
{
    u8 *temp_3;

    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        *(s32 *)(temp_3 + 0x14) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
    }
}



// FUN_00123AA0
void func_00123aa0(s16 arg0) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 0xA) = *(s16 *)(p + 8);
        *(s16 *)(p + 8) = arg0;
    }
}
// FUN_00123AC0
void func_00123ac0(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 8) = *(s16 *)(p + 0xA);
    }
}
// FUN_00123AE0
s8 func_00123ae0(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s8 *)(p + 8);
    }
    return -1;
}
// FUN_00123B10
s16 func_00123b10(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s16 *)(p + 4);
    }
    return -1;
}
// FUN_00123B40
s16 func_00123b40(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s16 *)(p + 6);
    }
    return -1;
}
// FUN_00123B70
s32 func_00123b70(u8 *arg0)
{
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(u32 *)temp_16;
    switch (temp_2) {
    case 0:
        func_00111bc0();
        *(u32 *)temp_16 = 1;
        goto block_20;
    case 1:
        *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x11);
        *(u32 *)temp_16 = 2;
        goto block_20;
    case 2:
        temp_2_2 = func_0025e8f0(*(s32 *)(temp_16 + 4));
        if (temp_2_2 == 1) {
            *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x12);
            *(u32 *)temp_16 = 4;
        } else if (temp_2_2 == 2) {
            *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x13);
            *(u32 *)temp_16 = 3;
        }
        goto block_20;
    case 3:
        temp_2_3 = func_0025e8f0(*(s32 *)(temp_16 + 4));
        if (temp_2_3 == 1) {
            return -1;
        }
        if (temp_2_3 == 2) {
            *(u32 *)temp_16 = 1;
        }
        goto block_20;
    case 4:
        if (func_0025e8f0(*(s32 *)(temp_16 + 4)) == 1) {
            *(s32 *)(temp_16 + 8) = func_002aa300(arg0, 1);
            *(u32 *)temp_16 = 5;
        }
        goto block_20;
    case 5:
        temp_2_4 = func_002aa3f0();
        if (temp_2_4 == 2) {
            goto case_5_action;
        }
        if (temp_2_4 == 1) {
            goto case_5_error;
        }
        if (temp_2_4 != 0) {
            goto case_5_action;
        }
        goto block_20;
case_5_error:
        return -1;
case_5_action:
        *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x13);
        *(u32 *)temp_16 = 3;
        goto block_20;
    default:
        goto block_20;
    }
block_20:
    return 0;
}
// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00123D80
s32 func_00123d80(void)
{
    s32 temp_2;
    func_0044ea90(D_005E51A0, 0x84);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        temp_2 = 0;
    } else {
        temp_2 = (s32)func_00451fc0((void *)(0), (const void *)(D_005E51B0), 0xF, 0, 0, func_00123b70, func_00123d50, (u8 *)((u8 *)temp_2));
        if (temp_2 == 0)
            temp_2 = 0;
    }
    iGpffffb1e0 = temp_2;
    return 1;
}
// FUN_00123E30
s32 func_00123e30(void)
{
    if (func_004522d0(iGpffffb1e0) == 3) {
        iGpffffb1e0 = 0;
        return 1;
    }
    return 0;
}

// FUN_00123E80
s32 func_00123e80(u8 *arg0)
{
    extern s32 func_00122520(s32 arg0, s32 arg1);
    extern void func_00111050(s32 arg0);
    extern void func_00459880(void);
    extern void func_0045a8d0(s32 arg0, s32 arg1);
    extern s32 func_0012c110(void);
    extern s32 func_0012c1a0(s32 arg0);
    extern s32 func_0046a110(void *arg0, s32 arg1, void *arg2);
    extern void func_00121940(void);
    extern void func_00122640(s32 arg0, s32 arg1);
    extern s32 func_0012b760(void);
    extern s32 func_0012b810(s32 arg0);
    extern s32 iGpffffb1e4;
    extern s32 iGpffffb1f0;

    extern u8 D_007963A0[];
    extern u8 D_0079B698[];
    extern u8 D_0079B69C[];
    extern u8 D_0079B6A0[];
    u8 *temp_16;
    s32 temp_2;
    s16 temp_3;
    typedef struct {
        s16 s20;
        s16 s22;
        s16 s24;
        s16 s26;
        s16 s28;
        u8 pad_short[0x1E];
    } ShortWork;
    typedef struct {
        s32 s48;
        s32 s4C;
    } IntWork;
    ShortWork short_work;
    IntWork int_work;

    temp_16 = *(u8 **)(arg0 + 0x38);
    switch (*(u32 *)temp_16) {
    case 0:
        temp_2 = func_00122720();
        if (temp_2 == 0)
            break;
        switch (temp_2) {
        case 2:
            *(u32 *)temp_16 = 2;
            break;
        default:
            func_00122520(1, 1);
            *(u32 *)temp_16 = 1;
            break;
        }
        break;
    case 1:
        if (func_00122720() != 0) {
            *(u32 *)temp_16 = 2;
        }
        break;
    case 2:
        func_00111050(1);
        func_00459880();
        func_0045a8d0(3, 0);
        *(s32 *)(temp_16 + 0xC) = func_0012c110();
        *(u32 *)temp_16 = 3;
        break;
    case 3:
        if (func_0012c1a0(*(s32 *)(temp_16 + 0xC)) != 0) {
            *(u32 *)temp_16 = 4;
        }
        break;
    case 4:
        if (iGpffffb1e4 == 0) {
            *(s32 *)(temp_16 + 0xC) = func_0046a110(arg0, 0x15, D_007963A0);
        } else {
            *(s32 *)(temp_16 + 0xC) = func_0046a110(arg0, 0x16, D_007963A0);
        }
        iGpffffb1e4 = ~iGpffffb1e4;
        *(u32 *)temp_16 = 5;
        break;
    case 5:
        if (func_00452490(*(s32 *)(temp_16 + 0xC)) != 1) {
            *(u32 *)temp_16 = 6;
        }
        break;
    case 6:
        *(s32 *)(temp_16 + 0xC) = (s32)func_0012b760();
        *(u32 *)temp_16 = 7;
        break;
    case 7:
        temp_2 = func_0012b810(*(s32 *)(temp_16 + 0xC));
        if (temp_2 == 4)
            goto state4;
        if (temp_2 == 3)
            goto state3;
        if (temp_2 == 2)
            goto state2;
        switch (temp_2) {
        case 1:
            goto state1;
        default:
            goto state_done;
        }
    state1:
        *(u32 *)temp_16 = 2;
        goto state_done;
    state2:
        func_001113b0();
        func_00111290();
        func_00123850();
        func_001238c0(1);
        func_001029a0(0x19, 0, 0, 0);
        return -1;
    state3:
        iGpffffb1f0 = 1;
        func_00123850();
        func_001238c0(1);
        temp_3 = (s16)func_001060d0();
        if ((temp_3 == 9) && ((u8)func_001060e0() == 5)) {
            func_001029a0(0x19, 0, 0, 0);
            return -1;
        }
        if (*(s32 *)D_0079B6A0 != 0) {
            int_work.s48 = *(s32 *)D_0079B6A0;
            int_work.s4C = 0xFF;
            func_001029a0(0xB, &int_work, 8, 2);
        } else {
            short_work.s20 = (s16)*(s32 *)D_0079B698;
            short_work.s22 = (s16)*(s32 *)D_0079B69C;
            short_work.s24 = 0xFF;
            short_work.s26 = 0;
            short_work.s28 = 0;
            func_001029a0(9, &short_work, 0x1C, 0);
        }
        goto state_done;
    state4:
        func_001238c0(1);
        func_00121940();
        func_00122640(0, 1);
        *(u32 *)temp_16 = 8;
        goto state_done;
    state_done:
    case 8:
    default:
        break;
    }
    return 0;
}
// FUN_00124210
void func_00124210(u8 *arg0)
{
    func_0046a340(*(s32 *)(arg0 + 0x38));
}
// FUN_00124350
extern u32 RpRandom(void);
s32 func_00124350(u8 *unusedWork)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    s32 var_16;
    u32 var_3;
    u32 var_3_2;
    u32 var_3_3;
    u32 var_3_4;
    u32 var_3_5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;

    var_16 = 0;
    if (iGpffffb1e8 > 1) {
        temp_2 = RpRandom();
        var_f0 = (f32)(u32)temp_2;
        temp_f0 = 100.0f * (var_f0 / 2147483648.0f);
        var_3 = (u32)temp_f0;
        if (var_3 > 0x3B)
            goto block_second;
    }
block_8:
    var_16 = 0;
    goto block_end;
block_second:
    temp_2_2 = RpRandom();
    var_f0_2 = (f32)(u32)temp_2_2;
    temp_f0_2 = 100.0f * (var_f0_2 / 2147483648.0f);
    var_3_2 = (u32)temp_f0_2;
    if (var_3_2 < 0x32) {
        temp_2_3 = RpRandom();
        var_f0_3 = (f32)(u32)temp_2_3;
        temp_f0_3 = 3.0f * (var_f0_3 / 2147483648.0f);
        var_3_3 = (u32)temp_f0_3;
        var_16 = var_3_3 + 1;
    } else {
        temp_2_4 = RpRandom();
        var_f0_4 = (f32)(u32)temp_2_4;
        temp_f0_4 = 100.0f * (var_f0_4 / 2147483648.0f);
        var_3_4 = (u32)temp_f0_4;
        if (var_3_4 < 0xA) {
            var_16 = 7;
        } else if (iGpffffb1e8 >= 0xA) {
            temp_2_5 = RpRandom();
            var_f0_5 = (f32)(u32)temp_2_5;
            temp_f0_5 = 3.0f * (var_f0_5 / 2147483648.0f);
            var_3_5 = (u32)temp_f0_5;
            var_16 = var_3_5 + 4;
        }
    }
block_end:
    if (var_16 >= 8) {
        var_16 = 8;
    }
    return var_16 + 0xB;
}
// FUN_001246D0
s32 func_001246d0(u8 *arg0)
{
    u32 sp7C;
    u8 sp50[0x2C];
    s32 var_16;
    s32 var_17;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 1;
    if (arg0 == NULL) {
        func_0046d730(D_005E5548, 0xF4);
    }
    var_16 = 0;
    goto loop_14;
loop_18:
    temp_2 = arg0 + (var_16 * 4);
    temp_4 = temp_2 + 0x44;
    if (*(u8 **)temp_4 == NULL) {
        if (var_16 < 8) {
            sprintf(sp50, (const char *)D_005E5560, var_16 + 1);
        } else {
            sprintf(sp50, (const char *)D_005E5570, var_16 - 7);
        }
        var_17 = func_00455f70(sp50, (s32 *)&sp7C);
        if (var_17 == 0) {
            func_0046d730(D_005E5548, 0xFE);
        }
        *(u8 **)temp_4 =
            func_00477f10(9, 0xFF01, (void *)var_17, sp7C, 0);
        var_17 = 0;
    }
    if ((*(u8 **)temp_4 != NULL) &&
        (func_004782b0(*(u8 **)temp_4) == 0)) {
        var_17 = 0;
        goto done;
    }
    var_16++;
    goto loop_14;
loop_14:
    if (var_16 < 0xF) {
        goto loop_18;
    }
done:
    return var_17;
}
// FUN_00124830
s32 func_00124830(u8 *arg0)
{
    u8 sp40[0x30];
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_16;

    var_16 = 0;
    func_00453670(sp40, 3, 3, *(s32 *)(arg0 + 0x20), 0);
    func_004538e0(sp40, 0x4000, 0x1000, 0, 0);
    temp_2 = func_00453960(sp40);
    switch (temp_2) {
    case 1:
        var_16 = 1;
        break;
    case 2:
        var_16 = 1;
        break;
    }
    temp_18 = *(s32 *)(arg0 + 0x20);
    temp_2_2 = func_00453dc0(sp40);
    *(s32 *)(arg0 + 0x20) = temp_2_2;
    if (temp_2_2 != temp_18) {
        *(s32 *)(arg0 + 0x24) = temp_18;
        *(s32 *)(arg0 + 0x28) = temp_18 << 16;
    }
    if (D_008C024E[0] & 0x40) {
        func_0045af60(0, 0, 0, 1);
        return *(s32 *)(arg0 + 0x20) + 1;
    }
    if (var_16 != 0) {
        func_0045af60(0, 0, 0, 0);
        return 0;
    }
    return -1;
}
// FUN_00124970
void func_00124970(s32 arg0, u32 arg1, s32 arg2, u32 *arg3)
{
    u8 spAC[4];
    u8 sp60[0x4C];
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *var_17;
    u8 *var_16;

    if (arg0 >= 0xF) {
        var_17 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
        var_17 = temp_2 + 0x44;
        if (func_004782b0(*(u8 **)var_17) != 0) {
            var_17 = *(u8 **)var_17;
        } else {
            var_17 = NULL;
        }
    }
    if (var_17 != NULL) {
        if ((arg0 + 8) >= 0xF) {
            var_16 = NULL;
        } else {
            temp_2_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
            var_16 = temp_2_2 + 0x64;
            if (func_004782b0(*(u8 **)var_16) != 0) {
                var_16 = *(u8 **)var_16;
            } else {
                var_16 = NULL;
            }
        }
        if ((var_16 != NULL) && (func_0047a510(var_17, 0x64, sp60) != 0)) {
            spAC[0] = arg1 >> 0x18;
            spAC[1] = arg1 >> 0x10;
            spAC[2] = arg1 >> 8;
            spAC[3] = arg1;
            func_0047a1c0(var_16, sp60, 0);
            if (arg2 & 1) {
                *(s32 *)(var_16 + 0xD8) |= 8;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~8;
            }
            if (arg2 & 2) {
                *(s32 *)(var_16 + 0xD8) |= 0x10;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x10;
            }
            if (arg2 & 0x10) {
                *(s32 *)(var_16 + 0xD8) |= 0x100000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x100000;
            }
            if (arg2 & 0x40) {
                *(s32 *)(var_16 + 0xD8) |= 0x40000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x40000;
            }
            func_002ab550(var_16, spAC);
            if (!(arg2 & 0x10000)) {
                func_00478e70(var_16);
            }
        }
    }
}
extern void *RwMatrixRotate(void *m, void *src, f32 angle, s32 mode);
extern void *func_003e4320(void *dst, void *src, void *m);
extern void *RwMatrixScale(void *m, void *v, s32 mode);
extern void *RwMatrixTranslate(void *m, void *v, s32 mode);
extern u8 D_005E55B0[];
extern u8 D_005E55B8[];
extern u8 D_005E55C0[];
extern u8 D_005E55C8[];
extern u8 D_005E55D0[];
extern u8 D_005E55D8[];

typedef struct {
    u8 q[8];
    f32 f;
} Code1GlobalPair12;

// FUN_00124BB0
/* 956/960 bytes; twenty-five resolved relocations and one zero alignment word. */
#pragma push
#pragma opt_propagation off
void func_00124bb0(s32 arg0,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5,
                   u32 arg1, u32 arg2,
                   f32 fparg6,
                   s32 arg3, u32 *arg4)
{
    u8 color[4];
    Code1GlobalPair12 global_pair;
    u8 vec_f[0x10];
    u8 vec_e[0x10];
    u8 vec_d[0x10];
    u8 matrix[0x40];
    u8 *temp_2;
    u8 *var_16;

    {
        s64 q = *(s64 *)D_005E55B0;
        f32 f = *(f32 *)D_005E55B8;
        *(s64 *)global_pair.q = q;
        global_pair.f = f;
    }
    {
        s64 q = *(s64 *)D_005E55C0;
        f32 f = *(f32 *)D_005E55C8;
        *(s64 *)vec_f = q;
        *(f32 *)(vec_f + 8) = f;
    }
    {
        s64 q = *(s64 *)D_005E55D0;
        f32 f = *(f32 *)D_005E55D8;
        *(s64 *)vec_e = q;
        *(f32 *)(vec_e + 8) = f;
    }
    if (arg0 >= 0xF) {
        var_16 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg4);
        var_16 = temp_2 + 0x44;
        if (func_004782b0(*(u8 **)var_16) != 0) {
            var_16 = *(u8 **)var_16;
        } else {
            var_16 = NULL;
        }
    }
    if (var_16 != NULL) {
        *(s32 *)(matrix + 0x28) = 0x3F800000;
        *(s32 *)(matrix + 0x14) = 0x3F800000;
        *(s32 *)(matrix + 0x00) = 0x3F800000;
        *(s32 *)(matrix + 0x10) = 0;
        *(s32 *)(matrix + 0x08) = 0;
        *(s32 *)(matrix + 0x04) = 0;
        *(s32 *)(matrix + 0x24) = 0;
        *(s32 *)(matrix + 0x20) = 0;
        *(s32 *)(matrix + 0x18) = 0;
        *(s32 *)(matrix + 0x38) = 0;
        *(s32 *)(matrix + 0x34) = 0;
        *(s32 *)(matrix + 0x30) = 0;
        *(s32 *)(matrix + 0x0C) |= 0x20003;
        RwMatrixRotate(matrix, &global_pair, fparg4, 0);
        *(s32 *)(vec_f + 0x00) = 0x3F800000;
        *(s32 *)(vec_f + 0x04) = 0;
        *(s32 *)(vec_f + 0x08) = 0;
        func_003e4320(vec_f, vec_f, matrix);
        RwMatrixRotate(matrix, vec_f, fparg3, 2);
        *(s32 *)(vec_e + 0x00) = 0;
        *(s32 *)(vec_e + 0x04) = 0;
        *(s32 *)(vec_e + 0x08) = 0x3F800000;
        func_003e4320(vec_e, vec_e, matrix);
        RwMatrixRotate(matrix, vec_e, fparg5, 2);
        *(f32 *)(vec_d + 0x00) = fparg6;
        *(f32 *)(vec_d + 0x04) = fparg6;
        *(f32 *)(vec_d + 0x08) = fparg6;
        RwMatrixScale(matrix, vec_d, 2);
        *(f32 *)(vec_d + 0x00) = fparg0;
        *(f32 *)(vec_d + 0x04) = fparg1;
        *(f32 *)(vec_d + 0x08) = fparg2;
        RwMatrixTranslate(matrix, vec_d, 2);
        func_0047a1c0(var_16, matrix, 0);
        color[0] = arg1 >> 0x18;
        color[1] = arg1 >> 0x10;
        color[2] = arg1 >> 8;
        color[3] = arg1;
        if (arg3 & 1) {
            *(s32 *)(var_16 + 0xD8) |= 8;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~8;
        }
        if (arg3 & 2) {
            *(s32 *)(var_16 + 0xD8) |= 0x10;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x10;
        }
        if (arg3 & 0x10) {
            *(s32 *)(var_16 + 0xD8) |= 0x100000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x100000;
        }
        if (arg3 & 0x40) {
            *(s32 *)(var_16 + 0xD8) |= 0x40000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x40000;
        }
        if (!(arg3 & 0x10000)) {
            func_00478e70(var_16);
        }
        func_00124970(arg0, arg2, arg3 | 2, arg4);
        func_002ab550(var_16, color);
        func_00124970(arg0, arg2, arg3 | 1, arg4);
    }
}
#pragma opt_propagation on
#pragma pop
/* Floor: 844 differing words (was 900), 967 of 964 instrs (+3, +0.3% well inside 3% band, 26 slack to 993 edge; was 993/+29 edge), 932 fnalign edits (was 1077). Surplus was 6 extra clamped float->u8 (cvt.w.s/mfc1 +12, c.ole/sub/bc1t +6, lui +6) from double-converting white via f intermediates + a2; fix is u32 r/g/b for retail's unsigned bltz/srl doubling, a0 as (s32)(f32)*(s32 *) for lwc1/cvt.s.w/cvt.w.s/mfc1, and 5 of 6 f intermediates folded to direct sums (first f0 double retained to center count). Cheap causes ruled out: all literals f-suffixed, 13 jals both with no __ soft-float relocs, no 2.0f in body (mul.s 3/3). Gate 8 inside 0 outside. Body also at docs/probe_archive/Lane0012_00124f70_body.c; production stays ASM. */
/* measured 2026-09-18: reconstructed from bare marker (retail 0x00124F70, 3856B window, 964 instrs). v1c baseline 921 (Ghidra-direct, [6] frame exact at 0x360; [8] gave 0x370 at 922). v2 908 (-13: D_5530/40 array not scalar + 002aaf20 640/448 not 512/480,512/1216). v3 904 (-4: flag beqz polarity + col order + buffers address-ascending). v4 903 (-1: buffers descending, first-declared highest per micro stacktest2). v5 900 (-3: explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals, first two spill to 0xA0/0xB0). Free pragmas tie/worse: loopinv 922 (+1), nounroll 921 tie, sched 921 tie, propoff 943 (+22), commonsubs 940 (+19). 7o eight skipped: body already in 7o form (bare decls + statement assigns, no Type name = ...; initialisers). Full proof in archive. */
/* Title palettes contain six complete four-byte RGBA values. Native value
 * assignment through the byte-storage view preserves the copied object.
 * Measured: 3852/3856 bytes, with one zero alignment word. */

typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;
typedef char TitleDrawColorSizeCheck[sizeof(TitleDrawColor) == 4 ? 1 : -1];
static inline u8 *titleCopyValue(u8 *destination, const u8 *source)
{
    *(TitleDrawColor *)destination = *(const TitleDrawColor *)source;
    return destination;
}

static inline void titleRectangle(u8 *color, f32 x, f32 y, f32 depth, f32 width, f32 height, s32 flags, void *parent)
{
    extern void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *parent);
    func_002aaf20(x, y, depth, color, width, height, flags, parent);
}
static inline f32 titleBlend(f32 delta, f32 blend, f32 value)
{
    return value + delta * blend;
}

static inline u8 titlePaletteChannel(u32 value, u32 target, f32 blend)
{
    return (u8)titleBlend((f32)(target - value), blend, (f32)value);
}

typedef struct { u32 words[6]; } TitlePalette;
typedef char TitlePaletteSizeCheck[sizeof(TitlePalette) == 24 ? 1 : -1];
static inline void titlePaletteCopy(TitlePalette *destination, const TitlePalette *source)
{
    const s32 *src = (const s32 *)source->words;
    s32 *dst = (s32 *)destination->words;
    s32 count = 3;
    do {
        s32 first = src[0];
        s32 second = src[1];
        src += 2;
        count--;
        dst[0] = first;
        dst[1] = second;
        dst += 2;
    } while (count > 0);
}

static inline u32 titleCopySelect(u8 *destination, const u8 *source, s32 byteOffset)
{
    *(TitlePalette *)destination = *(const TitlePalette *)source;
    return *(u32 *)(destination + byteOffset);
}


#pragma push
#pragma always_inline on
// FUN_00124F70
void func_00124f70(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext)
{
    extern void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *parent);
    extern s32 func_0025f3f0(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha,
        s32 spriteIndex, s32 frame, u8 *sprites, s32 flags);
    extern void func_002aaac0(void);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void func_00124bb0(s32 modelIndex, f32 x, f32 y, f32 z,
        f32 pitch, f32 yaw, f32 roll, u32 baseColor, u32 highlightColor,
        f32 scale, s32 flags, u32 *models);
    extern TitlePalette D_005E5530;
    extern u8 D_005E5230[];
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5244[];
    extern u8 D_005E5248[];
    extern u8 D_005E524C[];
    TitlePalette flatRed;
    TitlePalette flatGreen;
    TitlePalette flatBlue;
    TitlePalette flatAlpha;
    TitlePalette shadeRed;
    TitlePalette shadeGreen;
    TitlePalette shadeBlue;
    TitlePalette shadeAlpha;
    TitlePalette opacityRed;
    TitlePalette opacityGreen;
    TitlePalette opacityBlue;
    TitlePalette opacityAlpha;
    TitlePalette firstHighlight;
    TitlePalette firstBase;
    TitlePalette secondHighlight;
    TitlePalette secondBase;
    TitlePalette firstPalette;
    TitlePalette secondPalette;
    TitlePalette flatPalette;
    TitlePalette shadePalette;
    TitlePalette opacityPalette;
    TitleDrawColor color;
    TitleDrawColor zero;
    u8 *clearByte;
    s32 clearCount;
    s32 layoutOffset;
    s32 *paletteSelection;
    s32 paletteOffset;
    u32 packedColor;
    u32 packedBaseColor;
    u32 red;
    u32 green;
    u32 blue;
    u8 *xField;
    u8 *modelIndexField;
    u8 *scaleField;
    u8 *rollField;
    u8 *yawField;
    u8 *pitchField;
    u8 *zField;
    s32 modelFlags;
    (void)unusedArgument;
    if (drawMode != 0) {
        modelFlags = 0;
    } else {
        modelFlags = 0x10000;
    }
    clearByte = zero.bytes;
    clearCount = 4;
    if (clearByte != NULL) {
        do {
            *clearByte = 0;
            clearByte++;
            clearCount--;
        } while (clearCount != 0);
    }
    titleRectangle(titleCopyValue((u8 *)&color, (const u8 *)&zero), 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, NULL);
    /* Each value copy preserves all six RGBA palette entries. */
    firstPalette = D_005E5530;
    titlePaletteCopy(&firstHighlight, &firstPalette);
    layoutOffset = titleIndex * 0x28;
    paletteSelection = (s32 *)(D_005E524C + layoutOffset);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)((u8 *)firstHighlight.words + paletteOffset);
    packedBaseColor = titleCopySelect((u8 *)&firstBase, (const u8 *)&firstPalette, paletteOffset);
    scaleField = D_005E5248 + layoutOffset;
    green = (packedColor >> 0x10) & 0xFF;
    red = (packedColor >> 0x18) & 0xFF;
    blue = (packedColor >> 8) & 0xFF;
    rollField = D_005E5244 + layoutOffset;
    yawField = D_005E5240 + layoutOffset;
    pitchField = D_005E523C + layoutOffset;
    zField = D_005E5238 + layoutOffset;
    xField = D_005E5234 + layoutOffset;
    modelIndexField = D_005E5230 + layoutOffset;
    {
        s32 a0 = (s32)(f32)*(s32 *)modelIndexField;
        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
        func_00124bb0(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, 0x10052, (u32 *)sceneContext);
    }
    secondPalette = D_005E5530;
    titlePaletteCopy(&secondHighlight, &secondPalette);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)((u8 *)secondHighlight.words + paletteOffset);
    packedBaseColor = titleCopySelect((u8 *)&secondBase, (const u8 *)&secondPalette, paletteOffset);
    green = (packedColor >> 0x10) & 0xFF;
    red = (packedColor >> 0x18) & 0xFF;
    blue = (packedColor >> 8) & 0xFF;
    {
        s32 a0 = (s32)(f32)*(s32 *)modelIndexField;
        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
        func_00124bb0(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, modelFlags | 0x12, (u32 *)sceneContext);
    }
    flatPalette = D_005E5530;
    titlePaletteCopy(&flatRed, &flatPalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)((u8 *)flatRed.words + paletteOffset) >> 0x18);
    color.bytes[1] = (u8)(titleCopySelect((u8 *)&flatGreen, (const u8 *)&flatPalette, paletteOffset) >> 0x10);
    color.bytes[2] = (u8)(titleCopySelect((u8 *)&flatBlue, (const u8 *)&flatPalette, paletteOffset) >> 8);
    color.bytes[3] = (u8)titleCopySelect((u8 *)&flatAlpha, (const u8 *)&flatPalette, paletteOffset);
    color.bytes[0] = (u8)brightness;
    color.bytes[1] = (u8)brightness;
    color.bytes[2] = (u8)brightness;
    func_002aaac0();
    RpSkyRenderStateSet(3, (void *)0x53001);
    RpSkyRenderStateSet(2, (void *)0x52);
    {
        u32 c = brightness & 0xFF;
        u32 rep = (c << 24) | (c << 16) | (c << 8) | 0xFF;
        func_0025f3f0(-1.0f, -1.0f, 0.0f, rep >> 8, 0xFF, 0, 0, (u8 *)(*(s32 *)(sceneContext + 0x3C)), 0);
    }
    /* Preserve sequential byte stores while applying RGB brightness. */
    shadePalette = D_005E5530;
    titlePaletteCopy(&shadeRed, &shadePalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)((u8 *)shadeRed.words + paletteOffset) >> 0x18);
    color.bytes[1] = (u8)(titleCopySelect((u8 *)&shadeGreen, (const u8 *)&shadePalette, paletteOffset) >> 0x10);
    color.bytes[2] = (u8)(titleCopySelect((u8 *)&shadeBlue, (const u8 *)&shadePalette, paletteOffset) >> 8);
    color.bytes[3] = (u8)titleCopySelect((u8 *)&shadeAlpha, (const u8 *)&shadePalette, paletteOffset);
    {
        f32 base = (f32)brightness / 255.0f;
        color.bytes[0] = (u8)((f32)color.bytes[0] * base);
        color.bytes[1] = (u8)((f32)color.bytes[1] * base);
        color.bytes[2] = (u8)((f32)color.bytes[2] * base);
    }
    func_002aaac0();
    RpSkyRenderStateSet(3, (void *)0x53001);
    RpSkyRenderStateSet(2, (void *)0x58);
    func_002aaf20(0.0f, 0.0f, 0.0f, (u8 *)color.bytes, 640.0f, 448.0f, 0x300, NULL);
    /* Retail ORs the full brightness word into the selected color. */
    opacityPalette = D_005E5530;
    titlePaletteCopy(&opacityRed, &opacityPalette);
    paletteOffset = *paletteSelection * 4;
    {
        u32 w0 = *(u32 *)((u8 *)opacityRed.words + paletteOffset);
        color.bytes[0] = (u8)(((u32)brightness | (w0 & 0xFFFFFF00)) >> 0x18);
    }
    {
        u32 w1 = titleCopySelect((u8 *)&opacityGreen, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[1] = (u8)(((u32)brightness | (w1 & 0xFFFFFF00)) >> 0x10);
    }
    {
        u32 w2 = titleCopySelect((u8 *)&opacityBlue, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[2] = (u8)(((u32)brightness | (w2 & 0xFFFFFF00)) >> 8);
    }
    {
        u32 w3 = titleCopySelect((u8 *)&opacityAlpha, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[3] = (u8)((u32)brightness | (w3 & 0xFFFFFF00));
    }
    func_002aaac0();
    func_002aaf20(0.0f, 0.0f, 1.0f, (u8 *)color.bytes, 640.0f, 448.0f, 1, NULL);
}
#pragma pop
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern void func_002aaac0(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 D_005E55E0[];
extern s8 D_005E5610[];
extern void (*D_00887300[])(s32 arg0, s32 arg1);

// FUN_00125E80
void func_00125e80(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1)
{
    u8 spCC[4];
    PrimPointRow sp90[6];
    s8 sp70[0x20];
    PrimFloat2 sp40[6];
    s32 *src;
    PrimPointRow *dst;
    s32 count;
    s32 temp1;
    s32 temp2;
    s8 *src8;
    s8 *dst8;
    s32 count8;
    s8 temp8_1;
    s8 temp8_2;
    u8 *p;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    f32 *out;
    PrimPointRow *in;

    src = D_005E55E0;
    dst = sp90;
    count = 6;
    do {
        temp1 = src[0];
        temp2 = src[1];
        src += 2;
        count--;
        dst->words.w0 = temp1;
        dst->words.w1 = temp2;
        dst++;
    } while (count > 0);

    src8 = D_005E5610;
    dst8 = sp70;
    count8 = 0xC;
    do {
        temp8_1 = src8[0];
        temp8_2 = src8[1];
        src8 += 2;
        count8--;
        dst8[0] = temp8_1;
        dst8[1] = temp8_2;
        dst8 += 2;
    } while (count8 > 0);

    p = spCC;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }

    func_00489f80();
    func_0025f3f0(0.0f, 0.0f, fparg2, 0xFFFFFF, arg0 & 0xFF, 0x1000D, 0, (u8 *)(*(s32 *)(arg1 + 0x3C)), 1);
    func_0048a000();

    i = 0;
    x = -100.0f + fparg0;
    y = -200.0f + fparg1;
    while ((u32)i < 6) {
        in = &sp90[i];
        out = sp40[i].v;
        out[0] = x + in->point.v[0];
        out[1] = y + in->point.v[1];
        i++;
    }

    func_002aaac0();
    D_00887300[0](6, 1);
    RpSkyRenderStateSet(3, 0x5000D);
    RpSkyRenderStateSet(2, 0x58);
    func_0045e6a0(sp70, sp40, fparg2, 6, 4, 0, 0, 0,
                  -20.0f, 1.0f, 1.0f);
}
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);
extern s32 func_0025f430(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5,
                         s16 arg6, s16 arg7, f32 farg3, f32 farg5, f32 farg4);

extern void func_002aaac0(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
typedef struct { u8 c0, c1, c2, c3; } __attribute__((aligned(4))) TitleColor;
typedef struct { s128 bits; } TitleRect;
extern TitleRect D_005E5590;
extern TitleRect D_005E55A0;

static inline void titleRing(f32 x, f32 y, s32 color, f32 scale, f32 angle, u8 *texture)
{
    f32 size = 64.0f * scale;

    func_0025f430(x - size, y - size, 0.0f, color, 0x80, 0x1000F, 0, texture, 0, (s16)size, (s16)size, angle,
                  scale, scale);
}

/* 1288/1296 bytes (two words of padding); relocations: D_005E5590,
   D_005E55A0, this function's literal pool at gp-0x7DD0..-0x7D64, and the
   called functions.  The eight rings share one inline shape: size is
   64 * scale, the position is the centre minus size, and b210 folds each
   product and difference into the pool (radius, x, y, scale per ring) while
   still converting the radius at run time.  The screen colour and the two
   rectangles are copied into scratch locals declared ahead of their
   sources, which is what fixes retail's frame slots (0x7C/0x60 above
   0x78/0x74/0x70 and 0x50/0x40). */
/* The caller passes 0.0f in $f12-$f14 ahead of the colour and task
   (retail func_001265a0); the three floats are unused here. */
// FUN_00126090
void func_00126090(f32 x, f32 y, f32 depth, s32 arg0, u8 *arg1)
{
    TitleColor fillColor;
    TitleColor black;
    TitleColor shade;
    TitleColor clear;
    TitleRect rect;
    TitleRect upper;
    TitleRect lower;
    s32 frame;
    f32 phase;
    f32 angle;
    u8 *p;
    s32 n;

    p = (u8 *)&black;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    fillColor = black;
    titleRectangle((u8 *)&fillColor, 0.0f, 0.0f, 0.0f, 640.0f, 480.0f, 0x12, NULL);
    func_00489f80();
    func_0025f3f0(0.0f, 0.0f, 0.0f, 0xFFFFFF, arg0 & 0xFF, 0x1000C, 0, (u8 *)(*(s32 *)(arg1 + 0x3C)), 1);
    func_0048a000();
    func_00489f80();
    p = (u8 *)&clear;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    clear.c3 = 0;
    shade = clear;
    upper.bits = D_005E5590.bits;
    rect = upper;
    func_0045d6e0(&shade, &rect, 0.0f, 0);
    lower.bits = D_005E55A0.bits;
    rect = lower;
    func_0045d6e0(&shade, &rect, 0.0f, 0);
    func_0048a000();
    frame = *(s32 *)(arg1 + 0x80) + 1;
    *(s32 *)(arg1 + 0x80) = frame;
    if (frame >= 200) {
        *(s32 *)(arg1 + 0x80) = 0;
    }
    phase = (f32)*(s32 *)(arg1 + 0x80) / 200.0f;
    func_002aaac0();
    RpSkyRenderStateSet(3, 0x53001);
    RpSkyRenderStateSet(2, 0x58);
    angle = 360.0f * phase;
    titleRing(35.0f, 152.0f, 0x202020, 2.4f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(233.0f, 102.0f, 0x808080, 1.8f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(377.0f, 93.0f, 0x808080, 1.4f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(626.0f, 110.0f, 0x808080, 1.1f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    angle = -360.0f * phase;
    titleRing(35.0f, 152.0f, 0x808080, 2.2f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(233.0f, 102.0f, 0x808080, 1.45f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(377.0f, 93.0f, 0x808080, 1.0f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(626.0f, 110.0f, 0x808080, 1.55f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
}
/* measured: archived build/func_001265a0_floor_v1.c (1791L m2c) + jtbl-bound fix cases 10-15 to tail per ELF jtbl_00746730 dump at file-off 0x6467B0 (16 entries 0:26660,1-2:26664,3:26688,4-5:2679C,6-7:29778,8-9:2A024,10-15:2A948 tail; sltiu 0xa->0x10 exact). Installed fnalign retail 4404/object 4404 (exact, 0.0%, 80 edits +124 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0012.c func_001265a0`; probe 3842 words via measure_guarded. Candidate-method fnalign (--candidate floor) reports retail 4400/object 3779 (-14.1%, 6325 edits) due to scratch-vs-real TU compilation difference (header/guard placement), not body quality; installed is exact. Call census: all 202 retail jals +14 jalr have counterparts (30x0045d6e0,22x0025f3f0,17x0044b7b0,14x003f6440/002aaf20/002aaac0,11x0048a000/00489f80,etc.). Loops: 40 retail backward branches (30x6-instr zeroing +8x8-instr bgtz copy +3 large 414/240/240 at 0x126D9C/0x12742C/0x129B0C) all present as draft loop_93/loop_128/loop_351 + 4-word do-whiles. Frame -0x6C0 exact, sltiu 0x10 exact. Residual 80 edits are lui symbol materialization (0x5e vs 0) + MMI lq/add_a.w vs plain + VU0 adda/madd + scheduling, no missing regions by address (no deletes in installed alignment). */
/* gate: func_001265a0 is INSIDE the +-3% band at 4404 against retail 4404 (+0.0%, band
   4272-4536), deficit 0, via --candidate measurement 2026-09-20.  Filled the 46-run
   (0x12A794-0x12A84C) that deficit_scan named ABSENT: the empty-if at 0x12A7F4 is the
   same defect as its 0x12A794 neighbour - retail's 0.25f normalization
   ((f32)(0x20<<16)+0.25f*(f32)((0x20-0x24)<<16)-(f32)0x28), (s32) compare, recomputed $3
   ((f32)$2+$f1), and 32.0f*((f32)$3/65535.0f)+327.0f madd for the first 0x10006
   func_0025f3f0 call, which m2c had left as an empty if plus blend/0.0f args.  The 46
   dissolves into small register-color replaces; deficit_scan now reports only CROSS runs
   (2350 at 0x127930, 142 at 0x129E18, 48 at 0x12A6F8) with mtc1 +207/lui +108/sb +40.
   Prior stamp described 4348/4400 -1.2% deficit 52 (15 color channels + quantized factor;
   159-run and 104-run dissolved; 2350/142/46 phantoms + sb+40/lwc1+37/empty-if gaps) and
   3779/-14.1% floor, kept for history.  Candidate fnalign is 6509 edits +15 reloc-only,
   probe 3903 words (base 3899); installed TU stays 74 MATCH/8 ASM with func_0012d630
   untouched.  The old 4404/4404 +0.0% 80-edit number came from running `fnalign.py
   <file> <func>` with NO --candidate on this guarded floor, which compiles the
   INCLUDE_ASM fallback and therefore aligns retail against itself; fnalign now refuses
   that invocation outright and tests/test_fnalign.py pins it. */
/* fix 2026-09-20: old 4404/4404 was two errors cancelling, not evidence the body was right. */
/* Historical count-only experiments used the wrong alpha-scratch value for
 * temp_10. Retail 0x1291FC keeps 137.0f * scale in f2 while f0 converts alpha;
 * 0x129268 then converts f2 and narrows its signed integer to 16 bits. The
 * guarded source now preserves that independent value flow, not just width.
 * The adjacent scale uses separate mul.s/add.s rounding. Other upstream
 * ACC placeholders remain outside this bounded sprite-alpha repair. */
/* measured 2026-09-29: canonical TitleRect payload reads compile the guarded
 * body to 17072/17616 bytes, nd 3941. Earlier scores above are historical;
 * this body remains assembly-backed.
   2026-10-08: opt_lifetimes on lowers fnalign from 3558 to 3424 edits. */
/* 2026-10-09: 3424 -> 3340 edits: m2c's expanded float-to-unsigned conversions are plain (u32) casts. Open, found by comparing the retail lui constants: the m2c body drops several sinf results and leaves `temp_f20 * temp_f21 +/- temp_f7 * temp_f8` placeholders where retail has adda/madd chains with constants such as 200 - 700 * (1 - (1 + sin) / 2) (0x00126C48). */
/* 2026-10-09: 3340 -> 3069 edits. Restored three dropped MAC expressions from retail: the title glow calls (func_00125e80 at 0xB2/0x99: 200 - 700 * (1 - (1 + sin) / 2); at 0xFF: 200 - 700 * sin), the four func_002abb30 glow layers (x/y from D_005E5234/D_005E5238 advanced by 200/250 * (1 - sin), offsets 49/33, 24/12, 9/5, 0), and the /45 fade alpha 255 * (fGpffff822c + fGpffff8228 * (1 - sin)). func_002abb30/func_002ab380 use their titleVisual.c float-first prototypes. Open: the palette blocks still pass m2c placeholders for func_00124bb0's lerped position (A + t * (B - A) over D_005E5370/D_005E5398/D_005E53C0 records); keep the `temp_one` locals, since b210 folds a literal * 1.0f.
 * 3071: D_005E538C/D_005E53B4 are absolute in retail (lui/lw %lo); declared as
 * arrays so b210 does not place them in small data.
 * 5454: the 28 rectangle copies go through TitleRect locals (retail stores each
 * constant to the m2c-named slot, then copies it; the s128 form let b210 delete
 * the first store). Locals now sit at retail's offsets plus the 0x30 of three
 * extra saved registers (frame 0x6D0 vs 0x6C0; was 0x510).
 * 2604: with the rectangle temporaries in place, opt_common_subs off gives retail's
 * saved-register set (s0-s5, f20-f24); CSE was holding repeated loads in extra
 * saved registers.
 * 2550: the background colour constants also go through TitleDrawColor locals
 * (sp6B4..sp68C) before the copy into sp6BC, as retail stores them; the frame is
 * now retail's 0x6C0.
 * 2452: sp694 is the same colour intermediate.
 * 2418: the model-draw floats are block-scoped, declared in retail's colour order.
 * 2497: the two palette-glow calls pass the lerped record position
 * A + t * (B - A) over D_005E5370 -> D_005E5398 and D_005E5398 -> D_005E53C0,
 * with t the sinf result the old body discarded (retail adda/madd with f20 = t);
 * m2c's placeholder read stale temp_f20/f21/f7/f8.
 * 2503: the 0x5B..0x64 position call passes 159 + 36*s, 87 - 15*s (retail
 * adda/madd on the sinf result s); the alpha is 255*s without m2c's int round trip.
 * 3022: the two 0x1000E glow calls pass -82 + 160*t and -51 + 60*t (retail
 * adda/madd with f20 = temp_f20_5) and the gp scale without an int round trip.
 * Saved FPRs drop from f20-f28 to f20-f26 (retail f20-f24); the frame is 0x10
 * short until the remaining placeholders are rebuilt.
 * 2954: the last m2c placeholders are rebuilt: the 81.0 call passes
 * 52 + 246*(1 - r) with alpha 255*r, and the scroll step converts
 * (x<<16 - pos) + 0.5*((x - y)<<16) to int once (retail cvt.w.s into s0) for
 * func_0043c6a0 and the half step. Saved FPRs are now retail's f20-f24.
 * 2949: the sinf results are floats; m2c's (f32)(s32) round trips are gone.
 * (fGpffff8094 is loaded directly, as retail)
 * 2942: the 0xFF alpha converts a float at run time (retail cvt with the
 * 0x4F000000 check), so it goes through temp_f1_11.
 * 2595: retail keeps 0xFFFFFF in $s2: `white` is set at the top of each first
 * fade branch and reused by the eight later case-4/5 draw calls (the 0x1000E
 * calls use the literal). Prologue and frame now match retail.
 * 2098: opt_propagation off (retail keeps the hoisted record-id conversions
 * glowId0..4 ahead of the colour lerps instead of sinking them into the call).
 * 1897: the palette-glow calls read the from-record fields D_005E5374.. into
 * glowFrom locals ahead of the colour lerps (retail loads them early), the
 * to-record fields by their own symbols, and the colour components convert
 * float -> u8 directly (retail masks in both conversion arms).
 * 1891: the record id converts after the from-field loads, as retail.
 * 1860: retail keeps the function-table address in $s1 across each (8,1)/(6,1)
 * call pair (fnTable) and the 268/361 label position in f20/f21 (titlePosX/Y,
 * set in both branches and reused by the 0x1000A calls).
 * 1848: titlePosY is declared first (retail f21 = y, f20 = x).
 * 1843: the three record loops are for loops (m2c goto form).
 * 1775: the task pointer is declared first (retail $s4).
 * 1665: the loop calls pack red|green into temp_9_* right after the green
 * channel, as retail (the final colour ORs blue<<8 onto it).
 * 1618: common-subexpression elimination and propagation are back to the
 * defaults (retail shares repeated constants inside one call, `mov.s $f13,$f12`).
 * The sprite pointer is read through a TitleTaskView member, which b210 does not
 * hoist as an address, and the blend state is a void * constant, as
 * RpSkyRenderStateSet's prototype takes.
 * (with CSE on, b210 itself keeps 0xFFFFFF, the 268/361 position and the record
 * ids in registers; the explicit white/titlePos/glowId locals are gone)
 * 1512: all task fields are TitleTaskView members (b210 hoists M2C_FIELD
 * address arithmetic into saved registers; retail does not).
 * 1496: the alpha arguments convert float -> u8 directly.
 * 1469: each 0x1000E call converts the float alpha itself.
 * (the from-record fields are read in place; with propagation on the glowFrom
 * locals made no difference)
 * 1441: the fade fractions f88/20 and timer/20 are computed first, as retail.
 * 1434: fadeT holds the case-6/7 fraction; the alpha converts in the call.
 * 1401: the remaining alpha conversions happen inside the draw calls.
 * 842: the colour channels use the file's titlePaletteChannel helper (as the
 * matched func_00124f70 does) instead of m2c's expanded ACC sequence.
 * (blend 1.0f passed directly; the m2c temp_one/temp_cA/temp_cB locals are gone)
 *
 * (unused m2c declarations removed)
 * 429: the five palette-glow draws follow the matched func_00124f70 shape:
 * selected word through titleCopySelect, channels via titlePaletteChannel in one
 * packed expression, record id/base/colour as block locals.
 * (unused declarations removed)
 * 423: func_00126090 takes three trailing floats (retail callers load f12-f14
 * with zero; the callee ignores them), so the calls pass 0.0f in FPRs.
 * 412: the 137 * scale size converts inside the call (retail shares it via CSE).
 * 410: func_0043c6a0 takes an int (retail passes the converted step in $a0).
 * 409: the scroll target is (f20 << 16) + 0.25 * ((f20 - f24) << 16) (the old
 * body dropped the shift on the first term); retail multiplies and adds
 * separately.
 * 349: each rectangle is copied by a titleCopyValue-style inline that returns
 * the destination, so the argument address is formed before the copy (retail).
 * 341: 1 - fraction, then the 42 scale, as separate steps.
 * 342: the glow blend reads the 0x32-step sinf result (temp_f20_3); m2c had
 * left the stale temp_f20 there.
 * 330: declaration order for the loop counter and second glow sine (register colouring).
 * 324: the upper clamp is written `> 0x1E` (retail's slti $at form).
 * 313: model slot 0 is a TitleTaskView member.
 * 298: the remaining alpha bytes convert float -> u8 directly.
 * 285
 * 269: the fade texture lookup happens inside the draw call, after the alpha.
 * 262: the scroll delta and the rounded step share one int local (retail
 * evaluates the delta first).
 * 261: no explicit fnTable local; b210's CSE keeps the table address.
 * 217: the glow-loop record pointers index a TitleRecordBlock array (as
 * 0x28-byte records).
 * 209: each (8,1)/(6,1) call pair goes through a fnTable local (retail $s1).
 * 199: the table pointer is formed through an integer cast, so b210 keeps it
 * in $s1 for both calls instead of folding the first load.
 * (fade clamps written `> N`, retail's slti $at form; fadeT holds the timer fraction)
 * 162: range tests written `> N - 1` where retail uses the slti $at form.
 * 160: comparison constants in retail's form.
 * 145: conversion lever (var_19:(0, 2)).
 * 138: conversion lever (temp_10_2:(0, 2)).
 * 130: gp float constants written as literals.
 * sdiff 24/101 -> 22/99: (s32)(u32) around the row offset puts it before the field load, as retail.
 * sdiff 22/99 -> 20/98: the f28 word is read after the 0.25 blend term (retail's load order).
 * sdiff 20/98 -> 18/91: the 137 * size product is formed before the alpha, and 255 * (1 - t) is two steps (retail's constant order).
 * sdiff 18/91 -> 16/89: func_002ab380's texture slot is declared as a pointer (retail loads it in slot order; the (s32) cast was hoisted as a conversion).
 */
// FUN_001265A0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
typedef struct { u8 bytes[0x28]; } TitleRecordBlock;
static inline f32 *titleCopyRect(u8 *destination, const u8 *source)
{
    *(TitleRect *)destination = *(const TitleRect *)source;
    return (f32 *)destination;
}

typedef struct {
    u32 f00;
    u32 state;
    s32 f08;
    s32 timer;
    s32 f10;
    u8 pad0[0xc];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad1[0xc];
    u8 *sprites;
    u8 pad2[0x4];
    u8 *model0;
    u8 pad3[0x3c];
    u32 f84;
    s32 f88;
} TitleTaskView;
#include "btl_shuffle_draw_internal.h"
#define M2C_GUARD
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
/* The draw queue supplies node+0x1C, then the task stored at node+0x10.
 * Only the task reaches the word-returning work accessor; the first payload
 * is a real, unused callback input. See Title_entry_contract_001265a0_20261003. */
void func_001265a0(void *unusedDrawData, void *task) {
    f32 temp_f21;
    u32 *temp_20;
    TitleTaskView *taskView;
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    typedef union TitleRectangleWords { s128 bits; s32 words[4]; } TitleRectangleWords;
    extern s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern void func_002aaac0(void);
    extern void func_002ab380(f32 x, f32 y, f32 z, s32 color, s32 alpha, s32 mode, void *texture, s32 kind, void *extra);
    extern void func_002abb30(f32 x, f32 y, f32 z, s32 color, s32 alpha, f32 scale, s32 mode, u8 *object, void *extra);
    extern s32 RpSkyRenderStateSet();
    extern s32 func_00401b80(void);
    extern s32 func_0043c6a0(s32);
    extern f32 sinf(f32);
    extern u32 func_00452560(void *task);
    extern s32 func_00455f70();
    extern s32 func_0045ad50();
    extern void func_0045c870(u8 *colors, s32 enabled);
    extern void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
    extern s32 func_0046d730();
    extern s32 func_004782b0();
    extern s32 func_00478e70();
    extern void func_0047a0e0(u8 *model, s32 layer, f32 speed);
    extern s32 func_00489f80();
    extern s32 func_0048a000();
    extern u8 D_005E5230[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5248[];
    extern u8 D_005E5254[];
    extern s32 D_005E5370[];
    extern s32 D_005E538C[];
    extern s32 D_005E5398[];
    extern s32 D_005E53C0[];
    extern f32 D_005E5374[];
    extern f32 D_005E5378[];
    extern f32 D_005E537C[];
    extern f32 D_005E5380[];
    extern f32 D_005E5384[];
    extern f32 D_005E5388[];
    extern f32 D_005E539C[];
    extern f32 D_005E53A0[];
    extern f32 D_005E53A4[];
    extern f32 D_005E53A8[];
    extern f32 D_005E53AC[];
    extern f32 D_005E53B0[];
    extern f32 D_005E53C4[];
    extern f32 D_005E53C8[];
    extern f32 D_005E53CC[];
    extern f32 D_005E53D0[];
    extern f32 D_005E53D4[];
    extern f32 D_005E53D8[];
    extern s32 D_005E53B4[];
    extern TitlePalette D_005E5530;
    extern u8 D_005E5548[];
    extern BtlShuffleVec3 D_005E5628;
    extern BtlShuffleVec3 D_005E5638;
    extern s128 D_005E5650;
    extern s128 D_005E5660;
    extern s128 D_005E5670;
    extern s128 D_005E5680;
    extern s128 D_005E5690;
    extern s128 D_005E56A0;
    extern u32 D_005E56B0[8];
    extern u8 D_005E56D0[];
    extern void (*D_00887300[])(s32, s32);
    extern f32 fGpffff9c70;
    extern f32 fGpffff9c74;
    extern f32 fGpffff9c78;
    extern f32 fGpffff9c7c;
    extern f32 fGpffff9c80;
    extern f32 fGpffff9c84;
    extern f32 fGpffff9c88;
    extern f32 fGpffff9c8c;
    extern f32 fGpffff82a0;
    extern f32 fGpffff822c;
    extern f32 fGpffff8228;
    extern f32 fGpffff8170;
    extern f32 fGpffff8110;
    extern f32 fGpffff80bc;
    extern f32 fGpffff81e0;
    extern f32 fGpffff81dc;
    extern f32 fGpffff8094;
    s32 var_19;

    TitleDrawColor sp6BC;
    s32 sp6B8;
    TitleDrawColor sp6B4;
    TitleDrawColor sp6B0;
    TitleDrawColor sp6AC;
    TitleDrawColor sp6A8;
    TitleDrawColor sp6A4;
    TitleDrawColor sp6A0;
    TitleDrawColor sp69C;
    TitleDrawColor sp698;
    TitleDrawColor sp694;
    TitleDrawColor sp690;
    TitleDrawColor sp68C;
    TitleDrawColor layerColor;
    TitleDrawColor layerColorSource;
    TitleDrawColor firstOverlayColor;
    TitleDrawColor firstOverlaySource;
    TitleDrawColor sp678;
    TitleDrawColor sp674;
    TitleDrawColor sp670;
    TitleDrawColor sp66C;
    TitleDrawColor sp668;
    TitleDrawColor sp664;
    TitleDrawColor sp660;
    TitleDrawColor sp65C;
    TitleDrawColor sp658;
    TitleDrawColor sp654;
    TitleDrawColor sp650;
    TitleDrawColor sp64C;
    TitleDrawColor sp648;
    TitleDrawColor sp644;
    TitleDrawColor sp640;
    TitleDrawColor sp63C;
    TitleDrawColor sp638;
    TitleDrawColor sp634;
    TitleDrawColor sp630;
    TitleDrawColor sp62C;
    TitleDrawColor sp628;
    TitleDrawColor sp624;
    TitleDrawColor sp620;
    TitleDrawColor sp61C;
    TitleDrawColor sp618;
    TitleDrawColor sp614;
    TitleDrawColor sp610;
    TitleDrawColor sp60C;
    TitleDrawColor sp608;
    TitleDrawColor sp604;
    TitleDrawColor sp600;
    TitleDrawColor sp5FC;
    TitleDrawColor sp5F8;
    TitleDrawColor sp5F4;
    TitleDrawColor sp5F0;
    TitleDrawColor sp5EC;
    TitleDrawColor sp5E8;
    TitleDrawColor sp5E4;
    TitleDrawColor sp5E0;
    TitleDrawColor sp5DC;
    TitleDrawColor sp5D8;
    TitleDrawColor sp5D4;
    BtlShuffleVec3 titleYawAxis;
    BtlShuffleVec3 titlePitchAxis;
    BtlShuffleVec3 titleTranslation;
    s128 sp590;
    BtlShuffleMatrix titleMatrix __attribute__((aligned(16)));
    union { u32 words[8]; f32 pairs[4][2]; } fadeUv;
    u32 *fadeUvSource;
    u32 *fadeUvDestination;
    s32 fadeAlpha;
    TitleRectangleWords sp520;
    TitleRectangleWords sp510;
    TitleRect sp500;
    TitleRect sp4F0;
    TitleRect sp4E0;
    TitleRect sp4D0;
    s128 sp4C0;
    TitleRect sp4B0;
    TitleRect sp4A0;
    s128 sp490;
    TitleRect sp480;
    TitleRect sp470;
    TitlePalette firstHighlight;
    TitlePalette firstBase;
    TitlePalette thirdHighlight;
    TitlePalette thirdBase;
    TitlePalette fourthHighlight;
    TitlePalette fourthBase;
    s128 sp3A0;
    TitleRect sp390;
    TitleRect sp380;
    s128 sp370;
    TitleRect sp360;
    TitleRect sp350;
    s128 sp340;
    TitleRect sp330;
    TitleRect sp320;
    s128 sp310;
    TitleRect sp300;
    TitleRect sp2F0;
    s128 sp2E0;
    TitleRect sp2D0;
    TitleRect sp2C0;
    s128 sp2B0;
    TitleRect sp2A0;
    TitleRect sp290;
    s128 sp280;
    TitleRect sp270;
    TitleRect sp260;
    s128 sp250;
    TitleRect sp240;
    TitleRect sp230;
    s128 sp220;
    TitleRect sp210;
    TitleRect sp200;
    s128 sp1F0;
    TitleRect sp1E0;
    TitleRect sp1D0;
    TitlePalette secondHighlight;
    TitlePalette secondBase;
    TitlePalette fifthHighlight;
    TitlePalette fifthBase;
    TitlePalette firstPalette;
    TitlePalette secondPalette;
    TitlePalette thirdPalette;
    TitlePalette fourthPalette;
    TitlePalette fifthPalette;
    u8 *var_3_10;
    u8 *var_3_12;
    u8 *var_3_14;
    u8 *var_3_16;
    u8 *var_3_18;
    u8 *var_3_20;
    u8 *var_3_22;
    u8 *var_3_24;
    u8 *var_3_27;
    u8 *overlayClearByte;
    u8 *var_3_31;
    u8 *var_3_33;
    u8 *var_3_4;
    u8 *var_3_5;
    f32 lerpT;
    void (**fnTable)(s32, s32);
    s32 paletteOffset;
    u32 packedColor;
    u32 packedBaseColor;
    u32 red;
    u32 green;
    u32 blue;
    f32 fadeT;
    f32 temp_f0_11;
    f32 temp_f0_5;
    f32 temp_f0_7;
    f32 temp_f0_9;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_q1;
    f32 temp_f1_28;
    f32 temp_f13_28;
    f32 temp_f1_11;
    f32 temp_f1_17;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    u8 *layerClearByte;
    u8 *var_3_11;
    u8 *var_3_13;
    u8 *var_3_15;
    u8 *var_3_17;
    u8 *var_3_19;
    u8 *var_3_21;
    u8 *var_3_23;
    u8 *var_3_25;
    u8 *var_3_28;
    u8 *var_3_32;
    u8 *var_3_3;
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_19;
    s32 temp_2_24;
    s32 temp_2_26;
    u32 temp_2_27;
    s32 temp_2_2;
    s32 temp_3_19;
    s32 temp_3_20;
    s32 temp_3_21;
    u32 temp_3_22;
    s32 temp_3_23;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_5;
    s32 temp_f0_10;
    s32 temp_28;
    s32 temp_i28;
    s32 var_16;
    s32 var_17;
    s32 var_17_2;
    s32 layerClearCount;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_19;
    s32 var_2_20;
    s32 var_2_21;
    s32 var_2_22;
    s32 var_2_23;
    s32 var_2_24;
    s32 var_2_25;
    s32 var_2_26;
    s32 var_2_27;
    s32 var_2_28;
    s32 var_2_29;
    s32 overlayClearCount;
    s32 var_2_30;
    s32 var_2_31;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    s32 var_3_30;
    s32 var_4_17;
    s32 var_4_18;
    s32 temp_10;
    s32 temp_10_2;
    u32 var_3_26;
    u32 var_3_29;
    u32 *temp_2_11;
    u32 *temp_2_12;
    u32 *temp_2_23;
    u32 *temp_2_25;
    u32 *temp_2_3;
    u32 *temp_2_4;
    u32 temp_17_2;
    u32 temp_3;
    u8 *temp_21;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_7_5;
    u8 *var_16_2;
    u8 *var_4;
    u8 *var_4_16;
    u8 *var_4_2;
    u8 *var_4_7;
    u8 *var_4_8;
    u8 *var_4_9;

    temp_20 = (u32 *)func_00452560(task);
    taskView = (TitleTaskView *)temp_20;
    titleYawAxis = D_005E5628;
    titlePitchAxis = D_005E5638;
    sp6B8 = 0;
    sp6B4.value = fGpffff9c70;
    sp6BC = sp6B4;
    func_0045c870((u8 *)&sp6BC, 1);
    temp_3 = (u32)(taskView->state);
    switch (temp_3) {
    case 0:
        taskView->f88 = 0;
        /* fallthrough */
    case 1:
    case 2:
        sp6B0.value = fGpffff9c74;
        sp6BC = sp6B0;
        func_0045c870((u8 *)&sp6BC, 1);
        break;
    case 3:
        sp6AC.value = fGpffff9c78;
        sp6BC = sp6AC;
        func_0045c870((u8 *)&sp6BC, 1);
        temp_2 = (s32)(taskView->f88 + 1);
        taskView->f88 = temp_2;
        if (temp_2 >= 0x14) {
            taskView->f88 = 0x14;
        }
        temp_f20 = (f32) taskView->f88 / 20.0f;
        sp6A8.value = fGpffff9c7c;
        sp6BC = sp6A8;
        sp520.bits = D_005E5650;
        temp_f20 = 1.0f - temp_f20;
        temp_f20 = 42.0f * temp_f20;
        sp520.words[1] = (s32)-temp_f20;
        func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp520), 0.0f, 1);
        sp510.bits = D_005E5660;
        sp510.words[1] = (s32)(406.0f + temp_f20);
        func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp510), 0.0f, 1);
        break;
    case 4:
    case 5:
        temp_16 = (s32)(taskView->timer + 1);
        taskView->timer = temp_16;
        if (temp_16 > 0x19) {
            if (temp_16 < 0x74) {
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x4C, 0, 0, taskView->sprites, 0);
            } else if (temp_16 < 0xA1) {
                temp_f20_2 = sinf((1.5707964f * (f32) (temp_16 - 0x73)) / 45.0f);
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * (fGpffff822c + fGpffff8228 * (1.0f - temp_f20_2))), 0, 0, taskView->sprites, 0);
            } else {
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x2D, 0, 0, taskView->sprites, 0);
            }
            /* Retail colors at sp+0x684 and sp+0x688 are distinct four-byte objects. */
            layerClearByte = layerColorSource.bytes;
            layerClearCount = 4;
            if (layerClearByte != NULL) {
                do {
                    *layerClearByte = 0;
                    layerClearByte += 1;
                    layerClearCount -= 1;
                } while (layerClearCount != 0);
            }
            layerColorSource.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&layerColor, (const u8 *)&layerColorSource);
            {
                /* Retail passes depth in f12 and saveState in a2 at both calls. */
                extern void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
                sp4B0 = D_005E5590;
                func_0045d6e0((u8 *)&layerColor, titleCopyRect((u8 *)&sp4C0, (const u8 *)&sp4B0), 0.0f, 1);
                sp4A0 = D_005E55A0;
                func_0045d6e0((u8 *)&layerColor, titleCopyRect((u8 *)&sp4C0, (const u8 *)&sp4A0), 0.0f, 1);
            }
            func_00126090(0.0f, 0.0f, 0.0f, 0xFF, (u8 *)temp_20);
            if (temp_16 >= 0xCD) {
                /* Retail sp+0x67C is cleared bytewise before its independent value copy. */
                overlayClearByte = firstOverlaySource.bytes;
                overlayClearCount = 4;
                if (overlayClearByte != NULL) {
                    do {
                        *overlayClearByte = 0;
                        overlayClearByte += 1;
                        overlayClearCount -= 1;
                    } while (overlayClearCount != 0);
                }
                titleCopyValue((u8 *)&firstOverlayColor, (const u8 *)&firstOverlaySource);
                titleRectangle((u8 *)&firstOverlayColor, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_3 = sp624.bytes;
                var_2_3 = 4;
                if ((u8 *)(var_3_3) != NULL) {
                    do {
                        *var_3_3 = 0;
                        var_3_3 += 1;
                        var_2_3 -= 1;
                    } while (var_2_3 != 0);
                }
                sp624.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp628, (const u8 *)&sp624);
                sp480 = D_005E5590;
                func_0045d6e0((u8 *)&sp628, titleCopyRect((u8 *)&sp490, (const u8 *)&sp480), 0.0f, 0);
                sp470 = D_005E55A0;
                func_0045d6e0((u8 *)&sp628, titleCopyRect((u8 *)&sp490, (const u8 *)&sp470), 0.0f, 0);
                func_0048a000();
                temp_2_2 = (s32)(taskView->f10 + 1);
                taskView->f10 = temp_2_2;
                if (temp_2_2 >= 0x168) {
                    taskView->f10 = 0;
                }
                func_00125e80(200.0f - 700.0f * (1.0f - (1.0f + sinf((((fGpffff81dc + ((fGpffff81e0 * (f32) taskView->f10) / 360.0f)))))) / 2.0f), 0.0f, 10.0f, 0xB2, (u8 *)temp_20);
            }
            if (temp_16 > 0x3d) {
                if (temp_16 < 0x11A) {
                    var_3_4 = sp6A4.bytes;
                    var_2_4 = 4;
                    if (var_3_4 != NULL) {
                        do {
                            *var_3_4 = 0;
                            var_3_4 += 1;
                            var_2_4 -= 1;
                        } while (var_2_4 != 0);
                    }
                    titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp6A4);
                    titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, NULL);
                    sinf(((((1.5707964f * (f32) (temp_16 - 0x3D)) / 80.0f))));
                    for (var_19 = 1; (s32)var_19 < 8; var_19++) {
                        if ((u32) var_19 >= 0x13U) {
                            func_0046d730(D_005E5548, 0xD1);
                        }
                        temp_21 = (u8 *)&((TitleRecordBlock *)D_005E5230)[(s32)var_19];
                        var_17 = (s32)((s32)(u32)(temp_16 - 0x3D) - M2C_FIELD(temp_21, s32 *, 0x20));
                        if (var_17 > 0) {
                            var_2_5 = var_17 - 0x32;
                            if (var_2_5 < 0) {
                                var_2_5 = 0;
                            } else if (var_2_5 > 0x1E) {
                                var_2_5 = 0x1E;
                            }
                            temp_f20_3 = sinf(((((1.5707964f * (f32) var_2_5) / 30.0f))));
                            if (var_17 >= 0x32) {
                                var_17 = 0x32;
                            }
                            temp_f21 = sinf(((((1.5707964f * (f32) var_17) / 50.0f))));
                            if (var_17 == 1) {
                                temp_3_2 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_2 >= 0xF) {
                                    var_4 = NULL;
                                } else {
                                    temp_2_3 = (u32 *)(&temp_20[temp_3_2]);
                                    if (func_004782b0(M2C_FIELD(temp_2_3, u8 **, 0x44)) != 0) {
                                        var_4 = (u8 *)(M2C_FIELD(temp_2_3, u8 **, 0x44));
                                    } else {
                                        var_4 = NULL;
                                    }
                                }
                                if (var_4 != NULL) {
                                    func_00479940(var_4, 0, 1, 0, 1);
                                }
                            } else if (var_17 == 0x1E) {
                                temp_3_3 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_3 >= 0xF) {
                                    var_4_2 = NULL;
                                } else {
                                    temp_2_4 = (u32 *)(&temp_20[temp_3_3]);
                                    if (func_004782b0(M2C_FIELD(temp_2_4, u8 **, 0x44)) != 0) {
                                        var_4_2 = (u8 *)(M2C_FIELD(temp_2_4, u8 **, 0x44));
                                    } else {
                                        var_4_2 = NULL;
                                    }
                                }
                                if (var_4_2 != NULL) {
                                    func_00479940(var_4_2, 0, 0, 0x1E, 1);
                                }
                            }
                            if (temp_f21 < 1.0f) {
                                func_00124f70(var_19, (s32)(255.0f * temp_f21), 0, 1, (u8 *)temp_20);
                            } else {
                                var_3_5 = sp6A0.bytes;
                                var_2_6 = 4;
                                if (var_3_5 != NULL) {
                                    do {
                                        *var_3_5 = 0;
                                        var_3_5 += 1;
                                        var_2_6 -= 1;
                                    } while (var_2_6 != 0);
                                }
                                titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp6A0);
                                titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                                /* Six packed colors form one snapshot and two independent copies.
                                 * Model calls use the same-owner typed definition; special ACC
                                 * producers remain supplied/unproven expressions. */
                                firstPalette = D_005E5530;
                                titlePaletteCopy(&firstHighlight, &firstPalette);
                                temp_7 = (u8 *)&((TitleRecordBlock *)D_005E5230)[var_19];
                                paletteOffset = *(s32 *)(temp_7 + 0x1C) * 4;
                                packedColor = *(u32 *)((u8 *)firstHighlight.words + paletteOffset);
                                temp_q1 = (f32)(s32)(255.0f * temp_f20_3) / 255.0f;
                                packedBaseColor = titleCopySelect((u8 *)&firstBase, (const u8 *)&firstPalette, paletteOffset);
                                green = (packedColor >> 0x10) & 0xFF;
                                red = (packedColor >> 0x18) & 0xFF;
                                blue = (packedColor >> 8) & 0xFF;
                                {
                                    s32 a0 = (s32)((f32) M2C_FIELD(temp_7, s32 *, 0));
                                    u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                                    u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, temp_q1) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, temp_q1) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, temp_q1) << 8) | 0xFF;
                                    func_00124bb0(a0, M2C_FIELD(temp_7, f32 *, 4), 0.0f, M2C_FIELD(temp_7, f32 *, 8), M2C_FIELD(temp_7, f32 *, 0xC), M2C_FIELD(temp_7, f32 *, 0x10), M2C_FIELD(temp_7, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7, f32 *, 0x18), 0x42, temp_20);
                                }
                            }
                        }
                    }
                } else {
                    for (var_17_2 = 1; var_17_2 < 8; var_17_2++) {
                        secondPalette = D_005E5530;
                        titlePaletteCopy(&secondHighlight, &secondPalette);
                        temp_7_2 = D_005E5230 + var_17_2 * 0x28;
                        paletteOffset = *(s32 *)(temp_7_2 + 0x1C) * 4;
                        packedColor = *(u32 *)((u8 *)secondHighlight.words + paletteOffset);
                        packedBaseColor = titleCopySelect((u8 *)&secondBase, (const u8 *)&secondPalette, paletteOffset);
                        green = (packedColor >> 0x10) & 0xFF;
                        red = (packedColor >> 0x18) & 0xFF;
                        blue = (packedColor >> 8) & 0xFF;
                        {
                            s32 a0 = (s32)((f32) M2C_FIELD(temp_7_2, s32 *, 0));
                            u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                            u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                            func_00124bb0(a0, M2C_FIELD(temp_7_2, f32 *, 4), 0.0f, M2C_FIELD(temp_7_2, f32 *, 8), M2C_FIELD(temp_7_2, f32 *, 0xC), M2C_FIELD(temp_7_2, f32 *, 0x10), M2C_FIELD(temp_7_2, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7_2, f32 *, 0x18), 0x42, temp_20);
                        }
                    }
                }
            }
            if (temp_16 > 0x81) {
                if (temp_16 < 0xBE) {
                    temp_17 = temp_16 - 0x81;
                    lerpT = sinf(((((1.5707964f * (f32) temp_17) / 60.0f))));
                    if (temp_17 == 1) {
                        if (*(s32 *)D_005E5230 >= 0xF) {
                            var_4_7 = NULL;
                        } else {
                            temp_2_11 = (u32 *)(&temp_20[*(s32 *)D_005E5230]);
                            if (func_004782b0(M2C_FIELD(temp_2_11, u8 **, 0x44)) != 0) {
                                var_4_7 = (u8 *)(M2C_FIELD(temp_2_11, u8 **, 0x44));
                            } else {
                                var_4_7 = NULL;
                            }
                        }
                        if (var_4_7 != NULL) {
                            func_00479940(var_4_7, 0, 2, 0, 1);
                        }
                        if (func_004782b0(taskView->model0) != 0) {
                            var_4_8 = (u8 *)(taskView->model0);
                        } else {
                            var_4_8 = NULL;
                        }
                        func_0047a0e0(var_4_8, 0, fGpffff8110);
                    } else if (temp_17 == 0x3A) {
                        if (*(s32 *)D_005E5230 >= 0xF) {
                            var_4_9 = NULL;
                        } else {
                            temp_2_12 = (u32 *)(&temp_20[*(s32 *)D_005E5230]);
                            if (func_004782b0(M2C_FIELD(temp_2_12, u8 **, 0x44)) != 0) {
                                var_4_9 = (u8 *)(M2C_FIELD(temp_2_12, u8 **, 0x44));
                            } else {
                                var_4_9 = NULL;
                            }
                        }
                        if (var_4_9 != NULL) {
                            func_00479940(var_4_9, 0, 0, 0xF, 1);
                        }
                    }
                    thirdPalette = D_005E5530;
                    titlePaletteCopy(&thirdHighlight, &thirdPalette);
                    paletteOffset = D_005E538C[0] * 4;
                    packedColor = *(u32 *)((u8 *)thirdHighlight.words + paletteOffset);
                    packedBaseColor = titleCopySelect((u8 *)&thirdBase, (const u8 *)&thirdPalette, paletteOffset);
                    green = (packedColor >> 0x10) & 0xFF;
                    red = (packedColor >> 0x18) & 0xFF;
                    blue = (packedColor >> 8) & 0xFF;
                    {
                        s32 a0 = (s32)((f32) D_005E5370[0]);
                        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                        func_00124bb0(a0, (0.0f + D_005E5374[0] + lerpT * (D_005E539C[0] - D_005E5374[0])), 0.0f, (0.0f + D_005E5378[0] + lerpT * (D_005E53A0[0] - D_005E5378[0])), (0.0f + D_005E537C[0] + lerpT * (D_005E53A4[0] - D_005E537C[0])), (0.0f + D_005E5380[0] + lerpT * (D_005E53A8[0] - D_005E5380[0])), (0.0f + D_005E5384[0] + lerpT * (D_005E53AC[0] - D_005E5384[0])), a1, a2, (0.0f + D_005E5388[0] + lerpT * (D_005E53B0[0] - D_005E5388[0])), 0x40, temp_20);
                    }
                } else if (temp_16 < 0xD2) {
                    lerpT = sinf(((((1.5707964f * (f32) (temp_16 - 0xBD)) / 20.0f))));
                    fourthPalette = D_005E5530;
                    titlePaletteCopy(&fourthHighlight, &fourthPalette);
                    paletteOffset = D_005E53B4[0] * 4;
                    packedColor = *(u32 *)((u8 *)fourthHighlight.words + paletteOffset);
                    packedBaseColor = titleCopySelect((u8 *)&fourthBase, (const u8 *)&fourthPalette, paletteOffset);
                    green = (packedColor >> 0x10) & 0xFF;
                    red = (packedColor >> 0x18) & 0xFF;
                    blue = (packedColor >> 8) & 0xFF;
                    {
                        s32 a0 = (s32)((f32) D_005E5398[0]);
                        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                        func_00124bb0(a0, (0.0f + D_005E539C[0] + lerpT * (D_005E53C4[0] - D_005E539C[0])), 0.0f, (0.0f + D_005E53A0[0] + lerpT * (D_005E53C8[0] - D_005E53A0[0])), (0.0f + D_005E53A4[0] + lerpT * (D_005E53CC[0] - D_005E53A4[0])), (0.0f + D_005E53A8[0] + lerpT * (D_005E53D0[0] - D_005E53A8[0])), (0.0f + D_005E53AC[0] + lerpT * (D_005E53D4[0] - D_005E53AC[0])), a1, a2, (0.0f + D_005E53B0[0] + lerpT * (D_005E53D8[0] - D_005E53B0[0])), 0x40, temp_20);
                    }
                } else {
                    func_00124f70(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);
                }
            }
            if (temp_16 < 0x74) {
                temp_f20_4 = sinf(((((1.5707964f * (f32) (temp_16 - 0x19)) / 90.0f))));
                var_3_10 = sp674.bytes;
                var_2_7 = 4;
                if (var_3_10 != NULL) {
                    do {
                        *var_3_10 = 0;
                        var_3_10 += 1;
                        var_2_7 -= 1;
                    } while (var_2_7 != 0);
                }
                titleCopyValue((u8 *)&sp678, (const u8 *)&sp674);
                titleRectangle((u8 *)&sp678, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                func_00489f80();
                var_3_11 = sp61C.bytes;
                var_2_8 = 4;
                if ((u8 *)(var_3_11) != NULL) {
                    do {
                        *var_3_11 = 0;
                        var_3_11 += 1;
                        var_2_8 -= 1;
                    } while (var_2_8 != 0);
                }
                sp61C.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp620, (const u8 *)&sp61C);
                sp390 = D_005E5590;
                func_0045d6e0((u8 *)&sp620, titleCopyRect((u8 *)&sp3A0, (const u8 *)&sp390), 0.0f, 0);
                sp380 = D_005E55A0;
                func_0045d6e0((u8 *)&sp620, titleCopyRect((u8 *)&sp3A0, (const u8 *)&sp380), 0.0f, 0);
                func_0048a000();
                func_002aaac0();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(-1.0f, -1.0f, 10.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - temp_f20_4)), 0, 0, taskView->sprites, 0);
            }
            if (temp_16 == 0x55) {
                func_0045ad50(2, func_00455f70(&D_005E56D0, &sp6B8), sp6B8);
            }
            if (temp_16 > 0x5a) {
                if (temp_16 < 0x65) {
temp_f2 = sinf(((((1.5707964f * (f32) (temp_16 - 0x5A)) / 10.0f))));
    /* ACC seed */;
                    temp_f14 = 0.0f;
                    func_0025f430(159.0f + 36.0f * temp_f2, 87.0f + -15.0f * temp_f2, temp_f14, 0xFFFFFFU, (u8)(255.0f * temp_f2), 0x10001, 0, taskView->sprites, 1, 0, 0, temp_f14, 1.0f, 1.0f);
                } else {
                    func_0025f3f0(195.0f, 72.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10001, 0, taskView->sprites, 1);
                }
            }
            if ((temp_16 > 0xbb) && (temp_16 < 0xDF)) {
                temp_f2_2 = 1.5707964f;
                func_0025f3f0(195.0f, 72.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * sinf((((temp_f2_2 + ((temp_f2_2 * (f32) (temp_16 - 0xBB)) / 35.0f)))))), 0x10009, 0, taskView->sprites, 1);
            }
            if (temp_16 < 0x74) {
                var_3_12 = sp66C.bytes;
                var_2_9 = 4;
                if (var_3_12 != NULL) {
                    do {
                        *var_3_12 = 0;
                        var_3_12 += 1;
                        var_2_9 -= 1;
                    } while (var_2_9 != 0);
                }
                titleCopyValue((u8 *)&sp670, (const u8 *)&sp66C);
                titleRectangle((u8 *)&sp670, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_13 = sp614.bytes;
                var_2_10 = 4;
                if ((u8 *)(var_3_13) != NULL) {
                    do {
                        *var_3_13 = 0;
                        var_3_13 += 1;
                        var_2_10 -= 1;
                    } while (var_2_10 != 0);
                }
                sp614.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp618, (const u8 *)&sp614);
                sp360 = D_005E5590;
                func_0045d6e0((u8 *)&sp618, titleCopyRect((u8 *)&sp370, (const u8 *)&sp360), 0.0f, 0);
                sp350 = D_005E55A0;
                func_0045d6e0((u8 *)&sp618, titleCopyRect((u8 *)&sp370, (const u8 *)&sp350), 0.0f, 0);
                func_0048a000();
                func_0025f3f0(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
            } else {
                func_0025f3f0(268.0f, (f32) 0x169, 0.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
            }
            if (temp_16 < 0x56) {
                var_3_14 = sp664.bytes;
                var_2_11 = 4;
                if (var_3_14 != NULL) {
                    do {
                        *var_3_14 = 0;
                        var_3_14 += 1;
                        var_2_11 -= 1;
                    } while (var_2_11 != 0);
                }
                titleCopyValue((u8 *)&sp668, (const u8 *)&sp664);
                titleRectangle((u8 *)&sp668, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                func_00489f80();
                var_3_15 = sp60C.bytes;
                var_2_12 = 4;
                if ((u8 *)(var_3_15) != NULL) {
                    do {
                        *var_3_15 = 0;
                        var_3_15 += 1;
                        var_2_12 -= 1;
                    } while (var_2_12 != 0);
                }
                sp60C.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp610, (const u8 *)&sp60C);
                sp330 = D_005E5590;
                func_0045d6e0((u8 *)&sp610, titleCopyRect((u8 *)&sp340, (const u8 *)&sp330), 0.0f, 0);
                sp320 = D_005E55A0;
                func_0045d6e0((u8 *)&sp610, titleCopyRect((u8 *)&sp340, (const u8 *)&sp320), 0.0f, 0);
                func_0048a000();
                func_002aaac0();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, 0xFF, 0x1000A, 0, taskView->sprites, 0);
            } else if (temp_16 < 0x92) {
                var_3_16 = sp65C.bytes;
                var_2_13 = 4;
                if (var_3_16 != NULL) {
                    do {
                        *var_3_16 = 0;
                        var_3_16 += 1;
                        var_2_13 -= 1;
                    } while (var_2_13 != 0);
                }
                titleCopyValue((u8 *)&sp660, (const u8 *)&sp65C);
                titleRectangle((u8 *)&sp660, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                func_00489f80();
                var_3_17 = sp604.bytes;
                var_2_14 = 4;
                if ((u8 *)(var_3_17) != NULL) {
                    do {
                        *var_3_17 = 0;
                        var_3_17 += 1;
                        var_2_14 -= 1;
                    } while (var_2_14 != 0);
                }
                sp604.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp608, (const u8 *)&sp604);
                sp300 = D_005E5590;
                func_0045d6e0((u8 *)&sp608, titleCopyRect((u8 *)&sp310, (const u8 *)&sp300), 0.0f, 0);
                sp2F0 = D_005E55A0;
                func_0045d6e0((u8 *)&sp608, titleCopyRect((u8 *)&sp310, (const u8 *)&sp2F0), 0.0f, 0);
                func_0048a000();
                temp_f22 = sinf(((((1.5707964f * (f32) (temp_16 - 0x55)) / 60.0f))));
                func_002aaac0();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                func_0025f3f0(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - temp_f22)), 0x1000A, 0, taskView->sprites, 0);
            }
            if (temp_16 < 0x56) {
                var_3_18 = sp654.bytes;
                var_2_15 = 4;
                if (var_3_18 != NULL) {
                    do {
                        *var_3_18 = 0;
                        var_3_18 += 1;
                        var_2_15 -= 1;
                    } while (var_2_15 != 0);
                }
                titleCopyValue((u8 *)&sp658, (const u8 *)&sp654);
                titleRectangle((u8 *)&sp658, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_19 = sp5FC.bytes;
                var_2_16 = 4;
                if ((u8 *)(var_3_19) != NULL) {
                    do {
                        *var_3_19 = 0;
                        var_3_19 += 1;
                        var_2_16 -= 1;
                    } while (var_2_16 != 0);
                }
                sp5FC.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp600, (const u8 *)&sp5FC);
                sp2D0 = D_005E5590;
                func_0045d6e0((u8 *)&sp600, titleCopyRect((u8 *)&sp2E0, (const u8 *)&sp2D0), 0.0f, 0);
                sp2C0 = D_005E55A0;
                func_0045d6e0((u8 *)&sp600, titleCopyRect((u8 *)&sp2E0, (const u8 *)&sp2C0), 0.0f, 0);
                func_0048a000();
                func_00125e80(200.0f, 0.0f, 10.0f, 0xFF, (u8 *)temp_20);
            } else if (temp_16 < 0xCE) {
                var_3_20 = sp64C.bytes;
                var_2_17 = 4;
                if (var_3_20 != NULL) {
                    do {
                        *var_3_20 = 0;
                        var_3_20 += 1;
                        var_2_17 -= 1;
                    } while (var_2_17 != 0);
                }
                titleCopyValue((u8 *)&sp650, (const u8 *)&sp64C);
                titleRectangle((u8 *)&sp650, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_21 = sp5F4.bytes;
                var_2_18 = 4;
                if ((u8 *)(var_3_21) != NULL) {
                    do {
                        *var_3_21 = 0;
                        var_3_21 += 1;
                        var_2_18 -= 1;
                    } while (var_2_18 != 0);
                }
                sp5F4.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp5F8, (const u8 *)&sp5F4);
                sp2A0 = D_005E5590;
                func_0045d6e0((u8 *)&sp5F8, titleCopyRect((u8 *)&sp2B0, (const u8 *)&sp2A0), 0.0f, 0);
                sp290 = D_005E55A0;
                func_0045d6e0((u8 *)&sp5F8, titleCopyRect((u8 *)&sp2B0, (const u8 *)&sp290), 0.0f, 0);
                func_0048a000();
                func_00125e80(200.0f - 700.0f * sinf(((((1.5707964f * (f32) (temp_16 - 0x55)) / 120.0f)))), 0.0f, 10.0f, 0xFF, (u8 *)temp_20);
            }
            if (temp_16 < 0xE2) {
                var_3_22 = sp644.bytes;
                var_2_19 = 4;
                if (var_3_22 != NULL) {
                    do {
                        *var_3_22 = 0;
                        var_3_22 += 1;
                        var_2_19 -= 1;
                    } while (var_2_19 != 0);
                }
                titleCopyValue((u8 *)&sp648, (const u8 *)&sp644);
                titleRectangle((u8 *)&sp648, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_23 = sp5EC.bytes;
                var_2_20 = 4;
                if ((u8 *)(var_3_23) != NULL) {
                    do {
                        *var_3_23 = 0;
                        var_3_23 += 1;
                        var_2_20 -= 1;
                    } while (var_2_20 != 0);
                }
                sp5EC.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp5F0, (const u8 *)&sp5EC);
                sp270 = D_005E5590;
                func_0045d6e0((u8 *)&sp5F0, titleCopyRect((u8 *)&sp280, (const u8 *)&sp270), 0.0f, 0);
                sp260 = D_005E55A0;
                func_0045d6e0((u8 *)&sp5F0, titleCopyRect((u8 *)&sp280, (const u8 *)&sp260), 0.0f, 0);
                func_0048a000();
                temp_f20_5 = sinf((1.5707964f * (f32) temp_16) / 225.0f);
                if (temp_16 > 0x87) {
                    var_2_21 = temp_16 - 0x87;
                } else {
                    var_2_21 = 0;
                }
                temp_f21_2 = sinf((1.5707964f * (f32) var_2_21) / 90.0f);
                /* Keep the first return across the second call; round multiply and add separately. */
                temp_f16 = 1.5f * temp_f20_5;
                temp_f16 = fGpffff8170 + temp_f16;
                {
                    f32 size = 137.0f * temp_f16;

                    temp_f21_2 = 1.0f - temp_f21_2;
                    temp_f21_2 = 255.0f * temp_f21_2;
                    func_0025f430(-3.0f, -76.0f, 10.0f, 0xFFFFFFU, (u8)temp_f21_2, 0x1000E, 0, taskView->sprites, 1, (s16)size, (s16)size, -82.0f + 160.0f * temp_f20_5, temp_f16, temp_f16);
                }
    /* ACC seed */;
                temp_f16_2 = 1.3f;
                func_0025f430(-9.0f, 33.0f, 10.0f, 0xFFFFFFU, (u8)temp_f21_2, 0x1000E, 0, taskView->sprites, 1, 0x6B, 0xE6, -51.0f + 60.0f * temp_f20_5, temp_f16_2, temp_f16_2);
            }
        }
        if (temp_16 < 0x19) {
            var_3_24 = sp63C.bytes;
            var_2_22 = 4;
            if (var_3_24 != NULL) {
                do {
                    *var_3_24 = 0;
                    var_3_24 += 1;
                    var_2_22 -= 1;
                } while (var_2_22 != 0);
            }
            titleCopyValue((u8 *)&sp640, (const u8 *)&sp63C);
            titleRectangle((u8 *)&sp640, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
            func_002aaac0();
            D_00887300[0](8, 1);
            func_00489f80();
            var_3_25 = sp5E4.bytes;
            var_2_23 = 4;
            if ((u8 *)(var_3_25) != NULL) {
                do {
                    *var_3_25 = 0;
                    var_3_25 += 1;
                    var_2_23 -= 1;
                } while (var_2_23 != 0);
            }
            sp5E4.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&sp5E8, (const u8 *)&sp5E4);
            sp240 = D_005E5590;
            func_0045d6e0((u8 *)&sp5E8, titleCopyRect((u8 *)&sp250, (const u8 *)&sp240), 0.0f, 0);
            sp230 = D_005E55A0;
            func_0045d6e0((u8 *)&sp5E8, titleCopyRect((u8 *)&sp250, (const u8 *)&sp230), 0.0f, 0);
            func_0048a000();
            sp69C.value = fGpffff9c80;
            temp_f1_11 = 255.0f;
            var_3_26 = (u8)temp_f1_11;
            sp69C.bytes[3] = (u8)var_3_26;
            titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp69C);
            sp500 = *(TitleRect *)&D_005E5670;
            func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp500), 10.0f, 1);
        } else if (temp_16 < 0x56) {
            var_3_27 = sp634.bytes;
            var_2_24 = 4;
            if (var_3_27 != NULL) {
                do {
                    *var_3_27 = 0;
                    var_3_27 += 1;
                    var_2_24 -= 1;
                } while (var_2_24 != 0);
            }
            titleCopyValue((u8 *)&sp638, (const u8 *)&sp634);
            titleRectangle((u8 *)&sp638, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
            func_002aaac0();
            D_00887300[0](8, 1);
            func_00489f80();
            var_3_28 = sp5DC.bytes;
            var_2_25 = 4;
            if ((u8 *)(var_3_28) != NULL) {
                do {
                    *var_3_28 = 0;
                    var_3_28 += 1;
                    var_2_25 -= 1;
                } while (var_2_25 != 0);
            }
            sp5DC.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&sp5E0, (const u8 *)&sp5DC);
            sp210 = D_005E5590;
            func_0045d6e0((u8 *)&sp5E0, titleCopyRect((u8 *)&sp220, (const u8 *)&sp210), 0.0f, 0);
            sp200 = D_005E55A0;
            func_0045d6e0((u8 *)&sp5E0, titleCopyRect((u8 *)&sp220, (const u8 *)&sp200), 0.0f, 0);
            func_0048a000();
            temp_f2_3 = 1.5707964f;
            temp_f0_5 = sinf((((temp_f2_3 + ((temp_f2_3 * (f32) (temp_16 - 0x19)) / 60.0f)))));
            sp698.value = fGpffff9c84;
            temp_f1_11 = 255.0f * temp_f0_5;
            var_3_29 = (u8)temp_f1_11;
            sp698.bytes[3] = (u8)var_3_29;
            titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp698);
            sp4F0 = *(TitleRect *)&D_005E5680;
            func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4F0), 10.0f, 1);
        }
        break;
    case 6:
    case 7:
        var_3_30 = (s32)(taskView->timer + 1);
        taskView->timer = var_3_30;
        if (var_3_30 >= 0x14) {
            var_3_30 = 0x14;
        }
        fadeT = (f32) var_3_30 / 20.0f;
        func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
        RpSkyRenderStateSet(3, (void *)0x50003);
        RpSkyRenderStateSet(2, 0x48);
        func_0025f3f0(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x2D, 0, 0, taskView->sprites, 0);
        sp694.value = fGpffff9c88;
        sp6BC = sp694;
        sp4E0 = *(TitleRect *)&D_005E5690;
        func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4E0), 0.0f, 1);
        sp4D0 = *(TitleRect *)&D_005E56A0;
        func_0045d6e0((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4D0), 0.0f, 1);
        func_00126090(0.0f, 0.0f, 0.0f, 0xFF, (u8 *)temp_20);
        var_3_31 = sp62C.bytes;
        var_2_26 = 4;
        if (var_3_31 != NULL) {
            do {
                *var_3_31 = 0;
                var_3_31 += 1;
                var_2_26 -= 1;
            } while (var_2_26 != 0);
        }
        titleCopyValue((u8 *)&sp630, (const u8 *)&sp62C);
        titleRectangle((u8 *)&sp630, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
        func_002aaac0();
        D_00887300[0](8, 1);
        func_00489f80();
        var_3_32 = sp5D4.bytes;
        var_2_27 = 4;
        if ((u8 *)(var_3_32) != NULL) {
            do {
                *var_3_32 = 0;
                var_3_32 += 1;
                var_2_27 -= 1;
            } while (var_2_27 != 0);
        }
        sp5D4.bytes[3] = 0xFF;
        titleCopyValue((u8 *)&sp5D8, (const u8 *)&sp5D4);
        sp1E0 = D_005E5590;
        func_0045d6e0((u8 *)&sp5D8, titleCopyRect((u8 *)&sp1F0, (const u8 *)&sp1E0), 0.0f, 0);
        sp1D0 = D_005E55A0;
        func_0045d6e0((u8 *)&sp5D8, titleCopyRect((u8 *)&sp1F0, (const u8 *)&sp1D0), 0.0f, 0);
        func_0048a000();
        temp_2_19 = (s32)(taskView->f10 + 1);
        taskView->f10 = temp_2_19;
        if (temp_2_19 >= 0x168) {
            taskView->f10 = 0;
        }
        func_00125e80(200.0f - 700.0f * (1.0f - (1.0f + sinf((((fGpffff81dc + ((fGpffff81e0 * (f32) taskView->f10) / 360.0f)))))) / 2.0f), 0.0f, 10.0f, 0x99, (u8 *)temp_20);
        var_3_33 = sp690.bytes;
        var_2_28 = 4;
        if (var_3_33 != NULL) {
            do {
                *var_3_33 = 0;
                var_3_33 += 1;
                var_2_28 -= 1;
            } while (var_2_28 != 0);
        }
        titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp690);
        titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
        for (var_16 = 1; var_16 < 8; var_16++) {
            fifthPalette = D_005E5530;
            titlePaletteCopy(&fifthHighlight, &fifthPalette);
            temp_7_5 = D_005E5230 + var_16 * 0x28;
            paletteOffset = *(s32 *)(temp_7_5 + 0x1C) * 4;
            packedColor = *(u32 *)((u8 *)fifthHighlight.words + paletteOffset);
            packedBaseColor = titleCopySelect((u8 *)&fifthBase, (const u8 *)&fifthPalette, paletteOffset);
            green = (packedColor >> 0x10) & 0xFF;
            red = (packedColor >> 0x18) & 0xFF;
            blue = (packedColor >> 8) & 0xFF;
            {
                s32 a0 = (s32)((f32) M2C_FIELD(temp_7_5, s32 *, 0));
                u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                func_00124bb0(a0, M2C_FIELD(temp_7_5, f32 *, 4), 0.0f, M2C_FIELD(temp_7_5, f32 *, 8), M2C_FIELD(temp_7_5, f32 *, 0xC), M2C_FIELD(temp_7_5, f32 *, 0x10), M2C_FIELD(temp_7_5, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7_5, f32 *, 0x18), 0x42, temp_20);
            }
        }
        func_00124f70(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);
        func_0025f3f0(195.0f, 72.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10001, 0, taskView->sprites, 1);
        func_0025f430(204.0f, (f32) 0x143, 0.0f, 0xFFFFFFU, (u8)(255.0f * fadeT), 0x10007, 0, taskView->sprites, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        func_0025f3f0(268.0f, (f32) 0x169, 0.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
        break;
    case 8:
    case 9:
        if (taskView->timer == 0) {
            temp_f0_7 = (f32)*(s32 *)(D_005E5230 + taskView->f84 * 0x28);
            if (M2C_BITWISE(s32, temp_f0_7) >= 0xF) {
                var_4_16 = NULL;
            } else {
                temp_2_23 = (u32 *)(&temp_20[M2C_BITWISE(s32, temp_f0_7)]);
                if (func_004782b0(M2C_FIELD(temp_2_23, u8 **, 0x44)) != 0) {
                    var_4_16 = (u8 *)(M2C_FIELD(temp_2_23, u8 **, 0x44));
                } else {
                    var_4_16 = NULL;
                }
            }
            if (var_4_16 != NULL) {
                func_00479940(var_4_16, 0, 2, 0, 1);
            }
        }
        temp_2_24 = (s32)(taskView->timer);
        if (temp_2_24 < 0x258) {
            taskView->timer = (s32) (temp_2_24 + 1);
        }
        sp68C.value = fGpffff9c8c;
        sp6BC = sp68C;
        func_0045c870((u8 *)&sp6BC, 1);
        temp_f0_9 = (f32)*(s32 *)(D_005E5230 + taskView->f84 * 0x28);
        if (M2C_BITWISE(s32, temp_f0_9) >= 0xF) {
            var_16_2 = NULL;
        } else {
            temp_2_25 = (u32 *)(&temp_20[M2C_BITWISE(s32, temp_f0_9)]);
            if (func_004782b0(M2C_FIELD(temp_2_25, u8 **, 0x44)) != 0) {
                var_16_2 = (u8 *)(M2C_FIELD(temp_2_25, u8 **, 0x44));
            } else {
                var_16_2 = NULL;
            }
        }
        if (var_16_2 != NULL) {
            f32 titleY;
            f32 temp_f24;
            f32 temp_f23;
            f32 temp_f21_3;
            f32 titleX;

            temp_3_19 = (s32)(taskView->f84 * 0x28);
            titleX = *(f32 *)(D_005E5234 + temp_3_19);
            titleY = *(f32 *)(D_005E5238 + temp_3_19);
            temp_f24 = *(f32 *)(D_005E523C + temp_3_19);
            temp_f23 = *(f32 *)(D_005E5240 + temp_3_19);
            temp_f21_3 = *(f32 *)(D_005E5248 + temp_3_19);
            temp_2_26 = (s32)(M2C_FIELD(var_16_2, s32 *, 0xD8) & ~8);
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_2_26;
            temp_3_20 = temp_2_26 | 0x10;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_20;
            temp_3_21 = temp_3_20 | 0x100000;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_21;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = (s32) (temp_3_21 | 0x40000);
            temp_17_2 = (u32)(taskView->f84);
            if (temp_17_2 >= 0x13U) {
                func_0046d730(D_005E5548, 0xEB);
            }
            func_0047a0e0(var_16_2, 0, *(f32 *)(D_005E5254 + temp_17_2 * 0x28));
            /* Replace writes the matrix fields and flags before concatenation.
             * Provider padding remains unspecified; do not synthesize values. */
            RwMatrixRotate(&titleMatrix, &titleYawAxis, temp_f23, 0);
            RwMatrixRotate(&titleMatrix, &titlePitchAxis, temp_f24, 2);
            titleTranslation.x = 0.0f;
            titleTranslation.y = -90.0f;
            titleTranslation.z = 0.0f;
            RwMatrixTranslate(&titleMatrix, &titleTranslation, 1);
            func_0047a1c0(var_16_2, &titleMatrix, 0);
            var_2_29 = (s32)(taskView->timer - 5);
            if (var_2_29 > 0) {
                if (var_2_29 > 5) {
                    var_2_29 = 5;
                }
                {
                    f32 t = 1.0f - sinf(1.5707964f * (f32)var_2_29 / 5.0f);

                    titleX = titleX + 200.0f * t;
                    titleY = titleY + 250.0f * t;
                }
                func_002abb30(titleX + 49.0f * temp_f21_3, titleY - 33.0f * temp_f21_3, 100.0f, 0xFFFF81, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX + 24.0f * temp_f21_3, titleY - 12.0f * temp_f21_3, 100.0f, 0xFFFFFF, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX + 9.0f * temp_f21_3, titleY - 5.0f * temp_f21_3, 100.0f, 0xFFC705, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX, titleY, 100.0f, 0xFFF000, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_00478e70(var_16_2);
                func_002ab380(-1.0f, -1.0f, 1.0f, 0xFFFFFF, 0xFF, 0, taskView->sprites, 9, 0);
            }
        }
        var_2_30 = (s32)(taskView->timer);
        if (var_2_30 > 5) {
            var_2_30 = 5;
        }
        fadeT = (f32) var_2_30 / 5.0f;
        func_0025f3f0(195.0f, 72.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - fadeT)), 0x10001, 0, taskView->sprites, 1);
        var_2_31 = (s32)(taskView->timer - 2);
        if (var_2_31 > 0) {
            if (var_2_31 > 2) {
                var_2_31 = 5;
            }
            temp_f1_17 = (f32) var_2_31 / 5.0f;
            temp_f14_2 = 0.0f;
            temp_f16_3 = 0.87f;
            func_0025f430(52.0f + 246.0f * (1.0f - temp_f1_17), 81.0f, temp_f14_2, 0xFFFFFFU, (u8)(255.0f * temp_f1_17), 0x10001, 0, taskView->sprites, 1, 0, 0, temp_f14_2, temp_f16_3, temp_f16_3);
        }
        if (taskView->f28 != (taskView->f20 << 0x10)) {
    /* ACC seed */;
            temp_10_2 = (taskView->f20 << 0x10) - taskView->f28;
            temp_f0_10 = (f32)(s32)temp_10_2 + 0.5f * (f32)((taskView->f20 - taskView->f24) << 0x10);
            temp_10_2 = (s32)temp_f0_10;
            if (func_0043c6a0(temp_10_2) < 0xB) {
                taskView->f28 = (s32) (taskView->f20 << 0x10);
                taskView->f08 = (s32) ~(taskView->f08 ^ -5);
            } else {
                taskView->f28 = (s32) (taskView->f28 + (s32)((f32)(s32)temp_10_2 * 0.5f));
            }
        }
        temp_5 = (s32)(taskView->f24);
        temp_4 = (s32)(taskView->f20);
        temp_f1_28 = (f32)((temp_4 - temp_5) << 0x10);
        temp_f1_28 *= 0.25f;
        temp_f1_28 = (f32)(temp_4 << 0x10) + temp_f1_28;
        temp_28 = (s32)taskView->f28;
        temp_f0_11 = temp_f1_28 - (f32)temp_28;
        temp_i28 = (s32)temp_f0_11;
        if (((temp_5 < temp_4) && (temp_i28 < 0)) || ((temp_4 < temp_5) && (temp_i28 > 0))) {
            temp_28 = (s32)((f32)temp_i28 + temp_f1_28);
        }
        temp_f13_28 = 32.0f * ((f32)temp_28 / 65535.0f) + 327.0f;
        func_0025f3f0((f32) 0x18B, temp_f13_28, 0.0f, 0xFFFFFFU, 0xFF, 0x10006, 0, taskView->sprites, 1);
        func_0025f3f0(414.0f, 330.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10003, 0, taskView->sprites, 1);
        func_0025f3f0(444.0f, 362.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10004, 0, taskView->sprites, 1);
        func_0025f3f0((f32) 0x193, 394.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10005, 0, taskView->sprites, 1);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
    /* The update callback seeds this countdown with 10 or 13 frames. */
    if (taskView->f2C > 0) {
        /* Four UV pairs, copied as their original words before the texture lookup. */
        fadeUvSource = D_005E56B0;
        fadeUvDestination = fadeUv.words;
        var_4_17 = 4;
        do {
            temp_3_22 = fadeUvSource[0];
            temp_2_27 = fadeUvSource[1];
            fadeUvSource += 2;
            var_4_17 -= 1;
            fadeUvDestination[0] = temp_3_22;
            fadeUvDestination[1] = temp_2_27;
            fadeUvDestination += 2;
        } while (var_4_17 > 0);
        var_4_18 = 0xD;
        if (taskView->f00 == 0x10) {
            var_4_18 = 0xA;
        }
        temp_3_23 = (s32)(taskView->f2C - 1);
        taskView->f2C = temp_3_23;
        fadeAlpha = (s32)((f32)(temp_3_23 * 0xFF) / (f32)var_4_18);
        func_00366c70(0, 0, 0.0f, 0x280, 0x1C0, 0xFFFFFF, fadeAlpha,
                      1, 0, 0, NULL, func_00401b80(), fadeUv.pairs);
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);
#endif
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;
typedef struct Code12FrameMatrix {
    Code12FrameVector right; u32 flags;
    Code12FrameVector up; u32 pad1;
    Code12FrameVector at; u32 pad2;
    Code12FrameVector pos; u32 pad3;
} Code12FrameMatrix;
typedef union Code12FrameQuaternion {
    s128 packed;
    f32 value[4];
} Code12FrameQuaternion;
typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma push
#pragma opt_propagation off
static inline void code12QuaternionMatrix(Code12FrameMatrix *matrix, const Code12FrameQuaternion *rotation)
{
    f32 x, y, z, w;
    f32 xx, yy, zz, yz, zx, xy, wx, wy, wz;
    f32 squaredYZ;
    x = rotation->value[0];
    y = rotation->value[1];
    z = rotation->value[2];
    w = rotation->value[3];
    xx = x * x;
    yy = y * y;
    zz = z * z;
    yz = y * z;
    zx = z * x;
    xy = x * y;
    wx = w * x;
    wy = w * y;
    wz = w * z;
    squaredYZ = yy + zz;
    matrix->right.x = 1.0f - 2.0f * squaredYZ;
    matrix->right.y = 2.0f * (xy + wz);
    matrix->right.z = 2.0f * (zx - wy);
    matrix->up.x = 2.0f * (xy - wz);
    matrix->up.y = 1.0f - 2.0f * (xx + zz);
    matrix->up.z = 2.0f * (yz + wx);
    matrix->at.x = 2.0f * (zx + wy);
    matrix->at.y = 2.0f * (yz - wx);
    matrix->at.z = 1.0f - 2.0f * (xx + yy);
    matrix->pos.x = 0.0f;
    matrix->pos.y = 0.0f;
    matrix->pos.z = 0.0f;
    matrix->flags = 3;
}
#pragma pop

#pragma push
#pragma opt_propagation off
/* Native b210 O2: 3056/3056 bytes, 105 resolved relocations and the
 * complete 17-entry switch table at 0x00746770. Complete vector and
 * matrix objects retain the original stack transfers; reset-phase
 * models and the queued draw task have separate value lifetimes.
 * See docs/probe_archive/Menu_callback_0012aa70_20260923.md. */
// FUN_0012AA70
s32 func_0012aa70(u8 *task)
{
    extern s128 D_005E56F0;
    extern const Code12FrameVectorTransfer D_005E5700[1];
    extern u8 D_005E5220[];
    extern u8 D_005E5230[];
    extern u8 D_005E5710[];
    extern u8 D_005E5548[];
    extern char D_00795E60[];
    extern f32 fGpffff813c;
    extern s32 func_00440b68(const char *, ...);
    extern u8 *func_00454a60(u8 *task, s32 arg1);
    extern s32 H_Cdvd_IsFileLoaded(void *task);
    extern u8 *func_0025ef20(u8 *task);
    extern s32 func_0025f110(u8 *task);
    extern s32 func_001246d0(u8 *task);
    extern s32 func_00124830(u8 *task);
    extern s32 func_00124350(u8 *unusedWork);
    extern s32 func_001110e0(void);
    extern void func_00111160(s32 task);
    extern s32 func_00111200(void);
    extern void func_001113b0(void);
    extern void func_00122520(s32 task, s32 arg1);
    extern void func_00122640(s32 task, s32 arg1);
    extern s32 func_00122720(void);
    extern s32 func_0035c690(void *task, s32 arg1);
    extern s32 func_0035c7d0(u8 *task);
    extern s32 func_0035c810(u8 *task);
    extern u8 *func_00457120(void);
    extern void K_View_SetFov(void *task, f32 arg1);
    extern u8 *func_003e8180(u8 *camera, f32 nearClip);
    extern u8 *func_003e81c0(u8 *camera, f32 farClip);
    extern u8 *func_003e9cb0(u8 *frame, const void *matrix, s32 combine);
    extern u8 *func_003e9c10(u8 *frame, const f32 *translation, s32 combine);
    extern void func_004599a0(s32 task, s32 arg1);
    extern void func_0045aac0(s16 task, s32 arg1, s32 arg2);

    extern void func_0047a0e0(u8 *model, s32 layer, f32 speed);
    /* The persistent copy destination is a complete 0x5D0-byte buffer. */
    extern struct MenuSavedState { u8 bytes[0x5D0]; } iGpffff9c90 __attribute__((section(".sdata")));
    extern void func_001265a0(void *unusedDrawData, void *task);

    Code12FrameVectorTransfer translation;
    Code12FrameVectorTransfer initialTranslation;
    Code12FrameMatrix matrix;
    Code12FrameQuaternion rotation;
    Code12FrameQuaternion initialRotation;
    u8 *work;
    s32 state;
    s32 result;
    s32 updateIndex;
    s32 modelIndex;
    u32 pressed;
    u8 *activeModel;
    u8 *animation;

    work = (u8 *)func_00452560(task);
    initialRotation.packed = D_005E56F0;
    rotation = initialRotation;
    initialTranslation.vector = D_005E5700[0].vector;
    translation.vector = initialTranslation.vector;
    *(s32 *)(work + 4) = *(s32 *)work;
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)work = 1;
        func_00122640(1, 1);
    case 1:
        *(s32 *)work = 2;
        func_00440b68((const char *)&iGpffff9c90, D_005E5548, 0x5D0);
        *(u8 **)(work + 0x38) = func_00454a60(D_005E5710, 1);
    case 2:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 0x38)) != 0) {
            *(s32 *)work = 3;
            *(u8 **)(work + 0x3C) = func_0025ef20(D_005E5220);
        }
        break;
    case 3:
        if ((func_0025f110(*(u8 **)(work + 0x3C)) != 0) && (func_001246d0(work) != 0)) {
            *(s32 *)work = 4;
            func_004599a0(0x13, 0x1E);
        }
        break;
    case 4:
        code12QuaternionMatrix(&matrix, &rotation);
        func_003e9cb0(*(u8 **)(func_00457120() + 4), &matrix, 0);
        func_003e9c10(*(u8 **)(func_00457120() + 4), translation.value, 2);
        K_View_SetFov(func_00457120(), 50.0f);
        func_003e81c0(func_00457120(), 25600.0f);
        func_003e8180(func_00457120(), 10.0f);
        *(s32 *)work = 5;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        *(s32 *)(work + 0x10) = 0;
    case 5:
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
        if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
            func_0045af60(0, 0, 0, 1);
            pressed = D_008C024E[0];
        } else {
            pressed = 0;
        }
        if ((pressed != 0) || (*(s32 *)(work + 0x14) >= 0xEC)) {
            *(s32 *)(work + 8) = *(s32 *)(work + 8) & ~2;
            if (*(s32 *)(work + 0x14) < 0xEC) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) | 2;
                *(s32 *)(work + 0x2C) = 0xA;
            }
            *(s32 *)work = 6;
        }
        break;
    case 6:
        func_0045aac0(2, 0, 0x1E);
        *(s32 *)work = 7;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        code12QuaternionMatrix(&matrix, &rotation);
        func_003e9cb0(*(u8 **)(func_00457120() + 4), &matrix, 0);
        func_003e9c10(*(u8 **)(func_00457120() + 4), translation.value, 2);
        K_View_SetFov(func_00457120(), 50.0f);
        func_003e81c0(func_00457120(), 25600.0f);
        func_003e8180(func_00457120(), 10.0f);
        if (func_004782b0(*(u8 **)(work + 0x44)) != 0) {
            activeModel = *(u8 **)(work + 0x44);
        } else {
            activeModel = 0;
        }
        func_0047a0e0(activeModel, 0, fGpffff813c);
        updateIndex = 1;
        while (updateIndex < 8) {
            animation = D_005E5230 + updateIndex * 0x28;
            modelIndex = (s32)(f32)*(s32 *)animation;
            if (modelIndex >= 0xF) {
                activeModel = 0;
            } else {
                result = func_004782b0(*(u8 **)(work + modelIndex * 4 + 0x44));
                if (result != 0) {
                    activeModel = *(u8 **)(work + modelIndex * 4 + 0x44);
                } else {
                    activeModel = 0;
                }
            }
            if (activeModel != 0) {
                if ((u32)updateIndex >= 0x13) {
                    func_0046d730(D_005E5548, 0xEB);
                }
                func_0047a0e0(activeModel, 0, *(f32 *)(animation + 0x24));
            }
            updateIndex++;
        }
        if ((*(s32 *)(work + 8) & 2) != 0) {
            u8 *resetModel;
            s32 resetIndex;
            u8 *resetRow;
            modelIndex = *(s32 *)D_005E5230;
            if (modelIndex >= 0xF) {
                resetModel = 0;
            } else {
                result = func_004782b0(*(u8 **)((u8 *)(modelIndex * 4) + (u32)work + 0x44));
                if (result != 0) {
                    resetModel = *(u8 **)((u8 *)(modelIndex * 4) + (u32)work + 0x44);
                } else {
                    resetModel = 0;
                }
            }
            if (resetModel != 0) {
                func_00479940(resetModel, 0, 0, 0, 1);
            }
            resetIndex = 1;
            while (resetIndex < 8) {
                resetRow = D_005E5230 + resetIndex * 0x28;
                modelIndex = *(s32 *)resetRow;
                if (modelIndex >= 0xF) {
                    resetModel = 0;
                } else {
                    result = func_004782b0(*(u8 **)(work + modelIndex * 4 + 0x44));
                    if (result != 0) {
                        resetModel = *(u8 **)(work + modelIndex * 4 + 0x44);
                    } else {
                        resetModel = 0;
                    }
                }
                if (resetModel != 0) {
                    func_00479940(resetModel, 0, 0, 0, 1);
                }
                resetIndex++;
            }
        }
        *(s32 *)(work + 8) = *(s32 *)(work + 8) | 2;
    case 7:
        result = *(s32 *)(work + 0x14) + 1;
        *(s32 *)(work + 0x14) = result;
        if (result >= 0x1C2) {
            *(s32 *)work = 0x10;
            *(s32 *)(work + 0x1C) = 1;
            *(s32 *)(work + 0x2C) = 0xA;
            func_00122520(1, 0xA);
        } else {
            if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
                func_0045af60(0, 0, 0, 1);
                pressed = D_008C024E[0];
            } else {
                pressed = 0;
            }
            if (pressed != 0) {
                *(s32 *)work = 8;
            }
        }
        break;
    case 8:
        iGpffffb1e8 = iGpffffb1e8 + 1;
        *(s32 *)work = 9;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        *(s32 *)(work + 0x84) = func_00124350(work);
        matrix.right.x = matrix.up.y = matrix.at.z = 1.0f;
        matrix.up.z = matrix.at.x = matrix.at.y = matrix.right.y = matrix.right.z = matrix.up.x = 0.0f;
        matrix.pos.x = matrix.pos.y = matrix.pos.z = 0.0f;
        /* Preserve the original identity macro's read/OR of flags. This
         * branch does not initialize the pre-existing flag word. */
        matrix.flags |= 0x20003;
        func_003e9cb0(*(u8 **)(func_00457120() + 4), &matrix, 0);
        K_View_SetFov(func_00457120(), 70.0f);
        *(s32 *)(work + 0x28) = 0;
        *(s32 *)(work + 0x24) = 0;
        *(s32 *)(work + 0x20) = 0;
    case 9:
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
        if ((D_008C024E[0] & 0x20) || (*(s32 *)(work + 0x14) >= 0x1C2)) {
            *(s32 *)(work + 0x2C) = 0xD;
            *(s32 *)work = 6;
        } else {
            result = func_00124830(work);
            switch (result) {
            case 0:
                *(s32 *)(work + 0x14) = 0;
                break;
            case 1:
                *(s32 *)work = 0xA;
                break;
            case 2:
                *(s32 *)work = 0xC;
                func_0045aac0(2, 0, 0);
                break;
            case 3:
                *(s32 *)work = 0xE;
                break;
            }
        }
        break;
    case 10:
        *(s32 *)(work + 0x8C) = func_001110e0();
        func_001113b0();
        *(s32 *)work = 0xB;
        *(s32 *)(work + 0x34) = func_002aa300(task, 0);
    case 11:
        result = func_002aa3f0();
        switch (result) {
        case 1:
            func_00122520(1, 0xA);
            *(s32 *)(work + 0x1C) = 3;
            *(s32 *)work = 0x10;
            break;
        case 2:
            *(s32 *)work = 8;
            func_00111160(*(s32 *)(work + 0x8C));
            break;
        }
        break;
    case 12:
        *(s32 *)work = 0xD;
        func_00122520(1, 0xA);
    case 13:
        if (func_00122720() != 0) {
            *(s32 *)(work + 0x1C) = 2;
            *(s32 *)work = 0x10;
        }
        break;
    case 14:
        *(s32 *)work = 0xF;
        *(s32 *)(work + 0x34) = func_0035c690(task, 1);
    case 15:
        if (func_0035c7d0(*(u8 **)(work + 0x34)) != 0) {
            if (func_0035c810(*(u8 **)(work + 0x34)) != 0) {
                func_00111200();
            }
            func_00452080(*(u8 **)(work + 0x34));
            *(s32 *)(work + 0x34) = 0;
            *(s32 *)work = 8;
        }
        break;
    case 16:
        if ((func_00122720() != 0) && (*(s32 *)(work + 0x2C) == 0)) {
            *(s32 *)(work + 0x18) = *(s32 *)(work + 0x1C);
        }
        break;
    }
    {
        u8 *drawTask = func_00460990();
        *(void (**)(void *, void *))(drawTask + 8) = func_001265a0;
        *(u8 **)(drawTask + 0x10) = task;
        func_00460ac0(D_00795E60, drawTask);
    }
    return 0;
}

#pragma pop
// FUN_0012B660
void func_0012b660(u8 *unusedTask)
{
    u8 *temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    temp_2 = func_00452560();
    temp_3 = *(s32 *)(temp_2 + 0x1C);
    switch (temp_3) {
    case 2:
        break;
    case 3:
        if ((s64)(s16)func_001060b0() == 9 &&
            (func_001060c0() & 0xFF) == 5) {
            break;
        }
        goto error;
    default:
error:
        func_004598e0(0x1E);
        break;
    }
    var_17 = 0;
    goto loop_10_test;
loop_10_body:
    temp_4 = *(s32 *)(temp_2 + var_17 * 4 + 0x44);
    if (temp_4 != 0) {
        func_004787e0(temp_4);
    }
    var_17 += 1;
loop_10_test:
    if (var_17 < 0xF) {
        goto loop_10_body;
    }
    func_0025f230(*(s32 *)(temp_2 + 0x3C));
    H_Cdvd_Destroy(*(s32 *)(temp_2 + 0x38));
    jtbl_008873EC[0](temp_2);
}
// FUN_0012B760
s32 func_0012b760(void)
{
    u8 *temp_2;
    func_0044ea90(D_005E5548, 0x728);
    temp_2 = D_008873F4[0](1, 0x90, 0x40000);
    if (temp_2 == NULL)
        func_0046d730(D_005E5548, 0x729);
    *(s32 *)(temp_2 + 0x18) = 0;
    func_00451de0((const void *)(D_005E5720), 0xF, 0, 0, func_0012aa70, func_0012b660, (u8 *)(temp_2));
}
// FUN_0012B810
s32 func_0012b810(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(func_00452560(arg0));
    if (temp_2->field_18 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_18;
}



// FUN_0012B890
s32 func_0012b890(u8 *unusedTask)
{
    s32 sp2C;
    u8 *temp_2;
    s32 temp_3;
    temp_2 = (u8 *)func_00452560();
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_2 + 0) = 1;
    case 1:
        *(s32 *)(temp_2 + 0) = 2;
    case 2:
        *(s32 *)(temp_2 + 8) = func_004669d0(*(s32 *)(temp_2 + 4), &sp2C, 0);
        if (sp2C != 0) {
            *(s32 *)(temp_2 + 0) = 3;
            *(s32 *)(temp_2 + 4) = 0;
        }
        break;
    case 3:
        break;
    }
    return 0;
}
// FUN_0012B940
void func_0012b940(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_003ef3a0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_0012B9A0
void func_0012b9a0(s32 unused, s32 arg1)
{
    typedef struct {
        s128 sp50;
        s128 sp60;
        s128 sp70;
        u8 gap[4];
        f32 sp84;
        f32 sp88;
        f32 sp8C;
    } B9Stack;
    B9Stack stack;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_17;
    s32 temp_17_2;
    s32 var_2;
    s32 var_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;
    s32 temp_3;
    f32 *sp8c_ptr;
    s32 *sp70_ptr;

    temp_2 = (u8 *)func_00452560(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 4:
    case 5:
    case 6:
        temp_f0 = fGpffff9cA0;
        stack.sp88 = temp_f0;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0;
        stack.sp60 = D_005E5740;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5740;
        func_0045d6e0(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17 = *(s32 *)(temp_2 + 0x10);
        temp_16 = (u8 *)func_00452560(temp_17);
        if (func_00452490(temp_17) == 0) {
            var_2 = 0;
        } else if (*(s32 *)(temp_16 + 0) == 3) {
            var_2 = *(s32 *)(*(u8 **)(temp_16 + 8));
        } else {
            var_2 = 0;
        }
        func_00366c70(0x77, 0xAA, 0.0f, 0x200, 0x80, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2, 0);
        return;
    case 7:
    case 8:
    case 9:
        temp_f0_2 = fGpffff9cA4;
        stack.sp84 = temp_f0_2;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0_2;
        stack.sp50 = D_005E5750;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5750;
        func_0045d6e0(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17_2 = *(s32 *)(temp_2 + 0x14);
        temp_16_2 = (u8 *)func_00452560(temp_17_2);
        if (func_00452490(temp_17_2) == 0) {
            var_2_2 = 0;
        } else if (*(s32 *)(temp_16_2 + 0) == 3) {
            var_2_2 = *(s32 *)(*(u8 **)(temp_16_2 + 8));
        } else {
            var_2_2 = 0;
        }
        func_00366c70(0, 0, 0.0f, 0x400, 0x200, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2_2, 0);
        /* fall through */
    default:
        return;
    }
}
// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(func_00452560(arg0));
    if (temp_2->field_4 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_4;
}

// FUN_0012C220
s32 func_0012c220(u8 *arg0) {
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        if ((func_0045a890(0) != 0) && (func_0045a890(1) != 0)) {
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    default:
        goto block_20;
    case 1:
        *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0xF);
        *(s32 *)(temp_16 + 8) = 0x3C;
        *(u32 *)(temp_16 + 0) = 2U;
        goto block_20;
    case 2:
        temp_2_2 = *(s32 *)(temp_16 + 8) - 1;
        *(s32 *)(temp_16 + 8) = temp_2_2;
        if (temp_2_2 == 0) {
            func_00465f20();
            *(u32 *)(temp_16 + 0) = 3U;
        }
        goto block_20;
    case 3:
        temp_2_3 = func_00465f40();
        *(s32 *)(temp_16 + 4) = temp_2_3;
        if (temp_2_3 != 0) {
            if (temp_2_3 == 0x64) {
                func_0025e8b0(*(s32 *)(temp_16 + 0xC));
                return -1;
            }
            *(u32 *)(temp_16 + 0) = 4U;
            goto block_20;
        }
        goto block_20;
    case 4:
        func_0025e8b0(*(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 4) == -6) {
            *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0x15);
        } else {
            *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0x10);
        }
        *(u32 *)(temp_16 + 0) = 5U;
        goto block_20;
    case 5:
        temp_2_4 = func_0025e8f0(*(s32 *)(temp_16 + 0xC));
        if (temp_2_4 == 1) {
            func_0025e8b0(*(s32 *)(temp_16 + 0xC));
            return -1;
        }
        if (temp_2_4 == 2) {
            func_0025e8b0(*(s32 *)(temp_16 + 0xC));
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    }
block_20:
    return 0;
}
// FUN_0012C410
void func_0012c410(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    func_001029a0(1, 0, 0, 5);
}
// FUN_0012C460
s32 func_0012c460(s32 arg0) {
    s32 var_2;
    u8 *temp_2;

    func_0044ea90(D_005E57B8, 0x74);
    temp_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    var_2 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005E57D0), 0xF, 0, 0, func_0012c220, func_0012c410, (u8 *)(temp_2));
    if (var_2 == 0) {
        return 0;
    }
    return var_2;
}
#pragma push
/* measured: opt_loop_invariants on hoists the loop constants into the
   retail preheader and opt_propagation off keeps the pre-call indexed
   destination address materialised; 92 differing words -> 0 (532/544). */
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_0012D410
void func_0012d410(u8 *arg0)
{
    u32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 var_18_2;
    s32 var_18;
    s32 var_17;
    s32 var_2;
    s32 var_5;
    s32 temp_5;
    s32 temp_6;
    s32 *temp_4;

    *(s16 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x18) = -1;
    var_5 = 0;
    temp_5 = 0x42700000;
    temp_6 = 0x1000;
    while (var_5 < 0xB) {
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA4) = temp_5;
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA8) = 0;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0xBA) = temp_6;
        *(s8 *)(arg0 + (var_5 * 0x30) + 0xAE) = 0;
        var_5++;
    }
    temp_2_2 = (u32)func_0046a770((char *)D_005E5810);
    if (temp_2_2 == 0) {
        func_0046d730(D_005E5BB8, 0xC1);
    }
    temp_2_3 = (s32)func_0046a770((char *)D_005E57F0);
    *(s32 *)(arg0 + 0x90) = temp_2_3;
    if (temp_2_3 == 0) {
        func_0046d730(D_005E5BB8, 0xC3);
    }
    var_18 = 0;
    while (var_18 < 0x15) {
        temp_3 = var_18 * 4;
        temp_4 = (s32 *)(arg0 + temp_3 + 0x3C);
        temp_2_4 = (s32)func_0046d200(temp_2_2,
                                 *(u32 *)((u8 *)D_005E5B60 + temp_3));
        *temp_4 = temp_2_4;
        if (temp_2_4 == 0) {
            func_0046d730(D_005E5BB8, 0xC9);
        }
        var_18++;
    }
    var_17 = 0;
    var_18_2 = 0;
    while (var_17 < 7) {
        switch (var_17) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
            var_2 = 1;
            break;
        case 5:
            if (datGetFlag(0x1F) != 0) {
                var_2 = 0;
            } else {
                var_2 = 1;
            }
            break;
        default:
            func_0046d730(D_005E5BB8, 0xA7);
            var_2 = 0;
            break;
        }
        if (var_2 != 0) {
            *(s32 *)(arg0 + (var_18_2 * 4) + 0x1C) = var_17;
            var_18_2++;
        }
        var_17++;
    }
    *(s32 *)(arg0 + 0x38) = var_18_2;
    func_0012dea0(arg0, 0);
}
#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma pop
/* The menu owns eleven complete tween records and three seven-sprite banks.
 * measured: native b210 -O2 emits 1348 exact bytes plus 12 zero alignment bytes.
 * Scoped propagation preserves the selected sprite/opacity snapshots and the
 * two metadata color loads before their zero-depth argument transfers.
 * See docs/probe_archive/Camp_renderer_0012d630_complete_20260922.md. */
typedef struct {
    Vec2f startPosition;
    Vec2f endPosition;
    Vec2f position;
    u8 startAlpha;
    u8 endAlpha;
    u8 alpha;
    u8 pad1B;
    u16 startScaleX;
    u16 endScaleX;
    u16 scaleX;
    u16 startScaleY;
    u16 endScaleY;
    u16 scaleY;
    s32 startFrame;
    s32 endFrame;
} CampMenuTween;
typedef struct {
    s32 field00;
    Vec2f position;
    s16 frame;
    s16 field0E;
    s32 selection;
    s32 previousSelection;
    s32 state;
    s32 visibleOptions[7];
    s32 optionCount;
    u8 *sprites[3][7];
    s32 informationResource;
    CampMenuTween tweens[11];
} CampMenuWork;
typedef char CampMenuTweenSize[(sizeof(CampMenuTween) == 0x30) ? 1 : -1];
typedef char CampMenuWorkSize[(sizeof(CampMenuWork) == 0x2A4) ? 1 : -1];

#pragma push
#pragma opt_propagation off
// FUN_0012D630
s32 func_0012d630(u8 *menu)
{
    extern s32 func_0012e1d0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern void func_0034f320(u8 *arg0, f32 farg0, f32 farg1, f32 farg2,
                              u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                              u16 arg6, s16 arg7, f32 farg3, s16 arg_sp0);
    extern void func_0034f9d0(Vec2f pos, f32 z, u8 arg1, s32 arg2, s32 arg3);
    Vec2f pos;
    Vec2f pos2;
    u8 *bytes;
    s32 finished;
    s32 tweenIndex;
    s32 visibleCount;
    s32 selection;
    s32 row;
    f32 x;
    f32 y;
    f32 labelY;
    u8 numberColor;
    u8 informationColor;

    bytes = menu;
    finished = 1;
    switch (*(s32 *)(bytes + 0x18)) {
    case 0:
        if (func_0012e1d0(bytes) != 0) {
            func_0012dea0(bytes, 1);
            break;
        }
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            func_001437b0(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 1:
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            func_001437b0(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 2:
        if (func_0012e1d0(bytes) != 0) {
            func_0012dea0(bytes, 1);
            break;
        }
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            func_001437b0(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 2);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 3:
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            func_001437b0(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    }
    func_0034f1e0();
    selection = *(s32 *)(bytes + 0x10);
    visibleCount = *(s32 *)(bytes + 0x38);
    for (row = 0; row < visibleCount; row++) {
        u8 *rowBytes = bytes + row * 0x30;
        s32 option;
        u8 *sprite;
        u8 alpha;

        x = *(f32 *)(bytes + 4) + 173.0f + *(f32 *)(rowBytes + 0xA4);
        pos.x = x;
        y = *(f32 *)(bytes + 8) + 52.0f + *(f32 *)(rowBytes + 0xA8) + (f32)(row * 0x16);
        pos.y = y;
        alpha = *(u8 *)(rowBytes + 0xAE);
        option = *(s32 *)(bytes + row * 4 + 0x1C);
        if (row == selection) {
            pos.x += 2.0f;
            pos.y += 11.0f;
            sprite = *(u8 **)(bytes + option * 4 + 0x58);
        } else {
            pos.x += 1.0f;
            if (selection < row) {
                pos.y += 45.0f;
            }
            sprite = *(u8 **)(bytes + option * 4 + 0x3C);
        }
        func_0034f320(sprite, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                      alpha, 0x1000, *(u16 *)(rowBytes + 0xBA), 0,
                      0.0f, 0);
    }
    pos.x = *(f32 *)(bytes + 4) + 173.0f + *(f32 *)(bytes + 0x1F4) + 3.0f;
    pos.y = *(f32 *)(bytes + 8) + 52.0f + *(f32 *)(bytes + 0x1F8) + 311.0f;
    {
        CampMenuWork *work = (CampMenuWork *)bytes;
        u32 tweenOffset = (u32)row * sizeof(CampMenuTween);
        CampMenuTween *tween = (CampMenuTween *)(tweenOffset + (u32)bytes + 0x94);
        u8 selectedAlpha = tween->alpha;
        s32 selectedOption = work->visibleOptions[work->selection];
        u8 *selectedSprite = work->sprites[2][selectedOption];
        func_0034f320(selectedSprite, pos.x, pos.y, 0.0f,
                      0xFF, 0xFF, 0xFF, selectedAlpha, 0x1000,
                      tween->scaleY, 0, 0.0f, 0);
    }
    pos.x = *(f32 *)(bytes + 0x224) + 18.0f;
    labelY = (f32)0x17D;
    labelY += *(f32 *)(bytes + 0x228);
    pos.y = labelY;
    numberColor = *(u8 *)(bytes + 0x22E);
    func_00364320(pos, 0.0f, numberColor, -1);
    pos2.x = *(f32 *)(bytes + 0x254) + 640.0f;
    pos2.y = *(f32 *)(bytes + 0x258) + 400.0f;
    informationColor = *(u8 *)(bytes + 0x25E);
    func_0034f9d0(pos2, 0.0f, informationColor, 0, *(s32 *)(bytes + 0x90));
    return finished;
}

#pragma pop
// FUN_0012DB80
s32 func_0012db80(u8 *arg0, s32 arg1)
{
    if (arg1 != *(s32 *)(arg0 + 0x10)) {
        func_0045af60(0, 1, 0, 0);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x10);
        *(s32 *)(arg0 + 0x10) = arg1;
        *(s32 *)(arg0 + 0x18) = -1;
        func_0012dea0(arg0, 2);
    }
    return 1;
}
/* measured: opt_loop_invariants on is load-bearing for 0012DC00 -- without it
   the object grows to 676 bytes against the 672-byte window at nd 243. */
#pragma opt_loop_invariants on
// FUN_0012DC00
void func_0012dc00(u8 *arg0)
{
    s32 temp_10;
    s32 temp_3;
    s32 temp_5;
    s32 temp_7;
    s32 temp_9;
    s32 temp_8;
    s32 var_11;
    s32 var_11_2;
    s32 var_12;
    s32 var_c_ff;
    f32 var_c_1;
    f32 var_c_2;
    s32 var_c_7f;
    s32 var_c_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_5_2;
    u8 *temp_5_3;
    u8 *temp_6;
    u8 *temp_6_2;
    u8 *temp_6_3;
    u8 *temp_6_4;
    u8 *temp_6_5;

    temp_5 = *(s32 *)(arg0 + 0x10);
    temp_10 = *(s32 *)(arg0 + 0x14);
    temp_3 = *(s32 *)(arg0 + 0x38);
    temp_9 = temp_3 - 1;
    temp_8 = -temp_9;
    temp_7 = temp_5 - temp_10;
    var_11 = 0;
    goto loop_0012dc00_2_check;
loop_0012dc00_2_body:
    temp_6 = (var_11 * 0x30) + arg0;
    *(s32 *)(temp_6 + 0xBC) = 0;
    *(s32 *)(temp_6 + 0xC0) = 0;
    var_11 += 1;
loop_0012dc00_2_check:
    if (var_11 < 0xB) {
        goto loop_0012dc00_2_body;
    }
    if (temp_7 == 1) {
        temp_3_2 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_2 + 0x9C) = 0;
        *(s32 *)(temp_3_2 + 0x98) = 0;
        *(s32 *)(temp_3_2 + 0xA0) = 0;
        *(u8 *)(temp_3_2 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_2 + 0xC0) = 0;
        temp_5_2 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_2 + 0x9C) = 0;
        *(s32 *)(temp_5_2 + 0x98) = (s32)0xC1700000;
        *(s32 *)(temp_5_2 + 0xA0) = (s32)0x40B00000;
        *(s8 *)(temp_5_2 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_2 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == -1) {
        temp_3_3 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_3 + 0x9C) = 0;
        *(s32 *)(temp_3_3 + 0x98) = 0;
        *(s32 *)(temp_3_3 + 0xA0) = 0;
        *(u8 *)(temp_3_3 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_3 + 0xC0) = 0;
        temp_5_3 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_3 + 0x9C) = 0;
        *(s32 *)(temp_5_3 + 0x98) = (s32)0x41700000;
        *(s32 *)(temp_5_3 + 0xA0) = (s32)0xC0B00000;
        *(s8 *)(temp_5_3 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_3 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    } else if (temp_7 == temp_9) {
        var_12 = 0;
        var_c_ff = 0xFF;
        var_c_1 = -15.0f;
        var_c_2 = 5.5f;
        var_c_7f = 0x7F;
        var_c_3 = 3;
        goto loop_0012dc00_13_check;
loop_0012dc00_13_body:
        if (var_12 == temp_5) {
            temp_6_2 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(f32 *)(temp_6_2 + 0x98) = var_c_1;
            *(f32 *)(temp_6_2 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_2 + 0xAC) = var_c_7f;
            *(u8 *)(temp_6_2 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_2 + 0xC0) = var_c_3;
        } else {
            temp_6_3 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(s32 *)(temp_6_3 + 0x9C) = 0;
            *(s32 *)(temp_6_3 + 0x98) = 0;
            *(s32 *)(temp_6_3 + 0xA0) = 0;
            *(u8 *)(temp_6_3 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_3 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_3 + 0xC0) = 0;
        }
        var_12 += 1;
loop_0012dc00_13_check:
        if (var_12 < temp_3) {
            goto loop_0012dc00_13_body;
        }
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == temp_8) {
        var_11_2 = 0;
        var_c_ff = 0xFF;
        var_c_1 = 15.0f;
        var_c_2 = -5.5f;
        var_c_3 = 3;
        goto loop_0012dc00_21_check;
loop_0012dc00_21_body:
        if (var_11_2 == temp_5) {
            temp_6_4 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(f32 *)(temp_6_4 + 0x98) = var_c_1;
            *(f32 *)(temp_6_4 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_4 + 0xAC) = 0;
            *(u8 *)(temp_6_4 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_4 + 0xC0) = var_c_3;
        } else {
            temp_6_5 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(s32 *)(temp_6_5 + 0x9C) = 0;
            *(s32 *)(temp_6_5 + 0x98) = 0;
            *(s32 *)(temp_6_5 + 0xA0) = 0;
            *(u8 *)(temp_6_5 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_5 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_5 + 0xC0) = 0;
        }
        var_11_2 += 1;
loop_0012dc00_21_check:
        if (var_11_2 < temp_3) {
            goto loop_0012dc00_21_body;
        }
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    }
    *(s16 *)(arg0 + 0xC) = 0;
}
/* measured: closes the opt_loop_invariants bracket opened above func_0012dc00. */
#pragma opt_loop_invariants off
extern u8 D_005E58C0[];
extern u8 D_005E59A0[];
extern u8 D_005E5A80[];
extern void func_0012dc00(u8 *arg0);

#pragma push
/* measured: opt_loop_invariants on is load-bearing: removing it yields MISMATCH nd 383 (obj 684B/window 688B); on yields MATCH nd 0 (obj 680B/window 688B) by hoisting the case-zero constants. */
#pragma opt_loop_invariants on
// FUN_0012DEA0
s32 func_0012dea0(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 i0;
    s32 i1;
    s32 i3;
    u8 *p;
    u8 *src0;
    u8 *dst0;
    u8 *src1;
    u8 *dst1;
    u8 *src3;
    u8 *dst3;

    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0xC) = 0;
    i = 0;
    while (i < 0xB) {
        p = arg0 + i * 0x30;
        *(f32 *)(p + 0x94) = *(f32 *)(p + 0xA4);
        *(f32 *)(p + 0x98) = *(f32 *)(p + 0xA8);
        *(u8 *)(p + 0xAC) = *(u8 *)(p + 0xAE);
        *(u16 *)(p + 0xB0) = *(u16 *)(p + 0xB4);
        *(u16 *)(p + 0xB6) = *(u16 *)(p + 0xBA);
        i++;
    }
    switch (arg1) {
    case 0:
        i0 = 0;
        while (i0 < 0xB) {
            if (i0 != *(s32 *)(arg0 + 0x10)) {
                src0 = D_005E58C0 + i0 * 0x14;
                dst0 = arg0 + i0 * 0x30;
                *(f32 *)(dst0 + 0x9C) = *(f32 *)(src0 + 0);
                *(f32 *)(dst0 + 0xA0) = *(f32 *)(src0 + 4);
                *(u8 *)(dst0 + 0xAD) = *(u8 *)(src0 + 8);
                *(u16 *)(dst0 + 0xB8) = *(u16 *)(src0 + 0xA);
                *(s32 *)(dst0 + 0xBC) = *(s32 *)(src0 + 0xC);
                *(s32 *)(dst0 + 0xC0) = *(s32 *)(src0 + 0x10);
            } else {
                dst0 = arg0 + i0 * 0x30;
                *(s32 *)(dst0 + 0x94) = 0;
                *(s32 *)(dst0 + 0x9C) = 0;
                *(s32 *)(dst0 + 0x98) = 0x41B80000;
                *(s32 *)(dst0 + 0xA0) = 0;
                *(u8 *)(dst0 + 0xAC) = 0;
                *(u8 *)(dst0 + 0xAD) = 0xFF;
                *(u16 *)(dst0 + 0xB6) = 1;
                *(u16 *)(dst0 + 0xB8) = 0x1000;
                *(s32 *)(dst0 + 0xBC) = 0xB;
                *(s32 *)(dst0 + 0xC0) = 0xD;
            }
            i0++;
        }
        break;
    case 1:
        i1 = 0;
        while (i1 < 0xB) {
            src1 = D_005E59A0 + i1 * 0x14;
            dst1 = arg0 + i1 * 0x30;
            *(f32 *)(dst1 + 0x9C) = *(f32 *)(src1 + 0);
            *(f32 *)(dst1 + 0xA0) = *(f32 *)(src1 + 4);
            *(u8 *)(dst1 + 0xAD) = *(u8 *)(src1 + 8);
            *(u16 *)(dst1 + 0xB8) = *(u16 *)(src1 + 0xA);
            *(s32 *)(dst1 + 0xBC) = *(s32 *)(src1 + 0xC);
            *(s32 *)(dst1 + 0xC0) = *(s32 *)(src1 + 0x10);
            i1++;
        }
        break;
    case 2:
        func_0012dc00(arg0);
        break;
    case 3:
        i3 = 0;
        while (i3 < 0xB) {
            dst3 = arg0 + i3 * 0x30;
            *(s32 *)(dst3 + 0x94) = 0;
            *(s32 *)(dst3 + 0x98) = 0;
            src3 = D_005E5A80 + i3 * 0x14;
            *(f32 *)(dst3 + 0x9C) = *(f32 *)(src3 + 0);
            *(f32 *)(dst3 + 0xA0) = *(f32 *)(src3 + 4);
            *(u8 *)(dst3 + 0xAD) = *(u8 *)(src3 + 8);
            *(u16 *)(dst3 + 0xB8) = *(u16 *)(src3 + 0xA);
            *(s32 *)(dst3 + 0xBC) = *(s32 *)(src3 + 0xC);
            *(s32 *)(dst3 + 0xC0) = *(s32 *)(src3 + 0x10);
            i3++;
        }
        break;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants bracket for func_0012dea0. */
#pragma opt_loop_invariants off
#pragma pop
// FUN_0012E150
void func_0012e150(s32 arg0)
{
    s32 temp_4;
    s32 var_17;
    u8 *temp_3;
    u8 *temp_16;

    var_17 = 0;
    while (var_17 < 0x15) {
        temp_3 = (u8 *)(arg0 + (var_17 * 4));
        temp_16 = temp_3 + 0x3C;
        temp_4 = *(s32 *)temp_16;
        if (temp_4 != 0) {
            func_0046d280((void *)temp_4);
            *(s32 *)temp_16 = 0;
        }
        var_17 += 1;
    }
}
// FUN_0012E1D0
s32 func_0012e1d0(u8 *arg0)
{
    s32 var_16 = 1;
    s32 var_5 = 0;
    s32 temp_3 = *(s16 *)(arg0 + 0xC);

    while (var_5 < 0xB) {
        if (temp_3 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
// FUN_0012E250
s32 func_0012e250(u8 *arg0)
{
    s32 temp_3 = *(s32 *)(arg0 + 0x18);
    s32 var_16 = 1;
    s32 var_5;
    s32 temp_4;

    if (temp_3 == var_16) {
        goto block_early;
    }
    if (temp_3 != 2) {
        goto block_loop;
    }
block_early:
    return 1;
block_loop:
    var_5 = 0;
    temp_4 = *(s16 *)(arg0 + 0xC);
    while (var_5 < 0xB) {
        if (temp_4 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
/* measured: opt_loop_invariants on hoists the conversion constants into the loop preheader. */
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
// FUN_0012E2F0
s32 func_0012e2f0(u8 *arg0)
{
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    u8 *base_5f40;
    u8 *res_1;
    u8 *res_2;
    u8 *res_3;
    u8 *res_slot;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    u16 temp_u16;
    s32 temp_byte;
    s16 ii;

    memset(arg0, 0, 0x1BE8);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)arg0 = 0xFF;
    *(s32 *)(arg0 + 0x30) = -1;
    *(s16 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(arg0 + (i * 2) + 0x22) = 0;
    }
    j = 0;
    base_5f40 = D_005E5F40;
    for (; j < 30; j++) {
        temp_2 = base_5f40 + (j * 0x1C);
        temp_3 = arg0 + (j * 0x30);
        *(f32 *)(temp_3 + 0x12E8) = *(f32 *)temp_2;
        *(f32 *)(temp_3 + 0x12EC) = *(f32 *)(temp_2 + 4);
        *(u8 *)(temp_3 + 0x12F2) = *(u8 *)(temp_2 + 0x10);
        temp_u16 = (u16)*(f32 *)(temp_2 + 8);
        *(u16 *)(temp_3 + 0x12F8) = temp_u16;
        temp_u16 = (u16)*(f32 *)(temp_2 + 0xC);
        *(u16 *)(temp_3 + 0x12FE) = temp_u16;
    }
    for (k = 0; k < 12; k++) {
        *(s32 *)(arg0 + (k * 0x30) + 0x1888) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1878) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1884) = -1027080192;
        *(s32 *)(arg0 + (k * 0x30) + 0x187C) = -1027080192;
        *(u8 *)(arg0 + (k * 0x30) + 0x1891) = 127;
        *(u8 *)(arg0 + (k * 0x30) + 0x1890) = 127;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A0) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A4) = 10;
    }
    for (m = 0; m < 84; m++) {
        *(s32 *)(arg0 + (m * 0x14) + 0xC4C) = m % 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC54) = 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC50) = m / 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC58) = 12;
    }
    for (n = 0; n < 2; n++) {
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AB8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC4) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1ABC) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD1) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE4) = 3;
    }
    *(s16 *)(arg0 + 0x3C) = func_00353b50(arg0 + 0x34);
    res_1 = (u8 *)func_0046a770((char *)D_005E5830);
    if (res_1 == NULL) {
        func_0046d730(D_005E76C8, 0x1FA);
    }
    res_2 = (u8 *)func_0046a770((char *)D_005E5850);
    if (res_2 == NULL) {
        func_0046d730(D_005E76C8, 0x1FC);
    }
    temp_16 = (s32)func_0046a770((char *)D_005E57F0);
    res_3 = (u8 *)temp_16;
    *(u8 **)(arg0 + 0x1BE4) = (u8 *)temp_16;
    if (res_3 == NULL) {
        func_0046d730(D_005E76C8, 0x1FE);
    }
    ii = 0;
    while (ii < 51) {
        if (ii < 28) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)func_0046d200((u32)res_1, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else if (ii < 49) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)func_0046d200((u32)res_2, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = (s32)func_0046d200((u32)res_3, temp_byte);
            *(s32 *)res_slot = temp_16;
        }
        if (*(s32 *)res_slot == 0) {
            func_0046d730(D_005E76C8, 0x20B);
        }
        ii++;
    }
    func_0012e7c0(arg0);
    return func_0012ff60(arg0, 0);
}
#pragma opt_rebuildconditionals on
/* measured: closes the opt_loop_invariants bracket for func_0012e2f0. */
#pragma opt_loop_invariants off
/* measured: opt_propagation off probe for temp16 width in func_0012e7c0 */
#pragma opt_propagation off
// FUN_0012E7C0
void func_0012e7c0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    s64 temp_4_2;
    s16 var_18;
    s16 var_17;
    u8 *temp_3;

    var_17 = 0;
    var_18 = 0;
    goto loop_test;
loop_body:
    temp_16 = (s32)temp_4 + 0x300;
    temp_4_2 = (s64)(s16)(func_00106600(temp_16) & 0xFF);
    if (temp_4_2 != 0) {
        temp_3 = arg0 + ((s16)var_17 * 4);
        *(s16 *)(temp_3 + 0x3E) = (s16)temp_16;
        *(s16 *)(temp_3 + 0x40) = (s16)temp_4_2;
        var_17 += 1;
    }
    var_18 += 1;
loop_test:
    temp_4 = var_18;
    if (temp_4 < 0x300) {
        goto loop_body;
    }
    *(s16 *)(arg0 + 0xC3E) = var_17;
    if (var_17 <= 0x300) {
        goto guard_done;
    }
    func_0046d730(D_005E76C8, 0x225);
guard_done:
    ;
}
/* measured: opt_propagation on closes the temp16 width probe */
#pragma opt_propagation on
// FUN_0012E8B0
s32 func_0012e8b0(u8 *arg0)
{
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0x18);
    switch (temp_3) {
    case 0:
        *(s32 *)(arg0 + 0x18) = temp_3 + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0012E900
s32 func_0012e900(u8 *arg0) {
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_19;

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x1C);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x1C) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test_0012e900;
loop_body_0012e900:
    temp_19 = arg0 + (var_17 * 0x30);
    func_001437b0(temp_19 + 0x12D8, *(s16 *)(arg0 + 0x1C), 0);
    if (*(u8 *)(temp_19 + 0x12F2) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test_0012e900:
    if (var_17 < 0x1E) {
        goto loop_body_0012e900;
    }
    func_0012fdf0(arg0);
    func_0012feb0(arg0);
    func_0012e9d0(arg0);
    return var_16;
}
/* measured: propagation and constant extraction off preserve cached
 * opacity values and the independent animation-row evaluations. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* The label renderer reads these fields at offsets 0x00..0x18. */
typedef struct {
    s16 itemId;
    s16 quantity;
    s16 field04; /* Not read by these label modes. */
    s16 comparisonItem;
    s32 priceMode;
    s32 drawName;
    s32 drawStats;
    s16 iconFlags;
    s16 palette;
    s16 layout;
} CampLabelEntry;

/* Grid state shared with the countdown and cell-weight providers. */
typedef struct {
    s16 palette;
    s16 countdown;
    s32 column;
    s32 row;
    s32 columns;
    s32 rows;
} CampGridCell;

/* Draw the animated item list, selection, scrollbar, and background grid.
 * Native b210 -O2: 5148 executable bytes and four zero alignment bytes.
 * Preserve the independent position/opacity views across renderer calls. */
// FUN_0012E9D0
void func_0012e9d0(u8 *state)
{
    extern void func_0034f1e0(void);
    extern void func_0034c270(Vec2f position, s32 alpha, s32 mode, f32 depth);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void func_0034f2e0(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern f32 func_0034f720(u8 *cell, f32 horizontal, f32 vertical, f32 gain);
    extern void func_0034f320(u8 *sprite, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
        u16 scaleY, s16 mode, f32 angle, s16 flags);
    extern void func_00130c30(u8 *state, s64 position, s32 color);
    extern void func_001125d0(u8 *entry);
    extern void func_00112300(Vec2f position, f32 depth, u8 alpha, u8 *entry);
    extern void func_00130680(u8 *state, s32 index);
    extern u32 func_00106880(s16 item);
    extern s32 func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s8 font, s32 mode, const char *text, s32 flags,
        s32 unused);
    extern void func_00130ce0(u8 *state, PackedVec2f position, s32 alpha, s16 *entry);
    extern void func_0034f9d0(Vec2f position, f32 depth, u8 alpha, s32 value, s32 mode);
    extern u8 D_005E76B0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2F4[];
    extern u8 *iGpffff9cc8;
    PackedVec2f position;
    f32 opacityScale;
    f32 originX;
    f32 originY;
    f32 value;
    f32 scaledAlpha;
    s32 alphaByte;
    s32 dotIndex;
    void *dotSprite;
    s32 cellIndex;
    s32 labelIndex;
    u8 cachedAlpha;
    u8 *palette;
    s32 rowIndex;
    s32 selectedItem;
    u8 *row;
    CampGridCell *cell;
    f32 drawX;
    f32 rowY;
    f32 cellY;
    f32 cellWeight;
    CampLabelEntry label;
    CampLabelEntry detailLabel;
    typedef struct { u8 bytes[4]; } CampColorBytes;
    union { CampColorBytes channels; s32 word; } color;
    s32 itemIndex;
    s16 itemId;
    s16 quantity;
    u32 itemFlags;
    u8 *theme;
    s32 scrollRange;
    s32 scrollPosition;
    u8 fontAlpha;
    u8 *textRow;
    s32 textIndex;
    u8 *panelSprite;
    s16 selection;
    func_0034f1e0();
    originX = *(f32 *)(state + 4);
    originY = *(f32 *)(state + 8);
    value = (f32)*(u8 *)(state + 0);
    opacityScale = value / 255.0f;
    if (*(s32 *)(state + 0x10) != 0) {
        position.xy.x = originX;
        position.xy.y = originY;
        scaledAlpha = 255.0f * opacityScale;
        alphaByte = (u8)scaledAlpha;
        func_0034c270(position.xy, alphaByte & 0xFF, *(s32 *)(state + 0x10), 0.0f);
    }
    selectedItem = *(s16 *)(state + 0x24) + *(s16 *)(state + 0x22);
    if ((*(s32 *)(state + 0x14) & 0x200) != 0) {
        dotSprite = *(void **)(state + 0x1B50);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        dotIndex = 0;
        scaledAlpha = 190.0f * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        for (; dotIndex < 0xC; dotIndex++) {
            row = state + dotIndex * 0x30;
            position.xy.x = 363.0f + (originX + *(f32 *)(row + 0x1888));
            position.xy.y = 8.0f + (originY + *(f32 *)(row + 0x188C));
            func_0034f2e0(dotSprite, position.xy.x, position.xy.y, 0, 0xFF, 0x64, cachedAlpha);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        position.xy.x = 363.0f + (originX + *(f32 *)(state + 0x17F8));
        position.xy.y = 8.0f + (originY + *(f32 *)(state + 0x17FC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1802) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        cellIndex = 0;
        rowY = position.xy.y;
        for (; cellIndex < 0x54; cellIndex++) {
            row = state + cellIndex * 0x14;
            cell = (CampGridCell *)(row + 0xC48);
            if (cell->palette >= 0) {
                drawX = position.xy.x + (f32)(*(s32 *)(row + 0xC4C) * 44);
                cellY = rowY + (f32)(*(s32 *)(row + 0xC50) * 37);

                /* Literal weights retain the compiler-owned small-data constants. */
                cellWeight = func_0034f720((u8 *)cell, 0.3f, 0.3f, 0.6f);
                palette = D_005E76B0 + cell->palette * 4;
                color.channels = *(CampColorBytes *)palette;
                scaledAlpha = (f32)cachedAlpha * cellWeight;
                func_0034f2e0(dotSprite, drawX, cellY, color.channels.bytes[0], color.channels.bytes[1],
                    color.channels.bytes[2], (u8)scaledAlpha);
            }
        }
    }
    if ((*(s32 *)(state + 0x14) & 1) != 0) {
        position.xy.x = 152.0f + (originX + *(f32 *)(state + 0x12E8));
        position.xy.y = 370.0f + (originY + *(f32 *)(state + 0x12EC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x12F2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        func_0034f2e0(*(void **)(state + 0x1BDC), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 0x40) != 0) {
        position.xy.x = 16.0f + (originX + *(f32 *)(state + 0x1798));
        position.xy.y = 405.0f + (originY + *(f32 *)(state + 0x179C));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x17A2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        func_0034f2e0(*(void **)(state + 0x1B88), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 0x80) != 0) {
        position.xy.x = 62.0f + (originX + *(f32 *)(state + 0x17C8));
        position.xy.y = 405.0f + (originY + *(f32 *)(state + 0x17CC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x17D2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        func_0034f2e0(*(void **)(state + 0x1B8C), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 8) != 0) {
        u8 headingAlpha;
        position.xy.x = 271.0f + (originX + *(f32 *)(state + 0x1468));
        position.xy.y = 21.0f + (originY + *(f32 *)(state + 0x146C));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1472) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        headingAlpha = alphaByte;

        theme = D_0064B2F4;
        color.channels.bytes[0] = theme[0];
        color.channels.bytes[1] = theme[1];
        color.channels.bytes[2] = theme[2];
        color.channels.bytes[3] = headingAlpha;
        func_00130c30(state, position.packed, color.word);
        func_001125d0((u8 *)&label);
        label.itemId = ((s16 *)(state + 0x3E))[selectedItem * 2];
        label.quantity = ((s16 *)(state + 0x40))[selectedItem * 2];
        label.priceMode = -1;
        label.drawName = 1;
        label.drawStats = 0;
        label.layout = 4;
        label.iconFlags = 1;
        label.palette = 4;
        position.xy.x = position.xy.x + 1.0f;

        func_00112300(position.xy, 0.0f, headingAlpha, (u8 *)&label);
    }
    if ((*(s32 *)(state + 0x14) & 4) != 0) {
        for (labelIndex = 0; labelIndex < *(s16 *)(state + 0x3C); labelIndex++) {
            func_00130680(state, labelIndex);
        }
    }
    if ((*(s32 *)(state + 0x14) & 0x400) != 0) {
        value = *(f32 *)(state + 0x1AF8) + (originX + *(f32 *)(state + 0x15B8));
        rowY = *(f32 *)(state + 0x1AFC) + (originY + *(f32 *)(state + 0x15BC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x15C2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        drawX = 573.0f + value;
        position.xy.x = drawX;
        position.xy.y = 32.0f + rowY;
        func_0034f2e0(*(void **)(state + 0x1B44), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, cachedAlpha);
        position.xy.x = drawX;
        position.xy.y = 197.0f + rowY;
        func_0034f2e0(*(void **)(state + 0x1B48), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, cachedAlpha);
        position.xy.x = drawX;
        position.xy.y = 35.0f + rowY;
        scrollRange = (s32)*(s16 *)(state + 0xC3E) - 6;
        if (scrollRange > 0) {
            scrollPosition = (s32)*(s16 *)(state + 0x24) * 134;
            position.xy.y += (f32)(scrollPosition / scrollRange);
        }
        theme = D_0064B2E8;
        func_0034f2e0(*(void **)(state + 0x1B4C), position.xy.x, position.xy.y, theme[0], theme[1], theme[2],
            cachedAlpha);
    }
    if ((*(s32 *)(state + 0x14) & 2) != 0) {
        if (*(s16 *)(state + 0xC3E) == 0) {
            position.xy.x = 280.0f + (originX + *(f32 *)(state + 0x1318));
            position.xy.y = 20.0f + (originY + *(f32 *)(state + 0x131C));
            fontAlpha = *(u8 *)(state + 0x1322);
            func_00274ed0(position.xy.x, position.xy.y, 0.0f, (fontAlpha | ~0xFF), 6, 1, (const char *)iGpffff9cc8,
                0, 0);
        } else {
            if (*(u8 *)(state + 0x1AD2) > 0) {
                position.xy.x = originX + *(f32 *)(state + 0x1AC8);
                position.xy.y = originY + *(f32 *)(state + 0x1ACC);
                theme = D_0064B2E4;
                panelSprite = *(u8 **)(state + 0x1B18);
                func_0034f320(panelSprite, position.xy.x, position.xy.y, 0.0f, theme[0], theme[1], theme[2],
                    *(u8 *)(state + 0x1AD2), 0x1000, 0x1000, 0, 0.0f, 0);
            }
            for (rowIndex = 0; rowIndex < 6; rowIndex++) {
                u8 iconAlpha;
                u8 *iconSprite;
                itemIndex = rowIndex + *(s16 *)(state + 0x24);
                if (itemIndex < *(s16 *)(state + 0xC3E)) {
                    row = state + itemIndex * 4;
                    itemId = *(s16 *)(row + 0x3E);
                    quantity = *(s16 *)(row + 0x40);
                    itemFlags = func_00106880(itemId);
                    selection = *(s16 *)(state + 0x22);
                    if (rowIndex == selection) {
                        theme = D_0064B2E8;
                        palette = D_0064B2EC;
                        if ((*(s32 *)(state + 0x14) & 0x100) != 0) {
                            continue;
                        }
                        position.xy.x = 223.0f + (originX + *(f32 *)(state + 0x1318));
                        position.xy.y = 21.0f + (*(f32 *)(state + 0x131C) + (originY + 34.0f * (f32)selection));
                        color.channels.bytes[0] = theme[0];
                        color.channels.bytes[1] = theme[1];
                        color.channels.bytes[2] = theme[2];
                        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1322) * opacityScale;
                        alphaByte = (u8)scaledAlpha;
                        color.channels.bytes[3] = (u8)(alphaByte & 0xFF);

                        func_00130c30(state, position.packed, color.word);
                    } else {
                        theme = D_0064B2E4;
                        palette = D_0064B2E0;
                        row = state + rowIndex * 0x30;
                        position.xy.x = 221.0f + (originX + *(f32 *)(row + 0x1498));
                        position.xy.y = (21.0f + (originY + *(f32 *)(row + 0x149C))) + 34.0f * (f32)rowIndex;
                        scaledAlpha = (f32)(u32)*(u8 *)(row + 0x14A2) * opacityScale;
                        alphaByte = (u8)scaledAlpha;
                        panelSprite = *(u8 **)(state + 0x1B18);
                        func_0034f320(panelSprite, position.xy.x, position.xy.y, 0.0f, theme[0], theme[1], theme[2],
                            alphaByte, 0x1000, *(u16 *)(row + 0x14AE), 0, 0.0f, 0);
                    }
                    row = state + rowIndex * 0x30;
                    position.xy.x = 224.0f + (originX + *(f32 *)(row + 0x1498));
                    rowY = 34.0f * (f32)rowIndex;
                    position.xy.y = rowY + (23.0f + (originY + *(f32 *)(row + 0x149C)));
                    scaledAlpha = (f32)(u32)*(u8 *)(row + 0x14A2) * opacityScale;
                    iconAlpha = (u8)scaledAlpha;
                    if ((itemFlags & 0x10000) != 0) {
                        iconSprite = *(u8 **)(state + 0x1B9C);
                    } else if ((itemFlags & 0x20000) != 0) {
                        iconSprite = *(u8 **)(state + 0x1BA0);
                    } else {
                        iconSprite = *(u8 **)(state + 0x1B98);
                    }
                    /* Text geometry uses a separate row evaluation; the icon row
                     * remains live for the opacity read after label initialization. */
                    textIndex = rowIndex;
                    textRow = state + textIndex * 0x30;
                    func_0034f320(iconSprite, position.xy.x, position.xy.y, 0.0f, palette[0], palette[1],
                        palette[2], iconAlpha, 0x1000, *(u16 *)(textRow + 0x14AE), 0, 0.0f, 0);
                    position.xy.x = 266.0f + (originX + *(f32 *)(textRow + 0x1348));
                    position.xy.y = 21.0f + (*(f32 *)(textRow + 0x134C) + (originY + rowY));

                    func_001125d0((u8 *)&label);
                    label.itemId = itemId;
                    label.quantity = quantity;
                    label.priceMode = -1;
                    label.drawName = 1;
                    label.drawStats = 0;
                    label.layout = 4;
                    if (rowIndex == *(s16 *)(state + 0x22)) {
                        label.iconFlags = 0;
                        label.palette = 3;
                    } else {
                        label.iconFlags = 0;
                        label.palette = 2;
                    }
                    scaledAlpha = (f32)(u32)*(u8 *)(row + 0x1352) * opacityScale;
                    func_00112300(position.xy, 0.0f, (u8)scaledAlpha, (u8 *)&label);
                }
            }
        }
    }
    if (((*(s32 *)(state + 0x14) & 0x100) != 0) && (*(s16 *)(state + 0xC3E) != 0)) {
        position.xy.x = 223.0f + (originX + *(f32 *)(state + 0x1318));
        selection = *(s16 *)(state + 0x22);
        position.xy.y = 21.0f + (*(f32 *)(state + 0x131C) + (originY + 34.0f * (f32)selection));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x15F2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        itemId = *(s16 *)(state + 0x24);
        detailLabel.itemId = ((s16 *)(state + 0x3E))[(itemId + selection) * 2];
        detailLabel.quantity = ((s16 *)(state + 0x40))[(itemId + *(s16 *)(state + 0x22)) * 2];
        detailLabel.priceMode = -1;
        detailLabel.drawName = 1;
        /* comparisonItem is only consumed when statistics are enabled. */
        detailLabel.drawStats = 0;
        detailLabel.palette = 3;
        detailLabel.iconFlags = 1;
        detailLabel.layout = 4;

        func_00130ce0(state, position, alphaByte & 0xFF, (s16 *)&detailLabel);
    }
    position.xy.x = 640.0f + (originX + *(f32 *)(state + 0x1828));
    position.xy.y = 400.0f + (originY + *(f32 *)(state + 0x182C));
    value = (f32)*(u8 *)(state + 0x1832);
    scaledAlpha = value * opacityScale;
    alphaByte = (u8)scaledAlpha;
    func_0034f9d0(position.xy, 0.0f, (u8)(alphaByte & 0xFF), *(s16 *)(state + 0xC40), *(s32 *)(state + 0x1BE4));
}

#pragma pop
// FUN_0012FDF0
void func_0012fdf0(u8 *arg0)
{
    s16 temp_3;
    s32 var_16;
    s32 var_16_2;
    u8 *temp_2;

    temp_3 = *(s16 *)(arg0 + 0x1E);
    if (temp_3 < 0x64) {
        temp_3 += 1;
        *(s16 *)(arg0 + 0x1E) = temp_3;
    }
    for (var_16 = 0; var_16 < 0xC; var_16++) {
        temp_2 = arg0 + (var_16 * 0x30);
        func_001437b0(temp_2 + 0x1878, *(s16 *)(arg0 + 0x1E), 0);
    }
    for (var_16_2 = 0; var_16_2 < 0x54; var_16_2++) {
        temp_2 = arg0 + (var_16_2 * 0x14);
        func_0034f5d0(temp_2 + 0xC48);
    }
}
/* measured: opt_common_subs off preserves the retail base+offset accesses in
   the two-record callback loop. */
#pragma opt_common_subs off
// FUN_0012FEB0
void func_0012feb0(u8 *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = arg0 + i * 0x30 + 0x1AB8;
        func_001437b0(p, *(s16 *)(arg0 + 0x20), 0);
    }
}
/* measured: opt_common_subs on closes the callback-loop probe. */
#pragma opt_common_subs on
/* The selection is passed as a word; the field stores its low halfword. */
// FUN_0012FF40
s32 func_0012ff40(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *p;

    p = (u8 *)code1_0012_stride(arg1 * 2, arg0);
    *(s16 *)(p + 0x28) = *(s16 *)(p + 0x22);
    *(s16 *)(p + 0x22) = arg2;
    return 1;
}
extern u8 D_005E5BF0[];
extern u8 D_005E6290[];
extern u8 D_005E65E0[];
extern u8 D_005E6930[];
extern u8 D_005E6C80[];
extern u8 D_005E6FD0[];
extern u8 D_005E7320[];

/* measured: opt_common_subs off preserves retail's first-loop base/index
   addressing and setup order; on reverts immediately after the switch. */
#pragma opt_common_subs off
// FUN_0012FF60
s32 func_0012ff60(u8 *arg0, u32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    table = 0;
    if (arg1 == *(u32 *)(arg0 + 0x30)) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        dst = arg0 + (i * 0x30);
        *(f32 *)(dst + 0x12d8) = *(f32 *)(dst + 0x12e8);
        *(f32 *)(dst + 0x12dc) = *(f32 *)(dst + 0x12ec);
        *(u16 *)(dst + 0x12f4) = *(u16 *)(dst + 0x12f8);
        *(u16 *)(dst + 0x12fa) = *(u16 *)(dst + 0x12fe);
        *(u8 *)(dst + 0x12f0) = *(u8 *)(dst + 0x12f2);
    }
    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E5BF0;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 1:
        table = D_005E5F40;
        break;
    case 2:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 3:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 4:
        *(s32 *)(arg0 + 0x14) = 0x2dd;
        table = D_005E65E0;
        *(s16 *)(arg0 + 0x2c) = *(s16 *)(arg0 + 0x26);
        *(s16 *)(arg0 + 0x26) = 0;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 5:
        *(s32 *)(arg0 + 0x14) = 0x2ed;
        table = D_005E6C80;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 6:
        *(s32 *)(arg0 + 0x14) = 0x29d;
        table = D_005E6930;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 7:
        *(s32 *)(arg0 + 0x14) = 0x2ad;
        table = D_005E6FD0;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 8:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    case 9:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    default:
        func_0046d730(D_005E76C8, 0x4ab);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table-loop constants and
   stride calculations into retail's preheader (without it, nd is nonzero). */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 30; j++) {
            src = table + (j * 0x1c);
            dst = arg0 + (j * 0x30);
            *(f32 *)(dst + 0x12e0) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x12e4) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0x12f1) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0x12f6) = (u16)value;
            value = *(f32 *)(src + 0xc);
            *(u16 *)(dst + 0x12fc) = (u16)value;
            *(s32 *)(dst + 0x1300) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x1304) = *(s32 *)(src + 0x18);
        }
        *(u32 *)(arg0 + 0x30) = arg1;
        *(s16 *)(arg0 + 0x1c) = 0;
    }
    return 1;
}
/* measured: closes opt_loop_invariants for func_0012ff60. */
#pragma opt_loop_invariants off
