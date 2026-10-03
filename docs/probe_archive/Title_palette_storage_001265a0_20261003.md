# Largest Title controller: complete palette storage and local selection

Baseline: `bed91675c50af703b974bd44ede3234eef532590`.
Only guarded `src/promoted/code1_0012.c::func_001265a0` changes. The
NON_MATCHING guard and assembly fallback remain. This is bounded source
recovery, with **no exact-C credit or full-controller claim**.

## Five snapshots and ten real copies

The retail controller takes five separate 24-byte snapshots from the six-word
palette at `005E5530`. Each snapshot supplies two independent 24-byte copies.
The old source split each snapshot into unrelated 16-byte and eight-byte
locals, reserved only four bytes per destination, advanced an `s128 *` source
by eight elements (128 bytes), and advanced a four-byte destination pointer
by eight elements (32 bytes). Its selected-word reads used an invented
external `sp` pointer instead of any of these locals.

The repair reuses the owner's established `TitlePalette` (`u32 words[6]`,
size 24) and `titlePaletteCopy` helper. It adds no helper, pragma, synthetic
alignment, padding, stack backing array, or ABI alteration. Each snapshot is
one complete struct assignment; the ten copies each move three pairs of
words through the helper's two-word increments. The five index locals now
hold the actual palette index, and both selections address the corresponding
local `words[index]` array. Obsolete copy cursors/counters/temporaries disappear.
The first through fifth names denote the existing source-order groups.

| Group | Retail snapshot | Retail copies | Rebuilt snapshot | Rebuilt copies |
|---|---:|---|---:|---|
| first | 130 | 450 / 430 | 320 | 500 / 4E0 |
| second | 110 | 1B0 / 190 | 300 | 3A0 / 380 |
| third | F0 | 410 / 3F0 | 2E0 | 4C0 / 4A0 |
| fourth | D0 | 3D0 / 3B0 | 2C0 | 480 / 460 |
| fifth | B0 | 170 / 150 | 2A0 | 360 / 340 |

Offsets are hexadecimal SP-relative compiler observations, not source layout
requirements. All fifteen rebuilt objects are distinct and frame-contained;
they are also disjoint from all 52 previously recovered color objects. The
only direct stack operations intersecting the palette objects are the five
complete snapshot stores, each a 16-byte SQ and an eight-byte SD. The actual
copy loops access exactly six words and end at source/destination +24.

The authenticated retail audit verifies all five snapshot instruction windows,
all ten pair-copy loops and their actual local selected-word loads. The six
packed colors are `FFFFFFFF`, `FFFF81FF`, `FFC705FF`, `FFFF64FF`, `FF0000FF`,
and `FFD518FF`. All nineteen 40-byte layout records have their palette index
at +28 in the range 0..5. This bounds the observed selections without adding
an invented clamp to source.

`D_005E5540` is the palette's tail alias at `D_005E5530 +16`. The old guarded
object had actually eliminated all five tail loads: those split scalar locals
were not read by the malformed source loops. The repaired object has five
LQ loads at `005E5530` and five LD loads at `005E5540`, spelled as relocations
against `D_005E5530` with addend 16. The replay checks the symbol-map alias,
retail addresses, instruction addends, store widths and local homes. It does
not mistake changed symbol spelling for changed data, or ignore relocation
fields as a substitute for checking their actual targets.

## Explicit packed-word proof boundary

The five existing `func_00124bb0` expressions still have an unresolved local
old-style return/argument contract, and two retain unrecovered ACC geometry.
This checkpoint changes only their base palette-selection subexpression.
All other argument expressions and declarations remain as before. Neither
these calls, their model-index conversion, interpolation, nor model rendering
is claimed correct. The native fixture stops at a typed recorder receiving
the selected highlight word and selected base word with alpha forced to FF.
It does **not** use an invented model-renderer prototype to excuse the source.

## Source-bound execution and controls

The i386 fixture extracts the actual palette type, size assertion, copy helper,
all fifteen live declarations, five contiguous snapshot/copy/selection blocks,
and the actual base-color selection subexpressions. Each actual declaration
is enclosed by independent test-only canaries; all objects exist together.
After each group, unrelated objects and every guard must remain intact.

