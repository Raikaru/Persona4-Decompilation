# Field resource authentication and guarded store correction, 2026-09-21

Worker-1 used only `build/resume-completion-20260921/field/` and this note.
No production C, headers, symbol maps, tests, or build tools were edited by this
worker. The starting publication HEAD was
`5a1bcf7e889d9b1fb1560201d686669739014501`. Final machine-readable evidence is
`build/resume-completion-20260921/field/FINAL_HANDOFF.json`; `EVIDENCE.json`
contains the expanded proofs, and `RUN_INDEX.json` records every new attempt.

## Resource queue proposal authenticated

The pending proposal in
`build/complete-20260921/field/resource/0014efc0/reviewed-native-resource-query/`
was authenticated before integration against the live resource owner, both
symbol maps, provider sources, owner dependencies, frozen assembly inputs,
compiler hash, and configured flags. No completed queue compilation was repeated.

The complete patch must contain all three files: `src/Kosaka/Field/k_fldResource.c`,
`config/symbols_recovered.txt`, and `config/symbol_data_addrs.txt`. Both maps add
`fldResourcePresets = 0x005f0590`. The three records at that address have a
12-byte stride: ordinary count, special count, and ten minor IDs. The separately
addressed 20-byte field map starts at `0x005f05b8`. The saved data evidence was
checked against the actual retail bytes.

`func_0014efc0` proves 844 bytes in its 848-byte window, four zero tail bytes,
and all 54 relocations. It owns no separate allocated data section. The twenty
other function bodies and their resolved relocation records remain unchanged,
as do all allocated data sections. The source-bound official result is
**20 MATCH / 1 ASM**; the remaining ASM is `func_0014f310`.

| Artifact | SHA-256 |
| --- | --- |
| Original live resource owner | `872d62d3115e1d769d3d5a22ae799c65e2bd5df3dcf787b8d495a6972151c8c8` |
| Accepted resource source | `5ecaf9137ec3d9dfe50f4af508ab93b04ee853ec2c476369a6625ed8d63f7bd5` |
| Accepted resource object | `8636c48354b0ed7955e7fe2cb071b8dd094d406ce084273d6c34f16e9ba70345` |
| Complete three-file integration patch | `2c8bf841c583596db538c821103c69c236b000b763acddcab27ec2e488e4bfe2` |

The patch passed `git apply --check --whitespace=error-all`. Copies of the source,
object, complete patch, both proposed maps, data evidence, and all 21 resolved
function proofs are preserved under `resource-authenticated/`. Its
`authentication.json` records the original base hashes and the proposed hashes.

During subsequent work the shared live resource owner and both maps changed to
exactly these authenticated proposal bytes. The final evidence records that
observation. The worker did not perform that integration. The field probe input
snapshot remains immutable; `field-probes/resource-alias-input-drift.json`
records the validated alias-only map addition separately.

## Ready guarded-source correction for 0014f310

The ordinary and special preset loops in the guarded C body truncate entries
when copying them into `D_007E8060`. Both assignments use an `u8` lvalue despite
the four-byte stride and the table's `s32` declaration. Retail has word stores:

| Retail instruction address | Actual word | Operation |
| --- | --- | --- |
| `0x0014fc84` | `0xac440000` | `sw $4, 0($2)` |
| `0x0014fd6c` | `0xac440000` | `sw $4, 0($2)` |

These words were read directly from the configured retail image. The surrounding
loops are visible in
`asm/nonmatchings/k_fldResource/func_0014f310.s:655-755`.
Real consumers in `src/promoted/code1_0015.c:2243-2254` and `2305-2313` read and
clear 32-bit entries across sixteen slots. This is a concrete width error in the
guarded candidate.

The proposal changes only the two lvalues to
`*(s32 *)((u8 *)D_007E8060 + offset)`. It remains inside the existing
`NON_MATCHING` branch. Reviewable files are under
`resource-loader/guarded-entry-word-stores/`:

- `guarded-resource-store-width.patch`, `k_fldResource.c`, and `HANDOFF.json`.
- `compile.json`, `owner.o`, all 21 `proofs/*.json`, and `official/verify.json`.

| Artifact | SHA-256 |
| --- | --- |
| Corrected guarded source | `bd8c46043dc6ed2564100bab40c332fb5ad2d6655ab7d67abce980704447d88c` |
| Two-store correction patch | `8c7f75e537b6ce543ec355510f2ef36a338d925e1cb2811cd888dca2f3315230` |
| Corrected owner object | `8636c48354b0ed7955e7fe2cb071b8dd094d406ce084273d6c34f16e9ba70345` |

