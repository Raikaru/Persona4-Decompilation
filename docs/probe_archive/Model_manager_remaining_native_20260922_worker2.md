# Model manager remaining-function audit, 2026-09-22, worker 2

No new source closure. `src/Graphics/Model/mdlManager.c` is unchanged. The current
owner remains **121 MATCH / 5 ASM**, with the same 126-function set. No provider,
vendor implementation, shared header, publication file, commit, rebase, push or
full build was changed or performed by this lane.

All new native evidence is under
`build/finish-first-party-20260922/model-next-01/`. Start with its `completed.json`.
The completed native baseline was compiled once. Its object is byte-for-byte
identical to the earlier
`build/continue-first-party-20260922/model-manager-after-rebase/closed-model-two-functions/owner.o`.

| Binding | Value |
| --- | --- |
| HEAD at verification | `2260985773b9b9c7b7a9aeb487ee0e2aa80f909f` |
| Current owner SHA-256 | `a04a90ea3d0fbf818e26e3ed76281171e569f16e9191f6ea53a9058e1ca93994` |
| Native owner object SHA-256 | `d8e7d8e7134eebbdb9f9e12ab94347fc98f5e90ef3cec2ffb827234644956e56` |
| Compiler | `D:\mwcps2-3.0.1b210-060308\mwccps2.exe` |
| Compiler SHA-256 | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Configured flags | `-O2 -Iinclude` |

`official-current-owner-02/official.json` and `official.log` record an exit-zero
run of `tools/verify.py`'s unchanged `main`, including its callee and data-symbol
relocation checks. The compile boundary reused the completed native object after
checking the owner bytes, compiler file, flags and all dependencies. It did not
recompile or alter comparison gates. The first wrapper attempt stopped before
comparison because it compared compiler path spellings as strings; the second
used resolved file identity and a new report directory. The first directory is
retained. The final source, function/status inventory and full object identity
were checked again.

## Fresh loader work: `0047b0c0`

The guarded draft has concrete source defects beyond register allocation. The
new scratch candidate corrects the following, using the current first-party
providers, public interface declarations, IDA/Ghidra headstarts and retail ASM:

* `RwStreamReadChunkHeaderInfo` writes a 20-byte header. The draft supplied the
  address of one scalar while treating a separately declared scalar as its length.
  The scratch candidate supplies the complete header. Its 20-byte effect header
  and eight-byte memory-stream descriptor are also real C objects.
* Both type-seven `func_004667d0` requests need `D_0070B610` as argument nine.
  The draft passes zero. Retail stores the schema pointer in the first stack
  argument slot at `0047b58c`–`0047b594` and `0047b65c`–`0047b664`.
  The actual ten-argument provider is in `src/promoted/code1_0046.c:1280` onward.
* The clone path calls `func_0047d200` and `func_0047dc30` without their required
  selected-list argument. The providers in `src/Graphics/Model/mdlEffect.c` take
  `u32 **` and return a pointer. Retail passes the primary or secondary wrapper
  selected from the arrays at attachment offsets `0x14` and `0x20`.
* An animation entry begins with a complete `RwMatrix`. The new draft assigns
  that value and keeps the entry's remaining fields separate, following the
  already closed adjacent `0047c660` implementation.
* The animation sentinel must use the existing `D_00922BC0_abs` address view.
  The draft's scalar declaration emitted `R_MIPS_GPREL16` at candidate offset
  `0x70c`, requiring displacement **1,809,104**, outside the signed 16-bit range.
  `loader-relocation-diagnostic.json` records the rejected object without masking
  or substituting the relocation.

The first loader compile exposed a remaining integer-to-pointer free argument.
That failed attempt is preserved in `loader-aggregate-contracts/compile.log`.
The next native object compiled successfully but hit the sentinel relocation
failure above. A new candidate used the owner's established absolute alias.
The successful native loader compiles have no C source warnings; their logs
retain the environment's existing Python bootstrap/MWCIncludes notices.

Retail's dispatch is a linear comparison chain at `0047b13c`–`0047b25c`, with
handlers in a different physical order. The old source note calling this a jump
table is inaccurate. `loader_dispatch.py` separates the semantic chunk tests
from the handler order using ordinary C labels. It introduces no data table.
`loader_handler_lifetimes.py` then tests actual per-handler temporary lifetimes.

| Current-source native candidate | Code bytes / retail window | Unmasked differing words | Alignment edits | Result |
| --- | ---: | ---: | ---: | --- |
| `loader-aggregate-contracts-free-pointer` | 5512 / 5536 | Not scored | Not scored | Out-of-range sentinel relocation |
| `loader-aggregate-contracts-absolute-sentinel` | 5516 / 5536 | 1315 | 1577 | Rejected |
| `loader-ordered-dispatch-handlers` | 5508 / 5536 | 1287 | 997 | Rejected |
| `loader-scoped-handler-lifetimes` | 5508 / 5536 | 1296 | 1133 | Rejected |

