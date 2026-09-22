# Current motion and color integration proposal

This proposal is based on current `5a1bcf7e889d9b1fb1560201d686669739014501`,
which descends from upstream `5076837`. It combines the complete audited motion
revision 2 and its color increment. All 26 current production owners still have
their original sealed input bytes, and both proposed shared headers are absent.
There are no textual merge conflicts. The complete current proposal and receipts
are in `build/complete-20260921/event`.

The old seals and all independent review evidence remain unchanged:

- `build/finish-current-20260921/motion/sealed-motion-exact-v2`
- `build/finish-current-20260921/motion/sealed-color-exact`
- `build/finish-current-20260921/event/motion-color-review`

## Current evidence and integration scope

The candidate adds two native recoveries in `src/promoted/code1_0019.c`:

| Function | Executable bytes / retail window | Resolved relocations | Zero tail |
| --- | ---: | ---: | ---: |
| `func_00198920` | 1196 / 1200 | 9 | 4 bytes |
| `func_0019b730` | 1164 / 1168 | 3 | 4 bytes |

`prove_current.py` authenticates the current source, transitive headers, fallback
inputs, compiler executable, logical-owner flags and retail identity against
the completed compiler receipts. It resolves every instruction and allocated
data relocation of the 26 completed objects with current symbol bindings and
compares them with validated retail. All 1,580 function windows and all 47
allocated data sections are exact. Twenty-five complete objects are unchanged;
the target owner preserves all 149 non-target functions, their relocation
records, and every allocated data section.

This is a fresh inspection of completed objects, not a new target compiler run
or a new whole-image build. No completed compiler job was rerun to retrieve its
output. The existing 77 checkpoint recoveries are accounted for individually in
`preserved-77.json`: affected owners are rechecked exactly and other owners are
outside this proposal. Unrelated working-tree edits are not included.

The complete source graph is required. Integrate `candidate.patch` as a unit,
including `btl_motion_internal.h`, `model_motion_internal.h`, every caller change,
and both real model-provider definitions. Do not install only the two function
bodies or replace current files from whole-owner snapshots without checking the
before hashes. `current-caller-graph.json` scans active and guarded source and
finds no additional owner outside the 26-owner migration. Prime owns the final
official verifier, whole-image build, campaign accounting and integration.

## Motion contracts and guarded callers

The battle motion contract is
`void (u8 *, s16 motion, u16 frame, f32 rate, u16 option)`. The rate occupies the
independent FPR argument register file. The model dispatcher uses
`s32 (u8 *, u32 layer, s16 animation, u16 blendTicks, s32 flags)`. Signed animation
and unsigned frame conversions agree with the actual `004740c0`, `00475350`,
`00479d10` and `0047eb20` consumers. Layer and flag narrowing remains at the
observed uses. The index provider remains `s64 (u8 *, s32)`; callers explicitly
narrow values where the original storage uses a halfword.

The migration changes real definitions and all discovered declarations and
callers together. The callback returns are `u32 (void *)`, as required by packet
update dispatch. Two old uppercase aliases now use the canonical typed model
interface. No incompatible local prototype or function-pointer cast supplies
the matching instructions.

The original 14 guarded-caller audit is reusable because the full proposed
owners, headers and relevant dependency contexts remain identical. Its 28
before/after compiler receipts were authenticated. Nine whole objects and eleven
canonical target bodies were unchanged; three guarded targets have scheduling
or register changes: `00349c50`, `001727f0`, and `00172e00`. All sizes, unrelated
functions and allocated data are preserved. These three targets remain guarded.
Five dormant floors retain their preexisting uninitialized-local warnings;
some floors also retain unresolved helper/data symbols. Neither a new recovery
nor general native link eligibility is claimed for those guarded functions.

Invalid resource pointers or invalid model indices are not made valid by a
narrow declaration. The inherited provider domain remains necessary.

## Color packet and arithmetic domain

