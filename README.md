# Persona 4 PS2 Decompilation

Preliminary matching-decompilation work for **Shin Megami Tensei: Persona 4**
(USA, version 1.00, `SLUS_217.82`) on the PlayStation 2.

[![Matching progress](https://img.shields.io/endpoint?url=https%3A%2F%2FRaikaru.github.io%2FPersona4-Decompilation%2Fprogress%2Fmatching.json)](https://Raikaru.github.io/Persona4-Decompilation/progress/matching.json)
[![C-linked progress](https://img.shields.io/endpoint?url=https%3A%2F%2FRaikaru.github.io%2FPersona4-Decompilation%2Fprogress%2Flinked.json)](https://Raikaru.github.io/Persona4-Decompilation/progress/linked.json)

See [`ROADMAP.md`](ROADMAP.md) for the P3 completion sequence and the parallel
P4 synchronization backlog.

This repository intentionally contains no game executable, disc image, or
extracted game data. Supply a disc image from a copy you legally own. The setup
tool validates the disc against the confirmed Redump record before extracting
only the boot executable and its loadable image.

## Current status

The complete retail executable has a byte-identical assembly baseline. The
matching build now selects 189 C translation units containing 190 exact-match
functions; the resulting loadable image and full ELF both reproduce the retail
SHA-1. The recovered set spans runtime, Kernel, Event, Scene, battle, gameplay,
CRI, model, and RenderWare helpers, including functions ported from uniquely
corresponding, verifier-matched Persona 3 FES implementations.

| Artifact | Verified value |
| --- | --- |
| USA DVD image | 4,405,952,512 bytes; SHA-1 `179381f67a412dc56e9b7ae40dbc1c00a0beea59` |
| Boot executable | `SLUS_217.82`; 8,621,084 bytes; SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |
| Executable PT_LOAD image | `0x838a00` bytes at VRAM `0x00100000`; SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78` |
| Entry point / global pointer | `0x00100008` / `0x007690f0` |
| Canonical function windows | 13,080 |
| Decompiled and matching | 871 functions in 783 C-linked translation units |

The ELF comment is `MW MIPS C Compiler (2.4.1.01)`, but this is linker
provenance rather than proof that the C compiler was MWCC 2.4. Direct probes
show that MWCCPS2 3.0.1 builds 198, 205, and 210 produce identical `-O2`
codegen for the tested P4 shapes; build 151 differs. Build 210 is the default,
but the path remains configurable because the probes do not distinguish
198/205/210. `-O3` is excluded for ordinary game code by its scheduled delay
slots.

Disc identity: [Redump record 5576](http://redump.org/disc/5576/).

## Prerequisites

- Python 3.10 or newer.
- [`splat`](https://github.com/ethteck/splat):
  `python -m pip install -r requirements-python.txt`
- GNU `mipsel-linux-gnu-as` and `mipsel-linux-gnu-objcopy` with R5900 support.
- A locally usable MWCCPS2/MWLDPS2 installation. The current default profile is
  `mwcps2-3.0.1b210-060308 -O2`.
- Your own Persona 4 USA disc image.

No external ISO extraction program is required. `tools/setup.py` contains a
small read-only ISO9660 root-directory reader and uses only Python's standard
library.

## Setup

```sh
python tools/setup.py "D:/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
```

The command verifies the complete 4.4 GB disc SHA-1, reads `SYSTEM.CNF`, checks
that it boots `SLUS_217.82`, validates the ELF and PT_LOAD layout, and writes:

- `orig/SYSTEM.CNF`
- `orig/SLUS_217.82`
- `image.bin`

All three outputs are gitignored.

Equivalent Make target:

```sh
make setup ISO="D:/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
```

## Split and function map

```sh
make split
make reconcile
```

The verified executable layout is:

| Region | VRAM | Image offsets |
| --- | --- | --- |
| `code1` | `0x00100000`–`0x0052da00` | `0x000000`–`0x42da00` |
| `data1` | `0x0052da00`–`0x0070c850` | `0x42da00`–`0x60c850` |
| `code2` | `0x0070c850`–`0x0070e140` | `0x60c850`–`0x60e140` |
| `data2` | `0x0070e140`–`0x00764280` | `0x60e140`–`0x664280` |
| zero fill | `0x00764280`–`0x00938a00` | `0x664280`–`0x838a00` |

`code1` ends immediately after the final statistics helper at `0x0052d9a0`.
`code2` is a `0x18f0`-byte PS2 SDK/kernel blob with the same layout as Persona
3 FES's corresponding region; only ten absolute address/call words differ.
Startup clears the final zero-filled range before entering the game.

Ghidra identified 11,833 functions. The canonical 13,080-window map
reconciles Ghidra with Splat's code1 control-flow scan and the independently
matching nine-function SDK layout in code2:

```sh
python tools/reconcile_function_boundaries.py
```

The raw Ghidra export is `tools/slus21782_functions.ghidra.json`; the canonical
map consumed by the verifier is `tools/slus21782_functions.json`.

The source tree is organized by module rather than by address-suffixed file.
Run:

```sh
make consolidate
```

`tools/consolidate_sources.py` places each original source unit under a
`P4_UNIT_<address>` preprocessor guard in its module C file. The verifier and
build compile one guard at a time, preserving the independent local struct
layouts and matching codegen that made the original units safe. Existing
multi-function modules remain ordinary C files; new grouped modules use the
same source text without semantic rewrites. Use
`python tools/consolidate_sources.py --check` to validate this layout.

Reconciliation scans every non-generated `src/**/*.c` file for `// FUN_...`
markers and writes `build/function_map.txt`. Each canonical boundary is listed
exactly once with its C translation unit when decompiled C exists; every
remaining boundary is represented by exact retail assembly inside grouped
generated C translation units under `build/function_sources/`. Thus all
13,080 canonical boundaries are `MAPPED`: 873 C-marked functions across 51
module C files and 12,207 retail-assembly functions consolidated into 68
generated C files. Generated functions are ownership units, not claims of
recovered C semantics. Use
`python tools/reconcile_function_boundaries.py --check` to validate the map
and assembly coverage without rewriting generated files.

## Bulk m2c candidate generation

The remaining exact-retail ownership boundaries can be passed through the
pinned m2c revision in grouped batches:

```sh
make m2c-bulk
python tools/m2c_bulk.py --check
```

This writes grouped candidate C files under both
`build/m2c_candidates/` (the machine-readable batch output) and
`src/generated/` (the source-tree candidate layout). The unresolved source
copies use the same `P4_UNIT_<address>` selection model as the recovered tree;
they are not one-file-per-function outputs. Verified candidate matches that
remain exact when compiled together are rendered as unguarded module-level
files under `src/generated/matched/`, following the P3-style translation-unit
layout. Source copies carrying `// FUN_<address> NONMATCHING` remain visible
as C bodies without entering the authoritative matching build or progress
totals. The verifier, source consolidator, and boundary reconciler intentionally
exclude `src/generated/` by default; the build admits only verified matching
candidate bodies.
The generator reconstructs indirect-switch input from the supplied
`image.bin`, `undefined_syms_auto.txt`, and split `asm/code*.s` files, adding
local labels and `.word` jump-table definitions before invoking m2c.
Exact-retail inline-assembly fallbacks are byte-swapped when copied into these C
candidate units because MWCC emits `.word` literals in the opposite byte order
from the retail ELF; the authoritative ownership assembly remains unchanged.
The report records which boundaries m2c converted, which retained an
exact-retail fallback, and which input-preparation or parser limitation
remains. These candidates are evidence for further matching work; they remain
separate from the authoritative recovered module files and
`build/function_sources/` until a candidate is reviewed and passes the retail
verifier. The full-run counts and input contract are recorded in
`build/m2c_candidates/report.json`.

To measure the generated candidates instead of the authoritative recovered
set, run `python tools/verify.py --include-generated --json
build/m2c_verify_report.json`. Generated candidates are intentionally allowed
to report `NONMATCHING`; only the ordinary verifier run is used for progress
and build eligibility.

The current full run produced 12,186 m2c bodies and 21 exact-retail fallback
bodies for all 12,207 fallback boundaries. The remaining seven are isolated
indirect-dispatch cases: four reference zero-filled runtime pointer tables
(`jtbl_008873E8`, `jtbl_008873EC`, or `jtbl_008873FC`), and three do not expose
a recoverable `jtbl_` read before the indirect jump. The formerly ambiguous
four-table dispatch now has per-branch setup context; the report records one
specialized function, 350 loaded tables, and 345 emitted table definitions.
Split-boundary branches and missing return delay slots are now supplied with
recovered context; none remain in the full-run failure set.
The final candidate verifier covered all 13,080 boundaries: 1,928
functions match retail bytes (873 authoritative functions plus 1,055 generated
candidates), and 11,152 generated candidates remain `MISMATCH`. No generated
`SIZE_MISMATCH`, `NONMATCHING`, `COMPILE_ERROR`, or `STALE_NONMATCHING` rows
remain.
Fourteen residual generated units now use exact `RETAIL_ASM` bodies: five
padding stubs and nine code2 hardware or opaque-instruction routines. These
preserve retail bytes but are not semantic C recoveries.
The 546 grouped generated matches live in `src/generated/matched/` across 57
unguarded C files; `python tools/m2c_bulk.py --apply-group-report
build/m2c_grouped_final_report.json` removes those functions from their guarded
source copies. The remaining verified candidate functions stay guarded where
grouped MWCC codegen did not remain exact. All 12,207 generated candidate
bodies now compile under the candidate verifier.
The grouped candidate layout validates as 68 guarded C files in
`build/m2c_candidates/` and 125 source C files under `src/generated/`.
The grouped build selected 676 C objects from source. The resulting loadable
image and `SLUS_217.82` both hash exactly to retail.

## Shared-code mapping from Persona 3 FES

`tools/map_shared_p3.py` compares the two canonical function maps and retail
load images without copying either game's executable into this repository. It
requires a separately set up Persona 3 FES decompilation checkout containing
its own gitignored `image.bin`:

```sh
make shared-p3 P3_ROOT="../Persona3-FES-Decompilation"
```

Equivalent direct invocation:

```sh
python tools/map_shared_p3.py \
  --p3-root "../Persona3-FES-Decompilation" \
  --with-source-evidence
```

The deterministic, gitignored report is written to `build/shared_p3.json`. It
contains raw-identical and address-normalized function matches, unique versus
ambiguous P3 candidates, decoded direct-call and relocated-address mappings,
and—when `--with-source-evidence` is used—P3 verifier status and source paths.
The report records SHA-1 hashes for both images, both function maps, and the P3
metrics input.

Address normalization masks only MIPS fields controlled by executable layout:
J/JAL targets, LUI immediates, GP-relative immediates, and low halves paired
with a recent LUI. Opcodes, register operands, ordinary constants, branch
displacements, and instruction order must still match exactly.

## m2c first-pass decompilation

The repository pins a known `m2c` revision and can generate a one-function C
draft using the P4 translation unit as type context:

```sh
make m2c-setup
make m2c FILE=src/Battle/btlUnit.c FUNC=func_00195850
```

Outputs are written under `build/m2c/`. Use `STACK=1` to include m2c's inferred
stack-structure template. `M2C=/path/to/m2c.py` and `M2C_CPP=/path/to/clang`
override the pinned tool and detected C preprocessor.

The draft is a starting point, not accepted source: replace inferred fields and
temporary names with project types and semantics, check calls and conditions
against retail assembly, then require `tools/verify.py` to report `MATCH`.

## Build and verification

Put machine-local paths in the gitignored configuration files:

```json
// tools/verify_config.local.json
{
  "mwcc": "D:/mwcps2-3.0.1b210-060308/mwccps2.exe",
  "retail_elf": "C:/path/to/SLUS_217.82"
}
```

`tools/build_config.local.json` accepts the same `mwcc` and `retail_elf` keys
plus an optional `ld_exe`. Environment variables `P4_MWCC`, `P4_RETAIL_ELF`,
`P4_AS`, and `P4_OBJCOPY` take precedence.

```sh
make build       # assemble/link/splice and verify both retail hashes
make verify      # compile and byte-compare every // FUN_ marker
make test        # deterministic parser/reconciliation tests
```

A successful build currently reports:

```text
eligible C objects: 783
C objects linked from source: 783
loadable image sha1: 3d1d3d2b9d6ccb60836db239ab49674223025a78  OK
SLUS_217.82 sha1: 4eeec0360cf2715535d9f7e52eb69d786fb0158c  OK
```

Archive-backed SCE names promoted from the external PS2 SDK corpus are recorded
in [`config/sdk_symbol_provenance.txt`](config/sdk_symbol_provenance.txt).
That file stores archive/member metadata and normalized hashes only; proprietary
SDK object bytes remain outside the repository.

## Progress endpoints

The committed [`progress/metrics.json`](progress/metrics.json) is generated
from `tools/verify.py --json` (matching) and a successful
`tools/build.py --progress-report` run (C-linked functions).  The canonical
function denominator is `tools/slus21782_functions.json`; duplicate verifier
rows are counted once by address, and every linked address must also match.

GitHub Pages publishes the validated endpoints at
`https://Raikaru.github.io/Persona4-Decompilation/progress/`.  Validate the
committed snapshot locally with:

```sh
make progress-validate
```

## Layout

```text
config/       target identity, segment layout, symbols, recovered linker symbols
asm/          committed macro support; generated assembly is ignored
include/      shared PS2 C types and decompilation headers
src/          matching C translation units
tools/        ISO setup, Ghidra export, boundary reconciliation, build and verify
tests/        synthetic ISO/ELF and boundary-map tests
orig/         user-supplied/extracted retail files (ignored)
image.bin     extracted executable PT_LOAD payload (ignored)
build/        linked objects, ELF and verifier reports (ignored)
```
