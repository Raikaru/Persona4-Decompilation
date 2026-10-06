# Exact After geometry recovery, 2026-10-06

`after-promoted.c` replaces `func_004b8350` with ordinary C that produces all
2720 retail bytes exactly. There are zero differing words after resolving
every code and data relocation. The function is promoted in the default
owner, its obsolete strip helper and ASM fallback are removed, and its
remaining guarded sibling is preserved.

`changes.patch` applies directly to the original After and afpack owners.
It also carries the reviewed, byte-neutral afpack caller type correction.
Prime reviewed and released direct installation of both hashes. Worker-7
installed them after checking the exact original hashes and froze both owners
for batch 3. No commit or push was made.

## Source binding

| File | SHA-256 |
| --- | --- |
| `after-promoted.c` | `3c90fbf82d7de3a5faa2fc8e3e01fba7dbb37d79181d7a11c6a13e8f7130154a` |
| `afpack-caller.c` | `48c64b226a673af50b33cd4b7b75ab92236cef4e5a9da7309ea92f61a4fdc6de` |
| `after-original.c` | `836fc3161273a2c3e56e052202209c3bb499fba6bd514de87b2f59ea8c36faf8` |
| `afpack-original.c` | `523b41c037b0b2aaa74a524db920aa49b4fcca17f78765332f7ab264a00e7289` |
| `after-reviewed32.c` | `45c0c306ad74e7fb6196225b3ada39999849f23625f5e2928b3d805f27f170f0` |

The previously reviewed typed recovery and ABI rationale remain in
`../After_geometry_004b8350_20261006`. That 32-word proposal was used as the
scratch starting point and was not installed as an intermediate change.

## The remaining source issue

The reviewed candidate had exactly the retail instruction stream except
that its retained vertex count used `s3` and its topology cursors used `s2`.
Retail used `s2` for the count and `s3` for those cursors. All 32 differences
were consequences of that one register exchange.

The inlined strip helper created a separate advancing triangle cursor for
each of the two strip modes. In the compiler's actual graph, those inline
cursor values were numbered after all ordinary function locals. Moving
declarations within the caller could not move the vertex-count value past
the inline cursor; the previous neutral declaration families followed from
that constraint.

The exact source expresses the same two strip branches directly. Each has
an explicit `RpTriangle *` cursor declared with the function's other geometry
pointers, before the retained vertex count. Each cursor is initialized from
the geometry's triangle buffer and is used by that branch's cap, strip and
tail writes. The two branches retain their own loop index and 16-bit vertex
index. These are real values with the native lifetimes, and there are no
unused liveness expressions, dummy arguments, forced spills or output edits.
The first probe of this source change produced the exact result.

## Observational compiler evidence

`allocation-evidence/capture-receipt.json` records the unmodified configured
Metrowerks b210 compiler, GDB, debugger profile, command, inputs and hashes.
All 49 snapshots completed without errors or input drift. The directly
compiled and debugged object files had the same SHA-256:
`c84fb757b69d71de823e2b218b1cd6e87a66510ff3a0b8c00f9684f94edd93b3`.
The target bytes and canonical relocation identities also equaled the
normal complete-owner compilation. The debugger only observed the compiler.

The retained post-color graphs reproduce the actual color assignments.
The simplify routine at compiler address `004c1de0`, read from its existing
binary, was separately replayed on the observed 428-node graph. Every
simplification order entry and every final dynamic degree were reproduced.
The threshold is 25, derived from the captured ordinary and fallback
register sets. This models simplification of an observed graph; it does not
claim to reconstruct the compiler's liveness or graph-building passes.

At the decisive point the remaining values are work pointer 32, geometry 35,
vertex count 41, first inline cursor 67, strip vertex 69 and normalized vertex
172. Ascending simplification removes them in that order. Reverse coloring
then gives cursor 67 `s2` and count 41 `s3`. Giving the actual branch cursors
ordinary local lifetimes places them before the count and predicts the exact
register exchange. No compiler settings changed for the successful probe.

`allocation-evidence/binding.json` hashes the retained graphs, their replay
results, native compiler disassembly, source probe and capture receipt.
The capture driver is retained with its original session paths and source
guard; the standalone simplification check uses only the archived evidence:

```powershell
build/venv/Scripts/python.exe -B -Xutf8 docs/probe_archive/After_geometry_004b8350_exact_20261006/replay_simplification.py
```

