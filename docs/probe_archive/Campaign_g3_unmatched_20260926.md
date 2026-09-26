# Campaign group 3: probed but not matched, 2026-09-26

Measurements are `tools/fndiff.py` masked words on the body installed in place of
the guarded draft (`#ifdef NON_MATCHING` removed), same toolchain as the tree.
Bodies are banked next to this note. Production for all of these stays ASM.

## mc.c `func_002a5f00` (1552 B): 181 -> 70 words

Body: `Mc_002a5f00_body_20260926.c` (1540 B in the 1552 B window).

- Rewritten from retail: the scroll step is `step = (s < K) ? d * 0.5f : s` with
  the float-to-int conversion in each branch (the draft computed something else),
  the lower list loop tests `idx` before computing x/y, and the 0x3B8 counter
  decrement is guarded by `> 0`.
- `func_00452560` is called directly (the draft cast it to a function pointer,
  which emitted `jalr`).
- `func_002a7920`'s first parameter is `u8`, not `s8`: every caller passes
  `0xFF` and retail materialises 255 (not -1), and the callee masks the value
  with `andi 0xFF` at each use. The mc.c prototype and the guarded definition
  now say `u8`.
- `cur << 16` must be a loop-invariant expression, not a `base` local, with
  `#pragma opt_loop_invariants on`: retail sets `i = 0` before the hoisted
  shift.
- Residual (70): a saved-register rotation. Retail: `p` $s0, `diff`/`cur` $s1,
  `target`/`idx` $s2, `i` $s3, hoisted `cur << 16` $s4. Declaration order moves
  only `p` against `i`/`idx` (70 or 95 over 52 permutations of five
  declarations); the hoisted temporary never reaches $s4.

## k_fldFrame.c `func_0016a110` (2128 B): 251 -> 228 words

Body: `FldFrame_0016a110_body_20260926.c`.

- The `D_007E8020 + 0x20` table walk is
  `for (k = 0; (entry = table[k]) != NULL; k++)` (retail tests at the bottom
  and uses the loaded entry in the body): 231.
- The allocation-free loop sets `i = 0` before the three hoisted `copy.f[1..3]`
  loads: 228.
- Residual: b210 keeps `&work.fracs[i]` in a saved register across the
  `RwV3dNormalize` call and retail recomputes it; `allHit` and `i` swap
  $s1/$s2 (declaration order has no effect: 24 permutations all 228); float
  temporaries in the MAC blocks are coloured differently.
  `opt_common_subs off` is much worse (565, 2388 B).

## code1_0026.c `func_0026cef0` (1296 B): 262 -> 245 words

Body: `Code0026Spline_0026cef0_body_20260926.c` (typed path/point struct).

- The control points are `path->pts[seg * 3 + j]` (12-byte points after a
  4-byte header); retail multiplies `(count - 1) * 3` and then scales by 12
  separately, which the folded `pts[(count - 1) * 3]` form does not reproduce.
- Float register order follows declaration order (dist, t, step, pos).
- Residual: the last-segment branch keeps `count` in a register and hoists
  `arg0 + idx * 12` with the `+4` folded into the loads; the delta after the
  `*pos = at` struct copy reuses the loaded x/y/z registers in retail.

## code1_0031.c `func_00313d20` (656 B): fresh draft 81 words

Body: `C31B_00313d20_body_20260926.c`. Not better than the 22-word frontier
recorded in `FclIndependent_00312c60_00313d20_worker6_20260921.md`.
`((s8 *)(work + 0x2D4))[m]` gives retail's `addu $v1, $s3, $s0` operand order;
writing the flag stores as `*(work + m * 5 + k + 0x2C4)` inside the loop lets
LICM place `m * 5` after `k = 0` as retail does. The branch-2 flag base uses the
raw `$a3` parameter re-extended in retail; no `mode`/`m` spelling, parameter
width, `opt_propagation off` or `opt_common_subs off` reproduced it.

## cmmScript.c `func_0024be40` (672 B): 8 words (unchanged)

A separate pointer local (`row`) at every declaration position, an
`s8 (*)[6]` table view, and folding the two index terms into the subscript all
stay at 8 or grow to 155 (680 B). The `$s0`/`$s2` swap stands.

## code1_0013.c `func_00130680` (1456 B): 256 -> 35 words

