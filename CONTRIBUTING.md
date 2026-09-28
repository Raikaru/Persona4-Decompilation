# Contributing

The project recovers readable C that reproduces Persona 4's retail machine
code. A useful contribution can be a new match, a proven type or name, a
better explanation of existing code, or a tooling fix.

Build the project first using [Getting Started](wiki/Getting-Started.md).
Keep retail files, proprietary tools and machine-local paths out of commits.
The [source rules](docs/STYLE.md) define acceptable C; the
[matching playbook](docs/matching.md) records measured compiler behavior.

## Pick a function

Start from a fresh verifier report rather than a progress badge or an old
handoff. Look for an assembly fallback in a file with related matching C,
or the last few unresolved functions in an otherwise recovered unit.

```sh
python tools/verify.py src/Battle/btlTarget.c
```

Read its callers, data users and neighboring functions before changing its
signature. Check [the probe archive](docs/probe_archive/) for previous
attempts. Repeating a failed experiment is useful only when you have new
evidence or a different hypothesis.

For code shared with Persona 3 FES:

```sh
make shared-p3 P3_ROOT=/path/to/Persona3-FES-Decompilation
```

Pass `P3_REPORT=/path/to/fresh-full-verify.json` when available; without it,
the mapper uses P3's committed progress snapshot. A corresponding P3 function
is evidence, not proof that P4 kept the same types or implementation.

## Match in the owning file

1. Get a draft, if needed:

   ```sh
   make m2c-setup  # once, before using m2c
   make m2c FILE=src/Battle/btlTarget.c FUNC=func_001ec630
   ```

   Replace inferred declarations and raw offsets with types supported by the
   surrounding code. Preserve the function's `// FUN_XXXXXXXX` marker.

2. Compile and compare the whole translation unit:

   ```sh
   python tools/verify.py --json build/btlTarget-verify.json src/Battle/btlTarget.c
   python tools/fndiff.py src/Battle/btlTarget.c func_001ec630
   ```

   Check the status of every function in the file. Shared declarations,
   literals and register allocation can change a sibling even when its body
   is untouched. `MATCH` in an extracted test function is not sufficient.

3. Classify the remaining difference, then change one source property at a
   time: a type, a loop, a value's lifetime or an addressing expression.
   Use [documented measurements](docs/matching.md), not a sequence of casts
   chosen only to move registers.

4. Keep an unmatched attempt behind `#ifdef NON_MATCHING`, with its
   `INCLUDE_ASM` fallback in the production branch. Record the residual and
   the evidence needed to revisit it. A small difference is still a difference.

