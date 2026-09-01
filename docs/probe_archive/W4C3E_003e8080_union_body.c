#pragma schedule on
s32 func_003e8080(s32 arg0, s32 arg1) {
    extern s32 D_00763C7C;
    extern s32 D_00763C80;
    extern u8 D_008872B0[];

    D_007648A0 = arg1;
    ((union { s32 value; } *)(D_008872E0 + D_007648A0))->value = func_003e1220(*(s32 *)D_0070B710, D_00763C7C, 0x10, D_00763C80, D_008872B0, 0x40005);
    if (((union { s32 value; } *)(D_008872E0 + D_007648A0))->value == 0) {
        return 0;
    }
    D_007648A4 += 1;
    return arg0;
}
#pragma schedule off
