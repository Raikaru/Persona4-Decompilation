# Battle owner after rebase: worker 5, 2026-09-22

Checkout: `build/first-party-publish-latest`, HEAD
`c4388741f9070eaec2b37e3a3af3684886d1a581`.
All paths below are relative to that checkout. The new proof lane is
`build/continue-first-party-20260922/battle-after-rebase/`.

## Retained result

`func_001b70c0` is promoted to C and passes the official current-owner native
gate. This owner now has **115 MATCH / 8 ASM**. The global authenticated
checkpoint was not rewritten. The only production file edited in this run is
`src/promoted/code1_001b.c`.

| Item | Evidence |
| --- | --- |
| Original owner SHA256 | `02a3d51234b8653236a8475e8c613e32b57ca7a6be94279c35fcde945e1da51d` |
| Retained owner SHA256 | `c2b8c18109b72d82520660305d6c9c650549b40066c1ff2bf5a331cc77936d59` |
| Fresh native owner object SHA256 | `f8c9cc6a69ab43c3201e31ca9e58ef2b81e024728e591d9861803f892303545a` |
| Compiler SHA256 | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Compiler and flags | native MWCC b210, `-O2 -Iinclude` |
| Target size | 812 / 816 bytes; four-byte zero-only tail |
| Target relocations | all 34 resolved and compared without masking |
| Other owner functions | all 122 preserve raw bytes and canonical relocations |
| Allocated data | identical, including the existing `.lit4` section |
| Official result hash | `6da018b9f002a3edbb5535de208400cb3969a2a5ba5b1cbaab955ccc630996bb` |

The closure is `light-native/completed.json` within the proof lane. Its
`compile.json`, `owner.o`, `official.json`, source/dependency/assembly-input
hashes, target proof, and unchanged-sibling receipts are retained together.
`light-promotion/` contains exact before/after source, the retained patch, and
its receipt. `probes/light-retail-local-layout/` holds the exact scratch
precursor. No old proof directory or compiler receipt was overwritten.

The light update now declares the three scene getters as their actual
`void *(u16)` contracts from `src/Kosaka/Field/k_sceneDraw.c`. It also declares
the normalizer's floating return and the rotation provider's floating angle.
The old missing rotation prototype emitted an unwanted `litodp` relocation
in the first new control; that rejected control remains archived.

The retained C snapshots each color before destination stores and copies real
matrix/vector values. Independent vector locals supply the native stack
alignment and declaration order. They replace the parked explicit frame-gap
record, the `u64` comma-expression spill, and handwritten matrix copy loops.
The copied matrix representation follows the actual SDK aggregate operation;
no invented initialization or synthetic padding was inserted. The original
scoped propagation setting remains scoped to this function.

The caller in `code1_0019.c`, the unit-center provider in `Battle/btlUnit.c`,
the scene getters and consumers, complete retail assembly, both decompiler
references, and SDK matrix/vector/color definitions were inspected. Existing
typed callback helpers and owner game-state declarations were preserved.

## Camera: exact proposal, not promoted

`func_001b6120` now has an exact 1968-byte scratch candidate. It remains ASM in
the production owner because the final step requires a consistent geometry
provider/caller contract outside this assignment.

| Candidate | Words differing | Size | Status |
| --- | ---: | ---: | --- |
| Prior worker's `quaternion-y-first-load` | 26 | 1968 / 1968 | old proof read, not rerun |
| `camera/inspected-light-and-texture-providers/` | 5 | 1968 / 1968 | agrees with the current integer-address geometry provider |
| `camera/review-only-geometry-pointer-contract/` | 0 | 1968 / 1968 | depends on the provider/caller contract proposal |

The exact proposal has all **100 unmasked relocations**, no tail, unchanged
allocated data, and all **122 siblings unchanged**, including the promoted
light update. Its receipts are:

| Item | SHA256 |
| --- | --- |
| Exact camera full-owner source | `5b902e79b61d5abcc83310700799fb9b8fa3a71c161b8cdb084343da79185bef` |
| Exact camera native object | `5da451658c5e54ca8dd8014cb2f2d1350362399918f83d13d2ad8d9189c57f06` |
| Exact camera raw function | `ff1afa34263f7dd5188918ab0f588a32250ec3b2d8f989633ed33e1e1edf9fa9` |
| Exact camera resolved function | `1c4f086a16082c0bc688440e18bc3475ea6e4036a8c86f61aaa1b31692054629` |

