# Fcl initializer: exact staged proposal, pending SDK contracts

This is **unfinished recovery work**, captured on September 20, 2026 against
`0360227d0a4194cb84500a5cf63ac554b38a79c2`. The initializer still uses its
assembly fallback in production. Neither the initializer nor the existing
creator functions in this proposal add an accepted match to this checkpoint.

The earlier body remains unchanged in
[`../Recovery_20260920_pending/002e8410.c`](../Recovery_20260920_pending/002e8410.c).
This record preserves the subsequent complete owner proposals, creator-return
corrections, aggregate contracts, and real SDK registration/dispatch work as a
compact patch rather than another set of whole-owner snapshots.

## Contents and reproduction limits

`proposal.patch` describes seven C owners, the shared Fcl header adjustment,
and three proposed headers. The headers are also available separately under
`include/` for review. `manifest.json` records baseline and proposed source
hashes, saved object hashes, resolved target hashes, all owner comparisons,
guarded-body checks, and the staged official-verifier result.
`sdk-inventory.json` preserves registration arguments, literal callback
definitions, and input hashes for the observed migration scope.

Owner proof baselines are immutable `0360227` copies. The SDK inventory was
refreshed from the working tree while other recovery lanes continued; its
per-file hashes identify those inputs, which are not all claimed to be pristine
`0360227` blobs.

The patch is a **partial SDK migration**, not an integration-ready patch.
Do not apply its SDK changes to production without completing the callback
closure described below. It is based on immutable baseline sources and must
not replace newer whole owners. Reconcile its individual changes with current
source before any future compilation.

The measured sources, logs, objects, complete relocation records, proof tools,
and failed alternatives remain under
`build/first-party-0360227/fcl/`. The preferred staged shape is `direct03/`.
The patch changes only the scratch SDK include's spelling to the ordinary
repository-relative include; it preserves the compiled function bodies.
Both compiled-source and portable-source hashes are recorded. A future
integration still requires fresh compilation of the actual resulting owners.
The published patch uses zero context and LF line endings so its checked hashes
survive a normal Git checkout. It was checked and applied with
`git apply --unidiff-zero` in a separate fixture repository containing the
pinned baseline. All eleven resulting file hashes equal the manifest's portable
source hashes. The production tree was not used for this replay. Apply this
context-free patch only to its pinned baseline; reconcile changes individually
when working on a later revision.

The original CRLF archive is preserved under
`build/first-party-0360227/fcl/archive-before-lf/`. The manifest retains its
prepublication hashes separately. This encoding and patch-format change does
not alter the measured C bodies or compiled-object receipts.

## Implemented and measured changes

The initializer retains the saved independent descriptor-loop counters and
constructor-backed positions. Position and color arguments use the same
aggregate member types as the real draw provider. Existing menu and shop
callers retain eight-byte packet storage and pass the union's position member;
an inline packet-return helper caused unnecessary stack copies and was not
retained. The newer guarded `002f0f00` and `002f9d90` bodies survive.

Five creators capture and return the real SDK task handle. In addition to the
previously archived `002b5c90`, `0034ad70`, and `0034b740`, the initializer also
consumes `002b8150` and `002b9f90`, whose old C definitions returned `void`
despite retail preserving the registration result. Each captured return keeps
the existing creator's instructions and relocation destinations unchanged.
No synthetic return value or replacement callback body is introduced.

The actual SDK update dispatcher consumes a signed-word result: zero retains
the current handler, minus one requests destruction, and another value becomes
the next handler address. Cleanup callbacks return `void`. The staged interface
uses `s32 (*)(u8 *)` and `void (*)(u8 *)` respectively, and the dispatcher and
cleanup paths pass the same byte view of the task object. Registration forwards
these actual function pointer types into the appropriate stored slots. The
reviewed Fcl callbacks keep their real existing definitions; incompatible
function-pointer casts are removed from the staged registrations.

Fresh configured MWCCPS2 b210 compilation and complete relocation application
give the following results. These are staged-source measurements, not evidence
that the global SDK API has been reconciled.

