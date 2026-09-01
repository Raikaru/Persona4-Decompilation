/* object=344 window=352 normalized_diff=175; first_diffs=44,46,47,48,52,56,57,58,59,60,61,62,63,64; classification=undersized declaration/order/address-materialization near-miss archived after corrected block-scope callees; ruled out: retail window has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, or sd $sN prologue; callee declarations corrected locally for func_003d5790(void*,void*) -> void*, func_003bff30(void*,void*,void*), func_004633c0(void*,void*), func_003d5e40(u8*,f32); tried data/data+4/resource temporaries and setup ordering; no live mismatch retained. */
void func_00473710(u8* arg0, u8* arg1, s32 arg2)
{
    extern void* func_003d5790(void*, void*);
    extern void func_003bff30(void*, void*, void*);
    extern void func_004633c0(void*, void*);
    extern s32 func_003d5e40(u8*, f32);
    u8* data4;
    u8* data;
    u8* resource;
    u32 value;
    void* obj;
    void* tmp;

    data = arg1;
    value = 0;
    data4 = data + 4;
    resource = *(u8**)(data + 4);
    func_003e9af0(resource, (s32 (*)(u8*, s32))func_004711e0,
                  (s32)&value);
    *(void**)(arg0 + 0x20) = (void*)value;
    func_003bff30(data, (void*)func_00471250, &value);
    if (arg2 != 0) {
        func_003bff30(data, (void*)func_00473250, *(void**)data4);
    }
    func_004633c0(data, *(void**)(arg0 + 0x20));
    obj = *(void**)(arg0 + 0x20);
    *(u32*)obj |= 0x3000;
    tmp = *(void**)(arg0 + 0x34);
    if (tmp != (void*)0 && *(void**)((u8*)tmp + 4) != (void*)0) {
        obj = *(void**)(arg0 + 0x20);
        *(void**)(arg0 + 0x2C) = func_003d5790(*(void**)((u8*)obj + 4), *(void**)((u8*)*(void**)((u8*)obj + 0x20) + 0x20));
        obj = *(void**)(arg0 + 0x20);
        *(void**)(arg0 + 0x30) = func_003d5790(*(void**)((u8*)obj + 4), *(void**)((u8*)*(void**)((u8*)obj + 0x20) + 0x20));
        tmp = *(void**)(arg0 + 0x34);
        func_003d5840(*(void**)(arg0 + 0x2C), *(void**)((u8*)tmp + 4));
        func_003d5840(*(void**)(arg0 + 0x30), *(void**)((u8*)tmp + 4));
        func_003d5e40(*(void**)(arg0 + 0x30), 0.0f);
        *(u16*)arg0 |= 0x80;
    }
}
