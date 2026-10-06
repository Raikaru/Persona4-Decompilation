# Sprite extent arithmetic, worker 26, 2026-10-05

The guarded `func_0046b380` now converts both signed bounds to `u32` before
subtracting in its two private width/height helpers. The previous assignment
to a `u32` result happened after a signed subtraction and therefore did not
define overflowing differences. Retail uses nontrapping 32-bit `subu` at all
18 inlined extent sites. The unsigned subtraction preserves that word result.

This is a source-semantics correction and earns **zero new C matches**.
The final native complete-owner object is byte-identical to the previous
guard object. The default complete-owner object is also byte-identical.
Only four operand casts and their two-line explanation were installed.
The source remains guarded with its production assembly fallback.

## Final source-bound proof

`src/Kernel/sdkSpr.c` changed from
`6990c0b8a3d840bc2f93cec9cff23c2e52e86dab1520a3dd543ca27d36a6aa91`
to
`f39f05eed1906f13c87e5558a962a530218be3a3f2df38b842fb28ac0d1173bd`.

Fresh `verify.verify_file` calls compiled that physical owner in both modes.
Default verification is **15 MATCH / 1 ASM**. With `NON_MATCHING` enabled it
is **15 MATCH / 1 NONMATCHING**. Every sibling retains its bytes, size,
fully resolved references and zero suffix. The full storage proof retains
all allocated sections, sizes, alignment, content and six data relocations.
Default code has 117 resolved relocations; enabled code has 130.

The target remains **7840 / 7808 bytes**, a **32-byte overrun**, with
**1833 positional resolved differing words**, 5768 differing bytes and
830 resolved alignment edits. An empty suffix on an overlong function is
not window eligibility; the receipt explicitly marks this candidate
ineligible. No exact-match or complete-image/runtime result is claimed.

Scoped lint completed with zero errors and two unchanged H011 warnings:
`func_00455f70` and `func_004669d0` declarations. They are outside the edited
guard helpers. The scoped whitespace check passed.

## Completed hypotheses

All 28 retained worker-17 objects were authenticated before new work. No
old lifetime/type/packet/color sweep was rerun. Three new whole-owner inputs
were compiled, followed by the two physical-owner verification compiles.

| New hypothesis | Bytes | Resolved differing words | Alignment edits | Decision |
| --- | ---: | ---: | ---: | --- |
| Unsigned operands for the two extent differences | 7840 | 1833 | 830 | Installed with a source comment; entire object unchanged |
| Initialize planar Z immediately before the 3D consumer | 7844 | 1846 | 830 | Rejected; larger body |
| Also define UV decrements and other integer coordinate operations | 7840 | 1833 | 831 | Archived; swaps two loads at +0dac/+0db0 without closing the residual |

The broader coordinate profile exchanges `lh pivotY` and `lw topBorder`.
Those remaining word operations and their valid-range requirements are
recorded for later work. It was not installed. No register forcing,
volatile access, synthetic local storage or altered ABI was introduced.

## Provider and behavior constraints

The full retail target and both decompiler references were read, along with
the actual callers, loader, matrix/vector providers, attachment transformer,
and installed vertex dispatcher. The sprite record remains 0x80 bytes,
the containing raster table has 32 entries, and vertices have the SDK's
complete aligned 64-byte storage. The renderer still uses the initial
raster lookup to govern UV initialization while binding from the current
raster table across later calls. All existing UV guards and all four
explicit planar-Z stores remain in place.

The vector provider reads all three components. The separately owned
attachment transformer `0046a7f0` still leaves its own Z inputs unwritten;
this investigation changes neither that provider nor its contracts.
The primitive consumer copies all four vertex lanes. No claim is made
that the untouched lane values or all callback/runtime paths are defined.
Valid resources, readable records, suitable raster dimensions, and existing
finite/representable float conversions remain required. The two arithmetic
overflow examples in the receipt are mathematical witnesses, not observed
game assets or gameplay tests.

## Retained evidence

`receipt.json` contains complete default/native code and storage proofs,
source hashes, three reconstructible source recipes, the installed source
delta, actual-owner verifier rows, the 18 retail subtraction sites and
bounded arithmetic witnesses. `extent.patch` is the installed change.
Private complete sources, native objects, logs and scripts remain under
`build/resume-cos20999/sprite`. The old frozen input manifest is preserved;
the receipt adds the actual installed owner's new input binding.

The RenderQueue archive is separately complete at
`docs/probe_archive/RenderQueue_worker26_20261005`. Its eleven saved objects
were authenticated with no new compilation and the formation-header edit
was explicitly excluded from renderer dependencies. No other production
file, shared header, configuration, Git index or branch, global report or global job
was changed by this worker.

## Targeted boundary execution

The actual current and previous `sdkSpriteRight`/`sdkSpriteBottom` bodies
were extracted without edits and authenticated by SHA-256. A freestanding
wasm32 fixture preserves 32-bit pointer/word widths and complete typed
container, record and sample storage. Clang 17 compiled both profiles with
UBSan trap mode; Node 22.16 executed them in a separate Linux container.
An independent 64-bit oracle checks bounds, optional signed overrides,
six Q12 scales, pivots, borders, and both record indices.

The corrected helpers pass **24 ordinary checks and 960 extreme-bound
checks**. The previous helpers pass the same 24 ordinary checks. Independent
width `INT_MAX - (-1)` and height `INT_MIN - 1` negative controls each trap
in the previous signed subtraction; both corrected controls return the
expected floating-point bits. These are targeted helper executions, not
the complete renderer or a PS2 runtime test. The frozen owner remains
`f39f05eed1906f13c87e5558a962a530218be3a3f2df38b842fb28ac0d1173bd`.

The portable text proof includes `boundary_fixture.c`, `boundary_run.mjs`,
compiler flags, output hashes and execution results in `receipt.json`.
No additional matching probe was compiled. Authentication without compiling:

```text
build/venv/Scripts/python.exe -B docs/probe_archive/Sprite_worker26_20261005/replay_boundary.py --hashes-only
```

`--compile` runs a fresh isolated boundary fixture using an available clang
with wasm32 support and node; `--clang` and `--node` accept explicit tool paths.
It does not rebuild the matching owner or change production source.
