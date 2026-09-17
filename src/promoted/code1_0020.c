#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "fr_font_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
typedef struct BtlUnit BtlUnit;
typedef struct BtlAction BtlAction;

extern s32 func_00247cb0(s16 arg0);
extern u16 func_00107ac0(s32 arg0);
extern void func_00209d40(u8 *arg0, u8 *arg1);
extern u16 func_00209dc0(u8 *arg0, u8 *arg1);
extern void func_00209fa0(s32 arg0, u8 *arg1, f32 *arg2);
extern void func_00209f90(void);
extern void func_0020a5c0(void);
extern void func_00202d20();
extern void func_00113500(void);
extern void func_00113480(s32 a0, s32 a1, s32 a2, s32 a3);
extern f32 func_0046b260(u8 *arg0);
extern f32 func_0046b2f0(u8 *arg0);
extern s32 func_00201ee0(void);
extern s32 func_00202820(void);
extern void func_0021afa0(s32 arg0);
extern void func_0020e3f0();

extern u32 func_00106330(s32 arg0);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern void func_00213ab0(s32 arg0, u8 *arg1);
extern void func_0021ae60(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern void func_00202e00(u8 *arg0, s16 *arg1);
extern void func_00202460(u8 *arg0);
extern s32 func_00202480(u8 *arg0);
extern void func_00202570(u8 *arg0);
extern u32 func_001067f0(s16 arg0);
extern s32 func_001eb860(void);

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


extern u32 func_00452560();
extern f32 fGpffff815c;
extern f32 fGpffff83b0;
extern u8 *func_0010ace0(s16 arg0);
extern s32 func_0010b510(void);
extern s32 func_00109390(u8 *arg0);
extern s32 func_00109220(s32 arg0);
extern u16 func_00272c60(s16 arg0);
extern u16 func_00272c80(u16 arg0);

extern u32 func_001d8bc0(void *arg0);
extern void func_0011b360(u8 *arg0);
extern s32 func_0011ba00(u8 *arg0);
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
extern void func_0011bb90(u8 *arg0);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0011c2c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 func_0011c610(u8 *arg0);
extern void func_0011c630(u8 *arg0);
extern void func_0011c6e0(u8 *arg0, s32 arg1);
extern void func_0011caf0(u8 *arg0);
extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void func_002119a0(u8 *arg0);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void func_00216c40(s32 arg0, s32 arg1);
extern s32 func_00243e90(u8 *arg0);
extern void func_00216b40(s32 arg0, s32 arg1);
extern void func_00216bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00216d10(s32 task);



extern u8 *func_00194470(s32 id, s32 size);
extern s32 func_00202340(u8 *arg0);
extern s32 func_00202070(u8 *arg0);
extern s32 func_00202180(u8 *arg0);


extern s32 func_00202640(u8 **arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
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
extern void func_00213b50(s32 task);
extern void func_00213b80(s32 task);
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern s32 func_00200ce0(void);
extern void func_00205170(u8 *arg0, s32 arg1, f32 fx, f32 fy, s32 arg2, s32 arg3, s32 arg4);
extern void func_00205ff0(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          void (*callback)(void), u8 *arg3);
extern void func_002055d0(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 show_detail);
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
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern u8 *func_00457120(void);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void func_00201820(s32 arg0);
extern void func_00205c20(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted);
extern void func_00205950(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted);
extern u16 func_00243920(s64 arg0);
extern void func_00207140(u16 *flags, u8 *work);
extern s32 func_00207320(u8 *arg0, u8 *arg1, u8 **arg2);
extern void func_00207b00();
extern void func_002089e0();
extern void func_00208870(u8 *unused, u8 *arg1, f32 *arg2);
extern void func_001bc660(s32 state, BtlAction *action, u32 param_3);
extern void func_001bcd40(f32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u16 arg4);
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
extern s32 func_00242930(u8 *arg0);
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern void func_0021b310(u8 *arg0, s32 arg1);
extern void func_0020bb70(u8 *arg0);
extern void func_00219130(void *arg0);
extern void func_0021b1e0(void *arg0);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern void func_0020ad80(u8 *arg0, s32 arg1);
extern void func_0020b1a0(s32 arg0, u8 *arg1);
extern void func_0020bb70(u8 *arg0);
extern void func_0020b3a0(s32 arg0, u8 *arg1);
extern void func_0020b5a0(void);
extern void func_0020b5b0(s32 arg0, u8 *arg1);
extern void func_0020bb20(u8 *arg0, s32 arg1);
extern void func_0020bd70(u8 *arg0, u8 *arg1);
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
extern void func_0021b1f0(s32 arg0, s32 *arg1);
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
void func_00200770(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 sp40;
        Vec3 sp4C;
        u8 pad18[8];
        u8 sp60[0x10];
        u8 sp70[0x20];
        u8 sp90[0x40];
        u8 spD0[0x10];
        u8 spE0[0x40];
        Vec3 sp120;
    } Frame;
    extern void func_001bcd40(f32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u32 arg4);
    extern u16 func_001bc7f0(void);
    extern void func_0048a150(void *arg0, void *arg1);
    extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
    extern void func_0047a1e0(void *arg0, f32 *arg1, s32 arg2);
    extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
    extern void func_00478e70(void *arg0);
    extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
    extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
    extern void func_001bab00(void *arg0, void *arg1);
    extern u8 *iGpffffb474;
    Frame frame;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_4;
    u32 temp_3;
    f32 temp_f0;

    temp_17 = *(u8 **)(arg0 + 0x30);
    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u32 *)(arg0 + 0x28);
    temp_3 = *(u32 *)(temp_16 + 0x2C);
    if ((temp_3 >= temp_4) || (temp_3 == 0)) {
        if (temp_4 == 0) {
            if (*(u16 *)(temp_16 + 0x38) == 0) {
                func_001bc660(1, NULL, 1);
                func_001bcd40(0.0f, NULL, NULL, NULL, 0x100);
            } else {
                func_001bc660(1, NULL, 0);
            }
        }
        if (((func_001bc7f0() & 0xFFFF) == 1) && (*(s32 *)temp_17 != 0)) {
            func_0048a150(frame.spE0, arg0 + 0x10);
            func_0047a1c0(*(u8 **)temp_17, frame.spE0, 0);
            temp_f0 = *(f32 *)(arg0 + 0x20) * *(f32 *)(temp_16 + 0x34);
            frame.sp120.z = temp_f0;
            frame.sp120.y = temp_f0;
            frame.sp120.x = temp_f0;
            func_0047a1e0(*(u8 **)temp_17, &frame.sp120.x, 2);
            frame.sp120.x = *(f32 *)(arg0 + 0);
            frame.sp120.y = *(f32 *)(arg0 + 4);
            frame.sp120.z = *(f32 *)(arg0 + 8);
            func_0047a180((RwMatrix *)*(u8 **)temp_17, (const RwV3d *)&frame.sp120, 2);
            func_0047a0e0(*(u8 **)temp_17, 0, *(f32 *)(temp_16 + 0x30));
            func_00478e70(*(u8 **)temp_17);
            func_0047a510(*(u8 **)temp_17, *(u16 *)(temp_17 + 4), frame.sp60);
            func_0047a510(*(u8 **)temp_17, *(u16 *)(temp_17 + 4) + 1, frame.sp90 + 0x10);
            frame.sp40 = *(Vec3 *)frame.sp90;
            func_001bd780(&frame.sp4C, frame.sp90, frame.spD0, frame.sp70);
            func_001bab00(iGpffffb474 + 0x24, &frame.sp40);
        }
    }
}
// FUN_00200960
void func_00200960(void) {
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
}
/* measured: clean-C body is byte-exact in the current TU (object/window 208B, normalized_diff 0). */
// FUN_00200980
void func_00200980(u8 *arg0)
{
    s32 temp_3;
    s32 temp_5;
    u8 *temp_6;
    f32 var_f1;
    f32 var_f0;
    f32 temp_f2;

    temp_6 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(arg0 + 0x28);
    temp_5 = *(s32 *)(temp_6 + 0);
    if ((temp_5 == 0) || ((u32)temp_5 < (u32)temp_3)) return;
    temp_f2 = *(f32 *)(temp_6 + 4);
    var_f1 = (f32)(u32)temp_3;
    var_f0 = (f32)(u32)temp_5;
    var_f1 /= var_f0;
    var_f0 = *(f32 *)(temp_6 + 8) - temp_f2;
    var_f0 = func_0020_mul(var_f1, var_f0);
    var_f1 = var_f0 + temp_f2;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff81a8 * var_f1;
}

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
        func_001bc660(0x2E, (BtlAction *)func_001b0c80(D_00881444_abs[0]), 1);
        break;
    case 3:
        func_001bc660(6, (BtlAction *)func_001b0c80(D_00881444_abs[0]), 1);
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

    temp_2 = (u8 *)func_00452560();
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
    func_00213ab0((s32)arg0, arg1);
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
void func_00201410(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1)
{
    u8 *entry;
    u32 offset;
    f32 value;

    offset = (u32)(arg1 * 4);
    entry = p4_002091f0_add(offset, arg0);
    *(s32 *)(arg0 + 0x6C) = *(s32 *)(entry + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    if ((*(f32 *)(arg0 + 0x14) == 1.0f) &&
        (*(f32 *)(arg0 + 0x18) == 1.0f)) {

        *(f32 *)(arg0 + 0x74) = (f32)*(s32 *)(arg0 + 4) + fparg0;
        *(f32 *)(arg0 + 0x78) = (f32)*(s32 *)(arg0 + 8) + fparg1;
        func_0046b380(arg0 + 0x6C, 0);
        return;
    }
    *(f32 *)(arg0 + 0x74) =
        (f32)*(s32 *)(arg0 + 4) +
        ((f32)*(s32 *)(arg0 + 0x0C) *
         (1.0f - *(f32 *)(arg0 + 0x14))) * 0.5f +
        *(f32 *)(arg0 + 0x14) * fparg0;
    *(f32 *)(arg0 + 0x78) =
        (f32)*(s32 *)(arg0 + 8) +
        ((f32)*(s32 *)(arg0 + 0x10) *
         (1.0f - *(f32 *)(arg0 + 0x18))) * 0.5f +
        *(f32 *)(arg0 + 0x18) * fparg1;
    value = *(f32 *)(arg0 + 0x14) * 4096.0f * *(f32 *)(arg0 + 0x1C);
    *(u16 *)(arg0 + 0x8C) = (u16)value;
    value = *(f32 *)(arg0 + 0x18) * 4096.0f * *(f32 *)(arg0 + 0x20);
    *(u16 *)(arg0 + 0x8E) = (u16)value;
    if (*(f32 *)(arg0 + 0x84) != 0.0f) {
        *(s16 *)(arg0 + 0x88) =
            (s16)(*(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x14));
        *(s16 *)(arg0 + 0x8A) =
            (s16)(*(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x18));
    }
    func_0046b380(arg0 + 0x6C, 0);
    *(u16 *)(arg0 + 0x8C) = 0;
    *(u16 *)(arg0 + 0x8E) = 0;
}
/* Keep the opacity base ahead of byte promotion, matching retail order. */
#pragma push
#pragma opt_propagation off
// FUN_00201650
void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1,
                   u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    arg0[0x94] = (u8)arg5;
    arg0[0x95] = (u8)arg6;
    arg0[0x96] = (u8)arg7;
    {
        s32 maximum = 0xFF;
        arg0[0x7D] = maximum - (arg8 & 0xFF);
    }
    func_00201410(arg0, arg1, arg2, fparg0, fparg1);
    arg0[0x94] = 0xFF;
    arg0[0x95] = 0xFF;
    arg0[0x96] = 0xFF;
    arg0[0x7D] = 0;
}
#pragma pop

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
void func_00201720(u8 *arg0, f32 fparg0, f32 fparg1)
{
    if ((fparg0 == 1.0f) && (fparg1 == 1.0f)) {
        *(s16 *)(arg0 + 0x8C) = 0;
        *(s16 *)(arg0 + 0x8E) = 0;
    } else {
        *(u16 *)(arg0 + 0x8C) = (u16)(4096.0f * fparg0);
        *(u16 *)(arg0 + 0x8E) = (u16)(4096.0f * fparg1);
    }
    *(f32 *)(arg0 + 0x1C) = fparg0;
    *(f32 *)(arg0 + 0x20) = fparg1;
}
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
f32 func_00201950(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    return func_0046b260(arg0 + 0x6C);
}
// FUN_00201990
f32 func_00201990(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    return func_0046b2f0(arg0 + 0x6C);
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
/* Measured: 676/688 bytes, seven resolved relocations and twelve zero alignment bytes.
 * Snapshot inputs before providers; reload the skill fields and final output
 * metadata at their retail callback boundaries. */
#pragma push
#pragma opt_propagation off
// FUN_00201B00
s32 func_00201b00(u8 *work)
{
    u16 flags;
    u32 input_flags;
    s32 empty;
    s32 value0;
    s32 value1;
    struct { s32 value0; s32 value1; u16 flags; } result;
    f32 position[3];
    s32 value;
    u8 *table;
    s32 offset;

    extern u8 *iGpffffb3b8;
    extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
    extern s32 func_0023d6e0(s16 arg0);
    extern void func_00195ea0(BtlUnit *unit, RwV3d *position);
    extern void func_001959d0(BtlUnit *unit, RwV3d *position);
    extern void func_0020e250(u8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, u16 arg4);

    flags = 0;
    input_flags = *(u16 *)(work + 0x2C);
    if ((input_flags & 4) ||
        (*(s32 *)(work + 8) == 0 && *(s32 *)(work + 0xC) == 0 &&
         *(s32 *)(work + 0x10) == 0 && *(s32 *)(work + 0x14) == 0 &&
         *(s32 *)(work + 0x18) == 0)) {
        empty = 1;
    } else {
        empty = 0;
    }

    value0 = *(s32 *)(work + 8);
    if (value0 != 0) {
        flags |= 0x10;
    } else {
        value0 = 0;
    }

    value1 = *(s32 *)(work + 0xC);
    if (value1 != 0) {
        flags |= 0x20;
    } else {
        value1 = 0;
    }

    if (*(u16 *)(work + 0x32) == *(u16 *)(work + 0x30) + 1) {
        if (empty == 0) {
            value = *(u16 *)(work + 0x2E);
            if (value & 2) {
                flags |= 1;
            }
            if (value & 4) {
                flags |= 2;
            }
        }

        if (input_flags & 0x100) {
            value = *(s32 *)(work + 0x28);
            if (value != -1 && *(u8 **)(*(u8 **)work + 0xA64) != NULL) {
                value = func_0023d8e0(*(u8 **)(*(u8 **)work + 0xA64), value & 0xFFFF);
                value = func_0023d6e0((s16)value);
            } else {
                value = 0;
            }
            if (!(value & 0x1FE00)) {
                flags |= 8;
            } else {
                flags |= 4;
            }
        } else if (empty != 0) {
            flags |= 4;
        }

        if (*(s32 *)(work + 0x10) & 0x100000) {
            flags |= 0x40;
        }
    }

    offset = *(s32 *)(work + 0x28);
    if (offset >= 0) {
        offset *= 0x28;
        table = iGpffffb3b8;
        value = *(u8 *)((u32)offset + (u32)table + 8);
        switch (value) {
        case 1:
        case 2:
            flags |= 0x80;
            break;
        }
        if (*(u8 *)(table + offset) & 0x20) {
            flags &= 0xFFFB;
        }
    }

    result.value0 = value0;
    result.value1 = value1;
    result.flags = flags;
    if (*(s32 *)(work + 0x34) != 0) {
        func_00195ea0((BtlUnit *)*(u8 **)(work + 4), (RwV3d *)position);
    } else {
        func_001959d0((BtlUnit *)*(u8 **)(work + 4), (RwV3d *)position);
    }

    func_0020e250(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(work + 4),
                  (s32 *)&result, position, *(u16 *)(work + 0x38));
    return 1;
}
#pragma pop
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
u8 *func_002022e0(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x507, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)func_00202180;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return (u8 *)iVar2;
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
void func_00202e60(u8 *arg0, void *arg1)
{
    *(s32 *)(arg0 + 0x18) = (s32)arg1;
}

/* Flag-ladder floor (1264B window). First probe nd 231
   (obj 1208B, in-window); frame/prologue verified. Open:
   GPREL-vs-absolute masks (scope-proof), return masking,
   scheduler ordering. s32 counter beats s16 (-16); sign-
   extend at checks verified; IDA returns over Ghidra.
   u8 def avoids caller churn; s32 return = int history. */
// FUN_00202E70 NONMATCHING
#ifdef NON_MATCHING
s32 func_00202e70(u8 *arg0)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0276[];
    extern u16 D_008C027A[];
    u16 *a;
    s16 v1;
    s32 v2;
    s32 v5;
    s32 v6;
    s32 v7;
    s16 v8;
    s32 i;

    a = (u16 *)arg0;
    v1 = (s16)a[4];
    if ((s16)a[2] >= v1) {
        a[2] = v1 - 1;
        v2 = (s16)a[4] - (s16)a[3];
        a[1] = v2;
        if ((s16)v2 < 0LL) {
            a[1] = 0;
        }
    }
    if (D_008C024E[0] & 0x40) {
        return 2;
    }
    if (D_008C024E[0] & 0x20) {
        return 1;
    }
    if (D_008C024E[0] & 0x80) {
        return 3;
    }
    if ((a[0] & 4) != 0 && (D_008C024E[0] & 4) != 0) {
        return 4;
    }
    if (((D_008C027A[0] & a[22]) != 0) || (((a[0] & 1) != 0) && ((D_008C027A[0] & a[24]) != 0))) {
        v5 = 1;
        v6 = (D_008C027A[0] & a[24]) != 0;
        v7 = (D_008C027A[0] & a[24]) == 0;
        if ((D_008C027A[0] & a[24]) != 0) {
            v8 = a[3];
        } else {
            v8 = 1;
        }
        for (i = 0; i < v8; i = i + 1) {
            v1 = (s16)a[1];
            v2 = (s16)a[2];
            if (v1 + 1 < v2) {
                a[2] = v2 - 1;
            } else if (v1 <= 0) {
                if (v2 != 1) {
                    if (((a[0] & 2) == 0) || ((D_008C0276[0] & a[22]) != 0) || (v6 != 0 && ((D_008C0276[0] & a[24]) != 0))) {
                        v2 = (s16)a[4] - (s16)a[3];
                        a[1] = v2;
                        if ((s16)v2 < 0LL) {
                            a[1] = 0;
                        }
                        a[2] = (s16)a[4] - 1;
                    } else {
                        v5 = 0;
                        a[1] = 0;
                        a[2] = 0;
                    }
                    break;
                }
                a[2] = 0;
            } else {
                a[1] = v1 - 1;
                a[2] = a[2] - 1;
            }
        }
        if (v5 != 0 && (a[0] & 8) != 0) {
            if (v6 != 0) {
                func_0045af60(0, 0, 0, 5);
            } else {
                func_0045af60(0, 0, 0, 0);
            }
        }
        if (v7 == 0) {
            return 7;
        } else {
            return 5;
        }
    } else if (((D_008C027A[0] & a[23]) != 0) || (((a[0] & 1) != 0) && ((D_008C027A[0] & a[25]) != 0))) {
        v5 = 1;
        v6 = (D_008C027A[0] & a[25]) != 0;
        v7 = (D_008C027A[0] & a[25]) == 0;
        if ((D_008C027A[0] & a[25]) != 0) {
            v8 = a[3];
        } else {
            v8 = 1;
        }
        for (i = 0; i < v8; i = i + 1) {
            v1 = (s16)a[1];
            v2 = (s16)a[2];
            if (v1 + 1 < v2) {
                a[2] = v2 - 1;
            } else if (v1 <= 0) {
                if (v2 != 1) {
                    if (((a[0] & 2) == 0) || ((D_008C0276[0] & a[23]) != 0) || (v6 != 0 && ((D_008C0276[0] & a[25]) != 0))) {
                        v2 = (s16)a[4] - (s16)a[3];
                        a[1] = v2;
                        if (v2 < 0) {
                            a[1] = 0;
                        }
                        a[2] = (s16)a[4] - 1;
                    } else {
                        v5 = 0;
                        a[1] = 0;
                        a[2] = 0;
                    }
                    break;
                }
                a[2] = 0;
            } else {
                a[1] = v1 - 1;
                a[2] = a[2] - 1;
            }
        }
        if (v5 != 0 && (a[0] & 8) != 0) {
            if (v6 != 0) {
                func_0045af60(0, 0, 0, 5);
            } else {
                func_0045af60(0, 0, 0, 0);
            }
        }
        if (v7 == 0) {
            return 8;
        } else {
            return 6;
        }
    } else {
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202e70);
#endif
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
    u8 *temp_18;
    temp_2 = (u8 *)func_00452560();
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
    temp_18 = temp_16 + 0x40;
    func_00202e60(temp_18, (void *)func_00208870);
    func_0043f9c8((s16 *)&sp38, 0, 8);
    sp38.values[0] = 0x1000;
    sp38.values[1] = 0x4000;
    func_00202e00(temp_16 + 0x40, (s16 *)&sp38);
    func_00202d20(temp_16 + 0x40, 3, 0);
    func_00203360(temp_16 + 0x2C, temp_16 + 0x40);
    *(s32 *)(temp_16 + 0x2C) = 0;
    *(s32 *)(temp_16 + 0x30) = 0;
}
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

    p = (u8 *)func_00452560();
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
void func_002038c0(s32 task) {
    u8 *b = (u8 *)func_00452560((void *)task) + 0x9C;

    *(s32 *)(b + 4) &= ~2;
    func_002033c0(b + 0x2C);
    if (*(s32 *)(b + 0x5A8) != 0) {
        func_0011b360(*(u8 **)(b + 0x5A8));
        *(s32 *)(b + 0x5A8) = 0;
        *(s16 *)(b + 0x5AC) = -1;
    }
    *(s32 *)(b + 0x178) = 0;
    *(s16 *)b = 0;
}

