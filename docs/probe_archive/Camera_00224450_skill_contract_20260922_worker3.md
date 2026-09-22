# Skill camera and classification contract, 2026-09-22

`func_00224450` is installed as ordinary C in `src/promoted/code1_0022.c`.
The final current-source native gate reports **95 MATCH / 3 ASM**, adding one
first-party recovery. The other nine owners in the coordinated skill family
retain their previous MATCH/ASM counts.

## Exact source and compiler evidence

All paths below are relative to
`build/finish-first-party-20260922/camera-next-01/`.

The complete ten-owner mapping is
`integration-457acdb-02/completed.json`. Each `owner_receipts` entry names the
current source hash, compiler and flags, recursive source inputs, native
object and hash, official report, and completed owner receipt. The camera's
individual receipt is
`integration-457acdb-02/native/src_promoted_code1_0022/completed.json`.

The native b210 compiler, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`,
uses the configured `-O2 -Iinclude` profile. The target reproduces all
**1312/1312 bytes**, **46 resolved relocations**, and no owned data sections.
All **97 other camera-owner functions** retain their bytes and canonical
relocations; allocated data is identical. Across the ten owners, **1056
other functions** retain their bytes, relocations, and allocated data.

Final camera source SHA-256:
`7fa438c0ee7a4161c298066ded5ff82f2510479f88224a01e5cf30122443fa79`.
Final camera native object SHA-256:
`fc68b1c9d3c3ce942c4c91692de42fc1dcc2f8c5330adab5c09b0328f9ce47ca`.
Resolved target SHA-256:
`5b9f567cb1fe8fccc5054d66ee20b65ebf6ff87e1513066defe63faecd4f2d0c`.

`resume-457acdb-01/authentication.json` authenticates the ten original owner
sources, native compiler, flags and dependencies after the fast-forward to
`457acdb30c641ac5d68ce03c80e361aa128ec526`. The upstream vendor profile changes
do not change these owners' compiler settings or inputs.

## Recovered camera state

The priority status scan uses a word-sized predicate. The later camera
preset uses a distinct unsigned halfword. Keeping these values separate,
with the halfword declared before the reset flag, reproduces the observed
saved-register reuse and the halfword constant materialization. The existing
signed-halfword presence helper preserves both retail narrowing operations.
No union, extra initialization, or fabricated state is used by the accepted
candidate.

The final source uses a complete pair of position/quaternion poses and named
roster, party-index, skill, and target-group variables. The exact candidate
and its final naming/layout control are retained at
`camera-native-01/00224450/predicate-preset-order-012/` and
`camera-native-01/00224450/reviewed-complete-poses/`.
The old nonmatching notes are preserved in
`integration-457acdb-01/old-00224450-floor-notes.txt`.

### Original retail omission retained

With target mask 2, global flag `0x400`, skill classification zero, and an
encounter other than `0x215`, retail branches from `0022466C` to `00224888`
without initializing the second pose. `func_001bd560` initializes only the
first pose; `func_001c8cf0` has no pointer to the caller's second pose. The
final pose consumer therefore observes unwritten automatic storage on that
admitted machine-code path. The corresponding target-mask-1 path returns
immediately after its fallback call.

The recovery preserves and explicitly documents that original omission.
It does not add a default pose, introduce a new ABI parameter, or assert an
unproved skill-table invariant. This is a static reconstruction of retail;
no gameplay trace or runtime-table exclusion proof is claimed. The earlier
retail branch/registration evidence remains in
`build/continue-first-party-20260922/battle-geometry-after-rebase/00224450-initialization-audit.json`.

## Coordinated skill classification interface

`include/btl_skill_target_internal.h` now declares:

```c
u16 func_001d7f10(u8 *action, u8 *targets, u16 skill, u32 reverseGroups);
```

The provider reads the classification byte at offset eight of a `0x28`-byte
skill record, so its values remain in `0..255`. Existing command, condition,
and camera consumers use an unsigned halfword, including the retail
`andi 0xffff` after the call. Widening the provider's declared return to the
observed interface preserves the provider's complete native object. The
shared declaration replaces the inconsistent local prototypes in all ten
current first-party owners, including guarded callers.

| Owner | Official MATCH / ASM | Preserved functions besides the new camera |
| --- | --- | --- |
| `src/Battle/btlAICommand.c` | 261 / 2 | 263 |
| `src/Battle/btlBoss.c` | 15 / 0 | 15 |
| `src/Battle/btlEffect.c` | 24 / 0 | 24 |
| `src/promoted/code1_0019.c` | 150 / 1 | 151 |
| `src/promoted/code1_001a.c` | 56 / 15 | 71 |
| `src/promoted/code1_001c.c` | 62 / 1 | 63 |
| `src/promoted/code1_001d.c` | 92 / 2 | 94 |
| `src/promoted/code1_001e.c` | 116 / 4 | 120 |
| `src/promoted/code1_001f.c` | 157 / 1 | 158 |
| `src/promoted/code1_0022.c` | 95 / 3 | 97 |

The Boss and `001f0ff0` callers retain a word local for the skill index, so
the typed interface still emits retail's separate halfword load and move.
The `001c8cf0` caller retains a halfword local, preserving its direct argument
load. Explicit pointer casts repair the actual address arguments in
`001a2c10`, `001f0ff0`, and the group condition. Failed preliminary controls
remain immutable in `skill-contract-01/` and `skill-contract-02/`; the accepted
controls are selected explicitly by the integration manifests.

The `btlEffect` proof initially stopped because the older standalone resolver
lacked the existing `btlCond_MYUSESKIL` name. Its current `FUN_001DA6F0` marker,
the retail HI16/LO16 reference at `001DA7C0`, and all 60 bytes of its body
establish the address. `close_effect_alias.py` supplied that source-derived
symbol address to the unchanged proof and official verifier. It reused the
already completed native object. The evidence is
`integration-457acdb-02/native/src_Battle_btlEffect/source-alias-evidence.json`;
no comparison mask or acceptance condition was relaxed.

## Validation and remaining work

The final eleven-file source set passes focused lint with **zero errors**;
the 16 warnings concern existing optimization pragmas. The report is
`integration-457acdb-02/lint.json`. Scoped `git diff --check` passes. The
installation diff and before/after snapshots are retained alongside the
source-bound native and official receipts.

The remaining camera-owner ASM functions are `00222210`, `00225ec0`, and
`0022a730`. Fresh `00225ec0` controls preserve all siblings and data but remain
nonzero; the strongest aligned control has 35 edits and emits 1984 bytes in
the 2032-byte window. No additional camera function is counted as recovered.
No `0012d630` source edit, vendor implementation edit, commit, push, full game
build, or gameplay execution was performed by this worker during this resume.
