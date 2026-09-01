/* object_size=304 window=304 normalized_diff=100 differing_offsets=0x88,0x9c-0x128 (35 reloc-masked words); ruled out: callee signatures (all c00 callees match local declarations), opt_propagation off/on, pointer/base spellings, direct stack indexing, M2C_FIELD load, pointer declaration permutations, pointer/lifetime assignment order, narrow and signed/unsigned character types, s32/u8 pointer variants, loop and branch forms, constant declaration/assignment order, and pointer arithmetic operand order. */
// FUN_00230C00
s32 func_00230c00(s32 arg0, s32 arg1, void *arg2)
{
    s8 sp40[0x100];
    s32 var_2;
    s8 temp_5_2;
    u8 *temp_5;
    u8 *temp_7;
    s32 slash;
    s32 backslash;

    if (func_0047d0e0() == 0) {
        func_0047d0b0(arg0, arg1, arg2);
        goto done;
    }
    func_0047d0b0(arg0, arg1, sp40);
    var_2 = func_00442948(sp40);
    *((sp40 - 0x40) + var_2 + 0x3D) = 0x70;
    *((sp40 - 0x40) + var_2 + 0x3E) = 0x61;
    *((sp40 - 0x40) + var_2 + 0x3F) = 0x63;
    slash = 0x2F;
    backslash = 0x5C;
    goto loop_check;
 loop_back:
    var_2 -= 1;
 loop_check:
    temp_5 = (u8 *)((s32)sp40 - 0x40 + var_2);
    temp_7 = temp_5 + 0x40;
    temp_5_2 = *temp_7;
    if ((temp_5_2 != backslash) && (temp_5_2 != slash)) {
        goto loop_back;
    }
    switch (arg0 & 0xFFFF) {
    case 2:
        func_00442088(arg2, D_006357C8, D_00635678);
        break;
    default:
        func_00442088(arg2, D_006357C8, &D_007636e0);
        break;
    }
 done:
    return 1;
}
