# 0023e6f0 hit/evasion recovery — 2026-09-20

The live `src/Main/Battle/Data/datCalc.c` owner now reports **79 MATCH / 1 ASM**.
`func_0023e6f0` emits **10920 bytes**, equal to every retail code byte, followed
by the retail window's **eight zero alignment bytes**. All **325 instruction
relocations** resolve without masking. This function adds no owned data.
All 79 other function bodies, their relocation identities, and existing
allocated data remain unchanged. The remaining ASM is `func_00235520`.

## Durable evidence

All paths below are under `build/first-party-next/datcalc/`.

- `worker2-hit-v6/shared-result/`: first exact source/object and resolved proof.
- `worker2-hit-release-final/`: helper reuse, obsolete-note removal, final source,
  compiler receipt, resolved proof, reviewed `integration.apply_patch`, and
  before/after hashes in `integration.json`.
- `worker2-hit-live/`: official live owner source, complete immutable inputs,
  object, compiler command/log, official report and receipt.
- `worker2-hit-live/closure.json` and `resolved/`: release proof from that actual
  official object, including the modifier provider and sibling/data comparison.

Original live owner SHA256:
`e59acb419dcd7bc5e618ff0cd099fd18a09fc6995ad1babee8d77dc8fd137ccb`.

Integrated live owner SHA256:
`c2fe74bc31885c5a296aa322dde485f96ae5640fc09b8c097141fae40769b2ce`.

The actual configured b210 owner compiler and frozen include set were used.
`live_owner.py` captured the official verification with the normal owner lock;
its manifest was unchanged during the run. No full-tree/image build, commit,
rebase or push was performed.

## Faithful C mechanisms

The sixteen expanded skill searches use the existing eight-slot
`DC411SkillTable` / `DC411HasFixedSkill` helpers. Their bodies were moved before
the earliest consumer, not duplicated. Equipment checks reuse
`DC411HasEquipmentProperty`; the counter's per-unit count wrapper returns u16.
Signed metadata reads and native byte/halfword assignments preserve retail's
flag checks and element conversions. Unsigned table indexing keeps the skill
mask distinct from signed validation. A shared cause variable spans counter and
evade paths, and the two immediate success cases share an explicit result exit.
The low-status and equipment category checks retain their ordinary C switches.
All floating-point multiplication order, including the original neutral hit
multiplier, is retained.

The hit function keeps an explicit s32 call interface and uses a compatible
C89 identifier-list u16 skill formal. `func_00233bc0`'s unused third parameter
is now consistently u16 in its definition and the guarded damage declaration.
Its executable callers are only the four damage and two hit sites in this owner;
all pass a skill ID. The provider itself resolves exactly: 1280/1280 bytes and
23 relocations. No external owner/header edits are required for this closure.

## Probe cautions

Retained `hit.py` baseline/halfwords/skills/equipment/loop-invariants receipts
were reused. The first `worker2-hit-v2/*` decoder outputs were invalid because
Python `-s` hid Capstone and `fnalign` silently emitted `??`. The objects and
direct comparisons were valid; the `decoded/` subdirectories reanalyze the same
objects with decoder availability asserted. See the adjacent
`DIAGNOSTIC_NOTICE.md`. Later drivers assert decoding before use.

`worker2-hit-v6/switch-result/` is a retained syntax-error experiment. It did not
affect the exact `shared-result` sibling or the live integration. The queued
pragma experiments after that failure were not run; no further sweep was needed.

Agent routing returned `AGENTS_BUSY: no agent family belongs to this conversation`
when reporting to `prime`. This is a routing limitation only; the source and
all evidence above are durable in the shared workspace.
