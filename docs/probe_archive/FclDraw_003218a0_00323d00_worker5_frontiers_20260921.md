# Current-input Fcl frontiers: 003218a0 and 00323d00

This worker produced **no new exact recovery**. The live source, headers,
configuration, tools and Git metadata were not changed. The experiments and
review diffs are nonmatching evidence, not patches to promote into production.

The strongest result is `func_00323d00`: **1,800 emitted instruction bytes in
the 1,808-byte retail window, with 29 differing words after applying every
relocation**. The other eight retail bytes are zero. Its remaining differences
are a three-way saved-register rotation. The instruction classes, operands
other than those registers, call sequence, branches, stack layout and length
agree with retail.

## Frozen owner and reproduction

All scratch paths below are relative to:

```text
build/next-wave-20260921/fcl-next/
```

`inputs/manifest.json` authenticates the complete logical owner, its nine
recursive headers, the configured compiler binary and profile, configuration
files, build/verification helpers, fallback assembly, function-window manifest,
target configuration and retail ELF. The snapshot includes the current
77-recovery owner and the scoped four-aligned `FclDrawPosition` contract.

```text
Frozen/live draw source:
24f17ba7449b660c4480e00d0d927c177733806d8b244511439e98c10f15abd2

Baseline draw object:
ec3d5971b1e73ac421d41ec3c8ae30c1899128c9eaf2b09a96b7925e22dc75de

Frozen manifest:
1c92f22b14d89f78b10feab2eb998310853e4def637d7c00021603cb6805f3ba

Compiler: D:/mwcps2-3.0.1b210-060308/mwccps2.exe
Compiler SHA-256:
286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7

Logical profile: -O2 -Iinclude
```

The actual compile redirects the include path to the frozen header tree.
Every successfully compiled candidate retains `candidate.c`, the complete
`y_fclCombineDraw.c`, `owner.o`, `compile.log`, `compile-receipt.json`, a real EE
decode/alignment, measurement and whole-owner sibling comparison. The harness
refuses to overwrite completed artifacts or reuse a mismatched receipt.

`sealed-frontiers/experiment-index.json` authenticates **100 successful
compilations and one recorded compiler failure**, including the baseline.
No compilation was performed during sealing:

```text
python -B -S build/next-wave-20260921/fcl-next/seal.py
```

The completed seal confirmed that the live owner and all nine live headers
still equaled the frozen inputs. It also rehashed the retail ELF. Read the
retained seal instead of rerunning completed compilation jobs.

## 00323d00: native values and constructor evaluation

Selected directory:

```text
nearby/func_00323d00/native-resource-value-captured-before-constructor/
```

```text
Complete candidate owner SHA-256:
77a877e529daeafded27bc4f674dda757328350d5fb071c9a5dbe5eba5c77e14
Object SHA-256:
43633af8574a3bd5de1d592efb83d79c727c4e7003f9d3054e0529b8cd3e86f4
Function-source SHA-256:
5bf86cca76944e7abba0d3e18c8873829a103e2410cdd66fcf1edab4941501bd
```

The whole retail assembly, IDA and Ghidra exports, current owner and actual
draw/list providers were inspected. The old draft had six byte-buffer color
temporaries and evaluated list lookups before position construction. Native
`FclDrawColor` return values and aggregate assignments restore the actual byte
copies; position construction now precedes those lookups. The first list's
signed-byte size is explicitly loaded at the native point. One short counter
is reused by all three loops, and alpha values are narrowed at their consumers.

The exact `00316470` source supplies the constant-position pattern: retain a
named `FclVec2 *`, then read `.x` and `.y`. This produces the six native
`lui/addiu` address pairs. Direct float-array reads rematerialized the two
addresses independently. The existing external declarations remain unchanged.
The five real retail data pairs were read and recorded in
`nearby/func_00323d00/native-anchor-data.json`.

The constructor lifetime matters independently of those addresses. The
logical resource ID is short, while the existing `002b6c30` placement interface
takes its value as `s64`. Retaining the two initialized consumer views in the
same assignment captures the required conversion before the opaque position
constructor:

