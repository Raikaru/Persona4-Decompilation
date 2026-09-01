/* object_size=292 window=304 normalized_diff=167 differing_offsets=4,6,7,8,10,11,12,14,16,17,18,19,20,21,22,23 classification=undersized/prologue scheduling and saved-register mapping residual; prologue=frame 0x70, saved $s5/$s4/$s3/$s2/$s1/$s0 six locals, $a0/$a1 incoming pointers, $a2 scratch; declarations corrected at block scope: func_0043f810(void*,void*,u32), func_003eb700(void); measured no_branch_likely on/off; no confirmed compiler floor */
u8 *func_003ebac0(u8 *arg0, u8 *arg1)
{
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern s32 func_003eb700(void);
    u8 *temp_4;
    u8 *var_17;
    u8 *var_21;
    s32 temp_16;
    s32 temp_3;
    s32 var_19;
    u8 *temp_5;
    u8 *var_18;

    temp_3 = *(s32 *)(arg1 + 0xc);
    var_21 = arg0;
    if (*(s32 *)(arg0 + 0xc) == temp_3) {
        temp_4 = *(u8 **)(var_21 + 0x18);
        if (temp_4 != NULL) {
            temp_5 = *(u8 **)(arg1 + 0x18);
            if (temp_5 != NULL && temp_3 < 9) {
                func_0043f810(temp_4, temp_5, (1 << temp_3) * 4);
            }
        }
        temp_16 = ((*(s32 *)(var_21 + 0xc) + 7) >> 3) * *(s32 *)(var_21 + 4);
        var_18 = *(u8 **)(arg1 + 0x14);
        var_17 = *(u8 **)(var_21 + 0x14);
        var_19 = 0;
        if (*(s32 *)(var_21 + 8) > 0) {
            do {
                func_0043f810(var_17, var_18, temp_16);
                var_19 += 1;
                var_17 += *(s32 *)(var_21 + 0x10);
                var_18 += *(s32 *)(arg1 + 0x10);
            } while (var_19 < *(s32 *)(var_21 + 8));
        }
    } else if (func_003eb700() == 0) {
        var_21 = NULL;
    }
    *(s32 *)var_21 &= ~2;
    *(s32 *)var_21 |= *(s32 *)arg1 & 2;
    return var_21;
}
