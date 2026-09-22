# Independent review: crossfade 004b2a00

Worker 3 reviewed the actual `canonical-typed-vertices/code1_004b.c`, its
retained native object, and the subsequently integrated owner. No compiler,
owner write, shared-header change, vendor edit, or broad test was performed
by this review. This note is the only review artifact written.

No new target behavior defect was found on the initialized, positive-duration
crossfade paths inspected. The final owner fixes the two early review issues:
the dormant 004b1ad0 camera declaration now agrees with the s32 provider, and
the final native receipt includes the newly used header dependencies.

## Actual object and integration evidence

The candidate-first call in `build/first-party-resume-20260922/card_effect.py:49`
compiles the candidate path with the logical owner's compiler settings. The
review read the full transformed translation unit: the intermediate `body.c`
alone precedes `canonical_owner`'s callback and camera corrections.

Independent read-only relocation proof of the retained candidate object
reconfirmed 1016 bytes against the 1024-byte retail window, an all-zero
eight-byte suffix, all nine resolved code relocations, no referenced owned
data sections, and unchanged allocated data. All **76** other function bodies
and canonical relocations agree with `crossfade/before/owner.o`; 68 of those
siblings have first-party provenance. This includes 004b2780, whose declarations
and call-site types were reconciled without changing its object bytes.

The integrated `integration/native-final/owner.o` is byte-for-byte identical
to the independently checked candidate object. The current owner and retained
final source have identical hashes. Every dependency hash in the final receipt
was checked against the current files. `integration/official.json` reports
004b2a00 MATCH, 1016/1024 bytes, with owner totals 69 MATCH / 8 ASM and first-party
totals 68 MATCH / 1 ASM. These are the prime's retained official results; this
review did not recompile or rerun official verification.

| Item | SHA-256 |
| --- | --- |
| Original reviewed complete candidate | `793bebbcd4ff81a164b89f830b1376e753704116702f9b8d15c2f89c7cc09330` |
| Integrated owner and native-final source | `5876849a62c0ada6365a411c11a61fbfe2b89256406f39a28f41fd43672ea296` |
| Candidate and final native object | `4fded382aabc694ea57bd03c00aa25a54487478c42aa2c649e0f1535e0c6e5ee` |
| Resolved target body | `45a27e7f3915fb3c0ea9d53084a18b21c887e2f6678fec4113a8a7d66ae167a8` |
| btl_shuffle_draw_internal.h | `dcb613bdbcbbf4786419b542ebe9ea269516cd4161516b2df1c49e355a3fd8f4` |
| rw/plcore/barenderstate.h | `ae1b1ffe5c64ac25db9533848125c6b4a3fadd2e72b25a588b48fae58cb75f21` |

Evidence directory: `build/first-party-next-20260922/crossfade/`, specifically
`canonical-typed-vertices/{compile.json,result.json,unmasked-proof.json}` and
`integration/{native-final/compile.json,unmasked-proof.json,official.json}`.

## Duration, references, and resource lifetime

`src/Graphics/Effect/effCrossfade.c` establishes the relevant state sequence.
004b3110 admits a request only when the task is idle and stores its duration
as a halfword. 004b2ed0 creates and checks the camera, attached frame, and raster,
attaches the raster at camera+0x60, initializes elapsed at state+4 to zero, and
enters state 3 only after 004b2780's capture succeeds. 004b30a0 draws only in
state 3, **then** increments elapsed and changes to state 4 when elapsed reaches
duration. Cleanup occurs outside the state-3 draw path.

For duration d in 1..65535, the rendered elapsed values are 0..d-1. Increment
cannot wrap before the transition to state 4, even for d=65535. Both halfwords
are exactly representable as f32, their ratio stays in [0,1], and
`255.0f * (1.0f - ratio)` stays in [0,255]. The byte conversion and its subsequent
unsigned-to-float conversions are therefore defined on these paths. The
inspected retail callers pass 5 or 8 directly; the task callback 001d79e0 reads
the duration saved by 001d7a10, whose two inspected retail callers pass 5.

