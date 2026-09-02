// FUN_00485630 archive (wave Ko lane KoD, killed by provider rate limit; live state at cutoff, MISMATCH nd8 564/576).
// NOT A VALID CANDIDATE: uses __asm__ volatile (sqc2/lqc2/qmtc2 + VU macro ops), banned by the lane brief and lint.
// Residual with the asm: one adjacent swap at +300/+304 (addiu $a1,$sp,0x70 vs a COP2 op). Redo with the MWCC VU
// intrinsics documented in TRAK_004938e0_body.c (_vitof0/_vmul under enable_vu0_registers + vu0_mmi_reg_binding).
extern void func_00485630(u8 *arg0);
void func_00485630(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    u_long128 sp80;
    u_long128 sp70;
    u_long128 sp60;
    u_long128 sp50;
    f32 var_21;
    f32 var_20;
    s32 temp_16;
    u8 *var_17;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    s32 temp_3;
    void (*temp_2)(s32, void *);
    void (*temp_2_2)(s32, void *);
    void (*temp_2_3)(s32);

    __asm__ volatile(
        "lqc2 $vf10, 0x40(%0)\n"
        "lqc2 $vf11, 0(%0)\n"
        "vadd.xyzw $vf10, $vf10, $vf11\n"
        :
        : "r"(arg0)
        : "$vf10", "$vf11", "memory");
    __asm__ volatile(
        "sqc2 $vf10, 0(%0)\n"
        :
        : "r"(&sp80)
        : "$vf10", "memory");

    if ((*(s32 *)(arg0 + 0x68) & 0x60) != 0) {
        __asm__ volatile(
            "lq $2, 0x50(%0)\n"
            "sq $2, 0(%1)\n"
            :
            : "r"(arg0), "r"(&sp50)
            : "$2", "memory");
        func_00486970(arg0, (u8 *)&sp80, &sp60);
        func_00486330(arg0, (u8 *)&sp60);
        __asm__ volatile(
            "lq $2, 0(%0)\n"
            "sq $2, 0x50(%1)\n"
            :
            : "r"(&sp50), "r"(arg0)
            : "$2", "memory");
    }

    temp_16 = *(s32 *)(arg0 + 0x84);
    var_21 = *(f32 *)(arg0 + 0x60) * *(f32 *)(arg0 + 0x74);
    var_17 = *(u8 **)(arg0 + 0x8C);
    var_20 = 5.0f;
    goto loop_00485630_check;
loop_00485630_body:
    if (temp_16 < *(s32 *)(var_17 + 0x80)) {
        goto next_00485630;
    }
    if ((*(s32 *)(var_17 + 0x84) & 2) != 0) {
        goto next_00485630;
    }
    if ((*(s32 *)(var_17 + 0x68) & 0x18) != 0) {
        func_00486840(var_17, (u8 *)&sp80, &sp70);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&sp80) : "$vf10", "memory");
        temp_3 = *(s32 *)(var_17 + 0x68);
        if ((temp_3 & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0\n"
                "nop\n"
                "qmtc2.ni $2, $vf2\n"
                "vaddx.y $vf10, $vf0, $vf2x\n"
                :
                : "f"(var_20)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&sp70) : "$vf11", "memory");
        if ((temp_3 & 0x80) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0\n"
                "nop\n"
                "qmtc2.ni $2, $vf2\n"
                "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                :
                : "f"(var_21)
                : "$2", "$vf2", "$vf11", "memory");
        }
        __asm__ volatile(
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            "sqc2 $vf10, 0(%0)\n"
            :
            : "r"(&sp70)
            : "$vf10", "$vf11", "memory");
        temp_4 = *(u8 **)(var_17 + 0x90);
        temp_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_2 != NULL) {
            temp_2(*(s32 *)(temp_4 + 8), &sp70);
        }
    }
    if ((*(s32 *)(var_17 + 0x68) & 0x60) != 0) {
        func_00486970(var_17, (u8 *)&sp80, &sp60);
        temp_4_2 = *(u8 **)(var_17 + 0x90);
        temp_2_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4_2 + 4) << 6) + 0x24);
        if (temp_2_2 != NULL) {
            temp_2_2(*(s32 *)(temp_4_2 + 8), &sp60);
        }
    }
    temp_4_3 = *(u8 **)(var_17 + 0x90);
    temp_2_3 = *(void (**)(s32))(D_00713480 + (*(u16 *)(temp_4_3 + 4) << 6) + 0x8);
    temp_2_3(*(s32 *)(temp_4_3 + 8));
next_00485630:
    var_17 = *(u8 **)(var_17 + 0xAC);
loop_00485630_check:
    if (var_17 != NULL) {
        goto loop_00485630_body;
    }

    *(s32 *)(arg0 + 0x68) = *(s32 *)(arg0 + 0x68) | 0x80000000;
    *(s32 *)(arg0 + 0x84) = *(s32 *)(arg0 + 0x84) + 1;
}
    func_00485630((u8 *)arg0);
