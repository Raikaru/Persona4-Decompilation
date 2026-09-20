# Movie resource binding: 0028fc40 recovery

Measured on `work/first-party-0360227`, HEAD
`6de7889e650ab0c6806e94720949207da80e1921`, after the upstream `167e607`
rebase. The logical owner is `src/Event/evtPolygonMovie.c`; all candidate
compiles use its configured MWCCPS2 b210 profile, `-O2 -Iinclude`.
New experiments and proofs are in `build/first-party-resume-167e607/movie/`.
The older `func_0028fc40.md` audit and its saved experiments are unchanged.

## Accepted result

`func_0028fc40` is now authoritative C. The current owner's official verifier
reports **8 MATCH**, previously **7 MATCH / 1 ASM**. The function emits
**2088 bytes / 2096-byte retail window**, with **16 fully resolved code
relocations** and **eight zero alignment bytes**. There is no owned jump
table, and neither the before nor after owner has an allocated data section.

All seven sibling functions retain their complete instruction bytes and
canonical relocations. Each of the eight functions was also independently
resolved against its retail window:

| Function | Emitted/window bytes | Resolved code relocations | Zero tail |
| --- | ---: | ---: | ---: |
| 0028f990 | 504 / 512 | 5 | 8 |
| 0028fb90 | 164 / 176 | 10 | 12 |
| 0028fc40 | 2088 / 2096 | 16 | 8 |
| 00290470 | 128 / 128 | 5 | 0 |
| 002904f0 | 164 / 176 | 11 | 12 |
| 002905a0 | 192 / 192 | 9 | 0 |
| 00290660 | 164 / 176 | 11 | 12 |
| 00290710 | 368 / 368 | 24 | 0 |

The assembly fallback and NONMATCHING guard are removed. Five pointer-copy
locals are replaced by the existing input parameters. The parameters and
record cursors now have descriptive names. The scoped pragma group preserves
the prior propagation and loop-invariant settings while adding lifetime
analysis. Obsolete claims that the entry order was unreachable were removed
from production; the historical audit remains available.

## The source mechanism

The old residual was confined to five entry moves at offsets 0x20 through
0x30. Register assignments were correct, but the first two inputs were saved
after the three resource inputs:

| Shape | Entry sequence |
| --- | --- |
| Retail | `s1 <- a0`, `s0 <- a1`, `s5 <- a2`, `s4 <- a3`, `s3 <- t0` |
| Old copied-input C | `s5 <- a2`, `s4 <- a3`, `s3 <- t0`, `s1 <- a0`, `s0 <- a1` |

Using the input parameters directly restores the argument order. With the
default lifetime setting it assigns different saved registers throughout the
body. Enabling lifetime analysis on that direct-parameter source restores
the retail register assignments as well:

```c
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
u8 *func_0028fc40(u8 *messageContext, u8 *work,
                 u8 *primary, u8 *secondary, u8 *overlay)
{
    /* Existing resource traversal, using these parameters directly. */
}
#pragma pop
```

The following controls were actually compiled as complete owners. These
figures are unmasked positional instruction-word differences, after resolving
all relocations. Each candidate emits 2088 bytes:

| Source shape | Lifetime analysis | Differing words | Aligned edits |
| --- | --- | ---: | ---: |
| Original five copied inputs | Existing setting | 5 | 4 |
| Direct input parameters | Existing setting | 201 | 201 |
| Direct input parameters | Explicitly off | 201 | 201 |
| Original five copied inputs | Explicitly on | 163 | 162 |
| Direct input parameters | Explicitly on | **0** | **0** |

Thus neither removing aliases alone nor enabling lifetime analysis on the
old body closes the function. `formal_lifetimes.py` records the decisive
direct-parameter comparison; `mechanism_control.py` records the copied-input
control. `named_direct_lifetimes/` confirms that naming and declaration cleanup
preserve the exact result.

The existing `opt_propagation off` keeps the record-base loads, row offsets,
switch values and work-field reloads in the observed order. The existing
`opt_loop_invariants on` keeps the third traversal's constant 4 in its
preheader, as shown at retail `0x002903dc`. All settings are confined by
push/pop, and the sibling proofs verify the restored surrounding context.

