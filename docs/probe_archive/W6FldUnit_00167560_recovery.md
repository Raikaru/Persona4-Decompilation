# Nearby-unit collection: 00167560

Recovered on 2026-09-20 in `src/promoted/k_fldUnit.c`. The integrated owner
now contains **38 MATCH and 4 ASM** functions. The earlier guarded body and
its diagnostics are retained in the frozen input snapshot.

## Identities and exact proof

Complete-owner SHA-256 values:

```text
before 4be68043a5beb6b0394d70b7fbd120429ae259fecbce6cec1513fb71fe60830c
after  09849cdd779745eb3342aefc26a6a490b4a9da9b16f01b8bad068c962ae801d3
```

The actual current owner emits **1128 bytes** in the **1136-byte** retail
window. All **39 relocations are applied**, with **zero unmasked differing
words** and the remaining **8 bytes verified as retail zeros**. There is no
target-owned jump table or extra emitted helper. All **41 neighboring
functions**, their canonical relocations, and every allocated data section
are unchanged from the accepted 00164230 owner object.

```text
current object 12cf6b14ee8a1305526ab18557788c9814eb017f6df1452afff4d117f1d17380
resolved target 5e6a7e48a1aae8d15a1c8482499e12857eaeb76c65ee7526e99f047f55284801
retail ELF SHA-1 4eeec0360cf2715535d9f7e52eb69d786fb0158c
```

The configured owner compiler is MWCCPS2 3.0.1 b210, `-O2 -Iinclude`, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
The official current-owner verifier exited zero, reporting42 functions:
38 MATCH,4 ASM. Its JSON SHA-256 is
`fe1581a25cb9a93775f9dcb6077408dc9a2177f6895e58b22856aed1e4ea2318`.
The owner whitespace check also passed. No full-tree or full-image check was
performed by this worker.

## Reconstruction

The function collects nearby field units and objects into the two halves of
`D_007E8020`. The old guarded draft used floating-point locals to hold already
converted grid coordinates, passed the address of `D_007EFA00` instead of
the stored model, and incorrectly added the object's byte stride to its grid
lookup. Retail and both decompiler exports establish signed integer grid
coordinates, the loaded model pointer and the unshifted grid base.

The recovered source retains each readiness result and the model-slot address
across the two matrix queries. Source scopes retain the actual per-site unit
address calculations. The function's common-subexpression and propagation
settings are scoped with push/pop; all other functions keep their prior
settings. The two scan indices and counts have the lifetime ordering used by
retail. Negative range guards retain the upper-bound comparison operands.

The final instruction difference was in the second scan's floating-point
addition: assigning the sum back into the loaded coordinate commuted its
operands. Keeping `positionX` and `shiftedX` as separate values produces
`shiftedX = center + positionX` in the retail operand order. The grid center
and size are shared by the two coordinate conversions. These are ordinary
values used by the computation; there is no padding, volatile memory,
artificial state or assembly in the recovered body.

## Source ABI closure

The sole real caller is `k_fldEvent.c:func_001747d0`, with a matching
void(void) declaration and a retail call at00174804. It is unchanged.
The owner now declares the actual provider types: `void *(void *)` for
`mdlGetMatrix`/0047a2f0, `s32 *(void)` for the grid accessor00155280,
`Resrc *(u16)` for `MT_Scene_GetRes`/00145270, `void *(void *,s32,u32)` for
memset/0043f9c8, and `void(void *,s32)` for diagnostic0046d730. Existing
owner model callers load pointer slots directly. Byte-pointer casts only
provide the views needed by the callers' component accesses. No external
provider or caller source patch is required.

The complete evidence package is
`build/first-party-finish-20260920/field-worker6/continue-67560/`:
`proof.json`, `integration.patch`, `integration-before.c`,
`integration-after.c`, `current-owner.verify.json`, and
`func_00167560/current-integrated/audit.json`. `inputs/` and `closure/`
contain frozen source, retail assembly, IDA/Ghidra exports and ABI evidence.
The previous accepted owner object was reused as the baseline; successful
probe jobs were not recompiled to reconstruct history.
