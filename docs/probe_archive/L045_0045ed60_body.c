/* Re-measured 2026-09-02 (Main): the residual `move $a3,$a2` is CSE of the two literal 3s -
   with opt_propagation off ALONE (common_subs on) the call tail is instruction-exact
   (move $a0,$t1; addiu $a2,$zero,3; move $a3,$a2) but the twelve lbu reloads collapse to
   four (nd43). The reloads need opt_common_subs off, which also kills the constant CSE;
   a shared `s32 n = 3` local under both pragmas is hoisted to the prologue (`addiu
   $a2,$zero,3` before the loads, nd8; same for n=0;n=3, n=arg2;n=3, block-scoped, s64),
   a `u8`/`s16` n materialises late but as `daddiu` and before `move $a0,$t1` (nd11).
   Aliasing cannot replace the pragma: stores through ptr/(u8 *)&colors/u32-slot casts,
   per-copy `src = arg0`, u32 staging locals, and a static inline copy helper all CSE the
   loads or move the stores off $sp. Two-pragma floor. */
/* measured: best retained baseline object 148B vs retail window 160B, normalized_diff 4; first differing instruction at offset 120 is retail daddu $a3,$a2,$zero while baseline emits li $a3,3; offset 124 is relocated jal. Candidate 148B has zero tail through 159. Residual is 64-bit call-argument materialization: retail words are daddu $a0,$s1; addiu $a2,$zero,3; daddu $a3,$a2,$zero; candidate words are move $a0,$t1; li $a2,3; li $a3,3. Scoped f32 * second-parameter and u8 * sixth-parameter prototype was tested; u64/s64 third/fourth parameter prototypes also tested, but MWCC still emitted the baseline sequence. Ruled out struct-vs-array aggregate, cached pointer declaration/initialization order, direct-vs-local color loads, repeated load aliases, count locals s32/s16/s8/s64/u32 and declaration timing, callee parameter widths u32/s32 and pointer forms, u64/s64 callee third/fourth positions, call-local argument assignments and all declaration/assignment order permutations, pointer arithmetic/identity assignments, O1/schedule/O3/tailcall/propagation/common-subexpression pragmas, mixed literal/count call order, helper wrappers, nested blocks, aliases, unions, and explicit argument locals. volatile and inline asm not used. */
/* measured probe context: suppress propagation so the cached colors pointer stays in t1. */
#pragma opt_propagation off
/* measured probe context: suppress common substitutions for repeated retail byte loads. */
#pragma opt_common_subs off
void func_0045ed60(void *arg0, void *arg1, s32 arg2, f32 farg0) {
    extern void func_0045dfd0(u8 *arg0, f32 *arg1, f32 farg0, u32 arg2, s32 arg3, u8 *arg4);
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
    func_0045dfd0(ptr, (f32 *)arg1, farg0, 3, 3, (u8 *)arg2);
}
/* measured probe context: restore common substitutions after func_0045ed60. */
#pragma opt_common_subs on
/* measured probe context: restore propagation after func_0045ed60. */
#pragma opt_propagation on
