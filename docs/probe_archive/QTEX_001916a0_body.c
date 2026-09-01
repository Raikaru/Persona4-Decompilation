/* object_size=420 window=432 normalized_diff=10 differing_offsets=252,253,254,255,256,258,260,261,262,263 classification=argument-materialization-order; ruled_out=frame/prologue, s32 sp[2] plus s32 spill[4] aggregates, declaration-order register coloring, switch/goto loop layout, shared-callee argument count/width; shared_callee_probe=retail func_003deff0 first-uses a0 as forwarded pointer, saves a1/a2, masks a3/t0 => canonical (void *,s32,s32,s32,s32), existing five args complete; block-scope pointer declaration, explicit casts, and canonical s32 return produced no nd change; residual=retail loads spill[0..1] before move a0 while b210 materializes bare first argument first */
s32 func_001916a0(u8 *arg0, void *arg1) {
    s32 sp[2];
    s32 spill[4];
    s32 var_19;
    s32 temp_18;
    s32 temp_17;
    u8 *var_16;

    var_19 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_18 = func_003e2f60(3, 1, &sp[0]);
    temp_17 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_18 != 0) && (temp_17 != 0)) {
        goto loop_check;
loop_body:
        switch (spill[0]) {
        case 0x16:
            var_19 = func_003e6a90(temp_18);
            break;
        default:
            if (spill[1] != 0) {
                func_0044ea90(D_005F6168, 0x330);
                var_16 = D_008873F4[0](1, spill[1], 0x40000);
                func_003e2910(temp_18, var_16, spill[1]);
            }
            func_003deff0(temp_17, spill[0], spill[1], spill[2], spill[3]);
            if (spill[1] != 0) {
                func_003e2ab0(temp_17, var_16, spill[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_18, &spill[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_18, 0);
        func_003e2e40(temp_17, 0);
    }
    return var_19;
}
