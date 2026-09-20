# Action 001a4800 and returned target-state packet

`func_001a4800` is now ordinary, unguarded C. The complete-owner verifier reports
MATCH for it, and independent relocation application reproduces all 1,148
executable bytes, the four retail alignment bytes, and the entire 52-byte switch
table at `0x00747010`. This is one additional C recovery. `001f3870` was already
matching C; its corrected return contract is not counted as another recovery.

The measurements below use baseline
`0360227d0a4194cb84500a5cf63ac554b38a79c2` and the exact working-source hashes
listed below. Other integration lanes were active concurrently. No complete
image build, commit, push, or whole-project completion claim is part of this
lane's evidence.

## Source changes

The saved `Recovery_20260920_pending/001a4800.c` supplied the successful counter
and state-view shape. The recovered function wraps its scan counter to sixteen
bits, uses the existing offset-first addition helper, and reads the two battle
state fields through one partial structure. These changes recover the observed
loads and branch displacements without extra state or assembly. The measured
`opt_common_subs off` setting is scoped with `push`/`pop`. Missing target callee
declarations now reflect their implemented pointer, parameter, and return
representations; the persona lookup result is explicitly viewed as bytes by
the skill-search caller.

`func_001f3870` now returns `u8 *` and accepts `u8 *action, u8 flags`. The shared
declaration is in `include/btl_target_state_packet_internal.h`, included by both
caller owners and the creator owner. Conflicting local creator declarations
were removed, and callers holding other pointer views explicitly convert to
`u8 *`. The allocator declaration is now its implemented
`u8 *func_00194470(s32 type, s32 workSize)` contract. Its returned pointer remains
in `$v0` through creator initialization and is returned for submission or
dependency setup.

The unsigned flag byte follows the updater's `lbu` and the dynamic callers'
`lbu` loads, rather than introducing signed-byte extension at those calls.
Bit 1 clears action byte `0x28`; otherwise bit 0 increments it. With neither
bit set, a positive value is clamped to one and decremented. Initialization and
destruction respectively increment and decrement the associated unit's
sixteen-bit packet counter at `0xA0`.

The existing `001f14f0` pointer conversion and declaration for `00242990` are
preserved. The packet and action changes do not restore an older whole owner.
The original pending candidate bodies and their hash manifest remain unchanged
as historical evidence.

## Complete-owner and unmasked evidence

All three owners were compiled before editing and again from immutable copies
of the final source, using their configured MWCCPS2 b210 `-O2 -Iinclude` profile.
Per-source receipts retain the logical owner, source copy, compiler, flags, and
source/object SHA-256 values. Input header and configuration hashes are retained
in the proof and gate receipts.

| Target | Executable / window bytes | Resolved code relocations | Owned data | Zero tail |
| --- | ---: | ---: | --- | ---: |
| `001a4800` | 1148 / 1152 | 39 | 52 bytes, all 13 relocated switch entries | 4 |
| `001f3870` | 112 / 112 | 7 | None | 0 |

Every target relocation was applied before comparing to the validated retail
ELF. The table's complete contents were checked after relocation, not merely
its inferred address. The proof also compares every non-target function's
instructions and canonical relocations: 70 functions in `code1_001a.c`, 157 in
`code1_001f.c`, and all 123 in `code1_001b.c` are unchanged. Existing allocated
data is unchanged. The complete `001f` and `001b` objects are byte-identical to
their baseline objects.

The official scoped verifier scans 352 functions and reports **318 MATCH and
34 ASM**, with no other status. Scoped integrity lint reports zero errors and
three inherited H003 advisories outside the recovered action. All four
`test_marker_tripwire.py` tests pass. These gates record exit zero and unchanged
relevant input fingerprints.

## Creator callers and callback dispatch

A word-aligned scan of the validated ELF's loadable segments found eleven
direct calls to `001f3870`, from `001a3f90`, `001a4800`, `001a59a0`, `001a7720`,
`001abbb0`, `001ac700`, `001acf50`, `001ad550`, `001ae800`, `001aed50`, and
`001b1b30`. These agree with the source caller inventory. Each consumes the
returned pointer. The action entry itself is referenced by the dispatch-table
pointer at `0x005f6ed8`.

