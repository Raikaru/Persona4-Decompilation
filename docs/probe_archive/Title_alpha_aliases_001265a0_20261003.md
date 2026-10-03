# Largest Title controller: remaining alpha-byte aliases and raw GP colors

Base: `87ed8afca8b62d80fe72148b10122a596e5996dc`.
Only guarded `func_001265a0` production-source text changes. Its assembly
fallback stays enabled; this is a bounded source repair, not a promotion.

## Real color words, real fourth-byte fields

Retail loads two GP words, at 00762D70 and 00762D74, directly into four-byte
stack color objects at SP+69C and SP+698. Both words are **0x00FFFFFF**.
Their floating interpretation is a tiny positive value; the draft's numeric
float-to-s32-to-float conversion turned each into zero, losing white RGB.

The source objects now use the existing TitleDrawColor union and receive the
GP float values directly in `.value`, preserving all four representation
bytes. The actual byte stores at SP+69F and SP+69B alias `.bytes[3]` of those
objects. They are no longer unrelated M2C_UNK scalar locals. Each modified
color is then copied as a complete raw value into the existing shared sp6BC
object before its depth-10 layer call. The same shared identity is retained.

The old low conversion arms assigned `(0x4F000000 & 0xFF)`, which is zero,
rather than converting the actual alpha. The repaired expressions use the
observed numeric signed conversion followed by low-byte masking. The high
arm subtracts 2^31, converts to signed, restores the high bit and masks.
Unsigned 32-bit temporaries retain the masked register words until the real
byte store, avoiding an unnecessary implementation-defined s8 assignment.

For the constant branch, the actual input is 255.0 and the rebuilt compiler
folds the result to byte FF. The dynamic branch retains both retail conversion
arms. Tests admit only finite values in the range where those signed casts
are defined: from -2^31 through the largest binary32 below 2^32. NaN,
infinity and EE integer-exception behavior are outside this conversion proof.
The actual sine-derived alpha is a much narrower finite range.

The phase calculation also used an unjustified float-to-integer round trip.
Retail loads fGpffff8094 directly as a float (bits 3FC90FDB), multiplies it
by the signed frame-minus-25 value, divides by 60 and adds that same float
before calling sinf. The source now retains the actual float value. No sine
provider implementation or approximation is changed.

## Source-bound native contracts

The new fixture extracts both contiguous load/convert/alias/copy/call blocks,
the actual local declarations and the dynamic conversion's two branches.
It surrounds the two source colors, shared destination and rectangle input
with canaries. The typed layer-call boundary checks depth 10, state flag 1,
rectangle identity, unchanged RGB, correct alpha and source/destination
independence. The sinf boundary checks the actual phase argument and supplies
controlled finite results; the real sinf library is not executed here.

At O0 and O2, **16,384 block/call cases** cover the actual RGB word plus many
other raw representations, every frame 26 through 85 repeatedly, and 8,192
sine-result samples in [-1,1). The fractional phase and signed truncation are
therefore exercised beyond merely testing alpha endpoints. The raw GP color
representations are copied without performing arithmetic on them.

A further **2,537 conversion cases** exercise both arms across finite exponent
ranges, mantissa boundaries, positive values up to the binary32 below 2^32,
and negative values down through -2^31. A separate integer bit-field decoder
computes the expected truncated low byte without floating numeric casts.

Eight controls reject old constant/dynamic zero-alpha arms, wrong byte alias,
numeric GP-color conversion, numeric phase conversion, copying before the
alpha store, wrong high-arm low bits and numeric instead of raw value copy.
All current Title suites pass together: **14 tests, no skips**. The actual
unchanged layer/vertex and overlay providers execute in the earlier suites.
These are native source contracts, not complete-controller, actual-renderer,
trigonometric-library or PS2 FPU/gameplay coverage.

The preceding rectangle documentation also receives a wording correction:
its templates vary X and width, with distinct fixed heights 42/43. That test's
code and scenarios are unchanged.

## Retail, rebuilt and complete-owner proof

The audit hash-validates all three GP constants and pins both retail alpha
stores, copies, conversion sequences and the phase calculation. The rebuilt
object shows direct GP load/store pairs without numeric conversion, source+3
byte writes, raw copies to the shared color, the folded FF constant arm and
both dynamic integer arms. Complete direct-access scans find three accesses
to each source object in retail and rebuilt code, with no wider overlap.

Together with the earlier fifty-object proof, **52 distinct aligned color
objects** are verified. All twenty-six byte-clear/copy families and all thirty
layer-call argument transports rerun against this object.

Base/final production and guarded builds preserve the whole production object
byte for byte, all 81 guarded siblings, all 420 non-target allocated data
bytes and their references. Frame growth 0x4F0 to 0x500 moves the shared color
SP+4EC to SP+4FC. As in the prior checkpoint, exactly one named SWC1 store
changes in table entries 1, 2 and 3; its two addresses are bound to the actual
first layer-call argument. All other prefix words/relocations and table alias
groups are unchanged.

Caller/provider owners remain **148 MATCH / 1 ASM**, with zero lint errors and
32 existing warnings. The guarded body is **17,452 bytes / 3,941 differing
words**, versus 17,360 / 3,949 at base and the 17,616-byte retail window.
These remain measured nonmatches. Other GP-color interpretations and unrelated
decompiler expressions are still unfinished. No aggregate image, CI or push
is claimed.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_alpha_aliases_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_alpha_aliases_001265a0_20261003/audit_color_storage.py
python docs/probe_archive/Title_alpha_aliases_001265a0_20261003/audit_layer_calls.py
python docs/probe_archive/Title_alpha_aliases_001265a0_20261003/audit_alpha.py
python docs/probe_archive/Title_alpha_aliases_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Omit the runner only on hosts with working direct i386 execution. Runtime
skips are unverified. Whole disassemblies and compiler objects are not included
in committed source-only evidence or delivery archives.

## Pointer-identity and sine-endpoint follow-up

This fixture-only follow-up adds an explicit expected-rectangle
pointer check to the alpha fixture, plus an equal-payload wrong-object control.
Previously rectangle bytes, but not pointer equality itself, were checked by
that stub; the rebuilt 30-call audit established the actual identity. The
controlled sine +1 endpoint is also added for every selected frame, yielding
16,508 block/call cases per optimization and nine controls. The branch's
actual local selection is 25–85: its separate <25 check follows an earlier
>=26 block. The original committed corpus covered only 26–85; the expanded
corpus includes frame25. No alpha production expression changes in that
follow-up.
