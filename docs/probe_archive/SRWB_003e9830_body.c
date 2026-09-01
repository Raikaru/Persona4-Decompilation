object 328B / window 368B / normalized_diff not measured (compile-only object); differing offsets not measured; instruction deficit 10 instructions; classification UNDERSIZED / wrong control-flow and repeated-load source shape; ruled out: pointer-return vs void (pointer return gave exact 0x60 frame and five saved registers), explicit relink/setup/process/detach labels, no_branch_likely on; retail prologue saves s0-s4 (5) and first-touches a0,a1 (2 args); declarations at function scope: u8* locals reordered to var_20,temp_19,var_18,temp_4,u8; callback declarations block-scope old-style.

u8 *func_003e9830(u8 *arg0, u8 *arg1)
{
    extern void func_003e8ed0();
    extern void func_003e99a0();
    u8 *var_20;
    u8 *temp_19;
    u8 *var_18;
    u8 *temp_4;
    u8 temp_6;

    if (*(u8 **)(arg1 + 4) != NULL) goto relink;
setup:
    *(u8 **)(arg1 + 0x9C) = *(u8 **)(arg0 + 0x98);
    *(u8 **)(arg0 + 0x98) = arg1;
    *(u8 **)(arg1 + 4) = arg0;
    temp_19 = *(u8 **)(arg0 + 0xA0);
    *(u8 **)(arg1 + 0xA0) = temp_19;
    var_20 = *(u8 **)(arg1 + 0x98);
    if (var_20 != NULL) {
        do {
            *(u8 **)(var_20 + 0xA0) = temp_19;
            var_18 = *(u8 **)(var_20 + 0x98);
            if (var_18 != NULL) {
                do {
                    func_003e8ed0(var_18, temp_19);
                    var_18 = *(u8 **)(var_18 + 0x9C);
                } while (var_18 != NULL);
            }
            var_20 = *(u8 **)(var_20 + 0x9C);
        } while (var_20 != NULL);
    }
    goto process;
relink:
    func_003e99a0(arg1);
    goto setup;
process:
    if ((*(u8 *)(arg1 + 3) & 3) != 0) goto detach;
process_list:
    temp_4 = *(u8 **)(arg1 + 0xA0);
    temp_6 = *(u8 *)(temp_4 + 3);
    if ((temp_6 & 3) == 0) {
        *(u8 **)(temp_4 + 8) = D_0088739C[0];
        *(u8 **)(temp_4 + 0xC) = (u8 *)D_0088739C;
        *(u8 **)(D_0088739C[0] + 4) = temp_4 + 8;
        D_0088739C[0] = temp_4 + 8;
    }
    *(u8 *)(temp_4 + 3) = temp_6 | 3;
    *(u8 *)(arg1 + 3) |= 0xC;
    return arg0;
detach:
    *(u8 **)(arg1 + 0xC) = *(u8 **)(arg1 + 8);
    *(u8 **)(*(u8 **)(arg1 + 8) + 4) = *(u8 **)(arg1 + 0xC);
    *(u8 *)(arg1 + 3) = *(u8 *)(arg1 + 3) & (u8)~3;
    goto process_list;
}
