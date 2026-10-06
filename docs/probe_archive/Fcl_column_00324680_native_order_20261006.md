# Fcl column drawing: native allocation order and coherent contract trials

`func_00324680` remains guarded C and still has **15 fully resolved differing
words**, with 2,292 bytes in the 2,304-byte retail window. The twelve trailing
retail bytes are zero. No Fcl source, caller or shared header was installed.
The existing trail renderer repair in `btlShuffleDraw.c` remains frozen.

Work is retained under
`build/finish-20261006/fcl-worker5/column-observation/`. The captured current
owner is `src/Event/Fcl/y_fclCombineDraw.c`, SHA-256
`eee7b4bfd3e06ad8e4733a6989f353090648e124f7ee2ceb69fbf226402fdc68`.

## Whole-owner baseline

The control is a complete configured owner compile with this target's guard
enabled and the other two remaining functions using their ASM fallbacks.
All **72 target code references** resolve to retail. All 69 other functions
in that object match retail, including the two assembly fallbacks; this is
not a claim of 69 C matches. All **five owned data sections** resolve exactly.
The fifteen differences are entirely the late two-column loop's raw counter
and its signed-halfword body view: the candidate exchanges `$s0` and `$s3`
over the differing instructions between `+0x4C8` and `+0x744`.

A diagnostic register-field normalization explains every difference. That
normalization is not compiled, linked or installed, and does not earn any
matching credit. The real object still differs at fifteen words.

## Native compiler observations

The original MWCCPS2 b210 compiler was observed with the existing schema-1
GDB profile, using a lane-local copy of the validated capture driver. The
full direct object and debug object are byte-identical. Both the current
source and the coherent signed-delay/cursor alternative produced **327
complete snapshots** without instrumentation errors or input drift.
Each target's native code and canonical references also equal its separate
complete mwccgap owner compilation.

| Captured source | Direct and debug object SHA-256 |
| --- | --- |
| Current control | `9949e61a8063594c42b94d7cf7fd0d76b986e8dcbcd27c5d2316e96e1412f733` |
| Signed delay reused as cursor | `4d8464f8a2c606e49361e53eb83a396fa7efae6ac65d2aef23d1db51526ddcd9` |

The target occupies stages 207-211. The actual GPR colorgraph has 362 nodes
and no coalesced aliases. The captured assignment replays exactly. The
ascending-ID simplification procedure and its final degrees also reproduce
the observed order exactly; its relevant removals are ordinary degree
removals, rather than spill-cost choices.

| Current value | Virtual ID | Observed GPR | Color work-list position |
| --- | ---: | --- | ---: |
| Raw column cursor | 36 | `$s3` | 14 |
| Signed body view | 223 | `$s0` | 8 |
| Shown alpha | 194 | `$s1` | 9 |
| Hidden alpha | 192 | `$s2` | 10 |
| Resource ID | 35 | `$s5` | 15 |

The raw cursor is an early declared scalar. Its signed body view is a later
generated `sext` result. Once their neighboring temporaries are removed, the
ascending virtual-ID walk removes resource 35, cursor 36, hidden 192, shown
194 and body view 223. Reversing the simplify stack colors the body view
before the alpha values and cursor. This accounts for the observed register
order. Merely increasing a spill preference cannot change this degree-only
ordering. This is an observation of the current compiler run, not a claim
that retail's original virtual graph is available.

## Coherent delay contract and its limitation

Retail explicitly interprets the delay as a signed halfword before its
twelve-row phase. The one active caller owner, `y_fclCombine.c`, passes only
the constants 0 and 2 at the six call sites in `func_002f9d90`. A coherent
alternative changes both the definition and caller declaration to `s16`.
The complete 41-function caller object is byte-identical, including data;
the callee control remains fifteen words. This validates that alternative
contract for the observed callers, not a unique historical type inference.

Reusing the retired signed delay object as the later column cursor gives
22 words at the same length. A second native capture explains the regression:
the raw cursor now colors to `$s0`, but the normalized view takes `$s1`,
then shown and hidden alpha take `$s2` and `$s3`. Both native graphs replay
exactly. The desired raw-cursor register was recovered while displacing the
three other live values. No caller-only ABI mismatch is retained.

## Fresh source measurements

These trials were selected from actual phase boundaries and the captured
ordering, rather than repeating the previous broad declaration permutations.
Every complete-owner candidate preserves all 69 other function bodies and
canonical references and all owner data. None improves the current result.

| Source mechanism | Masked words | Emitted bytes |
| --- | ---: | ---: |
| Coherent signed-halfword delay | 15 | 2,292 |
| Signed delay reused as column cursor | 22 | 2,292 |
| Private signed-delay whole operation | 504 | 2,296 |
| Complete column-pair helper, word or byte alpha inputs | 50 | 2,292 |
| Final cap position derived from completed column count | 112 | 2,308, exceeds window |
| Distinct per-layer drawing operations | 92 | 2,292 |
| Mutable counter advance through its actual short storage | 29 | 2,292 |
| Counter read and advance through that storage | 28 | 2,292 |
| Complete column operation returning/updating next cursor | 64 | 2,292 |
| Scalar or aggregate alpha-output boundary, current cursor | 15 | 2,292 |
| Scalar or aggregate alpha-output boundary, delay cursor | 22 | 2,292 |

The sixteen retained owner records include the current control. The existing
control's 15-word floor remains best. Native captures, PCode stage excerpts,
exact GPR replay, exact simplify replay, paired caller proof and all probe
sources/objects are retained in the lane directory. The adjacent receipt
binds the source, objects and the compact allocation evidence to hashes.
There is no new production edit, C promotion, commit or push from these trials.
