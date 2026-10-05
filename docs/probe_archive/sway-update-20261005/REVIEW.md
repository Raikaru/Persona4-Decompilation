# Sway particle update 00492100

Date: 2026-10-05. Integration base: `1d1c7bfe6a1052e69b9265b62cbf34901cbc2aa8`.

## Exact candidate

The configured whole owner, MWCCPS2 3.0.1 b210 at `-O2`, emits 2428 executable
bytes with frame `0x140`, zero masked or fully resolved instruction differences,
and all 27 reference payloads equal to retail at their original offsets. These
are 22 calls, three GP references, and the two address halves of the real
`D_00713D40` direction vector. The required return delay-slot instruction belongs
to those 2428 bytes; only the last four bytes of the 2432-byte window are alignment.
The older statement that a 2424-byte body lacked only padding was incorrect.

The refreshed readable candidate SHA-256 is
`7dfea0f853bf2591fa946b70991c9f8dde3674c6eb824153bb252b993a1f397a`.
Its whole-owner object SHA-256 is
`b62635a99df6bdb190e8f88cfe8f214ab87f5b4b8b25079b60b9c0d892bf9388`.
Private compiler objects and retail inputs are not included in this publication.

All 42 sibling instruction bodies preserve. All 244 sibling relocation records
preserve except one compiler-generated literal spelling: at `00494740+1716`,
`@484` becomes `@783`. Both name the same four-byte value at `.lit4+0` and resolve
to the same retail address. This is the only permitted spelling exception; there
is no general symbol-name normalization. The allocated `.lit4` payload is unchanged.

## Source mechanism

The retained, initialization-reviewed three-object source measured 2424 bytes,
298 fully resolved differing words and 228 stock aligned edits. Its corrected
physical-live comparison was 227 edits. The recovered in-progress branch had
already reached 2428 bytes and 57 resolved words before this continuation.

The completed steps preserve actual operations and dependencies:

1. Keep separate, fully initialized direction, spread and previous-position
   objects. Both position snapshots first complete the address of the existing
   object, then perform its full 16-byte assignment.
2. Keep the captured emitter pointer, count, flags, angle mode and physical
   parameters distinct from the live emitter fields used for later trail work.
3. Order complete equivalent expiration and angle-mode branches as retail.
   Retain the consumed byte-valued initial-preroll phase before widening it.
4. Give reused zero, one, half, two and negative-one values real scalar names;
   keep the actual runtime angle-range load. Their assignments occur in the
   existing loop preheader and every value has genuine uses.
5. Declare the initial-amplitude lifetime before the persistent physical values,
   while still producing it at its real spawn phase and storing it only after
   the final-amplitude RNG call. No arbitrary initializer or extra use is added.
6. Give preroll emission scale its own completed value lifetime and use the real
   RNG call directly in the two emission expressions. Portable C does not order
   every operand read against that call. The actual provider mutates only RNG
   state, and the configured object proves retail call-first/load-after order.
   This is not a promise for arbitrary mutating RNG replacements.
7. Complete the genuinely used unsigned particle index from the live emitter
   base before multiplying by trail span. It must not be replaced by the captured
   iteration count. Both expiration and preroll preserve their live reloads.

Explicit loop constants and declaration lifetimes reduce the residual to five
words; the emission phases leave two; the two completed indices close those.
No dummy use, padding, fake ABI, ordinary-memory volatile, machine-code patch,
undefined full-width shift or scalar computation assembly is used.

Both scoped compiler settings are recognized. With final source otherwise
unchanged, propagation on produces 2424 bytes and 137 resolved differing words;
loop-invariant motion off produces 2424 bytes and 411 resolved differing words.
The final off/on composition is wrapped in push/pop. The global pragma audit
recognizes all 43 spellings in the current source inventory.

The new header contains only kind-11 state, parameter and emitter records. It
reuses the unchanged published particle type and four VU helpers from
`particle_spawn_internal.h`; it does not add the former unused Orbit/Sphere
records or helper set. All 61 size/offset assertions compile with b210.
The owner-level RNG declaration now uses the canonical state pointer, and
memcpy has its actual ignored `void *` return. No provider body changes.

## Actual caller domain

