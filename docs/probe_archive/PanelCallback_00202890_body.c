/* Measured 2026-09-09 against the complete current owner and canonical
 * providers: 708/720 bytes, normalized_diff 226, 32 resolved relocations.
 * Retail has 716 executable bytes and one final zero alignment word.
 * Two missing scaled-offset copies account for the eight executable-byte
 * shortfall (retail +0x190 and +0x1A4). Their displacement shifts later
 * branches; some address-add operand orientations also differ. Finalization
 * and the epilogue have the same instructions after the eight-byte shift.
 * Production remains INCLUDE_ASM; this is not an exact-match claim.
 *
 * Integer-address slot stores avoid caching the entire slot pointer. The
 * initial pointer load and actual callback reloads are retained. The
 * indexed-store spelling ties this result. Primary agent body: 696/nd310;
 * explicit-offset alternative: 700/nd457; offset+CSE-off: 708/nd259;
 * selective offset recomputation: 724/nd176 but exceeds the retail body;
 * shared scale+CSE-off: 712/nd228. Named copied addresses and lifetime/dead
 * assignment controls did not restore the two instructions.
 *
 * The declaration fragment below replaces the old owner declarations; it
 * must not be appended beside incompatible prototypes. BtlPanel and globals
 * come from src/Battle/btlPanel.c. No production contract changes were made.
 * All preserved callback and invalid-input boundaries are documented below.
 */

