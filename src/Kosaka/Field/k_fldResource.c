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
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
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
extern void func_004b1250(s32 a, void *b);
extern u8 *iGpffff9db0;
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
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014efc0);
// FUN_0014F310
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014f310);
/* measured: opt_loop_invariants hoists the slash loop constant. */
#pragma push
#pragma opt_loop_invariants on

// FUN_00150970
u8 *func_00150970(char *arg0)
{
    u32 base;
    u8 *resource;
    u8 *work;
    s32 valid = 1;
    struct {
        char token[4];
        char pad[4];
    } local;

    func_0044ea90(D_005EFC80, 0x460);
    base = (u32)D_008873F4;
    resource = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0xAB0, 0x40000);
    if (resource == NULL) {
        return resource;
    }
    func_0044ea90(D_005EFC80, 0x462);
    work = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0x12C, 0x40000);
    *(u8 **)(resource + 0xA44) = work;
    if (work == NULL) {
        jtbl_008873EC[0](resource);
        return NULL;
    }
    func_00442830((char *)work, arg0);
    while (*arg0 != '\0') {
        arg0++;
    }
    for (; *arg0 != '/'; arg0--) {
    }
    if (arg0[1] == 'f') {
        if ((D_00754D88[(s8)arg0[2]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[3]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[4]] & 4) == 0) {
            valid = 0;
        }
        if (arg0[5] != '_') {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[6]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[7]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[8]] & 4) == 0) {
            valid = 0;
        }
    } else {
        valid = 0;
    }
    if (valid) {
        local.token[0] = arg0[2];
        local.token[1] = arg0[3];
        local.token[2] = arg0[4];
        local.token[3] = '\0';
        *(u16 *)(resource + 4) = (u16)func_0043c6b0(local.token);
        local.token[0] = arg0[6];
        local.token[1] = arg0[7];
        local.token[2] = arg0[8];
        local.token[3] = '\0';
        *(u16 *)(resource + 6) = (u16)func_0043c6b0(local.token);
    } else {
        *(s16 *)(resource + 4) = -1;
        *(s16 *)(resource + 6) = -1;
    }
    if (iGpffffb204 == 0) {
        func_00440b68(&iGpffff9df0, D_005EFC80, 0x4A5);
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) =
            func_00454a60(*(char **)(resource + 0xA44), 0);
    } else {
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) = 1;
    }
    return resource;
}
#pragma pop

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
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150ce0);

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
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152170);

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
            *(void (**)(void))(var_2 + 8) = func_00152170;
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
            *(void (**)(void))(var_6 + 8) = func_00152170;
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
                *(void (**)(void))(p2 + 8) = func_00152170;
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
            *(void (**)(void))(var_6 + 8) = func_00152170;
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
                    *(void (**)(void))(temp_2 + 8) = func_00152170;
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
            *(void (**)(void))(var_6 + 8) = func_00152170;
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
                    *(void (**)(void))(temp_2 + 8) = func_00152170;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))func_00152630;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

// FUN_00152E50
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152e50);

/* measured: opt_propagation off preserves the named scalar global loads; this scalar pair copy suppresses aggregate ld/sd traffic. */
#pragma push
#pragma opt_propagation off
#define COPY_SCALAR_PAIR(dst, src) \
do { \
    s64 copy_s64; \
    f32 copy_f32; \
    copy_s64 = (src).sp40; \
    copy_f32 = (src).sp48; \
    (dst).sp40 = copy_s64; \
    (dst).sp48 = copy_f32; \
} while (0)
// FUN_00153300
void func_00153300(s8 *arg0, f32 fparg0)
{
    extern void func_003e9d50(s32 a0, void *a1, f32 f12, s32 a3);
    extern void func_0047a1a0(void *a0, void *a1, f32 f12, s32 a2);
    void *ptr;
    struct {
        s64 sp40;
        f32 sp48;
    } sp;
    u16 temp_4;
    u32 var_16;
    u32 var_16_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_5;

    ptr = &sp.sp40;
    COPY_SCALAR_PAIR(sp, *(typeof(sp) *)D_005EFE38);
    if (!(*(u32 *)arg0 & 1)) {
        temp_3 = *(u8 **)(arg0 + 8);
        if (temp_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3 + 4), ptr, fparg0, 2);
        }
        temp_3_2 = *(u8 **)(arg0 + 0x10);
        if (temp_3_2 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_2 + 4), &sp.sp40, fparg0, 2);
        }
        temp_3_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_3 + 4), &sp.sp40, fparg0, 2);
        }
    }
    var_16 = 0;
    goto loop_test_11;
loop_body_11:
    temp_3_4 = *(u8 **)(arg0 + var_16 * 4 + 0x1C);
    if (temp_3_4 != NULL) {
        func_003e9d50(*(s32 *)(temp_3_4 + 4), &sp.sp40, fparg0, 2);
    }
    var_16 += 1;
loop_test_11:
    if (var_16 < *(u32 *)(arg0 + 0x18)) {
        goto loop_body_11;
    }
    var_16_2 = 0;
    goto loop_test_19;
loop_body_19:
    temp_5 = (u8 *)arg0 + var_16_2 * 0x18;
    temp_4 = *(u16 *)(temp_5 + 0x120);
    if (temp_4 == 0) {
        goto switch_body_a;
    }
    if (temp_4 != 2) {
        goto switch_case_1_test;
    }
switch_body_a:
    func_0047a1a0((void *)(*(s32 *)(temp_5 + 0x12C)), &sp.sp40, fparg0, 2);
    goto switch_end;
switch_case_1_test:
    if (temp_4 != 1) {
        goto switch_end;
    }
    func_004b1290(*(s32 *)(temp_5 + 0x130), 0.0f, fparg0, 0.0f);
switch_end:
    ;
    var_16_2 += 1;
loop_test_19:
    if (var_16_2 < *(u32 *)(arg0 + 0x11C)) {
        goto loop_body_19;
    }
}
/* measured: restore propagation after func_00153300. */
#pragma pop

// FUN_001534A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001534a0);

