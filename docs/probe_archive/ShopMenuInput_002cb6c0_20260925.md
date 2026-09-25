# Shop menu list + input: func_002cb6c0 recovered, 2026-09-25

`src/Event/Fcl/y_fclShopDraw.c::func_002cb6c0` is active C and **MATCH**
(2605 instructions, frame 0x230, nine saved GPRs plus `$f20`). The file went
from 30 to 31 MATCH. `src/Yajima/y_list.c` stays at 31 MATCH / 6 ASM.

## Shape

The function draws the scroll arrows and header, then five stock rows. Each
row gets a colour set chosen by stock (`func_00106a90` against
`func_002e7a60`), the 0x63 cap, the moon-phase bit and the cursor, followed by
the icon, name and count. The rest is pad handling: page and cursor moves
through `func_002b2cb0/2d00/2d50/2e70/2f90`, tab switches through
`func_002e2a10` and `func_002d8200`, the buy and sell confirms, and the
exit-to-panel setup, which reuses the six-spinner pattern of `func_002db400`.

## Levers (fnalign edits, from the archived 567 floor)

- The draft re-extracted after the file-wide Vec2f change measured 1042. File
  idiom (FclDrawColor, Vec2f slots with `*(u64 *)&` for `func_002e0620`,
  `pos = *(Vec2f *)&sp1C8`, `func_002e0970` taking two FclDrawColor by value)
  brought it to 461.
- A full rewrite from the retail listing: 92. Its main parts are block-scoped
  `func_0046d200` handles, bases assigned at group heads, `> 5`/`> 0` compare
  forms, s8 `work[0x14]`, `F3C` as s16, colour copies as whole FclDrawColor
  moves, an if/else-if chain with early returns ending in the shared
  `work[0x14] = 0`, switch labels in 0/1/2 order, and scoped
  `opt_loop_invariants on`.
- Callee contracts from the real definitions:
  - `func_002e2740` and `func_002e26a0` return int, and retail re-extends at
    each use. `y_list.c::func_002e2740` became `s32`; it is byte-identical.
  - `func_002b2d50` takes s16 arguments (`code1_002b.c`).
  - `clndGetMoonPhase` is used as `(u8)..& 1`, which keeps retail's
    `andi 0xFF; andi 1`.
  - `icon` is s32, so no hoisted u16 mask is emitted.
  - A stock compare written as `stock > func_002e7a60()` gives the `sltu $at`
    form.

  Together: 92 dropped to 61.
- `D_008C024E/0276/027A` and `D_0063FA40/44/46` are declared as arrays. As
  scalars, mwcc placed them in small data (`$gp`). Retail uses `lui` absolute
  addressing. All uses in the file were rewritten to `[0]`: 61 dropped to 35.
- A `ShopMenuWork` overlay typed as `work` itself, with all fields as members.
  Only this form gives retail's `idx + work` operand order for
  `kind[sel]`/`icon[sel]`; casts or a second pointer grow the frame: 35
  dropped to 27.
- The last two: the header arrow colour passed inline to `func_002e0b20`
  (retail's `$s1` temp), and the D60 pair written as a chained
  `field_100 = field_102 = 0`. The chain is what produces retail's
  `dsll32 $s1, $zero, 16`; `(s16)0`, `(s16)0.0f`, `(s16)(0.0f / 2.0f)` and
  `(s16)(s64)0` all fold it away. 27 dropped to 0.
