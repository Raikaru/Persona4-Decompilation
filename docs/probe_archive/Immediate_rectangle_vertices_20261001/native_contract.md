# Immediate rectangle native contract proof

Date: 2026-10-01. Base: `58553aa1b6ffd6d42c58f623d1d97677e00b1be3`.
The source owner stayed frozen during this native proof; this verification
changed only the tests and these receipt files. No source edit, commit, push, retail
matching claim, or full backend type-family closure is part of this native proof.

## Reproduce

From `/workspace/shared/p4-probe-immediate-rectangle-vertices`:

```sh
source /workspace/shared/p4-toolchain/env.sh
python /workspace/shared/run_p4_qemu32_tests.py /workspace/shared/p4-probe-immediate-rectangle-vertices test_immediate_rectangle_contract
```

Final invocation additionally redirected stdout/stderr to `native_contract.log`
in this directory. The toolchain was Debian Clang 19.1.7 and QEMU i386 10.0.11.
The runner uses the existing freestanding i386 runtime with real 32-bit pointers,
SSE float arithmetic, `-ffp-contract=off`, and
`-fsanitize=undefined,bounds -fsanitize-trap=all`.

Files:

- `tests/test_immediate_rectangle_contract.py`: actual-body extraction, native
  execution, compiler layout assertions, and independent controls
- `tests/immediate_rectangle_fixture.c.in`: typed objects, controlled geometry
  boundary, ordered callback oracle, and separate actual-provider replay
- `native_contract.log`: final five-test output
- `native_contract.json`: counts, commands, source hashes, and qualifications

## Positive coverage

All five unittest methods pass. The native positive replays run at `-O0` and
`-O2` first with the normal runtime's `-fno-strict-aliasing`, then again with
explicit `-fstrict-aliasing`. The strict compiler retains the same target ABI,
float settings, and undefined/bounds sanitizer traps.

Each of these four positive executions passes:

- **2,304 immediate-helper cases:** four finite `Code45Float4` rectangle objects,
  four distinct four-byte colors, three signed/fractional depths, six full-width
  save-state values (`0`, `1`, `-1`, `7`, `INT_MIN`, `INT_MAX`), and eight input
  mutation modes
- **6,075 separate real-geometry cases:** five signed x values, five signed y
  values, three widths, three heights, three depths, three colors, and three
  camera near-plane values. The selected coordinates and spans keep every signed
  addition defined

The helper's function body is extracted unchanged from
`src/promoted/code1_0045.c`. Its actual `Code45Float4` and `Code45RenderState`
declarations are also extracted. It is called with a genuinely declared
`Code45Float4` object, and the provider boundary byte-copies the snapshot into
real `s32[4]` and `u32[4]` objects. It never dereferences the helper's snapshot
through an incompatible integer lvalue.

The fixture checks:

1. The library-clear boundary receives a size of 256 and value zero. It performs
   the ordinary byte clear, checks every byte, and the subsequent geometry
   boundary independently checks every one of the 64 float lanes is zero. A
   missing or partial clear fails before any possibly uninitialized lane read
2. The geometry boundary writes all 64 float elements. The draw oracle checks all
   16 lanes of each of four vertices, including element 63, the exact primitive
   kind/count `(4, 4)`, the same buffer pointer, and 16-byte alignment at both
   geometry and draw boundaries
3. For nonzero full-width save-state values, the six state gets and matching
   initial sets interleave in row order, followed by `(1, 0)`, the two Sky state
   calls, clear, geometry, draw, and all six original saved values restored in
   order. Each saved-state slot receives a distinct initialized value. For zero,
   no get, set, Sky, or restore callback occurs
4. Mutations at the first get, third initial set, first Sky callback, geometry
   entry, draw entry, first restore, or clear boundary change the original caller
   rectangle and color. The rectangle delivered to geometry remains the entry
   snapshot. Color remains live through the geometry call. Changes during draw
   or restore leave the already written vertex data intact. Mode zero performs
   no mutation; state-only mutation sites are absent on the no-save path
5. No allocation, queue append, or free occurs; explicit hooks make each such
   unexpected action fail normally

The separate provider replay compiles the real `func_0045ce40` body with only its
function symbol renamed to `actual_rectangle_geometry`, allowing it to coexist
with the controlled boundary. It receives genuine `s32[4]`, `u8[4]`, and
`f32[64]` objects, plus a camera stub with a declared `f32` near-plane member at
byte offset 0x80. A numerical oracle checks its 32 populated vertex lanes and
that the other 32 pre-zeroed lanes remain unchanged. This replay does not call
the actual provider through the immediate helper's remaining cast.

## Compiler layout proof

The local work declaration is extracted from the actual helper and compiled as
a separately named type. C `_Static_assert`/compiler alignment assertions prove:

- Output member extent: 256 bytes
- Output member and whole work alignment: 16 bytes
- Saved state offset: 0
- Output offset: 32
- Snapshot offset: 288
- Whole work extent: 304 bytes

The positive declaration compiles at both optimization levels. A compile-only
scalar-plus-padding control replaces the output array with an aligned scalar
and 252 bytes of following padding. It deliberately retains the same alignment,
offsets, and overall extent, isolating the distinction between a 256-byte array
member and an adjacent byte region. At both optimization levels, the compiler
rejects its four-byte output member with the specific assertion
`immediate output member must contain 64 floats`. Neither declaration-only
layout test executes a helper. No unsafe scalar-plus-padding helper is run.

## Independent controls

All **21** independent helper mutations run at both optimization levels:
**42 executions**. Every one must exit through `CHECK` with status **1**, a normal
line/scenario diagnostic on stdout, and empty stderr. Crashes, sanitizer traps,
compile failures, and any other exit status fail the test.

- Partial clear, nonzero clear, missing clear
- Wrong restored slot, state-set-before-get ordering, narrowed save predicate,
  wrong state value, wrong Sky value, entirely missing save path
- Wrong draw count, primitive kind, buffer pointer, or final output lane
- Wrong color, wrong depth, live rectangle instead of snapshot, late rectangle
  snapshot, early color snapshot
- Unexpected free, queue append, or allocation

Controls do not deliberately create out-of-bounds accesses or read uninitialized
saved slots. For example, the wrong restore uses initialized slot zero, partial
clear is rejected before a tail read, and wrong draw-buffer identity is rejected
before any vertex read. The early-color and late-rectangle controls first run a
case whose first state getter mutates both original inputs.

Total: four full positive runtime executions plus 42 controlled-failure runtime
executions, and four separate compile-only layout attempts (two accepted,
two rejected for the expected member-size assertion).

## Limits

This proof establishes the declared local output extent/alignment and the tested
helper orchestration, snapshot timing, live-color timing, state order, and draw
extent. The library clear and platform callbacks are fixture boundaries; it is
not a retail renderer execution.

The authoritative helper still receives `f32 *`, snapshots `Code45Float4`, and
passes `(s32 *)&work.pos` to its real geometry provider. The controlled boundary
makes this fixture lawful; the separate actual-provider replay makes its own
integer-input scope lawful. Neither proves that all authoritative callers share
one input object type or that the actual helper/provider input type family is
closed. Likewise, the aligned `f32[64]` work array is not proof of a unified C
object type with every backend renderer vertex overlay. The SDK quadword vertex
alignment evidence and full-owner matching/ref checks belong to the owner
receipt in this directory.
