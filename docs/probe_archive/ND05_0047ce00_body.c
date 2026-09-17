/* Proof record (batch workflow, first-party handoff):
 * Target: func_0047ce00
 * Owner: src/promoted/code1_0047.c (// FUN_0047CE00 INCLUDE_ASM retained)
 * Retail address/window: 0x0047CE00, 592B (0x250)
 * Compiler/profile: MWCCPS2 3.0.1 b210 -O2 -Iinclude (unit default; not in speed_units, not in compiler_units)
 * Evidence read:
 *   - asm/nonmatchings/code1_0047/func_0047ce00.s (full, 169 lines, authoritative)
 *   - docs/ghidra_headstart/src/promoted/code1_0047.c FUN_0047ce00 (full)
 *   - docs/ida_headstart/src/promoted/code1_0047.c sub_47CE00 (full)
 *   - src/generated/code1_0047.c P4_UNIT_0047CE00 (121 lines, m2c gotos-only draft)
 *   - docs/probe_archive/QCMP_0047ce00_body.c (full)
 *   - docs/probe_archive/joC_v1_0047ce00_body.c (full)
 *   - docs/probe_archive/JoC_0047ce00_body.c (full, COMPILE_ERROR at cutoff)
 *   - src/promoted/code1_0047.c owner section around marker + provider decls
 * Initial candidate: joC_v1 fixed for u8*->s32 casts (65 differing words, reloc-masked).
 *   QCMP fixed (explicit if>=6 + switch) scored 129 with 0x60 frame and extra slti check.
 * Semantic gate:
 *   - func_0047e450 provider is void func_0047e450(void**, s32, s32, s32, u32)
 *     (src/Graphics/Model/mdlSE.c:127, MATCHED). Owner declared (u8*, s16, s16, s32, u32),
 *     forcing lh instead of retail lhu for 0xD4/0xD6. Corrected owner to
 *     (u8*, s32, s32, s32, u32); no other function in this owner calls it, so
 *     owner isolation holds (37 MATCH before and after).
 *   - func_00455ea0 provider is u8* (src/promoted/code1_0022.c:183, MATCHED).
 *     Candidate keeps (s32) casts at both call sites; no prototype change.
 *   - func_003e2e40/003e2f60, func_00454bd0/004553c0/00456150/00463250,
 *     func_0047b0c0/0047c660 decls already match providers/callers; unchanged.
 * Truthful residual (after header fix, fnalign 146/146, probe nd 5):
 *   - pure instruction scheduling in the 0x40-else e450 setup:
 *     retail: addiu a0,s2,0x2D0; lhu a1,D4; lhu a2,D6; move a3,v0; lw t0,0x4C(sp); jal
 *     object: lhu a1,D4; lhu a2,D6; lw t0,0x4C(sp); addiu a0,s2,0x2D0; move a3,v0; jal
 *     Same 5-instruction multiset, same registers, only dest-addiu vs stack-lw order.
 * Decisive source levers (measured via probe_variants, reloc-masked nd):
 *   - 0x40 branch order direct-first (if ==0 direct else calls): 65 -> 47.
 *   - case-2 polarity success-inline (if ==0 goto fail; state=3 inline): 65 -> 23 alone.
 *   - combined branch + split-temp + b0c0 fix: 65 -> 5 (v_comb).
 *   - e450 s16->s32 header: lh->lhu, fnalign 6 -> 4 edits (plus 2 reloc-only).
 * Stopped levers (all measured neutral/worse, recorded so not repeated):
 *   - hoist dest/p1/p2/spv into locals after tmp (w_hoist_all/dest_only/p_only/p_u16): all nd 5.
 *   - decl-order perms of ret/obj/sp4C (5 variants): all nd 5.
 *   - scoped pragmas: schedule off nd 5 (no effect), propagation off nd 5,
 *     schedule on nd 120, common_subs off nd 108.
 *   - schedule-off matches docs/matching.md PnC_001cff00: pure load-order residual
 *     the schedule knob does not reach.
 * Candidate emitted/window bytes: 584B / 592B (146/146 instrs, same size).
 * Relocations: 14, all resolved (HI16/LO16 jtbl_00756800 x2 + 12 R_MIPS_26 calls:
 *   00456150, 004553c0, 00455ea0 x2, 0047e450, 003e2f60, 0047c660, 0047b0c0,
 *   0047c660, 00463250, 003e2e40, 00454bd0). No unresolved.
 * Resolved prefix comparison: not exact; 5 reloc-masked differing words.
 * Retail suffix: 8B zero tail (2 words) after 584B prefix; accepted tail only.
 * Other owner functions: 37 MATCH unchanged (verify.py src/promoted/code1_0047.c).
 * Other owner relocations/tables: unchanged (no local tables touched).
 * Callers/declarations changed: only owner line 62 width (s16->s32) to match provider.
 * Caller-owner isolation: no other TU calls through this header; provider TU unchanged.
 * Hardware contract: none (no COP2/VU, no lqc2/sqc2).
 * Repository verifier: python tools/verify.py src/promoted/code1_0047.c -> 37 MATCH, 1 ASM.
 * Remaining caveat: production stays INCLUDE_ASM; this floor is semantically faithful
 *   but not instruction-exact due to the dest/lw scheduling wall.
 * Private artifacts: local/47ce00/{qcmp_fixed,jocv1_fixed,v_branch,v_split,v_b0c0,v_comb,
 *   w_hoist_all,w_dest_only,w_p_only,w_p_u16,p_sched_off,p_sched_on,p_prop_off,
 *   p_common_off,d_ret_sp_obj,d_obj_ret_sp,d_obj_sp_ret,d_sp_ret_obj,d_sp_obj_ret}.c
 *   plus align_*.txt; owner backup local/47ce00/code1_0047_backup.c.
 */

