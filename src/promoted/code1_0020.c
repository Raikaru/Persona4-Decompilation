#include "include_asm.h"
#include "type.h"
extern s32 func_00247cb0(s16 arg0);
extern u16 func_00107ac0(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00209d40(u8 *arg0, u8 *arg1);
extern void func_00209dc0(void);
extern void func_00209fa0(void);
extern void func_00209f90(void);
extern void func_0020a5c0(void);
extern void func_00202d20();
extern s32 func_00202e70(void);
extern void func_00113500(void);
extern void func_00113480(s32 a0, s32 a1, s32 a2, s32 a3);
extern f32 func_0046b260(u8 *arg0);
extern f32 func_0046b2f0(u8 *arg0);
extern s32 func_00201ee0(void);
extern s32 func_00202820(void);
extern void func_0021afa0(s32 arg0);
extern void func_0020e3f0();

extern s32 func_00106330(s32 arg0);
extern void func_00213ab0();
extern void func_0021ae60(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern void func_00202e00(u8 *arg0, s16 *arg1);
extern void func_00202460(u8 *arg0);
extern s32 func_00202480(u8 *arg0);
extern void func_00202570(u8 *arg0);
extern u32 func_001067f0(s16 arg0);
extern s32 func_001eb860(void);

typedef struct {
    f32 x;
    f32 y;
} Vec2f;
typedef struct {
    u8 pad0[2];
    s16 field2;
    s16 field4;
    s16 field6;
    s16 field8;
} P4_00202D20;
static inline f32 func_0020_mul(f32 left, f32 right)
{
    return left * right;
}
static inline u8 *p4_002091f0_add(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u8 *func_00452560();
extern void func_00364c90(s64 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2, f32 fparg3, s32 arg2);
extern f32 fGpffff815c;
extern f32 fGpffff83b0;
extern u8 *func_0010ace0(s16 arg0);
extern s32 func_0010b510(void);
extern s32 func_00109390(u8 *arg0);
extern s32 func_00109220(s32 arg0);
extern u16 func_00272c60(s16 arg0);
extern u16 func_00272c80(u16 arg0);
extern int func_00275020(f32 x, f32 y, f32 scale,
                         int color, int chr, int id, const char *str,
                         int flags, int charWidth);
extern u32 func_001d8bc0(void *arg0);
extern void func_0011b360(s32 arg0);
extern void func_00201410(u8 *arg0, s32 a, s32 b);
extern void func_002119a0(u8 *arg0);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void func_00216c40(s32 arg0, s32 arg1);
extern s64 func_00243e90(u8 *arg0);
extern void func_00216b40(s32 arg0, s32 arg1);
extern void func_00216bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00216d10(s32 arg0);



extern u8 *func_00194470(s32 id, s32 size);
extern s32 func_00202340(u8 *arg0);
extern s32 func_00202070(u8 *arg0);
extern s32 func_00202180(u8 *arg0);


extern s32 func_00202640(u8 **arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626500[];
extern u8 D_006265B0[];
extern void func_0044ea90(const void *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00451fc0(s32 arg0, const void *data, s32 prio, s32 a3,
                         s32 a4, void *init, void *close, void *work);
extern s32 func_00200cf0(void);
extern void func_00200f30(void);
extern void func_00200fd0(s32 arg0, u8 *arg1);
extern s32 func_00201b00(u8 *arg0);
extern void func_00201db0(void *arg0);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_002777f0(s32 arg0);
extern void func_0046b0d0(void *arg0);
extern s32 func_00231ed0(s32 arg0);
extern s32 func_00231f80(s32 arg0);
extern void func_004abd60(s32 arg0);
extern void func_004b5790(void *arg0, void *arg1);
extern u8 D_00625240[];
extern void func_00213b50(s32 arg0);
extern void func_00213b80(s32 arg0);
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern s32 func_00200ce0(void);
extern void func_00205170(void);
extern void func_00205ff0(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          void (*callback)(void), u8 *arg3);
extern void func_002055d0(void);
extern void func_00204690(u8 *arg0, f32 fparg0, f32 fparg1, s32 arg1, f32 fparg2);
extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;
typedef struct {
    s32 value3;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 pad[0xC];
    Color4 colors;
} Work4;
extern void func_003f6440(s32 arg0, s32 arg1);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern void func_00201820(s32 arg0);
extern void func_00205c20(void);
extern void func_00205950(void);
extern s32 func_00202e70(void);
extern u16 func_00243920(s64 arg0);
extern void func_00207140();
extern void func_00207320();
extern void func_00207b00();
extern void func_002089e0();
extern f32 func_00208870();
extern void func_001bc660(u16 arg0, void *arg1, u32 arg2);
extern void func_001bcd40(f32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u32 arg4);
extern u8 *func_001b0c80(s32 arg0);
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00194ee0(void *arg0, void *arg1);
extern void func_00194f10(void *arg0, void *arg1);
extern void func_00198dd0(void *arg0, s32 arg1);
extern void func_00198920(u8 *arg0, s16 arg1, u16 arg2, s16 arg3, f32 arg4);
extern u8 *iGpffffb3ac;
extern s32 D_00881444_abs[];
extern void func_0021be70(void *arg0);
extern void func_00213d20(void *arg0);
extern void func_00216e50(void *arg0);
extern void func_00211a10(void *arg0);
extern void func_0020add0(void *arg0);
extern void func_0020bb70(void *arg0);
extern void func_00219130(void *arg0);
extern void func_0021b1e0(void *arg0);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern void func_0020ad80(u8 *arg0, s32 arg1);
extern void func_0020b1a0(void);
extern void func_0020b3a0(void);
extern void func_0020b5a0(void);
extern void func_0020b5b0(void);
extern void func_0020bb20(u8 *arg0, s32 arg1);
extern void func_0020bd70(void);
extern void func_00211950(u8 *arg0, s32 arg1);
extern void func_00211ad0(u8 *arg0, u8 *arg1);
extern void func_00211ba0(void);
extern void func_00211f90(s32 arg0, u8 *arg1);
extern void func_00213cd0(u8 *arg0, s32 arg1);
extern void func_002167f0(void);
extern void func_00216df0(u8 *arg0, s32 arg1);
extern void func_00216e60(void);
extern void func_00218e50(u8 *arg0, s32 arg1);
extern void func_00219790(void);
extern void func_0021a7b0(void);
extern void func_0021b190(u8 *arg0, s32 arg1);
extern void func_0021b1f0(void);
extern void func_0021be10(u8 *arg0, s32 arg1);
extern void func_0021be80(void);
extern s32 func_002774d0(void *arg0);
extern u8 D_006253B0[];




// FUN_00200720
void func_00200720(s32 *arg0) {
    s32 temp_4;

    temp_4 = *arg0;
    if (temp_4 != 0) {
        func_004abd60(temp_4);
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00200770
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200770);
// FUN_00200960
void func_00200960(void) {
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
}
// FUN_00200980
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200980);

// FUN_00200A50
void func_00200a50(void)
{
}
// FUN_00200A60
void func_00200a60(u8 *arg0)
{
    u8 sp40[0x10];
    u8 sp30[0x10];
    s32 temp_4;
    s32 temp_4_2;
    u32 var_16;
    u8 *temp_16;
    u8 *var_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(arg0 + 0x28) != 0) {
        goto done;
    }
    func_001bc660(1, NULL, 1);
    func_001bcd40(0.0f, NULL, NULL, NULL, 0x100);
    temp_4 = *(s32 *)(temp_16 + 0);
    switch (temp_4) {
    case 0:
        func_001bc660(0x2C, NULL, 1);
        break;
    case 1:
        func_001bc660(0x2D, NULL, 1);
        break;
    case 2:
        func_001bc660(0x2E, func_001b0c80(D_00881444_abs[0]), 1);
        break;
    case 3:
        func_001bc660(6, func_001b0c80(D_00881444_abs[0]), 1);
        break;
    }
    if (*(u8 *)(temp_16 + 4) == 0) {
        goto done;
    }
    var_16 = 0;
    goto loop_19_test;
loop_19_body:
    var_17 = *(u8 **)(iGpffffb3ac + var_16 * 8 + 0x178);
    goto loop_17_test;
loop_17_body:
    temp_4_2 = *(s32 *)(var_17 + 0xA64);
    if ((temp_4_2 != 0) && (func_002428f0(temp_4_2, 0) == 0)) {
        func_00194ff0(var_17, sp40, sp30, NULL);
        func_00194ee0(var_17, sp40);
        func_00194f10(var_17, sp30);
        func_00198dd0(var_17, 0);
        func_00198920(var_17, *(s16 *)(var_17 + 0x9EC), 0,
                      *(s8 *)(var_17 + 0x9F4), *(f32 *)(var_17 + 0x9F0));
    }
    var_17 = *(u8 **)(var_17 + 0xA6C);
loop_17_test:
    if (var_17 != NULL) {
        goto loop_17_body;
    }
    var_16 += 1;
loop_19_test:
    if (var_16 < 2U) {
        goto loop_19_body;
    }
done:
    ;
}
// FUN_00200C50
void func_00200c50(void)
{
    func_00113500();
}
// FUN_00200C70
void func_00200c70(u8 *arg0)
{
    u8 *temp_7;

    temp_7 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(arg0 + 0x28) == 0) {
        func_00113480(*(s16 *)(temp_7 + 0),
                      *(s16 *)(temp_7 + 4),
                      *(s16 *)(temp_7 + 8),
                      *(s16 *)(temp_7 + 0xC));
    }
}
// FUN_00200CB0
void func_00200cb0(void) {
    func_004b5790((void *)&D_00625240, (void *)func_00200ce0);
}
// FUN_00200CE0
s32 func_00200ce0(void)
{
    return D_0076449C != NULL;
}
// FUN_00200CF0
s32 func_00200cf0(void)
{
    u8 *temp_2;

    temp_2 = func_00452560();
    func_0021be70(temp_2 + 0x9E4);
    *(s32 *)(temp_2 + 0x9F0) = 0;
    *(s32 *)(temp_2 + 0x9F4) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x9F0);
    *(s32 *)(temp_2 + 0x7DC) = 0;
    *(s32 *)(temp_2 + 0x7E0) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x7DC);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x800) == 0) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x7AC) = 0;
    *(s32 *)(temp_2 + 0x7B0) = 0;
    func_00460ac0(D_00794FF0, temp_2 + 0x7AC);
    func_00213d20(temp_2 + 0x80C);
    *(s32 *)(temp_2 + 0x81C) = 0;
    *(s32 *)(temp_2 + 0x820) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x81C);
    func_00216e50(temp_2 + 0x84C);
    *(s32 *)(temp_2 + 0x88C) = 0;
    *(s32 *)(temp_2 + 0x890) = 0;
    func_00460ac0(D_00795080, temp_2 + 0x88C);
    func_00211a10(temp_2 + 0x75C);
    *(s32 *)(temp_2 + 0x77C) = 0;
    *(s32 *)(temp_2 + 0x780) = 0;
    func_00460ac0(D_00795080, temp_2 + 0x77C);
    func_0020add0(temp_2 + 0x9C);
    *(s32 *)(temp_2 + 0x6E0) = 0;
    *(s32 *)(temp_2 + 0x6E4) = 0;
    func_00460ac0(D_00794810, temp_2 + 0x6E0);
    *(s32 *)(temp_2 + 0x6B0) = 0;
    *(s32 *)(temp_2 + 0x6B4) = 0;
    func_00460ac0(D_00794870, temp_2 + 0x6B0);
    *(s32 *)(temp_2 + 0x680) = 0;
    *(s32 *)(temp_2 + 0x684) = 0;
    func_00460ac0(D_00794FF0, temp_2 + 0x680);
    *(s32 *)(temp_2 + 0x650) = 0;
    *(s32 *)(temp_2 + 0x654) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x650);
    func_0020bb70(temp_2 + 0x710);
    *(s32 *)(temp_2 + 0x72C) = 0;
    *(s32 *)(temp_2 + 0x730) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x72C);
    func_00219130(temp_2 + 0x8C0);
    *(s32 *)(temp_2 + 0x980) = 0;
    *(s32 *)(temp_2 + 0x984) = 0;
    func_00460ac0(D_00794FF0, temp_2 + 0x980);
    *(s32 *)(temp_2 + 0x950) = 0;
    *(s32 *)(temp_2 + 0x954) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x950);
    func_0021b1e0(temp_2 + 0x9B0);
    *(s32 *)(temp_2 + 0x9B4) = 0;
    *(s32 *)(temp_2 + 0x9B8) = 0;
    func_00460ac0(D_00795020, temp_2 + 0x9B4);
    return 0;
}
// FUN_00200F30
void func_00200f30(void)
{
    u8 *temp_2;
    s32 temp_4;
    s32 var_16;
    temp_2 = (u8 *)func_00452560();
    func_002119a0(temp_2 + 0x75C);
    var_16 = 0;
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(temp_2 + (var_16 * 4) + 0x2C);
    if (temp_4 != 0) {
        func_0046b0d0((void *)temp_4);
    }
    var_16 += 1;
loop_test:
    if (var_16 < 0xC) {
        goto loop_body;
    }
    goto loop_done;
loop_done:
    func_002777f0(*(s32 *)(temp_2 + 0x98));
    jtbl_008873EC[0](temp_2);
}
// FUN_00200FD0
void func_00200fd0(s32 arg0, u8 *arg1)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;

    func_0020ad80(arg1 + 0x9C, arg0);
    *(void **)(arg1 + 0x658) = (void *)func_0020b1a0;
    temp_3 = arg1 + 0x9C;
    *(u8 **)(arg1 + 0x660) = temp_3;
    *(void **)(arg1 + 0x688) = (void *)func_0020b3a0;
    *(u8 **)(arg1 + 0x690) = temp_3;
    *(void **)(arg1 + 0x6B8) = (void *)func_0020b5a0;
    *(u8 **)(arg1 + 0x6C0) = temp_3;
    *(void **)(arg1 + 0x6E8) = (void *)func_0020b5b0;
    *(u8 **)(arg1 + 0x6F0) = temp_3;
    func_0020bb20(arg1 + 0x710, arg0);
    *(void **)(arg1 + 0x734) = (void *)func_0020bd70;
    *(u8 **)(arg1 + 0x73C) = arg1 + 0x710;
    func_00211950(arg1 + 0x75C, arg0);
    *(void **)(arg1 + 0x784) = (void *)func_00211ad0;
    temp_3_2 = arg1 + 0x75C;
    *(u8 **)(arg1 + 0x78C) = temp_3_2;
    *(void **)(arg1 + 0x7B4) = (void *)func_00211ba0;
    *(u8 **)(arg1 + 0x7BC) = temp_3_2;
    *(void **)(arg1 + 0x7E4) = (void *)func_00211f90;
    *(u8 **)(arg1 + 0x7EC) = temp_3_2;
    func_00213cd0(arg1 + 0x80C, arg0);
    *(void **)(arg1 + 0x824) = (void *)func_002167f0;
    *(u8 **)(arg1 + 0x82C) = arg1 + 0x80C;
    func_00216df0(arg1 + 0x84C, arg0);
    *(void **)(arg1 + 0x894) = (void *)func_00216e60;
    *(u8 **)(arg1 + 0x89C) = arg1 + 0x84C;
    func_00218e50(arg1 + 0x8C0, arg0);
    *(void **)(arg1 + 0x958) = (void *)func_00219790;
    temp_3_3 = arg1 + 0x8C0;
    *(u8 **)(arg1 + 0x960) = temp_3_3;
    *(void **)(arg1 + 0x988) = (void *)func_0021a7b0;
    *(u8 **)(arg1 + 0x990) = temp_3_3;
    func_0021b190(arg1 + 0x9B0, arg0);
    *(void **)(arg1 + 0x9BC) = (void *)func_0021b1f0;
    *(u8 **)(arg1 + 0x9C4) = arg1 + 0x9B0;
    func_0021be10(arg1 + 0x9E4, arg0);
    *(void **)(arg1 + 0x9F8) = (void *)func_0021be80;
    *(u8 **)(arg1 + 0xA00) = arg1 + 0x9E4;
    *(u8 *)(arg1 + 0x94) = 0xFF;
    *(u8 *)(arg1 + 0x95) = 0xFF;
    *(u8 *)(arg1 + 0x96) = 0xFF;
    *(f32 *)(arg1 + 0x14) = 1.0f;
    *(f32 *)(arg1 + 0x18) = 1.0f;
    *(f32 *)(arg1 + 0x1C) = 1.0f;
    *(f32 *)(arg1 + 0x20) = 1.0f;
    *(s32 *)(arg1 + 0x98) = func_002774d0(D_006253B0);
}
// FUN_002011C0
s32 func_002011c0(s32 arg0)
{
    u8 *temp_2_2;
    s32 temp_2;

    func_0044ea90(&D_006265B0, 0x3A);
    temp_2_2 = (u8 *)(*jtbl_008873E8)(0xA20, 0x40000);
    func_0043f9c8(temp_2_2, 0, 0xA20);
    temp_2 = func_00451fc0(arg0, &D_00626500, 0xF, 0, 0,
                           (void *)func_00200cf0,
                           (void *)func_00200f30, temp_2_2);
    func_00200fd0(temp_2, temp_2_2);
    return temp_2;
}
// FUN_00201280
void func_00201280(u8 *arg0, u8 *arg1) {
    func_00213ab0();
    func_0021ae60(arg0, arg1 + 0x18);
}



