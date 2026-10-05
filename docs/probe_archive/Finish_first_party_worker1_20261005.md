# Battle fade continuation: func_001b87e0

`src/Battle/btlMain.c` retains a **2944-byte guarded C candidate with thirteen
differing instruction words** at `0x001b87e0`. It is not an accepted C match.
Production remains `INCLUDE_ASM`, and the retained production owner report is
**26 MATCH / one ASM**. This continuation adds **zero production matches**.

The improved guard was already installed before the interrupted run resumed
and before prime captured `build/resume-20261005/baseline-verify-inputs.json`.
The resumed work did not edit production source or shared headers. Its final
tracked additions are this note and
`Finish_first_party_worker1_20261005_receipt.json`.

## Source and owning-object identity

The worktree is `build/finish-first-party-20261005`, based on `a1cede78`, using
the owner's configured MWCCPS2 3.0.1 b210 compiler and `-O2 -Iinclude` flags.
The guarded function additionally enables `opt_loop_invariants` under a
balanced pragma push/pop.

| Input or evidence | SHA-256 |
| --- | --- |
| `src/Battle/btlMain.c` | `10e04f830857283b8f290bcd6ad009e93c6c4f28ca8c49588331f4a7e7bc1655` |
| `build/worker-1/resume-retained-floor/func_001b87e0/owner.o` | `e1232f1dc8711a53e6003bbc4c724e3791017df9b8a78804386803c9333ea6b0` |
| `Finish_first_party_worker1_20261005_receipt.json` | `0f3fba00115b8bba7a4480e2caf7c5a8dea50650334bb794182e617affb016bc` |

The source hash agrees with both the earlier `build/worker-1/fade-proof.json`
and prime's baseline input manifest. The fresh owning-object hash is also
identical to the earlier guarded candidate object. The receipt includes the
complete base commit, artifact sizes and hashes, all thirteen word differences,
all 48 target relocation records, sibling results, and source deltas for the
six rejected resume candidates.

## The pre-existing guarded recovery

The earlier worker measurement of the original installed guard produced
**2920 bytes, 584 positional differing words and 271 aligned edits**. The
September 26 archived reconstruction was substantially closer; its ordinary
C structure was recovered into the current guard before this resume.
Those earlier measurements are retained under `build/worker-1/current/` and
`build/worker-1/fade/`, and are not new results from the resumed turn.

The current work record contains five actual `RwV4d` objects, followed by
the total frame count at `+0x50`, current frame at `+0x54`, and flags at
`+0x58`. This agrees with the adjacent constructor `func_001b9360`, which
allocates `0x5c` bytes and installs `func_001b87e0` as its update callback.
The callback retains its `u32(void *)` contract.

Palette conversion uses the existing complete four-byte `BtlCameraPalette`
objects `D_007635C8` and `iGpffffb45c`. It no longer obtains the second palette
by indexing beyond the adjacent scalar `fGpffffb458`. Whole RGBA assignments
preserve the initial unit color snapshot and completion color copy. The
fifth vector's final component now includes the target contribution multiplied
by the frame ratio, as the retail `mula.s`/`madd.s` sequence requires.

The full retail listing, the constructor, and the actual color providers in
`src/promoted/code1_0014.c` were inspected. `func_001496c0` consumes four
floating color factors; `func_00149ca0` and `func_00149ce0` return the scene
resource's color-vector storage at `+0x140` and `+0x150`. This continuation
does not change their declarations, definitions, or callers.

## Fresh scoped evidence

The final refresh used `probe_variants.scratch_source` to replace only the
target guard in a temporary copy of the **complete owning translation unit**.
It compiled that copy with the actual owner's configuration. No assembly
fallback was counted as candidate C.

| Check | Result |
| --- | --- |
| Candidate body / retail window | 2944 / 2944 bytes |
| Instructions | 736 / 736 |
| Relocation-masked difference | 27 bytes across 13 words |
| Aligned instruction edits | 13 |
| Nonzero retail tail | None |
| Target relocations checked | 48; no problems |
| Existing C siblings checked in the same object | 26; all retain size and zero normalized difference |
| Sibling relocations checked | 164; no problems |

