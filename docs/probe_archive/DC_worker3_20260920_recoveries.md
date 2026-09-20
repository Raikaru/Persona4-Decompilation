# datCalc recovery, worker 3, 2026-09-20

Baseline: `0360227d0a4194cb84500a5cf63ac554b38a79c2`, branch
`work/first-party-0360227`. Owner: `src/Main/Battle/Data/datCalc.c`.
All experiments used its configured MWCCPS2 b210 with `-O2 -Iinclude`.
New evidence is under `build/first-party-0360227/datcalc/`; earlier worker 7
reports and saved experiments were read without modification.

## Accepted: 002411a0

The initial sixteen-word residual was one index/element register exchange.
Declaring `idx` after `lvl` makes the compiler use retail's registers. The
accepted order is `tmp22`, `lvl`, `idx`. Removing the five unused declarations
`kind`, `id`, `tab`, `i`, and `found` preserves this result. The existing scoped
loop-invariant/common-subexpression controls, repeated skill searches and
native conversion boundaries are unchanged.

The production guard and assembly fallback were removed. The actual five-argument
signature remains `s32 func_002411a0(u8 *, u8 *, s32, s32, s32)`; retail's fifth
argument is passed by `func_001f14f0` and unused by this callee.

`verify411.json` reports **76 MATCH / 4 ASM**, previously 75 / 5. This is the one
new accepted match from this worker. `integrated411/proof.json` proves:

| Function | Object/window bytes | Resolved relocations | Retail zero tail |
| --- | ---: | ---: | ---: |
| 002411a0 | 2588 / 2592 | 70 | 4 |
| 00232d80 | 1304 / 1312 | 24 | 8 |
| 00233bc0 | 1280 / 1280 | 23 | 0 |
| 00242990 | 3252 / 3264 | 92 | 12 |

All 79 non-target functions retain their bytes and canonical relocations.
All allocated data sections, their alignment, bytes and canonical relocations
are unchanged. The lint report contains zero findings, and the source diff
passes `git diff --check`.

Accepted complete-owner source SHA-256:
`1a7be2001e890df884a9f7c3528fdf3376c797d099656d9fbfc2d3d7c506dd1e`.
Object SHA-256:
`bcc859cec582d32d36da5c7d3dae1b5ce6ebf60b13a2373bc8ed930353953e2d`.
The baseline object is `production/owner.o`; `integrated411/` retains the full
accepted source, object, compiler receipt and resolved target binaries.

Reproduction commands, from the repository root:

```powershell
python -B -S tools/verify.py src/Main/Battle/Data/datCalc.c --json build/first-party-0360227/datcalc/verify411.json
python -B -S build/first-party-0360227/datcalc/prove411.py
python -B -S tools/decomp_lint.py src/Main/Battle/Data/datCalc.c --errors-only --json build/first-party-0360227/datcalc/lint411.json
```

The first instruction-alignment reports lacked a disassembler because `-S`
also excludes the user package directory. Their alignment counts are invalid
and are not evidence for this recovery. Raw-byte, full-relocation and sibling
proofs were independent of that decoder. Later scripts explicitly load the
installed user package directory before importing the decoder. Capstone's
generic MIPS decoder still misnames some EE packed instructions; raw words
remain authoritative.

## Archived: exact 00238940 body, pending caller closure

`DC_worker3_00238940_exact_pending_callers.c` preserves the complete proposed
body. Swapping the previous draft's `count`/`index` declaration order to
`index`, `count` closes its ten remaining words. This was measured in the
complete current owner, with both the declaration and definition of
`func_0023d8e0` changed together to `s32 func_0023d8e0(u8 *, s32)`.

The provider itself masks the skill's low sixteen bits at retail addresses
`0023d8f0` and `0023d98c`. At `00238d34`, 00238940 forwards its original skill
register without a caller-side mask. The wide declaration preserves the
provider's complete 208-byte code and its five resolved relocations.

The exact draft emits **3728 / 3728 bytes**, with **60 fully resolved code
relocations**, no missing tail, and the complete ten-entry **40-byte owned
table at 00747c10**. All ten `R_MIPS_32` entries resolve to the actual current
function's labels and equal retail. The table is the only newly allocated
data section: every preexisting allocated section and every one of the 79
non-target functions retains its bytes and canonical relocations. This also
re-proves 002411a0 and all three protected matches in the same candidate object.

Evidence directory:
`00238940/index_before_count_wide_provider/`.
`fully_resolved.json` contains the target/table proof, and
`complete_owner_proof.json` additionally proves the provider, protected
functions and the exact allocated-data difference.

