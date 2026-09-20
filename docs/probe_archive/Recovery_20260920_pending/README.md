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

| Archived body | Saved result | Work required before production integration |
| --- | --- | --- |
| `001a4800.c` | 0 masked words; 1148/1152 bytes | Complete target relocation, sibling and data proof; reconcile the `001f3870` return and actual callers. |
| `001f3870.c` | 0 masked words; 112/112 bytes | Return the allocated packet through a coherent provider/caller contract. Its existing provider is already C, so this is not a new C recovery. |
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

The separate pending `00238940` proposal was already recovered as
`../DC_worker7_00238940_pending_abi.c`. It still needs the coordinated provider
width correction and complete owned-jump-table proof. The accepted guarded
`002411a0` improvement is in `src/Main/Battle/Data/datCalc.c` and retains its
assembly fallback at sixteen differing words.
