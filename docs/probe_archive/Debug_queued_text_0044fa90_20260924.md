# Queued debug-text renderer 0044fa90

The remaining renderer in `src/sdkDbprt.c` is recovered in ordinary C. The
configured MWCCPS2 b210 compiler with `-O2 -Iinclude` reproduces all 1,472
retail bytes, with twelve fully resolved relocations and no alignment tail.
All six neighboring functions, including the recovered grid renderer, retain
their native bytes and relocation meanings. Allocated data is unchanged.

This routine walks the queued debug-text nodes and renders up to 256 characters
per node, stopping at the terminating zero byte and skipping spaces. Nodes
with nonzero camera depth use the existing `func_00450490` projection helper;
the other path subtracts the node's depth offset from near-screen depth.
Both paths preserve their original vertex writes, per-channel unsigned color
conversions and draw calls.

## Complete source objects

`HDbText3D` now describes the full 0x118-byte object allocated by the existing
queue constructors: next pointer, X/Y coordinates, camera depth, 256 text
bytes, depth offset and four color bytes. The previous prefix-only type and
the renderer's separate inferred extension type are no longer needed.
Existing constructor and queue-walking functions compile unchanged.

The four vertices use complete 64-byte immediate-mode records. Texture
coordinates remain a separate eight-float array, with a real pointer to each
pair at the copy site. This preserves the retail address calculation and
avoids indexing beyond any scalar subobject.

The two atlas coordinates deliberately retain different integer domains:
the column is a signed remainder by sixteen and the row uses an unsigned
right shift. Keeping these domains distinct prevents the compiler from
merging the byte conversions and reproduces the original glyph lifetime.

The last two differing words were the X-addition operand order, one in each
depth path. Copying the computed character advance into its translation
input before adding the node's X coordinate preserves a separate multiply
and add in the correct order. This is the same measured value-copy pattern
documented for `func_002b2290` in `docs/matching.md`. It adds no generated
instruction, side effect or unobserved dummy operation.

Projected depth is calculated only when the node's camera-depth field is
nonzero at entry, as in retail. Near-screen depth alone is cached before
the other path's vertex loop; the node's depth offset is still read inside
that loop. No default value or additional calculation was introduced.

## Evidence

The resolved executable SHA-256 is
`91adf1a7408c5736426b0d1f6fa078c0fbd05dcd3ff6b2c5051f425a7ae62f60`.
The native proof independently checks all referenced queue, camera and raster
state words against their retail zero-filled storage. The four private state
objects and the text grid retain the exact placements established by the
previous grid-renderer recovery.

Candidate sources, objects, compiler receipts and measured alternatives are
in `build/finish-first-party-20260922/continue-39-dbprt/`; the reviewed final
case is `review-direct-fields/`. Installed verification, whole-object linker
admission, full-build hashes and publication records are in
`continue-39-integration/`.
