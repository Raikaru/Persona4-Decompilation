# Community portrait renderer, 0035aff0

Date: 2026-09-30. Owner: `src/promoted/code1_0035.c`.
Research baseline: `d8561cfa992612504ef8fc6186c56b86da44ed30`.
Retail window: 0x0035aff0, 2,784 bytes.

## Result and scope

Whole-owner `verify.py` reports **MATCH**, 2,772 bytes, normalized difference
zero, followed by twelve retail zero bytes. All **39 relocations** resolve to
exact retail fields, including both GP-relative constants. The owner has 79 C
matches and one ASM function (rank24, `func_003599c0`). This rank50 change does
not modify that function, its guard, or any other sibling body.

The research audit verifies all 79 siblings' instruction bytes, sizes and
relocation destinations, in both ordinary production and `-DNON_MATCHING`
builds. Allocated non-code data is unchanged in both modes. The report's
whole-production raw-equality fields are false because the target itself is
now compiled C with a shorter zero tail; they do not represent sibling drift.
No full link/hash run is claimed for this research checkout. Separate
minimal-main integration is recorded in
`Community_portrait_0035aff0_main_20260930.json`; publication still requires
review and exact-commit CI validation.

The earlier candidate was 2,792 bytes / 164 alignment edits / 450 differing
words. It captured the texture before `func_0034f1e0`, contrary to retail's
post-callback load. That error was removed before tuning. Full typed work,
byte RGBA, live table slots, actual index pairs, and natural loop structure
then reached zero edits. A lower instruction count was never treated as proof.

## Objects and live values

- `func_0035adc0` allocates 0x144 bytes. `func_0035bc10` establishes position,
  scale endpoints, signed-byte portrait ID, transition frame and flags.
  `CommunityPortrait` describes that allocation, with explicitly unknown
  regions rather than invented state. Its resource texture is at 0x3c and
  module reference at 0x140. The task's generic SDK work pointer is at 0x38.
- The entry work pointer and screen depth are captured before the camera
  query. Visibility is read through the task again afterward. If the task's
  work pointer changes during the query, the new work decides visibility but
  the entry work still supplies interpolation and geometry.
- The renderer returns the actual `func_0035bad0` transition blend. Opacity
  remains a byte, as required by its caller and established owner contract.
- Texture/raster is loaded after the reset helper. Flags are loaded after
  the first primitive callback. Geometry scale, initial UV direction, depth,
  reciprocal near clip, and the two light positions retain their observed
  lifetimes. Per-vertex position reads remain live through normalization calls.
- A full four-byte `CommunityColor` supplies flat-pass RGBA. The native byte
  conversions produce retail's unsigned conversion sequences; no signed
  float carriers or integer/float pointer punning remain.
- Each vertex is the actual 64-byte Sky2 field layout. Ten floats are written:
  screen XYZ, UV, reciprocal depth, and RGBA. No synthetic zero stores are
  added to cameraZ, fog padding, normal XYZ or alignment padding. Exact EE
  stack offsets 0x9f0 and 0x130 provide 16-byte-aligned vertex storage.
- Thirty `IndexPair` objects are initialized within capacity32 (128 bytes),
  equivalent to the observed 64-halfword allocation. Six strips read five
  adjacent pairs each. All values lie in 0..34, so the SDK's unsigned-halfword
  reads and the positive signed-halfword objects have identical values/bits.
  The two unused tail pairs are never passed to a consumer.

## Callback ABI and physical versus semantic vertex use

`include/rw/plcore/badevice.h` declares signed-word `RwBool` results for both
primitive callbacks, with (primitive, vertices, vertexCount) and
(primitive, vertices, vertexCount, indices, indexCount). `RwImVertexIndex` is
16-bit (`include/rw/sky2/rwplcore.h`). The target forwards all five indexed
arguments, uses three for ordinary primitives, and does not invent a return
or preserve accidental argument-register values. `RpSkyRenderStateSet` has its
actual signed-word return and pointer-valued payload. Callback addresses are
retained as table addresses, while the slot is reloaded for every call.

Retail installation at 0x0040d110 binds the ordinary/indexed callbacks to
0x0040c0f0 and 0x0040d0a0. For primitive4 the data tables at 0x0070c2e0 and
0x0070c300 select 0x0040bac0 and 0x0040ca00. Those backends physically copy
**all four 16-byte blocks** of each vertex, including unspecified lanes. A
64-byte buffer is therefore required even though not every field has a
semantic value. The native fixture does not read the unwritten float members.

The initialized-field claim is supported by the **actual active VU1 program**,
not merely by the SDK statement that normals are unused:

1. Reset helper `func_0034f1e0` sends render state14 with value0. The device
   descriptor at 0x0070c230 points to setter0x003f5070; its state14 branch at
   0x003f50cc reaches 0x003f5998, and value0 reaches 0x003f59bc. The AND/store
   at 0x003f59c8/0x003f59d0 clears selector bit0.
2. Both draw dispatchers choose the no-fog descriptor 0x00753330. Its triangle
   program pointer at +8 is 0x00559600, uploaded as 47 VU1 instruction pairs.
3. The program loads vertex qword1 using **xyz masks**, excluding fog padding.
   It never loads qword3, which contains the normal and alignment padding.
   Position qword0 is loaded as xyzw, but w is overwritten by MFIR.w at
   instruction22/23/24 before any use. Arithmetic only sees position XY/XYZ
   before those overwrites. The three position outputs are at29/30/31.
4. The exact control transfers are4→43 (empty input, delay5),36→11 (triangle
   loop, delay37), and45→1 (MSCNT restart, delay46). E43 terminates after
   delay44. Block11..35 has no branch, so each position load reaches its w
   overwrite before output. The backedge restarts before both the load and
   overwrite. Empty input has no vertex output. Restart also passes the input
   check and loop entry; it cannot skip the overwrite.

