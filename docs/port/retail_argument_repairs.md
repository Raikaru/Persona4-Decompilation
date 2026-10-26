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


## Second mirror audit

The second audit starts from decomp `854e43d2` and the PC mirror's 317
literal repairs and 156 explicit passthrough records. The audit distinguishes
an active marked C owner from guarded reconstruction text whose retail owner
is still assembly. Correcting the latter does not establish a new C match.

Live inputs and results are now stated at the owning interfaces: geometry
matrix translation/basis/scale, particle weight, effect and task handles,
model resource results, event handles, script-return values, and the stream
buffer returned by the upload wrapper. GP/FP order is corrected where the
whole owning unit retains the retail instruction sequence. In particular,
`btlShuffleCalcRotatePointAroundAxis` keeps its original definition order
`(center, axis, point, angle, output)`; its callers agree with it rather than
changing the callee to suit a host wrapper.

Three width repairs require changing the definition as well as its callers:
`datCalcSetBadStatusById` forwards the complete unsigned status word;
`sdkSndSetSlotTrack` accepts the complete slot index but explicitly narrows
only the indexed accesses; `btlAICommandNomalStatusCheck` retains a measured
wide input view and explicitly consumes its signed low halfword. The highlight
mode shared by the symbol and small-map wrappers is signed eight-bit. These
are PS2 contracts, not host pointer-width accommodations.

The bank request chain uses a packed 32-bit descriptor, full-width request
flags, and the actual appended-node pointer result. Merely narrowing the
wrapper's first formal changed the font caller by 55 normalized bytes. The
matching form also constructs the descriptor as a word in the font producer
and keeps its flags wide. The font producer's already evaluated third key is
explicitly an unused wrapper input; no value is invented or evaluated anew.
All 46 functions in the three affected units retain their retail bytes.

The guarded `sfadxt_IsEndDecinfo` reconstruction now names and forwards its
player handle. Its existing assembly remains authoritative: both supported
MWCC versions leave the same six-byte comparison/return-address-load scheduling
residual. This is an input repair to guarded source, not a new C match.

The generic packet callback `btlTargetCancelPlayback` now states its actual
work-pointer callback signature and unsigned word result. Its body does not
use the work pointer. Five queue/draw callbacks likewise share their actual
two-argument node/work contract, including references that only take a callback
address. Every newly named unused input was already evaluated and supplied by
an existing caller; no padding value is invented.

### Explicit caller inputs, including unused inputs

Removing the three-input battle helpers' last operands changed their callers
by 3213 normalized bytes; removing the skin plugin's supplied flag changed its
caller by 129. Those attempts targeted the wrong side of the interface. The
existing callers consistently supply these inputs. The three battle helpers,
affinity bypass hook and skin opener now declare their complete contracts,
including unused inputs. Their original calls and all 383 marked functions in
the seven affected units retain the retail bytes.

Nineteen other uniform caller-context contracts are now shared by the battle,
script, calendar, clump/texture-strip, Vpad, message and runtime hook owners.
`cmmDateTableHasEntry` consumes its explicit incoming seed rather than an
uninitialized local. All 517 marked functions in their 25 affected units match.
The auxiliary skill-message hook similarly accepts its existing skill ID;
the MPEG flush wrapper accepts the existing address and byte-count inputs but
flushes globally. All 75 marked functions in these final two units match.


Fifteen further nonzero-arity contracts retain the reset index, sound flags,
camera/boss context, event sub-ID, model index and skill-query tails supplied
by every existing caller. The sound chain forwards a complete cue word through
`hsndQueueSound` and `sdkSndPlayCue`; only the actual cue consumer truncates to
signed 16 bits. `K_Cmd_BGM` retains its existing explicit low-halfword view.
The model-list caller explicitly converts its stored word to the callee's
pointer type. After resolving those views, all 1086 marked functions in the
affected units match. A failed first attempt's 25/26-byte sound-wrapper
residuals were input promotion, not return-value ABI differences.

The three reported non-permutation aggregate aliases are also now canonical:
battle unit colors use `RwRGBA`, Fcl transitions use `FclDrawColor`, and panel
origins use the shared two-float aggregate. All 338 marked functions in their
11 affected units match. The skill-roll target is an actual `DatUnit *`, not
an integer address word; changing the caller to an integer cast caused a
56-byte residual, while the proper pointer contract leaves all 109 functions
in the data owner and skill caller matched.

