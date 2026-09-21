# Fcl grid fade 003212e0: native color and alpha closure

Recovered and integrated on 2026-09-21 in the dirty
`build/first-party-publish-latest` worktree based at
`188437938339ae6f47b39445e5c4f2b59a211dff`. Existing work was preserved.

`func_003212e0` now compiles as ordinary C using its configured owner compiler.
The emitted 1,472 bytes fill the entire retail window. All 35 relocations are
resolved and compared without masks. There is no owned data and no suffix.
The owner advances from 47 MATCH / 23 ASM to **48 MATCH / 22 ASM**.

| Artifact | SHA-256 |
| --- | --- |
| Current `src/Event/Fcl/y_fclCombineDraw.c` | `4b187fa30c4aba1fbb8ff239cda1bb8876693042c4b4a158a59adcab551ed932` |
| Configured whole-owner `stage-final/proof/y_fclCombineDraw/owner.o` | `7b851fe5dc5ecd6704031c7124f7c62541e071a0fc2df5b5923a8f1b7b4f2290` |
| Raw 003212e0 function bytes | `89d65de6fb31d14152a46b53955945a1082fba179ed4443b0e3f80dd8a509c71` |
| Resolved 003212e0 bytes, equal to retail | `999b514a4ab6abf615af10291bfe2068d4adfc5c83d0a769d13db7f1195bbd93` |

Paths beginning with `stage-final` in this note are relative to
`build/continuation-20260921/fcl-worker3/closure-003212e0/`.

## Contracts and storage

The constructor at 002b2a60 returns the native four-byte `FclDrawColor` value.
Its caller-provided aggregate result reproduces the retail output pointer.
The shared `include/fcl_color.h` defines the type and constructor once. Initial
fade colors are constructed and copied through `fclConstructColor`; subsequent
recoloring assigns native return values directly. Existing guarded byte-buffer
callers use `fclWriteColorBytes`, which writes all four channels through character
access. The constructor provider remains byte-for-byte unchanged.

The first alpha value consumed by 002b82d0 is an unsigned byte. The 002b6a40,
002b6a70, 002e0660 and 0033d4b0 forwarding contracts use the same first-alpha
type. Provider and forwarding function bytes and relocations remain unchanged.
The recovered grid fade also keeps actual pointer spills, signed-short row
normalization, lookup ordering and the separate initial color results.

Three Cmb callers initially regressed only in frame and color stack offsets
after switching to independent native color results. Their position fields
were stored as `s64` despite being constructed and consumed as two floats.
Replacing those fields and the position union with `CmbVec2f` removes incidental
eight-byte alignment. The local position-writer declaration now agrees with
the actual `func_002b2970(u8 *, f32, f32)` provider. No padding, fake data or
compiler forcing was added. All 35 emitted Cmb owner functions and all allocated
data are unchanged; the five affected large callers also pass full unmasked
retail proof.

Two pre-existing guarded combine callers omitted the task argument and declared
only two parameters for 003212e0. Ghidra and the retail call sites establish
`(task, 0x27, 0)` in 002ed430 and `(task, 0x7b, 0)` in 00304580. These calls now
pass `arg0`, and `include/fcl_combine_internal.h` supplies the three-parameter
declaration. Retail callsite evidence is retained in
`build/continuation-20260921/fcl-worker3/resume-references/fade-callers.json`.

## Whole-owner and source closure

The change covers these twelve owners:

| Owner | Current result | Unchanged siblings |
| --- | --- | ---: |
| `src/Event/Fcl/y_fclCombine.c` | 26 MATCH / 15 ASM | 41 |
| `src/Event/Fcl/y_fclCombineDraw.c` | 48 MATCH / 22 ASM | 69 |
| `src/Event/Fcl/y_fclShopDraw.c` | 26 MATCH / 12 ASM | 38 |
| `src/Event/Fcl/y_fclModel.c` | 4 MATCH / 2 ASM | 6 |
| `src/Event/Fcl/y_fclItemShopDraw.c` | 7 MATCH / 2 ASM | 9 |
| `src/promoted/code1_002b.c` | 72 MATCH / 3 ASM | 75 |
| `src/promoted/code1_002e.c` | 40 MATCH | 40 |
| `src/promoted/code1_0033.c` | 38 MATCH / 1 ASM | 39 |
| `src/promoted/y_CmbCardEff.c` | 31 MATCH / 4 ASM | 35 |
| `src/promoted/y_draw.c` | 54 MATCH / 4 ASM | 58 |
| `src/promoted/y_smap.c` | 28 MATCH / 8 ASM | 36 |
| `src/promoted/y_fclCmbBall.c` | 5 MATCH / 1 ASM | 6 |

The shared-header consumer `src/promoted/code1_0034.c` was separately compiled
before and after: 28 MATCH, all 28 functions and allocated data unchanged.
It required no source edit. In total the thirteen checked owners retain **480
sibling functions**, including their exact relocation records. All allocated
data remains unchanged.

The source audit checks all **782 constructor call sites**, including guarded
bodies: each channel expression retains the same token sequence and call order.
The existing placement calls retain their argument expressions, and every other
assembly guard is preserved. All current changed sources are UTF-8 without a
BOM or replacement characters. Superseded floor and convention comments were
retained in `stage-final/historical-003212e0-floor.txt` and
`stage-final/historical-conventions.txt` before replacing them with current
contracts.

The previously accepted 00330060 was re-proved against this exact draw object:
1,872 code bytes and its entire 24-byte switch table remain exact, with all
code and table relocations resolved and no suffix.

## Reproduction and durable evidence

The authoritative current-input seal is
`stage-final/actual-current/seal.json`. It records every live source hash,
object path and hash, recursive project-header hashes, configured compiler
binary and flags, per-owner score and full target proofs. Recheck it with:

```powershell
python build/continuation-20260921/fcl-worker3/seal_live_fade.py
```

The patch tool removed one terminal blank line from `y_fclShopDraw.c`.
Consequently its final source was freshly compiled in
`stage-final/actual-current/proof/y_fclShopDraw/`, and compared with the staged
owner. This is the only staged/live text difference. Use the current seal,
not the staged shop source hash:

- Current shop source: `4278088e711e6004ccdfa3f47e07398d4524a83396d501dae0ecac3992184a28`.
- Current shop object: `6b681b4eac4f0078fcb4402cb5f467a02f1333fd08cf36ec7e0db509bff0e8d7`.

`stage-final/proof/` retains the twelve configured owner compiles, before/after
comparisons, official scores, and fifteen complete unmasked target/provider
proofs. `stage-final/source-audit.json` records the caller audit.
`stage-final/pre-integration-gate.json` verifies every live-before source hash
before the atomic patch. `stage-final/integration.patch` is the applied patch,
not a command to replay. Earlier failed or incomplete experiments remain in
their original directories.

All twelve changed owners and the three shared headers were released to prime
after the current seal passed. Validation here is limited to these thirteen
owners and their dependencies; prime owns combined integration and CI. No
commit, push, rebase or full-project check was performed by this worker.
