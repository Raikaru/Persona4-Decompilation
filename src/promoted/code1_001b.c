#include "include_asm.h"
#include "type.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_001fc1b0(s16 arg0);
extern s32 func_002aa300(s32 arg0, s32 arg1);
extern void func_00144c90(s32 arg0, s32 arg1);
extern s32 func_003bbb60(u8 *arg0);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern u8 *iGpffffb3bc;
extern void func_001b0d00(s32 arg0, s32 arg1);
extern void *func_0014acd0(void);
extern void *func_0014ad10(void);
extern void func_001b6990();
extern void func_00193d30(void);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern void func_00194fc0(u8 *arg0, s32 arg1);
extern s32 func_00452080(KwlnTask *arg0);
extern u32 func_00452560(s32 arg0);
extern s32 func_00459760(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_00213a10(s32 arg0);
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern u8 *func_00193bf0(u64 arg0, u64 arg1);
extern s32 func_001f6290(void);
extern s32 func_00144f60(void);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_004833f0(void *arg0);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern s32 func_00196b50(u8 *arg0);
extern void func_00194ff0(u8 *arg0, void *arg1, void *arg2, void *arg3);
extern u8 *func_00197f50(u8 *arg0, void *arg1, s32 arg2);
extern void func_00194590(u8 *arg0, u32 arg1);
extern void func_001b0800(u8 *arg0, u32 arg1);
extern s32 func_001b0fa0(u8 *arg0);
extern void func_002bbcc0(void);
extern s32 func_002bb600(void);
extern s32 func_002bb140(void);
extern void func_002bb380(void);
extern void func_002bb4e0(void);

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void func_0022bd60(void);
extern s32 func_001fadc0(u8 *arg0);
extern u32 func_00193c70(void);
extern BtlPacket *func_001f5f70(u32 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void func_0019d040(u8 *arg0);
extern void func_0019d0c0(u8 *arg0);
extern s32 func_001ef9a0(void);
extern void func_002aaaa0(void);
extern void func_001fc230(s32 arg0);
extern s32 func_001faaa0(u8 *arg0);
extern s32 func_00230210(void);
extern void func_00198920(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern s32 func_001fae10(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_002aa3f0(void);
extern void func_00192b20(void);
extern void func_00145080();
extern void func_001ba0e0(void);
extern u8 *func_00194470(s32 size, s32 align);
extern void func_001ec5e0(u8 *arg0, f32 fp);
extern void func_001b69c0(void);
extern s32 func_001ba590(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern void func_0044ea90(const void *file, s32 line);
extern void func_001eb380(u8 *arg0);
extern s64 func_00192560(void);
extern u32 func_00231d70(u32 arg0);
extern u32 func_00232c70(u8 *arg0, s32 arg1);
extern void func_0022fdc0(u8 *arg0);
extern s8 func_00243e90(u8 *arg0);
extern void func_001b1020(s32 arg0);
extern void func_001b1280(s32 arg0);
extern u32 iGpffffa0b8;
extern void func_0014a2e0(u32 arg0);
extern void func_001b6120(void);
extern s32 func_00106330(s32 arg0);
extern BtlPacket *func_001f9b80(u16 arg0);
extern u8 *func_001f97b0(void);
extern u8 *func_002304b0(void);
extern s32 func_00230790(void);
extern u8 *func_002305c0(s32 arg0);
extern void func_002aaa80(void);
extern void func_001fc280(void);
void func_00194590(u8 *arg0, u32 arg1);
extern s32 func_0021d470(s32 arg0);
extern void func_00198dd0(u8 *arg0, s32 arg1);
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern s32 func_001faaf0(void);
extern s32 func_001fab40(u8 *arg0);
extern s32 func_001fab90(void);
extern void func_00212240(u8 *arg0, s32 arg1);
u8 *btlCameraCreateSetStatePacket(u8 *arg0, u32 arg1);
u8 *func_001d3700(u32 arg0, u32 arg1);
void func_002baac0(void *arg0);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 arg4);
extern void func_001b73f0(u8 *arg0);
extern s32 func_004bd050(s32 arg0);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_001be990(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *func_0014ad50(void);
extern u8 *func_00149ca0(void);
extern u8 *func_00149ce0(void);
extern s32 func_001d10d0(u8 *arg0, u8 *arg1);
extern void func_001d07e0(u8 *arg0, u8 *arg1);
extern u8 *func_001d1200(u8 *arg0);
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_001bdeb0(u8 *arg0);
extern u8 *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u8 *func_00194b60(void);
extern BtlPacket *func_001f60c0(void);
extern void func_001f86d0(void);
extern void func_00212100(s32 arg0);
extern void func_00213990(s32 arg0);
extern s32 func_002139d0(s32 arg0);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 func_0021db10(s32 arg0);
extern s32 func_00213a50(s32 arg0);
extern s32 func_0021db40(s32 arg0);
extern s32 func_00122720(void);
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern u8 *func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern void func_0019d550(u8 *arg0);
extern void func_001b08f0(void *arg0);
extern void func_001bc800(u8 *arg0);
extern void func_002318c0(DatUnitEc *arg0, DatUnit *arg1);
extern void func_002326f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_002339d0(s32 arg0);
extern void func_00194f60(u8 *arg0, s32 arg1);
extern void func_001bc660();
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern void func_001bd560(f32 *arg0, f32 *arg1);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern u32 func_001ba9e0(u16 *arg0, f32 *arg1, f32 *arg2);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 func_001ec630(f32 value, f32 *state);
extern u32 func_001bbc40(u8 *arg0, f32 *arg1, f32 *arg2);
extern u32 func_001bbd80(u8 *arg0, f32 arg1);
extern f32 fGpffff8430;
extern void func_0045f0b0(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void func_0045fa00(f32 *arg0, s32 arg1, f32 arg2);
extern u8 *func_0022cdb0(s32 arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern u8 *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void func_001bd390(void);
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern s32 func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
extern void func_001d12e0(void *arg0);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern void func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);

s32 func_001f2f90(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);

void btlUnitSetFlags(u8 *arg0, u32 arg1);
void btlUnitClearFlags(u8 *arg0, u32 arg1);



// FUN_001B0020
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0020);
// FUN_001B0260
void func_001b0260(u8 *arg0)
{
    f32 sp20[3];
    u8 *temp_2;

    if (func_00196b50(*(u8 **)(arg0 + 0x30)) == 0) {
        if (*(s32 *)(arg0 + 0x41C) == 1) {
            func_00194ff0(*(u8 **)(arg0 + 0x30), NULL, NULL, sp20);
            temp_2 = func_00197f50(*(u8 **)(arg0 + 0x30), sp20, 0);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 1);
        }
        func_001b0800(arg0, 1);
    }
}
// FUN_001B0300
void func_001b0300(u8 *arg0)
{
    u8 *p;
    u8 status;
    u8 *work;
    s32 flags;
    s32 flags2;

    p = *(u8 **)(arg0 + 0x30);
    func_001b0dd0(arg0);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        func_002339d0(*(s32 *)(p + 0xA64));
        return;
    case 1:
        func_001f2cc0(arg0);
        flags = *(s32 *)(p + 0x9C);
        if ((flags & 0x20) == 0 && (flags & 0x100) == 0) {
            work = (u8 *)func_0019bbe0((BtlUnit *)p, 0xFFFFFF, 6, 0, 4, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 1);
            work = func_001d6240((u32)*(s32 *)(iGpffffb3ac + 0xD48), (u32)p, (u32)p, 0, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 2);
            work = func_001f7c20(0xA, 2, 0xA);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 1);
        }
        flags2 = *(s32 *)(p + 0x9C);
        if ((flags2 & 0x40) == 0 && (flags2 & 8) != 0) {
            *(s32 *)(p + 0x9C) = flags2 & ~8;
        }
        return;
    default:
        return;
    }
}
// FUN_001B0460
void func_001b0460(u8 *arg0)
{
    u8 status;
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        if (func_002428f0(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
                func_0022fdc0((u8 *)func_001b1540());
            }
            func_001b0800(arg0, 1);
        }
        break;
    case 1:
        if ((*(s32 *)(p + 0x9C) & 0x40) == 0) {
            func_001b0800(arg0, 0x24);
            return;
        }
        if (func_002428f0(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            func_001b0800(arg0, 1);
        }
        break;
    default:
        break;
    }
}
// FUN_001B0590
void func_001b0590(u8 *arg0)
{
    s32 temp;
    u8 *p;
    s32 *field;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        field = (s32 *)(p + 0x9C);
        temp = *field;
        if (temp & 8) {
            *field = temp & ~8;
        }
    }
}
// FUN_001B05D0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b05d0);
// FUN_001B07C0
void func_001b07c0(void)
{
}
// FUN_001B0930
u8 *func_001b0930(void)
{
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(&D_005F6FE8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x458, 0x40000);
    func_0043f9c8(temp_2, 0, 0x458);
    func_001eb380(temp_2 + 0x38);
    *(s16 *)(temp_2 + 0xE) = 0;
    *(s16 *)(temp_2 + 0x14) = 8;
    *(s64 *)temp_2 = func_00192560();
    if (iGpffffa0b8 >= 0x0FFFFFFFU) {
        iGpffffa0b8 = 1;
    }
    temp_3 = iGpffffa0b8;
    iGpffffa0b8 = temp_3 + 1;
    *(u32 *)(temp_2 + 8) = temp_3;
    *(s32 *)(temp_2 + 0x24) = -1;
    *(s16 *)(temp_2 + 0x36) = (s16)func_00231d70(0x3C);
    *(s32 *)(temp_2 + 0x44C) = 0;
    temp_2_2 = *(u8 **)(iGpffffb3ac + 0x174);
    if (temp_2_2 != NULL) {
        *(u8 **)(temp_2_2 + 0x44C) = temp_2;
        *(u8 **)(temp_2 + 0x450) = *(u8 **)(iGpffffb3ac + 0x174);
    } else {
        *(u8 **)(temp_2 + 0x450) = NULL;
    }
    *(u8 **)(iGpffffb3ac + 0x174) = temp_2;
    *(u16 *)(temp_2 + 0x10) = *(u16 *)(temp_2 + 0xC);
    *(u16 *)(temp_2 + 0xC) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0;
    D_005F6E20[0](temp_2);
    return temp_2;
}
/* measured: exact-size plain C dispatcher candidate; normalized_diff 9 against the 400B retail window. The remaining residual is confined to the decrement/store instruction order. Parked because nd <= 25. */
// Committed at nd 9.
// FUN_001B0A60 NONMATCHING
#ifdef NON_MATCHING
void func_001b0a60(void)
{
    u8 *var_18;
    u16 temp_3;
    u16 temp_3_3;
    u16 temp_4;
    u8 *temp_17;
    u8 *temp_3_4;
    u8 *temp_3_5;
    s32 var_16;
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    var_18 = *(u8 **)(base + 0x174);
    goto loop_check;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0x450);
    var_16 = 1;
    if (*(u16 *)(var_18 + 0xE) != 0) {
        temp_3 = *(u16 *)(var_18 + 0x12);
        if ((s32)temp_3 > 0) {
            temp_3 = temp_3 - 1;
            *(u16 *)(var_18 + 0x12) = temp_3;
            if ((temp_3 & 0xFFFF) != 0) goto decrement_not_zero;
            temp_3_3 = *(u16 *)(var_18 + 0xE);
            *(u16 *)(var_18 + 0x10) = *(u16 *)(var_18 + 0xC);
            *(u16 *)(var_18 + 0xC) = temp_3_3;
            *(s32 *)(var_18 + 0x1C) = 0;
            (*(void (**)(u8 *))((u8 *)D_005F6E20 + temp_3_3 * 0xC))(var_18);
            *(u16 *)(var_18 + 0xE) = 0;
            goto decrement_done;
decrement_not_zero:
            var_16 = 0;
decrement_done:
            ;
        }
    }
    if (var_16 != 0) {
        temp_4 = *(u16 *)(var_18 + 0x1A);
        if ((temp_4 & 4) == 0) {
            if ((*(u16 *)(var_18 + 0x18) & 1) != 0) {
                (*(void (**)(u8 *))((u8 *)D_005F6E20 + *(u16 *)(var_18 + 0xC) * 0xC + 4))(var_18);
                *(s32 *)(var_18 + 0x1C) += 2;
            } else if ((temp_4 & 2) != 0) {
                temp_3_4 = *(u8 **)(var_18 + 0x450);
                if (temp_3_4 != NULL) {
                    *(u8 **)(temp_3_4 + 0x44C) = *(u8 **)(var_18 + 0x44C);
                }
                temp_3_5 = *(u8 **)(var_18 + 0x44C);
                if (temp_3_5 != NULL) {
                    *(u8 **)(temp_3_5 + 0x450) = *(u8 **)(var_18 + 0x450);
                } else {
                    *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_18 + 0x450);
                }
                (*jtbl_008873EC)(var_18);
            }
        }
    }
    var_18 = temp_17;
