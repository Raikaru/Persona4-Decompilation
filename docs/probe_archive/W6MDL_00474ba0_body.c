/* object 320B / window 320B / nd 41 */
void* func_00474ba0(void* param_1, void* param_2)
{
    s16 rawIndex;
    s64 lVar2;
    u16 count;
    void* list;
    void* elem;

    if ((param_2 == 0) ||
        ((rawIndex = *(s16*)((u8*)param_2 + 4),
          list = *(void**)((u8*)param_2 + 0x18), list != 0) &&
         (lVar2 = (s64)rawIndex, count = *(u16*)((u8*)list + 0xC),
          lVar2 < (s64)(u32)count)) &&
        (elem = *(void**)((u8*)*(void**)list + rawIndex * 8), elem != 0) &&
        (*(u16*)param_2 & 1)) {
        func_003d5840(param_1, *(void**)param_1);
        *(void**)((u8*)param_1 + 0x40) = (void*)func_00474a50;
        *(void**)((u8*)param_1 + 0x44) = (void*)func_00474a90;
        return param_1;
    }

    list = *(void**)((u8*)param_2 + 0x18);
    if (list != 0) {
        lVar2 = (s64)*(s16*)((u8*)param_2 + 4);
        count = *(u16*)((u8*)list + 0xC);
        if (lVar2 < (s64)(u32)count &&
            (elem = *(void**)((u8*)*(void**)list + (s32)lVar2 * 8), elem != 0) &&
            (*(u16*)param_2 & 1) == 0 &&
            lVar2 < (s64)(u32)count && *(s16*)((u8*)param_2 + 4) >= 0) {
            func_003d5e40(param_1, *(f32*)((u8*)*(void**)param_1 + 0xC));
            *(u8*)((u8*)param_2 + 2) = 1;
        }
    }
    return param_1;
}
