/* func_00162680 (code1_0016, window 1456B) -- best draft 2026-09-26, 1 word.
 * Supersedes F162_00162680_20260926_body.c (12 words). Needs the owner's
 *     extern void *func_00478140(u16 arg0, u16 arg1, s32 arg2);
 * (the callee masks its own two parameters; see the older note).
 * New lever: the slot-cache lookup is its own static inline helper returning
 * the cached object or NULL, called before `entry` is computed; that fixes the
 * default arm's slot*8/entry register swap (12 -> 1).
 * Residual (+0x408): the first arm's cache-miss tail branches to the arm's
 * shared `b 0x162c00` at +0x42c instead of straight to 0x162c00 (retail
 * chains it). Flat or worse: early return of the hit path in the helper (1),
 * inverted hit-first if (120), `return helper()` from the arms (141). */
static inline u8 *fldPartyModelCached(s32 slot, u16 type, u16 id)
{
    if (type == *(u16 *)(D_007F16F0 + slot * 8) && id == *(u16 *)(D_007F16F2 + slot * 8)) {
        return *(u8 **)(D_007F16F4 + slot * 8);
    }
    return NULL;
}

static inline u8 *fldPartyModelGet(s32 slot, u16 type, u16 id)
{
    u8 *entry;
    u8 *obj;
    s32 i;

    obj = fldPartyModelCached(slot, type, id);
    entry = D_007F16F0 + slot * 8;
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
