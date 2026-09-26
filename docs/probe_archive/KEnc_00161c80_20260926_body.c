/* func_00161c80 (k_encount, window 1184B) -- best draft 2026-09-26.
 * Measured with tools/probe_variants.py in src/Kosaka/k_encount.c: 1184B/1184B,
 * 9 reloc-masked differing words (down from the 243 of KEn80_00161c80_body.c).
 * The whole first scan loop, prologue, gp loads, divu and epilogue match.
 * Residual: the second (selection) loop colours the index and the sign-extended
 * id the other way round -- retail index $s4 / id $s0, b210 index $s0 / id $s4
 * (words at +0x2a4,+0x2b4,+0x2b8,+0x2d8,+0x2dc,+0x2f0,+0x2f8,+0x458,+0x45c).
 * Key levers: signature (s32 field, s32 room, u16 index, u16 mode) -- u16 mode
 * is load-bearing (s32 mode: 237 words), u16 field/room adds andi masks (267);
 * the 10-byte EncEntry typed lookup; opt_loop_invariants on; the per-loop rec
 * and pid locals. Callers (code1_0015.c:140, k_fldUnit.c:188) currently
 * declare (u16, u16, u16, s32); installing this needs them changed to agree.
 * Ruled out on this body (all >= 9): ~700 decl-order permutations of the
 * function and loop-2 block locals (previous agent), inline helpers for the
 * rare-id and on-field scans (19), reuse of i for loop 2 (13), shared
 * function-scope id (22/38), loop-2 id with initializer (12), acc/i2 init
 * order (10), block-scoped i2 (10), *pid reads (114-119), s32 id (118),
 * early return rec (257), acc > rnd (9, tie). */
typedef struct EncEntry {
    u16 id;
    u8 rate2;
    u8 rate3;
    u8 rate4;
    u8 pad5;
    u16 table;
    u16 pad8;
} EncEntry;
#pragma push
#pragma opt_loop_invariants on
u8 *func_00161c80(s32 arg0, s32 arg1, u16 arg2, u16 arg3)
{
    extern s32 func_00106600(s16 id);
    u8 *base;
    u8 *found;
    s32 i;
    s32 total;
    s32 acc;
    s32 i2;
    s32 rnd;

    found = NULL;
    if ((func_0014a230(arg0, arg1) == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        EncEntry *entry = (EncEntry *)iGpffffb41c;
        base = iGpffffb424 + entry[arg2].table * 0x15C;
    } else {
        return NULL;
    }
    if (arg2 == 0) {
        return NULL;
    }
    i = 0;
    total = 0;
    for (; i < 0x1D; i++) {
        u8 *rec = base + i * 0xC;
        s16 *pid = (s16 *)(rec + 2);
        if (*(u16 *)(rec + 2) != 0) {
            s16 id = *(u16 *)(rec + 2);
            s32 hit = 0;
            s32 j;
            for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                if (id == ((s16 *)D_005F1260)[j] && (func_00106600(id) & 0xFF) > 0) {
                    hit = 1;
                    break;
                }
            }
            if (hit == 0 && func_00161bb0(*pid) == 0) {
                s16 id2 = *pid;
                s32 present = 0;
                s32 k;
                for (k = 0; k < 8; k++) {
                    u8 *p = D_007E80A0 + k * 0x168;
                    if (*(s32 *)(p + 0) != 0) {
                        u8 *q = *(u8 **)(p + 0x160);
                        if (q != NULL && *(s32 *)(p + 8) != 1 && id2 == *(u16 *)(q + 2)) {
                            present = 1;
                            break;
                        }
                    }
                }
                if (present == 0) {
                    if (*(u8 *)(rec + 7) & 1) {
                        if (arg3 == 1 || arg3 == 2) {
                            total += *(u16 *)(rec + 0);
                        }
                    } else if (arg3 == 0 || arg3 == 2) {
                        total += *(u16 *)(rec + 0);
                    }
                }
            }
        }
    }
    if (total == 0) {
        func_0046d730(D_005F12C8, 0x166);
    }
    rnd = RpRandom() % total;
    i2 = 0;
    acc = 0;
    for (; i2 < 0x1D; i2++) {
        s16 *pid;
        s32 j;
        u8 *rec;
        s16 id;
        s32 hit;
        rec = base + i2 * 0xC;
        pid = (s16 *)(rec + 2);
        if (*(u16 *)(rec + 2) != 0) {
            id = *(u16 *)(rec + 2);
            hit = 0;
            for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                if (id == ((s16 *)D_005F1260)[j] && (func_00106600(id) & 0xFF) > 0) {
                    hit = 1;
                    break;
                }
            }
            if (hit == 0 && func_00161bb0(*pid) == 0) {
                s16 id2 = *pid;
                s32 present = 0;
                s32 k;
                for (k = 0; k < 8; k++) {
                    u8 *p = D_007E80A0 + k * 0x168;
                    if (*(s32 *)(p + 0) != 0) {
                        u8 *q = *(u8 **)(p + 0x160);
                        if (q != NULL && *(s32 *)(p + 8) != 1 && id2 == *(u16 *)(q + 2)) {
                            present = 1;
                            break;
                        }
                    }
                }
                if (present == 0) {
                    if (*(u8 *)(rec + 7) & 1) {
                        if (arg3 == 1 || arg3 == 2) {
                            acc += *(u16 *)(rec + 0);
                        }
                    } else if (arg3 == 0 || arg3 == 2) {
                        acc += *(u16 *)(rec + 0);
                    }
                    if (rnd < acc) {
                        found = rec;
                        break;
                    }
                }
            }
        }
    }
    return found;
}
#pragma pop
