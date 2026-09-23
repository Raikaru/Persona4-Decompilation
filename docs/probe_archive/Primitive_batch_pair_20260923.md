# Queued primitive batch pair

`src/sdkPrimitive.c` contains first-party drawing wrappers despite its historical
filename. Both remaining wrappers are recovered as ordinary C under native
MWCCPS2 b210, `-O2 -Iinclude`:

| Function | Emitted bytes | Retail window | Resolved relocations | Zero tail |
| --- | ---: | ---: | ---: | ---: |
| `func_0045e8e0` | 564 | 576 | 14 | 12 |
| `func_0045eb20` | 572 | 576 | 14 | 4 |

The six existing functions and allocated owner data remain unchanged. Both
new functions have their canonical source markers and no assembly fallback.

## Allocation and coordinate ownership

The batch contains a 28-byte header followed by packed four-byte color rows
and eight-byte two-float position rows. Keeping the position-byte and
color-byte counts distinct reproduces the original allocation calculation.
The allocator result first has a raw-storage lifetime, then becomes a typed
header pointer. The header's color pointer is a packed-row view, while its
stored position pointer remains untyped until each actual coordinate access.

In the transform loop, loading the stored pointer and then advancing the
typed position pointer retains retail's address calculation. The Y write
reloads the stored positions pointer. Coordinate subtraction precedes each
scale multiplication; the original product-seeded rotation expressions and
draw-queue registration remain intact. The alpha-enabled wrapper sets its
alpha byte after the loop. No initialization was added to the other wrapper.

The public input-buffer pointers remain `void *`, consistent with every
current caller. The queued callback is stored through its actual function
pointer type rather than being converted to a data pointer.

## Coherent offset contract

The alpha wrapper's native bytes alone do not distinguish a signed-word X
formal from a signed-halfword X formal: both definitions produce the same
complete native object. The legacy window caller already declares and uses
the halfword form. Simply widening that declaration changed two previously
exact window functions, so the provider-only proof was not treated as a
complete interface proof.

The integrated alpha-wrapper contract uses signed halfword X and Y offsets
consistently across all six authoritative declarations/definitions. The two
panel constructors in `code1_0036.c` already narrow their derived X offset to
a signed halfword. They now retain both real value roles explicitly: a
halfword snapshot for the alpha queue and the promoted signed-word value for
the immediate and non-alpha drawing interfaces. The numerical value is
unchanged. The other alpha caller supplies a zero X offset.

Native whole-owner comparisons prove that these coordinated declaration and
snapshot edits preserve every function and allocated data in `code1_0033.c`
and `code1_0036.c`. The window owner is untouched. The non-alpha wrapper keeps
its existing signed-word X and signed-halfword Y interface. No caller-only
alternate declaration or incompatible function-pointer cast is used to make
a call match.

## Evidence

The original worker's exact allocation recovery is preserved under
`build/finish-first-party-20260922/resume-22-primitive/`. Its final source was
reviewed further for canonical markers, public buffer types, callback typing,
and complete caller compatibility before installation.

The reviewed provider, actual-provider width experiment, all caller probes,
and complete resolved proofs are under
`build/finish-first-party-20260922/continue-22-primitive/`. The accepted caller
model is `offsets-nested/`; the halfword provider is `provider-x16/`.
`coherent-prepared.json` binds those sources and objects to their compiler,
flags, dependencies, and prior owner receipts. Current-source official
verification, full-build hashes, and real source-linked symbol checks are
recorded separately in that directory.

The final primitive object SHA-256 is
`84d14873b18f742b3535cf253408b0d5169b4fb97d4ab9b15caa7a81b55803b7`.
