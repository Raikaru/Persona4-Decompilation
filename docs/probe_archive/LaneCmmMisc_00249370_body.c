#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
s32 func_00249370(s32 arg0, u32 arg1, s32 arg2) {
    u8 *var_16;
    s32 sp4C;
    s32 sp48;
    s32 temp_2;

    if (arg0 == 0) {
        var_16 = D_008814D0[0] + 8;
        temp_2 = func_00249010(arg1);
        if (temp_2 != -1) {
            var_16 += temp_2 * 0x24;
        } else {
            var_16 = NULL;
        }
        goto end;
    }

    var_16 = D_008814D0[0] + 8;
    func_001104d0(arg1, &sp4C, &sp48);
    if (func_00106330(0xA61) == 0) {
        goto null2;
    }
    var_16 += func_001064f0(0x6D) * 0x24;
    {
        s32 cond = (s32)(arg1 < func_00110600(var_16[2], var_16[3]));
        if (cond != 0) {
            goto null2;
        }
        goto end;
    }
null2:
    var_16 = NULL;
end:
    if ((arg2 != 0) && (arg2 != 1)) {
        func_0046d730(D_006359D0, 0x4A0);
    }
    if (var_16 == NULL) {
        return 0;
    }
    return *(s32 *)(cmmMiscAddOff(arg2 * 0x10, (s32)var_16) + 0xC);
}
#pragma pop
