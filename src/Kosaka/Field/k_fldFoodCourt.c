/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldFoodCourt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_00454bd0(void *arg0);
extern void func_003e0f40(void *arg0);
extern void func_00145080(void);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0044ea90(const void *msg, s32 id);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005F5450[];
extern u8 D_005F54C8[];
extern s32 func_0018d950(u8 *arg0);
extern void func_0018dcd0(u8 *arg0);
extern u8 D_005F5470[];
extern u8 D_005F5490[];
extern u8 D_005F54B0[];
extern char iGpffff9f90;
extern void *func_003e0f80(void);
extern void func_00144c90(s32 arg0, s32 arg1);
extern void func_00144ed0(s64 arg0);
extern s64 func_001546a0(s32 arg0, s32 arg1);
extern s32 func_0014bdb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00144f60(void);
extern s32 func_0015f660(void);
extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern s64 func_00110960(s64 arg0, s32 arg1);
extern u8 *func_0014b490(void);
extern u8 *func_0014b450(void);
extern u8 *func_00457120(void);
extern f32 func_0014b4d0(void);
extern void func_004577d0(u8 *arg0, f32 arg1);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00452490(s32 arg0);
extern s32 func_0018ced0(void);
extern void func_0018c7e0(void);
extern void func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);



// FUN_0018D950
s32 func_0018d950(u8 *arg0) {
    s32 temp_3;
    s32 temp_3_2;
    s32 var_4;
    s32 temp_2;
    s64 temp_17;
    u8 *temp_16;
    u8 *temp_17_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *var_6;
    u8 *var_2;
    u8 *var_2_2;
    s32 var_5;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        *(u8 **)(temp_16 + 4) = (u8 *)func_003e0f80();
        func_00144c90(9, 1);
        func_00144ed0((s64)(s16)func_001546a0(9, 1));
        if (func_0014bdb0(4, 1, 7, 0x1F) == 1) {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x58);
            *(u8 **)(temp_16 + 8) = (u8 *)func_00454a60(D_005F5470, 0);
        } else if (func_0014bdb0(8, 1, 0xB, 0x1E) == 1) {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x5C);
            *(u8 **)(temp_16 + 8) = (u8 *)func_00454a60(D_005F5490, 0);
        } else {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x60);
            *(u8 **)(temp_16 + 8) = (u8 *)func_00454a60(D_005F54B0, 0);
        }
        *(s32 *)temp_16 += 1;
    case 1:
        if (func_00144f60() != 0) {
            if (func_004553c0(*(u8 **)(temp_16 + 8)) == 0) {
                return 0;
            }
            if (func_0015f660() == 0) {
                return 0;
            }
            temp_17 = (s16)func_001060b0();
            if ((s8)func_00110960(temp_17, func_001060c0() & 0xFF) == 1) {
                var_2 = (u8 *)func_0014b490();
                var_6 = *(u8 **)(temp_16 + 4);
                var_5 = 8;
                do {
                    var_4 = *(s32 *)(var_2 + 0);
                    temp_3 = *(s32 *)(var_2 + 4);
                    var_2 += 8;
                    var_5 -= 1;
                    *(s32 *)(var_6 + 0) = var_4;
                    *(s32 *)(var_6 + 4) = temp_3;
                    var_6 += 8;
                } while (var_5 > 0);
            } else {
                var_2_2 = (u8 *)func_0014b450();
                var_6 = *(u8 **)(temp_16 + 4);
                var_5 = 8;
                do {
                    var_4 = *(s32 *)(var_2_2 + 0);
                    temp_3_2 = *(s32 *)(var_2_2 + 4);
                    var_2_2 += 8;
                    var_5 -= 1;
                    *(s32 *)(var_6 + 0) = var_4;
                    *(s32 *)(var_6 + 4) = temp_3_2;
                    var_6 += 8;
                } while (var_5 > 0);
            }
            temp_17_2 = (u8 *)func_00457120();
            func_004577d0(temp_17_2, func_0014b4d0());
            temp_17_2 = (u8 *)func_00457120();
            func_003e9cb0(*(s32 *)(temp_17_2 + 4), *(u8 **)(temp_16 + 4), 0);
            temp_2_2 = *(u8 **)(temp_16 + 8);
            *(s32 *)(temp_16 + 0xC) =
                func_0029db50(0xF, *(s32 *)(temp_2_2 + 0x110), *(s32 *)(temp_2_2 + 0x118), 0);
            *(s32 *)temp_16 += 1;
        } else {
            goto done;
        }
    case 2:
        if (func_00452490(*(s32 *)(temp_16 + 0xC)) != 1) {
            if (func_0018ced0() == 0) {
                func_0018c7e0();
            }
            func_00122640(1, 0);
            *(s32 *)temp_16 += 1;
        }
        else {
            goto done;
        }
    case 3:
        if (func_00122720() != 0) {
            temp_2_3 = *(u8 **)(temp_16 + 8);
            *(s32 *)(temp_16 + 0xC) =
                func_0029db50(0xF, *(s32 *)(temp_2_3 + 0x110), *(s32 *)(temp_2_3 + 0x118), 1);
            *(s32 *)temp_16 += 1;
        }
    case 4:
    case 5:
    default:
        goto done;
    }
done:
    return 0;
}

// FUN_0018DCD0
void func_0018dcd0(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    func_00454bd0(*(void **)(work + 8));
    func_003e0f40(*(void **)(work + 4));
    func_00145080();
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018DD40
s32 func_0018dd40(u8 *arg0)
{
    u8 *mem;

    func_0044ea90(D_005F5450, 0xBF);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    return func_00451fc0(arg0, D_005F54C8, 0xF, 0, 0, (void (*)(u8 *))func_0018d950,
                         func_0018dcd0, mem);
}

