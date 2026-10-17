# Persona 4 PC port: platform surface (phase 0)

Scope: every platform-layer function or global that first-party code calls directly, grouped by library. Measured at `origin/main` 7cdaa8f1 (worktree `portplatformsurface`). Counts marked `[inferred]` come from address-owner attribution, not from a symbol name or a call site.

Method (summary):
- First-party = `src/` minus `rw`, `renderware`, `cri`, `sce`, `middleware`, `generated` (773 `.c` files). Comments and strings stripped.
- Callees matched two ways: by C name, and by `func_XXXXXXXX` / `FUN_XXXXXXXX` address. Address matches on unnamed functions are why some totals include calls that the name alone would miss.
- SDK functions matched to `config/sdk_symbol_provenance.txt` (491 promoted SCE symbols with archive:member and address). This is the most reliable SCE inventory.
- Total first-party call sites: 83,796 across 9,015 distinct callee names.

Caveats:
- The scripts ran in a live eval kernel that was lost before the final join was saved. Per-name totals below come from the final join output; the earlier name-only pass is noted where it differs. Caller-subsystem breakdowns were re-measured only for the SCE/SDK, CRI-wrapper, and `sceMc2` rows. For RW and libc rows, caller columns are omitted rather than guessed. Re-running the join will fill them in.
- The join is at 7cdaa8f1. `ThirdPartyNames` renames may shift names and counts.

## 1. Key numbers

| Area | Distinct callees | Direct call sites | Notes |
|---|---|---|---|
| SCE / SDK (provenance-matched) | 213 functions | 515 | libkernl 187 fns / 431 calls; libmc2 11 / 47; libpad 9 / 21; libcdvd 6 / 16 |
| First-party `H_Cdvd_*` wrappers | 42 names | 942 | Thin wrappers over `sceOpen`/`sceRead` and the CRI/ROFS file layer |
| RenderWare (named) | 31 names | 2,190 | `RpSkyRenderStateSet` alone is 681 |
| RenderWare (unnamed vendor, by owner dir) | many `func_` | 450 (`src/rw`) + 1,874 (`src/renderware`) | `[inferred]` owner attribution |
| CRI (named) | 9 names | 22 | Sofdec `mwPly*` dominates |
| CRI (unnamed, by owner dir) | many `func_` | 203 (`src/cri`) | `[inferred]` owner attribution |
| libc / libm | 16 names (21 in the name-only pass) | 2,714 (2,764) | `memset`, `memcpy`, `sinf`, `sprintf`, `cosf` |
| EE VU0 / macro intrinsics | 34 names | 888 | Macros in first-party code, not library code |
| Unnamed middleware helper `func_00440b68` | 1 | 478 | Adjacent to `qsort` (`0x440BB8`). Identity unknown |

Rough sums: about 4,000 RenderWare calls (named + owner-attributed unnamed), about 2,800 libc calls, about 1,300 CRI or file-layer calls (22 named CRI, 203 unnamed `src/cri`, 95 inferred, 942 `H_Cdvd_*` wrappers), and 515 direct SDK calls. These are sums of the rows above and may double count a few calls.

## 2. SCE / SDK surface (from `config/sdk_symbol_provenance.txt`)

Measured: 491 promoted symbols (83,400 bytes). 213 have first-party call sites (515 calls). Top 30 by call count, with caller subsystems re-measured:

