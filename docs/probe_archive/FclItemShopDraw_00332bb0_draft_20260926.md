# Item shop state machine `00332bb0`: 13 words from a match, 2026-09-26

`src/Event/Fcl/y_fclItemShopDraw.c` `func_00332bb0` is 37392 bytes: 9345 code words
and 3 zero pad words. It is the last INCLUDE_ASM in the unit, and it is still not
a match. The old `#ifdef NON_MATCHING` draft was about 5600 words and structurally
wrong. This session rewrote the whole function from the retail asm.

- Best draft: `FclItemShopDraw_00332bb0_draft_20260926.patch`, which applies with
  `git apply` on `claude/dreamy-dirac-mtzltf`@59e338e. The same body and the list
  of declaration changes are in `FclItemShopDraw_00332bb0_body.c`.
- Measured with the patch applied: `verify.py` gives NONMATCHING, with
  normalized_diff 14 bytes and an object of 37380 bytes, which is exactly retail's
  code size. `fndiff.py` shows 13 differing words (reloc-masked). The other 8
  functions in the unit stay MATCH with all of the declaration changes.
- Residual: case 5, D_008C024E&0x40 branch, inner `switch (work[1])` case 0,
  4-item loop at 0x33528C. The loop counter and the index+font value have swapped
  registers (`$s4`/`$s5`): retail puts the counter in `$s5` and index/font in `$s4`.
  Nothing else differs.

## Levers that closed the diff (in the order found)

1. **`func_002b2970` returns `F2_0033` by value.** It has a hidden `$a0` pointer.
   Written as
   `func_0033d3e0(spr, func_002b2970(x, y), func_002b2970(x2, y2), ...)`, each call
   gets its own struct-return temporary. They are allocated top-down in source
   order from `sp+0x748`, which reproduces the 0x770 frame and every `sp` offset
   exactly. `func_002b2a60` works the same way (`FclDrawColor` temporaries at
   0x76C, 0x768 and so on). In `func_002caa10`, the position (`F2_0033`) and colour
   (`FclDrawColor`) are passed by value (`ld a0` / `lw a1`). The matched callers
   in `func_0033c490` and `func_0033bf90` still match with the struct-return
   prototype.
2. **Floats-first prototypes.** `func_0033d4e0` and `func_0033d520` are
   `(u8 *, f32, f32, s8, s16, s64)`. Retail loads a gp literal into `$f12`
   between `lw $a0` and the int immediates, which is the evaluation order of
   float-first parameters. `func_0033d630` needs `u8 alpha` in this unit: with that
   type the `lbu` is scheduled after `ld a0` / `lwc1 f12`. The definition in
   `code1_0033.c` does not match with `u8`, so the u8 view stays local, following
   the precedent of the local `FclDrawColor` view of 2a60.
3. **gp constants are literals.** `iGpffff8504` is `0.1f`, `iGpffff809c` is
   `0.7f`, and the others are 2.7, 1.05, 0.01, 0.6 and 0.35. `iGpffffa928` is
   `"%s %d"` and `a930` is `"%d"`. All are in .sdata as `R_MIPS_LITERAL`/GPREL.
4. **`#pragma opt_loop_invariants on` around the function.** Retail hoists the
   140/340/20/10 constants and the `(s8)1` out of the loops.
5. **Every `for` loop gets its own `s16` counter.** One shared `i` gives ~1600
   diff units, because b210 colours it as one node across the whole function.
   Retail puts call-free loop counters in `$a*`. With 43 separate counters the
   diff dropped to ~300. Merging counters per case made it worse (455).
6. **No `f0` local and no `slot` pointer local.** Re-read
   `*(f32 *)(work + i*4 + 0x2FC)` in every condition, and write
   `*(void **)(work + i*4 + 0xNN)` at every call. The CSE temps then recompute
   `(s16)i` exactly where retail does (the dsll32/dsra32 pairs inside the branches).
7. **`s8 flag = 0;` is the only entry initializer.** The loops that retail runs
   with no init (case 12, case 5 inner case 1, and cases 5/9/16/17) are
   `for (j = 0; ...)` on a separate `s16 j`. mwcc gives `j` the zeroed `$s0` and
   drops the move, but keeps the `b test` block. A plain `for (; j < N; ...)`
   loses that block. This fixed the global colouring (`$s0` flag/j, `$s1` arg0,
   `$s2` work) and took the diff from 205 to 132.
8. **Per-site fresh `font`/`index` variables.** A greedy search over which
   assignment sites get a fresh variable (`index_sNNN`, `font_sNNN`) took the diff
   from 132 to 27. The case-5 inner loop also needs its own `fn5`/`idx5`/`co5`, and
   it has to share its counter with the twin loop in case 11 (`i31`). Every other
   counter choice leaves the counter elided into the known-zero `$s0`.
9. **Small spellings.** `func_002e2670() > 5` (gives retail's `slti $at`; `>= 6`
   gives `$v0`). `!func_002bb1c0(x)` (no s8 re-extension). Compare
   `W3 * func_0033cbc0(..) > func_002e7a60()` in that order. Chain
   `*(s16*)(p+0x100) = *(s16*)(p+0x102) = 0`, and store `-90.0f` to
   BC/C0/C4 right to left as one chained assignment. Store `(u16)(...)` into
   the +0xF8 fields.

## Ruled out (measured)

- Declaration order of the locals had no effect on the colouring once the
  structure was right. Swap and move searches gave at most ±2.
- For the last loop, all of these stayed at 14 to 33: `while`, `do`, and an s32
  counter with `(s16)` casts; a named `slot`; an `F2_0033 *` coords pointer; an
  `s64 layer` local; sharing the counter with any other loop variable (only `i31`
  works); sharing idx/coords/font with the case 11 twin loop; an index
  computation order different from retail's; a `static inline` helper (it shifts
  the struct-return temporaries); and the `register` keyword.

## Next step

Only the counter-versus-index/font priority in that one loop is left. Try making
the index value longer-lived, for example by reusing it after `func_0046d280`.
Another option is a search over counter/index/font sharing sets that spans both
twin loops (case 5 inner case 0 and case 11 at 0x3393D4) jointly, not one loop
at a time. The 43 counters and the numbered `_sNNN` locals should be merged back
into readable names once the function matches. Many counters can merge into `j`
alone at the same diff (24 measured), but not all of them together.
