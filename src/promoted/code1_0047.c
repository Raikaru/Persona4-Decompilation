#include "include_asm.h"
#include "type.h"
extern void (*iGpffffbb2c)();
extern void (*iGpffffbb30)();
extern void (*iGpffffbb34)();
extern void (*iGpffffbb38)();
extern void (*iGpffffbb3c)();

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

extern void func_00478a30(u8 *arg0, s32 arg1);

extern void func_00478ec0(u8 *arg0);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

extern s32 func_00479ca0(u8 *arg0, s32 arg1);

/* measured: single residual at off 64 -- addu $v0,$s0,$v0 vs retail
 * addu $v0,$v0,$s0 (commutative operand swap on the final index*0xA4+base
 * add). Both C operand orders compile identically; nd 2 -> 2. Allocator
 * floor (same residual in 0047ADF0/0047AE90). */

extern s32 func_004782b0(u8 *arg0);

extern void func_004b5c20(s32 arg0);



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
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_00470d10);

// FUN_00470E20
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_00470e20);

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

// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg1 + 4);
    if (temp_4 != 0) {
        func_004b5c20(temp_4);
    }
}