| Function | Archive:member | Calls | Caller subsystems | PC replacement |
|---|---|---|---|---|
| `EIntr` | libkernl:diei.o | 36 | Kernel 16, top 10, promoted 7 | No-op: single-threaded PC build has no interrupts |
| `DIntr` | libkernl:diei.o | 31 | Kernel 15, top 8, promoted 5 | No-op (pair of `EIntr`) |
| `sceSifLoadModule` | libkernl:eeloadfile.o | 16 | Kernel 16 | Stub (IOP module load skipped) |
| `sceMc2GetInfoAsync` | libmc2:libmc2.o | 15 | Kernel 15 | Host memory-card shim (folder-backed) |
| `sceClose` | libkernl:filestub.o | 12 | h_cdvd 4, Kosaka 4, promoted 4 | Host file layer `close` |
| `sceWrite` | libkernl:filestub.o | 11 | Kosaka 5, promoted 4, h_cdvd 2 | Host file layer `write` |
| `sceOpen` | libkernl:filestub.o | 9 | h_cdvd 4, Kosaka 4, promoted 1 | Host file layer `open` (case-insensitive ISO path map) |
| `WaitSema` | libkernl:klib.o | 9 | promoted 9 | SDL3 mutex/cond or no-op on single thread |
| `sceMc2SearchFileAsync` | libmc2:libmc2.o | 8 | Kernel 8 | Host memory-card shim |
| `sceDclose` | libkernl:filestub.o | 8 | Kosaka 5, Kernel 2, promoted 1 | Host directory close |
| `SignalSema` | libkernl:klib.o | 8 | promoted 8 | As `WaitSema` |
| `sceSifFreeSysMemory` | libkernl:iopheap.o | 7 | top 5, promoted 2 | Host allocator free |
| `sceSifAllocSysMemory` | libkernl:iopheap.o | 7 | top 7 | Host allocator |
| `sceDread` | libkernl:filestub.o | 7 | Kosaka 4, Kernel 2, promoted 1 | Host directory read |
| `sceDopen` | libkernl:filestub.o | 7 | Kosaka 4, Kernel 2, promoted 1 | Host directory open |
| `sceSync` | libkernl:filestub.o | 6 | Kosaka 3, h_cdvd 2, promoted 1 | Host file layer `sync` (no-op) |
| `sceRead` | libkernl:filestub.o | 6 | h_cdvd 2, promoted 2, Kosaka 2 | Host file layer `read` |
| `sceGetstat` | libkernl:filestub.o | 6 | Kosaka 5, promoted 1 | Host `stat` |
| `_sceCallCode` | libkernl:filestub.o | 6 | promoted 6 | Stub |
| `sceMc2WriteFileAsync` | libmc2:libmc2.o | 5 | Kernel 5 | Host memory-card shim |
| `sceLseek` | libkernl:filestub.o | 5 | h_cdvd 5 | Host file layer `seek` |
| `sceCdMmode` | libcdvd:cdvd036.o | 5 | Kernel 3, h_cdvd 2 | No-op (drive mode) |
| `sceCdInit` | libcdvd:cdvd000.o | 5 | Kernel 3, h_cdvd 2 | No-op / host disc mount |
| `ReferThreadStatus` | libkernl:klib.o | 5 | top 2, Kernel 2, promoted 1 | Stub |
| `FlushCache` | libkernl:klib.o | 5 | top 2, Kernel 2, promoted 1 | No-op (cache flush) |
| `Exit` | libkernl:exit.o | 5 | promoted 3, Kernel 2 | Host `exit` |
| `sceTtyInit` | libkernl:tty.o | 4 | promoted 4 | Stub / host stdio |
| `sceSifDmaStat` | libkernl:klib.o | 4 | top 3, promoted 1 | Stub |
| `scePadSetMainMode` | libpad:libpad.o | 4 | Kernel 4 | SDL3 gamepad init |
| `CreateSema` | libkernl:klib.o | 4 | promoted 4 | SDL3 mutex (or no-op) |

Remaining 183 SDK functions have 1 to 4 calls each, mostly `sceSif*`, `sceMc2*`, `scePad*`, `sceTty*`, thread and alarm primitives. The full list is in the provenance file.

Library summary from the provenance file:

| Archive | Promoted symbols | First-party-called | Calls |
|---|---|---|---|
| libkernl.a | 349 | 187 | 431 |
| libmc2.a | 85 | 11 | 47 |
| libpad.a | 32 | 9 | 21 |
| libcdvd.a | 25 | 6 | 16 |

