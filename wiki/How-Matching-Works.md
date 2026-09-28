# How Matching Works

## Function windows and markers

`tools/slus21782_functions.json` is the canonical function map: a start
address and window size for every function in the retail executable. Each
window is owned by one source file under `src/` through a marker comment:

```c
// FUN_00195850
void btlUnitGetSphereWorldCenter(BtlUnit* unit, RwV3d* dst)
{
    ...
}
```

A function without matching C keeps its retail assembly:

```c
// FUN_004BD760
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004bd760);
```

An attempt that does not match yet can sit beside the fallback:

```c
// FUN_00219790 NONMATCHING
#ifdef NON_MATCHING
void func_00219790(s32 arg0, u8 *arg1) { ... }
#else
INCLUDE_ASM(...);
#endif
```

The markers are the verifier's denominator. Deleting one hides a function
from the score, so `tests/test_marker_tripwire.py`,
`tests/test_verify_markers.py` and `tools/decomp_lint.py` check them.

## What the verifier checks

`python tools/verify.py [files]` compiles whole source files. It never
compiles a function on its own, because declarations, literals and neighbours
in the same file change the generated code.

1. Each file is compiled with the compiler and flags configured for its unit
   (see [The Retail Build](The-Retail-Build)). MWCC units go through
   `tools/mwccgap`, which assembles the `INCLUDE_ASM` bodies into the object;
   GCC units go through `tools/eegcc_shim.py`.
2. Every marked function is cut out of the object and compared with the
   retail bytes at its address. Relocated fields (`jal` targets,
   `%hi`/`%lo`, gp-relative offsets) are masked, because the linker fills
   them in.
3. Each function gets a status. `MATCH` means the bytes agree after masking
   and the object fits the window; any retail bytes past the end of the object
   must be zero padding. `ASM` is an `INCLUDE_ASM` fallback and never counts
   as C. CONTRIBUTING.md lists every status and what to do about it.
4. The relocations of every `MATCH` are checked separately, because masking
   hides them from the byte comparison:
   - **WRONG CALLEE**: a `jal` names a different function from the one retail
     calls.
   - **WRONG SYMBOL**: the data symbol's address plus the addend cannot
     produce the immediate that retail encodes.

   Either one fails the run.

`--json PATH` writes each function's status, sizes, first differing offsets
and relocations. `--show-mismatches` prints details for failures.

## What the build checks

`python tools/build.py` compiles every unit and chooses which objects can be
linked in place of retail code. An object is **link-eligible** when its
functions and data can be placed at their retail addresses. The rest of the
image comes from retail assembly. GNU ld does the linking by default;
`docs/gnu_linker.md` explains how it places sections and when it rejects an
object.

The build then checks:

- the loadable image SHA-1, `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
- the rebuilt ELF SHA-1, `4eeec0360cf2715535d9f7e52eb69d786fb0158c`;
- the **link floor** in `config/link_floor.json`, the minimum number of
  source units in the link.

The floor exists because the hashes cannot see a unit falling out of the
link: its bytes come from retail assembly and the image still matches.
`python tools/explain_ineligible.py` says why a unit is not linked.
`--progress-report PATH` writes the list of linked functions used for
progress reports.

## What a MATCH does not prove

- **Names and types.** A match can still be `func_00219790(u8 *arg0)` with raw
  offsets. `tools/recovery_quality.py` scores naming, typing and comments
  separately.
- **That a pragma does anything.** MWCC accepts unknown pragmas without a
  diagnostic. `tools/pragma_audit.py` and `tests/test_pragma_audit.py` reject
  spellings the compiler ignores.
- **That a global is the one retail used.** Masked bytes cannot tell two
  symbols apart. WRONG SYMBOL and the full link can.
- **That the source is honest.** Assembly transcribed into `asm` statements
  matches by construction. `tools/decomp_lint.py` rejects it; see
  [Rules](Rules).
