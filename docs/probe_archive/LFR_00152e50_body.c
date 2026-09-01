/* LFR archive: closest non-matching candidate; retained for reference only. */
#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct { f32 x; f32 y; f32 z; } Vec3;
typedef struct { f32 x; f32 y; f32 z; f32 w; } Vec4;

extern void func_00442088();
extern void func_00440b68(u8 *msg, u8 *file, s32 line);
extern s32 func_00454a60(char *path, s32 mode);
extern s32 func_004553c0(s32 handle);
extern u8 *func_00460f80(u8 *list, s32 arg1);
extern u8 *func_00461080(u8 *list, s32 arg1);
extern u8 *func_00461180(u8 *list, s32 arg1);
extern u8 *func_003e9d50(u8 *arg0);
extern void func_00152170();
extern s32 func_004581a0(void *object, const char *name);
extern void func_00458430(s32 *out, void *object, const char *name, s32 index);
extern void func_0046d730(const char *file, s32 line);
extern void func_0047a1a0(void);
extern void func_004b1290(s32 a0, f32 f12, f32 f13, f32 f14);
extern void func_003c9d40(void *arg0);
extern void func_003c0700(void *arg0);
extern void func_00462bf0(void *arg0);
extern void func_004787e0(s32 arg0);
extern void func_004b1150(s32 arg0);
extern void func_003bbb60(void *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_00460e80(u8 *list, s32 arg1);
extern u8 *func_00461290(u8 *list, s32 arg1);
extern void *func_00457120(void);
extern void *func_00457190(void);
extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);
extern void func_003e8110(void *arg0);
extern void func_003e8120(void *arg0);
extern void func_003cbf30(s32 a0, void *a1);
extern void func_003cbe80(void *a0, void *a1);
extern void func_003cbc60(s32 a0, void *a1);
extern void func_003cbc10(void *a0, void *a1);
extern void func_003c38b0(void *a0, void *a1);
extern void func_003e9cb0(void *a0, void *a1, s32 a2);
extern s32 func_004782b0(u32 arg0);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00479940(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8 *func_003e9700(void *a);
extern void func_00463250(void *arg0);
extern s32 func_004b1130(s32 a0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void func_003e2e40(s32 arg0, s32 arg1);
extern s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003dc370(void *arg0);
extern void func_003ef260(s32 arg0, void (*arg1)(void), void *arg2);
extern void func_003ef1b0(s32 arg0);
extern void func_00463100();
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 func_00149ca0(void);
extern s32 func_00149ce0(void);
extern s32 func_00149d20(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 *func_004669d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_00457ce0(u8 *arg0, char *arg1);
extern s32 func_00457c90(u8 *arg0, char *arg1);
extern s32 func_00462ae0(void *arg0);
extern void func_003db550(u8 *arg0, u8 *arg1);
extern char D_005EFCE0[];
extern char D_005EFD00[];
extern char D_005EFD80[];
extern char D_005EFD98[];
extern char D_005EFDA8[];
extern char D_005EFDB8[];
extern char D_005EFDC8[];
extern char D_005EFDD8[];
extern char D_005EFDE8[];
extern char D_005EFE00[];
extern char D_005EFE10[];
extern char iGpffff9e10;
extern void func_00442428(char *dst, char *src);
extern s32 func_00477e80(s32 arg0, u16 arg1, char *arg2, s32 arg3);
extern s32 func_00477f10(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0014a230(s32 a0, s32 a1);
extern s32 func_0014a2a0(s32 a0, s32 a1);
extern u8 *func_0015c640(s32 a0, s32 a1);
extern u8 *func_00155280(void);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_0043c6b0(const char *arg0);
extern void func_00442830(char *dst, char *src);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern s8 D_00754D88[];
extern s32 func_0044ec30(void);
extern s32 func_003c0520(s32 arg0);
extern s32 func_00478750(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_00153300(s8 *arg0, f32 arg1);
extern void func_003e0380(f32 *arg0);
extern void func_003e03e0(void *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern u8 *func_003e0f80();
extern void func_003e0f40(void *arg0);
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 arg3);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_0047a180(void *arg0, f32 *arg1, s32 arg2);
extern s64 D_005EFE28[];
extern f32 D_005EFE30[];
extern char D_005EFC90[];
extern u8 D_005F0590[];
extern u8 D_005F0591[];
extern u8 D_005F05B8[];
extern s32 D_007E8060[];
extern u8 *iGpffff9db0;
extern s32 iGpffffb208;
extern void func_004b1250(s32 a, void *b);
extern void func_00454bd0(void *ptr);
extern u8 D_005EFD20[];
extern u8 D_005EFD40[];
extern u8 D_005EFD60[];
extern s64 D_005EFE38[];
extern f32 D_005EFE40[];
extern char D_005EFC60[];
extern u8 D_005EFC80[];
extern s32 iGpffffb200;   /* gp - 0x4E00 = 0x007642F0 */
extern s32 iGpffffb204;   /* gp - 0x4DFC = 0x007642F4 */
extern u8 iGpffff9df0;    /* gp - 0x6210 = 0x00762EE0 */

// FUN_0014EED0
void func_0014eed0(s32 arg0, s32 arg1)
{
    char path[0x40];

    if (iGpffffb200 == 0) {
        func_00442088(path, D_005EFC60, (u16)arg0, (u16)arg1);
        func_00440b68(&iGpffff9df0, D_005EFC80, 0x9E);
        iGpffffb200 = func_00454a60(path, 1);
    }
}

// FUN_0014EF40
s32 func_0014ef40(void)
{
    if (iGpffffb200 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb200) != 0;
}

// FUN_0014EF80
s32 func_0014ef80(void)
{
    if (iGpffffb204 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb204) != 0;
}

// FUN_0014EFC0
void func_0014efc0(s32 arg0, s32 arg1)
{
    char pad[0x80];
    u16 var_17;
    s32 var_2;
    s32 var_7;
    s32 var_16;

    *(s32 *)(iGpffff9db0 + 0x24) = 0;
    *(s32 *)(iGpffff9db0 + 0x94) = 0;
    func_0043f9c8(iGpffff9db0 + 0x9C, 0, 0x40);
    if (func_0014a230(arg0, arg1) != 0 || func_0014a2a0(arg0, arg1) != 0) {
        if (func_0014a2a0(arg0, arg1) != 0) {
            s32 temp_16;
            var_17 = (u16)((u16)arg0 - 0x14);
            *(s32 *)(iGpffff9db0 + 0x88) = *(s32 *)(iGpffff9db0 + 0x88) | 0x80000000;
            temp_16 = (s32)func_0015c640(arg0, arg1);
            *(s32 *)(func_00155280() + 0x1864) = temp_16;
            var_16 = D_005F0591[D_005F0590[(u16)var_17] * 0xC];
        } else {
            var_17 = (u16)arg0;
            var_16 = (u8)(*((u8 *)((s32)&D_005F0590 +
                (*((u8 *)((s32)&D_005F0590 + ((u16)var_17 & 0xFFFF))) * 0xC))));
        }
        if (*(s32 *)(iGpffff9db0 + 0x88) & 0x80000000) {
            if (iGpffffb204 == 0) {
                func_00442088(pad + 0x40, D_005EFC90, (s16)arg0, (s16)arg1);
                func_00440b68(&iGpffff9df0, D_005EFC80, 0xC9);
                iGpffffb204 = func_00454a60(pad + 0x40, 1);
            }
            var_2 = var_16 - 1;
            while (var_2 >= 0) {
                *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9C) = var_17;
                *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9E) =
                    (s16)*(s8 *)(D_005F0590 + D_005F05B8[(u16)var_17 - 0x28] * 0xC + var_2 + 2);
                *(s32 *)(iGpffff9db0 + 0x98) = *(s32 *)(iGpffff9db0 + 0x98) + 1;
                var_2 -= 1;
            }
        } else {
            *(s32 *)(iGpffff9db0 + 0x24) = var_16;
            var_7 = 0;
            while (var_7 < *(s32 *)(iGpffff9db0 + 0x24)) {
                *(s32 *)(iGpffff9db0 + var_7 * 4 + 0x28) = D_007E8060[var_7];
                var_7 += 1;
            }
            *(s32 *)(iGpffff9db0 + 0x94) = 4;
        }
    } else {
        if (iGpffffb204 == 0) {
            func_00442088(pad, D_005EFC90, (s16)arg0, (s16)arg1);
            func_00440b68(&iGpffff9df0, D_005EFC80, 0xC9);
            iGpffffb204 = func_00454a60(pad, 1);
        }
        *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9C) = (s16)arg0;
        *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9E) = (s16)arg1;
        *(s32 *)(iGpffff9db0 + 0x98) = *(s32 *)(iGpffff9db0 + 0x98) + 1;
    }
    iGpffffb208 = func_0044ec30();
}
// FUN_0014F310
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014f310);

