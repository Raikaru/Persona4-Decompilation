# Calendar panel draw 0027bf30: rewrite at 22 edits

`func_0027bf30` (2992-byte window, 747 instructions, frame 0x110) stays
INCLUDE_ASM. `CalendarPanel_0027bf30_20260926_body.c` is a fresh rewrite from
the retail listing. It scores 22 fnalign edits (747/747); the guarded draft
scores 218.

The body needs one declaration fix in code1_0027.c:
`func_001104d0(s32 date, s32 *month, s32 *day)` (retail passes the date
unextended; the file declares `s16 year`, and the two other callers already
cast to s16 so they do not change).

What moved it (fnalign edits):

- `switch (state) { case 4: ... }` gives retail's `beq; b end` entry. The
  `handle == NULL` early exit is a `break`.
- `**(void ***)(handle + 8)` for the texture (retail dereferences twice),
  RpRandom-free: 218 -> 112.
- Declaration order sets both stack slots and registers: `month, day,
  depthColor, color[4], rect, appear[6], ...` for the frame, `alpha, x, y,
  rot, fade, t` for f23..f20, and `font, py, mode, date, px, today, tile, rgb,
  week, phase, frame, i, table, handle` for fp..s0. The two loops have
  separate counters (`tile` in s3, `i` in s1): 112 -> 56.
- `if (now >= appear[i]) { ... } else { step = 0; }` gives retail's block
  order.
- `t = 64.0f * rot; py = 113.0f + t;` keeps mul + add (no madd).
- The trailing colour test is the loop's three-way weekday test copied
  without its mode (`week == 6` arm identical). Retail keeps both
  assignments in `$s0`. A two-arm if/else of identical assignments is merged
  and constant-folded: 56 -> 30.
- The render-state table base is cached the way k_fldLmap.c's matched
  00188030 does it (`tbl = (void (**)(s32, s32))(u32)D_00887300;`): 30 -> 22.

Residual (22 edits, all stack slots):

- Retail has two 16-byte copies of the `{0, 0, 640, 480}` rect
  (D_0063BFA0): one at 0xC0 that is never read, and one at 0xF0 that is
  passed to func_0045d6e0. b210 drops the unread copy in every shape tried:
  two initialised locals, local + function-scope copy, an inline helper
  taking the rect by value, by pointer with a local copy, a struct-returning
  inline, `mode(TI)` scalars, and `(void)&copy`. Without it the frame is 0x100
  instead of 0x110, and month/day/color sit 0x10 lower.
- `opt_propagation off` over the function is far worse (215).
