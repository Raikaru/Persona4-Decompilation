# Encounter camera recovery: 001ccdb0

`src/Battle/btlCamera.c` now contains exact ordinary C for `func_001ccdb0`.
The official current-owner report has **46 MATCH, zero ASM**. Independent
proof covers **2,124 bytes in the 2,128-byte retail window**, all **80
relocations**, and a **four-byte zero-only suffix**. The other **45
functions**, their relocation targets, and both allocated-data sections are
unchanged. Source lint reports zero findings.

The catalog's historical `btlAct_NOP` alias does not describe the inspected
table row: `D_005F74C0` index 2, at `005F74E8`, names **ENCOUNT**. Its
initializer is `001CCDB0`, update slot is null, and its label pointer is
`007632F0`. The initializer has the actual `void (u8 *)` contract used by
`001bc660`; no unrelated symbol metadata was renamed.

The reconstruction uses three real 28-byte frames instead of the previous
guarded draft's undersized middle output and separated position/quaternion
storage. It also removes the draft's extra battle-work-pointer dereference.
A whole quaternion assignment retains the grouped load/store sequence.
The large-angle branches precede the small-angle branches, and strict `> 1`
participant tests preserve the retail `slti $at` lowering. The vector-length
calls use the real `RwV3dLength(const RwV3d *)` provider.

The prepared draft initially measured 19 differing words. Branch layout and
quaternion assignment reduced this to six; the strict thresholds closed the
remaining differences. The final canonical-provider spelling remains exact.
All candidate objects, compiler receipts and the complete retired floor are
preserved. Completed jobs were not repeated to recover terminal output.

The supported domain has a valid action/unit and nonempty eligible queried
groups. Ordinary encounter mode is 0, 1 or 2, as produced by `001ef8c0` and
stored by the inspected battle initializer; flag 0x20000000 bypasses the
mode switch. No poses are invented for corrupted ordinary modes or absent
group outputs. The ordered minimum `!(200.0f <= distance)` preserves the
retail unordered behavior. The detailed audit records all output extents,
provider contracts and initialization paths.

Independent build eligibility found one unbound duration name in the draft.
Prime authorized the single `uGpffff81a0 = 0x00761290` entry in each symbol
configuration. Retail `001CD024` loads from GP `0x007690F0 - 0x7E60`;
the bytes `66 66 16 40` encode float bits `0x40166666` (approximately 2.35).
Both exact one-line changes and resolver eligibility before/after are saved.
No code recompilation was needed for this data binding.

A native run of the recovered body with bounded provider doubles passes
**2,560 caller-contract cases**. These exercise all 256 participant-byte
values, all valid mode paths, the special flag path, distance boundaries and
NaN, complete three-pose output, and ordered visibility/spline/duration
calls. The test checks caller contracts; it does not claim to emulate EE
floating-point or the real RenderWare algorithms.
Its retained GCC log warns about the uninitialized duration on an arbitrary
ordinary default-mode path. The external 0/1/2 mode precondition is documented
above; the warning was not silenced or hidden with a fabricated assignment.

Delivery: `build/first-party-next/camera/nop/integration/`.
`proof.json`, `official.json`, `official.o`, compiler/process receipts,
`semantic-audit.md`, dispatch bytes, constant bytes and `duration-binding/`
hold the evidence. Native input/output and its receipt are in the sibling
`native-result/` directory; the exact candidate is in `canonical-length/`.
`retired-floor.c` preserves the previous guarded body and historical notes.

Integrated source SHA-256:
`cd162a500cba5449e55de08b7daa6af6762eb9ab0103b33776427a120ce23249`.

Official object SHA-256:
`fe37890d5786a728b89dfb5ae4470272b91c42d33f1c13e843f560cb870f8a0e`.

Resolved target SHA-256:
`a133660e49901dafb97cff30ac580f2e5faefa08976a7a2a378d817bdea30137`.

The existing `001c04e0` and `001bcd40` recoveries were not recompiled or
reintegrated for this task. Their visibility-provider handoff is preserved
separately in `Visibility_001bcd40_20260920.md`. Git checkpointing, aggregate
counts, full-image gates and publication remain prime's responsibility.
