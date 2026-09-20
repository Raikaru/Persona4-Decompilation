# Exact twelve-card loader recovery

`func_0033e5c0` now has a verified ordinary-C proposal: **500 emitted bytes in
the 512-byte retail window, zero unmasked differing words, fourteen resolved
relocations, and twelve confirmed zero alignment bytes**. The repository
verifier reports `MATCH` for the target and `31 MATCH / 4 ASM` for the complete
owner. All 34 sibling functions, their canonical relocations, and both allocated
data sections remain unchanged against the fresh SDK-updated production owner.
The target owns no data sections.

The worker changed only its assigned scratch directory and this note. Production
integration, commits, and the project build remain with the prime.

## Integration package

All paths below are relative to `/persona4-decompilation/build/recovered-upstream`.

- Patch: `build/first-party-resume-continue/cards/final/integration.patch`
- Complete proposed owner: `build/first-party-resume-continue/cards/final/proposed/y_CmbCardEff.c`
- Object and compile receipt: the same directory's `owner.o` and `compile.json`
- Complete manifest: `build/first-party-resume-continue/cards/final/manifest.json`
- Independent resolved proof: `build/first-party-resume-continue/cards/final/exact-proof.json`
- Sibling/data comparison: `build/first-party-resume-continue/cards/final/comparison.json`
- Repository verification: `build/first-party-resume-continue/cards/final/verify.json`

The final source SHA-256 is
`a99316b4aaceecfa1b96a9f72475ba2694a05c20ee466f3f7734648f99a244ba`.
The complete object SHA-256 is
`7f33282d878e6b6da6df6394c95309be34c8d93f06bc8264222518abd76f2784`.
The resolved 500-byte target SHA-256 is
`e5dd23e58b21875142fb3d3164da38b462070fb48ea2664097b655cff83cff59`.

The configured compiler was `D:/mwcps2-3.0.1b210-060308/mwccps2.exe`, with
`-O2 -Iinclude`. The compiler hash, effective configuration, retail hash, Python
version, complete source snapshots, headers, assembly references, helper scripts,
and provider evidence are retained under `final/`. The final receipt pass checked
that captured live dependencies and their archived copies still matched their
hashes.

Verification commands completed successfully:

```powershell
py -3 -B tools\verify.py build\first-party-resume-continue\cards\final\proposed\y_CmbCardEff.c --json build\first-party-resume-continue\cards\final\verify.json --show-mismatches
git apply --check build/first-party-resume-continue/cards/final/integration.patch
```

The patch was checked against the live SDK package at HEAD
`1adec7e926b81497a86b3a4238ba57edfb780c2b`. SDK changes were uncommitted when this
receipt was written. They arrived after the initial card experiments; the first
handoff preparation stopped on its source-change assertion before compiling.
The worker inspected the delta, confirmed that it matched
`sdk-worker1/final-r2/proposed/src/promoted/y_CmbCardEff.c`, and prepared the final
patch on that newer source. The loader's guarded body was unchanged by the SDK
package. `final/sdk-context-transition.json` records the old and new owner hashes
and dependency changes. The new patch preserves the SDK callback registrations,
includes, and drawing types.

## Layout and compiler mechanism

The creator `func_0033f690` allocates `0x19FDC` bytes and copies twelve IDs into
the loader. The owner consumers, retail target, IDA, and Ghidra references support
this layout:

| Offset | Field |
|---|---|
| `0x0000` | Signed byte state |
| `0x0002` | Twelve 16-bit card IDs |
| `0x001C` | File handle pointer |
| `0x0020` | Environment block, `0x2738` bytes |
| `0x2758` | First bank of twelve `0xFB0`-byte cards |
| `0xE398` | Second bank of twelve `0xFB0`-byte cards |
| `0x19FD8` | Signed byte loaded count |

The proposal represents the banks as `CmbLoaderCard cards[2][12]`, with a
compile-time check that the complete state has the creator's `0x19FDC` size.
Its reserved bytes account for actual gaps in that allocated object. No emitted
padding, assembly body, extra arguments, or narrowed provider arguments are used.

The real array layout establishes the retail register allocation and retains the
repeated ID-slot calculation. A byte-addressed view of the real 16-bit ID slots
then fixes the operand ordering of two address additions. Finally, an explicit
second-card pointer followed by the second ID reload, under a function-scoped
`#pragma opt_propagation off`, preserves the retail order of address calculation
and load immediately before the second initializer call. The pragma is restored
with `#pragma pop` before the next function.

The first card initializer remains followed by an ID reload for the second
initializer. Zero IDs skip both calls, the loaded count advances once per pair,
the loop visits all twelve slots, and the signed state increments and zero return
match retail. The exact proof includes the state-machine branches and both call
arguments, including the GP-relative diagnostic format address.

## Bounded measurements

The previously unexecuted `card_record_layout.py` was recovered into a new runner.
The eleven negative probes in
`CmbCard_0033e5c0_value_lifetimes_000fca0.md` were not rerun. The old scripts,
negative notes, and artifacts remain intact.

| New proposal | Emitted bytes | Resolved differing words |
|---|---:|---:|
| Fresh guarded C baseline | 500 | 36 |
| Real two-by-twelve card arrays | 500 | 5 |
| Real arrays with scoped counter | 500 | 5 |
| Inline card-address helper | 504 | 54 |
| Real arrays with byte-addressed ID view | 500 | 3 |
| Field-relative byte ID view | 500 | 5 |
| Separate front/back array fields | 500 | 5 |
| Card byte-array decay | 500 | 5 |
| Explicit second card pointer then ID | 500 | 3 |
| Explicit byte pointer then ID | 500 | 3 |
| Explicit pointer/ID with propagation disabled | 500 | 0 |
| Inline second-card reload helper | 500 | 3 |

All measurements compiled complete logical owners and preserved their siblings
and allocated data. Per-candidate sources, objects, logs, target bytes, exact
relocation records, and differences are under `cards/layouts/0033e5c0/`.

The final proposal also aligns the loader's file-scope declarations with the
actual providers: the variadic diagnostic, pointer-returning file opener,
`HCdvd` polling/destruction, pointer-taking persona loader, and signed 32-bit
environment/card arguments. Other calls in this owner received the corresponding
pointer types. These adjustments remained byte-neutral for every sibling and
preserved the target's exact bytes. The SDK registration header supplies the
loader's actual `s32 (u8 *)` callback contract.

## Shuffle and saved-zero audit

The recovered `shuffle_lifetimes.py` proposals were measured independently under
`cards/shuffle/00375f00/`. `opt_lifetimes on` and `off` both retain the baseline
`156 / 160` bytes and two unmasked differing words. Reusing the cached context
for both state stores, with either setting, regresses to `128 / 160` bytes and
38 differing words. All siblings and data remain unchanged; no shuffle source
change is proposed.

`cards/saved-zero-audit.json` indexes 36 distinct functions from 24 saved SDK and
caller reports. Thirty-four have current unguarded C markers. The two remaining
SDK entries, `func_00212270` and `func_00385970`, compile their assembly fallback
in the saved source; their exact object receipts do not establish exact C.
`final/saved-zero-exclusions.json` records those checked markers and source
hashes. The zero-scoring YList, formation, and shdSkill production baselines are
also assembly fallbacks. The audit did not identify another abandoned exact C
candidate to integrate. It inspected saved receipts and current source markers;
it did not recompile the other workers' owners.

The worker's `agents action=message to=prime` calls returned
`AGENTS_BUSY: no agent family belongs to this conversation`. The filesystem and
terminal remained available, so work continued to this concrete handoff.
