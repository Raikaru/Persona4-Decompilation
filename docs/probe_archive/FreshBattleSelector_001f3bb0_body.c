/* Fresh battle selector func_001f3bb0; production remains ASM.
 * Preferred initial owner-context replay: 968/944 bytes, nd678, 17 object relocations;
 * 24-byte overrun included. Explicit head snapshot ties 968/nd678. Proven narrow
 * count/level locals regress to 972/nd715. No native behavioral verification.
 * 
 * Zero-input s32 selector. Preserves both full list scans, callback reloads, last
 * qualifying attribute selection, absent index5 mapping, and val1-before-val2
 * precedence. Metadata bit0x40 wins over bit0x80. Enemy-count rejection precedes
 * skill/level queries; enemy-minus-hero level advantage is at least four.
 * Actual slot input is signed16. Eight-entry retail jump tables at00747210 and
 * 007471F0 map indices0,1,2,3,4,6,7; index5 leaves the previous result unchanged.
 * 
 * Replay replaces only the owner's ASM slot, with the following five declarations.
 * Existing owner provides the two global pointers and func_00106330/func_001ef720.
 * No production declaration changes or unmatched source promotion are made.
 */

extern u8 *func_0010a900(u16 arg0);
extern s32 func_0010ce10(u8 *arg0, s32 arg1);
extern s32 func_001ef4d0(s32 arg0, s32 arg1);
extern s32 func_00231e20(s32 arg0);
extern s32 func_00242800(s32 arg0, s16 arg1);
// FUN_001F3BB0
s32 func_001f3bb0(void)
{
    s32 count;
    s32 actor;
    s32 has_skill;
    s32 avg_level;
    s32 hero_level;
    s32 level_advantage;
    u8 *node;
    u16 flags;
    s32 val1;
    s32 val2;
    s16 i;

    count = func_001ef720(2, 0x80000) & 0xFFFF;
    if (count >= 6) {
        return -1;
    }

    if (func_00106330(0x38) != 0) {
        actor = 5;
    } else {
        actor = 8;
    }
    has_skill = func_0010ce10(func_0010a900(actor & 0xFFFF), 0x10D) != -1;

    avg_level = func_001ef4d0(2, 0x80000) & 0xFFFF;
    hero_level = func_00231e20(*(s32 *)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) + 0xA64)) & 0xFF;
    level_advantage = (avg_level - hero_level) >= 4;

    for (node = *(u8 **)(iGpffffb3ac + 0x180); node != NULL; node = *(u8 **)(node + 0xA6C)) {
        flags = *(u16 *)(iGpffffb3c4 + (*(u16 *)(node + 0xA4) * 0x3C));
        if ((flags & 0x40) != 0) {
            return 1;
        }
        if ((flags & 0x80) != 0) {
            return 0;
        }
    }

    if (has_skill) {
        val1 = -1;
        val2 = -1;

        for (node = *(u8 **)(iGpffffb3ac + 0x180); node != NULL; node = *(u8 **)(node + 0xA6C)) {
            for (i = 0; i < 8; i++) {
                if ((func_00242800(*(s32 *)(node + 0xA64), i) & 0x07000000) != 0) {
                    switch (i) {
                    case 0:
                        val1 = 0x17;
                        break;
                    case 1:
                        val1 = 0x18;
                        break;
                    case 2:
                        val1 = 0x19;
                        break;
                    case 3:
                        val1 = 0x1B;
                        break;
                    case 4:
                        val1 = 0x1A;
                        break;
                    case 6:
                        val1 = 0x1C;
                        break;
                    case 7:
                        val1 = 0x1D;
                        break;
                    }
                }
            }
        }

        for (node = *(u8 **)(iGpffffb3ac + 0x180); node != NULL; node = *(u8 **)(node + 0xA6C)) {
            for (i = 0; i < 8; i++) {
                if ((func_00242800(*(s32 *)(node + 0xA64), i) & 0x08000000) != 0) {
                    switch (i) {
                    case 0:
                        val2 = 0x1E;
                        break;
                    case 1:
                        val2 = 0x1F;
                        break;
                    case 2:
                        val2 = 0x20;
                        break;
                    case 3:
                        val2 = 0x22;
                        break;
                    case 4:
                        val2 = 0x21;
                        break;
                    case 6:
                        val2 = 0x23;
                        break;
                    case 7:
                        val2 = 0x24;
                        break;
                    }
                }
            }
        }

        if (val1 != -1) {
            return val1;
        }
        if (val2 != -1) {
            return val2;
        }
    }

    if (level_advantage) {
        return 2;
    }

    switch (*(u16 *)(iGpffffb3ac + 0x1A)) {
    case 0:
        return count + 2;
    case 1:
        return count + 7;
    case 2:
        return count + 12;
    default:
        return -1;
    }
}
