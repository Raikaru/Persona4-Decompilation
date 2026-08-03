#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00452560(void);
extern void func_00454bd0(u8 *ptr);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void func_0045d6e0(void *, void *, f32, s32);
extern void func_0025f230(u32 param_1);
extern void func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, s32, s32);
extern void func_002a6650(void *, void *);
extern void func_002a6680(s32);
extern void func_002aa2b0(void *arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                        s32 (*arg5)(s32), s32 (*arg6)(s32), u8 *arg7);
extern void func_003f6440(s32, s32);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025ef20(const void *);
extern s32 func_0025f110(s32);
extern s32 func_004553c0(s32);
extern s32 func_00454a60(const char *path, s32 flags);
extern void func_00440b68(const void *, ...);
extern void func_004659f0(void *);
extern void func_0025e8b0(s32);
extern s32 func_0025e800(s32, s32, s32);
extern void *func_0010d7c0(s32, s32 *, s32);
extern void func_0043f810(void *, void *, s32);
extern void func_00464650(s32, void *, s32);
extern void func_00466260(s32);
extern char D_0063EB90[];
extern char D_0063EBB0[];
extern char D_0063EBD0[];
extern char D_0063EB20[];
extern char D_0063ED38[];
extern char D_00763900;
extern void func_00149680(s32);
extern s32 func_002a4570(u8 *);
extern s32 func_002a4d10(s32);
extern s32 func_002a73c0(s32, u8 *, u8 *, s32);
extern s32 func_002a5630(s32);
extern s32 func_002a5f00(s32);
extern void func_00453670(void *, s32, s32, s32, s32);
extern void func_004538e0(void *, s32, s32, s32, s32);
extern void func_00453ff0(void *, s32);
extern void func_004537e0(void *, s32);
extern s32 func_00453960(void *);
extern void func_00453760(void *, s32);
extern s32 func_00453dc0(void *);
extern s32 func_00453d70(void *);
extern void func_0045af60(s32, s32, s32, s32);
extern void *memset(void *dst, s32 value, u32 size);
extern char D_00796370[];
extern void (*D_008873EC[])(void *);
extern u8 *(*D_008873F4[])(s32, s32, s32);
typedef int (*RwRenderStateSetFunc)(s32, s32);
extern f32 D_00763910;
extern s32 D_00764634;
extern s32 D_00764638;
extern char D_007638F8;
extern char D_00763918;
typedef struct { u64 lo, hi; } Qword;
extern Qword D_0063ED70;
extern f32 D_00761184;
extern f32 D_00761174;
extern f32 iGpffff8214;
extern f32 iGpffff8218;
extern f32 iGpffff821c;
extern f32 iGpffff8030;
extern s32 func_0043c6a0(u32 arg0);
extern void func_002a7920(s8, u8 *, s32, s32, u8 *, f32, f32, f32, f32);
extern void func_002a9f50(s32, u8 *, s32, s32, u8 *, f32, f32, f32);
extern void func_002a6b10(s32, s32, s32, void *);
extern void func_002a7710(s32, u8 *);
extern void func_002a6b60(s32, s32, s32, u8 *);
extern void func_002a6c30(s32, s32, s32, u8 *);
extern void func_002a6960(s32, s32, s32, s32, f32);
extern void func_002a6e30(s32, s32, s32, u8 *);
extern s32 D_0063ED80[];
extern f32 func_0044b610(f32);
extern f32 func_0044b7b0(f32);
extern f32 iGpffff81e0;
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045dfd0(void *, void *, f32, s32, s32, s32);
extern void func_002a66d0(f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_0045ed60(void *, void *, s32, f32);
typedef struct { s32 a, b, c, d; } Quad4;
extern RwRenderStateSetFunc D_00887300[4];
extern char D_0063EBF0[];
extern char D_0063EB50[];
extern char D_0063EB70[];
extern char D_0063EC10[];
extern char D_0063EC30[];
extern char D_0063EC50[];
extern char D_0063EC70[];
extern char D_0063EC90[];
extern char D_0063ECB0[];
extern char D_0063ECD0[];
extern char D_0063ECF0[];
extern char D_0063ED20[];
extern s32 func_00465a10(s32);
extern s32 func_0025e8f0(s32);
extern void func_004653f0(void);
extern s32 func_00465400(void);
extern s32 func_00466280(s32);
extern s32 func_004647c0(void);
extern void func_004647a0(void);
extern void func_004647b0(void);
extern void func_00465570(s32, s32, s32);
extern s32 func_00465590(void);
extern void func_0010e710(s32, s32, s32);
extern s32 func_0010e880(s32, s32, s32);
extern u16 D_008C024E[];
extern s32 func_00110580(s32);
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 func_00110d30(s32 idx);
extern s32 func_0025f2c0(s32, s32, u8 *);
extern u8 *D_0063EA68;
extern s32 D_0063EA60[];
extern void func_00442088(void *, void *, s32, ...);
extern void func_0025f6b0(f32, f32, f32, s32, u8, void *, s32, void *, void *, s32);
extern s32 func_00275020(s32, s32, s32, void *, s32, s32, f32, f32, f32);
extern s16 D_0063EB30[];
extern char iGpffffa824;
extern void func_002a2e10(void);
extern void func_002a9100(f32, f32, f32, s32, s32, s32, s32, u8 *);
extern void func_002a95c0(s32, s32, s32, u8 *, u8 *, f32, f32, f32);
extern s32 func_003b7060(s32);
extern s32 D_0063EDB0[];
extern s32 D_0063EDD0[];
extern f32 D_00761300;

// FUN_002A2E50
void func_002a2e50(u8 *arg0, s32 arg1) {
    s32 v;
    s32 t19;
    u8 *p18;
    s32 p17;
    u8 *p;
    s32 sp6C;

    *(s32 *)(arg0 + 8) = arg1;
    *(s32 *)(arg0 + 0xC) = 0;
    v = *(s32 *)(arg0 + 8);
    switch (v) {
    case 0:
        func_0043f9c8(arg0 + 0x14, 0, 0x380);
        func_004659f0(arg0 + 0x14);
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xF);
        func_00440b68(&D_0063EB90);
        return;
    case 1:
        func_00466260(*(s32 *)(arg0 + 0x3AC));
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    case 2:
        t19 = *(s32 *)(arg0 + 0x3AC);
        p18 = (u8 *)func_0010d7c0(0, &sp6C, 0);
        p17 = sp6C;
        func_0044ea90(&D_007638F8, 0x16D);
        p = D_008873F4[0](1, 0x38008, 0x40000);
        *(s32 *)(p + 4) = (s32)(p + 8);
        if (p18 != NULL && p17 != 0) {
            func_0043f810((void *)*(s32 *)(p + 4), p18, p17);
            *(s32 *)p = p17;
        }
        D_008873EC[0](p18);
        func_00464650(t19, (void *)*(s32 *)(p + 4), *(s32 *)p);
        *(s32 *)(arg0 + 0x39C) = (s32)p;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xF);
        func_00440b68(&D_0063EBB0);
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    case 3:
        func_00440b68(&D_0063EBD0);
        *(s32 *)(arg0 + 0xC) = 0x10;
        return;
    }
}

