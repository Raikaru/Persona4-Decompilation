# func_002fbea0 (y_fclCombine) — made compilable, cases reordered, not matched

Measured 2026-09-25. Production stays `INCLUDE_ASM`; best body is
`FclCombine_002fbea0_20260925_body.c`.

Retail: 26320 B = 6580 instrs, frame `-0x500`, `jtbl_00749280`,
states 0x8A..0x9F (22 cases; 0x8C is empty and shares the epilogue).

- The guarded draft no longer compiled: `func_002b6140` and `func_002b29e0`
  now take `u8 *` in the file's declarations. Cast the ten call sites.
- **Case order.** MWCC lays out case bodies in source order. Retail order is
  0x8A, 0x8B, 0x8D, 0x95, 0x96, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x97,
  0x94, 0x98, 0x9D, 0x9E, 0x9F, 0x99, 0x9A, 0x9B, 0x9C, (0x8C). With the
  draft's numeric order the per-case alignment scored 8151; reordered, 3018.
- `(s64)((x << 0x30) >> 0x30)` (shift inside the cast, undefined on `s32`)
  -> `(s16)x`; `p + off` accesses -> struct `FclCombineSel`; loop counters
  `var_16/var_18/var_19` -> `s16`: 2963.

| measure | this body |
|---|---|
| object instrs | 7079 (retail 6580) |
| fnalign edits | 6731 (whole-function difflib is lost at this size gap) |
| differing words (probe_archive.py) | 5811 |
| per-case aligned edits | 2963 |

Oversized cases (retail/object): 0x8B 243/278, 0x8D 836/972, 0x98 1231/1329,
0x9B 741/924, 0x9C 359/407. These still carry m2c temporaries (`s64`
counters, duplicated `func_0034ae50` lookups) and need the same rewrite that
002ed430 got.
