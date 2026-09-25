# Fusion skill picker `00312c60` recovered, 2026-09-25

`src/Event/Fcl/fclCombineMisc.c` `func_00312c60`: 1152/1152 bytes, MATCH; the unit
is now 11/11 MATCH with no INCLUDE_ASM left. It supersedes the 1136/1152 frontier in
`FclIndependent_00312c60_00313d20_worker6_20260921.md`.

Relocations: `D_00642F30` (assert file, lines 0x3AF and 0x327, plus the 0x3CC
allocation marker), `D_00642F50`, `D_00641C20` and its `+1` field (the tier table
`{s8 minCount; s8 picks;}[9]`), `D_00641C40` (`s16 [][19]` base weights),
`D_00641E60` (signed-byte rates), `jtbl_008873E8`/`EC` (alloc/free), and the
gp-relative `iGpffffb3b4`/`iGpffffb3d4`.

## Shaping levers (in the order they closed the diff)

- Widths: the pool holds signed halfwords, the weight buffer holds 32-bit words
  and the base weights are `s16`. With these widths the body was already 1152 bytes
  and 204 words off.
- `#pragma opt_loop_invariants on` is required. Without it the body is 1164 bytes
  and 250 words off.
- Weight loop: `weights[k] = weight(...); total += weights[k];`. Using a
  temporary value (`w = ...; weights[k] = w; total += w;`) makes b210 keep
  `(s32)k` in a saved register across the assert call. Retail re-extends k after
  the call.
- Pick: pass the pool entries directly as `((s16 *)pool)[pick]` to both calls.
  With a `slot` pointer the compiler reused the loop condition's extension across
  the scan loop and dropped 8 bytes.
- The tier test is written `table[step].minCount <= count`. Written as
  `count >= min`, it emits `slt $v0` instead of retail's `slt $at`.
- The pick bound is `u8 n = pool[0x60];`, captured after the roll. This matches
  retail's `lbu` placed before `pick = 0`.
- The first loop's bound is `i < (s8)arg2` with no `limit` local, so the hoisted
  sign extension follows `i = 0`. This fixed the rotated
  `$fp`/`$s4`/`$s5`/`$s7` colouring of arg1, limit, row and cell.
- Argument scheduling: `func_002e6f90(pool, (s16)*cell)` and
  `func_0010cc20(arg0, ((s16 *)pool)[pick])`. These load the second argument
  before the first, as retail does.
- Saved-register colouring came from a hill climb over declaration order (about
  180 compiles). It took the diff from 62 to 12 words. The winning order is
  `pool, weights, remaining, total, taken, roll, n, k, i, row, scan, running, cell,
  id, j, freeSlots, pick`.

Inline helpers (`fclSkillPickCount`, `fclSkillWeight`, the latter holding the
line-0x327 assert) were neutral for codegen. They are kept because the assert
line predates this function.
