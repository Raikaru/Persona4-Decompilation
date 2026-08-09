#include "include_asm.h"
#include "type.h"
extern void func_004787e0();

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern s32 D_00724C78;
extern s32 D_00724C7C;
extern u8 D_00714350[];
extern void func_0046d730(u8 *arg0, s32 arg1);
extern s32 func_003e9320(void);
extern u8 *func_00457120(void);
extern void func_003e9830(s32 arg0, s32 arg1);
extern f32 D_00922D80[];
extern u8 *func_00401b80(void);
extern u8 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];

extern u8 D_00714144[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);

extern void func_004a7c00(u8 *arg0, s32 arg1);

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

extern void func_0044ea90(const void *msg, s32 id);
extern void func_0043f810(void *dst, void *src, u32 size);
extern u8 *func_00484490(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);



extern void (*jtbl_008873EC[])(u8 *arg0);

// FUN_004A18E0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a18e0);
// FUN_004A1950
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1950);
// FUN_004A1AA0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1aa0);
// FUN_004A1AF0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1af0);
// FUN_004A1B50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1b50);
// FUN_004A1BA0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1ba0);
// FUN_004A1C30
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1c30);
// FUN_004A1C40
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1c40);
// FUN_004A1C50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1c50);
// FUN_004A1C60
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1c60);
// FUN_004A1C80
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1c80);
// FUN_004A1CA0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1ca0);
// FUN_004A1D70
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1d70);
// FUN_004A22C0
void func_004a22c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A35F0
void func_004a35f0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A49C0
void func_004a49c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A58B0
void func_004a58b0(u8 *arg0)
{
    (*(void (**)(u8 *))(D_00714138 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    jtbl_008873EC[0](arg0);
}

// FUN_004A5910
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5910);
// FUN_004A59B0
void func_004a59b0(u8 *arg0)
{
    (*(void (**)(void))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}

// FUN_004A5A00
void func_004a5a00(u8 *arg0)
{
    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}

// FUN_004A5A60
void func_004a5a60(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}

// FUN_004A5AB0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5ab0);
// FUN_004A5B40
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5b40);
// FUN_004A5B50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5b50);
// FUN_004A5B60
void func_004a5b60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x30) = arg1;
}

/* measured: the jump table must be called through the pointer -- `jtbl_x(a)` is
   an implicit function call to the table SYMBOL, which links and runs wrong. */

// FUN_004A5B70
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5b70);

// FUN_004A5B90
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5b90);

// FUN_004A5BB0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5bb0);
// FUN_004A5DE0
void func_004a5de0(u8 *arg0) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = (s32)(*(s32 *)((u8 *)(arg0) + 0xCC));
    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    temp_4_2 = (s32)(*(s32 *)((u8 *)(arg0) + 0xD0));
    if (temp_4_2 != 0) {
        func_00481ee0(temp_4_2);
    }
    func_004833f0(*(s32 *)((u8 *)(arg0) + 0xC8));
    (*jtbl_008873EC)(arg0);
}

// FUN_004A5E50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5e50);
// FUN_004A5EF0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5ef0);
// FUN_004A5F90
void func_004a5f90(u8 *arg0)
{
    *(s32 *)(arg0 + 0x2C) = 0;
}

// FUN_004A5FA0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5fa0);
// FUN_004A5FC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5fc0);
// FUN_004A6B90
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6b90);
// FUN_004A6BC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6bc0);
// FUN_004A6BD0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6bd0);
// FUN_004A6BE0
void func_004a6be0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004A6BF0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6bf0);
// FUN_004A6C00
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6c00);
// FUN_004A6D90
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6d90);
// FUN_004A6DC0
void func_004a6dc0(u8 *arg0)
{
    func_004841c0(*(s32 *)(arg0 + 0x58));
    jtbl_008873EC[0](arg0);
}

// FUN_004A6E10
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6e10);
// FUN_004A6E40
void func_004a6e40(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

// FUN_004A77B0
void func_004a77b0(void) {
    if (D_00724C70 != 0) {
        func_0046d730(D_00714350, 0x1E9);
    }
    D_00724C58 = 0;
    D_00724C5C = 0;
    D_00724C60 = 0;
    D_00724C64 = 0;
    D_00724C78 = 0;
    D_00724C7C = 0;
    D_00724C70 = func_003e9320();
    func_003e9830(D_00724C70, *(s32 *)(func_00457120() + 4));
}

// FUN_004A7830
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7830);
// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}



// FUN_004A7A90
void *func_004a7a90(void)
{
    u8 *src;
    void *dst;

    src = func_00484490();
    func_0044ea90(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    func_0043f810((u8 *)dst + 4, src, 0x10);
    return dst;
}

// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}



// FUN_004A7B70
void *func_004a7b70(void *arg0)
{
    u8 *src;
    void *dst;

    src = (u8 *)arg0;
    func_0044ea90(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    func_0043f810((u8 *)dst + 4, src + 4, 0x10);
    return dst;
}

// FUN_004A7BF0
void func_004a7bf0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x0) = 0;
}

// FUN_004A7C00
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7c00);
// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004A7DE0
void func_004a7de0(void) {
}



// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004A7E30
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7e30);
// FUN_004A8250
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a8250);
// FUN_004A8440
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a8440);
// FUN_004A86C0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a86c0);
// FUN_004A8890
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a8890);
// FUN_004A8A50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a8a50);
// FUN_004ABB60
void func_004abb60(void)
{
    u8 *temp_2;

    temp_2 = func_00401b80();
    *(u8 **)&D_00922D90[0] = temp_2;
    D_00922D94[0] = (f32)*(s32 *)(temp_2 + 0xC);
    D_00922D98[0] = (f32)*(s32 *)(temp_2 + 0x10);
}

// FUN_004ABBB0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004abbb0);
// FUN_004ABC50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004abc50);
// FUN_004ABD60
void func_004abd60(void)
{
    func_004787e0();
}

// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}

// FUN_004ACB80
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004acb80);
// FUN_004ACCC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004accc0);
// FUN_004AD030
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad030);
// FUN_004AD240
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad240);
// FUN_004AD280
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad280);
// FUN_004AD3E0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad3e0);
// FUN_004AD400
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad400);
// FUN_004AD410
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad410);
// FUN_004AD440
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad440);
// FUN_004AD450
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad450);
// FUN_004ADAB0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adab0);
// FUN_004ADB50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adb50);
// FUN_004ADE80
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ade80);
// FUN_004ADFA0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adfa0);
// FUN_004ADFE0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adfe0);
// FUN_004ADFF0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adff0);
// FUN_004AE000
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ae000);
// FUN_004AE010
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ae010);
// FUN_004AE0A0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ae0a0);
// FUN_004AE2F0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ae2f0);
// FUN_004AF520
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af520);
// FUN_004AF580
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af580);
// FUN_004AF5E0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af5e0);
// FUN_004AF610
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af610);
// FUN_004AF640
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af640);
// FUN_004AF650
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004af650);