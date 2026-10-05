# Camp display: guarded recovery at 0x001400f0

`src/promoted/code1_0014.c` now retains the recovered `coordinate_steps`
checkpoint under the existing `NON_MATCHING` guard. Its complete owning
translation unit produces **7168 bytes in a 7168-byte retail window**, with
**85 aligned instruction edits and 637 fully resolved differing words**.
This remains a guarded nonmatch and adds **zero production C matches**.
The default owner remains **124 MATCH / two ASM**, with an object identical
to the previous renderer integration.

The recovery was installed only after prime reviewed the private complete
owner and joint-guard proofs. A fresh compile of the actual installed source
and a fresh complete owner compile with both guards enabled confirm the
result. Neither opacity provider, either qsort comparator, nor the earlier
renderer guard was changed.

## Installed source and earlier evidence

| Artifact | SHA-256 |
| --- | --- |
| Owner before this recovery | `fe472719e3a947f9fe2c1d699bd426ad145efea851b828ee1812954800025e4b` |
| Installed owner | `23cd0461f660968b29901b0e4e452829b3a533cd88194ff8be94438e8171d438` |
| Fresh installed default owner object | `6a7ea051c49fe20425895f8b92bf5499ce22855ff30be21147abadbb7c1ac527` |
| Fresh installed owner with both guards enabled | `df9722767fb541d8e7ac913d3c5e0540df84fb9e1cf61de4a5872c305b752559` |
| Camp target body before relocation resolution | `8521eb6e2ab5a95217bb05df245361a19bbd2676a61a5f14b3e93fa8a33c8fff` |
| Camp target body after relocation resolution | `4cec670e4ec23c42798f5747bcfefe9dedb3d80887c858604b783f9fb3d0347f` |

`CampDisplay_001400f0_worker13_resume_20261005_receipt.json` is the portable
receipt for this installed source. It embeds the guarded C, the source
delta, per-function code hashes, resolved relocation records, owned data
records, residual words, provider evidence, and the source-hash bridge.
The core evidence can be inspected without the ignored worker scratch.

The predecessor is
`RenderQueue_00148280_worker1_20261005_receipt.json`. Its installed source
hash is exactly this recovery's starting hash, `fe472719...`. The predecessor
still describes that earlier integration point. This receipt explicitly
extends its evidence to `23cd0461...`: the fresh default object has the same
hash, the complete source regions of `func_00148280`, `func_00148000`, and
`func_00148140` are unchanged, and their fresh forced-guard code and resolved
hashes equal the predecessor's.

The renderer remains 5016 bytes in its 5024-byte window with 21 resolved
differing words. Both comparators remain 316 bytes in 320-byte windows with
zero resolved differences, including the accepted `const void *` contracts.
The source regions of `func_001427c0` and `func_00142bf0` are also unchanged.

## Recovered behavior and real call contracts

The old guarded draw code read packed eight-byte positions through addresses
of standalone four-byte locals. The recovery gives each position a complete
eight-byte object with float XY and packed views. Colors likewise use complete
four-byte objects. Radar storage uses the existing complete 64-byte vertex
type and initializes the screen-position and RGBA fields used by this path.
These are data objects required by the providers, not register-allocation
padding or uninitialized register keepers.

Unselected party names now use font style **6**, while selected names retain
style **8**, as in retail. The sprite and descriptor calls use their actual
providers' argument types and order. In particular, the final gauge draw
passes X, Y, and depth as coordinates, then byte RGBA, then the horizontal
scale from `work + 0x690` and the remaining scale/rotation fields. The old
guard mixed palette bytes and coordinates into those argument positions.

Radar opacity uses `fGpffff854c`, the float at `0x0076163c`, whose stored
value is approximately 0.3. Screen depth remains `D_008872F8[0]`. The recovery
keeps these separate and follows retail's coordinate evaluation, palette
reloads, and resource lifetimes. The first **4120 fully resolved bytes** of
the recovered target now agree with retail; the first differing word is at
target offset `0x1018`.

The SDK declaration is now
`RwBool RpSkyRenderStateSet(RpSkyRenderState, void *)`, matching
`include/rw/sky2/rwcore.h:5683-5747`. The actual provider is `0x003f6440` in
`src/rw/basky.c`, backed by
`asm/nonmatchings/rwcore_grouped/func_003f6440.s`. The receipt checks all 592
bytes of that listing against retail. States 2 and 3 use compact value bits;
states 4 and 5 dereference a real pointer. Success and failure return 1 and
0. All four camp calls resolve to that provider. The two calls in matching
`func_0014dd80` receive explicit `(void *)` value casts and keep identical
code and relocations.

