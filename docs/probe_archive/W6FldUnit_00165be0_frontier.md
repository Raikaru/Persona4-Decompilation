# 00165be0: resource ownership and remaining lifetime differences

This 2026-09-20 continuation starts from the accepted 37-MATCH, 5-ASM
`k_fldUnit.c` owner, SHA-256
`4be68043a5beb6b0394d70b7fbd120429ae259fecbce6cec1513fb71fe60830c`.
No 00165be0 production edit was installed. The function remains ASM.

The previous guarded body does not describe all retail behavior. The readiness
and completion loops use the small owner arrays `D_007643C8[2]` (model
handles, gp-0x4D28) and `D_007643C0[2]` (loaded files, gp-0x4D30).
`D_007E8BE0` is a different array of 16-byte selection records; it is still
the correct base for the selection loop, and `D_007E8BE8[0]` is the selected
node override. The completion arm must copy the file's +0x118 size to the
instance's +0x28C and call `0044EA90(D_005F1500, 0x990)` before allocation.
The model template comes from `iGpffffb274`, not `D_007E8BE0 - 0x5C`.
These distinctions are confirmed by retail, both decompiler exports, and the
owner's producer functions 001658b0 and 00165b00.

The corrected candidate preserves the two initial 0014a200 calls, the
redundant count-zero diagnostic, signed count parity, unsigned random
remainder, selected-node walk, both completion iterations, file data copy
and release, model scale/rotation/translation, callback creation and handle
clear. The native random API is `RwUInt32 RpRandom(void)` in
`include/rw/inc/rprandom.h:54`, mapped to 003b7060. The legacy u64 provider
declaration is not the API contract. Prime owns that provider correction.

`build/first-party-finish-20260920/field-worker6/continue-65be0/` freezes the
owner, headers, compiler identity, retail assembly, IDA/Ghidra exports,
callers and providers. `actual-provider-contracts/` contains a complete
owner candidate using the audited provider declarations. It emits 964 bytes
in the 976-byte window, with a verified 12-byte zero suffix, **51 unmasked
differing words**, and 44 aligned edits. Its `audit.json` applies every
relocation and confirms all **41 other functions**, their canonical
relocations and all allocated data are unchanged; no helper function is
emitted. The prior accepted owner object was reused as the comparison
baseline rather than recompiled.

The untyped constructor-helper variant is 49 words; it is not the selected
ABI-complete candidate. Its lower number does not justify restoring legacy
declarations. Remaining differences in the typed candidate are the
selection loop's activity/record register assignment, the node/instance
saved-register swap, completion-helper early-exit layout, file-slot address
rematerialization, and memcpy argument-load order. Equal total byte length
does not close these differences: two extra helper-exit instructions offset
two missing address instructions.

The continuation measured distinct readiness/count/instance scopes, explicit
node-walk limits, genuine completion and selection helpers, promoted resource
IDs, a cursor value, pointer-owning arrays, loaded-file versus owning-slot
lifetimes and signed/unsigned element addressing. All candidates and compiler
receipts are retained. The focused propagation-off region retains the scan's
activity literal; whole-function common-subexpression disabling worsens the
body. No broad pragma search or artificial volatile/padding/state was used.

Before promotion, 0047a1a0's provider wrapper must also describe its actual
matrix/axis/float-angle/combine-op forwarding contract. Its current no-argument
source declaration merely preserves incoming registers. The continuation's
typed caller is based on the real retail call and forwarded matrix operation;
the external provider has not been edited by this worker.
