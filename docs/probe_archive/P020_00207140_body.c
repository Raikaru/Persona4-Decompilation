/*
 * IDA-led safe floor: object 476B / retail window 480B. There are 34
 * relocation-masked emitted word differences (115 bytes), or 36 after
 * resolving all relocations. fndiff reports 35 including the omitted
 * four-byte zero tail. The first residual is +0x130, in the item phase.
 * IDA: docs/ida_headstart/src/promoted/code1_0020.c:1552-1608.
 * Typed item records tie the previous raw-address floor; retaining a live
 * output-record pointer grows the body to 480B. All 115 existing MATCH
 * bodies in the owner remain exact.
 * Skills are unsigned: IDs >= 0x8000 must not pass the < 0x1B8 filter.
 * Retain both flag stores, action-before-flags ordering, all 256 first item
 * queries, and each accepted ID store before its second quantity query.
 * The latter may mutate the ID, quantity, padding or other work bytes:
 * write only the quantity afterwards, never a cached complete record.
 * Remaining differences: the genuine u8 return mask and item ID/address
 * scheduling. Do not widen the count-return ABI to remove its mask.
 * Native typed-record consumer: 384 cases / 98,304 first item queries,
 * Clang ASan/UBSan/function sanitizer. Covers all eight accepted skills,
 * skill-flag rejection, all 256 accepted items, unsigned skill boundaries,
 * disabled lists, actions, changing second quantities, observable callback
 * mutations and every untouched byte of the 0x600-byte work buffer.
 * The earlier raw-address version separately passed 2,048 cases.
 * iGpffffb3b8 is 0x007644A8 (GP 0x007690F0, displacement -0x4C48).
 * Production remains INCLUDE_ASM; typed layout is not a promotion.
 */
extern u8 func_00106600(s16 id);
extern u16 *func_0010a900(s32 id);
extern u16 func_0010cf40(u8 *persona, s16 slot);
extern s32 func_00232aa0(s32 id);
extern u8 *iGpffffb3b8;

typedef struct {
    u16 id;
    u8 quantity;
    u8 reserved;
} BattleListItem;

typedef struct {
    u8 prefix[0x194];
    u16 skills[8];
    u16 skillCount;
    BattleListItem items[256];
    u16 itemCount;
} BattleListWork;

void func_00207140(u16 *flags, u8 *work)
{
    u8 *action;
    u8 *unit;
    u8 *persona;
    u16 skillSlot;
    u16 skillCount;
    u16 skill;
    u16 itemCount;
    u16 itemSlot;

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
            ((BattleListWork *)work)->items[itemCount].id = itemSlot + 0x300;
            ((BattleListWork *)work)->items[itemCount].quantity = func_00106600((s16)(itemSlot + 0x300));
            itemCount++;
        }
    }
    *(u16 *)(work + 0x5A6) = itemCount;
}
