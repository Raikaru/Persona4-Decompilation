# Wave update: complete production replay

This addendum records the complete gates for `0048b9e0`, based on public
`90f7c9c8321347f7fa6b572183a7edc33205a7de`. The other receipts in this directory
retain their original research and scoped-review stages. Their private paths
and hashes identify the evidence used; they are not public download links or
runtime dependencies. Current source, the Wave header and ordinary tests are
complete and require no unpublished Git history or recovery archive.

## Complete checks

- Full verifier: 13,102 rows; 9,580 MATCH and 3,522 ASM. First-party: 6,760 MATCH and 101 remaining
- Only `0048b9e0` gains MATCH status, adding 2,656 matched code bytes. Its 2,652
  live bytes include the real return delay slot; the last four bytes are authentic
  zero alignment
- All 28 target references, 72 sibling bodies and raw sibling references
  preserve. There are no allocated non-executable owner sections and no metadata
  normalization exceptions
- Cold build: 604 C objects plus 54 SDK objects; zero cache hits, with 860 eligibility and 604 link compiles
- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Ordinary suite: 1,083 tests, zero failures and only the two documented absent-middleware skips

The earlier matches `00480940`, `00172e00`, `0031ac10`, `001b2380` and
`002eb270` remain MATCH and C-linked, alongside the new target. The actual
linked inventory remains 8,586 functions in 658 translation units. All other
13,101 verifier rows preserve apart from source line numbers, and the generated
report changes only the Wave owner's matching progress.

The scoped fixture executes 13 positive scenarios at each of O0 and O2, rejects
19 distinct semantic controls at each level and separately checks the expected
invalid-conversion trap from a signed-remainder mutation. That trap is not
counted as an assertion-based semantic control. The 52 record-layout checks
and recognized scoped compiler settings are recorded in the original receipt.

## Retained caller and provider boundary

The actual constructor/reset/dispatch/spawn lifecycle supplies the fields that
Wave consumes. All three complete 16-byte local objects and both real W
initializations remain. Spawn writes the live state and primary fields, and the
attribute provider supplies color, size and angle before the complete primary
copy. No target-owned unwritten local, state or primary-field read is accepted.

The existing `0048b340` provider remains an assembly fallback. Its known missing
initial-history producer is unchanged: some trail dimensions can read unwritten
history before an age guard. On the reviewed coherent-allocation contract, those
reads and writes stay within disjoint trail groups, whose payload Wave never
consumes. This is a caller-only claim at the actual opaque provider boundary;
it neither repairs that history hole nor certifies the provider's reconstructed
C as defined for every call.

Complete initialized parameter objects, successful valid allocations, coherent
nonoverflowing capacities and offsets, normal initialized live state, and finite
representable numerical/resource inputs remain prerequisites. Normalization and
camera/interpolation inputs must be usable. The fixture's controlled VU and
provider models do not establish every asset's validity, universal host floating
behavior, the whole effect engine or a PS2 gameplay run.

## Reproduce from current source

Use the repository's documented toolchain and authorized retail input. Complete
the documented setup, splitting and generated fallback assembly preparation,
then run:

```sh
mkdir -p build
python tools/verify.py --json build/verify_report.json
python tools/build.py --linker-backend gnu --progress-report build/linked_report.json
python -m unittest discover -s tests -v
python tools/gen_decomp_report.py --report build/verify_report.json \
  --linked-report build/linked_report.json --output build/report.json
```

The complete native gate allows only the two existing absent-middleware skips.
A host that cannot execute i386 ELF directly needs an external execution adapter
that preserves arguments, environment, timeouts and failures without changing
source, tests or skip rules. Compiler binaries, retail inputs and machine-object
captures are not included in this source publication.
