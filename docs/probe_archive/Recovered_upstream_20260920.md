# Recovery rebased onto September 20 upstream

The seven saved recovery commits were rebased from `1344039` onto
`9ed8ca6b1442af9a305f75491a44950816fa78df`, producing `17f42ca` before the
final archival and caller follow-up. `git range-diff` reports the seven patches
unchanged. All thirteen production files changed by the three intervening
upstream commits retain their upstream contents. The original worktrees and
the pre-rebase tip remain preserved locally.

## Additional C recoveries

These five functions still use assembly in that upstream revision. Fresh
compilations in the rebased owner contexts, followed by complete relocation
application and retail comparison, give:

| Function | Executable bytes | Retail window | Resolved code relocations | Verified zero tail |
| --- | ---: | ---: | ---: | ---: |
| `00232d80` | 1304 | 1312 | 24 | 8 |
| `00233bc0` | 1280 | 1280 | 23 | 0 |
| `00303610` | 1036 | 1040 | 8 | 4 |
| `0032a960` | 1684 | 1696 | 53 | 12 |
| `0032b000` | 1904 | 1904 | 54 | 0 |

The skill-mask function reuses the existing skill-search helper, including its
equipment fallback. The status multiplier preserves its signed-byte status,
native unsigned conversion, unsigned table addressing, and the actual caller
contract. The rule predicate uses independent search counters and retains the
retail rule-pointer behavior. Its complete 44-byte switch table, including all
eleven relocated entries, also matches retail. The two draw functions use the
shared position-by-value contract and constructor-backed float snapshots.

The independent comparison with freshly compiled upstream owners preserves
68 non-target draw functions, 40 non-target combination-menu functions, 78
non-target battle functions, and all 58 provider functions. Existing allocated
data is unchanged; the rule predicate's new compiler-owned table is separately
resolved and verified. Protected `0032f4d0`, `00315310`, `00232730`, and the
`002b6c30` provider also pass full unmasked target proofs.

The compiler inputs for this comparison were immutable copies of the current
and fetched upstream sources, each in its own scratch directory. The actual
logical source owner selected the compiler and flags; source hashes were
checked again after compilation. The proof does not rely on the instruction
alignment tool's treatment of unsupported opcodes.

## Other retained worker work

The shared Fcl position and constructor declarations, field and RenderWare
contract corrections, four camera symbol aliases, and native Windows probe
locking are retained. Earlier exact recoveries already present upstream are
preserved and are not counted again in the table above.

`002411a0` retains its assembly fallback. Its saved current-context measurement
improves from 473 masked differing words (505 after relocation) to sixteen
under either comparison, at 2588/2592 bytes with seventy resolved relocations.
The pending `00238940` proposal remains archived because its provider-width
correction and owned jump-table proof are unfinished.

The truthful Fcl packet contract changes ten other guarded draft bodies:
eight saved differing-byte scores worsen and two improve. Fourteen other
guarded bodies retain identical instructions and relocations. These drafts
remain assembly-backed; this migration is not represented as a matching
improvement for every draft.

## Preserved unfinished candidates

`Recovery_20260920_pending/` contains exact copies of nine additional saved C
bodies and a hash manifest. In particular, the saved zero-word `001a4800` and
`002e8410` candidates are now durable outside ignored scratch directories.
Neither is promoted: the former still needs full target/owner proof and its
packet-return contract; the latter has a saved full target proof but still
needs coherent creator and SDK callback contracts. The remaining creator,
UI, formation, and weighted-selector proposals have explicit limitations in
the archive README and inventory.

The damaged `KOC`/`KoC` case-colliding archive and rejected rank-up, callback,
and provider-regressing experiments were not substituted into production.
The newer upstream guarded `002f0f00` loops and restored switch arms were
preserved instead of restoring an older saved whole-owner snapshot.

## Verification records

Fresh repository-wide compiler verification passed on `17f42ca`: 12,720
functions scanned, 8,011 MATCH and 4,709 ASM. The first-party subset contains
6,860 functions, with 6,376 MATCH and 484 ASM. There are no other statuses,
incorrect call destinations, or incorrect data-symbol relocation targets.
The source fingerprint is unchanged across the complete verification run.

