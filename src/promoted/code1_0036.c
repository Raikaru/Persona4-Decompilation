#include "include_asm.h"
#include "type.h"
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
extern void func_0036bbf0();

extern void func_003642e0(u8 *arg0, void *arg1);

extern void memset(void *dst, s32 value, s32 size);

extern void func_0036b650(u8 *arg0);
extern void func_0036aa20(void);
extern void func_0036d8b0(void);

extern void func_0036b750(void);
extern s32 func_0036bb60(void);
extern void func_001437b0(u8 *arg0, s16 arg1, s32 arg2);



extern s32 func_0034c210(void);

extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00369440(void);
extern u8 *func_00457120(void);
extern void func_003e8180(void *arg0, f32 arg1);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_00457630(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void func_0011fd30(u8 *arg0);
extern void func_0011fd50(s64 arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern void func_0046d280(s32 arg0);
extern void func_00452080(s32 arg0);
extern void func_002bb550(s8 arg0);
extern f32 iGpffff84a4;
extern f32 func_0044b610(f32 arg0);
static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
extern void func_00367420(void);
extern void func_003675f0(void);
extern void func_003676f0(void);
extern void func_00367940(P4Pair arg0, f32 arg1, s32 arg2, u8 *arg3);
extern void func_003679c0(void);
extern void func_00367b80(void);
extern void func_00367d00(void);

// FUN_00361970
void func_00361970(u8 *arg0)
{
    *(s32 *)(arg0 + 0x5C4) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x32)) {
        *(f32 *)(arg0 + 0x5BC) = -10.0f;
    } else {
        *(f32 *)(arg0 + 0x5BC) = 10.0f;
    }
    *(s16 *)(arg0 + 0x26) = 0;
}



// FUN_003619B0
s32 func_003619b0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 29) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x74)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00361A30
void func_00361a30(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 var_18;
    s8 temp_4_3;
    u8 *temp_3;

    var_18 = 0;
    while (var_18 < 0x2A) {
        temp_3 = arg0 + (var_18 * 4) + 0x658;
        temp_4 = *(s32 *)temp_3;
        if (temp_4 != 0) {
            func_0046d280(temp_4);
            *(s32 *)temp_3 = 0;
        }
        var_18 += 1;
    }
    temp_4_2 = *(s32 *)(arg0 + 0x704);
    if (temp_4_2 != 0) {
        func_00452080(temp_4_2);
        *(s32 *)(arg0 + 0x704) = 0;
    }
    temp_4_3 = *(s8 *)(arg0 + 0x3C);
    if (temp_4_3 != -1) {
        func_002bb550(temp_4_3);
        *(s8 *)(arg0 + 0x3C) = -1;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}
// FUN_00361AE0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00361ae0);
// FUN_00361CA0
void func_00361ca0(u8 *arg0) {
    s16 c = *(s16 *)(arg0 + 0x26);
    s32 count;
    s32 i;
    u8 *record;

    if (c < 100) {
        *(s16 *)(arg0 + 0x26) = c + 1;
    }
    for (i = 0; i <= 0; i++) {
        record = arg0 + i * 0x30;
        count = *(s16 *)(arg0 + 0x26);
        func_001437b0(record + 0x5B8, count, 0);
    }
  }

// FUN_00361D20
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00361d20);
// FUN_00362630
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00362630);
// FUN_003627B0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003627b0);
// FUN_00362F00
s32 func_00362f00(u8 *arg0)
{
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s16 temp_2;
    s16 temp_3;

    temp_3 = *(s16 *)(arg0 + 0x18);
    if (temp_3 < *(s16 *)(arg0 + 0x1A)) {
        *(s16 *)(arg0 + 0x18) = temp_3 + 1;
        temp_2 = *(s16 *)(arg0 + 0x18);
        temp_f4 = 1.0f - func_0044b610(iGpffff84a4 * ((f32)temp_2 / (f32)*(s16 *)(arg0 + 0x1A)));
        temp_f3 = *(f32 *)(arg0 + 0);
        temp_f2 = *(f32 *)(arg0 + 8);
        temp_f2 = temp_f2 - temp_f3;
        temp_f1 = *(f32 *)(arg0 + 0xC);
        temp_f0 = *(f32 *)(arg0 + 4);
        temp_f1 = temp_f1 - temp_f0;
        temp_f2 = temp_f2 * temp_f4;
        temp_f1 = temp_f1 * temp_f4;
        temp_f2 = temp_f2 + temp_f3;
        *(f32 *)(arg0 + 0x10) = temp_f2;
        temp_f0 = *(f32 *)(arg0 + 4);
        temp_f0 = p4_00362f00_add(temp_f1, temp_f0);
        *(f32 *)(arg0 + 0x14) = temp_f0;
        return 0;
    }
    return 1;
}
// FUN_003642A0
void func_003642a0(u8 *arg0)
{
    u16 *temp = *(u16 **)(arg0 + 0x38);

    func_003642e0(arg0, NULL);
    *temp |= 2;
}



