# datCalc resistance recovery: live integration, 2026-09-20

`func_0023a6b0` is recovered as ordinary C. The freshly compiled live datCalc
owner reports **78 MATCH / 2 ASM**, up from the status recovery's 77 / 3.
The emitted **12,324 bytes and all 254 code relocations** resolve exactly to
retail. Its remaining twelve retail bytes are zero. The complete **64-byte,
sixteen-entry switch table at `0x00747c40`** also resolves exactly, including
all sixteen `R_MIPS_32` entries. No relocation mask substitutes for this proof.

## Implementation and actual interfaces

The recovery reuses the existing skill-search helper at all 44 searches and the
existing equipment-property helper at eight checks. The equipment helper moves
before its first use; its implementation is unchanged. Retail's separate enum
switches, physical-element case, grouped status cases, default dispatch, and
resistance-override precedence remain explicit. Packed high-byte flags are
shifted as unsigned values in both the resistance query and its small decoder.

The final two instruction differences were an argument-preparation order at the
persona query. Closing that boundary required the real provider chain, rather
than an isolated declaration change. The following definitions and their callers
are now represented consistently by the reviewed changes:

| Provider | Contract |
|---|---|
| `0010a900` | `u16 *(u16 character)` |
| `00109360` | `u16(u16 character)` |
| `00109870` | `u32(u16 character, s32 element)` |
| `00109980` | Public `s32(s32 character, s32 stat)`; compatible C89 `u16` first formal |
| `00109bf0` | `u8(u16 character, s32 stat)` |
| `0010a840` | `s32(u16 character, s32 stat, s32 amount)` |
| `0023a620` | `s32(s32 mode, u16 packedResistance)` |

`00109870` now explicitly returns the decoder result already retained in retail's
return register. `00109360` and `00109bf0` explicitly forward the character
argument previously omitted from their decompiled calls. `00109980` retains its
word argument transport under an explicit compatible prototype: the definition's
`u16` formal default-promotes to this target's `s32`. This preserves the existing
`00232b40` caller without introducing an incompatible provider declaration.

The review covered the complete target retail assembly, IDA and Ghidra exports,
current implementation, helpers and callers; the complete provider owner and
the affected providers' retail assembly; and the external callers' full current
C bodies and retail assembly. The two additional animation caller bodies were
also checked against their Ghidra exports. Existing matching provider functions
are not present in the saved decompiler exports; their actual source and retail
assembly supplied that evidence.

## Main owner gates

`build/first-party-next/datcalc/live_owner.py` captures the official verifier's
actual live-owner object with the standard owner lock. Current configured
compiler and owner flags are retained. Source, headers, relevant configuration,
assembly and tools are snapshotted and checked for changes during compilation.

Both live gates exit zero: **datCalc 78 MATCH / 2 ASM** and
**datPersona 54 MATCH / 2 ASM**. Only `0023a6b0` changes verification status.
All **79 non-target datCalc functions**, all **56 datPersona functions**, and
all preexisting allocated data preserve their bytes and canonical relocations.
The sole added data is the resistance switch table. The entire datPersona
object remains byte-identical to its baseline.

Fresh unmasked proofs from these live objects additionally protect:

| Function | Emitted / retail bytes | Code relocations |
|---|---:|---:|
| `0023a620` | 132 / 144 | 0 |
| `00238940` | 3728 / 3728 | 60 |
| `002411a0` | 2588 / 2592 | 70 |
| `00232d80` | 1304 / 1312 | 24 |
| `00233bc0` | 1280 / 1280 | 23 |
| `00231e20` | 172 / 176 | 8 |
| `00232b40` | 296 / 304 | 11 |
| `00232c70` | 260 / 272 | 8 |
| `00109360` | 36 / 48 | 1 |
| `00109870` | 172 / 176 | 9 |
| `00109980` | 104 / 112 | 4 |
| `00109bf0` | 292 / 304 | 7 |
| `0010a840` | 192 / 192 | 4 |
| `0010a900` | 172 / 176 | 11 |
| `001097c0` | 164 / 176 | 8 |

