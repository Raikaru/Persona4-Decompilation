# Digit RGBA storage at 002ba080

This guarded replacement is installed in `src/promoted/code1_002b.c` and has
passed integrated image validation. It earns no new C match: the production
branch retains the assembly fallback. `owner.patch` is the complete reviewable
source patch; `body.c` is the measured guarded C body.

The hide paths read the four RGBA bytes at draw offset `0x75`. A dedicated
one-byte-aligned stored-word type reads those bytes with the retail
`lwr/lwl` pairs. An aligned local union provides the existing native
`FclDrawColor` value to both endpoint arguments. Public signatures, caller
contracts, glyph dimensions and the bounds packet remain unchanged. The
second row index uses the proven doubled signed-halfword input expression.

MWCC b210 requires `TypeName __attribute__((packed))`. Placing the same
attribute between the closing brace and typedef name left these types
four-byte aligned. The installed type has compile-time checks for size four
and a five-byte prefix-plus-value holder; separate native layout probes
also measured field offset one. Copying the entire wrongly aligned union
emitted an unaligned `lwc1`; that earlier diagnostic is explicitly excluded.

The valid candidate improves 244 to **192 fully resolved differing words**
and 1380 to **1348 bytes within the 1360-byte window**, with a twelve-byte
zero suffix. It retains 74 exact siblings and the owner's allocated data.
All 75 production functions and 388 code references resolve exactly, with
74 MATCH / 1 ASM in ordinary verification. The target still has 61 aligned
edits, a `0x140` frame instead of `0x130`, and differing color/position
temporary lifetimes and evaluation order. No compiler-floor claim follows.

From a configured checkout, run:

```sh
python docs/probe_archive/Fcl_digit_packed_storage_ui_20261006/replay.py
```

The replay accepts the bound owner before or after applying the proposal,
compiles four complete-owner contexts in a unique build directory, resolves
all code/data references, verifies siblings and expected target hashes,
and leaves source unchanged. Proprietary tools and retail bytes are not
included. `receipt.json` binds the source, compiler, profile, headers,
symbol inputs and replay files. Its original proposal lifecycle is preserved;
`installed-validation.json` and `integration.json` record the later checks.

## Integrated validation

The installed source SHA-256 is
`8fa8c7b7e7769e250325c31a7ac620ba5110ea4b28a7016f9a080308ae683906`.
The fresh replay in `build/ui-digit-packed-replay-f752aa7af7fc` compiles all
four complete-owner contexts and checks 300 function windows. Every production
function and all 74 other guarded functions remain exact, including their
references and allocated data. The guarded target still has 192 resolved
differences; no status or denominator has been changed to conceal them.

The fresh integrated build in `build/finish88-20261006/reconcile` retains all
previously linked C functions, including this owner. Its 658 linked translation
units and 8,586 physically linked function entries are unchanged. Both hashes
pass:

```text
SLUS_217.82:    4eeec0360cf2715535d9f7e52eb69d786fb0158c
Loadable image: 3d1d3d2b9d6ccb60836db239ab49674223025a78
```

Actual-path lint reports zero errors and 26 existing advisories, not zero
warnings. The first-party checkpoint remains 6,773 MATCH / 88 ASM. The completed
native and integrated checks are recorded separately from the full-source
verifier's ongoing refresh; this archive does not claim that an unfinished
verification command passed.
