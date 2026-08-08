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

static inline u32 sdkAddOffset(u32 offset, u32 base) { return offset + base; }

/* measured: no real C body was produced for this 784B retail window; no
   candidate nd was retained. */
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

/* Ported from P3FES h_maestro.c func_001126b0 (blob+index scale variant).
   Donor struct fields map onto P4 offsets: output at 0x204, overrideX at 0x74,
   right/left at 0x5c/0x54. The `sdkAddOffset` inline carries the offset-first
   operand order retail emits (addu $v0,$a1,$a0). */
// FUN_0046B1F0
f32 func_0046b1f0(u8 *blob, u32 index)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;

    offset = index * 0x80;
    output = *(u8 **)(blob + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    return (f32)value;
}
// FUN_0046B260
f32 func_0046b260(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x20)) >> 12);
    }
    return (f32)value;
}
// FUN_0046B2F0
f32 func_0046b2f0(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = (u8 *)param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x22)) >> 12);
    }
    return (f32)value;
}
/* measured: no real C body was produced for this 7808B retail window; no
   candidate nd was retained. */
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
/* Measured nd 9 (object 176 / window 192); the body matches the allocation, field initialization, callback, and result path but retains nine normalized instruction differences. */
// FUN_0046D5F0
s32 func_0046d5f0(u8 *arg0, s32 arg1) {
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_5;
    u8 *output;
    s32 index;

    func_0044ea90(D_007130C8, 0x3AF);
    temp_2 = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(temp_2 + 0x28) = 0xFF;
    *(u8 *)(temp_2 + 0x29) = 0xFF;
    *(u8 *)(temp_2 + 0x2A) = 0xFF;
    *(u8 **)temp_2 = arg0;
    *(s32 *)(temp_2 + 4) = arg1;
    temp_5 = *(u8 **)temp_2;
    output = *(u8 **)(temp_5 + 0x204);
    output = (u8 *)sdkAddOffset((u32)(arg1 << 7), (u32)output);
    index = *(s32 *)(output + 0x14);
    temp_16 = *(s32 *)((u8 *)sdkAddOffset((u32)(index << 2), (u32)temp_5) + 0x104);
    jtbl_008873EC[0](temp_2);
    return temp_16;
}
// FUN_0046D6A0
void func_0046d6a0(void)
{
}

