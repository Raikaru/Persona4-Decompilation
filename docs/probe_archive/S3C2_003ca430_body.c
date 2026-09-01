/* func_003ca430: object 412B/window 368B/normalized_diff 242; oversized by 44B; first differing offsets 4,6-8,10-22; saved-register/prologue mismatch; candidate archived and ASM restored. */
s32 func_003ca430(void) {
    extern s32 func_003e8930(s32 arg0, s32 arg1, void *arg2, void *arg3);
    extern s32 func_003cb900(void);
    extern s32 func_003bfdf0(void);
    extern s32 func_003d4c70(void);
    extern void func_003c4040(void);
    extern void func_003c40d0(void);
    extern void func_003c5510(void);
    extern void func_003c54a0(void);
    extern void func_003c1d00(void);
    extern void func_003c1d20(void);
    extern void func_003bfd00(void);
    extern void func_003bfc40(void);
    extern void func_003c3e90(void);
    extern void func_003c3e10(void);
    extern void func_003c8ca0(void);
    extern void func_003c8cc0(void);
    extern void func_003c95a0(void);
    extern void func_003c9530(void);
    extern void func_003be7e0(void);
    extern void func_003be7c0(void);
    s32 result;

    result = 0;
    result |= func_003e8930(4, 0x501, (void *)func_003c4040, (void *)func_003c40d0);
    result |= func_003e8930(0x30, 0x502, (void *)func_003c5510,
                            (void *)((u8 *)func_003c54a0 + 0x20));
    result |= func_003e8930(4, 0x503, (void *)func_003c1d00, (void *)func_003c1d20);
    result |= func_003e8930(8, 0x504, (void *)func_003bfd00, (void *)func_003bfc40);
    result |= func_003e8930(4, 0x505, (void *)func_003c3e90, (void *)func_003c3e10);
    result |= func_003e8930(0, 0x50A, (void *)func_003c8ca0, (void *)func_003c8cc0);
    result |= func_003e8930(0xC, 0x507, (void *)func_003c95a0, (void *)func_003c9530);
    result |= func_003e8930(0, 0x50B, (void *)func_003be7e0, (void *)func_003be7c0);
    if (result < 0)
        return 0;
    if (func_003cb900() == 0)
        return 0;
    if (func_003bfdf0() == 0)
        return 0;
    return func_003d4c70() != 0;
}
