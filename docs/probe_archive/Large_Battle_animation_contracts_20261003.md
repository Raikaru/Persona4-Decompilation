# Large battle controllers: animation and opening-call repair

Baseline: `f6a8c57a1485a869dc5dbd1cc27a2c5184996f1c`.
Owner: `src/promoted/code1_001a.c`.
Targets: guarded `001a59a0` (7,536-byte retail window) and `001a7720`
(17,536-byte retail window).

This is a bounded semantic/contract repair, **not two recovered functions**.
Both production `INCLUDE_ASM` fallbacks remain. No provider, shared header,
compiler setting, other owner's source, or unrelated guard was changed.
The source comments retain historical scores as historical measurements.

## Findings and repair

Both current baseline guarded bodies fail compilation, independently enabled
inside their complete owning translation unit:

- `001a59a0` supplies a fourth argument to `func_001991c0`, whose implemented
  contract is `s16 (u8 *, u16, f32)`
- `001a7720` supplies a pointer to the first formal of
  `func_00199d00(s32 unused, u8 *unit, s16 skill, s32 paired)`

The next problems are semantic, not compilation-only:

1. `001a59a0` represents a floating-point rate as the integer bits
   `0x3fe00000`/`0x3f800000`, and passes several integer `0x3f800000` constants
   through obsolete declarations. Retail `001a5a10..001a5a24` puts **1.75f or
   1.0f** in f20; timing/creation sites move that value into f12. The draft now
   declares a real f32 and uses real float constants
2. All 15 animation calls now use the already canonical declaration:
   `BtlPacket *btlUnitCreateAnimPacket(BtlUnit *, s16, u16, f32, u16)`.
   Both conflicting local declarations are removed. All unit byte views are
   converted to the declared unit view. Speed precedes mode in this canonical
   C signature; the EE integer registers remain a0/a1/a2/a3 with speed in f12
3. The six timing calls in `001a59a0` use the real signatures. The bogus
   extra `var_6` argument is removed from `001991c0`. The two `001999f0` calls
   pass `(unit, motion, rate, hit)`, preserving the unsigned-halfword next-hit
   conversion visible at `001a6d20..001a6d38`. Timing helpers return s16, so
   their undefined shift-by-48 wrappers are removed in both controllers
4. Opening call `001a83b4` supplies the real word loaded at unit+0xa0c,
   the unit pointer, signed skill and paired flag. The first formal remains
   unused in the unchanged provider. Its caller's result conversion is
   `(s16)`, matching the signed halfword extension at `001a83bc..001a83c0`.
   This preserves the actual word load; it does not invent a provider argument
5. Hit animation `001aa23c` is **lb**, not lbu. The corresponding source call
   now reads s8. This is material: -2, -3 and -4 select specialized animation
   creators, and -5 becomes -1 inside the actual factory

The unchanged factory at `00199ee0` preserves a2 for blend frames, f12 for
speed and a3 for mode. Its ordinary work record stores unit/id/blend/speed/mode
at +0/+4/+6/+8/+0xc, allocating 0x10 bytes. Its ordinary return is the packet
pointer; negative-ID branches return the specialized creator's packet pointer.
The current implementation is `src/Battle/btlUnit.c:btlUnitCreateAnimPacket`.

## Exact retail call census

The evidence script validates the retail ELF hash, checks every decisive
argument-setup word and call/delay slot, and proves there are exactly these
15 calls to `00199ee0` in the two complete target windows:

| Caller | Calls |
| --- | --- |
| `001a59a0` | `001a5e30`, `001a6534`, `001a6570`, `001a67a4` |
| `001a7720` | `001a7fe4`, `001a8444`, `001a8628`, `001a8854`, `001a8be0`, `001a8ebc`, `001a8f60`, `001a92b8`, `001a9300`, `001a9400`, `001aa250` |

The full word-aligned loadable-segment scan finds **44 direct animation-creator
calls in 20 canonical function windows**. The census is in the proof, rather
than inferred from guessed declarations. The opening selector has six direct
calls in four windows. Neither provider address occurs as an exact address-valued
word in the validated loadable segments; that census is recorded separately
from JAL instructions. This bounded patch does not
reconcile the remaining conflicting creator declarations in other owners.

Both reference corpora contain the controllers:
`docs/ida_headstart/src/promoted/code1_001a.c` and
`docs/ghidra_headstart/src/promoted/code1_001a.c`.
IDA shows the signed hit byte and halfword opening result but omits the float
formal in its guessed creator calls. Ghidra puts the float bits first. Neither
is used as the provider ABI authority; the live definition and retail register
setup establish the independent integer/FP argument counters.

## Verification

The audit compiles complete owner copies with configured MWCCPS2 b210 `-O2
-Iinclude`. It separately enables each target, then both simultaneously.
All three final guarded configurations compile. Both baseline single-target
configurations fail for the specific signature errors above.

