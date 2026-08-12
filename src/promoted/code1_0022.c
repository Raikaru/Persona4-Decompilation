#include "include_asm.h"
#include "type.h"
typedef struct BtlTarget BtlTarget;
typedef struct BtlCamera BtlCamera;
typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct RwV3d RwV3d;
typedef struct DatUnit DatUnit;
typedef struct KwlnTask KwlnTask;
extern void func_001bdeb0();

u8 *func_00452380(s8 *name);

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
extern void func_001cbfe0(int param_1);
extern s32 func_00243ce0(u8 *arg0);
extern void func_002250a0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_002258b0(u8 *arg0, f32 arg1, f32 arg2);
extern u16 func_001eb440(BtlTarget *target);
extern s32 func_001f0a50(u8 *arg0);
extern void func_001c9750(u8 *arg0);
extern f32 fGpffff809c;

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];

void func_001c8d50(void);

extern u8 *DAT_0076449c;
extern void func_001c97b0(u8 *arg0);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern void func_0019de70(u8 *arg0, u16 arg1);

extern u8 *func_00193bf0(u64 uid, u64 mask);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00452490(void *target);
extern u8 *func_001b0c80(s32 arg0);
extern void func_001f2eb0(u8 *arg0, s32 arg1);
extern void func_001f7530(void);

