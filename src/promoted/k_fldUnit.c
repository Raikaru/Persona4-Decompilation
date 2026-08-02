/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*DAT_008873EC[])(void *);
extern s32 (*DAT_008873F4[])(s32, s32, s32);

extern void memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];
extern u8 D_007E8C00[];
extern u8 D_007EF9B0[];
extern u8 D_007E8BE0[];
extern u8 D_005F1500[];
extern u8 D_005F13C0[];
extern u8 D_005F1590[];
extern u8 D_005F15B0[];
extern u8 D_005F15C0[];
extern u8 D_005F15E0[];
extern u8 D_007E80A0[];

static s32 D_007643D8;
static s32 D_007643C8[2];
static s32 D_007643C0[2];
static u8 D_00763008[4];
static u8 D_00763010[4];
static u8 *D_00762EA0;
static s32 D_00764350;
static s32 D_007643E4;
static f32 D_007613EC;

typedef struct {
    u8 b[4];
} S4;

s32 func_00163c90(s32 arg0);
void func_00164020(u8 *arg0);
void func_00164fa0(s32 arg0);
void func_00165670(u8 *arg0, s32 arg1);
s32 func_00478140(s32 arg0, s32 arg1, s32 arg2);
s32 func_004782b0(s32 arg0);
void func_00440b68(u8 *arg0, u8 *arg1, s32 arg2);
s32 func_00454a60(u8 *arg0, s32 arg1);
s32 func_0014a200(void);
s32 func_0014a270(void);
s32 func_001668e0(u8 *arg0);
void func_0044ea90(u8 *arg0, s32 arg1);
void func_0044b7b0(f32 arg0);
u8 *func_0047a250(s32 arg0);
void func_0047a220(s32 arg0, u8 *arg1);
void func_004b14f0(u8 *arg0, u8 *arg1);
void func_004b13f0(u8 *arg0, u8 *arg1);
u8 *func_0047a2f0(s32 arg0);
void func_00146630(u16 arg0);
void func_0047a870(s32 arg0);
void func_004787e0(s32 arg0);
void func_00452080(s32 arg0);
s32 func_00162510(s32 arg0, s32 arg1);
s32 func_0015a160(void);
s32 func_001679d0(u8 *arg0);
u8 *func_001452b0(s32 arg0);
void func_0046d730(u8 *arg0, s32 arg1);
s32 func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2);
void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
s32 func_00161b10(u16 arg0, u16 arg1, u16 arg2);
s32 func_0015a320(void);
u8 *func_00161c80(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
s32 func_00451fc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, void (*arg5)(void *), void (*arg6)(void *), s32 arg7);





// FUN_00162C30
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162c30);



// FUN_00162E10
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162e10);



// FUN_00163990
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00163990);



// FUN_00163C90
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00163c90);



// FUN_00163FC0
s32 func_00163fc0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        if (func_00163c90(i) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00164020
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164020);



// FUN_00164170
void func_00164170(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        func_00164020(D_007EF9B0 + i * 0x750);
    }
}



// FUN_001641D0
void func_001641d0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00164020(D_007E8C00 + i * 0x750);
    }
}



// FUN_00164230
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164230);



// FUN_00164570
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164570);



// FUN_00164880
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164880);



// FUN_00164F40
s32 func_00164f40(void)
{
    return D_007643D8;
}



// FUN_00164F50
void func_00164f50(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00164fa0(i);
    }
}



// FUN_00164FA0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164fa0);



// FUN_00165270
void func_00165270(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0) {
            *(s32 *)(p + 0x50) = func_00478140(8, (u16)(*(u8 *)(p + 0x1CA) + 1), 0);
        }
    }
}



// FUN_00165300
s32 func_00165300(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0 && func_004782b0(*(s32 *)(p + 0x50)) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00165380
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165380);