## Semantics and ABI

The five incoming values are pointers. The sole retail caller supplies the
message context at event state +0x678, the allocated 0x114-byte movie work
object at state +4, and the three resource addresses from reader context
+0x34, +0x38 and +0x3c. There is no float argument or hidden return buffer.
The function returns the work pointer on normal paths and null when the
primary resource is absent. Its current caller discards that result.

The accepted body preserves the observed state transitions: the primary
resource is checked before work is modified; type 27 is skipped in its
record traversal; absent secondary data returns after secondary-field
initialization and before overlay setup; and absent overlay data returns
after its header and section fields are initialized. Work-field reloads
remain in place across stores and diagnostics. Message initialization keeps
the secondary-section, message-pointer and positive-count guards and calls
the existing `s32 func_00290880(u8 *, s32)` provider.

The local formatted-output declaration is corrected to
`s32 func_00440b68(const char *, ...)`, with its two actual format symbols
declared as character arrays. The retail variadic wrapper and existing
canonical header declaration support this boundary. Redundant local
assert-function and filename declarations are removed. These changes preserve
the exact target object and do not modify any external provider.

## Sole caller proposal, for prime integration

The prime authorized a separate frozen-owner compile of
`src/promoted/code1_0028.c`. This worker did **not** edit that live owner,
which also participates in the pending SDK proposal.

The staged repair changes the movie declaration from `void` and integer-held
pointer arguments to the actual pointer return and five `u8 *` parameters.
In `func_00285dd0`, `info` becomes a byte pointer, its reader return is used
directly, and the work/resource members are read as pointer fields. The
proposal does not cast incompatible integer arguments at the call boundary.

All **32 functions**, their relocations, and all allocated data are unchanged.
The **entire before/after object is byte-identical**. The caller target is
also fully resolved: **1128 / 1136 bytes**, **35 code relocations**, eight
zero-tail bytes, and the complete **60-byte / 15-entry table at 0x00748300**.
All table entries resolve to the actual function labels and equal retail.

The merge-ready source and patch are:

```text
build/first-party-resume-167e607/movie/caller/pointer_boundary/code1_0028.c
build/first-party-resume-167e607/movie/caller/pointer_boundary/proposal.patch
```

The same directory contains `comparison.json`, `target-proof.json`, the
object, compiler receipt, and resolved caller bytes. The prime owns merging
these changes with its SDK stage and verifying the final combined owner.

## Experiments, checks and retained evidence

There are **29 retained full-owner target measurements**, including the old
body, exact mechanism controls and named final body. The new attempts cover
real parameter reuse for row/base/result roles, early-return control flow,
input grouping and scalarization, a typed 0x114-byte work view, binding-helper
boundaries, direct parameters and lifetime analysis. Neutral and regressing
measurements remain archived with source/object hashes and focused diffs.
No previous experiment was overwritten.

`official-integrated.json` supplies the eight official MATCH results.
`integrated/proof.json` supplies the complete unmasked function proofs and
seven sibling/data comparisons. `release.json` records the verified live
source, exact diff hash, note hash, measurement inventory and staged caller.
The source diff at integration is **156 insertions / 216 deletions**.

Lint reports **zero errors and two H003 advisories**. One is the preexisting
loop-invariant closing directive after `0028f990`; the other is the recovered
function's measured loop-invariant setting described above. Both are reviewed
compiler-state controls. `git diff --check` passes, and line endings are
preserved. No full build, commit or push was performed.

