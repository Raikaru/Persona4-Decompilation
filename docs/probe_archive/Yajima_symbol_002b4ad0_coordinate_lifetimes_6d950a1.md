# Yajima symbol coordinate and resource lifetimes: 002b4ad0

Measured September 20, 2026 from `6d950a12d36f08706cd42225d5513e5a50d25748`. Final inspected HEAD:
`6d950a12d36f08706cd42225d5513e5a50d25748`. This is a **typed ordinary-C floor, not a MATCH or a
production promotion**. The current `src/Yajima/y_symbol.c` remains unchanged.
The accepted y_list archive and its two targets were not re-probed.

The complete resolved comparison improves **157 to 27
differing words**. The candidate emits **1,236 executable bytes in the 1,248-byte
retail window**, followed by twelve verified retail alignment zeros. The old
guarded body emitted 1,244 bytes. The retained source preserves the retail
0x80 frame and saved-register inventory.

## Selection and reconstruction

The current Yajima/Fcl frontier already marks the shop task initializer and
cleanup functions MATCH. The symbol placement callback was selected from
`build/first-party-resume-continue/alignment-ranking/func_002b4ad0.json` after
reading the live owner, previous archive, IDA/Ghidra descriptions, complete
retail assembly and actual callee providers. All writes belong to
`build/first-party-resume-now/yajima-next-worker5` and this new archive. The
datCalc and FclCombine owners are excluded.

Mode zero projects the symbol using map record coordinates; mode one uses the
stored position. Both modes retain the same visibility, color, resource and
draw calls. The 0xC work record is proved by `func_002b4fe0`'s allocation and
field initialization. The map record's 0x168 stride and position at 0x150 are
confirmed by both retail indexing and the y_smap consumers. Unknown record
bytes describe existing storage; no extra allocation or instruction padding
is introduced.

The projected and draw positions have actual floating components plus an
eight-byte snapshot view. The final source uses a union for that copy instead
of dereferencing floating pointers into integer locals. The origin is a
declared float pair with a component-copy address scope, replacing the old
byte buffer. A 24-word intermediate still used the byte-buffer alias and is
not the selected source. The fully typed 27-word result is retained.

## Contract closure

The function remains `s32 func_002b4ad0(u8 *)`, as required by its existing task
registration callback. Its complete scratch owner corrects stale shared
declarations to the current providers below. `ready/contracts.json` hashes
each provider region and confirms it is unchanged from the frozen evidence.
The map-coordinate providers receive `RwV3d` by value: the configured EE ABI
passes its address in the integer argument bank, and the corrected callers
retain the retail instruction shape. Both integer and floating argument banks
are checked through the real provider declarations.

| Address | Provider contract | Definition |
| --- | --- | --- |
| `002b2bd0` | `void(f32 *, s64, f32, f32, f32, f32)` | `src/promoted/code1_002b.c`: `func_002b2bd0` |
| `002b2960` | `s32(void)` | `src/promoted/code1_002b.c`: `func_002b2960` |
| `00106330` | `u32(s32)` | `src/g_data/g_data.c`: `datGetFlag` |
| `002ac3c0` | `s64(s32, s32)` | `src/promoted/code1_002a.c`: `func_002ac3c0` |
| `0047a2f0` | `void *(void *)` | `src/mdlManager_grouped.c`: `mdlGetMatrix` |
| `002b11c0` | `s32(RwV3d)` | `src/promoted/y_smap.c`: `func_002B11C0` |
| `002b1210` | `s32(RwV3d)` | `src/promoted/y_smap.c`: `func_002B1210` |
| `002b13e0` | `f32(YVec3f *, f32)` | `src/promoted/y_smap.c`: `func_002b13e0` |
| `002b1480` | `f32(YVec3f *, f32)` | `src/promoted/y_smap.c`: `func_002b1480` |
| `002b1260` | `f32(u8 *, f32)` | `src/promoted/y_smap.c`: `func_002b1260` |
| `002b1320` | `f32(u8 *, f32)` | `src/promoted/y_smap.c`: `func_002b1320` |
| `002b2a30` | `s32(u8, u8, u8, u8)` | `src/promoted/code1_002b.c`: `func_002b2a30` |
| `002ac740` | `s32(void)` | `src/promoted/y_smap.c`: `func_002ac740` |
| `0025ecd0` | `s32(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *)` | `src/promoted/code1_0025.c`: `func_0025ecd0` |

