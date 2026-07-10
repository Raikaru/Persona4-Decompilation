# Persona 4 PS2 Decompilation

Preliminary matching-decompilation work for **Shin Megami Tensei: Persona 4**
(USA, version 1.00, `SLUS_217.82`) on the PlayStation 2.

This repository intentionally contains no game executable, disc image, or
extracted game data. Supply a disc image from a copy you legally own. The setup
tool validates the disc against the confirmed Redump record before extracting
only the boot executable and its loadable image.

## Current status

The complete retail executable now has a byte-identical assembly baseline. One
C translation unit containing two functions is linked through MWCC/MWLD as real
code; the resulting loadable image and full ELF both reproduce the retail
SHA-1.

| Artifact | Verified value |
| --- | --- |
| USA DVD image | 4,405,952,512 bytes; SHA-1 `179381f67a412dc56e9b7ae40dbc1c00a0beea59` |
| Boot executable | `SLUS_217.82`; 8,621,084 bytes; SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |
| Executable PT_LOAD image | `0x838a00` bytes at VRAM `0x00100000`; SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78` |
| Entry point / global pointer | `0x00100008` / `0x007690f0` |
| Canonical function windows | 13,080 |
| Decompiled and matching | 2 functions in 1 C-linked translation unit |

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
eligible C objects: 1  (runtime_callback.c)
C objects linked from source: 1
loadable image sha1: 3d1d3d2b9d6ccb60836db239ab49674223025a78  OK
SLUS_217.82 sha1: 4eeec0360cf2715535d9f7e52eb69d786fb0158c  OK
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
