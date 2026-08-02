#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00442088(char *dst, char *fmt, u16 a, u16 b);
extern void func_00440b68(u8 *msg, u8 *file, s32 line);
extern s32 func_00454a60(char *path, s32 mode);
extern s32 func_004553c0(s32 handle);
extern u8 *func_00460f80(u8 *list, s32 arg1);
extern u8 *func_00461080(u8 *list, s32 arg1);
extern u8 *func_00461180(u8 *list, s32 arg1);
extern void func_00152170();
extern void func_00152630();
extern s32 func_004581a0(void *object, const char *name);
extern void func_00458430(s32 *out, void *object, const char *name, s32 index);
extern void func_0046d730(const char *file, s32 line);
extern void func_003e9d50(s32 a0, void *a1, f32 a2, s32 a3);
extern void func_0047a1a0(void *a0, void *a1, f32 f12, s32 a2);
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
extern void func_004b1250(s32 a, void *b);
extern void func_00454bd0(void *ptr);
extern u32 PTR_DAT_00762ea0;
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
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150ce0);

// FUN_001510C0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001510c0);

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
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151710);

// FUN_00151C80
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151c80);

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

/* measured: retail groups the two D_005EFE38/D_005EFE40 loads back-to-back
   (ld $a2; lwc1 $f0) before the two stores, and hoists `addiu $a1, $sp, 0x40`
   to the top for the first func_003e9d50 call; mwcc b210 interleaves the first
   store between the loads no matter the spelling. Tried: two member
   assignments into a struct local (nd 13), temp locals for the loads (nd 13),
   one struct-copy assignment from a struct-typed extern (copies 16B incl.
   padding vs retail's 12B, nd 5+), pointer local p = &sp40 with stores
   through p (nd 5, stores use $a1 base and stay interleaved), and pointer
   local passed to the calls (p gets a callee-saved register and the frame
   grows, nd 100). All with real (s32,void*,f32,s32) prototype so the f32
   arg stays single-precision. Compiler-floor scheduling artifact; the body
   and every call site were byte-identical at nd 5. */
// FUN_00153300
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00153300);

// FUN_001534A0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001534a0);
