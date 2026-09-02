// FUN_002B7CD0 archive (wave Jo lane JoB, killed by provider rate limit mid-work; body is the live state at cutoff, MISMATCH nd352 552/592).
#pragma push
/* measured: opt_loop_invariants off preserves the retail bit-loop's per-iteration s16 sign-extend and the constant-1 CSE. */
#pragma opt_loop_invariants off
/* measured: opt_propagation off keeps the global table loads per compare and anchors the local loads. */
#pragma opt_propagation off
/* measured: schedule off preserves the loop and float-compare issue order. */
#pragma schedule off
void func_002b7cd0(u8 *arg0, s16 arg1, s16 arg2) {
    u8 *t0;
    s32 idx;
    u8 *q;
    s32 off;
    s32 flags;
    s16 i;
    s16 found;
    u8 *base;
    f32 v[4];
    s16 j;

    t0 = *(u8 **)(arg0 + 0x38);
    flags = *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + ((s32)arg1 * 0x100) + 0x14);

    found = 0;
    for (i = 1; i < 13; i++) {
        if (((flags & (u16)(1 << i)) >> i) == 1) {
            found = 1;
            goto found_check;
        }
    }
    found = 0;

found_check:
    if (found) {
        return;
    }

    off = (s32)arg1 * 0x100;
    idx = arg2;
    q = func_0046d200(*(u32 *)t0, idx);
    (void)func_0046b260(q);
    (void)func_0046b2f0(q);
    base = (u8 *)(*(u32 *)(*(u32 *)q + 0x204)) + (idx * 0x80);

    for (j = 0; j < 4; j++) {
        v[j] = (f32)*(s32 *)(base + j * 4 + 0x34);
    }

    if ((*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3c) - v[2] >= 640.0f) ||
        (v[3] + (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3c) + func_0046b260(q)) < 0.0f) ||
        (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x40) - v[0] >= 480.0f) ||
        (v[1] + (*(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x40) + func_0046b2f0(q)) < 0.0f)) {
        *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14) &= ~1;
    }
    func_0046d280(q);
}
