#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 func_00457120(void);
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);
extern void func_00485b20(u8 *model);
extern void func_00485fe0();
extern void func_00485630(u8 *object);
extern void func_00486400();
extern s32 func_00486060(u8 *);
extern void func_004860f0();
extern void func_00486180();


extern void DistortParticleProjectRecords();
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern void func_004a7c00(u8 *arg0, s32 arg1);
extern void func_004a7a50(void);
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
extern void func_00492e30(u16 *emitter, f32 scale);
extern void TnSetTableBase(void *arg0);
extern void func_00485870(void *arg0);
extern void func_00485ae0(void *arg0);
extern void func_004861f0(void *arg0, f32 *arg1);
extern void func_004b1ad0(u8 *arg0);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;
extern void LineNovaUpdateCameraQuads(void);
extern void func_003efd20(u8 *arg0, s32 arg1);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void func_0040fcd0(s32 arg0, s32 arg1);
extern void func_003e8440(u8 *arg0);
extern u8 *GeometryCloneBlock(s32 arg0);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern void func_004b1a00(u8 *arg0, u8 *arg1);
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void TlpRelease(s32 arg0);
extern s32 TlpAddRef(s32 arg0);

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern void func_004866e0(u8 *arg0, u32 *arg1);
extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern void func_004bd9f8(u8 *arg0);
extern void func_00486330(u8 *arg0, void *arg1);
extern void effMiscEulerToQuatVU(f32 arg0, f32 arg1, f32 arg2);
extern f32 iGpffff836c;
extern void func_004866f0(u8 *arg0, u32 *arg1);
extern void mdlEffectBuildBasisRows(void *arg0, void *arg1);
extern void func_0048a980(f32 *arg0);
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
extern s32 func_00481d80(u16 *arg0);
extern s32 TnSlotObject(u16 arg0);
extern void func_003c42b0(s32 arg0, s32 arg1);
extern s32 TlpCreate(u16 *arg0);
extern void func_003e8110(u8 *arg0);
extern s32 func_003e8120(u8 *arg0);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern u8 *func_00401b80(void);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */



extern void DistortParticleProjectRecords();




extern void func_004865c0(u8 *arg0, s32 arg1);




// FUN_004B1090
void func_004b1090(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(*(s32 *)(instance + 0x5c), position);
}
// FUN_004B10C0
void func_004b10c0(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(*(s32 *)(instance + 0x5c), rotation);
}
// FUN_004B10F0
void func_004b10f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x4) = arg1;
}
// FUN_004B1100
void func_004b1100(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 8) = arg1;
    func_00492e30(*(u16 **)(arg0 + 0x5c), arg1);
}





// FUN_004B1250
void func_004b1250(void *arg0, f32 *arg1)
{
    f32 work[4];

    work[0] = arg1[0];
    work[1] = arg1[1];
    work[2] = arg1[2];
    work[3] = 0.0f;
    func_004861f0(arg0, work);
}
// FUN_004B1290
void func_004b1290(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    u8 scratch[16];

    effMiscEulerToQuatVU(iGpffff836c * arg1, iGpffff836c * arg2, iGpffff836c * arg3);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(scratch) : "memory");
    func_00486330(arg0, scratch);
}

// FUN_004B12E0
void func_004b12e0(u8 *arg0, u8 *arg1) {
    struct {
        f32 first[4];
        u8 result[16];
        f32 values[16];
    } work;

    work.first[0] = *(f32 *)(arg1 + 0x30);
    work.first[1] = *(f32 *)(arg1 + 0x34);
    work.first[2] = *(f32 *)(arg1 + 0x38);
    work.first[3] = 0.0f;
    func_004861f0((void *)arg0, work.first);
    work.values[0] = *(f32 *)(arg1 + 0);
    work.values[1] = *(f32 *)(arg1 + 4);
    work.values[2] = *(f32 *)(arg1 + 8);
    work.values[3] = 0.0f;
    work.values[4] = *(f32 *)(arg1 + 0x10);
    work.values[5] = *(f32 *)(arg1 + 0x14);
    work.values[6] = *(f32 *)(arg1 + 0x18);
    work.values[7] = 0.0f;
    work.values[8] = *(f32 *)(arg1 + 0x20);
    work.values[9] = *(f32 *)(arg1 + 0x24);
    work.values[10] = *(f32 *)(arg1 + 0x28);
    work.values[11] = 0.0f;
    work.values[12] = *(f32 *)(arg1 + 0x30);
    work.values[13] = *(f32 *)(arg1 + 0x34);
    work.values[14] = *(f32 *)(arg1 + 0x38);
    work.values[15] = 0.0f;
    func_0048a980(work.values);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(work.result) : "memory");
    func_00486330(arg0, work.result);
}

