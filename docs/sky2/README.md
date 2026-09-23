# Naming the sky2 driver

Persona 4 links RenderWare 3.7 as prebuilt vendor libraries, and the 3.7.0.2
source release this tree reconstructs from ships no platform driver at all -
`core/driver/{common,d3d8,d3d9,null,stub}` and `core/os/win`, nothing else.
So the PS2 renderer has no source and no names: roughly 300 functions in
`asm/nonmatchings/rwcore_grouped` plus a large part of `code1_0039..003e`.

Burnout Revenge (SLUS-212.42, July 2005) is Criterion's own game, shipped
unstripped with 12023 function symbols and a full linker map, and it links
`CodeSDKs\RW37\Graphics\rwsdk\lib\sky2\release\librwcore.a` - the same
library family Persona 4 does. It is the reference these files came from.

## The bytes do not match, and cannot

Burnout's map links `gcc-lib/ee/2.95.3/libgcc.a`; Persona 4's RenderWare
block is MWCCPS2 3.0.1 b119 (`config/compiler_units.txt`). Same source,
different compiler. Measured: a masked-word fingerprint over every
RenderWare symbol in Burnout found 21 candidates in all of Persona 4, every
one a trivial 4-9 word wrapper. `_rwFrameOpen` is 136 bytes there and 160
here, while both still carry the same `ori …, 0xe` completing `0x4000E`.

That is why this is a structural-matching problem, not a byte-matching one.

## What is in here

| file | what it is | trust |
|---|---|---|
| `burnout_link_map.json` | 533 RenderWare archive members from `B4EXTERN.MAP`, each with its functions, addresses and sizes, in link order | **deterministic** - read out of the map |
| `known_names.json` | 392 Persona 4 address -> RenderWare name pairs this repo already proves, from `src/renderware/**` markers and alias defines | **proven** |
| `proposed_names.json` | 122 proposals for currently unnamed Persona 4 functions | **hints only, see below** |
| `name-transfer-report.md` | the full method, every configuration tried, and the failure analysis | - |
| `ballers_names.json` | 417 proposals from the NBA Ballers Phenom diff, each with confidence, evidence, source file, and Burnout agreement | **hints, stronger - see REPORT.md** |
| `REPORT.md` | the Ballers method, scores, Burnout comparison, and agreement analysis | - |

## The proposals are hints, not facts

They come from romwright's structural diff, scored against the 392 pairs the
repo already knows. Measured on that ground truth:

```
greedy + semantics   93/143 correct   precision 0.650   recall 0.368
greedy, no semantics 54/80  correct   precision 0.675   recall 0.206
```

Thresholding does not rescue it. Precision rises to 0.755 at score >= 0.90
and 0.784 at >= 0.95, then *falls* to 0.720 at >= 0.99, because the top bin
fills with overconfident matches between tiny same-shaped functions. About
one proposal in three is wrong, and the wrongness concentrates in small
bodies.

So nothing here is written into `src/`. Use a proposal as a starting guess
for a function you are already working on, and confirm it the way the report
confirms its own sample: disassemble both sides and check the control flow
and the shared literals. Eight of eleven hand-checked pairs survived that;
one was weak and two were rejected.

## The map is the part worth trusting

`burnout_link_map.json` is read straight out of the linker map, so it is not
a guess. It gives the sky2 driver's real composition - `basky.obj` 54
functions, `texcache.obj` 23, `skyinst.obj` 22, `badma.obj` 20,
`palquant.obj` 18, `skyblit.obj` 14, `skyconv.obj` 8, `baim3d.obj` 6,
`p2heap.obj` 5, `baskytran.obj` 5, `bapipe.obj` 4, `p2core.obj` 4 - with
every function's name and size, in link order.

Persona 4's driver sits where that order predicts: the unnamed gap
`003EFF30-00410930` is 161 functions and `0x1FCBC` bytes, against the
`palquant -> … -> texcache` chain's `0x1F6BC` in Burnout.

Do not over-read that. Naive 1:1 alignment by order and size was tried and
**rejected** - only 14 of 161 land within 10% on size, because the two
compilers disagree too much. The correspondence is good enough to say which
source file a region came from, and not good enough to name a function by
counting along it.

## A second reference: Ballers

NBA Ballers Phenom (SLUS-21186) compiled its RenderWare from source with
`MW MIPS C Compiler` - the same toolchain family as Persona 4's block - so
the structural diff transfers far better than Burnout's gcc-built one.
Measured on the same 392 pairs: greedy with semantics **297/336 correct,
precision 0.884, recall 0.864** (driver block 100/107 = 0.935), against
Burnout's 93/143 = 0.650 / 0.368. Where the two references independently
propose the same name, precision is 92/94 = 0.979; where they disagree,
Ballers is right 31 times out of 42 and Burnout once. `ballers_names.json`
carries per-entry agreement, and `REPORT.md` has the full numbers, the
failure analysis, and nine hand-checked pairs. Same rule as above: hints,
not `src/` edits.

## Residual translation-unit split

`rw_unit_attribution.json` now accounts for all 285 markers previously
held in the RenderWare and skin-plugin grouped sources: 147 Ballers
name-to-CU attributions and 138 additional placements.
`rt2d_grouped.c` held RtAnim and UV-animation functions, **not** Rt2d;
they now reside in `rtanim.c` and `rpuvanim.c`. Despite its name,
`src/rprandom/rprandom_grouped.c` held skin, clump, light, world-object
and plugin-registry functions, not the random-number plugin; those 40
entries now belong to six corresponding owners under `src/rw/`.
The small user-data, world, animation and platform groups were likewise
merged into their owners. `QueryIntrContext` is EE runtime code and moved
to `src/sce/query_intr_context.c`, rather than another RenderWare unit.

The residual placements use neighboring named functions, source APIs and
link order; they are not all recovered original filenames. Three late
`0x0041fxxx` functions have no defensible narrower attribution and remain
in `src/rw/rwcore.c`. Each moved marker retains its function body and
compiler-control context. Scoped verification reports all 292 RW-region
rows with unchanged status and `normalized_diff`; both linked image hashes
are checked separately by `make build`.
