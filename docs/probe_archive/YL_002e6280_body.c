// func_002e6280 (0x002e6280-0x002e6630, 944B) — guarded floor @183fndiff/888B (56B under).
// Wins: entry/e38 recompute (saved relief, -13); switch jump-tables; (s16)i extends; u16 counters;
// 2e5960/2b2cb0/311d00/311d60/311e40/2e48a0/43f9c8/10cad0 calls; GPREL relocs.
// Walls: s-count (mine s5/s7 vs retail s6/fp + frame -0xC0 vs -0xB0; k-decl-first neutral;
//   recompute more neutral; lookahead-absent; prior nd-73 same s-rotation/spill floor with s7-vs-s6,
//   fp-spill, v1-flag details); j-loop fp-spill; sq-vs-sw spA0; (s8)-extend pair.
// Prior attempt (guard note, nd 73 @936B, no archive) hit the same wall. Production stays ASM.
void func_002e6280(s8 arg0, u8 *arg1, s8 arg2)
{
    u8 **slotp;
    s16 cnt;
    s16 i;
    u16 j;
    u16 k;
    s16 found;
    u8 *q;
    s16 h8;
    u32 sw1;
    u32 sw2;
    u8 *dst1;
    u8 *dst2;
    s32 spA0;
    u8 *gp_tbl;

    slotp = &D_00882F70[(s8)arg0];
    if (*slotp == NULL) {
        return;
    }
    gp_tbl = iGpffffb3d4;
    func_002e5960(arg0);
    spA0 = (s16)func_002b2cb0((s16)arg2, 3, 99, 1, 1);
    i = 0;
    while (((i & 0xFFFF)) < 192) {
        {
            u8 *t = *(u8 **)(gp_tbl + i * 14);
            if (*(t + 2) == 1 && (*(t) & 8) == 0) {
                u16 id = (u16)i;
                if (func_00311d00(id) != 0 && func_00311d60(id) != 0) {
                    found = 0;
                    j = 0;
                    while (((j & 0xFFFF)) < 13) {
                        if (id == *(u16 *)(arg1 + (j & 0xFFFF) * 2)) {
                            found = 1;
                            break;
                        }
                        j = (j + 1) & 0xFFFF;
                    }
                    if (found == 0) {
                        if (*slotp != NULL) {
                            k = 0;
                            found = 0;
                            while (((s16)k) < *(s32 *)(*(u8 **)(*slotp + 56) + 8)) {
                                if (i == *(s16 *)(func_002e48a0(arg0, k) + 2)) {
                                    found = 1;
                                    break;
                                }
                                k = (((s16)k + 1) & 0xFFFF);
                            }
                        }
                        if (found == 0 && func_00311e40(id) == 0 && spA0 >= *(t + 3)) {
                            h8 = *(s16 *)(*(u8 **)(*slotp + 56) + 8);
                            q = *(u8 **)(*slotp + 56);
                            sw1 = *(u32 *)(q + 4);
                            switch (sw1) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                            default:
                                dst1 = q + (h8 * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                dst1 = q + (h8 * 48) + 164;
                                break;
                            }
                            func_0043f9c8(dst1, 0, 48);
                            h8 = *(s16 *)(*(u8 **)(*slotp + 56) + 8);
                            q = *(u8 **)(*slotp + 56);
                            sw2 = *(u32 *)(q + 4);
                            switch (sw2) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                            default:
                                dst2 = q + (h8 * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                dst2 = q + (h8 * 48) + 164;
                                break;
                            }
                            func_0010cad0(dst2, id);
                            *(s16 *)(*(u8 **)(*slotp + 56) + 8) = h8 + 1;
                        }
                    }
                }
            }
        }
        i = (((s16)i + 1) & 0xFFFF);
    }
}