// FUN_002A3070
s32 func_002a3070(u8 *arg0) {
    s32 v;
    s32 r;
    s32 var_16;

    var_16 = 0;
    v = *(s32 *)(arg0 + 0xC);
    switch (v) {
    case 0:
        switch (r = func_00465a10(v)) {
        case 100:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            func_00440b68(&D_0063EBF0);
            return 1;
        case -2:
            *(s32 *)(arg0 + 0xC) = 1;
            func_00440b68(&D_0063EC10);
            func_0043f9c8(arg0 + 0x14, 0, 0x380);
            break;
        case -1:
        case -3:
        case -4:
        case -5:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            func_00440b68(&D_0063EC30, r);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        default:
            break;
        }
        break;
    case 0xA:
        *(s32 *)(arg0 + 0xC) = 0xB;
        func_004653f0();
        /* fallthrough */
    case 0xB:
        r = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (r != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (r != 0) {
            var_16 = 1;
        }
        r = func_00465400();
        switch (r) {
        case -2:
        case 3:
            return 3;
        }
        if (var_16 != 0) {
            return 4;
        }
        break;
    case 1:
        *(s32 *)(arg0 + 0xC) = 2;
        *(s32 *)(arg0 + 0x3A8) = 0;
        /* fallthrough */
    case 2:
        v = *(s32 *)(arg0 + 0x3A8) + 1;
        *(s32 *)(arg0 + 0x3A8) = v;
        if (v >= 0xF) {
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            return 1;
        }
        break;
    }
    return 0;
}


// FUN_002A32C0
s32 func_002a32c0(u8 *arg0) {
    s32 v;
    s32 r;

    v = *(s32 *)(arg0 + 0xC);
    switch (v) {
    case 0:
        switch (r = func_00466280(v)) {
        case 100:
            func_00440b68(&D_0063EC50);
            return 1;
        case -6:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 6);
            func_00440b68(&D_0063EC70);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        case -1:
        case -4:
        case -5:
        case -9:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            func_00440b68(&D_0063EC30, 0);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        default:
            break;
        }
        break;
    case 0xA:
        *(s32 *)(arg0 + 0xC) = 0xB;
        /* fallthrough */
    case 0xB:
        r = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (r != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (r != 0) {
            *(s32 *)(arg0 + 0xC) = 0xC;
        }
        break;
    case 0xC:
        *(s32 *)(arg0 + 0xC) = 0xD;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 8);
        /* fallthrough */
    case 0xD:
        r = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (r != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (r != 0) {
            return 4;
        }
        break;
    }
    return 0;
}


// FUN_002A34E0
s32 func_002a34e0(u8 *arg0) {
    s32 var_17;
    u8 *temp_16;
    s32 v;
    s32 t;
    s32 idx;

    v = *(s32 *)(arg0 + 0xC);
    switch (v) {
    case 0:
        temp_16 = *(u8 **)(arg0 + 0x39C);
        switch (var_17 = func_004647c0()) {
        case 100:
            D_008873EC[0](temp_16);
            break;
        case 1:
            func_00440b68(&D_0063EB50);
            var_17 = 1;
            break;
        case 2:
            func_00440b68(&D_0063EB70);
            var_17 = 2;
            break;
        case -1:
        case -3:
        case -4:
        case -5:
        case -6:
        case -7:
            break;
        }
        switch (var_17) {
        case 100:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 9);
            func_00440b68(&D_0063EC90);
            *(s32 *)(arg0 + 0xC) = 9;
            if (arg0 == NULL) {
                func_0046d730(&D_007638F8, 0xE3);
            }
            D_00764638 = *(s32 *)(arg0 + 0x3AC);
            break;
        case 1:
            *(s32 *)(arg0 + 0xC) = 3;
            break;
        case 2:
            func_00440b68(&D_0063EC10);
            *(s32 *)(arg0 + 0xC) = 5;
            break;
        case 4:
            func_00440b68(&D_0063ECB0);
            *(s32 *)(arg0 + 0x10) &= ~1;
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 7);
            break;
        case 5:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 7);
            break;
        case -5:
            func_00440b68(&D_0063EC30, var_17);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        case -3:
            func_00440b68(&D_0063EC30, var_17);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        case -6:
            func_00440b68(&D_0063EC30, var_17);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 6);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        case -4:
            idx = *(s32 *)(arg0 + 0x3AC) * 4;
            *(s32 *)(idx + (s32)arg0 + 0x14) = 2;
            /* fallthrough */
        case -7:
            func_00440b68(&D_0063EC30, var_17);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0x16);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        case 0:
            break;
        }
        break;
    case 3:
        *(s32 *)(arg0 + 0xC) = 4;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 4);
        func_004653f0();
        /* fallthrough */
    case 4:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        switch (t) {
        case 1:
            *(s32 *)(arg0 + 0xC) = 0;
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 7);
            func_004647a0();
            break;
        case 2:
            D_008873EC[0](*(void **)(arg0 + 0x39C));
            return 2;
        }
        t = func_00465400();
        switch (t) {
        case -5:
        case 3:
            func_00440b68(&D_0063EC30, t);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        }
        break;
    case 5:
        *(s32 *)(arg0 + 0xC) = 6;
        *(s32 *)(arg0 + 0x10) |= 1;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 1);
        func_004653f0();
        /* fallthrough */
    case 6:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        switch (t) {
        case 1:
            *(s32 *)(arg0 + 0xC) = 0;
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 2);
            func_004647b0();
            break;
        case 2:
            return 2;
        }
        t = func_00465400();
        switch (t) {
        case -5:
        case 3:
            func_00440b68(&D_0063EC30, t);
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 0xA;
            break;
        }
        break;
    case 9:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (t != 0) {
            return 1;
        }
        break;
    case 10:
        *(s32 *)(arg0 + 0xC) = 0xB;
        func_004653f0();
        /* fallthrough */
    case 11:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (t != 0) {
            *(s32 *)(arg0 + 0xC) = 0xC;
        }
        t = func_00465400();
        switch (t) {
        case -2:
        case 3:
            *(s32 *)(arg0 + 0xC) = 0xC;
            break;
        }
        break;
    case 12:
        *(s32 *)(arg0 + 0xC) = 0xD;
        func_004653f0();
        if (*(s32 *)(arg0 + 0x10) & 1) {
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 3);
        } else {
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 8);
        }
        *(s32 *)(arg0 + 0x10) &= ~1;
        D_008873EC[0](*(void **)(arg0 + 0x39C));
        /* fallthrough */
    case 13:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (t != 0) {
            return 4;
        }
        t = func_00465400();
        switch (t) {
        case -2:
        case 3:
            return 4;
        }
        break;
    }
    return 0;
}