Every omitted suffix is zero. `00238940` retains its exact 40-byte table.
The `001097c0` row is a preservation check of its unchanged implementation,
not a claim to repair its separate historical return declaration.

Both remaining datCalc guarded bodies, `00235520` and `0023e6f0`, were compiled
individually from before/after snapshots. Each preserves all 79 non-target
functions and previous data; only the accepted `0023a6b0` replacement and its
table differ. The guards remain in production. The old resistance floor comments
are retained in `resistance/final/superseded-source-notes.txt`, the immutable
input sources, and repository history.

Errors-only lint reports zero findings on both main proposals. The live source
diff passes `git diff --check`. No completed historical compilation was rerun.

## External consumer delivery

The prime applied all seventeen external owner patches and independently
compiled their actual live sources. All seventeen fresh live baseline verifications pass. Proposed
objects preserve **1,323 functions and all allocated data**. The seven affected
guarded C bodies also preserve their full compiled owners; 23 affected emitted
C functions have additional fully resolved retail proofs.

The patches normalize actual character IDs and pointer results. Two callers keep
both the halfword identity and its promoted word view; the animation constructor
uses its actual halfword ID. Its existing wide cast remains in one guarded
caller because removing that expression changed the historical C draft's code.
No external source was written by this worker. The prime's completed
`character_current.py` run retained fresh objects identical to all seventeen
reviewed proposals, preserving all 1,323 functions and allocated data.
`delivery/prime-live-after.json` records the sole source difference: one trailing
newline in `src/Camp/cmpSkill.c`; the actual source SHA-256 is
`8952e7eaa001f6305af3b7b5495baf7e7d507698930bb51bf5a9f564b122da8a`.
`prime-current/proof.json` records the actual source, dependency and object
identities. Combined-tree verification remains with the prime.

The selected patch and all source/object identities are recorded in
`delivery/external-manifest.json`, with before/proposed sources under
`delivery/before/` and `delivery/proposed/`. Retained unsuccessful experiments
remain separate and are not included in the delivery.

## Immutable identities and evidence

All paths below are relative to `build/first-party-next/datcalc/`.

- Live datCalc source: `e59acb419dcd7bc5e618ff0cd099fd18a09fc6995ad1babee8d77dc8fd137ccb`
- Live datCalc object: `045981f7597397cf7e1d46b1a942aa1af6defcb914705879e3224a1e5b3f7e61`
- Live datPersona source: `c9bfb3aa35f86289e5b282deee1e526872f28f3d98ef190cff3891174be61875`
- Live datPersona object: `f9cb05de58959ad35c9ef8b4b2b912eaf90ada64ecd76acc3c1536653af2c9a6`
- `delivery/main-live-closure.json`: `0025995802c0e1ccdfe1be8dd6ea899bd4ee3e6c58c58f720c0428f5a12c9839`
- `delivery/external.apply_patch`: `b1d762839b2d32160ef8f56400403c7b41de9211a28a730fdbf46a068e729aab`
- `delivery/external-manifest.json`: `920a0b7b02408d2034c7d4aa2fc75a6b1a374325f683e87f80a9b8c4d1fa62bb`

`resistance/live-final/` and `provider/live-final/` hold the actual live objects,
official reports, input snapshots and resolved proofs. `resistance/final/`
holds the accepted pre-integration source, patch, table and guard preservation
proofs. The live provider differs from its reviewed candidate
`7c3ae8dc3a28808c88ad28a88a271e5b71c9837acdf4aaaeb45b22ae0db7176a`
only by one removed trailing blank line; both compiled objects are identical.
The closure verifies that exact source difference explicitly.

This lane performed no commit, rebase, push, or full build. Global inventory,
combined-tree gates and publication remain with the prime.
