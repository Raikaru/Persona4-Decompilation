# Model flare recovery and packed-color return contract, 2026-09-22

`src/Graphics/Model/mdlEffect.c::func_004a6e70` is integrated as C and officially
MATCH. Native MWCCPS2 b210 with the configured `-O2 -Iinclude` emits 2,276 bytes
in the 2,288-byte retail window. All 53 code relocations resolve exactly; the
remaining 12 bytes are zero alignment. No referenced function-owned data is
introduced. Existing `func_0048a460` and the other 51 model siblings retain
their instruction bytes and canonical relocation destinations.

This continues the immutable `worker4-flare-aggregate-v1/numerator-comma-lifetime`
candidate after rebasing to `c4388741f9070eaec2b37e3a3af3684886d1a581`.
The remaining two extension instructions disappear when the actual first-party
packed-color provider and its callers share the proven signed 32-bit return
contract. The earlier unsigned 64-bit guarded declaration is not retained as
an incompatible provider behind a narrowed caller.

## Recovered behavior and contracts

The flare loads the source position into VF10, uses the existing visibility
projection, then renders the 13 configured flare entries. The reconstruction
preserves the lifetime gate, radial brightness, the empty-entry position
copies, material updates, four quads per visible entry, and the final
camera-space conversion. Packed-color and vector bridges contain genuine
MMI/COP2 operations with declared inputs and outputs. Scalar arithmetic,
branching, traversal and storage are C. The inherited scalar approximation,
missing projection output and obsolete guarded-body hypotheses were removed.

The color provider is `func_0048abd0` in `src/promoted/code1_0048.c`. An audit
identified 37 native calls across 11 source owners. Every source caller
already declared an `s32` return. Both native return sequences mask RGB to
24 bits, shift the alpha byte with a sign-extending 32-bit operation, then OR
the values. A symbolic bit proof verifies that all upper 32 result bits equal
bit 31 for arbitrary input colors. The provider's real guarded definition now
returns `s32`; its packing expressions use unsigned masks and shifts, avoiding
the old signed-left-shift overflow. Frame and duration parameters remain
signed, as established by the provider's comparisons and conversions.

Two owner-local declarations in `code1_004a.c` and the declaration in
`effModel.c` now agree with the provider's pointer and signed frame types.
Prime explicitly released the one-line `effModel.c` correction. Its active
object, the complete `code1_004a.c` object and the complete `code1_0048.c`
object are byte-identical to their respective baselines. Other caller owners
and shared headers were not edited.

The flare's RenderWare declarations now use the actual pointer-returning
material, frame and geometry contracts. The available canonical
`RpMaterialSetTexture` and `RwFrameGetLTM` symbols are used directly. Their
names and destinations were verified against the current providers and the
build's real resolvable-symbol set. No vendor implementation was changed.

## Native validation and retained receipts

All paths below are relative to
`build/continue-first-party-20260922/worker4-flare-contract-c438874-v1/`.

* `audit/source-callers.json`, `native-callers.json`, `return-contract.json`
  and `canonical-target-symbols.json` retain the source/native caller audit,
  both return proofs and the reviewed canonical providers.
* `official-before/official.json` reports 221 MATCH and 16 ASM across the four
  affected first-party owners. `source-final/official/official.json` reports
  222 MATCH and 15 ASM across the same 237 functions. Flare is the one new C
  MATCH; no third-party functions are included.
* `source-final/closure.json` binds all four final live source hashes to their
  native objects and compile receipts. `live-native/` contains fresh native
  compiles of all four integrated owners; `source-final/mdlEffect/` recompiles
  the final model comments and proves the entire object unchanged.
* `source-final/resolved/func_004a6e70.json` and `func_0048a460.json` prove the
  final flare and the preserved projection without relocation masking.
  `live-native/resolved/` also proves the actual provider fallback and the
  affected `0048b220`, `004ad030`, `004adb50` and `004ac300` callers.
* `live-native/provider-guarded/` contains a fresh compile of the actual
  current owner with only the provider's C guard activated. It has the real
  `s32` definition and unsigned packing, 1,036/1,056 bytes and 111 alignment
  edits; its full guarded object equals the prepared guarded object.
  This is a source-bound C-contract check, **not a provider C match**. The
  inherited provider reconstruction remains NONMATCHING and uses ASM in the
  production build.
* `checks/link-eligibility.json` shows all four owners eligible both before
  and after the change. `source-final/checks/lint.json` has zero errors and
  one inherited H003 advisory at `code1_004a.c`'s wind initializer pragma.
  That pragma and its code are unchanged; its prior measurements remain in
  the owner and wind archive. There are no new lint findings. The scoped
  final `git diff --check` passes.

The initial model source hash was
`85c7c2f285112adb5a7de4de13b4a3832b191fd2a28efd9b4aef70d7a394ebc8`.
The final model source hash is
`cd9555c2b07885904a98e40b06ac8cb4b1b21e149a503bfb6b44922931aa547b`;
its native object hash is
`345d1f161cbba2c1ddad2632450626f76279dd794b3a8b4c834855241d611eb9`.
The compiler hash is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

Integration completed in terminal session `91774`; fresh native/live closure
and scoped verification completed in `69206`; final model-comment/native
closure completed in `93916`. Historical destinations were not overwritten.
This pass makes no full-build, commit, push or whole-repository census claim.

Shake `func_004a7830` remains at the previously proven seven-word residual,
532/544 bytes. Its C body and fallback are unchanged by this recovery.
