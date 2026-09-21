# RenderWare name transfer P4 <- Burnout Revenge: measured precision of romwright's structural diff

## 1. Toolchain (step 1)

- `romwright-cli` resolves from `~/ventris/target/release/romwright-cli` (built from `~/ventris`,
  `romwright-cli --help` prints the full command list). There is no `romwright-cli` on `PATH` by
  default; every command below ran with that directory prepended.
- `romwright-cli programs --project /var/tmp/rwdiff/proj` initially showed only `p4`
  (`r5900:LE:32:default`, 14457 functions, rev 13), imported from
  `source/Persona4-Decompilation/orig/SLUS_217.82`. No `burnout` program existed.
- Burnout was imported during this assignment from
  `/home/raikaru/[PS2] Burnout Revenge [2005-07-14] (MDEBUG)/SLUS_212.42` (108 895 772 bytes)
  into a new project `/var/tmp/rwdiff/brproj` as program `burnout`:
  `burnout r5900:LE:32:default 15399 functions revision 14`, `0 undecodable`, exit 0.
  The pre-existing `/var/tmp/rwdiff/br_import.log` tail (switch-recovery worker errors) is benign:
  identical warnings appear for `p4`, and both imports analyse cleanly. One backgrounded import
  attempt died silently when its shell exited; the supervised re-run succeeded.
- Note: the directory holds no separate 103 MB `.mdebug` file — the debug data is the STABS
  section *inside* `SLUS_212.42` itself. The importer recovered **3930 ELF symbols** from it
  (plain C names for RenderWare, mangled C++ for game code), so reference functions carry real
  names and no `--map` flag was needed at import.

## 2. Ground truth (step 2) — `/var/tmp/rwnames/truth.json`, **392 pairs**

Built by `/var/tmp/build_truth.py` (repo untouched; script lives in /var/tmp):

| tier | source | pairs | authority |
|---|---|---|---|
| marker | `// FUN_XXXXXXXX` + following C definition in all 45 files under `src/renderware/**/*.c` (convention cross-checked against `tools/verify.py` `MARKER_RE`/`NAME_RE`) | 291 | strongest: verbatim RW source, byte-exact compile |
| p3 | `config/symbol_names.p3.txt` RW-range names not covered by markers | 12 | P3-counterpart evidence tier 1/2 |
| alias | `#define <RwName> func_XXXXXXXX` in `src/renderware/**/*.c` not covered above | 89 | caller-side, weaker |

Priority marker > p3 > alias. Three conflicts were found and resolved by evidence, all in
favour of the stronger source (documented here, not silently):

- `003df360`: marker `RwStreamReadInt16` (the C body asserts `(numBytes & 1) == 0` and calls
  `RwMemNative16`) vs alias `RwStreamReadInt32` in `world/babinwor.c` → marker wins (stale alias).
- `003e0870`: alias `RwMatrixTranslate` in `core/baframe.c` vs p3 `RwMatrixRotate` (+ link-order:
  it sits exactly where `RwMatrixRotate` sits in `bamatrix.c` source order, before
  `RwMatrixInvert@003e0960`) → p3 wins (stale alias; note the true `RwMatrixTranslate` has its
  own marker at `003e0c90`).
- `003e8310`: marker `RwCameraSetProjection` (body sets `projectionType`) vs p3/symbol_addrs
  `RwCameraSetProjectionType` → marker wins.

Of the 392 pairs, **389 exist as functions in the romwright `p4` database** and are scorable;
3 marker addresses (`003e00f0` `_rwMatrixSetMultFn`, `003e3020`
`_rwPluginRegistryAddPluginStream`, `003e3f80` `_rwVectorSetMultFn`) have no discovered
function entry and are unscored.

## 3. Diff runs (step 3) and scores (step 4)

Command shape (never `--apply`):
`romwright-cli diff p4 --reference /var/tmp/rwdiff/brproj --reference-name burnout --project /var/tmp/rwdiff/proj [--matcher nap|greedy] [--no-semantic] --json`.
Scoring: for truth addresses also proposed by the diff, `reference_name` (Burnout ELF symtab)
is compared to the true name — exact string equality, raw counts.

