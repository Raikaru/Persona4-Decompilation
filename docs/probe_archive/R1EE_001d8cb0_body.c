/* IDA: docs/ida_headstart/src/promoted/code1_001d.c:1174-1216;
   container builder: the same file, lines 772-869.
   Replay: python tools/probe_archive.py docs/probe_archive/R1EE_001d8cb0_body.c src/promoted/code1_001d.c
   Defined C floor: 312B/320B, six reloc-masked differing words: four
   first-entry comparison/branch words and two zero-tail words. A typed action
   table and natural u16 key induction close all twelve key-loop differences.
   Action prefix: src/Battle/btlAction.c, uid at +0 and unit at +0x30.
   The old draft evaluated an uninitialized best distance before its first-entry
   flag. Keep the defined short-circuit guard; do not revive that unsafe order.
   The source objects are two 12-byte RwV3d values and a 12-pointer selection
   table followed by its 64-bit key, count, selected index, and flags; no fourth
   vector lane is needed. Production remains ASM. */
/* Fresh guard-shaping measurements: baseline and an equivalent reject/advance
   guard both retain 312B/nd11 (four executable words). A conditional first
   entry gives 340B/nd105; a guarded boolean union gives 344B/nd115; splitting
   first-entry/update branches gives 332B/nd101. Propagation-off gives
   324B/nd241, while common-subexpression elimination off ties 312B/nd11.
   All have three call relocations. No safe source shape here moves the
   distance comparison before the first-entry test; the defined guard stays. */
// FUN_001D8CB0
#pragma push
#pragma opt_loop_invariants on
s32 func_001d8cb0(u8 *arg0, u8 *arg1)
{
    struct BtlUnit;
    struct BtlAction {
        u64 uid;
        u8 unknown08[4];
        u16 currState;
        u16 pendingState;
        u16 oldState;
        u16 pendingStateTimer;
        u16 state;
        u16 unknown16;
        u16 unknown18;
        u16 unknown1a;
        u32 stateTimer;
        u8 unknown20[0x10];
        struct BtlUnit *unit;
    };
    struct DistanceSelection {
        struct BtlAction *entries[12];
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
        u16 key_index;
        key = selection->key;
        if (key != 0) {
            key_index = 0;
            while (key_index < selection->count) {
                if (key == selection->entries[key_index]->uid) {
                    selection->selected = key_index;
                    return 1;
                }
                key_index++;
            }
        }
    }
    if (arg0 == NULL)
        goto return_one;
    first = 1;
    func_001958f0(((struct BtlAction *)arg0)->unit, &sp60);
    index = 0;
    goto distance_test;
distance_loop:
    func_001958f0(selection->entries[index & 0xFFFF]->unit, &sp50);
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
