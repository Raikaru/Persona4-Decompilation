# datCalc revival: retained recovery and guarded caller closure

The recovered-upstream owner still has the exact source hash
`1b9591a919c9d39de3c72f542aa7a008e2726b92db16d7c4524764450fe82dd0`.
The saved official object/report remain intact and report 80 MATCH, zero ASM.
No completed datCalc compilation was repeated during this revival.

`build/first-party-next/datcalc/worker2-resume-seal-v1/current-proof-index.json`
is the compact release index (SHA256
`d21e3a001cb7116d822d86c57cc4daa309e31abe2b4eaa72392e21d6ae9539e0`).
The same folder contains `siblings.json`, `damage-siblings.json`, and
`allocated-data.json`, recording individual body and canonical-relocation
hashes for the 78 unchanged functions across both recoveries and the 79
unchanged functions across the damage step. Every saved compile input and the
current effective command/compiler still matches its snapshot.

The final saved official object was resolved again without masking code
relocations. Damage is exactly 12,176 bytes with 363 relocations; hit/evasion
is 10,920 bytes with 325 relocations and eight zero suffix bytes. The damage
effect table at `0x00747bc0` has 68 exact bytes and 17 resolved pointer entries,
followed by four zero bytes in its reserved window. The complete original
proofs remain under `worker2-damage-live/resolved/` and are referenced by hash
in the release index. Re-resolution used no compiler.

## Separately enabled guarded callers

The new scratch audit at
`build/first-party-next/datcalc/worker2-guarded-callers-v1/` enables only the
named guarded function in each owner. It compares the existing C body with
the same body using explicit declarations of the promoted damage/hit
interfaces. Production guards remain in the proposed patches.

| Owner/function | Audited calls | Unchanged function bodies and relocations |
| --- | --- | --- |
| `code1_001e.c`, `001e9950` | Two damage calls | All 120 functions and allocated data |
| `code1_001f.c`, `001f14f0` | Two damage and two hit calls | All 158 functions and allocated data |

The `001e9950` before/after objects are identical, hash
`2e218165b4e443b72cd9e067fb9855c92638fd3965a065fdf246eb52f534942b`.
The `001f14f0` objects have different object metadata, but every emitted
function body, canonical relocation identity and allocated data section is
unchanged. Its function-body hash in both objects is
`2462e3ea5d72ad0c5f3432cb6ffa1ebd5cc33198ad93d8c5039a7338410c3c0e`.
Neither guarded caller is claimed to match retail; this audit proves that
using the completed providers' explicit C contracts preserves the existing
independently enabled callers.

The reviewed external declaration patches are saved under each owner's
audit subfolder as `external.apply_patch`, with exact source hashes and
compiler receipts in `proposal.json`, `before/receipt.json`, and
`after/receipt.json`. They have not been applied by worker-2.

Prime separately applied the previously reviewed `btlAICommand.c` patch.
Its current hash is
`5a4b95fd76b9c65967f793f59b4b48254809f7414e17cae02771818b49ff2f99`.
The source differs from the measured `425af19b...` candidate only in trailing
newline bytes; the code and all three typed pointer/prototype edits agree.
The release index records the exact current and proposed hashes and suffix
lengths. Worker-2 did not alter that integration.

## Session receipt

CoS run `f4ffecca-d096-407d-9813-a1c0092cb1d1`, worker-2, now routes messages to
prime successfully. Current hash inspection completed in terminal session
80926; the independent guarded-caller jobs completed in session 75290 with
each caller command exiting zero. Its preceding first seal command rejected
the changed AI source hash, which was explained by the final blank-line
removal. Corrected read-only sealing completed in session 11296, exit zero.
The session-recording lookup action itself returned JSON-RPC `-32602`,
`Tool session not found`; the release index records that limitation and the
actual terminal IDs instead of inventing a recording ID.

All compiler jobs and owner locks are released. No publish checkout, commit,
rebase, push, full-tree build or image build was performed by this lane.
