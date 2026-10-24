# Retail argument and result repairs

The PC mirror audit at decomp `d19f9e222c96450289faa9fec9c40c24267bf4bd`
includes both upstream C and port-only implementations of upstream assembly
fallbacks. Source line numbers in that audit are mirror line numbers, not
upstream line numbers. Classification and repairs use retail function addresses.

## Argument classes

The EE assigns general-purpose and floating-point arguments from independent
register sequences. C parameter order must nevertheless agree across callers
and definitions; the host ABI cannot infer the intended order.

- `MT_Scene_CreateModelCharShadowRes` and `MT_Scene_CreateModelNpcShadowRes`:
  `FldFrameTask_Spawn` (`001684a0`) consumes two GP values and height in `f12`.
  Removing the unread third GP zero changes both callers (normalized diff 54).
  The calls retain their original spelling with explicit retail-input comments;
  the unused declaration in `code1_0014.c` is corrected.
- `0052bbd8` and its delegate `0050f538`: `SFXZ_SetZclip` (`0052c790`)
  consumes a handle and the incoming `f12`/`f13` clip planes. Declare and forward
  the planes as floats, not unrelated incoming GP values.
- `shdPersonaDrawByState`: `nLineDrawSet` is `(position, alpha, setIndex,
  depthOffset)`. A direct canonical call has normalized diff 35. An inline
  evaluation-order helper produced the same instruction residual; explicitly
  staging opacity changed the frame's register allocation and was worse.
  Both calls and the inherited declaration remain with retail-input comments.
  These two host-order fixes must remain in the port.
- `FldSmapTileQueueQuad`: `FldRc_QueueScreenQuad` (`0014def0`) has fourteen
  arguments. The surplus UV pointer occupied an unread GP register; the final
  UV value belongs immediately after the orientation parameter.
- `RpHAnimCompressedKeyFrameInterpolate`: the inherited declaration places
  interpolation fraction before the final pointer, consistent with the real
  three-GP/one-FP/one-GP interface. There is no direct call here.

The audit's rotation calls at `003d6c50`, `003d6fb0`, and `003d7cf0` are
port-only C: upstream retains `INCLUDE_ASM` for these addresses. Their mirror
repairs must remain in the port. The matrix implementation at `003e0870` is
also upstream assembly. `FldNpcControlUpdate` (`0018a200`) already declares
and calls `RwMatrixRotate(matrix, axis, heading, rwCOMBINEPOSTCONCAT)` at this
pin; there is no remaining upstream alias or argument-order fix at that site.

## File-size result widths

`004e77c0` and the `004e8058` delegate retain the full 64-bit EE `v0`;
`004e80c0` uses `dsra32` to return its signed upper word. The C declaration,
temporary and call now preserve that width and the incoming filename.
`004e7798` deliberately applies `dsll32`/`dsra32` to the low word: its C
return remains signed 32-bit with an explicit narrowing cast.

`004e3448` builds a 64-bit value from callback commands `0xc8` and `0xc9`
(`dsll32` plus `daddu` at `004e34b8`–`004e34c4`). Its inherited declaration
now preserves the full result and names the handle input. `004f14e0` returns
that value unchanged when nonzero, otherwise the signed 32-bit result of
`004f14c8`. Its guarded C attempt now states those semantics; production
continues to use its existing assembly fallback. `004f14c8` forwards the
handle and explicitly returns the transfer count.

The actual bodies at `004e77c0`, `004e8058` and `004e3448` remain assembly
fallbacks. The excluded, legacy `libadxe/htci.c` implementation is not the
retail 64-bit interface and is intentionally unchanged.

## Omitted live arguments

The forty call-site findings comprise 38 calls in active upstream C and two
in port-only active C. The latter are the unmarked RE4 reconstructions
`SFD_Init` and `mwSfdExecDecSvrHndl`: upstream's authoritative retail owners
remain assembly. These SDK reconstruction files must not be mistaken for
matched upstream definitions merely because their text is in `src/`. Of the
38 upstream sites, 37 are expressed directly in C; `003de6a0` is documented
only, as detailed below.

