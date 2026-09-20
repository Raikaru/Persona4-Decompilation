# shdSkill 001138c0: argument phases and concrete wide-rank rejection

Measured 2026-09-20 at rebased HEAD
`000fca07c5203f373cb6035ef3654df61bf3c614`. No production source was changed.
The canonical `s32` skill contract remains four resolved words short in
`func_001138c0`; none of this lane's experiments is a promotion candidate.

All new scripts, complete-owner source snapshots, objects, compile logs, input
receipts, and proofs are under:

`build/first-party-resume-final/worker3-shdskill-eval/`

The final evidence is `complete_owner_proof.json`. This lane contains thirteen
completed objects and one deliberately retained failed width assertion. It
adds five argument-phase experiments to the earlier 81 shdSkill measurements,
then separately checks two concrete wider contracts and the target's `long`
width. These counts include no claim that the search space is exhausted.

## Recovered state

Read the current complete owners, shdSkill retail and available IDA/Ghidra
targets, `DC_worker3_20260920_recoveries.md`, both earlier shdSkill contract and
promotion notes, `Query_001da5f0_wide_provider_167e607.md`, packet-worker5's
release, and the saved `status/00238940` measurements before probing.

The query `001da5f0` closure remains recorded as exact. Packet-worker5's release
still reports `0020b6d0` at three aligned edits under the wide provider: a
missing preheader halfword mask and the temporary at `sp+0xde` instead of
`sp+0xd0`. Its separate exact correction of the `00452560` task-pointer
contract was measured with the narrow provider. This lane did not modify or
remeasure that packet owner.

The saved `status/00238940/existing-narrow-provider` result is still 3728 bytes,
two words/two edits; its `input-u16` and `input-s16` alternatives regress to
120 and 132 aligned edits and change other functions. The existing exact wide
`00238940` source remains staged in its earlier archive, pending caller closure.

## Fresh canonical proof

`lane.py` compiles the complete current owner using its logical owner profile:
MWCC PS2 3.0.1 b210, `-O2 -Iinclude`. Completed objects are reused only after
source, object, relevant header, compiler binary, and configuration fingerprints
match their receipts. The compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

The fresh source/object hashes reproduce the earlier narrow and canonical wide
artifacts:

| Artifact | SHA-256 |
| --- | --- |
| Current shdSkill source | `975774045f344a736c1184b1271c54a63694fa14894ddacdfe3ca6004fd650e0` |
| Current shdSkill object | `be3c85569dd5e7d872a0370a9b9135bd7b1a93bb2a9c602df61f069fb3508699` |
| Canonical wide source | `bf2088723a9e2b585f5d3f8afb038278c025c35f4717327ee258edbd91c79301` |
| Canonical wide object | `52498134211899a4651e9f689ecb87b8f8e59f0e05220c67cf4b66d9d38e9935` |

`finalize.py` independently resolves all fifteen baseline functions and all
fourteen unchanged wide siblings against retail, including the 80-byte,
20-entry table owned by `00114cb0`. All allocated shdSkill data is preserved.
The wide caller emits 1384 bytes in its 1392-byte window, has 23 resolved
relocations, and omits only eight zero bytes. Its entire residual is:

| Offset | Retail | Canonical wide |
| --- | --- | --- |
| `+0x218` | `ld a0,0xd0(sp)` | `lhu a2,0xa(s5)` |
| `+0x21c` | `mov.s f12,f21` | `ld a0,0xd0(sp)` |
| `+0x220` | `lw a1,0xdc(sp)` | `mov.s f12,f21` |
| `+0x224` | `lhu a2,0xa(s5)` | `lw a1,0xdc(sp)` |

The texture load and following `jal func_00114dc0` remain in place. Frame size
and the rest of the function remain unchanged. No relocation masking is used
to call this residual exact.

## New argument-phase mechanism

The retail sequence and the handoff's argument-materialization rule motivated
moving the narrow-to-`s32` promotion into a consumed earlier value phase. The
new submission record carries the **promoted skill value**, whereas earlier
address records carried the descriptor pointer and left conversion in the
final draw expression. Its five members are all actual submitted values or
addresses of actual position/color objects; no padding local or dummy work is
introduced. `expression_forms.py` preserves canonical query and both wrapper
formals throughout.

| Complete-owner variant | Target bytes | Resolved differing words | Aligned edits |
| --- | ---: | ---: | ---: |
| `mode_assignment_argument` | 1384 | 4 | 2 |
| `mode_statement` | 1384 | 4 | 2 |
| `promoted_submission_record` | 1424 | 225 | 24 |
| `promoted_submission_scalarize` | 1400 | 212 | 9 |
| `promoted_submission_propagate` | 1384 | 4 | 2 |

All five retain fourteen siblings and allocated data. Assignment through the
consumed `mode` formal is folded back to the original early halfword load.
The explicit record initially adds setup and unaligned aggregate-copy traffic.
Scalarization plus propagation eliminates that traffic but restores the same
four-word residual, so the promotion phase does not survive in the useful form.

`signature_census.py` also checks 11,154 retail assembly files for a halfword
load into `a2` preceded within nine instructions by `ld a0`, `mov.s f12`, and
`lw a1`, and followed within six by `jal`. Its only hit is this caller at
`00113ae4`. This bounded sequence census supplied no independent precedent;
it does not rule out differently shaped source or retail sequences.

## Concrete wider-contract diagnostics

`abi_forms.py` checks a coordinated query declaration and both actual wrapper
signatures in complete shdSkill copies. An unchanged wrapper result is then
checked against a complete datCalc copy containing the actual query definition
and declaration. The existing provider's retail masks at `0023d8f0` and
`0023d98c` motivate testing this hypothesis; equal callee bytes alone would
not establish a new project-wide declaration identity.

The fresh canonical `s32` query definition is independently exact at 208 bytes
with five relocations. All eighty datCalc function bytes/relocations and all
allocated data remain unchanged against its freshly compiled narrow baseline.
See `provider_s32/proof.json` and `provider_s32/owner.o`.

The coordinated `s64` shdSkill signatures preserve the fourteen siblings but
leave the same four-word caller residual. The actual provider grows to 224
bytes and differs in 49 resolved words: its masked index arithmetic becomes
`dsll`/`daddu` and needs explicit 64-to-32-bit normalization before pointer
indexing. `provider_s64/func_0023d8e0.diff.txt` records the precise mechanism.
This contract is rejected.

The coordinated `u64` signatures leave the caller unresolved and change
`00114cb0+0x10` from `slti` to `sltiu`. This wrapper regression rejects the
hypothesis before a provider experiment.

The proposed `signed long` 32-bit rank does not exist in this profile.
`contract_long32/compile.log` preserves the failed `sizeof(long)==4`
assertion. `long_width.py` successfully compiles the complete canonical wide
owner with assertions that `sizeof(long)==8` and `sizeof(s32)==4`; its object
is byte-identical to the canonical wide object. The failed compile is recorded
separately and is never treated as a completed object or matching evidence.

## Remaining prerequisite

An accepted source form must retain the canonical `s32` query/wrapper contract
and emit the descriptor halfword load after the position, float, and color
argument loads while preserving the fourteen siblings, their table, and all
other data. This lane has not found that form. `0020b6d0` remains separately
open at its saved three-edit wide-provider floor. No wide provider or caller
change from this lane has been installed.
