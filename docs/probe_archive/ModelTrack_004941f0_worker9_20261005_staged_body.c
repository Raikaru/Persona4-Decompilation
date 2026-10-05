#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
#pragma opt_propagation off
/* VU0 packed-color transport. C owns addresses, loops, and byte aggregates. */
void func_004941f0(u8 *track, u32 *colors)
{
    extern u8 *RpGeometryLock(u8 *geometry, s32 lockMode);
    extern u8 *func_003c22f0(u8 *geometry);
    extern f32 fGpffff8044;
    u32 *firstInput;
    u32 firstWord;
    u32 secondWord;
    u32 thirdWord;
    u32 fourthWord;
    u32 firstPacked;
    u32 secondPacked;
    EffectVuVector first;
    EffectVuVector third;
    EffectVuVector second;
    EffectVuVector fourth;
    EffectVuVector *firstVector;
    EffectVuVector *secondVector;
    EffectVuVector *thirdVector;
    EffectVuVector *fourthVector;
    u8 *work;
    u32 rowCount;
    u32 vertexCount;
    u32 segmentCount;
    u8 *destination;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 one;
    f32 scale;
    u32 index;
    u32 packedScaleBits;
    u32 rowBytes;
    u32 rowIndex;
    u8 *geometry;
    u8 *cap;
    u8 *capColors;
    u8 *nextCapRow;
    u32 capRowIndex;

    work = *(u8 **)(track + 0x10);
    RpGeometryLock(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 8);
    rowCount = *(s16 *)(work + 0x48);
    vertexCount = *(s16 *)(work + 8);
    segmentCount = vertexCount / 3U;
    destination = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x30);
    firstRow = destination;
    fractionStep = 1.0f / (f32)segmentCount;
    fraction = 0.0f;
    firstWord = colors[0];
    firstInput = &firstWord;
    scale = fGpffff8044;
    effectVuUnpackColor10(firstInput, scale);
    firstVector = &first;
    effectVuStore10(firstVector);
    secondWord = colors[1];
    effectVuUnpackColor10(&secondWord, scale);
    secondVector = &second;
    effectVuStore10(secondVector);
    thirdWord = colors[2];
    effectVuUnpackColor10(&thirdWord, scale);
    thirdVector = &third;
    effectVuStore10(thirdVector);
    fourthWord = colors[3];
    effectVuUnpackColor10(&fourthWord, scale);
    fourthVector = &fourth;
    effectVuStore10(fourthVector);
    index = 0;
    if (segmentCount != 0) {
        one = 1.0f;
        packedScaleBits = 0x437F0000U;
        goto gradient_check;
gradient_body: {
            f32 inverse;
            effectVuLoad11(firstVector);
            effectVuLoad10(thirdVector);
            effectVuScale10(fraction);
            inverse = one - fraction;
            effectVuScale11(inverse);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 packed;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    "vftoi0.xyzw $vf10, $vf10\n"
                    "qmfc2.ni %0, $vf10\n"
                    "ppach %0, $zero, %0\n"
                    "ppacb %0, $zero, %0\n"
                    "sw %0, firstPacked\n"
                    : "=&r"(packed), "=m"(firstPacked)
                    : "r"(packedScaleBits)
                    : "$vf2", "$vf10", "memory");
            }
            *(u32 *)(destination + 4) = firstPacked;
            effectVuLoad11(secondVector);
            effectVuLoad10(fourthVector);
            effectVuScale10(fraction);
            effectVuScale11(inverse);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 packed;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    "vftoi0.xyzw $vf10, $vf10\n"
                    "qmfc2.ni %0, $vf10\n"
                    "ppach %0, $zero, %0\n"
                    "ppacb %0, $zero, %0\n"
                    "sw %0, secondPacked\n"
                    : "=&r"(packed), "=m"(secondPacked)
                    : "r"(packedScaleBits)
                    : "$vf2", "$vf10", "memory");
            }
            *(u32 *)destination = secondPacked;
            *(Code1_0049Color *)(destination + 8) = *(Code1_0049Color *)destination;
            fraction += fractionStep;
            destination += 12;
            index++;
        }
gradient_check:
        if (index < segmentCount) goto gradient_body;
    }
    rowIndex = 1;
    rowBytes = vertexCount * 4;
    while (rowIndex < rowCount) {
        memcpy(destination, firstRow, rowBytes);
        destination += rowBytes;
        rowIndex++;
    }
    geometry = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)work & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
    cap = *(u8 **)(track + 0x14);
    RpGeometryLock(*(u8 **)(*(u8 **)(cap + 0x10) + 0x18), 8);
    capColors = *(u8 **)(*(u8 **)(*(u8 **)(cap + 0x10) + 0x18) + 0x30);
    *(u32 *)capColors = colors[0];
    *(u32 *)(capColors + 4) = colors[1];
    *(Code1_0049Color *)(capColors + 8) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 12) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 16) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 20) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 24) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 28) = *(Code1_0049Color *)(capColors + 4);
    nextCapRow = capColors + 32;
    capRowIndex = 1;
    while (capRowIndex < rowCount) {
        memcpy(nextCapRow, capColors, 32);
        nextCapRow += 32;
        capRowIndex++;
    }
    geometry = *(u8 **)(*(u8 **)(cap + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)cap & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}

#pragma pop
