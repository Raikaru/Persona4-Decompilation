# effGeometry 00483a00: native C match, 2026-09-21

`func_00483a00` now has a verified native C candidate under the real
`src/promoted/effGeometry.c` compiler configuration. Its 572-byte body matches
every retail instruction after resolving all 17 relocations. The remaining
four bytes of the 576-byte retail window are zero alignment bytes. The object
section has 16-byte alignment; no padding was added to the source.

The complete candidate owner has **17/17 MATCH** results from the repository's
verifier and **17/17 unmasked proofs**. All 16 neighboring functions retain
their original bytes and relocation destinations. The existing 28-byte
`.rodata` table, its seven relocations, and its alignment are unchanged; the
unmasked owner proof also resolves and checks its full contents against retail.

The production owner is unchanged. This worker prepared a patch for prime to
review and apply; no commit, rebase, or production edit was made. Neither
`mdlEffect` nor prime's separate `0052d9a0` target was edited.

## Handoff

All build evidence is under
`build/resume-completion-20260921/geometry-next/`:

| File | Purpose |
| --- | --- |
| `promote.patch` | Complete owner patch; `git apply --check` passed. |
| `native-review/effGeometry.c` | Clean, measured whole-owner candidate. |
| `review-body.c` | Readable target body, without owner declarations. |
| `native-review/owner.o` | Authenticated exact compiler output. |
| `native-review/result.json` | Zero differing words and all sibling comparisons. |
| `native-review/unmasked-proof.json` | All target relocations resolved to retail addresses. |
| `owner-unmasked-proof.json` | Every owner function and referenced owned table checked against retail. |
| `official-verification.json` | Repository verifier results for the saved candidate object. |
| `allocated-data-proof.json` | Original/candidate table bytes, alignment, and relocation identities. |
| `alignment-tail-proof.json` | Four-byte retail zero tail and real section alignment. |
| `SEALED.json` | Source, object, compiler, patch, proof, and input identities. |

`seal.py` authenticates saved outputs instead of repeating a completed compile.
It calls the unchanged `verify_file` comparison and classification logic with
the real logical owner, while supplying the candidate's markers and the
authenticated saved object. These are candidate results, not a claim that the
live source has already been promoted. The complete candidate was compiled
with the owner's actual flags before this cached verification.

The patch changes one owner, with 77 insertions and 92 deletions. It replaces
the guarded nonmatching body and its fallback, corrects the RenderWare
prototypes, supplies explicit conversions in two legacy sibling bodies, and
removes the obsolete floor comment. Those sibling conversions produce
identical machine code and relocation destinations.

## Native source mechanisms

Repeated vertex and triangle products let the compiler retain the expressions
across calls. The resulting compiler temporaries naturally produce retail's
`sq`, `paddub`, and `lq` sequence. The function has no explicit 128-bit local,
ordinary assembly, volatile access, or artificial side effect.

The `RwFrame` declaration must carry the SDK's real 16-byte type alignment.
An unaligned opaque declaration placed the saved frame pointer at `sp+0xc8`;
the public aligned typedef reproduces `sp+0xc0`. This alignment comes from
`include/rw/core/baframe.h:77`, `include/rw/ps2/ostypes.h:39-42`, and the public
`include/rw/sky2/rwplcore.h` definitions.

Using `RpMaterial **materials` and `materials[index]` produces the retail loop
with an ordinary `u16 index`. The earlier byte-address expression caused the
compiler to retain an unwanted counter conversion. The sphere uses the real
`RwSphere` layout: `RwV3d center` followed by a float radius.

The last eight differences were a swap between the retained vertex product
in `$s6` and the instance count in `$s5`. The exact source keeps construction
locals in a scope after the diagnostics, declares
`const s32 count = (u16)partCount` after the atomic local and before the loop
index, and uses `(s32)count` in both triangle products. The explicit conversion
preserves the desired expression lifetime with this compiler. Removing it
from the constant form rematerialized the product. Moving the declaration
changed allocation. Preserve the measured scope, declaration order, qualifier,
and conversion when integrating this result.

Renaming and formatting the successful source, removing its inert pragma
bracket, and removing stale prose produced an object identical to the first
exact candidate, `constant-instance-cast-before-counter/owner.o`.

## Provider and caller evidence

The declarations were checked against the provider implementations:

| Retail function | Actual contract and source |
| --- | --- |
| `003e9320` | `RwFrame *RwFrameCreate(void)`, `src/renderware/core/baframe.c:603-624`. |
| `003c00e0` | `RpAtomic *RpAtomicCreate(void)`, `src/renderware/world/baclump.c:2486`. |
| `003c4140` | `RpMaterial *RpMaterialCreate(void)`, `src/renderware/world/bamateri.c:339-377`. |
| `003c2630` | `RpGeometryCreate(s32 vertices, s32 triangles, u32 format)`, `src/renderware/world/bageomet.c:2125-2292`. |
| `003c1b90` | `RpAtomicSetFrame(RpAtomic *, RwFrame *)`, `src/renderware/world/baclump.c:5402-5417`. |
| `003c0210` | `RpAtomicSetGeometry(RpAtomic *, RpGeometry *, u32)`, `src/renderware/world/baclump.c:2621-2674`. |
| `003c2a80` | `s32 RpGeometryDestroy(RpGeometry *)`, `src/renderware/world/bageomet.c:2359`. |

`include/rw/world/bageomet.h:152-204` establishes the morph-target pointer and
bounding-sphere layout. `include/rw/plcore/batypes.h:360-364` supplies the sphere
fields. The complete owner and its callers `00483c40`, `00483e10`, and
`src/promoted/code1_0048.c:445-511` were inspected. The final public signature
remains compatible with their four signed-word arguments, with explicit
16-bit count conversions in the body.

Changing the public parameters themselves to `u16` was tested in an isolated
whole owner. That compiled but changed both native sibling callers; it was
rejected. No incompatible declaration or hidden alternate prototype was used
in the final candidate.

## Prior evidence and identities

The earlier `build/complete-20260921/geometry/` sphere probes were inspected
first. The authenticated prior best, `chained-rgba-white`, had 41 differing
resolved words. This run tested native expression retention and real provider
types rather than repeating that sphere-only search. The already extensive
`mdlEffect 0048a460` projection negatives were inspected and left alone.

The configured compiler is MWCCPS2 3.0.1 b210 with exactly `-O2 -Iinclude`.
Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

Clean candidate source SHA-256:
`f8d29bc15b4b8a4b55df5dfa8083bd6fe3ec712e3f12ee0b56968ecde7e0c029`.

Exact whole-object SHA-256:
`0c072f6dfb869d894bf66a72478c6ff9d4ac9a77b88a8b4a3d069543f9d06898`.

Patch SHA-256:
`5543ac59d6c04d550092203096b0b0078426379476e34f0a944ec41e72a7f0a8`.

Unchanged live owner SHA-256:
`233b3e2219b7bf0cc94d5aa2e2bbe33448096a0fa7f53d5ad2c0f29b992e5280`.

Retail ELF SHA-1:
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

The initial and progress messages to prime failed with
`AGENTS_BUSY: no agent family belongs to this conversation`. That affected
delivery only. The patch and complete evidence remain available in the shared
workspace.
