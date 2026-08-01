#include "include_asm.h"
#include "type.h"

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


// FUN_00479C30 NONMATCHING
#ifdef NON_MATCHING
s16 func_00479c30(s32 arg0, s32 arg1)
{
    if (func_00479ca0((u8 *)arg0, arg1) != 0) {
        return *(s16 *)(arg0 + ((arg1 & 0xFFFF) * 0xA4) + 0xF0);
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_00479c30);
#endif


// FUN_0047ADF0 NONMATCHING
#ifdef NON_MATCHING
void func_0047adf0(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(((arg1 & 0xFFFF) * 0xC) + arg0 + 0x294) = arg2;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047adf0);
#endif


// FUN_0047AE90 NONMATCHING
#ifdef NON_MATCHING
s32 func_0047ae90(s32 arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + ((arg1 & 0xFFFF) * 0xC) + 0x290);
    if (temp_4 == NULL) {
        return 1;
    }
    return func_004782b0(temp_4);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ae90);
#endif



// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg1 + 4);
    if (temp_4 != 0) {
        func_004b5c20(temp_4);
    }
}
