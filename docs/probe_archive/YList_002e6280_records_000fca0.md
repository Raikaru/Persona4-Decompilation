# List candidate builder: 002e6280

Measured on September 20, 2026 against `000fca07c5203f373cb6035ef3654df61bf3c614`,
rebased onto `f3d59b1`. The owning `src/Yajima/y_list.c` is unchanged from that
upstream. **This is a corrected ordinary-C floor, not an accepted match.**
Production remains `INCLUDE_ASM`; no live source, header, configuration or tool
was changed by this lane.

The retained candidate emits **936 executable bytes in a 944-byte window**.
After independently resolving all sixteen code relocations, **fourteen words
still differ**. The final eight retail bytes are zero alignment after the
return delay slot. Both eleven-entry switch tables resolve byte-for-byte to
retail: 44 bytes at `00748e90` for clearing a row, and 44 bytes at `00748e60`
for initializing it. Their four-byte alignment suffixes are also zero.

## Structural recovery

The previous draft was not merely an allocation floor. It loaded a pointer
from the metadata record instead of addressing the record directly, tested
only a byte of its halfword flags, cached the metadata base across callbacks,
discarded the saved list pointer, and wrote a halfword count after the new
persona was initialized. It also merged each switch's default into the first
case group, deleting distinct code paths present in retail.

The corrected body uses the fourteen-byte metadata stride, reads the halfword
flags, retains the original list for the count, reloads the active list at
each row lookup, and reloads the metadata base for the level test. The final
count update is a fresh 32-bit load/add/store. The exclusion scan uses a
32-bit index; the persona and existing-list indices retain their signed
halfword behavior. Each search assigns its result at the matching exit or
after exhaustion. Those lifetimes recover retail's `0xb0` frame and its
quadword threshold spill without assembly, forced registers or extra storage.

The complete current owner, retail assembly, IDA/Ghidra targets and prior
`YL_002e6280_body.c` archive were read before reconstruction. Provider evidence
comes from `code1_002b.c` for the bounded increment, `code1_0031.c` for the
three persona predicates, `datPersona.c` for the 0x30-byte initializer, and
the reset/accessor definitions in the current list owner.

## Measurements and remaining difference

All rows below were compiled as complete isolated copies of the current owner
with MWCCPS2 3.0.1 b210 and its configured `-O2 -Iinclude` profile. The last
column is the raw-object alignment metric; final acceptance uses the separate
unmasked proof.

| Source stage | Emitted bytes | Masked differing words | Aligned edits |
| --- | ---: | ---: | ---: |
| Existing guarded draft | 888 | 172 | 147 |
| Draft with truthful provider declarations | 884 | 159 | 146 |
| Separate switch default bodies | 956 | 179 | 91 |
| Direct metadata records | 952 | 206 | 111 |
| Retained list and word count | 956 | 200 | 86 |
| Correct index and key widths | 936 | 68 | 50 |
| Search exits, staged metadata and exclusion key | 936 | 26 | 30 |
| Sequenced level-record reload | 936 | 25 | 28 |
| Signed index scoped to the loop | 936 | 14 | 16 |
| Named count record and full-width level input | 936 | 14 | 16 |

The remaining offsets are `034, 04c, 050, 068, 0d4, 0d8, 0ec, 104, 14c,
1a0, 1c4, 1f8, 2a4, 33c`. They are register selection only. Retail keeps the
slot address in `$s2` and the persona ID in `$s0`; the candidate uses `$s0`
and `$s2`. The incoming level is in `$s0` in retail and `$s1` in the candidate.
The signed persona snapshot, retained list, other saved values, branch layout,
argument order and memory operations agree.

Fifty full-owner compilations are retained. Bounded scope, scalar-width,
initialization, register-storage and inline-search/scan-boundary alternatives
did not close the final cycle. A single lifetime-coalescing control was also
neutral. No generic pragma sweep was run. Merely copying the existing caller
signature `(s32, void *, s64)` emits 940 bytes and 162 masked differing words:
its extra list-selector extension changes an actual instruction. It is not
an exact alternative.

## Contract and isolation gates

Every reconstructed candidate after the raw baseline uses these current
provider declarations in the isolated owner:

```c
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s64 func_00311d00(s32);
extern s32 func_00311d60(s32);
extern s32 func_00311e40(s32);
```

The retained target uses `(s8, void *, s64)`, with an explicit signed-byte
interpretation of the incoming level. Both real guarded callers in
`src/Event/Fcl/y_fclCombine.c` pass the literal list selector `0xd`, but their
declarations at lines 1681 and 2987 still say `(s32, void *, s64)`. Those
declarations and their compiled caller objects must be reconciled before any
future promotion. This lane did not edit or compile that concurrently owned
file. A masked zero alone would not waive this requirement.

The final candidate preserves all **36 sibling functions**, comparing both
bytes and relocation records, and all **17 pre-existing allocated data
sections**, including their relocation records and alignment. Generated local
table names are compared by their owning function and reference order, not
their unstable `@number` spelling. The two new target tables have a separate
independent R_MIPS_32 proof covering every case. Candidate lint reports zero
errors and zero warnings. No game execution or whole-image build is claimed.

