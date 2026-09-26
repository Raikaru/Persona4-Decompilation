# Shop tab colours 002d4760: natural-source pass

Follow-up to `ShopDraw_002d4760_20260925.md`. The function still matches
(0 reloc-masked words, whole unit 37 MATCH / 1 ASM as before). This pass
rewrote the body in a form closer to what the developers probably wrote.
Every step below was measured with `tools/fndiff.py`.

Status: the source was not committed because src/ was frozen for the
declaration cleanup. The whole replacement (macros, comment and body, from
the line before `// FUN_002D4760` up to `// FUN_002D4F30`) is
`ShopDraw_002d4760_natural_body_20260926.c`. On 604f2bd it measured
fndiff 0, y_fclShopDraw 37 MATCH / 1 ASM (unchanged), decomp_lint 0 errors
and 4 warnings (the existing H003 pragmas elsewhere in the file), and build.py
passed with both SHA-1 OK. It uses only the existing file-scope prototypes
(`func_002e04e0(void *)`, `func_002e26f0(void *)`,
`D_00748908`) and adds no local externs.

## Kept (still MATCH)

- `ShopWork *work` with `work->field_EC4` etc. and a
  `SHOP_SPRITE(h) ((ShopWork *)func_002e04e0(h))` macro for the sprite
  stores (`->field_FC`, `->field_8`, `->field_79/7A/7B`). This replaces the
  raw `*(T *)((u8 *)func_002e04e0(*(void **)(work + off)) + off)` casts.
- The draw cases are written as plain statements. `row = y[j];` sits
  right before the first y store, `ca = colorA[j]; r = ca[0];` sits before
  the first colour store, and `cb = colorB[j];` before the third sprite. That
  is the same code as the old `(yr = y[j])[0]` / `r = (ca = colorA[j])[0]`
  expressions, because the address is formed lazily either way. The
  `switch (j)` stays because retail really has three copied cases.
- Colour setters as do-while macros with component pointers:
  `SHOP_SET_GRAY(rgb, v)` (declares `b_ = &rgb[2]` and then `g_ = &rgb[1]`,
  then `rgb[0] = *g_ = *b_ = v`) and `SHOP_SET_RGB(rgb, r, g, b)` (declares
  `g_`/`b_` and stores r, g, b). They replace the hand-written `a1p/a2p`
  blocks, the `ga/ba/gb/bb` function locals and `(u8 *)colorA + i * 4`.
  The later `SHOP_SET_GRAY(colorA[i], 0x9C)` is CSE'd with the addresses from
  `SHOP_SET_RGB`, which gives retail's saved-register g/b addresses.
  In `SHOP_SET_RGB` all three declaration orders measured 0.
- `for (i = 0, sel = arg1; i < 3; i++)` in place of
  `i = 0; sel = arg1; for (; ...)`: 0.

## Ruled out

- `RGBA colorA[3]` / `RGBA colorB[3]` (struct array; any access shape or
  declaration position): the frame grows from 0x100 to 0x120 and every stack
  offset moves (~300 words). The rows stay `u8 [3][4]`.
- Plain chained stores `colorA[i][0] = colorA[i][1] = colorA[i][2] = v`: 358.
  A row pointer `u8 *c = colorA[i]; c[0] = c[1] = c[2] = v`: 365.
- `SHOP_SET_RGB` as a comma expression, as plain statements, or as a
  do-while through one row pointer `c_`: 82 / 82 / 300. The g/b addresses
  are then formed as `sp+0xF1` rather than `row+1`.
- Draw loop without the r/g/b temporaries (`ca[k]` read again for the
  second sprite): 256. Direct `colorA[j][k]` in every store: 332.
- `work->field_F18[i]` (and `i[...]`, `*(field_F18 + i)`,
  `(&field_F18[0])[i]`, `field_F18[(s32)i]`): 1 word (`addu v1, v0, s3`
  instead of `addu v1, s3, v0`). Kept `*(void **)((u8 *)work + 0xF18 + i * 4)`
  with a comment in the source.
- `sel` dropped (compare `i == arg1`): 385. `s32 sel = arg1;` as an
  initializer: 55. `sel = arg1; for (i = 0; ...)`: 4.