Body: `Code0013Label_00130680_body_20260926.c` (1448 B). To install it, first make
the file's `func_0011fd30`/`func_0011fd50` externs agree with the code1_0011
definitions (`(u8 *)` and `(Vec2f, f32, s32, u8 *, s32)`). The old guarded
drafts of 00130680 and 0013ad40 still call the old forms.

- `id` is an `s32` local loaded from `((s16 *)(arg0 + 0x34))[arg1]`. An `s16`
  local re-extends (dsll32/dsra32) before `func_00104c70(s32)`: 101 -> 42.
- Commutative operand order follows named-variable vs expression, not
  source order. Writing `ty = y + slot.y; pos.y = K + (ty + yoff);` makes the
  sum come before `yoff`. The same trick with a float `ty` for the first
  alpha fixes the `mul.s` order: 42 -> 35.
- Residual (35): (1) the addu at +0x2d8 is `arg0 + row` but retail has
  `row + arg0`. Explicit px/py pointer locals, the LabelSlot form and index-first
  forms all leave it unchanged. (2) Retail loads `lw $a0, 0x1be0($s4)` before
  the final `(u8)(alpha * dim)` conversion; b210 converts first. A sprite local,
  the table-index form, an implicit conversion and a float temp all leave it
  unchanged.

## Round 2 (same day)

`func_00130680` and its twin `func_0013ad40` are MATCHED; see
`Code0013Label_00130680_20260926.md`.

### code1_0031.c `func_00313d20`: 81 -> 13 words

Body: `C31B_00313d20_body_r2_20260926.c` (the round 1 body with two changes).

- `s16 m = mode;` instead of `s32 m`. The `s16` copy is not CSE'd with the
  parameter, so branch 2's flag base re-extends the raw `$a3` exactly as retail
  does (81 -> 16). `s32`/`s8` copies, `(s16)`/`(s32)` casts at the use, an
  `s32 mode` parameter and a mode-only spelling all stay at 81.
- The count is written inline, `*(s16 *)(work + m * 2 + 0x2C0)`, not held in a
  `count` pointer local (16 -> 13; `date` then lands in `$a1`). All
  spellings of the inline form (`((s16 *)work)[m + 0x160]`, index-first) tie.
- Residual (13): in the else branch retail colours the second loop's counter
  `k` into `$a2` before the count temporary (`$t0`), so `k`'s `+1` is done in
  place; b210 gives the temporary `$a2` and `k` `$t0`. It also adds
  `m * 2 + work`, while b210 adds `work + m * 2`. Declaration order (60 random
  permutations: all 16 on the pointer-local form), a fresh counter for the second
  loop, block scope, and computing count before date do not move it.
  `tools/permute_ast.py` loses the function's push/pop pragmas (base score 939),
  so it cannot be used here.

### mc.c `func_002a5f00`: 70 -> 58 words

Body: `Mc_002a5f00_body_r2_20260926.c`.

- `if (*(s32 *)(p + 0x3AC) + 1 != 0)`: retail tests `addiu +1; beqz`, not
  `!= -1` (-2 words).
- `scale = D_00761120 * sinf(...); scale = 1.0f + scale;` in two statements
  stops b210 fusing the mul and add into `adda.s`/`madd.s`, as retail does (-9).
  `scale = 1.0f; scale += ...` fuses again (76). A separate `wave` local
  (`scale = 1.0f + wave;`) also fixes the add operand order (58). The literal
  floats (0.001f, 0.2f, 13107.2f, 0.1f, pi) tie with the gp names. The
  declaration order is inert (45-step hill-climb), and `p` declared last is worse (83).
- Residual (59): the saved-register rotation from round 1 (`p` is `$s4`
  here, `$s0` in retail), the f20/f21 x/y swap, and two commutative float
  operand orders (`d * 0.5f` and `1.0f + scale`). Neither spelling order, an
  explicit `(f32)diff` and dropping `d`, nor a declaration initializer for `p`
  moves any of them.

### cmmScript.c `func_0024be40`: 8 (unchanged)

A clean rewrite (`WSCR_0024be40_body_r2_20260926.c`: separate `flag`/`row`
locals, `for` loops, a fresh counter for each loop) reaches 12 at best over 40
declaration permutations, with the same `$s0`/`$s2` row/counter swap. With no
row local, `base[index * 6 + i]` is not hoisted, because the loop calls
datGetFlag (157). With one shared counter for both loops, both loops get the
same register (20). `row = base; row += ...` coalesces `row` with `base`
(16). The 8-word archive draft stays the frontier.

