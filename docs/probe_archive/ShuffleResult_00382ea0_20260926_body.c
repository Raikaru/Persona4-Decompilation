/* func_00382ea0 (btlShuffleResult, window 2176B) -- best draft 2026-09-26.
 * fnalign: 539 vs retail 543 instructions, 18 edit instructions (+20
 * reloc-only), down from the owner draft's 72 (+12). Reloc-masked word count
 * is 437 only because the four missing instructions shift everything after
 * them; the aligned residual is exactly four missing `andi`s.
 * Requires the owner's table externs to be two-dimensional:
 *     extern u8 D_0064E6E0[][2];  extern u8 D_0064E700[][2];
 * (retail indexes them base + level*2 + flag; only this function uses them).
 * Levers: the two chance chains are static inline helpers (a 1/0 roll whose
 * result joins in $v0, and the cumulative-weight pick); s32 thresh/chance/sum
 * locals holding explicit (u8) conversions with (u8) casts at the compare
 * (u8 locals made b210 merge the two threshold stores after the join);
 * the weight base pointer `&D_0064E700[0][flag]` is hoisted as in retail.
 * Residual: retail materialises the bonus flag with `sltu $v0; andi $sN,
 * $v0,0xff` (four sites); every spelling tried emits `sltu $sN` directly:
 * u8/s32 flag, (u8)(x != 0), x ? 1 : 0, !!x, (x != 0) & 0xFF, x > 0, u8 and
 * s32 returning helpers, a u8 helper parameter, opt_propagation off,
 * opt_dead_assignments off. The same sltu/andi pair appears only in this
 * unit (also func_00381a70, as an array index). */
/* Roll for the shuffle bonus: nonzero when enabled and a 0-99 roll falls
   under the table threshold for the current bonus level and rate. */
static inline s32 shuffleBonusRoll(u8 *work, s32 rate)
{
    s32 flag;
    s32 thresh;
    s32 chance;

    if (datGetFlag(0x1430) == 0 || datGetFlag(0x11) == 0) {
        return 0;
    }
    flag = (u8)(func_0015a190() != 0);
    if (*(u8 *)(work + 0x12) == 0) {
        thresh = (u8)(D_0064E6E0[0][(u8)flag] + (&iGpffffa9B8)[rate]);
    } else {
        thresh = (u8)(D_0064E6E0[(u8)func_00107890(*(u8 *)(work + 0x12))][(u8)flag] + (&iGpffffa9B8)[rate]);
    }
    chance = (u8)(100.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
    if ((u8)chance < (u8)thresh) {
        return 1;
    }
    return 0;
}

/* Pick the bonus level from the cumulative D_0064E700 weights. */
static inline s32 shuffleBonusPick(void)
{
    s32 flag;
    s32 chance;
    s32 sum;
    s32 i;
    u8 *weights;

    flag = (u8)(func_0015a190() != 0);
    chance = (u8)(100.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
    sum = 0;
    i = 0;
    weights = &D_0064E700[0][(u8)flag];
    for (; i < 0x15; i++) {
        sum = (u8)(sum + weights[i * 2]);
        if (chance < sum) {
            break;
        }
    }
    return i;
}

s32 func_00382ea0(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3)
{
    u8 *unit;
    s32 count;
    s32 i;
    u8 *u;

    unit = func_0036e910(arg0);
    *(u8 **)work = unit;
    *(s32 *)(work + 0xC) = arg1;
    *(u16 *)(work + 0x10) = arg2;
    func_002baac0((u8 *)(*(s32 *)(unit + 0x1F2DC)));
    switch (*(s32 *)(work + 0xC)) {
    case -1:
        func_002bad10(8);
        *(s32 *)(work + 8) = 8;
        return 0;
    case 0:
        if (shuffleBonusRoll(work, arg3) != 0) {
            *(u8 *)(work + 0x12) = shuffleBonusPick() + 1;
            *(u16 *)(work + 4) |= 1;
            *(s32 *)(unit + 0x1F2A0) = func_00377eb0(*(u8 **)(unit + 0x1F2A8), (u8)(*(u8 *)(work + 0x12) - 1));
        }
        *(u16 *)(work + 6) = 0;
        func_002bbd20(0, func_00109220(arg2));
        func_002bad10(0);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 0;
        break;
    case 2:
        if (shuffleBonusRoll(work, arg3) != 0) {
            *(u8 *)(work + 0x12) = shuffleBonusPick() + 1;
            *(u16 *)(work + 4) |= 1;
            *(s32 *)(unit + 0x1F2A0) = func_00377eb0(*(u8 **)(unit + 0x1F2A8), (u8)(*(u8 *)(work + 0x12) - 1));
        } else if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) |= 2;
        }
        func_002bad10(7);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 2;
        break;
    case 3:
        if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) |= 2;
        }
        *(u16 *)(work + 6) = 0;
        func_002bad10(9);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 3;
        break;
    default:
        func_0046d730(D_0064EC70, 0x6C7);
        break;
    }
    if ((*(u16 *)(work + 4) & 2) == 0) {
        u = *(u8 **)work;
        count = func_00378530(*(s32 *)(u + 0x1F304), *(s32 *)(u + 0x1F2FC));
        for (i = 0; i < count; i++) {
            if (i != *(s32 *)(u + 0x1F308)) {
                if (*(u16 *)(u + i * 0xE8 + 0x1D6A0) & 2) {
                    func_0046d730(D_0064EC70, 0x8C);
                }
                func_0036e000(u + i * 0xFB0);
            }
        }
    }
    return 0;
}