// FUN_002012D0
void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1) {
    *(s32 *)(arg0 + 4) = (s32)fparg0;
    *(s32 *)(arg0 + 8) = (s32)fparg1;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
}
// FUN_00201300
void func_00201300(s32 *arg0, f32 fp0, f32 fp1, f32 fp2, f32 fp3) {
    arg0[1] = (s32)fp0;
    arg0[2] = (s32)fp1;
    arg0[3] = (s32)fp2;
    arg0[4] = (s32)fp3;
}

/* measured: caching D_00887300 in s0 reproduces retail's one-time
   lui/addiu vtable materialization across these callback calls. */
#pragma opt_propagation off
// FUN_00201350
void func_00201350(void)
{
    void (**base)(u32, u32);

    func_00201820(0);
    base = D_00887300;
    base[0](7, 2);
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
}
/* measured: close the vtable propagation probe and restore default state. */
#pragma opt_propagation on
// FUN_00201410
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201410);
// FUN_00201650
void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    arg0[0x94] = (u8)arg5;
    arg0[0x95] = (u8)arg6;
    arg0[0x96] = (u8)arg7;
    arg0[0x7D] = 0xFF - (arg8 & 0xFF);
    func_00201410(arg0, arg1, arg2);
    arg0[0x94] = 0xFF;
    arg0[0x95] = 0xFF;
    arg0[0x96] = 0xFF;
    arg0[0x7D] = 0;
}