Callers are mostly `src/Kernel` (`sdkCdvd`, `h_memcard`, `h_cdvd`) and `src/promoted`. Gameplay code (Kosaka, and others) calls the file layer (`sceOpen`, `sceRead`, `sceDopen`) directly.

## 3. First-party platform wrappers

These are defined in first-party code, so they are not counted as library functions. They are where the PC port should cut, because they hide SCE/CRI calls behind one name.

| Wrapper group | Names | Calls | Defined in | PC replacement |
|---|---|---|---|---|
| `H_Cdvd_*` (disc / file) | 42 | 942 | `src/Kernel/sdkCdvd.c`, `src/h_cdvd/`, `src/cldScheduler.c`, `src/cmmMisc.c` | Host ISO/loose-file reader behind the same API |
| `mwPlayer*` (movie) | 4 | 16 (`Create` 6, `GetTaskName` 4, `GetCurrent` 3, `CreateReset` 3) | `src/Kosaka/Field/k_fldrc_inferred_00468d10.c` | Sofdec replacement (section 4) |

Specific `H_Cdvd_*` counts by name (from the name pass): `AcquireDirectory` 216, `Destroy` 206, `IsFileLoaded` 160, `LookupRequest` 109, `ReadSync` 44, `GetArchiveEntry` 41, `FileExists` 25, `BuildPathUppercase` 16, `StartStreamLoad` 11, `NormalizePath` 11, `CreateFileDevice` 10, `SplitPath` 8, `SelectDirectory` 8, `UpdateRequests` 5, `StartPlayback` 4, `InitDevices` 4, `StreamOpenHandle` 3.

Naming note: `sceneUpdate*`, `SceneDraw_*`, and `mc*` (`mcSetSkyRenderState` 20, `mcIconTaskCreate` 10, `mcDrawCircleFan` 11) are game code, not SCE. `mc_add` is game code too. `sdkAddOffset` (16 calls) is a first-party helper, not an SDK call.

## 4. CRI (ADX, Sofdec, ROFS, IOP driver)

Named CRI callees (9 names, 22 calls):

| Function | Calls | Callers (measured) | Notes |
|---|---|---|---|
| `mwPlyReleaseLp` | 6 | Kosaka 6 | Sofdec loop release |
| `mwPlyInitSfdFx` | 5 | top 2, Kernel 2, promoted 1 | Sofdec init |
| `mwPlySetFrmSync` | 2 | Kosaka 2 | |
| `mwPlyRelCurFrm` | 2 | Kosaka 2 | |
| `mwPlyGetCurFrm` | 2 | Kosaka 2 | |
| `mwPlyCalcWorkCprmSfd` | 2 | Kosaka 2 | |
| `mwPlyStartFnameLp` | 1 | h_cdvd 1 | |
| `H_Cdvd_StreamSeek` | 1 | Kernel 1 | First-party wrapper, not CRI |

Unnamed CRI callees (`src/cri` owner, 203 calls) and bucket-attributed CRI callees (95, `[inferred]`) are dominated by ADX and Sofdec internals. Names in the retail image: `adxt_*` (about 110), `adxf_*` (about 17), `ADXB_DecodeHeaderAdx` at `0x4C3688`, `mwPly*`, `MWSFD_*`, `MWSST_Create` (`0x510BC0`), `sfxcnv_*`, `sfx_InitHn` (`0x52B738`).

Disc / IOP side (verified in `image.bin`):
- IOP module names (`cdrom0:\LIB31\...`, string table at VA `0x5DC560..0x5DC730`): `SIO2MAN`, `SIO2D`, `PADMAN`, `DBCMAN`, `MC2_S1`, `LIBSD`, `CRI_ADXI`, `SDRDRV`, `MODHSYN`, `MODMSIN`, `MODSESQ`, `SKSOUND`, `SKHSYNTH`, `SKSESQ` (14 IRX). Plus `sdinit=0 spucore=1` and `maxtrack=16` argument strings.
- Asset families by string occurrence in the image (not unique files): `.BIN` 897, `.ADX` 623, `.AFS` 361, `.SFD` 23, `.IRX` 14. `ROFS` appears 29 times. Movies include `P3CTOP.SFD` and `P4CT001.SFD` to `P4CT007.SFD` (among 23).
- VA to file offset mapping `VA - 0x100000` confirmed (module strings found at file offset `0x4DC560`).

