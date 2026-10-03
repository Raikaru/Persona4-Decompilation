# Largest Title controller: opening rectangle Y fields and snapshots

Base: `9d485ae870fd8ea6b8986dde35984b71789e6d06`.
Only guarded `func_001265a0` production-source text changes. Its fallback
remains enabled; no match promotion or whole-controller recovery is claimed.

## Two real fields inside sixteen-byte objects

In the opening state-3 branch, retail copies D_005E5650 to SP+520, writes a
signed Y word at SP+524, then copies the complete modified object to SP+590
before the first layer call. It similarly copies D_005E5660 to SP+510,
writes Y at SP+514, and copies that modified object to the same SP+590 input
before the second call.

The draft instead assigned unrelated `unksp524`/`unksp514` scalar locals and
then recopied the unmodified global templates to sp590. The resulting calls
lost both calculated Y coordinates. It also rounded the shared floating
slide offset to an integer before computing the two Y expressions.

The source now uses one actual representation union for each source snapshot:
`s128 bits` aliases four signed 32-bit `words`. The two source objects remain
independent, 16-byte aligned, sixteen bytes wide. Word 1 is Y. Each whole
modified `.bits` snapshot is copied to the existing s128 sp590 object.
No padding, synthetic layout address or compiler option is added.

The floating offset is retained as the actual retail product:

```
42.0f * (1.0f - (f32)frame / 20.0f)
```

The first Y conversion is `(s32)-offset`; the second is
`(s32)(406.0f + offset)`. Retail retains the product in f20 between the calls
and performs the two separate CVT.W.S conversions. The rebuilt code retains
it in f25 and exhibits those same operations. The initial frame increment and
upper clamp to twenty are unchanged.

`audit_rectangles.py` verifies 28 decisive retail instructions and the actual
rebuilt field stores, whole LQ/SQ snapshot copies, unrounded floating product,
template relocations and two provider destinations. The rebuilt source
snapshots are SP+3C0 and SP+3B0, and the shared consumer copy is SP+3D0.
All are aligned, frame-contained and disjoint from the fifty color objects.

## Executed source and provider contract

The fixture extracts the actual union/declarations, counter update/clamp and
contiguous two-snapshot/two-call block. It executes both real layer and vertex
providers. Only camera lookup, state API and draw callbacks are controlled
boundaries. All four local objects have two-sided canaries; the two global
templates and copied color remain unchanged.

At O0 and O2, **65,536 cases** cover every signed-halfword initial counter,
including the ordinary zero-to-twenty range. The increment is safe for this
admitted domain, and the existing upper clamp is applied. Rectangle templates
vary X and width and have distinct fixed heights 42/43; their old Y words are deliberately
unrelated values. Each draw checks all 64 emitted vertex words and the
combined get/set/Sky/draw/restore event order.

The Y oracle uses independent integer-domain expectations over the bounded
counter range: with the clamped frame, `q = floor(21*(20-frame)/10)`, the
first Y is -q and the second is 406+q. The fixture separately verifies the
intermediate still has a fractional part whenever that numerator is not
divisible by ten, catching the old premature rounding even when final integer
Y values happen to coincide. This is an executed native-binary32 source
contract, not an EE FPU emulator or a claim for every possible s32 input.

Seven controls reject either stale template copy, either wrong member offset,
premature rounding, the wrong second Y base and storing float bits as a
signed coordinate word. The complete current Title suites pass **12 tests,
no skips**. This checkpoint also strengthens the preceding color-family
fixture with negative infinity, six signed representation-boundary cases and
actual pointer-end/counter checks. Its 49,872 cases now detect short layer
clears independently of the later alpha overwrite. No color production
expression changes.

The tests deliberately supply an already-established color to this isolated
rectangle block; they do not certify the preceding GP-color interpretations,
00126090, other controller branches or gameplay behavior.

## Preservation and specific table-prefix movement

Fresh base/final production and guarded builds preserve the entire production
object byte for byte, all 81 guarded siblings, all 420 non-target allocated
data bytes and every non-target reference. The full thirty-layer-call argument
audit reruns, as do all twenty-six rebuilt color loops/copies and fifty-object
storage checks.

The frame grows 0x4D0 to 0x4F0. This moves the shared color object from SP+4CC
to SP+4EC, also visible in one instruction of jump-table entries 1, 2 and 3.
The table proof permits exactly those three SWC1 f0 stores to the same named
object, binding its old/new address to the actual first layer call. Every
other entry-prefix instruction and every prefix relocation is unchanged; all
sixteen entries retain their alias groups. This is an explicitly checked
object displacement, not a blanket masking of stack offsets or a claim that
the raw prefixes are all identical.

The caller/provider owners remain **148 MATCH / 1 ASM**, with zero lint
errors and 32 existing warnings. The guarded target is 17,360 bytes against
the 17,616-byte retail window, versus 17,236 at base. Its relocation-masked
difference improves 3,967 to 3,949 words. These are still nonmatches; no match
credit, aggregate-image pass, remote CI or push is claimed.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/audit_color_storage.py
python docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/audit_layer_calls.py
python docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/audit_rectangles.py
python docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Omit the runner only for functional direct i386 execution. Skips remain
unverified. Committed receipts omit whole disassemblies and compiler objects.
