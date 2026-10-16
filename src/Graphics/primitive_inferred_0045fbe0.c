#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
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
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} Code45Vec3;

typedef struct RwMatrixTag {
    Code45Vec3 right;
    u32 flags;
    Code45Vec3 up;
    u32 pad1;
    Code45Vec3 at;
    u32 pad2;
    Code45Vec3 pos;
    u32 pad3;
} Code45Matrix;

typedef struct RwSphere {
    Code45Vec3 center;
    f32 radius;
} Code45Sphere;
typedef struct {
    u8 red, green, blue, alpha;
} Code45RGBA;
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

/* Source unit: src/promoted/code1_0045.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0045.c; members 0045fbe0-0045fbe0 */

extern void K_ClumpLookAtBasis(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void func_0045b430(void);
extern void PrimDrawFlatTriangle(volatile u8 *arg0, void *arg1, s32 arg2, f32 fparg0);
extern s32 func_00457120(void);
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
#pragma push
#pragma pop
/* Honest plain-C best is the 1-word common-off body, still MISMATCH. */
/* measured: restores propagation after PrimDrawFlatTriangle. */
// FUN_0045FBE0
void primCircleLine3D(const Code45Vec3 *center, f32 radius, u8 *inputColors, f32 *inputMatrix, s32 inputPreserveState)
{
    typedef union RingMatrix {
        Code45Matrix fields;
        s32 pairs[8][2];
    } RingMatrix;
    Code45Vec3 localPoint;
    Code45Vec3 worldPoint;
    Code45Vec3 cameraPoint;
    Code45Im2DVertex vertices[21];
    s32 savedStates[6];
    RingMatrix matrix;
    Code45Sphere sphere;
    u8 *colors;
    f32 *sourceMatrix;
    s32 preserveState;
    f32 angle;
    f32 farDepth;
    f32 nearPlane;
    f32 farPlane;
    f32 depthScale;
    u32 stateIndex;
    u32 restoreIndex;
    Code45Im2DVertex *vertex;

    colors = inputColors;
    sourceMatrix = inputMatrix;
    preserveState = inputPreserveState;
    sphere.radius = radius;
    sphere.center.x = center->x;
    sphere.center.y = center->y;
    sphere.center.z = center->z;
    if (RwCameraFrustumTestSphere(D_008872E0.camera, &sphere) != 0) {
        const void *view;
        farDepth = D_008872FC_abs[0];
        depthScale = D_008872F8_abs[0];
        farPlane = *(f32 *)((u8 *)(u32)func_00457120() + 0x84);
        nearPlane = *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
        view = (u8 *)(u32)func_00457120() + 0x20;
        if (sourceMatrix != NULL) {
            const s32 (*source)[2];
            s32 (*destination)[2];
            s32 remaining;
            source = (const s32 (*)[2])sourceMatrix;
            destination = matrix.pairs;
            remaining = 8;
            do {
                s32 first = (*source)[0];
                s32 second = (*source)[1];
                source++;
                remaining--;
                (*destination)[0] = first;
                (*destination)[1] = second;
                destination++;
            } while (remaining > 0);
        } else {
            matrix.fields.at.z = 1.0f;
            matrix.fields.up.y = 1.0f;
            matrix.fields.right.x = 1.0f;
            matrix.fields.up.x = 0.0f;
            matrix.fields.right.z = 0.0f;
            matrix.fields.right.y = 0.0f;
            matrix.fields.at.y = 0.0f;
            matrix.fields.at.x = 0.0f;
            matrix.fields.up.z = 0.0f;
            matrix.fields.pos.z = 0.0f;
            matrix.fields.pos.y = 0.0f;
            matrix.fields.pos.x = 0.0f;
            /* Retail expands RwMatrixSetIdentityMacro here, including its
             * read/OR/write of flags without a preceding local initialization.
             * Preserve that original defect; do not invent a flags-zero store. */
            matrix.fields.flags |= 0x20003;
        }
        matrix.fields.pos = *center;
        if (preserveState != 0) {
            for (stateIndex = 0; stateIndex < 6; stateIndex++) {
                const Code45RenderState *state = &D_00712490[stateIndex];
                D_00887304[0](state->state, &savedStates[stateIndex]);
                D_00887300[0](state->state, state->val);
            }
            D_00887300[0](1, 0);
            RpSkyRenderStateSet(2, 0x48);
            RpSkyRenderStateSet(3, 0x71801);
        }
        {
            u32 vertexIndex;
            vertex = vertices;
            angle = 0.0f;
            localPoint.y = 0.0f;
            vertexIndex = 0;
            /* Convert the saved screen-near value to the projection slope. */
            depthScale = (depthScale - farDepth) / (nearPlane - farPlane);
            while (vertexIndex < 20) {
                f32 screenDepth;
                f32 ratio;
                f32 distance;
                f32 scaledDistance;
                localPoint.x = radius * cosf(angle);
                localPoint.z = radius * sinf(angle);
                func_003e42a0(&worldPoint, &localPoint, &matrix.fields);
                func_003e42a0(&cameraPoint, &worldPoint, (const Code45Matrix *)view);
                ratio = nearPlane / cameraPoint.z;
                distance = cameraPoint.z - farPlane;
                scaledDistance = distance * depthScale;
                screenDepth = farDepth + ratio * scaledDistance;
                cameraPoint.x = 640.0f * (cameraPoint.x / cameraPoint.z);
                cameraPoint.y = 448.0f * (cameraPoint.y / cameraPoint.z);
                vertex->position[0] = cameraPoint.x;
                vertex->position[1] = cameraPoint.y;
                vertex->position[2] = screenDepth;
                vertex->reciprocal = 1.0f / screenDepth;
                vertex->color[0] = (f32)(u32)colors[0];
                vertex->color[1] = (f32)(u32)colors[1];
                vertex->color[2] = (f32)(u32)colors[2];
                vertex->color[3] = (f32)(u32)colors[3];
                vertex++;
                angle += fGpffff81f0;
                vertexIndex++;
            }
            vertex->position[0] = vertices[0].position[0];
            vertex->position[1] = vertices[0].position[1];
            vertex->position[2] = vertices[0].position[2];
            vertex->reciprocal = vertices[0].reciprocal;
            vertex->color[0] = (f32)(u32)colors[0];
            vertex->color[1] = (f32)(u32)colors[1];
            vertex->color[2] = (f32)(u32)colors[2];
            vertex->color[3] = (f32)(u32)colors[3];
            D_00887310[0](2, vertices, 21);
        }
        if (preserveState != 0) {
            for (restoreIndex = 0; restoreIndex < 6; restoreIndex++) {
                const Code45RenderState *state = &D_00712490[restoreIndex];
                D_00887300[0](state->state, savedStates[restoreIndex]);
            }
        }
    }
}

