# Guarded Title controller: matrix storage and call ABI

Base: `9bb8b6ad0fafafca04007d67acadff673449bdfa`, the independently reviewed
entry checkpoint. This is a bounded source repair of `func_001265a0`.
**The NON_MATCHING guard and production fallback remain. No new exact-C credit,
full Title execution, matrix arithmetic, or renderer correctness is claimed.**

## Source repair

- Reuse the existing complete `BtlShuffleVec3` and `BtlShuffleMatrix` layouts.
  The latter has the canonical `RwMatrixTag` fields: right/flags, up/pad1,
  at/pad2, pos/pad3. It is exactly 64 bytes. The local explicitly retains the
  real PS2 matrix's 16-byte alignment, as specified by the existing SDK header
- Replace both split axis objects with complete 12-byte vector assignments.
  Retail globals are `(0, 1, 0)` at `005E5628` and `(1, 0, 0)` at `005E5638`
- Replace the three separate translation scalars with one real vector,
  explicitly `(0, -90, 0)`. `-90.0f` has the authenticated `C2B40000` bits
- Remove the conflicting old-style declarations. Reuse the owner’s existing
  canonical rotate `(matrix, axis, f32 angle, s32 mode)`, translate, and void
  model-matrix-copy declarations. The four modes remain `0, 2, 1, 0`
- No source-level matrix initialization is added

The wrong table byte reads/indexing, speed-call ABI, ACC expressions, every
other Title call, all provider bodies, and the global dispatcher are unchanged.
The source audit reconstructs the entire owner from the frozen base using only
these recorded substitutions. Existing type and provider files are hash-checked
as source-identical.

## Retail/provider boundary

The retail ELF is SHA-1 authenticated before inspecting it. Exact word checks
and provider-slice SHA-256 receipts establish:

- Entry copies both axes with one 8-byte load/store and one 4-byte load/store
- The two rotate calls receive their angle in `f12`, matrix in `a0`, axis in
  `a1`, and mode in `a2`
- `RwMatrixRotate` reads all three axis floats, normalizes the axis, and passes
  the transformed angle through trigonometry to `003E0680`
- The replace helper writes all twelve numeric fields and writes flags `3`
  unconditionally before its eight-iteration, 8-byte-per-iteration copy
- That initial replace path does not read old destination flags. The mode-2
  multiply reads four 16-byte rows from each matrix and explicitly ANDs flags
- Translate mode 1 reads all twelve numeric matrix fields plus the three
  translation floats, writes the three position floats, and clears identity
  in flags. It does not execute translate mode 0's old-flags OR
- `0047A1C0` forwards the matrix pointer and mode to `003E0E20`; mode 0 copies
  exactly 64 bytes, including the three nonnumeric padding words

**Remaining provider limitation:** the rotate helper's local words at offsets
`0x1C`, `0x2C`, and `0x3C` are not initialized before being copied. Subsequent
full-row VU loads and whole-matrix copies physically transport those words.
The recorder fixtures supply explicit tagged output bytes, including padding;
this is a storage/ABI boundary test, not a passing full-provider execution.
No padding value is guessed, zeroed, or installed in production source.
The separate model-draw provider's old-flags OR remains unchanged as well.

## Verification

- Production raw object is byte-identical to the entry baseline, SHA-256
  `59e652c8faa507dfb2feae59814a9668abfdbb377ba7eb62c3167eac9a7cc8c5`
- All 81 guarded siblings and their relocations are exact; all 420 non-target
  allocated data bytes, section properties and references are preserved
- Outside the two repaired boundaries, all 4,172 instructions are exact under
  the explicitly proven offset/stack-home map. No opcode or register masks
  are used. All 291 branch destinations and sixteen switch destinations are
  checked, including branches spanning the changed call block
- Target reference changes are exactly two GP axis references becoming complete
  HI/LO vector transports, and removal of two default-promotion `fptodp` calls.
  Every other event and addend is preserved
- Native i386 O0/O2 tests extract live declarations, actual existing layouts,
  vector copies, and the complete four-call block. Each optimization runs
  4,096 cases with distinct axes, angles and model identities. Actual pointed
  storage has canaries; all three providers are typed recorders. Thirty
  independent O0/O2 negative-control runs reject, including a 60-byte matrix
  overwrite, incomplete vector, old rotate order, wrong pointers and modes
- Actual retail and emitted axis-copy/call instructions execute in 2,048 cases
  with caller-saved registers clobbered at every boundary; twelve controls fail
- Two real retail 64-byte replacement-copy loops execute in 512 additional
  cases with explicit complete input bytes; six controls fail
- Whole-target stack census proves the matrix, axes and translation stay
  disjoint from all 52 colors, fifteen palette objects, fade UVs, saved state,
  argument area and the adjacent 16-byte payload
- All twelve earlier Title native modules rerun: 33 prior tests plus three
  matrix tests, **36 tests with no skips**. All eight previous bounded machine
  scopes and the entry machine contract rerun on the final guarded object
- Thirteen relevant owners: **510 MATCH / 63 ASM**. Title remains
  **81 MATCH / 1 ASM**. Lint: **0 errors / 32 existing advisories**

Final guarded size is 16,840 / 17,616 bytes, with 3,980 position-based masked
word differences. Before this checkpoint: 16,820 bytes / 3,985 differences.
The frame increases from `0x4B0` to `0x500` because the previously undersized
matrix and vectors now occupy real storage. This metric is not a complete
semantic or matching verdict.

Final source SHA-256:
`d66ac8bdfa05fc0e582b916dd8a550cd34ec030c8e20a4f2c8c4146ee6cd8360`

No full linked-image build, full repository test suite, renderer/gameplay run,
CI, push, upload or publication was performed. There is no new linkage claim.

## Replay

From the repository root, with configured licensed MWCC/retail inputs, Clang,
GNU ld and an existing i386 runner:

```sh
bash docs/probe_archive/Title_matrix_contract_001265a0_20261003/replay.sh
```

`P4_NATIVE32_RUNNER` defaults to `qemu-i386`. Full captures and intermediate
logs remain untracked under `proof/`. The archive contains only source scripts,
compact receipts and native test output. Manifest keys are repository-relative.
