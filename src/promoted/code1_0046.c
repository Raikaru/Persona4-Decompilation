#include "include_asm.h"
#include "type.h"
#include "h_cdvd_internal.h"
#include "Kosaka/k_clump_internal.h"
extern s32 iGpffffb034;
extern s32 iGpffffbaf8;
extern s32 iGpffffbab4;
extern s32 iGpffffbab0;
extern s32 D_008E4B30[];
extern s32 D_008E4B34[];
extern s32 D_008E4B38[];
extern u8 D_008E4800[];
extern u8 D_008E4B50[];
extern u8 D_008E4D30[];
extern void func_0043a978(void);
extern void func_004316a8(s32 arg0);
extern s32 func_00431928(void *a, u8 *b);
extern s32 func_003e1220(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
extern s32 iGpffffba98;
extern s32 iGpffffba9c;
extern u8 D_008E43C0[];
extern u8 D_008E43E4[];
extern void *func_004632f0(void *a0, void *a1);
extern s32 D_00922984[];
extern s32 D_00922980[];
extern s32 D_00922988[];
extern s32 D_00922934[];
extern s32 D_00922930[];
extern s32 D_0092293C[];
extern u8 *(*D_008873F8[])();
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])();

extern void func_00452730(s32 arg0);

extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbae8;
extern s32 iGpffffbaec;
extern u8 D_0070B610[];
extern void func_0050ffc8(s32 arg0);
extern void func_005097e8(s32 arg0);
extern void func_003ec330(s32 arg0);
extern s32 func_003d5fb0(u8 *arg0);
extern void func_0046a340(u32 arg0);

extern s32 D_00724BEC;
extern s32 D_00724BF0;

extern void func_0046ab90(u8 *arg0);
extern u8 *D_00724C08;

extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;
extern void func_00451de0(const void *name, s32 prio, s32 a2, s32 a3, void *entry, s32 a5, s32 a6);
extern s32 func_004633f0(void);
extern void func_00468ff0(s32 arg0, u8 *arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00460ac0(char *name, u8 *task);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern u8 D_00800000[];
extern u16 D_008C0276;
extern u8 iGpffffb020[];
extern u8 iGpffffb024[];
extern u8 iGpffffb028[];
extern u8 *func_00468940(s64 arg0, s16 arg1);
extern void func_00453670(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4);
extern void func_00453860(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern s32 func_004688d0(u8 *arg0, u8 *arg1, s16 arg2);
extern s32 func_004426e8(const char *a, const char *b);
extern s32 uGpffffb230;
extern s32 D_00724BC8;
extern s32 func_0042ba70();
extern s32 func_0042ba20();
extern void func_004216e0(s32 handle, s32 *out);
extern void func_00421770(s32 handle);
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void (*D_00887304[])(s32 arg0, s32 *arg1);
extern u8 D_008872E0[];
extern s32 iGpffffaf60;
extern void func_003c21e0(s32 arg0, s32 (*callback)(u8 *, s32 *), s32 *result);
extern u8 *func_003bfae0(s32 arg0);
extern s32 func_003e8200(s32 arg0, u8 *arg1);
extern void func_00477400(s32 arg0, s32 arg1);
extern void func_00476c70(u8 *arg0);
extern void func_00479910(s32 arg0);
extern void func_00461560(u8 *arg0);
extern void func_00461a40(u8 *arg0);
extern void func_00461be0(u8 *arg0);
extern u8 *func_0046a6f0(s32 arg0, s32 arg1);
extern s32 func_00451fc0(s32 arg0, const void *name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern s32 func_00468fa0(u8 *arg0);
extern void func_0046a020(u8 *arg0);
extern u32 iGpffffbb14;
extern u32 iGpffffbb10;
extern u32 iGpffffbb0c;
extern u32 iGpffffbb04;
extern s32 func_00432ec0(void);
extern s32 iGpffffba8c;
extern s32 iGpffffb198;
extern s32 iGpffffb194;
extern f32 iGpffffbb20;
extern f32 iGpffffbb1c;
extern f32 iGpffffbb24;
extern void func_0044f720(void);
extern s32 func_003e23e0(void);
extern void func_003e82e0();
extern void func_003e5510(s32 arg0);
extern s32 func_00457120(void);
extern void func_00466c60(void);
extern void func_0050cd80(void);
extern void func_00466600(void);
extern s32 func_00442088(char *dst, const char *fmt, ...);
extern s32 sceMc2GetInfoAsync(s32 socket, void *out);
extern s32 func_00431d78(s32 socket, void *data, void *result);
extern char D_007127D0[];
extern char D_00712950[];
extern char D_008E4900[];
extern char D_008E4A20[];
extern s32 D_00764BA4;
extern s32 D_00764BB8;
extern s32 D_00764BC0;
extern s32 D_008E4B20[];
extern s32 D_008E4B28[];
extern s32 D_00712490[];
extern s64 D_007615DC;
extern f32 fGpffff82fc;
extern f32 fGpffff84f0;
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b7b0(f32 arg0);
extern void func_0045f790(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void func_0045fbe0(void *arg0, void *arg1, void *arg2, s32 arg3, f32 fparg0);
struct Data_00712508 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};
extern struct Data_00712508 D_00712508[] __attribute__((aligned(8)));
extern f32 fGpffff81f0;
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern void *func_003e0f80(void);
extern void *func_003e0680(void *mat, void *axis, s32 arg2, f32 fparg0, f32 fparg1);
extern void func_003e42e0(void *dst, void *src, s32 count, void *mat);
extern void func_003e0f40(void *mat);
extern u8 D_007130B8[];
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8084;
extern f32 fGpffff81b0;
extern f32 fGpffff81b4;
extern f32 fGpffff81b8;
extern f32 fGpffff81bc;
extern f32 fGpffff81c0;
extern f32 fGpffff81c4;
extern f32 fGpffff81c8;
extern f32 fGpffff81cc;


// FUN_004601C0
void func_004601c0(u8 *arg0, f32 fparg0, u8 *arg1, s32 arg2) {
    struct Data_00712508 spE __attribute__((aligned(16)));
    f32 spF0[3];
    f32 spA0[4][4];
    s32 sp80[6];
    f32 sp70[4];
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f21;
    u32 var_16;
    u32 var_16_2;
    u32 var_16_3;
    u32 var_17;
    s32 *temp_16;
    spE = D_00712508[0];
    sp70[3] = fparg0;
    sp70[0] = *(f32 *)(arg0 + 0);
    sp70[1] = *(f32 *)(arg0 + 4);
    sp70[2] = *(f32 *)(arg0 + 8);
    if (func_003e8200(*(s32 *)D_008872E0, (u8 *)&sp70[0]) != 0) {
        if (arg2 != 0) {
            for (var_17 = 0; var_17 < 6U; var_17++) {
                temp_16 = &D_00712490[var_17 * 2];
                D_00887304[0](temp_16[0], &sp80[var_17]);
                D_00887300[0](temp_16[0], temp_16[1]);
            }
            D_00887300[0](1, 0);
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
        }
        spA0[2][2] = 1.0f;
        spA0[1][1] = 1.0f;
        spA0[0][0] = 1.0f;
        var_f21 = 0.0f;
        spA0[1][0] = 0.0f;
        spA0[0][2] = 0.0f;
        spA0[0][1] = 0.0f;
        spA0[2][1] = 0.0f;
        spA0[2][0] = 0.0f;
        spA0[1][2] = 0.0f;
        spA0[3][2] = 0.0f;
        spA0[3][1] = 0.0f;
        spA0[3][0] = 0.0f;
        *(s32 *)&spA0[0][3] |= 0x20003;
        for (var_16 = 0; var_16 < 9U; var_16++) {
            var_f21 += fGpffff81f0;
            temp_f22 = fparg0 * func_0044b610(var_f21);
            temp_f12 = fparg0 * func_0044b7b0(var_f21);
            spF0[0] = *(f32 *)(arg0 + 0);
            spF0[1] = *(f32 *)(arg0 + 4) + temp_f22;
            spF0[2] = *(f32 *)(arg0 + 8);
            func_0045fbe0(&spF0[0], arg1, &spA0[0][0], 0, temp_f12);
        }
        func_003e0870(&spA0[0][0], &spE, 2, 90.0f);
        temp_f22 = 0.0f;
        for (var_16_2 = 0; var_16_2 < 9U; var_16_2++) {
            temp_f22 += fGpffff81f0;
            var_f21 = fparg0 * func_0044b610(temp_f22);
            temp_f12_2 = fparg0 * func_0044b7b0(temp_f22);
            spF0[0] = *(f32 *)(arg0 + 0);
            spF0[1] = *(f32 *)(arg0 + 4);
            spF0[2] = *(f32 *)(arg0 + 8) + var_f21;
            func_0045fbe0(&spF0[0], arg1, &spA0[0][0], 0, temp_f12_2);
        }
        if (arg2 != 0) {
            for (var_16_3 = 0; var_16_3 < 6U; var_16_3++) {
                D_00887300[0](D_00712490[var_16_3 * 2], sp80[var_16_3]);
            }
        }
    }
}






/* measured: fnalign retail 270 vs object 270 (+0, PASS 3% band 260-276, was 190 vs 268 -29.1%); opclass clean (no delta, was swc1 -26/lwc1 -19/add.s -11); frame 0xE0 matches retail (was 0xA0). Shapes: honest aggregates f32 sp80[4]/spD[3]/spB0[3]/spBC[3] + s32 sp90[6] (was scalars + sp90[8] with &sp90[var+36] and byte-load UB, b210 deleted stores per handoff 7z); memory-update adds spB0[0]=spB0[0]+... where retail reloads (was temp-reg adds keeping values in saved regs, +3 swc1); `if (fparg0>fparg1)` max form (was <= with bc1f, retail bc1t, clean census); fGpffff84f0/fGpffff82fc for gp loads (was 0.123f/0.456f literals, same lwc1 class, correct GPREL); distinct fourth-loop temps (was single temp_f0 reuse bug) + word loads (was byte). Walls: saved-reg rotation, scheduling, 97 fnalign edits; production stays ASM. */
// FUN_004604D0 NONMATCHING
#ifdef NON_MATCHING
void func_004604d0(f32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    f32 spD[3];
    f32 spBC[3];
    f32 spB0[3];
    s32 sp90[6];
    f32 sp80[4];
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 var_f0;
    f32 var_f20;
    f32 var_f22;
    u32 var_16;
    u32 var_19;
    u32 var_19_2;
    u32 var_19_3;
    u32 var_20;
    s32 *temp_16;

    if (fparg0 > fparg1) {
        var_f0 = fparg0;
    } else {
        var_f0 = fparg1;
    }
    sp80[3] = var_f0;
    sp80[0] = arg0[0];
    sp80[1] = arg0[1];
    sp80[2] = arg0[2];
    if (func_003e8200(*(s32 *)D_008872E0, (u8 *)&sp80[0]) != 0) {
        if (arg2 != 0) {
            var_20 = 0;
            for (var_20 = 0; var_20 < 6U; var_20++) {
                temp_16 = &D_00712490[var_20 * 2];
                D_00887304[0](temp_16[0], &sp90[var_20]);
                D_00887300[0](temp_16[0], temp_16[1]);
            }
            D_00887300[0](1, 0);
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
        }
        spD[0] = arg0[0];
        temp_f20 = 0.5f * fparg1;
        spD[1] = arg0[1] - temp_f20;
        spD[2] = arg0[2];
        temp_f21 = fparg1 / 7.0f;
        var_19 = 0;
        for (var_19 = 0; var_19 < 8U; var_19++) {
            func_0045fbe0(&spD[0], arg1, 0, 0, fparg0);
            spD[1] += temp_f21;
        }
        var_f22 = 0.0f;
        var_19_2 = 0;
        temp_f21 = 0.5f * -fparg1;
        for (var_19_2 = 0; var_19_2 < 10U; var_19_2++) {
            spB0[0] = fparg0 * func_0044b610(var_f22);
            spB0[1] = temp_f21;
            temp_f4 = fparg0 * func_0044b7b0(var_f22);
            spB0[2] = temp_f4;
            spBC[0] = spB0[0];
            spBC[1] = temp_f20;
            spBC[2] = temp_f4;
            spB0[0] = spB0[0] + arg0[0];
            spB0[1] = spB0[1] + arg0[1];
            spB0[2] = spB0[2] + arg0[2];
            spBC[0] = spB0[0];
            spBC[1] = temp_f20 + arg0[1];
            spBC[2] = spB0[2];
            func_0045f790(&spB0[0], &spBC[0], arg1, 0);
            var_f22 += fGpffff84f0;
        }
        var_f20 = 0.0f;
        var_19_3 = 0;
        for (var_19_3 = 0; var_19_3 < 5U; var_19_3++) {
            temp_f0 = fparg0 * func_0044b610(var_f20);
            spB0[0] = temp_f0;
            spB0[1] = temp_f21;
            temp_f0_2 = fparg0 * func_0044b7b0(var_f20);
            spB0[2] = temp_f0_2;
            temp_f22 = fGpffff82fc + var_f20;
            temp_f0_3 = fparg0 * func_0044b610(temp_f22);
            spBC[0] = temp_f0_3;
            spBC[1] = temp_f21;
            temp_f4_2 = fparg0 * func_0044b7b0(temp_f22);
            spBC[2] = temp_f4_2;
            spB0[0] = spB0[0] + arg0[0];
            spB0[1] = spB0[1] + arg0[1];
            spB0[2] = spB0[2] + arg0[2];
            spBC[0] = spBC[0] + arg0[0];
            spBC[1] = spBC[1] + arg0[1];
            spBC[2] = spBC[2] + arg0[2];
            func_0045f790(&spB0[0], &spBC[0], arg1, 0);
            spB0[1] = spB0[1] + fparg1;
            spBC[1] = spBC[1] + fparg1;
            func_0045f790(&spB0[0], &spBC[0], arg1, 0);
            var_f20 += fGpffff84f0;
        }
        if (arg2 != 0) {
            var_16 = 0;
            for (var_16 = 0; var_16 < 6U; var_16++) {
                D_00887300[0](D_00712490[var_16 * 2], sp90[var_16]);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004604d0);
#endif

// FUN_00460910
void func_00460910(s32 arg0, s32 arg1)
{
    iGpffffba98 = func_003e1220(0x30, arg0, 4, 1, D_008E43C0, 0x41002);
    iGpffffba9c = func_003e1220(0x30, arg1, 4, 1, D_008E43E4, 0x41003);
}
// FUN_00460990
u8 *func_00460990(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B88, 0x41002);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_004609F0
u8 *func_004609f0(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B8C, 0x41003);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_00460A50
void func_00460a50(s32 arg0)
{
    jtbl_008873FC[0](D_00724B8C, arg0);
}



// FUN_00460A80
void func_00460a80(s32 arg0, s32 arg1)
{
    memset((void *)arg0, 0, arg1 * 0x30);
    func_00452730(D_00724B88);
}



// FUN_004614B0
void func_004614b0(void) {
    void (**tbl)(s32, s32) = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
}

// FUN_00461530
s32 func_00461530(u8 *arg0, s32 *arg1)
{
    if (*(u8 *)(arg0 + 7) == 0xFF) {
        *arg1 = 1;
    }
    return (s32)arg0;
}
// FUN_00461560
void func_00461560(u8 *arg0)
{
    s32 sp4C;
    s32 sp48;
    s32 temp_4_2;
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *var_16;
    u8 *var_17;
    u8 *var_17_2;
    u8 *var_17_3;

    temp_16 = *(u8 **)(arg0 + 0x1C);
    if (temp_16 != NULL) {
#pragma opt_propagation off
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            {
                void (**table)(s32, s32) =
                    (void (**)(s32, s32))(u32)D_00887300;
                table[0](6, 1);
                table[0](8, 1);
            }
        }
#pragma opt_propagation on
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        var_17 = *(u8 **)(temp_16 + 8);
        goto loop_00461560_first_test;
loop_00461560_first_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_17 + 0))) != 0) {
            if (*(s32 *)(var_17 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 - 0x18)) == 1) {
                temp_4 = *(u8 **)(var_17 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4 + 0x48)))(temp_4);
            }
            if (*(s32 *)(var_17 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_17 = *(u8 **)(var_17 + 0x24);
loop_00461560_first_test:
        if (var_17 != NULL) {
            goto loop_00461560_first_body;
        }
        var_17_2 = *(u8 **)(temp_16 + 0x14);
        goto loop_00461560_second_test;
loop_00461560_second_body:
        sp48 = 0;
        temp_4_2 = *(s32 *)(*(u8 **)(var_17_2 + 0) + 0x18);
        if (temp_4_2 != 0) {
            func_003c21e0(temp_4_2, func_00461530, &sp48);
            if (*(f32 *)(var_17_2 + 0x14) >= 1.0f && sp48 != 0 &&
                func_003e8200(*(s32 *)D_008872E0,
                              func_003bfae0(*(s32 *)(var_17_2 + 0))) != 0) {
                if (*(s32 *)(var_17_2 + 4) == 1) {
                    D_00887304[0](0xE, &sp4C);
                    D_00887300[0](0xE, 0);
                }
                if (*((s32 *)((u8 *)&iGpffffaf60 - 0x18)) == 1) {
                    temp_4_3 = *(u8 **)(var_17_2 + 0);
                    ((void (*)(u8 *))(*(void **)(temp_4_3 + 0x48)))(temp_4_3);
                }
                if (*(s32 *)(var_17_2 + 4) == 1) {
                    D_00887300[0](0xE, sp4C);
                }
            }
        }
        var_17_2 = *(u8 **)(var_17_2 + 0x24);
loop_00461560_second_test:
        if (var_17_2 != NULL) {
            goto loop_00461560_second_body;
        }
#pragma opt_propagation off
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            {
                void (**table)(s32, s32) =
                    (void (**)(s32, s32))(u32)D_00887300;
                table[0](6, 1);
                table[0](8, 0);
            }
        }
#pragma opt_propagation on
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        var_17_3 = *(u8 **)(temp_16 + 0x18);
        goto loop_00461560_third_test;
loop_00461560_third_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_17_3 + 0))) != 0) {
            if (*(s32 *)(var_17_3 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 - 8)) == 1) {
                temp_4_4 = *(u8 **)(var_17_3 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4_4 + 0x48)))(temp_4_4);
            }
            if (*(s32 *)(var_17_3 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_17_3 = *(u8 **)(var_17_3 + 0x24);
loop_00461560_third_test:
        if (var_17_3 != NULL) {
            goto loop_00461560_third_body;
        }
#pragma opt_propagation off
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            {
                void (**table)(s32, s32) =
                    (void (**)(s32, s32))(u32)D_00887300;
                table[0](6, 1);
                table[0](8, 1);
            }
        }
#pragma opt_propagation on
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x715FB);
        var_16 = *(u8 **)(temp_16 + 0x1C);
        goto loop_00461560_fourth_test;
loop_00461560_fourth_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_16 + 0))) != 0) {
            if (*(s32 *)(var_16 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 - 4)) == 1) {
                temp_4_5 = *(u8 **)(var_16 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4_5 + 0x48)))(temp_4_5);
            }
            if (*(s32 *)(var_16 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_16 = *(u8 **)(var_16 + 0x24);
loop_00461560_fourth_test:
        if (var_16 != NULL) {
            goto loop_00461560_fourth_body;
        }
    }
}
#pragma opt_propagation off
// FUN_00461A40
void func_00461a40(u8 *arg0)
{
    s32 sp3C;
    s32 sp38;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_4_2;
    u8 *var_16;
    void (**table)(s32, s32);

    temp_16 = *(u8 **)(arg0 + 0x1C);
    if (temp_16 != NULL) {
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            table = D_00887300;
            table[0](6, 1);
            table[0](8, 0);
        }
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        var_16 = *(u8 **)(temp_16 + 0x20);
        goto loop_00461A40_test;
loop_00461A40_body:
        sp38 = 0;
        temp_4 = *(s32 *)(*(u8 **)(var_16 + 0) + 0x18);
        if (temp_4 != 0) {
            func_003c21e0(temp_4, func_00461530, &sp38);
            if ((sp38 != 1) &&
                (func_003e8200(*(s32 *)D_008872E0,
                               func_003bfae0(*(s32 *)(var_16 + 0))) != 0)) {
                if (*(s32 *)(var_16 + 4) == 1) {
                    D_00887304[0](0xE, &sp3C);
                    D_00887300[0](0xE, 0);
                }
                if (iGpffffaf60 == 1) {
                    temp_4_2 = *(u8 **)(var_16 + 0);
                    ((void (*)(u8 *))(*(void **)(temp_4_2 + 0x48)))(temp_4_2);
                }
                if (*(s32 *)(var_16 + 4) == 1) {
                    D_00887300[0](0xE, sp3C);
                }
            }
        }
        var_16 = *(u8 **)(var_16 + 0x24);
loop_00461A40_test:
        if (var_16 != NULL) {
            goto loop_00461A40_body;
        }
    }
}
// measured: closes opt_propagation around func_00461a40.
#pragma opt_propagation on
// FUN_00461BE0
void func_00461be0(u8 *arg0)
{
    s32 sp4C;
    s32 sp48;
    s32 temp_4_3;
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *var_16;
    u8 *var_17;
    u8 *var_17_2;
    u8 *var_17_3;
    u8 *var_17_4;

    temp_16 = *(u8 **)(arg0 + 0x1C);
    if (temp_16 != NULL) {
#pragma opt_propagation off
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            {
                void (**table)(s32, s32) =
                    (void (**)(s32, s32))(u32)D_00887300;
                table[0](6, 1);
                table[0](8, 1);
            }
        }
#pragma opt_propagation on
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x715FB);
        var_17 = *(u8 **)(temp_16 + 0xC);
        goto loop_00461BE0_first_test;
