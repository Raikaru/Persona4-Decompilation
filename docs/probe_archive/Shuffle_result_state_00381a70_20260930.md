# Shuffle result state machine `func_00381a70` (2026-09-30)

## Result

`src/promoted/btlShuffleResult.c`, retail `0x00381a70`:

- Whole-owner **MATCH**, object **4396 B**, window **4400 B**, with four
  zero tail bytes and no differing instructions
- All **135** relocations resolve exactly: 120 calls, five HI16/LO16 pairs,
  and five GP-relative references
- The native 20-entry jump table at `0x00752bb0` resolves to all **80** retail
  bytes. The owner's complete `.rodata` placement is 148 B at `0x00752b90`
- All ten functions in the result owner now match
- Across the seven consumers of `btl_shuffle_draw_internal.h`, the other
  **384 functions retain identical raw function bytes**, status and size in
  both production and `NON_MATCHING` builds
- The official build selector admits Result, Draw and Calc, including their
  native owned data and complete function windows

The fresh guarded baseline emitted 4504 B: 791 differing words, 298 aligned
edits, normalized byte difference 2631, with the correct `0x140` frame.

## Source recovery

The result step has 20 phases, a three-way dialogue choice, and a one-case
card-kind switch. Keeping those nested switches reproduces the retail dispatch
and branch layout. Phase 2/3, 7/8 and 11/12 have deliberate same-call
continuations.

Small inline operations represent the repeated upright roll, primary and
secondary result messages, forced upright override, opening projection, and
persona-inventory decision. Their actual local lifetimes recover the three
64-byte text buffers and projected XYZ value. The projection provider
`func_0036a6b0` writes exactly three floats; a guessed four-float array and an
oversized text buffer were unnecessary.

`ShuffleResultState` describes the observed payload prefix at work + `0x18`.
A local two-pointer view captures the context and payload bases once. Both
members are used, with no dummy field, padding, volatile access, register pin or
extra read. Scalarizing this logical view closes the final 86 saved-register
mirror words. It is a local source representation, not a claim that this pair
is an external Atlus structure.

The two-column threshold table keeps the kind byte and boolean column distinct.
The boolean conversion is `(u8)(columnValue ? 1 : 0)`, following the measured
narrow-return idiom in the adjacent bonus setup. A single call-result local
retains retail's base calculation before its `sltu`/`andi` pair. All random,
unsigned-to-float and fused card-selection chains match with ordinary C; the
old conversion-floor description did not apply to the corrected source shape.

The message globals are pointers to `"upright"` and `"reversed"`: respectively
`0x00763ad0 -> 0x00763ac8` and `0x00763ad4 -> 0x0064ec60`. Their declarations and
`strcpy` now use actual pointer types. Pointer-taking effect/task calls, the
projection argument order, and the dispatch's explicit work arguments agree
with their providers. These corrections preserve every existing sibling byte.

## Rotation ABI and corrected draft behavior

The old draft copied only eight bytes of a three-float axis and passed an
integer zero where retail supplies `$f12 = 0.0f`, followed by `$f13 = 180.0f`.
The real `BtlShuffleVec3` copy preserves all 12 bytes. A shared declaration now
connects `func_00381a70 -> func_003761f0 -> func_003730f0`; the wrapper explicitly
forwards both floating controls instead of relying on undeclared register
passthrough.

The timing fields at interpolation offsets 2 and 4 are unsigned halfwords.
The initializer stores those fields, and `func_00373170` reads them as `u16`
for interpolation. Both interfaces therefore use `u16`. The initializer stays
**116/128 B MATCH**, the wrapper stays **148/160 B MATCH**, and all 83 functions
in their owners retain their prior bytes and statuses. The wrapper's scaled
address uses unsigned EE32 integer addition before conversion to a pointer,
avoiding arithmetic on an integer-derived null pointer for card zero.

The persona lookup is a full-width pointer test. Truncating it to 16 bits, as
the old guarded draft did, incorrectly treats a non-null address such as
`0x00010000` as absent. The chosen dialogue message also keeps the retail signed
`(kind - 1) * 4 + 21` arithmetic; it does not insert an unsigned-byte wrap.

