# Item list panel `0033c490` recovered, 2026-09-25

`src/Event/Fcl/y_fclItemShopDraw.c` `func_0033c490`: 1836 bytes of code plus 4 bytes
of zero alignment, filling the 1840-byte window. It is a MATCH. The unit is now
8/9 MATCH; only `func_00332bb0` (37392 bytes) is still on INCLUDE_ASM. The old
draft was 1856/1840 bytes and 326 words off. Rebuilt from retail asm, this body
started at 357 words off.

## Contracts corrected (evidence from retail call sites)

- `func_002caa10(s64 position, f32 depth, s32 color, u32 number, s16 glyphBase, void
  *sprite, s32 style)`. Every caller loads `$f12` (62.0 here and 1.0 in
  `00332bb0`). This matches the typed definition in `y_fclShopDraw.c`. The two
  draft call sites in `00332bb0` now pass the 1.0 depth.
- `func_002e2740` returns `s64`. Retail passes the result to `func_0033cbc0`'s
  `s64` parameter and to `clndGetMoonPhase` with no extension, and sign-extends it
  only for the `s16` consumers. `clndGetMoonPhase` is viewed as taking `s64`.
- `func_002e2670` returns `s32`. Retail compares the result directly, with no
  sign extension.
- `func_002b2a60` takes `u8` components in this unit, declared locally. The
  include of `fcl_color.h` was dropped because nothing compiled here used it.
  The loop passes its u8 colour locals with no `andi`. Under the shared int view
  there are 4 extra words. Switching the shared header to `u8` breaks 4 matched
  functions elsewhere (`0033d630`, `00348c40`, `002b6590`, `002b74f0`), so the
  byte view stays local. The 4 draft `fclWriteColorBytes` uses in `00332bb0`
  became direct struct stores.

## Shaping levers (in the order they closed the diff)

- Split the pos/colour pairs for the header and for the rows. This gives retail's
  F0/FC and E8/F8 slots and the 0x100 frame.
- Read the cursor tables through an `F2_0033 *` (`tbl->x`, `tbl->y`). With
  `f32 tbl[]` indexing, the address constant is folded per use. The struct base
  keeps `$s1` live across the `func_0033d320` call, as retail does. Neither
  `opt_propagation off` nor `opt_pulloutconstants off` was needed. Both regressed
  elsewhere.
- Make the row frame and row name `static inline` helpers with an `f32 y`
  parameter, and pass the name helper `s16 item`. Compute the row top once in
  an int local `top = y + 0x4D`. This produces retail's `sq`/`lq` spill of top
  and the per-helper `cvt.s.w $f20`. It took the diff from 147 to 30 words.
- Pass `func_002b2a30(...)` directly as the name helper's argument, with no
  colour local. This makes the value a compiler temporary that is spilled with
  `sq`, as retail does, rather than `sw`. It took the diff from 30 to 6 words.
- Write the shaded colour as `green = blue = 0`. The assignment value converts
  back to u8 and gives retail's `andi $s3,$zero,0xff`.
- The row colours are `u8`, so their constants are built with `daddiu`. Brute
  force over u8/s16/u16/s32 per channel found nothing better.
