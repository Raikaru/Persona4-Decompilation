#include "include_asm.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
#include "rw_types_internal.h"
#include "psc_model_internal.h"
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
typedef struct {
    f32 x;
    f32 y;
} PairF32;
typedef union {
    s64 raw;
    PairF32 f;
} PairBits;
typedef struct PersonaWork PersonaWork;






extern u8 *kwlnGetCamera(void);
extern f32 iGpffff84a4;
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y,
                          u8 alphaSubtract, u8 red, u8 green, u8 blue,
                          f32 z, s32 setStates);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

extern f32 fGpffff8390;
extern f32 fGpffff8394;
extern u16 D_008C024E[];
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0;
    f32 u;
    f32 v;
    f32 w;
    f32 pad1;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 pad2[4];
} P4Vertex66C70;
typedef struct {
    s32 matrix[16];
    P4Vertex66C70 vertices[4];
    s32 config[8];
    u8 local[0x30];
} P4DrawFrame66C70;
typedef void (*P4RenderState66C70)(s32 state, s32 value);
extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src,
                           const struct RwMatrixTag *matrix);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0036; members 0036ae90-0036ae90 */

struct PanelMatrix;
struct PanelTransform;
/* 780/784 bytes; nine resolved relocations; four zero alignment bytes.
 * Keep the angle and shared scale local to each primitive call. */
#pragma push
#pragma pop
/* measured: opt_common_subs off keeps the raw alpha argument in $s1 and re-masks it at each of
   its two uses (color entry, 0xFF - alpha at the sprite call) as retail does; with CSE on b210
   masks once into $s0 (nd 78). */
/* measured: nd 9 -> 0. opt_loop_invariants on hoists the digit loop's 16.0f and 10
   ahead of the entry branch. Alpha: `n = arg1 & 0xFF; arg1 = 0xFF - n;` through the
   loop counter's register puts the andi before the li (fresh local or one expression: nd 3). */
/* measured: closes the loop-invariant bracket; the file default is off. */
/* measured: retail hoists the 0.5f loop constants out of the corner loops. */
#pragma push
#pragma pop
/* measured: cache the invariant light Y/Z after outer initialization; declaration lifetimes retain MATCH without opt_loop_invariants. */
// Intent: Builds a panel's tile vertex list: the camera-facing flip, the 9-row grid of tiles and their colours [inferred]
/* Orient the card mesh toward the camera and shade its alternating tile rows using diffuse and specular weights. */
// FUN_0036AE90
/* Initial whole-layout typing changed address lifetimes (1528/1504 bytes);
 * per-access forms retain the retail code without raw object offsets. */
