#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern void func_004ccb38(s32);
extern void kwlnMainLoop(void);
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
extern void H_Cdvd_UpdateRequests(void);
extern void resourceLoadSprites(void);
extern void sdkSndUpdateDecodeSlots(void);
extern void sdkSndUpdate(void);
extern void sdkPadUpdateAll(void);
extern s32 kwlnTaskRunFrame(void);
extern void hsfdSuspendWorker(void);
extern void func_003e5510(s32);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern f32 iGpffffba6c;
extern void RpSkyRenderStateSet(s32, s32);
extern void kwlnInitIop(void);
extern void kwlnInitEngine(void);
extern void kwlnInitSubsystems(void);
extern void RpRandomSeed(s32);
extern void RpRandomSeedMT(s32);
extern s32 kwlnEnableInterrupts(void);
extern void mainDrawStartClearOt(void);
extern void mainDrawStartFrame(void);
extern void sequenceCreate(void);
extern void sequenceRequest(s32 sequenceId, s32 parameters, s32 parameterSize, s32 delay);
extern void datKernelInitNoop(void);
extern void tickerStartTask(void);
extern void fadeCreateController(s32 parentTask);
extern u8 *resrcMngSpawnRenderTask(u8 *parentTask);
extern void FldFilterLoadFile(void);
extern void btlUnitLoadSyncedAssets(void);
extern void mdlAppRegisterModelCallbacks(void);
extern void mdlAppPreloadResource(void);
extern void cmmLoadTables(void);
extern void cldSchedulerInit(void);
extern void cldDayChangePreloadData(void);
extern void mtSceneIconLoadDirectory(void);
extern void frFontStartup(void);
extern void itfMesLoadData(void);
extern void itfMesInitManager(void);
extern void scrInitPools(void);
extern void loadingSpinnerTaskCreate(void);
extern void fclShopLoadMessageResources(void);
extern void nLineInit(void);
extern void RpSkySelectTrueTSClipper(s32);
extern void RpSkySelectTrueTLClipper(s32);
extern void func_00418b18(s32);
extern void memset(void *, s32, s32);
extern void sdkDbprtInit(s32 cameraAddress);
extern void kwlnTaskInitPool(s32 capacity);
extern void H_Cdvd_ResetStreamState(void);
extern void H_Cdvd_InitDevices(void);
extern s32 kwlnGetCamera(void);
extern u8 D_005DD680[];
/* Prefix of RenderWare's RwGlobals/RwDevice (ourGlobals); member access lets device fields like
 * zBufferNear and the Im2D entry points be addressed absolutely, as retail does. */
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
extern void sdkSndInit(void);
extern void sdkSndSetSlotTrack(s32 slotIndex, s32 trackId);
extern void mdlRenderInitializeBuffers(void);
extern void PrimCreatePools(s32 queueCount, s32 batchCount);
extern void hMaestroCreateServicesTask(void);
extern void hsfdInitWorker(void);
extern void sdkSetActiveHandle(s32 handle);
extern void mdlResetModelTable(s32 model);
extern void TnSetTableBase(s32 table);
extern void TnInitModule(s32 taskPriority);
extern void mdlEffectSetGlobalValue(s32 value);
extern void AfPackInit(s32 drawList, s32 taskPriority);
extern void func_004c6eb0(s32);
extern s32 func_004c6f50(s32, s32, s32);
extern void func_004c7188(s32);
extern void func_004ca720(void);
extern void func_004cc200(s32, s32);
extern void func_004cc218(s32);
extern void func_004cd470(s32, s32);
extern void mwPlyInitSfdFx(void *iprm);
extern void func_004d8c78(void);
extern void func_004f2798(s32, s32);
extern void func_004f34b0(s32);
extern void func_004f5bf0(s32, s32, s32);
extern void kwlnPrintStreamError(void);
extern void kwlnLogStreamError(void);
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
/* The linker symbol anchors three consecutive single-precision constants. */
typedef struct KwlnInitConstants {
    f32 unk00;
    f32 unk04;
    f32 unk08;
} KwlnInitConstants;
extern f32 fGpffff8030;
extern u8 iGpffff85d0;

/* measured: tailcall on gives the bare jump wrapper retail uses. */
#pragma tailcall on
#pragma tailcall off
// Callback that calls func_004ccb38(0), then runs sync and ei to re-enable interrupts; registered
// through func_00418b18.
// FUN_00100E30
/* measured: enabling interrupts needs the literal sync/ei instruction pair in order. */
s32 kwlnEnableInterrupts(void)
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

