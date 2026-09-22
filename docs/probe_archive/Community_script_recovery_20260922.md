# Community script: fishing draw and update recovery

`src/promoted/cmmScript.c` now contains ordinary C for `func_0024c460` and
`func_0024f790`. Both have source-bound native MWCCPS2 b210 objects, complete
unmasked retail proofs and official `tools/verify.py MATCH` results. The
installed five-owner family closes the accompanying task and model contracts.
These are two promotions; the eleven other family targets were already C.

| Recovered function | Emitted bytes | Retail window | Zero alignment tail |
| --- | ---: | ---: | ---: |
| Fishing draw, `func_0024c460` | 3,464 | 3,472 | 8 |
| Fishing update, `func_0024f790` | 1,988 | 2,000 | 12 |

## Source and contracts

The draw callback receives its entry through its second argument. The actual
dispatcher, `func_0024efa0`, calls an `s32 (*)(u8 *, u8 *)` entry with the task
work and the current entry. Fade-in and fade-out leave through the common
epilogue before overlay drawing; the steady phase uses full opacity. Scoped
phase values and separate height multiplication preserve the retail floating
operations, stores and call order.

The fishing update retains unsigned random conversion, stored halfword
counters, direction-button cases, task lookups and model transport. Its two
retail origin objects are eight-byte aligned and sixteen bytes apart; only
their three coordinates are copied. `CmmFishingOrigin` expresses the global
alignment, while each local `CmmFishingPosition` contains three floats. The
interpolation helper `0.0f + origin + delta * ratio` and the actual delta/origin
lifetimes reproduce the complete retail COP1 chain. No ordinary assembly,
fabricated effects, padding stores or compiler-profile changes were added.

The task getter is `u32 func_00452560(void *)`, which reads the packed address
at task offset `0x38`. Its consumers now pass their actual task. The model
creator returns the task handle; the getter `func_0025ff60(s32)` receives that
handle and returns the model stored in its work. The creator, update,
destructor and model wrappers agree on this transport. The existing signed
32-bit handle convention is also explicit at rank-up call sites. The rank-up
function `func_00257900` remains guarded ASM.

The retained IDA and Ghidra headstarts corroborate the callback arguments,
task lookups, branches and work layout. Their pseudotypes and floating-point
approximations remain references; the native comparison establishes the final
instruction sequence. Retail call-site evidence is retained in
`community-script/task-getter-call-audit.json`.

## Installed native closure

All paths in this section start at `build/finish-first-party-20260922/`.
`community-script/installed-family/completed-family.json` binds each owner to
its child `completed.json`, native object and full official report. The
configured compiler is MWCCPS2 3.0.1 b210 with `-O2 -Iinclude`.

| Owner | Official main-origin result | Comparison with publication-6500 |
| --- | --- | --- |
| `src/promoted/cmmScript.c` | 49 MATCH, 2 ASM | Two recovered targets; all 49 existing siblings preserved. |
| `src/promoted/code1_0025.c` | 47 MATCH, 1 ASM | All 48 functions preserved. |
| `src/shdEffect.c` | 7 MATCH | All seven functions preserved. |
| `src/cmmRankUp.c` | 17 MATCH, 9 ASM | All 26 functions preserved, including the guarded rank-up caller. |
| `src/promoted/code1_004b.c` | 68 MATCH, 1 ASM | All 77 object functions preserved, including eight outside the main-origin count. |

Every allocated data section in these five owners is unchanged. The
independent `resume-publication-audit-01/native-proof-audit.json` recomputes all
thirteen family target proofs, compares complete resolved code and referenced
owned data, and checks every other function's bytes and canonical relocations
against the prior published objects. Compiler, flags, recursive dependencies,
remaining fallback assembly and official reports were authenticated without
repeating their completed compilation or verifier jobs.

The final `cmmScript.c` SHA-256 is
`5483794cf474002b7829bb50b969c27426ea61ea567ab175570988fef519778a`.
Its native object SHA-256 is
`f7d0305cf2c6c9d444ac6128535b468e7dc0a4f936395b8747ab41fde13b230f`.
Its official report SHA-256 is
`53e61f9d455ab312ff3f9735c075747cdf2ecb3dc9cd813038ce0367a7ce25a2`.
The other source/object/report bindings are listed in the installed family
and `resume-publication-audit-01/receipt-map.json`.

## Retained behavior evidence

`community-script/behavior32/result.json` records successful O0 and O2
executions with four-byte pointers. Each run covers 837 update cases, 866
transport cases, 29 callback cases and 768 button truth-table cases.
`draw-behavior32/result.json` records 6,537 draw cases, 391 dispatch cases and
40,480 serialized sprites per optimization level. The two fishing mutation
controls and the fade/overlay mutation control fail as intended.

`fishing-behavior-final-draw-binding.json` connects the earlier fishing fixture
to the combined installed source. The independent
`resume-publication-audit-01/supporting-evidence.json` authenticates that binding,
the exact extracted target bodies, source inputs, compiler, runners, fixture
files and compiled modules for all four positive runs and three negative
controls. It reuses the completed execution receipts. Lower allocation,
rendering, sound and sine boundaries are controlled; these tests do not claim
PS2 execution or visual validation.

## Remaining work

`func_0024be40` and `func_0024d1f0` remain ASM in this owner. Inherited model
wrapper declarations outside this family remain recorded in
`community-script/model-wrapper-caller-audit.json`; this recovery does not
close those unrelated declarations or the lower model allocator's ASM body.
The old source measurements immediately above the recovered draw function and
the comparison with its still-guarded neighbor are stale historical comments.
They were preserved by the read-only audit and should be corrected with a new
source binding when that owner next changes.

The audit froze this community family at HEAD
`2260985773b9b9c7b7a9aeb487ee0e2aa80f909f`. The concurrent radial-outline work
supersedes separate owners and does not change these community-family receipts.
