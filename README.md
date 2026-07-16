# Persona 4 PS2 Decompilation

[![Matching progress](https://img.shields.io/endpoint?url=https%3A%2F%2FRaikaru.github.io%2FPersona4-Decompilation%2Fprogress%2Fmatching.json)](https://Raikaru.github.io/Persona4-Decompilation/progress/matching.json)
[![C-linked progress](https://img.shields.io/endpoint?url=https%3A%2F%2FRaikaru.github.io%2FPersona4-Decompilation%2Fprogress%2Flinked.json)](https://Raikaru.github.io/Persona4-Decompilation/progress/linked.json)

Matching decompilation of **Shin Megami Tensei: Persona 4** for PlayStation 2
(USA, version 1.00, `SLUS_217.82`).

This repository contains source and build tooling, not the game executable, disc
image, or extracted game data. Use a copy you legally own. The setup tool checks
the disc against the [Redump record](http://redump.org/disc/5576/) before
extracting the files required for the build.

## Status

| Item | Verified value |
| --- | --- |
| Retail executable | `SLUS_217.82`; SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |
| Loadable image | `0x838a00` bytes at `0x00100000`; SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78` |
| Canonical function windows | 13,080; all mapped to C or owned retail assembly |
| Authoritative matching C | 873 functions |

The matching build uses MWCCPS2/MWLDPS2 and reproduces the retail load image and
ELF byte-for-byte. See [`ROADMAP.md`](ROADMAP.md) for current priorities.

## Setup

Requirements:

- Python 3.10 or newer.
- Python dependencies: `python -m pip install -r requirements-python.txt`.
- GNU `mipsel-linux-gnu-as` and `mipsel-linux-gnu-objcopy` with R5900 support.
- MWCCPS2/MWLDPS2, currently `mwcps2-3.0.1b210-060308` with `-O2`.
- A legally owned Persona 4 USA disc image.

Set `P4_MWCC`, `P4_RETAIL_ELF`, `P4_AS`, and `P4_OBJCOPY`, or create the
machine-local `tools/verify_config.local.json` and
`tools/build_config.local.json` files. The build config also accepts `ld_exe`.

```json
{
  "mwcc": "D:/mwcps2-3.0.1b210-060308/mwccps2.exe",
  "retail_elf": "C:/path/to/SLUS_217.82",
  "ld_exe": "D:/mwcps2-3.0.1b210-060308/mwldps2.exe"
}
```

Use the same `mwcc` and `retail_elf` values in both local files.

## Build

```sh
python -m pip install -r requirements-python.txt
make setup ISO="D:/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
make split
make
make test
```

`make setup` writes the ignored `orig/SYSTEM.CNF`, `orig/SLUS_217.82`, and
`image.bin`. `make` builds the retail image and runs the authoritative verifier.

Useful targets:

```sh
make build              # build and verify retail hashes
make verify             # verify every authoritative // FUN_ marker
make test               # deterministic unit tests
make progress-validate  # validate committed progress endpoints
```

## Decompiling

Use m2c for a first draft, replace inferred names and types with project
definitions, then require an exact verifier match:

```sh
make m2c FILE=src/Battle/btlUnit.c FUNC=func_00195850
python tools/fndiff.py src/Battle/btlUnit.c func_00195850
python tools/verify.py src/Battle/btlUnit.c
```

Function markers use `// FUN_XXXXXXXX`; only `MATCH` functions enter the
authoritative matching build.

For grouped candidate generation:

```sh
make m2c-bulk
python tools/m2c_bulk.py --check
python tools/verify.py --include-generated --json build/m2c_verify_report.json
```

Generated candidates under `src/generated/` support ongoing work and are not
authoritative source. Exact-retail assembly bodies preserve ownership where
semantic C has not yet been recovered.

## Tools

```sh
make consolidate
make reconcile
make shared-p3 P3_ROOT=../Persona3-FES-Decompilation
python tools/progress.py
```

The shared-code mapper compares Persona 3 FES and Persona 4 without copying
proprietary files into this repository.

## Layout

```text
config/      target identity, symbols, and progress metadata
asm/         assembler support; generated split files are ignored
include/     shared PS2 types and headers
src/         matching C and generated candidate ownership files
tools/       setup, build, verification, and analysis tools
tests/       deterministic parser, ELF, ISO, and reconciliation tests
orig/        extracted retail files (ignored)
image.bin    extracted load image (ignored)
build/       objects, reports, and linked outputs (ignored)
```
