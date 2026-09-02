/* code1_0039 / func_003990a0 probe archive.
 * object_size=368B window=368B normalized_diff=196.
 * Differing offsets: prologue correct, but candidate has p in $s1 and e in $s0
 * (retail p in $s0, e in $s1); total assigned to a saved reg ($s4) instead of
 * $v0; switch case order and branch ladder layout differ; early-return branch
 * shape; some scheduling/branch delays.
 * Levers tried: #pragma schedule on, #pragma no_branch_likely on, switch vs
 * if/else, e-reuse as size value vs separate var_17, declaration order,
 * parenthesized total expression.
 * Still needs: a source shape that keeps p in $s0, e in $s1, total in $v0,
 * and emits the exact case branch order (4,2,1,5,0,default).
 */
#include "include_asm.h"
#include "type.h"

extern s32 func_003e6240(s32 arg0);

#pragma schedule on
#pragma no_branch_likely on
s32 func_003990a0(s32 arg0)
{
    u8 *p;
    s32 i;
    s32 total;
    u8 *e;
    s32 type;
    s32 var_18;

    p = *(u8 **)(arg0 + iGpffffb5e0);
    if ((p == NULL) || (*(s32 *)(p + 0x80) == 0)) {
        return 0;
    }
    total = 4;
    i = 0;
    do {
        var_18 = 4;
        e = p + ((i & 0xFF) << 6);
        type = *(s32 *)(e + 0x20);
        total += 4;
        switch (type) {
        case 4:
            if (*(s32 *)(e + 0) != 0) {
                var_18 = func_003e6240(*(s32 *)(e + 0)) + 0xC + 4;
            }
            total = total + 8 + var_18;
            break;
        case 2:
            if (*(s32 *)(e + 4) != 0) {
                var_18 = func_003e6240(*(s32 *)(e + 4)) + 0xC + 4;
            }
            total = total + 8 + var_18;
            break;
        case 1:
            if (*(s32 *)(e + 4) != 0) {
                var_18 = func_003e6240(*(s32 *)(e + 4)) + 0xC + 4;
            }
            if (*(s32 *)(e + 8) != 0) {
                e = (u8 *)(func_003e6240(*(s32 *)(e + 8)) + 0xC + 4);
            } else {
                e = (u8 *)4;
            }
            total = total + 4 + var_18 + (s32)e;
            break;
        case 5:
        case 0:
        default:
            break;
        }
        i = (i + 1) & 0xFF;
    } while (i < 2);
    return total;
}
#pragma no_branch_likely off
#pragma schedule off
