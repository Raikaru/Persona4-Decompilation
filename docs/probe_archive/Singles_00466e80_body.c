/* Closest candidate: object 820B/window 1040B, normalized_diff 0 over the
   implemented body. The remaining 220B are the unmarked D_004671C0 callback
   folded into the canonical retail window, so this candidate was reverted. */
void func_00466e80(u8 *arg0)
{
    u8 *work;
    u8 *next;
    s32 lock;
    s16 status;

wait_start:
    for (;;) {
        func_00421700();
        status = *(s16 *)(arg0 + 0);
        switch (status) {
        case 0:
            goto wait;
        case 1:
            goto process;
        default:
            goto wait;
        }
    wait:
        ;
    }
process:
    for (;;) {
        work = *(u8 **)(arg0 + 4);
        switch (*(s32 *)(work + 0x1AC)) {
        case 0:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B4) =
                func_003ef740(*(u8 **)(arg0 + 4) + 0x24, 0);
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 1:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            *(u8 **)(*(u8 **)(arg0 + 4) + 0x10) =
                func_003be180(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 2:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            if (*(s32 *)(*(u8 **)(arg0 + 4) + 0x1CC) != 0) {
                func_003d60e0(D_0070B610, *(s32 *)(*(u8 **)(arg0 + 4) + 0x1CC));
            }
            *(s32 *)(*(u8 **)(arg0 + 4) + 0xC) =
                (s32)func_003c0f20(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 3:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x14) =
                func_003d5330(work + 0x24);
            break;
        case 4:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1BC) =
                func_003e2910(*(s32 *)(work + 8),
                              *(s32 *)(work + 0x1C4),
                              *(s32 *)(work + 0x1C0));
        case 5:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x18) =
                (s32)func_00395290(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            break;
        case 6:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C) =
                func_003bba90(work + 0x24);
            break;
        case 7:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C8) =
                func_003d6350(*(s32 *)(work + 0x20), *(s32 *)(work + 8));
            break;
        case 8:
            *(u8 **)(*(u8 **)(arg0 + 4) + 0x1D0) =
                func_003e6a90(*(s32 *)(work + 8));
            break;
        case 9:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B8) =
                func_00464100(*(s32 *)(work + 0x1C4), 0);
            break;
        case 10:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C4) =
                func_003eaf60(work + 0x24);
            break;
        case 11:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C) =
                func_003bb210(*(s32 *)(work + 8));
            break;
        }
        if (*(s32 *)(*(u8 **)(arg0 + 4) + 0x1B0) != 0) {
            lock = func_0042ba20();
            func_00454bd0(*(u8 **)(*(u8 **)(arg0 + 4) + 0x1B0));
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B0) = 0;
            if (lock != 0) {
                func_0042ba70();
            }
        }
        lock = func_0042ba20();
        *(s32 *)(*(u8 **)(arg0 + 4) + 0x1A4) = 3;
        work = *(u8 **)(arg0 + 4);
        if (*(s32 *)(work + 0x1AC) != 8 &&
            *(s32 *)(work + 0x1AC) != 2) {
            next = *(u8 **)(work + 0);
            if (next != NULL &&
                *(s32 *)(next + 0x1A4) == 0 &&
                *(s8 *)(next + 0xA4) == 0) {
                *(s32 *)(next + 0x1A4) = 2;
                *(u8 **)(arg0 + 4) = next;
                if (lock != 0) {
                    func_0042ba70();
                }
                continue;
            }
        }
        *(s16 *)(arg0 + 0) = 0;
        if (lock == 0) {
            goto wait_start;
        }
        func_0042ba70();
        goto wait_start;
    }
}
