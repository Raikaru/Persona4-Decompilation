/* measured: object 284B/window 288B/normalized_diff 39; differing offsets 4,48,60,68,72,92,112,116,120,124,132,136,140,144,156,180,184,188,192,196,200,204,208,212,216,220,224,232,236,240,248,252,256,260,264,268,272,276,280,284; instruction deficit 1 (4B); classification declaration/register allocation, aggregate copy scheduling, default-delay layout; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, ee-gcc sd/sq floor, absolute D_0070B6F0 addressing, old-style helper declarations, pointer counter reuse, Pair aggregate and scalar temporary probes. */
u8 *func_003e0e20(s32 arg0, u8 *arg1, s32 arg2) {
    extern u8 D_0070B6F0[];
    extern s32 func_003df590();
    extern void func_003df4d0();
    s32 spA8;
    s32 spAC;
    s32 sp60[16];
    s32 sp20[16];
    u8 *ret;

    ret = (u8 *)(u32)arg0;
    switch (arg2) {
    case 0:
        arg0 = 8;
        arg2 = (s32)ret;
        do {
            ((s32 *)(u32)arg2)[0] = ((s32 *)arg1)[0];
            ((s32 *)(u32)arg2)[1] = ((s32 *)arg1)[1];
            arg1 += 8;
            arg0 -= 1;
            arg2 += 8;
        } while (arg0 > 0);
        break;
    case 1:
        func_003e05f0((u8 *)sp60, arg1, ret);
        arg2 = (s32)sp60;
        arg1 = ret;
        arg0 = 8;
        do {
            ((s32 *)arg1)[0] = ((s32 *)(u32)arg2)[0];
            ((s32 *)arg1)[1] = ((s32 *)(u32)arg2)[1];
            arg2 += 8;
            arg0 -= 1;
            arg1 += 8;
        } while (arg0 > 0);
        break;
    case 2:
        func_003e05f0((u8 *)sp20, ret, arg1);
        arg2 = (s32)sp20;
        arg1 = ret;
        arg0 = 8;
        do {
            ((s32 *)arg1)[0] = ((s32 *)(u32)arg2)[0];
            ((s32 *)arg1)[1] = ((s32 *)(u32)arg2)[1];
            arg2 += 8;
            arg0 -= 1;
            arg1 += 8;
        } while (arg0 > 0);
        break;
    default:
        spA8 = 2;
        spAC = func_003df590(0x80000003, (s32 *)D_0070B6F0);
        func_003df4d0(&spA8);
        ret = NULL;
        break;
    }
    return ret;
}
