/* IDA: docs/ida_headstart/src/promoted/code1_001d.c:1174-1216;
   container builder: the same file, lines 772-869.
   Replay: python tools/probe_archive.py docs/probe_archive/R1EE_001d8cb0_body.c src/promoted/code1_001d.c
   Defined C floor: 312B/320B, 18 reloc-masked differing words: 12 key-loop
   register words, four first-entry comparison/branch words, two zero-tail words.
   The old 14-word draft evaluated an uninitialized best distance before its
   first-entry flag. Guarding that comparison preserves nearest-selection
   behavior without that undefined read. Do not revive the lower unsafe score.
   The source objects are two 12-byte RwV3d values and a 12-pointer selection
   table followed by its 64-bit key, count, selected index, and flags; no fourth
   vector lane is needed. Production remains ASM. */
// FUN_001D8CB0
#pragma push
#pragma opt_loop_invariants on
s32 func_001d8cb0(u8 *arg0, u8 *arg1)
{
    struct DistanceSelection {
        u8 *entries[12];
        u64 key;
        u16 count;
        u16 selected;
        u8 flags;
    };
    struct RwV3d {
        f32 x;
        f32 y;
        f32 z;
    };
    struct BtlUnit;
    extern void func_001958f0(struct BtlUnit *unit, struct RwV3d *dst);
    extern f32 func_001ec250(const struct RwV3d *first, const struct RwV3d *second);
    struct RwV3d sp60;
    struct RwV3d sp50;
    f32 temp_f0;
    f32 var_f20;
    struct DistanceSelection *selection = (struct DistanceSelection *)arg1;
    s32 first;
    s32 index;
    selection->selected = 0;
    {
        u64 key;
        s32 key_index;
        key = selection->key;
        if (key != 0) {
            key_index = 0;
            while ((u16)key_index < selection->count) {
                if (key == *(u64 *)selection->entries[key_index & 0xFFFF]) {
                    selection->selected = (u16)key_index;
                    return 1;
                }
                key_index = (key_index + 1) & 0xFFFF;
            }
        }
    }
    if (arg0 == NULL)
        goto return_one;
    first = 1;
    func_001958f0((struct BtlUnit *)(u32)*(u32 *)(arg0 + 0x30), &sp60);
    index = 0;
    goto distance_test;
distance_loop:
    func_001958f0(
        (struct BtlUnit *)(u32)*(u32 *)(selection->entries[index & 0xFFFF] + 0x30),
        &sp50);
    temp_f0 = func_001ec250(&sp60, &sp50);
    if ((first != 0) || (temp_f0 < var_f20)) {
        selection->selected = (u16)index;
        var_f20 = temp_f0;
        first = 0;
    }
    index = (index + 1) & 0xFFFF;
distance_test:
    if ((u16)index < selection->count)
        goto distance_loop;
return_one:
    return 1;
}
#pragma pop