/* Original reconstruction evidence (agent emission hypotheses are superseded
 * by the measurements above; body.c/declarations.c are scratch names).
func_00202890 recovery: complete ordinary-C candidates, UNMEASURED

Artifacts and insertion
- body.c replaces the INCLUDE_ASM at current src/Battle/btlPanel.c:43. It retains the exact existing s32 func_00202890(void*) declaration at line 48 and uses the existing BtlPanel view by casting the sole argument inside the body. No owner-type rewrite is required.
- declarations.c REPLACES current owner lines 16-25; do not append incompatible prototypes beside the old ones. Its forward HCdvd tag is the genuine tag in include/h_cdvd_internal.h, not a new layout. Remaining owner globals/types and adjacent functions are unchanged.
- body_offset.c is one optional complete alternative, using an explicit genuine four-byte slot offset and ordinary case fallthrough. It uses the same declarations fragment. No additional helper, padding, artificial array extent, register binding, asm, initialized dummy input or output is present.
- No production files changed. No compiler, validator, test, formatter or runtime was run. Source-to-retail correspondence below is the evidence; no emission or exact-match claim is made for either candidate. The archive's old 696B/720B and nd310 commentary is historical, NOT a measurement of these artifacts.

Authoritative sources and index qualification
Read the complete 199-line retail asm/nonmatchings/btlPanel/func_00202890.s, including the final nop: 00202890..00202B5F, 0x2D0 = 720 bytes. Read the current 75-line owner and the complete build/WBHygiene_func_00202890_archive.txt. The archive's actual recorded status is COMPILE_ERROR: it defined BtlPanel* but later declared void*. body.c explicitly fixes that source-contract conflict without changing the callback ABI.
Graph discovery was only a locator. check_index_coverage reports generation 2026-09-04T07:03:15Z; owner/sdkTask/sdkSpr/promoted0019/promoted0046/promoted0020/g_data are metadata_changed; promoted0046 and generated0019/001b have parse gaps; target ASM and dispatcher ASM have partial assembly parsing; archive and asm/code1.s and retail ELF are excluded. Current direct source and retail instructions, not graph line numbers or completeness, support all conclusions here.

Real object layouts, inputs, and actual caller
1. BtlPanel is the existing 0x40-byte work view: u8* records +0; real unknown span +4..+33; s32 field34 +34; unknown +38..+3B; signed s16 state +3C; signed s16 index +3E. Do not mistake records for the parent sprite table; it holds the archive/CDVD node pointer. No local stack output buffer exists in this callback.
2. Current constructor func_00202b60 (owner:50-61), corroborated by complete retail constructor in asm/code1.s at 00202B60..00202BDF: func_00194470(0x508,0x40); clear packet+47 bit0; store callback address at packet+6C; load work from packet+78; zero exactly0x40 work bytes; store incoming param at work+34; return packet. Allocation provider src/promoted/code1_0019.c:1067-1105 takes s32,s32 and allocates workSize+0x90, initializes it, and places the positive-size work at packet+90. Thus this packet allocation is0xD0 total, not a fabricated frame/array dimension.
3. Actual caller is ASM func_001b33c0 (current promoted owner still INCLUDE_ASM at src/promoted/code1_001b.c:855). 001B35F8..001B3628 loads battle-global+DD4, passes it to func_00202b60, then schedules returned packet with func_00194590(packet,1), preserving the preceding task's +58 dependency in packet+8. There is no second callback input.
4. Dispatcher ASM func_00194670:00194840 loads packet+78 into a0, reloads packet+6C into v0, jalr v0 at00194848, and tests the returned v0 at00194850. Zero keeps phase2 and increments packet+50; nonzero sets packet+45 to3 and proceeds to later phases. Work pointer, not packet pointer, is the input. The dispatch reloads callback and work every invocation; candidate does not invent a captured callback or change return to void.
5. field34 is the parent kernel task handle. Current src/Kernel/sdkTask.c:986-989 defines func_00452560 as u32(void* task), returning *(u32*)(task+38). Target sets a0 from work+34 before jal002028B4; every callback invocation resolves once and keeps that resulting parent-work base for the entire invocation, including after all providers.
6. Battle initialization src/promoted/code1_0019.c:587-588 stores func_002011c0(parent) at battle-global+DD4. src/promoted/code1_0020.c:559-571 allocates and clears0xA20 bytes and gives that work to kernel task creation. This callback accesses parent flags u32 at+0 and sixteen 4-byte sprite-pointer slots at+2C..+68 (last byte+6B). It does not require or invent a packed/new parent struct. Owner's u32 D_00626720[] remains an unbounded extern array of actual 32-bit pointer words.

Full state and mutation correspondence
- 002028AC..C8: save sole input, resolve field34, initialize done=0, THEN load signed state. The resolver is still called even for an unknown state; caching state before that call would discard possible mutations.
- state other than0/1: no state work, no finalization, return0 (002028DC ->00202ACC ->00202B34).
- state0, records==NULL: query flag0x1438. Zero logs format/file/line with line0x532, requests D_00626790 mode1; nonzero logs line0x534, requests D_006267B0 mode1. Store returned archive pointer into panel->records AFTER the request, leave state/index unchanged, and return0. NULL result is not replaced with a fabricated success/fallback: next invocation follows the same state0 allocation branch.
- state0, records!=NULL: call IsFileLoaded on the current pointer. Zero returns0. Nonzero stores state=1 and processes state1 immediately in the SAME invocation. It does not re-test a callback-modified state to decide fallthrough.
- state1 entry0020298C: snapshot signed index into idx and load parent slot at+2C+4*idx BEFORE either idx<8 or idx<12 bounds test. Preserve signed comparisons, not unsigned or clamped indices. Snapshot idx is used for this iteration's table/slot accesses even if providers subsequently mutate panel->index.
- empty slot and idx<8: find actor(type0,id=(idx+1)&FFFF). If absent: explicitly clear the old indexed slot, THEN reload panel->index from+3E, increment, truncate through s16 store, return0. Do not replace increment with idx+1; retail reload is00202A40 after func_0019ef90.
- actor present: query flag0x1438 again. Unless the flag is nonzero AND snapshotted idx==0, allocate sprite from D_00626720[idx]. For that special combination allocate from iGpffffa570 instead. Store pointer into the snapshotted indexed slot after the call. Do not advance index or free the archive on this branch. Always return0.
- empty slot with8<=idx<12: allocate from D_00626720[idx], store returned pointer, return0. No actor lookup. Empty slot with idx>=12: no request/advance, return0.
- nonempty slot for ANY signed idx: call func_0046a750 on the loaded node, even if idx>=12. Zero returns0. Nonzero reloads panel->index AFTER the provider (00202A98), increments and stores it as s16, then compares the truncated signed result to12. This is ++panel->index, not cached idx+1. If not12 return0.
- only that successful nonempty-slot increment to12 reloads panel->records (00202AB8), destroys/releases it, then unconditionally clears panel->records AFTER the provider (00202AC4) and sets local done=12. Do not cache archive across the sprite readiness call, clear it before destruction, check/deduplicate it, increment state, or clear any sprite slot here. A provider-written records value is overwritten after destruction, as retail does.
- done==12 finalization: for indices12,13,14,15 in increasing order, call func_0046a770(table[idx]) and store returned pointer (including NULL) into corresponding parent slot. This is lookup of existing global sprite nodes, NOT allocation and NOT readiness polling. After all four calls, reload parent flags, OR bit1 numerically0x1, store flags, return1. No earlier bit snapshot may replace the final reload. All other paths return0. State remains1 and index normally12; scheduler consumes the return, so callback is not made artificially idempotent.

Provider contracts, allocation/free behavior, stale declarations
- func_00440b68 is s32(const char*,...), as include/h_cdvd_internal.h:90 declares. Retail00440B68 spills a1..a7 and forwards a va_list to004447F8, then returns its v0. Current owner's void foo() is stale K&R; generated0044's eight fixed s64 arguments/void return are also not the real variadic contract. Keep all three actual arguments here; do not narrow to fake byte-count prototypes.
- func_00454a60: actual src/Kernel/sdkCdvd.c:45-81 is u8*(u8*,s32). It may return an existing archive node after incrementing refCount or allocate0x364 bytes through mutable D_008873F4[0], initialize fields, and link it. Request mode1 is real. No allocation-output synthesis or local allocator callback caching is allowed.
- func_00454bd0 retail address is H_Cdvd_Destroy: actual src/h_cdvd/h_cdvd.c:146-196 is u32(HCdvd*), always returning true on its defined exits. It can defer destruction while readState!=0, decrement a reference and retain the node, or unlink/free memory and node through HCDVD_FREE's mutable dispatcher slots. Target ignores the returned value. Current void(u8*) declaration hides its real return/argument contract.
- func_004553c0 retail address is H_Cdvd_IsFileLoaded: src/h_cdvd/h_cdvd.c:477-480 is u32(HCdvd*), readState==4, not s32(u8*).
- func_00106330 retail address is datGetFlag: src/g_data/g_data.c:1001-1010 is u32(s32), not s32(s32). It returns the selected packed flag bit;0x1438 is within the provider's flag range.
- func_0019ef90: src/promoted/code1_0019.c:3598-3615 is u8*(s32,s32), internally narrows both to u16, walks battle-global's type-selected packet list and matches packet+ A4, returns packet/NULL. Owner's s32 return is stale. This provider has no output argument.
- func_0046b000: src/Kernel/sdkSpr.c:172-197 is u8*(const char*), not s32(u32). Calls logging, reloads mutable allocator D_008873F4[0](1,0x240,0x40000), sets state1, copies the filename, obtains archive payload through func_00455f70(name,&out), and links sprite node. Its out local is not read when lookup fails; callback has no reason to initialize a dummy out local of its own.
- func_0046a750: src/h_maestro.c:309-312 is u32(s16*), *state==5, not s32(s32). Candidate preserves the actual node pointer input.
- func_0046a770: src/promoted/code1_0046.c:1574-1587 is u8*(char*), not s32(u32). Walks existing sprite list by name, returns matching pointer/NULL. Table entries12..15 are shared/global resources; panel destructor separately destroys only slots0..11 (src/promoted/code1_0020.c:479-501).
- func_00452560: u32(void*), not u8*(s32). See input provenance above. Constructor declaration func_00194470(u32,u32) is additionally stale versus its current s32,s32 definition; values0x508/0x40 are in-range so no callback body dependency. Owner func_0043f9c8 is the memset address according to retail constructor; its current void return spelling is not repaired here because this assignment is a scratch callback recovery, not an adjacent-provider cutover.

Actual table bytes and invalid-input caveat (NO fabricated fallback)
Used readelf only to establish retail ELF LOAD mapping: vaddr0x100000, file offset0x80. Read16 little-endian words at retail0x626720 and pointed-to strings; the next bytes at0x626760 are a string, not another pointer entry. Thus the resource table span is exactly0x40 bytes at this boundary:
0 b_p_k01.spr; 1 b_p_k02.spr; 2 b_p_k03.spr; 3 b_p_k04.spr;
4 NULL; 5 b_p_k06.spr; 6 b_p_k07.spr; 7 b_p_k08.spr;
8 battle_01.spr; 9 b_cammand01.spr; 10 corsol_01.spr; 11 b_badsta01.spr;
12 init/c_equip_01.spr; 13 init/c_equip_help_02.spr;
14 init/c_top_01.spr; 15 init/noiz.spr.
Entries0..11 non-NULL names have battle/panel/ prefix. Config resolves iGpffffa578 at0x763668; bytes there are "%s %d". The pointer word at0x763660 (iGpffffa570) is0x626760 ->battle/panel/b_p_k01_op.spr. D_00626780 is "btlPanel.c"; D_00626790/B0 are battle/panel/btlpanel.bin and battle/panel/btlpnlop.bin.
There is NO undefined incoming register or uninitialized-local path in the target itself: all live saved regs have defined origins, work is constructor-zeroed, resolver receives field34 explicitly, done is initialized by retail, and both returns explicitly set v0. Neither candidate invents a result for a missing machine input.
However, arbitrary corrupted/out-of-contract work cannot be made safe while preserving retail behavior. In particular if signed idx==4, slot4==NULL, and func_0019ef90(0,5)!=NULL, retail002029E8..00202A08 loads table[4]==NULL and calls func_0046b000(NULL). That provider copies the name through strcpy at00442830 without a NULL guard. Reachability exclusion would require a gameplay invariant that no type0 packet with actor id5 enters this list; the inspected provider itself does NOT prove that invariant. Candidates deliberately preserve this branch, not substitute an asset/skip/success. A guarantee of defined ordinary-C behavior for this arbitrary state is BLOCKED on that invariant; it is not an undefined-register blocker for valid callback inputs. Likewise negative/large indices access the slot before the bounds test, and missing parent task/work or allocator success is not repaired with fabricated fallback behavior.

*/

