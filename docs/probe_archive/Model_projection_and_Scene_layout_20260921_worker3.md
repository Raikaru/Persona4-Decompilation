# Model projection controls and Scene layout audit

The immutable evidence lives under
`build/next-wave-20260921/event/model-projection-wave2/`. Its `REVIEW.md`,
`LAYOUT_AUDIT.md`, and `SEAL.json` preserve the complete investigation. This
note makes the findings durable outside ignored build scratch. No production
source or build rule was edited by this investigation.

## Projection 0048a460

The actual `void(void)` projection returns through VU0 `vf10`; both call sites
in `func_0048b220` consume that register. Its incidental stack address in `v0`
is not a valid pointer result. Native source remains guarded and is not a match.

Six source shapes were measured with the configured MWCCPS2 b210 toolchain
and a frozen whole `mdlEffect.c` owner based on the sealed Scene-v3 closure:

| Shape | Bytes / window | Resolved differing words | Aligned edits |
| --- | ---: | ---: | ---: |
| Actual typed transform contract | 176 / 176 | 15 | 15 |
| Depth-first scalar projection helper | 176 / 176 | 15 | 15 |
| Returned projected-point value | 196 / 176 | 34 | 27 |
| Pointer to caller-owned output | 176 / 176 | 15 | 15 |
| Staged depth and ratio, propagation off | 176 / 176 | 15 | 15 |
| One shared-depth projection operation | 176 / 176 | 15 | 15 |

All 52 siblings, relocations and allocated data were preserved. The target's
ten references were resolved explicitly; the retained body fills all 176 bytes.
The 15 differences are FPR allocation around perspective division and the
`v0`/`v1` choice for constants and the final VU transfer address. The only target
assembly is its genuine `sqc2`/`lqc2` hardware transfer. No volatile ordinary
memory, fabricated return, padding, effect or arithmetic assembly was added.

The separate `guarded-contract/dependency.patch` proposes the actual
`RwV3dTransformPoint` pointer return and three pointer arguments for all three
calls in this owner. The provider source and retail wrapper confirm the
contract. Its guarded compile preserves all 53 functions, relocations and data.
This patch is **not installed**; prime reserves coordinated adoption.

Patch SHA256:
`6ddbf60158ea1430388e003f79d161778b99705888dde80f98dbef7c5b335246`.
Before-owner SHA256:
`a7e65d5f5bed276a1e7e8e1fa86acfde977a66a114ca71487ef3d78be8d85626`.
After-owner SHA256:
`7395ad4555cd58f2ce70ddf2c5a4feb65854411597eacffbac6b911e73093f93`.
The seal inventories 455 artifacts and seven completed compiler receipts;
patch applicability passed when sealed. No new instruction match was claimed.

## Discontiguous Scene owner

The no-gap eligibility rule is intentional. Commit
`7f330f04542b93adce65dd8c176d20a006de9138` records a September 3, 2026
mwldps2 crash when a foreign splat chunk was placed between two sections of the
same input object. This is recorded historical evidence, not a newly reproduced
crash. The older explanation that the carver would drop those foreign bytes is
stale: the current carver already consumes per-function ranges and preserves
foreign intervals, and the LCF already places named per-function sections.

Scene's sealed owner has two runs separated by `0026CEF0..0026D810`, with the
outlying `0026D810` function in Scene. Every function fits its own section and
window; both runs pass individually. The complete data planner accepts 72 table
bytes and 16 zero alignment bytes. The unsplit owner still fails the deliberate
text-layout gate.

A future build change needs separate input objects for contiguous runs,
preserved cross-run relocations and local symbols, one owner for every allocated
data section, and logical-source progress accounting. A successful split-object
link and full retail comparison are required before changing eligibility. No
splitter was implemented or validated here. Build and validation rules remain
unchanged.