One whole-owner compile under the configured profile produced a byte-identical
object. All code relocations, tails, and allocated data were re-proved. The
official result remains **20 MATCH / 1 ASM**, and the two-store patch passes
`git apply --check --whitespace=error-all`. This validates preservation of the
current build; it does not validate the entire guarded loader as native C.
`func_0014f310` remains ASM and still requires further whole-function recovery
and review of its legacy provider declarations. This correction is not a new
native promotion.

## Sphere callback and exact query remain held

The live field owner is unchanged at SHA-256
`ae3f5d2d77c7a9734380152602ac47b84f2e76e07bf5862fc986791ec45b07e8`.
Its sixteen existing function proofs were authenticated without recompiling the
baseline.

Mode-one sphere queries do not initialize collector direction. The current exact
`00169a30` callback computes the direction projection before testing mode.
The defined source must guard those reads with `mode == 0`. Retaining the normal
Y value for the independent slope filter preserves the existing fourteen-word
frontier but does not close it.

Six new callback trials covered direct short-circuit form, an explicit acceptance
branch, a boolean rejection value, and the three relevant predicate reconstruction
controls. Five retain fourteen differences at offsets `0xe4..0x118`; the boolean
value increases the mismatch. Every other function and all allocated data remain
unchanged. The selected trial is
`field-probes/00169a30/guarded-logical-y-lifetime-complete-pipeline/`:
1668/1680 bytes, twelve zero tail bytes, eight actual relocations,
**13 MATCH / 1 MISMATCH / 2 ASM** for that whole owner.

The saved combined exact-query/defined-callback object was separately
authenticated and preserved under `sphere-query-held/`. The old receipt's
`inputs_sha256` is a hash of canonical input entries, not of the JSON file bytes;
input, header, and profile digests were verified using the original convention.
`0016abc0` proves **1216/1216 bytes and all 30 relocations**. Its safe callback
still differs in fourteen words. Whole-owner verification reports
**14 MATCH / 1 MISMATCH / 1 ASM**, with the callback as the mismatch.

The combined source SHA-256 is
`6f68c10902f59643b6e998b3e753351e7ac7fa3125ceacbb91422863537f064d`;
its object is
`8cdab6957205b95409750d4acd1c8090504adece3e8563346395097b0b955854`.
Do not integrate the earlier `comparison-only.patch`, regress the exact live
callback, or promote the query while this acceptance issue remains.

## Dynamic query frontier retained

The saved dynamic owner was authenticated against current dependencies and
providers with all 39 target relocations resolved. Ten new trials tested projection
lifetimes, complete versus staged expressions, threshold/comparison interfaces,
and complete normal values. None reduced the existing twelve differences.

`field-probes/0016a110/pair-shared-query-projection/` retains
**2124/2128 bytes, four zero tail bytes, 39 relocations, and twelve differing
words** at `0x760`, `0x764`, and `0x7a4..0x7c8`. All fifteen other functions and
allocated data remain unchanged. The object is byte-identical to the earlier
best dynamic object:
`60fed3c82782ece1b03fa51604f18a41609ccc9970e4d4f7eeda4aef77bc3d07`.
Its official result is **14 MATCH / 1 MISMATCH / 1 ASM**.

The residual concerns the final opposed-normal projection's register allocation
and threshold/zero placement. Complete normal-value variants increased size and
remain rejected. `dynamic-authenticated/previous-measurements.json` and
`RUN_INDEX.json` preserve the old and new measurements so these jobs need not be
repeated.

`field-provider-authentication.json` records the actual providers: normalizer
`003e40b0` stores all three output components on every returning path, including
the Z store in the branch delay slot at `003e413c`; `0047a310` is the real
`void *mdlGetClump(void *mdl)` getter at model offset `0xdc`. The dynamic trials
retain actual array storage for normalizer arguments and the compatible model
pointer contract. No provider change is proposed here.

## Receipts and completion status

There are eighteen new attempts: seventeen successful whole-owner compiles and
one wrapper import failure before the native compiler was reached. That failure
is preserved separately; the subsequent compiler package snapshot is complete.
No successful compilation was replayed to recover logs. Final verification reused
only objects bound to their exact source hashes. Source, compiler, input,
relocation, data, and official results are retained in the lane.

Tracked background sessions `74453`, `18461`, and `39697` ended with exit zero.
There are no active terminal sessions. New native promotions in this run: zero.
The ready integration item is the guarded two-store correction; the pending
resource queue proposal was authenticated and subsequently observed integrated.

Three progress messages to prime were rejected with
`AGENTS_BUSY: no agent family belongs to this conversation`. This is an agent
routing failure; filesystem and terminal tools remained usable. The durable
handoff files contain the complete results independently of that routing issue.
