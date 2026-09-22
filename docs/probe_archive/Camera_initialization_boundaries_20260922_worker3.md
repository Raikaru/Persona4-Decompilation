# Camera owner initialization boundaries, 2026-09-22

The remaining `src/promoted/code1_0022.c` functions were reviewed against retail,
both decompiler headstarts, and their current callers and providers. No source
candidate was installed. The owner retains 94 MATCH / 4 ASM; this review adds
no MATCH claim.

The new scratch record is
`build/finish-first-party-20260922/camera-next-01/camera-audit.json`.
It authenticates the completed `battle-geometry-after-rebase/final-integrated`
source, compiler, dependency, assembly-input and object hashes, checks the
critical words against the retail ELF, and preserves numbered source excerpts.
Completed compiler and verification commands were not repeated.

## `00222210`: scroll phase on frames one through six

Retail branches from `00222400` to `00222514` when the frame at work offset
`0x46` is below seven. That path bypasses both assignments to `$f20`, at
`0022247c` and `00222510`, but the multiplication at `0022272c` consumes it.
Saving the incoming callee-saved register in the prologue does not initialize
an ordinary C local.

`002230e0` clears the allocated work. The state-zero path of `00221f40` sets
draw flag two, and `00222d20` increments the frame and calls `00222210` without
a frame-seven guard. These callers admit the early-frame path. The guarded
draft's `var_f20` remains unwritten there; no initialization invariant was
established by this review.

## `00225ec0`: player camera point height

The player-kind path reads `point.y` at `002260f8` from `sp+0x134`, then first
stores that slot at `0022610c`. Before the read, the called providers receive
the first pose at `sp+0xe0`, centers at `sp+0x140` and `sp+0x150`, and the
direction at `sp+0x120`. None receives the point record at `sp+0x130`.

`00228d50` and `00228f60` explicitly call this function for player-kind units.
Neither guarantees its separate cached-action early return. Giving the point
height a new value would change retail behavior; reading an uninitialized C
local does not meet the recovery requirement. This function remains ASM.

## `0022a730`: selected action and parameter storage

Retail assigns `$s1` at `0022a7f8` only after finding an eligible action whose
unit has status `0x100`. There is no initialization before the scan, but
`0022a80c` tests `$s1` after the scan. The current draft initializes `v1` to
zero, which supplies behavior absent from that retail path.

`0022dbe0` arranges this callback after finding an active party member
**without** status `0x100`. `001fae60` merely stores callbacks and their
argument. `001fac80` dispatches after checking the global callback gate and
`0022bd00`, whose body only tests the pointer at global offset `0xba0`.
Neither establishes an affected action. The earlier `00229da0` status-apply
loop filters targets and does not prove a positive count remains when this
callback executes. No runtime invariant excluding an empty affected set was
established.

There is also a separate storage defect in the guarded draft: its `v26[12]`
is passed to `001f0a10`, whose implementation clears `0x20` bytes, and to
`001f36e0`, which copies `0x20` bytes. Retail uses `sp+0x70..0x8f`, with the
status word at offset `0x0c`; the center starts at `sp+0x90`. A future valid
candidate needs one complete 32-byte parameter record, as already used by
the neighboring `00229da0` implementation. This does not resolve the selected
action initialization issue.

## Existing second-pose blocker

`00224450` remains under its previously recorded undefined second-pose
restriction. This lane did not modify or recompile that draft.