loop_check:
    if (var_18 != NULL) goto loop_body;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0a60);
#endif
// FUN_001B0BF0
void func_001b0bf0(void)
{
    u8 *temp_16;
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_check;
loop_body:
    temp_16 = *(u8 **)(var_4 + 0x450);
    if (temp_16 != NULL) {
        *(u8 **)(temp_16 + 0x44C) = *(u8 **)(var_4 + 0x44C);
    }
    temp_3 = *(u8 **)(var_4 + 0x44C);
    if (temp_3 != NULL) {
        *(u8 **)(temp_3 + 0x450) = *(u8 **)(var_4 + 0x450);
    } else {
        *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_4 + 0x450);
    }
    (*jtbl_008873EC)(var_4);
    var_4 = temp_16;
loop_check:
    if (var_4 != NULL) goto loop_body;
}
/* measured: returning directly from the compare branch preserves retail's
   bne/branch-to-tail layout; the C object is 60B/64B with nd 0 and only the
   retail alignment nop remains. */
// FUN_001B0C80
u8 *func_001b0c80(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 0x30) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}
/* measured: 0cc0 shares the pointer-chain branch shape above; only its
   compare-field displacement changes, with nd 0 in a 60B/64B object. */
// FUN_001B0CC0
u8 *func_001b0cc0(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 8) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}
// FUN_001B0D70
s32 func_001b0d70(u8 *arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = (s32)arg0;
    return 1;
}
// FUN_001B0DD0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0dd0);
// FUN_001B0E30
s32 func_001b0e30(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x2CC);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = arg0;
    return 1;
}
/* measured: opt_rebuildconditionals off probe for 0e90 guard polarity. */
#pragma opt_rebuildconditionals off
// FUN_001B0E90
s32 func_001b0e90(u8 *arg0)
{
    s32 temp;
    u8 *p;

    if (*(u8 *)(arg0 + 0x28) != 0) {
        goto ret1;
    }
    if (*(u8 *)(arg0 + 0x29) == 0) {
        goto check;
    }
ret1:
    return 1;
check:
    p = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(p + 0xC) & 8) == 0) {
        return 1;
    }
    if ((*(u16 *)(arg0 + 0x18) & 4) == 0) {
        temp = *(s32 *)(p + 0x2CC);
        if ((temp != 0) && ((u8 *)temp == arg0)) {
            return 1;
        }
    }
    return *(s32 *)(p + 0x2A0) == (s32)arg0;
}
/* measured: close opt_rebuildconditionals off for func_001b0e90. */
#pragma opt_rebuildconditionals on
// FUN_001B0F20
s32 func_001b0f20(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto shift;
    }
    return 0;
shift:
    while ((s32)i > 0) {
        *p = *(p - 1);
        p--;
        i--;
    }
    *p = arg0;
    return 1;
}
// FUN_001B0FA0
s32 func_001b0fa0(u8 *arg0)
{
    s32 *p;
    u32 i;
    s32 temp;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == (s32)arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto limit;
    }
    return 0;
compact:
    temp = *(p + 1);
    if (temp == 0) {
        goto store;
    }
    *p = temp;
    p++;
    i++;
limit:
    if (i < 0xB) {
        goto compact;
    }
store:
    *p = (s32)arg0;
    return 1;
}
// FUN_001B1020
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1020);
// FUN_001B11C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b11c0);
// FUN_001B1280
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1280);
// FUN_001B13C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b13c0);
// FUN_001B1450
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1450);
// FUN_001B1510
s32 func_001b1510(void)
{
    s32 *var_4;
    u8 *temp_3;

    temp_3 = D_0076449C;
    var_4 = (s32 *)(temp_3 + 0x2CC);
    if (*(s32 *)(temp_3 + 0x2CC) == 0) {
        var_4 = (s32 *)(temp_3 + 0x29C);
    }
    return *var_4;
}
// FUN_001B1540
s32 func_001b1540(void)
{
    return *(s32 *)(iGpffffb3ac + 0x29C);
}
// FUN_001B1550
s32 func_001b1550(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2CC);
}
// FUN_001B1560
s32 func_001b1560(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2A0);
}
// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}



// FUN_001B15B0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b15b0);
// FUN_001B1800
void func_001b1800(void)
{
    u8 *temp_4;
    u8 *temp_4_2;

    temp_4 = D_0076449C;
    *(u16 *)(temp_4 + 0x290) |= 8;
    temp_4_2 = D_0076449C;
    *(u16 *)(temp_4_2 + 0x290) |= 1;
}
// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
}



// FUN_001B1850
void func_001b1850(void)
{
    func_0043f9c8(D_0076449C + 0x290, 0, 0x6C);
}
// FUN_001B1880
void func_001b1880(void)
{
    *(u16 *)(D_0076449C + 0x290) = 0;
    *(s32 *)(D_0076449C + 0x298) = 0;
    func_0043f9c8(D_0076449C + 0x2CC, 0, 0x30);
}
// FUN_001B18C0
void func_001b18c0(void)
{
}

