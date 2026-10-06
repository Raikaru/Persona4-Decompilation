# Field AI follower recovery, 2026-10-05

`func_0017d3c0` has a defined guarded reconstruction with the real task,
model, motion-resource and vector contracts. It remains an assembly
fallback. The actual installed owner remains **9 MATCH / 2 ASM**, with
**zero new C matches** in this continuation.

The previous guard used field addresses where retail loads pointers,
passed the wrong object to the fade-status and other-AI helpers, and let
the idle-animation branch enter movement logic. It also contained
unsupported `keepS`/`keepF` branches comparing against `0x12345678`.
Those branches are removed. The replacement uses complete XYZ values,
preserves the separate idle/steering/teleport paths, and retains the six
real formation handlers and their callback-visible loads.

## Native result and preservation

The installed guard emits **5152 bytes in a 5248-byte retail window**,
with **89 aligned edits**. The initial pre-contract guard emitted 5168
bytes with 809 aligned edits; the separately installed axis contract had
then corrected its float-argument promotion, producing 5156 bytes.

The 89-edit count measures instruction alignment, not exact bytes. After
all **114 code relocations** are resolved, **1227 words still differ**
from the retail window. In particular, the shorter candidate does not
leave an entirely zero retail tail. The remaining differences include
readiness-predicate materialization, entry/model-slot address lifetimes,
saved-register choices, two vector-copy instruction sequences and minor
history/branch placement. No padding, fabricated storage or assembly
replacement is used to hide those differences.

The candidate and retail have exactly the same **92 direct calls**,
including their complete target-address multiplicities. This is checked
independently of the aligned score. The source and native call contracts
were reviewed against the providers and both decompiler views.

Both actual installed default and complete `NON_MATCHING` owners were
compiled. The default owner is byte-identical to its preceding object:

```text
0123764b17a9047963076bff4e409fa12fb1bca0da88578a381def8a555ac54f
```

All eleven default function windows resolve exactly to retail, including
the two assembly fallbacks, with **465 code relocations** checked. The
default owner has no allocated non-code data. All ten guarded siblings
retain their raw instructions and canonical relocation targets. Anonymous
compiler-symbol renaming is checked against the complete referenced
section, offset and payload. All guarded owned data, including the
secondary routine's existing 60-byte table, is unchanged.

The actual guarded object is:

```text
544a2db8d2f359c330bb4edaede281ba0cf89e4d8a1dcdc266605022f928318c
```

Scoped lint reports **zero errors and one existing declaration warning**
for the pointer-valued camera getter whose defining source still uses an
integer-address return type. The whitespace check passes. The complete
guarded compile retains the old secondary routine's uninitialized-local
warning; that warning is not produced by the reconstructed follower.

## Axis-contract evidence bridge

This change follows the completed five-owner axis-pointer repair. The AI
owner advances from SHA256
`b69e71bc810e4e85e4f18bbf05025f8b67787d3d1835dbbff9677eba762ef85c`
to
`b5ccbe3bc9426c297caa4918c266589f24e90f177f700b26930a284d3ef12a7e`.
The four other axis-contract owners and every default object remain
unchanged. The follower retains the installed `const void *` axis
contract, and the secondary guard is unchanged from the axis repair.

`Field_axis_contract_20261005_receipt.json` remains a historical source
snapshot. Its old AI source/guarded-object hashes are intentionally
superseded by this receipt; its unchanged default-owner results remain
valid through the whole-object identity proof. The published rain region
and object are untouched by this AI-only continuation.

## Secondary routine: concrete private repair and rejection

The private `func_0017f490` candidate repairs four complete XYZ objects,
including a twelve-byte random-target zeroing operation that previously
wrote through one four-byte scalar and then read an uninitialized Y
scalar. It also repairs six float speed stores, two integer timer reads,
the sine function's float argument/result, 31 out-of-range GP-relative
player-model accesses, and ten unresolved `CAND_` GP-symbol placeholders.

Those corrections remove the secondary candidate's C compiler warning
and lower its aligned score from 2261 to 2184 edits. They do **not**
close the function: the current-context candidate emits **11892 bytes
for a 11584-byte window**, a **308-byte overrun**, and has **2846 fully
resolved differing words** after its 302 code relocations are applied.

The fifteen entries in its 60-byte state table are also resolved, using
the independently identified retail table at `0x00746d80`. **None of the
fifteen entries match retail**, and the state-13/default entry targets
fall beyond the retail function window. The native handler layout must
therefore be reconciled before this source can be promoted or its table
claimed as exact. The candidate is not installed. Its ten sibling bodies
and relocation records are preserved in the current follower context.

The durable receipt embeds its current-context patch and guarded source
region, the exact native target/table diagnostics, and the compiler/input
bindings. This retains the concrete repairs without banking an unsafe
or falsely exact production result.

## Replay and retained evidence

The portable evidence consists of this note,
`Field_AI_follower_0017d3c0_20261005_receipt.json`,
`Field_AI_follower_0017d3c0_20261005_proof.py` and
`Field_AI_follower_0017d3c0_20261005_replay.py`. The replay also uses the
already archived `Field_axis_contract_20261005_proof.py` for complete
default-owner code/data resolution.

```text
build/venv/Scripts/python.exe docs/probe_archive/Field_AI_follower_0017d3c0_20261005_replay.py --hashes-only
build/venv/Scripts/python.exe docs/probe_archive/Field_AI_follower_0017d3c0_20261005_replay.py
```

Replay checks the recorded project inputs and compiler profile, rebuilds
the actual AI owner in default and guarded modes, proves all default
windows, and repeats the follower's unmasked relocation and direct-call
diagnostics. It writes only a fresh scratch output directory. The full
experiment chain remains under `build/resume-field-worker12/ai/` and
`build/resume-field-worker12/ai-current/`. In particular, three earlier
SDK-copy probes that accidentally emitted calls to an unavailable macro
are explicitly rejected in `ai/rejected-sdk-copy-probes.json`; their
scores are not recovery evidence.