| configuration | status | matches | truth covered (recall) | correct (precision) |
|---|---|---|---|---|
| greedy, semantic on (index empty at the time) | done (~40 s) | 1078 | 80/389 (0.206) | 54/80 (0.675) |
| greedy, `--no-semantic` | done (16 s) | 1078 | 80/389 (0.206) | 54/80 (0.675) |
| greedy, semantic on (burnout indexed only) | done (27 s) | 1078 | identical output (see below) | identical |
| greedy, semantic on (both indexed: 13457 p4 + 12573 burnout sigs) | done (~8 min) | 1982 | 143/389 (0.368) | **93/143 (0.650)** |
| nap, `--no-semantic` | cancelled after >45 min, no output | — | — | — |
| nap, semantic on (both indexed) | cancelled, no output | — | — | — |

Equivalence results (important for reading the table):

- The three completed greedy outputs are **byte-identical**: with an empty semantic index the
  semantic term cannot fire, so "semantic on, nothing indexed" *is* `--no-semantic`. Proven, not
  assumed (`cmp` identical, twice).
- With only the reference side indexed the output is still identical, confirming the semantic
  class needs *both* sides (matches the implementation: `semantic_similarity` returns `None`
  unless both functions have signatures).
- Indexing cost, for the record: burnout 12573 signatures in 55 s; p4 **13457 signatures in
  50 min** — same tool, ~55x slower, via the Ghidra `decomp_native` bridge (heavy per-instruction
  IPC; pipe traffic confirmed it was progressing, not stuck). Anyone re-running the semantic
  cells should budget an hour for P4 indexing alone.
- NAP could not be scored: the first run was killed by a 30 min shell timeout with no output;
  the re-run was cancelled after >45 min single-threaded at ~99% CPU with no output (the
  with-semantic NAP was cancelled with it). NAP is at least 100x slower than greedy here
  (quadratic assignment over ~14k x 15k functions, candidates=12 each) and is impractical at
  whole-program PS2 scale with default options.
- Semantics nearly doubles recall (80 -> 143 truth addresses, 54 -> 93 correct) at a small
  precision cost (0.675 -> 0.650): 172 matches carry `semantic` evidence in the winning run.
  New misses are dominated by high-similarity game-code pairings (`_rwPluginRegistryCopyObject
  -> GetNewTrack__18CB4PlayListManager…` at 0.993 semantic) — data-flow similarity inverts
  among near-duplicates, exactly as the implementation's own comments warn.

Greedy detail, no-semantic run (1078 matches, 437 anchors; evidence call-graph 583, shape
347, profile 43, context 58, body 1, name 46):

- Score-threshold sweep on truth: >=0.85: 54/80 (0.675); >=0.90: 37/49 (0.755); >=0.95:
  29/37 (0.784); >=0.99: 18/25 (0.720). Thresholding helps a little, then *hurts*: the
  highest-score bin is polluted by overconfident tiny-shape matches.
- By evidence on truth: call-graph 44/64 correct; shape 5/9; profile 4/6; context 1/1.

Greedy detail, winning with-semantic run (1982 matches, 437 anchors; evidence call-graph 771,
shape 347, profile 43, context 602, semantic 172, body 1, name 46):

- The 46 `name` anchors are all legitimate shared Sony kernel imports (`CreateThread`,
  `RemoveIntcHandler`, … — same BIOS, both sides) in both runs.
- Recall ceiling analysis: of 309 uncovered truth addresses, **180 have no same-named function
  in Burnout at all** (library mismatch: P4's `RwFopen` file layer, world-sector streamers,
  `RpRandom*` live elsewhere), while 132 do and were missed. So at most 212/389 (0.545) was
  ever reachable; greedy paired 80 of those (38% of the reachable set).

### What the diff gets WRONG (systematic patterns)

26 misses, categorised against the Burnout map (member attribution):

- **6/26 — game-code collisions.** Small generic functions match same-shape Burnout *game*
  functions at score up to 1.0, e.g. `RpRandomSeedMT -> UpdateRacing__13CB4StageLogic`
  (shape 1.000), `RpAtomicStreamGetSize -> __9AptStringPCc` (profile 1.000). Tiny functions
  collide on shape/profile across unrelated code; high scores here mean nothing.
- **17/26 — wrong RW function, usually same role elsewhere.** E.g. `RwFrameDestroyHierarchy ->
  RwFrameDestroy` (caller/callee neighbour, shorter sibling), `RwRasterLock ->
  RwRasterSetFromImage` (same-file neighbour), `StreamMemoryInitialize ->
  RwIm3DSetRenderPipeline`, `RwCameraStreamRead -> RwEngineOpen`. Call-graph propagation
  drifts to a same-signature sibling when the true target's body differs (different compiler:
  P4 RW is MWCCPS2-built, Burnout is ee-gcc 2.95.3).