// FUN_001B18D0
s32 func_001b18d0(void)
{
    return 0;
}

// FUN_001B18E0
void func_001b18e0(void) {
    func_001f7620(2, 0);
    func_001f7620(3, 0);
    func_001f7570(0);
    func_00106550(0x78, func_001064f0(0x78) + 1);
}

// FUN_001B1940
s32 func_001b1940(void) {
    u8 *b = D_0076449C;
    s32 off = *(u16 *)(b + 0xC6C) << 2;

    *(s32 *)(b + 0xC68) = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    *(u16 *)(b + 0xC6C) = *(u16 *)(b + 0xC6C) + 1;
    if (func_0022bd20() != 0) {
        func_0022bd60();
    }
    return 3;
}

// FUN_001B19A0
void func_001b19a0(void)
{
    func_001b6990();
}

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
#pragma opt_rebuildconditionals off
// FUN_001B19C0
s32 func_001b19c0(void)
{
    extern s32 func_001b6a00(void);
    extern u32 func_00193c70(void);
    extern void func_0014a2e0(u32 arg0);
    extern void func_001b6120(void);
    extern s32 func_00106330(s32 arg0);
    extern BtlPacket *func_001f9b80(u16 arg0);
    extern s64 func_00194590(u8 *arg0, u32 arg1);
    extern u8 *func_001f97b0(void);
    extern s32 func_0022bd20(void);
    extern u8 *func_002304b0(void);
    extern s32 func_00230790(void);
    extern u8 *func_002305c0(s32 arg0);
    extern s32 func_001ef9a0(void);
    extern void func_002aaa80(void);
    extern void func_001fc280(void);
    s32 var_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u8 *temp_2;
    u8 *temp_2_2;

    if (func_001b6a00() == 0) {
        goto done;
    }
    if (func_00193c70() != 0) {
        goto done;
    }
    func_0014a2e0(1);
    func_001b6120();
    if (func_00106330(0x38) == 0) {
        goto set_zero;
    }
    var_2 = 1;
    goto got_var;
set_zero:
    var_2 = 0;
got_var:
    temp_2 = (u8 *)func_001f9b80((u16)(var_2 & 0xFFFF));
    func_00194590(temp_2, 1);
    temp_2_2 = func_001f97b0();
    *(s8 *)(temp_2_2 + 0) = 4;
    *(s64 *)(temp_2_2 + 8) = *(s64 *)(temp_2 + 0x58);
    func_00194590(temp_2_2, 1);
    if (func_0022bd20() != 0) {
        func_00194590(func_002304b0(), 1);
        temp_2_3 = func_00230790();
        if (temp_2_3 != -1) {
            func_00194590(func_002305c0(temp_2_3), 1);
        }
    }
    temp_2_4 = func_001ef9a0();
    switch (temp_2_4) {
    case 0x20B:
    case 0x215:
        func_002aaa80();
        func_001fc280();
        break;
    }
    return 5;
done:
    return 0;
}
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
#pragma opt_rebuildconditionals on
// FUN_001B1B20
void func_001b1b20(void)
{
}
// FUN_001B1B30
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1b30);
// FUN_001B1D70
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1d70);
// FUN_001B2380
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b2380);
// FUN_001B33C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b33c0);
// FUN_001B36B0
s32 func_001b36b0(void)
{
    s32 temp3;
    u8 *temp4;
    u8 *var16;

    if (func_00193c70() == 0) {
        temp4 = D_0076449C;
        temp3 = *(s32 *)(temp4 + 0xC);
        if ((temp3 & 0x100000) == 0) {
            if ((temp3 & 0x20000000) == 0) {
                func_00194590((u8 *)func_001f5f70((u32)*(u8 **)(temp4 + 0x170), 0, 0, 0, 0), 1);
            }
            var16 = *(u8 **)(D_0076449C + 0x180);
            goto check;
loop:
            if ((*(s32 *)(var16 + 0x9C) & 8) != 0) {
                func_0019d040(var16);
            } else {
                func_0019d0c0(var16);
            }
            var16 = *(u8 **)(var16 + 0xA6C);
check:
            if (var16 != NULL) {
                goto loop;
            }
            return 7;
        }
    }
    return 0;
}
// FUN_001B3790
void func_001b3790(void)
{
    s32 temp2;
    u8 *var16;

    if ((*(s32 *)(D_0076449C + 0x10) & 1) == 0) {
        goto done;
    }
    temp2 = func_001ef9a0();
    switch (temp2) {
    case 0x20B:
    case 0x215:
        func_002aaaa0();
        break;
    default:
        break;
    }
    func_001fc230(3);
    if (func_001faaa0((u8 *)*(s32 *)(D_0076449C + 0x170)) == 0) {
        goto done;
    }
    if (func_00230210() == 0) {
        goto done;
    }
    var16 = *(u8 **)(D_0076449C + 0x17C);
    goto check;
loop:
    *(u16 *)(var16 + 0x9D8) = *(u16 *)(var16 + 0x9D8) | 0x40;
    func_00198920(var16, 0, 0, 1, 1.0f);
    var16 = *(u8 **)(var16 + 0xA68);
check:
    if (var16 != NULL) {
        goto loop;
    }
done:
    return;
}
/* measured: plain C candidate is 372 bytes in the 384-byte retail window with normalized_diff 11; residual is limited to the loop/call-tail schedule. */
// Committed at nd 11.
// FUN_001B3870
#ifdef NON_MATCHING
s32 func_001b3870(void)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *var_16;

    if (func_0021d470(*(s32 *)(D_0076449C + 0xDD4)) != 1) goto done;
    if (func_00193c70() != 0) goto done;
    if (func_001faaf0() != 0) goto done;
    if (func_001fab90() != 0) goto done;
    if (func_001fab40(*(u8 **)(D_0076449C + 0x170)) != 0) {
        return 0;
    }
    if (func_00230210() != 0) {
        var_16 = *(u8 **)(D_0076449C + 0x17C);
        goto check;
loop:
        *(u16 *)(var_16 + 0x9D8) &= 0xFFBF;
        func_00198dd0(var_16, 0);
        func_00198920(var_16, *(s16 *)(var_16 + 0x9EC), 8,
                      *(s8 *)(var_16 + 0x9F4), *(f32 *)(var_16 + 0x9F0));
        var_16 = *(u8 **)(var_16 + 0xA68);
check:
        if (var_16 != NULL) goto loop;
    }
    if (func_001eb860() == 1) {
        temp_3 = D_0076449C;
        *(s32 *)(temp_3 + 0xC) |= 0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
    } else {
        temp_4 = D_0076449C;
        *(s32 *)(temp_4 + 0xC) &= ~0x2000;
        func_001eb7f0(temp_4);
    }
    func_001b1800();
    temp_3_2 = D_0076449C;
    *(s32 *)(temp_3_2 + 0xC) |= 0x800;
    return 8;
done:
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3870);
#endif
// FUN_001B39F0
void func_001b39f0(void)
{
}