| Final guarded target | Object / window bytes | Normalized differing bytes | Frame |
| --- | ---: | ---: | ---: |
| `001a59a0` | 7,640 / 7,536 | 5,542 | 0x410 versus retail 0x330 |
| `001a7720` | 17,540 / 17,536 | 12,829 | 0x6e0 versus retail 0x5b0 |

These are differing **bytes**, not instruction counts or accepted matches.
Both scores and frame sizes are the same when the guards are enabled together.
There is no meaningful before/after score for the current baseline, which does
not compile. No source shape was selected to reach a size band.

The default production owner object is **byte-identical** to the baseline,
including every section, symbol and relocation. The whole-owner verifier
retains **69 MATCH / 2 ASM**. Separate canonical byte/relocation comparisons
preserve all 70 non-target functions in each single-guard build and all 69
non-target functions when both are enabled. Lint reports zero errors, with
24 owner warnings (8 H003 and 16 H011). Unrelated declaration warnings remain.

The new eight-test contract suite executes at O0 and O2 with real i386 pointers,
UB/bounds traps and an explicit QEMU runner on this host:

- All 15 **verbatim extracted source call expressions** invoke the **actual unchanged
  animation factory**: 6,300 cases per optimization, including signed ID
  boundaries and specialized -2/-3/-4 returns, -5 normalization, frame/mode
  truncation, speed, returned packet identities and callback-slot identities
- Six mutation controls reject unsigned hit-byte loads, lost speed, wrong mode,
  unsigned ID dispatch, wrong blend frames and a missing special-ID branch.
  An incompatible wide creator declaration is rejected during compilation
- The exact opening-call assignment invokes the actual signed-opening
  providers in the existing 122,139-case fixture; wrong skill and paired
  argument mutations fail. A separate 65,536-value return conversion stress
  rejects unsigned result narrowing. The real selector returns only 0..3;
  stress values do not claim a wider gameplay result domain
- The six exact timing call expressions and actual rate-selection statement
  execute 2,160 recording-boundary cases per optimization. Integer-bit rates
  and the wrong next-hit argument fail. These boundary tests are separate from
  the existing actual-provider timing suite, which is also rerun

The existing motion-override and signed-opening suites also pass under the
same explicit runner. The default native-only run skips on this host because
it cannot directly execute i386 binaries; that skip is not counted as a pass.
No complete battle controller/gameplay execution is claimed.

No full image build or remote CI run is part of this scoped repair. Production
object identity proves this owner contributes the same link input as baseline;
it is not substituted for a fresh aggregate retail-hash gate after integration.

## Remaining reconstruction defects and next meaningful scope

The remaining defects are not a compiler-allocation floor:

- `001a59a0` explicitly truncates action UID and packet dependency UID through
  `(s64)(s32)`. Retail uses `ld` at `001a59dc`, `001a5e5c`, `001a685c`, and
  doubleword packet stores. Its `sp2C0` dependency local is also only s32
- The hit-record expression `temp_18 + (sp1D0 << 5)` scales a **s64 pointer**,
  giving a 0x100-byte stride. Retail `001a66f8..001a6700` adds the counter
  times **0x20 bytes**. The already-audited fixture hit view is in
  `tests/battle_approach_action_fixture.h`
- The timing clamp at `001a5d48..001a5d74` is a signed integer conversion and
  clamp to 25. The current draft keeps a floating local and assigns the
  subnormal float `3.5e-44f` on the clamp branch
- Both controllers pass scalar stack locals to buffer-writing providers:
  `00196040` writes an RwV3d, and `001f0a10` clears 0x20 bytes. The large
  controller also passes `&sp4F0` to the actual formatted-string producer
  `001d69f0`. Adjacent separately declared scalars are not valid output buffers
- Unrelated signed/oversized shift idioms, narrow packet dependency stores,
  and obsolete local provider declarations remain elsewhere in both bodies

The next high-leverage bounded reconstruction is an evidence-backed typed
local/action/hit view: preserve real 64-bit UIDs, use a 0x20-byte hit element,
and allocate real provider-sized result/vector/string objects. Start with
UID and hit-stride adversarial tests, then the first timing/clamp block.
Keep all fallback guards until complete-owner matching and semantic tests
justify removing one. Register/pragma grids are premature here.

## Retained evidence

[Verification and retail call census](Large_Battle_animation_contracts_20261003/verification.json)
retains the final source/test fingerprints, production object identity, guarded
measurements, preservation counts and precise register-setup observations. The
audit produces the full per-function preservation records and compiler logs.

## Reproduction

After configuring licensed tools and retail data, regenerate the fallbacks:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_animation_contracts_20261003/audit.py build/large-battle-contract/replay
python docs/probe_archive/Large_Battle_animation_contracts_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c --json build/large-battle-contract/verify.json
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit `--runner` on an x86 host that executes the native32 fixtures directly.
The runner script refuses to count skipped runtime tests as a complete pass.
The audit reads the pinned baseline from git without changing the checkout,
retains source/object fingerprints and precise diagnostics, and removes its
scratch source. Private retail input, fallback assembly, compiled objects and
verbose diffs stay under ignored local storage.