// FUN_00150970
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150970);

// FUN_00150C80
s32 func_00150c80(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80);
    if (p == NULL) {
        return 1;
    }
    if (iGpffffb204 == 0) {
        return func_004553c0((s32)p) != 0;
    }
    return 1;
}

// FUN_00150CE0
void func_00150ce0(u8 *arg0)
{
    s32 sp54;
    s32 sp7C;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp50;
    s32 temp_2;
    s32 temp_2_3;
    s32 temp_2_2;

    temp_2 = func_00455f70(*(u8 **)(arg0 + 0xA44), &sp7C);
    sp70 = temp_2;
    sp74 = sp7C;
    if (temp_2 != 0) {
        temp_2_2 = func_003e2f60(3, 1, &sp70);
        if (temp_2_2 != 0) {
loop_17:
            if (func_003df3c0(temp_2_2, &sp50) != 0) {
                switch (sp50) {
                case 11:
                    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) +
                                 *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C) * 4 + 0x90) == 0) {
                        sp68 = sp70 + *(s32 *)((u8 *)temp_2_2 + 0xC);
                    }
                    sp6C = sp74;
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) +
                             *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C) * 4 + 0x90) =
                        func_004667d0(1, 0, 0, 0, func_003e2f60(3, 1, &sp68), 0, 0, 0, 0, 0);
                    func_003e2ce0(temp_2_2, sp54);
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C) =
                        *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C) + 1;
                    break;
                case 16:
                    sp68 = sp70 + *(s32 *)((u8 *)temp_2_2 + 0xC);
                    sp6C = sp74;
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) +
                             *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0) * 4 + 0xA4) =
                        func_004667d0(2, 0, 0, 0, func_003e2f60(3, 1, &sp68), 0, 0, 0, 0, 0);
                    func_003e2ce0(temp_2_2, sp54);
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0) =
                        *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0) + 1;
                    break;
                case 35:
                    temp_2_3 = func_003dc370((void *)temp_2_2);
                    func_003ef260(temp_2_3, func_00463100,
                                  *(u8 **)(arg0 + 0xA44) + 0x128);
                    func_003ef1b0(temp_2_3);
                    break;
                case 22:
                    sp68 = sp70 + *(s32 *)((u8 *)temp_2_2 + 0xC);
                    sp6C = sp74;
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) =
                        func_004667d0(8, 0, 0, 0, func_003e2f60(3, 1, &sp68), 0, 0, 0, 0, 0);
                    func_003e2ce0(temp_2_2, sp54);
                    break;
                case 12:
                    sp68 = sp70 + *(s32 *)((u8 *)temp_2_2 + 0xC);
                    sp6C = sp74;
                    *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) =
                        func_004667d0(0xB, 0, 0, 0, func_003e2f60(3, 1, &sp68), 0, 0, 0, 0, 0);
                    func_003e2ce0(temp_2_2, sp54);
                    break;
                default:
                    func_003e2ce0(temp_2_2, sp54);
                    break;
                }
                goto loop_17;
            }
            if (temp_2_2 != 0) {
                func_003e2e40(temp_2_2, 0);
            }
        } else {
            if (*(u8 **)(arg0 + 0xA44) != NULL) {
                func_00454bd0(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80));
                jtbl_008873EC[0](*(u8 **)(arg0 + 0xA44));
            }
            if (arg0 != NULL) {
                jtbl_008873EC[0](arg0);
            }
        }
    }
}