s32 func_0047ce00(u8 *arg0)
{
    s32 ret;
    u8 *obj;
    s32 sp4C;

    obj = *(u8 **)(arg0 + 0x30C);
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    switch (*(u8 *)(obj + 0x3C)) {
    case 0:
        if (*(u8 **)(obj + 0x38) != NULL) {
            if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
                func_00456150(*(u8 **)(obj + 0x38));
            }
            if (func_004553c0(*(u8 **)(obj + 0x38)) == 0) {
                goto ret_label;
            }
            if (*(s32 *)(obj + 0x40) == 0) {
                *(s32 *)(obj + 0x2C) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x110);
                *(s32 *)(obj + 0x30) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x118);
            } else {
                *(s32 *)(obj + 0x2C) = (s32)func_00455ea0(*(u8 **)(obj + 0x38), 0, &sp4C);
                *(s32 *)(obj + 0x30) = sp4C;
                func_0047e450((u8 *)((u32)arg0 + 0x2D0), *(u16 *)(arg0 + 0xD4), *(u16 *)(arg0 + 0xD6),
                              (s32)func_00455ea0(*(u8 **)(obj + 0x38), 1, &sp4C), (u32)sp4C);
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
        if (*(s32 *)(obj + 0) == 0) {
            *(s32 *)(obj + 0) = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 1:
        if (*(u8 *)(obj + 0x3C) == 1) {
c660_again:
            if (func_0047c660(arg0) == 0) {
                goto ret_label;
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 2:
        if (func_0047b0c0(arg0) == 0) {
            goto L_case2_fail;
        }
        *(u8 *)(obj + 0x3C) = 3;
        goto L_D8_check;
L_case2_fail:
        *(u8 *)(obj + 0x3C) = 1;
        goto c660_again;
L_D8_check:
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(obj + 0x3C) = 4;
            goto L_after_c3;
        }
    case 3:
        if (func_0047c660(arg0) == 0) {
            goto ret_label;
        }
        *(u8 *)(obj + 0x3C) = 4;
L_after_c3:
    case 4:
        if (*(s32 *)(obj + 0x34) != 0) {
            func_00463250(*(void **)(obj + 0x34));
        }
        func_003e2e40(*(s32 *)(obj + 0), (s32 *)(obj + 0x2C));
        if (*(u8 **)(obj + 0x38) != NULL) {
            func_00454bd0(*(u8 **)(obj + 0x38));
        }
        *(u8 *)(obj + 0x3C) = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}
