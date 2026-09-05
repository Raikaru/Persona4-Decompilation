/* Corrected reference candidate; NOT MATCHING.
 * Measured: object 212B / retail window 224B, 15 differing emitted bytes
 * after relocation masking. fndiff counts 18 words including three absent
 * zero-tail words. Register allocation and comparison destinations remain.
 * The output helper writes eight bytes: separate scalar locals were not a
 * valid buffer. Keep stats[4], the masked loop index, and the real argument.
 */
s64 func_001d15a0(void)
{
    u16 stats[4];
    s32 index;
    u16 selected;
    u16 result;
    s32 a;
    s32 b;
    s32 c;
    u8 *table;
    u8 *entry;

    if (func_0022ead0() == 1) return -1;
    func_001d1310(stats);
    index = 0;
    a = stats[0];
    b = stats[1];
    c = stats[2];
    table = D_00607E50;
    goto test;
loop:
    selected = (u16)index;
    entry = table + (s32)selected * 0xE0;
    if (*(u16 *)(entry + 0xD8) >= a &&
        *(u16 *)(entry + 0xDA) >= b &&
        *(u16 *)(entry + 0xDC) >= c) {
        result = selected;
        goto done;
    }
    index = (index + 1) & 0xFFFF;
test:
    if ((u32)(index & 0xFFFF) < 0x19U) goto loop;
    result = 0x18;
done:
    return (s16)result;
}
