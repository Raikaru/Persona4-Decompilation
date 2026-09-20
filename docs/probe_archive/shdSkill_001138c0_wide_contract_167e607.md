# shdSkill wide skill contract, 167e607 resume

Worker 3 resumed on `work/first-party-0360227` after the upstream `167e607`
rebase. The measured HEAD is `6de7889e650ab0c6806e94720949207da80e1921`.
Only `src/shdSkill.c`, the new scratch lane and this note were in scope.
The earlier `DC_worker3_20260920_recoveries.md` and all saved experiments
were read without modification.

## Result and production state

No production edit was applied. `src/shdSkill.c` still reports **15 MATCH**
under its configured MWCCPS2 b210, `-O2 -Iinclude`. All fifteen functions
were also independently relocated and compared with their complete retail
windows. Every omitted suffix is zero-filled alignment.

The staged wide-contract owner remains **four differing instruction words,
two aligned edits**, in `001138c0` at 1384/1392 bytes. It does not constitute
an accepted recovery. Forty-four complete-owner measurements, including the
baseline, preserve a record of the new source mechanisms tested in this run.

The best full-owner proposal is:

`build/first-party-resume-167e607/shdSkill/wide/shdSkill.c`

It makes only these four declaration/definition changes to the exact baseline:

```diff
-s32 func_0023d8e0(u8 *arg0, u16 arg1);
+s32 func_0023d8e0(u8 *arg0, s32 arg1);
-void func_00114dc0(Vec2f position, f32 scale, Color4 color, u16 skill, s32 texture);
+void func_00114dc0(Vec2f position, f32 scale, Color4 color, s32 skill, s32 texture);
-s32 func_00114cb0(u16 arg0) {
+s32 func_00114cb0(s32 arg0) {
-void func_00114dc0(Vec2f arg0, f32 fparg0, Color4 arg1, u16 arg2, s32 arg3) {
+void func_00114dc0(Vec2f arg0, f32 fparg0, Color4 arg1, s32 arg2, s32 arg3) {
```

Production still declares the provider and both forwarding wrappers with
their prior `u16` skill parameters. The datCalc provider was read but not
edited or compiled by this lane.

## Exact residual and complete-owner proof

Retail loads the skill after the position, scale and color arguments.
The wide proposal materializes the halfword-to-word value first:

| Function offset | Retail | Wide proposal |
| --- | --- | --- |
| 0x218 | `ld a0, 0xd0(sp)` | `lhu a2, 0xa(s5)` |
| 0x21c | `mov.s f12, f21` | `ld a0, 0xd0(sp)` |
| 0x220 | `lw a1, 0xdc(sp)` | `mov.s f12, f21` |
| 0x224 | `lhu a2, 0xa(s5)` | `lw a1, 0xdc(sp)` |

The frame remains 0xe0 bytes. All 23 code relocations resolve to their actual
destinations. The last eight bytes of the 1392-byte retail window are zero.
There are no other differences in the fully relocated target.

All **fourteen non-target functions** retain their raw instructions and
canonical relocations, and all allocated data retains its bytes, alignment
and canonical relocations. Each of those fourteen functions was separately
resolved against retail in the wide proposal. In particular:

| Function | Emitted/window bytes | Code relocations | Zero tail |
| --- | ---: | ---: | ---: |
| 00114cb0 | 264 / 272 | 6 | 8 |
| 00114dc0 | 140 / 144 | 2 | 4 |

The complete `00114cb0` table at **0x00746580** is **80 bytes / 20 entries**.
All twenty table relocations resolve to the function's actual labels, and
the entire table equals retail in both the baseline and the wide proposal.
`001138c0` creates no owned table or other allocated data.

`build/first-party-resume-167e607/shdSkill/proof.json` records the fifteen
baseline proofs, fourteen wide sibling proofs, complete data comparison,
fully relocated target residual, compiler receipts and all forty-four measurements.

## New source mechanisms tested

