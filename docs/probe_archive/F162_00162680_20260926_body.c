/* func_00162680 (code1_0016, window 1456B) -- best draft 2026-09-26, 12 words.
 * Measured with tools/probe_variants.py in src/promoted/code1_0016.c:
 * 1456B/1456B, 12 reloc-masked differing words (guarded owner draft: 282).
 * Requires the owner's local extern to read
 *     extern void *func_00478140(u16 arg0, u16 arg1, s32 arg2);
 * instead of (u32, u32, u32): retail passes the u16 type/id straight through
 * (`move $a0,$s2` / `move $a1,$s1`) and the callee masks both of its own
 * parameters with 0xFFFF, so they are u16 (mdlManager.c still defines them as
 * u32 with explicit masks; effModel.c/effHelper.c/evtScript.c/k_fldFBN.c
 * already say u16). With u32 the draft is 46.
 * Structure: slot scan over datGetPartyId, then a switch whose two arms each
 * expand an inline slot-cache helper (retail has two copies; the default arm
 * has type 1 folded). The default arm's `u16 m = member;` block local is
 * load-bearing: retail masks member once into $a1 and reuses it for both the
 * cache compare and the func_00478140 argument (46/44 -> 12; passing member
 * directly re-masks per use, an outer `id = member` lands in $s1: 76).
 * Residual (12): (a) +0x408 the first arm's cache-miss tail branches to the
 * shared `b` at +0x42c instead of straight to the epilogue 0x162c00; (b) in
 * the default arm expansion the slot*8 CSE temp and the entry pointer swap
 * ($s1/$s0 vs retail $s0/$s1: +0x438..+0x540, 11 words).
 * Flat or worse on this body: helper local permutations (12), function-scope
 * `u16 m` in all six positions (12), no entry local (12), explicit `off`
 * local (339), direct returns from the arms (141), inverted helper if (125),
 * default-first switch or if/else forms (300+), (u16)member argument (44),
 * s32 id helper parameter (111). The previous agent's ~370 declaration-order
 * permutations on the older body (q/s/r series) were flat at 46. */
static inline u8 *fldPartyModelGet(s32 slot, u16 type, u16 id)
{
    u8 *entry;
    u8 *obj;
    s32 i;

    entry = D_007F16F0 + slot * 8;
    if (type == *(u16 *)entry && id == *(u16 *)(D_007F16F2 + slot * 8)) {
        obj = *(u8 **)(D_007F16F4 + slot * 8);
    } else {
        obj = NULL;
    }
    if (obj == NULL) {
        obj = func_00478140(type, id, 0);
        if (type == 1) {
            func_0047d140(obj);
        } else {
            func_0047aaa0(obj, 0, (void *)9, (void *)0x163, D_005F13A0, 0);
            func_0047adf0(obj, 0, 0x1F4);
        }
        if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u8 **)(entry + 4) + i * 0xC + 0x28C) |= 1;
            }
            func_004787e0(*(u8 **)(D_007F16F4 + slot * 8));
            *(u8 **)(D_007F16F4 + slot * 8) = NULL;
        }
        *(u8 **)(D_007F16F4 + slot * 8) = obj;
        *(u16 *)entry = *(u16 *)(obj + 0xD4);
        *(u16 *)(D_007F16F2 + slot * 8) = *(u16 *)(*(u8 **)(D_007F16F4 + slot * 8) + 0xD6);
    } else {
        mdlSetColor(obj, &iGpffff9f10);
        func_0047a990(obj);
    }
    return obj;
}

u8 *func_00162680(u16 field, u16 room, s32 member)
{
    s32 i;
    u8 *obj;
    s32 slot;
    u16 type;
    u16 id;

    slot = 0;
    id = 0;
    for (i = 0; i < 3; i++) {
        if (member == datGetPartyId(i)) {
            slot = i + 1;
            break;
        }
    }
    switch (member) {
    case 1:
        if (func_00162510(field, room) == 1) {
            type = 9;
            switch (func_00110d60((s16)func_001060b0())) {
            case 0:
            case 2:
                id = 0x103;
                break;
            case 1:
            case 3:
                id = 0x102;
                break;
            }
        } else if (field == 0x44 && room == 1) {
            type = 9;
            id = 0x100;
        } else if (func_0015a160() != 0) {
            type = 1;
            id = member;
        } else if ((field == 7 && room == 2) || (field == 7 && room == 3)) {
            type = 9;
            switch (func_00110d60((s16)func_001060b0())) {
            case 0:
                id = 0x10B;
                break;
            case 2:
                id = 0x10D;
                break;
            case 1:
                id = 0x10A;
                break;
            case 3:
                id = 0x10C;
                break;
            }
        } else {
            type = 9;
            switch (func_00110d60((s16)func_001060b0())) {
            case 0:
                id = 0x101;
                break;
            case 2:
                id = 0x105;
                break;
            case 1:
                id = 0x100;
                break;
            case 3:
                id = 0x104;
                break;
            }
        }
        obj = fldPartyModelGet(slot, type, id);
        break;
    default: {
        u16 m = member;
        obj = fldPartyModelGet(slot, 1, m);
        break;
    }
    }
    return obj;
}
