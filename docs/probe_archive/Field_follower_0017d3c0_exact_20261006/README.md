# Exact field follower update: 0017d3c0

This proposal replaces the field follower update's assembly fallback with C.
The complete owner is `src/Kosaka/Field/k_fldAI.c`. The native diagnostic string
at 005f1b18 identifies `k_fldAI.c`; descriptive local/accessor names are recovered
names, not claims of original Atlus identifiers.

The reviewed source is SHA256
`25654cc1806a17308c27adcd48290da43fee0a9f55aa378b9d8308f11fc4ee3d`.
It is the original sealed proposal. Optional SDK-pointer experiments are not
part of this patch. No provider, shared header, or other owner is changed.

## Lifecycle and initialized state

The update reads task work at +0x38 and exits when stopped or either required
party entry lacks its ready flag or loaded resource. Four readiness results are
normalized to 0/1 before lossless byte storage and zero/nonzero tests.

State 0 finds this unit among the four party entries, stores its formation
index and movement limits, initializes its steering/history state, and advances
to state 1. State 1 first measures camera separation, handles fades and model
color, and leaves through a separate idle-animation path when movement is off.

The moving path classifies the current map tile, updates formation-side state,
and obtains normalized forward/right axes. It clears the accumulated leader
position and direction before scanning nearby party entries. Each model slot
is loaded at the native call boundary; the resulting matrices supply the actual
geometry query, avoidance delta, and leader formation accumulations.

The leader distance determines speed. Formation offsets use the stored unit
index and side, then contribute to a normalized steering delta. A distant unit
teleports only on the initial recovery path; other units rotate and move through
their actual motion tasks. The history index is the preceding ring slot with
negative wrap to 63. The independent active flag starts at zero and is set only
when the initialized history delta is shorter than movement speed. Those values
drive the existing idle/run animation transition and timer behavior.

Both position outputs are complete 12-byte objects. Their union contains the
existing RwV3d layout (three f32 members), so its byte view is float-aligned.
The native follower passes stack +0x70 and +0x80 to `func_001687f0`. That provider
clears all 12 bytes of its local XYZ value at 00168804..0016882c, optionally
replaces all XYZ from model offsets +0x30/+0x34/+0x38, then unconditionally writes
all three components to the destination at 0016885c..00168870. A missing model
therefore produces zero XYZ. The motion-task argument itself must be valid.
The history calculation keeps initialized Y from this position output while
replacing X and Z with the selected recorded sample; its delta Y is consequently
computed from initialized values. No invented filler or partial output array is
used to obtain the stack layout.

## Length and model pointer contracts

The retained SDK header `include/rw/plcore/bavector.h:362` declares
`RwReal RwV3dLength(const RwV3d *)`. The active compiled provider at
`src/promoted/code1_003e.c:533` uses `f32 RwV3dLength(f32 *)`, as does this owner's
existing declaration. Native 003e4180 reads three floats at +4,+0,+8, writes
nothing through the pointer, and returns the floating length in f0. The follower
passes the first component of complete `cameraDelta` and `historyDelta` objects.
The exact sibling 0017ea10 passes its complete `d` object. The source spelling
agrees with the active provider, and the native extent and float result agree
with the SDK. The SDK's pointee/const distinction is recorded without an isolated
provider signature change in this promotion.

The active `src/mdlManager_grouped.c:22` provider is
`void *mdlGetMatrix(void *)`: native 0047a2f0 returns its input address. This owner
uses a byte-pointer view of the same model/matrix storage. Its pointer input and
result have the same native ABI; neither an integer return nor additional native
argument is introduced by the follower. The self/other matrix calls retain the
native order and call targets in the final complete-owner object. Later calls
reload the model slots as observed in retail.

Fresh complete-owner provider compilations, recorded in receipt.json, prove:

