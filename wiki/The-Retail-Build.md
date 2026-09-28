# The Retail Build

`SLUS_217.82` was built with more than one compiler and more than one set of
flags. The tree reproduces this per translation unit: each source file is
compiled by exactly one compiler at one setting, chosen by files in
`config/`. `unit_compiler` and `unit_compile_flags` in `tools/verify.py`
make the choice for both the verifier and the build.

| Code | Compiler | Flags | Configured by |
| --- | --- | --- | --- |
| Atlus game and engine code | MWCCPS2 3.0.1 build 210 (`060308`) | `-O2` | default (`compile_flags` in `tools/verify_config.json`) |
| RenderWare block (`src/renderware/`, `src/promoted/code1_0039_cw119.c` to `code1_003e_cw119.c`) | MWCCPS2 3.0.1 build 119 (`040914`) | `-O4,p -inline auto`, RenderWare defines and headers | `config/compiler_units.txt` (`cw3.0.1b119`), `config/version_flags.txt` |
| Older RenderWare-block files (`src/promoted/code1_0039.c` to `code1_003e.c`, `src/rw/basky.c`) | build 210 | `-O2,p`; `code1_003c.c` plain `-O2` | `config/speed_units.txt` |
| CRI middleware, some Sony SDK and C runtime units | ee-gcc 2.96 | `-O2 -G0`, per-library include roots | `config/gcc_units.txt`, `config/compiler_units.txt` (`eegcc296re4`), `config/version_flags.txt` |

The older RenderWare-block files hold fallbacks and functions matched with
build 210 before the RenderWare source was used. Vendor code that is not
reconstructed stays as `INCLUDE_ASM`, so the image still matches.
`VENDOR_CODE_RANGES` in `tools/verify.py` marks the vendor address ranges
for progress reporting.

## Evidence

**Build 210 for game code.** Probes compiled with builds 198, 205 and 210
give identical `-O2` code that matches retail's control flow and unscheduled
delay slots. Build 151 produces a different inverted-branch sequence, and
`-O3` fills branch and return delay slots differently from retail. Build 210
is the default because the Persona 3 FES project validated the same compiler
family;
`config/target.json` rates the exact build as medium confidence. The ELF's
`MW MIPS C Compiler (2.4.1.01)` comment comes from the linker and says
nothing about the C compiler.

**Build 119 for RenderWare.** Retail's RenderWare functions use `movz`/`movn`,
which the recorded build-210 and build-198 probes never produced. Builds 74,
119 and 151 emit them from a plain ternary. Compiling the whole tree with
build 119 kept 488 of the block's 529 matches but only 4,620 of 7,468
overall, so the block uses build 119 and Atlus's code stays on 210.
The measurement is in the header of `config/compiler_units.txt`.

**RenderWare flags** (`config/version_flags.txt` documents each one):

- `-O4`: at `-O2`, build 119 turned a plain `while` into a bottom-tested
  loop; retail's are top-tested. A whole-file compile of the RenderWare
  sources matched 360 functions at `-O4,p`, 259 at `-O3` and 130 at `-O2`.
- `-inline auto`: `_rwPluginRegistryWriteDataChunks` contains
  `_rwPluginRegistryGetSize` inline, and the out-of-line copy is still
  emitted.
- `-DRWBUILDNUMBER=55`: retail writes chunk headers with build 55
  (`addiu $t0, 0x37`); the 3.7.0.2 source defaults to 101.
- `-DSKY2_DRVMODEL_H`: selects the PS2 layout of the Im3D globals without
  using the incompatible RenderWare 3.5 sky2 headers.
- `-nosyspath` with `include/rw/std`: the RenderWare headers get their C
  library declarations from the project's shims.

**`-O2,p`.** With `,p`, MWCC inserts an alignment `nop` after a filled
back-edge delay slot so the next branch target is 8-byte aligned. No pragma
tried reproduces it, so it is set per unit. A whole-tree build at `-O2,p`
lost 962 matches overall but none in the listed units. `code1_003c.c` lost
one and stays at `-O2`.

**ee-gcc 2.96.** These functions save callee-saved registers with `sd`;
the MWCC builds on hand used `sq` at every level tried. ee-gcc 2.95.3 also
uses `sq`, and 3.2 allocates a scratch register differently from retail;
2.96 reproduces both. `config/gcc_units.txt` records which units moved to
ee-gcc and the measured gain for each. The reconstructed CRI sources come
from two upstream projects with incompatible headers, so the RE4-derived
units under `src/cri/re4` use their own version key and include root.

The assembler matters as well; see
[Getting Started](Getting-Started#the-assembler-for-gcc-units).

## Linking

Retail was linked by a Metrowerks linker; the ELF comment above is its
version string. The project links with GNU ld by
default, because it can place the compiler's literal pools and jump tables
exactly where retail has them. The MWLD backend is still available with
`--linker-backend mwld`, but its literal-pool placement can stop the current
tree from passing the image check. `docs/gnu_linker.md` has the details.
