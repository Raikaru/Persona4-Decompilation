# First-party continuation, October 6, 2026

The third integrated checkpoint has **6,773 first-party C matches and 88
assembly fallbacks**, out of 6,861 Atlus game and engine functions. Across all
origins, the verifier accounts for 13,102 windows: 9,593 MATCH and 3,509 ASM.
The remaining first-party work is listed in `remaining.json`; guarded source
repairs have not been counted as exact C.

The integrated build includes 604 game/vendor C objects and 54 Sony SDK
objects. Both retail hashes pass:

| Output | SHA-1 |
| --- | --- |
| `SLUS_217.82` | `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |
| Loadable image | `3d1d3d2b9d6ccb60836db239ab49674223025a78` |

The 658 eligible translation units contain 8,586 function windows, including
assembly fallbacks. That physical-link count is not a count of recovered C.
The progress generator separately reports 4,574 windows in completely
ASM-free C files.

## Exact recoveries and installed repairs

Three consecutive source-bound batches were built and sealed in
`build/finish-20261006/batch-1`, `batch-2` and `batch-3`. Each has its source
inputs, verifier report, successful link report and receipt. They retain all
previous C-link membership and pass both retail hashes.

| Exact function | Native C body / window | Complete proof |
| --- | --- | --- |
| Map updater `002add90` | 1,924 / 1,936 bytes; zero alignment suffix | [Map updater](../Smap_update_002add90_20261006/README.md) |
| Minimap constructor `002ae630` | 3,500 / 3,504 bytes; zero alignment suffix | [Minimap constructor](../Smap_constructor_002ae630_20261006/README.md) |
| Battle color fade `001b87e0` | 2,944 / 2,944 bytes | [Battle fade](../Battle_fade_alpha_001b87e0_20261006/README.md) |
| After geometry `004b8350` | 2,720 / 2,720 bytes | [After geometry](../After_geometry_004b8350_exact_20261006/README.md) |

Each recovery was checked in its complete source owner, including native
relocation identities, owned data and jump tables, and default and guarded
sibling bodies. Normal installed verification and actual C-link membership
were checked before recording the new match.

The same batches repaired battle cleanup arguments, native renderer
contracts, eight effect-vector callbacks and the After material caller.
The list range builder, contour and shuffle trail retain their assembly
fallbacks. Their C attempts now use the recovered storage and caller
contracts; these improvements have separate guarded proofs.

The shuffle trail repair restores finite pass limits, floating conversions,
actual sample and vertex arrays, and callback-visible color accesses.
Its 53 behavior cases cover 13,440 vertices. It still differs from retail
by 511 fully resolved instruction words. In particular, the native identity
macro reads an unwritten matrix-flags word; the guarded C explicitly defines
the identity flags. That is a documented defined-state repair, not a claim
that the unknown native bits match. See the
[shuffle trail proof](../Shuffle_trail_003768e0_20261006/README.md).

## What the checkpoint authenticates

`checkpoint.json` retains the sealed third-batch receipt and artifact hashes.
`source-inputs.json` records 1,922 source, header, tool and configuration
inputs. Four changed owners have fresh installed verification reports;
the other 1,918 inputs are identical to the preceding sealed batch. The
aggregate report contains the preceding rows only for those unchanged
inputs. No status was inferred from an old headline count.

The sealed aggregate report is
`build/finish-20261006/batch-3/combined-verify.json`; its SHA-256 is
`cd89e72c45a7b531d7d1c7b9d3f2236afe9a086800d724793f02a361182db042`.
The source manifest SHA-256 is
`d8bcad2ecd725ca306311a925522058a7dc68319cc9e6b685863b49c9610437e`.
The successful link report SHA-256 is
`66ba6dc2998317ca1753a814782634f128bfaef504fcbdb7743646dbf08b0620`.
The checked-in progress endpoints and README status were generated from
these reports with `tools/progress.py`.

Run the lightweight authentication without recompiling already proved
inputs:

```sh
python docs/probe_archive/First_party_continuation_20261006/verify_checkpoint.py
python tools/progress.py --validate-dir progress
```

The authentication verifies the current input hashes and that each recorded
remaining function still has its owned assembly marker. Later legitimate
source edits will make this historical checkpoint report drift; create a
new source-bound checkpoint rather than rewriting the old proof.

## Continuing the remaining work

The native compiler trace explained two exact closures in this continuation.
The battle fade needed its actual weighted-alpha contribution staged before
the sum, avoiding a prematurely commoned accumulator zero. The After strip
builder needed the two real branch-local cursors expanded before the retained
vertex count. Neither change writes compiler memory, forces a register, or
adds an unused value. Direct and debugger-compiled whole objects were
identical before their allocation traces were used.

Current private traces and negative probes live under
`build/finish-20261006`. They include the movie decoder's native 144-byte
frame record, the weather selector's row/counter allocation, the field
follower's conditional reconstruction and the FCL column's normalized short
index. Read those source-bound receipts before repeating an earlier family.
Their nonzero mismatch measurements are not exact matches or proofs that a
function is impossible to recover.
