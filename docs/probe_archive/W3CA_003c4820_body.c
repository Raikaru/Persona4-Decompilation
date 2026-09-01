/* func_003c4820: object 400B/window 384B/normalized_diff 239; oversized by 16B; first differing offsets 16,18-19,24-28,30-38; exact two-parameter signature and helper prototypes tried; stack aggregate still over frame; ASM restored. */
u8 *func_003c4820(u8 *arg0, s32 arg1) {
    extern s32 func_003deff0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e2ab0(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e6240(s32 arg0);
    extern s32 func_003e62b0(s32 arg0, s32 arg1);
    extern u8 *func_003e33f0(u8 *arg0, s32 arg1, s32 arg2);
    struct {
        s32 result;
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
        u8 pad[4];
        s32 flag;
        f32 f0;
        f32 f1;
        f32 f2;
    } stack;
    s32 count;
    u8 *self;
    s32 value;

    count = 0x28;
    self = arg0;
    value = arg1;
    if (*(s32 *)self != 0)
        count += func_003e6240(*(s32 *)self) + 0xC;
    if (func_003deff0((void *)value, 7, count + (func_003e3370(D_0070AFF0, self) + 0xC),
                      0x37002, 0x37) == 0)
        goto fail;
    if (func_003deff0((void *)value, 1, 0x1C, 0x37002, 0x37) == 0)
        goto fail;
    stack.result = 0;
    if (*(s32 *)self != 0)
        stack.flag = 1;
    else
        stack.flag = 0;
    stack.f0 = *(f32 *)(self + 0xC);
    stack.b0 = *(u8 *)(self + 4);
    stack.f1 = *(f32 *)(self + 0x10);
    stack.b1 = *(u8 *)(self + 5);
    stack.f2 = *(f32 *)(self + 0x14);
    stack.b2 = *(u8 *)(self + 6);
    stack.b3 = *(u8 *)(self + 7);
    if (func_003e2ab0(value, &stack, 0x1C, stack.b1, stack.b0) == 0)
        goto fail;
    if (*(s32 *)self != 0 && func_003e62b0(*(s32 *)self, value) == 0)
        goto fail;
    if (func_003e33f0(D_0070AFF0, value, (s32)self) != 0)
        return self;
fail:
    return NULL;
}
