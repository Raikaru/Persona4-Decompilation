/* Original translation unit btlShuffleSeq.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct ShuffleUnit {
    u8 data[0xE8];
} ShuffleUnit;

extern void func_0046d730(const void *file, u32 line);
extern u32 func_003b7060();
extern s32 func_00106330(s32 a);
extern s32 func_00375970(u8 *a);
extern s32 func_00375a00(u8 *a);
extern s32 func_00375a50(u8 *a);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00375d50(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void func_00375dd0(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void func_00375fa0(u8 *a, s32 b, s32 c, f32 *d, f32 *e, f32 *f, f32 g, f32 h);
extern void func_003760f0(u8 *ctx, s32 a, s32 b, s32 c, f32 *d, f32 *e);
extern void func_00376290(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern void func_003dc740(f32 *dst, f32 *src, s32 c, f32 d);
extern s32 func_0036de60(u8 *a);
extern u16 func_0036dee0(u8 *a);
extern s32 func_00378530(s32 a, s32 b);
extern void func_00374910(u8 *a);
extern s32 func_00379f90(u8 *a);
extern s32 func_0037ad10(u8 *a);
extern s32 func_0037bc80(u8 *a);
extern s32 func_0037da60(u8 *a);
extern s32 func_0037f6e0(u8 *a);
extern s32 func_00383ae0(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00383c00(s32 a);
extern s32 func_00383c20(s32 a);
extern void func_00373f00(u8 *a);
extern void func_00374730(u8 *a);
extern void func_00388d10(s32 a);
extern void func_0038d890(s32 a);
extern void func_0038d020(s32 a);
extern void func_002bd7b0(s32 a);
extern void func_002bd840(s32 a);
extern void func_002bb7c0(s32 a);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 a);
extern void func_002bb4e0(void);
extern s32 func_002bb140(void);
extern void func_0043f9c8(void *dst, s32 c, s32 n);
extern void func_002baac0(s32 a);
extern void func_002baf40(s32 a);
extern void func_002bb050(s32 a);
extern void func_002bbf60(void);
extern void func_002bad10(s32 a);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern void func_00442830(char *dst, s32 value);
extern char *func_002438b0(s32 a);
extern void func_002bbd20(s32 a, char *b);
extern void func_00389200(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00389280(s32 a);
extern s32 func_003891e0(s32 a);
extern void func_003891b0(s32 a, s32 b, s32 c, s32 d);
extern void func_003892c0(s32 a);
extern void func_0036d990(u8 *a, u8 *b);
extern void func_0036db60(u8 *a);

extern char D_0064EAA0[];
extern s32 D_00763AD0;
extern s32 D_00763AD4;


// FUN_00378600
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00378600);

// FUN_00378930
s32 func_00378930(u8 *arg0, s32 arg1) {
    s32 i;

    i = 0;
    while (i < arg1) {
        if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

// FUN_003789D0
s32 func_003789d0(u8 *arg0, s32 arg1) {
    s32 i;

    i = 0;
    while (i < arg1) {
        if (func_00375a00(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

// FUN_00378A70
s32 func_00378a70(u8 *arg0, s32 arg1) {
    s32 i;
    s32 r;
    s32 ok1;
    s32 ok2;

    i = 0;
    while (i < arg1) {
        if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            r = 0;
            goto join1;
        }
        i++;
    }
    r = 1;
join1:
    ok1 = (r != 0);
    if (ok1 != 0) {
        i = 0;
        while (i < arg1) {
            if (func_00375a00(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join2;
            }
            i++;
        }
        r = 1;
join2:
        ok1 = (r != 0);
    }
    ok2 = (ok1 != 0);
    if (ok2 != 0) {
        i = 0;
        while (i < arg1) {
            if (func_00375a50(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join3;
            }
            i++;
        }
        r = 1;
join3:
        ok2 = (r != 0);
    }
    return ok2;
}

// FUN_00378BF0
u16 func_00378bf0(void) {
    f32 x;

    if (func_00106330(0x1431) == 0) {
        return 0x1A;
    }
    func_003b7060();
    x = 0.0f;
    return (u16)x;
}

// FUN_00378C80
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00378c80);

// FUN_00378DF0
void func_00378df0(u8 *arg0, s32 arg1) {
    f32 sp58[2];
    f32 sp48[3];
    f32 sp30[4];

    sp58[0] = 316.0f;
    sp58[1] = 211.0f;
    func_0036dc60(arg0 + arg1 * 0xFB0, sp58, sp48, 160.0f);
    func_00375d50(arg0, arg1, 0.0f, 15.0f, NULL, sp48);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    func_003760f0(arg0, arg1, 0, 0xF, NULL, sp30);
}

// FUN_00378EC0
void func_00378ec0(u8 *arg0, s32 arg1) {
    f32 sp58[2];
    f32 sp48[3];
    f32 sp30[4];

    sp58[0] = 316.0f;
    sp58[1] = 211.0f;
    func_0036dc60(arg0 + arg1 * 0xFB0, sp58, sp48, 160.0f);
    func_00375d50(arg0, arg1, 0.0f, 0.0f, sp48, sp48);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    func_003760f0(arg0, arg1, 0, 0xF, NULL, sp30);
}

// FUN_00378F90
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00378f90);


// FUN_00379090
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379090);

// FUN_00379150
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379150);


// FUN_00379240
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379240);

// FUN_00379420
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379420);

// FUN_003798D0
void func_003798d0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x1F23C) = 0;
    func_002bd7b0(*(s32 *)(arg0 + 0x1F2E0));
    func_002bd840(arg1);
}

// FUN_00379920
s32 func_00379920(u8 *arg0) {
    u8 *base = arg0 + 0x1F23C;

    switch (*(s32 *)base) {
    case 0:
        *(s32 *)base = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)base = 2;
            func_002bb4e0();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

// FUN_003799D0
void func_003799d0(u8 *arg0) {
    func_0043f9c8(arg0 + 0x1F244, 0, 8);
    func_002baac0(*(s32 *)(arg0 + 0x1F2DC));
    func_002baf40(0x14);
    func_002bb050(0);
    func_002bbf60();
    func_002bad10(0x13);
    func_0045af60(0, 4, 0, 2);
}

// FUN_00379A70
s32 func_00379a70(u8 *arg0) {
    u8 *base = arg0 + 0x1F244;

    switch (*(s32 *)base) {
    case 0:
        *(s32 *)base = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            s32 r = func_002bb140();
            switch (r) {
            case 0:
                *(s32 *)(base + 4) = 1;
                break;
            case 1:
                *(s32 *)(base + 4) = 0;
                break;
            default:
                func_0046d730(D_0064EAA0, 0x22F);
                break;
            }
            func_002bb1e0(1);
            *(s32 *)base = 2;
            func_002bb4e0();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

// FUN_00379B70
s32 func_00379b70(u8 *arg0) {
    s32 state;

    func_00374910(arg0);
    state = *(s32 *)(arg0 + 0x1F2FC);
    switch (state) {
    case 0:
        return func_00379f90(arg0);
    case 1:
        return func_0037ad10(arg0);
    case 2:
        return func_0037bc80(arg0);
    case 3:
        return func_0037da60(arg0);
    case 4:
        return func_0037f6e0(arg0);
    default:
        func_0046d730(D_0064EAA0, 0x25A);
        return 0;
    }
}

// FUN_00379C70
s32 func_00379c70(u8 *arg0, s32 arg1) {
    s32 var_17 = 0;
    s32 var_16;
    s32 result;

    if (arg1 < 0) {
        var_16 = -1;
    } else {
        u8 *p = arg0 + arg1 * 0xFB0;
        var_16 = func_0036de60(p);
        if (var_16 == 0) {
            var_17 = func_0036dee0(p) & 0xFFFF;
        }
        *(u16 *)(arg0 + 0x1F2F4) |= 4;
    }
    *(s32 *)(arg0 + 0x1F308) = arg1;
    result = func_00383ae0(*(s32 *)(arg0 + 0x1F2A8), var_16, var_17, *(s32 *)(arg0 + 0x1F2FC));
    *(s32 *)(arg0 + 0x1F290) = result;
    return result;
}

// FUN_00379D70
s32 func_00379d70(u8 *arg0) {
    if (func_00383c00(*(s32 *)(arg0 + 0x1F290)) != 0) {
        s32 r = func_00383c20(*(s32 *)(arg0 + 0x1F290));
        *(s32 *)(arg0 + 0x1F290) = 0;
        switch (r) {
        case 1:
            return 1;
        case 2:
            func_00378600(arg0);
            func_00373f00(arg0);
            func_00374730(arg0);
            func_00388d10(*(s32 *)(arg0 + 0x1F294));
            func_0038d890(*(s32 *)(arg0 + 0x1F29C));
            func_0038d020(*(s32 *)(arg0 + 0x1F298));
            return 0;
        default:
            func_0046d730(D_0064EAA0, 0x296);
            return 1;
        }
    }
    return 0;
}
