# Packed-color provider recovered as native C, 2026-09-22

`src/promoted/code1_0048.c::func_0048abd0` is integrated as C and officially
MATCH. Native MWCCPS2 b210 with the configured `-O2 -Iinclude` emits 1,044 bytes
in its 1,056-byte retail window. Its one GP-relative relocation resolves
exactly, there is no referenced function-owned data, and the remaining twelve
retail bytes are zero alignment. The owner retains all 72 sibling functions'
instruction bytes and canonical relocation destinations; allocated data is
unchanged.

This is the follow-through after the flare and return-contract recovery in
`Model_flare_004a6e70_20260922_worker4.md`. That earlier milestone retained the
provider's fallback. This later milestone replaces it with exact C. The
audited signed 32-bit ABI, all 37 native call sites and their 11 source owners
remain as recorded there. No additional caller or header edit was needed.

## Behavior and repaired reconstruction

The provider selects the appropriate pair of RGB keys for zero, one or two
intermediate color keys. It computes a blend within the selected integer-frame
segment, interpolates the unpacked channels in VU0, and combines the resulting
RGB with a separately faded alpha value. With zero duration it returns the
first RGB value and the supplied alpha directly. Both returns use unsigned
packing and the proven `s32` result contract.

The old guarded draft had three semantic defects independent of its register
differences: the full-opacity plateau was never initialized, its fade-in
division used the untruncated floating threshold rather than the integer
boundary used by retail, and its fixed stack-address assembly store did not
declare the packed output that C subsequently read. The recovered C initializes
opacity to one, calculates both signed integer fade boundaries, and declares
the actual VU packed output as a memory result.

The byte closure then follows real value lifetimes. Capturing each later
segment's denominator before its numerator reproduces the retail conversion
order. Keeping the RGB blend declaration before the duration/opacity values
reproduces the float-register assignment. A small returning opacity helper
preserves the compiler's three-instruction division wait at the fade-out
boundary. No scalar computation or padding assembly was added. The assembly
is limited to packed-color MMI/COP2 bridges, with actual C inputs and outputs.

The final source uses typed `EffectPackedColorKeys` and
`EffectPackedOpacityKeys` views and named scalar values. Their consumed field
offsets are established by the byte-exact native loads. The unused opacity
word at offset four remains neutrally named `field04`. The external function
signature continues to match its existing byte-pointer callers. Obsolete
guarded code and its superseded mismatch commentary were removed.

## Evidence

Receipts are under
`build/continue-first-party-20260922/worker4-color-provider-c438874-v1/`.

| Candidate | Native bytes / window | Alignment edits |
| --- | ---: | ---: |
| Coherent VU output and initialized opacity | 1,032 / 1,056 | 46 |
| Segment denominator captured first | 1,032 / 1,056 | 22 |
| Correct blend lifetime | 1,032 / 1,056 | 9 |
| Returning fade helper | 1,044 / 1,056 | 3, all zero tail |
| Final typed and documented source | 1,044 / 1,056 | 3, all zero tail |

`final-candidate/unmasked-proof.json` and
`live-native/resolved/func_0048abd0.json` independently resolve and compare
the complete provider. The resolved function SHA-256 is
`1dfbd2d91b84fba1529afc3c64171f4f0a7eb164be692f75e6ad88228a018835`.
`final-candidate/preservation.json` records all 72 sibling and allocated-data
comparisons against the actual active owner baseline.

`official-before/official.json` reports 60 MATCH and 13 ASM for the provider
owner. `official-candidate/official.json` reports 61 MATCH and 12 ASM. After
integration, the actual live provider was freshly compiled in
`live-native/provider/`; its complete object equals the prepared object.
`live-native/official/official.json` checks all four affected live first-party
owners and reports **223 MATCH, 14 ASM across 237 functions**. Both the new
provider and flare are MATCH, as is the preserved `0048a460` projection.

`live-native/closure.json` records the final source/object/compile-receipt
bindings for all four owners. The resolved proof directory also contains the
existing `0048b220` caller, flare and projection proofs. The other three owners
retain their sealed flare-closure hashes and native objects. The provider
remains link-eligible (`live-native/link-eligibility.json`), live provider lint
has zero findings, and the final scoped `git diff --check` passes.

The final provider source SHA-256 is
`845ad5db3a1e9ca8c4889c0c5acbcdae3ff383d84ec1136d8a1ba4f6b5e1eb71`.
Its native owner object SHA-256 is
`7045f2118359efd71aaa80da9d90b63660125ed9d78d7de450e403a36dd132b9`.
The native compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

Exact helper discovery completed in session `66907`; final native preparation
and official candidate verification completed in `35796`; integration
completed in `90930`; fresh live compilation and final verification completed
in `11042`. All completed probe destinations are retained unchanged.

This recovery adds one first-party C MATCH after the flare's one MATCH. It
makes no global census, full-build, commit, push or vendor-source claim. Shake
`004a7830` remains at its inherited seven-word residual; its body is unchanged.
