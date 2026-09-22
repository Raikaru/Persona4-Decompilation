# Exact wind-strip initializer: func_004a4450

`src/Graphics/Effect/effPolygonWind.c` now contains the exact C initializer for
`004a4450`: **824 executable bytes in the 832-byte retail window**, four fully
resolved calls and eight zero alignment bytes. The official native owner result
is **15 MATCH / 3 ASM**, replacing its previous 14 MATCH / 4 ASM.

## Donor and behavior

The complete retail window is byte-identical to `004a1d70`, an already-matched
first-party function in `src/promoted/code1_004a.c`. Its actual current C body
was transplanted into the wind owner and measured there. Both the initial
consumer-declaration experiment and the corrected native-interface experiment
produce zero resolved differences. No source was recovered from the assembly
by substituting inline assembly or padding.

The function skips an empty mesh set, locks and reloads the model geometry,
constructs the first strip's colors and horizontal texture coordinates, copies
that strip for the remaining meshes, then unlocks the geometry and updates its
flag when the model requests it. The copied implementation uses separate
unsigned row and replication counters and named byte lengths, keeping the
original compiler lifetimes. Earlier attempts based on a different nearby
initializer tied at nine or twelve differences; they are not the source used
for this recovery.

Each row has four color records and four two-float texture-coordinate records.
The packed edge colors have zero alpha; the inner two records share the
computed opacity through a four-character color copy. The initializer writes
only the horizontal texture-coordinate components. The vertical components
are intentionally left for the later `004a4a10` update, just as in retail;
the recovery does not pretend that the allocator zero-initializes them.

The direct callers are `004a4790` and `004a48d0`. They allocate or clone the
model, clamp the minimum frame count to three, and invoke the initializer with
its work and settings pointers. Valid allocated dimensions and finite fade
parameters are the existing resource contract. The minimum clamp alone does
not prove arbitrary upper counts or nonfinite input safe, and no such claim is
made here. No new execution-time validation or changed arithmetic was added.

## Scoped call interfaces

The game owner now declares the geometry lock and unlock functions using their
native `RpGeometry *` interfaces, and the memory-copy function using its actual
pointer return. All affected geometry-pointer arguments in this owner are
explicitly converted. The three still-guarded update functions were each
compiled separately before and after those declaration corrections; all their
non-target functions, relocations and allocated data remain unchanged.

Review also found two inherited game-provider declaration discrepancies in
the initializer's allocation paths. The wind owner now agrees with the active
`00483e10(s32,s32,s32,s32,s32)` pointer-returning constructor and
`00484010(u8 *)` pointer-returning clone provider. All three constructor calls
preserve their original halfword loads and supply the table address through
the actual integer-address argument. All three clone calls read and store the
actual pointer value. This correction preserves the **complete eighteen-function
owner object byte-for-byte**. No provider implementation or other owner was
edited for this recovery.

## Verification and artifacts

The final installed owner was compiled with its configured native MWCCPS2 b210
profile, `-O2 -Iinclude`, and its authenticated object was graded by the official
verifier. The target's four call relocations are:

| Function-relative offset | Destination |
| --- | --- |
| `0x50` | `func_003c2290` |
| `0x29C` | `func_0043f810` |
| `0x2B4` | `func_0043f810` |
| `0x2E0` | `func_003c22f0` |

All seventeen neighboring functions retain their instruction bytes and
canonical relocation lists. Existing allocated data is unchanged; the target
adds no owned data. The inherited loop-invariant compiler setting is scoped
with push/pop around the recovered function. Source lint has no errors;
existing and measured optimization-setting advisories remain documented.

The immutable artifacts are under `build/first-party-continue-live/wind/`.
`donor.py` contains the candidate experiments and donor authentication.
`integrated/proof.json` records the first native installation, including the
three independently enabled guarded update comparisons. The final
game-constructor/clone correction is sealed by
`allocator-contract/live-proof.json`, `allocator-contract/live/compile.json`,
`allocator-contract/official.json`, and its completion receipt. Older receipts
retain their original source hashes; they are not overwritten by the follow-up.

| Final artifact | SHA-256 |
| --- | --- |
| Installed wind owner | `c055ab7b7c61af04e68af67f40272833ba2734b65c8f8330905fc33deb891ae5` |
| Complete native owner object | `f904110beabeaee75c524e6b81dff0c018bc1707e21ea31b0600d1861ef759b5` |
| Raw target instructions | `d9f08bfece5497f1536ea2a588908de9c568443d211c554e07539adf5aad56e8` |
| Fully relocated target instructions | `1ac947b5a8485089d730a81eaec243ed0800904f84973c886007f21c4c2d2012` |

The donor source/object receipts and complete retail identity are retained
alongside the proposal. Independent read-only source, caller and native-object
review is under `build/first-party-continue-live/wind-review/`. This is one
additional first-party C recovery; the three guarded update routines remain
unfinished and are not counted as matches.
