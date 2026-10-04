# Battle opening positions: 001b2380

## Accepted source

The production implementation in `src/promoted/code1_001b.c` recovers the
opening rotation, party placement, packet dependencies, group bonuses and
transition to state 6. The unchanged caller/provider interfaces and complete
owning translation unit are part of the match.

The accepted scoped source (the measurement comment through `#pragma pop`,
excluding only the inserted address marker) has SHA-256
`99515c370301e478549c98abd9ed802a3c7fccf651e33ec5a25601ab9226770a`.
The production whole-owner object is byte-identical to the independently
reviewed candidate, SHA-256
`5013bea0b58cf5ff36a636126c333ed8ef9263667132e0ce37b7101a5af22af2`.

- 4,156 executable bytes match, including the return's real delay-slot nop
- The retail window is 4,160 bytes; only the final word at 001b33bc is alignment
- All 122 relocations resolve at the original instruction offsets
- All 122 other owner functions, bindings and allocated data preserve
- Verifier-local literal renumbering is resolved explicitly: 001ba0e0's eight
  references to `@1604` become `@1870` at the same address 0x7612e4;
  001be990's two references to `@2583` become `@2849` at 0x761220

`nodeOrPacket` is a real work pointer whose completed rotation-list phase is
reassigned before every later actor/packet use. The party placement and both
bonus scans initialize their own `unit` cursor from the current root. The
mode-2 animation packet remains live until its UID is copied into the separate
move packet. No local address escapes and no pointed-to storage is merged.
The list constructor 0019d210 allocates and clears the complete 0xa70-byte unit,
stores the old root through the pointer field at +0xa6c, and publishes the new
root. These are pointer values, rather than artificial integer transport.

The scoped `opt_lifetimes on` is a real compiler input. With precisely these
used value lifetimes it produces the complete match; the same final source
without it differs in 17 words. Declaration movement changes no evaluation
order. The setting is bounded by push/pop and verified not to affect siblings.
The earlier 57-word source's scoped-on negative was a different lifetime graph;
it remains a valid negative for that source, not a universal compiler rule.

## Retained-height caller domain

The missing explicit Y seed is supported separately by the actual resource
and caller-history proof. It is not inferred from a match or manufactured by
the fixture. The applicable normal-program domain requires authenticated,
unchanged US resources, in-bounds inputs, distinct live allocator objects and
valid ordinary task/list/packet lifetimes.

The authenticated complete files are:

- UNIT.TBL: 39,152 bytes, SHA-256
  `88864c47c3c3cf9a7b15bf633a6b62a62fa678069d599d0cf56a673b6325d41c`
- ENCOUNT.TBL: 63,744 bytes, SHA-256
  `da1cd20cb00f38222decd4a89f63d0798283cedf050673e1ba16f9e1d7682eb3`

The independent census covers all 23,600 selector draws across 270 referenced
weighted-table/alternate/category cases. All 453 distinct selected encounters
are populated, and fallback encounter 1 is populated. All nonzero enemy IDs
are in bounds and have positive initial HP. Every selected encounter and the
fallback have boss flag 0x20 clear. No licensed rows or payloads are included
here.

The source/history chain establishes the following producer before use:

1. Normal field selection (00164570/00161630) and fallback construct fresh
   distinct groups. Queue construction (00172e00) chooses distinct live actors;
   equal encounter IDs do not imply shared group allocations
2. The shallow battle descriptor preserves those group pointers. Instantiation
   and mutation use only the selected current group. Unselected future groups
   remain fresh, and postbattle field cleanup destroys queued actors rather
   than leaving damaged groups available for requeue
3. The special continuation flag is set by 001b3a00 only when a later queue
   slot exists. The generic flags-packet callers supply 0x80, not that bit
4. State 5 entry 001b1d70 instantiates the next live enemy row before update
   001b2380. Normal constructors do not remove this row; boss-only mutation is
   excluded by the resource flags. Order dispatch remains disabled during the
   opening wait. Remaining transition packets refer to prior valid units or
   presentation state, not future groups or newly created enemy units
5. The target waits for pending packets, then its enemy prepass stores Y from
   each enemy's position. Thus the special dead-party branch reuses initialized
   Y. The relevant setter reads all three components

Script 00174680 and direct creator 001932f0 initialize single-wave descriptors.
They can select other or empty encounter rows, but cannot supply a later
special continuation. Their normal dead-unit branch never reads this position;
normal live units receive a complete formation vector.