The visibility provider accepts two full-width integers, masks their low
bytes internally and returns `s64`. The explicit `(s8)` interpretation at each
visibility test is retained. The origin provider takes a signed 64-bit mode.
The flag getter returns `u32`; the model matrix accessor returns a pointer.
The offset helpers take their actual vector/resource pointers and return
floating results. No incompatible prototype is used to force instruction
selection.

Changing the visibility declaration initially changed four argument words in
matched sibling `002b4250`. Its four query snapshots now keep an explicitly
normalized byte value in `s32` storage for the visibility call. The later
coordinate differences explicitly take their own unsigned-byte views with
`& 0xFF`. This preserves both the actual callee contract and all of the
sibling's original instructions. Raw unnormalized snapshots and early-only
normalization were measured and rejected because their sibling bytes changed.

## Complete proof and residual

`ready/proof.json` independently applies all **38 code relocations**, covering
all fourteen called providers and every referenced global. There are no
unresolved relocations. The target owns no jump tables or other allocated
data; the complete owner contains no allocated non-code sections. All
**14 sibling functions** retain identical bytes and canonical relocation
records. No fallback row is counted as decompiled progress.

The baseline has 149 masked words and 28 aligned edits; its full unmasked
comparison has 157 differing words. The selected candidate has 27 masked
and resolved words and 19 aligned edits. Three residual words concern the
origin copy's load/store ordering. The other twenty-four occur in the two
record-offset argument sequences: retail materializes the floating spacing
before calculating the record address, while the candidate materializes it
afterward. The remaining instructions, call targets, frame, source accesses,
draw packet and return structure agree.

Remaining instruction offsets:

`0x048`, `0x04c`, `0x050`, `0x1ac`, `0x1b0`, `0x1b4`, `0x1b8`, `0x1bc`, `0x1c0`, `0x1c4`, `0x1c8`, `0x1cc`, `0x1d0`, `0x1d4`, `0x1d8`, `0x23c`, `0x240`, `0x244`, `0x248`, `0x24c`, `0x250`, `0x254`, `0x258`, `0x25c`, `0x260`, `0x264`, `0x268`

The guarded review copy `proposal/y_symbol.c` passes `decomp_lint` with zero
errors and zero warnings. The executable measurement copy intentionally
selects the C body and initially triggered M002/M005 because its inherited
NONMATCHING marker had no fallback guard. The proposal restores that original
guard and fallback for structural lint; this is not a match-status waiver.
No game execution or whole-image build is claimed.

## Retained evidence

| Artifact | SHA-256 |
| --- | --- |
| Unchanged live owner | `efd08479c1d6a441218f97e28e72b2fa46b0219dfd11e7e226a709b012ccbc3c` |
| Selected complete compiled owner | `93ec04fb67dc037f3b91cad09fee838e7bbbf26645391f49c71a404640cab4ce` |
| Selected body below | `26eeef481edf8152d72820468f5f0abacd98adc0800c03d5ff373c0918e7a93e` |
| Selected object | `63256959364cebdf1b8dbd28e0e62b722da43bc6563f54c742b413f8e5d01354` |
| Independent proof | `1c1543601286afb9eeb0dd2211cd6d725959899c8d6d5effa3e2fa7fd0c346f9` |
| Configured b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Retail ELF | `f90675b8a38138ddb5dc5cdf641550f41800fcb86bb499c586073e964fb41836` |

Compiler and flags are selected by the real owning path through
`probe_variants._compile_in_context`: MWCCPS2 3.0.1 b210, `-O2 -Iinclude`.
Only the source input is redirected to the isolated complete owner. Every
compile completed under the standard owner lock; compiler ownership is
released. `final-manifest.json` validates all source/object receipts and
retained artifact hashes. The live owner, configurations and accepted
archives are preserved. This worker made no Git mutations or publication.

## Measurements

Each row is a completed full-owner compilation. The production row uses its
existing fallback as a control. Word counts here are the masked comparison;
complete resolved baseline and selected proof results are given above.

