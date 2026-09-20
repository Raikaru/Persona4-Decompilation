# YList range-builder bound and counter lifetimes

The replacement worker did not improve the existing `002e6280` floor. A fresh
configured-owner proof reproduces 936 executable bytes in its 944-byte retail
window, 14 fully resolved differing instruction words, and 16 aligned edits.
Both 11-entry switch tables are exact. The new lifetime, metadata-record,
row-selector, append-operation and level-limit helper trials tie or regress.

The related `002e5ae0` range builder has a strict source improvement: **416 to
51 fully resolved differing words**, with emitted code reduced from 1,884 to
the retail executable length of **1,860 bytes**. Its retail window is 1,872
bytes; the following 12 bytes are verified retail alignment zeros. All four
44-byte switch tables now resolve exactly. This is an archived C floor, not a
MATCH or production promotion. The existing live C and ASM choices are intact.

## Owner and evidence

The current owner is `src/Yajima/y_list.c`, at HEAD `6d950a12d36f08706cd42225d5513e5a50d25748`. The assigned
historical promoted path and `worker3-ylist` scratch directory were absent.
The earlier `002e6280` artifacts were recovered from
`build/first-party-resume-now/ylist/persona-list-work-layout` and
`build/first-party-resume-final/worker4-ylist`. The previous published floor is
documented in `YList_002e6280_records_000fca0.md`.

All work in this run is confined to
`build/first-party-resume-now/ylist-replacement` and this new archive. The
retained source, object and independent proof are in
`build/first-party-resume-now/ylist-replacement/range-list/distinct-range-search-counters`.
The full inventory is `build/first-party-resume-now/ylist-replacement/final-manifest.json`.

| Evidence | SHA-256 |
| --- | --- |
| Unchanged live owner | `844b6481d71a8696195b0534cb033648fe86dacc578ec25c4600c85f232a84a8` |
| Retained complete scratch owner | `550c0e91469604e4ec91dc5ac4c53bc10345dc28bb45e6b6de4a2f12dd482c5e` |
| Retained body below | `bada873b4212a1ca3a599d9e8a74019e60cb1299fe10f9115b73dde1b742abce` |
| Retained object | `ae264b07dfc60c939da7d9309a02c713f3ea64f8e8bf91c16e079102e2615830` |
| Configured b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Retail ELF | `f90675b8a38138ddb5dc5cdf641550f41800fcb86bb499c586073e964fb41836` |

Compilation uses the owner's configured MWCCPS2 3.0.1 b210 compiler with
`-O2 -Iinclude`. `probe_variants._compile_in_context` selects the flags using
the real owner path, redirects only the input to the scratch owner and holds
the standard owner lock through each compiler invocation. Every invocation
completed and released that lock. Receipts hash the owner, recursive includes,
ASM siblings, relevant compiler configuration, tools, real callee providers,
compiler binary, and retail bytes. No configuration is edited.

## Real lifetimes and contracts

The list is first scanned at a narrow level range and then, when empty, scanned
again at progressively wider ranges. Each clamp result is truncated to a
signed halfword at the arithmetic boundary. Its ordinary integer promotion
then lives throughout its corresponding scan. Separate `s32` comparison
snapshots recover the retail `sq`/`lq` spills without a fabricated 128-bit type,
volatile storage, or padding. The initial upper bound is captured directly;
the initial lower bound and both expanded bounds are captured at their scan
boundaries.

Each metadata record has a signed index and a stride-14 byte offset. The
offset survives predicate calls; the metadata global is deliberately loaded
again before checking the record's level. Each existing-list search defines
its result at its successful or exhausted exit. Distinct counters represent
the searches belonging to the initial and expanded scans.

Actual callers in `src/Event/Fcl/y_fclCombine.c` declare
`void func_002e5ae0(s32, void *, s64)`. The retained old-style definition has
that explicit prototype, the selector's default-promoted `s8` parameter,
`void *` exclusions and the actual `s64` level. The level is interpreted as
`s8` once after reset and retained as `s32` across both scans. This preserves
the callers' real ABI and the retail byte interpretation. No caller is edited.

The scratch owner also corrects the four stale declarations used by the
builder to their actual provider contracts:

```c
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s64 func_00311d00(s32);
extern s32 func_00311d60(s32);
extern s32 func_00311e40(s32);
```

