# Window/render recovery, 20 September 2026

The receipts for this work are under
`build/first-party-next/window-resume-w4-20260920/` (abbreviated `receipt/`
below). They are immutable source snapshots, compiler records, objects,
resolved retail bytes, and comparison results. The old window delivery and
all 32 saved list-render experiments were validated and retained.

## Integrated window and render-state contracts

The initial live `code1_0046.c` was exactly the saved `delivery-final` source.
`func_0046d750` already returned `-1` in case 8 and `0` otherwise. This is the
task-update contract in `include/sdk_task_registration.h`: the scheduler at
`src/Kernel/sdkTask.c::func_00451430` reads the result, and the `-1` branch
performs task/child cleanup when the corresponding task flags select it.
The retail callback contains the same explicit return values. No return was
invented or added to force a code match.

The remaining local state-restore declarations used integer payloads and
void returns for native RenderWare callbacks. They now use the native signed
return, `RwRenderState`, and `void *` payload types. Cached setter pointers and
actual payload expressions in the assigned owners were updated consistently.

Four save/restore call expressions in `004601c0` and guarded `004604d0` use a
compatible C89 function-pointer call type without a prototype. Their actual
arguments are explicitly converted to the native enum and pointer types.
Those types are unchanged by default promotions, and the signed return is
unchanged. The native function declarations retain their prototypes. This
preserves the retail address-before-load ordering without integer payload
proxies, altered effects, or fabricated memory accesses. The same technique
must not be extended to float parameters by casting away their prototypes:
float arguments undergo default promotion to double.

`receipt/state46-final/result.json` proves:

| Function | Executable / retail bytes | Zero suffix | Resolved code relocations |
| --- | ---: | ---: | ---: |
| `004601c0` | 784 / 784 | 0 | 30 |
| `0046d750` | 4244 / 4256 | 12 | 14 |

The nine-entry window switch table at retail `00756790` is also proved in
the `0046d750` result. Its 36 resolved bytes have SHA-256
`7374cf150379804f1ba51163837f2bfa3f7095657256c6cea34772a215405928`.
The entire default owner object was byte-identical to the old delivery:
`90396dfbe534f40e286efd416cbf2e9dfd379cb3b60cac0792fa205a2e2eeed7`.
All 57 sibling functions and all allocated data were preserved.

The corresponding `code1_0038.c` update covers 67 Sky-state calls and three
device setter calls. Its 95 default functions and all allocated data were
preserved, including the independently re-resolved `00380bd0` character
caller. The object remained
`cda145d1ac2cf239158b27a962c7f3f1d26dec954541bc24ac6877a166340933`.
See `receipt/caller38/final/result.json` and
`receipt/caller38/native/result.json`.

Thirteen guarded witnesses were also checked: three in `code1_0046` and ten
in `code1_0038`. `0038acd0` had a pre-existing compile collision between a
local anonymous vector and the shared `Vec2f` contract. It now uses the
shared type. Its normalized-before and final witnesses are identical;
its remaining retail residual is 154 masked words / 43 alignment edits.
The failed original compile is retained. The state-restore witness for
`004604d0` initially changed under ordinary native prototypes; the final
compatible call expressions restored the prior witness exactly.

The initial two-owner official verification passed 132 MATCH / 22 ASM
(first-party: 130 MATCH / 19 ASM). The report is
`receipt/native-verify.json`; `git diff --check` passed.

## TMX recovery and the actual original unit

`00463930` is now recovered as ordinary C. The saved, previously unexecuted
lead required native signed image dimensions and palette layout, valid TMX
indexed palette depths, and the original private helper boundary. The
palette byte count must survive private conversion calls. The six helpers
are called only by the memory decoder and have no materialized code-address
references. Their static definitions supply the actual compiler call-clobber
information; no synthetic effects were added.