/* measured: retail materializes the func_0010e880/0010e710 args as
   [lw p[4]] [lw p[0]] [addiu a2,p[0]-4] [lw a0,sp4C] [addiu a1,p[4]+4]; mwcc
   b210 emits arg order left-to-right interleaving each load with its addiu
   ([lw p[4]] [addiu a1] [lw p[0]] [addiu a2] [lw a0]), 6 words per call site
   (nd 12). The D_008873EC base hoist WAS matched via a `void *ec` local
   (setState pattern, nd 81 -> 12); only this arg-order scheduling remains.
   Argument-evaluation-order floor. */
// FUN_002A3D80
INCLUDE_ASM("asm/nonmatchings/mc", func_002a3d80);
// FUN_002A4390
s32 func_002a4390(s32 arg0) {
    typedef struct {
        u8 pad[4];
        u32 flags; /* 0x04 */
        u8 pad2[0x3A4];
        s32 f3AC; /* 0x3AC */
        s32 f3B0; /* 0x3B0 */
        u8 pad3[4];
        s32 f3B8; /* 0x3B8 */
    } McWork;
    u8 buf[0x30];
    McWork *w = (McWork *)arg0;
    s32 v;

    func_00453670(buf, 0x10, 0x10, w->f3AC, w->f3B0);
    func_004538e0(buf, 0x4000, 0x1000, 0, 0);
    func_00453ff0(buf, 0);
    func_004537e0(buf, 0);
    v = func_00453960(buf);
    switch (v) {
    case 1:
    case 3:
        w->flags |= 0x2000;
        w->f3B8 = 0xA;
        func_0045af60(0, 0, 0, 0);
        break;
    case 2:
    case 4:
        w->flags |= 0x1000;
        w->f3B8 = 0xA;
        func_0045af60(0, 0, 0, 0);
        break;
    default:
        func_00453760(buf, 0);
        break;
    }
    w->f3AC = func_00453dc0(buf);
    w->f3B0 = func_00453d70(buf);
    if (w->f3AC == 0) {
        w->flags &= ~0x4000;
    } else {
        w->flags |= 0x4000;
    }
    if (w->f3AC == 0xF) {
        w->flags &= ~0x8000;
    } else {
        w->flags |= 0x8000;
    }
    w->flags |= 0x80000;
    return 0;
}

