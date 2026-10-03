# Guarded Battle vector storage: actual 12-byte producer/consumer objects

Base: `6db34823ac38e6b7833489795a4c52c871a5dcc0`.
Both controller fallbacks stay enabled in production. No match is promoted.

## Source and retail evidence

`func_001a59a0` previously declared `s32 sp308`; `func_001a7720` declared
`s32 sp578`. Each address is passed to providers that write three float
components and to packet factories that read all three. The source objects
were four bytes, so adjacent scalar locals did not establish the required
12-byte storage, regardless of their stack-like names.

Each controller now has a real `RwV3d targetPosition` object. Existing
provider types are used without changing any provider definition:

- `func_00196040(u32, u32, RwV3d *, f32 *, f32 *, u32)` returns f32
- `func_001958f0(BtlUnit *, RwV3d *)` returns void
- `btlUnitCreateRotatePacket(BtlUnit *, const RwV3d *, u32)` returns BtlPacket *
- `btlUnitCreateLookAtPacket(BtlUnit *, const RwV3d *, u16)` returns BtlPacket *

Only the corresponding declarations and eight call expressions in these two
guarded bodies change. The existing file-scope RwV3d and rotation declaration
are reused. The actual unit-pointer loads replace integer/byte-pointer views.
No nominal ABI slot, dummy argument, padding, global or compiler flag is added.

Retail has four consecutive producer/consumer pairs:

| Controller | Producer call | Consumer call | Vector address |
|---|---:|---:|---:|
| 001A59A0 | 001A5AE4 group center | 001A5AF8 rotate | SP+308 |
| 001A7720 | 001A7A60 group center | 001A7A74 rotate | SP+578 |
| 001A7720 | 001A7ABC unit grid center | 001A7AD0 rotate | SP+578 |
| 001A7720 | 001A9D50 group center | 001A9D64 look-at | SP+578 |

The group producer writes output offsets 0/4/8 at `00196598..001965A0`.
The unit producer writes 0/4/8 at `00195974`, `00195984`, `001959B4`.
The rotate factory reads all three words at `00197FB8..00197FC0` and copies
into work+4/+8/+C. It allocates 24 bytes and stores full-word flags at +10.
The look-at factory similarly reads/copies all three at `0019E1B0..0019E1C4`,
allocates 20 bytes and stores halfword flags at +10. The audit pins 62 decisive
retail instructions, including all caller argument setups and these extents.

## Executed source contract

The new fixture extracts all four actual caller pairs, both actual variable
declarations, the provider structs and the four entire provider definitions.
It does not rewrite the caller expressions. The object is surrounded by
canaries; all three components, destination identities, flags, packet sizes,
callback fields and allocation counts are checked.

At O0 and O2, 65,536 cases cover four sites, four flag patterns, 4,096
coordinate seeds spanning signed grid coordinates, half/double scale, single
and paired admitted targets, and an excluded unit whose flags would change
the output if the exclusion parameter were wrong. The group options are the
actual caller value 1. Empty groups are excluded: the provider leaves its
output untouched in that case, and this work does not invent initialization
or claim validity for the subsequent retail read.

Allocation and group-mask lookup are controlled recording boundaries. The
lookup adapter records the address word used by the existing pointer/word
views; it is not a new production declaration. Quaternion transformation is
a controlled identity-rotation boundary with its input, unit and count
checked. The length boundary returns a controlled radius contribution; the
callers discard radius. Thus this fixture proves vector production and
transport for these source cases, not every geometry helper or FPU behavior.
No whole controller, renderer, gameplay or PS2 execution is claimed.

Eight negative controls are rejected: undersized object, missing group Z,
missing rotate Z, missing look-at Z, wrong excluded flags, wrong unit source,
wrong look-at unit, and narrowing rotation flags. The undersized control fails
its runtime extent check before any provider can perform an undefined write.

## Complete-owner preservation and current nonmatches

All eight baseline/final builds succeed: production, either guard separately,
and both guards together. Production objects are byte-identical. Every
unaffected function and relocation is preserved: 70 per single-guard build,
69 with both guards. All 148 allocated data bytes and 36 references match.
The candidate audit verifies all eight call destinations and that each
controller's producer/consumer arguments use one aligned, frame-contained
12-byte object. Candidate addresses are SP+438 and SP+668; both differ from
retail, as expected for these unfinished bodies.

The owner remains 69 MATCH / 2 ASM. The unchanged btlUnit provider owner
verifies 41 MATCH. Lint remains 0 errors / 24 existing warnings. The combined
native families pass 42 tests without skips.

The 59a0 object remains 7,852 bytes with 5,944 differing bytes and a 0x450
frame. The 7720 object remains 17,400 bytes with 12,850 differing bytes;
its frame grows from 0x680 to 0x690 to accommodate its real storage. This is
bounded semantic reconstruction, not score or first-party match credit.

Other stack output objects, narrow loads and decompiler-expression problems
remain in these controllers. No full-image gate, remote CI or push is claimed.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_vector_storage_20261003/audit.py proof/vector-replay
python docs/probe_archive/Large_Battle_vector_storage_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c src/Battle/btlUnit.c
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit `--runner` only for a host that can execute i386 directly. A skipped
runtime is unverified, not a pass. The audit checks source/test fingerprints,
retail identity, every sibling/data reference and candidate call address.
