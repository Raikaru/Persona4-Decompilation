# Independent SDK/Fcl closure review

Date: 2026-09-20. Reviewer: worker-7. Reviewed proposal:
`build/first-party-resume-167e607/sdk/stage04/` and
`sdk/sdk-fcl-closure.patch`. The SDK lane and live SDK sources were read only.
The reviewer did not compile the closure, change its proofs, or install it.

Recommendation: integrate the frozen proposal, preserving the current quad
caller fixes and verifying the combined inputs. No callback contract,
return-value, bounds-prefix, priority, or font-handle blocker was found.
This recommendation is not a claim that the combined live tree has passed
the prime's integration checks or a full build.

## Independently reproduced evidence

The review scripts and output are in
`build/first-party-resume-167e607/fresh/worker7/`:

| File | Evidence |
| --- | --- |
| `sdk_review_evidence.py` | Read-only source, dependency, compiler-setting, object, relocation and retail comparison |
| `sdk-review/evidence.json` | All 112 independently recomputed owner comparisons, fourteen resolved targets, patch hashes and live drift |
| `sdk_review_callbacks.py` | Actual source inventory, all 132 definition repairs, return-site checks and review-only three-way merges |
| `sdk-review/callbacks-and-merge.json` | 400 compatible role definitions, 241 registrations, repaired definitions and merge receipts |
| `sdk-review/merge-0021.c` | Conflict-free merge preserving the current `00212270` caller |
| `sdk-review/merge-0038.c` | Conflict-free merge preserving the current `00385970` caller |

The frozen patch SHA-256 is:

```text
bf94220f7b325e010bdca29c42e5537adc4be23e3783fb4180ea98bb80d2ca63
```

The reviewer checked each patch path's input and proposed hashes, each
selected object and baseline receipt, every selected source hash, and the
recursive include dependencies against both the selected compilation stage
and final `stage04`. Used header hashes match the compiler receipts. The
recorded compiler and normalized flags match each owner's configured compiler
and flags. The checks found no unknown include expression in these dependency
closures.

Both ELF objects were independently read for all 112 owners. Their 3,554
function-name sets agree. Of those functions, 3,553 retain identical bytes
and 3,553 retain identical canonical relocation lists. The initializer
`002e8410` is the sole byte change. The only relocation-list change is the
`00192e90` callback alias; its old and new complete functions resolve to
identical bytes. All allocated data contents, sizes, alignments and canonical
relocations agree.

All fourteen listed targets were independently relocated using the frozen
symbol maps, compared with the actual retail image, and checked against the
saved resolved files and hashes. Every emitted byte agrees, and every
remaining byte in its retail window is zero. This covers the initializer,
creators, bounds constructor/setters, registration providers, SDK dispatcher
and the alias caller. The initializer's 148 relocations are included in the
resolved comparison.

## Callback contract and definition repairs

The current SDK provider stores the update callback at task offset `0x30`,
destroy callback at `0x34`, and work pointer at `0x38`. Its dispatcher calls
the update with the task object. A zero result keeps the handler, another
word supplies a replacement handler, and `-1` initiates the destruction path
when the task is in the relevant state. The cleanup calls ignore a return
value. This agrees with `SdkTaskUpdate` as `s32 (*)(u8 *)` and
`SdkTaskDestroy` as `void (*)(u8 *)`, including the actual registration
definitions and task fields.

A fresh source scan reproduces all 400 compatible callback role definitions
and 241 registration expressions in 103 owners. Every one of the 132 changed
definitions was checked against its actual final source signature and return
statements. These changes comprise 121 parameter repairs, seven `void` to
`s32` return repairs, three `u32` to `s32` changes, and one pointer-return to
`s32` change. They are not 132 newly recovered function bodies.

All seven previously void update callbacks have real retail return evidence:

| Function | Ordinary/early zero return sites | Other result |
| --- | --- | --- |
| `00148280` | `001495e8`, `00148318` | None |
| `0016bdd0` | `0016e1d0`, `0016be18`, `0016be34` | None |
| `00182bc0` | `001837bc`, `00182bf8` | None |
| `00183b80` | `001850f0`, `00183bd4` | None |
| `00185850` | `001865d4`, `00185888` | None |
| `0018a200` | `0018baa8`, `0018a234` | None |
| `00332bb0` | `0033bd80` | `0033bd74` returns `-1` after the completed state-18 test |

The corresponding assembly was inspected. Their large inherited C drafts
remain guarded. Their active assembly bodies are preserved, and the source
contract repairs do not count them as new matches. The three unsigned-return
functions and `btlUpdateDraw3DFrontTask` return zero in their actual bodies;
the signed SDK return declaration preserves that result.

