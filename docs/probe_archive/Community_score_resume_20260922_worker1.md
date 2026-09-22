# Community score callback recovery, September 22, 2026

`func_0024d1f0` is now active C in `src/promoted/cmmScript.c`. The native
configured b210 `-O2 -Iinclude` object reproduces all 7,600 bytes of its retail
window and all 201 relocations without masking. The official current-source
owner report is **50 MATCH / 1 ASM**, compared with **49 MATCH / 2 ASM** at
the start of this resume. This is one new promotion.

The resume began at `457acdb`. Its ancestor `f8bd21c` had published the draw
callback `0024c460` and fishing update `0024f790`; the score callback was still
guarded. The already-completed score candidate in
`build/finish-first-party-20260922/community-script/final-script-score/`
was authenticated before any new compilation. Existing community archives and
receipts remain intact.

## Source and contracts

The score callback keeps the two-argument `s32 (u8 *, u8 *)` contract used by
`func_0024efa0`. The constructor `func_00250120` installs it at offset `0x44`
in the three-entry callback workspace. The callback reads its second argument
for flags and the frame counter; its first argument is unused in retail.

The recovered C retains the entry animation, ten-frame exit animation,
steady displacement phases, byte-masked score and decimal digit selection.
The two task lookups and explicit task-data forwarding agree with
`func_00452380(s8 *)` and `func_00452560(void *)` in `src/Kernel/sdkTask.c`.
The atlas lookup uses the current `u8 *func_0046a770(char *)` provider, and the
score lookup uses `s32 func_00106600(s16)`. The local sprite declaration's
final argument was corrected to `void *`, matching `func_0025ecd0` in
`src/promoted/code1_0025.c`; every caller in this owner remains byte-exact.
No provider or shared header was edited.

Small inline C helpers express clamping, atlas acquisition, bounce and signed
displacement. `cmmScoreProduct` retains the separately rounded displacement
product before the sprite-anchor addition. The bounce expressions retain
the retail accumulator operations. These are ordinary arithmetic and control
flow; no scalar assembly, artificial side effects or allocation barriers
were introduced. Obsolete comments claiming the score was unattempted and
misstating the prior draw callback's size were corrected.

## Native and official evidence

All new evidence is under
`build/finish-first-party-20260922/resume-community-worker1-01/`.

| Item | Evidence |
| --- | --- |
| Retained candidate authentication | `retained-audit.json`, `provider-caller-contracts.json`, `retained-score/` |
| One new final-source native compilation | `final-score/compile.json`, `final-score/cmmScript.c`, `final-score/owner.o` |
| Complete target proofs and owner comparison | `final-score/func_0024d1f0-proof.json`, `final-score/owner-comparison.json` |
| Source installation | `installed.json` |
| Official current-source closure | `installed-score/completed.json`, `installed-score/official.json`, `installed-score/official.log` |
| Publication receipt map | `handoff.json` |

The installed source SHA-256 is
`bb0d9f3766752d6cfec212ee8ef51a8747aa64b3a618794de1999e9e36c123bc`.
Its native object SHA-256 is
`ef6a16aa1eb3007f5607ee89b13dfe0ebe99a91605460cb508882fb512348a1d`.
The compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The final object is identical to the authenticated retained score object.

The source was installed only after the complete unmasked native proof and
preservation checks. The official closure reused that identical final-source
object after validating the live source, configured compiler, flags and
recursive inputs. It invoked the unchanged `tools/verify.py` entry point and
scoring with a checked compiler callback, following the established owner-gate
pattern. Its `compile.json` explicitly records reuse and the original native
receipt; it does not claim another compilation. No completed compiler job was
repeated.

| Protected function | Emitted / retail bytes | Relocations | Official result |
| --- | ---: | ---: | --- |
| `func_0024c460` | 3,464 / 3,472 | 87 | MATCH |
| `func_0024d1f0` | 7,600 / 7,600 | 201 | MATCH |
| `func_0024f790` | 1,988 / 2,000 | 69 | MATCH |

All 50 functions other than the promoted score callback retain their native
bytes and canonical relocations. The closure separately proves the two prior
targets and checks the other 48 siblings. Every allocated data section,
including its bytes, alignment and canonical relocations, is unchanged; the
three target proofs require no new owned data sections. The complete retail
windows, including the eight and twelve trailing bytes of the prior targets,
are covered by their unmasked proofs.

Scoped `decomp_lint` reports zero errors and one existing H003 warning for
the measured `optimization_level 1` scope at `func_0024a710`. This change
introduces no optimization pragma. `git diff --check` passed for the edited
source. No runtime or visual emulator result is claimed by this closure.

## Remaining selector

`func_0024be40` remains `NONMATCHING` with its assembly fallback. Its retail
window is 672 bytes. The best current-context C probes still differ at eight
unmasked words: offsets `196, 236, 480, 492, 520, 544, 556, 560`. They exchange
the saved registers assigned to the weight-row pointer and second-loop
counter (`s0` and `s2`); instruction count, other words and relocations agree.

The current providers and caller were reviewed: signed six-byte weight rows
within a 72-byte monthly record, `s32 func_00246e10(s32)`, signed date getter,
unsigned phase getter, `s64 func_00110960(s32, u32)`, `u32` flag result and
`u32` random result. The scratch candidates use consistent file-scope
declarations and the necessary address cast in sibling `func_00250940`.
Those declaration corrections preserve all 50 sibling functions.

Six new full-owner native snapshots were measured, each once:

| Scratch directory | Bytes / window | Differing words |
| --- | ---: | ---: |
| `selector-canonical-current-contracts` | 672 / 672 | 8 |
| `selector-hot-weight-row` | 672 / 672 | 8 |
| `selector-hot-row-and-counter` | 672 / 672 | 8 |
| `selector-record-word-cursor` | 672 / 672 | 8 |
| `selector-sampling-result-helper` | 696 / 672 | 169 |
| `selector-staged-sampling-helper` | 696 / 672 | 169 |

Each directory contains source, compile identity, native object, resolved
retail comparison, alignment, result and full sibling/data preservation
evidence. The combined sampling helper causes the compiler to rematerialize
the row address inside both loops and to save an additional register.
Disabling propagation at that helper definition does not repair it.
Register hints and reuse of the record-address word as the later cursor do
not change the eight-word residual. None of these selector candidates was
installed or counted as a promotion.

Future selector work needs a new, semantically supported value-lifetime or
control-flow reconstruction that resolves this specific register assignment.
The retained declaration-order sweeps, old writers and completed compiler
jobs should be read, not repeated. Publication and repository-wide rollup are
owned by the prime; this worker made no commit, rebase or push.
