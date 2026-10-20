#include "effect_mesh_internal.h"
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
extern u32 K_Clump_MatUsrDataHasData(const RpMaterial *material, const char *name);
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
extern u8 *K_ClumpMatColorScale(u8 *material, u8 *data);
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern u8 D_00711720[];
extern s32 func_003bcfa0(RpMaterial *material, char *name, s32 format, s32 numElements);
extern void func_003bd0d0(u8 *userData, s32 index, s32 value);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 004587d0-004587d0 */

extern void K_ClumpLookAtBasis(u8 *object, u8 *position, u8 *target, f32 *referenceUp);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off preserves the retail global-load destination register. */
/* measured: close propagation-off probe for K_ClumpLookAtBasis. */
// FUN_004587D0
/* Measured: 1136/1136 bytes, 23 resolved relocations, no alignment tail.
   Separate userdata lifetimes and index-before-color declarations preserve
   register allocation; unsigned >255 clamps retain the retail branch form. */
u8 *K_ClumpMatColorScale(u8 *material, u8 *data)
{
    f32 *scale = (f32 *)data;
    s32 i;
    s32 found;

    if (K_Clump_MatUsrDataHasData((RpMaterial *)material, (const char *)D_00711870_abs) == 0)
    {
        u32 packedColor;
        s32 index;

        packedColor = ((u32)((RpMaterial *)material)->color.c[3] << 24) |
                      (((RpMaterial *)material)->color.c[0] << 16) |
                      (((RpMaterial *)material)->color.c[1] << 8) |
                      ((RpMaterial *)material)->color.c[2];

        index = func_003bcfa0((RpMaterial *)material, (char *)D_00711870_abs, rpINTUSERDATA, 1);
        func_003bd0d0((u8 *)func_003bd000((RpMaterial *)material, index), 0, (s32)packedColor);
    }

    found = 0;
    for (i = 0; i < func_003bcfb0((RpMaterial *)material); i++)
    {
        RpUserDataArray *userData;
        userData = func_003bd000((RpMaterial *)material, i);
        func_003bd040(userData);
        if (strcmp(func_003bd040(userData), (const char *)D_00711870_abs) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        s32 j;
        u32 colorValue = 0;
        u32 red;
        u32 green;
        u32 blue;
        u32 alpha;
        EffMeshColor color;

        for (j = 0; j < func_003bcfb0((RpMaterial *)material); j++)
        {
            RpUserDataArray *userData;
            userData = func_003bd000((RpMaterial *)material, j);
            if (strcmp(func_003bd040(userData), (const char *)D_00711870_abs) == 0 &&
                func_003bd050(userData) == rpINTUSERDATA)
            {
                colorValue = (u32)func_003bd070(userData, 0);
                break;
            }
        }

        red = (u32)((f32)((colorValue >> 16) & 0xFF) * scale[0]);
        green = (u32)((f32)((colorValue >> 8) & 0xFF) * scale[1]);
        blue = (u32)((f32)(colorValue & 0xFF) * scale[2]);
        alpha = (u32)((f32)((colorValue >> 24) & 0xFF) * scale[3]);

        if (red > 0xFF)
        {
            red = 0xFF;
        }
        color.c[0] = red;

        if (green > 0xFF)
        {
            green = 0xFF;
        }
        color.c[1] = green;

        if (blue > 0xFF)
        {
            blue = 0xFF;
        }
        color.c[2] = blue;

        if (alpha > 0xFF)
        {
            alpha = 0xFF;
        }
        color.c[3] = alpha;

        ((RpMaterial *)material)->color = color;
    }

    return material;
}

