# Battle/action recoveries, 2026-09-22

All three assigned functions are integrated as recovered C in
`src/promoted/code1_001f.c` and reported `MATCH` by the official scoped verifier.
The starting owner and its existing dirty changes were preserved in the lane's
`before.c`. The approved companion change in `src/promoted/code1_0020.c` makes
the radial-draw declaration, definition and callers agree on parameter order.

All evidence below is under
`build/first-party-resume-20260922/battle-action/` in the
`build/first-party-publish-latest` worktree. This lane started at HEAD
`5a1bcf7e889d9b1fb1560201d686669739014501`; it did not commit or publish changes.

| Function | Starting differing words | Final emitted / retail window | Retail zero suffix | Result |
| --- | ---: | ---: | ---: | --- |
| `func_001f3bb0` | 11 | 932 / 944 bytes | 12 bytes | MATCH |
| `func_001fbb50` | 13 | 1620 / 1632 bytes | 12 bytes | MATCH |
| `func_001f4e50` | 13 | 1876 / 1888 bytes | 12 bytes | MATCH |

The configured compiler was native MWCCPS2 b210 at
`D:\mwcps2-3.0.1b210-060308\mwccps2.exe`, with owner flags `-O2 -Iinclude`.
Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Each candidate retains its complete source, object, compiler log and input
identity. The original compiler/profile, provider implementations, retail ASM,
IDA/Ghidra output and archived probes were inspected before the changes.

## Resistance scan: `func_001f3bb0`

The original residual was the first resistance pass's node/index allocation.
Its second pass already had the required allocation. Separate declaration
scopes, native cursor addresses, predicate types and forward-loop spellings
left the 11-word residual or made it worse. Earlier typed-union phase probes
also failed to preserve a common scalar lifetime.

The successful representation keeps one `uintptr_t scanPosition`. During the
first pass it holds the element index, initialized to zero for each node.
During the second pass it holds a node address, initialized from the freshly
reloaded list head. Every use follows initialization for that phase. Pointer
values are explicitly converted to and from `uintptr_t`; no inactive union
member or fabricated state is read.

The native word alone produced 40 differing words because the result locals
still competed with the long-lived count and cursor. Moving both real message
results to function scope, before the count declaration, removed the entire
residual. Typed node fields at `0xA4`, `0xA64` and `0xA6C` and meaningful local
names preserved the exact result.

The original list head survives the metadata-flags traversal. The second
resistance pass reloads its head after the first pass's query callbacks. Both
query passes and their priority rules remain intact. All four unused integer
parameters retain the actual `D_0060AB20` callback contract.

The two owned eight-entry tables resolve exactly at `0x007471F0` and
`0x00747210`, including all 16 relocated entries. The decisive probes are
`after-action/001f3bb0/outer-results-before-count/` and
`after-action/001f3bb0/reviewed-typed-scan-nodes/`.

## Fade/draw state machine: `func_001fbb50`

The former function disabled propagation and common-subexpression
optimization to keep a render callback-table base live. That setting also
made both unsigned float-to-byte conversions use a destructive destination
register. The matched conversion precedent in `code1_0031.c` explained this
interaction.

The recovered function enables ordinary propagation and common-subexpression
optimization in its scoped pragma block. A `uintptr_t` holds the callback
table's address, and each call reloads the actual typed callback from that
address. This preserves the retail base lifetime while allowing both alpha
conversions to receive their retail temporaries. Pointer or single-field
struct versions under the same optimization settings did not do this.

Render state IDs use the existing `RwRenderState` enum, and saved state values
use `void *`. Reading the enum through its actual type is significant: a load
as `s32` followed by an enum conversion changed eight loop instructions.
The owner reuses `rw/plcore/barenderstate.h`; no RenderWare implementation was
edited. Set/get callbacks use `s32 (RwRenderState, void *)`, and the reviewed
`func_003f6440` contract is `s32 (s32, void *)`. Existing `func_001fb480` calls
were updated to the same types without changing its instructions.

The remaining three-word difference was the radial call's depth/color
evaluation order. The coordinated first-party contract is:

```c
void func_00204690(u8 *unused, f32 scaleX, f32 scaleY,
                   f32 depth, s32 color);
```

Both owners' declarations, the actual provider definition and both callers
were changed together. The independent floating-point and integer argument
registers remain unchanged. A fresh native comparison proved the entire
`code1_0020.c` object byte-for-byte identical: all 146 functions, relocations
and allocated data are preserved.

