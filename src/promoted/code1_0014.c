#include "include_asm.h"
#include "type.h"
typedef struct {
    f32 x;
    f32 y;
} Float2_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0[3];
    f32 scale;
    f32 pad1;
    u32 color[4];
    u32 pad2[4];
} Quad_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[0x14];
    u32 color[3];
    f32 scale;
    u8 pad1[0x10];
} Packet_0014;
typedef struct {
    u8 pad[0x40];
    u8 arg0[8];
    u8 arg1[8];
    Packet_0014 packet[4];
} Frame_0014;

extern u8 D_005EDA20[];
extern u8 D_005EDEA0[];
extern u8 D_005EE320[];
extern u8 D_005EE7A0[];
extern u8 D_005EEC20[];
extern u8 D_005EF0A0[];
extern u8 D_005EF530[];
extern u8 D_005EF540[];
extern u8 D_005EF548[];
extern u8 D_005EF6C8[];
extern f32 fGpffff8110;
extern void func_00355070(u8 *arg0, u8 *arg1);
extern void func_003550d0(u8 *arg0, Float2_0014 *arg1, Float2_0014 *arg2);
extern void func_003552d0(u8 *arg0, Float2_0014 arg1);
extern void func_00355300(u8 *arg0, s32 arg1);
extern void func_00355370(u8 *arg0, u8 *arg1);