// FUN_001510C0
s32 func_001510c0(u8 *arg0)
{
    s32 sp6C;
    s32 sp68;
    s32 var_16;
    u32 var_20;
    s32 temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u32 var_19;

    var_16 = 0;
    if (*(u8 **)(arg0 + 0xA44) == NULL) {
        return 1;
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) != 0) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
            func_0046d730((const char *)D_005EFC80, 0x56C);
        }
        temp_18 = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84), &sp68, &sp6C);
        if (sp68 == 1) {
            func_003ef260(temp_18, func_00463100, *(u8 **)(arg0 + 0xA44) + 0x128);
            func_003ef1b0(temp_18);
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) = 0;
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
        } else {
            var_16 += 1;
        }
    }
    for (var_20 = 0; var_20 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C); var_20++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) != 0) {
            temp_19 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_19 == NULL) {
                    func_0046d730((const char *)D_005EFC80, 0x588);
                }
                if (func_00457ce0(temp_19, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_19;
                } else if (func_00457ce0(temp_19, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_19;
                } else if (*(s32 *)(arg0 + 0xC) == 0) {
                    *(s32 *)(arg0 + 0xC) = (s32)temp_19;
                    func_003db550(temp_19, func_00457120());
                } else {
                    *(s32 *)(arg0 + 8) = (s32)temp_19;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) = 0;
                *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 1;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    for (var_19 = 0; var_19 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0); var_19++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) != 0) {
            temp_20 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_20 == NULL) {
                    func_0046d730((const char *)D_005EFC80, 0x5B4);
                }
                if (func_00457c90(temp_20, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_20;
                } else if (func_00457c90(temp_20, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_20;
                } else if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 8) == 0) {
                    *(s32 *)(arg0 + 8) = (s32)temp_20;
                    *(s32 *)(arg0 + 0xC) = func_00462ae0(temp_20);
                } else {
                    *(s32 *)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x1C) = (s32)temp_20;
                    *(s32 *)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x9C) = func_00462ae0(temp_20);
                    *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) + 1;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) = 0;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) != 0) {
        *(s32 *)(arg0 + 0xA20) = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124), &sp68, &sp6C);
        if (sp68 == 1) {
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
            if (*(s32 *)(arg0 + 0xA20) == 0) {
                func_0046d730((const char *)D_005EFC80, 0x5D9);
            }
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) = 0;
        } else {
            var_16 += 1;
        }
    }
    if (var_16 == 0) {
        if (*(s32 *)(arg0 + 8) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
            *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 0xC);
        }
        if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 0x18) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
        }
        if (iGpffffb204 == 0) {
            func_00454bd0(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80));
        }
        *(s32 *)(arg0 + 0xA24) = 0x3F800000;
        *(s32 *)(arg0 + 0xA28) = 0x3F800000;
        *(s32 *)(arg0 + 0xA2C) = 0x3F800000;
        return 1;
    }
    return 0;
}