The historical synthetic special + empty enemy row + dead first party node is
outside that caller contract. The old seeded checkpoint preserved its explicit
zero-Y behavior. The ordinary fixture retains the constructed witness and
rejects it with a precondition check before invoking the seed-free function;
a broken-checker control must fail. Valid carried-enemy-height, normal empty-row
and single-wave cases remain positive tests. This is not a claim of totality
for fabricated battle work, malformed IDs, corrupted memory or modified assets.

## Coherent prerequisite contracts

The sound factories 001f82b0 and 001f8330 return their actual allocated
`BtlPacket *` and take the actual opaque `BtlUnit *`. Each four-byte work payload
stores that pointer; its callback reads the same pointer type. The four real
retail callers at 001a7f64, 001a847c, 001b2618 and 001b269c consume the returned
packet. All provider/caller definitions and declarations agree. Complete
provider instructions, references, siblings and both guarded caller objects
were preserved by the contract correction.

Equipment query 00232950 counts the two records and returns a complete signed
word in [0, 2], with explicit halfword narrowing after each increment. Its
shared declaration is used by the provider and callers; numerical callers keep
their explicit narrowing. Its scoped propagation setting preserves the retail
increments. The provider and both caller owners retain their production bytes.

The protected animation getter/delay packet APIs remain unchanged. The
experimental wider delay formal and guarded 001a7720 arithmetic repair are
unadopted. This integration makes no broader correctness claim for that legacy
guarded function.

## Scoped integration gates

The actual production integration was measured on public base
`fa980eedbd5732a5f986d27166c525503b0f94dc`:

- Eight-owner verifier: 728 MATCH, 9 ASM, no failing rows
- Actual production target: MATCH, 4,156 / 4,160 bytes, zero normalized differences
- Exact reference/whole-owner audit: zero fully resolved differences, 122 refs,
  122 siblings and allocated data preserved
- Focused native suite: six tests, no skips; 30 target and 12 provider negative
  executions rejected at O0/O2
- Actual guarded 001a7720 lift: whole object identical to accepted packet baseline
- Five changed C owners: lint has zero errors and 116 existing/reviewed warnings
- All pragma spellings recognized; `git diff --check` clean

The ordinary source-bound tests run from the current checkout; they do not read
unpublished Git objects, private proof captures, licensed tables or executables.
They use `tests/native32_support.py` and the configured 32-bit native runner.
The target extractor includes its full scoped pragmas. Fifteen target mutation
kinds cover both optimization levels, including wrong packet phase, missing
bonus-cursor reset, broken caller precondition, full-width UIDs, vectors and
all dispatch boundaries. Separate tests execute the actual sound factory/
callback definitions and equipment provider with their original controls.

Reproduce the focused checks with the configured toolchain and retail ELF:

```sh
python -m unittest discover -s tests -p test_battle_position_controller.py -v
python tools/verify.py src/Battle/btlSound.c src/Main/Battle/Data/datCalc.c \
  src/promoted/code1_001a.c src/promoted/code1_001b.c src/promoted/code1_001e.c \
  src/Battle/btlMain.c src/promoted/code1_0019.c src/promoted/code1_0020.c
python tools/decomp_lint.py src/Battle/btlSound.c src/Main/Battle/Data/datCalc.c \
  src/promoted/code1_001a.c src/promoted/code1_001b.c src/promoted/code1_001e.c
python tools/pragma_audit.py
git diff --check
```

The proof dependencies are identified by SHA-256, independently of the native
fixture. Resource replay requires the two authorized complete assets listed
above; these metadata identities do not grant access to them:

- `resource-census.json`:
  `02c632e7977b95760174fef09144dfde8000972b1ecb257f4fd8ddfd6802b38d`
- Queue-history `evidence.json`:
  `b24bb2ebfa4dd2c2b2f708d5608031b6daf8f7d643f0016046d071fdff7af08d`
- Independent retained-height review:
  `50c617b088210fd2b321ec62f69fe0abca4fa64b7de30fa9b55cab0e363509b6`
- Independent sound-packet contract review:
  `b2662808f71e5ca16464bda7774a840f05580603ac1257b87eac1f6ff186b033`
- Independent exact lifetime/native review:
  `2b1916d7cae970629d806f889e7cb5a98fa73fa3655222e143a2e00bbff5a2c8`

The publication successor must still run the full verifier, strict ordinary suite and cold retail link/hash
checks and confirm this owner remains C-linked. Scoped evidence alone is not
those full gates, nor a gameplay test.
