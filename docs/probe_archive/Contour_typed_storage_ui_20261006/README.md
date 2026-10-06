# Contour rendering reconstruction

`src/promoted/code1_0026.c` retains `func_00267b20` as guarded C with its retail
ASM fallback. The proposed reconstruction replaces the synthetic stack-frame
overlay with complete contour-count and point-pointer tables, a complete clip
rectangle, packed backdrop color, initialized channel values, and vertex/color
workspaces. Typed loops copy the nineteen table words. Point origins are still
reloaded at the original rendering boundaries.

The local device callback declaration follows the SDK's boolean return and
`(RwRenderState, void *)` arguments. The sky-state setter also receives its real
pointer-valued second argument and boolean return. All uses in this owner,
including the other two guarded functions, use those contracts. No provider or
shared header is changed.

The contour improves from **175 to 31 fully resolved differing words** while
remaining **1796 bytes in an 1808-byte window**, with twelve zero tail bytes.
Its remaining differences consistently exchange saved registers `s0` and `s1`.
It is still non-exact C; **no guard is removed and no new match is claimed**.

## Verification

All 65 production functions, including the three ASM fallbacks, resolve to
retail bytes. Their 608 code references and all four allocated data sections
are checked. Production remains **62 C matches and 3 ASM**. Activating only the
contour preserves all 64 siblings and their resolved references. Enabling all
three guarded functions compiles successfully; the other two guarded bodies,
the 62 matched siblings, and allocated storage are unchanged before and after
the proposal.

The all-guards build already introduces an extra jump table. Its section
numbers consequently differ from the production build. The proof compares
that build before/after and resolves production and contour-only builds with
their own section identities. GP-relative literal loads are checked along with
ordinary GP-relative references, including signed displacement bounds.

Evidence comes from the complete retail function, its matched caller
`func_00267800`, the retained IDA and Ghidra guides, SDK render-state headers,
and prior contour experiments. New signed-count, typed-point, color-width and
RGB-lifetime probes do not remove the final register exchange. Declaring global
tables as complete objects lets the compiler use 128-bit copies; explicit word
loops retain retail's scalar copy behavior.

## Replay

`receipt.json` binds both source states, compiler, configuration, headers,
resolved function hashes and allocated data. `contour.patch` is the exact
reviewed change. The replay accepts either pinned source state and writes only
to a fresh build directory:

```text
python docs/probe_archive/Contour_typed_storage_ui_20261006/replay.py
python tools/verify.py src/promoted/code1_0026.c
python tools/measure_guarded.py src/promoted/code1_0026.c func_00267b20
```

While staged, run the same `replay.py` under
`build/finish-20261006/ui-worker4-contour-archive`. The source remains unchanged
until the exact reviewed patch is installed. Original measurements are retained
under `build/finish-20261006/ui-worker4/contour-owner-proof-v2`.