The update callback is `u32 (void *)`, agreeing with its real creator
`0019bbe0` and indirect dispatcher `00194670`. The target packet is 20 bytes:
unit pointer at 0, start/target words at 4/8, signed-halfword alpha/RGB durations
at 12/14, mode/flags bytes at 16/17, and signed-halfword counter at 18. The
allocator zeroes the work record; the creator then initializes unit, target,
durations, mode and flags. The first update captures start color before use.

Modes 1 through 4 initialize both durations, start times and completion time.
Mode 1 starts alpha at zero and RGB at alpha duration plus one; mode 2 reverses
that order. Their end time is the sum. Modes 3 and 4 start both at zero and end
at the maximum duration. The promoted signed-halfword arithmetic fits in s32.

Division occurs only when counter is at least start, duration is positive and
counter is less than start plus duration. The factor is finite and in [0,1];
the other path selects one. All high-byte color shifts use unsigned arithmetic,
including alpha shifted by 24. RGB and alpha merges preserve the other channel
group, and start-color flags retain their original precedence.

The independent retail scan found exactly 18 direct creator calls, including
delay slots. Every call uses mode 3 or 4, flags 0 or 1, and durations drawn from
0, 1, 6, 8, 12 and 80. This establishes those direct callers, not arbitrary
future indirect users or malformed packets. Modes outside 1..4 leave timing
locals uninitialized and are outside the supported contract. Starting at zero,
finite normal completion requires end at most 32766: end at least 32767 can
wrap the s16 counter to -32768 before the strict `end < counter` test succeeds.
The target's narrowing behavior reproduces the retail halfword store. No
recorded creator reaches that limit, and no clamp or expiry action is invented.

Publication matches the actual four-byte RGBA-by-value setter at `00194f60`:
write unit+0x30 through +0x33, then OR dirty mask 4 into unit+0x98. The reset
provider is called at the first update, before blending. Older generic packet
init/destructor declarations and legacy pointer aliases remain interface debt;
this proposal does not certify global packet-interface consistency.

## Hardware bridge and fixed-VF limitation

The prior guarded color reconstruction already contained a packed-word/VU
bridge. This replacement fixes its hidden stack writes and volatile C reloads.
Every C memory input and the real four-byte output is named by an `m` operand;
GPR scratch and hardware clobbers are declared. C owns the snapshots, inverse
factor, masks, timing, branches, packet state and publication. No new assembly
steering, padding, invented side effects or ordinary control flow is added.

The unpacking initializes all four RGBA lanes in VF10 and VF11. Unknown upper
GPR bits do not reach those lanes. Scalar transfers initialize VF2.x, and every
consumer broadcasts x; VF2.y/z/w are not required inputs. Q, ACC and VF0 are not
read. The final pack writes the declared four-byte object. The literal scale is
retail binary32 1/255 followed by actual 255.0f scaling, conversion and packing.

**The split volatile statements carry implicit fixed-VF dependencies.** VF11
survives the second statement, VF10/VF11 feed the third, and VF10 feeds the
fourth. These are not explicit C vector operands. The audited b210 object has
no intervening call or VF overwrite and every consumed lane is initialized.
Current source, headers, compiler and flags are authenticated to that artifact.
This evidence is not a generic compiler scheduling guarantee and does not
license inserting vector code between those blocks. Preserve this qualification
when reusing the source with another compiler or configuration.

## Reused behavioral validation

The sealed independent host test passed 1,795,171 callback checks under GCC's
undefined-behavior sanitizer: 452,608 recorded-creator timeline steps, 293,984
mode/duration/counter boundary steps, 1,048,576 unsigned-packing cases, and three
explicit counter-completion/wrap cases. It copied the callback/control code and
replaced only the hardware helper with recording sentinels. It checked masks,
call ordering and arguments, factor domain, flag precedence, publication extent,
dirty bits, unchanged packet fields, counter updates and completion.

That test did not execute VU instructions, the real allocator, the game, or the
PS2 ABI. Its 64-bit host pointer layout was separate from a 20-byte target wire
layout assertion. Its source and result hashes are authenticated here; the
completed test was not repeated without a source change.
