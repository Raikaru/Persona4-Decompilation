# Pair and duel action cameras

The interrupted camera work was recovered from the actual owning translation
unit at `6d950a12d36f08706cd42225d5513e5a50d25748`, preserving the earlier
worktrees. Both bodies derive from the typed Persona 3 FES camera source at
donor commit `04d95e2`, with the Persona 4 instructions and call contracts
checked independently.

| Function | Executable bytes | Retail window | Resolved relocations | Zero suffix |
| --- | ---: | ---: | ---: | ---: |
| `func_001bf5e0` | 1416 | 1424 | 29 | 8 |
| `func_001bfc00` | 2256 | 2256 | 53 | 0 |

These are ordinary C definitions. Their two-pose arrays contain actual
28-byte position/quaternion records. The interpolation cache contains both
quaternions, its scalar, and its flag in 40 bytes. The reconstructed temporaries
are real vectors and scalar values; there is no instruction padding or
allocation-only assembly.

The pair camera preserves the acting unit's radius and scale at the relevant
distance calculation. It does not substitute the second unit's dimensions.
The duel camera retains its separate height snapshot, horizontal vectors,
600-unit distance clamp, and final adjustment of both poses. All calls and
floating-point branches keep the Persona 4 order.

Review corrected the duel's declaration of `func_001bc3a0` to its actual
`u32 (f32 *, f32 *)` type. The return remains intentionally unused. Unit-center
queries use `btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *)`, and three-dimensional
normalization uses `RwV3dNormalize(RwV3d *, const RwV3d *)`. These corrections
preserve every instruction word and resolve to the original retail callees.
They do not assert that unrelated legacy declarations elsewhere are reconciled.

Three previously missing float aliases are recorded in both curated symbol
inputs and the recovered symbol map, without removing any existing aliases:

| Alias | Address | Retail use |
| --- | --- | --- |
| `fGpffff804c` | `0x0076113c` | Duel small-angle threshold |
| `fGpffff8158` | `0x00761248` | Pair angular limit |
| `fGpffff8160` | `0x00761250` | Duel rotation scale |

The actual caller in `src/promoted/code1_0022.c` now declares the pair callback
as `void (u8 *)`. Its entire active object remains identical, including all 98
functions, symbols, data and relocations. The dispatch records independently
identify the pair and duel callback entries at `0x005F7664` and `0x005F7678`.

The first fresh integrated-owner proof retained all 121 other functions in
`code1_001b.c` and all existing allocated data. The subsequent canonical-contract
proof again retained all 123 instruction streams. The later combined camera
release also promotes `001be990`; it proves all three targets, preserves the
other 120 functions, and separately verifies the new four-byte duration literal.

Local evidence, kept outside the committed source, is under:

* `build/first-party-resume-active/action-camera-integration/current/`:
  initial fresh owner/caller proof and scoped official verifier.
* `build/first-party-resume-now/camera-contract/`: isolated provider-type
  correction and unchanged-instruction proof.
* `build/first-party-resume-now/camera-release/`: combined three-camera source,
  object, complete relocation records, owned-data proof, and resolved bodies.

The combined release source SHA-256 is
`457b07705e90c03218695fd50455995a565e8d85493b30ea62249bbbc7789d77`;
its object SHA-256 is
`8eb353b246b1e55e1fc88722eab11a90ec94534ae91e6293befb8f8679c0acfe`.
Later caller-only changes must be compared against that release rather than
silently treating these identities as a newer whole-owner receipt.

As with the retail battle-camera callbacks, inputs are initialized camera,
action, and unit objects with the target records selected by battle dispatch.
No arbitrary-null or corrupted-battle-state guarantee is claimed.
