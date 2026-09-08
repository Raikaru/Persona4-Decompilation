/*
Exact ordinary-C recovery, integrated in src/promoted/code1_0022.c.
object_size=2312; window=2320; normalized_diff=0; fully_resolved_code_relocations=75; resolved_differing_bytes=0; zero_tail_bytes=8.
All nine R_MIPS_32 entries at retail 0x007478F0 are exact:
0022A3FC 0022A3FC 0022A374 0022A38C 0022A3A4 0022A3FC 0022A3BC 0022A3EC 0022A3D4.
Supersedes the 2308-byte candidate with four missing executable bytes and 1481 resolved differing bytes.
Separate phase-local packet roles and an iteration-local target pointer recover the retail register allocation. The two complete 32-byte configuration objects have real word/halfword/byte views; no padding or fabricated initialization.
Verification is actual owner compilation and full code/table relocation resolution, not game execution.

TARGET AND ABI
func_00229da0: retail [0x00229DA0,0x0022A6B0), 0x910 bytes, 607-line ASM file read completely. Entry a0 is a 32-bit action-record address. No a1/a2/a3/f12 or incoming saved-register values are consumed. Void result: final func_001d3e00 result is not turned into a deliberate return value. Frame is 0xF0. The candidate uses the existing owner's u8 * action representation, not camera+0x24.

REAL CALLER REACHABILITY
asm/nonmatchings/code1_0022/func_0022dc70.s:
- 0022DC84 saves its a0 action directly in s2; 0022DCA0 reads its unit at action+0x30.
- 0022E104..0022E140 select action+0x6C == 2 and action+0x6E == 0x17B or 0x184.
- 0022E150..0022E164 pass initialize=00229DA0, update=0022A6B0, context=s2 to func_001fae60. No +0x24 adjustment.
- Current src/promoted/code1_0022.c func_0022dc70 shows this under case 0x108, then sets action+0x6C=8 and btlActionSetState(action,25).
asm/nonmatchings/code1_001f/func_001fae60.s 001FAE60..001FAE74 stores the three values at battle-root+0xB40,+0xB44,+0xB48.
asm/nonmatchings/code1_001f/func_001fac80.s 001FAC90..001FACCC, when root+0xC has 0x200000 and func_0022bd00()==0, loads the initializer from +0xB40 and invokes it with a0 loaded directly from +0xB48. Therefore the actual reachable initializer gets the action, and no undocumented argument is justified.

ACTION AND ROOT FIELDS ACTUALLY USED
- action+0x00: u64 identity, copied afresh at every retail packet identity write; never truncated to a word.
- action+0x30: unit pointer; action+0x38+4*i: target action pointers; action+0x6A: u16 target count; action+0x6E: u16 effect/action ID.
- target+0x1A: u16 flags (require mask 0x1; clear mask 0x8); target+0x30: unit.
- unit+0xA2: u8 genus; unit+0xA4: u16 character ID; unit+0xA64: data-unit pointer; unit+0xA68: linked-list next.
- root+0xC flags set 0x80000 initially and clear 0x400000 later; root+0x18 is entirely cleared as a halfword; root+0x17C is the roster head.
- Root symbol iGpffffb3ac is the pointer at 0x76449C, using GP=0x7690F0 and displacement -0x4C54.
- src/Battle/btlAction.c BtlAction confirms uid as u64 at +0 and unit at +0x30. No fabricated complete action struct is introduced.

PACKET ALLOCATION, RETURNS, AND CONSUMED OUTPUTS
src/promoted/code1_0019.c func_00194470 allocates workSize+0x90, zeroes that full extent, sets workData at packet+0x78 to packet+0x90 for nonzero workSize, initializes condition modes at +0,+0x10,+0x20,+0x30, and returns the pointer. Thus every constructor below provides the entire packet header used here, including condition payloads through +0x1F, timing fields +0x48/+0x4A, generated packet identity +0x58..+0x5F, and action identity +0x60..+0x67.
- src/Battle/btlEffect.c func_00202010(u32 unit,u16 effect): packet kind 0x504, 0xC-byte work, writes unit/effect/zero and returns BtlPacket *.
- src/Battle/btlCamera.c btlCameraCreateSetStatePacket (001BC920): kind 0x200, 8-byte work, writes action pointer and u16 state, returns packet. Owner's existing func_001bc920 address-name declaration returns u8 *; reused.
- src/Battle/btlUnit.c btlUnitCreateAnimPacket (00199EE0): normal IDs 0xF/0xB here use kind 0x100 and write unit, animation ID, blend count, speed, mode, returning packet. Existing owner's func_00199ee0 is reused: (unit,id,blend,mode,speed) gives a0..a3 and f12. Provider's source order (unit,id,blend,speed,mode) has the same separate float/integer EE register mapping.
- src/Battle/btlUnit_functions.c btlUnitCreateRotateTowardUnitPacket (00198300): kind 0x10E; writes both unit pointers and flags; returns packet.
- src/Battle/btlUnit.c btlUnitCreateRotatePacket (00197F50): kind 0x10D; reads exactly the supplied 12-byte RwV3d, or default vector if null; returns packet. All target pointers here are nonnull D_006354C0.
- src/Battle/btlFormation.c func_001d6240: kind 0x301, work 0x20, writes formation/unit/target/mode/flags and returns BtlPacket *. All uses have arg4=0x200. The initial mode=0 packet is assigned before either loop, so formationPacket is defined even for zero eligible targets.
- src/Battle/btlSound.c func_001f7c20(u16,u16,u16): kind 0x902, work 6; writes channel/cue/variant; returns packet.
- src/Battle/btlTarget.c func_001f36e0: kind 0x700, work 0x2C; writes the two action pointers, copies exactly 0x20 bytes from arg2 to work+8, writes two s16 values at work+0x28/+0x2A, returns packet. Retail asm/nonmatchings/btlTarget/func_001f36e0.s 001F3764 supplies length 0x20 and 001F3778 restores the saved packet to v0.
- src/Battle/btlUnit.c btlUnitCreateMovePacket (001973F0): kind 0x10A; writes unit/speed/flags; copies exactly 12 bytes from nonnull targetPos, or D_00881430 when null; returns packet. Final return motions intentionally pass NULL, not an unwritten output.
- func_001d3700 now explicitly returns its BtlPacket * in src/Battle/btlFormation.c. The corrected provider is exact: 88/96 bytes, three resolved relocations, zero differing bytes, eight zero tail bytes. All affected owner declarations were migrated; this source consumes the real returned packet.

PUBLISHED PACKET IDENTITIES
src/promoted/code1_0019.c func_00194590 at 00194590 writes func_00192560()'s full s64 result to packet+0x58 before initialization/list insertion, then returns that identity. Every read of source+0x58 in the candidate happens after func_00194590(source,queue), and is a u64 read. Every copied dependency to destination+8 or +0x18 is a u64 write. Source packet+0x58 is not a constructor work output and is never read before publication.
Initial animation is published before the finish packet depends on it. Initial formation is published before any possible finish dependency; each subsequent formation replaces it only after publication. Optional status animation is published before its status packet depends on it. Per-target outward move is published before both rotation and target effect depend on it. Finish camera is published before cleanup packets and return moves depend on it; return moves are published before return rotations depend on them.

LOCAL OUTPUT EXTENTS AND DEFINED STATE
src/promoted/code1_001f.c func_001f0a10 calls memset(arg,0,0x20). There are TWO independent 0x20-byte objects: retail SP+0xB0..0xCF (statusParams) and SP+0xD0..0xEF (targetParams). Both are initialized exactly once before the loop, through the actual provider. Candidate unions expose exactly these bytes as u32/u16/u8 views; they have no guessed padding or dummy initialization.
- targetParams+8 receives 0x100 (SP+0xD8).
- statusParams+0xC receives 0x100001 (SP+0xBC).
- targetParams+0x1E (SP+0xEE) is already zero-initialized before every initial read-modify-write; its 0x80 bit is set or cleared for each eligible target.
- func_001f36e0 consumes the complete initialized 32 bytes, including the final halfword. Ghidra's split auStack_20[8]/uStack_18/uStack_2 view is not an unwritten-stack blocker.
No incoming saved-register state is consumed. delay and both loop counters are explicitly initialized by retail. Optional animationFrames is assigned on both branches (signed low16 duration or zero). formationPacket is initialized outside the first loop. The second traversal's result is unused but the retail traversal is retained in C rather than deleted manually.

SCALAR AND VECTOR PROVIDERS
- src/Battle/btlFormation.c func_001d3d50(0) allocates 0x638 state and initializes flags/counter/value; func_001d3ea0 copies 0x630 bytes of the formation data and resolves referenced entries, setting the loaded flag; func_001d3e00 releases the creator reference after all sequencing.
- src/promoted/code1_0022.c func_0022ced0(0xC) performs the existing data-resource lookup via func_00455ea0(root+0xB90,12,0); result is a source address passed to func_001d3ea0, not a stack output.
- src/datCalc/datCalc_grouped.c datCalcIsDead (002428F0) reads data-unit+0xC bit0x80000 or data-unit+8 HP plus signed delta. Both loops pass delta=0. Returns u32 Boolean, no side outputs. Address-name declaration accepts the 32-bit pointer via void *.
- Same file datCalcChkBadStatus (00232710) reads data-unit+0xC & mask. Optional animation/effect path tests mask0x100000.
- src/Main/Battle/Data/datCalc.c func_00243e30(u16 *) returns whether data-unit+0 flags contain0x200; controls targetParams final halfword bit0x80.
- src/btlTarget/btlTarget.c func_001ec6d0(s16*,s16*,f32*) reads input position[0] and position[2], writes exactly two bytes at unit+0x94 and two at unit+0x96. No vector/quaternion output or larger local extent is involved.
- src/promoted/code1_0019.c func_00199500(u8*,s32,f32) returns s16. Full retail ASM read confirms every return either zero or explicitly sign-extended low16; candidate preserves signed frame assignment to +0x48. The provider's COP1 conversion is not duplicated or replaced in this target.
- src/promoted/code1_001e.c func_001ef4a0 returns table byte for (id&0xFFFF)*4, replacing zero with1. Retail masks its result to u16 before 32-bit addu into cumulative delay; candidate uses u32 delay += (u16)result and only narrows at packet+0x48.

RETAIL DATA AND VERIFIED SWITCH TARGETS
Read orig/SLUS_217.82 ELF32 program headers; LOAD segment file offset0x80 maps VA0x100000, so data recovered directly by VA. At 0x7478F0 the nine switch words are:
0:0022A3FC 1:0022A3FC 2:0022A374 3:0022A38C 4:0022A3A4 5:0022A3FC 6:0022A3BC 7:0022A3EC 8:0022A3D4.
Thus cases 2/3/4/6/8/7 call flags0x15CF/0x15D0/0x15D1/0x15D2/0x15D3/0x15D4 respectively. 0/1/5 and all >=9 fall through without a flag call. Particularly 7 and8 are not sequentially mapped.
D_006354C0 first vector: (0,0,1000).
D_006354D0 four observed vectors: (0,0,0),(0,0,-50),(150,0,-50),(-150,0,-50).
D_00635500 four observed vectors: (0,0,0),(-300,0,-400),(300,0,-400),(-450,0,-250).
GP-0x7F64=0x76118C contains float0.699999988079071, existing symbol fGpffff809c. Candidate refers to the symbol rather than inlining a guessed decimal.
The slot-derived vector indexing remains exactly retail. No extra bound guard or invented roster fallback is added.

*/
extern BtlPacket *func_00202010(u32 unit, u16 effect);
extern BtlPacket *func_001f7c20(u16 channel, u16 cue, u16 variant);
extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPosition, f32 speed, u32 flags);
extern s16 func_00199500(u8 *unit, s32 animation, f32 scale);
extern u32 func_002428f0(void *unit, s32 hpDelta);
extern s32 func_00243e30(u16 *unit);
extern s32 func_001ef4a0(s32 action);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern BtlPacket *func_001d3700(u16 group, u16 mask);
// FUN_00229DA0
void func_00229da0(u8 *action)
{
    s32 formation;
    u8 *packet;
    u8 *initialAnimation;
    u8 *formationPacket;
    u8 *sequencePacket;
    u8 *statusAnimation;
    u8 *returnPacket;
    u8 *finishPacket;
    u8 *returnTarget;
    u8 *unit;
    u8 *returnUnit;
    u8 *node;
    u8 *returnNode;
    u32 targetIndex;
    u32 returnIndex;
    u16 slot;
    u32 rosterIndex;
    u32 delay;
    u32 positionOffset;
    s16 animationFrames;
    union {
        u32 words[8];
        u16 halves[16];
        u8 bytes[0x20];
    } targetParams, statusParams;

    formation = func_001d3d50(0);
    func_001d3ea0(formation, (u32)func_0022ced0(0xC));
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;

    packet = (u8 *)func_00202010(*(u32 *)(action + 0x30),
                                *(u16 *)(action + 0x6E));
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 3);

    packet = func_001bc920(action, 0x1A);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    initialAnimation = func_00199ee0(*(u8 **)(action + 0x30), 0xF, 0, 2, 1.0f);
    *(u64 *)(initialAnimation + 0x60) = *(u64 *)action;
    *(u16 *)(initialAnimation + 0x4A) = 0xC8;
    func_00194590(initialAnimation, 0);

    if (*(u16 *)(action + 0x6A) == 1) {
        packet = (u8 *)btlUnitCreateRotateTowardUnitPacket(
            *(BtlUnit **)(action + 0x30),
            *(BtlUnit **)(*(u8 **)(action + 0x38) + 0x30), 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 0);
    } else {
        packet = (u8 *)btlUnitCreateRotatePacket(
            *(BtlUnit **)(action + 0x30), (const RwV3d *)D_006354C0, 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);
    }

    unit = *(u8 **)(action + 0x30);
    formationPacket = (u8 *)func_001d6240((u32)formation, (u32)unit,
                                         (u32)unit, 0, 0x200);
    *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
    func_00194590(formationPacket, 2);

    packet = (u8 *)func_001f7c20(0xC, 5, 0xE);
    *(u16 *)(packet + 0x48) = 0x5A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    func_001f0a10(targetParams.bytes);
    targetParams.words[2] = 0x100;
    func_001f0a10(statusParams.bytes);
    statusParams.words[3] = 0x100001;
    delay = 0;
    targetIndex = 0;
    while ((u16)targetIndex < *(u16 *)(action + 0x6A)) {
        u8 *target = *(u8 **)(action + (u32)(u16)targetIndex * 4 + 0x38);
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0)
            goto next_target;
        if (*(u16 *)(unit + 0xA4) == 1)
            goto next_target;
        if ((*(u16 *)(target + 0x1A) & 1) == 0)
            goto next_target;
        if (func_002428f0(*(u8 **)(unit + 0xA64), 0) != 0)
            goto next_target;

        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0) {
            slot = 0;
        } else {
            rosterIndex = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node)
                    break;
                rosterIndex = (u16)(rosterIndex + 1);
                node = *(u8 **)(node + 0xA68);
            }
            slot = (u16)rosterIndex;
        }

        formationPacket = (u8 *)func_001d6240((u32)formation,
            *(u32 *)(action + 0x30), (u32)unit, 1, 0x200);
        *(u16 *)(formationPacket + 0x48) = (u16)delay;
        *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
        func_00194590(formationPacket, 2);

        packet = (u8 *)func_001f7c20(0xC, 5, 0xE);
        *(u16 *)(packet + 0x48) = 0x6C;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        positionOffset = (u32)slot * 12;
        unit = *(u8 **)(target + 0x30);
        func_001ec6d0((s16 *)(unit + 0x94), (s16 *)(unit + 0x96),
                      (f32 *)(D_00635500 + positionOffset));
        *(u16 *)(target + 0x1A) &= 0xFFF7;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x20;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 8;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x10;

        if (func_00232710(*(u8 **)(*(u8 **)(target + 0x30) + 0xA64),
                          0x100000) != 0) {
            statusAnimation = func_00199ee0(*(u8 **)(target + 0x30),
                                            0xB, 0, 0, 1.0f);
            statusAnimation[0] = 0xB;
            *(u64 *)(statusAnimation + 8) = *(u64 *)(formationPacket + 0x58);
            *(u64 *)(statusAnimation + 0x60) = *(u64 *)action;
            func_00194590(statusAnimation, 0);

            packet = (u8 *)func_001f36e0((s32)(u32)target, (s32)(u32)target,
                                         statusParams.bytes, 1, 1);
            packet[0] = 4;
            *(u64 *)(packet + 8) = *(u64 *)(statusAnimation + 0x58);
            *(u64 *)(packet + 0x60) = *(u64 *)action;
            func_00194590(packet, 1);
            animationFrames = func_00199500(*(u8 **)(target + 0x30), 0xB, 1.0f);
        } else {
            animationFrames = 0;
        }

        sequencePacket = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)(target + 0x30),
            (const RwV3d *)(D_006354D0 + positionOffset), 0.5f, 8);
        sequencePacket[0] = 0xB;
        *(u64 *)(sequencePacket + 8) = *(u64 *)(formationPacket + 0x58);
        *(s16 *)(sequencePacket + 0x48) = animationFrames;
        *(u64 *)(sequencePacket + 0x60) = *(u64 *)action;
        func_00194590(sequencePacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(target + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        if (func_00243e30(*(u16 **)(*(u8 **)(target + 0x30) + 0xA64)) != 0)
            targetParams.halves[15] |= 0x80;
        else
            targetParams.halves[15] &= 0xFF7F;
        packet = (u8 *)func_001f36e0((s32)(u32)target, (s32)(u32)target,
                                     targetParams.bytes, 1, 1);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u16 *)(packet + 0x48) = 8;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        switch (*(u16 *)(*(u8 **)(target + 0x30) + 0xA4)) {
        case 2:
            func_00106390(0x15CF, 1);
            break;
        case 3:
            func_00106390(0x15D0, 1);
            break;
        case 4:
            func_00106390(0x15D1, 1);
            break;
        case 6:
            func_00106390(0x15D2, 1);
            break;
        case 8:
            func_00106390(0x15D3, 1);
            break;
        case 7:
            func_00106390(0x15D4, 1);
            break;
        }
        delay += (u16)func_001ef4a0(0x17B);
next_target:
        targetIndex = (u16)(targetIndex + 1);
    }

    *(u16 *)(iGpffffb3ac + 0x18) = 0;
    *(u32 *)(iGpffffb3ac + 0xC) &= 0xFFBFFFFF;
    finishPacket = func_001bc920(action, 0x2C);
    finishPacket[0] = 4;
    *(u64 *)(finishPacket + 8) = *(u64 *)(initialAnimation + 0x58);
    if (formationPacket != NULL) {
        finishPacket[0x10] = 4;
        *(u64 *)(finishPacket + 0x18) = *(u64 *)(formationPacket + 0x58);
    }
    *(u64 *)(finishPacket + 0x60) = *(u64 *)action;
    func_00194590(finishPacket, 0);

    packet = (u8 *)func_001d3700(2, 0xFFF);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    packet = func_00199ee0(*(u8 **)(action + 0x30), 0xB, 0, 0, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u16 *)(packet + 0x4A) = 0x60;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    returnIndex = 0;
    while ((u16)returnIndex < *(u16 *)(action + 0x6A)) {
        returnTarget = *(u8 **)(action + (u32)(u16)returnIndex * 4 + 0x38);
        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] != 0)
            goto next_return_target;
        if (*(u16 *)(returnUnit + 0xA4) == 1)
            goto next_return_target;
        if ((*(u16 *)(returnTarget + 0x1A) & 1) == 0)
            goto next_return_target;
        if (func_002428f0(*(u8 **)(returnUnit + 0xA64), 0) != 0)
            goto next_return_target;

        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] == 0) {
            returnNode = *(u8 **)(iGpffffb3ac + 0x17C);
            while (returnNode != NULL) {
                if (returnUnit == returnNode)
                    break;
                returnNode = *(u8 **)(returnNode + 0xA68);
            }
        }

        returnPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)returnUnit,
                                                       NULL, fGpffff809c, 0x18);
        returnPacket[0] = 4;
        *(u64 *)(returnPacket + 8) = *(u64 *)(finishPacket + 0x58);
        *(u64 *)(returnPacket + 0x60) = *(u64 *)action;
        func_00194590(returnPacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(returnTarget + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(returnPacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);
next_return_target:
        returnIndex = (u16)(returnIndex + 1);
    }
    func_001d3e00((u32)formation);
}
