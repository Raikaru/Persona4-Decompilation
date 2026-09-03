# Getting Started

## What you need

| Item | Notes |
| --- | --- |
| Python 3.10+ | `python -m pip install -r requirements-python.txt` |
| MIPS binutils with R5900 support | `mipsel-linux-gnu-as`, `mipsel-linux-gnu-objcopy`; the [decompals build](https://github.com/decompals/binutils-mips-ps2-decompals) is what CI uses |
| MWCCPS2 3.0.1 build 210 (`mwcps2-3.0.1b210-060308`) | compiler and linker (`mwccps2.exe`, `mwldps2.exe`) for Atlus's code |
| MWCCPS2 3.0.1 build 119 (`040914`) | the RenderWare units; runs without its licence DLL |
| ee-gcc 2.96 | five GCC-built units; driven by `tools/eegcc_shim.py` |
| [wibo](https://github.com/decompals/wibo) | runs the Windows compilers on Linux (`wibo mwccps2.exe ...`) |
| A Persona 4 USA disc image | checked against [Redump](http://redump.org/disc/5576/) before anything is extracted |

The compilers and the retail executable are not in the repository and must
never be committed. CI fetches them from a private repository (see
`.github/workflows/ci.yml` and the `Dockerfile`).

## Pointing the tools at your toolchain

Either environment variables:

```sh
export P4_MWCC=/opt/mwcc-wrapper.sh          # a script that execs wibo mwccps2.exe "$@"
export P4_MWCC_CW3_0_1B119=/opt/mwcc-b119-wrapper.sh
export P4_RETAIL_ELF=/path/to/SLUS_217.82
export P4_AS=/usr/local/bin/mipsel-linux-gnu-as
export P4_OBJCOPY=/usr/local/bin/mipsel-linux-gnu-objcopy
```

or the git-ignored `tools/verify_config.local.json` and
`tools/build_config.local.json` (same content in both):

```json
{
  "mwcc": "/opt/mwcc-wrapper.sh",
  "ld_exe": "/opt/mwld-wrapper.sh",
  "retail_elf": "/path/to/SLUS_217.82",
  "mwcc_versions": { "cw3.0.1b119": "/opt/mwcc-b119-wrapper.sh" }
}
```

`tools/build.py` derives `mwldps2.exe` from the `mwcc` path when `ld_exe` is
not given, so wrapper names ending in `.exe` are convenient.

## First build

```sh
make setup ISO="/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
make split
make
make test
```

- `make setup` verifies the ISO and writes the ignored `orig/SYSTEM.CNF`,
  `orig/SLUS_217.82` and `image.bin`.
- `make split` runs splat and extracts the retail assembly for every function
  that is not yet matched (`asm/nonmatchings/...`, ignored).
- `make` compiles every unit, links, and checks both SHA-1s. Expect
  `loadable image sha1: 3d1d3d2b... OK` and `SLUS_217.82 sha1: 4eeec036... OK`.
- `make test` runs the deterministic tests under `tests/`; a handful of
  `test_reconcile` cases about window boundaries are known failures and are
  the same on every machine.

## Docker

```sh
docker build -t p4-decomp .
docker run --rm -it -v "$PWD:/work" -v /path/to/private:/opt/p4:ro p4-decomp \
  sh -c 'python tools/build.py --setup-only && make split && python tools/build.py --progress-report build/linked_report.json && python tools/verify.py'
```

`/opt/p4` holds `mwccps2.exe`, `mwldps2.exe`, `SLUS_217.82` and
`cw3.0.1b119/mwccps2.exe`. This is exactly what CI runs.
