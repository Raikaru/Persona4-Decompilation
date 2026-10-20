#include "include_asm.h"
#include "type.h"
#include "h_cdvd_internal.h"
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

extern void func_0042eae0(s32);
extern void sceCdMmode(s32);
extern void func_0042efe0(s32);
extern void movieResetSlotFlags(s32);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0045; members 004543d0-004544b0 */

#pragma push
#pragma pop
/* The visible range, step, limit, selection and scroll offset share one list state. */
typedef struct HCdvdListState {
    u8 pad00[0x14];
    s32 visibleCount;
    u8 pad18[4];
    s32 step;
    s32 count;
    s32 selected;
    s32 offset;
} HCdvdListState;

// Intent: held-input repeat step forward. Advances the record's counter at +0x28 by the step at +0x1C, clamped to the limit at +0x20. Returns 0 at the end of the list.
// FUN_004543D0
/* Raw accesses retain MATCH: the typed rewrite changed instruction selection; field widths and offsets remain documented by the layout above. */
s32 sdkListStateRepeatForward(u8 *state) {
    s32 visibleCount;
    s32 nextOffset;
    s32 offset;
    s32 reloadedCount;
    s32 count;
    s32 reloadedVisibleCount;
    s32 clampedCount;

    visibleCount = *(s32 *)(state + 0x14);
    count = *(s32 *)(state + 0x20);
    clampedCount = visibleCount;
    if (count < visibleCount) {
        clampedCount = count;
    }
    offset = *(s32 *)(state + 0x28);
    if ((offset + visibleCount) >= count) {
        goto zero;
    }
    nextOffset = offset + *(s32 *)(state + 0x1C);
    *(s32 *)(state + 0x28) = nextOffset;
    reloadedVisibleCount = *(s32 *)(state + 0x14);
    reloadedCount = *(s32 *)(state + 0x20);
    if (reloadedCount >= (nextOffset + reloadedVisibleCount)) {
        goto one;
    }
    *(s32 *)(state + 0x28) = reloadedCount - reloadedVisibleCount;
    goto one;
zero:
    *(s32 *)(state + 0x28) = count - clampedCount;
    *(s32 *)(state + 0x24) = clampedCount - 1;
    return 0;
one:
    return 1;
}

// Intent: held-input repeat step back. Decrements the record's counter at +0x28 by the step at +0x1C, clamped at zero. Returns 0 at the start of the list.
// FUN_00454460
/* The three exits are laid out with explicit gotos because retail places the
   `return 0` block and the `return 1` block out of line, in that order, after
   the main body. The natural nested-if / result-variable spellings all merge
   them into one epilogue and come out two words short (nd 24). */
/* Raw accesses retain MATCH: the typed rewrite changed instruction selection; field widths and offsets remain documented by the layout above. */
s32 sdkListStateRepeatBack(u8 *state) {
    s32 offset;
    s32 nextOffset;

    offset = *(s32 *)(state + 0x28);
    if (offset <= 0) {
        goto zero;
    }
    nextOffset = offset - *(s32 *)(state + 0x1C);
    *(s32 *)(state + 0x28) = nextOffset;
    if (nextOffset >= 0) {
        goto one;
    }
    *(s32 *)(state + 0x28) = 0;
    goto one;
zero:
    *(s32 *)(state + 0x28) = 0;
    *(s32 *)(state + 0x24) = 0;
    return 0;
one:
    return 1;
}

// Intent: resets the CD streaming state: sets the CD mode, clears the stream table and the movie slot flags.
// FUN_004544B0
void H_Cdvd_ResetStreamState(void)
{
    s32 index;
    u8 *table;

    func_0042eae0(0);
    sceCdMmode(2);
    func_0042efe0(0);
    *(u8 **)D_008D1B80 = NULL;
    *(u8 **)D_008D1B84 = NULL;
    *(s32 *)D_008D1C90 = 0;
    *(s32 *)D_008D1C98 = 0;
    *(s32 *)D_008D1B88 = 0;
    index = 0;
    table = D_008C8780;
    while (index < 0x100) {
        ((HCdvdCache*)table)[index].isValid = 0;
        index += 1;
    }
    *(s32 *)D_008D1CD4 = 0;
    movieResetSlotFlags(index);
}

