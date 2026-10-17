# Host-build census and data-strategy probe (Phase 0)

Scope: how far the first-party and third-party C in `origin/main` (commit `7cdaa8f1`) gets when compiled for a 32-bit Linux host, what blocks it, what the link surface looks like, and whether retail data can be used at its original addresses. Nothing in the repo was changed; all scripts and outputs are scratch on `fates-vps` (container `p4census`, `/w` = `/tmp/p4c`).

Labels: measured = produced by a script in this census. `[inferred]` = not measured.

## 1. Environment

- Host: `fates-vps`, Ubuntu 24.04 x86_64, image `p4-decomp-ci:latest` with `gcc-multilib libc6-dev-i386 clang lld` added in container `p4census`.
- Compilers: gcc 14.2.0 `-m32`, clang 19.1.7 `-m32` / `--target=i386-linux-gnu`.
- Windows workstation: no 32-bit toolchain (mingw64 and x64 clang only), so no Windows-side compile or `VirtualAlloc` probe was run.
- Include base matches the real build: `-Iinclude` only (`build.py:128`). Regimes come from `config/version_flags.txt` (`cw3.0.1b119` for RW, `eegcc296` for CRI, `eegcc296re4` for RE4). Unit regime is taken from `config/compiler_units.txt` (339 units: 68 cw, 271 re4) and `config/gcc_units.txt` (407).

Two compile modes:

- **raw**: repo sources and headers exactly as in the tree, plus `-m32`.
- **shim**: mirrored copy at `/w/shim` with three mechanical transforms:
  1. `__int128` → `long long` via `compat/port_compat.h` (under `#ifdef P4_CENSUS_SHIM` only).
  2. `asm <type> name(args) {` function definitions (430 matched, any return type; 316 `asm void` definitions in 62 files) → plain prototype, body dropped.
  3. `mode(TI)` → `aligned(16)`. This is a census artifact: it puts 16-byte alignment on a 4-byte typedef (e.g. `btlMain.c:97`, `typedef unsigned int u_long128 __attribute__((mode(TI)))`). The alignment-of-array-elements errors in §3.3 come from this.

Shim results therefore show what remains once the three syntax-level blockers are removed. They say nothing about asm bodies or ABI.

## 2. Compile census (1540 `.c` files in `src/`)

Compile-only (`-fsyntax-only`-equivalent) per file, grouped by origin. `GENERATED` = `src/generated/*.c` (125 m2c drafts, includes `include/type.h` and a vendor header that is not in the tree, so they cannot build under repo flags; excluded from link and error gating).

Raw:

| group | files | gcc: files with errors / errors | clang: files with errors / errors |
|---|---:|---:|---:|
| FIRST | 773 | 262 / 563 | not tabulated |
| CRI | 169 | 109 / 270 | not tabulated |
| CRI-re4 | 329 | 0 / 0 | not tabulated |
| RW | 97 | 1 / 1 | not tabulated |
| MIDDLEWARE | 27 | 1 / 3 | not tabulated |
| SCE | 20 | 8 / 12 | not tabulated |
| GENERATED | 125 | 125 / 125 | 125 / 125 |

Totals: gcc rc0 1034, 506 files with errors. clang rc0 1099, 441 files with errors (clang also emits 1767 `-Wdeprecated-non-prototype` warnings in 224 files, not counted as errors).

Shim:

| group | files | gcc: files w/ errors / errors | clang: files w/ errors / errors |
|---|---:|---:|---:|
| FIRST | 773 | 115 / 342 | 197 / 1939 |
| CRI | 169 | 2 / 2 | 2 / 2 |
| CRI-re4 | 329 | 0 / 0 | 0 [inferred: none listed] |
| RW | 97 | 1 / 1 | 2 / 5 |
| MIDDLEWARE | 27 | 0 / 0 | 1 / 15 |
| SCE | 20 | 0 / 0 | 0 / 0 |
| GENERATED | 125 | 125 / 125 | 125 / 125 |

Totals: gcc shim rc0 1297, 243 files with errors. clang shim rc0 1214, 326 files with errors.

