/* object 536B, window 512B, normalized_diff 303; differing offsets begin 0x28,0x3C,0x48,0x70,0x79-0x80; classification=oversized near-miss with correct frame/saved-s-register count and node/value register mapping after declaration swap; ruled_out=movz/movn, COP1 accumulator MAC, standalone MMI H009, framed tail-jump, sd-saved-register floor, COP2/VU0. Retail uses dsll32/dsrl32 byte-clear idioms and compact 32-bit arithmetic; candidate's s64-to-s32 spelling expands shifts and candidate still has control-flow/temporary ordering residuals. */
void func_001d6680(void)
{
    extern void func_00478e70(s32 arg0);
    extern void func_00479100(u8 *arg0, s32 arg1);
    extern void func_0047a220(s32 arg0, s32 *arg1);
    extern void func_00481440(u8 *arg0);
    extern void func_00485630(s32 arg0);
    extern void func_00485870(s32 arg0);
    extern void func_004865c0(s32 arg0, s32 arg1);
    extern u8 D_005DC7D0[];
    extern u8 D_00794150[];
    u8 *node;
    s32 value;
    s32 stack_value;
    u16 flags;
    u8 amount;
    u8 *object;
    func_00481440(D_005DC7D0);
    node = *(u8 **)(iGpffffb3ac + 0x1B8);
    while (node != NULL) {
        value = *(s32 *)(node + 4);
        flags = *(u16 *)(node + 0);
        if ((flags & 0x40) == 0) {
            if ((flags & 0x100) != 0) {
                amount = *(u8 *)(node + 8);
                if ((u32)amount << 24 < ((u32)value & 0xFF000000)) {
                    value -= (u32)amount << 24;
                } else {
                    value = (s32)(((s64)value << 0x28) >> 0x28);
                    *(u16 *)(node + 0) = flags & 0xFE7F;
                }
            } else if ((flags & 0x80) != 0) {
                amount = *(u8 *)(node + 8);
                if ((u32)amount << 24 < 0xFF000000 - ((u32)value & 0xFF000000)) {
                    value += (u32)amount << 24;
                } else {
                    value = (s32)(((s64)value << 0x28) >> 0x28) | 0xFF000000;
                    *(u16 *)(node + 0) = flags & 0xFE7F;
                }
            }
            if ((*(u16 *)(node + 0) & 0x220) == 0x220) {
                if (*(s32 *)(node + 0x18) != 0)
                    func_00478e70(*(s32 *)(node + 0x18));
                if (*(s32 *)(node + 0x14) != 0)
                    func_00485630(*(s32 *)(node + 0x14));
                object = *(u8 **)(node + 0x10);
                if (object != NULL)
                    func_001d53e0(object);
            }
        }
        if ((*(u16 *)(node + 0) & 0x210) == 0x210 &&
            (*(s32 *)(node + 4) & 0xFF000000) != 0) {
            if (*(s32 *)(node + 0x18) != 0) {
                stack_value = value;
                func_0047a220(*(s32 *)(node + 0x18), &stack_value);
                func_00479100(D_00794150, *(s32 *)(node + 0x18));
            }
            if (*(s32 *)(node + 0x14) != 0) {
                func_004865c0(*(s32 *)(node + 0x14), value);
                func_00485870(*(s32 *)(node + 0x14));
            }
            object = *(u8 **)(node + 0x10);
            if (object != NULL) {
                *(s32 *)(object + 0x10) = value;
                func_001d5b20(object);
            }
        }
        *(s32 *)(node + 4) = value;
        *(s32 *)(node + 0xC) = *(s32 *)(node + 0xC) + 1;
        node = *(u8 **)(node + 0x20);
    }
}
