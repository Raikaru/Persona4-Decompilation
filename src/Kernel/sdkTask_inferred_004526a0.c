#include "sdk_pad_record.h"
#include "kwln_task_internal.h"
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
extern s64 D_00711858[];
extern f32 D_00711860[];
static inline f32 add_f32(f32 a, f32 b) {
    return a + b;
}
extern u8 *iGpffffb9e0;
extern void memset(void *dst, s32 value, s32 size);
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
extern void func_003e18c0(void *object, void *callback, s32 userdata);
extern void kwlnTaskDispatchCallback(u8 *arg0, s32 arg1);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 004526a0-00452760 */

#pragma pop
/* measured: restore O2 after func_00450e80. */
/* Clear parent/sibling links for the children being detached from this task. */
// FUN_004526A0
void kwlnTaskDetachChildren(u8 *parent) {
    u8 *node;
    u8 *match;

    node = (u8 *)((KwlnTask *)parent)->childList;
    goto loop_004526a0_check;
loop_004526a0_body:
    if ((u8 *)((KwlnTask *)node)->parent == parent) {
        match = node;
    }
    node = (u8 *)((KwlnTask *)node)->next;
    ((KwlnTask *)match)->parent = NULL;
    ((KwlnTask *)match)->next = NULL;
loop_004526a0_check:
    if (node != NULL) {
        goto loop_004526a0_body;
    }
}

// Intent: returns the processing task pointer (iGpffffba10) that sdkTask.c sets while a task runs and clears afterwards. The allocator assert paths print it as the current task.
// FUN_004526E0
s32 kwlnTaskGetCurrent(void)
{
    return iGpffffba10;
}

// Intent: task callback. Calls the dispatch slot D_008873FC with (arg1, arg0). Registered for a task by kwlnTaskRegisterCallback.
// FUN_004526F0
void kwlnTaskDispatchCallback(u8* task, s32 value)
{
    (*D_008873FC)(value, task);
}

// Intent: registers kwlnTaskDispatchCallback for the task node `arg0` through func_003e18c0. Called from the primitive node setup in primitive_inferred_004601c0.c.
// FUN_00452730
void kwlnTaskRegisterCallback(void *task)
{
    func_003e18c0(task, kwlnTaskDispatchCallback, (s32)task);
}

// Intent: clears the pad records and state buffers, initialises the pad library and both ports, then sets each slot's id and default repeat counter (3). Called from kwlnInitIop.
// FUN_00452760
/* measured: opt_propagation off preserves the constant 3 as a live local in $a0 and the computed pointer in $v1. */
#pragma push
/* measured: func_00452760 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void sdkPadInit(void)
{
    extern u8 D_008C032A[];
    extern u8 D_008C0240[];
    extern u8 D_008C028A[];
    extern u8 D_008C0040[];
    extern u8 D_008C0140[];
    extern s32 func_0042f6f8(s32);
    extern s32 func_0042fb50(s32, s32, u8 *);
    s32 i;
    u8 *base;
    s32 three;
    u8 *ptr;

    memset(D_008C02E0, 0, 0x4A);
    memset(D_008C032A, 0, 0x4A);
    memset(D_008C0240, 0, 0x4A);
    memset(D_008C028A, 0, 0x4A);
    func_0042f6f8(0);
    func_0042fb50(0, 0, D_008C0140);
    func_0042fb50(1, 0, D_008C0040);
    i = 0;
    base = D_008C02E0;
    three = 3;
    for (; i < 2; i++) {
        ptr = base + i * 0x4A;
        ((SdkPadRecord *)ptr)->port = i;
        ((SdkPadRecord *)ptr)->slot = 0;
        ((SdkPadRecord *)ptr)->state = 0;
        ((SdkPadRecord *)ptr)->mode = 0;
        ((SdkPadRecord *)ptr)->requestedMode = three;
    }
}
#pragma pop

