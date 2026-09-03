# How Matching Works

## The unit of work is a function window

`tools/slus21782_functions.json` lists 13,102 function start addresses for the
retail executable and the size of each one's window (up to the next
function). Every window is owned by exactly one source file through a marker
comment:

```c
// FUN_00195850
s32 func_00195850(BattleUnit *unit) { ... }
```

A window whose C is not matched yet keeps its retail assembly instead:

```c
// FUN_00195850
INCLUDE_ASM("asm/nonmatchings/btlUnit", func_00195850);
```

The marker is the verifier's denominator. Deleting or moving one changes what
is being measured, so the tooling counts them and CI fails on unexplained
changes.

## What the verifier does

`python tools/verify.py [files]`:

1. Compiles each file with the compiler and flags configured for that unit
   (see [The Retail Build](The-Retail-Build)), through `tools/mwccgap`, which
   splices the `INCLUDE_ASM` bodies in as assembly.
2. Extracts every marked function from the object and compares it with the
   retail bytes at the marker address, masking the relocation fields (`jal`
   targets, `%hi`/`%lo`/gp-relative immediates) because those are only fixed
   at link time.
3. Reports one status per function:
   - `MATCH` - byte-identical after masking, and the object is not longer than
     the window (trailing window bytes must be zero padding).
   - `ASM` - the `INCLUDE_ASM` fallback; correct by construction, not C.
   - `MISMATCH` / `SIZE_MISMATCH` - live C that differs; never committed.
   - `NONMATCHING` - C kept under `#ifdef NON_MATCHING` beside its fallback.
   - `COMPILE_ERROR`, `NO_SYMBOL`, `UNKNOWN_ADDR` - tooling-level problems.
4. Cross-checks relocations of every `MATCH` function, because masking makes
   the byte comparison blind to them:
   - **WRONG CALLEE** - the `jal` names a function other than the one retail
     calls at that offset.
   - **WRONG SYMBOL** - a data symbol whose address plus the candidate's
     addend cannot produce the immediate retail encodes (gp-relative,
     `%hi`/`%lo` with carry). This caught seven wrong-but-plausible symbols in
     otherwise matching functions the day it was added.

Both checks are hard failures. `verify.py --json` writes a report with every
function's status, sizes, first differing offsets and relocations; the
per-wave reports under `build/` are how progress is diffed.

## What the build does

`python tools/build.py` compiles every unit, decides which objects are
**link-eligible** (a C object whose functions are contiguous in retail and
whose data can be placed at its retail addresses), links those with the retail
assembly of everything else, and checks:

- the loadable image SHA-1 (`3d1d3d2b...`),
- the ELF SHA-1 (`4eeec036...`),
- the **link floor** (`config/link_floor.json`): the number of C objects in the
  link may only go up. A unit silently losing eligibility falls back to retail
  bytes, which neither SHA-1 nor the per-function verifier can see.

The full link is the last line of defence for symbol mistakes in link-eligible
units; the WRONG SYMBOL check covers the units that are not linked.

## What a MATCH does not prove

- That names and types are right. A matching function can still be
  `func_00195850(u8 *arg0)` with raw offsets; `tools/recovery_quality.py`
  scores that separately (NAMED / TYPED / DOCUMENTED in the README table).
- That a pragma did anything. MWCC ignores unknown pragmas silently;
  `tools/pragma_audit.py` compiles every spelling in the tree against the real
  compiler and `tests/test_pragma_audit.py` fails on any that are inert.
- That the global you named is the one retail used - that is what WRONG
  SYMBOL and the full link are for.
