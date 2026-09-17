/* func_0049aa30 floor (measured 2026-09-17, source-repo): probe u8+loop 488 FINAL, fnalign 540/528/297, emitted 2112B/2176B (97.06%% PASS by 1B). measured loop worth 27w/54ed. Residual s128/MMI/VU/daddu. See effPolygonFlash.c guard. */
#pragma opt_loop_invariants on
void func_0049aa30(u8 *arg0)
{
    u8 *tmp40;
    u32 outer_ge;
    u32 outer_arg34;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 bVar;
    s32 iVar17;
    u32 *puVar15;
    u8 *puVar14;
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
    s32 iVar19;
    s32 iVar20;
    f32 f80d0;
    f32 scale;
    f32 fTmp;
    f32 fA;
    f32 fB;
    f32 fC;
    f32 fD;
    f32 fSin;
    f32 fCos;
    f32 f27save;
    s32 loop;
    s32 cur;
    s32 tmp22;
    f32 f1tmp;
    f32 f2tmp;
    u8 cVar1;

    tmp40 = *(u8 **)(arg0 + 0x40);
    outer_ge = *(u32 *)(tmp40 + 0x34);
    outer_arg34 = *(u32 *)(arg0 + 0x34);
    if ((outer_ge >= outer_arg34) || (outer_ge == 0)) {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(tmp40 + 0x38);
        iVar5 = *(s32 *)(tmp40 + 0x4C);
        if (iVar5 != 0) {
            if ((*(u8 *)(tmp40 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0)) {
                bVar = 0;
                iVar17 = *(s32 *)(tmp40 + 0x50);
            } else {
                bVar = 1;
                iVar17 = iVar4;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u8 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(tmp40 + 0x58) & 0xFFFFFF;
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
            c5c = *(u32 *)(tmp40 + 0x5C) & 0xFFFFFF;
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
            iVar19 = (s32)(*(f32 *)(tmp40 + 0x44) * (f32)iVar5);
            iVar20 = (s32)(*(f32 *)(tmp40 + 0x48) * (f32)iVar5);
            f27save = *(f32 *)(tmp40 + 0x7C);
            cVar1 = *(u8 *)(tmp40 + 0x54);
            f80d0 = fGpffff80d0;
            loop = 0;
            while (loop < iVar4) {
                cur = *piVar16;
                if (cur != -2) {
                    if (cur == -1) {
                        if (iVar17 != 0) {
                            fTmp = func_004bd0b0(0);
                            piVar16[2] = (s32)(f80d0 * fTmp);
                            fC = *(f32 *)(tmp40 + 0x78);
                            fTmp = func_004bd0b0(0);
                            piVar16[1] = (s32)(*(f32 *)(tmp40 + 0x74) * (0.0f + (1.0f - fC) + fC * fTmp));
                            tmp22 = func_004bd050(0);
                            if ((tmp22 & 1) != 0) {
                                piVar16[1] = (s32)((f32)piVar16[1] * -1.0f);
                            }
                            fC = *(f32 *)(tmp40 + 0x70);
                            fTmp = func_004bd0b0(0);
                            piVar16[3] = (s32)(*(f32 *)(tmp40 + 0x6C) * (0.0f + (1.0f - fC) + fC * fTmp));
                            fC = *(f32 *)(tmp40 + 0x68);
                            fTmp = func_004bd0b0(0);
                            f1tmp = (0.0f + (1.0f - fC) + fC * fTmp);
                            piVar16[4] = (s32)(*(f32 *)(tmp40 + 0x60) * f1tmp);
                            piVar16[5] = (s32)(*(f32 *)(tmp40 + 0x64) * f1tmp);
                            if (bVar != 0) {
                                tmp22 = func_004bd050(0);
                                *piVar16 = (s32)(tmp22 % (u32)iVar5);
                            } else {
                                *piVar16 = 0;
                            }
                            iVar17 += -1;
                        }
                    } else if (cur < iVar5) {
                        f1tmp = (f32)cur;
                        f2tmp = *(f32 *)(&piVar16[1]);
                        if (0.0f < f2tmp) {
                            f2tmp = 0.0f + f2tmp + 0.5f * (f27save * f1tmp);
                        } else {
                            f2tmp = 0.0f + f2tmp - 0.5f * (f27save * f1tmp);
                        }
                        fD = f1tmp * f2tmp + (f32)piVar16[2];
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "vmove.xyzw $vf10, $vf11  \n"
                            "lw $2, 16(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "lw $2, 20(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "sqc2 $vf11, 0(%4)        \n"
                            :
                            : "r"(D_00713CE0), "r"(piVar16), "r"(&au31), "r"(&au29), "r"(&au28)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        fSin = func_0044b610(fD);
                        fCos = func_0044b7b0(fD);
                        {
                            f32 _s = fSin;
                            f32 _c = fCos;
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
                                "swc1 $f0, 48(%4)         \n"
                                "lwc1 $f0, 4(%3)          \n"
                                "swc1 $f0, 52(%4)         \n"
                                "lwc1 $f0, 8(%3)          \n"
                                "swc1 $f0, 56(%4)         \n"
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
                                : "r"(&_s), "r"(&au29), "r"(&au31), "r"(D_00713D10), "r"(puVar15)
                                : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        }
                        if (cur < iVar19) {
                            fD = (f32)cur / (f32)iVar19;
                        } else {
                            fD = 1.0f;
                            if (iVar20 < cur) {
                                fD = (f32)(iVar5 - cur) / (f32)(iVar5 - iVar20);
                            }
                        }
                        {
                            u32 col0;
                            u32 col1;
                            f32 fade = fD;
                            __asm__ volatile(
                                "lqc2 $vf11, 0(%0)        \n"
                                "mfc1 $2, %1              \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "lqc2 $vf10, 0(%2)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "mfc1 $2, $f21            \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vftoi0.xyzw $vf10, $vf10 \n"
                                "qmfc2 $2, $vf10          \n"
                                "ppach $2, $0, $2         \n"
                                "ppacb $2, $0, $2         \n"
                                "sw $2, 0(%3)             \n"
                                :
                                : "r"(D_00713CE0), "f"(fade), "r"(&au27), "r"(&au32)
                                : "$2", "$vf2", "$vf10", "$vf11", "$f21", "memory");
                            col0 = *(u32 *)&au32;
                            *(u32 *)puVar14 = col0;
                            puVar14[4] = puVar14[0];
                            puVar14[5] = puVar14[1];
                            puVar14[6] = puVar14[2];
                            puVar14[7] = puVar14[3];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "mfc1 $2, $f21            \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vftoi0.xyzw $vf10, $vf10 \n"
                                "qmfc2 $2, $vf10          \n"
                                "ppach $2, $0, $2         \n"
                                "ppacb $2, $0, $2         \n"
                                "sw $2, 0(%1)             \n"
                                :
                                : "r"(&au13), "r"(&au30)
                                : "$2", "$vf2", "$vf10", "$vf11", "$f21", "memory");
                            col1 = *(u32 *)&au30;
                            if ((loop & 1) != 0) {
                                *(u32 *)(puVar14 + 12) = col1 | 0xFF000000;
                                fA = 128.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(puVar14 + 8) = _s;
                                    *(s32 *)(puVar14 + 16) = _s;
                                }
                            } else {
                                *(u32 *)(puVar14 + 12) = col1 | 0x40000000;
                                fA = 255.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(puVar14 + 8) = _s;
                                    *(s32 *)(puVar14 + 16) = _s;
                                }
                            }
                        }
                        *piVar16 = cur + 1;
                    } else {
                        s32 k;
                        for (k = 0; k < 5; k++) {
                            ((f32 *)puVar15)[k * 3 + 0] = 0.0f;
                            ((f32 *)puVar15)[k * 3 + 1] = 0.0f;
                            ((f32 *)puVar15)[k * 3 + 2] = 0.0f;
                            ((u32 *)puVar14)[k] = 0;
                        }
                        if (cVar1 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        *piVar16 = cur;
                    }
                }
                piVar16 += 6;
                puVar15 += 15;
                puVar14 += 20;
                loop += 1;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(puVar3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)puVar3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}

#pragma opt_loop_invariants off