`func_002b2d00(s32, s32, s32, s32, s8) -> s32` is confirmed in
`src/promoted/code1_002b.c`, and its existing declaration already agrees.
Both clamp results still receive their observed `(s16)` conversion.
`func_0010cad0(u8 *, u16)` is confirmed in
`src/Main/Battle/Data/datPersona.c`; the clear and initialize operations each
reload the active list and the original count as in retail. The existing
`func_002e48a0(s8, s16)` accessor and `func_002e6230(u16, u16 *)` exclusion
search are called with their real contracts. No ordinary ASM, undefined
arithmetic, incompatible return width, or synthetic instruction padding is
introduced.

## Complete comparison

The independent resolver applies all **35 code
relocations**, including direct calls, paired HI16/LO16 relocations and GP
relative metadata loads. There are no unresolved code relocations. It also
resolves every entry in the four switch tables, compares their complete bytes
against the retail ELF, and checks their four-byte zero alignment tails.

| Table role | Retail address | Bytes | R_MIPS_32 entries | Result |
| --- | --- | ---: | ---: | --- |
| initial clear | `0x00748e30` | 44 | 11 | exact |
| initial initialize | `0x00748e00` | 44 | 11 | exact |
| expanded clear | `0x00748dd0` | 44 | 11 | exact |
| expanded initialize | `0x00748da0` | 44 | 11 | exact |

The complete-owner comparison confirms all **36 siblings** and **18 other
allocated data sections** retain the same bytes, canonical relocation targets,
sizes and alignment. This includes the matched SDK-based `002e4090`; its
implementation and include path are untouched.

The resolved instruction score is 51. Remaining differences are the saved
register assignments for the slot/temporary values and expanded scan index,
plus comparison temporaries. The instruction count and table destinations
are exact; the instructions themselves still differ. Residual byte offsets
from the function start are:

`0x034`, `0x04c`, `0x050`, `0x068`, `0x08c`, `0x090`, `0x0c0`, `0x104`, `0x108`, `0x11c`, `0x130`, `0x148`, `0x19c`, `0x1c0`, `0x1f4`, `0x1f8`, `0x204`, `0x2b0`, `0x348`, `0x3b8`, `0x3bc`, `0x3c0`, `0x3c4`, `0x3ec`, `0x408`, `0x40c`, `0x41c`, `0x420`, `0x444`, `0x448`, `0x474`, `0x478`, `0x48c`, `0x4a0`, `0x4b8`, `0x4e4`, `0x50c`, `0x530`, `0x568`, `0x56c`, `0x578`, `0x624`, `0x6bc`, `0x6d4`, `0x6d8`, `0x6dc`, `0x6e0`, `0x6e4`, `0x6e8`, `0x704`, `0x708`

The corrected baseline emits 1,884 bytes, has 395 relocation-masked overlap
differences, 416 fully resolved differences over the complete comparison, and
155 aligned edits. Its four tables differ. The retained floor emits 1,860
bytes with 51 masked/resolved differences and 55 aligned edits. The archived
raw counts are kept separate from the complete resolved comparison.

## Completed measurements

Each row is a fresh serial complete-owner compile. The ASM production rows
are controls, not C matching claims. The table's word counts are the initial
relocation-masked overlap metric; the retained and baseline complete resolved
proofs are recorded above.

