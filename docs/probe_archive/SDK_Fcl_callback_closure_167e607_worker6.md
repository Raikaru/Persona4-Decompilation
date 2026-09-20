# SDK/Fcl callback closure, 2026-09-20

Worker-6 constructed a complete scratch proposal for the previously blocked
SDK registration prerequisite of `002e8410`. The proposal resolves all 132
incompatible callback definitions identified by the previous 400-role audit.
All 112 affected whole owners compile against frozen inputs. The initializer,
five creators, bounds constructor/setters, SDK registration functions and
dispatcher have resolved-byte proofs against retail. This note records a
reviewable implementation; production integration and whole-image acceptance
remain with the prime lane.

## Frozen inputs and deliverables

All paths below are relative to the repository unless otherwise stated. Scratch
root is `build/first-party-resume-167e607/sdk/`.

The requested base `167e607` is an ancestor of the actual snapshot HEAD,
`6de7889e650ab0c6806e94720949207da80e1921`. `inputs.json` records all 666 copied
source/header/configuration inputs and their SHA256 values. The ten original
`direct03` owners were merged into that snapshot with `git merge-file -p`;
`rebase.json` records the original, archived, current and merged source hashes.
The existing recovery archive and compiler outputs were retained.

| Deliverable under the scratch root | Purpose |
|---|---|
| `stage04/src/`, `stage04/include/` | Exact final proposed source and headers |
| `sdk-fcl-closure.patch` | 118-file, 342,201-byte patch against the frozen input tree |
| `patch-manifest.json` | Base/proposal/current hashes for every patch path |
| `final-proof/manifest.json` | Exact-input object selection, all-owner comparisons and 14 resolved target proofs |
| `final-proof/callbacks.json` | All 400 actual callback definitions, signatures, declarations and registration references |
| `final-proof/registrations.json` | All 241 registration expressions |
| `final-proof/bounds-inventory.json` | Every bounds constructor/setter declaration and call |
| `final-proof/lint.json` | Before/after findings with logical owner paths |
| `final-proof/current-input-drift.json` | Source/header changes made by other lanes after the snapshot |
| `final-proof/patch-checks.json` | Read-only patch checks against frozen and current trees |

Final patch SHA256:
`bf94220f7b325e010bdca29c42e5537adc4be23e3783fb4180ea98bb80d2ca63`.

Proof manifest SHA256:
`5e496d8892d6aad4525b5c96b6158577d03e0cb490816ebd33597f4ffea2d62b`.

`closure.py`, `bounds_probe.py`, `evidence.py` and `review_checks.py` retain the
construction and verification procedures. Stages and compiler receipts are
immutable inputs to later stages. Compiler temporary directories, objects,
logs and JSON outputs stayed inside the scratch root. No production source,
header, configuration or Git state was written by this worker.

## SDK contract and complete migration scope

The shared registration header declares exactly the two real providers:

```c
typedef s32 (*SdkTaskUpdate)(u8 *task);
typedef void (*SdkTaskDestroy)(u8 *task);

void *func_00451de0(const void *name, s32 priority, s32 delay, s32 freeDelay,
                   SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work);
void *func_00451fc0(void *parent, const void *name, s32 priority, s32 delay,
                   s32 freeDelay, SdkTaskUpdate update,
                   SdkTaskDestroy destroy, u8 *work);
```

The final inventory contains 400 compatible actual definitions, 257 compatible
callback declarations, and 241 calls in 103 owners: 58 root registrations and
183 child registrations. The prior 116 scattered SDK declarations are replaced
by two declarations in one header. The reference inventory found no direct C
calls to the 132 definitions whose signatures required repair.

Unused task parameters replace false `(void)` callback signatures. Existing
byte/void pointer parameters become `u8 *`; callbacks whose bodies use a typed
task pointer or an EE address word take `u8 *sdkTaskBytes` and convert that
object address to the existing local representation. Registered function
arguments are actual function names. The proposal introduces no cast from an
incompatible function-pointer type to the SDK callback type.

The actual SDK owner uses `SdkTaskUpdate` and `SdkTaskDestroy` fields at offsets
`0x30` and `0x34`, with `u8 *work` at `0x38`. The dispatcher calls the update
with the task object, as retail does at `00451520`/`00451524`; it does not pass
the work allocation. Existing handler values zero and `-1` skip invocation.
An update result of zero retains the handler; another word replaces it;
`-1` starts destruction when the task is in state two. Consequently the
signed word return is required. The remaining integer-to-handler conversion
in the dispatcher represents that retail replacement-address protocol.
Cleanup calls at `0045170C`, `00451874` and `0045223C` likewise pass the task
object and ignore a return value. Parent and work address conversions agree
with the actual provider and these dispatch paths.

The previously unresolved paths are included:

* `src/cldScheduler.c` uses typed locals for the real update `00260020` and
  destroy `00260440`, instead of integer-address locals and an integer SDK
  prototype.
* `src/promoted/k_fldUnit.c` declares `D_005F15B0` as `SdkTaskUpdate[]`. Its
  retail words are zero, `00166C80`, `00166E30`, `00167120`; the three non-null
  definitions already have the required `s32(u8 *)` signature. Registration
  now indexes that typed table directly.
* The `00192790` provider is `btlUpdateDraw3DFrontTask`, not an absent generic
  body. Its definition now returns `s32` and accepts `u8 *`, retaining its
  existing zero result. `00192e90` registers the canonical name. Both symbol
  names resolve to `00192790`; the complete 460-byte caller resolves exactly
  to retail. The proof reads the frozen canonical function-name map in
  `config/symbol_addrs.txt`, in addition to the recovered data map.

Two additional declaration errors surfaced during compilation and were fixed
from actual use. `frFont.c:func_00274970` stores a task pointer in its existing
EE integer handle field using an explicit `(s32)` conversion. Its 57 functions
are preserved. `tnEffect.c:func_00481a20` receives integer priority `0xC7` from
`code1_0010.c:func_00100e60`; the concrete call is at the frozen
file's line 782. Both the real `func_004b3180(s32)` provider in
`Graphics/Effect/effCrossfade.c` and SDK registration consume that integer.
The proposal corrects the `00481a20` parameter and local `004b3180`
declaration to `s32`; all 18 tnEffect functions are preserved.

## Missing update returns recovered from retail

These were actual void-returning definitions in the prior inventory. Every
return path was inspected before adding a result; the proposal does not
infer a return value merely from caller expectations.

| Callback | Retail return evidence | Proposed result |
|---|---|---|
| `00148280` | Zero at `001495E8`; early path sets zero at `00148318` before the common epilogue | Zero |
| `0016BDD0` | Zero at `0016E1D0`; early zero paths at `0016BE18`, `0016BE34` | Zero |
| `00182BC0` | Zero at `001837BC`; early zero at `00182BF8` | Zero |
| `00183B80` | Zero at `001850F0`; early zero at `00183BD4` | Zero |
| `00185850` | Zero at `001865D4`; early zero at `00185888` | Zero |
| `0018A200` | Zero at `0018BAA8`; early zero at `0018A234` | Zero |
| `00332BB0` | State 18 tests `00122720`; `0033BD74` materializes `-1`, ordinary exit `0033BD80` materializes zero | `-1` for that completed state, otherwise zero |

The corresponding disassembly is under `asm/nonmatchings/code1_0014/`,
`code1_0016/`, `code1_0018/` and `y_fclItemShopDraw/`. These large inherited
nonmatching C drafts remain guarded. Their signature/return repairs are part
of the contract closure; they are not counted as newly decompiled functions.
Whole-owner comparisons preserve the existing active assembly functions.

## Bounds prefix: representation and actual consumers

Retail `002b29e0` writes converted signed width and height at stack offsets
eight and twelve, leaves the preceding eight bytes unspecified, and copies
the sixteen-byte record. The original source represented the prefix as two
uninitialized floats. The final proposal uses an explicit byte-copy view:

```c
typedef struct {
    u8 data[16];
} __attribute__((aligned(4))) FclBoundsBytes;

typedef union {
    struct {
        u8 reserved[8];
        s32 width;
        s32 height;
    } dimensions;
    FclBoundsBytes representation;
} FclBoundsPacket;
```

The constructor assigns only `val.dimensions.width` and `.height`, then
copies `val.representation` into the output's representation member. Every
forwarding copy uses `FclBoundsBytes` or the representation member. Thus
source-level prefix reads are unsigned-character representation copies;
there is no evaluation of an indeterminate integer or float prefix member.
The compiler retains the retail FPU load/store block-copy instructions,
which transfer these bytes without interpreting the prefix in arithmetic.
The prefix remains unspecified. The evidence is for the configured EE/MWCC
build and does not assign a stable numeric meaning to those bytes.

The four-byte alignment is the alignment of the actual sixteen-byte records
and their integer dimensions. It is material to code generation: an
unaligned character record produced byte loops. No fabricated padding value,
zero initialization or arbitrary callback conversion is used.

All 23 constructor call sites are inventoried: five initializer records,
two common digit records, one menu record, eleven card-effect records and
four combine-draw records. There are seven direct bounds-setter calls and
five animation-setter calls. The previous scalar float forwarding in the
common/combine-draw consumers has been replaced with character-only copies,
including guarded draft paths.

