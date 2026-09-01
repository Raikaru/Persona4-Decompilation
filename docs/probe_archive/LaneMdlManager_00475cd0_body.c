/* Closest reconstruction candidate for func_00475cd0; retained for future work. */
// FUN_00475CD0
void func_00475cd0(void* param_1)
{
    extern void func_00397c40();
    extern void func_003f6440(s32 a, s32 b);
    extern void func_00477260(u64 a, u32* b, u16 c);
    extern void func_004789c0(void* a);
    extern void func_003dc610(void* out, void* in);
    extern void func_003dcb40(void* out, const void* in, s32 count, const void* quat);
    extern void func_003dcc70(f32* first, f32* second, void* result);
    extern f32 func_0044b920(f32 value);
    extern void* func_004571b0(void);
    extern void* func_004571c0(void* object, u32 index);
    extern void func_004746b0(u8* a, u8* b);
    extern void func_00479910(void* a);
    extern void* func_0047a2f0(void* a);
    extern s32 func_0047a510(void* a, s32 b, void* c);
    extern void func_0047d540(u32 a, void* b);
    extern void func_0047d900(u32 a, void* b);
    extern void func_0047dd40(u32 a, void* b);
    extern void (*D_00887300_abs[])(s32, s32);
    extern void (*D_00887304[])(s32, void*);
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff80f0;
    extern f32 fGpffff81f4;

    u32 current;
    u32 target;
    u32 value;
    u32 flags;
    struct {
        f32 quaternion[4];
        struct {
            f32 value[4];
            f32 second[4];
            f32 scale;
            s32 flag;
        } interpolation;
        u8 padding[0x18];
        u8 identity[0x40];
        u8 matrix0[0x40];
        u8 matrix1[0x48];
        f32 direction[3];
        u8 directionPadding[4];
        s32 renderState;
        u8 color[4];
    } stack;
#define color stack.color
#define quaternion stack.quaternion
#define interpolation stack.interpolation
#define direction stack.direction
#define matrix0 stack.matrix0
#define matrix1 stack.matrix1
#define identity stack.identity
#define renderState stack.renderState
    void (**renderStateSet)(s32, s32);
    u8* material;
    u8* source;
    u8* effect;
    u8* slot;
    u8* model;
    u8* animation;
    u16 i;
    u16 j;
    u16 k;
    u32 hasIndex;
    u32 hasItem;
    u32 needsReset;
    u32 copyCount;
    u32* copySource;
    u32* copyTarget;

    target = *(u8*)((u8*)param_1 + 0x281);
    current = *(u8*)((u8*)param_1 + 0x280);
    if (current < target) {
        value = current + *(u8*)((u8*)param_1 + 0x282);
        if (target < value) {
            *(u8*)((u8*)param_1 + 0x280) = (u8)target;
        } else {
            *(u8*)((u8*)param_1 + 0x280) = (u8)value;
        }
    } else if (target < current) {
        value = current - *(u8*)((u8*)param_1 + 0x282);
        if (value < target) {
            *(u8*)((u8*)param_1 + 0x280) = (u8)target;
        } else {
            *(u8*)((u8*)param_1 + 0x280) = (u8)value;
        }
    } else {
        *(u8*)((u8*)param_1 + 0x280) = (u8)target;
    }

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    flags = *(u8*)((u8*)param_1 + 0x260);
    {
        f32 alpha;
        s32 alphaValue;
        alpha = 255.0f * ((f32)(*(u8*)((u8*)param_1 + 0x280)
                                * *(u8*)((u8*)param_1 + 0xD3)) / 65025.0f);
        if (alpha >= 2147483600.0f) {
            alphaValue = (s32)(alpha - 2147483600.0f);
        } else {
            alphaValue = (s32)alpha;
        }
        color[3] = (u8)alphaValue;
    }

    if ((flags & 1) != 0 && (flags & 0x20) == 0) {
        material = (u8*)func_004571b0();
    } else {
        material = (u8*)func_004571c0(param_1, target);
    }
    material = *(u8**)(material + 4);

    if ((flags & 2) != 0 && (flags & 0x20) == 0) {
        if ((flags & 4) == 0) {
            func_003dc610(quaternion, material + 0x10);
        } else {
            quaternion[0] = *((f32*)((u8*)&fGpffff81f4) + 1);
            quaternion[1] = 0.0f;
            quaternion[2] = 0.0f;
            quaternion[3] = quaternion[0];
        }
        {
            f32 dot;
            f32 angle;
            f32 amount;
            f32 limit;
            dot = *(f32*)((u8*)param_1 + 0x268) * quaternion[1]
                + *(f32*)((u8*)param_1 + 0x264) * quaternion[0]
                + *(f32*)((u8*)param_1 + 0x26C) * quaternion[2]
                + *(f32*)((u8*)param_1 + 0x270) * quaternion[3];
            if (dot < 0.0f) {
                quaternion[3] = -quaternion[3];
                quaternion[0] = -quaternion[0];
                quaternion[1] = -quaternion[1];
                quaternion[2] = -quaternion[2];
                dot = *(f32*)((u8*)param_1 + 0x268) * quaternion[1]
                    + *(f32*)((u8*)param_1 + 0x264) * quaternion[0]
                    + *(f32*)((u8*)param_1 + 0x26C) * quaternion[2]
                    + *(f32*)((u8*)param_1 + 0x270) * quaternion[3];
            }
            angle = 2.0f * func_0044b920(dot);
            limit = *(f32*)((u8*)param_1 + 0x284);
            if (limit < 1.0f) {
                f32 maximum;
                maximum = *(f32*)((u8*)param_1 + 0x288);
                if (angle <= maximum) {
                    amount = limit;
                } else {
                    amount = maximum / angle;
                    if (amount < limit) {
                        amount = limit;
                    }
                }
                func_003dcc70((f32*)((u8*)param_1 + 0x264), quaternion,
                              &interpolation);
                if (amount <= 0.0f) {
                    interpolation.value[0] = *(f32*)((u8*)param_1 + 0x264);
                    interpolation.value[1] = *(f32*)((u8*)param_1 + 0x268);
                    interpolation.value[2] = *(f32*)((u8*)param_1 + 0x26C);
                    interpolation.value[3] = *(f32*)((u8*)param_1 + 0x270);
                } else if (amount >= 1.0f) {
                    interpolation.value[0] = quaternion[0];
                    interpolation.value[1] = quaternion[1];
                    interpolation.value[2] = quaternion[2];
                    interpolation.value[3] = quaternion[3];
                } else {
                    f32 remaining;
                    f32 t;
                    f32 t2;
                    f32 t3;
                    f32 curve0;
                    f32 curve1;
                    remaining = 1.0f - amount;
                    if (interpolation.flag == 0) {
                        t = remaining * interpolation.scale;
                        t2 = t * t;
                        curve0 = t2 * (t2 * (t2 * (t2 * (t2 * fGpffff8054
                            + fGpffff8058) + fGpffff805c) + fGpffff8060)
                            + *(f32*)((u8*)&fGpffff81f4 + 8))
                            + t;
                        t = curve0 * interpolation.scale;
                        t2 = t * t;
                        curve1 = t2 * (t2 * (t2 * (t2 * (t2 * fGpffff8054
                            + fGpffff8058) + fGpffff805c) + fGpffff8060)
                            + *(f32*)((u8*)&fGpffff81f4 + 8))
                            + t;
                        interpolation.scale = curve1;
                    }
                    t = interpolation.value[0] * remaining;
                    interpolation.value[0] = t + interpolation.second[0] * interpolation.scale;
                    t = interpolation.value[1] * remaining;
                    interpolation.value[1] = t + interpolation.second[1] * interpolation.scale;
                    t = interpolation.value[2] * remaining;
                    interpolation.value[2] = t + interpolation.second[2] * interpolation.scale;
                    interpolation.value[3] = interpolation.value[3] * amount;
                    interpolation.value[3] = interpolation.value[3] + interpolation.second[3] * interpolation.scale;
                }
                *(f32*)((u8*)param_1 + 0x264) = interpolation.value[0];
                *(f32*)((u8*)param_1 + 0x268) = interpolation.value[1];
                *(f32*)((u8*)param_1 + 0x26C) = interpolation.value[2];
                *(f32*)((u8*)param_1 + 0x270) = interpolation.value[3];
            } else {
                *(f32*)((u8*)param_1 + 0x264) = quaternion[0];
                *(f32*)((u8*)param_1 + 0x268) = quaternion[1];
                *(f32*)((u8*)param_1 + 0x26C) = quaternion[2];
                *(f32*)((u8*)param_1 + 0x270) = quaternion[3];
            }
        }
        func_003dcb40(direction, (u8*)D_00713138 + 0x10, 1,
                      (u8*)param_1 + 0x264);
    } else {
        source = material + 0x10;
        func_003dc610((u8*)param_1 + 0x264, source);
        direction[0] = *(f32*)(source + 0x20);
        direction[1] = *(f32*)(source + 0x24);
        direction[2] = *(f32*)(source + 0x28);
    }

    if (color[3] == 0) {
        if ((*(u16*)((u8*)param_1 + 0xEC) & 0x10) != 0) {
            func_00473000(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC);
        } else if ((*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0) {
            func_00471370(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140, 0);
        } else {
            func_00397c40(*(void**)((u8*)param_1 + 0x10C));
        }
        if ((*(u32*)((u8*)param_1 + 0xD8) & 0x80000) != 0) {
            func_004746b0((u8*)param_1 + 0x234, (u8*)param_1 + 0xEC);
        }
        func_00477260((u64)(u32)*(void**)((u8*)param_1 + 0xDC), (u32*)color,
                               (u16)((*(u8*)((u8*)param_1 + 0x260) & 8) != 0));
        effect = *(u8**)((u8*)param_1 + 0xE0);
        if (effect == 0) {
            func_003f6440(3, 0x7C01B);
        } else if ((*(s32*)(effect + 0x10) != 0 || *(s32*)(effect + 0x1C) != 0)
                   && (*(u8*)((u8*)param_1 + 0x260) & 0x80) == 0) {
            func_003f6440(3, 0x7F06B);
        } else {
            func_003f6440(3, 0x7D7FB);
        }
        func_00479910(*(void**)((u8*)param_1 + 0xDC));
        func_004789c0(param_1);
        if ((*(u16*)((u8*)param_1 + 0xEC) & 0x10) != 0) {
            func_00473000(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC);
        } else if ((*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0) {
            func_00471370(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140, 0);
        } else {
            func_00397c40(*(void**)((u8*)param_1 + 0x10C));
        }
        effect = *(u8**)((u8*)param_1 + 0x2CC);
        if (effect != 0) {
            func_0047d900((u32)effect, (u8*)param_1 + 0x80);
            func_0047d540((u32)effect, param_1);
        }
        i = 0;
        while (i < 2) {
            model = *(u8**)((u8*)param_1 + i * 0xA4 + 0x124);
            if (model != 0) {
                effect = *(u8**)(model + 0x18);
                if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                    func_0047d900((u32)effect, model + 8);
                    func_0047d540((u32)effect, param_1);
                }
                effect = *(u8**)(model + 0x24);
                if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                    func_0047dd40((u32)effect, param_1);
                }
                if (*(u16*)(model + 0x30) > 0) {
                    *(u16*)(model + 0x30) -= 1;
                }
            }
            i++;
        }
        j = 0;
        while (j < 5) {
            slot = (u8*)param_1 + j * 0xC;
            if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
                *(void**)(slot + 0x290) != 0 &&
                func_0047ae90(param_1, j) != 0) {
                model = *(u8**)(slot + 0x290);
                if ((*(u32*)(model + 0xD8) & 2) == 0) {
                    if (*(s32*)(slot + 0x294) == -1) {
                        copyCount = 8;
                        copySource = (u32*)param_1;
                        copyTarget = (u32*)model;
                        do {
                            copyTarget[0] = copySource[0];
                            copyTarget[1] = copySource[1];
                            copySource += 2;
                            copyTarget += 2;
                            copyCount--;
                        } while (copyCount > 0);
                    } else {
                        func_0047a510(param_1, *(s32*)(slot + 0x294),
                                      func_0047a2f0(model));
                    }
                    hasIndex = 0;
                    hasItem = 0;
                    needsReset = 0;
                    animation = *(u8**)(model + 0x120);
                    if (animation != 0 &&
                        *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                        hasIndex = 1;
                    }
                    if (hasIndex != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                        hasItem = 1;
                    }
                    if (hasItem != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                            != (void*)D_00922BC0_abs) {
                        needsReset = 1;
                    }
                    if (needsReset != 0) {
                        func_00397c40(*(void**)(model + 0x10C));
                    }
                    if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                        func_004746b0(model + 0x234, model + 0xEC);
                    }
                }
            }
            j++;
        }
        return;
    }

    if (direction[1] >= 0.0f) {
        f32 unit;
        unit = *((f32*)((u8*)&fGpffff81f4) + 1);
        *(f32*)((u8*)param_1 + 0x264) = unit;
        *(f32*)((u8*)param_1 + 0x268) = 0.0f;
        *(f32*)((u8*)param_1 + 0x26C) = 0.0f;
        *(f32*)((u8*)param_1 + 0x270) = unit;
        func_003dcb40(direction, (u8*)D_00713138 + 0x10, 1,
                      (u8*)param_1 + 0x264);
    }
    if (*(f32*)((u8*)param_1 + 0x274) !=
        *(f32*)((u8*)param_1 + 0x278)) {
        *(f32*)((u8*)param_1 + 0x274) =
            *(f32*)((u8*)param_1 + 0x274)
            + *(f32*)((u8*)param_1 + 0x27C)
              * (*(f32*)((u8*)param_1 + 0x278)
                 - *(f32*)((u8*)param_1 + 0x274));
    }
    {
        f32 limit;
        limit = *(f32*)((u8*)param_1 + 0x274);
        if (fabsf(direction[1]) < limit) {
            if (direction[1] < 0.0f) {
                direction[1] = -limit;
            } else {
                direction[1] = limit;
            }
        }
    }

    *(f32*)(identity + 0x00) = 1.0f;
    *(f32*)(identity + 0x04) = 0.0f;
    *(f32*)(identity + 0x08) = 0.0f;
    *(f32*)(identity + 0x10) = -direction[0] / direction[1];
    *(f32*)(identity + 0x14) = fGpffff80f0;
    *(f32*)(identity + 0x18) = -direction[2] / direction[1];
    *(f32*)(identity + 0x20) = 0.0f;
    *(f32*)(identity + 0x24) = 0.0f;
    *(f32*)(identity + 0x28) = 1.0f;
    *(f32*)(identity + 0x30) = 0.0f;
    *(f32*)(identity + 0x34) = 0.0f;
    *(f32*)(identity + 0x38) = 0.0f;
    *(u32*)(identity + 0x0C) |= 0x20003;

    func_003e05f0(&matrix0, (u8*)param_1 + 0x40, param_1);
    func_003e05f0(&matrix1, &matrix0, &identity);
    func_003e9cb0(*(void**)((u8*)*(u8**)((u8*)param_1 + 0xDC) + 4),
                  &matrix1, 0);
    if ((*(u16*)((u8*)param_1 + 0x140) & 0x4000) != 0) {
        func_00471370(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140,
                      &identity);
    } else {
        func_00397c40(*(void**)((u8*)param_1 + 0x10C));
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](6, 1);
    renderStateSet[0](8, 0);
    D_00887304[0](0xE, &renderState);
    renderStateSet[0](0xE, 0);
    func_003f6440(2, 0x44);
    if ((*(u32*)((u8*)param_1 + 0xD8) & 0x80000) != 0) {
        func_004746b0((u8*)param_1 + 0x234, (u8*)param_1 + 0xEC);
    }
    func_00477260((u64)(u32)*(void**)((u8*)param_1 + 0xDC), (u32*)color,
                        (u16)((*(u8*)((u8*)param_1 + 0x260) & 8) != 0));
    effect = *(u8**)((u8*)param_1 + 0xE0);
    if (effect == 0) {
        func_003f6440(3, 0x7C01B);
    } else if ((*(s32*)(effect + 0x10) != 0 || *(s32*)(effect + 0x1C) != 0)
               && (*(u8*)((u8*)param_1 + 0x260) & 0x80) == 0) {
        func_003f6440(3, 0x7F06B);
    } else {
        func_003f6440(3, 0x7D7FB);
    }
    func_00479910(*(void**)((u8*)param_1 + 0xDC));
    func_004789c0(param_1);
    if ((*(u16*)((u8*)param_1 + 0xEC) & 0x10) != 0) {
        func_00473000(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC);
    } else if ((*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0) {
        func_00471370(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140, 0);
    } else {
        func_00397c40(*(void**)((u8*)param_1 + 0x10C));
    }
    effect = *(u8**)((u8*)param_1 + 0x2CC);
    if (effect != 0) {
        func_0047d900((u32)effect, (u8*)param_1 + 0x80);
        func_0047d540((u32)effect, param_1);
    }
    i = 0;
    while (i < 2) {
        model = *(u8**)((u8*)param_1 + i * 0xA4 + 0x124);
        if (model != 0) {
            effect = *(u8**)(model + 0x18);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047d900((u32)effect, model + 8);
                func_0047d540((u32)effect, param_1);
            }
            effect = *(u8**)(model + 0x24);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047dd40((u32)effect, param_1);
            }
            if (*(u16*)(model + 0x30) > 0) {
                *(u16*)(model + 0x30) -= 1;
            }
        }
        i++;
    }
    j = 0;
    while (j < 5) {
        slot = (u8*)param_1 + j * 0xC;
        if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
            *(void**)(slot + 0x290) != 0 &&
            func_0047ae90(param_1, j) != 0) {
            model = *(u8**)(slot + 0x290);
            if ((*(u32*)(model + 0xD8) & 2) == 0 &&
                *(u8*)((u8*)param_1 + 0xD3) != 0) {
                if (*(s32*)(slot + 0x294) == -1) {
                    copyCount = 8;
                    copySource = (u32*)param_1;
                    copyTarget = (u32*)model;
                    do {
                        copyTarget[0] = copySource[0];
                        copyTarget[1] = copySource[1];
                        copySource += 2;
                        copyTarget += 2;
                        copyCount--;
                    } while (copyCount > 0);
                } else {
                    func_0047a510(param_1, *(s32*)(slot + 0x294),
                                  func_0047a2f0(model));
                }
                source = *(u8**)(model + 0xDC);
                material = *(u8**)(source + 4);
                func_003e05f0(&matrix0, model + 0x40, model);
                func_003e05f0(&matrix1, &matrix0, &identity);
                func_003e9cb0(material, &matrix1, 0);
                hasIndex = 0;
                hasItem = 0;
                needsReset = 0;
                animation = *(u8**)(model + 0x120);
                if (animation != 0 &&
                    *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                    hasIndex = 1;
                }
                if (hasIndex != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                    hasItem = 1;
                }
                if (hasItem != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                        != (void*)D_00922BC0_abs) {
                    needsReset = 1;
                }
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                    func_004746b0(model + 0x234, model + 0xEC);
                }
                func_00477260((u64)(u32)*(void**)(model + 0xDC), (u32*)color,
                                    (u16)((*(u8*)(model + 0x260) & 8) != 0));
                effect = *(u8**)((u8*)param_1 + 0xE0);
                if (effect == 0) {
                    func_003f6440(3, 0x7C01B);
                } else if (*(s32*)(effect + 0x10) != 0 ||
                           *(s32*)(effect + 0x1C) != 0) {
                    func_003f6440(3, 0x7F08B);
                } else {
                    func_003f6440(3, 0x7D7FB);
                }
                func_00479910(*(void**)(model + 0xDC));
                func_004789c0(model);
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                effect = *(u8**)(model + 0x2CC);
                if (effect != 0) {
                    func_0047d900((u32)effect, model + 0x80);
                    func_0047d540((u32)effect, model);
                }
                k = 0;
                while (k < 2) {
                    effect = *(u8**)(model + k * 0xA4 + 0x124);
                    if (effect != 0) {
                        source = *(u8**)(effect + 0x18);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047d900((u32)source, effect + 8);
                            func_0047d540((u32)source, model);
                        }
                        source = *(u8**)(effect + 0x24);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047dd40((u32)source, model);
                        }
                        if (*(u16*)(effect + 0x30) > 0) {
                            *(u16*)(effect + 0x30) -= 1;
                        }
                    }
                    k++;
                }
            }
        }
        j++;
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](0xE, renderState);
    func_003f6440(3, 0x717FB);
    renderStateSet[0](8, 1);
}
#undef renderState
#undef identity
#undef matrix1
#undef matrix0
#undef direction
#undef interpolation
#undef quaternion
#undef color

