# datCalc status recovery: live integration, 2026-09-20

`func_00238940` is now an exact C recovery in the rebased owner
`src/Main/Battle/Data/datCalc.c`. The independently reviewed delivery is
`build/first-party-resume-persist/status/delivery/recovery.apply_patch`.
The live input matched its recorded source hash exactly. The patch was applied
once, without changing any provider, caller owner, header, or compiler setting.

## Interfaces and behavior

The status function retains its explicit public `s32` skill argument. Its C89
identifier-list definition gives that parameter the narrow `u16` interpretation;
the definition is compatible because `u16` default-promotes to `s32` on this
target. Existing callers therefore retain their word argument transport while
the two real narrow consumers receive the correct skill value. The local rate
declaration now agrees with the actual provider:
`s32 func_00244f60(u32, u16 *, u16 *, u16, s32)`.
`func_002411a0` uses the same compatible promoted parameter boundary to preserve
its existing exact code under that declaration.

The body preserves the full 24-bit status result, the bounded 24-entry selection
buffer, all mode/kind returns, resistance checks, nine element skill searches,
the general status boost, random-call order, rate clamp, and survival-status
stores. The selection mode retains retail's asserted nonempty-mask precondition.
Unsigned table indexing keeps the two retail skill masks separate. The existing
skill-search helper and scoped loop-invariant setting produce the repeated
retail searches without new emitted helper code or synthetic effects.

Review covered the complete retail ASM and both IDA/Ghidra exports for the
recovered function and the adjusted `002411a0` definition; current helpers and
providers; and complete current C/retail ASM for all five dynamic status callers.
The external delivery audit was checked against eleven current source owners.
Ten remain byte-identical. `code1_001e.c` differs only in an unrelated diagnostic
comment above `001ee610`; its element-query declarations and calls are unchanged.

## Fresh live verification

`build/first-party-next/datcalc/verify_owner.py` invokes the unmodified official
verifier on the live owner. Its compilation wrapper only acquires the standard
owner lock and retains the actual object before temporary-output cleanup.
Both compilations use the configured MWCCPS2 3.0.1 b210 with `-O2 -Iinclude`.
Owner source, headers, configuration and relevant tool/ASM inputs are snapshotted
and checked for changes during each run. No old completed compilation was rerun.

The official owner report changes from **76 MATCH / 4 ASM** to
**77 MATCH / 3 ASM**, with both runs exiting zero. Only `00238940` changes status.
The official wrong-callee and wrong-symbol checks pass. The full byte/relocation
comparison preserves all **79 non-target functions** and all preexisting
allocated data. The sole data addition is the exact 40-byte, ten-entry switch
table at `0x00747c10`; all ten `R_MIPS_32` entries resolve to retail addresses.

| Fresh resolved function | Emitted / retail bytes | Relocations | Zero-only suffix |
|---|---:|---:|---:|
| `00238940` | 3728 / 3728 | 60 | 0 |
| `002411a0` | 2588 / 2592 | 70 | 4 |
| `00232d80` | 1304 / 1312 | 24 | 8 |
| `00233bc0` | 1280 / 1280 | 23 | 0 |
| `0023d8e0` | 208 / 208 | 5 | 0 |
| `002397d0` | 1636 / 1648 | 38 | 12 |
| `00239e40` | 260 / 272 | 8 | 12 |
| `00239f50` | 644 / 656 | 13 | 12 |
| `0023a1e0` | 684 / 688 | 13 | 4 |
| `0023a490` | 400 / 400 | 10 | 0 |

Errors-only `decomp_lint.py` reports zero findings. `git diff --check` passes.
The old lifted-guard proofs remain applicable: the accepted source and compiled
object are byte-identical to the delivered candidate, including unchanged guard
bodies aside from the reviewed compatible rate-argument preparations. No match
is claimed for `00235520`, `0023a6b0`, or `0023e6f0` by this integration.

## Immutable identities

- Input source: `a86afb3381ef3c753e87f0b366af36b8c3c07ca99ed15ad94f2028d3aa526928`
- Accepted source: `e128296daa3429de0d1d4f7f011373ab32e716b0042ebde1ad5910f9e6ef2390`
- Baseline object: `bcc859cec582d32d36da5c7d3dae1b5ce6ebf60b13a2373bc8ed930353953e2d`
- Accepted object: `1ed5b0e504967b0d83ba5fd487cf35e53025a07330db489c9d6a5d870ef6f4f9`
- Closure JSON: `1e3b6b82dd819a2c5ab0cd7b680a007d8549d6a22e4c02650726d1807b23d430`
- Reviewed patch: `8c30d35708fb4d85863534cd6ebb0abd67a422402c9ec833ddfc57f22328ffc7`

Retained outputs are under `build/first-party-next/datcalc/`: `before/`,
`after/`, `resolved/`, `owner-comparison.json`, `closure.json`, `lint.json`, and
`saved-evidence-audit.json`. The accepted live object is also byte-identical to
the delivery's frozen `probes/final-owner/object.o`.

The prime owns the combined-tree inventory, full build, and publication gate.
This lane performed no commit, rebase, push, or full build.
