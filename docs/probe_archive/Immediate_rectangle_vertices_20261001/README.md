# Immediate rectangle helper: real aligned vertex storage

## Bounded production correctness repair

Base: published 58553aa1b6ffd6d42c58f623d1d97677e00b1be3, including the earlier queued rectangle payload repair. This change concerns the separate immediate helper `src/promoted/code1_0045.c::func_0045d6e0`, directly used by the calendar renderer. It does not import an older guarded owner over published source.

The helper previously declared one float followed by 252 bytes, then cleared 256 bytes starting at that float and passed it as the output for four 64-byte vertices. It now owns a genuine 64-float array. Its explicit eight-byte gap is replaced by the SDK's actual 16-byte alignment requirement, so the C compiler supplies the needed alignment instead of a synthetic local byte member. The output begins at the same offset 32 after six saved state words; its extent 256 and following rectangle snapshot position are unchanged.

The same helper's state loop now uses actual Code45RenderState rows through state/val members and genuine saved[i]/saved[j] elements. This closes the former cross-member s32-pointer walk without changing callback order or read timing. All allocation, rendering, conditions and arithmetic remain ordinary C. No ABI, external signature or production marker changes.

The evidence is source and retail, not matching numbers alone: `include/rw/sky2/rwcore.h:525–576` defines each RwSky2DVertex as 64 bytes with a four-quadword alignment overlay; the actual func_0045ce40 writes four 16-float strides and the draw callback receives count 4. The immediate helper clears the full 64-float output before geometry construction, so even lanes not written by that provider start defined.

## Fresh preservation

All 60 owner functions preserve exact instruction bytes and every raw relocation in both production and all-guard compilations. All allocated sections and canonical bindings are identical. Fresh verification remains 60 MATCH, with zero lint errors and 20 inherited unrelated warnings. Target remains 432 bytes/frame 0x190, 18 reference records, SHA baaf4f4cdefca8c41992b9654ffe153a2f8da58ac6d2671cf3dd04c9022e0f90. No new matching function or count gain is claimed.

The first measured form retained the inherited 8-byte gap while replacing only the scalar-plus-tail extent. The selected form replaces that gap with actual SDK alignment; both emit the same target bytes and references. This was a source-supported alignment repair, not a declaration-order or register search.

## Remaining boundaries

The input still arrives through the inherited f32* transport and is copied through Code45Float4 before its word representation is passed to func_0045ce40. This output/state-storage repair does not claim that every immediate rectangle caller's effective types, the input transport family, or the generic RenderWare backend is now closed. The callback tables and graphics backend are controlled boundaries in native tests. The preceding queued helper has its own independent receipt and remains unchanged.

## Native verification

The final five-method native run passes in 17.257 seconds with zero skips. At each O0/O2 and under both ordinary and strict aliasing, it executes 2,304 actual-helper scenarios with controlled graphics boundaries and 6,075 separate actual-geometry scenarios using genuine integer and float arrays. All 21 independent runtime controls fail through ordinary CHECK exit 1 at both levels, with empty stderr. Compiler-evaluated assertions establish the real output member's extent/alignment and work offsets; a scalar-plus-padding control preserves total layout but fails the output-member-size assertion without execution.

The detailed [native receipt](native_contract.md) and machine-readable record bind exact source/test hashes, scenarios, callback timing, controls and qualifications. The actual helper/provider input cast is deliberately not exercised as if its type family were closed: that boundary is modeled by lawful byte copying, and the real geometry provider is tested separately with proper inputs.

## Reproduce

```sh
source /workspace/shared/p4-toolchain/env.sh
python docs/probe_archive/Immediate_rectangle_vertices_20261001/audit.py
python tools/verify.py src/promoted/code1_0045.c
python /workspace/shared/run_p4_qemu32_tests.py "$PWD" test_immediate_rectangle_contract
```

The complete owner proof compares directly with published 58553aa1. No raw compiler, ELF or object payload is committed. Independent review and full main-tree retail hash/C-membership gates remain required before publication. No push occurred.

## Full main integration

Exact reviewed source and tests were integrated on published main
`58553aa1b6ffd6d42c58f623d1d97677e00b1be3`. Both retail hashes pass with
604 C objects and 54 SDK objects. All 8,586 linked windows and the complete
linked report remain identical to that baseline. All five focused methods pass
without skips. The ordinary suite reports 869 tests with 39 capability skips
and no failures. Changed-file lint reports zero errors and 20 existing warnings.
No new matching function is claimed; the documented input/backend limitations
remain unchanged.