| Caller | Callee | Retail input |
|---|---|---|
| `004adfa0` | `004adb50` | incoming instance |
| `002b32d0` | `00442830` | first replacement-name pointer, incoming `a1` |
| `004eb228` | `004d4308` | incoming voice handle |
| `003bf2d0` | `003e5250` | incoming object |
| `003a0260` | `0039c730` | incoming object |
| `003a02a0` | `0039c730` | incoming object |
| `003a02e0` | `0039c730` | incoming object |
| `003a0320` | `0039c730` | incoming object |
| `003a0360` | `0039c730` | incoming object |
| `003a1470` | `0039c730` | incoming object |
| `003a14b0` | `0039c730` | incoming object |
| `003de6a0` (documented only) | `004275a8` | incoming buffer and low-word byte count |
| `003d0930` | `003d3e60` | incoming object, first branch |
| `003d0930` | `003d0fa0` | incoming object, alternate branch |
| `004f9130` | `004f8f60` | all three incoming key-scramble words |
| `00438fa0` | `00438e60` | all three incoming syscall words |
| `00438780` | `00439970` | incoming syscall word |
| `00438760` | `00439770` | incoming syscall word |
| `00438740` | `00439598` | both incoming syscall words |
| `005242d0` | `00524318` | incoming analysis state |
| `00278640` | `00440b68` | incoming style kind for the diagnostic format |
| `004f94b8` | `004f9130` | all three incoming key-scramble words |
| `004bd688` | `004f1278` | incoming flags pointer |
| `004be3d8` | `004df068` | incoming loop flag, alongside loaded decoder |
| `004d18b0` | `004f1278` | incoming flags pointer |
| `004d3528` | `004e7258` | incoming filename, not a no-argument close-all |
| `0050e3a8` | `00517eb8` | incoming fifth word in `t0` |
| `004eb2b0` | `004eaa88` | incoming left/right sample output pointers |
| `004e80c0` | `004e8058` | incoming filename; see result-width group |
| `004f14c8` | `004e2750` | incoming CVFS handle; see result-width group |
| `004f14b0` | `004e2690` | incoming CVFS handle |
| `004f1448` | `004e2240` | incoming CVFS handle |
| `004f1430` | `004e2170` | incoming CVFS handle, sectors and destination |
| `004f1418` | `004e20a0` | incoming CVFS handle |
| `00422460` | `00421580` | incoming interrupt cause |
| `00422480` | `00421590` | incoming interrupt cause |
| `004224a0` | `004215a0` | incoming interrupt cause |
| `004224c0` | `004215b0` | incoming interrupt cause |
| `SFD_Init` (port-only active C) | `00525488` | existing `p1`, read from `prm->prm1`, not a constant |
| `mwSfdExecDecSvrHndl` (port-only active C) | `0050c5e8` | existing `mwply` handle |

The four intentional audit exclusions remain unchanged: RE4 debug-name tails,
the skin identity no-op, opcode-specific ignored sound packet tails, and
inactive `NON_MATCHING` source. No invented padding arguments are added.

### Write-wrapper codegen exception

At `003de6c0`, `sceWrite` receives the unchanged incoming buffer in `a1` and
the count in `a2`, while its delay slot preserves the original 64-bit count
in `s1`. Adding both arguments with the actual 32-bit syscall count type
changes the function (normalized diff 116). `micro_codegen.py` confirms that
both a direct `(s32)` cast and a named 32-bit count produce the same extra
`dsll32`/`dsra32` conversion; the retail call has neither instruction.
Changing the syscall's count to 64-bit would introduce a conflicting ABI
instead of fixing it. The original call remains with a short retail-input
comment, and the port retains its two explicit syscall repair rows.

## Style diagnostic width

The style diagnostic forwards the full incoming kind, while its field store
narrows to signed 16-bit. Keeping `kind` as a narrow formal moved the store's
temporary into `a1` (normalized diff 4). The matching form uses a 32-bit
formal in both style wrappers, an explicit `(s16)` only at the field store,
and the actual 32-bit `itfMesWindowSetProcedure` declaration. All 125 functions
in the three affected caller/owner units matched with this form.

## Smap aggregate inputs

`smapWorldToColumn` (`002b11c0`) and `smapWorldToRow` (`002b1210`)
retain their by-value `RwV3d` definitions. MWCC implements that aggregate
parameter through an address and emits the retail three-lane copy prologue.
Changing the definitions to pointer parameters would remove that prologue.
The two declarations and calls in `y_misc_inferred.c` instead use the same
aggregate type as the definitions and the existing `y_symbol.c` callers.
`YVec3f` in `y_smap.c` is already a typedef of `RwV3d`.

The port still needs its pointer-ABI adaptation for these helpers on host
compilers. That is a platform adaptation, not evidence that the matched
aggregate-copy definitions should be replaced in the decomp.
