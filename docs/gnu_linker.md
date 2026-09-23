# Selecting the matching-build linker

The committed `tools/build_config.json` selects `gnu`, so normal `make` and
`python tools/build.py` builds use GNU ld. This links the current native literal
pools exactly without a machine-local override. The backend may also be selected
explicitly:

```sh
python tools/build.py --linker-backend gnu --progress-report build/linked.json
```

MWLD remains available through `--linker-backend mwld`. Its literal-pool limitations
can prevent the current source tree from passing the complete-image check.
For a persistent machine-local selection, set `"linker_backend"` in
`tools/build_config.local.json`. `P4_LINKER_BACKEND` overrides configuration;
the command-line option overrides both. Valid values are `mwld` and `gnu`.
The compiler, compiler versions, per-unit settings and flags are unchanged.

The GNU backend discovers `mipsel-linux-gnu-ld` using the same tool discovery as
the GNU assembler. `P4_LD` overrides the linker command. On Windows, for example:

```powershell
$env:P4_LD = 'wsl -d Debian -- mipsel-linux-gnu-ld'
python tools/build.py --linker-backend gnu
```

`P4_WSL_DISTRO` selects the distribution during automatic discovery. An explicit
WSL command in `P4_LD` must include `--` before the linker executable. The backend
maps the common absolute input directory once and uses identical full paths in
the linker script and response file. Long object lists remain inside the response
file, including paths containing spaces.

## Native object placement

GNU ld can place separate sections from one input object around functions owned
by another object. Gapped owners containing first-party functions therefore remain whole. The existing
text-section renaming expresses each function's retail address without changing
instruction bytes, data bytes, symbol definitions or native relocations. Local
`R_MIPS_LITERAL` references still name the compiler's original local pool. The
per-function origin classification is preserved in mixed owners, including their
existing vendor functions. Entirely third-party gapped owners retain their previous
eligibility restriction. When these literal pools cannot use their emitted section
order, each pool receives a unique section name and its independently recovered
retail placement. The original alignment, bytes, local symbols and relocation
indices stay intact. Missing placement evidence or differing data rejects the owner.

The same first-party GNU path can place separately emitted local jump tables
when their `.rodata` sections have gaps or a different retail order. Every
four-byte word must have exactly one native `R_MIPS_32` relocation. Its symbol
and original addend are independently resolved, and the complete table must
equal the retail bytes at its recovered, aligned address. Missing, conflicting
or overlapping placements, ambiguous targets and unsupported relocations reject
the owner. Validated tables receive unique section names; their payloads,
symbols and relocation records remain unchanged. Foreign data in the gaps is
retained. This does not admit arbitrary unmatched `.rodata` or change MWLD's
placement rules.

Two native owners may refer to the same retail constant. A shared placement is
accepted only for identical, aligned, four- or eight-byte literal atoms with local
symbols and bounded GP-relative load references. The adapter gives private copies
of those input sections GNU merge metadata, letting the linker preserve every
original local definition at the shared address. Instructions, payload bytes and
relocation records remain unchanged, as do the original input objects. Writable,
address-exposed or conflicting overlaps are rejected.

The script omits fallback names already defined by input objects, including the
entry symbol and allocated data. Remaining fallback linker symbols use `PROVIDE`.
An actual source definition remains associated with its linked section. The backend rejects
missing, duplicate, overlapping or unplaced allocated input sections. It also
checks the linked load span, entry point, GP and every placed function's real
section-backed definition. The existing whole-image and complete-retail-ELF
verification remain required before a successful progress report is written.

Non-loadable MWCC `.mwcats` metadata is retained outside the load image. The image
combines retail code and writable data in one segment, so GNU ld may print its
RWX-segment warning. Linker diagnostics remain visible. No ABI-warning suppression,
input ABI-flag edits or relocation-type substitutions are used.

## Regression checks

```sh
python -m unittest discover -s tests -p test_gnu_link.py
python -m unittest discover -s tests -p test_build.py
python -m unittest discover -s tests -p test_elf_text_runs.py
```

These tests cover backend selection, first-party gap eligibility, unchanged local
literal references, foreign gaps, full-path response files, allocation failures,
extra load segments and absolute-symbol shadowing. A native integration proof must
also link completed compiler objects and pass both retail hashes; synthetic ELF
fixtures alone do not establish native linker compatibility.

The carving tests additionally compare partial assembly blocks across overlapping
and nested C ranges, duplicate starts, zero-length intervals and exact boundaries.
The indexed range-membership lookup preserves the original chunk names, labels,
bytes and placement indices while avoiding a scan of every C range for every
instruction.
