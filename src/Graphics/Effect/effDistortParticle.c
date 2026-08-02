#include "include_asm.h"
/* Persona 4 USA decompilation - effDistortParticle.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00714538[];
extern char D_00714550[];

extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern void func_00492cd0(void *ptr);
extern u8 *func_00484490(void);
extern s32 func_004844d0(void *obj);
extern u8 *func_00492b20(u32 arg0, s32 arg1, u8 *arg2);
extern void func_00492d10(void *ptr);
extern s32 func_00481300(u16 param);
extern void func_00492df0(void *arg0, void *arg1);
extern void func_00492db0(void *arg0, void *arg1);
extern s32 func_004bd050(s32 arg0);
extern s32 func_004afe20(u8 *arg0, u8 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
extern void func_004bceb0(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern f32 func_004bd0b0(u32 arg0);
extern f32 fGpffff8080;
extern f32 fGpffff8098;
extern f32 fGpffff809c;
void func_004afc80(u8 *arg0, u8 *arg1);
void func_004afb10(u8 *arg0, u32 arg1, u8 *arg2);
void func_004afa60(u8 *arg0, s32 arg1);
void func_004afaa0(u8 *arg0, u8 *arg1);
extern s32 func_00481390();

// FUN_004AF680
u8 *func_004af680(u32 arg0) {
    u8 *temp;

    func_0044ea90(D_00714538, 0x171);
    temp = (u8 *)(*jtbl_008873E8)(0x9C, 0x40000);
    func_0043f9c8(temp, 0, 0x9C);
    if (temp == NULL) {
        func_0046d730(D_00714550, 0x2F);
    }
    *(u32 *)(temp + 0) = arg0;
    *(s32 *)(temp + 4) = -1;
    *(u32 *)(temp + 8) = 0x3F800000;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    *(s16 *)(temp + 0x84) = 0x1A;
    *(u32 *)(temp + 0x88) = (u32)temp;
    return temp;
}

// FUN_004AF740
u8 *func_004af740(u8 *arg0) {
    s32 temp_3;
    u32 var_4;
    u8 *temp_2_2;
    u8 *temp_2;
    s32 temp_2_3;

    temp_2_2 = func_00484490();
    if (temp_2_2 == NULL) {
        func_0046d730(D_00714550, 0x69);
    }
    temp_3 = *(s32 *)(temp_2_2 + 0x68);
    if (temp_3 == 0) {
        var_4 = *(u32 *)(temp_2_2 + 0x100) * *(u32 *)(temp_2_2 + 0x6C);
    } else {
        var_4 = (u32)temp_3 * *(u32 *)(temp_2_2 + 0x6C);
    }
    if (var_4 > 0x64) {
        var_4 = 0x64;
    }
    temp_2 = func_004af680(var_4);
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0x6B);
    }
    func_0043f810(temp_2 + 0xC, temp_2_2, 0x48);
    func_004afb10(temp_2, *(u16 *)(arg0 + 0xC), temp_2_2 + 0x48);
    if (*(s32 *)(*(u8 **)(temp_2 + 0x5C) + 8) == 0) {
        return temp_2;
    }
    temp_2_3 = func_004844d0(arg0);
    if (temp_2_3 != 0) {
        switch (*(u16 *)(arg0 + 0x1C)) {
        case 1:
            func_004afa60(temp_2, temp_2_3);
            break;
        default:
            func_0046d730(D_00714550, 0x80);
            break;
        }
    }
    return temp_2;
}

// FUN_004AF8A0
void func_004af8a0(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x60);
    if (temp != NULL) {
        func_003ef3a0(temp);
    }
    temp = *(u8 **)(arg0 + 0x5C);
    if (temp != NULL) {
        func_00492cd0(temp);
    }
    temp = *(u8 **)(arg0 + 0x68);
    if (temp != NULL) {
        (*jtbl_008873EC)(temp);
    }
    (*jtbl_008873EC)(arg0);
}

// FUN_004AF920
u8 *func_004af920(u8 *arg0) {
    s32 temp_3;
    u32 var_4;
    u8 *temp_16;
    u8 *temp_2;

    if (*(u8 **)(arg0 + 0x5C) == NULL) {
        func_0046d730(D_00714550, 0xB3);
    }
    temp_16 = *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x24);
    if (temp_16 == NULL) {
        func_0046d730(D_00714550, 0xB5);
    }
    temp_3 = *(s32 *)(temp_16 + 0x20);
    if (temp_3 == 0) {
        var_4 = *(u32 *)(temp_16 + 0xB8) * *(u32 *)(temp_16 + 0x24);
    } else {
        var_4 = (u32)temp_3 * *(u32 *)(temp_16 + 0x24);
    }
    if (var_4 > 0x64) {
        var_4 = 0x64;
    }
    temp_2 = func_004af680(var_4);
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0xB7);
    }
    func_0043f810(temp_2 + 0xC, arg0 + 0xC, 0x48);
    func_004afb10(temp_2, *(u16 *)(*(u8 **)(arg0 + 0x5C) + 0), temp_16);
    if (*(s32 *)(*(u8 **)(temp_2 + 0x5C) + 8) == 0) {
        return temp_2;
    }
    func_004afaa0(temp_2, arg0);
    return temp_2;
}

// FUN_004AFA60
void func_004afa60(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x60) = func_00481390(arg1);
}

// FUN_004AFAA0
void func_004afaa0(u8 *arg0, u8 *arg1) {
    u8 *temp;

    if (*(u32 *)(arg1 + 0x60) == 0) {
        func_0046d730(D_00714550, 0xDA);
    }
    temp = *(u8 **)(arg1 + 0x60);
    *(u8 **)(arg0 + 0x60) = temp;
    *(s32 *)(temp + 0x54) += 1;
}

// FUN_004AFB10
void func_004afb10(u8 *arg0, u32 arg1, u8 *arg2) {
    u32 temp_16;
    u8 *var_19;
    u32 var_18;
    u8 *temp_2;

    if (*(u8 **)(arg0 + 0x5C) != NULL) {
        func_00492cd0(*(u8 **)(arg0 + 0x5C));
    }
    if (*(s32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(D_00714550, 0xF4);
    }
    *(u8 **)(arg0 + 0x5C) = func_00492b20(arg1 & 0xFFFF, *(s32 *)(arg0 + 0), arg2);
    if (*(u8 **)(arg0 + 0x68) != NULL) {
        (*jtbl_008873EC)(*(u8 **)(arg0 + 0x68));
    }
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x5C) + 8);
    func_0044ea90(D_00714550, 0xFE);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_16 * 0x1C, 0x40000);
    *(u8 **)(arg0 + 0x68) = temp_2;
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0xFF);
    }
    var_19 = *(u8 **)(arg0 + 0x68);
    *(u8 **)(arg0 + 0x64) = var_19;
    var_18 = 0;
    while (var_18 < temp_16) {
        func_004afc80(arg0, var_19);
        var_18 += 1;
        var_19 += 0x1C;
    }
}

// FUN_004AFC50
void func_004afc50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x5C);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AFC80
void func_004afc80(u8 *arg0, u8 *arg1) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;

    temp_f20 = *(f32 *)(arg0 + 0xC);
    temp_f20_2 = (1.0f - temp_f20) + temp_f20 * func_004bd0b0(0);
    *(f32 *)(arg1 + 0) = fGpffff8080 * func_004bd0b0(0);
    *(f32 *)(arg1 + 0xC) = fGpffff8080 * func_004bd0b0(0);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * func_004bd0b0(0));
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * func_004bd0b0(0));
    *(f32 *)(arg1 + 8) = temp_f20_2 * (*(f32 *)(arg0 + 0x10) * (fGpffff809c + fGpffff8098 * func_004bd0b0(0)));
    *(f32 *)(arg1 + 0x14) = temp_f20_2 * (*(f32 *)(arg0 + 0x14) * (fGpffff809c + fGpffff8098 * func_004bd0b0(0)));
    temp_f20_3 = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x18) = (1.0f - temp_f20_3) + temp_f20_3 * func_004bd0b0(0);
}

// FUN_004AFE20
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afe20);

// FUN_004B0A80
void func_004b0a80(u8 *arg0) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    s32 temp_16;
    u8 *var_19;
    u8 *var_18;
    s32 var_17;
    u8 *temp_4;

    func_00492d10(*(u8 **)(arg0 + 0x5C));
    temp_4 = *(u8 **)(arg0 + 0x5C);
    temp_16 = *(s32 *)(temp_4 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_4 + 0x10) != 0)) {
        var_19 = *(u8 **)(temp_4 + 0x18);
        var_18 = *(u8 **)(arg0 + 0x64);
        *(f32 *)(arg0 + 0x54) = *(f32 *)(arg0 + 0x54) + *(f32 *)(arg0 + 0x1C);
        *(f32 *)(arg0 + 0x58) = *(f32 *)(arg0 + 0x58) + *(f32 *)(arg0 + 0x20);
        var_17 = 0;
        while (var_17 < temp_16) {
            if (*(s32 *)(var_19 + 0x10) == 0) {
                temp_f20 = *(f32 *)(arg0 + 0xC);
                temp_f20_2 = (1.0f - temp_f20) + temp_f20 * func_004bd0b0(0);
                *(f32 *)(var_18 + 0) = fGpffff8080 * func_004bd0b0(0);
                *(f32 *)(var_18 + 0xC) = fGpffff8080 * func_004bd0b0(0);
                *(f32 *)(var_18 + 4) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * func_004bd0b0(0));
                *(f32 *)(var_18 + 0x10) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * func_004bd0b0(0));
                *(f32 *)(var_18 + 8) = temp_f20_2 * (*(f32 *)(arg0 + 0x10) * (fGpffff809c + fGpffff8098 * func_004bd0b0(0)));
                *(f32 *)(var_18 + 0x14) = temp_f20_2 * (*(f32 *)(arg0 + 0x14) * (fGpffff809c + fGpffff8098 * func_004bd0b0(0)));
                temp_f20_3 = *(f32 *)(arg0 + 0x24);
                *(f32 *)(var_18 + 0x18) = (1.0f - temp_f20_3) + temp_f20_3 * func_004bd0b0(0);
            }
            if (*(s32 *)(var_19 + 0x10) >= 0) {
                *(f32 *)(var_18 + 0) = *(f32 *)(var_18 + 0) + *(f32 *)(var_18 + 4);
                *(f32 *)(var_18 + 0xC) = *(f32 *)(var_18 + 0xC) + *(f32 *)(var_18 + 0x10);
            }
            var_17 += 1;
            var_19 += 0x20;
            var_18 += 0x1C;
        }
    }
}

// FUN_004B0CE0
void func_004b0ce0(u8 *arg0, s32 arg1) {
    s32 spFC;
    f32 spF0[2];
    u8 spE0[16];
    u8 spD0[16];
    u8 spC0[16];
    u8 spB0[16];
    u8 sp70[0x40];
    u8 *var_18;
    s32 temp_16;
    s32 var_21;
    s32 var_21_2;
    u8 *temp_21;
    u8 *temp_3;
    u8 *temp_4;
    u8 *var_17;

    temp_3 = *(u8 **)(arg0 + 0x5C);
    temp_16 = *(s32 *)(temp_3 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_3 + 0x10) != 0)) {
        if (*(s32 *)(arg0 + 0x60) == 0) {
            func_0046d730(D_00714550, 0x265);
        }
        var_18 = *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x18);
        var_17 = *(u8 **)(arg0 + 0x64);
        temp_21 = *(u8 **)(s32)func_00481300(0x15);
        if ((arg1 & 0xFF) == 1) {
            D_00887300[0](1, (u32)temp_21);
        }
        spF0[0] = (f32) * (s32 *)(temp_21 + 0xC);
        spF0[1] = (f32) * (s32 *)(temp_21 + 0x10);
        spFC = *(s32 *)(arg0 + 4);
        __asm__ volatile(
            "lw $3, -0x7E0C($gp)     \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            :
            : "r"(&spFC)
            : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spE0) : "$vf10", "memory");
        temp_4 = *(u8 **)(arg0 + 0x5C);
        if (!(*(s32 *)(temp_4 + 0xC) & 1)) {
            var_21 = 0;
            while (var_21 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    func_004afe20(arg0, var_17, var_18, var_18, spE0, spF0, arg1, func_004bd050(0) & 3);
                }
                var_21 += 1;
                var_18 += 0x20;
                var_17 += 0x1C;
            }
        } else {
            func_00492df0(temp_4, spB0);
            func_00492db0(*(u8 **)(arg0 + 0x5C), spC0);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(spB0) : "$vf10", "memory");
            func_004bceb0();
            __asm__ volatile("lqc2 $vf31, 0(%0)" : : "r"(spC0) : "$vf31", "memory");
            __asm__ volatile(
                "sqc2 $vf28, 0(%0)     \n"
                "sqc2 $vf29, 16(%0)    \n"
                "sqc2 $vf30, 32(%0)    \n"
                "sqc2 $vf31, 48(%0)    \n"
                :
                : "r"(sp70)
                : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            var_21_2 = 0;
            while (var_21_2 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    __asm__ volatile(
                        "lqc2 $vf28, 0(%0)     \n"
                        "lqc2 $vf29, 16(%0)    \n"
                        "lqc2 $vf30, 32(%0)    \n"
                        "lqc2 $vf31, 48(%0)    \n"
                        "lqc2 $vf10, 0(%1)     \n"
                        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                        "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                        "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                        :
                        : "r"(sp70), "r"(var_18)
                        : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spD0) : "$vf10", "memory");
                    func_004afe20(arg0, var_17, var_18, spD0, spE0, spF0, arg1, func_004bd050(0) & 3);
                }
                var_21_2 += 1;
                var_18 += 0x20;
                var_17 += 0x1C;
            }
        }
        D_00887300[0](1, 0);
    }
}
