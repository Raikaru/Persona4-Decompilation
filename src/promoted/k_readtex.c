/* Consolidated Persona 4 source units. */
/* Original translation unit k_readtex.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(u8 *);





// FUN_001901D0
INCLUDE_ASM("asm/nonmatchings/k_readtex", func_001901d0);

// FUN_001905D0
void func_001905d0(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_00190600
INCLUDE_ASM("asm/nonmatchings/k_readtex", func_00190600);
