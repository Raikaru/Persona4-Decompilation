/* Flood fill floor for func_0015b3e0 (retail 0x0015b3e0).
 * Owner src/promoted/code1_0015.c marker // FUN_0015B3E0. PRODUCTION REMAINS ASM
 * via #ifdef NON_MATCHING guard (INCLUDE_ASM in the #else arm).
 *
 * Target: src/promoted/code1_0015.c, func_0015b3e0, retail 0x0015b3e0, window 1792B.
 * Candidate: docs/probe_archive/Flood_0015B3E0_body.c (this file).
 * Compiler: MWCCPS2 3.0.1 b210, -O2, TU pragmas opt_loop_invariants on (line 158)
 *   and opt_propagation on (restored line 1282); no extra scoped pragma for this
 *   candidate.
 * Commands run:
 *   python3 tools/probe_variants.py src/promoted/code1_0015.c func_0015b3e0 --candidate NAME=PATH
 *   python3 tools/probe_archive.py docs/probe_archive/Flood_0015B3E0_body.c src/promoted/code1_0015.c
 *   python3 tools/fndiff.py <spliced-owner-test>.c func_0015b3e0 --addr 0015b3e0
 *   python3 tools/fnalign.py src/promoted/code1_0015.c func_0015b3e0 --candidate PATH
 *   python3 tools/verify.py src/promoted/code1_0015.c
 * Instruction result: obj 1780B, window 1792B, differing words (reloc-masked) 284.
 *   fnalign: 445 retail vs 445 object instrs, 71 edits plus 4 reloc-only.
 *   Frame exact (addiu $sp,$sp,-0x120 both sides); prologue exact through the
 *   counter spill (move $s7,$a0 / move $fp,$a1 / sb 0x11F/0x11E / move $s4/$s3 /
 *   sw 0x118); epilogue exact (ld/lq restores, addiu $sp,0x120, jr). 28 jal
 *   relocs (23x func_00155280, 1x func_0014a0f0, 4x recursion) plus 4 gp-relative
 *   mode loads (retail lw -0x6250($gp) vs *(s32 *)iGpffff9db0, reloc-only).
 *   verify.py on the owner reports 61 MATCH / 7 ASM, zero MISMATCH; this target
 *   stays ASM via the guard's INCLUDE_ASM arm, so TU C-link eligibility and
 *   retail image identity are unverified for this floor (no link run claimed).
 * Semantic review: four-direction recursive flood over the board returned by
 *   func_00155280(). Cell address is base + (row << 8) + (col * 0x10) where row
 *   is arg1 and col is arg0; fields 0x54 occupied, 0x55 flags, 0x56 u16 id,
 *   0x58 type, 0x5E wall bits. Outer guard is (arg5 & 0xFF) < (arg6 & 0xFF);
 *   occupied must be 1; func_0014a0f0(*(u16*)(cell + 0x56), 1) per
 *   include/Kosaka/k_command_internal.h:11, then (*arg7)++. Exits are
 *   (~arg2 & cell[0x5E]) & 0xFF, tested bit-by-bit (1 north, 2 west, 4 south,
 *   8 east) with recursive incomings 4, 8, 1, 2. Per-direction next-limit is 3
 *   when the corresponding arg3 bit is set, else propagated limit (u16
 *   north/west/south hold it; east reuses limit_low directly, retail $s5).
 *   North/south type 7/8 with ((arg4 & 0xFF) & 0xA) and depth 0 increments the
 *   limit and intentionally leaves next_depth unassigned (retail has no $s2 set
 *   on that path, so the recursive depth is the stale $s2, preserved here by not
 *   assigning next_depth); west/east type 7/8 with limit 4 keeps depth via
 *   (u8)arg5; type 3 keeps depth via (u8)arg5 when ((arg4 & 0xFF) & bit) with
 *   bit 1/2/4/8 per direction, else depth is (depth_low + 1) & 0xFF. East defers
 *   its arg3 & 8 test (east_tmp) to after the depth cascade. The gp-relative
 *   deref compared against 0x2C/0x40 is the owner file's existing iGpffff9db0
 *   (0x00762ea0; config/symbol_data_addrs.txt:286 records retail func_0014a2f0
 *   lw $3,-0x6250($28) with gp base 0x007690F0; promoted uses *(s32 *)iGpffff9db0
 *   for the same 0x2C/0x40 test at lines 1084/1100, there with 0x2E/0x42 also).
 *   No new gp name invented. Callers in the owner (func_0015bae0) pass
 *   (x, y, 0, dir, 4/8/2/1, 0, 4, &D_0076430C), consistent with
 *   (col, row, incoming, arg3, arg4, depth, limit, counter). All board/type/flag
 *   loads are direct (base + (arg1 << 8) + (arg0 << 4)) with no row_save/col_save
 *   caching, matching the MATCH sibling func_00157700's direct form.
 * Residual: double-andi sites (retail andi 0xFF then andi mask vs object single
 *   andi mask: north/south 0xA plus four type-3 1/2/4/8); limit spill shape
 *   (retail move + sb/lbu/addiu vs object daddiu + sh/lhu and andi 0xFFFF +
 *   sh, plus sw/lw on the s32 path); call-setup extra lbu + move vs direct lbu
 *   to $t2; east_tmp and counter scheduling; remaining branch-displacement and
 *   register-colour drift after the first direction. No frame/prologue/epilogue
 *   gap remains.
 * Levers tried (all measured via probe_variants from this archive, source never
 *   installed except the final guarded floor): s32 north/west/south 376 -> 372
 *   (-4, addiu vs daddiu for =3); keep via (u8)arg5 372 -> 361 (-11, andi vs
 *   move, defeats CSE with depth_low kept as arg5 & 0xFF; depth as (u8)arg5
 *   regresses to 372); all-direct (drop row_save/col_save, direct id/exits)
 *   361 -> 300 (-61, frame 0x100 -> 0x120 exact, prologue/counter exact,
 *   431 -> 442 instrs); u16 north/west/south 300 -> 284 (-16, sh/lhu vs sw/lw,
 *   442 -> 445 instrs exact count). Neutral: arg4 direct (arg4 & mask) vs
 *   folded ((arg4 & 0xFF) & mask) (same); exits/inc (u8) casts; col <<4 vs *0x10
 *   and row <<8 vs *0x100; declaration-order families (reverse/row-last, all
 *   neutral on every base); scoped opt_propagation/common_subs/dead_assignments
 *   (propoff +3, commonoff +29, deadoff +3); s8/s16/east-u16/depth-u8/counter-local
 *   and single/shared tmp two-step for =3 (297, still worse than 284).
 * Non-goal respected: func_00156cf0 and func_001561a0 untouched (still MATCH /
 *   guarded-ASM respectively in the 61/7; no edits outside FUN_0015B3E0).
 */
