# Camp menu renderer 0012d630

The recovered `src/promoted/code1_0012.c::func_0012d630` uses the actual menu
and tween records, the existing renderer interfaces, and ordinary C. The
configured native b210 `-O2 -Iinclude` candidate emits 1,348 executable bytes
against the 1,360-byte retail window. All 13 relocations resolve to the retail
destinations, and the final 12 retail bytes are zero alignment padding.

## Behavior and storage

The four transition states advance the frame and update eleven 48-byte tween
records. States zero and two retain the early transition request. Opacity is
read after each update, and a nonzero opacity keeps the completion result clear.
Rendering follows the state update, including states outside the four handled
cases. The visible menu options use the current selection and their original
normal/selected sprite banks. The selected background, number and information
panel are drawn afterward in the original call order.

`func_0012d410` initializes three banks of seven sprite pointers and filters
the seven possible option IDs into the visible list. The renderer's final row
index is that visible count, so its selected-background tween is inside the
eleven-record array. The recovered menu view is 0x2A4 bytes, matching the
distance between the menu at parent+0x18 and the next panel at parent+0x2BC in
`src/Camp/cmpMain.c::func_0012cd90`. Compile-time checks retain that extent and
the 0x30-byte tween size.

The earlier candidate overlaid an alpha-first padded record at menu+0xAE.
The final body instead accesses a complete `CampMenuTween`, whose actual alpha
and vertical scale fields are at offsets 0x1A and 0x26. A consumed unsigned
byte-offset local preserves the target's 32-bit address computation. No extra
storage, unused value, empty assembly, or fixed register is introduced.

## Contracts and evaluation order

The caller retains `s32 (u8 *menu)`. The local declarations agree with the
existing `func_0034f320` sprite renderer and `func_0034f9d0` information renderer
in `src/promoted/code1_0034.c`. In particular, opacity is a `u32`, scales are
`u16`, and the information call places its floating depth before its integer
color argument. The number renderer uses the existing shared `Vec2f` contract.
The owner declaration of `func_001437b0` now matches its actual `u8 *` tween
input in `src/promoted/code1_0014.c`.

The scoped `opt_propagation off` setting retains the selected sprite and alpha
snapshots before preparing the remaining call arguments. Keeping the real menu
pointer before the completion-result declaration and assignment preserves
their original saved registers. Explicit byte-valued metadata colors close
the two remaining color-load/zero-depth ordering pairs. The integer-to-float
label Y conversion remains ahead of the following float load.

All provider calls and relevant reloads stay at their retail points. There is
no reassociation of the coordinate arithmetic or assumption that a rendering
callback is pure. The dead constant condition wrappers in the old draft were
removed without changing any generated instruction.

## Evidence

New work is retained under
`build/finish-first-party-20260922/resume-457acdb/camp/`.

| Candidate | Fully resolved differing words | Executable bytes |
| --- | ---: | ---: |
| Prior typed selection snapshot | 8 | 1348 |
| Staged input/result with propagation disabled | 4 | 1348 |
| Explicit metadata byte snapshots | 0 | 1348 |
| Complete tween with a direct array index | 1 | 1348 |
| Complete tween with the actual byte-offset lifetime | 0 | 1348 |

`complete-tween-explicit-offset/` contains the exact candidate source, native
object, full resolved comparison, all 81 sibling checks and the independent
target proof. Its source cleanup is retained in `install-complete-tween/`,
including the original source and superseded floor notes. `production-closed/`
is the final current-source native and official verification destination.
The owner gate requires all 81 other functions' complete bytes and canonical
relocations and all original allocated data to remain unchanged.

The direct references inspected were the complete retail fallback assembly,
the current IDA and Ghidra exports, the menu initializer and sole active
external caller, and the actual tween/sprite/number/information providers.
No gameplay or emulator execution is claimed by these compiler proofs.