// FUN_00151580
s32 func_00151580(u8 *arg0, s32 arg1, s32 *arg2)
{
    s32 spA8[2];
    s32 spA0[2];
    s32 sp98[2];
    s32 var_17;
    s32 var_16;
    u8 *temp_21;
    s32 var_22;
    s32 temp_23;

    var_22 = 0;
    for (var_17 = 0; var_17 < *(u32 *)(arg0 + 0x18); var_17++) {
        temp_21 = arg0 + var_17 * 4;
        temp_23 = func_004581a0(*(void **)(temp_21 + 0x1C), (const char *)D_005EFD20);
        for (var_16 = 0; var_16 < temp_23; var_16++) {
            func_00458430(spA0, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD40, var_16);
            if (spA0[0] == 0) {
                func_0046d730((const char *)D_005EFC80, 0x622);
            }
            func_00458430(spA8, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD20, var_16);
            func_00458430(sp98, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD60, var_16);
            if (sp98[0] != 0) {
                *arg2 = 1;
            } else {
                *arg2 = 0;
            }
            if (spA8[0] != 1 && arg1 == spA0[0]) {
                var_22 = spA8[1];
                goto out;
            }
        }
    }
out:
    return var_22;
}

// FUN_00151710
void func_00151710(u8 *arg0)
{
    s32 temp_16;
    u8 *temp_17;
    u32 var_19;
    s32 var_18;
    s32 sp20C;
    s32 sp208;
    s32 sp200[2];
    s32 sp1F8[2];
    s32 sp1F0[2];
    s32 sp1E8[2];
    s32 sp1E0[2];
    char sp1A0[0x40];
    char sp160[0x40];
    char sp120[0x40];
    char spE0[0x40];
    char spA0[0x40];
    char sp60[0x40];
    s32 r;

    for (var_19 = 0; var_19 < *(u32 *)(arg0 + 0x18); var_19++) {
        temp_17 = arg0 + var_19 * 4;
        temp_16 = func_004581a0(*(void **)(temp_17 + 0x1C), (const char *)D_005EFD20);
        for (var_18 = 0; var_18 < temp_16; var_18++) {
            func_00458430(sp1F8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD80, var_18);
            if (sp1F8[0] != 0) {
                func_00458430(sp1E8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD40, var_18);
                if (sp1E8[0] == 0) {
                    func_0046d730((const char *)D_005EFC80, 0x65A);
                }
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x124) = (u16)sp1E8[0];
                func_00458430(sp1E0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD60, var_18);
                if (sp1E0[0] != 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) = 2;
                }
                func_00458430(sp200, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD20, var_18);
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x120) = (u16)sp200[0];
                if (sp200[0] == 0) {
                    if (iGpffffb204 == 0) {
                        func_00442830(sp1A0, D_005EFD98);
                        func_00442088(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp1A0, sp160);
                        func_00442088(sp160, D_005EFDA8, sp1F8[0]);
                        func_00442428(sp1A0, sp160);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477e80(4, (u16)sp1F8[0], sp1A0, 0);
                    } else {
                        func_00442830(sp1A0, D_005EFDB8);
                        func_00442088(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp1A0, sp160);
                        func_00442088(sp160, D_005EFDA8, sp1F8[0]);
                        func_00442428(sp1A0, sp160);
                        r = func_00455f70(sp1A0, &sp20C);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477f10(4, (u16)sp1F8[0], r, sp20C, 0);
                    }
                } else if (sp200[0] == 1) {
                    if (iGpffffb204 == 0) {
                        func_00442830(sp120, D_005EFDC8);
                        func_00442088(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp120, spE0);
                        func_00442088(spE0, D_005EFDD8, sp1F8[0]);
                        func_00442428(sp120, spE0);
                        func_00440b68(&iGpffff9df0, D_005EFC80, 0x6A1);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00454a60(sp120, 0);
                        if (*(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) == 0) {
                            func_0046d730((const char *)D_005EFC80, 0x6A2);
                        }
                    } else {
                        func_00442830(sp120, D_005EFDE8);
                        func_00442088(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp120, spE0);
                        func_00442088(spE0, D_005EFDD8, sp1F8[0]);
                        func_00442428(sp120, spE0);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00455f70(sp120, &sp208);
                    }
                } else if (sp200[0] == 2) {
                    func_00442830(spA0, D_005EFE00);
                    func_00442088(sp60, D_005EFDA8, sp1F8[0]);
                    func_00442428(spA0, sp60);
                    *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477e80(4, (u16)(sp1F8[0] + 0x3E8), spA0, 0);
                }
                func_00458430(sp1F0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFE10, var_18);
                if (sp200[0] == 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) |= (u16)sp1F0[0];
                }
                *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x128) = sp200[1];
                *(u32 *)(arg0 + 0x11C) = *(u32 *)(arg0 + 0x11C) + 1;
            }
        }
    }
}

