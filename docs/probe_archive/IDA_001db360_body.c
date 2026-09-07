/* Measured: 544B/window 544B, 10 fully relocated executable differing words.
 * Promoted u16 command values and short-circuit continuation remove the
 * previous 17-word floor's register/mask residuals. Block ordering remains.
 * All 257 owner C functions preserve bytes/relocations. The actual bitmap
 * provider and this predicate pass 15,360 ASan/UBSan consumer cases.
 * KEEP_ASM; see docs/matching.md for current evidence.
 */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern s32 func_001f9ce0(u8 *formation, s32 index);
extern u32 func_0010f420(u32 enemy, u32 index);
extern s32 func_0023d6e0(s16 index);
extern s8 func_00233a90(u8 *unit, s32 status);
extern u32 func_0023e130(u8 *unit);
extern u8 *func_0023e140(u8 *unit);
extern s32 func_00242800(u8 *unit, s32 index);

// FUN_001DB360
s32 func_001db360(u8 *formation, s32 index, s32 enabled)
{
    u8 *unit;
    s32 flags;
    u16 count;
    u16 *commands;
    u16 i;
    s32 limit;
    s32 command;
    s32 key1;
    s32 key2;
    s32 key3;

    unit = *(u8 **)(formation + 0x30);
    if (*(u8 *)(unit + 0xA2) == 1 &&
        func_001f9ce0(formation, (s16)index) == 0) {
        u32 queryIndex = (u16)index;
        if (func_0010f420(*(u16 *)(unit + 0xA4), queryIndex) == 0)
            return 1;
    }

    flags = func_0023d6e0((s16)index);
    if (enabled == 1 && !(flags & 0xE0001)) {
        if (flags & 2) {
            if (func_00233a90(*(u8 **)(unit + 0xA64), 0x10) > 0)
                return 0;
        } else if (!(flags & 0x40) &&
                   func_00233a90(*(u8 **)(unit + 0xA64), 0x11) > 0) {
            return 0;
        }
    }

    if (flags & 2) {
        if (*(u8 *)(unit + 0xA2) == 1) {
            if (*(u16 *)*(u8 **)(unit + 0xA64) & 0x100)
                return 0;
        } else {
            count = func_0023e130(*(u8 **)(unit + 0xA64));
            commands = (u16 *)func_0023e140(*(u8 **)(unit + 0xA64));
            i = 0;
            limit = count;
            key1 = 0x1F8;
            key2 = 0x1F7;
            key3 = 0x1F6;
            while (i < limit) {
                command = commands[i];
                if (command != key1 && command != key2 && command != key3) {
                    ++i;
                    continue;
                }
                return 0;
            }
        }
    }
    return !(func_00242800(*(u8 **)(unit + 0xA64), (s16)index) & 0x07000000);
}

#pragma pop
