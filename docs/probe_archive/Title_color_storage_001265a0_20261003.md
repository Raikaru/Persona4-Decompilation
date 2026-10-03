# Largest title controller: first complete color-storage family

Base: `fc4998c071373cf09d27abe0ed7dc5c2e0bcd59e`.
Owner: `src/promoted/code1_0012.c`; guarded target: `001265a0`.
The 17,616-byte controller remains assembly-backed and `NON_MATCHING`.
This is a bounded semantic repair, not a recovered controller.

## Four actual objects, one byte alias

The retail first-family storage is:

- `sp+0x684..0x687`: `layerColorSource`; four bytes cleared, then byte 3 set to FF
- `sp+0x688..0x68B`: `layerColor`; one four-byte value copy of that source
- `sp+0x67C..0x67F`: `firstOverlaySource`; four bytes cleared
- `sp+0x680..0x683`: `firstOverlayColor`; an independent four-byte value copy

The old `sp687` scalar is the fourth byte of the source at 684, not a separate
local. No source object depends on adjacency to another local. Both old clear
loops advanced a four-byte pointer four times; each overran its scalar.
The old layer copy also numerically converted the inferred integer to float.

The replacement uses the existing, sibling-proven `TitleDrawColor` union and
`titleCopyValue` helper. Both clears advance `u8 *` by one for four iterations.
Union value assignment preserves the complete four-byte representation, not a
numeric interpretation of those bytes.

Retail `00126A48..00126A70` supplies the first byte loop. `00126A78` writes FF
to source+3. `00126A80/84` uses `lwc1/swc1` to copy four bytes to 688.
`00126AA4` and `00126ACC` pass the same 688 object, with no recopy between the
opaque calls. The intervening rectangle snapshot changes, but the color's
identity and lifetime remain intact. `00126AEC` calls the unchanged 00126090.
The later loop at `00126B00..00126B28` clears 67C; `00126B30/34` copies to
680 for the first overlay call at `00126B68`.

The hash-validating retail audit enumerates every direct stack access or
address materialization overlapping all four objects throughout the complete
controller. It checks overlapping wider accesses, not just exact offsets.
The ten census entries are in `retail-color-storage.json`. The audit also
verifies all 14 rectangle color source/copy pairs; only the first is repaired.
The three destinations at 6BC share an existing scratch object with other
providers and must not be split into independent locals in future work.

## Two canonical layer calls, with narrow scope

The actual matching provider in `src/promoted/code1_0045.c` is:

```
void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
```

Retail preserves a0 at `0045D6FC`, f12 at `0045D700`, and a2 at `0045D704`;
`0045D708..14` reads four f32 members from a1. Both selected calls pass color
688 in a0, rectangle 4C0 in a1, zero depth in f12 and state flag 1 in a2.
The old draft supplied integer `1, 0` through an old-style declaration.

A compatible declaration in the selected pair's inner block and arguments
`0.0f, 1` repair these two calls without changing the other 28 layer calls,
00126090, shared declarations, or matching siblings. No alternative ABI or
return value is invented. The first overlay retains the previously accepted
`titleRectangle` adapter and all eight of its canonical arguments.

`audit_candidate.py` checks the guarded whole-owner object: both loops emit
`sb` and +1, both copies emit raw `lwc1/swc1`, the alpha write targets byte 3,
no copied-color store occurs between the two layer calls, and both calls set
a0/a1, f12 and a2 correctly. The candidate's local offsets are 4B4/4B8 and
4AC/4B0; these are observations, not source layout assumptions.

## Native behavior coverage

`test_title_color_storage.py` extracts actual declarations, the two clear/copy
fragments, the scoped declaration, calls and existing helpers directly from
source. Each actual color declaration is a member of its own fixture-only
guarded object; macros address that member without rewriting the tested
statements. Canary arrays are test instrumentation, not production padding.
The unrelated s128 rectangle snapshots use a 16-byte native vector storage
substitute because i386 lacks a 128-bit integer scalar; only copies are tested.

