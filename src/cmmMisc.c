/* Original translation unit cmmMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_00440b68(const char *fmt, const char *file, s32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00456150(void *handle);
extern u8 *func_00455ea0(void *handle, s32 index, void *out);
extern void func_0046d730(const char *file, s32 line);
extern void func_0046d700(const char *file, s32 line, char *fmt, s32 value);
extern s32 func_001060b0(void);
extern s32 func_00106330(s32 flag);
extern s32 func_00107240(s32 idx);
extern s32 func_00107ac0(s32 idx);
extern s32 func_001093a0(s32 idx);
extern s8 func_00248760(s32 idx);
extern s32 func_001077f0(s32 idx);
extern s32 func_00109280(s32 idx);
extern s32 func_00109300(s32 idx);
extern s32 func_0010b6f0(void);
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 func_00110d30(s32 idx);
extern s32 func_00249010();

extern char D_006359D0[];
extern char D_006359E0[];
extern char D_007636F0;
extern char D_007636F8;
extern u8 *D_00881480[];
extern u8 *D_00881484[];
extern s32 D_0088149C[];
extern s32 D_008814A0[];
extern s32 D_008814A4[];
extern s32 D_008814A8[];
extern s32 D_008814AC[];
extern u8 *D_008814B0[];
extern s32 D_008814B8[];
extern u8 *D_008814BC[];
extern u8 *D_008814C4[];
extern u8 *D_008814D4[];
extern u8 *D_008814D8[];
extern u8 *D_008814DC[];
extern u8 *D_008814E0[];
extern u8 *D_008814E4[];
extern s32 D_008814E8[];
extern s32 D_008814EC[];
extern u8 *D_00881490[];
extern u8 *D_00881494[];
extern u8 *D_00881498[];
extern u8 *D_008814C0[];
extern u8 *D_008814C8[];
extern s32 D_008814CC[];
extern u8 *D_008814D0[];

// FUN_00246700
void func_00246700(void) {
    u32 sp3C;
    s32 i;
    void *handle;

    func_00440b68(&D_007636F0, D_006359D0, 0x3F);
    func_00456150(handle = func_00454a60(D_006359E0, 1));
    for (i = 0; i < 0x1C; i++) {
        D_00881480[i] = func_00455ea0(handle, i, &sp3C);
    }
}

// FUN_002467B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002467b0);

// FUN_00246830
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246830);

// FUN_002468A0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002468a0);

// FUN_00246910
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246910);

// FUN_00246940
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);

// FUN_00246970
s32 func_00246970(void) {
    return D_008814A4[0];
}

// FUN_00246980
s32 func_00246980(s16 arg0, s16 arg1) {
    s32 base = D_008814A8[0] + 8;

    if (arg0 >= 5) {
        func_0046d730(D_006359D0, 0xBC);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xBD, &D_007636F8, arg1);
    }
    return base + arg0 * 0x41 + (arg1 - 1) * 0xD;
}

// FUN_00246A50
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246a50);

// FUN_00246B10
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246b10);

// FUN_00246B80
s32 func_00246b80(void) {
    return D_008814B8[0] + 8;
}

// FUN_00246BA0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246ba0);

// FUN_00246C20
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246c20);

// FUN_00246C90
u8 *func_00246c90(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D4[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D4[0] + 8);
}

// FUN_00246CD0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246cd0);

// FUN_00246D50
u8 *func_00246d50(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D8[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D8[0] + 8);
}

// FUN_00246D90
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246d90);

// FUN_00246E10
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246e10);

// FUN_00246E90
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246e90);

// FUN_00246F10
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246f10);

// FUN_00247020
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247020);

// FUN_00247270
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247270);

// FUN_002474F0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002474f0);

// FUN_00247770
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247770);

// FUN_00247820
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247820);

// FUN_00247900
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247900);

// FUN_00247C20
s32 func_00247c20(s16 arg0) {
    s32 i = 0;
    s32 key = (s32)arg0;

    while (i < (func_0010b6f0() & 0xFFFF)) {
        if (key == (func_00109280(func_00109300(i & 0xFFFF) & 0xFFFF) & 0xFF)) {
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_00247CB0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247cb0);

// FUN_00247DD0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247dd0);

// FUN_00247EC0
s32 func_00247ec0(s32 seed) {
    u8 *p = D_00881498[0] + 8;
    s32 a, b;
    s32 a0, b0;
    s32 i;
    s32 count;

    func_001104d0(seed, &a, &b);
    count = *(s32 *)(D_00881498[0] + 4);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return 1;
        }
        p += 2;
        i++;
    }
    return 0;
}

// FUN_00247F60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247f60);

// FUN_00248040
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248040);

// FUN_002480E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002480e0);

// FUN_00248240
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248240);

// FUN_002483C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002483c0);

// FUN_002485E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002485e0);

// FUN_00248760
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248760);

// FUN_002487E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002487e0);

// FUN_002488E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002488e0);

// FUN_002489C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002489c0);

// FUN_00248A60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248a60);

// FUN_00248B80
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248b80);

// FUN_00248D00
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248d00);

// FUN_00248D80
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248d80);

// FUN_00248E20
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248e20);

// FUN_00248F20
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248f20);

// FUN_00249010
s32 func_00249010(s32 seed) {
    u8 *base = D_008814D0[0];
    u8 *p = base + 8;
    s32 count = *(s32 *)(base + 4);
    s32 a, b;
    s32 a0, b0;
    s32 i;

    func_001104d0(seed, &a, &b);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return i;
        }
        p += 0x24;
        i++;
    }
    return -1;
}

// FUN_002490B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002490b0);

// FUN_00249180
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249180);

// FUN_00249230
s32 func_00249230(void) {
    s32 seed;
    u8 *base8 = D_008814D0[0] + 8;
    s32 idx = func_00249010(seed);
    u8 *p;

    if (idx != -1) {
        p = base8 + idx * 0x24;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        return 0;
    }
    return 1;
}

// FUN_002492B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002492b0);

// FUN_00249370
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249370);

// FUN_002494C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002494c0);

// FUN_00249670
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249670);

// FUN_00249770
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249770);

// FUN_00249960
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249960);

// FUN_00249A60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249a60);
