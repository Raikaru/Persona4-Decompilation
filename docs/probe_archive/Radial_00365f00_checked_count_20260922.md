# Radial drawing: checked count lifetime

`src/shdMisc.c::func_00365f00` is installed as C and reports official
`tools/verify.py MATCH`. The native owner was compiled from the final installed
source after the production release at
`2260985773b9b9c7b7a9aeb487ee0e2aa80f909f`.

## Recovered operation

`radialCheckedSegmentCount(u32)` preserves the existing low-halfword mask and
the assertion for counts outside 1..100, then returns that count. The caller
retains the full 32-bit `segments` argument for angle division. Loading the
edge components in alpha, blue, green, red order gives red its retail `$fp`
lifetime, while the checked return gives the loop count its retail `$s3`
lifetime. The previous 13-word residual exchanged these two values; the
conflicting edge-green and mode diagnoses in the removed source comments were
incorrect.

The shared declaration and callers retain the same argument contract. Invalid
counts are reported, not clamped. The 102 rows of 16 floats, previous-row
reciprocal store, unsigned color conversions, callback reloads and 64-bit flag
operations are preserved. The change adds no padding, ordinary assembly,
fabricated state, vertex initialization or private callee declarations.

## Current-source proof

All paths below are relative to
`build/finish-first-party-20260922/radial-drawing/`.

| Evidence | Result |
|---|---|
| Configured compiler | Native MWCCPS2 b210, `-O2 -Iinclude` |
| Executable target bytes | 1148 |
| Retail window | 1152, including four zero alignment bytes |
| Fully resolved differing words | 0 |
| Resolved relocations | 17 |
| Additional target-owned data | None |
| Existing sibling functions | All nine byte/relocation pairs identical |
| Allocated data sections | Identical |
| Official full-owner result | 8 MATCH, 2 ASM |
| Source lint | 0 errors; three pre-existing sibling pragma advisories |

`installed-native/authenticated-proposal.json` authenticates the retained
baseline, recursive includes, fallback ASM, compiler and flags against current
production before installation. It also authenticates the exact scratch owner
and its complete unmasked proof. Existing probe jobs were not repeated.

`installed-native/compile.json` records the native compilation of the installed
owner. `installed-native/func_00365f00-proof.json` contains the unmasked retail
proof; `installed-native/completed.json` includes sibling/data preservation and
the official verifier result. The owner gate supplies that authenticated current
native object to `tools/verify.py` for its official scoring; it does not replace
the verifier's comparison logic. `installed-native/frozen.json` binds the final
source, object and receipt.

| Frozen artifact | SHA-256 |
|---|---|
| `src/shdMisc.c` | `90cc24cd6410be58f6fe0463157009dd42f0c7720e66c3260e803984ab1c87cb` |
| `installed-native/owner.o` | `74e6c2310d912c43f9088258df1b905a6f624c6995406437c5e56e86e54a1ab7` |
| `installed-native/completed.json` | `af427eab80e1a10c8e3f5e8799d46ce3dbb1ea20c54fdfecfb316ab63924a79d` |
| Unchanged `include/shd_misc_internal.h` | `20000d7b758fbfa8faf32e9c81f5c57ee72fe53fb008aacc484a2db6ad52ac37` |
| Resolved executable target | `fb66e9a49a32d2e38311aa0c48a8f072a0c7d7e66dd3494d9e27461de6de2092` |

## Retained semantic checks

The authenticated `semantic-result.json` records 262,144 count/assertion cases
and 38,400 vertex/callback cases passing under Wasm32 undefined-behavior,
float-conversion and float-division traps. The installed source is byte-for-byte
identical to the source bound by those receipts; the completed tests were reused.

The count checks cover every low halfword with four upper halves. The draw
checks cover valid counts 1..100, packed colors, modes and callback mutation
patterns, including full-width angle division, low-halfword submission count,
depth sampling, replacement of the draw callback during state setup and
preservation of callback changes to the render flags. Only retail-written
vertex fields are read. Trigonometric and renderer boundaries are deterministic
mocks, so these receipts do not establish PS2 presentation or trig accuracy.

The outline candidate remains in scratch. Neither `func_00365ac0` nor the
`func_00364320` declaration/body was changed by this recovery.
