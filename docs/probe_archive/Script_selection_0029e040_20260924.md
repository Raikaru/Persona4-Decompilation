# Script-selection and preview callback

Owner: `src/Script/scrScriptProcess.c`, `func_0029e040`.
Compiler: MWCCPS2 b210, `-O2 -Iinclude`.

The recovered callback emits 1,284 bytes in the 1,296-byte retail window.
All 41 relocations resolve exactly; the final twelve bytes are zero alignment.
The other 21 owner functions retain their instruction bytes and relocation
meanings. Allocated data is unchanged.

This callback handles script selection, loading, preview placement and the
selected procedure's execution state. It retains the original input reads,
coordinate adjustments, procedure search and return-code dispatch. Its filer
declaration agrees with the actual signed-word provider and size-output
parameter. Debug text uses the shared variadic declaration and reads the
packed position from the complete task storage.

The final residual was in the preview argument copies. Direct stores allowed
the compiler to defer the two argument addresses; explicit pointer stores
placed the addresses correctly but used different base registers for the
stores. Returning complete color and rectangle values reproduces both the
copy order and the stack-based stores. The color constructor copies the
existing float-sized color storage without arithmetic. The rectangle union
contains complete packed, signed-integer and float transport views, and its
value copy supplies the independent drawing argument. These helpers introduce
no extra effects or generated instructions.

The final source keeps the primitive provider's existing color-pointer and
rectangle-pointer interface. The four-byte color and sixteen-byte rectangle
stay within their complete objects. The pixel-scale products precede the
color copy; the integer coordinate stores precede the rectangle copy, as in
the retail instruction stream.

The retained near-match is under
`build/finish-first-party-20260922/continue-33-script/`.
New source experiments, unmasked proofs, reviewed source and installation
records are under `build/finish-first-party-20260922/continue-34-script/`.
Both pointer-input and value-input color constructors reached the exact
result; the reviewed source uses the value-input form. Reading the packed
debug position from the complete task byte storage was separately compiled
and preserved the exact result.

The complete build initially exposed three missing linker aliases:
`iGpffffa7cc`, `iGpffffa7d0` and `iGpffffa7d8`. Their native GP-relative
references independently establish `0x007638BC`, `0x007638C0` and `0x007638C8`.
Both symbol maps now retain those definitions. The joint linkage preflight,
installed-source checks and final publication build are recorded under
`build/finish-first-party-20260922/continue-36-batch/`.
