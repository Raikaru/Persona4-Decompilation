/* EXACT_ORDINARY_C: object_size=1036; window=1040;
 * normalized_diff=0; fully_resolved_differing_bytes=0;
 * code_relocations=26; zero_alignment_tail=4. Integrated in code1_0022.c.
 * Switch table: nine resolved R_MIPS_32 entries at retail 0x00747750:
 * 00223314 002233A4 00223558 00223560 0022358C
 * 002235FC 0022362C 00223644 00223688
 *
 * opt_propagation off preserves the result-area base and field reloads.
 * A named reward preserves load/add order. Prefix increments preserve
 * modulo-u16 comparison values without changing later field reloads.
 * func_0011f410's record and eleven-word message array are real pointers;
 * its active definition and this caller now share those parameter types.
 * Both integrated owners verify: 180 MATCH / 20 ASM, no mismatches.
 * All code relocations and all table destinations independently resolve
 * to retail bytes. No inline asm, fake guard, padding or pinned register.
 */
/* Replace the existing void func_002232a0() declaration with this prototype. */
extern s32 func_002232a0(KwlnTask *task);

/* Existing owner types, func_00452560(void *), and func_00455ea0 are reused. */
extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern void func_00460ac0(u8 *list, u8 *node);
extern u16 func_0010b6f0(void);
extern u16 *func_0010ace0(s16 slot);
extern u8 *func_00117780(s32 parent, s32 priority, s32 mode, s32 layout, s32 option);
extern void func_00117580(u8 *window, s32 value);
extern void func_0011d100(u8 *window, f32 *position);
extern void func_0011bb90(u8 *window);
extern void func_0011b480(u8 *window, s32 mode, u32 persona, s32 option);
extern u8 *func_0011f410(s32 parent, s32 window, u8 *record, s32 payload, s32 option, s32 *messages);
extern u32 func_0011f560(u8 *child);
extern s32 func_0011f580(u8 *child);
extern s32 func_00353f50(s32 mode);
extern s32 func_0021de60(void);
extern void func_0046d730(const void *file, u32 line);

