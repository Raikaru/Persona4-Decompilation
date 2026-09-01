/* func_00286430 reconstruction body — D26 lane 2026-08-21.
 * Best result: normalized_diff 144, object 316B / retail window 432B (MISMATCH).
 * Structure fully decoded from retail: switch on *(s8*)(arg0+0xC):
 *   case 3: if func_0028d060(half@8, half@A)==half@A -> result=1;
 *   case 2: inner switch on u8@E sets a1 offset 0/0x400/0x1200, then result =
 *     (half@A==0) ? func_00106330(half@8+a1)==0 : ==1;
 *   case 1: func_00286350() && (val=func_00452560()) && func_00290de0(val+0x678);
 *   case 0/default: return 0. Retail also carries a default-only cleanup tail
 *   (func_00440b68(0x63C380, *(arg0+0x38)); func_0043f9c8(arg0+8,0,8)) that no
 *   reachable source shape could own without inventing dead code.
 * Residual: retail keeps arg0 in $s0 across all cases; every probed spelling
 * parks it in $s1/s2 or spills, shifting ~35 downstream rows. Probed without
 * improvement: switch vs if-chain dispatch, ascending/descending case order,
 * explicit empty cases/defaults, shared a1 register variable, ternary vs
 * if/else tails, early-break vs nested-if vs &&-chain case bodies, separate
 * temps, declaration-order permutations.
 */
s32 func_00286430(u8 *arg0)
{
    s32 result;
    s32 a1;
    s32 val;
    s32 t;

    result = 0;
    a1 = 0;
    switch (*(s8 *)(arg0 + 0xC)) {
    case 0:
        break;
    case 1:
        if (func_0028d060(*(s16 *)(arg0 + 8), a1) == *(s16 *)(arg0 + 0xA)) {
            result = 1;
        }
        break;
    case 2:
        t = *(u8 *)(arg0 + 0xE);
        switch (t) {
        case 1:
            a1 = 0x400;
            break;
        case 2:
            a1 = 0x1200;
            break;
        default:
            break;
        }
        result = (*(s16 *)(arg0 + 0xA) == 0) ?
            (func_00106330(*(s16 *)(arg0 + 8) + a1) == 0) :
            (func_00106330(*(s16 *)(arg0 + 8) + a1) == 1);
        break;
    case 3:
        if (func_00286350() == 0) {
            break;
        }
        t = (s32)func_00452560();
        if (t == 0) {
            break;
        }
        result = (func_00290de0(t + 0x678) != 0) ? 1 : 0;
        break;
    default:
        break;
    }
    return result;
}