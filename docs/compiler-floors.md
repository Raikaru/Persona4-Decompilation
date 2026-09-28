# Measured compiler floors

A compiler floor is a documented code-generation limit for a particular
compiler build and configuration. Keep an unmatched function on its
`INCLUDE_ASM` fallback. Revisit the recorded limit when you have a new
source hypothesis, compiler configuration or ABI fact; unsuccessful probes
alone do not prove that no C source can match.

The second half lists shapes once mistaken for compiler limits.

## Conditional moves (`movz` / `movn`) under build 210

The recorded build-210 probes did not emit conditional moves. They covered:

1. b210 was run locally on six source shapes: `c ? v : 0`,
   `s = v; if (!c) s = 0;`, `s = 0; if (c) s = v;`, `c != 0 ? v : 0`, the
   three-operand `c ? v : w`, and a sixth written in retail's exact order
   with the value live across the call.
2. Every optimisation level from `-O0` to `-O4` was tried, plus `-opt all`,
   `-opt speed`, `-opt level=4`, `-opt conditional_move` and
   `-opt late_conditional_move`.
3. Both pragmas named in the compiler's string table,
   `conditional_move` and `late_conditional_move`, were set on and off. The
   compiler accepts them without a diagnostic, and they change nothing.
4. All seventeen other `mwcps2` builds on decomp.me, `2.3-991202` through
   `3.0.1b205-051227`, compiled `func_003cb790`'s real source. None emitted
   `movz`. Every one produced the same branch-and-move sequence b210 does.

The mnemonics also occur in the compiler's string table because its assembler
accepts them. Their presence alone does not show that C code generation uses
them.

In a candidate diff, this floor appears as a `beqz`/`bnez` plus a move where
retail has `movz $rd, $zero, $rc`, making the object two words longer.

**Scope (measured 2026-09-03).** The retail functions that need these moves
are in the RenderWare-derived block, which retail built with MWCCPS2 3.0.1
**build 119**. Builds 74, 119 and 151 emit `movz` from a plain ternary,
byte-exact. Those units now compile with b119 through
`config/compiler_units.txt`, and that file's header records the measurement.
Those b119 results do not establish a build-210 solution.

**Apparent counter-example.** Some linked CRI and runtime functions contain
`movz`/`movn` as raw `.word` literals in `asm` bodies. They came from the
former `src/cri/cri_adx_grouped.c` and now live in the split owners under
`src/cri/`, plus `src/middleware/soft_float.c` and `src/sce/rofs_dir.c`.
Those bodies are transcribed, not decompiled. Do not copy the approach into
first-party code. An `INCLUDE_ASM` row is already byte-exact in the linked
image and does not claim to be C.

## Not floors, despite appearances

### Commutative operand order

Example: the candidate has `addu $v0,$v1,$v0` and retail has
`addu $v0,$v0,$v1`. In the case below, operand lifetimes determined the
order; swapping operands within the same expression did not change it.

`func_00242990` (`src/Main/Battle/Data/datCalc.c`) had 813 instructions
with the correct count and one differing word at `0x00242CEC`. It was
recorded as a floor after ten spellings all left that one word: swapped
operands, the constant written first, the offset hoisted into a `u32` temp,
both sides cast to `u32`, an array subscript, and both parenthesisations.
All ten were still one expression.

The same file already defines

```c
static inline u32 PTDatCalcOffsetAdd(u32 offset, u32 base)
{ return offset + base; }
```

and three of the four sites with this address shape used it. Routing the
fourth site through it matches the function:

```c
value = *(u8 *)((u8 *)PTDatCalcOffsetAdd(*(u16 *)(arg0 + 2) * 0x3C,
                                         (u32)iGpffffb3c4) + 0x38);
```

The call boundary fixes which operand becomes live first. When a single
commutative operand order survives every rewrite, look for an inline helper
in the same file, or the one sibling sites already use.

### `addiu` where retail has `daddiu`

When a constant is loaded from `$zero`, `daddiu` means the destination is a
narrow unsigned type: `u8`, `u16` or an unsigned bitfield. See
[open_question_daddiu.md](open_question_daddiu.md) for the rule and its
truth table. For a variable's initialiser, `addiu` versus `daddiu` often
follows the declared width.

The two examples recorded here as unexplained width residuals are now
matched, both by source changes rather than declaration changes:

- `func_001932f0`: retail initialises a variable with `daddiu` and increments
  it with 32-bit `addiu`. Declaration and literal-suffix changes did not
  reproduce this. The function later reached `MATCH` at 352/352 bytes.
- `func_0015d310`: six sites of `$v0`/`$v1` and `addiu`/`daddiu` churn sat
  at 14 words whether the holders were `s64` or `s32`. Mixing the two made
  it worse (112 words). The cause was a hand-expanded signed modulo: the
  body spelled `x % 2` as `x & 1` plus a negative correction and `-= 2`.
  Writing `(s32)var_2 % 2` with `s32` temporaries lets the compiler emit its
  own sequence and matches the function.

### Missing `nop` before the final `jr`

Symptom: the candidate is one word short, and every later branch
displacement is off by one. It was seen on `func_003c4bc0` and
`func_003b6da0`, in different files. Two lanes recorded it as an unexplained
floor. It is delay-slot scheduling. Retail fills the `blez` delay slot with
the following `addiu`, and the candidate emits a `nop`. The fix is
`#pragma schedule on`; both lanes had tried `schedule off`, so their probes
got worse. On decomp.me scratch voNWo (max_score 1500):

```
mwcc b210 -O2 bare                  680   54.7%
mwcc b210 -O2 #pragma schedule on    70   95.3%
ee-gcc 3.2 -O2                      285   81.0%
ee-gcc 3.2 -O3                      270   82.0%
```

The ee-gcc rows are kept because they beat bare MWCC, which suggested these
functions were built with GCC. They were not; see the next section.

## Where GCC-built code is

In the recorded census, both functions above were at 16-byte-aligned
addresses outside the configured vendor spans. With the scheduler pragma,
MWCC scored better than the tested ee-gcc builds. The census also compared
8-byte GCC alignment with 16-byte MWCC alignment:

```
inside the known vendor ranges:  2350/4873 = 48.22% at 8 mod 16
first-party overall:                2/7867 =  0.03% at 8 mod 16
```

The rates differ by a factor of about 1600, supporting the existing compiler
partition. They do not rule out every small or deliberately aligned GCC
unit. The two first-party outliers in that census, `func_00100008` and
`func_00100218`, sit at the start of the text segment.

The prologue test cannot classify leaf functions that save no registers.
Use alignment as supporting evidence for those functions, not as a compiler
identifier on its own.
