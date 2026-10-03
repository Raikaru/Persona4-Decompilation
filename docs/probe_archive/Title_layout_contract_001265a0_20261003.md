# Guarded Title controller: record/index/float/speed contract

Base: `c0da65b93e785858dad848163c2482b7b0d533cb`, the matrix checkpoint.
This is a bounded repair in `func_001265a0`. **The NON_MATCHING guard and
production fallback remain. There is no new exact-C credit or full Title,
renderer, ACC-producer or gameplay execution claim.**

## Source recovery

- The guard-local record root uses the existing matched siblings' byte-array
  contract. Four already-byte-strided row expressions retain their semantics
- Both selected model reads load a full signed word from a 40-byte row. Their
  actual signed word → f32 → signed word round trip and signed `>=15` rejection
  remain. There is no invented lower-bound clamp
- The four direct row-zero expressions retain direct signed-word semantics.
  They do not gain a float conversion. Slot indexing remains on `u32 *`, so
  its existing subscript already multiplies the index by four
- Pitch, yaw, scale and speed load their raw f32 words. There is no integer
  numeric conversion for these fields
- The local speed declaration is the actual provider's
  `void(u8 *, s32, f32)` contract. Both guarded calls now transport speed in
  f12. The earlier GP-float expression is unchanged; the provider's s32 layer
  formal still masks with `0xffff` internally

The exact source reconstruction permits only these sixteen line changes.
The one existing native palette fixture alias changes from scalar to byte
pointer to follow the real table declaration. The provider, updater, previous
matrix/vector repair, every helper family, call order and post-validator reload
remain unchanged. Complete owner/table/provider-use censuses are included.

## Evidence and verification

The retail ELF is authenticated before inspection. All 4,404 fallback words
and the nineteen 40-byte native test rows agree with its actual bytes. The
whole owner is compiled before/after in production and guarded configurations.

- Production raw object is identical, SHA-256
  `59e652c8faa507dfb2feae59814a9668abfdbb377ba7eb62c3167eac9a7cc8c5`
- All 81 guarded siblings and relocations are exact; all 420 non-target data
  bytes, section properties and references are preserved
- An explicit instruction map checks 4,115 retained instructions and 285
  branch destinations. The compiler's earlier s0/s1 reassignment is checked
  as an exact GPR-operand bijection over its measured live region; no opcode
  or register mask is used. Stack homes and the matrix call block are unchanged
- All sixteen switch destinations are checked. Every reference event and
  addend is retained except seven incorrect GP root events becoming exact
  HI/LO pairs and the earlier speed call's removed default promotion.
  Root `005E5230` is outside signed GP16 reach; all HI/LO symbol addresses,
  zero addends and field-alias offsets are checked explicitly
- New live-source native tests run 13,465 scenarios at each O0/O2 with trapping
  undefined/bounds sanitizers and the existing no-strict-aliasing/SSE fixture
  settings. Forty-eight independent control runs fail as expected
- Actual retail/emitted instructions execute 15,504 bounded selection cases,
  760 pointer-free conversion/predicate probes, eight isolated unsigned bound
  probes, twelve earlier speed boundaries and seventy actual provider cases.
  Sixteen independent machine controls fail
- All 36 earlier Title native tests rerun without skips. All eight older
  bounded machine scopes plus entry and matrix contracts rerun on the final
  object, including the matrix's 512 actual provider-copy-loop cases
- Thirteen relevant production owners: **510 MATCH / 63 ASM**. Title remains
  **81 MATCH / 1 ASM**. Actual speed provider: 52 bytes, matching its 64-byte
  retail window with a zero-only tail. Lint: **0 errors / 32 advisories**
- Full repository production verification: **9,574 MATCH / 3,528 ASM**
  across 13,102 functions, with no failure status
- Full production build: 604 C owners plus 54 Sony SDK owners linked. Both
  loadable-image and reconstructed ELF SHA-1 checks match retail. All 81
  Title C siblings remain linked; the guarded controller earns no C credit

The new guarded body is **16,712 / 17,616 bytes**, with **3,973** position-based
relocation-masked differing words. Its base was 16,840 bytes / 3,980 words.
This metric does not imply a whole-function semantic proof or an exact match.

## Defined native domains and limits

Full selections use row indices 0..18, actual retail model words, or synthetic
accepted model indices 0..14. Synthetic 15 takes the rejection before a model
slot is formed. Validator results 0, 1, 2 and -1, callback row changes, mutated
slot pointers, separate first/second selection identities, counter-zero gating
and saturation are exercised. Nonzero validators require reloading the actual
slot; their result is never substituted for its model pointer.

Negative and large model words execute conversion/predicate slices only.
These include ±16777217 with independent ±16777216 expectations. No negative
or large model-slot pointer is formed. INT_MAX and other positive values that
round to +2^31 are excluded. This is not a hardware-wide rounding emulation.
The unsigned row diagnostic is tested in isolation for 18, 19 and UINT_MAX;
out-of-range rows never run the preceding full-path record reads.

The source-extracted speed provider runs against sufficiently large real
32-bit storage for layers 0, 1, 2, 65535, 65536, -1 and -65536. Its masked main
store and zero-layer mirror are checked with ten finite raw float patterns,
including signed zero, .12 and maximum finite magnitudes. Earlier speed-call
transport is tested with a valid model pointer; this does not prove an
unconditional provider call on a failed earlier validator safe.

Validators and unrelated callbacks are typed recorders. Full renderer,
unrecovered sine/ACC expressions, helper-call ABI families, and full matrix
providers remain outside this proof. Actual matrix provider padding remains
unspecified; no padding or dummy values were added to production source.

Final owner source SHA-256:
`a6684ac3ce4e80240fa76651c1de17bd2562e429192ff48bdb577f1df233ee64`

## Replay and archive

Run from the repository root with configured licensed toolchain/retail inputs,
Clang, GNU ld and an existing i386 runner:

```sh
bash docs/probe_archive/Title_layout_contract_001265a0_20261003/replay.sh
```

`P4_NATIVE32_RUNNER` defaults to `qemu-i386`. Compact measurements and test
output are committed; intermediate objects, full disassemblies and logs remain
untracked in `proof/`. The source-only manifest uses repository-relative keys.
No push, upload, CI, publication or full repository native suite was performed.
