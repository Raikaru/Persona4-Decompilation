# Field-light records: exact `func_0015fb00`

The recovery is integrated in `src/promoted/k_fldHBN.c`, after the SDK/Fcl
integration on `1adec7e926b81497a86b3a4238ba57edfb780c2b`. The actual current
owner compiles to **1052 executable bytes in the 1056-byte retail window**.
All **18 code relocations** resolve correctly; the remaining four bytes are
zero alignment. The seven neighboring functions and all allocated owner data
remain unchanged.

## Record color and call order

The two 32-byte record types contain four color bytes at offsets `+4..+7`, a
three-float point at `+8`, and three more floats at `+0x14`, `+0x18`, and
`+0x1C`. The former guarded draft read a scalar at `record + 7` to obtain one
unaligned load instruction. That address was not the complete color field.

The shared `include/field_light_internal.h` now describes the actual color as
a four-byte `FieldRgba8` value. Both real providers, `func_00145d60` and
`func_00145e90`, take that value after the three float arguments:

```c
s32 func_00145d60(u16 id, f32 *point, f32 x, f32 y, f32 z, FieldRgba8 color);
s32 func_00145e90(u16 id, f32 *point, f32 x, f32 y, f32 z, FieldRgba8 color);
```

The providers' bodies consume the aggregate directly. Their old scalar stack
snapshot and reinterpretation are removed. The existing `Rgba8_0014` name in
the provider owner aliases the shared type. Both providers remain exact at
**300/304 bytes with six resolved relocations each**. Their complete owner
object remains unchanged, including all 126 functions and allocated data.

Passing the real aggregate after the floats produces retail's complete
`lwr`/`lwl` transfer from offsets four and seven. Keeping the aggregate before
the floats left ten target words and four provider words different; placing
it last closes both sides of the contract. This is a coordinated provider and
caller change, not a private prototype chosen only for the target.

## Other instruction differences

Scoped `opt_lifetimes on` removes the saved-register rotation in the earlier
draft. The remaining source changes preserve the observed evaluation phases:

* Each loop increments its counter before advancing its record cursor.
* Unsigned version tests use `version > 0x10000`, `> 0x10001`, and `> 0x10002`.
  These are equivalent to the preceding inclusive comparisons and reproduce
  the retail compare form.
* After creating the second kind of color-bearing record, the resource lookup
  completes before the record's attribute halfword is loaded and stored at
  resource offset `0x18C`.

The eight record groups, their counts and strides, filter tests, and call
sequence are retained. The scalar color experiment, explicit byte assembly,
and packed-word helper controls remain in the local experiment archive; none
of those incomplete variants is installed.

## Complete caller coverage

The two providers have four source call sites: two in this recovery and two
in guarded `func_001587d0` in `src/promoted/code1_0015.c`. All four now use the
same shared declaration and place the actual color bytes last. The latter
draft's two calls retain their original point and float expressions.

The active `code1_0015.c` object remains identical across all 68 functions.
Separately enabling its guarded caller changes that draft from 4556 to 4572
bytes, with its differing-byte score changing from 3337 to 3399. Its call
sequence, 67 neighboring functions, and allocated data remain unchanged.
That draft remains assembly-backed; its ABI correction is not counted as a
new match or a universal scoring improvement.

An independent review decoded both revised guarded call sites. They address
the current record at `+4` and load the four color bytes into the integer
argument register with `lwr`/`lwl`; the ID, point, and float values retain
their intended registers. No new argument is invented or discarded.

## Verification and reproduction

The experiments and immutable inputs are under
`build/first-party-resume-continue/`. `hbn_probe.py` records the data-flow
controls; `hbn_color_contract.py` tests both real provider definitions;
`hbn_integration.py` prepares and verifies complete owners. The
`hbn-integration/` directory contains before/proposed/current source and
object receipts, frozen headers, compiler logs, and unmasked proofs.

The completed current-owner proof is `hbn-integration/integrated-proof.json`.
All three integrated objects equal their measured proposals. The live HBN
source differs from its proposal only by a blank line; its actual source
receipt is recorded separately. The independent review is
`hbn-integration/review.md`, with machine evidence in `sdk/hbn-review/`.

The official scoped verifier reports **202 functions: 189 MATCH and 13 ASM**,
with the new function marked MATCH and no unexpected statuses. Its report is
`hbn-integration/official-verify.json`. This accounts for 7 + 126 + 68 = 201
other functions preserved around the new recovery. `git diff --check` passes.

The configured compiler is MWCCPS2 3.0.1 b210, with the owner's `-O2` profile.
Compiler executable SHA-256, independently checked during review:

```text
286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7
```

This record establishes the target, its changed provider contract, and its
affected owners. Full-project image verification and publication are the
integration lane's subsequent checks.
