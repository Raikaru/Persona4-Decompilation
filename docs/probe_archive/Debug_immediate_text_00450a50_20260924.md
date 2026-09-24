# Immediate debug text 00450a50

The immediate renderer in `src/promoted/code1_0045.c` is recovered with the
configured MWCCPS2 b210 compiler and `-O2 -Iinclude`. It emits 884 bytes in
the 896-byte retail window. All eight relocations resolve exactly; the twelve
remaining retail bytes are zero alignment.

Color and origin are genuine packed values. The definition, declaration and
both variadic callers now agree on `PackedColor4` and `PackedVec2f`. The first
caller retains the representation of its existing four-byte scale value in a
union; the second passes its existing color aggregate directly. Both callers
compile to their previous native instructions and relocation meanings.

The renderer initializes four complete 64-byte immediate-mode vertices, then
draws up to 256 non-space characters from the supplied string. Each glyph uses
an eleven-pixel rectangle, a twelve-pixel advance and one cell of the
sixteen-column atlas. The texture-coordinate pairs form a separate complete
array. The input is read through a const-qualified byte pointer.

## Source details that close the match

Near-screen depth is the field at offset eight of the render-device object
at `0x008872F0`. Representing its real owner restores the order in which the
loop's color-conversion inputs and depth expression are hoisted. The layout
follows `include/rw/plcore/badevice.h`, and the common device and vertex records
are also used by the neighboring overlay renderer.

Depth remains the original function argument instead of an unnecessary local
copy, which preserves the prologue's saved-register move. The atlas column
is materialized as a signed remainder result before conversion to float;
the atlas row uses an unsigned shift followed by a signed-word float
conversion. These separate integer domains preserve the retail byte masks
and conversion order.

The final combined owner also recovers `func_00450630`. All 58 other functions,
including both callers, retain their instruction bytes and relocation meanings.
Allocated data is unchanged, and neither new function introduces owned data.
No compiler flags, assembly fallback bytes or verifier criteria were changed.

Resolved executable SHA-256:
`2dbceec116ef58c4dd3edc65cd1bc24c9bb7c2227c35825e5dfff961dfc42cc9`.

The prior aggregate-interface experiment is retained in `continue-32/`.
New native measurements and the final shared-layout source are in
`build/finish-first-party-20260922/continue-40-font/review-pair/`.
Installed verification, whole-object linker eligibility, full-build hashes
and publication records are in `continue-40-integration/`.