The two layer calls reach a boundary recorder with the provider's real
signature. It checks full colors, rectangle snapshots, depth, state flag,
source/copy independence and ordering. It can mutate the first copied color
and rectangle, proving that the second call observes the same color object
without recopying while receiving the second rectangle snapshot. This is
boundary-recording coverage, not execution of the layer renderer.

The overlay executes the actual unchanged `002aaf20` provider. Allocation-time
color mutation verifies its later byte copy; packet bounds, depth, flags,
complete color, dispatch and guard bytes are checked. Separate probes execute
the exact two extracted copy expressions across all byte channels and special
representations, including signed zero, quiet/signaling NaNs and infinities.

At each of `-O0` and `-O2`, **4,128 cases pass**, covering all 256 values of
each channel, eight extra bit patterns and four opaque-mutation modes.
Eleven negative controls fail at both optimization levels: each old wide
clear, a short clear, wrong alpha byte, numeric copy, short copy, wrong source,
source/destination alias, recopy between opaque calls, wrong layer depth, and
wrong layer state flag. No skipped tests are accepted.

The existing all-call overlay suite also passes **30,720 cases per optimization**
and its five transport negative controls. Its extraction now recognizes the
new meaningful color identifier and includes the actual union declaration.

The unchanged 00126090 call, threshold branch, subsequent callbacks and the
rest of the controller are explicitly outside native fragment coverage. Their
retail order is recorded by the audit, not claimed as an end-to-end execution.

## Whole-owner preservation and residual

- Production owner: **81 MATCH / 1 ASM**
- Unchanged layer-provider owner: **60 MATCH**; overlay-provider owner: **7 MATCH**
- All 82 production function streams, allocated sections and resolved
  allocated references are exactly unchanged
- All 81 guarded siblings preserve bytes, sizes and canonical references
- All 420 non-target allocated data bytes and their references are unchanged
- The target-owned 64-byte, 16-entry jump table changes with the guarded body;
  both before/after entries are recorded. All entries remain aligned/in-bounds,
  target the same function, keep case alias groups and keep the first four
  instructions at each case entry
- Lint: zero errors; the same 32 existing advisories (31 H011, one H003)

The guarded target changes from **17,180 bytes / 3,959 masked differing words**
to **17,184 bytes / 3,935 masked differing words**. Its frame remains 0x4D0
versus retail 0x6C0. These measurements are not a match or a size-band claim.
No full retail-image build, gameplay run, CI, upload or push is claimed here;
aggregate gates belong to later integration.

## Remaining work

Thirteen overlay clear/copy sites remain untyped, including the shared 6BC
object. Eleven later opaque-black source/copy pairs have analogous source+3
alpha aliases. Twenty-eight 0045D6E0 calls retain their existing old-style
transport defects; 00126090 and other old-style calls still need independent
ABI recovery. Wider rectangle/vector objects, numeric conversions, accumulator
placeholders and other uninitialized draft values remain. Keep the whole
controller guarded while repairing these proven contracts in bounded families.

## Reproduction

With the existing licensed toolchain and retail input configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_color_storage_001265a0_20261003/audit_retail.py
python docs/probe_archive/Title_color_storage_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_color_storage_001265a0_20261003/audit_candidate.py
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
python tools/decomp_lint.py src/promoted/code1_0012.c
python -m unittest discover -s tests -p 'test_title_*storage.py' -v
python -m unittest discover -s tests -p test_title_overlay_contract.py -v
```

On this host, the external QEMU native32 adapter ran both test modules without
skips, preserving the repository compiler flags and sanitizer traps. Its
machine-local executable path is normalized in the saved log. The capture
script compiles the exact Git baseline in scratch source files and leaves all
objects and detailed capture records under uncommitted `proof/title-color-owner`.