Complete candidate source SHA-256:
`b639d1ee865c96395f1c047c007e1ac9c8bad5acecad99cb5ea6a63968af941b`.
Complete candidate object SHA-256:
`7af911c3b9f26172032ffc0ffa88f3ab117ae2c106b3fa6496916e3c2cef1338`.
Resolved 00238940 code SHA-256:
`e6aa2ab5dc7d48d7a9d1d65403d88db26b7fdb2bd52095e6e318768a0aa6d6ba`.
Resolved owned-table SHA-256:
`5ffef224f812161e8ba0c30fe8747903541fd96851e83d292dce73249d052ad3`.

The frozen candidate's official verifier result is **76 MATCH / 3 ASM /
1 STALE_NONMATCHING**: the replacement preserved the original NONMATCHING
marker, and 00238940 has zero normalized difference. This is not an accepted
production match. The production 00238940 guard and the provider declaration
remain unchanged because the external caller work below is not closed.

## External caller audit and remaining work

The prime authorized scratch audits of the following eight additional owners.
No source edits from this audit were applied to them. Each `provider/<stem>/`
directory retains `before/`, `wide/` and named full-owner candidates with
compiler receipts, canonical sibling/data comparisons and focused differences.
The audit changed all declarations within each owner, including function-local
declarations, to the same `s32` skill contract.

| Owner | Functions compared | Outcome of wide declaration |
| --- | ---: | --- |
| btlAICommand | 263 | All function bytes, relocations and data unchanged |
| cmpSkill | 16 | Exact after widening 0013ac30 and its declaration to s32 |
| datScript | 4 | 00245030 swaps its unit/skill load order at two calls |
| shdSkill | 15 | Exact forwarding needs 00114cb0/00114dc0 widened; 001138c0 then moves one load |
| code1_0019 | 151 | All function bytes, relocations and data unchanged |
| code1_001d | 94 | 001da5f0 changes nested unit/skill argument load order |
| code1_001e | 120 | All function bytes, relocations and data unchanged |
| code1_0020 | 146 | 0020b6d0 changes the skill's halfword spill and load order |

The exact cmpSkill repair is `provider/cmpSkill/wide_caller/`: both
`func_0013ac30(u16 arg0)` occurrences become `func_0013ac30(s32 arg0)` in
addition to the provider declaration correction. Its retail code explicitly
masks the comparison operand while forwarding the original argument. All 16
functions and allocated data then equal the baseline.

For shdSkill, `wide_caller_and_draw/` widens 00114cb0 plus the definition and
forward declaration of 00114dc0. Its only remaining changed function is
001138c0, still 1384 bytes: `lhu a2, 0xa(s5)` moves from offset 224 to 218,
before the position/color argument loads. All other function bytes and
allocated data equal baseline. Pointer-backed payload fields and equivalent
sixteen-bit field views did not change that remaining load order.

For code1_001d, the baseline 001da5f0 is 76 bytes in an 80-byte window. A plain
wide declaration produces 72 bytes, removing the early action-pointer copy
and loading its skill before the final unit-pointer load. Explicit unit/action
locals, `register`, direct equality/XOR forms and typed storage queries did not
restore the original sequence. Scoped propagation-off forms retain 76 bytes
but use a different load/copy sequence.

For code1_0020, the baseline 0020b6d0 is 812 bytes in an 816-byte window. The
plain wide declaration produces 816 bytes: the saved skill becomes a native
register spill plus a mask instead of retail's `sh`/`lhu` pair at stack offset
D0. `memory_10/` and `addressed_13/` preserve actual halfword memory storage
with scalarization disabled and reduce eleven aligned edits to four, at 808
bytes. They still use DC or DE instead of D0, omit the preheader mask, and
load the skill before the unit. No artificial padding or alignment was added
to force that slot. Signed storage, explicit casts and inline storage readers
did not resolve it.

The datScript audit was released to the separate caller-closure worker. Its
initial `before/` and `wide/` objects retain the original four-word load-order
residual at offsets 4e8/4f0 and 5c0/5c8. The final exact repair is recorded below.
The prime owns code1_001a, code1_001b and code1_001f; this worker did not edit or
compile those active owners. Their provider-declaration restoration is handled
by the prime, preserving the five-argument 002411a0 declaration and the packet
and action changes.

Do not promote 00238940 or widen the production provider until all real caller
contexts preserve their existing exact implementations. The durable candidate
and complete table proof remove the target itself from that remaining problem.

## Final status of the four caller contexts

