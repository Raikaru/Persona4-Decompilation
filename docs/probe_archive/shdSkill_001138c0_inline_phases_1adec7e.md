# shdSkill 001138c0: consumed inline argument phases

Measured 2026-09-20 at HEAD
`1adec7e926b81497a86b3a4238ba57edfb780c2b` by worker-2. The canonical
`s32` provider prerequisite remains open. No production source was changed.

The complete evidence is under:

`build/first-party-resume-continue/worker2-shdskill-prereq/`

`complete_owner_proof.json` records eleven complete-owner objects, nine new
proposals, independent unmasked function and data proofs, compiler/input
fingerprints, and the scoped official verifier results. The best retained
source is `wide/shdSkill.c`; it is a measured unsuccessful proposal.

## Starting evidence

Read the current complete shdSkill owner and its callers, the retail target
and forwarding wrapper, IDA and Ghidra references, STYLE.md, and the previous
wide-contract, promotion, and argument-phase notes. Also read the query final
proof and packet-worker5 release before probing.

`archive-audit.json` checks 114 saved `shdSkill.c` copies across the original
first-party lane and the three resume roots. None with the canonical `s32`
query declaration and both `s32` forwarding wrappers had a saved zero-target
comparison. This is a bounded archive audit, not a claim about unrecorded
source forms.

The new lane freshly compiled the current narrow owner and the canonical
wide owner with the logical `src/shdSkill.c` profile: MWCC PS2 3.0.1 b210,
`-O2 -Iinclude`. Each proposal retains its complete source, object, compile
log, compiler receipt, relevant input fingerprints, comparison, decoded
target, and resolved target bytes. Relevant headers and configuration are
also copied into `inputs/`.

## New mechanism and measurements

The previous simple inline adapters retained the original argument order.
This lane instead tested whether an inline boundary consuming the actual
inputs in a different order would preserve the stored halfword as a later
argument phase. The real external query and both forwarding wrapper skill
parameters stay `s32` in every proposal.

| Proposal family | New complete owners | Target bytes | Resolved differing words | Aligned edits |
| --- | ---: | ---: | ---: | ---: |
| Stored `u16` input first or last in an inline submission | 2 | 1384 | 4 | 2 |
| Stored skill address first or last in an inline submission | 2 | 1384 | 4 | 2 |
| Common-subexpression or propagation control scoped to the inline helper | 2 | 1384 | 4 | 2 |
| Actual typed callback first or last in an inline submission | 2 | 1384 | 4 | 2 |
| Actual typed callback retained in a target-local variable | 1 | 1392 | 213 | 7 |

The eight inline proposals preserve every canonical-wide function's raw
instructions and canonical relocations, plus all allocated data. Their ELF
files are not byte-identical: the only differing section is `.strtab`.
`inventory-inspection.json` distinguishes this container metadata from the
unchanged executable and allocated contents. An initial whole-object-identity
assertion in the finalizer was too strong; the independent function and data
comparison supplies the actual result.

The callback local retains the correct complete function-pointer type,
`void (*)(Vec2f, f32, Color4, s32, s32)`. It introduces a function-address
`lui`/`addiu` pair and changes the direct `jal` to `jalr`, while still loading
the skill early. Its shifted residual is 213 resolved words, corresponding
to seven aligned edits. It preserves the fourteen siblings and allocated
data but supplies no useful improvement.

No newly tested inline phase changes the external formal order. The earlier
coherent float-position experiments already covered every source order that
preserves the wrapper's integer register roles and left caller and wrapper
differences. The current boundary already carries genuine position and color
aggregates. The prime's separate aggregate-last HBN result does not by itself
establish a new shdSkill ordering: placing color after skill or texture would
change their retail `a1`/`a2`/`a3` roles.

## Exact remaining difference

The canonical wide target emits 1384 bytes in its 1392-byte window. All 23
code relocations resolve to their actual destinations; the omitted eight
bytes are verified zero alignment. Its full unmasked residual remains:

| Target offset | Retail | Canonical wide |
| --- | --- | --- |
| `+0x218` | `ld a0,0xd0(sp)` | `lhu a2,0xa(s5)` |
| `+0x21c` | `mov.s f12,f21` | `ld a0,0xd0(sp)` |
| `+0x220` | `lw a1,0xdc(sp)` | `mov.s f12,f21` |
| `+0x224` | `lhu a2,0xa(s5)` | `lw a1,0xdc(sp)` |

The texture load, direct call, frame size, and remaining instructions agree.
All fifteen baseline functions and all fourteen wide siblings were separately
resolved against retail. This includes the complete 80-byte, 20-entry table
owned by `00114cb0`. All allocated shdSkill data is preserved.

The official frozen-baseline verifier reports **15 MATCH**. The official
frozen-wide verifier reports **14 MATCH / 1 MISMATCH**, with `001138c0` as
the sole mismatch. Both frozen compiler commands were checked against the
logical owner's command, differing only in the source path. The successful
finalization command is recorded as terminal session `34060`, exit zero;
the wide verifier's own expected exit status is one.

## Query, provider, and packet handoff

The saved query closure remains available at:

`build/first-party-resume-167e607/query/final/code1_001d.c`

Its source and object receipt hashes were read back, and `001da5f0` was
independently resolved again: 76 executable bytes in an 80-byte window,
one call relocation, and four verified zero bytes. The saved complete
94-function owner object remains byte-identical to its saved narrow baseline.
This is a revalidation of the archived object, not a new current-owner compile.

The saved canonical provider object at
`build/first-party-resume-final/worker3-shdskill-eval/provider_s32/owner.o`
was likewise revalidated against its immutable source receipt. Its full
208-byte `0023d8e0` body resolves exactly, and all eighty function bodies,
canonical relocations, and allocated data agree with the saved narrow
provider baseline. Neither provider source nor packet source was compiled
or edited by this lane.

Packet-worker5's saved release still reports `0020b6d0` at 808 bytes in an
816-byte window and three aligned edits: the preheader halfword mask is
absent, and the halfword store/load use `sp+0xde` instead of `sp+0xd0`.
That packet result was read, not remeasured. Its separate task-pointer
correction was exact under the narrow provider and does not close the wide
contract.

The archived exact `00238940` source therefore still depends on shdSkill
argument-phase closure and packet closure. This lane supplies a measured
limit and preserved evidence, with no additional source ready for integration.

## Artifact entry points

`lane.py` creates the archive audit and the two baseline measurements.
`inline_phases.py` and `callback_phases.py` generate the nine new proposals.
`inspect_inventory.py` checks executable equality separately from ELF metadata.
`finalize.py` resolves the full owner, invokes both scoped official gates, and
revalidates the archived dependency objects. Completed sources and objects
are reused only after their receipt hashes and relevant inputs agree; a
completed final proof is never replaced.

The source/object directories, `proof/`, `official-baseline.{json,log}`,
`official-wide.{json,log}`, and `complete_owner_proof.json` contain the
reviewable measurements. Ownership of shdSkill/query scratch work is released
with this handoff.
