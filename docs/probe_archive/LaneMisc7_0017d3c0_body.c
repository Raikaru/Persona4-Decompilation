/* Closest plain-C attempt for func_0017d3c0; lverify object 4052/window 5248, normalized_diff 2803. Reverted because it was not an exact match. */
// FUN_0017D3C0
s32 func_0017d3c0(u8 *arg0)
{
    u8 *work;
    u8 *entry;
    u8 *obj;
    u8 *other;
    s32 i;
    s32 j;
    s32 mode;
    s32 type;
    s32 subtype;
    s32 active;
    s32 active_other;
    s32 value;
    s32 count;
    s32 sample_count;
    f32 distance;
    f32 angle;
    f32 effect;
    f32 limit;
    f32 ratio;
    f32 dot;
    f32 turn;
    FldAIVec3 position;
    FldAIVec3 target;
    FldAIVec3 delta;
    FldAIVec3 direction;
    FldAIVec3 offset;
    FldAIVec3 sample;

    work = *(u8 **)(arg0 + 0x38);
    angle = 0.0f;
    effect = 0.0f;
    if (*(s32 *)(work + 4) == 1) {
        return 0;
    }
    active = 0;
    obj = *(u8 **)(work + 0x10);
    if ((*(s32 *)(obj + 0x48) != 0) && (*(s32 *)(obj + 0x54) != 0)) {
        active = 1;
    }
    if (active == 0) {
        return 0;
    }
    active_other = 0;
    obj = *(u8 **)(work + 0x14);
    if ((*(s32 *)(obj + 0x48) != 0) && (*(s32 *)(obj + 0x54) != 0)) {
        active_other = 1;
    }
    if (active_other == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(u8 **)(work + 0x50) = func_003e0f80();
        for (i = 0; i < 4; i++) {
            entry = D_007EF9B0 + i * 0x750;
            if ((*(s32 *)(entry + 0x48) != 0) &&
                (*(s32 *)(entry + 0x54) != 0) &&
                (*(u8 **)(work + 0x10) == entry)) {
                break;
            }
        }
        if (i >= 4) {
            func_0046d730(D_005F1B18, 0x97);
        }
        *(s32 *)(work + 0x20) = i;
        *(f32 *)(work + 0x24) = 2800.0f;
        *(f32 *)(work + 0x28) = 360.0f;
        *(s32 *)(work + 0x58) = 0;
        *(s32 *)(work + 0x5C) = 0;
        *(s32 *)(work + 0x4C) = -1;
        *(s32 *)work = *(s32 *)work + 1;
        break;
    case 1:
        type = func_001687d0(*(u8 **)(D_007EFA04 + 0x220));
        subtype = func_001687e0(*(u8 **)(D_007EFA04 + 0x220));
        value = *(s32 *)(func_00457120() + 4);
        func_001687f0((u8 *)&position,
                      *(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220);
        target = position;
        target.y += 180.0f;
        obj = func_003e9700(value);
        position.x = *(f32 *)(obj + 0x30);
        position.y = *(f32 *)(obj + 0x34);
        position.z = *(f32 *)(obj + 0x38);
        delta.x = target.x - position.x;
        delta.y = target.y - position.y;
        delta.z = target.z - position.z;
        distance = func_003e4180(&delta.x);
        if ((*(s32 *)(work + 0x6C) != 0) && (func_0014bd90() == 1)) {
            func_0047a870(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
            func_00452080(*(s32 *)(work + 0x6C));
            *(s32 *)(work + 0x6C) = 0;
        }
        if (distance <= *(f32 *)(work + 0x64) + 110.0f) {
            if (*(s32 *)(work + 0x6C) != 0) {
                func_0047a870(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
                func_00452080(*(s32 *)(work + 0x6C));
                *(s32 *)(work + 0x6C) = 0;
            }
            func_0047a220(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164,
                          (void *)0x00763048);
            *(s32 *)(work + 0x68) = 1;
        }
        if ((*(s32 *)(work + 0x68) == 1) &&
            (distance > *(f32 *)(work + 0x64) + 110.0f)) {
            func_0047a850(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
            *(s32 *)(work + 0x6C) = func_0014bbe0(
                (s32)arg0, *(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164,
                0, 0xFF, 10);
            *(s32 *)(work + 0x68) = 0;
        }
        if (func_00175db0() > 0.0f) {
            *(s32 *)(work + 0x0C) = 1;
        }
        if (*(s32 *)(work + 0x0C) == 0) {
            s32 current;
            s32 desired;
            current = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
            desired = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
            if (current != desired) {
                func_00479940(*(s32 *)(*(u8 **)(work + 0x10) + 0x50),
                               0, desired, 0, 1);
            }
        } else {
            u8 *table;
            type = func_001687d0(*(u8 **)(D_007EFA04 + 0x220));
            subtype = func_001687e0(*(u8 **)(D_007EFA04 + 0x220));
            table = func_00155280() + subtype * 0x100 + type * 0x10;
            value = table[0x58];
            if ((value == 2) || (value == 9) || (value == 0xA) ||
                (value == 0xB) || (value == 0xC) || (value == 0xD) ||
                (value == 0xE)) {
                *(s32 *)(work + 0x58) = 0;
                *(s32 *)(work + 0x5C) = 0;
                *(s32 *)(work + 0x4C) = -1;
                func_00168750(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220, 1);
                *(s32 *)(work + 0x18) = 1;
                if (*(s32 *)(work + 0x1C) != 1) {
                    if ((func_003b7060() & 1) == 0) {
                        *(s32 *)(work + 0x48) = -1;
                    } else if (*(s32 *)(*(u8 **)(work + 0x14) + 0x1B0) == 0) {
                        *(s32 *)(work + 0x48) = 1;
                    } else {
                        value = func_0017e980(arg0);
                        if (value < 1) {
                            if (value < 0) {
                                *(s32 *)(work + 0x48) = 1;
                            } else {
                                *(s32 *)(work + 0x48) = 0;
                            }
                        } else {
                            *(s32 *)(work + 0x48) = -1;
                        }
                    }
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            } else {
                *(s32 *)(work + 0x18) = 0;
                if (*(s32 *)(work + 0x1C) != 0) {
                    if ((func_003b7060() & 1) == 0) {
                        *(s32 *)(work + 0x48) = 0;
                    } else if (*(s32 *)(*(u8 **)(work + 0x14) + 0x1B0) == 0) {
                        *(s32 *)(work + 0x48) = 1;
                    } else {
                        value = func_0017e980(arg0);
                        if (value < 1) {
                            if (value < 0) {
                                *(s32 *)(work + 0x48) = 1;
                            } else {
                                *(s32 *)(work + 0x48) = 0;
                            }
                        } else {
                            *(s32 *)(work + 0x48) = -1;
                        }
                    }
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            }
        }
        *(s32 *)(work + 0x18) = 0;
        obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50));
        position.x = *(f32 *)(obj + 0x20);
        position.y = *(f32 *)(obj + 0x24);
        position.z = *(f32 *)(obj + 0x28);
        obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50));
        direction.x = *(f32 *)(obj + 0);
        direction.y = *(f32 *)(obj + 4);
        direction.z = *(f32 *)(obj + 8);
        func_003e40b0(&position.x, &position.x);
        func_003e40b0(&direction.x, &direction.x);
        func_0043f9c8(work + 0x30, 0, 0xC);
        func_0043f9c8(work + 0x3C, 0, 0xC);
        *(s32 *)(work + 0x2C) = 0;
        for (i = 0; i < 4; i++) {
            entry = D_007EF9B0 + i * 0x750;
            if ((*(s32 *)(entry + 0x48) != 0) &&
                (*(s32 *)(entry + 0x54) != 0) &&
                (*(u8 **)(work + 0x10) != entry)) {
                u8 *self_object;
                u8 *other_object;
                FldAIVec3 difference;
                f32 candidate;
                self_object = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50));
                other_object = func_0047a2f0(*(s32 *)(entry + 0x50));
                candidate = func_0014c3d0(
                    self_object, other_object + 0x30, *(f32 *)(work + 0x28),
                    *(f32 *)(work + 0x24), 0.0f);
                if ((candidate >= 0.0f) && (candidate <= 80.0f)) {
                    difference.x = *(f32 *)(other_object + 0x30) -
                                   *(f32 *)(self_object + 0x30);
                    difference.y = *(f32 *)(other_object + 0x34) -
                                   *(f32 *)(self_object + 0x34);
                    difference.z = *(f32 *)(other_object + 0x38) -
                                   *(f32 *)(self_object + 0x38);
                    func_003e40b0(&difference.x, &difference.x);
                    turn = 800.0f / candidate;
                    dot = difference.x * direction.x +
                          difference.y * direction.y +
                          difference.z * direction.z;
                    if (dot >= 0.0f) {
                        turn = turn * -1.0f;
                    }
                    angle += turn;
                    if (*(u8 **)(work + 0x14) == entry) {
                        *(f32 *)(work + 0x30) += *(f32 *)(other_object + 0x30);
                        *(f32 *)(work + 0x34) += *(f32 *)(other_object + 0x34);
                        *(f32 *)(work + 0x38) += *(f32 *)(other_object + 0x38);
                        *(f32 *)(work + 0x3C) += *(f32 *)(other_object + 0x20);
                        *(f32 *)(work + 0x40) += *(f32 *)(other_object + 0x24);
                        *(f32 *)(work + 0x44) += *(f32 *)(other_object + 0x28);
                        *(s32 *)(work + 0x2C) += 1;
                    }
                }
            }
        }
        obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x14) + 0x50));
        delta.x = *(f32 *)(obj + 0x30) -
                  *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)) + 0x30);
        delta.y = *(f32 *)(obj + 0x34) -
                  *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)) + 0x34);
        delta.z = *(f32 *)(obj + 0x38) -
                  *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)) + 0x38);
        distance = func_003e40b0(&delta.x, &delta.x);
        limit = func_00175db0() > 0.0f ? 400.0f : 150.0f;
        if (distance > limit) {
            ratio = distance / limit;
            if (ratio > 1.0f) {
                ratio = 1.0f;
            }
            effect += iGpffff830c * ratio;
        }
        count = *(s32 *)(work + 0x2C);
        if (count > 0) {
            func_0043f9c8(&offset.x, 0, 0xC);
            if (*(s32 *)(work + 0x18) == 0) {
                obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x14) + 0x50));
                sample.x = *(f32 *)(obj + 0);
                sample.y = *(f32 *)(obj + 4);
                sample.z = *(f32 *)(obj + 8);
                func_003e40b0(&sample.x, &sample.x);
                mode = *(s32 *)(work + 0x20);
                if ((mode == 1) || (mode == 2) || (mode == 3)) {
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.x = -sample.x;
                        sample.y = -sample.y;
                        sample.z = -sample.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = sample.x * 100.0f;
                        offset.y = sample.y * 100.0f;
                        offset.z = sample.z * 100.0f;
                    }
                } else {
                    func_0046d730(D_005F1B18, 0x19F);
                }
            } else {
                obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x14) + 0x50));
                sample.x = *(f32 *)(obj + 0);
                sample.y = *(f32 *)(obj + 4);
                sample.z = *(f32 *)(obj + 8);
                func_003e40b0(&sample.x, &sample.x);
                mode = *(s32 *)(work + 0x20);
                if ((mode == 1) || (mode == 2) || (mode == 3)) {
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.x = -sample.x;
                        sample.y = -sample.y;
                        sample.z = -sample.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = sample.x * 50.0f;
                        offset.y = sample.y * 50.0f;
                        offset.z = sample.z * 50.0f;
                    }
                } else {
                    func_0046d730(D_005F1B18, 0x1B6);
                }
            }
            obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50));
            offset.x += *(f32 *)(obj + 0x30);
            offset.y += *(f32 *)(obj + 0x34);
            offset.z += *(f32 *)(obj + 0x38);
            *(f32 *)(work + 0x30) += offset.x;
            *(f32 *)(work + 0x34) += offset.y;
            *(f32 *)(work + 0x38) += offset.z;
            *(f32 *)(work + 0x30) /= (f32)(count + 1);
            *(f32 *)(work + 0x34) /= (f32)(count + 1);
            *(f32 *)(work + 0x38) /= (f32)(count + 1);
            obj = func_0047a2f0(*(s32 *)(*(u8 **)(work + 0x10) + 0x50));
            delta.x = *(f32 *)(work + 0x30) - *(f32 *)(obj + 0x30);
            delta.y = *(f32 *)(work + 0x34) - *(f32 *)(obj + 0x34);
            delta.z = *(f32 *)(work + 0x38) - *(f32 *)(obj + 0x38);
            func_003e40b0(&delta.x, &delta.x);
            dot = delta.x * direction.x + delta.y * direction.y + delta.z * direction.z;
            if (dot < 1.0f) {
                ratio = (func_0044b920(dot) * 20.0f) / iGpffff82fc;
                if (1.0f - dot < ratio / 180.0f) {
                    ratio = (1.0f - dot) * 180.0f;
                }
                turn = delta.x * sample.x + delta.y * sample.y + delta.z * sample.z;
                if (turn < 0.0f) {
                    ratio = ratio * -1.0f;
                }
                angle += ratio;
            }
        }
        if ((distance <= 2800.0f) || (*(s32 *)(work + 8) != 0)) {
            if ((angle != 0.0f) && (effect != 0.0f)) {
                func_00168de0(
                    *(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                    D_00756510, angle);
            }
            if (effect != 0.0f) {
                func_00168cb0(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                              effect);
            }
            j = *(s32 *)(*(u8 **)(work + 0x10) + 0x710) - 1;
            if (j < 0) {
                j = 0x3F;
            }
            obj = *(u8 **)(work + 0x10);
            if (*(u8 *)(obj + j + 0x1D0) != 0) {
                func_001687f0((u8 *)&position,
                              *(u8 **)(*(u8 **)(obj + 0x54) + 0x220));
                target.x = *(f32 *)(obj + j * 8 + 0x210);
                target.z = *(f32 *)(obj + j * 8 + 0x214);
                target.y = position.y;
                delta.x = target.x - position.x;
                delta.y = target.y - position.y;
                delta.z = target.z - position.z;
                if (func_003e4180(&delta.x) < effect) {
                    active = 1;
                } else {
                    active = 0;
                }
            } else {
                active = 0;
            }
            if ((effect == 0.0f) || (active != 0)) {
                if (*(s32 *)(work + 0x60) < 0x1E) {
                    *(s32 *)(work + 0x60) += 1;
                } else {
                    value = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                    mode = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    if (value != mode) {
                        func_00479940(*(s32 *)(*(u8 **)(work + 0x10) + 0x50),
                                       0, mode, 0x10, 1);
                    }
                    *(s32 *)(work + 0x60) = 0;
                }
            } else {
                value = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                mode = (s16)func_0016ffd0(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                if (value != mode) {
                    func_00479940(*(s32 *)(*(u8 **)(work + 0x10) + 0x50),
                                   0, mode, 8, 1);
                    *(s32 *)(work + 0x60) = 0;
                }
            }
        } else {
            obj = func_0047a2f0(*(s32 *)(D_007EFA04 + 0x164));
            func_00168ae0(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                          obj + 0x30);
            *(s32 *)(work + 0x4C) = -1;
            *(s32 *)(work + 0x58) = 0;
            *(s32 *)(work + 0x5C) = 0;
        }
        if (*(s32 *)(work + 8) == 0) {
            *(s32 *)(work + 8) = 1;
        }
        break;
    case 2:
    default:
        break;
    }
    return 0;
}
