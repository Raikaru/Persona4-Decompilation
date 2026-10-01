# One work type for queued primitive batches

This is a source-object contract repair, not a matching gain. The base is
`2980dff69b5e786a3f54283430f2866d89ea71a8`. Only `src/sdkPrimitive.c` changes
in production; public signatures, declarations, callers, allocation sequence,
and layout stay unchanged.

## Defect and repair

The two constructors, `func_0045e8e0` and `func_0045eb20`, previously each
introduced a different block-scope anonymous `TypedPrimBatch` struct. Both
wrote through that type and handed the allocation to `func_0045e310`, whose
parameter was a third struct type, `PrimBatch`. The consumer's color member
was also spelled `u8 *` instead of `PrimByte4 *`. Identical layout and target
bytes did not make those separately declared struct types compatible.

The common `PrimBatch` now has the existing packed-row `PrimByte4 *colors`
member, and both producers use it. The consumer explicitly obtains the
unsigned-byte representation with `(u8 *)work->colors`. Its bytewise channel
reads are permitted character accesses, while the header is accessed through
the same work type that the constructors use.

Both producers retain the separate `void *storage` allocation result followed
by its `PrimBatch *work` view. The allocation is still one 28-byte header,
`count * 4` color bytes, then `count * 8` position bytes. The queued position
member remains `void *`. No extra initialization, padding, public provider
change, or caller adjustment is introduced. In particular, the non-alpha
producer still leaves the alpha byte as returned by the allocation boundary;
the alpha producer writes exactly 1 after the transform loop.

## Whole-owner preservation

Native MWCCPS2 3.0.1 b210, configured `-O2 -Iinclude`, compiled both complete
owners. The entire 9,352-byte object is byte-identical before and after:

`8b3891294ef3f45bbbf39ef2b59cd64724bb3151ac99ac65f16f8279c3a20bc6`

That comparison includes all 4,856 code bytes, all symbol/section/metadata
bytes, all 141 code relocations, and all 149 relocations including the compiler
metadata. Neither object has an allocated non-executable section. No symbol
or owned-data change is hidden by relocation masking.

Both official whole-owner verification runs report **8 MATCH**. Independently,
every relocation was resolved and every emitted function byte compared with
retail; each remaining retail-window tail consists only of zeros:

| Function | Bytes | Window | Code relocations | Zero tail |
| --- | ---: | ---: | ---: | ---: |
| `func_0045da40` | 256 | 256 | 10 | 0 |
| `func_0045db40` | 492 | 496 | 17 | 4 |
| `func_0045dd30` | 664 | 672 | 6 | 8 |
| `func_0045dfd0` | 832 | 832 | 26 | 0 |
| `func_0045e310` | 908 | 912 | 30 | 4 |
| `func_0045e6a0` | 568 | 576 | 24 | 8 |
| `func_0045e8e0` | 564 | 576 | 14 | 12 |
| `func_0045eb20` | 572 | 576 | 14 | 4 |

The companion JSON binds the source/object hashes, complete relocation lists,
resolved function hashes, allocated sections, fixture/test hashes and native
receipt. Lint reports no errors; the two unchanged H011 advisories concern the
existing `func_0045d890` and `func_00457120` provider declarations. They are not
expanded into this narrowly scoped repair.

No full-image build was repeated. Exact whole-object identity is the
preservation evidence for this replacement, not a newly claimed link result.
The guarded rank5 controller is untouched; its supplied full391/stock390
status is not remeasured here. Zero-choice phases9/12 remain unproven.

## Native constructor-to-callback proof

`tests/test_primitive_batch_contracts.py` extracts the actual three complete
bodies and their actual types without body rewrites. The 32-bit freestanding
fixture runs with O0 and O2, undefined/bounds traps, and the existing native32
adapter. It uses real untyped mmap allocations rather than declaring an
alternative typed work object. The callback is retrieved from the actual
queued node and dispatched after the caller's input arrays are overwritten.

At each optimization level, **3,200 queued scenarios** pass. They cover both
constructors, five positive counts (1, 2, 3, 7, 16), enabled/disabled and
non-boolean state flags, signed offset boundaries, non-alpha X values outside
signed-halfword range, zero/negative/non-unit scales, four instrumented
rotation pairs, unsigned color extremes, existing alpha flag bits, and five
draw-time alpha mutation modes. The independent model checks:

- Raw header offsets, allocation size/hint, copied colors, transformed points,
  untouched input arrays, callback/work slots and queue identity
- Delayed ownership of the copied buffers; no release or draw at enqueue
- All emitted vertex fields and untouched vertex bytes
- Ordered render-state save/setup/restore and independent camera reciprocal
- Exact alpha `== 1` predicates, the post-draw live reread, and preservation of
  unrelated 64-bit flag bits
- Vertex-buffer release before work release, with guards and actual unmapping

**31 independent behavior mutations are rejected at both O0 and O2**, changing
only an extracted body while leaving the oracle unchanged. They cover
allocation/layout, row strides/copies, offsets/transforms, stored header
values, alpha initialization, queue slots/destination, emitted vertices,
render state and release behavior. Three additional structural controls
reject each producer's former distinct work type and the former byte-pointer
header. The baseline source also fails the canonical work-type check.

Runtime success alone cannot diagnose all incompatible-type accesses,
especially with the existing native support's `-fno-strict-aliasing` option.
The explicit source/type checks establish the common-type change separately;
native execution checks its behavior. External allocation, render, state,
queue and trigonometric providers are instrumented boundaries, not newly
recovered providers. Zero/negative constructor counts and allocation failure
are outside this fixture's established domain.

## Reproduction

With the configured private compiler environment already available:

```sh
python tools/verify.py src/sdkPrimitive.c --json /tmp/primitive-verify.json
python tools/decomp_lint.py src/sdkPrimitive.c
python /workspace/shared/run_p4_qemu32_tests.py "$PWD" test_primitive_batch_contracts
```

On a host with working native i386 execution, the last command can instead be
`PYTHONPATH=tests:tools python -m unittest -v test_primitive_batch_contracts`.
The recorded native adapter run reports 5 tests, no skips, and OK. Before/after
objects and official JSON reports are retained in the isolated evidence
folder `/workspace/shared/p4-primitive-batch-evidence/`; `make_receipt.py` there
rechecks whole-object identity and resolves all eight functions against retail.

## Independently verified main projection

The initial receipt above describes the research baseline. The minimal five-file
projection was separately reviewed on main `b690bb2cf0afdae66301fa6422f6997c4715a91f`.
It preserves main's existing rectangle API and does not import the research
branch's rectangle header or guarded controller. The resulting source SHA-256
is `6c06803f18e2d3039fa51a9630e7607a07b268500efce205165edf0e1040a60f`;
the complete object remains byte-identical to main and the research result.
The JSON's `main_projection` section records this distinct source identity.

On this exact source, the independent review and integration reruns passed all
five focused methods without skips, including 3,200 cases per O0/O2 and all
31 behavioral and three type controls. Full integration linked 604 C objects
and 54 SDK objects, retained all 8,586 linked windows with an identical report,
and passed both retail hashes. The ordinary suite reported 868 tests with
34 capability skips and no failures; lint reported zero errors and two existing
API warnings. No new matching function is claimed.