loop_00461BE0_first_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_17 + 0))) != 0) {
            if (*(s32 *)(var_17 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 - 0x14)) == 1) {
                temp_4 = *(u8 **)(var_17 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4 + 0x48)))(temp_4);
            }
            if (*(s32 *)(var_17 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_17 = *(u8 **)(var_17 + 0x24);
loop_00461BE0_first_test:
        if (var_17 != NULL) {
            goto loop_00461BE0_first_body;
        }
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x735FB);
        var_17_2 = *(u8 **)(temp_16 + 0x10);
        goto loop_00461BE0_second_test;
loop_00461BE0_second_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_17_2 + 0))) != 0) {
            if (*(s32 *)(var_17_2 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 - 0x10)) == 1) {
                temp_4_2 = *(u8 **)(var_17_2 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4_2 + 0x48)))(temp_4_2);
            }
            if (*(s32 *)(var_17_2 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_17_2 = *(u8 **)(var_17_2 + 0x24);
loop_00461BE0_second_test:
        if (var_17_2 != NULL) {
            goto loop_00461BE0_second_body;
        }
#pragma opt_propagation off
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            {
                void (**table)(s32, s32) =
                    (void (**)(s32, s32))(u32)D_00887300;
                table[0](6, 1);
                table[0](8, 0);
            }
        }
#pragma opt_propagation on
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        var_17_3 = *(u8 **)(temp_16 + 0x14);
        goto loop_00461BE0_third_test;
loop_00461BE0_third_body:
        sp48 = 0;
        temp_4_3 = *(s32 *)(*(u8 **)(var_17_3 + 0) + 0x18);
        if (temp_4_3 != 0) {
            func_003c21e0(temp_4_3, func_00461530, &sp48);
            if (sp48 == 0 &&
                func_003e8200(*(s32 *)D_008872E0,
                              func_003bfae0(*(s32 *)(var_17_3 + 0))) != 0) {
                if (*(s32 *)(var_17_3 + 4) == 1) {
                    D_00887304[0](0xE, &sp4C);
                    D_00887300[0](0xE, 0);
                }
                if (*((s32 *)((u8 *)&iGpffffaf60 - 0xC)) == 1) {
                    temp_4_4 = *(u8 **)(var_17_3 + 0);
                    ((void (*)(u8 *))(*(void **)(temp_4_4 + 0x48)))(temp_4_4);
                }
                if (*(s32 *)(var_17_3 + 4) == 1) {
                    D_00887300[0](0xE, sp4C);
                }
            }
        }
        var_17_3 = *(u8 **)(var_17_3 + 0x24);
loop_00461BE0_third_test:
        if (var_17_3 != NULL) {
            goto loop_00461BE0_third_body;
        }
        func_003f6440(2, 0x42);
        func_003f6440(3, 0x71801);
        var_17_4 = *(u8 **)(temp_16 + 0x28);
        goto loop_00461BE0_fourth_test;
loop_00461BE0_fourth_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_17_4 + 0))) != 0) {
            if (*(s32 *)(var_17_4 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 + 8)) == 1) {
                temp_4_5 = *(u8 **)(var_17_4 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4_5 + 0x48)))(temp_4_5);
            }
            if (*(s32 *)(var_17_4 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_17_4 = *(u8 **)(var_17_4 + 0x24);
loop_00461BE0_fourth_test:
        if (var_17_4 != NULL) {
            goto loop_00461BE0_fourth_body;
        }
        func_003f6440(2, 0x48);
        func_003f6440(3, 0x71801);
        var_16 = *(u8 **)(temp_16 + 0x24);
        goto loop_00461BE0_fifth_test;
loop_00461BE0_fifth_body:
        if (func_003e8200(*(s32 *)D_008872E0,
                          func_003bfae0(*(s32 *)(var_16 + 0))) != 0) {
            if (*(s32 *)(var_16 + 4) == 1) {
                D_00887304[0](0xE, &sp4C);
                D_00887300[0](0xE, 0);
            }
            if (*((s32 *)((u8 *)&iGpffffaf60 + 4)) == 1) {
                temp_4_6 = *(u8 **)(var_16 + 0);
                ((void (*)(u8 *))(*(void **)(temp_4_6 + 0x48)))(temp_4_6);
            }
            if (*(s32 *)(var_16 + 4) == 1) {
                D_00887300[0](0xE, sp4C);
            }
        }
        var_16 = *(u8 **)(var_16 + 0x24);
loop_00461BE0_fifth_test:
        if (var_16 != NULL) {
            goto loop_00461BE0_fifth_body;
        }
    }
}
// measured: opt_propagation off preserves the callback table pointer across jal calls while probing func_00462230.
#pragma opt_propagation off
// FUN_00462230
void func_00462230(u8 *arg0)
{
    u8 *self;
    u8 *work;
    void (**table)(s32, s32);

    self = arg0;
    work = *(u8 **)(self + 0x1C);
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        func_00477400(*(s32 *)(work + 0xDC), 1);
    }
    func_00476c70(work);
    if ((*(s32 *)(work + 0xE0) == 0) ||
        ((*(s32 *)(work + 0xD8) & 0x800) != 0)) {
        func_003f6440(2, *(s32 *)(work + 0xE4));
        func_003f6440(3, *(s32 *)(work + 0xE8));
        self = (u8 *)D_00887300;
        ((void (**)(s32, s32))self)[0](6, 1);
        ((void (**)(s32, s32))self)[0](8, 0);
        func_00479910(*(s32 *)(work + 0xDC));
    } else {
        table = D_00887300;
        table[0](6, 1);
        table[0](8, 0);
        *(u16 *)(self + 0x1A) |= 2;
        *(s32 *)(self + 0x1C) = *(s32 *)(work + 0xE0);
        func_00461560(self);
        func_00461a40(self);
        func_00461be0(self);
    }
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        func_00477400(*(s32 *)(work + 0xDC), 0);
    }
}
// measured: closes opt_propagation around func_00462230.
#pragma opt_propagation on
// FUN_004623A0
void func_004623a0(u8 *arg0)
{
    u8 *p;
    s8 sp2C[4];
    s8 *ptr;
    s32 count;
    u16 type;
    void (*start_cb)(u8 *, s32, void *);
    void (*end_cb)(u8 *, s32, void *);
    extern void func_003e82a0(s32, s8 *, s32);
    extern s32 func_003c9d00(u8 *);
    extern void *func_00462170(void *, void *);
    extern void func_00410420(void *, u32, void *, u32);
    extern void func_004104d0(void);
    extern void func_00410520(u32, void *, u32);
    extern void func_004106a0(s32);
    extern s32 func_00410800(s32, s32, s32);
    extern s32 func_00410930(s32, s32);
    extern void func_004815b0(void *);
    extern void func_00481660(void *);
    extern void func_004816d0(void *);
    extern void func_00481740(void *);
    extern void func_004818a0(void *);
    extern void func_004818c0(void *);
    extern void func_00475cd0(void *);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void (*D_00887314[])(s32, void *, s32, void *, s32);
    extern void (*D_00887308[])(s32, s32, s32, s32);
    extern void (*D_0088730C[])(s32, s32, s32, s32, s32);

    p = arg0;
    while (p != NULL) {
        start_cb = (void (*)(u8 *, s32, void *))*(u32 *)(p + 8);
        if ((start_cb != NULL) && (((*(u16 *)(p + 0x1A) & 1) == 0) || (*(u32 *)p != 0))) {
            start_cb(p + 0x1C, *(s32 *)(p + 0x10), (void *)start_cb);
        }

        type = *(u16 *)(p + 0x18);
        switch (type) {
        case 1:
            ptr = &sp2C[0];
            count = 4;
            if (ptr != NULL) {
                do {
                    *ptr = 0;
                    ptr++;
                    count--;
                } while (count != 0);
            }
            func_003e82a0(func_00457120(), &sp2C[0], *(s32 *)(p + 0x1C));
            break;
        case 2:
            D_00887300[0](*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20));
            break;
        case 3:
            func_003f6440(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20));
            break;
        case 4:
            {
                u8 *obj = *(u8 **)(p + 0x1C);
                ((void (*)(u8 *))*(u32 *)((u8 *)obj + 0x48))(obj);
            }
            break;
        case 5:
            func_00461560(p);
            func_00461a40(p);
            func_00461be0(p);
            break;
        case 6:
            func_00461560(p);
            break;
        case 7:
            func_00461a40(p);
            break;
        case 8:
            func_00461be0(p);
            break;
        case 9:
            func_003bff30(*(void **)(p + 0x1C), func_00462170, NULL);
            break;
        case 10:
            func_003c9d00(*(u8 **)(p + 0x1C));
            break;
        case 11:
            D_00887310[0](*(s32 *)(p + 0x1C), *(void **)(p + 0x20), *(s32 *)(p + 0x24));
            break;
        case 12:
            D_00887314[0](*(s32 *)(p + 0x1C), *(void **)(p + 0x20), *(s32 *)(p + 0x24), *(void **)(p + 0x28), *(s32 *)(p + 0x2C));
            break;
        case 13:
            D_00887308[0](*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28));
            break;
        case 14:
            D_0088730C[0](*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28), *(s32 *)(p + 0x2C));
            break;
        case 15:
            func_00410420(*(void **)(p + 0x1C), *(u32 *)(p + 0x20), *(void **)(p + 0x24), *(u32 *)(p + 0x28));
            break;
        case 16:
            func_004104d0();
            break;
        case 17:
            func_00410930(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20));
            break;
        case 18:
            func_00410800(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24));
            break;
        case 19:
            func_004106a0(*(s32 *)(p + 0x1C));
            break;
        case 20:
            func_00410520(*(u32 *)(p + 0x1C), *(void **)(p + 0x20), *(u32 *)(p + 0x24));
            break;
        case 21:
            func_004815b0(*(void **)(p + 0x1C));
            break;
        case 22:
            func_00481660(*(void **)(p + 0x1C));
            break;
        case 23:
            func_004816d0(*(void **)(p + 0x1C));
            break;
        case 24:
            func_00481740(*(void **)(p + 0x1C));
            break;
        case 25:
            func_004818a0(*(void **)(p + 0x1C));
            break;
        case 26:
            func_004818c0(*(void **)(p + 0x1C));
            break;
        case 27:
            func_00462230(p);
            break;
        case 28:
            func_00475cd0(*(void **)(p + 0x1C));
            break;
        default:
            break;
        }

        end_cb = (void (*)(u8 *, s32, void *))*(u32 *)(p + 0xC);
        if ((end_cb != NULL) && (((*(u16 *)(p + 0x1A) & 1) == 0) || (*(u32 *)p != 0))) {
            end_cb(p + 0x1C, *(s32 *)(p + 0x14), (void *)end_cb);
        }

        p = *(u8 **)p;
    }
}
// FUN_00462BF0
void func_00462bf0(u8 *arg0)
{
    u8 *current;
    s32 next;

    if (arg0 == NULL) {
        return;
    }
    while (*(s32 *)(arg0 + 8) != 0) {
        current = *(u8 **)(arg0 + 8);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 8) = next;
    }
    while (*(s32 *)(arg0 + 0x18) != 0) {
        current = *(u8 **)(arg0 + 0x18);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x18) = next;
    }
    while (*(s32 *)(arg0 + 0x1C) != 0) {
        current = *(u8 **)(arg0 + 0x1C);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x1C) = next;
    }
    while (*(s32 *)(arg0 + 0xC) != 0) {
        current = *(u8 **)(arg0 + 0xC);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0xC) = next;
    }
    while (*(s32 *)(arg0 + 0x10) != 0) {
        current = *(u8 **)(arg0 + 0x10);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x10) = next;
    }
    while (*(s32 *)(arg0 + 0x20) != 0) {
        current = *(u8 **)(arg0 + 0x20);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x20) = next;
    }
    while (*(s32 *)(arg0 + 0x14) != 0) {
        current = *(u8 **)(arg0 + 0x14);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x14) = next;
    }
    while (*(s32 *)(arg0 + 0x24) != 0) {
        current = *(u8 **)(arg0 + 0x24);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x24) = next;
    }
    while (*(s32 *)(arg0 + 0x28) != 0) {
        current = *(u8 **)(arg0 + 0x28);
        next = *(s32 *)(current + 0x24);
        jtbl_008873EC[0](current);
        *(s32 *)(arg0 + 0x28) = next;
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00462DF0
s32 func_00462df0(u8 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if ((*(s32 *)(arg0 + 0) == 0) ||
        ((*(s32 *)(arg0 + 0x10) == 0) &&
         (*(s32 *)(arg0 + 0xC) == 0) &&
         (*(s32 *)(arg0 + 0x14) == 0) &&
         (*(s32 *)(arg0 + 0x18) == 0) &&
         (*(s32 *)(arg0 + 0x1C) == 0) &&
         (*(s32 *)(arg0 + 0x24) == 0) &&
         (*(s32 *)(arg0 + 0x28) == 0))) {
        return 0;
    }
    return 1;
}
// FUN_004633C0
void func_004633c0(void *arg0, void *arg1)
{
    func_003bff30(arg0, func_004632f0, arg1);
}
// FUN_004633F0
s32 func_004633f0(void)
{
    f32 var_f0_2;
    f32 var_f0;
    s32 temp_2;
    s32 temp_4;

    func_0044f720();
    iGpffffba8c = func_003e23e0();
    func_003e82e0(func_00457120(), 0, 0);
    temp_4 = *(s32 *)0x10000000;
    iGpffffb198 = temp_4;
    temp_2 = temp_4 - iGpffffb194;
    var_f0 = (f32)(u32)temp_2;
    iGpffffbb20 = var_f0;
    var_f0_2 = (f32)(u32)temp_4;
    iGpffffbb1c = var_f0_2;
    iGpffffbb24 = 100.0f * ((*(f32 *)&iGpffffbb20) / 520.0f);
    *(s32 *)0x10000000 = 0;
    func_003e5510(0);
    func_00466600();
    func_00466c60();
    func_0050cd80();
    return 0;
}

// FUN_00463520
void func_00463520(void) {
    func_00451de0(D_00712670, 0x12C, 0, 0, (void *)func_004633f0, 0, 0);
}

/* Floor: 177 words (was 155) / fnalign 154 edits (was 257), obj 262 vs retail 264 (-2, inside gate, was exact 264/264 hiding an 83-instruction pure hole vs 91-instruction lump per 7aa). */
/* Hole fix first: palette entry `image + *(image+0x18) + i*4` and raw `dst = image + *(image+0x14)` added the image base to absolute pointers (Ghidra/IDA: entry = *(image+0x18)+i*4, dst = *(image+0x14); HSfdImage.palette/pixels at 0x18/0x14). */
/* Removing the base deletes the invented lump (object[116:207] 91) and recovers the missing retail palette (retail[129:212] 83); max pure delete is now 22 (retail[100:122] advance-before) with no pure lump >=25, so the composition gate passes. */
/* Palette now does three separate `*(u16*)(source+i*2)` loads (lhu exact, was -2 with cached `value`); advance uses a block-scope `s32 base` (0x20/0x10/0) with `source += (base*count*(1<<bit_depth))>>3` (two mults like retail, was two literal shift+mult blocks). Frame stays 0x50. */
/* Words rose 155->177 while edits fell 257->154: correct structure insertion per 7y (cf. func_00468ff0 898->911 while edits 674->316). Count -2 is inside the 2-instruction slack. */
/* Remaining wall: 22-hole advance-before (retail computes `base*count*(1<<...)>>3` before the palette into $t4 across jal 463870; hoisting it here costs a fifth saved reg, frame 0x60, edits 250 regress) plus the known 5-instruction per-branch default-body placement (costs 45 elsewhere, 200). Switch order 1,2/0xA,0x13/0x1B,0x14/0x24/0x2C unchanged. */
// FUN_00463930 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00463930(u8 *arg0)
{
    u8 *image;
    s32 bit_depth;
    u8 *source;
    s32 i;
    u8 *dst;
    extern u8 *func_003ea2c0(s32 width, s32 height, s32 depth);

    source = arg0 + 0x40;
    if ((*(u8 *)(arg0 + 0) != 2) ||
        (*(u8 *)(arg0 + 1) != 0) ||
        (*(u8 *)(arg0 + 8) != 0x54) ||
        (*(u8 *)(arg0 + 9) != 0x4D) ||
        (*(u8 *)(arg0 + 0xA) != 0x58) ||
        (*(u8 *)(arg0 + 0xB) != 0x30)) {
        return NULL;
    }
    switch (*(u8 *)(arg0 + 0x16)) {    case 1:
        bit_depth = 0x18;
        break;
    case 2:
    case 0xA:
        bit_depth = 0x10;
        break;
    case 0x13:
    case 0x1B:
        bit_depth = 8;
        break;
    case 0x14:
    case 0x24:

    case 0x2C:
        bit_depth = 4;
        break;
    default:
        if (*(u8 *)(arg0 + 0x16) == 0) {
            bit_depth = 0x20;
        } else {
            bit_depth = 0;
        }
        break;
    }
    if (bit_depth == 0) {
        return NULL;
    }
    if (bit_depth >= 0x10) {
        bit_depth = 0x20;
    }
    image = func_003ea2c0(*(u16 *)(arg0 + 0x12),
                          *(u16 *)(arg0 + 0x14), bit_depth);
    func_003ea3e0(image);
    if (*(u8 *)(arg0 + 0x10) != 0) {
        switch (*(u8 *)(arg0 + 0x11)) {        case 0:
            func_004637c0(image, (const u16 *)source);
            break;
                case 2:

        case 0xA:
            for (i = 0; i < (1 << *(s32 *)(image + 0xC)); i++) {
                u8 *entry = *(u8 **)(image + 0x18) + i * 4;
                entry[0] = (u8)((*(u16 *)(source + i * 2) & 0x1F) * 8);
                entry[1] = (u8)(((*(u16 *)(source + i * 2) >> 5) & 0x1F) * 8);
                entry[2] = (u8)(((*(u16 *)(source + i * 2) >> 0xA) & 0x1F) * 8);
                if (i == 0) {
                    entry[3] = 0;
                } else {
                    entry[3] = -1;
                }
            }
            break;
}
        func_00463870(image, bit_depth);
        {
            s32 base;
            if (*(u8 *)(arg0 + 0x11) == 0) {
                base = 0x20;
            } else if (*(u8 *)(arg0 + 0x11) == 0xA || *(u8 *)(arg0 + 0x11) == 2) {
                base = 0x10;
            } else {
                base = 0;
            }
            source += (base * *(u8 *)(arg0 + 0x10) * (1 << bit_depth)) >> 3;
        }
    }
    switch (*(u8 *)(arg0 + 0x16)) {    default:
        if (*(u8 *)(arg0 + 0x16) == 0) {
            func_00463570(image, source);
        }
        break;
        case 1:
        func_00463620(image, source);
        break;
    case 2:
    case 0xA:
        func_004636a0(image, source);
        break;
    case 0x13:
    case 0x1B:
        dst = *(u8 **)(image + 0x14);
        for (i = 0; i < *(s32 *)(image + 8); i++) {
            s32 j;

            for (j = 0; j < *(s32 *)(image + 4); j++) {
                dst[j] = *source;
                source++;
            }
            dst += *(s32 *)(image + 0x10);
        }
        break;
    case 0x14:
    case 0x24:

    case 0x2C:
        func_00463740(image, source);
        break;
}
    return image;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00463930);
#endif
// FUN_004645E0
void func_004645e0(void) {
    func_0043a978();
    func_004316a8(0);
    D_008E4B30[0] = 2;
    D_008E4B34[0] = 2;
    D_008E4B38[0] = 0;
    iGpffffbab4 = func_00431928(D_008E4B30, D_008E4800);
    iGpffffbab0 = 0;
}

// FUN_00464670
s32 func_00464670(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;

    temp_2 = func_00432ec0();
    switch (temp_2) {
    case -1:
        return -1;
    case 0:
        return 0;
    case 1:
        temp_3 = *arg0;
        switch (temp_3) {
        case 5:
        case 6:
            if (*arg1 < 0) {
                *arg2 = 0;
                temp_2_3 = *arg1;
                if (temp_2_3 < 0) {
                    *arg1 = temp_2_3 & 0xFFFF;
                }
            } else {
                *arg2 = 1;
            }
            break;
        default:
            if (*arg1 == 0) {
                *arg2 = 1;
            } else {
                *arg2 = 0;
            }
            temp_2_2 = *arg1;
            if (temp_2_2 < 0) {
                *arg1 = temp_2_2 & 0xFFFF;
            }
            break;
        }
        return 1;
    default:
        return -1;
    }
}
// FUN_00466280
s32 func_00466280(void)
{
    s32 sp1c;
    s32 sp18;
    s32 sp14;
    s32 temp_6;

    func_00440b68(D_00712950, D_00764BC0);
    switch (D_00764BC0) {
    case 0:
        sp1c = 0;
        sp18 = 0;
        if (func_00464670(&sp1c, &sp18, &sp14) == -1) {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            D_00764BC0 = 1;
        }
        goto done;
    case 1:
        if (func_00464670(&sp1c, &sp18, &sp14) == 1) {
            if (sp14 == 0) {
                switch (sp18) {
                case 0x6F:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9003:
                    sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
                    goto done;
                case 0x9001:
                    return -4;
                case 0x2F:
                    return 100;
                default:
                    return -9;
                }
            } else {
                if (D_008E4B20[0] == 2) {
                    if (D_008E4B28[0] >= 0xE6) {
                        return 100;
                    }
                    D_00764BC0 = 2;
                    goto done;
                }
                return -1;
            }
        }
        goto done;
    case 2:
        if (func_00464670(&sp1c, &sp18, &sp14) == -1) {
            temp_6 = D_00764BB8;
            func_00442088(D_008E4A20, D_007127D0, temp_6, temp_6);
            func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
            D_00764BC0 = 3;
        }
        goto done;
    case 3:
        if (func_00464670(&sp1c, &sp18, &sp14) == 1) {
            if (sp14 == 0) {
                switch (sp18) {
                case 0x9003:
                    return -5;
                case 0x6F:
                    return -5;
                case 0x16:
                    return -5;
                case 0x13:
                    return -5;
                case 2:
                    return -6;
                default:
                    goto done;
                }
            } else {
                return 100;
            }
        }
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}
// FUN_00466600
void func_00466600(void) {
    s32 sp20[12];
    s32 r;

    r = func_0042ba70();
    if (uGpffffb230 != 0) {
        func_004216e0(D_00724BC8, sp20);
        if (sp20[0] == 0xC) {
            goto call;
        }
        if (sp20[0] != 8) {
            goto skip;
        }
call:
        func_00421770(D_00724BC8);
    }
skip:
    if (r == 0) {
        func_0042ba20();
    }
}

/* 512/512 bytes; ten fully resolved relocations.
 * A real interrupt-state local retains the retail spill under register pressure. */
#pragma opt_loop_invariants on
// FUN_004667D0
u8 *func_004667d0(s32 kind, const char *name, const char *path,
                    s32 flags, s32 source, s32 buffer, s32 byteCount,
                    const char *cacheName, s32 resultKind, s32 memoryKind)
{
    extern void *func_0043f9c8(void *dst, s32 value, u32 size);
    extern char *func_00442830(char *dst, const char *src);
    s32 lock;
    u8 *last;
    u8 *request;
    s16 i;

    last = D_008E4B50;
    lock = func_0042ba20();
    for (;;) {
        if (*(u8 **)last == NULL) {
            i = 0;
            for (; i < 256; i++) {
                if (*(s32 *)(D_008E4D30 + i * 0x1DC) == 0) {
                    *(s32 *)(D_008E4D30 + i * 0x1DC) = 1;
                    request = D_008E4D30 + i * 0x1DC + 4;
                    func_0043f9c8(request, 0, 0x1D8);
                    goto allocated;
                }
            }
            request = NULL;
        allocated:
            *(u8 **)(request + 0) = NULL;
            request[0x24] = 0;
            if (name != NULL) {
                func_00442830((char *)request + 0x24, name);
            }
            request[0xA4] = 0;
            if (path != NULL) {
                func_00442830((char *)request + 0xA4, path);
            }
            *(s32 *)(request + 8) = source;
            *(s32 *)(request + 0x1A4) = 0;
            *(s32 *)(request + 0x1A8) = flags;
            *(s32 *)(request + 0x1AC) = kind;
            *(s32 *)(request + 0x1C4) = buffer;
            *(s32 *)(request + 0x1C0) = byteCount;
            request[0x124] = 0;
            *(s32 *)(request + 0x20) = resultKind;
            *(s32 *)(request + 0x1CC) = memoryKind;
            *(s16 *)(request + 0x1D4) = 0;
            if (cacheName != NULL) {
                func_00442830((char *)request + 0x124, cacheName);
            }
            *(u8 **)(request + 4) = last;
            *(u8 **)last = request;
            if (lock != 0) {
                func_0042ba70();
            }
            return request;
        }
        last = *(u8 **)last;
    }
}
#pragma opt_loop_invariants reset
// FUN_004669D0
u8 *func_004669d0(u8 *arg0, s32 *arg1, s32 *arg2)
{
    s32 lock;
    u8 *next;
    u8 *result;
    u8 *entry;
    u8 *table;
    s16 i;

    if (arg0 == NULL) {
        return NULL;
    }
    lock = func_0042ba20();
    if (*(s32 *)(arg0 + 0x1A4) != 3) {
        goto failed;
    }
    next = *(u8 **)(arg0 + 4);
    if (next == NULL) {
        goto failed;
    }
    *(u8 **)(next + 0) = *(u8 **)(arg0 + 0);
    if (*(u8 **)(arg0 + 0) != NULL) {
        *(u8 **)(*(u8 **)(arg0 + 0) + 4) = next;
    }
    switch (*(s32 *)(arg0 + 0x1AC)) {
    case 0:
        result = *(u8 **)(arg0 + 0x1B4);
        break;
    case 1:
        result = *(u8 **)(arg0 + 0x10);
        *arg2 = *(s32 *)(arg0 + 8);
        break;
    case 2:
        func_003e9680(*(s32 *)(*(u8 **)(arg0 + 0xC) + 4));
        result = *(u8 **)(arg0 + 0xC);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    case 3:
        result = *(u8 **)(arg0 + 0x14);
        break;
    case 4:
        result = *(u8 **)(arg0 + 0x1BC);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    case 5:
        result = *(u8 **)(arg0 + 0x18);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    case 6:
        result = *(u8 **)(arg0 + 0x1C);
        break;
    case 7:
        result = *(u8 **)(arg0 + 0x1C8);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    case 8:
        result = *(u8 **)(arg0 + 0x1D0);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    case 9:
        result = *(u8 **)(arg0 + 0x1B8);
        if (arg2 != NULL) {
            *arg2 = (s32)result;
        }
        break;
    case 10:
        result = *(u8 **)(arg0 + 0x1C4);
        if (arg2 != NULL) {
            *arg2 = (s32)result;
        }
        break;
    case 11:
        result = *(u8 **)(arg0 + 0x1C);
        if (arg2 != NULL) {
            *arg2 = *(s32 *)(arg0 + 8);
        }
        break;
    }
    i = 0;
    table = (u8 *)D_008E4D30;
    while (i < 0x100) {
        entry = table + i * 0x1DC;
        if (*(s32 *)entry != 0 && arg0 == entry + 4) {
            *(s32 *)entry = 0;
            break;
        }
        i++;
    }
    *arg1 = 1;
    if (lock != 0) {
        func_0042ba70();
    }
    return result;
failed:
    *arg1 = 0;
    if (lock != 0) {
        func_0042ba70();
    }
    return NULL;
}
typedef struct FilerEntry {
    char name[256];
    s32 type;
    s32 active;
} FilerEntry;

typedef struct FilerTable {
    u8 path[256];
    FilerEntry entries[2000];
} FilerTable;

typedef struct FilerStat {
    u32 mode;
    u32 attr;
    u32 size;
    u8 ctime[8];
    u8 atime[8];
    u8 mtime[8];
    u32 hisize;
    u32 private_0;
    u32 private_1;
    u32 private_2;
    u32 private_3;
    u32 private_4;
    u32 private_5;
} FilerStat;

/* Extended directory entry: 64-byte stat, 256-byte name, trailing word.
 * Layout: PCSX2 IopBios.cpp, revision 9fe8235e, fxio_dirent_t.
 * Natural four-byte alignment, not modern ps2sdk's aligned(64) variant. */
typedef struct FilerDirent {
    FilerStat stat;
    char name[256];
    u32 unknown;
} FilerDirent;


// FUN_004673C0
/* measured: MWCCPS2 b210 -O2, 1204B/window 1216B, 12 resolved relocations,
 * 12 zero alignment bytes. Ghidra and IDA agree on the 2000-entry cap,
 * type/name ordering, and 264-byte record copies; both split the local
 * directory entry, whose complete 324-byte backend layout supplies the frame. */
void func_004673c0(u8 *work)
{
    extern s32 func_00428550(u8 *path);
    extern s32 func_00428780(s32 handle, void *out);
    extern s32 func_00428618(s32 handle);
    extern char iGpffffb01c;
    FilerDirent dirent;
    FilerEntry selected;
    FilerEntry swapped;
    s32 handle;
    s16 readIndex;
    s16 clearIndex;
    s32 compareIndex;
    s32 sortIndex;
    s32 shouldSwap;
    u8 *sortEntry;
    s16 *count;

    *(s16 *)(work + 0x80F86) = 0;
    for (clearIndex = 0; clearIndex < 2000; clearIndex++) {
        ((FilerTable *)work)->entries[clearIndex].active = 0;
    }
    handle = func_00428550(work);
    for (readIndex = 0; readIndex < 2000; readIndex++) {
        if (func_00428780(handle, &dirent) <= 0) {
            break;
        }
        (*(s16 *)(work + 0x80F86))++;
        dirent.stat.mode &= 0xF000;
        ((FilerTable *)work)->entries[readIndex].active = 1;
        switch (dirent.stat.mode) {
        case 0x1000:
            ((FilerTable *)work)->entries[readIndex].type = 1;
            func_00442088(((FilerTable *)work)->entries[readIndex].name, &iGpffffb01c, dirent.name);
            break;
        case 0x2000:
            ((FilerTable *)work)->entries[readIndex].type = 0;
            func_00442088(((FilerTable *)work)->entries[readIndex].name, &iGpffffb01c, dirent.name);
            break;
        case 0x4000:
            ((FilerTable *)work)->entries[readIndex].type = 2;
            func_00442088(((FilerTable *)work)->entries[readIndex].name, &iGpffffb01c, dirent.name);
            break;
        }
    }
    func_00428618(handle);
    if (*(s16 *)(work + 0x80F86) >= 2) {
        for (sortIndex = 0; sortIndex < *(s16 *)(work + 0x80F86); sortIndex++) {
            sortEntry = work + sortIndex * 0x108;
            selected = *(FilerEntry *)(sortEntry + 0x100);
            compareIndex = sortIndex;
            count = (s16 *)(work + 0x80F86);
            for (; compareIndex < *count; compareIndex++) {
                shouldSwap = 0;
                switch (selected.type) {
                case 2:
                    if (((FilerTable *)work)->entries[compareIndex].type == 2) {
                        if (func_004426e8(((FilerTable *)work)->entries[compareIndex].name, selected.name) <= 0) {
                            shouldSwap = 1;
                        }
                    }
                    break;
                case 1:
                    if (((FilerTable *)work)->entries[compareIndex].type == 2) {
                        shouldSwap = 1;
                    }
                    if (((FilerTable *)work)->entries[compareIndex].type == 1) {
                        if (func_004426e8(((FilerTable *)work)->entries[compareIndex].name, selected.name) <= 0) {
                            shouldSwap = 1;
                        }
                    }
                    break;
                case 0:
                    if (((FilerTable *)work)->entries[compareIndex].type == 2) {
                        shouldSwap = 1;
                    }
                    if (((FilerTable *)work)->entries[compareIndex].type == 1) {
                        shouldSwap = 1;
                    }
                    if (((FilerTable *)work)->entries[compareIndex].type == 0) {
                        if (func_004426e8(((FilerTable *)work)->entries[compareIndex].name, selected.name) <= 0) {
                            shouldSwap = 1;
                        }
                    }
                    break;
                }
                if (shouldSwap != 0) {
                    swapped = ((FilerTable *)work)->entries[compareIndex];
                    ((FilerTable *)work)->entries[compareIndex] = selected;
                    *(FilerEntry *)(sortEntry + 0x100) = swapped;
                    selected = swapped;
                }
            }
        }
    }
}
// FUN_00467880
/* measured: honest void *table plus explicit function-pointer casts; object 848B/window 848B/nd 0; no H001 waiver. */
void func_00467880(u8 *arg0)
{
    extern void func_003e8110(s32 arg0);
    extern s32 func_003e8120(s32 arg0);
    extern void func_00450050(s64 arg0, char *arg1, ...);
    extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 farg0, s32 arg2);
    extern char iGpffffb01c;
    extern u8 D_00712A20[];
    extern u8 D_00712A30[];
    struct Work {
        s32 field40;
        f32 field44;
        s32 field48;
        s32 field4c;
        s32 pair0;
        f32 pair4;
        s32 field58;
        s8 color0;
        s8 color1;
        s8 color2;
        s8 color3;
    } work;
    s16 i;
    u8 *entry;
    u8 *data;
    s32 kind;
    void *table;

    if (func_003e8120(func_00457120()) != 0) {
        D_00887304[0](0xE, &work.field58);
        table = D_00887300;
        (*(void (**)(s32, s32))table)(0xE, 0);
        work.pair0 = 0x40800000;
        work.pair4 = 4.0f;
        func_00450050(*(s64 *)(void *)&work.pair0, &iGpffffb01c, arg0);
        work.pair4 += 2.0f;
        i = 0;
        while (i < 10) {
            entry = arg0 + (*(s16 *)(arg0 + 0x80F84) + i) * 0x108;
            data = entry + 0x100;
            if (*(s32 *)(entry + 0x204) == 0) {
                break;
            }
            kind = *(s32 *)(data + 0x100);
            switch (kind) {
            case 0:
                func_00450050(*(s64 *)(void *)&work.pair0,
                              &iGpffffb01c, data);
                break;
            case 1:
                func_00450050(*(s64 *)(void *)&work.pair0,
                              (char *)&D_00712A20, data);
                break;
            default:
                func_00450050(*(s64 *)(void *)&work.pair0,
                              (char *)&D_00712A30, data);
                break;
            }
            work.pair4 += 1.0f;
            i++;
        }
        work.field40 = 0x30;
        *(s32 *)(void *)&work.field44 = 0x30;
        work.field48 = 0x190;
        work.field4c = 0x90;
        *(u8 *)(void *)&work.color3 = 0xFF;
        work.color2 = 0x1E;
        work.color1 = 0x1E;
        work.color0 = 0x1E;
        func_0045d6e0((u8 *)&work.color0,
                      (f32 *)(void *)&work.field40, 0.0f, 1);
        work.field40 = 0x30;
        *(s32 *)(void *)&work.field44 =
            (s32)(0.0f + 72.0f +
                  12.0f * (f32)*(s16 *)(arg0 + 0x80F82));
        work.field48 = 0x184;
        work.field4c = 0xC;
        *(u8 *)(void *)&work.color3 = 0xFF;
        *(u8 *)(void *)&work.color2 = 0xFF;
        work.color1 = 0x50;
        work.color0 = 0x50;
        func_0045d6e0((u8 *)&work.color0,
                      (f32 *)(void *)&work.field40, 0.0f, 1);
        work.field40 = 0x1B4;
        *(s32 *)(void *)&work.field44 =
            (s32)(72.0f +
                  (f32)(((*(s16 *)(arg0 + 0x80F82) +
                          *(s16 *)(arg0 + 0x80F84)) *
                         0x78) /
                        *(s16 *)(arg0 + 0x80F86)));
        work.field48 = 0xC;
        work.field4c = 0x78 / *(s16 *)(arg0 + 0x80F86);
        *(u8 *)(void *)&work.color3 = 0xFF;
        *(u8 *)(void *)&work.color2 = 0x80;
        *(u8 *)(void *)&work.color1 = 0x80;
        *(u8 *)(void *)&work.color0 = 0x80;
        func_0045d6e0((u8 *)&work.color0,
                      (f32 *)(void *)&work.field40, 0.0f, 1);
        (*(void (**)(s32, s32))table)(0xE, work.field58);
        func_003e8110(func_00457120());
    }
}
/* measured: base 277wd (reloc-masked) / fnalign 344 edits, obj 976B/window 1264B (-288B), retail 312/object 244 instrs (-68); */
/* census 48 (opclass, unusually clean): addu -40, lui -27, addiu +7, sll -6, move +5, lbu +4, lh -4, lb -4, bne +3, andi -2, mtc1 +1 (jal +1 from __fixsfdi, sw/lw -2). */
/* 2026-09-19 addressing pass (7k/7p) following func_0045b7c0 template (slot_cast 439, both_cast 257, decl 228, hoist 523 rejected): */
/* slot_cast (25 D_00800000+w+off to (char*)D+...) 277 tie, census 48; both_cast (w-based (char*)w+...) 277 tie; subscript (2 u8** to &D[w+...]) 277 tie, census 47 (addu+2/lui+1/addiu+3); fullsub (all 25) 282 regress; */
/* parens D+(w+off) 282 regress (addu+10/addiu+11); swap/u32w ties; noehoist (e hoist removed) 276 (-1); hoistbase (D+w hoisted) 280 regress, census 50; hoiststr (string base) 277 tie; */
/* inline_h (h1/h2 inlined for e+3 sites) 282 (+5) but census 40 (-8: addu+9/sll+6/lh+6, sll fixed, lh +2 over) / edits 297 (-47) / 268 instrs (+24); selective 1-site 280/280/277 census 44, 2-site 284/279/279 census 40 (lh 0 exact), 3-site 282 census 40 (lh+2 over); */
/* best inline_23_sub (sites 2+3 inlined for both 442088 + 2 u8** subscript) 268 (-9) / edits 330 (-14) / 267 instrs (+23) / 1068B (+92) / census 39 (-9: addu -32, lui -26, addiu +13, sll -2, move +3, lbu+4/lb-4, lh 0, bne+3, andi-2, mtc1+1); tie inline_13_sub 268/342 edits; full23sub 285 regress; */
/* decl placement ties at 277 (6 orders) and at 268 (3 orders on best); pragma ties (loopinv/unroll/sched) and comsubs_off 328 (+51) / inline+comsubs 335 regress; solve_signedness mismatch 12, all flips reject/free (tmp free, st/i/k count moves, h1/h2 +2, flag constrained); slti $at + short-by-N hunts from prior note carry (neutral); */
/* remaining wall: D_00800000+w hoist (retail rematerializes lui/addu per access, b210 CSEs to saved regs; 25-use respell neutral per archive), frame 0xA0 vs 0x170 (fewer spills; tmp[64] only), __fixsfdi/mtc1+1 + jal+1 from (s64)f1 float pack vs retail lui/sw/ld, iGp HI/LO-vs-GPREL phantoms, st==4/3 empty-arm branch layout; production stays ASM. */
/* gate 2026-09-19: missing (D_008C0276 & 0x10)!=0 arm (retail 0x467eec bnez */
/* to shared truncation block at 0x467ce8, 0x467cf4-0x467d90 i/k loops + st=1): */
/* object 267 vs retail 312 (-45) before; duplicate i/k loops + st=1 return as */
/* else of the 0x10 check -> object 311 vs retail 312 (-1, inside 303-321 gate). */
/* Prior addressing/inline/decl/pragma/signedness hunts above carry (do not redo). */
// FUN_00467BD0 NONMATCHING
#ifdef SKIP_ASM
s32 func_00467bd0(u8 *arg0)
{
    s32 w;
    s16 st;
    u16 i;
    u16 k;
    s16 h1;
    s16 h2;
    s32 e;
    s32 v;

    w = *(s32 *)(arg0 + 56);
    st = *(s16 *)(D_00800000 + w + 3968);
    if (st == 4) {
    } else if (st == 3) {
    } else if (st == 2) {
        if ((D_008C0276 & 0x40) != 0) {
            h1 = *(s16 *)(D_00800000 + w + 3970);
            h2 = *(s16 *)(D_00800000 + w + 3972);
            e = w + (h1 + h2) * 264;
            v = *(s32 *)(e + 512);
            if (v == 1) {
                if (func_004426e8((const char *)iGpffffb020, (const char *)(e + 256)) != 0) {
                    if (func_004426e8((const char *)iGpffffb024, (const char *)(w + (h1 + h2) * 264 + 256)) == 0) {
                        *(s16 *)(D_00800000 + w + 3968) = 1;
                        return 0;
                    }
                    func_00442088((char *)w, (const char *)iGpffffb028, (char *)w, (char *)(w + (*(s16 *)(D_00800000 + w + 3970) + *(s16 *)(D_00800000 + w + 3972)) * 264 + 256));
                    *(s16 *)(D_00800000 + w + 3968) = 1;
                    return 0;
                }
                i = 0;
                while (((i & 0xFFFF)) < 256) {
                    if (*(u8 *)(w + (i & 0xFFFF)) == 0) {
                        break;
                    }
                    i = (i + 1) & 0xFFFF;
                }
                k = i & 0xFFFF;
                while (((k & 0xFFFF)) >= 2) {
                    u8 *p = (u8 *)(w + (k & 0xFFFF));
                    if (*p == 47) {
                        if (*(p - 1) != 58) {
                            *(u8 *)(w + (k & 0xFFFF)) = 0;
                        } else {
                            *(p + 1) = 0;
                        }
                        break;
                    }
                    k = (k - 1) & 0xFFFF;
                }
                *(s16 *)(D_00800000 + w + 3968) = 1;
                return 0;
            }
            if (v == 0) {
                *(s32 *)(D_00800000 + w + 3976) = 1;
                func_00442088((char *)(w + 3984), (const char *)iGpffffb028, (char *)w, (char *)(w + (*(s16 *)(D_00800000 + w + 3970) + *(s16 *)(D_00800000 + w + 3972)) * 264 + 256));
                *(s16 *)(D_00800000 + w + 3968) = 3;
                return 0;
            }
        } else if ((D_008C0276 & 0x10) == 0) {
            if ((D_008C0276 & 0x80) != 0) {
                {
                    f32 f1 = 48.0f;
                    f32 f2 = 248.0f;
                    *(u8 * *)&D_00800000[w + 3984] = func_00468940((s64)f1, st);
                    *(s16 *)(D_00800000 + w + 3968) = 4;
                }
            } else if ((D_008C0276 & 0x20) != 0) {
                *(s32 *)(D_00800000 + w + 3976) = 0;
                *(s16 *)(D_00800000 + w + 3968) = 3;
                return 0;
            } else {
                {
                    u8 tmp[64];
                    func_00453670(tmp, 10, *(s16 *)(D_00800000 + w + 3974), *(s16 *)(D_00800000 + w + 3970), *(s16 *)(D_00800000 + w + 3972));
                    func_00453860(tmp, 0x4000, 0x1000, 0x2000, 0x8000);
                    if (func_00453960(tmp) != 0) {
                        *(s16 *)(D_00800000 + w + 3970) = *(s16 *)(tmp + 24);
                        *(s16 *)(D_00800000 + w + 3972) = *(s16 *)(tmp + 28);
                    }
                }
            }
        } else {
            i = 0;
            while (((i & 0xFFFF)) < 256) {
                if (*(u8 *)(w + (i & 0xFFFF)) == 0) {
                    break;
                }
                i = (i + 1) & 0xFFFF;
            }
            k = i & 0xFFFF;
            while (((k & 0xFFFF)) >= 2) {
                u8 *p = (u8 *)(w + (k & 0xFFFF));
                if (*p == 47) {
                    if (*(p - 1) != 58) {
                        *(u8 *)(w + (k & 0xFFFF)) = 0;
                    } else {
                        *(p + 1) = 0;
                    }
                    break;
                }
                k = (k - 1) & 0xFFFF;
            }
            *(s16 *)(D_00800000 + w + 3968) = 1;
            return 0;
        }
        func_00467880((u8 *)w);
    } else if (st == 4) {
        {
            u8 flag;
            if (func_004688d0(*(u8 * *)&D_00800000[w + 3984], &flag, st) != 0) {
                if (flag == 0) {
                    *(s16 *)(D_00800000 + w + 3968) = 2;
                } else {
                    *(s32 *)(D_00800000 + w + 3976) = 1;
                    func_00442088((char *)(w + 3984), (const char *)iGpffffb028, (char *)w, &flag);
                    *(s16 *)(D_00800000 + w + 3968) = 3;
                }
            }
            func_00467880((u8 *)w);
        }
    } else if (st == 1) {
        func_004673c0((u8 *)w);
        *(s16 *)(D_00800000 + w + 3972) = 0;
        *(s16 *)(D_00800000 + w + 3970) = 0;
        *(s16 *)(D_00800000 + w + 3968) = 2;
    } else if (st == 0) {
        *(s16 *)(D_00800000 + w + 3968) = 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467bd0);
#endif
// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0x38));
}



// FUN_004680F0
s32 func_004680f0(u8 *arg0, s8 *arg1) {
    u8 *temp_6;

    temp_6 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *arg1 = 0;
    if (*(s16 *)(temp_6 + 0x80F80) == 3) {
        if (*(s32 *)(temp_6 + 0x80F88) != 0) {
            func_00442830((char *)arg1, (char *)temp_6 + 0x80F90);
        }
        return 1;
    }
    return 0;
}

// FUN_00468A10
void func_00468a10(void)
{
    D_00922984[0] = 0;
    D_00922980[0] = 0;
    D_00922988[0] = 0;
    D_00922934[0] = 0;
    D_00922930[0] = 0;
    D_0092293C[0] = 0;
}
/* Measured: 652/656 bytes, eight resolved relocations and four zero tail bytes.
 * Request handles and resource tables are reloaded after their callbacks. */
#pragma opt_loop_invariants on
// FUN_00468D10
void func_00468d10(void)
{
    extern s32 func_00468bf0(u8 *node, s32 slot);
    extern s32 func_004c9820(ADXF request);
    extern void *func_0043f9c8(void *dst, s32 value, u32 count);
    extern void func_00456530(u8 *basePath, u8 *archive, s32 singleEntry);
    u8 *node;
    char *cursor;
    s8 value;
    s32 state;
    s32 slot;
    s32 phase;
    s32 character;
    s32 separator;
    s32 backslash;
    char path[0x100];

    node = (u8 *)D_00922930;
    do {
        state = *(s32 *)(node + 0xC);
        switch (state) {
        case 0:
            node = *(u8 **)(node + 4);
            break;
        case 1:
            *(s32 *)(node + 0x44) = 0;
            for (phase = 0; phase < 10; phase++) {
                if (func_00468bf0(node, phase) == 0) {
                    break;
                }
            }
            *(s32 *)(node + 0xC) = 2;
            /* fall through */
        case 2:
            phase = 1;
            for (slot = 0; slot < 10; slot++) {
                if (*(s32 *)(node + 0x10 + slot * 4) != 0) {
                    if (func_004c9820(*(ADXF *)(node + 0x10 + slot * 4)) == 3) {
                        func_004c8a60(*(ADXF *)(node + 0x10 + slot * 4));
                        *(s32 *)(node + 0x10 + slot * 4) = 0;
                        if (func_00468bf0(node, slot) == 1) {
                            phase = 0;
                        }
                    } else {
                        phase = 0;
                    }
                }
            }
            if (phase != 0) {
                *(s32 *)(node + 0xC) = 3;
            } else {
                node = NULL;
                break;
            }
            /* fall through */
        case 3:
            func_0043f9c8(path, 0, 0x100);
            backslash = 0x5C;
            for (character = 0; character < 0x100; character++) {
                value = *(s8 *)(*(u8 **)(node + 8) + character + 0x118);
                if (value != 0) {
                    path[character] = value;
                } else {
                    for (separator = character - 1;; separator--) {
                        cursor = path + separator;
                        if (cursor[-1] == backslash) {
                            *cursor = 0;
                            break;
                        }
                    }
                }
            }
            for (phase = 0;
                 phase < *(s32 *)(node + 0x40) - *(s32 *)(node + 0x3C);
                 phase++) {
                if ((*(s32 **)(node + 0x38))[phase] != 0) {
                    func_00456530((u8 *)path,
                                  (u8 *)(*(s32 **)(node + 0x38))[phase], 1);
                    (*(s32 **)(node + 0x38))[phase] += 0x100;
                }
            }
            *(s32 *)(node + 0xC) = 4;
            break;
        case 4:
            node = *(u8 **)(node + 4);
            break;
        }
    } while (node != NULL);
}
#pragma opt_loop_invariants reset
// FUN_00468FA0
s32 func_00468fa0(u8 *arg0) {
    u8 *ctx;
    u8 *task;

    ctx = *(u8 **)(arg0 + 0x38);
    task = func_00460990();
    *(void **)(task + 8) = (void *)func_00468ff0;
    *(u8 **)(task + 0x10) = ctx;
    func_00460ac0(*(char **)(ctx + 0x218), task);
    return 0;
}

/* Shortfall -88 SHORT, not banked: retail 1032 vs object 944 (band 1001-1063).
 * Candidate at /var/tmp/cold468ff0/cand_base_honest.c (honest 2-arg (s32,u8*) + D_00712Cxx/D_007130xx/D_008872F8 array + comsubs-off shape;
 * fnalign at /var/tmp/cold468ff0/fnalign_honest.txt; pragma/subscript/colour variants alongside).
 * Delete-side audit, all measured not assumed:
 * - jal counts equal (50 direct + 24 jalr; per-callee 1:1/3:3/2:2 etc. -> excluded, 0 missing calls).
 * - 12-entry jtbl_007566F0 switch cases match (0,2,3/4/5,6,7,8,9,10,11 with 1->default; explicit case 0/4/5 added) -> excluded.
 * - unsigned (f32)(u32): 2 sites as plain (f32)(u32) (retail add.s, not 2.0f*mul) -> excluded, 0 cost.
 * - dsll32/dsra32 0x10: retail 22 s16 pairs kept as s16 (0x1EA/0x1EE/loop counters) -> excluded.
 * - field-by-field vs aggregate: 0x100/0x104/0x108 + 0x10C colour stores match retail sw/swc1 counts -> excluded.
 * - defensive C: no extra null checks beyond retail beqz (all match) -> excluded, 0 extra.
 * Found shortfall (delete-side): frame retail 0x100 vs object 0xE0 (-32, excluded as smaller not bloat) +
 *   switch-3 lowering drift (largest net replaces, not deletes) + per-block scheduling drift (largest deletes:
 *   [577:579] len2, [607:610] len3, [757:759] len2, [776:777] len1; no single large delete).
 * - absolute-value idiom (~28) and 2.0f* multiply (~12) checked first per brief: body already uses plain
 *   (f32)(u32) + add.s and D_008872F8[0] absolute, so 0 overshoot there (object is SHORT, not long).
 * Free pragma probes on honest base (one call): opt_loop_invariants on 929->918 (-11), opt_unroll_loops off tie,
 *   schedule off tie, opt_common_subs off 929->863 (-66, kept).
 * Subscript probes tie (P[i] vs ((s32*)P)[i*10] 863->863; store subscript 863->863).
 * Register colouring 2 probes tie (decl-order swaps 892->892,892->892).
 * Honesty fixes regress but are faithful: dead switch-2 (863) -> explicit if/switch (892/893, +29/+30) and
 *   missing switch-3 cases 4/5 added (892->898, +6); dead omitted 0x1C0/0x04/0x05 arms so must keep honest.
 * Stopping: above 60, subscript tie + colour tie = two consecutive non-improving -> stop. */
/* measured 2026-09-18, gap closed: object 1033 against retail 1032 (+1,
   band 1001-1063), where the first reconstruction was 944 - 88 short.  The
   cause was two missing switch labels, `case 6` and `case 11`, worth about
   115 words of dead code, plus the switch-3 chain order, two table-base
   hoists and s32 temporary idioms.  `tools/jtbl.py` confirms the 12-entry
   table at 0x7566F0 with case 1 falling to default.
   Census after the fix: `jal` 50/50, `jalr` 24/24, `swc1` 26/26 all equal;
   `lwc1` 11/12 and `mtc1` 11/12; `dsll`/`dsra` 11/1 is loop-shape residue.
   fnalign edits fell 674 -> 316 while the differing-word score moved 898 ->
   911, which is positional noise from inserting correct structure, not a
   regression - the count and the edit list are the honest measures here.
   Remaining: nine small hunks, all explained, and a frame of 0xF0 against
   retail's 0x100 that wants a `move $s1, $s2` split this body does not
   reproduce.  The file-scope extern was `void func_00468ff0(void)`; retail's
   prologue reads $a1 (`daddu $16, $5, $0`), so it is now
   `(s32 arg0, u8 *arg1)`.  The only other reference is a function-pointer
   store cast to `void *`, which is unaffected. */
/* measured 2026-09-19: pragma opt_loop_invariants on (kept with comsubs off): retail 1033 object 1033 exact, words 911->911, edits 316->310 (-6, +69 reloc unchanged), lui +12 unchanged (70 object vs 58 retail; 0x437F 13 vs 3 remains: comsubs-off vs hoist tradeoff, manual c255 would go 1033->1027 (-6) with edits 316->318 (+2) so not taken; nopragma would go 1051 (+18) with edits 518 (+202) so not taken); frame 0xF0/0x100 unchanged, no large holes (largest deletes 2,1,1). */
// FUN_00468FF0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
#pragma opt_loop_invariants on
void func_00468ff0(s32 arg0, u8 *arg1) {
    extern s32 func_003d5fb0(u8 *arg0);
    extern void func_003d6010(u8 *arg0);
    extern s32 func_003df860(s32 arg0);
    extern void func_003ec330(s32 arg0);
    extern s32 func_003ec590(s32 a, s32 b, s32 c, s32 d);
    extern void func_0040fcd0(s32 a, s32 b);
    extern s32 func_00418f50(s32 arg0);
    extern void func_00419520(void *a0, s32 a1, s32 a2);
    extern void func_0043f810(void *dst, s32 src, s32 size);
    extern void func_0043f9c8(u8 *dst, s32 val, s32 size);
    extern void func_00440b68(u8 *arg0, ...);
    extern void func_0044ea90(void *arg0, s32 arg1);
    extern void func_0044ec50(s32 arg0);
    extern void func_00450050(s64 arg0, void *arg1, ...);
    extern void func_00452040(s32 arg0);
    extern void func_004561a0(void *handle, void *path, s32 sync);
    extern s32 func_00457120(void);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern s32 func_00508310(u8 *arg0);
    extern s32 func_00509268(u8 *arg0);
    extern void func_005097e8(s32 arg0);
    extern void func_0050a008(s32 arg0, s32 arg1);
    extern void func_0050a1c0(s32 arg0, void *arg1);
    extern void func_0050aae0(s32 arg0);
    extern s32 func_0050d4d0(s32 arg0);
    extern void func_0050ffc8(s32 arg0);
    extern void func_001228a0(s32 r, s32 g, s32 b);
    extern void func_00143ba0(s32 src, u32 owner, s32 t0, s32 t1);
    extern s32 iGpffffbaf0;
    extern s32 iGpffffbaf4;
    extern u8 D_0070B610[];
    extern s32 D_0070B620;
    extern u8 D_00712C50[];
    extern u8 D_00712C54[];
    extern u8 D_00712C5C[];
    extern u8 D_00712C60[];
    extern u8 D_00712C64[];
    extern u8 D_00712C6C[];
    extern u8 D_00712C70[];
    extern u8 D_00712C72[];
    extern u8 D_00712C74[];
    extern u8 D_00712FF8[];
    extern u8 D_00713010[];
    extern u8 D_00713030[];
    extern u8 D_00713040[];
    extern u8 D_00713050[];
    extern u8 D_00713068[];
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void *(*D_008873F4[])(u32, u32, u32);
    extern void *(*jtbl_008873E8[])(s32, s32);
    extern u16 D_008C024E[];

    s32 sp60[36];
    s32 spFC;
    s32 spF4;
    s32 spF0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    s16 temp_3;
    s16 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_8;
    s16 temp_3_9;
    s16 temp_4_4;
    s32 temp_5;
    s32 *var_6_2;
    void (**tbl300a)(s32, s32);
    void (**tbl300b)(s32, s32);
    void (**tblEC)(void *);
    s32 temp_2;
    s32 temp_2_3;
    s32 temp_3_4;
    s32 temp_3_6;
    s32 temp_4_12;
    s32 temp_4_13;
    s32 temp_4_16;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_5;
    s32 temp_4_8;
    s32 temp_4_9;
    s32 temp_5_2;
    s32 temp_5_4;
    s32 temp_6;
    s32 var_4;
    s32 var_6;
    s32 var_7;
    s32 var_7_2;
    s64 temp_2_2;
    s64 temp_3_7;
    s32 var_6_3;
    s32 var_7_3;
    s32 var_9;
    u32 temp_3_2;
    u32 temp_4;
    u32 temp_4_10;
    u32 temp_4_11;
    u32 temp_4_14;
    u32 temp_4_15;
    u32 temp_4_6;
    u32 temp_4_7;
    u32 temp_5_6;
    u8 *temp_17;
    f32 *fb34;
    u8 *db34;
    u8 *temp_5_3;
    u8 *temp_5_5;
    u8 *temp_8;
    u8 *var_5;
    (void)arg0;

    temp_5 = (*(s16 *)((u8 *)(arg1) + (0x1E4)));
    switch (temp_5) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if ((*(s32 *)((u8 *)(arg1) + (0x1FC))) != 0) {
            (*(s32 *)((u8 *)(arg1) + (0x1FC))) = 0;
            func_003d5fb0(D_0070B610);
        }
        if ((*(s32 *)((u8 *)(arg1) + (0x1F4))) != 0) {
            (*(s32 *)((u8 *)(arg1) + (0x204))) = 0;
            (*(s32 *)((u8 *)(arg1) + (0x208))) = 0;
            (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 2;
        }
    default:                                        /* switch 1 */
        return;
    case 2:                                         /* switch 1 */
        temp_f20 = 1.0f / (*(f32 *)((u8 *)func_00457120() + (0x80)));
        temp_3 = (*(s16 *)((u8 *)(arg1) + (0x1EE))) + 1;
        (*(s16 *)((u8 *)(arg1) + (0x1EE))) = temp_3;
        if (temp_3 == 1) {
            (*(s32 *)((u8 *)(arg1) + (0x1FC))) = 1;
        }
        if ((*(s16 *)((u8 *)(arg1) + (0x1EE))) == 6) {
            if (func_003df860(D_0070B620) != 0) {
                func_0046d730(D_00712FF8, 0x120);
            }
            func_003d6010(D_0070B610);
        }
        if ((*(s16 *)((u8 *)(arg1) + (0x1EE))) == 0xA) {
            func_00440b68(D_00713010);
            (*(s32 *)((u8 *)(arg1) + (0xD8))) = (*(s32 *)(D_00712C64 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)));
            temp_17 = (u8 *)(arg1 + 8);
            func_0043f9c8(temp_17, 0, 0x30);
            (*(s32 *)((u8 *)(temp_17) + (0x20))) = 0x11;
            (*(s32 *)((u8 *)(arg1) + (8))) = 1;
            (*(s32 *)((u8 *)(temp_17) + (4))) = 0x4C4B40;
            (*(s32 *)((u8 *)(temp_17) + (8))) = (*(s32 *)(D_00712C5C + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)));
            (*(s32 *)((u8 *)(temp_17) + (0xC))) = (*(s32 *)(D_00712C60 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)));
            (*(s32 *)((u8 *)(temp_17) + (0x10))) = 2;
            (*(s32 *)((u8 *)(temp_17) + (0x14))) = 1;
            (*(s32 *)((u8 *)(temp_17) + (0x24))) = 2;
            (*(s32 *)((u8 *)(temp_17) + (0x1C))) = (s32)(func_00508310(temp_17));
            func_0044ec50(1);
            func_0044ea90(D_00712FF8, 0x135);
            (*(u32 *)((u8 *)(arg1) + (0x1E0))) = (u32)(jtbl_008873E8[0]((*(s32 *)((u8 *)(temp_17) + (0x1C))) + 0x40, 0x40000));
            func_0044ea90(D_00712FF8, 0x136);
            (*(u32 *)((u8 *)(arg1) + (0x200))) = (u32)(D_008873F4[0](1U, 0x118000, 0x40000));
            func_0044ec50(0);
            func_00440b68(D_00713030, (*(u32 *)((u8 *)(arg1) + (0x1E0))));
            temp_3_2 = (*(u32 *)((u8 *)(arg1) + (0x1E0)));
            if ((temp_3_2 == 0) || ((*(u32 *)((u8 *)(arg1) + (0x200))) == 0)) {
                func_00440b68(D_00713040);
                (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0xB;
                return;
            }
            (*(u32 *)((u8 *)(temp_17) + (0x18))) = temp_3_2;
            (*(u32 *)((u8 *)(arg1) + (0xD4))) = temp_3_2;
            temp_2 = func_00509268(temp_17);
            if (temp_2 == 0) {
                tblEC = (void (**)(void *))(u32)jtbl_008873EC;
                tblEC[0]((void *)(*(u32 *)((u8 *)(arg1) + (0x1E0))));
                (*(u32 *)((u8 *)(arg1) + (0x1E0))) = 0U;
                temp_4 = (*(u32 *)((u8 *)(arg1) + (0x200)));
                if (temp_4 != 0) {
                    tblEC[0]((void *)temp_4);
                    (*(u32 *)((u8 *)(arg1) + (0x200))) = 0U;
                    iGpffffbae8 = 0U;
                }
            }
            func_0050a008(temp_2, 0);
            (*(s32 *)((u8 *)(arg1) + (4))) = temp_2;
            if ((*(s32 *)((u8 *)(arg1) + (0xD8))) != 0) {
                func_004561a0((void *)temp_2, *(u8 **)(D_00712C54 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)), 1);
            } else {
                func_004561a0((void *)temp_2, *(u8 **)(D_00712C54 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)), 0);
            }
            func_0044ec50(1);
            temp_3_3 = (*(s16 *)(D_00712C50 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)));
            switch (temp_3_3) {
            case 0:
                (*(s32 *)((u8 *)(arg1) + (0xD0))) = func_003ec590(0x280, 0x1C0, 0x20, 0x584);
                break;
            case 1:
                (*(s32 *)((u8 *)(arg1) + (0xD0))) = func_003ec590(0x280, 0x170, 0x20, 0x584);
                break;
            }
            func_0044ec50(0);
            if ((*(s32 *)((u8 *)(arg1) + (0xD0))) == 0) {
                (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0xB;
                return;
            }
            var_9 = 0;
            fb34 = D_008872F8;
            db34 = D_00712C50;
loop_34:
            if (var_9 < 4) {
                temp_8 = (u8 *)(arg1 + (var_9 << 6));
                (*(f32 *)((u8 *)(temp_8) + (0xE8))) = fb34[0];
                (*(f32 *)((u8 *)(temp_8) + (0xF8))) = temp_f20;
                if ((*(s32 *)(db34 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28) + (0x1C))) != 0) {
                    (*(s32 *)((u8 *)(temp_8) + (0x100))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x104))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x108))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x10C))) = 0;
                    (*(s16 *)((u8 *)(arg1) + (0x1E6))) = (*(s16 *)(db34 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28) + (0x22)));
                    (*(s16 *)((u8 *)(arg1) + (0x1E8))) = 0;
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 3;
                } else {
                    (*(s32 *)((u8 *)(temp_8) + (0x100))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x104))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x108))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_8) + (0x10C))) = 0x437F0000;
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 3;
                }
                var_9 = (var_9 + 1);
                goto loop_34;
            }
            temp_f21 = (f32)(*(s32 *)((u8 *)(*(u8 **)((u8 *)func_00457120() + (0x60))) + (0xC)));
            temp_f20_2 = (f32)(*(s32 *)((u8 *)(*(u8 **)((u8 *)func_00457120() + (0x60))) + (0x10)));
            temp_f2 = 1.0f / (*(f32 *)((u8 *)func_00457120() + (0x80)));
            if ((*(s16 *)(D_00712C50 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28))) == 0) {
                (*(s32 *)((u8 *)(arg1) + (0xE0))) = 0;
                (*(s32 *)((u8 *)(arg1) + (0x120))) = 0;
                (*(f32 *)((u8 *)(arg1) + (0x160))) = temp_f21;
                (*(f32 *)((u8 *)(arg1) + (0x1A0))) = temp_f21;
                (*(s32 *)((u8 *)(arg1) + (0xE4))) = 0;
                (*(f32 *)((u8 *)(arg1) + (0x124))) = temp_f20_2;
                (*(s32 *)((u8 *)(arg1) + (0x164))) = 0;
                (*(f32 *)((u8 *)(arg1) + (0x1A4))) = temp_f20_2;
            } else {
                s32 c40;
                (*(s32 *)((u8 *)(arg1) + (0xE0))) = 0;
                (*(s32 *)((u8 *)(arg1) + (0x120))) = 0;
                (*(f32 *)((u8 *)(arg1) + (0x160))) = temp_f21;
                (*(f32 *)((u8 *)(arg1) + (0x1A0))) = temp_f21;
                c40 = 0x42200000;
                (*(s32 *)((u8 *)(arg1) + (0xE4))) = c40;
                temp_f0 = temp_f20_2 - *(f32 *)&c40;
                (*(f32 *)((u8 *)(arg1) + (0x124))) = temp_f0;
                (*(s32 *)((u8 *)(arg1) + (0x164))) = c40;
                (*(f32 *)((u8 *)(arg1) + (0x1A4))) = temp_f0;
            }
            (*(f32 *)((u8 *)(arg1) + (0xE8))) = D_008872F8[0];
            (*(f32 *)((u8 *)(arg1) + (0x128))) = D_008872F8[0];
            (*(f32 *)((u8 *)(arg1) + (0x168))) = D_008872F8[0];
            (*(f32 *)((u8 *)(arg1) + (0x1A8))) = D_008872F8[0];
            var_7 = var_6 = 0x10;
            temp_5_2 = (*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28;
            temp_4_2 = (*(s32 *)(D_00712C5C + temp_5_2)) + 1;
            temp_3_4 = (*(s32 *)(D_00712C60 + temp_5_2)) + 1;
loop_40:
            if (var_7 < temp_4_2) {
                var_7 *= 2;
                goto loop_40;
            }
loop_43:
            if (var_6 < temp_3_4) {
                var_6 *= 2;
                goto loop_43;
            }
            (*(s32 *)((u8 *)(arg1) + (0xF0))) = 0;
            (*(s32 *)((u8 *)(arg1) + (0x130))) = 0;
            temp_f0_2 = (f32) temp_4_2 / (f32) var_7;
            (*(f32 *)((u8 *)(arg1) + (0x170))) = temp_f0_2;
            (*(f32 *)((u8 *)(arg1) + (0x1B0))) = temp_f0_2;
            (*(s32 *)((u8 *)(arg1) + (0xF4))) = 0;
            temp_f0_3 = (f32) temp_3_4 / (f32) var_6;
            (*(f32 *)((u8 *)(arg1) + (0x134))) = temp_f0_3;
            (*(s32 *)((u8 *)(arg1) + (0x174))) = 0;
            (*(f32 *)((u8 *)(arg1) + (0x1B4))) = temp_f0_3;
            (*(f32 *)((u8 *)(arg1) + (0xF8))) = temp_f2;
            (*(f32 *)((u8 *)(arg1) + (0x138))) = temp_f2;
            (*(f32 *)((u8 *)(arg1) + (0x178))) = temp_f2;
            (*(f32 *)((u8 *)(arg1) + (0x1B8))) = temp_f2;
            return;
        }
        break;
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
        if (temp_5 != 3) {
            temp_3_5 = (*(s16 *)((u8 *)(arg1) + (0x1EA)));
            if (temp_3_5 != 0x11) {
                if ((temp_3_5 != 0x16) && (temp_3_5 != 0x15)) {
                    if (D_008C024E[0] & 0x800) {
                        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 6;
                    }
                } else if (D_008C024E[0] & 0x9FF) {
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 6;
                }
            }
        }
        func_0050a1c0((*(s32 *)((u8 *)(arg1) + (4))), sp60);
        if (sp60[0] != 0) {
            iGpffffbaf8 = sp60[9];
            if ((*(s16 *)((u8 *)(arg1) + (0x1E4))) == 4) {
                temp_3_6 = (*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28;
                if ((*(s32 *)(D_00712C6C + temp_3_6) != 0) && (sp60[9] >= (*(s16 *)(D_00712C70 + temp_3_6)))) {
                    (*(s32 *)((u8 *)(arg1) + (0x204))) = 0;
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 5;
                }
            }
            (*(s32 *)((u8 *)(arg1) + (0x210))) = sp60[3];
            (*(s32 *)((u8 *)(arg1) + (0x214))) = sp60[4];
            iGpffffbaf4 = sp60[5];
            iGpffffbaf0 = sp60[6];
            func_00419520((void *)func_00418f50(2), 0, 0);
            func_0043f810((void *)(*(u32 *)((u8 *)(arg1) + (0x200))), sp60[0], (*(s32 *)((u8 *)(arg1) + (0x210))) * (*(s32 *)((u8 *)(arg1) + (0x214))) * 4);
            iGpffffbae8 = (u32)((u32) (*(u32 *)((u8 *)(arg1) + (0x200))));
            var_6_2 = sp60;
            var_5 = (u8 *)(arg1 + 0x40);
            var_4 = 9;
            do {
                temp_3_7 = (*(s64 *)var_6_2);
                temp_2_2 = (*(s64 *)((u8 *)var_6_2 + 8));
                var_6_2 = (s32 *)((u8 *)var_6_2 + 0x10);
                var_4 -= 1;
                (*(s64 *)var_5) = temp_3_7;
                (*(s64 *)((u8 *)var_5 + 8)) = temp_2_2;
                var_5 += 0x10;
            } while (var_4 > 0);
            if ((*(s16 *)((u8 *)(arg1) + (0x1E4))) == 3) {
                if ((*(s16 *)(D_00712C74 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28))) == 0) {
                    var_7_2 = 0xFF;
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 4;
                } else {
                    temp_4_3 = (*(s32 *)((u8 *)(arg1) + (0x208))) + 1;
                    (*(s32 *)((u8 *)(arg1) + (0x208))) = temp_4_3;
                    temp_3_8 = (*(s16 *)((u8 *)(arg1) + (0x1EA)));
                    if (temp_4_3 == (*(s16 *)(D_00712C74 + (temp_3_8 * 0x28)))) {
                        switch (temp_3_8) {
                        case 4:
                        case 16:
                            func_001228a0(0, 0, 0);
                            break;
                        case 5:
                        case 6:
                        case 10:
                        case 11:
                        case 14:
                        case 15:
                        case 21:
                        case 22:
                            func_001228a0(0xFF, 0xFF, 0xFF);
                            break;
                        }
                        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 4;
                    }
                    var_7_2 = (((*(s32 *)((u8 *)(arg1) + (0x208))) * 0xFF) / (*(s16 *)(D_00712C74 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)))) & 0xFF;
                }
                var_6_3 = 0;
loop_85:
                if (var_6_3 < 4) {
                    temp_5_3 = (u8 *)(arg1 + (var_6_3 << 6));
                    (*(s32 *)((u8 *)(temp_5_3) + (0x100))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_5_3) + (0x104))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_5_3) + (0x108))) = 0x437F0000;
                    if (var_7_2 >= 0) {
                        var_f0 = (f32) var_7_2;
                    } else {
                        var_f0 = (f32)(u32)var_7_2;
                    }
                    (*(f32 *)((u8 *)(temp_5_3) + (0x10C))) = var_f0;
                    var_6_3 = (var_6_3 + 1);
                    goto loop_85;
                }
            }
            if ((*(s16 *)((u8 *)(arg1) + (0x1E4))) == 5) {
                temp_5_4 = (*(s32 *)((u8 *)(arg1) + (0x204))) + 1;
                (*(s32 *)((u8 *)(arg1) + (0x204))) = temp_5_4;
                temp_4_4 = (*(s16 *)(D_00712C72 + ((*(s16 *)((u8 *)(arg1) + (0x1EA))) * 0x28)));
                temp_6 = (0xFF - (((s32) (temp_5_4 * 0xFF) / temp_4_4) & 0xFF)) & 0xFF;
                if (temp_5_4 >= temp_4_4) {
                    (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 6;
                }
                var_7_3 = 0;
loop_94:
                if (var_7_3 < 4) {
                    temp_5_5 = (u8 *)(arg1 + (var_7_3 << 6));
                    (*(s32 *)((u8 *)(temp_5_5) + (0x100))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_5_5) + (0x104))) = 0x437F0000;
                    (*(s32 *)((u8 *)(temp_5_5) + (0x108))) = 0x437F0000;
                    if (temp_6 >= 0) {
                        var_f0_2 = (f32) temp_6;
                    } else {
                        var_f0_2 = (f32)(u32)temp_6;
                    }
                    (*(f32 *)((u8 *)(temp_5_5) + (0x10C))) = var_f0_2;
                    var_7_3 = (var_7_3 + 1);
                    goto loop_94;
                }
            }
        }
        func_0050aae0((*(s32 *)((u8 *)(arg1) + (4))));
        temp_2_3 = func_0050d4d0((*(s32 *)((u8 *)(arg1) + (4))));
        if ((u32) (temp_2_3 - 3) < 2U) {
            (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 6;
            return;
        }
        D_00887304[0](0xE, &spFC);
        tbl300a = (void (**)(s32, s32))(u32)D_00887300;
        tbl300a[0](0xE, 0);
        func_0040fcd0((*(s32 *)((u8 *)(arg1) + (0xD0))), 1);
        temp_5_6 = iGpffffbae8;
        if (temp_5_6 != 0) {
            func_00143ba0((*(s32 *)((u8 *)(arg1) + (0xD0))), temp_5_6, iGpffffbaf4, iGpffffbaf0);
            tbl300b = tbl300a;
            tbl300b[0](0x14, 1);
            (*(s32 *)((u8 *)(arg1) + (0x38))) = temp_2_3;
            tbl300b[0](6, 0);
            tbl300b[0](7, 2);
            tbl300b[0](8, 0);
            tbl300b[0](0xA, 5);
            tbl300b[0](0xB, 9);
            tbl300b[0](9, 1);
            tbl300b[0](0xC, 1);
            tbl300b[0](2, 3);
            tbl300b[0](1, (*(s32 *)((u8 *)(arg1) + (0xD0))));
            D_00887310[0](4, (void *)(arg1 + 0xE0), 4);
        }
        func_0040fcd0((*(s32 *)((u8 *)(arg1) + (0xD0))), 0);
        tbl300a[0](0xE, spFC);
        return;
    case 6:                                          /* switch 1 */
        if ((*(s32 *)((u8 *)(arg1) + (0x1F4))) != 0) {
            func_00452040(iGpffffb034);
            return;
        }
        temp_4_5 = (*(s32 *)((u8 *)(arg1) + (4)));
        if (temp_4_5 != 0) {
            if ((*(s32 *)((u8 *)(arg1) + (0xD8))) != 0) {
                func_0050ffc8(temp_4_5);
            }
            func_005097e8((*(s32 *)((u8 *)(arg1) + (4))));
            (*(s32 *)((u8 *)(arg1) + (4))) = 0;
        }
        temp_4_6 = (*(u32 *)((u8 *)(arg1) + (0x1E0)));
        if (temp_4_6 != 0) {
            jtbl_008873EC[0]((void *)temp_4_6);
            (*(u32 *)((u8 *)(arg1) + (0x1E0))) = 0U;
        }
        temp_4_7 = (*(u32 *)((u8 *)(arg1) + (0x200)));
        if (temp_4_7 != 0) {
            jtbl_008873EC[0]((void *)temp_4_7);
            (*(u32 *)((u8 *)(arg1) + (0x200))) = 0U;
            iGpffffbae8 = 0U;
        }
        temp_4_8 = (*(s32 *)((u8 *)(arg1) + (0xD0)));
        if (temp_4_8 != 0) {
            func_003ec330(temp_4_8);
            (*(s32 *)((u8 *)(arg1) + (0xD0))) = 0;
        }
        (*(s16 *)((u8 *)(arg1) + (0x1EE))) = 0;
        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0;
        return;
    case 7:                                         /* switch 1 */
        (*(s16 *)((u8 *)(arg1) + (0x1EE))) = 0x1E;
        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 8;
        /* fallthrough */
    case 8:                                         /* switch 1 */
        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 9;
        /* fallthrough */
    case 9:                                         /* switch 1 */
        (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0xA;
        /* fallthrough */
    case 10:                                        /* switch 1 */
        temp_3_9 = (*(s16 *)((u8 *)(arg1) + (0x1EE))) - 1;
        (*(s16 *)((u8 *)(arg1) + (0x1EE))) = temp_3_9;
        if (temp_3_9 == 0) {
            if ((*(s32 *)((u8 *)(arg1) + (0x1F4))) != 0) {
                func_00452040(iGpffffb034);
                return;
            }
            temp_4_9 = (*(s32 *)((u8 *)(arg1) + (4)));
            if (temp_4_9 != 0) {
                if ((*(s32 *)((u8 *)(arg1) + (0xD8))) != 0) {
                    func_0050ffc8(temp_4_9);
                }
                func_005097e8((*(s32 *)((u8 *)(arg1) + (4))));
                (*(s32 *)((u8 *)(arg1) + (4))) = 0;
            }
            temp_4_10 = (*(u32 *)((u8 *)(arg1) + (0x1E0)));
            if (temp_4_10 != 0) {
                jtbl_008873EC[0]((void *)temp_4_10);
                (*(u32 *)((u8 *)(arg1) + (0x1E0))) = 0U;
            }
            temp_4_11 = (*(u32 *)((u8 *)(arg1) + (0x200)));
            if (temp_4_11 != 0) {
                jtbl_008873EC[0]((void *)temp_4_11);
                (*(u32 *)((u8 *)(arg1) + (0x200))) = 0U;
                iGpffffbae8 = 0U;
            }
            temp_4_12 = (*(s32 *)((u8 *)(arg1) + (0xD0)));
            if (temp_4_12 != 0) {
                func_003ec330(temp_4_12);
                (*(s32 *)((u8 *)(arg1) + (0xD0))) = 0;
            }
            (*(s16 *)((u8 *)(arg1) + (0x1EE))) = 0;
            (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0;
            return;
        }
        break;
    case 11:                                        /* switch 1 */
        spF0 = 0x40000000;
        spF4 = 0x41200000;
        func_00450050((s64) spF0, D_00713050);
        spF0 = 0x40000000;
        spF4 = 0x41300000;
        func_00450050((s64) spF0, D_00713068);
        if (D_008C024E[0] & 0x800) {
            if ((*(s32 *)((u8 *)(arg1) + (0x1F4))) != 0) {
                func_00452040(iGpffffb034);
                return;
            }
            temp_4_13 = (*(s32 *)((u8 *)(arg1) + (4)));
            if (temp_4_13 != 0) {
                if ((*(s32 *)((u8 *)(arg1) + (0xD8))) != 0) {
                    func_0050ffc8(temp_4_13);
                }
                func_005097e8((*(s32 *)((u8 *)(arg1) + (4))));
                (*(s32 *)((u8 *)(arg1) + (4))) = 0;
            }
            temp_4_14 = (*(u32 *)((u8 *)(arg1) + (0x1E0)));
            if (temp_4_14 != 0) {
                jtbl_008873EC[0]((void *)temp_4_14);
                (*(u32 *)((u8 *)(arg1) + (0x1E0))) = 0U;
            }
            temp_4_15 = (*(u32 *)((u8 *)(arg1) + (0x200)));
            if (temp_4_15 != 0) {
                jtbl_008873EC[0]((void *)temp_4_15);
                (*(u32 *)((u8 *)(arg1) + (0x200))) = 0U;
                iGpffffbae8 = 0U;
            }
            temp_4_16 = (*(s32 *)((u8 *)(arg1) + (0xD0)));
            if (temp_4_16 != 0) {
                func_003ec330(temp_4_16);
                (*(s32 *)((u8 *)(arg1) + (0xD0))) = 0;
            }
            (*(s16 *)((u8 *)(arg1) + (0x1EE))) = 0;
            (*(s16 *)((u8 *)(arg1) + (0x1E4))) = 0;
        }
        break;
    }
}
#pragma opt_loop_invariants reset
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468ff0);
#endif
// FUN_0046A020
void func_0046a020(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) != 0) {
        if (*(s32 *)(work + 0xD8) != 0) {
            func_0050ffc8(*(s32 *)(work + 4));
        }
        func_005097e8(*(s32 *)(work + 4));
        *(s32 *)(work + 4) = 0;
    }
    if (*(s32 *)(work + 0x1E0) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(work + 0x1E0));
        *(s32 *)(work + 0x1E0) = 0;
    }
    if (*(s32 *)(work + 0x200) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(work + 0x200));
        *(s32 *)(work + 0x200) = 0;
        iGpffffbae8 = 0;
    }
    if (*(s32 *)(work + 0xD0) != 0) {
        func_003ec330(*(s32 *)(work + 0xD0));
        *(s32 *)(work + 0xD0) = 0;
    }
    if (*(s32 *)(work + 0x1F4) == 0) {
        iGpffffbaec = 0;
    }
    if (*(s32 *)(work + 0x1FC) != 0) {
        *(s32 *)(work + 0x1FC) = 0;
        func_003d5fb0(D_0070B610);
    }
    func_0046a340((u32)work);
}
// FUN_0046A110
s32 func_0046a110(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = func_0046a6f0(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = func_00451fc0(arg0, (const void *)iGpffffb034, 0xC6, 0, 0,
                           (void (*)(u8 *))func_00468fa0,
                           (void (*)(u8 *))func_0046a020, work);
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A1E0
s32 func_0046a1e0(void)
{
    return iGpffffb034;
}

// FUN_0046A1F0
s32 func_0046a1f0(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = func_0046a6f0(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = func_00451fc0(arg0, (const void *)iGpffffb034, 0xC6, 0, 0,
                           (void (*)(u8 *))func_00468fa0,
                           (void (*)(u8 *))func_0046a020, work);
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x1FC) = 0;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A2C0
s32 func_0046a2c0(void)
{
    return iGpffffbaf8;
}

// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}



// FUN_0046A2E0
void func_0046a2e0(u8 *arg0, s32 arg1) {
    u32 i;

    D_00724C04 = arg0;
    D_00724C00 = arg0 + arg1;
    D_00724BFC = 0x1F4;
    i = 0;
    while (i < D_00724BFC) {
        *(s32 *)(arg0 + i * 8) = 0;
        *(s32 *)(arg0 + i * 8 + 4) = 0;
        i++;
    }
    D_00724BF8 = 0;
    D_00724BF4 = 0;
}

// FUN_0046A340
void func_0046a340(u32 arg0) {
    s32 temp_2;
    u32 var_4;
    u32 var_7;
    u8 *temp_5;
    u8 *entry;

    if (arg0 < iGpffffbb14) {
        (*jtbl_008873EC)((void *)arg0);
        return;
    }
    if (iGpffffbb10 < arg0) {
        (*jtbl_008873EC)((void *)arg0);
        return;
    }
    temp_2 = func_0042ba20();
    temp_5 = (u8 *)iGpffffbb14;
    var_7 = 0;
    var_4 = iGpffffbb0c;
    goto loop_test;
loop_body:
    entry = temp_5 + (var_7 * 8);
    if (arg0 == *(s32 *)(entry + 0)) {
        var_4 = iGpffffbb04;
        iGpffffbb04 = var_4 - *(s32 *)(entry + 4);
        *(s32 *)(entry + 0) = 0;
        *(s32 *)(entry + 4) = 0;
        goto loop_done;
    }
    var_7 += 1;
loop_test:
    if (var_7 < var_4) {
        goto loop_body;
    }
loop_done:
    if (temp_2 != 0) {
        func_0042ba70(var_4);
    }
}
extern void func_00451b70(void);
extern char *func_004526e0(void);
extern void func_0046d700(const char *file, s32 line, const char *msg, ...);
extern char D_00713078[], D_00713088[], D_007130A0[];
extern char D_00756758[], D_00756748[], D_00756730[], D_00756720[];
/* Inline overlap search preserves retail's early-return branches.
   The metadata table and count are reloaded on each retry. */
static inline u32 sdkMallocFindOverlap(u32 candidate, u32 size)
{
    u32 i;
    u32 base;
    u32 length;
    u32 finish;
    u32 end;
    u32 count;
    u8 *table;
    u8 *entry;
    table = (u8 *)iGpffffbb14;
    end = candidate + size;
    i = 0;
    count = iGpffffbb0c;
    for (; i < count; i++) {
        entry = table + i * 8;
        length = *(u32 *)(entry + 4);
        if (length != 0) {
            base = *(u32 *)entry;
            finish = base + length;
            if (candidate == base) {
                return finish;
            } else if (base < candidate) {
                if (candidate < finish) {
                    return finish;
                }
            } else if (finish < end) {
                return finish;
            } else if (base < end) {
                return finish;
            }
        }
    }
    return candidate;
}

/* Measured: 692/704 bytes, 53 resolved relocations and twelve zero
   alignment bytes. Diagnostic arguments reload after the task-name call. */
// FUN_0046A430
u8 *func_0046a430(s32 arg0)
{
    s32 lock;
    u32 candidate;
    u32 size;
    u32 finish;
    u32 i;
    u8 *entry;
    u32 *entry_length;
    char *task_name;

    lock = func_0042ba20();
    size = ((u32)arg0 + 0xF) & ~0xF;
    candidate = iGpffffbb14 + iGpffffbb0c * 8;
retry:
    finish = sdkMallocFindOverlap(candidate, size);
    if (finish == candidate) {
        i = 0;
        while (i < iGpffffbb0c) {
            entry = (u8 *)iGpffffbb14 + i * 8;
            entry_length = (u32 *)(entry + 4);
            if (*entry_length == 0) {
                *(u32 *)entry = finish;
                *entry_length = size;
                iGpffffbb04 += size;
                goto allocated;
            }
            i++;
        }
        func_00440b68(D_00756758);
        task_name = func_004526e0();
        func_0046d700((const char *)D_00756748, 0xB2,
                      (const char *)D_00756730, iGpffffbb04, size,
                      task_name, D_00724BEC, D_00724BF0);
        func_0046d730(D_00756720, 0xB3);
allocated:
        if (lock != 0) {
            func_0042ba70();
        }
        if (finish + size >= iGpffffbb10) {
            func_00440b68(D_00713078);
            task_name = func_004526e0();
            func_0046d700((const char *)D_00713088, 0xEC,
                          (const char *)D_007130A0, iGpffffbb04, size,
                          task_name, D_00724BEC, D_00724BF0);
        }
        return (u8 *)finish;
    }
    candidate = finish;
    if (candidate + size >= iGpffffbb10) {
        func_00451b70();
        func_00440b68(D_00713078);
        task_name = func_004526e0();
        func_0046d700((const char *)D_00713088, 0xFA,
                      (const char *)D_007130A0, iGpffffbb04, size,
                      task_name, D_00724BEC, D_00724BF0);
        func_0046d730(D_00713088, 0xFB);
    }
    goto retry;
}
// FUN_0046A770
/* The list walk is written with an explicit goto loop: retail tests the
   cursor at the TOP of the loop and both early exits are out of line, which
   the natural `while (p != NULL)` form does not reproduce (nd 57). */
u8 *func_0046a770(char *arg0) {
    u8 *p;

    p = D_00724C08;
loop:
    if (p == NULL) {
        return NULL;
    }
    if (func_004426e8((char *)(p + 2), arg0) == 0) {
        return p;
    }
    p = *(u8 **)(p + 0x238);
    goto loop;
}

/* measured: 19 differing words at an exact 211/211, from a full rewrite.
   The previous note recorded nd 71 for a body that no longer exists in the
   tree; this is re-derived from the disassembly and every number below is
   reproducible with `tools/measure_guarded.py --save-candidate` plus
   `tools/fnalign.py --candidate` on the body beneath.
   Levers that paid, in order of size: `opt_loop_invariants on` 56 -> 25
   differing words (retail hoists 360.0f, -180.0f, 180.0f and the constant 1
   out of the angle-wrap loop; b210 rematerialises them per iteration unless
   told); declaring the two f32[4][3] frame slots src-before-dst so src lands
   at sp+0x80 and dst at sp+0x50; materialising the wrap test as
   `over = !(ang <= 180.0f)` into an s32 rather than branching on it directly,
   which is what produces retail's move/bc1/xori triple; and copying the
   middle 4x3 block with a three-field struct assignment rather than three
   scalar temps, worth 25 -> 19 (temps in either declaration order, reversed
   store order, and function-scope temps all mis-order the three lwc1s).
   WALL 1, 2 words: retail materialises the *negation* of `ang <= 180.0f`
   with `bc1f` and then recovers the positive sense with `xori` for the
   branch; b210 materialises the positive sense with `bc1t` and folds the
   negation into `beqz`. Same instruction count, opposite polarity. Measured
   and rejected: `(ang <= 180.0f) ? 0 : 1` (19, unchanged), `!(180.0f >= ang)`
   (23), `over != 0` / `over == 1` (23), `(ang <= 180.0f) == 0` (161),
   `!!(...)` with `if (!over)` (163), `ang > 180.0f` (163), the nested
   if/else form (169), an explicit `over = 1; if (ang <= 180.0f) over = 0;`
   (162), and a u8 `over` (161).
   WALL 2, 17 words: retail computes the y table term
   `(f32)*(s32 *)(*(s32 *)(*arg0 + 0x204) + (idx << 7) + 0x48)` *last* in the
   final loop, into $f0, while computing the x term first into $f2 - the
   same expression shape scheduled two different ways in one loop body.
   b210 hoists both to the top. The destination register is the cause: $f2
   has to stay live across the y arithmetic, so the scheduler pulls it
   forward. Measured and rejected: the y sum in an intermediate variable,
   the x term in an intermediate variable, table-term-first, explicit
   parentheses around the sum, a u8* pointer temp for the table base, and
   all of `opt_common_subs off` (205), `opt_propagation off` (130),
   `schedule on` (196), `opt_strength_reduction off` (19, neutral),
   `opt_dead_assignments off` (122) and `peephole off` (124) layered on the
   loop-invariants base.
   Seven gp coefficient slots (fGpffff81b4..fGpffff81cc, the sin/cos Horner
   table contiguous with the known fGpffff81b0 at 0x007612a0) are new in
   config/symbol_data_addrs.txt. */
/* 2026-09-18 lead pass, 8 measured variants, floor confirmed at 19 words.
   Two residual classes at 211/211 instructions.  (a) Branch polarity at
   offsets 43 and 47: retail has `bc1f`/`bnez` where this body emits
   `bc1t`/`beqz`.  (b) The `o[0]`/`o[1]` sums: retail evaluates strictly left
   to right, adding the first two terms and only then loading the table term,
   while this body hoists that load ahead of the first add.
   Neither is reachable from source.  `!(ang <= 180.0f)` is load-bearing -
   rewriting it as `(ang > 180.0f)` costs 19 -> 163, and moving the negation
   onto the `if` costs the same.  Splitting the sums into `o[i] = a + b;
   o[i] += c;` to force the load after the first add costs 19 -> 55, and
   combining both changes costs 162.  `while (wrapped)` and an explicit
   `!(ang >= -180.0f)` tie at 19; `while (wrapped == 1)` costs one word.
   The body is at a local optimum in every direction tried. */
/* 2026-09-18 probe; floor stands at 19.  Two of the differing words are
   branch polarity - retail `bc1f`/`bnez` where this body emits `bc1t`/`beqz`
   - and the rest is a seven-instruction attachment-table block this body
   issues before the `add.s` that retail issues after.  The polarity is not
   reachable by inverting the source test: `over = ang > 180.0f` instead of
   `!(ang <= 180.0f)` costs 163, swapping the arms of the if/else costs 28,
   and spelling the second test `!(ang >= -180.0f)` costs 161.  This is the
   same measurement recorded in handoff 7l, on the same function, and it is
   worth repeating: the comparison spelling that scores is the one already
   here. */
// FUN_0046A7F0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0046a7f0(u8 *arg0, u8 *arg1)
{
    f32 src[4][3];
    f32 dst[4][3];
    s32 i;
    s32 j;
    s32 k;
    f32 ang;
    f32 x;
    f32 x2;
    f32 r;
    f32 q;
    f32 h;
    f32 cosv;
    f32 sinv;
    s32 wrapped;
    void *mat;
    void *rot;

    for (i = 0; i < 4; i++) {
        f32 *s = (f32 *)(arg1 + i * 8);
        f32 *d = src[i];

        d[0] = s[0];
        d[1] = s[1];
    }
    ang = *(f32 *)(arg0 + 0x18);
    if (ang != 0.0f) {
        do {
            s32 over;

            wrapped = 0;
            over = !(ang <= 180.0f);
            if (over) {
                ang -= 360.0f;
                wrapped = 1;
            } else if (ang < -180.0f) {
                ang += 360.0f;
                wrapped = 1;
            }
        } while (wrapped != 0);
        x = (fGpffff8084 * ang) / 180.0f;
        x2 = x * x;
        mat = func_003e0f80();
        r = fGpffff81b0 * x2 + fGpffff81b4;
        r = x2 * r + fGpffff81b8;
        r = x2 * r + fGpffff81bc;
        r = x2 * r + fGpffff81c0;
        r = x2 * r + fGpffff81c4;
        q = x2 * r;
        h = 0.5f * x2 - x2 * q;
        cosv = 1.0f - (1.0f - h);
        r = fGpffff81c8 * x2 + fGpffff8054;
        r = x2 * r + fGpffff8058;
        r = x2 * r + fGpffff805c;
        r = x2 * r + fGpffff8060;
        r = x2 * r + fGpffff81cc;
        sinv = x + (x2 * x) * r;
        rot = func_003e0680(mat, D_007130B8, 0, cosv, sinv);
        func_003e42e0(dst, src, 4, rot);
        func_003e0f40(rot);
        for (k = 0; k < 4; k++) {
            f32 *s = dst[k];
            f32 *d = src[k];
            struct V3 { f32 x; f32 y; f32 z; };

            *(struct V3 *)d = *(struct V3 *)s;
        }
    }
    for (j = 0; j < 4; j++) {
        f32 *p = src[j];
        f32 *o = (f32 *)(arg1 + j * 8);

        o[0] = *(f32 *)(arg0 + 8) + ((f32)*(s16 *)(arg0 + 0x1C) + p[0]) +
               (f32)*(s32 *)(*(s32 *)(*(u8 **)arg0 + 0x204) + (*(s32 *)(arg0 + 4) << 7) + 0x44);
        o[1] = *(f32 *)(arg0 + 0xC) + ((f32)*(s16 *)(arg0 + 0x1E) + p[1]) +
               (f32)*(s32 *)(*(s32 *)(*(u8 **)arg0 + 0x204) + (*(s32 *)(arg0 + 4) << 7) + 0x48);
    }
}

#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a7f0);
#endif
// FUN_0046AB40
void func_0046ab40(void)
{
    u8 *var_16 = D_00724C08;
loop_1:
    if (var_16 != NULL) {
        func_0046ab90(var_16);
        var_16 = *(u8 **)(var_16 + 0x238);
        goto loop_1;
    }
}



// FUN_0046D6B0
void func_0046d6b0(s32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}

// FUN_0046D700
void func_0046d700(const char *file, s32 line, const char *msg, ...)
{
}
// FUN_0046D730
void func_0046d730(void *arg0, s32 arg1) {}
// FUN_0046D740
void func_0046d740(const void *msg, const void *file, u32 line) {}
/* measured: func_0046d750 reconstruction from retail asm + P4_UNIT_0046D750 draft (495 lines, m2c noise 0).
 * Jal audit: func_00457120 takes 0 args (no $a0-$a3 written before jal, returns pointer for 0x80 float);
 * func_003e8120/func_003e8110 take 1 arg ($a0 = 457120 result); func_003f6440 takes 2 ($a0,$a1);
 * D_00887300 takes 2 ($a0,$a1, cached in $s1), D_00887310 takes 3 ($a0,$a1,$a2 = 4,ptr,4, cached in $s1);
 * func_0046ea60 takes 2 (arg0 original $a0 + work+0xC $a1) -- draft 1-arg form is invented, fixed here.
 * Frame is 0x30 with $s0=work, $s1=table base, no stack locals (all state in work struct).
 * Variants hand-reasoned from alignment edits, all with #pragma opt_propagation off (measured below):
 * v1 honest for-loops, cached tables: nd 3061 obj 4252/4256 (frame 0x20, no $s1, float $f1/$f2 swapped, counters $v vs $a).
 * +pragma off: nd 629 obj 4236/4256 (frame 0x30 + $s1 restored, tail tables match).
 * decl f2-before-f1: nd 618 (float sub/div $f2/$f1 fixed).
 * case-7 duplicate bnez via (b23==0 && b23==0): nd 325 obj 4244/4256 (tail + epilogue byte-exact from 0x46e678).
 * case-7 group pointer g=work+(i<<8), e=g+(j<<6): nd 318 obj 4244/4256 hwasm (best, ported below).
 * Residual is pure integer register coloring: outer $v1 vs $a3, g $a3 vs $a1, e $a2 vs $a0, byte $a0 vs $v0,
 * or-dest $a1 vs $v1; decl-order sweeps (3 tries) all stay nd 318, tail from 0x46e678 onward is byte-exact.
 * Saved-register coloring + call-argument setup order floor (cf. docs/matching.md known floors); banked as guarded body.
 * Removing #pragma opt_propagation off measures nd 318 -> nd 3061 (frame 0x30->0x20, tables reload each call).
 * Ported to this owner with function-local externs (D_00887310 s32-return, 8120/8110, ea60); file-scope here
 * already has D_00887300/003f6440/457120. probe_variants.py in this tree: base without pragma context 1030,
 * with pragma 248 differing words; store-via-g without e temp (noe) 248, e/g decl swap (egdecl) 248, byte-temps
 * before e (bytesfirst) 285 (worse). fnalign.py base: retail 1061 instrs, object 1061 instrs, all edits are
 * register-only replaces ($a3/$a2/$a1/$a0 vs $v1/$v0/$a3/$a2, $v0/$v1 vs $a0/$a1); same count confirms coloring floor. */
#pragma opt_propagation off
// FUN_0046D750 NONMATCHING
#ifdef NON_MATCHING
s32 func_0046d750(u8 *arg0) {
    extern s32 func_003e8120(s32 arg0);
    extern void func_003e8110(s32 arg0);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void func_0046ea60(u8 *arg0, u8 *arg1);
    f32 f2;
    f32 f1;
    s32 i;
    s32 j;
    s32 k;
    u8 *work;
    u8 *g;
    u8 *e;
    s32 state;
    void (**tbl00)(s32, s32);
    s32 (**tbl10)(s32, void *, s32);

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        f2 = *(f32 *)((u8 *)func_00457120() + 0x80) - 400.0f;
        f1 = 1.0f / f2;
        i = 0;
        goto test0o;
body0o:
        g = work + (i << 8);
        *(s32 *)(g + 0x60) = 0;
        *(s32 *)(g + 0x64) = 0;
        *(f32 *)(g + 0x68) = f2;
        *(s32 *)(g + 0xA0) = 0;
        *(s32 *)(g + 0xA4) = 0;
        *(f32 *)(g + 0xA8) = f2;
        *(s32 *)(g + 0xE0) = 0;
        *(s32 *)(g + 0xE4) = 0;
        *(f32 *)(g + 0xE8) = f2;
        *(s32 *)(g + 0x120) = 0;
        *(s32 *)(g + 0x124) = 0;
        *(f32 *)(g + 0x128) = f2;
        *(f32 *)(g + 0x78) = f1;
        *(f32 *)(g + 0xB8) = f1;
        *(f32 *)(g + 0xF8) = f1;
        *(f32 *)(g + 0x138) = f1;
        j = 0;
        goto test0i;
body0i:
        e = g + (j << 6);
        *(f32 *)(e + 0x80) = (f32)*(u8 *)(work + 0x1C);
        *(f32 *)(e + 0x84) = (f32)*(u8 *)(work + 0x1D);
        *(f32 *)(e + 0x88) = (f32)*(u8 *)(work + 0x1E);
        *(f32 *)(e + 0x8C) = (f32)*(u8 *)(work + 0x1F);
        j++;
test0i:
        if (j < 4) {
            goto body0i;
        }
        i++;
test0o:
        if (i < 4) {
            goto body0o;
        }
        *(f32 *)(work + 0x460) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x464) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x468) = f2;
        *(f32 *)(work + 0x4A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x4A4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x4A8) = f2;
        *(f32 *)(work + 0x4E0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x4E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x4E8) = f2;
        *(f32 *)(work + 0x520) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x524) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x528) = f2;
        *(f32 *)(work + 0x478) = f1;
        *(f32 *)(work + 0x4B8) = f1;
        *(f32 *)(work + 0x4F8) = f1;
        *(f32 *)(work + 0x538) = f1;
        k = 0;
        goto test0k;
