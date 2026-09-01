# ANSWERED: `daddiu $rX, $zero, K` is a constant into a NARROW UNSIGNED destination

**The rule, measured directly against our own MWCCPS2 3.0.1b210:**

> Assigning a constant that fits a signed 16-bit immediate to an **unsigned
> destination narrower than 32 bits** — a `u8`/`u16` variable, or any unsigned
> bitfield — materialises that constant with `daddiu $rX, $zero, K`.

```c
u16 f(u16 k) { u16 n = k; if (k > 3) { n = 1; } return n; }
/*  10:  64020001   daddiu  v0,zero,1  */
```

## The full truth table

| destination | constant | result |
|---|---|---|
| `u8` | 1 | **`daddiu v0,zero,1`** |
| `u16` | 1 | **`daddiu v0,zero,1`** |
| `u16` | 0x1234 | **`daddiu v0,zero,4660`** |
| `u16` | 0xffff | `ori` — does not fit a signed 16-bit immediate |
| `u32` | 1 | `addiu`/`li` |
| `s8` | 1 | `addiu`/`li` |
| `s16` | 1 | `addiu`/`li` |
| `u64` bitfield `NLOOP:15` | 5 | **`daddiu a1,zero,5`** |
| `u32` bitfield `a:15` | 255 | **`daddiu a1,zero,255`** |

So **unsignedness and narrowness are both required**, signed narrow types do
not do it, and bitfields are simply the special case of a narrow unsigned
destination. Liveness across a call is NOT required — an earlier hypothesis
that the value had to survive a call in a saved register is wrong; a leaf
function with no calls at all still emits it.

The mechanism is consistent with the EE ABI: an unsigned narrow value must be
zero-extended in its 64-bit register, and `daddiu` from `$zero` produces a
clean 64-bit value with no sign-extension, where `addiu` would sign-extend.

## Exact retail reproduction

`func_001e7ab0` is the campaign's closest near-miss — one word in 368 bytes,
at `+0xEC`. Retail:

```
001e7b74: andi    v0, s1, 0xffff
001e7b88: andi    s1, v0, 0xffff
001e7b9c: daddiu  s1, zero, 0x1
```

A `u16` loop counter reset to 1 inside a branch reproduces that sequence
instruction for instruction:

```c
u16 d_loop(u16 k) { u16 n = k; int i;
    for (i = 0; i < 3; i++) { if (cond()) { n = 1; } else { n = n + 1; } }
    return n; }
/*  10:  andi    s1,a0,0xffff
    30:  daddiu  s1,zero,1
    3c:  andi    v0,s1,0xffff
    44:  andi    s1,v0,0xffff   */
```

The repeated `andi $rX,$rY,0xffff` after every arithmetic op is the signature
of a `u16` local. **If you see that masking pattern around a `daddiu`, the
variable is `u16`, not `u32` or `s32`.**

## Still correct: everything the earlier sweep ruled out

The previous investigation was not wrong, it was searching the wrong space —
it explored *arithmetic* spellings exhaustively and never varied the
destination's signedness and width together. All re-confirmed to give
`addiu`/`li`/`ori`, never `daddiu`:

- `*p |= 255` on a `u64` pointer → `ori`; a `u64` local built from constants → `ori`.
- Constants passed to a callee with `u64` parameters → neither.
- `1`, `1LL`, `(long long)1`, `s64` return types, 64-bit locals, 64-bit stores,
  `ULL` literals, whole-variable `s64` widening.
- All 255 pragma names extracted from the compiler binary, each compiled `on`
  and `off`: 482 successful compiles, 0 produced `daddiu` for a constant.
- Not an assembler pseudo-expansion, not an ee-gcc unit, no ABI/width flag.

A 64-bit add with a live **register** operand also emits `daddiu`
(`long long x; return x + 1;` → `64820001 daddiu $2,$4,1`), but that is a
different shape from the `$zero`-source constants in the retail family.

## Instances to re-open

Every one was archived as an unreachable floor. Check the destination type of
whatever receives the constant and try `u8`/`u16`:

| function | file | residual | offset |
|---|---|---|---|
| `func_001e7ab0` | `src/promoted/code1_001e.c` | **1 word** | `+0xEC` |
| `func_00232c70` | `src/Main/Battle/Data/datCalc.c` | 2 words | `+0xD0`, `+0xE8` |
| `func_00209870` | `src/promoted/code1_0020.c` | 6 words | `+0x124` |
| `func_0034ac00` | `src/promoted/code1_0034.c` | 5 words | `+248` |
| `func_0038b1c0` | `src/promoted/code1_0038.c` | 6 words | `0x144`–`0x1bc` |

`func_0038b1c0`'s six decode as `daddiu a2,zero,0xff`, `a3,zero,0xbe`,
`t0,zero,0x5a`, `a2,zero,0x2b`, `a3,zero,0x26`, `t0,zero,0x1e` — three-channel
colour values in consecutive argument registers, i.e. `u8` colour components,
exactly what this rule predicts.

## Credit

Suggested by the user mid-wave (`sp->giftag.NLOOP = 5`) after the automated
sweep had declared the family closed by exhaustion. The bitfield probe that
suggestion prompted is what exposed the general narrow-unsigned rule.