| Function | Executable / retail bytes | Resolved code relocations | Verified zero tail |
| --- | ---: | ---: | ---: |
| `002e8410` | 3256 / 3264 | 148 | 8 |
| `002b5c90` | 264 / 272 | 12 | 8 |
| `0034ad70` | 220 / 224 | 12 | 4 |
| `0034b740` | 204 / 208 | 12 | 4 |
| `002b8150` | 160 / 160 | 12 | 0 |
| `002b9f90` | 228 / 240 | 12 | 12 |

The initializer introduces no owned data section. All 413 functions across
the ten audited owners were compared against fresh baseline objects: only
the initializer changes. The other 412 function bodies and canonical
relocations remain equal, as does every allocated data section. The three
additional protected owners are `code1_002b.c`, `code1_0034.c`, and
`y_fclCombineDraw.c`; their unchanged definitions need no source patch.

The official verifier run on the seven staged changed owners reports
**203 MATCH and 37 ASM**, including `MATCH` for `002e8410`. This is not a
repository-wide build or a current-production acceptance result. Fourteen
affected guarded bodies were separately enabled and compiled on both sides;
their bytes, canonical relocations, call sequences, sibling functions, and
allocated data remain equal. An include-tree change invalidated the first
`002f9d90` after-compile receipt, so both sides were recompiled successfully in
`guarded03-recheck/`. The invalidated attempt is retained in scratch.

## Concrete remaining contract work

The observed SDK inventory contains **241 registration calls in 103 C owners**.
Combining these with the literal callback-definition owners covers **115 C
files** and **394 distinct update/cleanup callback roles**. This includes
guarded source. It is a starting inventory, not proof that every indirect
handler and every external declaration has been found.

Among the observed definitions are eighty no-argument callbacks, integer and
various pointer parameter types, and seven update callbacks declared `void`:
`00332bb0`, `00148280`, `0016bdd0`, `00182bc0`, `00183b80`, `00185850`, and
`0018a200`. Their actual return behavior must be recovered before assigning a
common update signature; adding invented zero returns is not acceptable.
The initial scanner did not find a C definition for literal callback `00192790`.
The [independent review](sdk-review.md) resolves it to the existing
`btlUpdateDraw3DFrontTask` definition and follows the scheduler aliases and field
table. Its expanded inventory contains 400 callback roles, with 132 incompatible
roles across 58 owners, and identifies stale declarations and five incompatible
callbacks still inside the staged owner set.

The closure must also follow the `D_005F15B0` callback table used by
`k_fldUnit`'s `00167420`, the forwarded handlers in `cldScheduler`'s `00260450`,
the named `scrDestroyTask` registrations, handler replacement addresses, and
any direct non-SDK callers of callbacks. Reconcile both registration entry
points, every applicable declaration, and their actual invoked function types
together. The older 74-owner proposal in `sdk-registration/` does not cover
this current set and used an incorrect void-return update declaration.

A narrower bridge preserving the current SDK's raw integer-address interface
was also measured. Casts to integer callback arguments moved callback-address
setup before the ordinary arguments. Eight variants using genuine address
locals, inline conversions, parameter packets, unions, and scoped compiler
controls either retained that residual or added stack traffic. The original
bridge leaves twenty-seven differing bytes at the initializer's registration
setup and also changes existing matched creators; no bridge variant was
installed. The successful direct typed interface must not be substituted while
leaving the other SDK callers on incompatible declarations.

There is a separate representation review to finish. The existing bounds
constructor `002b29e0` assigns dimensions at offsets eight and twelve, then
copies the whole sixteen-byte record, including an unspecified first eight
bytes. Retail confirms the unwritten stack prefix. The panel setter copies
that complete record. Establish the opaque-prefix and consumer contract before
claiming that this is a fully initialized four-float rectangle; do not invent
initial values to hide the issue.

After those contracts are complete, recompile every actual affected owner and
each touched guarded caller with current configuration. Require exact target
instructions, fully resolved code and data, a zero-only omitted suffix,
preserved previously matched siblings, and the integration lane's normal
verification gates. Until then this proposal remains an archive.

## Production state

No proposed C owner was installed. The three unused live headers were removed
after preservation, and `include/fcl_combine_internal.h` was restored byte for
byte to the baseline. Other workers' source and header changes were left
intact. No compiler output, retail bytes, machine-local configuration, commit,
push, or whole-image build is part of this archive.
