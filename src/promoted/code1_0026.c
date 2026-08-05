#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb4bc;
extern void func_0026d810();

extern u8 *func_00452560(void);

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(void);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void func_004b1150(u8 *arg0);

// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266A90
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266a90);

// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}



// FUN_002674B0
void func_002674b0(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266cc0;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_00267510
void func_00267510(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0025f230((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_002677A0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_002677a0);

// FUN_00268A70
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00268a70);

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

// FUN_0026DC30
void func_0026dc30(void)
{
    func_0026d810();
}

// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}