The original filename string at retail `00712688` is `sdkUttmx.c`.
Filename references in `00463d60` and `00464100` bracket the intervening
`00463e60` and `00463ea0`. This supports the original unit reconstruction,
along with the contiguous helper/decoder cluster and measured preservation.
The two raw words numerically equal to `00463620` were checked in context:
they are ASCII ` 6F\0` within "Yukiko's Castle 6F" and
"Marukyu Striptease 6F", not stored function pointers.
Use `receipt/tmx-provenance-final.json` and
`receipt/tmx-raw-value-context.json`; earlier exploratory classifications
are retained but superseded by the byte-context audit.

The final unit contains the following exact functions:

| Function | Executable / retail bytes | Zero suffix |
| --- | ---: | ---: |
| `00463570` | 172 / 176 | 4 |
| `00463620` | 128 / 128 | 0 |
| `004636a0` | 160 / 160 | 0 |
| `00463740` | 128 / 128 | 0 |
| `004637c0` | 168 / 176 | 8 |
| `00463870` | 180 / 192 | 12 |
| `00463930` | 1060 / 1072 | 12 |
| `00463d60` | 252 / 256 | 4 |
| `00463e60` | 60 / 64 | 4 |
| `00463ea0` | 604 / 608 | 4 |
| `00464100` | 1240 / 1248 | 8 |

The memory decoder's eight code relocations are fully resolved. Its resolved
SHA-256 is
`bcb9c7c90632ab75e0aba1cbf98c302304b5a98189c5fe2002ce603327288dc1`.
The original three SDK functions, the moved helpers, the relocated write
callback, and all allocated data are preserved. `h_maestro.c` retains only
`0046a750`, still exact at 20 / 32 bytes. The promoted owner loses only the
old guarded decoder ownership and retains all 58 other function bodies,
relocations, and data.

The final callback audit establishes that `00463e60` is the registered TMX
image-write callback, not a stream callback. Its native signature is
`RwImage *(RwImage *, const char *)`. Retail opens the named stream for
reading, discards that returned handle, and returns the input image. That
observable behavior is preserved; the recovery does not add writing or
cleanup operations. The read callback is `RwImage *(const char *)`, and
the memory decoder now returns its native image pointer. Stream open, read,
and close declarations match the actual RenderWare providers.

The registration at `00100670` uses native image callback types. Its other
existing BMP write callback, `003d96b0`, needed matching pointer carriers
to complete that registration contract. The follow-up changes all 38
registration-owner and 131 BMP-owner functions by zero bytes/relocations and
preserves all data. `00100670` is independently exact at 1888 / 1888 bytes;
`003d96b0` also has a full resolved proof. These changes add no recovered
third-party function.

Final evidence and transfer files:

- `receipt/tmx-complete-unit/proof.json` and `integration.json`.
- `receipt/tmx-complete-unit/three-owner.patch` for the original TMX unit.
- `receipt/tmx-complete-unit/complete-integration.patch` for that recovery
  together with the separate native callback declaration follow-up.
- `receipt/tmx-registration-contract/integration.json`,
  `registration-proof.json`, and `code1_003d/write-callback.json`.
- `receipt/tmx-owner-removal/result.json` for promoted-owner preservation.

Prime applied the complete five-owner package to recovered-upstream and its
separate publish checkout. This worker did not write the external owners or
the publish checkout. The earlier `tmx-original-unit` proposal remains
immutable and is superseded by `tmx-complete-unit`.

## Exact wireframe cylinder and caller contracts

The `004601c0` external callers in `k_draw.c` and `code1_0014.c` used different
formal orderings even though the EE's separate integer and floating argument
registers had hidden the mismatch. Their native declarations and call
expressions are corrected in the external proposal, which prime has now
integrated in recovered-upstream: both live hashes match the proved final
snapshots. All 23 and 126 default owner functions, respectively, and all
data are preserved.

`004604d0` now compiles exactly as ordinary C: 1076 executable bytes in its
1088-byte retail window, twelve zero suffix bytes, and thirty fully resolved
code relocations. The resolved SHA-256 is
`196b93700c9cd16d0a0fa2e0abac50f4fba091ece0dbd781335c8c462da8371d`.
It draws a wireframe cylinder using circular slices, vertical lines, and
opposing radial segments. Its already exact `0014d830` wrapper uses the
formal order position, radius, height, color, state flag. The recovered
callee agrees with that order. Changing the wrapper to the old callee order
instead introduced an extra register move; that rejected experiment is
retained.

