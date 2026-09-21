# Fcl draw transition 002b83e0 continuation — worker 2, 2026-09-21

## Result

`func_002b83e0` is exact in the final current-input closure: **1468 / 1472 bytes,
eight resolved relocations, four verified zero omitted bytes, no owned data**.
All 57 existing `y_draw` sibling functions are unchanged. All eleven closure owners
preserve their existing code/relocations and data; the official verifier reports
**366 MATCH / 70 ASM with no other statuses**. The new transition accounts for the
one additional C match. All 70 CombineDraw functions are unchanged, including
`003212e0`, `00330060`, and the two transition call sites in `0032fbc0`.

This is a scratch-only integration proposal. The prime owns production integration
and the subsequent complete first-party gate. No production source/header/config/tool
was edited by this worker. The latest Scene/effect changes in Cmb are preserved:
source SHA `6684e2be09a12856f1f3b48ecaf2e93df997e9722e461f0b419d0f986eec6757`.

## Exact package

The root is `build/next-wave-20260921/fcl/final-002b83e0/`.

- `002b83e0-scoped-position.patch` changes exactly five files: `y_draw.c`,
  `y_fclCombineDraw.c`, guarded call spellings in `y_fclCombine.c` and `code1_002b.c`,
  and `include/fcl_draw_task.h`.
- `release-manifest.json` seals the patch, final object receipts, current before
  inputs, recursive header dependencies, compiler/profile/tool hashes and all results.
- `before/` and `after/` are frozen whole-owner source/header inputs; `proof/` holds
  the final objects, compile logs, unchanged-function/data comparisons and official
  scores. Final owner profiles use logical production paths, not scratch filenames.
- `caller-audit.json` checks all 33 source call sites. Both compiled calls
  retain all eleven other arguments; guarded drafts receive only the typed conversion.
- `position-layout-proof.json` records the actual element geometry and checked
  retail unaligned load words. The proof is independent of the chosen C spelling.

The target raw SHA is `696115ba30c54e538428d2ad6d5dbd3f1f6a4582c9fa387bc2cd0672939a0be4` and resolved SHA is
`1cbc39be82e0ee2ef138b4f90d4065d79e18a0dd2bd7f912ae1d05f6744b8356`. Its relocations comprise four calls to the unchanged
`func_002b2970` provider and four accesses to the existing scale global.

## Position and timing contracts

The element provider `0034ae50` returns `work + signed_slot * 0x200 + 0x104`.
The position used by `0032fbc0` is at element offset `0x28`, therefore at work
offset `slot * 0x200 + 0x12C`. This is a four-byte-aligned eight-byte pair. Retail
loads it with `ldr $5, 0x28($16)` at `0032fd90` and `ldl $5, 0x2f($16)` at `0032fd94`.
Those exact words are asserted in the resolved current caller proof.

`FclDrawPosition` expresses that packet with a scoped four-byte layout and native
`FclVec2`, integer, and existing-packet views. The existing global
`FclPackedPosition` retains its natural eight-byte alignment. The compiler accepted
negative-size assertions for the new size (8), its prefixed layout (12), and the
restored natural packet layout after `#pragma pop` (16). This uses the repository's
established `push` / `pack(4)` / `pop` pattern; no compiler-profile change is required.

The first compiled caller loads the real element packet directly. The second views
the existing, more strongly aligned stack packet through the new compatible-layout
union. Both compile identically to the existing caller. The constructor remains the
coherent `void func_002b2970(u8 *, f32, f32)` provider. Its source function, all 75
provider-owner functions, and data are unchanged; its caller declaration in `y_draw`
is corrected from the stale pointer-return spelling and the existing output call is
explicitly typed as bytes.

Transition duration and delay are signed words. Duration remains wide through the
signed divide by two for the reverse color delay. Each scale timing store receives
the original explicit halfword narrowing. The recovered reveal-scale read occurs
after its three preceding stores, and the outgoing/non-reverse scale-mode byte is
zero as in retail. The position work record contains only consumed start/end
snapshots and constructor results, with no padding-only or effect-only fields.

The creator allocates and clears `0x1810` bytes for twelve `0x200` records. For valid
slots 0 through 11, transition writes through element offset `0xA3` fit their record
(`0x104 + 0xA3 = 0x1A7 < 0x200`) and the allocation (last byte `0x17A7`). Arbitrary
out-of-range signed slots remain outside this proof; provider behavior is unchanged.

## Whole-owner verification

| Owner | Existing functions unchanged | Final MATCH | Final ASM |
| --- | ---: | ---: | ---: |
| `y_fclCombine.c` | 41 | 26 | 15 |
| `y_fclCombineDraw.c` | 70 | 48 | 22 |
| `y_fclItemShopDraw.c` | 9 | 7 | 2 |
| `y_fclShopDraw.c` | 38 | 26 | 12 |
| `code1_002b.c` | 75 | 72 | 3 |
| `code1_002e.c` | 40 | 40 | 0 |
| `code1_0034.c` | 28 | 28 | 0 |
| `y_CmbCardEff.c` | 35 | 31 | 4 |
| `y_draw.c` | 57 | 55 | 3 |
| `y_fclCmbBall.c` | 6 | 5 | 1 |
| `y_smap.c` | 36 | 28 | 8 |

The 435 unchanged existing functions include matching C and retained assembly.
Every data section and data relocation is unchanged. The final closure was compiled
once after source cleanup against current inputs, including the latest Cmb effect
header and direct-pointer calls. The official verifier then scored authenticated
objects without recompiling. Separate resolved proofs also cover `002b2970`,
`003212e0`, `00330060` and `0032fbc0`. No active compiler remains for this release.

## Reproduction and continuation

`finalize_scoped_transition.py` freezes/authenticates current inputs, compiles whole
owners using their configured profiles, proves preservation and scores the retained
objects. `release_scoped_transition.py` seals the final package. Existing receipts
must be checked before rerunning any compile; changed inputs require a new stage.

The previous global-native-constructor route remains archived under `closure/`.
It would regress one CombineDraw and five Cmb functions and is not part of this patch.
The final packet contract avoids that dependency migration. Failed factories, storage
layouts, and compiler-lifetime probes are retained as immutable evidence.

The original `003218a0` assignment was paused for this closure. It is not promoted
by this patch. Its saved best candidates remain non-exact; continue with the current
native-color/position-packet contracts and the exact `003212e0` source-lifetime pattern.
The constructor interface and unrelated global packet types should stay fixed.
