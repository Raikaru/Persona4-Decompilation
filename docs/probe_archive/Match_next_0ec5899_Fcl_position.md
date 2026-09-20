# Exact combination-menu positions: func_0032f4d0

Recorded by worker-5 on 2026-09-19 in `build/match-next-latest`, starting at
upstream `0ec589932637d637b451882bfbaa479d5f8043a9`. Prime created the fresh
worktree after fetching upstream; the previous dirty worktree was preserved.
Worker-6 completed the constructor ABI follow-up below on the same date.
The changes below are integrated in the current source, without a commit or
push. This worker ran only the two affected owners' verification and lint;
there is no full-project build or complete-image claim in this record.

## Integrated result

`func_0032f4d0` now reproduces **1368 executable bytes in its 1376-byte retail
window**, including all **22 resolved R_MIPS_26 relocations**, followed by
**eight zero alignment bytes**. This is an ordinary C recovery. The assembly
fallback and NONMATCHING guard for this function were removed.

The existing exact `func_00315310` caller remains **740/752 bytes**, with all
**14 relocations resolved** and twelve zero alignment bytes. All 69 non-target
functions in `y_fclCombineDraw.c` retain their instruction bytes and relocation
destinations. All three allocated data sections retain their contents,
alignment and relocations.

The complete active `y_fclCombine.c` object is byte-identical to its baseline:
all 41 functions and all three allocated data sections are unchanged.
Its three affected C drafts remain guarded, so these active-object comparisons
are separate from the guarded-source checks below.

The official current-source verifier passed:

| Owner | MATCH | ASM | Other statuses |
| --- | ---: | ---: | ---: |
| `src/Event/Fcl/y_fclCombineDraw.c` | 39 | 31 | 0 |
| `src/Event/Fcl/y_fclCombine.c` | 24 | 17 | 0 |
| Total | 63 | 48 | 0 |

`decomp_lint.py` reports two first-party files and zero findings. `git diff
--check` also passes.

## Recovered contract

The incoming position at `func_003147e0` is an eight-byte, naturally
four-byte-aligned struct containing X and Y floats. The retail provider stores
the incoming `$a2` at `0031481C`, then consumes the low float and high float
at `003148E4` and `003148DC`, respectively. There is no scalar integer
calculation on this position.

The shared declaration in `include/fcl_combine_internal.h` is:

```c
void func_002b2970(u8 *out, f32 x, f32 y);

void func_003147e0(u8 *task, s8 slot, FclVec2 position, s16 resource,
                   s32 order, s32 mode);
```

Both owners include this declaration. The actual guarded provider takes
`FclVec2` and reads `arg2.x` and `arg2.y`, replacing its scalar `spE8` snapshot
and pointer reinterpretations. The external owner's previous fifth-formal
`s16` declaration is reconciled to the existing provider's `s32` formal;
all variable fifth arguments retain their explicit signed-short conversion,
and constant arguments retain their values. No actual argument was dropped
or reordered.

The local constructor output in `00315310` and the external constructors use
`FclPackedPosition`, a union of the actual vector and its eight-byte packet
view. This preserves the existing local storage and alignment while exposing
the position as a typed value. Constructor destinations use the active
provider's `u8 *` interface. The new target needs only plain
`FclVec2` locals and a six-element `FclVec2` array; its obsolete scalar-position
union was removed. The color unions and ID-store helper from the upstream
floor are retained.

The critical call in `0032f4d0` passes `tbl[n]` by value. With the real aggregate
formal, MWCC emits the retail `ldr $a2,0x50($a3)` / `ldl $a2,0x57($a3)` pair.
With the previous scalar formal it emitted one `ld`. The recovered aggregate
also fixes the affected address register and branch displacements. No
instruction padding, volatile accesses, assembly, extra state, or new
optimization pragma was used.

The nested flag decisions, arithmetic and call order are unchanged. The array
has room for all six rows. Its last element also serves as the last constructor
output, then is copied to the current active slot. The signed count is reread
after each constructor and during the drawing loop, preserving the existing
alias-visible ordering. The selected-row lookup precedes its three color
constructors, and the second descriptor's color still comes from the first
descriptor after the second lookup.

