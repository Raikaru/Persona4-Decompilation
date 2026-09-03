# Compiler Floors

A floor is a retail instruction shape the configured compiler will not emit
from any C, measured rather than assumed. A function whose residual is a floor
stays on `INCLUDE_ASM`; probing it again wastes time. The full evidence is in
`docs/compiler-floors.md` and the "Known compiler floors" section of
`docs/matching.md`; this is the summary.

## Resolved by choosing the right compiler

Several "floors" were the wrong compiler, not the wrong C. They are listed
here so nobody re-measures them.

- **`movz` / `movn`** - build 210 never emits them; the RenderWare block was
  built with build 119, which emits them from a plain ternary. Resolved by the
  per-unit compiler configuration.
- **Top-tested `while` loops in RenderWare** - build 119 inverts them at
  `-O2`; the block was built at `-O4`.
- **Inlined same-unit callees in RenderWare** - `-inline auto`.
- **`sd` for callee-saved registers** - those units are ee-gcc 2.96.
- **Alignment nop after a filled back-edge delay slot** - `-O2,p`, per unit.

## Real floors for build 210 game code

- **`lw` before `sd $ra` in the prologue**, and a parameter `move` interleaved
  between the `sq` saves: every MWCC build on hand keeps the `$ra` store first
  for that source. Measured across builds, levels and many spellings
  (`func_003c47c0`, `func_003cc250`, `func_003e8ed0`).
- **`slt $at` entry guard** (`slt $at, $zero, $v0; beqz $at` with the loop
  init in the delay slot) where the compiler emits `blez`.
- **Allocator-pool register allocation**: fifteen independently hoisted
  `%hi()` base registers per loop in the `effLineNova` / `effPolygonRing`
  family.
- **Hardware access**: the DMA and scratchpad functions (`fromSPR`/`toSPR`
  family in `code1_003a.c`/`003b.c`, `func_00174e10`, `func_0016bdd0`) use
  `bc0f`, `mtc0` and direct scratchpad reads. Inline asm is allowed only for
  the privileged instructions C cannot express (`tools/decomp_lint.py`'s
  allow-list); packed MMI ops are not on it because their absence is an
  optimiser finding, not a language limit.

## How a floor gets on the list

Measurement: the residual survives the documented levers, the pragma sweep,
the other compiler builds and the flag axis, and the note in
`docs/matching.md` records each probe. "It resisted a few attempts" is not a
floor.
