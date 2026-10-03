# Largest Title controller: sprite alpha and independent signed-16 pair

Base: `29758b87c3234fa4f519127c1f61722ca1d087d8` (frozen tail-fade checkpoint).
Only guarded `func_001265a0` changes. Production keeps INCLUDE_ASM; this is a
bounded source repair with no new exact-C credit or full-controller claim.

## Ten actual alpha conversions

Ten low arms assigned `0x4F000000 & 0xFF`, discarding their input and returning
zero. They now numerically convert their actual f32 input to s32, then preserve
the low byte through `(u32)(s32)value & 0xFF`. High arms explicitly subtract
2^31, convert to s32, restore bit31 as u32, then mask. The guard's M2C_BITWISE
macro already expanded to a numeric cast, so these high-arm rewrites clarify
the existing arithmetic rather than repairing a supposed reinterpret cast.

| Source output | Retail low cvt.w.s | Retail draw | Rebuilt threshold / draw offsets |
|---|---:|---:|---:|
| var_5 | 126950 | 1269A8 | 0368 / 03DC |
| var_5_10 | 128450 | 1284A8 | 1E6C / 1EE0 |
| var_5_11 | 128560 | 1285FC | 1F88 / 2014 |
| var_5_12 | 1286C0 | 12871C | 20C8 / 2140 |
| var_5_13 | 128CA0 | 128CF8 | 2690 / 2704 |
| var_5_14 | 129238 | 1292D8 | 2BF8 / 2CAC |
| var_5_15 | 1292F8 | 12938C | 2CB4 / 2D4C |
| var_5_18 | 129F50 | 129FD0 | 38C0 / 3960 |
| var_5_19 | 12A538 | 12A598 | 3F2C / 3FAC |
| var_5_20 | 12A604 | 12A69C | 4000 / 4098 |

The conversion proof admits finite binary32 values from -2^31 through the
largest value below 2^32. Each signed cast is defined within its selected arm.
NaNs, infinities, EE invalid-conversion behavior and arbitrary floating-point
rounding modes are excluded. The ordinary animation values are much narrower.
The masked results fit the existing s32 locals without signed-byte ambiguity.

## Two sine returns, floating scale, independent integer pair

Retail saves the first sine return directly in f20 at 129180, preserving its
fractional part across the second sine call at 1291D0. The guarded source now
does that too; both phase expressions and the frame>=136 / frame-135 selection
remain unchanged. The second return is retained as a float until computing
255 * (1 - return), and that alpha value survives both subsequent conversions.

Retail multiplies the first return by 1.5f, then separately adds fGpffff8170.
The GP word at 761260 is 3F19999A (binary32 0.6f). Separate source statements
preserve the retail mul.s/add.s rounding instead of contracting to an ACC
operation. No integer round trip belongs in this scale. Rebuilt offsets 2BD0
and 2BD8 show the two independent floating operations after the second call;
2B6C preserves the first result across that call in a callee-saved register.
The rebuilt add has the operands reversed relative to retail, retaining the
same finite result; exact register/instruction matching is not claimed.

The signed-16 pair is independently derived from 137.0f * scale. Retail keeps
that product in f2 while f0 converts alpha, then converts f2 at 129268 and
sign-extends the low16 bits at 129274/129278. Rebuilt offsets 2C4C–2C60 perform
the same value flow with `(s16)(s32)(137.0f * temp_f16)`. The old source's
var_f0 dependency has been removed. On its normal low alpha arm, var_f0 had
been 2^31, causing an out-of-range numeric s32 cast; its signed shift was also
unsafe. The old comment documented only instruction-count experiments while
still using the wrong value. The replacement explicitly describes the repair.

This pair feeds func_0025f430 a6/a7 in GPR10/GPR11, independently of its f4/f5
scale arguments in f16/f17 and alpha a1 in GPR5. Both provider branches forward
the pair to func_0025ea20, which writes halfwords at sprite+1C/+1E. These ABI
and storage facts are verified; width/height semantics are not inferred from
the offsets alone. Both actual provider owners verify MATCH.

The signed-pair domain requires the evaluated float product to lie in
[-2^31,2^31). The native and machine checks also cover signed16 wrap behavior,
which is implementation-defined C and is verified for these compilers, not
undefined behavior. Controlled sine returns in [-1,1] produce products around
[-123.3,287.7], wholly within s16; actual sinf execution is not claimed.

## Source-bound execution

The fixture extracts all ten actual conversion-through-call slices, the actual
local declarations and typed call prototypes. It supplies independent finite
conversion inputs, executes the original following call expressions, and
checks alpha at the sprite API boundary along with every other defined input.
Unrecovered coordinate/rotation placeholders receive declared bounded inputs;
the tests do not claim those producer expressions agree with retail.