## All caller sites

The retail, IDA and Ghidra references for the target and provider were read in
full. All current caller bodies and both decompilers' external caller bodies
were inspected, together with the retail argument-setup windows at every
external call. The canonical contract covers two owner-local calls and all
15 real external source calls:

| Caller | Retail call addresses | Position source |
| --- | --- | --- |
| `00315310` | Existing owner-local call | Constructed local position |
| `0032f4d0` | `0032F83C` | Indexed two-float array value |
| `002e90d0` | `002E9CE8`, `002EA00C`, `002EA1C0`, `002EB0C8` | Four constructed local positions |
| `002e90d0` | `002EAC14`, `002EAD1C`, `002EAF6C` | Three descriptor-position snapshots |
| `0030b060` | `0030B190`, `0030B6E4` | Constructed local positions |
| `0030b7b0` | `0030B850`, `0030B8E4`, `0030B980`, `0030BA1C`, `0030BAC8`, `0030C2D8` | Constructed local positions |

The three descriptor paths in the existing guarded `002e90d0` draft had
disconnected scalar copies and read their call argument through stale
`temp_v4`. Retail obtains the descriptor from `002b6150`, copies its floats at
`+0x38/+0x3C`, and supplies that copied position. Those directly exposed paths
now use the actual returned `te` and a typed position snapshot. This is the
only correction beyond the aggregate contract in that state-machine draft.
The other pre-existing nonmatching logic remains guarded.

Separate whole-owner compilations enabled each guarded body before and after
the migration:

| Guarded function | Before bytes | After bytes | Validation |
| --- | ---: | ---: | --- |
| `003147e0` | 1860 | 1860 | All 49 calls retain order; aggregate home and float-local placement change |
| `002e90d0` | 8636 | 8648 | All 264 calls retain order; the three position sources are corrected |
| `0030b060` | 1872 | 1872 | Complete object, function bytes and relocations identical |
| `0030b7b0` | 3076 | 3076 | Complete object, function bytes and relocations identical |

The provider is still a nonmatching draft: its positional residual changes
from 367 to 366 words. Its direct member form is used because it represents
the incoming aggregate without an extra snapshot. A measured union-snapshot
alternative grew it to 1868 bytes and 374 words and was rejected. The guarded
`002e90d0` compiler folds its typed snapshots into aggregate reads from the
current descriptor; it does not yet reproduce retail's stack-copy scheduling.
None of these four guarded drafts is promoted by this change.

## Constructor ABI consistency

The active constructor definition at `src/promoted/code1_002b.c:141` is
`void func_002b2970(u8 *arg0, f32 arg1, f32 arg2)`. It builds a two-float value
and writes it to the supplied buffer. The retail assembly at `002B2984` and
`002B2988` stores X and Y to destination offsets zero and four, respectively.
The shared header now declares that exact pointer and float contract. Both
owners' incompatible local declarations (`void *` and `s64 *`) were removed.

All **677 draw-owner calls and 161 combine-owner calls**, including guarded
drafts, use explicit `(u8 *)` destination casts. The constructor-only transform
checks every underlying buffer-address expression, preserves both float
argument slices exactly, and retains the count and order of all 838 calls.
It changes no destination storage, float expression, or constructor provider.

Before integration, immutable copies of the two current owners, shared header,
recovery note, active constructor source and assembly, active objects, and
four guarded object baselines were saved under
`build/match-next/fcl-constructor/before`. Source hashes were checked against
the accepted preconstructor state. The active object baselines came from
`fcl-contract/current/draw.o` and `combine.o`; guarded baselines came from the
existing `fcl-contract/func_*-after.o` measurements.

Both proposed complete owners passed scratch compilation before their patches
were integrated. Fresh direct compilation of the integrated owners then
produced **byte-identical complete active objects**: all 70 draw functions,
all 41 combine functions, all symbols and relocations, and every allocated
data section are unchanged by this constructor correction. The accepted
target and owner-local exact caller were independently relocated again and
retain their 1368/1376-byte and 740/752-byte proofs above.