body0k:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(s32 *)(e + 0x48C) = 0;
        k++;
test0k:
        if (k < 4) {
            goto body0k;
        }
        *(f32 *)(work + 0x40) = (f32)*(u8 *)(work + 0x23);
        *(u8 *)(work + 0x23) = 0;
        *(s32 *)work = *(s32 *)work + 1;
        *(u8 *)(work + 0x23) = (u8)(*(f32 *)(work + 0x40));
        k = 0;
        goto test0k2;
body0k2:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        k++;
test0k2:
        if (k < 4) {
            goto body0k2;
        }
        *(s32 *)work = 6;
        break;
    case 1:
        if (!(*(f32 *)(work + 0x30) < (f32)*(s32 *)(work + 0x14))) {
            *(f32 *)(work + 0x30) = (f32)*(s32 *)(work + 0x14);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x60) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x64) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0xA0) = (f32)*(s32 *)(work + 0xC) + *(f32 *)(work + 0x30);
        *(f32 *)(work + 0xA4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0xE0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0xE4) = (f32)(*(s32 *)(work + 0x10) + 2);
        *(f32 *)(work + 0x120) = (f32)*(s32 *)(work + 0xC) + *(f32 *)(work + 0x30);
        *(f32 *)(work + 0x124) = (f32)(*(s32 *)(work + 0x10) + 2);
        *(f32 *)(work + 0x30) = *(f32 *)(work + 0x30) + (f32)*(s32 *)(work + 0x14) / 2.0f;
        break;
    case 2:
        if (!(*(f32 *)(work + 0x34) < (f32)*(s32 *)(work + 0x18))) {
            *(f32 *)(work + 0x34) = (f32)*(s32 *)(work + 0x18);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x160) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14) - 2);
        *(f32 *)(work + 0x164) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x1A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x1A4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x1E0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14) - 2);
        *(f32 *)(work + 0x1E4) = (f32)*(s32 *)(work + 0x10) + *(f32 *)(work + 0x34);
        *(f32 *)(work + 0x220) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x224) = (f32)*(s32 *)(work + 0x10) + *(f32 *)(work + 0x34);
        *(f32 *)(work + 0x34) = *(f32 *)(work + 0x34) + (f32)*(s32 *)(work + 0x18) / 2.0f;
        break;
    case 3:
        if (!(*(f32 *)(work + 0x38) < (f32)*(s32 *)(work + 0x14))) {
            *(f32 *)(work + 0x38) = (f32)*(s32 *)(work + 0x14);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x260) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14)) - *(f32 *)(work + 0x38);
        *(f32 *)(work + 0x264) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18) - 2);
        *(f32 *)(work + 0x2A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x2A4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18) - 2);
        *(f32 *)(work + 0x2E0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14)) - *(f32 *)(work + 0x38);
        *(f32 *)(work + 0x2E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x320) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x324) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x38) = *(f32 *)(work + 0x38) + (f32)*(s32 *)(work + 0x14) / 2.0f;
        break;
    case 4:
        if (!(*(f32 *)(work + 0x3C) < (f32)*(s32 *)(work + 0x18))) {
            *(f32 *)(work + 0x3C) = (f32)*(s32 *)(work + 0x18);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x360) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x364) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18)) - *(f32 *)(work + 0x3C);
        *(f32 *)(work + 0x3A0) = (f32)(*(s32 *)(work + 0xC) + 2);
        *(f32 *)(work + 0x3A4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18)) - *(f32 *)(work + 0x3C);
        *(f32 *)(work + 0x3E0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x3E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x420) = (f32)(*(s32 *)(work + 0xC) + 2);
        *(f32 *)(work + 0x424) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x3C) = *(f32 *)(work + 0x3C) + (f32)*(s32 *)(work + 0x18) / 2.0f;
        break;
    case 5: {
        u8 c;
        c = (u8)(*(f32 *)(work + 0x40));
        if (*(u8 *)(work + 0x23) < c) {
            f32 fb;
            f32 f;
            fb = (f32)*(u8 *)(work + 0x23);
            f = fb + *(f32 *)(work + 0x40) / 8.0f;
            *(u8 *)(work + 0x23) = (u8)f;
        } else {
            *(u8 *)(work + 0x23) = (u8)(*(f32 *)(work + 0x40));
            *(s32 *)work = *(s32 *)work + 1;
        }
        k = 0;
        goto test5k;
body5k:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        k++;
test5k:
        if (k < 4) {
            goto body5k;
        }
        break;
    }
    case 6:
        func_0046ea60(arg0, work + 0xC);
        break;
    case 7:
        if (*(u8 *)(work + 0x23) > 0) {
            *(u8 *)(work + 0x23) = *(u8 *)(work + 0x23) - 1;
        }
        if (*(u8 *)(work + 0x1F) > 0) {
            *(u8 *)(work + 0x1F) = *(u8 *)(work + 0x1F) - 1;
        }
        i = 0;
        goto test7o;
