#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

void func_00483810();

extern u8 D_00713480[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];


extern void (*jtbl_008873EC[])();

// FUN_00481D80
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00481d80);
// FUN_00481E30
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00481e30);
// FUN_00481EE0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00481ee0);
// FUN_00481F30
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00481f30);
// FUN_00482230
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00482230);
// FUN_004823E0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004823e0);
// FUN_004824A0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004824a0);
// FUN_00482790
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00482790);
// FUN_00484010
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484010);
// FUN_004841C0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004841c0);
// FUN_00484280
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484280);
// FUN_004842D0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004842d0);
// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004843F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004843f0);
// FUN_00484510
void func_00484510(void)
{
}

// FUN_00484520
void func_00484520(void)
{
}

// FUN_00484530
s32 func_00484530(void)
{
    return 0;
}

// FUN_00484540
void func_00484540(void)
{
}

// FUN_00484550
void func_00484550(void)
{
}

// FUN_00484560
s32 func_00484560(void)
{
    return 1;
}

// FUN_00484570
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484570);
// FUN_004846D0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004846d0);
// FUN_00484790
void func_00484790(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        *(u8 **)(arg0 + 0x18) = NULL;
    }
}

// FUN_004847E0
void func_004847e0(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u8 **)(arg0 + 0x28) = NULL;
    }
}

// FUN_00484830
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484830);
// FUN_00484970
void func_00484970(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_0071349C + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_004849C0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004849c0);
// FUN_00484A00
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484a00);
// FUN_00484A40
void func_00484a40(u8 *arg0, void *arg1) {
    void (*fn)(s32, void *) = *(void (**)(s32, void *))(D_007134A0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

// FUN_00484A90
void func_00484a90(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_007134A8 + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_00484AE0
void func_00484ae0(u8 *arg0, s32 arg1) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

/* Measured compiled-C park: typed 16-byte aggregate copy reproduces retail
   D_00713CE0 lq/sq transfer widths; object 120B / window 128B,
   normalized_diff 6. Exact residual rows are archived in
   build/WBSmallFiles_code1_0048_00484b30_park.txt. Committed at nd 6. */
// FUN_00484B30 NONMATCHING
#ifdef NON_MATCHING
/* measured: opening propagation bracket for the parked aggregate probe. */
#pragma opt_propagation off
void func_00484b30(u8 *arg0)
{
    s32 temp;
    u_long128 *quadSrc;
    func_0043f9c8(arg0, 0, 0x80);
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(arg0) : "memory");
    temp = 0x40A00000;
    *(s32 *)(arg0 + 0x44) = temp;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(arg0) : "memory");
    quadSrc = (u_long128 *)(void *)D_00713CE0;
    *(u_long128 *)(arg0 + 0x20) = *quadSrc;
    temp = 0x3F800000;
    *(s32 *)(arg0 + 0x60) = temp;
    *(s32 *)(arg0 + 0x74) = temp;
    temp = -1;
    *(s32 *)(arg0 + 0x64) = temp;
    temp = 0x80;
    *(s32 *)(arg0 + 0x68) = temp;
}
/* measured: close propagation bracket for the parked aggregate probe. */
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484b30);
#endif

// FUN_00484BB0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484bb0);
// FUN_00485630
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485630);
// FUN_00485870
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485870);
// FUN_00485AE0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485ae0);
// FUN_00485B20
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485b20);
// FUN_00485C80
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485c80);
// FUN_00485FE0
void func_00485fe0(u8 *arg0) {
    u8 *n = *(u8 **)(arg0 + 0x8C);
    u8 *o;
    void (*fn)(s32);

    while (n != NULL) {
        o = *(u8 **)(n + 0x90);
        fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(o + 4) << 6) + 0x1C);
        if (fn != NULL) {
            fn(*(s32 *)(o + 8));
        }
        n = *(u8 **)(n + 0xAC);
    }
    *(s32 *)(arg0 + 0x84) = 0;
}

// FUN_00486060
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486060);
// FUN_004860F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004860f0);
// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}

// FUN_004861F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004861f0);
// FUN_00486330
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486330);
// FUN_00486400
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486400);
// FUN_004865C0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004865c0);
// FUN_00486780
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486780);
// FUN_004867E0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004867e0);
// FUN_00486840
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486840);
// FUN_00486970
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00486970);
// FUN_00489E00
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00489e00);
// FUN_00489E80
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00489e80);
// FUN_00489EE0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00489ee0);
// FUN_00489F10
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00489f10);
// FUN_0048A980
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048a980);
// FUN_0048ABD0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048abd0);
// FUN_0048AFF0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048aff0);
// FUN_0048B220
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b220);
// FUN_0048B340
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b340);
// FUN_0048B9E0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b9e0);
// FUN_0048C440
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048c440);
// FUN_0048C4E0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048c4e0);
// FUN_0048CD60
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048cd60);
// FUN_0048CDF0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048cdf0);
// FUN_0048D820
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048d820);
// FUN_0048D8C0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048d8c0);
// FUN_0048E270
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048e270);
// FUN_0048E2F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048e2f0);
// FUN_0048EBC0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048ebc0);
// FUN_0048EC50
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048ec50);
// FUN_0048F560
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048f560);
// FUN_0048F5F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048f5f0);