// FUN_00151C80
s32 func_00151c80(u8 *arg0)
{
    u32 i;
    u32 j;

    for (i = 0; i < *(u32 *)(arg0 + 0x11C); i++) {
        if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + i * 0x18 + 0x120) == 2) {
            if (*(u32 *)(arg0 + i * 0x18 + 0x12C) == 0) {
                func_0046d730((const char *)D_005EFC80, 0x6E4);
            }
            if (func_004782b0(*(u32 *)(arg0 + i * 0x18 + 0x12C)) == 0) {
                return 0;
            }
        } else if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0 && *(u8 **)(arg0 + i * 0x18 + 0x134) != NULL && func_004553c0((s32)*(u8 **)(arg0 + i * 0x18 + 0x134)) == 0) {
                return 0;
            }
        }
    }
    for (j = 0; j < *(u32 *)(arg0 + 0x11C); j++) {
        if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + j * 0x18 + 0x120) == 2) {
            func_0047a1c0(*(void **)(arg0 + j * 0x18 + 0x12C), func_003e9700(*(u8 **)(arg0 + j * 0x18 + 0x128)), 0);
            if (*(u16 *)(arg0 + j * 0x18 + 0x122) & 1) {
                func_0047a0e0(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0.0f);
            } else {
                func_00479940(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0, 8, 1);
            }
        } else if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0) {
                if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                    *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130(*(u32 *)(*(u8 **)(arg0 + j * 0x18 + 0x134) + 0x110));
                    func_004b1250(*(s32 *)(arg0 + j * 0x18 + 0x130), func_003e9700(*(u8 **)(arg0 + j * 0x18 + 0x128)) + 0x30);
                    func_00454bd0(*(u8 **)(arg0 + j * 0x18 + 0x134));
                    *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
                }
            } else if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130((s32)*(u8 **)(arg0 + j * 0x18 + 0x134));
                func_004b1250(*(s32 *)(arg0 + j * 0x18 + 0x130), func_003e9700(*(u8 **)(arg0 + j * 0x18 + 0x128)) + 0x30);
                *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
            }
        }
    }
    if (*(u8 **)(arg0 + 0xA44) != NULL) {
        if (*(s16 *)(arg0 + 4) >= 0x28 && *(s16 *)(arg0 + 4) < 0x31) {
            if (*(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
                *(s32 *)(iGpffff9db0 + 0x8C) = *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128);
            }
        } else {
            func_00463250(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x128));
        }
        jtbl_008873EC[0](*(u8 **)(arg0 + 0xA44));
        *(u8 **)(arg0 + 0xA44) = NULL;
    }
    return 1;
}

// FUN_00151F80
void func_00151f80(u8 *arg0)
{
    s32 temp_4;
    u32 var_16;
    u32 var_18;
    u8 *temp_16;
    u8 *temp_4_8;

    if (*(u32 *)arg0 & 1) {
        temp_4 = *(s32 *)(arg0 + 8);
        if (temp_4 != 0 && temp_4 != *(s32 *)(arg0 + 0xC)) {
            func_003c9d40((void *)temp_4);
        }
        if (*(s32 *)(arg0 + 0xC) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0xC));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x14));
        }
    } else {
        func_00462bf0((void *)*(s32 *)(arg0 + 0xC));
        if (*(s32 *)(arg0 + 8) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 8));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x14));
        }
    }
    for (var_18 = 0; var_18 < *(u32 *)(arg0 + 0x18); var_18++) {
        temp_16 = arg0 + var_18 * 4;
        func_00462bf0((void *)*(s32 *)(temp_16 + 0x9C));
        func_003c0700((void *)*(s32 *)(temp_16 + 0x1C));
    }
    for (var_16 = 0; var_16 < *(u32 *)(arg0 + 0x11C); var_16++) {
        temp_4_8 = arg0 + var_16 * 0x18;
        if (*(u16 *)(temp_4_8 + 0x120) == 0 || *(u16 *)(temp_4_8 + 0x120) == 2) {
            func_004787e0(*(s32 *)(temp_4_8 + 0x12C));
        } else if (*(u16 *)(temp_4_8 + 0x120) == 1) {
            func_004b1150(*(s32 *)(temp_4_8 + 0x130));
        }
    }
    if (*(s32 *)(arg0 + 0xA20) != 0) {
        func_003bbb60((void *)*(s32 *)(arg0 + 0xA20));
    }
    if (*(s32 *)(arg0 + 0xA40) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0xA40));
    }
    jtbl_008873EC[0](arg0);
}

