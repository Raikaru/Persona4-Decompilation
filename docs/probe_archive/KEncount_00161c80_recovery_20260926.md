# k_encount `func_00161c80`: weighted encounter-record pick (MATCH)

Window 1184 B, object 1184 B. Relocations: `func_0014a230`, `func_0014a2a0`,
`func_00106600`, `func_00161bb0`, `func_0046d730`, `RpRandom`, gp loads of
`iGpffffb41c`/`iGpffffb424`, and HI/LO pairs for `D_005F1260`, `D_005F12C8`,
`D_007E80A0`.

Path: 243 words (KEn80_00161c80_body.c) -> 9 (previous group-0 agent) -> 0.

Levers, all load-bearing:

- Signature `(s32 field, s32 room, u16 index, u16 mode)`. `u16 mode` is
  needed (s32 mode: 237 words); u16 field/room adds entry masks (267). The two
  callers (code1_0015.c, k_fldUnit.c) declared `(u16, u16, u16, s32)` and now
  use the definition's prototype; both files keep all their statuses.
- Typed 10-byte `EncEntry` lookup for the record-block index.
- `#pragma opt_loop_invariants on` (push/pop) hoists the list bases and
  constants ahead of both loops.
- The draw loop's locals sit in their own block, declared
  `id, pid, j, rec, hit, n` with the counter last, and the block starts with
  `n = 0; acc = 0;` in that order. This ranks the counter in `$s0` and the
  id in `$s4` as in retail. With the counter at function scope the two swap
  (9 words); counter last but `acc = 0` before the block: 2 words (init order);
  `for (n = 0, acc = 0; ...)` also matches.

Ruled out on the 9-word body: ~700 declaration permutations of the function
and draw-loop locals, inline helpers for the two scans (19), reusing `i` or
`total` for the draw loop (9-13), a shared function-scope id (22/38),
`*pid` reads (114-119), `s32 id` (118), early `return rec` (257).
