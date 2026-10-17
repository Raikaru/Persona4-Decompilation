# Renderer strategy for the PC port

Author: PortRenderer (phase 0). Scope: how rendering is done on PC. Source tree: `origin/main` at `7cdaa8f1`. Counts are measured from the repo unless marked `[inferred]`.

## Verdict

**Option (c): keep the matched RenderWare 3.7 core compiled for x86, and replace only the PS2 driver layer with an OpenGL driver.** The driver layer is the sky2 driver in `src/rw/` plus the PS2 pipelines in `src/renderware/p2/` and `src/renderware/worldp2/`. Do not emulate GS/VIF/VU1 packets. Implement the PC pipelines at the RW API boundary, as sky2hook does, and keep game code unchanged except for its VU0 inline-asm sites.

Why:
1. The portable RW core is already C and nearly fully matched: `core/`, `plcore/`, `world/` are 65,773 lines with only 3 INCLUDE_ASM. The PS2-specific parts are the 13,485 lines of `p2/` and `worldp2/` plus the 10,845-line `src/rw/` driver layer (193 INCLUDE_ASM).
2. RW already dispatches immediate-mode draws through a driver table (`RwDevice`, 11 function-pointer slots). Game code reaches it directly in one place (`src/Graphics/primitive.c`).
3. The game's coupling to the sky2 GS layer is an API of 685 call sites that pass GS register words (`RpSkyRenderStateSet`). That is a small, enumerable state set (4 enum values in use, see §4), and it maps to GL state without emulating the GS.
4. The VU1 microcode behind the sky2 pipelines is not in the repo. Only INCLUDE_ASM stubs exist. A GS/VIF/VU1 interpreter would have to reverse-engineer microcode. sky2hook avoided this and reached 33/50 scenes at MAD < 10 with an RW-level renderer (§6).

