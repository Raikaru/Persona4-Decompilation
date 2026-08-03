/* Consolidated Persona 4 source units. */
/* Original translation unit btlCutin.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern u8 *iGpffffb3ac;
extern void func_00485b20();
extern u8 *func_00194470();
extern s32 func_001fa370();
extern void func_0043f810();
extern void func_001f9cf0();
extern s32 func_001f9fa0();
extern s32 func_004553c0();
extern s32 func_00484bb0();
extern void func_00454bd0();
extern s32 func_004b1520();
extern void func_00485630();
extern void func_00485870();
extern void *func_00481450();
extern void func_00481440();
extern u8 D_005DC8CC[];
extern u8 D_00625190[];
extern u8 D_00625090[];
extern u8 D_006251C0[];
extern u8 iGpffffa528;
extern u8 iGpffffa530;
extern s32 func_001060b0();
extern s32 func_00110d60();
extern s32 func_00106330();
extern s32 func_00120e20();
extern void func_00442088();
extern void func_00440b68();
extern s32 func_00454a60();
extern u8 iGpffffa520;
extern u8 D_00625050[];
extern u8 D_00625060[];
extern u8 D_006250A0[];
extern u8 D_006250D0[];
extern u8 D_00625100[];
extern u8 D_00625130[];
extern u8 D_00625160[];


/* measured: retail keeps the case-0 base pointer (iGpffffa520 + temp_5*4) in $s2
   and the loaded arg0+8 s16 in $s1; mwcc b210 emits them swapped (temp_17->$s2,
   temp_18->$s1) when temp_17 is assigned first, and reversed ORDER (temp_18
   computed before the lh) when temp_18 is assigned first. Declaration-order
   swaps, s32-pointee vs s32 address typing, and a temp_6 intermediate for temp_17+1 all
   leave nd 8 (register swap) or nd 4 (instruction-order swap); it is a coupled
   register/order floor, not a declaration-order fix. obj exactly matches the
   688B window apart from this. */
// FUN_001F9CF0
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001f9cf0);

// FUN_001F9FA0
s32 func_001f9fa0(void) {
    s32 var_18;
    s32 var_17;
    s32 temp_16;

    var_17 = 1;
    for (var_18 = 0; var_18 < 4; var_18++) {
        u8 *temp_4 = *(u8 **)((u32)var_18 * 4 + (u32)iGpffffb3ac + 0xB6C);
        if (temp_4 != NULL) {
            if (func_004553c0(temp_4) != 0) {
                if (!(*(s32 *)(iGpffffb3ac + 0xB4C) & 1)) {
                    temp_16 = var_18 * 4;
                    *(s32 *)(iGpffffb3ac + temp_16 + 0xB5C) = func_00484bb0(*(s32 *)(*(u8 **)(iGpffffb3ac + temp_16 + 0xB6C) + 0x110));
                }
                temp_16 = var_18 * 4;
                func_00454bd0(*(u8 **)(iGpffffb3ac + temp_16 + 0xB6C));
                *(u8 **)(iGpffffb3ac + temp_16 + 0xB6C) = 0;
            } else {
                var_17 = 0;
            }
        }
    }
    if (var_17 != 0 && func_004553c0(*(u8 **)(iGpffffb3ac + 0xB58)) != 0) {
        s32 temp_3_2 = *(s32 *)(iGpffffb3ac + 0xB4C);
        if (!(temp_3_2 & 1)) {
            *(s32 *)(iGpffffb3ac + 0xB54) = func_00484bb0(*(s32 *)(*(u8 **)(iGpffffb3ac + 0xB58) + 0x110));
        } else {
            *(s32 *)(iGpffffb3ac + 0xB4C) = temp_3_2 & ~1;
        }
        func_00454bd0(*(u8 **)(iGpffffb3ac + 0xB58));
        *(u8 **)(iGpffffb3ac + 0xB58) = 0;
        return 1;
    }
    return 0;
}

// FUN_001FA110
u8 *func_001fa110(s32 arg0) {
    u8 *p = func_00194470(0xC00, 0xA);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x68) = (void *)func_001f9cf0;
    *(void **)(p + 0x6C) = (void *)func_001f9fa0;
    func_0043f810(*(s32 **)(p + 0x78), arg0, 0xA);
    return p;
}