The kind-11 dispatch table specifies 64-byte state and 272-byte parameters.
Constructor `00492b20` lays out emitter48, primary/trail particle32 records,
two parameter272 copies, then one state64 per primary. State and particle
strides equal their actual allocations. Reset/first dispatch marks all ages
inactive before the controller. Lifetime zero returns before state/vector use;
unspawned or terminal particles skip live payload reads. Normal spawn produces
every subsequently read primary and state field.

The three real complete local objects stay distinct. Spread W is initialized
at entry. Direction W is explicitly zero before its complete load and is
preserved by XYZ-only normalization. The actual quaternion provider supplies
complete basis columns with W zero. World position uses the live parameter
center, including its W lane; local position W is zero. Actual attributes
`0048b220` write primary color, size and angle before the only complete
32-byte primary copy. The previous-position snapshot is complete and separate
from the mutable primary record at both attribute calls.

The actual normal lifecycle supplies all 16 Sway state floats before live use.
The initial amplitude stays live across the next RNG call and is not exposed
in state early. Captured physical values remain captured across later calls.
Provider code, data, signatures and sampling phases are retained except for
the two corrected declaration descriptions noted above.

The existing opaque `0048b340` trail provider has genuine missing initial-history
producers for some dimensions. It may copy/read an inactive trail slot before
an age guard. On coherent nonoverlapping allocations, all such sources and
writes stay within that primary's disjoint trail group. Sway never reads trail
payload: it clears ages or copies an initialized primary into the first trail
slot. This is caller-only preservation of the actual opaque provider, not a
claim of transitive engine definedness or a repair of the provider's own debt.

Prerequisites include complete valid resource records and allocations, coherent
nonnegative counts/dimensions and representable offsets/products/conversions,
normal reset/spawn lifecycle, finite usable scalar arithmetic, positive usable
lifetime, nondegenerate normalization, and initialized interpolation/camera
inputs with usable projection depth where needed. No all-resource census,
universal host-floating guarantee or PS2 gameplay execution is claimed.

## Ordinary native evidence

The ordinary tests extract the current owner definition; they contain no
research-file dependency or permanent source-hash lock. The observed extracted
function SHA-256 is
`b743d815248e3bc9ed1b6effaa0c609a89f0323fa08310cb90625ea79c1a2035`.
The scoped suite passes 40 tests with zero skips: 28 positive scenarios and
38 ordinary assertion-based semantic controls at each O0/O2, plus an exact-once
mutation-binding check. All 21 historical scenarios and 25 historical controls
remain. New coverage includes captured flags/angle mode, provider order/count,
the real runtime direction input, and live-base trail indices. Complete state
setup/comparisons use memcpy with genuine float arrays, avoiding aggregate
pointer stepping.

These are native32 controller tests with deterministic scalar/VU/provider seams.
Callback mutations distinguish captured/live behavior; they are not assertions
that the actual RNG or matrix provider performs those mutations. The suite does
not execute the actual trail helper or establish its transitive definedness.

## Scoped production gate

After independent candidate/source/domain/native acceptance, only the target
production guard was removed. Ordinary whole-owner verification reports
39 MATCH / 4 ASM, including `00492100` MATCH. The complete ordinary production
object is byte-identical to the independently reviewed exact object. All four
remaining guarded regions, 42 siblings and allocated data preserve, with only
the narrow literal-name exception described above.

Lint reports zero errors and two H003 warnings: the measured scoped Sway
loop-invariant setting and an unchanged neighboring attempt. Both Sway compiler
settings are recognized and measured. The shared published Wave headers remain
unchanged. The final ordinary production native replay also passes all
40 tests with zero skips, preserving the 28 scenarios and 38 controls at each
optimization level.

Complete cold build, both retail hashes and the full native suite belong to
publication and must not be inferred from this scoped owner gate.

## Scoped reproduction

With the documented toolchain and an authorized retail input, complete the
repository's setup and fallback-assembly preparation, then run:

```sh
python tools/verify.py --json build/sway-owner.json src/promoted/code1_0049.c
python tools/decomp_lint.py src/promoted/code1_0049.c include/sway_particle_internal.h
python tools/pragma_audit.py
python -m unittest discover -s tests -p test_sway_particle_contract.py -v
```

A host unable to execute i386 ELF directly needs a faithful external execution
adapter; it must preserve arguments, environment, failures and timeouts without
changing the source, tests or skip rules. The scoped native suite permits no
skips. Complete linked/hash gates use the ordinary documented repository build.
