# Retained color and sphere recovery, 2026-09-22

These proposals recover two uninstalled first-party functions from the retained
zero-difference index. They were prepared against the 457acdb source baseline in
`build/first-party-publish-latest`. Production was frozen while prime completed
the preceding publication batch; this worker changed scratch files only.

The complete source, compiler, dependency, object and proof mapping is
`build/finish-first-party-20260922/retained-worker6-01/FINAL_HANDOFF.json`.
Its explicit source patches are `color-family.patch` and `field-query.patch`.
The combined patch also installs this note. The exact new-source native jobs
are retained in the same lane and must not be rerun merely to reconstruct a
receipt. Publication must bind these exact source bytes after installation.

| Function | Native bytes / retail window | Resolved relocations | Official owner result | Preserved siblings |
| --- | ---: | ---: | --- | ---: |
| `func_001496c0` | 1504 / 1504 | 14 | 123 MATCH, 3 ASM | 125 |
| `func_0016abc0` | 1216 / 1216 | 30 | 15 MATCH, 1 ASM | 15 |

Both targets have zero differing resolved bytes and no alignment suffix.
Allocated owner data is unchanged. The configured compiler is
`D:/mwcps2-3.0.1b210-060308/mwccps2.exe`, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`, with
`-O2 -Iinclude`. No build, profile or vendor implementation was changed.

## Color: why the retained exact source was not installed

The source at
`build/continue-first-party-20260922/resource-transform/color001496c0-post-rebase/final-native/code1_0014.c`
was exact, but ended the recovered function with `}// FUN_00149CA0`. The marker
scanner therefore omitted `func_00149ca0`. The old family closure scanned 125
functions and reported 122 MATCH / 3 ASM, then failed the assertion expecting
123 MATCH / 3 ASM before it could write `prepared.json`.

The new source separates the closing brace and marker and repairs the reference
to the previously absent provenance note. The source hash is
`8f4cf6ad5270e3070d9cf543fd9d16d7b1e779f4b56e48175a1a709b7fcc5491`.
Its newly compiled object is byte-identical to the retained object, SHA-256
`eafb8a3a8edc0bb7c6a5ac70609deaad3cea99228771f878d2871ed011b4cc80`.
Official verification now sees all 126 function markers.

The color operation reads four float factors, visits the resource list, updates
visibility, scales the four base color bytes, clamps the unsigned channels to
255, and scales the packed fog channels. The packed fog construction casts
bytes to `u32` before shifting, including the 24-bit shift. The actual model
color provider at `src/promoted/code1_0015.c:191` accepts `u32 *resource` and
`const f32 *color`; the caller declaration now agrees. The color function's
`void *` entry contract agrees with the existing `btlMain.c` and `btlEPL.c`
callers, whose arguments hold the four float factors.

### Complete unsigned setter contract

The retail setter at 00457140 stores the low byte of each argument to GP
offsets -0x4578 through -0x4575. The four stores do not alone distinguish
signed and unsigned C declarations. Its calling family supplies unsigned byte
loads, values masked with `0xFF`, and constants including alpha 255. Together
these establish the unsigned RGBA argument contract. The obsolete definition
used `s8` and several callers used `s32`. The proposal changes the provider and
every first-party declaration of this setter to four `u8` arguments.

| Owner | Evidence and source correction |
| --- | --- |
| `src/promoted/code1_0045.c` | Four retail `sb` stores; change the setter definition from `s8` to `u8`. |
| `src/promoted/code1_0014.c` | Scaled channels are clamped and masked; new caller uses the same unsigned contract. |
| `src/Event/evtMain.c` | Call extracts packed channels with byte masks; correct its declaration. |
| `src/Kosaka/k_command/k_command.c` | `func_001783b0` masks each command value with 255; its two retained channel locals become `u8`. |
| `src/promoted/code1_0018.c` | Guarded `func_0018f950` passes byte-valued constants, including alpha 255; correct its declaration. |
| `src/promoted/code1_001b.c` | Guarded `func_001ba0e0` masks each interpolated channel; four channel locals become `u8` and the setter declaration agrees. |
| `src/promoted/code1_0033.c` | Three calls pass `(0, 0, 0, 255)`; correct the declaration. |
| `src/promoted/k_fldEvent.c` | RGB comes from byte fields and alpha is zero; correct the last argument from `s32` to `u8`. |
| `src/promoted/k_fldEnvironment.c` | Already declares four `u8` arguments; authenticated and verified without a source change. |
| `src/evtMisc.c` | Already declares four `u8` arguments; authenticated and verified without a source change. |

The two local-width changes represent values already bounded to 0..255, with
no new masking or invented state. Both guarded caller bodies were separately
authenticated from their saved native receipts and their complete function
and data contents compare unchanged. This is not a private caller declaration
chosen in conflict with the provider.

The base-color getter `func_00457160` actually returns `s8 *` from the provider.
The new color function agrees with that declaration, then views the object
representation as unsigned bytes. The setter storage declarations and other
getter families are not changed by this proposal.

The retained family was checked against the current source and dependency
closure. Eight of its ten owner input closures were unchanged. The current
`include/shd_misc_internal.h` differed for `code1_0045.c` and `code1_0033.c`;
new scratch compilations for those two owners replace reuse of their stale
dependency receipts. Both preserve all functions and allocated data. The
other seven family owner jobs were reused after authentication; the color
target itself received the new marker-corrected compile. No saved native job
was rerun.