At both O0 and O2 it passes **123,000 cases**: every group and index, the six
real packed colors, every byte value in every channel with distinct word tags,
and four independent mutation modes. Test-only observation boundaries can
change the global palette after the snapshot and the highlight destination
after its copy. The saved source and second copy must remain independent.
These inserted observer calls are fixture instrumentation, not retail calls
or a claim that the unchanged controller has extra opaque boundaries.

All **34 source controls** fail meaningfully: short copy, wrong source stride,
wrong destination stride, repeated second word, and per-group omitted copy,
wrong highlight index, wrong base index, absent snapshot, recopying from the
subsequently changed global, and aliased destination. Controls retain their
observer checks, so an omitted copy fails on actual stored values rather
than simply omitting an instrumentation event.

A separate interpreter executes the actual emitted pair-loop words and each
actual selected LW for all ten sites. It checks the exact read/write sequence,
all six output words, terminal pointers and counters, and rejects unwritten
reads and out-of-object writes. It passes **61,500 copy/index cases** and
rejects **30 instruction controls**, including the original 128-byte source
stride and 32-byte destination stride at each site. Snapshot instructions are
audited against authenticated retail and resolved addresses; this interpreter
does not execute the intervening model/ACC subgraphs.

## Whole-owner preservation and prior scopes

Fresh baseline/final owner builds in production and NON_MATCHING modes prove:

- The whole raw production object is byte-identical
- All 81 guarded siblings and all their references are identical
- All 420 non-target allocated data bytes and references are identical
- All sixteen switch destinations retain their alias groups and exact entry
  prefixes/references, except the explicitly checked shared-color home change
- Outside the five bounded snapshot-through-model-call subgraphs, 2,650 words
  are identical, 235 SP-relative/frame adjustments follow a fixed explicit
  per-home map, and all 191 branch destinations are checked against exact
  corresponding instructions
- Every other target reference, reference order and immediate addend remains
  unchanged, including the existing floating conversion helper references
  within the five model subgraphs

The full frame grows from `0x520` to `0x680` for genuine objects. No blanket
stack, instruction, branch or relocation masking is used by this preservation
proof. The whole-source audit reconstructs the entire diff from the baseline.

Against the final object, prior audits again verify all 26 clear/copy color
families, twelve byte-alpha aliases, thirty layer calls, six GP color words,
four fullscreen calls and 52 disjoint color objects. Both earlier alpha-alias
slices and the full fade tail/epilogue preserve their words and references,
with only the explicit new frame/object homes. All ten sprite conversion
slices and the bounded two-sine subgraph replay successfully: 50,740 actual
retail/emitted conversions, 1,134 subgraph invocations, and 23 rejected machine
controls. The actual fade replay passes another 1,368 retail/emitted invocations
and four rejected controls using the new UV home at SP+560.

All **26 current Title native tests pass with zero skips**, including the
unchanged provider/alpha/fade suites. The seven-owner verification reports
**253 MATCH / 46 ASM** across 299 functions; the affected owner remains
**81 MATCH / one ASM**. Lint has zero errors and the same 32 existing advisories.

The guarded target is **17,496 / 17,616 bytes with 3,986 masked differing
words**, versus baseline 17,468 bytes / 3,995 words. This remains a nonmatch;
a smaller masked count is not proof of whole-controller correctness. No full
linked-image build, graphics/gameplay run, CI, publication, or push is claimed.

## Reproduction

From repository root, with existing licensed compiler/retail inputs and an
existing i386 runner configured:

```
P4_NATIVE32_RUNNER=qemu-i386 bash docs/probe_archive/Title_palette_storage_001265a0_20261003/replay.sh
```

The replay regenerates authorized assembly, recompiles both complete owner
configurations, runs the retail/candidate/preservation audits, executes all
native and bounded-machine suites, verifies the seven affected provider
owners, lints the source, and measures the guarded residual. It then collects
compact source-only receipts beside the scripts. Licensed objects, retail
bytes, whole disassemblies and full local reports stay under `proof/` and are
not committed. Runtime skips are unverified and fail the replay.
