// FUN_0045ED60
/* measured best legal plain-C probe: object 148B / retail window 160B; verify normalized_diff 4 bytes (one content word at 0x78) and fndiff residual 4 words including three zero tail words at 0x94-0x9C. Retail prologue has no saved GPR or FPR registers: arg0/arg1/arg2/farg0 and colors/ptr/color0..3 do not survive a call, so the ordered saved-register list is empty. The body matches every other instruction. The one remaining content residual is addiu $a3,$zero,3 versus retail daddu $a3,$a2,$zero. The 12B retail tail is all-zero alignment padding accepted by verify.py. Tried and ruled out count locals and declaration/assignment order, five-argument and old-style helper declarations, helper parameter width/order variants, pointer/struct/union/alias forms, inline wrappers, schedule/propagation/common-subexpression pragma combinations, and all literal/count call permutations. No volatile or inline asm used. */
/* measured probe context: suppress propagation so the cached colors pointer stays in t1. */
#pragma opt_propagation off
/* measured probe context: suppress common substitutions for repeated retail byte loads. */
#pragma opt_common_subs off
void func_0045ed60(void *arg0, void *arg1, s32 arg2, f32 farg0) {
    struct { u8 b[12]; } colors;
    u8 *ptr = colors.b;
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;

    color0 = ((u8 *)arg0)[0];
    color1 = ((u8 *)arg0)[1];
    color2 = ((u8 *)arg0)[2];
    color3 = ((u8 *)arg0)[3];
    colors.b[0] = color0;
    colors.b[1] = color1;
    colors.b[2] = color2;
    colors.b[3] = color3;

    color0 = ((u8 *)arg0)[0];
    color1 = ((u8 *)arg0)[1];
    color2 = ((u8 *)arg0)[2];
    color3 = ((u8 *)arg0)[3];
    colors.b[4] = color0;
    colors.b[5] = color1;
    colors.b[6] = color2;
    colors.b[7] = color3;

    color0 = ((u8 *)arg0)[0];
    color1 = ((u8 *)arg0)[1];
    color2 = ((u8 *)arg0)[2];
    color3 = ((u8 *)arg0)[3];
    colors.b[8] = color0;
    colors.b[9] = color1;
    colors.b[10] = color2;
    colors.b[11] = color3;
    func_0045dfd0(ptr, (f32 *)arg1, farg0, 3, 3, (s32)arg2);
}
/* measured probe context: restore common substitutions after func_0045ed60. */
#pragma opt_common_subs on
/* measured probe context: restore propagation after func_0045ed60. */
#pragma opt_propagation on
