#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_camera_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
extern f32 cosf(f32 depth);
extern f32 sinf(f32 depth);
extern s32 iGpffffb9e8;
struct RwCamera;
struct RwSphere;
enum RwFrustumTestResult {
    rwSPHEREOUTSIDE = 0,
    rwSPHEREBOUNDARY = 1,
    rwSPHEREINSIDE = 2,
    rwFRUSTUMTESTRESULTFORCEENUMSIZEINT = 0x7fffffff
};
extern enum RwFrustumTestResult RwCameraFrustumTestSphere(const struct RwCamera *camera,
                                           const struct RwSphere *sphere);
struct RwV3d;
struct RwMatrixTag;
extern struct RwV3d *func_003e42a0(struct RwV3d *out, const struct RwV3d *in,
                                  const struct RwMatrixTag *matrix);
typedef struct Code45CurrentEntities {
    const struct RwCamera *camera;
    void *world;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
} Code45CurrentEntities;
extern Code45CurrentEntities D_008872E0;
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern s64 D_00711858[];
extern f32 D_00711860[];
static inline f32 add_f32(f32 a, f32 b) {
    return a + b;
}
extern u8 *iGpffffb9e0;
extern void memset(void *dst, s32 value, s32 size);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
#include "rw_types_internal.h"
typedef RwV3d Code45Vec3;

typedef RwMatrixTag Code45Matrix;

typedef struct RwSphere {
    Code45Vec3 center;
    f32 radius;
} Code45Sphere;
typedef struct {
    u8 red, green, blue, alpha;
} Code45RGBA;
extern s32 PrimBuildQuadVertices(f32 *out, u8 *colors, s32 *pos, f32 z);
typedef struct Code45RenderState {
    s32 state;
    s32 val;
} Code45RenderState;
extern Code45RenderState D_00712490[6];
extern s32 iGpffffac74;
extern s32 iGpffffad88;
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern u8 D_008C02E0[];
extern s16 D_008C0336[];
extern s16 D_008C0338[];
extern s16 D_008C033C[];
extern s16 D_008C0340[];
extern s16 D_008C0342[];
extern u8 D_008C0346[];
extern u8 D_008C0347[];
extern u8 D_008C0348[];
extern u8 D_008C0349[];
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern u8 D_00711720[];
extern s32 D_00711870_abs[];
extern s32 D_00711890_abs[];
extern u8 D_008E4090[];
extern u8 D_008E4230[];
extern s32 D_008E4018_abs[];
extern s32 D_008E40B4_abs[];
extern s32 D_008E40F8_abs[];
extern s32 D_008E413C_abs[];
extern s32 D_008E4180_abs[];
extern s32 D_008E41C4_abs[];
extern s32 D_008E4208_abs[];
extern u8 D_007117C8[];
extern u8 D_007117E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00711800[];
extern u8 D_00711810[];
extern u8 D_00711820[];
extern u8 D_00711830[];
extern u8 D_00756500[];
extern u8 D_00756510[];
extern f32 fGpffff802c;
extern f32 fGpffff8030;
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern u8 *iGpffffba74;
extern u8 *iGpffffba78;
extern u8 *iGpffffba7c;
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern s32 iGpffffba10;
extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
extern u8 D_008C02EC[];
extern u8 D_008C02EE[];
extern u8 D_008C02F0[];
extern u8 D_008C02F6[];
extern u8 D_008C02F8[];
extern u8 D_008C02FA[];
extern u8 D_008C02FC[];
extern u8 D_008C02FD[];
extern u8 D_008C02FE[];
extern u8 D_008C02FF[];
extern u8 D_008C0318[];
extern u8 D_008C02F2[];
extern u8 D_008C0300[];
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];

extern u8 D_008C8780[];
extern u8 D_008D1B80[];
extern u8 D_008D1B84[];
extern u8 D_008D1B88[];
extern u8 D_008D1C90[];
extern u8 D_008D1C98[];
extern u8 D_008D1CD4[];


typedef struct {
    f32 x;
    f32 y;
} Code45Vec2;

typedef struct {
    f32 u;
    f32 v;
} Code45TexCoords;


/* Providers and external symbols */
extern s32 iGpffffb9d4;
extern Code45Vec2 iGpffffac48;
extern Code45Vec2 iGpffffac50;
extern s8 iGpffffb9d8;
extern f32 D_008872F8;
extern u8 D_008BE320[][256];


/* RwDevice's near-screen depth and callback slots are one real object.
 * The complete Sky immediate-mode vertex has a 64-byte stride. */
typedef struct Code45RenderDevice {
    f32 gamma;
    s32 (*system)(s32, void *, void *, s32);
    f32 nearDepth;
    f32 farDepth;
    s32 (*setState)(s32, void *);
    s32 (*getState)(s32, void *);
    u32 renderCallbackAddresses[8];
} Code45RenderDevice;
extern Code45RenderDevice D_008872F0;

typedef struct Code45Im2DVertex {
    f32 position[3];
    f32 cameraZ;
    f32 uv[2];
    f32 reciprocal;
    f32 pad1;
    f32 color[4];
    f32 normal[3];
    f32 pad2;
} Code45Im2DVertex;

