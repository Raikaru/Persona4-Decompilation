/* object 300B vs window 288B, normalized_diff 212, differing offsets first reported 0x00,0x04,0x06-0x08,0x0a-0x0c,0x0e-0x10,0x12,0x14,0x16-0x18; classification oversized candidate/different function; ruled out further reordering after automatic archive threshold. */
/* Candidate attempted the mixed-ABI helper signature (pointer, f32, integer, integer, byte buffer, integer), explicit 4-byte buffer zeroing, and sparse 15-word work aggregate. */

u8 **func_003d76d0(u8 *arg0)
{
    extern u8 **func_003d7b40(u8 *arg0, f32 factor, s32 arg1, s32 arg2,
                              s8 *buffer, s32 mode);
    extern void func_003d65e0(u8 *arg0, u8 *arg1, s32 arg2, f32 factor,
                              s32 *work);
    s8 bytes[4];
    s32 work[15];
    s32 count;
    s8 *byte_ptr;
    u8 **result;
    u8 *header;
    u8 *base;
    u8 *end;

    count = 4;
    byte_ptr = &bytes[0];
    if (byte_ptr != NULL) {
        do {
            *byte_ptr = 0;
            count -= 1;
            byte_ptr += 1;
        } while (count != 0);
    }
    result = func_003d7b40(arg0, 1.0f, 1, 2, &bytes[0], 0);
    if (result != NULL) {
        header = *(u8 **)result;
        base = *(u8 **)((u8 *)result + 0x10);
        work[3] |= 0x20003;
        work[10] = 0x3F800000;
        work[5] = 0x3F800000;
        work[0] = 0x3F800000;
        work[4] = 0;
        work[2] = 0;
        work[1] = 0;
        work[9] = 0;
        work[8] = 0;
        work[6] = 0;
        work[14] = 0;
        work[13] = 0;
        work[12] = 0;
        end = base + *(u32 *)(header + 8);
        func_003d65e0((u8 *)result, base, 0, 0.0f, &work[0]);
        func_003d65e0((u8 *)result, end, (s32)base, 1.0f, &work[0]);
        return result;
    }
    return NULL;
}
