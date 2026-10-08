# Guarded Model controller recovery: func_00471370

This is an improved **NONMATCHING** reconstruction, not a new match. The
production branch retains its `INCLUDE_ASM` fallback. Only the guarded body
and its explanatory comments change; no compiler table, shared header,
function marker, or other owner is changed.

## Recovered contracts

- Matrix values occupy complete 64-byte `RwMatrix` objects, including flags
  and padding. Quaternion values occupy 16 bytes; the interpolation cache is
  40 bytes with `omega` at offset 32. Compile-time layout checks are in the
  guarded body. Copies retain complete values rather than inventing scalar
  aliases or live-pointer substitutions.
- Model/controller halfword views scale their indexed accesses correctly.
  Keyframe quaternion components come from offsets 8, 12, 16 and 20.
  The keyframe callback receives a matrix and keyframe pointer.
- The parent stack retains 31 entries. Its two control bits dispatch as a
  four-way operation; both bits set leave the parent unchanged. This does
  not establish safe underflow or initial values in unwritten slots.
- Desired yaw is completed before the independent pitch phase. Arithmetic
  grouping and negated comparisons preserve the observed unordered paths.
- The blend-duration reader uses the float written at control + 0x34, rather
  than numerically converting its integer bit pattern. The matching writer
  is `func_004740c0`; retail reads this field at 0x00472dd0–0x00472de0.
- Hierarchy modes 0x1000 and 0x4000 are derived from the original entry flags
  before node callbacks and reused during publication. Retail producers are
  at 0x004716d0–0x004716dc; corresponding consumers are at 0x004728c0 and
  0x00472920. This preserves snapshot lifetime if hierarchy memory changes.

The superseded target-local `opt_common_subs off` and `opt_propagation off`
directives are removed; the reviewed candidate uses canonical owner settings.
The existing pragma push/pop, NONMATCHING marker and production fallback stay.
No register search, padding, assembly transcription or synthetic ABI is added.

## Measurements and limits

The independently replayed 2026-10-08 checkpoint measures 7,084 candidate
bytes against 7,104 live retail bytes, a 0x550 frame on both sides, and 812
unit-cost Levenshtein edits on words after resolving references. Positional
word differences are 1,668; these are different metrics. A matching frame
and near-equal size do not establish a matching function.

Across the accepted incremental checkpoint, all 124 C siblings and 11 owned
data sections were preserved, references resolved without errors, repeated
objects were identical, and the 77 direct / 1 indirect call sequence was
preserved relative to its prior candidate. This is not a claim that its call
order equals retail. The production-guarded object was byte-identical.

The retained text-only research archive is identified by SHA-256
`b88438d5b4b90d36bb11aaa7351eae31e0cf62c87b30bc3aedb63228b268fe93`.
It is not required for these repository tests and is not bundled here.

Unwritten retail matrix flags/padding and the conditionally assigned
`iStack_450` remain explicitly qualified in source. Whole-owner behavior,
actual callback aliasing and EE exceptional floating-point behavior are not
proved by host tests. No initialization was invented to erase those limits.

## Reproduce the repository checks

With ordinary Python and a host C compiler:

```
python -m unittest discover -s tests -p test_model_controller.py -v
python tools/decomp_lint.py src/Graphics/Model/mdlManager.c
```

The source tests check guard, storage, field and snapshot contracts in the
actual owner. Five small C witnesses under `tests/fixtures/model_controller/`
cover value transfers, parent dispatch, angle graphs/predicates, float blend
duration and hierarchy-mode snapshots. They run bounded host operation
models, not the PS2 owner, callbacks or an EE emulator. Float programs are
built with contraction and fast-math disabled. If `cc` is absent, unittest
explicitly skips the host programs; source checks still run.

With the authorized private toolchain/retail inputs configured as described
in `wiki/Getting-Started.md`, run the normal full production gates:

```
python tools/build.py --setup-only
make split
python tools/regenerate_asm.py --fresh
python tools/build.py --progress-report build/linked_report.json
python tools/verify.py --json build/verify_report.json
```

Both retail hashes and the actual C-linked inventory must be checked; an
ASM fallback does not earn C progress. The production verifier reports ASM
for this target because its C remains guarded. A separate NON_MATCHING
compile is required to measure the candidate and must never be reported as
production progress. No retail bytes, emitted objects, compiler binaries or
machine-local paths accompany this evidence.

### Compact byte/reference replay

After normal build setup and fallback generation, export `P4_MWCC`,
`P4_RETAIL_ELF` and `P4_AS` to existing authorized files (a compiler wrapper
is permitted). This compact replay requires those environment variables even
when normal builds discover inputs through local configuration or PATH. Run:

```
python tools/replay_model00471370.py
```

The baseline commit `ff2f5f96ab71399cea76af2eb715823d306b8d7d` must be
available in local Git history. The driver uses current repository headers,
configuration and verifier/build helpers. It enables only this target in a
temporary copy, verifies the canonical candidate object hash twice, resolves
actual code/data addresses with the independently reviewed resolver, checks
124 exact siblings and 11 data sections, and runs seven wrong-address negative
controls. It also checks both C-only and assembly-spliced guarded production
objects against the baseline. No full source or dependency snapshot is copied.

Only a path-free JSON receipt is printed. Temporary source/object files are
cleaned up on completion or ordinary failure; do not publish temporary storage
after an interrupted run. The program installs nothing and does not edit the
owner. `--skip-production-splice` permits C-only replay without generated
fallbacks and explicitly reports the production comparison as not checked.
`--repo`, `--owner-source` and `--private-dir` support read-only integration
review and private temporary storage; see `--help`. This command does not
replace the full linked build or execute callbacks/the PS2 owner.