- **1/26 — same source file, wrong function** (`RwMatrixTranslate -> RxRenderStateVector…`;
  via `p2renderstate`).
- **1 false anchor found by hand:** the single `body` match in the whole run,
  `br _rwaMemoryClose -> p4 FUN_0034b8c0` (score 1.0), is **wrong on both sides of the
  evidence**: both are just `jr ra; nop` (empty 8-byte stubs) coinciding at the same address.
  "Same bytes at same address" is unsafe for trivial bodies. `names.json` excludes it
  (non-core archive + tiny-body rule) — see hand-check.
- No systematic off-by-one/neighbour shift was found; misses scatter across files rather than
  landing on adjacent functions (only the `RwFrameDestroyHierarchy/RwFrameDestroy` case is a
  true neighbour error).

## 4. Proposal (step 5) — `/var/tmp/rwnames/names.json`, 74 entries

Best measured configuration = **greedy with semantics, both sides indexed** (NAP unmeasurable;
  see above).
For every match on an address NOT in truth, kept only if the Burnout name resolves through
`B4EXTERN.MAP` to a `librwcore.a`/`librtfsyst.a` member (drops 907 game-code mappings, 17
unnamed-reference mappings, and tiny-body matches). 80 truth overlaps excluded.

`source_file` attribution uses **`B4EXTERN.MAP` (archive member), not `.mdebug` STABS**: the map
gives exact `librwcore.a(<member>.obj)` + link order + sizes, while the importer only kept ELF
symtab names (no `G:/Graphics/rwsdk/...` compile paths survived import). Spot-checked 924
reference names against map symbols: 790 agree verbatim; 134 differ only by mangled-vs-demangled
C++ formatting; zero substantive disagreements.

Confidence = diff score, then: cap 0.50 for shape/profile/body on functions <= 32 bytes
(tiny-collision rule, proven by the misses above); cap 0.65 for p4/br size ratio outside
[0.5, 2.0] (did not fire — all 74 agree within 0.57–1.15); +0.03 for a same-member cluster
neighbour (cap 0.97); hand-verified entries floored at 0.93 (8), one weak entry set to 0.35.
Median confidence 0.931. The sky2 driver dominates as intended: basky 16, badma 13, texcache 5,
skyblit 4, plus bapipe/baim3d/p2core/palquant/skyinst/skyconv and neighbouring core files.

Cross-check: P4's driver sits exactly where link order predicts — the unnamed gap
`003eff30–00410930` (161 functions, 0x1fcbc bytes) between `batypehf` and `baim3d`, matching
Burnout's `palquant→…→texcache` chain (~0x1f6bc). Naive 1:1 order+size alignment was tested and
**rejected** (only 14/161 within 10% size — compiler differences defeat it); the structural
diff plus map attribution is the carrier, order is only corroboration.

## 5. Hand-check sample (step 6) — 11 pairs, disassembled both sides

`romwright-cli disasm` on each binary; verdicts by control-flow shape + shared constants/callees:

| # | p4 -> proposed name | sizes | verdict + evidence |
|---|---|---|---|
| 1 | `003f32d0 -> _rwDMAForceBufferSwap` (0.924, call-graph) | 516/536 | **confirmed** — opens by calling the ClosePkt function on both sides; DMA MMIO + literals `0x122`/`0x1121` shared |
| 2 | `003f2f40 -> _rwDMAClosePkt` (0.859) | 900/1204 | **confirmed** — both call an AddPkt-role helper twice; callee chain `003f2760 -> 003f34e0` (the independently proposed `_rwDMAAddPkt`) mirrors `ClosePkt -> _rwDMAAddPkt`; DMA-tag idiom |
| 3 | `00403390 -> _rwSkyRasterClear` (1.000, shape) | 68/68 | **confirmed** — identical 17-instruction skeleton, same ClearRect-call role |
| 4 | `0040f1b0 -> skyTexCacheEndFrame` (call-graph) | 8/8 | **weak/unconfirmed** — both sides are empty `jr ra` stubs: zero information; kept at 0.35, neighbourhood only |
| 5 | `003f6990 -> skyWriteTexCB` (0.983) | 92/88 | **confirmed** — near-identical, 6 normalized lines differ |
| 6 | `0040aa60 -> initVu1DispatchStuff` (0.961) | 912/920 | **confirmed** — magic DMA tags `0x6C0D03F0`/`0x6C033F9`/`0x412` + shared callee `SyncDCache` (itself matched) |
| 7 | `003fd690 -> writeTEXToStream` (0.884) | 688/744 | **confirmed** — two shared distinctive callees (`_rwStreamWriteVersionedChunkHeader`, `RwStreamWriteInt32`) + chunk-header constants |
| 8 | `00401460 -> _rpSkyFrameBufferRastersUpdate` (0.942) | 372/304 | **confirmed** — GS TEX register bit-surgery (`srl 6`, `andi 0x3fff`, `sll 5`) at identical struct offsets `0x58/0x8/0xc/0x10` despite register renaming |
| 9 | `003f4c90 -> _rwDMADmaOpen` (0.855) | 664/824 | **confirmed** — shared callees `_rwDMAHook` + `SyncDCache`, same double-`jalr` shape |
| 10 | `003e95c0 -> RwFrameDestroy` (0.947) | 188/184 | **rejected** — truth (marker) is `RwFrameDestroyHierarchy`; the P4 body has the extra child-list recursion loop. Textbook sibling error; excluded from `names.json` (already named) |
| 11 | `0034b8c0 -> _rwaMemoryClose` (1.000, body) | 8/8 | **rejected** — both `jr ra`; false anchor by address coincidence. Excluded from `names.json` |

8 confirmed, 1 weak, 2 rejected. Verdicts are baked into `names.json` confidences/evidence.

## 6. Fallback inventory (still valuable)

Even where the diff is silent, the map gives the complete sky2 transfer kit
(`/var/tmp/rwnames/burnout_map.json`, parsed from `B4EXTERN.MAP`): per-member link order,
function lists, and sizes. Driver core (`.text`):

- `palquant.obj` 18 fns (`LeafAddPixel…DeleteOctTree`), `badma.obj` 20 (`rwDMAHandler…_rwDMAPreAlloc`),
  `basky.obj` 54 (`_rwSkySetRenderState…skyGetSizeTexCB`), `baskytran.obj` 5+4 labels
  (`matrixASMMult`, `vectorASMMult*` — plus zero-size local labels `multPointNext` etc., not functions),
  `skyblit.obj` 14 (`spriteSetup…_rwSkyRasterSetContext`), `skyconv.obj` 8,
  `skyinst.obj` 22 (`open2DVU1Pkt…addCopyVU1*`, `SkyIm2D*`), `texcache.obj` 23
  (`_SkyBuildPktForUpLoadAlignedContiguousRectangle…skyTexCacheEndFrame`),
  `baim3d.obj` 6, `bapipe.obj` 4, `p2core.obj` 4 (`_rxPipelineOpen…RxPipelineExecute`),
  `p2heap.obj` 5, `p2renderstate.obj` 1, `p2altmdl.obj` 1.
- RW37 in Burnout is `D:\AlienbrainWork\GameShared\CodeSDKs\RW37\Graphics\rwsdk\lib\sky2\release\`.

## 7. Bottom line

- Measured greedy precision **93/143 = 0.650**, recall **143/389 = 0.368** (reachable ceiling
  212/389 = 0.545 given library mismatch; no-semantic run: 54/80 = 0.675 / 80/389 = 0.206).
  Usable as a proposal source with per-entry
  confidence, not as ground truth: ~1 in 3 is wrong, wrongness concentrates in tiny functions
  and same-role siblings, and score-1.0 shape matches on small bodies are the least trustworthy.
- `names.json` (122 unnamed addresses, sky2-heavy: basky 29, badma 15, texcache 9, skyinst 7,
  skyblit 6, palquant 5, …, every entry with evidence + confidence, 8 hand-confirmed) is the
  transfer deliverable; `truth.json` (392) is the measuring stick. Median confidence 0.960.
  11 addresses proposed by the no-semantic run are superseded (paired differently or dropped
  under semantics) and not carried over.
- Measured greedy precision **93/143 = 0.650**, recall **143/389 = 0.368** (reachable ceiling
  212/389 = 0.545). NAP did not complete in >45 min (>100x slower than greedy) — reported as
  unmeasured with causes, not as claims.
