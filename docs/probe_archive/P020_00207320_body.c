/* Floor: 72 differing words (fndiff reloc-masked) / 78 verify nd over 111 fnalign edits (plus 3 reloc-only), 502
   emitted instructions against retail's 502 (equal). Object 2008B / window 2016B: 8B zero-alignment tail,
   size-exact modulo tail. Width pass fixed three defects (135 -> 111 edits, pairs 4 -> 2 = retail):
   (1) func_0010b6f0 s8 -> u16 (dsll32/dsra32 24 -> 16); (2) case-6 load after func_001f0620 call, no hoisted
   lh/pair; (3) (s32)(func_001ef720(1,0) & 0xFFFF) < 2 flips sltiu -> slti. Outer dispatch is if/else-if chain,
   inner dispatch on *(s16 *)(arg0+4) is jump table with 3/7/2/0 arms sharing return 4. List counter stays 32-bit
   with explicit & 0xFFFF (andi).
   WALL: saved-register rotation. Retail arg1=$s0, arg2=$s1, arg0=$s2; this build arg1=$s1, arg2=$s0, arg0=$s2;
   frames/saves otherwise identical (0x40, ra+s0/s1/s2). 250 declaration orders, all pragmas, local aliases
   measured pre-fix; only other diff is 0x18C store one insn later (pair before sh vs sh first). Removing
   opt_loop_invariants costs 6 edits, bracket stays.
   Measured 2026-09-17 (Board00207320, method Board001f4e50): baseline via recon_probe single variant
   obj=2008/2016 nd=78; via measure_guarded fndiff nd=72. opclass: no surplus for this floor (owner's 6 other
   floors carry surpluses; this one scanned clean). fnalign 111+3, first diffs off 24/28 move $s1/$s0 swap
   then s0/s1-displaced lh/lw cascade (72,196,260,304...).
   Neighbour spellings first (all vs canonical defs): A 00202c60 s32->s16 nd78; B 001ef720 u32->s32 nd78;
   D 001f0620 s32->s64 nd78; C 0023dfe0 s16(s32)->s32(u8*) COMPILE_ERROR (int->u8* without cast);
   E 00117780 s32->u8* COMPILE_ERROR (ptr->s32 without cast); F/G combined COMPILE_ERROR; honest
   C_honest (u8** load + s32 def) nd78; E_honest ((s32) cast + u8* def) nd78; H_combined_honest nd78.
   fndiff-driven (2, total 12 incl. neighbours): P1 decl-reversed count/sub/mode/ui/entry/panel nd88 (+10);
   P2 <2 -> <=1 nd78 neutral. Gates: obj 8B PASS (tail-exact); nd 72/78 >25 => archive + leave guard.
   Status NONMATCHING, production INCLUDE_ASM. No waiver (no pragma/volatile change). Scoped lint 0 errors.
   Eye-check: no volatile/asm in body. Owner src/promoted/code1_0020.c unchanged (146 scanned, 135 MATCH, 11 ASM).
*/
#pragma opt_loop_invariants on
s32 func_00207320(u8 *arg0, u8 *arg1, u8 **arg2)
{
    extern s32 func_001f0620(u8 *arg0, s32 arg1);
    extern void func_001f56d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u32 func_001ef720(s32 arg0, s32 arg1);
    extern s16 func_0023dfe0(s32 arg0);
    extern s32 func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u16 func_0010b6f0(void);
    extern void func_00202c60(u8 *arg0, s32 arg1, s16 arg2, void *a, void *b, void *c, void *d, u8 *arg7);
    extern void func_00202e60(u8 *arg0, void *arg1);
    extern void func_002019f0(u8 *arg0, s32 arg1);
    extern void func_00208a50(void);
    extern void func_00208b00(void);
    extern void func_00208d00(void);
    extern void func_00208fd0(void);
    extern void func_002090d0(void);
    extern void func_00209140(void);
    extern void func_002091f0(void);
    extern void func_00209370(void);
    extern void func_00209640(void);
    extern void func_00209740(void);
    extern void func_002097b0(void);
    extern void func_00209870(void);
    extern void func_002099c0(void);
    extern void func_00209bc0(void);
    extern void func_00209cd0(void);
    extern void func_0020a5d0(void);
    extern void func_0020a640(void);
    extern void func_0020aa70(void);
    extern void func_0020ac70(void);
    extern void func_0020ad70(void);
    u8 *panel;
    u8 *entry;
    u8 *ui;
    s32 mode;
    s16 sub;
    s32 count;

    if (*(s16 *)(func_00452560(*(s32 *)(arg1 + 0x5B0)) + 0xAA) < 2) {
        return 1;
    }
    if (*(s16 *)(arg1 + 0x14) != 0) {
        return 1;
    }
    mode = func_00202e70(arg0) & 0xFFFF;
    if (mode == 1) {
    if (*(s16 *)(arg0 + 4) != 3) {
        func_0045af60(0, 0, 0, 2);
    }
    *(s16 *)(arg0 + 4) = 3;
    *(s16 *)(arg0 + 2) = 0;
    } else if (mode == 4) {
    if (func_001f0620(*(u8 **)(arg1 + 0x178), 0xA) == 0) {
        return 1;
    }
    func_0045af60(0, 0, 0, 3);
    *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 0xA;
    if (func_00106330(0x38) != 0) {
        sub = 0x10B;
    } else {
        sub = 0x110;
    }
    *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = sub;
    return 4;
    } else if (mode == 5) {
    *(s16 *)(arg1 + 0x14) = -3;
    } else if (mode == 6) {
    *(s16 *)(arg1 + 0x14) = 3;
    } else if (mode == 2) {
    switch (*(s16 *)(arg0 + 4)) {
    case 3:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 1) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 1;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) =
            func_0023dfe0(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64));
        break;
    case 4:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 2) == 0) {
            if (func_00232710(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64), 8) != 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x90);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_0010a900(*(u16 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA4));
        func_00202c60(arg1 + 0x74, 4, *(s16 *)(arg1 + 0x1A4), func_00208a50,
                      func_00208b00, func_00208d00, func_002090d0, arg1);
        panel = arg1 + 0x74;
        *arg2 = panel;
        func_00202e60(panel, func_00208fd0);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 6:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 3) == 0 || *(s16 *)(arg1 + 0x5A6) == 0) {
            if (*(s16 *)(arg1 + 0x5A6) == 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x92);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_00202c60(arg1 + 0xA8, 4, *(s16 *)(arg1 + 0x5A6), func_00209140, func_002091f0,
                      func_00209370, func_00209740, arg1);
        panel = arg1 + 0xA8;
        *arg2 = panel;
        func_00202e60(panel, func_00209640);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 1:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 4) == 0) {
            if ((s32)(func_001ef720(1, 0) & 0xFFFF) < 2) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x93);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        count = 0;
        for (ui = *(u8 **)(iGpffffb3ac + 0x17C); ui != NULL; ui = *(u8 **)(ui + 0xA68)) {
            if (*(u16 *)(ui + 0xA4) != 1) {
                *(u8 **)(arg1 + (count & 0xFFFF) * 4 + 0x17C) = ui;
                count = (count + 1) & 0xFFFF;
            }
        }
        *(s16 *)(arg1 + 0x18C) = count;
        func_00202c60(arg1 + 0xDC, 3, (s16)count, func_002097b0, func_00209870,
                      func_002099c0, func_00209cd0, arg1);
        panel = arg1 + 0xDC;
        *arg2 = panel;
        func_00202e60(panel, func_00209bc0);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 5:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 5) == 0) {
            if (func_00232710(*(s32 *)(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30) + 0xA64), 8) != 0) {
                func_002019f0(*(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30), 0x91);
            } else {
                entry = *(u8 **)(arg1 + 0x178);
                if (!(*(u16 *)(entry + 0x18) & 0x400)) {
                    func_002019f0(*(u8 **)(entry + 0x30), 0x95);
                }
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s32 *)(arg1 + 0x5A8) = func_00117780(*(s32 *)(arg1 + 0x5B0), 0xF, 1, 8, 8);
        *(s16 *)(arg1 + 0x5AC) = -1;
        func_00202c60(arg1 + 0x144, 4, (s16)func_0010b6f0(), func_0020a5d0,
                      func_0020a640, func_0020aa70, func_0020ad70, arg1);
        panel = arg1 + 0x144;
        *arg2 = panel;
        func_00202e60(panel, func_0020ac70);
        *(s16 *)(arg1 + 0x10) = 0;
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) & ~4;
        return 3;
    case 7:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 6) == 0) {
            func_001f56d0(*(u8 **)(arg1 + 0x178), 5, 0, 0, 2);
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 6;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = 0;
        break;
    case 2:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 7) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 7;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = 0;
        break;
    case 0:
        if (func_001f0620(*(u8 **)(arg1 + 0x178), 0xA) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 0xA;
        if (func_00106330(0x38) != 0) {
            sub = 0x10B;
        } else {
            sub = 0x110;
        }
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = sub;
        break;
    default:
        break;
    }
    return 4;
    }
    return 1;
}
#pragma opt_loop_invariants off