// FUN_00152170
void func_00152170(u8 *arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_18_4;
    s32 temp_18_5;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_4;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_18_3;
    u8 *temp_2;
    u8 *temp_2_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_g0;
    f32 temp_g1;
    f32 temp_g2;
    f32 temp_g3;
    u8 *var_5;
    u8 *var_6;

    temp_16 = (s32)func_00457120();
    {
        void (*state)(u32, u32);
        state = D_00887300[0];
        state(0x14, 2);
    }
    func_003e8110((void *)temp_16);
    temp_2 = func_004571a0();
    temp_f2 = *(f32 *)(temp_2 + 0x18);
    temp_f1 = *(f32 *)(temp_2 + 0x1C);
    temp_f0 = *(f32 *)(temp_2 + 0x20);
    temp_f3 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0xA50) = temp_f2;
    *(f32 *)(arg1 + 0xA54) = temp_f1;
    *(f32 *)(arg1 + 0xA58) = temp_f0;
    *(f32 *)(arg1 + 0xA5C) = temp_f3;
    temp_2_2 = func_004571b0();
    temp_g2 = *(f32 *)(temp_2_2 + 0x18);
    temp_g1 = *(f32 *)(temp_2_2 + 0x1C);
    temp_g0 = *(f32 *)(temp_2_2 + 0x20);
    temp_g3 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0xA60) = temp_g2;
    *(f32 *)(arg1 + 0xA64) = temp_g1;
    *(f32 *)(arg1 + 0xA68) = temp_g0;
    *(f32 *)(arg1 + 0xA6C) = temp_g3;
    var_6 = *(u8 **)(func_004571b0() + 4) + 0x10;
    var_5 = arg1 + 0xA70;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)(var_6 + 0);
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)(var_5 + 0) = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    if (func_00149ca0() != 0) {
        temp_18 = func_004571a0();
        func_003c38b0(temp_18, (void *)func_00149ca0());
        temp_18_2 = func_004571b0();
        func_003c38b0(temp_18_2, (void *)func_00149ce0());
        temp_18_3 = func_004571b0();
        func_003e9cb0(*(void **)(temp_18_3 + 4), (void *)func_00149d20(), 0);
    }
    *(s8 *)(func_004571b0() + 2) = 3;
    func_004571b0();
    if (*(u32 *)arg1 & 1) {
        func_003cbc60((s32)func_00457190(), (void *)temp_16);
        temp_3_2 = *(s32 *)arg1;
        if (temp_3_2 & 0x80000000) {
            func_003cbc10(*(void **)(arg1 + 0xC), (void *)temp_16);
        } else if (temp_3_2 & 0x40000000) {
            temp_4 = *(s32 *)(arg1 + 0x10);
            if (temp_4 != 0) {
                func_003cbc10((void *)temp_4, (void *)temp_16);
            }
        } else if (temp_3_2 & 0x20000000) {
            temp_4_2 = *(s32 *)(arg1 + 0x14);
            if (temp_4_2 != 0) {
                func_003cbc10((void *)temp_4_2, (void *)temp_16);
            }
        } else {
            func_003cbc10(*(void **)(arg1 + 8), (void *)temp_16);
        }
        temp_18_4 = (s32)func_00457190();
        func_003cbf30(temp_18_4, func_004571a0());
        temp_18_5 = (s32)func_00457190();
        func_003cbf30(temp_18_5, func_004571b0());
        temp_3_3 = *(s32 *)arg1;
        if (temp_3_3 & 0x80000000) {
            func_003cbe80(*(void **)(arg1 + 0xC), func_004571a0());
            func_003cbe80(*(void **)(arg1 + 0xC), func_004571b0());
        } else if (temp_3_3 & 0x40000000) {
            func_003cbe80(*(void **)(arg1 + 0x10), func_004571a0());
            func_003cbe80(*(void **)(arg1 + 0x10), func_004571b0());
        } else if ((temp_3_3 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbe80(*(void **)(arg1 + 0x14), func_004571a0());
            func_003cbe80(*(void **)(arg1 + 0x14), func_004571b0());
        } else {
            func_003cbe80(*(void **)(arg1 + 8), func_004571a0());
            func_003cbe80(*(void **)(arg1 + 8), func_004571b0());
        }
    } else {
        temp_17 = (s32)func_00457190();
        func_003cbf30(temp_17, func_004571c0());
    }
    func_003e8120((void *)temp_16);
    D_00887300[0](6, 1);
    D_00887300[0](8, 1);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    D_00887300[0](0x14, 2);
    if (iGpffffba48 == 1) {
        D_00887300[0](0xE, 1);
        D_00887300[0](0xF, (u32)iGpffffba54 | ((u32)iGpffffba50 << 8) |
                             ((u32)iGpffffba58 << 0x18) | ((u32)iGpffffba4c << 0x10));
        D_00887300[0](0x10, 1);
    }
}

// FUN_00152630
void func_00152630(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_18_3;

    temp_2 = func_00457120();
    func_003e8110(temp_2);
    if (*(u32 *)arg1 & 1) {
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbf30(*(s32 *)(arg1 + 0xC), func_004571a0());
            func_003cbf30(*(s32 *)(arg1 + 0xC), func_004571b0());
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbf30(*(s32 *)(arg1 + 0x10), func_004571a0());
            func_003cbf30(*(s32 *)(arg1 + 0x10), func_004571b0());
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbf30(*(s32 *)(arg1 + 0x14), func_004571a0());
            func_003cbf30(*(s32 *)(arg1 + 0x14), func_004571b0());
        } else {
            func_003cbf30(*(s32 *)(arg1 + 8), func_004571a0());
            func_003cbf30(*(s32 *)(arg1 + 8), func_004571b0());
        }
        temp_18 = func_00457190();
        func_003cbe80(temp_18, func_004571a0());
        temp_18_2 = func_00457190();
        func_003cbe80(temp_18_2, func_004571b0());
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbc60(*(s32 *)(arg1 + 0xC), temp_2);
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbc60(*(s32 *)(arg1 + 0x10), temp_2);
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbc60(*(s32 *)(arg1 + 0x14), temp_2);
        } else {
            func_003cbc60(*(s32 *)(arg1 + 8), temp_2);
        }
        func_003cbc10(func_00457190(), temp_2);
    } else {
        temp_18_3 = func_00457190();
        func_003cbe80(temp_18_3, func_004571c0());
    }
    func_003c38b0(func_004571a0(), arg1 + 0xA50);
    func_003c38b0(func_004571b0(), arg1 + 0xA60);
    func_003e9cb0((void *)*(s32 *)(func_004571b0() + 4), arg1 + 0xA70, 0);
    *(s8 *)(func_004571b0() + 2) = 3;
    func_004571b0();
    func_003e8120(temp_2);
}