void pscModelBuildTileVertices(u8 *mesh, u8 *model) {
    RwV3d *cameraPosition;
    extern u8 *func_003e9700(u8 *frame);
    extern struct RwMatrixTag *func_003e0f80(void);
    extern void pscBuildModelMatrix(struct PanelMatrix *output,
                              const struct PanelTransform *transform);
    extern RwV3d *func_003e42a0(RwV3d *out, const RwV3d *in,
                                const struct RwMatrixTag *matrix);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern struct RwMatrixTag *RwMatrixRotate(struct RwMatrixTag *matrix,
                                              const RwV3d *axis, f32 angle,
                                              s32 combineOp);
    extern void func_003e0f40(struct RwMatrixTag *matrix);
    extern RwV3d D_0064E490;
    extern RwV3d D_0064E4A0;
    extern RwV3d D_0064E4B0;
    extern RwV3d D_0064E4C0;
    RwV3d lightAxis;
    RwV3d lightDirection;
    RwV3d eyeDirection;
    RwV3d position;
    RwV3d worldPosition;
    RwV3d lightPosition;
    RwV3d modelNormal;
    RwV3d flipAxis;
    RwV3d worldNormal;
    s32 inner;
    s32 outer;
    s32 limit;
    s32 even;
    u8 *dst;
    u8 *mtx;
    u8 *view;
    u8 *rgba;
    struct RwMatrixTag *cam;
    f32 dot;
    f32 fx;
    f32 dot2;
    f32 pow6;
    f32 lightY;
    f32 lightZ;
    f32 dot3;
    f32 clamped;
    f32 combined;
    u8 abyte;
    u8 shade;
    f32 af;
    f32 scaled;

    lightAxis = D_0064E490;
    view = kwlnGetCamera();
    mtx = func_003e9700(((MdlEffectCamera *)view)->frame) + 0x30;
    cameraPosition = (RwV3d *)mtx;
    modelNormal = D_0064E4A0;
    flipAxis = D_0064E4B0;
    worldNormal = D_0064E4C0;
    cam = func_003e0f80();
    pscBuildModelMatrix((struct PanelMatrix *)cam,
                  (const struct PanelTransform *)model);
    func_003e4320(&modelNormal, &modelNormal, cam);
    lightPosition = *(RwV3d *)&((PscTileMesh *)mesh)->lightPosition;
    if (((PscModel *)model)->frame != NULL) {
        func_003e42a0(&position, (RwV3d *)(model + 0x20),
                      (struct RwMatrixTag *)func_003e9700(((PscModel *)model)->frame));
    } else {
        position = *(RwV3d *)&((PscModel *)model)->position;
    }
    dot = modelNormal.x * (*(f32 *)mtx - position.x) + modelNormal.y * (((RwV3d *)mtx)->y - position.y) + modelNormal.z * (((RwV3d *)mtx)->z - position.z);
    *(s32 *)mesh &= ~1;
    if (dot < 0.0f) {
        RwMatrixRotate(cam, &flipAxis, 180.0f, 1);
        *(s32 *)mesh |= 1;
    }
    rgba = model + 0x40;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 100.0f;
    func_003e42a0(&position, &position, cam);
    func_003e4320(&worldNormal, &lightAxis, cam);
    RwV3dNormalize(&worldNormal, &worldNormal);
    {
        dst = mesh + 4;
        outer = 0;
        lightY = lightPosition.y;
        lightZ = lightPosition.z;
        for (; outer < 9; outer++) {
            even = ~outer & 1;
            if (even != 0) {
                limit = 8;
            } else {
                limit = 7;
            }
            for (inner = 0; inner < limit; inner++, dst += 0x24) {
                if (even != 0) {
                    if (inner == 0) {
                        fx = 0.0f;
                    } else if (inner == limit - 1) {
                        fx = 6.0f;
                    } else {
                        fx = 0.5f + (f32)(inner - 1);
                    }
                } else {
                    fx = (f32)inner;
                }
                position.x = fx - 3.0f;
                position.y = 7.68f * ((f32)outer / 8.0f - 0.5f);
                position.z = 0.0f;
                func_003e42a0(&worldPosition, &position, cam);
                eyeDirection.x = worldPosition.x - *(f32 *)mtx;
                eyeDirection.y = worldPosition.y - cameraPosition->y;
                eyeDirection.z = worldPosition.z - cameraPosition->z;
                RwV3dNormalize(&eyeDirection, &eyeDirection);
                lightDirection.x = worldPosition.x - lightPosition.x;
                lightDirection.y = worldPosition.y - lightY;
                lightDirection.z = worldPosition.z - lightZ;
                RwV3dNormalize(&lightDirection, &lightDirection);
                dot2 = eyeDirection.x * lightAxis.x + eyeDirection.y * lightAxis.y + eyeDirection.z * lightAxis.z;
                {
                    f32 normalX = lightAxis.x * dot2;
                    f32 normalY = lightAxis.y * dot2;
                    f32 normalZ = lightAxis.z * dot2;
                    f32 reflectedZ = normalZ + (normalZ - eyeDirection.z);
                    f32 reflectedX = normalX + (normalX - eyeDirection.x);
                    f32 reflectedY = normalY + (normalY - eyeDirection.y);
                    f32 specularDot = lightDirection.x * reflectedX + lightDirection.y * reflectedY + lightDirection.z * reflectedZ;
                    if (specularDot <= 0.0f) {
                        pow6 = 0.0f;
                    } else {
                        pow6 = specularDot * specularDot * specularDot * specularDot * specularDot * specularDot;
                    }
                }
                lightDirection.x = lightPosition.x - worldPosition.x;
                lightDirection.y = lightY - worldPosition.y;
                lightDirection.z = lightZ - worldPosition.z;
                RwV3dNormalize(&lightDirection, &lightDirection);
                dot3 = lightDirection.x * worldNormal.x + lightDirection.y * worldNormal.y + lightDirection.z * worldNormal.z;
                if (dot3 <= 0.0f) {
                    clamped = 0.0f;
                } else {
                    clamped = dot3;
                }
                combined = pow6 * ((PscTileMesh *)mesh)->specularWeight + clamped * ((PscTileMesh *)mesh)->diffuseWeight;
                if (!(combined <= 1.0f)) {
                    combined = 1.0f;
                }
                abyte = rgba[3];
                af = (f32)(u32)abyte;
                scaled = af * combined;
                shade = scaled;
                dst[0xC] = shade;
                dst[0xD] = shade;
                dst[0xE] = shade;
                dst[0xF] = shade;
            }
        }
    }
    func_003e0f40(cam);
}

