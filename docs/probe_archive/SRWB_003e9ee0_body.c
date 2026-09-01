object 524B / window 592B / normalized_diff not measured (compile-only object); differing offsets not measured; instruction deficit 17 instructions; classification UNDERSIZED / repeated call-result loads and callback argument materialization still differ; ruled out: generated M2C body wholesale (manual transcription), pointer-persistent state local (removed; exact retail frame), pointer allocator declaration order probe, old-style callee declarations, reversed allocator argument order fixed; retail prologue frame 0x30 saves s0-s1 (2), first-touches a0,a1 (2 args); declarations corrected at function scope for func_003e1220/func_003e12f0/func_003ebff0 old-style and GP globals iGpffffab9c/iGpffffaba0/iGpffffaba4/iGpffffb7cc plus D_0088B340/D_0088B310.

s32 func_003e9ee0(s32 arg0, s32 arg1)
{
    extern s32 func_003e1220();
    extern void func_003e12f0();
    extern void func_003ebff0();
    extern s32 iGpffffab9c;
    extern s32 iGpffffaba0;
    extern s32 iGpffffaba4;
    extern s32 iGpffffb7cc;
    extern u8 D_0088B340[];
    extern u8 D_0088B310[];
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void (*jtbl_008873EC[])(void *ptr);
    u8 *work;
    void *(*allocator)(u32 size, u32 align);

    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) = func_003e1220(*(s32 *)D_0070B7C0, iGpffffab9c, 4, iGpffffaba0, D_0088B340, 0x40018);
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) != 0) goto allocate_second;
    return 0;
allocate_second:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) = func_003e1220(0x34, iGpffffab9c, 4, iGpffffaba4, D_0088B310, 0x40406);
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) == 0) goto second_alloc_fail;
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8) = 0x100;
    allocator = jtbl_008873E8[0];
    work = (u8 *)allocator(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8), 0x1040406);
    *(u8 **)((u8 *)D_008872E0 + iGpffffb7c8 + 4) = work;
    if (work == NULL) goto first_callback_fail;
    *work = 0;
    iGpffffb7cc += 1;
    func_003ebff0(1.0f);
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x21c) = 0;
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x214) = 0x100;
    work = (u8 *)allocator(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x214), 0x1040018);
    *(u8 **)((u8 *)D_008872E0 + iGpffffb7c8 + 0x210) = work;
    if (work != NULL) return arg0;
    goto second_callback_fail;
second_alloc_fail:
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) = 0;
    return 0;
first_callback_fail:
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) = 0;
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) = 0;
    return 0;
second_callback_fail:
    jtbl_008873EC[0](*(void **)((u8 *)D_008872E0 + iGpffffb7c8 + 4));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 4) = 0;
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8) = 0;
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) = 0;
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) = 0;
    return 0;
}
