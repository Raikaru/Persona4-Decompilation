/* lane W42c20 probe for func_00201b00 (0x00201b00)
 * measured: obj 704B, window 688B, differing words 151 (fndiff)
 * levers tried: u16 temp_4 for arg0[0x2C], if/else-if for var_5,
 *   explicit (var_18 | X) & 0xFFFF, forward decl func_0020e250, (s32 *)&sp60.
 */

s32 func_00201b00(u8 *arg0)
{
    u16 var_18;
    u16 temp_4;
    s32 var_5;
    s32 var_17;
    s32 var_16;
    f32 sp50[3];
    struct { s32 a; s32 b; s16 c; } sp60;
    s32 val;
    u8 *table;
    s32 idx;

    extern s32 func_0023d8e0(u8 *arg0, s32 arg1);
    extern s32 func_0023d6e0(s16 arg0);
    extern void func_00195ea0(u8 *arg0, f32 *arg1);
    extern void func_001959d0(u8 *arg0, f32 *arg1);

    var_18 = 0;
    temp_4 = *(u16 *)(arg0 + 0x2C);
    if ((temp_4 & 4) == 0) {
        if ((*(s32 *)(arg0 + 8) == 0) &&
            (*(s32 *)(arg0 + 0xC) == 0) &&
            (*(s32 *)(arg0 + 0x10) == 0) &&
            (*(s32 *)(arg0 + 0x14) == 0) &&
            (*(s32 *)(arg0 + 0x18) == 0)) {
            var_5 = 1;
        } else {
            var_5 = 0;
        }
    } else {
        var_5 = 1;
    }

    var_17 = *(s32 *)(arg0 + 8);
    if (var_17 != 0) {
        var_18 = (var_18 | 0x10) & 0xFFFF;
    } else {
        var_17 = 0;
    }

    var_16 = *(s32 *)(arg0 + 0xC);
    if (var_16 != 0) {
        var_18 = (var_18 | 0x20) & 0xFFFF;
    } else {
        var_16 = 0;
    }

    if (*(u16 *)(arg0 + 0x32) == *(u16 *)(arg0 + 0x30) + 1) {
        if (var_5 == 0) {
            val = *(u16 *)(arg0 + 0x2E);
            if (val & 2) {
                var_18 = (var_18 | 1) & 0xFFFF;
            }
            if (val & 4) {
                var_18 = (var_18 | 2) & 0xFFFF;
            }
        }

        if (temp_4 & 0x100) {
            val = *(s32 *)(arg0 + 0x28);
            if ((val != -1) && ((*(u8 **)(*(u8 **)arg0 + 0xA64)) != NULL)) {
                val = func_0023d8e0(*(u8 **)(*(u8 **)arg0 + 0xA64), val & 0xFFFF);
                val = func_0023d6e0((s16)val);
            } else {
                val = 0;
            }
            if (!(val & 0x1FE00)) {
                var_18 = (var_18 | 8) & 0xFFFF;
            } else {
                var_18 = (var_18 | 4) & 0xFFFF;
            }
        } else if (var_5 != 0) {
            var_18 = (var_18 | 4) & 0xFFFF;
        }

        if (*(s32 *)(arg0 + 0x10) & 0x100000) {
            var_18 = (var_18 | 0x40) & 0xFFFF;
        }
    }

    idx = *(s32 *)(arg0 + 0x28);
    if (idx >= 0) {
        table = iGpffffb3b8;
        val = *(u8 *)(table + idx * 0x28 + 8);
        if ((val == 2) || (val == 1)) {
            var_18 = (var_18 | 0x80) & 0xFFFF;
        }
        if (*(u8 *)(table + idx * 0x28) & 0x20) {
            var_18 = (var_18 & 0xFFFB) & 0xFFFF;
        }
    }

    sp60.a = var_17;
    sp60.b = var_16;
    sp60.c = (s16)var_18;
    if (*(s32 *)(arg0 + 0x34) != 0) {
        func_00195ea0(*(u8 **)(arg0 + 4), sp50);
    } else {
        func_001959d0(*(u8 **)(arg0 + 4), sp50);
    }

    func_0020e250(*(u8 **)(iGpffffb3ac + 0xDD4), (s32)*(u8 **)(arg0 + 4), (s32 *)&sp60, sp50, *(u16 *)(arg0 + 0x38));
    return 1;
}
