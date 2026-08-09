#include "include_asm.h"
#include "type.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_002baa50(void);
extern void func_002baa90(s32 *arg0);
extern void func_002bb7c0(s32 arg0);
extern void func_002bd440(void);

extern void func_002bb9e0(u8 *arg0, s32 arg1);

extern s32 func_002bc0e0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_002bcc60(u8 *arg0);
extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void func_0046d730(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern void func_0045a9a0(s32 arg0, s32 arg1);

extern s32 clndGetMoonPhase(void);

extern u32 func_00106a90(s16 arg0);
extern u8 *D_00882F40[];
extern void func_00278450(s32 arg0);
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern s8 D_007488F8[];
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 *func_002bbf70(void);
extern s32 func_002bb0e0(void);
extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_00279350(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern s32 func_00106880(void);
extern void func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00145080(void);
extern void func_003f6440(s32 arg0, s32 arg1);



// FUN_002B2940
s32 func_002b2940(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}
// FUN_002B2950
void func_002b2950(s32 arg0)
{
    iGpffffb55c = arg0;
}
// FUN_002B2960
s32 func_002b2960(void)
{
    return iGpffffb55c;
}
// FUN_002B2970
void func_002b2970(u8 *arg0, f32 arg1, f32 arg2)
{
    struct Float2 {
        f32 x;
        f32 y;
    } val;

    val.x = arg1;
    val.y = arg2;
    *(struct Float2 *)arg0 = val;
}
// FUN_002B29A0
void func_002b29a0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Float3 {
        f32 x;
        f32 y;
        f32 z;
    } val;

    val.x = arg1;
    val.y = arg2;
    val.z = arg3;
    *(struct Float3 *)arg0 = val;
}
// FUN_002B29E0
void func_002b29e0(u8 *arg0, f32 arg1, f32 arg2)
{
    struct Float2Int2 {
        f32 x;
        f32 y;
        s32 z;
        s32 w;
    } val;

    val.z = (s32)arg1;
    val.w = (s32)arg2;
    *(struct Float2Int2 *)arg0 = val;
}
// FUN_002B2A30
s32 func_002b2a30(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 result;

    result = arg3 & 0xFF;
    result = p4_pack_or(result, (arg2 & 0xFF) << 8);
    result = p4_pack_or((arg1 & 0xFF) << 16, result);
    result = p4_pack_or((arg0 & 0xFF) << 24, result);
    return result;
}
// FUN_002B2A60
void func_002b2a60(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    struct Byte4 {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } val;

    val.b0 = (u8)arg1;
    val.b1 = (u8)arg2;
    val.b2 = (u8)arg3;
    val.b3 = (u8)arg4;
    *(struct Byte4 *)arg0 = val;
}
// FUN_002B2AA0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2aa0);
// FUN_002B2BD0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2bd0);
// FUN_002B2CB0
s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 + arg1;
    }
    {
        s32 var = arg0 + arg1;
        s32 bound;
        if (arg2 < var) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D00
s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 - arg1;
    }
    {
        s32 var = arg0 - arg1;
        s32 bound;
        if (var < arg2) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D50
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2d50);
// FUN_002B2E70
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2e70);
// FUN_002B2F90
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2f90);
// FUN_002B3050
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3050);

