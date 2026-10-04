# Combination-row renderer: exact closure, 2026-10-04

This follows the retained rank16 comparison on the source tree published as
`a9d7c7c58e35602a5fea100df12eff31e328e4a5`. It preserves the accepted row-Y
repair, current provider order, field-event controller, and primitive match.
The initial guarded checkpoint is `4deb84a49c5d332b741b1569e5c62933b096dff5`.

## Source and contract evidence

The target's incoming level and `002ba080`'s row selector are separate
contracts. The target stores the level with `sh` into SP+0xfe and consumes
it with one `lh`; all 23 direct retail callers were enumerated. Its coherent
formal is now `s16` in the definition and both owner declarations.

The digit provider's prior word-row rationale was explicitly reviewed. At
`002ba0b4`, retail saves incoming A1 in S7. The first semantic use at
`002ba170` takes its signed low halfword; the original value is then replaced
by the derived next index at `002ba188/18c`. No incoming high bits are used.
The only direct calls are `0031aa8c` and `0031b9b0`, and no initialized-data
pointer to the entry was found. This supports a coherent `s16` row in both
the actual provider definition and `fcl_draw_task.h`. It does not establish
an original source typedef or exclude every synthesized indirect pointer.
The already-canonical signed-halfword value and aggregate/integer/float
argument order are unchanged. Native controlled boundaries use the same
signature. The complete forced-C provider object is byte-identical across
the change; the provider itself remains guarded and nonmatching.

The remaining six target words were scheduling of the real signed delay.
The persona lookup scalar is dead after the final name-resource lookup,
never address-taken, and never read later as an ID. Assigning `persona =
delay` at that phase boundary and passing it to the digit call describes
retail's S7 reuse. There is no dummy value, added branch, storage inflation,
or changed provider evaluation order. The scoped `opt_lifetimes on` keeps
the real disjoint transition-scale lifetimes from the retained source.

Availability retains the original signed byte-offset lookup:
`base + selectedRow * 12 + rowIndex + 0x14`. The earlier rank16 two-dimensional
array view would incorrectly restrict a caller supplied with valid larger
backing. The existing coordinate fixture returns an interior pointer into
0x1000 bytes, tests all signed rows and groups -128/-1/0/1/127, and remains
unchanged in domain. These are valid fixture inputs, not a claim that every
pair occurs in retail or that the real getter allocates that extent. The
actual function still requires the selected byte and all accessed task,
work, sprite, and provider objects to exist.

## Measurements and native checks

The final guarded target emits 5,788 executable bytes in its 5,792-byte
retail window: zero differing non-relocation words and four authentic zero
alignment bytes. The frozen owner object is subject to the independent
all-reference audit before promotion. Earlier scores were 14 aligned edits
for rank16, 11 after the row contract, and six instruction words after the
combined contracts. Captured delay/register hints were neutral; a late row
assignment and helper/aggregate variants changed actual scheduling and were
not installed.

The three directly affected production objects and the entire forced-C
digit-provider object remain byte-identical to their prior contexts. The five
additional owners that include the shared header also preserve their entire
production ELF objects byte-for-byte.
Ordinary production-C promotion and full repository/build gates are separate
from this guarded checkpoint; this report does not award MATCH credit to a
fallback assembly branch.

Native checks execute the actual target, native point/color constructors,
and controlled trace/backing-object providers at O0 and O2:

- 1,620 transition/trace scenarios per level, checking all backing bytes,
  signed arguments, row exclusions, resources, alpha and opaque-call reloads
- 115,200 coordinate scenarios per level, preserving the published row-Y
  regression coverage and its signed larger-backing availability domain
- 23 O2 row-behavior controls, including stale persona as delay, incorrectly
  zero-extended delay, and overwriting the lookup ID before its real use
- Five O2 coordinate controls retain name, digit, decoration and hand offsets

The controller fixture does not execute the digit provider or every opaque
provider. Their ABI/dataflow evidence and preserved machine objects are
separate checks; algebraic low16 transport checks are not arbitrary
out-of-range executions of the digit provider.

## Portable replay

Use the documented pinned toolchain and authorized retail input. No retained
archive or historical Git read is required by the new tests or final source.
The historical checkpoint hashes above are provenance only.

```sh
python tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_0031ac10
python tools/verify.py --json fcl-owners.json \
  src/Event/Fcl/y_fclCombine.c src/Event/Fcl/y_fclCombineDraw.c \
  src/Event/Fcl/y_fclShopDraw.c src/promoted/code1_002b.c \
  src/promoted/code1_002e.c src/promoted/y_CmbCardEff.c \
  src/promoted/y_draw.c src/promoted/y_fclCmbBall.c
python -m unittest discover -s tests -p 'test_fcl*'
```

A host unable to execute native i386 binaries must use its external native32
runner/adapter without changing tests or allowing extra skips. Full
`tools/verify.py`, the ordinary suite, and `make build-progress` remain the
promotion/publication gates, including both retail hashes and C-link ownership.
