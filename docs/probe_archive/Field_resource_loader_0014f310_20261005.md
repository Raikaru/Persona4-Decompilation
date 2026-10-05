# Field-resource loader: guarded source recovery, 2026-10-05

`func_0014f310` remains an assembly fallback. The installed guarded C repairs
resource-ID stores, local provider contracts, camera output objects and state
dispatch. The actual default owner still has **20 MATCH / 1 ASM**, and its
entire native object is byte-identical to the completed property-result
integration. This continuation adds **zero recovered functions**.

The durable receipt is
`Field_resource_loader_0014f310_20261005_receipt.json`. Reproducible scripts,
original/proposed sources, native objects, compiler logs and unsuccessful
measurements are retained under `build/resume-field-worker12/`.

## Source repairs and measured result

Both resource-publication loops now write complete `s32` identifiers to
`D_007E8060`, as the retail stores at `0014fc84` and `0014fd6c` do. The old
guard wrote one byte. Unknown states return zero explicitly. The loader's
linear state dispatch preserves handler order, fallthrough and the successful
completion path, and eliminates the unnecessary compiler-generated dispatch
table.

The camera outputs are complete objects: two 64-byte matrices with the real
RenderWare vector/flags/padding layout, one position vector, 32 signed-byte
entries and 32 position vectors. These typed objects produce exactly the same
native object as the preceding raw-buffer candidate. Scalar names retain their
known file offsets rather than assigning unproved near/far semantics.

Local declarations and calls now agree with the reviewed providers:
`00149ea0` takes no arguments; `00146440` receives its real scalar, vector and
matrix arguments in order; `0015e960` and `0015f9b0` receive complete pointer
outputs; `0015c800`, `0015cd70` and `mdlGetClump` use the actual pointer
contracts. The frame accessor is
`func_003e9700`, using the owner's existing `RwFrame *` declaration.

The strict proof found six invalid GP-relative accesses already present in
the old guard. `D_007D24E0` and `D_007D24E8` lie outside the signed 16-bit
small-data range: their displacements were 431088 and 431096. Explicit
array-element views of those existing file-handle words produce the retail
absolute address sequences, without a header, provider or symbol-map change.

| Whole-owner candidate | Code bytes / 5504-byte retail window | Aligned edits |
| --- | ---: | ---: |
| Original installed guard | 5392 | 574 |
| Word stores and defined default return | 5404 | 563 |
| Reviewed local provider contracts | 5404 | 559 |
| Linear state dispatch | 5492 | 528 |
| Complete camera objects | 5492 | 528 |
| Correct absolute file-handle addresses, installed | 5516 | 513 |

The final guard remains **12 bytes over the retail window**, with 969 masked
differing words and **1063 differing words after all 252 code relocations
are resolved**. The aligned score is a diagnostic, not an exact-match claim.
Its direct-call inventory is unchanged. Every one of the twenty guarded
siblings retains its original raw instructions and relocation records.

The installed guard owns no allocated non-code data. The prior guard's
44-byte dispatch table is removed with its dispatch path. The default owner
also owns no allocated non-code data. All 21 default functions, including
the assembly fallback, resolve exactly to retail with **655 code
relocations** checked. No full-tree build or linked-image claim is made here.

## Camera output lifetime limits

A present camera member with version at least `0x10002` writes both matrices
and every scalar/vector/table output. Two other real provider paths require
further caller or asset evidence before ordinary C promotion:

* With a nonzero bundle handle, camera start returns sentinel one. A missing
  member makes `func_00154be0` return one at `00154cc8` without writing any
  outputs. The loader tests only for return zero before reading the kind and
  field-of-view outputs and calling `00146440`.
* The legacy member path writes the secondary matrix's vectors, then reads
  its previous flags at `00154e54`, before the first flag store at `00154e64`.
  The caller has not initialized that matrix or its SDK padding words.

The matrices occupy caller stack ranges `0x200..0x23f` and `0x240..0x27f`.
Their first argument addresses are constructed at `00150200`/`00150204`.
Earlier escaped stack objects are the four-byte HBN pointer at `0x2ac` and
the twelve-byte Euler vector at `0x290`; neither overlaps a matrix. The
upstream resource constructor initializes heap-backed resources, and does
not initialize these later automatic outputs or establish the missing
member/version preconditions. The receipt records the complete reviewed
provider bodies and retail instruction-byte checks.

This review does not claim shipped assets exercise either problematic path.
It records the precise preconditions still needed. Adding an invented
initialization, member lookup or version guard would change the measured
program and does not establish exact recovery.

## Property-result evidence bridge and final validation

The field owner advances from source SHA256
`b6d23a9d0485a28abf7c3a79e0406ab26a3b0d691aa322765050a40c7990abb2`
to
`5537e14927bca5e6efac08c073871bbccfebd0853d65dfece5dfd08dc7b8ea27`.
Only the loader guard and its explanatory comment change. All eleven
property-result call sites, the shared type, provider/callback and texture
owner remain unchanged. The previous property receipt remains historical;
this receipt bridges its old field-owner hash to the installed source.

The complete default object remains SHA256
`f3cc267a7b3a31340885cb3070e0046ad9290648954bde5b256449ca25a587bf`.
The actual installed-owner verification confirms the pre-install proof
object, while the guarded-source bytes equal the source bound to its
completed native proof. Scoped lint reports **zero errors and eleven
warnings**: nine existing declaration disagreements and two measured pragma
findings. `git diff --check` passes for the field owner.
