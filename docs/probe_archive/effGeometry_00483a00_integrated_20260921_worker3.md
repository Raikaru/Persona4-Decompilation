# Geometry constructor integration, September 21, 2026

`func_00483a00` is integrated as native C in `src/promoted/effGeometry.c`.
The earlier worker-5 candidate was authenticated before use. Its unsigned
count-product correction avoids signed multiplication overflow while retaining
the identical native object. The real aligned frame pointer, material pointer
array and complete sphere representation are preserved.

Fresh compilation of the integrated source proves 572 bytes in the 576-byte
retail window, all 17 relocation destinations and four zero alignment bytes.
All 17 owner functions pass official and unmasked comparison. The original
16 siblings and 28-byte table with seven entries are unchanged. All three
direct callers also pass unmasked comparison.

Prime approved the single game diagnostic definition correction to
`func_0044ea90(const void *file, s32 line)` in `src/Kernel/sdkChkmem.c`.
Its entire native object is unchanged, and all 13 functions pass official and
unmasked comparison. Original comment bytes are preserved.

Authoritative evidence is in `build/first-party-focus-20260921/effects/`:
`HANDOFF.md`, `integrated/FINAL.json`, the two integrated owner folders and
the artifact inventory. Use `integrated/diagnostic/changes.patch` for the
correct one-line UTF-8 patch; the old scratch patch containing mojibake was
retained only as historical evidence.

Final source hashes:

* `effGeometry.c`: `040dd286d1a93e8f901b7d77d815301ffd8a166be6d47d5aff228004d2878d47`
* `sdkChkmem.c`: `9d071c24413619cfbd3f9436b19127b8a24bfdc81843ae2574ccbeba25d064c4`

The model projection `0048a460` remains guarded and unmodified. Three actual
matrix/camera alignment probes each retained the existing 15-word residual in
176 bytes; all 52 siblings and hardware instructions were unchanged. These
bounded negative results are in `effects/model/alignment-results.json`.
