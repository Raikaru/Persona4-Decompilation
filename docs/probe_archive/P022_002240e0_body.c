/* Complete plain-C probe; production remains ASM.
 * classification=SOURCE_SHAPE_NONMATCH; object_size=872; window=880;
 * retail_executable_bytes=876; missing_executable_bytes=4;
 * fully_resolved_code_relocations=34; executable_byte_diff=414;
 * differing_executable_words_including_uncovered=136;
 * unresolved_relocations=0; window_overrun=0; no jump table.
 * The final four retail bytes are zero alignment, not missing code.
 * Measured with the production code1_0022.c owner profile.
 *
 * First complete candidate: 868B, 557 differing overlap bytes, 174
 * executable word positions differing, including eight missing bytes.
 * Contiguous seven-float transform records, separate ordinal traversal,
 * and conditional-result narrowing improved the source to the result below.
 * A subsequent ordinary for-loop spelling produced identical bytes.
 * No assembly, artificial padding, fixed registers, or undefined reads.
 * No native-behavior or game-execution claim is made for this candidate.
 * Additional declarations assume the live owner's existing declarations.
 */
extern s32 func_00243d80(u8 *arg0);
extern s32 func_00243e30(u16 *arg0);
extern void func_001b73f0(u8 *arg0);
extern f32 D_00634870[3];
extern f32 D_00634874[];
extern f32 D_00634878[];
extern f32 D_0063487C[3];
extern f32 fGpffff80e8;

void func_002240e0(u8 *arg0)
{
    f32 transforms[2][7];
    f32 *entry;
    f32 x;
    f32 y;
    f32 z;
    u8 *unit;
    u8 *node;
    s32 immediate;
    s32 hasBadStatus;
    s32 hasUnitFlag;
    u16 state;
    u32 index;
    u16 variant;

    state = *(u16 *)(iGpffffb3ac + 0x108);
    switch (state) {
    case 0x29:
    case 0x28:
    case 0x22:
    case 2:
        immediate = 0;
        break;
    default:
        immediate = 1;
        break;
    }
    if (*(s32 *)(arg0 + 0x148) != 0) {
        immediate = 1;
        *(s32 *)(arg0 + 0x148) = 0;
    }

    unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    if (*(u8 *)(unit + 0xA2) != 0) {
        index = 0;
    } else {
        u16 ordinal = 0;
        u8 *cursor;
        for (cursor = *(u8 **)(iGpffffb3ac + 0x17C); cursor != NULL;
             cursor = *(u8 **)(cursor + 0xA68)) {
            if (unit == cursor) {
                break;
            }
            ordinal++;
        }
        index = ordinal;
    }

    hasBadStatus = 0;
    hasUnitFlag = 0;
    node = *(u8 **)(iGpffffb3ac + 0x180);
    while (node != NULL) {
        if ((*(u32 *)(node + 0x9C) & 8) != 0 &&
            *(u8 **)(node + 0xA64) != NULL &&
            func_00243d80(*(u8 **)(node + 0xA64)) != 0) {
            if (datCalcChkBadStatus((s32)*(u8 **)(node + 0xA64),
                                    0x100000) != 0) {
                hasBadStatus = 1;
            }
            if (func_00243e30(*(u16 **)(node + 0xA64)) != 0) {
                hasUnitFlag = 1;
            }
        }
        node = *(u8 **)(node + 0xA6C);
    }
    variant = hasUnitFlag != 0 ? 2 : (u16)(hasBadStatus != 0);

    if (func_001ef9a0() == 0x208 && variant == 0) {
        node = *(u8 **)(iGpffffb3ac + 0x178);
        while (node != NULL) {
            if ((*(u32 *)(node + 0x9C) & 8) != 0 &&
                *(u8 **)(node + 0xA64) != NULL &&
                datCalcChkBadStatus((s32)*(u8 **)(node + 0xA64),
                                    0x100) != 0) {
                variant = 2;
                break;
            }
            node = *(u8 **)(node + 0xA6C);
        }
    }

    func_001bd560(transforms[0], (f32 *)(arg0 + 0x9C));
    if (func_001ef9a0() != 0x215) {
        entry = (f32 *)(*(u8 **)(iGpffffb3ac + 0xB98) +
                        (u32)(u16)index * 0x48 + (u32)variant * 0x18);
        func_001bd780(transforms[1] + 3, entry, entry + 3, D_0060A0E0);
        x = entry[0];
        y = entry[1];
        z = entry[2];
        transforms[1][0] = x;
        transforms[1][1] = y;
        transforms[1][2] = z;
    } else {
        func_001bd780(transforms[1] + 3, D_00634870, D_0063487C,
                      D_0060A0E0);
        x = D_00634870[0];
        y = D_00634874[0];
        z = D_00634878[0];
        transforms[1][0] = x;
        transforms[1][1] = y;
        transforms[1][2] = z;
    }

    if (immediate != 0) {
        func_001b73f0(NULL);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0.0f);
        func_001bab00((u16 *)arg0, transforms[1]);
    } else {
        func_001bac20((u16 *)arg0, transforms[0], transforms[1], 1);
        func_001bbef0(arg0, fGpffff80e8);
    }
}
