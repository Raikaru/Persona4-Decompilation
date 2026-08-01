/* Consolidated Persona 4 source units. */
/* Original translation unit evtEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_00452080(s32 arg0);
s32 *func_00452560(void);
extern void (*jtbl_008873EC[])(void *);
void func_002852a0(s32 arg0, s32 arg1);

s32 func_00452380(void *arg0);
extern s32 D_0063C2F8[];
void func_002853c0(void);



// FUN_00285980
void func_00285980(void) {
    s32 *temp_2;

    temp_2 = func_00452560();
    func_00452080(*(s32 *)((u8 *)temp_2 + 0xC));
    jtbl_008873EC[0](temp_2);
    func_002852a0(0, -0x60);
}



// FUN_00285AF0
void func_00285af0(void) {
    if (func_00452380(D_0063C2F8) == 0) {
        func_002853c0();
    }
}
