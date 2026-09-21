# DatCalc remaining-owner closure — 2026-09-20

`src/Main/Battle/Data/datCalc.c` now reports **80 MATCH / 0 ASM** under its
configured MWCC b210 owner profile. Both targets assigned to worker-2 are live C.
The already integrated `00238940` and `0023a6b0` recoveries were preserved.

| Function | Exact code bytes | Retail window | Code relocations | Owned data |
|---|---:|---:|---:|---|
| `00235520` damage/HP-SP calculation | 12176 | 12176 | 363 | 17 entries / 68 bytes at `00747bc0`, plus four zero bytes in the reserved window |
| `0023e6f0` hit/evasion | 10920 | 10928 | 325 | None; eight zero bytes complete the code window |

All instruction relocations and the damage table's 17 relocations were resolved
and compared without masking against retail. Both proofs use the actual final
official live-owner object. The unused skill formal correction in `00233bc0`
also resolves exactly: 1280/1280 bytes and 23 relocations.

The 78 functions outside these two recoveries retain their original bytes and
relocation identities. All pre-existing allocated data is unchanged. The only
new allocated data is the damage effect table. Between the hit integration and
damage integration, all 79 non-damage functions remained unchanged.

## Final source and receipts

The final live owner SHA256 is:
`1b9591a919c9d39de3c72f542aa7a008e2726b92db16d7c4524764450fe82dd0`.

The preceding, fully proved hit integration was:
`c2fe74bc31885c5a296aa322dde485f96ae5640fc09b8c097141fae40769b2ce`.

The original retained owner before either worker-2 recovery was:
`e59acb419dcd7bc5e618ff0cd099fd18a09fc6995ad1babee8d77dc8fd137ccb`.

All evidence below is under `build/first-party-next/datcalc/`:

- **`worker2-damage-live/closure.json`** is the final release entry point. It
  joins the official result, both unmasked target proofs, provider proof,
  table proof, original-owner comparison, input manifest and source hashes.
- `worker2-damage-live/` contains the actual source, object, frozen input set,
  configured compiler command/log, official report/receipt and lint report.
  `resolved/` contains the linked code/table bytes and detailed relocation
  records. `release-proof.json` also records the table's four-byte zero suffix.
- `worker2-damage-release-final/` contains the reviewed integration delta,
  before/after hashes, prepared source and independent owner proof.
- `worker2-damage-v7/sum-helper+kind-narrow/` is the first fully exact candidate.
- `worker2-hit-live/` and `DC_worker2_20260920_hit_recovery.md` preserve the
  independent earlier hit closure.

`worker2_datcalc_closure.py` rechecks the saved official object and source. It
does not compile again. The official manifest remained unchanged during the
live compiler run. Source lint completed with **zero errors and five H003
optimization-provenance advisories**; those pragmas have measured owner evidence.
`git diff --check -- src/Main/Battle/Data/datCalc.c` passed.

## Recovered C and contracts

The damage draft's lost/misidentified case labels, byte skill reads, and float
bit-pattern clamps were replaced from the complete retail control flow. HP
uses effect/power fields `0x11/0x12`, current HP at unit `+8` and `00231f80` for
maximum HP. SP uses fields `0x14/0x16`, current SP at `+10` and `00232290` for
maximum SP. Both paths initialize the signed bonus to zero, as retail does.
The effect table has 17 cases. Final result class 16, independently of the
earlier effect value, supplies the fixed 500 damage path.

The implementation reuses the actual general skill-count/table search in
`PTDatCalcHasSkill`; damage does not use hit's fixed-eight specialization.
The existing equipment-count and weapon/armor-property helpers were moved
before their earliest consumer, retaining their bodies. Accessory property
and percentage helpers preserve the retail diagnostic checks, signed item
conversion and native word-to-float conversion. Float multiplier order and
integer clamp/randomization order follow retail exactly.

The final narrow skill-kind lookup and signed base-plus-bonus helper retain
normal data operations. Staging the constant base of 50 before adding the
bonus preserves the same arithmetic path as the variable-base cases. Unsigned
channel dispatch keeps that conversion independent of the signed fifth
argument to `00244f60`. Declaring the result locals after the arithmetic work
local reproduces the retail register assignment. No copied assembly, fake
side effects, forced volatile accesses or explicit padding were introduced.

The damage function's visible call interface uses promoted word integers.
Its compatible C89 identifier-list definition retains the real u16/u8
formals. Internal callers still emit the same code. The promoted external
callers use pointer-valued arguments and default integer promotions.
One pre-existing external caller owner needs the small typed-pointer cleanup
described below; it was not silently edited outside this lane.

## External caller proposal for prime

`worker2-damage-caller-proposal/external.apply_patch` is a complete, reviewed,
**unapplied** delta for `src/Battle/btlAICommand.c`. It gives `00235520` the
promoted prototype and explicitly converts the six unit pointer payloads in
its three legacy calls. The source previously passed these payloads as raw
u32 integers through an unprototyped declaration.

Exact external owner **before** SHA256:
`3d49a1f953a980aae76f0300fcd2ba6ec60fda683af84a691542b25e8e3951df`.

Prepared **after** SHA256:
`425af19b9dce8ce0b2dc8094b3e35ffcdc4f39d4b10b660010dd7a10b846d76b`.

The actual configured battle-AI owner compiler built frozen before and after
sources. All **263 function bodies, their relocation identities, and all
allocated data are unchanged**. `proposal.json`, `comparison.json` and the
two compile receipts record the commands and object/source hashes. The live
external owner was checked unchanged after the comparison. Prime may apply
this delta only after confirming its before hash against the current owner.

## Retained experiments and boundaries

Baseline and each native candidate are immutable in `worker2-damage-v1` through
`v7`. The initial `repaired` mode failed before compilation because its assumed
decompiler case spelling did not match the saved draft. It is not a valid
candidate or a basis for the final case mapping. The later native template was
checked directly against retail and the IDA/Ghidra exports.

Native progress moved from 544 aligned differences to 450 after the promoted
contract, 395 after unsigned channel dispatch, 42 after declaration ordering,
14 after staged constants and final switch, then zero with the native lookup
and addition helpers. Object sizes alone were never used as match evidence.
The normal Python environment was used with an asserted working decoder.

No external owner was changed by this worker. No commit, rebase, push,
full-tree build or image build was performed. All compiler commands finished
and released their owner locks. `agents action=message to=prime` repeatedly
returned `AGENTS_BUSY: no agent family belongs to this conversation`; the
source, final receipts and external patch remain durable in the workspace.
