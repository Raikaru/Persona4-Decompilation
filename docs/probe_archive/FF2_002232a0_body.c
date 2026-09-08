/* Fresh complete reference for valid retail state; production remains ASM.
 * 1024/1040 bytes versus 1036 executable retail bytes and four zero tail bytes.
 * 26 code and nine table relocations resolved; 778 overlap bytes and ten
 * switch bytes differ; missing suffix includes six nonzero bytes.
 * Captured measurement used the legacy owner getter declaration. Integration
 * requires u32 func_00452560(void *task), s32 callback(void *task), and full
 * provider/callback migration described in docs/matching.md. No equivalence
 * is claimed for the retail corrupted-index uninitialized-register path.
 * This is not a standalone translation unit.
 */
s32 func_002232a0(void *task)
{
    u32 owner;
    u8 *work;
    u8 *persona;
    f32 position[2];
    s32 options[11];

    work = (u8 *)(u32)func_00452560(task);
    owner = *(u32 *)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    func_00460ac0(D_00795F20, work + 8);
    switch (*(s32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = func_0010b6f0();
        *(u8 **)(work + 0x4C) = func_00117780(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0)
            func_0046d730(D_006296D0, 0x2F);
        func_00117580(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        func_0011d100(*(u8 **)(work + 0x4C), position);
        func_0011bb90(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        owner += 0x60;
        while (*(s32 *)(work + 0x3C) < *(s32 *)(work + 0x38)) {
            persona = func_0010ace0((s16)*(s32 *)(work + 0x3C));
            *(s32 *)(persona + 8) = *(s32 *)(owner + *(s32 *)(work + 0x3C) * 4 + 8) + *(s32 *)(persona + 8);
            if (*(u8 *)(owner + *(s32 *)(work + 0x3C) * 0x88 + 0x38) > 0)
                goto show_persona;
            ++*(s32 *)(work + 0x3C);
        }
        goto exhausted;
    show_persona:
        func_0011b480(*(u8 **)(work + 0x4C), 1, persona, 0);
        options[0] = 12;
        options[1] = 0;
        options[2] = 6;
        options[3] = 9;
        options[4] = 10;
        options[5] = 11;
        options[6] = 13;
        options[7] = 14;
        options[8] = 19;
        options[9] = 20;
        options[10] = 21;
        *(u8 **)(work + 0x50) = func_0011f410(task, *(u8 **)(work + 0x4C),
            (u8 *)(owner + *(s32 *)(work + 0x3C) * 0x88 + 0x38),
            func_00455ea0(*(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0), 0, options);
        *(u16 *)work |= 2;
        *(s32 *)(work + 4) = 2;
        break;
    exhausted:
        if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= ~1;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= ~1;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;
    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (!func_0011f560(*(u8 **)(work + 0x50)))
            break;
        func_0011f580(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        if (++*(u16 *)(work + 0x48) >= 45 || (D_008C024E[0] & 0x50) ||
            ((D_008C024C[0] & 0x10) && *(u16 *)(work + 0x48) >= 4)) {
            ++*(s32 *)(work + 0x3C);
            *(s32 *)(work + 4) = 1;
        }
        break;
    case 5:
        if (!func_00353f50(1)) {
            *(u16 *)work &= ~1;
            *(s32 *)(work + 4) = 8;
        }
        break;
    case 6:
        if (!func_0021de60())
            break;
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) || ++*(u16 *)(work + 0x48) >= 5) {
            *(u16 *)work &= ~2;
            return -1;
        }
        break;
    case 8:
        break;
    }
    return 0;
}