extern void func_0046d280(s32 arg0);
extern void func_00452080(s32 arg0);
extern void func_00146630(u16 arg0);
extern void func_001470e0(u8 *arg0);
extern u8 *func_00147500(u8 *arg0, s32 arg1);
extern void func_0015cc40(void);
extern void func_0015cf10(void);
extern void func_00160180(void);
extern void func_003e1a70(void);
extern void func_00451b70(void);
extern void func_0014eed0(s32 arg0, s32 arg1);
extern void func_0014efc0(s32 arg0, s32 arg1);
extern s32 func_0014f310(s32 arg0, s32 arg1);
extern s32 func_0026df80(void);
extern u8 *func_00147190(s32 arg0, s32 arg1);
extern u8 *func_00147530(u8 *arg0, u16 arg1);
extern void func_0015f720(u8 *arg0, const u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern u8 *func_003e0f80(void);
extern void func_0043f810(void *dest, const void *src, s32 size);
extern void func_00147430();
extern void func_00151f80(void *arg0);
extern void func_00268b20(void *arg0);
extern void func_003bbb60(s32 arg0);
extern void func_003e0f40(s32 arg0);
extern u8 D_005EF890[];
extern u8 D_005EF8B0[];
extern u8 D_005EF8D0[];
extern u8 D_005EF8F0[];
extern u8 D_005EF910[];
extern u8 D_005EF930[];
extern u8 D_005EF950[];
extern u8 D_005EF970[];
extern u8 D_005EF820[];
extern u8 D_005EF870[];
extern void func_0046d730(const void *arg0, s32 arg1);
extern void func_0047a180();
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void func_004b1150(s32 arg0);
extern s32 func_004782b0(s32 arg0);
extern void func_004787e0(s32 arg0);
extern s32 func_00104c70(s32 arg0);
extern u8 D_007EF9B0[];
extern void func_003c38b0(void *arg0, void *arg1);
extern void func_003e8110(void *arg0);
extern void func_003e8120(void *arg0);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern u8 *func_00457120(void);
extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);
extern u8 *func_00457190(void);
extern void func_003cbe80(void *arg0, void *arg1);
extern u8 *func_00149ca0(void);
extern u8 D_007E8020[];
extern u8 *func_0047a2f0(s32 arg0);
extern f32 func_003e4180(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern s32 func_0014c240(void *arg0, void *arg1, f32 fparg0, f32 fparg1);

extern s32 func_0014a230(s32 arg0, s32 arg1);
extern s32 func_0014a2a0(s32 arg0, s32 arg1);
extern void func_00440b68();
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern s32 func_00153a60(s32 arg0);
extern s32 func_00147070(void);
extern s32 func_001458b0(s32 arg0);
extern void func_0014ad90(void);
extern s32 func_00145930(s32 arg0);
extern void func_0014b1e0(void);
extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern s32 func_003cbf30(s32 arg0, void *arg1);
extern u8 *func_00149ce0(void);
extern u8 *func_00149d20(void);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
extern void func_00364c50();
extern void func_00364c70(void);
extern u16 D_008C024E[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern void func_00145080(void);
extern u8 * iGpffff9db0;
extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, s64 arg4, s64 arg5,
                          s32 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 D_00762EA0;

extern s32 func_00145540(u16 arg0, s32 arg1, s32 arg2);
extern s32 func_004b1130(s32 arg0);
extern void func_004b1170(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_004b1250(s32 arg0, u8 *arg1);
extern s32 func_001684a0(s32 arg0, s32 arg1, s32 arg2, f32 fparg0);
extern s32 func_0017b510(s32 arg0, s32 arg1, s32 arg2);
extern void func_004b13d0(s32 arg0, f32 arg1);

extern s32 D_007642E4;
extern u8 D_005EFB10[];
extern void func_00148280(void);
extern void func_0017ccc0(u8 *arg0);
extern u8 *func_00451fc0(u8 *a, void *b, s32 c, s32 d, s32 e, void *f, void *g, void *h);

static inline u8 *p4_e740_add(s32 offset, u8 *base) {
    return (u8 *)(offset + (u32)base);
}
static inline f32 p4_0014_recip(f32 value)
{
    return 1.0f / value;
}
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;
typedef struct { f32 x, y, z; } SVec3;
typedef struct { u8 c[4]; } Rgba8_0014;

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;



extern u8 *func_00460990(void);
extern void func_00460ac0(void *arg0, u8 *arg1);
extern void func_0014d290(u8 *arg0, u8 *arg1);

extern s32 func_0034c210(void);
extern void func_0013fb50(u8 *arg0);
extern s32 func_0013ff80(u8 *arg0);
extern s32 func_00142340(u8 *arg0);
extern void func_001422b0(u8 *arg0);
extern void func_00142230(u8 *arg0);
extern s32 func_0034bb20(s32 arg0);
extern void func_0034bd60(s32 arg0);
extern void func_00353fb0(void);
extern void func_00353fe0(void);
extern s32 func_00354030(void);
extern void func_00355190(u8 *arg0, u16 arg1);
extern void func_003671d0(void *arg0);
extern void func_003672d0(void *arg0, s16 pcId);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00142d80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern u8 *func_001452b0(s32 arg0);
extern u8 *resrcMngGetListHead(u8 *resManager, u8 resType);
extern void func_00153b20(s32 arg0, s32 arg1);

extern void func_00153b60(s32 arg0, s32 arg1);

extern void func_00153b90(s32 arg0, s32 arg1);

extern void func_00153bd0(s32 arg0, s32 arg1);
extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007D24B0[];
extern void func_0034f5d0(u8 *arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern void func_0044ea90(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern s32 func_0014e2a0(u8 *arg0);
extern void func_0014e540(u8 *arg0);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c,
                         void *init, void *close, void *buf);
extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern void func_001441e0(u8 *arg0);
extern void func_00144ac0(u8 *arg0);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442088(void *arg0, const char *arg1, ...);
extern void func_00442428(void *arg0, const void *arg1);
extern s32 func_00454570(void *arg0);
extern u8 D_005EF7C0[];
extern u8 iGpffff9db8;
extern u8 iGpffff9dc0;
extern u8 iGpffff9dc8;
extern s32 func_00168ec0(void *arg0, void *arg1, void *arg2);
typedef union {
    s64 bits;
    Float2_0014 values;
} NormalXY0014;
extern NormalXY0014 D_005EFB98[];
extern f32 D_005EFBA0[];
static inline u8 *p4_00141cf0_add(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}



// FUN_001400F0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001400f0);
// FUN_00141CF0
s32 func_00141cf0(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *temp_3;

    temp_3 = p4_00141cf0_add((u32)(arg1 * 2), arg0);
    *(s16 *)(temp_3 + 0x36) = *(s16 *)(temp_3 + 0x34);
    *(s16 *)(temp_3 + 0x34) = arg2;
    return 1;
}
// FUN_00141D10
void func_00141d10(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0xFA0);
    }
}
/* measured: opt_loop_invariants on hoists the shared float conversion constants in func_00141d80. */
#pragma opt_loop_invariants on
// FUN_00141D80
s32 func_00141d80(u8 *arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;

    table = NULL;
    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = arg0 + i * 0x30;
        *(f32 *)(dst + 0x40) = *(f32 *)(dst + 0x50);
        *(f32 *)(dst + 0x44) = *(f32 *)(dst + 0x54);
        *(u16 *)(dst + 0x5C) = *(u16 *)(dst + 0x60);
        *(u16 *)(dst + 0x62) = *(u16 *)(dst + 0x66);
        *(u8 *)(dst + 0x58) = *(u8 *)(dst + 0x5A);
    }
    switch (arg1) {
    case 0:
        table = D_005EDA20;
        *(s32 *)(arg0 + 0x1C) = 0x149;
        *(s16 *)(arg0 + 0x38) = 0;
        break;
    case 1:
        table = D_005EDEA0;
        break;
    case 2:
        table = D_005EE320;
        *(s32 *)(arg0 + 0x1C) = 0x949;
        *(s16 *)(arg0 + 0x38) = 0;
        break;
    case 3:
        table = D_005EE7A0;
        *(s32 *)(arg0 + 0x1C) = 0xBDB;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg0 + 0x34) * 2), arg0) + 0x22) == 1) {
            *(s16 *)(arg0 + 0x38) = 6;
        } else {
            *(s16 *)(arg0 + 0x38) = 5;
        }
        break;
    case 4:
        table = D_005EEC20;
        *(s32 *)(arg0 + 0x1C) = 0xED2;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg0 + 0x34) * 2), arg0) + 0x22) == 1) {
            *(s16 *)(arg0 + 0x38) = 6;
        } else {
            *(s16 *)(arg0 + 0x38) = 5;
        }
        break;
    case 5:
        table = D_005EF0A0;
        *(s32 *)(arg0 + 0x1C) = 0xAF6;
        *(s16 *)(arg0 + 0x38) = 7;
        break;
    case 6:
        *(s32 *)(arg0 + 0x1C) = 0x874;
        *(s16 *)(arg0 + 0x38) = 7;
        break;
    default:
        func_0046d730(&D_005EF6C8, 0x425);
        break;
    }
    if (table != NULL) {
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0x48) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x4C) = *(f32 *)(src + 4);
            *(u16 *)(dst + 0x5E) = (u16)*(f32 *)(src + 8);
            *(u16 *)(dst + 0x64) = (u16)*(f32 *)(src + 0xC);
            *(u8 *)(dst + 0x59) = *(u8 *)(src + 0x10);
            *(s32 *)(dst + 0x68) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x6C) = *(s32 *)(src + 0x18);
        }
        *(s32 *)(arg0 + 0x18) = arg1;
        *(s16 *)(arg0 + 0x20) = 0;
    }
    return 1;
}
/* measured: restore loop-invariant hoisting after func_00141d80. */
#pragma opt_loop_invariants off
/* measured: opt_loop_invariants on hoists the loop constants to the preheader. */
#pragma opt_loop_invariants on
// FUN_00142090
void func_00142090(u8 *arg0)
{
    s32 i;
    s16 cur;
    u8 *p;
    f32 f;

    for (i = 0; i < 8; i++) {
        cur = *(s16 *)((u8 *)arg0 + 0x34);
        if (i == cur) {
            p = (u8 *)arg0 + i * 0x30;
            *(s32 *)(p + 0x78) = 0xC4480000;
            *(s32 *)(p + 0x7C) = 0;
            *(u8 *)(p + 0x89) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8 *)arg0 + i * 0x30;
            *(s32 *)(p + 0x78) = 0;
            *(f32 *)(p + 0x7C) = f;
            *(u8 *)(p + 0x89) = 0;
        }
    }
}
/* measured: restore loop-invariant hoisting after func_00142090. */
#pragma opt_loop_invariants off
// FUN_00142130
void func_00142130(u8 *arg0) {
    *(f32 *)(arg0 + 0x250) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0x42C80000;
    *(s32 *)(arg0 + 0x220) = 0x42C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(s32 *)(arg0 + 0x708) = 0xC3160000;
    *(s32 *)(arg0 + 0x6D8) = 0xC2C80000;
    *(s32 *)(arg0 + 0x738) = 0xC2C80000;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_001421B0
void func_001421b0(u8 *arg0) {
    *(s32 *)(arg0 + 0x250) = 0xC3160000;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0xC2C80000;
    *(s32 *)(arg0 + 0x220) = 0xC2C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(f32 *)(arg0 + 0x708) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x6D8) = 0x42C80000;
    *(s32 *)(arg0 + 0x738) = 0x42C80000;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_00142230
/* measured: optimization level 1 plus base-before-value declaration order
   keeps the retail t0/t1/a3 live ranges and loop arithmetic. */
#pragma optimization_level 1
void func_00142230(u8 *arg0) {
    extern s32 iGpffff9cd8;
    extern u8 D_005EF5A0[];
    s32 i;
    u8 *base;
    s32 value;
    u8 *table;
    u8 *temp_3;
    u8 *temp_5;
    i = 0;
    base = (u8 *)&iGpffff9cd8;
    table = D_005EF5A0;
    while (i < 5) {
        value = *(s16 *)(arg0 + (*(u8 *)(base + i) * 2) + 0x187E) - 1;
        temp_5 = table + i * 0x28 + value * 8;
        temp_3 = arg0 + i * 0x30;
        *(f32 *)(temp_3 + 0x588) = *(f32 *)(temp_5 + 0);
        *(f32 *)(temp_3 + 0x58C) = *(f32 *)(temp_5 + 4);
        i++;
    }
}
/* measured: closes the scoped optimization-level-1 probe. */
#pragma optimization_level 2

// FUN_001422B0
void func_001422b0(u8 *arg0) {
    s32 temp_4;
    s32 temp_4_2;
s32 i;
    u8 *p;
    u8 *q;

    for (i = 0; i < 0x19; i++) {
        p = arg0 + i * 4;
        q = p + 0x1810;
        temp_4 = *(s32 *)(p + 0x1810);
        if (temp_4 != 0) {
            func_0046d280(temp_4);
            *(s32 *)q = 0;
        }
    }
    temp_4_2 = *(s32 *)(arg0 + 0x3C);
    if (temp_4_2 != 0) {
        func_00452080(temp_4_2);
        *(s32 *)(arg0 + 0x3C) = 0;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}
// FUN_00142340
s32 func_00142340(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x6C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

/* measured: opt_propagation off probe for func_001423c0. */
#pragma opt_propagation off
// FUN_001423C0
void func_001423c0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3)
{
    u8 *base;
    s32 count;
    s64 c1;
    u8 c2;
    u8 c3;
    base = arg2;
    count = arg3;
    c1 = ((u8 *)&arg1)[3];
    c2 = ((u8 *)&arg1)[2];
    c3 = ((u8 *)&arg1)[1];
    while (count > 0) {
        func_0034f320(*(u8 **)(base + ((count % 10) * 4) + 0x1844),
                      *(f32 *)&arg0, *(((f32 *)&arg0) + 1), fparg0, *(u8 *)&arg1, c3, c2,
                      c1, 0x1000, 0x1000, 0, 0, 0);
        *(f32 *)&arg0 -= 22.0f;
        count /= 10;
    }
}
/* measured: closes opt_propagation off probe for func_001423c0. */
#pragma opt_propagation on
// FUN_001424B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001424b0);
// FUN_001427C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001427c0);
/* measured: opt_propagation off probe for func_00142bf0. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on probe for func_00142bf0. */
#pragma opt_loop_invariants on
// FUN_00142BF0
void func_00142bf0(s64 arg0, s64 arg1, s32 arg2, f32 fparg0, s32 arg3)
{
    u8 packet[0x100];
    f32 temp_f20;
    f32 diff;
    s32 var_12;
    u8 *base;
    u8 *var_10;
    u8 *temp_8;
    u8 *temp_7;

    if (arg2 >= 5) {
        func_0046d730(&D_005EF6C8, 0x5B6);
    }
    temp_f20 = D_008872F8[0];
    D_00887300[0](1, 0);
    var_12 = 0;
    base = D_005EF710 + (arg2 << 5);
    diff = temp_f20 - fparg0;
    var_10 = (u8 *)&arg1;
    while (var_12 < 4) {
        if (var_12 < 2) {
            var_10 = (u8 *)&arg0;
        } else {
            var_10 = (u8 *)&arg1;
        }
        temp_8 = base + (var_12 * 8);
        temp_7 = packet + (var_12 << 6);
        *(f32 *)(temp_7 + 0) = *(f32 *)var_10 + *(f32 *)(temp_8 + 0);
        *(f32 *)(temp_7 + 4) = *((f32 *)var_10 + 1) + *(f32 *)(temp_8 + 4);
        *(f32 *)(temp_7 + 8) = diff;
        *(u32 *)(temp_7 + 0x20) = 0x437F0000;
        *(u32 *)(temp_7 + 0x24) = 0x431E0000;
        *(u32 *)(temp_7 + 0x28) = 0x40C00000;
        *(f32 *)(temp_7 + 0x2C) = (f32)(u32)arg3;
        var_12 += 1;
    }
    func_00364c50();
    D_00887310[0](4, packet, 4);
    func_00364c70();
}
/* measured: closes opt_loop_invariants on probe for func_00142bf0. */
#pragma opt_loop_invariants off
/* measured: restores opt_propagation after func_00142bf0 probe. */
#pragma opt_propagation on
// FUN_00142D80
void func_00142d80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Float2_0014 pair;
    Float2_0014 pair2;
    s32 temp_19;
    u8 *temp_2;
    u8 *var_5;
    u8 *var_6;

    if ((arg1 < 0) || (arg1 >= 4)) {
        func_0046d730(&D_005EF6C8, 0x5D8);
    }
    if (arg0 == NULL) {
        func_0046d730(&D_005EF6C8, 0x5D9);
    }
    if (arg3 != 0) {
        var_6 = D_005EF530 + (arg1 * 0x1C);
        var_5 = var_6 + 8;
    } else {
        var_5 = D_005EF530 + (arg1 * 0x1C);
        var_6 = var_5 + 8;
    }
    temp_2 = D_005EF540 + (arg1 * 0x1C);
    pair = *(Float2_0014 *)temp_2;
    temp_19 = *(s32 *)(D_005EF548 + (arg1 * 0x1C));
    if (arg2 != 0) {
        func_003550d0(arg0, (Float2_0014 *)var_5, (Float2_0014 *)var_6);
    } else {
        func_00355070(arg0, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, temp_19);
    if (arg1 == 2) {
        pair2.x = fGpffff8110;
        pair2.y = pair2.x;
        func_00355370(arg0, (u8 *)&pair2);
        return;
    }
    func_00355370(arg0, NULL);
}
// FUN_00142F20
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142f20);
// FUN_001437B0
void func_001437b0(u8 *arg0, s32 arg1, s32 arg2) {
    extern f32 D_00761184;
    extern f32 func_0044b610(f32 fparg0);
    extern f32 func_0044b7b0(f32 fparg0);
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_17;
    s32 temp_16;
    u8 temp_4;
    u16 temp_4_2;
    u16 temp_4_3;

    temp_17 = *(s32 *)(arg0 + 0x2C) - *(s32 *)(arg0 + 0x28);
    if (temp_17 == 0) {
        *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 8);
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0xC);
        *(u8 *)(arg0 + 0x1A) = *(u8 *)(arg0 + 0x19);
        *(u16 *)(arg0 + 0x20) = *(u16 *)(arg0 + 0x1E);
        *(u16 *)(arg0 + 0x26) = *(u16 *)(arg0 + 0x24);
        return;
    }
    if (*(s32 *)(arg0 + 0x2C) < arg1) {
        arg1 = *(s32 *)(arg0 + 0x2C);
    }
    if (arg1 < *(s32 *)(arg0 + 0x28)) {
        arg1 = *(s32 *)(arg0 + 0x28);
    }
    temp_16 = arg1 - *(s32 *)(arg0 + 0x28);
    switch (arg2) {
    case 0:
        temp_f21 = (D_00761184 * (f32)temp_16) / (f32)temp_17;
        temp_f20 = *(f32 *)arg0;
        *(f32 *)(arg0 + 0x10) =
            temp_f20 + (*(f32 *)(arg0 + 8) - temp_f20) *
                           func_0044b7b0(temp_f21);
        temp_f20 = *(f32 *)(arg0 + 4);
        *(f32 *)(arg0 + 0x14) =
            temp_f20 + (*(f32 *)(arg0 + 0xC) - temp_f20) *
                           func_0044b7b0(temp_f21);
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    case 1:
        *(f32 *)(arg0 + 0x10) =
            *(f32 *)arg0 +
            ((f32)temp_16 * (*(f32 *)(arg0 + 8) - *(f32 *)arg0)) /
                (f32)temp_17;
        *(f32 *)(arg0 + 0x14) =
            *(f32 *)(arg0 + 4) +
            ((f32)temp_16 * (*(f32 *)(arg0 + 0xC) - *(f32 *)(arg0 + 4))) /
                (f32)temp_17;
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    case 2:
        temp_f21 = (D_00761184 * (f32)temp_16) / (f32)temp_17;
        temp_f20 = *(f32 *)arg0;
        *(f32 *)(arg0 + 0x10) =
            temp_f20 + (*(f32 *)(arg0 + 8) - temp_f20) *
                           (1.0f - func_0044b610(temp_f21));
        temp_f20 = *(f32 *)(arg0 + 4);
        *(f32 *)(arg0 + 0x14) =
            temp_f20 + (*(f32 *)(arg0 + 0xC) - temp_f20) *
                           (1.0f - func_0044b610(temp_f21));
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    default:
        return;
    }
}
// FUN_00143B70
void func_00143b70(void)
{
}

// FUN_00143B80
void func_00143b80(void)
{
}

// FUN_00143B90
void func_00143b90(void)
{
}

