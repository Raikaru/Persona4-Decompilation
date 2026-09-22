# Model manager: native 00473b20 closure after the 7387466 rebase

The owner is `src/Graphics/Model/mdlManager.c`, based on HEAD
`c4388741f9070eaec2b37e3a3af3684886d1a581`. The first-party owner now has
**120 MATCH / 6 ASM**, a gain of one ordinary-C function.

## Final proof

The authoritative receipt is
`build/continue-first-party-20260922/model-manager-after-rebase/closed-owner-contract/completed.json`.
The native object, exact compiled owner source, compiler log, official report,
official log, and individually resolved target bytes are retained beside it.

| Binding | SHA-256 |
| --- | --- |
| Final owner source | `5185a1dd62531d7c4d7b72e9fd936df94b4cd8c8de550d1755cb4c267d4efd86` |
| Final complete native object | `b5bfb0fe611d54fe5af854f791a24ef0806e902eb933a1c6a4a7e22f9f22eb5d` |
| Native b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Original rebased owner source | `3a1232706a3b0b6c876f36e48e7de02b7bdb2a010011d1d5718d2e448d980354` |
| Original rebased native object | `78b6c2eba585b4d8aa251bf69210b02d5dd6b5aad3fa4d938d4dde93d664236c` |

The profile is native `mwccps2.exe` b210 with `-O2 -Iinclude`. Every source,
header dependency, remaining ASM input, and compiler identity is bound in the
receipt. The official verifier explicitly reuses that one freshly compiled
current-owner object; its reuse and source/object hashes are recorded.

| Explicitly proved function | Executable / retail window | Zero tail | Resolved relocations |
| --- | ---: | ---: | ---: |
| `func_00473b20` | 1432 / 1440 bytes | 8 bytes | 26 |
| `func_00473000` | 312 / 320 bytes | 8 bytes | 22 |
| `func_0047a320` | 372 / 384 bytes | 12 bytes | 7 |

All three functions have full unmasked retail proofs, including every HI16,
LO16, GPREL16 and call relocation. The other 123 owner functions preserve
their bytes and canonical relocations. Every allocated data section remains
identical; these targets own no additional data sections. The earlier
`closed-00473b20` receipt separately proves the new target and preserves all
125 siblings. The owner-wide API cleanup then produced the identical complete
native object. All ten rebased `RtAnimInterpolatorSetAnimLoopCallBack`
relocations remain unchanged.

## Recovered C behavior and mechanisms

`func_00478a30` calls the update for each valid animation layer, passes the
previous layer and tick flag, and consumes the returned layer pointer.
`func_004740c0` establishes the blend state: a nonzero blend duration and a
valid prior clip are required before copying the previous index to offset
`0x10` and resetting progress at `0x1c`; the non-blending path sets progress
to one. Full retail ASM and both IDA/Ghidra drafts were inspected.

The previous guarded C omitted the repeated `index < table->count` check in
the non-blending sentinel fallback. The new C preserves that check before
reading the entry. Each independently guarded lookup narrows the promoted
stored index after checking its table. The checked index and the 32-bit
entry offset are separate values, and the positive table count remains
promoted through the pair of blend lookups.

The pre-callback blend input is separate from the progress reloaded after
the blend callback. Successful and fallback blend increments have separate
duration/step values. The actual sentinel, current interpolator, reciprocal
numerator, and increment are shared only where retail shares them. The
frame-to-time path snapshots its real scale, converted source frame and
completed time before loading the hierarchy for the setter. Scoped
`opt_common_subs off` and `opt_propagation off` retain these source lifetimes.
All locals are initialized along every path that reads them. No register-only
dummy, inline assembly, extra arithmetic, fabricated padding, volatile
ordinary state, or weakened proof gate was added.

The initial post-rebase active-body baseline was 267 differing words and
1472 bytes. Explicit lookup phases plus correct address domains reached 38
words at 1432 bytes. Guarding the independent narrowed indices reached four
words. Representing the real shared values and separating callback phases
closed the function exactly. The successful scratch body and complete
candidate receipt are under `motion-blend-inputs-before-increment/`.

## Owner-wide hierarchy contract

The hierarchy matrix-update interface takes one hierarchy pointer and returns
a signed word, consistent with the RW interface header. An old owner-wide
two-argument declaration had kept unrelated caller temporaries alive as
spurious arguments in `00473000` and `0047a320`. The final owner uses the
one-pointer `s32` declaration, removes obsolete K&R overrides and the unused
`func_00397c40_1` declaration, and removes both extra call arguments.

The canonical interface was tested against the completed first closure in
`after-00473b20/hierarchy-canonical-owner-interface/`. All 126 functions and
all allocated data remained identical. The final native current-owner gate
also explicitly proves both affected callers. `func_003d5e90` now has its
actual signed-word return type; all its actual arguments are preserved.
No vendor implementation or shared header was edited.

## Remaining owner work and preserved experiments

Six ASM fallbacks remain: `00471370`, `00475cd0`, `00476e90`, `00479100`,
`0047b0c0`, and `0047c660`. Their source bodies and old proofs are preserved.
The predecessor's 18 exhausted `00479100` probes were read and not rerun.
Its resume note remains
`docs/probe_archive/Model_manager_00479100_resume_20260922_worker2.md`.

Fresh rebased baselines were 72 unmasked words / 996 bytes for `00476e90`
and 30 words / 1908 bytes for `00479100`. A real material destination
lifetime reduced `00476e90` to 67 words without changing its size, siblings
or data. It still misses the retail quantizer register lifetime and material
base register, so it was not installed. Separate source/output colors,
scalar quantizer arguments, fixed component loops, alpha-value separation
and pointer-analysis variants did not close it. Each completed native job
has an immutable source/compiler/dependency/object receipt and alignment.

The old material note claiming retail stores directly from the quantizer to
the material is inaccurate: retail writes the local RGBA bytes at stack
offsets `0x8c` through `0x8f` before copying them to the material. Preserve
that real storage lifetime in later probes.

The old `model-manager/PAUSED_FOR_REBASE.md` named in the assignment was not
present; its release JSON and the predecessor's resume note were available.
No old script main, completed compiler job or completed gate was replayed.
The new source belongs to the final receipt above: earlier scratch harnesses
correctly refuse it because their frozen source bindings are older.
