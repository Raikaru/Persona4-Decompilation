# Field unit creation: 00164230

Recovered on 2026-09-20 in `src/promoted/k_fldUnit.c`. The integrated owner
contains 37 MATCH and 5 ASM functions. This note supersedes the earlier
`KFU_00164230_body.c` floor; that historical candidate remains archived.

## Source and toolchain identities

The SHA-256 values below identify the complete owner immediately before and
after this recovery. The after hash was checked again before writing this note.

```text
before e188efefe164a7cff0b41d9aa1c13ec76a3421e98eebf857fb15f198d723325f
after  4be68043a5beb6b0394d70b7fbd120429ae259fecbce6cec1513fb71fe60830c
```

The configured compiler was MWCCPS2 3.0.1 b210 with `-O2 -Iinclude`. The
isolated proof substituted frozen copies of the consumed headers for the
include directory; it retained the actual owner's compiler and other flags.
The compiler SHA-256 was
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The validated retail ELF SHA-1 was
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Reconstruction

The primary allocation, cache traversal and party-selection branches have
separate local lifetimes. The signed party-reader result, unsigned 16-bit
PC ID and promoted model selector retain their distinct uses. Loop counters
belong to their actual loops, while the cache's model-pointer slot survives
model teardown. The two row-address expressions use signed and unsigned
index arithmetic; this preserves the observed row recomputation without the
previous common-subexpression pragma.

`D_005F13C0` is an external array of 32-byte script-path records. The retail
320-byte region contains ten records: two reserve paths, then yousuke, tae,
yukiko, rise, kanji, naoto, kuma and kitsune paths. The recovered access is
through `((u8 (*)[32])D_005F13C0)[pcId]`, using the actual PC ID. Treating the
same access as a flat integer offset left either a missing move or a
redundant narrow conversion. The array access closes that final instruction
without added state, padding, volatile accesses or assembly.

The target's sole real caller is `k_field.c:func_00155360`; its declaration
is `void (u16, u16, u16)`, and retail loads all three fields with `lhu`.
The owner's declarations now agree with the real providers: `DatUnitPc *`
from `00231580`, `u8 * (u16, u16, s32)` for `00162680`, `s32 (u16, u16)`
for `00162510`, `s16 (s32)` for the party reader, `u8 (u16)` for the level
reader, and `void (u8 *)` for model teardown. The other model-teardown
calls in this owner were changed to pointer loads. No external source edit
was required.

## Verification

The integrated object emits all **832 bytes** of the retail function window.
All **31 relocations were applied**, yielding **zero unmasked differing
words**. The resolved target SHA-256 is
`87e8e7ab0b2386d3e794bd0a3174bdfeb8010ff50d0080ffdcf3de7fc3d8996a`.
There is no missing zero suffix and no target-owned jump table.

All **41 neighboring functions** retain their exact object bytes and
canonical relocations. Every allocated data section is unchanged. No extra
function is emitted; the script-path array remains an external retail data
reference rather than a newly allocated table.

The official current-owner command exited zero:

```text
python -S tools/verify.py src/promoted/k_fldUnit.c --json build/first-party-finish-20260920/field-worker6/current-owner.verify.json --show-mismatches
42 functions: 37 MATCH, 5 ASM
```

The official JSON report SHA-256 is
`8e58635ea767e8a3bdd7fb6c4c5d38f7e05d6626fcba42179ecec7dd75ccfcff`.
`git diff --check -- src/promoted/k_fldUnit.c` passed.

The immutable local evidence lives under
`build/first-party-finish-20260920/field-worker6/`: `proof.json`,
`current-owner.verify.json`, `integration-before.c`, `integration-after.c`,
`integration.patch`, and `func_00164230/current-integrated/audit.json`.
The integrated object SHA-256 is
`212aadbf3c1c644359bcdf6cff577d159583b3e7a4beb1ed7b9b84339213f5c0`.
`closure/` preserves the caller/provider sources and retail windows used by
the ABI audit. Completed compile jobs were reused when preparing this note.