```c
s16 resourceId;
s64 placementResource;

anchor = (FclVec2 *)D_00644290;
placementResource = (resourceId = (s16)(k + 0x2BB));
func_002b2970((u8 *)&position.bits,
    anchor->x + (f32)(k * 0x139), anchor->y);
func_002b6c30(placementResource, position.position, 140.0f, 0x41);
/* The later lookup and alpha calls consume resourceId. */
```

This excerpt explains the mechanism; the retained `candidate.c` is the exact
measured source. The constructor still returns `void`, all storage is
initialized, and no provider or header declaration changes are needed for
this candidate.

Separating the two assignments retains an extra conversion. Capturing the
resource only inside the placement call's first argument also reaches 1,800
bytes, but moves resource setup after the constructor. Neither is equivalent
to the selected instruction sequence. Inline position-result and label-operation
helpers did not improve the selected sequence.

| Milestone | Bytes | Masked differing words | EE alignment edits |
| --- | ---: | ---: | ---: |
| Frozen guarded draft | 2,252 | 504 | 614 |
| Native colors and retail lookup order | 1,836 | 355 | 127 |
| Shared counter, byte alpha views, aggregate anchor views | 1,812 | 198 | 71 |
| Named anchor selected before resource | 1,812 | 187 | 39 |
| Both resource views captured before constructor | 1,800 | 29 | 31 |

The last alignment count includes the two zero retail-tail words. Applying
all 57 relocations leaves precisely the same 29 differing instruction words;
the first `0x2D4` bytes are fully identical. Remaining allocation is:

| Retained value | Retail | Candidate |
| --- | --- | --- |
| `(1 - (s8)arg2) * 255` | `s4` | `s3` |
| `(s8)arg2 * 255` | `s3` | `s1` |
| Current label resource and captured placement value | `s1` | `s4` |

No binary register substitution or assembly steering was used. A subsequent
source patch to group those real retained values was blocked before execution
because the tool could not determine its safety status. That patch was not
applied, and those grouping variants were not compiled. This is a limitation
of that operation, not a claim that the workspace is read-only.

## 003218a0: retained constructor and loop evidence

Selected exploratory directory:

```text
experiments/wide-both-comparison-expressions/
```

This is **not an integration candidate**. It has 1,488 bytes against the
1,472-byte window, 219 differing masked words and 71 EE alignment edits. Full
relocation application gives 240 differing words. Its object SHA-256 is:

```text
9778b7c06d25d3c96cb34a7fdbcf39c5dbbfd438da562e7567c8a7f0706c9277
```

Native colors, all six final `0034ae50` lookups, alpha byte offset `+0x78`,
initialized position packets and the short-counter lifetimes are preserved.
The remaining differences include the text-X saved lifetime, the first cell
task's `sq/lq` storage, and inner-loop normalization. Pointer-result helpers,
position destination types and ordinary task-parameter reuse did not close
those differences.

This selected experiment also uses the previously investigated word-sized
`002b69f0` delay declaration. Its current provider/declaration closure has
not been performed here; that change must not be copied into live source on
the strength of this target score. The initial
`native-colors-packed-storage-current-delay` experiment retains the current
delay declaration and is separately available. No global `002b2970` return
migration was attempted in this run; prior regressions of that migration
remain disqualifying evidence.

## Preservation and handoff

`sealed-frontiers/seal.json` is the final identity and result index.
For both selected objects, every one of the **69 other owner functions**
preserves code and canonical relocation destinations, and allocated data is
unchanged. Full independent relocation/owned-data proofs also confirm the
protected `003212e0`, `00330060` and `0032fbc0` functions in each selected object.

Each selected target has a `*-resolved-residual.json`, resolved bytes,
`*-siblings.json`, `*-protected-proofs.json` and `*.review.diff` in
`sealed-frontiers/`. The diffs compare the frozen guarded owner with the
nonmatching scratch witness; they are for review and continued reconstruction,
not production promotion. The real EE decoder was used throughout.

All compilation sessions completed. A process query found no compiler process
whose command line belonged to `fcl-next`. This worker has no reliable view of
other worker families' process state. Prime owns integration and publication.