void func_0015b3e0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5, u8 arg6, s32 *arg7)
{
    s32 depth_low;
    s32 limit_low;
    u16 north_limit;
    u16 west_limit;
    u16 south_limit;
    s32 east_tmp;
    s32 next_depth;
    s32 mode;
    s32 exits;

    depth_low = arg5 & 0xFF;
    limit_low = arg6 & 0xFF;
    if (depth_low < limit_low) {
        if (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x54] == 1) {
            func_0014a0f0(*(u16 *)(((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10)) + 0x56), 1);
            *arg7 += 1;
            exits = (~arg2 & ((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x5E]) & 0xFF;
            if (exits & 1) {
                if (arg3 & 1) {
                    north_limit = 3;
                } else {
                    north_limit = (u16)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((arg4 & 0xFF) & 0xA) != 0) && (depth_low == 0)) {
                    north_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 1) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0, arg1 - 1, 4, 0, arg4, next_depth, north_limit, arg7);
            }
            if (exits & 2) {
                if (arg3 & 2) {
                    west_limit = 3;
                } else {
                    west_limit = (u16)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = (u8)arg5;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 2) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0 - 1, arg1, 8, 0, arg4, next_depth, west_limit, arg7);
            }
            if (exits & 4) {
                if (arg3 & 4) {
                    south_limit = 3;
                } else {
                    south_limit = (u16)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((arg4 & 0xFF) & 0xA) != 0) && (depth_low == 0)) {
                    south_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 4) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0, arg1 + 1, 1, 0, arg4, next_depth, south_limit, arg7);
            }
            if (exits & 8) {
                east_tmp = arg3 & 8;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = (u8)arg5;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 8) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                if (east_tmp != 0) {
                    limit_low = 3;
                }
                func_0015b3e0(arg0 + 1, arg1, 2, 0, arg4, next_depth, limit_low & 0xFF, arg7);
            }
        }
    }
}
