#include "include_asm.h"
#include "type.h"
extern void (*iGpffffbb2c)();
extern void (*iGpffffbb30)();
extern void (*iGpffffbb34)();
extern void (*iGpffffbb38)();
extern void (*iGpffffbb3c)();
extern void func_00470d70(u8 *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffbb28;
extern void *D_00922BE0[];
extern void func_004b5800(u8 *arg0);
extern void func_004b5f70(u8 *arg0);
struct RuntimeWork;
extern void func_004b5f80(struct RuntimeWork* work, const u8* color);
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

extern void func_00478a30(u8 *arg0, s32 arg1);

struct MdlFlags78ec0;
extern void func_00478ec0(void* context, struct MdlFlags78ec0* model);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

extern s32 func_00479ca0(u8 *arg0, s32 arg1);

extern void func_00453ce0(u8 *arg0, s32 arg1);
extern s32 func_00453e10(u8 *arg0);
extern s32 func_00453d70(u8 *arg0);
extern s32 func_00453dc0(u8 *arg0);
/* measured: func_00470e20's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

extern s32 func_004782b0(u8 *arg0);
extern s32 func_0047e6f0(u8 *arg0);
extern s32 func_0047e0f0(u8 *arg0, s16 arg1, s16 arg2, u16 arg3);
extern void func_0045abd0(s16 arg0, s32 arg1, s16 arg2);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0045aa90(s16 arg0, s16 arg1);
extern s32 func_0045a890(s16 arg0);
extern s32 func_0045af90(s16 arg0);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern void func_00454bd0(u8 *arg0);
extern s32 func_004553c0(u8 *arg0);
extern s32 func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void func_00456150(u8 *arg0);
extern void func_00463250(void *arg0);
extern s32 func_0047b0c0(u8 *arg0);
extern s32 func_0047c660(u8 *arg0);
extern void func_0047e450(u8 *arg0, s16 arg1, s16 arg2, s32 arg3, u32 arg4);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
static inline f32 code1_0047_mul(f32 left, f32 right)
{
    return left * right;
}
static inline f32 code1_0047_madd(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + left * right;
}
static inline f32 code1_0047_madd_reverse(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + right * left;
}


// FUN_00470210
void func_00470210(u8 *arg0)
{
    func_00470d70(arg0);
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00470C10
void func_00470c10(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 2;
        *(s32 *)(temp_2 + 0x208) = arg2;
        *(s32 *)(temp_2 + 0x210) = 0;
        *(s32 *)(temp_2 + 0x214) = 1;
        func_004704d0(arg0);
    }
}



// FUN_00470C80
void func_00470c80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    temp_2 = func_00470d10(arg0, arg1);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 4;
        *(f32 *)(temp_2 + 0x20C) = (f32)arg2;
        *(s32 *)(temp_2 + 0x210) = arg3;
        *(s32 *)(temp_2 + 0x214) = arg4;
        func_004704d0(arg0);
    }
}



// FUN_00470D10
u8 *func_00470d10(u8 *arg0, s32 key)
{
    u8 *node;

    node = *(u8 **)(*(u8 **)(arg0 + 0x38) + 0x144);
    if (key == -1) {
        return NULL;
    }
    if (node == NULL) {
        return NULL;
    }
    goto compare;
advance:
    node = *(u8 **)(node + 0x228);
    if (node == NULL) {
        return NULL;
    }
compare:
    if (*(s32 *)node != key) {
        goto advance;
    }
    return node;
}

// FUN_00470D70
void func_00470d70(u8 *arg0)
{
    u8 *temp_2;
    u8 *var_3;

    temp_2 = *(u8 **)(arg0 + 0x38);
    var_3 = *(u8 **)(temp_2 + 0x144);
    while (var_3 != NULL) {
        u8 *temp_4;

        temp_4 = *(u8 **)(var_3 + 0x228);
        jtbl_008873EC[0](var_3);
        var_3 = temp_4;
    }
    *(s32 *)(temp_2 + 0x144) = 0;
    *(s32 *)(temp_2 + 0x148) = 0;
    *(s32 *)(temp_2 + 0x140) = 0;
    *(s32 *)(temp_2 + 0x134) = 0;
    *(s32 *)(temp_2 + 0x138) = 0;
    func_00453ce0(temp_2 + 0x164, 0);
    *(s32 *)(temp_2 + 0x140) = func_00453e10(temp_2 + 0x164);
    *(s32 *)(temp_2 + 0x138) = func_00453d70(temp_2 + 0x164);
    *(s32 *)(temp_2 + 0x134) = func_00453dc0(temp_2 + 0x164);
}
// FUN_00470E20
s32 func_00470e20(u8 *arg0)
{
    s32 temp_3;
    s32 var_4;
    u8 *temp_4;
    u8 *var_5;

    temp_4 = *(u8 **)(arg0 + 0x38);
    var_5 = *(u8 **)(temp_4 + 0x144);
    temp_3 = *(s32 *)(temp_4 + 0x138);
    temp_3 = viewAddReverse(temp_3, *(s32 *)(temp_4 + 0x134));
    if (temp_3 >= *(s32 *)(temp_4 + 0x140)) {
        return -1;
    }
    var_4 = 0;
    while (var_4 < temp_3) {
        var_5 = *(u8 **)(var_5 + 0x228);
        var_4 += 1;
    }
    return *(s32 *)var_5;
}

// FUN_00478E70
void func_00478e70(u8 *arg0)
{
    func_00478a30(arg0, (*(s32 *)(arg0 + 0xD8) & 1) == 0);
}



/* The draw callback's second argument supplies the model to color/setup. */
// FUN_00479030
void func_00479030(u8 *arg0, u8 *arg1)
{
    func_00478ec0(arg0, (struct MdlFlags78ec0*)arg1);
    RpSkyRenderStateSet(2, *(s32 *)(arg1 + 0xE4));
    RpSkyRenderStateSet(3, *(s32 *)(arg1 + 0xE8));
}


// FUN_00479C30
s16 func_00479c30(s32 arg0, s32 arg1)
{
    if (func_00479ca0((u8 *)arg0, arg1) != 0) {
        s32 off = (arg1 & 0xFFFF) * 0xA4;
        return *(s16 *)(off + (s32)arg0 + 0xF0);
    }
    return -1;
}


// FUN_0047ADF0
void func_0047adf0(u8 *arg0, u16 arg1, s32 arg2) {
    /* Offset added to the base, not the other way round: `arg0 + off` makes
       mwcc emit `addu $v1,$a0,$v1` where retail has `addu $v1,$v1,$a0`. */
    s32 off = arg1 * 12;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s32 *)(p + 0x294) = arg2;
}