The lexical scan initially reports five indirect expressions. Each was
checked instead of treating an empty postprocessed list as evidence:
`cldScheduler.c` assigns its typed update and destroy locals to `00260020`
and `00260440`; `00451fc0` forwards its already typed parameters `a5/a6`;
and `k_fldUnit.c` indexes the actual `D_005F15B0` callback table. Its retail
entries are zero, `00166c80`, `00166e30`, and `00167120`. The three providers
have the required signed-word update signature.

The scan balances source expressions and retains conditional definitions; it
is not a C parser or a new whole-program control-flow proof. Actual provider
and return-path inspection, saved whole-owner compilation, and independent
binary comparisons supply the other checks described here.

## Bounds prefix and consumers

The constructor initializes signed dimensions at offsets eight and twelve.
Its preceding eight bytes remain unspecified. The final source copies a
four-byte-aligned structure containing only unsigned-character bytes through
the packet's `representation` member. The constructor and all reviewed
forwarders do not evaluate those prefix bytes as an integer or float.

The full constructor/setter proofs preserve the retail copy instructions.
The source-level representation operation does not give the carried prefix a
stable numeric value. Numeric consumers were traced through the actual work
objects and their draw callbacks:

| Path | Copied prefix | Numeric fields read |
| --- | --- | --- |
| Rectangle setter to `002b52a0` | `work+0x120..0x127` | Dimensions `0x128/0x12c`; position `0x134/0x138` |
| Animated rectangle inputs | `0x158..0x15f`, `0x168..0x16f` | Dimensions `0x160/0x164`, `0x170/0x174` |
| Combine-draw forwarding through `002b81f0` to `002b7f20` | `0x08..0x0f` | Position `0/4`; dimensions `0x10/0x14` |
| Digit work consumed by `002b9ab0` | `0x204..0x20b` | Dimensions `0x20c/0x210`, multiplied by scale `0x194/0x1a0` |

The rectangle's render callback `002b5120` reads flags at `0x184/0x18c` and
does not inspect the prefix. The only external `002b5da0` getter use tests
the work state byte at offset zero. The black-rectangle render callbacks
`002b6da0` and `002b6ea0` set render state and do not evaluate the work prefix.
The digit updater's `0xf0`-byte copy begins at work `0x104`, ending before
the packet at `0x204`; its final renderer reads the initialized dimensions.

The common/combine-draw direct forwarding copies and constructor calls were
also inspected. Existing unrelated incomplete guarded C drafts remain
incomplete; this review does not claim that those entire drafts have been
recovered. The reviewed bounds-prefix paths contain no numeric use of their
uninitialized prefix.

## Priority and handle semantics

`code1_0010.c` calls `00481a20` with integer priority `0xc7`. The corrected
`tnEffect.c` function accepts `s32` and passes the same integer to the actual
`004b3180(s32)` crossfade provider and SDK registration. No pointer-derived
priority is introduced. The entire tnEffect owner is preserved in the saved
comparison.

`frFont.c:00274970` stores the task pointer returned by registration into its
existing EE 32-bit handle field through an explicit `s32` conversion. The
second registration ignores its returned handle. This preserves the original
handle storage and all function bytes in that owner.

## Integration with the recovered transition quad

The SDK patch does not change `src/shdMisc.c` or
`include/shd_misc_internal.h`. It does overlap the owners of two guarded
callers repaired for the new exact `00364fb0` match: `code1_0021.c` and
`code1_0038.c`.

A read-only `git apply --check` against the live tree fails only at the first
include hunk in `code1_0038.c`, where the quad work added the shared header.
Independent `git merge-file -p current inputs stage04` calls succeed without
conflicts for both files. The saved review copies retain the complete current
`00212270` and `00385970` function regions. The SDK changes concern includes,
callback declarations and separate registration sites. Replacing these owners
with their unmerged frozen versions would lose the quad caller fixes.

The review copies were produced from these current source hashes:

```text
code1_0021.c  520af7d60f3fe668653519c03501813e48e38de1e0a3f09f00462ac1f660f95e
code1_0038.c  269c508895a14b0c10b2c03b53bf3e051b9522960f369a6fc641d8d340432f5c
```

The live shared quad header differs from the frozen input. It affects the
saved dependencies of `calendar.c`, `code1_0020.c`, `code1_0021.c`,
`code1_002b.c`, `code1_0033.c`, `code1_0035.c`, `sdkFiler.c`, and
`shdPersona.c`; the current `code1_0038.c` also newly includes that header.
The frozen proofs therefore cannot substitute for combined-input checks of
these owners. The reviewed, reserved `0020ff00` quad caller patch remains
held for prime integration. This reviewer has not edited that live owner.

All review commands completed. No SDK file, frozen proof, production source,
compiler setting, commit, push, or full build was performed during this review.