| Target | Trial | Emitted bytes | Masked words | Aligned edits |
| --- | --- | ---: | ---: | ---: |
| 002e6280 | `baseline-production` | 944 | 0 | 2 |
| 002e6280 | `baseline-typed` | 936 | 14 | 16 |
| 002e6280 | `exclusion-counter-scope` | 936 | 14 | 16 |
| 002e6280 | `existing-counter-scope` | 936 | 20 | 22 |
| 002e6280 | `inline-level-boundary` | 936 | 14 | 16 |
| 002e6280 | `inline-persona-append` | 936 | 14 | 16 |
| 002e6280 | `inline-row-selector` | 936 | 14 | 16 |
| 002e6280 | `metadata-record-view` | 936 | 14 | 16 |
| 002e6280 | `search-and-record-scopes` | 936 | 20 | 22 |
| 002e6280 | `search-counter-scopes` | 936 | 20 | 22 |
| 002e5ae0 | `baseline-contracts` | 1884 | 395 | 155 |
| 002e5ae0 | `baseline-guard` | 1884 | 395 | 155 |
| 002e5ae0 | `baseline-production` | 1872 | 0 | 3 |
| 002e5ae0 | `bound-and-record-snapshots` | 1876 | 408 | 117 |
| 002e5ae0 | `caller-level-lifetime` | 1860 | 77 | 81 |
| 002e5ae0 | `distinct-range-search-counters` | 1860 | 51 | 55 |
| 002e5ae0 | `expanded-count-completion` | 1860 | 51 | 55 |
| 002e5ae0 | `expanded-counter-scope` | 1860 | 51 | 55 |
| 002e5ae0 | `expansion-bound-scopes` | 1860 | 51 | 55 |
| 002e5ae0 | `inclusive-level-ranges` | 1860 | 51 | 55 |
| 002e5ae0 | `promoted-bound-snapshots` | 1876 | 411 | 120 |
| 002e5ae0 | `range-expansion-snapshot` | 1860 | 77 | 81 |
| 002e5ae0 | `search-result-exits` | 1860 | 155 | 119 |
| 002e5ae0 | `separate-scan-counter-scopes` | 1860 | 62 | 66 |

Completed commands, from `build/recovered-upstream`:

```text
python -B build/first-party-resume-now/ylist-replacement/counter_scopes.py
python -B -S build/first-party-resume-now/ylist-replacement/row_boundary.py
python -B -S build/first-party-resume-now/ylist-replacement/proof.py baseline-typed
python -B -S build/first-party-resume-now/ylist-replacement/range_bounds.py
python -B -S build/first-party-resume-now/ylist-replacement/range_level.py
python -B -S build/first-party-resume-now/ylist-replacement/boundary_finish.py
python -B -S build/first-party-resume-now/ylist-replacement/range_proof.py distinct-range-search-counters
python -B -S build/first-party-resume-now/ylist-replacement/range_proof.py baseline-contracts
```

The first Python invocation printed the environment's existing missing
`pywin32_bootstrap` startup warning and completed with exit code 0. Subsequent
commands use `-S` to omit that unrelated site startup. Two tool calls were
blocked before execution because their safety status could not be determined;
their exact retries succeeded. No successful command was replayed to recover
a terminal.

## Retained C body

This body belongs under the existing guarded-C path until the remaining
differences are closed and the prime's owner/caller gates pass. The ordinary
ASM production fallback is not changed by this archive.

