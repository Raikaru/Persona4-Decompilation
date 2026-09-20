# Camp item application: func_0013c700

The accepted C body emits 852 executable bytes in the 864-byte retail window.
All 22 code relocations resolve to the retail destinations, the remaining
twelve bytes are zero alignment, and the target introduces no owned data.

## Source and contracts

The original item-list index remains live across item application callbacks.
The recipient traversal and the selection chosen after rebuilding the list
have independent counters. The early item lookup uses the existing interleaved
halfword array, while the later count update uses the numeric byte offset.
These expressions refer to the same original row without incorrectly keeping
one scaled index live through the entire operation.

The loaded item has two actual views: a signed halfword for the item accessors
and its promoted word for the inventory setter. Each value is initialized from
the same load and used by the appropriate real provider. The corresponding
promoted views in the existing equipment handler `0013d5d0` also preserve its
instruction stream under the corrected file-level inventory declaration.

The target's first two parameters are signed halfwords. Both calls from
`0013bcf0` pass character 1; their recipient is a signed party entry or -1.
The table accessor now receives its actual item argument, including the
previously omitted argument in `0013c6d0`, and uses the provider's
`GDataEntry *(s16)` declaration.

The selection setter `0012ff40` receives its value as a word and stores its low
halfword. Its definition and all ten calls now agree. The seven existing calls
outside the new target retain their real word or explicitly narrowed values;
the provider and every neighboring function retain their exact bytes.

Review also found that the predicate wrapper `00354010` was declared `void`
despite both camp callers consuming its result. The real `0015a560` provider
returns `s32`. The wrapper now declares and explicitly forwards that result.
Its complete 32-byte function and its entire owning object remain unchanged.
This closes the same previously inherited return contract in `0013f720`.

## Behavior and valid state

The selected index addresses an existing item/count pair. Its signed-halfword
row and column inputs cannot overflow a signed word when summed and scaled for
the array lookup. The item list builder supplies IDs 0x300 through 0x5FF,
at most 768 entries, and positive cached counts from 1 through 255. Recipient
traversal is entry-tested and bounded by the signed-halfword party count.

Only successful use deducts inventory. State 3 sets flag 0x1401; the other
successful states update effects and decrement the original cached count.
When that count reaches zero, the list is rebuilt before adjusting the new
selection. Failure, normal success, and special state retain their distinct
sound behavior. The predecrement writes the low halfword before testing its
narrowed result. No artificial initialization, padding, assembly, volatile
access or fabricated side effect is added.

## Verification

Six fresh configured whole-owner compilations compare the three affected
owners before and after the change: 184 MATCH / 21 ASM becomes 185 MATCH /
20 ASM. `0013c700` is the sole new C match. All **204 other functions** retain
their instruction bytes and canonical relocation records; all **15 allocated
data sections** are unchanged. Independent full resolution also covers the
existing equipment and selection callers, `0013f720`, `0013fb50`, the selection
setter and the predicate wrapper. Two inherited optimization advisories remain;
there are no new lint findings or errors.

The immutable release and complete proof are under
`build/first-party-resume-now/camp/item3c700/release-final/` in the recovery
worktree. `proof/complete-proof.json`, `semantic-evidence.json`,
`caller-searches.json` and the six compiler receipts retain the exact inputs
and results. The final audit reuses already completed compiler jobs; it does
not repeat them merely to recover an interrupted worker's terminal.

```text
python tools/verify.py src/promoted/code1_0013.c src/promoted/code1_0012.c src/promoted/code1_0035.c --show-mismatches --json build/camp-item-verify.json
```
