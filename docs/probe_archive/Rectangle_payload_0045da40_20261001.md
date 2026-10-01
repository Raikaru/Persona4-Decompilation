# Queued rectangle payload: bounded three-owner source repair

Base: `ed67deedad3f02060f4541df0233998c7557018c`, the SDK constructor
return-header projection on published `61b8a752`. This is an independent
minimal projection, not the guarded rank5 controller research rewrite.
No function changes matching status; there are **85 MATCH / 4 ASM** across
89 functions in the three owners.

## Recovered objects and contract

The sole active direct caller is Window helper `func_0027d660`; guarded
Window `func_0027f6f0` has two further calls. Shared
`primitive_rectangle_packet.h` closes all direct declarations and gives
these actual caller objects consistent types. It also declares the existing
queued callback with its actual two-pointer signature.

- Color is a real union containing a four-byte RGBA aggregate and the
  historical scalar float view. The helper clears a real color object and
  copies it, removing its old unrelated `u32 *` / `float *` alias.
- Rectangle inputs are real unions containing four-word aggregate transport
  and signed/unsigned views. No unrelated-object pointer casts or numeric
  integer-to-float conversions are used to copy these representations.
- The producer snapshots these complete aggregate views into a typed 28-byte
  packet: RGBA at +0, rectangle at +4, depth at +20, save-state at +24.
  The float aggregate is a representation transport, not four evaluated
  scalar floating computations. Allocation remains 28 bytes with hint
  `0x40000`; the hint is not asserted to be an alignment guarantee.
- The packet is copied to owned allocation storage before node allocation.
  Callback and work-pointer node slots remain +8 and +16. Source objects
  may change immediately after the diagnostic/allocation boundaries.
- The callback copies the packet's signed union **aggregate** view into a
  separate declared signed-word aggregate. Geometry receives that object's
  actual `s32[4]`, never a pointer escaped from an inactive union member.
- The callback has actual `f32 out[64]` backing for four 16-float-stride
  vertices. This replaces the inherited scalar-plus-252-byte pseudo-buffer,
  adding no padding. The other preexisting eight-byte local gap is unchanged.
  Named render-state fields replace the old `s32 *` / `p[1]` traversal.
- The local standard `memcpy` declaration now has its correct pointer return.
  All its existing call sites discard the result; bytes are unchanged.

Window's guarded controller only receives compatible local types and member
accesses at its existing producer calls. Its old numeric palette conversion
and ineffective `copyA` rectangle modifications are deliberately unchanged.
All guarded object bytes are identical. No reviewed rank5 control-flow or
172-edit checkpoint is imported here; its zero-choice gate remains separate.

## Measurements

Fresh whole-owner verification: 85 MATCH / 4 ASM. Production and all-guard
builds of Window (21 functions), SDK primitives (8), and code1_0045 (60)
produce **six entire objects byte-identical to baseline**. This includes
function bodies, allocated sections/data, local layouts, symbols, padding,
raw relocation addends and symbolic targets. Exact symbolic preservation of
unchanged assembly references is not a full-link resolution claim.

Separately resolving all references in the three edited matched bodies gives
exact retail bytes:

- `func_0045da40`: 256 bytes, 64 instructions, 10 references
- `func_0045d890`: 432 bytes, 108 instructions, 19 references
- `func_0027d660`: 416 bytes, 104 instructions, 13 references

Source hashes, six object hashes, exact resolved code hashes and evidence
hashes are bound in the adjacent JSON. The preservation and resolution tools
are `/workspace/shared/p4-rectangle-payload-preservation.py` and
`/workspace/shared/p4-rectangle-payload-retail-proof.py`. No cold full-image
build, linked C-membership proof, new MATCH or match-count change is claimed.

## Actual-body native proof

Run with the approved environment:

```
source /workspace/shared/p4-toolchain/env.sh
python /workspace/shared/run_p4_qemu32_tests.py "$PWD" \
  test_rectangle_payload_contract test_sdk_ot_state_contract
```

Eight test methods pass with no skips. The new fixture executes 17,670
scenarios at each of O0/O2: 16,200 direct safe-domain geometry pipelines,
1,350 helper pipelines, 96 arbitrary raw-word transport cases including
NaN-like representations, and 24 alternate active float-view cases. The
existing SDK suite adds 392 scenarios per optimization level.

