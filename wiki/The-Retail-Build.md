# The Retail Build

`SLUS_217.82` was not produced by one compiler at one setting. Everything
below was measured against the retail bytes (the details, with the probes that
established each fact, are in `docs/matching.md` under "The retail binary is a
MIXED-toolchain build").

| Region | Compiler | Flags | How the tree reproduces it |
| --- | --- | --- | --- |
| Atlus game code | MWCCPS2 3.0.1 build 210 (060308) | `-O2 -Iinclude` | the default in `tools/verify_config.json` |
| A few Atlus units | build 210 | `-O2,p` (optimise for speed) | `config/speed_units.txt` |
| RenderWare Graphics 3.7 (`0x0038f000`-`0x003ef000`, `src/renderware/`) | MWCCPS2 3.0.1 build 119 (040914) | `-O4,p -inline auto -DRWBUILDNUMBER=55`, RenderWare headers | `config/compiler_units.txt` names the version; `config/version_flags.txt` holds that version's flags (`-O4` replaces the default level, `,p` still per unit) |
| Five units | ee-gcc 2.96 | `-O2 -G0` | `config/gcc_units.txt`, compiled through `tools/eegcc_shim.py` |
| CRI, Sony SDK, C runtime | prebuilt | - | tracked as assembly (`src/cri`, `src/sce`, address ranges in `tools/verify.py`) |

How each of these was pinned:

- **build 210 for game code**: a whole-tree verify under every other MWCC
  build on hand (2.4, 3.0.1, 3.0.1 b74/b119/b151/b198, 3.0.3) loses 20-85% of
  the matches per unit; b210 keeps them all.
- **`-O2,p`**: `,p` inserts an alignment nop after a filled back-edge delay slot
  so the following branch target is 8-aligned. No pragma spelling reaches it,
  so it is carried per unit.
- **build 119 for RenderWare**: b210 and b198 never emit `movz`/`movn` at any
  option; b74/b119/b151 emit them from a plain ternary, byte-exact. b119 keeps
  488 of the block's 529 b210-tuned matches and adds the ones b210 cannot
  produce.
- **`-O4` for RenderWare**: at `-O2` b119 inverts a plain `while` into a
  bottom-tested loop; retail's loops are top-tested, and from `-O3` up the
  verbatim source reproduces them. A whole-file compile of the RenderWare
  sources fingerprints 360 byte-exact functions at `-O4,p`, 259 at `-O3,p`
  and 130 at `-O2,p`.
- **`-inline auto`**: retail carries small same-unit callees inline while also
  emitting the out-of-line copy (`_rwPluginRegistryWriteDataChunks` contains
  `_rwPluginRegistryGetSize`).
- **`RWBUILDNUMBER=55`**: every chunk header is written with build 55
  (`addiu $t0, 0x37`); the 3.7.0.2 tree defaults to 101.
- **ee-gcc 2.96**: those units save callee-saved registers with `sd`, which
  MWCC never emits (it uses `sq`); 2.95.3 and 3.2 differ from retail in other
  ways, 2.96 reproduces it exactly.

Per-unit configuration is deliberate: every translation unit is compiled by
exactly one compiler at one setting, the way the original build did it, and
`tools/verify.py::unit_compile_flags` / `unit_compiler` are the single place
that decides which.
