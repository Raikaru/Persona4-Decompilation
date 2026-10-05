# Attachment callback contract and retained slide/attach residuals

Measured on 2026-10-05 in the finish-first-party worktree. The installed change is
the position callback contract in `src/promoted/code1_001d.c`. Neither
`func_001d53e0` nor `func_0029fbb0` reached an exact C match. Both retain their
assembly fallback and receive no new match credit.

## Installed callback contract

`func_001d53e0` calls the table at `D_00609500` with the attachment work pointer,
battle unit pointer, current 24-byte entry pointer, and a local four-float
position buffer. Retail passes these through `$a0` to `$a3`. The previous C
table declaration took four byte pointers, while six providers declared the
entry pointer as `s32`, the zero-position provider declared its unused first
three arguments as `s32`, and `func_001d4eb0` already declared its output as
`f32 *`. The provider types therefore disagreed with the indirect call type.

The installed function typedef is:

```c
typedef void BtlAttachPositionCallback(u8 *work, u8 *unit,
                                       u8 *entry, f32 *position);
```

Nine declarations using this function type require the native compiler to check
every provider definition against the same interface. The table declaration
uses pointers to that function type. No callback-function casts, wrappers,
extra uses, storage, or compiler settings were added.

The first three byte-pointer types describe the actual object representations;
they are not integer carriers. Entry arithmetic now stays on the entry pointer.
The output is indexed as floats. `func_001d4e90` writes four floating zeros.
The existing `func_001d44a0` helper retains its byte-view output parameter, so its
callers explicitly pass the byte view of the same position buffer.

| Provider | Work argument | Unit argument | Entry argument | Position argument |
| --- | --- | --- | --- | --- |
| `001d4780` | Reads scale, size, bounds, position, rotation. | Reads the scale at `+0x2c`. | Reads descriptor at `+8` and bound at `+0xc`. | Passed to `001d44a0`, which writes the position. |
| `001d48b0` | Reads transform fallback. | Reads flags and model pointer. | Reads descriptor bone at `+0xc`. | Writes three float coordinates. |
| `001d49c0` | Reads transform fallback. | Follows model then `+0x29c`. | Reads descriptor bone at `+0xc`. | Writes three float coordinates. |
| `001d4b00` | Reads transform fallback. | Follows model then `+0x290`. | Reads descriptor bone at `+0xc`. | Writes three float coordinates. |
| `001d4c40` | Unused pointer supplied by dispatch. | Unused pointer supplied by dispatch. | Reads descriptor at `+8`. | Passed to `001d44a0`. |
| `001d4cf0` | Unused pointer supplied by dispatch. | Reads side at `+0xa2`. | Reads descriptor at `+8`. | Passed to `001d44a0`. |
| `001d4dc0` | Unused pointer supplied by dispatch. | Reads side at `+0xa2`. | Reads descriptor at `+8`. | Passed to `001d44a0`. |
| `001d4e90` | Unused pointer supplied by dispatch. | Unused pointer supplied by dispatch. | Unused pointer supplied by dispatch. | Writes four zero words representing `0.0f`. |
| `001d4eb0` | Reads frame and transform; reads/writes cached position at `+0x5c`. | Reads flags and model pointer. | Reads mode, bone, camera offset, start frame. | Reads/writes three float coordinates. |

The fourteen retail slots are:

```text
0:001d4780  1:001d48b0  2:001d4cf0  3:001d4dc0  4:001d4c40
5:null      6:null      7:001d48b0  8:001d49c0  9:001d4b00
a:001d49c0  b:001d4b00  c:001d4e90  d:001d4eb0
```

Active source/header searches found no direct calls to these nine functions.
A separate scan of all retail function windows found no `j` or `jal` transfer
to any provider. The indirect call and every provider's argument use supply the
contract evidence. No outside owner needed editing.

## Native preservation and independent references

Before installation, the full owner was compiled twice with the production
guards and twice with only the attach candidate enabled. Both pairs of complete
ELF object files are byte-identical. This includes all 94 functions, every
symbol, all allocated code/data/literal storage, and every relocation section.
The equality is stronger than a masked function comparison.

The independent check also resolves 434 code references across the 92 existing C
functions and the enabled attach candidate. Calls resolve from source symbols
and the repository symbol maps. Named high/low and global-pointer-relative data
references include their real addends. Literal references compare object bytes
with the referenced retail bytes. The compiler-local 56-byte jump table in
`func_001d5130` is separately reconstructed from all fourteen `R_MIPS_32`
function-symbol-plus-addend references before comparison with retail.

