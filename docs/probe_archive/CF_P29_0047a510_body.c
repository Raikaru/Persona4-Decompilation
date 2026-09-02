/* CF_P29 attempted body for func_0047a510; better localized starting point.
 * Measurement: object 432B/window 448B, normalized_diff 165.
 * The top loop (offsets 0x00..0x84 / 0..132) is byte-exact with s32 count
 * loaded once from the u16 list field; residual begins at the callback branch
 * after offset 0x88 / 136 and the callback argument materialization. The body
 * is 8B shorter than the 448B retail window.
 * Retail registers: saves $ra,$s3,$s2,$s1,$s0; $a4=list, $a3=container,
 * $a2=count, $a5=index, $a1=key, $s3=entry, $s1=value, $s2=temp,
 * $s0=destination. Tried: generated pseudocode, declaration/local-order
 * permutations, pointer load variants, u16/s32/u32 counter shapes, signed
 * count, callback array, if/else/goto/switch/while branch forms, and
 * optimization pragmas.
 */
s32 func_0047a510(void* arg0, s32 arg1, void* arg2)
{
    s32 key;
    u16* list;
    s32 count;
    u16 index;
    s32 bodyIndex;
    s32 testIndex;
    s32 foundIndex;
    u8* entry;
    s32 value;
    s32 temp;
    s32 result;
    u8* dst;
    u8* src;
    s32 copyCount;
    s32 copyLo;
    s32 copyHi;
    s32 callbackArgs[2];
    u8* container;

    dst = (u8*)arg2;
    list = *(u16**)((u8*)arg0 + 0x2C8);
    if (list != (u16*)0) {
        container = *(u8**)((u8*)arg0 + 0xDC);
        count = *list;
        index = 0;
        key = arg1 & 0xFFFF;
        goto loop_test;
loop_body:
        bodyIndex = index & 0xFFFF;
        entry = *(u8**)((u8*)list + 4) +
                (bodyIndex * 0x50);
        if (key == *(s32*)(entry + 0x40)) {
            goto found;
        }
        index += 1;
loop_test:
        testIndex = index & 0xFFFF;
        if (testIndex < count) {
            goto loop_body;
        }
found:
        if (testIndex == count) {
            result = 0;
        } else {
            foundIndex = index & 0xFFFF;
            entry = *(u8**)((u8*)list + 4) +
                    (foundIndex * 0x50);
            value = *(s32*)(entry + 0x44);
            temp = (s32)*(u8**)(container + 4);
            if (value != (s32)func_00397470((void*)temp)) {
                callbackArgs[1] = value;
                callbackArgs[0] = 0;
                func_003e9af0((u8*)temp,
                              (s32 (*)(u8*, s32))func_00475b10,
                              (s32)&callbackArgs[0]);
                temp = callbackArgs[0];
            }
            if (temp == 0) {
                result = 0;
            } else {
                func_003e05f0(dst, entry, func_003e9700((u8*)temp));
                result = 1;
            }
        }
    } else {
        src = (u8*)func_00457f40(*(void**)((u8*)arg0 + 0xDC),
                                 (const char*)D_007131D8, arg1);
        if (src == (u8*)0) {
            result = 0;
        } else {
            src = func_003e9700(src);
            copyCount = 8;
            do {
                copyLo = *(s32*)(src + 0);
                copyHi = *(s32*)(src + 4);
                src += 8;
                copyCount -= 1;
                *(s32*)(dst + 0) = copyLo;
                *(s32*)(dst + 4) = copyHi;
                dst += 8;
            } while (copyCount > 0);
            result = 1;
        }
    }
    return result;
}
