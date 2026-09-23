# Shuffle ring and count animation

`src/promoted/code1_0038.c` has two additional native C recoveries. The installed
owner reports **82 MATCH / 8 ASM**, advancing the first-party checkpoint to
**6,544 MATCH / 316 ASM**.

| Function | Native bytes / retail window | Resolved relocations | Zero tail |
| --- | ---: | ---: | ---: |
| `func_0038a480` | 1,204 / 1,216 | 19 | 12 bytes |
| `func_0038c100` | 1,640 / 1,648 | 12 | 8 bytes |

## Ring geometry

The ring renderer uses a complete three-component rotation axis and transformed
position, the actual matrix pointer returned by the allocation API, and a
130-element array of 64-byte vertices. Each of the 65 samples writes both ring
edges, including their four color channels, depth and reciprocal depth. The
second edge retains the original displacement calculation.

The source retains the real angle value across the sine/cosine calculations.
The inclusive sample bound `i <= 64` and the post-loop `count <= 130` test use
the actual ranges established by the two increments per sample. Neither adds
an iteration or suppresses the existing diagnostic path. The local vertex
helper is fully inlined; no additional executable function was introduced.

The first-party caller declarations agree with the matrix allocation,
destruction, rotation and point-transform providers. The matrix stays a pointer
through allocation, calls and destruction. The transform receives addresses of
complete three-component objects and preserves the provider's supported
in-place input/output alias. Provider implementations were not changed.

## Count animation

The count renderer preserves separate horizontal and vertical scale values,
the eight-frame entry/count-change phases, and the five-frame exit phase.
Frame counters remain halfwords, including truncation after increment. Exit
clears the flag on the original task object at offset 4; it does not clear the
count stored in the animation subobject.

The easing and sprite calls use the existing providers' argument order and
byte/halfword domains. Distinct X/Y remainder and extent values preserve the
retail calculation order for the centered, scaled sprite. The original three
background sprite calls precede the scaled count sprite.

## Validation and retained evidence

Both functions compile as active C under the configured MWCCPS2 3.0.1 b210
`-O2 -Iinclude` profile. Their complete native instruction streams match after
every relocation is resolved. The zero suffixes agree with the full retail
windows. All 93 other native function bodies and canonical relocation targets,
including previously recovered C and remaining assembly siblings, are unchanged.
Allocated data is identical.

The retained ABI-correct worker package is
`build/finish-first-party-20260922/continue-15-shuffle/resume-6542/package-combined-c100-a480-abi/`.
Its `manifest-typed.json` names the successful native source/object and proofs;
the earlier uncorrected package is preserved separately. Integration removed
duplicate markers and obsolete failure comments, then compiled the reviewed
source once and verified its unchanged native results.

The installed-source verifier report, current owner receipt, unmasked target
proofs and complete first-party checkpoint are under
`build/finish-first-party-20260922/continue-17-shuffle-integration/`.
`completed.json` records the installed count and source/compiler/input hashes.
Focused integrity lint and `git diff --check` passed. The subsequent full build
completed with no source drift and exact retail hashes:

* Load image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`.
* Complete executable SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Both new functions occur in the successful source-link report, and all 5,801
first-party source-link entries from the preceding published build remain
present. Recovery counts and link participation are separate: remaining
assembly siblings in compiled source owners are not counted as recovered C.
`build/completed.json`, `build/progress.json` and `publication-checked.json` in
the integration directory retain the completion, current inputs and comparison.
