#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 lock;
    u8 pad[12];
    s32 arg6;
} Func004667d0Locals;
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
static inline u8 *func_004667d0_entry(u8 *base, s32 index)
{
    return base + index * 0x1DC;
}
extern void func_0043a978(void);
extern void func_004316a8(s32 arg0);
extern s32 func_00431928(void *a, u8 *b);
extern s32 func_003e1220(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
extern s32 iGpffffba98;
extern s32 iGpffffba9c;
extern u8 D_008E43C0[];
extern u8 D_008E43E4[];
extern void func_003bff30(void *object, void *callback, void *userdata);
extern u8 *func_004632f0(u8 *a0, u8 *a1);
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

extern void (*jtbl_008873EC[])();
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
extern void func_00451de0(u8 *name, s32 prio, s32 a2, s32 a3, void *entry, s32 a5, s32 a6);
extern s32 func_004633f0(void);
extern void func_00468ff0(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00460ac0(char *name, u8 *task);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern s32 func_004426e8(char *a, char *b);
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
extern s32 func_00451fc0(s32 arg0, s32 name, s32 prio, s32 a3, s32 a4,
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
extern void func_00440b68();
extern void func_00442088(void *dst, void *fmt, s32 arg2, s32 arg3);
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






// FUN_004604D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004604d0);
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
    extern void *func_00462170(void *);
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
    extern void (*D_00887310[])(s32, void *, s32);
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
            func_003bff30(*(void **)(p + 0x1C), (void *)func_00462170, NULL);
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

// FUN_00463930
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00463930);
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

// FUN_004667D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004667d0);
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
// FUN_004673C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004673c0);
// FUN_00467880
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467880);
// FUN_00467BD0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467bd0);
// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}



// FUN_004680F0
s32 func_004680f0(u8 *arg0, s8 *arg1) {
    u8 *temp_6;

    temp_6 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *arg1 = 0;
    if (*(s16 *)(temp_6 + 0x80F80) == 3) {
        if (*(s32 *)(temp_6 + 0x80F88) != 0) {
            func_00442830(arg1, temp_6 + 0x80F90, temp_6);
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
// FUN_00468D10
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468d10);
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

// FUN_00468FF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468ff0);
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
        jtbl_008873EC[0](*(s32 *)(work + 0x1E0));
        *(s32 *)(work + 0x1E0) = 0;
    }
    if (*(s32 *)(work + 0x200) != 0) {
        jtbl_008873EC[0](*(s32 *)(work + 0x200));
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
    result = func_00451fc0(arg0, iGpffffb034, 0xC6, 0, 0,
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
    result = func_00451fc0(arg0, iGpffffb034, 0xC6, 0, 0,
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
        (*jtbl_008873EC)();
        return;
    }
    if (iGpffffbb10 < arg0) {
        (*jtbl_008873EC)();
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
// FUN_0046A430
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a430);
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

// FUN_0046A7F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a7f0);
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
void func_0046d740(void) {}
// FUN_0046D750
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d750);
// FUN_0046E7F0
void func_0046e7f0(u8 *arg0)
{
    void (**tbl)(u8 *) = (void (**)(u8 *))jtbl_008873EC;
    u8 *work = *(u8 **)(arg0 + 0x38);

    tbl[0](*(u8 **)(work + 0x48));
    tbl[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0046E850
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046e850);
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
// FUN_0046EC70
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ec70);
// FUN_0046F2B0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046f2b0);
