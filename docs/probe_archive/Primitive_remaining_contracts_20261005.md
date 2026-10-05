# Remaining primitive contracts, 2026-10-05

The two functions remain guarded. This run repairs the independent scalar tail
of `func_00480f20` and records executable counterexamples for the state consumed
by both retail functions. It does not promote an ASM fallback to C.

## Source repair

`func_00480f20` previously returned immediately when its quaternion norm was
nonpositive. Retail skips the inverse calculation on that path, but still
executes all six scalar subtractions at `0048104c` through `004810a8`.
Those subtractions have complete input producers and do not depend on the
quaternion result. The guarded C now protects only the quaternion calculation,
retaining its existing defined fallback of leaving that quaternion untouched,
and always computes the six scalar differences.

The complete-owner native objects for the previous and repaired guarded bodies
differ at exactly one instruction, offset `+0x4c`: the norm branch destination.
All other instruction bytes and relocations are identical. Thus the repair
does not change the previous candidate's arithmetic or its non-taken path.
The checked-in replay also verifies exact input/output aliasing and preservation
of the frame header and trailing `value30` storage.

| Target | Compiled C / retail window | Residual | Production state |
| --- | --- | --- | --- |
| `primLine3D` / `0045f790` | 612 / 624 bytes | One differing word; 4 aligned edits include three authentic zero tail words | Guard retained |
| `00480f20` | 420 / 416 bytes | 101 differing words; 82 aligned edits | Guard retained |

The earlier archival 408-byte quaternion match used inverse components without
producers on the failed-norm path. It is not a defined-C promotion candidate.

## Matrix and vertex contract

The complete `primLine3D` owner, its axis/cylinder/spline callers, the P3 donor,
the retail body, and the SDK immediate-mode provider agree on two 36-byte
vertices, position/color inputs, a local identity matrix and four arguments to
`RwIm3DTransform`. There is no incoming matrix argument from which local flags
could be copied. `src/renderware/p2/baim3d.c` retains the supplied matrix in its
pool and executes the transform pipeline; the subsequent line render consumes
the same live local vertex and matrix storage.

Retail first reads the automatic matrix flags at `0045f89c`, stack offset
`+0x9c`. On the `saveStates == 0` path there is no preceding call and no store to
that word. The six saved render states occupy a different stack range. The
matrix's numeric identity fields are produced before the flags read; they do
not initialize its flags field. The current C's only differing instruction
replaces that unproduced load with zero before applying the identity bits.

The replay runs both actual code bodies up to the transform call. Identical
points and colors, with different pre-existing stack flags, produce:

| Initial flags word | Retail submitted flags | Defined C submitted flags |
| --- | --- | --- |
| `0x00000100` | `0x00020103` | `0x00020003` |
| `0x40000000` | `0x40020003` | `0x00020003` |

The point/color packet bytes and the count/transform arguments agree in both
fixtures. This establishes the incoming stack dependency at the API boundary;
it does not claim that the differing reserved flags affect the rendered image.
No vertex padding, extra argument, or later matrix provider produces the word
before the local C macro reads it.

## Quaternion and callback contract

`include/rw/sky2/rtanim.h` declares the reciprocal callback with two pointer
arguments. `func_00481250` registers it in descriptor slot `+0x1c`, and retail
`func_003d5000` copies the full 0x30-byte descriptor into the interpolation
registry. The corresponding `rtquat.h` reciprocal macro writes its destination
only after a positive norm check. Neither contract supplies four extra floating
arguments or initializes a separate automatic inverse object.

At `00480f6c`, retail branches over all producers of `f10`, `f9`, `f1`, and `f0`
when the norm check fails. Their values are then consumed by the quaternion
multiply. The IDA and Ghidra archives expose the same missing producers. The
owner's stream reader accepts the quaternion payload without a norm check;
this audit does not assert that shipped animation assets exercise that path.