### code1_0026.c `func_0026cef0`: 245 -> 60 words -> MATCH

Body: `Code0026Spline_0026cef0_body_r2_20260926.c` (1292 B of 1296 B, under
`opt_loop_invariants on`).

- Separate scalar out-parameters (`f32 ax0, ax1, ay0, ay1, az0, az1;` and the
  same for the b/c groups), `CefV3` locals, and three `f32[4]` control-point
  arrays reproduce retail's stack layout exactly. `dir` must be a `CefV3`
  (as an `f32[4]` it drops below the structs). Out-parameters that are scalar
  locals let `delta = at - p0` reuse the register copy of `at`.
- `n = path->count` as an `s8` local (loaded once and re-extended), plus
  `idx = (n - 1) * 3; ... path->pts[idx + j]` under the loop-invariant pragma,
  gives retail's hoisted `arg0 + idx * 12` base with `+4` kept in the loads.
  Folding `(n - 1) * 3 + j` inline folds `*3*12` into `*36`, and a hoisted
  `CefV3 *` folds the `+4` into the pointer.
- `sx = bx0; sy = by0; sz = bz0;` read before `dist += len` (retail loads the
  start point before the branch), and `u = t + adv` in a fresh local.
- Residual (60): register colouring only. Retail colours `k` into `$s0` first,
  then seg, arg2, arg1 and arg0 into `$s1`..`$s4`; b210 colours `k` last (`$s4`).
  The same order is reversed for the `$a0`/`$a1`/`$v0` temporaries of both
  control-point loops. Permuting the integer/pointer declarations (30), a
  block-scoped `k`, a `while` loop, testing `*arg0` directly, and dropping the
  `path` local all leave 60.
- MATCH: declare the control-point counter `j` in block scope, once inside the
  first branch and once inside the segment loop. The sampling counter `k` is then
  coloured first (`$s0`), and the `j` loops take `$a1`. When one variable serves
  all three loops, all three get `$s0` (11 words). When the first-branch loop
  shares `k`, `k` goes to `$s0` but that loop is also in `$s0` (6 words).
  Installed with the body as `Code0026Spline_0026cef0_body_r2_20260926.c` plus
  that scoping change.

### code1_0036.c `func_0036ae90`: 292 -> 23 words

Body: `Code0036Light_0036ae90_body_r2_20260926.c` (1504 B of 1504 B, frame -0x140,
under `opt_loop_invariants on`).

- The four constant vectors are struct copies from typed globals
  (`extern RwV3d D_0064E490; stack130 = D_0064E490;`). b210 then emits retail's
  `ld`+`lwc1`/`sd`+`swc1` pairs, and the `+8` half resolves to the `D_0064E498`
  address. The cast form `*(RwV3d *)D_...` gives three `lwc1` (4-byte alignment).
- `stackE0 = *(RwV3d *)(arg0 + 0x994);` and
  `stack100 = *(RwV3d *)(arg1 + 0x20);` as struct copies. Per-field copies promote
  `stackE0` to registers and shrink the frame to -0x130.
- `stack100` is declared before `stackF0` (0x100 against 0xF0).
- `rgba = arg1 + 0x40;` after the `dot < 0` block, read as `rgba[3]` in the
  loop. This is retail's `$fp`.
- The fx ladder tests the odd row first, with `0.5f + (f32)(inner - 1)`.
- The reflection is `t + (t - n)` per axis, with the `t` products in x, y, z
  order (`stack130.x * dot2` first). This fixes the whole MAC block (-15).
