# `daddiu $rX, $zero, K`: constants in narrow unsigned destinations

Measured with MWCCPS2 3.0.1b210: if a constant fits a signed 16-bit
immediate and is assigned to an **unsigned destination narrower than 32
bits**, the compiler loads it with `daddiu $rX, $zero, K`. That destination
can be a `u8` or `u16` variable, or any unsigned bitfield.

```c
u16 f(u16 k) { u16 n = k; if (k > 3) { n = 1; } return n; }
/*  10:  64020001   daddiu  v0,zero,1  */
```

| destination | constant | result |
|---|---|---|
| `u8` | 1 | **`daddiu v0,zero,1`** |
| `u16` | 1 | **`daddiu v0,zero,1`** |
| `u16` | 0x1234 | **`daddiu v0,zero,4660`** |
| `u16` | 0xffff | `ori` (does not fit a signed 16-bit immediate) |
| `u32` | 1 | `addiu`/`li` |
| `s8` | 1 | `addiu`/`li` |
| `s16` | 1 | `addiu`/`li` |
| `u64` bitfield `NLOOP:15` | 5 | **`daddiu a1,zero,5`** |
| `u32` bitfield `a:15` | 255 | **`daddiu a1,zero,255`** |

In these probes, the combination of narrow width and unsigned type selected
`daddiu`. A bitfield was one way to express that destination. The value
did not have to survive a call: the leaf example above emits it too.

For the positive constants shown, both `addiu` and `daddiu` produce the
same register value. The opcode is a compiler clue, not proof of a source
type. Confirm width and signedness through the surrounding operations.

## Recognising a `u16` local

In retail, `func_001e7ab0` differed from the candidate by one word at
`+0xEC`:

```
001e7b74: andi    v0, s1, 0xffff
001e7b88: andi    s1, v0, 0xffff
001e7b9c: daddiu  s1, zero, 0x1
```

A `u16` loop counter reset to 1 inside a branch reproduces the sequence:

```c
u16 d_loop(u16 k) { u16 n = k; int i;
    for (i = 0; i < 3; i++) { if (cond()) { n = 1; } else { n = n + 1; } }
    return n; }
/*  10:  andi    s1,a0,0xffff
    30:  daddiu  s1,zero,1
    3c:  andi    v0,s1,0xffff
    44:  andi    s1,v0,0xffff   */
```

The repeated `0xffff` masks support a `u16` interpretation of this local.
Test that declaration against the whole function rather than widening the
variable merely to obtain a 64-bit instruction.

## Spellings that do not produce it

An earlier sweep varied arithmetic spellings without changing destination
width and signedness together. It wrongly treated those failed probes as a
general limit. The recorded cases below did not produce the desired
`$zero`-source `daddiu`:

- `*p |= 255` through a `u64` pointer, and a `u64` local built from
  constants, give `ori`.
- Constants passed to a callee with `u64` parameters produce neither.
- `1`, `1LL`, `(long long)1`, `s64` return types, 64-bit locals, 64-bit
  stores, `ULL` literals and widening a whole variable to `s64` do not
  produce it.
- All 255 pragma names extracted from the compiler binary were compiled `on`
  and `off`. None of the 482 successful compiles emitted `daddiu` for a
  constant.
- It is not an assembler pseudo-instruction expansion, an ee-gcc unit, or an
  ABI/width flag.

A 64-bit add with a live register operand also emits `daddiu`
(`long long x; return x + 1;` gives `64820001 daddiu $2,$4,1`). That shape
has a register source, unlike the `$zero`-source constants above.

## Functions matched with this rule

All of these had been archived as unreachable floors. Each is now matched C
in the listed file (`tools/verify.py`: `MATCH`, `normalized_diff` 0, checked
2026-09-23):

| function | file | residual before | offset |
|---|---|---|---|
| `func_001e7ab0` | `src/promoted/code1_001e.c` | 1 word | `+0xEC` |
| `func_00232c70` | `src/Main/Battle/Data/datCalc.c` | 2 words | `+0xD0`, `+0xE8` |
| `func_00209870` | `src/promoted/code1_0020.c` | 6 words | `+0x124` |
| `func_0034ac00` | `src/promoted/code1_0034.c` | 5 words | `+248` |
| `func_0038b1c0` | `src/promoted/code1_0038.c` | 6 words | `0x144`–`0x1bc` |

In `func_0038b1c0`, the six loads are `daddiu a2,zero,0xff`,
`a3,zero,0xbe`, `t0,zero,0x5a`, `a2,zero,0x2b`, `a3,zero,0x26` and
`t0,zero,0x1e`. They are three-channel colour values in consecutive argument
registers, so the arguments are `u8` colour components.

The useful probe was the bitfield assignment `sp->giftag.NLOOP = 5`.
It tested a destination type the earlier arithmetic sweep had missed.
