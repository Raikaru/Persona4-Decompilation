# RenderWare sky2 driver: reference data

Persona 4 links RenderWare 3.7 as prebuilt vendor libraries. The 3.7.0.2
source release used to reconstruct the rest of RenderWare contains no PS2
driver: only `core/driver/{common,d3d8,d3d9,null,stub}` and `core/os/win`.
The sky2 driver therefore has no reference source. Its functions include
the 300 listings in `asm/nonmatchings/rwcore_grouped` and much of
`code1_0039`–`code1_003e`.

This directory holds the data from two games with symbols that were used to
name and place that code. Nothing here is written into `src/` automatically.

| file | contents | trust |
|---|---|---|
| `known_names.json` | 392 Persona 4 address → RenderWare name pairs already proven by `src/renderware/**` markers, P3 names and alias defines | ground truth for scoring |
| `burnout_link_map.json` | 533 RenderWare archive members from Burnout Revenge's `B4EXTERN.MAP`, with functions, addresses and sizes in link order | exact copy of the map |
| `proposed_names.json` | 122 Burnout-derived proposals for unnamed functions | weak hints |
| `ballers_names.json` | 417 Ballers-derived proposals with confidence, evidence, source file and Burnout agreement | stronger hints |
| `ballers_rw_units.json`, `ballers_sky2_units.json` | Ballers' RenderWare and sky2 functions grouped by compilation unit, from its DWARF 1 debug data | exact for Ballers; read by `tools/port_rw_names.py` |
| `ballers_structs.json` | 832 struct layouts from Ballers' DWARF, including game types | exact for Ballers' build |
| `rw_tu_map.json` | 381 Persona 4 address → RenderWare name and source unit entries | attribution input |
| `rw_unit_attribution.json` | owner unit for each of the 285 former RenderWare and skin-plugin grouped markers | inferred split (below) |
| [`name-transfer-report.md`](name-transfer-report.md) | Burnout structural-diff run: method, scores, failures, hand checks | historical measurement |
| [`REPORT.md`](REPORT.md) | Ballers structural-diff run and comparison with Burnout | historical measurement |

The names in `config/symbol_names.vendor.txt` come from a separate, stricter
method. `tools/port_rw_names.py` accepts a reference function only if it is
relocation-identical to the retail window. Its docstring describes the
method.

## The two reference games

**Burnout Revenge** (SLUS-212.42, July 2005) is Criterion's own game. It
shipped unstripped with 12,023 function symbols and a full linker map, and
it links `CodeSDKs\RW37\Graphics\rwsdk\lib\sky2\release\librwcore.a`, the
same library family as Persona 4. It was built with ee-gcc 2.95.3, while
Persona 4's RenderWare block uses MWCCPS2 3.0.1 b119
(`config/compiler_units.txt`). A masked-word fingerprint of every Burnout
RenderWare symbol found only 21 candidates in Persona 4, all trivial 4–9
word wrappers. `_rwFrameOpen` is 136 bytes in Burnout and 160 in Persona 4,
although both contain the same `ori …, 0xe` that completes `0x4000E`. Burnout
supports structural matching only, not byte matching.

**NBA Ballers: Phenom** (SLUS-21186) compiled RenderWare from source with
`MW MIPS C Compiler`, the same Metrowerks family as Persona 4's block. Its
debug data names the sky2 source files. Structural matching transfers much
better from Ballers.

## How reliable the proposals are

Both proposal sets come from romwright's structural diff. They were scored
against `known_names.json` using greedy matching with semantic signatures:

| reference | correct / proposed on truth | precision | recall |
|---|---|---|---|
| Burnout | 93/143 | 0.650 | 0.368 |
| Ballers | 297/336 | 0.884 | 0.864 |
| Ballers, driver block only | 100/107 | 0.935 | 0.947 |

- Where both references propose the same name, 92/94 (0.979) are correct.
- Where they disagree, Ballers was right 31 of 42 times, Burnout once, and
  neither 10 times.
- Raising the Burnout score threshold does not help. In the run without
  semantic signatures, precision rose from 0.675 to 0.784 at score ≥ 0.95,
  then fell to 0.720 at ≥ 0.99, because tiny same-shaped functions receive
  overconfident matches.
- Common errors are swaps between sibling functions or overloads, such as
  Near/Far clip planes and Persp/Parallel view matrices. Tiny bodies are
  also unreliable.

Use a proposal as a first guess for a function you are already working on.
Before relying on it, disassemble both sides and compare control flow,
shared literals and callees, as the reports' hand checks do. In the Burnout
run, 8 of 11 hand-checked pairs were confirmed, 1 was weak and 2 were
rejected. In the Ballers run, 9 of 9 were confirmed.

## Burnout's link map

`burnout_link_map.json` is copied directly from the linker map. It lists the
sky2 driver's objects with every function name and size in link order:
`basky.obj` 54 functions, `texcache.obj` 23, `skyinst.obj` 22, `badma.obj`
20, `palquant.obj` 18, `skyblit.obj` 14, `skyconv.obj` 8, `baim3d.obj` 6,
`p2heap.obj` 5, `baskytran.obj` 5, `bapipe.obj` 4 and `p2core.obj` 4.

Persona 4's driver is where that order predicts. The unnamed gap
`003EFF30`–`00410930` contains 161 functions and `0x1FCBC` bytes. The
matching Burnout chain from `palquant` to `texcache` is `0x1F6BC` bytes.
Aligning functions one-to-one by order and size failed: only 14 of 161 were
within 10% in size. The order can identify the source file for a region, but
not the name of an individual function.

## Unit split

`rw_unit_attribution.json` places all 285 markers from the former RenderWare
and skin-plugin grouped sources. It has 147 Ballers name-to-CU attributions
and 138 placements based on neighbouring named functions, source APIs and
link order. Not every filename is recovered from the original build.

Some grouped files had misleading names:

- `rt2d_grouped.c` held RtAnim and UV-animation functions, not Rt2d. They
  moved to `rtanim.c` and `rpuvanim.c`.
- `src/rprandom/rprandom_grouped.c` held skin, clump, light, world-object and
  plugin-registry functions, not the random-number plugin. Its 40 entries now
  belong to six owners under `src/rw/`.
- `QueryIntrContext` is EE runtime code, so it moved to
  `src/sce/query_intr_context.c`.

The small user-data, world, animation and platform groups were merged into
their owners. Three late `0x0041fxxx` functions have no defensible narrower
attribution and stay in `src/rw/rwcore.c`. Each moved marker kept its
function body and compiler-control context. When the split landed, a scoped
verification of all 292 RW-region rows showed no change in status or
`normalized_diff`. `make build` checks both linked-image hashes.
