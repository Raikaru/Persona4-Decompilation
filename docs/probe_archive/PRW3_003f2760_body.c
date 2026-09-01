/* object_size=208 window=208 normalized_diff=28 differing_offsets=26,30,34,35,54,55,58,70,74,82,86,89,90,94,98,99 classification=exact-size saved-register-colouring residual despite declaration-order probe; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; declarations corrected at block scope: iGpffffb810/iGpffffb80c/iGpffffabd4 u16 GP scalars, iGpffffb808 u8* GP scalar table base, func_003f34e0(void*,u32); measured no_branch_likely on/off; no object-size deficit */
/* Best measured body retained no pragma in archive; source probe used no_branch_likely on. */
void func_003f2760(void)
{
    extern u16 iGpffffb810;
    extern u16 iGpffffb80c;
    extern u8 *iGpffffb808;
    extern u16 iGpffffabd4;
    extern void func_003f34e0(void *packet, u32 size);
    u16 var_19;
    s32 var_18;
    u16 temp_17;
    s32 temp_16;
    s32 var_2;
    u8 *temp_3;

    var_19 = iGpffffb810;
    temp_17 = iGpffffb80c;
    if (var_19 != temp_17) {
        iGpffffb810 = 0;
        iGpffffb80c = 0;
        do {
            temp_16 = (var_19 & 0xffff) * 4;
            temp_3 = *(u8 **)((u8 *)iGpffffb808 + temp_16);
            var_18 = *(s32 *)(temp_3 + 4);
            *(s32 *)(temp_3 + 4) = 0;
            if (var_18 > 0) {
                do {
                    if (var_18 >= 0x10000) {
                        var_2 = 0xffff;
                    } else {
                        var_2 = var_18;
                    }
                    func_003f34e0(
                        *(void **)((u8 *)iGpffffb808 + temp_16),
                        (var_2 << 0xc) | 0x42);
                    var_18 = (var_18 - 0x8000) - 0x7fff;
                } while (var_18 > 0);
            }
            var_19 = (var_19 + 1) & 0xffff;
            if (var_19 == iGpffffabd4) {
                var_19 = 0;
            }
        } while ((var_19 & 0xffff) != temp_17);
    }
}
