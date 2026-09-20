> Durable preservation, September 20, 2026: **7 resolved differing instruction
> words; not MATCH; no source integration.** The complete reviewed report below
> is preserved verbatim as historical evidence from its stated measurement HEAD.
> Statements about live owners and scratch-only work describe that earlier run.
> The companion `Yajima_002b0250_typed_floor_20260920.c` adds the support declarations
> needed to interpret the unchanged measured body. Its separate wrapper has not
> been compiled for a new score. Pending API obligations remain unapplied.

# Yajima map-tile initializer: 002b0250

Measured September 20, 2026 at HEAD `6d950a12d36f08706cd42225d5513e5a50d25748`. This is a new typed C floor,
not an exact MATCH or a production promotion. The live owners remain unchanged.
The accepted 002e6280, 002e5ae0 and 002b4ad0 families were not reprobed.

The complete resolved comparison improves **282 to 7 differing
instruction words**. The selected initializer emits **1356 bytes in the 1360-byte
retail window**. The remaining four bytes are retail zero alignment. Its
six-entry switch table is exact, including all relocation targets. The retained
frame is the retail 0xb0 bytes.

## Source recovery

The current frontier's shop constructors and cleanup entries already match.
The selected actual owner is `src/promoted/y_smap.c`, function `func_002b0250`.
Its old guarded draft contained a different kind sentinel, an if-chain where
retail has a switch table, and unsigned/signed coordinate lifetimes that did
not reproduce the table, frame and control flow together. The old baseline
emits 1368 bytes, has 278 masked differing words, 282 resolved
differing words, and 273 aligned edits.

The new source describes the real 0x160-byte allocation and its texture bounds,
draw coordinates and special-cell fields. A two-float output array supplies
the eight bytes actually written by the centering provider. No narrow object
is accessed as a wider object to manufacture stack storage.

The kind is interpreted as an unsigned byte. Retail nevertheless compares that
value against -1. The candidate preserves this redundant guard, including the
fact that kind 255 still allocates. The orientation parameter is an unsigned
byte, as shown by all its retail `andi` uses. The outer low-kind branch and the
six-case switch retain their distinct store sequences.

The texture update captures its left bound before forming the span, then uses
that span for both bounds. This restores the two retail load/latency sequences
without inserting padding. The source-cell bytes retain their parameter homes
until the allocation and dispatch are complete. Signed row and column snapshots
then belong to the 2x2 scan. The task handle and work allocation remain separate
values. A scoped `opt_propagation off` preserves the redundant guard and these
load boundaries; the final source uses no ordinary ASM, volatile steering or
synthetic storage.

## Relocations, tables and object isolation

`ready/proof.json` independently resolves all **18 code relocations**. The table
at **00748840** is exactly **24 bytes**, with six R_MIPS_32 entries for kinds
9 through 14. Each resolved destination is aligned and lies within the emitted
function. The switch's six-entry bound is tested across all 256 kind values;
the instruction harness never reads beyond byte 24 of the table. The following
eight retail alignment bytes are verified zero and are not counted as entries.

All **35 sibling functions** retain their bytes and canonical relocation
records. Both pre-existing allocated data sections retain their bytes, alignment
and relocations. The only added allocated data is the initializer's proved
switch table.

Seven words remain different: `0x440`, `0x450`, `0x468`, `0x484`, `0x4e0`, `0x4e4`, `0x4e8`. They swap the source-row and signed
column-snapshot registers. The actual operations, call boundaries, branch
targets, table destinations and frame agree.

## Provider and caller contracts

The complete scratch owner corrects `func_002b2bd0` to its actual
`void(f32 *, s64, f32, f32, f32, f32)` contract. The map getter is
`s32 *func_00155280(void)`; byte views explicitly convert its result before
byte-offset arithmetic. Both providers are read and frozen in `evidence/`.
The task registration uses `sdk_task_registration.h` and the actual update and
destroy callback contracts. The destructor retains its one-pointer free call.

