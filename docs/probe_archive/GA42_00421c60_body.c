/* measured: object=16 window=16 normalized_diff=12; reverted to INCLUDE_ASM. */
u32 func_00421c60(void)
{
    u32 segment = 0x00710000;
    *(u32 *)(segment - 0x3A30) = 0;
    return segment;
}
