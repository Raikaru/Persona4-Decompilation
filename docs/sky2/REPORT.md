# RenderWare name transfer P4 <- NBA Ballers Phenom: same-toolchain structural diff

## 0. Verdict up front

Ballers beats Burnout decisively, and the reason is the compiler. Ballers'
1341 RenderWare compilation units all carry the producer string
`MW MIPS C Compiler` (Metrowerks — the same family as Persona 4's MWCCPS2
3.0.1 b119), confirmed with `build/rw_dwarf.py` and the `.comment` section
(`MW MIPS C Compiler (2.4.1.01)`). The 796 `gcc2_compiled` markers in the
image are elsewhere, not in RenderWare. So this is a same-toolchain
reference: same instruction selection, same register allocator, same idioms.
The differences left are RenderWare version and build flags, not codegen.

Measured against the same 392-pair ground truth (`docs/sky2/known_names.json`,
389 scorable):

| configuration | matches | recall | precision |
|---|---|---|---|
| ballers greedy, `--no-semantic` | 1974 | 246/389 = 0.632 | **221/246 = 0.898** |
| ballers greedy, semantics both indexed | 3165 | 336/389 = 0.864 | **297/336 = 0.884** |
| burnout greedy, `--no-semantic` | 1078 | 80/389 = 0.206 | 54/80 = 0.675 |
| burnout greedy, semantics both indexed | 1982 | 143/389 = 0.368 | 93/143 = 0.650 |

Driver block only (`asm/nonmatchings/rwcore_grouped`, 113 truth pairs):

| configuration | recall | precision |
|---|---|---|
| ballers greedy, `--no-semantic` | 74/113 = 0.655 | 72/74 = 0.973 |
| ballers greedy, semantics both indexed | 107/113 = 0.947 | 100/107 = 0.935 |
| burnout greedy, `--no-semantic` | 37/113 = 0.327 | 29/37 = 0.784 |
| burnout greedy, semantics both indexed | 62/113 = 0.549 | 45/62 = 0.726 |

The better anchor set helped by **+0.234 precision overall
(0.650 -> 0.884), +0.209 on the driver (0.726 -> 0.935), and recall more
than doubled (0.368 -> 0.864)**. The reachable ceiling explains half of it:
356 of 392 truth names exist in Ballers' symtab at all (353/389 scorable =
0.907) versus 212/389 = 0.545 for Burnout — and the matcher converts
336/353 = 0.952 of what is reachable. Same-toolchain structure does the rest:
sizes agree to the byte on most pairs (48/48, 164/164, 68/68, 112/112 are
typical), and whole bodies differ only in gp-relative offsets and callee
addresses (see hand-checks).

## 1. Toolchain (step 1)

- `romwright-cli` from `~/ventris/target/release/romwright-cli`. No
  `romwright` on `PATH`; every command ran with the release dir prepended.
- P4 target: `/var/tmp/ballersdiff/proj`, a file-level copy of the Burnout
  run's `/var/tmp/rwdiff/proj` (`sqlite3 backup`, verified afterwards:
  `p4 r5900:LE:32:default 14457 functions`, **13457 semantic signatures
  preserved** — no 50-minute P4 re-index needed). Import source
  `source/Persona4-Decompilation/orig/SLUS_217.82`, confirmed with
  `programs`: 1 program, `p4`.
- Ballers reference: `/home/raikaru/[PS2] NBA Ballers - Phenom (USA)
  [SLUS-21186] [2006-02-09]/SLUS_211.86` (48 658 476 bytes, ELF32 MIPS-III,
  `not stripped`: `.symtab` + `.strtab` + 35 MB `.debug`/`.line`) imported as
  program `ballers` into `/var/tmp/ballersdiff/ballproj`:
  `ballers r5900:LE:32:default 26630 functions revision 15`,
  **13527 symbols**, exit 0, backgrounded (a few minutes); switch-recovery
  worker warnings as in the Burnout run, benign.