// FUN_004B13F0
void func_004b13f0(void *object, s32 *arg1) {
    func_004865c0(object, *arg1);
}


extern u32 func_00486700(void *object);



// FUN_004B1470
void func_004b1470(u8 *arg0, u8 *arg1)
{
    struct {
        f32 projected[3];
        u32 alignment;
        u8 vector[16];
    } scratch;

    func_004866f0(arg0, (u32 *)scratch.vector);
    mdlEffectBuildBasisRows(arg1, scratch.vector);
    func_004866e0(arg0, (u32 *)scratch.projected);
    *(f32 *)(arg1 + 0x30) = scratch.projected[0];
    *(f32 *)(arg1 + 0x34) = scratch.projected[1];
    *(f32 *)(arg1 + 0x38) = scratch.projected[2];
}

// FUN_004B14F0
void func_004b14f0(void *object, s32 *arg1) {
    *arg1 = func_00486700(object);
}


typedef signed __int128 s128;





// FUN_004B1590
void mdlEffectSeqStart(s32 arg0, s16 arg1)
{
    D_00922DA0[0] = arg0;
    D_00922DA4[0] = arg1;
    D_00922DA8[0] = 0;
    D_00922DAC[0] = 0;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}
// FUN_004B1600
void mdlEffectSeqStep(void)
{
    s32 temp_5;
    s32 limit;

    if (iGpffffbb98 != 0) {
        limit = D_00922DA0[0];
        if ((iGpffffbb94 < limit) || (limit == 0)) {
            temp_5 = iGpffffbb94;
            func_004a7c00((u8 *)&D_00922DA0[0], temp_5);
        } else {
            func_004a7a50();
            iGpffffbb98 = 0;
        }
        iGpffffbb94 = iGpffffbb94 + 1;
    }
}
extern void *func_004b16c0(void *opaqueSource);
// FUN_004B18E0
void func_004b18e0(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0xA8);
    if (h != 0) {
        TlpRelease(h);
    }
    h = *(s32 *)(arg0 + 0xAC);
    if (h != 0) {
        func_00481ee0(h);
    }
    GeometryBlockDestroy(*(s32 *)(arg0 + 0xA4));
    (*jtbl_008873EC)(arg0);
}

// FUN_004B1950
void *func_004b1950(void *opaqueSource) {
    u8 *arg0 = opaqueSource;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;

    temp_2 = func_004b16c0(NULL);
    *(s32 *)(temp_2 + 4) = *(s32 *)(arg0 + 4);
    memcpy(temp_2 + 0xC, arg0 + 0xC, 0x98);
    temp_4 = *(s32 *)(arg0 + 0xA4);
    if (temp_4 != 0) {
        temp_2_2 = GeometryCloneBlock(temp_4);
        *(u8 **)(temp_2 + 0xA4) = temp_2_2;
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2_2 + 0x10) + 0x18) + 0x30);
        *(s32 *)(temp_3 + 0) = -1;
        *(s32 *)(temp_3 + 4) = -1;
        *(s32 *)(temp_3 + 8) = -1;
        *(s32 *)(temp_3 + 0xC) = -1;
    }
    func_004b1a00(temp_2, arg0);
    return temp_2;
}
// FUN_004B1A00
void func_004b1a00(u8 *arg0, u8 *arg1) {
    s32 temp_4;
    s32 temp_4_2;

    if (*(s32 *)(arg1 + 0xAC) != 0) {
        temp_4 = *(s32 *)(arg0 + 0xAC);
        if (temp_4 != 0) {
            func_00481ee0(temp_4);
        }
        *(s32 *)(arg0 + 0xAC) = func_00481e30(*(s32 *)(arg1 + 0xAC));
        return;
    }
    if (*(s32 *)(arg1 + 0xA8) != 0) {
        temp_4_2 = *(s32 *)(arg0 + 0xA8);
        if (temp_4_2 != 0) {
            TlpRelease(temp_4_2);
        }
        *(s32 *)(arg0 + 0xA8) = TlpAddRef(*(s32 *)(arg1 + 0xA8));
    }
}
// FUN_004B1AA0
void func_004b1aa0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x8) = 0;
}

