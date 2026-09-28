# Compiler Floors

A compiler floor is a retail instruction shape that recorded probes could not
produce with a given compiler build and configuration. It is a measured
limit, not proof that no C source can match. A function whose only
difference is a recorded floor stays on its `INCLUDE_ASM` fallback until
someone has new evidence: a different source shape, compiler configuration
or ABI fact. Repeating the recorded probes does not count.

The evidence is in `docs/compiler-floors.md` and in the compiler-floor
sections of `docs/matching.md`. Read both before you record a new floor or
retry an old one.

## Resolved by the per-unit toolchain

Several differences looked like floors under build 210 but came from the
wrong compiler or flags for that unit. They are now reproduced through
configuration (see [The Retail Build](The-Retail-Build)):

- **`movz` / `movn`**: the recorded b210 probes did not emit them; builds 74,
  119 and 151 emit them from a plain ternary. The RenderWare units use
  build 119.
- **Top-tested `while` loops in RenderWare**: build 119 at `-O2` produced
  bottom-tested loops; the verbatim source reproduces retail from `-O3` up,
  and the block uses `-O4`.
- **Small same-unit callees inlined in RenderWare**: `-inline auto`.
- **Callee-saved registers stored with `sd`**: the MWCC builds on hand used
  `sq` at every level tried; those units are ee-gcc 2.96.
- **An alignment `nop` after a filled back-edge delay slot**: `-O2,p`, set per
  unit in `config/speed_units.txt`. No pragma tried reproduced it.

## Recorded limits

- **`movz` / `movn` under build 210.** Still recorded for b210 and for
  Atlus's code. The probes covered six source shapes, every optimisation
  level, the `conditional_move` options and pragmas, and seventeen other
  MWCC builds.
- **A parameter load before `sd $ra` in the prologue** (`addiu $sp`,
  `lw $vN,0($aN)`, `sd $ra`). `func_003cc250` was compiled under every
  cached MWCC build at several levels and many flags, and every one stored
  `$ra` first. A source shape that makes b210 load the parameter earlier would
  reopen it.

## Not floors

`docs/compiler-floors.md` also lists shapes that were once recorded as
floors and later matched: commutative operand order, `addiu` against
`daddiu`, and a missing `nop` before the final `jr`. Check that list before
giving up on a similar difference.

## Recording a floor

A difference is a floor candidate when it survives the documented source
changes, a pragma sweep (`tools/pragma_sweep.py`), the other compiler builds
and the relevant flags, and each probe is written down. Put the best body
behind `#ifdef NON_MATCHING` with a note saying which limit it hits and what
was tried. Failing after a few attempts is not a floor.