The recovery uses a real pair of three-component line endpoints, one counter
for the successive geometry traversals, and explicit initialization before
each traversal. The slice-step calculation precedes the point stores, and
the negative-height calculation is a separate full expression. The ordinary
floating local declaration order retains the original value lifetimes. None
of these changes adds effects, padding, or machine-register declarations.
The final readable names were recompiled and independently proved.

The last four mismatching instructions were caused by the ring routine's
formal order. `0045fbe0` takes position, radius, color, optional matrix, and
state flag. Its retail argument home moves and the cylinder's call setup
both show the floating radius in that position. All three callers in
`code1_0046.c` now use that typed contract. The two calls in the already exact
`004601c0` preserve their code and relocations. The coupled external provider
proposal changes only the guarded `0045fbe0` formal order. All sixty default
provider functions and all allocated data are preserved. Its own guarded
1492-byte witness improves from 323 masked words / 143 alignment edits to
322 / 140 and remains NONMATCHING; this is not a second promoted function.

`receipt/cylinder-delivery/owner/result.json` proves the cylinder, the
unchanged exact `004601c0`, and the window callback with its owned switch
table. All 57 other owner functions and all allocated data are preserved.
`receipt/cylinder-delivery/provider/result.json` proves the external ring
contract change. The two-owner proposal is `integration.patch`; individual
`owner.patch` and `provider.patch` files and before/after hashes are recorded
beside it in `integration.json`.

The promotion is integrated in the assigned recovered-upstream owner.
`receipt/cylinder-delivery/live-integration.json` binds the live source,
unchanged compiler dependencies, and exact object. Current owner source
SHA-256 is
`7911f07b6a28229d8c622da555bd6e48926dfe30bdb0829754768a0c561805f0`;
the exact object SHA-256 is
`19ec51c44acafaa0c41ef08a8e74de554d5e6786bf3da3af76ff5ed22ca07d40`.
Official scoped verification passes 54 MATCH / 4 ASM and `git diff --check`
passes. The ring-provider change remains prime-owned and was still at its
before hash in the last recorded check. The two external spatial caller
changes match their proved final snapshots. Their observed integration
state is recorded explicitly rather than assumed.

The earlier `receipt/rectangle-live-contract` records the intermediate
guarded formal-order correction, before the complete recovery. Its
195-word / 97-edit result and `f2db641c...` source identity are superseded by
the final cylinder delivery. The older external caller package contains that
intermediate guarded hunk; use only its individual `k_draw/final/proposal.patch`
and `code1_0014/final/proposal.patch` after the final promotion.

## List-render experiments and resumption

The 32 archived `0046f2b0` experiment source/object identities are indexed in
`receipt/inventory.json`. The saved best remains
`build/first-party-next/window/f2b0/analog-region-common-subs`: 3904 bytes,
469 masked words, 91 alignment edits against the 3936-byte retail window.

Four new probes use actual C89 identifier-list inline boundaries. Both
rectangle argument orders reproduce the 91-edit score. A float-default-
promotion analog boundary measures 98 edits; an unsigned analog boundary
measures 129. All default sibling functions are preserved, and no out-of-line
helper is emitted. These are scratch experiments, not production changes.
Their target-owned switch data is recorded separately from unchanged owner
data; no whole-owner data equality is claimed for these nonexact witnesses.
See `receipt/list-c89/completed.json` and each immutable compile/alignment
receipt. The remaining mechanisms are coordinate-register allocation across
the byte-clear loops and independent X/Y analog constant evaluation.

Do not re-import `receipt/lane.py` after integration: its freeze operation
intentionally requires the original delivery source. Use
`receipt/sealed_common.py` to inspect established snapshots or create a new
scoped harness. Reuse successful objects and receipts; failed comparison
assertions in the early migration scripts did not invalidate the completed
compiles. No full-tree or full-image check, commit, rebase, or push was run
by this worker. Prime owns publication and whole-tree verification.
