# Primitive quaternion/scale callback: 00480940

The game callback is recovered as production C: 348 exact relocated bytes and
four authentic zero tail bytes. Both callback parameters remain `void *`.
Using the incoming result parameter at its typed consumers removes a redundant
local pointer web and reproduces retail's output-before-input save order.
The quaternion formulas, COP1 operation grouping, scale-before-multiply calls,
translation reload after Multiply, and final flags mask are unchanged.

## Target-specific opaque SDK contract

This caller uses RenderWare's documented REPLACE output-storage boundary.
Criterion's *RenderWare Graphics 3.7 User Guide*, volume 1, §2.10.3 (I-55),
describes constructing and replacing a transformation across all matrix
transforming APIs. The SDK team's `uvanim` example declares a raw automatic
matrix and passes it to Translate(REPLACE) before reading transformation fields.
Applying that generic contract to Scale is the explicit, independently reviewed
caller-boundary judgment here, not a claim that a raw Scale example was found.

Primary archived SDK sources, snapshot `2d89df64a7d03122f6c419d91bad2fdfd496c54e`:

- [User Guide, volume 1, I-55](https://github.com/sigmaco/rwsdk-v3.7.0.2/blob/2d89df64a7d03122f6c419d91bad2fdfd496c54e/docs/userguide/UserGuideVol1.pdf)
  (PDF SHA-256 `b8a46f5a6f7e57d1e2b26617311641269203bf21f32610b6e961eb839044ab47`)
- [Original UV-animation example, lines 520–534](https://github.com/sigmaco/rwsdk-v3.7.0.2/blob/2d89df64a7d03122f6c419d91bad2fdfd496c54e/examples/uvanim/src/main.c#L520-L534)
  (Git blob `2edc7fc0169895141b325ab314700e8f362eb635`)

Counter-evidence was retained: User Guide I-35 recommends creator functions;
core `MatrixQueryRotate` initializes local flags before SetIdentity; the only
Scale(REPLACE) call in the 222-file SDK example census uses RwMatrixCreate.
Those facts do not prove globally defined uninitialized provider C. Existing
matched game code was not used as a policy waiver.

## Provider debt and actual retail dependencies

The temporary scale matrix is at sp+0x70, flags at sp+0x7c; retail has no prior
write to that word. At 003e0b04, actual Scale(REPLACE) reads and ORs flags with
0x20003; at 003e0c60–74 it clears exactly those bits. Its result is
`incoming_flags & 0xfffdfffc`, preserving every other incoming bit.

The rotation matrix flags are initialized to 3. Multiply at 003e05f0 reads and
ANDs both flags, so all possible incoming scale flag bits are killed in this
specific caller. Final output flags are zero before and after the final mask.
Scale writes all twelve numeric fields before Multiply. Input row-tail padding
is excluded from Multiply's VU `.xyz` arithmetic; its full-row output stores
nevertheless write the VF result W lanes. These are not modeled as defined
numeric padding values. All Multiply input rows and flags precede its stores.

**The reconstructed Scale provider still performs an indeterminate C read if
called directly with this raw local. This promotion is a target-specific game
caller match at the opaque SDK boundary, not whole-program-defined provider C,
not a provider cleanup, and not permission for arbitrary uninitialized locals.**
No fake ABI, self-copy, aliased initialization, ordinary-memory volatile,
provider alteration, inline arithmetic assembly, or padding was introduced.

The independent contract review bound 19 actual flag opcodes and all-bit
independence with four negative controls. Its sealed review SHA-256 is
`deb9f9bb831ab203168cf4868d739ea51144f1bc11b935aed0ae0bd515354819`;
review checksum-list SHA-256 is
`ec7031918bc58b5a68b547f67031db07d31d55b38682536aceaa20637d35d5e3`.

## Native boundary tests and limits

`test_primitive_apply_sdk_boundary.py` extracts the production target unchanged,
the real Scale function body (renaming its identifier only for tracing), and
its real SDK macros. The explicitly labeled boundary fixture supplies one of
35 controlled flag seeds and varied defined padding words **before** actual Scale C is invoked. It never reads
an uninitialized native word and never equates that setup with a retail store.
All 32 flag bits, all-ones, a mixed word and zero are covered. Standalone Scale
checks preserve all other bits, written numeric fields and untouched padding.

O0 and O2 each pass 368,585 cases: 10,125 quaternion/scale combinations and
405 overlapping-output/frame cases under each of 35 seeds, plus 35 standalone
provider cases. Ten native negative controls fail at each level: provider
order, cross-product sign, scale offset, Multiply operand order, rotation flags,
early translation capture, translation offset, provider flag erasure, padding
clobber, and incorrect provider mask. The final target mask is dead with these providers,
so a structural negative control preserves its retail operation rather than
fabricating nonzero provider output. Another rejects a changed callback ABI.

Multiply is an explicit scalar dependency model with known synthetic W lanes.
No VU execution or EE ACC floating-point emulator is claimed. Dyadic finite
inputs avoid making rounding, NaN, overflow, denormal or generic-host-FMA claims.
Overlaps run in the existing native fixture's no-strict-aliasing mode and
establish storage/load timing, not a new effective-type proof. Authentication
of the exact relocated target instructions is the separate EE-code evidence.

Reproduce the focused native gate with:

```
python -m unittest discover -s tests -p test_primitive_apply_sdk_boundary.py -v
```

Use an existing i386 execution path or `P4_NATIVE32_RUNNER` as supported by the
repository fixture helper. Scoped whole-owner verification retains all eleven
siblings and all allocated data sections; both SDK providers remain untouched.
Full verification, production linking and both retail hash checks are required
before publication, with this object confirmed C-linked in the linked report.
