#include "include_asm.h"
#include "type.h"
extern void func_001bdeb0();

s32 func_00452380(u8 *arg0);

extern u8 D_006290F0[];

u16 *func_00452560();
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90();
extern void func_0043f9c8();
extern s32 func_00451fc0();
extern void func_00221f40();
extern void func_002230a0();
extern void func_00222d20();
extern void func_002232a0();
extern void func_002236b0();
extern void func_002236c0();

extern u8 D_00629640[];
extern u8 D_00629738[];
extern void func_002239a0();
extern void func_00223ed0();
extern void func_00223ee0();
extern s32 func_001998e0(u8 *arg0, s32 arg1);
extern s64 func_001999f0(u8 *arg0, s32 arg1, f32 arg2, s64 arg3);
extern s32 func_0019fe60(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001cbf80(u8 *arg0);
extern void func_001cbfe0(u8 *arg0);
extern s32 func_00243ce0();
extern void func_002250a0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_002258b0(u8 *arg0, f32 arg1, f32 arg2);
extern f32 fGpffff809c;

extern u8 D_006296B0[];
extern u8 D_006296E8[];

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

void func_002258b0(u8 *arg0, f32 arg1, f32 arg2);

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern s32 func_0011b360(s32 arg0);
extern void func_001f7570(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_001bd780();
extern void func_001bab00();
extern void func_001bd5a0();
extern void func_001bd560();
extern void func_001bac20();
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern s32 func_00231d70(s32 arg0);
extern u8 D_0060A0E0[];
extern s32 func_001ef9a0(void);
extern u8 *iGpffffb414;
extern u8 D_0062A5F0[];
extern u8 D_0062AD40[];
extern u8 D_0062B490[];
extern u8 D_0062BBE0[];
extern u8 D_0062C330[];
extern u8 *func_001b1510(void);
extern s32 func_00232710(u8 *arg0, s32 arg1);
extern f32 fGpffff834c;
extern void func_001958f0(u8 *arg0, u8 *arg1);
extern void func_00194ee0(u8 *arg0, s32 *arg1);
extern void func_001ec6d0(u8 *arg0, u8 *arg1, s32 *arg2);
extern u8 *iGpffffb3e0;
extern s32 func_001f0ff0();
extern s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2);
extern s32 func_0022fc00(u8 *arg0);
extern s32 func_0022ff70(u8 *arg0);

extern u8 *func_001bc920(u8 *arg0, s32 arg1);
extern void func_00194590(u8 *arg0, s32 arg1);
extern u8 *func_00202400(s32 arg0, s32 arg1);
extern s32 func_004bd050(s32 arg0);
extern void func_001bdd80(u8 *arg0, void *arg1, s32 arg2);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 arg4);
extern u8 D_00632240[];
extern void func_00225ec0(void);
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
s32 func_002230e0(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_00629698, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x74, 0x40000);
    func_0043f9c8(temp_2, 0, 0x74);
    temp_16 = (s32)(func_00451fc0(arg0, &D_00629640, 0xF, 0, 0,
                                  (void *)func_00221f40,
                                  (void *)func_002230a0, temp_2));
    temp_2_2 = (u16 *)(func_00452560(arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 0xC, 0, 0x30);
    *(void (**)(u8 *))((u8 *)(temp_2) + 0x14) = (void (*)(u8 *))(func_00222d20);
    *(u8 **)((u8 *)(temp_2) + 0x1C) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
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
s32 func_00223730(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_006296E8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x54, 0x40000);
    func_0043f9c8(temp_2, 0, 0x54);
    temp_16 = (s32)(func_00451fc0(arg0, &D_006296B0, 0xF, 0, 0,
                                  (void *)func_002232a0,
                                  (void *)func_002236c0, temp_2));
    temp_2_2 = (u16 *)(func_00452560(arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x40) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(func_002236b0);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
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
s32 func_00223f40(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_00629738, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x4C, 0x40000);
    func_0043f9c8(temp_2, 0, 0x4C);
    temp_16 = (s32)(func_00451fc0(arg0, &D_00629700, 0xF, 0, 0,
                                  (void *)func_002239a0,
                                  (void *)func_00223ee0, temp_2));
    temp_2_2 = (u16 *)(func_00452560(arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(func_00223ed0);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
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
void func_00225bd0(u8 *arg0)
{
    func_002258b0(arg0, 0.0f, 2.0f);
}



// FUN_00225C00
void func_00225c00(u8 *arg0)
{
    u8 *self;
    u8 *temp_3;

    self = arg0;
    temp_3 = *(u8 **)(self + 0xE0);
    if (temp_3 != NULL) {
        if (func_00243ce0(*(s32 *)(*(u8 **)(temp_3 + 0x30) + 0xA64)) != 0) {
            if (func_0019fe60(*(u8 **)(self + 0xE0), 0, 0) != 0) {
                func_002258b0(self, 0.0f, 0.75f);
            } else {
                func_002250a0(self, 0.0f, 0.75f);
            }
            arg0 = (u8 *)(s64)(s16)func_001998e0(
                *(u8 **)(*(u8 **)(self + 0xE0) + 0x30), 4);
            *(s16 *)(self + 0x10E) =
                func_001999f0(*(u8 **)(*(u8 **)(self + 0xE0) + 0x30),
                              4, 1.0f, (s64)((u32)arg0 & 0xFFFF));
            *(s16 *)(self + 0x10C) = 0;
            *(s32 *)(self + 0x100) = *(s32 *)(*(u8 **)(self + 0xE0) + 0x38);
            return;
        }
        func_001cbf80(self);
    }
}
/* measured 00225d00 plain-C reconstruction reproduces the complete 252-byte object against the 256-byte window; the counter-field register colouring residual remains at normalized_diff 11. Committed at nd 11. */
// FUN_00225D00 NONMATCHING
#ifdef NON_MATCHING
void func_00225d00(u8 *arg0)
{
    u16 temp_4;
    u16 temp_3;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x100) == *(s32 *)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_00243ce0(*(s32 *)(*(u8 **)(temp_5 + 0x30) + 0xA64),
                           temp_5) == 0) {
            func_001cbfe0(arg0);
            return;
        }
        temp_4 = *(u16 *)(arg0 + 0x10E);
        temp_3 = (u16)(*(u16 *)(arg0 + 0x10C) + 1);
        *(u16 *)(arg0 + 0x10C) = temp_3;
        if (temp_4 != temp_3) {
            return;
        }
        if (func_0019fe60(*(u8 **)(arg0 + 0xE0), 0, 0) != 0) {
            func_002258b0(arg0, 400.0f, fGpffff809c);
            return;
        }
        func_002250a0(arg0, 400.0f, fGpffff809c);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225d00);
#endif
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
void func_002284d0(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        f32 first[7];
        Vec3 second;
        f32 third[4];
    } work;
    f32 *temp_16;
    u8 *temp_2;

    func_001bd560(work.first, arg0 + 0x9C);
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = (f32 *)(temp_2 + 0x6B4);
    func_001bd780(work.third, temp_16, (u8 *)temp_16 + 0xC, D_0060A0E0);
    work.second = *(Vec3 *)temp_16;
    func_001bac20(arg0, work.first, &work.second, 1);
    func_001bbef0(arg0, 0.75f);
}
// FUN_00228580
void func_00228580(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u16 temp_2_2;
    u8 *base;
    u8 *temp_16;
    u8 *temp_2;

    index = (u32)(func_00231d70(2) & 0xFFFF);
    base = *(u8 **)(DAT_0076449c + 0xB98);
    temp_2 = base + index * 0x34;
    temp_16 = temp_2 + 0x64C;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    func_001bac20(DAT_0076449c + 0x24, &work.first, &work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
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
void func_002289b0(u8 *arg0)
{
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u8 *temp_2;
    u8 *target;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    temp_16 = *(u16 *)(temp_2 + 0xA4);
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = (temp_16 & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_00632240 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 8);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 3, 0.0f);
}
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
void func_00228f60(u8 *arg0)
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
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) != 0) {
        goto body;
    }
    func_00225ec0();
    return;