// FUN_001441E0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001441e0);
// FUN_00144AC0
void func_00144ac0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00144AF0
s32 func_00144af0(void)
{
    s32 temp_2;

    func_0044ea90(&iGpffff9da8, 0xFE);
    temp_2 = (s32)D_008873F4[0](1, 0x20, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    return func_00451de0(&D_005EF7B0, 0x100, 0, 0,
                         func_001441e0, func_00144ac0, (void *)(u32)temp_2);
}
/* Return zero for a missing path; otherwise retain retail's short-circuited
   predicate calls and always-one result. Distinct equivalent low-16 forms
   prevent caching masks across calls without changing the predicate ABI.
   measured: object 264B/window 272B; exact instructions and 8B zero tail. */
// FUN_00144B80
s32 func_00144b80(s32 arg0, s32 arg1)
{
    char path[128];
    char part[128];
    s32 result;

    func_00442830(path, (char *)D_005EF7C0);
    func_00442088(part, (char *)&iGpffff9db8, arg0);
    func_00442428(path, part);
    func_00442088(part, (char *)&iGpffff9dc0, arg1);
    func_00442428(path, part);
    func_00442428(path, &iGpffff9dc8);
    if (func_00454570(path) == 0) {
        return 0;
    }
    result = 1;
    if (func_0014a230((u16)arg0, (u16)arg1) == 1 ||
        func_0014a2a0(arg0 & 0xFFFF, arg1 & 0xFFFF) == 1) {
        result = 1;
    }
    return result;
}
// FUN_00144C90
void func_00144c90(s32 arg0, s32 arg1) {
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *var_16;

    *(s32 *)(iGpffff9db0 + 0xC) = 0;
    temp_3 = iGpffff9db0;
    if ((*(s32 *)(temp_3 + 0) == arg0) &&
        (*(s32 *)(temp_3 + 4) == arg1) &&
        (func_0014a230(arg0 & 0xFFFF, arg1 & 0xFFFF) == 0)) {
        func_00440b68(&D_005EF7D0, arg0, arg1);
        temp_3_2 = iGpffff9db0;
        *(s32 *)(temp_3_2 + 0xC) = *(s32 *)(temp_3_2 + 0xC) | 1;
        var_16 = func_001452b0(0xA);
        goto loop_5_test;
loop_5_body:
        func_00479940((u8*)*(s32 *)(var_16 + 0x144), 0, 0, 0, 1);
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) | 2;
        var_16 = *(u8 **)(var_16 + 0x138);
loop_5_test:
        if (var_16 != NULL) {
            goto loop_5_body;
        }
        return;
    }
    func_00145080();
    *(s32 *)(iGpffff9db0 + 0x90) = 0;
    *(s32 *)(iGpffff9db0 + 0) = arg0;
    *(s32 *)(iGpffff9db0 + 4) = arg1;
    *(s16 *)(iGpffff9db0 + 0x10) = 0;
    temp_3_3 = iGpffff9db0;
    *(s16 *)(temp_3_3 + 0x12) = *(s32 *)(temp_3_3 + 4);
    *(s32 *)(iGpffff9db0 + 0x20) = func_00153a60(0);
    *(s32 *)(iGpffff9db0 + 8) = func_00147070();
    func_001458b0(0);
    func_0014ad90();
    func_00145930(0);
    func_0014b1e0();
    func_00440b68(&D_005EF800);
}
// FUN_00144E10
void func_00144e10(s64 arg0) {
    s32 temp_5;
    u8 *flags;
    u8 *temp_2;
    u8 *temp_7;
    u8 *var_4;

    temp_7 = iGpffff9db0;
    flags = temp_7 + 0xC;
    temp_5 = *(s32 *)flags;
    if (temp_5 & 1) {
        if (*(s16 *)(temp_7 + 0x10) != ((s64)(arg0 << 0x30) >> 0x30)) {
            *(s32 *)flags = temp_5 | 2;
            *(s16 *)(iGpffff9db0 + 0x10) = arg0;
            *(s32 *)(iGpffff9db0 + 0x94) = 0x1E;
            temp_2 = iGpffff9db0;
            func_0014eed0(*(u16 *)temp_2, *(u16 *)(temp_2 + 4));
            return;
        }
        var_4 = func_001452b0(3);
        while (var_4 != NULL) {
            *(s32 *)(var_4 + 0x28) |= 2;
            var_4 = *(u8 **)(var_4 + 0x138);
        }
        return;
    }
    *(s16 *)(temp_7 + 0x10) = arg0;
}
// FUN_00144ED0
void func_00144ed0(s64 arg0) {
    s32 temp_6;
    u8 *flags;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffff9db0;
    flags = temp_5 + 0xC;
    temp_6 = *(s32 *)flags;
    if (temp_6 & 1) {
        if (*(s16 *)(temp_5 + 0x12) != ((s64)(arg0 << 0x30) >> 0x30)) {
            * (s32 *)flags = temp_6 | 4;
            *(s16 *)(iGpffff9db0 + 0x12) = arg0;
            temp_2 = iGpffff9db0;
            func_0014eed0(*(u16 *)temp_2, *(u16 *)(temp_2 + 4));
            temp_4 = iGpffff9db0;
            if ((*(s32 *)(temp_4 + 0xC) & 2) == 0) {
                *(s32 *)(temp_4 + 0x94) = 0x28;
            }
        }
    } else {
        *(s16 *)(temp_5 + 0x12) = arg0;
    }
}
// FUN_00144F60
s32 func_00144f60(void)
{
    s32 temp_3;
    s32 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3_3;
    u8 *temp_5;

    temp_5 = iGpffff9db0;
    if (*(s32 *)(temp_5 + 8) == 0) {
        return 1;
    }
    temp_3 = *(s32 *)(temp_5 + 0xC);
    if ((temp_3 & 1) && !(temp_3 & 6)) {
        return 1;
    }
    temp_3_3 = temp_5 + 0x90;
    temp_3_2 = *(s32 *)temp_3_3;
    switch (temp_3_2) {
    case 0:
        *(s32 *)temp_3_3 = temp_3_2 + 1;
        return 0;
    case 1:
        temp_2 = iGpffff9db0;
        func_0014eed0(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
        temp_2_2 = iGpffff9db0;
        func_0014efc0(*(u16 *)(temp_2_2 + 0), *(u16 *)(temp_2_2 + 4));
        temp_3_3 = iGpffff9db0;
        *(s32 *)(temp_3_3 + 0x90) = *(s32 *)(temp_3_3 + 0x90) + 1;
        return 0;
    default:
        if (func_0014f310((s32)temp_3_3, (s32)temp_5) == 0) {
            return 0;
        }
        if (*(s32 *)(iGpffff9db0 + 0x1C) == 0) {
            *(s32 *)(iGpffff9db0 + 0x1C) = func_0026df80();
        }
        return 1;
    }
}
// FUN_00145080
void func_00145080(void) {
    u8 *temp_17;
    s32 var_16;
    s32 temp_18;
    u8 *temp_18_3;
    s32 var_16_2;
    s32 var_16_3;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *var_2;

    temp_2 = iGpffff9db0;
    temp_17 = *(u8 **)(temp_2 + 8);
    temp_4 = *(u8 **)(temp_2 + 0x1C);
    if (temp_4 != NULL) {
        func_00452080((s32)temp_4);
        *(u8 **)(iGpffff9db0 + 0x1C) = NULL;
    }
    if (*(u8 **)(iGpffff9db0 + 0x20) != NULL) {
        func_00451b70();
        func_00452080(*(s32 *)(iGpffff9db0 + 0x20));
        *(u8 **)(iGpffff9db0 + 0x20) = NULL;
    }
    var_16 = 0;
    goto loop_8_test;
loop_8:
    temp_2 = iGpffff9db0;
    temp_18 = var_16 * 4;
    temp_2 += temp_18;
    temp_4_2 = *(u8 **)(temp_2 + 0x68);
    if (temp_4_2 != NULL) {
        func_00452080((s32)temp_4_2);
        *(s32 *)(iGpffff9db0 + temp_18 + 0x68) = 0;
    }
    var_16++;
loop_8_test:
    if (var_16 < 4) {
        goto loop_8;
    }
    var_16_2 = 0;
    goto loop_13_test;
loop_13:
    temp_2 = iGpffff9db0;
    temp_18 = var_16_2 * 4;
    temp_2 += temp_18;
    temp_4_3 = *(u8 **)(temp_2 + 0x78);
    if (temp_4_3 != NULL) {
        func_00452080((s32)temp_4_3);
        *(s32 *)(iGpffff9db0 + temp_18 + 0x78) = 0;
    }
    var_16_2++;
loop_13_test:
    if (var_16_2 < 4) {
        goto loop_13;
    }
    if (temp_17 != 0) {
        var_16_3 = 0;
        goto loop_20_test;
loop_20_body:
        var_2 = func_00147500(temp_17, var_16_3 & 0xFF);
        goto loop_18_test;
loop_18_body:
        temp_18_3 = *(u8 **)(var_2 + 0x138);
        func_00146630(*(u16 *)(var_2 + 0));
        var_2 = temp_18_3;
loop_18_test:
        if (var_2 != NULL) {
            goto loop_18_body;
        }
        var_16_3++;
loop_20_test:
        if (var_16_3 < 0x16) {
            goto loop_20_body;
        }
        func_001470e0(temp_17);
        *(s32 *)(iGpffff9db0 + 8) = 0;
    }
    func_0015cc40();
    func_0015cf10();
    func_00160180();
    *(s32 *)(iGpffff9db0 + 0) = -1;
    *(s32 *)(iGpffff9db0 + 4) = -1;
    *(s16 *)(iGpffff9db0 + 0x10) = 0;
    *(s16 *)(iGpffff9db0 + 0x12) = 0;
    *(s32 *)(iGpffff9db0 + 0x14) = 0;
    func_003e1a70();
}
// FUN_00145250
s32 func_00145250(void) {
    return D_00762EA0;
}



// FUN_001452B0
u8 *func_001452b0(s32 arg0)
{
    u8 *resManager;

    resManager = *(u8 **)(iGpffff9db0 + 8);
    if (resManager == NULL) {
        return NULL;
    }
    return resrcMngGetListHead(resManager, (u8)(arg0 & 0xFF));
}

// FUN_001453A0
s32 func_001453a0(u16 arg0)
{
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x2000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(D_005EF820);
        return 0;
    }
    temp_3 = (u16)temp_16;
    if (((temp_3 & 0xFFC00) >> 10) != 8) {
        func_00440b68(D_005EF840);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        func_0046d730(D_005EF858, 0x1DE);
    }
    return temp_16;
}
// FUN_00145480
s32 func_00145480(u16 arg0) {
    s32 temp_16;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x1C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x140) = 0x420C0000;
    return temp_16;
}
// FUN_00145510
void func_00145510(s32 arg0, s32 arg1) {
    extern s32 func_00145540(s32 arg0, s32 arg1, s32 arg2);
    func_00145540(arg0, 0, arg1);
}