/* measured: retail's 14-entry jump-table dispatch keeps the switch value in
   $v0 and the table base in $v1 (lh; sltiu; lui/addiu; sll; addu; lw; jr);
   mwcc b210 colors the same dispatch value into $v1 and the base into $a1,
   9 words (nd 9). Everything else in the function matches byte-for-byte.
   Tried: inline switch, s32/s16/u32 locals with (s16)/(s32)/(u32) casts,
   three declaration orders, explicit empty cases 0xA/0xC, single shared
   result variable -- all nd 9. Register-allocation floor ($v0/$v1 coloring),
   not source-drivable. */
// FUN_002A4570
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4570);
// FUN_002A4B10
s32 func_002a4b10(s32 arg0) {
    u8 *w = func_00452560();

    switch (*(s16 *)(w + 0)) {
    case 0:
        *(s16 *)(w + 0) = 3;
        /* fallthrough */
    case 3:
        *(s16 *)(w + 0) = 4;
        *(u32 *)(w + 0x398) = func_0025ef20(D_0063EB20);
        func_00440b68(&D_00763900, &D_007638F8, 0x47E);
        *(u32 *)(w + 0x3A4) = func_00454a60(D_0063ED38, 1);
        *(u32 *)(w + 0x568) = 0;
        *(u32 *)(w + 4) |= 0x400;
        /* fallthrough */
    case 4:
        if (func_0025f110(*(u32 *)(w + 0x398)) == 0) {
            break;
        }
        if (func_004553c0(*(u32 *)(w + 0x3A4)) == 0) {
            break;
        }
        *(s16 *)(w + 0) = 5;
        *(u32 *)(w + 4) |= 1;
        break;
    case 5:
        if (*(u32 *)(w + 4) & 0x400) {
            break;
        }
        func_00149680(1);
        *(s16 *)(w + 0) = 6;
        /* fallthrough */
    case 6:
        if (func_002a4570(w) == 0) {
            break;
        }
        func_00149680(0);
        *(s16 *)(w + 0) = 7;
        break;
    case 7:
        if (*(u32 *)(w + 4) & 0x40000) {
            break;
        }
        *(s16 *)(w + 0) = 8;
        /* fallthrough */
    case 8:
        return -1;
    }
    func_002a6680(arg0);
    return 0;
}

// FUN_002A4CB0
void func_002a4cb0(void) {
    u8 *work = func_00452560();
    s32 p = *(s32 *)(work + 0x3A4);
    if (p != 0) {
        func_00454bd0((u8 *)p);
        *(s32 *)(work + 0x3A4) = 0;
    }
    func_0025f230(*(u32 *)(work + 0x398));
    func_002aa2b0(work);
}

/* measured: retail hoists `addiu $a0, $sp, 0x5C` (the &sp50[3] arg for
   func_0045d6e0) between the two sp50 stores; mwcc b210 sinks the address
   materialization to just before the jal, shifting 31 words (nd 62). Tried:
   direct &sp50[3], local pointer assigned at the store point, `*(&sp50[3]) =
   D`, and #pragma schedule on (which fills delay slots retail leaves empty).
   All give nd 62 except schedule on (worse, nd > 100). Load-sinking floor. */
