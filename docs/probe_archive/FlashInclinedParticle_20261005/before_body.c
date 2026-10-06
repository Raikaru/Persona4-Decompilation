#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
    void func_004a0c00(u8 *effect)
    {
        u32 innerWord, outerWord, outerPacked, innerPacked;
        EffectVuVector innerColor, outerColor;
        EffectVuVector direction, widthVector, lengthVector;
        s32 firstFrame, count, index, fadeIn, fadeOut, initialAge, terminalAge, ageStep, recycle;
        u8 *state, *owner, *config;
        s32 *particle;
        f32 *pf;
        s32 life;
        FlashVertex *vertices;
        u32 *colors;
        f32 acceleration, distance, phase, inclination, fullTurn, unit, zero, half, byteScale, normalization, radius, cosine, factor, endpoint;
        const u32 *colorInput;
        u32 frame, lastFrame;
        s32 births;

        config = *(u8 **)(effect + 0x40);
        lastFrame = *(u32 *)(config + 0x34);
        frame = *(u32 *)(effect + 0x34);
        if (lastFrame < frame && lastFrame != 0) return;
        state = *(u8 **)(effect + 0x3c);
        particle = *(s32 **)state;
        owner = *(u8 **)(state + 4);
        count = *(s32 *)(config + 0x38);
        life = *(s32 *)(config + 0x4c);
        if (life == 0) return;
        if (*(u8 *)(config + 0x94)) {
            initialAge = life; terminalAge = 0; ageStep = -1;
            fadeIn = (s32)((1.0f - *(f32 *)(config + 0x48)) * (f32)life);
            fadeOut = (s32)((1.0f - *(f32 *)(config + 0x44)) * (f32)life);
        } else {
            initialAge = 0; terminalAge = life; ageStep = 1;
            fadeIn = (s32)(*(f32 *)(config + 0x44) * (f32)life);
            fadeOut = (s32)(*(f32 *)(config + 0x48) * (f32)life);
        }
        if (*(u8 *)(config + 0x55) != 0 && frame == 0) {
            firstFrame = 1;
            births = count;
        } else {
            firstFrame = 0;
            births = *(s32 *)(config + 0x50);
        }
        RpGeometryLock(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18), 10);
        vertices = *(FlashVertex **)(*(u8 **)(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18) + 0x5c) + 0x14);
        colors = *(u32 **)(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18) + 0x30);
        zero = 0.0f;
        direction.lane[1] = zero;
        direction.lane[3] = zero;
        innerWord = *(u32 *)(config + 0x58);
        colorInput = &innerWord;
        normalization = fGpffff8044;
        effectVuUnpackColor10(colorInput, normalization);
        effectVuStore10(&innerColor);
        outerWord = *(u32 *)(config + 0x5c);
        effectVuUnpackColor10(&outerWord, normalization);
        effectVuStore10(&outerColor);
        acceleration = *(f32 *)(config + 0x90);
        recycle = *(u8 *)(config + 0x54);
        index = 0;
        fullTurn = fGpffff80d0;
        unit = 1.0f;
        half = 0.5f;
        byteScale = 255.0f;
        for (; index < count; index++, particle += 8, vertices += 4, colors += 4) {
            s32 age = *particle;
            pf = (f32 *)particle;
            if (age == -2) continue;
            if (age == -1) {
                if (births == 0) continue;
    pf[2] = fullTurn * effMiscRandFloat(0);
    cosine = *(f32 *)(config + 0x6c);
    factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
    pf[3] = *(f32 *)(config + 0x68) * factor;
    cosine = *(f32 *)(config + 0x74);
    factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
    cosine = *(f32 *)(config + 0x70) * factor;
    radius = *(f32 *)(config + 0x7c);
    factor = 0.0f + (unit - radius) + radius * effMiscRandFloat(0);
    endpoint = *(f32 *)(config + 0x78) * factor;
    pf[4] = cosine;
    pf[5] = (endpoint - cosine) / (f32)life;
    cosine = *(f32 *)(config + 0x8c);
    factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
    pf[1] = *(f32 *)(config + 0x88) * factor;
    cosine = *(f32 *)(config + 0x64);
    factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
    pf[7] = *(f32 *)(config + 0x60) * factor;
    cosine = *(f32 *)(config + 0x84);
    factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
    pf[6] = *(f32 *)(config + 0x80) * factor;
                if (firstFrame) {
                    *particle = effMiscRand(0) % (u32)life;
                    
                } else {
                    *particle = initialAge;
                }
                births--;
                continue;
            }
            if (age == terminalAge) {
                s32 vertex;
                for (vertex = 0; vertex < 4; vertex++) {
                    vertices[vertex].x = zero;
                    vertices[vertex].y = zero;
                    vertices[vertex].z = zero;
                    colors[vertex] = 0;
                }
                *particle = recycle ? -1 : -2;
            } else {
                u32 transfer;
                EffectVuVector *scratch;
                f32 time = (f32)age;
                f32 fade;
                f32 sine;
                phase = pf[2];
    if (acceleration < zero) {
        f32 maximum = half * (-pf[1] / (half * acceleration));
        if (time > maximum) time = maximum;
    }
    distance = time * (0.0f + pf[1] + half * (acceleration * time));
    radius = 0.0f + pf[4] + pf[5] * time;
    inclination = pf[6];
    cosine = cosf(phase);
    sine = sinf(phase);
    direction.lane[0] = cosine * inclination;
    direction.lane[1] = unit - inclination;
    direction.lane[2] = sine * inclination;
    scratch = &direction;
    __asm__ volatile(
          "lqc2 $vf10, 0(%1) \n"
          "vmove.xyzw $vf11, $vf10 \n"
          "lw %0, %3 \n"
          "nop \n"
          "qmtc2.ni %0, $vf2 \n"
          "vmulx.xyzw $vf10, $vf10, $vf2x \n"
          : "=&r"(transfer) : "r"(scratch), "m"(*scratch), "m"(pf[3])
          : "$vf2", "$vf10", "$vf11");
      effectVuStore10(&lengthVector);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuScale10(distance);
    effectVuStore10(scratch);
    direction.lane[0] = 0.0f + direction.lane[0] + cosine * radius;
    direction.lane[2] = 0.0f + direction.lane[2] + sine * radius;
    effectVuSetX10(sine);
    __asm__ volatile(
        "qmtc2.ni %0, $vf2 \n"
        "vaddx.y $vf10, $vf0, $vf2x \n"
        : : "r"(zero) : "$vf2", "$vf10");
    effectVuSetZ10(-cosine);
    effectVuScale10(pf[7]);
    effectVuStore10(&widthVector);
    __asm__ volatile(
        "lqc2 $vf12, 0(%0) \n"
        : : "r"(scratch), "m"(*scratch) : "$vf12");
    effectVuLoad10(&lengthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad11(&widthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    scratch = (EffectVuVector *)D_00713D10;
    effectVuStore10(scratch);
    vertices[0].x = D_00713D10[0];
    vertices[0].y = D_00713D14[0];
    vertices[0].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10(scratch);
    vertices[1].x = D_00713D10[0];
    vertices[1].y = D_00713D14[0];
    vertices[1].z = D_00713D18[0];
    effectVuLoad10(&lengthVector);
    __asm__ volatile(
        "vsub.xyz $vf10, $vf0, $vf10 \n"
        "vadd.xyzw $vf10, $vf10, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad11(&widthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10(scratch);
    vertices[2].x = D_00713D10[0];
    vertices[2].y = D_00713D14[0];
    vertices[2].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10(scratch);
    vertices[3].x = D_00713D10[0];
    vertices[3].y = D_00713D14[0];
    vertices[3].z = D_00713D18[0];

                if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
                else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
                else fade = unit;
                effectVuLoad11((EffectVuVector *)D_00713CE0);
                effectVuScale11(fade);
                effectVuLoad10(&outerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, outerPacked \n"
            : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[0] = outerPacked;
                colors[1] = outerPacked;
                effectVuLoad10(&innerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, innerPacked \n"
            : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[2] = innerPacked;
                colors[3] = innerPacked;
                *particle = age + ageStep;
            }
        }
        {
            u8 *geometry = *(u8 **)(*(u8 **)(owner + 0x10) + 0x18);
            func_003c22f0(geometry);
            if (*(u16 *)owner & 4) *(u16 *)(geometry + 0xc) |= 1;
        }
    }
#pragma pop
