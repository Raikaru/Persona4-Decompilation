# Final SDK, Fcl, movie and quad integration review

Worker-1 completed this review on 2026-09-20 against local HEAD
`1adec7e926b81497a86b3a4238ba57edfb780c2b`, after the prime rebased the five
local recovery commits onto origin/main
`4ec489386f3dc93898a2ed1f40ea5fc4607a12d6`.

The current 118-file proposal is ready for prime integration. All 112 complete
owner selections have exact source and recursive header dependencies. The two
owners changed upstream were merged in new scratch and freshly compiled before
and after the SDK changes. Their 170 active functions, relocations and allocated
data are unchanged. The full proposal still has 400 compatible callback role
definitions, 257 compatible callback declarations and 241 registrations agreeing
with the retail call inventory. No unresolved callback or caller issue was found
within the reviewed package. This worker did not edit production, apply the
patch, run a full project build, commit or publish.

## Current package and application boundary

Paths are relative to the recovered-upstream repository. New scratch is
`build/first-party-resume-continue/sdk/`; the final source tree is its
`proposed/` directory. The prior `build/first-party-resume-final/` packages and
all their saved scripts, snapshots and receipts were left unchanged.

| Artifact under the new scratch root | Purpose |
| --- | --- |
| `package/sdk-fcl-movie-quad-current.patch` | Exact-byte unified diff for the current 118 files, 351,424 bytes |
| `package/manifest.json` | Current before/after file hashes, nine bounded patch chunks, original-proof bindings and EOF requirements |
| `selected-objects.json` | Every final owner, source hash, recursive include closure, selected object and compiler receipt |
| `package_current.py` | Builds the package or performs read-only before/after checks; never applies it |
| `capture.json` | Current snapshot, clean three-way merge results and hashes of 1,264 original artifacts |
| `drift-compilation.json` | Fresh whole-owner comparisons for code1_0018 and code1_0021 |
| `source-merge-review.json` | Exact preservation checks for the upstream bodies and the local quad caller |
| `semantic/` | Complete callback, registration, retail-registration, bounds and lint inventories |
| `target-proof/` | Recomputed resolved retail targets, owned movie table and unchanged provider proofs |
| `saved-proof-recheck.json` | Recomputed original final evidence is identical to the saved evidence |
| `independent-final-chain/` | Missing independent four-owner review, now completed |
| `independent-final-chain-selection.json` | Explanation and final selection for the later code1_0020 getter correction |

The released hashes are:

```text
unified patch  80b5b1e9c740f7e967f3e55a32085c1d2bbb38392fc3657d10ff2eb8d063dfe8
manifest       9d3b4870b1ef8e8c8a86b7707944751fe9ceb3e6513333446a694ff2dc2945df
selections     f0b3aeeb31824bd0cde9ab0d865ab99da8b349e8f30cd572574bf3b5fc3df4c7
```

The unified diff passed `git apply --check` against both the captured current
snapshot and the live checkout. `package_current.py check-before` also passed,
validating the live tree, exact object selections, compiler settings and saved
artifact hashes. Prime can use the following sequence, with each check passing
before proceeding:

```powershell
python -B build/first-party-resume-continue/sdk/package_current.py check-before
git apply build/first-party-resume-continue/sdk/package/sdk-fcl-movie-quad-current.patch
python -B build/first-party-resume-continue/sdk/package_current.py check-after
```

Run the after check immediately after SDK integration and before another owner
is edited. It checks the captured source, include, configuration and tool-input
tree, including inputs not changed by this patch. It deliberately rejects later
source changes instead of silently treating them as the measured proposal.

The nine `package/apply-patches/sdk-current-*.patch` files are an alternative
for the manual patch tool. Its text handling appends a newline to six sources
whose selected bytes have no final newline: `btlShuffleResult.c`, `calendar.c`,
`code1_0022.c`, `code1_0024.c`, `k_fldEnvironment.c` and `y_fclCmbBall.c`, all in
`src/promoted/`. The manifest records exact before and after hashes for removing
that one appended LF. The unified diff already represents the exact endings and
needs no such finalization. The sequential manual-chunk simulation agrees with
all selected source hashes after those six recorded EOF corrections.

## What was already complete, and what this review added

The old `sdk-worker1/final/package-captured.json` and
`package-integrated.json` show that the four-owner caller release had already
been captured and finalized. Its final `evidence-manifest.json` was also complete:
112 owners, 20 fresh selections and 92 retained selections, with 3,554 functions.
This review recomputed all of that final evidence and compared the resulting
JSON with the original saved output. It agrees exactly. The original installer
was not needed or run.

