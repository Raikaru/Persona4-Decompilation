/* object 172 bytes, retail window 176 bytes, normalized_diff 6.
   Best source shape preserves MWCC's saved-register setup, 0x40507 allocator
   constant, call/store order, and repeated GP-relative list-head reloads.
   Remaining residual is three words: the true-body order swap at offsets
   0x30/0x34 (candidate emits the base addu before the D_008873F8+0x118
   load) plus the address-relocation word at 0x14. In addition to the prior
   direct-call, named-allocator-argument, allocator-local-before/after-base,
   direct-global-expression, schedule, declaration-order, pointer-width,
   local-address-form, and optimization-level-1 probes, measured probes of
   a first-statement named global value (pointer, scalar, function-pointer,
   aggregate, and escaping-local forms), integer-domain base sums, and an
   array-typed absolute D_008873F8 alias did not improve the residual. */
void func_003c9940(s32 arg0, s32 arg1) {
    extern s32 iGpffffb6f8;
    u8 *base;
    u8 *temp_2;
    u8 *temp_4;
    u8 *(*allocator)(u8 *, u32);

    allocator = (u8 *(*)(u8 *, u32))D_008873F8[0x46];
    base = D_008872E0 + iGpffffb6f8;
    temp_2 = allocator(*(u8 **)base, 0x40507U);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 0) = arg0;
        *(s32 *)(temp_2 + 4) = arg1;
        *(s32 *)(temp_2 + 8) =
            *(s32 *)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4));
        *(u8 **)(temp_2 + 0xC) =
            (u8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4);
        temp_4 = temp_2 + 8;
        *(u8 **)(*(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4) + 0) + 4) =
            temp_4;
        *(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4)) = temp_4;
    }
}
