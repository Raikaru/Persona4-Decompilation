# Tools

Everything runs from the repository root with `python tools/<name>.py`. Set
`PYTHONNOUSERSITE=1` (or use `python -E -s`) so a user site-packages cannot
change the toolchain's behaviour; the Makefile does this for you.

## The pipeline

| Tool | Does |
| --- | --- |
| `setup.py` (`make setup`) | verifies the ISO against Redump, extracts `orig/SLUS_217.82` and `image.bin` |
| `build.py --setup-only`, `make split` | writes the splat configuration and extracts the retail assembly |
| `verify.py [files] [--json report]` | compiles, compares every marker, cross-checks callees and data symbols; the authoritative score |
| `build.py [--progress-report json]` | compiles, decides link eligibility, links, checks both SHA-1s and the link floor |
| `decomp_lint.py [files]` | style, pragma-justification, inline-asm, marker and CRLF rules; `--errors-only` for the gate |
| `pragma_audit.py` | compiles every pragma spelling in the tree against the real compiler; inert ones fail the test |
| `progress.py`, `recovery_quality.py`, `gen_decomp_report.py` | the README table, `progress/` endpoints and the decomp.dev report |
| `mwccgap/` | the compile wrapper that splices `INCLUDE_ASM` bodies in (vendored) |
| `eegcc_shim.py` | drives ee-gcc 2.96 for the GCC units |

## Working on a function

| Tool | Does |
| --- | --- |
| `fndiff.py <file> <func> [--addr]` | side-by-side disassembly of your object vs retail, relocations annotated |
| `m2c_decompile.py` (`make m2c FILE= FUNC=`), `m2c_bulk.py` | decompiler first drafts into `src/generated/` |
| `build/RECON_dis.py <addr>` | retail disassembly of a window; Ghidra-backed (`gmcp serve --port 8091 --file orig/SLUS_217.82`) so EE COP1/VU ops decode |
| `knob_sweep.py`, `probe_variants.py`, `permute*.py` | try pragma spellings / source permutations on a candidate automatically |
| `floor_census.py`, `nd_audit.py`, `residual_census.py` | rank open functions by size, measured distance, floor category |
| `probe_archive.py`, `build/archive_sweep.py` | manage and re-measure `docs/probe_archive/` |
| `gen_objdiff.py` (`make objdiff`) | objdiff-cli project for interactive whole-object diffing |
| `map_shared_p3.py` (`make shared-p3`) | Persona 3 FES twin map |

## RenderWare

| Tool | Does |
| --- | --- |
| `build/rw_fid.py` | fingerprint the RenderWare sources against the block -> `build/rw_fid.json`, `build/rw_map.txt` |
| `build/rw_port.py <dir>/<file>.c [--install]` | generate, verify and install a verbatim unit |
| `build/rw_hints.py` | rwID / memory-hint constants, gp slots and calls per block function |

## Symbols and names

| Tool | Does |
| --- | --- |
| `recover_symbols.py` | `config/symbol_data_addrs.txt` -> `config/symbols_recovered.txt` (run after adding a symbol) |
| `apply_symbol_names.py`, `port_p3_names.py`, `mine_name_strings.py`, `file_strings.py` | name recovery from strings and the P3 twin |
| `reconcile_function_boundaries.py` (`make reconcile`), `attribute_windows.py`, `tu_audit.py` | keep the window table, markers and units consistent |
