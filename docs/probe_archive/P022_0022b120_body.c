/* Exact ordinary C: func_0022b120, retail 0x0022B120..0x0022B86F.
 * Object 1860 bytes; all 67 code relocations resolved; zero differing bytes.
 * The remaining twelve retail bytes are zero alignment words.
 * Declaring wait1, wait0, anchor in that order preserves the saved-register
 * allocation. Actual script-name pointers close argument materialization.
 * The active script constructor has the same u8* name contract; its existing
 * word-address resolver boundary is explicit. Both live owners verify:
 * 204 MATCH / 15 ASM; no mismatches. No game execution is claimed.
 * All 23 publications retain full-width action/predecessor identities.
 * The sole automatic payload is an initialized 12-byte RwV3d, copied by
 * the real rotate constructor. Formation initialization and reference
 * releases retain the retail ordering. No fake input or padding is used.
 *
 * func_0022b120 contract recovery
 *
 * Authority and scope
 * - Complete current retail window: asm/nonmatchings/code1_0022/func_0022b120.s, 0x0022B120..0x0022B86F, size 0x750 (1872 bytes). The return delay slot is at 0x0022B860; the remaining three words are zero alignment words.
 * - Graph discovery was used first; coverage reports the target assembly partial and many C owners metadata_changed. All conclusions below use direct current source and retail assembly, not archived probes or stale graph line numbers.
 * - body.c is an insertion body for current src/promoted/code1_0022.c. No repository changes or validation commands were performed.
 *
 * Incoming ABI and actual reachability
 * - a0 alone is an action/list-entry pointer, called action in body.c. The target directly reads its u64 identity at +0 and its actor pointer (32-bit lw) at +0x30. It does not consume a1..a3, t0/t1, incoming s0..s7, or floating argument registers.
 * - void return: the actual initializer dispatcher ignores the callback's result. The target leaves v0 from the final formation-release call without establishing a return value.
 * - Actual registration is func_001ea4a0, retail asm/nonmatchings/code1_001e/func_001ea4a0.s. When func_001ef9a0()==0x20B, bit 0x15FF is not 1, and neither the initializer at battle+0xB40 nor updater at +0xB44 is already this pair, it asks func_0019ef90(1,0x10B) for the actor. The a0=1 is established at 0x001EA4C8 and survives to 0x001EA520. A nonnull actor is looked up with func_001b0c80; only a nonnull returned action is registered as (func_0022b120,func_0022b870,action).
 * - func_001b0c80 is not an allocator. Its complete retail code walks battle+0x174, compares each node+0x30 to the actor argument, advances through node+0x450, and returns the matching existing action or null. Thus the registered argument is the existing action whose +0x30 names the selected actor, not an invented scheduler packet.
 * - func_001fae60 retail stores its three incoming words to battle+0xB40/+0xB44/+0xB48 respectively, without capturing any saved registers.
 * - Actual initializer dispatch is func_001fac80 (complete retail read). It checks battle flags +0xC bit 0x200000, calls func_0022bd00, and, if that result is zero and +0xB40 is nonnull, loads a0 from +0xB48 and jalr's +0xB40. It then returns 1 regardless of callback v0. Its own s0 contains its own incoming argument; target overwrites s0 before consuming it. Its incoming s1 has no contract and is NOT used by this target.
 *
 * Saved-register definition audit: every definition dominates every use
 * - s4 = a0 at 0x0022B148; held as action through the complete function.
 * - s3 = *(u32 *)(a0+0x30) at B14C; held as actor through every constructor. Later actor calls do not reload action+0x30, matching retail.
 * - s5 = return of first func_001d3d50(0) at B188; openingFormation until B82C.
 * - s6 = return of second func_001d3d50(0) at B198; closingFormation until B820.
 * - s0 = first script packet at B200 before its first dependency load B23C; reassigned to func_0019b6a0 result at B418; reassigned to second script at B538. body.c calls it anchor.
 * - s2 = opening traversal side 0 at B2F4 before first identity read B3E4; reassigned to closing traversal side 1 at B6E8 before B73C. body.c calls it wait1.
 * - s1 = opening traversal side 1 at B33C before first identity read B3F0; reassigned to morph packet at B4EC before B544; reassigned to closing traversal side 0 at B69C before B730. body.c calls it wait0. There is NO incoming-s1 blocker analogous to the neighboring target.
 * - s7 = func_00230650 result at B498 before B5D8; body.c calls it cleanup.
 * - There are no conditional branches, loops, alternate entries or join points in the target. All of these definitions are reached sequentially on every returning execution. This conclusion is from all 0x750 bytes, not from source guesses.
 *
 * Object widths, provider extents and initialization
 * - 32-bit target pointers/formation handles are preserved as pointers or the existing s32/u32 ABI; they are not 64-bit packet identities. All ld/sd identity copies use u64 loads/stores in body.c. There is no narrowing of identities from action+0, packet+0x58, packet+8, packet+0x18 or packet+0x60.
 * - All generic packet constructors below use func_00194470. Its complete retail code allocates 0x90+workSize bytes, zeros the ENTIRE allocation with func_0043f9c8, sets id at +0x40, initializes wait-type bytes at +0/+0x10/+0x20/+0x30 to 1, points +0x78 at packet+0x90 if size>0, and sets flags +0x47 |=0x31. All fields not subsequently set are initialized zero, including unused work bytes. Zero-work packet workData remains null. No target writes into a constructor's payload or invents a header shorter than 0x90.
 * - func_00194590(packet,lane) is not void allocation plumbing: retail assigns a fresh 64-bit identity from func_00192560 to packet+0x58, resets header fields, sets lane byte +0x44 and flags, synchronously calls the optional initializer at +0x68 with workData, publishes into battle list slots +0x198/+0x19C indexed by (u8)lane*8, and returns the u64 identity. Every target read of a predecessor+0x58 occurs after predecessor publication. body.c deliberately reloads those fields at the same points rather than caching IDs early across callbacks.
 * - func_001d3d50(0): 0x638-byte formation allocation, exact current return s32 representing its address. It writes flags u16 at +0x630=0, counter u16 at +0x632=1, value u32 at +0x634=0. First 0x630 bytes are NOT initialized by this allocator. Target initializes them before any traversal by func_001d3ea0.
 * - func_0022ced0(id): returns an asset/subfile pointer from func_00455ea0(*(battle+0xB90),id&0xFFFF,NULL). Asset length is data-dependent; target does not receive a size and does not create a local copy. Calls use id=0xC/0xD. func_001d3ea0(destination,source) immediately copies exactly 0x630 bytes, walks two 0x314-byte blocks with counts at block+0x10 and 0x18-byte entries beginning +0x1C, leaves type 0xFE alone, resolves 0xFF references using packed>>5 and packed&0x1F, resolves other resource offsets relative to source, and ORs destination+0x630 with 2. The resulting entire 0x638 formation object is initialized. Its nested resource outputs are handles, not fixed-size locals. Source resource validity/count bounds are the same retail prerequisites; no guards are added.
 * - func_001ebb00(action,3,name), name now u8* in the active provider and caller: packet id 0xD00, work 0x10, total 0xA0. Flags &=0xEE, update=001eba20. work+0 action pointer, +0xC resource base from func_0022ced0(0), +4 resolved name from func_0029de20(base,name), +8 zero. Uses D_00635560 then D_00635580 by address; no guessed string lengths or copied assets.
 * - func_00194c90(callback,action): independently allocates and zeros 0x98 bytes, a full 0x90 header plus 8-byte {function pointer,data pointer}. Returns u8*. Stores callback and action by value; it retains no pointer to a target automatic. Existing s32-returning callbacks are supplied through the owner's existing void* callback convention.
 * - func_00199ee0 / named provider btlUnitCreateAnimPacket: actor/id/blend/mode are a0/a1/a2/a3 and speed is f12. Target uses actor,0x13,0,2,1.0f. The named C provider semantic order is unit,id,blend,speed,mode; owner currently exposes equivalent register order as unit,id,blend,mode,speed. For id 0x13, packet id 0x100, work 0x10, total 0xA0: unit +0, s16 id +4, u16 blend +6, float speed +8, u16 mode +0xC, remaining zero. Negative-id constructor alternatives are not selected here.
 * - func_002306d0: id 0xE03, zero work, total 0x90; flags &=0xFE, update=00230690. This is the ONLY target-created packet whose actionUID +0x60 is intentionally left at constructor zero rather than assigned action+0.
 * - func_001d6240: id 0x301, work 0x20, total 0xB0. Inputs a0..a4 are formation, actor, actor, u16 side, flags 0x200. Writes work u32 +0/+4/+8, u16 +0xC, u32 +0x1C; all other work bytes are allocator-zero. Init=001d5f60, update=001d6010, condition=001d6170, destroy=001d61e0, flags &=0xEF. Four calls use opening sides 0/1 then closing sides 0/1. Each synchronous init increments formation counter via 001d40d0 and actor reference counts, sets work+0x18=0, chooses actor+0xA08 into work+0x14 for side 0 or 1, obtains work+0x10 via 001d6ce0. Both side branches initialize that field; neither relies on incoming state. Both actor inputs intentionally alias the same actor, so its ref count changes twice per init/destruction.
 * - func_001d7ab0: id 0x30A, work 6, total 0x96. Copies FOUR bytes from its first argument, then u16 duration 30 to work+4. Input is the live region at gp-0x5B28 (iGpffffa4d8=0x007635C8), not a one-byte temporary. declarations.h exposes the four-byte accessible region; no copied global/padding object is introduced.
 * - btlUnitCreateRotatePacket (retail address 00197F50): id 0x10D, work 0x18, total 0xA8. Work {unit +0, RwV3d +4..+0xF, flags +0x10, timer +0x14}. It copies exactly the three floats, not a quaternion or 16-byte vector; null input instead chooses D_00881430, but target supplies nonnull. The sole target stack object is RwV3d rotation={0,0,(float)3000}, all 12 bytes explicitly initialized before the call. Retail storage is sp+0x90..0x9B; sp+0x9C is not read. The constructor does not retain &rotation, so lifetime ends after construction without dangling storage.
 * - func_0019b6a0: id 0x110, work 4, total 0x94. Work actor pointer, init=0019b620, update=0019b640, destroy=0019b680, flags &=0xFE.
 * - func_00230750: id 0xE04, zero work, total 0x90, flags &=0xFE, update=00230710.
 * - func_00230650: id 0xE02, zero work, total 0x90, flags &=0xFE, update=00230610. Its published identity is retained until used as the second wait of func_002305c0.
 * - func_0019b550(actor,0x10E,0x216): id 0x10F, work 0x10, total 0xA0. Work actor +0, s16 animation +8. It calls 002300f0(actor,work+4,work+6); on zero result it sets +4 to actor byte +0xA2 plus 1 and +6 to 0x10E. Full work was already zero-initialized, so no uninitialized output locals are involved. Flags &=0xFE, init=0019acd0, update=0019ae20, destroy=0019b530.
 * - func_002305c0(0x10E): id 0xE01, work 8, total 0x98; work+0 id, +4 zero; update=00230500.
 * - func_0019bbe0(actor,0xFFFFFFFF,1,0,3,0): six integer register inputs a0..a5, no floating inputs. id 0x112, work 0x14, total 0xA4. Work unit +0, startColor +4 (zero at construction), targetColor +8, s16 startFrame +0xC, s16 duration +0xE, u8 mode +0x10, u8 flags +0x11, s16 counter +0x12 (zero). Init=0019b710, update=0019b730, destroy=0019bbc0. The -1 retail immediate is the low u32 color 0xFFFFFFFF, not an identity or pointer.
 * - func_001d7b60(30): id 0x30B, work 2, total 0x92; u16 duration +0; update=001d7b30.
 * - func_001b7e20(16): id 0x601, work 0x28, total 0xB8; u32 duration at work+0x20, update=001b7b30, all other work zero.
 * - func_001b9360(16,0): id 0x603, work 0x5C, total 0xEC; s32 duration work+0x50, s16 mode +0x58, update=001b87e0, all other work zero.
 * - func_001b99a0(16): id 0x605, work 0x18, total 0xA8; s32 duration work+0x10, update=001b96e0, all other work zero.
 * - func_001ba090(8): id 0x607, work 8, total 0x98; s32 duration work+0, update=001b9e50, remaining zero.
 *
 * Nested cleanup and final ownership
 * - Before creating the two formations, target sets battle+0xC |=0x400000 and battle u16 +0x18 |=0x23, then passes STILL-LIVE a0=action to func_001a03b0. Current direct provider consumes *action as a 64-bit identity. Its bit-0x20 packet and bit-2 packet paths run, and bit-1 enables traversal from battle+0x174 via +0x450. Qualifying nodes have flags +0x1A bit 1 and zero HP via 002428f0; their animation packets get action identity. Preexisting bits 0x10/8/4/0x40 also control additional packet creation. It then zeros +0x18 and clears 0x400000. body.c neither substitutes null nor suppresses those preexisting-bit effects.
 * - Target sets battle+0xC |=0x80000 only after both formations are populated. Later updater func_0022b870 clears it after action-linked packets cease to exist; target does not clear it early.
 * - Each formation starts counter 1; two traversal publications synchronously acquire two more references. Target releases closing then opening at the end, leaving two packet-held references each in normal execution. The installed destruction callback func_001d61e0 releases its formation and actor references. No local or resource destructor is invented, and the target does not free a still-used formation.
 *
 * Direct source evidence for providers
 * src/Battle/btlFormation.c: func_001d3d50,001d3e00,001d3ea0,001d40d0,001d61e0,001d6240.
 * src/Battle/btlPacket.c: func_00194c90 and its exact 0x90-byte header/callback work layout.
 * src/Battle/btlUnit.c: RwV3d, BtlUnitPacketRotate, BtlUnitPacketAnim, btlUnitCreateRotatePacket, btlUnitCreateAnimPacket.
 * src/Battle/btlUnit_functions.c: BtlUnitColorWork, func_0019b6a0,0019bbe0.
 * src/Battle/btlEffect.c: func_001d7ab0.
 * src/Battle/btlMain.c: func_001b7e20,001b9360,001b99a0,001ba090.
 * src/promoted/code1_0019.c: func_00194590,0019b550 (also complete retail reads).
 * src/promoted/code1_001d.c: func_001d7b60.
 * src/promoted/code1_001e.c: func_001ebb00.
 * src/promoted/code1_0023.c: func_002305c0,00230650,002306d0,00230750.
 * src/promoted/code1_001a.c: complete func_001a03b0 cleanup traversal.
 * src/promoted/code1_0022.c: owner types/declarations, func_0022ced0,0022b0b0,0022b0e0,0022b870.
 * Additional complete retail reads: 001ea4a0 registration,001fae60 registration storage,001fac80 dispatcher,001b0c80 action lookup,00194470 full allocation/zeroing,00194590 identity/publication,0019b550 constructor,001d5f60 formation init.
 */