// FUN_004B1AB0
void func_004b1ab0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
}
/* Screen-space sprite update, the func_004a5fc0 sibling. It shares the COP2
 * colour pack (the asm writes the packed frame slot, retail reloads it) and
 * the frame-info struct, then projects the four corners through the camera's
 * depth range onto the 640x448 screen. */
typedef struct EffScreenSpriteFrame {
    f32 rect[4];
    u32 size[2];
    u16 corner[8];
} EffScreenSpriteFrame;

typedef struct EffScreenSpriteRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} EffScreenSpriteRGBA;

#pragma push
#pragma opt_loop_invariants on
#pragma pop
// FUN_004B2740
void func_004b2740(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
    func_004b1ad0(arg0);
}
/* measured: opt_propagation off retains the cached D_00887300 base and retail frame. */
// FUN_004B2780
#pragma opt_propagation off
s32 func_004b2780(u8 *arg0) {
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f2;
    BtlShuffleRenderStateSet *base;
    u8 *temp_17;
    u8 *temp_2;

    if (func_003e8120(*(u8 **)(arg0 + 0xC)) == 0) {
        return 0;
    }
    temp_2 = func_00401b80();
    temp_17 = temp_2;
    temp_f21 = 640.0f / (f32)*(s32 *)(temp_2 + 0xC);
    temp_f20 = 448.0f / (f32)*(s32 *)(temp_2 + 0x10);
    RpSkyRenderStateSet(2, (void *)0x2024);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    base = D_00887300;
    base[0]((RwRenderState)0xE, (void *)0);
    base[0]((RwRenderState)6, (void *)0);
    base[0]((RwRenderState)8, (void *)0);
    base[0]((RwRenderState)9, (void *)2);
    base[0]((RwRenderState)0xC, (void *)1);
    base[0]((RwRenderState)1, (void *)(u32)temp_17);
    base[0]((RwRenderState)3, (void *)3);
    base[0]((RwRenderState)4, (void *)3);
    temp_f2 = *(f32 *)D_008872FC_abs;
    temp_f0 = 1.0f / *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x84);
    *(s32 *)(work.packet + 0x00) = 0;
    *(s32 *)(work.packet + 0x04) = 0;
    *(f32 *)(work.packet + 0x08) = temp_f2;
    *(s32 *)(work.packet + 0x20) = 0x437F0000;
    *(s32 *)(work.packet + 0x24) = 0x437F0000;
    *(s32 *)(work.packet + 0x28) = 0x437F0000;
    *(s32 *)(work.packet + 0x2C) = 0x437F0000;
    *(f32 *)(work.packet + 0x18) = temp_f0;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(s32 *)(work.packet + 0x40) = 0;
    *(s32 *)(work.packet + 0x44) = 0x43800000;
    *(f32 *)(work.packet + 0x48) = temp_f2;
    *(s32 *)(work.packet + 0x60) = 0x437F0000;
    *(s32 *)(work.packet + 0x64) = 0x437F0000;
    *(s32 *)(work.packet + 0x68) = 0x437F0000;
    *(s32 *)(work.packet + 0x6C) = 0x437F0000;
    *(f32 *)(work.packet + 0x58) = temp_f0;
    *(s32 *)(work.packet + 0x50) = 0;
    *(f32 *)(work.packet + 0x54) = temp_f20;
    *(s32 *)(work.packet + 0x80) = 0x44000000;
    *(s32 *)(work.packet + 0x84) = 0;
    *(f32 *)(work.packet + 0x88) = temp_f2;
    *(s32 *)(work.packet + 0xA0) = 0x437F0000;
    *(s32 *)(work.packet + 0xA4) = 0x437F0000;
    *(s32 *)(work.packet + 0xA8) = 0x437F0000;
    *(s32 *)(work.packet + 0xAC) = 0x437F0000;
    *(f32 *)(work.packet + 0x98) = temp_f0;
    *(f32 *)(work.packet + 0x90) = temp_f21;
    *(s32 *)(work.packet + 0x94) = 0;
    *(s32 *)(work.packet + 0xC0) = 0x44000000;
    *(s32 *)(work.packet + 0xC4) = 0x43800000;
    *(f32 *)(work.packet + 0xC8) = temp_f2;
    *(s32 *)(work.packet + 0xE0) = 0x437F0000;
    *(s32 *)(work.packet + 0xE4) = 0x437F0000;
    *(s32 *)(work.packet + 0xE8) = 0x437F0000;
    *(s32 *)(work.packet + 0xEC) = 0x437F0000;
    *(f32 *)(work.packet + 0xD8) = temp_f0;
    *(f32 *)(work.packet + 0xD0) = temp_f21;
    *(f32 *)(work.packet + 0xD4) = temp_f20;
    D_00887310_abs[0]((BtlShufflePrimitive)4, (BtlShuffleSkyVertex *)work.packet, 4);
    base[0]((RwRenderState)1, (void *)0);
    func_003e8110(*(u8 **)(arg0 + 0xC));
    return 1;
}
#pragma opt_propagation on
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma pop
// FUN_004B2E00
void func_004b2e00(u8 *object) {
    u8 *base;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    s32 *slot_1;
    s32 *slot_2;
    s32 temp_17;
    s32 temp_4_2;
    s32 temp_4_3;

    base = object;
    temp_4 = *(u8 **)(base + 0xC);
    if (temp_4 != NULL) {
        temp_17 = *(s32 *)(temp_4 + 4);
        if (temp_17 != 0) {
            func_003efd20(temp_4, 0);
            func_003e9390(temp_17);
        }
        temp_3 = *(u8 **)(base + 0xC);
        slot_1 = (s32 *)(temp_3 + 0x64);
        temp_4_2 = *(s32 *)(temp_3 + 0x64);
        if (temp_4_2 != 0) {
            *slot_1 = 0;
            func_003ec330(temp_4_2);
        }
        temp_2 = *(u8 **)(base + 0xC);
        slot_2 = (s32 *)(temp_2 + 0x60);
        if (*(s32 *)(temp_2 + 0x60) != 0) {
            *slot_2 = 0;
        }
        func_003e8440(*(u8 **)(base + 0xC));
        *(u8 **)(base + 0xC) = NULL;
    }
    temp_4_3 = *(s32 *)(base + 8);
    if (temp_4_3 != 0) {
        func_0040fcd0(temp_4_3, 0);
        func_003ec330(*(s32 *)(base + 8));
        *(s32 *)(base + 8) = 0;
    }
}

