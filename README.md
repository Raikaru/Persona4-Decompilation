# Persona 4 PS2 Decompilation

Preliminary matching-decompilation work for **Shin Megami Tensei: Persona 4**
(USA, version 1.00, `SLUS_217.82`) on the PlayStation 2.

This repository intentionally contains no game executable, disc image, or
extracted game data. Supply a disc image from a copy you legally own. The setup
tool validates the disc against the confirmed Redump record before extracting
only the boot executable and its loadable image.

## Current status

The repository is bootstrapped for executable analysis; matching C and a
byte-identical link pipeline have not been established yet.

| Artifact | Verified value |
| --- | --- |
| USA DVD image | 4,405,952,512 bytes; SHA-1 `179381f67a412dc56e9b7ae40dbc1c00a0beea59` |
| Boot executable | `SLUS_217.82`; 8,621,084 bytes; SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |
| Executable PT_LOAD image | `0x838a00` bytes at VRAM `0x00100000`; SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78` |
| Entry point | `0x00100008` |
| Global pointer (`.reginfo`) | `0x007690f0` |
| ELF compiler comment | `MW MIPS C Compiler (2.4.1.01)` |

The compiler comment alone does **not** identify the exact CodeWarrior build;
that must be established from code-generation evidence before matching work.

Disc identity: [Redump record 5576](http://redump.org/disc/5576/).

## Prerequisites

- Python 3.10 or newer.
- [`splat`](https://github.com/ethteck/splat):
  `python -m pip install -r requirements-python.txt`
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

## Initial split

```sh
make split
# or: python -m splat split config/slus21782.yaml
```

The preliminary splat map conservatively treats the ELF's named `main` section
(`0x000000`–`0x664280` in `image.bin`) as assembly. Every byte in the remaining
PT_LOAD range (`0x664280`–`0x838a00`, virtual `0x00764280`–`0x00938a00`) is
zero. The handwritten startup clears exactly that virtual range before entering
the game, so the split preserves it as `zero_fill.bin`. The `main` section's
internal code/data boundaries remain provisional and must be refined from
disassembly, cross-references, and reconstructed data ownership.

Generated assembly and extracted bytes are ignored until the executable map is
stable. `config/symbol_addrs.txt` currently contains only the ELF entry point.

## Planned analysis sequence

1. Import `orig/SLUS_217.82` into Ghidra as 32-bit little-endian MIPS/R5900 at
   the ELF-provided addresses.
2. Recover function boundaries and export a fresh Persona 4 symbol map; do not
   copy Persona 3 addresses or names.
3. Identify real code/data transitions inside the ELF `main` section and refine
   `config/slus21782.yaml`.
4. Determine the exact CodeWarrior compiler build and flags from codegen.
5. Port the generic R5900 assembly/build/verifier tooling only after the segment
   model and function windows are grounded.
6. Establish a byte-identical assembly baseline before accepting matching C.

## Layout

```text
config/       target identity, preliminary splat map, symbols
asm/          committed macro support; generated assembly is ignored
include/      shared PS2 C types and decompilation macros
src/          matching C translation units (currently empty)
tools/        reproducible ISO/ELF setup tooling
orig/         user-supplied/extracted retail files (ignored)
image.bin     extracted executable PT_LOAD payload (ignored)
```