/* Add these declarations to src/promoted/code1_0022.c; types come from that owner. */
extern u8 D_00635560[], D_00635580[];
/* Retail func_001d7ab0 copies FOUR bytes beginning at gp - 0x5B28.
 * This is an addressable input region, not a one-byte automatic temporary. */
extern u8 iGpffffa4d8[4];
extern u8 *func_001ebb00(s32 action, s32 kind, u8 *name);
extern u8 *func_00194c90(void *callback, void *data);
extern BtlPacket *func_001d7ab0(u8 *values, u16 duration);
extern BtlPacket *func_001d7b60(u16 duration);
extern BtlPacket *func_0019b6a0(BtlUnit *unit);
extern u8 *func_0019b550(u8 *unit, s16 id, s16 animation);
extern BtlPacket *func_002305c0(s32 id);
extern BtlPacket *func_00230650(void);
extern BtlPacket *func_002306d0(void);
extern BtlPacket *func_00230750(void);
extern BtlPacket *func_001b7e20(u32 duration);
extern BtlPacket *func_001b9360(s32 duration, s16 mode);
extern BtlPacket *func_001b99a0(s32 duration);
extern BtlPacket *func_001ba090(s32 duration);

/* Already declared/defined in the current owner; retain, do not duplicate:
 * RwV3d (three floats), BtlUnit, BtlPacket, DAT_0076449c;
 * void func_001a03b0(s64 *);
 * s32 func_001d3d50(u32);
 * u8 *func_0022ced0(s32);
 * void func_001d3ea0(int, u32);
 * void func_001d3e00(u32);
 * s64 func_00194590(u8 *, u32);
 * u8 *func_00199ee0(u8 *, s32, s32, s32, f32);
 * BtlPacket *func_001d6240(u32, u32, u32, u16, u32);
 * BtlPacket *btlUnitCreateRotatePacket(BtlUnit *, const RwV3d *, u32);
 * BtlPacket *func_0019bbe0(BtlUnit *, u32, s16, s16, u8, u8);
 * s32 func_0022b0b0(void), func_0022b0e0(void).
 * No existing declaration needs changing for this body.
 * func_00199ee0's current owner spelling/order is deliberately retained.
 * Its named provider btlUnitCreateAnimPacket has semantic order
 * (BtlUnit *, u16, u16, f32, u16); both place actor/id/blend/mode in
 * a0/a1/a2/a3 and speed in f12 under the target ABI.
 * The provider ABI is not an extra integer or hidden floating argument.
 */