## Native behavior and ABI review

`native/contracts.json` binds six functions to the verified retail image.
Their disassemblies preserve absolute call targets. The three geometry
providers establish the following contracts directly:

* `003c2130` stores the three 16-bit vertex indices at triangle offsets 0, 2
  and 4 and returns the geometry pointer. Its declaration is
  `const RpGeometry *(const RpGeometry *, RpTriangle *, u16, u16, u16)`.
* `003c2150` uses the material argument to find or append a geometry material,
  stores the resulting 16-bit material index at triangle offset 6, and
  returns the geometry or null. Its three pointer arguments are preserved.
* `003c2630` takes signed vertex and triangle counts plus unsigned flags.
  It allocates eight bytes per triangle and texture coordinate, four bytes
  per prelight color, and stores their pointers at geometry offsets 0x2c,
  0x34 and 0x30. The geometry and morph-target objects remain provider-owned.

The sole builder caller at `004b6900` creates a material at `004b6a4c`, stores
it in the second word of its eight-byte record, and reloads that word into
the builder's second argument at `004b6ae4`. `afpack-caller.c` expresses that
argument as `RpMaterial *`; its generated code and relocations are unchanged.

The complete C body was reviewed against the native builder. Mode 0 retains
its two-triangle strips and final triangle. Modes 1 and 2 retain two leading
triangles, four per section, two trailing triangles, and the 16-bit advancing
vertex value. Material assignment reloads the triangle base. Color and UV
loops retain their mode-specific counts, offsets, interpolation and strides.
`RpTriangle`, the UV pair and the bounding sphere are complete eight-, eight-
and sixteen-byte objects. All three sphere coordinates and its radius are
initialized before the complete sphere copy. No provider signature, source
behavior or object extent was weakened to obtain the match.

## Complete-owner validation

`proof/owner-proof.json` records nine complete-owner compilations, source and
compiler hashes, flags, included inputs, every function and canonical
relocation, fully resolved target words, and every allocated data section.
Nonmatching functions were excluded when establishing local-data placements;
unchanged sibling references supplied the anchors, and all placed data bytes
and pointer values were checked against retail.

| Complete owner | Geometry 004b8350 | Update 004b8f40 / loader 004b6030 |
| --- | --- | --- |
| Original After, default | ASM, 2720 bytes, 0 words | ASM, 7728 bytes, 0 words |
| Original After, both guards enabled | C, 2676 bytes, 626 words | C, 7728 bytes, 1845 words |
| Reviewed After32, both guards enabled | C, 2720 bytes, 32 words | C, 7728 bytes, 1845 words |
| Promoted After, default | C, 2720 bytes, 0 words | ASM, 7728 bytes, 0 words |
| Promoted After, all guards enabled | C, 2720 bytes, 0 words | C, 7728 bytes, 1845 words |
| Original afpack, default | — | ASM, 2256 bytes, 0 words |
| Original afpack, guard enabled | — | C, 2220 bytes, 535 words |
| Typed-caller afpack, default | — | ASM, 2256 bytes, 0 words |
| Typed-caller afpack, guard enabled | — | C, 2220 bytes, 535 words |

All 11 After and nine afpack default functions resolve exactly. Every normal
and guarded sibling's size, code and canonical relocations are unchanged in
the corresponding before/after builds. Both owners' allocated data and data
relocations are preserved. The exact geometry result is unchanged with all
guarded siblings enabled. No input drift occurred. The other two functions
remain guarded and are not claimed as exact C matches by this package.

To replay the complete proof, choose a fresh output directory:

```powershell
build/venv/Scripts/python.exe -B -Xutf8 docs/probe_archive/After_geometry_004b8350_exact_20261006/replay.py --output build/finish-20261006/after-exact-recheck
```

This produces one new exact C function. The full-image integration count and
final installation receipt are owned by prime's batch verification.

`installation-receipt.json` and `installed-verify.json` record the checks of
the actual installed source paths: 18 MATCH and two ASM functions, zero lint
errors, and a clean `git diff --check`. Lint reports the justified local
loop-invariant pragma and five unchanged afpack declaration warnings outside
this change. The approved source hashes remain frozen for batch 3.

This durable archive contains source, text and hashes only. Binary objects
and resolved byte streams from the completed proof were retained in worker
scratch; `binary-evidence-locations.json` records every location and SHA-256.