body:
    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    func_001bd780(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    func_001bab00(DAT_0076449c + 0x24, (f32 *)&values.position);
    func_001bd5a0(arg0 + 0x9C, (f32 *)&values.position);
}
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
s32 func_0022abd0(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x15FF, 0);
        func_00106390(0x15CF, 0);
        func_00106390(0x15D0, 0);
        func_00106390(0x15D1, 0);
        func_00106390(0x15D2, 0);
        func_00106390(0x15D3, 0);
        func_00106390(0x15D4, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
// FUN_0022ACB0
void func_0022acb0(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;

    *(s32 *)(DAT_0076449c + 0xC) |= 0x80000;
    temp_2 = func_001bc920(arg0, 0x2C);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = func_00202400(*(s32 *)(arg0 + 0x30), 0xAF);
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_2, 3);
}
// FUN_0022AD40
s32 func_0022ad40(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x1435, 0);
        func_00106390(0x15C5, 0);
        func_00106390(0x15C6, 0);
        func_00106390(0x15C7, 0);
        func_00106390(0x15C8, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
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
static inline u8 *cb90AddBaseIndex(u32 base, u32 index)
{
    return (u8 *)(base + index);
}
// FUN_0022CB90
s32 func_0022cb90(u8 *arg0, s32 arg1)
{
    s32 temp_6;
    s8 temp_2;
    u16 temp_3_2;
    u8 *temp_7;
    u16 temp_3_3;

    if (*(u8 *)(arg0 + 0xA2) != 1) {
        return -1;
    }
    temp_7 = DAT_0076449c;
    temp_6 = *(s32 *)(temp_7 + 0xC30);
    if (temp_6 == 0) {
        return -1;
    }
    temp_3_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x110:
    case 0x111:
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    case 0x10F:
        temp_3_3 = (u16)arg1;
        if (((temp_3_3 == 0) || (temp_3_3 == 0x12)) &&
            (*(s16 *)(temp_7 + 0xC34) != 3)) {
            return 0xB;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    default:
        temp_2 = *(s8 *)cb90AddBaseIndex((u32)temp_7 + 0xC10,
                                         (u32)(arg1 & 0xFFFF));
        if (temp_2 >= 0) {
            return temp_2;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    }
}
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
s32 func_0022d540(u8 *arg0, u8 *arg1) {
    u16 temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_3 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_3) {
    case 0x112:
    case 0x109:
        *(s32 *)(arg1 + 0) = *(s32 *)(temp_6 + 0xBE4);
        *(s32 *)(arg1 + 4) = *(s32 *)(DAT_0076449c + 0xBE8);
        *(s32 *)(arg1 + 8) = *(s32 *)(DAT_0076449c + 0xBEC);
        return 1;
    default:
        return 0;
    }
}
// FUN_0022D600
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022d600);
// FUN_0022DB90
void func_0022db90(u8 *arg0) {
    u16 id;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) &&
        (temp_5 = *(u8 **)(arg0 + 0x30), *(u8 *)(temp_5 + 0xA2) == 1)) {
        id = *(u16 *)(temp_5 + 0xA4);
        switch (id) {
        case 0x102:
            *(u8 **)(temp_6 + 0xB98) = D_0062A5F0;
            return;
        case 0x10D:
            *(u8 **)(temp_6 + 0xB98) = D_0062AD40;
            return;
        case 0x103:
            *(u8 **)(temp_6 + 0xB98) = D_0062B490;
            return;
        case 0x110:
            *(u8 **)(temp_6 + 0xB98) = D_0062BBE0;
            return;
        case 0x111:
            *(u8 **)(temp_6 + 0xB98) = D_0062C330;
            break;
        }
    }
}
// FUN_0022DC70
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022dc70);
// FUN_0022E4F0
s32 func_0022e4f0(u8 *arg0, s32 arg1) {
    u16 temp_4_2;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_4_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_4_2) {
    case 0x102:
        if (arg1 == 0x163) {
            return 1;
        }
        goto block_25;
    case 0x100:
        if (arg1 == 0x160) {
            return 1;
        }
        goto block_25;
    case 0x103:
        if (arg1 == 0x166) {
            return 1;
        }
        if (arg1 == 0x167) {
            return 1;
        }
        goto block_25;
    case 0x10A:
    case 0x113:
        if (*(s8 *)(temp_6 + 0xC10) == 0xE) {
            return 1;
        }
        if (arg1 == 0x17E) {
            return 1;
        }
        goto block_25;
    case 0x108:
        if (arg1 == 0x17C) {
            return 1;
        }
        goto block_25;
    }
