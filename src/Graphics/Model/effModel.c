#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit retail's lq/sq
   quadword copy, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

extern void func_004813f0(void);
extern void func_004abe60(void);
extern s32 func_00481460(s32 arg0);
extern void *func_00478140(u16 arg0, u16 arg1, s32 arg2);
extern void func_0046d730(const char *arg0, s32 arg1);
extern void func_0047a2a0(void *arg0);
extern s32 func_00479ca0(void *arg0, s32 arg1);
extern void func_00479940(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478eb0(void *arg0, void (*arg1)(void), void *arg2);
extern void func_004787e0(u32 arg0);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_007144A8[];
extern void *func_004abe80(u8 *arg0);
extern void func_004ac170(u8 *arg0, u8 *arg1);
extern void func_004ac300(s32 arg0, u8 *arg1);
extern u8 *func_004ac640(u8 *arg0);
extern void func_004ac9a0(u8 *arg0, u8 *arg1);
extern void func_00478ea0(u8 *arg0, void (*arg1)(u8 *), void *arg2);
extern void func_0047a4d0(void *arg0, s32 arg1);
extern u8 *func_00484490(u8 *arg0);
extern s32 func_004844d0(u8 *arg0);
extern s32 func_00477c40(u16 arg0, u16 arg1, s32 arg2);
extern u8 *func_00477f10(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u16 iGpffffbb90;
extern char D_007144B8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);



// FUN_004ABD80
void *func_004abd80(void *arg0)
{
    void *work;

    work = func_00478140(*(u16 *)((u8 *)arg0 + 0xD4), *(u16 *)((u8 *)arg0 + 0xD6), 1);
    if (work == 0) {
        func_0046d730(D_007144A8, 0x55);
    }
    func_0047a2a0(work);
    if (func_00479ca0(work, 0) != 0) {
        func_00479940(work, 0, 0, 0, 0);
        func_0047a0e0(work, 0, 1.0f);
    }
    *(u32 *)((u8 *)work + 0xD8) &= 0xFFFFFFFD;
    func_00478eb0(work, func_004abe60, work);
    return work;
}

// FUN_004ABE60
void func_004abe60(void) {
    func_004813f0();
}

// FUN_004ABE80
void *func_004abe80(u8 *arg0) {
    f32 temp_f20;
    s32 temp_18;
    s32 temp_2_3;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;

    func_0044ea90(D_007144B8, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x9C, 0x40000);
    func_0043f9c8(temp_2, 0, 0x9C);
    if (temp_2 == NULL) {
        func_0046d730(D_007144A8, 0x73);
    }
    *(s32 *)(temp_2 + 0x98) = 0;
    *(s32 *)(temp_2 + 0x28) = -1;
    temp_f20 = 1.0f;
    *(f32 *)(temp_2 + 0x20) = temp_f20;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(temp_2) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(temp_2) : "memory");
    if (arg0 != NULL) {
        temp_2_2 = func_00484490(arg0);
        if (temp_2_2 == NULL) {
            func_0046d730(D_007144A8, 0x83);
        }
        func_0043f810(temp_2 + 0x2C, temp_2_2, 0x68);
        temp_2_3 = func_004844d0(arg0);
        if (temp_2_3 != 0) {
            if (*(u16 *)(arg0 + 0x1C) != 3) {
                func_0046d730(D_007144A8, 0x8A);
            }
            temp_18 = *(s32 *)(arg0 + 0x24);
            while (func_00477c40(6, iGpffffbb90, 0) != 0) {
                iGpffffbb90 += 1;
            }
            temp_2_4 = func_00477f10(6, iGpffffbb90, temp_2_3, temp_18, 1);
            func_0047a2a0(temp_2_4);
            if (func_00479ca0(temp_2_4, 0) != 0) {
                func_00479940(temp_2_4, 0, 0, 0, 0);
                func_0047a0e0(temp_2_4, 0, temp_f20);
            }
            *(u32 *)(temp_2_4 + 0xD8) &= ~2U;
            func_00478eb0(temp_2_4, func_004abe60, temp_2_4);
            iGpffffbb90 += 1;
            *(u8 **)(temp_2 + 0x94) = temp_2_4;
        }
    }
    return temp_2;
}
// FUN_004AC0B0
void func_004ac0b0(void *arg0)
{
    if (*(void **)((u8 *)arg0 + 0x94) != 0) {
        func_004787e0(*(u32 *)((u8 *)arg0 + 0x94));
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004AC100
void *func_004ac100(void *arg0)
{
    void *work;

    work = func_004abe80(0);
    func_0043f810((u8 *)work + 0x2C, (u8 *)arg0 + 0x2C, 0x68);
    func_004ac170(work, arg0);
    return work;
}

// FUN_004AC170
void func_004ac170(u8 *dst, u8 *src)
{
    void *work;

    if (*(void **)(src + 0x94) == 0) {
        func_0046d730(D_007144A8, 0xBB);
    }
    if (*(void **)(dst + 0x94) != 0) {
        func_004787e0(*(u32 *)(dst + 0x94));
    }
    work = func_00478140(*(u16 *)(*(u32 *)(src + 0x94) + 0xD4), *(u16 *)(*(u32 *)(src + 0x94) + 0xD6), 0);
    if (work == 0) {
        func_0046d730(D_007144A8, 0xC5);
    }
    func_0047a2a0(work);
    if (func_00479ca0(work, 0) != 0) {
        func_00479940(work, 0, 0, 0, 0);
        func_0047a0e0(work, 0, 1.0f);
    }
    *(u32 *)((u8 *)work + 0xD8) &= 0xFFFFFFFD;
    func_00478eb0(work, func_004abe60, work);
    *(void **)(dst + 0x94) = work;
}

// FUN_004AC290
void func_004ac290(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0x94), 0, 0.0f);
}



