# Two-sided shuffle-card constructor: 00377eb0

The recovery starts from the current shuffle owner after the nine-commit
first-party continuation was rebased onto `6fce030`. The prior guard was not
an exact C implementation: its resolved baseline differs in 113 words and
emits 796 bytes for the 800-byte retail window.

## Accepted result

`func_00377eb0` is ordinary, unguarded C and reproduces all **800/800 bytes**.
All **22 code relocations** are applied and equal retail, including the two
height references at GP displacement `-0x7C20`. There is no omitted suffix
or new owned data. The function retains the existing loop-invariant setting,
now scoped with pragma push/pop. It does not require the additional lifetime
pragma tested during reconstruction.

The owner keeps all **51 other functions** byte-identical with canonical
relocation records, including the explicitly corrected readiness callback,
and all **four allocated data sections** remain unchanged. Fresh official
verification of the owner and its caller file reports **54 MATCH / 8 ASM
across 62 functions**, with no unexpected status.

## Source corrections

The allocator returns a 0x240-byte work buffer. Task registration returns a
different object whose work pointer is at offset 0x38. The earlier draft
overwrote its only local with that task result and subsequently built vertices
through the task pointer. The accepted source keeps `work` and `task`
separate, initializes the work buffer, passes the task to the existing setup
functions, and returns the task handle. This follows retail's separate s1
work and s0 task lifetimes.

The two rectangles use the existing `iGpffff83e0` definition at `0x007614D0`.
The old source instead named `iGpffff81e0`; relocation masking could hide that
wrong constant. The source reloads the actual height before constructing
the reverse face, in the same order as retail.

Positions are actual three-float objects, and texture coordinates are float
arrays. Both loops copy the three position components into a fully initialized
local before assigning it to the destination. This removes the old artificial
stack gap and the array/structure reinterpretations. The four vertices of
each face have stride 0x24; their positions, four color bytes and texture
coordinates stay within offsets 0x120..0x23F of the allocated buffer. Fields
that retail leaves as initialized by the allocator receive no extra stores.

Each loop has its own block-local index. Together with declaring the real
work pointer before the task pointer, this reproduces the retail register
allocation without forced registers, assembly, synthetic state or extra
memory traffic. The loop body and constructor call order are unchanged.

The readiness callback now explicitly passes its incoming task to
`func_00378220`. Retail keeps that task in a0 for the call; the earlier
unprototyped C call omitted it. The actual readiness provider accepts `u8 *`.
Both declarations and both external readiness calls in `btlShuffleResult.c`
now agree with that provider. Its three constructor calls use the full
`s32 (u8 *, s32)` prototype and retain their original arguments.

## Measured controls

All measurements used immutable complete-owner inputs and the configured
MWCCPS2 b210 profile, with the owner's existing invariant setting.

| Source form | Resolved differing words | Emitted bytes |
| --- | ---: | ---: |
| Original guarded body | 113 | 796 |
| Correct work/task and height, old stack aggregate | 114 | 796 |
| Both real vector assignments, old stack aggregate | 116 | 808 |
| Independent stack objects, original pointer declaration order | 70 | 800 |
| Work pointer declared before task pointer | 60 | 800 |
| Actual vector objects and independent loop indices | **0** | **800** |

The `opt_lifetimes on` control also reaches zero with the corrected pointer
order. Ordinary independent loop scopes reach the same result without it;
the accepted function uses those scopes. Correcting the readiness input and
making all caller declarations explicit preserves the zero result.

## Current-source and caller proof

`build/first-party-next/shuffle/current/proof.json` contains fresh production
compilations and dependency hashes. Additional protected unmasked proofs are:

| Function | Executable/window bytes | Code relocations |
| --- | ---: | ---: |
| `00377e10` readiness callback | 72/80 | 2 |
| `00378220` readiness provider | 20/32 | 0 |
| `00374d20` earlier recovery | 1732/1744 | 37 |
| `00375b40` earlier recovery | 520/528 | 10 |

All omitted bytes in these protected windows are zero alignment. The entire
active caller object remains identical across its ten functions and one
allocated data section. Separately enabling each affected guarded caller,
`00381a70` and `00382ea0`, also produces an identical complete object. These
guarded callers remain assembly-backed and are not counted as new matches.

The before/after production placement checks retain eligibility for both
owners: **52/52** accepted shuffle-draw functions and **10/10** caller
functions, valid layouts and data, with no gaps or unresolved references.
The source lint reports zero errors and two optimization advisories: the
measured setting here and an unchanged neighboring setting. Whitespace
checks pass.

The original guard, full-owner snapshots, every candidate, compiler log,
object, instruction alignment and resolved bytes are retained under
`build/first-party-next/shuffle/`. The existing historical C archive remains
unchanged. The official current-source check is:

```text
python tools/verify.py src/Battle/btlShuffleDraw.c src/promoted/btlShuffleResult.c --json build/shuffle-verify.json
```

The independent relocation and sibling check can be repeated using a fresh
output directory with `build/first-party-next/shuffle_current.py`, or the
existing `build/recover-upstream/prove.py` with the saved
`shuffle/proof/owner-before/owner.o`. Whole-project integration remains the
prime's separate gate; these scoped checks do not claim that all first-party
functions are recovered.
