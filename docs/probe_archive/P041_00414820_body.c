/* object 312B/window 272B, normalized_diff 252, differing offsets 0x000-0x134 (74 differing words; object oversized); classification: MWCC candidate with wrong frame/statement shape. Retail prologue: addiu $sp,-80; sd $ra,48($sp); sq $s2,32($sp), sq $s1,16($sp), sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; allocator and error helpers were block-scoped with typed declarations. */
// FUN_00414820
s32 *func_00414820(u8 **arg0)
{
    extern u8 *(*D_008873F0)(u8 *, u32, u32);
    extern s32 func_003df590(s32, ...);
    extern void func_003df4d0(s32 *);
    s32 *array;
    s32 *new_array;
    u8 *cursor;
    u32 count;
    u32 capacity;
    u32 new_capacity;
    s32 fail_words[2];

    count = *(u32 *)((u8 *)arg0 + 0x14);
    capacity = *(u32 *)((u8 *)arg0 + 0x10);
    array = *(s32 **)((u8 *)arg0 + 0xC);
    if (count >= capacity) {
        new_capacity = capacity + 0x20;
        *(u32 *)((u8 *)arg0 + 0x10) = new_capacity;
        new_array = (s32 *)D_008873F0((u8 *)array, new_capacity * 8, 0x01030409);
        if (new_array != NULL) {
            if ((new_array != array) && (count != 0)) {
                cursor = (u8 *)new_array;
                do {
                    count -= 1;
                    *(s32 **)(*(u8 **)(cursor + 4) + 0xC) = (s32 *)cursor;
                    cursor += 8;
                } while (count != 0);
            }
            array = new_array;
            *(s32 **)((u8 *)arg0 + 0xC) = array;
        } else {
            fail_words[0] = 1;
            fail_words[1] = func_003df590(0x80000013, new_capacity * 8);
            func_003df4d0(fail_words);
            *(u32 *)((u8 *)arg0 + 0x10) = new_capacity - 0x20;
        }
    }
    if (array != NULL) {
        count = *(u32 *)((u8 *)arg0 + 0x14);
        *(u32 *)((u8 *)arg0 + 0x14) = count + 1;
        array += count * 2;
    }
    return array;
}
