/* object=1064 window=1136 nd=740; differing_offsets=0x0-0x41C (257 differing words); deficit=18 instructions; classification=reconstruction-scale undersized candidate (frame 416 vs retail 448, candidate omits retail saved $s4/$s5); ruled_out=no floor claim (retail has scalar COP1 only, no COP2/VU0 or standalone MMI); triage-only after one donor-body measurement with opt_loop_invariants/opt_lifetimes. */
u64 func_00275d80(f32 param_1, s32 param_2, s32 param_3, u32 *param_4,
                  s32 param_5, s32 param_6, s32 param_7, u32 param_8)
{
    float fVar1;
    float fVar2;
    int iVar5;
    float *pfVar4;
    int iVar3;
    float *pfVar6;
    int iVar7;
    float *pfVar8;
    u32 *puVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float afStack_100[64];
    float afStack_120[8];
    float fStack_12c;
    float fStack_128;
    float fStack_124;
    float afStack_140[5];

    fVar12 = (float)param_2 / 16.0f;
    fVar11 = (float)param_3 / 8.0f;
    iVar5 = (int)func_00457120();
    fVar10 = *(float *)(iVar5 + 0x80);
    pfVar6 = (float *)D_0063bcc0;
    pfVar8 = afStack_120;
    iVar5 = 4;
    do {
        fVar1 = *pfVar6;
        fVar2 = pfVar6[1];
        pfVar6 = pfVar6 + 2;
        iVar5 = iVar5 + -1;
        *pfVar8 = fVar1;
        pfVar8[1] = fVar2;
        pfVar8 = pfVar8 + 2;
    } while (0 < iVar5);
    pfVar6 = (float *)0x20;
    pfVar8 = afStack_140;
    pfVar4 = pfVar8;
    while (pfVar4 != (float *)0x0) {
        *(u8 *)pfVar8 = 0;
        pfVar8 = (float *)((int)pfVar8 + 1);
        pfVar6 = (float *)((int)pfVar6 + -1);
        pfVar4 = pfVar6;
    }
    if (param_6 >= 0) {
        afStack_140[2] = (float)(int)param_6;
    } else {
        afStack_140[2] = (float)(param_6 & 0xffffffff);
    }
    afStack_140[2] = fVar12 + afStack_140[2];
    if (param_7 >= 0) {
        fStack_12c = (float)(int)param_7;
    } else {
        fStack_12c = (float)(param_7 & 0xffffffff);
    }
    fStack_124 = fVar11 + fStack_12c;
    iVar5 = (int)param_4;
    afStack_140[0] = fVar12;
    afStack_140[1] = fVar11;
    afStack_140[3] = fVar11;
    afStack_140[4] = fVar12;
    fStack_128 = afStack_140[2];
    if (*(int *)(iVar5 + 0x1c) == 0) {
        func_0046d730(D_0063bc88, 0x9b);
    }
    puVar9 = *(u32 **)(*(int *)(iVar5 + 0x1c) + 0xc);
    if ((short)puVar9[2] != param_5) {
        iVar7 = (int)func_00271f50(param_4, puVar9[1]);
        *(short *)(*(int *)(iVar5 + 0x1c) + 4) =
            *(short *)(*(int *)(iVar5 + 0x1c) + 4) + -1;
        iVar3 = *(int *)(iVar5 + 0x1c);
        if ((iVar3 != 0) && (*(short *)(iVar3 + 4) == 0)) {
            puVar9 = *(u32 **)(iVar3 + 0xc);
            if (puVar9 != (u32 *)0x0) {
                *puVar9 = *puVar9 & 0xfffffffe;
                puVar9[4] = 0;
            }
            func_00271310(*(u32 *)(iVar3 + 8));
            DAT_00881750_abs[0] = DAT_00881750_abs[0] + -1;
        }
        *(int *)(iVar5 + 0x1c) = iVar7;
        puVar9 = *(u32 **)(iVar7 + 0xc);
    }
    *puVar9 = *puVar9 | 1;
    if ((param_8 & 0xff) != 0) {
        func_0043f9c8(afStack_100, 0, 0x100);
        for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
            afStack_100[iVar5 * 0x10 + 2] =
                D_008872f8[0] - param_1;
            afStack_100[iVar5 * 0x10 + 6] = 1.0f / fVar10;
            afStack_100[iVar5 * 0x10 + 4] = afStack_120[iVar5 * 2];
            afStack_100[iVar5 * 0x10 + 5] = afStack_120[iVar5 * 2 + 1];
            afStack_100[iVar5 * 0x10 + 8] = (float)(param_8 >> 0x18);
            afStack_100[iVar5 * 0x10 + 9] =
                (float)(param_8 >> 0x10 & 0xff);
            afStack_100[iVar5 * 0x10 + 10] =
                (float)(param_8 >> 8 & 0xff);
            afStack_100[iVar5 * 0x10 + 0xb] =
                (float)(param_8 & 0xff);
            afStack_100[iVar5 * 0x10] = afStack_140[iVar5 * 2];
            afStack_100[iVar5 * 0x10 + 1] =
                afStack_140[iVar5 * 2 + 1];
        }
        D_00887300[0](1, puVar9[5]);
        D_00887310[0](4, afStack_100, 4);
    }
    return 0;
}