The complete Linux unit suite runs 611 tests successfully with eleven skipped;
all seventeen native Windows probe tests pass. Compiler-pragma checks use the
existing pinned Wibo compatibility runtime so the Windows compiler receives
valid Linux paths. Initial setup failures are retained in the local logs;
the successful run is `tests-linux-wibo`.

Repository integrity lint reports no errors. Scoped source lint records nine
optimization-pragma advisories; they are inherited outside the new match
bodies. Python byte-compilation, committed progress validation, JSON/YAML and
workflow parsing, and all 13,102 objdiff configuration entries pass their
checks.

Local reproduction and evidence are under
`build/recover-upstream/resume-20260920/`: `upstream-comparison.json`,
`independent/proof.json`, per-owner source/object receipts, test/configuration
results, and the independent review. The source code and pending candidate
archive are tracked; compiler objects, retail bytes, and machine-specific
configuration are not part of the recovery commits.

## Final integration on ff294a8

The interrupted integration resumed from the clean nine-commit recovery tip
`c772d4e60735902d85cec5fd1b143d7351228bce`. The already completed full build
was recovered from its receipt: exit zero, 172 C objects and 56 Sony SDK
objects linked, with both the loadable image and the complete executable
matching their retail hashes. It was not restarted to retrieve its terminal.

The recovery was then rebased onto
`ff294a8d200d571a635813cdcd29ca895d3a70ee`. Seven patches are unchanged;
the other two differ only in diff context around upstream's replaced loop
labels. The newer `002f9d90` loop forms remain alongside the recovered Fcl
position contracts. The old tip is retained in the local backup branch
`backup/recovered-c772d4e-before-ff294a8`; other worktrees remain intact.

One completed saved correction had not been integrated: the guarded
`001f14f0` caller lacked `00242990`'s pointer/int prototype. The actual
provider is `s32 func_00242990(u8 *, s32)`. Restoring its declaration and
explicit pointer conversion changes neither the active object nor the
separately enabled guarded object, including all 158 functions, relocations,
and allocated data. This is a recovered contract correction, not another
function promoted from assembly.

Fresh independent compilation against this upstream again proves all five
additional C functions and the protected callers/provider listed above.
The comparisons retain 68 draw siblings, 40 combination-menu siblings, 78
battle-calculation siblings and all 58 provider functions. The rule predicate's
44-byte owned table is fully relocated and compared separately.

Complete-tree verification reuses the earlier full run only after reproducing
its exact committed input fingerprint. All twelve changed C owners were
recompiled: 647 functions, 564 MATCH and 83 ASM, with no status regressions.
The other 929 tracked verification inputs are unchanged, including headers,
tooling, configuration and tests. The resulting report still covers 12,720
functions: 8,011 MATCH and 4,709 ASM; the first-party subset is 6,376 MATCH
and 484 ASM. This is an explicitly recorded combination of fresh owner
checks and verified unchanged inputs, not a claim that every compiler job
was rerun. The full Linux test suite was rerun and passed all 611 tests with
eleven skipped; repository integrity lint reports zero errors.

The final rebased build completed with exit zero in 888.43 seconds. It retains
172 C objects linked from source and 56 Sony SDK objects. Its cache reused
361 eligibility objects and 168 link objects, rebuilding twelve and four,
respectively. The loadable-image SHA-1 is
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete `SLUS_217.82`
SHA-1 is `4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Both match retail.
The fingerprint before and after the build is
`c2bd4f1d3fb12bc5ae20fa24830995ef879345fb86f2778a7e152ea74214a763`.
It includes the recovered caller correction, subsequently committed as
`10ee8a6`, rather than only the commit checked out when the build started.

Final evidence is under `build/recover-upstream/continue-20260920/`:
`verification-inputs.json`, `changed-verify.json`, `full-verify.json`,
`independent/proof.json`, `saved-caller/proof.json`, `build-result.json`,
`linked-report.json`, `publish-audit.json`, and the test/lint receipts.
Pending bodies remain in the tracked recovery archive with their unresolved
contracts and proofs identified; they are not included in the five-match gain.
