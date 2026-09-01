/* RnB best candidate archive for func_004ab420.
   Object/window: 372B / 384B. Normalized diff: 6 words (3 differing rows).
   Differing offsets: 0x28, 0xEC, 0x104.
   Residual is the measured constant-cache floor: retail hoists 0x60 in $s1,
   while MWCC hoists 0xFFFF in $s1. Thus retail has addiu $s1,0x60;
   addu $a0,$s3,$s1; andi $v1,$s5,0xffff, while this candidate emits
   ori $s1,0xffff; addiu $a0,$s3,0x60; and $v1,$s5,$s1.
   Ruled out: original `(u32)(size + 0x60)` assertion (32 words); u16 arg0
   (direct and implicit-narrowing forms, 348-360B, 89-90 words); u16 local
   narrowing forms (348-360B, 89-90 words); s32 off=0x60 forms (frame 0x80,
   89 words); O1 and opt_common_subs off (frame 0x60, about 90 words);
   opt_propagation off (32 words); callback/pointer and declaration-order
   variants (32 words); prior archive spelling (372B, 42 words).
   No new pool/string data refs. Added D_00714474/D_00714460/global/function
   references are existing, placeable symbols; sqc2 is the required COP2 op.
*/

u8 *func_004ab420(u32 arg0, s32 arg1) {
    s32 (*temp_2_2)(s32);
    s32 temp_16;
    u8 *temp_2;
    s32 temp_18;
    u8 *temp_4;
    u8 *s3;

    temp_16 = arg0 & 0xFFFF;
    temp_18 = *(s32 *)(D_00714474 + temp_16 * 0x18);
    if ((u32)temp_18 + 0x60 >= 0x200U) {
        func_0046d730(D_00714450, 0x170);
    }
    func_0044ea90(D_00714450, 0x171);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_18 + 0x60, 0x40000);
    s3 = temp_2;
    func_0043f9c8(s3, 0, temp_18 + 0x60);
    if (s3 == (u8 *)0) {
        func_0046d730(D_00714380, 0x706);
    }
    *(s32 *)(s3 + 0x18) = temp_16;
    *(s32 *)(s3 + 0x10) = -1;
    *(s32 *)(s3 + 0x14) = 0x3F800000;
    *(s32 *)(s3 + 0x28) = 0;
    __asm__ ("sqc2 vf0, 0(%0)" : : "r"(s3) : "memory");
    temp_4 = s3 + 0x60;
    *(u8 **)(s3 + 0x24) = temp_4;
    func_0043f810(temp_4, (const void *)arg1, temp_18);
    temp_2_2 = (s32 (*)(s32))(*(u8 **)(D_00714460 + ((arg0 & 0xFFFF) * 0x18)));
    if (temp_2_2 != (s32 (*)(s32))0) {
        *(s32 *)(s3 + 0x20) = temp_2_2(arg1);
    }
    *(s16 *)(s3 + 0x44) = 0x17;
    *(u8 **)(s3 + 0x48) = s3;
    return s3;
}