| Trial | Emitted bytes | Masked words | Aligned edits |
| --- | ---: | ---: | ---: |
| `actual-gate-and-output-contracts` | 1244 | 153 | 36 |
| `aligned-origin-storage` | 1252 | 278 | 71 |
| `all-coordinate-storage` | 1212 | 273 | 58 |
| `baseline-guard` | 1244 | 149 | 28 |
| `baseline-production` | 1248 | 0 | 3 |
| `both-output-views` | 1236 | 24 | 16 |
| `canonical-provider-contracts` | 1236 | 24 | 16 |
| `coordinate-accumulator` | 1220 | 271 | 191 |
| `coordinate-pair` | 1220 | 271 | 191 |
| `float-record-accessor-boundaries` | 1236 | 27 | 19 |
| `map-record-position-view` | 1236 | 27 | 19 |
| `origin-address-scope` | 1236 | 27 | 19 |
| `origin-copy-operation` | 1212 | 273 | 58 |
| `origin-copy-propagation-scope` | 1204 | 269 | 83 |
| `origin-copy-record-pointers` | 1236 | 27 | 19 |
| `origin-copy-same-type` | 1236 | 27 | 19 |
| `origin-copy-shared-vec2` | 1236 | 27 | 19 |
| `origin-float-array` | 1220 | 271 | 65 |
| `origin-record-array` | 1236 | 27 | 19 |
| `origin-union-fields` | 1212 | 273 | 58 |
| `output-coordinate-union` | 1236 | 24 | 16 |
| `owner-byte-snapshot-contracts` | 1236 | 27 | 19 |
| `owner-coordinate-view-contracts` | 1236 | 27 | 19 |
| `owner-raw-query-lifetimes` | 1236 | 27 | 19 |
| `projected-offset-result-lifetimes` | 1236 | 27 | 19 |
| `ready` | 1236 | 27 | 19 |
| `record-offset-call-boundaries` | 1236 | 24 | 16 |
| `record-offset-staged-arguments` | 1236 | 24 | 12 |
| `symbol-work-and-map-layout` | 1236 | 27 | 19 |
| `typed-origin-copy` | 1236 | 27 | 19 |
| `typed-origin-output-array` | 1236 | 27 | 19 |
| `typed-origin-snapshot` | 1244 | 250 | 21 |
| `typed-record-accessor-boundary` | 1248 | 273 | 69 |
| `visibility-coordinate-snapshots` | 1244 | 149 | 28 |

Completed commands, with the recovered upstream project as working directory:

```text
python -B -S build/first-party-resume-now/yajima-next-worker5/first_probe.py
python -B -S build/first-party-resume-now/yajima-next-worker5/coordinate_storage.py
python -B -S build/first-party-resume-now/yajima-next-worker5/record_boundary.py
python -B -S build/first-party-resume-now/yajima-next-worker5/origin_scope.py
python -B -S build/first-party-resume-now/yajima-next-worker5/canonical_contracts.py
python -B -S build/first-party-resume-now/yajima-next-worker5/typed_origins.py
python -B -S build/first-party-resume-now/yajima-next-worker5/pair_identity.py
python -B -S build/first-party-resume-now/yajima-next-worker5/sibling_contracts.py
python -B -S build/first-party-resume-now/yajima-next-worker5/map_record_view.py
python -B -S build/first-party-resume-now/yajima-next-worker5/sibling_raw_snapshots.py
python -B -S build/first-party-resume-now/yajima-next-worker5/sibling_coordinate_views.py
python -B -S build/first-party-resume-now/yajima-next-worker5/final_boundaries.py
python -B -S build/first-party-resume-now/yajima-next-worker5/final_source.py
python -B -S build/first-party-resume-now/yajima-next-worker5/proof.py baseline-guard
python -B -S build/first-party-resume-now/yajima-next-worker5/proof.py ready
python -B -S build/first-party-resume-now/yajima-next-worker5/package_source.py
python -B -S tools/decomp_lint.py --json build/first-party-resume-now/yajima-next-worker5/proposal/lint.json build/first-party-resume-now/yajima-next-worker5/proposal/y_symbol.c
```

Initial agent delivery returned AGENTS_BUSY under Unattributed identity; later
messages to prime succeeded. A command containing an app virtual path was
rejected before execution. Additional command calls were blocked before
execution by the tool safety-status check; valid retries completed.
No successful patch or compiler command was replayed to recover a terminal.

## Retained C body

