# Card initialization argument lifetimes at 000fca0

The current `src/promoted/y_CmbCardEff.c` remains unchanged. A fresh configured
MWCCPS2 b210 whole-owner compilation confirms the existing `0033e5c0` C draft
at 500 bytes in its 512-byte window, with 36 differing words after resolving
the target relocations. Its assembly fallback remains in production.

Retail retains the ID-table slot across two card initialization calls. The
first call uses the ID already loaded for the nonzero test; the second loads
the ID again after the first call. The retained slot, object, loop counter,
and card row occupy different saved registers from the existing draft.

Eleven new compiling candidates tested that concrete value/address boundary:

| Candidate family | Number | Emitted bytes | Resolved differing words |
| --- | ---: | ---: | ---: |
| Explicit first ID value and retained slot, slot declaration scopes, paired-call helper, task-to-work parameter reuse, and lifetime analysis | 7 | 492 | 61 |
| Explicit ID/slot and paired helper with common-subexpression elimination disabled | 2 | 516 | 122 |
| An inline slot-address boundary | 1 | 492 | 61 |
| The slot-address boundary with common-subexpression elimination disabled | 1 | 528 | 117 |

The 492-byte variants fix the saved-register assignment, but hoist the slot
address into the condition block and omit retail's later address
recomputation. The larger variants exceed the retail window. Every measured
candidate preserves its owner's other function bytes, canonical relocations,
and allocated data. None is an exact recovery or a replacement for the
existing production body.

The full retail body, both decompiler references, actual creator, and card
initialization providers were inspected. The creator allocates `0x19FDC`
bytes, initializes twelve IDs, and registers this function as the update
callback. Its two card arrays have twelve `0xFB0`-byte elements each, starting
at `0x2758` and `0xE398`; the loaded-card count follows at `0x19FD8`.

An additional source proposal using those concrete arrays was prepared, but
its compiler command was blocked before execution with the tool result
“couldn't determine the safety status of the request.” No measurement is
claimed for that proposal. A separate shuffle lifetime proposal also never
executed and contributes no compiler evidence here.

The completed scripts are `build/first-party-resume-final/card_initialization.py`
and `card_address_reuse.py`. Their immutable owner snapshots, candidates,
objects, compiler receipts, complete comparisons, and resolved differences
are under `build/first-party-resume-final/card-initialization/0033e5c0/`.
`summary.json` and `address-summary.json` retain the completed measurements;
`card_record_layout.py` is the unmeasured proposal.
