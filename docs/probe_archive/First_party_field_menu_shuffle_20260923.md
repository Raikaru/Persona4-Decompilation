# Field placement, battle command menu, and shuffle animation

Four additional first-party functions are recovered as C. The installed
source was checked by the official verifier using authenticated native
compiler outputs. All instruction fields and relocations were independently
resolved against the retail windows; omitted bytes are verified zero alignment.

| Function | Source owner | Executable / window bytes | Code relocations |
| --- | --- | ---: | ---: |
| `func_001587d0` | `src/promoted/code1_0015.c` | 4,596 / 4,608 | 110 |
| `func_00207b00` | `src/promoted/code1_0020.c` | 3,440 / 3,440 | 57 |
| `func_00384cc0` | `src/promoted/code1_0038.c` | 1,720 / 1,728 | 20 |
| `func_0038bab0` | `src/promoted/code1_0038.c` | 1,608 / 1,616 | 18 |

## Field placement and shared command contracts

`func_001587d0` uses the actual serialized placement records, grid coordinates,
resource templates, and complete three-component vectors. Grid addressing
preserves the original halfword coordinate views while world-coordinate
conversion keeps the full input words. The world-row displacement and template
scan are successive uses of the same real temporary, retaining retail's register
lifetimes without adding work or storage.

The coordinated `func_0014b510` declaration now returns `u16` from a word-sized
argument, matching its actual definition and consumers. Related resource
arguments retain their explicit halfword snapshots. The shared command header,
five field/resource/command source owners, and the unchanged script-header
consumer were all checked in their native owner contexts. Their unrelated
functions and allocated data remain unchanged.

The field source file is complete at **68 MATCH / 0 ASM**. The immutable
reviewed package is
`build/finish-first-party-20260922/continue-14-field/ready-vectors/`.
Its native source uses complete vector-object addresses rather than advancing
from an individual scalar member. The package supersedes the earlier `ready/`
proposal, which remains preserved for provenance.

## Battle command menu

`func_00207b00` acquires the render-state table at entry to the extended drawing
phase. Its inline strip operation receives the actual table object by value,
and the two state changes reload the mutable callback member around the draw.
Circle-center, animation-progress, and opacity values retain their separate
roles and conversion points. No new optimization directive is introduced.

The recovered callback follows the real dispatcher contract: selection pointer,
integer work address, and drawing-state pointer. Its 145 other owner functions
and all allocated data preserve their native bytes and relocation meanings.
The owner now has **144 MATCH / 2 ASM**; `func_00204dc0` and `func_00205ff0`
remain assembly-backed. The retained package is
`build/finish-first-party-20260922/continue-14-code20/ready-menu/`.

## Shuffle animation

`func_00384cc0` models the animation frame and flag fields as halfwords,
including the original increment-before-test wrapping behavior. Opacity is
converted at the byte boundary used by the drawing interfaces. Complete
two-component points preserve the shared mask and overlay geometry.

The external point table at `0x0064ecc0` contains thirteen eight-byte points.
Its selected accesses were checked against the saved retail data. The other
89 owner functions and allocated data are preserved. Its installed-source evidence is retained under
`build/finish-first-party-20260922/continue-14-shuffle/line-installed/`.

`func_0038bab0` animates the main strips and their detail panel. The complete
point stores the centered X coordinate before that coordinate is retained for
the second strip; both drawing calls consume the same two-component object.
Halfword frame increments, flag transitions, easing calls and the independent
detail-entry/detail-exit phases retain their retail execution order. Its 89
sibling functions and allocated data are unchanged. The installed owner now
has **80 MATCH / 10 ASM**. The current-source native object, official report and
unmasked proof are under `continue-15-integration/shuffle-detail/`.

Six newly referenced small-data constants are explicitly resolved in both
symbol registries. Their native GPREL16 relocations have zero addends, and each
address follows from the actual retail load displacement and GP `0x007690f0`.
This restores the complete shuffle owner's source-link eligibility. The audit
is recorded in `continue-15-integration/build-6542-inputs.json`.

## Installed-source verification

The four functions use configured MWCCPS2 3.0.1 b210 with `-O2 -Iinclude`.
The retained compiler SHA-256 is
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

`build/finish-first-party-20260922/continue-15-integration/checkpoint-6542.json`
binds the current source/header inputs, native objects, official reports,
unmasked target proofs, sibling comparisons, and lint result. Completed native
jobs were reused only after source, compiler, flag, and dependency authentication.
The current native first-party checkpoint is **6,542 MATCH / 318 ASM** over
the same 6,860-function audited scope. Remaining assembly functions are not
counted as recovered C, even when their fallback bytes are exact.

The existing full build completed successfully in `build-6542/`, with no source
drift. Both the recorded result and the retained executable passed the retail
hashes:

* Load image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`.
* Complete `SLUS_217.82` SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

All four newly recovered functions occur in the successful source-link report.
All 5,801 first-party function entries from the preceding published source-link
report remain present. Recovery counts and link participation are separate:
the new native C replaces previously included assembly without changing that
report's total function population.

The publication audit authenticated all 292 owners, repeated the four complete
native target proofs from their retained objects, and passed 62 current symbol,
marker and origin tests plus focused source integrity lint. It replayed no
completed compiler or full-build job. The source hashes, native proofs, output
hashes and source-link comparison are recorded in
`build/finish-first-party-20260922/continue-16-integration/publication-checked.json`.
