# Ribbon offset builder 004bb1d0: MATCH

`func_004bb1d0` (4112-byte window, 1027 instructions, frame 0xA0) is now C.
It is a fresh rewrite from the retail listing. The old guarded draft scored
618 words / 314 edits.

Contract change: the queue is a file-scope `EffAfterQueue` (config pointer,
count, write index, position/normal rings, four output rings). The parameter
struct `EffAfterParam` has `mid[3]`, head pair, tail pair, `width[2]`,
`alpha[2]`. `func_004bb1d0` now takes `EffAfterQueue *` (the extern uses
`struct EffAfterQueue *`), and `func_004bad70` uses the same type instead of
its local `SampleQueue` (still MATCH; `capacity` replaces the raw `+ 8` read).

Levers, in the order they closed the diff (fnalign edits):

- `queue` must be the real typed parameter. A `void *arg0` plus local cast
  swaps `$s1`/`$s2` for queue/section everywhere.
- Vector differences written as `queue->positions[ib].c[1] - ...`, with a
  local `dir` whose address goes to RwV3dNormalize, give retail's
  `addiu base,4` + `addu idx*12` per field. No manual byte offsets are needed.
- Block-scoped ring indices (`s32 ia, ib;` in each else arm and around each
  output store) fix the temporary registers of the wrap code (196 -> 63).
- FP colouring follows declaration order: first declared gets the highest
  register, and variables whose lifetimes do not overlap share. The retail
  order is `mid0, w0, w1, a1, a0, prev0, next0, scale, term, scale2, mid1,
  next1, prev1`. The following-section coefficients are separate variables
  (1119 -> 18 together with the next items).
- `term = a * func_004bc310(..); scale = scale + term;` keeps retail's
  mul + add. `scale += a * ..` fuses into adda/madd.
- In the following-section blocks retail multiplies into the width register
  (`w0 *= func_004bc1e0(..)`, then `scale2 = w0 + term`). The last block uses
  `scale2 = w1 * ..; term = ..; scale2 = scale2 + term;`.
- The four weight loads use a reused element pointer
  (`pw = &widths[sel & 1]; w0 = *pw;`). This reproduces retail's materialised
  `addu; addiu 0x78; lwc1 0(..)` (docs/matching.md, folded displacement vs
  materialised address). A single-use pointer is propagated back to the
  folded form. No pragma is needed.