// FUN_00152930
void func_00152930(u8 *arg0, u8 *arg1)
{
    u8 *var_2;
    u8 *var_6;
    u8 *p2;
    s32 temp_3;
    u32 flags;
    u32 i;

    var_6 = NULL;
    flags = *(u32 *)arg1;
    if (flags & 1) {
        temp_3 = *(s32 *)(arg1 + 8);
        if (temp_3 != 0) {
            if (flags & 0x80000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0xC));
            } else if (flags & 0x40000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x10));
            } else if ((flags & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x14));
            } else {
                var_2 = func_00461290(arg0, temp_3);
            }
            *(void (**)(void))(var_2 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_2 + 0x10) = arg1;
            *(void (**)(void))(var_2 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_2 + 0x14) = arg1;
        }
    } else {
        if (flags & 0x80000000) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00460e80(arg0, *(s32 *)(arg1 + 0xC));
            } else {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 8));
            }
        } else if (flags & 0x40000000) {
            var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
        } else if (flags & 0x20000000) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(s32 *)(arg1 + 0x9C + i * 4) != 0) {
                p2 = func_00460e80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
            } else {
                p2 = func_00461180(arg0, *(s32 *)(arg1 + 0x1C + i * 4));
            }
            if (p2 != NULL && i == 0) {
                *(void (**)(void))(p2 + 8) = (void (*)(void))func_00152170;
                *(u8 **)(p2 + 0x10) = arg1;
            }
            if (p2 != NULL && i == *(u32 *)(arg1 + 0x18) - 1) {
                *(void (**)(void))(p2 + 0xC) = (void (*)(void))func_00152630;
                *(u8 **)(p2 + 0x14) = arg1;
            }
        }
    }
}

// FUN_00152BB0
void func_00152bb0(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000) && *(u8 **)(arg1 + 0xC) != NULL) {
            var_6 = func_00460f80(arg0, *(s32 *)(arg1 + 0xC));
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00460f80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00152170;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))func_00152630;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

// FUN_00152CD0
void func_00152cd0(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000)) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00461080(arg0, *(s32 *)(arg1 + 0xC));
            }
        } else if ((*(u32 *)arg1 & 0x40000000)) {
            if (*(s32 *)(arg1 + 0x10) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
            }
        } else if ((*(u32 *)arg1 & 0x20000000)) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00461080(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00152170;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))func_00152630;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

