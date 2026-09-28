# RenderWare

Persona 4 links Criterion's RenderWare Graphics 3.7 as prebuilt libraries.
The part in the `code1_0039` to `code1_003e` address block was built with
MWCCPS2 3.0.1 build 119 at `-O4,p -inline auto`
([The Retail Build](The-Retail-Build) has the evidence).

The RenderWare 3.7.0.2 source is public, so this block is recovered from it
**verbatim**: the original file text, names, macros (`RWFUNCTION`,
`RWASSERT`, `RWRETURN`, ...) and comments, compiled against the RenderWare
headers.

## Where the files are

- `src/renderware/{plcore,core,p2,world,worldp2}/` mirror the source tree,
  one unit per original file. Each is listed as `cw3.0.1b119` in
  `config/compiler_units.txt` and in `config/speed_units.txt`.
- `src/promoted/code1_0039_cw119.c` to `code1_003e_cw119.c` hold functions
  matched under build 119 before the RenderWare source was used.
  `code1_0039.c` to `code1_003e.c` hold build-210 matches and the fallbacks
  for functions not ported yet.
- `src/rw/` holds other retail RenderWare functions grouped by their
  original source file; `docs/sky2/rw_unit_attribution.json` records the
  attribution. Many are still `INCLUDE_ASM`.
- `include/rw/` holds the headers: `inc/` (public) and the source-tree
  directories (`plcore/`, `core/`, `p2/`, `world/`, ...), the null driver
  (`drvnull/`, `p2null/`, `worldp2null/`), `ps2/` (project-written
  `ostypes.h` and friends for the PS2 target), and `std/` (C library shims for
  `-nosyspath`).
- `include/rw/sky2/` and `sky2priv/` are RenderWare 3.5 PS2 headers kept as
  a reference for the driver API. Do not put them ahead of the 3.7 include
  path; `include/rw/sky2/README.md` explains why.

## How a unit is ported

A ported file starts with a comment naming its source file and compiler.
Then:

- file-scope `static` data becomes `extern` at its retail address, registered
  in `config/symbol_data_addrs.txt`, so the unit links;
- a callee not yet ported under its RenderWare name is mapped to the retail
  function with a `#define` before the includes, for example
  `#define RwFopen func_003dddf0`, so the header prototype declares the right
  symbol;
- only functions that verify as `MATCH` keep a `// FUN_` marker; the rest
  stay with their fallbacks in the `code1_00XX.c` files.

The scripts used to fingerprint the RenderWare source against retail and
generate ported units were local research scripts under the ignored `build/`
directory. They are not in the repository.

## The PS2 driver

The public 3.7.0.2 source has no `sky2` (PS2) driver, so roughly 300 driver
functions have no source and no names. `docs/sky2/` collects the evidence
used to name them: Burnout Revenge's symbol table and link map, and a diff
against NBA Ballers Phenom. Its proposed names are hints; the README there
says how far each source can be trusted. `tools/port_rw_names.py` transfers
names from those symbol tables, `tools/rw_reference.py` reads a linked
reference ELF, and `tools/rw_dwarf.py` recovers sky2 structure layouts from
a DWARF build.

## What is left

Functions whose retail bytes differ from the verbatim compile are worked by
hand, with the same loop as any other function (see
[Matching a Function](Matching-a-Function)). The source is only a starting
point here: retail's chunk headers show RenderWare build 55 rather than the
source's 101, and the PS2 driver changes some functions.
