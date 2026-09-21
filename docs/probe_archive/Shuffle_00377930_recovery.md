# Projected shuffle quad: 00377930

The current btlShuffleDraw owner now contains ordinary C for `func_00377930`.
Fresh native MWCCPS2 b210 `-O2` compilation reproduces **1236 executable bytes
in the 1248-byte retail window**, with all **17 code relocations** applied and
twelve verified zero alignment bytes. No optimization pragma was added for
this recovery.

The implementation constructs a quaternion-derived matrix, translates it to
the card position, projects four corners and draws an untextured four-vertex
strip. The optional alpha-state disable/restore calls retain their condition,
order and final matrix destruction.

## Corrections to the old guarded body

The prior quad initializer mixed the coordinates of different corners. The
accepted vertices are `(halfW, halfH, 0)`, `(-halfW, halfH, 0)`,
`(halfW, -halfH, 0)` and `(-halfW, -halfH, 0)`, in retail order. Actual vector
and quaternion value copies replace the disconnected scalar copies, and the
vertex index has a lifetime separate from the input position pointer.

The nine products used to populate the rotation matrix are explicitly
captured before its stores. The source quaternion sum is
`x*x + y*y + z*z + w*w`: this owner's compiler emits retail's accumulator
order from that spelling. Writing `y*y` first produces two different raw
instruction words even though the earlier alignment display reports zero
edits because it does not decode those EE accumulator instructions. The
acceptance proof compares their actual fully relocated bytes.

The two entry-address calculations use one inline offset helper with the
actual index and base, reproducing retail's addition-operand order. The color
components use native unsigned-to-float conversions. The reciprocal-Z store
follows the color stores, matching retail's alias-visible ordering.

## Native types and caller consistency

`include/btl_shuffle_draw_internal.h` records the PS2 sky2 vertex layout from
the recovered P3 RenderWare header, independently confirmed by P4's 0x40-byte
stride and field offsets. It has a 16-byte-aligned four-quadword overlay and
the actual `RwSky2DVertex` tag. The function writes screen position at offsets
0, 4 and 8, reciprocal Z at 0x18, and float color at 0x20..0x2C. Texture,
normal and padding fields are not given artificial initialization: this draw
disables texturing and follows the original native vertex contract.

The shared declaration takes the optional position as a pointer to an actual
three-float value. All eight external calls and all three previous local
declarations in `code1_0038.c` were reconciled. In `0038c770`, the existing
three-float input becomes the shared vector type; its producer and projection
calls retain the same buffer addresses and values. The actual projection
interfaces use byte pointers and receive explicit address conversions.

Matrix creation, translation, transformation and destruction declarations now
agree with their active RenderWare providers, including the matrix/vector
tags and combine-mode enum. The camera getter's existing integer address
return is explicitly converted for the real camera FOV provider. Native
render-state and primitive function pointers use the actual state/primitive
enums and PS2 vertex pointer instead of incompatible integer/void-pointer
function types. Existing callers in the shuffle owner were updated together.

The completed character-lookup correction in `00380bd0` was already present
when this renderer was integrated. The two independent patches were combined
on that current owner, preserving its `u16` character argument and exact code.

## Validation

All **51 non-target shuffle-owner functions** and its **four allocated data
sections** retain their bytes and canonical relocation records. The external
owner preserves all **95 functions**, its complete object and its allocated
data. Separately enabling the affected guarded callers `00383f80` and
`00387750` also gives identical complete before/after objects. They remain
assembly-backed and are not counted as new recoveries.

Protected full relocation proofs in the final live objects include:

| Function | Executable/window bytes | Relocations |
| --- | ---: | ---: |
| `00377eb0` card constructor | 800/800 | 22 |
| `00374d20` earlier shuffle recovery | 1732/1744 | 37 |
| `00380bd0` character caller | 424/432 | 7 |

The official two-owner verifier reports **127 MATCH / 20 ASM over 147
functions**. Its first-party subset is 125 MATCH / 17 ASM over 142 functions;
the other five functions are attributed to middleware. There are no
unexpected statuses. Scoped lint reports zero errors and the two existing
loop-invariant advisories; whitespace checks pass.

The shuffle owner remains C-link eligible. The external owner's existing
ineligibility, gaps and unresolved references are unchanged. No C-linked
coverage is lost.

Current-source compiler/dependency receipts, full resolved instructions,
function/data comparisons and both placement reports are in
`build/first-party-next/shuffle-render/current/proof.json`.
`official-current.json` holds the official result. Immutable input copies,
all intermediate candidates and the independent caller integration proof
remain below the same scratch directory. The prior guard and historical
archive were retained there before replacement.

```text
python tools/verify.py src/Battle/btlShuffleDraw.c src/promoted/code1_0038.c --json build/shuffle-render-verify.json
```

The independent proof implementation is
`build/first-party-next/shuffle_render_current.py`; subsequent source changes
require a new receipt/output directory. This scoped result is distinct from
the complete integration build and the remaining first-party recovery work.
