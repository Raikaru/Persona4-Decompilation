/* func_0049e150 floor (measured 2026-09-17, source-repo): probe p3_both 495 BEST, fnalign 500/546/466, emitted 2184B/2000B (+9.2% over, banked per 100+word rule). measured loop+prop worth 28w/54ed. Residual s128/MMI/VU/frame. See effPolygonFlash.c guard. */
#pragma opt_loop_invariants on
#pragma opt_propagation off
void func_0049e150(u8 *arg0)
{
    u8 *temp_2;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 bVar;
    s32 iVar17;
    u32 *puVar15;
    u32 *puVar14;
    u32 c58;
    u32 c5c;
    f32 scale;
    s128 sp100 __attribute__((aligned(16)));
    s128 spF0 __attribute__((aligned(16)));
    s128 spD0 __attribute__((aligned(16)));
    s128 spC0 __attribute__((aligned(16)));
    s32 temp_18;
    s32 temp_21;
    s32 temp_22;
    f32 temp_24;
    f32 temp_25;
    f32 fVar21;
    f32 f27o;
    s32 iVar19;
    s32 iVar20;
    s8 cVar1;
    f32 fVar26;
    f32 t320;
    f32 t328;
    f32 f6c;
    u32 temp_6;
    u32 temp_7;
    s32 ecVal;
    s32 e8Val;
    s32 d0Val;
    f32 fVar18;
    f32 f25;

    temp_2 = *(u8 **)(arg0 + 0x40);
    temp_7 = *(u32 *)(temp_2 + 0x34);
    temp_6 = *(u32 *)(arg0 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(temp_2 + 0x38);
        *(s32 *)&sp100 = iVar4;
        iVar5 = *(s32 *)(temp_2 + 0x4C);
        if (iVar5 != 0)
        {
            if (*(s8 *)(temp_2 + 0x84) == 0)
            {
                ecVal = 0;
                e8Val = iVar5;
                d0Val = 1;
                *(s32 *)&spD0 = d0Val;
                iVar19 = (s32)(*(f32 *)(temp_2 + 0x44) * (f32)iVar5);
                *(s32 *)&sp100 = iVar19;
                iVar20 = (s32)(*(f32 *)(temp_2 + 0x48) * (f32)iVar5);
                *(s32 *)&spF0 = iVar20;
            }
            else
            {
                ecVal = iVar5;
                e8Val = 0;
                d0Val = -1;
                *(s32 *)&spD0 = d0Val;
                iVar19 = (s32)((1.0f - *(f32 *)(temp_2 + 0x48)) * (f32)iVar5);
                *(s32 *)&sp100 = iVar19;
                iVar20 = (s32)((1.0f - *(f32 *)(temp_2 + 0x44)) * (f32)iVar5);
                *(s32 *)&spF0 = iVar20;
            }
            if ((*(s8 *)(temp_2 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0))
            {
                bVar = 0;
                iVar17 = *(s32 *)(temp_2 + 0x50);
            }
            else
            {
                bVar = 1;
                iVar17 = (s32)sp100;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u32 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(temp_2 + 0x58);
            scale = fGpffff8044;
            c58 = (u32)((f32)(c58 & 0xFF) * scale);
            c5c = *(u32 *)(temp_2 + 0x5C);
            c5c = (u32)((f32)(c5c & 0xFF) * scale);
            fVar26 = *(f32 *)(temp_2 + 0x80);
            cVar1 = *(s8 *)(temp_2 + 0x54);
            spC0 = (s128)(s32)(s32)cVar1;
            temp_18 = 0;
            while (temp_18 < (s32)sp100)
            {
                temp_21 = *piVar16;
                if (temp_21 != -2)
                {
                    if (temp_21 == -1)
                    {
                        if (iVar17 != 0)
                        {
                            temp_24 = func_004bd0b0(0);
                            piVar16[2] = (s32)(fGpffff80d0 * temp_24);
                            f6c = *(f32 *)(temp_2 + 0x6C);
                            temp_24 = func_004bd0b0(0);
                            piVar16[3] = (s32)(*(f32 *)(temp_2 + 0x68) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            f6c = *(f32 *)(temp_2 + 0x74);
                            temp_24 = func_004bd0b0(0);
                            piVar16[4] = (s32)(*(f32 *)(temp_2 + 0x70) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            f6c = *(f32 *)(temp_2 + 0x7C);
                            temp_24 = func_004bd0b0(0);
                            piVar16[1] = (s32)(*(f32 *)(temp_2 + 0x78) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            f6c = *(f32 *)(temp_2 + 100);
                            temp_24 = func_004bd0b0(0);
                            piVar16[5] = (s32)(*(f32 *)(temp_2 + 0x60) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            if (bVar != 0)
                            {
                                temp_22 = func_004bd050(0);
                                *piVar16 = (s32)(temp_22 % (u32)iVar5);
                            }
                            else
                            {
                                *piVar16 = ecVal;
                            }
                            iVar17 += -1;
                        }
                    }
                    else if (temp_21 == e8Val)
                    {
                        s32 k;
                        k = 0;
                        while (k < 4)
                        {
                            puVar15[k * 3 + 0] = 0;
                            puVar15[k * 3 + 1] = 0;
                            puVar15[k * 3 + 2] = 0;
                            puVar14[k] = 0;
                            k++;
                        }
                        if ((s32)spC0 == 0)
                        {
                            temp_21 = -2;
                        }
                        else
                        {
                            temp_21 = -1;
                        }
                        *piVar16 = temp_21;
                    }
                    else
                    {
                        temp_24 = (f32)temp_21;
                        temp_25 = *(f32 *)(&piVar16[1]);
                        fVar21 = temp_24;
                        if (fVar26 < 0.0f)
                        {
                            f25 = -(float)piVar16[1] / (0.5f * fVar26);
                            fVar18 = 0.5f * fVar26;
                            f25 = f25 * 0.5f;
                            if (fVar21 <= f25)
                            {
                                fVar18 = fVar21;
                            }
                            else
                            {
                                fVar18 = f25;
                            }
                        }
                        else
                        {
                            fVar18 = fVar21;
                        }
                        f27o = fVar18 * (0.5f * fVar26 * fVar18 + (float)piVar16[1] + 0.0f) + (float)piVar16[2];
                        t320 = func_0044b610(*(f32 *)&piVar16[2]);
                        t328 = func_0044b7b0(*(f32 *)&piVar16[2]);
                        D_00713D10[0] = f27o;
                        D_00713D10[1] = t320;
                        D_00713D10[2] = t328;
                        puVar15[0] = (u32)D_00713D10[0];
                        puVar15[1] = (u32)D_00713D10[1];
                        puVar15[2] = (u32)D_00713D10[2];
                        puVar15[3] = (u32)D_00713D10[0];
                        puVar15[4] = (u32)D_00713D10[1];
                        puVar15[5] = (u32)D_00713D10[2];
                        puVar15[6] = (u32)f27o;
                        puVar15[7] = (u32)t320;
                        puVar15[8] = (u32)t328;
                        puVar15[9] = (u32)f27o;
                        puVar15[10] = (u32)t320;
                        puVar15[11] = (u32)t328;
                        if (temp_21 < (s32)sp100)
                        {
                            fVar21 = (f32)temp_21 / (f32)(s32)sp100;
                        }
                        else
                        {
                            fVar21 = 1.0f;
                            if ((s32)spF0 < temp_21)
                            {
                                fVar21 = (f32)(iVar5 - temp_21) / (f32)(iVar5 - (s32)spF0);
                            }
                        }
                        puVar14[0] = (u32)(fVar21 * 255.0f);
                        puVar14[1] = (u32)(fVar21 * 255.0f);
                        puVar14[2] = (u32)(fVar21 * 255.0f);
                        puVar14[3] = (u32)(fVar21 * 255.0f);
                        *piVar16 = temp_21 + (s32)spD0;
                    }
                    piVar16 += 6;
                    puVar15 += 12;
                    puVar14 += 4;
                }
                {
                    u8 *temp_17;
                    temp_17 = *(u8 **)(*(u32 **)(puVar3 + 8) + 6);
                    func_003c22f0(temp_17);
                    if (*(u16 *)puVar3 & 4)
                    {
                        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
                    }
                }
                temp_18++;
            }
        }
    }
}

#pragma opt_propagation on
#pragma opt_loop_invariants off
