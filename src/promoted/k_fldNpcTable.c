#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldNpcTable.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00155280(void);

// FUN_0015C750
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015c750);

// FUN_0015C800
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015c800);

// FUN_0015CA30
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015ca30);
/* measured: opt_loop_invariants hoists the 0xFFFF compare constant (nd 8 -> 3).
 * Residual nd 3: scan pointer loaded from the call result coloured $a2 where
 * retail reuses $v0 -- allocator floor (decl order/typing/spelling/temps). */



#pragma opt_loop_invariants on


// FUN_0015CBE0 NONMATCHING
#ifdef NON_MATCHING
void func_0015cbe0(s32 arg0)
{
    u16 *work = *(u16 **)(func_00155280() + 0x18F4);
    s32 count = 0;

    for (;;) {
        if (count == arg0) {
            break;
        }
        if (*work == 0xFFFF) {
            count += 1;
        }
        work += 0x10;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cbe0);
#endif
#pragma opt_loop_invariants off








// FUN_0015CC40
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cc40);

// FUN_0015CCC0
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015ccc0);

// FUN_0015CD70
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cd70);

// FUN_0015CF10
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cf10);

// FUN_0015CF70
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cf70);

// FUN_0015D000
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015d000);

// FUN_0015D100
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015d100);

// FUN_0015D1A0
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015d1a0);