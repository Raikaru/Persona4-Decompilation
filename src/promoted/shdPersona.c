/* Consolidated Persona 4 source units. */
/* Original translation unit shdPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void func_0011e230();
void func_0011e240();
void func_0046d4c0(s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2);
void func_0011aaa0();
void func_0011ba40();
void func_0011e3c0(s32, s32);
void func_0011fd10(s32);
void func_00452080();
void func_0011bc70();
s32 func_00115020();
void func_0045af60(s32 a, s32 b, s32 c, s32 d);
s32 func_001152b0();
void func_00115cb0(Vec2f, s32, s16 *);
void func_00115dc0(Vec2f, s32, s16 *);
void func_00115e90(Vec2f, s32, s16 *);
void func_0046d730(const char *file, s32 line);
void func_0043f9c8(void *dst, s32 value, s32 size);
s32 func_0010cc20();
void func_00115420();
void func_00115940();
s32 func_0010c750();
s32 func_00109430();
s32 func_0010cd70(s32, s32, u8 *);
void func_00115500(s16, u8 *, u8 *);
void func_0011dfc0();
void func_00454bd0();
void func_003ef3a0();
f32 func_0044b7b0(f32 arg0);
f32 func_0044b610(f32 arg0);
extern f32 D_007613EC;
extern f32 D_00761184;
s32 func_004669d0();
s32 func_00440b68();
extern char D_005E4ED0[];
extern char D_005E4EF0[];
void func_0045aeb0(s16 channelIndex, const char *name);
extern char D_005E4868[];
extern char D_005E4E20[];
extern char D_005E4E40[];
extern u8 D_00793E80[];

extern void (*jtbl_008873EC[])(u8 *);





// FUN_00115890
s32 func_00115890(u8 *arg0, s32 arg1)
{
    u8 c = *(u8 *)(arg0 + 4);
    s32 s17;
    s32 r;
    if (c == 0x63) {
        return 0;
    }
    s17 = c + (arg1 & 0xFF);
    if (s17 > 0x63) {
        func_0046d730(D_005E4868, 0x65);
    }
    s17 = func_0010c750(arg0, (u16)(s17 + 1));
    r = s17 - func_00109430(arg0);
    if (r < 0) {
        return 0;
    }
    return r;
}



// FUN_00115940
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115940);



// FUN_00115C00
void func_00115c00(u8 *arg0, u8 *arg1)
{
    s32 i = 0;
    while (i < 5) {
        *(u8 *)(arg1 + i + 0xC) = *(u8 *)(arg0 + i);
        i++;
    }
}



// FUN_00115C40
void func_00115c40(Vec2f arg0, s32 arg1, s16 *arg2)
{
    switch (*arg2) {
    case 0:
        func_00115dc0(arg0, arg1, arg2);
        break;
    case 1:
        func_00115e90(arg0, arg1, arg2);
        break;
    case 2:
        func_00115cb0(arg0, arg1, arg2);
        break;
    }
}



// FUN_00115CB0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115cb0);



// FUN_00115DC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115dc0);



// FUN_00115E90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115e90);



// FUN_00116190
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116190);



/* measured: everything matches except the mask fold — retail keeps the raw
   `0xFF - (arg1 & 0xFF)` subu in $s0 and re-applies `andi $a3, $s0, 0xff` at
   each of the two func_0046d4c0 call sites; mwcc b210 always folds the & 0xFF
   into the CSE'd def (andi $s0) and emits plain move $a3, $s0, which also
   collapses retail's FPU/GPR call-site interleave into sequential order (nd 33).
   Tried: s32 mask local, u8 mask local, inline expr at calls, u8 arg1, and a
   static inline helper — all fold identically. AND-fold scheduling floor. */
// FUN_001162F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001162f0);



// FUN_001163E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001163e0);



// FUN_00116610
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116610);



// FUN_00116820
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116820);



// FUN_00116D40
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116d40);



// FUN_001171C0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001171c0);



// FUN_00117310
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117310);



// FUN_001174A0
f32 func_001174a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (arg0 < arg1) {
        return 0.0f;
    }
    if (arg0 < arg2) {
        f32 f = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 0:
            break;
        case 1:
            f = func_0044b7b0(D_00761184 * f);
            break;
        case 2:
            f = 1.0f - func_0044b610(D_00761184 * f);
            break;
        }
        return f;
    }
    return 1.0f;
}



// FUN_00117580
void func_00117580(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (!((arg1 & 0xFFFF) < 0xD8)) {
        func_0046d730(D_005E4868, 0x595);
    }
    *(u16 *)(b + 0x570) = arg1;
}



// FUN_001175E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001175e0);



// FUN_00117780
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117780);



