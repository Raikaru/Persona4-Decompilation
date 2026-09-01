/* object 224B, window 224B, normalized_diff 49; fndiff differing offsets are clustered in saved-register coloring, selection-gate branch layout, and call staging. Compiler check: sd $ra only and no callee-saved register save, so no sq/sd diagnostic; addiu/addu/sltu style and location before the documented ee-gcc transition retain it as MWCC candidate. Body restored from WT17 archive after schedule-on (196B/50) and opt_rebuildconditionals-off (224B/52) probes; helper call kept old-style to preserve all seven retail arguments. */
void func_004142b0(u8 *arg0)
{
    void func_004156e0();
    s32 var_6;
    s32 var_7;
    s32 var_8;
    u32 *var_4;
    u32 var_3;
    u32 var_9;
    u8 *temp_3;
    u8 *temp_5;
    u8 *var_4_2;

    var_8 = 0;
    temp_5 = *(u8 **)(arg0 + 8);
    var_4 = *(u32 **)(*(u8 **)(temp_5 + 0x1C) + 8);
    var_3 = *var_4;
    var_9 = 0;
    if ((u32)0 < var_3) {
        var_7 = 0;
        var_6 = 0;
        do {
            if (var_9 < var_3) {
                var_4_2 = *(u8 **)((u8 *)var_4 + 0xC) + var_7;
            } else {
                var_4_2 = NULL;
            }
            if ((u32)(*(s32 *)(var_4_2 + 4) - 1) < 2U) {
                var_8 += 1;
                temp_3 = *(u8 **)(arg0 + 0x1C) + var_6;
                *(s32 *)(temp_3 + 0) = *(s32 *)(var_4_2 + 0);
                var_6 += 0xC;
                *(s32 *)(temp_3 + 4) = *(s32 *)(var_4_2 + 4);
                *(s32 *)(temp_3 + 8) = *(s32 *)(var_4_2 + 0x1C);
            }
            var_9 += 1;
            var_4 = *(u32 **)(*(u8 **)(temp_5 + 0x1C) + 8);
            var_3 = *var_4;
            var_7 += 0x24;
        } while (var_9 < var_3);
    }
    *(s32 *)(arg0 + 0x18) = var_8;
    func_004156e0(*(s32 **)(arg0 + 0x1C), *(u32 *)(arg0 + 0x18),
                  0xC, 0, 0, -1, arg0);
}
