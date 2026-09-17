/* FUN_001ABBB0 floor (v7, fndiff 449, obj 2384B/window 2384B, frame -0x170 MATCH).
 * Target: src/promoted/code1_001a.c, func_001abbb0, retail 0x001ABBB0, window 2384B (0x950).
 * Draft: P4_UNIT_001ABBB0 (270 body lines, M2C candidate in src/generated/code1_001a.c:5839-6153).
 * Candidate: docs/probe_archive/C1A_001abbb0_body.c (this file, single-function body with measured pragma context).
 * Compiler: MWCCPS2 3.0.1 b210-060308, -O2 -Iinclude, #pragma opt_common_subs off, opt_propagation off, opt_loop_invariants on (push/pop around function).
 * Commands:
 *   python3 tools/probe_variants.py src/promoted/code1_001a.c func_001abbb0 --candidate v7=/tmp/cand_abbb0_v7.c
 *   python3 tools/fndiff.py <scratch> func_001abbb0 --addr 001abbb0
 *   python3 tools/verify.py src/promoted/code1_001a.c
 *   python3 tools/probe_archive.py docs/probe_archive/C1A_001abbb0_body.c src/promoted/code1_001a.c
 * Instruction result: obj 2384B/window 2384B (no overrun, no zero-tail padding to hide), reloc-masked differing words 449/596 (75%).
 *   Frame -0x170 and 10 saves (sd ra@0x90 + sq s0-s7+fp@0x00-0x80) verified identical to retail; prologue move/daddu/lh/ld verified to offset 52.
 *   First residual at offset 56: propagation-off `move $a0,$s4` before jal func_001a03b0 vs retail direct $a0 (1 word + shift cascade).
 *   Further residuals: aux masking dsll32/dsra32+andi vs retail andi, plus scattered s-reg rotation/scheduling/operand orientation through 30+ packet calls and 3-iteration loop. No bulk.
 * TU eligibility: unverified (production stays INCLUDE_ASM; no TU edit for floor, no build link run).
 * Retail identity: unverified (no linked image/ELF hashes for floor).
 * Semantic review:
 *   - Struct layout: arg0+0x00 s64 uid (*arg0), +0x30 unit pointer (s32/u8*), +0x6C u16 finalId (lhu), +0x6E s16 auxRaw (lh, sign-extended for off), +0x76 u16 curId array (lhu, idx*2), +0x78 u16 special (lhu).
 *   - Packets (raw offsets per file convention, as in func_001adb80/001ac700, not BtlPacket struct): +0x00 s8 type (4/5/11 sb), +0x08 s64 parentUID (sd), +0x10 s8 wait0 (4/11 sb), +0x18 s64 wait1 (sd), +0x47 u8 flags (&=~0x20 via lbu/andi/sb), +0x48 s16 delay (sh: scaleTmp+6, 0x18, 0x1C, 1), +0x58 s64 unk (ld/sd, callee-set for 1d5eb0/1f8000/etc.), +0x60 s64 actionUID (sd uid, except 1f7c20 packet with no 0x60 per retail).
 *   - Unit (from 19f5f0 pkt+0x30): +0xA64 s32 (sw 2317a0 result), +0x94/0x96 s16 (sh/lh copy from arg0+0x30 unit), +0x04/0x08/0x0C f32 (lwc1/swc1 copy, not lw/sw).
 *   - Callees canonical: s32 1d3d50(s32), u8* 00202010(s32,u16), u8* 1f3b20(u8*), s16 1991c0(u8*,s32,f32) (dsll32/dsra32 for s16 return), void 1b7060(u32,s32*,s32*), s32 1b7080/7090(s32), void 1b70a0(u32,s32*,s32*), u8* 1b7880/83f0/9560(s32...), u8* 1b9de0(u8*,u16,s32) (declared u8* to reproduce daddu $4,$2 after jal; canonical btlMain void leaves packet in $v0 via 194470, caller relies on leftover -- caveat, preserved for matching, not invented), void 1d69f0(s32,void*), u8* 1d5eb0(s32,void*,s32), u8* 1f8000(s32,s32), u8* 194b60(void), u8* 1f8140(s32), u8* 19f5f0(s32,s64,u16*) (1,curId,NULL), void 19ea60(u8*,s32) (masked curId), u8* 19b550(u8*,u16,s16) (0x7E), u8* 19c030(u8*,u16,u16) (0x10), u8* 00202400(s32,s32) (0x9F), u8* 1b7e20/99a0(s32), u8* 1b9360(s32,s32), BtlPacket* 1d6240(u32,u32,u32,u16,u32)/1f7c20(u16,u16,u16)/1d3900(u16)/1d3700(u16,u16)/ba090(s32)/7a10(u16) (cast to u8* for byte stores), s32 1f68e0(u8*), void 1b0800(u8*,u16) (0x1B/0x20), s32 2317a0(u8*,u16), s32 194590(u8*,u32), void 1a03b0(s64*), void 1d3e00(s32), u8* 199ee0(u8*,s32,s32,s32,f32) (8,6,0,1.0f), u8* bc920(u8*,s32) (0x15/0x2D), u8* 1f3870(s64*,s8) (0), u8* 1f5f70(u8*,u16,u32,u32,u32) (9,0,0,0,0).
 *   - Floats honest (EE ABI f12): 1.0f for 199ee0/1991c0, f32 for unit pos; Ghidra float mistypes ignored, disassembly (mtc1/lwc1/swc1) trusted.
 *   - GP: iGpffffb3ac+0xD40/0xC68 (lw -0x4C54(gp) + lw 0xD40/0xC68) and (u32)iGpffffb3bc+2U+off (lw -0x4C44(gp) + addu + lhu 0x2 + andi 0x40, off=(s32)auxRaw*4 with dsll32/dsra32+sll per retail); immediates/addends match retail per fndiff (reloc-masked jal/GPREL, no ! on offset lws); no TU/relocation ownership change, no full link needed for floor.
 *   - Saved58 = *(pktI_save+0x58) (1d5eb0 packet), not pktK (1d6240 packet) -- fixed vs v1/v2 (semantic bug, wrong parentUID); pktI_save kept live across 1f8000/1d6240/1f8140 per retail s1 lifetime.
 *   - No volatile/inline-asm steering; no omitted args; no incompatible empty-prototype casts; no moved observable loads across unknown-mutation calls (auxRaw/uid loads before 1a03b0 per retail order; 1a03b0 only reads *arg0 for 0x60 stores, verified in src/promoted/code1_001a.c:303-370).
 *   - Callers: no C callers in src/promoted (grep only generated M2C + INCLUDE_ASM); static-helper gate N/A.
 *   - Caveats: 1b9de0 u8* vs canonical void (leftover $v0 reliance); tail empty-if `if ((tailId!=2)&&(tailId!=3)&&(tailId!=1)) {}` preserves retail redundant branches both loading 0x20 (as in 001ac700 precedent, array-free, mask-literal style); loop goto (loop_test/loop_body/loop_end, (idx&0xFFFF)<3, curId==0 break) matches retail .L001AC304/.L001ABFE4/.L001AC318 physical CFG (shared exit, not duplicated tail).
 *   - Rejected: v1 no-pragmas (480, frame 0x1A0, 48 over), v2/v3 both-off no-loop (488/490, frame 0x160, 16 under, v1/v2 saved58 bug), v4 common-off/prop-on (490, 0x160), v5 common-on/prop-off (502), v6 both-on (480, 0x1A0), v8 both-on+loop (480), v9 common-off/prop-on+loop (490, 0x160), v10 common-on/prop-off+loop (502), v11 scoped prop on/off (449 same, pragma ignored for early move), v12/v13 s32 auxRaw (486/487, off missing dsll/dsra), v14 direct (u16)auxRaw (498). All via probe_variants, none reached 0.
 * WINS: frame -0x170 + saves verified (vs 0x1A0/0x160) via common-off+prop-off+loop-on (480->449, -31, exact obj size); s16 auxRaw for off dsll/dsra+sll; pktI_save fix; f32 pos; empty tail guard; loop goto CFG.
 * WALLS: early move (prop-off) vs retail direct (prop-on removes move but loses frame to 0x1A0); aux dsll/dsra+andi vs retail andi (direct worse); scattered coloring/scheduling, no bulk; signature census gate 4: no verified MATCH window with same 30-call order + loop + tail (zero hits, stop mining recipe).
 * Stop: measured floor (75% differing, no overrun); production stays ASM; do not call impossible.
 */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_001abbb0(s64 *arg0) {
    extern s32 func_001d3d50(s32 arg0);
    extern u8 *func_00202010(s32 arg0, u16 arg1);
    extern u8 *func_001f3b20(u8 *arg0);
    extern s16 func_001991c0(u8 *arg0, s32 arg1, f32 arg2);
    extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_001b7080(s32 arg0);
    extern s32 func_001b7090(s32 arg0);
    extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
    extern u8 *func_001b7880(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_001b83f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u8 *func_001b9560(s32 arg0, s32 arg1);
    extern u8 *func_001b9de0(u8 *arg0, u16 arg1, s32 arg2);
    extern void func_001d69f0(s32 arg0, void *arg1);
    extern u8 *func_001d5eb0(s32 arg0, void *arg1, s32 arg2);
    extern u8 *func_001f8000(s32 arg0, s32 arg1);
    extern u8 *func_00194b60(void);
    extern u8 *func_001f8140(s32 arg0);
    extern u8 *func_0019f5f0(s32 arg0, s64 arg1, u16 *arg2);
    extern void func_0019ea60(u8 *arg0, s32 arg1);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern u8 *func_0019c030(u8 *arg0, u16 arg1, u16 arg2);
    extern u8 *func_00202400(s32 arg0, s32 arg1);
    extern u8 *func_001b7e20(s32 arg0);
    extern u8 *func_001b9360(s32 arg0, s32 arg1);
    extern u8 *func_001b99a0(s32 arg0);
    extern s32 func_001f68e0(u8 *arg0);
    extern void func_001b0800(u8 *arg0, u16 arg1);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3bc;
    extern s32 func_002317a0(u8 *arg0, u16 arg1);
    s64 uid;
    s16 auxRaw;
    u16 aux;
    s32 handle;
    s32 outHi;
    s32 outLo;
    u8 workBuf[136];
    s32 firstDone;
    s16 scaleTmp;
    u8 *evPkt;
    u8 *holdJ;
    u8 *tailPkt;
    s64 cur58;
    u8 *tmp;
    s32 tmpS;
    u16 tailId;
    s32 off;
    s32 idx;
    u8 *pktI_save;
    auxRaw = *(s16 *)((u8 *)arg0 + 0x6E);
    uid = *arg0;
    func_001a03b0(arg0);
    handle = func_001d3d50(1);
    aux = (u16)(auxRaw & 0xFFFF);
    tmp = func_00202010(*(s32 *)((u8 *)arg0 + 0x30), aux);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 3);
    tmp = func_001f3b20((u8 *)arg0);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001f3870(arg0, 0);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    evPkt = func_00199ee0(*(u8 **)((u8 *)arg0 + 0x30), 8, 6, 0, 1.0f);
    *(s64 *)(evPkt + 0x60) = uid;
    func_00194590(evPkt, 0);
    tmp = func_001bc920((u8 *)arg0, 0x15);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 0);
    cur58 = *(s64 *)(evPkt + 0x58);
    scaleTmp = func_001991c0(*(u8 **)((u8 *)arg0 + 0x30), 8, 1.0f);
    func_001b7060(aux, &outHi, &outLo);
    tmp = func_001b7880(outHi, outLo, 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmpS = func_001b7080(aux);
    func_001b70a0(aux, &outHi, &outLo);
    tmp = func_001b83f0(tmpS, outHi, outLo, 0x10, 0);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001b9560(func_001b7090(aux), 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001b9de0((u8 *)arg0, aux, 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    func_001d69f0(aux, workBuf);
    pktI_save = func_001d5eb0(handle, workBuf, 0);
    *(pktI_save + 0) = 4;
    *(s64 *)(pktI_save + 8) = 0;
    *(s16 *)(pktI_save + 0x48) = (s16)(scaleTmp + 6);
    *(s64 *)(pktI_save + 0x60) = uid;
    func_00194590(pktI_save, 1);
    holdJ = func_001f8000(aux, 0);
    *(holdJ + 0) = 4;
    *(s64 *)(holdJ + 8) = *(s64 *)(pktI_save + 0x58);
    func_00194590(holdJ, 1);
    {
        u8 *pk;
        pk = (u8 *)func_001d6240((u32)handle, (u32)*(u8 **)((u8 *)arg0 + 0x30), (u32)*(u8 **)((u8 *)arg0 + 0x30), 0, 0);
        *(pk + 0) = 4;
        *(s64 *)(pk + 8) = *(s64 *)(pktI_save + 0x58);
        *(pk + 0x10) = 4;
        *(s64 *)(pk + 0x18) = *(s64 *)(holdJ + 0x58);
        func_00194590(pk, 2);
        tmp = pk;
    }
    {
        u8 *pk2;
        pk2 = func_001f8140(0);
        *(pk2 + 0) = 5;
        *(s64 *)(pk2 + 8) = *(s64 *)(tmp + 0x58);
        func_00194590(pk2, 1);
    }
    cur58 = *(s64 *)(pktI_save + 0x58);
    {
        u8 *pk3;
        pk3 = func_00194b60();
        *(pk3 + 0) = 4;
        *(s64 *)(pk3 + 8) = cur58;
        *(s16 *)(pk3 + 0x48) = 0x18;
        *(s64 *)(pk3 + 0x60) = uid;
        func_00194590(pk3, 1);
        tmp = pk3;
    }
    tailPkt = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD40), *(s32 *)((u8 *)arg0 + 0x30), 0, *(s64 *)(tmp + 0x58), 0x100);
    *(tailPkt + 0) = 4;
    *(s64 *)(tailPkt + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tailPkt + 0x60) = uid;
    func_00194590(tailPkt, 1);
    tmp = (u8 *)func_001f7c20(10, 2, 7);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = *(s64 *)(evPkt + 0x58);
    func_00194590(tmp, 1);
    firstDone = 0;
    off = ((s32)auxRaw) * 4;
    idx = 0;
    goto loop_test;
loop_body:
    {
        u16 curId;
        u8 *loopPkt;
        u8 *unit;
        curId = *(u16 *)((u8 *)arg0 + (idx & 0xFFFF) * 2 + 0x76);
        if (curId == 0) {
            goto loop_end;
        }
        loopPkt = func_0019f5f0(1, (s64)curId, (u16 *)0);
        unit = *(u8 **)(loopPkt + 0x30);
        *(s32 *)(unit + 0xA64) = func_002317a0(*(u8 **)(iGpffffb3ac + 0xC68), curId);
        func_0019ea60(unit, (s32)(curId & 0xFFFF));
        *(s16 *)(unit + 0x94) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x94);
        *(s16 *)(unit + 0x96) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x96);
        *(f32 *)(unit + 4) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 4);
        *(f32 *)(unit + 8) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 8);
        *(f32 *)(unit + 12) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 12);
        if (firstDone == 0) {
            u8 *r1;
            u8 *r2;
            r1 = (u8 *)func_001d3900(0);
            *(r1 + 0) = 4;
            *(s64 *)(r1 + 8) = cur58;
            *(s64 *)(r1 + 0x60) = uid;
            func_00194590(r1, 0);
            r2 = (u8 *)func_001d3700(1, 0xFFF);
            *(r2 + 0) = 4;
            *(s64 *)(r2 + 8) = cur58;
            *(s64 *)(r2 + 0x60) = uid;
            func_00194590(r2, 0);
            if ((*(u16 *)((u32)iGpffffb3bc + 2U + (u32)off) & 0x40) == 0) {
                u8 *r3;
                u8 *r4;
                r3 = func_001d7a10(5);
                *(r3 + 0) = 4;
                *(s64 *)(r3 + 8) = cur58;
                *(s64 *)(r3 + 0x60) = uid;
                func_00194590(r3, 0);
                r4 = func_001bc920((u8 *)arg0, 0x2D);
                *(r4 + 0) = 4;
                *(s64 *)(r4 + 8) = cur58;
                *(s64 *)(r4 + 0x60) = uid;
                func_00194590(r4, 0);
            }
            firstDone = 1;
        }
        {
            u8 *q1;
            u8 *q2;
            q1 = func_0019b550(unit, curId, 0x7E);
            *(q1 + 0) = 4;
            *(s64 *)(q1 + 8) = cur58;
            *(s64 *)(q1 + 0x60) = uid;
            func_00194590(q1, 1);
            q2 = func_0019c030(unit, curId, 0x10);
            *(q2 + 0) = 4;
            *(s64 *)(q2 + 8) = *(s64 *)(q1 + 0x58);
            func_00194590(q2, 1);
            {
                u8 *q3;
                u8 *q4;
                q3 = (u8 *)func_001d6240((u32)handle, (u32)*(u8 **)((u8 *)arg0 + 0x30), (u32)*(u8 **)(loopPkt + 0x30), 1, 0x100);
                *(q3 + 0) = 4;
                *(s64 *)(q3 + 8) = *(s64 *)(q2 + 0x58);
                *(q3 + 0x10) = 4;
                *(s64 *)(q3 + 0x18) = *(s64 *)(holdJ + 0x58);
                *(s64 *)(q3 + 0x60) = uid;
                func_00194590(q3, 2);
                tailPkt = q3;
                q4 = func_001f8140(1);
                *(q4 + 0) = 5;
                *(s64 *)(q4 + 8) = *(s64 *)(q3 + 0x58);
                func_00194590(q4, 1);
                if (((idx & 0xFFFF) == 0) && (*(u16 *)((u8 *)arg0 + 0x78) == 0)) {
                    u8 *q5;
                    q5 = func_00202400(*(s32 *)(loopPkt + 0x30), 0x9F);
                    *(q5 + 0) = 5;
                    *(s64 *)(q5 + 8) = *(s64 *)(q3 + 0x58);
                    *(s16 *)(q5 + 0x48) = 0x1C;
                    func_00194590(q5, 3);
                }
                {
                    u8 *q6;
                    q6 = func_0019bbe0(unit, (u32)-1, 0xC, 0, 3, 1);
                    *(q6 + 0) = 4;
                    *(s64 *)(q6 + 8) = *(s64 *)(q2 + 0x58);
                    *(q6 + 0x10) = 0xB;
                    *(s64 *)(q6 + 0x18) = *(s64 *)(q3 + 0x58);
                    *(s16 *)(q6 + 0x48) = 1;
                    *(s64 *)(q6 + 0x60) = uid;
                    func_00194590(q6, 1);
                    cur58 = *(s64 *)(q2 + 0x58);
                }
            }
        }
    }
    idx = (idx + 1) & 0xFFFF;
