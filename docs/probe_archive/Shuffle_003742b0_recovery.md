# Shuffle archive loader: func_003742b0

The interrupted campaign's loading-state draft is recovered as ordinary C in
`src/Battle/btlShuffleDraw.c`. The current owner emits 852 executable bytes in
the 864-byte retail window. Every code relocation is applied before comparing
the bytes; the remaining twelve bytes are zero alignment. The assembly
fallback is removed only for this target.

## Source reconstruction

The function advances through archive loading, sprite readiness, and completed
states. Its first state copies nine archive entries, registers three sprite
entries, copies three further entries, and forwards the last entry to the
persona-resource loader. The archive index continues across all these phases.
The readiness state checks the three sprite handles before closing the archive.

The retail dispatch is a switch with deliberate fallthrough. Separate copy and
sprite indices retain the real live ranges; the two copy phases share the
returned source pointer. The sprite destination is computed before fetching
the archive entry and registering it, and the readiness call consumes the
actual slot value. Each copy loop increments its local index before the archive
index. These changes reconstruct the loads, stores, calls, and loop tails.

The structurally corrected source initially had 22 differing instruction words,
all involving the work pointer and archive index registers. A scoped
`opt_lifetimes on` closes those differences to zero. Its off control retains
22 words. The earlier incomplete skeleton did not respond the same way: the
control is effective after the slot and variable-lifetime reconstruction.
No instruction padding, extra state, volatile accesses, or assembly was added.

## Complete returned-handle contract

Retail `func_0046af60` returns the newly allocated sprite-loader node. Its former
C definition returned `void`, despite callers consuming that result. The
definition now returns the actual `node`, and `include/sdk_sprite_loader.h`
declares the same `u8 *(u32)` interface for all real source callers. The input
remains the existing 32-bit sprite-data address representation. Integer handle
fields use explicit pointer-to-address conversions; pointer fields retain the
pointer result.

The coordinated files are the shuffle owner, `src/Kernel/sdkSpr.c`,
`src/Battle/btlResultSimple.c`, `src/cldDayChange.c`,
`src/Event/Fcl/shdSprite.c`, `src/promoted/cmmScript.c`,
`src/promoted/itfMsgProcedure_Window.c`, and `src/promoted/k_fldLmap.c`.
The provider itself remains byte-identical. The archive readiness/destruction,
sprite readiness, and resource-loader declarations in the shuffle owner also
agree with their actual provider definitions. The native H_Cdvd names resolve
through their existing source markers and curated function addresses.

## Verification

All 198 other compiled functions across the eight changed owners preserve
their instruction bytes and relocation destinations. Existing allocated data
is unchanged. The affected guarded light-map caller was also enabled and
compiled separately; its complete object remains identical. This distinguishes
the guarded-source check from an unchanged assembly fallback.

The installed source was compiled again with the normal current-owner compiler
configuration. Each resulting complete object equals its reviewed proposal.
The ordinary official verifier over the eight owners and the archive provider
reports 224 functions: 206 MATCH and 18 ASM, with no unexpected status.
Scoped integrity lint reports zero errors; seven inherited optimization
advisories remain outside the new loader. Whitespace checks pass.

Evidence is retained under
`build/first-party-finish-20260920/sprite-loader/`: `proof.json`,
`reviewed-proof.json`, `current-proof.json`, `official-current.json`, immutable
before/proposed/reviewed sources and objects, and the separately enabled
guarded caller. The source-decision controls are under the adjacent
`shuffle-load/func_003742b0/` directory. Historical results were preserved,
including an intermediate proof that lacked native function-name resolution;
the final proofs bind those names to the real provider markers.

This note records the target and owner checks. The assembled campaign's full
image and publication gate is recorded separately.
