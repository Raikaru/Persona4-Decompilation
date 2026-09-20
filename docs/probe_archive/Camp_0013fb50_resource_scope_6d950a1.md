# Camp status initialization: func_0013fb50

The continuation from `6d950a12d36f08706cd42225d5513e5a50d25748` recovers
`func_0013fb50` in `src/promoted/code1_0013.c` as ordinary C. A fresh complete
owner compilation under the configured MWCCPS2 b210 `-O2` profile emits 1060
executable bytes in the 1072-byte retail window. All 42 relocations resolve
independently to the expected targets, every executable byte is equal, and
the remaining twelve retail bytes are zero alignment bytes.

## Mechanism and measurements

The saved floor was reproduced before making changes. The current retail
alignment contradicts the stale nearby note about displaced error blocks:
the resource fetches and branches already occur in the correct order. The
remaining allocation rotates the three resources, slot pointer and final
loop counter. The counter has no use outside sprite construction; giving it
a block local to that loop reproduces the retail allocation. The third
resource is assigned both to its local and to the persistent field, using
the chained assignment present in the recovered cmpEquip/cmpSkill family.

All rows are whole-owner b210 `-O2` compilations and emit 1060 / 1072 bytes.

| Candidate | Resolved differing words | Aligned edits |
| --- | ---: | ---: |
| Saved draft | 28 | 28 |
| Resource pointer return and locals | 28 | 28 |
| Actual sprite-provider contract | 25 | 56 |
| Chained third-resource storage | 24 | 55 |
| Final loop counter scoped to sprite construction | 0 | 0 |
| All callee contracts audited; clean single-splice owner | 0 | 0 |

The temporary rise in aligned edits is a SequenceMatcher alignment across
three nearly identical sprite-construction branches. Direct resolved words
remain the primary byte comparison. Final equality is independent of this
diagnostic alignment.

The inherited loop-invariant optimization is retained with one scoped
push/pop pair. The release is reconstructed once from the frozen owner;
earlier experimental files carrying repeated pragma lines are not the
release source.

## Contracts and behavior

The final declarations agree with the actual providers:

| Function | Contract and use |
| --- | --- |
| `0043f9c8` | `void *(void *, s32, u32)`; retail uses destination, fill byte and unsigned size, returns the original destination. The return is unused here. |
| `00353c10` | `s16(s16 *)`; fills at most eight character IDs and returns their count. |
| `0046a770` | `u8 *(char *)`; traverses the resource list using the supplied filename. |
| `0046d200` | `u8 *(u32, u32)`; stores the resource bits and unsigned sprite ID in the new node. |
| `0046d730` | `void(void *, s32)`; all five assertion call sites remain. |
| `00354a50` | `u8 *(s32, u16)`; receives parent zero and mode one; its task pointer is stored at `+0x3c`. |
| `00141d80` | `s32(u8 *, s32)`; initializes state zero; its result is unused here. |

The initializer remains `void(u8 *)`; its actual caller `00142f20` supplies
the work pointer and ignores the result. All four loop entry tests, counts
(1, 41, 108, 25), memory writes, resource lookup order, failure calls and
final initialization calls are preserved.

Retail resource names at `005e5830`, `005e5850`, `005e57f0`, and `005e5810`
are respectively `init/c_equip_01.spr`, `init/c_equip_help_02.spr`,
`init/c_tittle_01.spr`, and `init/c_top_01.spr`. The assertion filename at
`005ef6c8` is `cmpStatus.c`.

The 25-byte sprite-ID table at `005eda00` contains ID 207 at index 23, so
the unsigned byte load is material. Both scale fields in each of the 41
records at `005edea0` contain exactly 4096.0: all 82 float conversions are
finite, integral, and representable in both the unsigned conversion type
and the signed-halfword destination. The four counter ranges avoid
halfword overflow; every direct store fits the caller's 0x18b0-byte work
area. The target introduces no compiler-owned data.

## Acceptance evidence

Fresh official `verify_file` checks report **35 MATCH / 8 ASM before** and
**36 MATCH / 7 ASM after** for the complete owner. Only `0013fb50` changes
status. All 42 sibling function byte streams and canonical relocations,
plus all three allocated data sections and their relocations, are unchanged.
The previously committed `0013f720` is independently rechecked as exact
1060 / 1072 bytes with all 30 relocations resolved.

Both fresh compiler jobs exit zero; their only output is the existing
`MWCIncludes` environment warning. Lint reports zero errors and the same
single H003 advisory at line 772 outside this target before and after.
`git apply --check` passes. `git diff --no-index --check` emits no whitespace
diagnostics and returns one for the differing files.

Evidence is under `build/first-party-resume-now/camp/`. Use **release2/**:
`src/promoted/code1_0013.c` is the complete proposed owner;
`func_0013fb50.c` is the standalone body; `change.patch` is the review patch.
`formal/before/` and `formal/release2/` contain fresh compiler commands,
exit records, logs, objects and verifier reports. `release2/proof/` contains
`whole-owner-proof.json`, `semantic-evidence.json`, and `resolved.bin`.
The production owner still equaled its frozen input when the proof completed.
