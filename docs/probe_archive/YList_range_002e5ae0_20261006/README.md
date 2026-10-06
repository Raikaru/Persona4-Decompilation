# YList range builder: current ABI and range lifetimes

`func_002e5ae0` remains guarded C with its production ASM fallback. The
installed candidate has **45 fully resolved differing words**, emits 1,860
bytes in the 1,872-byte retail window, and has the correct 12-byte zero tail.
This work adds **no C match**.

The current owner is `src/Yajima/y_list.c`. Work started from
`4b32b6ccbb935945461838d8981ba508f675358a` in the isolated
`build/finish-first-party-20261005` worktree. The measured candidate and the
installed owner were both compiled as complete translation units.

## Source changes

The retained body in
[`YList_002e5ae0_bound_lifetimes_6d950a1.md`](../YList_002e5ae0_bound_lifetimes_6d950a1.md)
recovers the signed level, range-bound and metadata-offset lifetimes. Its old
declarations were adapted to the current, consistent
`void func_002e5ae0(s8, u16 *, s8)` contract. The two active callers in
`src/Event/Fcl/y_fclCombine.c` already use that contract, so no caller or
shared-header change was needed. The existing `memset` declaration names the
same retail operation as the archive's `func_0043f9c8` calls.

Each scan preserves the promoted signed candidate index and its 14-byte
metadata offset. The metadata base is reloaded after the predicate calls.
The initial and expanded membership searches have distinct counters and
explicit result joins. Signed bounds are promoted at their actual uses,
which produces the retail spill and reload widths.

Two equivalent comparisons close six additional words. Writing the lower
bound on the left (`lowLimit > metadata[3]`) selects retail's comparison
temporary in both scans. Writing the expanded completion condition as
`count <= 5` does the same for the final loop branch. These preserve the
accepted levels, callback order and completion condition.

| Complete-owner candidate | Emitted bytes | Differing words |
| --- | ---: | ---: |
| Starting current guard | 1,884 | 398, relocation-masked screening |
| Archived lifetimes with current ABI | 1,860 | 51, relocation-masked screening |
| Installed guard | 1,860 | 45, masked and fully resolved |

The remaining instructions differ only in register assignment: the slot
address and temporary values use `$s1`/`$s2` in the opposite roles, and the
expanded scan's raw and promoted indices use `$s6`/`$s7` in the opposite
roles. The exact offsets and resolved target hash are in `receipt.json`.

## Proof

The independent resolver verifies every target reference, including direct
calls, paired HI16/LO16 references and the GP-relative metadata loads. All
**35 target code relocations** resolve to the retail targets. The four
range-builder switch tables are independently resolved and compared in full:

| Table operation | Retail address | Bytes | Verified pointer entries |
| --- | --- | ---: | ---: |
| Initial clear | `0x00748e30` | 44 | 11 |
| Initial initialize | `0x00748e00` | 44 | 11 |
| Expanded clear | `0x00748dd0` | 44 | 11 |
| Expanded initialize | `0x00748da0` | 44 | 11 |

All **36 sibling functions** retain their instruction bytes and canonical
relocation targets. Their resolved instructions match retail. The complete
guarded owner has **33 exact owned data sections**, with **350 resolved data
entries**, including the 44 entries above.

The production owner was compiled before and after installation. Its
objects are byte-identical in this run. Independent comparison verifies all
**37 production functions**, **368 code relocations**, **29 owned data
sections** and **306 data relocations** against retail. The normal verifier
reports **36 MATCH / 1 ASM**, with no mismatch.

`decomp_lint.py` reports zero errors and six existing warnings: five measured
optimization pragmas and the pre-existing `func_00452080` declaration
advisory. No warning was added by the range builder. `git diff --check`
passes. Source line endings are preserved.

## Replay

The replay authenticates 25 source, header, assembly, configuration and proof
inputs, the configured compiler's SHA-256 and its unit flags, and the retail
ELF identity. It compiles the installed owner in both production and
`NON_MATCHING` profiles, resolves code and owned data, and checks the recorded
residual. It reads the compiler and retail ELF from the local tool setup.

From the worktree root, use a new output directory:

```text
python docs/probe_archive/YList_range_002e5ae0_20261006/replay.py --output build/ylist-range-replay-20261006
```

`--hashes-only` checks recorded inputs. `--objects DIRECTORY` checks existing
`default.o` and `guarded.o` files without recompiling. Proof output must be
inside this repository's `build` directory.

The completed replay is retained at
`build/finish-20261006/fcl-worker5/installed-replay/`. It includes both object
files, compile logs, `production-proof.json` and `guarded-proof.json`.
The normal verifier report is
`build/finish-20261006/fcl-worker5/y_list-verify.json`.

## Other probes retained for the next pass

The lane's isolated scratch directory contains 58 probe records: 55 compiled
nonmatches and three compile-error records. `probe-inventory.json` lists
every source body, result and score path. The repaired forms of the failed
comparison and snapshot probes were subsequently measured; they do not
improve the installed result.

The restored range builder was also tested with the matched sibling's list
helpers, a shared scan helper, loop motion and lifetime settings, implicit
task-slot lookup, declaration hints and shared counter roles. The best of
those ties at 45 words. The positive append-range spelling also produces
45 words when combined with the inclusive completion condition; the
installed body retains the existing early-exit structure.

Fresh controls confirmed the other eight assigned residuals: `00375f00` 2,
`003768e0` 973, `00320b80` 73, `00323d00` 29, `00324680` 15, `0036ee60` 82,
`0036f880` 14 and `0024be40` 7 masked differing words. New Fcl alpha and column
lifetimes, shuffle selection and membership boundaries, and community row
construction did not improve their controls. Those owners are unchanged by
this worker. Earlier source bodies and measurements remain in their
original archives and scratch folders.
