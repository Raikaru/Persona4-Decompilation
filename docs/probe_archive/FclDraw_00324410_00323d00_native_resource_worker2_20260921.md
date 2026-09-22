**Fcl transition/resource and label frontier — worker-2, 2026-09-21**

No recovery is accepted from this work. The delivery is
`build/complete-20260921/fcl/delivery`; both complete proposals are explicitly
unaccepted. There were 52 new successful whole-owner compilations. The saved
14 grouping experiments and 139 retained-value compilations were not repeated.
Sealing authenticates existing artifacts and does not compile.

The run used HEAD `5a1bcf7e889d9b1fb1560201d686669739014501` and the authenticated
checkpoint77 inputs (6453 MATCH / 408 ASM first-party at that checkpoint).
Prime's concurrent motion-header integration was subsequently carried into
scratch and independently checked. No live production source, header,
configuration, or tool was edited by this worker. No full build, global test
suite, commit, or other Git mutation was run. Every owned terminal session
completed.

The prior records were read completely before experimenting:
`FclDraw_003218a0_00323d00_worker5_frontiers_20260921.md` and
`FclDraw_00323d00_6a70_retained_values_worker5_20260921.md`. The retained-values
delivery, compiler inputs, and before/wide objects were authenticated against
the rebased owners and reused. Changed global CRI/GCC routing entries did not
change these owners' effective MWCC profiles; the exact differences are in
`build/complete-20260921/fcl/inputs/rebase-routing-deltas.json`.

**Byte alpha and delay contract.**

`delivery/byte-alpha-chain/proposal.review.patch` and `proposal/` contain all
eight logical owners. The actual alpha providers and every identified
forwarder/caller use compatible alpha, mode, duration, and delay types:

```c
void func_002b6a70(s64 resource, u8 start, u8 end,
                  u32 mode, u32 duration, s32 delay);
void func_002b6a40(u8 *task, u8 start, u8 end,
                  u32 mode, u32 duration, s32 delay);
void func_002b82d0(u8 *state, u8 start, u8 end,
                  u32 mode, u32 duration, s32 delay);
void func_002e0660(u8 *task, u8 start, u8 end,
                  u32 mode, u32 duration, s64 delay);
void func_0033d4b0(u8 *task, u8 start, u8 end,
                  u32 mode, u32 duration, s64 delay);
```

The resource provider still narrows to the real signed-short slot before
indexing. `002b82d0` stores the delay into its real halfword field. The two
forwarders explicitly pass `(s16)delay`. This last distinction matters:
declaring the endpoint delay as `s16` introduced an extra conversion in
`002e0700`; the native-word endpoint plus explicit forwarder narrowing restores
that function exactly. The alpha endpoint itself only stores bytes, so both
alpha inputs can be `u8` without changing its instructions.

| Logical owner | Represented functions | Changed in byte-chain proposal |
| --- | ---: | --- |
| `src/Event/Fcl/y_fclCombineDraw.c` | 70 | `00324410` only |
| `src/Event/Fcl/y_fclCombine.c` | 41 | None |
| `src/promoted/y_draw.c` | 58 | None |
| `src/promoted/code1_002e.c` | 40 | None |
| `src/promoted/code1_0033.c` | 39 | None |
| `src/promoted/y_smap.c` | 36 | None |
| `src/Event/Fcl/y_fclShopDraw.c` | 38 | None |
| `src/Event/Fcl/y_fclItemShopDraw.c` | 9 | None |

This is 330/331 pre-existing functions preserved byte-for-byte with canonical
relocations, and all allocated data preserved. The remaining `00324410`
regression is 620 bytes in its 624-byte window, with 49 fully resolved differing
words. This proposal is not an accepted closure.

Selected endpoints and protected callers also received separate complete
relocation/zero-tail proofs: `002b6a70`, `002b6a40`, `002b82d0`, `002e0660`,
`002e0700`, `0033d4b0`, `0033d550`, `003205f0`, and `0032fbc0`. Their proof JSON
and resolved bytes are under the corresponding `evidence/<owner>/` folder.

**Native resource family and the exact transition.**

`delivery/native-resource-family/` additionally changes the real resource
parameters of `002b6150`, `002b68d0`, `002b69f0`, `002b6af0`, and `002b7750` to
`s64`. Each actual provider explicitly narrows the resource to `s16` before
indexing. All five providers and the already-native `002b6a70` independently
prove exact. The complete provider owner still preserves all 58 functions and
its allocated data.

`00324410` now accepts `s64 resource`, as do its real Combine declarations.
Its incompatible local scalar-position declaration of `002b69f0` is removed.
The three initialized constructor snapshots use `FclPackedPosition`, and the
two position arguments are passed as their actual `FclVec2` views. The fourth
snapshot remains its existing `FclVec2` loaded from task work. This fixes the
resource contract and the position contract together without padding,
uninitialized state, fabricated side effects, or ordinary inline assembly.

