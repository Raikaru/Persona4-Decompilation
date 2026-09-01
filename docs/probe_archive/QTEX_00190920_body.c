/* object_size=196 window=208 normalized_diff=37 differing_offsets=24,25,26,27,28,29,30,31,76,78,79,82,83,86,87,96 classification=argument-materialization-order; ruled_out=plain m2c body, computed-address hoisted local (optimized away), pointer-signature/block-prototype probe (target prototype redeclaration compile error), pointer-local and struct-field forms per existing campaign notes; residual=retail moves arg1 before each arg0+0x10 address while b210 schedules computed address first; final 12-byte window tail is zero padding */
s32 func_00190920(s32 arg0, s32 arg1) {
    if (func_003ef650(arg1, arg0 + 0x10) == 0) {
        func_003ef610(arg0);
        func_003ef5b0(arg1, arg0);
        func_00440b68(D_005F6178, arg0 + 0x10);
        if (func_003ef650(arg1, arg0 + 0x10) != 0) {
            func_00440b68(D_005F6190, arg0 + 0x10);
        }
    } else {
        func_00440b68(D_005F61B0, arg0 + 0x10);
    }
    return arg0;
}
