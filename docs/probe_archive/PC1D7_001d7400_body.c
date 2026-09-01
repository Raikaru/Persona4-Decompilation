/* measured: abandoned PC1D7 probe body; object 452B / window 464B / normalized_diff 4, differing words at offsets 428,432,436,440 (mov-chain
   register rotation). Lane stalled mid-probe; declaration-order variants
   were tested (build/PC1D7_declorder.json) and did not move it. */
void func_001d7400(s32 arg0, u8 *arg1)
{
    u8 *arg1_p = arg1;
    s32 arg0_p = arg0;
    u8 temp_3;
    u8 temp_2;
    u8 temp_1;
    u8 temp_0;

    *(u8 *)(3 + arg1) = 0xFF;
    switch (arg0_p) {
    case 2:
        *(u8 *)(arg1_p + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xB2;
        *(u8 *)(arg1_p + 2) = 0x9E;
        break;
    case 4:
        *(u8 *)(arg1 + 0) = 0xB2;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(arg1_p + 2) = 0xFF;
        break;
    case 8:
        *(u8 *)(arg1_p + 0) = 0xB2;
        *(u8 *)(arg1 + 1) = 0xFF;
        *(u8 *)(arg1 + 2) = 0xB2;
        break;
    case 0x10:
        *(u8 *)(arg1 + 0) = 0xEE;
        *(u8 *)(arg1_p + 1) = 0x9B;
        *(u8 *)(arg1_p + 2) = 0xDA;
        break;
    case 1:
        *(u8 *)(arg1_p + 0) = 0xFF;
        *(u8 *)(arg1_p + 1) = 0x94;
        *(u8 *)(arg1_p + 2) = 0x76;
        break;
    case 0x20:
        *(u8 *)(arg1 + 0) = 0xBC;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(2 + arg1) = 0xFF;
        break;
    case 0x40:
        *(u8 *)(0 + arg1_p) = 0x9E;
        *(u8 *)(arg1_p + 1) = 0xE4;
        *(u8 *)(arg1_p + 2) = 0xE1;
        break;
    case 0x80:
        *(u8 *)(arg1 + 0) = 0xCD;
        *(u8 *)(arg1_p + 1) = 0xB9;
        *(u8 *)(arg1_p + 2) = 0xD7;
        break;
    case 0x100:
        *(u8 *)(0 + arg1_p) = 0x94;
        *(u8 *)(arg1 + 1) = 0x10;
        *(u8 *)(arg1_p + 2) = 0x26;
        break;
    case 0x100000:
    case 0x80000:
    default:
        temp_1 = iGpffffa4d8;
        temp_2 = iGpffffa4d9;
        temp_0 = iGpffffa4da;
        temp_3 = iGpffffa4db;
        *(u8 *)(arg1 + 0) = temp_1;
        *(u8 *)(arg1_p + 1) = temp_2;
        *(u8 *)(arg1_p + 2) = temp_0;
        *(u8 *)(arg1 + 3) = temp_3;
        break;
    }
}