| Consumer path | Prefix destination | Numeric fields actually consumed |
|---|---|---|
| `002b5db0` to rectangle update `002b52a0` | Work `0x120..0x127` | Signed width/height `0x128/0x12C`; separate position `0x134/0x138` |
| `002b5ef0` / `002b5fd0` animation inputs to `002b52a0` | Work `0x158..0x15F`, `0x168..0x16F` | Signed dimensions `0x160/0x164`, `0x170/0x174` |
| Four combine-draw forwards through `002b81f0` to `002b7f20` | Work `0x08..0x0F` | Position `0/4`, signed width/height `0x10/0x14` |
| `002ba080` / `002ba5d0` digit records to `002b9ab0` | Digit work `0x204..0x20B` | Signed dimensions `0x20C/0x210`, multiplied by scale `0x194/0x1A0` |

The `002b52a0` vertex loop writes `0..0xFF`; its color source span is
`0x110..0x11F`. Neither overlaps the record prefix. Its packet callback
`002b5120` reads render flags at `0x184/0x18C`, after vertices have been
formed, and does not consume the prefix. The only external `002b5da0`
getter use tests the work state byte at offset zero. `002b7f20` forms its
vertices from positions and dimensions; its packet callbacks `002b6da0`
and `002b6ea0` set render state. The generic `002b89a0` update works inside
the record beginning at digit work `0x104`; its accesses do not reach the
`0x204/0x208` prefix. `002b9ab0` uses only the initialized dimensions.
These source and retail access paths establish that the carried prefix has
no numeric consumer in the recovered bounds paths.

Measured whole-owner alternatives, retained under `bounds-probes/v02/`:

| Representation copy | Constructor bytes / 80; differing bytes | Setter bytes / 112; differing bytes |
|---|---:|---:|
| Explicit `memcpy` | 72; 50 | 100; 63 |
| Explicit unsigned-character loop | 92; 44 | 128; 109 |
| Character aggregate, default alignment | 92; 43 | 132; 105 |
| Character aggregate, four-byte alignment | **80; 0** | **104; 0** |

The aligned character-copy variant preserves both entire owning objects,
including all siblings and allocated data. The final combined candidate
also preserves the two animation setters and every previously active
caller. The earlier opaque mixed-member aggregate probe was useful for
layout measurement; the final source uses the character representation.

## Verification and integration boundary

All 112 owner pairs compiled. Exactly 3,553 of 3,554 previous function bodies
are byte-identical; `002e8410` is the intended change. Exactly 3,553 relocation
lists are unchanged; the sole renamed-symbol list belongs to `00192e90` and
resolves identically. All allocated data contents, sizes, alignments and
relocations are preserved. The old 74-owner historical registration exercise
was not used as acceptance evidence.

`final-proof/manifest.json` selects each final object by exact source hash
and recursively checked include dependencies. It validates the selected
object and baseline receipt hashes. Later phases compile only owners with
changed final inputs; unchanged source text with changed transitive headers
requires a new measurement. No second full-owner run was substituted for
these dependency checks.

Resolved retail proofs:

| Function | Body / window | Relocations |
|---|---:|---:|
| `002e8410` | 3256 / 3264 | 148 |
| `002b5c90` | 264 / 272 | 12 |
| `002b8150` | 160 / 160 | 12 |
| `002b9f90` | 228 / 240 | 12 |
| `0034ad70` | 220 / 224 | 12 |
| `0034b740` | 204 / 208 | 12 |
| `002b29e0` | 80 / 80 | 0 |
| `002b5db0` | 104 / 112 | 0 |
| `002b5ef0` | 216 / 224 | 0 |
| `002b5fd0` | 280 / 288 | 1 |
| `00192e90` | 460 / 464 | 41 |
| `00451de0` | 480 / 480 | 12 |
| `00451fc0` | 120 / 128 | 2 |
| `00451430` | 376 / 384 | 15 |

Every listed suffix between body and window is confirmed zero in retail.
These are resolved byte comparisons, not a claim that this worker ran the
full authoritative verifier. The compiler logs contain the pre-existing
Python `pywin32_bootstrap` startup warning and MWCC `MWCIncludes` warning;
successful final receipts and object checks establish completion.

Focused before/after lint reports zero errors and no new findings: 73 H003,
11 H001 and two H007 advisories on each side. The patch passes
`git apply --check` against the frozen input tree. Its current-tree check
fails only at `src/promoted/code1_0038.c:1`, where another lane has changed
the source. Hash comparison additionally flags `code1_0021.c`, even though
its hunks may still apply. Both must be merged with the prime's current
versions. The changed live `include/shd_misc_internal.h` affects eight of
the frozen owners; their names and exact hashes are recorded in
`final-proof/current-input-drift.json`.

The final source proposal has no unresolved SDK callback or bounds-prefix
blocker identified by this worker. Prime review, conflict reconciliation,
verification of owners whose current inputs differ, and the whole-image
gate are the remaining integration work. This worker performed no commit,
push, full build or live installation.
