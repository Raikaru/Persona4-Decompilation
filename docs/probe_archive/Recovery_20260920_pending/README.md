# Pending worker recoveries preserved on September 20, 2026

These files are exact copies of saved worker C candidates recovered while
rebasing the accepted work onto upstream `9ed8ca6`. They are **not compiled by
the production build and are not additional accepted matches**. The original
translation units, compiler logs, objects, and detailed measurements remain in
the earlier local worktrees. `manifest.json` records each original path and
the hash of the C body preserved here. `inventory-review.md` accounts for the
accepted recoveries already upstream or retained in the recovery branch, and
for the unfinished work below.

The counts in this table are historical measurements from the saved compiler
runs, not new measurements of these bodies in the rebased source context.

The subsequent `0360227` recovery batch completed `001a4800` and its returned
`001f3870` packet contract, including the concrete callback types, all target
relocations and the complete switch table. See
[the accepted action recovery](../Recovered_Action_001a4800_20260920.md).
The original bodies below remain unchanged as historical inputs.

The `002e8410` initializer and its creator proposals now have a
[current-context implementation and proof record](../Fcl_initializer_002e8410_0360227/README.md)
against `0360227`. The staged initializer again resolves all 148 relocations
at 3256/3264 bytes, with paired creator and dispatcher changes. It remains
pending because the wider SDK callback contracts are not yet reconciled;
the original candidate bodies and their manifest hashes below remain unchanged.

| Archived body | Saved result | Disposition and remaining work |
| --- | --- | --- |
| `001a4800.c` | 0 masked words; 1148/1152 bytes | Completed in the subsequent batch: exact C, 39 resolved code relocations, complete 52-byte switch table, all neighbors preserved. |
| `001f3870.c` | 0 masked words; 112/112 bytes | Completed returned-packet/caller/callback contract, preserving exact bytes. The provider was already C, so this is not another C recovery. |
| `002e8410.c` | 0 words; saved target proof resolves 148 relocations, 3256/3264 bytes | Reconcile the creator returns, position/color aggregates, and SDK callback registration and dispatch; repeat the whole-owner proof. |
| `0034ad70.c` | 0 masked words; 220/224 bytes | Complete the SDK registration/callback contract along with the returned handle. |
| `0034b740.c` | 0 masked words; 204/208 bytes | Complete the SDK registration/callback contract along with the returned handle. |
| `002b5c90.c` | 0 masked words; 264/272 bytes | Complete the position-value and SDK registration/callback contracts along with the returned handle. |
| `0012d630.c` | 9 masked words; 1348/1360 bytes | Verify against current source and reconcile the UI provider/caller types. A separate five-word experiment changed already-matched providers and was not accepted. |
| `001d2e20.c` | 87 masked words; 440/448 bytes | Review the real position/rotation payload and all initialization paths. Current upstream independently reached the same word count, so this is not evidence of a further current improvement. |
| `0024be40.c` | 8 masked words; 672/672 bytes | Reconcile the inherited RNG return declaration and repeat the proof of the typed six-byte row and integer selector. |

The three SDK-dependent creator bodies are already-C functions in upstream.
Their saved zero-word return proposals do not prove that the callbacks are
called through compatible C types. The larger saved SDK proposal compared 74
active objects, but it did not finish that callback audit; those comparisons
alone are insufficient for accepting the migration. None of the callback
casts in these historical bodies is newly endorsed by this archive.

The initializer body depends on the types and declarations of its saved
owning translation unit, including `FclDrawColor`. The bodies are deliberately
preserved without adding invented declarations or silently changing source
forms. Do not paste a body into an unrelated context and assign it the saved
measurement. The two omitted zero-word candidates' C, translation-unit and
object hashes were independently checked during recovery; full hashes are in
the inventory report.

The separate `00238940` proposal now has an exact current-context body and a
complete owned-table proof in
`../DC_worker3_00238940_exact_pending_callers.c`. Its provider-width migration
still needs three existing caller contexts closed; the datScript caller is
already solved in the archived wide-provider proposal. The older
`../DC_worker7_00238940_pending_abi.c` remains a historical attempt.
`002411a0` is now accepted exact C, closing its sixteen-word register residual;
see `../DC_worker3_20260920_recoveries.md` for both results.
