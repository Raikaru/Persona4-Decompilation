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
extern u8 *func_00100230(void);
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
extern void func_00100350(void);
extern void func_00100670(void);
extern void kwlnInitSubsystems(void);
extern void RpRandomSeed(s32 arg0);
extern void RpRandomSeedMT(s32 arg0);
extern s32 fclBankTaskUpdate(u8 *arg0);
extern void fclBankTaskDestroy(u8 *arg0);
extern s32 kwlnEnableInterrupts(void);
extern void mainDrawStartClearOt(void);
extern void mainDrawStartFrame(void);
extern void func_001028c0(void);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0010d7b0(void);
extern void tickerStartTask(void);
extern void func_00122430(s32 arg0);
extern u8 *resrcMngSpawnRenderTask(u8 *parent);
extern void FldFilterLoadFile(void);
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
extern void loadingSpinnerTaskCreate(void);
extern void func_002bdf20(void);
extern void nLineInit(void);
extern void func_003f67e0(s32 arg0);
extern void func_003f67f0(s32 arg0);
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
extern void func_00463520(void);
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
// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}

// Intent: Start the time limit task under the root with no parent [inferred]
// FUN_00103510
void timeLimitStart(void) {
    timeLimitTaskCreate(0);
}
// Intent: Report whether the time limit task is running [inferred]
// FUN_00103540
s32 timeLimitIsActive(void) {
    return timeLimitTaskExists() != 0;
}
// Intent: Stop the time limit task and its hierarchy [inferred]
// FUN_00103570
void timeLimitStop(void) {
    timeLimitTaskDestroy();
}
// FUN_00103590
void func_00103590(void) {}
// Intent: Apply the base render states for a bank slot's sky layer [inferred]
// FUN_001035A0
void fclBankRenderStateBase(void) {
    D_00887300[0](1, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
}
// Intent: Apply the full render states for a bank slot's sky layer, including the interpolation mode [inferred]
// FUN_00103600
void fclBankRenderStateFull(void)
{
    u8 *fnTable;

    fnTable = (u8 *)D_00887300;
    (*(void (**)(s32, s32))fnTable)(6, 1);
    (*(void (**)(s32, s32))fnTable)(8, 1);
    (*(void (**)(s32, s32))fnTable)(9, 1);
    (*(void (**)(s32, s32))fnTable)(0xC, 1);
    (*(void (**)(s32, s32))fnTable)(7, 2);
    (*(void (**)(s32, s32))fnTable)(1, iGpffffb9e8);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
}
// Intent: Bank task update: run the state machine for the slot's current state [inferred]
// FUN_001036D0
s32 fclBankTaskUpdate(u8 *arg0) {
    extern u8 *PrimAllocBatchNode(void);
    extern void PrimAppendNode(void *list, void *node);
    extern u8 D_005DD5D0[];
    extern u8 D_00793E80[];
    extern s64 iGpffff85c8;
    s32 index;
    u8 *state;
    u8 *slot;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
        {
            f32 scale;
            f32 inverse;
            s32 forty;
            s32 one;

            scale = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
            inverse = 1.0f / scale;
            forty = 0x42800000;
            *(s32 *)(state + 0x10) = forty;
            *(s32 *)(state + 0x14) = forty;
            *(f32 *)(state + 0x18) = scale;
            *(s32 *)(state + 0x50) = 0x43000000;
            *(s32 *)(state + 0x54) = forty;
            *(f32 *)(state + 0x58) = scale;
            *(s32 *)(state + 0x90) = forty;
            *(s32 *)(state + 0x94) = 0x43400000;
            *(f32 *)(state + 0x98) = scale;
            *(s32 *)(state + 0xD0) = 0x43000000;
            *(s32 *)(state + 0xD4) = 0x43400000;
            *(f32 *)(state + 0xD8) = scale;
            *(f32 *)(state + 0x28) = inverse;
            *(f32 *)(state + 0x68) = inverse;
            *(f32 *)(state + 0xA8) = inverse;
            *(f32 *)(state + 0xE8) = inverse;
            *(s32 *)(state + 0x110) = 0x43010000;
            *(s32 *)(state + 0x114) = 0x43010000;
            *(f32 *)(state + 0x118) = scale;
            *(f32 *)(state + 0x150) = (f32)385;
            *(s32 *)(state + 0x154) = 0x43010000;
            *(f32 *)(state + 0x158) = scale;
            *(s32 *)(state + 0x190) = 0x43010000;
            *(f32 *)(state + 0x194) = (f32)385;
            *(f32 *)(state + 0x198) = scale;
            *(f32 *)(state + 0x1D0) = (f32)385;
            *(f32 *)(state + 0x1D4) = (f32)385;
            *(f32 *)(state + 0x1D8) = scale;
            *(s32 *)(state + 0x120) = 0;
            *(s32 *)(state + 0x124) = 0;
            one = 0x3F800000;
            *(s32 *)(state + 0x160) = one;
            *(s32 *)(state + 0x164) = 0;
            *(s32 *)(state + 0x1A0) = 0;
            *(s32 *)(state + 0x1A4) = one;
            *(s32 *)(state + 0x1E0) = one;
            *(s32 *)(state + 0x1E4) = one;
            *(f32 *)(state + 0x128) = inverse;
            *(f32 *)(state + 0x168) = inverse;
            *(f32 *)(state + 0x1A8) = inverse;
            *(f32 *)(state + 0x1E8) = inverse;

            {
                s32 max = 0x437F0000;
                s32 i;
                i = 0;
                goto loop1_check;
loop1_body:
                *(s32 *)(state + (i << 6) + 0x30) = max;
                *(s32 *)(state + (i << 6) + 0x34) = 0;
                *(s32 *)(state + (i << 6) + 0x38) = forty;
                *(s32 *)(state + (i << 6) + 0x3C) = max;
                i++;
loop1_check:
                if (i < 4) goto loop1_body;
            }
            {
                s32 max = 0x437F0000;
                s32 i;
                i = 0;
                goto loop2_check;
loop2_body:
                *(s32 *)(state + (i << 6) + 0x130) = max;
                *(s32 *)(state + (i << 6) + 0x134) = max;
                *(s32 *)(state + (i << 6) + 0x138) = max;
                *(s32 *)(state + (i << 6) + 0x13C) = max;
                i++;
loop2_check:
                if (i < 4) goto loop2_body;
            }
            index = 0;
            while (index < 2) {
                slot = state + (index << 2) + 4;
                *(u8 **)slot = PrimAllocBatchNode();
                *(s16 *)(*(u8 **)slot + 0x18) = 11;
                *(s32 *)(*(u8 **)slot + 0x1C) = 4;
                *(u8 **)(*(u8 **)slot + 0x20) =
                    state + (index << 8) + 0x10;
                *(s32 *)(*(u8 **)slot + 0x24) = 4;
                index++;
            }
            *(void **)(*(u8 **)(state + 4) + 8) = (void *)fclBankRenderStateBase;
            *(s32 *)(*(u8 **)(state + 4) + 0x10) = 0;
            *(void **)(*(u8 **)(state + 8) + 8) = (void *)fclBankRenderStateFull;
            *(s32 *)(*(u8 **)(state + 8) + 0x10) = 0;
            *(s32 *)state = *(s32 *)state + 1;
            break;
        }
    case 1:
        func_00450340(iGpffff85c8, (const char *)D_005DD5D0);
        *(s32 *)(*(u8 **)(state + 4) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 4) + 4) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 4) = 0;
        PrimAppendNode(D_00793E80, *(u8 **)(state + 4));
        PrimAppendNode(D_00793E80, *(u8 **)(state + 8));
        break;
    }
    return 0;
}
// Intent: Bank task destroy: free the slot's batch nodes and release its task memory [inferred]
// FUN_00103980
void fclBankTaskDestroy(u8 *arg0) {
    u8 *state;

    state = *(u8 **)(arg0 + 0x38);
    PrimFreeBatchNode(*(s32 *)(state + 4));
    PrimFreeBatchNode(*(s32 *)(state + 8));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// Intent: Create the bank task with its update and destroy callbacks [inferred]
// FUN_001039E0
void fclBankTaskCreate(void) {
    chkmemAllocSiteTag(D_005DD600, 0xBD);
    (s32)kwlnTaskCreate((const void *)(&iGpffff85d0), 0xF, 0, 0, fclBankTaskUpdate, fclBankTaskDestroy, (u8 *)(D_008873F4[0](1, 0x210, 0x40000)));
}
// Intent: Reset the bank slot table's per-slot flags and counters [inferred]
// FUN_00103A60
void fclBankTableReset(void)
{
    s16 i;
    s16 j;

    for (i = 0; i < 2; ++i) {
        *(s16 *)(D_00796700 + (i * 0x370)) = 0;
        *(s32 *)(D_00796700 + (i * 0x370) + 0x50) = 0;
        for (j = 0; j < 2; ++j) {
            *(s32 *)(D_00796700 + (i * 0x370) + (j * 4) + 0x14) = 0;
        }
    }
}
// Intent: Register the bank resource tables and load each of the two bank slots [inferred]
// FUN_00103B00
void fclBankTableInit(void) {
    extern u8 D_00796460[];
    extern u8 D_00796700[];
    extern void fclBankSlotLoad(u8 *arg0);
    s16 index;

    PrimQueueStateSet(D_00796460, 6, 1);
    PrimQueueStateSet(D_00796460, 7, 2);
    PrimQueueStateSet(D_00796460, 8, 1);
    PrimQueueStateSet(D_00796460, 11, 6);
    PrimQueueStateSet(D_00796460, 10, 5);
    PrimQueueStateSet(D_00796460, 9, 1);
    PrimQueueStateSet(D_00796460, 12, 1);
    PrimQueueStateSet(D_00796460, 2, 4);

    index = 0;
    while (index < 2) {
        fclBankSlotLoad(D_00796700 + (index * 0x370));
        index++;
    }
}
struct HCdvd;
struct RwTexture;
/* Measured: 700/704 bytes, 23 resolved code relocations and seven resolved
   jump-table entries; four zero alignment bytes. State 3 is inert, and the
   drawing callback receives the current slot. */
// Intent: Load a bank slot's resources from its archive entries and register them [inferred]
// FUN_00103C40
void fclBankSlotLoad(u8 *slot)
{
    extern u8 D_005DD630[];
    extern u8 D_005DD640[];
    extern u8 D_005DD670[];
    extern u32 H_Cdvd_IsFileLoaded(struct HCdvd *archive);
    extern const char *H_Cdvd_ArchiveEntryName(struct HCdvd *archive, s32 index);
    extern u8 *func_004667d0(s32 kind, const char *name, const char *path,
                            s32 flags, s32 source, s32 buffer, s32 byteCount,
                            const char *cacheName, s32 resultKind, s32 memoryKind);
    extern u8 *func_004669d0(u8 *request, s32 *complete, s32 *size);
    extern s32 func_004672c0(s32 request, u8 *archive);
    extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 mode);
    extern u32 H_Cdvd_Destroy(struct HCdvd *archive);
    extern s32 func_003ef3a0(struct RwTexture *texture);
    extern void fclBankSlotUpdate(u8 *slot);
    extern s32 sprintf(u8 *destination, const u8 *format, ...);
    s32 complete;
    s16 state;
    u8 *texture;
    s32 index;
    u8 *textureSlot;
    u8 *archive;
    u8 *request;
    s32 offset;

    state = *(s16 *)slot;
    switch (state) {
    case 1:
        *(s32 *)(slot + 0x36C) = *(s32 *)(slot + 0x36C) + 1;
        if (H_Cdvd_IsFileLoaded(*(struct HCdvd **)(slot + 0x24)) == 0) {
            break;
        }
        if (H_Cdvd_ArchiveEntryName(*(struct HCdvd **)(slot + 0x24),
                          *(s32 *)(slot + 0x4C)) != NULL) {
            sprintf(slot + 0x60, D_005DD630,
                           H_Cdvd_ArchiveEntryName(*(struct HCdvd **)(slot + 0x24),
                                          *(s32 *)(slot + 0x4C)));
            *(u8 **)(slot + 0x48) =
                func_004667d0(0, (const char *)slot + 0x60, NULL,
                              0, 0, 0, 0, NULL, 0, 0);
            *(s16 *)slot = 2;
            break;
        }
        H_Cdvd_Destroy(*(struct HCdvd **)(slot + 0x24));
        *(u8 **)(slot + 0x24) = NULL;
        *(s16 *)slot = 3;
        func_00440b68(D_005DD640, *(s16 *)(slot + 4),
                      *(s16 *)(slot + 6), *(s16 *)(slot + 8),
                      *(s32 *)(slot + 0x364), *(s32 *)(slot + 0x368),
                      *(s32 *)(slot + 0x36C));
        break;
    case 2:
        *(s32 *)(slot + 0x368) = *(s32 *)(slot + 0x368) + 1;
        texture = func_004669d0(*(u8 **)(slot + 0x48), &complete, NULL);
        offset = *(s32 *)(slot + 0x4C) * 4;
        *(u8 **)(offset + (u32)slot + 0x14) = texture;
        if (complete != 0) {
            offset = *(s32 *)(slot + 0x4C) * 4;
            texture = *(u8 **)(offset + (u32)slot + 0x14);
            *(u32 *)(texture + 0x50) =
                (*(u32 *)(texture + 0x50) & 0xFFFF00FF) | 0x3300;
            *(u8 **)(slot + 0x48) = NULL;
            *(s32 *)(slot + 0x4C) = *(s32 *)(slot + 0x4C) + 1;
            *(s16 *)slot = 1;
            break;
        }
        break;
    case 4:
        fclBankSlotUpdate(slot);
        break;
    case 5:
    case 6:
        *(s32 *)(slot + 0x364) = *(s32 *)(slot + 0x364) + 1;
        request = *(u8 **)(slot + 0x48);
        if (request != NULL) {
            func_004672c0((s32)request, *(u8 **)(slot + 0x24));
            *(u8 **)(slot + 0x48) = NULL;
            *(u8 **)(slot + 0x24) = NULL;
        } else {
            archive = *(u8 **)(slot + 0x24);
            if (archive != NULL) {
                H_Cdvd_Destroy((struct HCdvd *)archive);
                *(u8 **)(slot + 0x24) = NULL;
            }
        }
        index = 0;
        while (index < 2) {
            textureSlot = slot + (index * 4) + 0x14;
            if (*(struct RwTexture **)textureSlot != NULL) {
                func_003ef3a0(*(struct RwTexture **)textureSlot);
                *(u8 **)textureSlot = NULL;
            }
            index++;
        }
        if (*(s16 *)slot != 6) {
            *(s16 *)slot = 0;
        } else {
            func_00440b68((u8 *)&iGpffff85d0 + 8, D_005DD670, 0xC5);
            *(u8 **)(slot + 0x24) = H_Cdvd_AcquireDirectory(slot + 0x60, 1);
            *(s16 *)slot = 1;
        }
        break;
    case 0:
    default:
        break;
    }
}
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
// Intent: Advance a bank slot's loading and display state each step [inferred]
// FUN_00103F00
void fclBankSlotUpdate(u8 *arg0)
{
    s32 table[6];
    f32 pos[2];
    f32 depth;
    f32 inverse;
    f32 half_w;
    f32 half_h;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    f32 x0;
    f32 y0;
    f32 fx;
    f32 fy;
    f32 offset;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    s32 *src;
    s32 *dst;
    s32 lo;
    s32 hi;
    s32 n;
    s32 count;
    s32 index;

    kwlnGetCamera();
    a = arg0[0x1F];
    if (a != 0) {
        depth = *(f32 *)(arg0 + 0x20);
        b = arg0[0x1E];
        g = arg0[0x1D];
        r = arg0[0x1C];
        inverse = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
        {
            s32 i;
            u8 *quad;

            for (i = 0; i < 4; i++) {
                quad = arg0 + (i << 6);
                *(f32 *)(quad + 0x180) = (f32)r;
                *(f32 *)(quad + 0x184) = (f32)g;
                *(f32 *)(quad + 0x188) = (f32)b;
                *(f32 *)(quad + 0x18C) = (f32)a;
                *(f32 *)(quad + 0x168) = RwIm2DGetNearScreenZ() - depth;
                *(f32 *)(quad + 0x178) = inverse;
            }
        }
        *(Float2_0010 *)pos = *(Float2_0010 *)(arg0 + 0xC);
        half_w = (512.0f * *(f32 *)(arg0 + 0x28)) / 2.0f;
        half_h = (256.0f * *(f32 *)(arg0 + 0x2C)) / 2.0f;
        fx = pos[0];
        x0 = 256.0f + fx;
        left = x0 - half_w;
        *(f32 *)(arg0 + 0x160) = left;
        fy = pos[1];
        y0 = 128.0f + fy;
        top = y0 - half_h;
        *(f32 *)(arg0 + 0x164) = top;
        right = (x0 + half_w) - 1.0f;
        *(f32 *)(arg0 + 0x1A0) = right;
        *(f32 *)(arg0 + 0x1A4) = top;
        *(f32 *)(arg0 + 0x1E0) = left;
        bottom = (y0 + half_h) - 1.0f;
        *(f32 *)(arg0 + 0x1E4) = bottom;
        *(f32 *)(arg0 + 0x220) = right;
        *(f32 *)(arg0 + 0x224) = bottom;
        kwlnGetCamera();
        *(s32 *)(arg0 + 0x170) = 0;
        *(s32 *)(arg0 + 0x174) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0x3F800000;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1F0) = 0;
        *(s32 *)(arg0 + 0x1F4) = 0x3F800000;
        *(s32 *)(arg0 + 0x230) = 0x3F800000;
        *(s32 *)(arg0 + 0x234) = 0x3F800000;
        PrimQueueStateSet(D_00796460, 1, **(s32 **)(arg0 + 0x14));
        PrimQueueDrawPrimitive(D_00796460, 4, arg0 + 0x160, 4);
        if (*(s32 *)(arg0 + 0x4C) >= 2) {
            a = arg0[0x1F];
            if (a == 0xFF && *(s32 *)(arg0 + 0x50) != 0) {
                if (*(s32 *)(arg0 + 0x54) != 0) {
                    depth = *(f32 *)(arg0 + 0x20);
                    b = arg0[0x1E];
                    g = arg0[0x1D];
                    r = arg0[0x1C];
                    inverse = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
                    {
                        s32 i;
                        u8 *quad;

                        for (i = 0; i < 4; i++) {
                            quad = arg0 + (i << 6);
                            *(f32 *)(quad + 0x280) = (f32)r;
                            *(f32 *)(quad + 0x284) = (f32)g;
                            *(f32 *)(quad + 0x288) = (f32)b;
                            *(f32 *)(quad + 0x28C) = (f32)a;
                            *(f32 *)(quad + 0x268) = RwIm2DGetNearScreenZ() - depth;
                            *(f32 *)(quad + 0x278) = inverse;
                        }
                    }
                    offset = (f32)*(s32 *)(arg0 + 0x360);
                    half_w = (512.0f * *(f32 *)(arg0 + 0x28)) / 2.0f;
                    half_h = (64.0f * *(f32 *)(arg0 + 0x2C)) / 2.0f;
                    fx = pos[0];
                    x0 = 256.0f + fx;
                    left = x0 - half_w;
                    *(f32 *)(arg0 + 0x260) = left;
                    fy = pos[1];
                    y0 = 32.0f + fy;
                    top = offset + (y0 - half_h);
                    *(f32 *)(arg0 + 0x264) = top;
                    right = (x0 + half_w) - 1.0f;
                    *(f32 *)(arg0 + 0x2A0) = right;
                    *(f32 *)(arg0 + 0x2A4) = top;
                    *(f32 *)(arg0 + 0x2E0) = left;
                    bottom = (offset + (y0 + half_h)) - 1.0f;
                    *(f32 *)(arg0 + 0x2E4) = bottom;
                    *(f32 *)(arg0 + 0x320) = right;
                    *(f32 *)(arg0 + 0x324) = bottom;
                    kwlnGetCamera();
                    *(s32 *)(arg0 + 0x270) = 0;
                    *(s32 *)(arg0 + 0x274) = 0;
                    *(s32 *)(arg0 + 0x2B0) = 0x3F800000;
                    *(s32 *)(arg0 + 0x2B4) = 0;
                    *(s32 *)(arg0 + 0x2F0) = 0;
                    *(s32 *)(arg0 + 0x2F4) = 0x3F800000;
                    *(s32 *)(arg0 + 0x330) = 0x3F800000;
                    *(s32 *)(arg0 + 0x334) = 0x3F800000;
                    PrimQueueStateSet(D_00796460, 1, **(s32 **)(arg0 + 0x18));
                    PrimQueueDrawPrimitive(D_00796460, 4, arg0 + 0x260, 4);
                }
                src = (s32 *)D_005DD680;
                dst = table;
                n = 3;
                do {
                    lo = src[0];
                    hi = src[1];
                    src += 2;
                    n--;
                    dst[0] = lo;
                    dst[1] = hi;
                    dst += 2;
                } while (n > 0);
                count = *(s32 *)(arg0 + 0x58) - 1;
                *(s32 *)(arg0 + 0x58) = count;
                if (count <= 0) {
                    if (*(s32 *)(arg0 + 0x54) != 0) {
                        *(s32 *)(arg0 + 0x54) = 0;
                    } else {
                        *(s32 *)(arg0 + 0x54) = 1;
                    }
                    index = *(s32 *)(arg0 + 0x5C) + 1;
                    *(s32 *)(arg0 + 0x5C) = index;
                    index = index % 6;
                    *(s32 *)(arg0 + 0x5C) = index;
                    *(s32 *)(arg0 + 0x58) = table[index];
                }
            }
        }
    }
}
// Intent: Mark a bank slot as finished (state 5) [inferred]
// FUN_001044D0
void fclBankMarkDone(s64 arg0) {
    *(s16 *)(D_00796700 + ((s16)arg0 * 0x370)) = 5;
}
// Intent: Configure a bank slot from a three-id descriptor, looking up its table entry; default 0x3E when not found [inferred]
// FUN_00104510
void fclBankSlotConfigure(s16 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    u8 buf[0x100];
    s32 offset;
    s32 i;
    s32 found;
    u8 *entry;

    func_00440b68(D_005DD6A0, arg0);
    offset = (arg0 * 0x38 - arg0) * 0x10;
    *(s16 *)(D_00796700 + offset) = 5;
    *(s32 *)(D_0079674C + offset) = 0;
    *(s16 *)(D_00796704 + offset) = arg1;
    *(s16 *)(D_00796706 + offset) = arg2;
    *(s16 *)(D_00796708 + offset) = arg3;
    sprintf(buf, D_005DD6C0,
                  (s32)arg1, (s32)arg2, (s32)arg3);
    strcpy(D_00796700 + offset + 0x60, buf);
    *(s16 *)(D_00796700 + offset) = 6;
    *(s32 *)(D_00796A64 + offset) = 0;
    *(s32 *)(D_00796A68 + offset) = 0;
    *(s32 *)(D_00796A6C + offset) = 0;
    *(u8 *)(D_0079671C + offset) = 0xff;
    *(u8 *)(D_0079671E + offset) = 0xff;
    *(u8 *)(D_0079671D + offset) = 0xff;
    *(u8 *)(D_0079671F + offset) = 0xff;
    *(u32 *)(D_00796728 + offset) = 0x3f800000;
    *(u32 *)(D_0079672C + offset) = 0x3f800000;
    i = 0;
    found = 1;
    do {
        entry = D_005DD610 + i * 0x10;
        if (*(s32 *)entry == -1)
            break;
        if ((s32)arg1 == *(s32 *)entry &&
            (s32)arg2 == *(s32 *)(entry + 4) &&
            (s32)arg3 == *(s32 *)(entry + 8)) {
            *(s32 *)(D_00796A60 + offset) =
                *(s32 *)(D_005DD61C + i * 0x10);
            found = 0;
            break;
        }
        i++;
    } while (1);
    if (found)
        *(s32 *)(D_00796A60 + offset) = 0x3e;
}
// Intent: Set the alpha byte of a bank slot [inferred]
// FUN_00104770
void fclBankSetAlpha(s64 arg0, u8 arg1) {
    *(u8 *)(D_0079671F + (((s16)arg0) * 0x370)) = arg1;
}
// Intent: Set a bank slot's active flag; when set, reset its phase and timers [inferred]
// FUN_001047B0
void fclBankSetActive(s64 arg0, s32 arg1) {
    s32 offset;

    offset = (s16)arg0 * 0x370;
    *(s32 *)(D_00796750 + offset) = arg1;
    if (arg1 != 0) {
        *(s32 *)(D_00796754 + offset) = 1;
        *(s32 *)(D_0079675C + offset) = 0;
        *(s32 *)(D_00796758 + offset) = 2;
    }
}
// Intent: Resume a waiting bank slot (state 3 to 4) [inferred]
// FUN_00104830
void fclBankResume(s64 arg0) {
    s16 *entry;

    entry = (s16 *)(D_00796700 + ((s16)arg0 * 0x370));
    if (*entry == 3) {
        *entry = 4;
    }
}
// Intent: Return a pointer to the bank slot's position fields [inferred]
// FUN_00104880
u8 *fclBankGetPositionPtr(s64 arg0) {
    return D_00796700 + ((s16)arg0 * 0x370) + 0xC;
}
// Intent: Report whether a bank slot is waiting (state 3) [inferred]
// FUN_001048C0
s32 fclBankIsWaiting(s64 arg0) {
    return *(s16 *)(D_00796700 + ((s16)arg0 * 0x370)) == 3;
}
