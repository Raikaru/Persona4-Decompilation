# mwccgap AKA "MWCC Global Assembly Processor"

`mwccgap` is a tool that enables individual functions within a C file to be replaced with assembly code, drawing heavy inspiration from [asm-processor](https://github.com/simonlindholm/asm-processor).

While the MWCC compiler *does* support embedding raw assembly within a C file, it requires that all variables and functions be fully defined. This limitation makes the traditional [Ship of Theseus](https://en.wikipedia.org/wiki/Ship_of_Theseus) approach to matching decompiled code slow and cumbersome.

Unlike `asm-processor`, which uses a `GLOBAL_ASM` pragma, `mwccgap` adopts an `INCLUDE_ASM` macro to align with the needs of its first supported project, which uses GCC. Future updates may add support for both approaches.

When a function in a C file is marked defined using the `INCLUDE_ASM` macro, it is replaced with a series of `nop` instructions of the appropriate size during compilation. The C file is then compiled as usual. Separately, the assembly code for these functions is assembled, and the resulting object data is transplanted back into the C object. Symbols and relocations are updated as needed to ensure correctness.

Any `.rodata` symbols defined in the assembly code will also be transplanted into the C object.

## Usage

```
mwccgap input.c output.o [ -O4,p -sym on ... ]
```

`mwccgap` supports the following arguments:

### `--mwcc-path` (path)
The path to the MWCC executable, defaults to `mwccpsp.exe`

### `--as-path` (path)
The path to GNU as, defaults to `mipsel-linux-gnu-as`

### `--as-march`
The `-march=` value to pass to GNU as, defaults to `allegrex`

### `--as-mabi`
The `-mabi=` value to pass to GNU as, defaults to `32`

### `--as-flags`
Additional flags to pass to GNU as, defaults to `-G0`.

### `--use-wibo`
Whether or not to prefix the call to the MWCC executable with [wibo](https://github.com/decompals/wibo), defaults to **false**.

### `--wibo-path`
Path to `wibo` (i.e. if `wibo` is not on your path, or you wish to use `wine` instead), defaults to `wibo`.

### `--asm-dir-prefix`
Optional directory prefix for `INCLUDE_ASM` files.

### `--macro-inc-path`
Optional path to your `macro.inc` file.

### `--target-encoding [sjis, ujis, etc]`
Optional encoding that the input c file should be converted to, before being passed to the compiler.

### `--src-dir`
Optional path to use when passing data over stdin to interpret relative path include statements.

**NOTE:** Any additional arguments will be passed through to the MWCC executable.

## Setup

You will need to define empty macros for `INCLUDE_ASM` and `INCLUDE_RODATA` so that the MWCC compiler does not choke.

Create an `include_asm.h` header with the following content and ensure it is included as part of your compile process (e.g. from within your `common.h` header).

```c
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
```


## Quirks

### "@123"

Symbols that start with an `@` are not valid syntax. `mwccgap` will temporarily rename these symbols during processing.

### foo$bar$baz

Symbols that contain `$` are not valid syntax, `mwccgap` will temporarily rename these symbols during processing and also mark them as `static` (i.e. local to the file being compiled).

## Limitations

Known limitations:

- `.rodata` alignment set to `0x8` for all `INCLUDE_RODATA` sections.


## Bugs

This project is in its infancy and is full of assumptions, and therefore likely riddled with bugs; PRs are welcomed!


## Examples

Projects that use `mwccgap` include:

- <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/0e/PSP_Logo.svg/330px-PSP_Logo.svg.png" alt="PSP" width="48"> [Castlevania: Symphony of the Night Decompilation](https://github.com/Xeeynamo/sotn-decomp)
- <img src="https://upload.wikimedia.org/wikipedia/commons/a/af/PlayStation_2_logo.png" alt="PS2" width="48"> [Street Fighter III: 3rd Strike](https://github.com/apstygo/sfiii-decomp)
- <img src="https://upload.wikimedia.org/wikipedia/commons/a/af/PlayStation_2_logo.png" alt="PS2" width="48"> [Shaun Palmer's Pro Snowboarder](https://github.com/Daniel-McCarthy/SPPS)
- <img src="https://upload.wikimedia.org/wikipedia/commons/2/28/PlayStation_wordmark_%281994-2009%29.svg" alt="PS1" width="48"> [Digimon World](https://github.com/jype0/dw_decomp)
- <img src="https://upload.wikimedia.org/wikipedia/commons/a/af/PlayStation_2_logo.png" alt="PS2" width="48"> [Silent Hill 3](https://github.com/dreamingmoths/memory-of-alessa)
- <img src="https://upload.wikimedia.org/wikipedia/commons/a/af/PlayStation_2_logo.png" alt="PS2" width="48"> [Monster Hunter](https://github.com/2Tie/mh1j)

