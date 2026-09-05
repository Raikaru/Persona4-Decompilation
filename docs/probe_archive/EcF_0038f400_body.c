/* MWCCPS2: object 396B / retail window 400B / 17 differing words.
 * Sixteen emitted-word differences remain at 0x94 and 0xA4-0xE4;
 * the seventeenth is the absent zero-tail word at 0x18C.
 * Allocation setup, copies, full unsigned count loop and epilogue match.
 * Header-end formation uses s0 rather than v0; cursor/remainder/temporary
 * registers are a0/v1/v0 rather than retail v0/a0/v1.
 * Named descriptor fields, bounded cursor scope, separate alignment
 * remainder, split region cursors and a table-byte extent all retain 17.
 * A pointer-typed runtime header gives 23; reusing size as cursor gives 98.
 * IDA's inline alignment expressions and combined header/table extent also
 * retain 17 words; no improvement over this floor.
 * Preserve the five-word header, low-halfword stored ID/count, full source
 * count, copy lengths and absence of an invented allocation-failure check.
 * These are bounded measurements, not proof that other safe forms cannot match.
 */
extern u8 D_0064F240[];
extern void *func_0043f810(void *dst, const void *src, u32 size);
u32 func_0038f400(const u32 *arg0)
{
    u32 size;
    u32 remainder;
    u32 result;
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
    result = (u32)jtbl_008873E8[0](size, 0x40000);
    *(u32 *)(result + 8) = result + 0x14;
    cursor = result + 0x14;
    cursor += arg0[3] * 4;
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    *(u32 *)(result + 0xC) = cursor;
    cursor += arg0[6];
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    *(u32 *)(result + 0x10) = cursor;
    *(u32 *)(result + 4) = (u16)arg0[3];
    *(u32 *)result = (u16)arg0[0];
    func_0043f810((void *)*(u32 *)(result + 0xC), (const u8 *)arg0 + arg0[5], arg0[6]);
    func_0043f810((void *)*(u32 *)(result + 0x10), (const u8 *)arg0 + arg0[1], arg0[2]);
    lengths = (const u8 *)arg0 + arg0[4];
    string = *(u32 *)(result + 0xC);
    index = 0;
    while (index < arg0[3]) {
        size = index * 4;
        *(u32 *)(*(u32 *)(result + 8) + size) = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}