// FUN_002016B0
void func_002016b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *table;
    u8 *base;
    u32 index;
    u32 offset;
    u8 *temp_4;

    index = (u32)(arg1 * 4);
    table = (u8 *)(index + (u32)arg0 + 0x2C);
    table = *(u8 **)table;
    offset = (u32)(arg2 << 7);
    base = *(u8 **)(table + 0x204);
    temp_4 = (u8 *)(offset + (u32)base);
    *(s32 *)(temp_4 + 0x5C) = arg3 + *(s32 *)(temp_4 + 0x54);
}
// FUN_002016E0
void func_002016e0(u8 *arg0, s16 arg1, s16 arg2, f32 fparg0)
{
    *(s16 *)(arg0 + 0x88) = arg1;
    *(s16 *)(arg0 + 0x8A) = arg2;
    *(f32 *)(arg0 + 0x84) = fparg0;
    *(f32 *)(arg0 + 0x24) = (f32)arg1;
    *(f32 *)(arg0 + 0x28) = (f32)arg2;
}
// FUN_00201720
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201720);
// FUN_00201820
void func_00201820(s32 arg0)
{
    s32 temp_5;

    temp_5 = arg0 & 0xFFFF;
    switch (temp_5) {
    case 0:
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        return;
    case 1:
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        return;
    case 2:
        func_003f6440(2, 0x48);
        func_003f6440(3, 0x71801);
        return;
    case 3:
        func_003f6440(2, 0x42);
        func_003f6440(3, 0x71801);
        return;
    case 4:
        func_003f6440(2, 6);
        func_003f6440(3, 0x71801);
        return;
    }
}
// FUN_00201950
void func_00201950(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    func_0046b260(arg0 + 0x6C);
}
// FUN_00201990
void func_00201990(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    func_0046b2f0(arg0 + 0x6C);
}
// FUN_002019D0
void func_002019d0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    *(f32 *)(arg0 + 0x14) = fparg0;
    *(f32 *)(arg0 + 0x18) = fparg1;
}
// FUN_002019E0
void func_002019e0(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 0x90) = fparg0;
}
// FUN_002019F0
void func_002019f0(s32 arg0, u32 arg1)
{
    u8 *temp_2;

    if (arg1 < 0x1000U) {
        temp_2 = D_0076449C;
        func_00216bb0(*(s32 *)(temp_2 + 0xDD4), arg0,
                      *(s32 *)(temp_2 + 0xC60), arg1);
        return;
    }
    func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                  iGpffffb448 + (((arg1 - 0x1000) & 0xFFFF) * 0x13));
    func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
}
// FUN_00201A80
void func_00201a80(u8 *arg0) {
    s32 temp_4;
    u8 *temp_5;
    u8 *temp_5_2;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0));
    *(u16 *)(temp_5 + 0xA0) = (u16) (*(u16 *)(temp_5 + 0xA0) + 1);
    temp_5_2 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_5_2 + 0xA0) = (u16) (*(u16 *)(temp_5_2 + 0xA0) + 1);
    temp_4 = (s32)(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA64));
    if ((temp_4 != 0) && (func_00232710(temp_4, 0x100000) != 0)) {
        *(s32 *)(arg0 + 0x34) = 1;
        return;
    }
    *(s32 *)(arg0 + 0x34) = 0;
}

