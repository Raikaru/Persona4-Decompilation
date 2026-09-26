# Item shop state machine `00332bb0`: MATCH, parked until the declaration cleanup lands, 2026-09-26

`src/Event/Fcl/y_fclItemShopDraw.c` `func_00332bb0` (37392-byte window: object 37380 B,
then 3 zero pad words) now matches. The source is not committed yet because a
declaration cleanup on `claude/dreamy-dirac-mtzltf` (it makes `func_002b2970`
struct-returning) was in flight. The full change is
`FclItemShopDraw_00332bb0_match_20260926.patch`, which applies with `git apply` on
`claude/dreamy-dirac-mtzltf`@3036eb5.

Measured with the patch applied:

- `verify.py src/Event/Fcl/y_fclItemShopDraw.c`: 9/9 MATCH. `fndiff`: 0 differing
  words.
- `verify.py src/promoted/code1_0033.c`: 38 MATCH and 1 ASM, unchanged from before.
- `python tools/build.py`: both SHA-1 OK. No WRONG SYMBOL lines.
- Lint: H003 is unchanged (the new pragmas carry a `measured` note). H011 goes
  from 2416 to 2415.

## The lever that closed the last 13 words

The draft was 13 words off: in case 5 → `D_008C024E & 0x40` → inner `switch
(work[1])` case 0, the loop counter and the slot index/font had swapped
`$s4`/`$s5`. What fixed it was declaring the counter and the slot index as
**block locals** of that `case 0` (`{ s16 n; s32 slot; for (n = 0; ...) }`):

- A fresh counter at function scope coalesces into the known-zero `$s0` and
  loses `move $s5,$zero`, which gives about 5953 words of diff.
- The same fresh counter in a block keeps the move. With the index in the same
  block, the colouring matches retail.

The draft measured declaration order as irrelevant, and that is still true.
Scope is what matters. All 64 subsets/orders of {counter, index, pos, font} as
block locals were tried: 18 give 0, and any order that puts the counter before
the index with more than one of the others also in the block gives 5953.

## Cleanup that keeps the match (greedy merges, each one measured to 0)

- The 43 per-loop counters are down to 15. 24 counters merged into `j`,
  i3+i6+i13+i27 became `i`, and i16 absorbed the case 11 twin-loop counter.
  i1 stays alone as `k`. The call-free loops (`$a*`) cannot share with
  call-crossing ones (5 words each).
- The font locals are down to 6: 153+626+760 became `labelFont` and 219+659
  became `rowFont`. `index` absorbed `index_s486`. The remaining locals got
  names instead of `_sNNN`.
- The stale probe-log comment above the function (about 95 lines) was replaced
  with a short measured note.

## Contracts (the one-signature rule)

The definitions that were changed in `code1_0033.c` all still match:

- `func_0033d630(F2_0033, s16, f32, u8 alpha, s8)`. The definition only matches
  with `u8` when this unit sees `func_002b2a60` with u8 parameters
  (`#define FCL_COLOR_ARG u8`). Otherwise `andi $s0,$a2,0xff` appears. Callers
  pass the `lbu` byte, which gives retail's `ld a0` / `lwc1 f12` / `lbu a2` order.
- `func_0033d4e0` and `func_0033d520` are `(u8 *, f32, f32, s8, s16, s64)`, with
  the floats first. That is the argument evaluation order retail shows, and the
  two layouts are the same under EE's ABI. This unit and `code1_0033.c` are the
  only users.
- `func_0033d310` returns `u8 *` (`return *(u8 **)(arg0 + 0x38)`). This unit is
  its only caller.
- In this unit, the declarations of `func_0033d320` (`s8` 3rd), `func_002b2cb0`
  (`s8` 5th) and `func_002b2d00` (`s32` return, `s8` 5th) now agree with their
  definitions, and the code is unchanged.
- `func_002b2a60`: the definition in `code1_002b.c` also matches with `u8`
  parameters (72 MATCH / 3 ASM, the same as with `s32`). This supports `u8` as
  its real type, but units that pass ints still use the `s32` view.

Still open (H011 in this unit): `func_002b2970` (struct-return, waiting on the
cleanup), `func_002b2a60`, and `func_0033d4b0`. Changing the `func_0033d4b0`
definition to `u8, u8, u8` breaks it, through `code1_0033`'s `s8` view of
`func_002b82d0`. There are also 25 findings from before this work
(`func_0045af60`, `func_002bab80`, `func_0046d200` and others).
