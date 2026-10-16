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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0045.c; members 0045ed60-0045ee00 */

extern void K_ClumpLookAtBasis(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void func_0045b430(void);
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
/* STEP 4 (2026-09-20): this MATCH rests on a banned construct. `volatile u8 *arg0` */
/* is compiler-steering (H001): arg0 is a plain color buffer, not hardware, and the */
/* qualifier exists only to defeat b210 CSE. Re-measured 2026-09-20 in isolated */
/* probe copies (production never written for probes): baseline volatile + prop off */
/* probe_variants 0 words, fndiff 0 (obj 148B/window 160B, 12B zero tail); plain u8 * */
/* + prop off only: probe 22 words, fnalign 9 edits (retail 36 vs object 29 instrs, */
/* 8 lbu in two reload groups deleted, call tail exact) -- plain CSEs the reloads; */
/* plain + prop off + common_subs off (function-scoped): probe 1 word, fnalign 1 edit */
/* (retail move $a3,$a2 vs object addiu $a3,$zero,3; 37/37 instrs) -- reloads return */
/* but the 3,3 pair un-CSEs from retail li $a2,3 / move $a3,$a2; narrower scope */
/* (common off before fn, on inside before call): probe 22 words, fnalign 9 edits */
/* identical to plain -- pragma is function-granular, cannot split loads from call; */
/* reordered 3,3 (s32 n=3 as n,n / 3,n / n,3; s32 a=3,b=a as a,b): probe 27/28/28/28 */
/* words, copy-through fnalign 11 edits with addiu hoisted to prologue and $t1 lost. */
/* Callers: owner_of.py -> src/promoted/code1_0045.c; grep src+include finds no other */
/* volatile declaration (src/Kernel/mc.c declares void *,void *,s32,f32, not edited). */
/* opt_propagation off keeps the colors pointer in $t1; it is not the banned part. */
/* Honest plain-C best is the 1-word common-off body, still MISMATCH. */
/* measured: PrimDrawFlatTriangle MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0045ED60
void PrimDrawFlatTriangle(volatile u8 *arg0, void *arg1, s32 arg2, f32 fparg0) {
    u8 colors[12];
    u8 *ptr = colors;
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[0] = color0;
    colors[1] = color1;
    colors[2] = color2;
    colors[3] = color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[4] = color0;
    colors[5] = color1;
    colors[6] = color2;
    colors[7] = color3;
    color0 = arg0[0];
    color1 = arg0[1];
    color2 = arg0[2];
    color3 = arg0[3];
    colors[8] = color0;
    colors[9] = color1;
    colors[10] = color2;
    colors[11] = color3;
    PrimDrawPoints(ptr, arg1, fparg0, 3, 3, arg2);
}

/* measured: restores propagation after PrimDrawFlatTriangle. */
/* measured: PrimDrawRadialTriangle MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0045EE00
void PrimDrawRadialTriangle(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, f32 fparg0, f32 fparg1, u8 *arg4) {
    u8 colors[12];
    f32 coords[6];
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f22_3;
    f32 temp_f21;
    f32 temp_f0;
    temp_f23 = fGpffff8200 * fparg0;
    temp_f22 = sinf(temp_f23);
    temp_f0 = cosf(temp_f23);
    arg3 = -arg3;
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[0] = (f32)arg0 + (zero * temp_f0 + scale * temp_f22);
        coords[1] = (f32)arg1 + (zero * -temp_f22 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[0] = color0;
    colors[1] = color1;
    colors[2] = color2;
    colors[3] = color3;

    {
        f32 offset;
        offset = 120.0f;
        fparg0 = add_f32(offset, fparg0);
    }
    if (!(fparg0 < 360.0f)) {
        fparg0 -= 360.0f;
    }
    temp_f23 = fGpffff8200 * fparg0;
    temp_f22 = sinf(temp_f23);
    temp_f0 = cosf(temp_f23);
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[2] = (f32)arg0 + (zero * temp_f0 + scale * temp_f22);
        coords[3] = (f32)arg1 + (zero * -temp_f22 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[4] = color0;
    colors[5] = color1;
    colors[6] = color2;
    colors[7] = color3;

    {
        f32 offset;
        offset = 120.0f;
        fparg0 = add_f32(offset, fparg0);
    }
    if (!(fparg0 < 360.0f)) {
        fparg0 -= 360.0f;
    }
    temp_f22_3 = fGpffff8200 * fparg0;
    temp_f21 = sinf(temp_f22_3);
    temp_f0 = cosf(temp_f22_3);
    {
        f32 zero;
        f32 scale;
        zero = 0.0f;
        scale = (f32)arg3;
        coords[4] = (f32)arg0 + (zero * temp_f0 + scale * temp_f21);
        coords[5] = (f32)arg1 + (zero * -temp_f21 + scale * temp_f0);
    }
    color0 = arg2[0];
    color1 = arg2[1];
    color2 = arg2[2];
    color3 = arg2[3];
    colors[8] = color0;
    colors[9] = color1;
    colors[10] = color2;
    colors[11] = color3;
    PrimDrawPoints(colors, coords, fparg1, 3, 3, (s32)arg4);
}

