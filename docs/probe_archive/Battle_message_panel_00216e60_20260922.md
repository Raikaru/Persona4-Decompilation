# Battle message panel `00216e60` — 22 September 2026

`func_00216e60` is recovered as C: **4856 bytes**, **103
resolved relocations**, and **eight zero tail bytes** match its entire
4864-byte retail window. Together with `00210c70`, the owner is now
**105 MATCH / 3 ASM**.

## Recovered behavior and source contracts

State 1 initializes the text width, positioning, and flags, then falls through
to state 2 in the same update. Permanent messages and unexpired timed messages
use the same rendering path. Font width is stored whole; signed `/16` and `/2`
expressions supply the two centering conversions.

The background is an actual four-word rectangle plus four byte colors. Height
is set before use. Its first and second rounded integer Y positions are saved
as floats, then used to derive the middle rectangle. This fixes an uninitialized
height read and incorrect unrounded arithmetic in the old guarded draft.

The attack, defense, and speed selectors are signed bytes, their RGB channels
are independent unsigned-byte locals, and all of those objects belong to the
status-rendering block. Separate text-width and row-color lifetimes recover
the complete saved-register layout and naturally produce the retail 0x140
stack frame; no placeholder arrays or padding objects remain.

The flag test uses explicit branches for the all-attack state. The animation
uses the preincremented unsigned halfword. A distinct status X origin, scalar
multiply/add boundary for the sliding prompt, and the original pulse formula
preserve the retail floating-point operations. Both prompt phases clamp their
finite integer-derived progress before evaluating `2*t - t*t`. Prompt drawing
and input activation retain their independent completion checks.

Temporary rendering scopes retain the callback table's **address**, then reload
the current callback on each use. The access uses the already established
`BtlShuffleRenderStateSet` signature from `rw/plcore/badevice.h` and
`btl_shuffle_draw_internal.h`: Boolean return, `RwRenderState`, and `void *`.
Every declaration and call in the owner agrees; no RenderWare implementation
is changed. No volatile state or new optimization pragma is required.

The actual font, rectangle, and message providers determine the corrected
declarations and call arguments. The two prompt labels are distinct existing
globals. The input halfword uses the established absolute-array declaration,
matching the HI16/LO16 loads instead of incorrectly claiming GP storage.

## Evidence and validation

The retail listing and both IDA/Ghidra references were inspected alongside
`src/promoted/code1_0045.c`, `src/frFont.c`, `src/frFontEx.c`,
`src/itfMesManager.c`, `src/Main/Battle/Data/datCalc.c`, and actual sprite/task
providers. Reference hashes are bound in the individual scratch receipts.

Native compiler `mwcps2-3.0.1b210-060308` uses the configured `-O2 -Iinclude`
profile. Its SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The staged header is byte-identical to the header used for compilation.

All **108** owner functions pass full unmasked instruction, relocation, owned
table, and alignment-tail proof. Both recovered functions match retail. The
other **106** functions preserve their prior bytes and canonical relocations;
all allocated data and its relocations are identical. The cursor migration
retains the independently verified four-function proof from `ready-v1`, with
identical source/header/object hashes. The official verifier reports
**105 MATCH / 3 ASM** and **3 MATCH / 1 ASM**, respectively.

| Artifact | SHA-256 |
| --- | --- |
| `src/promoted/code1_0021.c` | `d7e3dae6801f4c808e06f3a89ba52321672059995b3ccba7a277d422eb0a914e` |
| `include/btl_panel_internal.h` | `209fa06aee1d948fa055cc1d3aeb06e6213b7515210c6d871e890f25d14042da` |
| `src/Battle/btlPanelCursor.c` | `02ec7a17b150ceae527e700ed24eb63f95807e49df90329199b6dafa4af1f477` |
| Native owner object | `ae09566353e0899e7f04ebbb980b3f31739cbf38f7bc20f14a7a1501d13a8d9b` |
| Resolved message body | `e10c13158438f993669e00eef16a9a621fea62b48ec531bd8f37e906c89a9726` |

The complete combined patch is
`build/finish-first-party-20260922/battle-ui-followup-04/ready-v2/change-with-evidence.patch`.
It supersedes the earlier `ready-v1` patch. Apply only one complete patch.
Source, native compiler receipts, per-function unmasked proofs, sibling/data
comparisons, official verification, and the patch dry run are preserved in
`build/finish-first-party-20260922/battle-ui-followup-04/ready-v2/`.

`00215c10` and `002161d0` were already exact in checkpoint 6514 and were
re-proved before this work. Remaining ASM in this owner is `00212270`,
`002142b0`, and `0021be80`. Production files remain untouched by this worker;
the prime owns full-project linking, integration, rebasing, and publication.
