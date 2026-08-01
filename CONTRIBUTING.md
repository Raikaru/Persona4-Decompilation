# Contributing to the Persona 4 PS2 Decompilation

This is a matching decompilation: C source that, when compiled with the retail
toolchain (MWCCPS2 3.0.1 b210, `-O2 -Iinclude`), reproduces the Persona 4 USA
(`SLUS_217.82`) executable byte-for-byte. A function "matches" when the
per-function verifier reports `MATCH`; only `MATCH` functions enter the
authoritative matching build.

Read these before starting:

- [`README.md`](README.md) — setup, build, and tooling overview.
- [`ROADMAP.md`](ROADMAP.md) — completion criteria, current priorities, and the
  operating model (parallel workers, integration gate).
- [`docs/matching.md`](docs/matching.md) — the source-shaping playbook for
  MWCCPS2 codegen.
- [`docs/STYLE.md`](docs/STYLE.md) — source-quality and honesty rules.

## Prerequisites

From [`README.md`](README.md):

- Python 3.10 or newer.
- `python -m pip install -r requirements-python.txt`.
- GNU `mipsel-linux-gnu-as` and `mipsel-linux-gnu-objcopy` with R5900 support.
- MWCCPS2/MWLDPS2, currently `mwcps2-3.0.1b210-060308`.
- A legally owned Persona 4 USA disc image (the setup tool checks it against
  the Redump record before extracting).

The tooling resolves the compiler and retail executable from the machine-local
`tools/verify_config.local.json` and `tools/build_config.local.json` files, or
from the `P4_MWCC` / `P4_RETAIL_ELF` / `P4_AS` / `P4_OBJCOPY` environment
variables. The committed `tools/verify_config.json` holds only the shared
defaults (`compile_flags: ["-O2", "-Iinclude"]`); never put machine-local
absolute paths there.

## Setup

Follow the "Setup" and "Build" sections of [`README.md`](README.md):

```sh
python -m pip install -r requirements-python.txt
make setup ISO="D:/path/to/Shin Megami Tensei - Persona 4 (USA).iso"
make split
make
make test
```

`make setup` writes the ignored `orig/SYSTEM.CNF`, `orig/SLUS_217.82`, and
`image.bin`. `make` builds the retail image and runs the authoritative
verifier. Verify your toolchain with `make verify` before starting work
(equivalent to `python tools/verify.py`).

## How to pick a target function

Priorities live in [`ROADMAP.md`](ROADMAP.md): the P4 synchronization lane
(unique address-normalized counterparts of P3-verified functions that are
ready but not yet P4-matched), then the milestone subsystem lists. In practice
the most productive picks are:

- **Functions in files that already have matches.** Getters, setters, flag
  checks, copy loops, and cleanup/destroy functions match far more reliably
  than update/render functions.
- **The P3-derived pool.** `make shared-p3 P3_ROOT=../Persona3-FES-Decompilation`
  (documented in `README.md`) regenerates the cross-game map; P3 `MATCH` source
  is the best starting point for its P4 counterpart.
- **Near-complete files** — close the last one or two functions in a file that
  is otherwise matching, so the whole translation unit can be C-linked.

Before editing a candidate, confirm its current status:

```sh
python tools/verify.py src/Battle/btlTarget.c
```

## The measure/iterate loop

1. **Get a first draft.** Use m2c per the "Decompiling" section of
   `README.md` (`make m2c FILE=... FUNC=...`), then replace inferred names and
   types with project definitions.
2. **Measure.** Compile the file and compare every tracked function against
   retail, writing a JSON report:

   ```sh
   python tools/verify.py --json build/verify_report.json src/Battle/btlTarget.c
   ```

   Output looks like:

   ```text
   functions scanned: 4
     MATCH              4
   report: build/verify_report.json
   ```

   The report contains a `summary` (status counts) and one `results` entry per
   function with `status`, `object_size`, `window`, `normalized_diff`
   (reloc-masked differing bytes), `first_diffs`, and `relocations`. Scoped
   runs on one file take under a second; the full run over `src/` takes about
   10 seconds. Reports and objects belong under `build/`, which is ignored.

