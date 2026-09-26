# btlShuffleResult `func_00382ea0`: shuffle result setup (MATCH)

Window 2176 B, object 2176 B. The owner's guarded draft stood at 396 words
(fnalign 72 edits). Relocations include `D_0064E6E0`, `D_0064E700`,
`D_0064EC70`, gp `iGpffffa9B8`, and the 0036e910/002baac0/00106330/0015a190/
00107890/RpRandom/00377eb0/00109220/002bbd20/002bad10/0038d2a0/00380bd0/
00378530/0036e000/0046d730 calls.

Levers, all load-bearing:

- Retail has four copies of the bonus-chance code. They are two static inline
  helpers, used by cases 0 and 2: a roll that returns 1/0 (it joins in `$v0`
  before `beqz`) and a pick over the cumulative weights. Written out by hand,
  the draft was 396 words; with the helpers it was 176.
- `D_0064E6E0` and `D_0064E700` are `u8 [][2]` tables indexed
  `[level][column]`. Retail forms `base + level*2`, then adds the column. The
  pick hoists `&D_0064E700[0][column]`.
- The column comes from a third helper,
  `static inline u8 shuffleBonusColumn(void) { return func_0015a190() ? 1 : 0; }`.
  Only this form reproduces retail's `sltu $v0` / `andi $sN,$v0,0xff` pair.
  These all emit `sltu $sN` directly: `x != 0`, `(u8)(x != 0)`,
  `(x != 0) & 0xFF`, `!!x`, `x > 0`, and helpers that return `x != 0`. The
  roll's column also works as an inline `func_0015a190() ? 1 : 0`, but the
  pick's does not.
- `thresh`, `chance` and `sum` are s32 locals that hold explicit `(u8)`
  conversions. The roll compares `(u8)chance < (u8)thresh`. With u8 locals,
  b210 merges the two threshold stores after the join, and it re-masks
  `chance` inside the pick loop.
- `(&iGpffffa9B8)[rate]` must index from the scalar's address. Declaring
  `iGpffffa9B8` as an array rotates the prologue's saved-register copies.

The same `sltu`/`andi` column idiom appears as an array index in
`func_00381a70`, which is still ASM.