/* measured: opt_rebuildconditionals off probe for min/max */
#pragma opt_rebuildconditionals off
// FUN_002B3110
s32 func_002b3110(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 < arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
// FUN_002B3140
s32 func_002b3140(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 > arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
/* measured: close opt_rebuildconditionals after min/max */
#pragma opt_rebuildconditionals on
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
#pragma opt_loop_invariants on
// FUN_002B3170
s32 func_002b3170(s32 arg0)
{
    s32 result;

    result = 0;
    do {
        arg0 /= 10;
        result++;
    } while (arg0 != 0);
    return result;
}
/* measured: close opt_loop_invariants after 3170. */
#pragma opt_loop_invariants off
// FUN_002B31A0
void func_002b31a0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 second;
    struct Vec3 result;

    first = *(struct Vec3 *)arg1;
    second = *(struct Vec3 *)arg2;
    result.x = first.x - second.x;
    result.y = first.y - second.y;
    result.z = first.z - second.z;
    *(struct Vec3 *)arg0 = result;
}
// FUN_002B3230
s32 func_002b3230(s16 *arg0, s16 *arg1) {
    s16 b;
    u32 x;
    u32 y;

    b = *arg1;
    x = func_00106a90(*arg0);
    y = func_00106a90(b);
    if (x < y) {
        return 1;
    }
    return -(s32)(y < x);
}

// FUN_002B32A0
s32 func_002b32a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 var;

    var = arg3;
    if (arg0 >= arg1) {
        return arg1;
    }
    if (arg2 == 0) {
        var = 0;
    }
    return var;
}
// FUN_002B32D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b32d0);
// FUN_002B3520
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3520);
// FUN_002B3720
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3720);
// FUN_002B3960
void func_002b3960(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B5100
void func_002b5100(u8 *arg0, s8 arg1)
{
    if (arg0 != NULL) {
        *(s8 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
    }
}
// FUN_002B5120
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b5120);
// FUN_002B52A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b52a0);
// FUN_002B5C60
void func_002b5c60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002BA080
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba080);
// FUN_002BA5D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba5d0);
// FUN_002BA970
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba970);
// FUN_002BAA20
void func_002baa20(void)
{
    func_002baa90(D_00882F60);
    func_002baa50();
}
// FUN_002BAA50
void func_002baa50(void)
{
    s32 i;
    u8 **t;

    i = 0;
    t = D_00882F40;
    while (i < 5) {
        t[i] = NULL;
        i++;
    }
}
// FUN_002BAB80
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bab80);
// FUN_002BACB0
s8 func_002bacb0(void) {
    s32 i = 0;
    u8 **t = D_00882F40;

    while (i < 5) {
        if (t[i] == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002BAD10
s32 func_002bad10(s32 arg0)
{
    s32 *temp_2;
    s32 temp_4;

    temp_2 = func_002bbf70();
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = temp_2[0];
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 0);
    func_00278170(temp_2[0], 0x200000);
    func_002778c0(temp_2[0], arg0, 0);
    func_00277010(temp_2[0], -1);
    *(s8 *)((u8 *)temp_2 + 4) = 1;
    return 1;
}
// FUN_002BADC0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002badc0);
// FUN_002BAE80
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bae80);
// FUN_002BAF40
s32 func_002baf40(s32 arg0) {
    s32 *p;

    p = func_002bbf70();
    if (p == NULL) {
        return 0;
    }
    if (*p < 0) {
        return 0;
    }
    p[2] = arg0;
    *((s8 *)p + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}

// FUN_002BAFC0
s32 func_002bafc0(s64 arg0, s32 arg1)
{
    u8 **temp_16;
    u8 *temp_3;

    temp_16 = &D_00882F40[(s8)arg0];
    temp_3 = *temp_16;
    if (temp_3 == NULL) {
        return 0;
    }
    if (*(s32 *)temp_3 < 0) {
        return 0;
    }
    *(s32 *)(temp_3 + 8) = arg1;
    *(s8 *)(*temp_16 + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}
// FUN_002BB180
s8 func_002bb180(s64 arg0)
{
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return -1;
    }
    return *(s8 *)(p + 0xD);
}
// FUN_002BB420
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb420);
// FUN_002BB4E0
s32 func_002bb4e0(void) {
    s32 *temp_2;
    s32 temp_4;

    temp_2 = (s32 *)(func_002bbf70());
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = (s32)(*(s32 *)((u8 *)(temp_2) + 0));
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)((u8 *)(temp_2) + 0) = -1;
        *(s8 *)((u8 *)(temp_2) + 4) = 0;
        *(s8 *)((u8 *)(temp_2) + 5) = 0;
    }
    func_002e0dd0();
    return 1;
}

// FUN_002BB550
s32 func_002bb550(s64 arg0)
{
    s32 temp_4;
    u8 **temp_16;
    u8 *temp_2;

    temp_16 = D_00882F40 + (s8)arg0;
    temp_2 = *temp_16;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0);
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)(*temp_16 + 0) = -1;
        *(s8 *)(*temp_16 + 4) = 0;
        *(s8 *)(*temp_16 + 5) = 0;
        jtbl_008873EC[0](*temp_16);
        *temp_16 = NULL;
    }
    func_002e0dd0();
    return 1;
}
// FUN_002BB680
s32 func_002bb680(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return 0;
    }
    if (*(s32 *)p < 0) {
        return 0;
    }
    if (*(s8 *)(p + 5) != 0) {
        if (*(s8 *)(p + 4) == 2) {
            return 0;
        }
    }
    return *(s8 *)(p + 4);
}

