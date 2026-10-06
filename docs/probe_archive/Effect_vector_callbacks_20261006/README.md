# Explicit effect vector callbacks, 2026-10-06

**Installed after prime release on 2026-10-06.** This archive describes the
reviewed eight-wrapper repair and its exact installed sources. Replaying the
archive does not edit production. The repair earns **zero new C matches**.

The position and rotation callbacks in the retail table at `0x00713480` receive
an instance and a pointer to a complete 16-byte vector. Eight recovered wrappers
omit the second parameter and call a two-argument provider with one argument.
The retail wrappers preserve the incoming vector address in `$a1`; the physical
providers `00492dd0` and `00492e10` load a quadword through that address and copy
it to the emitter's position or rotation storage. The corrected C declares and
forwards the vector explicitly.

| Owner | Position wrapper | Rotation wrapper | Emitter member |
| --- | --- | --- | --- |
| `src/promoted/code1_0048.c` | `00489ee0` | `00489f10` | `+0x4C` |
| `src/promoted/code1_004a.c` | `004af5e0` | `004af610` | `+0x58` |
| `src/promoted/code1_004b.c` | `004b1090` | `004b10c0` | `+0x5C` |
| `src/promoted/effPolygonTrack.c` | `00493da0` | `00493dd0` | `+0x30` |

The provider declarations agree with the definitions in
`src/Graphics/Model/mdlEffect.c`:

```c
extern u_long128 func_00492dd0(s32 emitter, u32 *position);
extern u_long128 func_00492e10(s32 emitter, u32 *rotation);
```

Each wrapper now accepts its actual vector argument and passes it to the
provider. The wrapper callers discard the provider's copied-quadword return.
The two owners that lack `u_long128` gain the same unsigned TI-mode typedef
already used by the provider and other owners. No provider body, shared header,
callback-table payload or optimization setting is changed by the proposal.
The source survey found no direct C calls to the eight wrappers; their observed
uses are the position and rotation table slots recorded in the receipt.

## Complete owner evidence

The final proposal was compiled as four complete translation units using the
configured MWCCPS2 3.0.1 b210 compiler with `-O2 -Iinclude`, in the default profile
and with `NON_MATCHING` defined. The archive packaging authenticates and reuses
those completed objects. It does not compile the unchanged proposal again.

| Owner | Functions | Default profile | Guarded profile | Code references, default / guarded |
| --- | ---: | --- | --- | ---: |
| `code1_0048.c` | 73 | 67 MATCH, 6 ASM | 67 MATCH, 6 NONMATCHING | 589 / 604 |
| `code1_004a.c` | 92 | 90 MATCH, 2 ASM | 90 MATCH, 2 NONMATCHING | 368 / 381 |
| `code1_004b.c` | 72 | 69 MATCH, 3 ASM | 69 MATCH, 1 NONMATCHING, 2 ASM | 215 / 215 |
| `effPolygonTrack.c` | 19 | 19 MATCH | 19 MATCH | 195 / 195 |
| **Total** | **256** | **245 MATCH, 11 ASM** | **245 MATCH, 9 NONMATCHING, 2 ASM** | **1,367 / 1,395** |

Every before/after function retains its code, size, canonical relocation
records and fully resolved bytes. All 245 existing matching C functions also
retain their code when the guarded profile is enabled. All eight repaired
wrappers remain exact. Existing guarded residuals remain visible in the proof.

The proof applies every code and owned-data relocation. It derives storage
placement from retail references, checks alignment, and compares the complete
resolved payload. This covers the eight entries of the 32-byte
`effPolygonTrack.c` jump table in both profiles, and the guarded camera owner's
eight-byte `.sdata` pair and four-byte `.lit4` literal. All executable sections
are covered by known function extents and zero alignment gaps; unexpected code,
data sections, unresolved references or nonzero uncovered bytes are rejected.

The complete external callback table has 33 rows of 64 bytes. The receipt pins
its 2,112-byte payload hash and the exact position/rotation slots reaching each
wrapper. It also pins both physical provider windows and the complete current
provider source. Compiler SHA-256:

```text
286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7
```

The earlier scoped lint comparison had zero errors in both versions. Warnings
decreased from 67 to 59, removing eight H011 provider-declaration disagreements.
The remaining warnings were one H001, five H003 and 53 other H011 advisories.
Their original report hashes are retained; replay does not present those older
lint runs as fresh checks.

## Archive contents and input authentication

`receipt.json` contains the exact before and final source hashes, reversible
source edits, all sixteen profile source/object hashes, compiler identity,
per-profile proof fingerprints, owned-storage identities, table witnesses and
the hashes of the prior final manifest and proofs. The edits reconstruct either
source from the other without a patch utility or a saved private source file.

`replay.py` accepts only the exact held source or exact final installed source
for each owner. It checks the reconstructed final source hash in either case.
It authenticates the provider, every recorded transitive header, fallback
assembly, compiler-selection files, symbol maps, retail metadata and compiler
wrapper scripts. It then checks the configured compiler binary and effective
owner flags. Any input drift requires a new audit; it is not silently accepted.

