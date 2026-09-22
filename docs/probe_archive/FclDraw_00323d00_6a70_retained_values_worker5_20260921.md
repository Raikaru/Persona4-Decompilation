# 00323d00 retained values and 002b6a70 resource contracts

No new recovery is ready for integration. The requested retained-value
grouping and declaration experiments were completed with ordinary C in new
scratch. The earlier 29-word frontier remains immutable, but its caller-side
`002b6a70` declaration is inherited rather than provider-coherent. It must not
be promoted on the strength of its register-only residual.

This note continues, and qualifies the contract claims in,
`FclDraw_003218a0_00323d00_worker5_frontiers_20260921.md`. No live source,
header, configuration, build helper, or Git metadata was changed.

## Retained-value controls

All paths in this note start at
`build/next-wave-20260921/fcl-next/retained-values-20260921/` unless stated
otherwise. `control/authenticated.json` authenticates the original complete
owner, object, compiler, transitive headers, and retail comparison without
compiling it again. The prior seal SHA-256 remains
`01fddc0cbd1475f3552a939a87e4a7c06613120385a872d32f3f3990930d66ec`.

The fourteen first controls vary only real alpha declarations, the shared
short/native resource views, and aggregates containing those retained values.
Every one remains at 1,800 bytes and 29 fully resolved differing words, with
all 69 other owner functions and allocated data preserved. No grouping was
left untested because of the previous tool block.

Additional controls cover actual first-alpha snapshots, native result values,
parameter storage, resource construction, and the observed mask propagation.
Byte alpha storage adds masks or moves; aggregate constructors add stack work.
The existing raw word alpha values are the closest inherited-contract form.
Every experiment retains its complete source, object, receipt, source diff,
real EE decode, resolved residual, and sibling/data comparison in
`experiments/`.

## The contract discrepancy and complete caller audit

The frozen provider defines:

```c
void func_002b6a70(s16 resource, u8 from, u32 to,
                  u32 mode, u32 duration, s32 delay);
```

The draw owner's global declaration had two byte alpha parameters, and its
local declarations also disagreed about resource or delay widths. The audit
found all 198 authoritative calls and eight declarations in exactly two
caller owners: CombineDraw has 155 calls and three declarations; Combine has
43 calls and five declarations. The third owner is the provider, `y_draw.c`.
No other authoritative `src` or `include` declaration was found. Generated
reconstruction files are not part of this closure.

`contract-002b6a70/audit.json` records every occurrence and the complete frozen
context. Fifteen former nonliteral destination-alpha byte conversions were
made explicit in the proposals. Actual call expressions and their external
call order otherwise remain unchanged, apart from the documented equivalent
resource view in `0032fbc0`.

Making every declaration agree with the current narrow-resource provider
preserves all 41 Combine functions, all 58 provider functions, and 69 of 70
Draw functions. `003205f0` remains 888 bytes, but its two alpha calls use the
existing normalized index registers instead of retail's raw incoming resource
registers. The changed offsets are `+0xFC` and `+0x2B8`.

This is the blocked `delivery/s16/` proposal. All 20 guarded caller pairs were
also compiled separately and compared. Sixteen guarded target bodies are
unchanged; four Draw drafts change only in the affected argument handling.
Every comparison preserves the external call sequence and allocated data.

## Wider-resource investigation

Retail's raw forwarding in `003205f0`, followed by normalization inside
`002b6a70`, supports investigating a wider formal. Prime authorized this as a
separate coherent proposal. The new provider takes `s64 resource`, retains
the correct alpha/flag/delay types, and explicitly converts the resource to
a local `s16` after obtaining the table base.

The complete provider object is unchanged: all 58 functions, their canonical
relocations, and allocated data match. The provider's 68 instruction bytes,
two resolved relocations, and 12 zero suffix bytes also match retail fully.
Combine remains unchanged, and `003205f0` becomes exact again.

`0032fbc0` initially acquired an extra conversion. Capturing its actual
short resource and native fade argument in the existing initialization fixes
that regression:

```c
s16 resource;
s64 fadeResource;
fadeResource = (resource = (s16)(normalizedRow + 0x25E));
```

The alpha call consumes `fadeResource`; the existing narrow consumers retain
`resource`. All 1,180 instruction bytes and all 32 relocations are exact again.

The final wide proposal preserves 168 of 169 active functions across the three
owners. Its remaining blocker is `00324410`: widening its incoming short
resource at the alpha call replaces one move with a sign-extension pair.
Code grows from 616 to 620 bytes inside the 624-byte window. The changed
branch displacements and shifted suffix produce 49 fully resolved differing
words. Initialized parameter-home captures at entry, within the branch, or at
the consumer do not remove that conversion. No further providers were widened.

The separately measured `s32` control preserves the low-16-bit resource index
mapping but regresses three active Draw functions. Its provider and Combine
objects remain unchanged. Its first execution request was blocked before
execution; an identical retry completed. The control is not selected.

`delivery/wide/` contains the complete wide proposal and all 20 guarded caller
comparisons. Eleven guarded target bodies are unchanged. The other nine Draw
drafts change at resource/alpha/delay handling; every call sequence and all
allocated data remain unchanged. `00324410` is separately identified as the
known active regression in those comparisons.

## 00323d00 under coherent declarations

Both the narrow-provider and wider-provider contexts change destination-alpha
mask propagation. The correctly declared native frontier is 1,804 bytes in
the 1,808-byte window, with 265 fully resolved differing words. Source-level
byte snapshots, byte-return helpers, actual parameter wrappers, grouping, and
scoped diagnostics for the observed mask propagation do not close it.

The wide variant uses the already captured native resource values at its
alpha calls. It preserves all 69 other functions relative to the wide context;
that context still has the separately recorded `00324410` regression.
Its complete-owner object SHA-256 is
`50037a09e9d65bd760150602f0ee376db163245dd55ea9bdd1f7b52e01fe7d58`.

Independent full relocation/owned-data proofs confirm `003212e0`, `00330060`,
`0032fbc0`, and `003205f0` in this selected object. The recovered `002b83e0`
provider is also independently re-proved in both closure packages.

## Sealed review packages

`delivery/seal.json` authenticates 139 successful new compilations and two
recorded path-length failures. The two affected source experiments were later
compiled under shorter new paths; successful jobs were not restarted to
recover output. Sealing performed no compilation. The three live owners still
matched the original frozen sources at sealing.

Both `delivery/s16/` and `delivery/wide/` contain `proposal.review.patch`,
`proposal.apply.patch`, complete before/after sources, `closure.json`, full
neighbor/data comparisons, guarded-caller results, protected-function proofs,
and resolved blocker bytes. Both explicitly have `integration_ready: false`.
Neither patch is a production promotion. The separate `69f0` investigation
belongs to prime's other lane and was not modified here.

Use the retained `delivery/compilation-index.json` and per-object receipts to
resume only from matching full contexts. The scripts retain the source forms
and exact controls; the recorded artifact is authoritative for each completed
measurement.

All compilation sessions completed. The final scoped process query reported
zero owned compiler or Python-wrapper processes; its result is retained in
`delivery/process-status.json`. Prime owns any subsequent merge or integration.
