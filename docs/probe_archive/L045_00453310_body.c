/* measured: object 192B vs retail window 192B, normalized_diff 16; differing offsets 16,20,32,40,64,92,100,120,124,128,136,140,160,168,180. Residual is fixed scratch-register coloring / liveness: retail keeps scaled index in $a3 and masked flag in $a0, while b210 keeps index in $t0 and masked flag in $a3; later pointer/byte operations consequently use $a1/$v1 instead of retail $a2/$v1 and $a0. Probes measured: declaration orders (all nd16); direct mask and index-inline spellings (nd16); argument/pointer reuse forms (nd16; compound read-modify-write nd18); index/mask local widths u32 (nd16), u16 (index nd130, mask nd16); parameter arg0/arg1 u32 (nd16); initializer and assignment orders (nd16, nd54); pragma sweep plain16, cse_off43, loopinv16, cse_off_loopinv43, sched110, sched_off16, nobl16, sched_cse_off121, sched_loopinv110, o1 43, o3 110, o1_sched120, o1_nobl43; permuter 2176 compiles best16. No volatile or inline asm used. */
void func_00453310(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_7;
    s32 temp_4;
    u16 *temp_4_2;
    u8 *temp_6;

    temp_7 = arg0 * 0x4A;
    temp_4 = arg1 & 0xFFFF;
    if (temp_4 & *(u16 *)(D_008C0316 + temp_7)) {
        *(u8 *)(D_008C031E + temp_7 + arg2) = 7;
        return;
    }
    if (temp_4 & *(u16 *)(D_008C0314 + temp_7)) {
        temp_6 = D_008C031E + temp_7 + arg2;
        *temp_6 -= 1;
        if (*temp_6 == 0) {
            temp_4_2 = (u16 *)(D_008C031A + temp_7);
            *temp_4_2 |= arg1;
            *temp_6 = 3;
        }
    }
}
