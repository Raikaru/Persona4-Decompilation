# Renderer caller contracts

The local declarations in `src/promoted/code1_0014.c` now agree with their
already reconstructed providers. Model color and matrix accessors take and
return pointers. The model queue routine takes a byte pointer to its model,
and the attachment position routine receives a model pointer and float
coordinates. Call sites read pointer fields directly. The complete initial
position in `func_001459b0` is stored as three floats instead of integer float
bit patterns.

Provider evidence is in `src/mdlManager_grouped.c` (`mdlGetColor`,
`mdlGetMatrix`), `src/Graphics/Model/mdlManager.c` (`func_00479100`), and
`src/promoted/code1_004b.c` (`func_004b1250`). No provider or shared header
changed. Existing callbacks, resource reloads and position-copy lifetimes
remain visible in the renderer.

## Native proof

The complete owner was compiled before and after the changes, both with its
normal guards and with all guarded C bodies enabled. All 126 production
function bodies and their canonical relocations are unchanged. Resolving every
code reference and all seven allocated data sections against the configured
retail ELF gives identical bytes. The production result remains **124 C
matches and 2 ASM fallbacks**.

Enabling both guarded functions preserves every one of the 124 matched
siblings. Both guarded bodies and their canonical relocations are unchanged
by the caller corrections. `func_001400f0` remains 7168 bytes with 637 fully
resolved differing words. `func_00148280` remains 5016 bytes in its 5024-byte
window, with 21 fully resolved differing words and an eight-byte zero tail.
Neither guard was removed, and this change earns no additional C match credit.

The renderer differences still concern saved-register allocation in the two
final sorted attachment loops. New pointer contracts and unsigned attachment
indices do not alter that residual. A separately measured predicate accessor
discards the earlier slot pointer, but also folds an address calculation and
does not match. All those experiments remain in the UI scratch directory.

`receipt.json` binds source, compiler, configuration, headers, function hashes,
resolved residuals and data placement. `caller_contract.patch` contains the
installed change. `native_references.py` retains the section-aware relocation
and data proof implementation used for the measurements; `replay.py` compiles
both source states and independently resolves the resulting objects again.

## Replay

From the pinned source revision with the native compiler and retail executable
configured:

```text
python docs/probe_archive/RenderQueue_native_contracts_ui_20261006/replay.py
python tools/verify.py src/promoted/code1_0014.c
python tools/measure_guarded.py src/promoted/code1_0014.c func_00148280
```

The replay writes only to a fresh `build/ui-renderer-replay-*` directory. The
original full-owner measurements and per-reference results are retained in
`build/finish-20261006/ui-worker4/renderer-native-proof-v2`.
