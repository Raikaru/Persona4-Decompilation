# Independent SDK contract review

The independent review agrees with `accepted: false` in the proposal manifest.
The initializer and creator instruction proofs are valid, but the proposed SDK
types are not yet consistent with the actual registrations and callbacks.
This review ran no compiler and made no production changes.

The complete report and read-only audit program are retained at
`build/first-party-0360227/sdk-inventory-review.md` and
`build/first-party-0360227/sdk_inventory_review.py`. The report contains exact
source references, all declarations, callback roles, direct-call addresses and
input hashes. These findings supplement the earlier address-only inventory in
this archive; its original JSON and hashes remain unchanged.

## Expanded inventory

The C scan and an independent scan of the validated retail ELF agree on all
**241 direct registration calls in 213 functions**: 58 calls to `00451de0` and
183 to `00451fc0`. All per-function call counts agree. No direct tail jumps to
either registration entry were found. The C calls span 103 source owners.

The review finds 116 SDK declaration entries in 100 source/header owners and
257 encountered callback declarations. Resolving named and indirect callbacks
expands the inventory to **400 callback roles with actual definitions**.
Of these, 268 have the proposed `s32(u8 *)` update or `void(u8 *)` cleanup type;
**132 roles across 58 owners do not**. These counts include guarded C and are
not counts of active matching objects.

The apparently missing `00192790` is already implemented under its recovered
name: `void *btlUpdateDraw3DFrontTask(void *task)` in `src/Battle/battle.c`.
Its registration in `code1_0019.c` still declares the generic spelling as
`void func_00192790(void)` and casts it to a different callback type. The real
definition, its declaration and the registration must be reconciled together.

Two callback aliases in `cldScheduler.c` resolve to
`s32 func_00260020(void *)` and `void func_00260440(void)`. The actual retail
table at `D_005F15B0` contains `{0, 00166c80, 00166e30, 00167120}`. All three
non-null providers already define `s32(u8 *)`; their table declaration and
registration casts still need correction. Named `scrDestroyTask` registrations
are also included. Null entries are not treated as functions.

## Defects still inside the staged owner set

The staged `y_fclCombineDraw.c`, `y_fclShopDraw.c`, and `y_CmbCardEff.c` do not
include the proposed SDK header and retain four incompatible registration
declarations. Their successful compilations therefore did not check those
declarations against the staged SDK definitions.

Five initially registered callbacks within the staged owners also retain
incompatible definitions: `00349340(void)` and `0034b8d0(void)` in
`code1_0034.c`; cleanup `002ca770(void *)`, update `002e0100(void *)`, and
cleanup `002e02d0(void *)` in `y_fclShopDraw.c`. The other 127 incompatible
roles are outside these initial staged definitions. Byte-identical objects
do not resolve any of these C function-type discrepancies.

Seven update bodies are currently declared `void` and have no value return:
`00148280`, `0016bdd0`, `00182bc0`, `00183b80`, `00185850`, `0018a200`, and
`00332bb0`. Recover their actual return paths before assigning the common
update type; an invented zero return would not be a contract correction.

## Verified runtime behavior and evidence limits

Retail registration stores the update, cleanup and work values at task offsets
`0x30`, `0x34`, and `0x38`. Dispatch receives the task base, not the work pointer.
An update result of zero preserves the handler; another nonzero word replaces
the stored handler. Minus one is a termination sentinel whose cleanup effect
also depends on task state. Thus the update return carries a signed word or
handler address, not merely a boolean result.

The reviewer independently compared the retained initializer and all five
creator resolved binaries to retail, including zero tails, and checked all ten
source/object pairs against their receipts. These checks validate those saved
objects; they do not complete the API migration. The original compile receipt
for one include path hashes the old live header even though the C included the
scratch SDK header. The full review separately identifies and hashes the actual
scratch header. Future compilation must record the headers really consumed.
The reviewed scratch SDK header SHA-256 is
`005f77fa470873ecc19367412474752b64d0f91917b6510440e055c3bd5eafc0`;
the portable LF header's separately recorded hash belongs to the archive replay.

The existing bounds constructor `002b29e0` writes only the trailing dimensions
before copying its full sixteen-byte object. The first eight bytes are an
uninitialized two-float prefix. The examined draw consumers use initialized
integer dimensions, but that does not approve reading the unwritten prefix as
typed float values. An opaque representation and complete consumer audit remain
necessary; initializing fabricated coordinates would change the recovered
operation.

This proposal is useful work to continue, not an additional accepted C match.
