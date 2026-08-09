#include "include_asm.h"
#include "type.h"
extern void func_001bdeb0();

s32 func_00452380(u8 *arg0);

extern u8 D_006290F0[];

u16 *func_00452560(void);

extern u8 D_00629640[];

extern u8 D_006296B0[];

extern u8 D_00629700[];

void func_001c8d50(void);

extern u8 *DAT_0076449c;
extern void func_001c97b0(void *arg0);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern void func_0019de70(u8 *arg0, u16 arg1);

extern u8 *func_00193bf0(u64 uid, u64 mask);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00452490(u8 *arg0);
extern u8 *func_001b0c80(u8 *arg0);
extern void func_001f2eb0(u8 *arg0, s32 arg1);
extern void func_001f7530(void);

void func_002258b0(float arg0, float arg1);

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern s32 func_0011b360(s32 arg0);
extern void func_001f7570(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_001bd780();
extern void func_001bab00();
extern void func_001bd5a0();
extern u8 D_0060A0E0[];
extern s32 func_001ef9a0(void);
extern u8 *iGpffffb414;

// FUN_002218E0
s32 func_002218e0(void)
{
    return (*func_00452560() & 4) != 0;
}
// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380(D_006290F0) != 0;
}



// FUN_00221940
s32 func_00221940(void)
{
    return ((*func_00452560() & 0x10) != 0) ^ 1;
}



// FUN_00221970
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00221970);
// FUN_00222210
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00222210);
// FUN_00222D20
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00222d20);
// FUN_002230E0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002230e0);
// FUN_002231E0
void func_002231e0(void) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560());
    *(s32 *)((u8 *)(temp_2) + 8) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 4;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 5;
}

// FUN_00223240
s32 func_00223240(void)
{
    return *func_00452560() & 1;
}
// FUN_00223270
s32 func_00223270(void)
{
    return func_00452380(D_00629640) != 0;
}



// FUN_002232A0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002232a0);
// FUN_002236B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002236b0);
// FUN_002236C0
void func_002236c0(void)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560();
    if (*(u16 *)p & 4) {
        h = *(s32 *)(p + 0x4C);
        if (h != 0) {
            func_0011b360(h);
            *(s32 *)(p + 0x4C) = 0;
        }
    }
    (*jtbl_008873EC)(p);
}

// FUN_00223730
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00223730);
// FUN_00223830
void func_00223830(void) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560());
    *(s16 *)((u8 *)(temp_2) + 0x48) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 6;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 7;
}

// FUN_00223890
s32 func_00223890(void)
{
    return *func_00452560() & 1;
}
// FUN_002238C0
s32 func_002238c0(void)
{
    return func_00452380(D_006296B0) != 0;
}



// FUN_00223ED0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00223ed0);
// FUN_00223EE0
void func_00223ee0(void)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560();
    h = *(s32 *)(p + 0x44);
    if (h != 0) {
        func_0011b360(h);
        *(s32 *)(p + 0x44) = 0;
    }
    (*jtbl_008873EC)(p);
}

// FUN_00223F40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00223f40);
// FUN_00224040
void func_00224040(void)
{
    u16 *temp_16;

    temp_16 = func_00452560();
    func_0021dda0();
    *(s32 *)(temp_16 + 2) = 5;
}
// FUN_00224080
s32 func_00224080(void)
{
    return *func_00452560() & 1;
}
// FUN_002240B0
s32 func_002240b0(void)
{
    return func_00452380(D_00629700) != 0;
}



// FUN_002240E0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002240e0);
// FUN_00224450
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00224450);
// FUN_00224970
void func_00224970(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        func_001c8d50();
    }
}



// FUN_002249A0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002249a0);
// FUN_002250A0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002250a0);
// FUN_00225740
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225740);
// FUN_00225860
void func_00225860(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    if ((temp_3 != NULL) && ((*(u16 *)(temp_3 + 0x1A) & 1) != 0)) {
        temp_5 = *(u16 *)(DAT_0076449c + 0xC00);
        if (temp_5 == 1) {
            func_001c97b0(arg0);
        }
    }
}

// FUN_002258B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002258b0);
// FUN_00225BD0
void func_00225bd0(void)
{
    func_002258b0(0.0f, 2.0f);
}



// FUN_00225C00
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225c00);
// FUN_00225D00
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225d00);
// FUN_00225E50
void func_00225e50(u8 *arg0)
{
    s32 iVar1;

    iVar1 = *(s32 *)(arg0 + 0xE0);
    if ((((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u8 *)(*(s32 *)(iVar1 + 0x30) + 0xA2) != 0)) &&
        (((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u16 *)(DAT_0076449c + 0xC00) == 1))) {
        func_001c97b0(arg0);
    }
}

