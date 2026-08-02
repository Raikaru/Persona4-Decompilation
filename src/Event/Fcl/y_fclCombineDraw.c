#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclCombineDraw.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;


extern void func_0044ea90(const void *arg0, u32 arg1);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern s32 func_00117780(s32, s32, s32, s32, s32);
extern void func_00314010(u8 *arg0);
extern void func_003142f0(u8 *arg0);
extern s32 func_00106330(s32);
extern s32 func_00452490(s32);
extern void func_0011b9e0(u8 *arg0);
extern void func_0011d100(u8 *arg0, f32 *arg1);
extern void func_0011b480(s32, s32, s32, s32);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(s32, s32, s32, s8);
extern void func_0011c2c0(s32, s32, s32, s8);
extern void func_0011bdc0(u8 *arg0);
extern void func_0011bf10(u8 *arg0);
extern void func_002b2970(s64 *out, f32 x, f32 y);
extern void func_002b6c30(s32 a, s64 b, s32 c, f32 d);
extern void func_002b6a70(s32, s32, s32, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern void func_002b7750(s32, s16);
extern void func_002b2a60(void *arg0, s32, s32, s32, s32);
extern f32 iGpffff8360;
extern s32 func_00331560(u8 *arg0);
extern void func_0025ecd0(s32, s32, s16, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_0046b0d0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
extern void func_002777f0(s8 arg0);
extern void func_00454bd0(u8 *arg0);
extern u8 *(*D_008873EC[])(u8 *);
extern char D_00644D30[];
extern char D_00644D50[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern f32 D_00644C90[];
extern s8 D_00749530[];
extern s64 iGpffffa900;
extern s64 iGpffffa908;

// FUN_00314320
s32 func_00314320(s32 arg0) {
    s32 ret;
    u8 *p;

    func_0044ea90(D_00644D30, 0x16D);
    p = (u8 *)D_008873F4[0](1, 0x14, 0x40000);
    func_0043f9c8(p, 0, 0x14);
    ret = func_00451fc0(arg0, D_00644D50, 0xF, 0, 0, func_00314010,
                       func_003142f0, p);
    *(s8 *)p = 7;
    *(s32 *)(p + 4) = func_00117780(ret, 0xF, 3, 5, 5);
    *(s8 *)(p + 0xD) = 0;
    return ret;
}

// FUN_00314400
void func_00314400(u8 *arg0, s8 arg1) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0) = 0x10;
    if (arg1 == 1) {
        *(s8 *)(t + 0) = 0xF;
        func_0011bc70((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_00314450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314450);
// FUN_003144D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003144d0);
// FUN_00314560
void func_00314560(u8 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (arg3 == 0) {
        *(s32 *)(t + 8) = arg1;
        *(s8 *)(t + 0xC) = arg2;
        func_0011c180(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
        return;
    }
    *(s32 *)(t + 8) = arg1;
    *(s8 *)(t + 0xC) = arg2;
    func_0011c2c0(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
}
// FUN_003145E0
s32 func_003145e0(u8 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (func_00452490((s32)arg0) == 0) {
        return 0;
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        return 0;
    }
    return *(s8 *)(*(u32 *)(arg0 + 0x38)) < 6;
}

// FUN_00314660
s8 func_00314660(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_00314670
void func_00314670(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38)) = arg1;
}

// FUN_00314680
void func_00314680(u8 *arg0) {
    s64 sp18;
    f32 *p;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp18, (sp18 = iGpffffa900, p)));
}
// FUN_003146C0
void func_003146c0(u8 *arg0) {
    func_0011b9e0(*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
}

// FUN_003146F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003146f0);
// FUN_00314740
void func_00314740(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xD) = arg1;
}

// FUN_00314750
void func_00314750(u8 *arg0, s8 arg1) {
    u8 *t;
    s64 sp38;
    f32 *p;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp38, (sp38 = iGpffffa908, p)));
    if (arg1 == 0) {
        func_0011bdc0((u8 *)*(u32 *)(t + 4));
    } else {
        func_0011bf10((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_003147D0
u32 func_003147d0(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38) + 4);
}

// FUN_003147E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003147e0);

// FUN_00314EF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314ef0);

// FUN_00315310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315310);

// FUN_00315600
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);

// FUN_00316470
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316470);

// FUN_00316E80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316e80);

// FUN_00317240
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317240);
// FUN_00317320
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317320);
// FUN_00317410
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317410);

// FUN_00317900
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);

