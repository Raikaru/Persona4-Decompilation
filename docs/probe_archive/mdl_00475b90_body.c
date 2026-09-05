// Lane mdl best body for func_00475b90 (attempted, did not close).
// Object 304B / window 320B, normalized_diff 89 (best from this session).
// Best fndiff 34 differing words (reloc-masked); branch-placement floor
// persists: mwcc b210 inlines the setup block under a negated skip
// (beq $s1,$v0,join) instead of retail's out-of-line bne/b setup block.
// Also the addiu $a2,$sp,0x58 for func_003e9af0's third arg is scheduled
// before a0/a1 materialisation; 00475B10 callback and data[2] layout
// otherwise reproduce retail's stack and call sequence.
// Levers tried: s32 count + u16 i (fixed loop u16 re-mask), u32 masked_idx,
// s32 data[2] for the callback data[0]/data[1] pair, goto do_setup/no_setup
// branch structure, opt_rebuildconditionals off, opt_propagation off,
// s32-vs-void* comparison, and goto label ordering. Replayed after the
// frame-getter ABI repair: still 34 words. Uses the source unit's canonical
// s32 func_00397470(u8*) declaration; the obsolete local prototype and
// unbalanced trailing pragma pop are removed.
// FUN_00475B90
int func_00475b90(void* buf, void* v, u32 idx, void* obj)
{
    s32 count;
    u16 i;
    u32 masked_idx;
    void* entry;
    u8* clump;
    s32 field44;
    s32 data[2];

    count = (s32)*(u16*)v;
    i = 0;
    masked_idx = idx & 0xFFFF;
    while ((s32)(u16)i < count) {
        entry = (void*)((u8*)*(void**)((u8*)v + 4) + (u32)(u16)i * 0x50);
        if (masked_idx == *(s32*)((u8*)entry + 0x40)) {
            break;
        }
        i++;
    }
    if ((s32)(u16)i == count) {
        return 0;
    }

    entry = (void*)((u8*)*(void**)((u8*)v + 4) + (u32)(u16)i * 0x50);
    field44 = *(s32*)((u8*)entry + 0x44);
    clump = *(u8**)((u8*)obj + 4);

    if (field44 != func_00397470(clump)) {
        goto do_setup;
    }
    goto no_setup;
do_setup:
    data[1] = field44;
    data[0] = 0;
    func_003e9af0(clump, (s32 (*)(u8*, s32))func_00475b10, (s32)&data[0]);
    clump = (u8*)data[0];
no_setup:
    if (clump == 0) {
        return 0;
    }

    func_003e05f0(buf, entry, func_003e9700(clump));
    return 1;
}
