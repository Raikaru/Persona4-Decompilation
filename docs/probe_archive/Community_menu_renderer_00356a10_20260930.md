# Community-menu renderer `00356a10`

Measured on 2026-09-30 against main
`2f948e5dbef9301bb033293d9bd072e8c55c3e7c`, using MWCCPS2 b210 at
`-O2 -Iinclude`. The whole owning translation unit is
`src/promoted/code1_0035.c`.

## Result and preservation

- Active C: **10,536 instruction bytes in the 10,544-byte retail window**;
  the remaining eight retail bytes are zero alignment, not source padding.
- All **115 relocations** resolve exactly: 67 `R_MIPS_26`, 24 `R_MIPS_HI16`
  and 24 `R_MIPS_LO16`. The resolved instruction stream and retail stream
  have SHA-256 `c1cc9c57953fcd18167e2a3b0461173cc806e3621124b42fd7e044265a396396`.
- Production owner: **78 MATCH / 2 ASM**. With `NON_MATCHING` enabled:
  **78 MATCH / 2 NONMATCHING**. `0035aff0` remains guarded.
- All 79 sibling images and canonical relocation records are unchanged,
  including the previously recovered `0035fd60` and the supporting functions
  whose types are repaired here.
- The four affected owners contain 298 functions. In both production and
  guarded builds, only `00356a10` changes image or status. The other owners
  are `code1_002b.c`, `code1_0014.c`, and `Camp/cmpPersona.c`.
- Every allocated data section remains unchanged, and all four owners pass
  the official C-link eligibility gate. No new symbol mapping is needed.

The archived body, including its scoped pragmas, has SHA-256
`28df25a17ef62dac24a2d52c7bcd5781fdb331943500a7a0738c68d60e92af73`.
The function-only text extracted by `recovery_quality.function_bodies` has
SHA-256 `8d69026437405e3a1b018242fb70ae89a48d823999783bd3a863118c944d22c7`.
These are two explicitly different source ranges.

## Source and ABI recovery

The starting guarded reconstruction compiled to 10,928 bytes with a `0x130`
frame. The final frame is `0x100`. The useful changes describe real objects
and value lifetimes rather than manufacturing register carriers:

- A sparse, offset-checked context view, real `Vec2f` positions, four-byte
  RGBA objects, and a fully initialized 16-byte integer rectangle replace
  decompiler scalar carriers. The rectangle retains the existing pointer
  transport interface without converting its integer payload to floats.
- Native unsigned conversions replace 21 expanded input conversions and
  45 expanded output conversions. Scales are `u16`, pivots and relevant IDs
  are signed halfwords, and opacity remains a quantized byte.
- Actual palette views, phase-local coordinates, retained resource handles,
  and live ID/flag/palette queries reproduce the observed callback timeline.
  The dark palette uses its canonical byte-array symbol and retail HI/LO
  references. The existing target-width address helper expresses bounded
  index-first addressing; no dummy storage is introduced.
- `00355410`, `0035aff0`, and `0035c040` share a byte-opacity input contract.
  The two float-returning providers must change together with their native
  `(f32)arg1` conversions; retaining the obsolete intermediate `(u32)` cast
  would be an incoherent partial migration. Their complete generated images
  and relocations remain unchanged. The only external `00355410` callers
  are in `cmpPersona.c` and `code1_0014.c`; both declarations are updated and
  both owners verified. Retail callsites are `00136590`, `001404dc`, and
  the target's `00356d84`. The other two providers are target-only calls.
- `0035c670` writes an actual `Vec2f`, with both output coordinates initialized.
  `002bc0b0` forwards its actual x/y/depth float inputs to `002bc0e0`; its
  former uninitialized float temporaries were decompiler residue. The entire
  `code1_002b.c` object retains its prior bytes and relocations.
- `00356250` initializes selected-entry display modes to 0, 1, 2, or 3.
  The renderer's rank selection is defined over that constructor-established
  domain. The fixture exercises all four modes, rather than inventing
  unsupported states to justify new source branches.

The scoped `opt_lifetimes on`, `opt_propagation off`, and
`opt_pulloutconstants off` settings have measured roles: preserving the
phased live ranges, retaining packed colors captured before callbacks, and
avoiding extra call-crossing float constants. They are restored with
`#pragma pop`. No ordinary-memory `volatile`, invented ABI, handwritten
conversion algorithm, inline computation assembly, or window-filling padding
is used. An independent source/ABI review checked the layout, output
initialization, valid-mode invariant, caller census, and provider identity.

## Behavior and regression checks

`tests/test_community_menu_contracts.py` extracts the active production body
and three actual tiny providers unchanged. Its separately written raw-offset
model checks ordered calls and complete context/palette state. The model
covers all rendering passes, 108 cells, six separators, five visible rows,
nine dynamic detail rows, all four display modes, signed-halfword boundaries,
byte opacity boundaries, and 128 flag combinations. Callback mutations test
retained versus live values. Getter stubs do not invent unrelated context
mutations that would depend on unspecified C argument-evaluation order.

The exact committed fixture ran as freestanding i386 C under GCC and qemu-i386
at **both O0 and O2**, with undefined/bounds/float-cast checks enabled:

```
PASS scenarios=3360 checks=1291297 trace_hash=2455546061
```

The output is identical at both optimization levels. The fixture SHA-256 is
`0c88ac8f5a6cceec2c955b29b40a494bdce6208e2b8dd27a6b1eac596d98b872`.
A separate sensitivity run compiled and rejected **31 semantic mutants**,
including stale and wrongly reloaded values, signedness, wrong opacity
conversion, incorrect rectangle transport, missing passes, row bounds,
wrong vector coordinates, wrong setter offset, and broken float forwarding.
Six representative mutants are retained in the reusable test. This is native
C semantic coverage, not EE/GPU emulation or a gameplay claim.

Validation of the final source:

- `python -m unittest discover -s tests`: **841 tests, OK, 30 skips**.
  This environment lacks Clang, so the two new Clang-based native unittest
  methods skip; the exact integrated fixture was also run through the GCC
  and qemu path above, including both optimization levels.
- Changed-owner decomp lint: **zero errors**, no findings in the new renderer;
  85 advisories elsewhere in the four owners remain for separate review.
- Pragma audit: all 43 distinct spellings (42,241 uses) recognized by MWCCPS2.
- `git diff --check`: clean.

Reproduce the owner checks with `tools/verify.py` for all four files, in
production and with `-DNON_MATCHING`, and use `tools/build.py`'s official
eligibility/build-progress path for owned-data and physical-link checks.
Run the reusable behavior tests with:

```
python -m unittest discover -s tests -p test_community_menu_contracts.py -v
```

The local environment cannot perform the full proprietary multi-compiler
build. Publication therefore still requires the exact-commit CI result:
retail image SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78`, retail ELF
SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c`, and physical C linkage of
the affected owners. Eligibility alone is not that final proof.
