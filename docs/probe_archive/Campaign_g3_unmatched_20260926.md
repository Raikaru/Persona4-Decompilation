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

### mc.c `func_002a5f00`: 70 -> 59 words

Body: `Mc_002a5f00_body_r2_20260926.c`.

- `if (*(s32 *)(p + 0x3AC) + 1 != 0)`: retail tests `addiu +1; beqz`, not
  `!= -1` (-2 words).
- `scale = D_00761120 * sinf(...); scale = 1.0f + scale;` in two statements
  stops b210 fusing the mul and add into `adda.s`/`madd.s`, as retail does (-9).
  `scale = 1.0f; scale += ...` fuses again (76).
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
