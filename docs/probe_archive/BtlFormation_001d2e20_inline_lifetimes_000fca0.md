# Formation callback: bounded inline-lifetime follow-up

`func_001d2e20` remains **NONMATCHING**. This run found no new exact body and
made no live source, header, configuration, or tool changes. The previously
recovered typed proposal remains a useful structural baseline, not a promotion.

## Current-context measurements

The complete owner is `src/Battle/btlFormation.c`. It is unchanged between
`167e607` and upstream `f3d59b1`. Fresh builds used rebased HEAD
`000fca07c5203f373cb6035ef3654df61bf3c614`, the logical owner's b210 compiler,
and `-O2 -Iinclude`. Owner SHA-256:
`236e2ffe92ef722267d62dd957571a080dc1750f18d1d8f51924fda212672dbb`.
The owner and its two included headers remained unchanged throughout validation.

The retail window is 448 bytes. Its executable body is 444 bytes, including
the zero-valued `jr` delay slot at `0x001d2fd8`. Only the final word at
`0x001d2fdc` is alignment. The configured, hash-validated retail ELF agrees
byte-for-byte with the entire assembly window.

| Full-owner candidate | Object bytes | Masked differing words | Independently resolved differing words | Structural edits |
| --- | ---: | ---: | ---: | ---: |
| Production ASM control | 448 | 0 | 0 | 0 |
| Current guarded C | 440 | 89 | 99 | 48 |
| `Recovery_20260920_pending/001d2e20.c` | 440 | 87 | 97 | 14 |
| `SFRM_001d2e20_body.c` transient/saved-mode proposal | 440 | 89 | 99 | 31 |

These measurements supersede stale current-owner comments for this compiler
context. The typed recovered proposal has 295 unmasked differing bytes after
all relocations are resolved, plus a four-byte executable coverage deficit.
The structural edit calculation preserves the mandatory terminal delay slot;
the repository's trailing-zero heuristic instead reports 49/15 edits for the
guard/recovered proposal by removing that slot from its shorter comparison.
Neither structural count establishes an exact match.

## Evidence and coherent value domains

Read before probing: the entire current owner; the complete retail function;
IDA `src/Battle/btlFormation.c:402-440`; Ghidra's complete function at
lines 358-395; the IDA, SFRM, and recovered pending archives; and the actual
providers and owning constructor.

The providers are `func_00199d00(s32, u8*, s64, s32)` and
`func_001f1210(u8*, s64, s32)`. The position solver's category is `s32`.
The guarded owner's narrower declarations are not the canonical contracts.
The recovered proposal preserves the full-width action argument while taking
the original signed-halfword snapshot from work offset `0xc`.

The constructor is `func_001d3000`, packet type `0xb02` with 16 bytes of work.
Its three pointers and halfword agree with the callback's reads. The first
actor/unit/action/presence values are snapshots; the second unit reference is
reloaded only after the predicate. The category provider returns only 0..3,
so the two solver case groups initialize the genuine `rotation[4]` and
`position[3]` payload on every supported returning path. No padding element,
new guard, fabricated argument, assembly, or register binding was introduced.

## Bounded new probes

Fifteen new candidates tested three concrete hypotheses against those baselines:

* Inline argument lifetime: direct action, direct presence, both direct, and
  a signed-halfword caller transient. All stay at 440 bytes; best ties the
  recovered baseline, while the other forms increase structural edits.
* Reused definitions: staged pointer-to-presence conversion, explicit presence
  branches, reused word selector, combined selector/presence definitions, and
  a scoped propagation boundary for that combined source. Staging ties its
  baseline. Explicit branches grow to 452 bytes and overrun the retail window.
* Actual value domains: boolean presence in the caller, helper, or both, and
  signed-halfword category alone or combined with boolean presence. Boolean
  spellings tie. Narrow categories add argument narrowing, grow to 452 bytes,
  and regress to 26 structural edits despite a lower masked word count.

No broad compiler-control or declaration-permutation sweep was performed.
None of these candidates supersedes the existing typed archive.

## Independent relocation and sibling checks

The typed proposal has exactly ten `R_MIPS_26` relocations, all with addend
zero. Each was resolved from its symbol's address, without copying or masking
retail instruction fields. The complete linked call sequence agrees with
retail. Every call is four bytes early because the initial retained-action
copy is absent:

| Provider | Candidate offsets | Retail offsets |
| --- | --- | --- |
| `func_00199d00` | `0x4c`, `0x88` | `0x50`, `0x8c` |
| `func_001f1210` | `0x68` | `0x6c` |
| `func_001951f0` | `0xe8`, `0x114`, `0x164` | `0xec`, `0x118`, `0x168` |
| `func_00194f10` | `0x124`, `0x174` | `0x128`, `0x178` |
| `func_00194ee0` | `0x134`, `0x184` | `0x138`, `0x188` |

There are zero unresolved relocations. The ten shifted call words explain
the change from 87 masked to 97 unmasked differing words; these are not wrong
call destinations. The remaining structural discrepancy is the absent
`lh $v1` to retained-action copy and the resulting action/presence/category
register assignments. Dispatch block order and the real stack payload
already agree with retail in the recovered proposal.

All **33 sibling functions** have identical raw bytes and identical
function-relative relocation records between fresh production and typed
candidate objects. Both objects emit zero allocated non-executable data
sections, and this target owns no data or jump table. There is no extra
out-of-line helper symbol. These comparisons establish preservation relative
to the current production owner; no new native/game execution or full-build
claim is made.

## Local replay and receipts

All scratch work is under `build/first-party-resume-final/worker4`.
`inputs.json` records owner/header/compiler/ELF hashes and the logical profile.
Each measured directory retains its complete owner copy, C body, object,
compiler log, independently linked target, side-by-side listing, and final
`result.json`. `validation.json` contains all 19 fresh full-owner measurements,
the ten resolved calls, and all 33 sibling byte/relocation comparisons.

The new scratch-only drivers are `probe.py`, `lifetime.py`, `definitions.py`,
`representation.py`, and `validate.py`. Final measurements require Capstone
explicitly, correct its EE `sq`/`lq` decoding, and keep the terminal delay slot.
Preserved `initial-no-decoder-result.json` files are obsolete bootstrap
diagnostics, not acceptance evidence. The final receipt-backed objects were
reanalysed rather than recompiled to correct that diagnostic issue.

The next attempt needs a new explanation for the retained-action copy at
retail `0x001d2e5c`; repeating the inline expression, staged-definition, or
boolean/narrow-category families above has no demonstrated benefit.
