# Title rendering and ANALYZE action

Two recovered C functions replace their assembly fallbacks against publication
`c7c8734ada7452fd69a38b9ca3788b78fbd232b7`. No provider implementation or shared
header changes in this batch.

| Function | Source owner | Native body | Retail window | Zero tail |
| --- | --- | ---: | ---: | ---: |
| `00124f70` | `src/promoted/code1_0012.c` | 3,852 | 3,856 | 4 |
| `001a24b0` | `src/promoted/code1_001a.c` | 1,564 | 1,568 | 4 |

## Title rendering

`00124f70` renders the title's background, model layers and sprite. Its palettes
contain six packed four-byte colors. Complete 24-byte palette assignments through
byte-storage parameters let the native compiler emit the original copy loops and
retain the selected color at the real copy boundary. A complete four-byte color
union assignment similarly preserves the rectangle argument's address before
the color load and store. Compile-time checks bind those object sizes.

Every helper carries an actual color, palette or draw argument. There is no
assembly body, forced register allocation, dummy memory, uninitialized helper
state or hidden extra function. The compiler inlines the helpers in the scoped
`always_inline` region. The recovered code keeps the complete brightness word
in its final color OR and preserves the earlier channel conversions and stores.

The actual five callee contracts are checked against the current model,
rectangle, sprite and render-state providers and the RenderWare declaration.
The retail renderer has three direct call sites: one supplies a variable title
index and converted fade brightness with mode 1; the other two pass index 10,
brightness 255 and mode `0x40`. Each supplies the scene pointer stored at offset
`0x38` of the renderer's second-argument task. The actual `00452560` accessor
loads that pointer; the scene is not inline task storage. The channel conversions
are defined over brightness 0 through
255; arbitrary high-bit values are not included in that domain merely because
the final expression retains a full word.

The final native object matches the first exact object byte-for-byte after
replacing the obsolete probe comment and adding the two size assertions. All
81 sibling windows and all allocated data remain exact.

The unchanged title body and helpers pass 58,368 native scenarios at each of
O0 and O2 with 32-bit pointers, strict aliasing, and undefined-behavior, bounds
and float-conversion traps. The cases cover all 19 authenticated layout records,
all 256 valid brightness values, six mode values and two distinct scene contexts.
Four unused-argument boundary values cycle through those cases. An independent
oracle uses exact rational arithmetic rounded to binary32 after each division
and multiplication, the retail palettes and layouts, and the expected sequence
of 13 provider calls. It checks colors, flags, geometry arguments, scene views,
and unchanged scene and global data images. Both optimization levels produce
the same trace.

Twelve palette checks and ten color bit-pattern checks cover complete copies,
returned pointers and surrounding guards. Wrong palette selection and truncated
copy controls are rejected. A separate 54-case fixture executes the unchanged
terminal opacity statements and rejects a narrowed brightness word. That control
passes the normal full-function cases, so its high-bit coverage is explicitly
limited to the terminal statements. Brightness -1 and 256 trap in separate full
function domain probes at both optimization levels. The rendering providers are
instrumented boundaries; these native tests do not execute the PS2 graphics
backend or establish arbitrary out-of-range title inputs.

## ANALYZE target selection

`001a24b0` is the update callback for state-table entry 7, named ANALYZE. The
entry at `0x005f6e74` identifies initializer `001a24a0` and this update callback.
The initializer selects internal phase 1. The existing dispatcher calls the
update with one action pointer.

The four phases open the unit-selection UI, wait for its resource result, cycle
or confirm the selected unit, and restore the previous action state. The source
keeps full packet UIDs, separates the stored signed-short cursor from its widened
slot index, and uses the original cursor for wrap detection. Confirmation passes
1 to `00212240`. The archived draft compared controller bits as wrap bounds and
passed 0 at that boundary.

The owner now declares `001f9a50` with the actual provider's `(s32, s32)`
parameters. Its caller still explicitly narrows the nonnegative resource result
to `u16`, as retail does. The scoped loop-invariant option preserves retail's
hoisted scan value and unsigned wrap bounds. All 25 direct provider contracts
agree, all 70 peer functions are unchanged, and lint has no errors or added
findings.

The native fixture executes the unchanged action and four source helpers with
32-bit pointers, undefined-behavior traps and bounds traps. O0 and O2 each pass
75,539 scenarios: all 16-bit input masks; the four phases; populated lists of
1 through 12 targets; forward and reverse wrapping; equal and distinct unit
identifiers; complete UIDs; busy, null and blocked paths; and resource narrowing.
Four negative controls reject a wrong wrap bound, wrong confirmation argument,
truncated action UID and missing resource narrowing. An independent oracle
checks callback ordering and complete action, battle, task-work and packet
images. Allocation, query, voice and some UI services are controlled boundaries;
this is not full-game execution.

## Complete-owner and integration evidence

The two fresh publication objects equal their sealed native objects. Full
relocation resolution covers 153 function windows, preserves 151 peers, and
checks 2,999 text relocations, 111 data relocations and 564 allocated data bytes.
Every executable section byte is accounted for; gaps and the two window tails
contain only zero alignment bytes. No relocation-masked result is used to accept
either match.

The complete verifier checks 13,102 markers in 959 owners. It recompiles the two
changed owners and authenticates the current source, dependencies and retained
objects of the other 957. Only these two functions move from ASM to MATCH:
first-party progress is 6,702 MATCH and 159 ASM out of 6,861; the complete report
is 9,522 MATCH and 3,580 ASM. There is no compiler-input drift.

The complete build and independent final link check pass. Both targets are
present as C from their intended owners, and all previously linked source
functions remain present. The load-image SHA-1 is
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete executable SHA-1 is
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Both equal retail.

Private source and proof packages are retained under
`build/cos20335-recovered-turn/title-action-package/`,
`title-palette/probes/publication-title/`, and
`battle-actions-next/sealed24b0-ready/` in the workspace root. The publication
checkout retains its own complete integration receipts in
`build/batches/title-action-v1/`,
`build/publication-verification/title-action-v1/`, and
`build/publication-gates/title-action-*`.

| Evidence | SHA-256 |
| --- | --- |
| Combined source patch | `3d38bb6c3cfcc6707308f5fb820c551d92f81b0349992532746da29175b98591` |
| Title owner source | `19a07ab3c64dca9fc1c633dd5a622eab427ff62104565fe8352a8fc4d560a906` |
| Title owner object | `a5db175a0dc64bf2d5c8951b7635f585ba3e29aafb2b045a6f280c69d4c34113` |
| Complete title window | `8fc5ab1ddf822fcac3af00df7b6977c2957204b44aa4203bda4a0eb99b35e07b` |
| Action owner source | `c6a043a2cc93a059033d7f918f36b8786910ac24b882c7b0033c01d2ddc67e10` |
| Action owner object | `2d001e850eab241e0f7d1bd14f5095b262660199857a1eef7444f19303707aca` |
| Complete action window | `2aa189af64f440082f205d598ae152bcfac78f62f224f2c5de2dd6bef8cbd33f` |