// FUN_002A4D10
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4d10);

/* measured: retail colors p->$s1, s16->$s0, s18->$s2, s19->$s3, s20(loop)->$s4,
   s21->$s5, f21->$f21, f20->$f20, f23->$f23, f22->$f22; mwcc b210 graph-colors
   a cyclic rotation (p->$s3, s16->$s4, s18->$s0, s19->$s1, s20->$s1, f21->$f22)
   and merges s19/s20 into one register. Tried all six saved-reg declaration
   orders and the mul.s operand-order split; all nd 332. Saved-register rotation
   floor. */
// FUN_002A4F20
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4f20);

/* measured: the func_0025f430 call site materializes its args with FPU
   accumulator instructions adda.s $f12,$f0 / madd.s $f13,$f1,$f21 (COP1 MAC
   writing $f12/$f13), which mwcc b210 cannot emit from plain C; and the
   surrounding body is the same item-loop family as func_002a4f20/5f00 which
   both floor on saved-register rotation. FPU-accumulator idiom + rotation
   floor. */
// FUN_002A5630
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5630);

/* measured: retail colors p->$s0, s17->$s1, s18->$s2, s19->$s3, s20->$s4; mwcc
   b210 graph-colors a cyclic rotation (p->$s2, s17->$s0, s18->$s1, s20->$s0,
   loop-s18->$s4) and the loop's s18 = s17+s19-3 reuses a different register
   than retail. Tried p first/last, all five saved-reg declaration orders, and
   the two-statement mul.s (value-in-fs) fix (that one landed); best nd 81.
   Saved-register rotation floor. */
// FUN_002A5F00
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5f00);

