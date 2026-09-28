# Fcl resource and digit renderers

Two first-party assembly fallbacks are replaced with C:

| Function | Owner | Executable bytes | Retail window | Zero alignment suffix |
| --- | --- | ---: | ---: | ---: |
| `0032c660` | `src/Event/Fcl/y_fclCombineDraw.c` | 7,944 | 7,952 | 8 |
| `002ba5d0` | `src/promoted/code1_002b.c` | 920 | 928 | 8 |

Both use the configured b210 compiler and match every resolved instruction.
The resource renderer preserves constructor-backed positions and native color
packets. The upper row snapshots its position before changing state; the lower
row reads the live position afterward. Its two clipping slots remain separate.
The actual resource provider `002b6c30` and forwarder `003205f0` now share a
signed-halfword resource interface. The already matched `003146c0` forwards the
actual task value argument to `0011b9e0`; it earns no additional matching credit.

The digit renderer retains separate position, color and bounds snapshots across
draw-slot writes. Its real interface places floating-point depth before the
integer layer. All four calls in `y_fclCombine.c` pass `46.0f` followed by `0x59`.
Their corrected declarations and argument order preserve the entire caller
object. The scoped zero-predicate helper reads the actual signed halfword and
keeps that read separate from the sentinel comparison. Its additional H003 lint
warning was reviewed against the emitted code; no lint rule was suppressed.

Seven affected owners were compiled from the exact publication sources. Four
objects equal the independently sealed complete text/data proofs; three equal
their authenticated baseline objects. The check covers 317 function windows and
preserves all 315 existing neighbors. Five whole objects are byte-identical to
their baselines, including both resource and digit consumer objects. No existing
C match was moved back to assembly, and every previous allocated data span is
preserved.

The complete public verifier reports 9,518 MATCH and 3,584 ASM across 13,102
windows; first-party attribution is 6,698 MATCH and 163 ASM across 6,861 windows.
The two-function delta is measured against `67dd74d`.

The final link keeps all 8,376 previous physical source memberships, with both
new C bodies supplied by their recorded owners. The rebuilt load image has SHA-1
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the rebuilt retail executable has SHA-1
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Both equal the configured retail hashes.

Local reproduction and evidence are retained under
`build/batches/fcl-digit-v1`, `build/publication-verification/fcl-digit-v1`, and
`build/publication-gates/fcl-digit-*` in the publication worktree. Original
source preimages, sealed patches, owner objects, interface censuses, and complete
resolved proofs remain in the sibling
`build/cos20335-publish-20260928/publication/row-transition/c660-standalone-publication`
and `build/cos20335-publish-20260928/fcl-row-draw-finish/digit-independent`
directories. Pending row-animation and Combine/shop candidates are separate.
