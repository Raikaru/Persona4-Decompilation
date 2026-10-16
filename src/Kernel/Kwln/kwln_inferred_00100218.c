#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern void func_00440b68();
extern void func_0042c0d8(void);
extern u8 *func_00100230(void);
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
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);

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
extern void func_00100350(void);
extern void func_00100670(void);
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
extern s32 func_0043ece8(u8 *arg0);
extern void func_0043ed08(s32 arg0);
extern u8 D_00559800[];
extern u8 D_938A00[];
extern u8 D_A0000[];
u8 *func_00100230(void) {
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

// FUN_001002C0
s32 func_001002c0(void) {
    s32 r;

    func_00440b68(D_00559810);
    r = (s32)func_00100230();
    func_00440b68(D_00559820, r);
    func_00101350();
    return 1;
}

// FUN_00100310
s32 func_00100310(s32 arg0)
{
    volatile u32 *reg = (volatile u32 *)0x10000010;

    if (arg0 == 9) {
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
// FUN_00100350
void func_00100350(void)
{
    extern void func_00424f28(s32 arg0);
    extern void func_00429c18(void);
    extern void func_0042eae0(s32 arg0);
    extern void sceCdMmode(s32 arg0);
    extern void sprintf(u8 *dst, const u8 *fmt, ...);
    extern s32 func_0042b098(u8 *arg0);
    extern s32 func_0042b048(void);
    extern void func_004214c0(s32 arg0, s32 (*cb)(s32), s32 arg2);
    extern void func_00422328(s32 arg0);
    extern s32 func_0042ab68(const u8 *path, s32 arg1, const u8 *arg2);
    extern void func_00452760(void);
    extern void func_004645e0(void);
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
        retry = !func_0042b048();
    } while (retry);
    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    sceCdMmode(2);
    func_004214c0(9, func_00100310, 0);
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
    func_00452760();
    func_004645e0();
    D_00764280 = func_004216d0();
}

/* MATCH: 1888B window, 1888B object, normalized_diff 0 (472/472 instrs, 0 edits +70 reloc-only). Base L10_00100670_body.c scores 24 words at 463/471 instrs; replacing the shared goto-error tail with retail's duplicated-tail shape (ok = 0; goto check in each arm, ok = 1 on success, if (ok == 0) error) closes it. */
// FUN_00100670
void func_00100670(void)
{
    extern s32 func_0044f510(void);
    extern s32 RwEngineInit(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_0039b5a0(s32 arg0);
    extern s32 func_0039b680(s32 arg0);
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
    extern s32 func_003e8b10(s32 arg0);
    extern s32 func_003f6780(s32 arg0);
    extern s32 func_003e8a10(s32 arg0);
    extern s32 func_003e22c0(s32 arg0);
    extern u32 func_00481250(void);
    extern s32 func_003f4f90(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_003e8a50(void);
    extern s32 FldShadow_InstallIntcHandler(void);
    extern void func_00456e40(void);
    extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void initEntryTable(void *arg0, s32 arg1);
    typedef RwImage *(*ImageReadCallback)(const char *name);
    typedef RwImage *(*ImageWriteCallback)(RwImage *image, const char *name);
    extern s32 func_003eb1f0(const char *extension, ImageReadCallback readImage, ImageWriteCallback writeImage);
    extern void func_0046d740(const void *arg0, const void *arg1, u32 arg2);
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
    s32 v32[7];
    s32 v31[8];
    s32 v30[8];
    s32 v29[8];
    s32 v28[8];
    s32 v27[8];
    s32 v26[8];
    s32 v25[8];
    s32 v24[8];
    s32 v23[8];
    s32 v22[8];
    s32 v21[8];
    s32 v20[8];
    s32 v19[8];
    s32 v18[8];
    s32 v17[8];
    s32 v16[8];
    s32 v15[8];
    s32 v14[8];
    s32 v13[8];
    s32 v12[8];
    s32 v11[8];
    s32 v10[8];
    s32 v9[8];
    s32 v8[8];
    s32 v7[8];
    s32 v6[8];
    s32 v33;
    s32 ok;


    RwEngineInit((s32)func_0044f510(), 0, 0x800000);
    func_0039b5a0(7);

    v32[0] = (s32)D_0064F2F0;
    v32[2] = 0x1001;
    v32[3] = 1;
    v32[1] = 0;
    v32[4] = 0;
    func_0039b680((s32)v32);
    v31[0] = (s32)D_0064F380;
    v31[2] = 0x1002;
    v31[3] = 2;
    v31[1] = 0x1001;
    v31[4] = 0;
    func_0039b680((s32)v31);
    v30[0] = (s32)D_0064F3A0;
    v30[2] = 0x1003;
    v30[3] = 2;
    v30[1] = 0x1001;
    v30[4] = 0;
    func_0039b680((s32)v30);
    v29[0] = (s32)D_0064F3C0;
    v29[2] = 4;
    v29[3] = 1;
    v29[1] = 0;
    v29[4] = 0;
    func_0039b680((s32)v29);
    v28[0] = (s32)D_0064F450;
    v28[2] = 5;
    v28[3] = 1;
    v28[1] = 0;
    v28[4] = 0;
    func_0039b680((s32)v28);
    v27[0] = (s32)D_0064F4E0;
    v27[2] = 6;
    v27[3] = 2;
    v27[1] = 4;
    v27[4] = 0;
    func_0039b680((s32)v27);
    v26[0] = (s32)D_0064F500;
    v26[2] = 7;
    v26[3] = 2;
    v26[1] = 5;
    v26[4] = 0;
    func_0039b680((s32)v26);
    func_003ca430();
    func_00390520();
    func_003bbe20();
    func_003999a0();

    v25[0] = (s32)D_0064F5B0;
    v25[2] = 0x1100B;
    v25[3] = 1;
    v25[1] = 0;
    v25[4] = 0;
    func_0039b680((s32)v25);
    v24[0] = (s32)D_0064F640;
    v24[2] = 0x1100C;
    v24[3] = 1;
    v24[1] = 0;
    v24[4] = 0;
    func_0039b680((s32)v24);
    v23[0] = (s32)D_0064F6D0;
    v23[2] = 0x1100D;
    v23[3] = 2;
    v23[1] = 0x1100B;
    v23[4] = 0;
    func_0039b680((s32)v23);
    v22[0] = (s32)D_0064F6F0;
    v22[2] = 0x1100E;
    v22[3] = 2;
    v22[1] = 0x1100C;
    v22[4] = 0;
    func_0039b680((s32)v22);
    v21[0] = (s32)D_0064F710;
    v21[2] = 0x1100F;
    v21[3] = 2;
    v21[1] = 0x1100B;
    v21[4] = 0;
    func_0039b680((s32)v21);
    v20[0] = (s32)D_0064F730;
    v20[2] = 0x11010;
    v20[3] = 2;
    v20[1] = 0x1100C;
    v20[4] = 0;
    func_0039b680((s32)v20);
    func_003d4fc0();
    func_00396f00();
    func_003b82d0();

    v19[0] = (s32)D_0064F770;
    v19[2] = 0x11001;
    v19[3] = 1;
    v19[1] = 0;
    v19[4] = 0;
    func_0039b680((s32)v19);
    v18[0] = (s32)D_0064F800;
    v18[2] = 0x11002;
    v18[3] = 2;
    v18[1] = 0x11001;
    v18[4] = 0;
    func_0039b680((s32)v18);
    v17[0] = (s32)D_0064F8D0;
    v17[2] = 0x11011;
    v17[3] = 1;
    v17[1] = 0;
    v17[4] = 0;
    func_0039b680((s32)v17);
    v16[0] = (s32)D_0064F960;
    v16[2] = 0x11012;
    v16[3] = 1;
    v16[1] = 0;
    v16[4] = 0;
    func_0039b680((s32)v16);
    v15[0] = (s32)D_0064F9F0;
    v15[2] = 0x11013;
    v15[3] = 2;
    v15[1] = 0x11011;
    v15[4] = 0;
    func_0039b680((s32)v15);
    v14[0] = (s32)D_0064FA10;
    v14[2] = 0x11014;
    v14[3] = 2;
    v14[1] = 0x11012;
    v14[4] = 0;
    func_0039b680((s32)v14);
    func_0039b380();
    RpUVAnimPluginAttach();
    func_00417470();

    v13[0] = (s32)D_0064FAC0;
    v13[2] = 0x1001F;
    v13[3] = 2;
    v13[1] = 0;
    v13[4] = 0;
    func_0039b680((s32)v13);
    v12[0] = (s32)D_0064FA30;
    v12[2] = 0x10020;
    v12[3] = 1;
    v12[1] = 0;
    v12[4] = 0;
    func_0039b680((s32)v12);
    v11[0] = (s32)D_0064FAE0;
    v11[2] = 0x10021;
    v11[3] = 1;
    v11[1] = 0;
    v11[4] = 0;
    func_0039b680((s32)v11);
    v10[0] = (s32)D_0064FB70;
    v10[2] = 0x10022;
    v10[3] = 1;
    v10[1] = 0;
    v10[4] = 0;
    func_0039b680((s32)v10);
    v9[0] = (s32)D_0064FC00;
    v9[2] = 0x10023;
    v9[3] = 1;
    v9[1] = 0;
    v9[4] = 0;
    func_0039b680((s32)v9);
    v8[0] = (s32)D_0064FC90;
    v8[2] = 0x10024;
    v8[3] = 1;
    v8[1] = 0;
    v8[4] = 0;
    func_0039b680((s32)v8);
    v7[0] = (s32)D_0064FD50;
    v7[2] = 0x1002A;
    v7[3] = 1;
    v7[1] = 0;
    v7[4] = 0;
    func_0039b680((s32)v7);
    v6[0] = (s32)D_0064FDE0;
    v6[2] = 0x1002B;
    v6[3] = 1;
    v6[1] = 0;
    v6[4] = 0;
    func_0039b680((s32)v6);
    func_003a16c0();
    func_003b7110();
    func_003bd160();

    v33 = 0;
    func_003e8b10((s32)&v33);
    func_003f6780(0);
    func_003e8a10(0x52);
    func_003e22c0(0x380000);
    func_00481250();
    func_003f4f90(0x280000, 0x400, 0);
    func_003e8a50();
    FldShadow_InstallIntcHandler();
    func_00456e40();
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
        func_0046d740(D_005DC760, (void *)&iGpffff8598, 0x2C8);
    }
}

