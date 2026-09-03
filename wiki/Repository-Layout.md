# Repository Layout

```text
src/                    matching C, one file per original translation unit
  Battle/ Camp/ Event/ Graphics/ Kernel/ Kosaka/ Main/ Scene/ Script/ Yajima/
                        Atlus's engine, grouped by the original directory names
                        recovered from the executable's __FILE__ strings
  *.c at the top level  units whose original name is known but not their directory
  promoted/code1_XXXX.c units named by address range until their original name is found
  renderware/           RenderWare Graphics 3.7, ported verbatim (build 119 units)
  rw/ cri/ sce/ middleware/
                        prebuilt vendor code: tracked as assembly for the image
  generated/            raw m2c candidates (M2C_CANDIDATE), never authoritative
include/                type.h and the project headers; include/rw/ is the RenderWare SDK
asm/                    macro.inc and the split retail assembly (asm/nonmatchings/, ignored)
config/
  target.json           the executable's identity (entry, gp, segments, SHA-1s)
  symbol_data_addrs.txt curated data symbols with evidence; the input to
  symbols_recovered.txt the generated symbol table the linker defines (do not hand-edit)
  compiler_units.txt    unit -> compiler version (cw3.0.1b119 for src/renderware)
  version_flags.txt     compiler version -> extra flags (-O4 -inline auto ... for b119)
  speed_units.txt       units compiled -O2,p / -O4,p
  gcc_units.txt         units compiled with ee-gcc 2.96
  link_floor.json       ratchet: how many C objects must be in the link
tools/                  setup, split, build, verify, lint, progress, analysis (see Tools)
tools/slus21782_functions.json
                        the canonical function windows
build/                  build output and reports (ignored) plus a few checked-in
                        research scripts (RECON_dis.py, rw_fid.py, rw_port.py, ...)
tests/                  deterministic tests for the tooling (python -m unittest discover -s tests)
docs/
  matching.md           the playbook: every residual pattern and the lever that fixed it
  STYLE.md              naming, typing and honesty rules for src/
  compiler-floors.md    shapes the compilers will not emit, with evidence
  probe_archive/        best candidate for every attempted-but-unmatched function
progress/               progress endpoints published to GitHub Pages
orig/ image.bin         extracted retail files (ignored)
.github/workflows/      CI: checks on every push; the proprietary build job
                        fetches the compilers from a private repository
Dockerfile              the CI image (binutils, wibo, Python deps)
```

## Markers, fallbacks and ownership

Every retail function window belongs to exactly one `// FUN_XXXXXXXX` marker
in exactly one file under `src/` (excluding `src/generated/`). What follows
the marker is either matching C or an `INCLUDE_ASM(...)` line naming the split
assembly file. `tests/test_marker_tripwire.py` and `tools/tu_audit.py` keep
the set of markers consistent with `tools/slus21782_functions.json`.

## Unit naming

Atlus's build embedded `__FILE__` in assert strings, so most units carry their
original names (`btlUnit.c`, `k_fldEvent.c`, ...). Windows the strings do not
cover live in `src/promoted/code1_XXXX.c` by address range; when a unit is
identified it is renamed without moving any marker.