#pragma push
static inline s32 overlayAtlasColumn(s32 value)
{
    return value % 16;
}


#pragma pop
#pragma push
/* Character codes are normalized as bytes; the atlas column retains
 * the signed remainder operation used by the original renderer. */
static inline s32 fontAtlasColumn(s32 value)
{
    return value % 16;
}

#pragma pop



#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 0045ce40-0045d890 */

extern void K_ClumpLookAtBasis(u8 *colorData, u8 *rectangleData, u8 *preserveState, f32 *arg3);
extern void mdlRenderInitializeBuffers(void);
extern s32 kwlnGetCamera(void);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off preserves the retail global-load destination register. */
/* measured: close propagation-off probe for K_ClumpLookAtBasis. */
/* measured: opt_scalarize off keeps the prop triple in stack spill slots with direct sp-relative accesses. */
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the array base into $v1 ahead of
   the loop as retail; a named base local is coloured $a0 (archived nd 8). */
/* measured: closes the hoisting scope after func_0045b430. */
/* Expand signed rectangle coordinates into four Sky vertices, using the camera near plane for reciprocal depth. */
// FUN_0045CE40
s32 PrimBuildQuadVertices(f32 *out, u8 *colors, s32 *pos, f32 z)
{
    f32 *vertices;
    s32 result;
    f32 inv;

    vertices = out;
    result = kwlnGetCamera();
    inv = 1.0f / ((RwCamera *)result)->nearPlane;
    z = D_008872F8_abs[0] - z;
    ((Code45Im2DVertex *)vertices)[0].position[0] = (f32)pos[0];
    ((Code45Im2DVertex *)vertices)[0].position[1] = (f32)pos[1];
    ((Code45Im2DVertex *)vertices)[0].position[2] = z;
    ((Code45Im2DVertex *)vertices)[0].color[0] = (f32)colors[0];
    ((Code45Im2DVertex *)vertices)[0].color[1] = (f32)colors[1];
    ((Code45Im2DVertex *)vertices)[0].color[2] = (f32)colors[2];
    ((Code45Im2DVertex *)vertices)[0].color[3] = (f32)colors[3];
    ((Code45Im2DVertex *)vertices)[0].reciprocal = inv;
    ((Code45Im2DVertex *)vertices)[1].position[0] = (f32)(pos[0] + pos[2]);
    ((Code45Im2DVertex *)vertices)[1].position[1] = (f32)pos[1];
    ((Code45Im2DVertex *)vertices)[1].position[2] = z;
    ((Code45Im2DVertex *)vertices)[1].color[0] = (f32)colors[0];
    ((Code45Im2DVertex *)vertices)[1].color[1] = (f32)colors[1];
    ((Code45Im2DVertex *)vertices)[1].color[2] = (f32)colors[2];
    ((Code45Im2DVertex *)vertices)[1].color[3] = (f32)colors[3];
    ((Code45Im2DVertex *)vertices)[1].reciprocal = inv;
    ((Code45Im2DVertex *)vertices)[2].position[0] = (f32)pos[0];
    ((Code45Im2DVertex *)vertices)[2].position[1] = (f32)(pos[1] + pos[3]);
    ((Code45Im2DVertex *)vertices)[2].position[2] = z;
    ((Code45Im2DVertex *)vertices)[2].color[0] = (f32)colors[0];
    ((Code45Im2DVertex *)vertices)[2].color[1] = (f32)colors[1];
    ((Code45Im2DVertex *)vertices)[2].color[2] = (f32)colors[2];
    ((Code45Im2DVertex *)vertices)[2].color[3] = (f32)colors[3];
    ((Code45Im2DVertex *)vertices)[2].reciprocal = inv;
    ((Code45Im2DVertex *)vertices)[3].position[0] = (f32)(pos[0] + pos[2]);
    ((Code45Im2DVertex *)vertices)[3].position[1] = (f32)(pos[1] + pos[3]);
    ((Code45Im2DVertex *)vertices)[3].position[2] = z;
    ((Code45Im2DVertex *)vertices)[3].color[0] = (f32)colors[0];
    ((Code45Im2DVertex *)vertices)[3].color[1] = (f32)colors[1];
    ((Code45Im2DVertex *)vertices)[3].color[2] = (f32)colors[2];
    ((Code45Im2DVertex *)vertices)[3].color[3] = (f32)colors[3];
    ((Code45Im2DVertex *)vertices)[3].reciprocal = inv;
    return result;
}

/* Native b210 O2: 880/880 bytes; all six code relocations resolve exactly.
 * Reusing the local corner and the two integer origins preserves the actual
 * fused multiply-accumulate expressions, including their zero accumulator
 * seed. See docs/probe_archive/Primitive_corners_0045d370_20260924.md. */
