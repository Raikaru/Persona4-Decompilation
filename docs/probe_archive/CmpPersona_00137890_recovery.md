# Camp persona row renderer, 00137890

The corrected C candidate remains guarded by `NON_MATCHING`. Under its configured
MWCCPS2 b210 compiler with `-O2 -Iinclude`, it emits 1340 bytes in the 1344-byte
retail window. The remaining four retail bytes are zero. Two unmasked instruction
words differ; no exact C promotion is claimed.

## Recovered behavior and interfaces

The panel passed to `func_00115830` occupies 0x80 bytes. That provider clears two
0x3C-byte records at offsets 8 and 0x44 and initializes the eight-byte header.
The prior candidate allocated an eight-byte panel and an unrelated sixteen-byte
record. The repaired candidate supplies the complete panel, passes `panel + 8`
to `func_00115940`, and reads the returned level from `panel[12]`: record offset
4. The `func_0010ace0` declaration now preserves its actual `u16 *(s16)` pointer
return instead of routing the result through a declared integer return.

The selected-row icon is drawn when the selection flag is nonzero. The equipped
marker always resets its Y coordinate to the row's base Y plus 26, including
after the selection icon used base Y plus 33. The final panel call uses the
existing shared `Vec2f` type and the actual provider signature
`func_00115c40(Vec2f, s32, s16 *, f32)`.

The row Y calculation, including its initial zero add, recovers the retail
`adda.s`/`madd.s` sequence from ordinary C. That sequence belongs to the row
coordinate calculation, not the opacity calculation described by the obsolete
source note. Declaring the selection state before the color locals retains its
retail register lifetime. The small integer-address helper preserves the
index-first address addition; it is fully inlined and introduces no emitted
function, table, or other allocated data.

The equipped-persona accessor's complete boundary is
`s32 func_00105330(s32 character)`. Its provider still returns the sign-extended
halfword at `D_00797F88[0]`. Both actual callers, `00137890` and `0013d8b0`, pass
the integer character value 1 and consume a word result. The latter's existing
C89 implicit integer declaration is compatible with the corrected prototype.
The coordinated provider patch preserves all 137 provider functions and their
relocations and allocated data; its 16-byte accessor remains unmasked exact.

## Remaining difference

At target offsets 0x80 and 0x84, retail loads parent X before adding the row
offset to the menu address:

```text
00137910  lwc1 $f1, 4($s5)
00137914  addu $v1, $v0, $s5
```

The candidate emits those two independent instructions in the opposite order.
Every other relocated instruction agrees. Ordinary pointer and integer address
forms, declaration and block lifetimes, compatible identifier-list formals,
inline accessors, and selected optimization passes were measured. The residual
is unresolved; these experiments do not establish that exact recovery is
impossible. The assembly fallback stays active.

## Reproducible evidence

The immutable archive is `build/first-party-next/persona-row-worker1/`:

- `inputs.json` identifies the 740 frozen inputs, retail bytes, compiler, flags,
  and symbol addresses. `active-before/reused.json` records the already verified
  normal owner object reused without another baseline compilation.
- `r33-release-candidate/result.json` proves the final source layout: 1340 bytes,
  two differing words at 0x80/0x84, all relocations resolved, all sixteen sibling
  functions and existing allocated data unchanged.
- `release33/staging.json` proves no additional helper function was emitted and
  records the exact guarded source prepared for integration.
- `official34/verify.json` and `official34/completion.json` record the official
  verifier run against the live source: 15 `MATCH`, two `ASM`, all seventeen
  normal owner functions and their canonical relocations preserved, and all
  allocated data unchanged.
- `provider21/provider-proof.json` and `provider21/g_data.patch` record the
  complete equipped-persona accessor correction and provider preservation proof.

The retained `cmpPersona.c` SHA-256 is
`5ff841182afc4f315da24c544c2c16bc300ecb5834f1bc59dc58109633440289`.
The compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The coordinated `g_data.c` SHA-256 is
`62653f4a2c43eac401585d7b7b8f061e10a70e2a701d84c8235bc3bf62a35e8b`.
