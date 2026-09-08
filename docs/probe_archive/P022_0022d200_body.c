/* MATCH: promoted to src/promoted/code1_0022.c.
 * Object/window=824/832 bytes; normalized_diff=0;
 * fully_resolved_code_relocations=1; unmasked_byte_diff=0.
 * Eight trailing retail bytes are zero alignment. No pragma is required.
 *
 * ABI: s32 resource handle from one action pointer. Global bit 0x200000,
 * action bit 1 and actor genus 1 gate selection. Unit ID and skill are u16.
 * Default slot is global+0xBE0; special skill groups use +0xBF0. Only
 * IDs 0x106/0x10F with skill 0x172 select +0xBF4. A zero chosen handle
 * is returned unchanged, not replaced inside the selector.
 * The ordered outer switch and separate final-case default return preserve
 * retail's comparison chain; merging that final return changed codegen.
 *
 * A throwaway smoke extracted the actual promoted body and ran 1,507,328
 * ID/skill selections (all u16 skills for IDs 0xFF..0x114 and 0xFFFF),
 * early gates, signed handles, and a zero special handle under Clang
 * AddressSanitizer and UndefinedBehaviorSanitizer. All passed.
 * This is native selector behavior, not a game-execution claim.
 */

s32 func_0022d200(u8 *action)
{
    u8 *global;
    u8 *unit;
    u16 unitId;
    u16 skill;

    global = iGpffffb3ac;
    if ((*(u32 *)(global + 0xC) & 0x200000) == 0) {
        return 0;
    }
    if ((*(u16 *)(action + 0x1A) & 1) == 0) {
        return 0;
    }
    unit = *(u8 **)(action + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1) {
        return 0;
    }
    unitId = *(u16 *)(unit + 0xA4);
    switch (unitId) {
    case 0x100:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x160 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x103:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x166 || skill == 0x167 || skill == 0x168) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    case 0x104:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x169 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x106:
    case 0x10F:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16D || skill == 0x173 || skill == 0x174 ||
            skill == 0x175 || skill == 0x176 || skill == 0x177) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x172 ? *(s32 *)(global + 0xBF4) : *(s32 *)(global + 0xBE0);
    case 0x105:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16B) {
            return *(s32 *)(global + 0xBF0);
        }
        if (skill == 0x16A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x16C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x108:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x17C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10A:
    case 0x113:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17F || skill == 0x186) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x180 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10B:
    case 0x10E:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x181 || skill == 0x18B || skill == 0x182 || skill == 0x185) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    default:
        return *(s32 *)(global + 0xBE0);
    }
}