// FUN_003642E0
void func_003642e0(u8 *arg0, void *arg1)
{
    u16 *temp;

    temp = *(u16 **)(arg0 + 0x38);
    if (arg1 != NULL) {
        *temp |= 1;
    } else {
        *temp &= (u16)~1;
    }
}
// FUN_00366380
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366380);
// FUN_00366670
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366670);
// FUN_00366960
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366960);
// FUN_00366C70
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366c70);
// FUN_003671D0
void func_003671d0(s16 *arg0)
{
    memset((u8 *)arg0 + 4, 0, 0x18);
    *arg0 = 0;
}



// FUN_00367210
void func_00367210(P4Pair arg0, f32 arg4, s32 arg1, s16 *arg2, s32 arg3)
{
    P4Pair sp18;
    s16 temp_3;

    sp18 = arg0;
    if (arg1 & 0xFF) {
        temp_3 = *arg2;
        switch (temp_3) {
        case 0:
            func_00367420();
            return;
        case 1:
            func_003675f0();
            return;
        case 2:
            func_003676f0();
            return;
        case 3:
            func_00367940(arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 4:
            func_003679c0();
            return;
        case 5:
            func_00367b80();
            return;
        case 6:
            func_00367d00();
            break;
        }
    }
}
// FUN_003672D0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003672d0);
// FUN_00367420
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00367420);
// FUN_003675F0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003675f0);
// FUN_003676F0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003676f0);
// FUN_00367940
void func_00367940(P4Pair arg0, f32 fparg0, s32 arg1, u8 *arg2) { u8 tmp[12]; f32 factor; factor = fparg0; func_0011fd30(tmp); *(s32 *)(tmp + 8) = 3; *(s16 *)(tmp + 6) = 1; *(s16 *)tmp = *(s16 *)(arg2 + 4); func_0011fd50(*(s64 *)&arg0, factor, arg1, tmp, 1); }

// FUN_003679C0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003679c0);

// FUN_00367B80
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00367b80);

// FUN_00367D00
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00367d00);

// FUN_00368D30
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00368d30);

// FUN_00368E80
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00368e80);
// FUN_00369470
void func_00369470(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00369440;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_0036AE90
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_0036ae90);
// FUN_0036B630
void func_0036b630(u8 *arg0, RwV3d *arg1)
{
    *(RwV3d *)(arg0 + 0x994) = *arg1;
}
// FUN_0036D860
void func_0036d860(u8 *arg0, s32 arg1)
{
    func_0036b650(arg0);
    func_0036aa20();
    if (arg1 != 0) {
        func_0036d8b0();
    }
}



// FUN_0036D8B0
void func_0036d8b0(void)
{
    struct {
        s32 f20;
        s32 f24;
        s32 f28;
        s32 pad2c;
        s32 f30;
        s32 f34;
        s32 f38;
        u8 pad[4];
    } local;
    s32 temp_2;

    temp_2 = (s32)func_00457120();
    func_003e8180((void *)temp_2, 1.0f);
    local.f30 = 0;
    local.f34 = 0;
    local.f38 = 0;
    local.f20 = 0;
    local.f24 = 0;
    local.f28 = 0x43480000;
    func_004577d0((void *)temp_2, 100.0f);
    func_00457630((void *)temp_2, &local.f30, &local.f20, 0);
}
// FUN_0036D940
void func_0036d940(void)
{
    func_0036bbf0();
}

// FUN_0036D960
s32 func_0036d960(void)
{
    func_0036b750();
    return !func_0036bb60();
}
