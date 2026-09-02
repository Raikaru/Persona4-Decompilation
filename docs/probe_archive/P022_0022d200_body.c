/* object_size=800; window=832; normalized_diff=437; status=MISMATCH; differing_offsets=... (many); levers tried: plain-C reconstruction; unresolved: branch chain layout. */

s32 func_0022d200(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_6;
    u16 temp_5;
    u16 temp_4;

    temp_2 = DAT_0076449c;
    if (!(*(s32 *)(temp_2 + 0xC) & 0x200000)) {
        return 0;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 0;
    }
    temp_6 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_6 + 0xA2) != 1) {
        return 0;
    }
    temp_5 = *(u16 *)(temp_6 + 0xA4);
    if ((temp_5 == 0x10E) || (temp_5 == 0x10B)) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if ((temp_4 == 0x181) || (temp_4 == 0x18B) || (temp_4 == 0x182) || (temp_4 == 0x185)) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if ((temp_5 == 0x113) || (temp_5 == 0x10A)) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if ((temp_4 == 0x17F) || (temp_4 == 0x186)) {
            return *(s32 *)(temp_2 + 0xBF0);
        } else if (temp_4 == 0x180) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if (temp_5 == 0x108) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if (temp_4 == 0x17A) {
            return *(s32 *)(temp_2 + 0xBF0);
        } else if (temp_4 == 0x17C) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if (temp_5 == 0x105) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        switch (temp_4) {
        case 0x16B:
        case 0x16A:
        case 0x16C:
            return *(s32 *)(temp_2 + 0xBF0);
        default:
            return *(s32 *)(temp_2 + 0xBE0);
        }
    } else if ((temp_5 == 0x10F) || (temp_5 == 0x106)) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if ((temp_4 == 0x16D) || (temp_4 == 0x173) || (temp_4 == 0x174) || (temp_4 == 0x175) || (temp_4 == 0x176) || (temp_4 == 0x177)) {
            return *(s32 *)(temp_2 + 0xBF0);
        } else if (temp_4 == 0x172) {
            return *(s32 *)(temp_2 + 0xBF4);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if (temp_5 == 0x104) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if (temp_4 == 0x169) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if (temp_5 == 0x103) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if ((temp_4 == 0x166) || (temp_4 == 0x167) || (temp_4 == 0x168)) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else if (temp_5 == 0x100) {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        if (temp_4 == 0x160) {
            return *(s32 *)(temp_2 + 0xBF0);
        }
        return *(s32 *)(temp_2 + 0xBE0);
    } else {
        return *(s32 *)(temp_2 + 0xBE0);
    }
}
