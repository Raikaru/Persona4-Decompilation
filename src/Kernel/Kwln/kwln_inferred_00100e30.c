#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern void func_004ccb38(s32 arg0);
extern void func_00101350(void);
extern u8 D_00559810[];
extern u8 D_00559820[];

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffb1a8;
extern s32 iGpffffb9e8;
extern u8 D_005DCB58[];
extern u8 D_005DCC64[];
extern u8 D_005DCC68[];
extern u8 D_005DD6A0[];
extern u8 D_005DD6C0[];
extern u8 D_005DD610[];
extern u8 D_005DD61C[];
extern u8 D_00796A60[];
extern u8 D_00796A64[];
extern u8 D_00796A68[];
extern u8 D_00796A6C[];
extern u8 D_00796704[];
extern u8 D_00796706[];
extern u8 D_00796708[];
extern u8 D_0079671C[];
extern u8 D_0079671D[];
extern u8 D_0079671E[];
extern u8 D_00796728[];
extern u8 D_0079672C[];
extern u8 D_0079674C[];
extern u8 iGpffff85d0;
extern u8 D_00761690;
extern u8 D_005DD600[];
extern u8 D_00796700[];
extern u8 D_0079671F[];
extern u8 D_00796750[];
extern u8 D_00796754[];
extern u8 D_00796758[];
extern u8 D_0079675C[];

