/* Closest candidate for func_003627b0; retained for reference after reverting non-MATCH. */
s32 func_003627b0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    u8 query[0x30];
    s32 resultFlag = 1;
    s32 queryResult;
    s16 soundType;
    u16 timer;
    u16 timer2;
    f32 alpha;

    *arg1 = 1;
    switch (*arg0) {
    case 0:
        *(s32 *)(arg2 + 4) = 0;
        *(s32 *)(arg2 + 8) = 0;
        *(u8 *)arg2 = 0xFF;
        func_0035f5b0(arg2);
        *arg0 = 1;
        *arg1 = 0;
        goto block_64;
    case 1:
        if ((func_0035fc40(arg2) != 0) && (func_0034c210() != 0)) {
            *arg0 = 3;
            func_0034bb20(0x1D);
        } else {
            *arg1 = 0;
        }
        goto block_64;
    case 2:
        if (func_003619b0(arg2) != 0) {
            func_00361a30(arg2);
            return 1;
        }
        goto block_64;
    case 3:
        if (func_003619b0(arg2) != 0) {
            func_0035fa20(arg2, 2);
            *arg0 = 4;
        }
        goto block_64;
    case 4:
        if (D_008C024E[0] & 0x20) {
            func_0035fa20(arg2, resultFlag);
            *arg0 = 2;
            func_0034bb20(0x1E);
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            soundType = *(s16 *)(arg2 + 0x28);
            switch (soundType) {
            case 0:
                func_0035fa20(arg2, resultFlag);
                *arg0 = 5;
                func_0034bb20(0x1E);
                break;
            case 1:
                func_0035fa20(arg2, resultFlag);
                *arg0 = 8;
                func_0034bb20(0x1E);
                break;
            case 2:
                func_002badc0(*(s8 *)(arg2 + 0x3C), 4);
                func_002bafc0(*(s8 *)(arg2 + 0x3C), 0);
                func_002bbf60();
                func_002bb0a0(*(s8 *)(arg2 + 0x3C), 1);
                *arg0 = 0xA;
                break;
            }
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xC;
        } else {
            func_00453670(query, 3, 3, *(s16 *)(arg2 + 0x28), 0);
            func_004538e0(query, 0x4000, 0x1000, 0, 0);
            if (func_00453960(query) != 0) {
                func_0035fa00(arg2, 0, *(s16 *)(query + 0x24));
                func_0045af60(0, 1, 0, 0);
            }
        }
        goto block_64;
    case 5:
        if (func_003619b0(arg2) != 0) {
            func_00362630(arg2);
            func_0035fa20(arg2, 3);
            *arg0 = 6;
            func_0034bb20(0x1F);
        }
        goto block_64;
    case 6:
        if (func_003619b0(arg2) != 0) {
            func_0035fa20(arg2, 4);
            *arg0 = 7;
            func_00353fe0();
        }
        goto block_64;
    case 7:
        if (D_008C024E[0] & 0x20) {
            func_0035fa20(arg2, 5);
            *arg0 = 1;
            func_0034bb20(0x20);
            func_00353fb0();
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xC;
        } else {
            func_00453670(query, 6, *(s32 *)(arg2 + 0x38),
                          *(s16 *)(arg2 + 0x2A), *(s16 *)(arg2 + 0x2C));
            func_004538e0(query, 0x4000, 0x1000, 0x2000, 0x8000);
            queryResult = func_00453960(query);
            if (queryResult > 0) {
                func_0035fa00(arg2, 1, *(s16 *)(query + 0x24));
                func_0035fa00(arg2, 2, *(s16 *)(query + 0x28));
                if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x32)) {
                    func_00361970(arg2);
                }
                func_00354080(queryResult);
            }
        }
        goto block_64;
    case 8:
        if (func_0034c210() != 0) {
            *(s32 *)(arg2 + 0x704) = func_0035c690(0, 0);
            *arg0 = 9;
        }
        goto block_64;
    case 9:
        if (func_0035c7d0(*(u8 **)(arg2 + 0x704)) != 0) {
            if (func_0035c7f0(*(u8 **)(arg2 + 0x704)) != 0) {
                return 2;
            }
            func_00452080(*(s32 *)(arg2 + 0x704));
            *(s32 *)(arg2 + 0x704) = 0;
            *arg0 = 1;
        }
        goto block_64;
    case 10:
        func_002bb9e0(*(s8 *)(arg2 + 0x3C), resultFlag);
        if (func_002bb680(*(s8 *)(arg2 + 0x3C)) == 0) {
            switch (func_002bb180(*(s8 *)(arg2 + 0x3C))) {
            case 0:
                func_00122520(1, 0x1E);
                func_004598e0(0x1E);
                func_0045aac0(3, 0, 0x1E);
                *arg0 = 0xB;
                break;
            case 1:
                *arg0 = 4;
                break;
            }
            func_002bb290((s8)*(s8 *)(arg2 + 0x3C), 1);
        }
        goto block_64;
    case 11:
        if (func_00122720() != 0) {
            func_001029a0(0x1B, 0, 0, 0xA);
        }
        goto block_64;
    case 12:
        timer = (u16)(*(u16 *)(arg2 + 0xC) + 1);
        *(u16 *)(arg2 + 0xC) = timer;
        if ((timer & 0xFFFF) >= 3) {
        } else {
            timer2 = *(u16 *)(arg2 + 0xC);
            alpha = 255.0f * (1.0f - ((f32)timer2 / 3.0f));
            *(u8 *)arg2 = (u8)alpha;
            resultFlag = 0;
        }
        break;
    }
    if (resultFlag != 0) {
        return 2;
    }
block_64:
    return 0;
}
