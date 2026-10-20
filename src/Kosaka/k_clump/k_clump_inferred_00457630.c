#include "rw_atomic_layout_internal.h"
#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
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
extern void RwMatrixUpdate(void *);
extern void RwV3dNormalize(f32 *, f32 *);
extern void func_003e9680(void *);
extern s64 D_00711858[];
extern f32 D_00711860[];
extern u8 *iGpffffb9e0;
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
#include "rw_types_internal.h"
typedef RwV3d Code45Vec3;

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


#pragma pop
#pragma push

#pragma pop



#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 00457630-00457630 */

#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off preserves the retail global-load destination register. */
/* measured: K_ClumpLookAtBasis MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Build an orthonormal frame from position, target, and an optional reference-up vector. */
/* RwFrame modelling matrix starts at +0x10 (rw/core/baframe.h). */
struct RwFrame {
    u8 pad00[0x10];
    struct RwMatrixTag modelling;
};

/* A retained matrix pointer keeps the cross-product component loads in retail order. */
// FUN_00457630
void K_ClumpLookAtBasis(u8 *object, u8 *position, u8 *target, f32 *referenceUp) {
    struct {
        s64 qword;
        f32 value;
    } local;
    s64 fallbackPair;
    f32 fallbackZ;
    f32 *fallback;
    u8 *record;
    u8 *basis;
    struct RwMatrixTag *matrix;
    f32 *refVec;
    u8 *fwd;
    u8 *up;
    f32 forwardY;
    f32 forwardX;

    fallback = (f32 *)&local;
    fallbackPair = D_00711858[0];
    fallbackZ = D_00711860[0];
    local.qword = fallbackPair;
    local.value = fallbackZ;
    if (referenceUp == NULL) {
        refVec = fallback;
    } else {
        refVec = referenceUp;
    }
    record = (u8 *)((struct RpAtomic *)object)->frame;
    basis = record + 0x10;
    matrix = (struct RwMatrixTag *)basis;
    ((struct RwFrame *)record)->modelling.pos = *(Code45Vec3 *)position;
    ((struct RwFrame *)record)->modelling.at.x = ((Code45Vec3 *)target)->x - ((struct RwFrame *)record)->modelling.pos.x;
    ((struct RwFrame *)record)->modelling.at.y = ((Code45Vec3 *)target)->y - ((struct RwFrame *)record)->modelling.pos.y;
    ((struct RwFrame *)record)->modelling.at.z = ((Code45Vec3 *)target)->z - ((struct RwFrame *)record)->modelling.pos.z;
    fwd = basis + 0x20;
    RwV3dNormalize((f32 *)fwd, (f32 *)fwd);
    ((struct RwMatrixTag *)basis)->right.x =
        matrix->at.y * refVec[2] -
        matrix->at.z * refVec[1];
    matrix->right.y =
        matrix->at.z * refVec[0] -
        matrix->at.x * refVec[2];
    forwardY = matrix->at.y;
    forwardX = matrix->at.x;
    matrix->right.z =
        forwardX * refVec[1] -
        forwardY * refVec[0];
    RwV3dNormalize((f32 *)basis, (f32 *)basis);
    ((struct RwMatrixTag *)basis)->up.x =
        ((struct RwMatrixTag *)basis)->at.y * ((struct RwMatrixTag *)basis)->right.z -
        ((struct RwMatrixTag *)basis)->at.z * ((struct RwMatrixTag *)basis)->right.y;
    ((struct RwMatrixTag *)basis)->up.y =
        ((struct RwMatrixTag *)basis)->at.z * ((struct RwMatrixTag *)basis)->right.x -
        matrix->at.x * ((struct RwMatrixTag *)basis)->right.z;
    ((struct RwMatrixTag *)basis)->up.z =
        ((struct RwMatrixTag *)basis)->at.x * ((struct RwMatrixTag *)basis)->right.y -
        ((struct RwMatrixTag *)basis)->at.y * ((struct RwMatrixTag *)basis)->right.x;
    up = basis + 0x10;
    RwV3dNormalize((f32 *)up, (f32 *)up);
    RwMatrixUpdate(basis);
    func_003e9680(record);
}

