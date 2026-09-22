# Field resource queue recovery: 0014efc0

Worker 1, September 21, 2026. The proposal recovers `func_0014efc0` in
`src/Kosaka/Field/k_fldResource.c` as **844 executable bytes in the 848-byte retail
window**, with **54 fully resolved relocations** and a four-byte retail zero tail.
The proposed whole owner verifies at **20 MATCH / 1 ASM**. All twenty siblings
retain their instruction bytes and canonical relocations, and allocated owner
data is unchanged. The target owns no allocated data sections.

The source and both required symbol-map changes are review-ready in
`build/complete-20260921/field/resource/0014efc0/reviewed-native-resource-query/`.
`HANDOFF.json` identifies the complete owner, `integration.patch`, compiler
receipt, per-function resolved proofs, official verifier result, lint and patch
checks. Prime owns integration and the full-image build. This worker changed no
production C, headers, maps, build tools, or existing archive files.

## Source mechanism

The function chooses between an ordinary preset, a special preset and the
requested major/minor pair. It preserves both scene-predicate calls and the
second special-predicate call, the optional resource-file request, the pack-file
open/log calls, descending preset expansion, ordinary resource-array copying,
and the final timestamp update. Existing queue count at work offset `0x98` is
retained; the retail initialization clears the queue bytes but does not reset
that count.

Each append captures the current work pointer for that operation. With retained
value propagation and loop-invariant handling, these captures reproduce retail's
single base load and its reload for the next operation. Explicit unsigned-short
identifier conversions prevent a shared `0xffff` mask from staying live across
calls and creating an extra saved register. The exported two-word interface and
all original arguments forwarded to predicates and the file provider remain intact.

The field data has three real 12-byte preset records at `0x005F0590`. Each record
contains ordinary count, special count and ten signed minor identifiers. The
twenty-byte field-index map begins at `0x005F05B8`. Both actual predicate providers
establish the index domain: ordinary major IDs are 40 through 59, while special
IDs are 60 through 79 and are reduced by 20. Consequently the map subscript is
0 through 19, and the retail map's values are all 0 through 2. Both record counts
are at most ten. `preset-data-proof.json` retains the complete records, map bytes,
addresses and hashes from the authenticated retail executable.

The named `fldResourcePresets[3]` declaration exposes those typed records while
the existing byte view remains available for field-index lookup. It introduces
no storage or copied data. **Both `config/symbols_recovered.txt` and
`config/symbol_data_addrs.txt` must register `fldResourcePresets = 0x005f0590`.**
The integration patch supplies both registrations. The named view separates the
record lookup from the byte-map expression and retains retail's two address
evaluations. An earlier diagnostic used an ignored `#pragma alias`; that directive
has no effect in b210 and is absent from the final source. The diagnostic's
completed object was analyzed without recompilation using an explicit scratch
symbol mapping, recorded in `table-binding.json` beside that diagnostic.

The two fallback queue fields use the field work object's integer-offset helper.
The index is scaled before adding the actual work address, preserving retail's
operand order without creating arithmetic from an integer-cast nonobject pointer.
There are no artificial calls, volatile accesses, assembly, padding or undefined
locals introduced to obtain the match.

## Provider and sibling contracts

The owner-local declarations now express the actual formatter and logging
providers' variadic argument lists and integer returns, the memory fill provider's
pointer return and unsigned byte count, and the field-work getter's `s32 *`
return. Existing work-getter callers retain byte-offset arithmetic through an
explicit byte view. The formatter takes a character destination, and the log's
format/file pointers have explicit character views. Complete provider assembly
and current scene/file-provider sources are retained in `contracts/`.

The remaining guarded `0014f310` body was also compiled before and after these
declaration corrections. All twenty functions other than the intentionally
recovered `0014efc0` retain their complete code and relocations; all allocated
data remains unchanged. `resource/guard-provider-contracts.json` binds these
two completed objects. This check does not claim that `0014f310` is a native match.

## Validation and identities

The configured logical owner uses MWCCPS2 b210 with `-O2 -Iinclude` and the real
R5900/EABI assembly context. Current dependencies were authenticated against the
already completed motion-contract owner. Its 21 functions were re-proved and its
object reused as the baseline; no baseline compilation was repeated.

The final source was compiled as a complete owner. The character-destination
declaration correction and review comments preserve the preceding exact native
object byte for byte. The unchanged official verifier reused that source-bound
object and reported 20 MATCH / 1 ASM. Scoped lint and
`git apply --check --whitespace=error-all` both exited zero. Full builds and
global test suites were left to prime. No runtime consumer test is claimed.

| Artifact | SHA-256 |
|---|---|
| Current owner before this recovery | `872d62d3115e1d769d3d5a22ae799c65e2bd5df3dcf787b8d495a6972151c8c8` |
| Final proposed owner | `5ecaf9137ec3d9dfe50f4af508ab93b04ee853ec2c476369a6625ed8d63f7bd5` |
| Final native owner object | `8636c48354b0ed7955e7fe2cb071b8dd094d406ce084273d6c34f16e9ba70345` |
| Resolved target bytes | `1290e9b8a0f5c544104b92e4992e0e2b34d698bdb47c7df1cd8c71495310a520` |
| Compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

The integrated `0016b8a0` ray owner was left intact. The separate sphere-query
mode-one acceptance hold and the dynamic-query twelve-word frontier are unchanged.