// FUN_004B4EA0
void func_004b4ea0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = arg0;
    (*(void (**)(u8 *))(D_00714658 + (*(s32 *)(temp_16 + 0x18) * 0x18)))(
        *(u8 **)(temp_16 + 0x20));
    jtbl_008873EC[0](temp_16);
}

// FUN_004B4F10
void *func_004b4f10(void *opaqueSource)
{
    u8 *arg0 = opaqueSource;
    return LineNovaCreateKindInstance(*(u16 *)(arg0 + 0x18), *(u8 **)(arg0 + 0x24));
}
// FUN_004B4F40
void func_004b4f40(u8 *arg0)
{
    ((void (*)(void *))(*(u32 *)(D_00714650 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    *(s32 *)(arg0 + 0x14) = 0;
}

// FUN_004B4F90
void func_004b4f90(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x14) += 1;
}

// FUN_004B4FF0
void func_004b4ff0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    }
}

// FUN_004B5040
void func_004b5040(void *param_1) {
    u8 *object;

    object = param_1;
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)(object + 0x18) * 24)))(object);
    *(s32 *)(object + 0x14) += 1;
    if (*(s32 *)(object + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + *(s32 *)(object + 0x18) * 24)))(object);
    }
}
// FUN_004B50D0
s128 func_004b50d0(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B50E0
void func_004b50e0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x10) = arg1;
}

