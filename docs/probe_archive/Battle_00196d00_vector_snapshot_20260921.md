# 00196d00 movement update recovery

The production owner is `src/promoted/code1_0019.c`. The recovered callback
updates the unit's direct or generated movement route and reports completion.
It now uses ordinary C with the real `u32(void *)` packet callback contract.

The padded scratch frame was replaced by three real three-component vector
objects and three XZ pairs. Each vector has aggregate and component views in
a union of equal-size members. Copying the destination vector before clearing
its Y coordinate reproduces the retail snapshot and subsequent reloads. The
two flattened vectors are then subtracted component by component. The existing
offset-first address helper preserves the final route-record address addition.
No new optimization pragma, assembly, volatile access, synthetic padding, or
unused storage is introduced.

The owner-local vector alias now uses the existing `struct RwV3d` tag and the
same three `f32` fields as the provider. `func_00196040` is declared with its real
float result, two unsigned masks, three typed output pointers, and unsigned
options. `func_001eec50` takes `void *`. The active sibling `func_00194ff0` is the
only other call site affected by those declaration corrections; no remaining
guarded sibling calls either corrected provider. No provider owner or shared
header was changed.

## Native proof

Evidence is under
`build/first-party-finish-20260920/battle-worker5/00196d00/`.

The sealed compile invokes the configured native MWCCPS2 3.0.1 b210 executable
on the actual live owner path, with `-O2 -Iinclude`. Its receipt is
`sealed/current/compile.json`; the compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

`sealed/current/result-decoded.json` records **1,736 matching executable bytes
in the 1,744-byte retail window**, including the mandatory final `jr` delay
slot. Only the two following retail alignment NOPs are outside the emitted
function. All ten call relocations were resolved independently before comparing
the unmasked bytes. No code relocation was excluded from that comparison.

All 150 sibling function bodies and canonical relocations match the original
current-owner object. Allocated data bytes, sizes, alignment, and relocations
are unchanged; the complete records are in
`sealed/current/allocated-data.json`. There are no added helper functions or
new owned data. The integrated source SHA-256 is
`138bdee92618fbf78fe74cef910b8389fb8e557c507895d317fc377f4185df49`.

Real provider and caller sources are frozen under `abi/sources/`. The packet
callback typedef and both callers agree with `u32(void *)`. Native full-owner
provider builds also resolve exactly: `00196040` is 1,480/1,488 bytes,
`001eec50` is 16/16, and `001ef110` is 904/912. `001eed10` retains its existing
typed guarded source and ASM provider. `003e40b0` retains its ASM provider,
whose actual instructions read and write three floats and return the length
in `$f0`; it is not claimed as a newly recovered C function.

The default owner verification report is `sealed/verify-owner.json`.

## Earlier evidence

The current guarded baseline was 1,728 bytes with 120 differing words. A real
vector snapshot plus separate local objects restored executable coverage;
measured stack declaration order left one differing address-add word. Reusing
the existing helper closed that word. Canonical callback/provider declarations,
the union representation, and the final integrated source all retained exact
bytes independently.

The unrelated `00375f00` shuffle reset was not promoted. Five whole-reset
inline-lifetime hypotheses produced a smaller 128-byte function and did not
improve its existing two-word residual. That evidence remains in the separate
`battle-worker5/00375f00/` scratch tree; it is not an accepted recovery.
