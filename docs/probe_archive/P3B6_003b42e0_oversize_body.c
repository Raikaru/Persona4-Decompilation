/* object 448B/window 400B, normalized_diff 360; differing byte offsets begin 0,4,6-24 and continue through 444; classification object oversized, archive immediately. Corrected GP declaration iGpffffb610 (retail -0x49F0 scalar) and reconstructed dynamic callback fields at object offsets 0x24..0x38 plus context zeroing. Candidate frame 0xE0 versus retail 0xB0 because typed callback/context locals inflated stack layout; callback register/order residual remains. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
s32 func_003b42e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 iGpffffb610;
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    typedef void (*Callback5)(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    typedef void (*Callback3)(s32 *arg0, s32 arg1, s32 arg2);
    u8 context[0x48];
    u8 *object;
    s32 selected;
    s32 *slot0;
    s32 *slot1;
    s32 *slot2;
    s32 *slot3;
    Callback5 callback0;
    Callback5 callback4;
    Callback3 callback1;
    Callback3 callback2;
    Callback3 callback3;

    object = *(u8 **)((u8 *)(u32)arg0 + iGpffffb610);
    if ((arg3 & 0x1E8000) != 0) {
        selected = *(s32 *)object;
    } else {
        selected = arg2;
    }
    callback0 = *(Callback5 *)(object + 0x24);
    if (callback0 != NULL) {
        func_0043f9c8(context, 0, 0x48);
        callback0(context, arg0, arg1, selected, arg3);
    }
    slot0 = (s32 *)(context + 0x10);
    slot1 = (s32 *)(context + 0x18);
    slot2 = (s32 *)(context + 0x20);
    slot3 = (s32 *)(context + 0x28);
    callback4 = *(Callback5 *)(object + 0x28);
    if (callback4 != NULL && *slot0 != 0) {
        callback4(slot0, (s32)(u32)(context + 0x30), (s32)(u32)(context + 0x3C), selected, arg1);
    }
    callback1 = *(Callback3 *)(object + 0x2C);
    if (callback1 != NULL && *slot1 != 0) {
        callback1(slot1, selected, arg1);
    }
    callback2 = *(Callback3 *)(object + 0x30);
    if (callback2 != NULL && *slot2 != 0) {
        callback2(slot2, selected, arg1);
    }
    callback3 = *(Callback3 *)(object + 0x34);
    if (callback3 != NULL && *slot3 != 0) {
        callback3(slot3, selected, arg1);
    }
    callback4 = *(Callback5 *)(object + 0x38);
    if (callback4 != NULL) {
        callback4(context, arg0, arg1, selected, arg3);
    }
    return 1;
}
