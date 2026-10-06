# After32 cleanup and material caller audit

This package stages the reviewed geometry recovery and its only first-party
caller contract. It does not install a source change or claim an exact C match.

`after-guarded.c` replaces the old score commentary and fixes indentation in
`effAfterBuildStrip`, the shared attribute-index scope, the right color/UV loops,
and both center-UV loops. Its C tokens are unchanged from `after-reviewed.c`.
All local scopes, declaration order and optimization pragmas are preserved.

`afpack-caller.c` declares `func_004b8350(u8 *, struct RpMaterial *)` and reads the
second argument through a pointer to that opaque material type. The declaration
and the one load are the only changes in that owner. No shared header is changed.
The runtime geometry and material APIs otherwise keep their existing declarations.

## Caller and layout evidence

The sole authoritative C caller is `func_004b6900` in
`src/Graphics/Effect/eff_afpack.c`. Retail at `004b6a4c` calls `func_003c4140` and
stores the returned material pointer in the second word of the eight-byte render
object record at `004b6a5c`. It subsequently sets that material's texture and RGBA.
At `004b6ae4`, the same record's second word is loaded into `$a1`; `004b6ae8` calls
`func_004b8350`. `$a0` is the corresponding 0x3c-byte effect work entry. The local
variable named `material` in an earlier nested scope instead holds the source
effect descriptor; that descriptor is not the argument passed to the builder.

Primary sources are `asm/nonmatchings/eff_afpack/func_004b6900.s`, the creation
body at `src/promoted/code1_003c_cw119.c:203`, and the SDK definitions/prototypes
in `include/rw/sky2/rpworld.h`. `RpMaterial` has its texture pointer at +0 and
RGBA at +4. The builder forwards its second parameter unchanged as the material
argument of `func_003c2150` (`RpGeometryTriangleSetMaterial`). `RpTriangle`
contains three u16 vertex indices and one u16 material index, matching the
eight-byte retail stride. Texture coordinates are two f32 values; the bounding
sphere is a three-component vector followed by its radius.

## Validation

`proof/owner-proof.json` binds the exact candidate source, compiler, flags,
included headers, verification tools, symbol maps and function windows. It
records all function sizes and code hashes, canonical relocations, fully
resolved instruction words, and allocated data placements. Resolution uses
stable sibling references to place local data rather than borrowing target
instruction positions from the nonmatching function.

Eight complete owners were compiled: default baseline/proposal and selectively
forced baseline/proposal for each source. For After, the forced comparison uses
the previously reviewed proposal as its baseline. The result is:

| Owner or comparison | Result |
| --- | --- |
| `eff_after.c` default | 9 C / 2 ASM; all 11 functions fully resolved and unchanged |
| `eff_afpack.c` default | 8 C / 1 ASM; all 9 functions fully resolved and unchanged |
| After32 forced target | 2720/2720 bytes, 32 fully resolved differing words |
| After formatting | Every function's code, size and relocations unchanged |
| Afpack typed caller | Default and selectively forced code/relocations unchanged |
| Both owners' allocated data | All references resolved; contents equal retail |
| New exact C matches | 0 |

The unrelated afpack loader guard remains at 535 resolved differing words in
both selectively forced builds. This package neither improves nor installs it.

Proposal source SHA-256 values:

```
after-guarded.c 45c0c306ad74e7fb6196225b3ada39999849f23625f5e2928b3d805f27f170f0
afpack-caller.c 48c64b226a673af50b33cd4b7b75ab92236cef4e5a9da7309ea92f61a4fdc6de
```

## Replay and review

Run with the repository's configured compiler and retail ELF:

```
python docs/probe_archive/After_geometry_004b8350_20261006/replay.py --output build/finish-20261006/effects-worker2/after32-archive-replay
```

The output directory must be new and should be placed under build for a new replay. The replay uses only this package and the
tracked repository tools; no other ignored probe folder is imported. Source
snapshots and `inputs.json` make the measured input explicit. Logical owner
paths preserve unit-specific compiler flags and quoted include context.
`changes.patch` is the combined proposed change; separate `eff_after.patch` and
`eff_afpack.patch` are also included. Installation and review belong to prime.

## Archive source binding

`source-rebinding.json` records the sole change after the eight native owner
compiles: the After source comment now points to this tracked archive. C tokens
are identical, so the native code and relocation proof is reused without another
compile. `proof/native-before-archive-comment.json` retains the exact original
native report. `proof/owner-proof.json` carries the same native measurements and
adds the explicit source binding; original compiled-source hashes are not relabeled.
`inputs.json` binds the source snapshots used by a future independent replay.
No object files or retail executable bytes are distributed in this package.