// FUN_00201B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201b00);
// FUN_00201DE0
u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4,
                  s16 arg5, s16 arg6, s32 arg7, u16 arg_sp0)
{
    u8 *spAC;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50A, 0x3C);
    spAC = temp_2;
    *(void **)(temp_2 + 0x68) = (void *)func_00201a80;
    *(void **)(temp_2 + 0x6C) = (void *)func_00201b00;
    *(void **)(temp_2 + 0x70) = (void *)func_00201db0;
    temp_16 = *(u8 **)(temp_2 + 0x78);
    func_0043f810(temp_16 + 8, (void *)arg7, 0x20);
    *(s32 *)(temp_16 + 0) = arg0;
    *(s32 *)(temp_16 + 4) = arg1;
    *(s32 *)(temp_16 + 0x28) = arg2;
    *(s16 *)(temp_16 + 0x2C) = arg3;
    *(s16 *)(temp_16 + 0x2E) = arg4;
    *(s16 *)(temp_16 + 0x30) = arg5;
    *(s16 *)(temp_16 + 0x32) = arg6;
    *(u16 *)(temp_16 + 0x38) = arg_sp0;
    return spAC;
}
// FUN_00201EE0
s32 func_00201ee0(void)
{
    func_0020e3f0(*(s32 *)(D_0076449C + 0xDD4));
    func_0021afa0(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00201F20
void func_00201f20(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50B, 0);
    *(void **)(temp_2 + 0x6C) = (void *)func_00201ee0;
}
/* measured: opt_rebuildconditionals off tested for callback completion. */
#pragma opt_rebuildconditionals off
// FUN_00201F60
s32 func_00201f60(u8 *arg0)
{
    u8 *temp_4;
    u32 temp_2;

    temp_4 = D_0076449C;
    if ((*(s32 *)(temp_4 + 0xC) & 0x200) == 0) {
        return 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        func_00216b40(*(s32 *)(temp_4 + 0xDD4),
                      iGpffffb448 + (*(u16 *)(arg0 + 4) * 0x13));
        func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    if (temp_2 >= 0x20U) {
        return 1;
    }
    return 0;
}
// FUN_00202070
s32 func_00202070(u8 *arg0)
{
    u32 temp_2;

    if ((*(s32 *)(D_0076449C + 0xC) & 0x200) == 0) {
        return 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                      func_001067f0(*(s16 *)(arg0 + 4)));
        func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    if (temp_2 >= 0x20U) {
        return 1;
    }
    return 0;
}
/* measured: restore conditional rebuilding after callback completion. */
#pragma opt_rebuildconditionals on
// FUN_00202120
void func_00202120(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x505, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)func_00202070;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_00202180
s32 func_00202180(u8 *arg0)
{
    s64 temp_4;
    s32 var_16;
    u16 temp_2;
    u8 *temp_3;

    if ((*(u16 *)(arg0 + 4) != 7) ||
        ((temp_3 = *(u8 **)arg0, (*(s32 *)(temp_3 + 0x9C) & 0x4000) == 0)) ||
        ((s16)func_00243e90(*(u8 **)(temp_3 + 0xA64)) != 4)) {
        var_16 = 0;
    } else {
        var_16 = 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        temp_2 = *(u16 *)(arg0 + 4);
        if (temp_2 == 0) {
            return 1;
        }
        func_00216b40(*(s32 *)(D_0076449C + 0xDD4), D_0062656C[temp_2]);
        if (var_16 == 0) {
            func_00216c40(*(s32 *)(D_0076449C + 0xDD4), 0x20);
        } else {
            func_00216c40(*(s32 *)(D_0076449C + 0xDD4), 0x10);
        }
        func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
    }
    *(u32 *)(arg0 + 8) = *(u32 *)(arg0 + 8) + 1;
    if (var_16 == 0) {
        if (*(u32 *)(arg0 + 8) >= 0x20U) {
            return 1;
        }
    } else if (*(u32 *)(arg0 + 8) >= 0x10U) {
        return 1;
    }
    return 0;
}
// FUN_002022E0
void func_002022e0(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x507, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)func_00202180;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_00202340
s32 func_00202340(u8 *arg0)
{
    u32 temp_2;
    u32 temp_7;
    s32 temp_8;
    u8 *temp_2_2;

    if (*(u32 *)(arg0 + 8) == 0) {
        temp_7 = *(u32 *)(arg0 + 4);
        temp_8 = *(s32 *)(arg0 + 0);
        if (temp_7 < 0x1000U) {
            temp_2_2 = D_0076449C;
            func_00216bb0(*(s32 *)(temp_2_2 + 0xDD4),
                          temp_8,
                          *(s32 *)(temp_2_2 + 0xC60), temp_7);
        } else {
            func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                          iGpffffb448 +
                              (((temp_7 - 0x1000) & 0xFFFF) * 0x13));
            func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
        }
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    return temp_2 >= 0x21U;
}
// FUN_00202400
void func_00202400(s32 arg0, s32 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)func_00194470(0x506, 0xC);
    *(void **)(temp_2 + 0x6C) = (void *)func_00202340;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_3 + 0) = arg0;
    *(s32 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = 0;
}

// FUN_00202460
void func_00202460(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00202480
s32 func_00202480(u8 *arg0)
{
    s16 temp_2;
    s16 temp_3_2;
    s32 var_17;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0);
    switch (*(u8 *)(arg0 + 4)) {
    case 0:
        var_17 = (s16)func_00231ed0(*(s32 *)(temp_16 + 0xA64));
        temp_3_2 = (s16)func_00231f80(*(s32 *)(temp_16 + 0xA64));
        temp_2 = *(s16 *)(arg0 + 6);
        if (temp_2 != 0) {
            var_17 = (s16)(var_17 + temp_2);
            if (temp_3_2 < var_17) {
                var_17 = temp_3_2;
            } else if (var_17 < 0) {
                var_17 = 0;
            }
        }
        *(f32 *)(temp_16 + 0xA28) = (f32)var_17 / (f32)temp_3_2;
        break;
    case 1:
        break;
    default:
        break;
    }
    return 1;
}
// FUN_00202570
void func_00202570(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00202590
void func_00202590(s32 arg0, s8 arg1, s16 arg2)
{
    u8 *packet;
    u8 *temp;

    packet = (u8 *)func_00194470(0x500, 8);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void **)(packet + 0x68) = (void *)func_00202460;
    *(void **)(packet + 0x6C) = (void *)func_00202480;
    *(void **)(packet + 0x70) = (void *)func_00202570;
    temp = *(u8 **)(packet + 0x78);
    *(s32 *)(temp + 0) = arg0;
    *(s8 *)(temp + 4) = arg1;
    *(s16 *)(temp + 6) = arg2;
}
// FUN_00202620
void func_00202620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}
// FUN_00202640
s32 func_00202640(u8 **arg0)
{
    f32 var_f0;
    f32 var_f20;
    u8 *temp_16;

    temp_16 = *arg0;
    var_f20 = (f32)(u32)func_00231ed0(*(s32 *)(temp_16 + 0xA64));
    var_f0 = (f32)(u32)func_00231f80(*(s32 *)(temp_16 + 0xA64));
    *(f32 *)(temp_16 + 0xA2C) = var_f20 / var_f0;
    *(s32 *)(temp_16 + 0xA28) = (s32)0xBF800000;
    *(s16 *)(temp_16 + 0xA38) = -1;
    return 1;
}
// FUN_00202720
void func_00202720(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}
// FUN_00202740
u8 *func_00202740(u8 *unit)
{
    u8 *packet;
    packet = (u8 *)func_00194470(0x501, 4);
    *(u8 *)(packet + 71) &= ~(1 << 4);
    *(void **)(packet + 0x68) = (void *)func_00202620;
    *(void **)(packet + 0x6C) = (void *)func_00202640;
    *(void **)(packet + 0x70) = (void *)func_00202720;
    *(u8 **)*(u8 **)(packet + 0x78) = unit;

    return packet;
}

