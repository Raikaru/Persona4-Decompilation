#include "include_asm.h"
#include "type.h"

extern u8 *D_00764298;
extern void func_00440b68();
extern void func_0042c0d8(void);
extern void func_004ccb38(s32 arg0);
extern u8 *func_00100230(void);
extern void func_00101350(void);
extern u8 D_00559810[];
extern u8 D_00559820[];

extern void (*jtbl_008873EC[])(u8 *);
extern void *(*D_008873F4[])(s32, s32, s32);
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffb1a8;
extern s32 iGpffffb9e8;
extern u8 D_005DCB58[];
extern u8 iGpffff85d0;
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
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern void func_001036d0(u8 *arg0);
extern void func_00103980(u8 *arg0);


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
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100230);
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
// FUN_00100350
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100350);
// FUN_00100670
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100670);
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
// FUN_00100E60
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100e60);
// FUN_00101270
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00101270);
// FUN_00101350
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00101350);
// FUN_00102780
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00102780);
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
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001036d0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103a60);
// FUN_00103B00
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103b00);
// FUN_00103C40
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103c40);
// FUN_00103F00
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103f00);
// FUN_001044D0
void func_001044d0(s64 arg0) {
    *(s16 *)(D_00796700 + ((s16)arg0 * 0x370)) = 5;
}
// FUN_00104510
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00104510);
// FUN_00104770
void func_00104770(s64 arg0, s8 arg1) {
    *(s8 *)(D_0079671F + (((s16)arg0) * 0x370)) = arg1;
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