/* Replace src/Battle/btlPanel.c lines 16-25 with this fragment.
 * HCdvd is the existing tag defined by include/h_cdvd_internal.h.
 * The func_ spellings below preserve this owner's linker names; the retail
 * providers at 00106330/00454bd0/004553c0 are datGetFlag/H_Cdvd_Destroy/
 * H_Cdvd_IsFileLoaded respectively.
 */
typedef struct HCdvd HCdvd;
s32 func_00440b68(const char* message, ...);
u8* func_00454a60(u8* param, s32 mode);
u32 func_00454bd0(HCdvd* cdvd);
u32 func_004553c0(HCdvd* cdvd);
u32 func_00106330(s32 bit);
u8* func_0019ef90(s32 type, s32 id);
u8* func_0046b000(const char* name);
u32 func_0046a750(s16* nodeState);
u8* func_0046a770(char* name);
u32 func_00452560(void* task);

// FUN_00202890
#pragma push
#pragma opt_propagation off
s32 func_00202890(void* arg0)
{
    BtlPanel* panel = (BtlPanel*)arg0;
    u8* recs = (u8*)func_00452560((void*)panel->field34);
    s16 done = 0;
    s32 idx;
    u8* rec;

    switch (panel->state) {
    case 0:
        rec = panel->records;
        if (rec == NULL) {
            if (func_00106330(0x1438) == 0) {
                func_00440b68(&iGpffffa578, D_00626780, 0x532);
                panel->records = func_00454a60(D_00626790, 1);
            } else {
                func_00440b68(&iGpffffa578, D_00626780, 0x534);
                panel->records = func_00454a60(D_006267B0, 1);
            }
            goto check;
        }
        if (func_004553c0((HCdvd*)rec) != 0) {
            panel->state = 1;
        case 1:
            idx = panel->index;
            rec = *(u8**)(recs + idx * 4 + 0x2C);
            if (rec == NULL) {
                if (idx < 8) {
                    if (func_0019ef90(0, (idx + 1) & 0xFFFF) != NULL) {
                        if (func_00106330(0x1438) == 0 || idx != 0) {
                            *(u8**)((u32)(idx * 4) + (u32)recs + 0x2C) =
                                func_0046b000((const char*)D_00626720[idx]);
                        } else {
                            *(u8**)((u32)(idx * 4) + (u32)recs + 0x2C) =
                                func_0046b000((const char*)iGpffffa570);
                        }
                    } else {
                        *(u8**)((u32)(idx * 4) + (u32)recs + 0x2C) = NULL;
                        panel->index++;
                    }
                } else if (idx < 0xC) {
                    *(u8**)((u32)(idx * 4) + (u32)recs + 0x2C) =
                        func_0046b000((const char*)D_00626720[idx]);
                }
            } else if (func_0046a750((s16*)rec) != 0) {
                if (++panel->index == 0xC) {
                    func_00454bd0((HCdvd*)panel->records);
                    panel->records = NULL;
                    done = 0xC;
                }
            }
        }
        break;
    default:
        break;
    }
check:
    if (done == 0xC) {
        for (idx = 0xC; idx < 0x10; idx++) {
            *(u8**)((u32)(idx * 4) + (u32)recs + 0x2C) =
                func_0046a770((char*)D_00626720[idx]);
        }
        *(u32*)recs |= 1;
        return 1;
    }
    return 0;
}

#pragma pop