The audit's 156 explicit passthrough records are therefore source-redundant.
This statement includes the two guarded SFADXT source repairs, not an assertion
that their retained assembly fallbacks have become matching C.

### Required noncanonical views

The following direct canonical rewrites changed the retained retail bytes.
Their original views remain; host argument-order or width adaptation is not
evidence that a different PS2 instruction sequence should be accepted.

| Caller / interface | Direct rewrite's normalized byte difference |
|---|---:|
| `cmmReversedAtRank`'s record query | 175 |
| three packed digit-color views | 911 |
| `btlShuffleEffUpdate` step-pose input order | 6 |
| `ThunderBoltUpdateStrip` axis/angle order | 8 |
| `ThunderOrbitBoltUpdateStrip` axis/angle order | 14 |
| `mdlEffectUpdateParticleTrail` curve input order | 8 |
| `FldEvent_StepMoveToward` heading input order | 8 |
| `calDrawDateCell` number input order | 31 |
| `evtInterpolateNodeMatrices` scalar input order | 20 |

Canonicalizing the remaining integer-width views also changes extension,
register lifetime or argument setup in their callers. The source keeps the
existing explicit views instead of manufacturing unused inputs or weakening
the byte comparison. Unused copied declarations from the audited prototype
records are removed, not converted into additional generic ABI declarations.

### SDK ownership and storage

Known fixed-address RenderWare registries, the mesh freelist, pipeline state,
script interpreter operands, the SFD queue and timing counters are declared
as external retail storage. Their recovered addresses are in the normal data
symbol map; there are no unused host-only initializer shadows. Field resource
format strings use correctly sized character arrays at their retail addresses,
which preserves GP-relative addressing.

The duplicate generic SDK `RwMatrixMultiply` body is removed: the authoritative
retail VU implementation already owns `003e05f0`. Native geometry reading is
`003ce560`; geometry and world-sector chunk readers own `003cb790` and
`003cb7e0` respectively, without a duplicate function owner.

Optional SDK reconstructions now express the PS2 little-endian self-test,
big-endian ADX header/footer and encrypted scale words, four-byte retry counter,
file-server CD request pumping, AC3 lifecycle forwarding, registered thread
callbacks and the already captured movie-player/timing inputs. Existing assembly fallbacks remain authoritative where those bodies
are not marked C. These corrections must not be counted as newly matched
functions. Native SIMD alignment, low-memory and MMIO mapping, host pointer
conversion, video-player seams, allocation policy and widescreen layout remain
port responsibilities.


SDK code must also retain real link eligibility, not merely normalized byte
matches. The first metadata placement put two previously linked getters in
the monolithic SJD reconstruction, whose unowned/gapped code cannot be placed
as an entirely third-party object. The strict gate caught 8099 instead of
8101 linked functions even though every verify row matched. The four corrected
metadata getters now use the existing contiguous `adx_sjd_forward_ed78.c` and
`adx_sjd_leaf_cf010.c` address groups and share the exact RE4 object layout in
`adx_sjd_internal.h`. No link floor or placement rule is relaxed.


The corrected AHX name exposes one further real input chain: `ADXSJD_SetInSj`
(`004cdca0`) hands its saved incoming sound joint to `ADXB_SetAhxInSj`
(`004c1c50`) before the AC3 setter. The one-input reconstruction declaration
omitted that live `a1`; the complete setter now shares the actual decoder and
sound-joint types. The AHX owner reuses the existing ADXB layout rather than
a second private prefix definition. This is distinct from the retained generic
four-GP register forwarding views.

### Weighted AI target-selector callback contracts

The dispatcher at `001ded30` invokes the `00609ce0` table as
`s32 (*)(u8 *, u32)`: one action pointer and one packed query word. Thirty
forwarding callbacks at `001dc5c0`–`001dd090` instead declared a `u64` first
input and a void result. On the EE each register still occupies one slot;
on i386 that declaration consumes two stack words before the query.

These callbacks now share their complete declarations in `btl_ai_internal.h`,
accept the actual pointer/query pair, and return `btlAICommandSelectCandidates`'s
status. The original instructions leave `a0` untouched, retain the query in
`a1`, and do not overwrite `v0` after the selector returns. The two fixed-DOWN
callbacks replace `a1` with `0x100000`; their dispatcher query is explicitly
unused. Predicate casts and selection/filter constants are unchanged.

