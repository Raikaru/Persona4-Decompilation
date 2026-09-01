/* BEST probe: object 324 bytes, retail window 336 bytes; verify normalized_diff 24 bytes (fndiff differing words 11). First differing byte offsets: 196, 198, 199, 200, 203, 206, 207, 210, 211, 212, 213, 214, 215, 220, 222, 223. The float-to-unsigned site is exact with `f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f; buf[3] = (u8)f;`: retail low path cvt.w.s/mfc1/andi 0xFF and high path bias sub.s/cvt.w.s/mfc1/lui 0x8000/or/andi 0xFF. Best address shape uses `arr16 = (u_long128 *)&arr[16]` before the arr[0] store, then stores arr[0] and *arr16; this improves the previous direct-store body from fndiff 12 words / normalized_diff 24 to fndiff 11 words / normalized_diff 24. Remaining residual is address-materialisation scheduling: retail hoists addiu $a0,$sp,0x5C before the fbuf load/store and addiu $a1,$sp,0x40 between the lq/sq copies, while MWCC sinks them. Tried and ruled out on this shape: fbuf address locals and void/f32 pointer aliases, pre-store pointer assignment, store-through-pointer fbuf, post-store pointer read/copy, direct address expressions, reordered arr16 assignment after arr[0], named integer stack-base/address casts, overlapping pointer lifetimes, live post-store reads, static-inline helpers, and optimization_level 1. No callee declaration change was needed; `func_00452560` remains block-scope old-style and `func_0045d6e0` retains its verified `(void *, void *, s32, f32)` prototype. */
void func_0025b0f0(s32 arg0, u8 *arg1) {
    extern u32 *func_00452560();
    u8 *sp;
    u8 *p;
    s32 i;
    f32 fbuf;
    u8 buf[4];
    u8 arr[32];
    u_long128 quad;
    u_long128 *arr16;
    f32 f;

    sp = (u8 *)func_00452560(arg1);
    p = buf;
    i = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
        } while (--i != 0);
    }
    f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f;
    buf[3] = (u8)f;
    fbuf = *(f32 *)buf;
    quad = D_00636730;
    arr16 = (u_long128 *)&arr[16];
    *(u_long128 *)&arr[0] = quad;
    *arr16 = quad;
    func_0045d6e0(&fbuf, arr16, 1, 0.0f);
    switch (*(u32 *)(sp + 4)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 9:
    case 10:
        func_00257900(arg1);
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }
}
