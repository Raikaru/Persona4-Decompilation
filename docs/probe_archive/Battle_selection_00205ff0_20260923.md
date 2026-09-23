# Battle-selection renderer: `func_00205ff0`

The recovered renderer in `src/promoted/code1_0020.c` emits 3,548 bytes in its
3,552-byte retail window under native MWCCPS2 b210, `-O2 -Iinclude`. All 28
native relocations resolve to retail, and the remaining four bytes are zero
alignment padding. Its 145 sibling functions and all allocated owner data are
unchanged. The renderer owns no additional data section.

## Source recovery

The earlier 86-word residual was entirely floating-point register allocation,
not missing drawing operations. Recovering actual work-variable lifetimes
closed it without binding registers or rewriting the native object:

- The four-frame divisor becomes the vertical edge-coordinate work after its
  last division. The clipping-edge X value later becomes the selected panel's
  horizontal slide displacement.
- The shared unit bound later becomes the scroll-arrow X coordinate. Some
  complements retain separate literal operands, matching retail's independent
  materializations rather than replacing every `1.0f` with the shared bound.
- The easing slope becomes selected-row progress, then the rescaled opacity
  progress after its earlier value is dead. The incoming horizontal scale has
  a real local snapshot; after the scale-setting call it can be reused for the
  selected row's vertical displacement. Their declaration order is material
  to the observed b210 allocation.

The primitive wrapper copies four float-sized words, then its builder
interprets them as signed rectangle coordinates. The renderer now supplies a
complete sixteen-byte union with integer-coordinate and float-word views.
Its twelve-byte unused gap places the separate four-byte color object at the
retail stack offset `sp+0xFC`; no value is invented for that unused storage.
The callback contract, signed selection fields, draw calls, clipping updates,
and conditional shared callback site remain intact.

## Retained evidence

The discovery and reviewed candidates are preserved under
`build/finish-first-party-20260922/resume-21-code20/`. The final installable
package is `renderer-final/`, with its native compile receipt, complete
resolved target proof, and source bound by `renderer-prepared.json`.

Final source SHA-256:
`e8be4e70545e7bb1c3a976efec2f9e5c24b91cb92c30261f6491893915e34605`.

Final native object SHA-256:
`153e7b3646ef23532b9fbbaafc09a2f39228b781963454dec7d113c7da182dcf`.

Current-source official verification and whole-image integration are recorded
separately under `build/finish-first-party-20260922/continue-22-integration/`.
The remaining rotated-strip function `func_00204dc0` is not part of this
recovery and retains its assembly fallback.
