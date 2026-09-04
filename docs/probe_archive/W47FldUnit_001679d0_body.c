/*
 * Probe archive for func_001679d0.
 * Best measured candidate: attempt 6, obj 772B, normalized_diff 184.
 * Attempt 7 (explicit pointer/lifetime lever): obj 776B, normalized_diff 193.
 * Earlier floors: attempt 1 nd 203, attempt 2 nd 197, attempt 3 nd 197,
 * attempt 4 nd 199, attempt 5 nd 199.
 * The live source was restored to INCLUDE_ASM after this archive.
 */
s32 func_001679d0(u8 *arg0)
{
    u8 *slot;
    u8 *p;
    u8 *entry;
    u8 *party;
    u8 *party_entry;
    s32 state;
    s32 i;
    s32 inner;
    s32 party_index;
    s32 reset_index;
    s32 state1_index;
    s32 ready;
    s32 kind;
    s32 index;

    p = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)p;
    switch (state) {
    case 0:
        goto state_zero;
    case 1:
        goto state_one;
    case 2:
        goto done_minus;
    default:
        goto done_zero;
    }

state_zero:
    i = 0;
    goto state_zero_check;
state_zero_body:
    ready = 0;
    slot = D_007EF9B0 + i * 0x750;
    if (*(s32 *)(slot + 0x48) != 0 &&
        *(s32 *)(slot + 0x54) != 0) {
        ready = 1;
    }
    if (ready != 0) {
        inner = 0;
        goto state_zero_inner_check;
state_zero_inner_body:
        entry = p + inner * 4 + 4;
        kind = *(u16 *)(slot + 0x728);
        if (*(s32 *)entry == kind) {
            if (kind == 3) {
                func_00165670(slot, 0);
                party = D_007F16F0 + i * 8;
                if (*(s32 *)(party + 4) != 0) {
                    party_index = 0;
                    goto state_zero_party_check;
state_zero_party_body:
                    party_entry = (u8 *)(*(s32 *)(party + 4) +
                                         party_index * 0xC);
                    *(u8 *)(party_entry + 0x28C) |= 1;
                    party_index += 1;
state_zero_party_check:
                    if (party_index < 5) {
                        goto state_zero_party_body;
                    }
                    party = D_007F16F0 + i * 8;
                    func_004787e0(*(s32 *)(party + 4));
                    *(s32 *)(party + 4) = 0;
                    *(u16 *)party = 0;
                    *(u16 *)(party + 2) = 0;
                }
                *(s32 *)(slot + 0x50) =
                    (s32)func_00162680(*(u16 *)iGpffff9db0,
                                       *(u16 *)(iGpffff9db0 + 4),
                                       *(u16 *)(slot + 0x728));
            } else {
                reset_index = 0;
                goto state_zero_reset_check;
state_zero_reset_body:
                func_0047ae10(*(s32 *)(slot + 0x50),
                              (u16)reset_index);
                reset_index += 1;
state_zero_reset_check:
                if (reset_index < 5) {
                    goto state_zero_reset_body;
                }
                func_0047d140(*(s32 *)(slot + 0x50));
            }
            *(s32 *)(p + *(s32 *)(p + 0x14) * 4 + 0x18) = i;
            *(s32 *)(p + 0x14) = *(s32 *)(p + 0x14) + 1;
            goto state_zero_next;
        }
        inner += 1;
state_zero_inner_check:
        if (inner < 4) {
            goto state_zero_inner_body;
        }
    }
state_zero_next:
    i += 1;
state_zero_check:
    if (i < 4) {
        goto state_zero_body;
    }
    *(s32 *)p = *(s32 *)p + 1;
    goto done_zero;

state_one:
    state1_index = 0;
    goto state_one_check;
state_one_body:
    entry = p + state1_index * 4;
    index = *(s32 *)(entry + 0x18);
    slot = D_007EF9B0 + index * 0x750;
    if (*(u16 *)(slot + 0x728) == 3) {
        if (func_004782b0(*(s32 *)(slot + 0x50)) == 0) {
            goto done_zero;
        }
        ready = 0;
        slot = D_007EF9B0 + index * 0x750;
        if (*(s32 *)(slot + 0x48) != 0 &&
            *(s32 *)(slot + 0x54) != 0) {
            ready = 1;
        }
        if (ready == 0) {
            func_00164fa0(index);
        }
    } else {
        reset_index = 0;
        goto state_one_reset_check;
state_one_reset_body:
        slot = D_007EF9B0 + index * 0x750;
        if (func_0047ae90(*(s32 *)(slot + 0x50),
                          (u16)reset_index) == 0) {
            goto done_zero;
        }
        reset_index += 1;
state_one_reset_check:
        if (reset_index < 5) {
            goto state_one_reset_body;
        }
    }
    state1_index += 1;
state_one_check:
    if (state1_index < *(s32 *)(p + 0x14)) {
        goto state_one_body;
    }
    *(s32 *)p = *(s32 *)p + 1;
done_minus:
    return -1;

done_zero:
    return 0;
}