A separate fixture extracts the contiguous two-sine/scale/pair/two-call block.
The sine boundary checks both actual phase arguments and returns independently
varied fractional values. It overwrites its own first-result storage during
the second call; the source's saved first value must remain intact. The first
sprite boundary similarly changes second-result storage, testing that the
second alpha conversion uses the retained local. Both calls check their real
parameter slots. Internal floating locals are checked where premature
truncation would otherwise be hidden by the final byte conversion.

Per O0 and O2:
- 25,370 isolated conversion/call cases: 2,537 finite sign/exponent/mantissa
  boundary inputs at each of ten sites
- 30,841 extra signed-pair call cases, including negative/fractional values and
  signed16 wrapping, through the actual var_5_14 slice
- 16,200 full local subgraph cases (32,400 sprite calls), with every frame
  26–225 and 81 independent pairs of controlled sine returns

An integer binary32 decoder supplies truncation/byte/signed16 expectations.
The scale oracle uses an exact dyadic rational expression independently of the
source's 1.5f multiplication. Thirty per-site controls individually restore
old low arms, corrupt high-arm low bits, or change the actual call alpha.
Twelve subgraph controls reject truncation, alpha-to-pair dependence, wrong
137 scaling, unsigned intermediate narrowing, wrong threshold/phase divisors,
wrong pair/scale call slots, and mutation of the saved alpha. A high-bit-only
omission cannot be observed after an FF mask and is not advertised as a useful
negative control. All 42 controls fail as intended under O2.

## Actual rebuilt machine dataflow

The scalar interpreter executes the actual retail and final whole-owner object
instructions, including delay slots, threshold comparisons, signed conversion,
byte masking, float moves, separately rounded arithmetic and signed16 narrowing.
Only sine calls are controlled and sprite calls are recorded. Caller-saved
floating registers are invalidated at these opaque calls; unknown ACC outputs
stay unknown and are prohibited from reaching any claimed alpha/scale/pair.
It does not approximate the unrecovered ACC geometry as if it were proven.

- 50,740 actual retail/rebuilt conversion slices pass
- 1,134 actual retail/rebuilt two-sine subgraphs pass, including the 135/136
  boundary and independent fractional returns
- 23 machine controls reject restored low conversions, corrupted high low-bits,
  alpha-to-pair dependence, unsigned narrowing and the wrong paired argument
- Exact retail provider forwarding/store words and GP constants are hash-checked

The second sprite's pre-existing numeric GP scale wrapper remains unchanged.
The machine check therefore asserts its preserved alpha and signed pair,
without pretending its scale or ACC-derived rotation was repaired.

## Preservation and verification

The source audit reconstructs the entire diff from the frozen base: the ten
conversions, bounded two-sine/scale/signed-pair subgraph, and obsolete note only.
Baseline/final whole-owner production objects are byte-identical. All 81
non-target guarded functions, all 420 non-target allocated data bytes and all
their references are unchanged. Switch entry offsets move with the enlarged
body, while every entry prefix/reference and every alias group is retained.
The frame stays 0x520 bytes.

Final-object audits recheck all 26 clear/copy families, all 30 layer calls,
six raw GP colors and all four fullscreen calls. Both earlier alpha-alias
phase/conversion/copy/call slices are byte/reference-identical after relocation
of their position. All 52 distinct color objects remain disjoint. The complete
fade tail and epilogue are byte/reference-identical; its 1,368 real instruction
invocations and four machine controls pass again against this final object.

All 23 current Title native tests pass, with no skips. The affected owner and
actual provider set verifies 207 MATCH / 1 ASM. Lint reports zero errors and
32 existing advisories. The guarded candidate is 17,468 bytes / 3,995 masked
differing words, compared with the base's 17,364 bytes / 3,958 differing words
and the retail window's 17,616 bytes. More faithful behavior here does not
mean a lower diff count or a match.

Unrelated ACC expressions, other upstream sine/phase round trips, the complete
state/timer paths and the actual sine library remain unproven. No full image
build, renderer/gameplay run, CI result, publication or promotion is claimed.

## Reproduction

With existing licensed tools, retail and an existing native32 runner configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_source.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_color_storage.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_layer_calls.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_gp_colors.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_preserved_slices.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_preserved_fade.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_sprite_alpha.py
python docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c src/Event/Fcl/shdSprite.c src/promoted/code1_0025.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Runner skips are unverified. Compiler objects, retail bytes, whole disassemblies
and machine-local paths are excluded from the committed evidence.
