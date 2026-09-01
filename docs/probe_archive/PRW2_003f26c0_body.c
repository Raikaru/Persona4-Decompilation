/* object_size=156 window=160 normalized_diff=57 differing_offsets=30,34,36,38,41,44,46,57,58,62,66,74,90,94,95,96; classification=near-miss/saved-register allocation and call/global declaration order; corrected block-scope callee/global: func_003f25c0(u8 *,u8 *,s32), iGpffffabd0. Ruled out: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, mixed-unit sd/sq floor, optimization_level 1 (object 180/160 nd115). */
void func_003f26c0(u8 *arg0)
{
    extern void func_003f25c0(u8 *arg0, u8 *arg1, s32 arg2);
    extern s32 iGpffffabd0;
    u8 *self;
    s32 temp_18;
    s32 var_20;
    u8 *temp_16;
    u8 *var_19;

    self = arg0;
    temp_16 = *(u8 **)(self + 0x4000);
    temp_18 = iGpffffabd0;
    if (temp_16 != NULL) {
        if (temp_18 > 0) {
            var_20 = 0;
            var_19 = temp_16;
            do {
                func_003f25c0(self, *(u8 **)(var_19 + 0x1C), temp_18 - 1);
                var_20 += 1;
                var_19 += 4;
            } while (var_20 < 0x10);
        }
        jtbl_008873FC[0](*(u8 **)(self + 0x4004), temp_16);
    }
    *(u8 **)(self + 0x4000) = NULL;
    func_003e12f0(*(s32 *)(self + 0x4004));
}
