/* object_size=384 window=368 normalized_diff=274 differing_offsets=0x40 onward (first_diffs=0x10,0x11,0x12,0x13,0x14,0x16,0x18,0x1A,0x1C-0x23); classification=automatic archive: object larger than retail window, likely saved-register/vtable-reuse and statement-order residual; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register floor; block-scope declarations corrected: func_003a93b0(u8*,u8*,u32,u8*), func_003a9880(u8*,u8*,u32,u8*), func_003a14f0(u8*,u8*) returning s32, func_003e9700(s32) returning u8*, D_00887300/D_00887304 typed callback arrays; iGpffffb610 existing file declaration; no further probes per oversized-object rule. */
s32 func_003a9f40(s32 arg0, u8 *arg1, u32 arg2)
{
    extern u8 *func_003e9700(s32 arg0);
    extern s32 func_003a14f0(u8 *arg0, u8 *arg1);
    extern void func_003a93b0(u8 *arg0, u8 *arg1, u32 arg2, u8 *arg3);
    extern void func_003a9880(u8 *arg0, u8 *arg1, u32 arg2, u8 *arg3);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void (*D_00887304[])(s32 arg0, void *arg1);
    s32 sp6C;
    s32 sp68;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_19;

    temp_19 = (u8 *)((u32)arg0 + (u32)iGpffffb610);
    temp_18 = *(u8 **)(*(u8 **)temp_19 + 0x9C);
    if (*(s32 *)(arg1 + 0x64) != 0) {
        temp_17 = (u8 *)D_00887300;
        (*(void (**)(s32, s32))temp_17)(12, 1);
        temp_16 = (u8 *)D_00887304;
        (*(void (**)(s32, void *))temp_16)(10, &sp6C);
        (*(void (**)(s32, s32))temp_17)(10, *(s32 *)(arg1 + 0x5C));
        (*(void (**)(s32, void *))temp_16)(11, &sp68);
        (*(void (**)(s32, s32))temp_17)(11, *(s32 *)(arg1 + 0x60));
    }
    if (*(s32 *)(arg1 + 0x58) & 2) {
        func_003a93b0(*(u8 **)(temp_18 + 0), *(u8 **)(arg1 + 0xC),
                      arg2, *(u8 **)(arg1 + 0x24));
    } else {
        func_003e9700(*(s32 *)(*(u8 **)(temp_18 + 8) + 4));
        temp_16 = (u8 *)(u32)func_003a14f0(*(u8 **)(temp_18 + 4),
                                            *(u8 **)(temp_18 + 8));
        func_003a9880(*(u8 **)(temp_18 + 0), *(u8 **)(arg1 + 0xC),
                      arg2, temp_16 + 0x20);
    }
    if (*(s32 *)(arg1 + 0x64) != 0) {
        temp_16 = (u8 *)D_00887300;
        (*(void (**)(s32, s32))temp_16)(10, sp6C);
        (*(void (**)(s32, s32))temp_16)(11, sp68);
    }
    return 0;
}
