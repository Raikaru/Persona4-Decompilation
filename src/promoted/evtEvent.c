/* Consolidated Persona 4 source units. */
/* Original translation unit evtEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern s32 func_00286350();

void func_00452080(s32 arg0);
/* Old-style: this unit calls it both with no argument (func_002856a0) and with
   one (func_00285480), exactly as retail does. */
s32 *func_00452560();
extern void (*jtbl_008873EC[])(void *);
void func_002852a0(s32 arg0, s32 arg1);

s32 func_00452380(void *arg0);
extern s32 D_0063C2F8[];
extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0063C2C8[];
void func_002853c0(void);



// FUN_00285480
s32 func_00285480(u8 *arg0)
{
    s32 handle;

    if (arg0 == 0) {
        func_0046d730(D_0063C2C8, 0x2E);
    }
    handle = *(s32 *)(arg0 + 0xC);
    if (handle == 0) {
        return 0;
    }
    return (s32)func_00452560(handle);
}

// FUN_002854E0
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_002854e0);

// FUN_00285760
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_00285760);

// FUN_002857C0
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_002857c0);
// FUN_00285980
void func_00285980(void) {
    s32 *temp_2;

    temp_2 = func_00452560();
    func_00452080(*(s32 *)((u8 *)temp_2 + 0xC));
    jtbl_008873EC[0](temp_2);
    func_002852a0(0, -0x60);
}



// FUN_002859E0
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_002859e0);
// FUN_00285AF0
void func_00285af0(void) {
    if (func_00452380(D_0063C2F8) == 0) {
        func_002853c0();
    }
}

// FUN_00285B30
s32 func_00285b30(void) {
    s32 h = func_00286350();

    if (h == 0) {
        return -1;
    }
    return *(s32 *)((u8 *)func_00452560(h) + 0x14);
}

// FUN_00285B80
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_00285b80);
