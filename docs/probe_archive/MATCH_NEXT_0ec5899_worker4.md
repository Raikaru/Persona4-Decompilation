# Worker-4 ordinary-C matching review at 0ec5899

Worktree: `/persona4-decompilation/build/match-next-latest`, branch
`work/match-next-0ec5899`, initial HEAD
`0ec589932637d637b451882bfbaa479d5f8043a9`.
No production source, shared harness, configuration or dependency was edited
by this worker. Existing edits in other worktrees and the prepared Windows
owner-lock port were preserved.

## Results

`func_003627b0` is already unguarded C upstream. Fresh scoped `tools/verify.py`
reported MATCH, 1864 emitted bytes in the 1872-byte window, normalized_diff 0.
Its owner `src/promoted/code1_0036.c` reported 31 MATCH and 3 ASM. The saved
report is `build/match-next/0036-initial-verify-worker4.json`; the older handoff
description of a four-word residual is stale for this HEAD.

Two ordinary-C fallbacks were investigated without new matches. All retained
candidate measurements use the complete current owning translation unit with
native configured MWCCPS2 b210 and `build/match-next/harness.py`.

| Target and owner | Fresh C baseline | Remaining executable words |
| --- | --- | --- |
| `00375f00`, `src/Battle/btlShuffleDraw.c` | 156/160 bytes, four-byte zero suffix | 2, at offsets 0x48 and 0x70 |
| `0034ddf0`, `src/promoted/nLine.c` | 700/704 bytes, four-byte zero suffix | 5, at offsets 0x118, 0x11C, 0x130, 0x134 and 0x138 |

Neither target was promoted: both retain their original guarded C and
INCLUDE_ASM fallback. These bounded negative results do not prove an exact
source is impossible.

## 00375f00: inline state boundaries

The complete current owner, retail target and caller ASM, IDA/Ghidra target,
the active definitions and retail bodies of `00370410`/`00370a80`, and
`D375_00375f00_body.c` were read. The true target contract is `(u8 *, s32)`;
the two callees each consume one motion/rotation pointer. The target calls
motion initialization, writes state 5, calls rotation initialization, then
writes state 3. The caller `00374a10` clears its flag after the target returns;
the target must not add such a flag store.

The baseline and its existing scoped O1 setting reproduce all instructions
except two recomputations `addu ...,s1,s0` where retail copies the cached
`s2` base. Six new probes tested meaningful inline API boundaries rather
than repeating the archive's broad pragma and local-spelling sweeps:

| Probe mechanism | Words / emitted bytes |
| --- | --- |
| Inline motion/rotation state setters, defined at O1 or O2 | 2 / 156 |
| Inline state-address helper with real parent, offset and field operands, O1 or O2 | 27 / 164 |
| Inline paired initialization-plus-state helpers, O1 or O2 | 21 / 152 |

All six complete compile jobs finished. Artifacts are under
`build/match-next/00375f00/`: `worker4_probe.py`, `measurements.json`, each
candidate `.c`, whole-owner `.tu.txt` and `.o`, compiler `.log`, positional
`.diff.txt`, and instruction `.align.txt`. The original C floor remains best.

Independent resolution of both target R_MIPS_26 relocations reproduces the
retail call words, leaving exactly the two listed executable differences.
All 51 sibling function bodies remain byte-identical in the baseline C
substitution. Forty-nine have identical relocation records; the two others
only rename compiler-local symbols (`@534` to `@539` and `@558` to `@563`).
Their section, value, size and symbol information are identical after
canonicalization, and allocated data is identical. No sibling behavior change
is inferred from those generated-label name changes.

## 0034ddf0: float-to-byte boundaries

The complete nLine owner, retail target, IDA/Ghidra target, its two switch
calls in `0034c860`, active vertex-writer body and retail vertex-writer ASM,
and `VNLN_0034ddf0_body.c` were read. Retail's difference is conversion
destination selection: `cvt.w.s f1,f2` versus `cvt.w.s f2,f2`, followed by
the corresponding mfc1 and high-path subtraction/conversion register fields.
The height, byte-alpha snapshot, four vertex calls and per-call right-edge
additions are otherwise present.

Thirteen concrete probes tested inline byte conversion, inline product,
combined product/conversion, height-product boundaries, an output-pointer
conversion helper, and four aggregates containing only actual used alpha
values. Eleven tied the original 5 words / 700 bytes. Moving the later
height product through `mulF`, alone or with the byte-conversion boundary,
regressed to 12 words / 700 bytes. No ordinary assembly, volatile/register
forcing, dummy state, extra callback, or broad pragma sweep was used.

Artifacts are under `build/match-next/0034ddf0/` with the same naming as
above. Its `worker4_probe.py` retains the exact probe definitions. Independent
resolution of all 12 relocations reproduces each retail relocation word.
All 27 siblings have identical byte and relocation records, and allocated
data remains identical for the retained baseline C substitution.

