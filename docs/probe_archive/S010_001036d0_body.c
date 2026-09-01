/* FUNC 001036D0 near-match archive: object 684B/window 688B, normalized_diff 106, first differing offsets 0x20,0x30,0x44,0xEC,0xF8; classification register/literal materialization and loop control-shape residual; prologue one saved s-register ($s0) and one incoming pointer argument (u8 *arg0); ruled out undersize/oversize (object 684 vs 688), missing call, and five compiler floors. */
// FUN_001036D0
s32 func_001036d0(u8 *arg0) {
    extern void func_00450340(s64 arg0, s32 arg1, ...);
    extern u8 *func_00457120(void);
    extern u8 *func_004609f0(void);
    extern void func_00460ac0(void *list, void *node);
    extern u8 D_005DD5D0[];
    extern u8 D_00793E80[];
    extern s64 iGpffff85c8;
    s32 index;
    u8 *state;
    u8 *slot;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
    {
        f32 scale;
        f32 inverse;
        register s32 forty;
        register s32 one;

        scale = *(f32 *)(func_00457120() + 0x80);
        inverse = 1.0f / scale;
        forty = 0x42800000;
        *(s32 *)(state + 0x10) = forty;
        *(s32 *)(state + 0x14) = forty;
        *(f32 *)(state + 0x18) = scale;
        *(s32 *)(state + 0x50) = 0x43000000;
        *(s32 *)(state + 0x54) = forty;
        *(f32 *)(state + 0x58) = scale;
        *(s32 *)(state + 0x90) = forty;
        *(s32 *)(state + 0x94) = 0x43400000;
        *(f32 *)(state + 0x98) = scale;
        *(s32 *)(state + 0xD0) = 0x43000000;
        *(s32 *)(state + 0xD4) = 0x43400000;
        *(f32 *)(state + 0xD8) = scale;
        *(f32 *)(state + 0x28) = inverse;
        *(f32 *)(state + 0x68) = inverse;
        *(f32 *)(state + 0xA8) = inverse;
        *(f32 *)(state + 0xE8) = inverse;
        *(s32 *)(state + 0x110) = 0x43010000;
        *(s32 *)(state + 0x114) = 0x43010000;
        *(f32 *)(state + 0x118) = scale;
        *(f32 *)(state + 0x150) = (f32)385;
        *(s32 *)(state + 0x154) = 0x43010000;
        *(f32 *)(state + 0x158) = scale;
        *(s32 *)(state + 0x190) = 0x43010000;
        *(f32 *)(state + 0x194) = (f32)385;
        *(f32 *)(state + 0x198) = scale;
        *(f32 *)(state + 0x1D0) = (f32)385;
        *(f32 *)(state + 0x1D4) = (f32)385;
        *(f32 *)(state + 0x1D8) = scale;
        *(s32 *)(state + 0x120) = 0;
        *(s32 *)(state + 0x124) = 0;
        one = 0x3F800000;
        *(s32 *)(state + 0x160) = one;
        *(s32 *)(state + 0x164) = 0;
        *(s32 *)(state + 0x1A0) = 0;
        *(s32 *)(state + 0x1A4) = one;
        *(s32 *)(state + 0x1E0) = one;
        *(s32 *)(state + 0x1E4) = one;
        *(f32 *)(state + 0x128) = inverse;
        *(f32 *)(state + 0x168) = inverse;
        *(f32 *)(state + 0x1A8) = inverse;
        *(f32 *)(state + 0x1E8) = inverse;

        {
            register s32 max = 0x437F0000;
            s32 i;
            i = 0;
            goto loop1_check;
loop1_body:
            *(s32 *)(state + (i << 6) + 0x30) = max;
            *(s32 *)(state + (i << 6) + 0x34) = 0;
            *(s32 *)(state + (i << 6) + 0x38) = forty;
            *(s32 *)(state + (i << 6) + 0x3C) = max;
            i++;
loop1_check:
            if (i < 4) goto loop1_body;
        }
        {
            register s32 max = 0x437F0000;
            s32 i;
            i = 0;
            goto loop2_check;
loop2_body:
            *(s32 *)(state + (i << 6) + 0x130) = max;
            *(s32 *)(state + (i << 6) + 0x134) = max;
            *(s32 *)(state + (i << 6) + 0x138) = max;
            *(s32 *)(state + (i << 6) + 0x13C) = max;
            i++;
loop2_check:
            if (i < 4) goto loop2_body;
        }
        index = 0;
        while (index < 2) {
            slot = state + (index << 2) + 4;
            *(u8 **)slot = func_004609f0();
            *(s16 *)(*(u8 **)slot + 0x18) = 11;
            *(s32 *)(*(u8 **)slot + 0x1C) = 4;
            *(u8 **)(*(u8 **)slot + 0x20) = state + (index << 8) + 0x10;
            *(s32 *)(*(u8 **)slot + 0x24) = 4;
            index++;
        }
        *(void **)(*(u8 **)(state + 4) + 8) = (void *)func_001035a0;
        *(s32 *)(*(u8 **)(state + 4) + 0x10) = 0;
        *(void **)(*(u8 **)(state + 8) + 8) = (void *)func_00103600;
        *(s32 *)(*(u8 **)(state + 8) + 0x10) = 0;
        *(s32 *)state = *(s32 *)state + 1;
        break;
    }
    case 1:
        func_00450340(iGpffff85c8, (s32)D_005DD5D0);
        *(s32 *)(*(u8 **)(state + 4) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 4) + 4) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 4) = 0;
        func_00460ac0(D_00793E80, *(u8 **)(state + 4));
        func_00460ac0(D_00793E80, *(u8 **)(state + 8));
        break;
    }
    return 0;
}