Replacement strategy:
- ADX: decode in the PC build. ADX is a fixed-rate ADPCM codec; the header decoder is `ADXB_DecodeHeaderAdx`. Use CRI ADX only as a reference. `[inferred]` 1,000 to 1,500 lines.
- Sofdec (MPEG-1 in an SFD container, with an IPU/YUV path): use pl_mpeg or ffmpeg behind a `mwPly*` shim. `[inferred]` 600 to 800 lines of shim plus the decoder dependency.
- IOP modules: skip entirely. The PC build needs no IRX loading. Keep `kwlnInitIop` as a state-only stub.

## 5. RenderWare 3.7 + sky2

Named RW callees (31 names, 2,190 calls by join). Caller breakdowns for these rows were not re-measured (see caveats):

| Function | Calls | PC replacement |
|---|---|---|
| `RpSkyRenderStateSet` | 681 | Re-implement sky2 render-state table on OpenGL (GL state cache) |
| `RwV3dNormalize` | 326 | Plain C |
| `RtQuatTransformVectors` | 206 | Plain C |
| `RpRandom` | 251 | Plain C (keep the seed behaviour) |
| `RwMatrixRotate` | 181 | Plain C |
| `RwV3dLength` | 111 | Plain C |
| `RwCameraFrustumTestSphere` | 51 | librw camera or plain C |
| `RwMatrixTranslate`, `RwMatrixScale`, `RwMatrixUpdate`, `RwMatrixOptimize` | 40, 38, 36, 30 | Plain C |
| `RwEngineGetMatrixTolerances` | 29 | Constant |
| `RtQuatConvertFromMatrix` | 19 | Plain C |
| `RpAtomicSetFrame` | 12 | RW shim |
| `RpMatFXMaterialGetEffects` | 9 | librw MatFX (check coverage) |
| `RwCameraClear`, `RwCameraSetViewWindow`, `RwCameraSetProjectionType` | 7, 6, 4 | RW camera shim |
| `RwRasterCreate`, `RwRasterDestroy` | 3, 6 | Texture shim (OpenGL textures) |
| `RwEngineInit` | 2 | RW engine init (heap `0x800000`) |
| `RpHAnimFrameGetHierarchy` | 2 | librw hanim (check coverage) |

Remaining named RW callees (about 17): `RpRandomSeed`, `RpRandomSeedMT`, `RpUVAnimPluginAttach`, `RpSkyTexGetTex0`, `RtAnimInterpolatorSetAnimLoopCallBack`, `RpGeometryLock`, `RwFclose`, `RwBool` (probably a cast), `RWALIGN` (macro), and others.

Unnamed vendor RW callees (`func_` names by owner dir): `src/renderware` 1,874 calls, `src/rw` 450 calls. Bucket-attributed to RW (`[inferred]`): 528 `src/rw`-nearest, 341 `src/renderware`-nearest.

Vendor source footprint (definitions by address marker, from `vendor_defs.txt`): `src/rw` 465 definitions in 35 files; `src/renderware` 331 in 45 files. These are grouped `INCLUDE_ASM` units. File names are labels, not ownership. Example: `src/rw/bacamera.c` is labelled camera code, but its header says the functions are attributed from `docs/sky2/rw_unit_attribution.json`. `src/sce/rofs_dir.c` mixes ROFS stubs with unrelated soft-float and game-style declarations.

