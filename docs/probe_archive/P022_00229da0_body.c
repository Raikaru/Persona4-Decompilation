/* Complete plain-C probe; production remains ASM.
 * classification=SOURCE_SHAPE_NONMATCH; object_size=2308; window=2320;
 * retail_executable_bytes=2312; missing_executable_bytes=4;
 * fully_resolved_code_relocations=75; executable_byte_diff=1481;
 * differing_executable_words_including_uncovered=458;
 * table_address=0x007478f0; table_bytes=36; table_relocations=9;
 * differing_table_bytes=9; unresolved_relocations=0; window_overrun=0.
 * The final eight retail bytes are zero alignment, not missing code.
 * Measured with the production code1_0022.c owner profile.
 *
 * First complete candidate: 2304B, 1448 differing overlap bytes, 460
 * executable word positions differing, including eight missing bytes.
 * One cast/lifetime refinement separated the ordinal scan, retained explicit
 * u16 loop narrowing in a wider counter, and restored config-array order.
 * The result below still does not match. No further compiler-floor sweep,
 * artificial padding, pinned registers, or undefined local reads was used.
 *
 * Both target passes, full u64 dependencies/action UIDs, independent output
 * coordinates, initialized 32-byte configs, all six switch arms, callback
 * reloads, and the second pass's otherwise-unused list walk are preserved.
 * The pointer-returning sound/voice providers were corrected separately.
 * No native-behavior or game-execution claim is made for this candidate.
 * Additional declarations assume the live owner's existing type forwards.
 */
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern BtlPacket *func_00202010(u32 unit, u16 skill);
extern u8 *func_00198300(u8 *unit, u8 *targetUnit, u32 flags);
extern u8 *func_00197f50(u8 *unit, const RwV3d *rotation, u32 flags);
extern u8 *func_001973f0(u8 *unit, const RwV3d *position, f32 speed, u32 flags);
extern s16 func_00199500(u8 *unit, s32 animation, f32 speed);
extern BtlPacket *func_001f7c20(u16 channel, u16 cue, u16 variant);
extern u8 *func_001d3700(u16 mode, u16 mask);
extern s32 func_001ef4a0(u16 skill);
extern u32 datCalcIsDead(s32 data, s32 hpDelta);
extern s32 func_00243e30(u16 *data);

