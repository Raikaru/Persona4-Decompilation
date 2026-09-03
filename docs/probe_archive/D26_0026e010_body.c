/* Main 2026-09-03: `result = sp4C = jtbl(...)` (store the call result to the stack slot first, retail
   sw v0 / move s0,v0) takes nd20 -> 12; the remaining words are the loop counter in $a1 (retail $v1)
   and the cascaded temps. AST permuter 14k compiles: 12. */
/* func_0026e010 reconstruction body — D26 lane 2026-08-21.
 * Best result: normalized_diff 20, object 204B / retail window 208B (MISMATCH).
 * Residual: MWCC colors the loop counter in $a1; retail uses $v1. All other
 * words byte-identical (fndiff: 14 differing words = that swap cascaded).
 * Key retail fact: the mult at 0026e048 ((arg0+8)*(arg1+1)) is DEAD — no mflo,
 * the alloc size arg is addiu $a0,$v0,4 = (arg1+1)+4. Every source spelling
 * that lets MWCC delete the mult shrinks the object to 172-192B (nd >= 105);
 * keeping the product live as the alloc size reproduces obj 204 nd 20.
 * Probed without improvement: store/copy order swaps, single-carried-pointer,
 * sp4C reuse, addr-of-result, chained assign, do-while/goto/for shapes,
 * unsigned compare, pre-increment, stride hoist, increment-in-condition,
 * declaration-order permutations, s32/u32 counter type+position.
 */
void func_0026e010(s32 arg0, s32 arg1)
{
    s32 i;
    s32 local_arg0;
    s32 local_arg1;
    u32 *result;
    u32 *sp4C;
    u32 *next;
    u32 *cursor;

    local_arg0 = arg0;
    local_arg1 = arg1;
    func_0044ea90(D_0063B5D8, 0x36);
    result = (u32 *)jtbl_008873E8[0](((local_arg0 + 8) * (local_arg1 + 1)) + 4,
                                    0x40000);
    sp4C = result;
    func_0043f810(result, &sp4C, 4);
    cursor = result + 1;
    i = 0;
    while (i < local_arg1) {
        *cursor = (u32)i;
        next = (u32 *)((u8 *)cursor + local_arg0 + 8);
        *(cursor + 1) = (u32)next;
        cursor = next;
        i++;
    }
    *cursor = (u32)local_arg1;
    *(cursor + 1) = (u32)(result + 1);
}