librw (MIT, re-implementation of RenderWare, `github.com/aap/librw`):
- Verified from README: DFF and TXD support for PS2, D3D8, D3D9, and Xbox. BSP is not supported. Rendering backends: D3D9 and OpenGL (>= 2.1, ES >= 2.0). An SDL skeleton exists (`skeleton/sdl2.cpp`, `skeleton/sdl3.cpp`).
- Not verified: per-plugin coverage for `RpSkin`, `RpHAnim`, `RpMatFX`, `RpUVAnim`, `Rt2d`, `Im2D`, `Im3D`, `RpPDS`, `RpMorph`, `RpSplines`, `RpPatch`, and sky2 pipes. The README file listing was elided at `src/`, so each plugin must be checked against `src/` directly.
- Recommendation: use librw for DFF/TXD loading and clump/hanim if coverage holds. Re-implement the sky2 render-state layer (`RpSkyRenderStateSet`, 681 calls) on OpenGL as first-party code, because sky2 state is PS2-specific. Do not copy sky2hook (no license).

## 6. libc / libm

Name-level totals (join): 16 names, 2,714 calls. The name-only pass counted 21 names, 2,764 calls.

| Function | Calls | PC replacement |
|---|---|---|
| `memset` | 581 | host `memset` |
| `memcpy` | 538 | host `memcpy` |
| `sinf` | 410 | host `sinf` |
| `sprintf` | 368 | host `sprintf` (check buffer sizes) |
| `cosf` | 204 | host `cosf` |
| `strcpy` | 143 | host `strcpy` |
| `tanf` | 136 | host `tanf` |
| `fabsf` | 89 | host `fabsf` |
| `strlen` | 68 | host `strlen` |
| `strcat` | 60 | host `strcat` (prefer `strncat`) |
| `strcmp` | 54 | host `strcmp` |
| `sqrtf` | 50 | host `sqrtf` |
| `strncpy` | 23 | host `strncpy` |
| `strncmp` | 17 | host `strncmp` |
| `qsort` | 15 | host `qsort` |
| `atoi` | 6 | host `atoi` |
| `sscanf` / `atanf` / `vsprintf` / `__sfvwrite` | 2 / 3 / 2 / 2 | host equivalents |

libm (`sinf`, `cosf`, `tanf`, `sqrtf`, `fabsf`, `atanf`) is about 890 calls. Host libm is acceptable because the PC port is a non-matching build.

Unnamed middleware helper: `func_00440b68` (478 calls). It lives in `src/middleware/middleware_inferred_004401c8.c`, next to `qsort` at `0x440BB8`. The function body is not in the worktree (`asm/` is generated and absent), so its identity is unverified. Action: disassemble from `image.bin` and identify before replacing. `[inferred]` it is a libc or ee-gcc runtime helper.

## 7. EE VU0 / macro intrinsics

First-party code calls these as functions or macros. They are not in vendor code, so there is no library to replace: rewrite the bodies as portable C.

| Name | Calls | Note |
|---|---|---|
| `effectVuLoad10` | 137 | VU0 load (effects) |
| `effectVuStore10` | 123 | VU0 store |
| `LD32`, `LD16` | 82, 61 | Unaligned loads (macros) |
| `effectVuLoad11` | 77 | |
| `M2C_FIELD` | 73 | m2c field access |
| `effectVuScale10` | 44 | |
| `addOffsetFirst` | 44 | |
| `addOff` | 25 | |
| `addOffsetAfterBase` | 23 | |
| `effectVuScale11` | 21 | |
| `addF` | 21 | |
| `effectVuUnpackColor10V0` | 19 | |
| `spawnVuAdd10` | 16 | |
| `effectVuUnpackColor10` | 16 | |
| `spawnVuMultiply10` | 12 | |
| `_pcpyld` | 12 | VU primitive |
| `effectVuStore11` | 11 | |
| `spawnVuTransform10` | 10 | |
| `spawnVuNormalize10` | 6 | |
| `novaMultiply` | 6 | |
| `effectVuSetZ10` / `effectVuSetX10` | 6 / 6 | |
| `mdlMulOrdered77810` | 5 | Game naming, VU family |
| `__asm__` | 2 | Inline asm: must be replaced |

