/* func_0046a7f0 wall floor: window 848B (212 instr), frame 0xB0 (input sp+0x80 / output sp+0x50).
 * Method: neighbours 0046a770 (128B) / 0046ab40 (80B) MATCH with explicit goto top-test loops;
 * full window top-down via fndiff: off 0-104 (first 4x2 xy copy) byte-exact, remainder walls.
 * Levers measured with probe_variants.py on src/promoted/code1_0046.c (b210 -O2):
 *  a unfaithful spelling twice (missing *(B+0x204) load, folded 0x248/0x24C): obj 836B nd 100.
 *  b faithful hoisted temps (tbl/entry hoisted, f32 arrays, var_2 xori form): obj 844B nd 163.
 *  d faithful spelling twice (correct `*( *(B+0x204)+(idx<<7)+0x44/0x48` inline twice): obj 844B nd 71 (best).
 *  c/e faithful/unfaithful + `opt_common_subs off`: nd 191 / 193 (worse).
 * Table-remat check: retail final loop remats table base twice per iter
 * (lw $5,0($17); lw $3,4($17); sll $4,$3,7; lw $3,0x204($5); addu $3,$3,$4
 * at 0x46AA80-90 and 0x46AAE4-F4 vs single saved reg). Spelling twice (d, nd 71)
 * and subs off (e, nd 193) both fail to close; middle 4x3 copy single-base
 * (sp+i*12 +0x50/+0x80, 3-reg loads-first) vs twice + 1-reg, FPR $f1 vs $f3,
 * counter $a3 vs $t0, ACC adda/madd scheduling also remain. Banked as wall;
 * production stays INCLUDE_ASM. Previous claim nd 102 (unfaithful) superseded.
 */
// FUN_0046A7F0
void func_0046a7f0(u8 *arg0, f32 *arg1) {
    extern f32 fGpffff8084;
    extern f32 fGpffff81b0;
    extern f32 D_007612A4;
    extern f32 D_007612A8;
    extern f32 D_007612AC;
    extern f32 D_007612B0;
    extern f32 D_007612B4;
    extern f32 fGpffff81c8;
    extern f32 D_00761144;
    extern f32 D_00761148;
    extern f32 D_0076114C;
    extern f32 D_00761150;
    extern f32 D_007612BC;
    extern u8 D_007130B8[];
    extern void *func_003e0f80(void);
    extern void *func_003e0680(void *a0, void *a1, s32 a2, f32 f0, f32 f1);
    extern void func_003e42e0(void *dst, void *src, s32 n, void *m);
    extern void func_003e0f40(void *m);
    u32 input[12];
    u32 output[12];
    f32 var_f3;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_2;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_8;
    f32 *pfVar3;
    f32 *pInput;
    f32 *pOutput;
    for (var_5 = 0; var_5 < 4; var_5++) {
        pfVar3 = (f32 *)((u8 *)arg1 + var_5 * 8);
        pInput = ((f32 *)input) + var_5 * 3;
        pInput[0] = pfVar3[0];
        pInput[1] = pfVar3[1];
    }
    var_f3 = *(f32 *)(arg0 + 0x18);
    if (var_f3 != 0.0f) {
        do {
            var_4 = 0;
            if (var_f3 <= 180.0f) {
                if (var_f3 < -180.0f) {
                    var_f3 += 360.0f;
                    var_4 = 1;
                }
            } else {
                var_f3 -= 360.0f;
                var_4 = 1;
            }
        } while (var_4 != 0);
        temp_f21 = (fGpffff8084 * var_f3) / 180.0f;
        temp_f20 = temp_f21 * temp_f21;
        temp_2 = (s32)func_003e0f80();
        temp_2 = (s32)func_003e0680(
            (void *)(u32)temp_2,
            (void *)D_007130B8,
            0,
            1.0f -
                (1.0f -
                 (temp_f20 * 0.5f -
                  temp_f20 * temp_f20 *
                  (temp_f20 *
                   (temp_f20 *
                    (temp_f20 *
                     (temp_f20 *
                      (fGpffff81b0 * temp_f20 + D_007612A4 + 0.0f) +
                      D_007612A8 + 0.0f) +
                     D_007612AC + 0.0f) +
                    D_007612B0 + 0.0f) +
                   D_007612B4 + 0.0f))),
            temp_f20 * temp_f21 *
                (temp_f20 *
                 (temp_f20 *
                  (temp_f20 *
                   (temp_f20 *
                    (fGpffff81c8 * temp_f20 + D_00761144 + 0.0f) +
                    D_00761148 + 0.0f) +
                   D_0076114C + 0.0f) +
                  D_00761150 + 0.0f) +
                 D_007612BC + 0.0f) +
                temp_f21 + 0.0f);
        func_003e42e0((void *)output, (void *)input, 4, (void *)(u32)temp_2);
        func_003e0f40((void *)(u32)temp_2);
        for (var_5_2 = 0; var_5_2 < 4; var_5_2++) {
            pOutput = ((f32 *)output) + var_5_2 * 3;
            pInput = ((f32 *)input) + var_5_2 * 3;
            pInput[0] = pOutput[0];
            pInput[1] = pOutput[1];
            pInput[2] = pOutput[2];
        }
    }
    for (var_8 = 0; var_8 < 4; var_8++) {
        pfVar3 = (f32 *)((u8 *)arg1 + var_8 * 8);
        pInput = ((f32 *)input) + var_8 * 3;
        pfVar3[0] =
            *(f32 *)(arg0 + 8) + ((f32)*(s16 *)(arg0 + 0x1C) + pInput[0]) +
            (f32)*(s32 *)(*(u8 **)(*(u8 **)arg0 + 0x204) + (*(s32 *)(arg0 + 4) << 7) + 0x44);
        pfVar3[1] =
            *(f32 *)(arg0 + 0xC) + ((f32)*(s16 *)(arg0 + 0x1E) + pInput[1]) +
            (f32)*(s32 *)(*(u8 **)(*(u8 **)arg0 + 0x204) + (*(s32 *)(arg0 + 4) << 7) + 0x48);
    }
}
