# Guarded Battle result storage and observed HP calculations

Base: `e324dcafd9c8f5d6e31e3a7aa1be3c2f66c04b6c`.
The two controllers remain guarded assembly fallbacks. This repairs bounded
source contracts; it does not promote either function or claim gameplay proof.

## Recover the real object, rather than adjacent scalar names

The existing `LargeBattleHitResult` layout is now file-scoped so both guarded
controllers can construct the same 32-byte payload that they consume from
an action's hit records. Its fields/layout are unchanged. The 59a0 draft's
`sp2E0`/`sp2E8` and 7720 draft's `sp550`/`sp554`/`sp558` were independent
scalar locals, not one object. A four-byte local is not valid storage for the
actual clear/copy providers, even if another name suggests a nearby offset.
Each is now one `LargeBattleHitResult result`.

Retail evidence establishes the full extent:

- `func_001f0a10` clears 32 bytes using the incoming pointer
- `func_001f36e0` allocates 44 bytes, copies 32 result bytes to work+8,
  and writes two flag halfwords after that payload
- `func_00201de0` allocates 60 bytes, also copies the entire 32-byte result,
  then writes display ID, effect/target flags, hit index/count and flags

59a0 clears SP+2E0, writes the status word at SP+2E8 and passes SP+2E0
at `001A6284..001A62AC`. 7720 reuses SP+550 for three paths: transfer
HP/SP words, an HP adjustment, or the status-only word at SP+558. Both display
calls pass exactly SP+550 at `001AACA8` and `001AB320`.
The actual clear prototype is void(u8 *), reflected only in these guarded
bodies. No provider definition or production sibling changes.

## Two additional directly observed defects

The HP-transfer pointer at target-record-base+108 is a signed halfword.
Retail `001AAC30` executes LH, then stores its sign-extended value as the
result's full HP word. The draft instead read one unsigned byte. It now has
an `s16 *hpTransfer` and assigns `result.hpDelta = *hpTransfer`. The existing
SP-transfer signed-halfword expression becomes the result's +4 member.
The later nonzero test reads `result.hpDelta`, the same object copied by the
providers. The pointer assignment and deferred dereference retain their order.

The HP path at `001AB280..001AB28C` masks the returned HP to 16 bits,
subtracts one, negates, then stores: `-(HP - 1)`, or `1 - HP`.
The old draft grouped this as `-HP - 1`. The source now computes
`1 - (s32)(datCalcGetHp(...) & 0xFFFF)`. Its local declaration uses the real
u16(s32) provider type, whose retail body loads the halfword at unit-data+8.
All unsigned-halfword inputs fit the resulting signed arithmetic.

The two status-only paths now assign `result.addedStatus` at +8, preserving
retail constants 0x100000 and 0x80000. No status is written into a detached
scalar or a different result field.

## Executed contracts and controls

The fixture binds the actual four construction blocks, transfer pointer declaration and
assignment, two display-call expressions, result nonzero condition and result
type. It executes the actual unchanged clear, HP getter and both entire packet
factories. Only allocation and the never-invoked callback destinations are
controlled boundaries. Canary checks surround the source object and the
packet work areas; all 32 payload bytes and all written metadata are checked.

At O0 and O2, 196,610 cases cover:

- Every signed-halfword HP transfer with positive SP transfer, and every
  signed-halfword SP transfer with positive HP transfer. These meet the actual
  enclosing branch's positive-HP-or-SP precondition
- Every u16 HP getter value, including 0, 1, 255/256, 32767/32768 and 65535
- Both status-only constructions, all 24 hit indices across the transfer
  cases, and varying full-halfword hit counts

Ten negative controls reject byte/unsigned-halfword HP loads, wrong HP
subtraction grouping, both wrong status offsets, short clear, short target or
display copies, byte HP getter, and undersized source storage. The undersized
case fails its extent check before any out-of-bounds provider operation.

The two existing hit/predicate fixtures only change where they extract the
same layout after it moves to file scope. Their test data and expectations are
unchanged. Together with the vector, timing, animation, UID, opening, motion
and approach families, **44 tests pass without skips**.

These are actual source fragments/providers, not whole-controller execution.
The surrounding queue logic, other provider calls and remaining undefined
shift expressions are outside this checkpoint. In particular the adjacent
packet-delay draft still needs separate reconstruction; this result proof
does not certify its timing. The tests are native i386 contracts, not a PS2
runtime or FPU emulator.

## Binary preservation and limits

All eight baseline/final configurations compile: production, either guarded
controller alone, and both together. Production objects are byte-identical;
70 unaffected functions are preserved in each single-guard build, 69 in the
both-guard build. All 148 allocated data bytes and 36 allocated-data references
are unchanged.

The audit pins 52 decisive retail instructions. In the rebuilt body it also
checks the actual LH and full-word HP/SP stores, 1-minus-HP subtraction, and
status +8 store. All ten direct stack-result clear/consumer calls are checked:
each controller passes one aligned 32-byte object, at SP+440 in 59a0 and
SP+660 in 7720, inside their respective frames.

The five relevant caller/provider owners verify **403 MATCH / 3 ASM**:
69 MATCH / 2 ASM in code1_001a, and 334 MATCH / 1 ASM across the unchanged
provider owners. The remaining provider-owner fallback is the already guarded
hit generator; all four providers executed by this fixture remain MATCH.
Missing generated assembly in the new worktree was restored from the audited
corpus before the final successful owner run. Lint remains 0 errors and 24
existing warnings.

Measured nonmatches become 7,860 bytes / 5,962 differing bytes / frame 0x480
for 59a0, versus 7,852 / 5,944 / 0x450 at base. 7720 becomes 17,416 bytes /
12,861 differing bytes / frame 0x6A0, versus 17,400 / 12,850 / 0x690.
These changes establish valid objects and observed calculations, not match
credit. No aggregate image gate, remote CI, gameplay test or push is claimed.

## Reproduction

With the configured licensed toolchain and hash-validated retail:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_result_storage_20261003/audit.py proof/result-replay
python docs/probe_archive/Large_Battle_result_storage_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c src/promoted/code1_001f.c src/Battle/btlTarget.c src/promoted/code1_0020.c src/datCalc/datCalc_grouped.c
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit the explicit runner only on hosts with working direct i386 execution.
Runtime skips are not passes. The receipt records source/test fingerprints,
retail words, provider-owner verification, complete preservation and scores.

## Independent-review fixture tightening

The test-only follow-up after 20d7dc4a binds the s16 pointer declaration
directly from the guarded source and adds leading/trailing guards around both
packet work buffers. The prior fixture already guarded the source result on
both sides and checked trailing packet-work bytes, but did not have leading
packet-work canaries. No production C, oracle, scenario or control changes.
