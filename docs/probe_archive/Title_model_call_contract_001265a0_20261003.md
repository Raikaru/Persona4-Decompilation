# Largest Title controller: truthful model calls and packed top bytes

Baseline: `69799eb8fe97c414501d20af309688f147e0e5d2`, the frozen palette
checkpoint. Only guarded `src/promoted/code1_0012.c::func_001265a0` changes.
The NON_MATCHING guard and assembly fallback remain. **No new exact-C credit,
full-controller correctness, or special-record geometry recovery is claimed.**

## Source contract

The actual same-owner, matching provider `func_00124bb0` returns `void` and
has twelve parameters: model index; x, y, z, pitch, yaw, roll; base and
highlight packed words; scale; flags; model-array pointer. Its separate EE
argument counters consume five integer/pointer lanes (`a0` through `a4`)
and seven float lanes (`f12` through `f18`). The provider is unchanged.

The controller's conflicting old-style `s32 func_00124bb0()` declaration is
removed, exposing the already visible actual definition. All five calls now
use its precise source argument order:

- The three generic calls select old arguments
  `0,6,7,8,9,10,11,1,2,12,3,4`. Only old argument 5, a fabricated numeric
  conversion of the packed highlight top byte, disappears
- The two special calls select old arguments
  `0,5,6,7,8,9,10,1,2,11,3,4`. No expression disappears. In particular,
  their repeated ACC-placeholder producer expressions remain supplied/unproven
- The five real palette-selected base expressions remain intact
- Each actual top-byte shift casts its input to `u32` before shifting:
  three packed temporaries and two inline special-call terms
- The complete use census finds only a declaration, top-byte definition,
  packed-color use and fabricated float use for each generic temporary.
  After removing the fabricated use, its three remaining occurrences form
  an exclusively raw-word lifetime; its type changes from `s32` to `u32`

The lower 8- and 16-bit shifts operate on masked byte values and cannot
exceed signed-int range. Casting the destination alone would not repair the
24-bit signed-shift overflow; this checkpoint changes the operand before
that shift. It does not rewrite channel interpolation.

`func_00126090` is untouched, including its unresolved unused-float arity.
Other helper declarations/calls, sine and ACC producers, matrices, and all
other functions are unchanged. A whole-source replay reconstructs the
complete diff from the frozen base and rejects any extra edit.

## Provider and geometry limits

The actual provider freshly verifies **MATCH, 956 / 960 bytes**, with zero
normalized difference, in the complete owner. Its pre-existing
`matrix + 0x0C` uninitialized flags OR is deliberately retained. The native
call fixture extracts its exact twelve-parameter signature for a typed
recorder; it does not execute, initialize, replace or claim defined execution
of the full provider.

The special retail calls write six distinct ACC geometry results to
`f12,f14,f15,f16,f17,f18`, with zero in `f13`. The guarded source still
repeats one unproven producer expression six times, and MWCC shares that
expression result. This checkpoint establishes its argument positions,
packed words, index, flags and model-pointer transport. It **does not**
establish that its six geometric values equal the six retail results.

## Source-bound native evidence

The fixture extracts the live provider signature, all five complete call
expressions, all call locals, and the three actual packed-word assignments.
It uses real 32-bit pointers with Clang's undefined-behavior/bounds traps,
without changing target declarations or using an incompatible fake ABI.

At both O0 and O2, two modes each pass **583,680 cases**:

1. The unaltered source call expressions, with defined bounded input values
2. An explicitly labeled producer-boundary mode that supplies independently
   tagged values for the six unresolved special expression occurrences

Every mode covers all nineteen record positions, all six palette indices,
every byte value in every base-color channel and every highlight channel,
distinct finite negative/fractional pose/scale fields, differing pointer
identities and both flag values. Model indices also include `±16777217`,
so the actual s32→f32→s32 round trip is observable rather than accidentally
identical to an integer load.

All **71 controls** reject: seven floating-lane swaps at every call site,
swapped colors, wrong flags, wrong model pointer, wrong model index,
removed float-round-trip conversion, missing base/highlight alpha masks,
and the original signed top-byte shift. The last fails through the actual
sanitizer trap on a high byte. Distinguishing special-lane swap controls use
the labeled supplied-producer mode; they do not claim independent source
geometry that the guarded expressions have not recovered.

