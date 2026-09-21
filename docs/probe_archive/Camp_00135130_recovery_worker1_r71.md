# Camp 00135130 recovery, worker 1, r71

Prepared on 2026-09-20 from the live R60 tree. This is a coordinated integration
handoff, not a claim that production source was changed. The new renderer is
exact; its provider preserves the complete existing default object. The
remaining callers stay guarded. No production source was written during this
continuation, and the larger cmpEquip body replacement was rejected.

The reviewable bundle is
`build/first-party-next/camp/equip-next/worker1-r71-closure/coordinated-closure.patch`.
`git apply --check` succeeds against the recorded live source hashes. The same
directory contains `ready-manifest.json`, the individual patches, final owner
sources and objects, compiler commands, preservation reports, and unmasked
proofs. The driver is `build/first-party-next/camp/worker1_close71.py`. Its
actions create immutable output directories; completed actions must not be
rerun into those directories.

## Exact candidate and preserved recoveries

`func_00135130` now has the faithful interface
`void (u8 *work, s64 inputPosition, s32 inputAlpha, u8 *entry)`. The incoming
scalar is the complete eight-byte position object. Its two float words are
read from that object, while a real `PackedVec2f` holds the changing draw
position. The function uses a complete RGB/alpha object and a four-word
rectangle union. All child calls carry their actual arguments, including the
R60 explicit float coordinates and depth for `func_002bc7a0`.

The scalar incoming position emits the same exact renderer as the earlier r69
aggregate candidate. Keeping that scalar interface permits a small caller
contract patch without substituting the unsuccessful cmpEquip packet body.
The final staged code13 source removes the obsolete 35130 floor comments and
its `NONMATCHING` marker. The preceding and following recoveries remain intact.

`ready-proofs/completion.json` contains these results. Every relocation is
resolved to its actual retail address; no instruction bits are masked. Every
remaining suffix byte is checked to be zero.

| Function | Emitted bytes | Retail window | Relocations | Zero suffix |
| --- | ---: | ---: | ---: | ---: |
| `func_00135130` | 1008 | 1008 | 27 | 0 |
| `func_00130ce0` | 1476 | 1488 | 14 | 12 |
| `func_0013b420` | 1480 | 1488 | 14 | 8 |
| `func_00112300` | 712 | 720 | 27 | 8 |
| `func_00112610` | 540 | 544 | 7 | 4 |

The final renderer object is
`renderer-ready/owner.o`, SHA-256
`d3df39410c4d704ef3b8aa518b88049049edcd311ea28c71576ee8fe5e737c31`.
Its 42 siblings have identical bytes and canonical relocations to the
validated R60 object. Every allocated data section retains its bytes,
alignment, and relocations. The resolved 35130 code SHA-256 is
`eaf625ac72db37664d5cc646690e159a959e2b1587c6649e70dfc66a0332d305`.

The owner uses the configured MWCC compiler and owner flags. The compiler
SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The final audit found 768 unchanged tool, configuration, include, and ASM
inputs, with no changed or missing input. Existing R60 and earlier compiler
objects were reused only after checking their source and object identities.

## Provider closure

The exact icon call requires the declaration
`void func_00112300(f32 depth, u64 position, s32 alpha, u8 *entry)`.
The provider keeps the actual parameter object as its position storage. An
extra local position union changes its frame and is not used.

Changing parameter order alone exchanges two prologue instructions. Retaining
the depth, alpha, and entry inputs in ordinary local variables under a scoped
`opt_propagation off` preserves their lifetimes and the original instruction
order. Propagation is restored immediately after the function. This is the
same kind of retained-input mechanism already present in neighboring
recoveries; it introduces no synthetic side effect or forced storage.

The patch also corrects the local 12610 position declaration to its actual
`Vec2f` definition and passes the complete position object to it. Alpha is
consistently `s32` in the declarations and definitions of 12610, 12830, and
130c0. The last two functions remain guarded.

`provider-capture-preservation.json` proves all 47 default owner functions and
all allocated data unchanged. The provider object is
`provider-capture-lifetime/owner.o`, SHA-256
`19a9175bb2a60e3215ceff74707a9e8b00a912b8b37f66264507ade924ad1c51`.
The final proof reuses this successful object after checking its receipt and
hash. The candidate source and external patch are
`provider-capture-lifetime/owner.c` and `provider-capture-code11.patch`.

## Coordinated patch contents