// FUN_00152E50
void func_00152e50(s8 *arg0, u8 *arg1, f32 fparg0)
{
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF0[4];
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD0[4];
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB0[4];
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp90[4];
    f32 sp88;
    s64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    u16 temp_4;
    u32 var_16;
    u32 var_16_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_17;
    u8 *temp_20;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_5;

    if (!(*(s32 *)arg0 & 1)) {
        temp_3 = *(u8 **)(arg0 + 8);
        if (temp_3 != NULL) {
            temp_16 = *(u8 **)(temp_3 + 4);
            temp_2 = func_003e9700(temp_16);
            sp100 = *(f32 *)(temp_2 + 0x30);
            sp104 = *(f32 *)(temp_2 + 0x34);
            sp108 = *(f32 *)(temp_2 + 0x38);
            sp100 += *(f32 *)(arg1 + 0);
            sp104 += *(f32 *)(arg1 + 4);
            temp_f0 = sp108 + *(f32 *)(arg1 + 8);
            sp108 = temp_f0;
            *(f32 *)(temp_16 + 0x40) = sp100;
            *(f32 *)(temp_16 + 0x44) = sp104;
            *(f32 *)(temp_16 + 0x48) = temp_f0;
            func_003e0380(spF0);
            func_003e03e0(temp_16 + 0x10, spF0);
            func_003e9680(temp_16);
        }
        temp_3_2 = *(u8 **)(arg0 + 0x10);
        if (temp_3_2 != NULL) {
            temp_16_2 = *(u8 **)(temp_3_2 + 4);
            temp_2_2 = func_003e9700(temp_16_2);
            spE0 = *(f32 *)(temp_2_2 + 0x30);
            spE4 = *(f32 *)(temp_2_2 + 0x34);
            spE8 = *(f32 *)(temp_2_2 + 0x38);
            spE0 += *(f32 *)(arg1 + 0);
            spE4 += *(f32 *)(arg1 + 4);
            temp_f0_2 = spE8 + *(f32 *)(arg1 + 8);
            spE8 = temp_f0_2;
            *(f32 *)(temp_16_2 + 0x40) = spE0;
            *(f32 *)(temp_16_2 + 0x44) = spE4;
            *(f32 *)(temp_16_2 + 0x48) = temp_f0_2;
            func_003e0380(spD0);
            func_003e03e0(temp_16_2 + 0x10, spD0);
            func_003e9680(temp_16_2);
        }
        temp_3_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3_3 != NULL) {
            temp_16_3 = *(u8 **)(temp_3_3 + 4);
            temp_2_3 = func_003e9700(temp_16_3);
            spC0 = *(f32 *)(temp_2_3 + 0x30);
            spC4 = *(f32 *)(temp_2_3 + 0x34);
            spC8 = *(f32 *)(temp_2_3 + 0x38);
            spC0 += *(f32 *)(arg1 + 0);
            spC4 += *(f32 *)(arg1 + 4);
            temp_f0_3 = spC8 + *(f32 *)(arg1 + 8);
            spC8 = temp_f0_3;
            *(f32 *)(temp_16_3 + 0x40) = spC0;
            *(f32 *)(temp_16_3 + 0x44) = spC4;
            *(f32 *)(temp_16_3 + 0x48) = temp_f0_3;
            func_003e0380(spB0);
            func_003e03e0(temp_16_3 + 0x10, spB0);
            func_003e9680(temp_16_3);
        }
    }
    var_16 = 0;
    while (var_16 < *(u32 *)(arg0 + 0x18)) {
        temp_3_4 = *(u8 **)(arg0 + var_16 * 4 + 0x1C);
        if (temp_3_4 != NULL) {
            temp_17 = *(u8 **)(temp_3_4 + 4);
            temp_2_4 = func_003e9700(temp_17);
            spA0 = *(f32 *)(temp_2_4 + 0x30);
            spA4 = *(f32 *)(temp_2_4 + 0x34);
            spA8 = *(f32 *)(temp_2_4 + 0x38);
            spA0 += *(f32 *)(arg1 + 0);
            spA4 += *(f32 *)(arg1 + 4);
            temp_f0_4 = spA8 + *(f32 *)(arg1 + 8);
            spA8 = temp_f0_4;
            *(f32 *)(temp_17 + 0x40) = spA0;
            *(f32 *)(temp_17 + 0x44) = spA4;
            *(f32 *)(temp_17 + 0x48) = temp_f0_4;
            func_003e0380(sp90);
            func_003e03e0(temp_17 + 0x10, sp90);
            func_003e9680(temp_17);
        }
        var_16 += 1;
    }
    var_16_2 = 0;
    while (var_16_2 < *(u32 *)(arg0 + 0x11C)) {
        temp_5 = (u8 *)arg0 + var_16_2 * 0x18;
        temp_4 = *(u16 *)(temp_5 + 0x120);
        switch (temp_4) {
        case 0:
        case 2:
            func_0047a180(*(void **)(temp_5 + 0x12C), (f32 *)arg1, 2);
            break;
        case 1:
            sp80 = D_005EFE28[0];
            sp88 = D_005EFE30[0];
            temp_2_5 = func_003e0f80(temp_4, temp_5);
            *(s32 *)(temp_2_5 + 0x28) = 0x3F800000;
            *(s32 *)(temp_2_5 + 0x14) = 0x3F800000;
            *(s32 *)(temp_2_5 + 0) = 0x3F800000;
            *(s32 *)(temp_2_5 + 0x10) = 0;
            *(s32 *)(temp_2_5 + 8) = 0;
            *(s32 *)(temp_2_5 + 4) = 0;
            *(s32 *)(temp_2_5 + 0x24) = 0;
            *(s32 *)(temp_2_5 + 0x20) = 0;
            *(s32 *)(temp_2_5 + 0x18) = 0;
            *(s32 *)(temp_2_5 + 0x38) = 0;
            *(s32 *)(temp_2_5 + 0x34) = 0;
            *(s32 *)(temp_2_5 + 0x30) = 0;
            *(s32 *)(temp_2_5 + 0xC) =
                *(s32 *)(temp_2_5 + 0xC) | 0x20003;
            func_003e0870(temp_2_5, &sp80, 2, fparg0);
            temp_20 = (u8 *)arg0 + var_16_2 * 0x18;
            temp_2_6 = func_003e9700(*(u8 **)(temp_20 + 0x128));
            sp70 = *(f32 *)(temp_2_6 + 0x30);
            sp74 = *(f32 *)(temp_2_6 + 0x34);
            sp78 = *(f32 *)(temp_2_6 + 0x38);
            func_003e42a0(&sp70, &sp70, temp_2_5);
            sp70 += *(f32 *)(arg1 + 0);
            sp74 += *(f32 *)(arg1 + 4);
            sp78 += *(f32 *)(arg1 + 8);
            func_004b1250(*(s32 *)(temp_20 + 0x130), &sp70);
            func_003e0f40(temp_2_5);
            break;
        }
        var_16_2 += 1;
    }
}

/* measured: 00153300 archive body is 416B/416B with normalized_diff 4; */
/* declaration-form probes are archived in build/L153_00153300_body.c; no C body was retained. */
// FUN_00153300 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00153300);

// FUN_001534A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001534a0);