// FUN_0047AE90
s32 func_0047ae90(u8 *arg0, u16 arg1)
{
    s32 off = arg1 * 0xC;
    u8 *p = (u8 *)(off + (s32)arg0);
    u8 *temp_4;

    temp_4 = *(u8 **)(p + 0x290);
    if (temp_4 == NULL) {
        return 1;
    }
    return func_004782b0(temp_4);
}



// FUN_0047CE00
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047ce00);
// FUN_0047D050
void func_0047d050(s32 arg0)
{
    func_0043f9c8(D_00922BE0, 0, 0x30);
    iGpffffbb28 = arg0;
}
// FUN_0047D090
s32 func_0047d090(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    iGpffffbb2c = (void (*)())arg0;
    iGpffffbb30 = (void (*)())arg1;
    iGpffffbb34 = (void (*)())arg2;
    iGpffffbb38 = (void (*)())arg3;
    iGpffffbb3c = (void (*)())arg4;
    return 1;
}
// FUN_0047D0B0
void func_0047d0b0(void)
{
    iGpffffbb2c();
}

// FUN_0047D0E0
void func_0047d0e0(void)
{
    iGpffffbb30();
}

// FUN_0047D110
void func_0047d110(void)
{
    iGpffffbb34();
}

// FUN_0047D140
void func_0047d140(void)
{
    iGpffffbb38();
}

// FUN_0047D170
void func_0047d170(void)
{
    iGpffffbb3c();
}

// FUN_0047DD40
void func_0047dd40(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 4);
    if (temp_4 != NULL) {
        func_004b5800(temp_4);
    }
}
// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg1 + 4);
    if (temp_4 != 0) {
        func_004b5c20(temp_4);
    }
}

