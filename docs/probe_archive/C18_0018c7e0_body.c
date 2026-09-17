/* func_0018c7e0 @ 0x0018c7e0 / owner src/promoted/code1_0018.c
   asm asm/nonmatchings/code1_0018/func_0018c7e0.s / window 1776B
   floor candidate: object 1752B (438 instrs) / retail 1760B executable (440 instrs)
   fndiff 40 differing words (reloc-masked) / fnalign 25 edit instructions (+4 reloc-only)
   relocations 19 R_MIPS_26 jal (0015a160, 001060b0 x2, 001060c0 x3, 00110960 x2,
     00106330 x2, 0045a3e0 x2, 0014bdb0 x6, 004598e0 x1), all resolved to retail targets.
   retail suffix after emitted prefix is zero alignment (4 nops at 0x8CEC4..0x8CECC).
   Residual: one dead slti 0xA0 at 0x8CE68 (with its b/+nop at 0x8CE60) plus the
   branch-displacement consequences (all b/beqz targets off by 2-3). No register
   differences remain; frame 0x50 with s3=dungeon/date2, s1=date/phase, s2=w1, s0=res.
   Levers that worked, all measured:
   - truthful s32/u32 for func_00110960(s32,u32) per src/promoted/code1_0011.c
     (owner had s64/s32; s64 first param forced dsll32 0 on dungeon/date moves).
     File-scope fix verified isolated: 53 MATCH / 9 ASM before and after.
   - uniform s32 for dungeon/date/w1/phase/res (s32 date still gives dsll32 16
     for (s16)func_001060b0, s32 w1 still gives dsll32 24 for (s8)func_00110960,
     s32 res still gives dsll32 16 for (s16)res; s64 phase/dungeon gave extra
     dsll32 0 on the &0xFF / s32->s64 moves).
   - direct *(s32*)iGpffff9db0 reads (no cached mode/sub locals) to reproduce
     retail lw-then-bne scheduling; mode-7 handler calls 001060c0 before the
     sub==2/3 split as retail does (IDA confirms call-before-branch).
   - separate s32 w2 temp for the second (dungeon-nonzero-else) weather so the
     first w1 stays saved ($s2) and the second stays temp ($v1) as retail does;
     reusing one var forced both saved and swapped dungeon/w1 ($s2/$s3).
   - switch (w2) with cases in source order 0,1,3,2,4 to get retail compare
     chain 4,2,3,1,0 (reverse-label rule) and bodies 0x16 before 0x17 in source
     order as retail lays them (CA98 before CAA4). if/else-if with empty arms
     gave bne-inline layout with swapped bodies.
   - call order exactly as retail: date->w1->phase before the iGp guard, t before
     sub split, dungeon/date2 reuse of $s3, phase ($s1) preserved to CC80.
   Semantic review: IDA/Ghidra/retail agree on CFG; dungeon==0 vs !=0 via bnez,
   mode/sub dispatch via bne/beq chains, dungeon thresholds via slti chain
   (<6/==20,40,60,80,100,120,140 then <20,40,60,80,100,120,140,159), final
   blez res. (s8)w1==0 guard with 15-disjunct mode/sub OR to CC80, then
   0014bdb0(7,27,8,31) with phase 3/4 vs phase==4 with 0014bdb0(9,1,9,7)/
   (9,8,10,5). No UB, no uninit, no omitted args, no fake returns; all callees
   use canonical widths ((s16)date, (s8)w, &0xFF phase, (s16)res). Dead slti 0xA0
   is the only structural wall: no truthful spelling reproduced an unreachable
   slti with its skipping b; forcing it would need synthetic dead code, which
   the acceptance rules reject. Banked as floor; production stays INCLUDE_ASM.
   Measured with: python tools/fnalign.py src/promoted/code1_0018.c func_0018c7e0
   --candidate <this body> (40W/25E) and
   python tools/probe_search.py src/promoted/code1_0018.c func_0018c7e0
   --candidate <this body> --declarations 200 (120 orders, best 40W/25E).
   SHA-256 of this archive body and of src/promoted/code1_0018.c recorded in
   batch evidence; re-measure after any edit. */
s32 func_0018c7e0(void) {
    s32 dungeon;
    s32 date;
    s32 w1;
    s32 phase;
    s32 res;

    dungeon = func_0015a160();
    res = 0;
    date = (s16)func_001060b0();
    w1 = (s8)func_00110960(date, func_001060c0() & 0xFF);
    phase = func_001060c0() & 0xFF;
    if (iGpffffb264 == 1) {
        return 0;
    }
    if (func_00106330(0x3E0) == 1) {
        func_0045a3e0(0x2C, 1);
        return 1;
    }
    if (dungeon == 0) {
        if ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 3)) {
            res = 0x14;
        } else if ((*(s32 *)iGpffff9db0 == 7) && ((*(s32 *)(iGpffff9db0 + 4) == 2) || (*(s32 *)(iGpffff9db0 + 4) == 3))) {
            s32 t;
            t = func_001060c0() & 0xFF;
            if (*(s32 *)(iGpffff9db0 + 4) == 2) {
                if (func_0014bdb0(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            } else if ((*(s32 *)(iGpffff9db0 + 4) == 3) && (((t & 0xFF) == 3) || ((t & 0xFF) == 4))) {
                if (func_0014bdb0(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            }
        } else if (((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 4))) {
            res = 0;
        } else {
            s32 t2;
            s32 w2;
            dungeon = (s16)func_001060b0();
            t2 = func_001060c0() & 0xFF;
            w2 = (s8)func_00110960(dungeon, t2);
            switch (w2) {
            case 0:
                res = 0x16;
                break;
            case 1:
                break;
            case 3:
                break;
            case 2:
                res = 0x17;
                break;
            case 4:
                break;
            }
            if (func_00106330(0x8A) == 1) {
                res = 0x18;
            }
        }
        if (((s8)w1 == 0) && (((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xE)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xF)) || ((*(s32 *)iGpffff9db0 == 7) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 4)) || ((*(s32 *)iGpffff9db0 == 0xB) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xD) && (*(s32 *)(iGpffff9db0 + 4) == 8)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 3)))) {
            if ((func_0014bdb0(7, 0x1B, 8, 0x1F) == 1) && (((phase & 0xFF) == 3) || ((phase & 0xFF) == 4))) {
                res = 0;
            } else if ((phase & 0xFF) == 4) {
                if (func_0014bdb0(9, 1, 9, 7) == 1) {
                    res = 0;
                } else if (func_0014bdb0(9, 8, 0xA, 5) == 1) {
                    res = 0;
                }
            }
        }
    } else if ((dungeon < 6) || (dungeon == 0x14) || (dungeon == 0x28) || (dungeon == 0x3C) || (dungeon == 0x50) || (dungeon == 0x64) || (dungeon == 0x78) || (dungeon == 0x8C)) {
        res = 0x1B;
    } else if (dungeon < 0x14) {
        res = 0x1C;
    } else if (dungeon < 0x28) {
        res = 0x1D;
    } else if (dungeon < 0x3C) {
        res = 0x1E;
    } else if (dungeon < 0x50) {
        res = 0x1F;
    } else if (dungeon < 0x64) {
        res = 0x20;
    } else if (dungeon < 0x78) {
        res = 0x21;
    } else if (dungeon < 0x8C) {
        res = 0x22;
    } else if (dungeon < 0x9F) {
        res = 0x23;
    }
    if (res > 0) {
        func_0045a3e0((s16)res, 1);
        return 1;
    }
    func_004598e0(0x1E);
    return 0;
}
