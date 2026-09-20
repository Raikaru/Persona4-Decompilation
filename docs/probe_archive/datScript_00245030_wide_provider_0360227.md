# Exact datScript caller proposal for the wide skill provider

Validated on 2026-09-20 in `work/first-party-0360227`, based on upstream
`0360227d0a4194cb84500a5cf63ac554b38a79c2`. The owner is
`src/datScript/datScript.c`. This exact proposal is archived: the live owner
was restored byte-for-byte because three other callers still block the
coordinated provider change.

The proposal declares `func_0023d8e0` with `s32` for its command argument.
The declaration and the expression used in both case arms are:

```c
s32 func_0023d8e0(u8* unit, s32 cmd);
(s16)func_0023d8e0((u8 *)(uintptr_t)D_00881460[0], D_0088146C[0])
```

Changing only that declaration moved the command halfword load ahead of the
unit pointer load in cases 11 and 12 of `func_00245030`. This left four
differing instruction words at offsets `0x4e8`, `0x4f0`, `0x5c0`, and `0x5c8`.

Passing the unit as `(u8 *)(uintptr_t)D_00881460[0]` restores both retail load
pairs. The project's `uintptr_t` is `u32`, so this is a pointer round-trip on
the 32-bit EE target. The command remains a load from the existing `u16`
storage, with normal promotion to the provider's actual `s32` parameter.
The resulting order is `lw a0` from `D_00881460`, then `lhu a1` from
`D_0088146C`, then the call. The two load pairs occupy the offsets listed
above.
The generated owner object is identical to the original narrow-declaration
object, including every function, relocation, and allocated data section.

The bounded probes retained in `build/first-party-0360227/datScript-closure/`
compare complete owner objects. Reversed narrow wrapper parameters, a wrapper
that takes only the unit, and a wrapper receiving both storage addresses each
retain the same four differences. The explicit pointer conversion eliminates
all four. The source change uses the `uintptr_t` spelling and retains the
provider's wide declaration.

The proposal was temporarily applied to its actual owner for verification.
The official current-owner verifier reported four `MATCH` rows. Independently
resolved retail comparisons established:

| Function | Emitted / retail bytes | Zero tail bytes | Code relocations |
| --- | ---: | ---: | ---: |
| `func_00244f60` | 196 / 208 | 12 | 24 |
| `func_00245030` | 5152 / 5152 | 0 | 334 |
| `func_00246480` | 84 / 96 | 12 | 7 |
| `func_002464e0` | 104 / 112 | 8 | 8 |

The target's complete 140-byte `.rodata` jump table also matches after all 35
table relocations are resolved. Every omitted tail above is verified zero.
All four functions retain their baseline bytes and canonical relocations;
allocated data and function ownership are unchanged. `decomp_lint.py` reports
zero findings, and `git diff --check` passes for the owner.

The retained `current/proof.json` contains all relocation records and the
sibling/data comparisons. `current/` also retains the complete source,
`owner.o`, compiler receipt/log, and resolved bytes for each function.
`official-current.json`, `official-current.log`, and `lint.json` retain the
official checks. `validate.py` ran while the proposal was live; reapplying
the retained source permits the same current-owner checks to be repeated.

Archived proposal source SHA-256:
`ba0d7fd619250c47e52edf32842cebbfc1c543515d4b6986e231b66a67aed6b3`.
Both original and proposal owner objects have SHA-256:
`8a5d2c3798b94115c22729f4d629a780793f67f129a491503ccbe48b5b99837d`.

The restored live owner has SHA-256
`a45593ae984e2b937227c1599902fe2d36dbaeb0dee46071ac07efbe01413cbe`.
The provider definition and the other callers belong to the coordinated
provider change; their remaining differences must be closed before this
proposal is integrated.
