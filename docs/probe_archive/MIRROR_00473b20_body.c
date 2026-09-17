/* Best body for func_00473b20 @0x00473b20 (window 1440B).
 * Probe: shared_flat via recon_probe (scoped opt_loop_invariants on + _abs pin + plain float expr, helpers outside pragmas).
 * Measured: MISMATCH nd=924 obj=1584/1440.
 * History: v1 invariants_abs nd=1221 obj=1880/1440; v2 flat_8040 nd=1092 obj=1848/1440; v3 shared_flat nd=924 obj=1584/1440 (best).
 * Note: prior file note nd=244 remains best; this archive is worse (924>244) so src note NOT updated per gates.
 * Retail shape covered: s16@4 early-return, u8@2==1 branch, 0x34 dual-index, float block (temp_f20, mask&6, 0x1C vs 1.0, 5e90/5840/5bc0, half-scaler idiom, adda/madd as plain C), tail re-check + 0x54 flags + *(0xC)=*(*(0x20)+0x20@4).
 * Residuals for retry: (1) u16@0x18 lhu;bltz floor (b210 andi/dsll32 vs raw), (2) single-use X+0x40 fold to lw 0x40, (3) adda/madd $f1/$f2 rotation + iGp load order, (4) chain2 base-before-sll vs chain-first. iGp used is iGpffff8040 (retail -0x7FC0); task hint 80cc appears to be typo (8040 per GP=0x7690F0).
 * s8[] lever evaluated N/A: retail byte load at +2 is lbu (u8), s8 would emit lb and mismatch.
 */
