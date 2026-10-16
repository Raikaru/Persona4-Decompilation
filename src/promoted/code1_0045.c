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
extern void PrimDrawPoints(void *arg0, void *arg1, f32 farg0, s32 arg2, s32 arg3, s32 arg4);
extern void func_00446ed8(void *buf, const void *fmt, void *va);
extern void func_00450a50(PackedColor4 color, PackedVec2f position, f32 depth, void *characters);
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
extern void RwMatrixUpdate(void *arg0);
extern void RwV3dNormalize(f32 *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
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
extern u32 K_Clump_MatUsrDataHasData(const RpMaterial *material, const char *name);
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
extern void func_003e18c0(void *object, void *callback, s32 userdata);
extern void func_003ca270(void *object, void *callback, void *userdata);
extern void func_003c21e0();
extern void kwlnTaskDispatchCallback(u8 *arg0, s32 arg1);
extern void sdkPadUpdateRecord(void *arg0);
extern void sdkPadCookInput(s32 arg0);
extern void sdkPadDispatchButtons(s32 arg0);
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
extern void func_004533d0(void);
extern void func_00453310(s32 arg0, u16 arg1, s32 arg2);
extern void sdkPadRepeatButton(s32 arg0, u16 arg1, s32 arg2);
extern u8 *K_ClumpMatColorScale(u8 *arg0, u8 *arg1);
extern void H_Cdvd_BuildPathUppercase(s32 arg0, void *arg1);
extern void memcpy(void *dst, void *src, s32 size);
extern void strcat(void *arg0, void *arg1);
extern void H_Cdvd_RegisterArchiveEntry(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
extern void *FldRc_ScaleGeometryColors(void *arg0, void *arg1);
extern u8 *K_ClumpMatPropScale(u8 *material, u8 *data);
extern void *FldRc_SetGeometryVector(void *arg0, void *arg1);
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern void func_004244c8();
extern u8 D_00711720[];
extern s32 func_003bcfa0(RpMaterial *material, char *name, s32 format, s32 numElements);
extern void func_003bd0d0(u8 *userData, s32 index, s32 value);
extern s32 D_00711870_abs[];
extern s32 D_00711890_abs[];
extern f32 func_003bd090(u8 *userData, s32 index);
extern void func_003bd0f0(u8 *userData, s32 index, f32 value);
extern void func_00430e28(void);
extern void func_00430f80();
extern void func_0043bb70();
extern void func_0043c008(s32 arg0);
extern void func_0043c010(s32 arg0);
extern void func_0043c0c0();
extern s32 func_0043bcb8();
extern u8 D_008E4090[];
extern u8 D_008E4230[];
extern s32 D_008E4018_abs[];
extern s32 D_008E40B4_abs[];
extern s32 D_008E40F8_abs[];
extern s32 D_008E413C_abs[];
extern s32 D_008E4180_abs[];
extern s32 D_008E41C4_abs[];
extern s32 D_008E4208_abs[];
extern s32 strlen(void *arg0);
extern s32 func_00426cf0(void *arg0, s32 arg1, s32 arg2);
extern s32 func_004270f8(s32 arg0, s32 arg1, s32 arg2);
extern void func_00426f80(s32 arg0);
extern void func_00428f08(void *arg0, s32 arg1);
extern s32 func_003dd900(s32 arg0);
extern s32 func_003dd290(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void func_00440b68();
extern u8 D_007117C8[];
extern u8 D_007117E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void H_Cdvd_FileContextSlot(void);
extern void H_Cdvd_FileContextFree(void);
extern void H_Cdvd_SlotRead(void);
extern void H_Cdvd_SlotWrite(void);
extern void adminiSeqExitTest(void);
extern void H_Cdvd_SlotSeek(void);
extern s32 H_Cdvd_ProbeFile(s32 arg0);
extern u8 *H_Cdvd_FileContextPath(void);
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

extern void func_0042eae0(s32 arg0);
extern void sceCdMmode(s32 arg0);
extern void func_0042efe0(s32 arg0);
extern void movieResetSlotFlags(s32 arg0);
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
#pragma opt_loop_invariants on
static inline s32 overlayAtlasColumn(s32 value)
{
    return value % 16;
}


#pragma pop
#pragma push
#pragma opt_loop_invariants on
/* Character codes are normalized as bytes; the atlas column retains
 * the signed remainder operation used by the original renderer. */
static inline s32 fontAtlasColumn(s32 value)
{
    return value % 16;
}

#pragma pop
#pragma optimization_level 1
#pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2



#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop
// FUN_00453310
void func_00453310(s32 arg0, u16 arg1, s32 arg2) {
    s32 off;
    s32 bits;
    u16 *word;
    u8 *timer;

    off = arg0 * 0x4A;
    bits = arg1 & 0xFFFF;
    if (bits & *(u16 *)(D_008C0316 + off)) {
        *(u8 *)(D_008C031E + off + arg2) = 7;
        return;
    }
    if (bits & *(u16 *)(D_008C0314 + off)) {
        timer = D_008C031E + off;
        timer = timer + arg2;
        *timer -= 1;
        if (*timer == 0) {
            word = (u16 *)(D_008C031A + off);
            *word |= arg1;
            *timer = 3;
        }
    }
}
// FUN_004533D0
void func_004533d0(void)
{
    s16 remaining;
    s16 phase;
    s16 pending;

    phase = iGpffffba1c;
    switch (phase) {
    case 0:
        iGpffffba34 = 0;
        iGpffffba2c = 0;
        iGpffffba20 = 0;
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        iGpffffba1c = (s16)(phase + 1);
        return;
    case 1:
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        return;
    case 2:
        if (iGpffffba34 == 0) {
            iGpffffba1c = 1;
            return;
        }
        remaining = iGpffffba30;
        if (remaining == 0) {
            if (iGpffffba24 == 0) {
                pending = iGpffffba20;
                D_008C030C[0] = pending & 1;
                D_008C030E[0] = pending & 0xFF;
                iGpffffba30 = iGpffffba2c;
                iGpffffba24 = 1;
            } else {
                D_008C030C[0] = 0;
                D_008C030E[0] = 0;
                iGpffffba30 = iGpffffba28;
                iGpffffba24 = 0;
            }
        } else {
            iGpffffba30 = (s16)(remaining - 1);
        }
        iGpffffba34 -= 1;
        return;
    }
}
// FUN_004534F0
void func_004534f0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (func_004535b0() == 0) {
        return;
    }
    iGpffffba34 = arg0;
    iGpffffba30 = 0;
    iGpffffba2c = arg2;
    iGpffffba28 = arg3;
    iGpffffba20 = arg1;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}

// FUN_004535B0
s32 func_004535b0(void)
{
    return iGpffffac74;
}





#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop

#pragma opt_propagation off
#pragma opt_propagation on
extern s32 kwlnGetCamera(void);





#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_scalarize off
#pragma pop
// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}




/* The slot loop indexes the global array directly with an s16 counter (the
   dsll32/dsra32 pairs are that counter's sign extension); the second loop is
   a separate s16 counter zeroed BEFORE the D_008E4018 store, which is what
   gives it $v1 and leaves the first counter's $a1 alone. */
/* measured: opt_loop_invariants on hoists the array base into $v1 ahead of
   the loop as retail; a named base local is coloured $a0 (archived nd 8). */
#pragma opt_loop_invariants on
// FUN_0045B430
void func_0045b430(void) {
    s16 i;
    s16 j;

    func_00430e28();
    func_0043c008(0);
    func_0043c010(0x20);
    func_0043bb70(D_008E4230, 0x20, 0);
    func_0043c0c0(0, 0x8F, 0);
    func_0043c0c0(3, 0x83, 0x105, 0x3C, 0);
    func_0043c0c0(3, 0x84, 0x3C, 0x3C);
    func_0043c0c0(3, 0x82, 1);
    func_00430f80(1, 0x8010, 0x800, 0xFC0);
    func_00430f80(1, 0x8010, 0x801, 0xFCC);
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 6; i++) {
        *(s16 *)(D_008E4090 + i * 0x44 + 0) = 0;
        *(s32 *)(D_008E4090 + i * 0x44 + 4) = 0;
        *(s32 *)(D_008E4090 + i * 0x44 + 0x18) = 0;
        *(s16 *)(D_008E4090 + i * 0x44 + 0xA) = i;
    }
    j = 0;
    D_008E4018_abs[0] = 0;
    for (; j < 0x10; j++) {
    }
    D_008E40B4_abs[0] = func_0043bcb8(0x64000);
    D_008E40F8_abs[0] = func_0043bcb8(0xE1000);
    D_008E413C_abs[0] = func_0043bcb8(0x19000);
    D_008E4180_abs[0] = func_0043bcb8(0x19000);
    D_008E41C4_abs[0] = func_0043bcb8(0x19000);
    D_008E4208_abs[0] = func_0043bcb8(0x19000);
}
#pragma opt_loop_invariants off
#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on
/* Draw a closed, twenty-segment ring after a sphere/frustum test. The
 * optional matrix supplies orientation; its translation becomes center.
 * Native b210 -O2: 1504/1504 bytes, 31 fully resolved relocations, no tail.
 * Source value/scoping order preserves the measured projection operations;
 * no per-function optimization overrides or arithmetic assembly are needed.
 * See docs/probe_archive/Projected_ring_0045fbe0_20260924.md. */