| Artifact | SHA-256 |
| --- | --- |
| Original movie source | `33655a96bf461976be3c0ae8c6453e92872b83ed454813fe8330c5da55aaa8a4` |
| Original production object | `82ecec990f59a9e5141b5a66f1be584c23f0730a482c0e65477253ef2be7b414` |
| Integrated movie source | `2d03a85fbb8c8c7a5d38ec5b8893c02d80dacf2361632d22396c219aa82fdf4c` |
| Integrated movie object | `d2736a989a57e134be66efed505905ea1d1c030bc50654999ccfd9930c14c2f7` |
| Resolved 0028fc40 code | `81a7393f840d151a1b727cd6e963b1349df3e7bff11b193a828eaa4d1370347b` |
| Frozen caller source | `9945727fa133a948dd8046c1893a71a22ec15586e5fe6942d370ea446feabe51` |
| Staged caller source | `7de4018badc9b12c870e6e3d0c3965079a9b5e0080c96b233bce68dc48a5d782` |
| Before and after caller object | `1d91ae0959422adb24b7f6003c703314293e10aea57b2253e4ee6cad20b106c0` |
| Resolved caller table | `2ada77bfbe8381c4d628075dbfed5a4e3da61f4582b3cd4ca09f00fe6630e716` |

Reproduction commands, from `build/recovered-upstream`:

```powershell
python -B -S tools/verify.py src/Event/evtPolygonMovie.c --json build/first-party-resume-167e607/movie/official-integrated.json
python -B -S build/first-party-resume-167e607/movie/validate.py
python -B -S tools/decomp_lint.py src/Event/evtPolygonMovie.c --json build/first-party-resume-167e607/movie/lint.json
python -B -S build/first-party-resume-167e607/movie/release.py
git diff --check -- src/Event/evtPolygonMovie.c
```

The snapshot helpers reuse a completed object only after verifying its source
and object hashes. The final readback script does not repeat compilation.

## Bounded lifetime-axis follow-up

The prime requested a check of earlier sweep coverage and four related
residuals. `tools/pragma_sweep.py` lists eight Boolean compiler controls plus
optimization-level variants; `opt_lifetimes` is absent. The documented
twenty-eight pair combinations therefore did not cover this axis either.
This does not imply that no individual historical experiment tested it.

Four current owners were frozen in
`build/first-party-resume-167e607/movie/lifetime-frontier/`. The first pair of
measurements retains each candidate's existing settings and compares the
current body with scoped lifetime analysis enabled:

| Target | Logical owner | Baseline words | Lifetimes-on words | Emitted/window bytes |
| --- | --- | ---: | ---: | ---: |
| 001b11c0 | Battle/btlOrder_grouped.c | 5 | 5 | 192 / 192 |
| 00331a20 | promoted/code1_0033.c | 24 | 24 | 1388 / 1392 |
| 0048a980 | promoted/code1_0048.c | 5 | 5 | 584 / 592 |
| 0034ddf0 | promoted/nLine.c | 5 | 8 | 700 / 704 |

The follow-up then pairs lifetime analysis on/off with an actual source-role
change. In 001b11c0 the argument itself stores the masked key; both variants
remain five words. In 00331a20 the original task is saved and the pointer
parameter is reassigned to its work object; both variants become 1408 bytes
and 301 words, adding address lifetimes. In 0048a980 a separate diagonal
difference variable separates that value from the later 1.0f constant; both
variants remain five words. Its existing terminal `lqc2` hardware transfer is
unchanged. In 0034ddf0 the direction parameter is reused for the computed
alpha; lifetime analysis off/on again gives five/eight words. The additional
three words are a coordinate-subtraction/load/addition FPR rotation at
offsets 0x174, 0x178 and 0x17c; the original five conversion-register
differences remain.

All **sixteen target measurements**, plus the four production snapshots, use
the configured logical owner context. Every target relocation was resolved,
and every candidate preserves its non-target functions and allocated data.
No additional candidate is exact, and none of these four live owners was
edited. The source and complete retail/IDA/Ghidra bodies were reviewed before
the associated changes were probed. Known provider-boundary concerns in the
nLine archive remain prerequisites for any future promotion.

`lifetime-frontier/release.json` records the complete source/object receipts,
all sixteen scores, preserved sibling counts, standard-sweep source hash and
live-owner readback. `run.py` and `parameter_roles.py` retain the exact probes.
This follow-up establishes the missing sweep axis and its concrete results;
it does not extend the movie's successful combination into an unmeasured
claim about other functions.
