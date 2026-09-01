/* object 720B / window 688B / normalized_diff 478; oversized and archived immediately. */
/* VU inline-asm candidate; call-site and declaration levers were measured, but object remained oversized. */
void func_004938e0(u8 *arg0) {
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    u8 sp70[16];
    f32 temp_f20;
    s32 temp_16;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_18;
    u8 *temp_17;
    u8 *var_19;
    s32 *pt;

    if (*(s32 *)(arg0 + 0) != 0) {
        func_00492d10(*(u8 **)(arg0 + 0x30));
        sp98 = *(s32 *)(arg0 + 4);
        temp_f20 = D_00761134;
        pt = &sp98;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "addiu $2, $sp, 0x70   \n"
            "sqc2 $vf10, 0($2)     \n"
            :
            : "r"(pt), "f"(temp_f20)
            : "$2", "$vf2", "$vf10", "memory");
        var_19 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x18);
        temp_16 = *(s32 *)(arg0 + 0);
        temp_17 = *(u8 **)(arg0 + 0x28);
        func_00494f90(temp_17);
        var_18 = 0;
        while (var_18 < temp_16) {
            if (func_00494710(temp_17, var_18 & 0xFFFF) == 0) {
                temp_3 = *(s32 *)(var_19 + 0x10);
                switch (temp_3) {
                case -2:
                    func_00494740(temp_17, var_18 & 0xFFFF, (void *)D_00922D80, 0.0f);
                    func_004940d0(temp_17, var_18 & 0xFFFF, (void *)D_00764C54);
                    func_004946f0(temp_17, var_18 & 0xFFFF);
                    break;
                case -1:
                case 0:
                    func_00494740(temp_17, var_18 & 0xFFFF, (void *)D_00922D80, 0.0f);
                    func_004940d0(temp_17, var_18 & 0xFFFF, (void *)D_00764C54);
                    func_004946d0(temp_17, var_18 & 0xFFFF);
                    break;
                default:
                    sp80 = *(f32 *)(var_19 + 0);
                    sp84 = *(f32 *)(var_19 + 4);
                    sp88 = *(f32 *)(var_19 + 8);
                    func_00494740(temp_17, var_18 & 0xFFFF, &sp80, *(f32 *)(var_19 + 0x18));
                    sp94 = *(s32 *)(var_19 + 0x14);
                    pt = &sp94;
                    temp_f20 = D_00761134;
                    __asm__ volatile(
                        "lw $2, 0(%0)          \n"
                        "pextlb $2, $0, $2     \n"
                        "pextlh $2, $0, $2     \n"
                        "qmtc2.ni $2, $vf10    \n"
                        "vitof0.xyzw $vf10, $vf10 \n"
                        "mfc1 $2, %1           \n"
                        "nop                   \n"
                        "qmtc2.ni $2, $vf2     \n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                        "addiu $2, $sp, 0x70   \n"
                        "lqc2 $vf11, 0($2)     \n"
                        "vmul.xyzw $vf10, $vf10, $vf11 \n"
                        "lui $2, 0x437F         \n"
                        "qmtc2.ni $2, $vf2     \n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                        "vftoi0.xyzw $vf10, $vf10 \n"
                        "qmfc2.ni $2, $vf10    \n"
                        "ppach $2, $0, $2        \n"
                        "ppacb $2, $0, $2        \n"
                        "sw $2, 0x90($sp)       \n"
                        :
                        : "r"(pt), "f"(temp_f20)
                        : "$2", "$vf2", "$vf10", "$vf11", "memory");
                    sp9C = *(volatile s32 *)&sp90;
                    func_004940d0(temp_17, var_18 & 0xFFFF, &sp9C);
                    break;
                }
            }
            var_18 += 1;
            var_19 += 0x20;
        }
        func_00494ff0(temp_17);
        temp_4 = *(s32 *)(arg0 + 0x2C);
        if ((temp_4 != 0) && ((u32)*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x10) >= (u32)*(s32 *)(arg0 + 0x10))) {
            func_00489f40((void *)temp_4, (void *)(arg0 + 4));
            func_00487c30(*(u8 **)(arg0 + 0x2C), *(f32 *)(arg0 + 0x24) / 10.0f);
        }
    }
}
