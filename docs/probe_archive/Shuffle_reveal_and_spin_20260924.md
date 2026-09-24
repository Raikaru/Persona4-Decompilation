# Shuffle reveal and spinning highlight recovery

Two first-party renderers in `src/promoted/code1_0038.c` now reproduce the
retail instructions using the owner's configured MWCCPS2 b210 `-O2 -Iinclude`.
`func_0038acd0` emits 1,264/1,264 bytes with all 18 relocations resolved.
`func_00387750` emits 1,820/1,824 bytes with all 28 relocations resolved and
four zero alignment bytes. Their combined object preserves all 93 neighboring
functions, canonical relocations and allocated data.

## Reveal bands: 0038acd0

The callback uses the counter and flags at work offsets 0x1B4 and 0x1B6 to
animate five symmetric bands and the center rectangle. Its existing table
at 0x0064F090 contains five 16-byte records: distance, width, start fraction
and end fraction. The complete local factor array contains five records,
each holding one float. The existing Vec2f drawing arguments and easing
function signatures remain unchanged.

A scoped `opt_loop_invariants on` preserves the retail preheader for the
constant fill. Direct `(f32)span` expressions in the two easing arguments
retain one conversion per iteration. Naming that converted duration as an
independent assignment lets the optimizer hoist it too early and changes the
native code. The final source also preserves the factor-pointer lifetime,
table-load order, counter transitions and separate distance/width values.

The resolved target SHA-256 is
`1094feaac59fae656e6328c4bbb02fd2d7bb4a1424bdd0229fef36d64c1143ac`.
The native GPREL16 reference at 0x0038AD60 independently establishes the
`fGpffff83a4` data alias at 0x00761494 using GP 0x007690F0 and a zero addend.
The curated and generated symbol tables must include it so the owner is
actually linked from C.

## Spinning highlight: 00387750

The frame, phase counter and transition flags begin at work offset 0x46.
The entrance reaches frame 15; the exit path reaches frame 35 and clears
work flag 0x400. The phase counter advances modulo ten. Two triangle-fan
passes retain their original coordinates, colors, alpha calculations and
render-state calls.

The four vertices use the canonical 64-byte `BtlShuffleSkyVertex` record.
Obtaining each vertex pointer after calculating X and Y restores the
original saved-register and stack layout. A local record groups the cached
depth, reciprocal Z and phase values. The quarter-turn helper returns the
real index-scaled offset; assigning it to a float before adding the phase
keeps the original separate multiply and add in both passes. The dispatch
record keeps the callback slot address across passes and reloads the slot
for each call.

The quarter-turn, full-turn phase and secondary-alpha constants were checked
against their retail bytes at 0x007614C8, 0x007613EC and 0x007613BC respectively.
The final source does not use assembly, bound registers, speculative unions,
fabricated effects or object-byte modifications.

## Evidence

The accepted paired source is under
`build/finish-first-party-20260922/continue-69-shuffle-effects/proposal-acd0-7750-reviewed/`.
Its source SHA-256 is
`858f48945f83400efa1acddac76e8e381dad05f73a0db9d567b8f7fc9735b646`;
its native object SHA-256 is
`032bdcbcc473a540c4cef6f87b5dad0fb2f67e65a54773ca3be3f4987362981f`.
That directory retains both complete relocation proofs, the explicit
93-function sibling proof, semantic table/caller evidence and reviewed diff.
The similarly named directory without `-reviewed` is a rejected cleanup
experiment and is not the accepted source.

Installed-source closure, all required linker aliases, full build hashes and
actual first-party C linkage are checked separately in `continue-70-integration/`.