// FUN_00203930
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203930);
/*
 * measured: 916/928 bytes, 15 resolved relocations, 12 zero alignment bytes.
 * The initialization loop covers 81 real vertex records; the four geometry
 * phases supply 77 vertices. Keep each quadrant cursor's separate lifetime.
 */
// FUN_00204690
#pragma push
#pragma opt_loop_invariants on
void func_00204690(u8 *unused, f32 scaleX, f32 scaleY, s32 color, f32 depth)
{
    f32 vertices[81][16];
    u32 alpha = ((u8 *)&color)[3];
    u32 blue = ((u8 *)&color)[2];
    u32 green = ((u8 *)&color)[1];
    u32 red = ((u8 *)&color)[0];
    f32 reciprocal;
    f32 transformedDepth;
    u32 vertex;
    u32 initialize;
    scaleX *= fGpffff82e0;
    scaleY *= fGpffff82e4;
    transformedDepth = D_008872F8[0] - depth;
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    for (initialize = 0; initialize < 81; initialize++) {
        f32 *out = vertices[initialize];
        out[2] = transformedDepth;
        out[6] = reciprocal;
        out[8] = (f32)red;
        out[9] = (f32)green;
        out[10] = (f32)blue;
        out[11] = (f32)alpha;
    }
    vertex = 0;
    vertices[0][0] = 320.0f;
    vertices[0][1] = 211.0f;
    {
        s32 i;
        for (i = 0; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 1; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    D_00887310[0](5, vertices, vertex);
}
#pragma pop
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
/* 460/464 bytes; 13 resolved relocations; four zero alignment bytes.
 * Forward byte opacity and reload the render-state callback for every call. */
#pragma push
#pragma opt_propagation off
// FUN_00204B80
void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 opacity)
{
    extern u8 D_00764564;
    s16 row;
    s16 column;
    s16 frame;
    f32 x;
    f32 y;

    {
        void (**state)(u32, u32);
        state = D_00887300;
        state[0](6, 1);
    }
    func_002012d0(arg0, 36.0f, 19.0f);
    func_002019e0(arg0, 50.0f);
    func_00201820(2);
    y = 0.0f;
    row = 0;
    while (row < 3) {
        x = 0.0f;
        column = 0;
        while (column < 5) {
            frame = D_00764564 % 4;
            D_00764564++;
            func_00201650(arg0, 15, frame, x, y, 255, 255, 255, opacity);
            x += 126.0f;
            column++;
        }
        y += 126.0f;
        row++;
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    {
        void (**state)(u32, u32);
        state = D_00887300;
        state[0](6, 0);
        state[0](1, 0);
    }
}
#pragma pop
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

/* Fresh rotated panel strip candidate: func_00204dc0.
 * Owner src/promoted/code1_0020.c. PRODUCTION REMAINS ASM.
 * Initial source856/944 bytes,nd660,18 object relocations. Preferred scoped
 * opt_propagation off source864/944 bytes,nd628,18 relocations:76 executable bytes
 * remain uncovered,plus four retail alignment bytes. Adding loop-invariant
 * optimization ties; disabling common subexpressions as well produces1216/nd1005.
 * No exact-match or behavioral-smoke claim is made for this candidate.
 * 
 * Actual inputs are index in a0,extend flag in a1,and four floats in f12..f15:
 * positionX,positionY,depth,angle. Index is sign-truncated to16 bits at use.
 * Four actual64-byte immediate vertex records form the first opaque27-gray strip;
 * the optional extension rewrites XY and colors while retaining depth/reciprocal
 * from the first pass, including any mutations made by the drawing callbacks.
 * Texture is disabled before geometry. Preserve the first draw's00364C50/00364C70
 * bracket and optional render-state8 enable/disable pair. Repeated zero terms,
 * FP accumulation and coordinate sharing do not yet reproduce retail code.
 * No invented inputs,synthetic stack padding,inline assembly or register binding
 * is used. Declarations below supplement the current owner; existing production
 * callers remain unchanged.
 */

extern f32 fGpffff836c;
extern void func_00364c50(void);
extern void func_00364c70(void);

/* measured: object 864B/window 944B/normalized_diff 628 (210 differing words, live re-measured current tree). */
/* measured: 234 vs 216 instrs (minus 18, 7pt short, draft-short pending plus-11 via s0-s1 decl swap and f23-f26 FPR coloring to reach floor); loop-invariant on worsens 210 to 221; slti-at N-A, no trailing short cascade beyond distributed coloring, arg-setup per archived conventions, schedule neutral. */
// FUN_00204DC0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_00204dc0(s32 index, f32 x, f32 y, f32 depth, f32 angle, s32 extend)
{
    f32 vertices[4][16];
    f32 reciprocal;
    f32 cosine;
    f32 sine;
    f32 width;
    f32 halfWidth;
    D_00887300[0](1, 0);
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    depth = D_008872F8[0] - depth;
    angle = fGpffff836c * angle;
    cosine = func_0044b610(angle);
    sine = func_0044b7b0(angle);
    width = 86.0f;
    x = 97.0f + x;
    y += (0.0f + 312.0f) + 15.0f * (f32)((s16)index - 3);
    halfWidth = width + 64.0f;
    vertices[0][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - 8.0f * sine;
    vertices[0][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + 8.0f * cosine;
    vertices[0][2] = depth;
    vertices[1][0] = (x + (0.0f - halfWidth) * cosine) - 8.0f * sine;
    vertices[1][1] = (y + (0.0f - halfWidth) * sine) + 8.0f * cosine;
    vertices[1][2] = depth;
    vertices[3][0] = (x + (0.0f - halfWidth) * cosine) - -8.0f * sine;
    vertices[3][1] = (y + (0.0f - halfWidth) * sine) + -8.0f * cosine;
    vertices[3][2] = depth;
    vertices[2][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - -8.0f * sine;
    vertices[2][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + -8.0f * cosine;
    vertices[2][2] = depth;
    vertices[0][8] = 27.0f;
    vertices[0][9] = 27.0f;
    vertices[0][10] = 27.0f;
    vertices[0][11] = 255.0f;
    vertices[1][8] = 27.0f;
    vertices[1][9] = 27.0f;
    vertices[1][10] = 27.0f;
    vertices[1][11] = 255.0f;
    vertices[2][8] = 27.0f;
    vertices[2][9] = 27.0f;
    vertices[2][10] = 27.0f;
    vertices[2][11] = 255.0f;
    vertices[3][8] = 27.0f;
    vertices[3][9] = 27.0f;
    vertices[3][10] = 27.0f;
    vertices[3][11] = 255.0f;
    vertices[0][6] = reciprocal;
    vertices[1][6] = reciprocal;
    vertices[2][6] = reciprocal;
    vertices[3][6] = reciprocal;
    func_00364c50();
    D_00887310[0](4, vertices, 4);
    func_00364c70();
    if (extend != 0) {
        D_00887300[0](8, 1);
        vertices[0][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - 0.0f * sine;
        vertices[0][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + 0.0f * cosine;
        vertices[1][0] = (0.0f + (x + (0.0f - halfWidth) * cosine)) - 0.0f * sine;
        vertices[1][1] = (0.0f + (y + (0.0f - halfWidth) * sine)) + 0.0f * cosine;
        vertices[3][0] = (x + (0.0f - halfWidth) * cosine) - -800.0f * sine;
        vertices[3][1] = (y + (0.0f - halfWidth) * sine) + -800.0f * cosine;
        vertices[2][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - -800.0f * sine;
        vertices[2][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + -800.0f * cosine;
        vertices[0][8] = 27.0f;
        vertices[0][9] = 27.0f;
        vertices[0][10] = 27.0f;
        vertices[0][11] = 0.0f;
        vertices[1][8] = 27.0f;
        vertices[1][9] = 27.0f;
        vertices[1][10] = 27.0f;
        vertices[1][11] = 0.0f;
        vertices[2][8] = 27.0f;
        vertices[2][9] = 27.0f;
        vertices[2][10] = 27.0f;
        vertices[2][11] = 0.0f;
        vertices[3][8] = 27.0f;
        vertices[3][9] = 27.0f;
        vertices[3][10] = 27.0f;
        vertices[3][11] = 0.0f;
        D_00887310[0](4, vertices, 4);
        D_00887300[0](8, 0);
    }
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204dc0);
#endif
/* measured: object 1100B/window 1120B/normalized_diff 614 (206 differing words fndiff, fnalign 275/278 3-short 106e+18 reloc; baseline parked 617/208/115e). Best type_u16_temp17 (s32 temp_17->u16 temp_17 single-line, -2w/-3B/-9e). */
/* measured: dead-arm head/lo/lo2/21 redundant-store shapes all neutral DCE (208w); slti inclusive, <1U/<2U, s16-cast, loopinv, schedule, s64, commsub, u16-narrowing (owner-edit N/A), adjacent-OR (no ||/-1), COP2 (N/A), index-mask/CSE (no andi-CSE/frame diff) all tried per checklist; remaining Path2 CSE + preheader + second-loop hoist + displacement cascade walls. No volatile/asm. Staged /tmp/push_205170_full.c via NearGA.Dead205170. */
/* measured 00205170: `opt_common_subs off` inside the guard is worth 2 words (206 -> 204); retail rematerialises what b210 hoists. */
// FUN_00205170 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_00205170(u8 *arg0, s32 arg1, f32 fx, f32 fy, s32 arg2, s32 arg3, s32 arg4) {
    extern u32 func_00452560(void *arg0);
    extern s32 func_0023ddc0(u8 *arg0, s32 arg1);
    extern u32 func_0023d9b0(u8 *arg0, s32 arg1);
    extern s32 func_0023dd90(u8 *arg0, s32 arg1);
    extern void func_00114dc0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fx);
    extern void func_002bc860(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 fx, f32 fy, f32 fz);
    f32 spB0;
    f32 spB4;
    u8 spBC;
    u8 spBD;
    u8 spBE;
    u8 spBF;
    s8 var_16;
    u16 temp_17;
    u8 *temp_18;
    u8 *temp_19;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2;
    s32 temp_lo;
    s32 temp_lo_2;
    f32 temp_f20;
    f32 temp_f23;
    f32 temp_f24;

    temp_19 = (u8 *)func_00452560(*(void **)(arg0 + 0x5B0));
    temp_18 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x178) + 0x30) + 0xA64);
    temp_17 = *(u16 *)(arg0 + arg1 * 2 + 0x194);
    if (temp_17 >= 0x1B8 || func_0023ddc0(temp_18, temp_17 & 0xFFFF) != 0) {
        if (arg3 != 0) {
            var_16 = 0x6E;
        } else {
            var_16 = 0x96;
        }
    } else if (arg3 != 0) {
        var_16 = 0x1B;
    } else {
        var_16 = 0xFF;
    }
    spB0 = fx;
    spB4 = fy;
    spBC = var_16;
    spBD = var_16;
    spBE = var_16;
    spBF = arg2;
    func_00114dc0((s32)(*(s64 *)&spB0), *(s32 *)&spBC, temp_17 & 0xFFFF, *(u8 **)(temp_19 + 0x60), 50.0f);
    func_00272c60(0x40);
    temp_22 = arg2 & 0xFF;
    temp_f20 = 42.0f + fx;
    temp_2 = (u8)var_16;
    func_00275020(temp_f20, (2.0f + fy) - 1.0f, 50.0f,
                  temp_22 | (((temp_2 << 24) | (temp_2 << 16)) | (((u8)var_16) << 8)),
                  0, 1, (const char *)D_00887300 + temp_17 * 0x13, 0, -1);
    func_00272c80(0x40);
    if (temp_17 < 0x1B8) {
        temp_21 = func_0023d9b0(temp_18, temp_17 & 0xFFFF);
        if (temp_21 != 0) {
            temp_f24 = 10.0f + fy;
            temp_f23 = 262.0f + fx;
            func_00201650(temp_19, 0xC, (temp_21 % 10) + 9, 32.0f + temp_f23, temp_f24, var_16, var_16, var_16, arg2);
            temp_lo = temp_21 / 10;
            if (temp_lo != 0) {
                func_00201650(temp_19, 0xC, (temp_lo % 10) + 9, 16.0f + temp_f23, temp_f24, var_16, var_16, var_16, arg2);
            }
            temp_lo_2 = temp_21 / 100;
            if (temp_lo_2 != 0) {
                func_00201650(temp_19, 0xC, (temp_lo_2 % 10) + 9, temp_f23, temp_f24, var_16, var_16, var_16, arg2);
            }
            if ((func_0023dd90(temp_18, temp_17 & 0xFFFF) & 0xFFFF) == 1) {
                func_00201650(temp_19, 0xC, 0x56, 310.0f + fx, 12.0f + fy, var_16, var_16, var_16, arg2);
            } else {
                func_00201650(temp_19, 0xC, 0x57, 310.0f + fx, 12.0f + fy, var_16, var_16, var_16, arg2);
            }
        }
    }
    if (arg4 != 0) {
        func_00272c60(0x40);
        func_002bc860(temp_22 | -0x100, 1, 0, temp_17, 10.0f + (2.0f + temp_f20), 36.0f + fy, 0.0f);
        func_00272c80(0x40);
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205170);
#endif

/* 888/896 bytes; twelve resolved relocations and eight zero alignment bytes.
 * Narrow the promoted row ID at helper boundaries. The four-byte color
 * has byte and packed-word views; reload the signed number after drawing. */
#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_002055D0
void func_002055d0(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 show_detail)
{
    extern u32 func_00452560(void *task);
    extern void func_00113280(Vec2f arg0, f32 fparg0, s32 arg1,
                              s16 arg2, s32 arg3, s32 arg4);
    extern void func_002bc4b0(s32 arg0, s32 arg1, s32 arg2, f32 fparg0,
                              s32 arg3, s32 arg4, s32 arg5);
    u8 *glyphs;
    u8 tone;
    s32 off;
    s32 id;
    s32 digit;
    s32 masked;
    s32 tens;
    s32 radix;
    f32 digit_y;
    f32 digit_x;
    f32 fx;
    const char *name;
    Vec2f pos;
    union {
        Color4 bytes;
        s32 word;
    } color;

    glyphs = (u8 *)func_00452560(*(void **)(work + 0x5B0));
    off = slot * 4;
    id = *(s16 *)(p4_002091f0_add((u32)off, work) + 0x1A6);
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    pos.x = x;
    pos.y = y;
    color.bytes.c0 = tone;
    color.bytes.c1 = tone;
    color.bytes.c2 = tone;
    color.bytes.c3 = opacity;
    func_00113280(pos, 50.0f, color.word, id,
                  *(s32 *)(glyphs + 0x5C), *(s32 *)(glyphs + 0x60));
    func_00272c60(0x40);
    masked = opacity & 0xFF;
    fx = 42.0f + x;
    name = (const char *)func_001067f0(id);
    {
        f32 text_y = (2.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        func_00275020(fx, text_y, depth,
                      (high << 24) | (high << 16) |
                          ((u32)(u8)tone << 8) | masked,
                      0, 1, name, 0, -1);
    }
    func_00272c80(0x40);
    func_00201650(glyphs, 0xC, 0x47, (374.0f + x) - 97.0f,
                  (157.0f + y) - 145.0f, tone, tone, tone, opacity);
    digit = *(s8 *)(p4_002091f0_add((u32)off, work) + 0x1A8);
    digit_y = (155.0f + y) - 145.0f;
    digit_x = (398.0f + x) - 97.0f;
    func_00201650(glyphs, 0xC, (digit % 10) + 9, 16.0f + digit_x,
                  digit_y, tone, tone, tone, opacity);
    radix = 10;
    tens = digit / radix;
    if (tens != 0) {
        func_00201650(glyphs, 0xC, (tens % radix) + 9, digit_x, digit_y,
                      tone, tone, tone, opacity);
    }
    if (show_detail != 0) {
        func_00272c60(0x40);
        func_002bc4b0((s16)id, (s32)(10.0f + ((2.0f + fx) - 1.0f)),
                      (s32)(36.0f + y), 0.0f, masked | ~0xFF, 1, 0);
        func_00272c80(0x40);
    }
}
#pragma pop
/* 712/720 bytes; twelve resolved relocations; eight zero alignment bytes.
 * Keep the shared decimal divisor and the branch-local byte tones. */
#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00205950
void func_00205950(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted)
{
    extern u32 func_00452560(void *task);
    u8 *glyphs;
    u8 *persona;
    u8 tone;
    s32 level;
    s32 tens;
    s32 radix;
    f32 digit_y;
    f32 digit_x;
    const char *name;

    glyphs = (u8 *)func_00452560(*(void **)(work + 0x5B0));
    persona = func_0010ace0((s16)slot);
    if (slot == (s16)func_0010b510()) {
        func_00201650(glyphs, 13, 0x2B, -11.0f + x, 6.0f + y,
                      0xF3, 0, 0xB, opacity);
        if (highlighted != 0) {
            tone = 0x6E;
        } else {
            tone = 0x96;
        }
    } else if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    func_00201650(glyphs, 13, 0x2A, 33.0f + x, 12.0f + y,
                  tone, tone, tone, opacity);
    level = (u8)func_00109390(persona);
    digit_y = 5.0f + y;
    digit_x = 63.0f + x;
    func_00201650(glyphs, 13, level % 10 + 0x1D, 22.0f + digit_x,
                  digit_y, tone, tone, tone, opacity);
    radix = 10;
    tens = level / radix;
    if (tens != 0) {
        func_00201650(glyphs, 13, tens % radix + 0x1D, digit_x,
                      digit_y, tone, tone, tone, opacity);
    }
    func_00272c60(0x40);
    name = (const char *)func_00109220(*(u16 *)(persona + 2));
    {
        f32 text_x = 151.0f + x;
        f32 text_y = (4.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        func_00275020(
            text_x, text_y, depth,
            (high << 24) | (high << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
            0, 1, name, 0, -1);
    }
    func_00272c80(0x40);
}
#pragma pop
extern s16 func_00105f00(s16 arg0);
extern u32 func_0010d6d0(s16 arg0);
/* 468/480 bytes; eight resolved relocations; twelve zero alignment bytes.
 * Keep branch-local tones and the two-channel cache after text coordinates. */
#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00205C20
void func_00205c20(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted)
{
    extern u32 func_00452560(void *task);
    u8 *glyphs;
    u8 *persona;
    u8 tone;
    const char *name;

    glyphs = (u8 *)func_00452560(*(void **)(work + 0x5B0));
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    persona = ((u8 **)(work + 0x17C))[slot];
    func_00272c60(0x40);
    name = (const char *)func_0010d6d0(*(s16 *)(persona + 0xA4));
    {
        f32 text_x = 1.0f + x;
        f32 text_y = (19.0f + y) - 3.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        func_00274ed0(
            text_x, text_y, depth,
            (high << 24) | (high << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
            0, 1, name, 0, 0);
    }
    func_00272c80(0x40);
    func_00201650(glyphs, 9, 0x3C, 155.0f + x,
                  24.0f + y, tone, tone, tone, opacity);
    func_00201650(
        glyphs, 9, func_00105f00(*(s16 *)(persona + 0xA4)) + 0x3F,
        178.0f + x, 16.0f + y, tone, tone, tone,
        opacity);
}
#pragma pop
extern s32 func_002791f0(f32 x, f32 y, f32 scale, s32 color, s32 mode,
                         s32 style, s32 flags, s32 handle, s32 index);
/* 488/496 bytes; seven resolved relocations; eight zero alignment bytes.
 * Preserve the two narrow tone assignments instead of rebuilding a merge. */
#pragma push
#pragma opt_rebuildconditionals off
// FUN_00205E00
void func_00205e00(u8 *panel, s32 index, f32 x, f32 y,
                   u8 opacity, s32 selected, s32 draw_text)
{
    u8 *work;
    u8 color;
    f32 line_y;

    work = (u8 *)func_00452560(*(void **)(panel + 0x5B0));
    if (selected != 0) color = 0x1B;
    else color = 0xFF;
    line_y = 8.0f + y;
    func_00201650(work, 9, 0x3C, 48.0f + x, line_y, color, color, color, opacity);
    func_00201650(work, 9, 0x3C, 270.0f + x, line_y, color, color, color, opacity);
    func_00201650(work, 9, (s32)((u32)index + 0x3FU), 71.0f + x, y,
                  color, color, color, opacity);
    if (draw_text != 0) {
        func_00272c60(0x40);
        func_002791f0(10.0f + (2.0f + (42.0f + x) - 1.0f), 36.0f + y, 0.0f,
                      (s32)(0xFFFFFF00U | (u8)opacity), 1, 0, 0,
                      *(s32 *)(work + 0x98), index);
        func_00272c80(0x40);
    }
}
#pragma pop
// FUN_00205FF0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205ff0);
/* measured: object 868B/window 880B/normalized_diff 291 (85 differing words, live re-measured current tree). */
/* measured: entry tall-branch plus callback-arg setup floor; slti-at, dead-store trailing-arm, arg-cast audit, loop-invariant and schedule levers checked top-down via fnalign with no gain over current 85-word body; full-size (868 vs 880, minus 1pt) floor. */
// FUN_00206DD0 NONMATCHING
#ifdef NON_MATCHING
/* lane W42c20 probe for func_00206dd0 (0x00206dd0)
 * measured: obj 868B, window 880B, differing words 88 (fndiff)
 * levers tried: explicit clamping, (2.0f * f) - (f * f) to trigger mula/msub,
 *   base = D_00887300, s32[4] pos with bit-pattern values, Color4 byte writes.
 * Remaining differences: D_00887300 base register/relocation handling
 *   and prologue saved-register copy order for s2 vs f20/f21.
 */

void func_00206dd0(u8 *arg0, u8 *arg1, void (*arg2)(u8 *, s16, s8, s32, s32, f32, f32), f32 fparg0, f32 fparg1)
{
    u8 *temp_2;
    f32 var_f0;
    f32 var_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 pos[4];
    Color4 color;
    void (**base)(u32, u32);

    temp_2 = (u8 *)func_00452560(*(s32 *)(arg0 + 0x5B0));
    func_002012d0(temp_2, fparg0, fparg1);

    var_f0 = (f32)(*(s16 *)(arg0 + 0x1A)) / 4.0f;
    if (var_f0 > 1.0f) {
        var_f1 = 1.0f;
    } else if (var_f0 < 0.0f) {
        var_f1 = 0.0f;
    } else {
        var_f1 = var_f0;
    }

    temp_f20 = (2.0f * var_f1) - (var_f1 * var_f1);
    if (temp_f20 <= 0.0f) {
        return;
    }

    base = D_00887300;
    base[0](8, 1);

    if (temp_f20 < 1.0f) {
        base[0](1, 0);

        color.c0 = 0;
        color.c1 = 0;
        color.c2 = 0xFF;
        color.c3 = 0;
        pos[0] = 0x6E;
        pos[1] = 0x14D;
        pos[2] = 0x17C;
        pos[3] = 0x25;
        func_0045d6e0((u8 *)&color, (f32 *)pos, 0.0f, 0);
    }

    func_002019e0(temp_2, 170.0f);
    func_00201720(temp_2, 1.0f, temp_f20);

    temp_f20_2 = (f32)0x14D + (18.5f * (1.0f - temp_f20));
    func_00201410(temp_2, 9, 0x30, 110.0f, temp_f20_2);
    func_00201410(temp_2, 9, 0x31, 470.0f, temp_f20_2);

    func_00201720(temp_2, 1.0f, 1.0f);
    base[0](8, 0);
    func_002019e0(temp_2, 150.0f);
    base[0](6, 1);
    arg2(arg0, *(s16 *)(arg1 + 4), 0xFF, 0, 0, 127.0f, 338.0f);
    base[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    func_00201410(temp_2, 9, 0x32, 215.0f, 412.0f);
    func_00201410(temp_2, 9, 0x33, 193.0f, 412.0f);
    func_00201410(temp_2, 9, 0x33, (f32)0x19D, 412.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00206dd0);
#endif

extern s32 func_00106600(s16 id);
extern u16 *func_0010a900(s32 id);
extern u16 func_0010cf40(u8 *persona, s16 slot);
extern s32 func_00232aa0(s32 id);
extern u8 *iGpffffb3b8;

typedef struct {
    s16 id;
    u8 quantity;
    u8 reserved;
} BattleListItem;

typedef struct {
    u8 prefix[0x194];
    u16 skills[8];
    u16 skillCount;
    BattleListItem items[256];
    u16 itemCount;
} BattleListWork;

/* 472/480 bytes; eight resolved relocations; eight zero alignment bytes.
 * Store each accepted signed item ID before its second quantity query. */
// FUN_00207140
void func_00207140(u16 *flags, u8 *work)
{
    u8 *action;
    u8 *unit;
    u8 *persona;
    u16 skillSlot;
    u16 skillCount;
    u16 skill;
    u16 itemCount;
    u16 itemSlot;

    if (func_00106330(0x3C) != 0) {
        action = *(u8 **)(*(u8 **)(work + 0x178) + 0x3F0);
        if (action != NULL) {
            func_00202d20((u8 *)flags, *(s16 *)(action + 2), *(s16 *)action);
        }
    }
    *flags |= 4;
    *flags |= 2;
    skillCount = 0;
    unit = *(u8 **)(*(u8 **)(work + 0x178) + 0x30);
    if (unit[0xA2] == 0) {
        persona = (u8 *)func_0010a900(*(u16 *)(unit + 0xA4));
        for (skillSlot = 0; skillSlot < 8; skillSlot++) {
            skill = func_0010cf40(persona, (s16)skillSlot);
            if (skill != 0 && skill < 0x1B8 && (*(u8 *)(skill * 0x28 + iGpffffb3b8 + 1) & 2)) {
                *(u16 *)(work + skillCount * 2 + 0x194) = skill;
                skillCount++;
            }
        }
    }
    *(u16 *)(work + 0x1A4) = skillCount;
    itemCount = 0;
    for (itemSlot = 0; itemSlot < 0x100; itemSlot++) {
        if (func_00106600((s16)(itemSlot + 0x300)) != 0 &&
            func_00232aa0((u16)(itemSlot + 0x300)) != 0) {
            ((BattleListWork *)work)->items[itemCount].id = itemSlot + 0x300;
            ((BattleListWork *)work)->items[itemCount].quantity = func_00106600((s16)(itemSlot + 0x300));
            itemCount++;
        }
    }
    *(u16 *)(work + 0x5A6) = itemCount;
}
/* Floor: 310 differing words, 505 emitted instructions against retail's 504,
   from a first reconstruction (no prior body).  What the retail stream
   dictated: the outer dispatch is an if/else-if chain, not a switch - each
   arm's body sits inline behind its own `bne` and the 1/5/6 arms fall
   through to a single `return 1` - while the inner dispatch on
   *(s16 *)(arg0 + 4) is a real jump table whose 3/7/2/0 arms break to one
   shared `return 4`.  Writing those arms as `return 4` costs a word each.
   func_001f0620 takes two arguments, not the six m2c prints; retail simply
   reuses the compare constants still sitting in $a1/$a3.  The list counter
   is 32-bit with an explicit `& 0xFFFF`, which gives retail's `andi` pair
   instead of the dsll32/dsra32 that a s16 counter emits.
   WALL: saved-register rotation.  Retail numbers them arg1=$s0, arg2=$s1,
   arg0=$s2 - the order their live ranges end, longest last - and this
   build numbers arg1=$s1, arg0=$s0.  250 declaration orders, all pragmas,
   and local aliases for both pointer parameters (MWCC coalesces the copy)
   were measured; the only other difference is the 0x18C store scheduling
   one instruction later than retail's; `opt_loop_invariants on` is worth
   one word here, which does not pay for a non-baseline pragma. */
/* measured 00207320: `opt_loop_invariants on` inside the guard is worth 1 words (311 -> 310), the loop-preheader constant hoist. */
// FUN_00207320 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_00207320(u8 *arg0, u8 *arg1, u8 **arg2)
{
    extern s32 func_001f0620(u8 *arg0, s32 arg1);
    extern void func_001f56d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u32 func_001ef720(s32 arg0, s32 arg1);
    extern s16 func_0023dfe0(s32 arg0);
    extern s32 func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s8 func_0010b6f0(void);
    extern void func_00202c60(u8 *arg0, s32 arg1, s16 arg2, void *a, void *b, void *c, void *d, u8 *arg7);
    extern void func_00202e60(u8 *arg0, void *arg1);
    extern void func_002019f0(u8 *arg0, s32 arg1);
    extern void func_00208a50(void);
    extern void func_00208b00(void);
    extern void func_00208d00(void);
    extern void func_00208fd0(void);
    extern void func_002090d0(void);
    extern void func_00209140(void);
    extern void func_002091f0(void);
    extern void func_00209370(void);
    extern void func_00209640(void);
    extern void func_00209740(void);
    extern void func_002097b0(void);
    extern void func_00209870(void);
    extern void func_002099c0(void);
    extern void func_00209bc0(void);
    extern void func_00209cd0(void);
    extern void func_0020a5d0(void);
    extern void func_0020a640(void);
    extern void func_0020aa70(void);
    extern void func_0020ac70(void);
    extern void func_0020ad70(void);
    u8 *panel;
    u8 *entry;
    u8 *ui;
    s32 mode;
    s16 sub;
    s16 n;
    s32 count;

    if (*(s16 *)(func_00452560(*(s32 *)(arg1 + 0x5B0)) + 0xAA) < 2) {
        return 1;
    }
    if (*(s16 *)(arg1 + 0x14) != 0) {
        return 1;
    }
    mode = func_00202e70(arg0) & 0xFFFF;
    if (mode == 1) {
    if (*(s16 *)(arg0 + 4) != 3) {
        func_0045af60(0, 0, 0, 2);
    }
    *(s16 *)(arg0 + 4) = 3;
    *(s16 *)(arg0 + 2) = 0;
    } else if (mode == 4) {
    if (func_001f0620(*(u8 **)(arg1 + 0x178), 0xA) == 0) {
        return 1;
    }
    func_0045af60(0, 0, 0, 3);
    *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 0xA;
    if (func_00106330(0x38) != 0) {
        sub = 0x10B;
    } else {
        sub = 0x110;
    }
    *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = sub;
    return 4;
    } else if (mode == 5) {
    *(s16 *)(arg1 + 0x14) = -3;
    } else if (mode == 6) {
    *(s16 *)(arg1 + 0x14) = 3;
    } else if (mode == 2) {
    switch (*(s16 *)(arg0 + 4)) {
    case 3:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 1) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 1;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) =
            func_0023dfe0(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64));
        break;
    case 4:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 2) == 0) {
            if (func_00232710(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64), 8) != 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x90);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_0010a900(*(u16 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA4));
        func_00202c60(arg1 + 0x74, 4, *(s16 *)(arg1 + 0x1A4), func_00208a50,
                      func_00208b00, func_00208d00, func_002090d0, arg1);
        panel = arg1 + 0x74;
        *arg2 = panel;
        func_00202e60(panel, func_00208fd0);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 6:
        n = *(s16 *)(arg1 + 0x5A6);
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 3) == 0 || n == 0) {
            if (*(s16 *)(arg1 + 0x5A6) == 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x92);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_00202c60(arg1 + 0xA8, 4, n, func_00209140, func_002091f0,
                      func_00209370, func_00209740, arg1);
        panel = arg1 + 0xA8;
        *arg2 = panel;
        func_00202e60(panel, func_00209640);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 1:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 4) == 0) {
            if ((func_001ef720(1, 0) & 0xFFFF) < 2) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x93);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        count = 0;
        for (ui = *(u8 **)(iGpffffb3ac + 0x17C); ui != NULL; ui = *(u8 **)(ui + 0xA68)) {
            if (*(u16 *)(ui + 0xA4) != 1) {
                *(u8 **)(arg1 + (count & 0xFFFF) * 4 + 0x17C) = ui;
                count = (count + 1) & 0xFFFF;
            }
        }
        *(s16 *)(arg1 + 0x18C) = count;
        func_00202c60(arg1 + 0xDC, 3, (s16)count, func_002097b0, func_00209870,
                      func_002099c0, func_00209cd0, arg1);
        panel = arg1 + 0xDC;
        *arg2 = panel;
        func_00202e60(panel, func_00209bc0);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 5:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 5) == 0) {
            if (func_00232710(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64), 8) != 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x91);
            } else {
                entry = *(u8 **)(arg1 + 0x178);
                if (!(*(u16 *)(entry + 0x18) & 0x400)) {
                    func_002019f0(*(u8 **)(entry + 0x30), 0x95);
                }
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s32 *)(arg1 + 0x5A8) = func_00117780(*(s32 *)(arg1 + 0x5B0), 0xF, 1, 8, 8);
        *(s16 *)(arg1 + 0x5AC) = -1;
        func_00202c60(arg1 + 0x144, 4, (s16)func_0010b6f0(), func_0020a5d0,
                      func_0020a640, func_0020aa70, func_0020ad70, arg1);
        panel = arg1 + 0x144;
        *arg2 = panel;
        func_00202e60(panel, func_0020ac70);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 7:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 6) == 0) {
            func_001f56d0(*(u8 **)(arg1 + 0x178), 5, 0, 0, 2);
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 6;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = 0;
        break;
    case 2:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 7) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 7;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = 0;
        break;
    case 0:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 0xA) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 0xA;
        if (func_00106330(0x38) != 0) {
            sub = 0x10B;
        } else {
            sub = 0x110;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = sub;
        break;
    default:
        break;
    }
    return 4;
    }
    return 1;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207320);