// FUN_00318840
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00318840);

// FUN_00318F30
void func_00318f30(s16 arg0) {
    s16 var;
    u8 *p;
    f32 fv;
    FclVec2 sp40;
    FclByte4 sp4C;
    s64 sp38;

    var = (s16)(arg0 * 2 + 0xDF);
    if (arg0 == 6) {
        var = 0xEF;
    } else if (arg0 == 7) {
        var = 0xEB;
    } else if (arg0 == 8) {
        var = 0xED;
    }
    func_002b7750(0x2F2, (s16)(var + 1));
    p = func_002b6150(var);
    sp40 = *(FclVec2 *)(p + 0x38);
    func_002b2970(&sp38, sp40.x - 15.0f, sp40.y - 7.0f);
    func_002b6c30(0x2F2, sp38, 0xAB, 58.0f);
    func_002b6a70(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    *(f32 *)(func_002b6150(0x2F2) + 0xA0) = fv;
    *(f32 *)(func_002b6150(0x2F2) + 0xAC) = fv;
    func_002b2a60(&sp4C, 0xE0, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2F2) + 0x85) = sp4C;
}

// FUN_003190D0
s32 func_003190d0(u8 *arg0) {
    u8 *t;
    s16 i;

    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < *(s8 *)(t + 0xB5); i++) {
        if (*(s8 *)(t + 0xB4) != i) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(*(s16 *)(t + i * 10 + 0xC8) + 0x20D)) + 0x10), 1) == 1) {
                return 1;
            }
        }
    }
    return (s16)func_002b6970(*(s16 *)(func_002b6150(0x1DC) + 0x10), 1) == 1;
}
// FUN_003191C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003191c0);

// FUN_0031AC10
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ac10);

// FUN_0031C2B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031c2b0);

// FUN_0031CCE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031cce0);

// FUN_0031D630
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031d630);

// FUN_0031DDF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ddf0);

// FUN_0031E320
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e320);

// FUN_0031E5B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);

// FUN_0031FA20
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);

// FUN_003205F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003205f0);

// FUN_00320970
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320970);

// FUN_00320B80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320b80);

// FUN_003212E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003212e0);

// FUN_003218A0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003218a0);

// FUN_00321E60
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00321e60);

// FUN_003233D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003233d0);

// FUN_00323D00
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);

// FUN_00324410
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324410);

// FUN_00324680
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324680);

// FUN_00324F80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324f80);

// FUN_00325450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00325450);

// FUN_00329310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329310);

// FUN_003297F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003297f0);

// FUN_00329E40
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);

// FUN_0032A960
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032a960);

// FUN_0032B000
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b000);

// FUN_0032B770
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b770);

// FUN_0032B9D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b9d0);

// FUN_0032C0C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c0c0);

// FUN_0032C480
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c480);

// FUN_0032C660
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c660);

// FUN_0032E570
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);

// FUN_0032F060
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032f060);

// FUN_0032F4D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032f4d0);

// FUN_0032FA30
void func_0032fa30(u8 *arg0, s16 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u8 *t;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    s32 idx;

    t = *(u8 **)(arg0 + 0x38);
    p1 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)&arg2;
    p2 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    idx = arg1 * 2;
    p3 = func_002b6150(*(s16 *)(idx + (s32)t + 0xB8));
    *(FclByte4 *)(p3 + 0x85) = *(FclByte4 *)&arg3;
    p4 = func_002b6150((s16)(arg1 + 0x2FF));
    *(FclByte4 *)(p4 + 0x85) = *(FclByte4 *)&arg4;
}
// FUN_0032FB60
s8 func_0032fb60(s8 arg0) {
    if (func_00106330(0x1306)) {
        arg0 = (s8)(D_00749530[arg0] - 4);
    }
    return arg0;
}
// FUN_0032FBC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032fbc0);

// FUN_00330060
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330060);

// FUN_003307B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003307b0);

// FUN_00330E50
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330e50);
// FUN_00330F20
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330f20);

// FUN_003312E0
void func_003312e0(u8 *arg0) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0046b0d0((u8 *)*(u32 *)(t + 4));
    func_0046b0d0((u8 *)*(u32 *)(t + 8));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x24));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x28));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x2C));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x30));
    func_002777f0(*(s8 *)(t + 0x44));
    func_00454bd0((u8 *)*(u32 *)(t + 0x1C));
    func_00454bd0((u8 *)*(u32 *)(t + 0x20));
    D_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00331390
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00331390);
