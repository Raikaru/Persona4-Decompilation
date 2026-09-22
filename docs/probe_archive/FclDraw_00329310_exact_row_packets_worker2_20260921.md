# Fcl row drawing: exact 00329310 recovery

Measured September 21, 2026 by worker-2 against the publication worktree at
`5a1bcf7e889d9b1fb1560201d686669739014501`, including its existing uncommitted
recoveries and motion changes. The ordinary C proposal for `func_00329310`
emits **1,244 exact executable bytes in the 1,248-byte retail window**. All
**28 code relocations** are independently resolved. The final four retail bytes
are zero alignment after the return delay slot. The target introduces no owned
data and has no assembly fallback in the proposed source.

The unapplied integration patch is
`build/resume-completion-20260921/fcl/ready/integration.patch`. It contains the
Draw recovery, coherent declarations in the real Combine and drawing-provider
owners, and one new header, `include/fcl_row_draw.h`. The other headers under
`ready/include/` are frozen dependencies, not proposed changes. This note is
the lane's only authored file outside its scratch directory. The worker did
not change production sources, headers, maps, configuration, tools or tests.

## What closed the match

The saved 003218a0 and 00323d00 frontiers were inspected first. Their archived
provider-contract blockers remained relevant: in particular, the attractive
29-word 00323d00 result did not close the real 002b6a70 contract. The row
function offered a separate concrete lead in its position copy and retained
column values. Retail assembly, the current owner, callers, provider bodies
and prior row experiments were read before changing that candidate.

The initial row candidate already had the correct calls, branch structure,
resource remapping and arithmetic. Five representation and lifetime choices
closed its remaining differences.

First, the draw transition takes native `FclVec2` and four-byte
`FclDrawColor` packets. Using the existing native color type in the shared
002b77d0 contract preserves the late color load in the already recovered
00320970 sibling. A scalar color declaration had moved four loads before
their retail positions. Existing opaque position and color drafts now use
the existing `fclPacketPosition` and `fclPacketColor` adapters at this shared
boundary.

Second, the row origin is two floating-point coordinates. Declaring its
storage as `f32 origin[2]` and copying the constructor's `FclVec2` value into
that storage produces retail's `lwc1/lwc1/swc1/swc1` sequence at stack offsets
`d8/dc` to `e8/ec`. A standalone structure assignment generated `ld/sd`;
individual component assignments lost or interleaved the required stores.
The array is exactly the two coordinates subsequently consumed by the row,
with no padding or unused state.

Third, the retained column is an unsigned word with explicit signed views at
its arithmetic consumers. The visible-column loop supplies values zero
through six. This prevents an unnecessary signed common subexpression from
remaining live and removes the extra `dsll32/dsra32` pair before the shadow
index calculation. The first-row byte and row/column counters retain their
retail signed narrowing.

Fourth, a signed word byte offset is retained for the position tables. A small
inline `fclRowAdjustedX` helper adds the second table entry to the current x
coordinate. Its locally scoped `opt_propagation off` preserves the current-x
load before the table load. That restores both the early table-offset shift
and the floating-point load order, leaving only a saved-register cycle.

Finally, declaring the resource before the first-row value and the column
before the row index gives retail's saved-value allocation: resource in `s2`,
column in `s1`, and row index in `s0`. An intermediate declaration order left
15 words different by swapping the two counters. The final order is exact
both with and without the `register` keyword; the ready source omits it.
No forced registers, empty assembly barriers, extra side effects or ordinary
computation assembly are involved.

Every row below is a completed immutable whole-Draw-owner compile using its
configured MWCCPS2 3.0.1 b210 `-O2` profile. Differences are fully resolved
instruction words, not relocation-masked scores.

| Stage | Executable bytes | Resolved differing words |
| --- | ---: | ---: |
| Current native-color contract with saved row body | 1,244 | 123 |
| Float-array origin copy and unsigned retained column | 1,244 | 30 |
| Retained table offset and ordered x-adjustment helper | 1,244 | 27 |
| Resource declared before the first-row value | 1,244 | 15 |
| Column declared before the row index | 1,244 | 0 |
| Final shared-contract owners and cleaned marker | 1,244 | 0 |

The ordinary C preserves the fourteen-resource hide loop, the
`0x14b` to `0x14c` remap, both signed truncations in the shadow resource
formula, the 61-times-column and three-times-column arithmetic, native color
returns, and the `savedIndex >= 3 && index != 12` branch. The exact instruction
proof includes stack arguments, all branch displacements and load/store order.

## Shared contracts and existing-code preservation

`fcl_row_draw.h` supplies one declaration for 002b77d0, 00320970 and 00329310.
The final 002b77d0 signature uses a signed halfword resource and image,
`FclVec2` position, `FclDrawColor` color, signed halfword order and durations,
signed byte mode, floating-point depth, signed halfword stack argument, and
unsigned word source. The real provider's retail code consumes the color
packet through its four bytes and explicitly narrows its mode comparison.
Its guarded C definition now agrees with the shared native-color declaration.
The provider remains an assembly fallback and earns no recovery credit.

The already matched 00320970 uses its signed-byte mode contract and native
position views. Its exact body remains 516 bytes with twelve zero alignment
bytes; all 24 relocations resolve. Combine's obsolete local declarations for
00320970 and 00329310 are removed in favor of the shared header. The entire
Combine and drawing-provider object files remain identical to their
authenticated pre-proposal objects, including the motion changes.

Preservation counts distinguish recovered C from assembly fallback symbols:

| Owner | Existing C preserved | Existing fallbacks preserved | C after proposal |
| --- | ---: | ---: | ---: |
| `src/Event/Fcl/y_fclCombineDraw.c` | 48 | 21 | 49 |
| `src/Event/Fcl/y_fclCombine.c` | 26 | 15 | 26 |
| `src/promoted/y_draw.c` | 55 | 3 | 55 |
| Total | 129 | 39 | 130 |