// FUN_002BB7C0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb7c0);
// FUN_002BB9E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb9e0);
// FUN_002BBCC0
void func_002bbcc0(void)
{
    func_002bb7c0(1);
}
// FUN_002BBCF0
void func_002bbcf0(u8 *arg0) {
    func_002bb9e0(arg0, 1);
}



// FUN_002BBD80
void func_002bbd80(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p != NULL) {
        func_00278450(*(s32 *)p);
    }
}

// FUN_002BC0B0
void func_002bc0b0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    func_002bc0e0(arg0, arg1, arg2, 1, arg3, arg4);
}



// FUN_002BC0E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc0e0);
// FUN_002BC4B0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc4b0);
// FUN_002BC7A0
void func_002bc7a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_002791f0(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0);
}

// FUN_002BC7F0
void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_00279350(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0, &D_00793E80[arg5 * 0x30]);
}

// FUN_002BC860
void func_002bc860(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    func_002791f0(arg0, arg1, arg2, 1, D_0063F2C8[0], arg3);
}
// FUN_002BC890
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc890);
// FUN_002BC9E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc9e0);
// FUN_002BCBC0
s32 func_002bcbc0(s32 arg0, s32 arg1)
{
    u8 *temp_3;

    if (arg0 == 0) {
        func_0046d730(D_0063F2A0, 0x58F);
    }
    if (arg1 < 0) {
        goto error;
    }
    if (arg1 <= 0xB) {
        goto done;
    }
error:
    func_0046d730(D_0063F2A0, 0x590);
done:
    temp_3 = (u8 *)(arg0 + arg1 * 0xC);
    *(s32 *)(temp_3 + 0x1C) |= 4;
    return 0;
}
// FUN_002BD280
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd280);
// FUN_002BD3E0
void func_002bd3e0(void) {
    func_002bcc60(D_0072466C);
}



// FUN_002BD410
void func_002bd410(void)
{
    func_0045a9a0(1, 0);
    func_002bd440();
}
// FUN_002BD7B0
s32 func_002bd7b0(void)
{
    u8 *p;
    s32 temp_2;

    p = (u8 *)D_00882F60;
    if (p != NULL) {
        *(s32 *)(p + 0) = -1;
        *(s8 *)(p + 4) = 0;
        *(s8 *)(p + 5) = 0;
        *(s32 *)(p + 8) = -1;
        *(s8 *)(p + 0xC) = 1;
        *(s8 *)(p + 0xD) = 1;
    }
    if (*(s32 *)(p + 0) < 0) {
        temp_2 = func_002774d0();
        *(s32 *)(p + 0) = temp_2;
        func_00278610(temp_2, 1);
        return 1;
    }
    return 0;
}
// FUN_002BD840
s32 func_002bd840(s32 arg0)
{
    u8 *p;

    p = (u8 *)D_00882F60;
    if (*(s32 *)(p + 0) < 0) {
        return 0;
    }
    func_00278610(*(s32 *)(p + 0), 1);
    func_00278170(*(s32 *)(p + 0), 0x200000);
    func_002778c0(*(s32 *)(p + 0), arg0, 0);
    *(s8 *)(p + 4) = 1;
    func_00277010(*(s32 *)(p + 0), -1);
    return 1;
}
// FUN_002BD8E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd8e0);
// FUN_002BDB10
void func_002bdb10(u8 *arg0)
{
    func_00145080();
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_002BDFF0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bdff0);
// FUN_002BE100
s32 func_002be100(s32 arg0) {
    s32 i = 0;
    s32 key = arg0 & 0xFF;
    s8 *t = D_007488F8;

    while ((i & 0xFF) < 0xC) {
        if (key == t[i & 0xFF]) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
    return 0;
}

// FUN_002BE160
s32 func_002be160(u8 *arg0, s32 arg1) {
    s32 n = arg1 & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase() & 0xFF) >= n;
}

// FUN_002BE1B0
void func_002be1b0(void)
{
    func_002be1e0(func_00106880());
}
// FUN_002BE1E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be1e0);
// FUN_002BE3C0
void func_002be3c0(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7100D);
}
// FUN_002BE4A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be4a0);