// FUN_001178A0
s32 func_001178a0(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    s32 off;
    *(s32 *)(b + 0x540) = 0;
    *(s32 *)(b + 0x544) = 0;
    off = 0x30 * *(u16 *)(b + 0x570);
    func_00460ac0(D_00793E80 + off, b + 0x540);
    switch (*(s32 *)(b + 0x538)) {
    case 0:
        *(s32 *)(b + 0x538) = 1;
        /* fallthrough */
    case 1:
        if (*(s32 *)(b + 0) != 0) {
            *(s32 *)(b + 0x538) = 2;
            *(s32 *)(b + 0x534) |= 8;
        }
        break;
    case 2:
        break;
    case 3:
        if (!(*(s32 *)(b + 0x534) & 1)) {
            return -1;
        }
        break;
    }
    return 0;
}



// FUN_00117980
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117980);



// FUN_001187B0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001187b0);



// FUN_00118A20
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00118a20);



// FUN_001190F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001190f0);



// FUN_00119210
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119210);



// FUN_00119810
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119810);



// FUN_00119E10
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119e10);



// FUN_0011AAA0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011aaa0);



// FUN_0011AC70
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ac70);



// FUN_0011AE90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ae90);



// FUN_0011B110
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011b110);



// FUN_0011B2D0
void func_0011b2d0(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    s32 v = *(s32 *)(b + 0x52C);
    if (!(v == 1 || v == 4 || v == 3 || v == 2 || v == 0)) {
        func_0046d730(D_005E4868, 0xB59);
    }
    jtbl_008873EC[0](b);
}



// FUN_0011B360
void func_0011b360(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(b + 0x534) & 1) != 0 && *(s32 *)(b + 0x538) == 2) {
        func_0011bc70(arg0);
    } else {
        *(s32 *)(b + 0x534) &= ~1;
    }
    *(s32 *)(b + 0x538) = 3;
}



// FUN_0011B3D0
void func_0011b3d0(u8 *arg0, u8 *arg1)
{
    s32 v = *(s32 *)(arg0 + 0x52C);
    switch (v) {
    case 0:
    case 1:
    case 2:
        func_00115940(arg1, arg0 + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940(arg1, arg0 + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
}



// FUN_0011B480
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011b480);



// FUN_0011B6D0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011b6d0);



// FUN_0011B8F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011b8f0);



// FUN_0011BA00
s32 func_0011ba00(u8 *arg0)
{
    s32 flags = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x534);
    if ((flags & 2) || (flags & 4)) {
        return 1;
    }
    return 0;
}



// FUN_0011BA40
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ba40);



// FUN_0011BB90
void func_0011bb90(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (!(*(s32 *)(b + 0x534) & 2) && *(u8 *)(b + 0x505) != 0xFF) {
        f32 t;
        f32 u;
        Vec2f src;
        Vec2f dst;
        func_0011ba40(b);
        *(u16 *)(b + 0x508) = 0;
        *(u8 *)(b + 0x504) = *(u8 *)(b + 0x505);
        *(u8 *)(b + 0x506) = 0xFF;
        t = 131.0f + *(f32 *)(b + 0x4FC);
        src.x = t;
        u = -59.0f + *(f32 *)(b + 0x500);
        src.y = u;
        dst.x = 640.0f + t;
        dst.y = u;
        func_0011e2b0(*(u8 **)(b + 0x4F8), &dst, &src);
        func_0011e240(*(u8 **)(b + 0x4F8), 0);
        func_0011aaa0(b, 0);
    }
}



// FUN_0011BC70
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bc70);



// FUN_0011BDC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bdc0);



// FUN_0011BF10
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bf10);



// FUN_0011C180
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c180);



// FUN_0011C2C0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c2c0);



// FUN_0011C3E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c3e0);



// FUN_0011C610
u32 func_0011c610(u8 *arg0)
{
    return (*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x534) & 0x800) != 0;
}



// FUN_0011C630
void func_0011c630(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x4000) == 0 && (v & 0x1000) == 0 && ((v & 0x800) == 0 || (v & 0x2000) != 0)) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0;
        *(u16 *)(b + 0x514) = 0;
        *(u8 *)(b + 0x88) = 0;
        *(s32 *)(b + 0x534) |= 0x1000;
        *(s32 *)(b + 0x534) |= 0x800;
        *(s32 *)(b + 0x534) &= ~0x2000;
        func_0045af60(0, 1, 0, 3);
    }
}



// FUN_0011C6E0
void func_0011c6e0(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x800) != 0 && (v & 0x2000) == 0) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0xC3E10000;
        *(u16 *)(b + 0x514) = 0;
        *(s32 *)(b + 0x534) |= 0x2000;
        *(s32 *)(b + 0x534) &= ~0x1000;
        if (arg1 != 0) {
            func_0045af60(0, 1, 0, 4);
        }
    }
}



