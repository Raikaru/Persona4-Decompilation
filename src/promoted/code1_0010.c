#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;
extern void strcpy(void *dst, void *src);

extern u8 *D_00764298;
extern void func_00440b68();
extern void func_0042c0d8(void);
extern void func_004ccb38(s32 arg0);
extern u8 *kwlnProbeHeapBudget(void);
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
extern s32 initBootChainStart(void);
extern s32 kwlnTaskGetTaskByName(void *arg0);
extern void timeLimitTaskCreate(s32 arg0);
extern s32 timeLimitTaskExists(void);
extern void timeLimitTaskDestroy(void);
extern void PrimFreeBatchNode(s32 arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);

extern s32 iGpffff85b8;
extern s32 iGpffffb194;
extern s32 iGpffffb1a0;
extern s32 iGpffffb19c;
extern void H_Cdvd_UpdateRequests(void);
extern void resourceLoadSprites(void);
extern void func_0045b7c0(void);
extern void sdkSndUpdate(void);
extern void sdkPadUpdateAll(void);
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
extern void kwlnInitIop(void);
extern void kwlnInitEngine(void);
extern void kwlnInitSubsystems(void);
extern void RpRandomSeed(s32 arg0);
extern void RpRandomSeedMT(s32 arg0);
extern s32 fclBankTaskUpdate(u8 *arg0);
extern void fclBankTaskDestroy(u8 *arg0);
extern s32 kwlnEnableInterrupts(void);
extern void mainDrawStartClearOt(void);
extern void mainDrawStartFrame(void);
extern void sequenceCreate(void);
extern void sequenceRequest(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0010d7b0(void);
extern void tickerStartTask(void);
extern void fadeCreateController(s32 arg0);
extern u8 *resrcMngSpawnRenderTask(u8 *parent);
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
extern void RpSkySelectTrueTSClipper(s32 arg0);
extern void RpSkySelectTrueTLClipper(s32 arg0);
extern void func_00418b18(s32 arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void func_0044f570(s32 arg0);
extern void kwlnTaskInitPool(s32 arg0);
extern void H_Cdvd_ResetStreamState(void);
extern void H_Cdvd_InitDevices(void);
extern s32 kwlnGetCamera(void);
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
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern void sdkSndInit(void);
extern void sdkSndSetSlotTrack(s32 arg0, s32 arg1);
extern void func_0045b430(void);
extern void PrimCreatePools(s32 arg0, s32 arg1);
extern void hMaestroCreateServicesTask(void);
extern void func_00466680(void);
extern void sdkSetActiveHandle(s32 arg0);
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

/* Hardware crt0 entry. Retail clears 29 writable GPRs at 00100008..00100078
 * (registers 1..25 and 28..31, leaving k0/k1 untouched), then HI/LO, HI1/LO1,
 * SA, all 32 FPRs, the FPU accumulator and FCR31 through 00100118.
 * It clears BSS [00764280, 00938a00) before establishing the thread stack.
 * GP is installed at 001001c0; syscall 60 (SetupThread) supplies the SP
 * assigned at 001001cc. Syscall 61 receives the BSS end and a size of -1.
 * Runtime setup, interrupt enable, main(argc, argv) and exit follow.
 *
 * There is no incoming C call frame for the reset/BSS sequence. An ordinary
 * function prologue cannot run against the cleared SP, and a split hardware
 * wrapper must preserve this entry ABI as well as the entire owner object.
 * Retain the extracted entry until that boundary has an exact validated
 * replacement.
 *
 * 2026-10-09 (user-approved route: an `asm void` body with real mnemonics,
 * like func_00100220 below): blocked by the compiler. MWCC's asm-function
 * syntax has no %hi/%lo operator (`%hi(x)`, `x@h`, `x@ha`, `hi(x)` and
 * bare-symbol `lui` all fail to parse), and `la` always emits lui/addiu
 * pairs, while retail at 00100198 issues five `lui`s before their five
 * `addiu`s. The routine is Sony's crt0.s, so the faithful source is an
 * assembler file, which the build does not support for first-party units.
 * 2026-10-09: classified as vendor code (VENDOR_CODE_RANGES in
 * tools/verify.py), like the other prebuilt SDK spans.
 */
// FUN_00100008
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100008);
#pragma tailcall on
#pragma tailcall off

#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_loop_invariants on
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on

struct HCdvd;
struct RwTexture;
/* Measured: 700/704 bytes, 23 resolved code relocations and seven resolved
   jump-table entries; four zero alignment bytes. State 3 is inert, and the
   drawing callback receives the current slot. */
/* Matched.  Three shapes carried it past the draft: the four colour bytes
   are u32 locals, so `(f32)r` is the bltz/srl/or/cvt/add.s unsigned
   conversion with the mtc1 and `& 1` hoisted; the loop index and quad
   pointer live in a block scope inside each half, which is what puts the
   hoisted lui in $v0 and the counter in $t1 (function-scope counters take
   $v0 first and rotate every temporary); and the position pair is an
   f32[2] filled by an 8-byte struct copy, which stops MWCC folding
   `256.0f + x` and the y reload across the two halves into $f21/$f20.  The
   y coordinate is read into its own local before the add so the load
   precedes the constant.  RwIm2DGetNearScreenZ() is the retail near-Z read
   in the loop; an array element there hoists the whole load. */