body7o:
        g = work + (i << 8);
        j = 0;
        goto test7i;
body7i:
        e = g + (j << 6);
        *(f32 *)(e + 0x80) = (f32)*(u8 *)(work + 0x1C);
        *(f32 *)(e + 0x84) = (f32)*(u8 *)(work + 0x1D);
        *(f32 *)(e + 0x88) = (f32)*(u8 *)(work + 0x1E);
        *(f32 *)(e + 0x8C) = (f32)*(u8 *)(work + 0x1F);
        j++;
test7i:
        if (j < 4) {
            goto body7i;
        }
        i++;
test7o:
        if (i < 4) {
            goto body7o;
        }
        k = 0;
        goto test7k;
body7k:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        k++;
test7k:
        if (k < 4) {
            goto body7k;
        }
        if (*(u8 *)(work + 0x23) == 0 && *(u8 *)(work + 0x23) == 0) {
            *(s32 *)work = *(s32 *)work + 1;
        }
        break;
    case 8:
        return -1;
    }
    if (*(s32 *)(work + 4) == 1) {
        if (func_003e8120(func_00457120()) != 0) {
            tbl00 = D_00887300;
            tbl00[0](6, 1);
            tbl00[0](8, 0);
            tbl00[0](7, 2);
            tbl00[0](0xC, 1);
            tbl00[0](1, 0);
            func_003f6440(2, 0x44);
            func_003f6440(3, 0x717FB);
            tbl10 = D_00887310;
            tbl10[0](4, work + 0x460, 4);
            tbl10[0](4, work + 0x60, 4);
            tbl10[0](4, work + 0x160, 4);
            tbl10[0](4, work + 0x260, 4);
            tbl10[0](4, work + 0x360, 4);
        }
        func_003e8110(func_00457120());
    }
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d750);
#endif
/* measured: closes opt_propagation around func_0046d750. */
#pragma opt_propagation on
// FUN_0046E7F0
/* Keep the table address cached without changing the free callback type. */
#pragma push
#pragma opt_propagation off
void func_0046e7f0(u8 *arg0)
{
    void (**tbl)(void *) = jtbl_008873EC;
    u8 *work = *(u8 **)(arg0 + 0x38);

    tbl[0](*(u8 **)(work + 0x48));
    tbl[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop
/* Pointer-valued task name restores retail argument setup.
 * MWCCPS2 b210 -O2: 444 executable bytes / 448-byte retail window.
 * The buffer calculation uses rectangle x/y, not width/height. */
#pragma push
#pragma opt_propagation off
extern s32 func_0046d750(u8 *);
extern void func_0044ea90(void *, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_007130F8[], D_00713108[];
// FUN_0046E850
u8 *func_0046e850(u8 *parent, void *rect_arg, void *first_arg, void *second_arg)
{
    typedef struct WindowRect { s32 x, y, width, height; } WindowRect;
    typedef struct WindowColor { u8 r, g, b, a; } WindowColor;
    typedef struct WindowWork {
        s32 state, enabled;
        u8 reserved08[4];
        WindowRect rect;
        WindowColor first, second;
        u8 reserved24[32];
        size_t buffer_size;
        u8 *buffer, *cursor;
    } WindowWork;
    WindowRect *rect = (WindowRect *)rect_arg;
    WindowColor *first = (WindowColor *)first_arg;
    WindowColor *second = (WindowColor *)second_arg;
    s32 result;
    WindowWork *work;
    u8 *buffer;
    size_t *size;
    void *(**allocator)(size_t, size_t, u32);

    func_0044ea90(D_007130F8, 379);
    allocator = D_008873F4;
    work = (WindowWork *)allocator[0](1, 0x560, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    result = func_00451fc0((s32)parent, D_00713108, 0x101, 0, 0,
        (void (*)(u8 *))func_0046d750, func_0046e7f0, (u8 *)work);
    work->enabled = 1;
    work->rect = *rect;
    work->first = *first;
    work->second = *second;
    size = &work->buffer_size;
    *size = (rect->x / 8) * (rect->y / 8) + 32;
    func_0044ea90(D_007130F8, 396);
    buffer = allocator[0](1, *size, 0x40000);
    work->buffer = buffer;
    work->cursor = buffer;
    return (u8 *)result;
}
#pragma pop
// FUN_0046EA10
s32 func_0046ea10(u8 *arg0)
{
    s32 value = *(s32 *)(*(u8 **)(arg0 + 0x38));

    if ((value == 6) || (value == 8)) {
        return 0;
    }
    return 1;
}
// FUN_0046EA50
void func_0046ea50(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0046EA60
void func_0046ea60(u8 *arg0, u8 *arg1)
{
    struct FInput {
        f32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    };
    union Input {
        struct {
            s32 sp0;
            s32 sp4;
            s32 sp8;
            s32 spC;
        } i;
        struct FInput f;
    } input;
#define sp0 input.i.sp0
#define sp4 input.i.sp4
#define sp8 input.i.sp8
#define spC input.i.spC
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_4;
    s32 temp_5;
    u8 *temp_3;

    input = *(union Input *)arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_3 + 0) == 6) {
        *(struct FInput *)(temp_3 + 0xC) = input.f;
        temp_f4 = (f32)sp0;
        *(f32 *)(temp_3 + 0x60) = temp_f4;
        temp_f3 = (f32)sp4;
        *(f32 *)(temp_3 + 0x64) = temp_f3;
        temp_5 = sp0 + sp8;
        temp_f2 = (f32)temp_5;
        *(f32 *)(temp_3 + 0xA0) = temp_f2;
        *(f32 *)(temp_3 + 0xA4) = temp_f3;
        *(f32 *)(temp_3 + 0xE0) = temp_f4;
        temp_f0 = (f32)(sp4 + 2);
        *(f32 *)(temp_3 + 0xE4) = temp_f0;
        *(f32 *)(temp_3 + 0x120) = temp_f2;
        *(f32 *)(temp_3 + 0x124) = temp_f0;
        temp_f0_2 = (f32)(temp_5 - 2);
        *(f32 *)(temp_3 + 0x160) = temp_f0_2;
        *(f32 *)(temp_3 + 0x164) = temp_f3;
        *(f32 *)(temp_3 + 0x1A0) = temp_f2;
        *(f32 *)(temp_3 + 0x1A4) = temp_f3;
        *(f32 *)(temp_3 + 0x1E0) = temp_f0_2;
        temp_4 = sp4 + spC;
        temp_f1 = (f32)temp_4;
        *(f32 *)(temp_3 + 0x1E4) = temp_f1;
        *(f32 *)(temp_3 + 0x220) = temp_f2;
        *(f32 *)(temp_3 + 0x224) = temp_f1;
        *(f32 *)(temp_3 + 0x260) = temp_f4;
        temp_f0_3 = (f32)(temp_4 - 2);
        *(f32 *)(temp_3 + 0x264) = temp_f0_3;
        *(f32 *)(temp_3 + 0x2A0) = temp_f2;
        *(f32 *)(temp_3 + 0x2A4) = temp_f0_3;
        *(f32 *)(temp_3 + 0x2E0) = temp_f4;
        *(f32 *)(temp_3 + 0x2E4) = temp_f1;
        *(f32 *)(temp_3 + 0x320) = temp_f2;
        *(f32 *)(temp_3 + 0x324) = temp_f1;
        *(f32 *)(temp_3 + 0x360) = temp_f4;
        *(f32 *)(temp_3 + 0x364) = temp_f3;
        temp_f0_4 = (f32)(sp0 + 2);
        *(f32 *)(temp_3 + 0x3A0) = temp_f0_4;
        *(f32 *)(temp_3 + 0x3A4) = temp_f3;
        *(f32 *)(temp_3 + 0x3E0) = temp_f4;
        *(f32 *)(temp_3 + 0x3E4) = temp_f1;
        *(f32 *)(temp_3 + 0x420) = temp_f0_4;
        *(f32 *)(temp_3 + 0x424) = temp_f1;
        *(f32 *)(temp_3 + 0x460) = (f32)*(s32 *)(temp_3 + 0xC);
        *(f32 *)(temp_3 + 0x464) = (f32)*(s32 *)(temp_3 + 0x10);
        temp_5 = *(s32 *)(temp_3 + 0xC) + *(s32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x4A0) = (f32)temp_5;
        *(f32 *)(temp_3 + 0x4A4) = (f32)*(s32 *)(temp_3 + 0x10);
        *(f32 *)(temp_3 + 0x4E0) = (f32)*(s32 *)(temp_3 + 0xC);
        temp_5 = *(s32 *)(temp_3 + 0x10) + *(s32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x4E4) = (f32)temp_5;
        temp_5 = *(s32 *)(temp_3 + 0xC) + *(s32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x520) = (f32)temp_5;
        temp_5 = *(s32 *)(temp_3 + 0x10) + *(s32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x524) = (f32)temp_5;
    }
}
#undef sp0
#undef sp4
#undef sp8
#undef spC
/* MATCHED 2026-09-18.  The last 20 words were `addiu $aN, $gp, ...` emitted
   one slot before the `lw $a1, ...($gp)` that should precede it, at every
   func_004501f0 and func_00450340 call.  Both take a pointer for the format
   argument, not an s32: b210 evaluates a cast address ahead of the plain
   arguments, so `(s32)&iGpffffb0xx` pulled the `addiu` forward.  Declaring
   the parameter `const void *` and dropping the casts restores retail's
   order.  Same lever as func_00196040's out-parameters in code1_001c.c. */
// FUN_0046EC70
void func_0046ec70(u8 *arg0) {
    extern char *func_00442830(char *dst, const char *src);
    extern s32 func_00442948(const void *str);
    extern s32 func_0044dcd8(f32 value);
    extern void func_004501f0(s64 arg0, s32 arg1, const void *arg2, ...);
    extern void func_00450340(s64 arg0, const void *arg1, ...);
    extern s32 iGpffffb064;
    extern char iGpffffb068;
    extern char iGpffffb06c;
    extern char iGpffffb070;
    extern char iGpffffb078;
    extern char iGpffffb080;
    extern char iGpffffb088;
    extern char iGpffffb090;
    extern char iGpffffb098;
    extern char iGpffffb0a0;
    extern char iGpffffb0a4;
    extern char iGpffffb0a8;
    extern char iGpffffb0b0;
    u8 *ctx;
    u8 *node;
    s32 i;
    s32 w;
    char buf[0x108];
    f32 pos[2];
    ctx = *(u8 **)(arg0 + 0x38);
    node = *(u8 **)(ctx + 0x144);
    pos[0] = (f32)(*(s32 *)(ctx + 0x18) + 2);
    pos[1] = (f32)(*(s32 *)(ctx + 0x1C) + 2);
    for (i = 0; node != NULL; i++) {
        s32 first;
        first = *(s32 *)(ctx + 0x138);
        if (i < first) {
            node = *(u8 **)(node + 0x228);
            continue;
        }
        if (i > first + *(s32 *)(ctx + 0x13C) - 1) {
            return;
        }
        if (*(s32 *)(ctx + 0x154) != 0) {
            ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb068, node + 8);
            switch (*(s32 *)(node + 4)) {
            case 0:
                break;
            case 1: {
                func_00442088(buf, &iGpffffb06c, node + 0x108);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(*(s32 *)(ctx + 0x28) + (w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf)));
                ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                break;
            }
            case 2: {
                func_00442830(buf, &iGpffffb070);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(*(s32 *)(ctx + 0x28) + (w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf)));
                if (*(s32 *)(node + 0x208) == 1) {
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, &iGpffffb078);
                } else {
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, &iGpffffb080);
                }
                break;
            }
            case 3: {
                if (*(s32 *)(node + 0x218) == 0) {
                    func_00442088(buf, &iGpffffb088, *(s32 *)(node + 0x208));
                    w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                    pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                } else {
                    func_00442088(buf, &iGpffffb090, *(s32 *)(node + 0x208));
                    w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                    pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                }
                break;
            }
            case 4: {
                s32 v;
                v = func_0044dcd8(*(f32 *)(node + 0x20C));
                func_00442088(buf, &iGpffffb098, v);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                break;
            }
            }
        } else {
            func_00450340(*(s64 *)pos, &iGpffffb0a0, node + 8);
            switch (*(s32 *)(node + 4)) {
            case 0:
                break;
            case 1: {
                s32 v;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * (func_00442948(node + 0x108) + 1));
                pos[0] = (f32)(u32)v;
                func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb0a4, node + 0x108);
                break;
            }
            case 2: {
                s32 v;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * (func_00442948(&iGpffffb0a8) + 1));
                pos[0] = (f32)(u32)v;
                if (*(s32 *)(node + 0x208) == 1) {
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb078);
                } else {
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb080);
                }
                break;
            }
            case 3: {
                if (*(s32 *)(node + 0x218) == 0) {
                    s32 v;
                    v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 9);
                    pos[0] = (f32)v;
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb088, *(s32 *)(node + 0x208));
                } else {
                    s32 v;
                    v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 11);
                    pos[0] = (f32)v;
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb0b0, *(s32 *)(node + 0x208));
                }
                break;
            }
            case 4: {
                s32 v;
                s32 r;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 8);
                pos[0] = (f32)v;
                r = func_0044dcd8(*(f32 *)(node + 0x20C));
                func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb098, r);
                break;
            }
            }
        }
        pos[0] = (f32)(*(s32 *)(ctx + 0x18) + 2);
        pos[1] = pos[1] + (f32)*(s32 *)(ctx + 0x2C);
        node = *(u8 **)(node + 0x228);
    }
}
/* Within band +4: retail 984 vs object 988 (band 954-1013). Probe 890 words (base 985, -95).
 * Candidate /tmp/vE_all6_case4.c (from /var/tmp/cold46f2b0/cand_base_honest.c + 2 fixes; fnalign honest 1081->988).
 * Fixes measured via probe_variants + fnalign (isolated TU copies, same flags as baseline):
 * - u8->float dead branches: 6x `if ((s32)u8>=0) (f32)u8 else 2.0f*(f32)((u>>1)|(u&1))` always-taken (u8 0..255 => (s32)u8 >=0, else dead) but MWCC emits both sides incl. sra/andi/or/mtc1/cvt/lui/mtc1/mul.s.
 *   Simplified all 6 to direct `(f32)u8` (loop temp_11/10/9/8 + D_008C025C/D): probe 985->899 (-86), fnalign 1081->993 (-88, pure inserts [593:605] len12 + [628:640] len12 gone).
 * - outer switch density: retail jtbl_007567C0 6 entries 0-5 (case4 -> block_167 shared tail at +0xf04, case5 return -1 at +0xef8); candidate lacked explicit case4 (fell to default) so MWCC used beq chain, not table.
 *   Added `case 4: goto block_167;`: probe 899->890 (-9), fnalign 993->988 (-5, edits 531->510).
 * Audited, excluded with measurement (not assumed):
 * - absolute-value: no abs.s/fabs in retail or object (grep 0); deadzone `spB0<-48 / spB0>48` (and spB8) is two compares (c.lt/c.le + bc1) in both, no bit-mask/neg variant present -> 0 extra.
 * - unsigned (f32)(u32): 0 in body (all (f32)(s32)/(f32)u8) -> excluded.
 * - dsll32/dsra32: 0 in fnalign object and built .o -> excluded.
 * - field-by-field rect/colour/work stores match retail sw/swc1 counts -> excluded.
 * - defensive 9x null checks match retail beqz -> excluded.
 * - absolute 0x007641xx lui: 28x probe-only (built .o gp-relative via small-data) -> excluded from source fix.
 * - frame retail 0xE0 vs probe object 0xB0 (-48 smaller) -> excluded, not bloat.
 * Decl sweep S1-S8 not repeated per assignment (985/985/998/998/985/985/998/998, colouring not shape).
 */
