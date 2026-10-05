# Sway update: complete production replay

This addendum records the complete gates for `00492100`, based on public
`1d1c7bfe6a1052e69b9265b62cbf34901cbc2aa8`. The scoped receipts retain their
original stages; private paths and hashes identify review evidence rather than
public downloadable dependencies. The current source, Sway header and ordinary
fixtures require no unpublished Git history or recovery archive.

## Complete checks

- Full verifier: 13,102 rows; 9,581 MATCH and 3,521 ASM. First-party: 6,761 MATCH and 100 remaining
- Only `00492100` gains MATCH status, adding 2,432 matched code bytes. Its 2,428
  executable bytes include the actual return delay slot; four authentic zero
  alignment bytes complete the retail window
- All 27 target references and 42 sibling bodies preserve. One compiler-local
  literal name changes: `00494740+1716`, `R_MIPS_LITERAL`, `@484` to `@783`.
  Both bind the identical four-byte `.lit4` value and exact retail address
  `007611b4`. All other reference fields and allocated data preserve; no general
  symbol-name normalization is allowed
- Cold build: 604 C objects plus 54 SDK objects; zero cache hits, with 860 eligibility and 604 link compiles
- Image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Ordinary suite: 1,123 tests, zero failures and only the two documented absent-middleware skips

The previous matches `00480940`, `00172e00`, `0031ac10`, `001b2380`, `002eb270`
and `0048b9e0` remain MATCH and C-linked, alongside the new target. The actual
linked inventory remains 8,586 functions in 658 translation units. All other
13,101 rows preserve apart from source line numbers and the single proven
literal-name substitution. Only the Sway owner's matching progress changes.

The shared Wave and VU headers remain unchanged. The only declaration
prerequisites in the Sway owner are the canonical RNG-state pointer and the
actual ignored `memcpy` pointer return. A separate compile-only comparison
enabled all four remaining guarded attempts with their scoped pragmas before
and after those declarations; the entire owner objects were byte-identical.
Those attempts retain their production fallbacks.
The original record retains the 61 compiler layout checks and recognized
scoped settings.

## Retained caller and provider boundary

The real constructor/reset/dispatch/spawn lifecycle supplies every consumed
Sway primary and state field. The three complete 16-byte local objects remain
separate, with the actual spread and direction W producers in their proper
places. The used scalar and snapshot lifetimes introduce no dummy storage or
unwritten target-owned read. Full primary copies follow the real attribute
provider's complete color, size and angle writes.

The unchanged `0048b340` provider remains an assembly fallback. Its known
trail-history and cubic-W limitations are neither repaired nor certified as
defined reconstructed C. On the reviewed coherent-allocation domain, its
uncertain bytes remain in disjoint trail storage that Sway does not consume.
This is a caller-only claim at the actual opaque provider boundary.

Complete initialized records, valid allocation and lifecycle, representable
capacities/offsets/conversions, and usable finite numerical/resource inputs
remain prerequisites. Normalization, interpolation and camera/projection
operands must satisfy their documented domains. Real RNG touches its own state;
retail-exact call/read ordering does not grant an arbitrary-mutating-callback
guarantee for every portable-C evaluation.

The fixture preserves 28 scenarios at each of O0 and O2 and rejects all 38
distinct controls with ordinary assertion failures at each level. It checks
complete state, W snapshots, floor/bounce behavior and captured versus live
fields, provider call order and trail-index reloads. Controlled VU, sine and
provider models do not establish every resource's validity, exceptional EE
floating-point behavior, transitive provider definedness or a full gameplay run.

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

The complete native gate permits only the two existing absent-middleware skips.
Hosts without direct i386 execution need an external adapter that preserves
arguments, environment, timeouts and failures without changing tests or skip
rules. Game resources, compiler files and machine-object captures are excluded
from this source publication.