`Community_portrait_0035aff0_pipeline.py` checks the retail words and performs
bounded lane-flow analysis of all47 pairs, rejecting unrecognized operations.
Its JSON receipt gives program SHA-256
`be30f12b217e3700635fe05b6067f79b1568193f87cd326b9baa4fbc37fc9bfa`.
This is a proof for the installed no-fog strip pipeline, not arbitrary callback
replacements, GPU emulation, or a general VU emulator. Instruction field
interpretation was cross-checked against PCSX2's primary disassembler files
linked in that receipt; the raw words and branch targets are independently
checked against this project's authorized retail input.

## Grayscale conversion domain

The retail normal at 0x0064cd30 is exactly `(0,0,1)` (raw words 0,0,0x3f800000).
The actual `func_0035bd20` forms each light direction with Z=20, normalizes it,
dots it with that normal, adds both projections, and clamps with
`if (!(total <= 1.0f)) total = 1.0f`.

For supported portrait state, creator/reset coordinates are finite, dimensions
are bounded by the finite scale transition, and the light radius is finite.
Each direction has strictly positive norm because Z=20 even when XY coincide.
Its normalized Z is in (0,1], so the sum is positive and at most2 before the
clamp, and the returned factor is in (0,1]. Multiplication by255 therefore
makes the byte conversion defined. There is no zero-length normalization
case. The native test separately checks coincident XY and an injected NaN:
the actual helper's negated comparison clamps NaN to1 before byte conversion.
That edge test does not claim invalid/nonfinite geometry is renderable. The
fixture's ordinary scenarios stay within the supported finite domain.

## Compiler inputs

One balanced push/pop scopes these real compiler settings:

- `opt_loop_invariants on`: hoists byte color conversions, row bases, and
  index-pair bases; the faithful typed-table candidate went from153 to42 edits
- `opt_lifetimes on`: retains the observed phased scalar register roles
- `opt_pulloutconstants off`: avoids unrelated call-crossing float constants
- `opt_propagation off`: retains provider table addresses while leaving slots
  live, and keeps the entry task transport separate from its visibility view

Direct byte-to-float casts, table pointers and the equivalent `vtx > 35`
condition close the residual. No schedule-on, volatile, artificial carrier,
invented ABI, 64-bit loop counter, padding local, or inline computation assembly
is used. The explanatory comment in the owner covers the H003 advisory.

## Tests and reproducible receipts

The native fixture extracts the final renderer and actual providers
`func_0035bad0`, `func_0035bd20`, and `func_0034f1e0` unchanged. A separate raw-
offset oracle checks ordered calls, initialized vertex fields, indices,
complete work mutations, and return values. Trigonometry, normalization and
packet boundaries are instrumented deterministic substitutes; these tests do
not claim retail floating hardware or GPU execution.

At both Clang19 O0 and O2, freestanding i386 under qemu-i386 with undefined and
bounds traps enabled:

```
community-portrait cases=8209 checks=5768608
```

Coverage includes all256 alpha bytes, all sixteen low flag combinations,
zero/negative signed IDs, loaded/unloaded state, frame wrapping, distinct
scales, camera-time task swaps, reset-time texture changes, post-draw flag
changes, changing callback slots, vertex-buffer modifications, and live work
mutations during every normalization call. **27 negative controls** are
rejected at both levels, including three actual-provider mutations.
Static assertions use exact source declarations for vertex/color/task/work
sizes and offsets. No target-body rewrites are used to compile the fixture.

Commands, with the normal toolchain environment and authorized retail input:

```
python tools/verify.py src/promoted/code1_0035.c --json owner.json
python docs/probe_archive/Community_portrait_0035aff0_audit.py --output audit --reference-tree REFERENCE_TREE
python docs/probe_archive/Community_portrait_0035aff0_pipeline.py --output pipeline.json
python tools/decomp_lint.py src/promoted/code1_0035.c
python tools/pragma_audit.py
python -m unittest discover -s tests -p 'test_community_portrait_contracts.py' -v
```

If the host blocks native i386 execution, inject the existing qemu runner into
`Native32Runtime.run` before unittest discovery; keep the fixture, compilation
flags and target source unchanged. Resolve `qemu-i386` on PATH, or supply its path through an explicit
`P4_TEST_RUNNER` environment variable. Direct native discovery
otherwise skips after its explicit preflight. Lint reports zero errors;
existing owner advisories are not silently waived. The audit JSON retains
source/body hashes, every sibling comparison and every resolved relocation.

## Minimal-main validation

Only this renderer delta was applied to main commit
`8407da0ac22444a65389d64fc01aae67e3d481fd`. The unrelated research recovery of
`func_003599c0` was excluded: its guarded source is byte-for-byte identical to
that main baseline, and its 4,672-byte guarded object retains all instructions
and relocation destinations. Both normal and guarded comparisons preserve
all79 sibling functions, with unchanged allocated data.

Fresh owner verification and all39 reference checks pass on this minimal
tree. The six available community contract tests pass, including 8,209
portrait scenarios / 5,768,608 checks at O0 and O2 and all27 negative controls.
`make build-progress` completes with 604 C objects and54 Sony SDK objects,
8586 functions across658 linked units, and both required hashes:

- Loadable image: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Final retail-format ELF: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`

`func_0035aff0` and its owning file are present in the terminal linked report.
The function was already physically covered by the owner object's ASM fallback,
so the linked totals do not increase; it is now an exact recovered C function.
Normal cache keys were retained (859 eligibility hits /1 miss;603 link hits /
1 miss). No cache-key override, skipped gate, guard change outside this target,
or progress artifact is included in the source delta.
