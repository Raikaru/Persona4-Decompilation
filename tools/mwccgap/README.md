# mwccgap

`mwccgap` lets a C translation unit retain individual assembly functions
while the rest is compiled by Metrowerks. It is based on
[asm-processor](https://github.com/simonlindholm/asm-processor), using
`INCLUDE_ASM` rather than a `GLOBAL_ASM` pragma.

For each fallback, it reserves space during C compilation, assembles the
external source, then transplants the bytes, symbols and relocations into
the object. Assembly-owned `.rodata` is transplanted too. These bytes are
still assembly, not a C match.

Persona 4's build and verifier invoke this tool with the target settings.
For normal project work, use those commands rather than calling it directly.

## Usage

```sh
python tools/mwccgap/mwccgap.py input.c output.o [options] [compiler flags]
```

Unrecognized arguments are passed to the compiler. The inherited defaults
are for PSP, not PS2; a direct PS2 invocation must select the appropriate
compiler, assembler architecture and ABI.

| Option | Meaning / default |
| --- | --- |
| `--mwcc-path PATH` | Compiler; defaults to `mwccpsp.exe`. |
| `--as-path PATH` | GNU assembler; defaults to `mipsel-linux-gnu-as`. |
| `--as-march NAME` | Assembler architecture; defaults to `allegrex`. |
| `--as-mabi NAME` | Assembler ABI; defaults to `32`. |
| `--as-flags FLAGS...` | Assembler flags; defaults to `-G0`. |
| `--use-wibo` | Run the compiler through wibo. Disabled by default. |
| `--wibo-path PATH` | Runner path; defaults to `wibo`, or can point to Wine. |
| `--asm-dir-prefix PATH` | Prefix for assembly include paths. |
| `--macro-inc-path PATH` | Assembler macro include. |
| `--symbol-map PATH` | Canonical names for address-form assembly fallbacks. |
| `--target-encoding NAME` | Source encoding passed to the compiler. |
| `--src-dir PATH` | Directory used for relative includes when reading stdin. |
| `--skip-asm` | Emit compiled C without splicing `INCLUDE_ASM` or `INCLUDE_RODATA`. |

Prefer explicit input and output paths. The stdin mode depends on whether
stdin is a terminal and how many arguments were supplied.

## Source integration

The compiler needs empty definitions for the macros that mwccgap processes.
Include them through the project's common header:

```c
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
```

Do not confuse `--skip-asm` with a matching build: it is useful for measuring
C-only output, but deliberately omits the fallback bodies.

## Symbol and data handling

Symbols beginning with `@`, or containing `$`, are temporarily renamed for
the assembler. Symbols containing `$` are also made local to the object.
`INCLUDE_RODATA` sections use 8-byte alignment; check object layout when a
fallback requires different alignment.

The [MIT license](LICENSE) covers this vendored tool. Other users include
[Symphony of the Night](https://github.com/Xeeynamo/sotn-decomp),
[Street Fighter III: 3rd Strike](https://github.com/apstygo/sfiii-decomp) and
[Silent Hill 3](https://github.com/dreamingmoths/memory-of-alessa).
