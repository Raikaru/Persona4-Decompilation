# First-party continuation: 76 verified recoveries

The interrupted campaign was resumed in `build/first-party-publish-latest`
from commit `188437938339ae6f47b39445e5c4f2b59a211dff` and its existing
uncommitted work. Earlier worktrees and all saved candidates were preserved.
The initial recovery authenticated 410 saved compiler objects, checked their
input and compiler identities, and independently resolved all 71 C recoveries
then present relative to published checkpoint `0360227`.

## Five additional integrated functions

| Function | Executable / retail window | Resolved code relocations | Verified zero suffix |
| --- | ---: | ---: | ---: |
| `00169780` | 680 / 688 bytes | 8 | 8 bytes |
| `00161630` | 888 / 896 bytes | 19 | 8 bytes |
| `0017ed40` | 1868 / 1872 bytes | 7 | 4 bytes |
| `00205170` | 1116 / 1120 bytes | 17 | 4 bytes |
| `0026a020` | 6708 / 6720 bytes | 48 | 12 bytes |

These are native C definitions in their actual owners, with assembly fallbacks
removed only for the five named functions. The combined current-owner verifier
reports **6452 MATCH and 409 ASM out of 6861 first-party functions**. The whole
program report covers 13102 functions: 8222 MATCH and 4880 ASM. The function
map includes one additional first-party entry compared with the older
6860-function published checkpoint; the denominator was not reduced.

All 76 current recoveries relative to `0360227` pass separate, unmasked
relocation and owned-data proofs. For this combined run, 370 objects were
reused only after checking unchanged source, transitive headers, compiler and
profile; 40 owners were recompiled. All regenerated assembly files were checked
against the pinned corpus before that reuse. This is documented object reuse,
not a claim that every compiler invocation ran again.

### Sphere collision query

`00169780` now uses a complete collector/work structure, including its genuine
128-bit-aligned sphere input and copies. Expression reuse retains the staged
projection and signed post-normalization scale lifetime. The canonical memory
clear declaration returns `void *` and accepts an unsigned size, matching its
provider. All 15 neighboring functions, including the already-recovered
`00169320` and `00169a30`, retain their bytes, relocations and allocated data.
The complete owner reports 14 MATCH and 2 ASM before further query work.

The worker's detailed source and compiler discussion is retained in
`Field_next_wave_00169780_0016a110_20260921_worker1.md`. The independent dynamic
query improvement remains a guarded candidate, not an additional exact match.

### Encounter category and AI bounds

`00161630` keeps its four real signed-word arguments and calls the actual field,
room, date, time, flag and random-number providers. Its two weighted draws,
forced-category flags, sentinel result and packed result bits preserve retail
execution order. The native declaration was also restored in `k_fldUnit.c`
and `code1_0017.c`; both complete caller objects remain identical across their
119 functions. All five non-target encounter-owner functions remain unchanged.

The weighted selection requires a configured encounter table with a positive
category-weight total. Its returning diagnostic is not declared `noreturn`
and is not treated as a zero-weight guard. The raw `battle/ENCOUNT.TBL` loader
was inspected: it loads the mapping, rate and record sections without proving
their weights positive. That external game-data precondition is explicit;
the payload was not available for an exhaustive valid-configuration check.
No invented default weight or error-path return was added to obtain a match.

`0017ed40` performs the sixteen-sample AI bounds scan using complete native
line, position and hit objects. Its 16-byte cell snapshot is an actual
four-float structure, replacing a casted local array. The guarded parent
`0017f490` now declares the actual byte-pointer interface and explicitly
converts its work pointer. All 10 active neighbors retain their bytes and data;
enabling that parent separately preserves its entire 11-function object too.
The zeroed work allocator, initialization-before-query state transitions,
sample range and all 16 finite offset pairs were inspected independently.

### Battle skill row

`00205170` passes complete position and color value objects to the actual
skill-icon renderer, preserves the signed loaded skill ID and its narrowing
at provider boundaries, and keeps the numeric-label and opacity calculations
in their original order. The cost-type provider `0023dd90` returns `u16`
while retaining its real `s32` skill parameter. Its underlying table load is
still a byte load; this return type reproduces the caller's ABI conversions.