// FUN_004AC2C0
void func_004ac2c0(u32 *param_1)
{
  if ((param_1[0x23] >= param_1[0x26]) || (param_1[0x23] == 0)) {
    *(f32 *)(param_1 + 9) = 1.0f;
    param_1[0x26] = param_1[0x26] + 1;
  }
}



extern void func_004accc0(u8 *arg0);
extern char D_007144B8[];
extern void func_0047a850(void *arg0);
extern s32 func_0048abd0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void func_0047a220(void *arg0, s32 *arg1);
extern f32 func_0048aff0(void *arg0, u32 arg1, u32 arg2);
extern void func_0048a150(void *arg0, void *arg1);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_0047a1e0(void *arg0, f32 *arg1, s32 arg2);
extern void func_0047a180(void *arg0, f32 *arg1, s32 arg2);
extern void func_0047aa30(void *arg0, s32 arg1);
extern s32 func_00481450(void);
extern void func_00479100(s32 arg0, void *arg1);
extern f32 D_00761134;

// FUN_004AC300
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac300);
// FUN_004AC550
void func_004ac550(void *arg0)
{
    func_004ac300(func_00481460(*(u16 *)((u8 *)arg0 + 0x54)), arg0);
}

// FUN_004AC590
void func_004ac590(u32 *param_1)
{
    if ((param_1[0x23] >= param_1[0x26]) || (param_1[0x23] == 0)) {
        *(f32 *)(param_1 + 9) = 1.0f;
        param_1[0x26] = param_1[0x26] + 1;
    }
    func_004ac300(func_00481460(*(u16 *)&param_1[0x15]), (u8 *)param_1);
}

// FUN_004AC600
u_long128 func_004ac600(u_long128 *dst, u_long128 *src) {
    return *dst = *src;
}

// FUN_004AC610
u_long128 func_004ac610(u_long128 *dst, u_long128 *src) {
    return dst[1] = *src;
}

// FUN_004AC630
void func_004ac630(void *arg0, f32 arg1)
{
    *(f32 *)((u8 *)arg0 + 0x20) = arg1;
}

// FUN_004AC620
void func_004ac620(int param_1, int param_2)
{
  *(int *)(param_1 + 0x28) = param_2;
}

