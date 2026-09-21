# Field model replacement task: 001679d0

`src/promoted/k_fldUnit.c` now contains the recovered model replacement task.
Official verification reports **40 MATCH / 2 ASM** across its 42 functions.
The remaining assembly functions are `00162e10` and `00165be0`.

The replacement task retains the resource kind and its field address through
model teardown, then loads the native field and subfield identifiers in call
order. The readiness count and its Boolean test have separate lifetimes.
State zero uses the shared zero return; state one advances only after every
selected model is ready and then falls through to the completed state.

The scoped `opt_lifetimes on`, `opt_common_subs off`, and `opt_propagation off`
profile reproduces these lifetimes without additional operations or padding.
The three completed earlier recoveries, `00164230`, `00164880`, and `00167560`,
were already present in the input owner and were preserved.

## Current-owner proof

Evidence root:
`build/first-party-finish-20260920/field-current-work/replacement-integration-final/`.

- `func_001679d0/shared-callback-header/integration-proof.json`: zero unmasked
  relocated differences; 904 emitted bytes in the 912-byte retail window;
  eight zero suffix bytes; all 41 neighboring function bodies and canonical
  relocations preserved; allocated data unchanged; no extra functions.
- `proposal.c` and `live-confirmation.json`: the reviewed source and the
  byte-for-byte live owner confirmation, with frozen header checks.
- `verify.json`: official 40 MATCH / 2 ASM result.
- `lint.json`: no errors; one existing volatile warning and five measured
  optimization-profile warnings, including the replacement task's scope.
- `inputs/`, `profile.json`, and `integration-evidence/`: frozen headers,
  compiler profile, actual provider sources, retail assembly, symbol inputs,
  verification tools, and prime's live callback-package proof.

Current owner SHA-256:
`598680b18cba35486dd273bdd389cee190eac2b21bee83ec508213126d744219`.

Object SHA-256:
`8c35d5db7548d91eecf75414a162b0f4b6d6b46bbac06024bfd5e66688c3cdaa`.

Resolved target SHA-256:
`516ee16c5c01151770da844ec10c1bb02664c4914a82c7be7be3b02656bef932`.

The compiler is the configured MWCCPS2 b210 at `-O2 -Iinclude`; the proof
substitutes an exact frozen include directory. Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Native dependency closure

The field owner includes `model_callbacks_internal.h` and
`model_matrix_internal.h`. The setup call passes its actual model pointer to
`void func_0047d140(void *)`; the registered setup callback has the native
`s32 (*)(void *)` contract. Model readiness and layer operations use the actual
pointer parameters consistently across this owner.

Prime integrated the callback slot, registration, provider, and external
caller fixes. Their proof is under
`build/first-party-finish-20260920/model-callback-closure/typed-registration/current/`.
The field matrix-header cutover independently preserved all 42 input functions
and allocated data; its evidence is in `field-current-work/matrix-integration/`.

## Continued work

The constructor's six-word frontier remains in
`field-current-work/constructor/func_00165be0/saved-order-loaded-file-unsigned-owner/`.
Its 964 emitted bytes have a 12-byte zero suffix, with full neighbor and data
preservation. Only the selection mode and record-pointer registers differ.

The initialization callback's initial six-word frontier required further
native-call auditing. The actual provider signatures introduce an additional
resource-kind conversion and expose three neighbor argument-lifetime changes;
these candidates remain scratch work. The native campaign records those
differences instead of treating the earlier incompatible declarations as a
completed recovery.