The actual `0010f560` wrapper now returns that value and takes an integer skill
ID. Its declaration and the other cost-type callers were reconciled in all
five affected owners. All 529 non-target functions preserve their instruction
bytes, relocation targets and data. The four provider/caller objects are
byte-identical, and a separately enabled `001e9950` guarded caller also retains
its complete object. This is one C promotion, not five additional matches.

### Scene update and queued operations

`0026a020` now represents the resource fields, interpolation temporaries and
24-byte animation queue as actual C data structures. The path evaluator's
float arguments and output buffers have one consistent declaration across its
provider and callers. The animation setter accepts its actual signed-word
integer arguments. The effect updater takes and forwards its real object
pointer; its callers include the shared `effect_update_internal.h` declaration.

The final footstep helper takes the sequence index and first-sound value in
their observed evaluation order. The recovered code preserves the original
load ordering, mode-dependent interpolation and queue processing. It adds
three compiler-owned 24-byte switch tables; all 72 table bytes and their
relocations are independently compared with retail, along with their layout.
The existing Event `00288170` and `00288af0` matches remain exact. The closure
checks preserve all 660 non-target functions across the 17 checked owners.

The associated `00287360` reconstruction is still guarded. Its corrected
Scene calls and packed records improve the saved alignment to 44 edits, but
the retail duration gate remains missing. No empty branch or synthetic
instruction padding was introduced to fill those twelve bytes.

The Scene owner's pre-existing discontinuous text ownership still prevents
whole-file C linkage. Its tables and contiguous runs are placeable, but the
linker previously crashed when the build attempted interleaved whole-owner
placements. Neither ownership nor the build's acceptance rule was changed to
turn this individual C recovery into a larger linked-coverage claim.

## Field-loader link closure

The completed 71-recovery build linked 174 C objects and 56 Sony SDK objects
and reproduced both retail hashes. Comparing its linked set exposed one
older owner regression: `k_fldData.c` referenced three names absent from the
link symbol map. The aliases are now present in both curated and recovered
symbol inputs:

| Symbol | Address | Retail reference |
| --- | --- | --- |
| `D_00762FC8` | `0x00762fc8` | Request-name references at `0015d788` through `0015da14` |
| `iGpffffb26c` | `0x0076435c` | Store at `0015da98`, load at `0015dd80` |
| `uGpffffb270` | `0x00764360` | Store at `0015da78` |

The actual current object and every reference were independently relocated.
Adding only these definitions changes the owner's eligibility from false to
true, with all three functions and all allocated data placeable. Its source
and object bytes are unchanged. A subsequent complete build must confirm the
resulting linked set; the earlier 174-object build predates these definitions.

## Evidence and reproduction

`build/next-wave-20260921/before/` preserves the interrupted worktree bytes and
patches. `integration-76/manifest.json` records each reviewed before/after hash;
`applied.json` proves that all 23 integrated files equal those proposals and
that unrelated verification inputs remain unchanged.

The combined verifier, compiler receipts, GCC receipts, input manifest,
object-reuse audit and unmasked proofs are in
`build/campaign-checkpoint/resumed-76/`. Reproduction from this exact state:

```text
python build/next-wave-20260921/resume.py verify --label <new-evidence-directory>
```

The target-specific closure records are under `build/next-wave-20260921/`:
`field/00169780/reviewed-sphere-native/`, `field-pair/`,
`battle/skill-cost-api-closure/final-release/`,
`event/release-closure-v3/`, and `field-data-symbols/proof.json`.
The independent field-pair review is in `event/field-pair-audit/`.

The preintegration complete test run passed all 711 tests with eleven skipped;
repository lint reported no errors. The full preintegration build's source
fingerprint was stable throughout its run. Completed jobs and their original
receipts were retained rather than restarted to recover a missing terminal.

## Unfinished candidates

The older machine-exact `001d1f30` candidate is not accepted: a null-companion
path can reach an uninitialized close flag, and its farthest-target selection
has no demonstrated qualifying-entry guarantee. The raw assembly review also
corrected the earlier assumption that the close flag inherits the movement
flag. Those uncertainties are recorded without inventing fallback values.

`00198920` has an exact target body but still changes two already-matched
neighbors. Its local tables now have complete independent proofs, but those
proofs do not waive the instruction regressions. The ongoing Fcl transition
and native constructor alternatives also require complete caller preservation
before acceptance. None is counted among the 76 recoveries above.