// FUN_002027B0
s32 func_002027b0(void) {
    func_00213b50(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00202820
s32 func_00202820(void) {
    func_00213b80(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00202850
void func_00202850(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50E, 0);
    *(void **)(temp_2 + 0x6C) = (void *)func_00202820;
}
// FUN_00202C60
void func_00202c60(u8 *arg0, s16 arg1, s16 arg2, void *arg3, void *arg4, void *arg5, void *arg6, u8 *arg7) {
    memset(arg0, 0, 0x34);
    *(s16 *)(arg0 + 6) = arg1;
    *(s16 *)(arg0 + 8) = arg2;
    *(void **)(arg0 + 0xC) = arg3;
    *(void **)(arg0 + 0x10) = arg4;
    *(void **)(arg0 + 0x14) = arg5;
    *(void **)(arg0 + 0x1C) = arg6;
    *(u8 **)(arg0 + 0x28) = arg7;
    *(u16 *)(arg0 + 0) |= 8;
    func_00202e00(arg0, NULL);
}



// FUN_00202D20
void func_00202d20(u8 *arg0, s64 arg1, s64 arg2)
{
    s32 temp_3;
    s16 temp_7;
    s16 temp_8_2;
    s32 temp_8;
    s32 temp_9;
    s64 var_6;

    var_6 = arg2;
    temp_8 = (s16)var_6;
    if ((temp_8 > 0) && (*(s16 *)(arg0 + 8) < (temp_8 + *(s16 *)(arg0 + 6)))) {
        var_6 = 0;
    }
    temp_9 = (s16)arg1;
    if (*(s16 *)(arg0 + 8) <= temp_9) {
        *(s16 *)(arg0 + 2) = 0;
        *(s16 *)(arg0 + 4) = 0;
        return;
    }
    temp_8_2 = *(s16 *)(arg0 + 8);
    temp_7 = *(s16 *)(arg0 + 6);
    if (temp_9 < ((s16)var_6 + temp_7)) {
        *(s16 *)(arg0 + 2) = (u16)var_6;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    if (temp_9 < (temp_7 - 1)) {
        *(s16 *)(arg0 + 2) = 0;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    temp_3 = temp_8_2 - temp_7;
    if (temp_3 < temp_9) {
        *(s16 *)(arg0 + 2) = temp_3;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    *(s16 *)(arg0 + 2) = (s16)(temp_9 - 1);
    *(s16 *)(arg0 + 4) = (u16)arg1;
}
// FUN_00202E00
void func_00202e00(u8 *arg0, s16 *arg1)
{
    if (arg1 != NULL) {
        func_0043f810(arg0 + 0x2C, arg1, 8);
        return;
    }
    *(s16 *)(arg0 + 0x2C) = 0x1000;
    *(s16 *)(arg0 + 0x2E) = 0x4000;
    *(u16 *)(arg0 + 0x30) = 0x8000;
    *(s16 *)(arg0 + 0x32) = 0x2000;
}

// FUN_00202E60
void func_00202e60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x18) = arg1;
}

// FUN_00202E70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202e70);
// FUN_00203360
void func_00203360(u8 *arg0, u8 *arg1) {
    u8 *temp_16;
    u8 *var_4;

    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(u8 **)(arg0 + 0xC) = arg1;
    *(u8 **)(arg0 + 8) = arg1;
    var_4 = arg1;
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0xC))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
}



// FUN_002033C0
void func_002033c0(u8 *arg0) {
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(arg0 + 8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0x1C))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
    *(u8 **)(arg0 + 8) = NULL;
}



// FUN_00203420
s32 func_00203420(u8 *arg0)
{
    u8 *sp4C;
    u8 *temp_17;
    s32 temp_16;
    u8 *temp_4;

    temp_17 = *(u8 **)(arg0 + 0xC);
    sp4C = *(u8 **)(temp_17 + 0x24);
    temp_16 = (*(s32 (**)(u8 *, s32, u8 **))(temp_17 + 0x10))(
        temp_17, *(s32 *)(temp_17 + 0x28), &sp4C) & 0xFFFF;
    switch (temp_16) {
    case 1:
        break;
    case 2:
        if (*(u8 **)(temp_17 + 0x20) != NULL) {
            if (*(void (**)(u8 *, s32))(temp_17 + 0x1C) != NULL) {
                (*(void (**)(u8 *, s32))(temp_17 + 0x1C))(
                    temp_17, *(s32 *)(temp_17 + 0x28));
            }
            *(u8 **)(arg0 + 0x10) = *(u8 **)(arg0 + 0xC);
            *(u8 **)(arg0 + 0xC) = *(u8 **)(temp_17 + 0x20);
            *(s32 *)(*(u8 **)(temp_17 + 0x20) + 0x24) = 0;
            temp_4 = *(u8 **)(temp_17 + 0x20);
            if (*(void (**)(u8 *, s32))(temp_4 + 0xC) != NULL) {
                (*(void (**)(u8 *, s32))(temp_4 + 0xC))(
                    temp_4, *(s32 *)(temp_4 + 0x28));
            }
        }
        break;
    case 3:
        if (sp4C != NULL) {
            if (*(void (**)(u8 *, s32))(temp_17 + 0x1C) != NULL) {
                (*(void (**)(u8 *, s32))(temp_17 + 0x1C))(
                    temp_17, *(s32 *)(temp_17 + 0x28));
            }
            *(u8 **)(arg0 + 0x10) = *(u8 **)(arg0 + 0xC);
            *(u8 **)(arg0 + 0xC) = sp4C;
            *(u8 **)(sp4C + 0x20) = temp_17;
            *(u8 **)(temp_17 + 0x24) = sp4C;
            *(s32 *)(sp4C + 0x24) = 0;
            if (*(void (**)(u8 *, s32))(sp4C + 0xC) != NULL) {
                (*(void (**)(u8 *, s32))(sp4C + 0xC))(
                    sp4C, *(s32 *)(sp4C + 0x28));
            }
        }
        break;
    case 4:
    case 5:
        break;
    }
    return temp_16;
}
// FUN_002035A0
void func_002035a0(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        (*(void (**)(u8 *, s32, u8 *))(var_16 + 0x14))(var_16, *(s32 *)(var_16 + 0x28), arg0);
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}



// FUN_00203600
void func_00203600(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        void (*fn)(u8 *, s32, u8 *) = *(void (**)(u8 *, s32, u8 *))(var_16 + 0x18);
        if (fn != NULL) {
            fn(var_16, *(s32 *)(var_16 + 0x28), arg0);
        }
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}



/* measured: callback materialisation residual remains. Committed at nd 73. */
// FUN_00203670
#ifdef NON_MATCHING
void func_00203670(s32 unused, s32 arg1)
{
    struct {
        s16 values[2];
        s32 pad;
    } sp38;
    s32 temp_4;
    s32 mask;
    u8 *temp_2;
    u8 *temp_16;
    temp_2 = func_00452560();
    temp_16 = temp_2 + 0x9C;
    *(s32 *)(temp_2 + 0x214) = arg1;
    *(s16 *)(temp_2 + 0x9C) = 1;
    *(s16 *)(temp_2 + 0xA4) = 0;
    mask = -3;
    *(s16 *)(temp_2 + 0xA6) = mask;
    *(s16 *)(temp_2 + 0xA8) = 0;
    *(s16 *)(temp_2 + 0xAA) = -9;
    *(s16 *)(temp_2 + 0xAE) = 0;
    *(s16 *)(temp_2 + 0xB0) = 0;
    *(s16 *)(temp_2 + 0xBC) = 0;
    *(s16 *)(temp_2 + 0xBE) = 0;
    *(s16 *)(temp_2 + 0xB2) = 0;
    *(s16 *)(temp_2 + 0xB4) = 0;
    temp_4 = *(s32 *)(temp_2 + 0xA0);
    temp_4 &= mask;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    temp_4 = temp_4 & 0xFFFFFFFEU;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    func_00202c60(temp_16 + 0x40, 8, 8,
                  (void *)func_00207140, (void *)func_00207320,
                  (void *)func_00207b00, (void *)func_002089e0, temp_16);
    func_00202e60(temp_16 + 0x40, (s32)func_00208870);
    sp38.values[0] = 0x1000;
    sp38.values[1] = 0x4000;
    func_00202e00(temp_16 + 0x40, (s16 *)&sp38);
    func_00202d20(temp_16 + 0x40, 3, 0);
    func_00203360(temp_16 + 0x2C, temp_16 + 0x40);
    *(s32 *)(temp_16 + 0x2C) = 0;
    *(s32 *)(temp_16 + 0x30) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203670);
#endif
// FUN_002037B0
void func_002037b0(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(s16 *)(p + 0x9C) = 1;
}
// FUN_002037E0
u16 func_002037e0(void) {
    return *(u16 *)((u8 *)func_00452560() + 0x9C);
}
/* measured: opt_propagation off probe for 00203810 evaluation order. */
#pragma opt_propagation off
// FUN_00203810
s32 func_00203810(void)
{
    u8 *p;
    u8 *base;
    s32 field;

    p = func_00452560();
    base = p + 0x9C;
    field = *(s32 *)(p + 0xD4);
    base += 0x40;
    return (s32)(field == (s32)base);
}
/* measured: close opt_propagation after func_00203810 probe. */
#pragma opt_propagation on
// FUN_00203850
s32 func_00203850(void)
{
    return *(s16 *)((u8 *)func_00452560() + 0xAA) < 2;
}
// FUN_00203880
void func_00203880(void)
{
}

// FUN_00203890
void func_00203890(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(s16 *)(p + 0x9C) = 4;
}
// FUN_002038C0
void func_002038c0(void) {
    u8 *b = (u8 *)func_00452560() + 0x9C;

    *(s32 *)(b + 4) &= ~2;
    func_002033c0(b + 0x2C);
    if (*(s32 *)(b + 0x5A8) != 0) {
        func_0011b360(*(s32 *)(b + 0x5A8));
        *(s32 *)(b + 0x5A8) = 0;
        *(s16 *)(b + 0x5AC) = -1;
    }
    *(s32 *)(b + 0x178) = 0;
    *(s16 *)b = 0;
}

// FUN_00203930
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203930);
// FUN_00204690
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204690);
/* measured: opt_propagation off probe for callback cache in func_00204a30. */
#pragma opt_propagation off
// FUN_00204A30
void func_00204a30(u8 *arg0, f32 fparg0, f32 fparg1)
{
    void (**base)(u32, u32);
    Work4 work;

    base = D_00887300;
    base[0](8, 1);
    base[0](6, 0);
    base[0](1, 0);
    func_003f6440(3, 0x32801);
    work.colors.c0 = 0;
    work.colors.c1 = -1;
    work.colors.c2 = 0;
    work.colors.c3 = 0x30;
    work.value3 = 0;
    work.value0 = 0;
    work.value1 = 0x280;
    work.value2 = 0x1C0;
    func_0045d6e0((u8 *)&work.colors, (f32 *)(void *)&work.value3, 0.0f, 0);
    work.colors.c0 = 0xFF;
    work.colors.c1 = 0xFF;
    work.colors.c2 = 0xFF;
    work.colors.c3 = 0x20;
    func_00204690(arg0, fparg0, fparg1, *(s32 *)(void *)&work.colors, 100.0f);
    func_003f6440(3, 0x717FB);
    base[0](8, 0);
}
/* measured: close callback cache probe for func_00204a30. */
#pragma opt_propagation on
// FUN_00204B80
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204b80);
// FUN_00204D50
void func_00204d50(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    *(s16 *)(temp_2 + 0xAC) = 0;
    *(s32 *)(temp_2 + 0xA0) &= ~1;
}
// FUN_00204D90
void func_00204d90(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0xA0) = *(s32 *)(p + 0xA0) | 0x1;
}