/* measured 2026-09-19: lui +15 unchanged (35 object vs 20 retail: 9x absolute 0x76 + 6x tables D_00887300/10; absolute excluded per above as probe-only, tables tested: tbl300/310 hoist keeps 988/984 but edits 510->599 (+89) so not taken; tbl300-only 985/984 (-3) with edits 510->603 (+93) so not taken); words 890, edits 510(+12 reloc) unchanged; no large holes (largest deletes 4,2,1). No source change. */
// FUN_0046F2B0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0046f2b0(u8 *arg0)
{
    extern s32 func_00457120(void);
    extern s32 func_003e8120(s32 arg0);
    extern void func_003e8110(s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern s32 func_00453960(void *arg0);
    extern s32 func_00453d70(void *arg0);
    extern s32 func_00453dc0(void *arg0);
    extern u8 *func_0046e850(u8 *parent, void *rect_arg, void *first_arg, void *second_arg);
    extern s32 func_0046ea10(u8 *arg0);
    extern void func_0046ea60(u8 *arg0, u8 *arg1);
    extern void func_0046ec70(u8 *arg0);
    extern void func_00470490(u8 *arg0, s32 arg1, s32 arg2);
    extern u8 *func_00470d10(u8 *arg0, s32 arg1);
    extern s32 func_00470e20(u8 *arg0);
    extern void (*D_00887300[])(s32, s32);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
    extern u16 D_008C0252[];
    extern u8 D_008C025C[];
    extern u8 D_008C025D[];
    extern f32 D_00761514;

    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB0;
    s32 spAC;
    void *spA8;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 (*temp_2)(s32);
    s32 (*temp_5)(void *, void *);
    f32 *var_3_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f1;
    f32 var_f1_2;
    s32 *var_3;
    s32 *var_3_2;
    s32 *var_3_3;
    s32 *var_3_4;
    s32 temp_2_2;
    s32 temp_2_6;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_12;
    s32 var_18;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_6;
    s32 var_6_2;
    u32 temp_4;
    u8 temp_10;
    u8 temp_11;
    u8 temp_8;
    u8 temp_9;
    void *temp_17;
    void *temp_2_3;
    void *temp_2_4;
    void *temp_2_5;
    void *temp_7;

    temp_17 = (*(void **)((u8 *)(arg0) + (0x38)));
    var_18 = 0;
    temp_4 = (*(u32 *)((u8 *)(temp_17) + (0)));
    switch (temp_4) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if ((*(s32 *)((u8 *)(temp_17) + (0xC))) == 1) {
            (*(u32 *)((u8 *)(temp_17) + (0))) = (u32) (temp_4 + 1);
        }
    default:                                        /* switch 1 */
block_167:
        if ((s32) (*(u32 *)((u8 *)(temp_17) + (0))) >= 3) {
            temp_2 = (*(s32 (**)(s32))((u8 *)(temp_17) + (0x14C)));
            if (temp_2 != NULL) {
                temp_2((*(s32 *)((u8 *)(temp_17) + (0x150))));
            }
        }
        return 0;
    case 1:                                         /* switch 1 */
        temp_f21 = (*(f32 *)((u8 *)(func_00457120()) + (0x80)));
        temp_f20 = 1.0f / temp_f21;
        temp_3 = (*(s32 *)((u8 *)(temp_17) + (8)));
        switch (temp_3) {                           /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_3 = &sp90;
            var_2 = 0x10;
            if (var_3 != NULL) {
                do {
                    *var_3 = 0;
                    var_3 += 1;
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            sp90 = (*(s32 *)((u8 *)(temp_17) + (0x18)));
            sp94 = (*(s32 *)((u8 *)(temp_17) + (0x1C)));
            sp98 = (*(s32 *)((u8 *)(temp_17) + (0x20)));
            sp9C = (*(s32 *)((u8 *)(temp_17) + (0x24)));
            spDC = (*(f32 *)0x00764134);
            spD8 = (*(f32 *)0x00764138);
            (*(u8 **)((u8 *)(temp_17) + 0x130)) = func_0046e850(arg0, &sp90, &spDC, &spD8);
            (*(u8 *)0x007641A8) = 0U;
            (*(u8 *)0x007641A9) = 0xE3U;
            (*(u8 *)0x007641AA) = 0U;
            (*(u8 *)0x007641AB) = 0x40U;
            break;
        case 1:                                     /* switch 2 */
            var_3_2 = &sp80;
            var_2_2 = 0x10;
            if (var_3_2 != NULL) {
                do {
                    *var_3_2 = 0;
                    var_3_2 += 1;
                    var_2_2 -= 1;
                } while (var_2_2 != 0);
            }
            sp80 = (*(s32 *)((u8 *)(temp_17) + (0x18)));
            sp84 = (*(s32 *)((u8 *)(temp_17) + (0x1C)));
            sp88 = (*(s32 *)((u8 *)(temp_17) + (0x20)));
            sp8C = (*(s32 *)((u8 *)(temp_17) + (0x24)));
            spD4 = (*(f32 *)0x0076413C);
            spD0 = (*(f32 *)0x00764140);
            (*(u8 **)((u8 *)(temp_17) + 0x130)) = func_0046e850(arg0, &sp80, &spD4, &spD0);
            (*(u8 *)0x007641A8) = 0x54U;
            (*(u8 *)0x007641A9) = 0U;
            (*(u8 *)0x007641AA) = 0U;
            (*(u8 *)0x007641AB) = 0x60U;
            break;
        case 2:                                     /* switch 2 */
            var_3_3 = &sp70;
            var_2_3 = 0x10;
            if (var_3_3 != NULL) {
                do {
                    *var_3_3 = 0;
                    var_3_3 += 1;
                    var_2_3 -= 1;
                } while (var_2_3 != 0);
            }
            sp70 = (*(s32 *)((u8 *)(temp_17) + (0x18)));
            sp74 = (*(s32 *)((u8 *)(temp_17) + (0x1C)));
            sp78 = (*(s32 *)((u8 *)(temp_17) + (0x20)));
            sp7C = (*(s32 *)((u8 *)(temp_17) + (0x24)));
            spCC = (*(f32 *)0x00764144);
            spC8 = (*(f32 *)0x00764148);
            (*(u8 **)((u8 *)(temp_17) + 0x130)) = func_0046e850(arg0, &sp70, &spCC, &spC8);
            (*(u8 *)0x007641A8) = 0xE3U;
            (*(u8 *)0x007641A9) = 0x4AU;
            (*(u8 *)0x007641AA) = 0U;
            (*(u8 *)0x007641AB) = 0x60U;
            break;
        case 3:                                     /* switch 2 */
            var_3_4 = &sp60;
            var_2_4 = 0x10;
            if (var_3_4 != NULL) {
                do {
                    *var_3_4 = 0;
                    var_3_4 += 1;
                    var_2_4 -= 1;
                } while (var_2_4 != 0);
            }
            sp60 = (*(s32 *)((u8 *)(temp_17) + (0x18)));
            sp64 = (*(s32 *)((u8 *)(temp_17) + (0x1C)));
            sp68 = (*(s32 *)((u8 *)(temp_17) + (0x20)));
            sp6C = (*(s32 *)((u8 *)(temp_17) + (0x24)));
            spC4 = (*(f32 *)0x0076414C);
            spC0 = (*(f32 *)0x00764150);
            (*(u8 **)((u8 *)(temp_17) + 0x130)) = func_0046e850(arg0, &sp60, &spC4, &spC0);
            (*(u8 *)0x007641A8) = 0x80U;
            (*(u8 *)0x007641A9) = 0x80U;
            (*(u8 *)0x007641AA) = 0x80U;
            (*(u8 *)0x007641AB) = 0x60U;
            break;
        }
        var_12 = 0;
        temp_11 = (*(u8 *)0x007641A8);
        temp_10 = (*(u8 *)0x007641A9);
        temp_9 = (*(u8 *)0x007641AA);
        temp_8 = (*(u8 *)0x007641AB);
loop_35:
        if (var_12 < 4) {
            temp_7 = (u8 *)temp_17 + (var_12 << 6);
            (*(s32 *)((u8 *)(temp_7) + (0x30))) = 0;
            (*(s32 *)((u8 *)(temp_7) + (0x34))) = 0;
            (*(f32 *)((u8 *)(temp_7) + (0x38))) = temp_f21;
            (*(f32 *)((u8 *)(temp_7) + (0x48))) = temp_f20;
            var_f0 = (f32) temp_11;
            (*(f32 *)((u8 *)(temp_7) + (0x50))) = var_f0;
            var_f0_2 = (f32) temp_10;
            (*(f32 *)((u8 *)(temp_7) + (0x54))) = var_f0_2;
            var_f0_3 = (f32) temp_9;
            (*(f32 *)((u8 *)(temp_7) + (0x58))) = var_f0_3;
            var_f0_4 = (f32) temp_8;
            (*(f32 *)((u8 *)(temp_7) + (0x5C))) = var_f0_4;
            var_12 += 1;
            goto loop_35;
        }
        (*(u32 *)((u8 *)(temp_17) + (0))) = (u32) ((*(u32 *)((u8 *)(temp_17) + (0))) + 1);
        goto block_167;
    case 2:                                         /* switch 1 */
        if (func_0046ea10((*(u8 **)((u8 *)(temp_17) + 0x130))) != 1) {
            func_0046ea60((*(u8 **)((u8 *)(temp_17) + 0x130)), (u8 *)temp_17 + 0x18);
            (*(u32 *)((u8 *)(temp_17) + (0))) = (u32) ((*(u32 *)((u8 *)(temp_17) + (0))) + 1);
        }
        goto block_167;
    case 3:                                         /* switch 1 */
        if (D_008C024C[0] & 8) {
            var_18 = 1;
        } else if (D_008C024C[0] & 4) {
            var_18 = 2;
        } else if (D_008C024C[0] & 2) {
            var_18 = 3;
        } else if (D_008C024C[0] & 1) {
            var_18 = 4;
        }
        if ((D_008C024C[0] & 2) && (D_008C024C[0] & 1)) {
            var_18 = 5;
        }
        if (((*(s32 *)((u8 *)(temp_17) + (0xC))) == 1) && ((*(s32 *)((u8 *)(temp_17) + (0x140))) != 0)) {
            if (!((*(s32 *)((u8 *)(temp_17) + (4))) & 1)) {
                (*(f32 *)((u8 *)(temp_17) + (0x30))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) + 2);
                (*(f32 *)((u8 *)(temp_17) + (0x34))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x1C))) + 2 + ((*(s32 *)((u8 *)(temp_17) + (0x134))) * (*(s32 *)((u8 *)(temp_17) + (0x2C)))));
                (*(f32 *)((u8 *)(temp_17) + (0x70))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) - 2 + (*(s32 *)((u8 *)(temp_17) + (0x20))));
                (*(f32 *)((u8 *)(temp_17) + (0x74))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x1C))) + 2 + ((*(s32 *)((u8 *)(temp_17) + (0x134))) * (*(s32 *)((u8 *)(temp_17) + (0x2C)))));
                (*(f32 *)((u8 *)(temp_17) + (0xB0))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) + 2);
                (*(f32 *)((u8 *)(temp_17) + (0xB4))) = (f32) (((*(s32 *)((u8 *)(temp_17) + (0x2C))) * ((*(s32 *)((u8 *)(temp_17) + (0x134))) + 1)) + 2 + (*(s32 *)((u8 *)(temp_17) + (0x1C))));
                (*(f32 *)((u8 *)(temp_17) + (0xF0))) = (f32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) - 2 + (*(s32 *)((u8 *)(temp_17) + (0x20))));
                (*(f32 *)((u8 *)(temp_17) + (0xF4))) = (f32) (((*(s32 *)((u8 *)(temp_17) + (0x2C))) * ((*(s32 *)((u8 *)(temp_17) + (0x134))) + 1)) + 2 + (*(s32 *)((u8 *)(temp_17) + (0x1C))));
                if (func_003e8120(func_00457120()) != 0) {
                    D_00887300[0](0xE, 0);
                    D_00887300[0](0xC, 1);
                    D_00887300[0](7, 2);
                    D_00887300[0](0x14, 1);
                    D_00887300[0](6, 0);
                    D_00887300[0](8, 0);
                    D_00887300[0](1, 0);
                    func_003f6440(2, 0x44);
                    func_003f6440(3, 0x717FB);
                    D_00887310[0](4, (u8 *)temp_17 + 0x30, 4);
                }
                func_003e8110(func_00457120());
            }
            func_003e8120(func_00457120());
            func_0046ec70(arg0);
            func_003e8110(func_00457120());
            if ((*(s32 *)((u8 *)(temp_17) + (4))) & 4) {
                var_3_5 = &spB0;
                var_2_5 = 0xC;
                if (var_3_5 != NULL) {
                    do {
                        *var_3_5 = 0;
                        var_3_5 += 1;
                        var_2_5 -= 1;
                    } while (var_2_5 != 0);
                }
                var_f1 = (f32) D_008C025C[0];
                spB0 = var_f1 - 128.0f;
                var_f1_2 = (f32) D_008C025D[0];
                spB8 = var_f1_2 - 128.0f;
                if (spB0 < -48.0f) {
                    (*(s32 *)((u8 *)(temp_17) + (0x18))) = (s32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) - 0xA);
                } else if (!(spB0 <= 48.0f)) {
                    (*(s32 *)((u8 *)(temp_17) + (0x18))) = (s32) ((*(s32 *)((u8 *)(temp_17) + (0x18))) + 0xA);
                }
                if (spB8 < -48.0f) {
                    (*(s32 *)((u8 *)(temp_17) + (0x1C))) = (s32) ((*(s32 *)((u8 *)(temp_17) + (0x1C))) - 0xA);
                } else if (!(spB8 <= 48.0f)) {
                    (*(s32 *)((u8 *)(temp_17) + (0x1C))) = (s32) ((*(s32 *)((u8 *)(temp_17) + (0x1C))) + 0xA);
                }
                func_00470490(arg0, (*(s32 *)((u8 *)(temp_17) + (0x18))), (*(s32 *)((u8 *)(temp_17) + (0x1C))));
            }
            if (!((*(s32 *)((u8 *)(temp_17) + (4))) & 2)) {
                temp_2_2 = (*(s32 *)((u8 *)(temp_17) + (0x10)));
                if (temp_2_2 > 0) {
                    (*(s32 *)((u8 *)(temp_17) + (0x10))) = (s32) (temp_2_2 - 1);
                } else if (func_00453960((u8 *)temp_17 + 0x164) != 0) {
                    (*(s32 *)((u8 *)(temp_17) + (0x138))) = func_00453d70((u8 *)temp_17 + 0x164);
                    (*(s32 *)((u8 *)(temp_17) + (0x134))) = func_00453dc0((u8 *)temp_17 + 0x164);
                } else if (D_008C0252[0] & 0x2000) {
                    temp_2_3 = func_00470d10(arg0, func_00470e20(arg0));
                    if (temp_2_3 != NULL) {
                        temp_6 = (*(s32 *)((u8 *)(temp_2_3) + (4)));
                        switch (temp_6) {           /* switch 3; irregular */
                        case 1:                     /* switch 3 */
                        case 0:                     /* switch 3 */
                            break;
                        case 2:                     /* switch 3 */
                            (*(s32 *)((u8 *)(temp_2_3) + (0x208))) = (s32) ((*(s32 *)((u8 *)(temp_2_3) + (0x208))) != 1);
                            break;
                        case 3:                     /* switch 3 */
                            var_6 = 1;
                            switch (var_18) {       /* switch 4; irregular */
                            case 1:                 /* switch 4 */
                                var_6 = 0xA;
                                break;
                            case 2:                 /* switch 4 */
                                var_6 = 0x64;
                                break;
                            case 3:                 /* switch 4 */
                                var_6 = 0x3E8;
                                break;
                            case 4:                 /* switch 4 */
                                var_6 = 0x2710;
                                break;
                            case 5:                 /* switch 4 */
                                var_6 = 0x186A0;
                                break;
                            }
                            temp_4_2 = (*(s32 *)((u8 *)(temp_2_3) + (0x208))) + var_6;
                            (*(s32 *)((u8 *)(temp_2_3) + (0x208))) = temp_4_2;
                            if ((*(s32 *)((u8 *)(temp_2_3) + (0x214))) < temp_4_2) {
                                (*(s32 *)((u8 *)(temp_2_3) + (0x208))) = (s32) (*(s32 *)((u8 *)(temp_2_3) + (0x210)));
                            }
                            break;
                        case 4:                     /* switch 3 */
                            {
                                s32 step = 1;
                                switch (var_18) {
                                case 1:
                                    step = 10;
                                    break;
                                case 2:
                                    step = 100;
                                    break;
                                case 3:
                                    step = 1000;
                                    break;
                                case 4:
                                    step = 10000;
                                    break;
                                case 5:
                                    step = 100000;
                                    break;
                                }
                                temp_f1 = (*(f32 *)((u8 *)(temp_2_3) + 0x20C)) + D_00761514 * (f32)step;
                                (*(f32 *)((u8 *)(temp_2_3) + 0x20C)) = temp_f1;
                                if (!(temp_f1 <= (f32)(*(s32 *)((u8 *)(temp_2_3) + 0x214)))) {
                                    (*(f32 *)((u8 *)(temp_2_3) + 0x20C)) = (f32)(*(s32 *)((u8 *)(temp_2_3) + 0x210));
                                }
                            }
                            break;
                        }
                    }
                } else if (D_008C0252[0] & 0x8000) {
                    temp_2_4 = func_00470d10(arg0, func_00470e20(arg0));
                    if (temp_2_4 != NULL) {
                        temp_6_2 = (*(s32 *)((u8 *)(temp_2_4) + (4)));
                        switch (temp_6_2) {         /* switch 6; irregular */
                        case 1:                     /* switch 6 */
                        case 0:                     /* switch 6 */
                            break;
                        case 2:                     /* switch 6 */
                            (*(s32 *)((u8 *)(temp_2_4) + (0x208))) = (s32) ((*(s32 *)((u8 *)(temp_2_4) + (0x208))) != 1);
                            break;
                        case 3:                     /* switch 6 */
                            var_6_2 = 1;
                            switch (var_18) {       /* switch 7; irregular */
                            case 1:                 /* switch 7 */
                                var_6_2 = 0xA;
                                break;
                            case 2:                 /* switch 7 */
                                var_6_2 = 0x64;
                                break;
                            case 3:                 /* switch 7 */
                                var_6_2 = 0x3E8;
                                break;
                            case 4:                 /* switch 7 */
                                var_6_2 = 0x2710;
                                break;
                            case 5:                 /* switch 7 */
                                var_6_2 = 0x186A0;
                                break;
                            }
                            temp_4_3 = (*(s32 *)((u8 *)(temp_2_4) + (0x208))) - var_6_2;
                            (*(s32 *)((u8 *)(temp_2_4) + (0x208))) = temp_4_3;
                            if (temp_4_3 < (*(s32 *)((u8 *)(temp_2_4) + (0x210)))) {
                                (*(s32 *)((u8 *)(temp_2_4) + (0x208))) = (s32) (*(s32 *)((u8 *)(temp_2_4) + (0x214)));
                            }
                            break;
                        case 4:                     /* switch 6 */
                            {
                                s32 step2 = 1;
                                switch (var_18) {
                                case 1:
                                    step2 = 10;
                                    break;
                                case 2:
                                    step2 = 100;
                                    break;
                                case 3:
                                    step2 = 1000;
                                    break;
                                case 4:
                                    step2 = 10000;
                                    break;
                                case 5:
                                    step2 = 100000;
                                    break;
                                }
                                temp_f1_2 = (*(f32 *)((u8 *)(temp_2_4) + 0x20C)) - D_00761514 * (f32)step2;
                                (*(f32 *)((u8 *)(temp_2_4) + 0x20C)) = temp_f1_2;
                                if (temp_f1_2 < (f32)(*(s32 *)((u8 *)(temp_2_4) + 0x210))) {
                                    (*(f32 *)((u8 *)(temp_2_4) + 0x20C)) = (f32)(*(s32 *)((u8 *)(temp_2_4) + 0x214));
                                }
                            }
                            break;
                        }
                    }
                } else if (D_008C024E[0] & 0x40) {
                    temp_2_5 = func_00470d10(arg0, func_00470e20(arg0));
                    if (temp_2_5 != NULL) {
                        temp_5 = (*(s32 (**)(void *, void *))((u8 *)(temp_2_5) + 0x21C));
                        if (temp_5 != NULL) {
                            temp_4_4 = (*(s32 *)((u8 *)(temp_2_5) + (4)));
                            switch (temp_4_4) {     /* switch 9; irregular */
                            case 0:                 /* switch 9 */
                                temp_2_6 = (*(s32 *)((u8 *)(temp_2_5) + (0x220)));
                                if (temp_2_6 != 0) {
                                    spA8 = NULL;
                                    spAC = temp_2_6;
                                    temp_5((void *)&spA8, (void *)temp_5);
                                } else {
                                    temp_5((void *)NULL, (void *)temp_5);
                                }
                                break;
                            case 1:                 /* switch 9 */
                                temp_3_2 = (*(s32 *)((u8 *)(temp_2_5) + (0x220)));
                                if (temp_3_2 != 0) {
                                    spA8 = (u8 *)temp_2_5 + 0x108;
                                    spAC = temp_3_2;
                                    temp_5((void *)&spA8, (void *)temp_5);
                                } else {
                                    temp_5((void *)((u8 *)temp_2_5 + 0x108), (void *)temp_5);
                                }
                                break;
                            case 3:                 /* switch 9 */
                            case 2:                 /* switch 9 */
                                temp_4_5 = (*(s32 *)((u8 *)(temp_2_5) + (0x220)));
                                if (temp_4_5 != 0) {
                                    spA8 = (u8 *)temp_2_5 + 0x208;
                                    spAC = temp_4_5;
                                    (*(s32 (**)(void *, void *))((u8 *)(temp_2_5) + 0x21C))((void *)&spA8, (void *)temp_5);
                                } else {
                                    temp_5((void *)((u8 *)temp_2_5 + 0x208), (void *)temp_5);
                                }
                                break;
                            case 4:                 /* switch 9 */
                                temp_3_3 = (*(s32 *)((u8 *)(temp_2_5) + (0x220)));
                                if (temp_3_3 != 0) {
                                    spA8 = (u8 *)temp_2_5 + 0x20C;
                                    spAC = temp_3_3;
                                    temp_5((void *)&spA8, (void *)temp_5);
                                } else {
                                    temp_5((void *)((u8 *)temp_2_5 + 0x20C), (void *)temp_5);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        goto block_167;
    case 4:                                         /* switch 1 */
        goto block_167;
    case 5:                                         /* switch 1 */
        return -1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046f2b0);
#endif
