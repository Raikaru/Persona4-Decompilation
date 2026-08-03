/* Original translation unit sdkSpr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_0044ea90(void *arg0, s32 arg1);
void func_00442830(void *arg0, const char *arg1);
void func_00440b68(char *arg0, const char *arg1, s32 arg2);
void func_0043f810(void *arg0, void *arg1, s32 arg2);
void func_00454bd0(u8 *ptr);
s32 func_004553c0(u8 *ptr);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_00454a60(void *arg0, s32 arg1);
void func_003ec330(void *ptr);
s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
void func_0046b380(u8 *arg0, s32 arg1);

/* Sprite dispatcher slot at 0x008873EC (absolute, outside gp window). */
extern void (*jtbl_008873EC[])(...);
/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern u8 *(*D_008873F4[])(s32, s32, s32);
/* GP-relative list head at gp -0x44E8 (absolute 0x00764C08). */
extern u8 *iGpffffbb18;
/* GP-relative global at gp -0x4FC8 (absolute 0x00764128). */
extern char iGpffffb038;
extern char D_007130C8[];

// FUN_0046AB90
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046ab90);

// FUN_0046AEA0
u8 *func_0046aea0(const char *name)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x115);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 0;
    func_00442830(node + 2, name);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046AF60
void func_0046af60(u32 arg0)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x12D);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    *(u32 *)(node + 0x20C) = arg0;
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
}

// FUN_0046B000
u8 *func_0046b000(const char *name)
{
    u8 *node;
    u8 *last;
    u32 out;

    func_0044ea90(D_007130C8, 0x146);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    func_00442830(node + 2, name);
    *(u32 *)(node + 0x20C) = (u32)func_00455f70((void *)name, &out);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046B0D0
void func_0046b0d0(u8 *node)
{
    s32 i;

    if (*(u8 **)(node + 0x23C) == NULL) {
        if (*(u8 **)(node + 0x238) == NULL) {
            iGpffffbb18 = NULL;
        } else {
            iGpffffbb18 = *(u8 **)(node + 0x238);
            *(u8 **)(iGpffffbb18 + 0x23C) = NULL;
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = NULL;
        }
    } else {
        *(u8 **)(*(u8 **)(node + 0x23C) + 0x238) = *(u8 **)(node + 0x238);
        if (*(u8 **)(node + 0x238) != NULL) {
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = *(u8 **)(node + 0x23C);
        }
    }
    i = 0;
    while (i < 0x20) {
        if (*(u32 *)(node + 0x104 + (i << 2)) != 0) {
            func_003ec330((void *)*(u32 *)(node + 0x104 + (i << 2)));
            *(u32 *)(node + 0x104 + (i << 2)) = 0;
        }
        i++;
    }
    if (*(u8 **)(node + 0x208) != NULL) {
        func_00454bd0(*(u8 **)(node + 0x208));
        *(u8 **)(node + 0x208) = NULL;
    }
    if (*(u32 *)(node + 0x204) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(node + 0x204));
        *(u32 *)(node + 0x204) = 0;
    }
    jtbl_008873EC[0](node);
}

/* measured: negative-rounding tail of this leaf (srl/andi/or/mtc1/cvt.s.w/add.s)
   is 2 words off: b210 always colors the OR result (and the mtc1 input) to the
   ANDI temp register (or $v0,$v1,$v0) where retail keeps it in the SRL temp
   register (or $v1,$v1,$v0). Tried ~12 spellings, all nd 2 with the identical
   pair: named f32 local vs inline, (s32) cast on the OR result (REQUIRED to kill
   b210's u32-conversion guard duplication; without it nd 8-18), u32 vs s32
   locals, statement splitting, compound |=, operand order flip, if/else vs
   early return, (f32)(s32)c + (f32)(s32)c CSE form. Every other word matches.
   Register-coloring floor, not source-drivable in this leaf shape. */
// FUN_0046B1F0
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b1f0);
/* measured: identical residual to func_0046b1f0's floor. Whole body matches
   (incl. the three-operand mult $2,$7,$2 and srl >>12) except the
   negative-rounding tail: b210 colors the OR result + mtc1 input to the ANDI
   temp register (or $v0,$v1,$v0 / mtc1 $v0) where retail keeps the SRL temp
   register (or $v1,$v1,$v0 / mtc1 $v1). Tried s32-typed OR expressions
   ((s32)((u32)v>>1)|(v&1)), assignment-back-to-v, named u32/s32 locals,
   (f32)c with and without (s32) cast -- all nd 3 (2 real + 1 benign padding
   nop). Register-coloring floor, same family as b1f0. */
// FUN_0046B260
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b260);
/* measured: same floor as func_0046b260 (offsets 0x60/0x58/0x76/0x22): entire
   body byte-identical except the negative-rounding tail or/mtc1 register pair
   (b210 colors OR result + mtc1 input to the ANDI temp; retail keeps the SRL
   temp). nd 3 (2 real + 1 benign padding nop). Same register-coloring floor
   family as b1f0/b260. */
// FUN_0046B2F0
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b2f0);
// FUN_0046B380
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b380);

// FUN_0046D200
u8 *func_0046d200(u32 arg0, u32 arg1)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    return node;
}

// FUN_0046D280
void func_0046d280(void)
{
    jtbl_008873EC[0]();
}

// FUN_0046D2B0
void func_0046d2b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, f32 z, s32 arg3)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    func_0046b380(node, arg3);
    jtbl_008873EC[0](node);
}

// FUN_0046D3B0
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, f32 z, s32 arg4)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x11) = arg3;
    func_0046b380(node, arg4);
    jtbl_008873EC[0](node);
}

// FUN_0046D4C0
void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x28) = arg3;
    *(u8 *)(node + 0x29) = arg4;
    *(u8 *)(node + 0x2A) = arg5;
    func_0046b380(node, arg6);
    jtbl_008873EC[0](node);
}

/* measured: nd 53 with a full C body (object 172B against a 192B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_0046D5F0
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046d5f0);