// FUN_00145540
s32 func_00145540(u16 arg0, s32 arg1, s32 arg2) {
    s8 sp50[0xC];
    s32 temp_16;
    s32 temp_2_2;
    s32 temp_4;
    s8 *var_3;
    s32 var_2;
    u8 *temp_2;

    var_3 = sp50;
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x164) = arg2;
    func_0047a180(arg2, sp50, 0);
    func_003e05d0(func_0047a2f0(*(s32 *)(temp_2 + 0x164)));
    temp_2_2 = func_001684a0(0, temp_16 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x220) = temp_2_2;
    *(s32 *)(temp_2 + 0x224) = func_0017b510(temp_2_2, temp_16, arg1);
    return temp_16;
}
// FUN_00145690
s32 func_00145690(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x158) = arg1;
    func_0047a180(arg1, sp30, 0);
    return temp_17;
}
// FUN_00145780
s32 func_00145780(u16 arg0, s32 arg1, s32 arg2) {
    s8 sp[0xC];
    s32 temp_17;
    s32 temp_2_2;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0xC00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 0x10000000;
    *(s32 *)(temp_2 + 0x164) = arg2;
    temp_2_2 = func_001684a0(0, temp_17 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x228) = temp_2_2;
    *(s32 *)(temp_2 + 0x230) = func_0017b510(temp_2_2, temp_17, arg1);
    return temp_17;
}
// FUN_001459B0
s32 func_001459b0(u16 arg0, s32 arg1, s8 arg2) {
    s32 sp[3];
    s32 temp_16;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x1800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        func_00440b68(&D_005EF870);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = func_004b1130(arg1);
    *(s8 *)(temp_2 + 0x140) = arg2;
    sp[0] = 0x42C80000;
    sp[1] = 0;
    sp[2] = 0;
    func_004b1250(*(s32 *)(temp_2 + 0x144), (u8 *)sp);
    func_004b13d0(*(s32 *)(temp_2 + 0x144), 1.5f);
    return temp_16;
}
// FUN_00145AC0
s32 func_00145ac0(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x2800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145BA0
s32 func_00145ba0(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x2C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145C80
s32 func_00145c80(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x1A0) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145D60
s32 func_00145d60(u16 arg0, f32 *arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp5C;
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;
    Rgba8_0014 color;

    sp5C = arg2;
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x144) = point;
    *(f32 *)(temp_2 + 0x150) = fparg0;
    *(f32 *)(temp_2 + 0x154) = fparg1;
    *(f32 *)(temp_2 + 0x158) = fparg2;
    color = *(Rgba8_0014 *)&sp5C;
    *(Rgba8_0014 *)(temp_2 + 0x140) = color;
    func_0015f720(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145E90
s32 func_00145e90(u16 arg0, f32 *arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp5C;
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;
    Rgba8_0014 color;

    sp5C = arg2;
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x5400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x144) = point;
    *(f32 *)(temp_2 + 0x150) = fparg0;
    *(f32 *)(temp_2 + 0x154) = fparg1;
    *(f32 *)(temp_2 + 0x158) = fparg2;
    color = *(Rgba8_0014 *)&sp5C;
    *(Rgba8_0014 *)(temp_2 + 0x140) = color;
    func_0015f720(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145FC0
s32 func_00145fc0(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_00146080
s32 func_00146080(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_00146140
s32 func_00146140(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_00146200
s32 func_00146200(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_001462C0
s32 func_001462c0(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_00146380
s32 func_00146380(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}
// FUN_00146440
s32 func_00146440(u16 arg0, s32 arg1, f32 fparg0, u8 *arg2, u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6) {
    s32 temp_22;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *temp_2;
    u8 *var_19;
    u8 *var_20;
    u8 *var_5;
    u8 *var_5_2;
    s32 var_4;
    s32 var_4_2;
    SVec3 point;

    temp_22 = ((arg0 & 0xFFFF & 0x3FF) | 0x5000) & 0xFFFF;
    var_20 = arg2;
    var_19 = arg3;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = func_00147190(temp_4, temp_22);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x140) = arg1;
    *(f32 *)(temp_2 + 0x144) = fparg0;
    *(u8 **)(temp_2 + 0x148) = func_003e0f80();
    if (var_20 != NULL) {
        var_5 = *(u8 **)(temp_2 + 0x148);
        var_4 = 8;
        do {
            temp_3 = *(s32 *)(var_20 + 0);
            temp_2_2 = *(s32 *)(var_20 + 4);
            var_20 += 8;
            var_4 -= 1;
            *(s32 *)(var_5 + 0) = temp_3;
            *(s32 *)(var_5 + 4) = temp_2_2;
            var_5 += 8;
        } while (var_4 > 0);
    }
    *(u8 **)(temp_2 + 0x14C) = func_003e0f80();
    if (var_19 != NULL) {
        var_5_2 = *(u8 **)(temp_2 + 0x14C);
        var_4_2 = 8;
        do {
            temp_3_2 = *(s32 *)(var_19 + 0);
            temp_2_3 = *(s32 *)(var_19 + 4);
            var_19 += 8;
            var_4_2 -= 1;
            *(s32 *)(var_5_2 + 0) = temp_3_2;
            *(s32 *)(var_5_2 + 4) = temp_2_3;
            var_5_2 += 8;
        } while (var_4_2 > 0);
    }
    if (arg4 != NULL) {
        point = *(SVec3 *)arg4;
        *(SVec3 *)(temp_2 + 0x150) = point;
    }
    *(f32 *)(temp_2 + 0x15C) = fparg1;
    *(f32 *)(temp_2 + 0x160) = fparg2;
    if (arg5 != 0) {
        func_0043f810(temp_2 + 0x164, (const void *)arg5, 0x20);
    }
    if (arg6 != 0) {
        func_0043f810(temp_2 + 0x184, (const void *)arg6, 0x180);
    }
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_22;
}
/* measured: O1 probe for 00146630 register allocation and short tail. */
#pragma optimization_level 1
/* measured: schedule-off probe for 46630 branch delay slots. */
#pragma schedule off
// FUN_00146630
void func_00146630(u16 arg0) {
    s32 var_19;
    s32 temp_2;
    s32 temp_4_12;
    s32 temp_4_6;
    s32 temp_4_8;
    s32 var_17;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_17_3;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_4;
    u8 *temp_4_10;
    u8 *temp_4_11;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_7;
    u8 *temp_4_9;
    u8 *temp_4_14;
    u8 *var_16;
    temp_18 = *(u8 **)(iGpffff9db0 + 8);
    if (temp_18 == NULL) {
        func_00440b68(&D_005EF820);
        return;
    }
    if (temp_18 == NULL) {
        var_16 = NULL;
    } else {
        var_16 = func_00147530(temp_18, arg0);
    }
    if (var_16 != NULL) {
        temp_2 = (*(u16 *)(var_16 + 0) & 0xFFC00) >> 0xA;
            switch (temp_2) {
            case 1:
                temp_17 = *(u8 **)(var_16 + 0x164);
                func_00452080(*(s32 *)(var_16 + 0x220));
                *(s32 *)(var_16 + 0x220) = 0;
                *(s32 *)(var_16 + 0x224) = 0;
                *(s32 *)(var_16 + 0x164) = 0;
                var_19 = 0;
                while (var_19 < 2) {
                    temp_2_2 = var_16 + var_19 * 4;
                    temp_4_14 = temp_2_2 + 0x140;
                    temp_4 = *(u8 **)(temp_2_2 + 0x140);
                    if (temp_4 != NULL) {
                        func_004b1150((s32)temp_4);
                        *(s32 *)temp_4_14 = 0;
                    }
                    var_19 += 1;
                }
                temp_4_2 = *(u8 **)(var_16 + 0x228);
                if (temp_4_2 != NULL) {
                    func_004787e0((s32)temp_4_2);
                    *(s32 *)(var_16 + 0x228) = 0;
                }
                func_00440b68(&D_005EF890, temp_17);
                break;
            case 2:
                temp_17_2 = *(u8 **)(var_16 + 0x158);
                func_004787e0((s32)temp_17_2);
                *(s32 *)(var_16 + 0x158) = 0;
                func_00440b68(&D_005EF890, temp_17_2);
                break;
            case 3:
                var_19 = (s32)*(u8 **)(var_16 + 0x164);
                temp_4_3 = *(u8 **)(var_16 + 0x228);
                if (temp_4_3 != NULL) {
                    func_00452080((s32)temp_4_3);
                    *(s32 *)(var_16 + 0x228) = 0;
                }
                *(s32 *)(var_16 + 0x230) = 0;
                *(s32 *)(var_16 + 0x294) = 0;
                temp_4_4 = *(u8 **)(var_16 + 0x22C);
                if (temp_4_4 != NULL) {
                    func_004787e0((s32)temp_4_4);
                    *(s32 *)(var_16 + 0x22C) = 0;
                }
                func_004787e0((s32)var_19);
                *(s32 *)(var_16 + 0x164) = 0;
                var_17 = 0;
                while (var_17 < 2) {
                    temp_2_3 = var_16 + var_17 * 4;
                    temp_4_14 = temp_2_3 + 0x140;
                    temp_4_5 = *(u8 **)(temp_2_3 + 0x140);
                    if (temp_4_5 != NULL) {
                        func_004b1150((s32)temp_4_5);
                        *(s32 *)temp_4_14 = 0;
                    }
                    var_17 += 1;
                }
                temp_4_6 = *(s32 *)(var_16 + 0x288);
                if (temp_4_6 != 0) {
                    jtbl_008873EC[0]((u8 *)temp_4_6);
                }
                temp_4_7 = *(u8 **)(var_16 + 0x290);
                if (temp_4_7 != NULL) {
                    func_00452080((s32)temp_4_7);
                }
                temp_4_8 = *(s32 *)(var_16 + 0x360);
                if (temp_4_8 != 0) {
                    func_003bbb60(temp_4_8);
                }
                func_00440b68(&D_005EF890, (u8 *)var_19);
                break;
            case 6:
                temp_4_9 = *(u8 **)(var_16 + 0x144);
                if (temp_4_9 != NULL) {
                    func_00268b20(temp_4_9);
                    *(s32 *)(var_16 + 0x144) = 0;
                    func_00440b68(&D_005EF8B0, var_16);
                }
                break;
            case 10:
                temp_17_3 = *(u8 **)(var_16 + 0x144);
                func_004787e0((s32)temp_17_3);
                *(s32 *)(var_16 + 0x144) = 0;
                temp_4_10 = *(u8 **)(var_16 + 0x16C);
                if (temp_4_10 != NULL) {
                    func_004787e0((s32)temp_4_10);
                    *(s32 *)(var_16 + 0x16C) = 0;
                }
                func_00440b68(&D_005EF8D0, temp_17_3);
                break;
            case 11:
                temp_4_11 = *(u8 **)(var_16 + 0x144);
                if (temp_4_11 != NULL) {
                    func_004b1150((s32)temp_4_11);
                    *(s32 *)(var_16 + 0x144) = 0;
                    func_00440b68(&D_005EF8F0, var_16);
                }
                break;
            case 12:
                temp_4_12 = *(s32 *)(var_16 + 0x1A0);
                if (temp_4_12 != 0) {
                    func_00151f80((void *)temp_4_12);
                    *(s32 *)(var_16 + 0x1A0) = 0;
                    func_00440b68(&D_005EF910, var_16);
                }
                break;
            case 13:
            case 21:
                func_00440b68(&D_005EF930, var_16);
                break;
            case 14:
            case 15:
            case 16:
                func_00440b68(&D_005EF950, var_16);
                break;
            case 20:
                func_003e0f40(*(s32 *)(var_16 + 0x148));
                func_003e0f40(*(s32 *)(var_16 + 0x14C));
                func_00440b68(&D_005EF970, var_16);
                break;
            case 4:
            case 5:
            case 7:
            case 8:
            case 9:
            case 17:
            case 18:
            case 19:
            ;
            }
        func_00147430(temp_18, var_16);
    }
}
/* measured: closes schedule-off probe for 46630. */
#pragma schedule on
#pragma optimization_level 2
// FUN_00146A10
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00146a10);
// FUN_00147530
u8 *func_00147530(u8 *arg0, u16 arg1) {
    s32 temp_3;
    s32 temp_5;
    u8 *var_2;

    temp_5 = arg1;
    temp_3 = ((temp_5 & 0xFFC00) >> 0xA) & 0xFF;
    if (temp_3 == 0) {
        return NULL;
    }
    if (temp_3 >= 0x16) {
        return NULL;
    }
    var_2 = *(u8 **)(arg0 + temp_3 * 4);
    while (var_2 != NULL) {
        if (*(u16 *)var_2 == temp_5) {
            return var_2;
        }
        var_2 = *(u8 **)(var_2 + 0x138);
    }
    return NULL;
}
// FUN_001475C0
/* Ported from P3FES resrcMngGetTotalResInList: P4 uses a 0x16-entry list
   table and the list link remains at offset 0x138. */
u32 func_001475c0(u8 *resLists, u8 resType)
{
    u32 total;
    u8 *currRes;

    total = 0;
    if (resType >= 0x16) {
        return total;
    }
    currRes = *(u8 **)(resLists + resType * 4);
    while (currRes != NULL) {
        total++;
        currRes = *(u8 **)(currRes + 0x138);
    }
    return total;
}

// FUN_00147620
u8 *func_00147620(s32 arg0) {
    return D_005EFAA0 + arg0 * 0x10;
}
/* measured probe: opt_propagation off for 00147640 float ordering. */
#pragma opt_propagation off
// FUN_00147640
void func_00147640(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_16;
    s32 temp_2_3;
    s32 temp_3;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *var_6;
    u8 *var_5;
    s32 var_4;
    void (**base)(u32, u32);

    func_003e8110(func_00457120());
    temp_2 = func_004571a0();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = func_004571b0();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(func_004571b0() + 4) + 0x10;
    var_5 = arg1 + 0x20;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)(var_6 + 0);
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)(var_5 + 0) = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    temp_16 = (s32)func_00457190();
    func_003cbf30(temp_16, func_004571c0());
    if (func_00149ca0() != NULL) {
        temp_16_2 = func_004571a0();
        func_003c38b0(temp_16_2, func_00149ca0());
        temp_16_3 = func_004571b0();
        func_003c38b0(temp_16_3, func_00149ce0());
        temp_16_4 = func_004571b0();
        func_003e9cb0(*(s32 *)(temp_16_4 + 4), func_00149d20(), 0);
    }
    func_003e8120(func_00457120());
    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0xE, 1);
        base[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        base[0](0x10, 1);
    }
}
/* measured probe: restore opt_propagation after 00147640. */
#pragma opt_propagation on
// FUN_00147830
void func_00147830(u8 *arg0, u8 *arg1) {
    u8 *temp_16;

    func_003e8110(func_00457120());
    temp_16 = func_00457190();
    func_003cbe80(temp_16, func_004571c0());
    if (func_00149ca0() != NULL) {
        func_003c38b0(func_004571a0(), arg1);
        func_003c38b0(func_004571b0(), arg1 + 0x10);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x20, 0);
    }
    func_003e8120(func_00457120());
}
/* measured probe: opt_propagation off for 00147910 float and vtable order. */
#pragma opt_propagation off
// FUN_00147910
void func_00147910(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_3;
    s32 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *var_6;
    u8 *var_5;
    s32 var_4;
    u8 *var_6_2;
    u8 *var_5_2;
    s32 var_4_2;
    void (**base)(u32, u32);

    func_003e8110(func_00457120());
    temp_2 = func_004571a0();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = func_004571b0();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(func_004571b0() + 4) + 0x10;
    var_5 = arg1 + 0x20;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)(var_6 + 0);
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)(var_5 + 0) = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    temp_2_4 = func_004571c0();
    temp_f3 = *(f32 *)(temp_2_4 + 0x18);
    temp_f2 = *(f32 *)(temp_2_4 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_4 + 0x20);
    temp_f0 = *(f32 *)(temp_2_4 + 0x24);
    *(f32 *)(arg1 + 0x60) = temp_f3;
    *(f32 *)(arg1 + 0x64) = temp_f2;
    *(f32 *)(arg1 + 0x68) = temp_f1;
    *(f32 *)(arg1 + 0x6C) = temp_f0;
    var_6_2 = *(u8 **)(func_004571c0() + 4) + 0x10;
    var_5_2 = arg1 + 0x70;
    var_4_2 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2_5 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4_2 -= 1;
        *(s32 *)(var_5_2 + 0) = temp_3_2;
        *(s32 *)(var_5_2 + 4) = temp_2_5;
        var_5_2 += 8;
    } while (var_4_2 > 0);
    func_003e8120(func_00457120());
    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0xE, 1);
        base[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        base[0](0x10, 1);
    }
    D_00887300[0](0x14, 2);
}
/* measured probe: restore opt_propagation after 00147910. */
#pragma opt_propagation on
// FUN_00147AE0
void func_00147ae0(u8 *arg0, u8 *arg1) {
    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), arg1);
    func_003c38b0(func_004571c0(), arg1 + 0x60);
    func_003c38b0(func_004571b0(), arg1 + 0x10);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x70, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x20, 0);
    func_003e8120(func_00457120());
}
// FUN_00147BB0
void func_00147bb0(u8 *arg0, u8 *arg1) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = func_001452b0(4);
    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), temp_16 + 0x140);
    func_003c38b0(func_004571c0(), temp_16 + 0x150);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), temp_16 + 0x160, 0);
    temp_3 = *(s32 *)(arg1 + 0x28);
    if (temp_3 & 0x80000000) {
        func_003c38b0(func_004571a0(), arg1 + 0x168);
        func_003c38b0(func_004571c0(), arg1 + 0x178);
        func_003c38b0(func_004571b0(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x190, 0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    } else if (temp_3 & 0x40000000) {
        func_003c38b0(func_004571b0(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    } else {
        func_003c38b0(func_004571b0(), temp_16 + 0x1A0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), temp_16 + 0x1B0, 0);
    }
    func_003e8120(func_00457120());
}
// FUN_00147D80
void func_00147d80(void) {
    u8 *temp_16;

    temp_16 = func_001452b0(5);
    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), temp_16 + 0x140);
    func_003c38b0(func_004571c0(), temp_16 + 0x150);
    func_003c38b0(func_004571b0(), temp_16 + 0x1A0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), temp_16 + 0x160, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), temp_16 + 0x1B0, 0);
    func_003e8120(func_00457120());
}
// FUN_00147E60
void func_00147e60(u8 *arg0, u8 *arg1) {
    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), arg1 + 0x168);
    func_003c38b0(func_004571c0(), arg1 + 0x178);
    func_003c38b0(func_004571b0(), arg1 + 0x1D0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x190, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    func_003e8120(func_00457120());
}
// FUN_00147F30
void func_00147f30(u8 *arg0, u8 *arg1) {
    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), arg1 + 0x15C);
    func_003c38b0(func_004571c0(), arg1 + 0x16C);
    func_003c38b0(func_004571b0(), arg1 + 0x1C0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x180, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1D0, 0);
    func_003e8120(func_00457120());
}
/* measured probe: opt_propagation off preserves 00148000 vector coloring. */
#pragma opt_propagation off
// FUN_00148000
s32 func_00148000(u8 **arg0, u8 **arg1) {
    struct Frame {
        f32 v40[3];
        u8 pad4C[4];
        f32 v50[3];
        u8 pad5C[4];
        f32 v60[3];
        u8 pad6C[4];
    } frame;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;

    temp_2 = func_00457120();
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f2 = *(f32 *)(temp_2 + 0x30);
    temp_f1 = *(f32 *)(temp_2 + 0x34);
    temp_f0 = *(f32 *)(temp_2 + 0x38);
    frame.v40[0] = temp_f2;
    frame.v40[1] = temp_f1;
    frame.v40[2] = temp_f0;
    temp_17 = *arg0;
    temp_16 = *arg1;
    frame.v60[0] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x30) - frame.v40[0];
    temp_f21 = frame.v40[1];
    frame.v60[1] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x34) - temp_f21;
    temp_f20 = frame.v40[2];
    frame.v60[2] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x38) - temp_f20;
    frame.v50[0] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x30) - frame.v40[0];
    frame.v50[1] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x34) - temp_f21;
    frame.v50[2] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x38) - temp_f20;
    temp_f20 = func_003e4180(frame.v60);
    return (s32)(temp_f20 - func_003e4180(frame.v50));
}
/* measured: closes opt_propagation off for func_00148000. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves 00148140 vector coloring. */
#pragma opt_propagation off
// FUN_00148140
s32 func_00148140(u8 **arg0, u8 **arg1) {
    struct Frame {
        f32 v40[3];
        u8 pad4C[4];
        f32 v50[3];
        u8 pad5C[4];
        f32 v60[3];
        u8 pad6C[4];
    } frame;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;

    temp_2 = func_00457120();
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f2 = *(f32 *)(temp_2 + 0x30);
    temp_f1 = *(f32 *)(temp_2 + 0x34);
    temp_f0 = *(f32 *)(temp_2 + 0x38);
    frame.v40[0] = temp_f2;
    frame.v40[1] = temp_f1;
    frame.v40[2] = temp_f0;
    temp_17 = *arg0;
    temp_16 = *arg1;
    frame.v60[0] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x30) - frame.v40[0];
    temp_f21 = frame.v40[1];
    frame.v60[1] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x34) - temp_f21;
    temp_f20 = frame.v40[2];
    frame.v60[2] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_17 + 0x164)) + 0x38) - temp_f20;
    frame.v50[0] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x30) - frame.v40[0];
    frame.v50[1] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x34) - temp_f21;
    frame.v50[2] = *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x164)) + 0x38) - temp_f20;
    temp_f20 = func_003e4180(frame.v60);
    return (s32)(temp_f20 - func_003e4180(frame.v50));
}
/* measured: closes opt_propagation off for func_00148140. */
#pragma opt_propagation on
// FUN_00148280
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00148280);
// FUN_00149620
u8 *func_00149620(void) {
    u8 *ctx;
    u8 *o;

    o = func_00451fc0(ctx, D_005EFB10, 0xC7, 0, 0, (void *)func_00148280, NULL, NULL);
    func_0017ccc0(o);
    return o;
}