#pragma opt_loop_invariants on
u8 *func_00473b20(u8 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_00397c40();
    s16 idx;
    u8 *tbl;
    u8 *ptr;
    u8 *ptr2;
    f32 temp_f20;
    s32 off;
    s32 off2;
    u16 cnt;
    s64 sIdx;
    s64 sIdx2;
    u16 v18;
    f32 var_f;
    f32 nf;
    u32 b40;

    idx = *(s16*)(arg0 + 4);
    if (idx < 0) {
        return arg1;
    }
    if (*(u8*)(arg0 + 2) == 1) {
        tbl = *(u8**)(arg0 + 0x34);
        if ((tbl != (u8*)0) && (idx < *(u16*)(tbl + 8))) {
            off = (s32)idx * 0x50;
            ptr = *(u8**)(*(u32*)tbl + 0x40 + off);
            if ((ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) {
                if ((tbl != (u8*)0) && (*(s32*)(tbl + 4) != 0)) {
                    func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), *(f32*)(arg0 + 0xC) - 1.0f);
                    func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), *(f32*)(arg0 + 0xC));
                    func_00473870(arg0);
                }
                func_00397c40(*(u8**)(arg0 + 0x20));
            }
        }
        return arg1;
    }
    temp_f20 = iGpffff8040 * *(f32*)(arg0 + 8);
    if ((!(temp_f20 <= 0.0f)) || (*(u16*)(arg0 + 0) & 6)) {
        if (*(f32*)(arg0 + 0x1C) < 1.0f) {
            tbl = *(u8**)(arg0 + 0x34);
            if ((tbl != (u8*)0) && (sIdx = (s64)idx, cnt = *(u16*)(tbl + 8), sIdx < (s64)(u32)cnt) && (off = (s32)sIdx * 0x50, b40 = *(u32*)tbl + 0x40, ptr = *(u8**)(b40 + off), (ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) && (sIdx2 = (s64)*(s16*)(arg0 + 0x10), sIdx2 < (s64)(u32)cnt) && (off2 = (s32)sIdx2 * 0x50, ptr2 = *(u8**)(b40 + off2), (ptr2 != (u8*)0) && (ptr2 != (u8*)D_00922BC0_abs))) {
                func_003d5e90(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(arg0 + 0x24), *(void**)(arg0 + 0x28), *(f32*)(arg0 + 0x1C));
                v18 = *(u16*)(arg0 + 0x18);
                if ((s32)v18 >= 0) {
                    var_f = (f32)v18;
                } else {
                    var_f = 2.0f * (f32)(s32)(((u32)v18 >> 1) | ((u32)v18 & 1));
                }
                nf = *(f32*)(arg0 + 0x1C) + (1.0f / var_f);
                *(f32*)(arg0 + 0x1C) = nf;
                if (!(nf < 1.0f)) {
                    func_003d5840(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(*(u8**)(arg0 + 0x28)));
                    ptr = *(u8**)(*(u32*)(*(u32*)(arg0 + 0x34)) + 0x4C + off);
                    if (ptr == (u8*)0) {
                        func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), temp_f20);
                    } else {
                        func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), temp_f20 + iGpffff8040 * (f32)*(s32*)ptr);
                    }
                }
            } else {
                v18 = *(u16*)(arg0 + 0x18);
                if ((s32)v18 >= 0) {
                    var_f = (f32)v18;
                } else {
                    var_f = 2.0f * (f32)(s32)(((u32)v18 >> 1) | ((u32)v18 & 1));
                }
                *(f32*)(arg0 + 0x1C) = *(f32*)(arg0 + 0x1C) + (1.0f / var_f);
            }
        } else {
            tbl = *(u8**)(arg0 + 0x34);
            if ((tbl != (u8*)0) && ((s64)idx < (s64)(u32)*(u16*)(tbl + 8)) && (*(u8**)(*(u32*)tbl + 0x40 + (s32)idx * 0x50) != (u8*)0) && (*(u8**)(*(u32*)tbl + 0x40 + (s32)idx * 0x50) != (u8*)D_00922BC0_abs)) {
                func_003d5bc0(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), tbl, temp_f20);
            } else if (tbl == (u8*)0) {
                *(f32*)(arg0 + 0xC) = *(f32*)(arg0 + 0xC) + temp_f20;
            } else if (*(u8**)(*(u32*)tbl + (s32)idx * 0x50 + 0x40) == (u8*)D_00922BC0_abs) {
            } else {
                *(f32*)(arg0 + 0xC) = *(f32*)(arg0 + 0xC) + temp_f20;
            }
        }
        *(u16*)(arg0 + 0) = *(u16*)(arg0 + 0) & 0xFFFB;
    }
    tbl = *(u8**)(arg0 + 0x34);
    if ((tbl != (u8*)0) && ((s64)idx < (s64)(u32)*(u16*)(tbl + 8))) {
        off = (s32)idx * 0x50;
        ptr = *(u8**)(*(u32*)tbl + 0x40 + off);
        if ((ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) {
            if ((*(u16*)(arg0 + 0) & 2) && (arg1 != (u8*)0)) {
                func_00471280(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(*(u8**)(arg1 + 0x20) + 0x20), *(void**)(*(u8**)(arg0 + 0x20) + 0x20), 1.0f);
            }
            func_00473870(arg0);
            if (arg2 != 0) {
                if (*(u16*)(arg0 + 0) & 0x10) {
                    func_00473000(*(u8**)(arg0 + 0x20), arg0);
                } else if (*(u16*)(arg0 + 0x54) & 0x81E0) {
                    func_00471370(*(u8**)(arg0 + 0x20), arg0, arg0 + 0x54, (void*)0);
                } else {
                    func_00397c40(*(u8**)(arg0 + 0x20));
                }
            }
            v18 = *(u16*)(arg0 + 0x54);
            if (v18 & 0x81E0) {
                *(u16*)(arg0 + 0x54) = v18 | 0x4000;
            } else {
                *(u16*)(arg0 + 0x54) = v18 & 0xBFFF;
            }
            *(f32*)(arg0 + 0xC) = *(f32*)(*(u32*)(*(u32*)(arg0 + 0x20) + 0x20) + 4);
        }
    }
    return arg0;
}
#pragma opt_loop_invariants off

