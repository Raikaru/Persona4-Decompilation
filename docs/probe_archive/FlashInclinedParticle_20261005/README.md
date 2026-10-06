# Inclined Flash particle storage, 2026-10-05

`func_004a0c00` in `src/promoted/effPolygonFlash.c` remains guarded C.
This recovery replaces the overlapping age-word/float-array views with one
complete, named 32-byte particle record. It earns **no new exact C match**.

| Result | Measurement |
| --- | --- |
| Production owner | 48 MATCH / 1 ASM, 49 functions |
| Guarded target | 2204 executable bytes / 2208-byte retail window |
| Remaining difference | Sixteen instruction words, CPU `v0`/`v1` operands |
| Alignment suffix | Four zero bytes |
| Resolved references | 639 production; 641 guarded, including 42 in the target |
| Allocated data and data relocations | None |

## Recovered record and producers

The local `FlashInclinedParticle` declaration describes these observed fields:

| Offset | Type | Recovered role |
| --- | --- | --- |
| `+0x00` | `s32` | Age and inactive/available sentinels |
| `+0x04` | `f32` | Initial velocity |
| `+0x08` | `f32` | Angular phase |
| `+0x0c` | `f32` | Longitudinal extent |
| `+0x10` | `f32` | Initial radius |
| `+0x14` | `f32` | Radius change per frame |
| `+0x18` | `f32` | Inclination factor |
| `+0x1c` | `f32` | Transverse extent |

The names describe the observed calculations, not original symbol names.
Both `004a09e0` and `004a0af0` allocate `count * 32 + 0x10` bytes and place
the particle pointer at allocation+0x10. `004a07b0` resets the age while
advancing eight words. The updater advances the corresponding typed pointer
one record at a time. Its age, birth budget, random-call order, terminal
handling, floating-point expressions and hardware operations are unchanged.
An extent assertion checks `sizeof(FlashInclinedParticle) == 0x20`.

Only this declaration, its accesses and its explanatory comment changed
inside the existing `NON_MATCHING` guard. No provider signature, shared
header, sibling body or optimizer setting was changed.

## Complete owner evidence

The actual owning path was compiled through `verify_file`, reporting
48 MATCH / 1 ASM. Its default object is byte-identical to the captured
starting object. The full `NON_MATCHING` profile also preserves every one
of the 49 function bodies and relocation records relative to the previous
guarded profile. Each reference is resolved against current symbol addresses;
relocation masking is not the final check. Executable sections are completely
accounted for by function extents and zero alignment gaps.

The remaining interval is `004a112c` through `004a11dc`. Retail keeps the
direction-vector address in `v1` and uses `v0` for scalar transfers to VU0.
The current C uses the opposite pair. The four vertex outputs and following
color work retain their existing instruction bytes. The register assignment
still lacks an exact source explanation.

Five earlier prime probes were authenticated before proceeding: separate
direction pointer, float transfer output, normal output constraint, separate
quad-output scope, and consumed-input output timing. They were not rerun.
Eight new full-owner hypotheses are recorded in `receipt.json`: the mixed
particle record, complete vector workspace, both together, two genuine
vector-operation helper boundaries, explicit lifetime optimization, register
class allocation, and a shared scalar transfer value. Each retained the same
sixteen words and preserved all 48 siblings and 641 references. This is a
record of those particular measurements, not a compiler-wide impossibility
claim. Only the particle record was installed.

## Source-bound native checks

`native_birth.py` extracts the installed type and the unchanged birth branch.
At both O0 and O2, **640 cases** pass against an independent byte-offset
oracle with exactly representable inputs. Cases cover available/inactive/other
ages, zero and nonzero birth budgets, ordinary and preroll initialization,
both initial-age choices, and power-of-two lifetimes. The check observes all
seven float fields, age, budget, the seven float RNG calls and optional integer
RNG call, configuration preservation and surrounding canaries. Swapped
length/width fields and a reversed radius delta are rejected at both levels.

`native_lifecycle.py` executes the actual current `004a09e0` and `004a0af0`
constructors and `004a07b0` reset body. **72 cases** at each optimization level
cover counts zero through eight, construction and cloning, both texture setup
paths, and the geometry dirty flag. They check the exact allocation size,
state-header pointers, particle initialization stride, vertex-clear length,
call counts and complete canaries. Allocation, geometry creation/cloning,
texture and UV leaf providers are controlled fixture seams. The existing
integer-address memset declaration uses an explicit native address adapter.
Wrong allocation and reset strides are rejected at both levels.

An initial lifecycle fixture trapped because its synthetic original-state
buffer was not word-aligned. That failed input/output was retained privately.
Only fixture alignment was corrected; both optimized profiles then passed.

These are freestanding i386 C checks with undefined/bounds sanitizer traps.
They do not execute the full Flash updater, emulate VU arithmetic, establish
PS2 floating-point equivalence, or render a frame. RNG values and the named
leaf providers are controlled. Native results and exact EE byte/reference
measurements are separate evidence.

## Frozen source and preserved objects

The final owner SHA-256 is
`c283e95382bde05d67022c40c6e0e9d143d9cd20e808601dd052bd360e645c4a`.
The starting owner SHA-256 was
`aab7dff0682b7658da404866095a44cd3b68ceb854fd82179bdaa8d02f5f1172`.

The full-owner objects and birth fixture were completed at source
`525ebc3eac02d01d6bab49a5be521617aaeca173ac40902e52e8d6bfe457544e`.
Prime then requested one comment correction: the wording now explicitly says
sixteen `v0/v1` differences remain. `receipt.json` records the exact old/new
comment and both owner hashes. All bytes outside that comment are identical.
The successful compiles and native birth executions were preserved rather
than rerun for this wording change. Lifecycle execution used the final owner.

Scoped lint has zero errors and the same 22 pre-existing warnings: nineteen
H003 optimizer advisories and three H011 declaration advisories. The latter
concern `00481300`, `004836b0` and `00483490`; this recovery changes none of
those interfaces. It is not a warning-free owner.

## Reproduction

With the repository's configured compiler/retail input and native32 support:

```text
python docs/probe_archive/FlashInclinedParticle_20261005/replay.py --output build/flash-inclined-proof.json
python docs/probe_archive/FlashInclinedParticle_20261005/native_birth.py --output build/flash-inclined-native
python docs/probe_archive/FlashInclinedParticle_20261005/native_lifecycle.py --output build/flash-inclined-native
```

The owner replay normally compiles fresh complete owner profiles in unique
build scratch. Its optional `--reuse-dir` authenticates completed source/object
hashes and the explicit comment bridge, then rechecks all current references.
Both native scripts support `--emit-only` to reproduce their fixture text
without calling a compiler or executing a binary. The packaged emitters were
checked against the already successful fixture texts. Native generated-source
hashes use normalized text newlines.

`before_body.c` permits the prior complete owner to be reconstructed and
authenticated. The bundle contains no retail bytes, object files, compiler
binary or machine-local paths. Production source is frozen. Global first-party
verification, linked build and publication remain prime-owned.