The independent `worker3-sdk-merge-review/review_final_chain.py` had been saved
without its final execution result. This review redirected its output to new
scratch and completed it without compilation or writes to its original lane.
It verifies all 193 functions in the four captured owners, identical allocated
sections, 17 resolved retail targets, the 60-byte movie jump table and all 15
table destinations. The only differing nonallocated data are two generated
symbol strings in code1_0028's `.strtab`. It also verifies four unchanged
registration expressions and continuity of all 400 callback roles, including
the eight roles in those four owners.

One apparent source mismatch in that review is intentional. The original
four-owner code1_0020 release has hash
`3cb14f8590a54f3c213b0d9979821b48329ff9570d5cda9a1982962cc624a213`.
The final SDK integration subsequently corrected the explicit task argument to
`func_00452560` in `func_0020b6d0`. Select the final source hash
`5291b1952c270f99963a6607ae36fbbce362cb86fa3fda4f88aa09afae50d1e5`
and its later whole-owner receipt, as listed below. The complete final owner is
preserved in the SDK comparison; the final `0020b6d0` target resolves to all 812
emitted retail bytes, followed by four zero alignment bytes.

## Reconciliation with origin/main 4ec4893

Only two selected owner dependency closures differ from the previous final SDK
proposal. Both three-way merges are conflict-free. No other proposed owner or
used header required a fresh compile.

For `code1_0018.c`, the merged `func_00185850` retains upstream's reordered
state-zero/state-one bodies and all eight corrected float loads. Its only
differences from that current definition are the real `s32` SDK return type,
the retail-return annotation and `return 0`. The retail assembly returns zero
at both `00185888` and `001865D4`. The function remains guarded. The other SDK
callback and registration repairs in this owner are retained as previously
reviewed.

For `code1_0021.c`, the entire current `func_0021be80` definition is preserved,
including the upstream loops and quad storage. The entire local typed
`func_00212270` quad caller definition is also preserved. The new diff against
the live owner contains only SDK callback and registration changes. The same
checks retain the current shop and other quad caller definitions.

Both complete logical owners were compiled through their configured MWCC
wrapper with normal owner flags. There were no added or missing functions.
code1_0018 preserves 62 functions; code1_0021 preserves 108. All function bytes,
canonical relocation lists and allocated-data contents, sizes, alignment and
relocations agree before and after. Their source and object selections are
immutable under `objects/{before,after}/promoted/` in the new scratch root.

## Exact final source and object selections

Every source below is selected from the new `proposed/` tree. Every object
filename is `owner.o` and the adjacent compiler receipt is `receipt.json`.
The two upstream-drifted objects are under the new scratch root's
`objects/after/`; the remaining listed objects are under
`build/first-party-resume-final/sdk-worker1/final/objects/after/`.
`selected-objects.json` provides full paths and receipt hashes for all 112
owners, including those omitted from this table.

| Logical owner | Final source SHA-256 | Selected object SHA-256 |
| --- | --- | --- |
| `src/promoted/code1_0018.c` | `9a6e66a7d56322103f2d4549e43a1b75dc651214bbf50fa044419330cedfd51f` | `748ef674c7fbf89dc46f4eac0a668cbb88ac52e81fb117318a536f7f3aac1b71` |
| `src/promoted/code1_0021.c` | `1be8bb18900377219c0347cdfd6ba7671f926d0231aafc9d427de2a29b88b71e` | `f34feac9c70b2b137d0ab5b8366eca86891cf84450b5c767c07c240e44336a3d` |
| `src/promoted/code1_0020.c` | `5291b1952c270f99963a6607ae36fbbce362cb86fa3fda4f88aa09afae50d1e5` | `2a681b81adda6cb90b79c4bda952a78f27414aef5e0b34d9dcbe355d5455fe96` |
| `src/promoted/code1_0028.c` | `dc8ba3e8545e35e09437f135cdef67d4927d648cef741f8256cd9355a38cb026` | `80d32efa607e71b900fa39cd13c87c5cc2f1b6cc43780bb5bb5bd1c40f2c258e` |
| `src/Event/evtPMFileReader.c` | `843abd96b74e38ab3949efeff281fbf48dc39b200bc115781116896a771d51e9` | `14c48ab746b2c167814759ccb672c70e03f51246fc580ede512f469c3519d14d` |
| `src/promoted/evtEvent.c` | `3d3bf3e790fb0f815870eec4f2e488ccf3b88e6a93c532a39b24fb2ea85c2118` | `75d2243d102f3a696a4d11118398ac6abb2938f235326836fc456848b30bd875` |
| `src/Event/Fcl/y_fclCombine.c` | `c43675e62f9d655798a11a1af682cbc92e769390643691f17eb0a2b5c685216c` | `cef25f1a7ac551fb18817443d28bd506a02e5ccf60a071be15c54477eb849da0` |

