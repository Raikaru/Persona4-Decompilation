# Route search 001eed10 recovered

`func_001eed10` (1024-byte window, 256 instructions, frame 0xB0) is MATCH in
`src/promoted/code1_001e.c` (117 MATCH / 3 ASM, previously 116 / 4).
MWCC b210 `-O2`, no pragmas (the old guard's `opt_propagation off` is gone).

Fresh body written from the retail assembly rather than the P023 draft
(which scored 80 edits once enabled). Measured steps (fnalign edits):

- straight rewrite with raw offsets: 96;
- endpoint copies through two float temps (`x`, `z`), matching retail's
  load-load-store-store pairs: 69 (with the membership helpers below);
- prototypes for `func_001ed700(f32)` / `func_001ee610(u8 *, f32)` in scope
  (the call otherwise went through `fptodp` as an unprototyped double): 62;
- open/closed membership as two `static inline` helpers returning 1/0 -
  their returns give retail's `inX = 1; b` / fall-through `inX = 0` joins;
- `RouteNode` struct for g/f/openNext/closedNext/parent/x/z: 52;
- node taken straight from `func_001eec60()`, closed-list removal reading the
  neighbour once into `removed`: 17;
- declaration order (`index` before `found`): 6;
- neighbour/distance arrays indexed as `(u8 *)node + index * 4 + field`
  (`ROUTE_NEIGHBOR`/`ROUTE_DISTANCE`), giving retail's `addu base, idx`
  operand order; `node->neighbors[index]` gives `addu idx, base`: 0.

Retail's `nop; nop` inside the closed-list unlink loop is reproduced by this
plain loop; it is not an alignment artifact to work around.