// FUN_00204DC0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204dc0);
// FUN_00205170
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205170);
// FUN_002055D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002055d0);
/* measured in the shipped translation unit: the candidate object was 716B
   against a 720B retail window but normalized_diff was 460. The apparent
   size agreement was an isolated declaration-environment artifact; the
   candidate is archived as build/WS02_candidate_00205950.c and discarded. */
// FUN_00205950
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205950);
/* measured in the shipped translation unit: func_00205c20 candidate object 504B/window 480B, normalized_diff 358; self-forward could not be reconciled with baseline extern void func_00205c20(void); candidate archived as build/WS02_candidate_00205c20.c and discarded. */
// FUN_00205C20
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205c20);
// FUN_00205E00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205e00);
// FUN_00205FF0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205ff0);
// FUN_00206DD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00206dd0);
// FUN_00207140
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207140);
// FUN_00207320
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207320);
// FUN_00207B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207b00);
// FUN_00208870
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208870);
// FUN_002089E0
void func_002089e0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[1] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[0] = *(s16 *)(arg0 + 2);
}

// FUN_00208A50
void func_00208a50(u8 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 6), *(s16 *)(p + 4));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}
// FUN_00208B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208b00);
// FUN_00208D00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208d00);
// FUN_00208FD0
void func_00208fd0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        func_00205ff0(arg1, arg0, arg2[0], arg2[1], func_00205170, arg0);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
}
// FUN_002090D0
void func_002090d0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[3] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[2] = *(s16 *)(arg0 + 2);
}