Eight actual extracted bodies are compiled: helper, packet producer,
callback, geometry provider, camera getter, SDK append and both state-node
constructors. The packet/node/list storage comes from mmap without a declared
object type. An independent byte oracle checks snapshots, layout, allocation
hint/size, packet extent, node slots, old-tail linkage, state-node order,
depth, state save/restore and ownership after caller mutations. Geometry is
checked through index59 at the correct 16-float stride; untouched lanes are
never read by the oracle. The camera getter is its actual signed-address-word
body, not a fabricated pointer-returning substitute.

Twenty-six runtime controls use initialized, in-bounds wrong data, slots,
counts, states, copies, timing or queue destinations. They include moving the
color and rectangle snapshots after the mutation boundary. A wrong callback
declaration must fail compilation. Existing SDK controls add ten runtime and
two declaration cases. Sanitizers are supplementary; the source review, not
`-fno-strict-aliasing` or the sanitizer, establishes the bounded effective-type
argument.

## Explicit inherited boundaries

The generic ordering-table dispatcher still invokes callbacks through an
incompatible historical three-argument type. Native proof reads the stored
function pointer and invokes its actual two-argument signature directly.
It therefore does not establish end-to-end generic queue dispatch.

Platform rendering, render-state tables and allocation providers are
instrumented boundaries. In particular, the geometry body does not initialize
all 64 floats; this repair does not claim an arbitrary backend can read every
lane. Reciprocal/depth inputs stay valid, and signed coordinate additions
must not overflow. Arbitrary representation-only cases do not call geometry.

The immediate renderer `func_0045d6e0`, its nineteen caller owners, other
preexisting camera/append/state-table interface debt, and guarded-controller
semantic/domain issues are unchanged. Review found no new dependency on that
wider closure for this bounded payload repair. No broad renderer correctness
claim follows from this work.

## Rejected probes

A safe generic byte-copy implementation lost the producer's retail float
aggregate transfers (44 aligned edits). Scalar word-view conversion also
mismatched. A real rectangle union with separately assigned color channels
reduced this to eight normalized bytes but reordered byte loads. A compound
literal introduced an unnecessary temporary. The retained form uses actual
canonical caller unions and the natural RGBA aggregate assignment, preserving
all retail instructions without fabricated ABI, padding or undefined reads.
The initial union-array pointer escape was rejected and repaired with the
separate signed aggregate before retention.

## Current-main projection

The final isolated patch is based on published
`c6c82910d63538b3d8eb8e14b0b860f89eb09d53` (tree
`d93571905aaf06e7c9eb3a31ea866fa3185ddd39`). A complete tracked-tree
comparison against measured base `ed67deed` differs only in the two SDK
evidence documents' aggregate-validation additions. Every source, header,
configuration, build tool and native harness is identical. The six candidate
source/test hashes stayed identical when moved onto this current-main base.
Thus the existing owner/native proof applies to the exact projected sources;
no base-only rectangle API or guarded-controller rewrite is imported.

Lint reports zero errors and 49 warnings versus 51 on the source-identical
base. Only the two repaired incompatible declarations disappear; the remaining
findings are inherited (including the unrelated camera interface warning).

## Independent review

The frozen independent audit
`/workspace/shared/p4-rectangle-payload-independent-review.py` has SHA-256
`e46a44e9392714409eee7cedd4d1e2350c715046325bc059d95d8cdc358103dd`.
Its receipt at the adjacent `.json` path has SHA-256
`2c8ff2596ef9e4e9f090ca7d1fbc1042977ed24ae1f7aa95b88b864f579368ed`.
The reviewer independently executed all eight native methods, compared all six
complete existing owner objects, resolved the three edited retail bodies and
all 42 references, checked the complete two-document-only main-base delta, and
confirmed the lint delta. Source/test files and this bounded evidence scope
are accepted. Final commit identity is bound separately; aggregate integration
remains unclaimed.

## Full main integration

The exact reviewed source/header/test files were integrated on published main
`c6c82910d63538b3d8eb8e14b0b860f89eb09d53`. Both retail hashes pass with
604 C objects and 54 SDK objects. All 8,586 linked windows and the complete
linked report remain identical to that baseline. The focused rerun passes all
eight methods without skips. The ordinary suite reports 869 tests, 37 capability
skips and no failures. Changed-file lint reports zero errors and 49 warnings.
These aggregate checks do not remove the explicitly inherited dispatcher,
backend or guarded-controller limitations and claim no new matching function.
