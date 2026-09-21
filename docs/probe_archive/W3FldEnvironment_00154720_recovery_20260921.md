# Environment state selection: 00154720

The final assembly fallback is now accepted in live
`src/promoted/k_fldEnvironment.c`. Fresh live-source compilation and the official
verifier report **11 MATCH / 11 functions**, and decompilation lint reports
**zero findings**. The complete live proof resolves all seven code relocations
and all fourteen entries of the owned kind jump table. Combined with the
loader recovery and its mipmap dependency, all **17 functions MATCH**.

## Recovered behavior

The previous draft incorrectly grouped the default kind with kind 6, applying
the `state < 6` adjustment to both. The retail table at `00746c20` shows kind 5
and the out-of-range default enter the common condition/period mapping directly.
Only kind 6 performs that adjustment. The recovered switch uses this actual
control flow, including the original-state and adjusted-state early returns.

The optional field-event entry has a separate state-return lifetime. An inline
helper returns the incoming state when there is no entry and the entry's state
byte otherwise. This reproduces the retail forward null-fallback branch and
shared state return without artificial side effects or dead code. The main
function then handles the ordinary kind mapping and condition/period offsets
as separate phases. The `condition == 0` path retains the actual period range
checks rather than replacing them with a two-value switch.

Native contracts are taken from the actual providers: `func_001060c0` returns
`u8`; `func_00110960` returns `s64` and accepts `(s32, u32)`; `func_00106330`
(`datGetFlag`) returns `u32`; and `func_0015a0c0` returns an encoded `s32` address.
The existing wrapper explicitly narrows the actual wide selection result to
`s8`, preserving every wrapper instruction. The optional-entry helper explicitly
converts the native encoded address to its byte view. The already-correct
`func_0014a160(void)` return contract is preserved.

## Validation and artifacts

All scratch paths are beneath
`build/first-party-finish-20260920/field-current-work/`.

The accepted complete owner is `src/promoted/k_fldEnvironment.c` in the repository.
It is byte-identical to the retained
`environment-native-20260921/reviewed-native-environment-owner-proposal.c`.
Its immutable source, object, compiler log, receipt, disassembly alignment,
full relocation proof, fully resolved code and resolved table are under
`environment-native-20260921/func_00154720/reviewed-native-environment-owner/`.
`official-verify.json` records 11 MATCH, and `official-lint.json` records no
findings. `profile.json`, `inputs/`, and `provider-evidence/` preserve the native
providers, complete retail assembly, IDA/Ghidra references and compiler inputs.
`retail-kind-table.json` records every kind-to-arm mapping.

`field-exact-integration-20260921/` combines this owner with the separately
proved field-loader recovery and its mipmap parent-parameter dependency. It
contains three reviewed owner files, their originals under `base/`, a unified
`recovery.patch`, and a hash manifest. The package checks current owner and
header hashes. This original package remains immutable after integration.

`live-field-integration-20260921/` contains the fresh before/staged/live source,
object and log captures. The accepted live proof is
`k_fldEnvironment/live/integration-proof.json`; the fully resolved code and
owned table are retained beside it. `live-manifest.json`, `live-verify.json`,
`live-decomp_lint.json`, `input-hashes.json` and `integration.patch` seal the
three live owners, official checks, current inputs and applied changes.
`resume_live_20260921.py` requires each recorded starting hash before mutation
and rechecks source and input hashes after the live proofs.

The target emits **1008 bytes in its 1008-byte window**, with **zero unmasked
relocated differences** and no suffix. All **ten** siblings retain identical
code and canonical relocations. The original owner has no allocated data; the
new owner has exactly the **56-byte** kind table. Every entry is an absolute
relocation to this function, and its fully relocated bytes match the retail
table. The proof maps the compiler's private table symbol to `00746c20` only
after verifying its exact size, contents and exclusive ownership. There are no
extra functions or other allocated data.

Original source SHA-256:
`39c7cda2645c83d7860fee1599075fe1bd1bf86eab464462a9a2a90fb925d32c`.
Accepted live source SHA-256 (identical to the saved proposal):
`54116f004e9bd39e9fc4f1b31a30be9eca5087551156846ddd554f6cbf8f70cb`.
Object SHA-256:
`653878c95ce67010341edcdef364141920fbab3cffe68e05236226b2a476f356`.
Resolved target SHA-256:
`c38f7408f0c3580719ea4538fb8e41a3bc5e63e2c32b4aea010466a2e87eeccc`.
Configured b210 compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

The loader, environment and bounded mipmap dependency were integrated. The protected
`k_fldUnit.c` owner remains at
`598680b18cba35486dd273bdd389cee190eac2b21bee83ec508213126d744219`.
Its two measured remaining frontiers and forty exact C functions are unchanged.