Each guarded definition was also enabled separately in its complete owner.
Both proposed and integrated versions reproduce the complete preconstructor
object, with these unchanged function measurements:

| Guarded function | Function bytes | Relocations | Complete object |
| --- | ---: | ---: | --- |
| `003147e0` | 1860 | 49 | Byte-identical |
| `002e90d0` | 8648 | 305 | Byte-identical |
| `0030b060` | 1872 | 60 | Byte-identical |
| `0030b7b0` | 3076 | 118 | Byte-identical |

`build/match-next/fcl-constructor/current-proof.json` records these final
comparisons, source identities, all function and data comparisons, and both
resolved exact functions. `fcl_constructor.py` first checks the old guarded
bodies against their measured proposals, then uses the explicitly checked
constructor-only transform as the new whole-owner reference. The earlier
`fcl_current.py` assertion still describes the preconstructor proposal and is
historical; it must not be rerun against the final sources as though that
reference had been updated.

The owners remain link-ineligible because of their existing unresolved-symbol
and data-placement blockers. Complete object identity introduces no new
blockers. This remains a scoped object and relocation proof, not a successful
link or complete-image proof for this checkout.
Prime's before/after placement reports retain 49 accepted functions of 70 for
draw and 14 of 41 for combine. Both retain `data_ok=false`, `layout_ok=true`,
and zero uncovered text gaps. The unresolved-symbol and data blockers are
identical; the accepted target introduces no unresolved reference or symbol
change. Reports: `build/match-next/fcl-draw-placement.json` and
`build/match-next/fcl-combine-placement.json`.

## Independent relocation and data proof

`build/match-next/fcl-contract/current/proof.json` records the preconstructor
integrated-owner compilations. It compares every non-target function, canonicalizes
anonymous compiler data symbols by their actual section and content, compares
all allocated data sections individually, and applies each target relocation
without masking it. The result equals the retail prefix and has an all-zero
remaining window. The local exact caller is independently relocated as well.

The 22 target relocation offsets below are function-relative. Each resolved
destination is the hexadecimal address encoded in its function name:

| Decimal offsets | Destination |
| --- | --- |
| 108, 224, 356, 504, 628, 748 | `func_002b2970` |
| 276, 408, 1056 | `func_00106330` |
| 876 | `func_003147e0` |
| 924 | `func_0032fb60` |
| 960, 988, 1016, 1092, 1212, 1284 | `func_002b2a60` |
| 1044 | `func_0032fa30` |
| 1104, 1152, 1224, 1296 | `func_002b6150` |

The draw owner's three allocated `.rodata` sections remain 24, 24 and 28 bytes,
each aligned to 16. Their SHA-256 values are, in section order:

```text
84d6b37ed7f55e9666131d62e8477e513a7da1afe7db598bf88691389db0b080
99e399c37cab56adf09fc7c502f12ecde367bbe546e4ad89d6b33f80d618ad2d
b946ae23ffe6d4728fd532c56e042be87f9a3fe8855d1a95fb7453cc9182a241
```

The external owner's allocated sections remain 28, 28 and 64 bytes, each
aligned to 16. The entire object is identical, including their data and
relocations. No new owned data is introduced.

## Reproduction and identities

The already-complete baseline artifacts in `build/match-next/0032f4d0` were
reused; the unavailable anonymous baseline process was not restarted.
The prepared `fcl_position.py` experiment first measured both aggregate-union
and plain-aggregate tables at zero differing words and 1368 bytes. The chosen
plain table reduces unnecessary packet views in the target.

`fcl_contract_probe.py` retains the bounded provider-member experiments.
`fcl_migrate.py` produced the complete owner proposals and separate guarded
compilations. `fcl_verify.py` checked those artifacts. The initial integrated
check was `fcl_current.py`; the final constructor-contract check is
`fcl_constructor.py`. These scratch scripts are under `build/match-next`.
The exact source itself is durable in the two production owners and the
shared header, not only in ignored scratch files. Historical archives and
generated source were preserved.

Before the constructor follow-up, the completed commands were:

```powershell
python tools/verify.py src/Event/Fcl/y_fclCombineDraw.c src/Event/Fcl/y_fclCombine.c --json build/match-next/fcl-contract/scoped-current.json
python build/match-next/fcl_current.py
python tools/decomp_lint.py src/Event/Fcl/y_fclCombineDraw.c src/Event/Fcl/y_fclCombine.c
git diff --check
```

All four exited zero. Existing Python pywin32 startup and MWCIncludes usage
warnings appear in compile logs; the objects and comparisons were produced
successfully. Every worker-owned probe session completed, including the final
batch session 25429. The owners were released to prime for independent checks.

For the constructor follow-up, `fcl_constructor.py snapshot`, `prepare`, and
`proposed` completed before integration. The final `current` action compiled
the actual integrated owners and all four guarded variants; session 78917
finished with exit code zero. All worker-6 compiler sessions ended before the
owners were released to prime. No further source or header changes followed
that release. Prime's final batch 42909 then completed with exit code zero:
the independent target proof again passed at 1368/1376 bytes, 22 resolved
relocations, 69 unchanged siblings and three unchanged data sections; the
official verifier reported 111 functions, 63 MATCH and 48 ASM; lint reported
two files and zero findings; and `git diff --check` passed. The final reports
are `build/match-next/verified/0032f4d0/proof.json` and
`build/match-next/final-verify.json`.

Repeat the final constructor comparison using the preserved baselines:

```powershell
python build/match-next/fcl_constructor.py current
```

The independent target proof can also be reproduced directly:

```powershell
python build/match-next/prove.py src/Event/Fcl/y_fclCombineDraw.c func_0032f4d0 build/match-next/fcl-contract/current/draw.o
```

The `snapshot` and `proposed` actions describe the preintegration state and
are not the commands for checking the already-integrated final owners.
The existing pywin32 startup warning did not prevent any completed proof.

Final SHA-256 identities of the integrated files and proof artifacts:

```text
src/Event/Fcl/y_fclCombineDraw.c
6735e79471600da846fb7f53cb8125b9eb2ed912068ba8d68f9d9d6c61cc5b77
src/Event/Fcl/y_fclCombine.c
dc0d3ccd459bcdfb5a5d382af8b4e8421fd9d4726433fd8612f170d7a2c2ccd4
include/fcl_combine_internal.h
038aff5fd6d0b9fd47e7bbad62a39917a257e47001177ab7d8183f1039f70658
draw complete object, before and after constructor correction
38d7dc0cd581d06a5a80a9b6ba7dbf3a2c5822cf30f55536e92eadb59289b361
combine complete object, before and after
2ff39ce3de134cf6e188bd72c94bdf6038ef9e77464c1cab6cdffbb45a22f41a
guarded 003147e0 complete object, before and after constructor correction
1bd3c5a5a284c780d3825e6bd2d38fd2ac8a23de57c4df1e5f9ca8a651ed0464
guarded 002e90d0 complete object, before and after constructor correction
e8c06ef2084b30974369dc7f531b88ce85673feceea9b9555440dc910369275f
guarded 0030b060 complete object, before and after constructor correction
5e5d13f03c959388852f3a48d8f9a7580029f7c73b72236d56b9816e6267b8d9
guarded 0030b7b0 complete object, before and after constructor correction
e5112ef7ca36d24c3a5beb6156350e16ae6375e968b25ea9054ea8e892583c6c
build/match-next/fcl-constructor/current-proof.json
e9c80e9b55f8769b7e39e63eaf6c0ca2998e660417d6e9c4cbd0a79c855e18de
0032f4d0 raw function
2e44ed42b155cc6ce4571dc0b2e5df575d709e4be25a7c1fc1259b05401dfecf
0032f4d0 fully resolved bytes and retail executable prefix
c6d4fc585d16cf9352d08125ec7ba7b6d4e5e9051dae2a99f367f4253401ad72
00315310 fully resolved bytes and retail executable prefix
1c377ced6173d9f91d9aba01c50f94794b033e3ec0d3b3bb80d715c14ab4d3a4
```
