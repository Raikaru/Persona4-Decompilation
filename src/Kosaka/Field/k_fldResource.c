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
extern void func_00153300(void *arg0, f32 arg1);
extern void func_003e0380(f32 *arg0);
extern void func_003e03e0(void *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern void *func_003e0f80(void);
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

/* measured: retail hoists the loop bases D_005F05B8+s17v and D_005F0590 into
   preheader temps and folds -0x28 into the lbu displacement, and does not
   mask s16v before `s16v-1`; mwcc b210 rematerializes the bases inside the
   loop body (nd 135). Tried 4 spellings: (1) u16 params + (u16) call casts
   -- mwcc masks params at entry and CSEs &iGpffff9db0 into $s5/$s6, frame
   grows to -0x100; (2) s32 params + (s16) casts + iGpffff9db0 as pointer --
   prologue exact, but loop CSE keeps D_005F0590[s17v] address in $s0 across
   calls and args land $s4/$s3; (3) loop lookup spelled D_005F05B8[s17v-0x28]
   (retail's own symbol choice, breaks the CSE) -- prologue/args/registers
   all exact, remaining diffs are the s16v mask, branch-2 base rematerialize,
   and the loop LICM; (4) func_00442088 prototype s32 + (s16) args (pure
   dsll32/dsra32) + swapped decl order (s16v->$s0, s17v->$s1) -- exact
   through the whole function except the LICM hoist and the s16v u16 mask.
   The last lever is scoped `#pragma opt_loop_invariants on` (unused here) or
   pointer locals for the two table bases; s16v should be s32 not u16. */
// FUN_0014EFC0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014efc0);
// FUN_0014F310
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014f310);

/* measured: retail hoists &D_008873F4 into $s3 once and does `lw $v0, 0($s3)`
   at both call sites; mwcc b210 with a local `tbl = D_008873F4` emits a dead
   early lui/addiu copy plus a fresh rematerialization at the FIRST call
   (nd 82, all remaining rows are that copy and the flag/r/tbl register
   placement). Tried: direct D_008873F4[0]() twice (no hoist, per-call
   lui/lw), scalar function-pointer extern (GPREL16 load, retail is
   absolute), local u8 **tbl in every declaration order and init spelling
   (&D_008873F4[0], init-in-decl, after-jal assignment) -- all nd 82-90.
   Also: the two strlen loops are `while (*p)` / `while (*p != '/')` (test
   first, retail branches to the test), D_00754D88 is s8[] (retail uses lb),
   flag/r order matches when declared [flag, r, p] modulo the dead copy. */
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

/* measured: every func_003e2ce0(s16, sp50[1]) call site is the known b210
   call-argument floor -- retail sets args [move $a0; lw $a1, 0x54($sp)],
   mwcc emits [lw $a1; move $a0] (same floor documented in effObjectParticle
   func_004aea70 and k_clumpInstance func_00191e90). Tried: s32/u32 casts on
   both args, hoisting sp50[1] into a local -- identical swapped pair each
   time (5 call sites, nd 185 total with layout). Additionally the retail
   stack layout (0x50..0x7C with 0x58-0x64 and 0x78 holes, frame -0x80)
   implies a 48-byte record local (12-word array) whose fields sit at 0x50,
   0x54, 0x68, 0x6C, 0x70, 0x74, 0x7C; separate s32 locals compile to a
   packed -0x70 frame and shift every sp offset. Case 11/16's s18 =
   arg0->0xA44 load wants to sit between the func_003e2f60 and func_004667d0
   calls (separate alloc statement), which perturbs callee-saved allocation
   (arg0 drifts to $s2). Declared case order 11,16,35,22,12 matches retail's
   reversed beq-chain test order (12,22,35,16,11) and body layout exactly. */
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

/* measured: retail materializes &D_00887300[0] via lui+addiu BEFORE the
   constant args and loads lw 0($v0) after them (3 instructions, no fold);
   mwcc b210 emits the args first, then lui+lw with the %lo folded into the
   load (2 instructions) -- every D_00887300[0](const, const) call site
   differs (8 sites, nd 242 all told: the 2-word form + the 4-byte shift
   ripples the whole tail). Tried D_00887300[0](), (*D_00887300)(),
   (D_00887300[0])() -- identical folded output through the mwccgap
   assembler; a fn-ptr local p = D_00887300[0] gives direct jalr (no per-call
   reload, retail reloads). The 2-param old-style definition
   (void f(a0, a1) u8 *a0; u8 *a1;) is required: the matched func_00152930
   assigns func_00152170 to a void(*)(void) slot without a cast, and retail
   reads arg1 from $a1. Everything else -- the Vec4 struct copies into
   0xA50/0xA60, the 8x8-byte copy loop into 0xA70, the two flag chains
   (nested-if for cbc10, &&-form for cbe80), the D_00887300(0xF, ...) byte
   merge, the five iGpffffbaXX gp bytes -- matched byte-identically. */
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

/* measured: retail reuses $s0 for p16 (blocks 1-3) then the loop-1 counter,
   keeping p17 in $s1 and the args at $s2/$s3 with p20 in $s4; mwcc b210 holds
   p16 in $s0 for the whole function and shifts the chain (args land $s3/$s4,
   counter $s1, p17 $s2) -- tried function-scoped and block-scoped p16, inline
   pointer reloads (mwcc re-loads arg0->off->4 per use, nd 259), and every
   pointer declaration order (nd 116, nd unchanged). The Vec3 add blocks
   (sp100/spE0/spC0/spA0, and the loop-2 sp70) match byte-identically with
   Vec3 struct assignments + 12-byte f32[3] buffers declared in descending
   address order (sp100, spF0, spE0, spD0, ...) -- the earlier f32[4] and
   separate-f32 spellings break the batched load/store or the slot layout.
   D_005EFE28/D_005EFE30 must be array-typed (absolute lui/ld + lwc1; scalar
   extern gives GPREL16). All loop-2 case 0/2 and case 1 bodies (matrix
   init, func_003e0870/003e42a0/004b1250 calls, the 0x20003 OR) matched. */
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

/* measured: retail loads 90.0f into $f1 BEFORE the arg2 sign branch and keeps
   var_f0 in $f0 (mtc1/cvt.s.w write $f0, add.s doubles in place); mwcc b210
   with the same statements allocates var_f0 to $f1 and materializes 90.0f
   into the dead $f0 right before the join's mul.s (nd 106, ~9 float words
   plus a nop that shifts the whole tail). Tried: declaration orders,
   temp_f20 = 90.0f; then temp_f20 *= var_f0 (mwcc sinks the load below the
   early return), 2.0f * (emits mul.s not add.s), separate s32 temp for the
   or-result -- all nd >= 106. Loop 2 also insists p18 (p20+j*24, live across
   calls) -> $s1 while retail has p17 (arg0+j*24, recomputed in-branch) ->
   $s1; p8 (copy source base) gets a callee-saved reg in mwcc but t0 in
   retail, and the type test reloads arg0+j*0x18+0x120 via p8 instead of the
   pre-walk p7 register. Everything else -- the copy loop, the type dispatch
   (if/else-if 0/2 then 1), the Vec3 struct copy of 0xA24..0xA2C, the s16
   (f32)(s32)(((u32)arg2>>1)|(arg2&1)) + x+x doubling, the (s32) casts on
   func_00478750/func_004b11b0 args -- matched byte-identically in the best
   build (nd 106 = only the float regs + loop-2 addressing). */
// FUN_001534A0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001534a0);

