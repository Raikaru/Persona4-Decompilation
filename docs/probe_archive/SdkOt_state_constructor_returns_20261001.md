# Canonical SDK ordering-table constructor returns

Exact main base: `61b8a7526e6ebc2f2a012a707f678d25a8a04d17`.

Both `func_00460b60` and `func_00460c70` return the allocated queue node as
`u8 *`. Their provider definitions already express that contract; the Window
owner instead declared void returns and a void-pointer list argument. A shared
header now carries the actual provider signatures across their complete
authoritative C declaration/caller set.

## Minimal source delta

- Add `include/sdk_ot_state_api.h`
- Include it in `src/sdkOt.c`
- Include it in `src/promoted/itfMsgProcedure_Window.c` and remove the two
  conflicting declarations
- Include it in `src/promoted/code1_0010.c` and remove two redundant b60
  declarations, one file-scope and one block-scope

There are twenty call sites, all discarded-result calls in matched functions:
10 in `func_0027d660`, eight in `func_00103b00`, and two in `func_00103f00`.
No executable statement, provider definition, guard, renderer declaration,
rectangle/color object, data definition or function marker is changed.
In particular this patch does not import the research controller, the RGBA
helper repair, `primitive_rectangle.h`, or a wider rectangle/callback ABI.

Removing the three added includes and restoring the four deleted declarations
reconstructs each original source byte-for-byte. The header equals the already
reviewed research header, but all preservation claims here use this exact main
base and its actual owner source hashes.

## Binary preservation

Production and all-guard builds preserve all 69 functions across the three
owners. Each of the six complete candidate objects is byte-identical to its
baseline object. Separate checks cover allocated code/data/padding, section
sizes/alignment, symbol definitions, raw relocation addends and symbolic
identities. The unchanged assembly symbol `D_938A00` is preserved symbolically;
this is not a claim to resolve every linked address.

The two providers are additionally resolved directly against retail: each
matches all 67 instructions and ten references, including its genuine node
return. Production remains 64 MATCH / 5 ASM. Lint has zero errors and 46
remaining unrelated warnings. No matching-count gain is claimed.

## Native proof

The fixture extracts both unchanged actual constructor bodies and the real
shared header. At each O0/O2 it executes 392 scenarios covering empty/nonempty
queues, one/ten-node alternating constructor chains, and signed-word boundary
state/value inputs. Mmap provides storage without a declared C object type.
An independent byte/link oracle checks complete zeroed records, command tags,
full-width state/value words, returned node addresses, queue linkage/tail and
allocation guard bytes.

Ten defined runtime mutations and two void-return declaration compile controls
are rejected at both optimization levels. Four methods pass without skips.
Caller bodies and rendering are not executed by this fixture; caller ABI scope
is instead established from their actual declarations, discarded-result calls,
retail provider return behavior and complete-object byte preservation.

The authoritative-source census excludes generated drafts and dot-prefixed
compiler scratch files. Direct assertions check both exclusions, preventing a
concurrent baseline compiler probe from being mistaken for a new C owner.

Full-link/retail-image validation and the ordinary whole-repository suite are
separate integration gates. This source-correctness change does not close the
renderer effective-type debt, generic callback arity, or guarded rank-5 domain
and matching gaps.

```sh
python /workspace/shared/p4-ot-main-preservation.py --repo . --base 61b8a7526e6ebc2f2a012a707f678d25a8a04d17 --output build/sdk-ot-projection/preservation
python tools/verify.py src/sdkOt.c src/promoted/itfMsgProcedure_Window.c src/promoted/code1_0010.c
python /workspace/shared/run_p4_qemu32_tests.py . test_sdk_ot_state_contract
```

Independent audit: `/workspace/shared/p4-main-ot-independent-review.py`
(SHA-256 `273387d3e08d70599de5ca73d8da2ed424a298e8bdb87b9f4b95dffb2e2286d5`).
Receipt: `/workspace/shared/p4-main-ot-independent-review.json`
(SHA-256 `267ba568547fa7e578b74b3675173bf6b4e3648332e1a2d0780a2f3f1c86281e`).
The receipt distinguishes the independent four-method native run from the
final census-only rerun after adding explicit scratch-exclusion assertions;
all source/header/fixture and generated runtime C remained unchanged. The
final local four-method run also passes. The adjacent JSON binds all six
source/header/test hashes and exact object/reference proof scopes.

## Main integration validation

The exact reviewed source/header/test files were integrated on
`61b8a7526e6ebc2f2a012a707f678d25a8a04d17`. The full build passes both retail
hashes with 604 C objects and 54 SDK objects. All 8,586 linked windows and the
complete linked report are identical to that baseline. Four focused methods
pass without skips. The ordinary suite reports 869 tests with 36 capability
skips and no failures; changed-file lint has zero errors and 46 existing warnings.
No guarded body, rectangle API or matching count changes.
