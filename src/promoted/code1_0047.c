#include "include_asm.h"
#include "type.h"
extern void (*iGpffffbb2c)();
extern void (*iGpffffbb30)();
extern void (*iGpffffbb34)();
extern void (*iGpffffbb38)();
extern void (*iGpffffbb3c)();
extern void func_00470d70(void);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffbb28;
extern void *D_00922BE0[];
extern void func_004b5800(u8 *arg0);
extern void func_004b5f70(u8 *arg0);
extern void func_004b5f80(u8 *arg0);
extern u8 D_00922C50[];

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

extern void func_00478a30(u8 *arg0, s32 arg1);

extern void func_00478ec0(u8 *arg0);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

extern s32 func_00479ca0(u8 *arg0, s32 arg1);

/* measured: func_00470e20's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

extern s32 func_004782b0(u8 *arg0);

extern void func_004b5c20(s32 arg0);



// FUN_00470210
void func_00470210(u8 *arg0)
{
    func_00470d70();
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00470C10
void func_00470c10(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 2;
        *(s32 *)(temp_2 + 0x208) = arg2;
        *(s32 *)(temp_2 + 0x210) = 0;
        *(s32 *)(temp_2 + 0x214) = 1;
        func_004704d0(arg0);
    }
}



// FUN_00470C80
void func_00470c80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 4;
        *(f32 *)(temp_2 + 0x20C) = (f32)arg2;
        *(s32 *)(temp_2 + 0x210) = arg3;
        *(s32 *)(temp_2 + 0x214) = arg4;
        func_004704d0(arg0);
    }
}



// FUN_00470D10
u8 *func_00470d10(u8 *arg0, s32 key)
{
    u8 *node;

    node = *(u8 **)(*(u8 **)(arg0 + 0x38) + 0x144);
    if (key == -1) {
        return NULL;
    }
    if (node == NULL) {
        return NULL;
    }
    goto compare;
advance:
    node = *(u8 **)(node + 0x228);
    if (node == NULL) {
        return NULL;
    }
compare:
    if (*(s32 *)node != key) {
        goto advance;
    }
    return node;
}

// FUN_00470D70
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_00470d70);
// FUN_00470E20
s32 func_00470e20(u8 *arg0)
{
    s32 temp_3;
    s32 var_4;
    u8 *temp_4;
    u8 *var_5;

    temp_4 = *(u8 **)(arg0 + 0x38);
    var_5 = *(u8 **)(temp_4 + 0x144);
    temp_3 = *(s32 *)(temp_4 + 0x138);
    temp_3 = viewAddReverse(temp_3, *(s32 *)(temp_4 + 0x134));
    if (temp_3 >= *(s32 *)(temp_4 + 0x140)) {
        return -1;
    }
    var_4 = 0;
    while (var_4 < temp_3) {
        var_5 = *(u8 **)(var_5 + 0x228);
        var_4 += 1;
    }
    return *(s32 *)var_5;
}

// FUN_00478E70
void func_00478e70(u8 *arg0)
{
    func_00478a30(arg0, (*(s32 *)(arg0 + 0xD8) & 1) == 0);
}



// FUN_00479030
void func_00479030(u8 *arg0, u8 *arg1)
{
    func_00478ec0(arg0);
    RpSkyRenderStateSet(2, *(s32 *)(arg1 + 0xE4));
    RpSkyRenderStateSet(3, *(s32 *)(arg1 + 0xE8));
}


// FUN_00479C30
s16 func_00479c30(s32 arg0, s32 arg1)
{
    if (func_00479ca0((u8 *)arg0, arg1) != 0) {
        s32 off = (arg1 & 0xFFFF) * 0xA4;
        return *(s16 *)(off + (s32)arg0 + 0xF0);
    }
    return -1;
}


// FUN_0047ADF0
void func_0047adf0(u8 *arg0, u16 arg1, s32 arg2) {
    /* Offset added to the base, not the other way round: `arg0 + off` makes
       mwcc emit `addu $v1,$a0,$v1` where retail has `addu $v1,$v1,$a0`. */
    s32 off = arg1 * 12;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s32 *)(p + 0x294) = arg2;
}

// FUN_0047AE90
s32 func_0047ae90(u8 *arg0, u16 arg1)
{
    s32 off = arg1 * 0xC;
    u8 *p = (u8 *)(off + (s32)arg0);
    u8 *temp_4;

    temp_4 = *(u8 **)(p + 0x290);
    if (temp_4 == NULL) {
        return 1;
    }
    return func_004782b0(temp_4);
}



// FUN_0047CE00
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ce00);
// FUN_0047D050
void func_0047d050(s32 arg0)
{
    func_0043f9c8(D_00922BE0, 0, 0x30);
    iGpffffbb28 = arg0;
}
// FUN_0047D090
s32 func_0047d090(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    iGpffffbb2c = (void (*)())arg0;
    iGpffffbb30 = (void (*)())arg1;
    iGpffffbb34 = (void (*)())arg2;
    iGpffffbb38 = (void (*)())arg3;
    iGpffffbb3c = (void (*)())arg4;
    return 1;
}
// FUN_0047D0B0
void func_0047d0b0(void)
{
    iGpffffbb2c();
}

// FUN_0047D0E0
void func_0047d0e0(void)
{
    iGpffffbb30();
}

// FUN_0047D110
void func_0047d110(void)
{
    iGpffffbb34();
}

// FUN_0047D140
void func_0047d140(void)
{
    iGpffffbb38();
}

// FUN_0047D170
void func_0047d170(void)
{
    iGpffffbb3c();
}

// FUN_0047DD40
void func_0047dd40(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 4);
    if (temp_4 != NULL) {
        func_004b5800(temp_4);
    }
}
// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg1 + 4);
    if (temp_4 != 0) {
        func_004b5c20(temp_4);
    }
}

// FUN_0047DDA0
void func_0047dda0(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 4);
    if (temp_4 != NULL) {
        func_004b5f70(temp_4);
    }
}
// FUN_0047DDD0
void func_0047ddd0(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 4);
    if (temp_4 != NULL) {
        func_004b5f80(temp_4);
    }
}
// FUN_0047EA40
void func_0047ea40(u8 **arg0, u8 **arg1)
{
    u8 *temp_5;

    temp_5 = *arg1;
    if (temp_5 != NULL) {
        *(s32 *)(temp_5 + 8) = *(s32 *)(temp_5 + 8) + 1;
        *arg0 = temp_5;
    }
}
// FUN_0047EA70
void func_0047ea70(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 8) = -1;
    *(s16 *)(arg0 + 0x16) = -1;
    *(s16 *)(arg0 + 0x24) = -1;
    *(s16 *)(arg0 + 0x26) = -1;
    *(u16 *)(arg0 + 0x10) |= 0x20;
}
// FUN_0047EAA0
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047eaa0);
// FUN_0047EB20
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047eb20);
// FUN_0047ED60
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ed60);
// FUN_0047EF10
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ef10);
// FUN_0047EF70
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ef70);
// FUN_0047F040
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f040);
// FUN_0047F1A0
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f1a0);
// FUN_0047F4D0
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f4d0);
// FUN_0047F5B0
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f5b0);
// FUN_0047F710
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f710);
// FUN_0047F830
u8 *func_0047f830(void)
{
    return D_00922C50;
}
// FUN_0047F850
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f850);