# nLine decoration direction domain, 2026-09-27

The ordinary-C recovery of `func_0034e360` uses its direction pair only for
decoration modes 1 through 4. Its callers establish that either those modes
are absent or a direction-initializing dimension is present.

The retail table at `0x007523C0` contains 36 records of 16 bytes: `u32 flags`,
`f32 duration`, then signed halfwords axis, kind, effect and decoration. The
first word is an integer flag, not a floating-point rate. All records whose
kind is 14 through 17 have decoration zero. `func_0034bb20` selects a bounded
table index and installs that decoration. Index zero retains the old decoration
but selects kind 1, which does not use scaled drawing.

`func_0034bd60` also changes the index and retains the decoration. All 17 retail
direct calls pass literals from `{3,4,8,11,14,15,21,22,25}`; their decoded argument
multiset matches the maintained source. Only 8 and 25 select scaled drawing,
both kind 14. This setter writes one to the state flag at `+0x1690`, causing
`func_0034db60` to use amount one and width 640, which initializes directions.
The inverse scaled rows 32 and 34 are not observed inputs of this setter.

The other direct caller, `func_0034e0b0`, passes width 640 and height 448.
Retail direct JAL counts are 38 for `0034bb20`, 17 for `0034bd60`, four for
`0034db60`, and two for `0034e360`. No direct jumps, allocated aligned full
function-address words, or address constructions in an eight-instruction
LUI/low-part scan were found for these four functions. This bounds the observed
references; the bounded address scan is not a proof of arbitrary dynamic
pointer dataflow. Preserve the setters and caller domain when revising this C.

Retail SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`. The review retained all raw table records,
retail call contexts and argument loads, current source hashes, and setter/caller
excerpts. Native C behavior, exact target compilation and full-link acceptance
are separate checks; this note records the caller-domain argument.