The 48 target relocations comprise **31 `R_MIPS_GPREL16`, eight
`R_MIPS_26`, and nine `R_MIPS_LITERAL`** records. Call destinations and
symbol addresses were checked against the symbol map and retail immediates.
For every literal relocation, the object literal bytes were compared with the
retail bytes at the GP-relative destination. The normalization literal is
`0x3b808081`, or `1.0f / 255.0f`, at retail `0x007612e4`.

The production summary comes from the retained `fade-after.json`, compared
with the earlier `baseline.json`. Status, object size, retail window,
normalized difference, and relocation lists are unchanged for all 27 markers.
The resume independently rechecked the 26 C siblings and their relocations
in the freshly compiled guarded object. It did not run another production
owner verifier, a broad test suite, or the full link; combined acceptance
belongs to prime.

## Remaining instruction difference

All thirteen differences belong to the unit-color quantizer. Retail
materializes `255.0f` into `$f4`, `0.5f` into `$f3`, and the compiler's
accumulator zero into `$f2`, in that order. The retained candidate creates
the accumulator zero first in `$f4`, then places `255.0f` in `$f3` and
`0.5f` in `$f2`.

Five setup words differ at `+0x68c` through `+0x69c`. Eight later words use
the corresponding different registers: the `adda.s`/`madd.s` pairs at
`+0x80c/+0x810`, `+0x828/+0x82c`, `+0x844/+0x848`, and `+0x860/+0x864`.
The candidate's remaining instruction bytes and all checked relocation
values agree with retail. The register and setup-order residual still
precludes promotion.

## New rejected hypotheses

These candidates were measured during the resumed turn against the unchanged
source hash above. Positional words count differences at fixed offsets;
aligned edits compare the instruction sequences and therefore differ when
the body size changes.

| Hypothesis | Object bytes | Differing words | Aligned edits |
| --- | ---: | ---: | ---: |
| Reuse the matched material quantizer's typed helper and named gain/bias | 2944 | 13 | 13 |
| Same helper with `always_inline` | 2944 | 13 | 13 |
| Snapshot the normalized vector into a const local before quantization | 2956 | 270 | 110 |
| Move one unit's complete fade into an inline helper | 2920 | 297 | 117 |
| Move the complete unit-list fade into an inline helper | 2920 | 297 | 117 |
| Preserve named gain/bias lifetimes with propagation disabled | 2924 | 691 | 190 |

The material helper pattern was grounded in the matched implementation at
`mdlManager.c:func_00476e90`; here it leaves the same thirteen-word residual.
The const snapshot changes temporary storage. The unit/list helper boundaries
also change the surrounding global blends and accumulator-seed lifetime.
Disabling propagation materializes gain and bias first, but disrupts the
normalization-load placement and register allocation. None is installed.

The earlier channel-helper permutations, scalarization settings, coefficient
arrays, and channel-cast variants were reviewed from retained evidence rather
than repeated. The new source deltas and each candidate's result/object hashes
are embedded in the receipt so that the rejected hypotheses are concrete.

## Replay

From a configured worktree, the repository's existing guarded-body tool
recreates the C measurement without modifying the owner:

```text
python tools/measure_guarded.py src/Battle/btlMain.c func_001b87e0 --save-candidate build/btlMain-fade-candidate.c
```

The exact refresh used in this continuation was:

```text
.\build\venv\Scripts\python.exe build/worker-1/measure.py --source src/Battle/btlMain.c --function func_001b87e0 --label resume-retained-floor
```

Its compiler log, complete side-by-side disassembly, alignment, candidate,
object, and byte images are retained together under
`build/worker-1/resume-retained-floor/func_001b87e0/`. The final receipt was
generated by `build/worker-1/finalize_fade_receipt.py`, which only reads
existing evidence, validates hashes/relocations/siblings, and writes the
receipt. It does not compile or edit production source.

No host execution or EE runtime semantic certification was added in this
continuation. The production fallback and guarded classification remain
explicit.
