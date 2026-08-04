/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

s32 func_00452380(void *arg0);
extern u8 D_0063E918[];
void func_00452080(s32 arg0);

extern s32 D_00882F20[];



// FUN_002A2310
void func_002a2310(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_002A2710
s32 func_002a2710(void) {
    return (s32)(func_00452380(D_0063E918) != 0);
}



// FUN_002A2740
void func_002a2740(void) {
    s32 temp_2;

    if ((temp_2 = func_00452380(D_0063E918)) != 0) {
        func_00452080(temp_2);
    }
}



// FUN_002AAA00
void func_002aaa00(void)
{
}

// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}



// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
