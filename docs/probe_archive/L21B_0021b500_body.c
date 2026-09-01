/* object 300B; retail window 304B; normalized_diff 8; differing offsets 0x3C, 0x40, 0x7C, 0x80, 0xBC, 0xC0, 0xFC, 0x100; retail-only tail pad 0x12C. Probes: union-packed u8 conversion baseline; s32/u32/s16/u16/u8 temporary and argument widths; declaration orders; separate masked/shifted locals; OR operand reversal and |=; direct OR expressions; mask-first versus shift-first statement order; parameter reuse and compound OR; signed/unsigned union word; scalar stack extraction; signed-mask casts; O1 and opt_common_subs; 1279 permuter compiles/120s. Best legal plain-C body; residual is the compiler's v1 (ANDI-dest) versus retail a1 (SRL-dest) OR/MT1 colouring at four repeated sites. */
void func_0021b500(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5)
{
    union {
        s32 word;
        u8 bytes[4];
    } spC;
    f32 var_f0;

    spC.word = arg1;
    *(f32 *)(arg0 + 0) = fparg0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg2;
    if ((s32)spC.bytes[0] >= 0) {
        var_f0 = (f32)(s32)spC.bytes[0];
    } else {
        var_f0 = (f32)(s32)(((u32)spC.bytes[0] >> 1) |
                             ((u32)spC.bytes[0] & 1));
        var_f0 = var_f0 + var_f0;
    }
    *(f32 *)(arg0 + 0x20) = var_f0;
    if ((s32)spC.bytes[1] >= 0) {
        var_f0 = (f32)(s32)spC.bytes[1];
    } else {
        var_f0 = (f32)(s32)(((u32)spC.bytes[1] >> 1) |
                             ((u32)spC.bytes[1] & 1));
        var_f0 = var_f0 + var_f0;
    }
    *(f32 *)(arg0 + 0x24) = var_f0;
    if ((s32)spC.bytes[2] >= 0) {
        var_f0 = (f32)(s32)spC.bytes[2];
    } else {
        var_f0 = (f32)(s32)(((u32)spC.bytes[2] >> 1) |
                             ((u32)spC.bytes[2] & 1));
        var_f0 = var_f0 + var_f0;
    }
    *(f32 *)(arg0 + 0x28) = var_f0;
    if ((s32)spC.bytes[3] >= 0) {
        var_f0 = (f32)(s32)spC.bytes[3];
    } else {
        var_f0 = (f32)(s32)(((u32)spC.bytes[3] >> 1) |
                             ((u32)spC.bytes[3] & 1));
        var_f0 = var_f0 + var_f0;
    }
    *(f32 *)(arg0 + 0x2C) = var_f0;
    *(f32 *)(arg0 + 0x10) = fparg3;
    *(f32 *)(arg0 + 0x14) = fparg4;
    *(f32 *)(arg0 + 0x18) = fparg5;
}
