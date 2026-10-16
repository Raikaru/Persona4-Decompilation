#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 kwlnGetCamera(void);
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern void func_004b1ad0(u8 *arg0);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void func_003c42b0(s32 arg0, s32 arg1);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Source unit: src/promoted/code1_004b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004b.c; members 004b1ad0-004b1ad0 */

typedef struct EffScreenSpriteFrame {
    f32 rect[4];
    u32 size[2];
    u16 corner[8];
} EffScreenSpriteFrame;
typedef struct EffScreenSpriteRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} EffScreenSpriteRGBA;
#pragma push
/* measured: func_004b1ad0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_004B1AD0
void func_004b1ad0(u8 *arg0)
{
    extern s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
    extern void mdlEffectWrapTrackFrames(s32 arg0, u32 arg1);
    extern void mdlEffectEvalSubPose(s32 arg0, f32 *arg1);
    extern void TlpSelectFrame(void *arg0, u32 arg1, f32 *arg2);
    extern void GeometryBlockGetTextureInfo(s32 arg0, u32 *arg1);
    extern void func_003c22f0(void *arg0);
    extern void func_003c42b0(void *arg0, s32 arg1);
    extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
    extern void PrimAppendNode(void *arg0, void *arg1);
    extern s32 TnGetOffset38(u16 arg0);
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern f32 D_00761134;
    extern f32 fGpffff8084;
    EffScreenSpriteRGBA color;
    u32 baseWord;
    u32 tintWord;
    u32 packed;
    u32 frame[4];
    f32 animation[16];
    f32 texture[8];
    EffScreenSpriteFrame info;
    f32 scale;
    f32 right;
    f32 bottom;
    f32 left;
    f32 top;
    f32 spin;
    s32 count;
    s32 total;
    u8 *sprite;
    f32 *vertex;
    f32 *uv;

    total = *(s32 *)(arg0 + 0x98);
    count = *(s32 *)(arg0 + 0x8);
    sprite = *(u8 **)(arg0 + 0xA4);
    if (count == 0) {
        return;
    }
    if (count >= total) {
        return;
    }
    {
        s32 tint = func_0048abd0(arg0 + 0xC, arg0 + 0x30, count, total);
        f32 unit;

        baseWord = *(u32 *)arg0;
        {
            const u32 *word = &baseWord;

            unit = D_00761134;
            effectVuUnpackColor10V0(word, unit);
        }
        __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
        tintWord = tint;
        effectVuUnpackColor10V0(&tintWord, unit);
    }
    __asm__ volatile(
        "vmul.xyzw $vf10, $vf10, $vf11\n"
        "lui $2, 0x437F\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2.ni $2, $vf10\n"
        "ppach $2, $0, $2\n"
        "ppacb $2, $0, $2\n"
        "sw $2, packed\n" : "=m"(packed) : : "$2", "$vf2", "$vf10");
    *(u32 *)&color = packed;
    if (color.alpha != 0xFF) {
        *(EffScreenSpriteRGBA *)(*(u8 **)(sprite + 0x14) + 4) = color;
    } else {
        color.alpha = 0xFE;
        *(EffScreenSpriteRGBA *)(*(u8 **)(sprite + 0x14) + 4) = color;
        color.alpha = 0xFF;
    }
    scale = func_0048aff0(arg0 + 0x40, count, total) / 100.0f;
    spin = func_0048aff0(arg0 + 0x6C, count, total);
    spin += fGpffff8084;
    if (*(s32 *)(arg0 + 0xAC) != 0) {
        f32 cellW;
        f32 cellH;
        f32 y0;
        f32 x0;
        f32 x1;

        mdlEffectWrapTrackFrames(*(s32 *)(arg0 + 0xAC), count);
        mdlEffectEvalSubPose(*(s32 *)(arg0 + 0xAC), animation);
        cellW = 16.0f * animation[12];
        cellH = 16.0f * animation[13];
        x0 = animation[6] * cellW;
        info.corner[2] = (u16)x0;
        y0 = animation[7] * cellH;
        info.corner[3] = (u16)y0;
        x1 = animation[8] * cellW;
        info.corner[0] = (u16)x1;
        info.corner[1] = (u16)y0;
        info.corner[6] = (u16)x1;
        x1 = animation[9] * cellH;
        info.corner[7] = (u16)x1;
        info.corner[4] = (u16)x0;
        info.corner[5] = (u16)x1;
        info.rect[0] = animation[0];
        info.rect[1] = animation[1];
        info.rect[2] = animation[2];
        info.rect[3] = animation[3];
        info.size[0] = (u32)animation[12];
        info.size[1] = (u32)animation[13];
        spin += animation[4];
        func_003c42b0(*(void **)(sprite + 0x14), *(s32 *)&animation[5]);
    } else if (*(void **)(arg0 + 0xA8) != NULL) {
        s32 w;
        s32 h;

        TlpSelectFrame(*(void **)(arg0 + 0xA8), count, texture);
        w = (s32)(16.0f * texture[2]);
        h = (s32)(16.0f * texture[3]);
        info.corner[2] = 0;
        info.corner[3] = 0;
        info.corner[0] = w;
        info.corner[1] = 0;
        info.corner[6] = w;
        info.corner[7] = h;
        info.corner[4] = 0;
        info.corner[5] = h;
        w = (s32)((f32)w * texture[0]);
        h = (s32)((f32)h * texture[1]);
        info.rect[0] = 0.0f;
        info.rect[1] = 0.0f;
        info.rect[2] = (f32)(w >> 5);
        info.rect[3] = (f32)(h >> 5);
        info.size[0] = (u32)texture[2];
        info.size[1] = (u32)texture[3];
        func_003c42b0(*(void **)(sprite + 0x14), *(s32 *)&texture[4]);
    } else {
        s32 w;
        s32 h;

        GeometryBlockGetTextureInfo((s32)sprite, frame);
        w = frame[0] << 4;
        h = frame[1] << 4;
        info.corner[2] = 0;
        info.corner[3] = 0;
        info.corner[0] = w;
        info.corner[1] = 0;
        info.corner[6] = w;
        info.corner[7] = h;
        info.corner[4] = 0;
        info.corner[5] = h;
        info.rect[0] = 0.0f;
        info.rect[1] = 0.0f;
        info.rect[2] = (f32)w;
        info.rect[3] = (f32)h;
        info.size[0] = frame[0];
        info.size[1] = frame[1];
    }
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(sprite + 0x10) + 0x18), 0xFF2);
    {
        u8 *geometry = *(u8 **)(*(u8 **)(sprite + 0x10) + 0x18);

        vertex = *(f32 **)(*(u8 **)(geometry + 0x5C) + 0x14);
        uv = *(f32 **)(geometry + 0x34);
    }
    left = info.rect[0] * scale;
    top = info.rect[1] * scale;
    right = info.rect[2] * scale;
    bottom = info.rect[3] * scale;
    {
        f32 c = cosf(spin);
        f32 s = sinf(spin);
        f32 x1 = left + right;
        f32 y1 = top + bottom;
        f32 x2;
        f32 y2;
        f32 x3;

        vertex[0] = x1 * c - y1 * s;
        vertex[1] = y1 * c + x1 * s;
        x2 = left - right;
        vertex[3] = x2 * c - y1 * s;
        vertex[4] = x2 * s + y1 * c;
        y2 = top - bottom;
        vertex[9] = x2 * c - y2 * s;
        vertex[10] = x2 * s + y2 * c;
        vertex[6] = x1 * c - y2 * s;
        x3 = left + right;
        vertex[7] = y2 * c + x3 * s;
    }
    {
        f32 invW = 1.0f / (f32)(info.size[0] << 4);
        f32 invH = 1.0f / (f32)(info.size[1] << 4);

        uv[2] = (f32)info.corner[0] * invW;
        uv[3] = (f32)info.corner[1] * invH;
        uv[0] = (f32)info.corner[2] * invW;
        uv[1] = (f32)info.corner[3] * invH;
        uv[6] = (f32)info.corner[6] * invW;
        uv[7] = (f32)info.corner[7] * invH;
        uv[4] = (f32)info.corner[4] * invW;
        uv[5] = (f32)info.corner[5] * invH;
    }
    {
f32 *camera;
        f32 nearZ;
        f32 farZ;
        f32 offsetX;
        f32 depth;
        f32 halfW;
        f32 halfH;
        f32 z;
        f32 offsetY;
        u32 i;

        camera = (f32 *)((u8 *)kwlnGetCamera() + 0x68);
        nearZ = *(f32 *)((u8 *)kwlnGetCamera() + 0x80);
        farZ = *(f32 *)((u8 *)kwlnGetCamera() + 0x84);
        offsetX = (f32)*(s32 *)(arg0 + 0x9C);
        offsetY = (f32)*(s32 *)(arg0 + 0xA0);
        depth = ((f32)(-65535) * nearZ * farZ) / ((f32)(-65535) * farZ - -31.0f * (farZ - nearZ));
        halfW = 2.0f * (camera[0] * depth);
        halfH = 2.0f * (camera[1] * depth);
        i = 0;
        z = 1.0f + depth;

        for (; i < 4; i++) {
            vertex[0] = halfW * (0.5f + -(vertex[0] + offsetX) / 640.0f);
            vertex[1] = halfH * (0.5f + -(vertex[1] + offsetY) / 448.0f);
            vertex[2] = z;
            vertex += 3;
        }
    }
    {
        u8 *owner = *(u8 **)(arg0 + 0xA4);
        u8 *geometry = *(u8 **)(*(u8 **)(owner + 0x10) + 0x18);

        func_003c22f0(geometry);
        if ((*(u16 *)owner & 4) != 0) {
            *(u16 *)(geometry + 0xC) |= 1;
        }
    }
    {
        u8 *scene = (u8 *)kwlnGetCamera();

        func_003e9cb0(*(void **)(sprite + 0xC), (void *)((u32)*(u8 **)(scene + 4) + 0x10), 0);
    }
    *(u16 *)sprite &= 0xFFFE;
    {
        s32 light = TnGetOffset38(*(u16 *)(arg0 + 0x34));

        *(u32 *)(sprite + 0x18) = 0;
        *(u32 *)(sprite + 0x1C) = 0;
        PrimAppendNode((void *)light, sprite + 0x18);
    }
}