5. Once it matches, run the checks under [Before sending a PR](#before-sending-a-pr).

`fndiff.py` shows instruction words, relocation annotations and differing-word
counts. Its count can include zero-filled alignment tails: a shorter C body
can still be a verifier `MATCH` when the remaining retail bytes are zero.
Use the verifier status rather than treating the diff count as the verdict.
For symbols without a marker, `--addr 00100008` supplies the retail address.

### Interactive diffing with objdiff

For function and data differences, including local jump tables:

```sh
make objdiff-objects ONLY=Battle/btlTarget
objdiff-cli diff -p . -u "Battle/btlTarget:001EC630"
```

`make objdiff` refreshes the config from a full verifier report;
`make objdiff-objects` also emits the referenced objects. Its default
`--skip-asm` mode prevents assembly fallbacks from earning C progress.
Use `SKIP_ASM=0` only when you want to inspect the spliced assembly.

Standalone `objdiff-cli diff -1 ... -2 ...` does not load project options.
Pass `-c functionRelocDiffs=none` to use the project's relocation-diff setting.
Publishing uses `tools/gen_decomp_report.py`, not this interactive report.

## Verifier statuses

A zero exit status is not proof of a new C match. The verifier accepts
`MATCH`, `ASM`, `NONMATCHING` and `STUB` rows; read the row for your function.

| Status | Meaning and response |
| --- | --- |
| `MATCH` | C bytes match within the retail window, allowing relocation masking and zero tails. Check object linkage too. |
| `ASM` | Extracted retail assembly, not recovered C. |
| `NONMATCHING` | An explicitly tagged C attempt still differs. Keep the production fallback. |
| `STUB` | A tracked shell without an implementation; not a match. |
| `MISMATCH` | C bytes differ. Inspect the instruction diff. |
| `SIZE_MISMATCH` | The object exceeds its window, or retail has a nonzero tail. Check boundaries and owned data; do not add padding to hide it. |
| `NO_SYMBOL` | The marked definition was not found in the object. Check its identifier and preprocessor guards. |
| `COMPILE_ERROR` | The whole source file failed to compile. Read the compiler diagnostic. |
| `STALE_NONMATCHING` | A tagged attempt now matches. Remove the stale tag and verify again. |
| `UNKNOWN_ADDR` | The marker address has no recognized function boundary. Investigate the map. |

The `NONMATCHING` marker tag and the `NON_MATCHING` preprocessor macro are
not interchangeable. The first labels a verifier result; the second selects
a candidate C body instead of its assembly fallback.

## Markers, names and boundaries

Each function belongs to one source file and retains its
`// FUN_XXXXXXXX` address marker. Do not delete a marker to remove a failure
from the denominator, or split a real translation unit to obtain an isolated
match. `src/generated/` contains non-authoritative `M2C_CANDIDATE` drafts.

For evidence-backed name changes, edit `config/symbol_names*.txt`, then run:

```sh
make reconcile
python tools/apply_symbol_names.py
make names-check
```

The migration updates non-generated C and headers together. Generated
assembly filenames and symbols retain their address-form spellings; the
build maps them to the same canonical address. Do not rename generated
assembly to make a C migration pass.

Investigate suspicious boundaries before implementing an empty or
one-instruction function. A raw `.word` marked as data, a branch into a
neighbor, or a lone `jr $ra; nop` may be a bad split rather than a function.
Look for callsites and data pointers. Record a proven data-reachable entry
in `DATA_REACHABLE_ENTRIES` in `tools/reconcile_function_boundaries.py`, with
its pointer site, and regenerate the map. Do not hand-edit
`tools/slus21782_functions.json` or change marker counts to conceal a loss.

## Generated assembly and recovery archives

`make regenerate-asm` rebuilds manifest-listed fallbacks from the
hash-validated retail ELF. It refuses unexpected edits to existing outputs
and checks the regenerated SHA-256 values. To check reproduction without
replacing output files:

```sh
P4_RETAIL_ELF="/path/to/SLUS_217.82" python tools/regenerate_asm.py --check
```

The generator accepts `orig/SLUS_217.82`, `P4_RETAIL_ELF` or `--retail PATH`;
it does not read the ignored compiler configuration files. It needs the
pinned Python dependencies, not the proprietary compilers.

A fallback change must be reproducible through a generator recipe or
correction, or explicitly retained as hand-maintained assembly in both the
manifest and Git. Do not change an expected hash merely to accept drift.
Untracking generated files requires clean-checkout reproduction and the
proprietary CI rebuild; a skipped CI job is not evidence.

Keep assembler support, manual exceptions and `docs/probe_archive/` tracked.
The archive contains C attempts and measurements that cannot be regenerated
from the executable.

## Before sending a PR

For source recovery:

- Show `MATCH` for each changed function and retain the matches in its whole
  owning file. Include the scoped verifier output in the PR.
- Run `python tools/decomp_lint.py <changed-file.c>`. Fix integrity errors;
  review advisories. A note saying "measured" does not justify a fake ABI,
  register-pinning trick or assembly transcription.
- Compile affected guarded attempts with `NON_MATCHING` enabled when changing
  shared declarations or types. The production branch alone cannot check them.
- Run `make verify` and `make build-progress`. Both retail hashes must pass,
  and the changed C object must remain in `build/linked_report.json`.
  A build can fall back to retail bytes and keep the hashes correct while
  losing C linkage. Use `python tools/explain_ineligible.py --reason unresolved`
  to investigate unresolved symbols.
- Explain non-obvious type, boundary or compiler-option changes with their
  evidence. Keep the diff focused.

For tooling changes, run `make test` and exercise the changed command. If
progress generation changes, also run `make progress-validate`. Preserve
published category IDs such as `main` and the badge measures when changing
reports; they are consumed outside the repository.

## Matching is not the finish line

A matching body with raw offsets and decompiler names still needs recovery.
Use names that describe observed behavior, fields supported by layout
evidence, and comments that explain non-obvious operations or constants.
Do not imply a descriptive name is an original Atlus symbol.

```sh
make recovery
```

This ranks matched first-party code by naming, typing and documentation
heuristics. Treat it as a way to find work, not as proof of source quality.
Moving a function from an anonymous promoted bucket into a proven original
unit is useful; splitting a known unit for tidiness can change the generated
code and layout.
