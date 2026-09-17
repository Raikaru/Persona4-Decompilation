/* func_0049d360 floor update (measured 2026-09-17, source-repo): guard 465w -> prop 461w/451ed WINNER (loop 463w/352ed fewer edits noted), fnalign 493/482/451, emitted 1928B/1984B (97.2%%). Residual saved/FP + COP2 + MMI + s128. See effPolygonFlash.c guard. */
#pragma push
#pragma opt_propagation off
void func_0049d360(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_21;
    s32 temp_22;
    f32 temp_24;
    f32 temp_25;
    f32 temp_26;
    f32 scale;
    f32 fVar9;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 iVar6;
    s32 bVar7;
    s32 iVar17;
    s32 iVar18;
    s32 iVar19;
    s32 iVar20;
    f32 fVar21;
    u32 uVar22;
    u32 uVar23;
    u32 *puVar15;
    u32 *puVar14;
    u32 c58;
    u32 c5c;
    s32 *pt58;
    s32 *pt5c;
    s128 au13;
    s128 au27;
    s128 au28;
    s128 au29;
    s128 au30;
    s128 au31;
    s128 au32;
    s128 au33;
    u32 temp_6;
    u32 temp_7;
    f32 t320;
    f32 t328;
    f32 f6c;
    f32 f27o;
    s8 cVar1;

    temp_2 = *(u8 **)(arg0 + 0x40);
    temp_7 = *(u32 *)(temp_2 + 0x34);
    temp_6 = *(u32 *)(arg0 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(temp_2 + 0x38);
        iVar5 = *(s32 *)(temp_2 + 0x4C);
        if (iVar5 != 0)
        {
            if ((*(s8 *)(temp_2 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0))
            {
                bVar7 = 0;
                iVar17 = *(s32 *)(temp_2 + 0x50);
            }
            else
            {
                bVar7 = 1;
                iVar17 = iVar4;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u32 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(temp_2 + 0x58);
            pt58 = (s32 *)&c58;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt58), "f"(scale), "r"(&au13)
                : "$2", "$vf2", "$vf10", "memory");
            c5c = *(u32 *)(temp_2 + 0x5C);
            pt5c = (s32 *)&c5c;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt5c), "f"(scale), "r"(&au27)
                : "$2", "$vf2", "$vf10", "memory");
            iVar19 = (s32)(*(f32 *)(temp_2 + 0x44) * (f32)iVar5);
            iVar20 = (s32)(*(f32 *)(temp_2 + 0x48) * (f32)iVar5);
            temp_26 = *(f32 *)(temp_2 + 0x7C);
            iVar6 = *(s32 *)(temp_2 + 0x70);
            cVar1 = *(s8 *)(temp_2 + 0x54);
            fVar9 = 0.5f;
            temp_18 = 0;
            while (temp_18 < iVar4)
            {
                temp_21 = *piVar16;
                if (temp_21 != -2)
                {
                    if (temp_21 == -1)
                    {
                        if (iVar17 != 0)
                        {
                            temp_24 = func_004bd0b0(0);
                            piVar16[2] = (s32)(scale * temp_24);
                            f6c = *(f32 *)(temp_2 + 0x78);
                            temp_24 = func_004bd0b0(0);
                            piVar16[1] = (s32)(*(f32 *)(temp_2 + 0x74) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            temp_22 = func_004bd050(0);
                            if ((temp_22 & 1) != 0)
                            {
                                piVar16[1] = (s32)((f32)piVar16[1] * -1.0f);
                            }
                            piVar16[3] = 0;
                            f6c = *(f32 *)(temp_2 + 0x6C);
                            temp_24 = func_004bd0b0(0);
                            piVar16[4] = (s32)((*(f32 *)(temp_2 + 0x68) * (0.0f + (1.0f - f6c) + f6c * temp_24)) / (f32)iVar6);
                            f6c = *(f32 *)(temp_2 + 100);
                            temp_24 = func_004bd0b0(0);
                            piVar16[5] = (s32)(*(f32 *)(temp_2 + 0x60) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            if (bVar7 != 0)
                            {
                                temp_22 = func_004bd050(0);
                                *piVar16 = (s32)(temp_22 % (u32)iVar5);
                                piVar16[3] = (s32)(0.0f + (f32)piVar16[3] + (f32)piVar16[4] * (f32)((temp_22 % (u32)iVar5) % iVar6));
                            }
                            else
                            {
                                *piVar16 = 0;
                            }
                            iVar17 += -1;
                        }
                    }
                    else if (temp_21 < iVar5)
                    {
                        temp_24 = (f32)temp_21;
                        temp_25 = *(f32 *)(&piVar16[1]);
                        if (0.0f < temp_25)
                        {
                            temp_25 = 0.0f + temp_25 + fVar9 * (temp_26 * temp_24);
                        }
                        else
                        {
                            temp_25 = 0.0f + temp_25 - fVar9 * (temp_26 * temp_24);
                        }
                        f27o = temp_24 * temp_25 + (f32)piVar16[2];
                        if (temp_21 < iVar6)
                        {
                            piVar16[3] = (s32)((f32)piVar16[3] + (f32)piVar16[4]);
                        }
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "vmove.xyzw $vf10, $vf11  \n"
                            "lw $2, 20(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            :
                            : "r"(D_00713CE0), "r"(piVar16), "r"(&au31), "r"(&au29)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        t320 = func_0044b610(fVar21);
                        t328 = func_0044b7b0(fVar21);
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "qmfc2 $2, $vf10          \n"
                            "mtc1 $2, $f1             \n"
                            "qmfc2 $2, $vf10          \n"
                            "pexew $2, $2             \n"
                            "mtc1 $2, $f0             \n"
                            "nop                      \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.x $vf10x, $vf0x, $vf2x \n"
                            "mfc1 $2, $f1             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.z $vf10z, $vf0z, $vf2x \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf10, $vf12  \n"
                            "lqc2 $vf11, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 24(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 28(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 32(%4)         \n"
                            "vsub.xyz $vf11xyz, $vf0xyz, $vf11xyz \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 36(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 40(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 44(%4)         \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "vadd.xyzw $vf10, $vf10, $vf12 \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 0(%4)          \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 4(%4)          \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 8(%4)          \n"
                            "vadd.xyzw $vf11, $vf11, $vf12 \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 12(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 16(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 20(%4)         \n"
                            :
                            : "r"(&t320), "r"(&au29), "r"(&au31), "r"(D_00713D10), "r"(puVar15)
                            : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        if (temp_21 < iVar19)
                        {
                            fVar21 = (f32)temp_21 / (f32)iVar19;
                        }
                        else
                        {
                            fVar21 = 1.0f;
                            if (iVar20 < temp_21)
                            {
                                fVar21 = (f32)(iVar5 - temp_21) / (f32)(iVar5 - iVar20);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, $f20            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%3)             \n"
                            "lw $2, 0(%3)             \n"
                            "sw $2, 0(%4)             \n"
                            "sw $2, 4(%4)             \n"
                            "lqc2 $vf10, 0(%5)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, $f20            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%6)             \n"
                            "lw $2, 0(%6)             \n"
                            "sw $2, 8(%4)             \n"
                            "sw $2, 12(%4)            \n"
                            :
                            : "r"(D_00713CE0), "f"(fVar21), "r"(&au29), "r"(&au32), "r"(puVar14), "r"(&au13), "r"(&au30)
                            : "$2", "$vf2", "$vf10", "$vf11", "$f20", "memory");
                        *piVar16 = temp_21 + 1;
                    }
                    else
                    {
                        for (temp_21 = 0; temp_21 < 4; temp_21++)
                        {
                            puVar15[temp_21 * 3 + 0] = 0;
                            puVar15[temp_21 * 3 + 1] = 0;
                            puVar15[temp_21 * 3 + 2] = 0;
                            puVar14[temp_21] = 0;
                        }
                        if (cVar1 == 0)
                        {
                            temp_21 = -2;
                        }
                        else
                        {
                            temp_21 = -1;
                        }
                        *piVar16 = temp_21;
                    }
                    piVar16 += 6;
                    puVar15 += 12;
                    puVar14 += 4;
                }
                temp_17 = *(u8 **)(*(u32 **)(puVar3 + 8) + 6);
                func_003c22f0(temp_17);
                if (*(u16 *)puVar3 & 4)
                {
                    *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
                }
            }
        }
    }
}
#pragma pop
