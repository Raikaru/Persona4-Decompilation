# Shop panel intro setup: func_002db400 recovered, 2026-09-25

`src/Event/Fcl/y_fclShopDraw.c::func_002db400` is active C and **MATCH**
(1930 instructions, frame 0x210). The file went from 29 to 30 MATCH.

## Starting point

The guarded draft (nd 1663 in older notes, 102 fnalign edits after the
2026-09-20 narrowing/hoist pass) wrote colors with `fclWriteColorBytes` into
`RGBA` locals, which costs 17 extra byte moves per group and a 0x2f0 frame.

## Levers, in order (fnalign edits)

1. `cN = func_002b2a60(..)` into `FclDrawColor` locals, stored whole at
   `t + 0x79`. Vec2f slots are passed to `func_002e0620` as `*(u64 *)&spN` (the
   file idiom after the Vec2f-return change): 778 dropped to 98.
2. `func_002e09b0` has the real signature `(void *, f32, s16)` (see
   `src/promoted/code1_002e.c`). The file prototype `(void *, s32, f32)` swapped
   the `lw $a0`/`lh $a1` order. Every call site in the file, including the
   guarded drafts, was rewritten to the real order: 98 dropped to 92.
3. The six `D_0063FA70..98` tables are read through
   `ShopSpinParam { f32 angle; s16 speed; s16 frames; }` instead of an `s16 *`
   plus `*(f32 *)` pun. That fixes the `180.0f + angle` constant/load order at
   the `func_002e0940` calls: 92 dropped to 84.
4. `if (func_002e26f0(list) <= D_00748908[n])`, with the call on the left:
   84 dropped to 60.
5. The rest was a `$s1`/`$s2` swap between the `func_0046d200` handle and the
   table base. Declaration order, `u8 *`/`s32` handle types, per-group table
   pointers and `opt_propagation off` (much worse, 1307) did not move it. A
   separate handle variable per group does, and the committed form scopes each
   `void *r = func_0046d200(..)` in its own block: 60 dropped to 0.
