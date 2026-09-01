/* measured: object 192B vs retail window 192B, normalized_diff 16; differing offsets 16,20,32,40,64,92,100,120,124,128,136,140,160,168,180. Residual is fixed scratch-register colouring / liveness: retail keeps scaled index in $a3 and masked flag in $a0, while b210 keeps index in $t0 and masked flag in $a3; later pointer/byte operations consequently use $a1/$v1 instead of retail $a2/$v1 and $a0. Probes measured: local declaration permutations, pointer/index locals, block-scope locals, parameter reuse, register hints; all retained the same nd16 residual. No volatile or inline asm used. */
void func_00453250(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_4;
    u8 *temp_6;
    u16 *temp_4_2;
    s32 temp_7;

    temp_7 = arg0 * 0x4A;
    temp_4 = arg1 & 0xFFFF;
    if (temp_4 & *(u16 *)(D_008C02EE + temp_7)) {
        *(u8 *)(D_008C0300 + temp_7 + arg2) = 7;
        return;
    }
    if (temp_4 & *(u16 *)(D_008C02EC + temp_7)) {
        temp_6 = D_008C0300 + temp_7 + arg2;
        *temp_6 -= 1;
        if (*temp_6 == 0) {
            temp_4_2 = (u16 *)(D_008C02F2 + temp_7);
            *temp_4_2 |= arg1;
            *temp_6 = 3;
        }
    }
}