// FUN_00165670
void func_00165670(u8 *arg0, s32 arg1)
{
    u8 *p = arg0;
    u8 *q;
    u8 *s;
    u8 *d;
    s32 n;
    s32 v;
    s32 i;
    v = *(u32 *)(p + 0x48) != 0 && *(u32 *)(p + 0x54) != 0;
    if (v != 0) {
        q = func_0047a2f0(*(u32 *)(p + 0x50));
        s = q;
        n = 8;
        d = p;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            n--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (n > 0);
        func_00146630(*(u16 *)(*(u32 *)(p + 0x54)));
        *(u32 *)(p + 0x54) = 0;
        if (*(u32 *)(p + 0x50) != 0) {
            func_0047a870(*(u32 *)(p + 0x50));
            func_0047a220(*(u32 *)(p + 0x50), D_00763010);
        }
        if (*(u32 *)(p + 0x50) != 0 && arg1 == 1) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u32 *)(p + 0x50) + i * 12 + 0x28C) |= 1;
            }
            func_004787e0(*(u32 *)(p + 0x50));
            *(u32 *)(p + 0x50) = 0;
        }
        if (*(u32 *)(p + 0x1B0) != 0) {
            func_00452080(*(u32 *)(p + 0x1B0));
            *(u32 *)(p + 0x1B0) = 0;
        }
        if (*(u32 *)(p + 0x1B8) != 0) {
            func_00452080(*(u32 *)(p + 0x1B8));
            *(u32 *)(p + 0x1B8) = 0;
        }
        if (*(u32 *)(p + 0x1B4) != 0) {
            func_00452080(*(u32 *)(p + 0x1B4));
            *(u32 *)(p + 0x1B4) = 0;
        }
    }
}



// FUN_001657E0
void func_001657e0(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00165670(D_007EF9B0 + i * 0x750, 0);
    }
}



// FUN_00165840
void func_00165840(s32 arg0)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00165670(D_007E8C00 + i * 0x750, arg0);
    }
}



// FUN_001658B0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001658b0);



// FUN_00165B00
void func_00165b00(void)
{
    s32 i;
    s32 j = 0;
    for (i = 0; i < 2; i++) {
        u8 *p = D_007E8BE0 + i * 16;
        if (*(s32 *)p != 0) {
            D_007643C8[j] = func_00478140(*(u16 *)(p + 4), *(u16 *)(p + 6), 0);
            func_00440b68(D_00763008, D_005F1500, 0x939);
            D_007643C0[j] = func_00454a60(D_005F13C0 + (*(s32 *)(p + 0xC) << 5), 0);
            j++;
        }
    }
}



// FUN_00165BE0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165be0);



// FUN_00165FB0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165fb0);



// FUN_001662D0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001662d0);

// FUN_001664A0
void func_001664a0(void)
{
    s32 i;
    s32 k;
    s32 j = 0;
    u8 *node;
    u8 *p;
    if (D_00764350 != 1) {
        for (i = 0; i < 8; i++) {
            p = D_007E80A0 + i * 360;
            if (*(s32 *)p != 0) {
                node = func_001452b0(0x10);
                if (node == 0) {
                    return;
                }
                for (k = 0; k < *(u16 *)(p + 0xE); k++) {
                    node = *(u8 **)(node + 0x138);
                    if (node == 0) {
                        func_0046d730(D_005F1500, 0xA87);
                    }
                }
                {
                    u8 *s;
                    u8 *d;
                    s32 n;
                    d = D_007E80A0 + (u32)i * 360 + 0x10;
                    n = 0x2A;
                    s = node;
                    do {
                        u32 w0 = *(u32 *)s;
                        u32 w1 = *(u32 *)(s + 4);
                        s += 8;
                        n--;
                        *(u32 *)d = w0;
                        *(u32 *)(d + 4) = w1;
                        d += 8;
                    } while (n > 0);
                }
                func_00165fb0(D_007E80A0 + (u32)i * 360, node, 0x3FE - j);
                j++;
            }
        }
    }
}// FUN_00166600
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00166600);



// FUN_001668E0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001668e0);

// FUN_00166B10
void func_00166b10(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00166B40
s32 func_00166b40(u8 *arg0, s32 arg1)
{
    s32 r;
    if (func_0014a200() == 0 && func_0014a270() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xB93);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(arg0, D_005F1590, 0xF, 0, 0, (void (*)(void *))func_001668e0, (void (*)(void *))func_00166b10, r);
    *(s32 *)(r + 0xC) = arg1;
}



// FUN_00166C30
u32 func_00166c30(u8 *arg0)
{
    if (arg0 == 0) {
        return 1;
    } else {
        return (*(u32 *)(*(u32 *)(arg0 + 0x38)) ^ 3) < 1;
    }
}



// FUN_00166C60
void func_00166c60(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        *(s32 *)(*(u32 *)(arg0 + 0x38) + 4) = arg1;
    }
}