/* measured: retail reloads values at each use instead of forwarding earlier copies, so propagation
 * stays off. */
#pragma opt_propagation off
/* measured: opt_loop_invariants off stops the four queue-address expressions being hoisted across
 * their wait loops; opt_common_subs off keeps each GP-anchor address computed at its retail call
 * site. */
#pragma opt_common_subs off
// Initialises the kwln subsystems: active handle, task and primitive pools, CD streams and devices,
// sound, and the active-handle table.
// FUN_00100E60
void kwlnInitSubsystems(void)
{
    s32 one;
    sdkSetActiveHandle((s32)&scrReleaseActiveHandle);
    kwlnTaskInitPool(0x190);
    PrimCreatePools(0x7D0, 0x64);
    H_Cdvd_ResetStreamState();
    H_Cdvd_InitDevices();
    datKernelInitNoop();
    mdlRenderInitializeBuffers();
    sdkSndInit();
    memset(&D_00764D10[0], 0, 0x14);
    D_00764D10[0] = (s32)((u8 *)&D_00761690 + 4);
    D_00764D14[0] = 0;
    func_004d32f8((s32)&D_00764D10[0]);
    func_004cc218(0);
    one = 5;
    func_004cd470(one, one);
    func_004ca720();
    func_004d8c78();
    func_004cc200((s32)&kwlnLogStreamError, 0);
    func_00418b18((s32)&kwlnEnableInterrupts);
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
    D_00764D30[0] = ((KwlnInitConstants *)&fGpffff8030)->unk08;
    one = 1;
    D_00764D34[0] = one;
    D_00764D38[0] = one;
    D_00764D3C[0] = 0;
    mwPlyInitSfdFx(&D_00764D30[0]);
    func_004cc200((s32)&kwlnPrintStreamError, 0);
    sdkSndSetSlotTrack(0, 1);
    sdkSndSetSlotTrack(1, 2);
    mdlResetModelTable((s32)&D_005DC878);
    mdlAppRegisterModelCallbacks();
    sdkDbprtInit(kwlnGetCamera());
    RpSkySelectTrueTSClipper(1);
    RpSkySelectTrueTLClipper(1);
    hsfdInitWorker();
    TnInitModule(0xC7);
    TnSetTableBase((s32)&D_005DC7D0);
    mdlEffectSetGlobalValue((s32)&D_007948A0);
    AfPackInit((s32)&D_00794510, 0xC7);
    btlUnitLoadSyncedAssets();
    cmmLoadTables();
    mtSceneIconLoadDirectory();
    mdlAppPreloadResource();
    frFontStartup();
    itfMesInitManager();
    itfMesLoadData();
    fclShopLoadMessageResources();
    scrInitPools();
    cldDayChangePreloadData();
    cldSchedulerInit();
    mainDrawStartClearOt();
    mainDrawStartFrame();
    hMaestroCreateServicesTask();
    sequenceCreate();
    FldFilterLoadFile();
    loadingSpinnerTaskCreate();
    sequenceRequest(0x1E, 0, 0, 0);
    resrcMngSpawnRenderTask(NULL);
    tickerStartTask();
    fadeCreateController(0);
    nLineInit();
}

#pragma opt_common_subs on
// Runs one kwln frame: updates CD requests, sprites, sound and pad, runs the task frame, advances
// frame counters; returns 0 if the task frame is not ready.
// FUN_00101270
s32 kwlnRunFrame(void)
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
    H_Cdvd_UpdateRequests();
    resourceLoadSprites();
    sdkSndUpdateDecodeSlots();
    sdkSndUpdate();
    sdkPadUpdateAll();
    if (kwlnTaskRunFrame() == 0) {
        return 0;
    }
    hsfdSuspendWorker();
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

// kwln main loop: runs the init steps, seeds the random number generators from the boot seed, then
// runs frames forever.
// FUN_00101350
void kwlnMainLoop(void)
{
    kwlnInitIop();
    kwlnInitEngine();
    kwlnInitSubsystems();
    RpRandomSeed(*(u32 *)0x10000000);
    RpRandomSeedMT(*(u32 *)0x10000000);
loop_1:
    kwlnRunFrame();
    goto loop_1;
}

/* Setting kind = 4 before data = &iGpffffba6c follows the order retail loads the arguments. */
// FUN_001013A0
/* Install the optional global render-state configuration, including packed color. */
void kwlnApplyRenderStateConfig(void)
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