The two RGBA objects own all eight initialized bytes. The waiting-state
fallthrough, both unsigned conversion paths, callback reloads, state
save/restore loops and calls with unused return values are retained.
The decisive reviewed candidate is `001fbb50/reviewed-native-fade/`.
The companion proof is `radial-contract/proof.json`.

## Action message rows: `func_001f4e50`

The retail read site keeps a shared `sp + selectedIndex * 4` base, then
materializes the code and actor field addresses separately. Earlier pointer
forms derived the actor field from the code pointer or folded the field
offset directly into a load. The historical smaller word count obtained by
changing the signed actor guard merely canceled two instruction-size errors;
that spelling was not used.

Independent field bases produced the correct shared row base but folded both
address computations into `lh` instructions. Keeping each field's actual
address in `uintptr_t` preserved both `addiu` followed by `lh` at offset zero.
The selected byte offset stays live across the previous-code comparison.
The actor address is formed only after the selected raw code is recorded.

The final local storage is an array of 64 typed `{ s16 code; s16 actor; }`
rows. The row writes, signed actor guard, status-priority chain, duplicate
check and actor-specific message adjustments preserve their retail ordering.
The nine-entry owned table at `0x00747500` resolves exactly, including all
nine relocation targets.

The decisive probes are
`after-fade/001f4e50/independent-field-address-values-uintptr_t/` and
`after-fade/001f4e50/reviewed-typed-message-rows/`.

## Provider contracts and preservation checks

The final ABI review aligned three existing owner declarations with their
already recovered providers, using explicit conversions at the 15 affected
call sites:

| Callee | Provider contract |
| --- | --- |
| `func_002428f0` / `datCalcIsDead` | `u32 (s32 unit, s32 hpDelta)` |
| `func_00242930` / `datCalcIsLowHp` | `u32 (s32 unit)` |
| `func_002340c0` | `s32 (u8 *unit, s32 flags)` |

This correction preserves the entire production owner object byte for byte.
Enabling the existing guarded `func_001f14f0` candidate exposed three changed
sign-extension instructions after the unsigned return declaration. Explicit
`(s32)` result conversions preserve that candidate's prior signed boundaries;
its complete object and allocated data also remain unchanged. The guarded
candidate was not promoted or replaced. No provider implementation needed an
edit for these declaration corrections.

The combined original-to-final proof preserves all 155 other functions in
`code1_001f.c`, including canonical relocations. All pre-existing allocated
data are preserved as a multiset. The only additions are the three fully
proved owned tables: 32, 32 and 36 bytes. The final ABI correction is an
additional whole-object equality proof, so it preserves that combined result.

## Final receipts

The final official scope is the two affected first-party owners:

```text
python tools/verify.py src/promoted/code1_001f.c src/promoted/code1_0020.c --json <receipt>
304 first-party functions: 294 MATCH, 10 ASM
0 mismatches; 0 Sony SDK or other third-party functions scanned
```

The errors-only integrity lint on both owners completed with zero findings.
The 10 ASM functions are other functions in these owners; all three assigned
functions are MATCH.

| Evidence | Path under the lane root |
| --- | --- |
| Final official result and log | `final-abi/integration/official-scoped.json`, `official-scoped.log` |
| Final source identities and accepted target rows | `final-abi/integration/accepted.json` |
| Retained final native source/object linkage | `final-abi/integration/native-source-receipt.json`, `native-candidate/owner.o` |
| Full instruction/relocation/owned-data target proofs | `final-abi/integration/func_001f3bb0.proof.json`, `func_001fbb50.proof.json`, `func_001f4e50.proof.json` |
| Original-owner sibling and allocated-data preservation | `after-action/integration/full-proof.json` |
| Final ABI whole-owner equality | `final-abi/integration/whole-owner-proof.json` |
| Guarded caller preservation | `final-abi/guarded/func_001f14f0/signed-result/proof.json` |
| Companion owner equality and radial retail proof | `radial-contract/proof.json` |
| Integrity lint | `final-abi/integration/integrity-lint.json` |
| Final manifest and reviewable lane diff | `final-manifest.json`, `lane.diff` |

All target proofs resolve actual relocations and compare the complete emitted
instructions, owned data and retail suffix. Diagnostic relocation masking was
used only for probe alignment, never as acceptance evidence. The lane reused
the existing probe and proof helpers without rerunning completed historical
destinations or all-origin jobs. The retained integration receipts distinguish
completed native compiles from later gate continuations.