- `if (dot3 <= 0.0f) clamped = 0.0f; else clamped = dot3;`,
  `shade = scaled;` stored to all four bytes (the plain `u8` conversion gives
  retail's checked lowering), and `inner++, dst += 0x24` in the for-increment.
- With the loop-invariant pragma, reading `stackE0.y`/`.z` in the loop (not
  `ey`/`ez` locals) hoists them after `outer = 0`, as retail does.
- Residual (23): a three-way saved-register permutation. Retail has `cam` in
  `$s1`, `arg1`/`dst` in `$s2` and `inner` in `$s3`; b210 has `arg1`/`inner` in
  `$s1`, `dst` in `$s2` and `cam` in `$s3`. Declaration order (16 permutations),
  block-scoping the loop variables, an explicit `even` local, and inlining `tmp`
  do not move it.

### mc.c `func_002a4f20`: 391 -> 96 words (fresh rewrite)

Body: `Mc_002a4f20_body_r2_20260926.c` (1796 B of 1808 B, under
`opt_loop_invariants on`). This is the fade-in twin of `func_002a5f00`, written
from that draft rather than the old m2c floor. The old floor's gp names were
wrong: the sine scale at `-0x7F6C($gp)` is `D_00761184` (pi/2), and the
`D_00761304/08/0C` and `D_00761120/74` reads are the same constants that
`002a5f00` uses.

- `func_00452560((void *)arg0)` is a direct call; retail leaves `arg0` in `$a0`.
- `alpha = 255.0f * fade;` is a plain signed conversion (`cvt.w.s`), passed to
  `func_002a6b60`/`6c30`/`2a9f50`.
- `slide = sinf(D_00761184 * (f32)frame / 30.0f);`. The first loop passes
  `x - 350.0f * (1.0f - slide)`, which LICM hoists; the last block uses
  `400.0f * (1.0f - slide)`.
- `wave = 0.1 * sinf(...); scale = 1.0f + wave;` with a separate `wave` local
  gives retail's `add.s $f22, $f0, $f1` operand order. Reusing `scale` or a
  single expression does not. The same change takes `002a5f00` from 59 to 58.
- Declaration order matters here: `p` declared last moves it from `$s4` to
  retail's `$s1` (149 -> 109). A 45-step hill-climb over the declarations
  reaches 96.
- Residual (96, 12 B short): `alpha`/`diff`/`target` rotate over `$s0`/`$s2`/`$s3`
  (retail `alpha` `$s0`); the slide and x/y floats are coloured f20/f21/f22/f23
  the other way round; `d * 0.5f` operand order. b210 CSEs the
  hoisted `1.0f - slide` into the last block, which retail recomputes (one
  `sub.s`, part of the 12 B). Writing the loop term as `(1.0f - slide) * 350.0f`,
  as an `ofs` local, or with an `if` block instead of `continue` does not change it.

## Round 3 (same day)

`func_0036ae90` is MATCHED; see `Code0036Light_0036ae90_20260926.md`. The
lever was scope, not order alone: with `inner` and `dst` at function scope,
declaration order moves `cam`/`arg1`/`inner` (with them block-scoped, the r2
permutations could not).

### mc.c `func_002a5f00`: 58 (unchanged)

- The ae90 lever does not carry over. A 150-step random hill-climb over all
  eleven declarations (seed 11) and five hand orders built on "declared last
  is coloured first" stay at 58 or go to 83.
- Renaming so retail's register sharing is literal (one variable for
  diff/cur, one for target/idx, a separate loop delta) is byte-identical to
  58: b210 splits webs, so a shared name does not change the colouring.
- Block-scoped `idx` in each loop 80; block-scoped top-of-function `delta` 58;
  `target` in its own block 58.
- `u8 *p` as the reassigned parameter (`p = func_00452560(p)`, with the extern
  and caller adjusted for the probe only) 58.
- The residual is unchanged: `p` `$s4` (retail `$s0`), and b210 colours the
  hoisted `cur << 16` into target's `$s1` where retail gives it `$s4`.

### code1_0031.c `func_00313d20`: 13 (unchanged)

- 120-step hill-climb over the 12 declarations with `flag` at function scope:
  13 throughout.
- The retail count base is `m * 2 + work` with `0x2C0` left in the
  displacements. Every spelling of the count that keeps the displacement
  (`((s16 *)work + m)[0x160]`, `((s16 *)work)[0x160 + m]`,
  `*(s16 *)(m * 2 + work + 0x2C0)`, `(m << 1)`, a `W31` struct view
  `->count[m]`) still emits `work + m*2` (13). The forms that emit retail's
  operand order (`((s16 *)(work + 0x2C0))[m]`, `*((s16 *)(work + 0x2C0) + m)`)
  fold `0x2C0` into the CSE'd pointer (86). A `s16 *` count local 87.
- The fully struct-typed flags/slot view is 120; `slot` through the struct is 14.

### cmmScript.c `func_0024be40`: 8 (unchanged)

Folding `index + found` into the pointer expression (three spellings)
costs 155. The statement order `index = index + found;` before `sum = 0; j = 0;`
is retail's.

