# Battle controller integration and replay

This addendum records full integration checks for `func_001b4880` against public
baseline `9938a483606bdf00f62f489664457d722850eb09`. The original reviewed 20-file
source, header, test and evidence payload is unchanged. Three existing test files
also receive the reviewed adjustments below; this addendum contains prose only. The
accompanying `production-approval.json` pins the original 13 source/header/test inputs.

## Verified scope

The production controller has 2688 executable bytes, frame 0x90, 75 references
and 47 calls, with no alignment tail. A fresh replay resolves the complete body
to retail, including the return delay slot. Its complete owner object SHA-256 is
`77fcfc50cb13a18c9123b7340a2ecaa8b4775a40a4d0d923c05d1b41e896cb8b`.
All 374 other functions across the five prerequisite owners and their allocated
data preserve. The only sibling reference-name changes are the ten exact entries
recorded in `production-validation.json`.

Full verification has 13,102 rows: 9,582 MATCH / 3,520 ASM, including 6,762
first-party MATCH / 99 ASM. Exactly `001b4880` changes status. Every other row
agrees after ignoring source line numbers and those ten proved literal names.
The seven preceding promoted functions remain matching:
`00480940`, `00172e00`, `0031ac10`, `001b2380`, `002eb270`, `0048b9e0`, `00492100`.

The fully cold build had zero cache hits, 860 eligibility misses and 604 link
misses. It links 604 source C objects and 54 SDK objects. The complete 8,586-function,
658-unit link inventory is unchanged, with the controller and all seven prior
matches present in their verified C owners. Both retail hashes pass:

- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Generated report SHA-256: `8e94523a137a8cc8fac7746dd63feffb714475d2a6dc572a88965bc3b3f8b493`

The complete ordinary suite passes **1,152 tests**, with zero errors/failures
and exactly the two absent-middleware-unit skips listed below. The unchanged
QEMU adapter redirects 1,572 i386 executions. Runtime limits and skip rules are
unchanged. The fixture and workload adjustments below address the failures
identified by the earlier retained attempts.

- `test_third_party_classification.MiddlewareUnitTests.test_any_preserved_body_stays_behind_include_asm`
- `test_third_party_classification.MiddlewareUnitTests.test_every_entry_is_include_asm`

Both skip reasons are `middleware unit not present`.

The existing opening-controller fixture now models sound-stop as `void(void)`,
matching the repaired real provider and caller family. Only the obsolete argument
assertion is removed; call-count, route and order checks and every original
mutation control are retained. Independent replay passes all six methods and
all 42 controller/provider assertion rejections at O0/O2. The corrected fixture
SHA-256 is `9c38a222e7bfd8383c6794abe6d57c918b8b86b9a0ff2406ac54c655684ec496`.
This test-only successor leaves all production inputs and completed verifier,
machine-replay, build and report artifacts unchanged.

The pre-existing Camp-alpha exhaustive fixture also exceeded its 60-second
process budget on unchanged public baseline source under the replacement host's
QEMU runner. Its test now partitions base-alpha values into `[0,64)`, `[64,128)`,
`[128,192)` and `[192,256)`. The ordered, disjoint union still executes every one
of the 131,072 byte-pair/callback scenarios at each of O0 and O2. Every per-case
statement, full-buffer assertion, trace check, fixture type and original negative
control is retained; diagnostic scenario IDs also retain their original values.
The four original negative executions keep their default full-range domain.
The runtime and its 60-second per-process limit are unchanged. Independent replay
passes all eight positive processes and all four ordinary assertion controls;
the slowest O0 process takes under 15 seconds on this host. Only these test
partitions change; the actual Camp source and reference caller are untouched.

The signed packed-word boundary is qualified for the target's 32-bit,
little-endian ABI. The admitted object, allocation, finite quaternion and byte
color domains in `docs/Battle_camera_sequence_20261005.md` remain in force.
Quaternion composition and dispatch remain explicit native-test boundaries;
adversarial node, UID and palette cases observe sampling and do not claim normal
engine mutation. This integration does not broaden those claims.

## Current-source reproduction

Use a fresh checkout and the normal setup with authenticated licensed inputs, split and
regenerated fallbacks. The validator needs only the public baseline and current
source. In a shallow clone, fetch the public baseline first:

```sh
git fetch origin 9938a483606bdf00f62f489664457d722850eb09
audit_output="$(mktemp -d)"
python docs/probe_archive/battle_camera_sequence_exact_20261005/validate_production.py "$audit_output"
mkdir -p build
python tools/verify.py --json build/verify_report.json
python tools/build.py --linker-backend gnu --progress-report build/linked_report.json
python tools/gen_decomp_report.py --report build/verify_report.json --linked-report build/linked_report.json --output build/report.json
python -m unittest discover -s tests -v
```

The full ordinary suite needs its compiler, assembler and retail fixtures, and
a working 32-bit execution environment. The integration host used the unchanged
external QEMU adapter; no test timeout or skip rule was changed.
Only the two specifically identified absent-middleware skips were admitted in
the integration run.

The source and scoped evidence were recovered to their exact pre-reset hashes,
then recompiled and rerun with restored authenticated tools. Historical lost
objects are not required by these commands and are not presented as accessible
artifacts. Compiler/game binaries and generated instruction bytes remain private.
Remote CI is a separate post-publication check.
