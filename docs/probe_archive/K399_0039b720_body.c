/* object 148B / window 160B / normalized_diff 81; differing offsets begin 0x18,0x1c,0x1d,0x1e,0x24,0x30-0x6c,0x70-0x94. */
/* Ruled out: concrete u8 pointer expansion, restored third parameter and four-register old-style bdf0 call, scoped schedule on, no_branch_likely on, unsigned >0 and reversed 0U<temp3 guards, explicit goto guard, and declaration/local reorder at the 20-minute stop. */
u8 *func_0039bdf0();
void func_0039b720(u8 *arg0, u8 *arg1, u32 arg3) {
    u8 *var_5;
    s32 temp_6;
    u32 temp_3;
    u32 var_7;
    u8 *temp_4;

    var_5 = arg1;
    var_7 = arg3;
    if (*(s32 *)(arg0 + 0xC) == 2) {
        temp_6 = *(s32 *)(arg0 + 4);
        temp_4 = *(u8 **)arg0;
        if (temp_6 != 0) {
            temp_3 = *(u32 *)(var_5 + 4);
            var_7 = 0;
            if (0U < temp_3)
                goto has_entries;
            goto after_entries;
has_entries:
            var_5 = *(u8 **)var_5;
loop_4:
            if (temp_6 == *(s32 *)(var_5 + 8)) {
                *(s32 *)(temp_4 + 0x10) = *(s32 *)(var_5 + 0x10);
            } else {
                var_7 += 1;
                var_5 += 0x14;
                if (var_7 < temp_3) {
                    goto loop_4;
                }
            }
            goto after_entries;
after_entries:
            ;
        } else {
            *(s32 *)(temp_4 + 0x10) = 0;
        }
        *(u8 **)(arg0 + 0x10) = func_0039bdf0(temp_4, var_5, temp_6, var_7);
        *(s32 *)(*(u8 **)(arg0 + 0x10) + 0x30) = *(s32 *)(arg0 + 8);
    }
}
