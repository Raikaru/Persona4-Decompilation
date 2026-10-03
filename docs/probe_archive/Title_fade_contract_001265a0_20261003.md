# Title tail fade: UV storage and mixed-ABI contract

Baseline: `fd71083ec6e1a69e27b86f947618e913e5acd20e`.
Owner: `src/promoted/code1_0012.c`, guarded `func_001265a0`.
This is a bounded source-contract repair, not a new matching function.

## Actual contract

Retail `0012A948–0012AA28` conditionally draws the trailing fade. For a positive
countdown at work `+0x2c`, it first copies four contiguous eight-byte UV pairs
from `005E56B0` into a 32-byte stack object. The pairs are `(1/1024, 1/512)`,
`(0.625, 1/512)`, `(1/1024, 0.875)`, and `(0.625, 0.875)`.
The old source reserved only one four-byte scalar and advanced four-byte
pointers by eight elements, writing at offsets 0/4, 32/36, 64/68 and 96/100.
The source now reserves the whole object as a word/pair union, advances by
two words, and transports the original words without numerical conversion.

The matching provider `00366c70` takes independent GPR/FPR arguments:

```
s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height,
                  s32 rgb, s32 alpha, s32 mode, s16 centerX, s16 centerY,
                  struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);
```

This call supplies x/y/z zero, 640-by-448 dimensions, white RGB, signed integer
alpha, mode one, zero centers, null matrix, the getter's texture word, and the
four UV pairs. The old shadow declaration and apparent register-order argument
list promoted the quotient as a float argument and omitted the real z argument.
The old `(s64)&sp530` is removed. The shared file-scope prototype is also made
coherent with the actual matrix and UV pointer types; that edit is outside the
guard and its production callers are checked, not assumed unaffected.

`00401b80` is a no-argument, signed-word getter. Its actual retail instructions
return the word at `gp-0x4700` (`007649F0`), the same storage used by its matching
C definition. No invented argument or 64-bit return remains in this caller.
The UV copy, count decrement and alpha-input snapshots precede this lookup.
Retail performs the float quotient/conversion before the getter; MWCC safely
moves the candidate's pure arithmetic after this read-only leaf while retaining
the already-snapshotted count and divisor. No volatile or dummy local forces it.

The update callback `0012aa70` seeds this countdown with ten at `0012AE4C` and
`0012B240`, or thirteen at `0012B404`. The retail audit enumerates all three
stores through that callback's work register and verifies their immediate
producers. Thus ordinary positive lifecycle inputs are 1..13. Nonpositive
values skip subtraction and multiplication entirely. The signed product is
not claimed defined for arbitrary positive s32 inputs. Tests also cover bounded
safe positive values through 65536, without inventing a runtime clamp.

## Whole-owner preservation

The replay compiles the baseline from Git and current source in their real owner
configuration, in both production and `NON_MATCHING` modes.

- All 82 production functions, allocated data and references are unchanged;
  the entire raw production object is byte-identical
- All 81 established guarded siblings are byte/reference-identical
- All 420 non-target allocated data bytes and all their references are unchanged
- All sixteen target jump-table offsets and case-alias groups are unchanged
- Case entry prefixes 4..9 and all prefix references are exact
- Prefixes 0..3 change only the known shared-color stack home from 0x4fc to 0x51c
- Prefixes 10..15 enter the repaired tail. Exact old/new words, UV symbol
  references and the branch's real restore-epilogue destination are checked
- Across the entire 17,068-byte pre-tail prefix, every non-stack word and every
  relocation is identical. Exactly 187 SP-relative stack-home instructions
  change according to explicit per-home displacement rules, plus the frame
  allocation grows from 0x500 to 0x520 for the real 32-byte object. No opcode,
  branch or relocation class is broadly masked

Production verification is **81 MATCH / one ASM** in the owner, **34 MATCH** in
`code1_0036.c`, and **12 MATCH / 45 ASM** in `rw/basky.c`: 127 MATCH / 46 ASM
across 173 functions. Both relevant providers report MATCH. Owner lint has zero
errors and the existing 32 advisories (31 H011, one H003).

The guarded target changes from 17,404 bytes to **17,364 / 17,616 bytes**, with
**3,958 masked differing instruction words**. Its guard remains. The missing
retail suffix is nonzero; shorter size is not an exactness claim.

## Behavioral evidence and limits

The native 32-bit fixture extracts the actual tail block, actual local types,
complete renderer/getter declarations and getter body. A strict typed recorder
stands at the renderer boundary. The getter's GP read is instrumented to check
and mutate source/state at the lookup boundary, proving that UV data, countdown
and alpha are already snapshotted. All four UV pairs are consumed as real float
loads; destination/source/state guards and untouched state words are checked.

It passes **107,904 cases at each of -O0 and -O2**, covering all realistic counts,
nonpositive gates including INT_MIN, states selecting each divisor, bounded
extra counts, four texture words, retail UVs and distinct per-word finite tags.
All **26 runtime negative controls** fail and a dummy getter argument fails
compilation. All eight Title suites pass together: **20 tests, zero skips**.

The separate bounded machine interpreter executes **1,368 actual retail/emitted
tail invocations**. It executes the actual getter leaf, resolves all four emitted
tail references to their real addresses, and checks exact copy reads/writes,
countdown writes and every renderer argument lane/stack slot. No unwritten
stack read occurs. Four instruction mutations fail: old stride, wrong alpha
lane, wrong height and shifted UV pointer. The ELF is hash-validated first;
provider argument-save words and countdown producer instructions are checked.

The full renderer is deliberately not executed by the native fixture: its
existing null-matrix path reads uninitialized `identity.flags` before ORing the
identity bits, as the retail instructions do. That provider is unchanged; no
invented initialization hides the boundary. This is not full-controller,
rendering, GS/DMA/VU, gameplay, full linked-image, CI or publication evidence.
No new exact function, progress credit, or compiler-floor claim is made.

## Reproduction

With the existing licensed compiler, hash-validated retail ELF and optional
existing i386 runner configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_fade_contract_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_fade_contract_001265a0_20261003/audit_fade.py
python docs/probe_archive/Title_fade_contract_001265a0_20261003/run_contracts.py --runner /path/to/qemu-i386
python tools/verify.py --json proof/owners.json src/promoted/code1_0012.c src/promoted/code1_0036.c src/rw/basky.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
python tools/decomp_lint.py src/promoted/code1_0012.c
```

The archived evidence is source-only. Compiler objects and full local reports
stay under `proof/`; replay creates them afresh and does not mutate owner source.
