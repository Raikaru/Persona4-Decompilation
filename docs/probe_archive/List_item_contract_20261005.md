# List item builders and shared contracts, 2026-10-05

Base commit: `a1cede7894141323ec6bb833af87a776aa19cc60`.

`src/Yajima/y_list.c` now implements `func_002e2a10` and `func_002e3560`
as ordinary C. The work allocation contains paired signed-halfword item IDs
and quantities; direct access to the ID field during compaction preserves
the retail reloads. Separate scan counters and the scoped common-subexpression
and loop-invariant settings preserve each phase's actual lifetimes.

| Target | Native C bytes | Retail window | Zero alignment tail |
| --- | ---: | ---: | ---: |
| `002e2a10` | 2888 | 2896 | 8 |
| `002e3560` | 2864 | 2864 | 0 |

The initial exact candidates depended on incompatible provider declarations.
The accepted repair uses `include/list_item_internal.h` throughout the caller
chain: signed-halfword IDs for inventory writes, category/bank metadata,
item predicates and labels; a signed-word flag index and unsigned-byte flag
value; explicit item/index arguments and predicate returns; and `const void *`
sorting callbacks with the SDK `qsort` declaration. Narrowing only the category
provider regressed inventory and label callers. Correcting their complete
contracts together preserves all provider code. Redundant promoted inventory
aliases were removed. The remaining flag scan uses a signed-halfword counter,
ordinary increment and signed-word result, retaining its retail instructions.

Actual native verification covers **19 owners, 1205 functions: 1196 MATCH and
9 retained ASM fallbacks**, adding two C matches. The combined list owner
preserves **35 siblings**, resolves **368 code relocations and 306 table
entries**, and retains its four-byte active-list pointer at `0076467c`.
Complete owner checks resolve **17007 code relocations and 855 data relocations
across 101 owned sections**, comparing every instruction and owned-data byte
without relocation masking. All permitted tails are zero.

All six affected `NON_MATCHING` builds compile. Scoped lint has zero integrity
errors; its 46 pragma and 254 unrelated declaration advisories remain. The
global inventory covers 18 repaired interfaces in 22 source/header files and
has no declaration inconsistency for those interfaces. Prime applied the
`code1_0026` header update; that owner's native object remains byte-identical.
The scratch `g_data` data discrepancy was its randomized `__FILE__` name;
stable-filename and actual-owner builds prove its code and owned data.

`List_item_contract_20261005_receipt.json` records source/compiler/object hashes,
every function's resolved hash and relocation-evidence fingerprint, complete
target relocation records, owned-storage records, caller inventory and guarded
checks. The adjacent replay script is independent of disposable `build` probes.
Run from the repository root with its configured native compiler and retail input:

```powershell
build/venv/Scripts/python.exe docs/probe_archive/List_item_contract_20261005_replay.py --hashes-only
build/venv/Scripts/python.exe docs/probe_archive/List_item_contract_20261005_replay.py
build/venv/Scripts/python.exe tools/decomp_lint.py src/Yajima/y_list.c include/list_item_internal.h
```

`--owners src/Yajima/y_list.c` limits native replay to that owner.
`--allow-source-drift` explicitly permits checking a later tree; changed input
hashes are recorded. Fresh objects and proofs go to `build/list-item-contract-replay`.
These are scoped object checks, not full-link or semantic-execution claims.
Prime owns final image/link verification. `func_002e5ae0` remains ASM at this
accepted snapshot; subsequent range-builder work must preserve the accepted pair.
