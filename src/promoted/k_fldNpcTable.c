#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldNpcTable.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00155280(void);

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