| Probe family | Result |
| --- | --- |
| Typed inline draw adapter accepting a `u16` value or its storage pointer; inline ID getters returning `u16` or `s32` | Same 1384-byte/two-edit residual |
| Aggregate-address draw adapter; integer-held texture address; equivalent signed/unsigned halfword views | No improvement; signed-load plus mask adds an instruction |
| Explicit position/color value-copy helpers | Extra copies and argument-home work; 1400-byte targets |
| Scalar propagation enabled; color represented by a genuine byte/word union | Same residual, with siblings and data preserved |
| Actual packed tag/ID word, shifted by 16 | Adds `lw`/`srl`; 1388 bytes and five aligned edits |
| Integer-address ID load, halfword view, unsigned masks and word-width unsigned icon contracts | Same residual |
| Alternative bitfield storage units and aggregate union views | Same residual |
| Inline transport of the existing position/color object representations | Extra copies; 1392 bytes and 31 aligned edits |
| Compatible default-promotion query forms while retaining narrow wrappers | Regress 00114cb0; no such form was accepted |
| Offset-icon construction from a real base-position pointer | Same residual; construction by value adds copies and frame changes |
| Block-local icon lifetime and explicit lifetime optimizer settings | Same residual |
| Named aggregate/float/skill snapshots, with register hints and scalarization enabled or disabled | 1396-byte targets; extra aggregate copies and frame changes |
| Common-subexpression elimination disabled, with descriptor/skill/texture parameter reuse | 1400-byte targets; 30 aligned edits for the first three forms and 53 for texture reuse |

The prime's float-position lead was tested coherently: every declaration,
the actual definition and the in-owner call were reordered together.
Integer and float argument registers are assigned independently here, but
these source orders still change instruction materialization:

| Scale parameter position | 001138c0 bytes / aligned edits | 00114dc0 bytes / aligned edits |
| --- | ---: | ---: |
| Before position | 1384 / 4 | 140 / 2 |
| After color | 1384 / 4 | 140 / 2 |
| After skill | 1384 / 4 | 140 / 2 |
| Last | 1384 / 6 | 140 / 2 |

The skill load remains first in all four cases. The wrapper's prologue also
changes, so none of these parameter orders was retained. This is a measured
residual, not a claim that ordinary C cannot reproduce the retail order.

During final release, the prime supplied a successful `001da5f0` mechanism
using scoped `opt_common_subs off` and reassigned input parameters. Four
additional shdSkill candidates tested that new lead. Disabling common
subexpressions alone, reusing the descriptor parameter as the ID storage
pointer, and reusing the unused mode parameter as the actual ID value each
retain the early skill load and regress to 30 aligned edits. Reusing mode as
the actual texture value regresses to 53. The additional differences include
unshared color constants, extra flag loads and different float reloads. None
was applied to production.

## Provider and caller dependencies

The intended query contract is `s32 func_0023d8e0(u8 *, s32)`. Retail
`00114cb0` preserves its incoming skill while masking only the bounds-check
operand; `00114dc0` forwards the incoming integer register unchanged.
The proposed word-width wrapper formals preserve both complete retail bodies.
The provider itself masks the low sixteen bits before its data accesses;
its coordinated definition/caller migration belongs to the prime.

Inside shdSkill, `001138c0` is the only call to `00114dc0`, and `00114dc0`
is the only call to `00114cb0`. `001138c0` retains its own existing signature,
so its other shdSkill callers and `src/promoted/code1_0011.c` do not acquire
a new parameter dependency from this proposal.

The remaining external `00114dc0` caller is the guarded `00205170` body in
`src/promoted/code1_0020.c` (function name `func_00205170`, marker
`FUN_00205170`). Its current declaration and call use packed scalar spellings
for the position and color and a pointer spelling for the last argument.
Future integration must reconcile that declaration with the actual
`(Vec2f, f32, Color4, s32, s32)` boundary and preserve the genuine eight-byte
coordinate and four-byte color objects. That owner belongs to the prime;
this lane neither edited nor compiled it. No float-order migration from the
rejected probes is required.

## Hashes and reproduction

| Artifact | SHA-256 |
| --- | --- |
| Exact production source | `975774045f344a736c1184b1271c54a63694fa14894ddacdfe3ca6004fd650e0` |
| Exact production object | `be3c85569dd5e7d872a0370a9b9135bd7b1a93bb2a9c602df61f069fb3508699` |
| Staged wide source | `bf2088723a9e2b585f5d3f8afb038278c025c35f4717327ee258edbd91c79301` |
| Staged wide object | `52498134211899a4651e9f689ecb87b8f8e59f0e05220c67cf4b66d9d38e9935` |

Run from `build/recovered-upstream`:

```powershell
python -B -S tools/verify.py src/shdSkill.c --json build/first-party-resume-167e607/shdSkill/official-baseline.json
python -B -S build/first-party-resume-167e607/shdSkill/prove.py
git diff --check -- src/shdSkill.c
```

The proof script reuses immutable completed objects only after checking their
source and object hashes. Every compiler invocation used the logical
`src/shdSkill.c` owner to select the configured profile. Experiment scripts
and full source/object/receipt/difference sets remain under the new scratch
lane. No earlier experiment was overwritten, and no full project build,
commit or push was performed.
