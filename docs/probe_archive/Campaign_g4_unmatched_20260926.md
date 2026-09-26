# Campaign group 4, round 2: probed but not matched, 2026-09-26

Measurements are `tools/fndiff.py` masked words (positional) or `tools/fnalign.py`
edits, taken with the body in place of `INCLUDE_ASM`. Production for all of
these stays ASM. Matched this round: `func_00385380`
(`Code0038Burst_00385380_20260926.md`).

## Round-1 banked drafts

| function | round 1 | round 2 | banked body |
|---|---|---|---|
| `func_001dbf20` | 21 edits | 7 words | `BtlAICommand_001dbf20_20260926_body.c` |
| `func_0048a980` | 5 (helper draft) / 16 (natural) | 5, natural body | `Quat_0048a980_20260926_body.c` |
| `func_00485630` | 3 | 3, `for` loop | `KoD_00485630_20260926_body.c` |
| `func_00485870` | 3 | not re-probed (same wall) | `PoB_00485870_propoff_body.c` |
| `func_0034ae70` | 12 edits | 12 edits | `FclBall_0034ae70_20260925_body.c` |

The walls are recorded in each body's header and in
`SceneNodeUpdate_00485630_00485870_20260926.md`.

### func_0034ae70 (y_fclCmbBall.c): the depth-load wall

Retail keeps `lwc1 $f1, %lo(D_008872F8)($a0)` in the vertex loop and hoists only
`lui $a0, %hi(D_008872F8)` above it; `i` is in `$v1`. Measured with the
round-1 file-scope changes (`FCL_COLOR_ARG u8`, s32 `func_00457120` /
`func_003315e0`):

- direct `D_008872F8[0]` in the loop, propagation off: 69 words (the lui stays
  in the loop);
- the same with `#pragma opt_loop_invariants on`: 67 words. LI hoists the whole
  `lwc1`, although the loop stores through arg1-derived `f32 *`s. So b210's LI
  treats the global as unaliased;
- `extern f32 D_008872F8;` (a scalar, not an array): 182 words, 1280 B;
- the round-1 `depth = (u32)D_008872F8` integer view is still the best at 12
  edits. It hoists `lui` + `addiu` together, so `i` moves to `$a0`.

## Other targets surveyed (guarded `#ifdef NON_MATCHING` drafts as they stand)

Positional words: `0018e810` 89 (35 edits), `001dd920` 39 (39 edits),
`00484bb0` 187 (197 edits), `0029fbb0` 404 (139 edits), `00296850` 455 (457
edits), `0048b340` 383. All other list entries are 300-2600 positional words.

### func_001dd920 (btlAICommand.c): 39 edits, all saved-register colouring

The instruction stream is identical. Retail puts `result` in `$s0` and `count`
in `$s1` (then reuses `$s1` for the inlined `btlCommandUsable` unit pointer, and
`$s0` for the case-0/1 loop index). The draft has the whole pairing mirrored.
Inert: all 24 declaration orders of count/result/n/unit, `s32 result` with
`switch ((s16)result)`, sharing one function-scope `entry` or `limit` across the
three case loops. Worse: `u32`/`s32 count` (330), `s32 n` (263), sharing one
`i` across the cases (46). permute.py 190 s: no improvement.

### func_0018e810 (code1_0018.c): 35 edits

Four independent residuals:

1. case 4 keeps `D_008C024E[0]` in `$a0` for the 0x40 test. Retail reloads it
   after the cursor stores, and a `u16 pad` local for the first two tests does
   not change that;
2. the `func_00450340` arguments. The gp "globals" are pooled constants:
   `iGpffff9fdc` is the string `"%d"` and `iGpffff9fd0` is the float pair
   {300.0f, 32.0f}. `iGpffff9fd8` is the colour word 0x800000FF that is copied
   to `spCC`. Retail loads `ld $a0` first. A local
   `union { f32 xy[2]; s64 packed; } pos = {{300.0f, 32.0f}}` gets that order,
   but it spills the union to the stack (127 words);
3. the panel loop's `y << 8`. Retail computes it once per row, next to `ty` and
   `panels`, and adds it first (`addu $v0, $s1, $v0`). A named `row` local gets
   that order, but b210 then folds the 0x54/0x55/0x58/0x59 displacements into
   `row` (367 words, frame 0xC0). A `FieldMap { u8 pad[0x54];
   FieldMapCell cells[24][16]; }` view keeps the displacements, but the order
   is still base-first, and the `off` copy is lost (40 edits);
4. the `spCC` / `func_0014def0` argument scheduling (`addiu $a2`,
   `move $a3/$t0`).

## Round 3 (same day)

Matched: `func_001823d0` (`FldAreaSe_001823d0_20260926.md`) and
`func_0018f950` (`FieldPanelEdit_0018f950_20260926.md`). Both were
rewritten from the retail listing rather than from the guarded drafts.

Two levers that transfer to other functions:

- **An unsized `extern T X[]` is treated as unaliased by pointer stores.**
  b210 CSEs or hoists its loads across stores. A struct member, or a
  sized array too large for .sdata, is reloaded after each store, which
  is the retail pattern whenever a global is re-read after stores
  through a work pointer. The pad words are `PadStatus` records at
  0x8C0240. D_008872F8 is the `nearZ` field of the render-state record
  at D_008872E0.
- **Pooled gp constants copied into stack slots are initialised statics
  or aggregates.** Examples: the `ld`/`lwc1` from a pool entry followed
  by a store to the frame, and an s64 float pair passed in $a0. They are
  copied just before use. Declaration order sets which local gets the
  higher slot: the earlier-declared local gets the higher address.

| function | round 2 | round 3 | banked body / blocker |
|---|---|---|---|
| `func_0018e810` | 35 edits | 25 edits (452/452) | `L18B_0018e810_20260926_body.c`; y-loop preamble order and which CSE gets the $s7 copy |
| `func_0034ae70` | 12 edits | 3 words | `FclBall_0034ae70_20260926_body.c`; nearZ loaded after the 0xE14 float |
| `func_00485630` | 3 | 3 | restore colour, see below |
| `func_0048a980` | 5 | 5 | 1.0f in $f3 vs $f1 |
| `func_001dbf20` | 7 | 7 | last/k colour swap |
| `func_001dd920` | 39 | 39 | result/count colour swap |
| `func_0029fbb0` | 131-139 edits | 137 edits | copy-array init, spill and rotation wall |

- **func_00485630.** The restore takes `$v1` in every shape. The save can
  be removed, the address can come from a second pointer or an inline
  helper, the slot can be a u8 pointer or a struct, or the callee's
  return can feed the restore, and the restore still takes `$v1`. So the
  colour does not depend on the save.
- **func_0048a980.** The sqrt argument is inert in every spelling:
  `d = sqrtf(..)`, `s = s * 2.0f`, a `trace` reuse, or the 1.0f split out.
- **func_001dbf20.** The following are inert:
  - block-scoping k, last, or both, including inside the else branch;
  - `last` merged with `sum`;
  - k merged with n or idx in the (u16)-masked s32 form;
  - `k < num - 1` (22) and `k + 1 < num` (33) are worse.
- **func_001dd920.** 40 random orders of all eleven locals score 39. An
  inline classifier helper scores 371.
- **func_0029fbb0.** An initialised `s32 copy[36]` after the `base`
  initialiser reproduces the copy loop. A natural 2-D rewrite scores 218
  edits. Retail mixes folded and unfolded table-row loads, which suggests
  an unfolded row-pointer temp.
