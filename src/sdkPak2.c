#include "include_asm.h"
/* Persona 4 USA decompilation - sdkPak2.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_004c8708(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0044ef70(s32 size, s32 align, s32 flags);
extern void func_004c9010(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_00712AC0[];

// FUN_00468A50
INCLUDE_ASM("asm/nonmatchings/sdkPak2", func_00468a50);

/* measured: nd 8 (obj 284B vs window 288B, so SEVEN real words) from 49.

   The whole 49 -> 8 came from ONE restructure: the range test must be a POSITIVE
   guard wrapping the entire body with a single trailing `return 0`, not an early
   `if (!(count < limit)) return 0;`. Written as an early return b210 materializes
   the zero inline at the test and uses `slt $v0` + `bnez`; as a positive guard it
   emits retail's `slt $at` + `beqz` branching forward to the shared exit at the
   end of the function. Same lever as mt_sceneIcon func_0026da30, and it also
   explains the $at destination -- $at appears here precisely because the
   comparison feeds a forward branch to a shared block.

   Residual: retail computes `(base + count) * 4` BEFORE loading the table
   pointer from arg0+8, and has the index as the first operand of the final
   `addu`; b210 loads the pointer first and puts it first in the addu. Retail
   also computes the slot address as `arg1 * 4 + arg0`.

   Measured and rejected: an explicit `off` temp for the scaled index, index-first
   spelling of the ent expression, `arg1 * 4 + arg0` for the slot, and
   opt_propagation off -- all six spellings score 8; b210 canonicalizes the
   commutative operands and sinks the load regardless. Address-materialization
   order floor. */
// FUN_00468BF0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00468bf0(u8 *arg0, s32 arg1)
{
    s32 base;
    s32 count;
    s32 len;
    u8 *slot;
    u8 *tbl;
    u8 *ent;

    base = *(s32 *)(arg0 + 0x3C);
    count = *(s32 *)(arg0 + 0x44);
    if (count < *(s32 *)(arg0 + 0x40) - base + 1) {
        tbl = *(u8 **)(arg0 + 8);
        ent = *(u8 **)(tbl + 0x10) + (base + count) * 4;
        len = *(s32 *)(ent + 8) - *(s32 *)(ent + 4);
        if (len != 0) {
            slot = arg0 + arg1 * 4 + 0x10;
            *(s32 *)slot = func_004c8708(tbl + 0x18, 0, *(s32 *)(ent + 4), len);
            func_0044ea90(D_00712AC0, 0xC7);
            *(s32 *)(*(u8 **)(arg0 + 0x38) + *(s32 *)(arg0 + 0x44) * 4) =
                func_0044ef70(len << 11, 0x40, 0x40000);
            func_004c9010(*(s32 *)slot, len,
                          *(s32 *)(*(u8 **)(arg0 + 0x38) + *(s32 *)(arg0 + 0x44) * 4));
        }
        *(s32 *)(arg0 + 0x44) = *(s32 *)(arg0 + 0x44) + 1;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkPak2", func_00468bf0);
#endif