#pragma opt_propagation off
s32 func_002232a0(KwlnTask *task)
{
    u8 *work;
    u8 *results;
    u8 *persona;
    u8 *payload;
    s32 index;
    s32 messages[11];
    f32 position[2];

    work = (u8 *)func_00452560(task);
    results = *(u8 **)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    func_00460ac0(D_00795F20, work + 8);

    switch (*(u32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = (u16)func_0010b6f0();
        *(u8 **)(work + 0x4C) = func_00117780(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0) {
            func_0046d730(D_006296D0, 0x2F);
        }
        func_00117580(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        func_0011d100(*(u8 **)(work + 0x4C), position);
        func_0011bb90(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        results += 0x60;
        while ((index = *(s32 *)(work + 0x3C)) < *(s32 *)(work + 0x38)) {
            u32 reward;

            persona = (u8 *)func_0010ace0((s16)index);
            reward = *(u32 *)(results + 8 + *(s32 *)(work + 0x3C) * 4);
            *(u32 *)(persona + 8) += reward;
            index = *(s32 *)(work + 0x3C);
            if (*(u8 *)(index * 0x88 + results + 0x38) > 0) {
                break;
            }
            *(s32 *)(work + 0x3C) = index + 1;
        }
        /* Constructor and transitions maintain 0 <= index <= count <= 12.
         * Consequently this arm always has a persona produced by the loop. */
        if (index != *(s32 *)(work + 0x38)) {
            s32 recordIndex;

            func_0011b480(*(u8 **)(work + 0x4C), 1, (u32)persona, 0);
            messages[0] = 12;
            messages[1] = 0;
            messages[2] = 6;
            messages[3] = 9;
            messages[4] = 10;
            messages[5] = 11;
            messages[6] = 13;
            messages[7] = 14;
            messages[8] = 19;
            messages[9] = 20;
            messages[10] = 21;
            payload = func_00455ea0(
                *(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0);
            recordIndex = *(s32 *)(work + 0x3C);
            *(u8 **)(work + 0x50) = func_0011f410(
                (s32)task, *(s32 *)(work + 0x4C),
                results + recordIndex * 0x88 + 0x38,
                (s32)payload, 0, messages);
            *(u16 *)work |= 2;
            *(s32 *)(work + 4) = 2;
        } else if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;
    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (func_0011f560(*(u8 **)(work + 0x50)) == 0) {
            break;
        }
        func_0011f580(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        if (++*(u16 *)(work + 0x48) < 45) {
            if ((*(u16 *)(D_008C0240 + 0xE) & 0x50) == 0) {
                if ((*(u16 *)(D_008C0240 + 0xC) & 0x10) == 0) {
                    break;
                }
                if (*(u16 *)(work + 0x48) < 4) {
                    break;
                }
            }
        }
        *(s32 *)(work + 0x3C) += 1;
        *(s32 *)(work + 4) = 1;
        break;
    case 5:
        if (func_00353f50(1) != 0) {
            break;
        }
        *(u16 *)work &= 0xFFFE;
        *(s32 *)(work + 4) = 8;
        break;
    case 6:
        if (func_0021de60() == 0) {
            break;
        }
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) == 0) {
            if (++*(u16 *)(work + 0x48) < 5) {
                break;
            }
        }
        *(u16 *)work &= 0xFFFD;
        return -1;
    case 8:
    default:
        break;
    }
    return 0;
}

#pragma opt_propagation on

/*
func_002232a0 contracts (fresh direct-source/retail audit; semantic audit before Main compilation; verified measurements above)

Authority and source ABI
- Primary target: asm/nonmatchings/code1_0022/func_002232a0.s, all 275 lines read. Archived P022_002232a0_body.c also read completely, but its measurements are not a limit or impossibility argument.
- ABI is s32 func_002232a0(KwlnTask *task). Target 2232B8 preserves only incoming a0 in s3. Target 2232BC calls func_00452560 without changing a0; its retail 452560 loads task+0x38 into v0. No input is obtained from an unspecified current-task global.
- Constructor 223730..223824: allocate 0x54 bytes, memset all 0x54, register parent=a0, name=6296B0, priority=15, timing=0,0, updater=2232A0, cleanup=2236C0, work=allocation in ABI slots a0..a7 ($4..$11). Explicitly store state=0 and parent work from getter(parent) at +0x40. Clear embedded node +8..+0x37, store callback 2236B0 at +0x10 and self at +0x18, set flag bit 1. Current owner code1_0022.c:383-403 agrees.
- sdkTask retail 451FC0..452034 shifts original $5..$11 into $4..$10 for 451DE0. The latter stores callback, cleanup and work at task+0x30,+0x34,+0x38 at 451F04/08/0C. It does not execute updater during creation. Current sdkTask.c:689-761 agrees.
- Dispatcher 451430..4515A4 loads callback at task+0x30, explicitly moves task into a0 at 451520, then jalr. Return 0 retains callback; nonzero replaces callback. Return -1 for an active (low flags=2) task enters removal and child teardown. Thus updater's only results are keep-running 0 and terminal -1, not fabricated status values. Cleanup receives task in a0; current sdkTask.c:434-436,487-489,839-841 establish actual invocation.

Work object and invariant
- 0x54-byte allocation: u16 flags +0; u32 state +4; 0x30-byte order node +8; s32 count +0x38; s32 index +0x3C; parent-work pointer +0x40; u16 timer +0x48; window task +0x4C; child task +0x50. No accessed field extends beyond allocation.
- State 0 writes index=0, then count=(u16)0010B6F0. Provider 10B6F0..10B7B0 selects max 12/10/8/6 from D_0079B40C bits 4/2/1/none; iterates only that many 0x30-byte persona slots and counts active-bit-1 entries. Therefore 0<=count<=12.
- There are exactly two index-advance sites in target. At 223400 the preceding loop body was entered only under signed index<count; it increments once for an empty result byte. At 2235E4 state 4 follows child creation from a loop iteration with index<count, and increments once before state=1. No state 4 self-loop advances index while waiting; no subsequent state 1 fallthrough occurs in that same invocation. Count has no further write in target. Therefore 0<=index<=count<=12 is inductive from construction.
- External exit is 223830..22388C (current owner lines405-416): resets timer, sets state6 after starting fade if flag4, otherwise state7. It never changes index/count. Parent queries 223890 read flag1 only. Parent current code1_0021.c:1572-1629 creates this task only after result construction, waits on flag1, then calls exit and discards its handle; it does not mutate child work.
- Order callback 2236B0..2236BC reads only u16 at a1 then masks bit2 into v1. It performs no stores and does not produce an ABI return in v0. Constructor supplies its self pointer at node+0x10 (work+0x18); current signature is void(s32,u16*,s32), not a one-argument updater. This no-write callback cannot break index/count.
- Incoming s2 is saved, but not semantically consumed on valid task paths: the only real definition is persona=getter(slot) at 2233C0. The branch 223420 tests index==count, not >=. With corrupt index>count retail would skip the loop and pass incoming s2 at 223430. Our ordinary C deliberately preserves the branch shape and an uninitialized persona local on this out-of-contract path; there is NO hidden argument, dummy initializer, extra guard or corruption fallback. For all constructor-reachable calls the local is defined before its use. This is not a remaining defined-C blocker on the actual registered-task invariant.

List and parent input extents
- Every call loads parent work into the long-lived results pointer before enqueue, zeroes work+8 and +0xC, then calls 460AC0(D_00795F20,work+8). The provider's complete 460AC0..460B5C reads list+4 and node+4, writes previous tail+0 and list+4 only. It neither invokes callbacks nor changes work+0x38/+0x3C. D_00795F20 is a mutable list with an eight-byte accessed header; no total extent is inferred from disk zeros.
- Parent constructor current code1_0021.c:1664-1683 allocates and clears 0x94C bytes. Embedded result area is +0x60..+0x933 (0x8D4 bytes); resource pointer +0x934 fits inside parent allocation. Retail 21E148 clears exactly 0x8D4 for the result producer. Its 21E2A0..21E2B4 snapshots the same count and starts slot zero; 21E620..21E630 increments and compares against that bound.
- State1 changes its local base to parent+0x60. Experience delta access is u32 at base+8+index*4, for index0..11: [base+8,base+0x38). Record-byte read is u8 at base+0x38+index*0x88; child receives the same record base, reloading index after resource retrieval.
- Producer 21E5E8..21E604 passes persona, base+0x38+slot*0x88, and delta to 10BE60; 21E614..21E61C stores each delta at base+8+slot*4. Provider 10BE88..10BECC saves output from a1 and clears precisely 0x88 bytes. Thus twelve real 0x88-byte record objects occupy [base+0x38,base+0x698), entirely in the 0x8D4 result area.
- 10ACE0(s16) sign-extends slot, asserts slot>=0 && slot<capacity, checks valid flag at D_00797F8C+slot*0x30, returns NULL when inactive or D_007973A0+0xBEC+slot*0x30 when active. The latter base equals D_00797F8C. Target adds a u32 delta to persona+8 with modulo-2^32 arithmetic. Target and its producer both rely on the game's occupied-prefix persona collection contract; count alone does not prove non-null slot values. No new null fallback is justified or introduced. The accessed persona word is within the actual 0x30-byte record.

All target call argument slots and outputs
- 452560: a0=task; returns work word from +0x38. Already repaired owner declaration u32(void*), reused unchanged.
- 460AC0: a0=list,a1=embedded node; output writes described above; void.
- 10B6F0: no arguments, u16 occupied count bounded by 12.
- 117780: a0=0,a1=15,a2=4,a3=5,a4=0. Current shdPersona.c:785-800 allocates/clears via allocator a 0x574-byte window work, creates task, forwards mode/layout/option to 1175E0 and returns task. Target stores return at work+0x4C and asserts nonzero.
- 46D730: a0=6296D0,a1=0x2F; diagnostic only. Retail ELF string at 6296D0 is btlResultHeroPsLvUp.c. Do not invent early return after diagnostic.
- 117580: a0=window,a1=0xAE; current provider lines718-724 validates low16<0xD8 and stores u16 at windowWork+0x570.
- 11D100: a0=window,a1=position; exact eight-byte consumer below.
- 11BB90: a0=window; starts window presentation using window work; no caller-stack pointer supplied.
- 10ACE0: a0=(s16)index, returns persona pointer as above.
- 11B480: a0=window,a1=1,a2=persona,a3=0. Current provider shdPersona.c:1410-1468 stores persona at windowWork+0, populates derived window data and updates display; persona is persistent global data, not an automatic. No caller local array is output here.
- 455EA0: a0=parentWork->resource(+0x934),a1=0,a2=NULL. Retail 455EC0..455EC8 substitutes its OWN s32 output slot when a2 is null. It reads resource+0x110, copies a 0x100-byte archive header, writes exactly one size word to that substituted slot, and returns resource-entry+0x100. No output is written into this updater's frame. Payload is archive-owned, not provider stack data.
- 11F410: a0=task,a1=window,a2=resultRecord,a3=payload,a4=0,a5=messages ($4..$9). Retail 11F434..11F448 saves all six real inputs. Allocates a 0x58-byte child work and stores inputs1..4 at +0x1C,+0x20,+0x24,+0x28. Returns child task, stored at updaterWork+0x50. It does NOT retain the stack messages pointer; exact copy below. Record/payload are persistent parent-owned data.
- 11F560: a0=child; reads child+0x38 then childWork+0x14 and returns whether state==14. No output buffers.
- 11F580: a0=child, forwarded unchanged to 452080 at retail 11F588; returns provider s32 unchanged. Updater legitimately ignores it. Current repaired source shdPersona.c:3246-3249 reused.
- 353F50: a0=1. Current repaired code1_0035.c:260-267 forwards mode to 2BB7C0 and, if 2BB600==0, to 2BB1E0, returning 0; otherwise returns1. Retail 353F50..353FA4 agrees.
- 21DE60: no input; name lookup at 21DE68..21DE7C returns true when fade task named by 6290E0 no longer exists.

Actual local producers/consumers, no padding
- messages is exactly s32[11], 44 bytes. Retail stores at SP+0x50,+54,+58,+5C,+60,+64,+68,+6C,+70,+74,+78 produce [12,0,6,9,10,11,13,14,19,20,21]. Consumer 11F410 receives SP+0x50 in a5 at 2234D4. Retail 11F500..11F52C loops i=0..10, reads input+i*4 and copies to childWork+0x2C+i*4, ending at +0x57 of its 0x58 allocation. It never reads a twelfth entry or retains pointer. All eleven are initialized before resource call and consumed synchronously during constructor.
- position is exactly f32[2], eight bytes. Retail 223374..22337C writes 0x00000000 and 0x41980000 (0.0f,19.0f) at SP+0x88,+0x8C. Retail 11D100..11D130 reads a1+0,+4 only and stores to windowWork+0x4FC,+0x500; no source pointer retention, no third element. Lifetime ends after this synchronous call.
- No other automatic storage is passed by address. payload and recordIndex have separate semantic lifetimes from slot-scanning index and persona. Stack gaps are NOT declared as objects: retail SP+0x48..0x4F and +0x7C..0x87 are unaccessed by target/consumers, and ABI saves are not source arrays.
- D_008C0240 is one real 0x94-byte input block, not two invented GP scalars. Dispatcher 451470..451484 clears 0x94 or 4514EC..451504 copies 0x94 from 8C02E0; two 0x4A-byte player records are filled. Target reads u16 at offsets+0xE and+0xC only. declarations.h uses the owner array, not D_008C024C/D_008C024E standalone symbols.

Cleanup and ownership
- 2236C0..223724 obtains work from real task argument. If flag4 and window nonzero, releases window and nulls +0x4C; always frees updater work through 8873EC. It does not free parent results or increment index/count. Child release occurs only after child done predicate; it is not an extra destructor added to updater. Window ownership branch exactly follows retail, including no release when flag4 is clear.

*/
