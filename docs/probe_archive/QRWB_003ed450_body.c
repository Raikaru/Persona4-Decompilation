/* object_size=208 window=240 normalized_diff=131 differing_offsets=16,17,18,19,20,22,25,28,30,32,34,36,38,39,40,41 classification=undersized near-miss; ruled_out=movz/movn/COP1 accumulator/MMI/tail-jump floors absent; nested sentinel if/while emitted duplicate initial guard shape, but candidate remained 32 bytes short */
void func_003ed450(u8 *arg0, s32 arg1)
{
    extern void func_003e05f0(u8 *arg0, u8 *arg1, s32 arg2);
    s32 temp_19;
    u8 *temp_16;
    u8 *var_18;
    u8 *var_21;
    u8 *flag;

    var_21 = arg0;
    if (var_21 != NULL) {
        do {
            flag = var_21 + 3;
            temp_19 = arg1 | *flag;
            if ((temp_19 & 4) != 0) {
                func_003e05f0(
                    var_21 + 0x50,
                    var_21 + 0x10,
                    *(s32 *)(var_21 + 4) + 0x50);
            }
            var_18 = *(u8 **)(var_21 + 0x90);
            temp_16 = var_21 + 0x90;
            if (var_18 != temp_16) {
                while (var_18 != temp_16) {
                    ((void (*)(u8 *))*(u32 *)(var_18 + 8))(var_18 - 8);
                    var_18 = *(u8 **)(var_18 + 0);
                }
            }
            *flag &= (u8)~0xc;
            func_003ed450(*(u8 **)(var_21 + 0x98), temp_19);
            var_21 = *(u8 **)(var_21 + 0x9c);
        } while (var_21 != NULL);
    }
}