// FUN_00166C80
s32 func_00166c80(u8 *arg0)
{
    u8 *p;
    u8 *node;
    u8 *q;
    u8 buf1[4];
    u8 buf2[3];
    u8 buf3[3];
    s32 f;
    s32 i;
    p = *(u8 **)(arg0 + 0x38);
    func_0044b7b0(D_007613EC * (f32)(*(s32 *)(p + 8)) / 10.0f);
    q = func_0047a250(*(u32 *)(*(u32 *)(p + 4) + 0x50));
    *(S4 *)buf1 = *(S4 *)q;
    buf1[0] = 0x34;
    buf1[1] = 0x2E;
    buf1[2] = 0x61;
    *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    if (*(s32 *)(p + 8) > 10) {
        *(s32 *)(p + 8) = 0;
    }
    f = *(u8 *)(*(u32 *)(p + 4) + 0x1CA);
    if (f == 0) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        node = *(u8 **)b;
        while (node != NULL) {
            if (*(u8 **)(node + 8) != NULL) {
                func_004b14f0(*(u8 **)(node + 8), buf2);
                buf2[0] = 0xFF;
                buf2[1] = 0xFF;
                buf2[2] = 0xFF;
                func_004b13f0(*(u8 **)(node + 8), buf2);
            }
            node = *(u8 **)(node + 0x10);
        }
    } else if (f == 1) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        u8 *c = *(u8 **)b;
        u8 *d = *(u8 **)(c + 0x10);
        node = *(u8 **)(d + 0x10);
        if (*(u8 **)(node + 8) != NULL) {
            func_004b14f0(*(u8 **)(node + 8), buf3);
            buf3[0] = buf1[0];
            buf3[1] = buf1[1];
            buf3[2] = buf1[2];
            func_004b13f0(*(u8 **)(node + 8), buf3);
        }
    }
    func_0047a220(*(u32 *)(*(u32 *)(p + 4) + 0x50), buf1);
    return 0;
}



// FUN_00166E30
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00166e30);



// FUN_00167120
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00167120);

// FUN_001673F0
void func_001673f0(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00167420
s32 func_00167420(u8 *arg0, u8 *arg1)
{
    s32 r;
    func_0044ea90(D_005F1500, 0xD36);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(arg0, D_005F15C0, 0xF, 0, 0, (void (*)(void *))*(void **)(D_005F15B0 + (*(u16 *)(arg1 + 0x1C8) << 2)), (void (*)(void *))func_001673f0, r);
    *(u8 **)(r + 4) = arg1;
    *(s32 *)(r + 0xC) = 0x28;
    *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) |= 0x80;
    if (*(u8 *)(arg1 + 0x1CA) == 1) {
        *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) &= ~0x100;
    }
}

// FUN_00167530
void func_00167530(void)
{
    memset(D_007E8020, 0, 0x40);
}





// FUN_00167560
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00167560);



// FUN_001679D0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001679d0);

// FUN_00167D60
void func_00167d60(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00167D90
s32 func_00167d90(u8 *arg0)
{
    s32 r;
    u32 acc = 0;
    s32 i = 0;
    s32 j = 0;
    while (i < 4) {
        u32 v = *(u32 *)arg0;
        if (v != 0) {
            acc |= (v & 0xFF) << (j * 8);
            j++;
        }
        i++;
        arg0 += 8;
    }
    if (acc == 0) {
        return 0;
    }
    if (func_00162510(*(u16 *)D_00762EA0, *(u16 *)(D_00762EA0 + 4)) == 1 || func_0015a160() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xED8);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x28, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(NULL, D_005F15E0, 0xF, 0, 0, (void (*)(void *))func_001679d0, (void (*)(void *))func_00167d60, r);
    *(s32 *)(r + 4) = acc & 0xFF;
    *(s32 *)(r + 8) = (acc >> 8) & 0xFF;
    *(s32 *)(r + 0xC) = (acc >> 16) & 0xFF;
    *(s32 *)(r + 0x10) = (acc >> 24) & 0xFF;
}
