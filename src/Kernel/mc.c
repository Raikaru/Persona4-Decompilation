#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

/* The SDK getter requires the callback task and returns a packed address. */
extern u32 func_00452560(void *task);
extern void H_Cdvd_Destroy(u8 *ptr);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void func_0045d6e0(void *, void *, f32, s32);
extern void func_0025f230(u32 param_1);
extern s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
extern void func_002a6650(void *, void *);
extern void func_002a6680(s32);
extern void func_002aa2b0(void *arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, u32 line);

extern void RpSkyRenderStateSet(s32, s32);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025ef20(const void *);
extern s32 func_0025f110(s32);
extern s32 H_Cdvd_IsFileLoaded(s32);
extern s32 func_00454a60(const char *path, s32 flags);
extern void func_00440b68(const void *, ...);
extern void func_004659f0(void *);
extern void func_0025e8b0(s32);
extern s32 func_0025e800(s32, s32, s32);
extern u8 *func_0010d7c0(s32, s32 *, s32);
extern void memcpy(void *, void *, s32);
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
extern void *memset(void *dst, s32 value, u32 size);
extern char D_00796370[];
extern void (*D_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
typedef int (*RwRenderStateSetFunc)(s32, s32);
extern f32 D_00763910;
extern s32 D_00764634;
extern s32 D_00764638;
extern char D_007638F8;
extern char D_00763918;
typedef struct { u64 lo, hi; } Qword;
extern Qword D_0063ED70;
static inline f32 mc_add(f32 a, f32 b) { return a + b; }
extern f32 D_00761184;
extern f32 D_00761174;
extern f32 iGpffff8214;
extern f32 iGpffff8218;
extern f32 iGpffff821c;
extern f32 iGpffff8030;
extern s32 func_0043c6a0(u32 arg0);
extern void func_002a7920(u8, u8 *, s32, s32, u8 *, f32, f32, f32, f32);
extern void func_002a9f50(f32, f32, f32, s32, u8 *, s32, s32, u8 *);
extern void func_002a6b10(s32, s32, s32, void *);
extern void func_002a7710(s32, u8 *);
extern void func_002a6b60(s32, s32, s32, u8 *);
extern void func_002a6c30(s32, s32, s32, u8 *);
extern void func_002a6960(s32, s32, s32, s32, f32);
extern void func_002a6e30(s32, s32, s32, u8 *);
extern s32 D_0063ED80[];
extern f32 cosf(f32);
extern f32 sinf(f32);
extern f32 iGpffff81e0;
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045dfd0(void *, void *, f32, s32, s32, s32);
extern void func_002a66d0(f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_0045ed60(void *, void *, s32, f32);
typedef struct { s32 a, b, c, d; } Quad4;
typedef struct { s32 x, y, width, height; } McRect;
extern f32 iGpffffa818;
extern f32 iGpffffa81c;
extern McRect D_0063ED50;
extern McRect D_0063ED60;
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
extern void func_0010e710(s32, u8 *, s32);
extern s32 func_0010e880(s32, u8 *, s32);
extern u16 D_008C024E[];
extern s32 func_00110580(s32);
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 func_00110d30(s32 idx);
extern s32 func_0025f2c0(s32, s32, u8 *);
extern u8 *D_0063EA68;
extern s32 D_0063EA60[];
extern void sprintf(void *, void *, s32, ...);
typedef void (*McGlyphCallback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
extern void func_0025f6b0(f32, f32, f32, s32, u8, void *, s32, void *, McGlyphCallback, u8 *);

extern s16 D_0063EB30[];
extern char iGpffffa824;
extern void func_002a2e10(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
extern void func_002a9100(f32, f32, f32, s32, s32, u8 *, s32, u8 *);
extern void func_002a95c0(f32, f32, f32, s32, s32, s32, u8 *, u8 *);
extern u32 RpRandom(void);
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
        memset(arg0 + 0x14, 0, 0x380);
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
        p18 = func_0010d7c0(0, &sp6C, 0);
        p17 = sp6C;
        func_0044ea90(&D_007638F8, 0x16D);
        p = D_008873F4[0](1, 0x38008, 0x40000);
        *(s32 *)(p + 4) = (s32)(p + 8);
        if (p18 != NULL && p17 != 0) {
            memcpy((void *)*(s32 *)(p + 4), p18, p17);
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
            memset(arg0 + 0x14, 0, 0x380);
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


/* 1544/1552 bytes; 67 resolved text relocations, twelve exact jump-table
 * entries, and eight zero alignment bytes. The payload's byte-pointer ABI
 * preserves retail's load/load/count/version/pointer argument schedule.
 * Cache only the deallocator slot address, not its callback or work pointer. */
// FUN_002A3D80
s32 func_002a3d80(s32 address) {
    u8 *arg0 = (u8 *)address;
    s32 v;
    s32 t;
    s32 file;
    u8 *p;
    s32 ok;
    s32 sp4C;
    s32 sp48;
    void *ec;
    u8 *temporary;

    v = *(s32 *)(arg0 + 0xC);
    switch (v) {
    case 16:
        *(s32 *)(arg0 + 0xC) = 0x11;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xB);
        func_004653f0();
        /* fallthrough */
    case 17:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        switch (t) {
        case 1:
            if (*(s32 *)(arg0 + 0x394) != 0) {
                func_0025e8b0(*(s32 *)(arg0 + 0x394));
                *(s32 *)(arg0 + 0x394) = 0;
            }
            *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xC);
            *(s32 *)(arg0 + 0xC) = 0x12;
            break;
        case 2:
            return 2;
        }
        t = func_00465400();
        switch (t) {
        case 0:
            break;
        case -5:
        case 3:
            func_00440b68(D_0063EC30, t);
            return 4;
        }
        break;
    case 18:
        *(s32 *)(arg0 + 0xC) = 0x13;
        file = *(s32 *)(arg0 + 0x3AC);
        func_0044ea90(&D_007638F8, 0x16D);
        p = D_008873F4[0](1, 0x38008, 0x40000);
        *(u8 **)(p + 4) = p + 8;
        func_00465570(file, *(s32 *)(p + 4), (s32)p);
        *(u8 **)(arg0 + 0x39C) = p;
        /* fallthrough */
    case 19:
        t = func_00465590();
        if (t == 0) {
            break;
        }
        if (t == -3 || t == -5) {
            goto read_failed;
        }
        switch (t) {
        case 100:
            p = *(u8 **)(arg0 + 0x39C);
            sp4C = 0;
            temporary = func_0010d7c0(0, &sp48, 0);
            ec = D_008873EC;
            (*(void (**)(void *))ec)(temporary);
            memcpy(&sp4C, *(void **)(p + 4), 4);
            if (func_0010e880(sp4C, *(u8 **)(p + 4) + 4, *(s32 *)p - 4) == 0) {
                ok = 0;
            } else {
                func_0010e710(sp4C, *(u8 **)(p + 4) + 4, *(s32 *)p - 4);
                ok = 1;
            }
            (*(void (**)(void *))ec)(*(void **)(arg0 + 0x39C));
            if (ok != 0) {
                func_00440b68(D_0063ECD0);
                *(s32 *)(arg0 + 0xC) = 0x14;
                if (arg0 == NULL) {
                    func_0046d730(&D_007638F8, 0xE3);
                }
                D_00764638 = *(s32 *)(arg0 + 0x3AC);
            } else {
                func_00440b68(D_0063ECF0);
                *(s32 *)(arg0 + 0xC) = 0x16;
            }
            break;
        case -4:
            func_00440b68(D_0063ED20);
            *(s32 *)(arg0 + 0xC) = 0xE;
            D_008873EC[0](*(void **)(arg0 + 0x39C));
            break;
        default:
read_failed:
            func_00440b68(D_0063ED20);
            *(s32 *)(arg0 + 0xC) = 0xC;
            D_008873EC[0](*(void **)(arg0 + 0x39C));
            break;
        }
        break;
    case 20:
        *(s32 *)(arg0 + 0xC) = 0x15;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xD);
        /* fallthrough */
    case 21:
        t = func_0025e8f0(*(s32 *)(arg0 + 0x394));
        if (t != 0) {
            *(s32 *)(arg0 + 0x394) = 0;
        }
        if (t != 0) {
            return 1;
        }
        break;
    case 22:
        *(s32 *)(arg0 + 0xC) = 0x17;
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0x14);
        func_004653f0();
        /* fallthrough */
    case 23:
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
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0xE);
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
            func_00440b68(D_0063EC30, t);
            return 4;
        }
        break;
    case 14:
        *(s32 *)(arg0 + 0xC) = 0xF;
        func_004653f0();
        if (*(s32 *)(arg0 + 0x394) != 0) {
            func_0025e8b0(*(s32 *)(arg0 + 0x394));
            *(s32 *)(arg0 + 0x394) = 0;
        }
        *(s32 *)(arg0 + 0x394) = func_0025e800(0, 0, 0x16);
        /* fallthrough */
    case 15:
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
            func_00440b68(D_0063EC30, t);
            return 4;
        }
        break;
    }
    return 0;
}

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
/* Wave-14 re-test: fresh m2c-sourced body (with the shared block_31 goto
   restored and func_002a2e50(arg0, n) calls) gives nd 278 — the m2c register
   allocation is far worse than the recorded nd 9. The m2c body is not a usable
   base; the previous nd-9 body must be reconstructed by hand. Dispatch
   register coloring ($v0 value / $v1 base) remains the known floor. */
