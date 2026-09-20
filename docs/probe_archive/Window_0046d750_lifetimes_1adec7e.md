# Window task 0046d750: exact body with a render-state API prerequisite

Worker-2 recovered the complete `func_0046d750` body on 2026-09-20 from the
current post-SDK owner at HEAD `1adec7e926b81497a86b3a4238ba57edfb780c2b`.
This lane writes scratch artifacts and this note; the prime owns integration.

The target is independently exact with the real rendering and camera APIs,
but the complete promotion is **not approved**: reconciling the shared API
leaves four resolved words / three aligned edits in the existing
`004601c0` restoration loop. Work on that dependency continues. No production
source has been changed by this lane.

The coherent complete-owner proposal is:

`build/first-party-resume-continue/worker2-window-0046d750/api-direct-payload/full-proposal-lf.patch`

Its complete source, object, receipt, exact target proof, and
`target-with-canonical-api.c` are in the same directory. The provider trace
and canonical complete-owner result are in `api-audit/complete.json`.

The initial target-only patch, retained as an intermediate result, is:

`build/first-party-resume-continue/worker2-window-0046d750/ready/integration-lf.patch`

The complete frozen source, object, compile receipt, target source, and
independent proof are beside it. It retains inherited incompatible render-state
and camera declarations and must not be promoted. The earlier
`integration.patch` was written with Windows CRLF and is retained as an
unsuccessful patch-format artifact. `git apply --check` passed for the LF
patch against the current owner in session `86236`.

## Result

The body, including the canonical API version, emits **4244 executable bytes** in its **4256-byte retail
window**. All **14 code relocations** are resolved to actual destinations.
The twelve omitted bytes are verified zero alignment, not missing code.
The complete **36-byte, nine-entry switch table at `0x00756790`** is also
resolved and byte-exact. No relocation fields or owned table entries are
masked in the independent proof.

The initial two gates pass with exit zero. The canonical gate reports the
one remaining dependency and exits one:

| Frozen owner | MATCH | ASM | MISMATCH | `0046d750` |
| --- | ---: | ---: | ---: | --- |
| Current source before promotion | 52 | 7 | 0 | ASM |
| Initial target-only candidate with inherited APIs | 53 | 6 | 0 | MATCH |
| Canonical render-state/camera APIs | 52 | 6 | 1 | MATCH |

All fifty-eight other verifier results are unchanged in the initial target-only
candidate. The canonical API candidate changes only `004601c0`; the target and
the other fifty-seven siblings remain exact or unchanged. The compiled logical
owner contains fifty-nine function symbols. All pre-existing
allocated data is preserved, and the new target-owned table is independently
proved. The guarded-C baseline's allocated data also agrees with the ready
object. The canonical owner also preserves all allocated data.

## Cause and final source change

The prime's saved lifetime discovery reduced the existing guarded body from
248 differing instruction words to six. A fresh compile of the current SDK
owner reproduced both measurements. The six residual words have two causes:

| Region | Retail behavior | Lifetime-only candidate |
| --- | --- | --- |
| `+0xc38` through `+0xc44` | Compute the case-5 loop condition in `v0`, branch backward while true, then branch forward on exit | Compute it in `at`, branch forward while false, then branch backward |
| `+0xc94` through `+0xc9c` | Initialize the inner-loop counter before computing the group address | Compute the group address before initializing the counter |

The final source scopes `opt_lifetimes on` together with the already needed
`opt_propagation off`. It initializes `j` before computing the case-7 group
address and expresses the case-5 color loop as a normal `for` loop. The loop
still visits exactly four vertices, in the same order, with the same loads,
conversions, and stores.

Initializing `j` first removes three differences. Naming the actual loop
condition removes the register difference but leaves the reversed branch
pair. The structured `for` loop removes the remaining pair. A guarded `do`
loop independently reaches the same discovery zero. The ready source uses
the simpler `for` form and removes the now-unused condition variable.

The old floor comment, NON_MATCHING marker, conditional assembly fallback,
and unscoped closing optimization directive are replaced with the scoped
exact body. The patch leaves neighboring functions and shared declarations
unchanged.

## ABI and memory review

The existing `s32 func_0046d750(u8 *task)` contract is retained. The current
SDK registration header defines that same task-update callback type, and
`0046e850` registers this function directly. Retail returns zero after normal
updates and minus one for state eight. No task argument or return type was
changed to influence allocation. The inherited rendering and camera
declarations were separately corrected after tracing their actual providers.

The task's work pointer is loaded from `task+0x38`. Its creator allocates
`0x560` bytes, writes the rectangle at `work+0xc`, and writes the two byte
colors at `work+0x1c` and `work+0x20`. The border vertices use four groups of
four 64-byte records; their last color store ends at `work+0x450`. The fill
quad uses four more 64-byte records; its last color store ends at
`work+0x550`, inside the allocation. The final loop retains live unsigned-byte
color reads for each vertex and the retail float conversions.

Case six still calls `0046ea60` with both the real task pointer and
`work+0xc`. The matching helper consumes the complete four-word rectangle.
The subsequent camera/render callbacks and their argument setup remain
unchanged at the machine-code boundary after the canonical declarations are
applied. The target contains no `0044f720` print calls, so the prime's
separate print-contract work does not alter this target's call interface.

The repeated zero-alpha predicate in case seven was already present in the
guarded reconstruction and is retained: retail contains two consecutive
branches on that same loaded alpha. This recovery does not add a redundant
predicate or a new memory access to obtain the match.

## Evidence and reproduction

All new work is under:

`build/first-party-resume-continue/worker2-window-0046d750/`

`inputs/manifest.json` binds the current complete owner, transitive headers,
configuration, configured compiler binary, and logical flags. The compiler
is MWCC PS2 3.0.1 b210 with logical `-O2 -Iinclude`; the measured scratch
compiles redirect that include path to the immutable header copies. Both
official gates use the same configured compiler/profile, with live header
and configuration hashes checked against the frozen inputs before and after
verification.

The initial eleven complete-owner objects are retained: the current guarded/stub owner,
the lifted guarded-C baseline, the lifetime-only body, seven focused source
variants, and the final ready owner. `lane.py`, `control_flow.py`, and
`loop_shape.py` reproduce the bounded exploration. `prepare_ready.py`
constructs the cleaned target region and proves the body/table.
`official_gates.py` compares both complete-owner verifier reports.

The first two diagnostic disassemblies were produced before the optional
disassembler was added to the `-S` process's search path. Their compiler
objects and word counts were valid and were retained. `decode_saved.py`
supplies the corrected `decoded.asm.txt` and `decoded_comparison.json`
without recompilation or replacement of the original diagnostics.

The independent ready proof completed in session `49299`, exit zero. The
initial official gates completed in session `24644`, exit zero. The canonical
audit completed in session `35427`, exit zero after asserting the canonical
verifier's expected exit-one result. The initial `release.py` has not been
run: its pre-audit acceptance assumptions are superseded by the canonical
proof, and no final release is claimed here.