## Actual retail/rebuilt boundary instructions

The machine replay executes **389,120 cases** over authenticated retail and
final emitted instructions: the nineteen actual retail records plus nineteen
distinct synthetic records, all 1,024 per-channel patterns, and all five
sites in both forms. Its explicitly disconnected, defined slices cover:

- The actual four-instruction model-index load and signed float round trip
- Every actual mask, 24/16/8-bit shift and OR composing the highlight word
- Base-color alpha replacement
- The six generic record field loads plus the zero Y lane
- Special output transport from supplied producer boundaries
- The actual flag materialization and model-pointer move

It independently checks the two special model-global addresses against
retail and the candidate's resolved symbol references. It verifies that
omitted producer spans do not overwrite the carried model index, red word,
combined channels or final base/highlight integer lanes. A whole-target register
census also binds the model pointer to the actual task-work return until its
epilogue restore, and the final floating writers and zero Y lane are checked. Channel arithmetic
starts at supplied byte inputs. Candidate palette-selection loads are bound
to the independently rerun actual palette machine proof, rather than
asserted correct by a fake stack pointer.

All **38 machine controls** reject: wrong red/green shifts, wrong flags and
pointer at each candidate call, and wrong source field offsets at all three
generic calls. The special retail ACC destinations are audited, while their
arithmetic remains outside execution and equivalence claims.

## Whole-owner and prior-scope gates

Fresh baseline/final production and NON_MATCHING compilations prove:

- The entire production object is byte-identical
- All 81 guarded siblings retain exact code bytes and references
- All 420 non-target allocated data bytes and references remain identical
- All sixteen actual switch destinations keep their alias groups and exact
  source-live entry operations/references, allowing only the explicitly
  checked work/counter register allocation and shared color home changes
- The only removed target references are **33 `fptodp` default promotions**,
  seven at each generic call and six at each special call. Every other
  target reference preserves its order and immediate addend; the precise
  outside-model ranges also retain relative reference positions

Removing the old-style default promotions shrinks the guarded frame from
`0x680` to `0x4B0` and changes register allocation. No general instruction,
register, stack or relocation mask is used to call the whole target equal.
No padding, address-observation trick, volatile, fake ABI or instruction-count
steering is added. All fifteen palette objects and all 52 established color
objects remain individually disjoint in the emitted frame.

Against this final object, the replays again pass all ten palette-copy loops
and local selections (**61,500 cases; 30 controls**), 26 color families,
twelve alpha aliases, thirty layer calls, six GP color words and four
fullscreen calls. Both earlier standalone alpha slices retain their exact
operations/references with an explicit allocation map. The sprite suite
passes **50,740 retail/emitted conversions and 1,134 two-sine invocations**
with 23 controls; the fade suite passes **1,368 invocations** with four
controls. These replays use final-object registers/homes and preserve their
original explicit producer and renderer boundaries.

All **29 current Title native tests pass with zero skips**. Seven relevant
owners verify **253 MATCH / 46 ASM** across 299 functions; this owner stays
**81 MATCH / one ASM**. Lint reports zero errors and 32 existing advisories.

The guarded target is **16,816 / 17,616 bytes, 3,955 masked differing words**,
versus the palette base's 17,496 bytes and 3,986 words. It remains nonmatching.
The lower count does not prove the untested controller, renderer or gameplay.
Full linked-image rebuild, CI and publication are not claimed or performed.

## Reproduction

Use the repository's existing licensed MWCCPS2 3.0.1 build 210 configuration
(`-O2 -Iinclude`, adding `-DNON_MATCHING` for the guarded owner capture),
authenticated retail input and an existing i386 runner. From repository root:

```
P4_NATIVE32_RUNNER=qemu-i386 bash docs/probe_archive/Title_model_call_contract_001265a0_20261003/replay.sh
```

This regenerates authorized assembly, builds both owner configurations,
reruns source/retail/candidate/preservation and prior-scope audits, executes
the native suites, verifies the seven owners, lints, measures and seals the
source-only receipts. `verification.json` binds them to the source SHA-256.
Licensed objects, retail bytes, disassemblies and full local reports remain
uncommitted under `proof/`; no binary or machine-local tool path is published.
