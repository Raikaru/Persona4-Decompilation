# Camp skill renderer `0013b420`

The applied recovery in `build/first-party-next/camp/b420-next/` independently
reproduces all 1480 instruction bytes in the 1488-byte retail window, resolves
all 14 relocations, and leaves eight zero tail bytes. Its resolved SHA-256 is
`6d536fe11c70467dae1f7fffd57b4a18f20b8e297109b717cf822cbcad58fd34`.
The current source is exact under the configured MWCC 3.0.1 b210 compiler and
the owner's `-O2 -Iinclude` flags.

The source uses the position, color, and shared sprite lifetimes established by
`00130ce0`. It preserves the full original height for both conversions, the
original Y coordinate through later position updates, and a single descriptor
cursor across the border and palette draw pairs. Complete eight-byte position
objects replace reads through adjacent scalar locals. The palette alpha is
passed to both palette draws, and the skill identifier at entry offset `0xA`
is read unsigned, as in retail. No function-specific optimization setting,
register forcing, volatile access, assembly, or fake effect was added.

## Actual interfaces

The recovered signature is `void (void *, Vec2f, s32, void *)`, matching the
existing declaration and actual `00138bf0` caller in `src/Camp/cmpSkill.c`.
The `00113790` declaration now uses the provider's actual `Vec2f` argument.

The `002bc860` provider now explicitly receives and forwards the three float
arguments previously passed through implicitly in floating-point registers.
The typed `002791f0` declaration agrees with its actual definition in
`src/itfMesManager.c`. The resulting provider object is byte-identical to its
accepted baseline: all 75 functions, relocation records, and allocated data
are preserved. Its own 48-byte function and all three relocations independently
resolve exactly to retail, with no suffix.

The existing `src/shdSkill.c` caller already has this contract. The remaining
guarded `00205170` caller in `code1_0020.c` is corrected to pass the three float
arguments first. The default owner preserves all 146 functions and allocated
data. An activated C witness retains its 1100-byte size and relocations but
changes 15 argument-setup words: coordinates and depth are now evaluated before
color and the item identifier. Retail `0020551c` through `00205574` uses this
same order. The guarded function remains nonmatching; no recovery is claimed
for it. Two attempted source-order adapters produce the same change and are
excluded from the minimal patch.

## Evidence and integration

The immutable input set builds on the completed `00130ce0` recovery and uses
the already verified owner object as its baseline. All 42 other functions in
the renderer owner and every allocated data section are unchanged. This
includes `00130ce0`, `0013c700`, `0013ea20`, `0013f720`, and `0013fb50`.

Artifacts under `build/first-party-next/camp/b420-next/`:

- `r30-family-object-lifetimes/`: first exact body, owner object, resolved
  relocation proof, and complete neighbor/data comparison.
- `r30-explicit-float-provider/`: complete provider source and whole-owner
  preservation proof.
- `r31-complete-contract/`: cleaned final source, default and activated caller
  witnesses, and the reviewable three-owner `integration.patch`.
- `r32-caller-value-order/` and `r33-caller-inline-contract/`: excluded neutral
  caller-adapter experiments.
- `r34-resolved-proof/`: unmasked proofs for `0013b420`, retained `00130ce0`,
  and `002bc860`, including every relocation and tail byte.
- `r43-current-stage/`: the minimal patch rebased onto the released character
  closure, current dependency snapshots, all neighbor/data comparisons, and
  the activated `00205170` caller witness.
- `r44-official-current/`: fresh actual compilation of all three applied
  owners, 247 MATCH / 17 ASM rows, no verification issues, and repeated
  unmasked `0013b420`, `00130ce0`, and `002bc860` proofs. All 264 functions and
  allocated data agree with the independent staged objects.

Applied source/object identities after the character closure:

| Owner | Source SHA-256 |
| --- | --- |
| `code1_0013.c` | `8e82526e8b282b352c4894630c2cb717582b86c1b2a5b3154336e6f75e7b0d9f` |
| `code1_002b.c` | `84ac795551d91842aa91db4f8d065401676524a189e91b60132d9b22146db683` |
| `code1_0020.c` | `055628f3709dd5cb3ebdf28d94f542fe889321b83d94cd909817ca542b4a5c6f` |

The renderer owner object SHA-256 is
`25de9ae637c8718500c5c82c19b6178b22230572fa6ffca74b4a064ec3a69ae1`.
The unchanged provider object SHA-256 is
`a9773a8f4f59088a1d9b784919df72452f5eb06d66784872bfb90a456d2c32bc`.

The minimal patch was applied after the prime released the character-accessor
closure. Current-source verification includes and preserves those changes.
The older r30-r34 snapshots remain immutable historical evidence.
The prime owns Git, the full linked-image gate, and publication.
