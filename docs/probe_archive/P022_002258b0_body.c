/* MATCH: promoted to src/promoted/code1_0022.c.
 * Object/window=800/800 bytes; normalized_diff=0;
 * fully_resolved_code_relocations=20; unmasked_byte_diff=0; no tail padding.
 * opt_common_subs off preserves the action reload and wrapping u16 target walk.
 * All 19 compiler-generated switch entries resolve exactly to retail table
 * 0x00747820: 2259E0,2259F4,225A08,225A40,225A54,225A8C,225AA0,
 * 225AEC,225B00,225B90,225B38,225B70,225B90,225B90,225B90,225AB4,
 * 225B90,225B90,225B84. Default slots retain scale=1.5, heightScale=0.2.
 *
 * ABI: camera=a0, distanceOffset=f12, duration=f13. The fitting provider
 * func_002266b0 receives heightScale=f12, scale=f13, distanceOffset=f14,
 * duration=f15. Height scale raises actor Y; it is not an angular threshold.
 * The switch selects ACTOR ID, but status checks read FIRST TARGET data.
 * All three real C callers remain fully resolved byte-exact:
 * func_00225bd0 44/48 bytes, func_00225c00 256/256, func_00225d00 252/256.
 * Their zero-only tails are 4/0/4 bytes; relocation counts are 1/7/7.
 *
 * GP=0x7690F0. Scalar addresses: fGpffff8030=761120,
 * fGpffff803c=76112C, fGpffff8098=761188, fGpffff8118=761208,
 * fGpffff8174=761264, fGpffff8178=761268, fGpffff817c=76126C.
 * Each is its own declared float; no address arithmetic beyond an extern
 * scalar is used. Exact code and table checks prove retail-byte identity;
 * no native execution or game-execution claim is made for this camera helper.
 */
extern void func_001c9820(u8 *camera, s32 reverseSide, s32 forceActorSide, f32 angleLimit);
extern void func_002266b0(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8098;
extern f32 fGpffff8118;
extern f32 fGpffff8174;
extern f32 fGpffff8178;
extern f32 fGpffff817c;

#pragma opt_common_subs off
void func_002258b0(u8 *camera, f32 distanceOffset, f32 duration)
{
    u8 *action;
    u8 *unit;
    u8 *target;
    u32 index;
    f32 scale;
    f32 heightScale;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL && (*(u16 *)(action + 0x1A) & 1) != 0) {
        if (action != NULL &&
            *(u8 *)((unit = *(u8 **)(action + 0x30)) + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (u16)index * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            func_001c9820(camera, 0, 1, 0.0f);
            return;
        }
        target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
        scale = 1.5f;
        heightScale = fGpffff803c;
        switch (*(u16 *)(unit + 0xA4)) {
        case 0x100:
            scale = 1.75f;
            heightScale = 0.0f;
            break;
        case 0x101:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x102:
            scale = 3.75f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8174;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x103:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x104:
            scale = 4.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8030;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x105:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x106:
            scale = 2.25f;
            heightScale = 0.0f;
            break;
        case 0x10F:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x107:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x108:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = 0.0f;
            } else {
                heightScale = fGpffff817c;
            }
            break;
        case 0x10A:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x10B:
            scale = 3.5f;
            heightScale = 0.0f;
            break;
        case 0x112:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        default:
            break;
        }
        func_002266b0(camera, heightScale, scale, distanceOffset, duration);
    }
}

#pragma opt_common_subs on