// FUN_004B5340
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b5340(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(s32);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 8;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(s32))(tbl + idx);
        if (fn != NULL) {
            fn(*(s32 *)(arg0 + 0x30));
        }
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004B53C0
void *func_004b53c0(void *opaqueSource)
{
    u8 *arg0 = opaqueSource;
    u8 *result;
    u8 *work;
    s32 base;
    s32 id;
    s32 off;
    s32 tex;
    s32 (*setup4)(s32, s32, s32, s32);
    void (*post)(u8 *);
    extern u8 *EffBattleAllocWork();

    id = *(s32 *)(arg0 + 0x2C);
    base = (s32)iGpffffbba0;
    off = (base, id * 0x1C);
    if (*(s32 *)(off + base + 0xC) == 0) {
        tex = *(s32 *)(arg0 + 0x38);
        off = id & 0xFFFF;
        work = EffBattleAllocWork(off, tex);
        if (iGpffffbba4() != 0) {
            off = (off & 0xFFFF) * 0x1C;
            base = (s32)iGpffffbba0;
            base += 4;
            base += off;
            setup4 = *(s32 (**)(s32, s32, s32, s32))base;
            if (setup4 != NULL) {
                *(s32 *)(work + 0x30) = setup4(tex, 0, 0, 0);
            }
            base = (s32)iGpffffbba0;
            base += off;
            post = *(void (**)(u8 *))base;
            if (post != NULL) {
                post(work);
            }
        }
        result = work;
    } else {
        work = EffBattleAllocWork((id = id & 0xFFFF),
                             (id, *(s32 *)(arg0 + 0x38)));
        {
            s32 idx2;
            idx2 = *(s32 *)(arg0 + 0x2C) * 0x1C;
            *(s32 *)(work + 0x30) =
                (*(s32 (**)(u8 *))((u8 *)(idx2 + (s32)iGpffffbba0 + 0xC)))(arg0);
        }
        off = *(s32 *)(arg0 + 0x2C) * 0x1C;
        base = (s32)iGpffffbba0;
        post = *(void (**)(u8 *))(base + off);
        if (post != NULL) {
            post(work);
        }
        result = work;
    }
    return result;
}
// FUN_004B5530
void func_004b5530(u8 *arg0) {
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        fn = *(void (**)(u8 *))(iGpffffbba0 + 0 + *(s32 *)(arg0 + 0x2C) * 0x1C);
        if (fn != NULL) {
            fn(arg0);
        }
        *(s32 *)(arg0 + 0x28) = 0;
    }
}

// FUN_004B55A0
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b55a0(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x10;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(arg0);
        }
        *(s32 *)(arg0 + 0x28) += 1;
    }
}

// FUN_004B5620
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b5620(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x14;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(arg0);
        }
    }
}

// FUN_004B5690
void func_004b5690(u8 *arg0)
{
    s32 tbl1;
    s32 idx1;
    void (*fn1)(u8 *);
    s32 tbl2;
    s32 idx2;
    void (*fn2)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl1 = (s32)iGpffffbba0 + 0x10;
        idx1 = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn1 = *(void (**)(u8 *))(tbl1 + idx1);
        if (fn1 != NULL) {
            fn1(arg0);
        }
        *(s32 *)(arg0 + 0x28) += 1;
    }
    if (iGpffffbba4() != 0) {
        tbl2 = (s32)iGpffffbba0 + 0x14;
        idx2 = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn2 = *(void (**)(u8 *))(tbl2 + idx2);
        if (fn2 != NULL) {
            fn2(arg0);
        }
    }
}
// FUN_004B5750
s128 func_004b5750(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B5760
s128 func_004b5760(u8 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *(s128 *)(arg0 + 0x10) = temp;
    return temp;
}


extern u8 *AfPackBindResource();
extern u8 *AfPackCreateInstance();
extern void AfPackStartSections();
extern void AfPackListAppend();


// FUN_004B5770
void func_004b5770(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004B5780
void func_004b5780(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 0x20) = arg1;
}
// FUN_004B5790
void func_004b5790(u8 *arg0, s32 arg1)
{
    iGpffffbba0 = arg0;
    iGpffffbba4 = (s32 (*)(void))arg1;
}
// FUN_004B57A0
u8 *func_004b57a0(void *object, s32 arg1) {
    u8 *temp_2;
    u8 *temp_2_2;

    temp_2_2 = AfPackBindResource(object);
    *(s32 *)(temp_2_2 + 0x20) = arg1;
    temp_2 = AfPackCreateInstance(temp_2_2);
    AfPackListAppend(temp_2);
    AfPackStartSections(temp_2);
    return temp_2;
}


// FUN_004BC4D0
void func_004bc4d0(u8 *arg0, f32 arg1)
{
    *(s32 *)(arg0 + 0x28) = 0;
    *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x2c);
    *(f32 *)(arg0 + 0x34) = arg1;
    *(s32 *)(arg0 + 4) |= 1;
}
// FUN_004BC500
void func_004bc500(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x2c) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xc) = 0;
}
// FUN_004BC520
void func_004bc520(u8 *arg0, f32 *arg1)
{
    *(f32 *)(arg0 + 0x2c) += *arg1;
}
/* measured: opt_propagation off with `arg1 = arg1 << 3;` as its own statement keeps the
   shift ahead of the table loads (retail sll/lw/lw/addu); with propagation on the shift
   is folded into the address expression and emitted after the loads. */