- Compiler/version evidence (checked before importing, corrected the
  briefing's GCC claim independently): `.comment` = `MW MIPS C Compiler
  (2.4.1.01)`; strings carry
  `C:\mwy\BALLER~1\main\Libs\RW\Graphics\rwsdk\driver\sky2\basky.c` and
  siblings — the same `driver\sky2` family P4 links. `mipsel-linux-gnu-nm`
  finds 777 global `Rw/Rp/_rw/Rx/Rt` symbols plus the driver's freeform names
  (`Sky*`, `PS2All*`, `open2DVU1Pkt`, `addCopyVU1*`, `rwDMA*`).
- Ground-truth attribution comes from the parent's DWARF 1 parser:
  `/var/tmp/rwnames/ballers_sky2_funcs.json` — **270 sky2 functions with
  names and low_pc grouped by source file** (basky.c 62, skyinst.c 23,
  texcache.c 20, badma.c 19, skyblit.c 15, wrldpipe.c 14, ps2allmat.c 11,
  ps2allatomic.c 11, skyconv.c 9, … 33 files). Spot-checked 9 low_pc values
  against `nm`: all match. `/var/tmp/rwnames/ballers_structs.json` holds 531
  layouts (used as corroboration, not scored).

## 2. Ground truth (step 2)

Same file the Burnout run used: `docs/sky2/known_names.json`, **392 pairs**,
byte-identical to `/var/tmp/rwnames/truth.json` (verified: same keys, same
names). 389 are scorable (the same 3 marker addresses —
`003e00f0 003e3020 003e3f80` — have no function entry in the P4 database).

Reachability (truth name present in the reference symtab at all):

- Ballers: 356/392 names, **353/389 scorable = 0.907**. Missing names are
  concentrated in stream-size pairs (`RpGeometryStreamGetSize`,
  `RwCameraStreamWrite`, …), the `RpRandom*` triple, `SList`,
  `WorldSectorStreamRead`, and frame-list helpers — a different RW
  cut, not a compiler effect.
- Burnout (prior run): 212/389 = 0.545. Library mismatch (P4's `RwFopen`
  layer, world-sector streamers live elsewhere) capped it; Ballers barely
  has this problem.
## 3. Diff runs (step 3) and scores (step 4)

Command shape (never `--apply`):
`romwright-cli diff p4 --reference /var/tmp/ballersdiff/ballproj --reference-name ballers --project /var/tmp/ballersdiff/proj --matcher greedy [--no-semantic] --json`
(`--matcher greedy` is explicit; NAP was already shown impractical at this
scale — >45 min with no output on the smaller Burnout pair — and the Ballers
pair is larger, 14k x 26k, so it was not attempted).

- `index-semantics` on ballers: **19023 signatures in 61 s** (vs 55 s for
  Burnout's 12573; the 50-minute P4 index was reused from the copied DB).
- Greedy `--no-semantic`: done in **52 s**, 1974 matches, 546 anchors.
  Evidence: call-graph 1345, shape 434, context 83, profile 57, name 53,
  body 2.
- Greedy with semantics (both sides indexed): done in **~14 min**,
  3165 matches, 546 anchors (same anchor set). Evidence: call-graph 1683,
  context 732, shape 434, semantic 204, profile 57, name 53, body 2.
  Semantics fires almost entirely through new `context` propagations
  (83 -> 732); the pure `semantic` term contributes 204 matches.
- The 53 `name` anchors are shared Sony kernel imports (`SetVTLBRefillHandler`,
  `RemoveIntcHandler`, `_EnableDmac`, … — same BIOS on both sides), the same
  legitimate category as the Burnout run's 46.
- The 2 `body` matches are the known hazard recurring: `_root -> FUN_00100220`
  and a game-init stub, both **same-address `jr ra`-class coincidences**
  (1.000). Neither is RW; the proposal filter drops both. "Same bytes at the
  same address" is still unsafe for trivial bodies — now observed twice.

Scores (`/var/tmp/ballersdiff/score_diff.py`, exact string equality):

- No-semantic: **221/246 = 0.898** precision, 246/389 = 0.632 recall.
  Threshold sweep: >=0.90: 176/194 = 0.907; >=0.95: 136/147 = 0.925;
  >=0.99: 79/83 = 0.952. Thresholding helps monotonically here — the
  overconfident-tiny-shape bin that poisoned Burnout's top bin is absent.
- With semantics: **297/336 = 0.884** precision, 336/389 = 0.864 recall
  (336/353 = 0.952 of the reachable set). Sweep: >=0.90: 262/292 = 0.897;
  >=0.95: 200/219 = 0.913; >=0.99: 112/121 = 0.926.
- Best configuration for proposals = greedy with semantics (same choice as
  the Burnout run: -0.014 precision for +90 covered, +76 correct).
- No-semantic/semantic stability: 1720/1899 = 0.906 of shared addresses keep
  the same name; all 4 early hand-checks persisted.
- Driver block: no-semantic 72/74 = 0.973 (recall 0.655); semantics
  100/107 = 0.935 (recall 0.947). At score >= 0.95 the driver is
  **66/66 = 1.000**.

### What the diff gets WRONG

25 no-semantic misses, 39 with-semantic misses (full lists in
`/var/tmp/ballersdiff/` via `score_diff.py … --detail`):

- **Sibling/overload swaps dominate** (~13 of the 39): `RpClumpRemoveLight ->
  RpClumpRemoveCamera`, `_rpReadWorldRights -> _rpReadMaterialRights`,
  `RwMatrixScale -> RwMatrixTranslate`, `RwCameraSet{ Near,Far }ClipPlane`
  swapped both ways, `CameraBuildPerspViewMatrix <-> ParallelViewMatrix`
  swapped both ways, `RwV3dTransformVector -> RwV3dTransformVectors`,
  `RwFrameTranslate -> RwFrameRotate`, `RwStreamReadInt16 -> RwStreamReadInt32`
  (see below), `SList -> _rwSListCreate`. Same compiler removed the random
  shape collisions and left the systematic ones: near-identical overloads
  that differ by one flag or one loop.
- **Game-code context drift** (~25, nearly all new with semantics):
  `piJoinRoomCopy`, `CollectibleImages`, `LeaderboardsReset`,
  `pppoe_find_softc_by_deny_huniq`, `bball_grunt_get_target_for_catch`,
  `InsertHighScoreInTable`, `_sce_eenet_flush_route`, … The `context`
  term (83 -> 732 matches) propagates into game code around shared
  low-level helpers. Same warning as the Burnout run's semantic term, now
  wearing a different evidence label.
- **Two twin-pair swaps need orientation notes**, both adjudicated by hand
  (see §6): `SkyIm2DRenderPrimitive <-> IndexedPrimitive` and the
  `addCopyVU1*` siblings. The matcher gets the pair right and the assignment
  has to be read off arg shuffles / literals.
- **The agreed miss that matters**: `003df360 RwStreamReadInt16 ->
  RwStreamReadInt32` is proposed by Burnout AND Ballers AND P4's own stale
  alias in `world/babinwor.c` — three sources against the marker. The body
  asserts `(numBytes & 1) == 0` and calls `RwMemNative16`, so the marker
  stands, but a future reader should know this truth entry has three
  dissenters, not zero.

## 4. Comparison against the Burnout run (step 4)

Direct, same ground truth, same scorer:

- Overall precision: **0.884 (297/336) vs 0.650 (93/143): +0.234.**
  No-semantic alone (0.898) already beats Burnout-with-semantics by 0.248.
- Overall recall: **0.864 vs 0.368 (x2.35)**; of reachable: 0.952 vs ~0.67.
- Driver precision: **0.935 vs 0.726 (+0.209)**; driver recall 0.947 vs 0.549.
- Miss character changed: Burnout's misses were 6/26 tiny-shape game-code
  collisions plus sibling drift; Ballers' misses are almost all sibling
  swaps and context drift into game code. The tiny-shape pollution category
  is gone — that was a cross-compiler artifact.
- What limits Ballers now: (1) overloads the two compilers render
  identically (Persp/Parallel, Near/Far — no matcher separates these
  structurally); (2) the aggressive `context` term (+649 matches, where most
  new misses live); (3) 36/392 names simply absent from Ballers' RW cut.

## 5. Cross-reference: agreement vs confidence (step 5)

`/var/tmp/ballersdiff/xrefs.py` on the two with-semantics runs:

- 1100 P4 addresses named by **both** references; they agree on the name
  496/1100 = **0.451** of the time.
- On truth (136 addresses named by both, 94 agreed):
  burnout correct 93/136 = 0.684, ballers correct 123/136 = 0.904,
  **agreed correct 92/94 = 0.979**.
- Against each side's own confidence on the same 136:
  burnout >= 0.90: 73/99 = 0.737; burnout >= 0.95: 51/63 = 0.810;
  ballers >= 0.90: 109/117 = 0.932; ballers >= 0.95: 92/98 = 0.939.
- **Yes — agreement (0.979) beats either confidence score (best 0.939),
  by ~4 points at comparable coverage.** Small sample (94), stated as such,
  but the direction is unambiguous and the misses are documented, not hidden.
- Disagreements on truth (42): **burnout right 1, ballers right 31,
  neither 10.** When they disagree, trust Ballers (~74%).
- The 2 agreed misses: `003df360` (the Int16/Int32 triple-dissenter above)
  and `003e7680` (Persp/Parallel shape-1.0 twins). Agreement is fallible
  exactly where both matchers see identical bytes.

## 6. Proposal (step 5+) — `/var/tmp/ballersdiff/ballers_names.json`, 417 entries

Built by `/var/tmp/ballersdiff/make_proposals.py` from the with-semantics run
for P4 addresses NOT in truth. Reference attribution uses the DWARF
`ballers_sky2_funcs.json` (exact file, ground truth), **with no
name-prefix filter anywhere**: 131/417 = **0.314** of the kept proposals
have non-`Rw/Rp/_rw` names (`Sky*`, `PS2All*`, `open2DVU1Pkt`,
`addCopyVU1*`, `rwDMA*`, `DMADataFillTags`, …) and a prefix filter would
have discarded all of them. Anything in neither the sky2 list nor an
RW-family prefix (2412 game-code mappings) is dropped, as are tiny-body
shape/profile/body matches.

Guards (all visible in each entry's evidence string): size-ratio outside
[0.5, 2.0] caps at 0.65; both-sides-<=16-byte stubs cap at 0.35 (24 entries,
the Burnout `skyTexCacheEndFrame` precedent); P4 outside `00390000-0043FFFF`
caps at 0.60 and flags `outside-RW-block-cap` (40 entries — e.g. P4 game
init matching Ballers game init; the 0039 matfx run itself was
spot-verified instruction-identical at `0039AA50` and is in-block).
Same-file cluster +0.03 (cap 0.97). Median confidence 0.966.

Composition: 377 rw-block + 40 outliers; **132 in the rwcore_grouped driver
block**; basky.c 42, skyinst.c 21, badma.c 19, texcache.c 17, skyblit.c 14,
wrldpipe.c 13, ps2allatomic.c/ps2allmat.c 10 each, skyconv.c 8, native.c 7,
nodeps2all.c 6, skinskycommon.c/ps2allim3d.c 5 each, and smaller sky2 files,
plus RW-core symtab 208. Burnout independently names 105 of
the 417 and **agrees on 58** (each entry carries `proposed_by`,
`burnout_name`/`burnout_score` where present). 10 mangled SDK-util names
(9 `rwutil_*`, 1 `rw_gsImgXfer_*`) carry a `mangled-name` flag — genuine RW
library code, kept, match on demangled base at your own risk.

## 7. Hand-check sample (step 6) — 9 pairs, disassembled both sides

`romwright-cli disasm` on each binary; verdicts by control-flow shape +
shared constants/callees. All 9 were checked against the final
with-semantics proposals (the first 4 were found under no-semantics and
verified stable across the switch):

| # | p4 -> proposed name | sizes | verdict + evidence |
|---|---|---|---|
| 1 | `003f6990 -> skyWriteTexCB` (0.995, call-graph, basky.c; AGREED) | 92/96 | **confirmed** — instruction-identical modulo gp/callee addrs; same frame `0x30`, same `beq`+`lhu 0x14` guard, same `movz` idiom; callee is the Int32-stream helper on both sides |
| 2 | `003f2760 -> rwDMAFlushPURef` (0.991, call-graph, badma.c) | 208/212 | **confirmed** — same `0x50` frame, same `0x8000/0x7fff` chunk loop, same `ori a1, 0x42` DMA tag; calls the AddPkt-role helper (P4 `003f34e0` = independently proposed `_rwDMAAddPkt`, Ballers `001428a0` = symtab `_rwDMAAddPkt`) |
| 3 | `00401460 -> _rpSkyFrameBufferRastersUpdate` (0.997, call-graph, basky.c; AGREED) | 372/376 | **confirmed** — GS TEX bit-surgery (`srl 6`, `andi 0x3fff`, `dsll 5`, `dsll32`) at struct offsets `0x58/0x8/0xc/0x10` line-for-line; Burnout proposed the same name independently |
| 4 | `0040d720 -> skyPrepareUploadRaster` (0.994, call-graph, texcache.c; AGREED) | 872/880 | **confirmed** — identical call skeleton: 4x `li a1, 0x7fee` + jal, same `jalr v0` virtual slots, same `0xa/0x10/0x20` sequence; callees resolve to same-role DMA/upload helpers |
| 5 | `00403390 -> _rwSkyRasterClear` (1.000, call-graph, skyblit.c; AGREED) | 68/68 | **confirmed** — instruction-identical; Ballers symtab at the ref addr reads `_rwSkyRasterClear`; Burnout's run confirmed this same pair too |
| 6 | `0040d0a0 -> SkyIm2DRenderPrimitive` (1.000, shape, skyinst.c; Burnout says Indexed) | 112/112 | **confirmed (Ballers orientation)** — the twins differ only in arg shuffle: `0040d0a0` forwards 2 regs (`move a2,a1`) exactly like Ballers `0015b850` (symtab Primitive), while `0040c0f0` forwards 3 (`move a3,a2`) exactly like Ballers `0015c890` (symtab IndexedPrimitive). Burnout has them swapped |
| 7 | `0040c6d0 -> addCopyVU1IndPrimTriList` (0.999, semantic, skyinst.c; Burnout says LineList) | 816/848 | **confirmed (Ballers orientation)** — P4 carries `li a0, 0x3` (3 verts/tri) and `ori 0x404` packet tag matching Ballers TriList `0015be60` (`li a0, 0x3`, `ori 0x404`); LineList `0015b8c0` differs |
| 8 | `003f38d0 -> _rwDMAWaitQueue` (0.998, call-graph, badma.c; AGREED) | 232/236 | **confirmed** — calls the ForceBufferSwap-role helper twice (P4 `003f32d0`, Ballers `00142620` = symtab `_rwDMAForceBufferSwap`) around the Handler-role call (P4 `003f2830`, Ballers `001419c0` = `rwDMAHandler`); callee identities close the loop |
| 9 | `003f44c0 -> _rwDMADMAPktAllocHigh` (0.947, call-graph, badma.c; Burnout says Unhook) | 612/636 | **confirmed (Ballers orientation)** — shared literal constellation `0x100/-0x4000/0x3f/0x7f/-0x80/0x102` in order plus a 5-call tail through ClosePkt- and ForceBufferSwap-role helpers; Ballers `_rwDMAUnhook` lives at a different address (`00143e20`) |

9 confirmed, 0 rejected, 0 weak (the only stub in the sample frame,
`0040f1b0 skyTexCacheEndFrame` 8/8, is capped at 0.35 in the proposals, not
hand-counted). Three verdicts adjudicate disagreements, all three for
Ballers; five confirm agreements.

## 8. Bottom line and what is committed

- Same-toolchain reference wins everywhere: **0.884/0.864 overall,
  0.935/0.947 on the driver**, vs 0.650/0.368 and 0.726/0.549. An honest
  negative was on the table; this is not it.
- Agreement between the two references (92/94 = 0.979) beats either
  confidence score and is the best correctness signal in the whole study;
  disagreement means trust Ballers (31/42 vs 1/42).
- Committed to `docs/sky2/`: `ballers_names.json` (417 proposals with
  confidence, evidence, source file, region, and per-entry Burnout
  agreement) and this report as `REPORT.md`. Nothing else in the repo is
  touched; `src/` is unchanged — proposals remain hints, with the measured
  caveat that ~1 in 8 is wrong overall (~1 in 15 on the driver, ~1 in 50
  where the references agree).
- Reproduction: scoring (`score_diff.py`), cross-reference (`xrefs.py`),
  and proposal (`make_proposals.py`) scripts live next to the diffs in
  `/var/tmp/ballersdiff/`; raw diffs `diff_greedy_nosem.json` (52 s) and
  `diff_greedy_sem.json` (~14 min) plus `ballproj/`/`proj/` are there too.
  P4-side re-indexing is unnecessary — `proj/` carries the 13457 P4
  signatures over from the Burnout run.