Total: 34 names, 888 calls. The main risks are the `__asm__` sites and `_pcpyld`. The effect and spawn subsystems (`effectVu*`, `spawnVu*`) are the best first target for the portable math layer.

Other externals (not platform): `kAssertFail` 1,931 calls (assert macro; route to host abort or log), `K_ASSERT` 87, `Vpad_SetColor` 3, `RWALIGN` 10 (macro), `HCDVD_FREE` 4, `dds3GetProcessWorkData` 2, `dds3SetProcessWorkData` 2, `CameraEndUpdate` 1, `__stream_write_callback` / `__stream_read_callback` 1 each.

## 8. Vendor code footprint (definitions)

From `vendor_defs.txt` (address-marker count, not functions after linking):

| Dir | Definitions | Files | Role |
|---|---|---|---|
| `src/rw` | 465 | 35 | RW 3.7 core (grouped units) |
| `src/renderware` | 331 | 45 | RW plugins / p2 (sky2) |
| `src/cri` | 4,376 | 429 | CRI ADX / Sofdec / ROFS / file layers |
| `src/sce` | 273 | 19 | SCE libs (filestub, cdvd, pad, mc2), ROFS |
| `src/middleware` | 256 | 27 | libc, ee-gcc runtime, soft-float |

Total vendor definitions: 5,701. About 3,077 third-party functions are still `INCLUDE_ASM` (from the architecture doc).

Address clusters overlap: RW core `0x38FB10..0x43F9C8`, CRI `0x4244C8..0x52D980`, SCE/middleware scattered `0x421DA8..0x4F8CD0`. Address-only attribution is approximate; use the provenance file for SCE and the unit files for the rest.

## 9. Entry-point size estimates (PC replacement)

All estimates are `[inferred]`, from the counts above and typical sizes for the stated libraries.

