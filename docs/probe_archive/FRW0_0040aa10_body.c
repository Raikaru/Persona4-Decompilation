/* object_size=80 window=80 normalized_diff=0 differing_offsets=none; classification=standalone MMI floor: retail contains pcpyld $a3,$a0,$v1 with no COP2/VU0 instruction in the statement/function. Per H009, do not force this ordinary MMI with inline asm; retained INCLUDE_ASM. */
extern u8 *iGpffffb884;
extern s128 D_0088CAF0;
extern s128 D_0088CB00;
extern s128 D_0088CB70;
void func_0040aa10(void)
{
    u8 *temp_6;
    u_long128 packed;
    u64 zero;
    u64 constant;

    temp_6 = iGpffffb884;
    *(s128 *)(temp_6 + 0) = D_0088CB00;
    zero = 0;
    constant = 0x11000000;
    packed = _pcpyld(zero, constant);
    *(s128 *)(temp_6 + 0x10) = packed;
    *(s128 *)(temp_6 + 0x20) = D_0088CAF0;
    *(s128 *)(temp_6 + 0x30) = D_0088CB70;
    iGpffffb884 = temp_6 + 0x40;
}
