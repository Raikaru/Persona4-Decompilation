# Persona renderer 001187b0

The recovered `src/promoted/shdPersona.c` function emits 612 native bytes in
the 624-byte retail window. All four calls to `func_0034f4a0` resolve exactly;
the final twelve retail bytes are zero alignment. The compiler is the configured
MWCCPS2 b210, with owner flags `-O2 -Iinclude`.

The routine draws four sprites using an incoming position, a second packed
base position, opacity, and rotation. Its two coordinate inputs each cover a
complete eight-byte object. The first is passed as `PersonaPanelPosition`, a
union with two float coordinates and a packed `s64` view. The second retains
its scalar packed interface and is copied into the existing `PackedVec2f`
union before its float members are used. Both calls in `func_00118a20` and the
owner declaration use the same first-argument type. The caller's existing
sixteen-byte workspace still has a complete four-float view and two packed
coordinate objects.

## What changed the native instructions

The previous valid local-union snapshot candidate was already 612 bytes,
with only two prologue instructions exchanged: the opacity save preceded
the first packed-coordinate store. Making the first coordinate an actual
aggregate parameter fixes that parameter-homing order. Direct aggregate-field
access then introduces eight differences because b210 eagerly loads its two
coordinates at function entry.

An addressable pointer view restores the source load sequence but emits an
additional address calculation. An array-member view alone also leaves eight
differences. With the complete array-member parameter and function-scoped
`opt_scalarize off`, the component loads remain at their original use sites,
and the complete native body matches. `opt_decomposeaggregates off` on the
same source is an eight-word tie. This is a measured effect on this aggregate
source model, not a general conclusion about scalar-register allocation.

The existing scoped `opt_propagation off` preserves the individual Y-offset
conversions at the four calls. The final source needs only these two scoped
optimization settings. Removing the diagnostic warning and redundant pointer
analysis directive, renaming real values, and archiving the old floor comments
all retained the exact native result.

## Verification evidence

The final whole-owner compilation preserves all 101 other functions, including
the two changed source callsites, byte-for-byte and relocation-for-relocation.
Allocated data is unchanged. The incoming arguments, callback parameters,
arithmetic grouping, memory reads, and sprite-call order are preserved; no
register bindings, assembly, fabricated effects, or patched object bytes are
used.

The fully resolved target SHA-256 is
`8f570e38be8d1f26818f911174c9e6326270def4a0307d50e0d192bdab297943`.
The original raw target SHA-256 is
`6287b83ca2c06fcb265b39d82d97f5922be2afae5d8ea156de0ebe7607fce0fa`.

Sources, compiler receipts, native objects, sibling comparisons, and complete
relocation proofs are retained under
`build/finish-first-party-20260922/continue-24/persona/`.
`array-noscalar` is the discovery; `reviewed` is the final source package.
Installed-source and publication records are recorded separately by
`continue-24/persona_integrate.py`.