// FUN_00229DA0
void func_00229da0(u8 *arg0)
{
    u8 *target;
    u32 index;
    u8 *lastEffect;
    s32 formation;
    u8 *packet = arg0;
    u8 *task;
    u32 slot;
    u32 delay;
    s16 animationFrames;
    u32 positionOffset;
    u8 *unit;
    u8 *cursor;
    u8 *animation;
    u8 *movement;
    u8 *finish;
    u8 *openingAnimation;
    u8 applyStatus[0x20];
    u8 clearStatus[0x20];

    formation = func_001d3d50(0);
    func_001d3ea0(formation, (u32)func_0022ced0(0xC));
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;

    task = (u8 *)func_00202010((u32)*(u8 **)(packet + 0x30), *(u16 *)(packet + 0x6E));
    *(u64 *)(task + 0x60) = *(u64 *)packet;
    func_00194590(task, 3);
    task = func_001bc920(packet, 0x1A);
    *(u64 *)(task + 0x60) = *(u64 *)packet;
    func_00194590(task, 0);
    openingAnimation = func_00199ee0(*(u8 **)(packet + 0x30), 0xF, 0, 2, 1.0f);
    *(u64 *)(openingAnimation + 0x60) = *(u64 *)packet;
    *(u16 *)(openingAnimation + 0x4A) = 0xC8;
    func_00194590(openingAnimation, 0);
    if (*(u16 *)(packet + 0x6A) == 1) {
        task = func_00198300(*(u8 **)(packet + 0x30),
                            *(u8 **)(*(u8 **)(packet + 0x38) + 0x30), 2);
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 0);
    } else {
        task = func_00197f50(*(u8 **)(packet + 0x30), (const RwV3d *)D_006354C0, 2);
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 1);
    }
    lastEffect = func_001d6240(formation, *(u8 **)(packet + 0x30),
                              *(u8 **)(packet + 0x30), 0, 0x200);
    *(u64 *)(lastEffect + 0x60) = *(u64 *)packet;
    func_00194590(lastEffect, 2);
    task = (u8 *)func_001f7c20(0xC, 5, 0xE);
    *(u16 *)(task + 0x48) = 0x5A;
    *(u64 *)(task + 0x60) = *(u64 *)packet;
    func_00194590(task, 1);

    func_001f0a10(applyStatus);
    *(u32 *)(applyStatus + 8) = 0x100;
    func_001f0a10(clearStatus);
    *(u32 *)(clearStatus + 0xC) = 0x100001;
    delay = 0;
    for (index = 0; (u16)index < *(u16 *)(packet + 0x6A); index = (u16)(index + 1)) {
        target = *(u8 **)(packet + (u16)index * 4 + 0x38);
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0 || *(u16 *)(unit + 0xA4) == 1 ||
            (*(u16 *)(target + 0x1A) & 1) == 0 ||
            datCalcIsDead((s32)*(u8 **)(unit + 0xA64), 0) != 0)
            continue;

        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0) {
            slot = 0;
        } else {
            u16 ordinal = 0;
            for (cursor = *(u8 **)(iGpffffb3ac + 0x17C); cursor != NULL;
                 cursor = *(u8 **)(cursor + 0xA68)) {
                if (unit == cursor)
                    break;
                ordinal++;
            }
            slot = ordinal;
        }
        lastEffect = func_001d6240(formation, *(u8 **)(packet + 0x30), unit, 1, 0x200);
        *(u16 *)(lastEffect + 0x48) = delay;
        *(u64 *)(lastEffect + 0x60) = *(u64 *)packet;
        func_00194590(lastEffect, 2);
        task = (u8 *)func_001f7c20(0xC, 5, 0xE);
        *(u16 *)(task + 0x48) = 0x6C;
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 1);
        positionOffset = (u16)slot * 12;
        unit = *(u8 **)(target + 0x30);
        func_001ec6d0((s16 *)(unit + 0x94), (s16 *)(unit + 0x96),
                     (f32 *)(D_00635500 + positionOffset));
        *(u16 *)(target + 0x1A) &= 0xFFF7;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x20;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 8;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x10;
        if (func_00232710(*(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 0x100000)) {
            animation = func_00199ee0(*(u8 **)(target + 0x30), 0xB, 0, 0, 1.0f);
            animation[0] = 0xB;
            *(u64 *)(animation + 8) = *(u64 *)(lastEffect + 0x58);
            *(u64 *)(animation + 0x60) = *(u64 *)packet;
            func_00194590(animation, 0);
            task = (u8 *)func_001f36e0((s32)target, (s32)target, clearStatus, 1, 1);
            task[0] = 4;
            *(u64 *)(task + 8) = *(u64 *)(animation + 0x58);
            *(u64 *)(task + 0x60) = *(u64 *)packet;
            func_00194590(task, 1);
            animationFrames = func_00199500(*(u8 **)(target + 0x30), 0xB, 1.0f);
        } else {
            animationFrames = 0;
        }
        movement = func_001973f0(*(u8 **)(target + 0x30),
                                (const RwV3d *)(D_006354D0 + positionOffset), 0.5f, 8);
        movement[0] = 0xB;
        *(u64 *)(movement + 8) = *(u64 *)(lastEffect + 0x58);
        *(s16 *)(movement + 0x48) = animationFrames;
        *(u64 *)(movement + 0x60) = *(u64 *)packet;
        func_00194590(movement, 1);
        task = func_00197f50(*(u8 **)(target + 0x30), (const RwV3d *)D_006354C0, 0);
        task[0] = 4;
        *(u64 *)(task + 8) = *(u64 *)(movement + 0x58);
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 1);
        if (func_00243e30((u16 *)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64)))
            *(u16 *)(applyStatus + 0x1E) |= 0x80;
        else
            *(u16 *)(applyStatus + 0x1E) &= 0xFF7F;
        task = (u8 *)func_001f36e0((s32)target, (s32)target, applyStatus, 1, 1);
        task[0] = 4;
        *(u64 *)(task + 8) = *(u64 *)(movement + 0x58);
        *(u16 *)(task + 0x48) = 8;
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 1);
        switch (*(u16 *)(*(u8 **)(target + 0x30) + 0xA4)) {
        case 2:
            func_00106390(0x15CF, 1);
            break;
        case 3:
            func_00106390(0x15D0, 1);
            break;
        case 4:
            func_00106390(0x15D1, 1);
            break;
        case 6:
            func_00106390(0x15D2, 1);
            break;
        case 8:
            func_00106390(0x15D3, 1);
            break;
        case 7:
            func_00106390(0x15D4, 1);
            break;
        }
        delay += (u16)func_001ef4a0(0x17B);
    }
    *(u16 *)(iGpffffb3ac + 0x18) = 0;
    *(u32 *)(iGpffffb3ac + 0xC) &= 0xFFBFFFFF;
    finish = func_001bc920(packet, 0x2C);
    finish[0] = 4;
    *(u64 *)(finish + 8) = *(u64 *)(openingAnimation + 0x58);
    if (lastEffect != NULL) {
        finish[0x10] = 4;
        *(u64 *)(finish + 0x18) = *(u64 *)(lastEffect + 0x58);
    }
    *(u64 *)(finish + 0x60) = *(u64 *)packet;
    func_00194590(finish, 0);
    task = func_001d3700(2, 0xFFF);
    task[0] = 4;
    *(u64 *)(task + 8) = *(u64 *)(finish + 0x58);
    *(u64 *)(task + 0x60) = *(u64 *)packet;
    func_00194590(task, 0);
    task = func_00199ee0(*(u8 **)(packet + 0x30), 0xB, 0, 0, 1.0f);
    task[0] = 4;
    *(u64 *)(task + 8) = *(u64 *)(finish + 0x58);
    *(u16 *)(task + 0x4A) = 0x60;
    *(u64 *)(task + 0x60) = *(u64 *)packet;
    func_00194590(task, 0);
    for (index = 0; (u16)index < *(u16 *)(packet + 0x6A); index = (u16)(index + 1)) {
        target = *(u8 **)(packet + (u16)index * 4 + 0x38);
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0 || *(u16 *)(unit + 0xA4) == 1 ||
            (*(u16 *)(target + 0x1A) & 1) == 0 ||
            datCalcIsDead((s32)*(u8 **)(unit + 0xA64), 0) != 0)
            continue;
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] == 0) {
            for (cursor = *(u8 **)(iGpffffb3ac + 0x17C); cursor != NULL;
                 cursor = *(u8 **)(cursor + 0xA68)) {
                if (unit == cursor)
                    break;
            }
        }
        movement = func_001973f0(unit, NULL, fGpffff809c, 0x18);
        movement[0] = 4;
        *(u64 *)(movement + 8) = *(u64 *)(finish + 0x58);
        *(u64 *)(movement + 0x60) = *(u64 *)packet;
        func_00194590(movement, 1);
        task = func_00197f50(*(u8 **)(target + 0x30), (const RwV3d *)D_006354C0, 0);
        task[0] = 4;
        *(u64 *)(task + 8) = *(u64 *)(movement + 0x58);
        *(u64 *)(task + 0x60) = *(u64 *)packet;
        func_00194590(task, 1);
    }
    func_001d3e00(formation);
}
