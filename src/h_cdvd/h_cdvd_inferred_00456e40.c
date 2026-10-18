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
extern void func_00440b68();
extern u8 D_007117C8[];
extern u8 D_007117E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 *func_003c9eb0(void *arg0);
extern u8 *func_003c3d20(s32 arg0);
extern void func_003c38b0(void *arg0, void *arg1);
extern void func_003cbe80(void *arg0, void *arg1);
extern u8 *func_003e9320(void);
extern void func_003e9df0(void *arg0);
extern void func_003efd20(void *arg0, void *arg1);
extern void func_003c3cc0(void *arg0);
extern s32 func_003e89c0(void);
extern void func_003e8970(void *arg0, s32 arg1);
extern u8 *kwlnCameraCreate(u32 arg0, u32 arg1, u32 arg2);
extern void func_003e81c0(void *arg0, f32 arg1);
extern void func_003e8180(void *arg0, f32 arg1);
extern void func_003cbc10(void *arg0, void *arg1);
extern void func_003e9d50(void *arg0, void *arg1, s32 arg2, f32 arg3);
extern void kwlnCameraResizeView(void *arg0, void *arg1, f32 arg2, f32 arg3);
extern s32 func_00410360(void);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 00456e40-00456e40 */

extern u8 *H_Cdvd_CreateFileDevice(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured probe: opt_propagation off preserves allocator-table liveness for 00456c60. */
/* measured probe: close opt_propagation scope after func_00456c60. */
// Intent: creates the scene parent objects, the two UI camera slots, and the main camera with its clip planes. Stores each in its global.
// FUN_00456E40
void kwlnInitSceneRig(void) {
    struct {
        s32 viewport[4];
        s32 dimensions[2];
        u8 pad[0x18];
        s32 bounds[6];
    } work;
    u8 *slot;
    u8 *parent;
    u8 *obj;

    work.bounds[5] = 0xC3160000;
    work.bounds[4] = 0xC3160000;
    work.bounds[3] = 0xC3160000;
    work.bounds[2] = 0x43160000;
    work.bounds[1] = 0x43160000;
    work.bounds[0] = 0x43160000;
    obj = func_003c9eb0(work.bounds);
    iGpffffba70 = (s32)obj;
    if ((parent = func_003c3d20(2)) != NULL) {
        func_003c38b0(parent, D_00711800);
        func_003cbe80(obj, parent);
    }
    iGpffffba74 = parent;
    parent = (u8 *)iGpffffba70;
    if ((slot = func_003c3d20(1)) != NULL) {
        if ((obj = func_003e9320()) != NULL) {
            ((RwObject*)slot)->flags = 1;
            func_003e9df0(obj);
            func_003efd20(slot, obj);
            func_003c38b0(slot, D_00711810);
            func_003cbe80(parent, slot);
        } else {
            func_003c3cc0(slot);
            goto loop_00456e40_second_done;
        }
    } else {
loop_00456e40_second_done:
        slot = NULL;
    }
    iGpffffba78 = slot;
    parent = (u8 *)iGpffffba70;
    if ((slot = func_003c3d20(1)) != NULL) {
        if ((obj = func_003e9320()) != NULL) {
            ((RwObject*)slot)->flags = 1;
            func_003e9d50(obj, D_00756500, 0, 25.0f);
            func_003e9d50(obj, D_00756510, 2, 170.0f);
            func_003efd20(slot, obj);
            func_003c38b0(slot, D_00711820);
            func_003cbe80(parent, slot);
        } else {
            func_003c3cc0(slot);
            goto loop_00456e40_third_done;
        }
    } else {
loop_00456e40_third_done:
        slot = NULL;
    }
    iGpffffba7c = slot;
    parent = (u8 *)iGpffffba70;
    func_003e8970(work.dimensions, func_003e89c0());
    if ((obj = kwlnCameraCreate(work.dimensions[0], work.dimensions[1], 1)) != NULL) {
        func_003e81c0(obj, 25600.0f);
        func_003e8180(obj, 20.0f);
        func_003cbc10(parent, obj);
        work.viewport[0] = 0;
        work.viewport[1] = 0;
        work.viewport[2] = work.dimensions[0];
        work.viewport[3] = work.dimensions[1];
        kwlnCameraResizeView(obj, work.viewport, 0.5f, fGpffff802c);
        ((RwCamera*)obj)->fogPlane = fGpffff8030;
    }
    iGpffffba80 = (s32)obj;
    func_00440b68(D_00711830, func_00410360(),
                  ((RwCamera*)obj)->frameBuffer->depth,
                  ((RwCamera*)obj)->zBuffer->depth);
}

