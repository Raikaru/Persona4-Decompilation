# Model setup forwarding and field predicate result

The September 21 continuation completes two provider contracts required by
the field-unit recoveries. Both changes were compiled in the actual current
owners with configured MWCCPS2 b210, `-O2 -Iinclude`, and checked against the
retail executable before acceptance.

## Model setup callback

`func_0047d140` forwards its model pointer to the fourth callback registered
by `func_0047d090`. Retail preserves the incoming argument through the
indirect call at `0047D14C`. The actual callback, `func_00230d30`, accepts
`void *`, returns `s32`, and reads the model fields at `+0xD4/+0xD6`.

`include/model_callbacks_internal.h` now describes the registration's five
function-pointer arguments and the model-setup forwarding interface. The
registration site agrees with the actual name/path, type, setup, and data
providers. The fourth stored callback retains its complete function type,
and the forwarding wrapper explicitly supplies its model argument.

The two calls in guarded `func_00162680` now supply the constructed `var_20`
model, as retail does at `00162994` and `00162B28`. The battle caller already
supplied its model; it now sees the shared declaration. The field-unit owner
uses the same header for its separately verified `func_001679d0` recovery.

The four provider/registration/caller owners preserve their complete default
objects: 38 functions in `code1_0047.c`, four in `mdlApp.c`, 64 in
`code1_0016.c`, and 41 in `btlUnit.c`. Actual-source official verification
reports **142 MATCH and five ASM across 147 functions**. Registration,
callback dispatch, and the callback-registration initializer are also checked
after applying their code relocations. The separately enabled guarded
`00162680` and `0019ae20` bodies preserve call order and unrelated functions
and data; the former now materializes its two previously omitted arguments.

The other four legacy dispatch wrappers retain their existing interfaces.
This record establishes the setup callback and registration argument types;
it does not claim a complete reconstruction of the other dispatch wrappers.

Evidence is under
`build/first-party-finish-20260920/model-callback-closure/typed-registration/`.
`proof.json` records immutable proposed-owner comparisons; `current/proof.json`
and `current/official.json` bind the integrated sources, transitive headers,
compiler identity, compiled objects, and relocation proofs. The original
integer-address registration experiment is preserved separately; its
registration-site code changed and it was not accepted.

## Field predicate return

Retail `func_0014a160` loads the current field identifiers, calls
`func_0014a190`, and returns its result unchanged. The source previously
declared this wrapper `void`, while its real callers already consumed an
`s32` result. It now returns `s32` explicitly, and the one conflicting local
declaration in guarded `func_00148280` agrees. No caller argument or branch
has been changed by this provider correction.

The entire 126-function owner remains byte-identical in both its default
compilation and a separately enabled `00148280` compilation. The corrected
wrapper is **44 bytes in a 48-byte window**, with two resolved relocations;
its predicate provider is **104 bytes in a 112-byte window**, also with two
resolved relocations. Both omitted suffixes are retail zero alignment.
Actual-source official verification reports **120 MATCH and six ASM**.

Evidence: `build/first-party-finish-20260920/field-query-return/`, including
`proof.json`, `current-proof.json`, and `current-official.json`. The guarded
`00148280` reconstruction still has its previously documented missing result
test; declaring the wrapper correctly does not itself recover that caller.
