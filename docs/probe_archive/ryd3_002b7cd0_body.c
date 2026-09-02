/* lane ryd3 addr 002b7cd0 residual MISMATCH nd=319 */
// FUN_002B7CD0
void func_002b7cd0(u8 *arg0, s16 arg1, s16 arg2) {
    u8 *t0;
    s32 off;
    s32 flags;
    s16 i;
    s16 found;
    u8 *q;
    u8 *base;
    f32 v[4];
    s16 j;

    t0 = *(u8 **)(arg0 + 0x38);
    flags = *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + ((s32)arg1 * 0x100) + 0x14);
    off = (s32)arg1 * 0x100;

    found = 0;
    for (i = 1; i < 13; i++) {
        if (((flags & (u16)(1 << i)) >> i) == 1) {
            found = 1;
            goto found_check;
        }
    }
    found = 0;

found_check:
    if (found) {
        return;
    }

    q = func_0046d200(*(u32 *)t0, arg2);
    (void)func_0046b260(q);
    (void)func_0046b2f0(q);
    base = (u8 *)(*(u32 *)(*(u32 *)q + 0x204)) + ((s32)arg2 * 0x80);

    for (j = 0; j < 4; j++) {
        v[j] = (f32)*(s32 *)(base + j * 4 + 0x34);
    }

    if ((*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3c) - v[2] >= 640.0f) ||
        (v[3] + (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3c) + func_0046b260(q)) < 0.0f) ||
        (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x40) - v[0] >= 480.0f) ||
        (v[1] + (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x40) + func_0046b2f0(q)) < 0.0f)) {
        *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14) &= ~1;
    }

    func_0046d280(q);
}
/* measured: restore opt_loop_invariants after the target. */
#pragma opt_loop_invariants off
#pragma pop

/* measured: retail compiles the u8->float c-check (lbu 0x125 + bltz, round-to-even
   trick via srl/andi/or, doubling via add.s) as a standard if/else - one bltz, direct
   path inline, trick out of line, single join store; mwcc b210 duplicates the else
   block and emits TWO bltz on the same lbu result for every spelling tried (>= / <
   condition, u8/u32 c, v2 local or inline doubled expression, u32 shift casts; nd
   111-129). Also retail hoists the D_008872F8 lui into the loop preheader and loads
   the LHS operand first (sub.s $f1, $f0 order), mwcc keeps the lui in the body and
   loads RHS first (nd 12 in the loop alone, same floor family as func_002b9e10's
   operand-order note). Else-duplication + loop-operand-order floor. */
/* measured: recipe A (s32 v = lbu load, u32 c copy, (f32)(s32)((c >> 1) | (c & 1)),
   f = f + f doubling, direct-path-first if (v >= 0)) DOES fix the old bltz
   duplication - mwcc now emits retail's single bare bltz, direct path inline,
   trick out of line, byte-identical conversion (nd 111-129 before, 0 here).
   Residual is the loop triple-wall: (1) retail re-sign-extends (s16)i at the
   body head (dsll32/dsra32 before the sll) while mwcc b210 folds that extension
   into the bottom test (2 words/iter x4); (2) retail hoists the D_008872F8 lui
   alone into the preheader and reloads lwc1 %lo per iteration, mwcc either
   rematerializes lui+addiu in the body (nd 59 best) or, with a typed f32 *dv
   local, hoists the full address into $s1 growing the frame (nd 59), or, with
   opt_loop_invariants on, hoists the whole lwc1 out of the loop (nd 106);
   (3) sub.s operand order: retail loads the D LHS first, mwcc loads the RHS
   (p+0x18) first - also survives (0.0f - x) + D reassociation (nd 108).
   lb for the 0x124 check needs the (s8) cast (lbu otherwise). Tail after the
   loop is byte-identical once aligned. Loop walls, s16-index-extension +
   operand-order family, same as func_002b6590/002b9ab0/002b9e10 notes. */
/* measured: re-measured 2026-08-03 with four fresh bodies (recipe-A
   conversion + s16 i + inline D_008872F8[0] LHS + per-site q), best nd 107:
   (s16)i cast at the body head does NOT force the extension (mwcc CSEs the
   bottom-test extension across the back edge), the inline D read keeps
   lui %hi(D_008872F8) in the body (lwc1 %lo folded - no addiu), the
   conversion itself is byte-identical, but the q/i temp colors rotate
   ($a0/$a1 vs retail $a1/$a2) and cascade through the trick path (or-result
   in $v0 vs retail's $a0) so the whole tail misaligns. f32 *dv local hoists
   the full address into the prologue (nd 113); while-loop + loop-scoped q
   folds q into $s0-relative stores (nd 110). Walls corroborated in
   y_CmbCardEff func_00347c70 (lui-hoist + or-register) and y_smap
   func_002b0b10 (lui-hoist + register cascade). */
#pragma push
/* measured: opt_loop_invariants on hoists D_008872F8's high-half constant into the
   loop preheader; the push/pop keeps this target's setting local. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off keeps the local load and index-extension
   ordering stable for this target. */
#pragma opt_propagation off
/* measured: schedule off preserves the D_008872F8 base register through the
   loop body and matches the retail issue order. */
#pragma schedule off