#endif
// FUN_00207B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207b00);
/* measured: the float argument to func_0045d6e0 is 0.0f - retail only ever clears
   $f12, and that hoisted zero is also the `<= 0.0f` compare operand and the
   accumulator seed of the adda.s/madd.s (the old archive passed temp_f4, nd10). */
// FUN_00208870
void func_00208870(u8 *unused, u8 *arg1, f32 *arg2)
{
    s32 values[4];
    Color4 color;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f4;

    func_002012d0((u8 *)func_00452560(*(void **)(arg1 + 0x5B0)), arg2[0], arg2[1]);
    temp_f0 = (f32)*(s16 *)(arg1 + 0xE) / 2.0f;
    if (temp_f0 > 1.0f) {
        temp_f1 = 1.0f;
    } else if (temp_f0 < 0.0f) {
        temp_f1 = 0.0f;
    } else {
        temp_f1 = temp_f0;
    }
    temp_f3 = temp_f1 * 2.0f - temp_f1 * temp_f1;
    if (temp_f3 <= 0.0f) {
        return;
    }
    color.c0 = 0xB4;
    color.c1 = 0;
    color.c2 = 0;
    color.c3 = 0xFF;
    values[0] = -10;
    temp_f4 = (1.0f - temp_f3) * 11.0f + 410.0f;
    values[1] = (s32)temp_f4;
    values[2] = 0x294;
    values[3] = (s32)(temp_f3 * 22.0f);
    func_0045d6e0((u8 *)&color, (f32 *)values, 0.0f, 0);
}
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
/* 500/512 bytes; twelve zero alignment bytes.
 * The shared four-byte record type preserves the flags-table load order. */
