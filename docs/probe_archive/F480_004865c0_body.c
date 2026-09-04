object_size=260 bytes; retail_window=288 bytes; normalized_diff=146 bytes; fndiff_differing_words=51; best_hardware_probe=asm_hard_vec_nr; plain_c_probe_object_size=860 bytes; plain_c_probe_normalized_diff=793 bytes; plain_c_probe_fndiff_differing_words=211; classification=honest NONMATCHING R5900 MMI/VU packed-color floor; measured_with=tools/fndiff.py and tools/verify.py on build/.probe_004865c0_asm_hard_vec_nr.c and build/.probe_004865c0_seq.c.

// FUN_004865C0
void func_004865c0(u8 *arg0, s32 arg1)
{
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 temp_f20;
    u_long128 sp30;
    s32 *sp4C_ptr;
    void (*temp_3)(s32, u32);
    u8 *temp_6;
    u8 *var_16;

    *(s32 *)(arg0 + 0x64) = arg1;
    sp4C = arg1;
    sp4C_ptr = &sp4C;
    temp_f20 = fGpffff8044;
    __asm__ volatile(
        ".set noreorder         \n"
        "lw $2, 0(%1)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10   \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $3, %2           \n"
        "nop                   \n"
        "qmtc2.ni $3, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "addiu $3, $sp, 0x30  \n"
        "sqc2 $vf10, 0($3)     \n"
        ".set reorder           \n"
        : "=m"(sp30)
        : "r"(sp4C_ptr), "f"(temp_f20)
        : "$2", "$3", "$vf2", "$vf10", "memory");
    var_16 = *(u8 **)(arg0 + 0x8C);
    if (var_16 != NULL) {
    loop_004865c0_body:
        sp48 = *(s32 *)(var_16 + 0x64);
        __asm__ volatile(
            ".set noreorder         \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %2           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "addiu $3, $sp, 48     \n"
            "lqc2 $vf11, 0($3)     \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437f        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 68($sp)        \n"
            ".set reorder           \n"
            : "=m"(sp44)
            : "r"(&sp48), "f"(temp_f20)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
        temp_6 = *(u8 **)(var_16 + 0x90);
        temp_3 = *(void (**)(s32, u32))(D_00713480 + (*(u16 *)(temp_6 + 4) << 6) + 0x30);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_6 + 8), (u32)sp44);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
        if (var_16 != NULL) {
            goto loop_004865c0_body;
        }
    }
}

Recovered control/data flow is a void function: it stores arg1 at arg0+0x64, computes the packed color from each node's +0x64, dispatches the indirect table callback at +0x30 with node-data +8 and the packed color, and advances through +0xAC. The old archive's erroneous s32 return and three-argument callback were corrected.

Residual is not ordinary C: retail uses standalone pextlb/pextlh and ppach/ppacb around COP2 VU0 vitof0/vmul/lqc2/vftoi0/qmtc2 operations, and no compiler-vector syntax produced those instructions. This archival hardware-only candidate uses .set noreorder, an aggregate output operand, and explicit $3 stack addressing to reach the best measured floor, but still misses the retail loop-entry schedule and later instruction ordering/stack references. Production therefore retains INCLUDE_ASM; no NONMATCHING C body is installed.
