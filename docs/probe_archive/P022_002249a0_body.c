/* MATCH: ordinary C; object_size=1780; window=1792; normalized_diff=0;
 * code_relocations=32; uncovered_tail=12 zero alignment bytes.
 * Verified in the integrated src/promoted/code1_0022.c owner context.
 * Both btlUnitGetSphereWorldCenter calls initialize exactly XYZ; every
 * branch returns a defined framing scale. The complete 20-entry retail
 * jump table is reproduced without inline COP1 instructions.
 * GP=0x7690F0: 8030=0.1, 803c=0.2, 8100=0.45, 810c=0.05,
 * 8118=0.15, 8128=0.35, 813c=0.4. Production ASM replaced by this body.
 */
f32 func_002249a0(u8 *actor, u8 *target, RwV3d *actorPosition, RwV3d *targetPosition)
{
    u32 actorKind;
    f32 height;

    btlUnitGetSphereWorldCenter((BtlUnit *)actor, actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, targetPosition);

    actorKind = actor[0xA2];
    if (actorKind == 0 && target[0xA2] == 1) {
        switch (*(u16 *)(target + 0xA4)) {
        case 0x100:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 3.5f;
        case 0x101:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8100 * height;
            return 4.5f;
        case 0x103:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 5.0f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 5.0f;
        case 0x104:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8128 * height;
            return 4.5f;
        case 0x105:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x106:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.75f * height;
            return 5.0f;
        case 0x10F:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x107:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff813c * height;
            return 4.5f;
        case 0x108:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 5.0f;
        case 0x10A:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x112:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 4.5f;
        case 0x113:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 6.5f;
        }
    } else if (actorKind == 1 && target[0xA2] == 0) {
        switch (*(u16 *)(actor + 0xA4)) {
        case 0x100: {
            f32 coefficient;
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            coefficient = fGpffff8100;
            actorPosition->y = (0.0f + actorPosition->y) - coefficient * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + coefficient * height;
            return 4.5f;
        }
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8100 * height;
            return 5.5f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8128 * height;
            return 5.0f;
        }
    }
    return 3.5f;
}
