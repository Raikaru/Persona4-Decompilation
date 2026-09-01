/* object 932B / window 848B / normalized_diff 732; differing offsets: 0x0, 0x4, 0x8, 0xA, 0xC, 0xE, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1C, 0x1D, 0x1E, 0x1F and throughout; classification: oversized reconstruction; ruled out: corrected 5-argument signature, block-scope helper declarations, stream decode loops, scratch stack layout, and direct jump-table error paths; object exceeded retail window on first measurement, so archived immediately. */
u8 *func_0038fe90(u8 *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4)
{
    extern s32 func_003df300(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df360(u8 *arg0, void *arg1, s32 arg2);
    extern u8 *func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s32 arg0, ...);
    extern s32 func_003e2ce0(u8 *arg0, s32 arg1);
    extern void (*jtbl_008873EC[])(u8 *arg0);
    extern u8 *func_0038f990(u16 arg0, u16 arg1, f32 *arg2, s32 arg3);
    u8 *stream;
    u8 *obj;
    u8 *data;
    u8 *record;
    u8 **records;
    u8 scratch[176];
    u32 input0;
    u32 input1;
    u32 input2;
    u32 input3;
    u32 failure0;
    u32 failure1;
    s32 depth;
    s32 i;
    s32 j;
    s32 value;
    u16 count;

    stream = arg0;
    *arg4 = 0;
    obj = func_0038f990(arg1 & 0xFFFF, arg2 & 0xFFFF, arg3, 1);
    if (obj == NULL) {
        return NULL;
    }
    count = *(u16 *)(obj + 0x1E);
    if (count > 0) {
        data = *(u8 **)(obj + 0x20);
        i = 0;
        while (1) {
            if (func_003df360(stream, &input0, 4) == 0 ||
                func_003df360(stream, &input1, 4) == 0 ||
                func_003df300(stream, data + 4, 4) == 0 ||
                func_003df300(stream, data + 0xC, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            data[8] = input0 >> 16;
            data[0] = data[8] | 1;
            *(s16 *)(data + 0xA) = input1;
            *(s16 *)(data + 2) = input1 >> 16;
            data[1] = (((input0 >> 8) & 0xFF) == 2) ? 0xFF : 0;
            data[9] = ((u8)input0 == 2) ? 0xFF : 0;
            i++;
            data += 0x10;
            if (i >= count) {
                break;
            }
        }
    } else if (func_003e2ce0(stream, 4) == 0) {
        jtbl_008873EC[0](obj);
        return NULL;
    }
    records = (u8 **)scratch;
    record = scratch + 0x98;
    record[0] = 0;
    record[1] = 0xFF;
    depth = 1;
    while (1) {
        if (record[1] == 0xFF) {
            record = *(u8 **)(*(u8 **)(obj + 0x20) +
                              (*(u16 *)(record + 2) * 0x10));
            records[depth++] = record + 8;
            continue;
        }
        if (func_003df360(stream, &input2, 4) == 0) {
            jtbl_008873EC[0](obj);
            return NULL;
        }
        value = (input2 >> 16) & 0xFFFF;
        if (value < 0xF0) {
            record[1] = value;
            depth--;
            *(u16 *)(record + 2) = input2;
            record = records[depth];
            if (depth == 0) {
                break;
            }
            continue;
        }
        *arg4 = 1;
        jtbl_008873EC[0](obj);
        failure0 = 0x11D;
        failure1 = func_003df590(1);
        func_003df4d0((s32 *)&failure0);
        return NULL;
    }
    if ((*(s32 *)obj & 1) != 0) {
        j = 0;
        count = *(u16 *)(obj + 0x1C);
        i = 0;
        while (i < count) {
            if (func_003df360(stream, &input3, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            *(u8 *)(*(u32 *)(obj + 0x24) + j) = (s16)input3;
            i++;
            j += 2;
        }
    }
    return obj;
}
