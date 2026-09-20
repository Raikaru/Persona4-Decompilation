# General action camera: func_001be990

The Persona 4 general action camera is recovered as 2564 executable bytes in
its 2576-byte retail window. All 73 code relocations resolve exactly, the
remaining twelve bytes are retail zero alignment, and its four-byte compiler
literal is independently placed and compared with retail.

The reconstruction begins with Persona 3 FES `btlCameraFrameAction` from donor
commit `04d95e2`. The complete Persona 4 assembly, both decompiler hypotheses,
current caller bodies, and the active providers were read before acceptance.
The donor is not copied indiscriminately: Persona 4 rejects the excessive-angle
path with return zero, uses the initialized candidate point during interpolation,
and has its own constants, visibility operations and success returns.

## Measured source changes

The first typed donor port emitted 2576 bytes and had 25 aligned instruction
edits. Giving the excessive-angle rejection its actual early return, and
sharing the final successful return, recovered the retail block layout.
Changing the height operand order left seven aligned edits at 2564 bytes.

The duration limit is the numeric constant `2.15f`. An inferred external
variable caused MWCC to retain a loaded value across both tests, introducing a
copy and deleting the second literal load. Writing the actual constant restores
both retail loads and leaves one multiplication operand difference.

The last instruction is recovered by putting the unit scale in the existing
`x` temporary immediately before multiplying it by the freshly read height:

```c
x = *(f32 *)(unit + 0x2C);
half = *(f32 *)(unit + 0x8C) * x;
```

The temporary is read by this calculation and is then overwritten by the
near-angle conversion before its later polynomial uses. No dummy use or
uninitialized lifetime is introduced. Other measured snapshots produced three
different instruction words; the used temporary's lifetime is material to this
compiler's operand selection.

The accepted body has no new optimization pragma, ordinary-CPU assembly,
volatile access, synthetic padding, or extra helper call. Bounded helper and
optimization experiments are retained in scratch with their unsuccessful
measurements; they are not part of the accepted source.

## Literal and storage proof

Retail `0x00761220` contains `9a 99 09 40`, exactly binary32 `2.15f`. The compiler's
four-byte literal section is placed at that address and its complete bytes are
equal. Four direct references in retail load the value; the audit found no
direct store, constant-address pointer escape, or source write. The merged retail
segment is writable, so this is evidence for a recovered numeric constant, not
a claim that segment protection proves immutability.

The body uses two complete 28-byte poses, a 40-byte interpolation cache, and a
64-byte matrix. The replacement-matrix call initializes the matrix components
used by the subsequent post-concatenation and vector transform. The cache flag
guards the use of its interpolation scalar. Both submitted poses are initialized
on every accepted control-flow path. The two submission arguments address the
whole poses rather than implying that the provider consumes only three floats.

The new calls use the actual typed unit-center and vector-normalization
contracts. The far-angle rejection, NaN-sensitive negated `<=` tests, 550-unit
minimum distance, 25-unit vertical limits, and 1.75 close-mode duration reproduce
Persona 4. The visibility operation retains its real flag and alpha changes.

## Battle-state preconditions

Like retail, this callback requires initialized camera/action/unit records and
nonempty selections for the bounds queries whose outputs it consumes. The first
query requires at least one group-0/1 unit with flag `0x8` at unit offset `0x9C`.
The target-group query requires a selected-group unit with that flag and without
flag `0x1`. The single-target path requires its first target record.

`func_00196040` returns without writing the requested outputs for an empty
selection. The immediate camera callers do not independently prove the complete
global battle-state invariant. No reachable violation was identified in this
review, but this recovery does not claim defined results for arbitrary empty
fixtures or corrupted battle state. Adding initial values or skipping those
operations would change the retail program and is not used as a matching device.

## Evidence

`build/first-party-resume-now/camera-action/` contains the complete variant
sources, configured compiler receipts, objects, instruction alignments and
resolved-word comparisons. `camera-release/proof.json` freshly compiles the
canonical combined source and proves this function and the pair/duel callbacks,
the new literal, all 120 non-target sibling functions, and unchanged existing
allocated data. `general-camera-review.md` and `general-camera-literal-audit.json`
contain the independent source and literal review.

The resolved general-camera body SHA-256 is
`4328c46c7502fae873159179aaa266dd776df07c9c4746bfd5199607f482d2d3`.
The ordinary current-owner verifier remains the reproducible public entry point:

```text
python tools/verify.py src/promoted/code1_001b.c --show-mismatches --json build/camera-verify.json
```
