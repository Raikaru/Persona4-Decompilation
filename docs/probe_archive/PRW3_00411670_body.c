/* object_size=184 window=208 normalized_diff=126 differing_offsets=16,17,18,19,20,22,24,25,26,27,28,30,31,32,34,35 classification=undersized saved-register/source-shape residual; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; declarations corrected at block scope: func_00411130(u8*,u8*), jtbl_008873EC/jtbl_008873FC arrays, iGpffffb9b8 GP scalar, D_008872E0 absolute array; typed self-local probe and no_branch_likely measured; no floor instruction */
void func_00411670(u8 *arg0)
{
    extern u8 *func_00411130(u8 *arg0, u8 *arg1);
    u8 *self;
    u32 var_18;
    u8 *var_17;
    u32 temp_16;
    u8 *temp_4;

    self = arg0;
    if (self != NULL) {
        temp_16 = *(u32 *)(self + 4);
        var_17 = *(u8 **)(self + 8);
        var_18 = 0;
        if (temp_16 != 0) {
            do {
                func_00411130(var_17, self);
                var_18 += 1;
                var_17 += 0x28;
            } while (var_18 < temp_16);
        }
        *(u8 **)(self + 8) = NULL;
        temp_4 = *(u8 **)(self + 0x20);
        if (temp_4 != NULL) {
            jtbl_008873EC[0](temp_4);
            *(u8 **)(self + 0x20) = NULL;
            *(s32 *)(self + 0x24) = 0;
        }
        jtbl_008873FC[0](
            *(u8 **)((u8 *)D_008872E0 + iGpffffb9b8), self);
    }
}
