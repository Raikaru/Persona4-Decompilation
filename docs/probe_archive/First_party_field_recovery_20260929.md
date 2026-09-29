# Field recoveries, 2026-09-29

These recoveries start from main `118189de` in the shared
`work/finish-first-party-20260929` worktree. Reproducible whole-owner probes,
compiler receipts, source snapshots, relocation reports, and unsuccessful
candidates are retained under `build/first-party-finish-20260929/field/`.
No prior worktree was modified.

## `k_fldFrame.c`: `func_0016a110`

The retained recovery in `../compassionate-20260928` was ported narrowly.
The local intersection union contains the complete 24-byte SDK payload,
including its quadword member, followed by the type at offset 24. Four-byte
packing and compile-time size checks preserve the 28-byte record. Contact-local
float lifetimes preserve the retail multiply/add order and register reuse.
The current vector and grid provider declarations were retained.

The installed owner verifies at **16 MATCH, 0 ASM**: the recovered function
contains 2,124 instruction bytes and the retail window has four zero alignment
bytes. All fifteen existing matches are preserved. Evidence:

- `field/frame-port-verify.json`
- `field/frame-port-diff.txt`
- `field/port_frame.py` and `field/k_fldFrame.before.c`

Scoped lint reports zero errors. The warnings comprise measured pragmas and
two pre-existing grid-provider declaration disagreements.

## `k_fldFBN.c`: `func_0015e960`

The reconstructed loader builds the model-request and 28-byte entry tables,
filters the two animation tables against the field parts, and then applies the
remaining scene transforms. The archived draft depended on an obsolete narrow
model-kind declaration. The recovery keeps the actual `u32` model-kind
provider contract and caches the loaded part kind as a `u32` value.

Provider declarations were checked against their definitions: the calendar
getter is signed 16-bit, the day-part getter unsigned 8-bit, the calendar
predicate returns signed 64-bit, and the table providers pass real pointers.
The formatter, printer, and diagnostic retain their real variadic interfaces.

Loop indices are initialized before the cached bounds and advanced before the
corresponding part pointers, as in the retail code. The measured loop-invariant
and lifetime passes preserve the cached bounds and allow the loading count,
part index, animation-entry pointers, and later transform index to reuse
registers across their disjoint phases. The retained experiment chain is:

| Candidate | Differing words | Instruction bytes | Changed siblings |
| --- | ---: | ---: | ---: |
| Archived body with current provider contracts | 50 | 1,696 | 0 |
| Cached unsigned part kind | 49 | 1,696 | 0 |
| Retail index and pointer update ordering | 41 | 1,696 | 0 |
| Lifetime pass and count/file/part declaration order | 2 | 1,696 | 0 |
| Source-ordered index initialization | 0 | 1,696 | 0 |
| Final provider-contract and commentary cleanup | 0 | 1,696 | 0 |

The installed owner verifies at **2 MATCH, 1 ASM**, preserving `0015e870`.
All 424 words of `0015e960` match, with no alignment tail. The verifier also
checks named call and data relocations. Evidence:

- `field/fbn-native-verify.json`
- `field/k_fldFBN/native-loader-contracts/`
- `field/probe_fbn.py`, `field/clean_fbn.py`, and `field/install_fbn.py`

Scoped lint reports zero errors and one pre-existing disagreement for the
pointer-valued file-loader wrapper `00455f70`, whose defining source still
uses integer-address types.

## Remaining `func_0015f000` initial yaw

The first rotation call loads yaw from `sp + 0xC4` at `0015F224`. The first
store to that slot is at `0015F344`, after the rotation. Earlier calls receive
heap-backed resources, not this local angle storage; the actual resource
loader callers pass exactly two arguments. The retained archived candidate
does not establish a defined first-iteration yaw. Its assembly fallback is
therefore retained while that source lifetime remains unresolved.
