# First-party matching campaign, 2026-09-25/26: summary and handoff

## Baseline before recommended-function follow-through

- First-party functions: **6,674 of 6,861 MATCH (97.3%), 187 ASM** (was 6,617 / 244
  when the campaign started, and 6,582 / 279 at the start of the Fcl work).
- Every merge was checked against a whole-tree per-function status comparison
  (13,102 functions; no regressions), `verify.py` WRONG SYMBOL lines (none), and a
  full `tools/build.py` run (594 linked units, both retail SHA-1s OK).
- Lint rule H011 (declarations that disagree with the function's definition) was
  added mid-campaign. Tree-wide findings fell from 2,416 to 2,333 while matching,
  then to 2,307 after the model-contract cleanup and 2,303 after the subsequent
  contract-first recovery pass; lint errors stayed at 0.
- The contract-first pass reverified 40 owners, including all 33 consumers of
  `sdk_snd_internal.h`: **1,894 MATCH / 66 ASM**, with no mismatches or wrong
  relocations. Replacing those rows in the unchanged full-tree baseline gives
  **9,494 MATCH / 3,608 ASM** across 13,102 functions. The only status change is
  `002af3e0` from ASM to MATCH; this was not a fresh full-tree compiler sweep.
- The final link retains **594 source-built C objects plus 54 SDK objects**
  (648 translation units in the progress report). All 8,339 source-linked
  function ranges remain present, including `002af3e0`.
  - Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`.
  - SLUS_217.82 SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
  - Both hashes match retail. Registering the recovered map data symbol fixed
    the temporary drop to 593 C objects without relaxing the 594-object floor.

## Recommended-function recoveries

Seven of the nine follow-through targets are active C, not guarded floors:

| Function | Owner | C bytes / retail window |
| --- | --- | ---: |
| `0045b7c0` | `sdkSndcom.c` | 2408 / 2416 |
| `00475cd0` | `Graphics/Model/mdlManager.c` | 3992 / 4000 |
| `0048a980` | `promoted/code1_0048.c` | 584 / 592 |
| `001dd920` | `Battle/btlAICommand.c` | 1748 / 1760 |
| `002f0f00` | `Event/Fcl/y_fclCombine.c` | 24048 / 24048 |
| `002fbea0` | `Event/Fcl/y_fclCombine.c` | 26320 / 26320 |
| `00304580` | `Event/Fcl/y_fclCombine.c` | 18232 / 18240 |

Each has zero normalized instruction differences; shorter bodies have only zero
alignment padding left in the retail window. The joint Fcl owner has 39 MATCH /
2 ASM, retaining all 36 earlier matches. Combining its check with the disjoint
numeric/renderer and supporting-provider checks gives 951 MATCH / 38 ASM across
989 functions in 21 owners, with no mismatches.

Combining the whole-tree verification with the subsequent complete Fcl-owner
check gives 9,501 MATCH / 3,601 ASM across 13,102 functions, with no mismatches.
First-party coverage is 6,681 / 6,861 MATCH (97.4%), with 180 ASM remaining.

The full link retains 594 source C objects, 54 SDK objects, all seven recovered
functions, and both retail hashes listed above. This also checks the new Fcl
case bindings and GP references: the early `002f0f00` scale load uses
`iGpffff8218`, not the differently addressed `iGpffff8504`.

Supporting contracts now use signed-16 resistance selectors, numeric dialog
slots rather than pointer-shaped IDs, native position/color values, and signed
byte renderer/persona selectors. `002badc0` is `s32(s8, s32)` throughout its
provider and callers; the shop wrappers retain their byte handle and signed-16
message view. The balance getter explicitly returns its underlying `u32`.
The full Fcl owner also compiles with `NON_MATCHING` defined. Guarded callers
use the actual persona-progress pointer types and variadic `sprintf`; experience
writes retain byte offset `+8` after the list accessor's return becomes `u8 *`.
The numeric/string format symbols are explicitly bound to retail `%d` / `%s`.

Still open: the best `001a43a0` candidate has 15 register-only differences in
its shuffle/output phase; `00485630` needs the original supported quadword-copy
primitive or ABI evidence. Neither is counted as a C recovery.

## Source standard applied

The accepted source had to be plausibly what the original developers wrote:

- one signature per function, agreeing with its definition (H011); callee
  definitions were corrected when evidence showed their real type (a callee that
  masks or extends its own parameter on entry was the usual tell);
- no contradictory block-scope externs, no undefined-behaviour tricks, no inline
  asm; optimisation pragmas only when measured and commented;
- functions that matched only by breaking these were parked behind
  `#ifdef NON_MATCHING` or banked here with their blockers.

## Contract findings worth keeping

- `func_002b2970` (and `func_002b29a0`, `func_002b29e0`) are plain C struct returns;
  the synthetic stack-layout structs that imitated their temporaries are gone. A
  C++ constructor was ruled out (FclDraw_002b2970_signature_20260926.md).
- The persona/class id contract is u16 (`func_00310a10`, `func_00109280`,
  `func_00109220`, `func_00105f50`); see FclCombine_002ed430_recovery_20260925.md.
- Model IDs are u16 and model types are u32 throughout mdlManager's lookup,
  constructor, attachment and callback path. `func_001b1d70` is now MATCH
  under the canonical `func_00477c40(u32, u16, u32)`, with no new exception.
  The existing Kosaka `func_00478140` type-only exception is retained.
  See `Prototype_mismatch_00477c40_00478140_20260926.md` for the contracts,
  exact linked hashes, and the three pre-existing guarded-body compile failures.
- The contract-first follow-up recovers `func_002af3e0` (1932B/1936B).
  Signed symbol-state setters, the drawing helper's pointer/four-floats/three-
  integers parameter order, and natural vector/counter lifetimes close the
  target. Its new `D_00764654` reference is registered for C-link eligibility.
  See `Campaign_g0r4_20260926.md`.
- Battle task constructors `001fa320`/`002027e0` explicitly return their task
  pointers; sound `0045c210` uses three pointer/unsigned-size payload pairs;
  model `0047dd40` accepts the owning-model argument supplied by all three
  retail callers. Each provider remains exact. The sound and model bodies above
  are now active C; `001a43a0` remains guarded, without a prototype exception or
  an artificial side effect to conceal its remaining register differences.
- gp-relative float "globals" are usually pooled float literals; write the literal.
- A `verify.py` MATCH does not prove a switch's case bindings or that gp symbol
  names are registered — only the full build does. `[ifsu]Gp` names encode the gp
  offset as 16-bit two's complement.

## Open decisions

- `func_00100008` is the crt0 `_start` entry, not C; it should not count as a
  first-party C target.
- `func_00225ec0` reads an uninitialised stack slot in retail; any matching C
  would rely on undefined behaviour.
- `src/Event/Fcl/y_fclCombineDraw.c.bak` is a stale tracked backup with outdated
  declarations.

## Where the remaining 187 stand

Per-group notes list every attempt with its best measure:
`Campaign_g0r4_20260926.md`, `Campaign_g1r2/g1r3_20260926.md`,
`Campaign_g2r2/g2r3_20260926.md`, `Campaign_g3_unmatched_20260926.md`,
`Campaign_g4_unmatched_20260926.md`, plus per-function notes and `*_body*.c`
drafts. Roughly: near-misses (1-60 words) blocked by one register-allocation
choice that permuters and declaration-order searches did not move; far-off drafts
that need fresh rewrites from the retail listing (the approach that produced most
later matches); and a handful that need VU0 instructions or depend on the open
decisions above. The 15 remaining Fcl functions are mostly large register-order
floors documented in their FclCombine_*/FclDraw_*/ShopDraw_* notes.
