# Large Battle controller: integer timing clamp and signed-halfword additions

Base: `1999e7d6360015ae6e7f1ca8f687d3db5a65c8a7`.
Only guarded `func_001a59a0` changes. Its fallback and every production function
remain intact. This is a semantic/defined-behavior repair, not a matching
promotion or an optimization experiment.

## Observed calculation

The timing queries have already been reconciled to actual signed-halfword
returns. The calculation at `001A5D1C..001A5D74`:

1. Sign-extends the initial frame count to 16 bits
2. When the ending time is later, converts their signed difference to float,
   multiplies by the GP float at `00761218` (bits `3EB33333`, approximately 0.35),
   and converts the product to a signed integer
3. Compares that integer with 26 and replaces it with the integer **25** when
   it reaches the threshold
4. Sign-extends the adjustment to 16 bits, adds it, and sign-extends the sum

The optional flag adjustment at `001A5D90..001A5D98` adds eight and narrows.
The paired-unit branch queries motion 0x1A at rate 1.0, calculates the two
relative delays against its signed returned frame minus four, then adds twelve
and narrows at `001A5DFC..001A5E04`.

The old draft instead stored the adjustment as f32 and assigned `3.5e-44f`
on the clamp branch. That is the floating interpretation of the integer-25
bit pattern, not the number 25; converting it numerically to an integer gives
zero. The draft also used shift-by-48 wrappers on 32-bit signed values, and
left shifts of negative values, to approximate halfword extension. Those C
operations are undefined.

The source now retains an s32 `timingAdjustment`, clamps it to the integer 25,
and expresses the observed signed-halfword conversions with s16 casts. The
later `temp_2_17` consumer likewise receives a defined signed-halfword value.
The surrounding provider call, relative-delay branch and packet construction
remain unchanged. No global, provider signature, compiler setting or other
controller was altered.

## Native source contract

`test_large_battle_timing_clamp.py` extracts the actual contiguous calculation
and its later result conversion. At both O0 and O2, 1,572,864 cases cover:

- Every positive timing difference through 65,535
- Every signed initial frame against the largest and smallest possible
  signed-halfword ending time, including equal/reversed timing
- All four combinations of the two optional flags, and both paired-unit paths
- Full signed-halfword companion results, the relative-delay split, and wrap
  boundaries after the eight/twelve additions

The expectation is independently integer-domain: the bounded uncapped
nearest-binary32 source product truncates as floor(7*d/20), and larger
positive differences cap at 25. The final sign extension is implemented in
the oracle using masks and subtraction rather than the source casts. These
host tests establish the defined C source contract; they are not a PS2 FPU
emulator or gameplay test. The compiler/retail audit separately verifies the
actual multiply/conversion/clamp/narrowing instructions and exact GP constant.

The unchanged timing provider is a recording boundary in this fixture. Its
real signed-halfword return, input unit, motion 0x1A, rate and invocation count
are checked. Existing actual-provider timing suites are rerun separately.

Seven mutations fail: zero clamp, cap 26, quarter multiplier, rounding instead
of truncation, AND instead of the optional-flag OR, wrong paired addition and
loss of signed-halfword wrapping. The zero-clamp mutation isolates the old
numeric error; it does not claim to execute the old undefined shift expressions.
All current animation, UID/storage, predicate, motion/opening and approach/alias
families pass together: **40 tests, no skips** under the explicit QEMU adapter.

## Complete-owner proof and limits

All eight baseline/final configurations compile: production, each controller
independently guarded and both guarded. Production objects are byte-identical.
The proof explicitly checks `001a7720` itself in every configuration, including
the both-guard build, in addition to every other unaffected function. The
single-7720 configuration is also byte-identical as an entire object.
All 148 allocated data bytes and all 36 references are unchanged.

The owner remains **69 MATCH / 2 ASM**. Lint retains zero errors and the same
24 existing warnings. No warning is treated as a waiver of another defect.

The restored, defined dataflow increases the 59a0 body from **7,604 to 7,852
bytes**, versus the 7,536-byte retail window. Its normalized differing-byte
count moves **5,678 to 5,944**, and the frame moves **0x400 to 0x450**. These
are measured nonmatches, not instructions or progress credit. Source correctness
is not judged by a size band. The guarded 7720 stays at 17,400 bytes with its
prior 12,850 differing bytes and 0x680 frame.

The controllers still need real provider-sized stack output objects, remaining
old declarations, and other decompiler-expression repairs. No aggregate image
build, remote CI, gameplay execution or push is claimed by this checkpoint.

## Reproduction

With existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_timing_clamp_20261003/audit.py proof/timing-replay
python docs/probe_archive/Large_Battle_timing_clamp_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit `--runner` on a host capable of direct i386 execution. Runtime skips are
not accepted as passes. The audit retains source/test fingerprints, hash-validates
retail, checks the decisive instructions and GP value, and emits complete
per-function/data/reference comparisons into the specified local output.
