// LANE: W42c1a
// addr: 001ae800
// object: 1052 (vs retail 1056)
// window: 1056
// normalized_diff: measured as MISMATCH in lverify
// differing words (fndiff): 3 (two real loop-test scheduler residual, one tail nop)
// levers tried:
//   - matched similar function func_001a3f90 as template
//   - u16 loop counter vs u32 + explicit & 0xFFFFU
//   - swapped condition operand order
//   - #pragma schedule on/off (huge regression, reverted)
//   - no_branch_likely, opt_propagation not attempted due to broad impact
// status: best measured candidate; not a byte-exact match
void func_001ae800(u8 *arg0)
{
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u8 frame[0x10];

    if (*(s32 *)(arg0 + 0x424) == 0) {
        if (func_00193cd0(0xC00) != 0) {
            return;
        }
        if (func_00193cd0(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while (i < *(u16 *)(gp2 + 0xC58)) {
            packet1 = *(u8 **)(gp2 + 0xC48 + ((u32)i * 4));
            *(u16 *)(frame + 2 + ((u32)i * 2)) =
                *(u16 *)(*(u8 **)(packet1 + 0x30) + 0xA4);
            i++;
        }
        *(u16 *)(frame + 8) = *(u16 *)(gp2 + 0xC58);
        packet1 = func_001fa110((s16 *)frame);
        func_00194590(packet1, 1);
        packet2 = func_001fa8f0();
        *(s16 *)(packet2 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet2, 1);
        packet3 = func_00194c90((s32)func_001ae3c0, (s32)arg0);
        *(s16 *)(packet3 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet3, 1);
        packet4 = func_001d65d0(
            *(s32 *)(D_0076449C + 0xD8C),
            *(s32 *)(arg0 + 0x30), 0,
            *(s64 *)(packet3 + 0x58), 0x8000);
        *(s16 *)(packet4 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet4, 2);
        *(s32 *)(arg0 + 0x424) = 1;
    }

    if (*(s32 *)(arg0 + 0x420) == 0) {
        if (*(s16 *)(arg0 + 0x42C) <= 0) {
            func_00218160(*(s32 *)(D_0076449C + 0xDD4),
                          *(s32 *)(arg0 + 0x41C));
            *(s32 *)(arg0 + 0x420) = 1;
        } else {
            *(s16 *)(arg0 + 0x42C) = *(s16 *)(arg0 + 0x42C) - 1;
        }
    }

    if (func_00193bf0(*(u64 *)arg0,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (*(s32 *)(arg0 + 0x428) == 0) {
        if (func_00218200(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            return;
        }
        if (func_00218230(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            packet1 = func_001f3870((s64 *)arg0, 2);
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
            *(s32 *)(*(u8 **)(D_0076449C + 0x170) + 0x434) =
                *(s32 *)(arg0 + 0x41C);
            *(s16 *)(*(u8 **)(D_0076449C + 0x170) + 0x16) = 0x1F;
            func_001b0e30(*(s32 *)(D_0076449C + 0x170));
            packet2 = (u8 *)func_001b1540();
            if ((*(u8 *)(*(u8 **)(packet2 + 0x30) + 0xA2) == 0) &&
                (*(u8 *)(packet2 + 0x28) != 0)) {
                *(u16 *)(packet2 + 0x18) |= 0x8000;
            }
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 1, 0, 0), 1);
        } else {
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 0, 0, 0), 1);
            packet1 = func_001fa450();
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
        }

        packet1 = func_001faa60();
        *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
        func_00194590(packet1, 1);
        packet2 = func_0019e7c0(0, 1);
        *(u64 *)(packet2 + 0x60) = *(u64 *)arg0;
        func_00194590(packet2, 1);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) |= 0x2000;
            func_00212240(*(s32 *)(D_0076449C + 0xDD4), 1);
        }
        *(s32 *)(arg0 + 0x428) = 1;
        *(u16 *)(arg0 + 0x42E) = 6;
        return;
    }

    if (*(u16 *)(arg0 + 0x42E) == 0) {
        func_00218260(*(s32 *)(D_0076449C + 0xDD4));
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        func_001b0800(arg0, 0x20);
        return;
    }
    *(u16 *)(arg0 + 0x42E) = *(u16 *)(arg0 + 0x42E) - 1;
}
