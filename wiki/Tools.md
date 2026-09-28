# Tools

Run everything from the repository root. Most scripts print their options
with `--help`, and each one's docstring describes it in more detail. This page
lists the ones you are likely to need.

## Setup and build

| Command | Does |
| --- | --- |
| `make setup ISO=...` (`tools/setup.py`) | checks the disc hash, writes `orig/` and `image.bin` |
| `make split` | runs splat on `image.bin` |
| `make regenerate-asm` (`tools/regenerate_asm.py`) | recreates manifest-listed `INCLUDE_ASM` fallbacks and checks their hashes; `--check` compares without writing |
| `make build` (`tools/build.py`) | compiles, links eligible objects, checks both SHA-1s and the link floor; `--progress-report PATH`, `--linker-backend gnu\|mwld`, `--setup-only` |
| `make verify` (`tools/verify.py [files]`) | per-function comparison with retail; `--json PATH`, `--show-mismatches`, `--skip-gcc-units` |
| `make` | `build`, then `verify` |
| `make test` | tooling tests under `tests/` |
| `make lint`, `make lint-errors` (`tools/decomp_lint.py`) | source-honesty and marker checks on first-party code; `--list` prints the rules |
| `tools/explain_ineligible.py` | why a unit is not in the link |

`tools/mwccgap/` (vendored) compiles a unit with MWCC and assembles its
`INCLUDE_ASM` bodies into the object. `tools/eegcc_shim.py` does the same job
for ee-gcc units.

## Working on a function

| Command | Does |
| --- | --- |
| `tools/fndiff.py <file> <function> [--addr]` | object against retail, word by word, with relocations |
| `tools/fnalign.py <file> <function> [--candidate body.c]` | aligns object and retail instructions, so a missing or extra instruction shows as one edit instead of shifting every later row |
| `make m2c-setup`, `make m2c FILE= FUNC=` | install pinned m2c; draft one function into `build/m2c/` |
| `make ctx CTX_SRC=<file>` (`tools/m2ctx.py`) | flattened context for decomp.me or the permuter |
| `tools/recon_dis.py <addr>` | retail disassembly; decodes EE COP1/VU instructions when a Ghidra server is running |
| `tools/eedis.py`, `tools/jtbl.py` | decode one EE instruction; decode a switch jump table |
| `tools/micro_codegen.py` | compile a standalone snippet with the project's MWCC and print the code |
| `tools/pragma_sweep.py`, `tools/probe_variants.py`, `tools/probe_search.py` | try pragmas or source spellings in isolated copies of the unit |
| `tools/permute.py`, `tools/permute_ast.py` | randomized source search, scored by the verifier's masked comparison |
| `tools/park.py` | move a candidate body behind `#ifdef NON_MATCHING` at a bare fallback |
| `make objdiff`, `make objdiff-objects ONLY=<unit>` | objdiff project and objects for interactive diffing |

## Finding work

| Command | Does |
| --- | --- |
| `tools/floor_census.py --report <verify.json>` | unattempted functions versus recorded floors |
| `tools/recon_pool.py` | ranks candidates by measurement |
| `tools/nd_audit.py`, `tools/probe_archive.py` | re-measure parked and archived attempts |
| `make recovery` (`tools/recovery_quality.py`) | matched files that still need names, types or comments |
| `make shared-p3 P3_ROOT=...` (`tools/map_shared_p3.py`) | map Persona 3 FES functions to their P4 counterparts |
| `tools/ida_headstart.py`, `tools/ghidra_headstart.py` | batch decompiler drafts for unmatched first-party functions |

## Symbols, names and boundaries

| Command | Does |
| --- | --- |
| `tools/recover_symbols.py` | regenerates `config/symbols_recovered.txt` from matched code and `config/symbol_data_addrs.txt` |
| `make names` | port P3 names, mine name strings, reconcile the map, apply names to the source |
| `make names-check` | fails if a recovered name has not been applied |
| `make reconcile` (`tools/reconcile_function_boundaries.py`) | rebuilds the canonical function map and `config/symbol_addrs.txt` |
| `make file-strings`, `make tu-audit P3_ROOT=...` | original file names from `__FILE__` strings; proposed unit boundaries |
| `tools/port_rw_names.py` | vendor-library names from other games' symbol tables |

## Progress

| Command | Does |
| --- | --- |
| `make build-progress` | build and write `build/linked_report.json` |
| `make progress` | full verify, then regenerate `progress/` and the README status table |
| `make progress-validate` | check the committed `progress/` files |
| `make objdiff-report` (`tools/gen_decomp_report.py`) | the decomp.dev report, from verifier data |