The sole real caller `func_002ae630` has ten calls to the initializer and passes
orientation literals 1, 2 or 3. Its declaration is reconciled to the initializer's
unsigned orientation. `contracts/caller-ready/proof.json` compiles this actual
caller from the final selected owner: its **3460 bytes** and relocation records
are unchanged. The complete caller-active comparison preserves all 35 other
functions and three pre-existing allocated data sections.

The indirect allocator is the `rwcalloc` member of `RwMemoryFunctions`, whose
canonical contract is `void *(size_t, size_t, RwUInt32)`. The primary header and
`_rwMemoryOpen` provider are frozen in `contracts/evidence/`. Retail 003e1b10
installs the caller-supplied fourth slot at 008873f4, or the default HCalloc
wrapper. The initializer preserves the arguments `(1, 0x160, 0x40000)`; no
particular runtime allocator binding is assumed from its initially zero slot.

The existing allocation diagnostic provider declares `void(void)` even though
retail allocation sites supply file and line. The separate scratch proposal
`contracts/allocation-site-proposal/owner.c` changes only this no-op definition
to `void func_0044ea90(void *file, s32 line)`. Its full provider object preserves
all **13 functions** and has no allocated data. The no-op remains exactly
8 executable bytes in its 16-byte window. No provider is edited live, and the
proposal is a prerequisite to a future source integration.

## Bounded execution and remaining map-data precondition

The target-specific EE harness executes the real retail bytes and the fully
relocated candidate bytes with bounded memory and typed provider stubs. It
checks actual call arguments, return values, every work write, map read, and
table read. External stubs destroy caller-saved registers. All **6020 defined
states** agree, covering every byte kind, orientation and variant boundaries,
both stored-coordinate mismatch exits, each possible special-cell hit, complete
search exhaustion, and null/non-null task-creation results.

The maximum table access ends at byte 24 of 24. The maximum work write ends at
byte 346 of 352. The centering provider writes exactly the declared eight-byte
output. All defined map reads stay inside the known 0x18f8-byte provider buffer.

A further **384 synthetic grid-edge states** also produce identical results
or identical failing reads. Six states with source row 23, columns 10 through
15, and no early special-cell hit exceed the known map buffer in **both retail
and candidate**. The caller scans 24 rows and 16 columns, so a universal safe
2x2 neighborhood cannot be inferred from its loop bounds alone. Real map data
may exclude these placements, but this lane does not establish that global
invariant. This is a documented existing data precondition, not a universal
runtime no-overread claim. The candidate introduces no widened table/work reads
and preserves the retail map addresses. Do not promote this floor on the basis
of these bounded executions.

## Validation and reproduction

The guarded proposal has zero lint errors and the same one H003 warning as the
unchanged live owner, in an unrelated `opt_loop_invariants on` scope. The target's
optimization scope has its local explanation. No game execution, whole-image
build, commit, rebase or publication is claimed.

All work is under `build/first-party-resume-now/yajima-init-worker5/`.
`ready/` holds the measured C, full owner, object and resolved proof.
`proposal/` holds the guarded review owner and unapplied source/provider patches.
`contracts/` contains the caller/provider objects and receipts.
`execution/proof.json` records the bounded execution results and six edge cases.
`final-inputs/manifest.json` records every compiler dependency; existing owner and
provider snapshots remain in their original evidence folders. `final-inputs/`
also freezes resolver metadata and symbol maps. Compiler binaries
and the retail ELF are identified by hash, not redistributed in this proposal.

| Artifact | SHA-256 |
| --- | --- |
| Unchanged live owner | `3666d5435e4279650381d354863433a7d465f41a0b52feffcdedd5e9643d7ffc` |
| Complete selected owner | `2ecd60d1b7473049e57214decfbf8dc5914fbbb800029f6a1b9f82f1db81d46d` |
| Selected body | `c36eb71039db867f6e230eded1b9149457067ca5513dacf5c911d888ecb22f5b` |
| Selected object | `c709261d5258ffdce1280a0edecc1626dd54a0f9526fcd6d636dc5cc8e0b6342` |
| Configured b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Retail ELF | `f90675b8a38138ddb5dc5cdf641550f41800fcb86bb499c586073e964fb41836` |

