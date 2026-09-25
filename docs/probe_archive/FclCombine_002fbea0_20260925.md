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

## Second pass (2026-09-25): 2963 -> 1465 (object 6537 / retail 6580)

Each lever is listed with its casealign total afterwards.
- `func_00275820`'s real float-first signature (2908).
- **0x8B rewritten from the retail listing** (2773):
  - an s16 `for` loop over `fB7`;
  - `f11E` re-read at every use (retail `lh 0x11e` each time, with no `base`
    temp);
  - a chained `= 0xFF` alpha store;
  - `FclDrawColor` values from `func_002b2a60` and struct copies.
- **Byte-wise colour code converted to struct form by script** (2056):
  - `fclWriteColorBytes(&wNNN, ...)` -> `FclDrawColor fc_wNNN =
    func_002b2a60(...)`;
  - `d0..d3` byte copies -> `*(FclDrawColor *)(e + 0x85) = ...`;
  - the m2c float -> u8 saturation block -> `(u8)func_002b2aa0(...)`.
- A greedy retype of the m2c `s64` temps to s16/s32 (1930).
- Then `(s64)((x + 1) << 0x30) >> 0x30` -> `(s16)(x + 1)` (1547). Before the
  retype this rewrite made things worse, because the variables were still
  s64.
- **Missing code restored in 0x98** (1465). The `D_008C0276 & 8` branch
  (`f123 = 1`) moves sprites 0x2EA/0x2EB/0x2E2/0x2E3 to x = 336/556/336/556;
  the draft had dropped all 84 of its instructions. Both the `& 8` and `& 4`
  branches copy the sprite position into a local `FclVec2f` (retail
  `swc1`/`swc1` then `ld`) rather than re-reading `ps + 0x38`.

Largest remaining cases:
- 0x98 (~349): `s64` temps still present (`dsll32 x, 0` pairs), `sq` spill
  slots, colouring.
- 0x8D (~259) and 0x9B (~239): the same shapes.
- The frame: 0x430 against retail 0x500.
