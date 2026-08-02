/* Source unit: src/Script/scrTraceCode_0029ad20.c */
#include "include_asm.h"
#include "type.h"

/* Minimal view of ScrData; only pc (offset 0x18) is accessed. */
typedef struct ScrData
{
    u8 padding_00[0x18];
    s32 pc;
} ScrData;

enum ScrOperation
{
    SCR_OPERATION_ADD,
    SCR_OPERATION_SUB,
    SCR_OPERATION_MUL,
    SCR_OPERATION_DIV,
    SCR_OPERATION_OR,
    SCR_OPERATION_AND,
    SCR_OPERATION_EQ,
    SCR_OPERATION_NEQ,
    SCR_OPERATION_S,
    SCR_OPERATION_L,
    SCR_OPERATION_SE,
    SCR_OPERATION_LE
};

u32 func_0029b1b0(ScrData* scr, u32 type);

// FUN_0029A050
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a050);
// FUN_0029A100
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a100);
// FUN_0029A1B0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a1b0);
// FUN_0029A260
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a260);
// FUN_0029A320
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a320);
// FUN_0029A3E0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a3e0);
// FUN_0029A4A0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a4a0);
// FUN_0029A560
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a560);
// FUN_0029A610
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a610);
// FUN_0029A6A0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a6a0);
// FUN_0029A820
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a820);
// FUN_0029A9C0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029a9c0);
// FUN_0029AB80
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029ab80);




// FUN_0029AD20
u32 func_0029AD20(ScrData* scr)
{
    scr->pc++;

    return 1;
}

// FUN_0029AD40
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029ad40);
// FUN_0029AE90
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029ae90);
// FUN_0029B020
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029b020);
// FUN_0029B060
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029b060);
// FUN_0029B120
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029b120);
// FUN_0029B170
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029b170);
// FUN_0029B1B0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029b1b0);




// FUN_0029BEB0
u32 CodeFunc_Add(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_ADD);
    scr->pc++;

    return 1;
}



// FUN_0029BEF0
u32 CodeFunc_Sub(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SUB);
    scr->pc++;

    return 1;
}



// FUN_0029BF30
u32 func_0029BF30(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_MUL);
    scr->pc++;

    return 1;
}



// FUN_0029BF70
u32 CodeFunc_Div(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_DIV);
    scr->pc++;

    return 1;
}

// FUN_0029BFB0
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029bfb0);
// FUN_0029C130
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029c130);




// FUN_0029C550
u32 CodeFunc_Or(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_OR);
    scr->pc++;

    return 1;
}



// FUN_0029C590
u32 CodeFunc_And(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_AND);
    scr->pc++;

    return 1;
}



// FUN_0029C5D0
u32 CodeFunc_Eq(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_EQ);
    scr->pc++;

    return 1;
}



// FUN_0029C610
u32 CodeFunc_Neq(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_NEQ);
    scr->pc++;

    return 1;
}



// FUN_0029C650
u32 CodeFunc_S(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_S);
    scr->pc++;

    return 1;
}



// FUN_0029C690
u32 CodeFunc_L(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_L);
    scr->pc++;

    return 1;
}



// FUN_0029C6D0
u32 CodeFunc_SE(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_SE);
    scr->pc++;

    return 1;
}



// FUN_0029C710
u32 CodeFunc_LE(ScrData* scr)
{
    func_0029b1b0(scr, SCR_OPERATION_LE);
    scr->pc++;

    return 1;
}

// FUN_0029C750
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029c750);
// FUN_0029CB00
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cb00);
// FUN_0029CC00
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cc00);
// FUN_0029CD50
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cd50);
// FUN_0029CE90
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029ce90);
// FUN_0029CF50
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cf50);
// FUN_0029CF70
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cf70);
// FUN_0029CF90
INCLUDE_ASM("asm/nonmatchings/scrTraceCode", func_0029cf90);