The three creator slot addresses resolve exactly to the real callbacks. Their
invocation boundaries were also inspected in the complete dispatcher source
and retail windows; storing an address through a `void *` cast alone is not the
basis for this audit.

| Packet slot | Actual callback definition | Retail invocation sites | Argument and result |
| --- | --- | --- | --- |
| `+0x68`, initialization | `void func_001f37b0(u8 *)`, `src/Battle/btlTarget.c` | `001945e0` in packet submission `00194590` | Loads the single work pointer from packet `+0x78` into `$a0`; ignores the return value |
| `+0x6c`, update | `u32 func_001f37d0(void *)`, `src/Battle/btlTarget.c` | `00194848` in state 2 of `00194670` | Loads the same work pointer into `$a0`; tests `$v0` against zero at `00194850` |
| `+0x70`, destruction | `void func_001f3850(u8 *)`, `src/btlTarget/btlTarget.c` | `001946c0` for requested destruction, `00194900` after state completion, and `00194a7c` in bulk cleanup | Loads the work pointer into `$a0`; ignores the return value before unlinking/freeing the packet |

The update definition returns `1` at retail `001f3844`. Its dispatcher already
uses `u32 (*)(void *)`, agreeing with the definition. The work record's first
word is the action pointer; the next byte is flags. Init/destroy read that first
word and the action's unit pointer at `+0x30`, so the dispatcher passes the work
record, not the packet or action directly. Binary checks retain the slot load,
argument load, `jalr`, and zero delay-slot words for all five invocation sites.

The final integration closes the concrete init/destroy callback mismatch found
in the initial audit. Their actual definitions now use `void (u8 *)`, agreeing
with the generic dispatchers. The destruction body explicitly loads the same
32-bit first word through `*(s32 *)work`; changing its formal does not turn that
load into a byte access. The updater remains `u32 (void *)`, which already
agrees with its invocation.

The shared header declares all three actual callbacks and the two function
pointer types. The creator writes `BtlTargetStateHook` and
`BtlTargetStateUpdate` values into their real slots, without function-pointer
casts through `void *`. Fresh proposed and integrated owner comparisons retain
all 19 functions in the initialization owner, all 17 in the destruction owner,
and all 158 in the creator owner, including every relocation and data section.
The three callbacks and creator independently resolve exactly to retail.
The generic dispatcher source itself is unchanged. This scoped correction
does not claim to reconcile unrelated packet types elsewhere in the program.

The complete target IDA and Ghidra references and the available caller
references were inspected and retained. Some already-matched provider and
caller functions are absent from those unmatched-function corpora; this absence
is recorded explicitly. Their retail instructions and active definitions form
the corresponding evidence. The local Ghidra service did not answer the two
queried endpoints; no new decompiler output is claimed for missing entries.

## Parallel battle-provider declaration changes

These declaration changes support the separate battle-calculation lane and
are distinguishable from the action/returned-packet recovery:

* `code1_001f.c`, guarded `001f14f0`, gains the actual
  `s32 func_002411a0(u8 *, u8 *, s32, s32, s32)` declaration. Its existing actual
  arguments already have these representations. The complete enabled guarded
  object remains identical to baseline.
* The same caller gains `s32 func_0023d8e0(u8 *, u16)`, matching the retained
  production provider. The experimental wider formal is **not integrated**:
  both the `001a` and `001f` declarations were returned to `u16` after the
  separate battle proposal left three other caller contexts unresolved. The
  guarded old-style declaration in `001a` remains removed. Existing explicit
  masks and casts stay; a legacy integer-loaded pointer argument in guarded
  `001a7720` is explicitly converted through `u32` to `u8 *`.

Each affected guarded caller was enabled independently in a scratch copy. For
these comparisons only, the independent new `001a4800` promotion is replaced
with its fallback, so its new table cannot obscure the declaration migration.
All non-caller functions and allocated data remain unchanged. The following
scores are relocation-masked **differing bytes**, not words or accepted matches:

| Guarded caller | Before / after emitted bytes | Window | Before / after differing bytes |
| --- | ---: | ---: | ---: |
| `001a43a0` | 1092 / 1092 | 1104 | 481 / 481 |
| `001a59a0` | 7716 / 7716 | 7536 | 5777 / 5773 |
| `001a7720` | 17984 / 17968 | 17536 | 13352 / 13433 |
| `001abbb0` | 2384 / 2384 | 2384 | 1499 / 1499 |
| `001ac700` | 1040 / 1040 | 1040 | 419 / 419 |
| `001ad550` | 1612 / 1612 | 1584 | 964 / 964 |
| `001aed50` | 3160 / 3160 | 3200 | 2203 / 2203 |
| `001f14f0` | 6080 / 6080 | 6096 | 4520 / 4516 |

Five rows have identical complete owner objects. The other three change only
the enabled guarded caller; all non-caller instructions and existing allocated
data remain unchanged. These remain ASM-backed drafts. In particular,
`001a7720` becomes shorter but its positional byte score worsens; this is not
reported as a matching improvement. The current results above replace the
earlier `guarded-final` measurements made during the deferred wide-formal trial.

## Retained fingerprints and receipts

Scratch root: `build/first-party-0360227/action/`.

| Owner | Final source SHA-256 | Final object SHA-256 |
| --- | --- | --- |
| `src/promoted/code1_001a.c` | `eb56a119dc36a6261b73b303962d4d4a41bb56d81349b5151595397a7d48914e` | `66334405967a34abde0efb4a1e8ad4f4afdd414e40a78367be2c4975545d9554` |
| `src/promoted/code1_001f.c` | `2b09b8db1b416ad68d5e94a8bbd5fcd7a2bd40d5554b2b3828245341697e59aa` | `feb7ecee8e6ea8ae0ff58199fece054917e552085ecee649280517feb9638b88` |
| `src/promoted/code1_001b.c` | `e9f081096ec83ef57f69d455b59e9ebad5d97eca703f3920cde632b127890f53` | `37ee1f4de3668c7e6e81e3e70c2d1f6e4caf4e74a2f194530e40f89fa62df9b6` |
| `src/Battle/btlTarget.c` | `cad31daf4144f55534cf34d659e3c07ba8e320b5de6860dffbd9365330895516` | `b8c27508c49fc29a8c6a987e3e0a6006f61edf25e27d4c552271ae7828d9bf7f` |
| `src/btlTarget/btlTarget.c` | `20575944b3c75a5968512939c63e3ad18d62f71b5cb33433b9e852024aabe079` | `e8a386d7a557b865e72368c566192759144284670ce0b068f054a07d6c23d6e8` |

Header SHA-256:
`d3acab483daab423762ceef49214900b309825fb205c26f9fbc1c3a45f5d529a`.
Configured b210 compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Validated retail ELF SHA-256:
`f90675b8a38138ddb5dc5cdf641550f41800fcb86bb499c586073e964fb41836`.

`prime-final/proof.json` contains both final unmasked target proofs and every
sibling/data comparison. `prime-guarded/proof.json` retains the eight final
guarded comparisons with the production `u16` skill formal. The separate
`../action-callbacks/current-proof.json` proves the final callback definitions
and typed slot stores. Earlier `final/` and `guarded-final/` receipts remain
historical checkpoints, not the final source hashes above.
`evidence/callers.json`, `evidence/retail-references.json`, and the initial
`evidence/callbacks/audit.json` retain the inspected reference and invocation
evidence. Private retail bytes and compiled objects remain under ignored `build/`.

Completed terminal receipts: baseline capture/compilation session `71416`,
final target proof/verifier/lint session `68156`, final guarded/marker session
`93502`, and callback binary/source audit session `94249`; all exited zero.
Earlier candidate iterations remain separately named and are not the final
gate evidence. The local reproduction entry point is `check_action.py`;
completed artifacts are preserved, and new runs require distinct output labels.