void func_002258b0(u8 *arg0, f32 arg1, f32 arg2);

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0011b360(u8 *arg0);
extern void func_001f7570(s16 fadeDuration);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_001bd780(void *out, const void *first, const void *second, const void *config);
extern void func_001bab00(u16 *param_1, f32 *param_2);
extern void func_001bd5a0(f32 *arg0, f32 *arg1);
extern void func_001bd560(f32 *arg0, f32 *arg1);
extern void func_001bac20(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern u32 func_00231d70(u32 arg0);
extern u8 D_0060A0E0[];
extern s32 func_001ef9a0(void);
extern u8 D_006348B0[];
extern u8 D_00634CB0[];
extern u8 D_006350B0[];
extern u8 *iGpffffb414;
extern u8 D_0062A5F0[];
extern u8 D_0062AD40[];
extern u8 D_0062B490[];
extern u8 D_0062BBE0[];
extern u8 D_0062C330[];
extern s32 func_001b1510(void);
extern s32 func_00232710(u8 *arg0, s32 arg1);
extern f32 fGpffff834c;
extern void func_001958f0(BtlUnit *unit, RwV3d *dst);
extern void func_00194ee0(u8 *arg0, s32 *arg1);
extern void func_001ec6d0(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3e0;
extern s32 func_001f0ff0();
extern s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2);
extern s32 func_0022fc00(u8 *arg0);
extern s32 func_0022ff70(u8 *arg0);

extern u8 *func_001bc920(u8 *arg0, s32 arg1);
extern s64 func_00194590(u8 *arg0, u32 arg1);
extern u8 *func_00202400(s32 arg0, s32 arg1);
extern s32 func_004bd050(s32 arg0);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 arg4);
extern u8 D_00632240[];
extern u8 *func_0019ef90(s32 arg0, s32 arg1);
extern void func_0019d0c0(u8 *arg0);
extern void func_00198dd0(u8 *arg0, s32 arg1);
extern void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);
extern void func_002339d0(u8 *arg0);
extern u8 D_0062D920[];
extern void func_001a03b0(s64 *arg0);
extern s32 func_001d3d50(u32 param_1);
extern u8 *func_0022ced0(s32 arg0);
extern void func_001d3ea0(int destination, u32 source);
extern BtlPacket *func_0019bbe0(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *func_001f36e0(s32 param_1, s32 param_2, void *param_3, s16 param_4, s16 param_5);
extern u8 *func_00199ee0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern BtlPacket *func_0019a980(BtlUnit *unit);
extern BtlPacket *func_001f81f0(u16 channel, const char *streamName);
extern u8 *func_001d6240(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_001d3e00(s32 arg0);
extern u8 D_006354B0[];
extern void func_00225ec0(void);
// FUN_002218E0
s32 func_002218e0(void)
{
    return (*func_00452560() & 4) != 0;
}
// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380((s8 *)D_006290F0) != 0;
}

// FUN_00221940
s32 func_00221940(void)
{
    return ((*func_00452560() & 0x10) != 0) ^ 1;
}
// FUN_00221970
s32 func_00221970(u8 *arg0)
{
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;

    temp_2 = func_00104c70(1) & 0xFF;
    temp_3 = 0;
    if (temp_2 >= 0x1E) {
        if (func_00106330(0x1202) == 0) {
            arg0[0x44] = 0xC;
            func_00106390(0x1202, 1);
            func_00106390(0x1201, 1);
            func_00106390(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x19) {
        if (func_00106330(0x1201) == 0) {
            arg0[0x44] = 0xA;
            func_00106390(0x1201, 1);
            func_00106390(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x14) {
        if (func_00106330(0x1200) == 0) {
            arg0[0x44] = 8;
            func_00106390(0x1200, 1);
            temp_3 = 1;
        }
    }
exit:
    temp_4 = temp_3;
    return temp_4;
}
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
    return func_00452380((s8 *)D_00629640) != 0;
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
            func_0011b360((u8 *)h);
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
    return func_00452380((s8 *)D_006296B0) != 0;
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
        func_0011b360((u8 *)h);
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
    return func_00452380((s8 *)D_00629700) != 0;
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
void func_00225740(u8 *arg0)
{
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_16;
    u8 *base;
    extern s32 func_00243ce0(u8 *arg0);
    base = arg0;
    *(u16 *)(DAT_0076449c + 0xC00) = 0;
    temp_2 = *(u8 **)(base + 0xE0);
    temp_16 = *(u8 **)(temp_2 + 0x30);
    temp_4 = func_001eb440((BtlTarget *)(temp_2 + 0x38));
    if (*(u8 *)(temp_16 + 0xA2) == 0) {
        if ((temp_4 & 0xFFFF & 1) == 0) {
            if (func_001f0a50(*(u8 **)(base + 0xE0)) == 0) {
                func_002250a0(base, 0.0f, 1.0f);
            }
        } else {
            func_001c9750(base);
            *(u16 *)(DAT_0076449c + 0xC00) = 1;
        }
    } else if ((temp_4 & 0xFFFF & 2) == 0) {
        if (func_00243ce0((u8 *)*(s32 *)(temp_16 + 0xA64)) != 0) {
            func_002250a0(base, 0.0f, 1.0f);
            return;
        }
        func_001c9750(base);
        *(u16 *)(DAT_0076449c + 0xC00) = 1;
    }
}
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
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_3 + 0x30) + 0xA64)) != 0) {
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
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
#pragma optimization_level 1
// FUN_00225D00
void func_00225d00(u8 *arg0)
{
    u32 temp_4;
    s32 temp_3;
    u8 *temp_5;
    extern s32 func_00243ce0(u8 *arg0);

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x100) == *(s32 *)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_5 + 0x30) + 0xA64)) == 0) {
            func_001cbfe0((int)arg0);
            return;
        }
        temp_4 = *(u16 *)(arg0 + 0x10E);
        temp_3 = *(u16 *)(arg0 + 0x10C) + 1;
        *(u16 *)(arg0 + 0x10C) = temp_3;
        temp_3 = (u16)temp_3;
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
#pragma optimization_level 2
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
void func_002282d0(u8 *arg0)
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
    u32 temp_2_2;
    u8 *base;
    u16 *raw;
    u8 *temp_17;
    extern void func_001b73f0(u8 *arg0);
    extern void func_001bf5e0();

    if (func_00243ce0(
            (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64)) != 0) {
        func_001b73f0(0);
        index = (u32)(func_00231d70(2) & 0xFFFF);
        base = *(u8 **)(DAT_0076449c + 0xB98);
        temp_17 = base + index * 0x34 + 0x548;
        func_001bd780(work.quat1, temp_17 + 4, temp_17 + 0x10,
                      D_0060A0E0);
        work.first = *(Vec3 *)(temp_17 + 4);
        func_001bd780(work.quat2, temp_17 + 0x1C, temp_17 + 0x28,
                      D_0060A0E0);
        work.second = *(Vec3 *)(temp_17 + 0x1C);
        raw = (u16 *)temp_17;
        temp_2_2 = *raw;
        if (temp_2_2 >= 0) {
            var_f1 = (f32)temp_2_2;
        } else {
            temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
            var_f1 = (f32)(s32)temp_2_2;
            var_f1 = var_f1 + var_f1;
        }
        var_f1 = var_f1 / 30.0f;
        func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                      (f32 *)&work.second, 1);
        func_001bbef0(DAT_0076449c + 0x24, var_f1);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 1, 0);
        return;
    }
    func_001bf5e0(arg0);
}
// FUN_00228480
void func_00228480(u8 *arg0) {
    if (func_00243ce0((u8 *)*(s32 *)((u8 *)(*(u8 **)((u8 *)(*(u8 **)((u8 *)(arg0) + 0xE0)) + 0x30)) + 0xA64)) == 0) {
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

    func_001bd560((f32 *)&work.first, (f32 *)(arg0 + 0x9C));
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = (f32 *)(temp_2 + 0x6B4);
    func_001bd780(work.third, temp_16, (u8 *)temp_16 + 0xC, D_0060A0E0);
    work.second = *(Vec3 *)temp_16;
    func_001bac20((u16 *)arg0, (f32 *)&work.first, (f32 *)&work.second, 1);
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
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
// FUN_002286C0
void func_002286c0(void)
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
    temp_16 = temp_2 + 0x5B0;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
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
    func_001bab00((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    func_001bd5a0((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}
// FUN_00228890
void func_00228890(void)
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
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = temp_2 + 0x6E4;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
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
void func_00228a80(u8 *arg0)
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
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u32 temp_2_2;
    u8 *temp_16_2;
    u8 *temp_17;
    u8 *temp_2;
    extern u8 D_00633740[];

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (func_004bd050(0) & 1) * 0xF4;
        index_offset = ((temp_16 & 0xFFFF) - 2) * 0x1E8;
        func_001bdd80(arg0, (u8 *)&D_00633740 + index_offset + flag_offset, 8);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 3, 0);
        return;
    }
    temp_5 = func_00231d70(2) & 0xFFFF;
    if (*(u8 *)(temp_17 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_17 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    func_001bd780(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    func_001bd780(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
}
// FUN_00228D00
void func_00228d00(u8 *arg0) {
    if (func_001f0ff0(*(u8 **)((u8 *)(arg0) + 0xE0)) != 0) {
        func_001bdeb0(arg0);
    }
}

// FUN_00228D50
void func_00228d50(u8 *arg0)
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
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;

    if (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA2) == 0) {
        func_00225ec0();
        return;
    }
    temp_16 = *(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30);
    temp_5 = func_00231d70(2) & 0xFFFF;
    if (*(u8 *)(temp_16 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_16 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    func_001bd780(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    func_001bd780(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
}
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
    func_001bab00((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    func_001bd5a0((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}

// FUN_00229020
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00229020);
/* measured: opt_propagation off preserves func_002299b0's initial GP-load/store order (nd 0). */
#pragma opt_propagation off
// FUN_002299B0
void func_002299b0(u8 *arg0)
{
    u8 *saved_arg0;
    struct {
        u8 data[0x10];
        u8 pad[0x10];
    } sp;
    s32 temp_17;
    u8 *var_16;
    u8 *temp_5;
    temp_5 = DAT_0076449c;
    *(s16 *)(temp_5 + 0xC34) = 0;
    saved_arg0 = arg0;
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(s32 *)(temp_3 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(u16 *)(temp_3 + 0x18) =
            (u16)(*(u16 *)(temp_3 + 0x18) | 0x23);
    }
    func_001a03b0((s64 *)saved_arg0);
    temp_17 = func_001d3d50(0);
    func_001d3ea0((int)temp_17, (u32)func_0022ced0(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001b1510();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2;
        temp_2 = func_001bc920(saved_arg0, 0x2D);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 0);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_0019bbe0((BtlUnit *)(*(u8 **)(saved_arg0 + 0x30)),
                              0xFFFFFF, 0x50, 0, 4, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 1);
    }
    var_16 = saved_arg0;
    {
        s32 temp_2;
        u8 *temp_2_5;

        temp_2 = (s32)func_0019ef90(1, 0x106);
        if (temp_2 == 0) {
            goto after_ef90;
        }
        var_16 = (u8 *)func_001b0c80(temp_2);
        func_001f0a10((u8 *)sp.data);
        *(s32 *)(sp.data + 8) = 0x100000;
        temp_2_5 = (u8 *)func_001f36e0((s32)(u32)var_16, (s32)(u32)var_16,
                                      (void *)sp.data, 1, 1);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 1);
        temp_2_5 = func_00199ee0(*(u8 **)(var_16 + 0x30),
                                 9, 0, 0, 1.0f);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 0);
after_ef90:
        ;
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001f81f0(2, (const char *)D_006354B0);
        *(u16 *)(temp_2 + 0x48) = 2;
        func_00194590(temp_2, 1);
    }
    {
        u8 *temp_2;
        temp_2 = func_001d6240(temp_17,
                               *(u8 **)(saved_arg0 + 0x30),
                               *(u8 **)(var_16 + 0x30), 0, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    {
        u8 *temp_2;
        temp_2 = func_001d6240(temp_17,
                               *(u8 **)(saved_arg0 + 0x30),
                               *(u8 **)(var_16 + 0x30), 1, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    func_001d3e00(temp_17);
}
/* measured: close opt_propagation after func_002299b0 (nd 0). */
#pragma opt_propagation on
// FUN_00229C40
s32 func_00229c40(u8 *arg0)
{
    u8 *temp_2_2;
    u8 *temp_2;
    u8 *temp_4_3;

    if (func_00193bf0(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_2 = (u8 *)func_0019ef90(1, 0x106);
        if (temp_2 != NULL) {
            temp_2_2 = (u8 *)func_001b0c80((s32)temp_2);
            *(u16 *)(temp_2_2 + 0x1A) =
                (u16)(*(u16 *)(temp_2_2 + 0x1A) | 8);
            *(s32 *)(*(u8 **)(temp_2_2 + 0x30) + 0x9C) |= 8;
            *(u16 *)(*(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64)) &= 0xFFDF;
        }
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) & 0xFFF7);
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) | 0x400);
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~8;
        func_0019d0c0(*(u8 **)(arg0 + 0x30));
        func_002339d0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
        func_00198dd0(*(u8 **)(arg0 + 0x30), 0);
        func_00198920(*(u8 **)(arg0 + 0x30), 0, 0, 1.0f, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_0062D920[0];
        temp_4_3 = DAT_0076449c;
        *(s32 *)(temp_4_3 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
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
void func_0022ae00(u8 *arg0)
{
    struct {
        u8 data[0x10];
        u8 pad[0x10];
    } sp;
    s32 sp38;
    s32 temp_16;

    func_00106390(0x15C0, 0);
    *(s8 *)(DAT_0076449c + 0xC10) = -1;
    *(s8 *)(DAT_0076449c + 0xC13) = -1;
    *(s8 *)(DAT_0076449c + 0xC28) = -1;
    *(s8 *)(DAT_0076449c + 0xC22) = -1;
    *(s8 *)(DAT_0076449c + 0xC1A) = -1;
    *(s8 *)(DAT_0076449c + 0xC12) = -1;
    *(s8 *)(DAT_0076449c + 0xC18) = -1;
    {
        u8 *temp_3;
        temp_3 = *(u8 **)(arg0 + 0x30);
        *(u16 *)(temp_3 + 0x9D8) =
            (u16)(*(u16 *)(temp_3 + 0x9D8) & 0xFFDF);
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3_2;
        temp_3_2 = DAT_0076449c;
        *(u16 *)(temp_3_2 + 0x18) =
            (u16)(*(u16 *)(temp_3_2 + 0x18) | 0x23);
    }
    func_001a03b0((s64 *)arg0);
    temp_16 = func_001d3d50(0);
    func_001d3ea0((int)temp_16, (u32)func_0022ced0(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001b1510();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4_2;
        temp_4_2 = DAT_0076449c;
        *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2_2;
        temp_2_2 = func_00199ee0(*(u8 **)(arg0 + 0x30),
                                 0xC, 0, 0, 1.0f);
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 0);
    }
    {
        u8 *temp_2_3;
        temp_2_3 = (u8 *)func_0019a980((BtlUnit *)(*(u8 **)(arg0 + 0x30)));
        *(s16 *)(temp_2_3 + 0x48) = 1;
        *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_3, 0);
    }
    func_001f0a10((u8 *)sp.data);
    *(s32 *)(sp.data + 8) = 0x100000;
    {
        u8 *temp_2_4;
        temp_2_4 = (u8 *)func_001f36e0((s32)(u32)arg0, (s32)(u32)arg0,
                                      (void *)sp.data, 1, 1);
        *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_4, 1);
    }
    {
        u8 *temp_5;
        u8 *temp_2_5;
        temp_5 = *(u8 **)(arg0 + 0x30);
        temp_2_5 = func_001d6240(temp_16, temp_5, temp_5, 0, 0x200);
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_5, 2);
    }
    {
        u8 *temp_5_2;
        u8 *temp_2_6;
        temp_5_2 = *(u8 **)(arg0 + 0x30);
        temp_2_6 = func_001d6240(temp_16, temp_5_2, temp_5_2, 1, 0x200);
        *(s64 *)(temp_2_6 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_6, 2);
    }
    func_001d3e00(temp_16);
}
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
/* measured: opt_loop_invariants on probe for func_0022b870. */
#pragma opt_loop_invariants on
// FUN_0022B870
s32 func_0022b870(u8 *arg0)
{
    extern void func_0019ea60(u8 *arg0, s32 arg1);
    extern u32 func_00231af0(DatUnit *unit, u8 genus, u16 id);
    extern s32 func_001b0d70(u8 *arg0);
    extern s32 func_001b1540(void);
    extern void func_0022fdc0(u8 *arg0);
    extern u8 *func_001f7650(u8 *arg0);
    extern void func_00198dd0(u8 *arg0, s32 arg1);
    extern u8 D_00630C50[];
    u32 index;
    s32 value;
    s32 fill;
    u8 *temp;

    if (func_00193bf0(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        *(s32 *)(DAT_0076449c + 0xC) &= 0xFFF7FFFF;
        func_0019ea60(*(u8 **)(arg0 + 0x30), 0x10E);
        func_00231af0((DatUnit *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)), 1, 0x10E);
        func_00106390(0x15FF, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_00630C50[0];
        *(s32 *)(DAT_0076449c + 0xC40) = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) |= 0x2000;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= 0xFFFF7FFF;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~0x20;
        temp = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp |= 0x20;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        func_001b0d70(arg0);
        func_0022fdc0((u8 *)func_001b1540());
        index = 0;
        fill = -1;
        goto loop_test;
loop_body:
        *(s8 *)(DAT_0076449c + index + 0xC10) = fill;
        index++;
loop_test:
        if (index < 0x1E) {
            goto loop_body;
        }
        value = (s32)func_001f7650(*(u8 **)(arg0 + 0x30));
        *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA00) + 0x2DC) = value;
        func_00198dd0(*(u8 **)(arg0 + 0x30), 6);
        func_00106390(0x15C0, 0);
        *(s32 *)(DAT_0076449c + 0xBB4) = 0;
        *(s32 *)(DAT_0076449c + 0xBC8) = 0;
        *(u16 *)(DAT_0076449c + 0x290) |= 0x10;
        return 0;
    }
    return 1;
}
/* measured: closes opt_loop_invariants around func_0022b870. */
#pragma opt_loop_invariants off
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
        p = (u8 *)func_001b0c80((s32)p);
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
#pragma opt_propagation off
// FUN_0022CC90
void func_0022cc90(void)
{
    extern void func_0010b010(s32 arg0);
    extern s32 func_0010b300(s32 arg0);
    extern void func_0010b7c0(void);
    extern void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
    extern void func_00454bd0(s32 arg0);
    extern void func_001d3e00(s32 arg0, u8 *arg1);
    s16 i;
    s32 value;
    s32 temp_index;
    s32 index;
    s16 index16;
    u8 *slot;
    u8 *base;

    switch (func_001ef9a0()) {
    case 0x214:
        func_0010b7c0();
        func_0010b010(1);
        func_0010b300(1);
        func_00106d40(1, 0, 1);
        break;
    }
    i = 0;
    while (i < 8) {
        base = DAT_0076449c;
        slot = base + i * 4;
        value = *(s32 *)(slot + 0xBE0);
        if (value != 0) {
            index16 = i;
            temp_index = (s32)(s64)(s16)index16;
            index = temp_index * 4;
            func_001d3e00(value, base);
            base = DAT_0076449c;
            *(s32 *)(base + index + 0xBE0) = 0;
        }
        i++;
    }
    value = *(s32 *)(DAT_0076449c + 0xB94);
    if (value != 0) {
        func_00454bd0(value);
        *(s32 *)(DAT_0076449c + 0xB94) = 0;
    }
    value = *(s32 *)(DAT_0076449c + 0xB90);
    if (value != 0) {
        func_00454bd0(value);
        *(s32 *)(DAT_0076449c + 0xB90) = 0;
    }
}
#pragma opt_propagation on
// FUN_0022CDB0
u8 *func_0022cdb0(s32 arg0)
{
    s32 temp_2;
    u8 *var_2;

    if ((*(s32 *)(DAT_0076449c + 0x10) & 0x10) == 0) {
        return NULL;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x20B:
        if (*(s32 *)(DAT_0076449c + 0xC40) == 0) {
            var_2 = (u8 *)((s32)&D_00634CB0 +
                           ((arg0 & 0xFFFF) * 0x14));
        } else {
            var_2 = (u8 *)((s32)&D_006350B0 +
                           ((arg0 & 0xFFFF) * 0x14));
        }
        break;
    case 0x215:
        var_2 = (u8 *)((s32)&D_006350B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    default:
        var_2 = (u8 *)((s32)&D_006348B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    }
    if ((*(s32 *)(var_2 + 0) == 0) &&
        (*(s32 *)(var_2 + 4) == 0)) {
        var_2 = NULL;
    }
    return var_2;
}
// FUN_0022CED0
u8 *func_0022ced0(s32 arg0)
{
    func_00455ea0(*(s32 *)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

// FUN_0022CF00
f32 func_0022cf00(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_3;
    u16 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return -1.0f;
    }
    if (*(u8 *)(arg1 + 0xA2) != 1) {
        return -1.0f;
    }
    temp_3 = arg2 & 0xFFFF;
    if ((temp_3 != 4) && (temp_3 != 0xC) &&
        (temp_3 != 5) && (temp_3 != 7)) {
        return -1.0f;
    }
    temp_2 = *(u16 *)(arg1 + 0xA4);
    switch (temp_2) {
    case 0x100:
        return 100.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x101:
        return 25.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x102:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x103:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x110:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x111:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x104:
        return 50.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x105:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x106:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10F:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x107:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x108:
        return 300.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10A:
        return 500.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x113:
        return 75.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x109:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x112:
    default:
        goto fail;
    }
fail:
    return -1.0f;
}
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
            func_001ec6d0((s16 *)(var_16 + 0x94), (s16 *)(var_16 + 0x96),
                          (f32 *)&temps.sp20);
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
s32 func_0022f520(void)
{
    struct {
        s64 a;
        s64 b;
        s64 c;
    } sp30;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0) {
        return 0;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x202: {
        u8 *var_17;
        u8 *temp_16;
        temp_2_2 = func_0019ef90(1, 0x102);
        if ((temp_2_2 == NULL) ||
            (func_002428f0(*(s32 **)(temp_2_2 + 0xA64), 0) != 0)) {
            func_001f0a10((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_17 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_14_check;
loop_0022f520_14_body:
            if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
                temp_16 = *(u8 **)(var_17 + 0x30);
                if ((*(u8 *)(temp_16 + 0xA2) == 1) &&
                    (*(u16 *)(temp_16 + 0xA4) != 0x102) &&
                    (func_002428f0(*(s32 **)(temp_16 + 0xA64), 0) == 0)) {
                    func_00194590(
                        (u8 *)func_001f36e0((s32)(u32)var_17, (s32)(u32)var_17,
                                            (void *)&sp30, 1, 1),
                        1);
                    func_00194590(
                        func_00199ee0(temp_16, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_17 = *(u8 **)(var_17 + 0x450);
loop_0022f520_14_check:
            if (var_17 != NULL) {
                goto loop_0022f520_14_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    case 0x203: {
        u8 *temp_17;
        u8 *var_16;
        temp_2_3 = func_0019ef90(1, 0x103);
        if ((temp_2_3 == NULL) ||
            (func_002428f0(*(s32 **)(temp_2_3 + 0xA64), 0) != 0)) {
            func_001f0a10((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_16 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_25_check;
loop_0022f520_25_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) != 0) {
                temp_17 = *(u8 **)(var_16 + 0x30);
                if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
                    (*(u16 *)(temp_17 + 0xA4) != 0x103) &&
                    (func_002428f0(*(s32 **)(temp_17 + 0xA64), 0) == 0)) {
                    func_00194590(
                        (u8 *)func_001f36e0((s32)(u32)var_16, (s32)(u32)var_16,
                                            (void *)&sp30, 1, 1),
                        1);
                    func_00194590(
                        func_00199ee0(temp_17, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_0022f520_25_check:
            if (var_16 != NULL) {
                goto loop_0022f520_25_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    default:
        goto block_0022f520_27;
    }
block_0022f520_27:
    return 0;
}
// FUN_0022F7D0
s32 func_0022f7d0(u8 *arg0, u8 *arg1) {
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_4;

    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x208:
        temp_2_2 = (u8 *)func_001b1510();
        if (temp_2_2 != NULL) {
            temp_4 = *(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64);
            if ((temp_4 != NULL) && (func_00232710(temp_4, 0x100) == 0)) {
                return 0;
            }
        }
        func_001958f0((BtlUnit *)(*(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30)),
                      (RwV3d *)arg1);
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