3. **Diff.** For an instruction-level view of one function:

   ```sh
   python tools/fndiff.py src/Battle/btlTarget.c func_001ec630
   ```

   This prints the object and retail words side by side, disassembled, with
   relocation annotations. Rows marked `!` are real reloc-masked differences;
   the trailing `differing words (reloc-masked): N` count also includes
   zero-padding tail words when the object is shorter than the retail window
   (for example a 148-byte object in a 160-byte window reports 3, and a
   108-byte object in a 112-byte window reports 1 — both are `MATCH`
   functions). `--addr` overrides the retail address when the function has no
   `// FUN_` marker: `python tools/fndiff.py src/foo.c fn --addr 00100008`.

4. **Shape the source.** Apply the levers in
   [`docs/matching.md`](docs/matching.md) — types, branch polarity, loop shape,
   caching, addressing form — one at a time, re-running step 2 after each
   change. When the only remaining difference is a documented compiler floor,
   park the function (see `NONMATCHING` below) and move on.

5. **Confirm.** Finish with the full run:

   ```sh
   python tools/verify.py
   ```

   The current baseline is **1942 functions scanned, 1843 `MATCH` + 99 `ASM`**.
   Your change must not introduce any unexpected status.

**Exit codes.** `verify.py` exits non-zero only when a row has an unexpected
status (`MISMATCH`, `SIZE_MISMATCH`, `NO_SYMBOL`, `COMPILE_ERROR`,
`STALE_NONMATCHING`, or `UNKNOWN_ADDR`). `MATCH`, `ASM`, `NONMATCHING` and
`STUB` rows do not fail the exit code — read the status lines, and never chain
`verify && git commit` as if a green exit code proved a match.

## Interactive diffing with objdiff

