#pragma opt_loop_invariants on
void func_003147e0(u8 *arg0, s8 arg1, FclVec2 arg2, s16 arg3, s16 arg4, s8 arg5) {
    FclByte4 c15C;
    FclByte4 c158;
    FclByte4 c154;
    FclByte4 c150;
    FclByte4 c14C;
    FclByte4 c148;
    FclByte4 c144;
    FclPackedPosition sp138;
    FclPackedPosition sp130;
    FclPackedPosition sp128;
    FclPackedPosition sp120;
    FclPackedPosition sp118;
    FclPackedPosition sp110;
    FclPackedPosition sp108;
    FclPackedPosition sp100;
    FclBoundsPacket spF0;
    u8 *t;
    u8 *h;
    u8 **slot;
    s16 base;
    s32 order;
    s16 res;
    s16 kind;
    s16 i;
    s32 r;
    s32 two;
    s32 o2;
    f32 x;
    f32 y;

    t = *(u8 **)(arg0 + 0x38);
    kind = arg3;
    base = arg1 * 5 + 0x66;
    if (kind == 0x16C) {
        func_002b2970((u8 *)&sp128, 67.0f, 175.0f);
        func_00314ef0(arg0, arg1, sp128.position, 0x16C, arg4, arg5);
        return;
    }
    two = arg1 * 2;
    res = two + 0x1F4;
    func_002b7750(res, 0x1AC);
    order = base;
    o2 = order + 2;
    func_002b2970((u8 *)&sp120, arg2.x, arg2.y);
    c15C = func_002b2a60(0, 0, 0x66, 0xFF);
    func_002b77d0(res, sp120.position, 0x1AC, c15C, 154.0f, o2, arg5, 3, 3, arg4, func_00331560());
    res = two + 0x1F5;
    func_002b7750(res, 0x1AF);
    func_002b2970((u8 *)&sp130, 258.0f + arg2.x, arg2.y);
    c158 = func_002b2a60(0, 0, 0x66, 0xFF);
    func_002b77d0(res, sp130.position, 0x1AF, c158, 154.0f, o2, arg5, 3, 3, arg4, func_00331560());
    func_002b2970((u8 *)&sp138, sp130.position.x - 28.0f, sp130.position.y);
    res = arg1 + 0x2FB;
    func_002b7750(res, 0x131);
    func_002b2970((u8 *)&sp130, 266.0f + arg2.x, arg2.y);
    c154 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(res, sp138.position, 0x131, c154, 153.0f, order + 3, arg5, 3, 3, arg4, func_00331560());
    func_002b68d0(res, 0xE, 0);
    h = func_0046d200(func_00331560(), 0x131);
    slot = (u8 **)(t + 0x258) + arg1;
    *(FclVec2 *)func_002b81f0(*slot) = sp138.position;
    x = func_0046b260(h);
    func_002b29e0((u8 *)&spF0, x, func_0046b2f0(h));
    ((FclBoundsPacket *)(func_002b81f0(*slot) + 8))->representation = spF0.representation;
    *(s32 *)(func_002b81f0(*slot) + 0x120) = order;
    *(f32 *)(func_002b81f0(*slot) + 0x18) = 152.0f;
    *(u8 *)(func_002b81f0(*slot) + 0x124) = 0;
    func_0046d280(h);
    if (kind == -1) {
        return;
    }
    if (kind == 0x174) {
        extern FclVec2 func_002b2970(f32, f32);

        for (i = 0, o2 = order + 4; i < 2; i++) {
            r = i + 0x174;
            res = r;
            func_002b77d0(res, sp118.position = func_002b2970(6.0f + arg2.x + (f32)(i * 0x67), 4.0f + arg2.y), r,
                          c150 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, o2, arg5, 3, 3, arg4, func_00331560());
        }
        return;
    }
    if (datGetFlag(0x1305) != 0 && kind == 0x160) {
        extern FclVec2 func_002b2970(f32, f32);

        func_002b77d0(0x160, sp110.position = func_002b2970(6.0f + arg2.x, 4.0f + arg2.y), 0x160,
                      c14C = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, base + 4, arg5, 3, 3, arg4, func_00331560());
        func_002b7750(0x2EB, 0x16F);
        func_002b77d0(0x2EB, sp108.position = func_002b2970(100.0f + (6.0f + arg2.x), 4.0f + arg2.y), 0x16F,
                      c148 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, base + 4, arg5, 3, 3, arg4, func_00331560());
        return;
    }
    func_002b2970((u8 *)&sp100, 6.0f + arg2.x, 4.0f + arg2.y);
    c144 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0(arg3, sp100.position, arg3, c144, 152.0f, order + 4, arg5, 3, 3, arg4, func_00331560());
}
#pragma opt_loop_invariants reset