All 168 existing object functions have identical bytes and canonical
relocations. All pre-existing allocated data sections, alignment and data
relocations are unchanged. Early progress messages called the 69/41/58
object-function counts “active functions”; those totals include the retained
fallbacks above and are not recovered-C counts. The marker census proves
exactly one new C recovery, 00329310, and no other marker transition.

Seven existing C providers or entry functions have additional independent
resolved proofs in `ready/providers/`: 002b2970, 002b2a60, 002b6150, 002b68d0,
002b7750, 00320970 and 00331560. Existing provider objects were authenticated
against source, dependency, assembly-input, compiler, flag and object receipts
before reuse. They were not recompiled to recover old logs.

The three retail calls into 00329310 occur at `002fb810`, `002fbb24` and
`00328c14`. The first two are in Combine's retained 002f9d90 fallback and the
third in Draw's retained 00325450 fallback. Six existing calls into 00320970
are also checked. `ready/providers/proof.json` records all nine call sites,
their resolved retail destinations and their fallback status.

## Table and tail proof

Both position tables remain external data2 image regions. The complete
`image.bin` was checked against the configured size and SHA-1 and against the
validated retail ELF's complete loadable payload. A 64-byte region at each
referenced table address was then compared directly. These samples are not a
claim about recovered array length or newly owned data.

| External region | Address | Bytes checked | SHA-256 |
| --- | --- | ---: | --- |
| First x adjustment | `007495c0` | 64 | `afd780d215fd32a1d67d41357039b6d48e63d276d9365f531a4a8f50538dcfd8` |
| Second x adjustment | `00749600` | 64 | `9be918419dfba1f72cd49f592760e4546d29bd0935aa507d7beb86797cf6655b` |

Both HI16/LO16 pairs resolve to their named retail addresses. The target's
independent function proof records all four table relocation words and the
remaining 24 call relocations. Its owned-data list is empty. The four-byte
code suffix is separately checked as zero after all 1,244 executable bytes
have matched.

## Validation, artifacts and reproduction

The final sources pass `decomp_lint.py` with zero errors. Their five H003
warnings are the same pre-existing provider warnings as the live baseline;
there are no added findings. The new helper's propagation scope has its
measured justification. `git apply --check --whitespace=error` accepts the
integration patch. This was a dry run, not a production edit.

The active compiler path remains `probe_variants` to `verify` to `mwccgap`.
During the lane, prime changed the unrelated build-cache and EE staging
drivers. Input guards stopped before compiling under a changed epoch. Their
reviewed snapshots are retained separately from the tools actually executed
by this MWCC-only path. The compiler, flags, dependency headers, target,
function windows and executed probe tools remain content-checked in
`inputs/manifest-epoch3.json`. Earlier receipts are immutable.

All paths below are relative to
`build/resume-completion-20260921/fcl/`:

- `ready/integration.patch` and `ready/src/`: concrete integration proposal.
- `objects/ready/{draw,combine,provider}/`: final whole-owner objects, sources,
  compile receipts and function/data comparisons; Draw also holds the strict
  target proof and resolved code.
- `ready/providers/`, `ready/tables/`: independent provider, caller and table
  evidence; `ready/marker-census.json` separates C and fallback status.
- `ready/validation.json` and `ready/seal.json`: final validation and artifact
  hashes; `ready/lint.json` and `ready/baseline-lint.json` retain the lint delta.

| Artifact | SHA-256 |
| --- | --- |
| Integration patch | `3fd1f3522f9178b50226f0ddb099c11ef045e960ed94a056ee186ed06b7b2df2` |
| Final Draw source | `0749a14328204979f91e3a1a2a95c451c9d153ec3bd577aee9a876c8733dfdc5` |
| Final Draw object | `f7856960b01f57dd0aaa0b372524e671b48545e98c04cdd17269e8a275148f65` |
| Final Combine source | `cf01866189912db49ef12b57bd52478e46428aee6fa58a26189fbfee8259392f` |
| Final Combine object, equal to baseline | `f1af40a57168486428faff21405e04d34a0cfc30248d69b59385e11b9338764f` |
| Final drawing-provider source | `7a8ad6144afe0c1f1badf1541275ca4b2c0f9c27b9ff631093780d5ecb87f9d5` |
| Final drawing-provider object, equal to baseline | `3e09071f856a8e48830b1f5f601d60e8f8cbcb841d548b389ec660b54a1a70dd` |
| Shared header | `47e12cf98d959d171b0d58f411b71fe343dc59dee12f9d9733c58ed1c83f25ed` |
| Resolved 00329310 code | `bca81e42d689d6abb4685d5143edea26310448e117e5a7ab2a2238653d755dca` |
| Configured b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

Commands run from the publication worktree:

```text
python -B -S build/resume-completion-20260921/fcl/ready.py draw
python -B -S build/resume-completion-20260921/fcl/ready.py combine
python -B -S build/resume-completion-20260921/fcl/ready.py provider
python -B -S build/resume-completion-20260921/fcl/ready.py tables
python -B -S build/resume-completion-20260921/fcl/seal.py providers
python -B -S build/resume-completion-20260921/fcl/seal.py verify
python -B -S build/resume-completion-20260921/fcl/seal.py seal
```

Completed owner jobs are reused only after source, compiler-context and
object-hash authentication. Exploratory native-return-constructor and
wide-mode-provider alternatives remain in scratch; neither is included in
the ready patch. No game execution, whole-image link/build, commit or
publication is claimed by this lane. Live integration and whole-build
validation belong to prime.
