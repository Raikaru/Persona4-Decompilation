# Exact first rank-up palette: func_002561f0

The completed native recovery replaces the first rank-up palette's assembly
fallback with C. It emits **612 executable bytes in the 624-byte retail window**,
with all **three code relocations applied** and **twelve verified zero alignment
bytes**. The integrated owner now reports **17 MATCH / 9 ASM** across 26 functions.

## Shared implementation and actual arguments

The entire retail windows of `002561f0` and the already recovered `00256460`
differ in one instruction word: offset `0x24`, the low half of the source-table
address. The first palette reads `D_00636310`; the second reads `D_00636390`.
Both use sixteen eight-byte position rows and an eighty-byte color allocation.
The implementation is consequently the same already verified point/color
algorithm with a different table. `RankUpColor` is shared by the two definitions.

The actual interface has seven integer arguments and five floating-point
arguments. The three callers in guarded `00257900` previously omitted the
second integer offset and shifted their float values. The retail calls at
`002581EC`, `00258580`, and `00258838` supply the following tail:

```c
saveState = 1;
offsetX = 0;
offsetY = 0;
translateX = 0.0f;
translateY = 40.0f;
depth = 0.0f;
scaleX = 1.0f;
scaleY = 1.0f;
```

All three C call sites now supply those arguments. Their original RGB and
alpha expressions remain in order. The caller's capped ramp, constant plateau,
and bounded fade give alpha values from zero through 153; the retained
`255.0f * alpha / 255.0f` conversion is defined in that observed domain. This
does not assert a contract for arbitrary full-range signed alpha values.

## Storage and native proof

`PrimPointRow` contains the two copied words and their actual `PrimFloat2`
representation. Copying uses the declared `const CopyPair[16]` source; translation
uses the union's point member. All sixteen submitted positions and all four
color fields of the sixteen submitted records are initialized before drawing.
The four remaining color records are capacity, not extra vertices. The immediate
draw provider consumes the stack buffers synchronously. No new provider or
shared-header change was required for this recovery.

All 25 neighboring functions retain their complete code and canonical
relocations, including the previously recovered second palette. All existing
allocated data is unchanged. The separate 128-byte source table is checked to
contain sixteen pairs of finite coordinates. No compiler-owned data is added.

The only code relocations are the HI16/LO16 pair at offsets `0x20/0x24` targeting
`D_00636310` and the call at `0x234` targeting `func_0045e6a0`.

Separate before/after builds with `00257900` enabled retain all 265 call
destinations in their original order and all 24 other functions. Its draft
changes from 14,264 to 14,248 bytes because the three actual-argument corrections
change call setup. It remains an assembly fallback and is not counted as a C
recovery. A final build of that guarded caller from the installed source is
identical to the corrected proposal.

## Reproduction and identities

All measurements use the configured MWCCPS2 b210 `-O2 -Iinclude` profile in
the complete `src/cmmRankUp.c` translation unit. The inherited, scoped
`opt_loop_invariants on` reproduces the retail color-division ordering. Scoped
lint reports no errors and two reviewed optimization-provenance advisories,
one for each palette; whitespace checks pass.

Artifacts are under `build/first-party-continue-live/rankup/`. `sibling.py`
retains the original proposal and before/after caller checks. `seal.py` compiles
the installed source and feeds that authenticated object to the official
verifier, then applies every relocation without masking. Its completed result
is `integrated/proof.json`, with `official.json`, `official-completed.json`,
`compile.json`, the two palette proofs, caller receipt, and `table.json`.
The source and dependency hashes must agree before a completed result is reused.

| Artifact | SHA-256 |
| --- | --- |
| Integrated owner | `bd4420d04bb0aab6e61d7e2e0634da28748caa905d54863e9d774759ddf098cc` |
| Integrated object | `ac97ac1435d6098fcf916540d5c3aad98ec33954daf06057520c8d8df5324d17` |
| Fully resolved first-palette instructions | `817c626420161bda8969382810fad6dd9eea54e0262274f8621be175dec60f6b` |
| Source position table | `83e5a6240fbc081790d4404a12918c22d00012209f8268a931f95a42e004a023` |

Independent source, caller-domain, table and retained-object review is in
`build/first-party-continue-live/audit/RANKUP_REVIEW.md` and its JSON evidence.
Earlier unsuccessful source forms remain historical evidence; their register
or stack-gap explanations do not describe the recovered implementation.
