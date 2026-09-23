# Battle damage panel `00210c70` — 22 September 2026

`func_00210c70` is recovered as C. Its 1604-byte body, 23
resolved relocations, and twelve zero alignment bytes match the complete
1616-byte retail window. The native owner has **104 MATCH / 4 ASM**.

## Source mechanisms

The damage packet is a real 20-byte structure: vertical offset at `0x00`,
byte alpha at `0x04`, gauge-enable word at `0x08`, and gauge coordinates at
`0x0c`/`0x10`. `func_0020e690`, `func_0020ea60`, and `func_0020ef10` write
these fields. The two projected screen coordinates remain a separate object.
The native compiler supplies the observed gap between these objects naturally.

HP and SP use separate amount, color, and background locals within their row
blocks. This fixes all the saved-register differences in the prior 58-word
floor. Sharing those temporaries across both rows distorted their lifetimes.

`flags &= ~1U` restores the retail expiration-path reload. The old explicit
load/AND/store spelling propagated the earlier read and removed one load.
Neither volatile state nor an optimization pragma is needed.

The remaining two words were the gauge call's mixed argument order. Retail
loads X before color and fraction. The provider, shared declaration, damage
caller, and all four cursor source calls now use
`(task, unit, x, y, color, fraction)`. EE integer and floating-point arguments
retain their actual registers. The provider's emitted bytes are unchanged.
The cursor's three compiled C calls and its ASM fallback also remain exact.

The body retains one initial rate query, the actual GP-relative scale globals,
the scalar multiply/add boundaries, and both byte-alpha conversions. There
are no new machine-code blocks, compiler switches, invented storage, or
synthetic helper effects.

## Native proof

Compiler: `mwcps2-3.0.1b210-060308`, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Both owners use their configured `-O2 -Iinclude` profiles. The staged shared
header was supplied through mwccgap's normal candidate-source directory;
its bytes equal the proposed header exactly.

All **108** functions in `code1_0021.c`, including the four unchanged ASM
fallbacks, pass full unmasked relocation and owned-table proof. All **107**
siblings retain their previous function bytes and canonical relocations.
Allocated data and its relocations are identical. All **4** cursor functions
pass the same unmasked proof and retain their bytes, relocations, and data.

`tools/verify.py` reused only the hash-bound native objects produced from the
exact candidate source and header. Its results are **104 MATCH / 4 ASM** for
the owner and **3 MATCH / 1 ASM** for the cursor. Source and input hashes were
rechecked against checkpoint 6514 after verification.

| Artifact | SHA-256 |
| --- | --- |
| `src/promoted/code1_0021.c` | `9ddb42a105fd29a5803746ac772c706aa4e12b52da3802d3783e750bb5c7fd4c` |
| `src/Battle/btlPanelCursor.c` | `02ec7a17b150ceae527e700ed24eb63f95807e49df90329199b6dafa4af1f477` |
| `include/btl_panel_internal.h` | `209fa06aee1d948fa055cc1d3aeb06e6213b7515210c6d871e890f25d14042da` |
| Native `code1_0021` object | `e05d3cbc49c5b317ed3b7b415c86eb6eb807fac657bf31b6c782fd727b423e08` |
| Native cursor object | `8fcbb69de9a3e99af5be1fc14d0b72fa2a09a7b15629049cb48d8f6b55b0bf80` |
| Target resolved body | `75e75f2403b2fbcf1d9e8b079776051e65823b68b484e90aa6955856c7e123ee` |

Complete source/header bindings, compiler receipts, individual relocation
records, table proofs, sibling comparisons, allocated-data records, and the
official reports are in `build/finish-first-party-20260922/battle-ui-followup-04/ready-v1/`.

## Already completed row functions

`func_00215c10` and `func_002161d0` were already C in checkpoint 6514. Their
current source and object were authenticated, then re-proved unmasked:
1464/1472 bytes with 11 relocations, and 1564/1568 with 10 relocations.
See `build/finish-first-party-20260922/battle-ui-followup-04/existing-pair-proof/` and
`docs/probe_archive/Battle_panel_card_rows_20260922.md`.

## Scope

The remaining owner fallbacks are `00212270`, `002142b0`, `00216e60`, and
`0021be80`. This recovery does not claim them as C. The patch and receipts were
prepared in scratch; source integration, full-project linking, rebasing, and
publication belong to the prime.