The complete `btlAICommand.c` owner retains all 263 first-party `MATCH` results.
This does not imply every callback's existing source view can be made uniform:
`001db5e0` retains its measured wide formal for the original 64-bit shift
sequence, while only the signed low 16 bits are observable. A host-only ABI
normalization of that trailing query is separate from repairing the thirty
incorrect wide-first-argument declarations.


### Variadic error callback low-word return

The RenderWare error callback `003df590` saves its unused variadic registers,
then returns the signed low word of its first input. Its measured `s64`
formal is retained: an `s32` formal with a direct return loses the original
`dsll32`/`dsra32` pair, while a narrow formal plus explicit unsigned widening
emits an extra pair of shifts. These were isolated with `micro_codegen.py`,
not inferred from host behavior.

The matching expression now performs the left shift in `u64`, then interprets
and arithmetically shifts the result before its signed low-word return. Negative
inputs no longer undergo a signed left shift. This defined bit-manipulation
spelling retains retail's two instructions and the complete owner reports
60 `MATCH` plus 71 `ASM` results without failures.

A host indirect signature such as `s32 (*)(s32, ...)` still needs a host ABI
adapter: its argument is one 32-bit slot, and the extra argument slots are
never consumed. That normalization is not a match-preserving source-formal
change and must not be credited as an upstreamed literal removal.


### Packet scheduler results and retained query-call views

`btlMainUpdateTintLerp` at `001b93c0` returns the full unsigned scheduler word,
not a byte. `btlPacketCallbackRun` at `00194c60` returns the signed completion
word its installed callback leaves in `v0`; the callback typedef and work
payload share `btl_packet_callback_internal.h`. This header does not inject
the factory header's forward `BtlPacket` tag into the existing function-local
packet layout, which MWCC otherwise resolves as an incomplete outer tag.
The packet layout, stored function pointers and callback payload remain
unchanged. The complete tint owner reports 27 `MATCH` results and the packet
owner three, with no failures.

Two existing target dispatchers retain measured wide-query call views:
`001eb1d0` and `001eb4a0` explicitly extract the unsigned low 24 bits, so
the meaningful query fits a host word. Changing only their callback local
declarations and load casts from `s64` to `u32` changes 82 and 90 normalized
bytes, respectively; the other 50 functions in the two owners still match.
Those experiments were reverted. Their host indirect-ABI normalization is
retained separately rather than claimed as a source-redundant repair.


### Stored error and draw callbacks

The MPS library and per-handle error slots now share the actual
`(void *object, Sint32 code)` callback type. `MPS_SetErrFn` uses that owning
declaration, and both public error paths forward the code already live in
`a1` at `00503870`–`005038e0`. The former object-only explanation described
a different platform and is removed, along with the private two-argument
cast. All 14 marked functions in the two affected SDK owners still match.
The unmarked setter/error reconstructions retain authoritative retail assembly;
this correction is not a claim of additional linked C.

`PersonaRenderWork.drawCommand.callback` now states the node/work pair that
`shdPersonaDrawPanels` actually receives. The install no longer erases its
second argument through a one-input function-pointer cast, and the prototype
belongs to `shdPersona_internal.h`. Stored pointer bits and record layout are
unchanged; the complete owner retains all 104 first-party `MATCH` results.
The analogous deferred-message queue callback already uses the shared
two-argument declaration from the earlier interface cohort.


### Actual AI condition table result contracts

The retail condition table at `00609850` contains 78 twelve-byte rows: one
null entry and 77 distinct non-null callbacks. Thirty-six targets had void source results:
22 enemy-side wrappers and 14 allied-side wrappers. Each calls
`btlEffectFindUnitMatchingCallback` at `001d94d0` and leaves its result in `v0`
through the frame/register restoration and return. Returning that status
explicitly fixes the interface consumed by the existing signed-word dispatch.

All 36 wrappers now return `s32`, and the existing condition owner header
carries every declaration, including the nine previously local-only AI-command
wrappers. Both complete source owners retain all 320 first-party `MATCH`
results. Predicate casts, branch layouts, filters and argument widths are
unchanged.

`btlCond_ENGROUP` at `001da890` forwards its `u32` query unchanged in `a1`;
it is the side-mask in `a2` that narrows to 16 bits. Its `btlCond_MYGROUP`
predicate at `001da7e0` ignores the query, loads the action skill halfword at
`+0x7e`, classifies the targets with zero selection/reverse inputs, and returns
a full one/zero according to the classifier's low-halfword category. Query
narrowing must not be invented from that unrelated mask or classification.

