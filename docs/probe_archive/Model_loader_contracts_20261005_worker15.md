# Model loader contract recovery — 2026-10-05, worker 15

`func_0047b0c0` in `src/Graphics/Model/mdlManager.c` now contains a complete typed
recovery behind its existing `NON_MATCHING` guard. The default branch still uses
retail assembly. **This change adds no exact C match.** The actual production
owner remains **123 MATCH / 3 ASM**, and its complete object is byte-identical to
the baseline object. The repository's `tools/verify.py` also reports
**123 MATCH / 3 ASM** when run on the actual installed owner alone.

The associated [machine-readable receipt](Model_loader_contracts_20261005_worker15.json)
records every production code relocation, every owned data relocation, all 126
function hashes and statuses, the actual data plan, native layout checks, and the
forced-C residual. Private candidates, compiler output, resolved disassemblies,
and proof scripts are retained under `build/resume-model-loader-worker15/`.

## Recovered contracts

The prior guarded implementation supplied an eight-byte fragment to
`func_003df3c0`. Its provider,
[`RwStreamReadChunkHeaderInfo`](../../src/renderware/plcore/babinary.c), writes the
complete twenty-byte `RwChunkHeaderInfo` and returns a stream pointer. The new
body owns all five words: type, length, version, build number, and complexity.
It also owns the complete twenty-byte effect header and eight-byte memory-stream
descriptor. These are independent objects, not aliases into adjacent locals.

Both deferred type-7 requests now pass `D_0070B610` as argument nine to
`func_004667d0`. The provider in
[`code1_0046.c`](../../src/promoted/code1_0046.c) stores that argument in the
request's `+0x20` field. The kind-7 consumer `func_00466e80` in
[`sdkWrap.c`](../../src/promoted/sdkWrap.c) passes that field to `func_003d6350`
as its schema. The old guarded calls passed zero. Each memory stream is opened
over the remaining input bytes using one captured stream cursor, and the
existing completion path retains ownership of the deferred streams.

The clone calls now receive the selected wrapper from the attachment table's
primary `+0x14` or secondary `+0x20` pointer array. Their providers are
`func_0047d200` and `func_0047dc30` in
[`mdlEffect.c`](../../src/Graphics/Model/mdlEffect.c). The source and destination
indices remain live across the clone calls, and the destination array is loaded
again after each call. The matrix copy is a complete `RwMatrix` assignment.

The loader state is a real `0x48` object, as allocated by `func_0047af60`. The
deferred material node is `0x10` bytes. The material table has an **eight-byte**
header followed by eight-byte entries; the UV table has a **sixteen-byte**
header followed by eight-byte entries. The existing donor-derived
`MdlAnimEntryTable` declaration is sixteen bytes and therefore is not used to
size this loader's eight-byte material header. The matrix resource consists of
`0x50`-byte entries followed by its eight-byte table footer.

Attachment allocation reuses `mdl_clone_attachment_storage`, which allocates
the genuine `0x34` header and two independently sized pointer arrays. Primary
and secondary effect handlers capture the complete payload pointer before
allocation callbacks. Allocation counts and byte sizes have local lifetimes;
the recovery removes the old dispatch-wide cache of unrelated temporary values.
The texture callback receives the address of the list head at state `+0x34`, as
required by `func_00463100` in
[`k_clump.c`](../../src/Kosaka/k_clump/k_clump.c).

## Native measurements

All measurements below compile the complete owner using its configured native
MWCCPS2 3.0.1 build 210 compiler and flags. The final installed check compiled
`src/Graphics/Model/mdlManager.c` itself, not an extracted function.

| Source | Owner status | Loader bytes / window | Frame | Resolved differing words | Alignment edits |
| --- | --- | --- | --- | --- | --- |
| Baseline production | 123 MATCH / 3 ASM | 5536 / 5536 | `0xd0` | 0 | 0 |
| Final forced C | 123 MATCH / 2 ASM / 1 NONMATCHING | 5540 / 5536 | `0xd0` | 1283 | 389 |
| Installed guarded production | 123 MATCH / 3 ASM | 5536 / 5536 | `0xd0` | 0 | 0 |