Excluding GENERATED, the per-file script (`perfile.py`) finds 118 gcc files and 201 clang files with errors in shim mode.

### 2.1 Raw top classes

gcc:

- 241 `unable to emulate 'TI'` (156 files): `mode(TI)` is not supported by gcc.
- 125 `include/type.h: No such file` (generated).
- 121 `'__int128' not supported` (112 files).
- 88 `expected '(' before 'void'` (48 files): `asm void` definitions.
- 41 implicit declaration `scrSetReturnInt`.
- `expected '(' before 'u32'/'int'/'u8'/'u64'` (27/22/11/9).
- 14 `RwV3dNormalize` pointer; 7 `RpSkyRenderStateSet`; `size of array 'SceneRootExtent' is negative`.

clang:

- 1767 `-Wdeprecated-non-prototype` (warnings, 224 files).
- 1540 `unknown register name '$vf…' in asm` (89 files).
- 409 `expected 'X' after top-level asm block` (74 files).
- 408 `expected expression` (73 files).
- 268 `conflicting types` (89 files).
- 125 generated file not found; 121 `__int128` (112 files).
- 87 `invalid output constraint` (78 files).
- 66 C11 typedef redefinition (54 files); 63 function declaration without prototype (23 files).
- 42 constant conversion (`mpv_vlc.c`); 28 incompatible function-pointer types (`btlAICommand.c`); 16 unknown `__builtin_*`.

Host-compiler facts behind these (probed on `-m32`):

- gcc and clang both reject `__int128`. gcc rejects `mode(TI)` ("unable to emulate 'TI'"); clang accepts it.
- Both reject `asm void`. clang rejects `void (*fn)(...)` and the `"$vf10"` clobber. gcc `-fsyntax-only` does not check asm clobbers or assemble asm strings, so **gcc clean does not mean asm bodies would assemble on x86**. [inferred] The `$vf` clobbers are EE VU0 registers.

### 2.2 Shim per-kind residual (excluding GENERATED; `perfile.py` from logs)

gcc (118 files, 345 diagnostic lines):

| count | files | kind |
|---:|---:|---|
| 193 | 85 | conflicting types for 'X'; have 'X' {aka …} |
| 65 | 9 | incompatible implicit declaration of function 'X' |
| 48 | 14 | conflicting types for 'X'; have 'X' |
| 28 | 25 | alignment of array elements is greater than element size (transform artifact, §1) |
| 3 | 3 | too few arguments to function 'X' |
| 3 | 1 | assignment to expression with array type (`effObjectParticle.c`) |
| 2 | 2 | static declaration follows non-static (`btlTarget.c`) |
| 1 | 1 | lvalue required (`frFontRaster.c`) |
| 1 | 1 | section attribute on local variable (`promoted/code1_0012.c`) |
| 1 | 1 | too many arguments (`promoted/code1_0042.c`) |

clang (201 files):

| count | files | kind |
|---:|---:|---|
| 1540 | 89 | unknown register name 'X' in asm (VU0 `$vf` clobbers) |
| 268 | 89 | conflicting types for 'X' |
| 87 | 78 | invalid output constraint 'X' in asm |
| 27 | 25 | size of array element isn't a multiple of its alignment (transform artifact, §1) |
| 9 | 4 | redeclaration with a different type |
| 3 | 3 | ISO C requires a named parameter before 'X' (`Event/mt_misc.c`, `Main/logoDraw.c`) |
| 3 | 1 | array type not assignable (`effObjectParticle.c`) |
| 2 | 2 | too few arguments (`btlAction_inferred_001a1450.c`, `effGeometry.c`) |
| 2 | 2 | static declaration follows non-static (`btlTarget.c`, `cri/libadxe/dvci.c`) |
| 2 | 1 | negative-size array (`mdlEffect_inferred_00484bb0.c`) |
| 1 | 1 | assignment to cast (`frFontRaster.c`) |
| 1 | 1 | return-mismatch (`itfMesManager.c`) |
| 1 | 1 | too many arguments (`promoted/code1_0042.c`) |

