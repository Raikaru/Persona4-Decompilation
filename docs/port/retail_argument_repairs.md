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
