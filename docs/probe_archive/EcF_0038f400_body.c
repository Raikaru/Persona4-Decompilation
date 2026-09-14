/* Exact func_0038f400 recovery.
 * Owner: src/promoted/code1_0038.c.
 * Object: 396/400 bytes; all executable bytes and seven relocations match.
 * The final retail word is zero alignment after the return delay slot.
 *
 * The allocator result must first enter the advancing cursor, then be copied
 * to the stable result pointer. That dataflow retains the return value for the
 * header-end calculation and reproduces retail's v0/v1/a0 register cycle.
 *
 * The five-word header, low-halfword ID/count stores, unsigned descriptor
 * lengths, two aligned payload regions, and full-width entry count are
 * preserved. No allocation-failure behavior is invented.
 *
 * 216 native cases cover full-width counts beyond 65535, unsigned lengths,
 * every alignment residue, exact payload bytes, untouched padding, and
 * debug/allocate/copy/copy ordering. Valid descriptors and successful
 * low-address allocation only; this is not retail MIPS execution.
 */
extern u8 D_0064F240[];
extern void *func_0043f810(void *dst, const void *src, u32 size);
EffectStateHeader *func_0038f400(const u32 *arg0)
{
    u32 size;
    u32 remainder;
    EffectStateHeader *result;
    u32 cursor;
    u32 string;
    u32 index;
    const u8 *lengths;

    size = 0x14;
    size += arg0[3] * 4;
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[6];
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[2];
    func_0044ea90(D_0064F240, 0x36);
    cursor = (u32)jtbl_008873E8[0](size, 0x40000);
    result = (EffectStateHeader *)cursor;
    cursor += sizeof(*result);
    result->entries = cursor;
    cursor += arg0[3] * 4;
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->strings = cursor;
    cursor += arg0[6];
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->data = cursor;
    result->count = (u16)arg0[3];
    result->id = (u16)arg0[0];
    func_0043f810((void *)result->strings, (const u8 *)arg0 + arg0[5], arg0[6]);
    func_0043f810((void *)result->data, (const u8 *)arg0 + arg0[1], arg0[2]);
    lengths = (const u8 *)arg0 + arg0[4];
    string = result->strings;
    index = 0;
    while (index < arg0[3]) {
        size = index * 4;
        *(u32 *)(result->entries + size) = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}
