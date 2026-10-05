# btlShuffle guarded improvements, 2026-10-05

Both remaining functions in `src/promoted/btlShuffle.c` have improved guarded
C. Neither is an exact match, so both retain `NON_MATCHING` and `INCLUDE_ASM`.
The owner still has **24 C matches and two assembly fallbacks**. All 26
functions are attributed to `main` by `verify.code_origin`.

| Function | Fresh starting words | Installed fully resolved words | Code/window bytes |
| --- | ---: | ---: | ---: |
| `func_0036ee60` | 97 | **82** | 1456/1456 |
| `func_0036f880` | 41 | **14** | 852/864 |

The skill candidate has 12 zero alignment bytes after its 852-byte body.
The draw candidate fills its complete retail window. No padding or artificial
state was added, and no assembly fallback was promoted.

## Skill replacement: `0036f880`

The inventory capacity is now retained as `u16` with scoped
`opt_loop_invariants on`. The provider `func_0010b5b0`, in
`src/Main/Battle/Data/datPersona.c`, returns 6, 8, 10, or 12. The twelve-pointer
inventory list retains its original extent. The type and pragma together
restore retail's capacity in `$s1` and signed slot value in `$s0`; either
change alone leaves that seven-word register swap.

The eight candidate slots are four-byte unions exposing their two `u16`
skills. They retain the original size and alignment while making both
halfword writes explicit. The selected replacement and original skill are
read through a byte-offset field accessor. The two addresses remain distinct
in the generated code, restoring the missing instruction and the 852-byte
body length.

The remaining 14 words consist of eight reverse-search register differences
(`$t3` versus `$t4`) and six final candidate-address instructions. The latter
still compute equivalent in-bounds addresses through a different sequence;
they are not an exact instruction match.

The two inventory declarations now agree with their providers:

```c
s32 func_0010abd0(s16 slot);
u16 *func_0010ace0(s16 slot);
```

The three consumers in this owner explicitly convert the returned record to
their existing byte-pointer view. The matching siblings using these
declarations keep their code and relocation targets unchanged. No provider
or shared header was edited. `datPersonaGetSkills(int)` and
`func_0010cd70(u8 *, s16, u16)` keep their actual provider contracts.

The two directional table searches, zero terminators, eight-skill membership
tests, random selection calls, and output stores are unchanged. A candidate
pair is read only after it has been written and the candidate count is
nonzero. The replacement skill is read before the original skill, as in retail.

## Card candidate drawing: `0036ee60`

The database pointer is read before forming the 14-byte record offset. The
level-range predicate is expressed as two rejection checks under
`mlvl <= lvl`, retaining the original integer inclusion set. There is no
floating-point predicate or NaN behavior involved in this rewrite.

The final draw loop has its own `drawIndex`, separate from the database scan.
When consuming the inventory-owned bucket, it captures the current index,
increments the cursor, and then loads the selected entry. This restores the
retail update-before-load ordering. An experimental inline pop helper was
removed from the delivered source because the same score is obtained without it.

All three 256-entry short arrays, their declaration order, random-swap calls,
output selection order, and return conditions remain. The existing zero-rate
branch still retains the retail's skipped higher-level-bucket code. The
signature preserves the unused third `s32` argument passed by the battle-end
caller; it was not narrowed to the obsolete two-argument archive signature.

The residual includes register assignments, comparison destinations, and
the draw-loop spill: retail spills `cIdx` as a halfword at `sp+0xE0`, whereas
the installed candidate retains it in a register and spills `nDraw` at
`sp+0xEC`. The source comment no longer claims that the already-reproduced
quadword spills or skipped bucket block are unreachable from C. Earlier
experiments remain in `BtlShuffle_0036EE60_body.c` and
`Campaign_g2r2_20260926.md` / `Campaign_g2r3_20260926.md`.

## Whole-owner proof and installation

The pinned Python environment and native MWCCPS2 3.0.1 b210 compiled the
whole owner for every measured candidate. The initial production object was
recompiled before installation and was byte-identical to the initial baseline.
The final combined candidate was also compared with each separately measured
target object; both functions retained their exact candidate code and
canonical relocation records.

The receipt resolves **17 draw-function relocations and 11 skill-function
relocations**. Every relocation's target bits equal retail at the corresponding
instruction. The reported 82 and 14 counts include fully resolved words,
rather than relying on relocation masking. All 24 other functions preserve
their raw code, sizes, and canonical relocation targets. All 26 production
functions remain unchanged with the guarded proposals installed.

The owner's single allocated readonly section is 40 bytes at `0x00752920`.
Its ten pointer relocations resolve to the original `func_0036e140` case
targets, and all 40 resolved bytes equal retail. Neither changed function
introduces local data. The proof distinguishes actual object sections rather
than merging repeated section names.

After prime authorized integration, `install_shuffle_guards.py` authenticated
the owner and include closure and applied the reviewed guarded patch. The
installed production object is byte-identical to the sealed guarded proposal.
Enabling both installed C bodies in a complete-owner scratch compile likewise
reproduces the sealed active candidate object exactly. Scoped production
verification remains **24 MATCH / 2 ASM**.

Installed source SHA-256:
`2f6bff411f27df73c5f6e5f129137748046e6b9b655c96949d432dec6c86cc11`.

## Receipts and reproducibility

The two installed bodies and full proof are retained beside this note as
`BtlShuffle_worker8_20261005_0036ee60_body.c`,
`BtlShuffle_worker8_20261005_0036f880_body.c`, and
`BtlShuffle_worker8_20261005_receipt.json`.

The initial proof package retains 118 whole-owner probe records. Eleven
additional probes were run against the installed owner after prime requested
continued investigation. The receipt keeps their source hashes and scores
separately under `followup_probes`. The installation scripts actually run were:

```powershell
.\build\venv\Scripts\python.exe build/worker-8/prepare_shuffle_delivery.py
.\build\venv\Scripts\python.exe build/worker-8/seal_shuffle.py
.\build\venv\Scripts\python.exe build/worker-8/install_shuffle_guards.py
```

`build/worker-8/shuffle/production-before.json` is the initial scoped report;
`build/worker-8/shuffle/installed/production.json` is the installed report.
The receipt binds the source/include closure, compiler, reports, code,
relocations, and data to their hashes. Installation scripts preserve the
pre-edit hash gate and are not intended to reapply an already installed patch.

The main negative results cover complete inventory-collection and membership
helpers, distinct cursor storage, equivalent pair field views, and bounded
compiler-option checks. These did not close the residuals above. The results
are measured frontiers, not a claim that exact C is impossible.

The eleven subsequent probes reconfirmed the installed 14/82 controls. Typed
reverse-table records retain 14 words; halfword-array candidate storage gives
34 words, and staged halfword addresses give 40. Extracting the complete
output-selection phase into an inline helper gives 86 words for either
natural argument grouping. Extracting the randomization phase gives 150
words and exceeds the window. None changed the installed sources or their
sealed objects.

The installed owner also passed `tools/decomp_lint.py` with **zero errors and
11 warnings**. All warnings concern pre-existing declarations outside these
target changes. `git diff --check` passed for both modified owners and notes.
The lint log and its hash are recorded in the installation receipt.

No whole-project build, global verification, C-link eligibility, or rebuilt
retail hash is claimed here. Prime owns that integration validation. The
positive instruction residuals continue to require the assembly fallbacks.
