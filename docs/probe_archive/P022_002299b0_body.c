/*
Exact payload-contract recovery, integrated in src/promoted/code1_0022.c.
object_size=644; window=656; normalized_diff=0; fully_resolved_code_relocations=29; resolved_differing_bytes=0; zero_tail_bytes=12.
The old 16-byte data plus 16-byte padding holder is replaced by the actual u32 payload[8]. func_001f0a10 initializes every byte and func_001f36e0 copies all 32 bytes before local lifetime ends.
Scoped opt_propagation off retains the already measured initial global load/store sequence.
The sound-provider requested-extent caveat below is preserved; no unconditional whole-provider memory-safety claim is made.
Verification is actual owner compilation and complete relocation resolution, not game execution.

func_002299b0 contract recovery
==============================
Scope: retail [0x002299B0,0x00229C40). Main integrated the real eight-word payload and verified the actual owner: 644/656 bytes, 29 resolved relocations, zero differing bytes, twelve zero tail bytes.

CALLER ABI AND REAL REGISTRATION
- The sole consumed input is a live BtlAction-like pointer in a0. The target reads its u64 identity at +0 and its unit pointer at +0x30. No other incoming argument, saved register, floating register, or uninitialized stack word is consumed. The initializer has no consumed return value: fac80 overwrites v0 with 1 immediately after jalr.
- The named func_0022dc70 was read in full (0x22DC70..0x22E4EC, 589 lines). It registers other callbacks, not func_002299b0. In particular, 0x22E150..0x22E168 registers 229da0/22a6b0, 0x22E258..0x22E270 registers 22a730/22abd0, and 0x22E2C0..0x22E2D8 registers 22acb0/22ad40. A direct dc70 -> 2299b0 path must not be invented.
- The actual registration is func_0022d600: 0x22DA88 loads initialize=2299b0, 0x22DA90 loads update=229c40, 0x22DA98 sets a2 to s0, and 0x22DA9C calls fae60. d600 initially copies its second input (a1) into s0 at 0x22D618. Its relevant paths require battle flags bit 0x200000 (0x22D624..30), unit genus 1 (0x22D638..44), and unit ID 0x10F or 0x106 (0x22D674..684).
- For ID 0x10F, s0 remains the incoming action and control enters 0x22DA10. For ID 0x106, the path requires nonzero signed battle+C34, negative *hpDelta (0x22D9B8..CCC), a successful lookup of unit (1,0x10F) (0x22D9D4..9EC), applies the HP delta, then converts that unit to its action through b0c80 (0x22DA00..A0C). Both converge at 0x22DA10. C34 selects percentage 40,60,100; d9740(action,100-percentage) is tested, falling back to unit data HP <2 at 0x22DA70..A80 before registration.
- fae60's complete ASM 0x1FAE60..7C stores a0/a1/a2 at battle+B40/B44/B48. fac80 (complete ASM 0x1FAC80..D0C) checks flags 0x200000, requires 22bd00()==0 and nonnull B40, loads a0 from B48 at 0x1FACC8 and invokes B40 at 0x1FACCC; at 0x1FACD4 it returns 1. Thus the callback argument is the actual registered action, not the fac80 argument or any inferred saved-register contents.

TARGET STATE AND PROVIDERS
1. Battle accesses use the current owner DAT_0076449c pointer (retail gp-0x4C54). +C34 is u16, +C u32, +18 u16. They are reloaded across provider calls, not cached past mutable global effects. a03b0 receives the original action while a0 is still live at 2299F4. Its complete ASM 1A03B0..1A05EC confirms it reads the action's u64 UID and creates/publishes packets based on battle+18 bits; it clears +18 and clears +C bit 0x400000 at 1A05B0..5CC. It is not a no-argument helper, nor can its effects be folded into the target flag stores. Corrected d3700 pointer-return contract from Main remains required by that provider.
2. d3d50(0): ASM 1D3D74..88 allocates 0x638 bytes, initializes flags +630=0, refcount +632=1, value +634=0 at 1D3DB8/3DD8..3DE0, and returns the actual allocation in v0. Current owner represents it as s32; body preserves that established target ABI spelling.
3. 22ced0(0xC): ASM/code1.s 22CED8..22CEEC loads battle+B90, masks selector to 16 bits, supplies null optional size output, and calls 455ea0; 22CEF0..22CEFC leaves its pointer result in v0. 455ea0's complete ASM 455EA0..455F64 reads archive+110, skips aligned archive members, writes an optional s32 size, and returns selected-header+0x100 at 455F44. This pointer refers to archive-owned bytes, not a local object. d3ea0 copies 0x630 bytes from it and resolves formation resources; source must contain that formation entry. Current direct owner read at lines 2908..2911 ALREADY has the explicit return. CSP returned stale pre-correction text; do not act on that stale result.
4. d3ea0(formation, entry): current btlFormation.c 623..658 copies exactly 0x630, walks two formation groups, replaces resource fields, then sets formation+630 bit2. The independent refcount at +632 is retained.
5. b1510(): complete ASM 1B1510..153C selects the first pointer in battle+2CC if nonnull, otherwise first pointer in battle+29C, and returns that pointer. The target null-check is real, then reads/writes its u16 +18. Current owner carries the return as s32 and explicitly casts to u8*; no fabricated scalar result is used.
6. bc920(action,0x2D): canonical provider btlCameraCreateSetStatePacket(BtlAction*,u16) returns BtlPacket*. ASM BC938..95C requests work size8 with packet type0x200, sets update callback +6C, stores action at work+0 and u16 state at work+4. Target stores original u64 action UID at packet+60 and publishes on queue0. No immediate camera update or local vector result is implied.
7. 19bbe0(unit,0xFFFFFF,0x50,0,4,0): current typed provider is BtlPacket*(BtlUnit*,u32,s16,s16,u8,u8). ASM 19BC18..64 requests work size0x14/type0x112, stores unit at work+0, color at +8, signed timing halfwords +C/+E, mode/flags bytes +10/+11. The target's literal timings fit their actual widths; no float/int timing conversion is present. Publish on queue1 with original action UID.
8. 19ef90(1,0x106): complete ASM 19EF90..EFDC masks both inputs to 16 bits, starts from battle+17C+group*8, follows unit+A68, compares u16 unit+A4, returns matching unit or null. The null path retains followup=original action and skips the payload+animation creation.
9. b0c80(unit): complete ASM 1B0C80..CBC traverses battle+174 via action+450, compares action+30 to unit, and returns the action or null. On successful unit lookup, retail assumes that unit has a live action: it adds NO second null guard. body preserves this engine-state precondition rather than inventing fallback behavior. Its +30 is read by target and its pointers are consumed by the effect provider.
10. f0a10(out): ASM/code1.s 1F0A18..24 calls memset(out,0,0x20). Current source promoted/code1_001f.c 362..364 agrees. The sole local payload is u32 payload[8], precisely 32 bytes, naturally aligned for its u32 +8 store. It is not RwV3d, not 16 or 24 bytes plus invented padding, and is never read before initialization. payload[2]=0x100000 corresponds exactly to target 229AF8. All other bytes remain zero.
11. f36e0(followup,followup,payload,1,1): complete ASM 1F36E0..37AC and btlTarget.c 344..360 request work 0x2C/type0x700, store two action pointers at +0/+4, memcpy exactly0x20 bytes into +8..27, store halfword arguments at +28/+2A, and return the allocated BtlPacket*. The local pointer is not retained. The target sets packet+48 u16 to0x20, sets +60 u64 UID, publishes queue1. Later execution reads the owned copy, so local lifetime ends safely.
12. 199ee0: canonical implementation is btlUnitCreateAnimPacket(BtlUnit*,u16 id,u16 blendFrameCount,f32 speed,u16 mode), returning BtlPacket*. ASM 199EFC..9F08 captures a0=unit,a2=blend,f12=speed,a3=mode. For id9 the normal path requests work0x10/type0x100 at 199F80..88; it writes unit+0,id+4,blend+6,speed+8,mode+C at 199FB8..9FE0. Current owner uses the older raw declaration (unit,id,blend,mode,speed), which delivers the same independent integer/FPR ABI on this target; body retains its established spelling and calls (unit,9,0,0,1.0f). If Main canonicalizes that declaration globally, migrate every owner call to (unit,id,blend,speed,mode) and BtlPacket* return; do not reorder only the arguments without changing the declaration. Target sets +48=0x20 and +60=original UID and publishes queue0. Float 1.0f is literal 0x3F800000, not a computed or converted duration.
13. f81f0(2,D_006354B0): BtlPacket* return is explicit at 1F8254. Target sets +48=2 and publishes queue1 without setting +60: retain allocator-zero default UID, do NOT add original-action dependency. The source string read from retail ELF is EM10F_END.ADX (13 bytes before NUL). The target does not copy this string locally. See provider extent caveat below.
14. d6240(formation, originalUnit, followupUnit,0/1,0x200): ASM 1D6270..2D0 allocates work0x20/type0x301, clears packet+47 bit0x10, installs init/update/destroy/completion callbacks, writes 32-bit formation and two units at work+0/+4/+8, u16 mode+C, flags+1C. It returns the actual packet pointer. Each receives original-action UID and publishes queue2. Mode0 precedes mode1; not a loop or combined packet.

PACKET IDENTITIES AND LIFETIME
- 194470 complete ASM: total allocation is workSize+0x90 at 194490, allocator call1944B8, memset of the whole extent1944D0; workData=packet+0x90 for positive workSize at 194554..558. Packet+48 and +60 accesses are in allocated header storage. Default wait-condition types are initialized, not fabricated by the target.
- 194590 complete ASM: obtains UID from192560 then stores u64 at packet+58 (1945B0); invokes nonnull init callback (1945D0..E4); links packet into queue selected by low byte (1945E8..19463C); returns u64 UID with ld at194640. Target ignores that return and does not read +58. Every target dependency store is an actual ld/sd-equivalent u64 copy from original action+0 into packet+60. No narrowing through s32, no dependency inferred from return pointers, no accidental capture of low32 identity.
- Publication does not destroy these packets. In particular, d6240's init callback d5f60 calls d40d0 (current source795..813; retail d40d0 increments formation+632 at1D40D8..E0), so after both queue2 publications the creation refcount1 has two packet references. Final d3e00 releases only the initializer's reference. Each packet's d61e0 later releases its own reference (source896..902). Keeping final d3e00 AFTER both publications is load-bearing.

PROVIDER EXTENT CAVEAT / REQUIRED RESOLUTION
- f81f0 ASM 1F8210 obtains strlen, 1F8218 passes length+8 to194470, and 1F824C strcpy writes length+1 bytes starting work+8. For the actual 13-character literal this requests0x15 work bytes, writes0x16, and requests total packet0xA5 while writing a terminating NUL at packet+0xA5. The current btlSound.c315..329 does the same. The logical requested extent is one byte short; no target-local enlargement fixes it.
- This is not yet proof of a physical overrun: custom allocator rounding can supply more bytes. The allocator function table starts zero in the ELF and is installed dynamically. ASM 3E1B8C..1BB8 supports a custom table; the default branch3E1BD8..1BE8 installs3e1ae0. I did not establish the active allocator's minimum returned object extent. Main must retain/prove the real allocator rounding contract or correct f81f0's allocation to cover the copied NUL (with an explicit provider-matching decision). Do not fabricate padding or a fake allocation result in this initializer. This caveat blocks an unconditional whole-provider memory-safety claim, not the target's completely initialized0x20 local payload or its reconstructed sequencing.
- All other directly consumed provider results and output extents are backed by actual source/ASM above. No missing local-result initialization, incoming saved-register dependency, or irreducible undefined local C was found. Standard live-action/unit and successful allocation preconditions are the same preconditions as retail; they are not new target guards.
*/
#pragma opt_propagation off
// FUN_002299B0
void func_002299b0(u8 *arg0)
{
    u8 *saved_arg0;
    u32 payload[8];
    s32 temp_17;
    u8 *var_16;
    u8 *temp_5;
    temp_5 = DAT_0076449c;
    *(s16 *)(temp_5 + 0xC34) = 0;
    saved_arg0 = arg0;
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(s32 *)(temp_3 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(u16 *)(temp_3 + 0x18) =
            (u16)(*(u16 *)(temp_3 + 0x18) | 0x23);
    }
    func_001a03b0((s64 *)saved_arg0);
    temp_17 = func_001d3d50(0);
    func_001d3ea0((int)temp_17, (u32)func_0022ced0(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001b1510();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2;
        temp_2 = func_001bc920(saved_arg0, 0x2D);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 0);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_0019bbe0((BtlUnit *)(*(u8 **)(saved_arg0 + 0x30)),
                              0xFFFFFF, 0x50, 0, 4, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 1);
    }
    var_16 = saved_arg0;
    {
        s32 temp_2;
        u8 *temp_2_5;

        temp_2 = (s32)func_0019ef90(1, 0x106);
        if (temp_2 == 0) {
            goto after_ef90;
        }
        var_16 = (u8 *)func_001b0c80(temp_2);
        func_001f0a10((u8 *)payload);
        payload[2] = 0x100000;
        temp_2_5 = (u8 *)func_001f36e0((s32)(u32)var_16, (s32)(u32)var_16,
                                      (void *)payload, 1, 1);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 1);
        temp_2_5 = func_00199ee0(*(u8 **)(var_16 + 0x30),
                                 9, 0, 0, 1.0f);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 0);
after_ef90:
        ;
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001f81f0(2, (const char *)D_006354B0);
        *(u16 *)(temp_2 + 0x48) = 2;
        func_00194590(temp_2, 1);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001d6240((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 0, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001d6240((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 1, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    func_001d3e00(temp_17);
}
#pragma opt_propagation on
