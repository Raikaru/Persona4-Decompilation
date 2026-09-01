/* measured: object 344/window 368, normalized_diff 145, differing offsets 34,38,64,74,104,117,122,139,144,146,147,148,149,150,152,153; instruction deficit 6 (24 bytes), likely missing/merged control-flow block; all five floor families ruled out. Prologue retail saves s3/s2/s1/s0 (4), arg0 u8*, status pointer; block-scope declarations corrected for func_00231d70(void) and func_00232730(u8 *, s32). */
s32 func_001f6770(u8 *arg0)
{
    extern u32 func_00231d70(void);
    extern s32 func_00232730(u8 *arg0, s32 arg1);
    u16 chance;
    u32 mask;
    u8 *status;
    u32 i;

    status = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    if (func_00232710((s32)status, 0x100000) != 0) {
        return 1;
    }
    if (func_00232710((s32)status, 0x1001DF) == 0) {
        return 0;
    }
    chance = 100;
    mask = 0;
    if (func_002326c0(status) == 4) {
        chance = 70;
        mask = 4;
    }
    chance &= 0xFFFF;
    if (chance == 100) {
        return 1;
    }
    chance = func_00231d70() < chance;
    if (chance == 0 && func_00232730(status, 0x230) != 0) {
        i = 0;
        do {
            if ((mask & (1 << i)) != 0) {
                if (*(u8 *)(arg0 + i + 0x3F6) > 0) {
                    return 1;
                }
                *(u8 *)(arg0 + i + 0x3F6) += 1;
                break;
            }
            i++;
        } while (i < 0x18);
    }
    return chance;
}