The forced candidate uses the same six saved registers and stack-frame size as
retail. Its actual header, effect, descriptor, metadata and halfword input homes
also occupy the retail positions. It remains **four bytes over the full retail
window**, fails text placement with `Invalid or overlong function window`, and
has nonzero instruction differences. The alignment metric is diagnostic only;
it does not replace resolved byte equality or imply an almost exact match.

The remaining differences include saved-register allocation, common-expression
lifetimes in the counters, the last dispatch branch, and handler instruction
ordering. Explicit callback-result sequencing compiles identically to the typed
candidate. Propagation, common-subexpression, and loop-invariant pragma
hypotheses produced larger frames or overlong code and were rejected. No
nonbaseline pragma, fabricated padding, register-keeping code, or ordinary
instruction assembly was installed.

The earlier complete-object audit is retained in
[Model_manager_remaining_native_20260922_worker2.md](Model_manager_remaining_native_20260922_worker2.md).
Its best frame was `0xe0`; the new handler-local lifetimes recover `0xd0`.
The local P3 donor is also nonmatching and has an incomplete chunk header; it is
not used as proof. The separate `func_00475cd0` uninitialized-local floor was
not revisited.

## Complete relocation and placement proof

`proof.py` resolves actual MIPS call, HI16/LO16, GP-relative, and owned-data
relocations before comparing bytes. It does not replace relocation fields with
zero. Owned-data bases are inferred only from exact sibling functions and then
checked against every actual data byte. The inexact C target is excluded as a
placement witness.

The installed owner has **1,047 resolved code relocations and seven resolved
data relocations**. Every function's resolved bytes and zero-only alignment tail
are checked. All 125 siblings preserve raw bytes, resolved bytes, canonical
relocation bindings, size, and status. The complete guarded object also has the
same SHA-256 as the baseline object.

| Owned section | Retail address | Size | Data relocations | Result |
| --- | --- | --- | --- | --- |
| `.rodata` | `0x007567e0` | 28 bytes | 7 | Exact and preserved |
| `.data` | `0x00713160` | 18 bytes | 0 | Exact and preserved |
| `.lit4` | `0x00761134` | 4 bytes | 0 | Exact and preserved |

There are **three** allocated data sections in this owner. An early progress
message repeated the historical archive's two-section count; the current
object's enumeration and this receipt supersede that statement.

The configured data planner, whole-object placement validator, and text layout
check all pass for the installed guarded source. A private native compilation
also checks 29 `sizeof` and `offsetof` assertions against the recovered layouts;
those assertions produce an object identical to the ordinary forced-C object.
Negative controls change one call binding and one owned-data binding by four
bytes; both changes are detected by the actual resolved-byte comparisons.

Scoped `decomp_lint.py` reports zero errors. Its 19 warnings are outside the
recovered target: ten existing pragma advisories and nine existing declaration
advisories. `git diff --check` passes for the source. This worker did not run a
full game build or runtime test; prime owns final global validation.

## Source-bound receipt

| Artifact | SHA-256 |
| --- | --- |
| Original owner | `5ad972554f5af6bb80091f463f9c0ba57d20e097932babb128cb48cee2880439` |
| Installed guarded owner | `2e110bfb44268f928c6309df6078e7ffddb3e6810e1112e1118a7e9a15e5b5aa` |
| Baseline and installed whole object | `c359d4c6b3ca2adc71f141ece18b830b0f24b0d9a6ca63eec7110b5059187253` |
| Final forced-C whole source | `3c7d6535eb240829d8be9034d4fc207894856024e76832269cff05425de4bfba` |
| Final forced-C whole object | `f083b61b6fe5632dd81b4c52cd2defe06a912c43214334d15fbeb4a48bf040d2` |

The original source prefix before this target's recovery note and the suffix
after its complete guard are preserved. The obsolete comments were replaced
with the current contract explanation and this receipt reference. No other
production owner, shared configuration, progress count, or git state was edited
by this worker.

The private proof can be re-run against the retained source-bound objects with:

```powershell
build/venv/Scripts/python.exe build/resume-model-loader-worker15/proof.py baseline final-forced installed
build/venv/Scripts/python.exe tools/verify.py src/Graphics/Model/mdlManager.c
build/venv/Scripts/python.exe tools/decomp_lint.py src/Graphics/Model/mdlManager.c
```

`install.py` is a one-time guarded installation script with an original-source
hash precondition; do not replay it after installation. The exact-C task remains
open at `func_0047b0c0`.
