object_size=284 bytes; retail_window=288 bytes; normalized_diff=211; differing_offsets=0x00,0x04,0x08,0x0a,0x0c,0x0e,0x0f,0x10,0x12,0x13,0x14,0x16,0x17,0x18,0x1a,0x1b; classification=documented R5900 MMI/VU packed-color floor (retail pextlb/pextlh/ppach/ppacb plus COP2 packet; no COP1 accumulator chain; candidate inline COP2/MMI sequence remained nonmatching and frame/save layout diverged).

s32 func_004865c0(u8 *arg0, s32 arg1)
{
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 temp_f20;
    u32 sp30[4];
    s32 (*temp_3)(s32, s32, u8 *);
    s32 var_2;
    u8 *temp_6;
    u8 *var_16;

    *(s32 *)(arg0 + 0x64) = arg1;
    sp4C = arg1;
    temp_f20 = fGpffff8044;
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10   \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $3, %1           \n"
        "nop                   \n"
        "qmtc2.ni $3, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "sqc2 $vf10, 0(%2)     \n"
        :
        : "r"(&sp4C), "f"(temp_f20), "r"(&sp30)
        : "$2", "$3", "$vf2", "$vf10", "memory");
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);
    if (var_16 != NULL) {
    loop_004865c0_body:
        sp48 = *(s32 *)(var_16 + 0x64);
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
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
            :
            : "r"(&sp48), "f"(temp_f20)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
        temp_6 = *(u8 **)(var_16 + 0x90);
        temp_3 = *(s32 (**)(s32, s32, u8 *))(D_00713480 + (*(u16 *)(temp_6 + 4) << 6) + 0x30);
        if (temp_3 != NULL) {
            var_2 = temp_3(*(s32 *)(temp_6 + 8), sp44, temp_6);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
        if (var_16 != NULL) {
            goto loop_004865c0_body;
        }
    }
    return var_2;
}

Ruled out: standalone ordinary-computation asm was not used; MMI was kept in COP2-containing templates per H009. No COP1 MAC chain appeared. Probed scratch aggregate/array forms, declaration order, frame placement, and stack-address materialization; all left the 16-byte save-area/frame divergence and packed-color residual. Retail uses sq saves (not ee-gcc sd), so this is not a gcc-unit separator finding.
