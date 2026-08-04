#include "type.h"
extern s32 iGpffffb4bc;
extern void func_0026d810();

extern u8 *func_00452560(void);

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
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
