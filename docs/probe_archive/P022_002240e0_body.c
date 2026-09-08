/* Complete ordinary-C source; production remains ASM.
 * classification=SOURCE_SHAPE_NONMATCH; object_size=872; window=880;
 * normalized_diff=344; fully_resolved_code_relocations=34;
 * unmasked_overlap_byte_diff=413;
 * differing_executable_words_including_uncovered=135;
 * retail_executable_bytes=876; missing_executable_bytes=4;
 * unresolved_relocations=0; window_overrun=0; no jump table.
 * Final four retail bytes are zero alignment. Measured in the current
 * production owner after the 002258b0 and 0022d200 promotions.
 * Previous retained source: 872 bytes, 414 unmasked differing bytes,
 * 136 differing executable words including the uncovered instruction.
 *
 * One camera pointer is the complete ABI. Matched caller func_00227e40
 * forwards it at retail 0x227EE4 and 0x227F08. All saved GPRs are defined
 * locally; no missing live-in or unwritten pose component was found.
 * Source/destination poses are seven floats each (pair size 0x38).
 * func_001bd560 writes the complete first pose; func_001bd780 writes the
 * destination quaternion, and the explicit float snapshot supplies XYZ.
 * The normal preset record contains six floats: eye[3], lookAt[3].
 *
 * Absolute special-vector objects are at 0x634870 and 0x63487C. Scalar
 * aliases at 0x634874/0x634878 use the existing unsized-array declaration
 * convention, not small-data scalar declarations that emit out-of-range
 * GP loads. Duration fGpffff80e8 is at 0x7611D8 (word 0x3F666666).
 * Both status accumulators are presence flags; traversal does not stop
 * after either flag becomes true. The canonical datCalcChkBadStatus is
 * used, rather than the owner's old generic func_00232710 declaration.
 *
 * Remaining differences: saved-register assignment, conditional narrowing
 * and instruction selection. Scoped walks, inline selection, reordered
 * declarations, explicit mask/selection separation, optimization level 1,
 * common-subexpression/propagation/conditional-rebuilding controls did not
 * produce a match. Diagnostic helpers and permutations are not retained.
 * No fixed registers, inline assembly, padding fields, invented arguments
 * or undefined reads were introduced. No native/game execution is claimed.
 * Rechecked after the halfword transition API repair: the complete baseline
 * still gives 872 bytes / 344 normalized differences. Word-sized variant
 * and party selectors give 868 bytes / 343 differences, omitting eight
 * executable bytes instead of four. Current propagation-off and explicit
 * selection temporaries do not close the missing narrowing or register
 * allocation differences. The complete baseline below remains preferred.
 * Additional declarations assume the live owner's existing types/providers.
 */
extern s32 func_00243d80(u8 *unitData);
extern s32 func_00243e30(u16 *unitData);
extern void func_001b73f0(u8 *unit);
extern f32 fGpffff80e8;
extern u8 D_00634870[];
extern f32 D_00634874[];
extern f32 D_00634878[];
extern u8 D_0063487C[];

void func_002240e0(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *unit;
    u8 *partyMember;
    u8 *enemy;
    u8 *ally;
    u8 *record;
    f32 x;
    f32 y;
    f32 z;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u16 previousState;
    s32 reset;
    s32 hasStatus;
    s32 hasPriorityStatus;

    previousState = *(u16 *)(iGpffffb3ac + 0x108);
    switch (previousState) {
    case 2:
    case 0x22:
    case 0x28:
    case 0x29:
        reset = 0;
        break;
    default:
        reset = 1;
        break;
    }
    if (*(s32 *)(camera + 0x148) != 0) {
        reset = 1;
        *(s32 *)(camera + 0x148) = 0;
    }
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (*(u8 *)(unit + 0xA2) != 0) {
        partyIndex = 0;
    } else {
        ordinal = 0;
        partyMember = *(u8 **)(iGpffffb3ac + 0x17C);
        while (partyMember != NULL) {
            if (unit == partyMember) {
                break;
            }
            ordinal = (u16)(ordinal + 1);
            partyMember = *(u8 **)(partyMember + 0xA68);
        }
        partyIndex = (u16)ordinal;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = *(u8 **)(iGpffffb3ac + 0x180);
    while (enemy != NULL) {
        if ((*(u32 *)(enemy + 0x9C) & 8) != 0 &&
            *(u8 **)(enemy + 0xA64) != NULL &&
            func_00243d80(*(u8 **)(enemy + 0xA64)) != 0) {
            if (datCalcChkBadStatus(*(s32 *)(enemy + 0xA64), 0x100000) != 0) {
                hasStatus = 1;
            }
            if (func_00243e30(*(u16 **)(enemy + 0xA64)) != 0) {
                hasPriorityStatus = 1;
            }
        }
        enemy = *(u8 **)(enemy + 0xA6C);
    }
    variant = hasPriorityStatus != 0 ? 2 : (u16)(hasStatus != 0);
    if (func_001ef9a0() == 0x208 && (u16)variant == 0) {
        ally = *(u8 **)(iGpffffb3ac + 0x178);
        while (ally != NULL) {
            if ((*(u32 *)(ally + 0x9C) & 8) != 0 &&
                *(u8 **)(ally + 0xA64) != NULL &&
                datCalcChkBadStatus(*(s32 *)(ally + 0xA64), 0x100) != 0) {
                variant = 2;
                break;
            }
            ally = *(u8 **)(ally + 0xA6C);
        }
    }
    func_001bd560((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (func_001ef9a0() != 0x215) {
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x48 + (u16)variant * 0x18;
        func_001bd780(&poses.secondRotation, record, record + 0xC, D_0060A0E0);
        x = *(f32 *)record;
        y = *(f32 *)(record + 4);
        z = *(f32 *)(record + 8);
        poses.second.x = x;
        poses.second.y = y;
        poses.second.z = z;
    } else {
        func_001bd780(&poses.secondRotation, D_00634870, D_0063487C, D_0060A0E0);
        x = *(f32 *)D_00634870;
        y = D_00634874[0];
        z = D_00634878[0];
        poses.second.x = x;
        poses.second.y = y;
        poses.second.z = z;
    }
    if (reset != 0) {
        func_001b73f0(NULL);
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        func_001bab00((u16 *)camera, (f32 *)&poses.second);
    } else {
        func_001bac20((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
        func_001bbef0(camera, fGpffff80e8);
    }
}