The relevant independent references are the radar and gauge regions of
`docs/ida_headstart/src/promoted/code1_0014.c:352-445` and
`docs/ghidra_headstart/src/promoted/code1_0014.c:280-350`, checked against
the complete retail listing. Real provider definitions are in
`src/promoted/code1_0034.c:465-500`,
`src/promoted/code1_0036.c:1129-1160`, and
`src/promoted/nLine.c:420-464`. The active caller
`func_0013ffd0` in `src/promoted/code1_0013.c` passes the same work pointer
after its update callbacks. The decompiler pseudotypes are reference
material, not declarations used to justify incompatible calls.

## Complete owner validation

The preparation compiled complete baseline, enabled-camp, and proposed
default owners. It resolved all target symbols independently of candidate
instruction offsets, checked the direct provider sequence, and compared
every sibling and allocated data section. After installation,
`verify.verify_file` compiled the actual authoritative owner. A second fresh
compile used that exact installed source with only
`#define NON_MATCHING 1` prefixed, enabling both guarded functions together.

| Check | Result |
| --- | --- |
| Camp target size / retail window | 7168 / 7168 bytes |
| Masked differing bytes / words | 1874 / 626 |
| Fully resolved differing bytes / words | 1932 / 637 |
| Aligned instruction edits | 85 |
| Target relocation records | 58, all resolved |
| Nonzero retail tail | None |
| Siblings with camp enabled alone | All 125 unchanged |
| Existing matched C with both guards enabled | All 124 retain size and zero resolved difference |
| Earlier renderer guard | Same source, code, and resolved hash; 21 words remain |
| Allocated data sections | Seven, unchanged |
| Installed default classification | 124 MATCH / two ASM |
| Installed owner lint | Zero errors; the same 27 pre-existing warnings |

Joint compilation renumbers a few compiler-generated anonymous data symbols,
for example `@91` to `@263`. The initial strict symbol-name comparison exposed
this difference. The final check resolves the actual contents and owned
relocations against retail, proving the tables unchanged. Renumbering was
not used to skip a relocation or classify a function as matching.

The receipt preserves every differing target word. Aligned instruction edits
are a separate diagnostic from fixed-offset byte/word differences; 85 edits
does not mean only 85 words differ. Neither the default assembly fallback
nor the improved guarded C receives new matching credit.

## Remaining cause and bounded continuation

The largest residual is the radar-fill loop's invariant placement. Retail
holds the offset-table base, RGB constants, and conversion setup outside the
five-vertex loop while retaining the needed loop operations. The saved
global `opt_loop_invariants` variant also moves conversion work out of the
neighboring edge loop and changes the surrounding schedule. It is not the
installed checkpoint.

Two float-to-byte opacity arguments also acquire an extra byte-to-word mask
when passed to the real word-width providers. Changing those providers to
byte-width parameters is not a valid repair: both construct vertex alpha
from the full opacity word, and the saved width diagnostic breaks both
previously matching provider bodies. Their declarations and definitions
remain unchanged. Earlier promotion-pass, helper, and scope probes are
retained as diagnostics and were not restarted during this resume.

One new bounded probe captured the final gauge sprite in a local immediately
before drawing. It produced exactly the same target bytes and relocation
records as `coordinate_steps`, so it was not adopted. The final resource-load
schedule and padding remain part of the residual. Further work should
explain the radar loop's partial invariant movement and byte promotion using
faithful source lifetimes, while keeping the actual provider contracts.

## Reproduction and scope

The compiler remains the owner's pinned MWCCPS2 3.0.1 b210 with
`-O2 -Iinclude`; its hash and the retail identity are in the receipt. The
installed candidate can be measured through the existing owner-aware tool:

```text
build/venv/Scripts/python.exe tools/measure_guarded.py src/promoted/code1_0014.c func_001400f0 --save-candidate build/camp-display-candidate.c
```

Private preparation and installed validation are retained under
`build/worker-13/coordinate-proof-20261005/`, with scripts
`prepare_coordinate_guard_20261005.py`,
`install_coordinate_checkpoint_20261005.py`, and
`finalize_coordinate_receipt_20261005.py` in `build/worker-13/`. The installer
refuses to replay an already recorded installation. The finalizer checks
the actual source hash before reusing any existing verification output.

No shared header, compiler configuration, progress file, or full-tree build
was changed. Prime owns combined verification and git publication. This
receipt establishes the guarded recovery and owner checks; it does not
claim a complete-image link or runtime test.
