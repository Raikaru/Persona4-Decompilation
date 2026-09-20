# Exact persona-list initializer at 0x002e4090

The isolated proposal for `src/Yajima/y_list.c` recovers `func_002e4090` as exact
C: 1360 emitted bytes in the 1360-byte retail window, 33 fully resolved code
relocations, and no omitted suffix. The nine-entry switch table is exact at
0x00748A40 (36 bytes, nine R_MIPS_32 relocations). The existing four-byte metadata
pointer at 0x007644C4 is also covered by the owned-data proof.

This work was prepared on `1adec7e926b81497a86b3a4238ba57edfb780c2b`, after the
prime installed the SDK registration package. It only writes scratch and this
note. Production integration remains with the prime.

## Mechanism

The prime's frozen lifetime pass reduced the guarded draft from 74 to 14
differing words while preserving the 1360-byte size. Those saved source/object
pairs were validated and reused without recompilation. The remaining fourteen
sites all belong to case 6: four reversed scratch-buffer addresses and ten
instructions affected by an incorrect lookup key.

Retail copies the inventory record into the 0x30-byte object at stack offset
0x40. At 0x002e43f0 it loads the copied record's unsigned halfword ID from
stack offset 0x42. That ID indexes the 14-byte metadata rows and supplies the
argument to `func_0010fcb0`. The guarded draft used the inventory loop index at
both sites. Inventory slot and persona ID are distinct: a persona stored in
slot 2 can have ID 57, so both metadata and compendium lookup must use 57.

`YListPersonaRecord` names the real leading `u16 flags` and `u16 id` fields and
retains the remaining 0x2C bytes. Declaring the compendium record before the
inventory copy gives their retail stack homes, respectively 0x70 and 0x40.
The function's scoped `opt_lifetimes on` preserves the saved-register assignment
found by the prime. Neither loop bounds nor the state-machine modes change.

Two bounded proposals were compiled: corrected byte buffers and corrected typed
records. Both resolved to zero differing words with identical function bytes.
The typed version was selected for the final handoff. No card or shuffle jobs
were repeated during this continuation.

## Provider and caller review

The complete current owner, the registration caller `func_002e4610`, its list
readers, and the comparison helper `func_002e5270` were read before editing.
`func_002e4610` allocates 0x3014 bytes, registers an `s32 (u8 *)` update callback,
and initializes state, mode, and row count. Existing SDK declarations and
registration changes remain in the final source.

The recovered provider definitions establish the declarations used here:

- `datPersona.c`: `func_0010a900(s32)` returns `u16 *`;
  `func_0010ace0(s16)` returns an inventory record; `func_0010abd0(s16)` tests its
  active flag; `func_0010b5b0(void)` returns inventory capacity;
  `func_0010cad0(u8 *, u16)` initializes a record and writes its ID at offset 2.
- `g_data.c`: `func_0010fcb0(s32)` returns a `u8 *` compendium record indexed by
  persona ID. `func_0010ffa0(void)` has no argument. The draft's extra argument
  was removed and the file-scope declaration corrected.
- Retail `func_0043f810` returns the destination pointer after copying an
  unsigned byte count. Retail `func_0043f9c8` likewise returns its destination
  and takes an unsigned count. Their file-scope declarations now reflect those
  contracts. All callers in this complete owner preserve their machine code.

The target compares true provider pointers and removes the draft's intermediate
pointer-to-integer round trips. No caller-only prototype, extra argument,
assembly, volatility, or emitted padding is introduced.

Primary evidence is retained in `cards/ylist4090/current-inputs/`, including
the full owner and provider sources. The target references are
`docs/ida_headstart/src/Yajima/y_list.c:514-632`,
`docs/ghidra_headstart/src/Yajima/y_list.c:557-661`, and the complete
`asm/nonmatchings/y_list/func_002e4090.s`.

## Final verification and integration

All paths below are relative to
`build/first-party-resume-continue/cards/ylist4090/final/`.

`proposed/y_list.c` and `proposed/owner.o` are the final complete logical owner.
The existing SDK baseline object was reused after matching its source, included
headers, profile, receipt hash, and object hash. `baseline-selection.json` and
`before/` preserve that evidence. Its original receipt did not hash the compiler
binary; the final compilation records the actual compiler hash separately.

All 36 other functions preserve their bytes and canonical relocations. All 17
existing allocated data sections are preserved. The newly owned 36-byte switch
table is fully resolved and compared with retail; the metadata pointer is an
existing section. `exact-proof.json`, `comparison.json`, and
`data-comparison.json` record those checks.

The repository verifier exits successfully with 37 functions scanned:
31 MATCH and 6 ASM. The new target is MATCH with normalized difference zero.
`git apply --check` succeeds for `integration.patch`. Neither command applies
the patch to production.

```text
Final source SHA-256
844b6481d71a8696195b0534cb033648fe86dacc578ec25c4600c85f232a84a8

Complete object SHA-256
360319957b49f24bb3e7335b8b44642ffa4067fb93630e8137f1c0926ee9f733

Resolved target SHA-256
b9907b018018229e3acc0e5fccb319d018b166b6f0aa2291cc99a7823b9cfdb5

Resolved switch-table SHA-256
fa56eac72aff3927fe69d39e9c8c9cbb5c7c6268a0be7ea1353229758facd46b
```

The toolchain is configured MWCCPS2 3.0.1 b210 with the logical owner's `-O2`
profile and immutable copies of the current headers. Effective flags, source
hash, object hash, and include/config receipts are retained under `final/`.

The final check was:

```powershell
py -3 -B tools\verify.py build\first-party-resume-continue\cards\ylist4090\final\proposed\y_list.c --json build\first-party-resume-continue\cards\ylist4090\final\verify.json --show-mismatches
```

The replay scripts `lane.py`, `persona_id.py`, and `finalize.py` preserve the
saved inputs and reuse completed objects. The handoff file
`build/first-party-resume-continue/cards/release.md` is the prime's requested
fallback communication channel because agent delivery returns `AGENTS_BUSY`.