## Sphere query: reject the old callback change, retain the original omission

The indexed `sphere-facing-aggregate-parameters` source is not suitable as a
whole-owner installation. Its query is exact, but the added
`fldFrameRejectFacing` helper changes `func_00169a30` to 1740 bytes in a
1680-byte window. It also evaluates the direction argument by value before
the helper can test the mode. The earlier fourteen-word defined-callback
frontier documented a different, guarded computation and was likewise not an
exact replacement for the live callback.

The new proposal keeps the current callback computation and removes the
aggregate helper. Its complete native callback bytes and relocations remain
unchanged. It copies the retained query's real collector, intersection and
aligned 128-bit payload representation, with explicit notes for omissions
visible in the retail instructions. The proposal source SHA-256 is
`2eec487ad04266caf2023a27c204575d92cd40da15524e91102b5a5ccd5dd66d`;
the object SHA-256 is
`ba33254e13eb3977126ce6b92b38346ba8076f9ea60fca1da1194b6cf01b2505`.

### Direct omission evidence

The collector begins at query SP+0xB0. The following coverage is read directly
from `asm/nonmatchings/k_fldFrame/func_0016abc0.s`, including loop bounds and
the 12-byte sizes passed to the clearing routine. Addresses below are relative
to the collector unless explicitly prefixed with SP.

| Instructions | Writes before first dispatch |
| --- | --- |
| 0016AC68..0016ACC8 | 64 points at +0x000..+0x2FF and 64 normals at +0x300..+0x5FF are cleared; distances +0x600..+0x6FF receive the threshold; flags +0xA00..+0xAFF become zero. |
| 0016ACCC, 0016ACD0 | Hit count +0xB08 and count +0xB04 become zero. |
| 0016ACD4..0016ACF8 | Seven words are copied from SP+0xC10 to SP+0xBC8, the intersection at collector+0xB18. |
| 0016ACFC..0016AD0C | A separate 12-byte vector at SP+0xBE8 is cleared. This is not the direction at SP+0xBBC. |
| 0016AD24..0016AD40 | Mode +0xB00 becomes one; the collector pointer SP+0xB0 is passed to the clump enumerator. |

None of those operations initializes direction +0xB0C..+0xB17. Before the
enumerator dispatch, the only other calls are resource lookups, which receive
numeric list identifiers, and the bounded clears described above. The adapter
`func_0016a0c0` writes the atomic at +0xB34 and passes the collector and its
intersection to the triangle enumerator; it does not initialize direction.

In the unchanged retail callback, 00169B14 loads direction.z from +0xB14,
00169B1C loads direction.x from +0xB0C, and 00169B24 loads direction.y from
+0xB10. The multiply/add and comparison occur at 00169B28..00169B3C.
Only afterward does 00169B44 load mode +0xB00 and 00169B48 test it. These reads
therefore occur even for the mode-one query that supplied no direction.

There is a second original omission in the intersection payload. The query
writes four sphere words at SP+0xC00..0xC0F, copies them as 128 bits to
SP+0xC10..0xC1F, and writes type three at SP+0xC28. The seven-word intersection
copy includes the two unused payload words at SP+0xC20 and SP+0xC24, which
retail has not initialized. The descriptor's sphere form uses its first four
words; `func_00394e70` dispatches type three to the sphere handler at
00394F4C..00394F58.

The C proposal explicitly preserves these original omissions under the user's
retail-defect allowance. It does not claim initialized values, a runtime
invariant that excludes the path, or fully defined portable-C behavior for
the unwritten direction. No zero initialization, allocation barrier, ordinary
assembly, artificial padding array, or incompatible callee prototype was
introduced to reproduce the callback. The independent 12-byte clear and
aligned payload storage correspond to observed retail operations.

### Provider and caller contracts

`func_00155280` actually returns `s32 *` in `src/promoted/code1_0015.c`.
`func_003e9700` is `RwFrameGetLTM`, declared and implemented as
`RwMatrix *(RwFrame *)` in `src/renderware/core/baframe.c` and its public
header. `func_00457120` returns the existing `s32` address value in
`src/promoted/code1_0045.c`; the field owner explicitly converts that address
through `uintptr_t` for pointer access. The `RwFrame` and `RwMatrixTag` forward
declarations match the provider's tags.

`func_0047a310` is `mdlGetClump(void *)`, implemented in
`src/mdlManager_grouped.c`, returning the pointer at model+0xDC. Both the
query and the same owner's guarded movement caller use that actual pointer
contract; the movement caller's model-pointer loads remain at the same field
offsets. Its assembly fallback remains selected. `func_0016b080` retains the
existing `(const RwV3d *, f32, RwV3d *, RwV3d *)` query call, and its full
native contents remain unchanged. There are no provider implementation or
shared-header edits in this frame proposal.

## Verification boundaries

All official proposal reports reused only their authenticated exact-source
native objects; this does not claim that frozen production was already
updated. Each changed owner's before-source hash is in the handoff manifest.
Prime must install after lifting the freeze and bind the installed bytes to
these receipts before adding the two functions to published progress.

The target linter scanned both whole owners with zero errors and four H003
optimization advisories. Three refer to existing sibling controls. The fourth
is the query's scoped loop-invariants setting, carried with propagation-off
from the authenticated exact source. The matching native compile is evidence
for that complete profile; no new claim about an individually removed control
is made. Prior field and color probe directories and their rejection evidence
remain unchanged.
