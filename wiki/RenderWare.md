# RenderWare

The block `code1_0039.c` .. `code1_003e.c` (retail `0x0038f000`-`0x003ef000`,
about 900 functions) is RenderWare Graphics 3.7 - the core library
(`core/src/plcore`, `core/src`), the p2 pipeline and the world plugin - built
with MWCCPS2 3.0.1 build 119 at `-O4,p -inline auto`. See
[The Retail Build](The-Retail-Build) for how that was established.

The RenderWare 3.7.0.2 source is public (`sigmaco/rwsrc-v3.7.0.2`) and the
block is being recovered from it **verbatim**: the source file's text,
RenderWare names, macros (`RWFUNCTION`, `RWASSERT`, `RWRETURN`,
`RWSRCGLOBAL`, ...) and comments, compiled against the same headers.

## Layout

- `src/renderware/<dir>/<file>.c` mirrors the source tree: `plcore/`,
  `core/`, `p2/`, `world/`. One unit per source file, registered in
  `config/compiler_units.txt` (`cw3.0.1b119`) and `config/speed_units.txt`.
- `include/rw/` holds the vendored headers: `inc/` (public), `plcore/`,
  `core/`, `p2/`, `p2null/`, `world/`, `worldp2/`, `worldp2null/`,
  `drvcommon/`, `drvnull/` (the null driver stands in for the sky2 driver,
  which is not in the public tree), `ps2/` (the PlayStation 2 `ostypes.h`,
  `osintf.h`, `rtfsyst.h` this project wrote: `long long` RwInt64, 16-byte
  matrix/vector alignment, `RWGLOBALSIZE` so `RwEngineInstance` is the static
  `ourGlobals` array at `0x008872E0`), and `std/` (libc shims for the
  `<stdlib.h>`-style includes; the b119 units are compiled with `-nosyspath`).
- File-scope `static` data becomes `extern` at its retail address
  (`config/symbol_data_addrs.txt`), so the unit links. Functions not yet ported
  under their RenderWare name are aliased to the retail `func_` symbol with a
  `#define` placed before the includes, so the header prototype declares the
  right function.
- The old `src/promoted/code1_00XX.c` files keep the `INCLUDE_ASM` fallbacks
  (and a few b210-era matches) for whatever is not ported yet; the
  `code1_00XX_cw119.c` siblings hold the functions matched under b119 before
  the source was available. Both shrink as the port proceeds.

## Tools

- `build/rw_fid.py` compiles every RenderWare source file with the real flags
  and fingerprints each function against every retail window (relocation
  fields masked, equal length, order-consistent within a file). Output:
  `build/rw_fid.json`, `build/rw_map.txt`. It maps ~350 functions with no
  human involvement; the fingerprint is not proof, the verifier is.
- `build/rw_port.py <dir>/<file>.c [--install]` generates the unit: verbatim
  text, markers for every mapped function, statics to externs, then verifies,
  registers the statics from retail's immediates, aliases unported callees,
  arbitrates fingerprint ties by requiring every function in the file to agree
  on its statics' addresses, and strips the markers of anything that did not
  verify `MATCH`.
- `build/rw_hints.py` lists the `rwID`/memory-hint constants, gp slots and
  call targets per block function, for placing functions the fingerprint
  cannot.

## What is left after the automatic pass

Functions whose retail bytes differ from the verbatim compile: mostly
`RwEngine*` subsystem getters/setters that the PS2 driver overloads, a handful
of functions with `,p` alignment-nop shapes in the one plain `-O2` unit, and
the stream/texture functions whose bodies changed between 3.7.0.2 build 55
and build 101. Those are worked by hand from the source and the disassembly,
the same loop as any other function.
