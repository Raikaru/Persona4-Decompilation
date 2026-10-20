#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern void func_00440b68();
extern void func_0042c0d8(void);
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
extern void chkmemAllocSiteTag(void *file, s32 line);

extern s32 iGpffff85b8;
extern s32 iGpffffb194;
extern s32 iGpffffb1a0;
extern s32 iGpffffb19c;
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern f32 iGpffffba6c;
extern void kwlnInitIop(void);
extern void kwlnInitEngine(void);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0010.c; members 00100218-00100670 */

// FUN_00100218
/* measured: tailcall on emits the retail bare jump wrapper. */
#pragma tailcall on
void func_00100218(void)
{
    func_0042c0d8();
}

/* measured: close tailcall bracket around func_00100218. */
#pragma tailcall off
// FUN_00100220
asm void func_00100220(void)
{
    addiu $3, $0, 0x23
    syscall 0
}

// FUN_00100230
/* Probe the allocation budget below 32 MiB after reserved/linker extents and
 * sixteen header bytes, release the probe, and return that budget. */
extern s32 func_0043ece8(u8 *);
extern void func_0043ed08(s32);
extern u8 D_00559800[];
extern u8 D_938A00[];
extern u8 D_A0000[];
u8 *kwlnProbeHeapBudget(void) {
    s32 status;
    u8 *base;
    base = (u8 *)((u32)0x02000000 + (u32)((-0x2000 - (s32)&D_A0000) - (s32)&D_938A00));
    status = func_0043ece8(base - 16);
    if (status == 0) {
        func_00440b68(&D_00559800);
    }
    func_0043ed08(status);
    return base - 16;
}

// Intent: boot entry. Print boot diagnostics and the probed allocation budget, then enter kwlnMainLoop. No C callers (entry point).
// FUN_001002C0
s32 kwlnBoot(void) {
    s32 heapBudget;

    func_00440b68(D_00559810);
    heapBudget = (s32)kwlnProbeHeapBudget();
    func_00440b68(D_00559820, heapBudget);
    kwlnMainLoop();
    return 1;
}

