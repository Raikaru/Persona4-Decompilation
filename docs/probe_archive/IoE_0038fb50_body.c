// FUN_0038FB50 archive (wave Io lane IoE cut off mid-work; body is the live state at cutoff, status MISMATCH-nd262).
u8 *func_0038fb50(u8 *arg0, s32 arg1)
{
    extern s32 func_003deff0();
    extern s32 func_003e2ab0();
    extern s32 func_003df270();
    struct {
        s32 f0;
        f32 f10;
        f32 f14;
        f32 f18;
        f32 f4;
        f32 f8;
        f32 fC;
        s32 f1C;
        s32 f1E;
    } header;
    struct {
        s32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    } entry;
    u32 count;
    s32 offset;
    u16 temp_2;
    u8 *temp_2_2;

    offset = 0x30;
    offset += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        offset += *(u16 *)(arg0 + 0x1C) * 2;
    }
#pragma push
/* measured: schedule on fills the first two call delay slots only. */
#pragma schedule on
    if (func_003deff0(arg1, 0x2C, offset, 0x37002, 0x37) == 0) {
        goto block_17;
    }
    if (func_003deff0(arg1, 1, offset - 0xC, 0x37002, 0x37) == 0) {
        goto block_17;
    }
#pragma pop
    header.f10 = *(f32 *)(arg0 + 0x10);
    header.f0 = *(s32 *)arg0;
    header.f14 = *(f32 *)(arg0 + 0x14);
    header.f1C = *(u16 *)(arg0 + 0x1C);
    header.f18 = *(f32 *)(arg0 + 0x18);
    header.f1E = *(u16 *)(arg0 + 0x1E);
    header.f4 = *(f32 *)(arg0 + 4);
    header.f8 = *(f32 *)(arg0 + 8);
    header.fC = *(f32 *)(arg0 + 0xC);
    if (func_003e2ab0(arg1, (u8 *)&header, 0x24) == 0) {
        goto block_17;
    }
    temp_2 = *(u16 *)(arg0 + 0x1E);
    if ((s32)temp_2 > 0) {
        count = 0;
        if (temp_2 != 0) {
            offset = 0;
            do {
                temp_2_2 = (u8 *)(*(s32 *)(arg0 + 0x20) + offset);
                entry.f0 = *(s32 *)temp_2_2;
                entry.f4 = *(f32 *)(temp_2_2 + 4);
                entry.f8 = *(f32 *)(temp_2_2 + 8);
                entry.fC = *(f32 *)(temp_2_2 + 0xC);
                if (func_003e2ab0(arg1, (u8 *)&entry, 0x10) == 0) {
                    goto block_17;
                }
                count += 1;
                offset += 0x10;
                if (count >= *(u16 *)(arg0 + 0x1E)) {
                    goto block_13;
                }
            } while (1);
        }
    }
block_13:
    if (*(s32 *)arg0 & 1) {
        if (func_003df270(arg1, *(u8 **)(arg0 + 0x24),
                          *(u16 *)(arg0 + 0x1C) * 2) == 0) {
            goto block_17;
        }
        return arg0;
    }
block_17:
    return NULL;
}