// FUN_002A6510
s32 func_002a6510(s32 arg0) {
    u8 *work = func_00452560();
    s32 flags = *(u32 *)(work + 4);

    if (!(flags & 1)) {
        return 0;
    }
    if (flags & 0x400) {
        if (func_002a4d10(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x400;
            *(u32 *)(work + 4) |= 0x20000;
        }
        return 0;
    }
    if (flags & 0x20000) {
        if (func_002a4f20(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x20000;
        }
        return 0;
    }
    if (flags & 0x40000) {
        if (func_002a5630(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x40000;
        }
        return 0;
    }
    func_002a5f00(arg0);
    return 0;
}

// FUN_002A6680
void func_002a6680(s32 arg0) {
    u8 *work = func_00460990();
    *(void **)(work + 8) = func_002a6650;
    *(void **)(work + 0x10) = (void *)arg0;
    func_00460ac0(&D_00796370, work);
}

// FUN_002A66D0
void func_002a66d0(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4,
                   s32 arg0, s32 arg1, s32 arg2) {
    typedef struct { f32 a, b; } V2;
    void *setState;
    V2 arr[0x29];
    u8 colors[0x29][4];
    s32 i;
    s32 p;
    s32 m0, m1, m2, m3;
    f32 f21, f20;
    f32 x;
    f32 *slot;
    u8 *col;

    arr[0].a = fparg0;
    arr[0].b = fparg1;
    p = (arg0 << 8) | arg1;
    m0 = (p >> 24) & 0xFF;
    colors[0][0] = p >> 24;
    m1 = (p >> 16) & 0xFF;
    colors[0][1] = p >> 16;
    m2 = (p >> 8) & 0xFF;
    colors[0][2] = p >> 8;
    m3 = p & 0xFF;
    colors[0][3] = p;
    i = 1;
    f21 = fparg3 / 2.0f;
    f20 = fparg4 / 2.0f;
    while (i < 0x28) {
        x = iGpffff81e0 * (f32)(i - 1) / 39.0f;
        slot = &arr[i].a;
        slot[0] = fparg0 + f21 * func_0044b610(x);
        slot[1] = fparg1 + f20 * -func_0044b7b0(x);
        col = &colors[i][0];
        col[0] = m0;
        col[1] = m1;
        col[2] = m2;
        col[3] = m3;
        i++;
    }
    arr[i] = arr[1];
    colors[i][0] = m0;
    colors[i][1] = m1;
    colors[i][2] = m2;
    colors[i][3] = m3;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(1, 0);
    if (arg1 == 0xFF && !(arg2 & 2)) {
        func_00364c50();
    }
    if (!(arg2 & 4)) {
        func_0045dfd0(&colors[0][0], &arr[0].a, fparg2, 0x29, 5, arg2 & 1);
    } else {
        func_0045dfd0(&colors[1][0], &arr[1].a, fparg2, 0x28, 2, arg2 & 1);
    }
    if (arg1 == 0xFF && !(arg2 & 2)) {
        func_00364c70();
    }
}

// FUN_002A6960
void func_002a6960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    void *setState;
    f32 sp5C;
    f32 sp58;
    Quad4 sp40;
    Quad4 sp30;
    u8 *p;
    s32 n;
    u8 *p2;
    s32 n2;

    p = (u8 *)&sp58;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    sp5C = sp58;
    p2 = (u8 *)&sp30;
    n2 = 0x10;
    if (p2 != NULL) {
        do {
            *p2 = 0;
            p2++;
            n2--;
        } while (n2 != 0);
    }
    sp30.a = arg0;
    sp30.b = arg1;
    sp30.c = arg2;
    sp30.d = arg3;
    sp40 = sp30;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(0xE, 0);
    (*(void (**)(u32, u32))setState)(0xC, 1);
    (*(void (**)(u32, u32))setState)(7, 2);
    (*(void (**)(u32, u32))setState)(9, 1);
    (*(void (**)(u32, u32))setState)(0x14, 1);
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp5C, &sp40, fparg0, 0);
    func_0048a000();
}

// FUN_002A6AF0
s32 func_002a6af0(u8 *arg0) {
    s32 idx = *(s32 *)(arg0 + 0x3AC) * 4;
    return *(s32 *)(idx + (s32)arg0 + 0x14);
}

// FUN_002A6B10
void func_002a6b10(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    typedef union { f32 f; u8 b[4]; } U4;
    U4 u;
    Qword q;
    U4 *pu = &u;

    pu->f = D_00763910;
    pu->b[3] = (u8)arg2;
    q = D_0063ED70;
    if (arg2 != 0) {
        func_0045d6e0(pu, &q, 0.0f, 1);
    }
}

// FUN_002A6B60
void func_002a6b60(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    if (arg2 != 0) {
        if (*(s32 *)(arg3 + 4) & 2) {
            func_0025f3f0((f32)(arg0 + 0x1C0), (f32)(arg1 + 0xC), 0.0f, 0xFFFFFF, arg2 & 0xFF, 0x3D, 0, *(s32 *)(arg3 + 0x398), 1);
        } else {
            func_0025f3f0((f32)(arg0 + 0x19A), (f32)(arg1 + 0xC), 0.0f, 0xFFFFFF, arg2 & 0xFF, 0x39, 0, *(s32 *)(arg3 + 0x398), 1);
        }
    }
}

// FUN_002A6C30
void func_002a6c30(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 v;
    f32 f;

    if (arg2 != 0) {
        if (*(s32 *)(arg3 + 4) & 0x80000) {
            v = *(s32 *)(arg3 + 0x3D0);
            if (v < 5) {
                *(s32 *)(arg3 + 0x3D0) = v + 1;
            }
        } else {
            v = *(s32 *)(arg3 + 0x3D0);
            if (v > 0) {
                *(s32 *)(arg3 + 0x3D0) = v - 1;
            }
        }
        f = ((f32)*(s32 *)(arg3 + 0x3D0) / 5.0f) * (f32)arg2;
        v = (s32)f;
        func_0025f3f0((f32)(arg0 + 0x1F5), (f32)(arg1 + 0x19B), 0.0f, 0xFFFFFF, v, 0x24, 0, *(s32 *)(arg3 + 0x398), 1);
        func_0025f3f0((f32)(arg0 + 0x207), (f32)(arg1 + 0x19D), 0.0f, 0xFFFFFF, v, 0x27, 0, *(s32 *)(arg3 + 0x398), 1);
        func_0025f3f0((f32)(arg0 + 0x22C), (f32)(arg1 + 0x19B), 0.0f, 0xFFFFFF, v, 0x25, 0, *(s32 *)(arg3 + 0x398), 1);
        func_0025f3f0((f32)(arg0 + 0x23E), (f32)(arg1 + 0x19D), 0.0f, 0xFFFFFF, v, 0x28, 0, *(s32 *)(arg3 + 0x398), 1);
        *(s32 *)(arg3 + 4) &= 0xFFF7FFFF;
    }
}

// FUN_002A6E30
void func_002a6e30(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    void func_002a66d0(s32, s32, s32, f32, f32, f32, f32, f32);
    typedef struct { s32 a, b; } I8;
    f32 f1, f3;
    f32 f23, f22, f21, f20, f24;
    s32 v;
    s32 i;
    I8 *p6;
    I8 *p5;
    s32 n;
    f32 *q;
    f32 sp70[0xC];
    u8 spAC[4];

    if (*(s32 *)(arg3 + 4) & 0x4000) {
        v = *(s32 *)(arg3 + 0x3C8);
        if (v < 0xA) {
            *(s32 *)(arg3 + 0x3C8) = v + 1;
        }
    } else {
        v = *(s32 *)(arg3 + 0x3C8);
        if (v > 0) {
            *(s32 *)(arg3 + 0x3C8) = v - 1;
        }
    }
    if (*(s32 *)(arg3 + 4) & 0x8000) {
        v = *(s32 *)(arg3 + 0x3CC);
        if (v < 0xA) {
            *(s32 *)(arg3 + 0x3CC) = v + 1;
        }
    } else {
        v = *(s32 *)(arg3 + 0x3CC);
        if (v > 0) {
            *(s32 *)(arg3 + 0x3CC) = v - 1;
        }
    }
    f20 = func_0044b7b0(D_00761184 * (f32)*(s32 *)(arg3 + 0x3C8) / 10.0f);
    f21 = func_0044b7b0(D_00761184 * (f32)*(s32 *)(arg3 + 0x3CC) / 10.0f);
    if (*(s32 *)(arg3 + 4) & 0x1000) {
        *(s32 *)(arg3 + 0x3C0) = 0xA;
        *(s32 *)(arg3 + 4) &= ~0x1000;
    }
    if (*(s32 *)(arg3 + 4) & 0x2000) {
        *(s32 *)(arg3 + 0x3C4) = 0xA;
        *(s32 *)(arg3 + 4) &= ~0x2000;
    }
    f23 = func_0044b7b0(D_00761174 * (f32)*(s32 *)(arg3 + 0x3C0) / 10.0f);
    f22 = func_0044b7b0(D_00761174 * (f32)*(s32 *)(arg3 + 0x3C4) / 10.0f);
    v = *(s32 *)(arg3 + 0x3C0);
    if (v > 0) {
        *(s32 *)(arg3 + 0x3C0) = v - 1;
    }
    v = *(s32 *)(arg3 + 0x3C4);
    if (v > 0) {
        *(s32 *)(arg3 + 0x3C4) = v - 1;
    }
    p6 = (I8 *)D_0063ED80;
    p5 = (I8 *)sp70;
    n = 6;
    do {
        v = p6->a;
        i = p6->b;
        p6++;
        n--;
        p5->a = v;
        p5->b = i;
        p5++;
    } while (n > 0);
    f1 = 1.0f - f20;
    f20 = -70.0f * f1;
    f24 = -30.0f * f1;
    func_002a66d0(0xFFAE20, arg2, 1, (f32)(arg0 + 0x15) + f24, (f32)(arg1 - 4) + f20, 0.0f, 108.0f, 100.0f);
    i = 0;
    f3 = (f32)(arg0 + 0xB) + f24;
    f1 = f20 + ((f32)(arg1 + 0x14) - 3.0f * f23);
    for (; i < 3; i++) {
        q = sp70 + i * 2;
        q[0] += f3;
        q[1] += f1;
    }
    spAC[0] = 0xFF;
    spAC[1] = 0xF2;
    spAC[2] = 0x3D;
    spAC[3] = (u8)arg2;
    func_0045ed60(spAC, sp70, 1, 0.0f);
    f1 = 1.0f - f21;
    f20 = 70.0f * f1;
    f21 = 30.0f * f1;
    func_002a66d0(0xFFAE20, arg2, 1, (f32)(arg0 + 0x95) + f21, (f32)(arg1 + 0x1D1) + f20, 0.0f, 108.0f, 100.0f);
    i = 0;
    f3 = (f32)(arg0 + 0x83) + f21;
    f1 = f20 + ((f32)(arg1 + 0x1AB) + 3.0f * f22);
    for (; i < 3; i++) {
        q = sp70 + i * 2;
        q[6] += f3;
        q[7] += f1;
    }
    spAC[0] = 0xFF;
    spAC[1] = 0xF2;
    spAC[2] = 0x3D;
    spAC[3] = (u8)arg2;
    func_0045ed60(spAC, &sp70[6], 1, 0.0f);
}

// FUN_002A7330
s32 func_002a7330(u8 *arg0) {
    s32 i = 0;
    while (i < 0x14) {
        if (!(*(u32 *)arg0 & 1)) {
            func_0043f9c8(arg0, 0, 0x14);
            *(u32 *)arg0 |= 1;
            return (s32)arg0;
        }
        arg0 += 0x14;
        i++;
    }
    return 0;
}

/* measured: saved-register rotation on the 4-saved-reg prologue -- retail
   colors arg2->$s0, arg1->$s1, arg2[4]->$s2, v->$s3; mwcc b210 always emits
   v->$s0, arg2->$s1, arg1->$s2 (+arg2[4] wherever), with the sp60 index
   folded into the lw instead of a separate addiu (nd 158). Tried with and
   without the preloaded arg2[4] local, 3 local declaration orders, pointer
   vs index copy loops -- the rotation never aligns. The first 4 copy-loop
   instructions, the state checks and the 66d0 call all match. Saved-register
   rotation floor. */
// FUN_002A73C0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a73c0);
// FUN_002A7710
void func_002a7710(s32 arg0, u8 *arg1) {
    s32 i;
    u8 *work;
    u8 *p;
    u8 *q;

    work = arg1 + 0x3D4;
    if (arg0 != 0) {
        p = work;
        for (i = 0; i < 0x14; i++) {
            if ((*(u32 *)p & 1) && func_002a73c0((s32)arg1, work, p, arg0) != 0) {
                func_0043f9c8(p, 0, 0x14);
            }
            p += 0x14;
        }
        if (*(u32 *)(work + 0x190) == 0) {
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 0;
                *(f32 *)(q + 8) = (f32)0x329;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 5;
            }
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 1;
                *(f32 *)(q + 8) = (f32)0x265;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 0x64;
            }
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 2;
                *(s32 *)(q + 8) = 0x440E0000;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 0x96;
            }
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 4;
                *(s32 *)(q + 8) = 0x43B40000;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 0x82;
            }
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 6;
                *(s32 *)(q + 8) = 0x43360000;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 0x50;
            }
            q = (u8 *)func_002a7330(work);
            if (q != NULL) {
                *(s32 *)(q + 4) = 7;
                *(s32 *)(q + 8) = 0x42FC0000;
                *(s32 *)(q + 0xC) = 0;
                *(s16 *)(q + 0x12) = 0;
            }
            *(s32 *)(work + 0x190) += 1;
        }
    }
}

