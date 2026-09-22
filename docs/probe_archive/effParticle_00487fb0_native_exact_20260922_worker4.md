# Particle renderer 00487fb0: native recovery

`func_00487fb0` is active in `src/promoted/effParticle.c`. The configured native
MWCCPS2 b210 compiler with `-O2 -Iinclude` emits **3516 exact bytes** in the
3520-byte retail window. The remaining four bytes are zero alignment. Every
instruction and code relocation is checked without masks. The compiler's new
32-byte switch table at `00756880` matches all eight retail destinations after
its relocations are applied.

The owner now has **16 official MATCH functions and one ASM fallback**. Complete
unmasked proofs pass for all seventeen functions, including the fallback. The
sixteen siblings retain their original bytes and canonical relocations; both
previously accepted 32-byte tables are unchanged. The particle constructor
`00486b00` and projected renderer `00488d70` remain exact.

## Native source mechanisms

The renderer uses actual eight-byte PTank lock records, with a data pointer and
stride. Its animation output is the 56-byte record written by `004824a0` through
`00482700`: position and size, angle, texture, four UV values, halfword type,
packed color, and texture dimensions. Both material updates dereference the
first material and snapshot its parent's RGBA in one shared four-byte object.

The first transformed pass contains no calls inside its loop. Keeping its actual
matrix and transformed-position pointers live across iterations reproduces the
retail address lifetimes. The emitter address can be reused for the object-array
cursor in subtypes five and six after the emitter's lifetime has ended. Slot
reloads before each callback and every pointer stride remain in retail order.

The ordinary and transformed point paths share the same semantic angle-range
locals, while loading their original constants at their original points. Upper
angle tests use `!(angle <= upper)` as in retail, including unordered inputs.
The two animated paths return their real four-byte color packing results from
inline VU/MMI boundaries. This keeps normalization input storage distinct from
the scalar output storage consumed by the color stream.

The last twelve differences were the animation-resource pointer and the active
particle count exchanging saved registers. The count is declared with its real
zero initializer in a scope beginning **after the resource-null diagnostic**.
This replaces the existing zero assignment, rather than introducing an extra
value or operation. The lifetime extends through both animation paths and the
final active-count guard and PTank count store:

| Retail address | Actual count operation |
| --- | --- |
| `004884d8` | Initialize the animated active-particle count to zero. |
| `004887c4` | Increment it for an active untransformed particle. |
| `00488a84` | Increment it for an active transformed particle. |
| `00488aa8` | Test whether any particle was emitted. |
| `00488b0c` | Store that count in the PTank extension. |

The uninitialized case-local and unsigned-count controls retain twelve differing
words. The accepted initialized lifetime preserves the same instruction order
and every output consumer. No dummy allocation state, added side effect,
volatile scalar field, fixed register assignment, padding, or ordinary scalar
assembly was introduced.

## Caller and provider review

The owner uses the actual `RpMaterial *` return and `RpMaterial *`/`RwTexture *`
arguments for the material texture provider at `003c42b0`. Two existing sibling
call sites receive compatible explicit pointer conversions and retain identical
native bodies and relocations. The PTank lock declaration describes its complete
eight-byte output and boolean result. The retail provider at `003a5180` has a
defined zero-or-one result on both exits, which its declaration preserves.
The current `003a2920` definition retains its `s32(s32)` address contract.

The animation setters/readers, 128-bit snapshot providers, effect/model callbacks,
geometry consumers, unsigned-halfword list selector, and `sdkOt` list insertion
were checked against their current definitions and retail where applicable.
The caller `00489e80` continues passing the particle pointer and `1.0f`.
Provider and SDK files were read and snapshotted; none was edited.

## Evidence

The immutable lane is
`build/finish-first-party-20260922/particle-next-02/`.

* `render-reviewed-02/` contains the exact final source, configured native
  compiler receipt, object, relocation/data proof, and source patch.
* `renderer-full-proof/SUMMARY.json` indexes all seventeen function proofs and
  all allocated data, including the new eight-entry switch table.
* `renderer-official-proposed/` and `renderer-official-live/` retain successful
  official verifier runs against the proposal and installed owner.
* `renderer-provider-review/` retains the read-only contract review and inputs.
* `renderer-lint/` records zero source-integrity findings.
* `renderer-installation.json`, `AUDIT.json`, `INVENTORY.json`, and `SEALED.json`
  record installation, native jobs, and evidence identities.

Official verification uses the unchanged `tools/verify.py` parser, comparisons,
and relocation checks. Its compile hook only authenticates the source,
configured compiler, flags, dependencies, and completed object, then copies
that object. No successful native compilation was replayed.

Final installed source SHA-256:
`b5c42ed0d1d1b6d2c0ca58c43a258a7a7dd6f2ecf2ab79db4f8ec6860833b7bb`.

Final native object SHA-256:
`b8ad172cb0e84e50df4c5076af011be43d191283f24ca950ce1334bfc27bdd81`.

## Remaining update function

`00487c30` remains an assembly fallback. All 53 earlier `particle-next-01`
completions were authenticated and preserved. Fresh parameter-lifetime,
complete VU memory-boundary, explicit unused-return, and inline return-adapter
experiments do not close its 27-word record/count register exchange. That
892-byte candidate is still nonexact and is not counted as a recovery.

The lane retains both failed fresh compiles: a parameter-view probe and the
first formatted proposal whose assembly strings were split inside instructions.
Their corrected or replacement candidates use new directories. Neither failed
result nor any earlier receipt was overwritten.

The prime authorized installation after final native, contract, lint, and
official proofs. The owner was then frozen for publication. This worker did
not commit, rebase, push, run a full build, or change headers or providers.