// FUN_00208B00
u16 func_00208b00(u8 *arg0, u8 *arg1)
{
    extern s32 func_0023ddc0(u8 *arg0, s32 arg1);
    extern s32 func_0023df70(s32 arg0);
    s32 temp_2;
    u16 var_16;
    u16 temp_16;
    s32 idx2;

    var_16 = func_00202e70(arg0) & 0xFFFF;
    switch (var_16) {
    case 2:
        idx2 = (s32)*(s16 *)(arg0 + 4) * 2;
        temp_16 = *(u16 *)(idx2 + (u32)arg1 + 0x194);
        if (func_0023ddc0(*(u8 **)(*(u8 **)(*(u8 **)(arg1 + 0x178) +
                                           0x30) + 0xA64),
                          temp_16) == 0) {
            if ((func_0023df70(temp_16) != 0) &&
                ((iGpffffb3bc[temp_16 & 0xFFFF].flags & 0x8000) == 0)) {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 1;
            } else {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 2;
            }
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = temp_16;
            *(s16 *)(arg1 + 0x1A) = 0;
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            var_16 = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    default:
        var_16 = 1;
        break;
    }
    return var_16;
}
/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * func_002035a0 forwards the signed state word at node+0x28. Convert that
 * real input to a pointer here; a pointer parameter swaps two entry moves. */
// FUN_00208D00
void func_00208d00(u8 *arg0, s32 arg1, f32 *arg2)
{
    extern void func_00206dd0(u8 *arg0, u8 *state, f32 farg0, f32 farg1, void (*callback)(void));
    u8 *state = (u8 *)arg1;
    u8 *temp;
    s16 temp_2;

    temp = (u8 *)func_00452560(*(void **)(state + 0x5B0));
    func_002012d0(temp, arg2[0], arg2[1]);
    if (*(u16 *)state == 2) {
        func_00201650(temp, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        func_00201650(temp, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00206dd0(state, arg0, arg2[0], arg2[1], (void (*)(void))func_00205170);
    } else {
        func_00201650(temp, 9, 0x21, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    func_002019e0(temp, 120.0f);
    func_00201650(temp, 9, 0x37, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    func_002019e0(temp, 0.0f);
    temp_2 = *(s16 *)(state + 0x1A);
    if (temp_2 < 4) {
        *(s16 *)(state + 0x1A) = temp_2 + 1;
    }
    if (func_001eb860() != 0) {
        func_00201650(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        func_00201650(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

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
        func_00205ff0(arg1, arg0, arg2[0], arg2[1], (void (*)(void))func_00205170, arg0);
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

    value = func_00202e70(arg0) & 0xFFFF;
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
/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * func_002035a0 forwards the signed state word at node+0x28. Convert that
 * input locally; preserve the position and callback-table reloads. */
// FUN_00209370
void func_00209370(u8 *arg0, s32 arg1, f32 *arg2)
{
    extern void func_00206dd0(u8 *arg0, u8 *state, f32 farg0, f32 farg1, void (*callback)(void));
    u8 *state = (u8 *)arg1;
    u8 *temp;
    s16 temp_2;

    temp = (u8 *)func_00452560(*(void **)(state + 0x5B0));
    func_002012d0(temp, arg2[0], arg2[1]);
    if (*(u16 *)state == 2) {
        func_00201650(temp, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        func_00201650(temp, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00206dd0(state, arg0, arg2[0], arg2[1], (void (*)(void))func_002055d0);
    } else {
        func_00201650(temp, 9, 0x23, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    func_002019e0(temp, 120.0f);
    func_00201650(temp, 9, 0x39, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    func_002019e0(temp, 0.0f);
    temp_2 = *(s16 *)(state + 0x1A);
    if (temp_2 < 4) {
        *(s16 *)(state + 0x1A) = temp_2 + 1;
    }
    if (func_001eb860() != 0) {
        func_00201650(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        func_00201650(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}
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
        func_00205ff0(arg1, arg0, arg2[0], arg2[1],
                      (void (*)(void))func_002055d0, arg0);
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
u16 func_00209870(u8 *arg0, s32 arg1, u8 **arg2)
{
    u16 temp_4;
    u16 var_2;
    u16 result;
    u8 **out;
    u8 *base;
    u8 *temp_2;
    u8 *temp_4_2;

    out = (u8 **)arg2;
    base = (u8 *)(u32)arg1;
    temp_4 = func_00202e70(arg0) & 0xFFFF;
    switch (temp_4) {
    case 2:
        temp_2 = *(u8 **)(p4_002091f0_add(
            (u32)(*(s16 *)(arg0 + 4) * 4), base) + 0x17C);
        *(u8 **)(base + 0x190) = temp_2;
        if ((func_00107ac0(func_00247cb0(*(s16 *)(temp_2 + 0xA4)) &
                           0xFFFF) & 0xFFFF) >= 0) {
            var_2 = 5;
        } else {
            var_2 = 4;
        }
        func_00202c60(base + 0x110, 4, (s16)var_2,
                      (void *)func_00209d40, (void *)func_00209dc0,
                      (void *)func_00209f90, (void *)func_0020a5c0, base);
        temp_4_2 = base + 0x110;
        *out = temp_4_2;
        func_00202e60(temp_4_2, (void *)func_00209fa0);
        *(s32 *)(base + 4) &= ~4;
        return 3;
    case 1:
        func_0045af60(0, 0, 0, 4);
        result = 2;
        goto done;
    default:
        result = 1;
        goto done;
    }
done:
    return result;
}
// FUN_002099C0
void func_002099c0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    u8 *temp;

    temp = (u8 *)func_00452560(*(void **)(arg1 + 0x5B0));
    func_002012d0(temp, arg2[0], arg2[1]);
    func_00201650(temp, 9, 0x1F, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    func_002019e0(temp, 120.0f);
    func_00201650(temp, 9, 0x35, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    func_002019e0(temp, 0.0f);
    if (func_001eb860() != 0) {
        func_00201650(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        func_00201650(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}
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
u16 func_00209dc0(u8 *arg0, u8 *arg1)
{
    extern s16 func_00105f00(s16 arg0);
    extern void func_00105e30(s16 arg0, s16 arg1);
    extern u8 *func_001b0c80(s32 arg0);
    extern u8 *func_001f99c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3,
                              s32 arg4);
    extern s64 func_00194590(u8 *arg0, u32 arg1);
    s16 temp_16;
    u8 *temp_2;
    s32 temp_2_2;
    s32 temp_3;
    u16 var_16;

    var_16 = func_00202e70(arg0) & 0xFFFF;
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 !=
            func_00105f00(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4))) {
            func_00105e30(
                *(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4), temp_16);
            temp_2 = func_001b0c80(*(s32 *)(arg1 + 0x190));
            if (temp_2 != NULL) {
                func_00194590(
                    func_001f99c0(temp_2, 2, *(s16 *)(arg0 + 4), 0, 0), 1);
            }
        }
        *(s32 *)(arg1 + 4) &= ~4;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
        func_0045af60(0, 15, 0, 1);
        var_16 = 2;
        break;
    case 1:
        temp_3 = *(s32 *)(arg1 + 4);
        if ((temp_3 & 4) != 0) {
            *(s32 *)(arg1 + 4) = temp_3 & ~4;
            var_16 = 1 & 0xFFFF;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    case 3:
        temp_2_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2_2;
        if ((temp_2_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    default:
        var_16 = 1 & 0xFFFF;
        break;
    }
    return var_16;
}
// FUN_00209F90
void func_00209f90(void)
{
}
/* Floor: 219 differing words over 92 edits, 392 emitted against retail's 392 (plus 2 reloc-only); probe a(v3)=300 -> b(block-scope+staged)=219. Levers: nested-block loop counters/pointers, per-statement float staging into s1/s2 temporaries, 5-arg 205ff0 direct-jal via block-scope shadow decl (no extra move a3,s1), isolated MAC idioms (2*c-c*c via mula+msub, 357+0.5*(138-x) via sub+adda+madd, 402-150*x via adda+msub, (u8)f via 2.1e9 check); opt_propagation bracket removed (219->219 without it, not load-bearing). WALL: s-allocation rotation (retail s1=arg0/s0=arg2/s3=arg1/s2=temp vs object s3/s2/s1, temp_2 lands in s1); div.s dest f1 vs f0 with extra mov.s and c.ole/c.olt operand swap; 1.0/2.0 into saved f22/f23 cascading FPU dest rotation; D_00887300 base stays temp (lui $v0+lw vs retail lui $s0+lw) at 3 sites. */
// FUN_00209FA0 NONMATCHING
#ifdef NON_MATCHING
void func_00209fa0(s32 arg0, u8 *arg1, f32 *arg2)
{
    extern u8 *func_00452560(s32 arg0);
    extern void func_00205ff0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, void (*callback)(void));
    extern s32 func_00105f00(s16 arg0);
    extern s32 func_0010d6d0(s16 arg0);
    extern s32 func_002738d0(u8 *arg0);
    extern u8 *func_00274cd0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f0, f32 f1, f32 f2);
    extern void func_00272950(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00273170(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00271b70(u8 *arg0);
    void (**base)(u32, u32);
    Work4 work;
    u8 *temp_2;
    u8 *res;
    f32 f21;
    f32 f20;
    u8 alpha;
    s32 ival;
    s32 sval;
    s32 dval;
    s32 chr;
    temp_2 = func_00452560(*(s32 *)(arg1 + 0x5B0));
    func_002012d0(temp_2, arg2[0], arg2[1]);
    if (*(u16 *)arg1 != 2) {
        func_00205ff0(arg1, (u8 *)arg0, arg2[0], arg2[1], (void (*)(void))func_00205e00);
    }
    {
        s16 ct0;
        s16 ct1;
        s16 ct2;
        s16 ct3;
        s16 ct4;
        s16 ct5;
        ct0 = *(s16 *)(arg1 + 0x20);
        if (ct0 < 4) {
            *(s16 *)(arg1 + 0x20) = ct0 + 1;
        }
        ct1 = *(s16 *)(arg1 + 0x22);
        if (ct1 < 0xA) {
            *(s16 *)(arg1 + 0x22) = ct1 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            ct2 = *(s16 *)(arg1 + 0x16);
            if (ct2 < 4) {
                *(s16 *)(arg1 + 0x16) = ct2 + 1;
            }
            ct3 = *(s16 *)(arg1 + 0x18);
            if (ct3 < 7) {
                *(s16 *)(arg1 + 0x18) = ct3 + 1;
            }
        } else {
            ct4 = *(s16 *)(arg1 + 0x16);
            if (ct4 > 0) {
                *(s16 *)(arg1 + 0x16) = ct4 - 1;
            }
            ct5 = *(s16 *)(arg1 + 0x18);
            if (ct5 > 0) {
                *(s16 *)(arg1 + 0x18) = ct5 - 1;
            }
        }
    }
    {
        f32 c;
        c = (f32)*(s16 *)(arg1 + 0x1C) / 5.0f;
        if (c > 1.0f) {
            c = 1.0f;
        } else if (c < 0.0f) {
            c = 0.0f;
        }
        f21 = 1.0f - (2.0f * c - c * c);
    }
    {
        f32 s1;
        f32 s2;
        f20 = 36.0f * f21;
        s1 = 324.0f + f20;
        s2 = s1;
        func_00201650(temp_2, 9, 0x4E, 491.0f, s2, 0xFE, 0xFF, 0x22, 0xFF);
    }
    if (f21 > 0.0f) {
        base = D_00887300;
        base[0](1, 0);
        base[0](8, 1);
        work.colors.c0 = 0;
        work.colors.c1 = 0;
        work.colors.c2 = 0xFF;
        work.colors.c3 = 0;
        work.value3 = 0x64;
        {
            f32 s1;
            f32 s2;
            s1 = 330.0f + f20;
            s2 = s1 - 40.0f;
            work.value0 = (s32)s2;
        }
        work.value1 = 0x1A4;
        work.value2 = 0x28;
        func_0045d6e0((u8 *)&work.colors, (f32 *)(void *)&work.value3, 0.0f, 0);
        base[0](8, 0);
    }
    base = D_00887300;
    base[0](6, 1);
    func_002019e0(temp_2, 50.0f);
    func_00201650(temp_2, 9, 0x3B, 493.0f, 330.0f, 0x1B, 0x1B, 0x1B, 0xFF);
    chr = (s16)func_00105f00(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4)) + 0x3F;
    func_00201650(temp_2, 9, chr, 168.0f, 334.0f, 0xFE, 0xFF, 0x22, 0xFF);
    func_00272c60(0x40);
    dval = func_0010d6d0(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4));
    res = func_00274cd0(-1, 0, 1, dval, 0, 0, 357.0f, 332.0f, 50.0f);
    sval = func_002738d0(res);
    {
        f32 s1;
        f32 s2;
        f32 s3;
        s1 = (f32)sval;
        s2 = 138.0f - s1;
        s3 = 0.5f * s2;
        s1 = 357.0f + s3;
        s2 = 16.0f * s1;
        ival = (s32)s2;
    }
    func_00272950(res, ival, 0xA60);
    func_00273170(res, 1, 0);
    func_00271b70(res);
    func_00272c80(0x40);
    base[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    {
        f32 c;
        f32 tmp;
        f32 fa;
        f32 fb;
        c = (f32)*(s16 *)(arg1 + 0x1E) / 10.0f;
        if (c > 1.0f) {
            c = 1.0f;
        } else if (c < 0.0f) {
            c = 0.0f;
        }
        tmp = 2.0f * c - c * c;
        fa = 1.0f - tmp;
        fb = 1.0f - fa;
        alpha = (u8)(255.0f * fb);
        func_00201650(temp_2, 9, 0x44, 402.0f - 150.0f * fa, 308.0f, 0xFE, 0xFF, 0x22, alpha);
    }
    {
        s16 ct6;
        s16 ct7;
        ct6 = *(s16 *)(arg1 + 0x1C);
        if (ct6 < 5) {
            *(s16 *)(arg1 + 0x1C) = ct6 + 1;
        }
        ct7 = *(s16 *)(arg1 + 0x1E);
        if (ct7 < 0xA) {
            *(s16 *)(arg1 + 0x1E) = ct7 + 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209fa0);
#endif
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
/* measured: 1064/1072 bytes; 35 independently resolved relocations and eight
   zero alignment bytes. Separate stats/task snapshots preserve the retail
   argument-load order without narrowing the persona lookup return type. */
u16 func_0020a640(u8 *arg0, u8 *arg1)
{
    s16 sp48[4];
    s16 temp_16;
    u8 *temp_2;
    u16 var_16;
    u8 *stats;
    u8 *task;

    var_16 = (u16)(func_00202e70(arg0) & 0xFFFF);
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 != (s16)func_0010b510()) {
            temp_2 = func_0010ace0(temp_16);
            *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 5;
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x74) = *(u16 *)((u8 *)temp_2 + 2);
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;

    case 3:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            if (func_0011ba00(*(u8 **)(arg1 + 0x5A8)) == 0) {
                temp_2 = func_0010ace0(*(s16 *)(arg0 + 4));
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x20000;
                stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                task = *(u8 **)(arg1 + 0x5A8);
                func_0011b480(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                func_0011bb90(*(u8 **)(arg1 + 0x5A8));
                func_00213ca0(*(u8 **)(arg1 + 0x5B0));
                func_0043f9c8(sp48, 0, 8);
                sp48[0] = 4;
                sp48[1] = 8;
                func_00202e00(arg0, sp48);
                *(u16 *)arg0 &= ~2;
                *(u16 *)arg0 &= ~1;
                *(u16 *)arg0 &= ~8;
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            }
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            func_0011c630(*(u8 **)(arg1 + 0x5A8));
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    case 1:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_0011bc70(*(u8 **)(arg1 + 0x5A8));
            *(s16 *)(arg1 + 0x5AC) = -1;
            func_00202e00(arg0, NULL);
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            *(u16 *)arg0 |= 2;
            *(u16 *)arg0 |= 1;
            *(u16 *)arg0 |= 8;
            func_0045af60(0, 0, 0, 4);
            var_16 = 1;
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    default:
        if (*(s16 *)(arg1 + 0x5AC) != -1) {
            if (*(s16 *)(arg1 + 0x5AC) != *(s16 *)(arg0 + 4)) {
                temp_2 = func_0010ace0(*(s16 *)(arg0 + 4));
                if (var_16 == 5) {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c180(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                } else {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c2c0(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                }
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) != 0) {
                func_0011caf0(*(u8 **)(arg1 + 0x5A8));
            }
        }
        var_16 = 1;
        break;
    }

    return var_16;
}
/* 508/512 bytes, 13 resolved relocations, four zero alignment bytes.
 * As in func_002099c0, reuse the consumed position view for the callback
 * table base; each state change still reloads the callback slot.
 */
// FUN_0020AA70
void func_0020aa70(u8 *arg0, u8 *arg1, f32 *arg2)
{
    u8 *temp;

    temp = (u8 *)func_00452560(*(void **)(arg1 + 0x5B0));
    func_002012d0(temp, arg2[0], arg2[1]);
    func_00201650(temp, 9, 0x22, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    func_002019e0(temp, 120.0f);
    func_00201650(temp, 9, 0x38, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    func_002019e0(temp, 0.0f);
    if (func_001eb860() != 0) {
        func_00201650(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        func_00201650(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}
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



/*
 * measured: 968/976 bytes, 11 resolved relocations, eight zero alignment bytes.
 * Preserve the 4,5,0 source case order and all reloads after callbacks.
 */
// FUN_0020ADD0
void func_0020add0(void *arg0)
{
    u8 *state = arg0;
    if (*(u32 *)(state + 4) & 1) {
        if (*(s16 *)(state + 0xA) < 11) ++*(s16 *)(state + 0xA);
    } else {
        if (*(s16 *)(state + 8) < 19) ++*(s16 *)(state + 8);
        if (*(s16 *)(state + 0xA) < 6) ++*(s16 *)(state + 0xA);
        else if (*(s16 *)(state + 0xA) > 6) --*(s16 *)(state + 0xA);
    }
    if (*(s16 *)(state + 0xC) < 4) ++*(s16 *)(state + 0xC);
    if (*(s16 *)(state + 0xE) < 2) ++*(s16 *)(state + 0xE);
    else if (!(*(u32 *)(state + 4) & 2)) {
        *(u32 *)(state + 4) |= 2;
        *(s16 *)(state + 0x10) = 0;
    }
    if (*(u16 *)state == 1 && *(s16 *)(state + 8) == 8) {
        func_0045af60(1, 15, 2, 26);
    }
    if (*(u8 **)(state + 0x38) == state + 0x40) {
        if (*(u16 *)state == 1) {
            if (*(s16 *)(state + 0x12) > 0) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
        }
    } else {
        if (!(*(u32 *)(state + 4) & 1)) {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
            else if (*(s16 *)(state + 0x12) > 3) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 6) ++*(s16 *)(state + 0x12);
        }
    }
    *(u16 *)(state + 2) = *(u16 *)state;
    if (*(u16 *)state == 1 && !(*(u32 *)(iGpffffb3ac + 0xC) & 0x10000)) {
        switch (func_00203420(state + 0x2C) & 0xFFFF) {
        case 4: *(u16 *)state = 2; break;
        case 5: *(u16 *)state = 0; break;
        case 0: break;
        }
        if (*(u8 **)(state + 0x178) != 0 &&
            *(u8 **)(*(u8 **)(state + 0x178) + 0x30) != 0 &&
            *(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64) != 0) {
            f32 pulse;
            if (func_00242930(*(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64))) {
                pulse = func_0044b7b0(fGpffff8478 * fGpffffb478);
                fGpffffb478 += 2.0f;
                if (!(fGpffffb478 < 180.0f)) fGpffffb478 -= 180.0f;
            } else {
                pulse = 0.0f;
                fGpffffb478 = 0.0f;
            }
            state[0x24] = (u8)(150.0f * pulse) + 10;
            state[0x25] = 10;
            state[0x26] = 10;
            state[0x28] = (u8)(160.0f * pulse);
            state[0x29] = 0;
            state[0x2A] = 0;
        }
    }
}
// FUN_0020B1A0
void func_0020b1a0(s32 arg0, u8 *arg1)
{
    extern void func_00203930(u8 *arg0, f32 fparg0, f32 fparg1,
                              u8 arg1, u8 arg2, u8 arg3, s32 arg4);
    u8 *temp_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f12;
    f32 temp_f20;

    temp_2 = (u8 *)func_00452560(*(void **)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                func_00201350();
                temp_f12 = (f32)*(s16 *)(arg1 + 8) / 19.0f;
                if (temp_f12 < 1.0f) {
                    temp_f12 = (temp_f12 * 2.0f -
                                temp_f12 * temp_f12) *
                               1.5f;
                    func_00203930(
                        temp_2, temp_f12, temp_f12,
                        *(u8 *)(arg1 + 0x24), *(u8 *)(arg1 + 0x25),
                        *(u8 *)(arg1 + 0x26), 0x4C);
                }
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    temp_f12 = (f32)(6 - temp_3) / 6.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 = 1.0f -
                                   (temp_f12 * 2.0f -
                                    temp_f12 * temp_f12);
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    temp_f12 = (f32)temp_4 / 5.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 =
                            (temp_f12 * 2.0f -
                             temp_f12 * temp_f12) *
                                0.25f +
                            1.0f;
                    }
                }
                func_00203930(
                    temp_2, temp_f20, temp_f20,
                    *(u8 *)(arg1 + 0x24), *(u8 *)(arg1 + 0x25),
                    *(u8 *)(arg1 + 0x26), 0xFF);
                func_002035a0(arg1 + 0x2C);
            }
        }
    }
}
// FUN_0020B3A0
void func_0020b3a0(s32 arg0, u8 *arg1)
{
    extern void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 arg1);
    extern u8 D_00626BE0[];
    u8 *temp_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f20;

    temp_2 = (u8 *)func_00452560(*(void **)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                func_00201350();
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    if (((f32)(6 - temp_3) / 6.0f) < 1.0f) {
                        temp_f20 = 1.0f -
                            ((f32)(6 - temp_3) / 6.0f * 2.0f -
                             (f32)(6 - temp_3) / 6.0f *
                                 ((f32)(6 - temp_3) / 6.0f));
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    if (((f32)temp_4 / 5.0f) < 1.0f) {
                        temp_f20 =
                            ((f32)temp_4 / 5.0f * 2.0f -
                             (f32)temp_4 / 5.0f *
                                 ((f32)temp_4 / 5.0f)) *
                                0.25f +
                            1.0f;
                    }
                }
                func_00204a30(temp_2, temp_f20, temp_f20);
                if (((*(s32 *)(arg1 + 4) & 2) != 0) &&
                    (*(u16 *)arg1 != 2) &&
                    (*(s16 *)(arg1 + 0xA) < 7)) {
                    func_00204b80(temp_2, 1.0f, 1.0f,
                                  D_00626BE0[*(s16 *)(arg1 + 0x10)]);
                    if ((u32)(s16)(*(s16 *)(arg1 + 0x10) += 1) >= 0x14) {
                        *(s16 *)(arg1 + 0x10) = 0x13;
                    }
                }
                func_00203600(arg1 + 0x2C);
            }
        }
    }
}
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

/* measured: opt_propagation off keeps D_00887300 cached across its callback sequence. */
#pragma opt_propagation off
// FUN_0020B5B0
void func_0020b5b0(s32 arg0, u8 *arg1)
{
    extern void func_0045c870(u8 *arg0, s32 arg1);
    u8 *temp_2;
    void (**base)(u32, u32);
    u8 work[4];

    temp_2 = (u8 *)func_00452560(*(void **)(arg1 + 0x5B0));
    if (((*(u32 *)temp_2 & 1) != 0) &&
        (*(u16 *)arg1 != 0) &&
        (*(s16 *)(arg1 + 0x5AC) == -1)) {
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](1, 0);
        work[0] = 0;
        work[1] = 0;
        work[2] = 0;
        work[3] = 0;
        func_0045c870(work, 0);
    }
}
/* measured: restore opt_propagation after func_0020b5b0. */
#pragma opt_propagation on

// FUN_0020B6D0
extern u32 func_001d8df0(u8 *arg0);
extern u16 *func_0010a900(s32 arg0);
extern s32 func_0010ce10(u8 *arg0, u32 arg1);
extern u16 func_0010f8c0(s32 arg0);
extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
extern s32 func_0023d6e0(s16 arg0);
extern s8 func_00233a90(u8 *arg0, s32 arg1);
extern s32 func_00242800(u8 *arg0, s32 arg1);
extern s32 func_001f0950(s32 arg0, s32 arg1);
extern void func_0020bfc0(u8 *arg0, s16 arg1);
extern void func_0020bfd0(u8 *arg0);

void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3)
{
    u16 spD0;
    u32 spC0;
    u32 spB0;
    u32 spA0;
    u8 *temp_2_3;
    u8 *temp_2;
    s32 temp_2_2;
    s32 var_20;
    s32 var_23;
    s32 var_2;
    s32 var_30;
    u16 var_19;
    s32 temp_18;
    s32 temp_3;
    u16 temp_16;
    u8 *temp_16_2;
    u8 *temp_22;

    temp_2 = (u8 *)func_00452560();
    temp_2_3 = temp_2 + 0x710;
    *(s32 *)(temp_2 + 0x718) = (s32)arg1;
    *(s32 *)(temp_2 + 0x71C) = 0;
    *(u8 **)(temp_2 + 0x720) = arg2;
    *(s16 *)(temp_2 + 0x724) = arg3;
    *(s16 *)(temp_2_3 + 4) = 1;
    *(u8 *)(arg2 + 0x3C) |= 1;
    if ((func_001d8df0(arg2) & 0xFFFF) == 1) {
        *(u16 *)temp_2_3 |= 2;
    } else {
        *(u16 *)temp_2_3 &= 0xFFFD;
    }
    switch (arg3) {
    case 0x110:
    case 0x10B:
        var_30 = 1;
        break;
    default:
        var_30 = 0;
        break;
    }
    var_23 = 0;
    if (arg3 >= 0) {
        if (func_00106330(0x38) != 0) {
            var_2 = 5;
        } else {
            var_2 = 8;
        }
        if (func_0010ce10((u8 *)func_0010a900(var_2 & 0xFFFF), 0x10C) != -1) {
            var_23 = 1;
        }
    }
    spC0 = *(u16 *)(arg2 + 0x38);
    temp_16 = (u16)arg3;
    spB0 = func_0010f8c0(temp_16) & 0xFFFF;
    var_20 = 0;
    spD0 = temp_16 & 0xFFFF;
    goto loop_condition;
loop_body:
    temp_22 = *(u8 **)(arg2 + var_20 * 4);
    temp_16_2 = *(u8 **)(temp_22 + 0x30);
    if (var_30 != 0) {
        var_19 = 3;
    } else {
        var_19 = 0;
        temp_18 = (s16)func_0023d8e0(*(u8 **)(temp_16_2 + 0xA64), spD0);
        temp_2_2 = func_0023d6e0((s64)(s16)temp_18);
        if (!(temp_2_2 & 0xE0001)) {
            if (temp_2_2 & 2) {
                if ((s8)func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x10) > 0) {
                    var_19 = 1;
                }
            } else if (!(temp_2_2 & 0x40) &&
                       (s8)func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x11) > 0) {
                var_19 = 1;
            }
        }
        if ((var_23 != 0) && !(var_19 & 0xFFFF)) {
            spA0 = func_00242800(*(u8 **)(temp_16_2 + 0xA64), temp_18);
            var_2 = (u16)temp_18;
            temp_3 = *(u16 *)(temp_16_2 + 0xA4);
            if (func_001f0950(temp_3, var_2) != 0) {
                if ((spA0 & 0x02000000) != 0) {
                    var_19 = 1;
                } else if ((spA0 & 0x05000000) != 0) {
                    var_19 = 2;
                }
            }
        }
    }
    func_0020bfc0(*(u8 **)(temp_22 + 0x30) + 0xA48, (s16)var_19);
    if (spB0 != 0) {
        func_0020bfd0(*(u8 **)(temp_22 + 0x30) + 0xA48);
    }
    var_20 += 1;
loop_condition:
    if (var_20 < (s32)spC0) {
        goto loop_body;
    }
    *(s16 *)(temp_2_3 + 2) = 0;
}

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



extern u16 func_0010f8c0(s32 arg0);
extern s32 func_0019f0f0(u8 *arg0);
extern void func_001d8010(u8 *arg0, u8 *arg1);
extern void func_00216ca0(s32 task);
extern void func_00216d40(s32 task);
extern void func_00216d70(u8 *task, s32 arg1);
extern void func_0020bfd0(u8 *arg0);
extern void func_0020e1d0(u8 *arg0, u8 *arg1);
extern u16 D_008C024E[];
/* 512/512 bytes; seventeen fully resolved relocations.
 * The transition helpers explicitly forward their task to its work getter. */
// FUN_0020BB70
void func_0020bb70(u8 *arg0)
{
    u8 *selected;
    if (*(u16 *)(arg0 + 2) == 0) {
        if ((*(u16 *)arg0 & 1) == 0) {
            if (*(u16 *)(arg0 + 4) > 0) {
                --*(u16 *)(arg0 + 4);
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                func_00216ca0(*(s32 *)(arg0 + 0x18));
                *(u16 *)(arg0 + 2) = 2;
            } else if (D_008C024E[0] & 0x40) {
                func_00216ca0(*(s32 *)(arg0 + 0x18));
                *(u16 *)(arg0 + 2) = 1;
            } else {
                func_001d8010(*(u8 **)(arg0 + 8), *(u8 **)(arg0 + 0x10));
                if (*(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) & 1) {
                    if ((u16)func_0010f8c0(*(u16 *)(arg0 + 0x14)) == 0) {
                        selected = (u8 *)func_001d8bc0(*(u8 **)(arg0 + 0x10));
                        func_00216b40(*(s32 *)(arg0 + 0x18), func_0019f0f0(*(u8 **)(selected + 0x30)));
                        func_00216c40(*(s32 *)(arg0 + 0x18), -1);
                        func_00216d40(*(s32 *)(arg0 + 0x18));
                        func_00216d70(*(u8 **)(arg0 + 0x18), *(s32 *)(selected + 0x30));
                        if (*(u8 **)(arg0 + 0xC) == NULL) {
                            func_0020bfd0(*(u8 **)(selected + 0x30) + 0xA48);
                        } else if (*(u8 **)(arg0 + 0xC) != selected) {
                            func_0045af60(0, 0, 0, 0);
                            func_0020e1d0(*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x30) + 0xA48, *(u8 **)(selected + 0x30) + 0xA48);
                        }
                        *(u8 **)(arg0 + 0xC) = selected;
                    }
                    *(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) &= 0xFE;
                }
            }
        } else {
            func_00216ca0(*(s32 *)(arg0 + 0x18));
            *(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) |= 1;
        }
    }
}
// FUN_0020BD70
void func_0020bd70(u8 *arg0, u8 *arg1)
{
    typedef struct {
        u8 pad[8];
        f32 sp48[2];
        f32 sp50[2];
    } Frame;
    extern u32 func_00452560(void *arg0);
    extern void func_00201350(void);
    extern u8 *func_001b1560(void);
    extern void func_00195d50(u8 *arg0, f32 *arg1);
    extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                               s32 arg8);
    extern void func_00201820(s32 arg0);
    extern void func_0020e010(s32 arg0, u8 *arg1, u8 *arg2);
    Frame frame;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_6;
    u16 temp_4;
    s32 temp_16;
    s32 var_17;

    temp_2 = (u8 *)func_00452560(*(u8 **)(arg1 + 0x18));
    if ((*(u32 *)temp_2 & 1) != 0) {
        if ((*(u16 *)arg1 & 1) == 0) {
            temp_4 = *(u16 *)(arg1 + 2);
            if ((temp_4 != 3) && (*(u16 *)(arg1 + 4) <= 0)) {
                func_00201350();
                temp_16 = *(u16 *)(*(u8 **)(arg1 + 0x10) + 0x38);
                var_17 = 0;
                while (var_17 < (s32)temp_16) {
                    temp_6 = *(u8 **)(*(u8 **)(*(u8 **)(arg1 + 0x10) +
                                              var_17 * 4) +
                                      0x30);
                    func_0020e010(*(s32 *)(arg1 + 0x18), temp_6 + 0xA48,
                                  temp_6);
                    var_17 += 1;
                }
            }
        } else {
            temp_2_2 = func_001b1560();
            if (temp_2_2 != NULL) {
                func_00195d50(*(u8 **)(temp_2_2 + 0x30), frame.sp50);
                if (func_001ec4a0(frame.sp50, frame.sp48) != 0) {
                    func_002012d0(temp_2, frame.sp48[0] - 46.0f,
                                  frame.sp48[1] - 17.0f);
                    func_00201820(2);
                    func_00201650(temp_2, 10, 0x51, 0.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    func_00201650(temp_2, 10, 0x52, 84.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    func_00201820(0);
                    func_00201650(temp_2, 10, 0x4F, 14.0f, 2.0f,
                                  0x0D, 0x1B, 0, 0xFF);
                }
            }
        }
    }
}
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

    temp_16 = (u8 *)func_00452560();
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
void func_0020e250(u8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, u16 arg4)
{
    u8 *state;
    u8 **list;
    u8 *node;
    u8 *new_node;
    u8 *allocated;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;

    state = (u8 *)func_00452560(arg0);
    list = (u8 **)(state + 0x75C);
    if (*(s32 *)arg2 != 0 || *(s32 *)(arg2 + 1) != 0 ||
        *(u16 *)((u8 *)arg2 + 8) != 0) {
        func_0044ea90(&D_00626C30, 0x3A);
        allocated = (u8 *)jtbl_008873E8[0](0x28, 0x40000);
        new_node = allocated;
        temp_f2 = arg3[0];
        temp_f1 = arg3[1];
        temp_f0 = arg3[2];
        *(f32 *)(new_node + 4) = temp_f2;
        *(f32 *)(new_node + 8) = temp_f1;
        *(f32 *)(new_node + 0xC) = temp_f0;
        func_0043f810(new_node + 0x18, arg2, 0xC);
        *(s32 *)(new_node + 0x10) = 0;
        *(u16 *)(new_node + 0x14) = arg4;
        *(s32 *)new_node = arg1;
        *(u16 *)(new_node + 0x14) |= 1;
        *(u16 *)(*(u8 **)new_node + 0xA0) += 1;
        for (node = *(u8 **)list; node != NULL; node = *(u8 **)(node + 0x24)) {
            if ((*(u16 *)(node + 0x20) & 0xF) == 0 &&
                *(s32 *)node == arg1) {
                if ((*(u16 *)(node + 0x14) & 2) == 0) {
                    *(s32 *)(node + 0x10) = 0;
                    *(u16 *)(node + 0x14) |= 2;
                }
                if ((*(u16 *)(new_node + 0x14) & 4) == 0) {
                    temp_f2 = *(f32 *)(node + 4);
                    temp_f1 = *(f32 *)(node + 8);
                    temp_f0 = *(f32 *)(node + 0xC);
                    *(f32 *)(new_node + 4) = temp_f2;
                    *(f32 *)(new_node + 8) = temp_f1;
                    *(f32 *)(new_node + 0xC) = temp_f0;
                    *(u16 *)(new_node + 0x14) |= 4;
                }
            }
        }
        *(u8 **)(new_node + 0x24) = *(u8 **)list;
        *(u8 **)list = new_node;
    }
}
// FUN_0020E3F0
void func_0020e3f0() {
    func_002119a0((u8 *)func_00452560() + 0x75C);
}

/* measured: entry parks are emitted in PARAMETER order, so the floats sit
   between $s6 and the $v1/$s4 parks only with (ctx, x, y, text, flag, color);
   the EE ABI assigns int/float registers independently, so callers are
   unchanged. arg3 is unsigned (srl, not sra) and the four colour bytes are
   (s8)(u8) into u64 locals (dsll32/dsra32 canonicalisation). Separate byte
   snapshots preserve the four masks and bare argument moves through the
   canonical byte-color provider declaration. `i = 0` precedes the masks
   so the index inherits the dead flag's $s4. */
// FUN_0020E420
void func_0020e420(u8 *arg0, f32 fparg0, f32 fparg1, s32 arg1, s32 arg2, u32 arg3)
{
    extern s32 iGpffffa580;
    extern void func_00442088(void *arg0, const char *arg1, ...);
    extern s32 func_00442948(const void *arg0);
    u8 sp90[0x40];
    u64 c0;
    u8 channel0;
    u64 c1;
    u8 channel1;
    u64 c2;
    u8 channel2;
    u64 c3;
    u8 channel3;
    s32 count;
    s32 i;

    c3 = (s8)(u8)((arg3 & 0xFF000000) >> 24);
    c2 = (s8)(u8)((arg3 & 0x00FF0000) >> 16);
    c1 = (s8)(u8)((arg3 & 0x0000FF00) >> 8);
    c0 = (s8)(u8)(arg3 & 0x000000FF);
    if (c0 != 0) {
        func_00442088(sp90, (const char *)&iGpffffa580, arg1);
        count = func_00442948(sp90);
        if (arg2 != 0) {
            fparg0 = fparg0 - (f32)count * 9.5f;
            fparg1 -= 11.0f;
        }
        i = 0;
        channel0 = (u8)c0;
        channel1 = (u8)c1;
        channel2 = (u8)c2;
        channel3 = (u8)c3;
        for (; i < count; i++) {
            func_00201650(arg0, 10, (s8)sp90[i] - 0x19, fparg0, fparg1,
                          channel3, channel2, channel1, channel0);
            fparg0 += 19.0f;
        }
    }
}
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
/*
 * measured: 964/976 bytes, three resolved calls, twelve zero alignment bytes.
 * The zero-duration ramp follows 0020E5C0 and the adjacent 0020F4D0 spelling;
 * its division is unreachable. Preserve the frame snapshot and flag reload.
 */
// FUN_0020E690
void func_0020e690(u8 *task, u8 *transition, u8 *panel,
                   f32 x, f32 y, s32 color, u8 *output)
{
    Vec2f position;
    s32 frame;
    f32 fade;
    f32 slide;
    func_00452560(*(void **)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (*(u16 *)(transition + 0x14) & 2) {
        if (frame < 3) fade = 0.0f;
        else if (frame < 9) fade = (f32)(frame - 3) / 6.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * (1.0f - fade));
        if (frame < 0) slide = 0.0f;
        else if (frame < 6) slide = (f32)frame / 6.0f;
        else slide = 1.0f;
        *(f32 *)output = -30.0f * slide;
    } else {
        if (frame < 0) slide = 0.0f;
        else if (frame < 0) slide = (f32)frame / 0.0f;
        else slide = 1.0f;
        if (!(slide <= 0.0f)) {
            position.x = 89.0f + x;
            position.y = 86.0f + y;
            func_003657d0(position, 0.0f, color, 22.0f * slide, 0.0f, 1);
        }
        if (frame < 0) fade = 0.0f;
        else if (frame < 3) fade = (f32)frame / 3.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * fade);
        *(f32 *)output = 10.0f * (1.0f - fade);
        if (*(u16 *)(transition + 0x14) & 4) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        } else if (frame == 3) {
            func_0021b310(panel, 1);
        } else if (frame > 3) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        }
    }
}
/*
 * measured: 1192/1200 bytes, eight resolved calls, eight zero alignment bytes.
 * Keep the alternating fade/y stages: expression propagation otherwise fuses
 * the slide arithmetic or reverses its floating-point operand order.
 */
// FUN_0020EA60
void func_0020ea60(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 stretch;
    f32 fade;
    f32 y;
    work = (u8 *)func_00452560(*(void **)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    stretch = 2.0f * first - second;
    if (!(stretch <= 0.0f)) {
        func_002019d0(work, 1.0f, stretch);
        func_00201650(work, 10, 21, 54.0f, 25.0f, 150, 255, 2, 255);
        func_00201650(work, 10, 22, 54.0f, 70.0f, 150, 255, 2, 255);
        func_002019d0(work, 1.0f, 1.0f);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 71.0f + y;
        y = fade - 16.0f;
        func_00201650(work, 10, 14, 28.0f, y, 150, 255, 2, (u8)alpha);
        func_00201650(work, 10, 13, 28.0f, y, 35, 55, 0, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    output[4] = (u8)(255.0f * fade);
    *(f32 *)output = 20.0f * (1.0f - fade);
    if (*(u16 *)(transition + 0x14) & 4) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    } else if (frame == 6) {
        func_0021b310(panel, 1);
    } else if (frame > 6) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    }
}
// FUN_0020EF10
/* Retail-exact: 1460 bytes, 7 call relocations, 12 zero alignment bytes. */
void func_0020ef10(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 expansion;
    f32 remaining;
    f32 fade;
    f32 offset;
    f32 y;
    work = (u8 *)func_00452560(*(void **)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    expansion = 3.0f * first - 2.0f * second;
    if (!(expansion <= 0.0f)) {
        alpha = (expansion > 1.0f) ? 255 : (u8)(255.0f * expansion);
        remaining = 1.0f - expansion;
        func_00201650(work, 10, 18, 61.0f,
                      (0.0f + 46.0f - 20.0f * remaining) - 16.0f,
                      244, 255, 14, (u8)alpha);
        offset = 10.0f * remaining;
        remaining = 87.0f + offset;
        y = remaining - 16.0f;
        func_00201650(work, 10, 19, 37.0f - offset, y, 244, 255, 14, (u8)alpha);
        func_00201650(work, 10, 20, 84.0f + offset, y, 244, 255, 14, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 73.0f + y;
        y = fade - 16.0f;
        func_00201650(work, 10, 12, 47.0f, y, 244, 255, 14, (u8)alpha);
        func_00201650(work, 10, 11, 47.0f, y, 54, 46, 0, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    output[4] = (u8)(255.0f * fade);
    *(f32 *)output = 20.0f * (1.0f - fade);
    if (*(u16 *)(transition + 0x14) & 4) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    } else if (frame == 6) {
        func_0021b310(panel, 1);
    } else if (frame > 6) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    }
}
/* measured: struct aggregate spelling probe for F4D0. */
#pragma opt_propagation off
// FUN_0020F4D0
void func_0020f4d0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1)
{
    extern u32 func_00452560(void *arg0);
    Vec2f sp48;
    f32 temp_f1;
    f32 var_f1;
    f32 var_f20;
    u8 *temp_17;
    s32 temp_16;

    temp_17 = (u8 *)func_00452560(*(void **)(arg0 + 4));
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
            func_00364c90(sp48, 0.0f, 0x151515FF, 87.0f,
                          16.0f, fGpffff815c, 1);
        }
        temp_f1 = 2.0f - var_f20;
        func_00364c90(sp48, 0.0f, 0xFF0F02FF,
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
/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Main current-owner compiler replay: 840/832 bytes, nd624, twenty-six object relocations; nd includes eight overrun bytes.
 * nd counts relocation-masked differing executable bytes, including overruns.
 * No native behavioral verification was run for this unpromoted candidate.
 * One initial compiler replay only; no source-layout sweep.
 * Production remains the original ASM fallback, including unchanged providers.
 *
 * Agent reconstruction evidence follows (its no-compilation statement describes
 * agent work before Main performed the compiler replay recorded above).
 * Target: func_0020f730, retail 0x0020F730..0x0020FA6F (0x340 bytes).
 * Deliverable: body.c is a complete ordinary-C candidate, not compiled or measured.
 * No production/shared files were changed. All validation was intentionally skipped as assigned.
 * 
 * ABI / input representation
 * - Entry 0x20F760..76C preserves a0=context, a1=panel pointer, a2=one packed 32-bit color, a3=signed segment index. No floating input or fifth argument exists.
 * - Existing owner Color4 is four consecutive u8 fields c0,c1,c2,c3 (src/promoted/code1_0020.c lines 125-130). body.c uses that true four-byte aggregate by value, not a pointer, u64, or invented extra arguments.
 * - Caller func_0020fa70 at 0x20FE5C..6C passes context and panel unchanged, loads one word from its four initialized color bytes at sp+0x8C into a2, and passes loop index in a3. The caller visits 1..11 inclusive. It initializes the packed color as {0x66,0x82,0xFF,0x33} or {0xFF,0x66,0x6E,0x33}; byte order is little-endian.
 * - Target spills that word at sp+0x9C and reads +0/+1/+2/+3 with lbu. c0/c1/c2 are RGB; c3 is alpha because renderer stores 255-(alpha&255) at context+0x7D.
 * - Panel fields actually accessed here are f32 at +8, sampled before renderer calls, and signed s16 at +2, sampled AFTER the first draw. No claimed complete panel struct or invented padding; u8 * plus grounded typed accesses follows the owner convention.
 * - Return is void: no return-value contract is consumed by the caller.
 * 
 * Initialized aggregates / storage proof
 * - config/slus21782.yaml maps image.bin offset zero to VRAM 0x100000. Direct binary extraction at address-0x100000 produced:
 *   0x626C40: 0000c4c2 0000b8c2 0000c442 0000b842
 *             f32 {-98,-92,98,92}, represented as corners[2][2].
 *   0x626C50: 00007041 00005842 0000d841 0000c841 00006442 00006041
 *             f32 {15,54,27,25,57,14}, represented as offsets[3][2].
 *   0x626C70: 31000000 36000000 39000000 3c000000
 *             s32 {49,54,57,60}, represented as sprites[4].
 * - The first aggregate occupies precisely sp+D0..DF: four lwc1/swc1 copies, later indexed at D0+8*flipX and D4+8*flipY.
 * - The six-word aggregate occupies precisely sp+B0..C7: retail 0x20F7B0..D0 performs three iterations, loading/storing TWO words each, advancing source and destination by eight. Accesses later are B0+8*part and B4+8*part. C8..CF is not invented array storage or padding. An ordinary initialized 3x2 float array represents the actual copy loop without a fake memcpy provider or integer/float alias punning.
 * - The four sprite words occupy sp+A0..AF. Though copied using FP loads/stores, retail reads selected values with lw at 0x20F8D8 and subtracts part as an integer. They are NOT tiny floating values.
 * - All three aggregate initializations precede the arg3==0 branch, exactly as retail; no pointers to these local arrays escape.
 * 
 * Scale constant
 * - Read orig/SLUS_217.82 ELF32 .reginfo (SHT_MIPS_REGINFO 0x70000006): gp=0x007690F0.
 * - Retail gp-0x7DF0 is therefore 0x00761300. image.bin has bytes b0 72 88 3f there: binary32 1.065999984741211 (0x3F8872B0).
 * - Candidate retains an external float load named fGpffff8210, not an immediate literal that would wrongly erase reloads. This follows existing fGpffff815c=0x0076124C mapping in config/symbols_recovered.txt. declarations.c records the new necessary symbol mapping.
 * 
 * Control flow / arithmetic
 * - Zero index: no context access or rendering after aggregate initialization.
 * - half=index/6; flipX=1-((index/3+half)&1); flipY=1-half. Signed divisions/remainders are intentional.
 * - Sign conversion is integer +1 for zero flip and -1 otherwise, followed by f32 conversion, matching cvt.s.w rather than an invented float ABI.
 * - part=index%3 if index%6<3, otherwise ~(index%3)+3. sprite=sprites[flipX|(flipY<<1)]-part. Caller-established 1..11 makes both flip flags 0/1 and part 0..2. The target itself does not add bounds guards, so the candidate does not either.
 * - Snapshot scaleY=globalScale*panel.scale before all calls.
 * - Width query first. Compute float(flipX)*returnedWidth; reload globalScale AFTER width query; divide the product by that reload; add offsets[part][0]; multiply by converted X sign; multiply by reloaded scale. No division-to-multiply rewrite or reassociation.
 * - Height query second. Compute float(flipY)*returnedHeight, divide by earlier scaleY, add offsets[part][1], multiply by converted Y sign, then multiply by scaleY.
 * - Origin X is (0.0f+float(0x117)) + newly reloaded globalScale*corners[flipX][0]; Y is (0.0f+229.0f) + scaleY*corners[flipY][1]. Retail explicitly uses adda.s to seed ACC with zero+base and madd.s for the product addition. Candidate preserves these additive/multiplicative expression trees; whether the compiler selects the identical accumulator instructions is unmeasured.
 * - Set origin, draw once with packed alpha, then reload panel signed +2 and draw again with alpha 255 if index<threshold. No outer render loop belongs in this function; it is in func_0020fa70. The only retail loop inside this window is the six-word initialization copy.
 * 
 * Providers / side effects / necessary owner corrections
 * - func_00201950 and func_00201990 each take (u8 *context,s32 bank,s32 sprite) in a0/a1/a2. Retail selects context[bank*4+0x2C], stores it at context+0x6C, stores sprite at +0x70, and calls respectively func_0046b260 or func_0046b2f0(context+0x6C). They preserve the returned f0 all the way out; target immediately consumes it as binary32.
 * - Current promoted owner incorrectly defines those two as void with bare calls. declarations.c specifies the essential f32 return types and `return` of their existing lower calls. This is required for a truthful candidate, not a block-scope false signature or unrelated ABI repair. Existing src/Kernel/sdkSpr.c lines 261-310 already defines both lower providers as f32, deriving dimensions from sprite metadata and optional dimension/scaling overrides. No new dimension helper or bypass of the real provider is proposed.
 * - func_002012d0(u8 *,f32,f32) uses a0,f12,f13; converts the coordinates to integer origin at context+4/+8 and clears context+C/+10. Its existing owner definition is truthful.
 * - func_00201650(u8 *,s32,s32,f32,f32,s32,s32,s32,s32) uses a0/a1/a2,f12/f13,a3/t0/t1/t2. Existing owner definition is truthful: sets RGB at +94/+95/+96, inverse alpha at +7D, invokes func_00201410, then resets RGB to 255 and inverse alpha to zero. No s64 color redeclarations are needed.
 * - func_00201410 selects the sprite, transforms coordinates from current renderer state, sets optional scaling fields, invokes func_0046b380, and clears scaling fields on its scaled path. Calls are retained in order with full opaque effects. No callback function pointer is an input to this target and none is fabricated. Do not mark providers pure/const or hoist panel threshold/global-scale reads across them: callbacks or aliased state reachable in renderer calls must retain their observable effects.
 * 
 * Uncertainty / blocker status
 * - No semantic representability blocker found for the actual caller's index range. Complete initializers, storage bounds, argument registers, effects, and arithmetic order are grounded.
 * - Initial array layout, compiler-generated aggregate-copy loop, register allocation, and accumulator instruction selection remain unmeasured; no MATCH claim is made. Main must perform central compilation/measurement and integrate the two essential return corrections before trying this candidate.
 * - Graph lookup and coverage checks found stale promoted-source metadata and partial assembly parsing. All substantive claims above use direct current-source/retail reads, plus raw image/ELF extraction; no graph absence was treated as proof.
 */

/* New owner-local data declaration. Retail gp is 0x007690F0; the load at
 * gp - 0x7DF0 addresses 0x00761300. Add the equivalent recovered-symbol
 * mapping if the normal symbol-recovery step does not already create it:
 * fGpffff8210 = 0x00761300; // type:data
 */
extern f32 fGpffff8210;

/* Correct the existing owner definitions to these result types, and replace
 * their final bare calls with `return func_0046b260(arg0 + 0x6C);` and
 * `return func_0046b2f0(arg0 + 0x6C);`, respectively. All existing argument
 * types and the two context stores remain unchanged. Do not add conflicting
 * block-scope declarations while retaining the incorrect void definitions.
 */
f32 func_00201950(u8 *arg0, s32 arg1, s32 arg2);
f32 func_00201990(u8 *arg0, s32 arg1, s32 arg2);

/* Existing Color4 at owner lines 125-130 is already exactly four u8 members
 * c0/c1/c2/c3 and needs no changes. Existing func_002012d0 and func_00201650
 * definitions already have the truthful signatures used by body.c.
 */

/* measured: object 836B/window 832B/normalized_diff 616 (199 differing words, live re-measured current tree). */
/* measured: top fnalign is absolute-data vs stack-immediate plus frame -0xe0 vs -0x100; extern-load variant improves 199 to 196 but goes 10pt short (182 vs 204 instrs, draft) so kept stack-immediate floor (209 vs 204 instrs, plus 2pt over, good size); slti-at N-A (no lt range, sltiu-at with a1-a2 input coloring), no 2-3 short tail (209 vs 204), arg-setup fixed (Color4 by value, 3-arg providers), loop-invariant neutral. */
/* measured 0020f730: `schedule on` inside the guard is worth 5 words (199 -> 194). */
// FUN_0020F730 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
void func_0020f730(u8 *arg0, u8 *arg1, Color4 arg2, s32 arg3)
{
    f32 corners[2][2] = {
        {-98.0f, -92.0f},
        {98.0f, 92.0f}
    };
    f32 offsets[3][2] = {
        {15.0f, 54.0f},
        {27.0f, 25.0f},
        {57.0f, 14.0f}
    };
    s32 sprites[4] = {49, 54, 57, 60};
    f32 scaleY;
    f32 drawY;
    f32 drawX;
    f32 dimension;
    f32 scaleX;
    s32 flipY;
    s32 flipX;
    s32 sprite;
    s32 part;
    s32 half;
    s32 sign;
    s32 green;
    s32 blue;

    if (arg3 != 0) {
        scaleY = fGpffff8210 * *(f32 *)(arg1 + 8);
        half = arg3 / 6;
        flipX = 1 - (((arg3 / 3) + half) & 1);
        flipY = 1 - half;
        sign = 1;
        if (flipX != 0) {
            sign = -1;
        }
        drawX = (f32)sign;
        if (flipY == 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        drawY = (f32)sign;
        if (arg3 % 6 < 3) {
            part = arg3 % 3;
        } else {
            part = ~(arg3 % 3) + 3;
        }
        sprite = sprites[flipX | (flipY << 1)] - part;
        dimension = func_00201950(arg0, 10, sprite);
        dimension = (f32)flipX * dimension;
        scaleX = fGpffff8210;
        drawX = scaleX * (drawX * (offsets[part][0] + dimension / scaleX));
        dimension = func_00201990(arg0, 10, sprite);
        dimension = (f32)flipY * dimension;
        drawY = scaleY * (drawY * (offsets[part][1] + dimension / scaleY));
        func_002012d0(arg0,
                     (0.0f + (f32)0x117) + fGpffff8210 * corners[flipX][0],
                     (0.0f + 229.0f) + scaleY * corners[flipY][1]);
        blue = arg2.c2;
        green = arg2.c1;
        func_00201650(arg0, 10, sprite, drawX, drawY,
                      arg2.c0, green, blue, arg2.c3);
        if (arg3 < *(s16 *)(arg1 + 2)) {
            func_00201650(arg0, 10, sprite, drawX, drawY,
                          arg2.c0, green, blue, 255);
        }
    }
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020f730);
#endif
// FUN_0020FA70
/* Retail-exact: 1156 bytes, 24 relocations, 12 zero alignment bytes. */
void func_0020fa70(u8 *work, u8 *state)
{
    extern void func_0020f730(u8 *work, u8 *state, s32 color, s32 index);
    extern f32 D_00761300;
    extern f32 fGpffff8110;
    extern f32 fGpffff84ac;
    union { Color4 rgba; s32 bits; } ring, fill, saved, black, transparent;
    Vec2f position;
    u8 red;
    u8 green;
    u8 blue;
    s32 index;
    f32 extent;
    extent = *(f32 *)(state + 8);
    if (extent == 0.0f) return;
    func_00201350();
    if (*(s16 *)(state + 4) & 4) {
        red = 140; green = 170; blue = 255;
        ring.rgba.c0 = 102; ring.rgba.c1 = 130; ring.rgba.c2 = 255;
        fill.rgba.c0 = 0; fill.rgba.c1 = 25; fill.rgba.c2 = 255;
    } else {
        red = 255; green = 140; blue = 170;
        ring.rgba.c0 = 255; ring.rgba.c1 = 102; ring.rgba.c2 = 110;
        fill.rgba.c0 = 255; fill.rgba.c1 = 0; fill.rgba.c2 = 21;
    }
    ring.rgba.c3 = 51;
    fill.rgba.c3 = (u8)(255.0f * extent);
    func_002012d0(work, (f32)279, 229.0f);
    func_002019d0(work, 1.0f, 1.0f);
    saved.rgba = fill.rgba;
    position.x = (f32)279;
    position.y = 229.0f;
    transparent.rgba.c0 = black.rgba.c0 = 0;
    transparent.rgba.c1 = black.rgba.c1 = 0;
    transparent.rgba.c2 = black.rgba.c2 = 0;
    black.rgba.c3 = (u8)(76.0f * extent);
    transparent.rgba.c3 = 0;
    func_00365f00(position, 0.0f, black.bits, transparent.bits, 100.0f, 0.0f, 12, D_00761300, 1.0f, 0);
    transparent.rgba.c0 = saved.rgba.c0;
    transparent.rgba.c1 = saved.rgba.c1;
    transparent.rgba.c2 = saved.rgba.c2;
    transparent.rgba.c3 = 0;
    func_00201820(2);
    func_00365f00(position, 0.0f, fill.bits, transparent.bits, 125.0f, 0.0f, 12, D_00761300, 1.0f, 0);
    func_00201720(work, extent, 1.0f);
    func_002016e0(work, 0, 0, 90.0f);
    func_00201650(work, 10, 45, 20.0f, -57.0f * extent, red, green, blue, 255);
    if (state[0]) {
        func_00201720(work, fGpffff8110, 1.5f);
        func_00201650(work, 10, 45, 30.0f, fGpffff84ac, red, green, blue, state[0]);
    }
    func_00201720(work, 1.0f, extent);
    func_002016e0(work, 0, 0, 0.0f);
    func_00201650(work, 10, 46, 12.0f, -5.0f * extent, red, green, blue, 255);
    func_00201720(work, D_00761300, extent);
    for (index = 1; index < 12; index++) func_0020f730(work, state, ring.bits, index);
    func_002016e0(work, 0, 0, 0.0f);
    func_00201720(work, 1.0f, 1.0f);
    func_002019d0(work, 1.0f, 1.0f);
}
// FUN_0020FF00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ff00);
