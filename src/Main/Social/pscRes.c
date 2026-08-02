/* Consolidated Persona 4 source units. */
/* Original translation unit pscRes.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern void func_003ec330(s32 arg0);
extern u32 *func_0036ce10(s32 arg0);
extern void *func_0036cad0(s32 arg0, s32 arg1);
extern s32 func_0036cd70(s32 arg0);
extern void func_0036cf80(s32 arg0);
extern s32 func_0036cee0(void);
extern u32 *func_0036d060(void);
extern s32 func_00442088(char *buf, char *fmt, ...);
extern void func_00440b68(char *fmt, ...);
extern s32 func_00454a60(void *msg, s32 kind);
extern char D_00723A78;
extern char D_0064E4F0[];
extern char D_0064E510[];
extern char D_0064E530[];
extern char D_00723A80;
extern char D_00723A88;
extern char D_00723A90;
extern char D_00723A98;
extern s32 func_0036ca20(s32 arg0, s32 arg1);
extern void func_0036cbc0(s32 arg0, s32 arg1);
extern s32 func_0036ccc0(void);
extern void func_00442830(char *dst, char *src);
extern char D_0064E550[];
extern char D_0064E570[];
extern void *func_0036d3e0(void *arg0);
extern void *func_003ec590(s32 a, s32 b, s32 c, s32 d);
extern void *func_003ec3d0(void *a, s32 b);
extern void func_003ec2e0(void *a);
extern void *func_003ec6a0(void *a, s32 b, s32 c);
extern void func_003ec2a0(void *a);
extern const u8 D_0064E4E0[];
extern void *D_0072469C;


// FUN_0036B650
void func_0036b650(void *arg0) {
    s32 i;
    void *p;

    if (D_0072469C != 0) {
        func_0046d730(D_0064E4E0, 0x90);
    }
    p = arg0;
    *(s32 *)((u8 *)p + 0x00) = 0;
    *(s32 *)((u8 *)p + 0x18) = 0;
    *(s32 *)((u8 *)p + 0x1C) = 0;
    *(s32 *)((u8 *)p + 0x10) = 0;
    *(s32 *)((u8 *)p + 0x14) = 0;
    *(s32 *)((u8 *)p + 0x04) = 0;
    *(s32 *)((u8 *)p + 0x08) = 0;
    *(s32 *)((u8 *)p + 0x0C) = 0;
    *(s32 *)((u8 *)p + 0x48) = 0;
    *(s32 *)((u8 *)p + 0x4C) = 0;
    for (i = 0; i < 0x20; i++) {
        *(u32 *)((u8 *)p + i * 0x124 + 0x294) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        *(u32 *)((u8 *)p + i * 0x14 + 0x54) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        *(u32 *)((u8 *)p + i * 0x10 + 0x194) = 0;
    }
    D_0072469C = arg0;
}

// FUN_0036B750
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036b750);

// FUN_0036BB60
s32 func_0036bb60(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x20; i++) {
        if (*(u32 *)((u8 *)p + i * 0x124 + 0x294) & 1) {
            break;
        }
    }
    return i < 0x20;
}

// FUN_0036BBF0
void func_0036bbf0(void) {
    u8 *p;
    s32 i;
    s32 j;
    u32 v;
    u8 *e;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (*(u32 *)(p + 0x10) & 0x10) {
        func_003ec330(*(s32 *)(p + 0xC));
    }
    if (*(u32 *)(p + 0x10) & 1) {
        func_003ec330(*(s32 *)(p + 4));
    }
    if (*(u32 *)(p + 0x10) & 2) {
        func_003ec330(*(s32 *)(p + 8));
    }
    if (*(u32 *)(p + 0x10) & 4) {
        for (i = 0; i < 7; i++) {
            func_003ec330(*(s32 *)(p + i * 4 + 0x24));
        }
    }
    if (*(u32 *)(p + 0x10) & 8) {
        for (i = 0; i < 2; i++) {
            func_003ec330(*(s32 *)(p + i * 4 + 0x40));
        }
    }
    for (j = 0; j < 0x10; j++) {
        v = *(u32 *)(p + j * 0x14 + 0x54);
        if (!(~v & 1)) {
            if (!(v & 2)) {
                func_0046d730(D_0064E4E0, 0x13F);
            }
            e = p + j * 0x14 + 0x54;
            func_003ec330(*(s32 *)(e + 0xC));
        }
    }
    for (j = 0; j < 0x10; j++) {
        v = *(u32 *)(p + j * 0x10 + 0x194);
        if (!(~v & 1)) {
            if (!(v & 2)) {
                func_0046d730(D_0064E4E0, 0x148);
            }
            e = p + j * 0x10 + 0x194;
            func_003ec330(*(s32 *)(e + 8));
        }
    }
    D_0072469C = 0;
}


// FUN_0036BE00
s32 func_0036be00(void) {
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(*(u32 *)((u8 *)p + 0x10) & 1)) {
        func_0046d730(D_0064E4E0, 0x155);
    }
    return *(s32 *)((u8 *)p + 4);
}

// FUN_0036BE70
s32 func_0036be70(void) {
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(*(u32 *)((u8 *)p + 0x10) & 2)) {
        func_0046d730(D_0064E4E0, 0x15F);
    }
    return *(s32 *)((u8 *)p + 8);
}

// FUN_0036BEE0 NONMATCHING
// Measured floor (nd 16, obj 232B/win 272B): same allocator fold as sibling
// function 0036BFF0 — mwcc keeps (p + i*0x14) folded in s0 across the 0x171
// assert
// call (sll->v0; addu s0,s0,v0; lw(s0); lw(s0)) where retail keeps i*0x14 in
// s1 via in-place shift (sll s1,v0,2) and re-adds per access (addu v0,s1,s0;
// lw(v0)). Loop and dispatch match byte-for-byte.
#ifdef NON_MATCHING
s32 func_0036bee0(s32 arg0, s32 arg1) {
    s32 i;
    s32 v58;
    s32 v5c;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        v58 = *(s32 *)((u8 *)p + i * 0x14 + 0x58);
        if (v58 == arg0) {
            v5c = *(s32 *)((u8 *)p + i * 0x14 + 0x5C);
            if (v5c == arg1) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x170);
    }
    i = i * 0x14;
    if (!(*(u32 *)(i + (u8 *)p + 0x54) & 2)) {
        func_0046d730(D_0064E4E0, 0x171);
    }
    return *(s32 *)(i + (u8 *)p + 0x60);
}
#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036bee0);
#endif

// FUN_0036BFF0 NONMATCHING
// Measured floor (nd 12, obj 212B/win 224B): mwcc folds (p + i<<4) into a
// callee-saved register across the 0x184 assert call and emits sll->v0,
// addu->s0, lw(s0), lw(s0) where retail keeps p in s0 and i<<4 in s1 in place
// and re-adds per access (sll s1,s1,4; addu v0,s1,s0; lw(v0); addu; lw(v0)).
// Tried: inline i*0x10, i<<=4/i*=0x10, index-first operand order, u8* base,
// volatile lvalues, declaration order, optimization_level 3 (nd 52) — all 12.
#ifdef NON_MATCHING
s32 func_0036bff0(s32 arg0) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = arg0 & 0xFFFF; i < 0x10; i++) {
        v = *(u16 *)((u8 *)p + i * 0x10 + 0x198);
        if (v == key) {
            break;
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x182);
    }
    i <<= 4;
    if (!(*(u32 *)(i + (u8 *)p + 0x194) & 2)) {
        func_0046d730(D_0064E4E0, 0x184);
    }
    return *(s32 *)(i + (u8 *)p + 0x19C);
}
#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036bff0);
#endif

// FUN_0036C0D0
s32 func_0036c0d0(void) {
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(*(u32 *)((u8 *)p + 0x10) & 0x10)) {
        func_0046d730(D_0064E4E0, 0x18E);
    }
    return *(s32 *)((u8 *)p + 0xC);
}

// FUN_0036C140
void func_0036c140(s32 arg0, s32 arg1) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = func_0036cad0(arg0, arg1);
    if (*(s32 *)((u8 *)p + 0x10) == 0) {
        func_0046d730(D_0064E4E0, 0x19B);
    }
    v = *(s32 *)((u8 *)p + 0x10) - 1;
    *(s32 *)((u8 *)p + 0x10) = v;
    if (v == 0) {
        if (!(*(u32 *)((u8 *)p + 0) & 2)) {
            func_0046d730(D_0064E4E0, 0x1A4);
        }
        func_003ec330(*(s32 *)((u8 *)p + 0xC));
        *(u32 *)((u8 *)p + 0) &= ~2;
        *(u32 *)((u8 *)p + 0) &= ~1;
    }
}

// FUN_0036C230
void func_0036c230(s32 arg0) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = func_0036ce10(arg0);
    if (*(s32 *)((u8 *)p + 0xC) == 0) {
        func_0046d730(D_0064E4E0, 0x1B4);
    }
    v = *(s32 *)((u8 *)p + 0xC) - 1;
    *(s32 *)((u8 *)p + 0xC) = v;
    if (v == 0) {
        if (!(*(u32 *)((u8 *)p + 0) & 2)) {
            func_0046d730(D_0064E4E0, 0x1BD);
        }
        func_003ec330(*(s32 *)((u8 *)p + 8));
        *(u32 *)((u8 *)p + 0) &= ~2;
        *(u32 *)((u8 *)p + 0) &= ~1;
    }
}

// FUN_0036C310
void func_0036c310(void) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (*(s32 *)((u8 *)p + 0x4C) == 0) {
        func_0046d730(D_0064E4E0, 0x1DF);
    }
    v = *(s32 *)((u8 *)p + 0x4C) - 1;
    *(s32 *)((u8 *)p + 0x4C) = v;
    if (v == 0) {
        func_003ec330(*(s32 *)((u8 *)p + 8));
        *(s32 *)((u8 *)p + 0x10) &= ~2;
    }
}

// FUN_0036C3B0
void func_0036c3b0(void) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (*(s32 *)((u8 *)p + 0x50) == 0) {
        func_0046d730(D_0064E4E0, 0x1F3);
    }
    v = *(s32 *)((u8 *)p + 0x50) - 1;
    *(s32 *)((u8 *)p + 0x50) = v;
    if (v == 0) {
        func_003ec330(*(s32 *)((u8 *)p + 0xC));
        *(s32 *)((u8 *)p + 0x10) &= ~0x10;
    }
}

// FUN_0036C450 NONMATCHING
// Measured floor (nd 51, obj 288B/win 288B): identical allocator behavior to
// function 0036C900 — base pointer colored caller-saved, (p + 0x4C) folded into $s0
// across the 0x212 assert instead of retail's p-in-$s0 with inline lw 0x4C.
#ifdef NON_MATCHING
void func_0036c450(void) {
    void *p;
    void *q;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (*(u32 *)((u8 *)p + 0x10) & 2) {
        *(s32 *)((u8 *)p + 0x4C) += 1;
    } else if (*(u32 *)((u8 *)p + 0) & 4) {
        if (*(s32 *)((u8 *)p + 0x4C) == 0) {
            func_0046d730(D_0064E4E0, 0x212);
        }
        *(s32 *)((u8 *)p + 0x4C) += 1;
    } else {
        *(s32 *)((u8 *)p + 0x4C) = 1;
        *(u32 *)((u8 *)p + 0) |= 4;
        q = func_0036d060();
        *(s32 *)((u8 *)q + 0x110) = 2;
        *(s32 *)((u8 *)q + 0x114) = 1;
        func_00440b68(&D_00723A78, D_0064E4E0, 0x21E);
        *(s32 *)((u8 *)q + 8) = func_00454a60(D_0064E4F0, 0);
        *(s32 *)((u8 *)q + 4) = 1;
        *(u32 *)((u8 *)q + 0) |= 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036c450);
#endif

// FUN_0036C570 NONMATCHING
// Measured floor (nd 7, obj 620B/win 624B): switch selector `s` is colored
// $v1 (lw $v1,8($s0); slti $at,$v1,0xb; beq $v1,$v0,...) where retail loads it
// into $a3 ($7). Pure register-allocation difference; every other instruction
// in the 624B function matches byte-for-byte (both switches, element-pointer
// caching, s8 vararg extension, buffer calls).
#ifdef NON_MATCHING
void func_0036c570(s32 arg0, s32 arg1) {
    char buf1[0x10];
    char buf2[0x100];
    void *p;
    u8 *e;
    void *q;
    s32 i;
    s32 s;
    s8 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (func_0036ca20(arg0, arg1) != 0) {
        func_0036cbc0(arg0, arg1);
        return;
    }
    i = func_0036ccc0();
    e = (u8 *)p + i * 0x14 + 0x54;
    *(s32 *)((u8 *)p + i * 0x14 + 0x58) = arg0;
    *(s32 *)((u8 *)p + i * 0x14 + 0x5C) = arg1;
    *(s32 *)((u8 *)p + i * 0x14 + 0x60) = 0;
    *(s32 *)((u8 *)p + i * 0x14 + 0x64) = 1;
    *(u32 *)((u8 *)p + i * 0x14 + 0x54) |= 1;
    q = func_0036d060();
    *(s32 *)((u8 *)q + 0x110) = 0;
    *(s32 *)((u8 *)q + 0x114) = i;
    switch (arg0) {
    case 0:
        func_00442830(buf1, &D_00723A80);
        break;
    case 1:
        func_00442830(buf1, &D_00723A88);
        break;
    case 2:
        func_00442830(buf1, &D_00723A90);
        break;
    case 3:
        func_00442830(buf1, &D_00723A98);
        break;
    }
    s = *(s32 *)(e + 8);
    if (s < 11) {
        func_00442088(buf2, D_0064E510, buf1);
    } else {
        switch (s) {
        case 11:
            v = 0x70;
            break;
        case 12:
            v = 0x6E;
            break;
        case 13:
            v = 0x71;
            break;
        case 14:
            v = 0x6B;
            break;
        }
        func_00442088(buf2, D_0064E530, buf1, v);
    }
    func_00440b68(&D_00723A78, D_0064E4E0, 0x260);
    *(s32 *)((u8 *)q + 8) = func_00454a60(buf2, 0);
    *(s32 *)((u8 *)q + 4) = 1;
    *(u32 *)((u8 *)q + 0) |= 1;
}

#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036c570);
#endif
// FUN_0036C7E0
void func_0036c7e0(s32 arg0) {
    char buf[0x100];
    void *p;
    void *q;
    s32 i;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (func_0036cd70(arg0) != 0) {
        func_0036cf80(arg0);
        return;
    }
    i = func_0036cee0();
    *(u32 *)((u8 *)p + i * 0x10 + 0x194) |= 1;
    *(u16 *)((u8 *)p + i * 0x10 + 0x198) = arg0;
    *(s32 *)((u8 *)p + i * 0x10 + 0x19C) = 0;
    *(s32 *)((u8 *)p + i * 0x10 + 0x1A0) = 1;
    q = func_0036d060();
    *(s32 *)((u8 *)q + 0x110) = 1;
    *(s32 *)((u8 *)q + 0x114) = i;
    func_00442088(buf, D_0064E550, arg0 & 0xFFFF);
    func_00440b68(&D_00723A78, D_0064E4E0, 0x285);
    *(s32 *)((u8 *)q + 8) = func_00454a60(buf, 0);
    *(s32 *)((u8 *)q + 4) = 1;
    *(u32 *)((u8 *)q + 0) |= 1;
}

// FUN_0036C900 NONMATCHING
// Measured floor (nd 49, obj 288B/win 288B): mwcc colors the base pointer
// caller-saved ($a0) and folds (p + 0x50) into $s0 across the 0x29B assert,
// emitting addiu s0,a0,0x50 + lw 0x50(a0) + post-call lw(s0), while retail
// keeps p in $s0 throughout and uses inline lw 0x50($s0) before and after the
// call (same allocator family as FUN_0036BFF0/FUN_0036BEE0). Tried: else-if
// vs early-return shape, value temp, p reused for the d060 result (p in $a0
// still) — all nd 49.
#ifdef NON_MATCHING
void func_0036c900(void) {
    void *p;
    void *q;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (*(u32 *)((u8 *)p + 0x10) & 0x10) {
        *(s32 *)((u8 *)p + 0x50) += 1;
    } else if (*(u32 *)((u8 *)p + 0) & 0x10) {
        if (*(s32 *)((u8 *)p + 0x50) == 0) {
            func_0046d730(D_0064E4E0, 0x29B);
        }
        *(s32 *)((u8 *)p + 0x50) += 1;
    } else {
        *(s32 *)((u8 *)p + 0x50) = 1;
        *(u32 *)((u8 *)p + 0) |= 0x10;
        q = func_0036d060();
        *(s32 *)((u8 *)q + 0x110) = 2;
        *(s32 *)((u8 *)q + 0x114) = 2;
        func_00440b68(&D_00723A78, D_0064E4E0, 0x2A7);
        *(s32 *)((u8 *)q + 8) = func_00454a60(D_0064E570, 0);
        *(s32 *)((u8 *)q + 4) = 1;
        *(u32 *)((u8 *)q + 0) |= 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036c900);
#endif

// FUN_0036CA20
s32 func_0036ca20(s32 arg0, s32 arg1) {
    s32 i;
    s32 v5c;
    s32 v58;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x14 + 0x54) & 1)) {
            v5c = *(s32 *)((u8 *)p + i * 0x14 + 0x5C);
            if (v5c == arg1) {
                v58 = *(s32 *)((u8 *)p + i * 0x14 + 0x58);
                if (v58 == arg0) {
                    break;
                }
            }
        }
    }
    return i < 0x10;
}

// FUN_0036CAD0
void *func_0036cad0(s32 arg0, s32 arg1) {
    s32 i;
    s32 v5c;
    s32 v58;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x14 + 0x54) & 1)) {
            v5c = *(s32 *)((u8 *)p + i * 0x14 + 0x5C);
            if (v5c == arg1) {
                v58 = *(s32 *)((u8 *)p + i * 0x14 + 0x58);
                if (v58 == arg0) {
                    break;
                }
            }
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x2D3);
    }
    return (u8 *)p + i * 0x14 + 0x54;
}

// FUN_0036CBC0
void func_0036cbc0(s32 arg0, s32 arg1) {
    s32 i;
    s32 v5c;
    s32 v58;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x14 + 0x54) & 1)) {
            v5c = *(s32 *)((u8 *)p + i * 0x14 + 0x5C);
            if (v5c == arg1) {
                v58 = *(s32 *)((u8 *)p + i * 0x14 + 0x58);
                if (v58 == arg0) {
                    break;
                }
            }
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x2D3);
    }
    *(u32 *)((u8 *)p + i * 0x14 + 0x64) += 1;
}

// FUN_0036CCC0
s32 func_0036ccc0(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (~*(u32 *)((u8 *)p + i * 0x14 + 0x54) & 1) {
            break;
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x2F0);
    }
    return i;
}

// FUN_0036CD70
s32 func_0036cd70(s32 arg0) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = arg0 & 0xFFFF; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x10 + 0x194) & 1)) {
            v = *(u16 *)((u8 *)p + i * 0x10 + 0x198);
            if (v == key) {
                break;
            }
        }
    }
    return i < 0x10;
}

// FUN_0036CE10
u32 *func_0036ce10(s32 arg0) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = arg0 & 0xFFFF; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x10 + 0x194) & 1)) {
            v = *(u16 *)((u8 *)p + i * 0x10 + 0x198);
            if (v == key) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x319);
    }
    return (u32 *)((u8 *)p + i * 0x10 + 0x194);
}

// FUN_0036CEE0
s32 func_0036cee0(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (~*(u32 *)((u8 *)p + i * 0x10 + 0x194) & 1) {
            break;
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x32B);
    }
    return i;
}

// FUN_0036CF80
void func_0036cf80(s32 arg0) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = arg0 & 0xFFFF; i < 0x10; i++) {
        if (!(~*(u32 *)((u8 *)p + i * 0x10 + 0x194) & 1)) {
            v = *(u16 *)((u8 *)p + i * 0x10 + 0x198);
            if (v == key) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        func_0046d730(D_0064E4E0, 0x319);
    }
    *(u32 *)((u8 *)p + i * 0x10 + 0x1A0) += 1;
}

// FUN_0036D060
u32 *func_0036d060(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x20; i++) {
        if (~*(u32 *)((u8 *)p + i * 0x124 + 0x294) & 1) {
            break;
        }
    }
    if (i >= 0x20) {
        func_0046d730(D_0064E4E0, 0x352);
    }
    return (u32 *)((u8 *)p + i * 0x124 + 0x294);
}

// FUN_0036D130
s32 func_0036d130(s32 arg0) {
    void *p;
    u32 *q;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(*(u32 *)((u8 *)p + 0x10) & 4)) {
        func_0046d730(D_0064E4E0, 0x371);
    }
    q = p;
    return q[arg0 + 9];
}
// FUN_0036D1B0
s32 func_0036d1b0(s32 arg0) {
    void *p;
    u32 *q;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(*(u32 *)((u8 *)p + 0x10) & 8)) {
        func_0046d730(D_0064E4E0, 0x37C);
    }
    q = p;
    return q[arg0 + 0x10];
}

// FUN_0036D230 NONMATCHING
// Measured floor (nd 88, obj 412B/win 432B): mwcc CSEs the constant-offset
// address (p + 0x10) into a callee-saved register (addiu s1,s2,0x10; lw(s1))
// and colors arg0->s0/p->s2, while retail keeps p in s1 with inline
// lw 0x10($s1) per assert and colors arg0->s3 (same allocator family as
// function 0036BFF0/FUN_0036BEE0/FUN_0036C900/FUN_0036C450). Loops, call args and
// the chained-OR tail are otherwise structurally identical.
#ifdef NON_MATCHING
void func_0036d230(u8 *arg0) {
    u8 *p;
    u8 *base2;
    s32 i;
    s32 j;

    if (D_0072469C == 0) {
        func_0046d730(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(~*(u32 *)((u8 *)p + 0x10) & 4)) {
        func_0046d730(D_0064E4E0, 0x3A4);
    }
    if (!(~*(u32 *)((u8 *)p + 0x10) & 8)) {
        func_0046d730(D_0064E4E0, 0x3A5);
    }
    if (!(~*(u32 *)((u8 *)p + 0x10) & 1)) {
        func_0046d730(D_0064E4E0, 0x3A6);
    }
    if (*(u16 *)((u8 *)arg0 + 4) != 10) {
        func_0046d730(D_0064E4E0, 0x3A7);
    }
    for (i = 0; i < 7; i++) {
        *(s32 *)((u8 *)p + i * 4 + 0x24) =
            func_0036d3e0((u8 *)arg0 + *(s32 *)((u8 *)arg0 + i * 8 + 8));
    }
    base2 = (u8 *)arg0 + 8;
    *(s32 *)((u8 *)p + 4) =
        func_0036d3e0((u8 *)arg0 + *(s32 *)((u8 *)arg0 + 0x40));
    for (j = 0; j < 2; j++) {
        *(s32 *)((u8 *)p + j * 4 + 0x40) =
            func_0036d3e0((u8 *)arg0 + *(s32 *)((u8 *)base2 + j * 8 + 0x40));
    }
    *(u32 *)((u8 *)p + 0x10) |= 1;
    *(u32 *)((u8 *)p + 0x10) |= 4;
    *(u32 *)((u8 *)p + 0x10) |= 8;
}
#else
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036d230);
#endif

// FUN_0036D3E0
INCLUDE_ASM("asm/nonmatchings/pscRes", func_0036d3e0);

