# YDraw update: faithful guarded repair

`func_002b6ec0`, owned by `src/promoted/y_draw.c`, remains behind its strict
`NON_MATCHING` guard. This change earns **no C match credit**. Native verification
of the actual owner reports **57 MATCH and 1 ASM**. The exposed repaired body is
1512 bytes in a 1536-byte retail window and differs at 368 fully resolved words.
The complete default owner preserves all 58 functions; enabling the C guard
preserves the other 57 functions, their references, and all allocated storage.
Neither object owns allocated non-code storage.

## Recovered behavior

Retail's inactive test at `002b6f40` branches to the index increment at
`002b7468`. It bypasses the append/count region beginning at `002b742c`.
The previous guard appended every one of the 780 slots. The repaired guard
appends only slots that were active on loop entry. A slot deactivated by its
animation or culling step still belongs in that iteration's active list.

The table used as the animation-copy destination is sampled after
`func_002b89a0`. The callback allocator `func_00460990` runs before the table used
to select its ordering queue is sampled. The table is sampled again after
`func_00460ac0` inserts the callback. The draw entry then survives the pure color
packer `func_002b2a30`; the old guard refreshed it at the wrong boundary.
The repaired source follows these boundaries and reloads the signed count
after storing the active index.

All three drawing arms use the retail `<=` rejection comparisons. The normal
arm's old positive comparison was replaced by the negated rejection predicate.
The behavioral interpreter exercises finite inputs and signed zero; it does
not claim to model EE exceptional floating-point values or exception flags.

The actual `0025ecd0` provider and the queue providers were read before editing
the caller. The existing declaration is correct: six float channels carry
`x, y, depth, angle, scaleX, scaleY`; eight integer/pointer channels carry
`color, opacity, frame, resource, mode, originX, originY, queue`. The opacity
channel is `u8`, and both origins are `s16`. The redundant local declaration was
removed; the owner-wide declaration and provider contract were preserved.

## Layout evidence

The neighboring constructor allocates `0x31220` bytes. The resource pointer is
at offset zero, followed at offset four by 780 records of `0x100` bytes. The
signed count is at `0x30c04`, and the signed active indices begin at `0x30c06`.
`typed-context.c` retains the typed reconstruction, including native-compiler
size assertions for the record and context. Unknown spans represent observed
storage whose fields are not recovered; they do not allocate additional data.

The typed candidate passed the same 92 behavioral cases and preserved all 57
siblings. Its native body was 1452 bytes and remained nonmatching. The installed
repair keeps the smaller source diff and the existing scoped
`opt_common_subs off` setting. No ABI or shared-header changes were made.

## Proof and replay

`receipt.json` records the frozen source, compiler, objects, input hashes,
function hashes, and compact behavioral results. `guard.c` is the installed C
body. `proof_core.py` resolves code and data references independently of the
compiler's relocation-masked score. Unsupported or unplaced references fail.
The production body and all siblings require exact resolved bytes and only
zero retail tails.

`behavior.py` interprets the actual native and retail instructions. The 92
cases cover inactive and sparse lists, all three draw arms, both special-branch
scans, transition bits 1 through 13, signed transition flags, animation/culling
deactivation, and table replacement at animation, culling, allocation, queue
insertion and drawing boundaries. Every one of the 381 non-padding retail
instructions executes. Provider calls have explicit hooks and poison volatile
integer and float registers. Cases use retail's stored `0.1f` cutoff, including
the cutoff and adjacent representable floats for both scales in all three draw
arms. The comparison includes all call channels and all
observable memory; saved registers, return value and stack restoration are
checked. Hooks isolate caller behavior and do not prove renderer integration.

Run with the configured Python and compiler from any directory:

```text
python docs/probe_archive/YDraw_update_002b6ec0_20261005/replay.py --output build/ydraw-replay-new
```

The output directory must be new. The script verifies the frozen input hashes,
compiles the actual owner normally and with `NON_MATCHING` enabled, resolves
every reference, and runs the behavioral comparison. It never changes source,
configuration, caches or shared build reports. With `--retained`, existing
object hashes and proofs can be checked without repeating compilation.

## Prior and new measurements

The retained October 5 starting guard measured 1500 bytes and 363 masked word
differences. The earlier September 24 c60 review measured 1500 bytes, 376
resolved word differences and 251 alignment edits. These are dated prior
results, not new runs. Closed September table-hoisting/CSE probes were not
repeated.

This investigation compiled five new semantic/source shapes: repaired raw
control flow (1576 bytes), explicit retail branch order (1428), actual typed
context (1452), explicit stored values (1552), and the installed minimal repair
(1512). All preserved the 57 exact siblings. Their residual scores are
diagnostic and do not authorize a match claim. The remaining differences are
instruction selection, register allocation, address formation and signed
loop-state handling. The fallback remains authoritative.