## Verification and regression coverage

The portable tests are `tests/test_shuffle_result_contracts.py` and
`tests/shuffle_result_fixture.c.in`. They include the production bodies without
rewriting them and run with real 32-bit pointers.

- **3032** state transitions, including all phases, invalid dispatch values,
  timer wrap/boundaries, continuation paths, dialogue choices, resource cleanup,
  packed results, full-width persona pointers and callback-time mutations
- **180224** upright-roll comparisons over all 4096 random residues, all 22
  table rows and both columns, checked against independent integer arithmetic
- **800** executions of the real wrapper and initializer together, covering
  both floating controls, all vector components, unsigned timing boundaries,
  multiple card indices and untouched surrounding bytes
- Ordered typed call traces, full work/context comparisons and payload-layout
  assertions at both `-O0` and `-O2`
- **28/28** deliberate behavioral regressions rejected, including lost vector Z,
  float forwarding, truncated pointers/timers, incorrect random formulas,
  missing transitions, message orientation, cleanup and side effects

Local execution used GCC i386/SSE2 with strict interface warnings and
undefined-behavior, bounds and float-cast-overflow traps, run by qemu-i386.
The checked-in runner uses the project's Clang-based native32 harness. Clang
is absent from this local container, so its unittest runtime class skips here;
the identical generated fixtures were executed separately as described above.
This is C behavior coverage, not PS2 execution.

The broad test run passed **838 tests**, with **28 tool/environment skips**.
Source lint reports **zero findings** in the result owner. Draw/Calc retain
18 pre-existing unrelated H011 advisories and two existing pragma advisories;
the changed rotation chain has none.

`make verify` and `make build-progress` were both attempted locally. The full
verifier requires the unavailable `cw3.0.1b119` compiler; the full build requires
the unavailable ee-gcc toolchain. Thus the full image/ELF hashes and final
physical C-link report remain **unverified locally** and must be established by
the equipped proprietary CI run. The scoped eligibility result is not a
replacement for those gates.

### Commands exercised

```sh
python tools/verify.py --json build/shuffle-result.json src/promoted/btlShuffleResult.c
python tools/decomp_lint.py src/promoted/btlShuffleResult.c src/Battle/btlShuffleDraw.c src/Battle/btlShuffleCalc.c
python -m unittest discover -s tests -p test_shuffle_result_contracts.py -v
make test
make verify
make build-progress
```

The seven-owner production/guarded comparison uses `verify.verify_file` on
Result, Draw, Calc, `code1_0021.c`, `code1_004b.c`, `code1_0038.c` and
`effParticle.c`, with `-O2 -Iinclude` and then `-DNON_MATCHING`. Scoped link
checks use `build.eligible_c_objects`, `plan_data_sections` and
`object_layout_is_placeable`; the target text and its jump table are also
relocated independently and compared without masks.

### Input receipts

Measured against base commit `badc42a3a3fd2ff7ee7304dc59181c74e477f24f` with
MWCCPS2 3.0.1 b210, `-O2 -Iinclude`, no new optimization pragma.

- `src/promoted/btlShuffleResult.c`: `808722129dede29a8e062b39ce72b69449f51b0e36976f21c76474ffec26651f`
- `src/Battle/btlShuffleDraw.c`: `cc2577d8b2e62e6d9480d14873037479c05af9f4c09fb85f8858e41acdb3faef`
- `src/Battle/btlShuffleCalc.c`: `79208b446d2812a44f5a240b58bf88f8d2d4742c3ff39f891480eeeee4a635ca`
- `include/btl_shuffle_draw_internal.h`: `bc8d22302f8ed7e3fc1a2d67ba85c845c5abf7c2cab72b6eb5310229b6e6350d`

Resolved text SHA-256: `4a7b9e13f23589030736aff752622ef7a824561bf978ff7156857f0adb8efdd1`

Resolved jump-table SHA-256: `95d8f41c925cf379bbb21c35667d3edf23856846d71983c04d42516f7bf924cf`