// FUN_00149680
void func_00149680(s32 arg0) {
    D_007642E4 = arg0;
}



// FUN_00149690
void func_00149690(s32 arg0) {
    if (arg0 == 0) {
        iGpffff9dd0 = 0xF;
        return;
    }
    iGpffff9dd0 = 0x1D;
}
// FUN_001496C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001496c0);
// FUN_00149CA0
u8 *func_00149ca0(void) {
    u8 *temp_2;

    temp_2 = func_001452b0(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x140;
}
// FUN_00149CE0
u8 *func_00149ce0(void) {
    u8 *temp_2;

    temp_2 = func_001452b0(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x150;
}
// FUN_00149D20
u8 *func_00149d20(void) {
    u8 *temp_2;

    temp_2 = func_001452b0(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x160;
}
// FUN_00149D60
void func_00149d60(s32 arg0)
{
    func_001452b0(12);
    func_00153b20(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149DB0
void func_00149db0(s32 arg0)
{
    func_001452b0(12);
    func_00153b60(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E00
void func_00149e00(s32 arg0)
{
    func_001452b0(12);
    func_00153b90(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E50
void func_00149e50(s32 arg0)
{
    func_001452b0(12);
    func_00153bd0(*(s32 *)(D_00762EA0 + 32), arg0);
}

/* measured: opt_rebuildconditionals off is scoped to func_00149ea0. */
#pragma opt_rebuildconditionals off

// FUN_00149EA0
void func_00149ea0(void)
{
    extern f32 fGpffff8198;
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    s32 stack[3];
    f32 temp_f0;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *var_17;
    u8 *var_18;
    u8 *var_16;

    temp_2 = func_001452b0(0xC);
    if (temp_2 == NULL) {
        var_17 = NULL;
    } else {
        var_17 = temp_2 + 0x140;
    }
    temp_2_2 = func_001452b0(0xC);
    if (temp_2_2 == NULL) {
        var_18 = NULL;
    } else {
        var_18 = temp_2_2 + 0x150;
    }
    temp_2_3 = func_001452b0(0xC);
    if (temp_2_3 == NULL) {
        var_16 = NULL;
    } else {
        var_16 = temp_2_3 + 0x160;
    }
    temp_f0 = fGpffff8198;
    *(f32 *)(var_17 + 0) = temp_f0;
    *(f32 *)(var_17 + 4) = temp_f0;
    *(f32 *)(var_17 + 8) = temp_f0;
    *(s32 *)(var_17 + 0xC) = 0;
    *(s32 *)(var_18 + 0) = 0x3F000000;
    *(s32 *)(var_18 + 4) = 0x3F000000;
    *(s32 *)(var_18 + 8) = 0x3F000000;
    *(s32 *)(var_18 + 0xC) = 0;
    *(s32 *)(var_16 + 0x28) = 0x3F800000;
    *(s32 *)(var_16 + 0x14) = 0x3F800000;
    *(s32 *)(var_16 + 0) = 0x3F800000;
    *(s32 *)(var_16 + 0x10) = 0;
    *(s32 *)(var_16 + 8) = 0;
    *(s32 *)(var_16 + 4) = 0;
    *(s32 *)(var_16 + 0x24) = 0;
    *(s32 *)(var_16 + 0x20) = 0;
    *(s32 *)(var_16 + 0x18) = 0;
    *(s32 *)(var_16 + 0x38) = 0;
    *(s32 *)(var_16 + 0x34) = 0;
    *(s32 *)(var_16 + 0x30) = 0;
    *(s32 *)(var_16 + 0xC) = *(s32 *)(var_16 + 0xC) | 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    func_003e0870(var_16, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    func_003e0870(var_16, &stack[0], 2, -45.0f);
}
/* measured: closes opt_rebuildconditionals for func_00149ea0. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a000. */
#pragma opt_rebuildconditionals off

/* measured: loop-invariant constants probe for func_0014a000. */
#pragma opt_loop_invariants on
// FUN_0014A000
void func_0014a000(s32 arg0, s32 arg1)
{
    u8 *var_16;
    u8 *var_6;
    s32 one;
    s32 mask;
    var_16 = func_001452b0(0xC);
    var_6 = func_001452b0(0xA);
    one = 1;
    mask = -3;
    goto loop_5_test;
loop_5_body:
    if (arg0 == one) {
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) | 2;
    } else {
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) & mask;
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_5_test:
    if (var_16 != NULL) {
        goto loop_5_body;
    }
    if (arg1 != one) {
        goto done;
    }
    goto loop_12_test;
loop_12_body:
    if (arg0 == one) {
        *(s32 *)(var_6 + 0x28) = *(s32 *)(var_6 + 0x28) | 2;
    } else {
        *(s32 *)(var_6 + 0x28) = *(s32 *)(var_6 + 0x28) & mask;
    }
    var_6 = *(u8 **)(var_6 + 0x138);
loop_12_test:
    if (var_6 != NULL) {
        goto loop_12_body;
    }
done:
    ;
}
/* measured: closes loop-invariant constants probe for func_0014a000. */
#pragma opt_loop_invariants off
/* measured: closes opt_rebuildconditionals for func_0014a000. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a160. */
#pragma opt_rebuildconditionals off

// FUN_0014A160
void func_0014a160(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    func_0014a190(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
/* measured: closes opt_rebuildconditionals for func_0014a160. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a190. */
#pragma opt_rebuildconditionals off

// FUN_0014A190
s32 func_0014a190(s32 arg0, s32 arg1) {
    if (func_0014a230(arg0, arg1) == 1) {
        return 1;
    }
    return func_0014a2a0(arg0, arg1) == 1;
}
/* measured: closes opt_rebuildconditionals for func_0014a190. */
#pragma opt_rebuildconditionals on

// FUN_0014A200
s32 func_0014a200(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    return func_0014a230(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
// FUN_0014A230
s32 func_0014a230(s32 arg0, s32 arg1) {
    s32 result;

    arg0 &= 0xFFFF;
    if (arg0 < 0x28) {
        goto false_0014a230;
    }
    if (arg0 >= 0x3C) {
        goto false_0014a230;
    }
    if ((arg1 & 0xFFFF) != 0) {
        goto false_0014a230;
    }
    result = 1;
    goto done_0014a230;
false_0014a230:
    result = 0;
done_0014a230:
    return result;
}
// FUN_0014A270
void func_0014a270(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    func_0014a2a0(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
// FUN_0014A2A0
s32 func_0014a2a0(s32 arg0, s32 arg1) {
    s32 result;

    arg0 &= 0xFFFF;
    if (arg0 < 0x3C) {
        goto false_0014a2a0;
    }
    if (arg0 >= 0x50) {
        goto false_0014a2a0;
    }
    result = 1;
    goto done_0014a2a0;
false_0014a2a0:
    result = 0;
done_0014a2a0:
    return result;
}
// FUN_0014A2F0
void func_0014a2f0(s32 arg0)
{
    *(s32 *)(iGpffff9db0 + 0x18) = arg0;
}

// FUN_0014B1E0
void func_0014b1e0(void) {
    extern f32 fGpffff8198;
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    s32 stack[3];
    f32 temp_f0;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *var_16;
    u8 *var_17;
    u8 *var_18;
    u8 *var_19;
    u8 *var_20;

    temp_2 = func_001452b0(5);
    if (temp_2 != NULL) {
        var_20 = temp_2 + 0x140;
    } else {
        var_20 = NULL;
    }
    temp_2_2 = func_001452b0(5);
    if (temp_2_2 != NULL) {
        var_19 = temp_2_2 + 0x150;
    } else {
        var_19 = NULL;
    }
    temp_2_3 = func_001452b0(5);
    if (temp_2_3 != NULL) {
        var_17 = temp_2_3 + 0x160;
    } else {
        var_17 = NULL;
    }
    temp_2_4 = func_001452b0(5);
    if (temp_2_4 != NULL) {
        var_18 = temp_2_4 + 0x1A0;
    } else {
        var_18 = NULL;
    }
    temp_2_5 = func_001452b0(5);
    if (temp_2_5 != NULL) {
        var_16 = temp_2_5 + 0x1B0;
    } else {
        var_16 = NULL;
    }
    temp_f0 = fGpffff8198;
    *(f32 *)(var_20 + 0) = temp_f0;
    *(f32 *)(var_20 + 4) = temp_f0;
    *(f32 *)(var_20 + 8) = temp_f0;
    *(s32 *)(var_20 + 0xC) = 0;
    *(s32 *)(var_19 + 0) = 0x3F000000;
    *(s32 *)(var_19 + 4) = 0x3F000000;
    *(s32 *)(var_19 + 8) = 0x3F000000;
    *(s32 *)(var_19 + 0xC) = 0;
    *(s32 *)(var_18 + 0) = 0;
    *(s32 *)(var_18 + 4) = 0;
    *(s32 *)(var_18 + 8) = 0;
    *(s32 *)(var_18 + 0xC) = 0;
    *(s32 *)(var_17 + 0x28) = 0x3F800000;
    *(s32 *)(var_17 + 0x14) = 0x3F800000;
    *(s32 *)(var_17 + 0) = 0x3F800000;
    *(s32 *)(var_17 + 0x10) = 0;
    *(s32 *)(var_17 + 8) = 0;
    *(s32 *)(var_17 + 4) = 0;
    *(s32 *)(var_17 + 0x24) = 0;
    *(s32 *)(var_17 + 0x20) = 0;
    *(s32 *)(var_17 + 0x18) = 0;
    *(s32 *)(var_17 + 0x38) = 0;
    *(s32 *)(var_17 + 0x34) = 0;
    *(s32 *)(var_17 + 0x30) = 0;
    *(s32 *)(var_17 + 0xC) |= 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    func_003e0870(var_17, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    func_003e0870(var_17, &stack[0], 2, -45.0f);
    *(s32 *)(var_16 + 0x28) = 0x3F800000;
    *(s32 *)(var_16 + 0x14) = 0x3F800000;
    *(s32 *)(var_16 + 0) = 0x3F800000;
    *(s32 *)(var_16 + 0x10) = 0;
    *(s32 *)(var_16 + 8) = 0;
    *(s32 *)(var_16 + 4) = 0;
    *(s32 *)(var_16 + 0x24) = 0;
    *(s32 *)(var_16 + 0x20) = 0;
    *(s32 *)(var_16 + 0x18) = 0;
    *(s32 *)(var_16 + 0x38) = 0;
    *(s32 *)(var_16 + 0x34) = 0;
    *(s32 *)(var_16 + 0x30) = 0;
    *(s32 *)(var_16 + 0xC) |= 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    func_003e0870(var_16, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    func_003e0870(var_16, &stack[0], 2, -45.0f);
}
// FUN_0014B450
s32 func_0014b450(void) {
    s32 var_3;
    u8 *temp_2;

    temp_2 = func_001452b0(0x14);
    var_3 = 0;
    if (temp_2 != NULL) {
        var_3 = *(s32 *)(temp_2 + 0x148);
    }
    return var_3;
}
// FUN_0014B490
s32 func_0014b490(void) {
    s32 var_3;
    u8 *temp_2;

    temp_2 = func_001452b0(0x14);
    var_3 = 0;
    if (temp_2 != NULL) {
        var_3 = *(s32 *)(temp_2 + 0x14C);
    }
    return var_3;
}
// FUN_0014B4D0
f32 func_0014b4d0(void) {
    f32 var_f0;
    u8 *temp_2;

    temp_2 = func_001452b0(0x14);
    var_f0 = 0.0f;
    if (temp_2 != NULL) {
        var_f0 = *(f32 *)(temp_2 + 0x144);
    }
    return var_f0;
}
// FUN_0014B510
s32 func_0014b510(s32 arg0)
{
    s32 var_17;
    s32 temp_16;
    u8 *var_2;

    var_17 = 0;
    temp_16 = arg0 & 0xFFFF;
    var_2 = func_001452b0(temp_16);
    while (var_2 != NULL) {
        if ((*(u16 *)var_2 & 0x3FF) == var_17) {
            var_17 += 1;
            var_2 = func_001452b0(temp_16);
        } else {
            var_2 = *(u8 **)(var_2 + 0x138);
        }
    }
    return var_17 & 0xFFFF;
}

// FUN_0014B590
f32 func_0014b590(f32 fparg0) {
    s32 integer;
    f32 result;

    integer = (s32)fparg0;
    result = (f32)integer;
    if (!((fparg0 - result) < 0.5f)) {
        result = (f32)(integer + 1);
    }
    return result;
}
// FUN_0014B780
s32 func_0014b780(u8 *arg0) {
    s32 temp_2;
    s32 temp_3;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)p;
    switch (temp_3) {
    case 0:
        if (func_004782b0(*(s32 *)(p + 8)) != 0) {
            *(s32 *)p = *(s32 *)p + 1;
        }
        goto done;
    case 1:
        temp_2 = *(s32 *)(p + 4) - 1;
        *(s32 *)(p + 4) = temp_2;
        if (temp_2 > 0) {
            goto done;
        }
        *(s32 *)p = *(s32 *)p + 1;
    case 2:
        func_004787e0(*(s32 *)(p + 8));
        return -1;
    default:
    done:
        return 0;
    }
}
// FUN_0014B840
void func_0014b840(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014BD90
s32 func_0014bd90(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) == 1;
}
/* measured: the archive uses a complete normal vector and three triangle pointers;
   416B/416B, four differing load/store words, no invented stack padding. */
// FUN_0014BE50 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014be50);
// FUN_0014C540
u8 *func_0014c540(u8 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    struct C540Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct C540Vec3 vec_x;
    struct C540Vec3 vec_y;
    f32 best;
    u8 *result;
    s32 i;
    u8 **saved_entry;
    u8 **entry;
    u8 *arg;
    u8 *temp_2;
    u8 *temp_2_2;
    struct C540Stack {
        struct C540Vec3 v80;
        struct C540Vec3 v8c;
        u8 pad98[8];
        s64 spA0;
        u8 padA8[8];
        f32 diffB0[3];
    } stack;
    extern s32 func_0016b540(void *arg0, s64 *arg1);
    extern s32 func_0014bff0(u8 *arg0, u8 *arg1, f32 fparg0);
    extern f32 fGpffff82b4;
    extern u8 *D_007E8020_abs[];

    arg = arg0;
    result = NULL;
    best = fGpffff82b4;
    i = 0;
    goto loop_test_0014c540;
loop_body_0014c540:
    saved_entry = (u8 **)(D_007E8020 + (i * 4));
    if (*saved_entry != 0) {
        if (func_0014bff0(func_0047a2f0(*(s32 *)(arg + 0x50)),
                          func_0047a2f0(*(s32 *)(*saved_entry + 0x50)) + 0x30,
                          fparg1) != 0) {
            entry = D_007E8020_abs + (u32)i;
            temp_f23 = *(f32 *)(func_0047a2f0(*(s32 *)(*entry + 0x50)) + 0x30);
            stack.diffB0[0] = temp_f23 -
                              *(f32 *)(func_0047a2f0(*(s32 *)(arg + 0x50)) + 0x30);
            temp_f23_2 = *(f32 *)(func_0047a2f0(*(s32 *)(*entry + 0x50)) + 0x34);
            stack.diffB0[1] = temp_f23_2 -
                              *(f32 *)(func_0047a2f0(*(s32 *)(arg + 0x50)) + 0x34);
            temp_f23_3 = *(f32 *)(func_0047a2f0(*(s32 *)(*entry + 0x50)) + 0x38);
            stack.diffB0[2] = temp_f23_3 -
                              *(f32 *)(func_0047a2f0(*(s32 *)(arg + 0x50)) + 0x38);
            temp_2 = func_0047a2f0(*(s32 *)(arg + 0x50));
            vec_x = *(struct C540Vec3 *)(temp_2 + 0x30);
            stack.v80 = vec_x;
            temp_2_2 = func_0047a2f0(*(s32 *)(*entry + 0x50));
            vec_y = *(struct C540Vec3 *)(temp_2_2 + 0x30);
            stack.v8c = vec_y;
            stack.v80.y += 100.0f;
            stack.v8c.y += 100.0f;
            if (func_0016b540(&stack.v80, &stack.spA0) == 0) {
                temp_f0 = func_003e4180(stack.diffB0);
                if ((temp_f0 < fparg0) && (temp_f0 < best)) {
                    result = *saved_entry;
                    best = temp_f0;
                }
            }
        }
    }
    i += 1;
loop_test_0014c540:
    if (i < 8) {
        goto loop_body_0014c540;
    }
    return result;
}
/* measured probe: optimization_level 1 on c780. */
#pragma optimization_level 1
// FUN_0014C780
s32 func_0014c780(void) {
    s32 index;
    s32 count;
    s32 sum;
    s32 hit;
    s32 valid;
    u8 *entry;

    sum = 0;
    index = 0;
    count = 0;
    goto loop_test_0014c780;
loop_body_0014c780:
    hit = 0;
    entry = D_007EF9B0 + (index * 0x750);
    if ((*(s32 *)(entry + 0x48) != 0) &&
        (*(s32 *)(entry + 0x54) != 0)) {
        hit = 1;
    }
    valid = hit != 0;
    if (valid == (hit = 1)) {
        if (index == 0) {
            sum += func_00104c70(hit) & 0xFF;
        } else {
            sum += *(s32 *)(entry + 0x1C0);
        }
        count += 1;
    }
    index += 1;
loop_test_0014c780:
    if (index < 4) {
        goto loop_body_0014c780;
    }
    return sum / count;
}
/* measured: restore optimization_level 2 after func_0014c780. */
#pragma optimization_level 2
// FUN_0014C850
s32 *func_0014c850(u8 *arg0, f32 fparg0, f32 fparg1) {
    u8 *temp_18;
    u8 *temp_19;
    s32 var_16;
    u8 *temp_2;

    var_16 = 0;
    goto loop_test_0014c850;
loop_body_0014c850:
    if (*(s32 *)temp_18 != 0) {
        if (func_0014c240(func_0047a2f0(*(s32 *)(arg0 + 0x50)),
                          temp_18 + 0x150, fparg1, fparg0) != 0) {
            return *(s32 **)temp_19;
        }
    }
    var_16 += 1;
loop_test_0014c850:
    temp_2 = D_007E8020 + (var_16 * 4);
    temp_19 = temp_2 + 0x20;
    temp_18 = *(u8 **)temp_19;
    if (temp_18 != NULL) {
        goto loop_body_0014c850;
    }
    return NULL;
}
// FUN_0014C920
void func_0014c920(void) {
    iGpffffb1f8 = 0;
    iGpffffb1fc = 0;
    func_0043f9c8(&D_007D24B0, 0, 0x30);
}
// FUN_0014C960
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014c960);
/* measured probe: opt_loop_invariants on hoists the 600.0f/1200.0f constants. */
#pragma opt_loop_invariants on
// FUN_0014CEF0
u8 *func_0014cef0(s32 arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_16;
    s32 temp_17;
    u8 *var_2;

    var_2 = func_001452b0(0xF);
    goto loop_test_0014cef0;
loop_body_0014cef0:
    temp_f0 = (600.0f + *(f32 *)(var_2 + 0x140)) / 1200.0f;
    temp_f0_2 = (600.0f + *(f32 *)(var_2 + 0x148)) / 1200.0f;
    temp_16 = (s32)temp_f0;
    temp_17 = (s32)temp_f0_2;
    if (((temp_16 == arg0) && (temp_17 == arg1)) ||
        ((temp_16 == (arg0 + 1)) && (temp_17 == arg1)) ||
        ((temp_16 == arg0) && (temp_17 == (arg1 + 1))) ||
        ((temp_16 == (arg0 + 1)) && (temp_17 == (arg1 + 1)))) {
        return var_2;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
loop_test_0014cef0:
    if (var_2 != NULL) {
        goto loop_body_0014cef0;
    }
    return NULL;
}
/* measured: restore opt_loop_invariants off after func_0014cef0. */
#pragma opt_loop_invariants off
// FUN_0014CFD0
s32 func_0014cfd0(u8 *arg0)
{
    s32 temp_21;
    s32 temp_20;
    u16 temp_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;
    s32 temp_19_2;
    s32 temp_16_2;
    s32 temp_3;
    u8 *var_19;
    extern u8 *func_00155280(void);
    {
        f32 temp_f2;

        temp_f2 = 600.0f;
        temp_f2 += *(f32 *)(arg0 + 0);
        var_18 = (s32)(temp_f2 / 1200.0f);
    }
    var_17 = (s32)((600.0f + *(f32 *)(arg0 + 8)) / 1200.0f);
    temp_16 = var_17 << 8;
    temp_21 = var_18 << 4;
    temp_19 = *(u16 *)(func_00155280() + temp_16 + temp_21 + 0x56);
    if ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 9) &&
        (*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 0xB) &&
        (*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 0xD)) {
        return 0;
    }
    if ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x55) & 0x20) == 0) {
        return 0;
    }
    temp_20 = temp_19;
    if ((temp_20 == *(u16 *)(func_00155280() + temp_16 + temp_21 + 0x46)) &&
        ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x45) & 0x20) != 0)) {
        var_18 -= 1;
    }
    temp_19_2 = var_18 * 0x10;
    if ((temp_20 == *(u16 *)(func_00155280() + temp_16 + temp_19_2 - 0xAA)) &&
        ((*(u8 *)(func_00155280() + temp_16 + temp_19_2 - 0xAB) & 0x20) != 0)) {
        var_17 -= 1;
    }
    var_19 = func_001452b0(3);
    goto loop_test_0014cfd0;
loop_body_0014cfd0:
    temp_16_2 = (s32)((600.0f +
                       *(f32 *)(func_0047a2f0(*(s32 *)(var_19 + 0x164)) + 0x30)) /
                      1200.0f);
    temp_3 = (s32)((600.0f +
                    *(f32 *)(func_0047a2f0(*(s32 *)(var_19 + 0x164)) + 0x38)) /
                   1200.0f);
    if (((temp_16_2 == var_18) && (temp_3 == var_17)) ||
        ((temp_16_2 == (var_18 + 1)) && (temp_3 == var_17)) ||
        ((temp_16_2 == var_18) && (temp_3 == (var_17 + 1))) ||
        ((temp_16_2 == (var_18 + 1)) && (temp_3 == (var_17 + 1)))) {
        return 1;
    }
    var_19 = *(u8 **)(var_19 + 0x138);
loop_test_0014cfd0:
    if (var_19 != NULL) {
        goto loop_body_0014cfd0;
    }
    return 0;
}
// FUN_0014D290
void func_0014d290(u8 *arg0, u8 *arg1)
{
    extern void func_003bb5b0(u8 *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);
    extern s32 func_003bb330(u8 *arg0);
    extern void func_003bb3a0(u8 *arg0, s32 arg1, void *arg2);
    extern void func_0045f790(void *arg0, void *arg1, void *arg2, s32 arg3);
    extern void func_004601c0(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern f32 D_005EFBB8[];
    extern u8 D_005EFBBC[];
    extern u8 D_005EFBBD[];
    extern u8 D_005EFBBE[];
    extern u8 D_005EFBBF[];
    extern u8 D_005EFBC0[];
    extern u8 D_005EFBC1[];
    extern u8 D_005EFBC2[];
    extern u8 D_005EFBC3[];
    f32 sp40[3];
    f32 sp30[3];
    P4Bytes0014 sp4C;
    s32 var_16;
    s32 var_16_2;
    s32 temp_3;
    f32 temp_f0;
    f32 temp_f1;

    var_16 = 0;
    while (var_16 < *(s32 *)(arg1 + 4)) {
        temp_3 = *(s32 *)(arg1 + 4);
        func_003bb5b0(*(u8 **)(arg1 + 0xC), 0xA, sp40, 0,
                      (1.0f / (f32)temp_3) * (f32)var_16);
        temp_f0 = (f32)*(s32 *)(arg1 + 4);
        temp_f1 = p4_0014_recip(temp_f0);
        func_003bb5b0(*(u8 **)(arg1 + 0xC), 0xA, sp30, 0,
                      temp_f1 * (f32)(var_16 + 1));
        func_0045f790(sp40, sp30, arg1 + 8, 1);
        var_16 += 1;
    }
    var_16_2 = 0;
    while (var_16_2 < func_003bb330(*(u8 **)(arg1 + 0xC))) {
        if (var_16_2 == 1) {
            *(f32 *)&sp4C = D_005EFBB8[0];
        } else if (var_16_2 == (func_003bb330(*(u8 **)(arg1 + 0xC))) - 2) {
            sp4C = *(P4Bytes0014 *)D_005EFBBC;
        } else {
            sp4C = *(P4Bytes0014 *)D_005EFBC0;
        }
        func_003bb3a0(*(u8 **)(arg1 + 0xC), var_16_2, sp40);
        func_004601c0(sp40, &sp4C, 1, 5.0f);
        var_16_2 += 1;
    }
}
// FUN_0014D470
s32 func_0014d470(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014d290;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x110), obj);
    return 0;
}

// FUN_0014D4E0
void func_0014d4e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014D7D0
void func_0014d7d0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014D9E0
void func_0014d9e0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014DCD0
void func_0014dcd0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44) = arg1;
}

// FUN_0014DCE0
void func_0014dce0(u8 *arg0, u8 *arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(Rgba8_0014 *)(p + 0x48) = *(Rgba8_0014 *)arg1;
}
// FUN_0014DD10
void func_0014dd10(u8 *arg0, u8 *arg1) {
    f32 sp20[4];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(SVec3 *)(temp_16 + 0x30) = *(SVec3 *)arg1;
    RwEngineGetMatrixTolerances(&sp20[0]);
    RwMatrixOptimize(temp_16, &sp20[0]);
    RwMatrixUpdate(temp_16);
}



/* measured probe: opt_propagation off preserves 0014dd80 vtable and float stores. */
#pragma opt_propagation off
// FUN_0014DD80
void func_0014dd80(u8 *arg0, u8 *arg1) {
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 0);
    base[0](7, 2);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](2, 3);
    base[0](0xC, 1);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    if (*(s32 **)(arg1 + 0x100) != NULL) {
        *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x108);
        *(f32 *)(arg1 + 0x14) = *(f32 *)(arg1 + 0x10C);
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x110);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x10C);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x108);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x114);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x110);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x114);
        base[0](1, *(u32 *)(*(s32 **)(arg1 + 0x100)));
        return;
    }
    base[0](1, 0);
}
/* measured probe: restore opt_propagation after 0014dd80. */
#pragma opt_propagation on
// FUN_0014DEF0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014def0);
// FUN_0014E2A0
s32 func_0014e2a0(u8 *arg0) {
    extern s32 func_004553c0(u8 *arg0);
    extern s32 func_00455f70(u8 *arg0, s32 *arg1);
    extern void func_00454bd0(u8 *arg0);
    extern s32 func_004b1190();
    extern void func_004b11d0();
    extern void func_004b1150();
    extern u8 D_005DC7D0[];
    s32 sp5C;
    u8 *temp_18;
    s32 temp_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_19;
    u8 *temp_2;
    u8 *temp_5;
    s32 *temp_10;
    s32 *temp_11;

    temp_18 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_18 + 0);
    switch (temp_3) {
    case 0:
        if (*(s32 *)(temp_18 + 0xC) == 0) {
            if (func_004553c0(*(u8 **)(temp_18 + 4)) != 0) {
                temp_2 = *(u8 **)(temp_18 + 4);
                if (temp_2 != NULL) {
                    *(s32 *)(temp_18 + 0x14) =
                        func_004b1130(*(s32 *)(temp_2 + 0x110));
                    func_00454bd0(*(u8 **)(temp_18 + 4));
                    *(u8 **)(temp_18 + 4) = NULL;
                }
                goto block_10;
            }
        } else {
            *(s32 *)(temp_18 + 0x14) =
                func_004b1130(func_00455f70(temp_18 + 0xBC, &sp5C));
block_10:
            *(s32 *)(temp_18 + 0) = *(s32 *)(temp_18 + 0) + 1;
        }
    case 1:
        goto block_31;
    case 2:
        temp_4 = *(s32 *)(temp_18 + 0x10);
        if ((temp_4 == 0) && (*(s32 *)(temp_18 + 0x20) == 0)) {
            *(s32 *)(temp_18 + 0) = 1;
        } else {
            if ((temp_4 == 1) &&
                (*(s32 *)(temp_18 + 0x74) != 1) &&
                (*(s32 *)(temp_18 + 0x98) != 1)) {
                if ((u32)*(u32 *)(temp_18 + 0x18) <
                    (u32)*(u32 *)(temp_18 + 8)) {
                    func_004b1190(*(s32 *)(temp_18 + 0x14));
                    func_004b11d0(
                        (s32)&D_005DC7D0 +
                        (*(u16 *)(temp_18 + 0x1C) * 0x54),
                        *(s32 *)(temp_18 + 0x14));
                    *(u32 *)(temp_18 + 0x18) =
                        *(u32 *)(temp_18 + 0x18) + 1;
                } else {
                    *(s32 *)(temp_18 + 0x10) = 0;
                }
            }
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_5 = temp_18 + (var_19 * 4);
            if ((*(s32 *)(temp_5 + 0x78) != 1) &&
                (*(s32 *)(temp_5 + 0x9C) != 1)) {
                temp_10 = (s32 *)(temp_5 + 0x24);
                temp_4_2 = *(s32 *)(temp_5 + 0x24);
                if (temp_4_2 != 0) {
                    temp_11 = (s32 *)(temp_5 + 0x44);
                    if ((u32)*(u32 *)(temp_5 + 0x44) <
                        (u32)*(u32 *)(temp_18 + 8)) {
                        func_004b1190(temp_4_2);
                        func_004b11d0(
                            (s32)&D_005DC7D0 +
                            (*(u16 *)(temp_18 + var_19 * 2 + 0x64) *
                             0x54),
                            *temp_10);
                        *temp_11 = *temp_11 + 1;
                    } else {
                        func_004b1150(temp_4_2);
                        *temp_10 = 0;
                        *(s32 *)(temp_18 + 0x20) =
                            *(s32 *)(temp_18 + 0x20) - 1;
                    }
                }
            }
            var_19 += 1;
loop_test:
            while (var_19 < 8) {
                goto loop_body;
            }
            goto block_31;
        }
        goto block_31;
    case 3:
        return -1;
    default:
block_31:
        return 0;
    }
}
// FUN_0014E540
void func_0014e540(u8 *arg0) {
    s32 i;
    u8 *p;
    s32 temp_4;

    p = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 8; i++) {
        temp_4 = *(s32 *)(p + i * 4 + 0x24);
        if (temp_4 != 0) {
            func_004b1150(temp_4);
        }
    }
    temp_4 = *(s32 *)(p + 0x14);
    if (temp_4 != 0) {
        func_004b1150(temp_4);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0014E5E0
s32 func_0014e5e0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&iGpffff9de0, 0xC2);
    temp_2 = D_008873F4[0](1, 0xFC, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_17 = (s32)func_00451fc0(arg0, &D_005EFC18, 0xF, 0, 0,
                                  (void *)func_0014e2a0,
                                  (void *)func_0014e540, temp_2);
    if (arg3 == 0) {
        func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
        *(s32 *)(temp_2 + 4) = (s32)func_00454a60(arg1, 0);
    } else {
        *(s32 *)(temp_2 + 4) = arg3;
        *(s32 *)(temp_2 + 0xC) = 1;
    }
    *(s32 *)(temp_2 + 8) = arg2;
    func_00442830(temp_2 + 0xBC, (const char *)arg1);
    return temp_17;
}
// FUN_0014E710
s32 func_0014e710(u8 *arg0) {
    if (arg0 == NULL) {
        return 1;
    }
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) >= 1;
}
/* measured probe: optimization level 1 register allocation for func_0014e740. */
#pragma optimization_level 1
// FUN_0014E740
s32 func_0014e740(u8 *arg0, f32 *arg1) {
    s32 temp_20;
    s32 temp_4;
    u8 *temp_19;
    s32 temp_2;
    s32 temp_3;
    s32 var_17;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_17 = -1;
    if (*(s32 *)(temp_16 + 0x10) == 1) {
        var_17 = 0;
        goto loop_test_4;
loop_body_4:
        if (*(s32 *)(temp_16 + (var_17 * 4) + 0x24) == 0) {
            goto loop_done_4;
        }
        var_17 += 1;
loop_test_4:
        if (var_17 < 8) {
            goto loop_body_4;
        }
loop_done_4:
        if (var_17 >= 8) {
            func_0046d730(&iGpffff9de0, 0x100);
        }
        temp_20 = var_17 * 4;
        temp_19 = p4_e740_add(temp_20, temp_16) + 0x24;
        temp_2 = func_004b11b0(*(s32 *)(temp_16 + 0x14));
        *(s32 *)temp_19 = temp_2;
        func_004b1250(temp_2, (u8 *)arg1);
        *(s32 *)(p4_e740_add(temp_20, temp_16) + 0x44) = 0;
        temp_3 = 1;
        *(s16 *)(p4_e740_add(var_17 * 2, temp_16) + 0x64) = temp_3;
        *(s32 *)(temp_16 + 0x20) = *(s32 *)(temp_16 + 0x20) + 1;
    } else {
        func_004b1170(*(s32 *)(temp_16 + 0x14));
        func_004b1250(*(s32 *)(temp_16 + 0x14), (u8 *)arg1);
        *(s32 *)(temp_16 + 0x18) = 0;
        temp_4 = 1;
        *(s32 *)(temp_16 + 0x10) = temp_4;
        *(s16 *)(temp_16 + 0x1C) = temp_4;
    }
    *(s32 *)temp_16 = 2;
    return var_17;
}
/* measured probe: restore optimization level 2 after func_0014e740. */
#pragma optimization_level 2
// FUN_0014E880
void func_0014e880(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 >= 0) {
        if (*(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x24) != 0) {
            *(s16 *)(p4_00141cf0_add((u32)(arg1 * 2), temp_4) + 0x64) = arg2;
        }
    } else {
        *(s16 *)(temp_4 + 0x1C) = arg2;
    }
}
// FUN_0014E8C0
s32 func_0014e8c0(u8 *arg0, s32 arg1) {
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 >= 0) {
        return *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_3) + 0x44);
    }
    return *(s32 *)(temp_3 + 0x18);
}
// FUN_0014E8F0
void func_0014e8f0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == -1) {
        *(s32 *)(temp_4 + 0x74) = arg2;
        return;
    }
    *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x78) = arg2;
}
// FUN_0014E920
void func_0014e920(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == -1) {
        *(s32 *)(temp_4 + 0x98) = arg2;
        return;
    }
    *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x9C) = arg2;
}
// FUN_0014E950
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014e950);
// FUN_0014EC20
void func_0014ec20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EC50
s32 func_0014ec50(u8 *arg0, s32 arg1) {
    extern s32 func_0014e950(u8 *arg0, s32 arg3);
    extern s32 func_00454a60(const void *arg0, s32 arg1);
    extern u8 D_005EFC40[];
    u8 **allocator_table;
    u8 *temp_2_2;
    s32 result;
    u8 *temp_2;
    u8 *header;
    func_0044ea90(&iGpffff9de0, 0x2DF);
    allocator_table = (u8 **)D_008873F4;
    temp_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0x50, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    header = D_005EFC28;
    result = (s32)func_00451fc0(arg0, header, 0xF, 0, 0,
                                 (void *)func_0014e950,
                                 (void *)func_0014ec20, temp_2);
    *(s32 *)(temp_2 + 4) = arg1;
    if (arg1 == 0) {
        func_0044ea90(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)func_00451fc0((u8 *)result, &D_005EFC18, 0xF, 0, 0,
                                      (void *)func_0014e2a0,
                                      (void *)func_0014e540, temp_2_2);
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = func_00454a60(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x53;
            func_00442830(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    } else if (arg1 == 1) {
        func_0044ea90(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)func_00451fc0((u8 *)result, &D_005EFC18, 0xF, 0, 0,
                                      (void *)func_0014e2a0,
                                      (void *)func_0014e540, temp_2_2);
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = func_00454a60(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x32;
            func_00442830(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    }
    return result;
}
// FUN_0014EEC0
s32 func_0014eec0(void) {
    return D_007642F0;
}
