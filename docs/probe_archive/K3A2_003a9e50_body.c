/* object_size=240 window=240; retail body is straightforward but no source probes were completed before handoff. */
s32 func_003a9e50(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;

    temp_2 = (u8 *)func_003c2630(0, 0, 0);
    if (temp_2 != NULL) {
        temp_3 = *(u8 **)(temp_2 + 0x5C);
        *(s32 *)(temp_3 + 4) = 0;
        *(s32 *)(temp_3 + 8) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
        *(s32 *)(temp_3 + 0x10) = 0x3F800000;
        if (func_003c22f0(temp_2) == 0) {
            return 0;
        }
        func_003c0210(arg0, temp_2, 0);
        func_003c2a80(temp_2);
        temp_2_2 = (u8 *)func_003c4140();
        func_003c4a80(temp_2 + 0x20, temp_2_2);
        func_003c4220(temp_2_2);
        temp_3_2 = *(u8 **)(arg0 + iGpffffb610);
        *(s32 *)(temp_3_2 + 0x24) = 0;
        *(s32 *)(temp_3_2 + 0x28) = 0;
        *(s32 *)(temp_3_2 + 0x2C) = 0;
        *(s32 *)(temp_3_2 + 0x30) = 0;
        *(s32 *)(temp_3_2 + 0x34) = 0;
        *(s32 *)(temp_3_2 + 0x38) = 0;
        return 1;
    }
    return 0;
}
