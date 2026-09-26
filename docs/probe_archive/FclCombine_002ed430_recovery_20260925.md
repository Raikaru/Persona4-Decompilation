# func_002ed430 (y_fclCombine): accepted C recovery, 2026-09-25

`src/Event/Fcl/y_fclCombine.c::func_002ed430` is active C and **MATCH**
(object 15048B inside the 15056B retail window, 0 differing words; the tail is
two alignment nops). Owner file: 33 MATCH / 8 ASM of 41. No other function
changed status. This supersedes the not-matched draft in
`FclCombine_002ed430_20260925.md` / `_body.c`. That draft was 3755/3761
instructions and 272 per-case edits.

## Relocations
537 in total. R_MIPS_26 to 75 callees. HI16/LO16 go to the local jump table
(`@747`, retail 0x00749110), D_00795E60, D_008C024C/024E/027A and D_00640C10. GPREL16
goes to iGpffffb440 and iGpffffb3d4.

## What closed it, in order of effect
Casealign totals, then fndiff words once the function was size-exact.
1. **Case 0x2A: `i + 0x270U` in the three colour branches** (274 -> 65
   casealign). Retail computes the 0x270 sprite id once for the alpha lookup
   (`temp_23`, $s7). It computes it *again* at the head of each colour
   branch, and in branch 1 spills that copy (`sq/lq 0xD0`), which is where
   the 0x260 frame comes from. With a signed `i + 0x270`, b210 value-numbers
   the branch copy equal to `temp_23` and reuses it. The unsigned sum emits
   the same `addiu` but is a distinct expression, so it is recomputed and
   spilled. Things that did not work:
   - Named or block-local copies of `i` (coalesced away).
   - Branch bodies as inline helpers (transparent to CSE).
   - `(s16)` or `(s32)` casts, and an `s64` temp (CSE'd, then sign-extended).
   - `+ 0x26F + 1` (folded before CSE).
   - `#pragma opt_common_subs off` (1210).
   `temp_30 - 0xD` and `(u16)i + 0x270` proved the mechanism (93 and 92)
   before the unsigned form was found.
2. **The real `func_00275820` signature** from frFontEx.c,
   `(f32 x, f32 y, f32 scale, int color, s8, int, const char *, int, int,
   void *, int)`. With the floats first, `pos.y` is loaded right after
   `$f14`, as in retail (89 -> 26 words, 7 sites).
3. `f11E = f128;` as its own statement, then `func_0031ddf0(arg0, f11E, ...)`.
   This forwards the stored value through `$v0` and adds the missing
   instruction (3761 -> 3762, size-exact).
4. `x > 5` instead of `x >= 6` for the `func_00314660` range test gives
   retail's `slti $at` (4 sites; see matching.md's slti grid).
5. Store, then re-read, for f2FA (`f2FA = f11E; t = f2FA;` and
   `func_002e48a0(f2F9, f2FA)`). The `sb` then comes before the sign-extend.
6. `RpRandom() % 1000U < 0x1F4U` (sltiu).
7. `func_003144d0`'s slot byte is declared `s8` in the local prototype. With
   s32 or u8 the byte load was hoisted ahead of `lw 0x148` (3 sites). The
   callee only stores the byte with `sb`. Its sibling func_00314560 takes the
   same +0xC field as `s8`.
8. The class id is `u16` and every persona-id callee takes `u16`. See
   "Class-id contract" below.

## Class-id contract (resolved 2026-09-26)

Earlier revisions kept a block-scope `func_00310a10(u8 *, u16)` declaration
that conflicted with an `s32` definition, then parked the body. The conflict
came from two wrong definitions, not from the caller. Retail's persona-id API
takes `u16` throughout, and MWCC b210 passes a `u16` value to a `u16`
parameter without a mask. It masks on any u16 <-> 32-bit change. Every
declaration below now agrees with its definition across `src/`.

- `func_00310a10(u8 *, u16 arg1)`. The row lookup is plain
  `iGpffffb3d4[arg1 * 14 + 2]`, which gives retail's `andi $v1,$s2` into a
  temporary. arg1 then reaches `func_00109280` raw. The old `s32` form needed
  an explicit `(arg1 & 0xFFFF)`. A `u16` parameter only renormalised `$s2` in
  place because `func_00109280` was still declared `s32`, which made the
  zero-extension shared.
- `func_00109280(u16)` and `func_00109220(u16)` in g_data. Retail masks the id
  separately for the `< 0x100` check and for the row offset. A plain
  `id * 0xE` CSEs both into one entry `andi $s0,$a0` (20 words), and so did
  `& 0xffff`, `(s32)` casts, `u16`/`s32` copies and a struct-array index.
  `(u32)personaId * 0xE` (and `* 0x11`) is a distinct conversion and matches.
- `func_001092f0` returns `u16`. The body reads `*(u16 *)(arg0 + 2)`, like its
  siblings 109300 and 109360.
- `func_003026c0(u16, s32)`. Its callers pass `lhu` values, and it passes
  arg0 raw to 109280.
