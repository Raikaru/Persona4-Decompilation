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
  order written. See `skill://mwccps2-operand-order-inline-helper`.
- **`addiu` where retail has `daddiu`** on a variable's initialiser. Usually the
  declared type is 64-bit. Note the converse is not reliable: in
  `func_001932f0` retail initialises with `daddiu` and increments the same
  variable with 32-bit `addiu`, and no declaration or literal-suffix change
  reproduced it - that one word remains open.
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