void func_0022b120(u8 *action)
{
    u8 *actor;
    s32 openingFormation;
    s32 closingFormation;
    u8 *wait1;
    u8 *wait0;
    u8 *anchor;
    u8 *cleanup;
    u8 *packet;
    RwV3d rotation;

    actor = *(u8 **)(action + 0x30);
    *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
    *(u16 *)(DAT_0076449c + 0x18) |= 0x23;
    func_001a03b0((s64 *)action);
    openingFormation = func_001d3d50(0);
    closingFormation = func_001d3d50(0);
    func_001d3ea0(openingFormation, (u32)func_0022ced0(0xC));
    func_001d3ea0(closingFormation, (u32)func_0022ced0(0xD));
    *(u32 *)(DAT_0076449c + 0xC) |= 0x80000;

    anchor = func_001ebb00((s32)action, 3, D_00635560);
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = func_00194c90((void *)func_0022b0b0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = func_00199ee0(actor, 0x13, 0, 2, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    packet = (u8 *)func_002306d0();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x33;
    func_00194590(packet, 1);

    wait1 = (u8 *)func_001d6240((u32)openingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    func_00194590(wait1, 2);

    wait0 = (u8 *)func_001d6240((u32)openingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 2);

    packet = (u8 *)func_001d7ab0(iGpffffa4d8, 0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x19A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = (f32)3000;
    packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)actor, &rotation, 2);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    anchor = (u8 *)func_0019b6a0((BtlUnit *)actor);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait1 + 0x58);
    anchor[0x10] = 4;
    *(u64 *)(anchor + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 1;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = (u8 *)func_00230750();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    cleanup = (u8 *)func_00230650();
    cleanup[0] = 4;
    *(u64 *)(cleanup + 8) = *(u64 *)(wait1 + 0x58);
    cleanup[0x10] = 4;
    *(u64 *)(cleanup + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(cleanup + 0x48) = 3;
    *(u64 *)(cleanup + 0x60) = *(u64 *)action;
    func_00194590(cleanup, 1);

    wait0 = func_0019b550(actor, 0x10E, 0x216);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 1);

    anchor = func_001ebb00((s32)action, 3, D_00635580);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 2;
    *(u16 *)(anchor + 0x4A) = 0xC;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = func_00194c90((void *)func_0022b0e0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_002305c0(0x10E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(cleanup + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_0019bbe0((BtlUnit *)actor, 0xFFFFFFFFU, 1, 0, 3, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001d7b60(0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 4;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    wait0 = (u8 *)func_001d6240((u32)closingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 2);

    wait1 = (u8 *)func_001d6240((u32)closingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait1 + 0x48) = 2;
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    func_00194590(wait1, 2);

    packet = (u8 *)func_001b7e20(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b9360(0x10, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b99a0(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001ba090(8);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    func_001d3e00((u32)closingFormation);
    func_001d3e00((u32)openingFormation);
}

