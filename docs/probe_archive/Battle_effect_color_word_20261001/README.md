# Matched effect callback color-word repair

Reviewed against main `725b5756604b687ed21759dacf0c15105d714ecc`.

The sole production change replaces `(u32)*(u64 *)(packet + 4)` with
`*(u32 *)(packet + 4)` in `func_001d6360`. The surrounding 24-bit mask,
assignment, phase conditions, callback signature and pragmas are unchanged.
This is a source-correctness repair; it does not add a match.

## Field and allocator evidence

- Retail `001d650c` loads one word at effect+4; `001d6510..18` masks its low
  24 bits and stores one word back.
- Initialization `001d6300` calls `001d6ce0` and stores the returned effect at
  work+0x18 (`001d6338..40`). The provider obtains a record from the owner's
  pointer array and initializes the u32 color at +4, the separate step byte
  at +8, and the counter word at +0xc (`001d6d6c..84`).
- `001d6ad0` allocates 0x24-byte records and initializes the same fields.
  The existing `001d6680` view also declares the color as u32 at +4.
- Startup supplies `0044f510`'s memory-function table to `RwEngineInit`.
  `0044f510` puts `0044ec60` in its allocator slot; `_rwMemoryOpen` copies
  that slot to `008873e8` at `003e1bac`. The allocator rounds its returned
  address to 16-byte alignment at `0044ed30..54`, returning it at `0044ee40`.
  Effect+4 is therefore four-byte aligned, but not eight-byte aligned.
- A compile-time layout probe with the owner's actual EE compiler confirms
  that `{u8; u64; u8;}` has size 24, consistent with eight-byte u64 alignment.

The old read crossed the four-byte color into the independent step/padding
bytes, still within the 0x24-byte allocation. It also used the wrong effective
access type and an invalid alignment assumption. The u32 read agrees with
its producers; the corresponding signed assignment remains valid and the
masked value fits s32. No new accepted packet states, control flow, or timing
arithmetic are introduced. Removing undefined behavior restores the intended
retail packet domain; it is not a claim of defined-C equivalence for the old
misaligned expression.

## Focused validation

An isolated main-only projection preserves all 94 owner functions, allocated
sections, relocation bindings, and global symbol bindings with production and
all guards enabled. Verification reports **92 MATCH / 2 ASM**. The callback
remains **516 bytes**, SHA-256
`df7f88658512473c2b1180b61360eacf66046c4aa55590a71d44bda58f04585a`.
Its four call relocations independently resolve to the retail callees.
Lint reports zero errors and 25 inherited warnings.

The exact callback body runs 4,500 cases per O0/O2 with Clang i386
undefined/bounds traps. The fixture compares every work/effect byte, return
value, and provider call count against a retail-derived oracle. Six independent
controls reject wrong masks, phases, options, freeze flags, abort steps, and
frame increments via expected fixture assertions. Signed timing inputs are
bounded; overflow behavior is not invented.

A separate x86_64 test extracts and executes the exact assignment with asserted
eight-byte u64 alignment. Corrected source passes at O0/O2; restoring the old
wide read traps at both levels. This test has its own unittest class, so lack
of i386 support does not skip an otherwise available x86_64 alignment check.
The i386 callback fixture alone does not prove the alignment defect because
that ABI permits four-byte u64 alignment. Neither fixture proves strict-aliasing
behavior; effective-type evidence comes from the production field/producers.

```sh
python tools/verify.py src/promoted/code1_001d.c
python tools/decomp_lint.py src/promoted/code1_001d.c
python -m unittest discover -s tests -p test_battle_effect_color_word.py -v
```

The normal native32 helper uses native Linux i386 execution or an existing WSL
installation. Unsupported execution paths report skips, which must not be
counted as passes. The independent review used an existing QEMU i386 runtime
for the complete callback suite and direct x86_64 execution for alignment.
The main-based integration also passes both retail SHA-1 gates:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` for the loadable image and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` for the final ELF. The baseline and
candidate linked reports are identical: 604 C owners, 54 SDK owners, and
8,586 linked function windows, with no membership loss. The ordinary suite
reports 865 tests, 32 skips, and no failures or errors; the focused QEMU run
passes all three methods without skips. No new matching-function credit is
claimed.
