/* object 668 / window 672 / normalized_diff 5 / differing byte offsets 0x1FE, 0x200, 0x202, 0x206, 0x20E. Direct residual classification: ordinary integer align-up materialisation (retail's $v1/$v0 register-class/lifetime pair versus candidate's $v0 reuse), not COP2/VU0 and not COP1 MAC. Temporary-rule prediction: both candidates load x into $v0 at offset 500 with the surrounding words identical; retail's sum lands in $v1 because x remains live past the addiu (rule 3 would otherwise reuse $v0). No later read of x is visible in retail. Measured named sum/q, nested assignment, repeated load, comma expression, and store-after-sum probes; named sum/q reached nd7, while store-after-sum drifted everything from 0x1E8. Classification: x-liveness that retail's source creates by a use not recoverable from the instruction stream. Prior lane exhausted signed/unsigned parameter and align-local widths, declaration order, pointer-slot and array forms, loop/guard polarity, arithmetic/cast spellings, local reuse/liveness, argument types, pragmas, and a 600-second permuter run. */
void func_0047e450(void **arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4)
{
    s32 arg3_p = arg3;
    void ** arg0_p = arg0;
    s32 sp16C;
    u8 sp70[0x100];
    s32 sp180[3];
    s32 sp170[3];
    void *temp_16;
    void *temp_2;
    void *temp_2_2;
    void *temp_2_3;
    void *temp_4_2;
    void *temp_4_3;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_5;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_4_4;
    s32 var_16;
    s32 var_17;
    s32 var_2;

    var_17 = arg3_p;
    temp_5 = *arg0;
    if ((temp_5 == NULL) || ((*(u16 *)((u8 *)temp_5 + 0x12) & 1) == 0)) {
        temp_4 = (u16)arg1;
        switch (temp_4) {
        case 1:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2, 0, 0x28);
                *(s32 *)((u8 *)temp_2 + 8) = 1;
                *(s16 *)((u8 *)temp_2 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2 + 0x10) = 1;
                *arg0 = temp_2;
            }
            temp_16 = *arg0_p;
            func_0044ea90(&D_007241D8, 0x49);
            temp_2_2 = jtbl_008873E8[0](arg4, 0x40000);
            *(void **)((u8 *)temp_16 + 0) = temp_2_2;
            func_0043f810(temp_2_2, (void *)var_17, arg4);
            temp_4_2 = *arg0_p;
            *(u16 *)((u8 *)temp_4_2 + 0x12) &= 0xFFFD;
            temp_4_3 = *arg0_p;
            *(u16 *)((u8 *)temp_4_3 + 0x12) |= 1;
            return;
        case 2:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2_3 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2_3, 0, 0x28);
                *(s32 *)((u8 *)temp_2_3 + 8) = 1;
                *(s16 *)((u8 *)temp_2_3 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2_3 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2_3 + 0x10) = 2;
                *arg0 = temp_2_3;
            }
            *(s32 *)((u8 *)(*arg0_p) + 0x14) = 0;
            *(s32 *)((u8 *)(*arg0_p) + 4) = func_0047df40(arg1, arg2);
            var_16 = 0;
            while (var_16 < 3) {
                func_0043f810(sp70, (void *)var_17, 0x100);
                temp_4_4 = var_17 + 0x100;
                sp180[var_16] = temp_4_4;
                sp16C = *(s32 *)(sp70 + 0xFC);
                sp170[var_16] = sp16C;
                var_2 = sp16C + 0x3F;
                temp_3_2 = var_2 >>= 7;
                if (var_2 < 0) {
                    temp_3_2 = (var_2 + 0x3F) >> 6;
                }
                var_17 = temp_4_4 + (temp_3_2 << 6);
                var_16 += 1;
            }
            func_0045a570((s16)*(s32 *)((u8 *)(*arg0) + 4), sp180[0], sp170[0], sp180[1], sp170[1], sp180[2], sp170[2]);
            temp_4_5 = *arg0_p;
            *(u16 *)((u8 *)temp_4_5 + 0x12) |= 8;
            temp_4_6 = *arg0_p;
            *(u16 *)((u8 *)temp_4_6 + 0x12) |= 2;
            break;
        }
    }
}
