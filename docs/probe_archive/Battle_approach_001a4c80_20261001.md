# Exact battle approach controller and coherent prerequisites

Baseline: `a78c378b3da3cc826aea3c66462ee1f07f287759`.

## Scope and exactness

`func_001a4c80` is now C-linked source: its complete owning translation unit
verifies **2,336 bytes**, **0x120-byte stack frame**, zero normalized differences,
and all **51 relocations resolve independently to retail**. The owning file
reports **69 MATCH / 2 ASM**. Only this target's assembly fallback is removed.

Nine complete affected owners report **774 MATCH / 10 ASM**, across 784
functions. Comparing objects compiled from the exact main baseline and this
tree preserves **783 function bodies, sizes and relocation destinations**.
All eight prerequisite owners preserve every allocated section and relocation;
the approach owner preserves its other 70 functions and every non-text
allocated section and relocation. Local compiler symbols are normalized by
section identity, value and size rather than by unstable anonymous names.

The existing rank-2 and rank-8 guarded recovery statements remain the main
versions. Only their conflicting declarations of the migrated ABI family are
removed. Neither separately developed guarded recovery is imported. Their
production assembly fallbacks stay active. The fixture's complete action/hit
view is isolated under `tests/battle_approach_action_fixture.h` and does not
introduce a production dependency on those recoveries.

Evidence: [per-owner preservation and resolved references](Battle_approach_001a4c80_20261001/preservation.json),
[whole-owner verification summary](Battle_approach_001a4c80_20261001/verification.json).

## Selector recovery and real provider contracts

The two motion locals use the real `u16` provider domain. Under the coherent
provider header, the former `s32` locals produced 2,340 bytes and an extra
narrowing instruction. The u16 locals reproduce all 584 retail instructions,
including the formerly unmatched `daddiu` selectors 7 and 5. No target-local
prototype override, wide temporary, padding, undefined shift, new pragma,
or synthetic branch is involved.

The existing scoped lifetime and dead-assignment settings are retained with
push/pop. Source names now describe the destination, actor/target centers,
quaternion, subunit, skill offset, range predicate and speed selection. The
nested range cases and alternate speed branch already exist in retail; none
was added to fill an instruction window.

### Minimal coherent dependencies

The declaration/provider changes are inseparable from this exact recovery:

- `btl_motion_internal.h` gives one unsigned-halfword selector domain to
  `001990d0`, `001991c0`, `00199350`, `00199500`, `001996d0`, `001999f0`,
  `00196bd0`, `0022cb90`, and `0022cf00`. Six animation providers pass both
  actual arguments to the boss override; the real override result is signed
  word with each consumer's existing halfword conversion preserved
- Both distance providers retain that same motion domain. The `0019ae20`
  selector local is u16, and `001999f0` retains the separately normalized late
  unsigned-halfword index. The requested selector is not confused with the
  overridden animation index
- `btl_skill_target_internal.h` and the motion header define the signed
  halfword skill/motion family: `00199d00`, `001f11e0`, `001f1210`, and
  `0022fa90`. All definitions, callers and declarations migrate together.
  `0022f950` supplies the real action to its paired query and reloads the
  skill after that query; scoped propagation preserves its retail order
- Canonical declarations are used in `code1_0019.c`, `code1_001a.c`,
  `code1_001b.c`, `code1_001c.c`, `code1_001f.c`, `code1_0022.c`,
  `Battle/btlCamera.c`, `Battle/btlUnit.c`, and `Battle/btlFormation.c`

The signed-identifier and motion provider/caller changes are isolated and
freshly reverified against the stated main baseline. Their unrelated
large guarded recoveries, six-factory return patch, and later guarded
follow-ups are excluded. Existing `00195730` packet-return and payload
contracts were already on main and require no unrelated factory changes.

## Evidence-backed link alias

The first aggregate build reproduced both retail hashes but rejected the entire
approach owner because `fGpffff8360` was absent from the address map. The exact
rejection was its R_MIPS_GPREL16 reference at function offset +0x7e8. Function
bytes, object placement and owned-data planning all passed; silently accepting
the assembly fallback would have lost all 71 owner windows from C linkage.

Retail instruction `001a5468` is `lwc1 f0,-0x7ca0(gp)`. GP is `007690f0`, so
the load names `00761450`; its bits are `3fb33333` (1.4f), followed by the speed
multiply. The maintained `tools/recover_symbols.py --print` independently emits
`fGpffff8360 = 0x00761450; // type:data`. Only that generated definition is
included, with no curated override and no unrelated regeneration churn. The
new alias test checks the verified retail instruction, float and following
multiply, and rejects neighboring addresses and a 64K displacement error.
See [alias evidence](Battle_approach_001a4c80_20261001/link-alias.json).

## Actor, UID, payload, and live-state evidence

- `0019f5f0` creates action actors in cases 0 and 1 through `0019d210(0/1)`
  and `btlActionSetUnit`. `0019d210` stores that kind at unit +0xa2. Kind 2
  is separately created for the subunit at actor +0xa0c. The non-ranged switch
  uses this admitted actor domain; invalid actor kinds are not given invented
  initialization behavior
