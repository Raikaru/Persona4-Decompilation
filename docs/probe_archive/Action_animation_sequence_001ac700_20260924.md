# Action animation sequence 001ac700

The recovered callback emits 1,036 native bytes in the 1,040-byte retail
window. All thirty relocations resolve exactly and the remaining four bytes
are zero alignment. It preserves all seventy other functions in
`src/promoted/code1_001a.c`, including the newly recovered `001ae3d0` callback,
and all existing allocated data.

## Selection values and resource lookup

The animation selection owns four halfword values: resource slot, animation
ID, frame count and camera state. Representing them together reproduces the
retail lifetimes of the action pointer, packet identity, camera state,
resource slot, animation packet and frame count. The arithmetic, branch
conditions and packet-construction order remain unchanged.

The resource helper accesses the action's real pointer-sized resource slots
at context offset `0xD04`. Its structure covers the prefix through the highest
slot used here, `0x21`. Passing the context before the halfword slot and using
the array member preserves the context reload before the index calculation.
The equivalent flat byte-offset helper leaves three differing words.

Camera and next-action states use the existing halfword APIs. Keeping the
two retail switch paths, even though both choose state `0x20`, reproduces the
retail branches and argument materialization without an artificial effect.

## Animation and packet contracts

The animation packet API's ID is signed: the provider interprets the ID as
`s16` and recognizes negative sentinels such as -2, -3, -4 and -5. Correcting
its formal ID type to `s16` preserves the complete native provider and lets
the caller express the retail signed-halfword conversion directly. The
other named callers use the same argument order and types.

The frame-count providers `001991c0` and `00199500` use only the low sixteen
bits of the animation selector. Their parameters now express that halfword
domain, preserving every native instruction in their owner, including its
existing caller. All calls and declarations introduced by this recovery
agree with these provider types.

`00202120` and `00202400` now explicitly return their allocated `BtlPacket`
objects. Their callers already consume those pointers. Both return repairs
leave the provider instructions unchanged.

The five-owner package preserves 531 non-target functions in total: 70 in
the callback owner, 146 in the effect packet owner, 151 in the frame-count
owner, 41 in the animation provider and 123 in the other named caller owner.
Allocated data is unchanged in all five files. No assembly, object patching,
padding effects or altered verification criteria are used.

## Evidence

Sources, compiler receipts, native objects, relocation proofs and sibling
comparisons are retained under
`build/finish-first-party-20260922/continue-52-actions/`.
The final packages are `reviewed-clean`, `effect-packet-providers`,
`halfword-frames-provider`, `signed-animation-provider` and
`review-named-callers`. `typed-prefix` records the initial exact discovery;
`signed-animation-caller` records closure with the coherent provider types.

The resolved target SHA-256 is
`53516cbc62c41d0dbd6aa9148d1c3c850c365416e174013549e6bdaef8f1ecb8`.
Installed-source, whole-image and publication records are kept separately
under `continue-52-integration/final`.
