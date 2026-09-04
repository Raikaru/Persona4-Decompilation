/*
 * func_00484b30 honest-C floor probe (not live).
 *
 * Measured object_size=116B; retail_window=128B; normalized_diff=45.
 * tools/fndiff.py differing words (reloc-masked)=24 at offsets 0x20-0x7C
 * inclusive (every 4-byte word). The first-party body has four stores of a
 * zero u_long128 in place of retail's sqc2 vf0 stores, and a typed aggregate
 * copy from D_00713CE0. MWCC emits GPR quadword stores for the zero value;
 * no honest C expression emits the retail COP2 sqc2 vf0 register side effect.
 * A probe of _sqc2 resolved to an external call and was discarded. VU0
 * register pragmas also worsened the measured body. This is therefore an
 * honest semantic floor, not a byte-match candidate.
 */
void func_00484b30(u8 *arg0)
{
    s32 temp;
    u_long128 zero;
    u_long128 *quadSrc;

    zero = 0;
    func_0043f9c8(arg0, 0, 0x80);
    *(u_long128 *)(arg0 + 0x00) = zero;
    *(u_long128 *)(arg0 + 0x10) = zero;
    *(u_long128 *)(arg0 + 0x40) = zero;
    temp = 0x40A00000;
    *(s32 *)(arg0 + 0x44) = temp;
    *(u_long128 *)(arg0 + 0x50) = zero;
    quadSrc = (u_long128 *)D_00713CE0;
    *(u_long128 *)(arg0 + 0x20) = *quadSrc;
    temp = 0x3F800000;
    *(s32 *)(arg0 + 0x60) = temp;
    *(s32 *)(arg0 + 0x74) = temp;
    temp = -1;
    *(s32 *)(arg0 + 0x64) = temp;
    temp = 0x80;
    *(s32 *)(arg0 + 0x68) = temp;
}
