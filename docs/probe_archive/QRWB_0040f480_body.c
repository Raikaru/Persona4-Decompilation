/* object_size=188 window=240 normalized_diff=59 differing_offsets=14,15,16,17,18,19,22,23,24,40,43,44,46,47,52,64 classification=undersized; ruled_out=absolute-array globals D_0070C340/D_0070C360/D_0070C364 and GP iGpffffb938 were declared, no movz/movn/COP1 accumulator/MMI/tail-jump floor; plain candidate omitted 52 retail bytes in bitfield update/control shape */
void func_0040f480(u8 *arg0)
{
    extern s32 D_0070C340[];
    extern void (*D_0070C360[])(u8 *arg0);
    extern u8 D_0070C364[];
    u8 *temp_16;
    u8 *temp_4;
    u32 temp_6;

    temp_16 = arg0 + iGpffffb938;
    if ((arg0 != D_0070C364) &&
        ((arg0[0x20] & 0x80) == 0) &&
        (*(s32 *)(arg0 + 4) != 0) &&
        (*(u8 **)(temp_16 + 0x58) == NULL)) {
        D_0070C360[0]((u8 *)1);
        temp_4 = *(u8 **)(temp_16 + 0x58);
        if ((temp_4 != NULL) && (D_0070C340[0] != 0)) {
            temp_6 = *(u32 *)(temp_4 + 4) >> 6;
            *(u32 *)(temp_16 + 8) &= ~0x3fff;
            *(u32 *)(temp_16 + 8) |= temp_6 & 0x3fff;
            *(u32 *)(temp_16 + 0xc) &= 0xfff8001f;
            *(u32 *)(temp_16 + 0xc) |=
                (u32)((s64)((((temp_6 + *(u32 *)(temp_16 + 0x10)) &
                              0x3fff) << 5) << 0x20) >> 0x20);
        }
    }
}
