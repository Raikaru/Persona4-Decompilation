# shdSkill wide-provider caller: argument construction follow-up

No additional proposal is accepted. The live `src/shdSkill.c` remains unchanged
and verifies **15 MATCH**. With the actual `s32 func_0023d8e0(u8 *, s32)`
contract and wide `00114cb0` / `00114dc0` skill parameters, the best complete
owner still preserves fourteen functions and all allocated data while leaving
four differing instruction words in `001138c0`, equivalent to two aligned
edits. This does not close the caller prerequisite for `00238940`.

This follow-up used branch `work/first-party-0360227` at
`6de7889e650ab0c6806e94720949207da80e1921`, rebased onto `167e607`.
Worker 8 wrote only the new scratch lane and this note. The previous 44-proposal
archive, its objects and proofs, the live owner, and the provider were preserved.

## Starting evidence

The previous result is recorded in
`docs/probe_archive/shdSkill_001138c0_wide_contract_167e607.md` and
`build/first-party-resume-167e607/shdSkill/proof.json`.
The complete current owner, its callers, retail assembly, and IDA/Ghidra
references were read before probing. The successful query caller's parameter
reuse mechanism in `Query_001da5f0_wide_provider_167e607.md` was also reviewed.

The new lane independently reproduced both baseline and plain-wide complete
objects with their existing hashes. Every compile used the logical owner
`src/shdSkill.c`, native MWCCPS2 3.0.1 build 210, and `-O2 -Iinclude`.
There were **37 complete-owner measurements: two reproductions and 35 new
proposals**. Each completed measurement retains its immutable source, object,
compiler receipt, function comparison, and diagnostic differences.

## New mechanisms and results

The main hypothesis was that an actual shared work record or an address chain
through the original formals could change how the compiler materializes the
position, color, and stored skill. Directly reusing `descriptor` for the
position/color address introduced pointer arithmetic and unaligned aggregate
loads. Reusing both `descriptor` and `mode` did not close that form. A work
record containing the three real addresses collapsed to the original wide
result only when scalarization and propagation removed its extra traffic.

Reusing the incoming `position` as the icon position, while retaining the base
position separately, added a second input store and exchanged the two stack
slots. It did not change the early skill promotion. Actual position/color
constructors, whether returning pointers, returning values, or expressed as
component assignments in the argument list, evaluated the color construction
before the position construction. Propagation could eliminate extra copies but
left that preparation-order difference and the skill-load residual.

| Probe family | Best target bytes | Aligned edits against exact baseline | Other result |
| --- | ---: | ---: | --- |
| Direct formal address chains | 1392 | 6 | Additional pointer and unaligned-load instructions |
| Shared address work record | 1384 | 2 | Returns to the plain-wide residual after propagation |
| Shared value work record | 1432 | 25 | Extra aggregate copies |
| Original position formal reused for the icon | 1388 | 17 | Input store and stack-slot changes |
| Actual position/color constructors | 1384 | 9 | Color preparation moves before position preparation |
| Two-byte enum storage with wide wrappers | 1384 | 2 | Same early promotion as the stored `u16` |
| Two-byte aggregate skill value | 1392 | 6 | Additional halfword copy through the stack |
| Explicit zero-extension through a word union | 1396 | 7 | Word initialization, halfword store, and word reload |
| Aggregate value getters | 1396 | 31 | Remaining aggregate-copy differences |
| Earlier value-copy forms with propagation enabled | 1384 | 2 | Copies disappear; original wide residual remains |

The enum experiment had one misleadingly smaller result. Making both the
stored identifier and wrapper parameters a two-byte enum moved the load back
to offset `0x224`, but emitted **`lh` instead of `lhu`**. It also changed
`00114cb0` from `move a1,a0; andi v0,a1,0xffff; slti ...` to
`andi a1,a0,0xffff; slti ...`, shortening that function to 260 bytes and
changing its owned table. That proposal is rejected; its one target edit is
not an improvement satisfying the unsigned identifier and complete-owner
requirements. Both enum-wrapper proposals and their data regressions remain
in the inventory.

These experiments narrow the useful next hypotheses; they do not establish
that every valid C representation has been exhausted. No incompatible local
prototype, ordinary assembly, artificial side effect, padding, or volatile
forcing was introduced as a solution.

## Exact residual and complete-owner proof

`001138c0` remains **1384 emitted bytes in a 1392-byte retail window**,
with 23 resolved code relocations and eight verified zero alignment bytes.
The only differences in the plain-wide owner are:

| Function offset | Retail | Wide owner |
| --- | --- | --- |
| `0x218` | `ld a0,0xd0(sp)` | `lhu a2,0xa(s5)` |
| `0x21c` | `mov.s f12,f21` | `ld a0,0xd0(sp)` |
| `0x220` | `lw a1,0xdc(sp)` | `mov.s f12,f21` |
| `0x224` | `lhu a2,0xa(s5)` | `lw a1,0xdc(sp)` |

The following texture load and call are unchanged. The halfword is still read
from descriptor offset `0xA`; the residual is its materialization before the
aggregate/float arguments.

The final proof resolves all fifteen baseline functions and all fourteen
unchanged wide siblings without relocation masking. It also verifies their
omitted suffixes and function-owned data, including the 80-byte, 20-entry
`00114cb0` jump table at `0x00746580`. The complete allocated-data comparison
is equal for baseline and plain-wide objects. Function ownership stays at
fifteen throughout the 37 measurements.

The official current-owner verifier reports **15 MATCH**, with `001138c0`
normalized difference zero. The frozen wide-owner verifier reports
**14 MATCH / 1 MISMATCH**, with `001138c0` normalized difference 14 bytes.
The wide verifier's exit status is 1, as expected for the retained unsuccessful
proposal. Its compiler command was checked to equal the current owner's
command except for the input source path. Terminal receipt `76306` completed
the proof and both scoped verifier runs with the harness exit status zero.

## Retained artifacts

Scratch root: `build/first-party-resume-167e607/shdskill-next/`.

`complete_owner_proof.json` contains the 37-entry inventory, compile receipts,
all resolved function proofs, exact residual offsets, allocated-data comparison,
official gate summaries, source revision, and relevant compiler/header/retail
fingerprints. `baseline/` and `wide/` contain the retained complete sources,
objects, and resolved function bytes. `official-current.{json,log}` and
`official-wide.{json,log}` retain the scoped verifier results. Each named probe
directory has its own `comparison.json`, source, object, receipt and differences.

The construction scripts are `address_forms.py`, `enum_forms.py`,
`promotion_forms.py`, and `value_returns.py`; `lane.py` supplies the common
logical-owner measurement entry point. `finalize.py` reproduces the final
unmasked checks and scoped official gates, protecting completed gate/proof
files against replacement. `release.py` reads back the finished artifacts and
writes `release.json` without compiling or editing the owner.

| Artifact | SHA-256 |
| --- | --- |
| Live/baseline source | `975774045f344a736c1184b1271c54a63694fa14894ddacdfe3ca6004fd650e0` |
| Baseline complete object | `be3c85569dd5e7d872a0370a9b9135bd7b1a93bb2a9c602df61f069fb3508699` |
| Plain-wide source | `bf2088723a9e2b585f5d3f8afb038278c025c35f4717327ee258edbd91c79301` |
| Plain-wide complete object | `52498134211899a4651e9f689ecb87b8f8e59f0e05220c67cf4b66d9d38e9935` |

No live source change, provider change, integration, commit, push, or full-image
build was performed. This lane releases its scratch compiles and owner claim;
the existing fifteen caller matches remain protected.
