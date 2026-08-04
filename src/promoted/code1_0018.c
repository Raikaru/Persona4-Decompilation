#include "include_asm.h"
#include "type.h"
extern void func_0048a000();
extern void func_00185370();

extern void (*jtbl_008873EC[])(void *);

extern s32 D_0076428C;

void func_0018e780(s32 arg0);



// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_001852F0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001852f0);

// FUN_00185370
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185370);

// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

// FUN_00185830
void func_00185830(void)
{
    func_0048a000();
}

// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189FA0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189fa0);

// FUN_0018A000
void func_0018a000(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4) = arg1;
}

// FUN_0018BAD0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bad0);

// FUN_0018BED0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bed0);

// FUN_0018BF50
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bf50);

// FUN_0018C610
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018c610);

// FUN_0018C700
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018c700);

// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0018E030
void func_0018e030(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}



// FUN_0018E450
s32 func_0018e450(u8 *arg0)
{
    s32 *p;
    s32 state;

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
        func_0018e780(0);
        *p += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}
