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
