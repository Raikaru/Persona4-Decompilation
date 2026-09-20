# datCalc retained recovery work

The recoveries originally committed as `eba2679` remain useful on upstream
`8217f8c0d309a5ad1467295e9a4395decd3ec00a`. That upstream still uses assembly for
`func_00232d80` and `func_00233bc0`; its independent changes to `00238940` and
`0023a6b0` are retained. This follow-up recovers an improved guarded `002411a0`
draft and archives the separate `00238940` proposal with its pending ABI work.

## Exact recoveries retained

Current configured b210 compilation reproduces the two committed recoveries:

| Function | Emitted / retail window | Relocations fully resolved | Zero tail |
|---|---:|---:|---:|
| `func_00232d80` | 1304 / 1312 bytes | 24 | 8 bytes |
| `func_00233bc0` | 1280 / 1280 bytes | 23 | None |

The other 78 functions and both allocated data sections remain identical to the
retained pre-recovery owner. The shared skill-search helper preserves public
`func_00232730` while recovering the six-skill mask. The status multiplier fixes
the case-4 table displacement, native unsigned conversion, pointer-subscript
address formation, and the three-argument definition used by the six retail
callers. The selector contract and full-ELF reference audit are documented in
`DC_worker7_20260919_recoveries.md`.

## `002411a0`: improved guarded draft

The current-owner comparison compiled the existing guarded body and exactly one
retained candidate with the configured owner compiler and flags:

| Source | Emitted / retail window | Relocation-masked differing words | Fully resolved differing words |
|---|---:|---:|---:|
| Previous guarded draft | 2584 / 2592 bytes | 473 | 505 |
| Retained worker7 draft | 2588 / 2592 bytes | 16 | 16 |

All 70 relocations resolve, and the four omitted retail bytes are zero. The 79
other functions and both allocated data sections are unchanged in the candidate
object. The remaining differences are the initial index/element register
assignment at offsets `0xC4..0x238`. The function remains `NONMATCHING` under
`SKIP_ASM`; ordinary builds continue to use its retail assembly.

The restored inline operations correspond to retail's skill-table lookup,
eight-slot skill search with equipment fallback, and equipment-property checks.
The base multiplier is converted to an integer before bonus queries, matching
retail `002417D4..002417E8`. Native unsigned equipment values precede the signed
16-bit provider conversion. Scoped compiler settings retain the measured
search preheaders and expression reuse. The fifth, unused argument matches the
call in `func_001f14f0`; no external provider declaration was changed.

The full retail body, IDA and Ghidra bodies, and the actual caller were reviewed.
The element shift retains the ordinary valid element range `-1..18`; this
recovery does not add an arbitrary-invalid-input guarantee. All three retail
random calls remain, including the middle call whose nonnegative remainder
cannot satisfy its comparison with zero.

Current proof artifacts, relative to the recovered-upstream worktree, are under
`build/recover-upstream/worker7/`: `before.proof.json`, `baseline411.proof.json`,
`retained411.proof.json`, `comparison.json`, and their complete `.c`, `.o`, compile
logs and resolved bytes. `after.proof.json` verifies that integrating the guarded
draft leaves all 80 production functions and allocated data unchanged.

The original retained candidate is in the match-next-latest worktree at
`build/all-first-party/datcalc/owner-eaa4708c2bba/002411a0/flag_u8_predicate.c`.
Its SHA-256 is
`3e176dbf800b5b6ff1fd6e10ed4d2933bffcee78904515664a71a17ed180f437`.
The earlier `DC_002411a0_body.c` is historical evidence, superseded by the current
guarded source.

## `00238940`: pending provider/caller ABI work

The complete retained function is archived as
`DC_worker7_00238940_pending_abi.c`. Its header records the two provider-signature
changes required by the measured translation unit and the existing inline
helpers it uses. Do not transplant the function alone and claim its saved score
applies to the resulting context.

The saved result is 3728/3728 bytes, ten masked differing words and ten aligned
edits. Its source replaces signed wide-shift status extraction with a native
24-bit unsigned mask, preserves native float conversions, and restores the
shared searches and status-return paths. The provider `func_0023d8e0` was widened
from `u16` to `s32` in the scratch declaration and definition, preserving its
saved emitted bytes. Current callers in `btlAICommand`, `cmpSkill`, `datScript`,
`shdSkill`, and promoted owners still use narrow declarations. Reconcile the
actual provider and every real caller together before promotion.

The saved-object check confirms 79 unchanged non-target functions and canonical
relocations, but the target adds a 40-byte local jump table with ten entries.
The generic resolver stops at local symbol `@1733`, HI16 relocation offset
`0x418`. Table placement and full target relocation proof are pending. This
recovery did not compile the archived draft again or start a cross-owner ABI
migration.

Complete original source, translation unit, object, alignment and measurement
logs remain in the match-next-latest worktree under
`build/all-first-party/datcalc/owner-eaa4708c2bba/00238940/`.
The inventory and independent retained-object checks are under that worktree's
`build/recover-upstream/worker7/`; its `REPORT.md` and
`measurements-summary.json` cover all 141 saved experiments, including hash
checks. For transformed experiments, the harness records the complete TU hash
in `candidate_sha256`, not the smaller candidate-body hash.

## Final validation

`python -S -B tools/verify.py src/Main/Battle/Data/datCalc.c` reports 75 `MATCH`
and five `ASM`, including `MATCH` for both committed recoveries and `ASM` for
the guarded `002411a0`. Errors-only `decomp_lint.py` and `git diff --check` pass.
The final production object SHA-256 remains
`1359e3580070db46745667a0a17b44f15979720878f2bb77e7c87ac13d4aab6c`.
The integrated guarded body is the measured candidate with only whitespace
changes; the archived `00238940` body equals its retained source exactly after
the added provenance header. No full build or cross-owner ABI migration was
performed.
