# Persona animation renderer: 00118a20

The recovered `func_00118a20` uses complete packed-coordinate and color
objects. Its native b210 `-O2 -Iinclude` output is **1,744 / 1,744 bytes**,
with all **18 relocations** resolved exactly. The 101 other native functions
and all allocated data in `shdPersona.c` are unchanged.

The four-float scratch record has a union view containing two `PackedVec2f`
values, so each packed argument covers a complete object. Both triangle color
loops use a three-element, 16-byte-aligned `PackedColor4` array. The two
particle rows have separate counter scopes. These source shapes and the scoped
loop-invariant setting preserve the retail temporaries and allocation without
new side effects or ordinary arithmetic in assembly.

## Original initialization omission

Retail computes the four phase values only when flag `0x10000` is set. Within
that branch, it initializes the first scroll value only at frame seven or later,
and the second only at frame nine or later. Skipped assignments leave the
corresponding saved floating-point registers holding incoming values. No
default or additional argument is introduced in the reconstruction.

The callers do not establish a universal frame-nine precondition.
`func_0011e8e0` state zero sets `0x200 | 0x10000` and resets the counters at
offsets `0x520`, `0x522` and `0x524`. `func_00119e10` increments the first
counter before testing draw visibility, then calls this renderer when `0x200`
is set and `0x400000` is clear. Its earlier calls do not initialize the two
incoming saved registers. The frame-ten side effect in `func_0011ce50` does
not exclude earlier frames. `func_0011ba40` explicitly clears the visibility
bit, and an observed result-screen sequence can subsequently start the reset
callback for the same persona task.

These are static source and retail control-flow observations, not a gameplay
trace. They supersede the earlier scratch README's incorrect assertion that
`0x10000` initializes all six values. The original omission is preserved and
documented according to the project's existing camera and quaternion recovery
rules.

## Retained evidence

The reviewed worker package and state audit are in
`build/finish-first-party-20260922/resume-20-persona/package-00118a20/`.
The final owner source, native compiler receipt, independent target proof,
official installed-source report and sibling checks are in
`build/finish-first-party-20260922/resume-20-integration/`.
No assembly fallback is counted as recovered C.
