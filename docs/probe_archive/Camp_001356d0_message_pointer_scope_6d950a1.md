# Camp persona initialization: func_001356d0

The September 20 continuation recovers `func_001356d0` in
`src/Camp/cmpPersona.c` as ordinary C under configured MWCCPS2 b210 `-O2`:
**1332 executable bytes in the 1344-byte retail window**, zero differing
instructions, all **42 code relocations resolved**, and twelve verified zero
alignment bytes. No assembly or filler instructions were added.

## Source recovery

The original draft shared one signed-halfword counter across six independent
initialization passes. Each pass now has its own lexical counter scope. The
clear pass addresses its two halfword arrays separately, and the effect pass
addresses its record fields directly. These source relationships preserve the
retail conversions at the loop test and loop body. The three other early
passes retain their existing pointer expressions.

Resource variables have the pointer type returned by `func_0046a770`. The
third resource is assigned to both its local and the work object in one
expression. The sprite loop computes its output slot inside each resource
arm, as retail does. The resource order for sprite indices is 0 for `[0,6)`,
2 for `[6,9)`, and 1 for `[9,23)`. Declaring the three independent values in
that use order preserves their allocation. The existing loop-invariant
optimization mechanism is scoped with push/pop; there are no forced register
bindings, empty assembly barriers, fabricated effects or arithmetic padding.

The six loop counts remain 4, 28, 120, 84, 36 and 23. All accesses fit the
required `0x1CC4`-byte work object, the counters cannot wrap, and the two
division denominators remain 10 and 7. The 56 scale values read from retail
at `0x005EA2E0` are finite, integral, and representable as unsigned halfwords.
The sprite IDs at `0x005E9FB0` are loaded as unsigned bytes. Resource filenames,
the `cmpPersona.c` diagnostic string, all four diagnostic sites and the final
task-creation calls are preserved. The target's single-pointer, void-return
contract with `func_0013d8b0` is unchanged.

## Native message-pointer contract

The final residual exposed an incorrect `u64` parameter on
`src/nmCmdList.c:func_002baac0`. Retail saves one native pointer, forwards it
unchanged to `func_002774d0`, and returns 0 or 1. The actual downstream
definition in `src/itfMesManager.c` accepts `u8 *` and passes that pointer to
message-object validation and allocation routines. The corrected contract is
`u8 func_002baac0(u8 *message)`; its return type is retained and all source
callers ignore the result. A non-const pointer agrees with the actual downstream
definition. No numerical 64-bit operation is performed on this input.

The provider and all **19 call sites in nine authoritative caller owners**
are corrected together. Calls already holding pointer bits in word fields
use an explicit pointer cast. These preserve the existing expression's
evaluation and effects. Generated decompiler copies are excluded from the
authoritative caller inventory.

The provider remains exactly **188 executable bytes in its 192-byte window**,
with all **17 relocations resolved**. Its instruction bytes and relocations
are identical before and after the contract correction. This change is
required for the target's actual boundary, rather than an allocation-only
local prototype.

## Measurements

All rows below are immutable complete-owner compilations. Aligned edits are
reported alongside word counts because a missing instruction shifts later
word positions. `active-before` is the assembly fallback and is not a C match.

| Candidate | Emitted bytes | Relocation-masked words | Aligned edits |
| --- | ---: | ---: | ---: |
| Saved draft | 1288 | 277 | 192 |
| Independent initialization phases | 1276 | 275 | 84 |
| Resource contracts and chained store | 1284 | 276 | 87 |
| Slots inside resource arms | 1324 | 287 | 40 |
| Resource declaration/use order | 1324 | 287 | 34 |
| Separate clear arrays | 1332 | 127 | 22 |
| Separate effect fields | 1340 | 34 | 5 |
| Clear-array base order | 1340 | 33 | 4 |
| Native message-pointer boundary | 1332 | 0 | 0 |

Rejected or neutral probes are also preserved. Direct versus explicitly
widened command addresses did not close the boundary error; function-scope
early counters tied the independent scopes; propagation off tied the current
result. Common-subexpression elimination off grew the body to 1460 bytes and
185 aligned edits. None of those probes is in the release.

## Validation and integration

Twenty successful formal before/release compilations cover ten owners and
361 functions. The official verifier changes **326 MATCH / 35 ASM to
327 MATCH / 34 ASM**; only `func_001356d0` is promoted. All **360 other
functions**, including the command provider, preserve their instruction bytes
and canonical relocations. All **11 allocated data sections** preserve their
bytes, alignment and canonical data relocations. The exact target and provider
introduce no new owned data and leave no unresolved relocations.

Lint reports zero errors and the same thirteen pre-existing warnings before
and after. The complete patch passes `git apply --check --whitespace=error-all`.
These are scratch-release results; prime performs the live integration check.

Evidence is retained in
`build/first-party-resume-now/camp/persona356d0/`. `release/` contains complete
proposed owners, the full patch, the exact function body, compiler results and
source receipts. `release/proof/whole-boundary-proof.json` contains the formal
comparison; `semantic-evidence.json`, `canonical-callers.json`, and
`audit-summary.json` record the ABI, data and final audits. `formal/` retains
all twenty commands, complete compiler output, object files and verifier rows.

Prime owns concurrent changes to `src/promoted/code1_001b.c`. Apply only the
two hunks in `release/prime-owned-code1_001b.patch` after the camera changes;
do not replace that live owner with the frozen full proposal. The isolated
hunk was prepared against SHA256
`d3de43bd758520ed28fe8730657a5dd03af90abb0edbca49d4df0ddbbde42f47`.
