/*
 * IDA-led safe floor: object 476B / retail window 480B / 35 differing words
 * (relocation-masked). Natural baseline was 49; declaration/address order
 * reduces it to 35. All instructions through the skill phase now match.
 * IDA: docs/ida_headstart/src/promoted/code1_0020.c:1552-1608.
 * Canonical helper contracts replace the previous incompatible declarations.
 * Skills are unsigned: IDs >= 0x8000 must not pass the < 0x1B8 filter, as
 * they incorrectly did in the superseded signed-halfword reconstruction.
 * Retain both flag updates, the optional action before them, all 256 item
 * queries, and the second quantity query after each accepted ID store.
 * Remaining differences: byte-return mask, item-ID/address materialization
 * and resulting offsets. Do not widen the real u8 count-return ABI to match.
 * Native smoke: 2048 cases cover boundary skills, eight accepted skills,
 * disabled lists, flags/actions, query ordering, changing second quantities,
 * ID-store visibility, zero counts, and every untouched work-buffer byte.
 * Production remains INCLUDE_ASM.
 */
void func_00207140(u16 *flags, u8 *work)
{
    extern u8 func_00106600(s16 id);
    extern u16 *func_0010a900(s32 id);
    extern u16 func_0010cf40(u8 *persona, s16 slot);
    extern s32 func_00232aa0(s32 id);
    extern u8 *iGpffffb3b8;
    u8 *action;
    u8 *unit;
    u8 *persona;
    u16 skillSlot;
    u16 skillCount;
    u16 skill;
    u16 itemCount;
    u16 itemSlot;
    u8 *entry;

    if (func_00106330(0x3C) != 0) {
        action = *(u8 **)(*(u8 **)(work + 0x178) + 0x3F0);
        if (action != NULL) {
            func_00202d20((u8 *)flags, *(s16 *)(action + 2), *(s16 *)action);
        }
    }
    *flags |= 4;
    *flags |= 2;
    skillCount = 0;
    unit = *(u8 **)(*(u8 **)(work + 0x178) + 0x30);
    if (unit[0xA2] == 0) {
        persona = (u8 *)func_0010a900(*(u16 *)(unit + 0xA4));
        for (skillSlot = 0; skillSlot < 8; skillSlot++) {
            skill = func_0010cf40(persona, (s16)skillSlot);
            if (skill != 0 && skill < 0x1B8 && (*(u8 *)(skill * 0x28 + iGpffffb3b8 + 1) & 2)) {
                *(u16 *)(work + skillCount * 2 + 0x194) = skill;
                skillCount++;
            }
        }
    }
    *(u16 *)(work + 0x1A4) = skillCount;
    itemCount = 0;
    for (itemSlot = 0; itemSlot < 0x100; itemSlot++) {
        if (func_00106600((s16)(itemSlot + 0x300)) != 0 &&
            func_00232aa0((u16)(itemSlot + 0x300)) != 0) {
            entry = work + itemCount * 4;
            *(u16 *)(entry + 0x1A6) = itemSlot + 0x300;
            entry[0x1A8] = func_00106600((s16)(itemSlot + 0x300));
            itemCount++;
        }
    }
    *(u16 *)(work + 0x5A6) = itemCount;
}
