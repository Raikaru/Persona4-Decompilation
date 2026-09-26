/* func_00162680 (code1_0016, window 1456B) -- 2026-09-26: byte-exact (0 words)
 * ONLY with the owner's local extern changed to
 *     extern void *func_00478140(u16 arg0, u16 arg1, s32 arg2);
 * which is why it is NOT installed. With the tree's (u32, u32, u32) prototype
 * (matching the mdlManager.c definition) the same body is 74 words: every u16
 * type/id argument gains an `andi 0xffff`.
 *
 * Why the prototype cannot simply change: the definition's retail code keeps
 * both parameters raw, masks them only for the D_00922BE0/id lookup, and
 * passes them unmasked to func_0047d110/func_004779b0/func_0047d0e0. A u16
 * definition (prototype or K&R) re-masks them for those unprototyped calls
 * (verified: func_00478140 MATCH -> MISMATCH). k_fldUnit.c func_001658b0
 * passes a u32 `modelCode` raw and also mismatches under a u16 prototype.
 * Making it consistent would need u16-forwarding prototypes for the
 * code1_0047.c trampolines func_0047d110/func_0047d0e0 (currently void(void)
 * wrappers around iGpffffbb34/iGpffffbb30), a u16 definition in mdlManager.c,
 * and a u16 modelCode in k_fldUnit.c: a cross-owner contract change left for
 * the owners.
 *
 * Shape levers found here: the slot-cache lookup as a static inline helper
 * returning the object or NULL (fixes the default arm's slot*8/entry swap);
 * both switch arms carry their own copy of the refresh code with block-local
 * `entry` and loop counter (an inline helper for it leaves the first copy's
 * miss path jumping to the arm's `break`); the default arm's `u16 m = member`.
 */
static inline u8 *fldPartyModelCached(s32 slot, u16 type, u16 id)
{
    if (type == *(u16 *)(D_007F16F0 + slot * 8) && id == *(u16 *)(D_007F16F2 + slot * 8)) {
        return *(u8 **)(D_007F16F4 + slot * 8);
    }
    return NULL;
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
    case 1: {
        u8 *entry;

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
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
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
        break;
    }
    default: {
        u16 m = member;
        u8 *entry;

        obj = fldPartyModelCached(slot, 1, m);
        entry = D_007F16F0 + slot * 8;
        if (obj == NULL) {
            obj = func_00478140(1, m, 0);
            func_0047d140(obj);
            if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
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
        break;
    }
    }
    return obj;
}
