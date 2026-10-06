# Getting Started

This page covers the toolchain, local configuration and the first build. The
[README](https://github.com/Raikaru/Persona4-Decompilation#readme) has the
short version.

## Requirements

| Item | Used for |
| --- | --- |
| Python 3.10+ and Make | every tool; `python -m pip install -r requirements-python.txt` (versions are pinned because splat's output feeds the build) |
| `mipsel-linux-gnu-as` with R5900 support | assembling `INCLUDE_ASM` fallbacks and split code; the [decompals binutils](https://github.com/decompals/binutils-mips-ps2-decompals) accept the EE instructions |
| `mipsel-linux-gnu-objcopy`, `mipsel-linux-gnu-ld` | object rewriting and the default GNU link; Debian's `binutils-mipsel-linux-gnu` works |
| MWCCPS2 3.0.1 build 210 (`mwcps2-3.0.1b210-060308`) | the default compiler |
| MWCCPS2 3.0.1 build 119 (`040914`) | units listed as `cw3.0.1b119` in `config/compiler_units.txt` (the RenderWare block) |
| ee-gcc 2.96 (`2.96-ee-001003-1`) and its EE `as` | units in `config/gcc_units.txt` (CRI, some Sony SDK and C runtime code) |
| [wibo](https://github.com/decompals/wibo) | running the Windows MWCC executables on Linux |
| MWLDPS2 | only for the optional `--linker-backend mwld` |
| Persona 4 USA disc image | must match [Redump 5576](http://redump.org/disc/5576/); `make setup` checks it |

The compilers, the executable and the disc are not in the repository. Do not
commit them, and do not commit machine-local paths.

Pair the decompals `as` with Debian's `objcopy`. The Dockerfile records that
decompals v0.7 `objcopy` can leave an invalid `.symtab` `sh_info`.

ee-gcc 2.96's `cc1` is a 32-bit i386 binary. Install the 32-bit loader and
libc (`libc6:i386` on Debian/Ubuntu, `glibc.i686` on Fedora), or point
`eegcc_ld_library_path` / `P4_EEGCC_LD_LIBRARY_PATH` at a directory holding
the glibc your `cc1` was patched to use. An inherited `LD_LIBRARY_PATH` can
shadow that library; every function in a GCC unit then reports
`COMPILE_ERROR`.

## Local configuration

`tools/verify.py` and `tools/build.py` read different files. Put
machine-local settings in the git-ignored `*.local.json` files; the committed
`tools/verify_config.json` and `tools/build_config.json` hold shared defaults.
Environment variables override both.

`tools/verify_config.local.json`:

```json
{
  "mwcc": "/opt/p4/bin/mwccps2.exe",
  "retail_elf": "/path/to/SLUS_217.82",
  "mwcc_versions": { "cw3.0.1b119": "/opt/p4/bin/mwccps2-cw3.0.1b119.exe" }
}
```

`tools/build_config.local.json`:

```json
{
  "mwcc": "/opt/p4/bin/mwccps2.exe",
  "retail_elf": "/path/to/SLUS_217.82",
  "mwcc_versions": { "cw3.0.1b119": "/opt/p4/bin/mwccps2-cw3.0.1b119.exe" },
  "eegcc_root": "/opt/p4/ee-gcc-2.96",
  "eegcc_as": "/opt/p4/ee-binutils/bin/as"
}
```

On Linux, `mwcc` and the `mwcc_versions` entries are wrapper scripts that run
the Windows compiler, for example `exec wibo /opt/p4/mwccps2.exe "$@"`. On
Windows, point them at the executables directly; a compiler directory needs
the same `LMGR326B.DLL` that lets the b210 build start without a license
server. Routing a Windows compiler through WSL and wibo costs about 25 times
as long per unit.

| Key | Read by | Notes |
| --- | --- | --- |
| `mwcc` | verify, build | default MWCC; `P4_MWCC` |
| `retail_elf` | verify, build | the extracted `SLUS_217.82`; `P4_RETAIL_ELF` |
| `mwcc_versions` | verify, build | version key from `config/compiler_units.txt` to compiler path; `P4_MWCC_<KEY>` with non-alphanumerics as `_`, e.g. `P4_MWCC_CW3_0_1B119` |
| `compile_flags` | verify | committed as `["-O2", "-Iinclude"]`; leave it alone |
| `cflags` | build | defaults to `config/target.json`'s `-O2`; the build appends `-Iinclude` |
| `linker_backend` | build | committed as `gnu`; `mwld` is the alternative. `P4_LINKER_BACKEND` and `--linker-backend` override it |
| `ld_exe` | build | MWLD backend only; defaults to `mwldps2.exe` beside `mwcc` |
| `eegcc_root` | ee-gcc shim | directory with ee-gcc's `bin/` and `lib/`; `P4_EEGCC_ROOT` |
| `eegcc_as` | ee-gcc shim | assembler for GCC units; `P4_EEGCC_AS` |
| `eegcc_ld_library_path` | ee-gcc shim | 32-bit glibc for `cc1`; `P4_EEGCC_LD_LIBRARY_PATH` |

`tools/eegcc_shim.py` reads all four config files, in the order
`verify_config.json`, `verify_config.local.json`, `build_config.json`,
`build_config.local.json`; later files win.

Per-unit compiler choices and extra flags come from `config/`, not from these
files. See [The Retail Build](The-Retail-Build).

### GNU binutils

The GNU tools are found in this order: `P4_AS`, `P4_OBJCOPY` or `P4_LD`; a
`p4_as`, `p4_objcopy` or `p4_ld` key in the verify config; `PATH`; then WSL
(on Windows, distribution `P4_WSL_DISTRO`, default `Debian`). The compile
wrapper also accepts `as_path` in the verify config.

### The assembler for GCC units

Set `eegcc_as` or `P4_EEGCC_AS` to the `as` shipped with the ee-gcc
toolchain (`ee-binutils/bin/as` in the CI layout). Without it, the shim uses
the general GNU assembler (`P4_AS` or discovery). In both cases it rewrites
the compiler's `move` to retail's `daddu` encoding before assembling. CI
refuses to run without the EE assembler; its check records that assembling
the CRI units with the decompals binutils reduced them from 66 `MATCH` to 6.

Verification includes the GCC units by default. Without an ee-gcc toolchain,
`python tools/verify.py --skip-gcc-units` omits them; the build still needs
the compiler for GCC units that contain C.

## First build

```sh
make setup ISO="/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
make split
make regenerate-asm
make
```

- `make setup` checks the disc hash and writes the ignored `orig/SYSTEM.CNF`,
  `orig/SLUS_217.82` and `image.bin`.
- `make split` runs splat on `image.bin` (`config/slus21782.yaml`).
- `make regenerate-asm` recreates the per-function fallbacks listed in
  `config/generated_asm.json` and checks their hashes.
- `make` runs `tools/build.py` and then `tools/verify.py`.

A good build ends with

```text
loadable image sha1: 3d1d3d2b9d6ccb60836db239ab49674223025a78  OK
SLUS_217.82 sha1: 4eeec0360cf2715535d9f7e52eb69d786fb0158c  OK
```

`make test` runs the tooling tests under `tests/`. They need neither the
compilers nor the disc.

If you have the ELF but not the disc image, export
`P4_RETAIL_ELF=/path/to/SLUS_217.82` and run
`python tools/build.py --setup-only` instead of `make setup`; it writes
`image.bin` from the ELF. Then continue with split, regeneration and the
build. The environment variable matters here: assembly regeneration does
not read `retail_elf` from the local compiler config files.

## Docker

The `Dockerfile` installs the decompals assembler, Debian binutils, wibo,
32-bit libc and the Python dependencies. It contains no proprietary files.
Mount them at `/opt/p4`:

```text
/opt/p4/mwccps2.exe
/opt/p4/mwldps2.exe
/opt/p4/SLUS_217.82
/opt/p4/cw3.0.1b119/mwccps2.exe
/opt/p4/ee-gcc-2.96/bin/ee-gcc
/opt/p4/ee-binutils/bin/as
```

The image's environment variables point at these paths, so no local config
file is needed. Run the same sequence as CI:

```sh
docker build -t p4-decomp .
docker run --rm -it -v "$PWD:/work" -v /path/to/private:/opt/p4:ro p4-decomp \
  sh -ec 'python tools/build.py --setup-only && make split && make regenerate-asm &&
          python tools/build.py --progress-report build/linked_report.json &&
          python tools/verify.py --json build/verify_report.json'
```

CI asserts that neither `*.local.json` file exists before it runs. Leave
them out of the container build too: local options can change settings not
overridden by the image's environment variables. The container runs as
root, so `build/` may be root-owned afterwards; CI runs `chown -R` on it
before reading the reports.