block_25:
    return 0;
}
// FUN_0022E630
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022e630);
// FUN_0022EAD0
s32 func_0022ead0(void) {
    struct {
        s32 sp20;
        s32 sp24;
        f32 sp28;
    } temps;
    u8 *var_16;

    if (!( *(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 0;
    }
    switch (func_001ef9a0()) {
    case 0x202:
        var_16 = *(u8 **)(DAT_0076449c + 0x180);
        goto loop_check;
loop_body:
        if (*(u16 *)(var_16 + 0xA4) == 0x10D) {
            temps.sp20 = 0x439B0000;
            temps.sp24 = 0;
            temps.sp28 = fGpffff834c;
            func_001ec6d0(var_16 + 0x94, var_16 + 0x96,
                          &temps.sp20);
            func_00194ee0(var_16, &temps.sp20);
        }
        var_16 = *(u8 **)(var_16 + 0xA6C);
loop_check:
        if (var_16 != NULL) {
            goto loop_body;
        }
        break;
    default:
        break;
    }
    return 1;
}
// FUN_0022EBA0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022eba0);
// FUN_0022F520
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022f520);
// FUN_0022F7D0
s32 func_0022f7d0(u8 *arg0, u8 *arg1) {
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_4;

    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x208:
        temp_2_2 = func_001b1510();
        if (temp_2_2 != NULL) {
            temp_4 = *(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64);
            if ((temp_4 != NULL) && (func_00232710(temp_4, 0x100) == 0)) {
                return 0;
            }
        }
        func_001958f0(*(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30), arg1);
        return 1;
    case 0x10E:
        *(s32 *)(arg1 + 0) = 0;
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)0xBB8;
        return 1;
    default:
        return 0;
    }
}
// FUN_0022F8B0
s32 func_0022f8b0(u8 *arg0, s32 arg1)
{
    u8 *temp_2;

    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        goto check_flag;
    }
    return 0;