// FUN_00209140
void func_00209140(u8 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 0xA), *(s16 *)(p + 8));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}
/* Reconstructed state dispatch and return width; candidate is byte-exact. */
// FUN_002091F0
u16 func_002091f0(u8 *arg0, u8 *arg1)
{
    s32 temp_2;
    u16 value;

    value = func_00202e70() & 0xFFFF;
    switch (value) {
    case 2:
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 3;
        temp_2 = *(s16 *)(p4_002091f0_add((u32)(*(s16 *)(arg0 + 4) * 4), arg1) + 0x1A6);
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x70) = temp_2;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) =
            func_00243920(*(u16 *)(*(u8 **)(arg1 + 0x178) + 0x70));
        *(s16 *)(arg1 + 0x1A) = 0;
        value = 4;
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 0xD, 2, 0x17);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            value = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            value = 2;
        }
        break;
    default:
        value = 1;
        break;
    }
    return value;
}
// FUN_00209370
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209370);
// FUN_00209640
void func_00209640(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        func_00205ff0(arg1, arg0, arg2[0], arg2[1], func_002055d0, arg0);
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
}
// FUN_00209740
void func_00209740(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[5] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[4] = *(s16 *)(arg0 + 2);
}

// FUN_002097B0
void func_002097b0(u8 *arg0, u8 *arg1)
{
    u8 *p;

    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 0xE), *(s16 *)(p + 0xC));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    if (*(s32 *)(arg1 + 0x3C) != (s32)(arg1 + 0x110)) {
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(arg1 + 0x20) = 0;
        *(s16 *)(arg1 + 0x22) = 0;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
    }
}
// FUN_00209870
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209870);
// FUN_002099C0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002099c0);
// FUN_00209BC0
void func_00209bc0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u8 **)(arg1 + 0x38) == arg1 + 0xDC) {
        if (*(u16 *)arg1 != 2) {
            func_00205ff0(arg1, arg0, arg2[0], arg2[1],
                          (void (*)(void))func_00205c20, arg0);
        }
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
}
// FUN_00209CD0
void func_00209cd0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[7] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[6] = *(s16 *)(arg0 + 2);
}

// FUN_00209D40
void func_00209d40(u8 *arg0, u8 *arg1)
{
    func_0045af60(0, 0, 0, 3);
    func_00202d20(arg0, 0, 0);
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x1C) = 0;
    *(s16 *)(arg1 + 0x1E) = 0;
}

// FUN_00209DC0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209dc0);
// FUN_00209F90
void func_00209f90(void)
{
}
// FUN_00209FA0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209fa0);
// FUN_0020A5C0
void func_0020a5c0(void)
{
}
// FUN_0020A5D0
void func_0020a5d0(u16 *arg0, u8 *arg1) {
    func_0045af60(0, 0, 0, 3);
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}

// FUN_0020A640
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020a640);
// FUN_0020AA70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020aa70);
// FUN_0020AC70
void func_0020ac70(s32 arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)arg1 != 2) {
        func_00205ff0(arg1, (u8 *)arg0, arg2[0], arg2[1],
                      (void (*)(void))func_00205950, (u8 *)arg0);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
}
// FUN_0020AD70
void func_0020ad70(void)
{
}

// FUN_0020AD80
void func_0020ad80(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x5B4);
    *(s32 *)(arg0 + 0x5B0) = arg1;
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 0x5AC) = -1;
}



// FUN_0020ADD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020add0);
// FUN_0020B1A0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b1a0);
// FUN_0020B3A0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b3a0);
// FUN_0020B5A0
void func_0020b5a0(void)
{
}

/* measured: nd 41 against retail's 96-byte window (real body 92). Retail
   materialises the ~0x200 mask in the loop preheader, ahead of the branch into
   the condition, and keeps it in $a0 for the whole loop; b210 rematerialises it
   inside the body, which also transposes the and's operands. Declaring the mask
   first, assigning it last, and spelling the update as an explicit
   `x = x & mask` all leave it at nd 41, and retail additionally carries a nop
   at the loop's condition label that b210 never emits. Committed at nd 41. */

// FUN_0020B5B0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b5b0);

// FUN_0020B6D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b6d0);

// FUN_0020BA00
u16 func_0020ba00(void) {
    return *(u16 *)((u8 *)func_00452560() + 0x712);
}

// FUN_0020BA30
void func_0020ba30(void)
{
    *(s16 *)((u8 *)func_00452560() + 0x712) = 0;
}

// FUN_0020BA60
void func_0020ba60(void)
{
    func_001d8bc0(*(u8 **)((u8 *)func_00452560() + 0x720));
}