### 2.3 Residual files (top by error count)

The full per-file lists (118 gcc rows, 201 clang rows, each with group, count, dominant kind) are at `/w/census/out/shim/perfile_gcc.md` and `perfile_clang.md` on `fates-vps`. Not committed, per the one-file commit scope. Top of each:

gcc, shim:

| file | errors | dominant kind |
|---|---:|---|
| `src/Battle/btlEffect_inferred_001e7400.c` | 44 | implicit decl `scrSetReturnInt` |
| `src/Battle/btlAction_inferred_001a1450.c` | 33 | implicit decl |
| `src/promoted/code1_003c.c` | 25 | conflicting types |
| `src/Graphics/Model/mdlManager.c` | 17 | implicit decl `func_003d5830` |
| `src/nmCmdList_inferred_00353b50.c` | 12 | conflicting types |
| `src/Kosaka/Field/k_shadow.c` | 9 | implicit decl |
| `src/cmmRankUp.c` | 9 | implicit decl `kwlnTaskGetWork` |

clang, shim:

| file | errors | dominant kind |
|---|---:|---|
| `src/Graphics/Effect/effPolygonFlash.c` | 142 | unknown register `$vf` in asm |
| `src/Graphics/Effect/effPolygonThunder.c` | 89 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_0048f5c0.c` | 71 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_00494740.c` | 60 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_00485b20.c` | 48 | unknown register |
| `src/Graphics/Effect/effParticle.c` | 47 | unknown register |
| `src/Graphics/Effect/effPolygonWind.c` | 46 | unknown register |
| `src/Battle/btlAction_inferred_001a1450.c` | 43 | conflicting types |
| `src/Graphics/Model/mdlEffect_inferred_0048a980.c` | 39 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_0048cdf0.c` | 39 | unknown register |
| `src/Graphics/Effect/effLineNova.c` | 35 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_00484bb0.c` | 33 | unknown register |
| `src/Graphics/Model/mdlEffect.c` | 32 | unknown register |
| `src/Graphics/Effect/effPolygonRing.c` | 30 | unknown register |
| `src/Graphics/Model/mdlEffect_inferred_00490c40.c` | 30 | unknown register |
| `src/Graphics/Effect/effBlurFilter.c` | 26 | unknown register |
| `src/promoted/code1_003c.c` | 25 | conflicting types |

Reading: the clang blocker set is dominated by the VU0 asm in `mdlEffect_inferred_*` and `eff*.c` (about 89 files with `$vf` clobbers). gcc's blocker set is dominated by first-party declaration mismatches (`scrSetReturnInt`, `func_*`, `kwlnTaskGetWork`), which are fixable header/prototype work.

## 3. Link census (clang IR, `census_ir.py`)

Method: 1415 non-generated files compiled with `clang -S -emit-llvm -O0` in shim mode; 1214 produced IR (85.8%). The IR's defined and undefined symbols were collected and each undefined symbol classified.

- Defined symbols: 8759. Undefined: 4944.

| class | undefined | note |
|---|---:|---|
| data (raw retail `.data`/`.rodata` names) | 3073 | `D_`/`DAT_` names; cross-check: 6299 distinct names in 993 files, 67271 occurrences |
| first-party, named, no C, no stub (retail only) | 912 | |
| unnamed `func_`/`FUN_`, no asm stub | 317 | |
| asm stub FIRST (INCLUDE_ASM, first-party) | 234 | |
| asm stub CRI | 115 | |
| CRI | 60 | |
| CRI Sofdec/MPV or RW-internal | 85 | [inferred] |
| libc/libm | 25 | |
| asm stub RW | 25 | |
| SCE/Sony libs | 24 | [inferred] (AXRNA_*, AR*, thread/cache) |
| SCE | 22 | |
| RW | 21 | |
| asm stub MIDDLEWARE | 15 | |
| asm stub SCE | 14 | |
| RW_sky2 | 1 | |
| asm stub GENERATED | 1 | |

`asm_stub_names` (names of INCLUDE_ASM functions referenced): 3831.

Reading: **about 60% of the undefined surface (3073 of 4944) is retail data**. The next-largest block is first-party functions that exist only in retail (912 named + 317 unnamed). Third-party undefined references, excluding asm stubs, total 238 (CRI 60, CRI Sofdec/RW-internal 85, libc 25, RW 21, SCE 22, SCE/Sony 24, RW_sky2 1).

## 4. Data strategy probe

Input: retail `SLUS_217.82` from `orig/` in the main repo (sha1 `4eeec036…`, 8,621,084 bytes). It has one file-backed `PT_LOAD` at VA `0x100000` with `filesz = memsz = 0x838a00` (covering code1, data1, code2, data2 and the zero-fill as explicit zero bytes), plus an empty `PT_LOAD` at `0x938a00`. The zero-fill is therefore stored in the file.

### 4.1 Word classes in data sections (`data_probe.py`)

Data1 `0x52da00–0x70c850` (490,388 words) and data2 `0x70e140–0x764280` (88,144 words; sizes checked against the scanned counts).

| class | words | distinct targets | meaning |
|---|---:|---:|---|
| zero | 163,475 | — | |
| other (not a pointer into known ranges) | 381,577 | — | mostly data (floats, ints) |
| func_start (equals a `type:func` start in `symbol_addrs.txt`) | 2,398 | 2,013 | **function pointers / jump targets** |
| code_off (in code1/code2, not a start) | 19,684 | 4,501 | [inferred] mostly ints or intra-function values; not verified |
| data_other (in data1/data2, not a named symbol) | 6,902 | 3,585 (all data-pointer targets) | data-to-data pointers |
| data_sym (equals a symbol in `symbol_data_addrs.txt`) | 19 | 16 of 3,585 named (0.4%) | |
| bss (in zero-fill range) | 4,477 | 284 | data-to-bss pointers |

Caveats: this is a value heuristic. A word equal to an address is not proven to be a pointer. `symbol_data_addrs.txt` yielded 872 parsed `name = addr; // type` entries out of 1094 lines; the remaining 222 lines were not inspected. The retail ELF was not checked for relocation records.

