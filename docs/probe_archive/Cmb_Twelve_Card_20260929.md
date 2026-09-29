# Twelve-card combination layout

`func_00345700` now uses the same native `cmbSetMove`, `cmbSetColor`, and
`cmbAddPath` operations as the five already matched smaller card layouts.
Each card moves from the center to its initial point, fades in, and then
receives its own zero, one, or two path points. The subsequent flip, split
effect, return, and fade-out states preserve retail's call and update order.

The old guard interpreted decreasing scratch offsets as increasing color
channels. For example, it constructed a color at `ttmp + 0x10` and then read
`ttmp[0x0F]`, `[0x0E]`, and `[0x0D]`, outside that initialized result. The
replacement keeps constructor results as four-byte color values and passes
them through the matched color operation. It also eliminates the accidental
float-to-integer conversion when copying card 2's position into its movement
start position.

The two-position effect provider, `func_00348a90`, accepts each `CmbVec3f` by
value, followed by that position's four transform floats and color. Its
duration and mode remain between the two input groups. This follows the
adjacent one-position provider's contract: both input vectors are copied into
locals before the destination state is updated; their addresses never escape
and their storage is never modified. The corrected provider has exactly the
same retail instructions. The only authored caller is the recovered layout.

In state 6, the scale is captured before the resource getter, then written to
the returned object. This restores the saved-float lifetime visible in retail.
Using the native split-effect input groups also restores constructor-result
stack placement and the order in which the scale and call arguments are read.

Configured whole-owner comparison measures 8,764 code bytes against the
8,768-byte window, with the final four retail bytes zero. There are zero
unmasked differing bytes or words, and no wrong-symbol relocations. All 33
previously matched functions in `y_CmbCardEff.c`, including `func_00348a90`,
remain exact. The owner retains the ASM fallback for `func_0033e810`.

The reproducible reconstruction and installed-source hashes are retained in
`build/first-party-finish-20260929/worker1-fcl/`: `card_layout.py`,
`card_positions.py`, `card_value_order.py`, `install_card_layout.py`,
`card-value-order/interleaved/`, and `card-layout-installed.json`. The older
scratch-buffer body and all measurements remain in the initial baseline
snapshot and in repository history.
