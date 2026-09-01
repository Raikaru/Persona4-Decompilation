/* measured: object=16 window=16 normalized_diff=9 under ee-gcc -O2 -G0; reverted to INCLUDE_ASM because the nonvolatile C body did not match. */
s32 func_004de2b0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = 1;
    return 1;
}
