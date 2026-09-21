# Recovered continuation: 62 additional first-party functions

The publication checkout's completed `build/campaign-checkpoint/resumed-62/`
run reports **6,438 MATCH / 422 ASM** among 6,860 first-party functions.
All 62 replacements since `0360227` have full code-relocation proofs;
referenced owned data and any zero alignment suffixes are checked separately.
The complete report is 8,073 MATCH / 4,647 ASM over 12,720 functions.
These are the pre-rebase counts; third-party classification and coverage may
change with later upstream work.

The ten recoveries added after the earlier 52-function record are:

| Function | Executable/window bytes | Code relocations |
| --- | ---: | ---: |
| `00137890` | 1340/1344 | 28 |
| `0032fbc0` | 1180/1184 | 32 |
| `001c1040` | 1884/1888 | 48 |
| `001c21d0` | 3336/3344 | 59 |
| `001c2ee0` | 4040/4048 | 87 |
| `001c3f70` | 4504/4512 | 74 |
| `001c9820` | 3364/3376 | 56 |
| `00196d00` | 1736/1744 | 10 |
| `0015d730` | 4196/4208 | 269 |
| `00154720` | 1008/1008 | 7 |

The resumed campaign verified all 373 recorded compiler-object hashes and
all 62 target source receipts against the live publication source. Three
owners changed after that full report for the reviewed `00355410` opacity
contract. Its word-sized opacity input is narrowed by the actual byte store;
the two external callers and one guarded local declaration now agree.
The publication check freshly compiled those three owners, reporting
210 MATCH / 13 ASM across 223 functions, with every earlier status, differing
byte count and emitted size preserved. The contract is not an additional
function recovery. Its earlier before/after object comparisons are retained
under `battle-worker5/opacity-closure-20260921-v2/` in the recovery worktree.

The six most recent source deliveries and the mipmap/camera caller repairs
are bound by `build/campaign-checkpoint/completed-wave-62/manifest.json`.
The opacity transfer is bound by `build/campaign-checkpoint/opacity-transfer/`.
The resumption audit, original uncommitted files and binary patch are preserved
under `build/continuation-20260921/initial/`; `initial-state.json` and
`pre-rebase-verified.json` identify the exact source fingerprints.

The camera owner now has 62 C matches and only `001c5b80` still in assembly.
The field-loader and environment owners are fully matched. The remaining
422 entries are still assembly fallbacks; their previous experiments remain
available. No saved zero-score candidate is counted without completing its
provider/caller and combined-owner proof.
