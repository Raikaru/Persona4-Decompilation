/* archived candidate: object 372B / retail window 384B / normalized_diff 42
   differing offsets: 0x20-0x34, 0x48-0x50, 0x84, 0x9c-0xb4, 0xd0-0x148
   Best source shape: u32 arg0, pointer locals, COP2 sqc2 vf0 statement.
   Ruled out: u16 arg0 (object 376B, nd 111), 20 declaration-order permutations
   (all nd 42), removing s3 local (nd 42), integer 0x60 temp (nd 263),
   pointer/address cast variants and callback parameter variants (nd 42+).
   Residual is saved-register/constant-cache coloring: retail keeps arg0/$s5,
   arg1/$s4, and hoists 0x60 into $s1; MWCC hoists 0xffff and rotates values.
*/

u8 *func_004aaee0(u32 arg0, s32 arg1) {
    s32 (*temp_2_2)(u8 *);
    s32 temp_16;
    s32 temp_18;
    u8 *temp_2;
    u8 *temp_4;
    u8 *s3;

    temp_16 = arg0 & 0xFFFF;
    temp_18 = *(s32 *)(D_007143A4 + temp_16 * 0x18);
    if ((u32)(temp_18 + 0x60) >= 0x200U) {
        func_0046d730(D_00714450, 0x170);
    }
    func_0044ea90(D_00714450, 0x171);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_18 + 0x60, 0x40000);
    func_0043f9c8(temp_2, 0, temp_18 + 0x60);
    if (temp_2 == (u8 *)0) {
        func_0046d730(D_00714380, 0x63B);
    }
    *(s32 *)(temp_2 + 0x18) = temp_16;
    *(s32 *)(temp_2 + 0x10) = -1;
    *(s32 *)(temp_2 + 0x14) = 0x3F800000;
    *(s32 *)(temp_2 + 0x28) = 0;
    s3 = temp_2;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(s3) : "memory");
    temp_4 = temp_2 + 0x60;
    *(u8 **)(temp_2 + 0x24) = temp_4;
    func_0043f810(temp_4, (const void *)arg1, temp_18);
    temp_2_2 = (s32 (*)(u8 *))(*(u8 **)(D_00714390 + ((arg0 & 0xFFFF) * 0x18)));
    if (temp_2_2 != (s32 (*)(u8 *))0) {
        *(s32 *)(temp_2 + 0x20) = temp_2_2(*(u8 **)(temp_2 + 0x24));
    }
    *(s16 *)(temp_2 + 0x44) = 0x16;
    *(u8 **)(temp_2 + 0x48) = temp_2;
    return temp_2;
}