extern s32 iGpffff85b8;
extern s32 iGpffffb194;
extern s32 iGpffffb1a0;
extern s32 iGpffffb19c;
extern void func_00454640(void);
extern void resourceLoadSprites(void);
extern void func_0045b7c0(void);
extern void func_004594c0(void);
extern void func_00452ce0(void);
extern s32 kwlnTaskRunFrame(void);
extern void func_00466580(void);
extern void func_003e5510(s32 arg0);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern f32 iGpffffba6c;
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_00100350(void);
extern void func_00100670(void);
extern void func_00100e60(void);
extern void RpRandomSeed(s32 arg0);
extern void RpRandomSeedMT(s32 arg0);
extern s32 func_00100e30(void);
extern void mainDrawStartClearOt(void);
extern void mainDrawStartFrame(void);
extern void func_001028c0(void);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0010d7b0(void);
extern void func_00121b20(void);
extern void func_00122430(s32 arg0);
extern u8 *resrcMngSpawnRenderTask(u8 *parent);
extern void func_001605a0(void);
extern void btlUnitLoadSyncedAssets(void);
extern void mdlAppRegisterModelCallbacks(void);
extern void mdlAppPreloadResource(void);
extern void cmmLoadTables(void);
extern void func_0025ff90(void);
extern void cldDayChangePreloadData(void);
extern void func_0026d840(void);
extern void frFontStartup(void);
extern void itfMesLoadData(void);
extern void itfMesInitManager(void);
extern void func_0029d950(void);
extern void func_002aaa10(void);
extern void func_002bdf20(void);
extern void func_0034b970(void);
extern void func_003f67e0(s32 arg0);
extern void func_003f67f0(s32 arg0);
extern void func_00418b18(s32 arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void func_0044f570(s32 arg0);
extern void kwlnTaskInitPool(s32 arg0);
extern void func_004544b0(void);
extern void func_004559b0(void);
extern s32 func_00457120(void);
extern u8 D_005DD680[];
/* RenderWare keeps its engine instance in the `ourGlobals` array
   (retail 0x008872E0) and reaches device state through
   RWSRCGLOBAL(dOpenDevice): the near Z is at +0x18, the render-state and
   Im2D entry points from +0x20.  The prefix of RwGlobals/RwDevice from
   rwplcore.h is what makes a member access address it absolutely with the
   %lo folded into the load, which is retail's loop shape. */
typedef struct {
    f32 gammaCorrection;
    void *fpSystem;
    f32 zBufferNear;
    f32 zBufferFar;
    void *fpRenderStateSet;
    void *fpRenderStateGet;
    void *fpIm2DRenderLine;
    void *fpIm2DRenderTriangle;
    void *fpIm2DRenderPrimitive;
    void *fpIm2DRenderIndexedPrimitive;
} RwDeviceHead_0010;
typedef struct {
    void *curCamera;
    void *curWorld;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
    RwDeviceHead_0010 dOpenDevice;
} RwGlobalsHead_0010;
extern u32 ourGlobals[];
#define RwIm2DGetNearScreenZ() \
    (((RwGlobalsHead_0010 *)ourGlobals)->dOpenDevice.zBufferNear)
typedef struct {
    f32 x;
    f32 y;
} Float2_0010;
extern u8 D_00796460[];
extern void func_00458fa0(void);
extern void func_0045a730(s32 arg0, s32 arg1);
extern void func_0045b430(void);
extern void func_00460910(s32 arg0, s32 arg1);
extern void func_00463520(void);
extern void func_00466680(void);
extern void func_0046d6b0(s32 arg0);
extern void mdlResetModelTable(s32 arg0);
extern void TnSetTableBase(s32 arg0);
extern void TnInitModule(s32 arg0);
extern void func_004b3250(s32 arg0);
extern void AfPackInit(s32 arg0, s32 arg1);
extern void func_004c6eb0(s32 arg0);
extern s32 func_004c6f50(s32 arg0, s32 arg1, s32 arg2);
extern void func_004c7188(s32 arg0);
extern void func_004ca720(void);
extern void func_004cc200(s32 arg0, s32 arg1);
extern void func_004cc218(s32 arg0);
extern void func_004cd470(s32 arg0, s32 arg1);
extern void mwPlyInitSfdFx(void *arg0);
extern void func_004d8c78(void);
extern void func_004f2798(s32 arg0, s32 arg1);
extern void func_004f34b0(s32 arg0);
extern void func_004f5bf0(s32 arg0, s32 arg1, s32 arg2);
extern void func_00100dd0(void);
extern void func_00100e00(void);
extern void scrReleaseActiveHandle(void);
extern u8 D_00559840[];
extern u8 D_005C4EC0[];
extern u8 D_005C6350[];
extern u8 D_005DB850[];
extern u8 D_005DC788[];
extern u8 D_005DC798[];
extern u8 D_005DC7A8[];
extern u8 D_005DC7B8[];
extern u8 D_005DC7D0[];
extern u8 D_005DC878[];
extern s32 D_00764D00[];
extern s32 D_00764D04[];
extern s32 D_00764D08[];
extern s32 D_00764D0C[];
extern s32 D_00764D10[];
extern s32 D_00764D14[];
extern f32 D_00764D30[];
extern s32 D_00764D34[];
extern s32 D_00764D38[];
extern s32 D_00764D3C[];
extern u8 D_00764D50[];
extern u8 D_00794510[];
extern u8 D_007948A0[];
extern f32 fGpffff8030;
extern u8 iGpffff85d0;

/* Source unit: src/promoted/code1_0010.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0010.c; members 00100e30-001013a0 */

/* measured: tailcall on emits the retail bare jump wrapper. */
#pragma tailcall on
/* measured: close tailcall bracket around func_00100218. */
#pragma tailcall off
// FUN_00100E30
/* measured: hardware barrier probe uses the required sync/ei instructions. */
s32 func_00100e30(void)
{
    func_004ccb38(0);
    __asm__ volatile (
        ".set noreorder\n"
        "sync\n"
        "ei\n"
        ".set reorder"
        :
        :
        : "memory"
    );
    return 0;
}

/* measured: opt_propagation off keeps each GP-relative queue address in the caller's temporary registers. */
/* measured: func_00100e60 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: opt_loop_invariants off prevents the four queue-address expressions from being hoisted across their wait loops. */
/* measured: opt_common_subs off keeps each GP-anchor address materialized at its retail call site. */
/* measured: func_00100e60 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_00100E60
void func_00100e60(void)
{
    s32 one;
    func_0046d6b0((s32)&scrReleaseActiveHandle);
    kwlnTaskInitPool(0x190);
    func_00460910(0x7D0, 0x64);
    func_004544b0();
    func_004559b0();
    func_0010d7b0();
    func_0045b430();
    func_00458fa0();
    memset(&D_00764D10[0], 0, 0x14);
    D_00764D10[0] = (s32)((u8 *)&D_00761690 + 4);
    D_00764D14[0] = 0;
    func_004d32f8((s32)&D_00764D10[0]);
    func_004cc218(0);
    one = 5;
    func_004cd470(one, one);
    func_004ca720();
    func_004d8c78();
    func_004cc200((s32)&func_00100e00, 0);
    func_00418b18((s32)&func_00100e30);
    D_00764D00[0] = 6;
    D_00764D04[0] = 4;
    D_00764D08[0] = 0x3D2;
    D_00764D0C[0] = (s32)&D_00764D50;
    func_004f34b0((s32)&D_00764D00[0]);
    func_004f5bf0(0, 0, 1);
    func_004c6eb0(0);
    do {
    } while (func_004c6f50((s32)((u8 *)&D_00761690 + 8),
                           (s32)&D_005DC788, 0) != 0);
    do {
    } while (func_004c6f50((s32)((u8 *)&D_00761690 + 12),
                           (s32)&D_005DC798, 0) != 0);
    do {
    } while (func_004c6f50((s32)((u8 *)&D_00761690 + 16),
                           (s32)&D_005DC7A8, 0) != 0);
    do {
    } while (func_004c6f50((s32)((u8 *)&D_00761690 + 20),
                           (s32)&D_005DC7B8, 0) != 0);
    func_004f2798((s32)((u8 *)&D_00761690 + 8), (s32)&D_00559840);
    func_004f2798((s32)((u8 *)&D_00761690 + 12), (s32)&D_005C4EC0);
    func_004f2798((s32)((u8 *)&D_00761690 + 16), (s32)&D_005C6350);
    func_004f2798((s32)((u8 *)&D_00761690 + 20), (s32)&D_005DB850);
    func_004c7188((s32)((u8 *)&D_00761690 + 8));
    memset(&D_00764D30[0], 0, 0x20);
    D_00764D30[0] = *(f32 *)((u8 *)&fGpffff8030 + 8);
    one = 1;
    D_00764D34[0] = one;
    D_00764D38[0] = one;
    D_00764D3C[0] = 0;
    mwPlyInitSfdFx(&D_00764D30[0]);
    func_004cc200((s32)&func_00100dd0, 0);
    func_0045a730(0, 1);
    func_0045a730(1, 2);
    mdlResetModelTable((s32)&D_005DC878);
    mdlAppRegisterModelCallbacks();
    func_0044f570(func_00457120());
    func_003f67e0(1);
    func_003f67f0(1);
    func_00466680();
    TnInitModule(0xC7);
    TnSetTableBase((s32)&D_005DC7D0);
    func_004b3250((s32)&D_007948A0);
    AfPackInit((s32)&D_00794510, 0xC7);
    btlUnitLoadSyncedAssets();
    cmmLoadTables();
    func_0026d840();
    mdlAppPreloadResource();
    frFontStartup();
    itfMesInitManager();
    itfMesLoadData();
    func_002bdf20();
    func_0029d950();
    cldDayChangePreloadData();
    func_0025ff90();
    mainDrawStartClearOt();
    mainDrawStartFrame();
    func_00463520();
    func_001028c0();
    func_001605a0();
    func_002aaa10();
    func_001029a0(0x1E, 0, 0, 0);
    resrcMngSpawnRenderTask(NULL);
    func_00121b20();
    func_00122430(0);
    func_0034b970();
}

/* measured: func_00101270 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// FUN_00101270
s32 func_00101270(void)
{
    s32 counter0;
    s32 counter1;

    if (iGpffff85b8 != 0) {
        iGpffff85b8 = 0;
        *(u32 *)0x10000000 = 0;
        *(u32 *)0x10000010 = 0x83;
        goto block_5;
    }
    iGpffffb194 = *(u32 *)0x10000000;
    func_00454640();
    resourceLoadSprites();
    func_0045b7c0();
    func_004594c0();
    func_00452ce0();
    if (kwlnTaskRunFrame() == 0) {
        return 0;
    }
    func_00466580();
    func_003e5510(1);
block_5:
    counter0 = iGpffffb1a0;
    if (counter0 != -1) {
        iGpffffb1a0 = counter0 + 1;
    }
    counter1 = iGpffffb19c;
    if (counter1 != -1) {
        iGpffffb19c = counter1 + 1;
    }
    return 1;
}

// FUN_00101350
void func_00101350(void)
{
    func_00100350();
    func_00100670();
    func_00100e60();
    RpRandomSeed(*(u32 *)0x10000000);
    RpRandomSeedMT(*(u32 *)0x10000000);
loop_1:
    func_00101270();
    goto loop_1;
}

/* measured: func_001013a0 is a live plain-C MATCH (272B window, 272B object, normalized_diff 0); staging kind = 4 before data = &iGpffffba6c reproduces retail's argument materialization order. */
// FUN_001013A0
void func_001013a0(void)
{
    u32 color;
    s32 kind;
    s32 data;
    void (**base)(s32, s32);

    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0x14, 2);
        base[0](0xE, 1);
        color = ((u32)iGpffffba58 << 24) |
                ((u32)iGpffffba4c << 16) |
                ((u32)iGpffffba50 << 8) |
                (u32)iGpffffba54;
        base[0](0xF, color);
        base[0](0x10, 1);
        kind = 4;
        data = (s32)&iGpffffba6c;
        RpSkyRenderStateSet(kind, data);
        base[0](6, 1);
        base[0](8, 1);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
}