// FUN_001B3A00
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3a00);
// FUN_001B3F00
void func_001b3f00(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0(&D_005F7000);
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = func_001d3700(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    func_00194590(t, 0);
    func_00194590(btlCameraCreateSetStatePacket(NULL, 0x2B), 0);
}



// FUN_001B3FB0
s32 func_001b3fb0(void)
{
    func_002bbcc0();
    if (func_002bb600() == 0) {
        if (func_002bb140() == 0) {
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_002bb380();
            func_002bb4e0();
            return 10;
        }
        *(s32 *)(iGpffffb3ac + 0xC) &= 0xFF7FFFFF;
        func_002bb380();
        func_002bb4e0();
        return 8;
    }
    return 0;
}
// FUN_001B4060
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4060);
// FUN_001B4630
s32 func_001b4630(void)
{
    extern u8 *func_001bc920();
    s64 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = (s64 *)(*(u8 **)(D_0076449C + 0x170));
    if (func_00193bf0(*temp_16, (s64)0x3FFFFFFFFFFFFFFF) == 0) {
        func_00106620(0x31E, ((func_00106600(0x31E) & 0xFF) - 1) & 0xFF);
        func_001b1800();
        if (func_00193060() == 0) {
            temp_4 = D_0076449C;
            *(s32 *)(temp_4 + 0xC) &= ~0x80;
            if (func_001eb860() == 1) {
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            func_00194590(func_001bc920(temp_16, 0x24), 0);
        } else {
            temp_3 = D_0076449C;
            *(s32 *)(temp_3 + 0xC) |= 0x80;
            temp_4_2 = D_0076449C;
            *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
        }
        return 8;
    }
    return 0;
}
// FUN_001B4760
void func_001b4760(void)
{
    func_001fadc0((u8 *)*(s32 *)(D_0076449C + 0x170));
    *(s32 *)(D_0076449C + 0xC) |= 0x80000;
}
// FUN_001B47A0
s32 func_001b47a0(void)
{
    s32 var2;
    u8 *temp4;

    if (func_001fae10() == 0) {
        temp4 = D_0076449C;
        *(s32 *)(temp4 + 0xC) = *(s32 *)(temp4 + 0xC) & 0xFFF7FFFF;
        func_0045a9a0(2, 0);
        if ((*(s32 *)(D_0076449C + 0xC) & 0x400) == 0) {
            func_00122520(1, 0x1E);
            func_001228a0(0xFF, 0xFF, 0xFF);
        }
        if ((*(s32 *)(D_0076449C + 0xC) & 0x80) != 0) {
            var2 = 0xE;
        } else {
            var2 = 8;
        }
        return var2;
    }
    return 0;
}
// FUN_001B4860
s32 func_001b4860(s32 *arg0)
{
    return *arg0 != 0xB;
}
// FUN_001B4880
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4880);
// FUN_001B5300
s32 func_001b5300(u8 *arg0)
{
    u8 *p;
    u16 limit;
    s32 hit;

    p = arg0;
    if ((*(s32 *)(p + 8) > (*(u16 *)(p + 0xC) + *(u16 *)(p + 0xE))) &&
        (*(s32 *)(p + 0x14) == 0) &&
        ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) &&
        ((D_008C024C[0] & 0x10) != 0 ||
         (D_008C024E[0] & 0x40) != 0)) {
        u8 *work;

        work = (u8 *)func_001f60c0();
        *(u16 *)(work + 0x4A) = 0xC;
        func_00194590(work, 1);
        func_001f86d0();
        *(s32 *)(p + 0x14) = 1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0 &&
        (*(s32 *)(p + 8) == *(u16 *)(p + 0x12))) {
        func_00212100(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto after_cac;
    }
    limit = *(u16 *)(p + 0xC);
    hit = *(s32 *)(p + 8) < limit;
    if (hit != 0) {
        goto after_cac;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto after_cac;
    }
    if (*(s32 *)(p + 8) == limit) {
        func_00213990(*(s32 *)(iGpffffb3ac + 0xDD4));
        return 0;
    }
    if (func_002139d0(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
        return 0;
    }
after_cac:
    if ((u32)func_00193c70() < 3) {
        if (*(s32 *)(p + 0x14) == 0) {
            hit = *(s32 *)(p + 8);
            hit = hit < (*(u16 *)(p + 0xC) + *(u16 *)(p + 0x10));
            if (hit != 0) {
                goto return_zero;
            }
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
            return 0xE;
        }
        return 4;
    }
return_zero:
    return 0;
}
// FUN_001B54E0
void func_001b54e0(void)
{
    u8 *p;
    u8 *work;

    p = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    if ((func_002428f0(*(s32 *)(p + 0xA64), 0) != 0) &&
        ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0)) {
        work = func_001d6240((u32)*(s32 *)(iGpffffb3ac + 0xDBC), (u32)p, (u32)p, 1, 0);
        *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
        *(u16 *)(work + 0x48) = 0xF;
        func_00194590(work, 2);
        return;
    }
    work = func_00194b60();
    *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
    *(u16 *)(work + 0x48) = 0x2A;
    func_00194590(work, 1);
    func_00122520(1, 0x1E);
    switch (func_001ef9a0()) {
    case 0x214:
        func_001228a0(0, 0, 0);
        break;
    default:
        func_001228a0(0xFF, 0xFF, 0xFF);
        break;
    }
}
// FUN_001B5620
s32 func_001b5620(u8 *arg0)
{
    if ((*(s32 *)(arg0 + 8) == 0x6E) &&
        (func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0) != 0) &&
        ((*(s32 *)(D_0076449C + 0x10) & 0x20000000) == 0)) {
        func_00122520(1, 1);
        func_001228a0(0xFF, 0xFF, 0xFF);
    }
    if (func_00193bf0(*(s64 *)(*(u8 **)(D_0076449C + 0x170)),
                     (s64)0x3FFFFFFFFFFFFFFF) != 0) {
        return 0;
    }
    if (func_001f6290() != 0) {
        return 0;
    }
    return 0xE;
}
// FUN_001B5710
void func_001b5710(u8 *arg0)
{
s32 temp4;

    temp4 = *(s32 *)(D_0076449C + 0xC);
    temp4 = temp4 & ~0x800;
    *(s32 *)(D_0076449C + 0xC) = temp4;
    if (*(u16 *)(D_0076449C + 0x1C) == 2) {
        goto done;
    }
    temp4 = *(s32 *)(D_0076449C + 0xC);
    if ((temp4 & 0x400) == 0) {
        goto fallback;
    }
    if ((temp4 & 0x40) != 0) {
        if (func_00459760(temp4) != 7) {
            func_0045a3e0(7, 1);
        }
    }
    *(s32 *)func_00452560(*(s32 *)(D_0076449C + 0xDD0)) |= 1;
    *(s32 *)(arg0 + 0xC) = 0;
    goto done;
fallback:
    if ((*(u16 *)(D_0076449C + 0xCAC) & 1) == 0) {
        goto done;
    }
    if ((temp4 & 0x20000000) != 0) {
        goto done;
    }
    func_00213a10(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001B57F0
s32 func_001b57f0(u8 *arg0)
{
    if (*(u16 *)(iGpffffb3ac + 0x1C) == 2) {
        goto state_two;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x400) == 0) {
        goto no_four_hundred;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto check_status;
    }
    if (func_0021db10(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto check_status;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto set_status;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto set_status;
    }
    func_00213a10(*(s32 *)(iGpffffb3ac + 0xDD4));
set_status:
    *(s32 *)(arg0 + 0xC) = 1;
check_status:
    if (*(s32 *)(arg0 + 0xC) != 1) {
        goto return_zero;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto status_fallback;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto status_fallback;
    }
    if (func_00213a50(*(s32 *)(iGpffffb3ac + 0xDD4)) != 0) {
        goto status_fallback;
    }
    return 0;
status_fallback:
    if (func_0021db40(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto return_zero;
    }
    return 0xF;
no_four_hundred:
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two:
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0) {
        goto state_two_f;
    }
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two_f:
    return 0xF;
return_zero:
    return 0;
}
// FUN_001B5970
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5970);
// FUN_001B5D30
s32 func_001b5d30(void) {
    u8 *p;

    if (*(s32 *)(D_0076449C + 0x174) != 0) {
        return 0;
    }
    func_001b69c0();
    p = D_0076449C;
    if ((*(s32 *)(p + 0xC) & 0x400) != 0 &&
        *(u16 *)(p + 0x1C) != 2) {
        return 0x10;
    }
    return 0x11;
}

// FUN_001B5DA0
void func_001b5da0(void) {
}

// FUN_001B5DB0
s32 func_001b5db0(void)
{
    u8 *temp_3;

    if (*(s32 *)(func_00452560(*(s32 *)(iGpffffb3ac + 0xDD0)) + 4) != 0) {
        return 0;
    }
    func_00452080((KwlnTask *)*(s32 *)(iGpffffb3ac + 0xDD0));
    *(s32 *)(iGpffffb3ac + 0xDD0) = 0;
    temp_3 = (u8 *)iGpffffb3ac;
    if ((*(u8 *)(temp_3 + 0xC65) == 1) &&
        (*(s32 *)(temp_3 + 0xC) & 0x400)) {
        func_00122640(1, 0xC);
    }
    return 0x11;
}
// FUN_001B5E40
void func_001b5e40(void)
{
    func_00193d30();
}

// FUN_001B5EC0
void func_001b5ec0(void)
{
}

// FUN_001B5ED0
s32 func_001b5ed0(void)
{
    func_001fc1b0(0);
    return 2;
}
// FUN_001B5F00
void func_001b5f00(void)
{
    *(s32 *)(D_0076449C + 0xDCC) = func_002aa300(0, 0);
}
// FUN_001B5F30
s32 func_001b5f30(void)
{
    if (func_002aa3f0() != 0) {
        func_00192b20();
        return 0x12;
    }
    return 0;
}
// FUN_001B5F70
void func_001b5f70(s32 arg0)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = arg0;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
}