check_flag:
    if (*(u16 *)(arg0 + 0x1A) & 1) {
        goto load_temp;
    }
    return 0;
load_temp:
    temp_2 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) == 1) {
        goto check_id;
    }
    return 0;
check_id:
    switch (*(u16 *)(temp_2 + 0xA4)) {
    case 0x104:
        if (arg1 != 0x169) {
            goto fail;
        }
        goto done;
    default:
        goto fail;
    }
done:
    return 1;
fail:
    return 0;
}
// FUN_0022F950
s32 func_0022f950(u8 *arg0, u8 *arg1) {
    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        if (*(u16 *)(iGpffffb3e0 +
                    (*(u16 *)(arg1 + 0xA4) * 0x58)) & 1) {
            return (func_001f1210(arg1, *(s16 *)(arg0 + 0x6E),
                                  func_001f0ff0()) != 0) ^ 1;
        }
        if ((func_001f0ff0() == 0) &&
            (*(u16 *)(iGpffffb3e0 +
                     (*(u16 *)(arg1 + 0xA4) * 0x58)) & 0x20)) {
            return 1;
        }
        if (func_0022ff70(arg0) == 1) {
            return 1;
        }
        if (func_0022fc00(arg0) == 0) {
            return 1;
        }
    }
    return 0;
}
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