// FUN_0020BA90
void func_0020ba90(void)
{
    func_001d8bc0(*(u8 **)((u8 *)func_00452560() + 0x720));
}
// FUN_0020BAC0
/* measured: retail keeps the ~0x200 mask live in the loop preheader; plain -O2
   rematerialises it inside the body (nd 41 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
void func_0020bac0(void) {
    u8 *w = (u8 *)func_00452560() + 0x710;
    s32 mask = ~0x200;
    u8 *p = *(u8 **)(D_0076449C + 0x178);

    while (p != NULL) {
        *(s32 *)(p + 0xA10) &= mask;
        p = *(u8 **)(p + 0xA6C);
    }
    *(s16 *)(w + 2) = 3;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// FUN_0020BB20
void func_0020bb20(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x1C);
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 2) = 3;
}



// FUN_0020BB70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020bb70);
// FUN_0020BD70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020bd70);
// FUN_0020BF60
void func_0020bf60(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(u16 *)(p + 0x710) |= 1;
}
// FUN_0020BF90
void func_0020bf90(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(u16 *)(p + 0x710) &= 0xFFFE;
}
// FUN_0020BFC0
void func_0020bfc0(u8 *arg0, s16 arg1)
{
    *(s16 *)(arg0 + 0) = arg1;
    *(s16 *)(arg0 + 2) = 0;
}
// FUN_0020BFD0
void func_0020bfd0(u8 *arg0)
{
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 1;
}
// FUN_0020E010
void func_0020e010(s32 arg0, u8 *arg1, u8 *arg2)
{
    extern void func_00195d50(u8 *arg0, f32 *arg1);
    extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_0020bff0(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void func_0020c680(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void func_0020ce60(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void func_0020d6a0(s32 arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    struct E010Frame {
        u8 pad[8];
        u8 value[4];
        u8 gap[4];
        u8 vector[12];
    } work;
    u8 *temp_16;
    u16 temp_3;
    u16 temp_4;

    temp_16 = func_00452560();
    temp_3 = *(u16 *)(arg1 + 2);
    if (temp_3 == 0) {
        if (*(u8 *)(arg2 + 0xA2) == 0) {
            *(s32 *)(arg2 + 0xA10) &= ~0x200;
        }
        return;
    }
    if (*(u8 *)(arg2 + 0xA2) != 0) {
        goto flags_done;
    }
    switch (temp_3) {
    case 1:
    case 4:
        goto flag_set;
    default:
        goto flag_clear;
    }
flag_set:
    *(s32 *)(arg2 + 0xA10) |= 0x200;
    goto flags_done;
flag_clear:
    *(s32 *)(arg2 + 0xA10) &= ~0x200;
flags_done:
    func_00195d50(arg2, (f32 *)work.vector);
    if (func_001ec4a0((f32 *)work.vector, (f32 *)work.value) != 0) {
        func_002012d0(temp_16, 0.0f, 0.0f);
        temp_4 = *(u16 *)(arg1 + 0);
        switch (temp_4) {
        case 0:
            func_0020bff0(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 1:
            func_0020c680(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 2:
            func_0020ce60(arg0, arg1, arg2, (f32 *)work.value);
            return;
        case 3:
            func_0020d6a0(arg0, arg1, arg2, (f32 *)work.value);
            break;
        }
    }
}
// FUN_0020E1D0
void func_0020e1d0(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 3;
    *(u16 *)(arg0 + 0x10) &= 0xFFFE;
    *(u16 *)(arg0 + 0x10) &= 0xFFFD;
    *(s16 *)(arg1 + 4) = 0;
    *(s16 *)(arg1 + 2) = 2;
    *(u16 *)(arg1 + 0x10) &= 0xFFF7;
    *(u16 *)(arg1 + 0x10) &= 0xFFFB;
    *(u16 *)(arg1 + 0x10) &= 0xFFFD;
    *(u16 *)(arg1 + 0x10) |= 1;
    *(Vec2f *)(arg1 + 8) = *(Vec2f *)(arg0 + 8);
}



// FUN_0020E250
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e250);
// FUN_0020E3F0
void func_0020e3f0() {
    func_002119a0(func_00452560() + 0x75C);
}

// FUN_0020E420
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e420);
// FUN_0020E5C0
f32 func_0020e5c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    f32 temp_f0;

    if (arg0 < arg1) {
        temp_f0 = 0.0f;
        goto done;
    }
    if (arg0 < arg2) {
        temp_f0 = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 1:
            temp_f0 = func_0044b7b0(fGpffff84a4 * temp_f0);
            goto done;
        case 2:
            temp_f0 = 1.0f - func_0044b610(fGpffff84a4 * temp_f0);
            goto done;
        default:
            goto done;
        }
    }
    temp_f0 = 1.0f;
done:
    return temp_f0;
}
// FUN_0020E690
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e690);
// FUN_0020EA60
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ea60);
// FUN_0020EF10
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ef10);
/* measured: struct aggregate spelling probe for F4D0. */
#pragma opt_propagation off
// FUN_0020F4D0
void func_0020f4d0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1)
{
    extern u8 *func_00452560(s32 arg0);
    Vec2f sp48;
    f32 temp_f1;
    f32 var_f1;
    f32 var_f20;
    u8 *temp_17;
    s32 temp_16;

    temp_17 = (u8 *)func_00452560(*(s32 *)(arg0 + 4));
    temp_16 = *(s32 *)(arg1 + 0x10);
    if (temp_16 < 0) {
        var_f20 = 0.0f;
    } else if (temp_16 < 6) {
        var_f20 = (f32)temp_16 / 6.0f;
    } else {
        var_f20 = 1.0f;
    }
    if (!(var_f20 <= 0.0f)) {
        sp48.x = 86.0f + fparg0;
        sp48.y = 86.0f + fparg1;
        if (var_f20 == 1.0f) {
            func_00364c90(*(s64 *)&sp48, 0x151515FF, 0.0f, 87.0f,
                          16.0f, fGpffff815c, 1);
        }
        temp_f1 = 2.0f - var_f20;
        func_00364c90(*(s64 *)&sp48, 0xFF0F02FF, 0.0f,
                      87.0f * temp_f1, 16.0f * temp_f1,
                      fGpffff83b0, 1);
    }
    if (temp_16 < 7) {
        var_f1 = 0.0f;
    } else if (temp_16 < 7) {
        var_f1 = (f32)(temp_16 - 7) / 0.0f;
    } else {
        var_f1 = 1.0f;
    }
    if (!(var_f1 <= 0.0f)) {
        func_002016e0(temp_17, 0x1C, 8, -30.0f);
        func_00201650(temp_17, 0xA, 6, 58.0f, 78.0f,
                      0x15, 0x15, 0x15, 0xFF);
        func_002016e0(temp_17, 0, 0, 0.0f);
    }
}
/* measured: close the F4D0 propagation probe. */
#pragma opt_propagation on
// FUN_0020F730
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020f730);
// FUN_0020FA70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020fa70);
// FUN_0020FF00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ff00);