The resulting selection consists of two fresh current owners, 19 retained
owners with the previous final fresh receipts, and 91 retained historical SDK
owner receipts. All recursive source/header dependencies match the current
proposal. All 3,554 function-name sets are preserved; 3,553 functions have
unchanged bytes and 3,553 have unchanged canonical relocation lists. The only
byte change is the intended Fcl initializer `002e8410`. The only relocation-list
change is the canonical callback name in `00192e90`; its complete relocated
bytes agree. Every allocated-data comparison passes.

## Callback, bounds and caller audit

The actual registration providers, task fields and dispatcher agree with
`SdkTaskUpdate` as `s32 (*)(u8 *)` and `SdkTaskDestroy` as `void (*)(u8 *)`.
Both handlers receive the task object. The work allocation is stored at task
offset `0x38`; the real getter `00452560(void *)` reads that field. The update
result is a signed word because zero retains the handler, another word can
replace its address, and `-1` enters the relevant destruction path.

The fresh lexical inventory includes all 400 role definitions and 257
declarations, with no incompatible or missing entries. The 241 registration
expressions comprise 58 root and 183 child registrations in 103 C owners.
Every per-function registration count agrees with the retail instruction
inventory. The five indirect expressions were checked explicitly: the two
scheduler locals, the two typed SDK-forwarded parameters and the field-unit
callback table. Its actual words are zero, `00166c80`, `00166e30` and
`00167120`. No direct caller to a changed SDK callback signature was found.

The final caller package retains the task returns from creators `00293ed0`
and `002862a0`, the pointer work return from `00294040`, the coherent movie
provider declaration and explicit getter task arguments. The independent
four-owner audit counts seven getter calls in code1_0028, seven in
evtPMFileReader and six in evtEvent. The later `0020b6d0` getter correction is
covered by its final owner selection and target proof. The `0020ff00` quad
caller repair remains a guarded C draft.

Bounds inventory still contains 23 constructor calls, seven direct setter
calls and five animation setter calls. The constructor and forwarders retain
the aligned unsigned-character representation copy; the unspecified prefix
is not evaluated as a numeric member in the reviewed paths. The four-byte
alignment and initialized width/height fields remain as previously reviewed.
Before/after lint has identical advisories: 73 H003, 11 H001 and two H007,
with no introduced findings.

All 16 SDK-target and 18 final-caller resolved proofs were recomputed using
their selected current inputs and frozen symbol maps. The initializer matches
all 3,256 emitted bytes with 148 resolved relocations and an eight-byte zero
alignment suffix. The movie caller's local 60-byte table is fully relocated
and equal to retail, with every destination checked. The unchanged quad
provider `00364fb0` and movie provider `0028fc40` were separately checked from
their exact source/header/object receipts and resolve exactly to retail.

## Remaining integration concerns

The source and object evidence has no identified blocker for applying this
package. Prime still owns the actual integrated-owner checks, whole-image
verification, full build and any runtime acceptance. None of those outcomes
is asserted by this worker's resolved-byte proofs.

Ninety-one selected historical receipts record compiler path and flags but
do not contain a historical compiler executable hash. Their exact source,
header, object and receipt hashes remain verified; all selections agree with
the currently configured compiler and owner flags. The 21 selected fresh
receipts include the executable hash, checked against
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
No reconstruction of the missing historical executable hashes is claimed.

Guarded C drafts, including the preserved upstream work, remain guarded.
Retail equality of a default whole-owner object may include its existing
assembly fallback and must not be reported as a new exact C recovery of that
guarded function. The unsigned-character bounds prefix remains unspecified;
the proof does not assign it a stable numeric value.

All 1,264 captured original package/review artifacts were hash-checked and
unchanged when this handoff was released. The only worker writes are the new
scratch artifacts and this integration note.