Each target trial below is a completed serial full-owner compile with the
configured MWCCPS2 3.0.1 b210 profile `-O2 -Iinclude`. Production control rows
use ASM and are not C progress. The masked score is kept separate from the full
resolved comparison above.

| Trial | Emitted bytes | Masked words | Aligned edits |
| --- | ---: | ---: | ---: |
| `active-cell-coordinate-scopes` | 1348 | 223 | 19 |
| `allocated-tile-work` | 1348 | 223 | 19 |
| `baseline-guard` | 1368 | 278 | 273 |
| `baseline-production` | 1360 | 0 | 1 |
| `cell-index-register-storage` | 1356 | 7 | 7 |
| `cell-lifetime-coalescing` | 1356 | 7 | 7 |
| `descending-low-kind-dispatch` | 1332 | 294 | 42 |
| `parameter-byte-homes` | 1348 | 223 | 19 |
| `ready` | 1356 | 7 | 7 |
| `retail-switch` | 1356 | 238 | 100 |
| `sentinel-and-provider-contracts` | 1344 | 304 | 278 |
| `sentinel-helper-boundary` | 1332 | 294 | 25 |
| `sentinel-only-scope` | 1332 | 294 | 25 |
| `sentinel-propagation-scope` | 1356 | 160 | 55 |
| `signed-cell-snapshots` | 1332 | 294 | 25 |
| `signed-column-function-scope` | 1348 | 223 | 19 |
| `signed-column-search-scope` | 1348 | 223 | 19 |
| `snapshots-propagation-scope` | 1356 | 146 | 29 |
| `source-cell-column-row` | 1364 | 315 | 17 |
| `source-cell-lifetimes` | 1372 | 272 | 97 |
| `source-cell-row-column` | 1364 | 315 | 17 |
| `special-cell-operation-boundary` | 1348 | 166 | 127 |
| `texture-destination-scopes` | 1356 | 7 | 7 |
| `texture-left-snapshot` | 1356 | 7 | 7 |
| `texture-span-lifetime` | 1356 | 7 | 7 |
| `unsigned-orientation-contract` | 1332 | 292 | 70 |
| `uv-addition-order` | 1348 | 223 | 19 |

Completed commands from `build/recovered-upstream`:

```text
python -B -S build/first-party-resume-now/yajima-init-worker5/frontier.py
python -B -S build/first-party-resume-now/yajima-init-worker5/structure.py
python -B -S build/first-party-resume-now/yajima-init-worker5/dispatch_lifetimes.py
python -B -S build/first-party-resume-now/yajima-init-worker5/sentinel_scope.py
python -B -S build/first-party-resume-now/yajima-init-worker5/typed_work.py
python -B -S build/first-party-resume-now/yajima-init-worker5/texture_scope.py
python -B -S build/first-party-resume-now/yajima-init-worker5/cell_boundary.py
python -B -S build/first-party-resume-now/yajima-init-worker5/final_lifetimes.py
python -B -S build/first-party-resume-now/yajima-init-worker5/proof.py texture-span-lifetime
python -B -S build/first-party-resume-now/yajima-init-worker5/contract_proof.py
python -B -S build/first-party-resume-now/yajima-init-worker5/final_source.py
python -B -S build/first-party-resume-now/yajima-init-worker5/proof.py ready
python -B -S build/first-party-resume-now/yajima-init-worker5/execute_proof.py
python -B -S build/first-party-resume-now/yajima-init-worker5/ready_contracts.py
python -B -S build/first-party-resume-now/yajima-init-worker5/proof.py baseline-guard
python -B -S tools/decomp_lint.py build/first-party-resume-now/yajima-init-worker5/proposal/y_smap.c --json build/first-party-resume-now/yajima-init-worker5/proposal/lint.json --summary
python -B -S tools/decomp_lint.py src/promoted/y_smap.c --json build/first-party-resume-now/yajima-init-worker5/proposal/baseline-lint.json --summary
```