// FUN_004BC540
#pragma opt_propagation off
void func_004bc540(u8 *arg0, s32 arg1, f32 fparg0, u8 *arg2)
{
    u8 *temp_5;
    struct {
        u8 *sp8;
        u8 *spC;
    } stack;
    u8 *var_7;
    s32 var_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;

    var_7 = (u8 *)&stack;
    var_3 = 8;
    if (var_7 != NULL) {
        do {
            *var_7 = 0;
            var_7++;
            var_3--;
        } while (var_3 != 0);
    }
    arg1 = arg1 << 3;
    temp_5 = *(u8 **)(*(u8 **)(arg0 + 0) + 4) + arg1;
    stack.sp8 = temp_5 + 8;
    stack.spC = temp_5 + 0xC;
    temp_f1 = 1.0f - fparg0;

    if (*(s32 *)(arg0 + 4) & 1) {
        temp_f4 = *(f32 *)(arg0 + 0x34);
        if (temp_f4 > 0.0f) {
            temp_f2 = 1.0f - ((*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x30)) / temp_f4);
            if (temp_f2 < 0.0f) {
                temp_f2 = 0.0f;
            }
        } else if (temp_f4 == 0.0f) {
            if (*(f32 *)(arg0 + 0x2C) < *(f32 *)(arg0 + 0x30)) {
                goto set_one;
            }
            temp_f2 = 0.0f;
            goto set_progress;
        set_one:
            temp_f2 = 1.0f;
        set_progress:
            ;
        }
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0]);
        arg2[0] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1]);
        arg2[1] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2]);
        arg2[2] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3]);
        arg2[3] = (u8)temp_f3;
        return;
    }
    temp_f3 = fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0];
    arg2[0] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1];
    arg2[1] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2];
    arg2[2] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3];
    arg2[3] = (u8)temp_f3;
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
} Code1_004bBccf0Temp;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code1_004bBddVec4;
// FUN_004BCCF0
void func_004bccf0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
    Code1_004bBccf0Temp temp;
    s16 temp_6;
    u8 *var_6_2;
    s32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *var_4;
    s32 var_4_2;

    var_7 = arg3;
    temp_6 = *(s16 *)(arg0 + 0x38);
    switch (temp_6) {
    case 0:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 2) + 1;
        break;
    case 1:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    case 2:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    }
    var_4 = *(u8 **)(arg1 + 0x30);
    var_6 = 0;
    while (var_6 < var_7) {
        *(u8 *)(var_4 + 0) = 0;
        *(u8 *)(var_4 + 1) = 0;
        *(u8 *)(var_4 + 2) = 0;
        *(u8 *)(var_4 + 3) = 0;
        var_6 += 1;
        var_4 += 4;
    }
    var_6_2 = *(u8 **)(*(u8 **)(arg1 + 0x5C) + 0x14);
    var_4_2 = 0;
    while (var_4_2 < var_7) {
        *(s32 *)(var_6_2 + 0) = 0;
        *(s32 *)(var_6_2 + 4) = 0;
        *(s32 *)(var_6_2 + 8) = 0;
        var_4_2 += 1;
        var_6_2 += 0xC;
    }
    temp.a = 0;
    temp.b = 0;
    temp.c = 0;
    temp.d = (f32)1000000000;
    temp_3 = *(u8 **)(arg1 + 0x5C);
    *(Code1_004bBccf0Temp *)(temp_3 + 4) = temp;
}
// FUN_004BD4A0
f32 func_004bd4a0(u8 *arg0, u8 *arg1)
{
    Code1_004bBddVec4 a;
    Code1_004bBddVec4 b;
    f32 ad;
    f32 bd;
    f32 dot;

    a = *(Code1_004bBddVec4 *)arg0;
    b = *(Code1_004bBddVec4 *)arg1;
    ad = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
    ad = __sqrt(ad, 0.0f);
    a.x = a.x / ad;
    a.y = a.y / ad;
    a.z = a.z / ad;
    a.w = a.w / ad;
    bd = b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w;
    bd = __sqrt(bd, 0.0f);
    b.x = b.x / bd;
    b.y = b.y / bd;
    b.z = b.z / bd;
    b.w = b.w / bd;
    if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w)) {
        return 0.0f;
    }
    dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    if (dot > 1.0f) {
        dot = 1.0f;
    } else if (dot < -1.0f) {
        dot = -1.0f;
    }
    return dot;
}
// Archived C body: build/WBHygiene_func_004bd6b8_archive.txt; no current park body remains.
// FUN_004BD6B8
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd6b8);

// FUN_004BD720
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd720);
// FUN_004BD750
/* measured: schedule on fills func_004bd750's retail jr delay-slot load. */
#pragma schedule on
s32 func_004bd750(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}
/* measured: close the schedule bracket around func_004bd750. */
#pragma schedule off