- The table at `0x005f6e20` uses `001a4c80` as state 0x10's initializer and
  `001a55a0` as its update. `001a4800` enters that state through `0019fc70`.
  Missing selected targets and failed allocation are not newly handled here
- Action UID at +0 and packet action UID at +0x60 are doublewords. All six
  static attachment sites preserve their `ld`/`sd` operations and reload the
  action UID after allocation. Queue selection is a word, not part of the UID
- The initial skill is read as an unsigned halfword and supplies the cached
  four-byte flag-table offset. The flag-table pointer is reloaded after calls.
  Speed selection rereads the skill after `001a03b0`; later target accesses
  reread the current first target and its unit
- Unit y, scale, radius, kind and data are +8, +0x2c, +0x90, +0xa2 and +0xa64.
  The enemy stride remains the complete `unitId * 0xe8`. Speed halfwords are
  at +0x24/+0x28. Fixture assertions check the actual partial-view offsets
- Position is a real three-float object with array/vector views. Rotation is
  a four-float quaternion, fully written by `001ec1c0` and copied by the actual
  `00195730` constructor. No adjacent scalar storage is used as a buffer
- The first five speed values at `0x005f6d20` are 0.5, 0.75, 1.0, 1.5 and 2.0.
  The reposition multiplier at `0x00761450` is bits `0x3fb33333` (1.4f).
  The proof resolves GP, HI/LO and call targets instead of only masking them

## Behavioral validation

The new approach suite executes the installed controller and nine actual
provider definitions at O0 and O2 with real i386 pointers, undefined/bounds
sanitizer traps and an explicit QEMU runner. It does not rewrite the target
for host pointer width or API compatibility.

**69 scenarios and ten negative controls pass at both optimization levels.**
Coverage includes entry suppression; actor kinds 0/1; paired/critical flags;
motions 4/5/7/12; ranged classes 3/5 and distances 499/500/501; mixed-kind battle
exclusion; both placement gates and geometry thresholds; complete enemy-record
offsets; both enemy speed slots; position/quaternion payloads; 0x16/0x17 camera
states; high UID bits; and changed flag-table, skill and target at explicit
external-call boundaries. Every allocation, queue mode and final movement/
camera payload is checked. All five packet constructors, `00196bd0`,
`001f0bf0`, `001f0a50` and `00243d80` are extracted from actual source.

The mutations reintroduce narrow UIDs, incorrect motion, speed/enemy strides,
three-float quaternion copies, unsigned opening conversions, wrong camera
state, stale skill, an inclusive range boundary, or wrong queue selection.
Allocation, geometry, queue execution and unrelated queries remain recording
boundaries. Stored callback identities are not executed. Opening-result sign
boundaries are deliberate external-input conversion stress; the production
selector itself returns small values. This is not a gameplay simulation.

The included real-provider suites also pass at O0/O2:

- Four motion tests: 86,400 timing/override and 21,120 distance cases per
  optimization, plus eight missing/wrong-selector mutations
- Three signed-opening tests: 122,139 cases per optimization, wide-ABI
  compilation rejections, and result/boundary/live-state mutations

The nine-source scoped lint run reports **zero errors**, with 173
owner advisories outside the recovered target. The final ordinary repository suite reports **863 tests, OK with 28 skip
records**. Native-runtime skips are not passes; the three relevant suites were
run separately under QEMU after the alias addition. All 43 pragma spellings
across 42,272 uses are recognized. The new alias suite passes three tests and
the existing recovered-symbol suite passes 17 tests.

The final `make build-progress` passes both full retail hashes with the target
owner actually C-linked: 604 C objects plus 54 SDK objects, 658 linked units
and 8,586 linked windows. Every prior membership record remains present; no
unit or function window is lost. The target owner contributes all 71 of its
prior windows, now with an exact C body at `001a4c80` rather than its fallback.
The loadable image SHA-1 is `3d1d3d2b9d6ccb60836db239ab49674223025a78` and the
rebuilt ELF SHA-1 is `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
See [final validation](Battle_approach_001a4c80_20261001/validation.json) and
[exact membership comparison](Battle_approach_001a4c80_20261001/link-membership.json).
Remote CI was not run during this local validation.

## Reproduction and release checks

Configure the licensed compiler/assembler and retail inputs according to the
repository instructions. Compile the nine affected owners with `tools/verify.py`.
The `capture_owners.py` helper in the evidence directory captures full objects
for an unmodified checkout of the named baseline and this tree; `audit.py`
compares those captures and independently resolves each target relocation.
The scripts accept checkout/output arguments and need no machine-specific path.

Run the approach, motion and signed-opening tests with the supported native32
runtime. On an execution host requiring emulation, use an explicit i386 QEMU
runner rather than treating a native-execution skip as a pass. Also run the
repository test suite, lint and pragma checks, `make build-progress`, and the
retail-hash checks. Confirm `code1_001a.c` remains C-linked in the generated
linked report. Repeat those gates after any rebase, merge or declaration change.
Remote CI must validate the exact published commit separately.
