# KClump indexed integer-property result: installed contract

The installed `KClumpIntPropertyResult` is an eight-byte result containing
an `s32 value` followed by an `RwFrame *frame`. Its shared declaration is in
`include/Kosaka/k_clump_property_internal.h`; the provider, its recursive
callback, and all eleven live call sites use that same contract.

The integration adds **one recovered function**, `func_00190c10`, described
in [the texture-strip recovery note](TexStrip_00190c10_20261005.md).
The provider/callback and two field-resource caller functions already
matched before this type integration. Their instructions remain unchanged.
`KClump_property_result_20261005_receipt.json` retains the final source and
object hashes, all five target relocation proofs, allocated-section
invariants, owner statuses, the call-site inventory, and lint findings.

## Provider and callback contract

`func_00458430(result, object, name, index)` obtains the root frame from
`object + 4`. It clears the complete `0x54`-byte search context, copies the
property name, and records the requested index. It visits the root's named
integer user-data elements first, then traverses child frames with
`func_003e9af0` and `func_004582c0`. The index counts matching integer
elements across that traversal. A successful lookup returns the integer
and the frame on which that element was found. A miss copies the cleared
result: value zero and a null frame on the target ABI.

The private context has the following complete layout, with no added
padding fields:

| Offset | Field | Size |
| --- | --- | ---: |
| `0x00` | `nameCopy` | `0x40` |
| `0x40` | `targetIndex` | 4 |
| `0x44` | `currentIndex` | 4 |
| `0x48` | `found` | 4 |
| `0x4c` | `result.value` | 4 |
| `0x50` | `result.frame` | 4 |

The header asserts an eight-byte result, and the provider asserts a
`0x54`-byte context. Retail clears exactly `0x54` bytes at `00458468`.
The root hit stores the integer at `0045850c` and the root frame at
`00458510`. The callback stores the integer and current frame at
`00458388` and `0045838c`, then sets `found` at `00458394`. Its initial
found check prevents later callbacks from replacing the selected result.
The frame iterator's full retail body follows the child link at `+0x98`
and the next-child link at `+0x9c`, stopping when the callback returns null.

The underlying user-data providers were reviewed in
`src/promoted/code1_003b.c` and `src/rw/rpusrdat.c`:
`func_003bcf10`/`func_003bcf60` enumerate the frame's user-data arrays;
`func_003bd040`, `func_003bd050`, and `func_003bd060` read their name,
format, and element count; `func_003bd070` reads an `s32` element.
The selected format is `rpINTUSERDATA`, whose value is one.

Both provider exits use ordinary `*result = context.result` assignment.
MWCC implements this eight-byte aggregate copy using two `lwc1`/`swc1`
transfers at `00458514..00458520` and `00458584..00458590`. These copy the
integer and pointer representations without floating-point arithmetic or
conversion. The removed `RwV2d` view and `f32 *` provider declaration are
unnecessary: the real aggregate emits the same instructions. Every call
supplies storage for both words, even when only `.value` is consumed.

## Eleven live call sites

There are eleven call sites in three caller functions, across two owner
files. The generated decompiler mirrors are excluded from this live-owner
inventory. Each source call was paired with its resolved retail `jal`;
the property strings below were also read from the retail image.