Conclusion: correctness of data does not need full symbolization. Keeping the image at its original VAs keeps every data-to-data and data-to-bss pointer valid. The only pointers that must change are the function pointers (2,398 words, 2,013 distinct starts, plus any `code_off` words that prove to be code pointers).

### 4.2 Original-VA mapping (`mapcheck.c`, Linux, `-m32`)

- `mmap(0x00100000, 0x839000, RWX, MAP_FIXED_NOREPLACE)`: ok at `0x100000`.
- The file bytes of the PT_LOAD were copied in: 0 word mismatches on readback.
- `mmap(0x00939000..0x02000000, MAP_FIXED_NOREPLACE)`: ok (the first attempt started at `0x938a00`, inside an already-mapped page, and failed for that reason).
- `/proc/self/maps` shows the image region as `00100000-00939000 rwxp`.

Windows: not measured. `VirtualAlloc` at `0x00100000` in a 32-bit process needs a 32-bit Windows runtime, which is not on this workstation. [inferred] It is likely to work because the first 64 KB are reserved but `0x100000` is usually free, but this has to be checked.

### 4.3 Layout (`lay.c`)

| build | `struct{char c; long long a;}` size / offset(a) | `struct{char c; unsigned long long u; char e;}` size / offset(u), offset(e) |
|---|---|---|
| gcc `-m32` | 12 / 4 | 16 / 4, 12 |
| clang `--target=i386-linux-gnu` | 12 / 4 | 16 / 4, 12 |
| clang `--target=i386-linux-gnu -malign-double` | **16 / 8** | 24 / 8, 16 |

gcc `-malign-double` was also measured earlier as 16 / 8 (matches MWCC layout). `-malign-double` is required to keep 64-bit members at 8-byte alignment. `[inferred]` `-malign-double` also changes the alignment of `double` members.

## 5. ABI and language notes