// FUN_001B5FD0
s32 func_001b5fd0(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2FC);
}
// FUN_001B5FE0
void func_001b5fe0(void)
{
    u8 *temp_2;
    s32 temp_3;

    if (*(s32 *)((u8 *)iGpffffb3ac + 0x300) != 0) {
        *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) =
            *(s32 *)((u8 *)iGpffffb3ac + 0x300);
        *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
        temp_2 = (u8 *)iGpffffb3ac;
        (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
            temp_2 + 0x2FC);
        *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    temp_3 = (*(s32 (**)(u8 *))(D_005F7184 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    if (temp_3 != 0) {
        temp_2 = (u8 *)iGpffffb3ac;
        *(s32 *)(temp_2 + 0x300) = temp_3;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    *(s32 *)(temp_2 + 0x304) = *(s32 *)(temp_2 + 0x304) + 1;
}
// FUN_001B60A0
void func_001b60a0(void)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = 1;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
}

// FUN_001B6110
void func_001b6110(void)
{
}

// FUN_001B6120
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b6120);
// FUN_001B68D0
/* measured: opt_propagation off probes the retail ordered second float load group. */
#pragma opt_propagation off
void func_001b68d0(void)
{
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    s32 value;

    a = *(f32 *)(D_0076449C + 0x270);
    b = *(f32 *)(D_0076449C + 0x274);
    c = *(f32 *)(D_0076449C + 0x278);
    d = *(f32 *)(D_0076449C + 0x27C);
    D_00922CA0[0] = a;
    D_00922CA4[0] = b;
    D_00922CA8[0] = c;
    D_00922CAC[0] = d;
    d = *(f32 *)(D_0076449C + 0x280);
    c = *(f32 *)(D_0076449C + 0x284);
    b = *(f32 *)(D_0076449C + 0x288);
    a = *(f32 *)(D_0076449C + 0x28C);
    D_00922CB0[0] = d;
    D_00922CB4[0] = c;
    D_00922CB8[0] = b;
    D_00922CBC[0] = a;
    D_00922CC0[0] = 1;
    *(s32 *)(D_0076449C + 0xE78) = 0;
    value = *(s32 *)(D_0076449C + 0xE7C);
    if (value != 0) {
        func_004833f0((void *)(u32)value);
        *(s32 *)(D_0076449C + 0xE7C) = 0;
    }
    func_00145080();
}
/* measured: closes opt_propagation probe for func_001b68d0. */
#pragma opt_propagation on
// FUN_001B6990
void func_001b6990(void)
{
    func_00144c90(*(u16 *)(D_0076449C + 0x26C),
                  *(u16 *)(D_0076449C + 0x26E));
}
// FUN_001B69C0
void func_001b69c0(void)
{
    u8 *p;

    *(s32 *)(D_0076449C + 0xE78) = 0;
    p = D_0076449C;
    *(s32 *)(p + 0xC) &= ~2;
    func_00145080(p);
}
// FUN_001B6A00
void func_001b6a00(void)
{
    func_00144f60();
}

// FUN_001B6A20
void func_001b6a20(void)
{
    struct P4Vec4 {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
    };
    u8 *base;
    struct P4Vec4 *dst;
    struct P4Vec4 *src;

    base = D_0076449C;
    if ((*(s32 *)(base + 0xC) & 2) != 0) {
        dst = (struct P4Vec4 *)func_0014acd0();
        src = (struct P4Vec4 *)(base + 0x1EC);
        *dst = *src;
        base = D_0076449C;
        dst = (struct P4Vec4 *)func_0014ad10();
        src = (struct P4Vec4 *)(base + 0x1FC);
        *dst = *src;
    }
}
// FUN_001B6AB0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b6ab0);
// FUN_001B7020
s32 func_001b7020(void)
{
    return iGpffffb3ac + 0x1BC;
}
// FUN_001B7030
s32 func_001b7030(void)
{
    return iGpffffb3ac + 0x1EC;
}
// FUN_001B7040
s32 func_001b7040(void)
{
    return iGpffffb3ac + 0x21C;
}
// FUN_001B7050
s32 func_001b7050(void)
{
    return iGpffffb3ac + 0x24C;
}

// FUN_001B7060
void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



// FUN_001B7080
s32 func_001b7080(void)
{
    return 0xFF808080;
}
// FUN_001B7090
s32 func_001b7090(void)
{
    return 0;
}

// FUN_001B70A0
void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



// FUN_001B70C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b70c0);
// FUN_001B73F0
void func_001b73f0(u8 *arg0)
{
    s32 index;
    u16 masked;
    u8 color[4];

    if (((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x400000) != 0) &&
        ((*(u16 *)((u8 *)iGpffffb3ac + 0x18) & 0x10) != 0)) {
        goto done;
    }
    if (arg0 != NULL) {
        color[0] = *(u8 *)(arg0 + 0x30);
        color[1] = *(u8 *)(arg0 + 0x31);
        color[2] = *(u8 *)(arg0 + 0x32);
        color[3] = 0xFF;
        func_00194f60(arg0, *(s32 *)color);
        goto done;
    }
    index = 0;
    goto outer_check;
outer_loop:
    masked = (u16)index;
    arg0 = *(u8 **)((u8 *)iGpffffb3ac + ((u32)masked << 3) + 0x178);
    goto inner_check;
inner_loop:
    if (*(u16 *)(arg0 + 0x9FE) == 0) goto next;
    if ((*(s32 *)(arg0 + 0x9C) & 1) != 0) goto next;
    color[0] = *(u8 *)(arg0 + 0x30);
    color[1] = *(u8 *)(arg0 + 0x31);
    color[2] = *(u8 *)(arg0 + 0x32);
    color[3] = 0xFF;
    func_00194f60(arg0, *(s32 *)color);
next:
    arg0 = *(u8 **)(arg0 + 0xA6C);
inner_check:
    if (arg0 != NULL) goto inner_loop;
    index = (index + 1) & 0xFFFF;
outer_check:
    if ((index & 0xFFFF) < 2) goto outer_loop;
done:
    ;
}
// FUN_001B7520
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b7520);
// FUN_001BA0E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001ba0e0);
// FUN_001BA530
void func_001ba530(s32 arg0, s32 arg1) {
    u8 *o = func_00194470(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = func_001ba0e0;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA590
s32 func_001ba590(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Ba590Vec3;
    typedef struct {
        Ba590Vec3 right;
        u32 flags;
        Ba590Vec3 up;
        u32 pad1;
        Ba590Vec3 at;
        u32 pad2;
        Ba590Vec3 pos;
        u32 pad3;
    } Ba590Matrix;
    Ba590Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    u32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *var_6;
    s32 var_5;
    u8 *var_2;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        var_2 = (u8 *)iGpffffb3ac;
        temp_f3 = *(f32 *)(var_2 + 0x20C);
        temp_f2 = *(f32 *)(var_2 + 0x210);
        temp_f1 = *(f32 *)(var_2 + 0x214);
        temp_f0 = *(f32 *)(var_2 + 0x218);
        *(f32 *)(arg0 + 0x10) = temp_f3;
        *(f32 *)(arg0 + 0x14) = temp_f2;
        *(f32 *)(arg0 + 0x18) = temp_f1;
        *(f32 *)(arg0 + 0x1C) = temp_f0;
    }
    temp_3 = *(s32 *)(arg0 + 0x24);
    if (temp_3 >= *(u32 *)(arg0 + 0x20)) {
    temp_f4 = *(f32 *)(arg0 + 4);
    temp_f12 = *(f32 *)(arg0 + 0);
    temp_f11 = *(f32 *)(arg0 + 8);
    temp_f3 = *(f32 *)(arg0 + 0xC);
    temp_f0 =
        2.0f / ((temp_f12 * temp_f12) +
                (temp_f4 * temp_f4) +
                (temp_f11 * temp_f11) +
                (temp_f3 * temp_f3));
    temp_f2 = temp_f12 * temp_f0;
    temp_f1 = temp_f4 * temp_f0;
    temp_f0_2 = temp_f11 * temp_f0;
    temp_f10 = temp_f2 * temp_f3;
    temp_f9 = temp_f1 * temp_f3;
    temp_f8 = temp_f0_2 * temp_f3;
    temp_f7 = temp_f12 * temp_f2;
    temp_f6 = temp_f4 * temp_f1;
    temp_f5 = temp_f11 * temp_f0_2;
    temp_f4_2 = temp_f4 * temp_f0_2;
    temp_f3_2 = temp_f11 * temp_f2;
    temp_f2_2 = temp_f12 * temp_f1;
    matrix.right.x = 1.0f - (temp_f6 + temp_f5);
    matrix.right.y = temp_f2_2 + temp_f8;
    matrix.right.z = temp_f3_2 - temp_f9;
    matrix.up.x = temp_f2_2 - temp_f8;
    matrix.up.y = 1.0f - (temp_f5 + temp_f7);
    matrix.up.z = temp_f4_2 + temp_f10;
    matrix.at.x = temp_f3_2 + temp_f9;
    matrix.at.y = temp_f4_2 - temp_f10;
    matrix.at.z = 1.0f - (temp_f7 + temp_f6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    var_2 = func_0014ad50();
    var_6 = (u8 *)&matrix;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_6 + 0);
        temp_3_2 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_5 -= 1;
        *(s32 *)(var_2 + 0) = temp_4;
        *(s32 *)(var_2 + 4) = temp_3_2;
        var_2 += 8;
    } while (var_5 > 0);
    return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_3 + 1;
    return 0;
}
// FUN_001BA710
void func_001ba710(f32 *arg0, s32 arg1) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *o = func_00194470(0x60A, 0x28);
    f32 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))func_001ba590;
    p = *(f32 **)(o + 0x78);
    value = *(struct F4 *)arg0;
    *(struct F4 *)p = value;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA790
