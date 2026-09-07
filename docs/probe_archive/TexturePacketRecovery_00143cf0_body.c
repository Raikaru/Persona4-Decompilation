/* Fully relocated exact:672 executable bytes,11 resolved calls,no tail.
 * Saved-Y lifetime, ordinary strides and separate address additions recover
 * retail evaluation order. Source is a numeric u32 address, not a pointer:
 * signed source+=stride traps at the signed boundary under UBSan; this
 * same-width unsigned form remains exact and passes137 native i386 cases
 * at each O0/O2. Real packed helpers and an independent serializer check all
 * 8192 fixture bytes, including untouched upper halves of DMA tag slots.
 * No MIPS/GS/DMA execution or actual output-buffer capacity claim. With
 * N=max(width>>4,0), extent is0x48+0x60*N and64+80*N bytes are written.
 * Invalid/misaligned pointers, insufficient buffers and signed dimension,
 * product or coordinate overflow are outside the exercised domain.
 * Requires existing h_malloc.c helper declarations; eleven-argument ABI
 * and wrapper are unchanged. */
void func_00143cf0(u32 arg0, u8* arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp8, s32 arg_sp10)
{
    s32 columns = arg6 >> 4;
    s32 rows = arg7 >> 4;
    s32 width;
    u8* packet;
    s32 i;
    s32 count;
    u32 source;
    s32 savedY;
    s32 last;
    s32 stride;
    s32 gapStride;
    savedY = arg5;
    func_00143f90((u64*)arg1, 0, 0, 0, 1, 0, 3);
    func_00144000((u32*)(arg1 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
    width = ((arg6 + 63) / 64) * 64;
    func_00144060((u32*)(arg1 + 0x20), arg0, width / 64, 0);
    func_00144140((u32*)(arg1 + 0x30), 16, rows * 16);
    packet = arg1 + 0x40;
    source = arg2 + (arg_sp0 >> 4) * (arg3 * (rows + (arg_sp10 >> 4)));
    source += arg3 * (arg_sp8 >> 4);
    i = 0;
    count = (rows * 1024) / 16;
    stride = arg3 * rows;
    gapStride = arg3 * (arg_sp10 >> 4);
    while (i < columns) {
        last = (i == columns - 1) ? 1 : 0;
        func_00143f90((u64*)packet, 0, 0, 0, 1, 0, 4);
        func_00144000((u32*)(packet + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
        func_001440d0((u32*)(packet + 0x20), 0, arg4 + i * 16, savedY);
        func_001441a0((u32*)(packet + 0x30), 0);
        func_00144000((u32*)(packet + 0x40), 0, 0, 2, 0, 0, last, count);
        func_00143f90((u64*)(packet + 0x50), 0, source & 0x0fffffff, 0, 3, 0, count);
        packet += 0x60;
        source += stride;
        source += gapStride;
        i++;
    }
    func_00143f90((u64*)packet, 0, 0, 0, 7, 0, 0);
}
