# Shuffle result and list availability recovery

The publication checkpoint based on `b647343` replaces three assembly fallbacks
with configured-compiler C implementations:

| Function | Owner | Executable / retail window | Zero alignment tail |
| --- | --- | ---: | ---: |
| `00380ea0` | `src/promoted/btlShuffleResult.c` | 2104 / 2112 bytes | 8 bytes |
| `002e4ac0` | `src/Yajima/y_list.c` | 1340 / 1344 bytes | 4 bytes |
| `002e5000` | `src/Yajima/y_list.c` | 612 / 624 bytes | 12 bytes |

The shuffle dialog uses the actual task, work-pointer, cursor and selection
interfaces. The list recovery preserves the pair/triple availability rules and
the real signed-halfword indices and three-argument helpers. The scoped
optimization settings are supported by the measured owner objects.

`iGpffffb3d4` now refers to the shared storage already supplied by `cmmMisc.c`.
Removing the duplicate private four-byte `.sbss` allocation allows `y_list.c`
to link from its compiled source. Its 37 function windows become physically
linked: 34 recovered C functions and three retained assembly fallbacks.

Both installed owners were freshly compiled and every function and allocated
data section independently resolved against retail. All 47 windows are exact;
the 44 other functions retain their raw and resolved bytes. The proof resolves
730 code relocations and 322 data relocations. Newly C-owned switch tables are
checked at `00752b90` and `00748aa0 + 0x30 * n` for `n = 0..9`, including every
branch destination. Other data is preserved apart from the removed duplicate.

The complete 13,102-function verifier reports 9,510 MATCH and 3,592 ASM. Its only
status changes are these three ASM-to-MATCH transitions. First-party progress
is 6,690 / 6,861 matched, with 171 assembly fallbacks remaining. Input hashes
agree throughout verification, integration and the final publication seal.

The full build links 595 C objects and 54 Sony SDK objects. All three new
functions are present under their actual source owners, and no previous
physical link membership is lost. The loadable image and complete retail ELF
are byte-exact:

```
loadable image: 3d1d3d2b9d6ccb60836db239ab49674223025a78
SLUS_217.82:    4eeec0360cf2715535d9f7e52eb69d786fb0158c
```

The Linux CI snapshot passes all six workflow checks, including 831 unit tests
with 22 expected skips. Scoped lint has zero errors and 34 existing advisories.
The progress endpoints were regenerated from the completed verifier and link
reports and validated separately after generation.

Local evidence is retained under `build/publication-verification/shuffle-list-v1`,
`build/batches/shuffle-list-v1`, `build/linux-ci/shuffle-list-v1` and the matching
`build/publication-gates/shuffle-list-*` directories. The installed source
SHA-256 values are:

```
btlShuffleResult.c a13c739bd16d5171537fba38afce9d733f7c29a9c5e3022990225360b3c12295
y_list.c          7b89fb249852a86cdbb8c9cf8069c6ac452f31b9d57ac2caaf71e2cc366fbf2e
```