The datScript closure uses `(u8 *)(uintptr_t)D_00881460[0]` as the first argument
at both wide-contract queries. This restores the unit load before the skill
promotion. Saved proof at
`build/first-party-0360227/datScript-closure/current/proof.json` reports all four
functions officially MATCH, unchanged function bytes/relocations and allocated
data, and exact 00245030 code with 334 relocations and its complete 140-byte,
35-entry table. The scratch candidate is in `unit_integer_transport/` alongside
that proof directory. Final production readback remains the original `u16`
contract; this exact wider-contract repair is retained for the remaining work.

| Caller context | Best retained object/window bytes | Final residual |
| --- | ---: | --- |
| datScript, 00245030 | 5152 / 5152 | Closed: exact code and complete owned table; all four owner functions preserved |
| shdSkill, 001138c0 | 1384 / 1392 | Two aligned edits: the skill `lhu` moves from 0x224 to 0x218 before the position/color loads |
| code1_001d, 001da5f0 | 76 / 80 | Four aligned edits at the original size: the action-pointer copy and unit/skill load sequence differ |
| code1_0020, 0020b6d0 | 808 / 816 | Three aligned edits: missing preheader mask and halfword slot 0xDC instead of 0xD0; four bytes shorter than the exact baseline |

The prime supplied the datScript result after the initial release. A bounded
six-candidate follow-up, `uintptr_followup.py`, tested the same conversion on
real unit pointers and existing complete aggregate objects. The 001da5f0
candidate `provider/code1_001d/uintptr_unit/` retains the previously observed
76-byte/four-edit residual. Aggregate pointer round-trips in shdSkill regress
the two-edit residual to five through seven, so `wide_caller_and_draw/` remains
the best candidate there.

For 0020b6d0, `provider/code1_0020/uintptr_unit_halfword_storage/` fixes the
unit/skill load order and improves the earlier four-edit halfword-storage draft
to three. Its actual `u16` field still resides at 0xDC instead of retail's 0xD0,
and its store omits the preheader mask. The ordinary scalar form with only the
pointer conversion remains ten edits at 816 bytes. No follow-up candidate was
applied to production, and no new target was opened.

## Final owner release

All nine owners are released. The actual source diff in this lane is confined
to datCalc: **9 insertions and 19 deletions**, promoting 002411a0, updating its
measurement comment and removing five unused locals. The eight external owners
are clean against HEAD and byte-identical to the source retained by their
`provider/<stem>/before/compile.json` receipts. The datCalc source still equals
its accepted `integrated411/compile.json` receipt. The object files' SHA-256s
were checked against all nine receipts; this final readback does not rerun
compilation.

`func_0023d8e0` retains its production `u16` skill parameter in both the datCalc
declaration and definition and every declaration in these eight external owners.
00238940 retains its assembly guard. The accepted owner result remains
**76 MATCH / 4 ASM**, with 79 unchanged siblings and unchanged allocated data.

| Released source | Git status | Source SHA-256 |
| --- | --- | --- |
| src/Main/Battle/Data/datCalc.c | Modified, 9+/19- | `1a7be2001e890df884a9f7c3528fdf3376c797d099656d9fbfc2d3d7c506dd1e` |
| src/Battle/btlAICommand.c | Clean | `3d49a1f953a980aae76f0300fcd2ba6ec60fda683af84a691542b25e8e3951df` |
| src/Camp/cmpSkill.c | Clean | `b07658653fca03d8b57f5fd1ea7fce277ae83a1e9510a3b710e855df18eef270` |
| src/datScript/datScript.c | Clean | `a45593ae984e2b937227c1599902fe2d36dbaeb0dee46071ac07efbe01413cbe` |
| src/shdSkill.c | Clean | `975774045f344a736c1184b1271c54a63694fa14894ddacdfe3ca6004fd650e0` |
| src/promoted/code1_0019.c | Clean | `cfba75a8c65d8600e9eb5d81b16941ec759e245b30471e6c0a327c0aa23fbbd7` |
| src/promoted/code1_001d.c | Clean | `e18cb8ef8fa97686559040013985b7e7fc1b25ab9c03bd67024e92bfeb39dbdb` |
| src/promoted/code1_001e.c | Clean | `fafb031e8c1791363620a34fddfdd10354d7f2dee11f74fc4c31d5aeff1fc96d` |
| src/promoted/code1_0020.c | Clean | `a048e8e1475570d45792fd14ff2b7c1e68e05bb005c15055ec259f7bfa98485b` |

`build/first-party-0360227/datcalc/release_owners.json` records the complete
source/object hashes, exact diff hashes, current branch/HEAD, note hashes,
unchanged provider declarations and retained caller-closure proof. The only
files added outside the ignored build lane are this note and the archived
00238940 proposal; both are untracked at release.