// FUN_0045D370
#pragma push
void PrimBuildRotatedRectangle(void *output, void *colorData, void *rectangle, f32 depth,
                  s32 offsetX, s32 offsetY, f32 angle, f32 scaleX, f32 scaleY)
{
    typedef struct { f32 x, y; } QuadPoint;
    QuadPoint corners[4];
    f32 inv;
    f32 sine;
    f32 cosine;
    f32 negSine;
    QuadPoint offset;
    f32 radians;
    s32 centerX;
    s32 centerY;
    f32 displacement;
    u32 i;
    f32 *out;
    u8 *colors;
    s32 *pos;

    out = (f32 *)output;
    colors = (u8 *)colorData;
    pos = (s32 *)rectangle;
    inv = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    depth = D_008872F8_abs[0] - depth;
    pos[2] = (s32)((f32)pos[2] * scaleX);
    pos[3] = (s32)((f32)pos[3] * scaleY);
    radians = fGpffff8200 * angle;
    sine = sinf(radians);
    cosine = cosf(radians);
    /* Traverse the four local corners. Preserve the first point
     * displacement before converting its shared integer origin. */
    offset.x = (f32)(-(s16)offsetX);
    offset.y = (f32)(-(s16)offsetY);
    centerX = pos[0] + (s16)offsetX;
    displacement = 0.0f + offset.y * sine + offset.x * cosine;
    corners[0].x = (f32)centerX + displacement;
    negSine = -sine;
    centerY = pos[1] + (s16)offsetY;
    displacement = 0.0f + offset.y * cosine + offset.x * negSine;
    corners[0].y = (f32)centerY + displacement;
    offset.x = (f32)(pos[2] - (s16)offsetX);
    corners[1].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[1].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    offset.x = (f32)(-(s16)offsetX);
    offset.y = (f32)(pos[3] - (s16)offsetY);
    corners[2].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[2].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    offset.x = (f32)(pos[2] - (s16)offsetX);
    corners[3].x = (f32)centerX + (0.0f + offset.y * sine + offset.x * cosine);
    corners[3].y = (f32)centerY + (0.0f + offset.y * cosine + offset.x * negSine);
    for (i = 0; i < 4; i++) {
        QuadPoint *point;
        f32 *dst;
        point = &corners[i];
        dst = (f32 *)((u8 *)out + i * 64);
        ((Code45Im2DVertex *)dst)->position[0] = point->x;
        ((Code45Im2DVertex *)dst)->position[1] = point->y;
        ((Code45Im2DVertex *)dst)->position[2] = depth;
        ((Code45Im2DVertex *)dst)->color[0] = (f32)(u32)colors[0];
        ((Code45Im2DVertex *)dst)->color[1] = (f32)(u32)colors[1];
        ((Code45Im2DVertex *)dst)->color[2] = (f32)(u32)colors[2];
        ((Code45Im2DVertex *)dst)->color[3] = (f32)(u32)colors[3];
        ((Code45Im2DVertex *)dst)->reciprocal = inv;
    }
}

#pragma pop
/* Draw a flat four-corner rectangle, optionally saving the six immediate-mode render states. */
// FUN_0045D6E0
void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState)
{
    struct {
        s32 saved[6];
        /* Four 64-byte Sky vertices; the SDK overlay requires quadword alignment. */
        f32 out[64] __attribute__((aligned(16)));
        Code45Float4 pos;
    } work;
    u32 i;
    u32 j;
    Code45RenderState *p;

    work.pos = *(Code45Float4 *)rectangleData;
    if (preserveState != 0) {
        for (i = 0; i < 6; i++) {
            p = &D_00712490[i];
            D_00887304[0](p->state, (void *)&work.saved[i]);
            D_00887300[0](p->state, p->val);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    memset(work.out, 0, 0x100);
    PrimBuildQuadVertices(work.out, colorData, (s32 *)&work.pos, depth);
    D_00887310[0](4, work.out, 4);
    if (preserveState != 0) {
        for (j = 0; j < 6; j++) {
            p = &D_00712490[j];
            D_00887300[0](p->state, work.saved[j]);
        }
    }
}

/* Consume a queued rectangle snapshot and release its packet after drawing. */
// FUN_0045D890
void PrimExecuteRectangle(void *unused, u8 *rectangleData)
{
    struct {
        PrimitiveRectangleSignedWords pos;
        s32 saved[6];
        u8 pad1[8];
        f32 out[64];
    } work;
    PrimitiveRectanglePacket *packet;
    f32 scale;
    s32 enabled;
    Code45RenderState *p;
    u32 i;
    u32 j;

    packet = (PrimitiveRectanglePacket *)rectangleData;
    work.pos = packet->rectangle.signedWords;
    scale = packet->depth;
    enabled = packet->saveState;
    if (enabled != 0) {
        for (i = 0; i < 6; i++) {
            p = &D_00712490[i];
            D_00887304[0](p->state, (void *)&work.saved[i]);
            D_00887300[0](p->state, p->val);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    PrimBuildQuadVertices(work.out, packet->color.rgba, work.pos.word, scale);
    D_00887310[0](4, work.out, 4);
    if (enabled != 0) {
        for (j = 0; j < 6; j++) {
            p = &D_00712490[j];
            D_00887300[0](p->state, work.saved[j]);
        }
    }
    D_008873EC[0](rectangleData);
}