Every successfully compiled loader candidate keeps all **125 sibling functions'
raw bytes and canonical relocations** and both owned data sections unchanged.
All 126 names remain present. The best dispatch candidate is still substantially
different: frame `0xe0` versus retail `0xd0`, an extra saved register, different
header/effect stack homes, opposite direct/pending branch placement, and remaining
handler load/callback lifetimes. Matching size or improving alignment is not an
exact closure. None of these candidates is installed.

## Remaining targets and concrete blockers

### `00471370`: hierarchy transforms and quaternion interpolation

The guarded draft requires correctness repairs before further matching claims.
At source lines 995 and 1000, `func_003dc740` receives the angle's integer bits as
argument one. Retail at `00471f34`–`00471f44` and `00471f74`–`00471f84` supplies the
quaternion pointer in `a0`, axis pointer in `a1`, the angle in **`f12`**, and combine
mode in `a2`. The public `RtQuatRotate` contract in `include/rw/inc/rtquat.h` has
exactly that pointer/pointer/float/enum shape. The draft's unprototyped call is
therefore an ABI error, not a harmless register-allocation difference.

The blend block at source lines 1123–1129 already writes byte offsets
`0x10/0x14/0x18/0x1c` through the `u16 *param_3` parameter. Lines 1139–1145 repeat
the calculation at pointer indices `0x10/0x14/0x18/0x1c`, which instead address
byte offsets **`0x20/0x28/0x30/0x38`**. Retail `004724ac`–`00472524` contains only
the first destination. The existing comment that attributes this duplicate to
register rotation is incorrect.

The draft also retains separate scalar fragments for real quaternion/cache and
matrix objects; for example `afStack_b0[8]` and `afStack_f0[3]` do not own the
complete matrices used by the retail paths. Their real aggregate boundaries and
callee contracts must be reconstructed. The retail frame is `0x550`. The IDA
and Ghidra headstarts identify the corresponding matrix/quaternion storage; their
scalar declarations are not valid C object ownership. No unsafe draft was enabled
or compiled as a claimed source recovery in this lane.

### `00475cd0`: shadow orientation and rendering

The interpolation expression is semantically wrong. At source lines 3261–3271,
the first polynomial result feeds the second angle, and the second result
overwrites the cache's angular displacement. Retail `0047600c`–`0047609c` instead
evaluates separate sine polynomials for `(1 - amount) * omega` and `amount * omega`,
including their cubic factors and the full coefficient chain. Retail then uses
those two weights consistently for all four quaternion components.

The nearly-zero branch is also wrong: the draft uses `interpolation.scale` as the
second weight and `amount` as the first real-component weight, where retail uses
`amount` and `1 - amount`, respectively. For example, with the near-zero flag set,
`amount = 0.25`, `omega = 0`, and identical cached unit quaternions `(0, 0, 0, 1)`,
the retail weight expressions preserve `(0, 0, 0, 1)`; the draft expressions give
`(0, 0, 0, 0.25)`.
This follows directly from the source expressions and does not require a
floating-point rounding assumption.

Retail stores the output quaternion separately at stack `0x80` and the 40-byte
cache at `0x90`; the draft folds output into the cache and uses padding to shape
the stack. The public cache layout in `include/rw/inc/rtslerp.h` confirms the two
quaternions, angular displacement and near-zero flag. The draft also declares
`func_004571c0` with two arguments, while its actual first-party provider in
`src/promoted/code1_0045.c:1410` takes none. These object and interface defects
need repair before another candidate can qualify. The retail window is 4000 bytes
and its frame is `0x1a0`; the old approximate-size receipts do not prove recovery.

### `00476e90`: material tint quantization

Read the current source, callers, both headstarts, complete retail assembly, and
the prior native probe receipts. The prior destination-lifetime result remains
negative at 996 bytes for a 976-byte window, with 67 unmasked differing words.
The documented register, packed-byte, normalization, aggregate, loop, quantizer,
CSE and propagation families have already been explored. Their receipts were
read, not rerun. This lane adds no claim of a fresh tint closure or a new
quantizer mechanism.

### `00479100`: model draw branches

`draw-separated-colored-uncolored` is a current-source native check of the
separate colored/uncolored draw-call structure: **1932 bytes / 1920-byte window,
189 unmasked differing words, 21 alignment edits**. All 125 siblings and owned
data are preserved, but the candidate exceeds the window and is rejected.
The historical audit also records this branch-split family as negative; it was
not pursued further. No exhausted color-quantizer sweep was replayed. The prior
30-word baseline's equal physical length combines extra quantizer instructions
with a missing second draw-call path and is not evidence of exactness.

## Handoff

Review `completed.json`, `official-current-owner-02/official.json`, and the
per-candidate `result.json`, `compile.json`, source, resolved bytes and alignment
files. Reuse the completed receipts; do not rerun their compilers or writers.
The loader's corrected contracts and ordered dispatch are concrete starting
points, but every remaining target still needs exact source-bound native proof
before installation. The two large transform/render drafts additionally contain
the specific correctness defects documented above.

Attempts to message the prime through `agents` returned
`AGENTS_BUSY: no agent family belongs to this conversation`. File, patch,
terminal and verification operations remained available and completed. Existing
dirty source and evidence from other workers were preserved.
