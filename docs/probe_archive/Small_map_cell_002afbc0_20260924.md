# Small-map cell renderer 002afbc0

The recovered `src/promoted/y_smap.c` callback draws a visible map cell and its
optional icon. In scrolling mode it computes the position relative to the map
origin and consumes the cell's pending draw request. In fixed mode it computes
the position directly from the row and column. The reveal flag and the row's
visibility bitmask retain their original branches and call order.

Native MWCCPS2 3.0.1 b210 with the owner's configured `-O2 -Iinclude` emits
1,624 bytes in the 1,632-byte retail window. All 28 relocations resolve exactly;
the final eight retail bytes are zero alignment. The reviewed source preserves
all 35 other functions, their canonical relocations, and both existing 24-byte
relocated data tables.

## Source representation

`func_002b0250` allocates the complete 0x160-byte cell. `SMapCell` describes the
position, offsets, dimensions, byte-valued row/column and visibility fields at
their observed offsets. Its four queued vertices occupy the existing 0x100-byte
region beginning at 0x40. A compile-time size check verifies the whole record.
The renderer retains the two separate field-data lookups used to obtain the
visibility row and column; it does not cache calls across observable operations.

The origin calculation writes a complete two-float object. Copying that object
to the second element of `YVec2f origin[2]` reproduces retail's two loads followed
by two stores. The `func_002b2bd0` declaration now agrees with its existing
signed-64-bit mode parameter in `src/promoted/code1_002b.c`.

The map-shape call uses a coherent position/width/height/origin/depth/scale/color/
orientation/layer declaration. Both callsites and the retained implementation of
`func_002b0b10` use that order. The integer and floating argument banks retain
their retail values. A direct texture-handle-to-pointer conversion also preserves
the original call preparation without an unnecessary unsigned intermediate.

No optimization pragma, hardware assembly, register binding, fabricated effect,
or object-byte change is used. The complete typed cell and descriptive local
names preserve the exact native result of the retained discovery.

## Evidence

The resolved target SHA-256 is
`bb61f31a09ecc0f2a20fffa780fcb66a8e03cbed88c3cc7cd2424edfbac02eff`.

The retained discovery is under
`build/finish-first-party-20260922/continue-68-smap/draw-size-origin/`.
The reviewed source, native object, compile receipt, relocation proof and
sibling/data comparisons are under
`build/finish-first-party-20260922/continue-69-smap/typed/`.
Installed-source verification and actual source-link/full-build publication
records are recorded separately in `continue-69-integration/`.
