# Line/talk continuation after c438874 — worker 1, 2026-09-22

No new exact function was integrated. Both assigned production owners are
unchanged. Official scoped verification reports **64 MATCH / 3 ASM**, with
zero mismatches, for `src/promoted/nLine.c` and `src/promoted/code1_0033.c`.
The earlier pscRes recovery remains separate completed work; its historical
compiler receipts were not rerun.

## Inputs and evidence

The resumed HEAD was `c4388741f9070eaec2b37e3a3af3684886d1a581`. Both owner
sources, all their recorded local dependencies, and the native b210 compiler
were hash-checked against `line-ui/PAUSED_FOR_REBASE.md` and the original
`line/inputs.json` / `talk/inputs.json`. No applicable AGENTS.md was found in
the worktree; the source style rules and retained target/provider evidence
were reviewed. Existing initialized storage and scope aliases were preserved.

New evidence is under
`build/continue-first-party-20260922/line-ui/postrebase-c438874/`.
It contains **40 successful native candidates, one failed compiler receipt,
and zero exact candidates**. The 29 pre-rebase candidates were read rather
than replayed. Each new successful destination retains its whole owner source,
candidate body, object, compile log/receipt, resolved target bytes, full
unmasked residual, and sibling/data comparison. `inventory-final.json`
contains the complete measurement inventory.

Native profile: MWCCPS2 b210, `-O2 -Iinclude`, compiler SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Scratch scripts are `resume.py`, `decoration_probe.py`, and
`review_postrebase.py` in the parent `line-ui/` directory. Their completed
actions are historical measurements, not a pending work queue.

## nLine 0034ddf0 and its callers

The compatible retained target remains **5 unmasked words / 700 bytes** in
the 704-byte window, with 12 fully resolved relocations and a four-byte zero
suffix. Retail uses f1 for the float-to-byte conversion destination and
high-path subtraction; the candidate reuses f2. The differing offsets remain
`0x118`, `0x11c`, `0x130`, `0x134`, and `0x138`.

The active vertex provider orders arguments as
`(x, y, destination, depth, reciprocal, red, green, blue, alpha)` and the
camera getter returns an s32 address. All new canonical fixtures use those
actual declarations and matching calls. No provider implementation was edited.
The retained canonical five-word source remains
`line-ui/line/canonical-staged-coordinate-destination/`.

Its five sibling regressions are `0034c6c0`, `0034c860`, `0034d890`,
`0034db60`, and `0034e0b0`. Their diagnostic alignments are now available in
the new lane; the prior reviewer stopped at an anonymous owned constant.
Diagnostic displays exclude relocation immediates, while the target proofs
and recorded sibling equality checks remain unmasked/canonical respectively.

New measurements tested real typed output-buffer addresses, arithmetic X/Y
snapshots, propagation limited to affected callers, ordered inline vertex
boundaries, combined fade-height/alpha values, and separate transition/alpha
lifetimes. Propagation-off plus typed coordinate staging restores most c6c0
setups, but its first call still puts the destination copy after the two
float moves. Whole-caller propagation changes other code/data and is rejected.
The naive e0b0 X snapshot additionally keeps a coordinate across calls and
changes its saved FPR allocation. These are concrete caller-lifetime issues;
a wrong prototype is not an accepted workaround.

The combined fade view changes the height/top allocation, but retains the
five conversion differences. Separating the scaled alpha amount adds a move
and still retains the conversion differences. Reusing the elapsed-time scalar
for the later product ties five. The documented scalarization control removes
required byte-promotion instructions and produces 692 bytes, so it is rejected.

## Talk 00331a20

The new **`talk/message-code-slot-inline-boundary/`** candidate improves the
compatible-provider baseline from **34 to 25 unmasked words**, still
1388/1392 bytes with 51 resolved relocations and a four-byte zero suffix.
All **38 siblings** retain identical bytes and canonical relocations; allocated
data is identical. This is not an improvement over the incompatible historical
24-word source under its old declarations; it is a better candidate under the
actual provider contracts.

