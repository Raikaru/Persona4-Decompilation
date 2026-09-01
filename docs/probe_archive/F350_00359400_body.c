/* object_size=652B; window=672B; normalized_diff=165; first_diffs=0x2C,0x16C,0x175,0x17A,0x17E,0x182,0x184,0x18D-0x18E,0x191-0x192,0x195-0x196,0x199-0x19A,0x19D; best measured candidate archived. */
/* Explicit first-loop offset and separate table-loop index make the first loop byte-exact. #pragma opt_loop_invariants on hoists the 2^31/0x80000000 conversion constants, but the remaining second-loop register colouring and branch-join residual did not match; source restored to INCLUDE_ASM. */
s32 func_00359400(u8 *arg0, s32 arg1)
{
    extern u8 D_0064B420[];
    extern u8 D_0064B8E0[];
    extern u8 D_0064BDA0[];
    extern u8 D_0064C260[];
    extern u8 D_0064C720[];
    u8 *table;
    u8 *dst;
    u8 *src;
    f32 value;
    s32 i;
    s32 j;
    s32 off;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 43; i++) {
        off = i * 0x30;
        dst = arg0 + off;
        *(f32 *)(dst + 0x150) = *(f32 *)(dst + 0x160);
        *(f32 *)(dst + 0x154) = *(f32 *)(dst + 0x164);
        *(u16 *)(dst + 0x16C) = *(u16 *)(dst + 0x170);
        *(u16 *)(dst + 0x172) = *(u16 *)(dst + 0x176);
        *(u8 *)(dst + 0x168) = *(u8 *)(dst + 0x16A);
    }
    switch (arg1) {
    case 0:
        table = D_0064B420;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 1:
        table = D_0064BDA0;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 2:
        table = D_0064C260;
        *(s32 *)(arg0 + 0x1C) = 55;
        break;
    case 3:
        table = D_0064C720;
        *(s32 *)(arg0 + 0x1C) = 70;
        *(s16 *)(arg0 + 0x14C) = 17;
        break;
    case 4:
        table = D_0064B8E0;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    default:
        func_0046d730(&D_0064CC98, 0x51F);
        break;
    }
    if (table != NULL) {
        for (j = 0; j < 43; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0x158) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x15C) = *(f32 *)(src + 4);
            value = *(f32 *)(src + 8);
            if (value >= 2147483648.0f) {
                *(u16 *)(dst + 0x16E) =
                    (u16)(((s32)(value - 2147483648.0f) | 0x80000000));
            } else {
                *(u16 *)(dst + 0x16E) = (u16)(s32)value;
            }
            value = *(f32 *)(src + 0xC);
            if (value >= 2147483648.0f) {
                *(u16 *)(dst + 0x174) =
                    (u16)(((s32)(value - 2147483648.0f) | 0x80000000));
            } else {
                *(u16 *)(dst + 0x174) = (u16)(s32)value;
            }
            *(u8 *)(dst + 0x169) = *(u8 *)(src + 0x10);
            *(s32 *)(dst + 0x178) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x17C) = *(s32 *)(src + 0x18);
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
