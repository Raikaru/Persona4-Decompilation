# 001dd920: current native frontier and owned-table review

Owner: `src/Battle/btlAICommand.c`. Worker 3 reproduced the current guarded C
at **39 differing words, 1748/1760 bytes**, then measured 52 additional native
variants. None improved the frontier or reached exact code. The authoritative
owner was not edited; its `NON_MATCHING` guard and assembly fallback remain.
The owner is released with this result, not promoted as MATCH.

All work was first-party and owner-local. No provider, header, vendor, compiler,
build-tool, or configuration changes, commits, pushes, or broad builds/tests
were made. Every compile has a unique retained scratch directory.

## Evidence and identities

The lane is `build/first-party-next-20260922/battle-ai-command-worker3/`.
`probe.py` compiles with explicit named `candidate=source` and
`logical_source=E.OWNER` arguments. Each candidate has its full owner source,
body, native object, compile receipt, score, and instruction alignment.
The original source, object, compiler, and dependency hashes are frozen in
`before/`. No historical compile was rerun or overwritten.

`frontier.py` reads the retained results without compiling. It checked all 53
candidate source/object hashes against their actual-path receipts, confirmed
the owner and dependencies remain unchanged, and produced:

- `frontier-review/result.json`: complete probe inventory, fully resolved
  frontier-code differences, and independently relocated owned-table evidence.
- `frontier-review/resolved-frontier.bin`: the 1748-byte C frontier after all
  36 code relocations are applied; it still differs from retail in 39 words.
- `frontier-review/owned-table.bin`: all 28 bytes of the relocated jump table.
- `frontier-review/released.json`: explicit `exact: false`, `integrated: false`,
  and the released owner/source/object identities.

| Item | SHA-256 |
| --- | --- |
| Current unchanged authoritative source | `5a4b95fd76b9c65967f793f59b4b48254809f7414e17cae02771818b49ff2f99` |
| Inherited authoritative fallback object | `a91adb73b9b8f5538d15031d5c79425e1388b2e911bce50a2a0347d89a401664` |
| Baseline actual C candidate source | `73d955f277227c7237cd89535f97544f871c01e148f7f2b7d53f8979e57a9d1a` |
| Baseline actual C candidate object | `77f0cf9956bea6a7b854c56338fb4281a8965b383c475b1ad1113f5b735d0f28` |

Compiler: native MWCCPS2 b210, `-O2 -Iinclude`, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

## What the current proof establishes

All **262** neighboring function bodies and canonical relocation records agree
with the inherited native object for every one of the 53 probes. The inherited
object has no allocated data. Compiling this target creates one legitimate
28-byte `.rodata` section, aligned to 16 bytes, for the seven-way command switch.
Consequently the raw `data_equal: false` field in probe results records newly
owned target data, not damage to pre-existing sibling data.

The baseline table is placed at retail **0x00747130** by its code references.
All seven R_MIPS_32 relocations name `func_001dd920`; after relocation every
entry is **0x001ddc54**. The complete relocated table equals retail, including
every entry. Its proof is independent of the remaining code mismatch. The
baseline code's missing 12-byte suffix is all zero; the 39 differences are
executable register operands, not missing instructions or suffix bytes.

No official MATCH is claimed for 001dd920. A future exact candidate must pass
the official verifier and full code plus owned-table proof before integration.

## New measurements and the useful negative result

The archive already exhausted general declaration and pragma sweeps. This pass
tested actual classification, query, and collection lifetimes instead:

| Family | Result |
| --- | --- |
| Classification helper/output, native-word staging, single-field aggregates, unused parameter reuse | Best remains 39; value-return helper is 46 |
| Promoted dispatch value, explicit forward classification join, immutable count initialization, separate count scope | 39 |
| Explicit halfword boundaries with native signed/unsigned storage | 39 when the original conversion sequence survives; narrower-domain variants add instructions |
| Separate first/third loop cursor scopes | 39; moving the second cursor or sharing the first two yields 56 |
| Actual selected-result lifetime through the whole function | 395–396 words and a larger frame; not retained |
| New selector consumers/default returns or count promotion before dispatch | Changes executable branches, masks, or lifetime; no improvement |
| Selection state with kind/count/tally/commands, with and without an inline initializer | 46 words, with count now in retail's register |
| Splitting the tally back from that state, or keeping only kind/count metadata together | Returns to the original 39-word exchange |
| Native-word collection tally with explicit halfword boundaries | 163 words; removes retail operations and is not retained |

Full labels, exact sizes, scores, hashes, and alignments are retained rather
than compressed into a claimed new floor. The aggregate experiment is the new
allocation observation: it puts the command count in retail's `$s1`, but swaps
the classification and tally between `$s0` and `$s2`. Separating the tally
restores retail's tally register while reintroducing the original count/selector
exchange. Reordering the actual aggregate fields did not change that outcome.

The unchanged baseline holds classification in `$s1` and source count in `$s0`;
retail uses `$s0` and `$s1`. That exchange propagates into the first two loop
indices and inline usability temporaries, and into the case-2 cursor/entry
allocation. An instruction alignment shows 437 executable words in both,
plus the three omitted zero padding words. Adding a real consumer of the
selector can change allocation, but every measured consumer also changed the
retail instruction stream. No fake consumer, dummy state, empty barrier,
ordinary assembly, or incompatible provider declaration was introduced.

## Behavior and bounded data reviewed

Current owner/callers, the full retail assembly, both IDA/Ghidra references,
and `QAIC_001dd920_body.c` were read before probing. The third argument is
unused by the target; 001de000 calls it when that argument is 0x10. Command
availability is still queried before target-state classification. Usability
checks preserve their calls, and selected command entries are reread after
those calls, matching possible alias effects.

The actual 0023e130 provider returns **8**. Its retail window was independently
decoded as `addiu $v0,$zero,8; jr $ra; nop; nop`, consistent with
`src/datCalc/datCalc_grouped.c:145-148`. The command array from 0023e140 therefore
has eight queried slots, so at most eight candidates enter `table[8]`. This
supports the existing stack-array bound without adding a guard. HP and maximum
HP are narrowed to u16 before multiplication by 100 and 60, respectively;
both products fit the source u32 domain. The final random selection is reached
only when the collected count is positive.

## Exact operational failures

An optional read-only JSON-summary command was blocked before execution with
the OpenAI message that it could not determine the request's safety status;
the relevant existing receipt region was then read directly. Two guessed
provider-assembly file paths were absent; the real retail provider bytes were
read through the configured ELF instead. No compiler failed, no successful
command was replayed to recover a session, and no such error was treated as a
filesystem restriction.
