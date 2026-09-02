/* EFcl lane draft (killed by provider rate limit mid-work): object 612B / window 624B, nd249. Unfinished; not measured further. */
// FUN_00324410
void func_00324410(u8 *arg0, s64 arg1, s64 arg2) {
    extern u8 *func_002b6150(s64);
    extern s16 func_002b6970(s16, s16);
    extern void func_002b7750(s64, s16);
    extern void func_002b68d0(s64, s32, s32);
    extern void func_002b69f0(s64, s64, s64, u32, u32, s16);
    extern void func_002b6af0(s64, u32, u32, s32, f32, f32, f32, f32);
    extern void func_002b6a70(s64, u8, u8, s32, s32, s32);
    FclVec2 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    f32 f20;
    u8 *t;
    s32 v17;

    t = *(u8 **)(arg0 + 0x38);
    sp68 = *(FclVec2 *)(t + 0x298);
    v17 = (s8)arg2;
    switch (*(s8 *)((u8 *)(v17 + (s32)t) + 0x294)) {
    case 0:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 2) == 1) {
            break;
        }
        func_002b7750(arg1, 0x1C7);
        func_002b68d0(arg1, 0, 0);
        if (v17 == 0) {
            func_002b2970(&sp60, 280.0f + sp68.x, sp68.y);
            func_002b69f0(arg1, *(s64 *)&sp68, sp60, 0, 0x32, 0);
        } else if (v17 == 1) {
            f20 = 20.0f + sp68.y;
            func_002b2970(&sp58, 280.0f + sp68.x, f20);
            func_002b2970(&sp50, sp68.x, f20);
            func_002b69f0(arg1, sp58, sp50, 0, 0x32, 0);
        }
        func_002b6af0(arg1, 0, 0, 0, 1.0f, 2.0f, 1.0f, 1.0f);
        func_002b6a70(arg1, 0, 0xFF, 1, 0x32, 0);
        *(s8 *)(func_002b6150(arg1) + 0x73) = 1;
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 1;
        break;
    case 1:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 1) == 1) {
            break;
        }
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 0;
        break;
    case 2:
        func_002b68d0(arg1, 0, 1);
        break;
    }
}
