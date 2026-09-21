# Motion 00198920: coherent API frontier, worker-4, 2026-09-21

**BLOCKED — do not integrate this package as an exact recovery.**

The canonical native target emits 1196 bytes of its 1200-byte retail window. All
nine target relocations resolve exactly and the omitted four-byte tail is zero.
Its owner retains three instruction differences in two existing callers. The
all-caller API correction adds one battle-effect caller with two differing words.
No production source, header, configuration, git state or old snapshot was edited.

## Review package

`build/next-wave-20260921/motion/sealed-contract-frontier/` contains a minimal
`candidate.patch`, complete proposed owners and the new shared header, a
`before-inputs.json` manifest, proposed hashes, evidence hashes and machine-readable
summary. The before manifest includes every frozen input and explicitly records
that `include/btl_motion_internal.h` does not exist in production. Apply only a
reviewed delta against matching before hashes; never restore these whole-owner
snapshots over unrelated changes.

## Native contract

The header declares motion `(u8 *, s16, s32, f32, u16)`, default application
`(u8 *, s32)`, actual index provider `s64 (u8 *, s32)`, and all three packet update
callbacks as `u32 (void *)`. Integer registers are unit/motion/frame/option in
a0/a1/a2/a3 and the rate is in f12. The source order remains rate before option.
No incompatible function override or function-pointer cast is introduced.

The script caller 001eaec0 uses explicit `(u16)` conversion of its 64-bit script
values before full-width frame passing. Keeping only a 64-bit AND expression
produced two redundant 32-bit sign-extension instructions; the explicit storage
boundary restores its whole object exactly. Five other external owners also
remain byte-for-byte identical, including all integrated 00205170 and 00206dd0 work.

## Complete unmasked result

Each owner was compiled with its logical owner path and configured MWCC b210
profile, frozen source/header inputs and per-run compiler/profile/header hashes.
The old successful code1_0019 baseline compile was reused after hash checks.
Every one of 724 production functions resolves exactly to retail. The candidate
has 721 exact function windows (including the native target) and three residual
callers. All 18 allocated data sections resolve exactly. There are no masked
relocation, padding, function-tail or data comparisons.

| Owner | Functions | Allocated data sections | Candidate difference |
| --- | ---: | ---: | --- |
| `src/promoted/code1_0019.c` | 151 | 4 | func_00198380: 1 words; func_0019a030: 2 words |
| `src/Battle/btlUnit.c` | 41 | 0 | Whole object unchanged |
| `src/Battle/btlUnit_functions.c` | 19 | 0 | Whole object unchanged |
| `src/promoted/btlEPL.c` | 26 | 1 | func_001fff40: 2 words |
| `src/promoted/code1_001b.c` | 123 | 1 | Whole object unchanged |
| `src/promoted/code1_001e.c` | 120 | 0 | Whole object unchanged |
| `src/promoted/code1_0020.c` | 146 | 0 | Whole object unchanged |
| `src/promoted/code1_0022.c` | 98 | 12 | Whole object unchanged |

The three residuals are:

- 00198380 +0x28c: retail `daddiu a2,zero,6`, candidate `addiu a2,zero,6`.
- 0019a030 +0x44/+0x48: retail mode `lb` precedes packet-frame `lhu`; candidate reverses them.
- 001fff40 +0xc4/+0xc8: retail unit `move` precedes frame `lhu`; candidate reverses them.

All other instructions, relocation destinations and omitted tails are accounted
for in `api-contract/<owner>/unmasked/{production,candidate,summary}.json`. Renamed
native functions resolve from their source markers. R_MIPS_LITERAL uses its full
signed GP displacement, with its original class retained in the proof receipt.
The code1_0019 switch tables at 0x746f10/52B, 0x746f50/24B, 0x746f70/28B and
0x746f90/28B are exact after resolving every local label to its actual code address.

## Storage and lifetime findings

The embedded defaults occupy unit+0x9ec: s16 motion, s16 blend frame, f32 rate,
s8 mode; the next table pointer is at 0x9f8. Holding an interior defaults pointer
across the provider call adds unwanted address instructions. The smaller saved
baseline avoids that extra lifetime. The 8-byte default packet stores its frame
as a halfword at +4; its producer's signed storage and consumer's unsigned view
must not be confused with the native full-width frame parameter.

93 existing objects were audited before new experiments. No saved full-width
frame variant preserves both existing callers. New embedded-layout, member
reference, real request output, selection output, signed-storage and aggregate
copy families were measured in isolated whole-owner snapshots. Halfword frame
accumulators produce the desired constant but retain a common-join mask; copied
aggregates add stack traffic. These rejected candidates are preserved alongside
their exact receipts. No generic register sweep, fake side effect, volatile
forcing or ordinary assembly was used for this motion work.

The frontier is concrete and reviewable, but the five residual instruction words
remain a release blocker. Worker-4 next selected the live guarded 0019b730 color
packet after confirming there is no other unmatched ordinary motion routine in
this owner; its existing literal stack accesses require a real output contract.