The exact transition proof is:
`delivery/native-resource-family/evidence/draw/func_00324410.proof.json`.
It is **616 / 624 bytes, all relocations resolved, eight zero tail bytes,
no owned data**, resolved SHA-256
`4aa6eda9c56e7658c01b25116c5fca3eb161a24c0007500218908c6577ddd244`.

Two affected callers were restored in the final compiled proposal:
`00318f30` keeps a real native resource while explicitly using its signed-short
view for descriptor arithmetic; `0032fbc0` passes its already-retained native
resource to scale and position transitions. Both have independent exact
proofs in the same evidence folder (408/416 and 1180/1184 bytes respectively).

Five Draw functions still prevent acceptance:

| Function | Object/window bytes | Remaining evidence |
| --- | ---: | --- |
| `0031d630` | 1980/1984 | 35 resolved differing words |
| `0031ddf0` | 1328/1328 | 138 resolved differing words |
| `003212e0` | 1472/1472 | 14 resolved differing words |
| `003233d0` | 2344/2352 | 477 resolved differing words |
| `00330060` | 1872/1872 | Changed owned jump table; full residual unresolved at `@1551` |

The wider family therefore preserves 326/331 pre-existing represented
functions; Draw preserves 65/70. Its allocated-data comparison fails because
of `00330060`. The masked baseline alignment for that function is diagnostic
only and must never be presented as a resolved proof. Four other users of
`fcl_draw_task.h` have not been compiled with the wider declaration:
`y_fclShopDraw.c`, `code1_002b.c`, `y_CmbCardEff.c`, and `y_fclCmbBall.c`.

The prototype inventory also exposes retained contracts outside the repaired
transition: Combine's `002b68d0` flag/state declaration remains word-sized
against the provider's `s16`/`s8`, and Draw/Combine contain legacy `002b69f0`
position or delay declarations. These must be reviewed with their real
callers before any wider-family integration. Exact transition instructions
do not establish a complete owner-wide contract closure.

**Label routine.**

The coherent byte-alpha chain restores the saved `00323d00` candidate to
**1800/1808 bytes and 29 fully resolved differing words**. Using the wider
resource getter with native retained label IDs and removing obsolete short
aliases does not improve this residual. The remaining differences are the
retained alpha/resource register rotation; the first difference is at 0x2D4.
No recovery or instruction-count claim is accepted from this candidate.

`delivery/label-frontier/` contains the complete body, compilation receipt,
resolved bytes, exact differing offsets, alignment, and whole-owner neighbor
report. Its receipt refers to the preserved complete source/object in
`build/complete-20260921/fcl/resource-views/objects/native-label-getter/`.
This candidate belongs to the wider resource context, whose five unrelated
Draw regressions remain; its target-only score must not hide those blockers.

**New experiments and restart guidance.**

`delivery/receipts.json` authenticates all 52 new compilations, including
source, object, compiler, and transitive header hashes.
`delivery/experiments.json` records every measured result. The new controls
cover resource storage qualifiers and entry snapshots; alpha register/halfword
storage; scoped lifetime optimization; complete byte-alpha/native-delay
providers and five additional callers; native and word-sized resource
families; raw versus normalized retained resources; scoped CSE and short-slot
inline adapters; and the concurrent motion rebase. Completed outputs are
already present; do not repeat these jobs just to retrieve results.

Repeated normalization is the useful remaining resource clue. In the wider
family, MWCC retains a normalized slot across several calls where retail
retains the raw word and normalizes each outgoing use. Broad CSE disablement,
native raw/normalized locals, and typed short-slot inline adapters were
measured and did not close the five callers. The word-sized six-provider
alternative also proves `00324410` and all six providers exact, but regresses
eight Draw functions and is sealed separately under
`build/complete-20260921/fcl/word-family/`; it is not a better accepted proposal.

Prime's concurrent motion change was exactly the new
`model_motion_internal.h` include and removal of the stale `00479940`
declaration. `rebase-combine.py` preserved that change in both complete scratch
proposals. The current-before, byte-chain, and native-family owner objects
preserve all 41 Combine functions and data. The observed current Combine SHA
is `3e338084a43105d5af970684d97a05e80116d04b54e35cdae4cd0db1683e7fe2`;
the rebase evidence is `delivery/rebase-combine.json`.

Live source/header equality was checked against the final observed inputs at
seal time. Draw remains
`24f17ba7449b660c4480e00d0d927c177733806d8b244511439e98c10f15abd2` and
the provider remains
`93297983b0d1d117437555b414085bda8cd9639c85d041d3f0a8107721c54766`.
The logical-owner profile is MWCC b210 at `-O2`, compiler SHA
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
`delivery/seal.json` records all eight source/header observations, compiler
input provenance, manifests, and the explicit blockers.

Agent messages to prime repeatedly returned
`AGENTS_BUSY: no agent family belongs to this conversation`. Workspace tools
remained available. The on-disk delivery and this archive are the durable
handoff; prime retains all integration decisions.
