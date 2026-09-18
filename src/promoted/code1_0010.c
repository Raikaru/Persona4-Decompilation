#include "include_asm.h"
#include "type.h"
extern void func_00442830(void *dst, void *src);

extern u8 *D_00764298;
extern void func_00440b68();
extern void func_0042c0d8(void);
extern void func_004ccb38(s32 arg0);
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
extern void func_00111b30(void);
extern s32 func_00452380(void *arg0);
extern void func_002a2650(s32 arg0);
extern s32 func_002a2710(void);
extern void func_002a2740(void);
extern void func_00460a50(s32 arg0);
extern void func_0044ea90(void *arg0, s32 arg1);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern s32 iGpffff85b8;
extern s32 iGpffffb194;
extern s32 iGpffffb1a0;
extern s32 iGpffffb19c;
extern void func_00454640(void);
extern void func_0046ab40(void);
extern void func_0045b7c0(void);
extern void func_004594c0(void);
extern void func_00452ce0(void);
extern s32 func_00451cf0(void);
extern void func_00466580(void);
extern void func_003e5510(s32 arg0);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern f32 iGpffffba6c;
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00100350(void);
extern void func_00100670(void);
extern void func_00100e60(void);
extern void func_003b6f00(s32 arg0);
extern void func_003b6da0(s32 arg0);
extern s32 func_001036d0(u8 *arg0);
extern void func_00103980(u8 *arg0);
extern s32 func_00100e30(void);
extern void func_00102490(void);
extern void func_00102610(void);
extern void func_001028c0(void);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0010d7b0(void);
extern void func_00121b20(void);
extern void func_00122430(s32 arg0);
extern u8 *func_00149620(u8 *parent);
extern void func_001605a0(void);
extern void func_001939a0(void);
extern void func_002312e0(void);
extern void func_00231330(void);
extern void func_00246700(void);
extern void func_0025ff90(void);
extern void func_00264e70(void);
extern void func_0026d840(void);
extern void func_00274970(void);
extern void func_00278940(void);
extern void func_002789a0(void);
extern void func_0029d950(void);
extern void func_002aaa10(void);
extern void func_002bdf20(void);
extern void func_0034b970(void);
extern void func_003f67e0(s32 arg0);
extern void func_003f67f0(s32 arg0);
extern void func_00418b18(s32 arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern void func_0044f570(s32 arg0);
extern void func_00451ca0(s32 arg0);
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
extern u8 *func_00460b60(u8 *arg0, s32 arg1, s32 arg2);
extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_00458fa0(void);
extern void func_0045a730(s32 arg0, s32 arg1);
extern void func_0045b430(void);
extern void func_00460910(s32 arg0, s32 arg1);
extern void func_00463520(void);
extern void func_00466680(void);
extern void func_0046d6b0(s32 arg0);
extern void func_0047d050(s32 arg0);
extern void func_00481440(s32 arg0);
extern void func_00481a20(s32 arg0);
extern void func_004b3250(s32 arg0);
extern void func_004b6c90(s32 arg0, s32 arg1);
extern void func_004c6eb0(s32 arg0);
extern s32 func_004c6f50(s32 arg0, s32 arg1, s32 arg2);
extern void func_004c7188(s32 arg0);
extern void func_004ca720(void);
extern void func_004cc200(s32 arg0, s32 arg1);
extern void func_004cc218(s32 arg0);
extern void func_004cd470(s32 arg0, s32 arg1);
extern void func_0050b3f8(void *arg0);
extern void func_004d8c78(void);
extern void func_004f2798(s32 arg0, s32 arg1);
extern void func_004f34b0(s32 arg0);
extern void func_004f5bf0(s32 arg0, s32 arg1, s32 arg2);
extern void func_00100dd0(void);
extern void func_00100e00(void);
extern void func_00111010(void);
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




/* PERMANENT ASM, not a matching candidate.  This is the crt0 entry stub.
   0x00100008-0x001001b8 zeroes all 32 GPRs with `padduw rX, $zero, $zero`
   (the 128-bit form, so the upper halves are cleared too), then HI/LO and
   their pipeline-1 twins via mthi/mthi1/mtlo/mtlo1, then SA via mtsah,
   then all 32 FPRs via mtc1, then flushes the FPU accumulator with
   `adda.s $f0,$f1` and clears FCR31 with `ctc1 $zero,$31`.  No C
   construct names $at, $k0, $gp, $sp, $ra or the COP1 control register as
   a destination, and no compiler emits mthi1/mtlo1/mtsah at all.  The
   tail then byte- and quad-zeroes the bss span 0x00764280-0x00948a00,
   issues syscall 60 (SetGsCrt/ExecPS2 thread setup) and syscall 61, and
   enables interrupts with `ei` - all privileged or register-exact
   sequences.  Retail's own crt0 was hand-written assembly; leave it. */
// FUN_00100008
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100008);
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
    s32 temp_2;
    u8 *temp_16;
    temp_16 = (u8 *)((u32)0x02000000 + (u32)((-0x2000 - (s32)&D_A0000) - (s32)&D_938A00));
    temp_2 = func_0043ece8(temp_16 - 16);
    if (temp_2 == 0) {
        func_00440b68(&D_00559800);
    }
    func_0043ed08(temp_2);
    return temp_16 - 16;
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
    extern void func_0042f600(s32 arg0);
    extern void func_00442088(u8 *dst, const u8 *fmt, ...);
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
    func_0042f600(2);
    func_00442088(resetPath, D_005DC530, D_005DC548);
    do {
        retry = !func_0042b098(resetPath);
    } while (retry);
    do {
        retry = !func_0042b048();
    } while (retry);
    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    func_0042f600(2);
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
    extern s32 func_003e8c60(s32 arg0, s32 arg1, s32 arg2);
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
    extern s32 func_003d71b0(void);
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
    extern s32 func_001026f0(void);
    extern void func_00456e40(void);
    extern void func_0044ea90(void *arg0, s32 arg1);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void func_0046a2e0(void *arg0, s32 arg1);
    extern s32 func_003eb1f0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_0046d740(const void *arg0, const void *arg1, u32 arg2);
    extern void func_003d8c00(void);
    extern u8 *func_003d96b0(u8 *arg0, s32 arg1);
    extern s32 func_00463d60(u8 *arg0);
    extern void *func_00463e60(void *arg0, void *arg1);
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


    func_003e8c60((s32)func_0044f510(), 0, 0x800000);
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
    func_003d71b0();
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
    func_001026f0();
    func_00456e40();
    func_0044ea90((void *)&iGpffff8598, 0x2C3);
    func_0046a2e0(jtbl_008873E8[0](0x62000, 0x40000), 0x62000);
    if (func_003eb1f0((s32)&iGpffff8590, (s32)func_003d8c00, (s32)func_003d96b0) == 0) {
        ok = 0;
        goto check;
    }
    if (func_003eb1f0((s32)&iGpffff8594, (s32)func_00463d60, (s32)func_00463e60) == 0) {
        ok = 0;
        goto check;
    }
    ok = 1;
