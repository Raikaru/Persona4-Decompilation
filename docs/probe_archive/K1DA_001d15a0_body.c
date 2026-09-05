/* Faithful threshold lookup recovery, MWCCPS2 b210: object 212B/window 224B.
 * Standard archive replay: 12 differing words = nine t0/t1 index/result
 * allocation differences plus three zero-tail words at +0xd4/+0xd8/+0xdc.
 * func_001d1310 clears and writes EIGHT bytes, including counter +6;
 * stats[4] is required. The old three independent halfwords were not a
 * valid output buffer. func_0022ead0 is s32(void); no hidden argument.
 * The signed-halfword result preserves retail's -1 and 0..24 values.
 * Branches, short-circuit threshold order, 0x19 bound, 0xe0 stride and
 * 0x18 fallback are retained. Production remains INCLUDE_ASM.
 * IDA replay: docs/ida_headstart/src/promoted/code1_001d.c:111-130.
 * Native 32-bit consumer smoke: 9750 cases covering gate values 0/1/2,
 * first-hit precedence, fallback, unsigned high-bit thresholds and all
 * four helper output halfwords. IDA's apparent gate argument is spurious.
 * Tested: direct return, halfword induction, shared result, propagation off,
 * signed result, local-order swap, unsigned induction and wider scalar temps.
 * Reproduce: python tools/probe_variants.py src/promoted/code1_001d.c
 * func_001d15a0 --candidate archive=docs/probe_archive/K1DA_001d15a0_body.c
 */
extern s32 func_0022ead0(void);
s16 func_001d15a0(void)
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
    if (a > *(u16 *)(entry + 0xD8)) goto next;
    if (b > *(u16 *)(entry + 0xDA)) goto next;
    if (c > *(u16 *)(entry + 0xDC)) goto next;
    result = selected;
    goto done;
next:
    index = (index + 1) & 0xFFFF;
test:
    if ((u32)(index & 0xFFFF) < 0x19U) goto loop;
    result = 0x18;
done:
    return (s16)result;
}