| Provider | Emitted / window bytes | Resolved references | Modes |
| --- | ---: | ---: | --- |
| mdlGetMatrix, 0047a2f0 | 12 / 16 | 0 | default |
| RwV3dLength, 003e4180 | 44 / 48 | 0 | default and guarded |
| Position output, 001687f0 | 152 / 160 | 1 | default and guarded |

Every omitted suffix in that table is retail zero bytes. The provider source and
header hashes bind these observations. No claim is made that unrelated unfinished
guards in the provider owners are recovered.

## Source causes and native evidence

The preserved 57-edit candidate supplied complete position outputs and the
measured `opt_rebuildconditionals off` setting. Byte readiness results preserved
the four native boolean conversions. The measured `opt_loop_invariants on`
setting restored the discovery preheader's true value, party stride, and base.
Unsigned offsets for the bounded 0..3 party index retained the two per-site
model-address calculations. Inline model-slot/history accessors retained the
actual storage boundaries and history-add operand order.

The last four differing words were a self-matrix/model-slot register exchange.
Read-only compiler capture and allocator replay tied them to two live values.
Using the actual matrix-query results directly as geometric-query arguments
removed a redundant source result binding. The final observed allocator assigns
slot virtual 286 to s4 and matrix virtual 289 to s1. The source has no register
pinning, false arguments/returns, ordinary inline assembly, volatile forcing,
uninitialized padding, or rewritten emitted code.

The optimization settings are scoped with push/pop before the next sibling.
The original owner line endings are retained. No float/declaration permutation
family was used to make this closure; failed pointer/profile alternatives remain
in the private scratch ledger.

## Complete-owner proof and scope

The candidate emits 5236 bytes into the 5248-byte retail window. All 118 target
relocations resolve, the remaining 12 retail bytes are zero, and there are zero
unmasked differing words in both modes. All 92 direct calls match retail at the
same offsets, in order, with the same targets.

The default owner has 10 MATCH and 1 ASM. All 11 default function windows and 469
code relocations resolve exactly; it owns no allocated non-code data. The ten
other functions retain their instructions and canonical relocations in both
default and NON_MATCHING modes. Guarded owned data, including the remaining
controller's table, is preserved. This is preservation, not a claim that the
remaining 0017f490 guard matches retail or is fully reconstructed.

Direct native and read-only debugger compilations of the same whole source were
byte-identical in both modes: 45 complete default snapshots and 50 guarded
snapshots, with no drift or capture errors. Default native compilation omits the
remaining assembly fallback; the complete mwccgap owner separately proves it.
All generated C functions agree with the proof objects. The current review
authenticated every artifact hash in the prior sealed record.

Lint has zero errors. The measured loop-invariant setting adds H003; the existing
camera-getter pointer/integer H011 advisory is unchanged. The remaining guarded
controller has inherited incomplete-object and legacy-alias issues described by
the earlier field AI archive; they are excluded from this recovered function.
An optional full camera-vector repair was measured privately and changes that
guard, so it was kept separate from this byte-preserving promotion.

This archive contains text, a source patch, replay code, and hashes. It contains
no compiler, retail binary, or object. Combined image hashes, final counts, and
C-link membership are the integrating prime's gates; this worker's audit did not
rerun a whole-game build. Protected y_smap updater/constructor source is unchanged.

## Replay and next action

Use the configured native compiler and hash-validated retail input:

```text
build/venv/Scripts/python.exe -B -Xutf8 <archive>/replay.py --hashes-only
build/venv/Scripts/python.exe -B -Xutf8 <archive>/replay.py --out build/field-follower-replay-new
```

Replay accepts either the recorded baseline or installed proposal, reconstructs
both using the authenticated patch, compiles complete default/guarded owners,
and repeats unmasked target, sibling, data, and ordered-call checks. It never
modifies production. Its output directory must be fresh.

Prime's next action is to finish the baseline freeze, review this unchanged
proposal hash and audit, then install proposal.patch and publish these text
artifacts in the chosen probe-archive directory. Any source cleanup after that
must be separately identified and re-proved. Worker-8 remains on the field queue.
