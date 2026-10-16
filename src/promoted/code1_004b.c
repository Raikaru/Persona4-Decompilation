#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 kwlnGetCamera(void);
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



extern u32 func_00486700(void *object);






typedef signed __int128 s128;





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

/* Screen-space sprite update, the EffSpriteUpdate sibling. It shares the COP2
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







typedef signed __int128 s128;









typedef signed __int128 s128;




extern u8 *AfPackBindResource();
extern u8 *AfPackCreateInstance();
extern void AfPackStartSections();
extern void AfPackListAppend();





#pragma opt_propagation off
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