| Area | Entry points | Estimate | Basis |
|---|---|---|---|
| SDL3 window, GL context, input (pad via gamepad) | libpad 9 names + `scePad*` wrappers | 600 to 900 lines | SDL3 event loop and pad mapping |
| File layer (ISO / loose files: `sceOpen`, `sceRead`, `sceDopen`, `sceDread`, `sceLseek`, `sceGetstat`) | ~40 filestub + 42 `H_Cdvd_*` | 800 to 1,200 lines | Path mapping for `cdrom0:\` and `LIB31` |
| Memory card (folder-backed `sceMc2*`) | 11 names, 47 calls | 400 to 600 lines | Folder per slot |
| Threads, sema, alarm, timers (`klib`, `timer`, `timeralarm`) | ~60 names | 300 to 500 lines | SDL3 threads or single-thread stubs |
| Sound: ADX decoder and IOP sound-driver replacement (`CRI_ADXI`, `LIBSD`) | adxt ~110, adxf ~17, ADXB header | 1,000 to 1,500 lines | ADPCM decoder + SDL3 audio stream |
| Sofdec (`mwPly*`, `MWSFD_*`) over pl_mpeg or ffmpeg | 9 named, ~200 unnamed | 600 to 800 lines + decoder | IPU/YUV-to-RGB path |
| RenderWare: librw for DFF/TXD/clumps/hanim (check coverage) + sky2 render-state layer on OpenGL | 31 named, ~4,000 calls | 4,000 to 6,000 lines | `RpSkyRenderStateSet` alone is 681 calls |
| libc / libm | 16 to 21 names | ~50 lines (host libc) | Direct mapping |
| VU0 macro replacement | 34 names, 888 calls | 800 to 1,200 lines | Portable C |

Rough total: 7,000 to 11,000 lines of new C/C++ on top of first-party code. The largest risk is the RW render layer, because sky2 state is tied to PS2 pipes and the unnamed vendor functions are not yet identified.

## 10. First-boot (title screen) milestone, ordered

Chain from `docs/architecture.md` sections 1 and 12: `kwlnBoot` (`func_001002c0`) → `kwlnInitIop` (`func_00100350`) → `kwlnInitEngine` (`func_00100670`) → `kwlnInitSubsystems` → `kwlnMainLoop` (`func_00101350`) → `kwlnRunFrame` (`func_00101270`).

1. SDL3 init and GL context. Replace the process entry and open a window. No game code change.
2. Allocator: route `jtbl_008873E8` (alloc), `jtbl_008873EC` (free), and `D_008873F4` (calloc) to host allocators. Slot layout from the architecture doc.
3. `kwlnInitIop` → state-only stub. Skip the 14 IRX modules; record module names only.
4. File layer: `H_Cdvd_AcquireDirectory` and `H_Cdvd_ReadSync` over the disc image or loose files. Include the `rofs_*` path (ROFS strings are present in the image). Map `cdrom0:\...` paths.
5. Pad: `scePadInit`, `scePadPortOpen`, `scePadRead`, `scePadGetState` to SDL3 gamepad or keyboard.
6. Memory-card boot check (sequence 30, `func_0029a0`): return "no card" first, folder-backed later.
7. `RwEngineInit` (heap `0x800000`) and the RW camera, raster, and matrix shims. Required before any draw.
8. `RpSkyRenderStateSet` on OpenGL. Required before `mainDraw` runs.
9. Thread, sema, and alarm stubs for `kwlnInitSubsystems` and the scheduler (`cldScheduler`).
10. Sound service `func_00458fa0` (`src/sdkSnd.c`): stub or SDL3 audio. Title may need sound for its loop `[inferred]`.
11. Texture loading (TXD via RW shim or librw).
12. Title draw via `kwlnRunFrame` → `mainDraw`. Verify the order against `docs/architecture.md` section 4.

Not needed for the title: Sofdec movies (`P4CT*.SFD`), memory-card UI, Event and Battle code paths `[inferred]`. Verify by tracing the title state before cutting them.

## 11. Recommendations

1. Replace SCE at the wrapper layer (`H_Cdvd_*`, `sdk*`, `h_memcard`, pad), not at the 213 raw SDK functions. Wrappers account for 942 calls and map to a few host operations.
2. Replace libc/libm with host libraries. Near-zero risk, removes about 2,700 calls.
3. Rewrite the VU0 / `effectVu*` / `spawnVu*` macros as portable C. 888 calls of pure math with no hardware dependency.
4. For RenderWare, use librw for asset formats and hanim after checking plugin coverage, and write the sky2 render-state layer as first-party code on OpenGL. Do not fork sky2hook (no license).
5. ADX and Sofdec: decode in-process. Start with pl_mpeg for Sofdec (smaller); keep ffmpeg as an option.
6. Identify `func_00440b68` (478 calls) before the libc swap, because it may be a runtime helper that needs a real replacement, not a libc alias.
7. Re-run the call join after `ThirdPartyNames` renames land, then update the counts in sections 2 to 6, including the blank caller columns in section 5.

## 12. Open items and limits

- `config/sdk_symbol_provenance.txt` header says `retail_sha1 = 4eeec036...`. The `image.bin` in `build/fp-solo-20261006` hashes to `3d1d3d2b...` (the same hash as `build/AtlusReadA/image.bin`). The provenance hash likely refers to a different artifact (possibly the executable). Not resolved; the disc and IOP strings above came from `image.bin`.
- Unnamed vendor functions (`func_` names) are the bulk of RW and CRI calls. Attribution by owner directory is `[inferred]`.
- The `asm/` tree is not generated in this worktree, so no disassembly was read.
- Caller-subsystem breakdowns are measured only for the SCE/SDK rows, `mwPly*`, and `sceMc2`. Others are omitted pending a re-run.
- No builds or runtime tests were run (phase 0; Main verifies).
- Checks Main should run: none required for this document. If re-running the counts, use the call-site scan and the provenance file on `origin/main` after `ThirdPartyNames` lands.