All nine callbacks retain zero differing instruction bytes and zero-only retail
tails. The enabled attach body retains its eight register differences and
twelve-byte zero tail. The actual installed owner verifies as **92 MATCH and
2 ASM**. Source-integrity lint reports zero errors; its 25 advisory sites all
occur in unchanged baseline text. Existing pragmas and unrelated signatures
were left in their assigned owners.

`receipt.json` pins source, compiler, native object, function, retail-window, and
archive hashes. `independent_proof.json` retains each checked reference and all
allocated/relocation-section evidence. `callback_contract.patch` is the exact
installed source change.

## Remaining attach residual

`func_001d53e0` emits **1444 bytes in a 1456-byte window**, with **eight differing
instruction words**. Retail keeps the frame snapshot in `$s3` and the entry
index in `$s5`; the current compiler assigns those two roles in reverse.
The eight differences are at function offsets `0x58`, `0x5c`, `0x78`, `0x1b0`,
`0x1c0`, `0x544`, `0x548`, and `0x554`. The rest of the body and its references
agree with retail.

The frame value is captured before refresh and retained across every loop
callback. The final increment reloads the work object's frame, so replacing it
with the cached snapshot plus one would change the actual lifetime semantics.

The entry-array extent is independently supported by `func_001d3ea0` and
`func_001d3ff0` in `src/Battle/btlFormation.c`: they process two `0x314`-byte
blocks, walk entries in `0x18`-byte steps, and decode packed references using
the low five bits as the entry index. With the block's `0x14`-byte header, this
accounts for 32 entry slots. The constructor `func_001d41b0` allocates the handle
array after a `0x68`-byte work header.

Probes tested genuine snapshot groups, cursor groups, vector workspaces,
branch-local const snapshots, ordinary C register hints, loop activation gates,
creation-state types, equivalent loop forms, and indexed entry/handle access.
Indexed access uses the real array layout and the real loop index, but worsens
the body to 1460–1480 bytes and 89–115 aligned edits. None resolves the current
frame/index partition. No fabricated liveness or explicit register binding was
installed.

## Remaining slide residual

`func_0029fbb0` emits **1824 bytes in a 1856-byte window**, with **14 aligned
edits**. In the final drawing region, six record-member reads are folded to
`lw K(base)`. Retail computes each member address with `addiu` and then loads
from offset zero. This shortens the candidate and also moves its epilogue;
the candidate does **not** have a zero-only retail tail at its current length.
Aligned edits and tail classification must accompany raw positional counts.

The copied table occupies exactly 144 bytes at `D_0063E830`: six records, each
containing two texture IDs and two coordinate pairs. The native values are:

```text
2   8   29 396  25 395
3   9  101 396  97 395
5  11  222 401 214 399
4 178  281 399 254 396
6  12  353 401 346 399
7  13  537 396 532 395
```

The caller `func_002a02f0`, work initialization, and the tween providers in
`src/Yajima/y_timeLimit.c` support the records and their drawing lifetimes. The
stack gap above the 144-byte copy is not evidence for an extra record.

Automatic initialized records, initialized flat words, initialized rows,
coordinate-pair members, pair arrays, and a copied flat 36-word array all retain
the same 14-edit floor. Thus the explicit two-word copy loop does not explain
the remaining field-address instructions. Record/pair snapshots change code
and register allocation substantially without reaching a match.

`slide_flat_words.c` retains the measured flat-array experiment. Its destination
copy stays within a single `s32[36]` object, eliminating the need to walk across
record subobjects through an `s32 *`; it still does not match and was not
installed. The production slide owner is unchanged.

## Replay

From the source revision pinned by the receipt, with the native compiler and
retail executable configured through the normal local verifier settings:

```text
build/venv/Scripts/python.exe docs/probe_archive/SlideAttach_worker20_20261005/replay.py
```

The replay reverses the retained patch in memory, checks its context, and builds
the before/after owner in both guard modes in a unique scratch directory. It
checks complete object hashes against the archived independently inspected
objects and remeasures both residuals. It does not edit production source or
the verifier configuration.

`variant_receipt.json` distinguishes compiled unmatched candidates, rejected
probe-generator cases, and any unsupported pragma spelling. Raw byte/word
counts mask relocation fields and count emitted object bytes; they must not be
used as a substitute for the aligned residual and missing-tail proof.
