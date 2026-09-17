// func_002411a0 (0x002411a0-0x00241bc0, 2592B) — guarded floor, obj 2532B/window 2592B (60B under; frame -0xA0 vs retail -0x90, extra s7), nd 512 reloc-masked differing words.
// Wins: switch-dispatch (cases 0x200,0x400,0x100,2,4) over the || if-chain (512 vs 563/581); 4-arg s32 signature; u8/s8 table views (lbu/lb + (s16) merge); s16 lvl/bits; single func_00242800 call kept in temp; shared return-1/return-4 tails; float f20 dance (1.0f, *0.5f, *2.0f, (s32)((f32)base*f20)); clamped total; three RpRandom mod-100 checks kept; staged t/ok temps for the 0x206/0x207 and 0x3C-0x3E fallbacks.
// Walls: saved-register rotation (obj arg2=$s6/tmp=$s0/arg3=$s1 vs retail arg2=$s2/tmp=$s6/arg3=$s0) plus one extra saved reg (s7, -0xA0 vs -0x90), cascading into every later color/schedule (fnalign: retail 646 instrs vs obj 631 instrs, leading replace at prologue). Prior corroborated floor reported nd 521 with the same rotation regardless of declaration order, type (s32/u16), or || vs switch form; scoped-reuse did not remove s7. 10 gp-relative table loads (0x28/0x3C/byte*2) — pragma+helper combo not applicable. Production stays ASM.
s32 func_002411a0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3)
{
    s32 idx;
    s32 tmp22;
    s32 lvl;
    s32 bits;
    s32 res;
    s32 base;
    s32 thresh;
    f32 f20;
    u8 *entry;
    u8 kind;
    u16 id16;
    s16 id;
    u8 *tab;
    u16 i;
    s32 found;
    s32 bonus;
    s32 scaled;
    s32 total;

    tmp22 = arg2 & 0xFFFF;
    if (tmp22 >= 0x1B8) {
        func_0046d730(D_00635938, 0x122E);
    }
    switch (arg3 & 0xFFFF) {
    case 0x200:
    case 0x400:
    case 0x100:
    case 2:
    case 4:
        return 1;
    }
    idx = arg2 & 0xFFFF;
    if ((arg0 != 0) && (tmp22 < 0x1B8) && ((iGpffffb3b8[idx * 0x28] & 2) != 0)) {
        if ((*(u16 *)arg0 & 4) != 0) {
            id16 = *(u16 *)(arg0 + 2);
            lvl = (s16)(u8)iGpffffb3c4[id16 * 0x3C + 0x38];
        } else {
            lvl = (s16)func_00106a30((s16)func_00106cd0(*(s16 *)(arg0 + 2), 0));
        }
    } else {
        idx = arg2 & 0xFFFF;
        lvl = *(s8 *)(iGpffffb3b4 + idx * 2);
    }
    if ((s16)lvl >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    bits = 1 << ((s16)lvl + 1);
    if ((bits & 0xE0001) != 0) {
        return 1;
    }
    res = func_00242800(arg1, lvl);
    if (((bits & 2) == 0) && (((bits & 0x40) == 0) || (iGpffffb3b8[idx * 0x28 + 2] != 1))) {
        if ((res & 0x08000000) == 0) {
            return 1;
        }
        return 4;
    }
    entry = iGpffffb3b8 + idx * 0x28;
    if (entry[0x25] == 0) {
        if ((res & 0x08000000) == 0) {
            return 1;
        }
        return 4;
    }
    if ((*(u16 *)arg1 & 0x80) != 0) {
        if ((res & 0x08000000) == 0) {
            return 1;
        }
        return 4;
    }
    if ((*(u16 *)arg0 & 4) == (*(u16 *)arg1 & 4)) {
        if ((res & 0x08000000) == 0) {
            return 1;
        }
        return 4;
    }
    if ((res & 0x08000000) != 0) {
        return 4;
    }
    if (func_00243e30((u16 *)arg1) != 0) {
        return 1;
    }
    base = 0;
    thresh = 0;
    f20 = 1.0f;
    entry = iGpffffb3b8 + idx * 0x28;
    if (entry[0x25] == 0x64) {
        base = 0x64;
        thresh = 0x64;
    }
    kind = entry[2];
    if (kind == 2) {
        return 1;
    }
    if (kind != 1) {
        func_0046d730(D_00635938, 0x12EF);
        return 1;
    }
    if (base == 0) {
        base = func_00244f60(5, arg0, arg1, arg2, 0);
    }
    if ((*(u16 *)arg1 & 4) == 0) {
        if (*(u16 *)(arg1 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        tab = func_001094e0(*(u16 *)(arg1 + 2));
    } else {
        if (*(u16 *)(arg1 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFA8);
        }
        tab = iGpffffb3c4 + *(u16 *)(arg1 + 2) * 0x3C + 0xE;
    }
    found = 0;
    for (i = 0; i < 8; i++) {
        if (*(u16 *)(tab + i * 2) == 0x206) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        if ((*(u16 *)arg1 & 4) == 0) {
            s32 t;
            t = func_00106cd0(*(s16 *)(arg1 + 2), 2) & 0xFFFF;
            if ((t >= 0) && (func_001069a0((s16)t) == 0x206)) {
                found = 1;
            }
        }
    }
    if (found != 0) {
        f20 = 1.0f * 0.5f;
    }
    if ((*(u16 *)arg0 & 4) == 0) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        tab = func_001094e0(*(u16 *)(arg0 + 2));
    } else {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFA8);
        }
        tab = iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0xE;
    }
    found = 0;
    for (i = 0; i < 8; i++) {
        if (*(u16 *)(tab + i * 2) == 0x207) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        if ((*(u16 *)arg0 & 4) == 0) {
            s32 t;
            t = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
            if ((t >= 0) && (func_001069a0((s16)t) == 0x207)) {
                found = 1;
            }
        }
    }
    if (found != 0) {
        f20 = f20 * 2.0f;
    }
    if (tmp22 >= 0x1B8) {
        func_0046d730(D_00635938, 0xF5E);
    }
    bonus = 0;
    if ((iGpffffb3b8[idx * 0x28] & 2) != 0) {
        s32 ok;
        u16 id16_2;
        s16 id_2;
        if ((*(u16 *)arg0 & 4) == 0) {
            id16_2 = *(u16 *)(arg0 + 2);
            if (id16_2 >= 0xB) {
                func_0046d730(D_00635938, 0x23B);
            }
            id_2 = (s16)id16_2;
            if (((func_001069d0(func_00106cd0(id_2, 0)) & 0xFFFF) == 0x3C) || ((func_001069d0(func_00106cd0(id_2, 1)) & 0xFFFF) == 0x3C)) {
                ok = 1;
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        if (ok != 0) {
            bonus = 5;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            id16_2 = *(u16 *)(arg0 + 2);
            if (id16_2 >= 0xB) {
                func_0046d730(D_00635938, 0x23B);
            }
            id_2 = (s16)id16_2;
            if (((func_001069d0(func_00106cd0(id_2, 0)) & 0xFFFF) == 0x3D) || ((func_001069d0(func_00106cd0(id_2, 1)) & 0xFFFF) == 0x3D)) {
                ok = 1;
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        if (ok != 0) {
            bonus += 10;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            id16_2 = *(u16 *)(arg0 + 2);
            if (id16_2 >= 0xB) {
                func_0046d730(D_00635938, 0x23B);
            }
            id_2 = (s16)id16_2;
            if (((func_001069d0(func_00106cd0(id_2, 0)) & 0xFFFF) == 0x3E) || ((func_001069d0(func_00106cd0(id_2, 1)) & 0xFFFF) == 0x3E)) {
                ok = 1;
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        if (ok != 0) {
            bonus += 15;
        }
    }
    if (func_002332a0(arg0, 5) > 0) {
        bonus += 7;
    }
    if (func_002332a0(arg0, 6) > 0) {
        bonus += 15;
    }
    scaled = (s32)((f32)base * f20);
    total = scaled + bonus;
    if (total >= 0x65) {
        total = 0x64;
    } else if (total < 0) {
        total = 0;
    }
    if ((s32)(func_003b7060() % 100) < thresh) {
        return 2;
    }
    if ((s32)(func_003b7060() % 100) < 0) {
        return 2;
    }
    if ((s32)(func_003b7060() % 100) < total) {
        return 2;
    }
    return 1;
}
