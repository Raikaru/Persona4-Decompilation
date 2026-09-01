# Open question: `daddiu $rX, $zero, K` that MWCCPS2 b210 will not emit

**Ask:** MWCCPS2 3.0.1b210, PS2 EE. Retail has `daddiu $v0,$zero,1`
(`64020001`) where our C compiles to `addiu`/`li` (`24020001`) — on
`func_001e7ab0` that one word is the entire diff in a 368-byte function.
Tried `1`, `1LL`, `(long long)1`, `s64` return types, 64-bit locals, 64-bit
stores: all emit `addiu`. The only thing that produces `daddiu` is a 64-bit
add with a *register* operand (`long long x; x + 1`), and holding the constant
in a callee-saved register across a call just gives `li` plus a trailing
`dsll32/dsra32` sign-extend. Not the ee-gcc part of the binary (these save
`$s` regs with `sq`, not `sd`), and `-help all` shows no ABI/width flag.
**What makes b210 emit `daddiu` for a small constant?**

## Instances

| function | file | whole-function residual | offset |
|---|---|---|---|
| `func_001e7ab0` | `src/promoted/code1_001e.c` | 1 word | `+0xEC` |
| `func_00232c70` | `src/Main/Battle/Data/datCalc.c` | 2 words | `+0xD0`, `+0xE8` |
| `func_00209870` | `src/promoted/code1_0020.c` | 6 words | `+0x124` |
| `func_0034ac00` | `src/promoted/code1_0034.c` | 5 words | `+248` |

## Ruled out

- **Assembler pseudo expansion.** MWCC emits objects directly, no text
  assembler for C, and the operand is `$zero` not `$gp`.
- **ee-gcc translation unit.** ee-gcc saves callee-saved regs with `sd`, MWCC
  with `sq`; all four use `sq`.
- **Source spelling.** Also ruled out per-function: `1u`, `1L`, `(s32)1LL`,
  explicit `s64`/`u64` casts, `sizeof(char)`, pointer differences, `!0`,
  computed comparisons, 64-bit helper returns, separate 64-bit locals, narrow
  temporaries, `u8`/`s8`/`u16`/`s16` destinations, whole-variable `s64`
  widening (372B/nd137, much worse).
- **Compiler flag.** `-help all` is 412 lines with no ABI, `-mips`,
  instruction-set or long-size option.

## Untested

A different MWCCPS2 build. We have b210; b151/b198/b205 are known to exist.
If one of those materialises small constants as `daddiu`, that explains it.
