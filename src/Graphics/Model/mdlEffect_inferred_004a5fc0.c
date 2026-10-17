#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern void EffSpriteUpdate(u8 *arg0);
extern u8 D_0071413C[];
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];



extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void func_003c22f0();
extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern void func_003c42b0(void *arg0, s32 arg1);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a5fc0-004a5fc0 */

typedef struct EffSpriteFrame {
    f32 rect[4];
    u32 size[2];
    u16 corner[8];
} EffSpriteFrame;
typedef struct EffSpriteRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} EffSpriteRGBA;
/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
/* Sprite update: reads the frame counter at +0x2C, resets it to zero when the cycle wraps, and rebuilds the sprite's frame, colour and texture state. */
// FUN_004A5FC0
void EffSpriteUpdate(u8 *arg0)
{
    extern void GeometryBlockSetFrameMatrix(void *arg0, void *arg1, void *arg2, f32 arg3);
    extern s32 mdlEffectSamplePackedColor(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern f32 mdlEffectSampleScalarKeys(u8 *arg0, s32 arg1, s32 arg2);
    extern void mdlEffectWrapTrackFrames(s32 arg0, u32 arg1);
    extern void mdlEffectEvalSubPose(s32 arg0, f32 *arg1);
    extern void TlpSelectFrame(void *arg0, u32 arg1, f32 *arg2);
    extern void GeometryBlockGetTextureInfo(s32 arg0, u32 *arg1);
    extern void GeometryBlockBindResource(void *arg0, s32 arg1);
    extern void func_003c22f0(void *arg0);
    extern void func_003c42b0(void *arg0, s32 arg1);
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern f32 D_00761134;
    EffSpriteRGBA color;
    u32 baseWord;
    u32 tintWord;
    u32 packed;
    u32 frame[4];
    f32 animation[16];
    f32 texture[8];
    EffSpriteFrame info;
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

    total = *(s32 *)(arg0 + 0xBC);
    count = *(s32 *)(arg0 + 0x2C);
    sprite = *(u8 **)(arg0 + 0xC8);
    if (count == 0) {
        return;
    }
    if (!(count < total) && total > 0) {
        if (*(u8 *)(arg0 + 0x74) != 0) {
            *(s32 *)(arg0 + 0x2C) = 0;
            count = 0;
        } else {
            return;
        }
    }
    GeometryBlockSetFrameMatrix(sprite, arg0, arg0 + 0x10, *(f32 *)(arg0 + 0x20));
    {
        s32 tint = mdlEffectSamplePackedColor(arg0 + 0x30, arg0 + 0x54, count, total);
        f32 unit;

        baseWord = *(u32 *)(arg0 + 0x24);
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
        *(EffSpriteRGBA *)(*(u8 **)(sprite + 0x14) + 4) = color;
    } else {
        color.alpha = 0xFE;
        *(EffSpriteRGBA *)(*(u8 **)(sprite + 0x14) + 4) = color;
        color.alpha = 0xFF;
    }
    scale = mdlEffectSampleScalarKeys(arg0 + 0x64, count, total);
    scale = scale * *(f32 *)(arg0 + 0xC0);
    spin = mdlEffectSampleScalarKeys(arg0 + 0x90, count, total);
    if (*(s32 *)(arg0 + 0xD0) != 0) {
        f32 cellW;
        f32 cellH;
        f32 y0;
        f32 x0;
        f32 x1;

        mdlEffectWrapTrackFrames(*(s32 *)(arg0 + 0xD0), count);
        mdlEffectEvalSubPose(*(s32 *)(arg0 + 0xD0), animation);
        cellW = 16.0f * animation[12];
        cellH = 16.0f * animation[13];
        x0 = animation[6] * cellW;
        info.corner[0] = (u16)x0;
        y0 = animation[7] * cellH;
        info.corner[1] = (u16)y0;
        x1 = animation[8] * cellW;
        info.corner[2] = (u16)x1;
        info.corner[3] = (u16)y0;
        info.corner[4] = (u16)x1;
        x1 = animation[9] * cellH;
        info.corner[5] = (u16)x1;
        info.corner[6] = (u16)x0;
        info.corner[7] = (u16)x1;
        info.rect[0] = animation[0];
        info.rect[1] = animation[1];
        info.rect[2] = animation[2] / 16.0f;
        info.rect[3] = animation[3] / 16.0f;
        info.size[0] = (u32)animation[12];
        info.size[1] = (u32)animation[13];
        spin += animation[4];
        func_003c42b0(*(void **)(sprite + 0x14), *(s32 *)&animation[5]);
    } else if (*(void **)(arg0 + 0xCC) != NULL) {
        s32 w;
        s32 h;

        TlpSelectFrame(*(void **)(arg0 + 0xCC), count, texture);
        w = (s32)(16.0f * texture[2]);
        h = (s32)(16.0f * texture[3]);
        info.corner[0] = 0;
        info.corner[1] = 0;
        info.corner[2] = w;
        info.corner[3] = 0;
        info.corner[4] = w;
        info.corner[5] = h;
        info.corner[6] = 0;
        info.corner[7] = h;
        w = (s32)((f32)w * texture[0]);
        h = (s32)((f32)h * texture[1]);
        info.rect[0] = 0.0f;
        info.rect[1] = 0.0f;
        info.rect[2] = (f32)(w >> 5) / 16.0f;
        info.rect[3] = (f32)(h >> 5) / 16.0f;
        info.size[0] = (u32)texture[2];
        info.size[1] = (u32)texture[3];
        func_003c42b0(*(void **)(sprite + 0x14), *(s32 *)&texture[4]);
    } else {
        s32 w;
        s32 h;

        GeometryBlockGetTextureInfo((s32)sprite, frame);
        w = frame[0] << 4;
        h = frame[1] << 4;
        info.corner[0] = 0;
        info.corner[1] = 0;
        info.corner[2] = w;
        info.corner[3] = 0;
        info.corner[4] = w;
        info.corner[5] = h;
        info.corner[6] = 0;
        info.corner[7] = h;
        info.rect[0] = 0.0f;
        info.rect[1] = 0.0f;
        info.rect[2] = ((f32)w / 32.0f) / 16.0f;
        info.rect[3] = ((f32)h / 32.0f) / 16.0f;
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
        vertex[1] = 0.0f;
        vertex[2] = y1 * c + x1 * s;
        x2 = left - right;
        vertex[3] = x2 * c - y1 * s;
        vertex[4] = 0.0f;
        vertex[5] = x2 * s + y1 * c;
        y2 = top - bottom;
        vertex[9] = x2 * c - y2 * s;
        vertex[10] = 0.0f;
        vertex[11] = x2 * s + y2 * c;
        vertex[6] = x1 * c - y2 * s;
        vertex[7] = 0.0f;
        x3 = left + right;
        vertex[8] = y2 * c + x3 * s;
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
        u8 *owner = *(u8 **)(arg0 + 0xC8);
        u8 *geometry = *(u8 **)(*(u8 **)(owner + 0x10) + 0x18);

        func_003c22f0(geometry);
        if ((*(u16 *)owner & 4) != 0) {
            *(u16 *)(geometry + 0xC) |= 1;
        }
    }
    if (*(u8 *)(arg0 + 0xC4) != 0) {
        *(u16 *)sprite |= 1;
    } else {
        *(u16 *)sprite &= 0xFFFE;
    }
    GeometryBlockBindResource(sprite, *(u16 *)(arg0 + 0x58));
}