/* measured: the float-to-arg0 color conversion uses the FPU accumulator idiom
   adda.s $f1,$f2 / madd.s $f2,$f3,$f0 (COP1 MAC writing accumulator regs),
   which mwcc b210 cannot emit from plain C; the overflow guard 0x4F000000
   around the (f32)(s32) conversion is likewise not reproducible. Same
   FPU-accumulator idiom as func_002a5630. FPU-accumulator floor. */
// FUN_002A7920
INCLUDE_ASM("asm/nonmatchings/mc", func_002a7920);

/* measured: nd 845 with a full C body (object 1232B against a 1216B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_002A9100
INCLUDE_ASM("asm/nonmatchings/mc", func_002a9100);

/* measured: retail frame is 0x140 with saved regs $s0-$s5 + f20-f23; mwcc b210
   over-allocates the frame to 0x180, mis-allocates saved regs ($s6/$s7/$fp
   garbage) and the D_00887300 render-vtable base is hoisted into two different
   saved regs ($21 then $16) across the two call groups. Tried the parent
   advisory's #pragma opt_propagation off + typed base local for the vtable
   hoist, all callee arg orders (incl. func_0025f6b0/5f3f0 floats-first), and the
   struct-field stack layout; best nd 657 with frame over-alloc. Frame +
   saved-register rotation floor. */