```c
extern s32 func_002e6230(u16 arg0, u16 *arg1);
extern void func_002e5ae0(s32, void *, s64);
void func_002e5ae0(arg0, arg1, arg2)
s8 arg0;
void *arg1;
s64 arg2;
{
    u8 **slotp;
    u8 *p;
    s16 lo;
    s32 level;
    s32 hi;
    s16 i;
    s16 initialRow;
    s16 expandedRow;
    s32 found;
    u16 id;
    u8 *q;
    s16 h;
    u32 sw1;
    u32 sw2;
    u8 *dst1;
    u8 *dst2;
    s16 lo2;
    s16 hi2;
    s16 outer;
    s32 lowLimit;
    s32 highLimit2;
    s32 lowLimit2;
    s16 inner;
    slotp = &D_00882F70[arg0];
    if (*slotp == NULL) {
        return;
    }
    p = *(u8 **)(*slotp + 0x38);
    func_002e5960(arg0);
    level = (s8)arg2;
    lo = (s16)func_002b2d00(level, 10, 1, 0x63, 1);
    hi = (s16)func_002b2cb0(level, 1, 0x63, 1, 1);
    i = 0;
    lowLimit = (s16)lo;
    for (; i < 0xC0; i++) {
        s32 signedIndex = i;
        s32 metadataOffset;
        u8 *metadata;
        u8 kind;
        metadata = iGpffffb3d4;
        metadataOffset = signedIndex * 14;
        metadata += metadataOffset;
        kind = metadata[2];
        if (kind < 2 || kind >= 0x16) {
            continue;
        }
        id = (u16)i;
        if (func_00311d00(id) == 0) {
            continue;
        }
        if (func_00311d60(id) == 0) {
            continue;
        }
        if (func_002e6230(id, arg1) != 0) {
            continue;
        }
        if (*slotp != NULL) {
            for (initialRow = 0; initialRow < *(s32 *)(*(u8 **)(*slotp + 0x38) + 8); initialRow++) {
                if (signedIndex == *(u16 *)(func_002e48a0(arg0, initialRow) + 2)) {
                    found = 1;
                    goto initialSearchDone;
                }
            }
        }
        found = 0;
initialSearchDone:
        if (found != 0) {
            continue;
        }
        if (func_00311e40(id) != 0) {
            continue;
        }
        metadata = iGpffffb3d4;
        metadata += metadataOffset;
        if (hi < metadata[3] || metadata[3] < lowLimit) {
            continue;
        }
        h = *(s16 *)(p + 8);
        q = *(u8 **)(*slotp + 0x38);
        sw1 = *(u32 *)(q + 4);
        switch (sw1) {
        case 0:
        case 2:
        case 7:
        case 8:
            dst1 = q + h * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            dst1 = q + h * 0x30 + 0xA4;
            break;
        default:
            dst1 = q + h * 0x30 + 0x14;
            break;
        }
        func_0043f9c8(dst1, 0, 0x30);
        h = *(s16 *)(p + 8);
        q = *(u8 **)(*slotp + 0x38);
        sw2 = *(u32 *)(q + 4);
        switch (sw2) {
        case 0:
        case 2:
        case 7:
        case 8:
            dst2 = q + h * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            dst2 = q + h * 0x30 + 0xA4;
            break;
        default:
            dst2 = q + h * 0x30 + 0x14;
            break;
        }
        func_0010cad0(dst2, id);
        *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    }
    if (level >= 0x3C && *(s32 *)(p + 8) < 3) {
        func_002e5960(arg0);
    }
    if (*(s32 *)(p + 8) != 0) {
        return;
    }
    outer = 0;
    do {
        s32 expansion = outer;
        lo2 = (s16)func_002b2d00(level, expansion * 5 + 10, 1, 0x63, 1);
        hi2 = (s16)func_002b2cb0(level, expansion + 1, 0x63, 1, 1);
        func_002e5960(arg0);
        inner = 0;
        highLimit2 = (s16)hi2;
        lowLimit2 = (s16)lo2;
        for (; inner < 0xC0; inner++) {
            s32 signedIndex = inner;
            s32 metadataOffset;
            u8 *metadata;
            u8 kind;
            metadata = iGpffffb3d4;
            metadataOffset = signedIndex * 14;
            metadata += metadataOffset;
            kind = metadata[2];
            if (kind < 2 || kind >= 0x16) {
                continue;
            }
            id = (u16)inner;
            if (func_00311d00(id) == 0) {
                continue;
            }
            if (func_00311d60(id) == 0) {
                continue;
            }
            if (func_002e6230(id, arg1) != 0) {
                continue;
            }
            if (*slotp != NULL) {
                for (expandedRow = 0; expandedRow < *(s32 *)(*(u8 **)(*slotp + 0x38) + 8); expandedRow++) {
                    if (signedIndex == *(u16 *)(func_002e48a0(arg0, expandedRow) + 2)) {
                        found = 1;
                        goto expandedSearchDone;
                    }
                }
            }
            found = 0;
expandedSearchDone:
            if (found != 0) {
                continue;
            }
            if (func_00311e40(id) != 0) {
                continue;
            }
            metadata = iGpffffb3d4;
            metadata += metadataOffset;
            if (highLimit2 < metadata[3] || metadata[3] < lowLimit2) {
                continue;
            }
            h = *(s16 *)(p + 8);
            q = *(u8 **)(*slotp + 0x38);
            sw1 = *(u32 *)(q + 4);
            switch (sw1) {
            case 0:
            case 2:
            case 7:
            case 8:
                dst1 = q + h * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                dst1 = q + h * 0x30 + 0xA4;
                break;
            default:
                dst1 = q + h * 0x30 + 0x14;
                break;
            }
            func_0043f9c8(dst1, 0, 0x30);
            h = *(s16 *)(p + 8);
            q = *(u8 **)(*slotp + 0x38);
            sw2 = *(u32 *)(q + 4);
            switch (sw2) {
            case 0:
            case 2:
            case 7:
            case 8:
                dst2 = q + h * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                dst2 = q + h * 0x30 + 0xA4;
                break;
            default:
                dst2 = q + h * 0x30 + 0x14;
                break;
            }
            func_0010cad0(dst2, id);
            *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
        }
        outer++;
    } while (*(s32 *)(p + 8) < 6);
}
```
