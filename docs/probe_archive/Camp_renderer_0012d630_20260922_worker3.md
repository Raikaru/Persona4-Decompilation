# Camp renderer `0012d630`, 2026-09-22

The best new native ordinary-C candidate has **8 fully resolved differing
words**, emits **1348 bytes** in the **1360-byte** retail window, and preserves
the other **81 owner functions**, their relocations, and all allocated data.
It is not exact and was not installed. `src/promoted/code1_0012.c` remains
74 MATCH / 8 ASM.

The current baseline is the completed native owner in
`build/finish-first-party-20260922/resume-outline-01/native/src_promoted_code1_0012/`.
The target's production source hash is
`f3606adb421ae6ee2e57eb58928726d979fba7649647351b3da144766bcfcc76`;
the shared renderer header is bound to
`b3ecfe04a54e4f4665573987f00f678fe97e3b38a8fe3c81f92df362ee1e7b95`.
The configured native compiler is MWCC PS2 3.0.1 b210, `-O2 -Iinclude`.

## Best retained source and evidence

The candidate is in
`build/finish-first-party-20260922/camera-next-01/ui-0012-current/typed-selection-row-snapshot/`.
Its complete translation unit, body, object, immutable compilation receipt,
resolved target bytes, retail bytes, instruction diff and sibling checks are
retained together. The translation-unit SHA-256 is
`c7dfbbd9de0aafbdc8e096d47baff43c627c226712c925300202c1795141d1e2`;
the native-object SHA-256 is
`77728a75a87e0d10de02e26c9151a2240216c7290020bf2104307f069220f548`.

The candidate uses the actual sprite argument widths and the existing
position/depth/color order of the two metadata renderers. The selected-option
lookup uses the menu work's inspected layout, while its row metadata retains
the measured offset view. The initializer establishes seven option slots,
three arrays of seven sprite pointers, and eleven 48-byte tween records.
The label's floating conversion and addition are kept in distinct lifetimes.
The tween updater declaration is corrected to its actual `u8 *` argument;
the other functions in the owner remain byte- and relocation-identical.

The original thirteen-word census lead becomes nine words after the renderer
contract and label-lifetime corrections. The mixed selected-row layout removes
one additional operand-order difference. Explicit byte metadata helpers and
packed-vector boundaries did not improve that eight-word result; adding a
by-value selected-row helper increased the frame and regressed.

## Remaining native differences

The eight differences are at target offsets `0x438`, `0x454`, `0x458`,
`0x45c`, `0x4b8`, `0x4bc`, `0x500`, and `0x504`. Four are ordering differences
among the selected sprite/alpha loads and outgoing zero arguments. The other
four exchange each metadata alpha load with the zero-depth transfer. All
thirteen target relocations are fully resolved before comparison.

The scripts `variants_ui_01.py`, `variants_ui_02.py`, and `variants_ui_03.py`
in `camera-next-01/` each completed once. The later two were executed by the
prime in terminal session 98113 and exited zero; completed candidates must
be read from their receipts rather than recompiled. No official MATCH or
publication-state update was attempted for the nonzero candidate.