The camera changes express the SDK's 16-byte-aligned matrix as a real global
matrix value and use aggregate color snapshots throughout. Converting only
the final color copy moved the eight floating-register differences to the
last remaining scalar copy. Replacing all six source-color snapshots and the
two global snapshots fixed that lifetime issue. The four-byte palette value
also fixed the final byte-register rotation. Quaternion loads, arithmetic,
the geometry fill loop, retail initialization, and call order are preserved.
Discarded call-result declarations were checked against actual providers.

The remaining five words under the current geometry contract are solely the
order of preparing four call arguments at offsets `0x5f4..0x604`. The current
provider declares the index-buffer address as `s32`; converting the actual
pointer to that parameter makes MWCC prepare `$a3` before `$a0..$a2`. Retail
prepares the three counts first and the index pointer next.

## Concrete cross-owner dependency

`geometry-contract-review/provider-proposal.patch` changes only the fourth
parameter of `func_00482f70` in a scratch copy of `src/promoted/effGeometry.c`
from `s32` to `const void *`, and performs its existing byte-offset arithmetic
on a byte pointer. The provider reads three halfword indices per triangle.
All inspected callers pass an index-buffer address.

This full-provider scratch object is exact at **380 / 384 bytes**, with a
four-byte zero tail, **six unmasked relocations**, all **16 siblings unchanged**,
and unchanged allocated data. The actual provider file has not been edited.

| Item | SHA256 |
| --- | --- |
| Unchanged production provider source | `040dd286d1a93e8f901b7d77d815301ffd8a166be6d47d5aff228004d2878d47` |
| Proposed provider full source | `e6a0fadf7c8fffcd4445360248c607d6d1f5d2c2207e44dcdd7b2ab3b1004987` |
| Proposed provider native object | `0c072f6dfb869d894bf66a72478c6ff9d4ac9a77b88a8b4a3d069543f9d06898` |

The proposal's source, body, compiler/dependency receipt, object, unmasked
proof and sibling/data checks are together under
`geometry-contract-review/index-buffer-pointer-contract/`.
`provider-proposal.json` and `camera-proposal.json` identify the two sides.

The other caller declarations needing coordinated review are in
`src/Graphics/Effect/effLineNova.c`, `src/promoted/code1_004a.c`,
`src/promoted/code1_004b.c`, `src/promoted/effPolygonFlash.c`, and
`src/promoted/effPolygonRing.c`. Their current declarations already use
pointer index parameters, with varying pointer-return views and integer
signedness. Those declarations and their call sites were inspected.
`audit/geometry-caller-inventory.json` records exact current lines and source
hashes. Some of these files have concurrent work; the proposal does not
overwrite them or presume their owners' approval.

Promotion requires integrating the consistent contract, capturing fresh
native current-owner/provider receipts, checking affected callers, and
running the official scorer against those fresh objects. The camera scratch
proof is not counted as a production MATCH and is not an official current
source closure.

## Probe coverage and handoff

New light groups cover verified callee contracts, color snapshots, SDK matrix
copies, vector-copy lifetimes, independent local values, and local layout.
New camera groups cover result contracts, matrix alignment/global typing,
RGBA snapshots, complete color-value lifetimes, typed address bridges, and
native-word address conversions. The latter address conversions and bridges
all retained the same five-word call setup difference. No old completed
control was recompiled and no broad pragma family was run.

`audit/completed.json` inventories every new native compile and scored probe,
hashes their objects and source, checks that all started compiles have
completion receipts, and revalidates the retained owner/compiler/dependencies
against `light-native/completed.json`. It also records the known first-probe
relocation rejection and `git diff --check` result. No full build, commit,
reset, clean, rebase, provider implementation write, or header write was run.

The remaining production ASM functions are `001b05d0`, `001b1d70`,
`001b2380`, `001b3a00`, `001b4060`, `001b4880`, `001b6120`, and `001ba0e0`.
This run did not replay the exhausted action-register/lifetime controls for
`001b05d0` or `001b11c0`.

All attempts to report the match and request cross-owner integration through
`agents action=message to=prime` returned `AGENTS_BUSY`: no agent family
belongs to this conversation. No prime delivery was confirmed. This failure
did not affect file access, native compilation, or the completed light gate.
One camera probe invocation was blocked before execution because its request
safety status could not be determined; after inspecting tool schemas and
saved state, the same group completed successfully. The retained source and
all completed native work were preserved.