For an output quaternion `(0, 0, 0, 1)` and source quaternion `(0, 0, 0, 0)`,
the actual retail instructions yield these finite results:

| Entry state `(f9, f1, f0, f10)` | Retail output quaternion |
| --- | --- |
| `(2, 3, 4, 5)` | `(2, 3, 4, 5)` |
| `(6, 7, 8, 9)` | `(6, 7, 8, 9)` |

Both runs use identical pointer arguments and frame memory. The six output
scalar values are `(15, 30, 45, 60, 75, 90)` in both runs for initial output
values `(16, 32, 48, 64, 80, 96)` and source values `(1, 2, 3, 4, 5, 6)`.
The repaired guard preserves those scalar results without consuming entry FPRs.

The counterexample uses finite dyadic values for which the checked arithmetic
is exact. The small instruction interpreter is a bounded contract check, not a
general R5900 emulator: exceptional inputs, signed-zero behavior and arbitrary
EE rounding are excluded. Four positive-norm fixtures and three exact-alias
fixtures also pass against the retail instructions. The full instruction-byte
comparison against the previous C guard separately establishes that only its
branch destination changed.

Directed scratch probes for a common exit and an enclosing positive-norm scope
retained the 420-byte/82-edit floor. Moving the saved output quaternion until
after validation produced 420 bytes/90 edits. No compiler-option sweep or
uninitialized-source candidate was used in this run.

## Complete owner and storage proof

The source edit preserves the complete default object byte-for-byte:

`335ccdf3303b7431e94a75b8fef6ab44accc3abc7baa151f0b67ad929c3c763a`

The default owner has ten exact C functions and two ASM fallbacks. Every one
of its twelve retail windows is checked, including zero suffixes. All 89 code
relocations resolve to the retail targets. Lifting either guarded body changes
only that target; the eleven surrounding function byte sequences and their
relocations remain unchanged. All executable section bytes belong to those
functions or verified zero alignment gaps.

The repository verifier independently reports `10 MATCH / 2 ASM` on the
installed owner. `decomp_lint.py` reports zero errors and the existing H011
camera-return declaration warning at `func_00457120`; that declaration is
outside the changed function. The scoped diff whitespace check passes.

The four allocated data sections contain 111 payload bytes:

| Object | Retail address | Bytes | Alignment |
| --- | --- | --- | --- |
| Render-state table | `00712490` | 48 | 16 |
| Owned source filename | `007124c0` | 15 | 8 |
| Axis vectors | `007124d0` | 36 | 16 |
| Axis colors | `007124f8` | 12 | 8 |

MWLD's same-name section concatenation, original section order and alignment,
and three independently recovered table addresses place the filename section.
The entire 116-byte `.rodata` span, including all five alignment bytes, equals
retail. No additional initialized, BSS, literal or executable payload is
introduced. No shared header, provider, configuration or progress file changes.

The original owner SHA-256 was
`01938c5853230f52da263341899e6ca1ee52ef7fb912c66445c9a6573f167df7`.
The repaired owner SHA-256 is
`aa869e05bbb24d75b3430e6aa7e5e9027740eef9ae989f32a9b217361b4c553d`.

## Reproduce

Run the self-contained
[`Primitive_remaining_contracts_20261005_replay.py`](Primitive_remaining_contracts_20261005_replay.py)
with the repository's configured Python environment and native toolchain:

```text
python docs/probe_archive/Primitive_remaining_contracts_20261005_replay.py --output build/primitive-contract-receipt.json
```

It compiles the actual complete owner and three isolated complete-owner profiles,
resolves code and data relocations, checks all allocated storage, and executes
the bounded contract fixtures. Scratch paths are unique and the source is never
edited. The retained
[`Primitive_remaining_contracts_20261005_receipt.json`](Primitive_remaining_contracts_20261005_receipt.json)
contains source/object hashes, per-function results, storage extents and fixture
results. It contains no retail payload or private native path.