// FUN_002A4570
s32 func_002a4570(u8 *work) {
    s32 value;
    s32 result;

    result = 0;
    switch (*(s16 *)(work + 2)) {
    case 1:
        *(u32 *)(work + 4) |= 0x40000;
        result = 1;
        goto return_result;
    case 0:
        *(s16 *)(work + 2) = 2;
        goto return_zero;
    case 2:
        *(s16 *)(work + 2) = 3;
        func_002a2e50(work, 0);
        /* fallthrough */
    case 3:
        result = 0;
        value = *(s32 *)(work + 8);
        switch (value) {
        case 0:
            result = func_002a3070(work);
            break;
        case 1:
            result = func_002a32c0(work);
            break;
        case 2:
            result = func_002a34e0(work);
            break;
        case 3:
            result = func_002a3d80((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            *(s16 *)(work + 2) = 4;
            break;
        case 3:
            *(s16 *)(work + 2) = 2;
            break;
        case 4:
            *(s16 *)(work + 2) = 1;
            break;
        default:
            break;
        }
        goto return_zero;
    case 4:
        *(s16 *)(work + 2) = 5;
        /* fallthrough */
    case 5:
        *(s16 *)(work + 2) = 6;
        func_004653f0();
        /* fallthrough */
    case 6:
        func_002a4390((s32)work);
        if (D_008C024E[0] & 0x40) {
            if (*(u32 *)(work + 4) & 2) {
                *(s16 *)(work + 2) = 7;
                func_0045af60(0, 0, 0, 1);
            } else if (func_002a6af0(work) == 1) {
                *(s16 *)(work + 2) = 0xC;
                func_0045af60(0, 0, 0, 1);
            } else {
                func_0045af60(0, 0, 0, 8);
            }
        } else if (D_008C024E[0] & 0x20) {
            *(s16 *)(work + 2) = 1;
            func_0045af60(0, 0, 0, 2);
            goto return_zero;
        }
        value = func_00465400();
        switch (value) {
        case 100:
        case -1:
        case -2:
            break;
        case 3:
        case -4:
        case -5:
            *(s16 *)(work + 2) = 2;
            break;
        }
        goto return_zero;
    case 7:
        *(s16 *)(work + 2) = 8;
        func_002a2e50(work, 1);
        /* fallthrough */
    case 8:
        result = 0;
        value = *(s32 *)(work + 8);
        switch (value) {
        case 0:
            result = func_002a3070(work);
            break;
        case 1:
            result = func_002a32c0(work);
            break;
        case 2:
            result = func_002a34e0(work);
            break;
        case 3:
            result = func_002a3d80((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            *(s16 *)(work + 2) = 9;
            break;
        case 4:
            *(s16 *)(work + 2) = 2;
            break;
        }
        goto return_zero;
    case 9:
        *(s16 *)(work + 2) = 0xB;
        func_002a2e50(work, 2);
        /* fallthrough */
    case 0xB:
        result = 0;
        value = *(s32 *)(work + 8);
        switch (value) {
        case 0:
            result = func_002a3070(work);
            break;
        case 1:
            result = func_002a32c0(work);
            break;
        case 2:
            result = func_002a34e0(work);
            break;
        case 3:
            result = func_002a3d80((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            D_00764634 = 1;
            *(s16 *)(work + 2) = 1;
            *(u32 *)(work + 4) |= 8;
            break;
        case 2:
            *(s16 *)(work + 2) = 5;
            break;
        case 4:
            *(s16 *)(work + 2) = 2;
            break;
        default:
            break;
        }
        goto return_zero;
    case 0xC:
        *(s16 *)(work + 2) = 0xD;
        func_002a2e50(work, 3);
        /* fallthrough */
    case 0xD:
        result = 0;
        value = *(s32 *)(work + 8);
        switch (value) {
        case 0:
            result = func_002a3070(work);
            break;
        case 1:
            result = func_002a32c0(work);
            break;
        case 2:
            result = func_002a34e0(work);
            break;
        case 3:
            result = func_002a3d80((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            D_00764634 = 1;
            *(s16 *)(work + 2) = 1;
            break;
        case 2:
            *(s16 *)(work + 2) = 5;
            break;
        case 4:
            *(s16 *)(work + 2) = 2;
            break;
        default:
            break;
        }
        goto return_zero;
    default:
        goto return_zero;
    }
return_zero:
    result = 0;
return_result:
    return result;
}
// FUN_002A4B10
s32 func_002a4b10(u8 *sdkTaskBytes) {
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *w = (u8 *)(uintptr_t)func_00452560((void *)(uintptr_t)(u32)arg0);

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
        if (H_Cdvd_IsFileLoaded(*(u32 *)(w + 0x3A4)) == 0) {
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

/* The teardown callback receives the task, not its work allocation. */
// FUN_002A4CB0
void func_002a4cb0(u8 *sdkTaskBytes) {
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *work = (u8 *)(uintptr_t)func_00452560((void *)(uintptr_t)(u32)arg0);
    s32 p = *(s32 *)(work + 0x3A4);
    if (p != 0) {
        H_Cdvd_Destroy((u8 *)p);
        *(s32 *)(work + 0x3A4) = 0;
    }
    func_0025f230(*(u32 *)(work + 0x398));
    func_002aa2b0(work);
}

/* Exact under MWCC b210/O2: three one-field values preserve the two source
   color slots and their shared output slot without synthetic padding. */
// FUN_002A4D10
s32 func_002a4d10(s32 task) {
    typedef struct { f32 value; } ColorValue;
    u8 *work;
    s32 frame;
    f32 eased;
    ColorValue outputColor;
    ColorValue firstColor;
    ColorValue secondColor;
    McRect rectangle;
    McRect first;
    McRect second;

    work = (u8 *)func_00452560((void *)task);
    frame = *(s32 *)(work + 0x568);
    if (frame > 20) frame = 20;
    eased = sinf((D_00761184 * (f32)frame) / 20.0f);
    firstColor.value = iGpffffa818;
    outputColor = firstColor;
    first = D_0063ED50;
    first.y = (s32)(178.0f * (1.0f - eased));
    first.height = (s32)(448.0f * eased);
    rectangle = first;
    func_0045d6e0(&outputColor.value, &rectangle, 0.0f, 1);
    frame = *(s32 *)(work + 0x568);
    if (frame > 5) {
        frame -= 5;
        if (frame > 15) frame = 15;
        eased = sinf((D_00761184 * (f32)frame) / 15.0f);
        secondColor.value = iGpffffa81c;
        outputColor = secondColor;
        second = D_0063ED60;
        second.y = (s32)(178.0f - (94.0f * eased) / 2.0f);
        second.height = (s32)(94.0f * eased);
        rectangle = second;
        func_0045d6e0(&outputColor.value, &rectangle, 0.0f, 1);
    }
    frame = ++*(s32 *)(work + 0x568);
    if (frame >= 20) {
        *(s32 *)(work + 0x568) = 0;
        return 1;
    }
    return 0;
}

/* measured: retail colors p->$s1, s16->$s0, s18->$s2, s19->$s3, s20(loop)->$s4,
   s21->$s5, f21->$f21, f20->$f20, f23->$f23, f22->$f22; mwcc b210 graph-colors
   a cyclic rotation (p->$s3, s16->$s4, s18->$s0, s19->$s1, s20->$s1, f21->$f22)
   and merges s19/s20 into one register. Tried all six saved-reg declaration
   orders and the mul.s operand-order split; all nd 332. Saved-register rotation
   floor. */
/* Wave-14: func_0025f3f0/func_002a66d0 in this family carry the same m2c
   call-signature errors found in func_002a5f00 (floats must precede the ints in
   the C call); not re-probed — same rotation family where a fresh m2c body
   measured worse than the recorded hand-adapted best. */
/* measured this session: fresh probe 391wd (was nd332 stale) / fnalign 264 edits (449 vs 445 instrs, 4 short) confirms floor; short-by-N hunt checked -- shortfall early at frame -0x80 vs -0x90 + swc1 $f23 (top-down fnalign), not trailing dead-arm chain (tail is while loops + calls, no if/else-if chain); slti $at inclusive checked (no convertible <N range in this window). Saved-reg rotation + frame/FPR wall per owner notes; banked. */
// FUN_002A4F20 NONMATCHING
#ifdef SKIP_ASM
s32 func_002a4f20(s32 arg0) {
    extern f32 iGpffff8214;
    extern f32 iGpffff8084;
    extern f32 iGpffff8218;
    extern f32 iGpffff821c;
    extern f32 iGpffff8030;
    extern f32 D_00761184;
    f32 temp_f0;
    f32 temp_f21;
    f32 var_f1;
    f32 var_3;
    s32 temp_2_2;
    s32 var_20;
    s32 s0f0;
    s32 var_20_2;
    u8 *temp_2;

    temp_2 = ((u8 *(*)(void))func_00452560)();
    func_002a6b10(0, 0, 255, temp_2);
    func_002a7710(255, temp_2);
    temp_2_2 = *(s32 *)(temp_2 + 0x568);
    if (temp_2_2 < 0x0A) {
        var_f1 = (f32)temp_2_2 / 10.0f;
    } else {
        var_f1 = 1.0f;
    }
    temp_f0 = 255.0f * var_f1;
    func_002a6b60(0, 0, (s32)temp_f0, temp_2);
    func_002a6c30(0, 0, (s32)temp_f0, temp_2);
    s0f0 = (s32)temp_f0;
    temp_f21 = (f32)(s32)sinf(iGpffff8214 * ((f32)*(s32 *)(temp_2 + 0x568) / 30.0f));
    {
        s32 t19 = (*(s32 *)(temp_2 + 0x3AC) << 16) >> 16;
        s32 t23 = *(s32 *)(temp_2 + 0x3B4);
        if (t23 != t19) {
            s32 t18 = t19 - t23;
            if ((f32)func_0043c6a0(t18) <= iGpffff8218 * (f32)t19) {
                *(s32 *)(temp_2 + 0x3B4) = t19;
            } else {
                f32 tf2 = (f32)t18;
                f32 tf02 = (f32)(s32)iGpffff821c;
                if (iGpffff821c * tf2 < tf02) {
                    var_3 = tf2 * 0.5f;
                } else {
                    var_3 = tf02;
                }
                *(s32 *)(temp_2 + 0x3B4) += (s32)var_3;
            }
        }
    }
    {
        s32 t182 = *(s32 *)(temp_2 + 0x3B4) >> 16;
        s32 t21 = t182 << 16;
        var_20 = 0;
        while (var_20 < 7) {
            s32 t192 = (t182 + var_20) - 3;
            if ((t192 >= 0) && (t192 < 0x10) && (((var_20 != 0) && (var_20 != 6)) || ((u16)*(s32 *)(temp_2 + 0x3B4) != 0))) {
                f32 tf23;
                f32 tf22;
                s32 t24 = t21 - *(s32 *)(temp_2 + 0x3B4);
                func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
                func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
                func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
                tf23 = -59.0f + (f32)(var_20 * 0x1A) + ((f32)(t24 * 0x1A) / 65536.0f);
                tf22 = -152.0f + (f32)(var_20 * 0x5E) + ((f32)(t24 * 0x5E) / 65536.0f);
                func_002a7920(0xFF, temp_2 + 0x14, t192, 0, temp_2, tf23 - (350.0f * (1.0f - temp_f21)), tf22, 0, 1.0f);
                func_002a9f50(tf23, tf22, 5.0f, s0f0, temp_2 + 0x14, var_20, 0, temp_2);
            }
            var_20 += 1;
        }
    }
    func_0025f3f0(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, (u8 *)(*(s32 *)(temp_2 + 0x398)), 1);
    {
        s32 t182b = *(s32 *)(temp_2 + 0x3B4) >> 16;
        s32 t21b = t182b << 16;
        var_20_2 = 0;
        while (var_20_2 < 7) {
            s32 t193 = (t182b + var_20_2) - 3;
            if ((t193 >= 0) && (t193 < 0x10) && (((t21b - *(s32 *)(temp_2 + 0x3B4)) != 0) || (t193 == t182b) || (t193 == t182b + 1))) {
                s32 t25 = t21b - *(s32 *)(temp_2 + 0x3B4);
                f32 tf222 = -59.0f + (f32)(var_20_2 * 0x1A) + ((f32)(t25 * 0x1A) / 65536.0f);
                f32 tf20 = -152.0f + (f32)(var_20_2 * 0x5E) + ((f32)(t25 * 0x5E) / 65536.0f);
                func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
                func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
                func_002a9f50(tf222, tf20, 5.0f, s0f0, temp_2 + 0x14, var_20_2, 1, temp_2);
            }
            var_20_2 += 1;
        }
    }
    if ((*(s32 *)(temp_2 + 0x3AC) + 1) != 0) {
        f32 tf223;
        f32 tf202;
        func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
        {
            s32 t26 = *(s32 *)(temp_2 + 0x3B8);
            if (t26 > 0) {
                *(s32 *)(temp_2 + 0x3B8) = t26 - 1;
            }
        }
        tf223 = (f32)(s32)(1.0f + (iGpffff8030 * sinf(iGpffff8084 * ((f32)*(s32 *)(temp_2 + 0x3B8) / 10.0f))));
        tf202 = 400.0f * (1.0f - temp_f21);
        func_002a66d0(72.0f - tf202, 179.0f, 0.0f, 124.0f * tf223, 116.0f * tf223, 0x2D2D2D, 0xFF, 1);
        func_002a7920(0xFF, temp_2 + 0x14, *(s32 *)(temp_2 + 0x3AC), 1, temp_2, 19.0f - tf202, 130.0f, 0, tf223);
    }
    {
        s32 t27 = *(s32 *)(temp_2 + 0x568) + 1;
        *(s32 *)(temp_2 + 0x568) = t27;
        if (t27 >= 0x1E) {
            *(s32 *)(temp_2 + 0x568) = 0;
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4f20);
#endif

/* measured: a fresh plain-C reconstruction uses `131.0f + 47.0f * temp_f21`
   for retail's adda.s/madd.s accumulator pair. MWCC emits the ordinary
   single-precision arithmetic from that expression; the full candidate still
   measured nd 1647 (object 2240B against the 2256B window) because its frame
   and saved-register layout diverge. The candidate was not retained; this
   remains bare pending a structurally correct body. */
/* Cold reconstruction from m2c + romwright drafts (guarded v2, best): probe 478wd / fnalign 246 edits (557 vs 563 instrs, 6 short, 1.1% — bankable). */
/*   Retail has no jump table and no sceMc* calls (this mc.c family is effect/sprite code, not memory-card); */
/*   calls verified against mc.c decls + shdSprite.c 0025f430 decl: 0025f430 as 8 ints + 6 floats direct, */
/*   002a7920 ints-first, 002a9f50/002a66d0 floats-first, 002a6960/6b10/6b60/6c30/7710 ints. */
/*   Globals: D_00761184 for -0x7F6C, iGpffff8214/8218/821c for -0x7DEC/-0x7DE8/-0x7DE4, */
/*   iGpffff8084/8030 for -0x7F7C/-0x7FD0 (sibling 002a4f20 spellings). Second loop is <6 (not <7). */
/*   v1 480wd; v2 direct-00452560 514wd (keep cast jalr); v3 fscope tie; v4 temp_2/alpha-last reorder 478wd. */
/*   Pragma sweep on v1: all ties/regressions (dead 480, strength 480, unroll 480, peephole 486, loop-inv 497, prop 510, schedule 515, common-subs 517, O1 517, O3/4 518, O0 559). */
/*   Unhandled: adda.s/madd.s 131+47*f21 pair (plain C), saved-reg rotation ($s1/$s4 etc) + FPR coloring. */
// FUN_002A5630 NONMATCHING
#ifdef NON_MATCHING
s32 func_002a5630(s32 arg0)
{
    extern f32 D_00761184;
    extern f32 iGpffff8214;
    extern f32 iGpffff8218;
    extern f32 iGpffff821c;
    extern f32 iGpffff8084;
    extern f32 iGpffff8030;
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    s32 frame;
    f32 f0;
    f32 f21;
    f32 f20;
    s32 t19;
    s32 t23;
    s32 c;
    s32 s17;
    s32 s20;
    s32 i;
    s32 t;
    u8 *temp_2;
    s32 alpha;

    temp_2 = ((u8 *(*)(void))func_00452560)();
    frame = *(s32 *)(temp_2 + 0x568);
    if (frame < 0x0B) {
        f0 = 0.0f;
    } else if (frame < 0x1E) {
        f0 = (f32)(frame - 10) / 20.0f;
    } else {
        f0 = 1.0f;
    }
    func_002a6b10(0, 0, (s32)(255.0f * (1.0f - f0)), temp_2);
    frame = *(s32 *)(temp_2 + 0x568);
    if (frame < 0x0A) {
        f0 = (f32)frame / 10.0f;
    } else {
        f0 = 1.0f;
    }
    func_002a7710((s32)(255.0f * (1.0f - f0)), temp_2);
    frame = *(s32 *)(temp_2 + 0x568);
    if (frame < 0x0A) {
        f0 = (f32)frame / 10.0f;
    } else {
        f0 = 1.0f;
    }
    f0 = 255.0f * (1.0f - f0);
    func_002a6b60(0, 0, (s32)f0, temp_2);
    func_002a6c30(0, 0, (s32)f0, temp_2);
    frame = *(s32 *)(temp_2 + 0x568);
    if (frame < 0x0A) {
        f20 = (f32)frame / 10.0f;
    } else {
        f20 = 1.0f;
    }
    f21 = sinf(D_00761184 * f20);
    frame = *(s32 *)(temp_2 + 0x568);
    if (frame < 2) {
        f0 = sinf(D_00761184 * ((f32)frame / 2.0f));
        alpha = (s32)(255.0f * (1.0f - f0));
    } else {
        alpha = 0;
    }
    if (f20 < 1.0f) {
        t19 = *(s32 *)(temp_2 + 0x3AC) << 16;
        t23 = *(s32 *)(temp_2 + 0x3B4);
        if (t23 != t19) {
            c = t19 - t23;
            if ((f32)func_0043c6a0(c) <= iGpffff8214 * (f32)t19) {
                *(s32 *)(temp_2 + 0x3B4) = t19;
            } else {
                f32 tf = (f32)c;
                f32 fv = iGpffff8218 * tf;
                if (fv < iGpffff821c) {
                    fv = tf * 0.5f;
                }
                *(s32 *)(temp_2 + 0x3B4) += (s32)fv;
            }
        }
        s17 = *(s32 *)(temp_2 + 0x3B4) >> 16;
        s20 = s17 << 16;
        i = 0;
        while (i < 7) {
            t = (s17 + i) - 3;
            if ((t >= 0) && (t < 0x10) && (((i != 0) && (i != 6)) || ((u16)*(s32 *)(temp_2 + 0x3B4) != 0))) {
                s32 d = s20 - *(s32 *)(temp_2 + 0x3B4);
                f32 f23 = -59.0f + (f32)(i * 0x1A) + ((f32)(d * 0x1A) / 65536.0f);
                f32 f22 = -152.0f + (f32)(i * 0x5E) + ((f32)(d * 0x5E) / 65536.0f);
                func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
                func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
                func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
                func_002a7920(0xFF, temp_2 + 0x14, t, 0, temp_2, f23 - (400.0f * f21), f22, 0.0f, 1.0f);
                func_002a9f50(f23, f22, 5.0f, alpha, temp_2 + 0x14, t, 0, temp_2);
            }
            i += 1;
        }
        func_0025f430(0.0f, 131.0f + 47.0f * f21, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, *(u8 **)(temp_2 + 0x398), 1, 0, 0, 0.0f, 1.0f, 1.0f - f21);
        i = 0;
        while (i < 6) {
            t = (s17 + i) - 3;
            if ((t >= 0) && (t < 0x10)) {
                s32 d = s20 - *(s32 *)(temp_2 + 0x3B4);
                f32 f23 = -59.0f + (f32)(i * 0x1A) + ((f32)(d * 0x1A) / 65536.0f);
                f32 f22 = -152.0f + (f32)(i * 0x5E) + ((f32)(d * 0x5E) / 65536.0f);
                if ((t == s17) || (t == s17 + 1)) {
                    func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
                    func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
                    func_002a9f50(f23, f22, 5.0f, alpha, temp_2 + 0x14, t, 1, temp_2);
                }
            }
            i += 1;
        }
        if ((*(s32 *)(temp_2 + 0x3AC) + 1) != 0) {
            func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
            {
                s32 bv = *(s32 *)(temp_2 + 0x3B8);
                if (bv > 0) {
                    *(s32 *)(temp_2 + 0x3B8) = bv - 1;
                }
            }
            {
                f32 f22b = 1.0f + (iGpffff8030 * sinf(iGpffff8084 * ((f32)*(s32 *)(temp_2 + 0x3B8) / 10.0f)));
                f32 f20b = 350.0f * f21;
                func_002a66d0(72.0f - f20b, 179.0f, 0.0f, 124.0f * f22b, 116.0f * f22b, 0x2D2D2D, 0xFF, 1);
                func_002a7920(0xFF, temp_2 + 0x14, *(s32 *)(temp_2 + 0x3AC), 1, temp_2, 19.0f - f20b, 130.0f, 0.0f, f22b);
            }
        }
    }
    {
        s32 n = *(s32 *)(temp_2 + 0x568) + 1;
        *(s32 *)(temp_2 + 0x568) = n;
        if (n >= 0x1E) {
            *(s32 *)(temp_2 + 0x568) = 0;
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5630);
#endif

/* measured: retail colors p->$s0, s17->$s1, s18->$s2, s19->$s3, s20->$s4; mwcc
   b210 graph-colors a cyclic rotation (p->$s2, s17->$s0, s18->$s1, s20->$s0,
   loop-s18->$s4) and the loop's s18 = s17+s19-3 reuses a different register
   than retail. Tried p first/last, all five saved-reg declaration orders, and
   the two-statement mul.s (value-in-fs) fix (that one landed); best nd 81.
   Saved-register rotation floor. */
/* Wave-14 re-test: corrected the m2c call-signature errors at func_0025f3f0 */
/*   (floats 0.0/195.0/0.0 then ints 0xFFFFFF/0xFF/0x22/0/[0x398]/1) and */
/*   func_002a66d0 (floats 72.0/179.0/0.0/124.0*f/116.0*f then ints 0x2D2D2D/0xFF/1) */
/*   and the 0xFF constants (m2c misread as 3.57e-43f); nd 314 from a fresh m2c */
/*   body, worse than the recorded 81 (previous hand-adapted body). The func_002a9f50 */
/*   call now passes the correct s32 0xFF first arg. Rotation floor persists. */
/* 2026-09-17 cold reconstruction from the m2c draft (guarded v1): nd 181. */
/*   Call map used (all verified against mc.c decls + 002a4f20 sibling spellings): */
/*   0025f3f0 as (0.0f,131.0f,0.0f,FFFFFF,FF,22,0,*(0x398),1) (m2c rotated the */
/*   two triples); 002a9f50 as (f21,f20,5.0f,0xFF,t+0x14,t18,0,temp_2); */
/*   002a66d0 floats-first; 6b10/6b60/6c30/7710 take int 255 (not 3.57e-43f); */
/*   0018bb20/0015d1a0 at true arity (extra m2c args dropped); 0047a1a0 as */
/*   (obj,&cfg,float,int). 00452560 called via cast (TU decl is (void*)->u32); */
/*   a block-scope shadow decl + direct call regressed badly (decl conflict), */
/*   reverted. Unhandled: two-statement mul.s split (870, worse), D_00761304/ */
/*   D_0076130C/D_00761308 unregistered (recover_symbols.py needed before any */
/*   live attempt; D_00761120/74 likewise Ghidra-spelled, cf iGpffff8030/8084). */
/*   Size: object 1568B vs 1552B window (16 over — residual is coloring plus */
/*   extra materialization, not missing work). Production stays ASM. */
// FUN_002A5F00 NONMATCHING
#ifdef NON_MATCHING
s32 func_002a5f00(s32 arg0)
{
    extern f32 D_00761304;
    extern f32 D_0076130C;
    extern f32 D_00761308;
    extern f32 D_00761120;
    extern f32 D_00761174;
    u8 *p;
    s32 s17;
    s32 s18;
    s32 s19;
    s32 s20;
    f32 f21;
    f32 f20;
    f32 f23;
    f32 f22;
    f32 t0;
    s32 a;
    s32 b;
    s32 c;

    p = ((u8 *(*)(void))func_00452560)();
    func_002a6b10(0, 0, 255, p);
    func_002a7710(255, p);
    func_002a6b60(0, 0, 255, p);
    func_002a6c30(0, 0, 255, p);
    a = *(s32 *)(p + 0x3AC) << 16;
    b = *(s32 *)(p + 0x3B4);
    if (b != a) {
        c = a - b;
        if ((f32)func_0043c6a0(c) <= D_00761304 * (f32)a) {
            *(s32 *)(p + 0x3B4) = a;
        } else {
            t0 = (f32)c;
            f20 = (f32)(s32)D_0076130C;
            if (D_00761308 * t0 < f20) {
                f23 = t0 * 0.5f;
            } else {
                f23 = f20;
            }
            *(s32 *)(p + 0x3B4) = *(s32 *)(p + 0x3B4) + (s32)f23;
        }
    }
    s17 = *(s32 *)(p + 0x3B4) >> 16;
    s19 = 0;
    s20 = s17 << 16;
    while (s19 < 7) {
        s18 = (s17 + s19) - 3;
        if (s18 >= 0 && s18 < 0x10 && ((s19 != 0 && s19 != 6) || (u16)*(s32 *)(p + 0x3B4) != 0)) {
            func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
            func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
            func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
            c = s20 - *(s32 *)(p + 0x3B4);
            f21 = -59.0f + (f32)(s19 * 0x1A) + (f32)(c * 0x1A) / 65536.0f;
            f20 = -152.0f + (f32)(s19 * 0x5E) + (f32)(c * 0x5E) / 65536.0f;
            func_002a7920(0xFF, p + 0x14, s18, 0, p, f21, f20, 0, 1.0f);
            func_002a9f50(f21, f20, 5.0f, 0xFF, p + 0x14, s18, 0, p);
        }
        s19 += 1;
    }
    func_0025f3f0(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, (u8 *)(*(s32 *)(p + 0x398)), 1);
    s19 = 0;
    while (s19 < 7) {
        s18 = (s17 + s19) - 3;
        if (s18 >= 0 && s18 < 0x10 && ((c = s20 - *(s32 *)(p + 0x3B4), f21 = -59.0f + (f32)(s19 * 0x1A) + (f32)(c * 0x1A) / 65536.0f, f20 = -152.0f + (f32)(s19 * 0x5E) + (f32)(c * 0x5E) / 65536.0f, s18 == s17) || s18 == s17 + 1)) {
            func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
            func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
            func_002a9f50(f21, f20, 5.0f, 0xFF, p + 0x14, s18, 1, p);
        }
        s19 += 1;
    }
    if ((*(s32 *)(p + 0x3AC) + 1) != 0) {
        func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
        c = *(s32 *)(p + 0x3B8);
        if (c > 0) {
            *(s32 *)(p + 0x3B8) = c - 1;
        }
        f20 = (f32)(s32)(1.0f + (D_00761120 * sinf((s16)((D_00761174 * (f32)*(s32 *)(p + 0x3B8)) / 10.0f))));
        func_002a66d0(72.0f, 179.0f, 0.0f, 124.0f * f20, 116.0f * f20, 0x2D2D2D, 0xFF, 1);
        func_002a7920(0xFF, p + 0x14, *(s32 *)(p + 0x3AC), 1, p, 19.0f, 130.0f, 0, f20);
    }
    func_002a6e30(5, -5, 0xFF, p);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5f00);
#endif

// FUN_002A6510
s32 func_002a6510(s32 arg0) {
    u8 *work = (u8 *)(uintptr_t)func_00452560((void *)(uintptr_t)(u32)arg0);
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
        slot[0] = fparg0 + f21 * cosf(x);
        slot[1] = fparg1 + f20 * -sinf(x);
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
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
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
            func_0025f3f0((f32)(arg0 + 0x1C0), (f32)(arg1 + 0xC), 0.0f, 0xFFFFFF, arg2 & 0xFF, 0x3D, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
        } else {
            func_0025f3f0((f32)(arg0 + 0x19A), (f32)(arg1 + 0xC), 0.0f, 0xFFFFFF, arg2 & 0xFF, 0x39, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
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
        func_0025f3f0((f32)(arg0 + 0x1F5), (f32)(arg1 + 0x19B), 0.0f, 0xFFFFFF, v, 0x24, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
        func_0025f3f0((f32)(arg0 + 0x207), (f32)(arg1 + 0x19D), 0.0f, 0xFFFFFF, v, 0x27, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
        func_0025f3f0((f32)(arg0 + 0x22C), (f32)(arg1 + 0x19B), 0.0f, 0xFFFFFF, v, 0x25, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
        func_0025f3f0((f32)(arg0 + 0x23E), (f32)(arg1 + 0x19D), 0.0f, 0xFFFFFF, v, 0x28, 0, (u8 *)(*(s32 *)(arg3 + 0x398)), 1);
        *(s32 *)(arg3 + 4) &= 0xFFF7FFFF;
    }
}

// FUN_002A6E30
void func_002a6e30(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
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
    f20 = sinf(D_00761184 * (f32)*(s32 *)(arg3 + 0x3C8) / 10.0f);
    f21 = sinf(D_00761184 * (f32)*(s32 *)(arg3 + 0x3CC) / 10.0f);
    if (*(s32 *)(arg3 + 4) & 0x1000) {
        *(s32 *)(arg3 + 0x3C0) = 0xA;
        *(s32 *)(arg3 + 4) &= ~0x1000;
    }
    if (*(s32 *)(arg3 + 4) & 0x2000) {
        *(s32 *)(arg3 + 0x3C4) = 0xA;
        *(s32 *)(arg3 + 4) &= ~0x2000;
    }
    f23 = sinf(D_00761174 * (f32)*(s32 *)(arg3 + 0x3C0) / 10.0f);
    f22 = sinf(D_00761174 * (f32)*(s32 *)(arg3 + 0x3C4) / 10.0f);
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
    func_002a66d0((f32)(arg0 + 0x15) + f24, (f32)(arg1 - 4) + f20, 0.0f, 108.0f, 100.0f, 0xFFAE20, arg2, 1);
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
    func_002a66d0((f32)(arg0 + 0x95) + f21, (f32)(arg1 + 0x1D1) + f20, 0.0f, 108.0f, 100.0f, 0xFFAE20, arg2, 1);
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
            memset(arg0, 0, 0x14);
            *(u32 *)arg0 |= 1;
            return (s32)arg0;
        }
        arg0 += 0x14;
        i++;
    }
    return 0;
}

static inline const s32 *mcTableAt(s32 index, const s32 *base)
{
    return base + index;
}

/* 844/848 bytes; eight resolved relocations; four zero alignment bytes.
 * Keep table indices separate from their bases and reload the stored step.
 * Reuse the table-copy word for width before converting it to float. */
// FUN_002A73C0
s32 func_002a73c0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    typedef struct { s32 a, b; } I8;
    s32 sp80[8];
    s32 sp60[8];
    u8 *work;
    u8 *rec;
    I8 *src;
    I8 *dst;
    s32 n;
    s32 v;
    s32 i;
    s32 scale;
    s32 total;
    s16 step;
    f32 rate;
    f32 w;
    f32 fx;
    f32 fy;
    s32 ns;
    u32 r;
    f32 rf;
    s32 tail;
    s32 idx;
    f32 cx;
    f32 cy;
    u8 *nw;

    work = arg1;
    rec = arg2;
    src = (I8 *)D_0063EDB0;
    dst = (I8 *)sp80;
    n = 4;
    do {
        v = src->a;
        i = src->b;
        src++;
        n--;
        dst->a = v;
        dst->b = i;
        dst++;
    } while (n > 0);
    src = (I8 *)D_0063EDD0;
    dst = (I8 *)sp60;
    n = 4;
    do {
        v = src->a;
        i = src->b;
        src++;
        n--;
        dst->a = v;
        dst->b = i;
        dst++;
    } while (n > 0);
    if (*(s16 *)(rec + 0x12) > 0) {
        *(s16 *)(rec + 0x12) -= 1;
        return 0;
    }
    scale = (s32)((f32)(s32)((u32)arg3 * 255U) / 255.0f);
    total = *mcTableAt(*(s32 *)(rec + 4), sp60);
    step = *(s16 *)(rec + 0x10);
    rate = (f32)step / (f32)total;
    if (step < 30) {
        scale = (s32)(((f32)step / 30.0f) * (f32)scale);
    } else if (total - 30 < step) {
        scale = (s32)((f32)scale * ((f32)(total - step) / 30.0f));
    }
    v = *mcTableAt(((s32 *)rec)[1], sp80);
    w = 2.0f * (f32)v;
    fx = *(f32 *)(rec + 8) - 512.0f * rate;
    fy = *(f32 *)(rec + 0xC) + 512.0f * rate;
    func_002a66d0(fx, fy, 0.0f, D_00761300 * w, w, 0xFFF267, scale, 1);
    *(s16 *)(rec + 0x10) += 1;
    total = *mcTableAt(*(s32 *)(rec + 4), sp60);
    ns = *(s16 *)(rec + 0x10);
    if (ns >= total) {
        *(s16 *)(rec + 0x10) = 0;
        return 1;
    }
    if ((s32)ns == (total >> 2) * 3) {
        r = RpRandom();
        rf = (f32)r;
        rf = 10.0f * (rf / 2147483648.0f);
        tail = (s32)(u32)rf + 30;
        idx = *(s32 *)(rec + 4);
        cy = *(f32 *)(rec + 0xC);
        cx = *(f32 *)(rec + 8);
        nw = (u8 *)func_002a7330(work);
        if (nw != 0) {
            *(s32 *)(nw + 4) = idx;
            *(f32 *)(nw + 8) = cx;
            *(f32 *)(nw + 0xC) = cy;
            *(s16 *)(nw + 0x12) = (s16)tail;
        }
    }
    return 0;
}
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
                memset(p, 0, 0x14);
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

/* measured 002a7920: guarded 1350wd via `python3 tools/measure_guarded.py src/Kernel/mc.c func_002a7920`; fnalign retail 1528 vs object 1531 instrs (+3, +0.2% inside 3% gate 1482-1574), 828 edits (+1 reloc-only) via `python3 tools/fnalign.py src/Kernel/mc.c func_002a7920 --candidate /tmp/compact7920_s64.c --quiet`; composition max pure hole 6 max pure lump 7 - CLEAN, no hole-against-lump. M2C + hand de-noise to file idiom reusing MATCHed neighbour call orderings (002a7920 ints-first, 002a9f50/002a66d0 floats-first per 002a4f20/002a5630 at 1327/1457; 0025f430 as 8 ints + 6 floats per shdSprite MATCH, 0025f3f0 floats-first per mc.c decl; 0045d6e0 as (ptr,ptr,float,int)): (f32)(s32) kept signed (no unsigned site); colour adda/madd pair as 1.0f*233.0f + -76.0f*ret and 1.0f*44.0f + 113.0f*ret with 0x4F000000 guard; msub args 8/9 of 0025f430 as 1.0f*base - scale*fparg3 (53/21, 70/32, 51/35); 0x41F00000 as 30.0f, 0x20/0x3E f3 as 0.0f/30.0f; D_00887300 via single setState base (retail two regs); tail 0x10 byte loop + 160.0f quad + 0045d6e0. s64 var/a to reach gate (retail 32-bit addiu/slti vs s64 daddiu/dsll; values small, semantics preserved). Residual is saved-reg rotation + FPR colouring + accumulator scheduling (adda/madd/msub as plain mul/sub). */
/* fix 2026-09-19 (decl): s64 var/a forced 64-bit extends retail never emits (addiu+dsll32/dsra32 vs plain addiu/slti) -- s32 var/a drops 68 instrs; (u8)a0b view at & 0xFF sites kills s8 sign-extracts (dsll32/dsra32/andi -> plain andi, matching retail andi $a1,$s2,0xff; bare a0b keeps s8 for sign-extended call args per retail move $a1,$s2). fnalign retail 1524 vs object 1439, 667 edits (+1 reloc, was 828/-161), guarded 1341wd (was 1350), frame 0xf0/0xe0, GPR exact, retail still saves $f30 (f30-value 9.0+fparg2 pinned $f27 here vs $f30 there; 11 live floats in 10 regs). Investigated and ruled out: second-copy 21.0f/53.0f -> 32.0f/75.0f alternation (retail alternates per sub-block at f29/f28 recomputes AND var==0 inlines, but both positional mappings regress +9/+15 -- needs block restructuring, not constant swaps; live values may already be correct with 32/75 confined to retail-dead legs). Residual is micro-diffs (max hole/lump unchanged shape) + $f30 packing. */
/* gate: func_002a7920 is now OUTSIDE the +-3% band at 1439 against retail 1524 (-5.6%).
   The sink pass that produced this is a real structural gain - the callee-saved set
   now matches retail exactly and fnalign edits fell to 667 from 828 edits - but it
   also removed real instructions, and the body is short by the difference.  Recorded
   outside the gate deliberately rather than propped up: no differing-word score
   measured against it is comparable to one measured inside (handoff 7y).  The next
   step is to find which of the sunk recomputations retail actually performs at each
   use and write those back - the register colouring is already right, so the missing
   instructions are recomputation, not spills. */
/* fix 2026-09-20 (absent): handoff 48 from 002ae630 ownership trace written back as retail does it. 0x002a8068-0x002a80a0 (14): f30=9+fparg2 + f29=(49+fparg1)-32*fparg3 + 70*fparg3 head of f28=(53+fparg0)-70*fparg3 for arg3!=0 Block A (f23) outer-false live var 0xA-0x13 leg -- live-leg 32/70 pair (dead-leg same shape uses 21/53). 0x002a8410-0x002a8448 (14): same shape for Block B (f20) with f30=10+fparg2 -- live-leg 32/70 for second sub-block. 0x002a8f8c-0x002a8fdc (20): tail Quad4 int stores spD.a=(s32)((fparg0-16)+tmp), spD.b=(s32)((fparg1-16)+tmp), spD.c=spD.d=(s32)(160*fparg3) with tmp=0.5*160*(1-fparg3) + D_00887300 load -- cvt.w.s+mfc1+sw, not swc1; Quad4 + (s32) keeps all four (separate s32 scalars dead-store to one). Outer-false siblings same pattern: arg3!=0 dead var<0xA msub 70/32 (not 53/21); arg3==0 outer (both legs, both sub-blocks) fparg0-5.0f/22.0f+fparg1 (not 14/33). f30 per-leg (9/10 shared with f23/f20 before branches) forced via f30/f30b/f30c/f30d distinct dests + opt_common_subs off (else single-hoisted). fnalign retail 1528 vs object 1562 (+34, +2.2% inside 3% gate 1482-1574), 910 edits (+1 reloc), guarded 1442wd; frame now 0xf0 (retail) via extra saves. Inside band so edit score comparable again. */
/* fix 2026-09-20 (helpers): libcall_scan 4x __fixsfdi -> 0 at the four (0.0f - tmp) sites via (s16)(0.0f - tmp). Amended-gate case: object LONGER than retail so the count check applies -- fnalign retail 1528 vs object 1562 (+34) 910ed -> 1556 (+28, +1.8% inside 1482-1574) 759ed (-151), guarded 1442->1266, count moved toward retail as required. Retail narrow shape at 0x002A7F50 (+3 siblings): mul 40*fparg3, sub 0-tmp, cvt.w.s, mfc1, dsll32/dsra32 16; micro_codegen confirms (s16) reproduces cvt+extend with no helper. Rejected (s32)(0.0f - tmp): 1544 instrs but 904ed, shorter yet unfaithful (drops the extend). Residual neg.s vs retail sub.s at those 4 sites left open. */
#pragma opt_common_subs off
// FUN_002A7920 NONMATCHING
#ifdef NON_MATCHING
void func_002a7920(u8 arg0, u8 *arg1, s32 arg2, s32 arg3, u8 *arg4, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    extern f32 D_00761184;
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    u8 spEF;
    s8 spEE;
    s8 spED;
    u8 spEC;
    Quad4 spD;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f20;
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f30b;
    f32 f30c;
    f32 f30d;
    f32 ret;
    f32 tmp;
    s32 v0;
    s32 v1;
    s32 c0;
    s32 c1;
    u32 col;
    u32 colHi;
    s32 var;
    s32 var2;
    s32 a;
    s32 b;
    u8 *p20;
    u8 *p;
    s32 n;
    void *setState;
    s8 a0b;
    s32 t;

    a0b = arg0;
    if (*(s32 *)((u8 *)(arg1) + (arg2 * 4)) == 1) {
        p20 = (u8 *)(arg1 + (arg2 * 0x34) + 0x40);
    } else {
        p20 = NULL;
    }
    if (arg3 != 0) {
        if ((p20 != NULL) && (*(u8 *)(p20 + 0xA) != 0)) {
            *(s32 *)(arg4 + 4) |= 0x10000;
        } else {
            *(s32 *)(arg4 + 4) &= 0xFFFEFFFF;
        }
        v0 = 0x7E;
        v1 = 0x76;
        if (*(s32 *)(arg4 + 4) & 0x10000) {
            t = *(s32 *)(arg4 + 0x3BC);
            if (t < 5) {
                *(s32 *)(arg4 + 0x3BC) = t + 1;
            }
        } else {
            t = *(s32 *)(arg4 + 0x3BC);
            if (t > 0) {
                *(s32 *)(arg4 + 0x3BC) = t - 1;
            }
        }
        ret = sinf((D_00761184 * (f32) *(s32 *)(arg4 + 0x3BC)) / 5.0f);
        tmp = 0.0f + 1.0f * 233.0f + -76.0f * ret;
        if (!(tmp >= 2.1474836e9f)) {
            c0 = 0x4F000000 & 0xFF;
        } else {
            c0 = ((s32)(tmp - 2.1474836e9f) | 0x80000000) & 0xFF;
        }
        colHi = ((c0 & 0xFF) << 0x10) | 0xFF000000;
        tmp = 0.0f + 1.0f * 44.0f + 113.0f * ret;
        if (!(tmp >= 2.1474836e9f)) {
            c1 = 0x4F000000 & 0xFF;
        } else {
            c1 = ((s32)(tmp - 2.1474836e9f) | 0x80000000) & 0xFF;
        }
        col = ((u8)a0b & 0xFF) | (colHi | ((c1 & 0xFF) << 8));
    } else {
        col = ((u8)a0b & 0xFF) | 0xFFAE2000;
        v0 = 0x6A;
        v1 = 0x62;
    }
    setState = (void *)D_00887300;
    func_00489f80();
    (*(void (**)(s32, s32))setState)(6, 0);
    (*(void (**)(s32, s32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x5000D);
    RpSkyRenderStateSet(2, 0x44);
    f29 = (f32) v1 * fparg3;
    f28 = (f32) v0 * fparg3;
    f23 = 9.0f + fparg2;
    f22 = 49.0f + fparg1;
    f21 = 53.0f + fparg0;
    func_002a66d0(f21, f22, f23, 2.0f + f28, 2.0f + f29, 0xFFFFFF, 1, 2);
    func_002a66d0(f21, f22, f23, f28, f29, 0xFFFFFF, a0b, 4);
    f20 = 10.0f + fparg2;
    func_002a66d0(f21, f22, f20, f28, f29, 0xFFFFFF, a0b, 2);
    if (arg3 != 0) {
        (*(void (**)(s32, s32))setState)(7, 2);
        (*(void (**)(s32, s32))setState)(9, 2);
        (*(void (**)(s32, s32))setState)(6, 1);
        (*(void (**)(s32, s32))setState)(8, 1);
        (*(void (**)(s32, s32))setState)(0xC, 1);
        (*(void (**)(s32, s32))setState)(0xB, 6);
        (*(void (**)(s32, s32))setState)(0xA, 5);
        (*(void (**)(s32, s32))setState)(2, 4);
        (*(void (**)(s32, s32))setState)(0xE, 0);
        RpSkyRenderStateSet(3, 0x50009);
        RpSkyRenderStateSet(2, 0x44);
        var = arg2 + 1;
        if (var < 0xA) {
            if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(0.0f + 1.0f * f21 - 53.0f * fparg3, 0.0f + 1.0f * f22 - 21.0f * fparg3, f23, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30 = 9.0f + fparg2;
            f29 = (49.0f + fparg1) - (21.0f * fparg3);
            f28 = (53.0f + fparg0) - (53.0f * fparg3);
            func_0025f430(f28, f29, f30, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            tmp = 40.0f * fparg3;
            func_0025f430(f28 + tmp, f29, f30, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, (s16)(0.0f - tmp), 0, 30.0f, fparg3, fparg3);
            }
        } else if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(0.0f + 1.0f * f21 - 70.0f * fparg3, 0.0f + 1.0f * f22 - 32.0f * fparg3, f23, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
        } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30b = 9.0f + fparg2;
            f29 = (49.0f + fparg1) - (32.0f * fparg3);
            f28 = (53.0f + fparg0) - (70.0f * fparg3);
            func_0025f430(f28, f29, f30b, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            tmp = 40.0f * fparg3;
            func_0025f430(f28 + tmp, f29, f30b, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, (s16)(0.0f - tmp), 0, 30.0f, fparg3, fparg3);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        var = arg2 + 1;
        if (var < 0xA) {
            if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(0.0f + 1.0f * f21 - 53.0f * fparg3, 0.0f + 1.0f * f22 - 21.0f * fparg3, f20, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30 = 10.0f + fparg2;
            f29 = (49.0f + fparg1) - (21.0f * fparg3);
            f28 = (53.0f + fparg0) - (53.0f * fparg3);
            func_0025f430(f28, f29, f30, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            tmp = 40.0f * fparg3;
            func_0025f430(f28 + tmp, f29, f30, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, (s16)(0.0f - tmp), 0, 30.0f, fparg3, fparg3);
            }
        } else if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(0.0f + 1.0f * f21 - 70.0f * fparg3, 0.0f + 1.0f * f22 - 32.0f * fparg3, f20, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
        } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30b = 10.0f + fparg2;
            f29 = (49.0f + fparg1) - (32.0f * fparg3);
            f28 = (53.0f + fparg0) - (70.0f * fparg3);
            func_0025f430(f28, f29, f30b, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, fparg3, fparg3);
            tmp = 40.0f * fparg3;
            func_0025f430(f28 + tmp, f29, f30b, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, (s16)(0.0f - tmp), 0, 30.0f, fparg3, fparg3);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        a = col >> 8;
        func_0025f430(0.0f + 1.0f * f21 - 51.0f * fparg3, 0.0f + 1.0f * f22 - 35.0f * fparg3, f23, a, (u8)a0b & 0xFF, 0x20, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 0.0f, fparg3, fparg3);
        if ((p20 != NULL) && (*(u8 *)(p20 + 0xA) != 0)) {
            RpSkyRenderStateSet(3, 0x50009);
            RpSkyRenderStateSet(2, 0x44);
            f22 = (49.0f + fparg1) - (53.0f * fparg3);
            f21 = (53.0f + fparg0) - (11.0f * fparg3);
            func_0025f430(f21, f22, f23, a, (u8)a0b & 0xFF, 0x3E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 0.0f, fparg3, fparg3);
            RpSkyRenderStateSet(3, 0x50805);
            RpSkyRenderStateSet(2, 0x44);
            func_0025f430(f21, f22, f20, a, (u8)a0b & 0xFF, 0x3E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 0.0f, fparg3, fparg3);
        }
    } else {
        (*(void (**)(s32, s32))setState)(7, 2);
        (*(void (**)(s32, s32))setState)(9, 2);
        (*(void (**)(s32, s32))setState)(6, 1);
        (*(void (**)(s32, s32))setState)(8, 1);
        (*(void (**)(s32, s32))setState)(0xC, 1);
        (*(void (**)(s32, s32))setState)(0xB, 6);
        (*(void (**)(s32, s32))setState)(0xA, 5);
        (*(void (**)(s32, s32))setState)(2, 4);
        (*(void (**)(s32, s32))setState)(0xE, 0);
        RpSkyRenderStateSet(3, 0x50009);
        RpSkyRenderStateSet(2, 0x44);
        var = arg2 + 1;
        if (var < 0xA) {
            if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(14.0f + fparg0, 33.0f + fparg1, f23, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30c = 9.0f + fparg2;
            f22 = 33.0f + fparg1;
            f21 = 14.0f + fparg0;
            func_0025f430(f21, f22, f30c, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            func_0025f430(f21 + 40.0f, f22, f30c, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
            }
        } else if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(fparg0 - 5.0f, 22.0f + fparg1, f23, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
        } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30d = 9.0f + fparg2;
            f22 = 22.0f + fparg1;
            f21 = fparg0 - 5.0f;
            func_0025f430(f21, f22, f30d, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            func_0025f430(f21 + 40.0f, f22, f30d, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        var = arg2 + 1;
        if (var < 0xA) {
            if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(14.0f + fparg0, 33.0f + fparg1, f20, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30c = 10.0f + fparg2;
            f22 = 33.0f + fparg1;
            f21 = 14.0f + fparg0;
            func_0025f430(f21, f22, f30c, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            func_0025f430(f21 + 40.0f, f22, f30c, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
            }
        } else if (var < 0xA) {
            if (var == 0) {
                var = 0xA;
            }
            func_0025f430(fparg0 - 5.0f, 22.0f + fparg1, f20, col >> 8, (u8)a0b & 0xFF, var + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
        } else if (var < 0x14) {
            if (var == 0xA) {
                a = 0xA;
            } else {
                a = arg2 - 9;
            }
            f30d = 10.0f + fparg2;
            f22 = 22.0f + fparg1;
            f21 = fparg0 - 5.0f;
            func_0025f430(f21, f22, f30d, col >> 8, (u8)a0b & 0xFF, 0x2E, 0, *(u8 **)(arg4 + 0x398), 0, 0, 0, 30.0f, 1.0f, 1.0f);
            func_0025f430(f21 + 40.0f, f22, f30d, col >> 8, (u8)a0b & 0xFF, a + 0x2D, 0, *(u8 **)(arg4 + 0x398), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
        }
        a = col >> 8;
        func_0025f3f0((3.0f + ((4.0f + fparg0) - 5.0f)) - 2.0f, 20.0f + fparg1, f23, a, (u8)a0b & 0xFF, 0x20, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 0);
        if ((p20 != NULL) && (*(u8 *)(p20 + 0xA) != 0)) {
            RpSkyRenderStateSet(3, 0x50009);
            RpSkyRenderStateSet(2, 0x44);
            f22 = 2.0f + fparg1;
            f21 = 42.0f + fparg0;
            func_0025f3f0(f21, f22, f23, a, (u8)a0b & 0xFF, 0x3E, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 0);
            RpSkyRenderStateSet(3, 0x50805);
            RpSkyRenderStateSet(2, 0x44);
            func_0025f3f0(f21, f22, f20, a, (u8)a0b & 0xFF, 0x3E, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 0);
        }
    }
    func_0048a000();
    setState = (void *)D_00887300;
    p = (u8 *)(&spD);
    n = 0x10;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            n -= 1;
        } while (n != 0);
    }
    tmp = 0.5f * (160.0f * (1.0f - fparg3));
    spD.a = (s32)((fparg0 - 16.0f) + tmp);
    spD.b = (s32)((fparg1 - 16.0f) + tmp);
    tmp = 160.0f * fparg3;
    spD.c = (s32)tmp;
    spD.d = (s32)tmp;
    (*(void (**)(s32, s32))setState)(0xE, 0);
    (*(void (**)(s32, s32))setState)(0xC, 1);
    (*(void (**)(s32, s32))setState)(7, 2);
    (*(void (**)(s32, s32))setState)(6, 1);
    (*(void (**)(s32, s32))setState)(8, 0);
    RpSkyRenderStateSet(3, 0x3100C);
    RpSkyRenderStateSet(2, 0x54);
    spEC = (u8) (col >> 0x18);
    spED = (s8) (col >> 0x10);
    spEE = (s8) (col >> 8);
    spEF = (u8) col;
    func_0045d6e0(&spEC, &spD, fparg2, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/mc", func_002a7920);
#endif
#pragma opt_common_subs on

#pragma opt_common_subs off
/* measured: #pragma opt_common_subs off preserves retail's saved-register
   allocation and repeated color shift; plain O2 C is 8 bytes short. */
// FUN_002A9100
void func_002a9100(f32 fparg0, f32 fparg1, f32 fparg2,
                   s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 spC0[0x60];
    s16 *var_6;
    s16 *var_6_2;
    s16 *var_6_3;
    s16 *var_5;
    s16 *var_5_2;
    s16 *var_5_3;
    f32 temp_f21;
    f32 temp_f24;
    f32 temp_f23;
    s16 temp_2_2;
    s16 temp_2_3;
    s16 temp_2_4;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    u8 *temp_17;
    s32 temp_16_2;
    s32 temp_19;
    s32 temp_22;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    u32 temp_23;
    u32 temp_30;
    u32 temp_3;
    u8 *temp_handle;

    temp_17 = (u8 *)(arg2 + (arg3 * 0x34) + 0x40);
    func_00110580(*(s16 *)temp_17);
    temp_3 = *(u32 *)(temp_17 + 4);
    temp_23 = temp_3 / 108000U;
    temp_30 = (temp_3 / 1800U) % 60U;
    arg0 = (arg0 << 8) | arg1;
    temp_22 = arg0 >> 8;
    func_0025f3f0(10.0f + fparg0, 31.0f + fparg1, fparg2, temp_22, (u8)arg1, 0x18, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    sprintf(spC0 + 0x58, &iGpffffa824, *(u8 *)(temp_17 + 8));
    temp_handle = *(u8 **)(arg4 + 0x398);
    var_6 = D_0063EB30;
    var_5 = (s16 *)(spC0 + 0x40);
    var_4 = 6;
    do {
        temp_3_2 = var_6[0];
        temp_2_2 = var_6[1];
        var_6 += 2;
        var_4 -= 1;
        var_5[0] = temp_3_2;
        var_5[1] = temp_2_2;
        var_5 += 2;
    } while (var_4 > 0);
    func_0025f6b0(46.0f + fparg0, 26.0f + fparg1, fparg2,
                  temp_22, (u8)arg1, spC0 + 0x58, 0, spC0 + 0x40,
                  func_002a2e10, temp_handle);
    if ((*(s32 *)(arg2 + (arg3 * 4)) == 1) &&
        (*(u8 *)(temp_17 + 0xA) == 0 ||
         *(s16 *)temp_17 != 9 ||
         *(s16 *)(temp_17 + 2) != 5)) {
        temp_19 = arg0 | arg1;
        temp_f24 = (24.0f + fparg1) - 6.0f;
        temp_f23 = 99.0f + fparg0;
        func_00275020(
            5.0f + (temp_f23 + (f32)func_00275020(
                temp_f23, temp_f24, fparg2, temp_19, 0, 0,
                (const char *)(temp_17 + 0x1E), 1, -1)),
            temp_f24, fparg2, temp_19, 0, 0, (const char *)(temp_17 + 0xC), 0, -1);
    }
    temp_16_2 = arg0 >> 8;
    func_0025f3f0(16.0f + fparg0, 53.0f + fparg1, fparg2, temp_16_2, (u8)arg1, 0x19, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    sprintf(spC0 + 0x58, &iGpffffa824, (s32)temp_23);
    temp_handle = *(u8 **)(arg4 + 0x398);
    var_6_2 = D_0063EB30;
    var_5_2 = (s16 *)(spC0 + 0x20);
    var_4_2 = 6;
    do {
        temp_3_3 = var_6_2[0];
        temp_2_3 = var_6_2[1];
        var_6_2 += 2;
        var_4_2 -= 1;
        var_5_2[0] = temp_3_3;
        var_5_2[1] = temp_2_3;
        var_5_2 += 2;
    } while (var_4_2 > 0);
    temp_f21 = 48.0f + fparg1;
    func_0025f6b0(36.0f + (109.0f + fparg0), temp_f21, fparg2,
                  temp_16_2, (u8)arg1, spC0 + 0x58, 2, spC0 + 0x20,
                  func_002a2e10, temp_handle);
    func_0025f3f0(177.0f + fparg0, temp_f21, fparg2, temp_16_2, (u8)arg1, 0xB, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    sprintf(spC0 + 0x58, &iGpffffa824, (s32)temp_30);
    temp_handle = *(u8 **)(arg4 + 0x398);
    var_6_3 = D_0063EB30;
    var_5_3 = (s16 *)(spC0 + 0x00);
    var_4_3 = 6;
    do {
        temp_3_4 = var_6_3[0];
        temp_2_4 = var_6_3[1];
        var_6_3 += 2;
        var_4_3 -= 1;
        var_5_3[0] = temp_3_4;
        var_5_3[1] = temp_2_4;
        var_5_3 += 2;
    } while (var_4_3 > 0);
    func_0025f6b0(24.5f + (205.0f + fparg0), temp_f21, fparg2,
                  temp_16_2, (u8)arg1, spC0 + 0x58, 2, spC0 + 0x00,
                  func_002a2e10, temp_handle);
    func_0025f3f0(250.0f + fparg0, temp_f21, fparg2, temp_16_2, (u8)arg1, 0xC, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
}
#pragma opt_common_subs on

/* measured: cold de-noised m2c+romwright (guarded v1): measure_guarded 340wd / fnalign 219 edits +6 reloc-only (retail 611/object 610 instrs, 1 short, 0.2% — bankable). */
/*   Calls floats-first per mc.c decls + 002a9100 sibling: 0025f6b0/0025f3f0 floats-first, 00275020 floats-first, 002a9100 floats-first, 0045d6e0 (ptr,ptr,float,int). */
/*   Stack per romwright extents (tmp128[8]/tmp110[12]/tmpF0[16]) + 6960 idioms (memset loops, Quad4 rectCopy, setState base). R1 pragma probes: loop_invariants on 343 (+3), unroll off 340 tie, schedule off 340 tie (strength off 340 tie). R2 subscript: hoist keys 368 (+28), tbl base 427 (+87), off=i*0xC 429 (+89) — keep P[i*3], do not hoist. R3 colour: baseY/baseX 539 (+199), var_5/var_6 swap 358 (+18), var_22/colMid + temp_2/temp_16 ties at 340 — baseline best. */
/*   Remaining: saved-reg rotation ($s5/$s3, $s1/$s0, $s2/$s1, $s0/$s7) + FPR rotation ($f22/$f21/$f20) + add.s operand transpose for fparg0+const + switch 0x1B/0x1C layout + table-loop lbu hoist + D_00887300 single base vs retail two regs. */
// FUN_002A95C0 NONMATCHING
#ifdef NON_MATCHING
void func_002a95c0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4)
{
    u8 tmp128[8];
    s16 tmp110[12];
    s16 tmpF0[16];
    s16 *var_6;
    s16 *var_6_2;
    s16 *var_5;
    s16 *var_5_2;
    s16 t3a;
    s16 t2a;
    s16 t3b;
    s16 t2b;
    s32 month;
    s32 day;
    s32 var_18;
    s32 var_22;
    s32 var_30;
    s32 colMid;
    s32 temp_17;
    s32 temp_18;
    s32 var_4;
    s32 var_4_2;
    s32 i;
    s32 baseSpill;
    f32 baseX;
    f32 baseY;
    f32 tmpY2;
    f32 tmpX2;
    u8 *temp_2;
    u8 *temp_16;
    u8 *str;
    u8 *handle;
    u8 mode;
    f32 single;
    f32 singleCopy;
    Quad4 rect;
    Quad4 rectCopy;
    u8 *p;
    s32 n;
    u8 *p2;
    s32 n2;
    void *setState;
    baseSpill = arg1;
    temp_2 = (u8 *)(arg1 + arg2 * 0x34);
    temp_16 = temp_2 + 0x40;
    func_001104d0(*(s16 *)(temp_2 + 0x40), &month, &day);
    var_18 = func_00110580(*(s16 *)(temp_2 + 0x40));
    if (var_18 < 0) {
        var_18 = 6;
    }
    if (arg3 != NULL) {
        var_22 = (arg0 & 0xFF) | 0xFFE92C00;
    } else {
        var_22 = (arg0 & 0xFF) | 0xFFAE2000;
    }
    if (arg3 != NULL) {
        colMid = (arg0 & 0xFF) | 0x52BDFF00;
    } else {
        colMid = (arg0 & 0xFF) | 0x6984A300;
    }
    if (arg3 != NULL) {
        var_30 = (arg0 & 0xFF) | 0xFF74AC00;
    } else {
        var_30 = (arg0 & 0xFF) | 0xDE6D9D00;
    }
    baseX = fparg0 + 107.0f;
    baseY = fparg1 + 17.0f;
    sprintf(tmp128, &iGpffffa824, month);
    handle = *(u8 **)(arg4 + 0x398);
    var_6 = D_0063EB30;
    var_5 = tmp110;
    var_4 = 6;
    do {
        t3a = var_6[0];
        t2a = var_6[1];
        var_6 += 2;
        var_4 -= 1;
        var_5[0] = t3a;
        var_5[1] = t2a;
        var_5 += 2;
    } while (var_4 > 0);
    temp_17 = var_22 >> 8;
    func_0025f6b0((baseX + 23.0f) - 2.0f, baseY - 1.0f, fparg2, temp_17, (u8)arg0, tmp128, 2, tmp110, func_002a2e10, handle);
    func_0025f3f0(baseX + 45.0f, baseY - 2.0f, fparg2, temp_17, (u8)arg0, 0x4B, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    sprintf(tmp128, &iGpffffa824, day);
    handle = *(u8 **)(arg4 + 0x398);
    var_6_2 = D_0063EB30;
    var_5_2 = tmpF0;
    var_4_2 = 6;
    do {
        t3b = var_6_2[0];
        t2b = var_6_2[1];
        var_6_2 += 2;
        var_4_2 -= 1;
        var_5_2[0] = t3b;
        var_5_2[1] = t2b;
        var_5_2 += 2;
    } while (var_4_2 > 0);
    func_0025f6b0((baseX + 61.0f + 24.0f) - 2.0f, (baseY + 1.0f) - 2.0f, fparg2, temp_17, (u8)arg0, tmp128, 2, tmpF0, func_002a2e10, handle);
    func_0025f3f0(baseX + 109.0f, baseY - 2.0f, fparg2, temp_17, (u8)arg0, 0x15, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    if ((var_18 == 0) || (func_00110d30(*(s16 *)(temp_2 + 0x40)) != 0)) {
        handle = *(u8 **)(arg4 + 0x398);
        func_0025f3f0((baseX + 129.0f) - (f32)func_0025f2c0(0xE, var_18, handle) / 2.0f, baseY - 2.0f, fparg2, var_30 >> 8, (u8)arg0, 0xE, var_18, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    } else if (var_18 == 6) {
        handle = *(u8 **)(arg4 + 0x398);
        func_0025f3f0((baseX + 129.0f) - (f32)func_0025f2c0(0xE, 6, handle) / 2.0f, baseY - 2.0f, fparg2, colMid >> 8, (u8)arg0, 0xE, 6, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    } else {
        handle = *(u8 **)(arg4 + 0x398);
        func_0025f3f0((baseX + 129.0f) - (f32)func_0025f2c0(0xE, var_18, handle) / 2.0f, baseY - 2.0f, fparg2, temp_17, (u8)arg0, 0xE, var_18, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    }
    func_0025f3f0(baseX + 136.0f, baseY - 2.0f, fparg2, temp_17, (u8)arg0, 0x16, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    i = 1;
    str = D_0063EA68;
    while (i < 0xD) {
        if (*(s32 *)&D_0063EA60[i * 3] == temp_16[0x30] && *(s32 *)&D_0063EA60[i * 3 + 1] == temp_16[0x31]) {
            str = (u8 *)D_0063EA60[i * 3 + 2];
            break;
        }
        i += 1;
    }
    func_00275020(baseX + 151.0f, ((baseY - 2.0f) - 6.0f) + 2.0f, fparg2, var_22 | arg0, 0, 1, (const char *)str, 0, -1);
    temp_18 = var_22 >> 8;
    func_002a9100(baseX, baseY, fparg2, temp_18, arg0, (u8 *)baseSpill, arg2, arg4);
    p = (u8 *)&single;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    singleCopy = single;
    p2 = (u8 *)&rect;
    n2 = 0x10;
    if (p2 != NULL) {
        do {
            *p2 = 0;
            p2++;
            n2--;
        } while (n2 != 0);
    }
    rect.a = (s32)(baseX - 16.0f);
    rect.b = (s32)(baseY - 16.0f);
    rect.c = 0x20;
    rect.d = 0x80;
    rectCopy = rect;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(0xE, 0);
    (*(void (**)(u32, u32))setState)(0xC, 1);
    (*(void (**)(u32, u32))setState)(7, 2);
    (*(void (**)(u32, u32))setState)(9, 1);
    (*(void (**)(u32, u32))setState)(0x14, 1);
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    func_00489f80();
    func_0045d6e0(&singleCopy, &rectCopy, 0.0f, 0);
    func_0048a000();
    func_00489f80();
    tmpY2 = baseY + 48.0f;
    tmpX2 = (f32)0x129 + baseX;
    func_0025f3f0(tmpX2, tmpY2, fparg2, temp_18, (u8)arg0, 0x1E, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    mode = temp_16[9];
    if (mode == 1) {
        func_0025f3f0(tmpX2 + 17.0f, tmpY2 + 4.0f, fparg2, temp_17, (u8)arg0, 0x1C, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    } else if (mode == 0) {
        func_0025f3f0(tmpX2 + 11.0f, tmpY2 + 4.0f, fparg2, temp_17, (u8)arg0, 0x1B, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    } else {
        func_0025f3f0(tmpX2 + 21.0f, tmpY2 + 3.0f, fparg2, temp_17, (u8)arg0, 0x1D, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    }
    func_0048a000();
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x30003);
    RpSkyRenderStateSet(2, 0x54);
    func_0025f3f0(tmpX2, tmpY2, fparg2, temp_17, (u8)arg0, 0x1E, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/mc", func_002a95c0);
#endif

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
/* Wave-14 re-test: fresh m2c-sourced body with the func_002a95c0 call arg
   order corrected; the m2c had scrambled the 8-arg call (missing the 4th arg).
   Retail leaves $7 live as arg3 at 0xA0C0, so the call is
   func_002a95c0(arg0,arg1,arg2,(u8*)arg3,arg4,f0,f1,f2); nd 190 (recorded
   162-181). The call site now matches (the jal relocation aligns) but the
   prologue register rotation (retail's FP store order vs int) dominates.
   Rotation floor persists. */
// FUN_002A9F50
void func_002a9f50(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_3;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    u8 *temp_2;
    u8 *temp_4;

    temp_2 = arg1 + (arg2 * 0x34);
    temp_4 = temp_2 + 0x40;
    temp_3 = *(s32 *)(arg1 + (arg2 * 4));
    if (temp_3 == 1) {
        if (*(u8 *)(temp_4 + 0xA) != 0 && *(s16 *)(temp_4 + 0) == 9 && *(s16 *)(temp_4 + 2) == 5) {
            if (arg3 != 0) {
                var_2 = (arg0 & 0xFF) | 0xFFE92C00;
            } else {
                var_2 = (arg0 & 0xFF) | 0xFFAE2000;
            }
            temp_17 = var_2 >> 8;
            func_0025f3f0(5.0f + (113.0f + fparg0), 10.0f + fparg1, fparg2, temp_17, (u8)arg0, 0x43, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
            func_002a9100(mc_add(fparg0, 107.0f), mc_add(fparg1, 17.0f), fparg2,
                          temp_17, arg0, (u8 *)arg1, arg2, arg4);
            return;
        }
        func_002a95c0(fparg0, fparg1, fparg2, arg0, (s32)arg1, arg2, (u8 *)arg3, arg4);
        return;
    }
    if (temp_3 == 2) {
        if (arg3 != 0) {
            var_2_2 = (arg0 & 0xFF) | 0xFFE92C00;
        } else {
            var_2_2 = (arg0 & 0xFF) | 0xFFAE2000;
        }
        temp_17_2 = var_2_2 >> 8;
        func_0025f3f0(113.0f + fparg0, 34.0f + fparg1, fparg2, temp_17_2, (u8)arg0, 0x46, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
        func_0025f3f0(122.0f + fparg0, 35.0f + fparg1, fparg2, temp_17_2, (u8)arg0, 0x45, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
        return;
    }
    if (arg3 != 0) {
        var_2_3 = (arg0 & 0xFF) | 0xFFE92C00;
    } else {
        var_2_3 = (arg0 & 0xFF) | 0xFFAE2000;
    }
    temp_17_3 = var_2_3 >> 8;
    func_0025f3f0(122.0f + fparg0, 35.0f + fparg1, fparg2, temp_17_3, (u8)arg0, 0x44, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
    func_0025f3f0(184.0f + fparg0, 36.0f + fparg1, fparg2, temp_17_3, (u8)arg0, 0x45, 0, (u8 *)(*(s32 *)(arg4 + 0x398)), 1);
}
// FUN_002AA2B0
void func_002aa2b0(void *arg0) {
    typedef struct { u8 pad[0x3A4]; s32 handle; } Work;
    Work *work = arg0;
    if (work->handle != 0) {
        H_Cdvd_Destroy((u8 *)work->handle);
        work->handle = 0;
    }
    D_008873EC[0](work);
}
// FUN_002AA300
/* The caller retains the task handle returned by registration. */
s32 func_002aa300(u8 *parent, s32 arg1) {
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
    return (s32)func_00451fc0(parent, (const void *)(&D_00763918), 0xF, 0, 0, func_002a4b10, func_002a4cb0, work);
}
