# Font loader pointer contract

Base: `b690bb2cf0afdae66301fa6422f6997c4715a91f`, the published-main lineage.
This is a narrowly scoped source-ABI repair. It imports no guarded controller,
research header or function body from the rank5 rewrite.

## Actual contract

The real `func_002716b0(s32, u8 *, u8 *)` dereferences a primary resource pointer,
falling back to the secondary resource if the primary is NULL. Its two wrappers
previously called `func_002716b0_typed(s32, u64, u8 *)`, a name supplied only by
an address-map alias at the real loader's address. That different prototype was
not an independent wide-value provider.

Both wrappers now call the actual pointer loader. `func_002738a0` has a resource
pointer parameter, and all four message callers explicitly convert their stored
32-bit address words at this boundary. The only other wrapper declaration,
in `ed_res.c`, now agrees with `func_00271380`'s existing `u8 *` parameter; its
`void *` allocation result converts normally to that pointer in C.

The manager's flag query declaration now matches the unchanged real
`func_00274650(u32)` provider's unsigned result and argument. Its four existing
queries retain their values and generated code. No caller-only alternative
prototype, new alias, extra ABI argument or assembly is introduced.

The old, now-unused symbol-map alias is deliberately left untouched. No
authoritative C reference or wide prototype remains; keeping this inert address
name avoids unrelated symbol-map changes. The native fixture links the actual
loader definition, not a replacement alias.

A direct experiment widening message callers to the old `u64` selector shape
was rejected: it added sign-extension instructions to four matched callers.
The accepted repair follows the loader's actual pointer contract instead.

## Whole-owner preservation

The production patch changes only four source files, by 12 insertions and
12 deletions:

- `src/frFont.c`: real loader prototype/calls and pointer selector definition
- `src/itfMesManager.c`: coherent selector/flag declarations and three explicit
  stored-address conversions
- `src/promoted/code1_0027.c`: the fourth selector declaration/conversion
- `src/Main/OpEd/ed_res.c`: the remaining fallback-wrapper declaration

Independent native b210 whole-owner comparison preserves **all 208 functions**
in those owners. Every raw allocated code/data byte, section size/alignment,
function and named allocated definition, marker, and resolved relocation
identity remains equal. There are **1,430 allocated relocations**. Only two raw
reference spellings change, from the old alias to the real loader in the two
wrappers; both resolve to **0x002716B0**. They are not masked or retargeted to a
different address.

The manager, message dispatcher and ending-resource objects are completely
byte-identical. The font object's allocated content is identical; its object
file differs because the unused undefined alias symbol disappears. No entire
font-object identity claim is made.

Official verification passes **209/209 MATCH**, including the unchanged flag
provider in `frFont_grouped.c`. These are existing matches, not new matches.
The four changed owners have no guarded function markers or active assembly
fallbacks. All other source files, headers and build configuration are unchanged.
No full-image/link run is claimed here; aggregate validation belongs to the
parent integration lane.

## Native proof and bounds

The fixture extracts unchanged complete definitions of the actual loader, both
wrappers and flag getter, their actual slot types, and the actual declarations
from every relevant caller owner. No tested body is rewritten in the positive
case. The 32-bit O0/O2 runs use aligned untyped mmap storage for synthetic font
resources and correctly typed global slot objects.

At each level, **4,006 scenarios** pass: 3,936 loader/wrapper cases and 70 flag
cases. They cover all nine valid low-byte slots, high slot-word prefixes, primary
and fallback resources, secondary pointers, four bounded layouts, four table
counts, and diagnostic-boundary mutations. The real loader must reread the live
count/resource slot after that boundary, while keeping its original base and
computed tail. Stored-word-to-pointer conversion is exercised through the real
selector. Other slots and allocation fields remain untouched.

All **12 independent body mutations** fail at both levels, covering wrapper
slots/order, fallback behavior, slot masking, header strides/counts, final table
stride, stale count use and flag masking. Four additional declaration controls
must fail compilation: the old signed flag API, old wide selector, old word
selector, and old `void *` fallback declaration. The authoritative-source census
also rejects any surviving C use of the wide alias.

The four test methods pass without skips. These tests execute actual C bodies,
not PS2 instructions. Diagnostic functions are checked boundaries, not claimed
recovered implementations. Resources have adequate storage, aligned fields and
valid slot/header ranges; malformed files, allocation failure and gameplay asset
reachability are not established. The full outer message/ending procedures are
covered by exact whole-owner preservation, not claimed native path execution.

## Deliberately separate gates

The 32-slot restore helper is unchanged. Its cells are pointer-valued and its
writers/readers need a separate coherent model; simply giving its old address
argument a new pointer prototype would not settle those object accesses.
The rank5 controller remains guarded, and its zero-choice domain and remaining
snapshot/alpha lifetime issues are not changed by this repair.

```sh
python tools/verify.py src/itfMesManager.c src/promoted/code1_0027.c src/frFont.c src/frFont_grouped.c src/Main/OpEd/ed_res.c
python /workspace/shared/run_p4_qemu32_tests.py "$PWD" test_fr_font_loader_contracts
```

The adjacent JSON binds exact source/object identities, the two alias-reference
changes, native body/fixture/test hashes and independent preservation results.

Independent reproducible whole-owner review is retained at
`/workspace/shared/p4-font-loader-independent-review.py` (SHA-256
`4f5c1ca98f3902584870c64df56d451091c39de19749182e5e532605e556ff72`).
Its report is `/workspace/shared/p4-font-loader-independent-review/receipt.json`
(SHA-256 `a48fe2a538eef7546994b6c97a9fd729b7268e0c941acc326d1b6c10e452cd58`).
These are inspection artifacts, not private compiler or retail payloads.

## Main integration validation

The same four reviewed source files were applied unchanged to published main
`b1f024ba5e0f6c1b525a6ecb83bbb7d2ee1808cf`. Its intervening primitive-work
repair remains present and unchanged. The full integration build passes both
retail hashes with 604 C objects, 54 SDK objects and all 8,586 linked windows;
the complete linked report is identical to that main baseline.

The focused integration rerun passes all four methods without skips. The
ordinary suite reports 869 tests with 35 capability skips and no failures.
Changed-file lint reports zero errors and 54 existing warnings. This remains
a source-contract repair with no new matching function claimed.
