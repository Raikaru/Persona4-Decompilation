/* object 328/304 normalized_diff=141 differing offsets=52,92,96,110,114,132,146,170-... classification=register-colouring residual; ruled-out=frame/signature, old-style helper declarations, base/offset evaluation order, while/for loop shape, pointer/integer result-local type */
void func_00296720(u8 *arg0, u8 *arg1)
{
    extern u8 *func_00286780();
    extern u8 *func_00286f00();
    s32 index;
    s32 temp;
    s32 limit;
    s32 offset;
    u8 *entry;
    u8 *dest;

    temp = (s32)func_00286f00(19, arg1);
    if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) < 6)
        limit = *(s32 *)(arg0 + 0xAC);
    else
        limit = *(s32 *)(arg0 + 0xA8);
    for (index = 0; index < limit; index++) {
        entry = *(u8 **)(arg0 + 0xA4);
        offset = index * 0x3C;
        entry += offset;
        if (*(u16 *)entry == 19) {
            dest = func_00286780((u8 *)temp, *(u16 *)(entry + 2), arg1);
            *(s16 *)(dest + 8) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0xC);
            *(s16 *)(dest + 0xA) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0xE);
            *(s16 *)(dest + 0xC) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0x10);
            *(s16 *)(dest + 0xE) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0x12);
            *(s16 *)(dest + 0x10) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0x14);
            *(s16 *)(dest + 0x12) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0x16);
            *(s16 *)(dest + 0x14) = *(s16 *)(*(u8 **)(arg0 + 0xA4) + offset + 0x18);
        }
    }
}