- Callers updated so their bytes are unchanged:
  - code1_0036 `func_003672d0`: `u16 personaId = func_00105290(pcId)`.
  - shdPersona `func_0011e8e0` and `func_0011f5a0`: the 1092f0 result goes
    straight into 109220. A `u16` local re-masks a call result.
  - Declarations in itfMesManager, code1_0019 (`(s32)` casts on the pointer
    return), code1_0020, code1_0038, cmmScript, cmmMisc, cmmRankUp,
    y_fclCombineDraw and y_fclCombine.
- `func_00105f50(u16)` and `func_0034a640(.., u16, ..)` are unchanged. The
  all-32-bit alternative stays ruled out. With `func_0034a640(u8 *, s32,
  s64)`, y_fclCombineDraw `func_0032c480` hoists `lhu $a1` above
  `lw $a0,0x254`, a 2-word difference. None of these closed it:
  - a u16, s32 or bitfield (`u32 cls:16`) read;
  - `(s32)`, `(u16)` and `& 0xFFFF` spellings;
  - pointer or index temporaries;
  - `(u8 *)(u32)` and `*(u8 **)` model reads;
  - s32/int/u8 third parameters;
  - an unprototyped declaration.
  Only a `u16` parameter keeps the argument order. u16 -> s32 at a
  prototyped call is scheduled as a computed argument, ahead of the memory
  operands.
- Other hypotheses measured in 002ed430 with an `s32` 310a10: an enum-typed
  temporary is int-sized and masks at both 105f50 calls.
- File-boundary evidence for 310a10: its only rodata, D_00749480, sits after
  the 00302570/00304580/00308f40 tables. It also comes before code1_0031's
  D_007494D0, so it fits y_fclCombine's rodata run in order. No TU split
  is indicated.

All affected units verified unchanged or improved, with no WRONG SYMBOL
lines:
- y_fclCombine 33/8 (002ed430 now MATCH)
- y_fclCombineDraw 61/9
- g_data 137
- code1_0034 28
- code1_0036 31/3
- code1_0038 88/7
- shdPersona 100/2
- cmmMisc 57
- fclCombineMisc 11
- itfMesManager 85
- code1_0020 146
- cmmScript 50/1
- btlShuffleResult 7/3
- datPersona 56
- cmmRankUp 26
- code1_0019 150/1

Lint: 0 errors.

## Superseded: why the func_00310a10 declaration stayed u16
In state 0x2F, retail loads the class id once (`lhu $s0`). It then passes
`$s0` unmasked to `func_00105f50` and to `func_00310a10`. MWCC masks on
every type change between u16 and a 32-bit type, but not on u16 -> u16 or
s32 <-> u32. So:
- The caller cannot use one honest type for both calls. Each probe below
  left 2 words (one `andi`):
  - u16 temp with `func_00310a10(u8 *, s32)`;
  - s32 temp with `func_00105f50(u16)`;
  - u32 temp;
  - `(u16)` casts;
  - an unprototyped `func_00310a10()` declaration.
- Callee definitions (fndiff):
  - `func_00310a10` matches only with a 32-bit parameter. A u16 parameter
    renormalises arg1 in place (5 words). It passes arg1 raw to
    `func_00109280`, whose definition is also 32-bit (u16 gives 20 words with
    three different bodies).
  - `func_00105f50` and `func_0034a640` match as u16, s32 or u32.
- An all-32-bit contract fixes 002ed430:
  - `func_00105f50(s32)`, `func_0034a640(u8 *, s32, s64)`,
    `func_00310a10(s32)`, an s32 temp;
  - `func_003097e0`'s `cls` becomes s32 with `(u16)cls` at the index uses;
  - with those, g_data, code1_0034 and y_fclCombine all keep their status.

  But y_fclCombineDraw `func_0032c480` regresses (MATCH -> 2 words). Its
  `lhu` argument is scheduled in argument order only when `func_0034a640`'s
  parameter is u16. So u16 is the contract that TU's bytes support.
- `func_003097e0` itself needs `cls` to reach both `func_0034a640` and
  `func_00105f50` unmasked. That fixes those two as u16 in this TU, so
  `func_00105f50` cannot be 32-bit here.

No single set of prototypes reproduces all four functions. The narrow local
declaration is the smallest deviation measured.

## Parked (2026-09-25; superseded by the class-id contract above)

The byte-exact body is kept in `src/Event/Fcl/y_fclCombine.c` under
`#ifdef NON_MATCHING`, with `INCLUDE_ASM` as the active build. It depends on a
block-scope `func_00310a10(u8 *, u16)` declaration that conflicts with the `s32`
definition in the same translation unit. Standard C rejects that, so the
original source could not have had it, and docs/STYLE.md forbids it. The
exception above is therefore evidence that part of the model is still wrong,
not a finished recovery. Retail reads the class id once with `lhu` and passes it
unmasked to a `u16` callee and an `int` callee; the likely missing piece is the
type or read form of the field it comes from. Restore the body once a shape
that uses the real prototypes is found.