// FUN_0047DDA0
void func_0047dda0(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 4);
    if (temp_4 != NULL) {
        func_004b5f70(temp_4);
    }
}
/* Retail forwards the requested color in a1 to the runtime color consumer. */
// FUN_0047DDD0
void func_0047ddd0(u8* attachment, const u8* color)
{
    struct RuntimeWork* work;

    work = *(struct RuntimeWork**)(attachment + 4);
    if (work != NULL) {
        func_004b5f80(work, color);
    }
}
// FUN_0047EA40
void func_0047ea40(u8 **arg0, u8 **arg1)
{
    u8 *temp_5;

    temp_5 = *arg1;
    if (temp_5 != NULL) {
        *(s32 *)(temp_5 + 8) = *(s32 *)(temp_5 + 8) + 1;
        *arg0 = temp_5;
    }
}
// FUN_0047EA70
void func_0047ea70(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 8) = -1;
    *(s16 *)(arg0 + 0x16) = -1;
    *(s16 *)(arg0 + 0x24) = -1;
    *(s16 *)(arg0 + 0x26) = -1;
    *(u16 *)(arg0 + 0x10) |= 0x20;
}
// FUN_0047EAA0
void func_0047eaa0(u8 *arg0)
{
    u8 *temp_2;
    s32 temp_3;
    u8 *temp_4;

    temp_2 = *(u8 **)arg0;
    if (temp_2 != NULL) {
        temp_3 = *(s32 *)(temp_2 + 8) - 1;
        *(s32 *)(temp_2 + 8) = temp_3;
        if (temp_3 == 0) {
            temp_4 = *(u8 **)temp_2;
            if (temp_4 != NULL) {
                jtbl_008873EC[0](temp_4);
            }
            jtbl_008873EC[0](temp_2);
        }
        *(s32 *)arg0 = 0;
    }
}
// FUN_0047EB20
void func_0047eb20(u8 *arg0, s16 arg1, u16 arg2)
{
    u16 status;
    s32 temp_4_2;
    u16 type;

    if ((*(u16 *)(arg0 + 0x10) & 0x10) == 0) {
        return;
    }
    if (*(u8 **)arg0 == NULL) {
        return;
    }
    if ((*(u16 *)(*(u8 **)arg0 + 0x12) & 1) == 0) {
        return;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        type = *(u16 *)(*(u8 **)arg0 + 0xC);
        if (type == 1) {
            status = 2;
        } else {
            status = 3;
        }
        if ((type == 1 &&
             (arg1 != 0xE || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) == 0)) ||
            (*(u16 *)(*(u8 **)arg0 + 0xC) == 2 &&
             (arg1 != 2 || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) == 0))) {
            if (func_0047e0f0(arg0, 0, arg1, arg2) != 0) {
                *(s16 *)(arg0 + 8) = 0;
                *(s16 *)(arg0 + 4) = arg1;
                *(u16 *)(arg0 + 6) = arg2;
                return;
            }
            *(s16 *)(arg0 + 8) = -1;
            return;
        }
        *(s16 *)(arg0 + 8) = -1;
        return;
    }
    if (*(u16 *)(*(u8 **)arg0 + 0x10) == 2 &&
        (arg1 == 4 || arg1 == 5) &&
        func_0045a890(*(s16 *)(*(u8 **)arg0 + 4)) != 0) {
        *(s16 *)(arg0 + 0x1C) = *(s32 *)(*(u8 **)arg0 + 4);
        *(s16 *)(arg0 + 0x24) = arg2;
        *(s16 *)(arg0 + 0x20) = 0;
        *(s16 *)(arg0 + 0x22) = arg1 - 4;
        temp_4_2 = *(s32 *)(*(u8 **)arg0 + 4);
        switch (temp_4_2) {
        case 3:
            *(s16 *)(arg0 + 0x1E) = 1;
            break;
        case 4:
            *(s16 *)(arg0 + 0x1E) = 2;
            break;
        case 5:
            *(s16 *)(arg0 + 0x1E) = 3;
            break;
        }
        *(s16 *)(arg0 + 4) = arg1;
    }
}
static inline void code1_0047_abd0(s16 arg0, s32 arg1, s16 arg2)
{
    func_0045abd0(arg0, arg1, arg2);
}