Rejected:
- **(a) librw**: a re-implementation with a different API. It needs a source-level rewrite of all 218 first-party files that touch RW APIs, and it has no RpSky state API. Its PS2 support is partial (§5).
- **(b) our own RW-compatible renderer over GL, replacing RW core**: discards 65,773 lines of matched C and reimplements frames, clumps, atomics, cameras, rasters, and streams. The 700 first-party functions that touch Rw/Rp/Rt APIs would have to keep the same semantics. Most work of the three.
- **(c') keep the PS2 `p2/` pipelines and interpret their GS/DMA packets**: needs a VIF1 + GIF + VU1 interpreter. The VU1 microcode is not in the repo, so this is reverse-engineering on top of the port. Rejected unless VU1 is recovered first.

Effort estimates: [inferred] (c) is the smallest of the three because it keeps the matched core and replaces roughly 24,000 lines of PS2-driver C with GL C, plus a state mapper.

## 1. First-party renderer surface (measured)

Scope: first-party `src/` excluding `src/rw`, `src/renderware`, `src/cri` (945 `.c`/`.h` files scanned). Function counts use the deduped 6,860-address census.

| Category | Functions | Files | Notes |
|---|---:|---:|---|
| RpSky render state (`RpSkyRenderStateSet`/`RpSkyRenderState`/`RpSkyTexGetTex0`) | 150 | 75 | 685 occurrences of `RpSkyRenderStateSet` in 79 files |
| VU0 inline asm (VU/EE macros) | 120 | 43 | 869 asm lines; top: `qmtc2.ni` 277, `lqc2` 241, `sqc2` 234, `vmulx.xyzw` 198 |
| RwIm2D / RwIm3D / RwRenderState / RwCameraClear | 43 | 26 | `RwIm2D*` 23 occ. / 10 files; `RwIm3D*` 11 / 1 |
| GS packet builders (`src/Kernel/h_malloc.c`) | 9 | 4 | misnamed file; `gsBuildTextureUploadPacket`, `gsPackDmaTag`, `gsPackGifTag`, ... |
| Any Rw/Rp/Rt identifier | 700 | 218 | includes camera, frame, atomic, anim, stream APIs |

Functions touching at least one renderer category: **785 of 6,860 (11.4%)**.

Direct API occurrences (first-party):

| Symbol | Occurrences | Files |
|---|---:|---:|
| `RpSkyRenderStateSet` | 685 | 79 |
| `mcSetSkyRenderState` | 20 | 1 |
| `RwIm2D*` | 23 | 10 |
| `RwIm3D*` | 11 | 1 |
| `RwCameraBeginUpdate` / `RwCameraEndUpdate` | 2 / 2 | 1 |
| `RpAtomicRender` | 1 | 1 |
| `RpAtomicSetRenderCallBack` / `RpAtomicGetRenderCallBack` | 0 / 0 | 0 |
| `RwRasterShowRaster` / `RwCameraShowRaster` | 0 | 0 |
| `RwRenderStateSet` | 0 | 0 |
| `sceGs*` | 0 | 0 |
| `SCE_GS_*` | 6 | 1 |
| `tmxDecodeStream` / `tmxLoadFile` | 6 | 3 |
| `tmxUploadStream` | 7 | 3 |
| `sceDmaSync` / `sceGsSyncVCallback` | 1 / 1 | 1 |

Reading: the game does not call the RW frame/present API much. Draws happen through the game's sprite and primitive helpers, which go to the RW device table. 3D models go through `mdlQueueModelForDraw` and `mdlDrawVisibleAtomics`, with atomic callbacks through `RpClumpForAllAtomics` (62 call sites).

Game code calls no RxPipeline API directly. All `RxPipeline*` references are inside `src/renderware/` (`p2/`, `world/`). The pipeline engine is internal to RW.

2D draw path: `shdSpriteDrawNow` (32), `shdSpriteDrawNowEx` (30), `PrimDrawFlatRectangle` (16), `sdkSpriteDrawAt` (15), `sdkSpriteDrawSized` (9), `sdkSpriteDraw` (5), `PrimDrawPoints` (7), `PrimDrawFlatTriangle` (5), `frFontExDrawTextWithCharWidth` (3). These end at `rwGlobals.device.fpIm2DRenderPrimitive` (`src/Graphics/primitive.c:422`) and `RwIm2DRenderPrimitive` (`src/Kosaka/k_spipe.c:214`).

## 2. RW driver seam (measured)

- `rwGlobals` is at `0x008872d8`. `src/Graphics/primitive.c:100-165` mirrors the device fields used by game code: `setRenderState` (0x18), `getRenderState` (0x1c), `fpIm2DRenderPrimitive` (0x28), `zBufferNear`/`zBufferFar` (0x14/0x10 relative to device).
- Game-side device users: `setRenderState` 3, `getRenderState` 1, `fpIm2DRenderPrimitive` 2, `zBufferNear` 1, `zBufferFar` 1.
- `RwDevice` (matched 3.7 in `include/rw/plcore/badevice.h` ~235-262; identical in `include/rw/sky2/rwplcore.h` ~5750-5780) has 14 members, of which **11 are function pointers**: `fpSystem`, `fpRenderStateSet`, `fpRenderStateGet`, `fpIm2DRenderLine`, `fpIm2DRenderTriangle`, `fpIm2DRenderPrimitive`, `fpIm2DRenderIndexedPrimitive`, `fpIm3DRenderLine`, `fpIm3DRenderTriangle`, `fpIm3DRenderPrimitive`, `fpIm3DRenderIndexedPrimitive`. The other three are `gammaCorrection`, `zBufferNear`, `zBufferFar`.
- RW core dispatches through `RWSRCGLOBAL(dOpenDevice).fp*` (macros in `include/rw/plcore/baimmedi.h:350-363`, `include/rw/inc/rwplcore.h:5616-5629`).
- Raster, camera, and engine driver functions are not counted yet. [unmeasured]

Consequence: a GL driver only needs to fill these 11 function pointers, plus the raster, texture, camera-clear/show, and light/atomic driver hooks that RW core calls. The hooks themselves are not enumerated here.

## 3. Build configuration to preserve

`config/version_flags.txt:27` (matched RW build):

- `cw3.0.1b119 -O4 -inline auto -DRWBUILDNUMBER=55 -DSKY2_DRVMODEL_H` and include order `include/rw/std`, `ps2`, `plcore`, `core`, `p2`, `drvcommon`, `drvnull`, `world`, `worldp2`, `p2null`, `worldp2null`, `inc` (3.7 headers last).
- `-DSKY2_DRVMODEL_H` picks the PS2 Im3D global layout (`curPool` at 0x40, `CorePluginAttach` registers 0x7c bytes) without the RW 3.5 sky2 headers. The file notes that 3.5 headers break 61/62 matched world functions.
- RW chunk headers are written with build number 55.

For the PC build, keep these settings: 3.7 headers, `RWBUILDNUMBER=55`, `SKY2_DRVMODEL_H`, and the null driver model for everything except the replaced driver. Layout constants differ between headers: `rwMATRIXALIGNMENT` is 4 in 3.7 (`include/rw/inc/rwplcore.h:167`) and 16 in sky2 (`include/rw/sky2/rwplcore.h:225`); `sizeof(RwFrame)` is 164 (null) vs 176 (sky2). Use the layouts the retail build used, which the matched build flags already encode. [inferred]

## 4. RpSky render-state mapping

`RpSkyRenderState` (`include/rw/sky2/rwcore.h:5685-5715`):

| Value | Name | Meaning |
|---:|---|---|
| 0 | `NARENDERSTATE` | sentinel |
| 1 | `DITHER` | 0 off, 0x55555555 half, else on |
| 2 | `ALPHA_1` | raw GS `ALPHA_1` register word |
| 3 | `ATEST_1` | low 16 bits of `TEST_1` |
| 4 | `FARFOGPLANE` | fog far plane; 0.0 if unset |
| 5 | `MAXMIPLEVELS` | max 7 |

Game code passes raw GS words: `src/Graphics/primitive.c:382` `RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, 0x48)`; line 383 `ATEST_1 0x71801`. Mapping plan [inferred]:

- decode `ALPHA_1` into GL blend equation/factors (A, B, C, D, FIX);
- decode `TEST_1` into an alpha-test threshold and function;
- `DITHER` and `FARFOGPLANE` map to shader uniforms;
- `MAXMIPLEVELS` maps to the GL sampler LOD clamp.

`RpSkyRenderStateSet` has no C definition in `src/rw` or `src/renderware`. `config/symbol_addrs.txt` maps it to `0x003F6440`. Its body is in the retail image only. [unmeasured]

## 5. Option (a): librw

Source: librw README at commit `169a45aa` (`https://github.com/aap/librw/blob/169a45aa/README.md`) and issue #127.

- Reads DFF and TXD for PS2, D3D8, D3D9, Xbox. PS2 read support is partial: "not all pre-instanced PS2 DFFs are supported".
- No BSP support.
- Backends: D3D9 and OpenGL (>= 2.1, ES >= 2.0). Rendering "some things on the PS2 is working as a test only".
- Used by re3 as an RW replacement. Its author notes re3 is dead, and that GTA III does not use librw and is "not easy to make compatible".

Blockers for P4:
1. librw is C++ with a re-implemented API. Game code calls RW's C API across 218 first-party files. Porting is a source-level rewrite, not a link swap.
2. No RpSky state API, so the 685 call sites need their own shim regardless.
3. Pre-instanced PS2 native geometry is only partly supported. Whether P4 uses it is unmeasured (§8).

## 6. sky2hook as reference

Source: `https://github.com/tge-was-taken/sky2hook`. C++, with no LICENSE file. The author has since given permission to reuse parts of it ("feel free to reuse parts of it", [issue #2](https://github.com/Raikaru/Persona4-Decompilation/issues/2#issuecomment-6234440298), 2026-10-17). The port records the grant and its attribution rules in `third_party/README.md`.

- Status: abandoned experiment. OpenGL renderer that hooks RW 3.x sky2 entry points: Im2D/Im3D, Rt2d, PTank, rasters, lights, cameras, atomics, world sectors. Does not run a game alone; host is PCSX2 (headless) with a hook DLL.
- Tested on P3 FES, P4, Sonic Heroes PAL, Shadow; 50 scenes; **33/50 under MAD 10**, worst ~42.
- Emulates GS blend, alpha test, destination alpha, fog, and feedback at PS2 resolution.
- VIF1 unpack emulation only for pre-instanced native meshes (`src/pipelines/sector/vif.cpp`). Everything else is decoded from RW structs.
- Layout: `src/pipelines/{atomic,im2d,im3d,rt2d,sector}`, `src/rw_to_gl.cpp`, `src/texture_decoder.cpp`, `src/state.cpp`, GLSL shaders.

Lessons for us: the RW-level draw path is enough for most scenes; the hard part is the GS state machine and pre-instanced geometry.

## 7. Asset path

- Game textures are TMX (custom container). `src/Kernel/sdkUttmx.c`: `tmxDecodeStream` (line 308) produces an `RwImage` through portable code (4/8-bit indexed with palette via `tmxUnpackNibbles`, `tmxConvertPalette`, `tmxSwizzlePalette8`; RGB/RGBA via `tmxConvertRgb`/`tmxConvertRgba`). Reuse this for PC: `tmxDecodeStream` → `RwImage` → GL texture.
- `tmxLoadFile` (line 449) is portable. `tmxImageWriteCallback` (473) is portable.
- `tmxDmaCopy` (489) uses DMA8/DMA9 with a 16 KiB scratchpad: PS2-only, replace.
- `tmxUploadStream` (623) uploads to GS VRAM. Header byte 0x16 = format code, 0x11 = palette selector, u16 width at 0x12, u16 height at 0x14. PS2-only, replace with GL upload. Users: `src/Graphics/Effect/tnEffect.c` (4), `src/sdkWrap.c` (2), `sdkUttmx.c`.
- GS packet builders (`src/Kernel/h_malloc.c`: `gsUploadRasterTiles` FUN_00143BA0, `gsBuildTextureUploadFixedStride` FUN_00143C90, `gsBuildTextureUploadPacket` FUN_00143CF0, `gsPackDmaTag` FUN_00143F90, `gsPackGifTag` FUN_00144000), called from `src/Kosaka/Field/k_fldrc_inferred_00468d10.c:668`: PS2-only, replace.
- `sceGsSyncVCallback` (`src/cri/libadxe/adx_mps2.c:74`) and `sceDmaSync` (`src/promoted/code1_0041.c:674`): PS2-only sync, replace.
- Retail RW TXD/DFF rasters: whether they are PS2-native (GS formats) or standard has **not** been measured. See §8.

## 8. Unmeasured or unknown

1. **Raster format (partially measured).** RMD texture dictionaries (`rwID_TEXDICTIONARY` 0x16) hold 23,335 `rwID_TEXTURENATIVE` (0x15) chunks in 4,803 TXDs (extraction scan, §12.7). The TXD STRUCT second `u16` is 6 in all 4,803, and the first `u32` of each native chunk is 1 in all 23,335. Under the `RwPlatformID` enum (`include/rw/inc/rwplcore.h:2132-2145`) those are `rwID_GAMECUBE` and `rwID_PCD3D7`, not `rwID_PS2` (4). They are probably not platform IDs [inferred]; their meaning stays unverified until the native read path (`stdFunc` slot 26, `rwSTANDARDNATIVETEXTUREREAD`, `badevice.h:117-119`) is identified. TMX (680 files) is not RW; all 680 have word 2 at +0 and `TMX0` at +8.
2. **Pre-instanced native geometry: answered, generic.** In the 4,889 RMDs the walker parsed, all 17,337 geometry STRUCT format words have `rpGEOMETRYNATIVE` (0x01000000) clear, so no geometry is pre-instanced VIF data. This holds in every sampled class: field (`FIELD/RMD` 1,544 structs; `FIELD/GRMD` 30), character (`MODEL/NPC` 6,640; `MODEL/NPC2` 2,464; `MODEL/PERSONA` 1,187; `MODEL_BTL/PERSONA` 1,252), and weapon (`MODEL/WEAPON` 1,551). No RMD lives under `TITLE/` or `BUSTUP/`; UI uses TMX. 157 RMDs (3%) did not parse with the walker; not investigated.
3. **Driver hook count.** `src/rw` driver stubs are 177 INCLUDE_ASM in sky2 units (193 across `src/rw`). Repeated `func_003e12f0 … func_003efda0` lines are macro lines, not separate functions. Real function count not measured.
4. **Present path: traced to the stdFunc slot; implementation not found.** `RwCameraShowRaster` (`src/renderware/core/bacamera.c:1896`) calls `RwRasterShowRaster(camera->frameBuffer, dev, flags)` (`baraster.c:1092`), which purges the resource cache and calls `stdFunc[rwSTANDARDRASTERSHOWRASTER]` (slot 20, `badevice.h:112`). No driver function registers slot 20 in `src/`, `config/`, or `asm/`, and there are no `DispEnv`, `DBuff`, or `sceGsSetDefDBuff` matches in `src/`. The PS2 flip is therefore in an unnamed driver function [unverified]. The GL port implements slot 20 as the window swap.
5. **VU1 microcode.** No VIF/GIF/DMA token matches in `src/rw`, `src/renderware`, or `src/cri` (named tokens). Since model geometry is generic (item 2), model data needs no VU1 path [inferred].

## 9. Sizing (measured)

| Group | Files | Lines | INCLUDE_ASM | Port action |
|---|---:|---:|---:|---|
| `src/renderware/core` | 17 | 23,033 | 0 | keep, compile for x86 |
| `src/renderware/plcore` | 20 | 15,102 | 3 | keep, compile for x86 |
| `src/renderware/world` | 11 | 27,638 | 0 | keep, compile for x86 |
| `src/renderware/p2` (PS2 pipes) | 12 | 11,986 | 0 | replace with GL pipelines; keep as spec |
| `src/renderware/worldp2` (PS2 world pipe) | 1 | 1,499 | 0 | replace with GL world pipeline |
| `src/rw` (sky2 driver + RW units) | 36 | 10,845 | 193 | replace driver units with GL driver |

Sky2 driver units by INCLUDE_ASM count: `basky.c` 46, `skyinst.c` 19, `badma.c` 18, `texcache.c` 15, `palquant.c` 15, `skyblit.c` 12, `skyconv.c` 10, `imrascnv.c` 8, `rpuvanim.c` 15, `rtanim.c` 8, `baimage.c` 5, `baskytran.c` 1, `bapipe.c` 1, `skinskycommon.c` 1, `p2core.c` 1, `p2define.c` 2, `baraster.c` 2, `baresamp.c` 3, `baevent.c` 2, `rwgrp.c` 1, `batextur.c` 1, `rpskin.c` 2.

Also in scope for any option: 120 first-party functions with VU0 inline asm (43 files), which need C equivalents on PC regardless of renderer choice [inferred].

## 10. First milestone: title screen 2D

Goal: the title screen renders correctly through the GL driver with no 3D pipelines.

Path:
1. `shdSpriteDrawNow*` / `PrimDrawFlatRectangle` → `rwGlobals.device.fpIm2DRenderPrimitive` (`src/Graphics/primitive.c:422`) → GL immediate-mode replacement (vertex buffer + shader).
2. Render states: `RpSkyRenderStateSet` ALPHA_1 (0x48) and ATEST_1 (0x71801) at `primitive.c:382-383` → GL blend and alpha test. Implement only the bits these two words use.
3. Textures: TMX → `tmxDecodeStream` → `RwImage` → `RwRaster` → GL texture (texture driver hook; replaces `texcache.c`, `palquant.c`, `imrascnv.c` for this path).
4. Camera: `RwCameraBeginUpdate`/`RwCameraEndUpdate` (2 each), `RwCameraClear` (7) → GL clear.
5. Present: swap buffers on SDL3/GL (§8.4 is unresolved; trace the present call first).

Acceptance: title frame matches a reference capture from PCSX2 at the same resolution, measured by pixel diff. Reference capture method not yet defined [inferred].

Out of scope for milestone 1: 3D atomics, world sectors, particles, VU0 math.

## 11. Checks for Main to run

- Count check: re-run the first-party census with `src/rw`, `src/renderware`, `src/cri` excluded (done here with Python on `build/PortRenderer/src`).
- Extract retail TXD archives and classify rasters (§8.1).
- Trace `RwCameraShowRaster`/present (§8.4).
- Decide the pre-instanced geometry question (§8.2) before committing to any librw experiment.

## 12. Asset pipeline

Options: (a) runtime reads the user's disc; (b) one-time install converts the disc to PC-native data; (c) (a) or (b) plus a replacement-override layer.

### 12.1 Formats

- **RMD** (model scene), measured in repo and Amicitia wiki. Criterion RenderWare 3.7.0.2 node-based format; holds all 3D assets of the PS2 P3/P4 builds, including textures and animations. Game paths: `field/rmd/m%03d_%03d.RMD` and `field/grmd/fobj%03d.RMD` (`src/Kosaka/k_command.c:561-574`), created by `K_Cmd_CREATE_FLD_MDL` (line 576).
- **TMX** (texture): `tmxDecodeStream` (`src/Kernel/sdkUttmx.c:308`), see §7.
- **ROFS** archives by name, reference counts in first-party `src/`: `rofs_mai` 36, `rofs_if` 27, `rofs_pfs` 16, `rofs_hn` 8, `rofs_dir` 7, `rofs_cvmh` 1. Archive directory and file-table layout not read [unverified].
- **`world.rws`** is written by `src/renderware/world/babinwor.c:1421` (`RwStreamOpen`, write mode). That is a dump in the RW core, not a game asset read.

Correction to the earlier notes: game-side loaders do not call RwStream APIs, but they parse a RenderWare chunk stream themselves. Measured chain:

1. `mdlCreateModelObjectFromData` (`src/Graphics/Model/mdlManager.c:4268`) → `mdlSetAuxResource` (`:6098`) → `H_Cdvd_AcquireDirectory` (`src/Kernel/sdkCdvd.c:232`). The resource is a path handed to the disc layer.
2. `mdlAdvanceAuxLoad` (`src/Graphics/Model/mdlFile_inferred_0047ce00.c:66`) waits for the file (`H_Cdvd_IsFileLoaded`), gets archive entries (`H_Cdvd_GetArchiveEntry`, `sdkCdvd.c:488`), and steps the aux state machine (0 → 1 → 2).
3. `mdlReadAuxChunks` (`mdlManager.c:6161`) walks the chunk stream and dispatches texture dictionary, animation, UV dictionary, effect list, material and clump chunks. The helpers it calls (`func_003e2ce0`, `func_003e2f60`, `func_004667d0`, `func_003ef1b0`, …) are unnamed in `config/symbol_addrs.txt`, so the chunk parser's identity is unresolved [unverified].
4. `mdlPrepareModel` (`mdlManager.c:4408`) is the readiness state machine; it sets flag `0x1000` once the aux load completes.

### 12.2 What game code needs from loaded objects

Counts in `src/Graphics/Model/mdlManager.c` only (the file that holds the loader): `RwMatrix` 130, `RtAnimInterpolator` 47, `RtQuat` 33, `RpClumpForAllAtomics` 25, `RtAnimAnimation` 16, `RpSkyRenderStateSet` 16, `RtAnimInterpolatorSetAnimLoopCallBack` 13, `RpMaterial` 9, `RpMatFXMaterialGetEffects` 9, `RpHAnimHierarchy` 7, `RwTexDictionary` 5.

So the game needs: clump, frame and atomic traversal; materials with MatFX; HAnim hierarchies; HAnim animation interpolators with loop callbacks; texture dictionaries; and per-material sky render state (PS2 only, replaced by the GL driver). Plus the aux block (+0x2C/+0x30 data pair, +0x38 file handle, +0x40 mode) and object flags `0x1000`/`0x2000`/`0x4000`. Pipeline IDs and user data were not counted.

### 12.3 librw uninstance of PS2 native data (checked in librw master source)

Partly supported.

- `src/ps2/ps2.cpp`: `readNativeData` keeps per-mesh VIF DMA blobs (`InstanceData`, `fixDmaOffsets` / `unfixDmaOffsets`).
- `objUninstance` (line 873) turns those blobs into generic geometry through each material pipeline's `uninstanceCB`. The default pipeline (`makeDefaultPipeline`, line 1124) uses `genericUninstanceCB` (line 993), which covers XYZ/XYZW, normals, RGBA, UV/UV2 and skin weights (mask `0x10000`).
- Known gaps in the fetched code: `// TODO: figure out scaling` for normals (line ~1007); the skin uninstance callback is commented out in `rwps2.h:206`; only the default pipeline is registered in this file.
- Rasters: `unswizzleRaster` (`ps2raster.cpp:1371`) and `rasterToImage` (`:1707`) handle the PS2 swizzle. The format list covers PSMT4, PSMT8, PSMCT32, PSMCT16, PSMCT24 and the Z formats.
- Target version: librw's PS2 path targets earlier RW streams. RMD is RW 3.7.0.2, so its chunk layout may differ [inferred]. librw is not a drop-in decoder for P4.

### 12.4 Community tools

- **Amicitia** (`tge-was-taken/Amicitia`, C#). Measured from the repo tree: a full RW node parser under `AmicitiaLibrary/Graphics/RenderWare/` (`RWGeometryStructNode`, `RWMeshListNode`, `RWTextureNativeStructNode`, and the sky-specific `RWSkyMipMapValueNode`), TMX and PAC wrappers, and `RMDSceneWrapper`. It exports Assimp models, imports FBX replacements, and converts PNG to TMX or RMD. The RMD wiki says it covers PS2 P3/P4. Whether it decodes PS2 VIF native mesh data into generic geometry is unverified: the tree has no VIF or VU file, and the geometry nodes are generic, so the answer is [inferred] either way.
- **RMD MaxScript** (3ds Max) loads skinned meshes, textures, bones and animations from RMD and PAC files (per the Amicitia wiki).

### 12.5 Options and costs

(a) Runtime reads the user's disc.

- Keeps retail data exact; nothing to keep in sync with a converter.
- Needs a decoder at load time: TMX (`sdkUttmx.c`, already portable) and the RMD chunk stream (already parsed by matched `mdlReadAuxChunks`). RMD geometry is generic (§8.2), so the librw-style VIF uninstance (librw `ps2.cpp`, 38 KB of C++ [measured]) is not needed for model data; the open item is the raster format (§8.1).
- Verification is per pipeline against retail output.

(b) One-time install converts the disc to PC data (uninstanced RW geometry and textures, or glTF/PNG/KTX2 plus sidecar data).

- Runtime is simpler and loads are faster; textures can be PNG or KTX2.
- glTF cannot carry MatFX, toon, user data, pipeline IDs or the HAnim tree, so those need sidecars.
- The converter must cover every RMD chunk the game reads. A converter bug shows up only as a wrong scene, so each output needs checking against retail.
- The user supplies the disc in (a) and (b) alike, so no assets are redistributed.

(c) (a) or (b) plus an override layer.

- Override keyed on the archive path (for example `field/rmd/m001_000.RMD`) or on the TMX name. A loose PNG, KTX2 or RMD takes precedence over the archive entry.
- Cost: one path lookup in the file layer. `H_Cdvd_AcquireDirectory` (`sdkCdvd.c:232`) is the single disc entry point used by the model loader, so this is the natural hook [inferred].

### 12.6 Recommendation

Option (c): start with (a) for the runtime path and add the override hook from day one. The matched RW core and `mdlReadAuxChunks` already consume the RMD chunk stream, so (a) reuses matched code. (b) would duplicate the parser in a converter and lose data at the boundary. Add (b) later only as a load-time cache if loading becomes a bottleneck.

Milestones: (1) TMX-only, which is the title screen (§10). (2) One field RMD (`field/rmd/m*.RMD`) through `mdlReadAuxChunks` → uninstance → GL. Step 2 needs a sample RMD. The retail `image.bin` in `build/fp-solo-20261006` holds the ROFS data but has not been extracted (§8.1 has the same gap).

### 12.7 Disc measurements and open items

- **ROFS layout (measured).** Five containers at the disc root: `DATA.CVM` (3,001,540,608 bytes), `BTL.CVM` (321,630,208), `BGM.CVM` (248,064,000), `ENV.CVM` (26,005,504), `ZZZZZ.BIN` (777,816,064). Each starts with a 0x800-byte `CVMH` header (ROFS string at 0x34, `ROFSBLD Ver.1.52`) and embeds an ISO9660 image at base 0x1800; directory LBAs are relative to that base. Total 14,564 embedded files, 4,358,695,057 bytes. Per container: DATA 8,631; BTL 1,750; BGM 107; ENV 66; ZZZZZ 4,010.
- **Directory layout.** DATA: BUSTUP, CAMP, CARD, CUTIN, DICT, EFFECT, EVENT, EVENT_DATA, FACILITY, FIELD, FONT, HELP, INIT, MEMCARD, MODEL, OPED, SCHEDULER, SFD, SMAP, SOUND, SPU, TEST, TITLE. BTL: BATTLE, MODEL_BTL, SKILL. ZZZZZ: BATTLE, MODEL, SKILL, SND_BENC. The game path `field/rmd/m%03d_%03d.RMD` is consistent with `FIELD/RMD/` on the disc [inferred].
- **RMD (measured).** 5,046 files by extension scan (DATA 2,541 including 3 odd names; BTL 256; ZZZZZ 2,248; the per-container sum is 5,045, so one file is unresolved). Layout: a 2-byte `0xF0F000F0` wrapper, then an RW stream from offset 0xE holding a texture dictionary (`0x16`), a clump (`0x10`), an HAnim animation (`0x1B`), and Criterion trailer chunks (`0xF0F0000x`). Top-level counts over all RMDs: `0x16` 4,803; `0x10` 4,940; `0x1B` 29,352.
- **TMX (measured).** 680 files: DATA CAMP 357, CARD 281, FIELD 11, FACILITY 4, OPED 2, EFFECT 1, FONT 1, SMAP 1; ZZZZZ BATTLE 21; BTL BATTLE 1. All have word 2 at +0 and `TMX0` at +8.
- **Field, character, UI samples.** Field: `FIELD/RMD` (375 files), `FIELD/GRMD` (8). Character: `MODEL/NPC` (1,872), `MODEL/NPC2` (637), `MODEL/PERSONA` (256), `MODEL_BTL/PERSONA` (256). UI: TMX only. Geometry is generic in all of them (§8.2).
- **Still unmeasured.** Identity of `func_003e2ce0`, `func_003e2f60`, `func_004667d0`; the native-texture read and show-raster driver functions (§8.1, §8.4); the meaning of the RMD `0xF0F000F0` word; the 157 unparsed RMDs; Amicitia's PS2 mesh decoding; licences for librw and Amicitia (not checked; no code copied).
