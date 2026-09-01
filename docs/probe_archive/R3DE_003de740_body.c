/* object 376B / window 384B / normalized_diff 193 / differing offsets 4,6,7,8,10,11,12,14,16-23,... / classification undersized-by-window near miss after exact 0x40 frame; retail saves s0-s1, candidate saves s0-s1; latest measured lq/sq aggregate probe; explicit dispatch-chain probe was not remeasured after parent cutoff; restored to ASM. */
void func_003de740(s128 *arg0, u8 *arg1, s64 arg2, s32 arg3) {
    extern s32 func_004270f8(s32 arg0, s32 arg1, s32 arg2);
    s64 sp30;
    unsigned __int128 scratch;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4_2;
    s64 temp_4;
    s64 temp_8;
    s64 var_7;
    u8 *self;

    temp_3 = 3;
    temp_8 = *(s64 *)(arg1 + 0x10);
    temp_4 = *(s64 *)arg1;
    if (arg3 == temp_3)
        goto case3;
    self = arg1;
    temp_3 = 2;
    if (arg3 == temp_3)
        goto case2;
    temp_3 = 1;
    if (arg3 == temp_3)
        goto case1;
    goto case_default;
case1:
    var_7 = (s64)(arg2 << 32) >> 32;
    goto block_8;
case2:
    var_7 = temp_8 + ((s64)(arg2 << 32) >> 32);
    goto block_8;
case3:
    var_7 = temp_4 - ((s64)(arg2 << 32) >> 32);
    goto block_8;
case_default:
    sp30 = -1;
    __asm__ volatile (
        "sd %0, 0x30($sp)\n"
        "lq $v1, 0x30($sp)\n"
        "sq $v1, 0(%1)"
        :
        : "r"(sp30), "r"(arg0), "m"(scratch)
        : "$v1", "memory");
    return;
block_8:
    if (temp_4 < var_7) {
        var_7 = temp_4;
    } else if (var_7 < 0) {
        var_7 = 0;
    }
    temp_2 = *(s32 *)(self + 0x6C);
    temp_3 = *(s32 *)(self + 0x64);
    if (temp_3 < temp_2) {
        temp_4_2 = temp_8 - (s64)((s64)temp_3 << 32 >> 32);
        if (var_7 >= temp_4_2 &&
            temp_8 + (s64)((s64)(temp_2 - temp_3) << 32 >> 32) >= var_7) {
            *(s32 *)(self + 0x64) =
                (s32)((s64)((s64)(var_7 - temp_4_2) << 32) >> 32);
            __asm__ volatile (
                "lq $v1, 0x10(%0)\n"
                "sq $v1, 0(%1)"
                :
                : "r"(self), "r"(arg0)
                : "$v1", "memory");
            return;
        }
    }
    *(s32 *)(self + 0x38) = 3;
    *(s32 *)(self + 0x64) = *(s32 *)(self + 0x6C);
    *(s64 *)(self + 0x10) = var_7;
    func_004270f8(*(s32 *)(self + 0x60),
                  (s32)((s64)(var_7 << 32) >> 32), 0);
    if (*(s32 *)(self + 0x30) == 0)
        *(s32 *)(self + 0x38) = 2;
    __asm__ volatile (
        "lq $v1, 0x10(%0)\n"
        "sq $v1, 0(%1)"
        :
        : "r"(self), "r"(arg0)
        : "$v1", "memory");
}