check:
    if (ok == 0) {
        func_0046d740(D_005DC760, (void *)&iGpffff8598, 0x2C8);
    }
}
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
#pragma opt_propagation off
/* measured: opt_loop_invariants off prevents the four queue-address expressions from being hoisted across their wait loops. */
#pragma opt_loop_invariants off
/* measured: opt_common_subs off keeps each GP-anchor address materialized at its retail call site. */
#pragma opt_common_subs off
// FUN_00100E60
void func_00100e60(void)
{
    s32 one;
    func_0046d6b0((s32)&func_00111010);
    func_00451ca0(0x190);
    func_00460910(0x7D0, 0x64);
    func_004544b0();
    func_004559b0();
    func_0010d7b0();
    func_0045b430();
    func_00458fa0();
    func_0043f9c8(&D_00764D10[0], 0, 0x14);
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
    func_0043f9c8(&D_00764D30[0], 0, 0x20);
    D_00764D30[0] = *(f32 *)((u8 *)&fGpffff8030 + 8);
    one = 1;
    D_00764D34[0] = one;
    D_00764D38[0] = one;
    D_00764D3C[0] = 0;
    func_0050b3f8(&D_00764D30[0]);
    func_004cc200((s32)&func_00100dd0, 0);
    func_0045a730(0, 1);
    func_0045a730(1, 2);
    func_0047d050((s32)&D_005DC878);
    func_002312e0();
    func_0044f570(func_00457120());
    func_003f67e0(1);
    func_003f67f0(1);
    func_00466680();
    func_00481a20(0xC7);
    func_00481440((s32)&D_005DC7D0);
    func_004b3250((s32)&D_007948A0);
    func_004b6c90((s32)&D_00794510, 0xC7);
    func_001939a0();
    func_00246700();
    func_0026d840();
    func_00231330();
    func_00274970();
    func_002789a0();
    func_00278940();
    func_002bdf20();
    func_0029d950();
    func_00264e70();
    func_0025ff90();
    func_00102490();
    func_00102610();
    func_00463520();
    func_001028c0();
    func_001605a0();
    func_002aaa10();
    func_001029a0(0x1E, 0, 0, 0);
    func_00149620(NULL);
    func_00121b20();
    func_00122430(0);
    func_0034b970();
}
#pragma opt_loop_invariants on
#pragma opt_common_subs on
#pragma opt_propagation on
// FUN_00101270
s32 func_00101270(void)
{
    s32 temp_3;
    s32 temp_3_2;

    if (iGpffff85b8 != 0) {
        iGpffff85b8 = 0;
        *(u32 *)0x10000000 = 0;
        *(u32 *)0x10000010 = 0x83;
        goto block_5;
    }
    iGpffffb194 = *(u32 *)0x10000000;
    func_00454640();
    func_0046ab40();
    func_0045b7c0();
    func_004594c0();
    func_00452ce0();
    if (func_00451cf0() == 0) {
        return 0;
    }
    func_00466580();
    func_003e5510(1);
block_5:
    temp_3 = iGpffffb1a0;
    if (temp_3 != -1) {
        iGpffffb1a0 = temp_3 + 1;
    }
    temp_3_2 = iGpffffb19c;
    if (temp_3_2 != -1) {
        iGpffffb19c = temp_3_2 + 1;
    }
    return 1;
}
// FUN_00101350
void func_00101350(void)
{
    func_00100350();
    func_00100670();
    func_00100e60();
    func_003b6f00(*(u32 *)0x10000000);
    func_003b6da0(*(u32 *)0x10000000);
loop_1:
    func_00101270();
    goto loop_1;
}
/* measured: func_001013a0 is a live plain-C MATCH (272B window, 272B object, normalized_diff 0); staging kind = 4 before data = &iGpffffba6c reproduces retail's argument materialization order. */
// FUN_001013A0
#pragma opt_propagation off
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
        func_003f6440(kind, data);
        base[0](6, 1);
        base[0](8, 1);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
}
/* measured: opt_propagation on closes the bracket after the exact-match body. */
#pragma opt_propagation on
// FUN_00102780
s32 func_00102780(u8 *arg0)
{
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_16 + 4);
    if (temp_3 > -1) {
        if (*(s32 *)temp_16 & 1) {
            temp_2 = *(s32 *)(temp_16 + 0xC);
            if (temp_2 <= 0) {
                (*(void (**)(s32))((u8 *)D_005DCC64 + temp_3 * 0x50))(*(s32 *)(temp_16 + 0x14));
                temp_4 = *(s32 *)(temp_16 + 0x14);
                if (temp_4 != 0) {
                    jtbl_008873EC[0]((u8 *)(u32)temp_4);
                }
                *(s32 *)(temp_16 + 0x14) = 0;
                *(s32 *)temp_16 &= ~1;
            } else {
                *(s32 *)(temp_16 + 0xC) = temp_2 - 1;
            }
            goto block_10;
        }
        if ((*(s32 (**)(void))((u8 *)D_005DCC68 + temp_3 * 0x50))() == 1) {
            return 0;
        }
        *(s32 *)(temp_16 + 4) = -1;
        *(s32 *)(temp_16 + 0x10) = 0;
    }
