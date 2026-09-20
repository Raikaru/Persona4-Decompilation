# Exact wide-provider query caller, 001da5f0

The complete-owner proposal preserves `func_001da5f0` with the actual
`s32 func_0023d8e0(u8 *, s32)` provider contract. It emits all 76 executable
bytes in the 80-byte retail window, resolves the single call to `0023d8e0`,
and verifies the remaining four bytes are zero alignment. The entire owner
object is byte-identical to its narrow-declaration baseline: all 94 function
bodies, relocations, symbols and allocated data are preserved.

This is a caller prerequisite for the wider provider migration, not an
additional C recovery. The live owner and live provider remain unchanged.
Integrate the proposal with the provider and the other caller closures.

## Source and ABI

Owner: `src/promoted/code1_001d.c`. The measurement used the stack rebased onto
`167e607`, with HEAD `6de7889`. The only proposed file-level declaration change
is:

```c
extern s32 func_0023d8e0(u8 *arg0, s32 arg1);
```

The exact target form is:

```c
#pragma push
#pragma opt_common_subs off
// FUN_001DA5F0
s32 func_001da5f0(u8 *arg0, s32 arg1)
{
    u8 *action = arg0;
    s32 comparison = arg1;
    arg0 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    arg1 = (s16)func_0023d8e0(arg0, *(u16 *)(action + 0x7E));
    return p4_001da5f0_xor(arg1, comparison) < 1U;
}
#pragma pop
```

`p4_001da5f0_xor` is the existing file-local inline helper; no new helper or
type is needed. The final full-source copy also includes a measured comment
immediately above this scope.

The saved locals retain the original action and full signed comparison value.
The two original parameters then become the data-unit pointer and the signed
query result. Reusing both parameters matters: retaining the query result only
inside the return expression leaves the first two register copies reversed.
The final form reproduces the action copy before the comparison copy, followed
by the action's `+0x30` unit load, the unit's `+0xA64` data pointer load, and
the unsigned halfword skill load at action `+0x7E`.

The stored skill is genuinely `u16`; promotion to the provider's `s32`
parameter preserves every possible stored value. The provider itself masks the
low sixteen bits at retail `0023d8f0` and `0023d98c`, as recorded in
`DC_worker3_20260920_recoveries.md`. The explicit `s16` conversion of its result
preserves the target's signed narrowing before comparison. The target's own
`s32 (u8 *, s32)` signature and its callback registrations in `001da640` and
`001da690` are unchanged.

## Measurements and necessary controls

All probes compiled immutable complete owners with the current owner's
configured MWCCPS2 b210 `-O2 -Iinclude` profile. The final proposal's official
verifier command was checked to use exactly the current owner's compiler and
flags, differing only in its input source path.

The plain wide declaration emits 72 bytes and changes the action lifetime and
unit/skill load order. Ordinary narrow inline adapters, storage getters,
unsigned-int bitfields, native address carriers and automatic inlining did not
close that form. Separate real getters with common-subexpression and
propagation controls reduced the residual to the two entry copies; all later
instructions already agreed.

A local input record with the action field before the comparison field first
closed the target. Reversing those fields restored the two-word residual.
Reassigning both original parameters then reproduced the same exact result
without the record or new getters. Removing controls established the final
minimum:

| Parameter-reuse form | Bytes / window | Fully resolved differing words |
| --- | ---: | ---: |
| Common subexpressions off; propagation off | 76 / 80 | 0 |
| Common subexpressions off only | 76 / 80 | 0 |
| Propagation off only | 76 / 80 | 5 |
| Default controls | 76 / 80 | 5 |

Only `opt_common_subs off` remains in the final proposal, scoped with
`push`/`pop`. A focused level-one probe also matched, but it is not the retained
proposal. The earlier two-word form and all named experiments remain in the
scratch lane. Alignment reports count the omitted zero word as an edit;
acceptance uses resolved executable bytes and the separate zero-tail check.

## Complete-owner evidence

Scratch root: `build/first-party-resume-167e607/query/`.

The final source is `final/code1_001d.c`; `final/owner.o` and
`final/compile.json` retain its complete object and compiler receipt.
`final/complete_owner_proof.json` contains the unmasked target proof,
unchanged-function inventory, canonical sibling/data comparisons, current
source fingerprint, relevant header/compiler/retail hashes and gate results.
`final/target.resolved.bin` retains the private resolved target bytes.

The official current-owner and frozen-proposal verifiers both report
**91 MATCH / 3 ASM**, with `001da5f0` MATCH and zero normalized difference.
Their complete per-function status, size and difference sets agree. Reports
and logs are `final/official-current.{json,log}` and
`final/official-proposal.{json,log}`. These checks do not accept any ASM-backed
function as a new C match.

Proposal integrity lint reports **zero errors and three H003 advisories**.
Two are inherited at lines 584 and 2621; the third is the measured scoped
common-subexpression control at line 3520. The report is `final/lint.json`.
Terminal receipt `80334` completed the final compile, both official verifier
runs and lint with exit zero.

| Artifact | SHA-256 |
| --- | --- |
| Unchanged live/baseline owner source | `e18cb8ef8fa97686559040013985b7e7fc1b25ab9c03bd67024e92bfeb39dbdb` |
| Final full-owner proposal source | `d9ce13310e1eaee40d954c54852ed9dd246307edf559731710edcb2392763451` |
| Both complete owner objects | `76ed7ec1377908bfb2617919d87ebb965cb30a1204896f31a2011072010a5a18` |

`finalize.py` is the local reproduction entry point. It protects completed
gate artifacts from replacement; a new verification pass needs a distinct
output label. No live source edit, provider edit, commit, push or full-image
build was performed in this lane.