- **128-bit types.** Both host compilers reject `__int128`; gcc rejects `mode(TI)`. Usage: 173 `u128` references, 111 `mode(TI)` definitions, 90 `aligned(16)`. Typedef sites: `include/cri/ps2/eetypes.h:31,39`, `include/rw/ps2/eetypes.h:31,39`, `include/rw/sky2/rwplcore.h:139`, `include/cri/recvx-decomp-cri/cri/mwlib/include/cri_xpts.h:112,117`. Recommendation: replace with a 16-byte struct of four `u32` plus `aligned(16)`, and move the 128-bit arithmetic to SSE intrinsics where the code actually computes with it. [inferred for the arithmetic usage; not counted.]
- **Inline asm.** 867 `__asm__`/`asm volatile` uses in 49 files; 316 `asm void` definitions in 62 files; 0 `asm {` blocks. The VU0 `$vf` clobbers (89 files) are the hard blocker. Those functions must be rewritten in C or SSE for the port; they cannot be carried over.
- **`__builtin_args_info` (33) and `__builtin_next_arg` (5).** Not supported by clang or gcc as written; both are varargs internals. [inferred] they can be replaced by `va_list` in the ported code.
- **Floating point.** [inferred] x87 excess precision on i386 can change float results. Not measured. Recommend `-msse2 -mfpmath=sse` (or `-ffloat-store` for a first pass) and byte-compare output once a path exists.
- **Regimes.** RECVX and RE4 both define `Sint32`-style names; the regime must be taken from the unit key, not a global flag (§1).

## 6. Recommendations

1. **Compile target.** Use `-m32 -malign-double` with clang as the primary host compiler. clang accepts `mode(TI)`, and its diagnostics are more precise. Keep gcc as a second checker for the first-party files that have no asm.
2. **Compat header.** Add a port-only header that provides the 128-bit typedef as a struct, replaces `mode(TI)` and `__builtin_*` varargs, and maps `eetypes.h` to the port's types. Do not edit the decomp sources for this; use an include path for the port build only.
3. **Asm.** Plan rewrites, not translation, for the 89 VU0 files and the `asm void` bodies. These are the largest port-only work item and should be scheduled before the renderer.
4. **Declarations.** The gcc blockers in first-party code (`scrSetReturnInt`, `func_003d5830`, `kwlnTaskGetWork`, `itfMesWindowSetState`, `btlUnitGetSphereWorldCenter`, `datGetDateIndex`, …) are prototype and header fixes. They are not port work and should be fixed in the decomp.
5. **Data.** Map the retail image at its original VAs (Linux verified; Windows to measure). Define the `D_` symbols as linker-defined addresses inside the mapped image, so no per-symbol data definitions are needed. Generate a table of the 2,398 function-start words (2,013 distinct) that maps retail function addresses to native function pointers. Decide the `code_off` words separately after a sample check.
6. **Third-party.** The RW and CRI surface is small in compile errors (RW 1 gcc / 2 clang files; CRI 2 files) but large in link surface (RW 21 + 25 asm stubs + 1; CRI 60 + 115 stubs + 85 `[inferred]`). Porting RW means a replacement renderer, not compiling RW 3.7 as-is. This is a Main decision; the census gives the surface size.
7. **Full data symbolization is not needed for correctness.** It would take about 3,600 new data names for the pointer targets alone, at 0.4% coverage today.

## 7. Not measured

- Windows 32-bit compile and `VirtualAlloc` fixed-base probe (no toolchain).
- Whether any asm body assembles on x86 (gcc does not assemble in `-fsyntax-only`).
- Float results under x87 vs SSE.
- Retail relocation records (none checked).
- Whether `code_off` words are pointers.

## 8. Checks for Main to run

- Build the real PS2 target as usual (`make`); this census changed nothing in the repo.
- `tools/decomp_lint.py` and a clean RW build, if RW is touched by the renderer work.
- If the port work starts, re-run the census against the new tree with the same scripts: the scripts are on `fates-vps` at `/tmp/p4c/census/` (not committed).