`proof.py` contains the complete MIPS relocation, owned-data and executable
coverage checks. Its only repository imports are the tracked `tools/verify.py`
and `tools/probe_variants.py`. `fallbacks.py` handles the eleven generated
assembly listings used by these owners. Existing listings are optional caches
whose hashes must agree with the tracked generator manifest. A clean checkout
recreates missing listings from the pinned splitter configuration and retail
image, then uses the official `tools/regenerate_asm.py` renderer to verify each
exact text hash. The listings are written only in replay scratch.

None of the archive scripts imports a prior build directory, reads a saved
global build report, needs an ignored helper, or changes production files.
The receipt authenticates all three archive scripts and the tracked generator
inputs. Reusing completed objects needs no generated assembly cache.

No retail bytes, native objects, proprietary compiler, machine-local path or
ignored-build input is included in this archive. A fresh replay needs the
repository's configured compiler, retail ELF and assembler, as ordinary native
owner verification does. Supplying both `--compiler` and `--retail` avoids any
need for a local configuration file.

## Replay

From the repository root, a future fresh proof compiles all sixteen before/after
profiles into a new scratch directory:

```text
python docs/probe_archive/Effect_vector_callbacks_20261006/replay.py --output build/effect-vector-proof.json
```

To authenticate and reuse completed objects without invoking the compiler:

```text
python docs/probe_archive/Effect_vector_callbacks_20261006/replay.py --reuse-dir /path/to/completed-objects --output build/effect-vector-reused-proof.json
```

The supplied directory uses this layout for each of the four owner stems:

```text
code1_0048/before-default/owner.c
code1_0048/before-default/owner.o
code1_0048/after-default/owner.c
code1_0048/after-default/owner.o
code1_0048/before-guarded/owner.c
code1_0048/before-guarded/owner.o
code1_0048/after-guarded/owner.c
code1_0048/after-guarded/owner.o
```

Repeat that structure for `code1_004a`, `code1_004b` and `effPolygonTrack`.
Every reused source and raw object must match its receipt hash. The fresh path
checks the same complete code-and-storage proof fingerprint and before/after identity;
it records the newly generated raw object hashes separately so irrelevant ELF
metadata differences cannot substitute for a code or storage check.

For source-only reproduction, `--emit-only` authenticates the same inputs and
writes all sixteen exact profile sources without compiling. This mode labels
its output as source emission and does not claim a completed native proof.
Adding `--regenerate-fallbacks` also reproduces the eleven assembly listings
from retail into scratch without invoking the C compiler. Fresh fallback
generation checks the package versions in `requirements-python.txt`.
`--work-dir` selects a new scratch directory; existing output files are refused.
Optional `--compiler`, `--retail` and `--assembler` arguments supply local asset
paths. Those assets remain subject to the recorded compiler and retail checks.

## Packaging validation actually performed

The replay ran in a separate minimal tree containing the 38 pinned tracked
inputs, the four exact held owners and this archive. That tree had no prior
build outputs, generated fallback cache or local compiler configuration. The
compiler and retail paths were supplied explicitly. Reusing the sixteen
authenticated completed objects passed the full 256-function proof in both
profiles. The JSON result SHA-256 is:

```text
b07e8a837b0c9a5dea095a657314e96f14ff648bdfb95ad31df20e59ada200e0
```

Only the copied owners were then changed to the exact proposed versions.
Source-only replay reproduced all sixteen before/after profile sources byte
for byte. Its forced fallback generation reproduced all eleven required
assembly listings from the retail image and pinned split recipes, with every
text hash matching the receipt. This result SHA-256 is:

```text
02922b8c99acdb32c647f4271a8c30fb8ab6c08132cddbe0665e41f95f85e391
```

Five isolated negative controls rejected a changed header, changed owner,
wrong compiler digest, wrong callback-table digest and wrong completed-object
digest. The copied files were restored after each control; actual production
sources and completed objects were unchanged. No C compiler was invoked by
these packaging checks. The fresh compilation branch is supplied for a future
replay; the already-proved unchanged proposals were not recompiled here.

## Installed verification

After prime released the repair following the batch-1 seal, the exact reviewed
patch was applied to the four owners. Every installed source hash equals the
final expected hash already recorded in this receipt. Normal installed-owner
verification reports **245 MATCH and 11 ASM across 256 functions**; its origin
breakdown is 244 first-party MATCH, nine first-party ASM, one third-party MATCH
and two third-party ASM. All eight repaired wrappers remain MATCH.

Fresh lint of the four installed owners reports zero errors and 59 unchanged
advisories: one H001, five H003 and 53 H011. Installed-state replay reused the
sixteen authenticated complete-owner objects and preserved 256 functions and
245 matching C functions in each profile, with 1,367 default and 1,395 guarded
code references plus eight owned-data references per profile. This replay
performed no new C compilation. The normal verifier above is the separately
requested installed-owner compile; guarded proposals were not recompiled.

The receipt's `installation` record binds the normal verifier, lint and reused
proof report hashes. The original proposal receipt hash is retained there as
well. The scripts, native source/object bindings, reference fingerprints and
portable validation evidence are unchanged by this lifecycle update.

## Scope

This is an explicit ABI repair with preserved native code, not new C progress.
The owner and data proofs do not execute a game frame or establish a rebuilt
image hash. The source repair is installed; its integrated build, C-link
eligibility, commit and push remain prime-owned.
