/* func_003e3f00 archive: best b119 candidate, object 128B/window 128B, normalized_diff 25.
   COP1 accumulator-chain residual: retail interleaves mula/madd/adda across the
   three dot-product outputs with a clear f6 zero base, and b119 does not adopt
   the same FPR assignment / load order after source-shape, declaration-order,
   and accumulator-initialization (0.0f vs mula-first) probes. Treat as floor.
*/
#include "include_asm.h"
#include "type.h"

u8 *func_003e3f00(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 x = *(f32 *)arg1;
    f32 y = *(f32 *)(arg1 + 4);
    f32 z = *(f32 *)(arg1 + 8);
    f32 *m = (f32 *)arg2;
    f32 out0 = x * m[0];
    f32 out1 = x * m[1];
    f32 out2 = x * m[2];

    out0 += y * m[4];
    out1 += y * m[5];
    out2 += y * m[6];
    out0 += z * m[8];
    out1 += z * m[9];
    out2 += z * m[10];
    *(f32 *)arg0 = out0;
    *(f32 *)(arg0 + 4) = out1;
    *(f32 *)(arg0 + 8) = out2;
    return arg0;
}
