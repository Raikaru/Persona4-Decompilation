# Position constructor 002b2970 as one out-pointer signature

Goal: one declaration, `void func_002b2970(FclVec2 *out, f32 x, f32 y);`
in `fcl_draw_types.h`, with every caller written against it. The full
rewrite is on branch `wip/002b2970-out-pointer` (commit 1b60585). It does
not land because 15 matched functions regress.

## What holds

- The definition in code1_002b takes `FclVec2 *` and still matches.
- Every pointer-form unit (y_fclCombine, y_CmbCardEff, y_fclItemShopDraw,
  code1_002b, code1_002e, y_draw, y_smap) keeps all its statuses once the
  casts are dropped (`.bits` becomes `.position`). s64 stack locals and raw
  byte storage keep an explicit `(FclVec2 *)` cast.
- Every statement of the form `dst = func_002b2970(x, y);` in y_fclShopDraw
  (382 sites) and y_fclCombineDraw (100 sites) compiles to the same bytes as
  `func_002b2970(&dst, x, y);`.

## What breaks

Functions that pass the struct-return result straight into another call's
argument list depend on the compiler temporary:

- **Argument order.** b210 evaluates a call-bearing argument to the left of
  the constructor before it (002df020 case 1, 003218a0 inner loop), and a
  non-call argument that stays live across the call (`base + 4` in
  003147e0, `(s16)(row * step)` in 0032b9d0) before the constructor as well.
  A constructor statement hoisted ahead of the consuming call runs first.
- **Hoisting those arguments into named locals** fixes the order but moves
  saved-register colouring and the frame size. For example, 003218a0 comes
  out 0x10 bytes short, and 003147e0 goes from 17 differing lines to 370.
  In 0032b9d0 a single-use local is propagated back into the call, which
  puts the `mult` after the constructor again. That leaves 9 differing
  lines.
- **Colouring and copies.** In 002df020 the temporary is what puts `work` in
  `$s1`. The inlined `shopDrawLabel` receives the temporary through a float
  (lwc1/swc1) copy, but a named FclVec2 local copies with ld/sd.
- Where the temps are declared has no effect: function top, innermost
  block, or a new block around the statement all give the same diffs.

| unit | function | fndiff `!` lines | verify normalized diff |
|---|---|---|---|
| y_fclCombineDraw | 0032b9d0 | 9 | 34 |
| y_fclCombineDraw | 003147e0 | 17 | 56 |
| y_fclCombineDraw | 003218a0 | 19 | 69 |
| y_fclCombineDraw | 003191c0 | 40 | 143 |
| y_fclCombineDraw | 0031cce0 | 60 | 159 |
| y_fclShopDraw | 002df020 | 183 | 583 |
| y_fclCombineDraw | 00318840 | 323 | 1022 |
| y_fclShopDraw | 002de5a0 | 505 | 1667 |
| y_fclCombineDraw | 0031c2b0 | 521 | 1816 |
| y_fclCombineDraw | 00315600 | 707 | 2430 |
| y_fclShopDraw | 002d5040 | 835 | 2824 |
| y_fclShopDraw | 002dd3b0 | 852 | 2773 |
| y_fclCombineDraw | 00317900 | 821 | 2879 |
| y_fclCombineDraw | 00325450 | 3653 | 12925 |
| y_fclShopDraw | 002be530 | 6118 | 20311 |

Also tried and ruled out: an inline `FclVec2 shopPos(x, y)` wrapper around
the out-pointer call, which keeps the nested call shape. It is worse
(16 ShopDraw functions regress) because the inline's return adds a copy.