block_10:
    return 0;
}
// FUN_00102890
void func_00102890(u8 *arg0) {
    iGpffffb1a8 = 0;
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}

// FUN_00102B90
void func_00102b90(void) {
    func_00111b30();
}
// FUN_00102BB0
s32 func_00102bb0(void) {
    return func_00452380(D_005DCB58) != 0;
}
// FUN_00103510
void func_00103510(void) {
    func_002a2650(0);
}
// FUN_00103540
s32 func_00103540(void) {
    return func_002a2710() != 0;
}
// FUN_00103570
void func_00103570(void) {
    func_002a2740();
}
// FUN_00103590
void func_00103590(void) {}
// FUN_001035A0
void func_001035a0(void) {
    D_00887300[0](1, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
}
// FUN_00103600
void func_00103600(void)
{
    u8 *temp_16;

    temp_16 = (u8 *)D_00887300;
    (*(void (**)(s32, s32))temp_16)(6, 1);
    (*(void (**)(s32, s32))temp_16)(8, 1);
    (*(void (**)(s32, s32))temp_16)(9, 1);
    (*(void (**)(s32, s32))temp_16)(0xC, 1);
    (*(void (**)(s32, s32))temp_16)(7, 2);
    (*(void (**)(s32, s32))temp_16)(1, iGpffffb9e8);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
}
// FUN_001036D0
s32 func_001036d0(u8 *arg0) {
    extern void func_00450340(s64 arg0, void *arg1);
    extern u8 *func_004609f0(void);
    extern void func_00460ac0(void *list, void *node);
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

            scale = *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
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
                *(u8 **)slot = func_004609f0();
                *(s16 *)(*(u8 **)slot + 0x18) = 11;
                *(s32 *)(*(u8 **)slot + 0x1C) = 4;
                *(u8 **)(*(u8 **)slot + 0x20) =
                    state + (index << 8) + 0x10;
                *(s32 *)(*(u8 **)slot + 0x24) = 4;
                index++;
            }
            *(void **)(*(u8 **)(state + 4) + 8) = (void *)func_001035a0;
            *(s32 *)(*(u8 **)(state + 4) + 0x10) = 0;
            *(void **)(*(u8 **)(state + 8) + 8) = (void *)func_00103600;
            *(s32 *)(*(u8 **)(state + 8) + 0x10) = 0;
            *(s32 *)state = *(s32 *)state + 1;
            break;
        }
    case 1:
        func_00450340(iGpffff85c8, D_005DD5D0);
        *(s32 *)(*(u8 **)(state + 4) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 4) + 4) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 4) = 0;
        func_00460ac0(D_00793E80, *(u8 **)(state + 4));
        func_00460ac0(D_00793E80, *(u8 **)(state + 8));
        break;
    }
    return 0;
}
// FUN_00103980
void func_00103980(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_00460a50(*(s32 *)(temp_16 + 4));
    func_00460a50(*(s32 *)(temp_16 + 8));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_001039E0
void func_001039e0(void) {
    func_0044ea90(D_005DD600, 0xBD);
    func_00451de0(&iGpffff85d0, 0xF, 0, 0, (void *)func_001036d0, (void *)func_00103980, D_008873F4[0](1, 0x210, 0x40000));
}
// FUN_00103A60
void func_00103a60(void)
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
// FUN_00103B00
void func_00103b00(void) {
    extern u8 D_00796460[];
    extern u8 D_00796700[];
    extern u8 *func_00460b60(u8 *list, s32 arg1, s32 arg2);
    extern void func_00103c40(u8 *arg0);
    s16 index;

    func_00460b60(D_00796460, 6, 1);
    func_00460b60(D_00796460, 7, 2);
    func_00460b60(D_00796460, 8, 1);
    func_00460b60(D_00796460, 11, 6);
    func_00460b60(D_00796460, 10, 5);
    func_00460b60(D_00796460, 9, 1);
    func_00460b60(D_00796460, 12, 1);
    func_00460b60(D_00796460, 2, 4);

    index = 0;
    while (index < 2) {
        func_00103c40(D_00796700 + (index * 0x370));
        index++;
    }
}
struct HCdvd;
struct RwTexture;
/* Measured: 700/704 bytes, 23 resolved code relocations and seven resolved
   jump-table entries; four zero alignment bytes. State 3 is inert, and the
   drawing callback receives the current slot. */
// FUN_00103C40
void func_00103c40(u8 *slot)
{
    extern u8 D_005DD630[];
    extern u8 D_005DD640[];
    extern u8 D_005DD670[];
    extern u32 func_004553c0(struct HCdvd *archive);
    extern const char *func_00456090(struct HCdvd *archive, s32 index);
    extern u8 *func_004667d0(s32 kind, const char *name, const char *path,
                            s32 flags, s32 source, s32 buffer, s32 byteCount,
                            const char *cacheName, s32 resultKind, s32 memoryKind);
    extern u8 *func_004669d0(u8 *request, s32 *complete, s32 *size);
    extern s32 func_004672c0(s32 request, u8 *archive);
    extern u8 *func_00454a60(u8 *path, s32 mode);
    extern u32 func_00454bd0(struct HCdvd *archive);
    extern s32 func_003ef3a0(struct RwTexture *texture);
    extern void func_00103f00(u8 *slot);
    extern s32 func_00442088(u8 *destination, const u8 *format, ...);
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
        if (func_004553c0(*(struct HCdvd **)(slot + 0x24)) == 0) {
            break;
        }
        if (func_00456090(*(struct HCdvd **)(slot + 0x24),
                          *(s32 *)(slot + 0x4C)) != NULL) {
            func_00442088(slot + 0x60, D_005DD630,
                           func_00456090(*(struct HCdvd **)(slot + 0x24),
                                          *(s32 *)(slot + 0x4C)));
            *(u8 **)(slot + 0x48) =
                func_004667d0(0, (const char *)slot + 0x60, NULL,
                              0, 0, 0, 0, NULL, 0, 0);
            *(s16 *)slot = 2;
            break;
        }
        func_00454bd0(*(struct HCdvd **)(slot + 0x24));
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
        func_00103f00(slot);
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
                func_00454bd0((struct HCdvd *)archive);
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
            *(u8 **)(slot + 0x24) = func_00454a60(slot + 0x60, 1);
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
// FUN_00103F00
void func_00103f00(u8 *arg0)
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

    func_00457120();
    a = arg0[0x1F];
    if (a != 0) {
        depth = *(f32 *)(arg0 + 0x20);
        b = arg0[0x1E];
        g = arg0[0x1D];
        r = arg0[0x1C];
        inverse = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
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
        func_00457120();
        *(s32 *)(arg0 + 0x170) = 0;
        *(s32 *)(arg0 + 0x174) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0x3F800000;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1F0) = 0;
        *(s32 *)(arg0 + 0x1F4) = 0x3F800000;
        *(s32 *)(arg0 + 0x230) = 0x3F800000;
        *(s32 *)(arg0 + 0x234) = 0x3F800000;
        func_00460b60(D_00796460, 1, **(s32 **)(arg0 + 0x14));
        func_00461390(D_00796460, 4, arg0 + 0x160, 4);
        if (*(s32 *)(arg0 + 0x4C) >= 2) {
            a = arg0[0x1F];
            if (a == 0xFF && *(s32 *)(arg0 + 0x50) != 0) {
                if (*(s32 *)(arg0 + 0x54) != 0) {
                    depth = *(f32 *)(arg0 + 0x20);
                    b = arg0[0x1E];
                    g = arg0[0x1D];
                    r = arg0[0x1C];
                    inverse = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
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
                    func_00457120();
                    *(s32 *)(arg0 + 0x270) = 0;
                    *(s32 *)(arg0 + 0x274) = 0;
                    *(s32 *)(arg0 + 0x2B0) = 0x3F800000;
                    *(s32 *)(arg0 + 0x2B4) = 0;
                    *(s32 *)(arg0 + 0x2F0) = 0;
                    *(s32 *)(arg0 + 0x2F4) = 0x3F800000;
                    *(s32 *)(arg0 + 0x330) = 0x3F800000;
                    *(s32 *)(arg0 + 0x334) = 0x3F800000;
                    func_00460b60(D_00796460, 1, **(s32 **)(arg0 + 0x18));
                    func_00461390(D_00796460, 4, arg0 + 0x260, 4);
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
// FUN_001044D0
void func_001044d0(s64 arg0) {
    *(s16 *)(D_00796700 + ((s16)arg0 * 0x370)) = 5;
}
// FUN_00104510
void func_00104510(s16 arg0, s16 arg1, s16 arg2, s16 arg3)
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
    func_00442088(buf, D_005DD6C0,
                  (s32)arg1, (s32)arg2, (s32)arg3);
    func_00442830(D_00796700 + offset + 0x60, buf);
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
// FUN_00104770
void func_00104770(s64 arg0, u8 arg1) {
    *(u8 *)(D_0079671F + (((s16)arg0) * 0x370)) = arg1;
}
// FUN_001047B0
void func_001047b0(s64 arg0, s32 arg1) {
    s32 temp_6;

    temp_6 = (s16)arg0 * 0x370;
    *(s32 *)(D_00796750 + temp_6) = arg1;
    if (arg1 != 0) {
        *(s32 *)(D_00796754 + temp_6) = 1;
        *(s32 *)(D_0079675C + temp_6) = 0;
        *(s32 *)(D_00796758 + temp_6) = 2;
    }
}
// FUN_00104830
void func_00104830(s64 arg0) {
    s16 *temp_5;

    temp_5 = (s16 *)(D_00796700 + ((s16)arg0 * 0x370));
    if (*temp_5 == 3) {
        *temp_5 = 4;
    }
}
// FUN_00104880
u8 *func_00104880(s64 arg0) {
    return D_00796700 + ((s16)arg0 * 0x370) + 0xC;
}
// FUN_001048C0
s32 func_001048c0(s64 arg0) {
    return *(s16 *)(D_00796700 + ((s16)arg0 * 0x370)) == 3;
}
