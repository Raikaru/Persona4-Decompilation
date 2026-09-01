/* object 492B/window 496B, normalized_diff 320, differing offsets 0x018-0x1E4 (106 differing words; residual in hundreds); classification: MWCC candidate with wrong callback/array statement shape and register allocation; archive-immediately condition reached. Retail prologue: addiu $sp,-96; sd $ra,64($sp); sq $s3,48($sp), sq $s2,32($sp), sq $s1,16($sp), sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature. Corrected block-scope declarations for iGpffffb3b8, D_008872E0, jtbl_008873E8, func_004118c0, func_00411a70, func_003df590, and func_003df4d0; no further probes after hundreds residual. */
// FUN_00412CA0
u8 *func_00412ca0(u8 *arg0)
{
    extern u8 *iGpffffb3b8;
    extern u8 D_008872E0[];
    extern u8 *(*jtbl_008873E8[])();
    extern s32 func_004118c0(s32 *, u32);
    extern s32 func_00411a70(s32 *, s32 *);
    extern s32 func_003df590(s32, ...);
    extern void func_003df4d0(s32 *);
    u8 *base;
    u8 **array;
    u8 **slot;
    u8 *object;
    u32 count;
    u32 size;
    u32 offset;
    void (*callback)(u8 **);
    void (*release)(u8 *);
    s32 fail_words;
    s32 fail_value;

    if (*(s32 *)(arg0 + 0) == 0) {
        base = D_008872E0 + (u32)iGpffffb3b8;
        count = *(u32 *)(base + 0x38);
        size = count * 0xB4;
        array = *(u8 ***)(arg0 + 8);
        if (array != NULL) {
            if (*(u32 *)(arg0 + 0x24) < size &&
                func_004118c0((s32 *)arg0, size) == 0)
                return NULL;
            if (func_00411a70((s32 *)arg0, (s32 *)arg0) == 0)
                return NULL;
        } else {
            array = (u8 **)jtbl_008873E8[0](size, 0x01030409, count);
            *(u8 ***)(arg0 + 0x20) = array;
            if (array != NULL) {
                *(u32 *)(arg0 + 0x24) = size;
                *(u8 ***)(arg0 + 8) = array;
            }
        }
        if (*(u8 ***)(arg0 + 8) != NULL) {
            offset = 0;
            if (*(u32 *)(arg0 + 4) != 0) {
                do {
                    slot = (u8 **)(*(u8 **)(arg0 + 8) + offset);
                    object = *slot;
                    callback = *(void (**)(u8 **))(object + 0x14);
                    if (callback != NULL)
                        callback(slot);
                    release = *(void (**)(u8 *))(object + 0x0C);
                    if (release != NULL)
                        release(object);
                    *(s32 *)(object + 0x3C) -= 1;
                    if (*(s32 *)(object + 0x3C) == 0) {
                        release = *(void (**)(u8 *))(object + 8);
                        if (release != NULL)
                            release(*slot);
                    }
                    offset += 0x28;
                    *(s32 *)(slot + 0x0C) = 0;
                } while (offset / 0x28 < *(u32 *)(arg0 + 4));
            }
            return arg0;
        }
        fail_words = 1;
        fail_value = func_003df590(0x80000013, size);
        func_003df4d0(&fail_words);
        return NULL;
    }
    return arg0;
}