// FUN_004AC640
u8 *func_004ac640(u8 *arg0) {
    s32 temp_18;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_4;

    func_0044ea90(D_007144B8, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0xBC, 0x40000);
    func_0043f9c8(temp_2, 0, 0xBC);
    if (temp_2 == NULL) {
        func_0046d730(D_007144A8, 0x18A);
    }
    *(s32 *)(temp_2 + 0xC) = -1;
    if (arg0 != NULL) {
        temp_2_2 = func_00484490(arg0);
        if (temp_2_2 == NULL) {
            func_0046d730(D_007144A8, 0x196);
        }
        func_0043f810(temp_2 + 0x10, temp_2_2, 0xA4);
        temp_2_3 = func_004844d0(arg0);
        if (temp_2_3 != 0) {
            if (*(u16 *)(arg0 + 0x1C) != 3) {
                func_0046d730(D_007144A8, 0x19D);
            }
            temp_18 = *(s32 *)(arg0 + 0x24);
            while (func_00477c40(6, iGpffffbb90, 0) != 0) {
                iGpffffbb90 += 1;
            }
            temp_2_4 = func_00477f10(6, iGpffffbb90, temp_2_3, temp_18, 1);
            func_0047a2a0(temp_2_4);
            if (func_00479ca0(temp_2_4, 0) != 0) {
                func_00479940(temp_2_4, 0, 0, 0, 0);
                func_0047a0e0(temp_2_4, 0, 1.0f);
            }
            *(u32 *)(temp_2_4 + 0xD8) &= ~2U;
            func_00478eb0(temp_2_4, func_004abe60, temp_2_4);
            iGpffffbb90 += 1;
            *(u8 **)(temp_2 + 0xB4) = temp_2_4;
            func_00478ea0(temp_2_4, func_004accc0, temp_2);
            if (*(u8 *)(temp_2 + 0xA0) == 0) {
                func_0047a4d0(*(u8 **)(temp_2 + 0xB4), 0x20);
            }
            if (*(s32 *)(temp_2 + 0xA4) != 0) {
                temp_4 = *(u8 **)(temp_2 + 0xB4);
                *(u32 *)(temp_4 + 0xD8) |= 0x40000;
            }
            temp_3 = *(s32 *)(temp_2 + 0x70);
            if ((temp_3 >= 0) && (temp_2_5 = *(s32 *)(temp_2 + 0x74), temp_2_5 >= 0) && (temp_2_5 >= temp_3)) {
                *(s8 *)(temp_2 + 0xB8) = 1;
            } else {
                *(s8 *)(temp_2 + 0xB8) = 0;
            }
        }
    }
    return temp_2;
}
// FUN_004AC8E0
void func_004ac8e0(void *arg0)
{
    if (*(void **)((u8 *)arg0 + 0xB4) != 0) {
        func_004787e0(*(u32 *)((u8 *)arg0 + 0xB4));
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004AC930
void *func_004ac930(void *arg0)
{
    void *work;

    work = func_004ac640(0);
    func_0043f810((u8 *)work + 0x10, (u8 *)arg0 + 0x10, 0xA4);
    func_004ac9a0(work, arg0);
    return work;
}

// FUN_004AC9A0
void func_004ac9a0(u8 *dst, u8 *src)
{
    void *work;

    if (*(void **)(src + 0xB4) == 0) {
        func_0046d730(D_007144A8, 0x1D0);
    }
    if (*(void **)(dst + 0xB4) != 0) {
        func_004787e0(*(u32 *)(dst + 0xB4));
    }
    work = func_00478140(*(u16 *)(*(u32 *)(src + 0xB4) + 0xD4), *(u16 *)(*(u32 *)(src + 0xB4) + 0xD6), 0);
    if (work == 0) {
        func_0046d730(D_007144A8, 0x1DA);
    }
    func_0047a2a0(work);
    if (func_00479ca0(work, 0) != 0) {
        func_00479940(work, 0, 0, 0, 0);
        func_0047a0e0(work, 0, 1.0f);
    }
    *(u32 *)((u8 *)work + 0xD8) &= 0xFFFFFFFD;
    func_00478eb0(work, func_004abe60, work);
    *(void **)(dst + 0xB4) = work;
    func_00478ea0(work, func_004accc0, dst);
    if (*(u8 *)(dst + 0xA0) == 0) {
        func_0047a4d0(*(void **)(dst + 0xB4), 0x20);
    }
    if (*(u32 *)(dst + 0xA4) != 0) {
        *(u32 *)(*(u32 *)(dst + 0xB4) + 0xD8) |= 0x40000;
    }
    if ((*(s32 *)(dst + 0x70) >= 0) && (*(s32 *)(dst + 0x74) >= 0) && (*(s32 *)(dst + 0x74) >= *(s32 *)(dst + 0x70))) {
        *(u8 *)(dst + 0xB8) = 1;
    } else {
        *(u8 *)(dst + 0xB8) = 0;
    }
}