This is a precondition, not an input check: 004b3110 itself does not reject zero.
An arbitrary zero-duration record can still reach 0/0 in the old algorithm.
The integrated comment correctly restricts its claim to initialized positive
duration. No guard, clamping, altered termination, or synthetic initialization
was added to obtain matching bytes. The live main-camera handle and its valid
far plane remain the existing initialized-renderer contract.

## Arithmetic, store order, and callbacks

Retail `asm/nonmatchings/code1_004b/func_004b2a00.s` and both IDA/Ghidra references
agree with the recovered division, subtraction, multiplication, byte conversion,
and four separate alpha-to-float conversions. The raster is captured before
render-state calls. The render-state callback is reloaded from its table slot
on every call; retaining the table address does not cache a callback across
calls. All state settings, global-depth/camera read order, 40 vertex stores,
triangle-strip submission, and final texture unbind retain retail order.

The camera provider in `src/promoted/code1_0045.c:1359-1363` returns an s32
handle. The explicit `(u8 *)(u32)` conversion preserves its pointer bits before
the +0x84 far-plane read. Both owner declarations now use s32, including the
inactive 004b1ad0 block. The enum/void-pointer/status-return state callback and
the enum/PS2-vertex-pointer/count primitive callback agree with the SDK contracts
in `include/rw/plcore/badevice.h:184-207`. `uintptr_t` is the project's u32.
The state interface integer round trip preserves the same address and reloads
the same slot. 003f6440's retail implementation returns a status and accepts
pointer-sized state values; commands 2 and 3 use the supplied bits, while other
commands can dereference the value. Ignoring those statuses preserves the
original call behavior. The unchanged vendor wrapper's coarse s32/void-pointer
spellings were reviewed against the actual ABI, not modified.

## Complete vertex storage and the reserved-field distinction

`BtlShuffleSkyVertex` has the documented PS2 0x40-byte layout and a quadword
alignment overlay. Four vertices provide the actual 0x100-byte input object.
Positions are (0,0), (0,448), (640,0), (640,448), with corresponding UVs
(0,0), (0,1), (1,0), (1,1), white RGB, shared depth/reciprocal depth, and the
computed alpha. The callback's vertex count is four. No filler packet is needed.

The reserved fields are **not literally unread**. Retail callback 0040c0f0
selects 0040bac0 for primitive type 4 (retail table 0070c2e0). That renderer
copies all four quadwords of each triangle's vertices using lq/sq, including
the +0x30 tail; see 0040bc38..0040bd64. With four input vertices it uses triangles
(0,1,2) and (1,3,2), entirely within the real array. Its CPU path transports
representations rather than evaluating uninitialized scalar fields.

The target initializes ten words per vertex. It preserves the retail omission
of camera-Z (+0x0c), fog padding (+0x1c), normals (+0x30..0x38), and alignment
padding (+0x3c). The SDK documents camera-Z/fog padding as fog-related and
normals as allocated but unused (`include/rw/sky2/rwplcore.h:4641-4655`). The
target explicitly disables fog first. The actual state handler 003f5070 routes
state 14 to 003f5998; its zero branch at 003f59bc clears bit 0 of iGpffffb984
and the fog primitive bit. 0040c0f0 checks that same bit to choose the no-fog
descriptor. Thus the omitted fields are not newly introduced rendering inputs;
their bytes still travel in the existing opaque packet. This review does not
claim the complete vertex object is initialized or that all copied bytes have
defined floating-point values. No VU microcode rewrite or arbitrary-field input
experiment was used to justify the recovery.

## Review limits and exact tool failures

The earlier archive `/persona4-decompilation/docs/probe_archive/C4B_004b2a00_followup.md`
was used as a lead, then current source, callers, retail, and retained objects
were checked. An optional whole-ELF reference scan was blocked before execution
with “couldn't determine the safety status of the request”; no exhaustive new
reference-scan result is claimed. One preliminary command using virtual paths
inside PowerShell was rejected with INVALID_COMMAND_PATH and had not run;
subsequent commands used relative paths. These did not block the source,
contract, state-machine, or retained-object review.

The crossfade owner is released back to the prime. Worker 3 made no crossfade
owner changes. The prior ring owner also remains released.