The bundle contains exactly these five source patches. External owners must
be integrated by the prime together with code13; installing code13 alone
would leave the provider declaration and callers inconsistent.

| Owner | Patch in the r71 directory | Default preservation |
| --- | --- | --- |
| `src/promoted/code1_0013.c` | `ready-code13.patch` | Exact renderer; 42 siblings and data unchanged |
| `src/promoted/code1_0011.c` | `provider-capture-code11.patch` | All 47 functions and data unchanged |
| `src/promoted/code1_0012.c` | `caller-code12.patch` | All 82 functions and data unchanged |
| `src/Battle/btlResultSimple.c` | `caller-battle.patch` | All 13 functions and data unchanged |
| `src/Camp/cmpEquip.c` | `caller-equip-contract-only.patch` | All 8 functions and data unchanged |

The recorded before hashes are:

```text
src/promoted/code1_0013.c
fbe4905881af70a491e9b2a120144df1149a597d718382504712e12618ded92c
src/promoted/code1_0011.c
8ace1e129eddd91918fe26cc73e0c41e883bf2057729a39d915e32d5dcb93d2e
src/promoted/code1_0012.c
21d913d5eae4f0a0983ae771b535b76024bc1ad75825d0ae1014cd5313498cab
src/Battle/btlResultSimple.c
529b098326d1874ff05aa62fdf7c7820bc8e1654f9379a170d48971382c1f578
src/Camp/cmpEquip.c
ef47f3bf295336bcfee62bd678eb224d3c5b78dd9dff5a56d924c5e8dd7db9e4
```

All after hashes, patch hashes, source paths, and object hashes are in
`ready-manifest.json`. The Battle snapshot includes the prime's existing
changes. R60 code2b/code35 forwarding and existing character accessor fixes
are preserved; this bundle contains no code2b, code20, code35, cmpSkill, or
global-header edit.

## Guarded candidates and limits

The interface updates were also compiled with each affected guarded body
selected. All other functions and allocated data remained unchanged. These
are unmasked alignment edit counts, not exact-match claims:

| Guarded function | Emitted bytes | Previous edits | Updated edits |
| --- | ---: | ---: | ---: |
| `func_00112830` | 2160 | 434 | 433 |
| `func_001130c0` | 440 | 4 | 6 |
| `func_0012e9d0` | 5040 | 658 | 657 |
| `func_0021fea0` | 5576 | 576 | 577 |

The 130c0 change exchanges the order and registers of the byte-alpha
subtraction. The Battle change exchanges the position load with the widened
alpha argument preparation. These small scheduling regressions are explicit
limitations of the prepared interface closure. Neither function is promoted.
A separate opacity-capture attempt produced 432 bytes and 30 edits for
130c0; that attempt is rejected.

Use `guarded-resolved-diagnostics.json` for the code12 and provider-child
measurements. Their first completion files tested only explicit symbol-map
membership and incorrectly listed address-encoded or GP-relative names as
unresolved. The corrected diagnostic uses the actual resolver; every symbol
in those four reported witnesses resolves.

The preferred cmpEquip patch only changes the two interfaces and four icon
call argument orders. It retains the existing body and its `0x100` frame.
The guarded witness changes from 10244 to 10236 bytes, including removal of
the incorrect signed-byte extension at the 35130 boundary. Legacy
`CONCAT44` and `fptodp` references remain unresolved in that witness, as they
were before this continuation. No fully resolved comparison is claimed for
this retained floor. The production ASM remains selected.

The separate `caller-equip-scalars-packets` experiment keeps float working
scalars, forms actual position packets at call boundaries, and replaces the
scattered entry fragments with one real entry structure at the offsets used
by 1125d0 and 112300. It eliminates every unresolved call in the guarded
candidate. However, it emits 10036 bytes with a `0x130` frame against the
retail `0x110` frame and has 1697 unmasked alignment edits. That larger
replacement is absent from the coordinated bundle and stays in scratch.

## Completion and integration status

`coordinated-closure-apply-check.log` records the successful read-only patch
check. `ready-proofs/completion.json` and `ready-manifest.json` are the final
receipts. No commit, rebase, push, full-tree build, or full-image build was
performed. All compiler subprocesses completed and released their owner
locks.

Prime messages repeatedly returned `AGENTS_BUSY: no agent family belongs to
this conversation` while calls were filed as Unattributed. File and terminal
tools remained functional. This note and the prepared bundle preserve the
handoff independently of that failed message route.