## Retained C

The body requires the owning declarations and the documented contract changes.
It remains an archived floor behind the existing production fallback.

```c
typedef struct SmapTileWork {
    struct SmapTileWork *self;
    u8 kind;
    u8 orientation;
    u8 fields06[2];
    YVec2f position;
    YVec2f displacement;
    u8 variant;
    u8 fields19[3];
    f32 uRight;
    f32 vBottom;
    f32 uLeft;
    f32 vTop;
    YVec2f extent;
    f32 scale;
    u8 fields38[0x108];
    u8 column;
    u8 row;
    u8 layout;
    u8 flag143;
    u8 flag144;
    u8 fields145[7];
    u8 hasSpecialCell;
    u8 fields14d[3];
    YVec2f specialOffset;
    u8 specialColumn;
    u8 specialRow;
    u8 fields15a[6];
} SmapTileWork;
typedef char SmapTileWorkSize[sizeof(SmapTileWork) == 0x160 ? 1 : -1];

/* The 0x160-byte allocation includes the draw state and special-cell fields.
* The diagnostic's filename/line contract is supplied in the provider proposal. */
#pragma push
/* Preserve retail's redundant -1 kind guard and its load-before-span sequence. */
#pragma opt_propagation off
s32 func_002afbc0(u8 *arg0);
u8 *func_002b0250(u8 *parent, u8 drawColumn, u8 drawRow, u8 kind, u8 piece, u8 variant, u8 mapColumn, u8 mapRow) {
    f32 center[2];
    u8 *task;
    SmapTileWork *work;
    s32 kindValue;
    s16 scanRow;
    s16 scanColumn;
    u8 *map;
    func_002b2bd0(center, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    kindValue = kind & 0xFF;
    /* Retail compares the zero-extended byte with -1, so 255 still allocates. */
    if (kindValue == -1) {
        return NULL;
    }
    func_0044ea90(D_0063EF60, 0x5C4);
    work = (SmapTileWork *)D_008873F4[0](1, 0x160, 0x40000);
    task = (u8 *)func_00451fc0(parent, D_0063EFD8, 0xF, 0, 0, func_002afbc0, func_002b0220, (u8 *)work);
    work->self = work;
    work->kind = kind;
    work->orientation = piece;
    work->variant = variant;
    work->scale = 1.0f;
    work->column = drawColumn;
    work->row = drawRow;
    work->layout = 0;
    work->flag143 = 0;
    work->flag144 = 0;
    work->displacement.y = 0.0f;
    work->displacement.x = 0.0f;
    if (kindValue >= 9) {
        switch (kindValue) {
            case 9:
            case 10: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1) {
                    work->vTop = 0.03125f;
                    work->uLeft = 0.03125f;
                    work->vBottom = 0.59375f;
                    work->uRight = 0.59375f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.015625f;
                    {
                        f32 left = work->uLeft;
                        f32 span = 0.578125f;
                        work->uRight = span + left;
                        work->vBottom = span + work->vTop;
                    }
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
            case 11:
            case 12: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1) {
                    work->vTop = 0.015625f;
                    work->uLeft = 0.015625f;
                    work->uRight = 0.296875f;
                    work->vBottom = 0.859375f;
                    work->extent.x = 19.0f;
                    work->extent.y = 55.0f;
                    work->layout = 1;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.015625f;
                    {
                        f32 left = work->uLeft;
                        f32 span = 0.578125f;
                        work->uRight = span + left;
                        work->vBottom = span + work->vTop;
                    }
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
            case 13:
            case 14: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1 || orientation == 3) {
                    work->vTop = 0.03125f;
                    work->uLeft = 0.03125f;
                    work->vBottom = 0.59375f;
                    work->uRight = 0.59375f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.296875f;
                    work->uRight = 0.859375f;
                    work->vBottom = 0.859375f;
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
        }
    } else {
        if (kindValue >= 7) {
            work->uLeft = 0.015625f;
            work->vTop = 0.015625f;
            work->vBottom = 0.578125f;
            work->uRight = 0.578125f;
            work->extent.y = 37.0f;
            work->extent.x = 37.0f;

        } else {
            if (kindValue == 2) {
                if ((piece & 0xFF) == 1) {
                    work->uLeft = 0.015625f;
                    work->vTop = 0.015625f;
                    work->uRight = 0.578125f;
                    work->vBottom = 0.578125f;
                    work->extent.x = 37.0f;
                    work->extent.y = 37.0f;
                    if (variant == 2 || variant == 1) {
                        work->layout = 2;
                    }
                } else if ((piece & 0xFF) == 2) {
                    work->vTop = 0.296875f;
                    work->uLeft = 0.296875f;
                    work->vBottom = 0.578125f;
                    work->uRight = 0.578125f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                }
            } else {
                work->uLeft = 0.03125f;
                work->vTop = 0.03125f;
                work->vBottom = 0.59375f;
                work->uRight = 0.59375f;
                work->extent.y = 19.0f;
                work->extent.x = 19.0f;
            }

        }

    }
    /* Each getter is reissued at its original boundary. The 2x2 scan uses
    * the source map cell, not the possibly shifted draw coordinates. */
    work->hasSpecialCell = 0;
    if ((piece & 0xFF) == 2) {
        s32 sourceColumn = mapColumn;
        if (sourceColumn == *(u8 *)((u8 *)func_00155280() + 0x46)) {
            s32 sourceRow = mapRow;
            if (sourceRow == *(u8 *)((u8 *)func_00155280() + 0x47)) {
                for (scanRow = 0; scanRow < 2; scanRow++) {
                    s32 row = scanRow;
                    s32 rowOffset;
                    scanColumn = 0;
                    rowOffset = (sourceRow + row) * 256;
                    for (; scanColumn < 2; scanColumn++) {
                        s32 column = scanColumn;
                        map = (u8 *)func_00155280();
                        if ((s8)(*(u8 *)(rowOffset + (u32)map + (sourceColumn + column) * 0x10 + 0x55) >> 4) == 2) {
                            work->specialOffset.x = 9.0f;
                            work->specialOffset.y = 9.0f;
                            work->specialColumn = (u8)scanColumn;
                            work->specialRow = (u8)scanRow;
                            work->hasSpecialCell = 1;
                            return task;
                        }
                    }
                }
            }
        }
    }
    return task;
}

#pragma pop
```