The body uses the owner's existing Vec2 type, the provider-compatible tagged
RwV3d/YVec3f declarations, and the corrected declarations described above.
The production fallback remains selected until the remaining instructions
and the prime's promotion gates pass.

```c
/* Map records have a 0x168 stride and a position at offset 0x150. */
typedef struct SymbolMapRecord {
    u8 fields00[0x150];
    YVec3f position;
    u8 fields15c[0xC];
} SymbolMapRecord;
typedef char SymbolMapRecordSize[sizeof(SymbolMapRecord) == 0x168 ? 1 : -1];

/* The task constructor allocates 0xC bytes and initializes these fields. */
typedef struct SymbolWork {
    Vec2 position;
    s8 mode;
    u8 column;
    u8 row;
    u8 record;
} SymbolWork;
typedef char SymbolWorkSize[sizeof(SymbolWork) == 0xC ? 1 : -1];

/* Place the symbol at its projected map position in mode zero, or at
 * the stored position in mode one. Keep the two coordinate snapshots
 * across the color and resource calls. The component copy has its own
 * address scope, matching the origin's observed memory lifetime. */
s32 func_002b4ad0(u8 *task)
{
    SymbolWork *work;
    Vec2 origin;
    /* Float components and their complete eight-byte draw snapshot. */
    union { f32 values[2]; u64 bits; } projected;
    Vec2 center;
    union { f32 values[2]; u64 bits; } drawPosition;
    f32 component;
    s32 columnDelta;
    s32 rowDelta;
    s32 column;
    s32 row;
    s8 mode;
    s32 visible;
    Vec2 storedPosition;

    work = *(SymbolWork **)(task + 0x38);
    func_002b2bd0((f32 *)&center, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    {
        Vec2 *copy = &origin;
        copy->x = center.x;
        copy->y = center.y;
    }
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s32 *)(D_007E80A8 + work->record * 0x168) == 1) {
        return 0;
    }
    mode = work->mode;
    if (mode == 0) {
        row = work->row;
        column = work->column;
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(column, row) == 1) {
                visible = 1;
                goto projectedVisibilityDone;
            }
        } else {
            visible = 1;
            goto projectedVisibilityDone;
        }
        visible = 0;
projectedVisibilityDone:
        if (visible == 1) {
            columnDelta = (s8)(work->column - func_002b11c0(*(RwV3d *)((u8 *)func_0047a2f0((void *)D_007EFA00[0]) + 0x30)));
            rowDelta = (s8)(work->row - func_002b1210(*(RwV3d *)((u8 *)func_0047a2f0((void *)D_007EFA00[0]) + 0x30)));
            origin.x += 17.0f;
            origin.y += 264.0f;
            component = origin.x + 18.0f * (f32)columnDelta -
                   func_002b13e0(&((SymbolMapRecord *)D_007E80A0)[work->record].position, 18.0f);
            component += func_002b1260(*(u8 **)(*(u8 **)D_007EFA04 + 0x220), 18.0f);
            component -= 13.0f;
            projected.values[0] = component;
            component = origin.y + 18.0f * (f32)rowDelta -
                   func_002b1480(&((SymbolMapRecord *)D_007E80A0)[work->record].position, 18.0f);
            component += func_002b1320(*(u8 **)(*(u8 **)D_007EFA04 + 0x220), 18.0f);
            component -= 13.0f;
            projected.values[1] = component;
            if (!(projected.values[0] < 1.0f) &&
                (projected.values[0] <= 164.0f) &&
                !(projected.values[1] < 248.0f) &&
                (projected.values[1] <= (f32)0x19B)) {
                drawPosition.bits = projected.bits;
                func_0025ecd0(
                    drawPosition.values[0], drawPosition.values[1], (f32)0xEA65,
                    func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                    (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                    D_00794DB0);
            }
        }
    } else if (mode == 1) {
        row = work->row;
        column = work->column;
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(column, row) == 1) {
                visible = 1;
                goto storedVisibilityDone;
            }
        } else {
            visible = 1;
            goto storedVisibilityDone;
        }
        visible = 0;
storedVisibilityDone:
        if (visible == 1) {
            storedPosition = work->position;
            func_0025ecd0(
                storedPosition.x, storedPosition.y, (f32)0xEA65,
                func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                D_00794CF0);
        }
    }
    return 0;
}
```