void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0)
{
    struct Ba790Local {
        f32 f50;
        f32 f54;
        f32 f58;
        f32 f5C;
        f32 f60;
        f32 f64;
        f32 f68;
        f32 f6C;
        f32 f70;
        s32 flag;
    } local;
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    var_f20 = 1.0f - fparg0;
    temp_f5 = arg1[1] * var_f20;
    temp_f4 = arg1[2] * var_f20;
    temp_f3 = arg2[1] * fparg0;
    temp_f2 = arg2[2] * fparg0;
    arg0[0] = (arg1[0] * var_f20) + (arg2[0] * fparg0);
    arg0[1] = temp_f5 + temp_f3;
    arg0[2] = temp_f4 + temp_f2;
    func_003dcc70(arg1 + 3, arg2 + 3, &local.f50);
    if (fparg0 <= 0.0f) {
        temp_f3 = arg1[3];
        temp_f2 = arg1[4];
        temp_f1 = arg1[5];
        temp_f0 = arg1[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (1.0f <= fparg0) {
        temp_f3 = arg2[3];
        temp_f2 = arg2[4];
        temp_f1 = arg2[5];
        temp_f0 = arg2[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (local.flag == 0) {
        temp_f0 = var_f20 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        var_f20 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
        temp_f0 = fparg0 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        fparg0 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
    }
    arg0[3] = local.f50 * var_f20;
    arg0[4] = local.f54 * var_f20;
    arg0[5] = local.f58 * var_f20;
    arg0[3] = local.f60 * fparg0 + arg0[3];
    arg0[4] = local.f64 * fparg0 + arg0[4];
    arg0[5] = local.f68 * fparg0 + arg0[5];
    arg0[6] = local.f5C * var_f20 + local.f6C * fparg0;
done:
    ;
}
// FUN_001BBE80
void func_001bbe80(u8 *arg0, f32 fp) {
    func_001ec5e0(arg0 + 0x84, 60.0f * fp / 2.0f);
    *(u16 *)arg0 &= 0xFFF3;
    *(u16 *)arg0 |= 2;
}

// FUN_001BBF40
void func_001bbf40(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x84) = (f32) ((60.0f * fparg0) / 2.0f);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFD);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFB);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFF7);
}

// FUN_001BBF90
void func_001bbf90(u8 *arg0)
{
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f12;
    u16 temp_3;
    u8 *temp_2;

    temp_3 = *(u16 *)arg0;
    if ((temp_3 & 2) != 0) {
        var_f12 =
            func_001ec630(1.0f, (f32 *)(arg0 + 0x84)) -
            *(f32 *)(arg0 + 0x80);
    } else if ((temp_3 & 4) != 0) {
        temp_f2 = *(f32 *)(arg0 + 0x94);
        if (temp_f2 < fGpffff8430) {
            temp_f4 = temp_f2 + (1.0f / *(f32 *)(arg0 + 0x84));
            *(f32 *)(arg0 + 0x94) = temp_f4;
            temp_f2 = 0.0f + (-1.0f) +
                      ((-2.0f * temp_f4) * temp_f4) +
                      (4.0f * temp_f4);
            var_f12 =
                (2.0f * (temp_f2 - 0.5f)) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else if ((temp_3 & 8) != 0) {
        if (*(f32 *)(arg0 + 0x88) >
            (0.5f * *(f32 *)(arg0 + 0x84))) {
            var_f12 =
                func_001ba790_mul(func_001ec630(1.0f, (f32 *)(arg0 + 0x84)), 2.0f) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else {
        var_f12 = 1.0f / *(f32 *)(arg0 + 0x84);
    }
    *(f32 *)(arg0 + 0x80) =
        *(f32 *)(arg0 + 0x80) + var_f12;
    func_001bbd80(arg0, var_f12);
    temp_2 = D_0076449C;
    func_001bbc40(temp_2 + 0x24, (f32 *)(temp_2 + 0xC0),
                  (f32 *)(temp_2 + 0xCC));
}
// FUN_001BC140
s32 func_001bc140(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0xE0));
    if (temp_16 == NULL) {
        return 0;
    }
    if (func_00232710(*(s32 *)((u8 *)(*(u8 **)(temp_16 + 0x30)) + 0xA64), 0x60) != 0) {
        return 1;
    }
    return (s32)(func_001f0b90(temp_16) != 0);
}

// FUN_001BC1B0
s32 func_001bc1b0(u8 *arg0)
{
    typedef struct {
        u16 pad;
        u16 flags;
    } TableEntry;
    u8 *temp_2;
    u8 *temp_3;
    TableEntry *base;
    s32 index;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(*(u8 **)(temp_3 + 0x30) + 0xA0C);
    index = *(u16 *)(temp_3 + 0x6E);
    if ((temp_2 != NULL) &&
        (*(u16 *)(iGpffffb3e0 + (*(u16 *)(temp_2 + 0xA4) * 0x58)) & 1)) {
        return 0;
    }
    base = (TableEntry *)iGpffffb3bc;
    if ((base[index & 0xFFFF].flags & 0x10) != 0) {
        return 0;
    }
    return 1;
}
// FUN_001BC240
/* measured: opt_propagation off probe for bc240 table-address order. */
#pragma opt_propagation off
s32 func_001bc240(s32 arg0)
{
    s32 result;
    u8 *temp;
    u8 *base;

    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) != 0) {
        result = 1;
        goto done;
    }
    temp = *(u8 **)((u8 *)arg0 + 0xE0);
    arg0 = *(u16 *)(temp + 0x6E);
    temp = *(u8 **)(*(u8 **)(temp + 0x30) + 0xA0C);
    if ((temp != NULL) &&
        ((*(u16 *)(iGpffffb3e0 +
                   (*(u16 *)(temp + 0xA4) * 0x58))) & 1) != 0) {
        result = 0;
        goto check20;
    }
    base = iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x10) != 0) {
        result = 0;
        goto check20;
    }
    result = 1;
check20:
    if (result == 0) {
        goto final_zero;
    }
    base = iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x20) != 0) {
        result = 1;
        goto done;
    }
final_zero:
    result = 0;
done:
    return result;
}
/* measured: close opt_propagation probe for bc240. */
#pragma opt_propagation on
// FUN_001BC330
s32 func_001bc330(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xE0);
    if (ptr == NULL) {
        return 0;
    }
    if (func_001f2f90(ptr) == 0) {
        return 1;
    }
    return *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6C) == 3;
}



// FUN_001BC980
s32 func_001bc980(u8 *arg0)
{
    struct C980Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct C980Frame {
        f32 v30[4];
        u8 gap40[0x10];
        f32 v50[3];
        f32 v5C[4];
        f32 v6C[3];
        f32 v78[4];
        u8 tail[8];
    } frame;
    s32 temp_17;
    u8 *temp_3;
    u8 *temp_3_2;

    func_001bc660(1, *(s32 *)(arg0 + 0), 1);
    if (*(s32 *)(arg0 + 0x40) != 0) {
        func_001bd560(frame.v50, (f32 *)(D_0076449C + 0xC0));
    } else {
        func_001bd780(frame.v5C, arg0 + 4, arg0 + 0x10, D_0060A0E0);
        *(struct C980Vec3 *)frame.v50 =
            *(struct C980Vec3 *)(arg0 + 4);
    }
    func_001bd780(frame.v78, arg0 + 0x1C, arg0 + 0x28, D_0060A0E0);
    *(struct C980Vec3 *)frame.v6C =
        *(struct C980Vec3 *)(arg0 + 0x1C);
    temp_3 = D_0076449C;
    temp_17 = (s32)(temp_3 + 0x24);
    *(u16 *)(temp_3 + 0x24) = 1;
    *(s16 *)(temp_3 + 0x98) = 0;
    *(s16 *)(temp_3 + 0x9A) = 0;
    *(s16 *)(temp_3 + 0x9C) = 0;
    *(s32 *)(temp_3 + 0xA4) = 0;
    *(s32 *)(temp_3 + 0xA0) = 0;
    func_001ba9e0((u16 *)temp_17, frame.v50, frame.v5C);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff82f8);
    func_001ba9e0((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff80c8);
    func_001ba9e0((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba9e0((u16 *)temp_17, frame.v6C, frame.v78);
    temp_3_2 = D_0076449C;
    *(f32 *)(temp_3_2 + 0xA8) =
        (60.0f * (2.0f * *(f32 *)(arg0 + 0x3C))) / 2.0f;
    *(s32 *)(temp_3_2 + 0xB8) = 0x3F000000;
    *(u16 *)(temp_3_2 + 0x24) &= 0xFFF5;
    *(u16 *)(temp_3_2 + 0x24) |= 4;
    return 1;
}
// FUN_001BCB50
u8 *func_001bcb50(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0,
                  u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2)
{
    struct Bcb50Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_2;
    u8 *temp_4;

    temp_2 = (u8 *)(func_00194470(0x201, 0x44));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) =
        (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bc980));
    temp_4 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_4 + 0) = arg0;
    *(f32 *)(temp_4 + 0x3C) = fparg2;
    if ((arg1 != NULL) && (arg2 != NULL)) {
        *(struct Bcb50Vec3 *)(temp_4 + 4) =
            *(struct Bcb50Vec3 *)arg1;
        *(struct Bcb50Vec3 *)(temp_4 + 0x10) =
            *(struct Bcb50Vec3 *)arg2;
        *(s32 *)(temp_4 + 0x40) = 0;
    } else {
        *(s32 *)(temp_4 + 0x40) = 1;
    }
    *(struct Bcb50Vec3 *)(temp_4 + 0x1C) =
        *(struct Bcb50Vec3 *)arg3;
    *(struct Bcb50Vec3 *)(temp_4 + 0x28) =
        *(struct Bcb50Vec3 *)arg4;
    *(f32 *)(temp_4 + 0x34) = fparg0;
    *(f32 *)(temp_4 + 0x38) = fparg1;
    return temp_2;
}
// FUN_001BCC80
s32 func_001bcc80(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}



