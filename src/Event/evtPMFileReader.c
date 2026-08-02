#include "include_asm.h"
/* Persona 4 USA decompilation - evtPMFileReader.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern s32 func_00452490();
extern s32 *func_00452560();
extern u8 D_0063C970[];

// FUN_002938C0
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_002938c0);

// FUN_00293D30
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_00293d30);

// FUN_00293ED0
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_00293ed0);

// FUN_00293FC0
s32 func_00293fc0(s32 arg0) {
    if (func_00452490(arg0) == 0) {
        func_0046d730(D_0063C970, 0x123);
    }
    if (func_00452560(arg0)[0] == 7) {
        return 1;
    }
    return 0;
}

// FUN_00294040
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_00294040);

// FUN_002940A0
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_002940a0);

