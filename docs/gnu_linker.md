# GNU linker backend

`tools/build.py` links the matching image with either GNU ld (`gnu`) or
Metrowerks mwldps2 (`mwld`). The committed `tools/build_config.json` selects
`gnu`, so `make build` and a bare `python tools/build.py` use GNU ld. MWLD
cannot place the current tree's native literal pools at their retail
addresses, so an `mwld` link may fail the whole-image check.

The choice only affects linking. Compilers, per-unit compiler versions and
flags are the same for both backends.

## Choosing the backend

From highest to lowest precedence:

1. `--linker-backend gnu|mwld` on the command line;
2. the `P4_LINKER_BACKEND` environment variable;
3. `"linker_backend"` in `tools/build_config.local.json`;
4. `"linker_backend"` in `tools/build_config.json` (committed: `gnu`).

If no config file sets the key, `build.py` falls back to `mwld`. Any value
other than `gnu` or `mwld` stops the build.

```sh
python tools/build.py --linker-backend gnu --progress-report build/linked.json
```

## Finding `ld`

The GNU backend looks for `mipsel-linux-gnu-ld` the same way the build looks
for the GNU assembler (`tools/asm.py`). `P4_LD` replaces the discovered
command. On Windows the linker can run under WSL:

```powershell
$env:P4_LD = 'wsl -d Debian -- mipsel-linux-gnu-ld'
python tools/build.py --linker-backend gnu
```

A WSL command in `P4_LD` must have the form `wsl -d DISTRO -- LINKER`.
`P4_WSL_DISTRO` (default `Debian`) picks the distribution when `ld` is
discovered automatically. The backend maps the shared absolute input
directory once and uses identical full paths in the linker script and the
response file. Object lists stay in the response file, so paths with spaces
work.

## Placing native objects

GNU ld can interleave sections from one input object with functions owned by
another. The backend relies on this for first-party objects whose retail
functions are not contiguous. It never changes instruction bytes, data bytes,
symbol definitions or relocation records.

**Gapped owners.** An owner with first-party functions stays one object even
when other code sits between its functions. Its text sections are renamed so
each function lands at its retail address. Vendor functions in a mixed owner
keep their per-function origin classification. Owners that contain only
third-party code keep the older restriction and are not linked across gaps.

**Literal pools.** Local `R_MIPS_LITERAL` references still point to the
compiler's original pool. If a pool cannot stay in its emitted section order,
it gets a unique section name and its independently recovered retail address.
Alignment, bytes, local symbols and relocation indices are unchanged. If the
placement evidence is missing or the bytes differ, the owner is rejected.

**Jump tables.** A first-party owner can also place separately emitted local
jump tables whose `.rodata` sections have gaps or appear in a different
order in retail. Each four-byte word must carry exactly one native
`R_MIPS_32` relocation. The backend resolves each word's symbol and original
addend, and the whole table must equal the retail bytes at its recovered,
aligned address. Missing, conflicting or overlapping placements, ambiguous
targets and unsupported relocation types reject the owner. A validated table
gets a unique section name; its payload, symbols and relocations are
unchanged, and foreign data in the gaps stays where it is. This does not
admit arbitrary unmatched `.rodata`, and MWLD's placement rules are
unchanged.

**Shared literals.** Two native owners may refer to the same retail
constant. Such a shared address is accepted only for identical, aligned
four- or eight-byte literal atoms with local symbols and bounded GP-relative
loads. The backend gives private copies of those input sections GNU merge
metadata, so ld keeps each original local definition at the shared address.
The original objects are not modified. Writable, address-exposed or
conflicting overlaps are rejected.

## Checks during the link

- The linker script leaves out fallback names that an input object already
  defines, including the entry symbol and allocated data. Remaining fallback
  symbols use `PROVIDE`, so a real source definition stays tied to its
  section.
- Missing, duplicate, overlapping or unplaced allocated input sections fail
  the link.
- After linking, the backend checks the load span, entry point, GP value and
  that every placed function is defined in a real section.
- The whole-image comparison and the complete retail-ELF hash check must still
  pass before a progress report is written.

## Expected warnings and stripped sections

- MWCC's non-loadable `.mwcats` metadata is kept outside the load image.
- Retail code and writable data share one segment, so ld may warn about an
  RWX segment. Linker diagnostics are not hidden. The backend does not
  suppress ABI warnings, edit input ABI flags or substitute relocation types.
- The link uses `--strip-debug`. ee-gcc writes ECOFF `.mdebug` sections with
  invalid external-string offsets, and those crash BFD during the final link.
  `.symtab` and `.mwcats` are not stripped, so linked function definitions
  and both retail hashes are still checked.

## Toolchain in CI

The `Dockerfile` installs Debian's `binutils-mipsel-linux-gnu` for `ld` and
`objcopy`, and the decompals v0.7 assembler for PS2 R5900 instructions.
Decompals' own `objcopy` can write an invalid `.symtab` `sh_info` when an
assembly-local label follows global labels. Debian's `objcopy` keeps the
symbol order correct.

## Tests

```sh
python -m unittest discover -s tests -p test_gnu_link.py
python -m unittest discover -s tests -p test_build.py
python -m unittest discover -s tests -p test_elf_text_runs.py
```

The tests cover backend selection, first-party gap eligibility, unchanged
local literal references, foreign gaps, full-path response files, allocation
failures, extra load segments and absolute-symbol shadowing.
`test_elf_text_runs.py` also covers how assembly is carved around C ranges:
overlapping and nested ranges, duplicate starts, zero-length intervals and
exact boundaries.

These tests use synthetic ELF fixtures, which do not show that ld handles
real compiler output. To prove that, link the compiled objects and pass both
retail hashes (`make build`).
