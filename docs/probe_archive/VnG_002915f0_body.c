/*
 * func_002915f0 residual probe (VnG).
 *
 * Best compliant body measured before reverting to INCLUDE_ASM:
 * object_size=408B, window=416B, normalized_diff=8 bytes (two words).
 * Retail and candidate differ only by the order of the independent
 * instructions at offsets 0x10c and 0x110: retail emits
 * andi $a1,$s3,0xffff then addu $v0,$v0,$s5; candidate swaps them.
 *
 * The source required the exact helper declarations already present in the
 * target TU, including the variadic func_0047ae10 ABI declaration.
 */

static inline u8 *code29AddOffBase(u8 *base, s32 offset) {
    u8 *result;
    result = base;
    result = (u8 *)((u32)offset + (u32)result);
    return result;
}

s32 func_002915f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 index;
    s32 flag;
    u8 *slot;
    u8 *entry;
    u8 work[0x40];
    s32 five;

    index = arg3;
    if (*(s32 *)(arg0 + 0x5D8) <= arg3) {
        return 0;
    }
    if (arg2 >= 3) {
        return 0;
    }
    flag = 0;
    slot = code29AddOff(arg2 * 0xC, arg1);
    if ((*(u8 *)(slot + 0x28C) & 1) &&
        (*(s32 *)(slot + 0x290) != 0)) {
        flag = 1;
    }
    if (flag == 1) {
        func_0047ae10(arg1, arg2 & 0xFFFF);
    }
    if (func_0047a510(arg1, arg4, work) == 0) {
        return 0;
    }
    entry = code29AddOff(index * 2, arg0) + 0x604;
    five = 5;
    if (func_00477c40(five, *(u16 *)entry, 0) == 0) {
        u16 weapon;
        u8 *data;
        weapon = (u16)arg2;
        data = code29AddOffBase(arg0, index * 4);
        func_0047ab90(arg1, weapon, five, *(u16 *)entry,
                      *(s32 *)(data + 0x5DC),
                      *(s32 *)(data + 0x618), 1);
    } else {
        func_0047ac90(arg1, (u16)arg2, five, *(u16 *)entry, 0);
    }
    func_0047adf0(arg1, (u16)arg2, arg4);
    return 1;
}
