# Menu and shuffle batch: 6,546 first-party C matches

The installed batch adds two first-party functions to the preceding
**6,544 MATCH / 316 ASM** checkpoint:

| Function | Owner | Native / retail bytes | Code relocations | Zero tail |
| --- | --- | ---: | ---: | ---: |
| `func_0012aa70` | `src/promoted/code1_0012.c` | 3,056 / 3,056 | 105 | 0 |
| `func_00386c00` | `src/promoted/code1_0038.c` | 2,228 / 2,240 | 27 | 12 |

The menu callback also owns a verified 17-entry switch table. Its complete
object and provider/caller changes are documented in
`Menu_callback_0012aa70_20260923.md`.

The shuffle renderer retains its entry, steady and exit phases, halfword frame
updates, two circular primitives, corner sprites and sixteen animated particle
sprites. Outer/inner radii, corner displacement, angle scale and opacity are
separate values. The actual byte alpha argument is converted at the sprite
provider boundary. A private inlined radius helper preserves the scale-times-
radius operand order without emitting a separate function or adding work.

Both recoveries compile as active C under the configured b210 `-O2 -Iinclude`
profile. The reviewed source has one marker per target and no target assembly
fallback. Every relocation and nonzero executable byte is independently
checked; the shuffle suffix is twelve verified zero bytes. All unrelated
native function bodies and canonical relocations in the five affected owners
are unchanged. Existing allocated data is preserved.

The installed-source official reports and complete checkpoint are under
`build/finish-first-party-20260922/continue-18-menu-integration/`.
They record **6,546 MATCH / 314 ASM** over the unchanged 6,860-function
first-party scope. Source hashes, compiler hashes, flags and dependencies
bind the reused successful native outputs to the installed files.

The full-build result and source-link continuity check belong to the same
directory's `build/` and `publication-checked.json`. Recovery counts exclude
remaining assembly siblings, even when those siblings are present in a linked
source owner's object.
