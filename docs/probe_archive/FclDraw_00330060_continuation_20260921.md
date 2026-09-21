# FCL row-selection recovery: func_00330060

The C implementation updates the selected row and visible row range, restores
the affected colors, places the six visible resources, and moves the two scroll
indicators. The six input modes come from the existing calls in
`src/Event/Fcl/y_fclCombine.c`. Its definition uses the same `s32` mode contract
as those callers; the dispatch narrows that value to `s8`, as retail does.

## Source and compiler context

The integration proposal starts from the publication checkout after its rebase
onto `7d8aaca`. In particular, the existing `func_002e90d0` float-literal and loop
changes in the combine owner are retained. Neither owner is reconstructed from
an older source snapshot.

The row-renderer implementation was recovered in the earlier
`build/first-party-finish-20260920/fcl-current-work/worker3-20260921/delivery-00330060`
package. Its source, compiler binary, object, transitive-header and proof hashes
were audited before reuse. New whole-owner objects cover the changed publication
combine source and the final UTF-8 draw proposal. Compiler selection remains tied
to the original logical owner through `probe_variants._compile_in_context`:
MWCC PS2 3.0.1b210, with the owner's configured `-O2` flags.

Current, immutable evidence is under:

```
build/continuation-20260921/fcl-worker3/
  inputs/
  proposal-utf8/
  integration-manifest-utf8.json
  source-closure-audit.json
  func_00330060-exact.c
  proof-00330060/closure-proof-utf8.json
  proof-00330060/{draw,combine,provider}/proof-utf8.json
  proof-00330060/{draw,combine,provider}/after-utf8/receipt.json
```

The manifests record original source bytes separately from normalized patch
text, along with the selected compiler binary, flags, and transitive headers.
Historical source/proof artifacts remain intact.

## Matching changes

Six native four-byte color values replace the artificial frame array and
individual scratch bytes. Their copies reproduce the byte-load/store batches.
The initial paired resource color copy reads from the first lookup's result;
it does not repeat the lookup. The visible-row loop retains its signed-short
row/column values and the resource offset before the placement and color calls.
The two final float updates preserve their original evaluation order.

The placement function has one coherent source contract across its declaration,
provider, and callers:

```c
void func_002b6c30(s64 resource, FclVec2 position, f32 depth, s32 order);
```

All 149 occurrences in the draw owner and 18 occurrences in the combine owner
use that argument order, including guarded drafts. Its provider in `y_draw.c`
uses the same order. This source ordering leaves the EE argument registers
unchanged: the resource, position and order occupy the integer argument bank,
and depth occupies the float argument bank. The compiled provider object is
identical before and after the change.

The source audit records every expression at the 148 unchanged draw call sites
and 18 combine call sites: only the third/fourth argument positions change.
After undoing that permutation, all C tokens outside the recovered function,
the four corrected navigation declarations, and the reviewed `0032c0c0`
adjustment are identical. The recovered function's one placement call is
covered by its complete code-and-table proof.

The draw owner's navigation declarations are also brought into agreement with
the existing `code1_002b.c` providers: `func_002b2d00` returns `s32`,
`func_002b2d50` accepts signed-short values, and `func_002b2e70` and
`func_002b2f90` accept signed-word inputs with signed-short output pointers.
The existing `func_0032c0c0` uses a native short row count and preserves the
lookup/evaluation order under those declarations. Its generated code and
relocations remain identical.

## Exactness evidence

`func_00330060` reproduces all **1,872 code bytes**, with **42 code relocations**
resolved to retail addresses and no suffix bytes. Its six-entry switch table
contains **24 bytes**, with all **six R_MIPS_32 entries** resolved to the
function's retail labels. The table is located at retail address `0x00749660`.

| Artifact | SHA-256 |
| --- | --- |
| Resolved function code | `a67f7c017ed0b8e41f8aff2e75d174906e787de13f6cf16edd67a1f5608da2cb` |
| Resolved switch table | `cff3941296b4c434de92722f38469515954f9013369f4dd99c7ad7f2fabb68ae` |
| Raw owned switch table | `b0bfdfe6df9ec21288a397b9f9133325edd926eee9fabafdcb1d5cce374b7cf4` |
| Draw owner after recovery | `ef76aa86eb79a829505b6e730f9e5854c3efdb484fbb3c37ba6f6aa7bda09637` |
| Combine owner, before and after | `497e56296538dc001202b1c19c5e59bca00e007663436b17840d0c63dd0d9d7e` |
| Placement provider owner, before and after | `6db4ff010909787bb81e9cbcf0fea70f14e63008b55a716d99a60fb49afb8313` |

The proof resolves code and owned data; it does not rely on a relocated-immediate
mask alone. It compares all other function bytes and canonical relocations, and
all unrelated allocated data. It preserves **69 neighboring draw functions**,
**41 combine functions**, and **58 provider-owner functions**. The new switch
table is the only added allocated data.

Additional complete relocation proofs cover the existing draw recoveries
`0032c0c0`, `0032fbc0`, `0031d630`, `0031ddf0`, `0031e320`, `00316470`,
`003297f0`, `0032a960`, `0032b000`, `0032f4d0`, `003233d0`, and `00324410`,
and the placement provider `002b6c30`.

Official verification of the recorded whole-owner objects gives:

| Owner | Before | After |
| --- | --- | --- |
| `y_fclCombineDraw.c` | 46 MATCH / 24 ASM | 47 MATCH / 23 ASM |
| `y_fclCombine.c` | 26 MATCH / 15 ASM | 26 MATCH / 15 ASM |
| `y_draw.c` | 54 MATCH / 4 ASM | 54 MATCH / 4 ASM |

Those scores describe the verified proposal objects. Publication-wide
verification and the actual integrated-source seal remain recorded separately
by the integration owner.
