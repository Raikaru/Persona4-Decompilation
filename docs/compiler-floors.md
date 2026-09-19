# Measured compiler floors

Shapes retail contains that MWCCPS2 3.0.1b210 provably will not emit, with the
evidence that established each one. A function whose retail body needs one of
these is unreachable in C and should stay on `INCLUDE_ASM`; probing it wastes a
lane. Add to this file only what has been measured, never what merely resisted
a few attempts.

## Conditional moves (`movz` / `movn`)

**Superseded 2026-09-03.** The functions that need `movz`/`movn` are the
RenderWare block, which retail built with MWCCPS2 3.0.1 **build 119**; that
build (and b74, b151) emits a conditional move from a plain ternary, byte-exact.
The block is now compiled with b119 per `config/compiler_units.txt`. The
measurements below remain true for build 210 and for Atlus's own code.

**No MWCCPS2 build 210 emits a conditional move.** Established four independent
ways:

1. b210 locally against six source shapes - `c ? v : 0`, `s = v; if (!c) s = 0;`,
   `s = 0; if (c) s = v;`, `c != 0 ? v : 0`, the three-operand `c ? v : w`, and a
   sixth written in retail's exact order with the value live across the call.
2. Every optimisation level `-O0` through `-O4`, plus `-opt all`, `-opt speed`,
   `-opt level=4`, `-opt conditional_move` and `-opt late_conditional_move`.
3. Both pragmas the compiler's own string table names, `conditional_move` and
   `late_conditional_move`, on and off. They are accepted without diagnostic
   and change nothing.
4. All seventeen other `mwcps2` builds on decomp.me, from `2.3-991202` through
   `3.0.1b205-051227`, compiled against `func_003cb790`'s real source. None
   emitted `movz`; every one produced the same branch-and-move shape b210 does.

The mnemonics appear in the compiler's string table because its assembler
accepts them. The instruction selector never chooses them.

The signature in a candidate: retail has `movz $rd, $zero, $rc` where the
candidate emits `beqz`/`bnez` plus a move, and the object comes out two words
long.

31 of the open first-party functions are affected. Regenerate the list with:

    python tools/residual_census.py

**Apparent counter-example.** 36 matched functions in the tree do contain
`movz`/`movn`, all in `src/cri/cri_adx_grouped.c`. Each is an `asm` function
body of raw `.word` literals - transcription rather than decompilation. Do not
copy that approach into first-party code: an `INCLUDE_ASM` row is already
byte-exact in the linked image and is honest about what it is.

## Not floors, despite appearances

Recorded here because each has been mistaken for a floor and each turned out to
be source-drivable. Check these before concluding anything is unreachable.

- **Commutative operand order** (`addu $v0,$v1,$v0` versus retail
  `addu $v0,$v0,$v1`). Driven by which operand becomes live first, not by the
  order written, so changing the source order alone never moves it.
  (An earlier revision of this line pointed at
  `skill://mwccps2-operand-order-inline-helper`, which does not exist.)

  `func_00242990` is the cautionary example.  It sat at 813 instructions,
  exact count, one differing word - `addu $v0, $v0, $v1` against retail's
  `addu $v0, $v1, $v0` at 0x00242CEC - and was written up here as a floor
  after ten spellings all tied at one: operand order swapped, the constant
  written first, the offset hoisted into a `u32` temp, both sides cast to
  `u32`, the array-subscript form, and the parenthesisations either way.

  It was not a floor.  The file already defines

      static inline u32 PTDatCalcOffsetAdd(u32 offset, u32 base)
      { return offset + base; }

  and three of the four sites with this address shape already went through it.
  Routing the fourth through it as well

      value = *(u8 *)((u8 *)PTDatCalcOffsetAdd(*(u16 *)(arg0 + 2) * 0x3C,
                                               (u32)iGpffffb3c4) + 0x38);

  takes the function to **zero** and it is now MATCHED.  The parameter
  boundary is what does it: passing the offset as the first argument fixes
  which operand becomes live first, and no amount of rewriting the expression
  in place can express that.  Every spelling that had been tried was still one
  expression.

  So the lesson is the opposite of what was recorded: when a lone commutative
  operand order survives every rewrite, look for a call boundary - an existing
  inline helper in the same file, or the one the siblings already use - before
  calling it a floor.

- **`addiu` where retail has `daddiu`** on a variable's initialiser. Usually the
  declared type is 64-bit. Note the converse is not reliable: in
  `func_001932f0` retail initialises with `daddiu` and increments the same
  variable with 32-bit `addiu`, and no declaration or literal-suffix change
  reproduced it - that one word remains open. Second citation: in
  `func_0015d310` (banked counted-for, 14wd exact 261/261) the six-site
  `$v0`/`$v1` + `addiu`-against-`daddiu` remnant at fnalign [147:181] in the
  `(s8)func_00110960` `&1`/`-2` adjust measures 14wd with the holder as
  `s64`/`s64`, ties at 14wd as `s32`/`s32` and as `s32`-return, and explodes
  to 112wd mixed (`mixA`/`mixB`) - declaration does not close it either.
- **A missing `nop` before the final `jr`**, with every following branch
  displacement off by one and the object one word short. Seen on
  `func_003c4bc0` and `func_003b6da0` in different files. Two lanes recorded
  this as an unexplained floor; it is not one. It is delay-slot scheduling,
  and the lever is `#pragma schedule` ON - the opposite of the `schedule off`
  both lanes tried, which is why their probes kept getting worse. Retail fills
  the `blez` delay slot with the following `addiu`; the candidate emits a
  `nop`. Measured on decomp.me scratch voNWo, max_score 1500:

      mwcc b210 -O2 bare                  680   54.7%
      mwcc b210 -O2 #pragma schedule on    70   95.3%
      ee-gcc 3.2 -O2                      285   81.0%
      ee-gcc 3.2 -O3                      270   82.0%

  The ee-gcc figures are kept because beating bare MWCC prompted a reasonable
  suggestion that these were GCC-built. They are not; see the census below.

## Where the GCC-built code is, and is not

Both functions above sit at 16-byte-aligned addresses outside every
`VENDOR_CODE_RANGES` span, and MWCC beats every ee-gcc build on them once the
scheduler pragma is set. A tree-wide alignment census confirms the boundary is
sound - GCC aligns functions to 8 bytes, MWCC to 16:

    inside the known vendor ranges:  2350/4873 = 48.22% at 8 mod 16
    first-party overall:                2/7867 =  0.03% at 8 mod 16

A 1600-fold separation, so there is no second GCC pocket hiding in first-party
code. The two first-party outliers, `func_00100008` and `func_00100218`, sit at
the very start of the text segment and one already matches under MWCC.

Note that the prologue test which originally found the vendor band cannot
classify a leaf function: both functions above save nothing, so they have no
`sd`/`sq` to read. Use alignment for those, not the prologue.
