/* Flood fill floor for func_0015b3e0 (retail 0x0015b3e0).
 * Owner src/promoted/code1_0015.c marker // FUN_0015B3E0. PRODUCTION REMAINS ASM.
 *
 * Target: src/promoted/code1_0015.c, func_0015b3e0, retail 0x0015b3e0, window 1792B.
 * Candidate: docs/probe_archive/Flood_0015B3E0_body.c (this file).
 * Compiler: MWCCPS2 3.0.1 b210, -O2, TU pragmas opt_loop_invariants on (line 158)
 *   and opt_propagation on (restored line 1282); no extra scoped pragma for this
 *   candidate (scoped opt_propagation off tested, no change).
 * Commands run:
 *   python3 tools/probe_variants.py src/promoted/code1_0015.c func_0015b3e0 --candidate NAME=PATH
 *   python3 tools/probe_archive.py docs/probe_archive/Flood_0015B3E0_body.c src/promoted/code1_0015.c
 *   python3 tools/fndiff.py src/promoted/code1_0015_probe.c func_0015b3e0 --addr 0015b3e0
 *   python3 tools/verify.py src/promoted/code1_0015.c
 * Instruction result: obj 1724B, window 1792B, differing words (reloc-masked) 376.
 *   verify.py on the owner reports 61 MATCH / 7 ASM, zero MISMATCH; this target
 *   stays ASM via INCLUDE_ASM, so TU C-link eligibility and retail image identity
 *   are unverified for this floor (no link run claimed).
 * Semantic review: four-direction recursive flood over the board returned by
 *   func_00155280(). Cell address is base + (row << 8) + (col * 0x10) where row
 *   is arg1 and col is arg0; fields 0x54 occupied, 0x55 flags, 0x56 u16 id,
 *   0x58 type, 0x5E wall bits. Outer guard is (arg5 & 0xFF) < (arg6 & 0xFF);
 *   occupied must be 1; func_0014a0f0(*(u16*)(cell + 0x56), 1) per
 *   include/Kosaka/k_command_internal.h:11, then (*arg7)++. Exits are
 *   (~arg2 & cell[0x5E]) & 0xFF, tested bit-by-bit (1 north, 2 west, 4 south,
 *   8 east) with recursive incomings 4, 8, 1, 2. Per-direction next-limit is 3
 *   when the corresponding arg3 bit is set, else propagated limit; north/south
 *   type 7/8 with ((arg4 & 0xFF) & 0xA) and depth 0 increments the limit and
 *   intentionally leaves next_depth unassigned (retail has no $s2 set on that
 *   path, so the recursive depth is the stale $s2, preserved here by not
 *   assigning next_depth); west/east type 7/8 with limit 4 keeps depth;
 *   type 3 keeps depth when ((arg4 & 0xFF) & bit) with bit 1/2/4/8 per direction,
 *   else depth is (depth_low + 1) & 0xFF. East defers its arg3 & 8 test to after
 *   the depth cascade and reuses limit_low as the outgoing limit (retail $s5).
 *   The gp-relative deref compared against 0x2C/0x40 is the owner file's
 *   existing iGpffff9db0 (0x00762ea0; config/symbol_data_addrs.txt:286 records
 *   retail func_0014a2f0 lw $3,-0x6250($28) with gp base 0x007690F0; promoted
 *   uses *(s32 *)iGpffff9db0 for the same 0x2C/0x40 test at lines 1084/1100,
 *   there with 0x2E/0x42 also). No new gp name invented. Callers in the owner
 *   (func_0015bae0) pass (x, y, 0, dir, 4/8/2/1, 0, 4, &D_0076430C), consistent
 *   with (col, row, incoming, arg3, arg4, depth, limit, counter).
 * Residual (notable): frame 0x100 vs retail 0x120 (two missing 16B spill slots);
 *   stack spill offsets 0xFF/0xFE vs 0x11F/0x11E; counter pointer kept in $s6
 *   vs spilled to 0x118 with double lw; arg5 full ($s3) not kept, only cached
 *   depth_low ($s2) vs retail $s3/$s6 pair; row_save/col_save give $s7/$fp match
 *   for col/row and $s5 match for limit but id/walls still use register reloads
 *   vs retail sq/lq D0/C0/B0 spills; east_tmp sq/lq A0 vs sw; type/mode/flag
 *   cascade order matches but register colors drift after the first direction.
 * Levers tried (all measured via probe_variants, source never installed):
 *   v1 single next_limit/exits u8 with goto rec (384); v2 separate north/west/
 *   south u8 + east word (385); v3 explicit depth_low/limit_low s32 (395);
 *   v4 keep via arg5 & 0xFF vs cached (395); v5 explicit arg5_save (395, CSE
 *   killed the save); v6 stale-depth fix removing north/south 7/8 depth assign
 *   (384, -11); v7 row_save/col_save for id/walls/exits (376, -8, best);
 *   declaration-order family orderA-D (all 376, no evidence for reverse-order
 *   law on this target); address-materialization family all-saved 390 vs
 *   all-direct 384 (hybrid best, supports gate-2 choice); scoped
 *   opt_propagation off (no change, still 0xD0/0x100 frame).
 * Non-goal respected: func_00156cf0 untouched (still MATCH in the 61).
 */
void func_0015b3e0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5, u8 arg6, s32 *arg7)
{
    s32 depth_low;
    s32 limit_low;
    s32 row_save;
    s32 col_save;
    u8 north_limit;
    u8 west_limit;
    u8 south_limit;
    s32 east_tmp;
    s32 next_depth;
    s32 mode;
    s32 exits;

    depth_low = arg5 & 0xFF;
    limit_low = arg6 & 0xFF;
    if (depth_low < limit_low) {
        if (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x54] == 1) {
            row_save = arg1 << 8;
            col_save = arg0 * 0x10;
            func_0014a0f0(*(u16 *)(((u8 *)func_00155280() + row_save + col_save) + 0x56), 1);
            *arg7 += 1;
            exits = (~arg2 & ((u8 *)func_00155280() + row_save + col_save)[0x5E]) & 0xFF;
            if (exits & 1) {
                if (arg3 & 1) {
                    north_limit = 3;
                } else {
                    north_limit = (u8)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = arg5 & 0xFF;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((arg4 & 0xFF) & 0xA) != 0) && (depth_low == 0)) {
                    north_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 1) != 0)) {
                    next_depth = arg5 & 0xFF;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0, arg1 - 1, 4, 0, arg4, next_depth, north_limit, arg7);
            }
            if (exits & 2) {
                if (arg3 & 2) {
                    west_limit = 3;
                } else {
                    west_limit = (u8)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = arg5 & 0xFF;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = arg5 & 0xFF;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 2) != 0)) {
                    next_depth = arg5 & 0xFF;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0 - 1, arg1, 8, 0, arg4, next_depth, west_limit, arg7);
            }
            if (exits & 4) {
                if (arg3 & 4) {
                    south_limit = 3;
                } else {
                    south_limit = (u8)limit_low;
                }
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = arg5 & 0xFF;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((arg4 & 0xFF) & 0xA) != 0) && (depth_low == 0)) {
                    south_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 4) != 0)) {
                    next_depth = arg5 & 0xFF;
                } else {
                    next_depth = (depth_low + 1) & 0xFF;
                }
                func_0015b3e0(arg0, arg1 + 1, 1, 0, arg4, next_depth, south_limit, arg7);
            }
            if (exits & 8) {
                east_tmp = arg3 & 8;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = arg5 & 0xFF;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = arg5 & 0xFF;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((arg4 & 0xFF) & 8) != 0)) {
                    next_depth = arg5 & 0xFF;
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
