// FUN_001F58D0
void func_001f58d0(void)
{
    u8 *base;
    u16 *modePtr;
    u16 mode;
    s16 *counter;
    u8 *resourceTable;
    u8 *record;
    s32 offset;
    u32 recordOffset;
    u32 randomValue;

    base = iGpffffb3c4;
    modePtr = (u16 *)(base + 0xa50);
    mode = *modePtr;
    switch (mode) {
    case 0:
        goto updateFlag;
    case 1:
        counter = (s16 *)(base + 0xa6e);
        if (*counter > 0) {
            *counter = *counter - 1;
            goto updateFlag;
        }
        *modePtr = 2;
    case 2:
        break;
    default:
        goto updateFlag;
    }
    resourceTable = *(u8 **)(base + 0xa54);
    record = *(u8 **)(resourceTable + 0x110);
    recordOffset = (u32)*(u16 *)(base + 0xa60) * 0xc;
    recordOffset += (u32)record;
    offset = *(u32 *)(recordOffset + 4);
    record += offset;
    func_002bd270((u32)record);
    randomValue = func_00231d70((u32)func_002777a0(record));
    func_002bd280(*(u16 *)(base + 0xa4c), randomValue, 0, 0);
    *(u32 *)(base + 0xa58) = *(u32 *)(base + 0xa60);
    *(u16 *)(base + 0xa5c) = *(s16 *)(base + 0xa64);
    *(u16 *)(base + 0xa4e) |= 1;
    *(u16 *)(base + 0xa50) = 0;
updateFlag:
    if (func_002bd340() == 0)
        *(u16 *)(base + 0xa4e) &= (u16)~1;
}