// FUN_0011C780
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c780);



// FUN_0011C930
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c930);



/* measured: retail booleanizes the (flags & 0x800) != 0 test with sltu and routes
   both early-outs through a shared `b` trampoline (beqz->L20, fallthrough->L20,
   L20: b end); mwcc b210 emits andi+beqz straight to the join and skips the
   trampoline. Tried: inline &&, nested ifs, early returns, bool locals,
   masked-variable comparisons, and cond = A && B assignment (which sltu-izes the
   first operand but also not/sltu-izes the byte test) — all nd 25. Branch-to-
   branch sharing + booleanize floors. */
// FUN_0011CAF0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011caf0);



// FUN_0011CB70
s32 func_0011cb70(u8 *arg0, u8 *arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE21);
    }
    if (func_0010cc20(*(s32 *)b, arg1) != 0) {
        func_00115420(arg1, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CC00
s32 func_0011cc00(u8 *arg0, s16 arg1, u8 *arg2)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE45);
    }
    if (func_0010cd70(*(s32 *)b, arg1, arg2) != -1) {
        func_00115500(arg1, arg2, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CCB0
s32 func_0011ccb0(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if (v & 0x2000) {
        return 0;
    }
    if ((v & 0x100000) != 0 && *(s8 *)(arg0 + 0x88) == 8) {
        return *(u16 *)(arg0 + 0x4F4);
    }
    return func_001152b0(arg0 + 0x84);
}



// FUN_0011CD20
void func_0011cd20(u8 *arg0)
{
    f32 f1 = (f32)*(s16 *)(arg0 + 0x518);
    if (f1 > 25.0f) {
        *(s32 *)(arg0 + 0x534) &= ~0x8000;
    } else if (f1 > 25.0f) {
        f1 = 25.0f;
    }
    *(f32 *)(arg0 + 0x51C) = func_0044b7b0(D_007613EC * f1 / 25.0f);
}



// FUN_0011CDD0
void func_0011cdd0(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0x534) |= 0x100000;
    func_0043f9c8(b + 0x4F0, 0, 6);
    *(u16 *)(b + 0x4F4) = arg1;
}



// FUN_0011CE30
void func_0011ce30(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(u16 *)(b + 0x4F2) = 0;
    *(u16 *)(b + 0x4F0) |= 2;
}



// FUN_0011CE50
void func_0011ce50(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if ((v & 0x10000) != 0) {
        if (*(s16 *)(arg0 + 0x520) == 10) {
            func_0045aeb0(2, D_005E4E20);
        }
    } else if ((v & 0x20000) != 0) {
        if (*(s16 *)(arg0 + 0x520) >= 50) {
            *(s32 *)(arg0 + 0x534) &= ~0x200;
        }
    }
}



// FUN_0011CEE0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011cee0);



// FUN_0011D080
void func_0011d080(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0x534) |= arg1;
}



// FUN_0011D0A0
void func_0011d0a0(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0x534) &= ~arg1;
}



// FUN_0011D0C0
u8 func_0011d0c0(u8 *arg0)
{
    return *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x505);
}



// FUN_0011D0D0
void func_0011d0d0(u8 *arg0)
{
    func_0011e240(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
}

// FUN_0011D100
void func_0011d100(u8 *arg0, f32 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(f32 *)(temp_3 + 0x4FC) = 0.0f;
        *(f32 *)(temp_3 + 0x500) = 0.0f;
        return;
    }
    *(f32 *)(temp_3 + 0x4FC) = arg1[0];
    *(f32 *)(temp_3 + 0x500) = arg1[1];
}





// FUN_0011D140
void func_0011d140(u8 *arg0)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
}

// FUN_0011D170
void func_0011d170(u8 *arg0, s32 arg1, s32 arg2)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
    func_0011e3c0(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8), arg2);
}





// FUN_0011D1D0
void func_0011d1d0(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x53C) = arg1;
}



// FUN_0011D1E0
s32 func_0011d1e0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8);
}



// FUN_0011D1F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011d1f0);



// FUN_0011D3C0
void func_0011d3c0(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(b + 0x48) != 0) {
        func_0011dfc0(*(s32 *)(b + 0x48), *(s32 *)(b + 0x4C), D_005E4E40);
        *(s32 *)(b + 0x48) = 0;
        *(s32 *)(b + 0x4C) = 0;
        *(s32 *)(b + 0x50) = 0;
    } else {
        if (*(s32 *)(b + 0x4C) != 0) {
            func_00454bd0(*(s32 *)(b + 0x4C));
            *(s32 *)(b + 0x4C) = 0;
        }
        if (*(s32 *)(b + 0x50) != 0) {
            func_003ef3a0(*(s32 *)(b + 0x50));
            *(s32 *)(b + 0x50) = 0;
        }
    }
    jtbl_008873EC[0](b);
}



