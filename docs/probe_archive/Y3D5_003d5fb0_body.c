/* Archived best body for func_003d5fb0: object 76B / retail window 96B / current normalized_diff 24 under schedule-on (stale prior header said nd 15); schedule-off remeasurement is object 92B / nd 47. Current differing word offsets under the best schedule-on body: 36,40,44,48,52,56,60,64,68,72,76,80 (fndiff reports 15 reloc-masked differing words). Retail offsets 76 and 80 are nonzero jr/addiu epilogue words; only bytes after offset 84 are zero padding, so the tail-zero shortcut is ruled out. Casts written: s32 allocator result and field stores, direct folded (u8*)base+0xNN accesses, s32 return of base. Levers ruled out: corrected two-argument func_003df5d0 block extern; schedule-off (obj92/nd47); post-store field reload spelling; integer-domain address spelling; signed/unsigned store split; opt_propagation off; opt_common_subs off; combined propagation/common-subs; named field pointer; named reload local; switch dispatch spellings (case 0, case 1, boolean switch, default case); ordinary volatile/asm; narrow u8/u16 reload locals and u8/u16 result staging. Best body still has the store/reload ordering plus branch/control-flow layout residual: retail emits sw field, lw field, bnez positive out-of-line, then b/move-zero/sw/move-self epilogue, while this C body lets MWCC hoist the conditional and emits the shorter inline branch. */
s32 func_003d5fb0(u8 *arg0) {
    extern s32 func_003df5d0(s32 arg0, s32 arg1);
    u8 *self;

    self = arg0;
    *(s32 *)(self + 0x10) =
        func_003df5d0(4, *(s32 *)(self + 4) | 0x40000);
    if (*(s32 *)(arg0 + 0x10) == 0) {
        return 0;
    }
    *(s32 *)(self + 0x14) = 0;
    return (s32)self;
}