// FUN_00100310
/* Acknowledge timer interrupt 9 (mode overflow bit 0x800), then re-enable interrupts. */
s32 kwlnHandleTimerInterrupt(s32 interruptId)
{
    volatile u32 *reg = (volatile u32 *)0x10000010;

    if (interruptId == 9) {
        if ((*reg & 0x800) != 0) {
            *reg = *reg | 0x800;
        }
    }
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

/* IOP reset, timer setup and ordered module loading. Materialized retry
   booleans preserve both reset-loop schedules. Exact 788/800 bytes with
   74 resolved relocations and twelve verified-zero alignment bytes. */
// Intent: IOP reset, timer setup and ordered module loading. Called from kwlnMainLoop before the engine init.
// FUN_00100350
void kwlnInitIop(void)
{
    extern void func_00424f28(s32);
    extern void func_00429c18(void);
    extern void func_0042eae0(s32);
    extern void sceCdMmode(s32);
    extern void sprintf(u8 *dst, const u8 *fmt, ...);
    extern s32 func_0042b098(u8 *);
    extern s32 sceSifSyncIop(void);
    extern void func_004214c0(s32, s32 (*cb)(s32), s32);
    extern void func_00422328(s32);
    extern s32 func_0042ab68(const u8 *path, s32 a1, const u8 *a2);
    extern void sdkPadInit(void);
    extern void memcardInitBackend(void);
    extern s32 func_004216d0(void);
    extern u8 D_005DC530[];
    extern u8 D_005DC548[];
    extern u8 D_005DC560[];
    extern u8 D_005DC580[];
    extern u8 D_005DC5A0[];
    extern u8 D_005DC5C0[];
    extern u8 D_005DC5E0[];
    extern u8 D_005DC600[];
    extern u8 D_005DC620[];
    extern u8 D_005DC640[];
    extern u8 D_005DC660[];
    extern u8 D_005DC680[];
    extern u8 D_005DC6A0[];
    extern u8 D_005DC6C0[];
    extern u8 D_005DC6E0[];
    extern u8 D_005DC700[];
    extern u8 D_005DC720[];
    extern u8 D_005DC740[];
    extern s32 D_00764280;
    extern s32 iGpffffb19c;
    extern s32 iGpffffb1a0;
    u8 resetPath[0x40];
    s32 retry;

    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    sceCdMmode(2);
    sprintf(resetPath, D_005DC530, D_005DC548);
    do {
        retry = !func_0042b098(resetPath);
    } while (retry);
    do {
        retry = !sceSifSyncIop();
    } while (retry);
    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    sceCdMmode(2);
    func_004214c0(9, kwlnHandleTimerInterrupt, 0);
    *(volatile u32 *)0x10000000 = 0;
    *(volatile u32 *)0x10000020 = 0;
    *(volatile u32 *)0x10000030 = 0;
    *(volatile u32 *)0x10000010 = 0x281;
    func_00422328(9);
    iGpffffb19c = 0;
    iGpffffb1a0 = 0;
    do {
    } while (func_0042ab68(D_005DC560, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC580, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5A0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5C0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5E0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC600, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC620, 0x14, D_005DC640) < 0);
    do {
    } while (func_0042ab68(D_005DC660, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC680, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6A0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6C0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6E0, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC700, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC700, 0, (u8 *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC720, 0x18, D_005DC740) < 0);
    sdkPadInit();
    memcardInitBackend();
    D_00764280 = func_004216d0();
}

/* MATCH: 1888B window, 1888B object, normalized_diff 0 (472/472 instrs, 0 edits +70 reloc-only). Base L10_00100670_body.c scores 24 words at 463/471 instrs; replacing the shared goto-error tail with retail's duplicated-tail shape (ok = 0; goto check in each arm, ok = 1 on success, if (ok == 0) error) closes it. */
// Intent: engine init sequence: RenderWare and plugin attach, the primitive interp register, the scene rig and the entry table. Called from kwlnMainLoop after kwlnInitIop.
// FUN_00100670
void kwlnInitEngine(void)
{
    extern s32 func_0044f510(void);
    extern s32 RwEngineInit(s32, s32, s32);
    extern s32 func_0039b5a0(s32);
    extern s32 func_0039b680(s32);
    extern s32 func_003ca430(void);
    extern s32 func_00390520(void);
    extern s32 func_003bbe20(void);
    extern s32 func_003999a0(void);
    extern s32 func_003d4fc0(void);
    extern s32 func_00396f00(void);
    extern s32 func_003b82d0(void);
    extern s32 func_0039b380(void);
    extern s32 RpUVAnimPluginAttach(void);
    extern s32 func_00417470(void);
    extern s32 func_003a16c0(void);
    extern s32 func_003b7110(void);
    extern s32 func_003bd160(void);
    extern s32 func_003e8b10(s32);
    extern s32 RpSkySelectDeepZBuffer(s32);
    extern s32 func_003e8a10(s32);
    extern s32 func_003e22c0(s32);
    extern u32 PrimInterpRegister(void);
    extern s32 func_003f4f90(s32, s32, s32);
    extern s32 func_003e8a50(void);
    extern s32 FldShadow_InstallIntcHandler(void);
    extern void kwlnInitSceneRig(void);
    extern void chkmemAllocSiteTag(void *file, s32 line);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void initEntryTable(void *buffer, s32 size);
    typedef RwImage *(*ImageReadCallback)(const char *name);
    typedef RwImage *(*ImageWriteCallback)(RwImage *image, const char *name);
    extern s32 func_003eb1f0(const char *extension, ImageReadCallback readImage, ImageWriteCallback writeImage);
    extern void kAssertFailAt(const void *msg, const void *file, u32 line);
    extern RwImage *func_003d8c00(const char *name);
    extern RwImage *func_003d96b0(RwImage *image, const char *name);
    extern RwImage *tmxLoadFile(const char *name);
    extern RwImage *tmxImageWriteCallback(RwImage *image, const char *name);
    extern u8 D_0064F2F0[];
    extern u8 D_0064F380[];
    extern u8 D_0064F3A0[];
    extern u8 D_0064F3C0[];
    extern u8 D_0064F450[];
    extern u8 D_0064F4E0[];
    extern u8 D_0064F500[];
    extern u8 D_0064F5B0[];
    extern u8 D_0064F640[];
    extern u8 D_0064F6D0[];
    extern u8 D_0064F6F0[];
    extern u8 D_0064F710[];
    extern u8 D_0064F730[];
    extern u8 D_0064F770[];
    extern u8 D_0064F800[];
    extern u8 D_0064F8D0[];
    extern u8 D_0064F960[];
    extern u8 D_0064F9F0[];
    extern u8 D_0064FA10[];
    extern u8 D_0064FAC0[];
    extern u8 D_0064FA30[];
    extern u8 D_0064FAE0[];
    extern u8 D_0064FB70[];
    extern u8 D_0064FC00[];
    extern u8 D_0064FC90[];
    extern u8 D_0064FD50[];
    extern u8 D_0064FDE0[];
    extern u8 D_005DC760[];
    extern u8 iGpffff8598;
    extern u8 iGpffff8590;
    extern u8 iGpffff8594;
    /* Registry entry names use their PDS IDs; the implementation tables do not
     * establish more specific pipeline roles. Keep each original stack extent. */
    s32 pipeline1001[7];
    s32 pipeline1002[8];
    s32 pipeline1003[8];
    s32 pipeline4[8];
    s32 pipeline5[8];
    s32 pipeline6[8];
    s32 pipeline7[8];
    s32 pipeline1100B[8];
    s32 pipeline1100C[8];
    s32 pipeline1100D[8];
    s32 pipeline1100E[8];
    s32 pipeline1100F[8];
    s32 pipeline11010[8];
    s32 pipeline11001[8];
    s32 pipeline11002[8];
    s32 pipeline11011[8];
    s32 pipeline11012[8];
    s32 pipeline11013[8];
    s32 pipeline11014[8];
    s32 pipeline1001F[8];
    s32 pipeline10020[8];
    s32 pipeline10021[8];
    s32 pipeline10022[8];
    s32 pipeline10023[8];
    s32 pipeline10024[8];
    s32 pipeline1002A[8];
    s32 pipeline1002B[8];
    s32 engineOption;
    s32 ok;


    RwEngineInit((s32)func_0044f510(), 0, 0x800000);
    func_0039b5a0(7);

    pipeline1001[0] = (s32)D_0064F2F0;
    pipeline1001[2] = 0x1001;
    pipeline1001[3] = 1;
    pipeline1001[1] = 0;
    pipeline1001[4] = 0;
    func_0039b680((s32)pipeline1001);
    pipeline1002[0] = (s32)D_0064F380;
    pipeline1002[2] = 0x1002;
    pipeline1002[3] = 2;
    pipeline1002[1] = 0x1001;
    pipeline1002[4] = 0;
    func_0039b680((s32)pipeline1002);
    pipeline1003[0] = (s32)D_0064F3A0;
    pipeline1003[2] = 0x1003;
    pipeline1003[3] = 2;
    pipeline1003[1] = 0x1001;
    pipeline1003[4] = 0;
    func_0039b680((s32)pipeline1003);
    pipeline4[0] = (s32)D_0064F3C0;
    pipeline4[2] = 4;
    pipeline4[3] = 1;
    pipeline4[1] = 0;
    pipeline4[4] = 0;
    func_0039b680((s32)pipeline4);
    pipeline5[0] = (s32)D_0064F450;
    pipeline5[2] = 5;
    pipeline5[3] = 1;
    pipeline5[1] = 0;
    pipeline5[4] = 0;
    func_0039b680((s32)pipeline5);
    pipeline6[0] = (s32)D_0064F4E0;
    pipeline6[2] = 6;
    pipeline6[3] = 2;
    pipeline6[1] = 4;
    pipeline6[4] = 0;
    func_0039b680((s32)pipeline6);
    pipeline7[0] = (s32)D_0064F500;
    pipeline7[2] = 7;
    pipeline7[3] = 2;
    pipeline7[1] = 5;
    pipeline7[4] = 0;
    func_0039b680((s32)pipeline7);
    func_003ca430();
    func_00390520();
    func_003bbe20();
    func_003999a0();

    pipeline1100B[0] = (s32)D_0064F5B0;
    pipeline1100B[2] = 0x1100B;
    pipeline1100B[3] = 1;
    pipeline1100B[1] = 0;
    pipeline1100B[4] = 0;
    func_0039b680((s32)pipeline1100B);
    pipeline1100C[0] = (s32)D_0064F640;
    pipeline1100C[2] = 0x1100C;
    pipeline1100C[3] = 1;
    pipeline1100C[1] = 0;
    pipeline1100C[4] = 0;
    func_0039b680((s32)pipeline1100C);
    pipeline1100D[0] = (s32)D_0064F6D0;
    pipeline1100D[2] = 0x1100D;
    pipeline1100D[3] = 2;
    pipeline1100D[1] = 0x1100B;
    pipeline1100D[4] = 0;
    func_0039b680((s32)pipeline1100D);
    pipeline1100E[0] = (s32)D_0064F6F0;
    pipeline1100E[2] = 0x1100E;
    pipeline1100E[3] = 2;
    pipeline1100E[1] = 0x1100C;
    pipeline1100E[4] = 0;
    func_0039b680((s32)pipeline1100E);
    pipeline1100F[0] = (s32)D_0064F710;
    pipeline1100F[2] = 0x1100F;
    pipeline1100F[3] = 2;
    pipeline1100F[1] = 0x1100B;
    pipeline1100F[4] = 0;
    func_0039b680((s32)pipeline1100F);
    pipeline11010[0] = (s32)D_0064F730;
    pipeline11010[2] = 0x11010;
    pipeline11010[3] = 2;
    pipeline11010[1] = 0x1100C;
    pipeline11010[4] = 0;
    func_0039b680((s32)pipeline11010);
    func_003d4fc0();
    func_00396f00();
    func_003b82d0();

    pipeline11001[0] = (s32)D_0064F770;
    pipeline11001[2] = 0x11001;
    pipeline11001[3] = 1;
    pipeline11001[1] = 0;
    pipeline11001[4] = 0;
    func_0039b680((s32)pipeline11001);
    pipeline11002[0] = (s32)D_0064F800;
    pipeline11002[2] = 0x11002;
    pipeline11002[3] = 2;
    pipeline11002[1] = 0x11001;
    pipeline11002[4] = 0;
    func_0039b680((s32)pipeline11002);
    pipeline11011[0] = (s32)D_0064F8D0;
    pipeline11011[2] = 0x11011;
    pipeline11011[3] = 1;
    pipeline11011[1] = 0;
    pipeline11011[4] = 0;
    func_0039b680((s32)pipeline11011);
    pipeline11012[0] = (s32)D_0064F960;
    pipeline11012[2] = 0x11012;
    pipeline11012[3] = 1;
    pipeline11012[1] = 0;
    pipeline11012[4] = 0;
    func_0039b680((s32)pipeline11012);
    pipeline11013[0] = (s32)D_0064F9F0;
    pipeline11013[2] = 0x11013;
    pipeline11013[3] = 2;
    pipeline11013[1] = 0x11011;
    pipeline11013[4] = 0;
    func_0039b680((s32)pipeline11013);
    pipeline11014[0] = (s32)D_0064FA10;
    pipeline11014[2] = 0x11014;
    pipeline11014[3] = 2;
    pipeline11014[1] = 0x11012;
    pipeline11014[4] = 0;
    func_0039b680((s32)pipeline11014);
    func_0039b380();
    RpUVAnimPluginAttach();
    func_00417470();

    pipeline1001F[0] = (s32)D_0064FAC0;
    pipeline1001F[2] = 0x1001F;
    pipeline1001F[3] = 2;
    pipeline1001F[1] = 0;
    pipeline1001F[4] = 0;
    func_0039b680((s32)pipeline1001F);
    pipeline10020[0] = (s32)D_0064FA30;
    pipeline10020[2] = 0x10020;
    pipeline10020[3] = 1;
    pipeline10020[1] = 0;
    pipeline10020[4] = 0;
    func_0039b680((s32)pipeline10020);
    pipeline10021[0] = (s32)D_0064FAE0;
    pipeline10021[2] = 0x10021;
    pipeline10021[3] = 1;
    pipeline10021[1] = 0;
    pipeline10021[4] = 0;
    func_0039b680((s32)pipeline10021);
    pipeline10022[0] = (s32)D_0064FB70;
    pipeline10022[2] = 0x10022;
    pipeline10022[3] = 1;
    pipeline10022[1] = 0;
    pipeline10022[4] = 0;
    func_0039b680((s32)pipeline10022);
    pipeline10023[0] = (s32)D_0064FC00;
    pipeline10023[2] = 0x10023;
    pipeline10023[3] = 1;
    pipeline10023[1] = 0;
    pipeline10023[4] = 0;
    func_0039b680((s32)pipeline10023);
    pipeline10024[0] = (s32)D_0064FC90;
    pipeline10024[2] = 0x10024;
    pipeline10024[3] = 1;
    pipeline10024[1] = 0;
    pipeline10024[4] = 0;
    func_0039b680((s32)pipeline10024);
    pipeline1002A[0] = (s32)D_0064FD50;
    pipeline1002A[2] = 0x1002A;
    pipeline1002A[3] = 1;
    pipeline1002A[1] = 0;
    pipeline1002A[4] = 0;
    func_0039b680((s32)pipeline1002A);
    pipeline1002B[0] = (s32)D_0064FDE0;
    pipeline1002B[2] = 0x1002B;
    pipeline1002B[3] = 1;
    pipeline1002B[1] = 0;
    pipeline1002B[4] = 0;
    func_0039b680((s32)pipeline1002B);
    func_003a16c0();
    func_003b7110();
    func_003bd160();

    engineOption = 0;
    func_003e8b10((s32)&engineOption);
    RpSkySelectDeepZBuffer(0);
    func_003e8a10(0x52);
    func_003e22c0(0x380000);
    PrimInterpRegister();
    func_003f4f90(0x280000, 0x400, 0);
    func_003e8a50();
    FldShadow_InstallIntcHandler();
    kwlnInitSceneRig();
    chkmemAllocSiteTag((void *)&iGpffff8598, 0x2C3);
    initEntryTable(jtbl_008873E8[0](0x62000, 0x40000), 0x62000);
    if (func_003eb1f0((const char *)&iGpffff8590, func_003d8c00, func_003d96b0) == 0) {
        ok = 0;
        goto check;
    }
    if (func_003eb1f0((const char *)&iGpffff8594, tmxLoadFile, tmxImageWriteCallback) == 0) {
        ok = 0;
        goto check;
    }
    ok = 1;
check:
    if (ok == 0) {
        kAssertFailAt(D_005DC760, (void *)&iGpffff8598, 0x2C8);
    }
}

