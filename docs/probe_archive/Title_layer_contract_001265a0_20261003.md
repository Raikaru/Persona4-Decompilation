# Largest Title controller: complete layer-call argument transport

Public foundation: `862a8d1e00d9aa26086aef62bfabdc583e1b1851`.
Experimental base: `de43968228ce8c80c11ceccb6d19e1c9ff09f5fa`, which adds
unchanged cherry-picks of the independently reviewed overlay/color checkpoints
`fc4998c0` and `7107e766` to that public foundation. Those prior changes are
not new work in this checkpoint.

Only guarded `func_001265a0` changes. Its assembly fallback remains enabled.
No matching promotion, full-controller recovery, image gate or push is claimed.

## All thirty real calls

The provider at 0045D6E0 has the canonical definition:

```
void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
```

The previous checkpoint repaired two calls inside the first color family.
The remaining 28 still used an old-style s32 declaration and passed state and
raw depth bits as integers. In retail, the provider preserves color from a0,
depth from f12, state from a2, and copies four rectangle words through a1.
The old integer depth argument occupied a3 rather than establishing f12.

This checkpoint supplies the actual prototype for the guarded controller and
repairs the remaining 28 expressions. All thirty calls now pass color,
rectangle, float depth and integer state in that order. The previously repaired
two calls and their compatible inner declaration are unchanged.

The complete retail census has 28 calls at depth 0.0 and two at depth 10.0
(indices 22 and 25, addresses 00129554 and 00129768). Eight calls save/restore
render state; the other 22 do not. The 10.0 values are established by retail
LUI 0x4120 followed by MTC1 into f12, not a guessed numeric conversion.

`audit_calls.py` checks every retail and rebuilt call, not selected examples.
It resets register facts at every branch, jump and opaque call, so values are
never inferred from stale paths. It verifies a0/a1/a2/f12, no-op delay slots,
all shared color/rectangle identities, alignment and complete 4/16-byte object
extents. Different named inputs are disjoint; the shared sp6BC scratch object
remains one object throughout. The provider's actual prologue is pinned too.
No color initializer, byte-clear loop, copy lifetime, rectangle computation,
switch arm, provider definition or other controller is changed.

## Execute actual callers, layer provider and vertex provider

`test_title_layer_contract.py` extracts all thirty call expressions and their
actual color/rectangle declarations. The fixture also extracts the real
`func_0045d6e0` and `func_0045ce40` definitions and their relevant types.
It supplies known byte/word representations to each input object and executes
both full providers. Canaries independently surround each input.

At O0 and O2, 122,880 cases cover thirty sites and 4,096 input patterns:
all byte values in each color channel, signed rectangle origins, bounded
width/height, both observed depths, all observed state flags, two far-plane
values, and two inverse-scale inputs. Each of all 64 output vertex words is
checked, including x/y/z, color channels, inverse scale and zeroed fields.
The actual state loops must perform all six gets, seven setup sets, two Sky
settings, drawing and all six restores in order. Source inputs stay unchanged.

Camera lookup, state APIs and the draw callback are controlled boundaries.
The state table is synthetic test data with distinct values, not a substitute
production table. The real provider owner verifies unchanged separately.
The native harness's documented no-strict-aliasing mode supports the existing
provider's float-word snapshot and signed-word interpretation. This establishes
source transport/render-provider behavior for the admitted test domain, not
PS2 FPU emulation, actual renderer execution or gameplay.

Nine controls reject wrong zero depth, lost depth 10, lost state flag, wrong
color identity, wrong rectangle word, nonzero vertex clearing, missing state
restore, wrong depth calculation and missing alpha. The earlier color and
overlay suites also pass: **8 tests total, no runtime skips**. Their 4,128
color cases and 30,720 overlay cases per optimization remain unchanged.

These call-level tests do not certify the controller's preceding color or
rectangle preparation. Most old clear/copy families and other decompiler
expressions still need reconstruction. In particular, no native coverage of
00126090 or execution of the complete 001265a0 is added here.

## Preservation and measured nonmatch

Four fresh owner builds compare base/final production and guarded modes.
Production objects are byte-identical. All 81 guarded siblings are preserved,
as are 420 non-target allocated data bytes and every non-target reference.
The target's 16-entry jump table keeps its alias groups and first four
instructions at each destination; only target-relative offsets may move.
All three caller/provider owners verify **148 MATCH / 1 ASM**. Lint has
zero errors and 32 existing warnings.

The guarded target grows from 17,184 to 17,192 bytes against the 17,616-byte
retail window. Its 0x4D0 frame is unchanged; the fresh relocation-masked score
is 3,947 differing words, versus the preceding checkpoint's 3,935. These are
measured remaining differences, not matching progress credit. The canonical
arguments are supported by retail/provider evidence despite the worse score.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_layer_contract_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_layer_contract_001265a0_20261003/audit_calls.py
python docs/probe_archive/Title_layer_contract_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Omit the explicit runner only on a host with working direct i386 execution.
Skips are unverified, not passes. Local object/disassembly products remain
outside the committed source-only evidence.

## Independent-review event-order tightening

The test-only follow-up after 5f3ee529 requires interleaved get/set events,
followed by the extra setup set, both Sky settings, drawing and restoration.
The original fixture checked each get and set subsequence separately; an
otherwise identical get/set swap could pass it. The stronger cross-counter
checks and new get/set-swap control close that gap. No provider or controller
source is changed, and the admitted cases/oracle values are unchanged.