// FUN_00225EC0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225ec0);
// FUN_002266B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002266b0);
// FUN_00226C40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00226c40);
// FUN_00227230
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00227230);
// FUN_00227770
void func_00227770(u8 *arg0)
{
    u8 *temp_3;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0x12C);
    if (temp_5 != NULL) {
        temp_3 = *(u8 **)(arg0 + 0xE0);
        if ((temp_3 != NULL) &&
            ((*(u16 *)(temp_3 + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, temp_5) != 0)) {
            func_0019de70(*(u8 **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}


// FUN_002277E0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002277e0);
// FUN_00227E40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00227e40);
// FUN_002282D0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002282d0);
// FUN_00228480
void func_00228480(u8 *arg0) {
    if (func_00243ce0(*(s32 *)((u8 *)(*(u8 **)((u8 *)(*(u8 **)((u8 *)(arg0) + 0xE0)) + 0x30)) + 0xA64)) == 0) {
        func_001bfb70(arg0);
    }
}

// FUN_002284D0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002284d0);
// FUN_00228580
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00228580);
// FUN_002286C0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002286c0);
// FUN_00228800
void func_00228800(s32 arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vector3;
    struct {
        Vector3 position;
        u8 transform[20];
    } values;
    f32 *temp;

    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    func_001bd780(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    func_001bab00(DAT_0076449c + 0x24, (f32 *)&values.position);
    func_001bd5a0((u8 *)arg0 + 0x9C, (f32 *)&values.position);
}
// FUN_00228890
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00228890);
// FUN_002289B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002289b0);
// FUN_00228A60
void func_00228a60(void)
{
    func_001bdeb0();
}

// FUN_00228A80
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00228a80);
// FUN_00228D00
void func_00228d00(u8 *arg0) {
    if (func_001f0ff0(*(u8 **)((u8 *)(arg0) + 0xE0)) != 0) {
        func_001bdeb0(arg0);
    }
}

// FUN_00228D50
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00228d50);
// FUN_00228F60
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00228f60);
// FUN_00229020
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00229020);
// FUN_002299B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002299b0);
// FUN_00229C40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00229c40);
// FUN_00229DA0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00229da0);
// FUN_0022A6B0
s32 func_0022a6b0(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x15FF, 1);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// FUN_0022A730
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022a730);
// FUN_0022ABD0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022abd0);
// FUN_0022ACB0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022acb0);
// FUN_0022AD40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022ad40);
// FUN_0022AE00
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022ae00);
// FUN_0022B040
s32 func_0022b040(s64 *arg0)
{
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

 
// FUN_0022B0B0
s32 func_0022b0b0(void)
{
    func_001f7570(0x2D);
    return 1;
}
// FUN_0022B0E0
s32 func_0022b0e0(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC) & 0x40) {
        func_0045a3e0(6, 1);
    }
    return 1;
}
// FUN_0022B120
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022b120);
// FUN_0022B870
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022b870);
/* measured: optimization_level 1 preserves func_0022ba40's loop branch. */
#pragma optimization_level 1
// FUN_0022BA40
void func_0022ba40(u16 arg1)
{
    s32 value;
    s32 id;
    u8 *p;

    p = *(u8 **)(DAT_0076449c + 0x180);
    id = 0x10E;
    goto check;
body:
    value = *(u16 *)(p + 0xA4);
    if (value == id) {
        goto found;
    }
    p = *(u8 **)(p + 0xA6C);
check:
    if (p != NULL) {
        goto body;
    }
found:
    if (p != NULL) {
        p = func_001b0c80(p);
        if (p != NULL) {
            func_001f2eb0(p, 0);
            func_001f7530();
        }
    }
}
/* measured: closes optimization_level 1 around func_0022ba40. */
#pragma optimization_level 2

// FUN_0022BAC0
s32 func_0022bac0(void)
{
    return 0;
}

// FUN_0022BAD0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022bad0);
// FUN_0022BC80
s32 func_0022bc80(s32 arg0) {
    u8 *b = DAT_0076449c;
    u8 *o = *(u8 **)(b + 0xBA0);

    if (o == NULL) {
        return 0;
    }
    if (*(u16 *)(b + 0xBA4) != (arg0 & 0xFFFF)) {
        return 0;
    }
    if (func_00452490(o) == 0) {
        *(s32 *)(DAT_0076449c + 0xBA0) = 0;
        return 0;
    }
    return 1;
}

// FUN_0022BD00
s32 func_0022bd00(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}



// FUN_0022BD20
s32 func_0022bd20(void)
{
    return (*(s32 *)(iGpffffb414 +
                     *(u16 *)(*(u8 **)(DAT_0076449c + 0xC68) + 8) * 0x18) &
            0x20) != 0;
}
// FUN_0022BD60
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022bd60);
// FUN_0022C430
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022c430);
// FUN_0022CB90
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022cb90);
// FUN_0022CC90
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022cc90);
// FUN_0022CDB0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022cdb0);
// FUN_0022CED0
void func_0022ced0(s32 arg0)
{
    func_00455ea0(*(s32 *)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

// FUN_0022CF00
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022cf00);
// FUN_0022D200
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022d200);
// FUN_0022D540
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022d540);
// FUN_0022D600
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022d600);
// FUN_0022DB90
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022db90);
// FUN_0022DC70
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022dc70);
// FUN_0022E4F0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022e4f0);
// FUN_0022E630
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022e630);
// FUN_0022EAD0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022ead0);
// FUN_0022EBA0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022eba0);
// FUN_0022F520
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022f520);
// FUN_0022F7D0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022f7d0);
// FUN_0022F8B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022f8b0);
// FUN_0022F950
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022f950);
// FUN_0022FA90
s32 func_0022fa90(u8 *arg0, s64 arg1)
{
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 1;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return 1;
    }
    return *(s8 *)((u8 *)(s16)arg1 + (u32)temp_6 + 0xC10) != -2;
}
// FUN_0022FB10
s32 func_0022fb10(void)
{
    s32 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 1;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x209:
    case 0x20C:
    case 0x20D:
        return 1;
    default:
        return 0;
    }
}