| Caller | Retail call | Output | Property | Consumption |
| --- | --- | --- | --- | --- |
| `func_00151580` | `00151604` | `spA0` | `per3FieldObjectResid` | Validate and compare resource ID. |
| `func_00151580` | `00151640` | `spA8` | `per3FieldObjectType` | Compare type; return the owning frame. |
| `func_00151580` | `0015165c` | `sp98` | `per3FieldObjectCollis` | Write the collision flag. |
| `func_00151710` | `0015177c` | `sp1F8` | `per3FieldObjectId` | Gate the entry and select resource names/IDs. |
| `func_00151710` | `001517a4` | `sp1E8` | `per3FieldObjectResid` | Validate and store resource ID. |
| `func_00151710` | `001517fc` | `sp1E0` | `per3FieldObjectCollis` | Set the collision flag. |
| `func_00151710` | `00151840` | `sp200` | `per3FieldObjectType` | Select resource kind; retain its frame. |
| `func_00151710` | `00151bd8` | `sp1F0` | `per3FieldObjectAnim` | Merge animation flags for type zero. |
| `func_00190c10` | `00190e24` | `kindProperty` | `per3FieldObjectType` | Dispatch kind zero or one. |
| `func_00190c10` | `00190e54` | `idProperty` | `per3FieldObjectId` | Append a kind-zero resource ID. |
| `func_00190c10` | `00190eac` | `idProperty` | `per3FieldObjectId` | Append a kind-one resource ID. |

The second word is a frame pointer. `func_00151580` returns it to
`func_00177b30` in `src/Kosaka/k_command/k_command.c`, which calls the
frame-matrix accessor `func_003e9700` before applying the position and
transform. `func_00151710` stores it at field-resource entry offset `+0x128`;
`func_00151c80` passes that stored pointer to the same accessor. Retail
`func_003e9700` returns the frame's matrix at `frame + 0x50` after any
required update. These consumers agree with the provider's root/child
frame stores. The texture updater consumes only the integer member.

## Installed-owner validation

The final actual-owner build report from the installed sources is
`build/worker-2/property-contract/final-owner-verification.json`.
It was reused after checking the exact header/source hashes, installation
proposal bytes, and final object hashes. The subsequent independent audit
reran the resolved-byte and section comparisons; it did not reinstall or
change production sources.

| Owner | MATCH | ASM | Default function records unchanged |
| --- | ---: | ---: | ---: |
| `src/Kosaka/k_clump/k_clump.c` | 18 | 0 | 18 |
| `src/Kosaka/Field/k_fldResource.c` | 20 | 1 | 21 |
| `src/promoted/k_texStrip.c` | 13 | 0 | 13 |
| Total | 51 | 1 | 52 |

The sole ASM status remains `func_0014f310`. The default-build comparison
covers all 52 function bodies and relocation records plus every allocated
section's payload, size, alignment, flags, and relocations. The field owner
also retains all 21 function bodies/relocations and allocated sections
under `NON_MATCHING`. The comparison baseline already contains the
texture recovery; it measures the subsequent shared-type integration.
The texture recovery's earlier 12 MATCH / 1 ASM to 13 MATCH transition is
recorded separately in its receipt.

| Function | Object bytes | Retail window | Zero tail | Code relocations |
| --- | ---: | ---: | ---: | ---: |
| `func_004582c0` | 356 | 368 | 12 | 10 |
| `func_00458430` | 392 | 400 | 8 | 12 |
| `func_00151580` | 388 | 400 | 12 | 15 |
| `func_00151710` | 1392 | 1392 | 0 | 83 |
| `func_00190c10` | 2476 | 2480 | 4 | 124 |

All **244 code relocations** resolve to the retail instructions, with zero
differing bytes in all five bodies. The remaining window bytes are zero
alignment. The texture owner's 36-byte switch table at `00746ec0` also
resolves all **nine `R_MIPS_32` entries** exactly. This is owner-level
validation; the prime owns the combined linked-image validation.

The independent checks use the worktree's configured
`build/venv/Scripts/python.exe` and `tools/verify_config.local.json`:

```text
build/worker-12/property_final_audit.py
tools/decomp_lint.py include/Kosaka/k_clump_property_internal.h src/Kosaka/k_clump/k_clump.c src/Kosaka/Field/k_fldResource.c src/promoted/k_texStrip.c --json build/worker-12/property-final-lint.json
```

The audit receipt is `build/worker-12/property-final-audit.json`.
Targeted lint reports zero errors and 18 existing warnings: 16 H011
declaration findings and two H003 pragma findings outside this integration.
Their exact locations are retained in the durable property receipt.
No new function credit is assigned to the type repair itself.
