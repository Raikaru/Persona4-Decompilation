# Large battle controllers: UID width and hit-record storage

Baseline: `28bf2efd677ec0436eef6c864603e416f1f26943`.
Owner: `src/promoted/code1_001a.c`.
Scope: guarded `001a7720` (17,536 retail bytes), then `001a59a0`
(7,536 retail bytes). Both whole-function production fallbacks remain.

This is a semantic reconstruction checkpoint, **not a recovered match**.
No provider, shared header, compiler flag, assembly fallback, or other owner
was modified. The preceding animation-contract checkpoint supplies the
provider ABI and signed motion evidence used here.

## Largest-first UID audit

The validated retail windows contain the following complete non-stack
access census. The corresponding source expression counts agree exactly:

| Controller | Packet UID loads at +0x58 | Action UID loads at +0 | UID stores |
| --- | ---: | ---: | ---: |
| 001a7720 | 108 | 12 | 272 |
| 001a59a0 | 9 | 1 | 81 |

Every packet UID load is `ld`. Every store at packet +8, +0x18, +0x28 and
+0x60 is `sd`; there are no `lw`/`sw` instances at these audited slots.
The 7720 store counts are 132/3/4/133 respectively. The 59a0 counts are
44 at +8 and 37 at +0x60. The proof retains every retail address and word.
Counts are not represented as an instruction-order mapping: retail reorders
a few stores around individual packet creations.

In 7720, 106 previously narrow UID assignment statements are repaired:
102 packet stores and four packet-UID-to-local assignments. The four locals
`var_17_3`, `sp468`, `sp480`, and `sp190` now preserve `s64` values. Their
retail uses include `ld`/`sd` at stack +0x468/+0x480 and a UID-preserving
`sq`/`lq` spill at +0x190. This is not a general widening pass: 7720's
unrelated `sp2C0` is a boolean and remains `s32`; integer resource IDs,
unit addresses and other ordinary fields are unchanged.

The one UID argument to `001d65d0` at `001a8358..001a8360` is a doubleword
load into a3. The existing file-scope declaration and unchanged provider
already specify `s64 arg3`, stored at work+0x10. Removing the obsolete local
empty prototype makes all seven calls use that canonical signature, including
correctly typed zero UIDs. Their unit arguments use the declared `s32` address
view. The provider is not retyped or edited.

In 59a0, the action owner and two packet dependency loads no longer truncate
through `(s64)(s32)`. Their decisive retail loads are `001a59dc`, `001a5e5c`
and `001a685c`. The loop dependency `sp2C0` is widened to `s64`, matching
`sd` at `001a6860` and the later `ld` uses.

## Hit record selection

The 59a0 draft had two independent scaled-pointer errors:

- `temp_18 + (sp1D0 << 5)` scaled an `s64 *`, selecting a 0x100-byte stride
- `temp_18 + (sp1D0 << 5) + 0xF0` also scaled the base offset, selecting
  action+0x780 instead of action+0xF0 for the result-provider call

Retail `001a66f8..001a6700` adds index times 0x20 bytes.
`001a6f9c..001a6fc0` adds 0xF0 bytes and passes that exact record to
`001f36e0`. A function-local typed hit view now selects the real 0x20-byte
record once and preserves that identity through both result calls. Motion,
flags, added-status and HP-delta reads use established fields. The layout
agrees with the audited producer and `tests/battle_approach_action_fixture.h`.
It does not introduce a shared action layout or invent a hit-count clamp.

The larger 7720 controller already scales its main hit loop in bytes.
Its `001aa190..001aa1ac` sequence and extracted expressions are tested as
an unchanged control; no unnecessary global pointer rewrite was made.

## Executed contracts

The seven-test storage suite uses actual extracted declarations, assignments,
call expressions and the unchanged UID payload factory. Native32 execution
uses real i386 pointers, UB/bounds traps, and an explicit QEMU runner at both
O0 and O2:

- 3,710 UID cases per optimization cover all 353 UID store statements,
  17 UID-to-local assignments, and the saved dependency copy, with ten bit
  patterns including nontrivial upper halves, equal low/different high halves,
  unsigned low-word boundaries and all-one bits. Entire destination/source
  buffers are checked so partial stores and adjacent-slot corruption fail
- 6,144 hit cases per optimization cover all 24 real slots and all signed-byte
  motion representations, record pointer identity, both extracted 59a0 result
  calls, unchanged 7720 selection, and unchanged complete action/record guards
- All seven 7720 UID-payload call expressions invoke the actual unchanged
  `001d65d0` factory: 70 cases per optimization validate resource, unit,
  delay, full UID, flags, callback slots, returned identity and untouched work
- Ten runtime negative controls reject narrow stores, narrow loads, narrow
  locals, wrong dependency slots, bad hit strides/base, lost signed motion,
  and payload/argument truncation. An incompatible narrow UID formal is
  rejected at compilation

Fixture-only `noinline` on hundreds of independent site wrappers bounds O2
optimizer cost. It does not alter any production statement or declaration.
An initial fixture without that containment exceeded the runtime helper's
60-second compiler timeout; those incomplete runs are not counted as passes.
The final focused storage suite and existing animation, motion-override and
signed-opening suites pass together: 22 tests, zero skips. The in-repository
reproduction runner repeats all 22 successfully; the additional 14-test
approach/alias suite also passes. No complete controller/gameplay run is
claimed, and provider boundary recording is distinguished from executing the
unchanged UID payload provider itself.

## Whole-owner verification

The audit compiles baseline/final complete owner copies in production, with
each guard enabled separately, and with both enabled together. All eight
configurations compile. Production objects are byte-identical. All 70
non-target functions are preserved in each single-guard object and all 69
in the both-guard object, including canonicalized relocations.

| Guarded target | Baseline / final object bytes | Final retail window | Baseline / final differing bytes | Baseline / final frame |
| --- | ---: | ---: | ---: | ---: |
| 001a7720 | 17,540 / 17,392 | 17,536 | 12,829 / 12,810 | 0x6e0 / 0x680 |
| 001a59a0 | 7,640 / 7,600 | 7,536 | 5,542 / 5,610 | 0x410 / 0x400 |

These are normalized differing **bytes**, not instructions or accepted match
scores. Single/both-guard measurements agree. No source shape was selected to
reach a size band. The production verifier remains **69 MATCH / 2 ASM**.
Lint reports **zero errors**, with the same 24 existing warnings (8 H003,
16 H011). Fresh aggregate retail-hash gates and publication remain integration
work; production-object identity is not substituted for those gates.

## Remaining bounded work

The controllers remain guarded because unrelated semantic defects are still
present. The next useful scope is real provider-sized stack objects and the
59a0 signed timing clamp, as documented in the preceding checkpoint. There
are also pointer-as-value conditions: 59a0's later `sp100` mask tests an
address rather than loading the added-status word (retail `001a731c..001a7328`);
7720 compares its motion-byte address against motion values in later
conditions. This patch preserves those existing conditions rather than
claiming the hit-selection tests validate the entire unfinished control flow.
Oversized signed shifts and obsolete provider declarations remain elsewhere.

## Reproduction and retained proof

With licensed tools and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_storage_20261003/audit.py build/large-battle-storage/replay
python docs/probe_archive/Large_Battle_storage_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c --json build/large-battle-storage/verify.json
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit `--runner` on a host that executes i386 binaries directly. Runtime skips
are not counted as passes. [Retained verification](Large_Battle_storage_20261003/verification.json)
contains source/test fingerprints, guarded scores, preservation counts and
the retail census. The audit emits verbose per-function proof and compiler
logs to ignored output; proprietary inputs and compiled objects stay untracked.
