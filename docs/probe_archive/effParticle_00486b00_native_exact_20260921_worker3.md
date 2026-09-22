# Particle constructor 00486b00: native C recovery

`func_00486b00` is integrated in `src/promoted/effParticle.c`. Fresh compilation
of the actual source with configured MWCCPS2 b210 and `-O2 -Iinclude` emits
780 bytes matching every retail instruction after all 37 code relocations are
resolved. The remaining four bytes in the 784-byte window are zero alignment.
No source padding, assembly, VU intrinsic, volatile access or fake effect was
introduced.

The complete owner has 14 official C matches and three unchanged assembly
fallbacks. All 17 functions pass unmasked comparison. The 16 siblings retain
identical bytes and relocation identities. The original 32-byte switch table
is unchanged; the constructor's new 32-byte, eight-entry table at `00756840`
matches all retail destinations after its relocations are applied.

## Native source mechanism

The old E486 candidate represented the capacity as a pointer, used signed
products before its unsigned limit check, and initialized a link's type before
attaching it to the particle. The native body uses `u32` capacity and products,
preserving retail's low-word multiplication and unsigned 300-particle cap.
It attaches the new case-7 link before writing its type and reloads that link
before storing the back pointer, in retail order.

Those corrections produced a 41-word saved-register exchange. Declaring the
actual allocation result as `u8 *const particle` at initialization in its own
construction scope closed that exchange. Retail's particle pointer occupies
`s2`, while the capacity and later resource share `s3`. The pointer is never
reassigned in the function; the qualifier represents its actual lifetime.
Keep that scope and initialization together when editing this code.

The retained allocator address remains an EE address word, but each load uses
the actual `void *(*)(u32, u32)` function-pointer type. The final source does
not read a declared function pointer through an integer lvalue.

## Actual callback and provider closure

The sole aligned retail data reference to `00486b00` is at `007134c0`, the
constructor slot of entry 1 in the table at `00713480`, with a 64-byte stride.
`func_00484570` and the equivalent inlined sites in guarded `00484bb0` call
that slot as `s32 (*)(u8 *)`, storing the address result. The recovered target
therefore returns `(s32)particle` through the same callback type. It does not
introduce a pointer-return declaration incompatible with that caller.

The two resource resolvers `00484490` and `004844d0` have actual `s32(s32)`
definitions in `mdlEffect.c`. The particle owner's declarations and explicit
address conversions now agree. Its memory-fill declaration returns the
destination pointer with an unsigned size, matching the retail provider; its
allocation diagnostic declaration agrees with the already-integrated game
definition. No provider or caller source was modified in this recovery.

The unchanged caller and resolver objects were authenticated against the
completed checkpoint-81 receipts, then checked against retail without masks.
The existing `00484bb0` assembly fallback is identified as such in the proof
and contributes no C recovery. The full particle callback table row is saved.

## Evidence and identities

All evidence is under `build/first-party-focus-20260921/particle/`:

* `integrated/FINAL.json` records the actual-source verification and identities.
* `integrated/` retains the source, native object, compiler log/receipt,
  official statuses and all owner code/data proofs.
* `review-native/caller-provider-proof.json` records the callback table,
  caller and resolver proofs with their authenticated input receipts.
* `review-native/promote.patch` is the reviewed one-owner patch.
* `INVENTORY.json` and `evidence-inputs.json` record the preserved artifacts
  and supporting source/tool identities.

Final source SHA-256:
`390403566386f3f521b9eae0ee0abc87473e6a26f860512a5d1118e9df369748`.

Final object SHA-256:
`2e6d31dce48fd15d22daefe2e61851a8410b1492b63898f7d21d61e38f5a04a1`.

The initial exploration accidentally labeled verifier differing-byte counts
as words. Those historical receipts remain intact, with exact corrected word
counts in `initial-metric-correction.json`; the 41-byte residual was also
41 words. Later receipts carry `measurement_schema: 2`. All acceptance proofs
use complete resolved bytes and owned data, independently of that metric.

The earlier geometry and diagnostic sources remain sealed and unchanged.
No vendor, shared tool, configuration, full-build or global-test work was done.