A genuine `talkSetMessage(s8 slot, s32 message)` inline adapter promotes the
slot to the provider's s64 input after materializing the message code. Its
call uses the existing `(s64, s32)` provider declaration and preserves the
ignored s32 return. It closes the three nine-word-total argument-order
regressions introduced by correcting that provider signature.

The remaining 25 words are the original 24 work/date s2/s3 register words and
one instruction at **0x34**: a byte mask when passing the u8 month getter's
result to the real s32 month converter, where retail has a move. A narrow
month adapter adds a result lifetime and delays the multiplication; it does
not remove this mask. Independent state-local work aliases, a retained work
view, separate scan bounds, and single calendar-encoding helpers do not close
the register exchange. The scalarization control ties 25. No incompatible
provider declaration or undefined upper-byte read was introduced.

## Remaining nLine target 0034e360

The decoration builder was investigated after the close mechanisms stalled.
The current inherited native control is 342 unmasked words; the compatible
provider control is 344, both at 2648/2656 bytes. A typed edge-geometry view
reduces the compatible result to **340 words**, retaining 40 resolved target
relocations, an eight-byte zero suffix and unchanged allocated data. The same
five canonical nLine sibling setup regressions remain.

Typed output-record arrays, retained indexed output views, independent endpoint
inputs, a projection pair, style-local vertex cursors, a shared strip basis,
and reusing exhausted extents as the current strip peak were measured. Retail
spills its fixed basis coordinates while this reconstruction keeps some in
FPRs and spills later corners instead. No exact source was found. The archived
custom-size/style-1..4 direction precondition remains an acceptance issue;
no invented initialization or input guard was added.

## Validation and hashes

`review_postrebase.py` independently resolves all target relocations from named
symbols, compares every unmasked instruction, checks each zero suffix, and
rechecks sibling bytes/canonical relocations and allocated data. Its three
reports are in `postrebase-c438874/review/`; they agree with the probe resolver.

The official verifier's comparison logic was unchanged. Its scoped main call
reused the original immutable native owner objects after checking source,
dependency, compiler and flag identities. `production-official/official.json`,
`official.log` and `completed.json` record **64 MATCH / 3 ASM**, exit 0.
Scoped lint reports **zero findings** for both owners; scoped `git diff --check`
passes, and their `git status --short` output is empty.

| Artifact | SHA-256 |
| --- | --- |
| Unchanged nLine source | `6641625e16fbd9f5f780f7a4ca3ea18f461cabfbbb155577c53a08adbb1e1284` |
| Unchanged nLine native object | `1c5e4a7217cc7648f0aa5c38fa2f418d19a4aa5366beace82a4b613ffa44c1ae` |
| Unchanged code1_0033 source | `7bca7e26ef3d1efddf886dd2eaa4b73b130999f5306e4ef91e99b3594b662258` |
| Unchanged code1_0033 native object | `4e34925d7861ec80317f8395113fc41537c1ffed7e212a99ba2d1779aa952c75` |
| New talk candidate source | `fe1f36e73234c879e2affdaf5acce86134b6d7ce044aeddf7d4b216794d7cc02` |
| New talk candidate object | `82ac1e3f76a79896dc345dc70b56209f661f0792495c63f58cd9227a449e927d` |
| New decoration candidate source | `29c0665b5f51748854de19d289aedd6e99b384ad174af1fe154be06ad322057b` |
| New decoration candidate object | `1b2e0747d537f73a4274673f5a0f03506ecf49f5ca5ed99acf1000a44f59d225` |

The one failed geometry compile came from naming a new outer view `edge`,
which collided with an existing inner Vec2f alias. The outer view was renamed
`meshGeometry` in a new destination; the existing inner alias was preserved.
Two commands were blocked before dispatch with `couldn't determine the safety
status of the request`; their unchanged retries completed once. Initial prime
messaging returned `AGENTS_BUSY`; messaging later recovered in run
`cfc5fe4b-66f0-447f-bd52-6b6be0bf5eeb`.

Released owners: `src/promoted/nLine.c`, `src/promoted/code1_0033.c`.
No native job remains running. No production edits, commits, pushes, vendor
changes, global builds, or global tests were performed in this continuation.
