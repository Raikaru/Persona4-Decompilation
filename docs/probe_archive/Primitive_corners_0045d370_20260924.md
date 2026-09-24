# Rotated rectangle primitive builder

Owner: `src/promoted/code1_0045.c`, `func_0045d370`.
Compiler: MWCCPS2 b210, `-O2 -Iinclude`.

The recovered C emits all 880 bytes in the retail window with no alignment
tail. Its six code relocations resolve exactly. The 59 other functions and
all allocated data retain their instruction bytes, relocation meanings and
contents. Both a typed internal interface and the final caller-compatible
void-buffer interface were independently compiled and proved exact.

The function scales the rectangle dimensions, rotates its four corners about
the requested signed-halfword offsets, then writes the position, depth,
unsigned color and reciprocal projection values into four 64-byte vertices.
Its public argument order agrees with the actual caller: three buffers,
depth, two signed-word offsets, angle and two scales. The low-halfword offset
interpretation remains inside the callee, exactly as in retail.

The old draft eagerly computed four independent extents and repeatedly used
their products. The recovered source follows one local corner as it advances
through left/top, right/top, left/bottom and right/bottom. It separately keeps
the two shared integer origins, and computes the first corner's displacement
before converting its origin to float. Those real value lifetimes produce
the original fused multiply-accumulate expressions and their explicit zero
seed. They also preserve the compiler's shared vertical products without
replacing the fused horizontal arithmetic with separately rounded products.

The four corners are a complete array of two-float points. The final vertex
loop reads each complete point and writes the original fields in order.
Unused draft declarations were removed and recompiled before integration.
No assembly, register binding, extra effects or instruction patching is used.

The owning file previously lacked a linker definition for `iGpffffac78`, a
buffer referenced by its existing pad-state routine. All 60 functions were
independently proved against retail; that native reference establishes the
alias at `0x00763D68`. Recording the alias allows the complete owner to enter
the actual C link. The existing pad function's code is unchanged.

Source experiments, exact native objects and unmasked proofs are retained in
`build/finish-first-party-20260922/continue-36-quad/`.
Joint installation, alias evidence, full-build and publication records are in
`build/finish-first-party-20260922/continue-36-batch/`.