/* measured: the retry counter is stored as an s32 sum and re-read through the s16 slot
   (`n = x + 1; x = n; temp = x;`): the reload forwards to a dsll32/dsra32 after the sh,
   as retail. The call argument re-reads the slot as `*(s16 *)((u32)arg0 + 8)` so it is
   not CSE'd with the forwarded value and stays a real lh (retail). */
// FUN_0047ED60
void func_0047ed60(u8 *arg0)
{
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_4;
    s16 temp_4_2;
    s32 var_16;
    u8 *temp_3;
    s16 call_a0;
    s16 call_a2;
    s32 call_a1;
    s32 n;

    func_0047e6f0(arg0);
    temp_3 = *(u8 **)arg0;
    if (temp_3 != NULL && (*(u16 *)(temp_3 + 0x12) & 1) != 0) {
        var_16 = 1;
        temp_3_2 = *(s16 *)(arg0 + 0x16);
        if (temp_3_2 >= 0) {
            if (temp_3_2 == 0) {
                temp_3_3 = ((*(u16 *)(arg0 + 0x10) & 0x20) != 0);
                if (temp_3_3 != 0) {
                    call_a0 = *(s16 *)(arg0 + 0x12);
                    call_a2 = *(s16 *)(arg0 + 0x14);
                    call_a1 = *(s32 *)(arg0 + 0x18);
                    code1_0047_abd0((s16)call_a0, (s32)call_a1, (s16)call_a2);
                }
                *(s16 *)(arg0 + 0x16) = -1;
            } else {
                *(s16 *)(arg0 + 0x16) = temp_3_2 - 1;
                var_16 = 0;
            }
        }
        temp_4 = *(s16 *)(arg0 + 0x24);
        if (temp_4 >= 0) {
            if (temp_4 == 0) {
                call_a0 = *(s16 *)(arg0 + 0x1E);
                call_a2 = *(s16 *)(arg0 + 0x20);
                temp_3_3 = *(s16 *)(arg0 + 0x22);
                func_0045af60(*(s16 *)(arg0 + 0x1C), call_a0, call_a2,
                              temp_3_3);
                *(s16 *)(arg0 + 0x26) = *(s16 *)(arg0 + 0x1C);
                *(s16 *)(arg0 + 0x24) = -1;
            } else {
                *(s16 *)(arg0 + 0x24) = temp_4 - 1;
                var_16 = 0;
            }
        } else if (temp_4 == -2) {
            temp_4_2 = *(s16 *)(arg0 + 0x26);
            if (temp_4_2 >= 0) {
                func_0045aa90(temp_4_2, *(s16 *)(arg0 + 0x1E));
                *(s16 *)(arg0 + 0x26) = -1;
            }
            *(s16 *)(arg0 + 0x24) = -1;
        }
        if (*(s32 *)(arg0 + 0xC) != 0 && var_16 == 1 &&
            *(s16 *)(arg0 + 8) != -1) {
            n = *(s16 *)(arg0 + 8) + 1;
            *(s16 *)(arg0 + 8) = n;
            temp_3_4 = *(s16 *)(arg0 + 8);
            if (temp_3_4 < 8) {
                call_a1 = *(u16 *)(arg0 + 0x06);
                if (func_0047e0f0(arg0, *(s16 *)((u32)arg0 + 8),
                                  *(s16 *)(arg0 + 0x04), (u16)call_a1) == 0) {
                    *(s16 *)(arg0 + 8) = -1;
                }
            } else {
                *(s16 *)(arg0 + 8) = -1;
            }
        }
    }
}
// FUN_0047EF10
static s32 func_0047ef10(u8 *arg0, f32 fparg0)
{
    s32 temp_2;
    s32 var_7;
    s32 var_6;
    s32 stride;
    u8 *base;

    var_6 = 0;
    var_7 = *(s32 *)arg0 - 1;
    stride = *(s32 *)(arg0 + 8);
    base = *(u8 **)(arg0 + 0xC);
    do {
        temp_2 = (var_6 + var_7 + 1) >> 1;
        if (fparg0 < *(f32 *)(base + (stride * temp_2))) {
            temp_2 = temp_2 - 1;
            var_7 = temp_2;
        } else {
            var_6 = temp_2;
        }
    } while (var_6 < var_7);
    return temp_2;
}
// FUN_0047EF70
u8 *func_0047ef70(u8 *arg0, f32 fparg0)
{
    s32 temp_5;
    s32 temp_6;
    s32 var_4;
    s32 var_8;
    s32 var_7;
    s32 stride;

    temp_6 = (s32)*(u8 **)(arg0 + 0xC);
    var_7 = 0;
    temp_5 = *(s32 *)arg0 - 1;
    var_8 = temp_5;
    stride = *(s32 *)(arg0 + 8);
    do {
        var_4 = (var_7 + var_8 + 1) >> 1;
        if (fparg0 < *(f32 *)(temp_6 + (stride * var_4))) {
            var_4 = var_4 - 1;
            var_8 = var_4;
        } else {
            var_7 = var_4;
        }
    } while (var_7 < var_8);
    if ((u32)var_4 >= (u32)temp_5) {
        fGpffffbb4c = *(f32 *)(viewAddReverse(temp_6, var_4 * 8) + 4);
    } else {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        x0 = *(f32 *)(temp_6 + (var_4 * 8));
        y0 = *(f32 *)(temp_6 + (var_4 * 8) + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(temp_6 + (var_4 * 8) + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(temp_6 + (var_4 * 8) + 0xC);
        fGpffffbb4c = y0 + code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    return (u8 *)&fGpffffbb48;
}
/* measured: duplicating the scalar sampler around the static exact
 * func_0047ef10 preserves both track pointers, times, and the blend factor.
 * Assigning each GP result pair to a two-float aggregate forces retail's
 * 0x20 frame and exact stack snapshots across the second call; the staged
 * inline madd helper closes the final blend. Object 340B/window 352B,
 * normalized_diff 0 with three retail zero-tail words. */
// FUN_0047F040
f32 *func_0047f040(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    s32 index;
    u8 *base;
    typedef struct Code47Pair {
        f32 time;
        f32 value;
    } Code47Pair;
    Code47Pair first;
    Code47Pair second;
    f32 difference;

    base = *(u8 **)(arg0 + 0xC);
    index = func_0047ef10(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    first = *(Code47Pair *)&fGpffffbb48;

    base = *(u8 **)(arg1 + 0xC);
    index = func_0047ef10(arg1, fparg1);
    if ((u32)index >= (u32)(*(s32 *)arg1 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg1 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg1;
    second = *(Code47Pair *)&fGpffffbb48;

    difference = second.value - first.value;
    fGpffffbb54 = code1_0047_madd(difference, fparg2, first.value);
    return &fGpffffbb50;
}
/* measured: keeping the exact func_0047ef10 helper static exposes its narrow
 * clobber set, preserving the caller's $t2/$t1/$f13 values. Caching the track
 * base before the call, scaling `index` in place in each branch, and carrying
 * the GP output address as an integer reproduce retail's register lifetimes.
 * Splitting the final difference/addend before the inline madd helper preserves
 * both evaluation order and FMA operand order. The object is 276B in a 288B
 * retail window with only three retail zero-tail words. */
// FUN_0047F1A0
f32 *func_0047f1a0(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    s32 index;
    u8 *base;
    s32 out;
    f32 difference;
    f32 addend;

    base = *(u8 **)(arg0 + 0xC);
    index = func_0047ef10(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    out = (s32)&fGpffffbb48;
    difference = (1.0f -
        ((f32)(u32)*(u8 *)(arg1 + 3)) / 255.0f);
    addend = *(f32 *)(out + 4);
    difference -= addend;
    *(f32 *)(out + 4) = code1_0047_madd(
        difference, fparg1, addend);
    return (f32 *)out;
}
/* measured: func_0047f3a0 remains 300B in a 304B retail window with
 * only one retail zero-tail word. Keeping the exact helper static in this
 * code1 TU exposes its real register clobbers to MWCC, so func_0047f4d0
 * retains $t1/$f13/$f14 across both calls. The pointer-first source signature
 * preserves the independent integer/float ABI while ordering the second
 * call's $a0 setup before $f12; func_0047f4d0 is 216B in a 224B window with
 * only two retail zero-tail words. */
// FUN_0047F3A0
static u32 *func_0047f3a0(int *param_2, float param_1)
{
  float *key;
  float fraction;
  float start;
  float output;
  float difference;
  int high;
  int low;
  int stride;
  u8 *data;
  int mid;
  u32 address;

  data = (u8 *)param_2[3];
  low = 0;
  high = *param_2 - 1;
  stride = param_2[2];
  do {
    mid = (low + high + 1) >> 1;
    if (param_1 < *(float *)(data + stride * mid)) {
      high = --mid;
    }
    else {
      low = mid;
    }
  } while (low < high);
  if ((u32)mid >= (u32)(*param_2 - 1)) {
    address = mid * 0x10;
    address += (u32)data;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(address + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(address + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(address + 0xc);
  }
  else {
    key = (float *)((u32)(mid * 0x10) + (u32)data);
    start = key[0];
    fraction = param_1 - start;
    fraction /= key[4] - start;
    output = key[1];
    difference = key[5] - output;
    *(float *)(DAT_00922c30_abs + 4) = fraction * difference + output;
    output = key[2];
    difference = key[6] - output;
    *(float *)(DAT_00922c30_abs + 8) = fraction * difference + output;
    output = key[3];
    difference = key[7] - output;
    *(float *)(DAT_00922c30_abs + 12) = fraction * difference + output;
  }
  *(float *)DAT_00922c30_abs = param_1;
  return (u32 *)DAT_00922c30_abs;
}
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
// FUN_0047F4D0
Code47Vec4 *func_0047f4d0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2)
{
    Code47Vec4 first;
    Code47Vec4 second;

    first = *(Code47Vec4 *)func_0047f3a0((int *)arg0, fparg0);
    second = *(Code47Vec4 *)func_0047f3a0((int *)arg1, fparg1);
    D_00922C40.y = 0.0f + first.y + fparg2 * (second.y - first.y);
    D_00922C40.z = 0.0f + first.z + fparg2 * (second.z - first.z);
    D_00922C40.w = 0.0f + first.w + fparg2 * (second.w - first.w);
    return &D_00922C40;
}
/* measured: the static exact func_0047f3a0 body preserves $t1/$f13 across
 * the call. Computing bytes 1 and 2 before byte 0 assigns retail's $f4/$f3
 * roles; staging each addend after its normalized value prevents load
 * hoisting, and the reverse-order inline madd helper reproduces all three
 * accumulator operand orders. Object 348B/window 352B, normalized_diff 0;
 * the final retail word is zero tail padding. */
// FUN_0047F5B0
void func_0047f5b0(s32 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    f32 *out;
    f32 second;
    f32 third;
    f32 first;
    f32 addend;
    f32 difference;

    out = (f32 *)func_0047f3a0((int *)arg0, fparg0);
    second = (f32)(u32)arg1[1] / 255.0f;
    third = (f32)(u32)arg1[2] / 255.0f;
    first = (f32)(u32)arg1[0] / 255.0f;

    difference = first;
    addend = out[1];
    difference -= addend;
    out[1] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = second;
    addend = out[2];
    difference -= addend;
    out[2] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = third;
    addend = out[3];
    difference -= addend;
    out[3] = code1_0047_madd_reverse(difference, fparg1, addend);
}
// FUN_0047F710
void func_0047f710(u8 *arg0, u8 *arg1)
{
    u8 *dst;

    dst = arg1 + 4;
    dst[0] = (u8)(255.0f * ((f32 *)arg0)[1]);
    dst[1] = (u8)(255.0f * ((f32 *)arg0)[2]);
    dst[2] = (u8)(255.0f * ((f32 *)arg0)[3]);
}
// FUN_0047F830
u8 *func_0047f830(void)
{
    return D_00922C50;
}
/* measured: clean reconstruction reaches object 412B/window 416B,
 * normalized_diff 13. Every structural instruction matches; only the
 * target-list/count/dispatch saved-register cycle differs. See
 * docs/probe_archive/W52Main_0047f850_body.c. */
// FUN_0047F850 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0047", func_0047f850);
