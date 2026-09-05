# Contributing to the Persona 4 PS2 Decompilation

This is a matching decompilation: C source that, when compiled with the retail
toolchain (MWCCPS2 3.0.1 b210, `-O2 -Iinclude`), reproduces the Persona 4 USA
(`SLUS_217.82`) executable byte-for-byte. A function "matches" when the
per-function verifier reports `MATCH`; only `MATCH` functions enter the
authoritative matching build.

Read these before starting:

- [`README.md`](README.md) — setup, build, and tooling overview.
- The [wiki](https://github.com/Raikaru/Persona4-Decompilation/wiki) — how
  matching works, the retail build, the RenderWare port, the rules.
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

The scoring tools (`tools/floor_census.py`, `tools/recovery_quality.py`)
show where the cheap work is; the wiki's *Matching a Function* page walks
through it. In practice the most productive picks are:

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

A contribution lands when it passes the same gate every commit passes (the
wiki's *Rules* page). As a contributor, that means your PR includes:

- **Focused verifier evidence for every changed function**: the scoped
  `python tools/verify.py --json ... <file.c>` run showing `MATCH` for what you
  changed (paste the output in the PR description).
- **A clean full run**: `python tools/verify.py` with no new unexpected
  statuses. Do not commit while any function you touched is `MISMATCH`,
  `SIZE_MISMATCH`, `NO_SYMBOL`, or `COMPILE_ERROR`.
- **Clean integrity checks** per `docs/STYLE.md`. Review advisory warnings and
  record useful compiler measurements; generic `measured` notes do not waive
  H002/H009. Those exceptions require a rule-specific semantic reason.
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
- **Published progress ids are a public contract.** The README badges are served
  by decomp.dev from the objdiff report, and the first-party badge selects
  `category=main` from `PROGRESS_CATEGORIES` in `tools/gen_objdiff.py`. Renaming
  a category id silently changes what that badge reports — decomp.dev answers
  200 either way — so `tests/test_recovery_quality.py` pins the README's
  `category` and `measure` values against the ids we actually emit. Change both
  together or not at all.
- **No junk in the tree**: no retail files, compiler outputs, or local scratch
  data in commits; minimal diffs — never reformat unrelated code.
- **Full-build ownership stays with the integration lane.** Byte-identical
  load-image/ELF verification, commits, and pushes are the lane's job; your PR
  proves per-function `MATCH` and leaves the whole-image gate to it.
- **The owning object must stay link-eligible.** A per-function `MATCH` is not
  the finish line. `tools/verify.py` masks relocations, so a wrong or missing
  symbol passes every per-function check and only shows up at link time, as a
  fall in `C objects linked from source` while both retail hashes still verify.
  If the count drops after your change, the cause is almost always a symbol your
  new C references that the object cannot resolve, and the fix is to resolve it
  (or to match the still-unresolved sibling), never to accept the loss. Run
  `python tools/explain_ineligible.py --reason unresolved` to see which units are
  blocked and on what symbol.
- **Boundary confidence for suspicious functions.** Before writing C for an empty
  body, a one-instruction body, or an address suspiciously close to its
  neighbour, prove the boundary is real:
  - If the function's `.s` begins with a raw `.word ... /* data */`, it is not a
    function. A backward-branch word means Ghidra split the tail off the previous
    function's loop; a forward-branch word means it split the head. Leave the
    `INCLUDE_ASM` in place and say so — do not invent a function that does not
    exist.
  - For a bare `jr $ra; nop`, decide whether it is padding or a real nullsub by
    looking for a reference: a `jal` to it, or a pointer word holding its address
    (a callback slot). No reference means it is padding inside the preceding
    window and must not get its own marker.
  - A genuinely data-reachable entry belongs in `DATA_REACHABLE_ENTRIES` in
    `tools/reconcile_function_boundaries.py`, with the pointer site recorded, so
    the canonical map and `tests/test_reconcile.py` agree. Never hand-edit
    `tools/slus21782_functions.json`.

## Matching is not the finish line

A byte-identical function can still be unreadable: `func_00123456` for a name,
`D_007973A0` for a global, `u8 *` for an object pointer, numeric field offsets,
`temp_3`/`uVar1` locals, and unexplained masks. The README status table therefore
reports matching and recovery separately, and
`python tools/recovery_quality.py --report <verify.json>` scores every matched
first-party function on three axes that have nothing to do with byte equality:

- **NAMED** — the identifier is not a `func_<address>` placeholder. A neutral
  descriptive name recovered from behaviour is far better than an address, and
  better than an overconfident guess at the original Atlus identifier. Keep the
  address discoverable in symbol metadata, not in the function name.
- **TYPED** — the body reaches its data through named fields rather than
  cast-and-offset arithmetic or `M2C_FIELD`. Raw offsets are a legitimate
  *starting* point; they are not a finished one.
- **DOCUMENTED** — anything non-trivial explains what it does, and any
  non-obvious constant explains why it is that value.

`tools/recovery_quality.py --worst 20` lists the files with the most
matched-but-untyped functions. Improving those is real work on the same footing
as converting a new fallback, and a PR that only does cleanup is welcome.

`src/promoted/` is transitional. It mixes recovered translation-unit names such
as `calendar.c` and `cmmScript.c` with generic `code1_00NN.c` buckets that exist
only because the owning unit was not known when the function was matched. Moving
a function from a generic bucket into its evidence-backed unit is an improvement;
splitting a real translation unit for tidiness is not, because unit boundaries
affect section layout and the link.
