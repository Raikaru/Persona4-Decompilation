/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldData.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*DAT_008873EC[])(void *);

extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c, void *init,
                         void *close, u8 *buf);
extern char D_005F0A88[];
extern char D_005F0A70[];
extern char D_005F0AA0[];
extern char D_005F0AC0[];
extern char D_005F0AE0[];
extern char D_005F0AF8[];
extern char D_005F0B10[];
extern char D_005F0B30[];
extern char D_005F0B50[];
extern char D_005F0B70[];
extern char D_005F0B90[];
extern char D_005F0BB0[];
extern char D_005F0BD0[];
extern char D_005F0BF0[];
extern char D_005F0C10[];
extern char D_005F0C30[];
extern char D_005F0C50[];
extern char D_005F0C70[];
extern char D_005F0C90[];
extern char D_005F0CB0[];
extern char D_005F0CD0[];
extern char D_005F0CF0[];
extern char D_005F0D10[];
extern char D_005F0D30[];
extern char D_005F0D50[];
extern char D_005F0D70[];
extern char D_005F0D90[];
extern char D_005F0DB0[];
extern char D_005F0DD0[];
extern char D_005F0DF0[];
extern char D_005F0E10[];
extern char D_005F0E30[];
extern char D_005F0E50[];
extern char D_005F0E70[];
extern char D_005F0E90[];
extern char D_005F0EB0[];
extern char D_005F0ED0[];
extern char D_005F0EF0[];
extern char D_005F0F10[];
extern char D_005F0F30[];
extern char D_005F0F50[];
extern char D_005F0F70[];
extern char D_005F0F90[];
extern char D_005F0FB0[];
extern char D_005F0FD0[];
extern char D_005F0FF0[];
extern char D_005F1010[];
extern char D_005F1030[];
extern u8 D_005F1050[];
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern void func_00456150(u8 *arg0);
extern s32 func_00477f10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00442088(char *buf, const char *fmt, ...);
extern s32 func_0015cf70(void);
extern s32 func_00161510(void);
extern s32 func_004782b0(s32 arg0);
extern s32 func_004553c0(u8 *arg0);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_00454bd0(u8 *arg0);
extern s32 func_0015d000(u8 *arg0);
extern s32 func_001615a0(s32 arg0);
extern s32 func_0045b1c0(u8 *arg0, s32 arg1, void *arg2, void *arg3);
extern s32 func_0045b170(s32 arg0);
extern s32 func_004667d0(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
extern void func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern s32 func_0018c580(u8 *arg0);
extern s32 func_00452490(s32 arg0);
extern void func_0046d730(const void *msg, s32 id);
extern s32 D_007E3710[];
extern s32 D_007E3714[];
extern s32 D_007E3718[];
extern u8 D_007E3720[];
extern char D_00762FC8;
extern s32 D_00764364;
extern s32 iGpffffb268;
extern s32 iGpffffb278;
extern s32 iGpffffb27c;
extern s32 iGpffffb280;
extern s32 iGpffffb284;
extern s32 func_0015d730(u8 *arg0);



/* measured: func_0015d730 (retail 1048 instrs, 4208B). Baseline m2c-cleaned pointer loops + absolute log (lui/addiu for gp-0x6128) 2396 nd, 4232B (+6W, branch cascade); log-context scalar (&D_00762FC8, GPREL addiu like k_fldNpcTable D_00762F20) 2396->831, 4184B (-6W). Step 1 free pragma probes first: opt_loop_invariants/schedule/propagation/common_subs (4) tie at 831; full sweep (8 pragmas + levels, via pragma_sweep) banked 166 tie (common_subs 757, schedule 871, levels 776-980 fail). Step 2 subscript form: loops sll/addu/lw-store-via-p (2 instr, addu $s3+lw/sw $3C) -> row/subscript (sll/addu/addiu/lw via $v0+$s3, sw ($s3), micro-verified 2->3 instr matching retail addu/addiu/lw) 831->498 (rowReuse/subscript tie, 4196B, 1049/1049 size-equal); for+subscript ((s32 *)work)[i+15/54/58] ties row (same codegen). Step 3 never hoisting what retail reloads: tail *(work+0x38) hoist (temp_3_2) vs reload tie at 923 (reload kept); hoisted call args (sz/src into $s0, move $a2) 923->2446 fail (retail lw $a2/$a1 after $a0 move, never hoist). Follow-ups R1 outer polarity: wrapped (false->case2, beqz 1 instr, incorrect logic) 498 vs else (false->return, correct) 923 vs early-return 1807 vs var/assign 1460 vs varElse 1445 (all with row); micro var+else gives sltu+beqz (2) vs direct beqz (1) but full spills +6W. R2 decl-orders (work/t18, t23/t18 swaps) tie at 923. R3 pragma on correct base (loop_invariants) tie at 923. Residuals (fnalign 33 edits +163 reloc-only, obj 4216B vs 4208B +2W): outer sltu $2,$0,$2+beqz (retail 2) vs beqz (1, +1W retail); first/second 0043f810 $a2-first (retail lw $a2 before $a0 move) vs $a0-first (arg-order floor); D_007E3720 $a2-first vs $a0-first (same floor); gp base+offset (addiu $s2+lw/sw, 2) vs direct lw/sw (1, hoist-vs-reload tradeoff, base scores 498 vs direct 1893 due to $s2 allocation). Correct-logic base (else+row+reload) parked. Production guarded. */
// FUN_0015D730 NONMATCHING
#ifdef NON_MATCHING
s32 func_0015d730(u8 *arg0)
{
    s32 sp1EC;
    char sp160[0x80];
    char spE0[0x80];
    char sp60[0x80];
    s32 temp_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    u16 *temp_2_2;
    u16 *temp_2_3;
    u16 *temp_2_4;
    u8 *work;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_2;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_3_2;
    u8 *row;

    work = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)work;
    switch (temp_3) {
    case 0:
        func_00440b68(&D_00762FC8, D_005F0A88, 0xE6);
        temp_2 = func_00454a60(D_005F0AF8, 0);
        func_00456150(temp_2);
        D_00764364 = func_00477f10(4, 0x7D0, *(s32 *)(temp_2 + 0x110), *(s32 *)(temp_2 + 0x118), 0);
        func_00442088(sp160, D_005F0A70);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x6B);
        *(u8 **)(work + 8) = func_00454a60(sp160, 1);
        func_00442088(spE0, D_005F0AA0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x89);
        *(u8 **)(work + 0x10) = func_00454a60(spE0, 0);
        func_00442088(sp60, D_005F0AC0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0xA9);
        *(u8 **)(work + 0x14) = func_00454a60(sp60, 0);
        *(u8 **)(work + 0x18) = (u8 *)func_0015cf70();
        *(s32 *)(work + 0x1C) = func_00161510();
        func_00440b68(&D_00762FC8, D_005F0A88, 0x124);
        *(u8 **)(work + 0x20) = func_00454a60(D_005F0B10, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x125);
        *(u8 **)(work + 0x24) = func_00454a60(D_005F0B30, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x128);
        *(u8 **)(work + 0x30) = func_00454a60(D_005F0B50, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x129);
        *(u8 **)(work + 0x34) = func_00454a60(D_005F0B70, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12A);
        *(u8 **)(work + 0x38) = func_00454a60(D_005F0B90, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12B);
        D_007E3710[0] = (s32)func_00454a60(D_005F0BB0, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12C);
        D_007E3714[0] = (s32)func_00454a60(D_005F0BD0, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12D);
        D_007E3718[0] = (s32)func_00454a60(D_005F0BF0, 0);
        func_0044ea90(D_005F0A88, 0xC5);
        temp_2_2 = (u16 *)D_008873F4[0](1, 0x414, 0x40000);
        *(u16 **)((u8 *)&iGpffffb268 + 8) = temp_2_2;
        *(s32 *)((u8 *)&iGpffffb268 + 4) = func_0045b1c0(arg0, 6, temp_2_2, D_005F0AE0);
        *(s32 *)work = *(s32 *)work + 1;
        /* fallthrough */
    case 1:
        if (func_004782b0(D_00764364) != 0) {
            if (func_004553c0(*(u8 **)(work + 8)) == 0) {
                return 0;
            }
            temp_18 = *(u8 **)(work + 0x10);
            if (temp_18 == NULL) {
                var_2 = 1;
            } else if (func_004553c0(temp_18) != 0) {
                func_0044ea90(D_005F0A88, 0x94);
                temp_2_3 = (u16 *)D_008873F4[0](1, *(u32 *)(temp_18 + 0x118), 0x40000);
                iGpffffb284 = (s32)temp_2_3;
                iGpffffb280 = *(s32 *)(temp_18 + 0x118);
                func_0043f810(temp_2_3, *(u8 **)(temp_18 + 0x110), *(u32 *)(temp_18 + 0x118));
                func_00454bd0(temp_18);
                var_2 = 1;
            } else {
                var_2 = 0;
            }
            if (var_2 == 0) {
                return 0;
            }
            *(u8 **)(work + 0x10) = NULL;
            temp_18_2 = *(u8 **)(work + 0x14);
            if (temp_18_2 == NULL) {
                var_2_2 = 1;
            } else if (func_004553c0(temp_18_2) == 0) {
                var_2_2 = 0;
            } else {
                if (*(u32 *)(temp_18_2 + 0x118) >= 0xC00U) {
                    func_0046d730(D_005F0A88, 0xB3);
                }
                func_0043f810(D_007E3720, *(u8 **)(temp_18_2 + 0x110), *(u32 *)(temp_18_2 + 0x118));
                func_00454bd0(temp_18_2);
                var_2_2 = 1;
            }
            if (var_2_2 == 0) {
                return 0;
            }
            *(u8 **)(work + 0x14) = NULL;
            if (func_0015d000(*(u8 **)(work + 0x18)) == 0) {
                return 0;
            }
            *(u8 **)(work + 0x18) = NULL;
            if (func_001615a0(*(s32 *)(work + 0x1C)) == 0) {
                return 0;
            }
            *(s32 *)(work + 0x1C) = 0;
            if (func_004553c0(*(u8 **)(work + 0x20)) == 0) {
                return 0;
            }
            if (func_004553c0(*(u8 **)(work + 0x24)) == 0) {
                return 0;
            }
            if (func_004553c0(*(u8 **)(work + 0x30)) == 0) {
                return 0;
            }
            if (func_004553c0(*(u8 **)(work + 0x34)) == 0) {
                return 0;
            }
            if (func_004553c0(*(u8 **)(work + 0x38)) == 0) {
                return 0;
            }
            if (func_004553c0((u8 *)D_007E3710[0]) == 0) {
                return 0;
            }
            if (func_004553c0((u8 *)D_007E3714[0]) == 0) {
                return 0;
            }
            if (func_004553c0((u8 *)D_007E3718[0]) == 0) {
                return 0;
            }
            temp_4 = *(s32 *)((u8 *)&iGpffffb268 + 4);
            if (temp_4 == 0) {
                var_2_3 = 1;
            } else if (func_0045b170(temp_4) == 0) {
                var_2_3 = 0;
            } else {
                *(s32 *)((u8 *)&iGpffffb268 + 4) = 0;
                var_2_3 = 1;
            }
            if (var_2_3 == 0) {
                return 0;
            }
            *(s32 *)(work + 0x3C) = func_004667d0(0, D_005F0C10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x40) = func_004667d0(0, D_005F0C30, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xAC) = func_004667d0(0, D_005F0C50, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xB0) = func_004667d0(0, D_005F0C70, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x44) = func_004667d0(0, D_005F0C90, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x48) = func_004667d0(0, D_005F0CB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x4C) = func_004667d0(0, D_005F0CD0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x50) = func_004667d0(0, D_005F0CF0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x54) = func_004667d0(0, D_005F0D10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x58) = func_004667d0(0, D_005F0D30, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x5C) = func_004667d0(0, D_005F0D50, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x60) = func_004667d0(0, D_005F0D70, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x64) = func_004667d0(0, D_005F0D90, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x68) = func_004667d0(0, D_005F0DB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x6C) = func_004667d0(0, D_005F0DD0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x70) = func_004667d0(0, D_005F0DF0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x74) = func_004667d0(0, D_005F0E10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x78) = func_004667d0(0, D_005F0E30, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x7C) = func_004667d0(0, D_005F0E50, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x80) = func_004667d0(0, D_005F0E70, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x84) = func_004667d0(0, D_005F0E90, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x88) = func_004667d0(0, D_005F0EB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x8C) = func_004667d0(0, D_005F0ED0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x90) = func_004667d0(0, D_005F0EF0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x94) = func_004667d0(0, D_005F0F10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x98) = func_004667d0(0, D_005F0F30, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0x9C) = func_004667d0(0, D_005F0F50, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xA0) = func_004667d0(0, D_005F0F70, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xA4) = func_004667d0(0, D_005F0F90, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xA8) = func_004667d0(0, D_005F0FB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xD8) = func_004667d0(0, D_005F0FD0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xDC) = func_004667d0(0, D_005F0FF0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xE8) = func_004667d0(0, D_005F1010, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0xEC) = func_004667d0(0, D_005F1030, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)work = *(s32 *)work + 1;
        } else {
            return 0;
        }
    case 2:
        var_18 = 0;
        goto loop_59_check;
loop_59:
        temp_2_7 = (u8 *)(work + (var_18 * 4));
        row = temp_2_7 + 0x3C;
        temp_4_4 = *(s32 *)(temp_2_7 + 0x3C);
        if (temp_4_4 != 0) {
            func_004669d0(temp_4_4, &sp1EC, 0);
            if (sp1EC != 0) {
                *(s32 *)row = 0;
            } else {
                return 0;
            }
        }
        var_18 += 1;
loop_59_check:
        if (var_18 < 0x1E) {
            goto loop_59;
        }
        var_18_2 = 0;
        goto loop_66_check;
loop_66:
        temp_2_6 = (u8 *)(work + (var_18_2 * 4));
        row = temp_2_6 + 0xD8;
        temp_4_3 = *(s32 *)(temp_2_6 + 0xD8);
        if (temp_4_3 != 0) {
            func_004669d0(temp_4_3, &sp1EC, 0);
            if (sp1EC != 0) {
                *(s32 *)row = 0;
            } else {
                return 0;
            }
        }
        var_18_2 += 1;
loop_66_check:
        if (var_18_2 < 2) {
            goto loop_66;
        }
        var_18_3 = 0;
        goto loop_73_check;
loop_73:
        temp_2_5 = (u8 *)(work + (var_18_3 * 4));
        row = temp_2_5 + 0xE8;
        temp_4_2 = *(s32 *)(temp_2_5 + 0xE8);
        if (temp_4_2 != 0) {
            func_004669d0(temp_4_2, &sp1EC, 0);
            if (sp1EC != 0) {
                *(s32 *)row = 0;
            } else {
                return 0;
            }
        }
        var_18_3 += 1;
loop_73_check:
        if (var_18_3 < 2) {
            goto loop_73;
        }
        func_0044ea90(D_005F0A88, 0x1BB);
        temp_2_4 = (u16 *)D_008873F4[0](1, *(u32 *)(*(u8 **)(work + 0x38) + 0x118), 0x40000);
        iGpffffb27c = (s32)temp_2_4;
        temp_3_2 = *(u8 **)(work + 0x38);
        func_0043f810(temp_2_4, *(u8 **)(temp_3_2 + 0x110), *(u32 *)(temp_3_2 + 0x118));
        iGpffffb278 = *(s32 *)(*(u8 **)(work + 0x38) + 0x118);
        func_00454bd0(*(u8 **)(work + 8));
        func_00454bd0(*(u8 **)(work + 0x20));
        func_00454bd0(*(u8 **)(work + 0x24));
        func_00454bd0(*(u8 **)(work + 0x30));
        func_00454bd0(*(u8 **)(work + 0x34));
        func_00454bd0(*(u8 **)(work + 0x38));
        *(s32 *)(work + 0xF0) = func_0018c580(arg0);
        *(s32 *)work = *(s32 *)work + 1;
        break;
    default:
        break;
    case 3:
        if (func_00452490(*(s32 *)(work + 0xF0)) != 1) {
            return -1;
        }
        break;
    }
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/k_fldData", func_0015d730);
#endif
// FUN_0015E7A0
void func_0015e7a0(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
// FUN_0015E7D0
s32 func_0015e7d0(void)
{
    u8 *mem;
    s32 result;

    func_0044ea90(D_005F0A88, 0x1ED);
    mem = D_008873F4[0](1, 0xF4, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    result = func_00451de0(D_005F1050, 0xF, 0, 0, (void *)func_0015d730,
                           (void *)func_0015e7a0, mem);
    *(s32 *)(mem + 4) = 0;
    return result;
}