Acceptance caveat: nLine currently declares `0034f0d0` with its destination
pointer first, whereas the active `src/promoted/code1_0034.c:441-450` definition
orders parameters as two floats, pointer, two floats, then four bytes. The EE
integer/float register groups agree for current calls, but those declarations
are not compatible C function types. The camera getter also uses a pointer
return declaration where active `code1_0045.c` exposes an s32 handle. Neither
dependency was edited in this bounded unsuccessful probe. A future accepted
candidate must complete the real provider/caller contract correction and
whole-owner revalidation rather than infer C type compatibility from byte
equality.

## Retained proof and final checks

`build/match-next/00375f00/worker4_audit.py` reads the already compiled objects;
it launches no compiler. Its two `worker4-audit.json` outputs retain source,
script, body and object hashes, exact residual byte/word positions, resolved
relocations, every sibling comparison, allocated-data identities and compiler
profile. Current owner bytes were asserted equal to each saved original owner.

| Artifact | SHA256 |
| --- | --- |
| btlShuffleDraw unchanged owner | `17123e455becef797297f5ddad4d4c021c90fef1c1f4aa4d7b6ea8cb8abcd911` |
| 00375f00 baseline whole-owner object | `4a84c4b0b1cc5cdbc902b100dfc980ba2e6134b3c37cc31ee56550f95da532cf` |
| nLine unchanged owner | `73e422e52c5be1bb41c6199fa0034292d0c8eb661daac78dfeae6394300f4939` |
| 0034ddf0 baseline whole-owner object | `64ca904ce0b5d9281df92a2e1858fd2a18fd07b95238a8db81bc0eea27be5a49` |

Final scoped command:

```text
python tools/verify.py src/Battle/btlShuffleDraw.c src/promoted/nLine.c --json build/match-next/worker4-final-verify.json --show-mismatches
```

Result: **80 scanned, 72 MATCH, 8 ASM, no mismatches**. This reports the
unchanged production owners; their ASM targets are not counted as recovered C.
Final compile batch session 12111 completed with exit 0 and all output delivered.
Probe sessions 65145, 9105 and 16102 also completed with exit 0. There is no
worker-owned compiler still running. The initial 003627b0 verification's
anonymous terminal could not be adopted after identity recovery; its completed
saved JSON was inspected without rerunning that successful job.

The Python interpreter printed the existing nonfatal `pywin32_bootstrap`
startup warning. No full build, global test run, commit or push was attempted.

## Read-only review of the Fcl aggregate migration

At prime's request, worker-4 subsequently reviewed worker-5's integrated diff
in `y_fclCombine.c`, `y_fclCombineDraw.c` and
`include/fcl_combine_internal.h`. This was a read-only review: no Fcl source
edit, compiler invocation or probe was performed by worker-4.

No new semantic defect was found in this migration. All 17 named callsites of
`003147e0` supply the six arguments and preserve slot, resource, order and mode.
The two-float value retains x at offset zero and y at offset four. Retail
`0031481C` saves the incoming third argument at stack+0xE8, then reads x/y at
0xE8/0xEC; the aggregate formal expresses those same values. The position
constructor's active body in `code1_002b.c:141-147` writes exactly those two
floats. The union owns the full eight bytes used by packed constructor outputs.

The three repaired descriptor snapshots in guarded `002e90d0` read the current
`002b6150` result at +0x38/+0x3C before the draw call. That matches retail loads
at `002EABDC`, `002EACE4` and `002EAF34`; the former stale integer receiver is no
longer used for these snapshots. In `0032f4d0`, `tbl[6]` covers the maximum six
rows, and its final `tbl[5]` scratch position is initialized before copying to
the active slot. The possible self-assignment when the active slot is five
is valid. Optional-row ordering, signed loop values, y adjustments, all six
draw arguments, and the later color-copy/call order remain intact.

The current source hashes were read with `Get-FileHash`, independently of the
proposal-source hashes:

| Reviewed file | SHA256 |
| --- | --- |
| `src/Event/Fcl/y_fclCombineDraw.c` | `679c6110d4fff4f1dd985da5db2017b073edf56526d28a71b41d69dec01d9226` |
| `src/Event/Fcl/y_fclCombine.c` | `b413ae912c0c2a9949f07d85c5d222711cb262f0ee1a47234eeb2b5248cb4039` |
| `include/fcl_combine_internal.h` | `d2dcbede2fb43d18b7b7a0493f0f9a26d726c5718ffc385db9de5cf57f805e01` |

The retained `build/match-next/fcl-contract/current/proof.json` identifies
these integrated sources and records `0032f4d0` exact at 1368/1376 bytes,
eight zero tail bytes and 22 resolved relocations. Its local caller
`00315310` is recorded exact at 740/752. The worker-5 scoped-current report
records 63 MATCH and 48 ASM. Those are reviewed results produced by the
matching/integration lane, not additional worker-4 compiler runs.

One existing declaration limitation remains outside the aggregate migration:
`002b2970` is declared with `void *` in the draw owner and `s64 *` in the combine
owner while its active definition takes `u8 *`. Its observed output memory
contract is the same eight-byte x/y pair, but the pointer parameter spellings
are not compatible C function types. This review does not claim that the
pre-existing constructor declaration discrepancy, or the remaining guarded
provider/state-machine residuals, has been resolved.
