/* object_size=216; window=224; normalized_diff=61; differing_word_offsets=28,32,44,48,68,80,164,168,172,176,180,184,188,192,196,200,204,208,212,216. */
/* Ruled out: corrected iGpffffb70c GP declaration; callback return-width and pointer-call forms; local declaration-order permutations; pointer versus s32 locals and parameter; do/while versus while loop; no_branch_likely on/off; schedule on/off; O2 probe; volatile and inline-asm perturbations. Residual is prologue saved-register/order plus an eight-byte loop-tail deficit. */
u8 *func_003cad90(u8 *arg0)
{
    u8 *var_19;
    s32 temp_17;
    u8 *temp_18;
    u8 *temp_5;
    void (**callback)(s32 arg0, u8 *arg1);

    temp_17 = (s32)arg0 + 0x64;
    var_19 = *(u8 **)(arg0 + 0x64);
    temp_18 = (u8 *)((s32)arg0 + iGpffffb70c);
    callback = jtbl_008873FC;
    if (var_19 != (u8 *)temp_17) {
        do {
            temp_5 = var_19 - 0xC;
            var_19 = *(u8 **)var_19;
            if ((*(s32 *)(temp_5 + 8) != 0) &&
                (*(s32 *)(temp_5 + 0x14) != 0)) {
                *(u8 **)(*(u8 **)(temp_5 + 0x10)) =
                    *(u8 **)(temp_5 + 0xC);
                *(u8 **)(*(u8 **)(temp_5 + 0xC) + 4) =
                    *(u8 **)(temp_5 + 0x10);
                *(u8 **)(*(u8 **)(temp_5 + 4)) =
                    *(u8 **)(temp_5 + 0);
                *(u8 **)(*(u8 **)(temp_5 + 0) + 4) =
                    *(u8 **)(temp_5 + 4);
                (*callback)(*(s32 *)((u8 *)D_008872E0 + iGpffffb718),
                            temp_5);
            }
        } while (var_19 != (u8 *)temp_17);
    }
    *(s32 *)(arg0 + 0x10) = *(s32 *)(temp_18 + 4);
    return arg0;
}