// FUN_001BCCC0
void func_001bccc0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)(func_00194470(0x202, 0x10));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) = (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bcc80));
    temp_3 = (u8 *)(*(u8 **)(temp_2 + 0x78));
    *(s32 *)(temp_3 + 0) = arg0;
    *(s16 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = arg2;
    *(s32 *)(temp_3 + 0xC) = arg3;
}

// FUN_001BCD40
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bcd40);
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
#pragma opt_propagation off
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
#pragma opt_common_subs off
// FUN_001BD300
void func_001bd300(void)
{
    s32 var_16;
    s32 index;
    u8 *var_17;

    var_16 = 0;
    goto outer_check;
outer_body:
    index = var_16 & 0xFFFF;
    var_17 = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    func_00194fc0(var_17, 0xF);
    var_17 = *(u8 **)(var_17 + 0xA6C);
inner_check:
    if (var_17 != NULL) goto inner_body;
    var_16 = (var_16 + 1) & 0xFFFF;
outer_check:
    if ((var_16 & 0xFFFF) < 2) goto outer_body;
}
/* measured: closes opt_common_subs for the following translation-unit code. */
#pragma opt_common_subs on
/* measured: closes opt_propagation for the following translation-unit code. */
#pragma opt_propagation on
// FUN_001BD390
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bd390);
// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}



// FUN_001BD530
void func_001bd530(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}