## Durable support and historical pending API obligations

The companion C includes the repository's `include/type.h` and
`include/sdk_task_registration.h`, then supplies the owner's `YVec2f` pair,
global declarations and called-function declarations. It contains the complete
`SmapTileWork` layout and size assertion, all initializer branches, and the
original scoped compiler option. The retained body is byte-for-byte identical
to `ready/body.c`; the original report above is byte-for-byte identical to the
reviewed `archive-proposal.md`. No source, configuration, provider or prior
archive is changed by this preservation.

The historical contract changes are prerequisites for any future integration,
not claims that the live API has already been reconciled:

| Interface | Historical live declaration | Retained/proposed contract and obligation |
| --- | --- | --- |
| `func_002b2bd0` | The y_smap declaration used `s32` for mode. | The actual provider takes `s64`; retain `void(f32 *, s64, f32, f32, f32, f32)`. The output array has two floats, matching the eight bytes written. |
| `func_00155280` | The y_smap declaration returned `u8 *`. | The provider returns `s32 *`; the selected owner explicitly converts each byte view before byte-offset arithmetic. Do not let the return-type correction change indexing units. |
| `func_002b0250` | The caller and old definition used `s8` for the fifth parameter (orientation). | The retained definition uses `u8` and the actual caller passes 1, 2 or 3. Its ten calls and whole-object neutrality are recorded in `contracts/caller-ready/proof.json`; this is a caller comparison, not a retail MATCH claim for that caller. |
| `func_0044ea90` | The provider was `void func_0044ea90(void) {}` while allocation sites supplied file and line. | The separately measured proposal accepts `void *file, s32 line`. It preserves the provider object, but global provider/caller reconciliation remains pending. No incompatible invocation is licensed by the floor score. |
| Allocation and destruction | The runtime memory slots are indirect. | Retain the RenderWare `rwcalloc` contract `void *(size_t, size_t, u32)` and one-pointer `rwfree`. No concrete runtime binding is inferred from the initial zero allocator slot. |
| Task registration | The existing task header defines pointer-returning registration and typed callbacks. | Retain `void *func_00451fc0(void *, const void *, s32, s32, s32, SdkTaskUpdate, SdkTaskDestroy, u8 *)`, `SdkTaskUpdate = s32 (*)(u8 *)`, and `SdkTaskDestroy = void (*)(u8 *)`. |

