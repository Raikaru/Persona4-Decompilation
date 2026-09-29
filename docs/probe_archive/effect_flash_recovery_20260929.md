# Flash Effect recovery, 2026-09-29

The rotating Flash updater at `0049aa30` is recovered as C in
`src/promoted/effPolygonFlash.c`. The complete owner verifies at 42 MATCH and
7 ASM functions, preserving its previous 41 matches. The function contains
2,164 bytes followed by 12 zero bytes in its 2,176-byte retail window.

The independent relocation check resolves all 42 relocations, including named
calls, HI16/LO16 addresses, and GP-relative constants. The resolved bytes and
retail padding match without masking. Evidence is retained under
`build/first-party-finish-20260929/effects/flash-aa30-clean-contract/`:
`summary.json`, `resolved.json`, `linked.bin`, `owner.o`, and `diff.txt`.
The official whole-owner report is `effects/flash-after-aa30.json` under the
same recovery root.

## Data and lifetime corrections

The effect's `+0x3c` field points to a state header. Its first member points to
the 24-byte particle array; its second member points to the geometry owner.
The previous draft incorrectly treated the state header itself as that array.
The geometry's morph-target vertex field is also a pointer, rather than an
inline vertex array. These indirections are now explicit.

Particle angular velocity, angle, radius, width, and length are floating-point
members. Age, particle counts, fade thresholds, and the recycle flag remain
scalar integer values. Their retail SQ/LQ spill operations arise naturally
from the configured compiler's register pressure. Declaring those scalar
values as `s128` had introduced unnecessary extension instructions and obscured
the actual data model.

The updater now includes the original active-frame interval, geometry lock
mask `0x0a`, both extent vectors, orthogonal direction construction, vector
negations, and unsigned alpha conversions. Its particle geometry and color
paths use complete vectors and initialized scalar values.

## Hardware boundaries

`include/effect_vu0_internal.h` describes the ordered VU0 operations with
actual C input/output objects and compiler-allocated scalar operands. It does
not select general-purpose or floating-point registers or encode stack
offsets. Scalar control flow, arithmetic, random sampling, color stores, and
vertex copies remain C.

Native MWCC accepts an `f32` value in an `r` constraint and supplies the
required bit transfer. The orthogonal-vector Z extraction and X insertion
instead expose the complete VU/FPU exchange with `r` and `f` outputs/inputs;
their transfer hazard NOPs belong to that hardware exchange. Each native
instruction is a complete string literal. A split standalone FPU transfer
was replaced by this combined boundary before promotion.

Color packing names both the actual caller-owned output word and its memory
operand. The output is read as a normal `u32` before its consuming branch.
The assembly contains only the VU conversion, packed-lane transfer, and its
required output store. The scratch-vector stores carry a memory clobber
because the retained `D_00713D10`, `D_00713D14`, and `D_00713D18` declarations
describe overlapping retail storage read by the following scalar copies.

## Compiler options and validation

The function locally enables `opt_loop_invariants` and disables
`opt_dead_assignments`, then restores both settings. Loop invariants reproduce
the shared per-frame constants. Disabling dead assignment removal preserves
the original packed-word stores and subsequent ordinary C loads. Both
settings were measured in the whole owner; no unrelated marker changed.
Source ordering keeps the real particle ordinal and birth budget together,
and the randomization and angular phase values have explicit shared scopes.

The new VU header has zero lint findings. The complete owner plus header has
zero errors; its warnings comprise existing declaration disagreements and
the reviewed optimization pragmas. The old claims that this updater requires
scalar `s128` state or fixed-register assembly have been removed with the
superseded guarded body.

## Radial Flash updater: retained two-word frontier

`func_0049b690` remains guarded and assembly-backed. Its reconstructed C now
emits 2,392 bytes in the 2,400-byte retail window, with two differing executable
words: the color-fill loop uses `$v0` for its `slti`/`bnez` pair where retail
uses `$at`. The eight-byte suffix is zero alignment. The current pre-change
guard measured 1,596 differing words at 2,332 bytes; its historical 507-word
note did not describe the current declaration environment.

The reconstruction follows the state-to-particle indirection and actual geometry
vertex/color pointers. Age, recycling, counts, and fade boundaries are scalar
state, not artificial `s128` storage. Existing VU helpers and compiler-allocated
hardware transfers replace fixed-register and fixed-stack templates.

`build/flashmatch-20260929/final-guarded/` retains the installed source,
compiler receipt, object, instruction comparison, and relocation proof.
All 42 matching C siblings remain exact; all 47 target relocations validate
without wrong or unresolved callees or data symbols. Final conditional-rebuild
and inline-loop-helper probes retain the same two-word residual. No match
promotion or shared-header change is claimed.