// FUN_001BD560
void func_001bd560(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5A0
void func_001bd5a0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5E0
void func_001bd5e0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD7D0
void func_001bd7d0(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Bd7Vec3;
    typedef struct {
        Bd7Vec3 right;
        u32 flags;
        Bd7Vec3 up;
        u32 pad1;
        Bd7Vec3 at;
        u32 pad2;
        Bd7Vec3 pos;
        u32 pad3;
    } Bd7Matrix;
    Bd7Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    void (*callback)(u8 *arg0);
    s32 temp_2;
    u16 temp_16;
    u8 *temp_6;
    u8 *temp_7;

    if ((*(s32 *)(D_0076449C + 0xF8) & 1) == 0) {
        temp_2 = *(s32 *)(D_0076449C + 0x100);
        if (temp_2 <= 0) {
            temp_16 = *(u16 *)(D_0076449C + 0xF4);
            temp_7 = func_0022cdb0(temp_16);
            if (temp_7 == NULL) {
                temp_7 = D_005F74C0 + ((temp_16 & 0xFFFF) * 0x14);
            }
            callback = *(void (**)(u8 *))(temp_7 + 4);
            if (callback != NULL) {
                callback(D_0076449C + 0x24);
            }
            func_001bbf90(D_0076449C + 0x24);
            *(s32 *)(D_0076449C + 0xFC) =
                *(s32 *)(D_0076449C + 0xFC) + 1;
        } else {
            *(s32 *)(D_0076449C + 0x100) = temp_2 - 1;
        }
        temp_f4 = *(f32 *)(D_0076449C + 0xD0);
        temp_f12 = *(f32 *)(D_0076449C + 0xCC);
        temp_f11 = *(f32 *)(D_0076449C + 0xD4);
        temp_f3 = *(f32 *)(D_0076449C + 0xD8);
        temp_f0 =
            2.0f / ((temp_f12 * temp_f12) +
                    (temp_f4 * temp_f4) +
                    (temp_f11 * temp_f11) +
                    (temp_f3 * temp_f3));
        temp_f2 = temp_f12 * temp_f0;
        temp_f1 = temp_f4 * temp_f0;
        temp_f0_2 = temp_f11 * temp_f0;
        temp_f10 = temp_f2 * temp_f3;
        temp_f9 = temp_f1 * temp_f3;
        temp_f8 = temp_f0_2 * temp_f3;
        temp_f7 = temp_f12 * temp_f2;
        temp_f6 = temp_f4 * temp_f1;
        temp_f5 = temp_f11 * temp_f0_2;
        temp_f4_2 = temp_f4 * temp_f0_2;
        temp_f3_2 = temp_f11 * temp_f2;
        temp_f2_2 = temp_f12 * temp_f1;
        matrix.right.x = 1.0f - (temp_f6 + temp_f5);
        matrix.right.y = temp_f2_2 + temp_f8;
        matrix.right.z = temp_f3_2 - temp_f9;
        matrix.up.x = temp_f2_2 - temp_f8;
        matrix.up.y = 1.0f - (temp_f5 + temp_f7);
        matrix.up.z = temp_f4_2 + temp_f10;
        matrix.at.x = temp_f3_2 + temp_f9;
        matrix.at.y = temp_f4_2 - temp_f10;
        matrix.at.z = 1.0f - (temp_f7 + temp_f6);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;
        matrix.pos = *(Bd7Vec3 *)(D_0076449C + 0xC0);
        temp_6 = func_00457120();
        func_003e9cb0(*(u8 **)(temp_6 + 4), &matrix, 0);
        func_004577d0(func_00457120(),
                      fGpffff8048 * *(f32 *)(D_0076449C + 0xDC));
    }
    if ((*(s32 *)(D_0076449C + 0xF8) & 2) != 0) {
        func_001bd390();
    }
}
/* measured: plain C candidate is 380 bytes in the 384-byte retail window with normalized_diff 6; residual is limited to the global-position load order and one retail tail padding word. */
// Committed at nd 6.
// FUN_001BD9E0
void func_001bd9e0(void)
{
  typedef struct 
  {
    f32 x;
    f32 y;
    f32 z;
  } Bd9Vec3;
  typedef struct 
  {
    Bd9Vec3 right;
    u32 flags;
    Bd9Vec3 up;
    u32 pad1;
    Bd9Vec3 at;
    u32 pad2;
    Bd9Vec3 pos;
    u32 pad3;
  } Bd9Matrix;
  u8 color[4];
  Bd9Matrix matrix;
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f10;
  f32 temp_f11;
  f32 temp_f12;
  f32 temp_f1;
  f32 temp_f2;
  f32 temp_f2_2;
  f32 temp_f3;
  f32 temp_f3_2;
  f32 temp_f4;
  f32 temp_f4_2;
  f32 temp_f5;
  f32 temp_f6;
  f32 temp_f7;
  f32 temp_f8;
  f32 temp_f9;
  s32 temp_4;
  u8 *temp_5;
  u8 *temp_6;
  temp_5 = D_0076449C;
  if (((*((s32 *) (temp_5 + 0xC))) & 4) == 0)
  {
    temp_4 = *((s32 *) (temp_5 + 0x14));
    if (((temp_4 & 4) == 0) && ((temp_4 & 8) != 0))
    {
      color[0] = 0xFF;
      color[1] = 0xFF;
      color[2] = 0;
      color[3] = 0xFF;
      temp_f4 = *((f32 *) (temp_5 + 0xD0));
      temp_f12 = *((f32 *) (temp_5 + 0xCC));
      temp_f11 = *((f32 *) (temp_5 + 0xD4));
      temp_f3 = *((f32 *) (temp_5 + 0xD8));
      temp_f0 = 2.0f / ((((temp_f12 * temp_f12) + (temp_f4 * temp_f4)) + (temp_f11 * temp_f11)) + (temp_f3 * temp_f3));
      temp_f2 = temp_f12 * temp_f0;
      temp_f1 = temp_f4 * temp_f0;
      temp_f0_2 = temp_f11 * temp_f0;
      temp_f10 = temp_f2 * temp_f3;
      temp_f9 = temp_f1 * temp_f3;
      temp_f8 = temp_f0_2 * temp_f3;
      temp_f7 = temp_f12 * temp_f2;
      temp_f6 = temp_f4 * temp_f1;
      temp_f5 = temp_f11 * temp_f0_2;
      temp_f4_2 = temp_f4 * temp_f0_2;
      temp_f3_2 = temp_f11 * temp_f2;
      temp_f2_2 = temp_f12 * temp_f1;
      if (((!temp_f3) && (!temp_f3)) && (!temp_f3))
      {
      }
      matrix.right.x = 1.0f - (temp_f6 + temp_f5);
      matrix.right.y = temp_f2_2 + temp_f8;
      matrix.right.z = temp_f3_2 - temp_f9;
      matrix.up.x = temp_f2_2 - temp_f8;
      matrix.up.y = 1.0f - (temp_f5 + temp_f7);
      matrix.up.z = temp_f4_2 + temp_f10;
      matrix.at.x = temp_f3_2 + temp_f9;
      matrix.at.y = temp_f4_2 - temp_f10;
      matrix.at.z = 1.0f - (temp_f7 + temp_f6);
      matrix.pos.x = 0.0f;
      matrix.pos.y = 0.0f;
      matrix.pos.z = 0.0f;
      matrix.flags = 3;
      temp_6 = temp_5 + 0xC0;
      temp_f2 = *((f32 *) temp_6);
      temp_f1 = *((f32 *) (temp_6 + 4));
      temp_f0 = *((f32 *) (temp_6 + 8));
      matrix.pos.x = temp_f2;
      matrix.pos.y = temp_f1;
      matrix.pos.z = temp_f0;
      func_0045f0b0((f32 *) temp_6, color, 1, 6.0f);
      func_0045fa00((f32 *) (&matrix), 1, 150.0f);
    }
  }
}
// FUN_001BDB60
void func_001bdb60(void)
{
    s32 temp_2;
    s32 var_4;
    u16 temp_4;
    u8 *temp_3;
    u8 *temp_3_2;

    func_003e8180(func_00457120(), 35.0f);
    func_004577d0(func_00457120(), 40.0f);
    {
        u8 *base;

        base = D_0076449C;
        temp_3 = base + 0x24;
        *(s16 *)(base + 0x24) = 1;
        *(s16 *)(base + 0x98) = 0;
        *(s16 *)(base + 0x9A) = 0;
        *(s16 *)(base + 0x9C) = 0;
        *(s32 *)(base + 0xA4) = 0;
        *(s32 *)(base + 0xA0) = 0;
    }
    func_0044ea90(&D_005F72B0, 0x3A);
    temp_3_2 = temp_3;
    temp_2 = (s32)(*jtbl_008873E8)(0x30, 0x40000);
    func_0043f9c8((void *)temp_2, 0, 0x30);
    *(s32 *)(temp_3_2 + 0x98) = func_003bbbe0(4, 1, (void *)temp_2);
    (*jtbl_008873EC)((u8 *)temp_2);
    func_00457120();
    *(f32 *)(D_0076449C + 0xD8) = fGpffff8314;
    *(f32 *)(D_0076449C + 0xCC) = fGpffff8318;
    *(f32 *)(D_0076449C + 0xD0) = fGpffff831c;
    *(f32 *)(D_0076449C + 0xD4) = fGpffff8320;
    *(f32 *)(D_0076449C + 0xC0) = fGpffff8324;
    *(f32 *)(D_0076449C + 0xC4) = fGpffff8328;
    *(f32 *)(D_0076449C + 0xC8) = fGpffff832c;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
    *(s16 *)(D_0076449C + 0xF4) = 0;
    *(s16 *)(D_0076449C + 0x10E) = 0;
    var_4 = 0;
    goto loop_test;
loop_body:
    temp_4 = var_4;
    *(s16 *)(D_0076449C + (temp_4 * 2) + 0x108) = 0;
    var_4 = (var_4 + 1) & 0xFFFF;
loop_test:
    if ((var_4 & 0xFFFF) < 3) {
        goto loop_body;
    }
    *(s32 *)(D_0076449C + 0xF8) |= 2;
    func_001d12e0(D_0076449C + 0x110);
}
// FUN_001BDD30
void func_001bdd30(void)
{
    s32 temp_4;

    temp_4 = *(s32 *)(D_0076449C + 0xBC);
    if (temp_4 != 0) {
        func_003bbb60((u8 *)temp_4);
    }
}
// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}

/* measured: opt_propagation off probe for bdd80 nd28 float scheduling. */
#pragma opt_propagation off
// FUN_001BDD80
void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 var_7;
    u16 temp_16;
    f32 temp_f12;
    u8 *temp_2;
    u8 *temp_5;

    *(s32 *)(arg0 + 0x134) = *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38);
    *(u16 *)(arg0 + 0x140) = *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A);
    temp_5 = *(u8 **)(arg0 + 0xE0);
    temp_16 = (u16)arg2;
    temp_16 = temp_16 | 1;
    func_001d10f0(arg0 + 0xEC, (s32)temp_5, *(s32 *)(temp_5 + 0x38), arg1,
                  temp_16);
    *(u16 *)(arg0 + 0x142) = *(u8 *)(arg1 + 1);
    temp_2 = func_001d1200(arg0 + 0xEC);
    if (temp_2 != NULL) {
        if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
            ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 1, 0.0f);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 8, 0.0f);
            *(s32 *)(arg0 + 0x138) = 1;
        } else {
            temp_f12 = 0.0f;
            if ((*(u16 *)(arg0 + 0x142) & 4) != 0) {
                var_7 = 0x18;
            } else {
                var_7 = 0xA;
            }
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, var_7,
                          temp_f12);
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
    *(s32 *)(arg0 + 0x13C) = 0;
}
/* measured: close opt_propagation probe for bdd80. */
#pragma opt_propagation on
// FUN_001BDEB0
void func_001bdeb0(u8 *arg0)
{
    s32 temp_16;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == *(u16 *)(arg0 + 0x140)) &&
        (temp_4 = *(u8 **)(arg0 + 0x134), temp_4 != NULL) &&
        (temp_4 == *(u8 **)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_001d10d0(arg0 + 0xEC, temp_5) != 0) {
            func_001d07e0(arg0, arg0 + 0xEC);
        }
        temp_2 = func_001d1200(arg0 + 0xEC);
        if (temp_2 != NULL) {
            if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
                ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
                if (*(s32 *)(arg0 + 0x13C) != 0) {
                    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x201, 0.0f);
                }
                *(s32 *)(arg0 + 0x138) = 1;
                return;
            }
            if (*(s32 *)(arg0 + 0x138) == 1) {
                var_2 = 3;
            } else {
                var_2 = 0xC3;
            }
            temp_16 = var_2 & 0xFFFF;
            if (*(s32 *)(arg0 + 0x13C) == 0) {
                if (func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 0xA64),
                                  0) == 0) {
                    func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C,
                                  (f32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 4),
                                  temp_16, 50.0f);
                }
            } else {
                func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, temp_16, 0.0f);
            }
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
}
// FUN_001BE050
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001be050);
// FUN_001BE900
void func_001be900(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0xC1,
                      0.5f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)));
    }
}
// FUN_001BE990
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001be990);
// FUN_001BF3A0
void func_001bf3a0(u8 *arg0)
{
    u8 *var_3;
    u16 temp_16;
    u8 *temp_17;

    switch (*(u16 *)(D_0076449C + 0x108)) {
    case 0x22:
        var_3 = 0;
        goto first_done;
    default:
        goto first_random;
    }
first_random:
    if (func_00231d70(0x64) <= 0x19) goto first_random_zero;
    var_3 = (u8 *)func_001be990(arg0, 0, 0x23, 0x3C);
    goto first_done;
first_random_zero:
    var_3 = 0;
first_done:
    if (var_3 != NULL) goto done;
    if (func_00231d70(0x64) <= 0x19) goto second_random;
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    func_001b73f0(temp_17);
    func_001bdd80(arg0,
                  func_001bf3a0_add((func_004bd050(0) & 1) * 0xF4,
                                    (u8 *)((s32)D_005FB400 +
                                           ((temp_16 & 0xFFFF) * 0x1E8))),
                  2);
    func_001b73f0(temp_17);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 1, 0.0f);
    *(s32 *)(arg0 + 0x144) = 1;
    goto finish;
second_random:
    func_001be990(arg0, 1, 0x23, 0x3C);
    *(s32 *)(arg0 + 0x144) = 0;
    goto finish;
done:
    *(s32 *)(arg0 + 0x144) = 0;
finish:
    ;
}
// FUN_001BF530
void func_001bf530(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    if (*(s32 *)(arg0 + 0x144) == 0) goto process;
    func_001bdeb0(arg0);
    goto done;
process:
    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0xC1,
                      0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)));
    }
done:
    ;
}
// FUN_001BF5E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bf5e0);
// FUN_001BFB70
void func_001bfb70(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0xC3,
                      0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)));
    }
}
// FUN_001BFC00
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bfc00);
// FUN_001C04D0
void func_001c04d0(void)
{
}