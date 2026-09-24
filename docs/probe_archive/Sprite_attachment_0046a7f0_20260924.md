# Sprite attachment transform 0046a7f0

The recovered `src/promoted/code1_0046.c` function emits 844 executable bytes
inside its 848-byte retail window with configured MWCCPS2 b210 at `-O2
-Iinclude`. All nineteen relocations resolve exactly; the final four retail
bytes are zero alignment. The complete owner compilation preserves all 57
other functions, their canonical relocations, and allocated data.

The function copies four incoming XY points into three-component working
vectors, optionally rotates them, then adds the attachment and selected sprite
record offsets. `RwV3d` arrays now represent both complete working buffers.
The transformation providers use their matrix/vector return types and the
rotation provider receives its two float arguments before the combine-mode
argument. This corrects the old decompiler prototype without changing any
neighboring native function. The input/output entry point retains its existing
pointer ABI.

## Two source boundaries that close the remaining differences

The retained `sine-cubic-product` proposal had eighteen resolved differing
words. It already represented the final sine product using a consumed cubic
intermediate. The attachment Y calculation still scheduled its integer table
load ahead of the coordinate additions. A named subtotal updated with the
table value, then stored into the output, reproduces the required load and
addition order. The same result is obtained by copying the subtotal into a
second consumed local. Either form removes sixteen differing words.

The last two differences were the branch polarities in the angle-wrap test.
The accepted source retains a negated greater-than result as an integer value
and then tests its negation:

```c
notAboveUpper = !(angle > 180.0f);
if (!notAboveUpper) {
    angle -= 360.0f;
    wrapped = 1;
}
```

This source produces the retail `c.ole.s`, `bc1f`, `xori`, and `bnez`
sequence. Directly branching on `angle > 180.0f` removes the integer-value
sequence and does not match. The previous `!(angle <= 180.0f)` value followed
by a positive test retains the same instruction count but chooses `bc1t` and
`beqz`. All comparison, branch, and relocation words in the accepted native
function were checked, rather than relying on a presumed source-level
equivalence for unordered floating-point inputs.

The scoped `opt_loop_invariants on` setting retains the original loop's
constant lifetimes. No register binding, arithmetic assembly, fabricated
effect, patched instruction, or inserted padding is used.

## Preserved original behavior

Retail writes only X and Y before passing the working vectors to the rotation
provider. The original Z component is unwritten. The recovered source documents
and retains that behavior; it does not introduce an extra initialization.
The vector-copy loop still copies all three components after the transform.

## Evidence

The fully resolved executable SHA-256 is
`af64de426dadad09cadb303ef45f49f14791df54df0f810fb2d30671ea4f08a6`.
The source, compiler receipts, native objects, full relocation proof, sibling
checks, and rejected measurements are retained under
`build/finish-first-party-20260922/continue-43-code46/`.
`greater-negated-value` is the discovery; `review-vectors` proves the complete
working vectors; `review-self-update` proves the consumed Y subtotal.
`reviewed` contains the final source and native evidence. The superseded floor
comments are retained as `archived-floor-comments.txt`.

The installation preflight also found the existing ring helper
`func_004604d0` referenced an unlisted constant, `fGpffff84f0`. Both native
GP-relative references independently resolve to `0x007615e0`; the real
`recover_symbols.py` decoder and consistency filter produced the same result.
The curated evidence and generated alias let the complete source object link.
The scoped generation preserves every pre-existing generated symbol entry.
Installation, symbol checks and publication receipts are retained under
`build/finish-first-party-20260922/continue-44-sprite/`.
