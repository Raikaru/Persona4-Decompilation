void func_00471370(u8 *param_1, u8 *param_2, u8 *param_3, void *param_4)

{
    extern unsigned long long func_003d5790(unsigned int, unsigned int);
    extern long func_003e9240(int);
    extern unsigned int func_003e9700(int);
    extern unsigned int func_0044b920(float);
    extern unsigned int func_0044b950(float, float);
    extern int func_003d5e40(unsigned char *, float);
    extern int func_003d5e90(unsigned char *, unsigned char *, unsigned char *, float);
    extern float func_004bd4a0(unsigned char *, unsigned char *);
    extern s32 func_003954b0();
    extern s32 func_00397c40();
    extern s32 func_003d5840();
    extern s32 func_003dc610();
    extern s32 func_003dc740();
    extern s32 func_003dcb40();
    extern s32 func_003dcc70();
    extern s32 func_003e05f0();
    extern s32 func_003e0870();
    extern s32 func_003e0960();
    extern s32 func_003e0a90();
    extern s32 func_003e40b0();
    extern s32 func_003e42a0();
    extern s32 func_003e4320();
    extern s32 func_003e9680();
    extern s32 func_003ed960();
/* irregular: 19 native warning(s); review required */
    extern s32 DAT_0088739c;
    extern s32 DAT_00922bb0;
    extern s32 DAT_00922bb4;
    extern float fGpffff8040;
    extern float fGpffff8048;
    extern float fGpffff804c;
    extern float fGpffff8050;
    extern float fGpffff8054;
    extern float fGpffff8058;
    extern float fGpffff805c;
    extern float fGpffff8060;
    extern float fGpffff8064;
    extern float fGpffff8068;
    extern float fGpffff806c;
    extern float fGpffff8070;
    extern float fGpffff8074;
  unsigned short temp_v0;
  code *pcVar2;
  unsigned int *puVar3;
  int *piVar4;
  unsigned char temp_v1;
  unsigned char temp_v2;
  unsigned int temp_v3;
  float *pfVar8;
  long temp_v4;
  unsigned long long temp_v5;
  unsigned int temp_v6;
  unsigned int *puVar12;
  int temp_v7;
  int temp_v8;
  int temp_v9;
  float *pfVar16;
  float *pfVar17;
  unsigned int temp_v10;
  unsigned char *pbVar19;
  int temp_v11;
  float *pfVar21;
  unsigned int *puVar22;
  unsigned int temp_v12;
  unsigned int temp_v13;
  float temp_v14;
  float temp_v15;
  float temp_v16;
  unsigned int temp_v17;
  float temp_v18;
  float temp_v19;
  float temp_v20;
  float temp_v21;
  int iStack_450;
  unsigned int uStack_430;
  int iStack_420;
  unsigned char temp_v22 [64];
  int uStack_3c0;
  unsigned int uStack_3bc;
  unsigned int uStack_3b8;
  unsigned int uStack_3b4;
  float fStack_3b0;
  float fStack_3ac;
  float fStack_3a8;
  float fStack_3a4;
  float fStack_3a0;
  float fStack_39c;
  float fStack_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  float fStack_368;
  float fStack_364;
  float fStack_360;
  int iStack_35c;
  float fStack_350;
  float fStack_34c;
  float fStack_348;
  float fStack_344;
  float fStack_340;
  float fStack_33c;
  float fStack_338;
  float fStack_334;
  float fStack_330;
  float fStack_32c;
  float fStack_328;
  unsigned int uStack_324;
  float fStack_320;
  float fStack_31c;
  float fStack_318;
  float fStack_310;
  float fStack_30c;
  float fStack_308;
  float fStack_300;
  float fStack_2fc;
  float fStack_2f8;
  unsigned char temp_v23 [64];
  unsigned char temp_v24 [64];
  unsigned char temp_v25 [16];
  unsigned char temp_v26 [48];
  float fStack_230;
  float fStack_22c;
  float fStack_228;
  unsigned int uStack_224;
  float fStack_220;
  float fStack_21c;
  float fStack_218;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  unsigned int uStack_200;
  unsigned int uStack_1fc;
  unsigned int uStack_1f8;
  float afStack_1f0 [16];
  float afStack_1b0 [17];
  unsigned int temp_v27 [31];
  float afStack_f0 [3];
  unsigned int uStack_e4;
  unsigned int uStack_e0;
  unsigned int uStack_dc;
  unsigned int uStack_d8;
  unsigned int uStack_d0;
  unsigned int uStack_cc;
  unsigned int uStack_c8;
  unsigned int uStack_c0;
  unsigned int uStack_bc;
  unsigned int uStack_b8;
  float afStack_b0 [8];
  unsigned int uStack_90;
  unsigned int uStack_8c;
  unsigned int uStack_88;
  unsigned int uStack_80;
  unsigned int uStack_7c;
  unsigned int uStack_78;
  int uStack_70;
  unsigned int uStack_6c;
  unsigned int uStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  int uStack_10;
  unsigned int uStack_c;
  unsigned int uStack_8;
  
  temp_v1 = 0;
  temp_v3 = 0;
  temp_v2 = 0;
  puVar12 = (unsigned int *)param_1;
  temp_v10 = *puVar12;
  if (((temp_v10 & 1) == 0) || (puVar12[7] == 0xffffffff)) {
    if ((temp_v10 & 0x4000) == 0) {
      temp_v1 = 1;
      temp_v3 = puVar12[5];
      pfVar21 = afStack_b0;
    }
    else {
      uStack_c8 = 0x3f800000;
      uStack_dc = 0x3f800000;
      afStack_f0[0] = 1.0;
      uStack_e0 = 0;
      afStack_f0[2] = 0.0;
      afStack_f0[1] = 0.0;
      uStack_cc = 0;
      uStack_d0 = 0;
      uStack_d8 = 0;
      uStack_b8 = 0;
      uStack_bc = 0;
      uStack_c0 = 0;
      uStack_e4 = uStack_e4 | 0x20003;
      pfVar21 = afStack_f0;
      if ((temp_v10 & 0x2000) != 0) {
        temp_v1 = 1;
        temp_v3 = puVar12[5];
      }
    }
  }
  else {
    pfVar21 = (float *)(*(int *)(puVar12[6] + 8) + puVar12[7] * 0x40);
    if (((temp_v10 & 0x2000) != 0) && ((temp_v10 & 0x4000) != 0)) {
      temp_v1 = 1;
      temp_v3 = *(unsigned int *)(puVar12[6] + 0x14);
    }
  }
  if (temp_v1) {
    if ((temp_v3 == 0) || (temp_v9 = *(int *)(temp_v3 + 4), temp_v9 == 0)) {
      uStack_88 = 0x3f800000;
      afStack_b0[5] = 1.0;
      afStack_b0[0] = 1.0;
      afStack_b0[4] = 0.0;
      afStack_b0[2] = 0.0;
      afStack_b0[1] = 0.0;
      uStack_8c = 0;
      uStack_90 = 0;
      afStack_b0[6] = 0.0;
      uStack_78 = 0;
      uStack_7c = 0;
      uStack_80 = 0;
      afStack_b0[3] = (float)((unsigned int)afStack_b0[3] | 0x20003);
    }
    else {
      temp_v4 = func_003e9240(temp_v9);
      if (temp_v4 == 0) {
        pfVar8 = (float *)func_003e9700(temp_v9);
        pfVar16 = afStack_b0;
        temp_v9 = 8;
        do {
          temp_v21 = *pfVar8;
          temp_v20 = pfVar8[1];
          pfVar8 = pfVar8 + 2;
          temp_v9 = temp_v9 - 1;
          *pfVar16 = temp_v21;
          pfVar16[1] = temp_v20;
          pfVar16 = pfVar16 + 2;
        } while (0 < temp_v9);
      }
      else {
        pfVar16 = (float *)(temp_v9 + 0x10);
        pfVar8 = afStack_b0;
        temp_v11 = 8;
        do {
          temp_v21 = *pfVar16;
          temp_v20 = pfVar16[1];
          pfVar16 = pfVar16 + 2;
          temp_v11 = temp_v11 - 1;
          *pfVar8 = temp_v21;
          pfVar8[1] = temp_v20;
          pfVar8 = pfVar8 + 2;
        } while (0 < temp_v11);
        for (temp_v9 = *(int *)(temp_v9 + 4); temp_v9 != 0; temp_v9 = *(int *)(temp_v9 + 4)) {
          pfVar16 = afStack_b0;
          pfVar8 = afStack_1f0;
          temp_v11 = 4;
          do {
            temp_v5 = *(unsigned long long *)pfVar16;
            temp_v21 = pfVar16[2];
            temp_v20 = pfVar16[3];
            pfVar16 = pfVar16 + 4;
            temp_v11 = temp_v11 - 1;
            *pfVar8 = (float)temp_v5;
            pfVar8[1] = (float)((unsigned long long)temp_v5 >> 0x20);
            pfVar8[2] = temp_v21;
            pfVar8[3] = temp_v20;
            pfVar8 = pfVar8 + 4;
          } while (0 < temp_v11);
          func_003e05f0(afStack_b0,afStack_1f0,temp_v9 + 0x10);
        }
      }
    }
  }
  temp_v3 = temp_v10 & 0x2000;
  if ((temp_v3 != 0) && ((*(unsigned char *)(*(int *)(puVar12[5] + 0xa0) + 3) & 3) == 0)) {
    *(int *)(*(int *)(puVar12[5] + 0xa0) + 8) = DAT_0088739c;
    *(int **)(*(int *)(puVar12[5] + 0xa0) + 0xc) = &DAT_0088739c;
    *(int *)(DAT_0088739c + 4) = *(int *)(puVar12[5] + 0xa0) + 8;
    temp_v9 = *(int *)(puVar12[5] + 0xa0);
    DAT_0088739c = temp_v9 + 8;
    *(unsigned char *)(temp_v9 + 3) = *(unsigned char *)(temp_v9 + 3) | 2;
  }
  temp_v6 = puVar12[8];
  pcVar2 = *(code **)(temp_v6 + 0x3c);
  temp_v9 = *(int *)(temp_v6 + 0x24);
  puVar22 = temp_v27;
  uStack_430 = puVar12[4];
  pfVar8 = (float *)puVar12[2];
  temp_v11 = temp_v6 + 0x4c;
  puVar3 = *(unsigned int **)((short)param_2[2] * 0x50 + **(int **)(param_2 + 0x1a) + 0x48);
  if ((puVar3 == (unsigned int *)0x0) || (*(float *)(param_2 + 4) != 0.0)) {
    for (iStack_420 = 0; iStack_420 < (int)puVar12[1]; iStack_420 = iStack_420 + 1) {
      if (*pcVar2 == func_003954b0) {
        temp_v14 = *(float *)(temp_v11 + 8);
        temp_v15 = *(float *)(temp_v11 + 0xc);
        temp_v21 = *(float *)(temp_v11 + 0x10);
        temp_v20 = *(float *)(temp_v11 + 0x14);
        fStack_230 = 1.0 - (temp_v15 * temp_v15 + temp_v21 * temp_v21) * 2.0;
        fStack_22c = (temp_v14 * temp_v15 + temp_v20 * temp_v21) * 2.0;
        fStack_228 = (temp_v21 * temp_v14 - temp_v20 * temp_v15) * 2.0;
        fStack_220 = (temp_v14 * temp_v15 - temp_v20 * temp_v21) * 2.0;
        fStack_21c = 1.0 - (temp_v14 * temp_v14 + temp_v21 * temp_v21) * 2.0;
        fStack_218 = (temp_v15 * temp_v21 + temp_v20 * temp_v14) * 2.0;
        fStack_210 = (temp_v21 * temp_v14 + temp_v20 * temp_v15) * 2.0;
        fStack_20c = (temp_v15 * temp_v21 - temp_v20 * temp_v14) * 2.0;
        fStack_208 = 1.0 - (temp_v14 * temp_v14 + temp_v15 * temp_v15) * 2.0;
        uStack_224 = 3;
        uStack_200 = *(unsigned int *)(temp_v11 + 0x18);
        uStack_1fc = *(unsigned int *)(temp_v11 + 0x1c);
        uStack_1f8 = *(unsigned int *)(temp_v11 + 0x20);
      }
      else {
        (*pcVar2)(&fStack_230,temp_v11);
      }
      if (*(int *)(puVar12[4] + iStack_420 * 0x10) == 0x1389) {
        if ((param_4 == 0) && ((*param_3 & 0x400) == 0)) {
          *param_3 = *param_3 | 0x600;
        }
        temp_v1 = 0;
        fStack_30 = 1.0 / *(float *)(param_3 + 0x18);
        fStack_2c = 1.0 / *(float *)(param_3 + 0x1a);
        fStack_28 = 1.0 / *(float *)(param_3 + 0x1c);
        if ((*param_2 & 0x10) != 0) {
          fStack_30 = fStack_30 * (1.0 / DAT_00922bb0);
          temp_v21 = (1.0 / DAT_00922bb0) * DAT_00922bb4;
          fStack_2c = fStack_2c * temp_v21;
          fStack_28 = fStack_28 * temp_v21;
        }
        pfVar17 = afStack_1b0;
        temp_v7 = 8;
        pfVar16 = pfVar21;
        do {
          temp_v21 = *pfVar16;
          temp_v20 = pfVar16[1];
          pfVar16 = pfVar16 + 2;
          temp_v7 = temp_v7 - 1;
          *pfVar17 = temp_v21;
          pfVar17[1] = temp_v20;
          pfVar17 = pfVar17 + 2;
        } while (0 < temp_v7);
        func_003e0a90(afStack_1b0,&fStack_30,1);
        func_003e05f0(&fStack_330,&fStack_230,afStack_1b0);
        fStack_20 = fStack_300;
        fStack_1c = fStack_2fc;
        fStack_18 = fStack_2f8;
        if (param_4 == 0) {
          func_003e0a90(&fStack_330,&fStack_30,1);
          uStack_10 = 0;
          uStack_c = 0x3f800000;
          uStack_8 = 0;
          func_003e0870(0x43340000,temp_v24,&uStack_10,0);
          uStack_10 = 0;
          uStack_c = 0;
          uStack_8 = 0x3f800000;
          func_003e0870(0xc2b40000,temp_v24,&uStack_10,2);
          func_003e05f0(temp_v25,temp_v24,afStack_b0);
          temp_v0 = *param_3;
          if ((temp_v0 & 0x100) == 0) {
            if ((temp_v0 & 0x60) == 0) {
              if ((temp_v0 & 0x80) == 0) {
                func_003dc610(&fStack_340,&fStack_330);
              }
              else {
                iStack_450 = 0;
                uStack_10 = 0x3f800000;
                uStack_c = 0;
                uStack_8 = 0;
                func_003e4320(&uStack_10,&uStack_10,afStack_b0);
                func_003e0870(*(unsigned int *)(param_3 + 0x1e),temp_v24,&uStack_10,0);
                uStack_10 = 0;
                uStack_c = 0x3f800000;
                uStack_8 = 0;
                func_003e4320(&uStack_10,&uStack_10,afStack_b0);
                func_003e0870(*(unsigned int *)(param_3 + 0x20),temp_v24,&uStack_10,2);
                func_003e05f0(pfVar8,temp_v25,temp_v24);
                func_003dc610(&fStack_340,pfVar8);
              }
            }
            else {
              iStack_450 = 1;
              if ((temp_v0 & 0x40) == 0) {
                fStack_30 = -*(float *)(param_3 + 0x1e);
                fStack_2c = -*(float *)(param_3 + 0x20);
                fStack_28 = -*(float *)(param_3 + 0x22);
              }
              else {
                fStack_30 = fStack_20 - *(float *)(param_3 + 0x1e);
                fStack_2c = fStack_1c - *(float *)(param_3 + 0x20);
                fStack_28 = fStack_18 - *(float *)(param_3 + 0x22);
              }
              func_003e40b0(&fStack_30,&fStack_30);
              func_003e0960(temp_v23,afStack_b0);
              func_003e4320(&fStack_30,&fStack_30,temp_v23);
              func_003e40b0(&fStack_30,&fStack_30);
              fStack_50 = 0.0;
              fStack_4c = 0.0;
              fStack_48 = -100.0;
              func_003e42a0(&fStack_50,&fStack_50,afStack_1b0);
              fStack_40 = fStack_20 - fStack_50;
              fStack_3c = fStack_1c - fStack_4c;
              fStack_38 = fStack_18 - fStack_48;
              func_003e4320(&fStack_40,&fStack_40,temp_v23);
              func_003e40b0(&fStack_40,&fStack_40);
              temp_v21 = (float)func_0044b920(fStack_3c);
              temp_v15 = fGpffff8048 * temp_v21 - 90.0;
              temp_v21 = (float)func_0044b950(fStack_40,fStack_38);
              temp_v14 = fGpffff8048 * temp_v21 + 180.0;
              temp_v21 = (float)func_0044b920(fStack_2c);
              temp_v20 = fGpffff8048 * temp_v21 - 90.0;
              temp_v21 = (float)func_0044b950(fStack_30,fStack_28);
              temp_v21 = fGpffff8048 * temp_v21;
              for (temp_v20 = temp_v20 - temp_v15; temp_v20 < 0.0; temp_v20 = temp_v20 + 360.0) {
              }
              for (; 360.0 < temp_v20; temp_v20 = temp_v20 - 360.0) {
              }
              temp_v16 = *(float *)(param_3 + 4);
              if ((temp_v16 < temp_v20) && (temp_v20 < 360.0 - temp_v16)) {
                if (180.0 <= temp_v20) {
                  temp_v16 = 360.0 - temp_v16;
                }
                temp_v1 = 1;
                temp_v20 = temp_v16;
              }
              func_003e0870(-(temp_v20 + temp_v15),temp_v24,temp_v26,0);
              for (temp_v21 = (temp_v21 + 180.0) - temp_v14; temp_v21 < 0.0; temp_v21 = temp_v21 + 360.0) {
              }
              for (; 360.0 < temp_v21; temp_v21 = temp_v21 - 360.0) {
              }
              temp_v20 = *(float *)(param_3 + 6);
              if ((temp_v20 < temp_v21) && (temp_v21 < 360.0 - temp_v20)) {
                if (180.0 <= temp_v21) {
                  temp_v20 = 360.0 - temp_v20;
                }
                temp_v1 = 1;
                temp_v21 = temp_v20;
              }
              func_003e0870(temp_v21 + temp_v14,temp_v24,temp_v25,2);
              func_003e05f0(pfVar8,temp_v25,temp_v24);
              func_003dc610(&fStack_340,pfVar8);
            }
            if (((*param_3 & 0x1000) == 0) || (!temp_v1)) {
              *param_3 = *param_3 & 0xf7ff;
            }
            else {
              if ((*param_3 & 0x800) == 0) {
                *(float *)(param_3 + 0x10) = fStack_340;
                *(float *)(param_3 + 0x12) = fStack_33c;
                *(float *)(param_3 + 0x14) = fStack_338;
                *(float *)(param_3 + 0x16) = fStack_334;
              }
              *param_3 = *param_3 | 0x800;
            }
            if ((*param_3 & 0x800) != 0) {
              fStack_340 = *(float *)(param_3 + 0x10);
              fStack_33c = *(float *)(param_3 + 0x12);
              fStack_338 = *(float *)(param_3 + 0x14);
              fStack_334 = *(float *)(param_3 + 0x16);
            }
            if (((*param_3 & 0x8000) != 0) &&
               ((*(float *)(param_3 + 0x24) != 0.0 || (*(float *)(param_3 + 0x26) != 0.0)))) {
              fStack_390 = fStack_340;
              fStack_38c = fStack_33c;
              fStack_388 = fStack_338;
              fStack_384 = fStack_334;
              iStack_450 = 0;
              uStack_10 = 0;
              uStack_c = 0x3f800000;
              uStack_8 = 0;
              func_003dcb40(&uStack_10,&uStack_10,1,&fStack_390);
              func_003dc740(*(unsigned int *)(param_3 + 0x24),&fStack_340,&uStack_10,2);
              uStack_10 = 0x3f800000;
              uStack_c = 0;
              uStack_8 = 0;
              func_003dcb40(&uStack_10,&uStack_10,1,&fStack_390);
              func_003dc740(*(unsigned int *)(param_3 + 0x26),&fStack_340,&uStack_10,2);
            }
          }
          else {
            func_003dc610(&fStack_340,&fStack_330);
          }
          if ((*param_3 & 0x200) == 0) {
            if ((puVar3 == (unsigned int *)0x0) && ((*param_3 & 0x100) != 0)) {
              temp_v21 = func_004bd4a0((unsigned char *)(param_3 + 8),(unsigned char *)&fStack_340);
              if (temp_v21 < 0.0) {
                fStack_344 = -fStack_334;
                fStack_350 = -fStack_340;
                fStack_34c = -fStack_33c;
                fStack_348 = -fStack_338;
                temp_v21 = func_004bd4a0((unsigned char *)(param_3 + 8),(unsigned char *)&fStack_350);
              }
              temp_v21 = (float)func_0044b920(temp_v21);
              if (temp_v21 * 2.0 < fGpffff804c) {
                *param_3 = *param_3 & 0x7e1f;
                *param_3 = *param_3 & 0xfbff;
              }
              *param_3 = *param_3 & 0xf7ff;
            }
            fStack_3b0 = *(float *)(param_3 + 8);
            fStack_3ac = *(float *)(param_3 + 10);
            fStack_3a8 = *(float *)(param_3 + 0xc);
            fStack_3a4 = *(float *)(param_3 + 0xe);
            func_003dcc70(&fStack_3b0,&fStack_340,&fStack_380);
            temp_v21 = *(float *)(param_3 + 2);
            if (temp_v21 <= 0.0) {
              fStack_3a0 = fStack_3b0;
              fStack_39c = fStack_3ac;
              fStack_398 = fStack_3a8;
              fStack_394 = fStack_3a4;
            }
            else if (1.0 <= temp_v21) {
              fStack_3a0 = fStack_340;
              fStack_39c = fStack_33c;
              fStack_398 = fStack_338;
              fStack_394 = fStack_334;
            }
            else {
              temp_v20 = 1.0 - temp_v21;
              if (iStack_35c == 0) {
                temp_v20 = temp_v20 * fStack_360;
                temp_v14 = temp_v20 * temp_v20;
                temp_v20 = temp_v14 * temp_v20 *
                         (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8050 * temp_v14 +
                                                                 fGpffff8054 + 0.0) +
                                                       fGpffff8058 + 0.0) + fGpffff805c + 0.0) +
                                   fGpffff8060 + 0.0) + fGpffff8064 + 0.0) + temp_v20 + 0.0;
                temp_v21 = temp_v21 * fStack_360;
                temp_v14 = temp_v21 * temp_v21;
                temp_v21 = temp_v14 * temp_v21 *
                         (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8050 * temp_v14 +
                                                                 fGpffff8054 + 0.0) +
                                                       fGpffff8058 + 0.0) + fGpffff805c + 0.0) +
                                   fGpffff8060 + 0.0) + fGpffff8064 + 0.0) + temp_v21 + 0.0;
              }
              fStack_3a0 = fStack_370 * temp_v21 + fStack_380 * temp_v20 + 0.0;
              fStack_39c = fStack_36c * temp_v21 + fStack_37c * temp_v20 + 0.0;
              fStack_398 = fStack_368 * temp_v21 + fStack_378 * temp_v20 + 0.0;
              fStack_394 = fStack_374 * temp_v20 + fStack_364 * temp_v21;
            }
            if (((*param_3 & 0x2000) == 0) || (iStack_450 == 0)) {
              *(float *)(param_3 + 8) = fStack_3a0;
              *(float *)(param_3 + 10) = fStack_39c;
              *(float *)(param_3 + 0xc) = fStack_398;
              *(float *)(param_3 + 0xe) = fStack_394;
            }
            else {
              func_003dc610(&uStack_3c0,&fStack_330);
              temp_v21 = func_004bd4a0((unsigned char *)&uStack_3c0,(unsigned char *)&fStack_3a0);
              if (temp_v21 < 0.0) {
                fStack_344 = -fStack_394;
                fStack_350 = -fStack_3a0;
                fStack_34c = -fStack_39c;
                fStack_348 = -fStack_398;
                temp_v21 = func_004bd4a0((unsigned char *)&uStack_3c0,(unsigned char *)&fStack_350);
              }
              temp_v21 = (float)func_0044b920(temp_v21);
              if (temp_v21 * 2.0 <= fGpffff8068 * *(float *)(param_3 + 6)) {
                *(float *)(param_3 + 8) = fStack_3a0;
                *(float *)(param_3 + 10) = fStack_39c;
                *(float *)(param_3 + 0xc) = fStack_398;
                *(float *)(param_3 + 0xe) = fStack_394;
              }
              else {
                temp_v21 = 1.0 - fGpffff806c / (temp_v21 * 2.0);
                func_003dcc70(&fStack_3a0,&uStack_3c0,&fStack_380);
                if (temp_v21 <= 0.0) {
                  *(float *)(param_3 + 8) = fStack_3a0;
                  *(float *)(param_3 + 10) = fStack_39c;
                  *(float *)(param_3 + 0xc) = fStack_398;
                  *(float *)(param_3 + 0xe) = fStack_394;
                }
                else if (1.0 <= temp_v21) {
                  *(unsigned int *)(param_3 + 8) = uStack_3c0;
                  *(unsigned int *)(param_3 + 10) = uStack_3bc;
                  *(unsigned int *)(param_3 + 0xc) = uStack_3b8;
                  *(unsigned int *)(param_3 + 0xe) = uStack_3b4;
                }
                else {
                  temp_v20 = 1.0 - temp_v21;
                  if (iStack_35c == 0) {
                    temp_v20 = temp_v20 * fStack_360;
                    temp_v14 = temp_v20 * temp_v20;
                    temp_v20 = temp_v14 * temp_v20 *
                             (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8070 * temp_v14 +
                                                                     fGpffff8054 + 0.0) +
                                                           fGpffff8058 + 0.0) + fGpffff805c + 0.0) +
                                       fGpffff8060 + 0.0) + fGpffff8064 + 0.0) + temp_v20 + 0.0;
                    temp_v21 = temp_v21 * fStack_360;
                    temp_v14 = temp_v21 * temp_v21;
                    temp_v21 = temp_v14 * temp_v21 *
                             (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8070 * temp_v14 +
                                                                     fGpffff8054 + 0.0) +
                                                           fGpffff8058 + 0.0) + fGpffff805c + 0.0) +
                                       fGpffff8060 + 0.0) + fGpffff8064 + 0.0) + temp_v21 + 0.0;
                  }
                  *(float *)(param_3 + 8) = fStack_380 * temp_v20;
                  *(float *)(param_3 + 10) = fStack_37c * temp_v20;
                  *(float *)(param_3 + 0xc) = fStack_378 * temp_v20;
                  *(float *)(param_3 + 8) = fStack_370 * temp_v21 + *(float *)(param_3 + 8) + 0.0;
                  *(float *)(param_3 + 10) = fStack_36c * temp_v21 + *(float *)(param_3 + 10) + 0.0;
                  *(float *)(param_3 + 0xc) = fStack_368 * temp_v21 + *(float *)(param_3 + 0xc) + 0.0;
                  *(float *)(param_3 + 0xe) = fStack_374 * temp_v20 + fStack_364 * temp_v21;
                }
              }
            }
          }
          else {
            func_003dc610(param_3 + 8,&fStack_330);
            *param_3 = *param_3 & 0xfdff;
            temp_v2 = 1;
            if ((*param_3 & 0x100) != 0) {
              *param_3 = *param_3 & 0x7e1f;
              *param_3 = *param_3 & 0xfbff;
              *param_3 = *param_3 & 0xf7ff;
            }
          }
        }
        if (puVar3 == (unsigned int *)0x0) {
          if (param_4 == 0) {
            temp_v16 = *(float *)(param_3 + 10);
            temp_v19 = *(float *)(param_3 + 8);
            temp_v18 = *(float *)(param_3 + 0xc);
            temp_v14 = *(float *)(param_3 + 0xe);
            temp_v20 = 2.0 / (temp_v14 * temp_v14 + temp_v18 * temp_v18 + temp_v19 * temp_v19 + temp_v16 * temp_v16);
            temp_v15 = temp_v19 * temp_v20;
            temp_v21 = temp_v16 * temp_v20;
            temp_v20 = temp_v18 * temp_v20;
            *pfVar8 = 1.0 - (temp_v16 * temp_v21 + temp_v18 * temp_v20);
            pfVar8[1] = temp_v19 * temp_v21 + temp_v20 * temp_v14;
            pfVar8[2] = temp_v18 * temp_v15 - temp_v21 * temp_v14;
            pfVar8[4] = temp_v19 * temp_v21 - temp_v20 * temp_v14;
            pfVar8[5] = 1.0 - (temp_v18 * temp_v20 + temp_v19 * temp_v15);
            pfVar8[6] = temp_v16 * temp_v20 + temp_v15 * temp_v14;
            pfVar8[8] = temp_v18 * temp_v15 + temp_v21 * temp_v14;
            pfVar8[9] = temp_v16 * temp_v20 - temp_v15 * temp_v14;
            pfVar8[10] = 1.0 - (temp_v19 * temp_v15 + temp_v16 * temp_v21);
            pfVar8[0xc] = 0.0;
            pfVar8[0xd] = 0.0;
            pfVar8[0xe] = 0.0;
            pfVar8[3] = 4.2039e-45;
            fStack_30 = *(float *)(param_3 + 0x18);
            fStack_2c = *(float *)(param_3 + 0x1a);
            fStack_28 = *(float *)(param_3 + 0x1c);
            if ((*param_2 & 0x10) != 0) {
              fStack_30 = fStack_30 * DAT_00922bb0;
              fStack_2c = fStack_2c * DAT_00922bb0 * DAT_00922bb4;
              fStack_28 = fStack_28 * DAT_00922bb0 * DAT_00922bb4;
            }
            func_003e0a90(pfVar8,&fStack_30,1);
            pfVar8[0xc] = fStack_20;
            pfVar8[0xd] = fStack_1c;
            pfVar8[0xe] = fStack_18;
          }
          else {
            temp_v16 = *(float *)(param_3 + 10);
            temp_v19 = *(float *)(param_3 + 8);
            temp_v18 = *(float *)(param_3 + 0xc);
            temp_v14 = *(float *)(param_3 + 0xe);
            temp_v20 = 2.0 / (temp_v14 * temp_v14 + temp_v18 * temp_v18 + temp_v19 * temp_v19 + temp_v16 * temp_v16);
            temp_v15 = temp_v19 * temp_v20;
            temp_v21 = temp_v16 * temp_v20;
            temp_v20 = temp_v18 * temp_v20;
            fStack_330 = 1.0 - (temp_v16 * temp_v21 + temp_v18 * temp_v20);
            fStack_32c = temp_v19 * temp_v21 + temp_v20 * temp_v14;
            fStack_328 = temp_v18 * temp_v15 - temp_v21 * temp_v14;
            fStack_320 = temp_v19 * temp_v21 - temp_v20 * temp_v14;
            fStack_31c = 1.0 - (temp_v18 * temp_v20 + temp_v19 * temp_v15);
            fStack_318 = temp_v16 * temp_v20 + temp_v15 * temp_v14;
            fStack_310 = temp_v18 * temp_v15 + temp_v21 * temp_v14;
            fStack_30c = temp_v16 * temp_v20 - temp_v15 * temp_v14;
            fStack_308 = 1.0 - (temp_v19 * temp_v15 + temp_v16 * temp_v21);
            fStack_300 = 0.0;
            fStack_2fc = 0.0;
            fStack_2f8 = 0.0;
            uStack_324 = 3;
            fStack_30 = *(float *)(param_3 + 0x18);
            fStack_2c = *(float *)(param_3 + 0x1a);
            fStack_28 = *(float *)(param_3 + 0x1c);
            if ((*param_2 & 0x10) != 0) {
              fStack_30 = fStack_30 * DAT_00922bb0;
              fStack_2c = fStack_2c * DAT_00922bb0 * DAT_00922bb4;
              fStack_28 = fStack_28 * DAT_00922bb0 * DAT_00922bb4;
            }
            func_003e0a90(&fStack_330,&fStack_30,1);
            fStack_300 = fStack_20;
            fStack_2fc = fStack_1c;
            fStack_2f8 = fStack_18;
            func_003e05f0(pfVar8,&fStack_330,param_4);
          }
          if (((*(int *)(uStack_430 + 0xc) != 0) &&
              (temp_v7 = *(int *)(*(int *)(uStack_430 + 0xc) + 4), temp_v7 != 0)) &&
             ((*(unsigned char *)(*(int *)(temp_v7 + 0xa0) + 3) & 1) != 0)) {
            func_003ed960();
          }
        }
        else {
          func_003e05f0(pfVar8,&fStack_230,pfVar21);
        }
      }
      else {
        func_003e05f0(pfVar8,&fStack_230,pfVar21);
      }
      temp_v7 = *(int *)(uStack_430 + 0xc);
      if (temp_v7 != 0) {
        if ((temp_v10 & 0x1000) != 0) {
          pfVar17 = &fStack_230;
          pfVar16 = (float *)(temp_v7 + 0x10);
          temp_v8 = 8;
          do {
            temp_v21 = *pfVar17;
            temp_v20 = pfVar17[1];
            pfVar17 = pfVar17 + 2;
            temp_v8 = temp_v8 - 1;
            *pfVar16 = temp_v21;
            pfVar16[1] = temp_v20;
            pfVar16 = pfVar16 + 2;
          } while (0 < temp_v8);
          if (temp_v3 == 0) {
            func_003e9680(temp_v7);
          }
        }
        if (temp_v3 != 0) {
          if ((temp_v10 & 0x4000) == 0) {
            pfVar17 = (float *)(temp_v7 + 0x50);
            temp_v8 = 8;
            pfVar16 = pfVar8;
            do {
              temp_v21 = *pfVar16;
              temp_v20 = pfVar16[1];
              pfVar16 = pfVar16 + 2;
              temp_v8 = temp_v8 - 1;
              *pfVar17 = temp_v21;
              pfVar17[1] = temp_v20;
              pfVar17 = pfVar17 + 2;
            } while (0 < temp_v8);
          }
          else {
            func_003e05f0(temp_v7 + 0x50,pfVar8,afStack_b0);
          }
          *(unsigned char *)(temp_v7 + 3) = (*(unsigned char *)(temp_v7 + 3) & 0xfb) | 8;
        }
      }
      temp_v6 = *(unsigned int *)(uStack_430 + 8) & 3;
      pfVar16 = pfVar21;
      if (temp_v6 != 3) {
        pfVar16 = pfVar8;
        if (temp_v6 == 2) {
          *puVar22 = (unsigned int)pfVar21;
          puVar22 = puVar22 + 1;
        }
        else if (temp_v6 == 1) {
          puVar22 = puVar22 + -1;
          pfVar16 = (float *)*puVar22;
        }
        else if (temp_v6 != 0) {
          pfVar16 = pfVar21;
        }
      }
      pfVar21 = pfVar16;
      temp_v11 = temp_v11 + temp_v9;
      pfVar8 = pfVar8 + 0x10;
      uStack_430 = uStack_430 + 0x10;
    }
    if ((puVar3 != (unsigned int *)0x0) && ((*param_3 & 0x81e0) != 0)) {
      if (*(short *)((int)puVar3 + 0x42) == 0) {
        for (temp_v10 = 0; temp_v10 < 4; temp_v10 = temp_v10 + 1) {
          temp_v5 = func_003d5790(puVar12[1],*(unsigned int *)(puVar12[8] + 0x20));
          (puVar3 + temp_v10)[4] = (int)temp_v5;
          func_003d5840(temp_v5,puVar3[temp_v10]);
        }
        *(unsigned short *)((int)puVar3 + 0x42) = 1;
      }
      if (temp_v2) {
        puVar3[0xc] = 0x3f800000;
        puVar3[0x12] = 0;
      }
      if ((1.0 <= (float)puVar3[0xe]) ||
         (pbVar19 = *(unsigned char **)(param_2 + 0x14), pbVar19 == (unsigned char *)0x0)) {
        pbVar19 = (unsigned char *)puVar12[8];
        temp_v21 = *(float *)(pbVar19 + 4);
      }
      else {
        piVar4 = *(int **)(**(int **)(param_2 + 0x1a) + 0x4c + (short)param_2[2] * 0x50);
        if (piVar4 == (int *)0x0) {
          temp_v21 = 0.0;
        }
        else {
          temp_v21 = fGpffff8040 * (float)*piVar4;
        }
      }
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_68 = 0x3f800000;
      if ((*param_3 & 0x100) == 0) {
        func_003dcb40(&fStack_60,&uStack_70,1,param_3 + 8);
        temp_v17 = *(unsigned int *)(param_3 + 10);
        temp_v12 = *(unsigned int *)(param_3 + 0xc);
        temp_v13 = *(unsigned int *)(param_3 + 0xe);
        puVar3[8] = *(unsigned int *)(param_3 + 8);
        puVar3[9] = temp_v17;
        puVar3[10] = temp_v12;
        puVar3[0xb] = temp_v13;
      }
      else {
        func_003dcb40(&fStack_60,&uStack_70,1,puVar3 + 8);
      }
      func_003e0960(temp_v22,afStack_b0);
      func_003e4320(&fStack_60,&fStack_60,temp_v22);
      func_003e40b0(&fStack_60,&fStack_60);
      temp_v20 = (float)*(unsigned short *)((int)puVar3 + 0x3e) / *(float *)(param_3 + 6);
      if (0.0 <= fStack_60) {
        func_003d5840(puVar3[5],puVar3[1]);
        func_003d5e40((unsigned char *)puVar3[5],temp_v21);
        func_003d5e90((unsigned char *)puVar3[6],pbVar19,(unsigned char *)puVar3[5],fStack_60 / temp_v20);
        temp_v9 = 2;
      }
      else {
        func_003d5840(puVar3[6],puVar3[2]);
        func_003d5e40((unsigned char *)puVar3[6],temp_v21);
        func_003d5e90((unsigned char *)puVar3[5],pbVar19,(unsigned char *)puVar3[6],-fStack_60 / temp_v20);
        temp_v9 = 1;
      }
      if (0.0 <= fStack_5c) {
        func_003d5840(puVar3[7],puVar3[3]);
        func_003d5e40((unsigned char *)puVar3[7],temp_v21);
        func_003d5e90((unsigned char *)puVar3[4],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[7],fStack_5c);
        puVar3[0x11] = 0;
      }
      else {
        func_003d5840(puVar3[4],*puVar3);
        func_003d5e40((unsigned char *)puVar3[4],temp_v21);
        func_003d5e90((unsigned char *)puVar3[7],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[4],-fStack_5c);
        puVar3[0x11] = 3;
      }
      if ((1.0 <= (float)puVar3[0xe]) || (*(unsigned char **)(param_2 + 0x12) == (unsigned char *)0x0)) {
        if ((*param_3 & 0x100) == 0) {
          puVar3[0xc] = (float)puVar3[0xc] * (1.0 - *(float *)(param_3 + 2));
          puVar3[0x12] = 0x3f800000;
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        1.0 - (float)puVar3[0xc]);
        }
        else {
          puVar3[0x12] = (float)puVar3[0x12] * (1.0 - *(float *)(param_3 + 2));
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        (float)puVar3[0x12]);
          if ((float)puVar3[0x12] < fGpffff8074) {
            *param_3 = *param_3 & 0x7e1f;
            *param_3 = *param_3 & 0xfbff;
          }
          *param_3 = *param_3 & 0xf7ff;
        }
      }
      else {
        func_003d5e90((unsigned char *)puVar12[8],*(unsigned char **)(param_2 + 0x12),(unsigned char *)puVar3[puVar3[0x11] + 4]
                      ,(float)puVar3[0xe]);
        puVar3[0xe] = (float)puVar3[0xe] + 1.0 / (float)puVar3[0xd];
        puVar3[0xc] = 0;
      }
      func_00397c40(param_1);
    }
  }
  return;
}