// FUN_0011D460
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011d460);



// FUN_0011D5B0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011d5b0);



// FUN_0011DC50
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011dc50);



// FUN_0011DD50
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011dd50);



// FUN_0011DE40
void func_0011de40(u8 *arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    s32 v = arg1 & 0xFF;
    *(s32 *)(b + 8) = (*(s32 *)(b + 8) & ~0xFF) | v;
    *(s32 *)(b + 0xC) = (*(s32 *)(b + 0xC) & ~0xFF) | v;
}

// FUN_0011DE80
f32 func_0011de80(u8 *arg0, Vec2f *arg1)
{
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x38);
    *arg1 = *(Vec2f *)(temp_2 + 0x28);
    return (f32)(*(s32 *)(temp_2 + 0x10)) / 10.0f;
}





// FUN_0011DEC0
s32 func_0011dec0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 8);
}



/* measured: retail materialises the D_005E4ED0 address (lui+addiu $a0) BEFORE the
   addiu $a1, $v0, 0x10 at the func_00440b68 call; mwcc b210 always emits the
   computed operand first and the constant global address last (nd 3, the three
   swapped words). Tried: hoisting arg1 to a local, hoisting the address to a
   char* local, inverting the if/else (nd 5) — constant-vs-computed argument
   materialisation order floor per operand-order skill. */
// FUN_0011DED0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ded0);

// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}





// FUN_0011DFC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011dfc0);



// FUN_0011E0C0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e0c0);



// FUN_0011E230
void func_0011e230(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
}



// FUN_0011E240
void func_0011e240(u8 *arg0, u8 *arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    f32 v0;
    f32 v1;
    if (arg1 != NULL) {
        *(f32 *)(b + 0x30) = *(f32 *)(arg1 + 0);
        *(f32 *)(b + 0x34) = *(f32 *)(arg1 + 4);
    *(f32 *)(b + 0x20) = 640.0f + *(f32 *)(b + 0x30);
    *(f32 *)(b + 0x24) = *(f32 *)(b + 0x34);
    }
    v0 = *(f32 *)(b + 0x20);
    *(f32 *)(b + 0x28) = v0;
    *(f32 *)(b + 0x40) = v0;
    v1 = *(f32 *)(b + 0x24);
    *(f32 *)(b + 0x2C) = v1;
    *(f32 *)(b + 0x44) = v1;
    *(f32 *)(b + 0x1C) = 15.0f;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E2B0
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x120A);
    }
    if (arg2 == NULL) {
        func_0046d730(D_005E4868, 0x120B);
    }
    *(Vec2f *)(b + 0x20) = *arg1;
    *(Vec2f *)(b + 0x28) = *arg1;
    *(Vec2f *)(b + 0x30) = *arg2;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E360
void func_0011e360(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) = arg1;
}



// FUN_0011E370
void func_0011e370(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(f32 *)(b + 0x40) = *(f32 *)(b + 0x28);
    *(f32 *)(b + 0x44) = *(f32 *)(b + 0x2C);
}



// FUN_0011E390
void func_0011e390(u8 *arg0, Vec2f arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);
    b[0xE] = arg1.x;
    b[0xF] = arg1.y;
}



// FUN_0011E3C0
void func_0011e3c0(s32 arg0, s32 arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0xC) = (arg1 & 0xFFFFFF00) | *(u8 *)(b + 8);
}



// FUN_0011E3E0
u32 func_0011e3e0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0) == 3;
}



// FUN_0011E400
void func_0011e400(u8 *arg0, u8 *arg1)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x124F);
    }
    *(Vec2f *)arg1 = *(Vec2f *)(b + 0x28);
}



// FUN_0011E460
s32 func_0011e460(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)b != 3) {
        return 0;
    }
    return *(s32 *)(b + 0x50);
}



// FUN_0011E490
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e490);



// FUN_0011E740
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e740);



// FUN_0011E8E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e8e0);



// FUN_0011F3C0
void func_0011f3c0(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(b + 0x18) != 0) {
        func_0011fd10(*(s32 *)(b + 0x18));
        *(s32 *)(b + 0x18) = 0;
    }
    jtbl_008873EC[0](b);
}



// FUN_0011F410
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011f410);



// FUN_0011F560
u32 func_0011f560(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) == 0xE;
}



// FUN_0011F580
void func_0011f580(void)
{
    func_00452080();
}



// FUN_0011F5A0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011f5a0);

// FUN_0011FB90
void func_0011fb90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_0011FBC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011fbc0);
