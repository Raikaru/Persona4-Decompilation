# First-party matching campaign, 2026-09-25/26: summary and handoff

## Result

- First-party functions: **6,671 of 6,861 MATCH (97.2%), 190 ASM** (was 6,617 / 244
  when the campaign started, and 6,582 / 279 at the start of the Fcl work).
- Every merge was checked against a whole-tree per-function status comparison
  (13,102 functions; no regressions), `verify.py` WRONG SYMBOL lines (none), and a
  full `tools/build.py` run (594 linked units, both retail SHA-1s OK).
- Lint rule H011 (declarations that disagree with the function's definition) was
  added mid-campaign. Tree-wide findings fell from 2,416 to 2,333 while matching;
  lint errors stayed at 0.

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
- gp-relative float "globals" are usually pooled float literals; write the literal.
- A `verify.py` MATCH does not prove a switch's case bindings or that gp symbol
  names are registered — only the full build does. `[ifsu]Gp` names encode the gp
  offset as 16-bit two's complement.

## Open decisions

- `func_00478140`: two byte-exact drafts (`func_00162680`, `func_0015e960`) need
  u16 parameters, but its definition and other matched callers only match with
  u32. Needs one cross-owner signature decision.
- `func_00477c40`: `func_001b1d70` is 1 word off and needs a u16 prototype that
  seven matched callers in other units contradict — the original units appear to
  have disagreed. Kept as ASM under the one-signature rule.
- `func_00100008` is the crt0 `_start` entry, not C; it should not count as a
  first-party C target.
- `func_00225ec0` reads an uninitialised stack slot in retail; any matching C
  would rely on undefined behaviour.
- `src/Event/Fcl/y_fclCombineDraw.c.bak` is a stale tracked backup with outdated
  declarations.

## Where the remaining 190 stand

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
