/* Closest clean C candidate; reverted because lverify remained MISMATCH (object 760, window 752, normalized_diff 540). */
// FUN_001B7B30
u32 func_001b7b30(BtlMainColorWork* param_1)
{
    int iVar1;
    int iVar2;
    f32* pfVar3;
    u32* puVar4;
    f32 fVar5;
    u32 uVar6;
    f32 fVar7;
    f32 fVar8;
    f32 fVar9;
    f32 fVar11;
    f32 fVar12;
    f32 fVar13;
    f32 fVar15;
    f32 fVar16;
    f32 fVar17;

    if ((*(u32*)(iGpffffb3ac + 0xc) & 2) == 0)
        uVar6 = 1;
    else if ((*(u32*)(iGpffffb3ac + 0xc) & 0x02000000) == 0)
        uVar6 = 1;
    else
    {
        if (param_1->currentFrame == 0)
        {
            pfVar3 = func_00149ca0();
            fVar12 = pfVar3[1]; fVar5 = pfVar3[2]; fVar7 = pfVar3[3];
            param_1->value0 = *pfVar3; param_1->value1 = fVar12;
            param_1->value2 = fVar5; param_1->value3 = fVar7;
            pfVar3 = func_00149ce0();
            fVar12 = pfVar3[1]; fVar5 = pfVar3[2]; fVar7 = pfVar3[3];
            param_1->value4 = *pfVar3; param_1->value5 = fVar12;
            param_1->value6 = fVar5; param_1->value7 = fVar7;
        }
        iVar1 = (int)iGpffffb3ac;
        if (param_1->currentFrame < param_1->totalFrames)
        {
            fVar16 = (f32)param_1->currentFrame / (f32)param_1->totalFrames;
            fVar17 = 1.0f - fVar16;
            fVar7 = param_1->value0; fVar12 = param_1->value1;
            fVar8 = param_1->value2; fVar9 = param_1->value3;
            fVar15 = *(f32*)(iGpffffb3ac + 0x1bc) * fVar16;
            fVar11 = *(f32*)(iGpffffb3ac + 0x1c0) * fVar16;
            fVar13 = *(f32*)(iGpffffb3ac + 0x1c4) * fVar16;
            fVar5 = *(f32*)(iGpffffb3ac + 0x1c8) * fVar16;
            pfVar3 = func_00149ca0();
            *pfVar3 = fVar7 * fVar17 + fVar15;
            pfVar3[1] = fVar12 * fVar17 + fVar11;
            pfVar3[2] = fVar8 * fVar17 + fVar13;
            pfVar3[3] = fVar5 + fVar9 * fVar17;
            fVar5 = param_1->value4; fVar9 = *(f32*)(iGpffffb3ac + 0x1cc);
            fVar7 = param_1->value5; fVar11 = *(f32*)(iGpffffb3ac + 0x1d0);
            fVar12 = param_1->value6; fVar13 = *(f32*)(iGpffffb3ac + 0x1d4);
            fVar8 = param_1->value7; fVar15 = *(f32*)(iGpffffb3ac + 0x1d8);
            pfVar3 = func_00149ce0();
            *pfVar3 = fVar5 * fVar17 + fVar9 * fVar16;
            pfVar3[1] = fVar7 * fVar17 + fVar11 * fVar16;
            pfVar3[2] = fVar12 * fVar17 + fVar13 * fVar16;
            pfVar3[3] = fVar8 * fVar17 + fVar15 * fVar16;
            param_1->currentFrame++; uVar6 = 0;
        }
        else
        {
            puVar4 = (u32*)func_00149ca0(); iVar2 = (int)iGpffffb3ac;
            uVar6 = *(u32*)(iVar1 + 0x1c4);
            puVar4[0] = *(u32*)(iVar1 + 0x1bc); puVar4[1] = *(u32*)(iVar1 + 0x1c0);
            puVar4[2] = uVar6; puVar4[3] = *(u32*)(iVar1 + 0x1c8);
            puVar4 = (u32*)func_00149ce0(); uVar6 = *(u32*)(iVar2 + 0x1d4);
            puVar4[0] = *(u32*)(iVar2 + 0x1cc); puVar4[1] = *(u32*)(iVar2 + 0x1d0);
            puVar4[2] = uVar6; puVar4[3] = *(u32*)(iVar2 + 0x1d8); uVar6 = 1;
        }
    }
    return uVar6;
}