## Reproduction and retained evidence

All private artifacts are under
`build/first-party-resume-final/worker4-ylist/`. The selected source is
`byte-list-caller-payload/body.c`, its complete translation unit is `owner.c`,
and `proof.json` contains the unmasked code, table and sibling/data results.
`inputs.json` records the frozen owner/header/compiler/retail inputs;
`final-manifest.json` validates every saved source/object receipt and enumerates
all fifty measurements. The original archive and all previous probe results
remain intact.

| Artifact | SHA-256 |
| --- | --- |
| Candidate body file | `510826d27230d7b488a1ff841ed6fd37736fab92c7fd65a5857f6fd3bc3bd538` |
| Complete candidate owner | `6395eb04946c09894fcfd72d44f94f399dbaf76c22caa67439c9a15155de93e5` |
| Compiled owner object | `ff9bdaa3dc0699d9e0c541da3323c8812613573e8abe2ea2ae315fc5dffcdd6a` |
| Independent proof | `c6e78f9d200fbb51b846751a99938854f2320ac31c0162d3617b019144497a74` |

The C body below is retained for future reconstruction. It requires the
owner's existing declarations and globals plus the four corrected provider
declarations above. Keep the production fallback until the register and
caller gates are both satisfied.

## Retained measured body

```c
void func_002e6280(s8 listId, void *excludedIds, s64 level)
{
    u8 **slot;
    struct ListCountView {
        u32 field00;
        u32 kind;
        s32 count;
    } *originalList;
    s16 personaIndex;
    s32 excludedIndex;
    s16 existingIndex;
    s32 found;
    u8 *activeList;
    s16 rowIndex;
    u32 clearKind;
    u32 initializeKind;
    u8 *clearRow;
    u8 *initializeRow;
    s32 levelLimit;
    s32 metadataOffset;
    s32 exclusionKey;

    slot = &D_00882F70[(s8)listId];
    if (*slot == NULL) {
        return;
    }
    originalList = *(struct ListCountView **)(*slot + 0x38);
    func_002e5960(listId);
    levelLimit = (s16)func_002b2cb0((s8)level, 3, 99, 1, 1);
    personaIndex = 0;
    while (personaIndex < 192) {
        {
            s32 signedIndex = personaIndex;
            u8 *metadata;
            metadata = iGpffffb3d4;
            metadataOffset = signedIndex * 14;
            metadata += metadataOffset;
            if (*(metadata + 2) == 1 && (*(u16 *)metadata & 8) == 0) {
                u16 personaId = (u16)personaIndex;
                if (func_00311d00(personaId) != 0 && func_00311d60(personaId) != 0) {
                    excludedIndex = 0;
                    exclusionKey = personaId & 0xFFFF;
                    while (excludedIndex < 13) {
                        if (exclusionKey == *(u16 *)((u8 *)excludedIds + excludedIndex * 2)) {
                            found = 1;
                            goto exclusionSearchDone;
                        }
                        excludedIndex++;
                    }
                    found = 0;
exclusionSearchDone:
                    if (found == 0) {
                        if (*slot != NULL) {
                            existingIndex = 0;
                            while (((s16)existingIndex) < *(s32 *)(*(u8 **)(*slot + 56) + 8)) {
                                if (signedIndex == *(u16 *)(func_002e48a0(listId, existingIndex) + 2)) {
                                    found = 1;
                                    goto existingSearchDone;
                                }
                                existingIndex++;
                            }
                        }
                        found = 0;
existingSearchDone:
                        if (found == 0 && func_00311e40(personaId) == 0) {
                            u8 *levelRecord;
                            levelRecord = iGpffffb3d4;
                            levelRecord += metadataOffset;
                            if (levelLimit < levelRecord[3]) {
                                goto nextPersona;
                            }
                            rowIndex = (s16)originalList->count;
                            activeList = *(u8 **)(*slot + 56);
                            clearKind = *(u32 *)(activeList + 4);
                            switch (clearKind) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                                clearRow = activeList + (rowIndex * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                clearRow = activeList + (rowIndex * 48) + 164;
                                break;
                            default:
                                clearRow = activeList + (rowIndex * 48) + 20;
                                break;
                            }
                            func_0043f9c8(clearRow, 0, 48);
                            rowIndex = (s16)originalList->count;
                            activeList = *(u8 **)(*slot + 56);
                            initializeKind = *(u32 *)(activeList + 4);
                            switch (initializeKind) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                                initializeRow = activeList + (rowIndex * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                initializeRow = activeList + (rowIndex * 48) + 164;
                                break;
                            default:
                                initializeRow = activeList + (rowIndex * 48) + 20;
                                break;
                            }
                            func_0010cad0(initializeRow, personaId);
                            originalList->count += 1;
                        }
                    }
                }
            }
        }
nextPersona:
        personaIndex++;
    }
}
```