// FUN_001FA190
s32 func_001fa190(s32 *arg0) {
    u8 *temp_17;
    s32 temp_19;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;
    s32 var_20;

    var_20 = 1;
    temp_17 = func_00481450();
    func_00481440(&D_005DC8CC);
    for (var_16 = 0; var_16 < 4; var_16++) {
        temp_4 = *(s32 *)((u32)var_16 * 4 + (u32)iGpffffb3ac + 0xB5C);
        if (temp_4 != 0) {
            if (func_004b1520(temp_4) == 0) {
                temp_19 = var_16 * 4;
                func_00485630(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                func_00485870(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                var_20 = 0;
            } else {
                temp_19 = var_16 * 4;
                func_00485b20(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                *(s32 *)(iGpffffb3ac + temp_19 + 0xB5C) = 0;
            }
        }
    }
    temp_4_2 = *(s32 *)(iGpffffb3ac + 0xB54);
    if (temp_4_2 != 0) {
        if (func_004b1520(temp_4_2) == 0) {
            func_00485630(*(s32 *)(iGpffffb3ac + 0xB54));
            func_00485870(*(s32 *)(iGpffffb3ac + 0xB54));
            var_20 = 0;
        } else {
            func_00485b20(*(s32 *)(iGpffffb3ac + 0xB54));
            *(s32 *)(iGpffffb3ac + 0xB54) = 0;
        }
    }
    func_00481440(temp_17);
    *arg0 += 1;
    return var_20;
}

// FUN_001FA320
void func_001fa320(void) {
    u8 *p = func_00194470(0xC01, 4);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)func_001fa190;
    **(s32 **)(p + 0x78) = 0;
}

// FUN_001FA370
s32 func_001fa370(void) {
    s32 i;
    s32 off;
    u8 *base;
    u8 *p;
    s32 h;

    for (i = 0; i < 4; i++) {
        base = iGpffffb3ac;
        off = i * 4;
        p = base + off;
        if (*(s32 *)(p + 0xB6C) != 0) {
            *(s32 *)(base + 0xB4C) |= 1;
        } else {
            h = *(s32 *)(p + 0xB5C);
            if (h != 0) {
                func_00485b20(h);
                *(s32 *)(iGpffffb3ac + off + 0xB5C) = 0;
            }
        }
    }
    base = iGpffffb3ac;
    if (*(s32 *)(base + 0xB58) != 0) {
        *(s32 *)(base + 0xB4C) |= 1;
    } else {
        h = *(s32 *)(base + 0xB54);
        if (h != 0) {
            func_00485b20(h);
            *(s32 *)(iGpffffb3ac + 0xB54) = 0;
        }
    }
    return 1;
}

// FUN_001FA450
void func_001fa450(void) {
    u8 *p = func_00194470(0xC02, 0);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)func_001fa370;
}

// FUN_001FA490
void func_001fa490(u8 *arg0) {
    struct { s16 a; s16 b; } sp12;
    char sp20[0x10C];
    s32 temp_5;
    u16 temp_4;

    temp_5 = (func_00110d60((s16)func_001060b0()) & 1) != 0;
    temp_4 = *(u16 *)arg0;
    switch (temp_4) {
    case 1:
        func_00442088(&sp20, &D_00625190, *(s16 *)(arg0 + 2), *(s32 *)(&iGpffffa530 + temp_5 * 4));
        func_00440b68(&iGpffffa528, &D_00625090, 0x152);
        *(s32 *)(iGpffffb3ac + 0xB84) = func_00454a60(&sp20, 0);
        break;
    case 3:
        func_00442088(&sp20, &D_006251C0, *(s16 *)(arg0 + 2), *(s32 *)(&iGpffffa530 + temp_5 * 4));
        func_00440b68(&iGpffffa528, &D_00625090, 0x158);
        *(s32 *)(iGpffffb3ac + 0xB84) = func_00454a60(&sp20, 0);
        break;
    case 5:
        if (func_00106330(0x38, temp_5) != 0) {
            sp12.a = 5;
            if (func_00110d60((s16)func_001060b0()) & 1) {
                sp12.b = 0x1E;
            } else {
                sp12.b = 0x14;
            }
        } else {
            sp12.a = 8;
            sp12.b = 0x1E;
        }
        *(s32 *)(iGpffffb3ac + 0xB88) = func_00120e20(*(s32 *)(iGpffffb3ac + 0xDC8), *(s32 *)&sp12);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB7C) = *(u16 *)arg0;
}