loop_test:
    if ((idx & 0xFFFF) < 3) {
        goto loop_body;
    }
loop_end:;
    {
        u8 *t1;
        u8 *t2;
        u8 *t3;
        u8 *t4;
        u8 *t5;
        t1 = func_001f5f70((u8 *)arg0, 9, 0, 0, 0);
        *(t1 + 0) = 0xB;
        *(s64 *)(t1 + 8) = *(s64 *)(tailPkt + 0x58);
        func_00194590(t1, 1);
        t2 = func_001b7e20(0x10);
        *(t2 + 0) = 4;
        *(s64 *)(t2 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t2 + 0x47) &= (u8)~0x20;
        *(s64 *)(t2 + 0x60) = uid;
        func_00194590(t2, 1);
        t3 = func_001b9360(0x10, 0);
        *(t3 + 0) = 4;
        *(s64 *)(t3 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t3 + 0x47) &= (u8)~0x20;
        *(s64 *)(t3 + 0x60) = uid;
        func_00194590(t3, 1);
        t4 = func_001b99a0(0x10);
        *(t4 + 0) = 4;
        *(s64 *)(t4 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t4 + 0x47) &= (u8)~0x20;
        *(s64 *)(t4 + 0x60) = uid;
        func_00194590(t4, 1);
        t5 = (u8 *)func_001ba090(8);
        *(t5 + 0) = 4;
        *(s64 *)(t5 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t5 + 0x47) &= (u8)~0x20;
        *(s64 *)(t5 + 0x60) = uid;
        func_00194590(t5, 0);
    }
    func_001d3e00(handle);
    if (func_001f68e0((u8 *)arg0) != 0) {
        func_001b0800((u8 *)arg0, 0x1B);
        return;
    }
    tailId = *(u16 *)((u8 *)arg0 + 0x6C);
    if ((tailId != 2) && (tailId != 3) && (tailId != 1)) {
    }
    func_001b0800((u8 *)arg0, 0x20);
}
#pragma pop
