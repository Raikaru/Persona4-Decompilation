/* MWCCPS2: object 396B / retail window 400B / 17 differing words.
 * Sixteen emitted-word differences remain at 0x94 and 0xA4-0xE4;
 * the seventeenth is the absent zero-tail word at 0x18C.
 * Allocation setup, copies, full unsigned count loop and epilogue match.
 * Header-end formation uses s0 rather than v0; cursor/remainder/temporary
 * registers are a0/v1/v0 rather than retail v0/a0/v1.
 * Named descriptor fields, bounded cursor scope, separate alignment
 * remainder, split region cursors and a table-byte extent all retain 17.
 * An earlier pointer-typed header variant gave 23; reusing size as cursor gave 98.
 * IDA's inline alignment expressions and combined header/table extent also
 * retain 17 words; no improvement over this floor.
 * Further probes: an inline alignment helper for cursor stages retains 17;
 * using it for all four stages regresses to 24. A separate allocation
 * result, byte-sized remainder, byte-pointer cursor, and typed allocation
 * plus cursor all retain 17. No source promotion follows these ties.
 * Preserve the five-word header, low-halfword stored ID/count, full source
 * count, copy lengths and absence of an invented allocation-failure check.
 * These are bounded measurements, not proof that other safe forms cannot match.
 * The current candidate returns the owned allocation through a pointer and
 * names the five-word header without changing the sixteen-word code floor.
 * 216 native cases cover full-width counts beyond 65535, unsigned lengths,
 * all alignment residues, exact payload bytes, untouched padding and
 * debug/allocate/copy/copy ordering. Valid descriptors and successful
 * low-address allocation only; this is not retail MIPS execution.
 * Retail identifies ed_staff.c: the owner contains ending-staff text/control
 * data. Allocation argument 0x40000 is rwMEMHINTDUR_GLOBAL, not alignment.
 * A three-boundary layout record and inline region initializer tie this
 * floor; publishing/aligning header boundaries in place regresses to 408B.
 * All seven relocations resolve and all 77 existing owner C matches survive.
 * The adjacent release wrapper now explicitly forwards its allocation;
 * promotion here still requires the canonical pointer-return caller API.
 */
typedef struct { u32 id, count, entries, strings, data; } EffectStateHeader;
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
    result = (EffectStateHeader *)jtbl_008873E8[0](size, 0x40000);
    result->entries = (u32)(result + 1);
    cursor = (u32)(result + 1);
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