// FUN_002A95C0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a95c0);

/* measured: cyclic saved-register rotation in the 5-int/3-float prologue --
   retail colors arg0->$s0, arg1->$s4, arg2->$s3, arg4->$s2; mwcc b210 always
   emits arg2->$s0, arg1->$s3, arg0->$s4 (arg4->$s2 stable) regardless of
   signature order (tried FP-first and interleaved signatures, 3 local
   declaration orders, single-expr vs split p, if/else vs ternary color, all
   nd 162-181). Scheduler residuals ride along: the `color >>= 8` lands at
   the call site instead of right after the OR, `add.s` operands are
   transposed for `fparg0 + const`, and the func_002a95c0 call materializes
   int args before float args. The float-param-first signature DID fix the
   FP move order (mov.s f22/f21/f20 before the int moves). Saved-register
   rotation floor. */
// FUN_002A9F50
INCLUDE_ASM("asm/nonmatchings/mc", func_002a9f50);
// FUN_002AA2B0
void func_002aa2b0(void *arg0) {
    typedef struct { u8 pad[0x3A4]; s32 handle; } Work;
    Work *work = arg0;
    if (work->handle != 0) {
        func_00454bd0((u8 *)work->handle);
        work->handle = 0;
    }
    D_008873EC[0](work);
}
// FUN_002AA300
void func_002aa300(s32 arg0, s32 arg1) {
    u8 *work;

    D_00764634 = 0;
    func_0044ea90(&D_007638F8, 0x8FF);
    work = D_008873F4[0](1, 0x56C, 0x40000);
    if (work == NULL) {
        func_0046d730(&D_007638F8, 0xE8);
    }
    *(s32 *)(work + 0x3AC) = D_00764638;
    *(s32 *)(work + 0x3B4) = D_00764638 << 16;
    *(u16 *)(work + 0) = 0;
    *(u16 *)(work + 2) = 0;
    if (arg1 == 1) {
        *(u32 *)(work + 4) |= 2;
    }
    func_00451fc0((u8 *)arg0, &D_00763918, 0xF, 0, 0, (s32 (*)(s32))func_002a4b10,
                 (s32 (*)(s32))func_002a4cb0, work);
}
