/* object_size=668 window=672 normalized_diff=20 differing_offsets=208,209,210,211,212,214,216,217,218,219,496,497,498,499,500,502 classification=argument-materialization-order; ruled_out=frame/prologue, s32 sp[2] plus s32 spill[4] and buffer[5] stack aggregates, saved-register declaration order, switch dispatch and goto loop layout, shared-callee argument count/width; shared_callee_probe=retail func_003deff0 first-uses a0 as forwarded pointer, saves a1/a2, masks a3/t0 => canonical (void *,s32,s32,s32,s32), existing five args complete; block-scope pointer declaration, explicit casts, and canonical s32 return produced no nd change; residual=both func_003deff0 calls materialize move a0 before retail's spill[0..1] loads */
s32 func_00190680(u8 *arg0, void *arg1) {
    s32 sp[2];
    s32 spill[4];
    s32 buffer[5];
    s32 var_20;
    s32 temp_19;
    s32 temp_18;
    u8 *temp_2;
    u8 *var_16;

    var_20 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_19 = func_003e2f60(3, 1, &sp[0]);
    temp_18 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_19 != 0) && (temp_18 != 0)) {
        goto loop_check;
loop_body:
        switch (spill[0]) {
        case 0x16:
            var_20 = func_003e6a90(temp_19);
            break;
        case 0xF0F000E0:
            func_003e2910(temp_19, &buffer[0], 0x14);
            func_003deff0(temp_18, spill[0], spill[1], spill[2], spill[3]);
            func_003e2ab0(temp_18, &buffer[0], 0x14);
            func_003e2ce0(temp_19, buffer[2]);
            func_0044ea90(D_005F6168, 0xBB);
            temp_2 = D_008873F4[0](1, buffer[1] + buffer[2], 0x40000);
            func_003e2910(temp_19, temp_2 + buffer[2], buffer[1]);
            func_003e2ab0(temp_18, temp_2, buffer[1] + buffer[2]);
            jtbl_008873EC[0](temp_2);
            break;
        default:
            if (spill[1] != 0) {
                func_0044ea90(D_005F6168, 0xCA);
                var_16 = D_008873F4[0](1, spill[1], 0x40000);
                func_003e2910(temp_19, var_16, spill[1]);
            }
            func_003deff0(temp_18, spill[0], spill[1], spill[2], spill[3]);
            if (spill[1] != 0) {
                func_003e2ab0(temp_18, var_16, spill[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_19, &spill[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_19, 0);
        func_003e2e40(temp_18, 0);
    }
    return var_20;
}
