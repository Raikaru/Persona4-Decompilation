/* object 444B/window 448B, normalized_diff 231, differing offsets 0x022,0x024,0x026,0x02E,0x032,0x035,0x03A,0x03C,0x044-0x04D,0x04E,0x050,0x052,0x054; classification: branch-placement/register-allocation near-miss after shared return-tail probe; best measured branch-goto shape was object 440B/window 448B, nd 221. Retail prologue saves $ra/$s3/$s2/$s1/$s0 with a 0x60 frame. Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature. Corrected the forward declaration of func_0047a510 to its s32 return type; existing callee declarations for func_003e9af0, func_003e9700, func_003e05f0, func_00457f40 and callback func_00475b10 were used with explicit types/casts. Probed declaration order, direct-vs-local container/list loads, branch-goto placement, reversed guard polarity, a single-case switch, and a shared return-tail; no exact match. */
// FUN_0047A510
s32 func_0047a510(void* arg0, s32 arg1, void* arg2)
{
    s32 stack5C;
    s32 stack58;
    s32 value;
    s32 temp;
    s32 index;
    s32 maskedIndex;
    s32 key;
    s32 copyCount;
    s32 result;
    u16 count;
    u8* entry;
    u8* container;
    u8* list;
    u8* dst;
    u8* src;

    dst = (u8*)arg2;
    list = *(u8**)((u8*)arg0 + 0x2C8);
    if (list != (u8*)0) {
        container = *(u8**)((u8*)arg0 + 0xDC);
        count = *(u16*)list;
        index = 0;
        key = arg1 & 0xFFFF;
        goto search_check;
search_body:
        entry = *(u8**)(list + 4) + ((index & 0xFFFF) * 0x50);
        if (key != *(s32*)(entry + 0x40)) {
            index = (index + 1) & 0xFFFF;
            goto search_check;
        }
        goto search_found;
search_check:
        maskedIndex = index & 0xFFFF;
        switch (maskedIndex < (s32)count) {
        case 1:
            goto search_body;
        }
        goto search_found;
search_found:
        if (maskedIndex == (s32)count) {
            result = 0;
        } else {
            entry = *(u8**)(list + 4) + ((index & 0xFFFF) * 0x50);
            value = *(s32*)(entry + 0x44);
            temp = (s32)*(u8**)(container + 4);
            if (value != ((s32 (*)(u8*))func_00397470)((u8*)temp)) {
                stack5C = value;
                stack58 = 0;
                func_003e9af0((u8*)temp,
                              (s32 (*)(u8*, s32))func_00475b10,
                              (s32)&stack58);
                temp = stack58;
            }
            if (temp == 0) {
                result = 0;
            } else {
                func_003e05f0(dst, entry, func_003e9700((u8*)temp));
                result = 1;
            }
        }
        goto done;
    }
    src = (u8*)func_00457f40(*(void**)((u8*)arg0 + 0xDC),
                             (const char*)D_007131D8, arg1);
    if (src == (u8*)0) {
        result = 0;
    } else {
        src = func_003e9700(src);
        for (copyCount = 8; copyCount > 0; copyCount--) {
            *(u32*)dst = *(u32*)src;
            *(u32*)(dst + 4) = *(u32*)(src + 4);
            src += 8;
            dst += 8;
        }
        result = 1;
    }
done:
    return result;
}