`fndiff.py` prints a static column dump. For an interactive, whole-object diff
(functions **and** data, including the function-owned `.rodata` jump tables the
per-function verifier does not compare), use
[objdiff](https://github.com/encounter/objdiff). Download `objdiff-cli` from its
releases page; the repo is configured for v3.7.3 or newer.

Generate the config and the per-unit object files, then diff one unit:

```sh
make objdiff-objects ONLY=Battle/btlTarget
objdiff-cli diff -p . -u "Battle/btlTarget:001EC630"
```

`make objdiff` regenerates `objdiff.json` alone; `make objdiff-objects` also
emits the objects it references (all 880 units take about 45s, and re-runs are
incremental). A whole-project progress report:

```sh
objdiff-cli report generate -p . -o build/objdiff_report.json
```

Two things to know when reading the numbers. A one-shot
`objdiff-cli diff -1 <target.o> -2 <base.o> <symbol>` does **not** pick up the
project's options, so pass `-c functionRelocDiffs=none` to match what project
mode does — otherwise every relocated operand shows as a spurious immediate
difference. And a function whose body is an `INCLUDE_ASM` stub is deliberately
left holding its full retail window, so it reports slightly under 100%: that is
correct, an asm fallback is not a decompiled match.

## Verifier statuses

| Status | Meaning | What to do |
| --- | --- | --- |
| `MATCH` | Object bytes equal retail within the window, relocation-masked. | Done. Keep the marker as-is. |
| `ASM` | The function is an `INCLUDE_ASM` stub: byte-correct by construction, because it *is* the extracted retail assembly. Tracked and accepted by the exit code, but deliberately **not** counted as `MATCH`. | This is the normal starting state for undecompiled work. Replace the `INCLUDE_ASM` line with real C, then iterate until the verifier reports `MATCH`. Never report an `ASM` row as decompiled progress. |
| `MISMATCH` | Body bytes differ (`normalized_diff > 0`); the marker line is not tagged `NONMATCHING`. | `fndiff.py` the function, classify the difference, apply `docs/matching.md` levers. If it is a proven compiler floor, tag the marker `NONMATCHING` so the row becomes a parked `NONMATCHING` instead of a failing one. |
| `SIZE_MISMATCH` | No differing bytes, but the object is longer than the window, or retail has nonzero bytes after the object's end. | Object longer than window: check the window boundaries and for duplicate/overlapping markers. Nonzero retail tail: the window extends past your function (owned data, or an unmarked sibling function); do not pad — fix the boundary or give the sibling its own marker. |
| `NO_SYMBOL` | The verifier could not find the function name in the compiled object. | The C identifier after the marker does not match any emitted symbol: check the name and that the definition actually compiles into the file's translation unit. |
| `COMPILE_ERROR` | The file failed to compile (`detail` holds the start of the compiler log). | Fix the C (missing include, bad type, undeclared extern). The whole file is one translation unit, so any error anywhere in it fails every function in the file. |
| `STALE_NONMATCHING` | The marker is tagged `NONMATCHING` but the function now matches. | Remove the `NONMATCHING` tag from the marker line and re-verify. |
| `STUB` | The marker body is a TODO shell with no real code. | Implement the function. |
| `NONMATCHING` | Deliberately parked (marker line carries the `NONMATCHING` tag). This is how proven compiler walls are recorded; the exit code treats it as acceptable. | Leave parked functions alone unless you have a new lever from `docs/matching.md`. Remove the tag only when the verifier reports `MATCH`. |
| `UNKNOWN_ADDR` | No plausible function boundary above the marker address. | The marker address is not in the function map — check the address. |

## Conventions you must follow

### Translation units and function markers

Each `src/**/*.c` file is one real translation unit: it is compiled whole
(one C file == one object) by `verify.py` and the matching build, so it can
carry one shared `#include`, typedef block, and set of externs for all the
functions it owns. Add new functions to the file that owns their addresses;
the `/* Source unit: <original.c> */` comment at the top of many files names
the original retail translation unit the file was recovered from.

A function that is deliberately parked on a compiler floor keeps its C body
behind `#ifdef NON_MATCHING` with an `INCLUDE_ASM` fallback in the `#else`
arm, so the object still carries the exact retail bytes while the C stays
findable for whoever finishes it:

### `// FUN_XXXXXXXX` markers

- Every tracked function has a marker comment `// FUN_XXXXXXXX` (8 uppercase
  hex digits) immediately above its definition.
- **The marker text is the tracking key.** `verify.py` resolves tracked
  functions by marker text, not by the C identifier — the two legitimately
  differ in places (for example `// FUN_001EC630` above `f32 func_001ec630`).
  Never change a marker's casing, prefix, or address.
- A marker line may carry the `NONMATCHING` tag (e.g.
  `// FUN_0077F710 NONMATCHING`) to park a function on a documented compiler
  floor. The tag is case-sensitive and must appear on the marker line itself.
- `src/generated/` holds m2c candidate output (`M2C_CANDIDATE` markers) and is
  excluded from normal verification. Do not treat it as authoritative source.

## What makes a PR acceptable

A contribution lands when it satisfies the integration gate in
`ROADMAP.md`. As a contributor, that means your PR includes:

- **Focused verifier evidence for every changed function**: the scoped
  `python tools/verify.py --json ... <file.c>` run showing `MATCH` for what you
  changed (paste the output in the PR description).
- **A clean full run**: `python tools/verify.py` with no new unexpected
  statuses. Do not commit while any function you touched is `MISMATCH`,
  `SIZE_MISMATCH`, `NO_SYMBOL`, or `COMPILE_ERROR`.
- **No banned constructs** per `docs/STYLE.md`, and a `measured`-annotated
  waiver for any genuinely load-bearing steering construct.
- **Marker and boundary hygiene**: correct `// FUN_` markers, no duplicate
  addresses, no markers without definitions. The reconciliation tools are
  documented in `README.md`; the integration gate validates markers and
  boundaries.
- **Tests for tooling changes**: `make test` for the deterministic unit tests,
  and `make progress-validate` whenever `progress/` files or `tools/progress.py`
  change (this is also what CI runs on push). `make test` is green — treat any
  failure as a real regression. `tests/test_marker_tripwire.py` asserts the
  exact total marker count as a tripwire against silently dropped or duplicated
  markers, and that no first-party file regresses to the old per-function guard
  scheme; when you genuinely add functions, bump the count deliberately and say
  so, and never bump it to silence a drop you did not intend.
- **No junk in the tree**: no retail files, compiler outputs, or local scratch
  data in commits; minimal diffs — never reformat unrelated code.
- **Full-build ownership stays with the integration lane.** Byte-identical
  load-image/ELF verification, commits, and pushes are the lane's job; your PR
  proves per-function `MATCH` and leaves the whole-image gate to it.
