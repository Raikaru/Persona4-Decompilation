#include "include_asm.h"
#include "type.h"
extern s32 iGpffffac74;
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern s32 iGpffffba74;
extern s32 iGpffffba78;
extern s32 iGpffffba7c;

extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];



// FUN_004526F0
void func_004526f0(u8* arg0, s32 arg1)
{
    (*D_008873FC)(arg1, arg0);
}



// FUN_004534F0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004534f0);

// FUN_004535B0
s32 func_004535b0(void)
{
    return iGpffffac74;
}

// FUN_00454460
/* The three exits are laid out with explicit gotos because retail places the
   `return 0` block and the `return 1` block out of line, in that order, after
   the main body. The natural nested-if / result-variable spellings all merge
   them into one epilogue and come out two words short (nd 24). */
s32 func_00454460(u8 *arg0) {
    s32 v;
    s32 t;

    v = *(s32 *)(arg0 + 0x28);
    if (v <= 0) {
        goto zero;
    }
    t = v - *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = t;
    if (t >= 0) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = 0;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 0;
one:
    return 1;
}

// FUN_004556B0
s32 func_004556b0(u8* arg0, u32 arg1)
{
    if (arg1 < *(u32*)(arg0 + 4)) {
        return (s32)(*(u8**)(arg0 + 0x58) + arg1 * 0x110);
    }
    return 0;
}



// FUN_00456840
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456840);

// FUN_00457120
s32 func_00457120(void)
{
    return iGpffffba80;
}

// FUN_00457190
s32 func_00457190(void)
{
    return iGpffffba70;
}

// FUN_004571A0
s32 func_004571a0(void)
{
    return iGpffffba74;
}

// FUN_004571B0
s32 func_004571b0(void)
{
    return iGpffffba78;
}

// FUN_004571C0
s32 func_004571c0(void)
{
    return iGpffffba7c;
}

// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}



// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}