## Round 4 (same day)

`func_00260e60` is MATCHED (fresh rewrite); see
`Code0026Calendar_00260e60_20260926.md`. That commit also corrects
`func_00260600`'s declared order to `(x, y, depth, color, u8 alpha, variant,
scaleX, scaleY, font, 0)`. It is ABI-identical to the old order, and the
guarded definition is updated to match.

### code1_0026.c `func_00263730` (1408 B): 285 -> 218 words (fresh rewrite)

Body: `C26_00263730_body_r4_20260926.c`. A variant under `opt_common_subs off`
is `C26_00263730_body_r4_cseoff_20260926.c` (291 words, but structurally
closest).

- Signature: `(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 blink,
  u8 *font)`. Retail moves the params in the order a0, a1, f12, a2..., so
  `depth` is third, as in the sibling `func_00262de0`. `alpha` is `u8`,
  because callers materialise 255 and mask computed values.
  `func_00261560` keeps its definition signature (`u8` 4th int, `s32` code:
  the callee `andi 0xF`/`sra 4`s it, and the caller masks the u16 day code).
  `code1_0027.c` still declares that 4th parameter `s32`, which is another
  owner's H011.
- The multiply the old draft dropped is real: `alpha * func_0043c6a0(x)`,
  with `alpha & 0xFF` LICM-hoisted into a `sq` slot
  (`opt_loop_invariants on`). The two fade bytes are separate `u8` locals
  (0x110/0x100). The font word for each `func_00261560` call is read into a
  local before the nested `func_00110c50` call (retail loads it first and
  spills it with `sw`).
- Blocker: retail recomputes `date - 1 + i` and `x + i * 94` at the top of
  every draw block, keeps `dx = px + 15` in `$s6` across into the
  `i == 1/2` blocks, and colours n `$s7`, px `$fp`. b210 value-numbers
  `date - 1 + i` with the header's value, even across `i + date - 1`,
  block-scoped locals, an inline helper, reusing the header variable, and
  under propagation off. Only `opt_common_subs off` gives retail's
  recompute structure, but it then loses retail's `mov.s $f14, $f13`
  (1.0f) and the `$t0 = 1` reuse from the `i == 1` compare.
  `(u32)` casts on the index hoist `date - 1` out of the loop (315).

### code1_0026.c `func_00267b20` (1808 B): 260 -> 232 words (fresh rewrite)

Body: `C26_00267b20_body_r4_20260926.c` (1788 B, `opt_propagation off`).

- Table copies are `*(ShapeCountTable *)D_0063A9E0` casts (4-byte `lw/sw`
  loops). A struct-typed global gives `lq/sq`.
- The depth/clip setup reuses `calendarZeroBytes` and the `func_00262de0`
  shape.
- Each vertex loop is `pt = &src[i]; dst = &points[i];` (src address
  first, then the materialised `sp + 0x5A0 + i*8`), with `col = colors[i]`
  after the float stores. `i = 0` is set before the colour-byte unpack. The
  last loop needs `dst = &points[i] - 1; col = colors[i] - 4;` to get
  retail's shared `i*8` with -8/-4 store offsets. `points[i - 1]` computes
  `i - 1` first.
- Residual: (1) `color` is `$s1` and count/states/src are `$s0`; retail has
  them the other way round. A 50-step declaration hill-climb is inert, and
  holding the colour in `rgb` gives 405. (2) Retail forms
  `sp + shape*8` then `addiu 0x154/0x104` for the outline count/pointer;
  every index spelling and plain local arrays fold the offsets into `lw`.
  (3) Retail spills the third colour byte with `sw` at 0xD0; b210 uses
  `sq` whatever its type (u8/u32/s32, or held in the unused parameter).
  Loop-invariant hoisting of the bytes instead gives the right `i = 0`
  placement but drops the `andi`s and turns the zero loops into `bgtz`
  (358).

### Not attempted this round

The `code1_0049.c` targets use VU0 macro code (`lqc2`/`vmul`...), including
`004941f0`, and were skipped. `sdkSndcom.c` `func_0045b7c0` has a 228-word
draft in-source (not in the group notes); retail keeps per-field pointers
(`addiu $18, $16, 4` then `sw 0($18)`) and recomputes the slot base after
every call, which needs a slot struct plus a per-case pointer study.