The exact historical diagnostic proposal, still unapplied by this archive, is:

```c
void func_0044ea90(void *file, s32 line) {}
```

The pending caller declaration is:

```c
extern u8 *func_002b0250(u8 *, u8, u8, u8, u8, u8, u8, u8);
```

These declarations preserve the reviewed proposal's scope. They do not stand
in for a current-revision owner, provider, caller or whole-image gate after a
rebase. The selected complete-owner and body hashes above remain the measured
identities. No new compiler invocation was made for durable preservation.

### Map-neighborhood precondition retained

When orientation is 2 and both stored source coordinates match, each visited
byte has the offset
`(mapRow + scanRow) * 0x100 + (mapColumn + scanColumn) * 0x10 + 0x55`.
That byte must be inside the actual map backing object; the known extent in
this evidence is `0x18f8` bytes. A hit can end the search before the full 2x2
neighborhood is visited. The six shared synthetic edge failures in the report
are preserved, and no proof that real map data excludes them is added here.
The exact 24-byte switch table and bounded 0x160-byte work layout are separate
from this unresolved map-placement invariant.

### Preservation identities and release

All 332 retained artifact hashes were checked before copying. The historical
scratch report, scripts, failed or partial attempts, receipts, and original
release note are preserved. Only this Markdown archive and its C companion
were added for the preservation request. Compiler ownership remains released.
Tracked writes are frozen after preservation verification; `y_draw` target
`002b77d0` is reserved for the later post-rebase notice, with no new baseline.

| Preserved item | SHA-256 |
| --- | --- |
| Reviewed scratch report | `e72ddb46eaa23fc0a53d05de651426b4e44667e83942857e95c5672c457ffb41` |
| Companion C, support declarations plus unchanged body | `e28dcb1b0199856f5dd53c58b080a33f2943cf1ab16f2b06cb3e11c0e8962eeb` |
| Unchanged measured body | `c36eb71039db867f6e230eded1b9149457067ca5513dacf5c911d888ecb22f5b` |
| Historical final manifest | `c54f918ba98bf1b0a05314732fdf369c7bb21371144b5cea74a8af65c059eb5a` |
| Historical release note | `b2d018d08cdd2fe0537c44b5a5983e6e69985bd19f1356c7d259b851022c0363` |
| Measured owner proof | `abdbeaec46247c5bc53c97063b8001e5eb3257ddeb075eb02d3ff793ca064b2a` |
| Historical caller proof | `6133dbfaad4a0507a34989fceb42d6aa5fd2da989afa477ca57ce91d109fb33e` |
| Historical diagnostic provider proof | `2fbf29848f9f8ed68f1e079bfb39ad0de5d25af62d31063b26e864a8df10e436` |
| Bounded execution proof | `6bf47b95dc7d102e2ed39d8cf87d8ce8c3928f7e02242174251e08553e503167` |
| Project type header used for interpretation | `d98ec5482a2782c2a9ca41f93d590ab2007b9817936d5208746d6e8794906db3` |
| Project task header used for interpretation | `7dbebce4a3eeb57f807e5f06a5cc1d6b16b89b644e4105bd2685000dd22075d1` |
